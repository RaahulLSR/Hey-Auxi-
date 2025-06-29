/*
 * Copyright 2019-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "lvgl_support.h"
#include "lvgl.h"
#if defined(SDK_OS_FREE_RTOS)
#include "FreeRTOS.h"
#include "semphr.h"
#endif
#include "board.h"

#include "fsl_gpio.h"
#include "fsl_cache.h"
#include "fsl_debug_console.h"

#include "fsl_gt911.h"

#if LV_USE_GPU_NXP_PXP
#include "src/gpu/lv_gpu_nxp_pxp.h"
#include "src/gpu/lv_gpu_nxp_pxp_osa.h"
#endif

#if LV_USE_GPU_NXP_VG_LITE
#include "vg_lite.h"
#include "vg_lite_platform.h"
#include "draw/nxp/vglite/lv_draw_vglite_blend.h"
#endif

#if ((LV_HOR_RES_MAX == DEMO_PANEL_HEIGHT) && (LV_VER_RES_MAX == DEMO_PANEL_WIDTH))
#include "fwk_graphics.h"
#include "hal_graphics_dev.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define KEYBOARD_OVERLAY 1

/* Cache line size. */
#ifndef FSL_FEATURE_L2CACHE_LINESIZE_BYTE
#define FSL_FEATURE_L2CACHE_LINESIZE_BYTE 0
#endif
#ifndef FSL_FEATURE_L1DCACHE_LINESIZE_BYTE
#define FSL_FEATURE_L1DCACHE_LINESIZE_BYTE 0
#endif

#if (FSL_FEATURE_L2CACHE_LINESIZE_BYTE > FSL_FEATURE_L1DCACHE_LINESIZE_BYTE)
#define DEMO_CACHE_LINE_SIZE FSL_FEATURE_L2CACHE_LINESIZE_BYTE
#else
#define DEMO_CACHE_LINE_SIZE FSL_FEATURE_L1DCACHE_LINESIZE_BYTE
#endif

#if (DEMO_CACHE_LINE_SIZE > FRAME_BUFFER_ALIGN)
#define DEMO_FB_ALIGN DEMO_CACHE_LINE_SIZE
#else
#define DEMO_FB_ALIGN FRAME_BUFFER_ALIGN
#endif

#if (LV_ATTRIBUTE_MEM_ALIGN_SIZE > DEMO_FB_ALIGN)
#undef DEMO_FB_ALIGN
#define DEMO_FB_ALIGN LV_ATTRIBUTE_MEM_ALIGN_SIZE
#endif

#define DEMO_FB_SIZE \
    (((DEMO_BUFFER_WIDTH * DEMO_BUFFER_HEIGHT * LCD_FB_BYTE_PER_PIXEL) + DEMO_FB_ALIGN - 1) & ~(DEMO_FB_ALIGN - 1))

#if LV_USE_GPU_NXP_VG_LITE
#define VG_LITE_MAX_CONTIGUOUS_SIZE 0x200000
#define VG_LITE_COMMAND_BUFFER_SIZE (256 << 10)
#endif

#if KEYBOARD_OVERLAY
#define KEYBOARD_WIDTH  (DEMO_BUFFER_WIDTH / 2)
#define KEYBOARD_HEIGHT DEMO_BUFFER_HEIGHT
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);
static void DEMO_WaitFlush(lv_disp_drv_t *disp_drv);

#if (LV_USE_GPU_NXP_VG_LITE || LV_USE_GPU_NXP_PXP)
static void DEMO_CleanInvalidateCache(lv_disp_drv_t *disp_drv);
#endif

static void DEMO_InitTouch(void);

static void DEMO_ReadTouch(lv_indev_drv_t *drv, lv_indev_data_t *data);

static void DEMO_BufferSwitchOffCallback(void *param, void *switchOffBuffer);

static void BOARD_PullMIPIPanelTouchResetPin(bool pullUp);

static void BOARD_ConfigMIPIPanelTouchIntPin(gt911_int_pin_mode_t mode);

#ifdef ENABLE_DISPLAY_DEV_LVGLHomePanel
static void DEMO_CameraBufferSwitchOffCallback(void *param, void *switchOffBuffer);
#endif

#if LV_USE_GPU_NXP_VG_LITE
static status_t BOARD_PrepareVGLiteController(void);

static status_t BOARD_InitVGliteClock(void);
#endif /* LV_USE_GPU_NXP_VG_LITE */

/*******************************************************************************
 * Variables
 ******************************************************************************/

SDK_ALIGN(static uint8_t s_frameBuffer[DEMO_FB_SIZE], DEMO_FB_ALIGN);
#if ((LV_HOR_RES_MAX == DEMO_PANEL_HEIGHT) && (LV_VER_RES_MAX == DEMO_PANEL_WIDTH))
SDK_ALIGN(static uint8_t s_frameBuffer_rotate[DEMO_FB_SIZE], DEMO_FB_ALIGN);
#endif

#if defined(SDK_OS_FREE_RTOS)
static SemaphoreHandle_t s_transferDone;
#else
static volatile bool s_transferDone;
#endif

static gt911_handle_t s_touchHandle;
static const gt911_config_t s_touchConfig = {
    .I2C_SendFunc     = BOARD_MIPIPanelTouch_I2C_Send,
    .I2C_ReceiveFunc  = BOARD_MIPIPanelTouch_I2C_Receive,
    .pullResetPinFunc = BOARD_PullMIPIPanelTouchResetPin,
    .intPinFunc       = BOARD_ConfigMIPIPanelTouchIntPin,
    .timeDelayMsFunc  = VIDEO_DelayMs,
    .touchPointNum    = 1,
    .i2cAddrMode      = kGT911_I2cAddrMode0,
    .intTrigMode      = kGT911_IntRisingEdge,
};
static int s_touchResolutionX;
static int s_touchResolutionY;

#if LV_USE_GPU_NXP_VG_LITE
static uint32_t registerMemBase = 0x41800000;
static uint32_t gpu_mem_base    = 0x0;

/*
 * In case custom VGLite memory parameters are used, the application needs to
 * allocate and publish the VGLite heap base, its size and the size of the
 * command buffer(s) using the following global variables:
 */
extern void *vglite_heap_base;
extern uint32_t vglite_heap_size;
extern uint32_t vglite_cmd_buff_size;

#if (CUSTOM_VGLITE_MEMORY_CONFIG == 0)
/* VGLite driver heap */
AT_NONCACHEABLE_SECTION_ALIGN(static uint8_t vglite_contiguous_mem[VG_LITE_MAX_CONTIGUOUS_SIZE], 64);

void *vglite_heap_base        = &vglite_contiguous_mem;
uint32_t vglite_heap_size     = VG_LITE_MAX_CONTIGUOUS_SIZE;
uint32_t vglite_cmd_buff_size = VG_LITE_COMMAND_BUFFER_SIZE;
#endif /* CUSTOM_VGLITE_MEMORY_CONFIG */

#endif /* LV_USE_GPU_NXP_VG_LITE */

/*******************************************************************************
 * Code
 ******************************************************************************/

void lv_port_pre_init(void)
{
}

void lv_port_disp_init(void)
{
    static lv_disp_draw_buf_t disp_buf;
    static lv_disp_drv_t disp_drv; /*Descriptor of a display driver*/

    lv_disp_draw_buf_init(&disp_buf, s_frameBuffer, s_frameBuffer, LCD_WIDTH * LCD_HEIGHT);

    status_t status;
    dc_fb_info_t fbInfo;

#if LV_USE_GPU_NXP_VG_LITE
    /* Initialize GPU. */
    BOARD_PrepareVGLiteController();
#endif

    /*-------------------------
     * Initialize your display
     * -----------------------*/
    BOARD_PrepareDisplayController();

    status = g_dc.ops->init(&g_dc);
    if (kStatus_Success != status)
    {
        assert(0);
    }

    // layer 0 for lvgl main screen
    g_dc.ops->getLayerDefaultConfig(&g_dc, 0, &fbInfo);
    fbInfo.pixelFormat = DEMO_BUFFER_PIXEL_FORMAT;
    fbInfo.width       = DEMO_BUFFER_WIDTH;
    fbInfo.height      = DEMO_BUFFER_HEIGHT;
    fbInfo.startX      = DEMO_BUFFER_START_X;
    fbInfo.startY      = DEMO_BUFFER_START_Y;
    fbInfo.strideBytes = DEMO_BUFFER_STRIDE_BYTE;
    g_dc.ops->setLayerConfig(&g_dc, 0, &fbInfo);

    g_dc.ops->setCallback(&g_dc, 0, DEMO_BufferSwitchOffCallback, &disp_drv);

#ifdef ENABLE_DISPLAY_DEV_LVGLHomePanel
    // layer 1 for camera preview
    g_dc.ops->getLayerDefaultConfig(&g_dc, 1, &fbInfo);
    fbInfo.pixelFormat = DEMO_BUFFER_PIXEL_FORMAT;
    fbInfo.width       = DISPLAY_DEV_LVGLHomePanel_WIDTH;
    fbInfo.height      = DISPLAY_DEV_LVGLHomePanel_HEIGHT;
    fbInfo.startX      = DISPLAY_DEV_LVGLHomePanel_StartX;
    fbInfo.startY      = DEMO_BUFFER_HEIGHT - DISPLAY_DEV_LVGLHomePanel_HEIGHT - DISPLAY_DEV_LVGLHomePanel_StartY;
    fbInfo.strideBytes = DISPLAY_DEV_LVGLHomePanel_WIDTH * DISPLAY_DEV_LVGLHomePanel_BPP;
    g_dc.ops->setLayerConfig(&g_dc, 1, &fbInfo);

    g_dc.ops->setCallback(&g_dc, 1, DEMO_CameraBufferSwitchOffCallback, NULL);
#endif

#if KEYBOARD_OVERLAY
    // layer 3 for keyboard
    g_dc.ops->getLayerDefaultConfig(&g_dc, 2, &fbInfo);
    fbInfo.pixelFormat = DEMO_BUFFER_PIXEL_FORMAT;
    fbInfo.width       = KEYBOARD_WIDTH;
    fbInfo.height      = DEMO_BUFFER_HEIGHT;
    fbInfo.startX      = DEMO_BUFFER_WIDTH - KEYBOARD_WIDTH;
    fbInfo.startY      = 0;
    fbInfo.strideBytes = DEMO_BUFFER_WIDTH * DISPLAY_DEV_LVGLHomePanel_BPP;
    g_dc.ops->setLayerConfig(&g_dc, 2, &fbInfo);
    g_dc.ops->setCallback(&g_dc, 2, DEMO_CameraBufferSwitchOffCallback, NULL);
    g_dc.ops->setFrameBuffer(
        &g_dc, 2, (void *)&s_frameBuffer_rotate[(DEMO_BUFFER_WIDTH - KEYBOARD_WIDTH) * DEMO_BUFFER_BYTE_PER_PIXEL]);
#endif

#if defined(SDK_OS_FREE_RTOS)
    s_transferDone = xSemaphoreCreateBinary();
    if (NULL == s_transferDone)
    {
        PRINTF("Frame semaphore create failed\r\n");
        assert(0);
    }
#else
    s_transferDone = false;
#endif

    /* lvgl starts render in frame buffer 0, so show frame buffer 1 first. */
    g_dc.ops->setFrameBuffer(&g_dc, 0, (void *)s_frameBuffer_rotate);

    /* Wait for frame buffer sent to display controller video memory. */
    if ((g_dc.ops->getProperty(&g_dc) & kDC_FB_ReserveFrameBuffer) == 0)
    {
#if defined(SDK_OS_FREE_RTOS)
        if (xSemaphoreTake(s_transferDone, portMAX_DELAY) != pdTRUE)
        {
            PRINTF("Wait semaphore error: s_transferDone\r\n");
            assert(0);
        }
#else
        while (false == s_transferDone)
        {
        }
#endif
    }

    g_dc.ops->enableLayer(&g_dc, 0);

    /*-----------------------------------
     * Register the display in LittlevGL
     *----------------------------------*/

    lv_disp_drv_init(&disp_drv); /*Basic initialization*/

    /*Set up the functions to access to your display*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = LCD_WIDTH;
    disp_drv.ver_res = LCD_HEIGHT;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = DEMO_FlushDisplay;

    disp_drv.wait_cb = DEMO_WaitFlush;

#if (LV_USE_GPU_NXP_VG_LITE || LV_USE_GPU_NXP_PXP)
    disp_drv.clean_dcache_cb = DEMO_CleanInvalidateCache;
#endif

    /*Set a display buffer*/
    disp_drv.draw_buf = &disp_buf;

    /* Partial refresh */
  //  disp_drv.full_refresh = 1;
    disp_drv.full_refresh = 0;
    disp_drv.direct_mode  = 1;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);

#if LV_USE_GPU_NXP_VG_LITE
    if (vg_lite_init(64, 64) != VG_LITE_SUCCESS)
    {
        PRINTF("VGLite init error. STOP.");
        vg_lite_close();
        assert(0);
    }
#endif
}

static void DEMO_BufferSwitchOffCallback(void *param, void *switchOffBuffer)
{
    lv_disp_drv_t *disp_drv = (lv_disp_drv_t *)param;

    /* IMPORTANT!!!
     * Inform the graphics library that you are ready with the flushing*/
    lv_disp_flush_ready(disp_drv);

#if defined(SDK_OS_FREE_RTOS)
    BaseType_t taskAwake = pdFALSE;

    xSemaphoreGiveFromISR(s_transferDone, &taskAwake);
    portYIELD_FROM_ISR(taskAwake);
#else
    s_transferDone = true;
#endif
}

#ifdef ENABLE_DISPLAY_DEV_LVGLHomePanel
static void DEMO_CameraBufferSwitchOffCallback(void *param, void *switchOffBuffer)
{
#if defined(SDK_OS_FREE_RTOS)
    BaseType_t taskAwake = pdFALSE;

    xSemaphoreGiveFromISR(s_transferDone, &taskAwake);
    portYIELD_FROM_ISR(taskAwake);
#else
    s_transferDone = true;
#endif
}

void lv_enable_keyboard_layout(bool enable)
{
    dc_fb_info_t fbInfo;
    g_dc.ops->getLayerDefaultConfig(&g_dc, 0, &fbInfo);
    uint16_t width = 0;
    if (enable)
    {
        width = DEMO_BUFFER_WIDTH - KEYBOARD_WIDTH;
        g_dc.ops->enableLayer(&g_dc, 2);
    }
    else
    {
        width = DEMO_BUFFER_WIDTH;
        g_dc.ops->disableLayer(&g_dc, 2);
    }

    fbInfo.pixelFormat = DEMO_BUFFER_PIXEL_FORMAT;
    fbInfo.width       = width;
    fbInfo.height      = DEMO_BUFFER_HEIGHT;
    fbInfo.startX      = DEMO_BUFFER_START_X;
    fbInfo.startY      = DEMO_BUFFER_START_Y;
    fbInfo.strideBytes = DEMO_BUFFER_STRIDE_BYTE;
    g_dc.ops->setLayerConfig(&g_dc, 0, &fbInfo);
}

void lv_enable_camera_preview(void *frameBuffer, bool enable)
{
    if (enable)
    {
        g_dc.ops->enableLayer(&g_dc, 1);
        g_dc.ops->setFrameBuffer(&g_dc, 1, (void *)frameBuffer);
    }
    else
    {
        g_dc.ops->disableLayer(&g_dc, 1);
    }
}

static int s_UIOff = 0;
void lv_enable_ui_preview(bool enable)
{
    if (enable)
    {
        g_dc.ops->enableLayer(&g_dc, 0);
        s_UIOff = 0;
    }
    else
    {
        g_dc.ops->disableLayer(&g_dc, 0);
        s_UIOff = 1;
    }
}
#endif

#if (LV_USE_GPU_NXP_VG_LITE || LV_USE_GPU_NXP_PXP)
static void DEMO_CleanInvalidateCache(lv_disp_drv_t *disp_drv)
{
#if __CORTEX_M == 4
    L1CACHE_CleanInvalidateSystemCache();
#else
    SCB_CleanInvalidateDCache();
#endif
}
#endif

static void DEMO_WaitFlush(lv_disp_drv_t *disp_drv)
{
#if defined(SDK_OS_FREE_RTOS)
    if (xSemaphoreTake(s_transferDone, portMAX_DELAY) != pdTRUE)
    {
        PRINTF("Display flush failed\r\n");
        assert(0);
    }
#else
    while (false == s_transferDone)
    {
    }
#endif
}

#if ((LV_HOR_RES_MAX == DEMO_PANEL_HEIGHT) && (LV_VER_RES_MAX == DEMO_PANEL_WIDTH))
void _rotate_270(void *pSrcData, void *pDstData)
{
#if PXP_LVGL_ROTATE
    gfx_surface_t srcSurface;
    gfx_surface_t dstSurface;
    gfx_rotate_config_t rotateMode;
    flip_mode_t flipMode;
    gfx_rotate_config_t *pRotate = NULL;

    /* source surface */
    srcSurface.pitch    = DEMO_PANEL_HEIGHT * 2;
    srcSurface.format   = kPixelFormat_RGB565;
    srcSurface.swapByte = 0;
    srcSurface.lock     = NULL;

    srcSurface.height = DEMO_PANEL_HEIGHT;
    srcSurface.width  = DEMO_PANEL_WIDTH;
    srcSurface.left   = 0;
    srcSurface.top    = 0;
    srcSurface.right  = DEMO_PANEL_WIDTH - 1;
    srcSurface.bottom = DEMO_PANEL_HEIGHT - 1;

    rotateMode.target = kGFXRotate_SRCSurface;
    rotateMode.degree = kCWRotateDegree_270;
    pRotate           = &rotateMode;

    /* flip */
    flipMode       = kFlipMode_None;
    srcSurface.buf = pSrcData;

    /* dst surface */
    dstSurface.height = DEMO_PANEL_HEIGHT;
    dstSurface.width  = DEMO_PANEL_WIDTH;
    dstSurface.left   = 0;
    dstSurface.top    = 0;
    dstSurface.right  = DEMO_PANEL_WIDTH - 1;
    dstSurface.bottom = DEMO_PANEL_HEIGHT - 1;

    dstSurface.pitch  = DEMO_PANEL_WIDTH * 2;
    dstSurface.format = kPixelFormat_RGB565;
    dstSurface.buf    = pDstData;
    dstSurface.lock   = NULL;

    gfx_blit(&srcSurface, &dstSurface, pRotate, flipMode);

#else
    lv_gpu_nxp_vglite_blit_info_t blit;

    blit.src = pSrcData;

    blit.src_width = LCD_WIDTH;
    blit.src_height = LCD_HEIGHT;
    blit.src_stride = LCD_WIDTH * (int32_t)sizeof(lv_color_t);
    blit.src_area.x1 = 0;
    blit.src_area.y1 = 0;
    blit.src_area.x2 = LCD_WIDTH - 1;
    blit.src_area.y2 = LCD_HEIGHT - 1;

    blit.dst = pDstData;
    blit.dst_width = DEMO_BUFFER_WIDTH;
    blit.dst_height = DEMO_BUFFER_HEIGHT;
    blit.dst_stride = DEMO_BUFFER_STRIDE_BYTE;
    blit.dst_area.x1 = DEMO_BUFFER_START_X;
    blit.dst_area.y1 = DEMO_BUFFER_START_Y;
    blit.dst_area.x2 = DEMO_BUFFER_WIDTH - 1;
    blit.dst_area.y2 = DEMO_BUFFER_HEIGHT - 1;

    blit.pivot.x = 638; // rotate point x
    blit.pivot.y = DEMO_BUFFER_HEIGHT / 2;

    blit.opa = LV_OPA_MAX;
    blit.zoom = LV_IMG_ZOOM_NONE;
    blit.angle = 2700;

    lv_gpu_nxp_vglite_blit(&blit);
#endif
}
#endif

static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    uint8_t *pData;

    if (!lv_disp_flush_is_last(disp_drv))
    {
        lv_disp_flush_ready(disp_drv);
        return;
    }

    /*
     * Before new frame flushing, clear previous frame flush done status.
     */
#if !defined(SDK_OS_FREE_RTOS)
    s_transferDone = false;
#else
    (void)xSemaphoreTake(s_transferDone, 0);
#endif

    DCACHE_CleanInvalidateByRange((uint32_t)color_p, DEMO_FB_SIZE);

#if ((LV_HOR_RES_MAX == DEMO_PANEL_HEIGHT) && (LV_VER_RES_MAX == DEMO_PANEL_WIDTH))
    _rotate_270((void *)color_p, (void *)s_frameBuffer_rotate);
    pData = s_frameBuffer_rotate;
#else
    pData = (uint8_t *)color_p;
#endif

    if (s_UIOff)
    {
        lv_enable_ui_preview(1);
        BOARD_BacklightControl(1);
    }
    g_dc.ops->setFrameBuffer(&g_dc, 0, (void *)pData);
}

void lv_port_indev_init(void)
{
    static lv_indev_drv_t indev_drv;

    /*------------------
     * Touchpad
     * -----------------*/

    /*Initialize your touchpad */
    DEMO_InitTouch();

    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type    = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = DEMO_ReadTouch;
    lv_indev_drv_register(&indev_drv);
}

static void BOARD_PullMIPIPanelTouchResetPin(bool pullUp)
{
    if (pullUp)
    {
        GPIO_PinWrite(BOARD_MIPI_PANEL_TOUCH_RST_GPIO, BOARD_MIPI_PANEL_TOUCH_RST_PIN, 1);
    }
    else
    {
        GPIO_PinWrite(BOARD_MIPI_PANEL_TOUCH_RST_GPIO, BOARD_MIPI_PANEL_TOUCH_RST_PIN, 0);
    }
}

static void BOARD_ConfigMIPIPanelTouchIntPin(gt911_int_pin_mode_t mode)
{
    if (mode == kGT911_IntPinInput)
    {
        BOARD_MIPI_PANEL_TOUCH_INT_GPIO->GDIR &= ~(1UL << BOARD_MIPI_PANEL_TOUCH_INT_PIN);
    }
    else
    {
        if (mode == kGT911_IntPinPullDown)
        {
            GPIO_PinWrite(BOARD_MIPI_PANEL_TOUCH_INT_GPIO, BOARD_MIPI_PANEL_TOUCH_INT_PIN, 0);
        }
        else
        {
            GPIO_PinWrite(BOARD_MIPI_PANEL_TOUCH_INT_GPIO, BOARD_MIPI_PANEL_TOUCH_INT_PIN, 1);
        }

        BOARD_MIPI_PANEL_TOUCH_INT_GPIO->GDIR |= (1UL << BOARD_MIPI_PANEL_TOUCH_INT_PIN);
    }
}

/*Initialize your touchpad*/
static void DEMO_InitTouch(void)
{
    status_t status;

    const gpio_pin_config_t resetPinConfig = {
        .direction = kGPIO_DigitalOutput, .outputLogic = 0, .interruptMode = kGPIO_NoIntmode};
    GPIO_PinInit(BOARD_MIPI_PANEL_TOUCH_INT_GPIO, BOARD_MIPI_PANEL_TOUCH_INT_PIN, &resetPinConfig);
    GPIO_PinInit(BOARD_MIPI_PANEL_TOUCH_RST_GPIO, BOARD_MIPI_PANEL_TOUCH_RST_PIN, &resetPinConfig);

    status = GT911_Init(&s_touchHandle, &s_touchConfig);

    if (kStatus_Success != status)
    {
        PRINTF("Touch IC initialization failed\r\n");
        assert(false);
    }

    GT911_GetResolution(&s_touchHandle, &s_touchResolutionX, &s_touchResolutionY);
}

/* Will be called by the library to read the touchpad */
static void DEMO_ReadTouch(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    static int touch_x = 0;
    static int touch_y = 0;

    if (kStatus_Success == GT911_GetSingleTouch(&s_touchHandle, &touch_x, &touch_y))
    {
        data->state = LV_INDEV_STATE_PR;
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Set the last pressed coordinates*/
#if ((LV_HOR_RES_MAX == DEMO_PANEL_HEIGHT) && (LV_VER_RES_MAX == DEMO_PANEL_WIDTH))
    // rotate 270
    data->point.x = (DEMO_PANEL_HEIGHT - touch_y) * DEMO_PANEL_HEIGHT / s_touchResolutionY;
    data->point.y = touch_x * DEMO_PANEL_WIDTH / s_touchResolutionX;
#else
    data->point.x = touch_x * DEMO_PANEL_WIDTH / s_touchResolutionX;
    data->point.y = touch_y * DEMO_PANEL_HEIGHT / s_touchResolutionY;
#endif
}

#if LV_USE_GPU_NXP_VG_LITE
void GPU2D_IRQHandler(void)
{
    vg_lite_IRQHandler();
}

static status_t BOARD_InitVGliteClock(void)
{
    const clock_root_config_t gc355ClockConfig = {
        .clockOff = false,
        .mux      = kCLOCK_GC355_ClockRoot_MuxVideoPllOut,
        .div      = 2,
    };

    CLOCK_SetRootClock(kCLOCK_Root_Gc355, &gc355ClockConfig);

    CLOCK_GetRootClockFreq(kCLOCK_Root_Gc355);

    CLOCK_EnableClock(kCLOCK_Gpu2d);

    NVIC_SetPriority(GPU2D_IRQn, 3);

    EnableIRQ(GPU2D_IRQn);

    return kStatus_Success;
}

static status_t BOARD_PrepareVGLiteController(void)
{
    status_t status;

    status = BOARD_InitVGliteClock();

    if (kStatus_Success != status)
    {
        return status;
    }

    vg_lite_init_mem(registerMemBase, gpu_mem_base, vglite_heap_base, vglite_heap_size);

    vg_lite_set_command_buffer_size(vglite_cmd_buff_size);

    return kStatus_Success;
}
#endif /* LV_USE_GPU_NXP_VG_LITE */

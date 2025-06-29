/*
 * Copyright 2020-2021 NXP.
 * This software is owned or controlled by NXP and may only be used strictly in accordance with the
 * license terms that accompany it. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms. If you do not agree to be bound by the
 * applicable license terms, then you may not retain, install, activate or otherwise use the software.
 */

/*
 * @brief Vision algorithm HAL driver declaration.
 */

#ifndef _HAL_VISION_ALGO_H_
#define _HAL_VISION_ALGO_H_

#include "board_define.h"

#include "hal_event_descriptor_common.h"

#include "hal_sln_facedb.h"

/*
 * OASIS lite device
 */
#ifdef SMART_LOCK_3D
#include "oasislite3D_runtime.h"
#elif defined(SMART_LOCK_2D) || defined(SMART_ACCESS_2D) || defined(SMART_TLHMI_2D)
#include "oasislite2D_runtime.h"
#else
#error "***Invalid demo APP definition! Supported definition [SMART_LOCK_3D | SMART_LOCK_2D | SMART_ACCESS_2D]***"
#endif

#ifdef SMART_TLHMI_HOMEPANEL
#include "uvita_gesture.h"
#endif /* SMART_TLHMI_HOMEPANEL */

#define OASIS_RUN_FLAG_STOP (OASIS_RUN_FLAG_NUM + 1)

#define OASIS_DETECT_MIN_FACE 100
#ifndef OASIS_STATIC_MEM_BUFFER
#define OASIS_STATIC_MEM_BUFFER 0
#endif

#if OASIS_STATIC_MEM_BUFFER
#define OASIS_STATIC_MEM_POOL 0x100000
#endif

/*dtc buffer for inference engine optimization*/
#define DTC_OPTIMIZE_BUFFER_SIZE (128 * 1024)

#ifndef VISION_SHARED_FRAME_BUFFER
#define VISION_SHARED_FRAME_BUFFER 0
#endif

#define VISION_ALGO_BUFFER_SIZE (0x247000)
/*dtc buffer for inference engine optimization*/
extern uint8_t g_DTCOPBuf[DTC_OPTIMIZE_BUFFER_SIZE];

extern uint8_t g_VisionAlgoBuffer[VISION_ALGO_BUFFER_SIZE];
/*
 * Default face rec threshold value:
 *
 * Oasis will set the threshold with this calculation: (DEFAULT_FACE_REC_THRESHOLD * 1.0f / 1000)
 */
#define MINIMUM_FACE_REC_THRESHOLD 600
#define DEFAULT_FACE_REC_THRESHOLD 800
#define MAXIMUM_FACE_REC_THRESHOLD 900

typedef enum _oasis_lite_mode
{
    kOASISLiteMode_SmartLock,
    kOASISLiteMode_FFI,
    kOASISLiteMode_Count
} oasis_lite_mode_t;

typedef enum _oasis_lite_state
{
    kOASISLiteState_Running = 0,
    kOASISLiteState_Stopped,
    kOASISLiteState_Recognition,
    kOASISLiteState_Registration,
    kOASISLiteState_DeRegistration,
    kOASISLiteState_RemoteRegistration,
    kOASISLiteState_Count
} oasis_lite_state_t;

typedef enum _oasis_lite_recognition_result
{
    kOASISLiteRecognitionResult_Invalid,
    kOASISLiteRecognitionResult_Success,
    kOASISLiteRecognitionResult_Unknown,
    kOASISLiteRecognitionResult_Timeout,
    kOASISLiteRecognitionResult_Count
} oasis_lite_recognition_result_t;

typedef enum _oasis_lite_registration_result
{
    kOASISLiteRegistrationResult_Invalid,
    kOASISLiteRegistrationResult_Success,
    kOASISLiteRegistrationResult_Duplicated,
    kOASISLiteRegistrationResult_Timeout,
    kOASISLiteRegistrationResult_Count
} oasis_lite_registration_result_t;

typedef enum _oasis_lite_deregistration_result
{
    kOASISLiteDeregistrationResult_Invalid,
    kOASISLiteDeregistrationResult_Success,
    kOASISLiteDeregistrationResult_Timeout,
    kOASISLiteDeregistrationResult_Count
} oasis_lite_deregistration_result_t;

typedef enum _oasis_lite_quality_check_result
{
    kOasisLiteQualityCheck_Ok,
    kOasisLiteQualityCheck_SmallFace,
    kOasisLiteQualityCheck_Blurry,
    kOasisLiteQualityCheck_SideFace,
    kOasisLiteQualityCheck_Brightness,
    kOasisLiteQualityCheck_FakeFace,
    kOasisLiteQualityCheck_PartialBrightness,
    kOasisLiteQualityCheck_Count
} oasis_lite_quality_check_result_t;

typedef enum _oasis_blocking_event_id
{
    kOasisBlockingList_UserInput = 1,
    kOasisBlockingList_Record,
    kOasisBlockingList_Gesture,
    kOasisBlockingList_Audio,

    kOasisBlockingList_COUNT
} oasis_blocking_event_id_t;

typedef enum _oasis_status
{
    kOasis_Success = 0,
    kOasis_Failed
} oasis_status_t;

#if HEADLESS_ENABLE
typedef enum _oasisi_lite_headless_reg_process
{
    OASIS_LITE_HEADLESS_REG_START = 0,
    OASIS_LITE_HEADLESS_REG_FRONT_FACE,
    OASIS_LITE_HEADLESS_REG_LEFT_FACE,
    OASIS_LITE_HEADLESS_REG_RIGHT_FACE,
    OASIS_LITE_HEADLESS_REG_COMPLETE,
} oasis_lite_headless_reg_process_t;
#endif

typedef struct _oasis_lite_debug
{
    uint32_t sim;
    /* the face id with this sim value */
    uint16_t faceID;
    uint8_t isOk;
    uint8_t isSmallFace;
    uint8_t isBlurry;
    uint8_t isSideFace;
    uint8_t is2dFake;
    uint8_t is3dFake;
    uint8_t hasMask;
    uint8_t hasGlasses;
    uint8_t irBrightness;
    uint8_t rgbBrightness;
} oasis_lite_debug_t;

// oasis lite algorithm result
typedef struct _oasis_lite_result
{
    oasis_lite_state_t state;

    /* detect result */
    uint8_t face_count;
    FaceBox_t face_box;

    /* recognition result */
    int face_recognized;
    uint16_t face_id;
    char name[FACE_NAME_MAX_LEN];

    /* quality check results */
    oasis_lite_quality_check_result_t qualityCheck;

    /* registration result */
    union
    {
        uint32_t result;
        oasis_lite_recognition_result_t rec_result;
        oasis_lite_registration_result_t reg_result;
        oasis_lite_deregistration_result_t dereg_result;
    };
    float process;
#if HEADLESS_ENABLE
    uint8_t headless_reg_status;
#endif
    oasis_lite_debug_t debug_info;

    /* the maximum user data set to 32 bytes,
     * need to update if more than 32 bytes.*/
    uint8_t userData[32];
} oasis_lite_result_t;

// h264 algorithm result
typedef struct _h264_result
{
    recording_state_t state;
    uint32_t recordedDataSize;
    uint8_t *recordedDataAddress;
} h264_result_t;

typedef struct _gesture_result
{
#ifdef SMART_TLHMI_HOMEPANEL
    uvita_gesture_out hand;
#endif
} gesture_result_t;

/*
 * H.264 Recording device
 */
typedef enum _vision_algo_id
{
    kVisionAlgoID_OasisLite,
    kVisionAlgoID_H264Recording,
    kVisionAlgoID_UvitaGesture,
    kVisionAlgoID_Count
} vision_algo_id_t;

typedef struct _vision_algo_result
{
    vision_algo_id_t id;
    union
    {
        oasis_lite_result_t oasisLite;
        h264_result_t h264Recording;
        gesture_result_t uvitaHandGesture;
    };
} vision_algo_result_t;

#endif /* _HAL_VISION_ALGO_H_ */

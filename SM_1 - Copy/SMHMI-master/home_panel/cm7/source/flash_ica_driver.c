/*
 * Copyright 2019-2022 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_gpio.h"

// Uncomment to force the FICA table to initialize
//#define FORCE_FICA_TABLE_INIT   1

#include "fica_definition.h"
#include "flash_ica_driver.h"
#include "pin_mux.h"
#include "board.h"

#include "FreeRTOS.h"

// Flash includes
#include "sln_flash.h"
#include "sln_flash_ops.h"
#include "fsl_flexspi.h"

#if (!DISABLE_IMAGE_VERIFICATION || BOOTLOADER_AWS_IOT_OTA_ENABLED || BOOTLOADER_FWUPDATE_ENABLED)
#include "sln_auth.h"
#include "sln_flash_files.h"
#include "sln_flash_fs_ops.h"
#endif /* (!DISABLE_IMAGE_VERIFICATION || BOOTLOADER_AWS_IOT_OTA_ENABLED || BOOTLOADER_FWUPDATE_ENABLED) */
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

#define CERT_HEADER "-----BEGIN CERTIFICATE-----"

/*******************************************************************************
 * Variables
 ******************************************************************************/
static uint8_t s_appImgBuffer[FLASH_SECTOR_SIZE];

#ifdef DEBUG_FICA
__attribute__((section(".data.$SRAM_DTC")))
#ifdef DEBUG_IMG
uint8_t tdata[EXT_FLASH_ERASE_PAGE + 1] = {0};
#else
uint8_t tdata[EXT_FLASH_PROGRAM_PAGE + 1] = {0};
#endif
#endif

static int32_t s_newAppImgType       = FICA_IMG_TYPE_NONE;
static uint32_t s_newAppImgStartAddr = 0;
static uint32_t s_newAppImgMaxSize   = 0;
static uint32_t s_newAppCurrLen      = 0;

fica_record_t ProgExtAppInfo = {0};
volatile uint32_t ErrorCnt   = 0;

static fica_t s_fica = {0};

/*******************************************************************************
 * Code
 ******************************************************************************/

/*
 * FICA - Flash ICA (Image Configuration Area) Driver
 *
 */

int32_t FICA_app_program_ext_init(int32_t newimgtype)
{
    status_t status;
    int32_t curimgtype = FICA_IMG_TYPE_NONE;

    s_newAppImgType = newimgtype;

    // Initialize the Flash ICA (Image Configuration Area)
    status = FICA_initialize();

    if (SLN_FLASH_NO_ERROR == status)
    {
        status = FICA_GetCurAppStartType(&curimgtype);
    }

#if ENABLE_REMAP
    /*
     * When using remap, new images should always be compiled for bank A address.
     * The new firmware will be placed in the unused bank.
     */
    FICA_GetFreeImgSlot(&s_newAppImgType);

#else
    if (newimgtype == curimgtype)
    {
        status = SLN_FLASH_ERROR;
    }
#endif /* ENABLE_REMAP */

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Get the base address for the new application based on the image type
        status = FICA_get_app_img_start_addr(s_newAppImgType, &s_newAppImgStartAddr);
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Get the application image max size
        status = FICA_get_app_img_max_size(s_newAppImgType, &s_newAppImgMaxSize);
    }

    s_newAppCurrLen = 0;
    FICA_clear_buf(s_appImgBuffer, 0xFF, FLASH_SECTOR_SIZE);

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Erase all pages in this App bank
        status = FICA_Erase_Bank(s_newAppImgStartAddr, s_newAppImgMaxSize);
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        status = FICA_set_comm_flag(FICA_COMM_AIS_NAI_BIT);
    }

    return status;
}

int32_t FICA_app_program_ext_abs(uint32_t offset, uint8_t *bufptr, uint32_t writelen)
{
    // Write the image buffer to the external flash
    // len should be the flash page size until the last call, then the remainder
    // Erase page before writing

    uint32_t curextlen    = 0; // current length of the write, accumulates to total image write length (writelen)
    uint32_t curwritelen  = 0; // will be EXT_FLASH_ERASE_PAGE size until the last page
    uint32_t curextpage   = 0; // Increments up each loop to index the page that is to be written
    uint32_t curwriteaddr = 0; // address to erase page and write the current buffer data, buffer reindexes on each loop

    uint32_t pagenumrem    = offset % EXT_FLASH_PROGRAM_PAGE;
    uint32_t pagestartaddr = (offset / EXT_FLASH_PROGRAM_PAGE) * EXT_FLASH_PROGRAM_PAGE;
    uint32_t prestartlen   = offset - pagestartaddr;
    uint32_t tempaddr      = 0;

    bool commflag = false;

    // check if some newbie passed in a null pointer for a buffer
    if (bufptr == NULL || writelen == 0)
        return (SLN_FLASH_ERROR);

    // length can not be greater than the total flash size allocated for images
    if ((offset + writelen) > s_newAppImgMaxSize)
        return (SLN_FLASH_ERROR);

    // Verify the init passed before calling this abs function
    if (FICA_get_comm_flag(FICA_COMM_AIS_NAI_BIT, &commflag) != SLN_FLASH_NO_ERROR)
        return (SLN_FLASH_ERROR);

    if (!commflag)
        return (SLN_FLASH_ERROR);

    FICA_clear_buf(s_appImgBuffer, 0xFF, FLASH_SECTOR_SIZE);

    if ((offset + writelen) > s_newAppCurrLen)
    {
        s_newAppCurrLen = (offset + writelen);
    }

    // If its not on a flash page boundary, need to read flash before erasing the page
    if (pagenumrem > 0)
    {
        FICA_read_for_debug(s_newAppImgStartAddr + pagestartaddr, EXT_FLASH_PROGRAM_PAGE);

        // the image address doesn't start on a page boundary, read the flash from the start of the page
        if (SLN_Read_Flash_At_Address(s_newAppImgStartAddr + pagestartaddr, (uint8_t *)s_appImgBuffer, prestartlen) !=
            SLN_FLASH_NO_ERROR)
            return (SLN_FLASH_ERROR);
    }

    // Erase External Flash and Program it from the buffer, by external flash page
    while (curextlen < writelen)
    {
        // Write either a page or less if only less than a page is left
        curwritelen  = prestartlen + (writelen - curextlen) >= EXT_FLASH_PROGRAM_PAGE ?
                           EXT_FLASH_PROGRAM_PAGE - prestartlen :
                           writelen - curextlen;
        curwriteaddr = pagestartaddr + (curextpage * EXT_FLASH_PROGRAM_PAGE);

        // See if there is data after the data we need to write, that needs to be saved as well
        if (prestartlen + curwritelen < EXT_FLASH_PROGRAM_PAGE)
        {
            uint32_t remainpagelen = EXT_FLASH_PROGRAM_PAGE - prestartlen - curwritelen;
            tempaddr               = curwriteaddr + prestartlen + curwritelen;

            if (SLN_Read_Flash_At_Address(s_newAppImgStartAddr + tempaddr,
                                          (uint8_t *)&s_appImgBuffer[prestartlen + curwritelen],
                                          remainpagelen) != SLN_FLASH_NO_ERROR)
                return (SLN_FLASH_ERROR);
        }

        // Copy the data from the passed buffer to the Program Image Buffer
        memcpy(&s_appImgBuffer[prestartlen], bufptr, curwritelen);

        tempaddr = curwriteaddr;

        if (SLN_Write_Flash_At_Address(s_newAppImgStartAddr + tempaddr, (uint8_t *)s_appImgBuffer) !=
            SLN_FLASH_NO_ERROR)
            return (SLN_FLASH_ERROR);

        curextlen += curwritelen;
        bufptr += curwritelen;
        curextpage++;
        prestartlen = 0;
    }
    return (IMG_EXT_NO_ERROR);
}

int32_t FICA_app_program_ext_finalize()
{
    int32_t status = SLN_FLASH_NO_ERROR;

    status = FICA_write_image_info(s_newAppImgType, FICA_IMG_FMT_BIN, s_newAppCurrLen);

    if (SLN_FLASH_NO_ERROR == status)
    {
        status = FICA_set_comm_flag(FICA_COMM_AIS_NAV_BIT);
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        /* Set the newImg flag only if the updated img is a runnable one */
        if ((s_newAppImgType == FICA_IMG_TYPE_APP_A) || (s_newAppImgType == FICA_IMG_TYPE_APP_B))
        {
            configPRINTF(("Updating FICA table...\r\n"));
            s_fica.header.newType = s_newAppImgType;

            status = FICA_write_db();

            if (SLN_FLASH_NO_ERROR == status)
            {
                configPRINTF(("Setting NAP bit...\r\n"));
                status = FICA_set_comm_flag(FICA_COMM_AIS_NAP_BIT);
            }
        }
    }

    if ((SLN_FLASH_NO_ERROR == status) || (s_newAppImgType == FICA_IMG_TYPE_NONE))
    {
        configPRINTF(("Clearing NAI bit...\r\n"));
        status = FICA_clr_comm_flag(FICA_COMM_AIS_NAI_BIT);
    }

    return status;
}

int32_t FICA_app_program_ext_set_reset_vector(void)
{
    int32_t status = SLN_FLASH_NO_ERROR;
    bool commflag  = false;

    status = FICA_initialize();

    if (SLN_FLASH_NO_ERROR == status)
    {
        status = FICA_get_comm_flag(FICA_COMM_AIS_NAP_BIT, &commflag);
    }

    if (commflag)
    {
        s_newAppImgType = s_fica.header.newType;

        if ((FICA_IMG_TYPE_NONE >= s_newAppImgType) || (FICA_NUM_IMG_TYPES <= s_newAppImgType))
        {
            status = SLN_FLASH_ERROR;
        }

        if (SLN_FLASH_NO_ERROR == status)
        {
            if (s_newAppImgType != s_fica.header.currType)
            {
                // Write the new application address as the current application address
                status = FICA_SetCurAppStartType(s_newAppImgType);
            }
        }

        if (SLN_FLASH_NO_ERROR == status)
        {
            status = FICA_clr_comm_flag(FICA_COMM_AIS_NAV_BIT);
        }

        if (SLN_FLASH_NO_ERROR == status)
        {
            status = FICA_clr_comm_flag(FICA_COMM_AIS_NAP_BIT);
        }

        if (SLN_FLASH_NO_ERROR == status)
        {
            // Setting the OTA flash bit clears the request for OTA update
            status = FICA_set_comm_flag(FICA_COMM_AIS_OTA_BIT);
        }
    }
    else
    {
        status = SLN_FLASH_ERROR;
    }

    return status;
}

int32_t FICA_Erase_Bank(uint32_t startaddr, uint32_t banksize)
{
#if defined(ERASE_BLOCK_SUPPORT)
    uint32_t sizeIncrement = EXT_FLASH_ERASE_BLOCK;
#else
    uint32_t sizeIncrement = EXT_FLASH_ERASE_PAGE;
#endif /* ERASE_BLOCK_SUPPORT */

    // Erase this bank
    for (uint32_t runaddr = startaddr; runaddr < (startaddr + banksize); runaddr += sizeIncrement)
    {
#if defined(ERASE_BLOCK_SUPPORT)
        if (SLN_Erase_Block(runaddr) != kStatus_Success)
#else
        if (SLN_Erase_Sector(runaddr) != kStatus_Success)
#endif /* ERASE_BLOCK_SUPPORT */
            return (SLN_FLASH_ERROR);
    }
    return (SLN_FLASH_NO_ERROR);
}

#if (!DISABLE_IMAGE_VERIFICATION || BOOTLOADER_AWS_IOT_OTA_ENABLED || BOOTLOADER_FWUPDATE_ENABLED)
int32_t FICA_Verify_Certificate_From_Buffer(uint8_t *certPem)
{
    int32_t status     = SLN_FLASH_NO_ERROR;
    uint8_t *caRootPem = NULL;
    uint32_t caRootLen = 0;

    if (NULL == certPem)
    {
        status = SLN_FLASH_ERROR;
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        status = sln_flash_fs_ops_read(ROOT_CA_CERT, NULL, 0, &caRootLen);
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Found a file
        caRootPem = (uint8_t *)pvPortMalloc(caRootLen);

        if (NULL == caRootPem)
        {
            status = SLN_FLASH_ERROR;
        }
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        status = sln_flash_fs_ops_read(ROOT_CA_CERT, caRootPem, 0, &caRootLen);
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        status = SLN_AUTH_Verify_Cert((uint8_t *)caRootPem, certPem);
    }

    vPortFree(caRootPem);
    caRootPem = NULL;

    return status;
}

int32_t FICA_Verify_Signature(int32_t imgType)
{
    int32_t status          = SLN_FLASH_NO_ERROR;
    uint8_t *certPem        = NULL;
    uint32_t certLen        = 0;
    uint32_t msgFlashOffset = 0;
    uint32_t imageLen       = 0;
    uint8_t *msgsig         = NULL;

    // Check if its a valid image type
    if ((FICA_IMG_TYPE_NONE >= imgType) || (FICA_NUM_IMG_TYPES <= imgType))
    {
        status = SLN_FLASH_ERROR;
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        char certHeader[] = CERT_HEADER;
        // Get flash read address (0x6xxx_xxxx address)
        msgFlashOffset = s_fica.records[imgType].imgAddr;
        // Calculate the image length without certificate
        imageLen = s_fica.records[imgType].imgLen - MAX_CERT_LEN;

        status = SLN_Read_Flash_At_Address((msgFlashOffset + imageLen) & 0x0FFFFFFF, certHeader, sizeof(certHeader));

        if (kStatus_Success == status)
        {
            if (strncmp((const char *)certHeader, CERT_HEADER, strlen(CERT_HEADER)))
            {
                // No certificate at end, we can use entire image length (factory application load)
                imageLen = s_fica.records[imgType].imgLen;
            }
        }

        // Point to the records signature
        msgsig = s_fica.records[imgType].imgPkiSig;
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        if (FICA_IMG_TYPE_BOOTLOADER == imgType)
        {
            status = sln_flash_fs_ops_read(CRED_SIGNING_CERT, NULL, 0, &certLen);
        }
        else if (FICA_IMG_TYPE_APP_A == imgType)
        {
            status = sln_flash_fs_ops_read(APP_A_SIGNING_CERT, NULL, 0, &certLen);
        }
        else if (FICA_IMG_TYPE_APP_B == imgType)
        {
            status = sln_flash_fs_ops_read(APP_B_SIGNING_CERT, NULL, 0, &certLen);
        }
        else
        {
            status = SLN_FLASH_ERROR;
        }
    }

    if (SLN_FLASH_NO_ERROR != status)
    {
        configPRINTF(("[ERROR] Unable to obtain certificate size: %d\r\n", status));
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Found a file
        certPem = (uint8_t *)pvPortMalloc(certLen);

        if (NULL == certPem)
        {
            status = SLN_FLASH_ERROR;
        }
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        if (FICA_IMG_TYPE_BOOTLOADER == imgType)
        {
            status = sln_flash_fs_ops_read(CRED_SIGNING_CERT, certPem, 0, &certLen);
        }
        else if (FICA_IMG_TYPE_APP_A == imgType)
        {
            status = sln_flash_fs_ops_read(APP_A_SIGNING_CERT, certPem, 0, &certLen);
        }
        else if (FICA_IMG_TYPE_APP_B == imgType)
        {
            status = sln_flash_fs_ops_read(APP_B_SIGNING_CERT, certPem, 0, &certLen);
        }
        else
        {
            status = SLN_FLASH_ERROR;
        }
    }

    if (SLN_FLASH_NO_ERROR != status)
    {
        configPRINTF(("[ERROR] Unable to read certificate file: %d\r\n", status));
    }

    if ((SLN_FLASH_NO_ERROR == status) || (SLN_FLASH_FS_EENCRYPT2 == status))
    {
        // Verify this certificate
        status = FICA_Verify_Certificate_From_Buffer(certPem);
    }

    if ((SLN_FLASH_NO_ERROR == status) || (SLN_FLASH_FS_EENCRYPT2 == status))
    {
        status = SLN_AUTH_Verify_Signature(certPem, (uint8_t *)msgFlashOffset, imageLen, msgsig);
    }

    if (SLN_FLASH_NO_ERROR != status)
    {
        configPRINTF(("[ERROR] Unable to verify signature: %d\r\n", status));
    }

    vPortFree(certPem);
    certPem = NULL;

    return status;
}
#endif /* (!DISABLE_IMAGE_VERIFICATION || BOOTLOADER_AWS_IOT_OTA_ENABLED || BOOTLOADER_FWUPDATE_ENABLED) */

int32_t FICA_Verify_OTA_Image_Entry_Point(int32_t imgType)
{
    int32_t status             = SLN_FLASH_NO_ERROR;
    uint32_t appVectorTable    = 0;
    uint32_t appEntryPointAddr = 0;

    // Check if its a valid image type
    if ((FICA_IMG_TYPE_NONE >= imgType) || (FICA_NUM_IMG_TYPES <= imgType))
    {
        status = SLN_FLASH_ERROR;
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Get flash read address (0x6xxx_xxxx address)
        appVectorTable = SLN_Flash_Get_Read_Address(s_fica.records[imgType].imgAddr);

        appEntryPointAddr = (*(uint32_t *)(appVectorTable + 4));

        if ((0xFFFFFFFF == appEntryPointAddr) || /* invalid address */
            (0x00000000 == appEntryPointAddr) || /* invalid address */
            appEntryPointAddr <=
                appVectorTable || /* must be greater than Bank address, otherwise we could have BankA app in BankB */
            (appEntryPointAddr - appVectorTable) >
                0x10000) /* bigger difference should be a clear indicator of BankB app in BankA */
        {
            status = SLN_FLASH_ERROR;
        }
    }

    return status;
}

int32_t FICA_clear_buf(uint8_t *pbuf, uint8_t initval, uint32_t len)
{
    int32_t status = SLN_FLASH_ERROR;

    if (NULL != pbuf)
    {
        status = SLN_FLASH_NO_ERROR;

        // Set buffer contents to init value
        for (uint32_t i = 0; i < len; i++)
        {
            pbuf[i] = initval;
        }
    }

    return status;
}

int32_t FICA_read_db(void)
{
    uint8_t *bufptr = s_appImgBuffer;

    for (uint32_t runaddr = FICA_START_ADDR; runaddr < (FICA_START_ADDR + FICA_TABLE_SIZE);
         runaddr += EXT_FLASH_PROGRAM_PAGE, bufptr += EXT_FLASH_PROGRAM_PAGE)
    {
        if (SLN_Read_Flash_At_Address(runaddr, bufptr, EXT_FLASH_PROGRAM_PAGE) != SLN_FLASH_NO_ERROR)
            return (SLN_FLASH_ERROR);
    }
    return (SLN_FLASH_NO_ERROR);
}

int32_t FICA_write_db(void)
{
    int32_t status  = SLN_FLASH_NO_ERROR;
    uint8_t *bufptr = (uint8_t *)&s_fica;

    // Erase the FICA sector
    status = SLN_Erase_Sector(FICA_START_ADDR);

    if (SLN_FLASH_NO_ERROR == status)
    {
        uint32_t runaddr   = FICA_START_ADDR;
        uint32_t endaddr   = FICA_START_ADDR + sizeof(fica_t);
        uint32_t length    = (endaddr - runaddr);
        uint32_t pageCount = length / FLASH_PAGE_SIZE;
        uint32_t pageMod   = length % FLASH_PAGE_SIZE;
        uint32_t toCopy    = 0;

        if (pageMod)
        {
            pageCount++;
        }

        do
        {
            // How much should we copy? SLN_Write_Flash_Page will fill end of page with ones.
            toCopy = (length > FLASH_PAGE_SIZE) ? FLASH_PAGE_SIZE : length;

            // Write a page worth of s_fica to NVM
            status = SLN_Write_Flash_Page(runaddr, (uint8_t *)bufptr, toCopy);

            if (SLN_FLASH_NO_ERROR != status)
            {
                status = SLN_FLASH_ERROR;
                break;
            }

            runaddr += FLASH_PAGE_SIZE; // Increment the destination NVM address
            bufptr += FLASH_PAGE_SIZE;  // Increment the source RAM address
            length -= FLASH_PAGE_SIZE;  // Decrement the total length
        } while (--pageCount);
    }

    // Read it back into the Info Structure so FICA is using what was written
    if (SLN_FLASH_NO_ERROR == status)
    {
        status = SLN_Read_Flash_At_Address(FICA_START_ADDR, (uint8_t *)&s_fica, sizeof(fica_t));
    }

    return status;
}

int32_t FICA_write_buf(uint32_t offset, uint32_t len, void *buf)
{
    uint8_t *pbuf = (uint8_t *)buf;

    offset -= FICA_START_ADDR;

    if (pbuf == NULL)
        return (SLN_FLASH_ERROR);
    for (int i = 0; i < len; i++)
    {
        if ((offset + i) >= EXT_FLASH_ERASE_PAGE)
            return (SLN_FLASH_ERROR);
        s_appImgBuffer[offset + i] = *pbuf++;
    }
    return (SLN_FLASH_NO_ERROR);
}

int32_t FICA_write_full_page(uint32_t offset, uint32_t progpagesize, uint32_t erasepagersize, uint32_t *pdatabuf)
{
    uint32_t run_offset = 0;

    FICA_read_for_debug(offset, EXT_FLASH_ERASE_PAGE);

    // Erase page before writing
    if (SLN_Erase_Sector(offset) != SLN_FLASH_NO_ERROR)
        return (SLN_FLASH_ERROR);

    FICA_read_for_debug(offset, EXT_FLASH_ERASE_PAGE);

    while (run_offset < EXT_FLASH_ERASE_PAGE)
    {
        if (SLN_Write_Flash_At_Address(offset + run_offset, (uint8_t *)pdatabuf) != SLN_FLASH_NO_ERROR)
            return (SLN_FLASH_ERROR);

        pdatabuf += EXT_FLASH_PROGRAM_PAGE;
        run_offset += EXT_FLASH_PROGRAM_PAGE;
    }
    FICA_read_for_debug(offset, EXT_FLASH_ERASE_PAGE);

    return (SLN_FLASH_NO_ERROR);
}

int32_t FICA_read_buf(uint32_t offset, uint32_t len, void *buf)
{
    uint8_t *pbuf = (uint8_t *)buf;

    if (pbuf == NULL)
        return (SLN_FLASH_ERROR);
    for (int i = 0; i < len; i++)
    {
        if ((offset + i) >= EXT_FLASH_ERASE_PAGE)
            return (SLN_FLASH_ERROR);
        *pbuf++ = s_appImgBuffer[offset + i];
    }
    return (SLN_FLASH_NO_ERROR);
}

int32_t FICA_get_new_app_img_type(int32_t *imgtype)
{
    int32_t status = SLN_FLASH_NO_ERROR;

    // Read out FICA from NVM to RAM... at least read out what is where is supposed to be
    status = SLN_Read_Flash_At_Address(FICA_START_ADDR, (uint8_t *)&s_fica, sizeof(fica_t));

    if (SLN_FLASH_NO_ERROR == status)
    {
        *imgtype = s_fica.header.newType;
    }

    return status;
}

int32_t FICA_get_app_img_start_addr(int32_t imgtype, uint32_t *startaddr)
{
    int32_t status = SLN_FLASH_ERROR;

    if (NULL != startaddr)
    {
        switch (imgtype)
        {
            case FICA_IMG_TYPE_BOOTLOADER:
                *startaddr = FICA_IMG_BOOTLOADER_ADDR;
                break;
            case FICA_IMG_TYPE_APP_A:
                *startaddr = FICA_IMG_APP_A_ADDR;
                break;
            case FICA_IMG_TYPE_APP_B:
                *startaddr = FICA_IMG_APP_B_ADDR;
                break;
#if FICA_RESOURCES_ENABLE
            case FICA_IMG_TYPE_RESOURCES_A:
                *startaddr = FICA_IMG_RESOURCE_A_ADDR;
                break;
            case FICA_IMG_TYPE_RESOURCES_B:
                *startaddr = FICA_IMG_RESOURCE_B_ADDR;
                break;
#endif /* FICA_RESOURCES_ENABLE */
            case FICA_IMG_TYPE_NONE:
            default:
                *startaddr = FICA_IMG_INVALID_ADDR;
                break;
        }

        if (*startaddr != FICA_IMG_INVALID_ADDR)
        {
            status = SLN_FLASH_NO_ERROR;
        }
    }

    return status;
}

int32_t FICA_get_app_img_max_size(int32_t imgtype, uint32_t *maximgsize)
{
    int32_t status = SLN_FLASH_ERROR;

    if (NULL != maximgsize)
    {
        switch (imgtype)
        {
            case FICA_IMG_TYPE_BOOTLOADER:
                *maximgsize = FICA_IMG_BOOTLOADER_SIZE;
                break;
            case FICA_IMG_TYPE_APP_A:
                *maximgsize = FICA_IMG_APP_A_SIZE;
                break;
            case FICA_IMG_TYPE_APP_B:
                *maximgsize = FICA_IMG_APP_B_SIZE;
                break;
#if FICA_RESOURCES_ENABLE
            case FICA_IMG_TYPE_RESOURCES_A:
            case FICA_IMG_TYPE_RESOURCES_B:
                *maximgsize = FICA_IMG_RESOURCE_SIZE;
                break;
#endif /* FICA_RESOURCES_ENABLE */
            case FICA_IMG_TYPE_NONE:
            default:
                *maximgsize = 0;
                break;
        }

        if (*maximgsize != 0)
        {
            status = SLN_FLASH_NO_ERROR;
        }
    }

    return status;
}

int32_t FICA_write_image_info(int32_t imgtype, uint32_t imgfmt, uint32_t len)
{
    int32_t status     = SLN_FLASH_NO_ERROR;
    uint32_t startaddr = 0;

    // Check if its a valid image type
    if ((FICA_IMG_TYPE_NONE >= imgtype) || (FICA_NUM_IMG_TYPES <= imgtype))
    {
        status = SLN_FLASH_ERROR;
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Set the start address of the image based on the image type
        status = FICA_get_app_img_start_addr(imgtype, &startaddr);
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Write the rest of the record values for this image types ICA (Image Config Area)
        s_fica.records[imgtype].descriptor = FICA_IMG_DESC_ID;

        // Write Image Type into FICA record for this image
        s_fica.records[imgtype].imgType = imgtype;

        // Write Image Start Address into FICA Record for this image type
        s_fica.records[imgtype].imgAddr = startaddr;

        // Write Image Size into FICA Record for this image type
        s_fica.records[imgtype].imgLen = len;

        // Write Image Type into FICA Record for this image type
        s_fica.records[imgtype].imgFmt = imgfmt;

        // Write the info to the flash
        status = FICA_write_db();

        configPRINTF(("[FICA] Flash ICA record written successfully\r\n"));
    }

    return status;
}

int32_t FICA_write_image_record(int32_t imgtype, uint32_t imgaddr, uint32_t imglen, uint8_t *imgsig)
{
    int32_t status = SLN_FLASH_NO_ERROR;

    // Check for valid pointer
    if (NULL == imgsig)
    {
        status = SLN_FLASH_ERROR;
    }

    // Check for valid imgType
    if ((SLN_FLASH_NO_ERROR == status) && ((FICA_IMG_TYPE_NONE >= imgtype) || (FICA_NUM_IMG_TYPES <= imgtype)))
    {
        status = SLN_FLASH_ERROR;
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        s_fica.records[imgtype].descriptor = FICA_IMG_DESC_ID;
        s_fica.records[imgtype].imgType    = imgtype;
        s_fica.records[imgtype].imgAddr    = imgaddr;
        s_fica.records[imgtype].imgLen     = imglen;
        s_fica.records[imgtype].imgFmt     = FICA_IMG_FMT_BIN;
#if (!DISABLE_IMAGE_VERIFICATION || BOOTLOADER_AWS_IOT_OTA_ENABLED || BOOTLOADER_FWUPDATE_ENABLED)
        memcpy(s_fica.records[imgtype].imgPkiSig, imgsig, RSA_SIG_LEN);
#endif /* (!DISABLE_IMAGE_VERIFICATION || BOOTLOADER_AWS_IOT_OTA_ENABLED || BOOTLOADER_FWUPDATE_ENABLED) */
        // Write the info to the flash
        status = FICA_write_db();
    }

    return status;
}

bool is_FICA_initialized(void)
{
    bool ret = false;

#ifdef FORCE_FICA_TABLE_INIT
    static bool firsttime = true;
    if (firsttime)
    {
        firsttime = false;
        return (false);
    }
#endif /* FORCE_FICA_TABLE_INIT */

    // Check ICA Start Identifier, value should be 0x5A5A5A5A
    if ((s_fica.header.descriptor == FICA_ICA_DESC) && (s_fica.header.version == FICA_VER))
    {
        configPRINTF(("[FICA] Flash ICA already initialized\r\n"));

        ret = true;
    }
    else
    {
        configPRINTF(("[FICA] Flash ICA needs initialization\r\n"));
    }

    return ret;
}

int32_t FICA_initialize(void)
{
    int32_t status     = SLN_FLASH_NO_ERROR;
    bool isInitialized = false;

    configPRINTF(("[FICA] VERSION %d\r\n", FICA_VER));

    status = FICA_verify_ext_flash();

    if (SLN_FLASH_NO_ERROR != status)
    {
        status = SLN_FLASH_ERROR;
    }

    configPRINTF(("[FICA] Checking Image Config Area (ICA) initialization\r\n"));

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Read out FICA from NVM to RAM... at least read out what is where is supposed to be
        status = SLN_Read_Flash_At_Address(FICA_START_ADDR, (uint8_t *)&s_fica, sizeof(fica_t));
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        isInitialized = is_FICA_initialized();
    }

    // If its already initialized, return no error
    if (!isInitialized)
    {
        configPRINTF(("[FICA] Flash ICA initialization started\r\n"));

        memset((uint8_t *)&s_fica, 0x00, sizeof(fica_t));

        status = SLN_Erase_Sector(FICA_START_ADDR);

        if (kStatus_Success == status)
        {
            // Write the ICA Start ID 0x5A5A5A5A
            s_fica.header.descriptor = FICA_ICA_DESC;

            // Write the ICA Version Number
            s_fica.header.version = FICA_VER;

            // Write the Factory Application type as the current application type
            s_fica.header.currType = FICA_IMG_TYPE_APP_A;

            s_fica.header.currBank = FICA_IMG_BANK_A;

            // Set OTA and OTW Bit so OTA/OTW update shows not pending
            s_fica.header.communication =
                FICA_COMM_AIS_OTA_BIT | FICA_COMM_FWUPDATE_BIT | FICA_COMM_FWUPDATE_METHOD_BIT;

            // Initialize all the records
            for (int32_t imgtype = FICA_IMG_TYPE_BOOTLOADER; imgtype < FICA_NUM_IMG_TYPES; imgtype++)
            {
                // Write defaults to all Image Records
                status = FICA_write_image_info(imgtype, FICA_IMG_FMT_NONE, 0);

                if (SLN_FLASH_NO_ERROR != status)
                {
                    status = SLN_FLASH_ERROR;
                    break;
                }
            }
        }
    }

    configPRINTF(("[FICA] Flash ICA initialization complete\r\n"));

    return status;
}

int32_t FICA_verify_ext_flash(void)
{
    uint8_t id   = FLASH_VENDOR_ID;
    uint8_t *pid = (uint8_t *)&id;

    configPRINTF(("[FICA] RT Flash Check...\r\n"));

    /* Read flash vendor ID */
    if (FICA_read_flash_id(pid) != SLN_FLASH_NO_ERROR)
    {
        configPRINTF(("[FICA] ERROR: Cannot find Flash device!\r\n"));

        return (SLN_FLASH_ERROR);
    }
    else
    {
        configPRINTF(("[FICA] Found Flash device!\r\n"));
    }

    return (SLN_FLASH_NO_ERROR);
}

int32_t FICA_read_flash_id(uint8_t *pid)
{
    uint8_t id;
    int32_t ret = SLN_FLASH_NO_ERROR;
    uint32_t irqState;

    irqState = SLN_ram_disable_irq();

    SLN_ram_disable_d_cache();

    // Read flash ID
    ret = sln_flash_ops_get_flash_id(BOARD_FLEXSPI, &id);

    if (SLN_FLASH_NO_ERROR != ret)
    {
        ret = SLN_FLASH_ERROR;
    }

    if (SLN_FLASH_NO_ERROR == ret)
    {
        // Check if it matches the intended device
        if (*pid != id)
        {
            ret = SLN_FLASH_ERROR;
        }
    }

    SLN_ram_enable_d_cache();

    SLN_ram_enable_irq(irqState);
    /* Flush pipeline to allow pending interrupts take place
     * before starting next loop */
    __ASM volatile("isb 0xF" ::: "memory");

    return ret;
}

void reset_mcu(void)
{
    NVIC_SystemReset();
    while (1)
        ;
}

int32_t FICA_get_comm_flag(uint32_t comflag, bool *flagstate)
{
    int32_t status = SLN_FLASH_NO_ERROR;

    // Read out FICA from NVM to RAM... at least read out what is where is supposed to be
    status = SLN_Read_Flash_At_Address(FICA_START_ADDR, (uint8_t *)&s_fica, sizeof(fica_t));

    if (SLN_FLASH_NO_ERROR == status)
    {
        *flagstate = (s_fica.header.communication & comflag) ? true : false;
    }

    return status;
}

int32_t FICA_set_comm_flag(uint32_t comflag)
{
    int32_t status = SLN_FLASH_NO_ERROR;

    // Read out FICA from NVM to RAM... at least read out what is where is supposed to be
    status = SLN_Read_Flash_At_Address(FICA_START_ADDR, (uint8_t *)&s_fica, sizeof(fica_t));

    if (SLN_FLASH_NO_ERROR == status)
    {
        if (!(comflag & s_fica.header.communication))
        {
            s_fica.header.communication |= comflag;

            status = FICA_write_db();
        }
    }

    return status;
}

int32_t FICA_clr_comm_flag(uint32_t comflag)
{
    int32_t status = SLN_FLASH_NO_ERROR;

    // Read out FICA from NVM to RAM... at least read out what is where is supposed to be
    status = SLN_Read_Flash_At_Address(FICA_START_ADDR, (uint8_t *)&s_fica, sizeof(fica_t));

    if (SLN_FLASH_NO_ERROR == status)
    {
        if (comflag & s_fica.header.communication)
        {
            s_fica.header.communication &= ~comflag;

            status = FICA_write_db();
        }
    }

    return status;
}

int32_t FICA_read_for_debug(uint32_t addr, uint32_t len)
{
#ifdef DEBUG_FICA

    FICA_clear_buf(tdata, 0xFF);

    if (SLN_Read_Flash_At_Address(addr, (uint8_t *)tdata, EXT_FLASH_ERASE_PAGE) != SLN_FLASH_NO_ERROR)
        return (SLN_FLASH_ERROR);

    for (uint32_t i = 0; i < EXT_FLASH_ERASE_PAGE; i++)
    {
        if (s_appImgBuffer[i] != tdata[i])
            ErrorCnt += 1;
    }
#endif /* DEBUG_FICA */

    if (ErrorCnt)
        return (SLN_FLASH_ERROR);

    return (SLN_FLASH_NO_ERROR);
}

int32_t FICA_GetCurBootStartAddr(uint32_t *paddr)
{
    int32_t status = SLN_FLASH_NO_ERROR;

    // Read out FICA from NVM to RAM... at least read out what is where is supposed to be
    status = SLN_Read_Flash_At_Address(FICA_START_ADDR, (uint8_t *)&s_fica, sizeof(fica_t));

    if (SLN_FLASH_NO_ERROR == status)
    {
        *paddr = s_fica.records[s_fica.header.currBootType].imgAddr;
    }

    return status;
}

int32_t FICA_GetCurBank(int32_t *pImgBank)
{
    int32_t status = SLN_FLASH_NO_ERROR;

    if (NULL == pImgBank)
    {
        status = SLN_FLASH_ERROR;
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        *pImgBank = FICA_IMG_TYPE_NONE;
        status    = FICA_initialize();
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Read the address of the current bank programmed in flash
        *pImgBank = s_fica.header.currBank;
    }

    return status;
}

int32_t FICA_GetCurAppStartType(int32_t *pimgtype)
{
    int32_t status = SLN_FLASH_NO_ERROR;

    if (NULL == pimgtype)
    {
        status = SLN_FLASH_ERROR;
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        *pimgtype = FICA_IMG_TYPE_NONE;

        status = FICA_initialize();
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Read the address of the current application programmed in flash
        *pimgtype = s_fica.header.currType;

        if ((*pimgtype != FICA_IMG_TYPE_APP_A) && (*pimgtype != FICA_IMG_TYPE_APP_B))
        {
            // No app found in flash, write the default address
            *pimgtype = FICA_IMG_TYPE_APP_A;

            s_fica.header.currType = *pimgtype;
            s_fica.header.currBank = FICA_IMG_BANK_A;
            // No Application set, write it to flash
            status = FICA_write_db();
        }
    }

    return status;
}

int32_t FICA_GetImgSig(int32_t imgtype, uint8_t **imgSig)
{
    int32_t status = SLN_FLASH_NO_ERROR;

    // Check if its a valid image type
    if ((FICA_IMG_TYPE_NONE >= imgtype) || (FICA_NUM_IMG_TYPES <= imgtype))
    {
        status = SLN_FLASH_ERROR;
    }

    if (NULL == imgSig)
    {
        status = SLN_FLASH_ERROR;
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        *imgSig = s_fica.records[imgtype].imgPkiSig;
    }

    return status;
}

int32_t FICA_GetImgLength(int32_t imgtype, uint32_t *imgSize)
{
    int32_t status = SLN_FLASH_NO_ERROR;

    // Check if its a valid image type
    if ((FICA_IMG_TYPE_NONE >= imgtype) || (FICA_NUM_IMG_TYPES <= imgtype))
    {
        status = SLN_FLASH_ERROR;
    }

    if (NULL == imgSize)
    {
        status = SLN_FLASH_ERROR;
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        *imgSize = s_fica.records[imgtype].imgLen;
    }

    return status;
}

int32_t FICA_GetNewAppStartAddr(uint32_t *paddr)
{
    if (paddr == NULL)
    {
        return (SLN_FLASH_ERROR);
    }

    *paddr = s_newAppImgStartAddr;
    return (SLN_FLASH_NO_ERROR);
}

int32_t FICA_GetNewAppSize(uint32_t *pSize)
{
    if (pSize == NULL)
    {
        return (SLN_FLASH_ERROR);
    }

    *pSize = s_newAppCurrLen;
    return (SLN_FLASH_NO_ERROR);
}

int32_t FICA_SetCurBootType(int32_t imgtype)
{
    int32_t status = SLN_FLASH_NO_ERROR;

    s_fica.header.currBootType = imgtype;

    status = FICA_write_db();

    return status;
}

int32_t FICA_SetCurAppStartType(int32_t imgtype)
{
    int32_t status   = SLN_FLASH_NO_ERROR;
    int32_t bankType = FICA_IMG_BANK_NONE;

    s_fica.header.currType = imgtype;
    FICA_GetBankFromImgType(imgtype, &bankType);
    s_fica.header.currBank = bankType;

    status = FICA_write_db();

    return status;
}

int32_t FICA_bank_program_ext_init(fica_img_bank_t newImgBank)
{
    status_t status;
    int32_t curImgBank = FICA_IMG_BANK_NONE;

    // Initialize the Flash ICA (Image Configuration Area)
    status = FICA_initialize();

    if (SLN_FLASH_NO_ERROR == status)
    {
        status = FICA_GetCurBank(&curImgBank);
    }

    s_newAppImgStartAddr = (newImgBank == FICA_IMG_BANK_A) ? FICA_IMG_BANK_A_ADDR : FICA_IMG_BANK_B_ADDR;

#if ENABLE_REMAP

    /*
     * When using remap, new images should always be compiled for bank A address.
     * The new firmware will be placed in the unused bank.
     */
    if (newImgBank == FICA_IMG_BANK_A)
    {
        if (curImgBank == FICA_IMG_BANK_A)
        {
            /* Allocate the unused bank */
            s_newAppImgStartAddr = FICA_IMG_BANK_B_ADDR;
        }
    }
#else
    if (newImgBank == curImgBank)
    {
        status = SLN_FLASH_ERROR;
    }
#endif /* ENABLE_REMAP */

    s_newAppImgMaxSize = FICA_IMG_BANK_SIZE;
    s_newAppCurrLen    = 0;
    s_newAppImgType    = FICA_IMG_TYPE_NONE;

    FICA_clear_buf(s_appImgBuffer, 0xFF, FLASH_SECTOR_SIZE);

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Erase all pages in this App bank
        status = FICA_Erase_Bank(s_newAppImgStartAddr, s_newAppImgMaxSize);
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        status = FICA_set_comm_flag(FICA_COMM_AIS_NAI_BIT);
    }

    if (SLN_FLASH_ERROR == status)
    {
        s_newAppImgMaxSize   = 0;
        s_newAppCurrLen      = 0;
        s_newAppImgStartAddr = 0;
        s_newAppImgType      = FICA_IMG_TYPE_NONE;
    }

    return status;
}

int32_t FICA_GetFreeImgSlot(int32_t *imgType)
{
    uint32_t curBank = FICA_IMG_TYPE_NONE;
    int32_t status   = SLN_FLASH_NO_ERROR;

    if (imgType == NULL)
    {
        return SLN_FLASH_ERROR;
    }

    status = FICA_GetCurBank(&curBank);

    if (SLN_FLASH_NO_ERROR == status)
    {
        if ((*imgType == FICA_IMG_TYPE_APP_A) || (*imgType == FICA_IMG_TYPE_APP_B))
        {
            if (curBank == FICA_IMG_BANK_A)
            {
                *imgType = FICA_IMG_TYPE_APP_B;
            }
            else if (curBank == FICA_IMG_BANK_B)
            {
                *imgType = FICA_IMG_TYPE_APP_A;
            }
        }
#if FICA_RESOURCES_ENABLE
        else if ((*imgType == FICA_IMG_TYPE_RESOURCES_A) || (*imgType == FICA_IMG_TYPE_RESOURCES_B))
        {
            if (curBank == FICA_IMG_BANK_A)
            {
                *imgType = FICA_IMG_TYPE_RESOURCES_B;
            }
            else if (curBank == FICA_IMG_BANK_B)
            {
                *imgType = FICA_IMG_TYPE_RESOURCES_A;
            }
        }
#endif /* FICA_RESOURCES_ENABLE */
        else
        {
            *imgType = FICA_IMG_TYPE_NONE;
        }
    }

    return status;
}

int32_t FICA_GetBankStartingAddr(fica_img_bank_t bank, uint32_t *startBankAddr)
{
    if (startBankAddr == NULL)
    {
        return SLN_FLASH_ERROR;
    }

    *startBankAddr = 0;
    if (bank == FICA_IMG_BANK_A)
    {
        *startBankAddr = FICA_IMG_BANK_A_ADDR;
    }
    else if (bank == FICA_IMG_BANK_B)
    {
        *startBankAddr = FICA_IMG_BANK_B_ADDR;
    }

    return (SLN_FLASH_NO_ERROR);
}

int32_t FICA_GetBankFromImgType(int32_t imgtype, int32_t *bankType)
{
    if (bankType == NULL)
    {
        return SLN_FLASH_ERROR;
    }

    *bankType = FICA_IMG_BANK_NONE;
    if (imgtype == FICA_IMG_TYPE_APP_A)
    {
        *bankType = FICA_IMG_BANK_A;
    }
    else if (imgtype == FICA_IMG_TYPE_APP_B)
    {
        *bankType = FICA_IMG_BANK_B;
    }

    return (SLN_FLASH_NO_ERROR);
}

int32_t FICA_GetImgTypeFromAddr(uint32_t appaddr, int32_t *imgtype)
{
    // Find the img type given the img address
    if (appaddr == FICA_IMG_APP_A_ADDR)
        *imgtype = FICA_IMG_TYPE_APP_A;
    else if (appaddr == FICA_IMG_APP_B_ADDR)
        *imgtype = FICA_IMG_TYPE_APP_B;
    else if (appaddr == FICA_IMG_BOOTLOADER_ADDR)
        *imgtype = FICA_IMG_TYPE_BOOTLOADER;
    else
        return (SLN_FLASH_ERROR);

    return (SLN_FLASH_NO_ERROR);
}

int32_t FICA_GetImgTypeFromResetISRAddr(int32_t *imgType)
{
    int32_t status           = SLN_FLASH_NO_ERROR;
    int32_t resetIsrOffset   = 0;
    uint32_t resetISRAddress = 0;

    if (imgType == NULL)
    {
        status = SLN_FLASH_ERROR;
    }
    else
    {
        // Extract the ResetISR address from the vector table
        resetISRAddress = *((uint32_t *)APPLICATION_RESET_ISR_ADDRESS);
        resetISRAddress = resetISRAddress - FLEXSPI_AMBA_BASE;

        // Find the image type given the ResetISR address
        status = SLN_FLASH_ERROR;

        // Check if Bootloader
        if (status == SLN_FLASH_ERROR)
        {
            resetIsrOffset = resetISRAddress - FICA_IMG_BOOTLOADER_ADDR;
            if ((resetIsrOffset >= 0) && (resetIsrOffset < FICA_IMG_BOOTLOADER_SIZE))
            {
                *imgType = FICA_IMG_TYPE_BOOTLOADER;
                status   = SLN_FLASH_NO_ERROR;
            }
        }

        // Check if Bank A
        if (status == SLN_FLASH_ERROR)
        {
            resetIsrOffset = resetISRAddress - FICA_IMG_APP_A_ADDR;
            if ((resetIsrOffset >= 0) && (resetIsrOffset < FICA_IMG_APP_A_SIZE))
            {
                *imgType = FICA_IMG_TYPE_APP_A;
                status   = SLN_FLASH_NO_ERROR;
            }
        }

        // Check if Bank B
        if (status == SLN_FLASH_ERROR)
        {
            resetIsrOffset = resetISRAddress - FICA_IMG_APP_B_ADDR;
            if ((resetIsrOffset >= 0) && (resetIsrOffset < FICA_IMG_APP_B_SIZE))
            {
                *imgType = FICA_IMG_TYPE_APP_B;
                status   = SLN_FLASH_NO_ERROR;
            }
        }
    }

    return status;
}

bool FICA_is_OTA_FlashBitCleared()
{
    bool otaflag = false;

    if (FICA_initialize() != SLN_FLASH_NO_ERROR)
    {
        return (false);
    }

#ifdef TESTING_OTA
    // if testing, clear the bit so it will go into AWS OTA mode
    Clear_OTA_FlashBit();
#endif /* TESTING_OTA */

    // Read the OTA bit from the flash
    if (FICA_get_comm_flag(FICA_COMM_AIS_OTA_BIT, &otaflag) != SLN_FLASH_NO_ERROR)
        return (false);

    // if the bit is cleared, return true
    if (otaflag == false)
        return (true);
    return (false);
}

int32_t FICA_Set_OTA_FlashBit()
{
    int32_t status = SLN_FLASH_NO_ERROR;

    status = FICA_initialize();

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Set the OTA bit in the flash
        status = FICA_set_comm_flag(FICA_COMM_AIS_OTA_BIT);
    }

    return status;
}

int32_t FICA_Clear_OTA_FlashBit()
{
    int32_t status = SLN_FLASH_NO_ERROR;

    status = FICA_initialize();

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Set the OTA bit in the flash
        status = FICA_clr_comm_flag(FICA_COMM_AIS_OTA_BIT);
    }

    return status;
}

#if (defined(ENABLE_UNSIGNED_USB_MSD) || ENABLE_UNSIGNED_USB_MSD == 1)
// NOTE: To facilitate ease of use in SLN-ALEXA-IOT kits
int32_t FICA_set_usb_mode(void)
{
    int32_t status = SLN_FLASH_NO_ERROR;

    status = FICA_initialize();

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Set the USB bit in the flash
        status = FICA_set_comm_flag(FICA_COMM_AIS_USB_BIT);
    }

    return status;
}

int32_t FICA_clr_usb_mode(void)
{
    int32_t status = SLN_FLASH_NO_ERROR;

    status = FICA_initialize();

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Set the USB bit in the flash
        status = FICA_clr_comm_flag(FICA_COMM_AIS_USB_BIT);
    }

    return status;
}

int32_t FICA_get_usb_mode(bool *isUSB)
{
    bool temp      = false;
    int32_t status = SLN_FLASH_NO_ERROR;

    status = FICA_initialize();

    if (SLN_FLASH_NO_ERROR == status)
    {
        // Set the USB bit in the flash
        status = FICA_get_comm_flag(FICA_COMM_AIS_USB_BIT, &temp);
    }

    if (SLN_FLASH_NO_ERROR == status)
    {
        *isUSB = temp;
    }

    return status;
}
#endif /* ENABLE_UNSIGNED_USB_MSD */

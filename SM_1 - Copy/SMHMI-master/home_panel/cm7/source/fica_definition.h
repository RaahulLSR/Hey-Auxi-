/*
 * Copyright 2018-2022 NXP.
 * This software is owned or controlled by NXP and may only be used strictly in accordance with the
 * license terms that accompany it. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms. If you do not agree to be bound by the
 * applicable license terms, then you may not retain, install, activate or otherwise use the software.
 */

#ifndef _FICA_DEFINITION_
#define _FICA_DEFINITION_

#include "sln_flash_config.h"

/*******************************************************************************
 * FICA (Flash Image Configuration Area) Definitions
 ******************************************************************************/
#define FICA_VER 3

/* FICA Descriptor, used to determine if the FICA area has been initialized or not */
#define FICA_ICA_DESC  (0xA5A5A5A5)
#define CHECK_APP_SIGN 1
#define APP_SIGN_SIZE  2048

/*******************************************************************************
 * Image Field Definitions
 * Defaults and choices for each of the FICA Record fields
 * Each offset is a word (4 bytes)
 ******************************************************************************/

/* Image Record Start Descriptor */
#define FICA_REC_START_ID (0x5A5A5A5A)

#define FICA_OFFSET_ICA_COMM 8

/* Image Record Field Default values and choices
 * Offset 0 - Descriptor ID (start id)
 */
#define FICA_IMG_DESC_ID (0x5A5A5A5A)

#define FICA_COMM_BOOT_NONE   (0x00000000)
#define FICA_COMM_AIS_OTA_BIT (0x00000010)
/* Bit indicates that a firmware update is needed using solutions method */
#define FICA_COMM_FWUPDATE_BIT (0x00000020)
/* Bit indicates which method to be used for firmware update SLN_OTA/SLN_OTW */
#define FICA_COMM_FWUPDATE_METHOD_BIT (0x00000040)
#define FICA_COMM_AIS_NAV_BIT         (0x00000100)
#define FICA_COMM_AIS_NAP_BIT         (0x00000200)
#define FICA_COMM_AIS_NAI_BIT         (0x00000400)

#if (defined(ENABLE_UNSIGNED_USB_MSD) || ENABLE_UNSIGNED_USB_MSD == 1)
/* NOTE: To facilitate ease of use in SLN-ALEXA-IOT kits */
#define FICA_COMM_AIS_USB_BIT (0x00000800)
#endif

/* The ResetISR address is placed on the index 1 of the vector table */
#define APPLICATION_RESET_ISR_ADDRESS (SCB->VTOR + 0x4)

#define FICA_IMG_SIZE_ZERO 0 /* Image Size - default */
#define FICA_IMG_CRC_NONE  0 /* Image CRC - default */
#define FICA_IMG_HASH_NONE 0 /* Image Key - default */
#define FICA_IMG_RSV       0 /* Offset 7 - Reserved - default */

/*******************************************************************************
 * Images` sizes (based on flash size)
 ******************************************************************************/

#if defined(ENABLE_BOOTSTRAP)
#define FICA_IMG_BOOTSTRAP_SIZE  (0x00040000) /* 0.25 MB */
#define FICA_IMG_BOOTLOADER_SIZE (0x001C0000) /* 1.75 MB */
#else
#define FICA_IMG_BOOTSTRAP_SIZE  (0x00000000) /* 0.00 MB */
#define FICA_IMG_BOOTLOADER_SIZE (0x00100000) /* 1.00 MB */
#endif

#if FLASH_SIZE < 0x2000000U
/* FLASH_SIZE < 32MB */
#error "Application cannot run with a flash size smaller than 32MB"
#elif (FLASH_SIZE == 0x2000000U)
/* FLASH_SIZE = 32MB */
#define FICA_IMG_RESERVED_SIZE (0x00000000)      /* 0  MB - toolbox - deprecated */
#define FICA_IMG_APP_SIZE      (0x00580000)      /* 5.5 MB */
#define FICA_IMG_APP_A_SIZE    FICA_IMG_APP_SIZE /* 5.5 MB */
#define FICA_IMG_APP_B_SIZE    FICA_IMG_APP_SIZE /* 5.5 MB */
#if FICA_RESOURCES_ENABLE
#define FICA_IMG_RESOURCE_SIZE (0x900000) /* 9 MB */
#endif                                    /* FICA_RESOURCES_ENABLE */
#elif (FLASH_SIZE == 0x4000000U)
/* FLASH_SIZE = 64MB */
#define FICA_IMG_RESERVED_SIZE (0x00000000) /* 0  MB - toolbox - deprecated */
#define FICA_IMG_APP_SIZE      (0x00700000) /* 7 MB , enlarge FICA_IMG_APP_SIZE to 10M first to contain the VIT models.*/
#define FICA_IMG_APP_A_SIZE    FICA_IMG_APP_SIZE /* 7 MB */
#define FICA_IMG_APP_B_SIZE    FICA_IMG_APP_SIZE /* 7 MB */

#if FICA_RESOURCES_ENABLE
#define FICA_IMG_RESOURCE_SIZE (0xD00000) /* 13 MB */
#endif                                    /* FICA_RESOURCES_ENABLE */

#endif /* FLASH_SIZE */

#ifndef FICA_IMG_RESOURCE_SIZE
#define FICA_IMG_RESOURCE_SIZE (0x0)
#endif /* FICA_IMG_RESOURCE_SIZE */

#define FICA_IMG_BANK_SIZE (FICA_IMG_APP_SIZE + FICA_IMG_RESOURCE_SIZE)
#if (FLASH_SIZE == 0x4000000U)
#define FICA_FILE_SYS_SIZE (0x280000)
#else
#define FICA_FILE_SYS_SIZE (0x100000)
#endif /* FLASH_SIZE */

#define FICA_CRYPTO_BACKUP_SIZE (FLASH_SECTOR_SIZE)
#define FICA_TABLE_SIZE         (FLASH_SECTOR_SIZE)

/*******************************************************************************
 * Images` start addresses offsets (based on images` sizes)
 ******************************************************************************/

#define FICA_IMG_BOOTSTRAP_ADDR     (0x00000000)
#define FICA_IMG_BOOTSTRAP_IVT_ADDR (FICA_IMG_BOOTSTRAP_ADDR + 0x00001000)
#define FICA_IMG_BOOTLOADER_ADDR    (FICA_IMG_BOOTSTRAP_ADDR + FICA_IMG_BOOTSTRAP_SIZE)
#define FICA_IMG_RESERVED_ADDR      (FICA_IMG_BOOTLOADER_ADDR + FICA_IMG_BOOTLOADER_SIZE) /* toolbox - deprecated */
/* Keep Bank A and Bank B at consecutive address */
#define FICA_IMG_BANK_A_ADDR     (FICA_IMG_RESERVED_ADDR + FICA_IMG_RESERVED_SIZE)
#define FICA_IMG_APP_A_ADDR      (FICA_IMG_BANK_A_ADDR)
#define FICA_IMG_RESOURCE_A_ADDR (FICA_IMG_APP_A_ADDR + FICA_IMG_APP_SIZE)

#define FICA_IMG_BANK_B_ADDR     (FICA_IMG_BANK_A_ADDR + FICA_IMG_BANK_SIZE)
#define FICA_IMG_APP_B_ADDR      (FICA_IMG_BANK_B_ADDR)
#define FICA_IMG_RESOURCE_B_ADDR (FICA_IMG_APP_B_ADDR + FICA_IMG_APP_SIZE)

#if (FLASH_SIZE == 0x4000000U)
#define FICA_IMG_BANK_C_ADDR     (FICA_IMG_BANK_B_ADDR + FICA_IMG_BANK_SIZE)
#define FICA_IMG_APP_C_ADDR      (FICA_IMG_BANK_C_ADDR)
#define FICA_IMG_RESOURCE_C_ADDR (FICA_IMG_BANK_C_ADDR + FICA_IMG_APP_SIZE)
#define FICA_LAST_APP_ADDR       (FICA_IMG_APP_C_ADDR)
#else
#define FICA_LAST_APP_ADDR (FICA_IMG_APP_B_ADDR)
#endif /* FLASH_SIZE */

/* Because of the remmap functionality, the resource is always placed at FICA_IMG_RESOURCE_A_ADDR */
#define FICA_IMG_RESOURCE_ADDR (FICA_IMG_RESOURCE_A_ADDR)

#define FICA_IMG_FILE_SYS_ADDR   (FICA_LAST_APP_ADDR + FICA_IMG_BANK_SIZE)
#define FICA_FREE_MEM_START_ADDR (FICA_IMG_FILE_SYS_ADDR + FICA_FILE_SYS_SIZE)
#define FICA_IMG_INVALID_ADDR    (0xFFFFFFFF)

/* FICA Table and Crypto Context Backup are placed at the end of the flash */
#define FICA_START_ADDR         (FLASH_SIZE - FICA_TABLE_SIZE)
#define FICA_CRYPTO_BACKUP_ADDR (FICA_START_ADDR - FICA_CRYPTO_BACKUP_SIZE)
#define FICA_FREE_MEM_END_ADDR  (FICA_CRYPTO_BACKUP_ADDR)

/* Flash memory between FICA_FREE_MEM_START_ADDR and FICA_FREE_MEM_END_ADDR is considered not mapped
 * and may be used by the application. EX:
 * - Alexa2 QSPI maps first 128KB as KVS.
 *
 * Perform a memory sufficiency/overlapping check.
 */
#if FICA_FREE_MEM_START_ADDR > FICA_FREE_MEM_END_ADDR
#error "Some memory sections overlap due to insufficient flash memory."
#endif

/* Used to check if flash address is valid */
#define FICA_IMG_FLASH_MASK           (0xF0000000)
#define FICA_IMG_BANK_START_ADDR_MASK (0x00FF0000)

/* Used to check flash addresses for Bank A vs. Bank B */
#define FICA_IMG_BANK_APP_MASK (FICA_IMG_BANK_START_ADDR_MASK + FICA_IMG_FLASH_MASK)

/*******************************************************************************
 * FICA typedefs
 ******************************************************************************/

/*! @brief FICA Header Structure */
typedef struct __attribute__((packed)) _fica_header
{
    uint32_t descriptor;    /*!< FICA Descriptor field */
    uint32_t version;       /*!< FICA Version number */
    uint32_t communication; /*!< Inter-App communication field */
    uint32_t currType;      /*!< New App Status */
    uint32_t currBank;      /*!< Current bank that is being used */
    uint32_t newType;       /*!< New App Type */
    uint32_t currBootType;  /*!< Current boot type, typically FICA_IMG_TYPE_BOOTLOADER, but may vary */
} fica_header_t;

/*! @brief FICA Image Types enumeration */
typedef enum _fica_img_bank
{
    FICA_IMG_BANK_NONE = -1, /*!< Default */
    FICA_IMG_BANK_A,
    FICA_IMG_BANK_B,
    FICA_IMG_BANK_C,
    FICA_IMG_BANK_NUMBERS
} fica_img_bank_t;

/*! @brief FICA Image Types enumeration */
typedef enum _fica_img_type
{
    FICA_IMG_TYPE_NONE = -1,   /*!< Default */
    FICA_IMG_TYPE_BOOTLOADER,  /*!< Bootloader Image */
    FICA_IMG_TYPE_APP_A,       /*!< Application A Image */
    FICA_IMG_TYPE_APP_B,       /*!< Application B Image */
    FICA_IMG_TYPE_RESOURCES_A, /*!< Resources A Image */
    FICA_IMG_TYPE_RESOURCES_B, /*!< Resources B Image */
    /* FICA IMT TYPE C is not involved in normal booting/updating process.
     * Used only for demo purpose. Should not be used in the flash_ica_driver.c
     */
    FICA_IMG_TYPE_APP_C, /*!< Application C Image */
    FICA_NUM_IMG_TYPES,  /*!< Total Number of Images Defined in this Version */
} fica_img_type_t;

#define FICA_IMG_TYPE_BUNDLE (FICA_NUM_IMG_TYPES + 1)

/*! @brief FICA Image Format Types enumeration */
typedef enum _fica_img_fmt
{
    FICA_IMG_FMT_NONE = 0, /*!< default */
    FICA_IMG_FMT_BIN,      /*!< Binary */
    FICA_IMG_FMT_SREC,     /*!< S-Record */
    FICA_IMG_FMT_AES_128,  /*!< Secure Binary */
} fica_img_fmt_t;

/*! @brief FICA Record Structure */
typedef struct __attribute__((packed)) _fica_record
{
    uint32_t descriptor;    /*!< Record descriptor */
    uint32_t imgType;       /*!< Image type (see fica_img_type_t) */
    uint32_t imgAddr;       /*!< Image start address */
    uint32_t imgLen;        /*!< Image length */
    uint32_t imgFmt;        /*!< Image format (see fica_img_fmt_t) */
    uint32_t imgHashType;   /*!< Image hash type */
    uint32_t imgHashLoc;    /*!<  */
    uint32_t imgEncType;    /*!<  */
    uint32_t imgPkiType;    /*!<  */
    uint32_t imgPkiLoc;     /*!<  */
    uint8_t imgPkiSig[256]; /*!<  */
    uint8_t res[12];        /*!<  */
} fica_record_t;

/*! @brief FICA Record Structure */
typedef struct __attribute__((packed)) _fica
{
    fica_header_t header;
    fica_record_t records[FICA_NUM_IMG_TYPES];
} fica_t;

#endif /* _FICA_DEFINITION_ */

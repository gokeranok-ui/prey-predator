/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    sd_diskio.c
  * @brief   SD Disk I/O driver (polling implementation)
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "ff_gen_drv.h"
#include "sd_diskio.h"
#include "stm32f4xx_hal.h"

/* External variables --------------------------------------------------------*/
extern SD_HandleTypeDef hsd;

/* Private defines -----------------------------------------------------------*/
#define SD_DEFAULT_BLOCK_SIZE   512U
#define SD_TIMEOUT_MS           5000U

#ifndef SD_DISKIO_TRACE
#define SD_DISKIO_TRACE 1
#endif

#if SD_DISKIO_TRACE
#define SD_TRACE(...)   printf("[sd_diskio] " __VA_ARGS__)
#else
#define SD_TRACE(...)
#endif

/* Private variables ---------------------------------------------------------*/
static volatile DSTATUS Stat = STA_NOINIT;

#if defined(__GNUC__)
#ifndef __ALIGN_BEGIN
#define __ALIGN_BEGIN
#endif
#ifndef __ALIGN_END
#define __ALIGN_END __attribute__ ((aligned (4)))
#endif
#endif

__ALIGN_BEGIN static uint8_t scratch[SD_DEFAULT_BLOCK_SIZE] __ALIGN_END;

/* Private function prototypes -----------------------------------------------*/
static DSTATUS SD_CheckStatus(BYTE lun);
static int SD_WaitReady(uint32_t timeout_ms);

DSTATUS SD_initialize(BYTE);
DSTATUS SD_status(BYTE);
DRESULT SD_read(BYTE, BYTE*, DWORD, UINT);
#if _USE_WRITE == 1
DRESULT SD_write(BYTE, const BYTE*, DWORD, UINT);
#endif /* _USE_WRITE == 1 */
#if _USE_IOCTL == 1
DRESULT SD_ioctl(BYTE, BYTE, void*);
#endif /* _USE_IOCTL == 1 */

const Diskio_drvTypeDef SD_Driver =
{
  SD_initialize,
  SD_status,
  SD_read,
#if _USE_WRITE == 1
  SD_write,
#endif
#if _USE_IOCTL == 1
  SD_ioctl,
#endif
};

/* Private functions ---------------------------------------------------------*/
static int SD_WaitReady(uint32_t timeout_ms)
{
  uint32_t start = HAL_GetTick();

  while ((HAL_GetTick() - start) < timeout_ms)
  {
    if (BSP_SD_GetCardState() == SD_TRANSFER_OK)
    {
      return 0;
    }
  }

  SD_TRACE("WaitReady: timeout after %lu ms\n", (unsigned long)timeout_ms);
  return -1;
}

static DSTATUS SD_CheckStatus(BYTE lun)
{
  (void)lun;

  if (BSP_SD_IsDetected() != SD_PRESENT)
  {
    Stat = STA_NOINIT;
    SD_TRACE("CheckStatus: card not present\n");
    return Stat;
  }

  if (SD_WaitReady(SD_TIMEOUT_MS) == 0)
  {
    Stat &= ~STA_NOINIT;
  }
  else
  {
    Stat = STA_NOINIT;
  }

  SD_TRACE("CheckStatus: Stat=0x%02x\n", Stat);
  return Stat;
}

/**
  * @brief  Initializes a Drive
  * @param  lun : not used
  * @retval DSTATUS: Operation status
  */
DSTATUS SD_initialize(BYTE lun)
{
  Stat = STA_NOINIT;

  SD_TRACE("Initialize: starting...\n");

  if (BSP_SD_Init() == MSD_OK)
  {
    if (SD_WaitReady(SD_TIMEOUT_MS) == 0)
    {
      Stat = SD_CheckStatus(lun);
    }
    else
    {
      SD_TRACE("Initialize: wait ready failed\n");
    }
  }
  else
  {
    SD_TRACE("Initialize: BSP_SD_Init failed\n");
  }

  SD_TRACE("Initialize: Stat=0x%02x\n", Stat);
  return Stat;
}

/**
  * @brief  Gets Disk Status
  * @param  lun : not used
  * @retval DSTATUS: Operation status
  */
DSTATUS SD_status(BYTE lun)
{
  return SD_CheckStatus(lun);
}

/**
  * @brief  Reads Sector(s)
  * @param  lun : not used
  * @param  buff: Data buffer to store read data
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to read (1..128)
  * @retval DRESULT: Operation result
  */
DRESULT SD_read(BYTE lun, BYTE *buff, DWORD sector, UINT count)
{
  (void)lun;

  if (Stat & STA_NOINIT)
  {
    return RES_NOTRDY;
  }

  if (SD_WaitReady(SD_TIMEOUT_MS) != 0)
  {
    SD_TRACE("Read: wait ready before read failed (sector=%lu)\n", (unsigned long)sector);
    return RES_ERROR;
  }

  if ((uintptr_t)buff & 0x3U)
  {
    for (UINT i = 0; i < count; ++i)
    {
      uint32_t blk = (uint32_t)(sector + i);
      if (BSP_SD_ReadBlocks((uint32_t *)scratch, blk, 1, SD_TIMEOUT_MS) != MSD_OK)
      {
        SD_TRACE("Read: BSP_SD_ReadBlocks failed (sector=%lu)\n", (unsigned long)blk);
        SD_TRACE("Read: HAL error=0x%08lx\n", (unsigned long)HAL_SD_GetError(&hsd));
        return RES_ERROR;
      }

      if (SD_WaitReady(SD_TIMEOUT_MS) != 0)
      {
        SD_TRACE("Read: wait ready after read failed (sector=%lu)\n", (unsigned long)blk);
        return RES_ERROR;
      }

      memcpy(&buff[i * SD_DEFAULT_BLOCK_SIZE], scratch, SD_DEFAULT_BLOCK_SIZE);
    }
  }
  else
  {
    if (BSP_SD_ReadBlocks((uint32_t *)buff, (uint32_t)sector, count, SD_TIMEOUT_MS) != MSD_OK)
    {
      SD_TRACE("Read: BSP_SD_ReadBlocks multi failed (sector=%lu, count=%u)\n",
               (unsigned long)sector, (unsigned)count);
      SD_TRACE("Read: HAL error=0x%08lx\n", (unsigned long)HAL_SD_GetError(&hsd));
      return RES_ERROR;
    }

    if (SD_WaitReady(SD_TIMEOUT_MS) != 0)
    {
      SD_TRACE("Read: wait ready after multi read failed\n");
      return RES_ERROR;
    }
  }

  return RES_OK;
}

#if _USE_WRITE == 1
/**
  * @brief  Writes Sector(s)
  * @param  lun : not used
  * @param  buff: Data to be written
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to write (1..128)
  * @retval DRESULT: Operation result
  */
DRESULT SD_write(BYTE lun, const BYTE *buff, DWORD sector, UINT count)
{
  (void)lun;

  if (Stat & STA_NOINIT)
  {
    return RES_NOTRDY;
  }

  if (SD_WaitReady(SD_TIMEOUT_MS) != 0)
  {
    SD_TRACE("Write: wait ready before write failed (sector=%lu)\n", (unsigned long)sector);
    return RES_ERROR;
  }

  if ((uintptr_t)buff & 0x3U)
  {
    for (UINT i = 0; i < count; ++i)
    {
      memcpy(scratch, &buff[i * SD_DEFAULT_BLOCK_SIZE], SD_DEFAULT_BLOCK_SIZE);

      uint32_t blk = (uint32_t)(sector + i);

      if (BSP_SD_WriteBlocks((uint32_t *)scratch, blk, 1, SD_TIMEOUT_MS) != MSD_OK)
      {
        SD_TRACE("Write: BSP_SD_WriteBlocks failed (sector=%lu)\n", (unsigned long)blk);
        SD_TRACE("Write: HAL error=0x%08lx\n", (unsigned long)HAL_SD_GetError(&hsd));
        return RES_ERROR;
      }

      if (SD_WaitReady(SD_TIMEOUT_MS) != 0)
      {
        SD_TRACE("Write: wait ready after write failed (sector=%lu)\n", (unsigned long)blk);
        return RES_ERROR;
      }
    }
  }
  else
  {
    if (BSP_SD_WriteBlocks((uint32_t *)buff, (uint32_t)sector, count, SD_TIMEOUT_MS) != MSD_OK)
    {
      SD_TRACE("Write: BSP_SD_WriteBlocks multi failed (sector=%lu, count=%u)\n",
               (unsigned long)sector, (unsigned)count);
      SD_TRACE("Write: HAL error=0x%08lx\n", (unsigned long)HAL_SD_GetError(&hsd));
      return RES_ERROR;
    }

    if (SD_WaitReady(SD_TIMEOUT_MS) != 0)
    {
      SD_TRACE("Write: wait ready after multi write failed\n");
      return RES_ERROR;
    }
  }

  return RES_OK;
}
#endif /* _USE_WRITE == 1 */

#if _USE_IOCTL == 1
/**
  * @brief  I/O control operation
  * @param  lun : not used
  * @param  cmd: Control code
  * @param  buff: Buffer to send/receive control data
  * @retval DRESULT: Operation result
  */
DRESULT SD_ioctl(BYTE lun, BYTE cmd, void *buff)
{
  (void)lun;

  if (Stat & STA_NOINIT)
  {
    return RES_NOTRDY;
  }

  BSP_SD_CardInfo CardInfo;

  switch (cmd)
  {
    case CTRL_SYNC:
      if (SD_WaitReady(SD_TIMEOUT_MS) == 0)
      {
        return RES_OK;
      }
      SD_TRACE("Ioctl: CTRL_SYNC timeout\n");
      return RES_ERROR;

    case GET_SECTOR_COUNT:
      BSP_SD_GetCardInfo(&CardInfo);
      *(DWORD *)buff = CardInfo.LogBlockNbr;
      SD_TRACE("Ioctl: GET_SECTOR_COUNT=%lu\n", (unsigned long)CardInfo.LogBlockNbr);
      return RES_OK;

    case GET_SECTOR_SIZE:
      BSP_SD_GetCardInfo(&CardInfo);
      *(WORD *)buff = CardInfo.LogBlockSize;
      SD_TRACE("Ioctl: GET_SECTOR_SIZE=%u\n", (unsigned)CardInfo.LogBlockSize);
      return RES_OK;

    case GET_BLOCK_SIZE:
      BSP_SD_GetCardInfo(&CardInfo);
      *(DWORD *)buff = CardInfo.LogBlockSize / SD_DEFAULT_BLOCK_SIZE;
      SD_TRACE("Ioctl: GET_BLOCK_SIZE=%lu\n", (unsigned long)(CardInfo.LogBlockSize / SD_DEFAULT_BLOCK_SIZE));
      return RES_OK;

    default:
      SD_TRACE("Ioctl: unsupported cmd=%u\n", cmd);
      return RES_PARERR;
  }
}
#endif /* _USE_IOCTL == 1 */

/* USER CODE BEGIN lastSection */
/* USER CODE END lastSection */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


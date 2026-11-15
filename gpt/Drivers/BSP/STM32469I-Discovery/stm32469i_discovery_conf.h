#ifndef __STM32469I_DISCOVERY_CONF_H
#define __STM32469I_DISCOVERY_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Identify the board */
#ifndef USE_STM32469I_DISCO
#define USE_STM32469I_DISCO
#endif
/* If you know the board revision, uncomment one */
//#define USE_STM32469I_DISCO_REVB
//#define USE_STM32469I_DISCO_REVC

/* ======= ENABLE/DISABLE BSP COMPONENT DRIVERS ======= */
#define USE_IO_EXPANDER                          1U
#define USE_TS_GESTURE                           1U
#define USE_TS_MULTI_TOUCH                       1U
#define USE_AUDIO_AMPLIFIER_WM8994
#define USE_CAMERA                                0U
#define USE_QSPI_FLASH                            1U
#define USE_SDRAM                                 1U

/* ======= LCD OPTIONS ======= */
#define LCD_LAYER_0_ADDRESS                     (0xC0000000U)
#define LCD_LAYER_1_ADDRESS                     (0xC0130000U)
#define LCD_DEFAULT_WIDTH                        800U
#define LCD_DEFAULT_HEIGHT                       480U

/* ======= I2C TIMING (for IO expander, touch, audio, etc.) ======= */
/* Value taken from CubeMX when I2C3 clock = 100MHz => 100kHz I2C speed */
#define DISCOVERY_I2Cx_TIMING                   0x00A0A3F7U

#ifdef __cplusplus
}
#endif

#endif /* __STM32469I_DISCOVERY_CONF_H */

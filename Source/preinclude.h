#define TC_LINKKEY_JOIN
#define NV_INIT
#define NV_RESTORE


#define TP2_LEGACY_ZC
//patch sdk
// #define ZDSECMGR_TC_ATTEMPT_DEFAULT_KEY TRUE

#define NWK_AUTO_POLL
#define MULTICAST_ENABLED FALSE

#define ZCL_READ
#define ZCL_WRITE
#define ZCL_BASIC
#define ZCL_IDENTIFY
#define ZCL_ON_OFF
#define ZCL_LEVEL_CTRL

//#define ZCL_LIGHT_LINK_ENHANCE
//#define ZCL_GROUPS
//#define ZCL_SCENES
//#define ZCL_ALARMS
//#define SE_UK_EXT

#define ZCL_REPORTING_DEVICE
#define ZCL_REPORT_DESTINATION_DEVICE

#if defined(HAL_BOARD_MONITOR)
//#define POWER_SAVING
//#define DO_DEBUG_UART

#elif defined(HAL_BOARD_CHDTECH_DEV)
// #define DO_DEBUG_UART
#define DO_DEBUG_MT

#endif

#ifdef EPD3IN7
#define ZSTACK_DEVICE_BUILD (DEVICE_BUILD_ENDDEVICE)
#endif

#ifdef TFT3IN5
//#define ZSTACK_DEVICE_BUILD (DEVICE_BUILD_ROUTER)
#define ZSTACK_DEVICE_BUILD (DEVICE_BUILD_ENDDEVICE)
#ifndef DO_DEBUG_UART
#define BREAKOUT
#endif
#endif

#define DISABLE_GREENPOWER_BASIC_PROXY
#define BDB_FINDING_BINDING_CAPABILITY_ENABLED 1
//#define BDB_REPORTING TRUE

#define ISR_KEYINTERRUPT
#define HAL_BUZZER FALSE

#if defined(EPD3IN7)
#define HAL_LED TRUE
#define BLINK_LEDS TRUE
#endif
#define HAL_I2C TRUE


#define LQI_REQ
#define BIND_REQ
#define IEEE_ADDR_REQ 
#if defined(LQI_REQ) || defined(BIND_REQ)
#define MT_TASK
#define MT_SYS_FUNC
#define MT_ZDO_FUNC
#define MT_ZDO_MGMT
#define INT_HEAP_LEN (2688 - 0x100 - 0x3 - 0x1F - 0x3 - 0xE)
#endif


//one of this boards
// #define HAL_BOARD_MONITOR
// #define HAL_BOARD_CHDTECH_DEV

#if !defined(HAL_BOARD_MONITOR) && !defined(HAL_BOARD_CHDTECH_DEV)
#error "Board type must be defined"
#endif

/*
Your JOB: Set this value according to your application
Max num of cluster with reportable attributes in any endpoint  
(eg. 2 endpoints with same cluster with reportable attributes counts as 2, 
regardless of the number of reportable attributes in the cluster)
*/
#define BDB_MAX_CLUSTERENDPOINTS_REPORTING 10

//Motion
#define MOTION_PORT 1 
#define MOTION_PIN  3
#define MOTION_POWER_PORT 1
#define MOTION_POWER_PIN  0

//#define EPD2IN9
//#define EPD2IN9V2
//#define EPD2IN13V2
//#define EPD1IN54V2
//#define EPD3IN7
//#define TFT3IN5

//spi BME280, EPD
#define HAL_LCD_MODE_PORT 0 
#define HAL_LCD_MODE_PIN  0  // EPD DC / TFT DC
#define HAL_LCD_RESET_PORT 1
#define HAL_LCD_RESET_PIN  1 // EPD RST / TFT RST
#define HAL_LCD_CS_PORT 1
#define HAL_LCD_CS_PIN  2    // BME280 CS
#define HAL_LCD_CS2_PORT 0
#define HAL_LCD_CS2_PIN  7   // EPD CS / TFT CS
#ifdef EPD3IN7
#define HAL_LCD_BUSY_PORT 0
#define HAL_LCD_BUSY_PIN  4  // EPD BUSY
#endif
#ifdef TFT3IN5
#define HAL_LCD_CS3_PORT 0
#define HAL_LCD_CS3_PIN  1   // TFT TP_CS
#define HAL_LCD_TPIRQ_PORT 0
#define HAL_LCD_TPIRQ_PIN  4  // TFT TP_IRQ
#define HAL_LCD_PWM_PORT 1
#define HAL_LCD_PWM_PIN  4  // TFT PWM
#define HAL_LCD_PWM_PORT1   // enable TFT PWM
#define HAL_LCD_RGB_18BIT
#define TFT_ILI9486
//#define TFT_ILI9488
//#define RTP_XPT2046
#define CTP_FT6236
#endif
//i2c bh1750
#define OCM_CLK_PORT 0
#define OCM_DATA_PORT 0
#define OCM_CLK_PIN 5
#define OCM_DATA_PIN 6

#define HAL_I2C_RETRY_CNT 1


#ifdef DO_DEBUG_UART
#define HAL_UART TRUE
#define HAL_UART_DMA 1
#if !defined(LQI_REQ) && !defined(BIND_REQ)
#define INT_HEAP_LEN (2685 - 0x4B - 0xBB)
#endif
#endif

#ifndef DO_DEBUG_UART
//#define HAL_UART TRUE
//#define HAL_UART_DMA 2
//#define HAL_UART_ISR 2
#define HAL_LCD_PWM_PORT0
#endif

#ifdef DO_DEBUG_MT
#define HAL_UART TRUE
#define HAL_UART_DMA 1
#define HAL_UART_ISR 2
#define INT_HEAP_LEN (2688-0xC4-0x15-0x44-0x20-0x1E)

#define MT_TASK

#define MT_UTIL_FUNC
#define MT_UART_DEFAULT_BAUDRATE HAL_UART_BR_115200
#define MT_UART_DEFAULT_OVERFLOW FALSE

#define ZTOOL_P1

#define MT_APP_FUNC
#define MT_APP_CNF_FUNC
#define MT_SYS_FUNC
#define MT_ZDO_FUNC
#define MT_ZDO_MGMT
#define MT_DEBUG_FUNC

#endif



#if defined(HAL_BOARD_MONITOR)
#define FACTORY_RESET_BY_LONG_PRESS_PORT 0x04 //port2

#define APP_COMMISSIONING_BY_LONG_PRESS TRUE
#define APP_COMMISSIONING_BY_LONG_PRESS_PORT 0x04 //port2

//#define HAL_KEY_P0_INPUT_PINS BV(0)
//#define HAL_KEY_P0_INPUT_PINS_EDGE HAL_KEY_RISING_EDGE

#define HAL_KEY_P0_INPUT_PINS BV(4)
//#define HAL_KEY_P0_INPUT_PINS_EDGE HAL_KEY_RISING_EDGE
#define HAL_KEY_P0_INPUT_PINS_EDGE HAL_KEY_FALLING_EDGE

#define HAL_KEY_P1_INPUT_PINS BV(3)
#define HAL_KEY_P1_INPUT_PINS_EDGE HAL_KEY_RISING_EDGE

#define HAL_KEY_P2_INPUT_PINS BV(0)

#elif defined(HAL_BOARD_CHDTECH_DEV)
#define HAL_KEY_P0_INPUT_PINS BV(1)
#define HAL_KEY_P2_INPUT_PINS BV(0)
#endif

#include "hal_board_cfg.h"

#include "stdint.h"
#include "stddef.h"

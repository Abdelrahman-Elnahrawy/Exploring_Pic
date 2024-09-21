/* 
 * File:   Dio_cfg.h
 * Author: Your Name <your.name at your.org>
 *
 * Created on September 19, 2024, 5:13 PM
 */

#ifndef DIO_CFG_H
#define	DIO_CFG_H
#include "../cfg/Gpio_Cfg.h"
#include "../include/Gpio_Types.h"

// Only define configurations for the pin that u are gonna use as dio

//#define DIO_CONFIG_PIN_0        GPIO_PIN_0, GPIO_DIR_OUTPUT, GPIO_PIN_LOW, GPIO_PULLUP_DISABLE
//#define DIO_CONFIG_PIN_1        GPIO_PIN_1, GPIO_DIR_OUTPUT, GPIO_PIN_LOW, GPIO_PULLUP_DISABLE
//#define DIO_CONFIG_PIN_2        GPIO_PIN_2, GPIO_DIR_INPUT, GPIO_PIN_LOW, GPIO_PULLUP_ENABLE
#define DIO_CONFIG_PIN_3        GPIO_PIN_3, GPIO_DIR_INPUT, GPIO_PIN_LOW, GPIO_PULLUP_ENABLE
#define DIO_CONFIG_PIN_4        GPIO_PIN_4, GPIO_DIR_OUTPUT, GPIO_PIN_LOW, GPIO_PULLUP_DISABLE
//#define DIO_CONFIG_PIN_5        GPIO_PIN_5, GPIO_DIR_OUTPUT, GPIO_PIN_LOW, GPIO_PULLUP_ENABLE






// GP0 check: Must be configured as GPIO if the configuration exists
#if defined(GPIO_PIN0_GPIO) ^ defined(DIO_CONFIG_PIN_0)
    #error "For GP0, either both GPIO_PIN0_GPIO and DIO_CONFIG_PIN_0 must be defined or neither should be defined."
#endif

// GP1 check: Must be configured as GPIO if the configuration exists
#if defined(GPIO_PIN1_GPIO) ^ defined(DIO_CONFIG_PIN_1)
    #error "For GP1, either both GPIO_PIN1_GPIO and DIO_CONFIG_PIN_1 must be defined or neither should be defined."
#endif

// GP2 check: Must be configured as GPIO if the configuration exists
#if defined(GPIO_PIN2_GPIO) ^ defined(DIO_CONFIG_PIN_2)
    #error "For GP2, either both GPIO_PIN2_GPIO and DIO_CONFIG_PIN_2 must be defined or neither should be defined."
#endif

// GP3 check: Must be configured as GPIO if the configuration exists
#if defined(GPIO_PIN3_GPIO) ^ defined(DIO_CONFIG_PIN_3)
    #error "For GP3, either both GPIO_PIN3_GPIO and DIO_CONFIG_PIN_3 must be defined or neither should be defined."
#endif

// GP4 check: Must be configured as GPIO if the configuration exists
#if defined(GPIO_PIN4_GPIO) ^ defined(DIO_CONFIG_PIN_4)
    #error "For GP4, either both GPIO_PIN4_GPIO and DIO_CONFIG_PIN_4 must be defined or neither should be defined."
#endif

// GP5 check: Must be configured as GPIO if the configuration exists
#if defined(GPIO_PIN5_GPIO) ^ defined(DIO_CONFIG_PIN_5)
    #error "For GP5, either both GPIO_PIN5_GPIO and DIO_CONFIG_PIN_5 must be defined or neither should be defined."
#endif


#endif	/* DIO_CFG_H */


/*_____________________________GPIO_CFG_H_____________________________________________________
                                      ___           ___           ___
 Author: Abdelrahman Selim           /\  \         /\  \         /\  \
                                    /::\  \       /::\  \       /::\  \
Created on:17 sep 2024             /:/\:\  \     /:/\:\  \     /:/\:\  \
                                  /::\ \:\  \   _\:\ \:\  \   /::\ \:\  \
 Version: 01                     /:/\:\ \:\__\ /\ \:\ \:\__\ /:/\:\ \:\__\
                                 \/__\:\/:/  / \:\ \:\ \/__/ \/__\:\/:/  / 
                                      \::/  /   \:\ \:\__\        \::/  /
                                      /:/  /     \:\/:/  /        /:/  /
 Brief : PIC EXPLORING               /:/  /       \::/  /        /:/  /
                                     \/__/         \/__/         \/__/
 _________________________________________________________________________________________*/
#ifndef GPIO_CFG_H
#define GPIO_CFG_H

#include "../../UTILS/Std_Types.h"
#include "../include/Gpio_Types.h"


#define GPIO_PIN_COUNT 6  // Number of available GPIO pins for PIC12F629/675

// uncomment the settings u want for the pin 


// GP0 functions
//#define GPIO_PIN0_GPIO         GPIO_PIN_0   // General Purpose I/O
#define GPIO_PIN0_AN0        GPIO_PIN_0   // Analog Input AN0 (for PIC12F675 only)
//#define GPIO_PIN0_CIN_PLUS   GPIO_PIN_0   // Comparator CIN+ input
//#define GPIO_PIN0_ICSPDAT    GPIO_PIN_0   // ICSP Data (programming)

// GP1 functions
//#define GPIO_PIN1_GPIO        GPIO_PIN_1  // General Purpose I/O
//#define GPIO_PIN1_AN1         GPIO_PIN_1  // Analog Input AN1 (for PIC12F675 only)
//#define GPIO_PIN1_CIN_MINUS   GPIO_PIN_1  // Comparator CIN- input
//#define GPIO_PIN1_VREF        GPIO_PIN_1  // Voltage Reference input (PIC12F675 only)
//#define GPIO_PIN1_ICSPCLK     GPIO_PIN_1  // ICSP Clock (programming)
#define GPIO_PIN1_SPI_MOSI      GPIO_PIN_1  // CNFIG PIN AS SPI 


// GP2 functions
//#define GPIO_PIN2_GPIO        GPIO_PIN_2  // General Purpose I/O
//#define GPIO_PIN2_AN2         GPIO_PIN_2  // Analog Input AN2 (for PIC12F675 only)
//#define GPIO_PIN2_T0CKI       GPIO_PIN_2  // Timer0 Clock Input
//#define GPIO_PIN2_INT         GPIO_PIN_2  // External Interrupt input
//#define GPIO_PIN2_COUT        GPIO_PIN_2  // Comparator Output
#define GPIO_PIN2_SPI_CLK       GPIO_PIN_2  // SOFTWARE SPI CLOCK PIN

// GP3 functions
#define GPIO_PIN3_GPIO          GPIO_PIN_3  // General Purpose I/O (input-only)
//#define GPIO_PIN3_MCLR        GPIO_PIN_3  // Master Clear (MCLR) / VPP (Programming voltage input)

// GP4 functions
#define GPIO_PIN4_GPIO        GPIO_PIN_4  // General Purpose I/O
//#define GPIO_PIN4_AN3           GPIO_PIN_4  // Analog Input AN3 (for PIC12F675 only)
//#define GPIO_PIN4_T1G         GPIO_PIN_4  // Timer1 Gate input
//#define GPIO_PIN4_OSC2        GPIO_PIN_4  // Oscillator Output (CLKOUT)

// GP5 functions
//#define GPIO_PIN5_GPIO        GPIO_PIN_5   // General Purpose I/O
//#define GPIO_PIN5_T1CKI       GPIO_PIN_5   // Timer1 Clock Input
//#define GPIO_PIN5_OSC1        GPIO_PIN_5   // Oscillator Input (CLKIN)
#define GPIO_PIN5_SPI_SS        GPIO_PIN_5   // SET PIN AS SPI SELECT PIN


// Configuration structure
typedef struct {
    uint8    pinNumber;        // Pin number (0 to 5)
    uint8    PinDirection;
    uint8    StateType;
    uint8    PullType;
} Gpio_ConfigType;

extern const Gpio_ConfigType Gpio_Configurations[GPIO_PIN_COUNT];



// Example configuration for the GPIO pins

// GP0 functions (Only one function must be chosen)
#if defined(GPIO_PIN0_GPIO) + defined(GPIO_PIN0_AN0) + defined(GPIO_PIN0_CIN_PLUS) + defined(GPIO_PIN0_ICSPDAT) != 1
    #error "For GP0, please define exactly one function (GPIO_PIN0_GPIO, GPIO_PIN0_AN0, GPIO_PIN0_CIN_PLUS, or GPIO_PIN0_ICSPDAT)."
#endif

// GP1 functions (Only one function must be chosen)
#if defined(GPIO_PIN1_GPIO) + defined(GPIO_PIN1_AN1) + defined(GPIO_PIN1_CIN_MINUS) + defined(GPIO_PIN1_VREF) + defined(GPIO_PIN1_ICSPCLK) + defined(GPIO_PIN1_SPI_MOSI) != 1
    #error "For GP1, please define exactly one function (GPIO_PIN1_GPIO, GPIO_PIN1_AN1, GPIO_PIN1_CIN_MINUS, GPIO_PIN1_VREF, or GPIO_PIN1_ICSPCLK)."
#endif

// GP2 functions (Only one function must be chosen)
#if defined(GPIO_PIN2_GPIO) + defined(GPIO_PIN2_AN2) + defined(GPIO_PIN2_T0CKI) + defined(GPIO_PIN2_INT) + defined(GPIO_PIN2_COUT) + defined(GPIO_PIN2_SPI_CLK) != 1
    #error "For GP2, please define exactly one function (GPIO_PIN2_GPIO, GPIO_PIN2_AN2, GPIO_PIN2_T0CKI, GPIO_PIN2_INT, or GPIO_PIN2_COUT)."
#endif

// GP3 functions (Only one function must be chosen)
#if defined(GPIO_PIN3_GPIO) + defined(GPIO_PIN3_MCLR) != 1
    #error "For GP3, please define exactly one function (GPIO_PIN3_GPIO or GPIO_PIN3_MCLR)."
#endif

// GP4 functions (Only one function must be chosen)
#if defined(GPIO_PIN4_GPIO) + defined(GPIO_PIN4_AN3) + defined(GPIO_PIN4_T1G) + defined(GPIO_PIN4_OSC2) != 1
    #error "For GP4, please define exactly one function (GPIO_PIN4_GPIO, GPIO_PIN4_AN3, GPIO_PIN4_T1G, or GPIO_PIN4_OSC2)."
#endif

// GP5 functions (Only one function must be chosen)
#if defined(GPIO_PIN5_GPIO) + defined(GPIO_PIN5_T1CKI) + defined(GPIO_PIN5_OSC1) + defined(GPIO_PIN5_SPI_SS) != 1
    #error "For GP5, please define exactly one function (GPIO_PIN5_GPIO, GPIO_PIN5_T1CKI, or GPIO_PIN5_OSC1)."
#endif

#endif /* GPIO_CFG_H */

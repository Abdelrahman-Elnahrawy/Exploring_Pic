/*_____________________________Gpio.C_____________________________________________________
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
#include <xc.h>
#include "../cfg/Gpio_Cfg.h"
#include "../include/Gpio_Types.h"
#include "../../UTILS/Std_Types.h"
#include "../include/gpio.h"

// Helper function to set pin direction and state


void Gpio_Init(void) {
    // GP0 configuration
    #ifdef GPIO_PIN0_GPIO
        ANSEL &= ~(1 << 0);  // Set GP0 as digital I/O
        TRISIO &= ~(1 << 0); // Set as output (adjust as needed)
 
    #elif defined(GPIO_PIN0_AN0)
        ANSEL |= (1 << 0);   // Set GP0 as analog input AN0
        TRISIO |= (1 << 0);  // Set as input
    #elif defined(GPIO_PIN0_CIN_PLUS)
        CMCON &= ~(1 << 0);  // Set GP0 as Comparator CIN+ input
    #elif defined(GPIO_PIN0_ICSPDAT)
        // No specific register for ICSPDAT, handled by ICSP programmer    
    #endif

    // GP1 configuration
    #ifdef GPIO_PIN1_GPIO
        ANSEL &= ~(1 << 1);  // Set GP1 as digital I/O
        TRISIO &= ~(1 << 1); // Set as output (adjust as needed)
    #elif defined(GPIO_PIN1_AN1)
        ANSEL |= (1 << 1);   // Set GP1 as analog input AN1
        TRISIO |= (1 << 1);  // Set as input
    #elif defined(GPIO_PIN1_CIN_MINUS)
        CMCON &= ~(1 << 1);  // Set GP1 as Comparator CIN- input
    #elif defined(GPIO_PIN1_VREF)
        VRCON |= (1 << 1);   // Set GP1 as Voltage Reference input
    #elif defined(GPIO_PIN1_ICSPCLK)
        // No specific register for ICSPCLK, handled by ICSP programmer
    #elif defined(GPIO_PIN1_SPI_MOSI)
        ANSEL &= ~(1 << 1);  // Set GP1 as digital I/O
        TRISIO &= ~(1 << 1); // Set as output (adjust as needed)
    #endif

    // GP2 configuration
    #ifdef GPIO_PIN2_GPIO
        ANSEL &= ~(1 << 2);  // Set GP2 as digital I/O
        TRISIO &= ~(1 << 2); // Set as output (adjust as needed)
    #elif defined(GPIO_PIN2_AN2)
        ANSEL |= (1 << 2);   // Set GP2 as analog input AN2
        TRISIO |= (1 << 2);  // Set as input
    #elif defined(GPIO_PIN2_T0CKI)
        OPTION_REG &= ~(1 << 5);  // Set GP2 as Timer0 clock input (T0CKI)
    #elif defined(GPIO_PIN2_INT)
        OPTION_REG &= ~(1 << 6);  // Enable external interrupt on GP2
    #elif defined(GPIO_PIN2_COUT)
        CMCON |= (1 << 6);   // Set GP2 as Comparator output (COUT)
    #elif defined(GPIO_PIN2_SPI_CLK)
        ANSEL &= ~(1 << 2);  // Set GP2 as digital I/O
        TRISIO &= ~(1 << 2); // Set as output (adjust as needed)
    #endif

    // GP3 configuration
    #ifdef GPIO_PIN3_GPIO
        TRISIO |= (1 << 3);  // GP3 is input-only, set as input
    #elif defined(GPIO_PIN3_MCLR)
        // Configure GP3 as MCLR, no special register
    #endif

    // GP4 configuration
    #ifdef GPIO_PIN4_GPIO
        ANSEL &= ~(1 << 3);  // Set GP4 as digital I/O
        TRISIO &= ~(1 << 4); // Set as output (adjust as needed)
    #elif defined(GPIO_PIN4_AN3)
        ANSEL |= (1 << 3);   // Set GP4 as analog input AN3
        TRISIO |= (1 << 4);  // Set as input
    #elif defined(GPIO_PIN4_T1G)
        T1CON |= (1 << 7);   // Set GP4 as Timer1 gate input
    #elif defined(GPIO_PIN4_OSC2)
        // Set GP4 as oscillator output (CLKOUT), no direct register needed
    #endif

    // GP5 configuration
    #ifdef GPIO_PIN5_GPIO
        TRISIO &= ~(1 << 5); // Set GP5 as output (adjust as needed)
    #elif defined(GPIO_PIN5_T1CKI)
        T1CON |= (1 << 1);   // Set GP5 as Timer1 clock input
    #elif defined(GPIO_PIN5_OSC1)
        // Set GP5 as oscillator input (CLKIN), no direct register needed  
    #elif defined(GPIO_PIN5_SPI_SS)
        TRISIO &= ~(1 << 5); // Set GP5 as output (adjust as needed)
    #endif
}



/*_____________________________GPIO_TYPES.H_____________________________________________________
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
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H


// Pin state macros
#define GPIO_PIN_LOW      0  // Logic Low
#define GPIO_PIN_HIGH     1  // Logic High

// Pin direction macros
#define GPIO_DIR_INPUT    0  // Input direction
#define GPIO_DIR_OUTPUT   1  // Output direction

// Pull-up type macros
#define GPIO_PULLUP_DISABLE          0  // No pull-up or pull-down
#define GPIO_PULLUP_ENABLE           1  // Enable pull-up resistor

// Pin number macros
#define GPIO_PIN_0        0  // Pin 0
#define GPIO_PIN_1        1  // Pin 1
#define GPIO_PIN_2        2  // Pin 2
#define GPIO_PIN_3        3  // Pin 3
#define GPIO_PIN_4        4  // Pin 4
#define GPIO_PIN_5        5  // Pin 5


#endif /* GPIO_TYPES_H */

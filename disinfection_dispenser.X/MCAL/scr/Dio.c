/*_____________________________{FILE_NAME}_____________________________________________________
                                      ___           ___           ___
 Author: Abdelrahman Selim           /\  \         /\  \         /\  \
                                    /::\  \       /::\  \       /::\  \
Created on: {DATE}                 /:/\:\  \     /:/\:\  \     /:/\:\  \
                                  /::\ \:\  \   _\:\ \:\  \   /::\ \:\  \
 Version: 01                     /:/\:\ \:\__\ /\ \:\ \:\__\ /:/\:\ \:\__\
                                 \/__\:\/:/  / \:\ \:\ \/__/ \/__\:\/:/  / 
                                      \::/  /   \:\ \:\__\        \::/  /
                                      /:/  /     \:\/:/  /        /:/  /
 Brief : {PROJECT_NAME}               /:/  /       \::/  /        /:/  /
                                     \/__/         \/__/         \/__/
 _________________________________________________________________________________________*/
#include "../include/Dio.h"
#include "../include/Dio_Types.h"
#include "../cfg/Dio_cfg.h"
static uint8 DIO_State ;
// Read the state of a DIO pin
uint8 Dio_Pin_Read(uint8 pinNumber) {
        if (GPIO & (1 << pinNumber)) {
            return DIO_PIN_HIGH;  // Return high state
        } else {
            return DIO_PIN_LOW;   // Return low state
        }
}

// Write a state (high or low) to a DIO pin

// Function to write a state to a pin
void Dio_Pin_Write (uint8 pinNumber, uint8 state){

    if (state == DIO_PIN_HIGH) {
        DIO_State |= (1 << pinNumber);  // Set pin high
    }
    else {
        DIO_State &= ~(1 << pinNumber); // Set pin low
    }
    GPIO = DIO_State ;
 }

 void Dio_Config (uint8 pinNumber, uint8 direction, uint8 state , uint8 pullType) {
    // Set the pin direction
    TRISIO = (unsigned char)((direction == DIO_DIR_INPUT) ? (TRISIO | (1U << pinNumber)) : (TRISIO & ~(1U << pinNumber)));
    // Set the pin state (only relevant if direction is output)
    if (direction == DIO_DIR_OUTPUT) {
        if (state == DIO_PIN_HIGH) {
            DIO_State |= (1 << pinNumber);  // Set pin high
        } else {
            DIO_State &= ~(1 << pinNumber); // Set pin low
        } 
        GPIO = DIO_State ;
    }     
    if (pullType == DIO_PULLUP_ENABLE) {
        OPTION_REG &= ~(1 << 7);  // Enable global pull-up 
        WPU |= (1 << pinNumber);  // Enable pull-up
    } else {
        WPU &= ~(1 << pinNumber); // Disable pull-up
    }    
}
void Dio_init(void){
    
   #ifdef DIO_CONFIG_PIN_0
       Dio_Config (DIO_CONFIG_PIN_0);
   #endif
  #ifdef DIO_CONFIG_PIN_1
       Dio_Config (DIO_CONFIG_PIN_1);
   #endif
  #ifdef DIO_CONFIG_PIN_2
       Dio_Config (DIO_CONFIG_PIN_2);
   #endif
  #ifdef DIO_CONFIG_PIN_3
       Dio_Config (DIO_CONFIG_PIN_3);
   #endif
  #ifdef DIO_CONFIG_PIN_4
       Dio_Config (DIO_CONFIG_PIN_4);
   #endif
  #ifdef DIO_CONFIG_PIN_5
       Dio_Config (DIO_CONFIG_PIN_5);
   #endif

       
       
}

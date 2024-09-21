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

#ifndef DIO_H
#define	DIO_H

#include <xc.h>
#include "../../UTILS/Std_Types.h"
#include "../include/Dio_Types.h"

// Read the state of a DIO pin (high or low)
 uint8 Dio_Pin_Read(uint8 pinNumber);

// Write a state (high or low) to a DIO pin
void   Dio_Pin_Write (uint8 pinNumber, uint8 state);
void Dio_init(void);
 void Dio_Config (uint8 pinNumber, uint8 direction, uint8 state , uint8 pullType);
#endif	/* DIO_H */


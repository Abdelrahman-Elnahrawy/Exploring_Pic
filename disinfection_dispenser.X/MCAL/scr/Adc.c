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

#include "../include/Adc.h"
#include "../cfg/Adc_Cfg.h"
#include "../include/Adc_Types.h"
#include "../../UTILS/Std_Types.h"
#include "../cfg/Gpio_Cfg.h"
#include "../cfg/efuse.h"
#include <xc.h>

/*
 ADCON0 ? A/D CONTROL REGISTER (ADDRESS: 1Fh)
 bit 7 ADFM: A/D Result Formed Select bit
 * 
1 = Right justified
0 = Left justified
 * 
bit 6 VCFG: Voltage Reference bit
1 = VREF pin
0 = VDD
 * 
bit 5-4 Unimplemented: Read as zero
bit 3-2 CHS1:CHS0: Analog Channel Select bits
 * 
00 = Channel 00 (AN0)
01 = Channel 01 (AN1)
10 = Channel 02 (AN2)
11 = Channel 03 (AN3)
 * 
bit 1 GO/DONE: A/D Conversion Status bit
1 = A/D conversion cycle in progress. Setting this bit starts an A/D conversion cycle.
This bit is automatically cleared by hardware when the A/D conversion has completed.
0 = A/D conversion completed/not in progress
 * 
bit 0 ADON: A/D Conversion STATUS bit
1 = A/D converter module is operating
0 = A/D converter is shut-off and consumes no operating current
 */


void Adc_Init(void) {
ADCON0 |=  (1 << 0);   // TURNING ON THE PREPHIREAL

#ifdef VREF_VOLTAGE_REFRENCE
    SET_VOLTAGE_REFRENCE(VCFG_VREF);
#else
    SET_VOLTAGE_REFRENCE(VCFG_VDD);
#endif
    
    SET_ADC_CONVERSION_SPEED_FASTEST(_XTAL_FREQ); 
    #if defined(GPIO_PIN0_AN0) ^ defined(ADC_PIN0_AN0)
        #error the pin ADC_PIN0_AN0 is not configured in both the adc configurations and the gpio configurations
    #endif

    #if defined(GPIO_PIN1_AN1) ^ defined(ADC_PIN1_AN1)
        #error the pin ADC_PIN1_AN1 is not configured in both the adc configurations and the gpio configurations
    #endif

    #if defined(GPIO_PIN2_AN2) ^ defined(ADC_PIN2_AN2)
        #error the pin ADC_PIN2_AN2 is not configured in both the adc configurations and the gpio configurations
    #endif

    #if defined(GPIO_PIN4_AN3) ^ defined(ADC_PIN4_AN3)
        #error the pin is not configured in both the adc configurations and the gpio configurations
    #endif

    #ifdef  ADC_FORMAT_LOW   
        ADCON0 |=  (1 << 7);  // ADFM = 1, right-justified result
    #else
        ADCON0 &= ~(1 << 7); // ADFM = 0, left-justified result
    #endif
}


void Adc_StartConversion(Adc_ChannelType channel) {
    
    // Select ADC channel
    ADCON0 &= ~( 0b11 <<  2);  // Clear the channel selection bits
    ADCON0 |= (channel << 2);  // Set the channel
    ADCON0 |= (1 << 1);  // Set GO/DONE bit to start conversion
}


uint16 Adc_ReadResult(void) {
    while (ADCON0 & (1 << 1));  // Wait for the conversion to complete (GO/DONE bit cleared)

    // Check if the result is right or left justified (based on ADFM)
    if (ADCON0 & (1 << 7)) {
        // Right-justified result (ADFM = 1)
        return (uint16)((ADRESH << 8) | ADRESL);        // Combine ADRESH and ADRESL for 10-bit result
    } else {
        // Left-justified result (ADFM = 0)
        return (uint16)((ADRESH << 2) | (ADRESL >> 6));  // Adjust the result for left-justified 10-bit result
    }
}

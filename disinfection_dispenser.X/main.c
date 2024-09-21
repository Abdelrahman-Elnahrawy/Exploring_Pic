/*_____________________________ Main.c _____________________________________________________
                                      ___           ___           ___
 Author: Abdelrahman Selim           /\  \         /\  \         /\  \
                                    /::\  \       /::\  \       /::\  \
Created on:16 sep 2024             /:/\:\  \     /:/\:\  \     /:/\:\  \
                                  /::\ \:\  \   _\:\ \:\  \   /::\ \:\  \
 Version: 01                     /:/\:\ \:\__\ /\ \:\ \:\__\ /:/\:\ \:\__\
                                 \/__\:\/:/  / \:\ \:\ \/__/ \/__\:\/:/  / 
                                      \::/  /   \:\ \:\__\        \::/  /
                                      /:/  /     \:\/:/  /        /:/  /
 Brief : Exploring Pic               /:/  /       \::/  /        /:/  /
                                     \/__/         \/__/         \/__/
 _________________________________________________________________________________________*/

#include "MCAL/cfg/efuse.h"
#include <xc.h>
#include "MCAL/include/gpio.h"
#include "MCAL/include/Adc.h"
#include "UTILS/Std_Types.h"
#include "MCAL/include/Dio.h"
#include "SERVICE/include/Spi.h"
#include "HAL/include/max7219.h"
//Other Includes

//#define CODE_1

#define CODE_2

uint8 DispenserOn ;
uint16 Counter ;
int main (void){
    
        Gpio_Init();
        Dio_init();
        Adc_Init();
        SPI_Init();
      MAX7219_Init();
   IOCB |= (1 << 3);  // Enable interrupt-on-change for GP3
    // Enable Global and Peripheral Interrupts
    INTCONbits.GIE  = 1;  // Global Interrupt Enable
    INTCONbits.PEIE = 1; // Peripheral Interrupt Enable
    INTCONbits.GPIE = 1; // GPIO Interrupt-on-change Enable
    while (1){


        while(DispenserOn){
            Adc_StartConversion(ADC_CHANNEL_AN0);           //get the set value of timer
            
            MAX7219_DISPLAY_ON();                           //Set On sign on the display
            
            
            for(uint8 i=0; (i<100)&&DispenserOn;i++ )     // wait for 2 seconds while make sure the client didnt close the machine
                {__delay_ms(10);}
            
            MAX7219_ClearDisplay();
            
            
            Dio_Pin_Write (DIO_PIN_4,HIGH);                 // Start the motor
#ifdef CODE_1
            Counter  = 10*(1 + (10*Adc_ReadResult()/114));      // read the supposed value for the counter the 10/114 is the same as 89/1024 but made this way to reduce the ammount of memory usage
           
#endif
       
#ifdef CODE_2
            Counter  = 10*(5 + (2*Adc_ReadResult()/1020));      // read the supposed value for the counter
#endif
            for(;(Counter>0)&&DispenserOn;Counter--){       //start counting while making sure the client didnt close the machine
                MAX7219_DisplayData(MAX7219_REG_DIGIT3, MAX7219_No_Table[Counter/6000]);      // as its not float will always approximate the result to the lowest .. divided by 60 for getting the minutes ten 10 to get the thenths of minutes
                MAX7219_DisplayData(MAX7219_REG_DIGIT2, MAX7219_No_Table[(Counter/600)%10]);  //
                MAX7219_DisplayData(MAX7219_REG_DIGIT1, MAX7219_No_Table[((Counter/10)%60)/10]);
                MAX7219_DisplayData(MAX7219_REG_DIGIT0, MAX7219_No_Table[((Counter/10)%60)%10]);
                __delay_ms(98);
            }
            Dio_Pin_Write (DIO_PIN_4, LOW);
            DispenserOn=0;
            MAX7219_DISPLAY_OFF();  
        }
    }   

}

void __interrupt() ISR() {
    // Check if the interrupt-on-change has occurred
    if (INTCONbits.GPIF) {
        // Check if GP3 state has changed (Interrupt-on-change detected)
        uint16 i = 0 ;
              while(!Dio_Pin_Read(DIO_PIN_3)){
                  i++;
                  __delay_us((100));
                  if(i>3000){
                      DispenserOn = !DispenserOn;
                      break;}
             }

        // Clear the interrupt-on-change flag
        INTCONbits.GPIF = 0;
    }
}


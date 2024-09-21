#include "../include/max7219.h"
#include "../../SERVICE/include/Spi.h"
#include "../../UTILS/Std_Types.h"
// Character encoding for the 7-segment display (Hexadecimal values)
static uint8 BCD_Enabled ;

// Initialize MAX7219
void MAX7219_Init(void) {
    SPI_Send_16bit(0x0900);  // No decode mode for all digits
    SPI_Send_16bit(0x0A0F);  // Maximum intensity
    SPI_Send_16bit(0xFBF7);  // Display all digits (0-7)
    SPI_Send_16bit(0x0C01);  // Exit shutdown mode
    SPI_Send_16bit(0x0F00);  // Disable test mode
   
}


// Clear the display
void MAX7219_ClearDisplay(void) {
    for (uint8_t i = MAX7219_REG_DIGIT0; i <= MAX7219_REG_DIGIT7; i++) {
        SPI_Send_16bit((i << 8) );  // Clear each digit
    }
}

// Display a character on a specific digit
void MAX7219_DisplayData(uint8 digit, uint8 character) {
    SPI_Send_16bit((digit) << 8 | character);
}
#ifdef DISPLAY_NUMBER_FUNCTION
// Display a number on the 7-segment display (up to 8 digits)
void MAX7219_DisplayNumber(uint32_t number) {
        for (uint8_t i = 0; i < 8; i++) {
            MAX7219_DisplayData(MAX7219_REG_DIGIT0+i, MAX7219_No_Table[number % 10]);  // Display each digit
            number /= 10;                                             // Move to the next digit
        }
        
    }
#endif
// Display a string (up to 8 characters)

// Control shutdown mode (1 = normal, 0 = shutdown)
void MAX7219_Shutdown(uint8_t state) {
    SPI_Send_16bit((MAX7219_REG_SHUTDOWN << 8) | (state ? 0x01 : 0x00));
}




      
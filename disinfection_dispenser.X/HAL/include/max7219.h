#ifndef MAX7219_HEADER
#define MAX7219_HEADER

#include <xc.h>
#include <stdint.h>
#include "../../UTILS/Std_Types.h"
// MAX7219 Register Addresses


#define DISPLAY_NUMBER_FUNCTION

#define MAX7219_REG_DIGIT0      0x01
#define MAX7219_REG_DIGIT1      0x02
#define MAX7219_REG_DIGIT2      0x03
#define MAX7219_REG_DIGIT3      0x04
#define MAX7219_REG_DIGIT4      0x05
#define MAX7219_REG_DIGIT5      0x06
#define MAX7219_REG_DIGIT6      0x07
#define MAX7219_REG_DIGIT7      0x08


#define MAX7219_REG_NOOP        0x00
#define MAX7219_REG_DECODE      0x09
#define MAX7219_REG_INTENSITY   0x0A
#define MAX7219_REG_SCANLIMIT   0x0B
#define MAX7219_REG_SHUTDOWN    0x0C
#define MAX7219_REG_DISPLAYTEST 0x0F

#define MAX7219_0 0x7E
#define MAX7219_1 0x30
#define MAX7219_2 0x6D
#define MAX7219_3 0x79
#define MAX7219_4 0x33
#define MAX7219_5 0x5B
#define MAX7219_6 0x5F
#define MAX7219_7 0x70
#define MAX7219_8 0x7F
#define MAX7219_9 0x7B

#define MAX7219_A 0x77
#define MAX7219_B 0x1F
#define MAX7219_C 0x4E
#define MAX7219_D 0x3D
#define MAX7219_E 0x4F
#define MAX7219_F 0x47

#define MAX7219_H 0x37
#define MAX7219_J 0x1E
#define MAX7219_L 0x0E
#define MAX7219_N 0x15
#define MAX7219_O 0x1D
#define MAX7219_P 0x67
#define MAX7219_U 0x3E



// Function Prototypes
void MAX7219_Init(void);
void MAX7219_ClearDisplay(void);
void MAX7219_DisplayData(uint8 digit, uint8 character);
#ifdef DISPLAY_NUMBER_FUNCTION
void MAX7219_DisplayNumber(uint32_t number);
#endif
void MAX7219_Shutdown(uint8_t state);


const uint8 MAX7219_No_Table[] = {
        MAX7219_0, MAX7219_1, MAX7219_2, MAX7219_3, MAX7219_4, MAX7219_5, MAX7219_6, MAX7219_7,
        MAX7219_8, MAX7219_9
    };



   #define MAX7219_DISPLAY_HELLO()\
        MAX7219_ClearDisplay();\
        MAX7219_DisplayData(MAX7219_REG_DIGIT6,MAX7219_H);\
        MAX7219_DisplayData(MAX7219_REG_DIGIT5,MAX7219_E);\
        MAX7219_DisplayData(MAX7219_REG_DIGIT4,MAX7219_L);\
        MAX7219_DisplayData(MAX7219_REG_DIGIT3,MAX7219_O);
 
    
   #define MAX7219_DISPLAY_OFF()\
        MAX7219_ClearDisplay();\
        MAX7219_DisplayData(MAX7219_REG_DIGIT4,MAX7219_O);\
        MAX7219_DisplayData(MAX7219_REG_DIGIT3,MAX7219_F);\
        MAX7219_DisplayData(MAX7219_REG_DIGIT2,MAX7219_F);

   #define MAX7219_DISPLAY_ON()\
        MAX7219_ClearDisplay();\
        MAX7219_DisplayData(MAX7219_REG_DIGIT3,MAX7219_O);\
        MAX7219_DisplayData(MAX7219_REG_DIGIT2,MAX7219_N);\



#endif /* MAX7219_HEADER */

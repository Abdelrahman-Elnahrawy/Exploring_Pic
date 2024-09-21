


#ifndef SPI_cfg_H
#define SPI_cfg_H

    #include <xc.h>
    #include "../../MCAL/cfg/Gpio_Cfg.h"
    #include "../../MCAL/include/Gpio_Types.h"

    #include "../../MCAL/cfg/efuse.h"


    /*
     this is a software spi module made using bit banging technique
     * the SPI module is a software based so it is on the MCAL Layer depends on the 
     * gpio and dio mainly .. furture updates it may depend on timers and interrupts
     * TILL NOW IT WORKS AS SIMPLEX ONLY MASTER OUT SLAVE IN  
     * only transmitting data no reciving till now 
     * the pin used are as follows
     * PIN1  MOSI
     * PIN2  CLK
     * PIN5  SS (CS)
     */
    #define SPI_CONFIG 


// enable only the function u will use 
//#define SPI_SEND_8BIT
  #define SPI_SEND_16BIT
//#define SPI_SEND_24BIT
//#define SPI_SEND_32BIT
//#define SPI_SEND_64BIT


    #define SPI_MOSI    GPIO_PIN1_SPI_MOSI
    #define SPI_MISO    
    #define SPI_CLK     GPIO_PIN2_SPI_CLK
    #define SPI_CS      GPIO_PIN5_SPI_SS


    #define SPI_DELAY __delay_us(50);

    // SPI modes (for clock polarity and phase)
    #define SPI_MODE_0  0  // Clock Polarity 0, Clock Phase 0
    //#define SPI_MODE_1  1  // Clock Polarity 0, Clock Phase 1
    //#define SPI_MODE_2  2  // Clock Polarity 1, Clock Phase 0
    //#define SPI_MODE_3  3  // Clock Polarity 1, Clock Phase 1






    #ifdef SPI_MODE_0
        #define SPI_MOSI_SET    Dio_Pin_Write(SPI_MOSI, HIGH)
        #define SPI_MOSI_RESET  Dio_Pin_Write(SPI_MOSI, LOW)

        #define SPI_SC_SET      Dio_Pin_Write(SPI_CS, HIGH)
        #define SPI_SC_RESET    Dio_Pin_Write(SPI_CS, LOW)

        // Clock pulse: Data is sampled on rising edge
        #define SPI_CLK_PULSE   \
            SPI_DELAY; /* Adjust delay as needed */\
            Dio_Pin_Write(SPI_CLK, HIGH); /* Pulse the clock */ \
            SPI_DELAY; /* Adjust delay as needed */ \
            Dio_Pin_Write(SPI_CLK, LOW); 

    #endif

    // Configuration for SPI Mode 1 (CPOL = 0, CPHA = 1)
    #ifdef SPI_MODE_1
        #define SPI_MOSI_SET    Dio_Pin_Write(SPI_MOSI, HIGH)
        #define SPI_MOSI_RESET  Dio_Pin_Write(SPI_MOSI, LOW)

        #define SPI_SC_SET      Dio_Pin_Write(SPI_SCK, HIGH)
        #define SPI_SC_RESET    Dio_Pin_Write(SPI_SCK, LOW)

        // Clock pulse: Data is sampled on falling edge
        #define SPI_CLK_PULSE   \
            Dio_Pin_Write(SPI_SCK, LOW); /* Start with clock low */ \
            SPI_DELAY; /* Adjust delay as needed */ \
            Dio_Pin_Write(SPI_SCK, HIGH); /* Pulse the clock */ \
            Dio_Pin_Write(SPI_SCK, LOW); \
            SPI_DELAY; /* Adjust delay as needed */
    #endif

    // Configuration for SPI Mode 2 (CPOL = 1, CPHA = 0)
    #ifdef SPI_MODE_2
        #define SPI_MOSI_SET    Dio_Pin_Write(SPI_MOSI, HIGH)
        #define SPI_MOSI_RESET  Dio_Pin_Write(SPI_MOSI, LOW)

        #define SPI_SC_SET      Dio_Pin_Write(SPI_SCK, HIGH)
        #define SPI_SC_RESET    Dio_Pin_Write(SPI_SCK, LOW)

        // Clock pulse: Data is sampled on rising edge, clock starts high
        #define SPI_CLK_PULSE   \
            Dio_Pin_Write(SPI_SCK, HIGH); /* Start with clock high */ \
            Dio_Pin_Write(SPI_SCK, LOW);  /* Pulse the clock */ \
            SPI_DELAY; /* Adjust delay as needed */ \
            Dio_Pin_Write(SPI_SCK, HIGH); \
            SPI_DELAY; /* Adjust delay as needed */
    #endif

    // Configuration for SPI Mode 3 (CPOL = 1, CPHA = 1)
    #ifdef SPI_MODE_3
        #define SPI_MOSI_SET    Dio_Pin_Write(SPI_MOSI, HIGH)
        #define SPI_MOSI_RESET  Dio_Pin_Write(SPI_MOSI, LOW)

        #define SPI_SC_SET      Dio_Pin_Write(SPI_SCK, HIGH)
        #define SPI_SC_RESET    Dio_Pin_Write(SPI_SCK, LOW)

        // Clock pulse: Data is sampled on falling edge, clock starts high
        #define SPI_CLK_PULSE   \
            Dio_Pin_Write(SPI_SCK, HIGH); /* Start with clock high */ \
            SPI_DELAY; /* Adjust delay as needed */ \
            Dio_Pin_Write(SPI_SCK, LOW);  /* Pulse the clock */ \
            Dio_Pin_Write(SPI_SCK, HIGH); \
            SPI_DELAY; /* Adjust delay as needed */
    #endif



    // Preprocessor checks to ensure only one mode is selected
    #if (defined(SPI_MODE_0) + defined(SPI_MODE_1) + defined(SPI_MODE_2) + defined(SPI_MODE_3)) != 1
        #error "Please define exactly one SPI mode (SPI_MODE_0, SPI_MODE_1, SPI_MODE_2, or SPI_MODE_3)."
    #endif

#ifdef SPI_CONFIG

    #if (defined(GPIO_PIN1_SPI_MOSI) + defined(GPIO_PIN2_SPI_CLK) + defined(GPIO_PIN5_SPI_SS)) != 3
        #error "Please define at least the MOSI PIN (AT GPIO 1), THE CLK PIN (GPIO 2), AND THE SS PIN (AT GPIO 5)"
    #endif

#else

    #if (defined(GPIO_PIN1_SPI_MOSI) + defined(GPIO_PIN2_SPI_CLK) + defined(GPIO_PIN5_SPI_SS)) != 0
        #error "Pins are set in SPI mode while SPI configuration macro is not enabled ---> go to SPI config header"
    #endif

#endif

#endif /* SPI_cfg_H */
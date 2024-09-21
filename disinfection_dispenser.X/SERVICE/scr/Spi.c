



#include <xc.h>
#include "../include/Spi.h"
#include "../../MCAL/cfg/efuse.h"
#include "../../MCAL/include/Dio.h"
#include "../cfg/Spi_Cfg.h"
#include "../../UTILS/Std_Types.h"
// Initialize the SPI
void SPI_Init(void) {
 Dio_Config (DIO_PIN_1, DIO_DIR_OUTPUT, HIGH , DIO_PULLUP_DISABLE);
 Dio_Config (DIO_PIN_2, DIO_DIR_OUTPUT, LOW , DIO_PULLUP_DISABLE);
 Dio_Config (DIO_PIN_5, DIO_DIR_OUTPUT, HIGH , DIO_PULLUP_DISABLE);

}

#ifdef SPI_SEND_8BIT
void SPI_Send_8bit(uint8 data) {
    SPI_SC_RESET;
    for (int bit =0 ; bit <8 ; bit ++ ) {
        // Write each bit to MOSI
        if (data & (1 << (7 - bit))) {
            SPI_MOSI_SET;
        } else {
           SPI_MOSI_RESET ;
        }
        
  SPI_CLK_PULSE;
    }
    SPI_SC_SET;  // Deselect the slave
}
#endif
#ifdef SPI_SEND_16BIT



void SPI_Send_16bit(uint16 data) {
    SPI_SC_RESET;
    for (int bit =0 ; bit <16 ; bit ++ ) {
        // Write each bit to MOSI
        if (data & (1 << (15 - bit))) {
            SPI_MOSI_SET;
        } else {
           SPI_MOSI_RESET ;
        }
        
  SPI_CLK_PULSE;
    }
    SPI_SC_SET;  // Deselect the slave
}
#endif
#ifdef SPI_SEND_24BIT
void SPI_Send_24bit(uint32 data) {
    SPI_SC_RESET;
    for (int bit =0 ; bit <24 ; bit ++ ) {
        // Write each bit to MOSI
        if (data & (1 << (23 - bit))) {
            SPI_MOSI_SET;
        } else {
           SPI_MOSI_RESET ;
        }
        
  SPI_CLK_PULSE;
    }
    SPI_SC_SET;  // Deselect the slave
}
#endif
#ifdef SPI_SEND_32BIT
void SPI_Send_32bit(uint32 data) {
    SPI_SC_RESET;
    for (int bit =0 ; bit <32 ; bit ++ ) {
        // Write each bit to MOSI
        if (data & (1 << (31 - bit))) {
            SPI_MOSI_SET;
        } else {
           SPI_MOSI_RESET ;
        }
        
  SPI_CLK_PULSE;
    }
    SPI_SC_SET;  // Deselect the slave
}
#endif
#ifdef SPI_SEND_64BIT

void SPI_Send_64bit(uint64 data) {
    SPI_SC_RESET;
    for (int bit =0 ; bit <64 ; bit ++ ) {
        // Write each bit to MOSI
        if (data & (1 << (63 - bit))) {
            SPI_MOSI_SET;
        } else {
           SPI_MOSI_RESET ;
        }
        
  SPI_CLK_PULSE;
    }
    SPI_SC_SET;  // Deselect the slave
}
#endif
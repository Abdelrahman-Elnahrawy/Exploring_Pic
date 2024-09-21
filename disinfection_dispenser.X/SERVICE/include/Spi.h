#ifndef SPI_H
#define SPI_H

#include <xc.h>
#include "../cfg/Spi_Cfg.h"
#include "../../UTILS/Std_Types.h"
// Initialize the SPI (bit-banging)
void SPI_Init(void);


#ifdef SPI_SEND_8BIT
void SPI_Send_8bit(uint8 data);
#endif

#ifdef SPI_SEND_16BIT
void SPI_Send_16bit(uint16 data);
#endif

#ifdef SPI_SEND_24BIT
void SPI_Send_24bit(uint32 data);
#endif

#ifdef SPI_SEND_32BIT
void SPI_Send_32bit(uint32 data);
#endif

#ifdef SPI_SEND_64BIT
void SPI_Send_64bit(uint64 data);
#endif





#endif /* SPI_H */

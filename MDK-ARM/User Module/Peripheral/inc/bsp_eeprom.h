#ifndef BSP_EEPROM_H
#define BSP_EEPROM_H

#include "i2c.h"


#define ADDR_24LCxx_Write 0xA0
#define ADDR_24LCxx_Read 0xA1
#define BufferSize 256

static void EEPROM_WriteOnePage(uint16_t MemAddress, uint8_t *pData, uint16_t Size);
void EEPROM_WriteBuffer(uint16_t MemAddress, uint8_t *pData, uint16_t Size);
void EEPROM_Read(uint16_t MemAddress, uint8_t *pData, uint16_t Size);

void EEPROM_Test(void);





#endif

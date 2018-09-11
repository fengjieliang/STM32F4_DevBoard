#include "bsp_eeprom.h"
#include "string.h"
extern I2C_HandleTypeDef hi2c1;

static void EEPROM_WriteOnePage(uint16_t MemAddress, uint8_t *pData, uint16_t Size)
{
	uint32_t err_code;
	if(Size>8)
	{
		printf("the page size of 24c02 is 8 Bytes, can't write more than 8 Bytes at one time!");
		return;
	}
	else
	{
		err_code=HAL_I2C_Mem_Write(&hi2c1,ADDR_24LCxx_Write,MemAddress,I2C_MEMADD_SIZE_8BIT,pData,Size,50);
		if(err_code!=HAL_OK)
			printf("EEPROM_Write error!\r\n");
		HAL_Delay(10);
	}
}




void EEPROM_WriteBuffer(uint16_t MemAddress, uint8_t *pData, uint16_t Size)
{

	if(Size<=8)
	{EEPROM_WriteOnePage(MemAddress,pData,Size);}
	else
	{
		for(int cycles=0;cycles<Size/8;cycles++)
		{
			EEPROM_WriteOnePage(MemAddress,pData,8);
			MemAddress+=8;
			pData+=8;
		}
		if(Size%8!=0)
		{EEPROM_WriteOnePage(MemAddress,pData,Size%8);}
		
		
	}

}


void EEPROM_Read(uint16_t MemAddress, uint8_t *pData, uint16_t Size)
{
	uint32_t err_code;
	err_code=HAL_I2C_Mem_Read(&hi2c1,ADDR_24LCxx_Read,MemAddress,I2C_MEMADD_SIZE_8BIT,pData,Size,50);
	
	if(err_code!=HAL_OK)
	{printf("EEPROM_read error!\r\n");}
}





void EEPROM_Test(void)
{
	uint8_t WriteBuffer[BufferSize];
	uint8_t ReadBuffer[BufferSize];
	
	memset(WriteBuffer,0,BufferSize);
	memset(ReadBuffer,0,BufferSize);
	
	for(int i=0;i<BufferSize;i++)
	{WriteBuffer[i]=i;}
	
	EEPROM_WriteBuffer(0,WriteBuffer,sizeof(WriteBuffer));
	EEPROM_Read(0,ReadBuffer,BufferSize);
	

	if(0==memcmp(WriteBuffer,ReadBuffer,BufferSize))
	{printf("if you see this, EEPROM test passed\r\n");}
	

}




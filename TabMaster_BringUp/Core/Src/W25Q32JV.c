/*
 * W25Q32JV.c
 *
 *  Created on: Feb 4, 2024
 *      Author: parke
 */

#include "main.h"


void write_enable(QSPI_HandleTypeDef *hqspi){

	QSPI_CommandTypeDef WE = {0};

	  WE.Instruction = 0x06;        								/* Specifies the Instruction to be sent
	                                  	  	  	  	  	  	  	  	  This parameter can be a value (8-bit) between 0x00 and 0xFF */
	  WE.Address = 0;            									/* Specifies the Address to be sent (Size from 1 to 4 bytes according AddressSize)
	                                  	  	  	  	  	  	  	  	  This parameter can be a value (32-bits) between 0x0 and 0xFFFFFFFF */
	  WE.AlternateBytes = 0x0;    									 /* Specifies the Alternate Bytes to be sent (Size from 1 to 4 bytes according AlternateBytesSize)
	                                  	  	  	  	  	  	  	  	  This parameter can be a value (32-bits) between 0x0 and 0xFFFFFFFF */
	  WE.AddressSize = QSPI_ADDRESS_24_BITS;       					 /* Specifies the Address Size
	                                  	  	  	  	  	  	  	  	  This parameter can be a value of @ref QSPI_AddressSize */
	  WE.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS; 			/* Specifies the Alternate Bytes Size
	                                  	  	  	  	  	  	  	  	  This parameter can be a value of @ref QSPI_AlternateBytesSize */
	  WE.DummyCycles = 0;        									/* Specifies the Number of Dummy Cycles.
	                                  	  	  	  	  	  	  	  	  This parameter can be a number between 0 and 31 */
	  WE.InstructionMode = QSPI_INSTRUCTION_1_LINE;    			/* Specifies the Instruction Mode
	                                  	  	  	  	  	  	  	  	  This parameter can be a value of @ref QSPI_InstructionMode */
	  WE.AddressMode = QSPI_ADDRESS_NONE;       					 /* Specifies the Address Mode
	                                  	  	  	  	  	  	  	  	  This parameter can be a value of @ref QSPI_AddressMode */
	  WE.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;  			/* Specifies the Alternate Bytes Mode
	                                  	  	  	  	  	  	  	  	  This parameter can be a value of @ref QSPI_AlternateBytesMode */
	  WE.DataMode = QSPI_DATA_NONE;          						 /* Specifies the Data Mode (used for dummy cycles and data phases)
	                                  	  	  	  	  	  	  	  	  This parameter can be a value of @ref QSPI_DataMode */
	  WE.NbData = 0;             										/* Specifies the number of data to transfer. (This is the number of bytes)
	                                  	  	  	  	  	  	  	  	  This parameter can be any value between 0 and 0xFFFFFFFF (0 means undefined length
	                                  	  	  	  	  	  	  	  	  until end of memory)*/
	  WE.DdrMode = QSPI_DDR_MODE_DISABLE;            				/* Specifies the double data rate mode for address, alternate byte and data phase
	                                  	  	  	  	  	  	  	  	  This parameter can be a value of @ref QSPI_DdrMode */
	  WE.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;   			/* Specifies if the DDR hold is enabled. When enabled it delays the data
	                                  	  	  	  	  	  	  	  	  output by one half of system clock in DDR mode.
	                                  	  	  	  	  	  	  	  	  This parameter can be a value of @ref QSPI_DdrHoldHalfCycle */
	  WE.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

	  uint8_t buffer[10] = {0};

	HAL_QSPI_Command(hqspi, &WE, 100);
	HAL_QSPI_Receive(hqspi, buffer, 100);


};

void page_program(QSPI_HandleTypeDef *hqspi, uint8_t *buffer, uint32_t start_addr, uint32_t data_len){

	QSPI_CommandTypeDef PP = {0};

	PP.Instruction = 0x02;
	PP.Address = start_addr;
	PP.AlternateBytes = 0;
	PP.AddressSize = QSPI_ADDRESS_24_BITS;
	PP.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
	PP.DummyCycles = 0;
	PP.InstructionMode = QSPI_INSTRUCTION_1_LINE;
	PP.AddressMode = QSPI_ADDRESS_1_LINE;
	PP.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
	PP.DataMode = QSPI_DATA_1_LINE;
	PP.NbData = data_len;
	PP.DdrMode = QSPI_DDR_MODE_DISABLE;
	PP.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
	PP.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

	HAL_QSPI_Command(hqspi, &PP, 100);
	HAL_QSPI_Transmit(hqspi, buffer, 100);
};

void fast_read(QSPI_HandleTypeDef *hqspi, uint8_t *buffer, uint32_t start_addr, uint32_t data_len){

	QSPI_CommandTypeDef FR = {0};

	FR.Instruction = 0x0B;
	FR.Address = start_addr;
	FR.AlternateBytes = 0;
	FR.AddressSize = QSPI_ADDRESS_24_BITS;
	FR.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
	FR.DummyCycles = 0;
	FR.InstructionMode = QSPI_INSTRUCTION_1_LINE;
	FR.AddressMode = QSPI_ADDRESS_1_LINE;
	FR.AlternateByteMode = QSPI_ALTERNATE_BYTES_1_LINE;
	FR.DataMode = QSPI_DATA_1_LINE;
	FR.NbData = data_len;
	FR.DdrMode = QSPI_DDR_MODE_DISABLE;
	FR.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
	FR.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

	HAL_QSPI_Command(hqspi, &FR, 100);
	HAL_QSPI_Receive(hqspi, buffer, 100);

};

void device_ID(QSPI_HandleTypeDef *hqspi, uint8_t *buffer){

	QSPI_CommandTypeDef ID = {0};

	ID.Instruction = 0x90;
	ID.Address = 0;
	ID.AlternateBytes = 0;
	ID.AddressSize = QSPI_ADDRESS_24_BITS;
	ID.AlternateBytesSize = QSPI_ALTERNATE_BYTES_24_BITS;
	ID.DummyCycles = 0;
	ID.InstructionMode = QSPI_INSTRUCTION_1_LINE;
	ID.AddressMode = QSPI_ADDRESS_NONE;
	ID.AlternateByteMode = QSPI_ALTERNATE_BYTES_1_LINE;
	ID.DataMode = QSPI_DATA_1_LINE;
	ID.NbData = 2;
	ID.DdrMode = QSPI_DDR_MODE_DISABLE;
	ID.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
	ID.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

	HAL_QSPI_Command(hqspi, &ID, 100);
	HAL_QSPI_Receive(hqspi, buffer, 100);



};




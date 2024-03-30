/*
 * GT911.h
 *
 *  Created on: Mar 28, 2024
 *      Author: parke
 */

#ifndef INC_GT911_H_
#define INC_GT911_H_

typedef enum{
	GT911_OK = 0,
	GT911_ERROR = 1,
	GT911_NotResponse = 2
}GT911_Status;

#define GT911_ADRESS 0x5D


void GT911_INIT(void);
void Set_GT911_INT_Output(void);
void Set_GT911_INT_Input(void);
GT911_Status GT911_I2C_Write(uint16_t address, uint8_t* buff, uint16_t data_len);
GT911_Status GT911_I2C_Read(uint16_t address, uint8_t* buff, uint32_t data_len);
void GT911_RESET(void);



#endif /* INC_GT911_H_ */




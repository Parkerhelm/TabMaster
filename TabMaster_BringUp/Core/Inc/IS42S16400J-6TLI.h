/*
 * IS42S16400J-6TLI.h
 *
 *  Created on: Feb 6, 2024
 *      Author: parke
 */

#ifndef SRC_IS42S16400J_6TLI_H_
#define SRC_IS42S16400J_6TLI_H_

#define SDRAM_Start 0xC0000000
#define SDRAM_Len 0x800000

void FMC_Init(SDRAM_HandleTypeDef* hsdram1);

#endif /* SRC_IS42S16400J_6TLI_H_ */

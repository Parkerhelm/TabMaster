/*
 * updateframebuff.c
 *
 *  Created on: Mar 25, 2024
 *      Author: parke
 */

#include "IS42S16400J-6TLI.h"
#include "updateframebuff.h"

void init_frame_buff(void){

	uint16_t* i;

	i = (uint16_t*)(SDRAM_Start);

	for( ; i < (uint16_t*)(PIXELCNT*2 + SDRAM_Start); i++){
		*i = 0xffff;

	};

}

void update_frame_buff(uint16_t color){

	uint16_t* i;

	i = (uint16_t*)SDRAM_Start;

	for( ;  i < (uint16_t*)(PIXELCNT*2 + SDRAM_Start); i++){
		*i = color;
	};
}

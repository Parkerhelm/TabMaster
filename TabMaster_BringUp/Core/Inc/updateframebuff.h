/*
 * updateframebuff.h
 *
 *  Created on: Mar 25, 2024
 *      Author: parke
 */

#ifndef INC_UPDATEFRAMEBUFF_H_
#define INC_UPDATEFRAMEBUFF_H_

#include "main.h"

#define PIXELCNT 384000

#define red 0xF800
#define green 0x07E0
#define blue 0x001F
#define cyan 0x07ff
#define majenta 0x690c
#define	orange 0xebc1

void update_frame_buff(uint16_t color);
void init_frame_buff(void);


#endif /* INC_UPDATEFRAMEBUFF_H_ */

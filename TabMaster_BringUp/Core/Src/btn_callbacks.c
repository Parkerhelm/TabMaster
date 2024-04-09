/*
 * btn_callbacks.c
 *
 *  Created on: Apr 9, 2024
 *      Author: parke
 */

#include "btn_callbacks.h"
#include <stdint.h>

extern uint16_t to_count; //to_count holds the number of pull tabs that will be counted
						  //the following functions define what each button does

void p50_btn_callback(){

	to_count += 50;

}

void p10_btn_callback(){

	to_count += 10;

}

void p1_btn_callback(){

	to_count++;

}

void reset_btn_callback(){

	to_count = 0;

}

void start_btn_callback(){

}

















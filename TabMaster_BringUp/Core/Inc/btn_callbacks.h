/*
 * btn_callbacks.h
 *
 *  Created on: Apr 9, 2024
 *      Author: parke
 */

#ifndef INC_BTN_CALLBACKS_H_
#define INC_BTN_CALLBACKS_H_

#include <stdint.h>

extern uint16_t to_count;

void p50_btn_callback(); //plus 50 button
void p10_btn_callback(); //plus 10 button
void p1_btn_callback();  //plus 1 button
void reset_btn_callback(); //reset button
void start_btn_callback(); //Start button

#endif /* INC_BTN_CALLBACKS_H_ */

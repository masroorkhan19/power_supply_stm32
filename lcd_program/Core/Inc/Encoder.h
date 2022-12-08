/*
 * Encoder.h
 *
 *  Created on: Dec 7, 2022
 *      Author: Syed Mir Hamza
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

#include "main.h"
#include "lcd_progm.h"

extern uint32_t Ticks;
extern uint32_t Current_Ticks;
extern uint32_t Previous_Ticks;
extern int32_t difference;

extern int32_t Encoder_Counter;

void Encoder_Ticks();

#endif /* INC_ENCODER_H_ */

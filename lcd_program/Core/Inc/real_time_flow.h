/*
 * real_time_flow.h
 *
 *  Created on: Dec 7, 2022
 *      Author: mkhan
 */

#ifndef INC_REAL_TIME_FLOW_H_
#define INC_REAL_TIME_FLOW_H_
#include "stdbool.h"
#include "main.h"
#include "KEYS.h"
#include "menu.h"
extern TIM_HandleTypeDef htim1;
#define lcd_update_timer_value  500 // timer 1 is set at 0.002 sec setting 500 will make 1 sec update rate
#define sw3516_update_timer_value 500
#define adc_update_timer_value 1
struct _update_real{

	bool _flag;
	uint16_t _update_timer_counter;

};

extern struct _update_real   lcd_update_,sw3516_update_,adc_update_,key_update_;



void program_flow();
 void event_base_prog_flow();
#endif /* INC_REAL_TIME_FLOW_H_ */

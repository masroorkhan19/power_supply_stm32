/*
 * KEYS.h
 *
 *  Created on: Dec 7, 2022
 *      Author: Syed Mir Hamza
 */

#ifndef INC_KEYS_H_
#define INC_KEYS_H_
#include "main.h"

#include "real_time_flow.h"

extern uint8_t page_load,state, counter;
extern TIM_HandleTypeDef htim4;

#define		key1_press	0x01//1<<0
#define		key2_press	0x02//1<<1
#define		key3_press	0x04//1<<2
#define		key4_press	0x08//1<<3
#define		key5_press	0x10//1<<4
#define		key6_press	0x20//1<<5

//typedef struct {
//
//
//	uint8_t sub_window_settable_id_location[10];
//	UG_WINDOW* window_page[3];
//
//}window_sub_struct;



extern uint8_t button_press_state;



void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
extern void button_debouncing_delay();

//extern window_with_editable_state bt_status;


void start_external_interupt_button();
void stop_external_interupt_button();
#endif /* INC_KEYS_H_ */

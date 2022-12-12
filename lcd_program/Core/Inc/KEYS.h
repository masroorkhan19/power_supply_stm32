/*
 * KEYS.h
 *
 *  Created on: Dec 7, 2022
 *      Author: Syed Mir Hamza
 */

#ifndef INC_KEYS_H_
#define INC_KEYS_H_
#include "main.h"
#include "ugui.h"
#include "real_time_flow.h"

extern uint8_t page_load,state, counter;
extern TIM_HandleTypeDef htim4;

#define		key1_press	1<<0
#define		key2_press	1<<1
#define		key3_press	1<<2
#define		key4_press	1<<3
#define		key5_press	1<<4
#define		key6_press	1<<5
#define		encoder_state_on	1
#define		encoder_state_off	0
#define		sub_tab_avialable	1
#define 	sub_tabe_not_avialable	0



typedef struct {

	UG_WINDOW* window_page;
	uint8_t number_of_settable_id;
	uint8_t current_selection_location;
	uint8_t window_sub_tab_state;
	uint8_t window_settable_id_location[];



}window_address_with_editable_state;



typedef struct {


	window_address_with_editable_state* current_window;
	uint8_t press_button_event;
}button_event;


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
extern void button_debouncing_delay();

//extern window_with_editable_state bt_status;


void start_external_interupt_button();
void stop_external_interupt_button();
#endif /* INC_KEYS_H_ */

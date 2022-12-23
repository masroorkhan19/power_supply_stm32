/*
 * lcd_callback.h
 *
 *  Created on: Dec 3, 2022
 *      Author: mkhan
 */

#ifndef INC_LCD_CALLBACK_H_
#define INC_LCD_CALLBACK_H_
#include "main.h"
#include "stdbool.h"

#define page_3_charge_type_id 1
#define page_3_temperature_id 2
#define page_3_time_id 3
#define page_3_status_A_id 4
#define page_3_status_C_id 5
#define page_3_amp_A_id 6
#define page_3_amp_A_id 6


//enum {
//	first_row =1,
//	second_row,
//	third_row=4,
//	forth_row=8,
//	fith_row=16,
//	sixth_row=32,
//	seventh_row=64,
//	eighth_row=128
//
//
//}msg_id_page_3;

void usb_charging_page_msg(void);
void buck_page_msg(void);
void setting_page_subwindow_first(uint8_t sub);
#endif /* INC_LCD_CALLBACK_H_ */

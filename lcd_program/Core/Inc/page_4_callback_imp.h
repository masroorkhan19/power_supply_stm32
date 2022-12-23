/*
 * page_4_callback_imp.h
 *
 *  Created on: Dec 20, 2022
 *      Author: HP
 */

#ifndef INC_PAGE_4_CALLBACK_IMP_H_
#define INC_PAGE_4_CALLBACK_IMP_H_
#include "ugui_ST7789.h"
#include "ugui.h"
#include "lcd_progm.h"



void window_page_4_callback(UG_MESSAGE *msg);
void window_page_4_tab_1_callback(UG_MESSAGE *msg);
void window_page_4_tab_2_callback(UG_MESSAGE *msg);
void window_page_4_tab_3_callback(UG_MESSAGE *msg);
void window_page_4_color(uint8_t ,char);
void window_page_4_tab1_color(uint8_t   , UG_COLOR );

#endif /* INC_PAGE_4_CALLBACK_IMP_H_ */

/*
 * lcd_progm.h
 *
 *  Created on: Nov 19, 2022
 *      Author: mkhan
 */

#ifndef INC_LCD_PROGM_H_
#define INC_LCD_PROGM_H_

#include "main.h"
#include "ugui_ST7789.h"
#include "ugui.h"
#include "page_2_callback_imp.h"
#include "page_3_callback_imp.h"
#include "page_4_callback_imp.h"
#include "SW3516.h"
#include "menu.h"


#define MAX_OBJECTS 					10
#define MAX_OBJECTS_WIN_PAGE_LOGO 		10
#define MAX_OBJECTS_WIN_PAGE_1 			20
#define MAX_OBJECTS_WIN_PAGE_2 			24
#define MAX_OBJECTS_WIN_PAGE_3 			27
#define MAX_OBJECTS_WIN_PAGE_4 			37
#define MAX_OBJECTS_WIN_PAGE_4_TAB_1 	20
#define MAX_OBJECTS_WIN_PAGE_4_TAB_2 	20
#define MAX_OBJECTS_WIN_PAGE_4_TAB_3 	20

#define BuffOUT     40
#define XSIZE_PHYS  320 // To be adapted to x-screen size
#define YSIZE_PHYS  240 // To be adapted to y-screen size
extern char char_buffer[16];
extern uint8_t current_page;
//
//typedef struct
//{
//   UG_U8 type;
//   UG_U8 id;
//   UG_U8 sub_id;
//   UG_U8 event;
//   void* src;
//} UG_MESSAGE;


//typedef struct {
//
//	uint8_t type;
//	uint8_t id[6][1];
//	uint8_t event;
//	void* src;
//
//
//}custom_ui_message;

extern char bufferOut[BuffOUT];
extern UG_WINDOW *active_window_ptr;

//////////////////////Page logo definitions//////////////////////
extern UG_WINDOW LOGO;
extern UG_OBJECT obj_buff_window_page_logo[MAX_OBJECTS_WIN_PAGE_LOGO];

extern UG_IMAGE image_1;
extern UG_TEXTBOX WD_graphic;
extern UG_TEXTBOX website_graphic;


//////////////////////Page 1 Definitions//////////////////////
extern UG_WINDOW window_page_1;
extern UG_OBJECT obj_buff_window_page_1[MAX_OBJECTS_WIN_PAGE_1];

extern UG_TEXTBOX textbox_page1_buck_ok;
extern UG_TEXTBOX textbox_page1_buck_cv;
extern UG_TEXTBOX textbox_page1_buck_cc;
extern UG_TEXTBOX textbox_page1_buck_current_v_value;
extern UG_TEXTBOX textbox_page1_buck_current_c_value;
extern UG_TEXTBOX textbox_page1_buck_set_v_heading;
extern UG_TEXTBOX textbox_page1_buck_set_v_value;
extern UG_TEXTBOX textbox_page1_buck_set_i_heading;
extern UG_TEXTBOX textbox_page1_buck_set_i_value;

//////////////////////Page 2 Definitions//////////////////////
extern UG_WINDOW window_page_2;
extern UG_OBJECT obj_buff_window_page_2[MAX_OBJECTS_WIN_PAGE_2];

extern UG_TEXTBOX textbox_page2_buck_current_v_heading;
extern UG_TEXTBOX textbox_page2_buck_current_t_heading;
extern UG_TEXTBOX textbox_page2_buck_current_t_value;
extern UG_TEXTBOX textbox_page2_buck_current_t_symbol;
extern UG_TEXTBOX textbox_page2_buck_current_v_value;
extern UG_TEXTBOX textbox_page2_buck_current_v_symbol;
extern UG_TEXTBOX textbox_page2_buck_current_i_heading;
extern UG_TEXTBOX textbox_page2_buck_current_i_value;
extern UG_TEXTBOX textbox_page2_buck_current_i_symbol;
extern UG_TEXTBOX textbox_page2_buck_current_w_heading;
extern UG_TEXTBOX textbox_page2_buck_current_w_value;
extern UG_TEXTBOX textbox_page2_buck_current_w_symbol;
extern UG_TEXTBOX textbox_page2_buck_set_v_heading;
extern UG_TEXTBOX textbox_page2_buck_set_v_value;
extern UG_TEXTBOX textbox_page2_buck_set_v_symbol;
extern UG_TEXTBOX textbox_page2_buck_set_i_heading;
extern UG_TEXTBOX textbox_page2_buck_set_i_value;
extern UG_TEXTBOX textbox_page2_buck_set_i_symbol;
extern UG_TEXTBOX textbox_page2_buck_cv_status;
extern UG_TEXTBOX textbox_page2_buck_cc_status;
extern UG_TEXTBOX textbox_page2_buck_ok_status;

//////////////////////Page 3 Definitions//////////////////////
extern UG_WINDOW window_page_3;
extern UG_OBJECT obj_buff_window_page_3[MAX_OBJECTS_WIN_PAGE_3];
extern UG_TEXTBOX textbox_pe;
extern UG_TEXTBOX textbox_temp;
extern UG_TEXTBOX textbox_temp_value;
extern UG_TEXTBOX textbox_temp_symbol;
extern UG_TEXTBOX textbox_usbc;
extern UG_TEXTBOX textbox_usbc_timer;
extern UG_TEXTBOX textbox_usba;
extern UG_TEXTBOX textbox_usba_timer;
extern UG_TEXTBOX textbox_page3_usbc_voltage_value;
extern UG_TEXTBOX textbox_page3_usbc_current_value;
extern UG_TEXTBOX textbox_page3_usbc_watt_value;
extern UG_TEXTBOX textbox_page3_usbc_voltage_symbol;
extern UG_TEXTBOX textbox_page3_usbc_current_symbol;
extern UG_TEXTBOX textbox_page3_usbc_watt_symbol;
extern UG_TEXTBOX textbox_page3_usba_voltage_value;
extern UG_TEXTBOX textbox_page3_usba_current_value;
extern UG_TEXTBOX textbox_page3_usba_watt_value;
extern UG_TEXTBOX textbox_page3_usba_voltage_symbol;
extern UG_TEXTBOX textbox_page3_usba_current_symbol;
extern UG_TEXTBOX textbox_page3_usba_watt_symbol;
extern UG_TEXTBOX textbox_page3_ok_symbol;
extern UG_TEXTBOX textbox_page3_cv_symbol;
extern UG_TEXTBOX textbox_page3_cc_symbol;
extern UG_TEXTBOX textbox_page3_output_voltage_value;
extern UG_TEXTBOX textbox_page3_output_current_value;
extern UG_TEXTBOX textbox_page3_output_voltage_symbol;
extern UG_TEXTBOX textbox_page3_output_current_symbol;


//////////////////////Page 4 Definitions//////////////////////
extern UG_WINDOW window_page_4;
extern UG_IMAGE image_2;
extern UG_OBJECT obj_buff_window_page_4[MAX_OBJECTS_WIN_PAGE_4];

extern UG_TEXTBOX textbox_page4_tab_1_heading;
extern UG_TEXTBOX textbox_page4_tab_2_heading;
extern UG_TEXTBOX textbox_page4_tab_3_heading;

//////////////////////Page 4 tab 1 Definitions//////////////////////
extern UG_WINDOW window_page_4_tab_1;
extern UG_OBJECT obj_buff_window_page_4_tab_1[MAX_OBJECTS_WIN_PAGE_4_TAB_1];

extern UG_TEXTBOX textbox_page4_tab_1_v_heading;
extern UG_TEXTBOX textbox_page4_tab_1_i_heading;
extern UG_TEXTBOX textbox_page4_tab_1_v_value;
extern UG_TEXTBOX textbox_page4_tab_1_v_symbol;
extern UG_TEXTBOX textbox_page4_tab_1_i_value;
extern UG_TEXTBOX textbox_page4_tab_1_i_symbol;
extern UG_TEXTBOX textbox_page4_tab_1_w_heading;
extern UG_TEXTBOX textbox_page4_tab_1_t_heading;
extern UG_TEXTBOX textbox_page4_tab_1_w_value;
extern UG_TEXTBOX textbox_page4_tab_1_w_symbol;
extern UG_TEXTBOX textbox_page4_tab_1_t_value;
extern UG_TEXTBOX textbox_page4_tab_1_t_symbol;

//////////////////////Page 4 tab 2 Definitions//////////////////////
extern UG_WINDOW window_page_4_tab_2;
extern UG_OBJECT obj_buff_window_page_4_tab_2[MAX_OBJECTS_WIN_PAGE_4_TAB_2];
extern UG_TEXTBOX textbox_page4_tab_2_language_heading;
extern UG_TEXTBOX textbox_page4_tab_2_language_english_heading;
extern UG_TEXTBOX textbox_page4_tab_2_language_chinese_heading;

//////////////////////Page 4 tab 3 Definitions//////////////////////
extern UG_WINDOW window_page_4_tab_3;
extern UG_OBJECT obj_buff_window_page_4_tab_3[MAX_OBJECTS_WIN_PAGE_4_TAB_3];


//////////////////////images Definitions//////////////////////
extern UG_IMAGE image_1;
extern UG_IMAGE image_2;
extern const UG_BMP logo_FNIRSI;
extern const UG_BMP sound;
extern const uint16_t LOGO_Image [3360];
extern const uint16_t Sound_Image [512];
extern const UG_BMP logo_USBB;
extern const uint16_t USBB_Image [760];

//key window structure













extern UG_COLOR color[3];
void begin(void);
void Page_logo(void);
void Page_1(void);
void Page_2(void);
void Page_3(void);
void Page_4(void);

void window_page_logo_callback(UG_MESSAGE *msg);
void window_page_1_callback(UG_MESSAGE *msg);


void main_window_load(uint8_t page_no);
void sub_menu_window_load(uint8_t sub_page_no);
#endif /* INC_LCD_PROGM_H_ */

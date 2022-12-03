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
#include "page_3_callback_imp.h"
#include "SW3516.h"
#define MAX_OBJECTS 10
#define MAX_OBJECTS_WIN_GRAPH 20
#define MAX_OBJECTS_WIN_PAGE_1 20
#define MAX_OBJECTS_WIN_PAGE_3 25

#define BuffOUT     40

#define XSIZE_PHYS  320 // To be adapted to x-screen size
#define YSIZE_PHYS  240 // To be adapted to y-screen size
extern char char_buffer[16];
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

extern UG_WINDOW window_1;
extern UG_WINDOW *active_window_ptr;
extern UG_WINDOW LOGO;


//page 0
extern UG_WINDOW window_page_0;
extern UG_OBJECT obj_buff_window_page_0[MAX_OBJECTS_WIN_GRAPH];
void window_page_0_callback(UG_MESSAGE *msg);



//page 1
extern UG_WINDOW window_page_1;

extern UG_BUTTON button_0;
extern UG_BUTTON button_1;
extern UG_BUTTON button_2;
extern UG_BUTTON button_3;

extern UG_TEXTBOX textbox_1;
extern UG_TEXTBOX OK_grahic;
extern UG_TEXTBOX CV_grahic;
extern UG_TEXTBOX CC_grahic;
extern UG_TEXTBOX current_V_graphic;
extern UG_TEXTBOX current_I_graphic;
extern UG_TEXTBOX current_W_graphic;

extern UG_IMAGE image_1;
extern UG_IMAGE image_2;

extern const UG_BMP logo_FNIRSI;
extern const UG_BMP sound;
extern const uint16_t LOGO_Image [3360];
extern const uint16_t Sound_Image [512];
extern const UG_BMP logo_USBB;
extern const uint16_t USBB_Image [760];


extern UG_COLOR color[3];

extern UG_OBJECT obj_buff_wnd_1[MAX_OBJECTS];

extern UG_OBJECT obj_buff_window_page_1[MAX_OBJECTS_WIN_PAGE_1];


//void window_1_callback(UG_MESSAGE *msg);
void window_page_1_callback(UG_MESSAGE *msg);

void window_logo_callback(UG_MESSAGE *msg);
void window_page_2_callback(UG_MESSAGE *msg);


//page 3
extern UG_WINDOW window_page_3;
extern UG_OBJECT obj_buff_window_page_3[MAX_OBJECTS_WIN_PAGE_3];
//void window_page_3_callback(UG_MESSAGE *msg);
void page_3(void);
extern UG_TEXTBOX textbox_pe;
extern UG_TEXTBOX textbox_temp;
extern UG_TEXTBOX textbox_temp_value;
extern UG_TEXTBOX textbox_temp_symbol;
extern UG_TEXTBOX textbox_usbc;
extern UG_TEXTBOX textbox_usba;

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



void begin(void);
void Page_0(void);
void Page_1(void);
void Page_2(void);
void Page_3(void);
void Page_logo(void);
#endif /* INC_LCD_PROGM_H_ */

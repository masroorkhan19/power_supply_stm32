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


#define MAX_OBJECTS 10
#define MAX_OBJECTS_WIN_GRAPH 20
#define MAX_OBJECTS_WIN_PAGE_1 20


#define BuffOUT     40

#define XSIZE_PHYS  320 // To be adapted to x-screen size
#define YSIZE_PHYS  240 // To be adapted to y-screen size

extern char bufferOut[BuffOUT];

extern UG_WINDOW window_1;
extern UG_WINDOW *active_window_ptr;
extern UG_WINDOW LOGO;
extern UG_WINDOW window_graph;
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
extern UG_OBJECT obj_buff_window_graph[MAX_OBJECTS_WIN_GRAPH];
extern UG_OBJECT obj_buff_window_page_1[MAX_OBJECTS_WIN_PAGE_1];


//void window_1_callback(UG_MESSAGE *msg);
void window_page_1_callback(UG_MESSAGE *msg);
void window_graph_callback(UG_MESSAGE *msg);
void window_logo_callback(UG_MESSAGE *msg);
void window_page_2_callback(UG_MESSAGE *msg);


void begin(void);
void Page_1(void);
void Page_2(void);
void Page_3(void);
void Page_logo(void);
#endif /* INC_LCD_PROGM_H_ */

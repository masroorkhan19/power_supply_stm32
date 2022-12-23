/*
 * menu.h
 *
 *  Created on: Dec 12, 2022
 *      Author: HP
 */

#ifndef INC_MENU_H_
#define INC_MENU_H_
#include "main.h"
#include "ugui.h"
#include "KEYS.h"
#include "lcd_progm.h"

#define		encoder_state_on	1
#define		encoder_state_off	0
#define		sub_tab_avialable	1
#define 	sub_tabe_not_avialable	0
#define		no_id_avialable -1
#define		total_page_menu	4

extern uint16_t temperory_content_data;

typedef struct{

	uint8_t  _number_of_settable_id;
	uint8_t _id_location[10];


}sub_window_id;

typedef struct {

	UG_WINDOW* window_page;
	uint8_t main_window_number_of_settable_id;
	uint8_t window_settable_location_id[10];
	uint8_t window_sub_tab_state;
	UG_WINDOW* sub_window_pages_address[3];
	uint8_t number_of_sub_window;
	sub_window_id sub_window[3];

}window_address_with_editable_state;


extern window_address_with_editable_state  menu_window[5];


typedef struct {
	window_address_with_editable_state* current_window;
	uint8_t press_button_event;
}button_event;



typedef struct {

	uint8_t current_page_no;
	window_address_with_editable_state current_window;
	uint8_t main_window_current_id_no;
	uint8_t sub_menu_current_id_no;
	uint8_t current_sub_window_id_no;
	uint8_t	sub_menu_exit;
	uint8_t enable_key_state;
	uint8_t lcd_first_time_load_flage;
	uint8_t lcd_sub_first_time_load_flage;
	uint8_t item_selected_flage;
	uint8_t sub_window_select;
}menu_struct;

extern menu_struct menu_;

void menu_flow(uint8_t key);
void menu_initialization();
void initialize(uint8_t page_no);
void sub_menu_initalize(int8_t );
void main_item_hover(int8_t );
void sub_item_hover(int8_t);
void setting_page_tab1();
void tab_selection_color(uint8_t ,UG_COLOR );
void changing_menu_content();

void get_menu_content();
void set_menu_content();
void temp_show_content(uint16_t ,uint8_t);
void check_safty_off();
void retrive_old_data();
#endif /* INC_MENU_H_ */

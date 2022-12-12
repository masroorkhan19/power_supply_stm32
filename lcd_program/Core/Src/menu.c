/*
 * menu.c
 *
 *  Created on: Dec 12, 2022
 *      Author: HP
 */
#include "menu.h"
window_address_with_editable_state  menu_window[5];

 menu_struct menu_;
 void initialize(uint8_t page_no){

	 menu_.current_window=menu_window[page_no];
	 menu_.current_page_no=page_no;
	 menu_.enable_key_state=0;
			if(menu_window[page_no].window_sub_tab_state==1){
			menu_.sub_menu_current_id_no=0;
			menu_.current_sub_window_id_no=0;
			menu_.sub_menu_exit =1;
			}
			else if(menu_window[page_no].window_sub_tab_state!=1){
				menu_.current_sub_window_id_no=-1;
				menu_.sub_menu_current_id_no=-1;
				menu_.sub_menu_exit =0;
			}

			if((menu_window[page_no].main_window_number_of_settable_id)>0){

			menu_.main_window_current_id_no=0;
			menu_.enable_key_state=key1_press|key2_press|key3_press|key4_press|key5_press|key6_press;
			}
			else if((menu_window[page_no].main_window_number_of_settable_id)==0)
			{

			menu_.main_window_current_id_no=-1;
			menu_.enable_key_state=(uint8_t)key4_press|key5_press|key6_press;
			}

			main_window_load( menu_.current_page_no);
			if((menu_.sub_menu_exit)==1)
			{
				sub_menu_window_load(0);
			}

 }



void menu_flow(uint8_t key){

	if((key==key4_press) || (key==key5_press)){

		if(key==key4_press){
			int8_t page_no = menu_.current_page_no-1;
					if(page_no<0){
						page_no=4;
					}

		initialize((uint8_t)page_no);
		}

		else if(key==key5_press){

			int8_t page_no = menu_.current_page_no+1;
								if(page_no>total_page_menu){
									page_no=0;
								}

					initialize((uint8_t)page_no);

		}

	}



}



void menu_initialization(){


	initialize(1);


}
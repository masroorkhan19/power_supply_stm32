/*
 * page_4_callback_imp.c
 *
 *  Created on: Dec 20, 2022
 *      Author: HP
 */
#include "page_4_callback_imp.h"
#include "eeprom_chip.h"
#include "stdio.h"
#include "menu.h"
void window_page_4_callback(UG_MESSAGE *msg){






}

void window_page_4_color(uint8_t txb_id, char color_flag){

if (color_flag=='c'){


	UG_TextboxSetBackColor(&window_page_4, txb_id, 	C_BLACK);
}
else if(color_flag =='s'){

	UG_TextboxSetBackColor(&window_page_4, txb_id, 	C_YELLOW);
}


}



///////////////////////////////////////////////////////////////////////////////////////////
void window_page_4_tab_1_callback(UG_MESSAGE *msg){


		if(msg->type==MSG_TYPE_OBJECT){

		if(msg->id==OBJ_TYPE_TEXTBOX){
		switch (msg->sub_id){
		case 3:
		{
			if(menu_.item_selected_flage){sprintf(char_buffer,"%.02f",(double)(temperory_content_data)/(double)100);}
			else {sprintf(char_buffer,"%.02f",(double)(max_eeprom_data.max_voltage/100));}
			//sprintf(char_buffer,"%.02f",(double)(max_eeprom_data.max_voltage/100));
			UG_TextboxSetText(&window_page_4_tab_1, TXB_ID_3, char_buffer);
			break;
		}
		case 5:
		{
			if(menu_.item_selected_flage){sprintf(char_buffer,"%.02f",(double)(temperory_content_data)/(double)100);}
			else{sprintf(char_buffer,"%.02f",(double)max_eeprom_data.max_current/100);}
			UG_TextboxSetText(&window_page_4_tab_1, TXB_ID_5, char_buffer);
			break;
		}
		case 9:
		{
			if(menu_.item_selected_flage){sprintf(char_buffer,"%.02f",(double)(temperory_content_data)/(double)100);}
			else{sprintf(char_buffer,"%.02f",(double)max_eeprom_data.max_power/100);}
			UG_TextboxSetText(&window_page_4_tab_1, TXB_ID_9, char_buffer);
			break;
		}
		case 11:
		{
			if(menu_.item_selected_flage){sprintf(char_buffer,"%.02f",(double)(temperory_content_data)/(double)100);}
			else{sprintf(char_buffer,"%.02f",(double)max_eeprom_data.max_temp/100);}
			UG_TextboxSetText(&window_page_4_tab_1, TXB_ID_11, char_buffer);
			break;
		}
		default:{}

		}}}




}
/////////////////////////////////////

void window_page_4_tab1_color(uint8_t txb_id  , UG_COLOR color_flag){

//if (color_flag=='c'){


	UG_TextboxSetBackColor(&window_page_4_tab_1, menu_.current_window.sub_window[0]._id_location[txb_id], 	color_flag);
//}
//else if(color_flag =='s'){
//
//	UG_TextboxSetBackColor(&guiST7735.active_window, menu_.current_window.sub_window._id_location[menu_.sub_menu_current_id_no], 	C_GREEN);
//}


}










////////////////////////////////////////////////////////
void window_page_4_tab_2_callback(UG_MESSAGE *msg){}
void window_page_4_tab_3_callback(UG_MESSAGE *msg){}


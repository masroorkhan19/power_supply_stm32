/*
 * page_2_callback_imp.c
 *
 *  Created on: Dec 13, 2022
 *      Author: HP
 */

#include "page_2_callback_imp.h"
#include "buck_convertor.h"
#include "stdio.h"

void window_page_2_callback(UG_MESSAGE *msg){

	if(msg->type==MSG_TYPE_OBJECT){

		if(msg->id==OBJ_TYPE_TEXTBOX){
		switch (msg->sub_id){
		case 2:
		{
			sprintf(char_buffer,"%.02f",buck_convertor_current.temperature);
			UG_TextboxSetText(&window_page_2, TXB_ID_2, char_buffer);
			break;
		}
		case 4:
		{
			sprintf(char_buffer,"%.02f",buck_convertor_current.voltageout_output);
	  	    UG_TextboxSetText(&window_page_2, TXB_ID_4,char_buffer);
			break;
		}
		case 7:
		{
			sprintf(char_buffer,"%.02f",buck_convertor_current.current_output);
	 	    UG_TextboxSetText(&window_page_2, TXB_ID_7, char_buffer);
			break;
		}
		case 10:
		{
			sprintf(char_buffer,"%.02f",(buck_convertor_current.voltageout_output*buck_convertor_current.current_output));
	 	    UG_TextboxSetText(&window_page_2, TXB_ID_10, char_buffer);
			break;
		}
		case 16:
		{
			if(menu_.item_selected_flage){sprintf(char_buffer,"%.02f",(double)(temperory_content_data)/(double)100);}
			else{sprintf(char_buffer,"%.02f",(double)(buck_convertor_current.voltageout_set)/(double)100);}
	 	    UG_TextboxSetText(&window_page_2, TXB_ID_16, char_buffer);
			break;
		}
		case 19:
		{
			if(menu_.item_selected_flage){sprintf(char_buffer,"%.02f",(double)(temperory_content_data)/(double)100);}
			else{sprintf(char_buffer,"%.02f",(double)buck_convertor_current.current_set/(double)100);}
	 	    UG_TextboxSetText(&window_page_2, TXB_ID_19, char_buffer);

			break;
		}
		case 21:
		{
			if(buck_convertor_current.status_cv){
			UG_TextboxSetBackColor(&window_page_2, TXB_ID_21, 	C_YELLOW);
			}
			else
			{

				UG_TextboxSetBackColor(&window_page_2, TXB_ID_21, 	C_DIM_GRAY);
			}
			break;
		}
		case 22:
		{
			if(buck_convertor_current.status_cc){
			UG_TextboxSetBackColor(&window_page_2, TXB_ID_22, 	C_YELLOW);
			}
			else
			{

				UG_TextboxSetBackColor(&window_page_2, TXB_ID_22, 	C_DIM_GRAY);
			}

			break;
		}
		case 23:
		{
			if(buck_convertor_current.buck_on_off){
	 	    UG_TextboxSetText(&window_page_2, TXB_ID_23, "ON");
	 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_23, 	C_GREEN);
				}
			else
			{
			UG_TextboxSetText(&window_page_2, TXB_ID_23, "OFF");
			UG_TextboxSetBackColor(&window_page_2, TXB_ID_23, 	C_RED);
				}

			break;
		}

		}
		}}
		}


void window_page_2_color(uint8_t txb_id  , UG_COLOR color_flag){

	UG_TextboxSetBackColor(&window_page_2, menu_.current_window.window_settable_location_id[txb_id], 	color_flag);


}


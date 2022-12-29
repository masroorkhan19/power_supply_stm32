/*
 * menu.c
 *
 *  Created on: Dec 12, 2022
 *      Author: HP
 */
#include "main.h"
#include "menu.h"
#include "buck_convertor.h"
#include "eeprom_chip.h"
#include "stdio.h"

window_address_with_editable_state  menu_window[5];

 menu_struct menu_;
 uint16_t temperory_content_data;

 void initialize(uint8_t page_no){

	 menu_.current_window=menu_window[page_no];
	 menu_.current_page_no=page_no;
	 menu_.enable_key_state=0;
	 menu_.lcd_first_time_load_flage=1;
	 menu_.item_selected_flage=0;
	 menu_.sub_window_select=0;
			if(menu_window[page_no].window_sub_tab_state==1){
			menu_.sub_menu_current_id_no=0;
			menu_.current_sub_window_id_no=0;
			menu_.sub_menu_exit =1;
			menu_.lcd_sub_first_time_load_flage=1;
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
			menu_.enable_key_state=(uint8_t)key4_press|key5_press|key1_press;
			}
			if(menu_.sub_menu_exit==0){

				main_window_load( menu_.current_page_no);
			}
			else if(menu_.sub_menu_exit==1)
			{
				for(uint8_t i=0;i<3;i++){
				window_page_4_color(i, 'c');
				}
				window_page_4_color(0, 's');
				main_window_load( menu_.current_page_no);
				sub_menu_window_load(0);
				menu_.lcd_sub_first_time_load_flage=0;
				 UG_Update();
			}

			 menu_.lcd_first_time_load_flage=0;
			// Encoder_Ticks();
 }



void menu_flow(uint8_t key){
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if((key==key4_press) || (key==key5_press)){

		//
		if( menu_.sub_window_select==1){
			if(menu_.sub_menu_exit==1){
			tab_selection_color(menu_.sub_menu_current_id_no,C_YELLOW);
			UG_Update();

			}
			else if(menu_.sub_menu_exit==0 ){
				tab_selection_color(menu_.main_window_current_id_no,C_YELLOW);

			}
			menu_.sub_window_select=0;
		}
		//
		if(key==key4_press)
		{
		int8_t page_no = menu_.current_page_no-1;
			if(page_no<0)
			{
				page_no=total_page_menu;
					}

		initialize((uint8_t)page_no);
		}
		else if(key==key5_press)
		{
		int8_t page_no = menu_.current_page_no+1;
			if(page_no>total_page_menu)
			{
				 page_no=0;
					}
		initialize((uint8_t)page_no);
		}
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	else if(((key&key2_press) || (key&key3_press) || (key&0x40))&&((menu_.enable_key_state&key2_press) || (menu_.enable_key_state&key3_press) )&& ((menu_.current_window.main_window_number_of_settable_id!=-1)  || (menu_.current_window.number_of_sub_window!=0))){


    if((key&key2_press) ){    //select button

		if(menu_.sub_menu_exit==1 && menu_.sub_window_select==0 && menu_.current_window.sub_window[menu_.current_sub_window_id_no]._number_of_settable_id !=0){
			tab_selection_color(menu_.sub_menu_current_id_no,C_GREEN);
			UG_Update();
			menu_.sub_window_select=1;


		}
		else if(menu_.sub_menu_exit==1 && menu_.sub_window_select==1 && menu_.item_selected_flage==0 && menu_.current_window.sub_window[menu_.current_sub_window_id_no]._number_of_settable_id !=0){

			tab_selection_color(menu_.sub_menu_current_id_no,C_ROYAL_BLUE);
			get_menu_content();
			UG_Update();
			menu_.item_selected_flage=1;
		}
		else if(menu_.sub_menu_exit==1 && menu_.sub_window_select==1 && menu_.item_selected_flage==1 && menu_.current_window.sub_window[menu_.current_sub_window_id_no]._number_of_settable_id !=0){

			tab_selection_color(menu_.sub_menu_current_id_no,C_GREEN);
			set_menu_content();
			UG_Update();
			menu_.item_selected_flage=0;
		}
		else if(menu_.sub_menu_exit==0 && menu_.sub_window_select==0 && menu_.item_selected_flage==0 && menu_.current_window.main_window_number_of_settable_id!=0){

			tab_selection_color(menu_.main_window_current_id_no,C_GREEN);
			//set_menu_content();
			UG_Update();
			 menu_.sub_window_select=1;
		}
		else if(menu_.sub_menu_exit==0 && menu_.sub_window_select==1 && menu_.item_selected_flage==0 && menu_.current_window.main_window_number_of_settable_id!=0){

			tab_selection_color(menu_.main_window_current_id_no,C_ROYAL_BLUE);
			check_safty_off();
			get_menu_content();
			UG_Update();
			menu_.item_selected_flage=1;
		}
		else if(menu_.sub_menu_exit==0 && menu_.sub_window_select==1 && menu_.item_selected_flage==1 && menu_.current_window.main_window_number_of_settable_id!=0){

			tab_selection_color(menu_.main_window_current_id_no,C_GREEN);
			set_menu_content();
			UG_Update();
			menu_.item_selected_flage=0;
		}

	}
	else if( (key&key3_press)){       //back button

		if(menu_.sub_menu_exit && menu_.sub_window_select==1 && menu_.item_selected_flage==0){

			tab_selection_color(menu_.sub_menu_current_id_no,C_YELLOW);
			UG_Update();
			menu_.sub_window_select=0;
		}
		else if(menu_.sub_menu_exit && menu_.sub_window_select==1 && menu_.item_selected_flage==1){
			tab_selection_color(menu_.sub_menu_current_id_no,C_GREEN);
			menu_.item_selected_flage=0;
			retrive_old_data();
			UG_Update();
			//menu_.item_selected_flage=0;

		}
		else if(menu_.sub_menu_exit==0 && menu_.sub_window_select==1 && menu_.item_selected_flage==0){

			tab_selection_color(menu_.main_window_current_id_no,C_YELLOW);
			UG_Update();
			menu_.sub_window_select=0;

		}
		else if(menu_.sub_menu_exit==0 && menu_.sub_window_select==1 && menu_.item_selected_flage==1){
			tab_selection_color(menu_.main_window_current_id_no,C_GREEN);
			menu_.item_selected_flage=0;
			retrive_old_data();
			UG_Update();

		}



	}
	else if(menu_.sub_menu_exit ){
		if(menu_.sub_window_select==0){
			// sub tab selection
			int8_t encoder_value=Encoder_Ticks_update();
			if(encoder_value>0){

				sub_menu_initalize(+1);
			}

			else if(encoder_value<0){

				sub_menu_initalize(-1);
			}


		}

		else{
			// sub tab selection
			if(menu_.item_selected_flage==0){
			if(menu_.current_window.sub_window[menu_.current_sub_window_id_no]._number_of_settable_id !=-1){
			int8_t encoder_value=Encoder_Ticks_update();
			if(encoder_value>0){

				sub_item_hover(+1);
			}

			else if(encoder_value<0){

				sub_item_hover(-1);
			}
			}

			}
			else{

				changing_menu_content();

			}
		}

	}
     ////////////////////////////////////////////////////
	else if(menu_.sub_menu_exit==0){
		if(menu_.sub_window_select==1 && menu_.item_selected_flage==0){
			int8_t encoder_value=Encoder_Ticks_update();
			if(encoder_value>0){

				main_item_hover(+1);
			}

			else if(encoder_value<0){

				main_item_hover(-1);
			}

		}
		else if(menu_.sub_window_select==1 && menu_.item_selected_flage==1){

			changing_menu_content();
		}
		}
    /////////////////////////////////////////////////////////


	}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if(key&key1_press){

    	if(buck_convertor_current.buck_on_off ==0){

    		buck_turn_on();
    	}
    	else
    	{

    		buck_turn_off();
    	}

    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}//////////////////menu_flow function end



void menu_initialization(){


	initialize(1);


}




void sub_menu_initalize(int8_t inc){

		switch (inc){

		case 1:
		{
			int8_t sub_window= menu_.current_sub_window_id_no+1;
			uint8_t temp=menu_.current_sub_window_id_no;
			if( sub_window>=menu_.current_window.number_of_sub_window){

				menu_.current_sub_window_id_no=0;
			}
			else{

				menu_.current_sub_window_id_no+=1;
			}
			menu_.sub_menu_current_id_no=0;
			window_page_4_color(temp, 'c');
			window_page_4_color(menu_.current_sub_window_id_no, 's');
			main_window_load( menu_.current_page_no);
			menu_.lcd_sub_first_time_load_flage=1;
			sub_menu_window_load(menu_.current_sub_window_id_no);

			break;
		}
		case -1:{
			int8_t sub_window= menu_.current_sub_window_id_no-1;
			uint8_t temp=menu_.current_sub_window_id_no;
			if( sub_window<0){

				menu_.current_sub_window_id_no=2;
			}
			else {
				menu_.current_sub_window_id_no-=1;
			}
			menu_.sub_menu_current_id_no=0;
			window_page_4_color(temp, 'c');
			window_page_4_color(menu_.current_sub_window_id_no, 's');
			main_window_load( menu_.current_page_no);
			menu_.lcd_sub_first_time_load_flage=1;
			sub_menu_window_load(menu_.current_sub_window_id_no);

			break;
		}
		default:{}
		}

}

void sub_item_hover(int8_t inc){

		switch(inc){

		case 1:{
			int8_t sub_window= menu_.sub_menu_current_id_no+1;
			uint8_t temp=menu_.sub_menu_current_id_no;
			if( sub_window>=menu_.current_window.sub_window[menu_.current_sub_window_id_no]._number_of_settable_id){

				menu_.sub_menu_current_id_no=0;
			}
			else{

				menu_.sub_menu_current_id_no+=1;
			}

			tab_selection_color(temp,C_YELLOW);
			tab_selection_color(menu_.sub_menu_current_id_no,C_GREEN);
			UG_Update();
			break;
		}

		case -1:{

			int8_t sub_window= menu_.sub_menu_current_id_no-1;
			uint8_t temp=menu_.sub_menu_current_id_no;
			if( sub_window<0){

				menu_.sub_menu_current_id_no=menu_.current_window.sub_window[menu_.current_sub_window_id_no]._number_of_settable_id-1;
			}
			else {
				menu_.sub_menu_current_id_no-=1;
			}

			tab_selection_color(temp,C_YELLOW);
			tab_selection_color(menu_.sub_menu_current_id_no,C_GREEN);
			UG_Update();
					break;
		}

		default:{}
		}


}

void main_item_hover(int8_t inc){


	switch(inc){
	case 1:
	{
		int8_t sub_window= menu_.main_window_current_id_no+1;
		uint8_t temp=menu_.main_window_current_id_no;
		if( sub_window>=menu_.current_window.main_window_number_of_settable_id){

			menu_.main_window_current_id_no=0;
		}
		else{

			menu_.main_window_current_id_no+=1;
		}

		tab_selection_color(temp,C_YELLOW);
		tab_selection_color(menu_.main_window_current_id_no,C_GREEN);
		UG_Update();


		break;}
	case -1:
	{
		int8_t sub_window= menu_.main_window_current_id_no-1;
		uint8_t temp=menu_.main_window_current_id_no;
		if( sub_window<0){

			menu_.main_window_current_id_no=menu_.current_window.main_window_number_of_settable_id-1;
		}
		else {
			menu_.main_window_current_id_no-=1;
		}

		tab_selection_color(temp,C_YELLOW);
		tab_selection_color(menu_.main_window_current_id_no,C_GREEN);
		UG_Update();

		break;}
	default :{}
	}


}


void setting_page_tab1(){



}


void tab_selection_color(uint8_t index,UG_COLOR color){

 if(menu_.sub_menu_exit){
	switch(menu_.current_sub_window_id_no){

	case 0:{


		window_page_4_tab1_color(index , color);
		break;
	}

	case 1:{

		break;
	}

	case 2:{

		break;
	}

	default :{}

	}
 }
 else{
	 switch(menu_.current_page_no){
	 case 0:
	 {break;}
	 case 1:
	 {break;}
	 case 2:
	 {

		 window_page_2_color(index , color);
		 break;}
	 case 3:
	 {break;}
	 default:{}

	 }



 }


}

void check_safty_off(){

	switch(menu_.current_page_no){
	case 0:
	{break;}
	case 1:
	{break;}
	case 2:
	{
		buck_turn_off();
		UG_MESSAGE page_msg={2,2,0,2,&obj_buff_window_page_2};
		page_msg.sub_id=23;
		window_page_2_callback(&page_msg);
		UG_Update();
		break;}
	case 3:
	{break;}
	case 4:
	{break;}
	default:{}
	}

}


void changing_menu_content(){


	if(menu_.sub_menu_exit && menu_.current_page_no==4){

		switch(menu_.current_sub_window_id_no){
		case 0:
		{
			switch(menu_.sub_menu_current_id_no){
			case 0:
			{
				temp_show_content(9999,1);
				UG_MESSAGE page_msg={2,2,0,2,&obj_buff_window_page_4_tab_1};
				page_msg.sub_id=3;
				window_page_4_tab_1_callback(&page_msg);
				UG_Update();
				break;
			}
			case 1:
			{
				temp_show_content(9999,1);
				UG_MESSAGE page_msg={2,2,0,2,&obj_buff_window_page_4_tab_1};
				page_msg.sub_id=5;
				window_page_4_tab_1_callback(&page_msg);
				UG_Update();

				break;
			}
			case 2:
			{
				temp_show_content(60000,100);
				UG_MESSAGE page_msg={2,2,0,2,&obj_buff_window_page_4_tab_1};
				page_msg.sub_id=9;
				window_page_4_tab_1_callback(&page_msg);
				UG_Update();
				break;
			}
			case 3:
			{
				temp_show_content(30000,100);
				UG_MESSAGE page_msg={2,2,0,2,&obj_buff_window_page_4_tab_1};
				page_msg.sub_id=11;
				window_page_4_tab_1_callback(&page_msg);
				UG_Update();
				break;
			}
			default:{}

			}

			break;}

		case 1:
		{break;}

		case 2:
		{break;}
		default:{}

		}


	}
	else{
		switch(menu_.current_page_no){
		case 0:{break;}
		case 1:{break;}
		case 2:{
				switch(menu_.main_window_current_id_no){
				case 0:
				{
					temp_show_content(max_eeprom_data.max_voltage,1);
					UG_MESSAGE page_msg={2,2,0,2,&obj_buff_window_page_2};
					page_msg.sub_id=16;
					window_page_2_callback(&page_msg);
					UG_Update();
					break;
				}
				case 1:
				{
					temp_show_content(max_eeprom_data.max_current,1);
					UG_MESSAGE page_msg={2,2,0,2,&obj_buff_window_page_2};
					page_msg.sub_id=19;
					window_page_2_callback(&page_msg);
					UG_Update();
					break;
				}
				default :{}
				}

			break;}
		case 3:{break;}
		default :{}
		}
	}


}

void temp_show_content(uint16_t upper_scale,uint8_t increment_step){

	int8_t encoder_value=Encoder_Ticks_update();

	temperory_content_data +=(encoder_value*increment_step);
	if(temperory_content_data>upper_scale){
		temperory_content_data=0;
	}
	else if(temperory_content_data==-1){

		temperory_content_data=upper_scale;
	}


}


void get_menu_content(){


	if(menu_.sub_menu_exit && menu_.current_page_no==4){

		switch(menu_.current_sub_window_id_no){
		case 0:
		{
			switch(menu_.sub_menu_current_id_no){
			case 0:{
				temperory_content_data= max_eeprom_data.max_voltage;
				break;
			}

			case 1:{
				temperory_content_data= max_eeprom_data.max_current;
				break;
			}

			case 2:{
				temperory_content_data= max_eeprom_data.max_power;
				break;
			}

			case 3:{
				temperory_content_data= max_eeprom_data.max_temp;
				break;
			}

			}

			break;
		}
		case 1:
		{

			break;
		}
		case 2:
		{

			break;
		}
		default:{}


		}
	}

	else{


		switch(menu_.current_page_no){

		case 0:{ break;}
		case 1:{break;}
		case 2:{
			switch(menu_.main_window_current_id_no){
			case 0:
			{
				temperory_content_data=buck_convertor_current.voltageout_set;
				break;}
			case 1:
			{
				temperory_content_data=buck_convertor_current.current_set;
				break;}
			default:{}
			}
			break;}
		case 3:{ break;}
		default:{}

		}

	}


}


void set_menu_content(){


	if(menu_.sub_menu_exit && menu_.current_page_no==4){

		switch(menu_.current_sub_window_id_no){
		case 0:
		{
			switch(menu_.sub_menu_current_id_no){
			case 0:{
				write_eeprom(temperory_content_data,max_voltage);
				read_eeprom(max_voltage);
				break;
			}

			case 1:{
				write_eeprom(temperory_content_data,max_current);
				read_eeprom(max_current);
				break;
			}

			case 2:{
				write_eeprom(temperory_content_data,max_power);
				read_eeprom(max_power);
				break;
			}

			case 3:{
				write_eeprom(temperory_content_data,max_temp);
				read_eeprom(max_temp);
				break;
			}

			}

			break;
		}
		case 1:
		{

			break;
		}
		case 2:
		{

			break;
		}
		default:{}


		}
	}

	else{


		switch(menu_.current_page_no){

		case 0:{ break;}
		case 1:{ break;}
		case 2:{
			switch(menu_.main_window_current_id_no){
			case 0:
			{
				buck_convertor_current.voltageout_set=temperory_content_data;
				write_buck_set_voltage();

				break;}
			case 1:
			{
				buck_convertor_current.current_set=temperory_content_data;
				write_buck_set_current();

				break;}
			default:{}
			}



			break;}
		case 3:{ break;}
		default:{}


		}

	}



}


void retrive_old_data(){


	if(menu_.sub_menu_exit && menu_.current_page_no==4){

		switch(menu_.current_sub_window_id_no){
		case 0:
		{
			switch(menu_.sub_menu_current_id_no){
			case 0:{


				UG_MESSAGE page_msg={2,2,0,2,&obj_buff_window_page_4_tab_1};
				page_msg.sub_id=3;
				window_page_4_tab_1_callback(&page_msg);
				break;
			}

			case 1:{

				UG_MESSAGE page_msg={2,2,0,2,&obj_buff_window_page_4_tab_1};
				page_msg.sub_id=5;
				window_page_4_tab_1_callback(&page_msg);
				break;
			}

			case 2:{

				UG_MESSAGE page_msg={2,2,0,2,&obj_buff_window_page_4_tab_1};
				page_msg.sub_id=9;
				window_page_4_tab_1_callback(&page_msg);
				break;
			}

			case 3:{

				UG_MESSAGE page_msg={2,2,0,2,&obj_buff_window_page_4_tab_1};
				page_msg.sub_id=11;
				window_page_4_tab_1_callback(&page_msg);
				break;
			}

			}

			break;
		}
		case 1:
		{

			break;
		}
		case 2:
		{

			break;
		}
		default:{}


		}
	}

	else{


		switch(menu_.current_page_no){

		case 0:{ break;}
		case 1:{ break;}
		case 2:{
			switch(menu_.main_window_current_id_no){
			case 0:
			{
				UG_MESSAGE page_msg={2,2,0,2,&obj_buff_window_page_2};
				page_msg.sub_id=16;
				window_page_2_callback(&page_msg);
				break;}
			case 1:
			{
				UG_MESSAGE page_msg={2,2,0,2,&obj_buff_window_page_2};
				page_msg.sub_id=19;
				window_page_2_callback(&page_msg);
				break;}
			default:{}
			}

			break;}
		case 3:{ break;}
		default:{}


		}

	}



}







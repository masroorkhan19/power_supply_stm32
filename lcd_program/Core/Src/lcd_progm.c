/*
 * lcd_progm.c
 *
 *  Created on: Nov 19, 2022
 *      Author: mkhan
 */
#include "lcd_progm.h"
#include "ugui_ST7789.h"
#include "stm32f1xx_hal.h"
#include "stdio.h"
#include "buck_convertor.h"
#include "menu.h"






 uint8_t current_page=0;
UG_COLOR color[3]= {C_RED, C_GREEN, C_BLUE};
char bufferOut[BuffOUT];
char char_buffer[16];
UG_WINDOW *active_window_ptr;



//////////////////////Page logo definitions//////////////////////
UG_WINDOW LOGO;
UG_OBJECT obj_buff_window_page_logo[MAX_OBJECTS_WIN_PAGE_LOGO];

UG_IMAGE image_1;
UG_TEXTBOX WD_graphic;
UG_TEXTBOX website_graphic;

const UG_BMP logo_FNIRSI =     // Construct the BMP structure with the Image data
{
    (void*)LOGO_Image,   // Data Image
    140,                // Image Width
    24,                // Image Heigth
    BMP_BPP_16,        // BPPs = 16Bit => 2*8bit
    BMP_RGB565         // Use RGB888 for RGB 24Bits BMP Image, RBG565 for 16bits
};



//////////////////////Page 1 Definitions//////////////////////
UG_WINDOW window_page_1;
UG_OBJECT obj_buff_window_page_1[MAX_OBJECTS_WIN_PAGE_1];

UG_TEXTBOX textbox_page1_buck_ok;
UG_TEXTBOX textbox_page1_buck_cv;
UG_TEXTBOX textbox_page1_buck_cc;
UG_TEXTBOX textbox_page1_buck_current_v_value;
UG_TEXTBOX textbox_page1_buck_current_c_value;
UG_TEXTBOX textbox_page1_buck_set_v_heading;
UG_TEXTBOX textbox_page1_buck_set_v_value;
UG_TEXTBOX textbox_page1_buck_set_i_heading;
UG_TEXTBOX textbox_page1_buck_set_i_value;


//////////////////////Page 2 Definitions//////////////////////
UG_WINDOW window_page_2;
UG_OBJECT obj_buff_window_page_2[MAX_OBJECTS_WIN_PAGE_2];

UG_TEXTBOX textbox_page2_buck_current_v_heading;
UG_TEXTBOX textbox_page2_buck_current_t_heading;
UG_TEXTBOX textbox_page2_buck_current_t_value;
UG_TEXTBOX textbox_page2_buck_current_t_symbol;
UG_TEXTBOX textbox_page2_buck_current_v_value;
UG_TEXTBOX textbox_page2_buck_current_v_symbol;
UG_TEXTBOX textbox_page2_buck_current_i_heading;
UG_TEXTBOX textbox_page2_buck_current_i_value;
UG_TEXTBOX textbox_page2_buck_current_i_symbol;
UG_TEXTBOX textbox_page2_buck_current_w_heading;
UG_TEXTBOX textbox_page2_buck_current_w_value;
UG_TEXTBOX textbox_page2_buck_current_w_symbol;
UG_TEXTBOX textbox_page2_buck_set_v_heading;
UG_TEXTBOX textbox_page2_buck_set_v_value;
UG_TEXTBOX textbox_page2_buck_set_v_symbol;
UG_TEXTBOX textbox_page2_buck_set_i_heading;
UG_TEXTBOX textbox_page2_buck_set_i_value;
UG_TEXTBOX textbox_page2_buck_set_i_symbol;
UG_TEXTBOX textbox_page2_buck_cv_status;
UG_TEXTBOX textbox_page2_buck_cc_status;
UG_TEXTBOX textbox_page2_buck_ok_status;

//////////////////////Page 3 Definitions//////////////////////
UG_WINDOW window_page_3;
UG_OBJECT obj_buff_window_page_3[MAX_OBJECTS_WIN_PAGE_3];

UG_TEXTBOX textbox_pe;
UG_TEXTBOX textbox_temp;
UG_TEXTBOX textbox_temp_value;
UG_TEXTBOX textbox_temp_symbol;
UG_TEXTBOX textbox_usbc;
UG_TEXTBOX textbox_usbc_timer;
UG_TEXTBOX textbox_usba;
UG_TEXTBOX textbox_usba_timer;
UG_TEXTBOX textbox_page3_usbc_voltage_value;
UG_TEXTBOX textbox_page3_usbc_current_value;
UG_TEXTBOX textbox_page3_usbc_watt_value;
UG_TEXTBOX textbox_page3_usbc_voltage_symbol;
UG_TEXTBOX textbox_page3_usbc_current_symbol;
UG_TEXTBOX textbox_page3_usbc_watt_symbol;
UG_TEXTBOX textbox_page3_usba_voltage_value;
UG_TEXTBOX textbox_page3_usba_current_value;
UG_TEXTBOX textbox_page3_usba_watt_value;
UG_TEXTBOX textbox_page3_usba_voltage_symbol;
UG_TEXTBOX textbox_page3_usba_current_symbol;
UG_TEXTBOX textbox_page3_usba_watt_symbol;
UG_TEXTBOX textbox_page3_ok_symbol;
UG_TEXTBOX textbox_page3_cv_symbol;
UG_TEXTBOX textbox_page3_cc_symbol;
UG_TEXTBOX textbox_page3_output_voltage_value;
UG_TEXTBOX textbox_page3_output_current_value;
UG_TEXTBOX textbox_page3_output_voltage_symbol;
UG_TEXTBOX textbox_page3_output_current_symbol;

//////////////////////Page 4 Definitions//////////////////////
UG_WINDOW window_page_4;
UG_IMAGE image_2;
UG_OBJECT obj_buff_window_page_4[MAX_OBJECTS_WIN_PAGE_4];

UG_TEXTBOX textbox_page4_tab_1_heading;
UG_TEXTBOX textbox_page4_tab_2_heading;
UG_TEXTBOX textbox_page4_tab_3_heading;

//////////////////////Page 4 tab 1 Definitions//////////////////////
UG_WINDOW window_page_4_tab_1;
UG_OBJECT obj_buff_window_page_4_tab_1[MAX_OBJECTS_WIN_PAGE_4_TAB_1];

UG_TEXTBOX textbox_page4_tab_1_v_heading;
UG_TEXTBOX textbox_page4_tab_1_i_heading;
UG_TEXTBOX textbox_page4_tab_1_v_value;
UG_TEXTBOX textbox_page4_tab_1_v_symbol;
UG_TEXTBOX textbox_page4_tab_1_i_value;
UG_TEXTBOX textbox_page4_tab_1_i_symbol;
UG_TEXTBOX textbox_page4_tab_1_w_heading;
UG_TEXTBOX textbox_page4_tab_1_t_heading;
UG_TEXTBOX textbox_page4_tab_1_w_value;
UG_TEXTBOX textbox_page4_tab_1_w_symbol;
UG_TEXTBOX textbox_page4_tab_1_t_value;
UG_TEXTBOX textbox_page4_tab_1_t_symbol;

//////////////////////Page 4 tab 2 Definitions//////////////////////
UG_WINDOW window_page_4_tab_2;
UG_OBJECT obj_buff_window_page_4_tab_2[MAX_OBJECTS_WIN_PAGE_4_TAB_2];
UG_TEXTBOX textbox_page4_tab_2_language_heading;
UG_TEXTBOX textbox_page4_tab_2_language_english_heading;
UG_TEXTBOX textbox_page4_tab_2_language_chinese_heading;
UG_TEXTBOX textbox_page4_tab_2_temperature_unit_heading;
UG_TEXTBOX textbox_page4_tab_2_degree_celsius_heading;
UG_TEXTBOX textbox_page4_tab_2_degree_fahrenheit_heading;
UG_TEXTBOX textbox_page4_tab_2_brightness_heading;
UG_TEXTBOX textbox_page4_tab_2_brightness_bar;
UG_TEXTBOX textbox_page4_tab_2_volume_heading;
UG_TEXTBOX textbox_page4_tab_2_volume_bar;

//////////////////////Page 4 tab 3 Definitions//////////////////////
UG_WINDOW window_page_4_tab_3;
UG_OBJECT obj_buff_window_page_4_tab_3[MAX_OBJECTS_WIN_PAGE_4_TAB_3];

UG_TEXTBOX textbox_page4_tab_3_website;
UG_TEXTBOX textbox_page4_tab_3_model;
UG_TEXTBOX textbox_page4_tab_3_serial;
UG_TEXTBOX textbox_page4_tab_3_version;



void Page_logo(void){

		 	    UG_WindowShow(&LOGO);
		 	   UG_Update();
		 	    UG_DrawLine(105, 79, 221, 79, C_AQUA);
		 	    current_page=0;
}

 void Page_1(void){

	 	    UG_WindowShow(&window_page_1);
	 	   UG_Update();

	 	        UG_FillCircle(297,23, 12, C_GREEN);

	 	        ///grid
	 	 	    //horizontal lines
	 	        UG_DrawLine(0, 39, 319, 39, C_WHITE);
	 	 	    for (int i=1;i<5;i++){
	 	 	    	 UG_DrawLine(73, 39+10*i, 319, 39+10*i, C_WHITE);
	 	 	    }
	 	 	    for (int i=5;i<18;i++){
	 	 	    	 UG_DrawLine(0, 39+10*i, 320, 39+10*i, C_WHITE);
	 	 	    }
	 	 	    UG_DrawLine(0, 218, 319, 218, C_WHITE);

	 	 	    //vertical lines
	 	 	    UG_DrawLine(0, 40, 0, 218, C_WHITE);
	 	 	    for (int i=0;i<4;i++){
	 	 	  	 	    	 UG_DrawLine(0+19*i, 84, 0+19*i, 218, C_WHITE);
 	    	    }
	 	 	    for (int i=4;i<17;i++){
	 	 	    	    	 UG_DrawLine(0+19*i, 40, 0+19*i, 218, C_WHITE);
 	    	    }
	 	 	    UG_DrawLine(319, 40, 319, 218, C_WHITE);


	 	 	    for(int i=0;i<4;i++){
	 	 	    	UG_DrawLine(5, 150+i, 315, 150+i, C_YELLOW);
	 	 	    }

	 	 	    for(int i=0;i<4;i++){
	 	 	   	 	 UG_DrawLine(5, 180+i, 315, 180+i, C_GREEN);
	 	 	   	}
	 	 	  current_page=1;
 }

 void Page_2(){

		 	    UG_WindowShow(&window_page_2);
		 	   buck_page_msg();
		 	   UG_Update();

	 	        UG_DrawLine(205, 0, 205, 239, C_WHITE);
	 	   	  	UG_DrawLine(205, 35, 319, 35, C_WHITE);
	 	   	  	UG_DrawLine(205, 140, 319, 140, C_WHITE);
	 	   	 current_page=2;
 }




 void Page_3(){

	 	 	 	UG_WindowShow(&window_page_3);
	 	 	  usb_charging_page_msg( );
	 	 	 UG_Update();
	 	 	   	UG_DrawLine(0, 32, 319, 32, C_WHITE);
	  	 	 	UG_DrawLine(160, 32, 160, 196, C_WHITE);
	  	 	   	UG_DrawLine(0, 196, 319, 196, C_WHITE);
	  	 	 current_page=3;
 }

 void Page_4(void){

 		 	    UG_WindowShow(&window_page_4);
 		 	  UG_Update();

	 	 	 //	UG_WindowShow(&window_page_4_tab_2);
	 	 	 	//UG_WindowShow(&window_page_4_tab_3);



 		 	    UG_DrawLine(104, 23, 104, 239, C_WHITE);
 		 	    UG_DrawLine(0, 95, 104, 95, C_WHITE);
 		 	    UG_DrawLine(0, 167, 104, 167, C_WHITE);
 		 	  current_page=4;

 }

 void page_4_tab1(void){
	 setting_page_subwindow_first(0);
	UG_WindowShow(&window_page_4_tab_1);


	UG_Update();
 }

 void page_4_tab2(void){
	 setting_page_subwindow_first(1);
	UG_WindowShow(&window_page_4_tab_2);

	UG_Update();

	UG_DrawFrame(120, 167, 287, 184, C_WHITE);
	UG_DrawFrame(120, 212, 287, 229, C_WHITE);

 }
 void page_4_tab3(void){
//	 setting_page_subwindow_first(2);
	UG_WindowShow(&window_page_4_tab_3);

	UG_Update();
 }



void begin(void){
	//Logo
		 		UG_WindowCreate(&LOGO, obj_buff_window_page_logo, MAX_OBJECTS_WIN_PAGE_LOGO, window_page_logo_callback);
				UG_WindowSetStyle(&LOGO, WND_STYLE_2D | WND_STYLE_HIDE_TITLE);
				UG_WindowSetBackColor(&LOGO, C_BLACK);

				UG_ImageCreate(&LOGO, &image_1, IMG_ID_1,105, 50, 245,74);
				UG_ImageSetBMP(&LOGO, IMG_ID_1, &logo_FNIRSI);

				UG_TextboxCreate(&LOGO, &website_graphic, TXB_ID_0, 1, 116, 318, 154);
				UG_TextboxSetFont(&LOGO, TXB_ID_0, &FONT_10X16);
				UG_TextboxSetAlignment(&LOGO, TXB_ID_0, ALIGN_CENTER);
				UG_TextboxSetBackColor(&LOGO, TXB_ID_0, C_BLACK);
				UG_TextboxSetForeColor(&LOGO, TXB_ID_0, C_WHITE);
				UG_TextboxSetText(&LOGO, TXB_ID_0, "http://www.fnirsi.cn");
				UG_TextboxShow(&LOGO, TXB_ID_0);

				UG_TextboxCreate(&LOGO, &WD_graphic, TXB_ID_1, 90, 85, 230, 115);
				UG_TextboxSetFont(&LOGO, TXB_ID_1, &FONT_12X20);
				UG_TextboxSetAlignment(&LOGO, TXB_ID_1, ALIGN_CENTER);
				UG_TextboxSetBackColor(&LOGO, TXB_ID_1, C_YELLOW);
				UG_TextboxSetForeColor(&LOGO, TXB_ID_1, C_BLACK);
				UG_TextboxSetText(&LOGO, TXB_ID_1, "WD-02");
				UG_TextboxShow(&LOGO, TXB_ID_1);

//				configuring key menu structure for logo page

				menu_window[0].window_page = &LOGO;
				menu_window[0].window_sub_tab_state = sub_tabe_not_avialable;
				menu_window[0].main_window_number_of_settable_id=0;
				menu_window[0].number_of_sub_window=0;
				for(int i=0;i<3;i++){
				menu_window[0].sub_window_pages_address[i]=NULL;
				menu_window[0].sub_window[i]._number_of_settable_id=0;
				for(int j=0;j<10;j++){

					menu_window[0].sub_window[i]._id_location[j]=no_id_avialable;
				}
				}
				for(int z=0;z<10;z++){

					menu_window[0].window_settable_location_id[z]=no_id_avialable;
				}




	//Page 1
				UG_WindowCreate(&window_page_1, obj_buff_window_page_1, MAX_OBJECTS_WIN_PAGE_1, window_page_1_callback);
		 	    UG_WindowSetStyle(&window_page_1, WND_STYLE_2D | WND_STYLE_HIDE_TITLE);
		 	    UG_WindowSetBackColor(&window_page_1, C_BLACK);

		 	    /////////////ok //
		 	    UG_TextboxCreate(&window_page_1, &textbox_page1_buck_ok, TXB_ID_0, 0, 5, 70, 35);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_0, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_0, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_0, C_GREEN);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_0, C_BLACK);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_0, "OK");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_0);

		 	    ////////////CV//
		 	    UG_TextboxCreate(&window_page_1, &textbox_page1_buck_cv, TXB_ID_1, 75, 5, 105, 35);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_1, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_1, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_1, C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_1, C_BLACK);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_1, "CV");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_1);
		 	    ////////////CC//
		 	    UG_TextboxCreate(&window_page_1, &textbox_page1_buck_cc, TXB_ID_2, 110, 5, 140, 35);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_2, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_2, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_2, 	C_DIM_GRAY);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_2, C_BLACK);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_2, "CC");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_2);

		 	    UG_ImageCreate(&window_page_1, &image_1, IMG_ID_1,145, 8, 160,32);
		 	   	UG_ImageSetBMP(&window_page_1, IMG_ID_1, &logo_FNIRSI);

		 	    UG_TextboxCreate(&window_page_1, &textbox_page1_buck_current_v_value, TXB_ID_3, 1, 40, 73,60);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_3, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_3, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_3, 	C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_3, C_BLACK);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_3, "12.10V");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_3);

		 	    UG_TextboxCreate(&window_page_1, &textbox_page1_buck_current_c_value, TXB_ID_4, 1, 63, 73,83);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_4, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_4, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_4, 	C_GREEN);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_4, C_BLACK);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_4, "0.000A");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_4);

		 	    UG_TextboxCreate(&window_page_1, &textbox_page1_buck_set_v_heading, TXB_ID_5, 0, 218, 76, 238);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_5, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_5, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_5, 	C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_5, C_WHITE);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_5, "SET V:");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_5);

		 	    UG_TextboxCreate(&window_page_1, &textbox_page1_buck_set_v_value, TXB_ID_6, 80, 218, 156, 238);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_6, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_6, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_6, 	C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_6, C_BLACK);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_6, "00.00V");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_6);

		 	    UG_TextboxCreate(&window_page_1, &textbox_page1_buck_set_i_heading, TXB_ID_7, 162, 218, 238, 238);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_7, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_7, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_7, 	C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_7, C_WHITE);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_7, "SET I:");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_7);

		 	    UG_TextboxCreate(&window_page_1, &textbox_page1_buck_set_i_value, TXB_ID_8, 242, 218, 318, 238);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_8, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_8, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_8, 	C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_8, C_BLACK);
		 	   UG_TextboxSetText(&window_page_1, TXB_ID_8, "0.000A");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_8);
//				configuring key menu structure for logo page

			menu_window[1].window_page = &window_page_1;
			menu_window[1].window_sub_tab_state = sub_tabe_not_avialable;
			menu_window[1].main_window_number_of_settable_id=0;
			menu_window[1].number_of_sub_window=0;
			for(int i=0;i<3;i++){
			menu_window[1].sub_window_pages_address[i]=NULL;
			menu_window[1].sub_window[i]._number_of_settable_id=0;
			for(int j=0;j<10;j++){

				menu_window[1].sub_window[i]._id_location[j]=no_id_avialable;
			}
			}
			for(int z=0;z<10;z++){

				menu_window[1].window_settable_location_id[z]=no_id_avialable;
			}
	//Page 2
	 	 	 	UG_WindowCreate(&window_page_2, obj_buff_window_page_2, MAX_OBJECTS_WIN_PAGE_2, window_page_2_callback);
		 	    UG_WindowSetStyle(&window_page_2, WND_STYLE_2D | WND_STYLE_HIDE_TITLE);
		 	    UG_WindowSetBackColor(&window_page_2, C_BLACK);

		 	    /////////////Current Voltage //
		   	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_current_v_heading, TXB_ID_0, 0, 10, 200, 26);
		  	    UG_TextboxSetFont(&window_page_2, TXB_ID_0, &FONT_10X16);
		 	   	UG_TextboxSetAlignment(&window_page_2, TXB_ID_0, ALIGN_CENTER_LEFT);
		 	   	UG_TextboxSetBackColor(&window_page_2, TXB_ID_0, C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_0, C_BLACK);
		  	    UG_TextboxSetText(&window_page_2, TXB_ID_0, "VOLTS");
		 	   	UG_TextboxShow(&window_page_2, TXB_ID_0);

		 	    ////////////Temp//
		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_current_t_heading, TXB_ID_1, 210, 5, 240, 30);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_1, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_1, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_1, 	C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_1, C_BLACK);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_1, "T");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_1);

		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_current_t_value, TXB_ID_2, 245, 5, 270, 30);
		 	    UG_TextboxSetFont(&window_page_2, TXB_ID_2, &FONT_12X20);
		  	    UG_TextboxSetAlignment(&window_page_2, TXB_ID_2, ALIGN_CENTER);
		  	    UG_TextboxSetBackColor(&window_page_2, TXB_ID_2, C_BLACK);
		  	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_2, C_YELLOW);

		   	    UG_TextboxShow(&window_page_2, TXB_ID_2);

		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_current_t_symbol, TXB_ID_3, 272, 5, 285, 30);
		 	    UG_TextboxSetFont(&window_page_2, TXB_ID_3, &FONT_12X20);
		  	    UG_TextboxSetAlignment(&window_page_2, TXB_ID_3, ALIGN_CENTER);
		  	    UG_TextboxSetBackColor(&window_page_2, TXB_ID_3, C_BLACK);
		  	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_3, C_YELLOW);
		   	    UG_TextboxSetText(&window_page_2, TXB_ID_3, "C");
		   	    UG_TextboxShow(&window_page_2, TXB_ID_3);

		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_current_v_value, TXB_ID_4, 0, 31, 181, 71);
		 	    UG_TextboxSetFont(&window_page_2, TXB_ID_4, &FONT_24X40);
	  	 	    UG_TextboxSetAlignment(&window_page_2, TXB_ID_4, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_2, TXB_ID_4, C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_4, C_WHITE);

		  	    UG_TextboxShow(&window_page_2, TXB_ID_4);

		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_current_v_symbol, TXB_ID_5, 182, 31, 200, 71);
		 	    UG_TextboxSetFont(&window_page_2, TXB_ID_5, &FONT_10X16);
		 	    UG_TextboxSetAlignment(&window_page_2, TXB_ID_5, ALIGN_BOTTOM_RIGHT);
		 	    UG_TextboxSetBackColor(&window_page_2, TXB_ID_5, C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_5, C_YELLOW);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_5, "V");
		 	    UG_TextboxShow(&window_page_2, TXB_ID_5);

		 	    ////////////Current Current//
		   	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_current_i_heading, TXB_ID_6, 0, 91, 200, 107);
		  	    UG_TextboxSetFont(&window_page_2, TXB_ID_6, &FONT_10X16);
		 	   	UG_TextboxSetAlignment(&window_page_2, TXB_ID_6, ALIGN_CENTER_LEFT);
		 	   	UG_TextboxSetBackColor(&window_page_2, TXB_ID_6, C_GREEN);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_6, C_BLACK);
		  	    UG_TextboxSetText(&window_page_2, TXB_ID_6, "AMPS");
		 	   	UG_TextboxShow(&window_page_2, TXB_ID_6);

		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_current_i_value, TXB_ID_7, 0, 112, 181, 152);
		 	    UG_TextboxSetFont(&window_page_2, TXB_ID_7, &FONT_24X40);
		 	    UG_TextboxSetAlignment(&window_page_2, TXB_ID_7, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_2, TXB_ID_7, C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_7, C_WHITE);

		 	    UG_TextboxShow(&window_page_2, TXB_ID_7);

		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_current_i_symbol, TXB_ID_8, 182, 112, 200, 152);
		 	    UG_TextboxSetFont(&window_page_2, TXB_ID_8, &FONT_10X16);
		 	    UG_TextboxSetAlignment(&window_page_2, TXB_ID_8, ALIGN_BOTTOM_RIGHT);
		 	    UG_TextboxSetBackColor(&window_page_2, TXB_ID_8, C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_8, C_GREEN);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_8, "A");
		 	    UG_TextboxShow(&window_page_2, TXB_ID_8);

		 	    ////////////power//
		   	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_current_w_heading, TXB_ID_9, 0, 172, 200, 188);
		  	    UG_TextboxSetFont(&window_page_2, TXB_ID_9, &FONT_10X16);
		 	   	UG_TextboxSetAlignment(&window_page_2, TXB_ID_9, ALIGN_CENTER_LEFT);
		 	   	UG_TextboxSetBackColor(&window_page_2, TXB_ID_9, C_VIOLET);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_9, C_BLACK);
		  	    UG_TextboxSetText(&window_page_2, TXB_ID_9, "WATTS");
		 	   	UG_TextboxShow(&window_page_2, TXB_ID_9);

		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_current_w_value, TXB_ID_10, 0, 193, 181, 233);
		 	    UG_TextboxSetFont(&window_page_2, TXB_ID_10, &FONT_24X40);
		 	    UG_TextboxSetAlignment(&window_page_2, TXB_ID_10, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_2, TXB_ID_10, C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_10, C_WHITE);

		 	    UG_TextboxShow(&window_page_2, TXB_ID_10);

		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_current_w_symbol, TXB_ID_11, 182, 193, 200, 233);
		 	    UG_TextboxSetFont(&window_page_2, TXB_ID_11, &FONT_10X16);
		 	    UG_TextboxSetAlignment(&window_page_2, TXB_ID_11, ALIGN_BOTTOM_RIGHT);
		 	    UG_TextboxSetBackColor(&window_page_2, TXB_ID_11, C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_11, C_VIOLET);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_11, "W");
		 	    UG_TextboxShow(&window_page_2, TXB_ID_11);

		  	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_set_v_heading, TXB_ID_15, 210, 40, 318, 56);
		  	  	UG_TextboxSetFont(&window_page_2, TXB_ID_15, &FONT_10X16);
		  	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_15, ALIGN_CENTER_LEFT);
		   	   	UG_TextboxSetBackColor(&window_page_2, TXB_ID_15, C_BLACK);
		   	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_15, C_WHITE);
	    	    UG_TextboxSetText(&window_page_2, TXB_ID_15, "Set V");
		   	   	UG_TextboxShow(&window_page_2, TXB_ID_15);

		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_set_v_value, TXB_ID_16, 210, 60, 290, 80);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_16, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_16, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_16, 	C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_16, C_BLACK);

		 	  	UG_TextboxShow(&window_page_2, TXB_ID_16);

		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_set_v_symbol, TXB_ID_17, 291, 60, 314, 80);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_17, &FONT_10X16);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_17, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_17, 	C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_17, C_BLACK);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_17, "V");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_17);


		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_set_i_heading, TXB_ID_18, 210, 90, 318, 106);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_18, &FONT_10X16);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_18, ALIGN_CENTER_LEFT);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_18, 	C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_18, C_WHITE);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_18, "SET I");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_18);

		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_set_i_value, TXB_ID_19, 210, 110, 290, 130);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_19, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_19, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_19, 	C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_19, C_BLACK);

		 	  	UG_TextboxShow(&window_page_2, TXB_ID_19);

		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_set_i_symbol, TXB_ID_20, 291, 110, 314, 130);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_20, &FONT_10X16);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_20, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_20, 	C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_20, C_BLACK);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_20, "A");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_20);

		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_cv_status, TXB_ID_21, 210, 145, 259, 188);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_21, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_21, ALIGN_CENTER);

		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_21, C_BLACK);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_21, "CV");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_21);


		 	    UG_TextboxCreate(&window_page_2, &textbox_page2_buck_cc_status, TXB_ID_22, 265, 145, 314, 188);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_22, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_22, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_22, 	C_DIM_GRAY);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_22, C_BLACK);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_22, "CC");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_22);

		 	  	UG_TextboxCreate(&window_page_2, &textbox_page2_buck_ok_status, TXB_ID_23, 210, 193, 314, 233);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_23, &FONT_24X40);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_23, ALIGN_CENTER);

		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_23, C_BLACK);

		 	  	UG_TextboxShow(&window_page_2, TXB_ID_23);
//				configuring key menu structure for  page 2

			menu_window[2].window_page = &window_page_2;
			menu_window[2].window_sub_tab_state = sub_tabe_not_avialable;
			menu_window[2].main_window_number_of_settable_id=2;
			menu_window[2].number_of_sub_window=0;
			for(int i=0;i<3;i++){
			menu_window[2].sub_window_pages_address[i]=NULL;
			menu_window[2].sub_window[i]._number_of_settable_id=0;
			for(int j=0;j<10;j++){

				menu_window[2].sub_window[i]._id_location[j]=no_id_avialable;
			}
			}
				menu_window[2].window_settable_location_id[0]=TXB_ID_16;
				menu_window[2].window_settable_location_id[1]=TXB_ID_19;
				//menu_window[2].window_settable_location_id[2]=TXB_ID_23;

	 //page 3
				UG_WindowCreate(&window_page_3, obj_buff_window_page_3, MAX_OBJECTS_WIN_PAGE_3, window_page_3_callback);
				UG_WindowSetStyle(&window_page_3, WND_STYLE_2D | WND_STYLE_HIDE_TITLE);
				UG_WindowSetBackColor(&window_page_3, C_BLACK);
				/////////////power mode //
				UG_TextboxCreate(&window_page_3, &textbox_pe, TXB_ID_0, 5, 5, 85, 27);
				UG_TextboxSetFont(&window_page_3, TXB_ID_0, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_0, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_0, C_YELLOW);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_0, C_BLACK);

				UG_TextboxShow(&window_page_3, TXB_ID_0);

				UG_TextboxCreate(&window_page_3, &textbox_temp, TXB_ID_1, 175, 5, 225, 27);
				UG_TextboxSetFont(&window_page_3, TXB_ID_1, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_1, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_1, C_YELLOW);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_1, C_BLACK);
				UG_TextboxSetText(&window_page_3, TXB_ID_1, "TEMP");
				UG_TextboxShow(&window_page_3, TXB_ID_1);

				// temp value
				UG_TextboxCreate(&window_page_3, &textbox_temp_value, TXB_ID_2, 228, 5, 288, 27);
				UG_TextboxSetFont(&window_page_3, TXB_ID_2, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_2, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_2, C_BLACK);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_2, C_YELLOW);

				UG_TextboxShow(&window_page_3, TXB_ID_2);

				// temp symbol
				UG_TextboxCreate(&window_page_3, &textbox_temp_symbol, TXB_ID_3, 292, 5, 310, 27);
				UG_TextboxSetFont(&window_page_3, TXB_ID_3, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_3, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_3, C_BLACK);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_3, C_YELLOW);
				UG_TextboxSetText(&window_page_3, TXB_ID_3, "C");
				UG_TextboxShow(&window_page_3, TXB_ID_3);

				//usbc symbol
				UG_TextboxCreate(&window_page_3, &textbox_usbc, TXB_ID_4, 5, 32, 50, 59);
				UG_TextboxSetFont(&window_page_3, TXB_ID_4, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_4, ALIGN_CENTER);

				UG_TextboxSetForeColor(&window_page_3, TXB_ID_4, C_BLACK);

				UG_TextboxSetText(&window_page_3, TXB_ID_4, "USBC");
				UG_TextboxShow(&window_page_3, TXB_ID_4);




				//usba symbol
				UG_TextboxCreate(&window_page_3, &textbox_usba, TXB_ID_5, 175, 32, 215, 59);
				UG_TextboxSetFont(&window_page_3, TXB_ID_5, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_5, ALIGN_CENTER);


				UG_TextboxSetForeColor(&window_page_3, TXB_ID_5, C_BLACK);
				UG_TextboxSetText(&window_page_3, TXB_ID_5, "USBA");
				UG_TextboxShow(&window_page_3, TXB_ID_5);

				//usbc voltage value
				UG_TextboxCreate(&window_page_3, &textbox_page3_usbc_voltage_value, TXB_ID_6, 5, 64, 130, 104);
				UG_TextboxSetFont(&window_page_3, TXB_ID_6, &FONT_24X40);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_6, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_6, C_YELLOW_GREEN);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_6, C_WHITE);

				UG_TextboxShow(&window_page_3, TXB_ID_6);

				//usbc voltage symbol
				UG_TextboxCreate(&window_page_3, &textbox_page3_usbc_voltage_symbol, TXB_ID_7, 130, 64, 145, 104);
				UG_TextboxSetFont(&window_page_3, TXB_ID_7, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_7, ALIGN_V_BOTTOM);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_7, C_YELLOW_GREEN);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_7, C_WHITE);
				UG_TextboxSetText(&window_page_3, TXB_ID_7, "V");
				UG_TextboxShow(&window_page_3, TXB_ID_7);


				//usba voltage value
				UG_TextboxCreate(&window_page_3, &textbox_page3_usba_voltage_value, TXB_ID_8, 175, 64, 300, 104);
				UG_TextboxSetFont(&window_page_3, TXB_ID_8, &FONT_24X40);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_8, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_8, C_YELLOW_GREEN);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_8, C_WHITE);



				UG_TextboxShow(&window_page_3, TXB_ID_8);

				//usba voltage symbol
				UG_TextboxCreate(&window_page_3, &textbox_page3_usba_voltage_symbol, TXB_ID_9, 300, 64, 310, 104);
				UG_TextboxSetFont(&window_page_3, TXB_ID_9, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_9, ALIGN_V_BOTTOM);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_9, C_YELLOW_GREEN);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_9, C_WHITE);
				UG_TextboxSetText(&window_page_3, TXB_ID_9, "V");
				UG_TextboxShow(&window_page_3, TXB_ID_9);


				//usbc current value
				UG_TextboxCreate(&window_page_3, &textbox_page3_usbc_current_value, TXB_ID_10, 5, 109, 130, 149);
				UG_TextboxSetFont(&window_page_3, TXB_ID_10, &FONT_24X40);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_10, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_10, C_BROWN);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_10, C_WHITE);


				UG_TextboxShow(&window_page_3, TXB_ID_10);

				//usbc current symbol
				UG_TextboxCreate(&window_page_3, &textbox_page3_usbc_current_symbol, TXB_ID_11, 130, 109, 145, 149);
				UG_TextboxSetFont(&window_page_3, TXB_ID_11, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_11, ALIGN_V_BOTTOM);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_11, C_BROWN);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_11, C_WHITE);
				UG_TextboxSetText(&window_page_3, TXB_ID_11, "A");
				UG_TextboxShow(&window_page_3, TXB_ID_11);


				//usba current value
				UG_TextboxCreate(&window_page_3, &textbox_page3_usba_current_value, TXB_ID_12, 175, 109, 300, 149);
				UG_TextboxSetFont(&window_page_3, TXB_ID_12, &FONT_24X40);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_12, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_12, C_BROWN);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_12, C_WHITE);

				UG_TextboxShow(&window_page_3, TXB_ID_12);

				//usba current symbol
				UG_TextboxCreate(&window_page_3, &textbox_page3_usba_current_symbol, TXB_ID_13, 300, 109, 310, 149);
				UG_TextboxSetFont(&window_page_3, TXB_ID_13, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_13, ALIGN_V_BOTTOM);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_13, C_BROWN);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_13, C_WHITE);
				UG_TextboxSetText(&window_page_3, TXB_ID_13, "A");
				UG_TextboxShow(&window_page_3, TXB_ID_13);


				//usbc watt value
				UG_TextboxCreate(&window_page_3, &textbox_page3_usbc_watt_value, TXB_ID_14, 5, 154, 130, 194);
				UG_TextboxSetFont(&window_page_3, TXB_ID_14, &FONT_24X40);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_14, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_14, C_INDIGO);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_14, C_WHITE);

				UG_TextboxShow(&window_page_3, TXB_ID_14);

				//usbc watt symbol
				UG_TextboxCreate(&window_page_3, &textbox_page3_usbc_watt_symbol, TXB_ID_15, 130, 154, 145, 194);
				UG_TextboxSetFont(&window_page_3, TXB_ID_15, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_15, ALIGN_V_BOTTOM);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_15, C_INDIGO);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_15, C_WHITE);
				UG_TextboxSetText(&window_page_3, TXB_ID_15, "W");
				UG_TextboxShow(&window_page_3, TXB_ID_15);


				//usba watt value
				UG_TextboxCreate(&window_page_3, &textbox_page3_usba_watt_value, TXB_ID_16, 175, 154, 300, 194);
				UG_TextboxSetFont(&window_page_3, TXB_ID_16, &FONT_24X40);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_16, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_16, C_INDIGO);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_16, C_WHITE);
				UG_TextboxShow(&window_page_3, TXB_ID_16);

				//usba watt symbol
				UG_TextboxCreate(&window_page_3, &textbox_page3_usba_watt_symbol, TXB_ID_17, 300, 154, 310, 194);
				UG_TextboxSetFont(&window_page_3, TXB_ID_17, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_17, ALIGN_V_BOTTOM);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_17, C_INDIGO);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_17, C_WHITE);
				UG_TextboxSetText(&window_page_3, TXB_ID_17, "W");
				UG_TextboxShow(&window_page_3, TXB_ID_17);

				// ok
				UG_TextboxCreate(&window_page_3, &textbox_page3_ok_symbol, TXB_ID_18, 15, 200, 65, 235);
				UG_TextboxSetFont(&window_page_3, TXB_ID_18, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_18, ALIGN_CENTER);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_18, C_BLACK);

				UG_TextboxShow(&window_page_3, TXB_ID_18);

				// cv
				UG_TextboxCreate(&window_page_3, &textbox_page3_cv_symbol, TXB_ID_19, 70, 200, 95, 235);
				UG_TextboxSetFont(&window_page_3, TXB_ID_19, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_19, ALIGN_CENTER);


				UG_TextboxSetForeColor(&window_page_3, TXB_ID_19, C_BLACK);
				UG_TextboxSetText(&window_page_3, TXB_ID_19, "CV");
				UG_TextboxShow(&window_page_3, TXB_ID_19);
				// cc
				UG_TextboxCreate(&window_page_3, &textbox_page3_cc_symbol, TXB_ID_20, 100, 200, 125, 235);
				UG_TextboxSetFont(&window_page_3, TXB_ID_20, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_20, ALIGN_CENTER);

				UG_TextboxSetForeColor(&window_page_3, TXB_ID_20, C_BLACK);
				UG_TextboxSetText(&window_page_3, TXB_ID_20, "CC");
				UG_TextboxShow(&window_page_3, TXB_ID_20);

				// output voltage
				UG_TextboxCreate(&window_page_3, &textbox_page3_output_voltage_value, TXB_ID_21, 130, 200, 185, 235);
				UG_TextboxSetFont(&window_page_3, TXB_ID_21, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_21, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_21, C_BLACK);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_21, C_WHITE);


				UG_TextboxShow(&window_page_3, TXB_ID_21);
				// output voltage symbol
				UG_TextboxCreate(&window_page_3, &textbox_page3_output_voltage_symbol, TXB_ID_22, 190, 200, 205, 235);
				UG_TextboxSetFont(&window_page_3, TXB_ID_22, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_22, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_22, C_BLACK);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_22, C_WHITE);
				UG_TextboxSetText(&window_page_3, TXB_ID_22, "V");
				UG_TextboxShow(&window_page_3, TXB_ID_22);


				// output current
				UG_TextboxCreate(&window_page_3, &textbox_page3_output_current_value, TXB_ID_23, 210, 200, 265, 235);
				UG_TextboxSetFont(&window_page_3, TXB_ID_23, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_23, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_23, C_BLACK);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_23, C_WHITE);
				UG_TextboxShow(&window_page_3, TXB_ID_23);

				// output current symbol
				UG_TextboxCreate(&window_page_3, &textbox_page3_output_current_symbol, TXB_ID_24, 270, 200, 285, 235);
				UG_TextboxSetFont(&window_page_3, TXB_ID_24, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_24, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_24, C_BLACK);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_24, C_WHITE);
				UG_TextboxSetText(&window_page_3, TXB_ID_24, "A");
				UG_TextboxShow(&window_page_3, TXB_ID_24);

				// usbc timer
				UG_TextboxCreate(&window_page_3, &textbox_usbc_timer, TXB_ID_25, 55, 32, 145, 59);
				UG_TextboxSetFont(&window_page_3, TXB_ID_25, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_25, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_25, C_LIGHT_SLATE_GRAY);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_25, C_WHITE_SMOKE);
				UG_TextboxShow(&window_page_3, TXB_ID_25);
				// usba timer
				UG_TextboxCreate(&window_page_3, &textbox_usba_timer, TXB_ID_26, 220, 32, 310, 59);
				UG_TextboxSetFont(&window_page_3, TXB_ID_26, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_3, TXB_ID_26, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_26, C_LIGHT_SLATE_GRAY);
				UG_TextboxSetForeColor(&window_page_3, TXB_ID_26, C_WHITE_SMOKE);
				UG_TextboxShow(&window_page_3, TXB_ID_26);
//				configuring key menu structure for  page 2

				menu_window[3].window_page = &window_page_3;
				menu_window[3].window_sub_tab_state = sub_tabe_not_avialable;
				menu_window[3].main_window_number_of_settable_id=1;
				menu_window[3].number_of_sub_window=0;
				for(int i=0;i<3;i++){
				menu_window[3].sub_window_pages_address[i]=NULL;
				menu_window[3].sub_window[i]._number_of_settable_id=0;
				for(int j=0;j<10;j++){

					menu_window[3].sub_window[i]._id_location[j]=no_id_avialable;
				}
				}
					menu_window[3].window_settable_location_id[0]=TXB_ID_18;

//Page 4
				UG_WindowCreate(&window_page_4, obj_buff_window_page_4, MAX_OBJECTS_WIN_PAGE_4, window_page_4_callback);
				UG_WindowSetStyle(&window_page_4, WND_STYLE_2D | WND_STYLE_SHOW_TITLE);
				UG_WindowResize(&window_page_4, 0, 0, 319, 239);
				UG_WindowSetBackColor(&window_page_4, C_BLACK);

				UG_WindowSetTitleColor(&window_page_4, C_BLACK); //title ending line is 22 pixel in height
				UG_WindowSetTitleTextColor(&window_page_4, C_YELLOW);
				UG_WindowSetTitleTextAlignment(&window_page_4, ALIGN_CENTER);
				UG_WindowSetTitleText(&window_page_4,"Settings");
				UG_WindowSetTitleTextFont(&window_page_4,&FONT_12X20);

				UG_TextboxCreate(&window_page_4, &textbox_page4_tab_1_heading, TXB_ID_0, 0,0,102,70);
				UG_TextboxSetFont(&window_page_4, TXB_ID_0, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4, TXB_ID_0, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4, TXB_ID_0, 	C_YELLOW);
				UG_TextboxSetForeColor(&window_page_4, TXB_ID_0, C_WHITE);
				UG_TextboxSetText(&window_page_4, TXB_ID_0, "Power\nSupply\nConfig");
				UG_TextboxShow(&window_page_4, TXB_ID_0);

				UG_TextboxCreate(&window_page_4, &textbox_page4_tab_2_heading, TXB_ID_1, 0,73,102,142);
				UG_TextboxSetFont(&window_page_4, TXB_ID_1, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4, TXB_ID_1, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4, TXB_ID_1, 	C_BLACK);
				UG_TextboxSetForeColor(&window_page_4, TXB_ID_1, C_WHITE);
				UG_TextboxSetText(&window_page_4, TXB_ID_1, "System\nConfig");
				UG_TextboxShow(&window_page_4, TXB_ID_1);

				UG_TextboxCreate(&window_page_4, &textbox_page4_tab_3_heading, TXB_ID_2, 0,146,102,215);
				UG_TextboxSetFont(&window_page_4, TXB_ID_2, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4, TXB_ID_2, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4, TXB_ID_2, 	C_BLACK);
				UG_TextboxSetForeColor(&window_page_4, TXB_ID_2, C_WHITE);
				UG_TextboxSetText(&window_page_4, TXB_ID_2, "About");
				UG_TextboxShow(&window_page_4, TXB_ID_2);
			//tab 1
				UG_WindowCreate(&window_page_4_tab_1, obj_buff_window_page_4_tab_1, MAX_OBJECTS_WIN_PAGE_4_TAB_1, window_page_4_tab_1_callback);
				UG_WindowSetStyle(&window_page_4_tab_1, WND_STYLE_2D | WND_STYLE_HIDE_TITLE);
				UG_WindowResize(&window_page_4_tab_1, 106, 23, 319, 239);
				UG_WindowSetBackColor(&window_page_4_tab_1, C_BLACK);

				UG_TextboxCreate(&window_page_4_tab_1, &textbox_page4_tab_1_v_heading, TXB_ID_1, 10,34,80,50);
				UG_TextboxSetFont(&window_page_4_tab_1, TXB_ID_1, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_1, TXB_ID_1, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4_tab_1, TXB_ID_1, 	C_BLACK);
				UG_TextboxSetForeColor(&window_page_4_tab_1, TXB_ID_1, C_WHITE);
				UG_TextboxSetText(&window_page_4_tab_1, TXB_ID_1, "Voltage");
				UG_TextboxShow(&window_page_4_tab_1, TXB_ID_1);

				UG_TextboxCreate(&window_page_4_tab_1, &textbox_page4_tab_1_i_heading, TXB_ID_2, 130,34,210,50);
				UG_TextboxSetFont(&window_page_4_tab_1, TXB_ID_2, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_1, TXB_ID_2, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4_tab_1, TXB_ID_2, 	C_BLACK);
				UG_TextboxSetForeColor(&window_page_4_tab_1, TXB_ID_2, C_WHITE);
				UG_TextboxSetText(&window_page_4_tab_1, TXB_ID_2, "Ampere");
				UG_TextboxShow(&window_page_4_tab_1, TXB_ID_2);

				UG_TextboxCreate(&window_page_4_tab_1, &textbox_page4_tab_1_v_value, TXB_ID_3, 15,55,80,85);
				UG_TextboxSetFont(&window_page_4_tab_1, TXB_ID_3, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4_tab_1, TXB_ID_3, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_4_tab_1, TXB_ID_3, 	C_YELLOW);
				UG_TextboxSetForeColor(&window_page_4_tab_1, TXB_ID_3, C_BLACK);
				UG_TextboxShow(&window_page_4_tab_1, TXB_ID_3);

				UG_TextboxCreate(&window_page_4_tab_1, &textbox_page4_tab_1_v_symbol, TXB_ID_4, 80,55,90,85);
				UG_TextboxSetFont(&window_page_4_tab_1, TXB_ID_4, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_1, TXB_ID_4, ALIGN_BOTTOM_RIGHT);
				UG_TextboxSetBackColor(&window_page_4_tab_1, TXB_ID_4, 	C_YELLOW);
				UG_TextboxSetForeColor(&window_page_4_tab_1, TXB_ID_4, C_BLACK);
				UG_TextboxSetText(&window_page_4_tab_1, TXB_ID_4, "V");
				UG_TextboxShow(&window_page_4_tab_1, TXB_ID_4);

				UG_TextboxCreate(&window_page_4_tab_1, &textbox_page4_tab_1_i_value, TXB_ID_5, 135,55,200,85);
				UG_TextboxSetFont(&window_page_4_tab_1, TXB_ID_5, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4_tab_1, TXB_ID_5, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_4_tab_1, TXB_ID_5, 	C_YELLOW);
				UG_TextboxSetForeColor(&window_page_4_tab_1, TXB_ID_5, C_BLACK);
				UG_TextboxShow(&window_page_4_tab_1, TXB_ID_5);

				UG_TextboxCreate(&window_page_4_tab_1, &textbox_page4_tab_1_i_symbol, TXB_ID_6, 200,55,210,85);
				UG_TextboxSetFont(&window_page_4_tab_1, TXB_ID_6, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_1, TXB_ID_6, ALIGN_BOTTOM_RIGHT);
				UG_TextboxSetBackColor(&window_page_4_tab_1, TXB_ID_6, 	C_YELLOW);
				UG_TextboxSetForeColor(&window_page_4_tab_1, TXB_ID_6, C_BLACK);
				UG_TextboxSetText(&window_page_4_tab_1, TXB_ID_6, "A");
				UG_TextboxShow(&window_page_4_tab_1, TXB_ID_6);

				UG_TextboxCreate(&window_page_4_tab_1, &textbox_page4_tab_1_w_heading, TXB_ID_7, 10,120,70,140);
				UG_TextboxSetFont(&window_page_4_tab_1, TXB_ID_7, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_1, TXB_ID_7, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4_tab_1, TXB_ID_7, 	C_BLACK);
				UG_TextboxSetForeColor(&window_page_4_tab_1, TXB_ID_7, C_WHITE);
				UG_TextboxSetText(&window_page_4_tab_1, TXB_ID_7, "Watts");
				UG_TextboxShow(&window_page_4_tab_1, TXB_ID_7);

				UG_TextboxCreate(&window_page_4_tab_1, &textbox_page4_tab_1_t_heading, TXB_ID_8, 130,120,180,140);
				UG_TextboxSetFont(&window_page_4_tab_1, TXB_ID_8, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_1, TXB_ID_8, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4_tab_1, TXB_ID_8, 	C_BLACK);
				UG_TextboxSetForeColor(&window_page_4_tab_1, TXB_ID_8, C_WHITE);
				UG_TextboxSetText(&window_page_4_tab_1, TXB_ID_8, "Temp");
				UG_TextboxShow(&window_page_4_tab_1, TXB_ID_8);

				UG_TextboxCreate(&window_page_4_tab_1, &textbox_page4_tab_1_w_value, TXB_ID_9, 15,145,80,175);
				UG_TextboxSetFont(&window_page_4_tab_1, TXB_ID_9, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4_tab_1, TXB_ID_9, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_4_tab_1, TXB_ID_9, 	C_YELLOW);
				UG_TextboxSetForeColor(&window_page_4_tab_1, TXB_ID_9, C_BLACK);
				UG_TextboxShow(&window_page_4_tab_1, TXB_ID_9);

				UG_TextboxCreate(&window_page_4_tab_1, &textbox_page4_tab_1_w_symbol, TXB_ID_10, 80,145,90,175);
				UG_TextboxSetFont(&window_page_4_tab_1, TXB_ID_10, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_1, TXB_ID_10, ALIGN_BOTTOM_RIGHT);
				UG_TextboxSetBackColor(&window_page_4_tab_1, TXB_ID_10, 	C_YELLOW);
				UG_TextboxSetForeColor(&window_page_4_tab_1, TXB_ID_10, C_BLACK);
				UG_TextboxSetText(&window_page_4_tab_1, TXB_ID_10, "W");
				UG_TextboxShow(&window_page_4_tab_1, TXB_ID_10);

				UG_TextboxCreate(&window_page_4_tab_1, &textbox_page4_tab_1_t_value, TXB_ID_11, 135,145,195,175);
				UG_TextboxSetFont(&window_page_4_tab_1, TXB_ID_11, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4_tab_1, TXB_ID_11, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_4_tab_1, TXB_ID_11, 	C_YELLOW);
				UG_TextboxSetForeColor(&window_page_4_tab_1, TXB_ID_11, C_BLACK);
				UG_TextboxShow(&window_page_4_tab_1, TXB_ID_11);

				UG_TextboxCreate(&window_page_4_tab_1, &textbox_page4_tab_1_t_symbol, TXB_ID_12, 195,145,205,175);
				UG_TextboxSetFont(&window_page_4_tab_1, TXB_ID_12, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_1, TXB_ID_12, ALIGN_BOTTOM_RIGHT);
				UG_TextboxSetBackColor(&window_page_4_tab_1, TXB_ID_12, 	C_YELLOW);
				UG_TextboxSetForeColor(&window_page_4_tab_1, TXB_ID_12, C_BLACK);
				UG_TextboxSetText(&window_page_4_tab_1, TXB_ID_12, "C");
				UG_TextboxShow(&window_page_4_tab_1, TXB_ID_12);
			//tab 2
				UG_WindowCreate(&window_page_4_tab_2, obj_buff_window_page_4_tab_2, MAX_OBJECTS_WIN_PAGE_4_TAB_2, window_page_4_tab_2_callback);
				UG_WindowSetStyle(&window_page_4_tab_2, WND_STYLE_2D | WND_STYLE_HIDE_TITLE);
				UG_WindowResize(&window_page_4_tab_2, 106, 23, 319, 239);
				UG_WindowSetBackColor(&window_page_4_tab_2, C_BLACK);

				UG_TextboxCreate(&window_page_4_tab_2, &textbox_page4_tab_2_language_heading, TXB_ID_0, 10,10,180,30);
				UG_TextboxSetFont(&window_page_4_tab_2, TXB_ID_0, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_2, TXB_ID_0, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4_tab_2, TXB_ID_0,  C_BLACK);
				UG_TextboxSetForeColor(&window_page_4_tab_2, TXB_ID_0, C_WHITE);
				UG_TextboxSetText(&window_page_4_tab_2, TXB_ID_0, "Language:");
				UG_TextboxShow(&window_page_4_tab_2, TXB_ID_0);

				UG_TextboxCreate(&window_page_4_tab_2, &textbox_page4_tab_2_language_chinese_heading, TXB_ID_1, 15,35,65,60);
				UG_TextboxSetFont(&window_page_4_tab_2, TXB_ID_1, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4_tab_2, TXB_ID_1, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_4_tab_2, TXB_ID_1, 	C_DIM_GRAY);
				UG_TextboxSetForeColor(&window_page_4_tab_2, TXB_ID_1, C_BLACK);
				UG_TextboxSetText(&window_page_4_tab_2, TXB_ID_1, "CN");
				UG_TextboxShow(&window_page_4_tab_2, TXB_ID_1);

				UG_TextboxCreate(&window_page_4_tab_2, &textbox_page4_tab_2_language_english_heading, TXB_ID_2, 110,35,160,60);
				UG_TextboxSetFont(&window_page_4_tab_2, TXB_ID_2, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4_tab_2, TXB_ID_2, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_4_tab_2, TXB_ID_2, 	C_YELLOW);
				UG_TextboxSetForeColor(&window_page_4_tab_2, TXB_ID_2, C_BLACK);
				UG_TextboxSetText(&window_page_4_tab_2, TXB_ID_2, "EN");
				UG_TextboxShow(&window_page_4_tab_2, TXB_ID_2);

				UG_TextboxCreate(&window_page_4_tab_2, &textbox_page4_tab_2_temperature_unit_heading, TXB_ID_3, 10,65,180,85);
				UG_TextboxSetFont(&window_page_4_tab_2, TXB_ID_3, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_2, TXB_ID_3, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4_tab_2, TXB_ID_3, 	C_BLACK);
				UG_TextboxSetForeColor(&window_page_4_tab_2, TXB_ID_3, C_WHITE);
				UG_TextboxSetText(&window_page_4_tab_2, TXB_ID_3, "Temperature Unit:");
				UG_TextboxShow(&window_page_4_tab_2, TXB_ID_3);

				UG_TextboxCreate(&window_page_4_tab_2, &textbox_page4_tab_2_degree_celsius_heading, TXB_ID_4, 15,90,65,115);
				UG_TextboxSetFont(&window_page_4_tab_2, TXB_ID_4, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4_tab_2, TXB_ID_4, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_4_tab_2, TXB_ID_4, 	C_YELLOW);
				UG_TextboxSetForeColor(&window_page_4_tab_2, TXB_ID_4, C_BLACK);
				UG_TextboxSetText(&window_page_4_tab_2, TXB_ID_4, "C");
				UG_TextboxShow(&window_page_4_tab_2, TXB_ID_4);

				UG_TextboxCreate(&window_page_4_tab_2, &textbox_page4_tab_2_degree_fahrenheit_heading, TXB_ID_5, 110,90,160,115);
				UG_TextboxSetFont(&window_page_4_tab_2, TXB_ID_5, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4_tab_2, TXB_ID_5, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_4_tab_2, TXB_ID_5, 	C_DIM_GRAY);
				UG_TextboxSetForeColor(&window_page_4_tab_2, TXB_ID_5, C_BLACK);
				UG_TextboxSetText(&window_page_4_tab_2, TXB_ID_5, "F");
				UG_TextboxShow(&window_page_4_tab_2, TXB_ID_5);

				UG_TextboxCreate(&window_page_4_tab_2, &textbox_page4_tab_2_brightness_heading, TXB_ID_6, 10,120,180,140);
				UG_TextboxSetFont(&window_page_4_tab_2, TXB_ID_6, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_2, TXB_ID_6, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4_tab_2, TXB_ID_6, 	C_BLACK);
				UG_TextboxSetForeColor(&window_page_4_tab_2, TXB_ID_6, C_WHITE);
				UG_TextboxSetText(&window_page_4_tab_2, TXB_ID_6, "Brightness:");
				UG_TextboxShow(&window_page_4_tab_2, TXB_ID_6);

				UG_TextboxCreate(&window_page_4_tab_2, &textbox_page4_tab_2_brightness_bar, TXB_ID_7, 15,145,83,160);
				UG_TextboxSetFont(&window_page_4_tab_2, TXB_ID_7, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_2, TXB_ID_7, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_4_tab_2, TXB_ID_7, 	C_YELLOW);
				UG_TextboxSetForeColor(&window_page_4_tab_2, TXB_ID_7, C_BLACK);
				UG_TextboxSetText(&window_page_4_tab_2, TXB_ID_7, "");
				UG_TextboxShow(&window_page_4_tab_2, TXB_ID_7);

				UG_TextboxCreate(&window_page_4_tab_2, &textbox_page4_tab_2_volume_heading, TXB_ID_8, 10,165,180,185);
				UG_TextboxSetFont(&window_page_4_tab_2, TXB_ID_8, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_2, TXB_ID_8, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4_tab_2, TXB_ID_8, 	C_BLACK);
				UG_TextboxSetForeColor(&window_page_4_tab_2, TXB_ID_8, C_WHITE);
				UG_TextboxSetText(&window_page_4_tab_2, TXB_ID_8, "Volume:");
				UG_TextboxShow(&window_page_4_tab_2, TXB_ID_8);

				UG_TextboxCreate(&window_page_4_tab_2, &textbox_page4_tab_2_volume_bar, TXB_ID_9, 15,190,83,205);
				UG_TextboxSetFont(&window_page_4_tab_2, TXB_ID_9, &FONT_10X16);
				UG_TextboxSetAlignment(&window_page_4_tab_2, TXB_ID_9, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_4_tab_2, TXB_ID_9, 	C_YELLOW);
				UG_TextboxSetForeColor(&window_page_4_tab_2, TXB_ID_9, C_WHITE);
				UG_TextboxSetText(&window_page_4_tab_2, TXB_ID_9, "");
				UG_TextboxShow(&window_page_4_tab_2, TXB_ID_9);

			//tab 3
				UG_WindowCreate(&window_page_4_tab_3, obj_buff_window_page_4_tab_3, MAX_OBJECTS_WIN_PAGE_4_TAB_3, window_page_4_tab_3_callback);
				UG_WindowSetStyle(&window_page_4_tab_3, WND_STYLE_2D | WND_STYLE_HIDE_TITLE);
				UG_WindowResize(&window_page_4_tab_3, 106, 23, 319, 239);
				UG_WindowSetBackColor(&window_page_4_tab_3, C_BLACK);


				UG_ImageCreate(&window_page_4_tab_3, &image_1, IMG_ID_0,50, 30, 190,54);
				UG_ImageSetBMP(&window_page_4_tab_3, IMG_ID_0, &logo_FNIRSI);

				UG_TextboxCreate(&window_page_4_tab_3, &textbox_page4_tab_3_website, TXB_ID_0, 30,60,190,80);
				UG_TextboxSetFont(&window_page_4_tab_3, TXB_ID_0, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4_tab_3, TXB_ID_0, ALIGN_CENTER);
				UG_TextboxSetBackColor(&window_page_4_tab_3, TXB_ID_0, 	C_BLACK);
				UG_TextboxSetForeColor(&window_page_4_tab_3, TXB_ID_0, C_WHITE);
				UG_TextboxSetText(&window_page_4_tab_3, TXB_ID_0, "www.fnirsi.cn");
				UG_TextboxShow(&window_page_4_tab_3, TXB_ID_0);

				UG_TextboxCreate(&window_page_4_tab_3, &textbox_page4_tab_3_model, TXB_ID_1, 10,120,190,140);
				UG_TextboxSetFont(&window_page_4_tab_3, TXB_ID_1, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4_tab_3, TXB_ID_1, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4_tab_3, TXB_ID_1, 	C_BLACK);
				UG_TextboxSetForeColor(&window_page_4_tab_3, TXB_ID_1, C_WHITE);
				UG_TextboxSetText(&window_page_4_tab_3, TXB_ID_1, "Model: XXXX");
				UG_TextboxShow(&window_page_4_tab_3, TXB_ID_1);

				UG_TextboxCreate(&window_page_4_tab_3, &textbox_page4_tab_3_serial, TXB_ID_2, 10,145,190,165);
				UG_TextboxSetFont(&window_page_4_tab_3, TXB_ID_2, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4_tab_3, TXB_ID_2, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4_tab_3, TXB_ID_2, 	C_BLACK);
				UG_TextboxSetForeColor(&window_page_4_tab_3, TXB_ID_2, C_WHITE);
				UG_TextboxSetText(&window_page_4_tab_3, TXB_ID_2, "Serial No: XXXX");
				UG_TextboxShow(&window_page_4_tab_3, TXB_ID_2);

				UG_TextboxCreate(&window_page_4_tab_3, &textbox_page4_tab_3_version, TXB_ID_3, 10,170,190,190);
				UG_TextboxSetFont(&window_page_4_tab_3, TXB_ID_3, &FONT_12X20);
				UG_TextboxSetAlignment(&window_page_4_tab_3, TXB_ID_3, ALIGN_CENTER_LEFT);
				UG_TextboxSetBackColor(&window_page_4_tab_3, TXB_ID_3, 	C_BLACK);
				UG_TextboxSetForeColor(&window_page_4_tab_3, TXB_ID_3, C_WHITE);
				UG_TextboxSetText(&window_page_4_tab_3, TXB_ID_3, "Version: V-1.01");
				UG_TextboxShow(&window_page_4_tab_3, TXB_ID_3);

//				configuring key menu structure for  page 2

				menu_window[4].window_page = &window_page_4;
				menu_window[4].window_sub_tab_state = sub_tab_avialable;
				menu_window[4].main_window_number_of_settable_id=3;
				menu_window[4].number_of_sub_window=3;

				menu_window[4].sub_window_pages_address[0]=&window_page_4_tab_1;
				menu_window[4].sub_window_pages_address[1]=&window_page_4_tab_2;
				menu_window[4].sub_window_pages_address[2]=&window_page_4_tab_3;
				menu_window[4].sub_window[0]._number_of_settable_id=4;
				menu_window[4].sub_window[0]._id_location[0]=TXB_ID_3;
				menu_window[4].sub_window[0]._id_location[1]=TXB_ID_5;
				menu_window[4].sub_window[0]._id_location[2]=TXB_ID_9;
				menu_window[4].sub_window[0]._id_location[3]=TXB_ID_11;

				for(int i=1;i<3;i++){
				menu_window[4].sub_window[i]._number_of_settable_id=0;
				for(int j=0;j<10;j++){

					menu_window[4].sub_window[i]._id_location[j]=no_id_avialable;
				}
				}

					menu_window[4].window_settable_location_id[0]=TXB_ID_0;
					menu_window[4].window_settable_location_id[1]=TXB_ID_1;
					menu_window[4].window_settable_location_id[2]=TXB_ID_2;

}



void window_page_logo_callback(UG_MESSAGE *msg){}




void main_window_load(uint8_t page_no){

	switch(page_no){

	case 0:
	{
		Page_logo();

		break;}
	case 1:
	{
		Page_1();
		break;
	}
	case 2:
	{
		Page_2();
		break;
	}
	case 3:
	{

		Page_3();
		break;
	}
	case 4:
	{
		Page_4();
		break;
	}
	default:
	{

	}

	}


}

void sub_menu_window_load(uint8_t sub_page_no){


	switch(sub_page_no){

	case 0:
	{
		page_4_tab1();
		break;}
	case 1:
	{
		page_4_tab2();
		break;
	}
	case 2:
	{
		page_4_tab3();
		break;
	}
	default:
	{

	}

	}




}






const uint16_t LOGO_Image [3360]  = {
		 // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░▒▒░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙░░░▒▒▒░░∙∙∙∙∙∙∙∙∙∙░░▒░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░░░░░∙░░░░░∙░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░∙∙∙∙∙∙∙∙░▒▒░░░░░░░░░░░░░░∙░░▒▒▒▒░░░░░∙∙░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙░▒▒▒▒▒▒▒▒░∙∙∙∙∙∙∙∙∙░▒▒▒▒░∙∙∙∙∙∙∙∙∙∙∙∙∙░▒▒▒▒░∙▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░∙∙∙░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒∙▒▒▓▓▓▒▒░░░░░▒▒░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙░░▒▒▒▒▒▒▒▒▒░∙∙∙∙∙∙∙∙∙░▒▒▒▒▒░░∙∙∙∙∙∙∙∙∙∙∙░▒▒▒▒░∙▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░∙░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒∙▒▒▓▒▒▒░░░░░░▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙░▒▒▒▒▒▒▒░░░░∙∙∙∙∙∙∙∙∙∙░▒▒▒▒▒▒░░∙∙∙∙∙∙∙∙∙∙░▒▒▒▒░░▒▒▒▒░∙∙░░░░░░░░░░░░░░░░▒▒▒▒▒░∙░▒▒▒▒▒▒▒░░░░░░░░░░░∙∙∙▒▒▒▒▓▒░░░░░░░░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙░▒▒▒░░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒▒▒▒░░∙∙∙∙∙∙∙∙∙░▒▒▒▒░░▒▒▒▒░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░░▒▒▒▒∙▒▒▒▒░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒░∙∙░░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙▒▒▒░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░▒▒▒░▒▒▒▒░░∙∙∙∙∙∙∙∙░▒▒▒▒░░▒▒▒░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░▒▒▒░░▒▒▒░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙░▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░▒▒▒▒∙░▒▒▒▒░∙∙∙∙∙∙∙∙░▒▒▒░∙░▒▒▒░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░▒▒▒∙░▒▒▒░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░░░░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░▒▒▒▒░░░▒▒▒▒░∙∙∙∙∙∙░░▒▒▒░∙▒▒▒▒░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░░▒▒▒∙▒▒▒▒▒░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒░░░░░░░░░░░░░░░░░░▒▒▒▒░∙░░▒▒▒▒░░∙∙∙∙∙▒▒▒▒░∙▒▒▒▒░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░░▒▒▒▒∙░▒▒▒▒▒▒░░░░░░░░░░░░░∙∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒▒▒▒∙∙∙░░▒▒▒▒▒░∙∙∙░▒▒▒▒░░▒▒▒▒░∙∙∙░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░∙∙░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒∙∙∙∙░░▒▒▒▒▒░∙∙░▒▒▒▒░░▒▒▒▒░∙∙∙▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░∙∙∙░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒░░░░░░░░░░░░░░░░░░▒▒▒▒▒∙∙∙∙∙∙░▒▒▒▒░░∙░▒▒▒▒░░▒▒▒░░∙∙∙░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░∙∙∙∙∙∙∙∙░░░░░▒▒▒░░▒▒▒▒▒▒░∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒∙∙∙∙∙∙∙∙░▒▒▒▒░∙░▒▒▒░∙∙▒▒▒░∙∙∙∙░▒▒▒▒▒▒▒░░░░░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░▒▒▒░∙▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙░░▒▒▒▒░░▒▒▒░∙▒▒▒▒░∙∙∙∙∙░░▒▒▒▒▒▒▒░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░░▒▒▒░▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙░░▒▒▒▒▒▒▒▒░∙▒▒▒▒░∙∙∙∙∙∙∙░░▒▒▒▒▒▒▒░░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░▒▒▒▒░▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙░░▒▒▒▒▒▒▒░∙▒▒▒▒░∙∙∙∙∙∙∙∙∙∙░▒▒▒▒▒▒▒░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░░▒▒▒▒░▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙░▒▒▒▒▒▒░░▒▒▒▒░∙∙∙∙∙∙∙∙∙∙∙∙░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░▒▒▒░∙∙∙∙∙∙∙∙∙∙∙∙░░▒▒▒▒▒░░▒▒▒░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░∙∙▒▒▒▒▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░▒▒░▒∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░▒▒▒░∙∙∙∙∙∙∙∙∙∙∙∙∙∙░▒▒▒░∙░▒▒▒░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░∙∙∙░▒▒▒░∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░░░░∙∙∙░░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙░░░░░░░░░░░░░░░░░░░░░░░░∙∙∙∙∙∙░░░∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6120, 0xd382, 0xdbc3, 0x9221, 0x8000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0186, 0x0a8d, 0x1330, 0x0bf5, 0x04ba, 0x051d, 0x051d, 0x13f4, 0x022c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001f, 0x022e, 0x0bb4, 0x0c76, 0x0b52, 0x0208, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x02b0, 0x0ad1, 0x0c15, 0x0bb4, 0x0210, 0x0000, 0x02b0, 0x0af1, 0x1416, 0x13f5, 0x0a4d, 0x0000, 0x032c, 0x0b32, 0x04ba, 0x053b, 0x053d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x053d, 0x051d, 0x051d, 0x04fc, 0x049b, 0x0459, 0x1373, 0x12f0, 0x120a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0a6c, 0x3412, 0x3bf2, 0x2b70, 0x2331, 0x1b51, 0x1331, 0x0b32, 0x0b53, 0x0b94, 0x0bb4, 0x0bb5, 0x0c16, 0x0438, 0x0c38, 0x0c18, 0x0a8f, 0x0000, 0xf800, 0x9263, 0xcbe5, 0xec04, 0xec03, 0xcbe5, 0x7243, 0x02e5, 0x0be8, 0x0c48, 0x0ba7, 0x0140, 0x0208, 0x1a6c, 0x0129, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0061, 0x0127, 0x12f0, 0x1457, 0x0cdc, 0x0d1c, 0x051d, 0x053d, 0x051c, 0x053c, 0x0d1d, 0x0bf6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1b33, 0x1418, 0x151d, 0x051e, 0x0cbb, 0x1395, 0x020d, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0410, 0x0c78, 0x0cfb, 0x053d, 0x0cfc, 0x03b4, 0x0000, 0x0c78, 0x0cdc, 0x051e, 0x0cfc, 0x1394, 0x2ab0, 0x1c36, 0x14da, 0x051d, 0x051d, 0x0cfd, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051c, 0x051c, 0x051c, 0x051c, 0x051c, 0x051c, 0x051c, 0x0cfc, 0x1479, 0x1393, 0x022e, 0x0000, 0x0000, 0x0000, 0x0210, 0x1352, 0x1416, 0x0cdb, 0x04fd, 0x051e, 0x04fe, 0x04fd, 0x051d, 0x0d1d, 0x0d1d, 0x051c, 0x04fc, 0x051d, 0x051d, 0x051d, 0x053c, 0x053d, 0x053d, 0x1478, 0x0165, 0xbba5, 0xd3c4, 0xf423, 0xfc22, 0xf422, 0xe3e2, 0x8b25, 0x0bc8, 0x04ea, 0x04c9, 0x0ca8, 0x0b6b, 0x1458, 0x0cda, 0x1415, 0x01c7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0064, 0x0a8e, 0x0c16, 0x0d1d, 0x053e, 0x051d, 0x051d, 0x053d, 0x051d, 0x04fc, 0x0d1c, 0x14da, 0x0bd5, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1415, 0x0cba, 0x051d, 0x051d, 0x051d, 0x0cdb, 0x0c16, 0x126e, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x032c, 0x04b9, 0x04fb, 0x051d, 0x04fc, 0x0c17, 0x0000, 0x04f9, 0x051c, 0x04fd, 0x04fb, 0x0bb3, 0x1aae, 0x1c36, 0x14da, 0x0d1c, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x053d, 0x053d, 0x04fc, 0x1458, 0x0b30, 0x0000, 0x032c, 0x0c37, 0x04bb, 0x053d, 0x053d, 0x053d, 0x053d, 0x053d, 0x0d1c, 0x051c, 0x0cfb, 0x0cfb, 0x0cfb, 0x0cfb, 0x0cfb, 0x0cfb, 0x0cfc, 0x0cfb, 0x0cfb, 0x0cda, 0x1436, 0x0124, 0xc3a6, 0xdc04, 0xec43, 0xe443, 0xec43, 0xdbc3, 0x7345, 0x0c08, 0x04c9, 0x0cc9, 0x0489, 0x0c31, 0x051c, 0x0cfc, 0x1478, 0x01c9, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x12ae, 0x0c58, 0x051d, 0x051d, 0x0cdb, 0x1499, 0x0c58, 0x0c78, 0x0417, 0x0375, 0x02f2, 0x024e, 0x014a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1436, 0x04db, 0x051d, 0x051d, 0x053d, 0x053d, 0x0cfa, 0x1436, 0x0af1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x220c, 0x04ba, 0x04fc, 0x051d, 0x04fc, 0x0436, 0x4208, 0x04da, 0x04fc, 0x051d, 0x04ba, 0x0bd3, 0x0000, 0x0189, 0x02d1, 0x0394, 0x03f6, 0x03f6, 0x03d6, 0x03d6, 0x03d6, 0x03d6, 0x03d6, 0x03d6, 0x03d7, 0x03d7, 0x03f7, 0x0418, 0x0418, 0x0c39, 0x0c79, 0x14da, 0x051c, 0x051d, 0x0c99, 0x0c16, 0x0000, 0x1bb3, 0x0cba, 0x051c, 0x051c, 0x14fb, 0x0cba, 0x0cda, 0x0478, 0x0395, 0x0333, 0x02b0, 0x020d, 0x022d, 0x022d, 0x022d, 0x022d, 0x022e, 0x020e, 0x020e, 0x020d, 0x01ab, 0x0000, 0xa2e1, 0xdbe3, 0xf423, 0xf402, 0xec23, 0xcbc4, 0x5305, 0x0c28, 0x0ca9, 0x0ca9, 0x0c28, 0x0b0d, 0x13f6, 0x0bf5, 0x02f1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c34, 0x04fc, 0x053d, 0x0cba, 0x0bf6, 0x022e, 0x02aa, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1c36, 0x04fb, 0x053d, 0x053d, 0x0d3d, 0x051d, 0x051d, 0x0cdb, 0x13f6, 0x0b10, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x19ce, 0x0cbb, 0x051c, 0x051d, 0x04bb, 0x0bd6, 0x4208, 0x04fb, 0x051c, 0x051d, 0x0c79, 0x1394, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x02aa, 0x13d4, 0x04dc, 0x051d, 0x051c, 0x051c, 0x0010, 0x0c9a, 0x051d, 0x053d, 0x047a, 0x0bf6, 0x02aa, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8000, 0x9ac3, 0xd3e4, 0xdc04, 0xbb84, 0x92c3, 0x2940, 0x02a5, 0x0b06, 0x0306, 0x0387, 0x0000, 0x0186, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c78, 0x051d, 0x051c, 0x1417, 0x1416, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1436, 0x051c, 0x051d, 0x04b9, 0x0395, 0x0cdb, 0x0d1c, 0x051d, 0x0cfb, 0x1416, 0x1313, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x122b, 0x04db, 0x053d, 0x051d, 0x0499, 0x0413, 0x3186, 0x04fa, 0x051d, 0x051d, 0x0c17, 0x1352, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x124c, 0x0cfb, 0x051d, 0x051d, 0x0439, 0x1a6c, 0x0cdb, 0x051d, 0x051d, 0x0bf6, 0x1b33, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1021, 0x0821, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0496, 0x0c5a, 0x051d, 0x053d, 0x2436, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0417, 0x1437, 0x051d, 0x053d, 0x0cba, 0x114a, 0x0b52, 0x0cfb, 0x051c, 0x053d, 0x0cfb, 0x03d5, 0x020c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0ad0, 0x04dc, 0x053d, 0x051d, 0x0417, 0x0000, 0x1313, 0x051b, 0x051d, 0x051c, 0x13b3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1acf, 0x051c, 0x051d, 0x051d, 0x1124, 0x1332, 0x04fc, 0x051d, 0x051c, 0x1394, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0410, 0x02cf, 0x0b72, 0x0bb3, 0x0332, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0459, 0x049a, 0x051c, 0x0cfc, 0x2457, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1416, 0x1458, 0x051d, 0x051d, 0x04da, 0x02aa, 0x0372, 0x0bd5, 0x0cda, 0x053d, 0x053c, 0x0cfb, 0x0bd6, 0x0186, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x02aa, 0x0c37, 0x04fc, 0x053d, 0x051c, 0x03f7, 0x0000, 0x0499, 0x04fc, 0x051d, 0x051c, 0x1394, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x12b0, 0x13f6, 0x04fe, 0x051e, 0x051d, 0x18c6, 0x1499, 0x0cfb, 0x053d, 0x051c, 0x0c9a, 0x228b, 0x0208, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c59, 0x04bb, 0x053e, 0x051d, 0x0c99, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0459, 0x049a, 0x051d, 0x04dc, 0x0c58, 0x0bd5, 0x0bf6, 0x0bf6, 0x0bf5, 0x0bf5, 0x0bf5, 0x0c15, 0x0c15, 0x0c16, 0x0c15, 0x0bf6, 0x0bf5, 0x0bf5, 0x0bd5, 0x0bd4, 0x1394, 0x1331, 0x1bd4, 0x0c79, 0x051d, 0x04fc, 0x04bb, 0x02aa, 0x0000, 0x0a4f, 0x0bd6, 0x04db, 0x053c, 0x053c, 0x04fc, 0x1436, 0x0290, 0x0000, 0x0000, 0x0000, 0x0000, 0x018c, 0x047a, 0x04fc, 0x053d, 0x04fc, 0x0416, 0x0010, 0x04da, 0x051c, 0x051d, 0x04db, 0x13b4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x01ce, 0x0b11, 0x1416, 0x0c99, 0x051d, 0x051d, 0x04fc, 0x0000, 0x1b92, 0x0c78, 0x051d, 0x051d, 0x051d, 0x0cdc, 0x0c79, 0x0c37, 0x1437, 0x0c37, 0x0c37, 0x1437, 0x0c17, 0x1417, 0x1416, 0x1c16, 0x13f5, 0x0b94, 0x02f3, 0x02aa, 0x0000, 0x0000, 0x0000, 0x0cda, 0x04db, 0x04fc, 0x0cdb, 0x1499, 0x000a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c3a, 0x04bc, 0x051e, 0x051d, 0x051c, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051c, 0x053d, 0x0cdb, 0x1c37, 0x1394, 0x04ba, 0x053c, 0x04fb, 0x0c9a, 0x0010, 0x0000, 0x0000, 0x1a6c, 0x0c37, 0x0cbb, 0x051d, 0x051d, 0x0cdb, 0x0c37, 0x02f0, 0x0000, 0x0000, 0x0000, 0x2249, 0x04bb, 0x04fc, 0x051d, 0x04fc, 0x0417, 0x52aa, 0x04fb, 0x051c, 0x051d, 0x04ba, 0x13b4, 0x0000, 0x0000, 0x0000, 0x0ab1, 0x13b4, 0x1436, 0x1478, 0x1478, 0x1478, 0x1478, 0x1478, 0x1478, 0x1478, 0x1478, 0x1478, 0x1478, 0x1c98, 0x14da, 0x14db, 0x0cfc, 0x051c, 0x053c, 0x0c99, 0x0b95, 0x0000, 0x0000, 0x0bd5, 0x0c79, 0x0cfc, 0x0d1d, 0x051d, 0x051d, 0x051d, 0x051d, 0x053d, 0x053d, 0x053d, 0x053d, 0x053d, 0x051d, 0x051d, 0x0cfc, 0x0cfc, 0x1499, 0x0bd4, 0x026f, 0x0000, 0x0000, 0x04fb, 0x051c, 0x051d, 0x0cfb, 0x1499, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c3a, 0x04fc, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x053d, 0x051d, 0x051d, 0x051d, 0x14ba, 0x13f6, 0x1bd5, 0x04dc, 0x053d, 0x04fb, 0x0cb9, 0x001f, 0x0000, 0x0000, 0x0000, 0x02b2, 0x1416, 0x0cdb, 0x051d, 0x053d, 0x0cdb, 0x1457, 0x2370, 0x0000, 0x0000, 0x224d, 0x04db, 0x051c, 0x051d, 0x04db, 0x0437, 0x4208, 0x04fb, 0x04fd, 0x051d, 0x0479, 0x1373, 0x0000, 0x0000, 0x0000, 0x0c79, 0x0cfb, 0x051c, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051c, 0x053d, 0x051d, 0x0cfc, 0x1458, 0x0b94, 0x02b0, 0x0000, 0x0000, 0x0010, 0x02b0, 0x0b94, 0x1437, 0x1c58, 0x1458, 0x0c79, 0x0c9a, 0x0cba, 0x04fc, 0x051c, 0x051c, 0x051c, 0x051d, 0x053d, 0x053d, 0x051c, 0x053d, 0x14da, 0x13f6, 0x02d0, 0x0000, 0x04db, 0x051d, 0x051d, 0x0cdb, 0x1479, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c3a, 0x051c, 0x051c, 0x0c79, 0x23b4, 0x2371, 0x2b91, 0x2b91, 0x2b91, 0x2b91, 0x2b91, 0x2b71, 0x2b71, 0x2b71, 0x2b91, 0x2371, 0x2b72, 0x2b72, 0x2b72, 0x2351, 0x128d, 0x02aa, 0x1457, 0x04fd, 0x051d, 0x0cbb, 0x0c59, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x018c, 0x13b3, 0x04db, 0x051d, 0x051e, 0x0cfb, 0x0c16, 0x0372, 0x0000, 0x19ca, 0x04db, 0x051d, 0x051d, 0x049a, 0x0416, 0x3186, 0x04fb, 0x051d, 0x051d, 0x0c37, 0x13b3, 0x0000, 0x0000, 0x0000, 0x03f7, 0x04fb, 0x053c, 0x053d, 0x051d, 0x053d, 0x051d, 0x051c, 0x04fc, 0x04fc, 0x04fc, 0x051c, 0x051c, 0x051c, 0x051d, 0x0c99, 0x1bd5, 0x1b10, 0x032c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0010, 0x02aa, 0x0333, 0x0333, 0x0415, 0x0415, 0x055a, 0x055a, 0x049b, 0x0a6e, 0x2310, 0x3c15, 0x0c79, 0x0cfb, 0x053d, 0x051e, 0x1499, 0x1417, 0x0000, 0x04fb, 0x053d, 0x053c, 0x14da, 0x1437, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c5a, 0x051d, 0x053d, 0x2436, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1458, 0x051d, 0x053d, 0x0cbb, 0x014a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0b73, 0x0d1b, 0x051d, 0x051d, 0x0cfb, 0x0bb4, 0x0000, 0x1a69, 0x04fb, 0x051e, 0x053d, 0x0417, 0x0000, 0x2945, 0x04fb, 0x051d, 0x051d, 0x1394, 0x0000, 0x0000, 0x0000, 0x0000, 0x11cc, 0x1457, 0x0d1b, 0x051c, 0x053d, 0x053d, 0x053c, 0x04ba, 0x0373, 0x122d, 0x2b50, 0x3350, 0x2aad, 0x3186, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c57, 0x053d, 0x0cfc, 0x0cdb, 0x0311, 0x0000, 0x04fc, 0x051d, 0x053c, 0x149a, 0x000c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c5a, 0x047a, 0x051d, 0x051c, 0x2c77, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c77, 0x0c99, 0x051d, 0x051d, 0x0cbb, 0x018c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0311, 0x0c15, 0x0cda, 0x051d, 0x0d1d, 0x0cfb, 0x13d3, 0x0b54, 0x0cdb, 0x053d, 0x053d, 0x03d6, 0x0000, 0x0499, 0x051c, 0x051d, 0x051c, 0x13b4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0331, 0x0394, 0x14b8, 0x0d1b, 0x053d, 0x053d, 0x051d, 0x0cfd, 0x0c99, 0x13b4, 0x220c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1335, 0x0bf7, 0x051d, 0x051c, 0x0cfb, 0x0373, 0x04dc, 0x051c, 0x051d, 0x051c, 0x14ba, 0x000a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c5a, 0x049b, 0x051d, 0x0cfb, 0x2c77, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1477, 0x0cba, 0x051d, 0x051c, 0x0c9a, 0x0186, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1a70, 0x13f6, 0x0cba, 0x053d, 0x051d, 0x04db, 0x0479, 0x051c, 0x051d, 0x051c, 0x0416, 0x0000, 0x04da, 0x04fc, 0x051d, 0x04fb, 0x1393, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x032c, 0x13b3, 0x1477, 0x0cfb, 0x051d, 0x051d, 0x053d, 0x051d, 0x04ba, 0x13f5, 0x0b73, 0x0410, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x03f5, 0x0499, 0x053d, 0x0cfc, 0x0cba, 0x02f2, 0x04fc, 0x04fd, 0x051d, 0x051b, 0x149a, 0x0010, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c59, 0x04db, 0x051d, 0x0cfb, 0x2c77, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1457, 0x0cdb, 0x051d, 0x04fc, 0x0c9a, 0x0208, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x02b1, 0x0bf7, 0x0cba, 0x053d, 0x051d, 0x053c, 0x053d, 0x053d, 0x04fb, 0x0bf6, 0x0000, 0x04fb, 0x051c, 0x051d, 0x04db, 0x1373, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x020c, 0x1392, 0x0c78, 0x04fb, 0x051c, 0x051d, 0x053d, 0x051c, 0x0cdb, 0x1436, 0x0332, 0x018c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0290, 0x0418, 0x04db, 0x053c, 0x0cfb, 0x0c9a, 0x0210, 0x04fc, 0x04fd, 0x051d, 0x0cfb, 0x149a, 0x0010, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c59, 0x04dc, 0x053d, 0x14ba, 0x2436, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1457, 0x04fc, 0x051d, 0x04dc, 0x0c79, 0x000a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x018c, 0x0bf5, 0x04fb, 0x051d, 0x051e, 0x051d, 0x053d, 0x04da, 0x0415, 0x4208, 0x04fb, 0x051d, 0x051d, 0x0499, 0x1393, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0150, 0x0394, 0x0c58, 0x0cdb, 0x051c, 0x051d, 0x051d, 0x0d1c, 0x0cba, 0x0cba, 0x04fb, 0x04db, 0x04fc, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051d, 0x051c, 0x051c, 0x053c, 0x04fb, 0x04da, 0x04ba, 0x0cda, 0x0cfc, 0x051d, 0x053c, 0x0cba, 0x0c37, 0x0000, 0x051c, 0x051d, 0x051d, 0x0cfb, 0x149a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0c59, 0x04fc, 0x053d, 0x1c78, 0x2456, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1416, 0x04fc, 0x053d, 0x04db, 0x0c38, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0410, 0x0b94, 0x0cda, 0x053c, 0x051d, 0x051d, 0x0c79, 0x0415, 0x318c, 0x051b, 0x051d, 0x051d, 0x0c57, 0x0bd4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x018c, 0x0b74, 0x1416, 0x04fb, 0x051c, 0x053c, 0x053d, 0x053d, 0x051d, 0x051d, 0x051d, 0x053d, 0x053d, 0x053d, 0x053d, 0x053d, 0x053d, 0x053d, 0x053d, 0x053d, 0x053d, 0x053d, 0x053d, 0x053d, 0x053d, 0x051d, 0x051d, 0x04fe, 0x051d, 0x053d, 0x051c, 0x0cdc, 0x03b6, 0x01ce, 0x0000, 0x051c, 0x051d, 0x053c, 0x0cdb, 0x1458, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1b73, 0x0cfb, 0x14fb, 0x1bb4, 0x2c15, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0b72, 0x14fb, 0x0d3b, 0x1478, 0x1b95, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1b31, 0x0cba, 0x0d3d, 0x1499, 0x0af1, 0x001f, 0x02aa, 0x1498, 0x0d1c, 0x0d1b, 0x0bb3, 0x0410, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3186, 0x0bd5, 0x0cba, 0x0cfc, 0x0d1c, 0x0d1c, 0x0d1c, 0x0d1c, 0x0cfc, 0x0d1c, 0x0cfc, 0x0cfc, 0x0d1c, 0x0cfc, 0x0cfc, 0x0cfc, 0x0cfc, 0x0cfc, 0x0cfc, 0x0d1c, 0x0d1c, 0x0cfc, 0x0d1c, 0x0d1c, 0x0cfb, 0x0cdc, 0x04bb, 0x1416, 0x1aad, 0x0000, 0x0000, 0x0000, 0x0bd4, 0x14fb, 0x0d1c, 0x1477, 0x2313, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x01ea, 0x024d, 0x024c, 0x020a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x020c, 0x01ec, 0x020c, 0x01ca, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0210, 0x024e, 0x0353, 0x0a6e, 0x0000, 0x0000, 0x0000, 0x026c, 0x024d, 0x020d, 0x0208, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x02aa, 0x0a0d, 0x022d, 0x022d, 0x024e, 0x022e, 0x022e, 0x022e, 0x022e, 0x026e, 0x026f, 0x02b1, 0x0290, 0x026f, 0x022e, 0x024f, 0x022e, 0x022d, 0x024d, 0x022c, 0x0a2c, 0x0a4c, 0x12ad, 0x52aa, 0x0010, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x02ae, 0x022d, 0x022d, 0x022b, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
		    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};







const UG_BMP sound =     // Construct the BMP structure with the Image data
{
    (void*)Sound_Image,   // Data Image
    32,                // Image Width
    16,                // Image Heigth
    BMP_BPP_16,        // BPPs = 16Bit => 2*8bit
    BMP_RGB565         // Use RGB888 for RGB 24Bits BMP Image, RBG565 for 16bits
};



const uint16_t Sound_Image [512] = {
    // ∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙████∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙████∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙█████∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙█████████████████∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙█████████████████∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙█████████∙███████∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙█████████∙∙██████∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙█████████∙∙██████∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙█████████∙███████∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙█████████████████∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙█████████████████∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙█████∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙████∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙███∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

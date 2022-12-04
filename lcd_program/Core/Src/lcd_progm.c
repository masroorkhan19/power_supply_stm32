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

UG_COLOR color[3]= {C_RED, C_GREEN, C_BLUE};
char bufferOut[BuffOUT];
char char_buffer[16];


UG_OBJECT obj_buff_wnd_1[MAX_OBJECTS];
UG_WINDOW window_1;
UG_WINDOW *active_window_ptr;
UG_BUTTON button_0;

 UG_WINDOW window_page_1;
 UG_TEXTBOX current_V_graphic_page_1;
 UG_TEXTBOX current_V_graphic_page_2;
 UG_TEXTBOX current_V2_graphic;
 UG_TEXTBOX current_CV_graphic;
 UG_TEXTBOX current_I_graphic_page_1;
 UG_TEXTBOX current_I_graphic_page_2;
 UG_TEXTBOX current_I2_graphic;
 UG_TEXTBOX current_CC_graphic;
 UG_TEXTBOX current_W_graphic;
 UG_TEXTBOX current_W2_graphic;
 UG_TEXTBOX current_CW_graphic;
 UG_TEXTBOX WD_graphic;
 UG_TEXTBOX website_graphic;

 UG_WINDOW window_page_2;
 UG_IMAGE image_2;
 UG_OBJECT obj_buff_window_page_2[MAX_OBJECTS_WIN_GRAPH];
UG_TEXTBOX dummy_text_1;
UG_TEXTBOX dummy_text_2;
UG_TEXTBOX dummy_text_3;
UG_TEXTBOX dummy_text_4;
UG_TEXTBOX dummy_text_5;
UG_TEXTBOX dummy_text_6;
UG_TEXTBOX dummy_text_7;
UG_TEXTBOX dummy_text_8;
UG_TEXTBOX dummy_text_9;
UG_TEXTBOX dummy_text_10;
UG_TEXTBOX dummy_text_11;


 UG_TEXTBOX temp_graphic;
 UG_TEXTBOX current_T_graphic;

 UG_TEXTBOX USBC_graphic;
 UG_TEXTBOX USBB_graphic;

 UG_TEXTBOX set_V_graphic_page_1;
 UG_TEXTBOX set_V_graphic_page_2;
 UG_TEXTBOX set_I_graphic_page_1;
 UG_TEXTBOX set_I_graphic_page_2;

 UG_TEXTBOX set_V_graphic_value_page_1;
 UG_TEXTBOX set_V_graphic_value_page_2;
 UG_TEXTBOX set_I_graphic_value_page_1;
 UG_TEXTBOX set_I_graphic_value_page_2;

 UG_OBJECT obj_buff_window_page_1[MAX_OBJECTS_WIN_GRAPH];


 //page 0
 UG_WINDOW window_page_0;
 UG_TEXTBOX OK_graphic;
 UG_TEXTBOX CV_graphic;
 UG_TEXTBOX CC_graphic;
 UG_OBJECT obj_buff_window_page_0[MAX_OBJECTS_WIN_GRAPH];



//page logo
 UG_WINDOW LOGO;
 UG_OBJECT obj_buff_window_logo[MAX_OBJECTS_WIN_GRAPH];
 UG_IMAGE image_1;

//
 //page 3
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





 void Page_0(void){


//	    	UG_WindowHide(&LOGO);
//	 	    UG_Update();


	 	    UG_WindowShow(&window_page_0);
	 	    UG_Update();
	 //UG_DrawFrame(0, 0, DISPLAY_WIDTH-1, DISPLAY_HEIGHT-1, C_LIGHT_GRAY);     // Draw a Frame
	 //	    HAL_Delay(10);

	 	    //Some Texts
	 //	    UG_FontSelect(&FONT_8X14);
	 //	    UG_SetBackcolor(C_BLACK);
	 //	    UG_SetForecolor(C_YELLOW);
	 //	    sprintf(bufferOut,"TFT 2,4\" (%dx%d)", XSIZE_PHYS, YSIZE_PHYS);
	 //	    UG_PutString(5, 5 , bufferOut);
	 //	    UG_FontSelect(&FONT_8X14);
	 //	    UG_SetBackcolor(C_BLACK);
	 //	    UG_SetForecolor(C_YELLOW);
	 //	    UG_PutString(5, 23, "STM32f103RB and ST7789");


	 //	    active_window_ptr=&window_1;
	 //	    // Create the window
	 //	    UG_WindowCreate(&window_1, obj_buff_wnd_1, MAX_OBJECTS, window_1_callback);
	 //	    // Window Title
	 //
	 //	    UG_WindowSetTitleText(&window_1, "Window \xe6GUI v0.31");      //  \xhh : Special CHR the ASCII value is given by hh interpreted as a hexadecimal number (Check FONT Table)
	 //	    UG_WindowSetTitleTextFont(&window_1, &FONT_8X14);
	 //	    UG_WindowSetXStart(&window_1, 25);
	 //	    UG_WindowSetYStart(&window_1, 50);
	 //	    UG_WindowSetXEnd(&window_1, 300);       // Window 175x250
	 //	    UG_WindowSetYEnd(&window_1, 220);
	 //	    UG_WindowSetBackColor(&window_1, C_BLACK);
	 //	    UG_WindowSetStyle(&window_1,WND_STYLE_2D | WND_STYLE_SHOW_TITLE);
	 //
	 //	    //button
	 //	    UG_ButtonCreate(&window_1, &button_0, BTN_ID_0, 10,10, 110, 30);
	 //	    UG_ButtonSetBackColor(&window_1, BTN_ID_0, C_RED);
	 //	    UG_ButtonSetForeColor(&window_1, BTN_ID_0, C_YELLOW);
	 //	    UG_ButtonSetFont(&window_1, BTN_ID_0, &FONT_8X14);
	 //	    UG_ButtonSetText(&window_1, BTN_ID_0, "button");
	 //	    UG_ButtonShow(&window_1, BTN_ID_0);
	 //	    UG_WindowShow(&window_1);
	 //	    UG_Update();
	 //	    HAL_Delay(5000);
	 //	   // UG_ButtonHide(&window_1, BTN_ID_0);
	 //	    UG_WindowHide(active_window_ptr);
	 //	    UG_Update();

	 ///////////////////graph window



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

	 	 //	    UG_DrawLine(5, 40, 315, 40, C_WHITE);
	 	 //	    UG_DrawLine(5, 55, 315, 55, C_WHITE);
	 	 //	    UG_DrawLine(5, 70, 315, 70, C_WHITE);
	 	 //	    UG_DrawLine(5, 85, 315, 85, C_WHITE);
	 	 //	    UG_DrawLine(5, 100, 315, 100, C_WHITE);
	 	 //	    UG_DrawLine(5, 115, 315, 115, C_WHITE);
	 	 //	    UG_DrawLine(5, 115, 315, 115, C_WHITE);


	 	 	    for(int i=0;i<4;i++){
	 	 	    	UG_DrawLine(5, 150+i, 315, 150+i, C_YELLOW);
	 	 	    }

	 	 	    for(int i=0;i<4;i++){
	 	 	   	 	 UG_DrawLine(5, 180+i, 315, 180+i, C_GREEN);
	 	 	   	}






 }

 void Page_1(){
	 	 	 	///////////////////graph window

//	 	 	 	UG_WindowHide(&window_graph);
//		 	    UG_Update();

		 	    UG_WindowShow(&window_page_1);
		 		UG_Update();

	 	        UG_DrawLine(215, 0, 215, 239, C_WHITE);
	 	   	  	UG_DrawLine(215, 73, 319, 73, C_WHITE);
	 	   	  	UG_DrawLine(215, 141, 319, 141, C_WHITE);
 }


 void Page_2(void){

 //				UG_WindowHide(&);
 //		 	    UG_Update();


 		 	    UG_WindowShow(&window_page_2);
 		 	    UG_Update();

 		 	    UG_DrawLine(104, 23, 104, 239, C_WHITE);
 		 	    UG_DrawLine(0, 95, 104, 95, C_WHITE);
 		 	    UG_DrawLine(0, 167, 104, 167, C_WHITE);


 }

 void Page_3(){

	 UG_WindowShow(&window_page_3);
	 		 		UG_Update();
	 		     //  UG_DrawLine(215, 0, 215, 239, C_WHITE);
	 		 	 	   	UG_DrawLine(0, 32, 319, 32, C_WHITE);
	 		 	 	 	UG_DrawLine(160, 32, 160, 196, C_WHITE);
	 		 	 	   	UG_DrawLine(0, 196, 319, 196, C_WHITE);

 }


void Page_logo(void){

//				UG_WindowHide(&);
//		 	    UG_Update();

		 	    UG_WindowShow(&LOGO);
		 	    UG_Update();
		 	    UG_DrawLine(105, 79, 221, 79, C_AQUA);
}



void begin(void){
	//Page 0
				UG_WindowCreate(&window_page_0, obj_buff_window_page_0, MAX_OBJECTS_WIN_GRAPH, window_page_0_callback);
		 	    UG_WindowSetStyle(&window_page_0, WND_STYLE_2D | WND_STYLE_HIDE_TITLE);
		 	    UG_WindowSetBackColor(&window_page_0, C_BLACK);

		 	    /////////////ok //
		 	    UG_TextboxCreate(&window_page_0, &OK_graphic, TXB_ID_0, 0, 5, 70, 35);
		 	    UG_TextboxSetFont(&window_page_0, TXB_ID_0, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_0, TXB_ID_0, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_0, TXB_ID_0, C_GREEN);
		 	    UG_TextboxSetForeColor(&window_page_0, TXB_ID_0, C_BLACK);
		 	    UG_TextboxSetText(&window_page_0, TXB_ID_0, "OK");
		 	    UG_TextboxShow(&window_page_0, TXB_ID_0);

		 	    ////////////CV//
		 	    UG_TextboxCreate(&window_page_0, &CV_graphic, TXB_ID_1, 75, 5, 105, 35);
		 	    UG_TextboxSetFont(&window_page_0, TXB_ID_1, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_0, TXB_ID_1, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_0, TXB_ID_1, C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_0, TXB_ID_1, C_BLACK);
		 	    UG_TextboxSetText(&window_page_0, TXB_ID_1, "CV");
		 	    UG_TextboxShow(&window_page_0, TXB_ID_1);
		 	    ////////////CC//
		 	    UG_TextboxCreate(&window_page_0, &CC_graphic, TXB_ID_2, 110, 5, 140, 35);
		 	    UG_TextboxSetFont(&window_page_0, TXB_ID_2, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_0, TXB_ID_2, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_0, TXB_ID_2, 	C_DIM_GRAY);
		 	    UG_TextboxSetForeColor(&window_page_0, TXB_ID_2, C_BLACK);
		 	    UG_TextboxSetText(&window_page_0, TXB_ID_2, "CC");
		 	    UG_TextboxShow(&window_page_0, TXB_ID_2);



		 	    UG_ImageCreate(&window_page_0, &image_1, IMG_ID_1,145, 8, 160,32);
		 	   	UG_ImageSetBMP(&window_page_0, IMG_ID_1, &logo_FNIRSI);

		 	    UG_TextboxCreate(&window_page_0, &current_V_graphic_page_1, TXB_ID_3, 1, 40, 73,60);
		 	    UG_TextboxSetFont(&window_page_0, TXB_ID_3, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_0, TXB_ID_3, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_0, TXB_ID_3, 	C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_0, TXB_ID_3, C_BLACK);
		 	    UG_TextboxSetText(&window_page_0, TXB_ID_3, "12.10V");
		 	    UG_TextboxShow(&window_page_0, TXB_ID_3);

		 	    UG_TextboxCreate(&window_page_0, &current_I_graphic_page_1, TXB_ID_4, 1, 63, 73,83);
		 	    UG_TextboxSetFont(&window_page_0, TXB_ID_4, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_0, TXB_ID_4, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_0, TXB_ID_4, 	C_GREEN);
		 	    UG_TextboxSetForeColor(&window_page_0, TXB_ID_4, C_BLACK);
		 	    UG_TextboxSetText(&window_page_0, TXB_ID_4, "0.000A");
		 	    UG_TextboxShow(&window_page_0, TXB_ID_4);

		 	    UG_TextboxCreate(&window_page_0, &set_V_graphic_page_1, TXB_ID_5, 0, 218, 76, 238);
		 	    UG_TextboxSetFont(&window_page_0, TXB_ID_5, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_0, TXB_ID_5, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_0, TXB_ID_5, 	C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_0, TXB_ID_5, C_WHITE);
		 	    UG_TextboxSetText(&window_page_0, TXB_ID_5, "SET V:");
		 	    UG_TextboxShow(&window_page_0, TXB_ID_5);

		 	    UG_TextboxCreate(&window_page_0, &set_V_graphic_value_page_1, TXB_ID_6, 80, 218, 156, 238);
		 	    UG_TextboxSetFont(&window_page_0, TXB_ID_6, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_0, TXB_ID_6, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_0, TXB_ID_6, 	C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_0, TXB_ID_6, C_BLACK);
		 	    UG_TextboxSetText(&window_page_0, TXB_ID_6, "00.00V");
		 	    UG_TextboxShow(&window_page_0, TXB_ID_6);

		 	    UG_TextboxCreate(&window_page_0, &set_I_graphic_page_1, TXB_ID_7, 162, 218, 238, 238);
		 	    UG_TextboxSetFont(&window_page_0, TXB_ID_7, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_0, TXB_ID_7, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_0, TXB_ID_7, 	C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_0, TXB_ID_7, C_WHITE);
		 	    UG_TextboxSetText(&window_page_0, TXB_ID_7, "SET I:");
		 	    UG_TextboxShow(&window_page_0, TXB_ID_7);

		 	    UG_TextboxCreate(&window_page_0, &set_I_graphic_value_page_1, TXB_ID_8, 242, 218, 318, 238);
		 	    UG_TextboxSetFont(&window_page_0, TXB_ID_8, &FONT_12X20);
		 	    UG_TextboxSetAlignment(&window_page_0, TXB_ID_8, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_0, TXB_ID_8, 	C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_0, TXB_ID_8, C_BLACK);
		 	    UG_TextboxSetText(&window_page_0, TXB_ID_8, "0.000A");
		 	    UG_TextboxShow(&window_page_0, TXB_ID_8);

		 	   //	 	 	    UG_FontSelect(&FONT_12X20);
 		 	   //	 	 	    UG_SetBackcolor(C_YELLOW);
		 	   //	 	 	    UG_SetForecolor(C_BLACK);
		 	   //	 	 	    UG_PutString(1 , 40 ,"12.10V");
		 	   //
		 	   //	 	 	    UG_SetBackcolor(C_GREEN);
		 	   //	 	 	    UG_SetForecolor(C_BLACK);
		 	   //	 	 	    UG_PutString(1 , 64 , "00.00A");
		 	   //
		 	   //	 	 	    UG_SetBackcolor(C_DIM_GRAY);
		 	   //	 	 	    UG_SetForecolor(C_BLACK);
		 	   //	 	   	    UG_PutString(0 , 219 ,"SET V:");
		 	   //
			   //	 	 	  	UG_SetBackcolor(C_YELLOW);
			   //	 	   	    UG_SetForecolor(C_BLACK);
			   //	 	  	    UG_PutString(76 , 219 ,"12.10V");
		 	   //
		 	   //	 	   	    UG_SetBackcolor(C_DIM_GRAY);
		 	   //	 	   	    UG_SetForecolor(C_BLACK);
		 	   //	 	 	  	UG_PutString(165 , 219 , "SET I:");
		 	   //
		 	   //	 	   	    UG_SetBackcolor(C_GREEN);
		 	   //	 	   	    UG_SetForecolor(C_BLACK);
		 	   //	 	   	    UG_PutString(242 , 219 , "00.00A");
	//Page 1
	 	 	 	UG_WindowCreate(&window_page_1, obj_buff_window_page_1, MAX_OBJECTS_WIN_GRAPH, window_page_1_callback);
		 	    UG_WindowSetStyle(&window_page_1, WND_STYLE_2D | WND_STYLE_HIDE_TITLE);
		 	    UG_WindowSetBackColor(&window_page_1, C_BLACK);

		 	    /////////////Current Voltage //
		   	    UG_TextboxCreate(&window_page_1, &current_CV_graphic, TXB_ID_3, 0, 10, 210, 26);
		  	    UG_TextboxSetFont(&window_page_1, TXB_ID_3, &FONT_10X16);
		 	   	UG_TextboxSetAlignment(&window_page_1, TXB_ID_3, ALIGN_CENTER_LEFT);
		 	   	UG_TextboxSetBackColor(&window_page_1, TXB_ID_3, C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_3, C_BLACK);
		  	    UG_TextboxSetText(&window_page_1, TXB_ID_3, "VOLTS");
		 	   	UG_TextboxShow(&window_page_1, TXB_ID_3);

		 	    UG_TextboxCreate(&window_page_1, &current_V_graphic_page_2, TXB_ID_4, 0, 31, 181, 71);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_4, &FONT_24X40);
	  	 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_4, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_4, C_DIM_GRAY);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_4, C_WHITE);
		  	    UG_TextboxSetText(&window_page_1, TXB_ID_4, "00.00");
		  	    UG_TextboxShow(&window_page_1, TXB_ID_4);

		 	    UG_TextboxCreate(&window_page_1, &current_V2_graphic, TXB_ID_5, 186, 27, 210, 71);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_5, &FONT_24X40);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_5, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_5, C_YELLOW);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_5, C_BLACK);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_5, "V");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_5);

		 	    ////////////Current Current//
		   	    UG_TextboxCreate(&window_page_1, &current_CC_graphic, TXB_ID_6, 0, 76, 210, 92);
		  	    UG_TextboxSetFont(&window_page_1, TXB_ID_6, &FONT_10X16);
		 	   	UG_TextboxSetAlignment(&window_page_1, TXB_ID_6, ALIGN_CENTER_LEFT);
		 	   	UG_TextboxSetBackColor(&window_page_1, TXB_ID_6, C_GREEN);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_6, C_BLACK);
		  	    UG_TextboxSetText(&window_page_1, TXB_ID_6, "AMPS");
		 	   	UG_TextboxShow(&window_page_1, TXB_ID_6);

		 	    UG_TextboxCreate(&window_page_1, &current_I_graphic_page_2, TXB_ID_7, 0, 97, 181, 137);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_7, &FONT_24X40);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_7, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_7, C_DIM_GRAY);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_7, C_WHITE);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_7, "0.000");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_7);

		 	    UG_TextboxCreate(&window_page_1, &current_I2_graphic, TXB_ID_8, 186, 93, 210, 137);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_8, &FONT_24X40);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_8, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_8, C_GREEN);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_8, C_BLACK);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_8, "I");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_8);

		 	    ////////////power//
		   	    UG_TextboxCreate(&window_page_1, &current_CW_graphic, TXB_ID_9, 0, 142, 210, 158);
		  	    UG_TextboxSetFont(&window_page_1, TXB_ID_9, &FONT_10X16);
		 	   	UG_TextboxSetAlignment(&window_page_1, TXB_ID_9, ALIGN_CENTER_LEFT);
		 	   	UG_TextboxSetBackColor(&window_page_1, TXB_ID_9, C_VIOLET);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_9, C_BLACK);
		  	    UG_TextboxSetText(&window_page_1, TXB_ID_9, "WATTS");
		 	   	UG_TextboxShow(&window_page_1, TXB_ID_9);

		 	    UG_TextboxCreate(&window_page_1, &current_W_graphic, TXB_ID_10, 0, 163, 181, 203);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_10, &FONT_24X40);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_10, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_10, C_DIM_GRAY);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_10, C_WHITE);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_10, "200.0");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_10);

		 	    UG_TextboxCreate(&window_page_1, &current_W2_graphic, TXB_ID_11, 186, 159, 210, 203);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_11, &FONT_24X40);
		 	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_11, ALIGN_CENTER);
		 	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_11, C_VIOLET);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_11, C_BLACK);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_11, "W");
		 	    UG_TextboxShow(&window_page_1, TXB_ID_11);



		 	    ////////////Temp//
		 	    UG_TextboxCreate(&window_page_1, &temp_graphic, TXB_ID_12, 220, 10, 318, 26);
		 	  	UG_TextboxSetFont(&window_page_1, TXB_ID_12, &FONT_10X16);
		 	  	UG_TextboxSetAlignment(&window_page_1, TXB_ID_12, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_1, TXB_ID_12, 	C_ORANGE);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_12, C_BLACK);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_12, "TEMP C");
		 	  	UG_TextboxShow(&window_page_1, TXB_ID_12);

		 	    UG_TextboxCreate(&window_page_1, &current_T_graphic, TXB_ID_13, 220, 31, 318, 71);
		 	    UG_TextboxSetFont(&window_page_1, TXB_ID_13, &FONT_12X20);
		  	    UG_TextboxSetAlignment(&window_page_1, TXB_ID_13, ALIGN_CENTER);
		  	    UG_TextboxSetBackColor(&window_page_1, TXB_ID_13, C_DIM_GRAY);
		  	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_13, C_WHITE);
		   	    UG_TextboxSetText(&window_page_1, TXB_ID_13, "24.5");
		   	    UG_TextboxShow(&window_page_1, TXB_ID_13);

		 	    ////////////USB//
		        UG_TextboxCreate(&window_page_1, &USBC_graphic, TXB_ID_14, 220, 76, 318, 107);
		   	    UG_TextboxSetFont(&window_page_1, TXB_ID_14, &FONT_12X20);
		   	   	UG_TextboxSetAlignment(&window_page_1, TXB_ID_14, ALIGN_CENTER);
		   	   	UG_TextboxSetBackColor(&window_page_1, TXB_ID_14, C_GREEN_YELLOW);
		   	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_14, C_BLACK);
		   	    UG_TextboxSetText(&window_page_1, TXB_ID_14, "USB C");
		  	   	UG_TextboxShow(&window_page_1, TXB_ID_14);

		  	    UG_TextboxCreate(&window_page_1, &USBB_graphic, TXB_ID_15, 220, 109, 318, 137);
		  	  	UG_TextboxSetFont(&window_page_1, TXB_ID_15, &FONT_12X20);
		  	  	UG_TextboxSetAlignment(&window_page_1, TXB_ID_15, ALIGN_CENTER);
		   	   	UG_TextboxSetBackColor(&window_page_1, TXB_ID_15, C_DIM_GRAY);
		   	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_15, C_WHITE);
	    	    UG_TextboxSetText(&window_page_1, TXB_ID_15, "USB B");
		   	   	UG_TextboxShow(&window_page_1, TXB_ID_15);

		 	    UG_TextboxCreate(&window_page_1, &set_V_graphic_page_2, TXB_ID_16, 220, 143, 318, 159);
		 	  	UG_TextboxSetFont(&window_page_1, TXB_ID_16, &FONT_10X16);
		 	  	UG_TextboxSetAlignment(&window_page_1, TXB_ID_16, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_1, TXB_ID_16, 	C_VIOLET);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_16, C_BLACK);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_16, "SET V");
		 	  	UG_TextboxShow(&window_page_1, TXB_ID_16);

		 	    UG_TextboxCreate(&window_page_1, &set_V_graphic_value_page_2, TXB_ID_17, 220, 163, 318, 185);
		 	  	UG_TextboxSetFont(&window_page_1, TXB_ID_17, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_1, TXB_ID_17, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_1, TXB_ID_17, 	C_DIM_GRAY);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_17, C_WHITE);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_17, "00.00");
		 	  	UG_TextboxShow(&window_page_1, TXB_ID_17);

		 	    UG_TextboxCreate(&window_page_1, &set_I_graphic_page_2, TXB_ID_18, 220, 190, 318, 206);
		 	  	UG_TextboxSetFont(&window_page_1, TXB_ID_18, &FONT_10X16);
		 	  	UG_TextboxSetAlignment(&window_page_1, TXB_ID_18, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_1, TXB_ID_18, 	C_VIOLET);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_18, C_BLACK);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_18, "SET I");
		 	  	UG_TextboxShow(&window_page_1, TXB_ID_18);

		 	    UG_TextboxCreate(&window_page_1, &set_I_graphic_value_page_2, TXB_ID_19, 220, 209, 318, 231);
		 	  	UG_TextboxSetFont(&window_page_1, TXB_ID_19, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_1, TXB_ID_19, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_1, TXB_ID_19, 	C_DIM_GRAY);
		 	    UG_TextboxSetForeColor(&window_page_1, TXB_ID_19, C_WHITE);
		 	    UG_TextboxSetText(&window_page_1, TXB_ID_19, "0.000");
		 	  	UG_TextboxShow(&window_page_1, TXB_ID_19);

	//Page 2
		 		UG_WindowCreate(&window_page_2, obj_buff_window_page_2, MAX_OBJECTS_WIN_GRAPH, window_page_2_callback);
				UG_WindowSetStyle(&window_page_2, WND_STYLE_2D | WND_STYLE_SHOW_TITLE);
				UG_WindowSetBackColor(&window_page_2, C_BLACK);

				UG_WindowSetTitleColor(&window_page_2, C_BLACK); //title ending line is 22 pixel in height
				UG_WindowSetTitleTextColor(&window_page_2, C_ORANGE);
				UG_WindowSetTitleTextAlignment(&window_page_2, ALIGN_CENTER);
				UG_WindowSetTitleText(&window_page_2,"Window");
				UG_WindowSetTitleTextFont(&window_page_2,&FONT_12X20);

//				UG_ImageCreate(&window_page_2, &image_2, IMG_ID_0,115, 50, 146,65);
//				UG_ImageSetBMP(&window_page_2, IMG_ID_0, &sound);

		 	    UG_TextboxCreate(&window_page_2, &dummy_text_1, TXB_ID_1, 1,1,102,70);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_1, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_1, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_1, 	C_ORANGE);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_1, C_WHITE);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_1, "PS\n Configuration");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_1);


		 	    UG_TextboxCreate(&window_page_2, &dummy_text_2, TXB_ID_2, 1,73,102,142);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_2, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_2, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_2, 	C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_2, C_WHITE);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_2, "Tab_2");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_2);


		 	    UG_TextboxCreate(&window_page_2, &dummy_text_3, TXB_ID_3, 1,146,102,215);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_3, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_3, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_3, 	C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_3, C_WHITE);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_3, "Tab_3");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_3);



		 	    UG_TextboxCreate(&window_page_2, &dummy_text_4, TXB_ID_4, 120,34,210,50);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_4, &FONT_10X16);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_4, ALIGN_CENTER_LEFT);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_4, 	C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_4, C_WHITE);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_4, "Voltage");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_4);

		 	    UG_TextboxCreate(&window_page_2, &dummy_text_5, TXB_ID_5, 220,34,310,50);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_5, &FONT_10X16);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_5, ALIGN_CENTER_LEFT);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_5, 	C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_5, C_WHITE);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_5, "Ampere");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_5);

		 	    UG_TextboxCreate(&window_page_2, &dummy_text_6, TXB_ID_6, 115,55,210,95);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_6, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_6, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_6, 	C_ORANGE);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_6, C_BLACK);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_6, "00.00V");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_6);

		 	    UG_TextboxCreate(&window_page_2, &dummy_text_7, TXB_ID_7, 215,55,310,95);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_7, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_7, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_7, 	C_ORANGE);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_7, C_BLACK);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_7, "0.000A");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_7);



		 	    UG_TextboxCreate(&window_page_2, &dummy_text_8, TXB_ID_8, 120,120,210,140);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_8, &FONT_10X16);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_8, ALIGN_CENTER_LEFT);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_8, 	C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_8, C_WHITE);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_8, "Watts");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_8);

		 	    UG_TextboxCreate(&window_page_2, &dummy_text_9, TXB_ID_9, 220,120,310,140);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_9, &FONT_10X16);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_9, ALIGN_CENTER_LEFT);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_9, 	C_BLACK);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_9, C_WHITE);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_9, "Temp");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_9);

		 	    UG_TextboxCreate(&window_page_2, &dummy_text_10, TXB_ID_10, 115,145,210,185);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_10, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_10, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_10, 	C_ORANGE);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_10, C_BLACK);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_10, "000W");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_10);

		 	    UG_TextboxCreate(&window_page_2, &dummy_text_11, TXB_ID_11, 215,145,310,185);
		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_11, &FONT_12X20);
		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_11, ALIGN_CENTER);
		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_11, 	C_ORANGE);
		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_11, C_BLACK);
		 	    UG_TextboxSetText(&window_page_2, TXB_ID_11, "50 C");
		 	  	UG_TextboxShow(&window_page_2, TXB_ID_11);




//		 	    UG_TextboxCreate(&window_page_2, &dummy_text_6, TXB_ID_6, 125,34,210,50);
//		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_6, &FONT_10X16);
//		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_6, ALIGN_CENTER);
//		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_6, 	C_BLACK);
//		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_6, C_WHITE);
//		 	    UG_TextboxSetText(&window_page_2, TXB_ID_6, "dummy");
//		 	  	UG_TextboxShow(&window_page_2, TXB_ID_6);
//
//		 	    UG_TextboxCreate(&window_page_2, &dummy_text_7, TXB_ID_7, 125,34,210,50);
//		 	  	UG_TextboxSetFont(&window_page_2, TXB_ID_7, &FONT_10X16);
//		 	  	UG_TextboxSetAlignment(&window_page_2, TXB_ID_7, ALIGN_CENTER);
//		 	  	UG_TextboxSetBackColor(&window_page_2, TXB_ID_7, 	C_BLACK);
//		 	    UG_TextboxSetForeColor(&window_page_2, TXB_ID_7, C_WHITE);
//		 	    UG_TextboxSetText(&window_page_2, TXB_ID_7, "dummy");
//		 	  	UG_TextboxShow(&window_page_2, TXB_ID_7);






	//Logo
		 		UG_WindowCreate(&LOGO, obj_buff_window_logo, MAX_OBJECTS_WIN_GRAPH, window_logo_callback);
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
///////////////////////page 3

					 //page 3
								UG_WindowCreate(&window_page_3, obj_buff_window_page_3, MAX_OBJECTS_WIN_PAGE_3, window_page_3_callback);
								UG_WindowSetStyle(&window_page_3, WND_STYLE_2D | WND_STYLE_HIDE_TITLE);
								UG_WindowSetBackColor(&window_page_3, C_BLACK);
								/////////////power mode //
								UG_TextboxCreate(&window_page_3, &textbox_pe, TXB_ID_0, 5, 5, 65, 27);
								UG_TextboxSetFont(&window_page_3, TXB_ID_0, &FONT_10X16);
								UG_TextboxSetAlignment(&window_page_3, TXB_ID_0, ALIGN_CENTER);
								UG_TextboxSetBackColor(&window_page_3, TXB_ID_0, C_YELLOW);
								UG_TextboxSetForeColor(&window_page_3, TXB_ID_0, C_BLACK);
								UG_TextboxSetText(&window_page_3, TXB_ID_0, "PE2.0");
								UG_TextboxShow(&window_page_3, TXB_ID_0);


				            ///
								UG_TextboxCreate(&window_page_3, &textbox_temp, TXB_ID_1, 180, 5, 225, 27);
								UG_TextboxSetFont(&window_page_3, TXB_ID_1, &FONT_10X16);
								UG_TextboxSetAlignment(&window_page_3, TXB_ID_1, ALIGN_CENTER);
								UG_TextboxSetBackColor(&window_page_3, TXB_ID_1, C_YELLOW);
								UG_TextboxSetForeColor(&window_page_3, TXB_ID_1, C_BLACK);
								UG_TextboxSetText(&window_page_3, TXB_ID_1, "TEMP");
								UG_TextboxShow(&window_page_3, TXB_ID_1);

								// temp value
								UG_TextboxCreate(&window_page_3, &textbox_temp_value, TXB_ID_2, 230, 5, 290, 27);
								UG_TextboxSetFont(&window_page_3, TXB_ID_2, &FONT_10X16);
								UG_TextboxSetAlignment(&window_page_3, TXB_ID_2, ALIGN_CENTER);
								UG_TextboxSetBackColor(&window_page_3, TXB_ID_2, C_BLACK);
								UG_TextboxSetForeColor(&window_page_3, TXB_ID_2, C_YELLOW);

								UG_TextboxShow(&window_page_3, TXB_ID_2);

								// temp symbol
								UG_TextboxCreate(&window_page_3, &textbox_temp_symbol, TXB_ID_3, 295, 5, 310, 27);
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

								UG_TextboxSetText(&window_page_3, TXB_ID_18, "OK");
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


}



void window_page_1_callback(UG_MESSAGE *msg){

}
void window_page_0_callback(UG_MESSAGE *msg){}

void window_logo_callback(UG_MESSAGE *msg){}

void window_page_2_callback(UG_MESSAGE *msg){}









const UG_BMP logo_FNIRSI =     // Construct the BMP structure with the Image data
{
    (void*)LOGO_Image,   // Data Image
    140,                // Image Width
    24,                // Image Heigth
    BMP_BPP_16,        // BPPs = 16Bit => 2*8bit
    BMP_RGB565         // Use RGB888 for RGB 24Bits BMP Image, RBG565 for 16bits
};


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

/*
 * page_3_callback_imp.c
 *
 *  Created on: Dec 3, 2022
 *      Author: mkhan
 */
#include "page_3_callback_imp.h"
#include "buck_convertor.h"
#include "stdio.h"


int hour_value,mint,sec=0;

void window_page_3_callback(UG_MESSAGE *msg){



	if(msg->type==MSG_TYPE_OBJECT){

		if(msg->id==OBJ_TYPE_TEXTBOX){
		switch (msg->sub_id){
		case 0:           //charging protocol
		{
			if (sw3516_current.charging_protocol == 0x00){
							sprintf(char_buffer,"Basic");
							UG_TextboxSetText(&window_page_3, TXB_ID_0, char_buffer);
			}
			else if(sw3516_current.charging_protocol == 0x1){
							sprintf(char_buffer,"QC2.0");
							UG_TextboxSetText(&window_page_3, TXB_ID_0, char_buffer);
			}
			else if (sw3516_current.charging_protocol == 0x2){
							sprintf(char_buffer,"QC3.0");
							UG_TextboxSetText(&window_page_3, TXB_ID_0, char_buffer);
			}
			else if (sw3516_current.charging_protocol == 0x3){
							sprintf(char_buffer,"FCP");
							UG_TextboxSetText(&window_page_3, TXB_ID_0, char_buffer);
			}
			else if (sw3516_current.charging_protocol == 0x4){
							sprintf(char_buffer,"SCP");
							UG_TextboxSetText(&window_page_3, TXB_ID_0, char_buffer);
			}
			else if (sw3516_current.charging_protocol == 0x5){
							sprintf(char_buffer,"PD FIX");
							UG_TextboxSetText(&window_page_3, TXB_ID_0, char_buffer);
			}
			else if (sw3516_current.charging_protocol == 0x6){
							sprintf(char_buffer,"PD PPS");
							UG_TextboxSetText(&window_page_3, TXB_ID_0, char_buffer);
			}
			else if (sw3516_current.charging_protocol == 0x7){
							sprintf(char_buffer,"PE1.1");
							UG_TextboxSetText(&window_page_3, TXB_ID_0, char_buffer);
			}
			else if (sw3516_current.charging_protocol == 0x8){
							sprintf(char_buffer,"PE2.0");
							UG_TextboxSetText(&window_page_3, TXB_ID_0, char_buffer);
			}
			else if (sw3516_current.charging_protocol == 0x9){
							sprintf(char_buffer,"VOOC");
							UG_TextboxSetText(&window_page_3, TXB_ID_0, char_buffer);
			}
			else if (sw3516_current.charging_protocol == 0xA){
							sprintf(char_buffer,"SFCP");
							UG_TextboxSetText(&window_page_3, TXB_ID_0, char_buffer);
			}

			break;
		}
		case 2:           //temperature value
				{
					sprintf(char_buffer,"%.02f",sw3516_current.temperature);
												UG_TextboxSetText(&window_page_3, TXB_ID_2, char_buffer);
					break;
				}
		case 4:          //usbc
				{
					if(sw3516_current.status_USBC){
					UG_TextboxSetBackColor(&window_page_3, TXB_ID_4, C_YELLOW);
					}
					else{
						UG_TextboxSetBackColor(&window_page_3, TXB_ID_4, C_LIGHT_GRAY);

					}
					break;
						}
		case 5:           //usba
				{
					if(sw3516_current.status_USBA){
					   UG_TextboxSetBackColor(&window_page_3, TXB_ID_5, C_YELLOW);
												}
					else{
						UG_TextboxSetBackColor(&window_page_3, TXB_ID_5, C_LIGHT_GRAY);

												}
					break;

				}
		case 6:          // voltage usbc
		{
			if(sw3516_current.status_USBC){
				sprintf(char_buffer,"%.02f",(sw3516_current.voltageout/1000));
				UG_TextboxSetText(&window_page_3, TXB_ID_6, char_buffer);
			}
			else
			{
				UG_TextboxSetText(&window_page_3, TXB_ID_6, "00.00");
			}
					break;
		}
		case 8:        // voltage usba
				{
					if(sw3516_current.status_USBA){
						sprintf(char_buffer,"%.02f",(sw3516_current.voltageout/1000));
						UG_TextboxSetText(&window_page_3, TXB_ID_8, char_buffer);
					}
					else
					{
						UG_TextboxSetText(&window_page_3, TXB_ID_8, "00.00");
					}
					break;
				}

		case 10:      // current usbc
				{
					if(sw3516_current.status_USBC){
						sprintf(char_buffer,"%.02f",(sw3516_current.currentC/1000));
						UG_TextboxSetText(&window_page_3, TXB_ID_10, char_buffer);
					}
					else
					{
						UG_TextboxSetText(&window_page_3, TXB_ID_10, "00.00");
					}
					break;
						}

		case 12:    // current usb
		{
			if(sw3516_current.status_USBA){
				sprintf(char_buffer,"%.02f",(sw3516_current.currentA/1000));
				UG_TextboxSetText(&window_page_3, TXB_ID_12, char_buffer);
			}
			else
			{
				UG_TextboxSetText(&window_page_3, TXB_ID_12, "00.00");
			}

			break;
		}

		case 14:  // watta usbc
				{
					if(sw3516_current.status_USBC){
						sprintf(char_buffer,"%.02f",(sw3516_current.voltageout/1000)*(sw3516_current.currentC/1000));
						UG_TextboxSetText(&window_page_3, TXB_ID_14, char_buffer);
					}
					else
					{
						UG_TextboxSetText(&window_page_3, TXB_ID_14, "00.00");
					}

					break;
				}

		case 16:   //watt usba
				{
					if(sw3516_current.status_USBA){
						sprintf(char_buffer,"%.02f",(sw3516_current.voltageout/1000)*(sw3516_current.currentA/1000));
						UG_TextboxSetText(&window_page_3, TXB_ID_16, char_buffer);
					}
					else
					{
						UG_TextboxSetText(&window_page_3, TXB_ID_16, "00.00");
					}
					break;
						}

		case 18:   // OK status
		{
			if(buck_convertor_current.status_ok ==1){
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_18, C_GREEN);
			}
			else
			{
				UG_TextboxSetBackColor(&window_page_3, TXB_ID_18, C_RED);
			}
			break;
		}
		case 19:  // cv status
				{
					if(buck_convertor_current.status_cv ==1){
						UG_TextboxSetBackColor(&window_page_3, TXB_ID_19, C_YELLOW);
					}
					else
					{
						UG_TextboxSetBackColor(&window_page_3, TXB_ID_19, C_LIGHT_GRAY);
					}
					break;
				}
		case 20:  //cc status
				{
					if(buck_convertor_current.status_cv ==1){
						UG_TextboxSetBackColor(&window_page_3, TXB_ID_20, C_YELLOW);
					}
					else
					{
						UG_TextboxSetBackColor(&window_page_3, TXB_ID_20, C_LIGHT_GRAY);
					}
					break;
				}
		case 21:   // buck voltage value
				{
					if(buck_convertor_current.buck_on_off){
						sprintf(char_buffer,"%.02f",(buck_convertor_current.voltageout_output/1000));
						UG_TextboxSetText(&window_page_3, TXB_ID_21, char_buffer);
					}
					else
					{
						UG_TextboxSetText(&window_page_3, TXB_ID_21, "00.00");
					}
					break;
				}
		case 23:  // buck current value
				{
					if(buck_convertor_current.buck_on_off){
						sprintf(char_buffer,"%.02f",(buck_convertor_current.current_output/1000));
						UG_TextboxSetText(&window_page_3, TXB_ID_23, char_buffer);
					}
					else
					{
						UG_TextboxSetText(&window_page_3, TXB_ID_23, "00.00");
					}

					break;

				}
		case 25:{
				hour_value=(int)(sw3516_current.time_in_secs_C)/3600;

				mint=(int)((sw3516_current.time_in_secs_C%3600)/60);
				sec=(sw3516_current.time_in_secs_C)%60;

				sprintf(char_buffer,"%02d:%02d:%02d",hour_value,mint,sec);
			UG_TextboxSetText(&window_page_3, TXB_ID_25, char_buffer);
			break;
		}

		case 26:{
			hour_value=(int)(sw3516_current.time_in_secs_A)/3600;
			mint=(int)((sw3516_current.time_in_secs_A%3600)/60);
			sec=(sw3516_current.time_in_secs_A)%60;
			sprintf(char_buffer,"%02d:%02d:%02d",hour_value,mint,sec);
			UG_TextboxSetText(&window_page_3, TXB_ID_26, char_buffer);
			break;

		 }
		}
	}
}



//	if((msg->cid[0][0])&0x01) {
//
//    HAL_Delay(500);
//
//   }

   //   if(msg->cid[1][0]) {
   //
   //
   //
   //    }
   //   if(msg->cid[2][0]) {
   //
   //
   //
   //     }

   }

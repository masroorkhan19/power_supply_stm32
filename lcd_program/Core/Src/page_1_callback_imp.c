/*
 * page_1_callback_imp.c
 *
 *  Created on: Dec 8, 2022
 *      Author: Syed Mir Hamza
 */

#include "ugui.h"
#include "page_3_callback_imp.h"
#include "buck_convertor.h"
#include "stdio.h"

void window_page_1_callback(UG_MESSAGE *msg){



	if(msg->type==MSG_TYPE_OBJECT){

		if(msg->id==OBJ_TYPE_TEXTBOX){
		switch (msg->sub_id){

		case 2:     //temperature value
				{
					sprintf(char_buffer,"%.02f",buck_convertor_current.temperature);
					UG_TextboxSetText(&window_page_3, TXB_ID_2, char_buffer);
					break;
				}
		case 4:
				{

					break;
						}
		case 5:
				{

					break;

				}
		case 6:
		{

					break;
		}
		case 8:
				{

					break;
				}

		case 10:
				{

					break;
				}

		case 12:
				{

					break;
				}

		case 14:
				{

					break;
				}

		case 16:
				{

					break;
				}

		case 18:
				{

					break;
				}
		case 19:
				{

					break;
				}
		case 20:
				{

					break;
				}
		case 21:
				{

					break;
				}
		case 23:
				{

					break;
				}
		case 25:{

					break;
				}
		case 26:{

					break;
				}

		}
		}

	}
}

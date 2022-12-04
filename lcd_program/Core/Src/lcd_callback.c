/*
 * lcd_callback.c
 *
 *  Created on: Dec 3, 2022
 *      Author: mkhan
 */


#include "lcd_callback.h"
#include "ugui.h"
#include "lcd_progm.h"
#include "stdbool.h"
#include "SW3516.h"
#include "buck_convertor.h"



void usb_charging_page_msg( ){
	UG_MESSAGE page_msg={2,2,0,0,&obj_buff_window_page_3};

if(guiST7735.active_window == &window_page_3){


	if(sw3516_current.temperature!=sw3516_previous.temperature){
		page_msg.event =2;
		page_msg.sub_id=2;
		 window_page_3_callback(&page_msg);
		 UG_Update();



	    }
	 if(sw3516_current.status_USBC!=sw3516_previous.status_USBC){
		 page_msg.event =2;
		 		page_msg.sub_id=4;
		 		 window_page_3_callback(&page_msg);

	        }
		if(sw3516_current.time_in_secs_C!=sw3516_previous.time_in_secs_C){
			 page_msg.event =2;
				 		page_msg.sub_id=25;
				 		 window_page_3_callback(&page_msg);

		          }


    if(sw3516_current.status_USBA!=sw3516_previous.status_USBA){
		 page_msg.event =2;
			 		page_msg.sub_id=5;
			 		 window_page_3_callback(&page_msg);

      }

    if(sw3516_current.time_in_secs_A!=sw3516_previous.time_in_secs_A){
    		 page_msg.event =2;
    			 		page_msg.sub_id=26;
    			 		 window_page_3_callback(&page_msg);

    	          }

    if(sw3516_current.voltageout!=sw3516_previous.voltageout){
		 page_msg.event =2;
			 		page_msg.sub_id=6;
			 		 window_page_3_callback(&page_msg);


			 		 page_msg.event =2;
			 					 		page_msg.sub_id=8;
			 					 		 window_page_3_callback(&page_msg);


			 					 	   	 page_msg.event =2;
			 					 	   	page_msg.sub_id=14;
			 					 	   	window_page_3_callback(&page_msg);


			 					 	   	 page_msg.event =2;
			 					 	   	page_msg.sub_id=16;
			 					 	   	window_page_3_callback(&page_msg);



             }

    if(sw3516_current.currentC!=sw3516_previous.currentC){
    	 page_msg.event =2;
    	page_msg.sub_id=10;
    	window_page_3_callback(&page_msg);



   	 page_msg.event =2;
   	page_msg.sub_id=14;
   	window_page_3_callback(&page_msg);

    }
    if(sw3516_current.currentA!=sw3516_previous.currentA){
   	 page_msg.event =2;
   	page_msg.sub_id=12;
   	window_page_3_callback(&page_msg);



  	 page_msg.event =2;
  	page_msg.sub_id=16;
  	window_page_3_callback(&page_msg);



        }
    ////////////
    if(buck_convertor_current.status_ok!=buck_convertor_pervious.status_ok){
      	 page_msg.event =2;
      	page_msg.sub_id=18;
      	window_page_3_callback(&page_msg);

            }
    if(buck_convertor_current.status_cv!=buck_convertor_pervious.status_cv){
      	 page_msg.event =2;
      	page_msg.sub_id=19;
      	window_page_3_callback(&page_msg);

              }
    if(buck_convertor_current.status_cc!=buck_convertor_pervious.status_cc){
      	 page_msg.event =2;
      	page_msg.sub_id=20;
      	window_page_3_callback(&page_msg);

                  }
    if(buck_convertor_current.voltageout_output!=buck_convertor_pervious.voltageout_output){
      	 page_msg.event =2;
      	page_msg.sub_id=21;
      	window_page_3_callback(&page_msg);

                        }
    if(buck_convertor_current.current_output!=buck_convertor_pervious.current_output){
      	 page_msg.event =2;
      	page_msg.sub_id=23;
      	window_page_3_callback(&page_msg);

                     }



}


}








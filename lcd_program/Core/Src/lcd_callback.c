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


typedef struct {

	bool flag;
}usb_status_;

usb_status_ usb_status_A={false};
usb_status_ usb_status_C={false};

void usb_charging_page_msg( ){
	UG_MESSAGE page_msg={2,2,0,0,&obj_buff_window_page_3};
if(menu_.lcd_first_time_load_flage){
	uint8_t id_update[17]={0,2,4,25,5,26,6,8,10,12,14,16,18,19,20,21,23};

	for(uint8_t i=0;i<17;i++){
		page_msg.event =2;
				page_msg.sub_id= id_update[i];
				 window_page_3_callback(&page_msg);
	}

}
if(guiST7735.active_window == menu_.current_window.window_page && menu_.lcd_first_time_load_flage==0){

	if(sw3516_current.charging_protocol != sw3516_previous.charging_protocol){
			page_msg.event =2;
			page_msg.sub_id=0;
			 window_page_3_callback(&page_msg);
			 UG_Update();
		    }
	if(sw3516_current.temperature!=sw3516_previous.temperature){
		page_msg.event =2;
		page_msg.sub_id=2;
		 window_page_3_callback(&page_msg);
		 UG_Update();
	    }
	 if(sw3516_current.status_USBC!=sw3516_previous.status_USBC ){
		 page_msg.event =2;
		 		page_msg.sub_id=4;
		 		 window_page_3_callback(&page_msg);
		 		 UG_Update();

	        }
		if(sw3516_current.time_in_secs_C!=sw3516_previous.time_in_secs_C){
			 page_msg.event =2;
				 		page_msg.sub_id=25;
				 		 window_page_3_callback(&page_msg);
				 		 UG_Update();
		          }


    if(sw3516_current.status_USBA!=sw3516_previous.status_USBA){
		 page_msg.event =2;
			 		page_msg.sub_id=5;
			 		 window_page_3_callback(&page_msg);
			 		 UG_Update();

      }

    if(sw3516_current.time_in_secs_A!=sw3516_previous.time_in_secs_A){
    		 page_msg.event =2;
    			 		page_msg.sub_id=26;
    			 		 window_page_3_callback(&page_msg);
    			 		 UG_Update();
    	          }

    if(sw3516_current.voltageout!=sw3516_previous.voltageout){
    	if(sw3516_current.status_USBC || sw3516_current.status_USBC!=sw3516_previous.status_USBC){
		 page_msg.event =2;
		page_msg.sub_id=6;
		window_page_3_callback(&page_msg);

		UG_Update();

    	}
    	if(sw3516_current.status_USBA || sw3516_current.status_USBA!=sw3516_previous.status_USBA){
		page_msg.event =2;
		page_msg.sub_id=8;
		window_page_3_callback(&page_msg);

		UG_Update();
    	}
             }



    if((sw3516_current.currentC!=sw3516_previous.currentC && sw3516_current.status_USBC) || sw3516_current.status_USBC!=sw3516_previous.status_USBC){

    	 page_msg.event =2;
    	page_msg.sub_id=10;
    	window_page_3_callback(&page_msg);
    	UG_Update();

    }
    if((sw3516_current.currentA!=sw3516_previous.currentA && sw3516_current.status_USBA) ||  sw3516_current.status_USBA!=sw3516_previous.status_USBA){
   	 page_msg.event =2;
   	page_msg.sub_id=12;
   	window_page_3_callback(&page_msg);
  	UG_Update();
        }

    if(((sw3516_current.voltageout!=sw3516_previous.voltageout || sw3516_current.currentC!=sw3516_previous.currentC) && sw3516_current.status_USBC) || sw3516_current.status_USBC!=sw3516_previous.status_USBC){

		page_msg.event =2;
		page_msg.sub_id=14;
		window_page_3_callback(&page_msg);
		UG_Update();
    }
    if(((sw3516_current.voltageout!=sw3516_previous.voltageout || sw3516_current.currentA!=sw3516_previous.currentA) && sw3516_current.status_USBA) || sw3516_current.status_USBA!=sw3516_previous.status_USBA){

		page_msg.event =2;
		page_msg.sub_id=16;
		window_page_3_callback(&page_msg);
		UG_Update();
      }



    ////////////
    if(buck_convertor_current.buck_on_off!=buck_convertor_pervious.buck_on_off){
      	 page_msg.event =2;
      	page_msg.sub_id=18;
      	window_page_3_callback(&page_msg);
      	 UG_Update();

            }
    if(buck_convertor_current.status_cv!=buck_convertor_pervious.status_cv){
      	 page_msg.event =2;
      	page_msg.sub_id=19;
      	window_page_3_callback(&page_msg);
      	 UG_Update();

              }
    if(buck_convertor_current.status_cc!=buck_convertor_pervious.status_cc){
      	 page_msg.event =2;
      	page_msg.sub_id=20;
      	window_page_3_callback(&page_msg);
      	 UG_Update();

                  }
    if(buck_convertor_current.voltageout_output!=buck_convertor_pervious.voltageout_output){
      	 page_msg.event =2;
      	page_msg.sub_id=21;
      	window_page_3_callback(&page_msg);
      	 UG_Update();

                        }
    if(buck_convertor_current.current_output!=buck_convertor_pervious.current_output){
      	 page_msg.event =2;
      	page_msg.sub_id=23;
      	window_page_3_callback(&page_msg);
      	 UG_Update();

                     }

    sw3516_previous= sw3516_current;

}


}


void buck_page_msg(){
UG_MESSAGE page_msg={2,2,0,0,&obj_buff_window_page_2};

if(menu_.lcd_first_time_load_flage){
	uint8_t id_update[9]={2,4,7,10,16,19,21,22,23};

	for(uint8_t i=0;i<9;i++){
		page_msg.event =2;
				page_msg.sub_id= id_update[i];
				 window_page_2_callback(&page_msg);
	}

}


if(guiST7735.active_window == &window_page_2  && menu_.lcd_first_time_load_flage==0){

		////////////////buck converter/////////////////
	if(buck_convertor_current.temperature!=buck_convertor_pervious.temperature){
	page_msg.event =2;
	page_msg.sub_id=2;
	window_page_2_callback(&page_msg);
	UG_Update();
	   }
    if(buck_convertor_current.voltageout_output!=buck_convertor_pervious.voltageout_output){
      page_msg.event =2;
      page_msg.sub_id=4;
      window_page_2_callback(&page_msg);
      UG_Update();
                        }
    if(buck_convertor_current.voltageout_set!=buck_convertor_pervious.voltageout_set){
      page_msg.event =2;
      page_msg.sub_id=16;
      window_page_2_callback(&page_msg);
      UG_Update();
                        }
    if(buck_convertor_current.current_output!=buck_convertor_pervious.current_output){
      page_msg.event =2;
      page_msg.sub_id=7;
      window_page_2_callback(&page_msg);
      UG_Update();
    }
    if(buck_convertor_current.current_set!=buck_convertor_pervious.current_set){
          page_msg.event =2;
          page_msg.sub_id=19;
          window_page_3_callback(&page_msg);
          UG_Update();
       }
    if(buck_convertor_current.voltageout_output!=buck_convertor_pervious.voltageout_output || buck_convertor_current.current_output!=buck_convertor_pervious.current_output){
      page_msg.event =2;
      page_msg.sub_id=10;
      window_page_2_callback(&page_msg);
      UG_Update();
              }
    if(buck_convertor_current.status_cv!=buck_convertor_pervious.status_cv){
      page_msg.event =2;
      page_msg.sub_id=21;
      window_page_3_callback(&page_msg);
      UG_Update();
                  }
    if(buck_convertor_current.status_cc!=buck_convertor_pervious.status_cc){
      page_msg.event =2;
      page_msg.sub_id=22;
      window_page_3_callback(&page_msg);
      UG_Update();
                  }
    if(buck_convertor_current.buck_on_off!=buck_convertor_pervious.buck_on_off){
      page_msg.event =2;
      page_msg.sub_id=23;
      window_page_2_callback(&page_msg);
      UG_Update();
            }







//    if(sw3516_current.currentC!=sw3516_previous.currentC && sw3516_current.status_USBC){
//
//    page_msg.event =2;
//    page_msg.sub_id=21;
//    window_page_2_callback(&page_msg);
//    UG_Update();
//
//    }
//    if(buck_convertor_current.status_ok!=buck_convertor_pervious.status_ok){
//      page_msg.event =2;
//      page_msg.sub_id=22;
//      window_page_3_callback(&page_msg);
//      UG_Update();
//        }

    buck_convertor_pervious=buck_convertor_current;
}
}








/*
 * Encoder.c
 *
 *  Created on: Dec 7, 2022
 *      Author: Syed Mir Hamza
 */


#include "Encoder.h"

uint32_t Current_Ticks = 0;
uint32_t Previous_Ticks = 0;
uint32_t Previous_Ticks_flage = 0;
int32_t difference = 0;

int32_t Encoder_Counter = 0;
uint8_t page_load = 1;


int8_t encoder_change(){

	Current_Ticks = ((TIM2->CNT)>>2);

		difference = Current_Ticks - Previous_Ticks_flage;
		Previous_Ticks_flage=Current_Ticks;
		difference=abs(difference);
		if(difference>0){
				return 1;
			}
		else {
				return 0;

			}


}
int8_t Encoder_Ticks_update(){


	Current_Ticks = ((TIM2->CNT)>>2);

	difference = Current_Ticks - Previous_Ticks;

	Previous_Ticks = Current_Ticks;

	if(difference==0){
			Encoder_Counter=0;
		}
	else if(difference>0){
			Encoder_Counter=1;

		}
	else{

		Encoder_Counter=-1;

	}

return Encoder_Counter;





//	if (Encoder_Counter > 3){
//			Encoder_Counter = 1;
//		}
//
//	if (Encoder_Counter < 1 ){
//			Encoder_Counter = 3;
//		}

//	if(Encoder_Counter == 1 && page_load == 1){
//		Page_1();
//		page_load = 0;
//	}
//	if(Encoder_Counter == 2 && page_load == 1){
//		Page_2();
//		page_load = 0;
//	}
//	if(Encoder_Counter == 3 && page_load == 1){
//		Page_3();
//		page_load = 0;
//
//	}




}

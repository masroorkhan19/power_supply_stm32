/*
 * real_time_flow.c
 *
 *  Created on: Dec 7, 2022
 *      Author: mkhan
 */
#include "real_time_flow.h"
#include "pid_with_adc_read.h"
#include "SW3516.h"
#include "pid.h"
struct _update_real   lcd_update_,sw3516_update_,adc_update_={0,0};

TIM_HandleTypeDef htim1;

void program_flow(){

    if(adc_update_._flag || sw3516_update_._flag || lcd_update_._flag){
	if(adc_update_._flag==1){

		read_adc_value();
		PID_Compute(&TPID);
		adc_update_._flag=0;
	}

	if(sw3516_update_._flag==1){


		sw3516_read();
		sw3516_update_._flag=0;
	}
	if(lcd_update_._flag==1){

		usb_charging_page_msg();
		lcd_update_._flag=0;


	}
	HAL_TIM_Base_Start_IT(&htim1);
    }

}







void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{


 if(htim->Instance==TIM1){
	lcd_update_._update_timer_counter++;

	sw3516_update_._update_timer_counter++;
	adc_update_._update_timer_counter++;

	if(lcd_update_._update_timer_counter==lcd_update_timer_value){

		lcd_update_._update_timer_counter=0;
		lcd_update_._flag=1;
	}
	if(sw3516_update_._update_timer_counter == sw3516_update_timer_value){

		sw3516_update_._update_timer_counter=0;
		sw3516_update_._flag=1;
		}

	if(adc_update_._update_timer_counter == adc_update_timer_value){

		adc_update_._update_timer_counter=0;
		adc_update_._flag=1;
		}
	HAL_TIM_Base_Stop_IT(&htim1);
 }

}

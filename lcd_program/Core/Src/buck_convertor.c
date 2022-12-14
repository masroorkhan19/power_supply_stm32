/*
 * buck_convertor.c
 *
 *  Created on: Dec 3, 2022
 *      Author: mkhan
 */
#include "buck_convertor.h"


 TIM_HandleTypeDef htim3;




struct buck_struct buck_convertor_current;  //.={0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,0}
struct buck_struct  buck_convertor_pervious;





void buck_turn_off(){

	pwm_current =0;
	pwm_voltage =0;
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2);
	buck_convertor_current.buck_on_off = 0;


}
void buck_turn_on()
{

	//  TIM3->CCR1=115;
	//  TIM3->CCR2=500;
	pwm_voltage = buck_convertor_current.voltage_pwm_out;
	pwm_current = buck_convertor_current.current_pwm_out;
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	buck_convertor_current.buck_on_off =1;



}

void set_voltage_pwm(){


	buck_convertor_current.voltage_pwm_out = (uint32_t)(buck_convertor_current.voltageout_set)*(htim3.Init.Period)/(3.3*31);


}

void set_current_pwm(){

	buck_convertor_current.current_pwm_out = (uint32_t)(25)*(htim3.Init.Period)/((3.3)*(buck_convertor_current.current_set));

}



/*
 * buck_convertor.h
 *
 *  Created on: Dec 3, 2022
 *      Author: mkhan
 */

#ifndef INC_BUCK_CONVERTOR_H_
#define INC_BUCK_CONVERTOR_H_
#include "stdbool.h"
#include "main.h"


extern TIM_HandleTypeDef htim3;


#define pwm_current TIM3->CCR2
#define pwm_voltage TIM3->CCR1


 struct  buck_struct{

			double current_set;
			double voltageout_set;
			double current_output;
			double voltageout_output;
			double voltagein;
			double temperature;
			bool status_cv;
			bool status_cc;
			uint8_t status_ok;
			bool buck_on_off;
			uint32_t voltage_pwm_out;
			uint32_t current_pwm_out;


};

extern  struct buck_struct buck_convertor_current;
extern  struct buck_struct buck_convertor_pervious;


void buck_turn_off();
void buck_turn_on();
void set_voltage_pwm();
void set_current_pwm();
#endif /* INC_BUCK_CONVERTOR_H_ */

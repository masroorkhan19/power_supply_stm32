/*
 * pid_with_adc_read.h
 *
 *  Created on: Dec 7, 2022
 *      Author: mkhan
 */

#ifndef INC_PID_WITH_ADC_READ_H_
#define INC_PID_WITH_ADC_READ_H_
#include "main.h"
#include "pid.h"
#include "buck_convertor.h"


struct buck_adc_para{

	uint16_t buck_temperature;
	uint16_t buck_voltage;
	uint16_t buck_current;
};


struct buck_cali_para{
	double calibrated_buck_voltage_input;
	double calibrated_buck_temperature;
	double calibrated_buck_voltage_output;
	double calibrated_buck_current_output;
};

extern struct buck_adc_para current_buck_adc_para,prev_buck_adc_para;
extern struct buck_cali_para calibrated_buck_para_value;
#include "main.h"



extern ADC_HandleTypeDef hadc1;
extern PID_TypeDef TPID;


void read_adc_value();




void ouput_current_callibration();
void ouput_voltage_callibration();
void buck_temperature_callibration();



void buck_current_adc();
void buck_voltage_adc();
void buck_temperature_adc();


void  pid_intialize();

#endif /* INC_PID_WITH_ADC_READ_H_ */

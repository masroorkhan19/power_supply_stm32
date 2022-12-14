/*
 * pid_with_adc_read.c
 *
 *  Created on: Dec 7, 2022
 *      Author: mkhan
 */

#include "pid_with_adc_read.h"
#include "buck_convertor.h"


struct buck_adc_para current_buck_adc_para,prev_buck_adc_para;
struct buck_cali_para calibrated_buck_para_value;
 PID_TypeDef TPID;

void read_adc_value(){


	prev_buck_adc_para=current_buck_adc_para;

  if(buck_convertor_current.buck_on_off){
	 buck_current_adc();
	 HAL_ADC_Start(&hadc1);
	 HAL_ADC_PollForConversion(&hadc1, 1);
	 current_buck_adc_para.buck_current = HAL_ADC_GetValue(&hadc1);
	 HAL_ADC_Stop(&hadc1);

	 buck_voltage_adc();
	 HAL_ADC_Start(&hadc1);
	 HAL_ADC_PollForConversion(&hadc1, 1);
	 current_buck_adc_para.buck_voltage = HAL_ADC_GetValue(&hadc1);
	 HAL_ADC_Stop(&hadc1);
	 ouput_current_callibration();
	 ouput_voltage_callibration();
  }
  else{

	  buck_convertor_current.voltageout_output =0;
	  buck_convertor_current.current_output=0;
		buck_convertor_current.status_cc=0;
		buck_convertor_current.status_cv=1;
  }
  buck_temperature_adc();
	 HAL_ADC_Start(&hadc1);
	 HAL_ADC_PollForConversion(&hadc1, 1);
	 current_buck_adc_para.buck_temperature = HAL_ADC_GetValue(&hadc1);
	 HAL_ADC_Stop(&hadc1);
	 buck_temperature_callibration();
}


void ouput_current_callibration(){

      // R=0.01 ohm  shunt resistor
	// I=V/(R*25)
	//   adc*3.3/(4096*R*25)
	calibrated_buck_para_value.calibrated_buck_current_output= (float)((current_buck_adc_para.buck_current)*(3.3))/(1024);
	buck_convertor_current.current_output =calibrated_buck_para_value.calibrated_buck_current_output;
	if(buck_convertor_current.current_output > buck_convertor_current.current_set && buck_convertor_current.buck_on_off){

		buck_convertor_current.status_cc=1;
		buck_convertor_current.status_cv=0;
	}
	else {

		buck_convertor_current.status_cc=0;
		buck_convertor_current.status_cv=1;
	}

}

void ouput_voltage_callibration(){
      // volatage divider (310/10)(adc)(3.3)/4096

	calibrated_buck_para_value.calibrated_buck_voltage_output=(float)(31*(current_buck_adc_para.buck_voltage)*(3.3))/4096;
	buck_convertor_current.voltageout_output=calibrated_buck_para_value.calibrated_buck_voltage_output;

}

void buck_temperature_callibration(){
	// buck temperature






}


void buck_current_adc(){

	ADC_ChannelConfTypeDef sConfig = {0};
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

}

void buck_voltage_adc(){

	ADC_ChannelConfTypeDef sConfig = {0};
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
}


void buck_temperature_adc(){

	ADC_ChannelConfTypeDef sConfig = {0};
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
}






// adc interrupt call back function

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){



}





void pid_intialize(){

//	 PID(&TPID, &calibrated_buck_para_value.calibrated_buck_voltage_output, &buck_convertor_current.pwm_out, &(buck_convertor_current.voltageout_set), 2, 5, 1, _PID_P_ON_E, _PID_CD_DIRECT);

//	  PID_SetMode(&TPID, _PID_MODE_AUTOMATIC);
	  //PID_SetSampleTime(&TPID, 2);
//	  PID_SetOutputLimits(&TPID, 0, 1000);



}

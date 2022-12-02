/*
 * SW3516.c
 *
 *  Created on: Dec 2, 2022
 *      Author: Syed Mir Hamza
 */


#include "SW3516.h"


uint8_t vin_buffer_enable = 1;
uint8_t vout_buffer_enable = 2;
uint8_t iout1_buffer_enable = 3;
uint8_t iout2_buffer_enable = 4;
uint8_t temp_buffer_enable = 6;
uint8_t Vinenable = 2;


uint8_t reg_value;


struct SW3516_ADC_data current_ADC;
struct SW3516_converted_values previous, current;


void write_to_reg(uint8_t reg_address, uint8_t value_to_write){

	HAL_I2C_Mem_Write(&hi2c1, SW3516_address, reg_address, I2C_MEMADD_SIZE_8BIT,  &value_to_write, 1, 10000);
}


void read_from_register(uint8_t reg_address, uint8_t value){
	HAL_I2C_Mem_Read(&hi2c1, SW3516_address, reg_address, I2C_MEMADD_SIZE_8BIT, &value, 1, 10000);
}


void SW3516_init(){
	HAL_I2C_Mem_Write(&hi2c1, SW3516_address, I2C_CTRL, I2C_MEMADD_SIZE_8BIT, &Vinenable, 1, 10000);
}


void read_ADC_DATA_BUFFER(uint8_t value, uint16_t* structure_member, uint8_t data_to_put_in_buff){

	  HAL_I2C_Mem_Write(&hi2c1, SW3516_address, ADC_DATA_TYPE, I2C_MEMADD_SIZE_8BIT, &data_to_put_in_buff, 1, 10000);
	  HAL_I2C_Mem_Read(&hi2c1, SW3516_address, ADC_DATA_BUFFER_H, I2C_MEMADD_SIZE_8BIT, &value, 1, 10000);
	  *structure_member  = (uint16_t)value << 4;
	  HAL_I2C_Mem_Read(&hi2c1, SW3516_address, ADC_DATA_BUFFER_L, I2C_MEMADD_SIZE_8BIT, &value, 1, 10000);
	  *structure_member |= (uint16_t)value & 0x000F;
}


void convert_ADC(float* current1, float* current2, float* voltagein, float* voltageout, float* temperature){

		read_ADC_DATA_BUFFER(reg_value, &current_ADC.currentA_ADC, iout1_buffer_enable);
		*current1 = current_ADC.currentA_ADC * 2.5;
		read_ADC_DATA_BUFFER(reg_value, &current_ADC.currentC_ADC, iout2_buffer_enable);
		*current2 = current_ADC.currentC_ADC * 2.5;
		read_ADC_DATA_BUFFER(reg_value, &current_ADC.voltagein_ADC, vin_buffer_enable);
		*voltagein = current_ADC.voltagein_ADC * 10;
		read_ADC_DATA_BUFFER(reg_value, &current_ADC.voltageout_ADC, vout_buffer_enable);
		*voltageout = current_ADC.voltageout_ADC * 6;
		read_ADC_DATA_BUFFER(reg_value, &current_ADC.temperature_ADC, temp_buffer_enable);
		*temperature = current_ADC.temperature_ADC / 100.0;
		HAL_I2C_Mem_Read(&hi2c1, SW3516_address, PWR_STATUS, I2C_MEMADD_SIZE_8BIT, &reg_value, 1, 10000);
		current.status_USBC = reg_value & 0x01;
		current.status_USBA = reg_value & 0x01;
		current.time_in_secs++;
}


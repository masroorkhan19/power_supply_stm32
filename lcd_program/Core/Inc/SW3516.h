/*
 * SW3516.h
 *
 *  Created on: Dec 2, 2022
 *      Author: Syed Mir Hamza
 */

#ifndef INC_SW3516_H_
#define INC_SW3516_H_

#include "main.h"
#include "stdbool.h"

extern I2C_HandleTypeDef hi2c1;

#define SW3516_address 				0x3C << 1
#define IC_VERSION					0x01
#define FCX_STATUS					0x06
#define PWR_STATUS					0x07
#define I2C_ENABLE					0x12
#define I2C_CTRL					0x13
#define ADC_VIN_H					0x30
#define ADC_VOUT_H					0x31
#define ADC_VIN_VOUT_L				0x32
#define ADC_IOUT1_H					0x33
#define ADC_IOUT2_H					0x34
#define ADC_IOUT1_IOUT2_L			0x35
#define ADC_TS_H					0x37
#define ADC_TS_L					0x38
#define ADC_DATA_TYPE				0x3A
#define ADC_DATA_BUFFER_H			0x3B
#define ADC_DATA_BUFFER_L			0x3C
#define PRO_CONF					0xB0
#define PDO_CONF0					0xB1
#define PDO_CONF1					0xB2
#define PDO_CONF2					0xB3
#define PDO_CONF3					0xB4
#define PDO_CONF4					0xB5

extern uint8_t reg_value;

struct SW3516_ADC_data {
		uint16_t currentA_ADC;
		uint16_t currentC_ADC;
		uint16_t voltagein_ADC;
		uint16_t voltageout_ADC;
		uint16_t temperature_ADC;
};

struct SW3516_converted_values {
			float currentA;
			float currentC;
			float voltagein;
			float voltageout;
			float temperature;
			bool status_USBA;
			bool status_USBC;
			unsigned long time_in_secs_A;
			unsigned long time_in_secs_C;

};

extern  struct SW3516_ADC_data sw3516_current_ADC;
extern struct SW3516_converted_values sw3516_previous, sw3516_current;

void write_to_reg(uint8_t reg_address, uint8_t value_to_write);
void read_from_register(uint8_t reg_address, uint8_t value);
void SW3516_init();
void read_ADC_DATA_BUFFER(uint8_t value, uint16_t* structure_member, uint8_t data_to_put_in_buff);
void convert_ADC(float* current1, float* current2, float* voltagein, float* voltageout, float* temperature);
void  sw3516_read(void );



#endif /* INC_SW3516_H_ */

/*
 * eeprom_chip.h
 *
 *  Created on: Dec 11, 2022
 *      Author: HP
 */

#ifndef INC_EEPROM_CHIP_H_
#define INC_EEPROM_CHIP_H_
#include "main.h"
#include "SW3516.h"


#define eeprom_address 0xA0

typedef enum {

	max_voltage=1,
	max_current,
	max_power,
	max_temp,
	set_voltage,
	set_current

}parameter_type;


typedef struct {

	uint16_t max_voltage;
	uint16_t max_current;
	uint16_t max_power;
	uint16_t max_temp;
}eeprom_data;


typedef struct {

	uint16_t current_set_voltage;
	uint16_t current_set_current;

}set_eeprom;


extern  eeprom_data max_eeprom_data;
extern  set_eeprom set_eeprom_data;


void write_eeprom(uint16_t data,parameter_type type);
void read_eeprom(parameter_type type);

#endif /* INC_EEPROM_CHIP_H_ */

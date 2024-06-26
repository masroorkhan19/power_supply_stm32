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
#include "buck_convertor.h"

#define eeprom_address 0x50 << 1

typedef enum {

	max_voltage=1,
	max_current,
	max_power,
	max_temp,
	set_voltage,
	set_current,
	first_time_initialize_byte

}parameter_type;


typedef struct {

	uint16_t max_voltage;
	uint16_t max_current;
	uint16_t max_power;
	uint16_t max_temp;
	uint16_t  first_time_initialize_byte;

}eeprom_data;



typedef struct {

	uint16_t current_set_voltage;
	uint16_t current_set_current;

}set_eeprom;

extern  eeprom_data max_eeprom_data, default_eeprom_data;
extern  set_eeprom set_eeprom_data;

void first_time_eeprom_initialize();
void write_eeprom(uint16_t data,parameter_type type);
void read_eeprom(parameter_type type);


void read_buck_set_voltage(void);
void write_buck_set_voltage(void);
void read_buck_set_current(void );
void write_buck_set_current(void );



#endif /* INC_EEPROM_CHIP_H_ */

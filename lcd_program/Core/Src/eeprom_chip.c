/*
 * eeprom_chip.c
 *
 *  Created on: Dec 11, 2022
 *      Author: HP
 */

#include "eeprom_chip.h"

 eeprom_data max_eeprom_data;
 set_eeprom set_eeprom_data;

 void eeprom_i2c_write(uint8_t data,uint16_t location){

	HAL_I2C_Mem_Write(&hi2c1, eeprom_address, location, I2C_MEMADD_SIZE_8BIT, &data, 1, 10000);


 }

 void eeprom_i2c_read(uint8_t *rdata,uint16_t location){

	HAL_I2C_Mem_Read(&hi2c1, eeprom_address, location, I2C_MEMADD_SIZE_8BIT, rdata, 1, 10000);

 }

 void write_eeprom(uint16_t data,parameter_type type ){

	 uint8_t upper_byte,lower_byte;
	 upper_byte =(uint8_t) data>>8;
	 lower_byte = data;
		switch(type){
		case 1:
		{
			eeprom_i2c_write(upper_byte,0);
			eeprom_i2c_write(lower_byte,1);

			break;
		}
		case 2:
		{
			eeprom_i2c_write(upper_byte,2);
			eeprom_i2c_write(lower_byte,3);
			break;
		}
		case 3:
		{
			eeprom_i2c_write(upper_byte,4);
			eeprom_i2c_write(lower_byte,5);
			break;
		}
		case 4:
		{
			eeprom_i2c_write(upper_byte,6);
			eeprom_i2c_write(lower_byte,7);
			break;
		}
		case 5:
		{

			eeprom_i2c_write(upper_byte,8);
			eeprom_i2c_write(lower_byte,9);
			break;
		}
		case 6:
		{
			eeprom_i2c_write(upper_byte,10);
			eeprom_i2c_write(lower_byte,11);
			break;
		}
		default:
		{}



		}

 }

void read_eeprom(parameter_type type){

	uint16_t temperory_value;
	uint8_t upper_byte_read,lower_byte_read;

	switch(type){
	case 1:
	{
		eeprom_i2c_read(&upper_byte_read,0);
		eeprom_i2c_read(&lower_byte_read,1);
		max_eeprom_data.max_voltage = (uint16_t)upper_byte_read<<8 | lower_byte_read;
		break;
	}
	case 2:
	{
		eeprom_i2c_read(&upper_byte_read,2);
		eeprom_i2c_read(&lower_byte_read,3);
		max_eeprom_data.max_current = (uint16_t)upper_byte_read<<8 | lower_byte_read;
		break;
	}
	case 3:
	{
		eeprom_i2c_read(&upper_byte_read,4);
		eeprom_i2c_read(&lower_byte_read,5);
		max_eeprom_data.max_power = (uint16_t)upper_byte_read<<8 | lower_byte_read;
		break;
	}
	case 4:
	{
		eeprom_i2c_read(&upper_byte_read,6);
		eeprom_i2c_read(&lower_byte_read,7);
		max_eeprom_data.max_temp = (uint16_t)upper_byte_read<<8 | lower_byte_read;
		break;
	}
	case 5:
	{
		eeprom_i2c_read(&upper_byte_read,8);
		eeprom_i2c_read(&lower_byte_read,9);
		set_eeprom_data.current_set_voltage = (uint16_t)upper_byte_read<<8 | lower_byte_read;
		break;
	}
	case 6:
	{
		eeprom_i2c_read(&upper_byte_read,10);
		eeprom_i2c_read(&lower_byte_read,11);
		set_eeprom_data.current_set_voltage = (uint16_t)upper_byte_read<<8 | lower_byte_read;
		break;
	}
	default:
	{}
	}

}

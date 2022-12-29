/*
 * eeprom_chip.c
 *
 *  Created on: Dec 11, 2022
 *      Author: HP
 */

#include "eeprom_chip.h"

 eeprom_data max_eeprom_data;
 set_eeprom set_eeprom_data;

 eeprom_data default_eeprom_data = {1500, 500, 7500, 5000, 100};
 set_eeprom default_set_eeprom_data = {0, 0};

 void eeprom_i2c_write(uint8_t data,uint16_t location){

	 uint8_t temp;

//	 do{
	HAL_I2C_Mem_Write(&hi2c1, eeprom_address, location, I2C_MEMADD_SIZE_8BIT, &data, 1, 10000);
	HAL_Delay(10);
//	eeprom_i2c_read(&temp, location);
//	 }while(temp!=data);
 }

 void eeprom_i2c_read(uint8_t *rdata,uint16_t location){

	HAL_I2C_Mem_Read(&hi2c1, eeprom_address, location, I2C_MEMADD_SIZE_8BIT, rdata, 1, 10000);

 }

 void write_eeprom(uint16_t data,parameter_type type ){

	 uint8_t upper_byte,lower_byte;
	 upper_byte =(data>>8) & 0xFF;
	 lower_byte = data & 0xFF;
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
		case 7:
		{
			eeprom_i2c_write(lower_byte,12);
		}
		default:
		{}



		}

 }

void read_eeprom(parameter_type type){

	uint8_t byte_value;
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
		set_eeprom_data.current_set_current = (uint16_t)upper_byte_read<<8 | lower_byte_read;
		break;
	}
	case 7:
	{
		eeprom_i2c_read(&byte_value,12);
		max_eeprom_data.first_time_initialize_byte = byte_value;
	}
	default:
	{}
	}

}

void first_time_eeprom_initialize(){

	read_eeprom(first_time_initialize_byte);

	if(max_eeprom_data.first_time_initialize_byte == default_eeprom_data.first_time_initialize_byte){
		for (int n=1; n<7; n++){
			read_eeprom(n);
		}

	}
	else{

			write_eeprom(default_eeprom_data.max_voltage,1);
			write_eeprom(default_eeprom_data.max_current,2);
			write_eeprom(default_eeprom_data.max_power,3);
			write_eeprom(default_eeprom_data.max_temp,4);
			write_eeprom(default_set_eeprom_data.current_set_voltage,5);
			write_eeprom(default_set_eeprom_data.current_set_current,6);
			write_eeprom(default_eeprom_data.first_time_initialize_byte,7);
			for (int n=1; n<7; n++){
					read_eeprom(n);
				}

	}

	 read_buck_set_voltage();
	 read_buck_set_current();

}


void read_buck_set_voltage(){

	read_eeprom(5);
	buck_convertor_current.voltageout_set = (double)set_eeprom_data.current_set_voltage;
}

void write_buck_set_voltage(){

	write_eeprom((uint16_t)((buck_convertor_current.voltageout_set)),5);

}

void read_buck_set_current(){
	read_eeprom(6);
	buck_convertor_current.current_set =(double) set_eeprom_data.current_set_current;

}

void write_buck_set_current(){

	write_eeprom((uint16_t)((buck_convertor_current.current_set)),6);

}

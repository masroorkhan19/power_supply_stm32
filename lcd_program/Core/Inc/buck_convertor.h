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

 struct  buck_struct{

			float current_set;
			float voltageout_set;
			float current_output;
			float voltageout_output;
			float voltagein;
			float temperature;
			bool status_cv;
			bool status_cc;
			uint8_t status_ok;
			bool buck_on_off;


};

extern  struct buck_struct buck_convertor_current;
extern  struct buck_struct buck_convertor_pervious;


#endif /* INC_BUCK_CONVERTOR_H_ */

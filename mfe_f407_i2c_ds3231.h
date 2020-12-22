/*
 * mfe_f407_i2c_ds3231.h
 *
 *  Created on: Nov 26, 2020
 *      Author: MFE
 */

#ifndef MFE_F407_I2C_DS3231_H_
#define MFE_F407_I2C_DS3231_H_




I2C_HandleTypeDef hi2c1;

typedef struct {
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hour;
	uint8_t dayofweek;
	uint8_t dayofmonth;
	uint8_t month;
	uint8_t year;
} TIME;

TIME time;

uint8_t decToBcd(int val);
int bcdToDec(uint8_t val);

void Set_Time(uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t dom,
		uint8_t month, uint8_t year);

void Get_Time(void);

float Get_Temp(void);

void force_temp_conv(void);


#endif /* MFE_F407_I2C_DS3231_H_ */

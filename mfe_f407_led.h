/*
 * mfe_f407_led.h
 *
 *  Created on: Sep 28, 2020
 *      Author: MFE
 */

#ifndef INC_MFE_F407_LED_H_
#define INC_MFE_F407_LED_H_

void init_ledBoard(void);
void ledBoard_on(int);
void ledBoard_off(int);
void ledBoard_toggle(int led_no);


#endif /* INC_MFE_F407_LED_H_ */

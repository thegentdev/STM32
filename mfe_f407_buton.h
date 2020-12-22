/*
 * mfe_f407_buton.h
 *
 *  Created on: Sep 28, 2020
 *      Author: MFE
 */

#ifndef INC_MFE_F407_BUTON_H_
#define INC_MFE_F407_BUTON_H_

/*Buton Pinleri: A13-A15
 * */
void init_butonExt(void);
int butonExt_check(int);

void init_butonBoard(void);
int butonBoard_check(void);


#endif /* INC_MFE_F407_BUTON_H_ */

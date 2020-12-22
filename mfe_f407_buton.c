/*
 * mfe_f407_buton.c
 *
 *  Created on: Sep 28, 2020
 *      Author: MFE
 */
#include "stm32f4xx_hal.h"
#include "mfe_f407_buton.h"

void init_butonExt(void){
	//PA13-15 pinleri buton olarak tanımlandı.
	RCC->AHB1ENR |= (1<<0);

	GPIOA->MODER &= ~(1 << 26) | ~(1 << 27) | ~(1 << 30) | ~(1 << 31);
	GPIOA->PUPDR |= (1 << 31) | (1 << 27);
	GPIOA->PUPDR &= ~(1 << 30) | ~(1 << 26);
}

int butonExt_check(int buton_no){
	if(buton_no==1){
		return (GPIOA->IDR & (1<<13));
	}
	else if(buton_no==2){
			return (GPIOA->IDR & (1<<15));
	}
	else return 0;
}

void init_butonBoard(){
	RCC->AHB1ENR |= (1<<0);

	GPIOA->MODER &= (0<<0)|(0<<1);
	GPIOA->PUPDR |= (1<<1);
	GPIOA->PUPDR &= (0<<0);

}
int butonBoard_check(void){
	return (GPIOA->IDR & (1<<0));
}

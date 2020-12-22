/*
 * mfe_f407_multiEXTI.c
 *
 *  Created on: Sep 28, 2020
 *      Author: MFE
 */
#include "stm32f4xx_hal.h"
#include "mfe_f407_multiEXTI.h"


void init_multiEXTI(void){
	//PA13-15 pinleri interrupt olarak ayarlanmış
	RCC->APB2ENR |= (1<<14);

	SYSCFG->EXTICR[3] &= (0<<15)|(0<<14)|(0<<13)|(0<<12);
	SYSCFG->EXTICR[3] &= (0<<7)|(0<<6)|(0<<5)|(0<<4);

	NVIC_EnableIRQ(EXTI15_10_IRQn);
	NVIC_SetPriority(EXTI15_10_IRQn,1);

	EXTI->IMR |= (1 << 15) | (1 << 13);
	EXTI->RTSR |= (1 << 15) | (1 << 13);
}

/*
 void EXTI15_10_IRQHandler(){
	if(EXTI->PR & (1<<13)){
		ledBoard_on(2);
		HAL_Delay(500);
		ledBoard_off(2);
		EXTI->PR |= (1<<13);
	}
	if (EXTI->PR & (1 << 15)) {
			ledBoard_on(4);
			HAL_Delay(500);
			ledBoard_off(4);
			EXTI->PR |= (1 << 15);

	}

}
 */

void init_multiExtiPA10(void){
	//PA10 pini interrupt olarak ayarlandı
	RCC->APB2ENR |= (1<<14);

	SYSCFG->EXTICR[3] &= (0<<11)|(0<<10)|(0<<9)|(0<<8);

	NVIC_EnableIRQ(EXTI15_10_IRQn);
	NVIC_SetPriority(EXTI15_10_IRQn,1);

	EXTI->IMR |= (1 << 10);
	EXTI->RTSR |= (1 << 10);

}
/*

 */



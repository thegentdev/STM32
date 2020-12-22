/*
 * mfe_f407_timer.c
 *
 *  Created on: 8 Eki 2020
 *      Author: MFE
 */
#include "stm32f4xx_hal.h"
void init_Timer2(void){
	// TIM2 CLOCK ACTIVE
	RCC->APB1ENR |= (1<<0);

	// UPCOUNTER
	TIM2->CR1 &= (0<<4);

	// ARR ACTIVE
	TIM2->CR1 |= (1<<7);

	// ARR = 2^32
	//TIM2->ARR = 0xFFFFFFFF;

	// EDGE ALLIGNED MODE
	TIM2->CR1 &= (0<<5) | (0<<6);

	// !!!!!!!!!!!!! CLOCK DIVISION ÇALIŞMIYOR
	TIM2->CR1 |= (1<<8);
	TIM2->CR1 &= ~(1<<9);

	// 168MHz - APB1 84MHz - 84MHz/42000Hz=2000Hz PERIYOD=(1/2000)=0.0005SN
	// PSC = 42000-1
	// 1 SANİYE = 2000 CNT
	TIM2->PSC = 41999;

	TIM2->SMCR &= (0<<0);
	TIM2->EGR |= (1<<0);


	TIM2->CR1 |= (1<<0);
}

void Timer2_enb(void){
	TIM2->CR1 |= (1<<0);
	TIM2->CNT =0;
}
void Timer2_dis(void){
	TIM2->CR1 &= (0<<0);
}

int Timer2_check(uint32_t *pretime,uint32_t wait){

	if(((TIM2->CNT)- *pretime) < (2*wait)){
		return 1;
	}
	else{
		return 0;
	}

}


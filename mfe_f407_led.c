/*
 * mfe_f407_led.c
 *
 *  Created on: Sep 28, 2020
 *      Author: MFE
 */
#include "stm32f4xx_hal.h"
#include "mfe_f407_led.h"

void init_ledBoard(void){
	RCC->AHB1ENR |= (1<<3);

	GPIOD->MODER &= (0 << 31) | (0 << 29) | (0 << 27) | (0 << 25);
	GPIOD->MODER |= (1 << 30) | (1 << 28) | (1 << 26) | (1 << 24);

	GPIOD->OTYPER &= (0 << 12) | (0 << 13) | (0 << 14) | (0 << 15);

	GPIOD->OSPEEDR &= (0 << 30) | (0 << 28) | (0 << 26) | (0 << 24);
	GPIOD->OSPEEDR |= (1 << 31) | (1 << 29) | (1 << 27) | (1 << 25);

	GPIOD->PUPDR |= (1 << 31) | (1 << 29) | (1 << 27) | (1 << 25);
	GPIOD->PUPDR &= (0 << 30) | (0 << 28) | (0 << 26) | (0 << 24);

}
void ledBoard_on(int led_no){
	switch (led_no) {
		case 1:
			GPIOD->ODR |= (1<<12);
			break;
		case 2:
			GPIOD->ODR |= (1<<13);
			break;
		case 3:
			GPIOD->ODR |= (1<<14);
			break;
		case 4:
			GPIOD->ODR |= (1<<15);
			break;
		default:
			break;
	}

}
void ledBoard_off(int led_no){
	switch (led_no) {
			case 1:
				GPIOD->ODR &= ~(1<<12);
				break;
			case 2:
				GPIOD->ODR &= (0<<13);
				break;
			case 3:
				GPIOD->ODR &= (0<<14);
				break;
			case 4:
				GPIOD->ODR &= (0<<15);
				break;
			default:
				break;
		}
}

void ledBoard_toggle(int led_no){
	switch (led_no) {
		case 1:
			GPIOD->ODR ^= (1<<12);
			break;
		case 2:
			GPIOD->ODR ^= (1<<13);
			break;
		case 3:
			GPIOD->ODR ^= (1<<14);
			break;
		case 4:
			GPIOD->ODR ^= (1<<15);
			break;
		default:
			break;
	}

}

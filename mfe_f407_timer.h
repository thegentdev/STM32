/*
 * mfe_f407_timer.h
 *
 *  Created on: 8 Eki 2020
 *      Author: MFE
 */

#ifndef MFE_MFE_F407_TIMER_H_
#define MFE_MFE_F407_TIMER_H_


void init_Timer2(void);

void Timer2_enb(void);

void Timer2_dis(void);

int Timer2_check(uint32_t *pretime,uint32_t wait);

#endif /* MFE_MFE_F407_TIMER_H_ */

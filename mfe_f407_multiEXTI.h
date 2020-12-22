/*
 * mfe_f407_multiEXTI.h
 *
 *  Created on: Sep 28, 2020
 *      Author: MFE
 */

#ifndef INC_MFE_F407_MULTIEXTI_H_
#define INC_MFE_F407_MULTIEXTI_H_

void init_multiEXTI(void);
void EXTI15_10_IRQHandler(void);
void init_multiExtiPA10(void);

#endif /* INC_MFE_F407_MULTIEXTI_H_ */

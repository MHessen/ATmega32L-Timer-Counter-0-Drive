/*
 * Timer_0.h
 * Author: Engr:M.Hussein
 */
#include "Timer_0_Config.h"

#ifndef TIMER_0_H_
#define TIMER_0_H_

/*---------------------------Timer/Counter-0 Registers------------------------------*/
enum TCCR0_Reg { CS00 , CS01 , CS02 , WGM01 , COM00 , COM01 , WGM00 , FOC0 } ;
enum TIMSK_Reg { TOIE0 , OCIE0 , TOIE1 , OCIE1B , OCIE1A , TICIE1 , TOIE2 , OCIE2 } ;
enum TIFR_Reg  { TOV0 , OCF0 , TOV1 , OCF1B , OCF1A , ICF1 , TOV2 , OCF2 } ;
/*__________________________________________________________________________________*/
/*---------------Functions---------------------------*/

void Timer_0_CLKset ( u8 PreScale ) ;
void Set_Normal_Mode (void);
void Force_Output_Compare (void) ;
void CTC_Compare_Output_Mode (u8 COMode);
void Timer0_CTC_INT (u8 state) ;
void Timer0_Overflow_INT (u8 state) ;
void Set_PWM_mode (void);
void FPWM_Compare_Output_Mode ( u8 COMode );

#endif /* TIMER_0_H_ */

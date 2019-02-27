/*
 * Timer_0.c
 * Author: Engr:M.Hussein
 */
#include "Types.h"
#include "Registers.h"
#include "Timer_0.h"
#include "Timer_0_Config.h"
#include "Interrupt.h"



/*----------Modes Of Operation-----------*/
/*----- Normal Mode -----*/
#if ( Normal_mode == Enable_T0_m )
/*--------------------------------*/
void Set_Normal_Mode (void)
{
	TCCR0 &= ~( (1<<WGM00)|(1<<WGM01) ) ;
}
/*--------------------------------*/
void Force_Output_Compare (void)
{
	TCCR0 |= (1<<FOC0) ;
}
/*--------------------------------*/
void Timer0_Overflow_INT (u8 state)
{
	if ( state == INT_En )
	{
		TIMSK |= (1<<TOIE0) ;
		SREG  |= (1<<I) ;
	}
	else if ( state == INT_Dis )
	{
		TIMSK &= ~(1<<TOIE0) ;
	}
}
/*--------------------------------*/
/*__________________________________________________________*/
#elif ( CTC_mode == Enable_T0_m )
/*----- CTC Mode -----*/
void Set_CTC_Mode (void)
{
	TCCR0 &= ~( (1<<WGM00) ) ;
	TCCR0 |=  (1<<WGM01) ;
}
/*--------------------------------*/
void Force_Output_Compare (void)
{
	TCCR0 |= (1<<FOC0) ;
}
/*--------------------------------*/
void CTC_Compare_Output_Mode (u8 COMode)
{
	/*
	 *Set DDR of OC0 to output.
	 */
	if ( COMode == Toggle )
	{
		TCCR0 |= (1<<COM00);
		TCCR0 &= ~( (1<<COM01) );
	}
	else if ( COMode == Set )
	{
		TCCR0 |= ( (1<<COM00)|(1<<COM01) );
	}
	else if ( COMode == Clear )
	{
		TCCR0 &= ~( (1<<COM00) ) ;
		TCCR0 |= (1<<COM01) ;
	}
}
/*--------------------------------*/
void Timer0_CTC_INT (u8 state)
{
	if ( state == INT_En )
	{
		TIMSK |= (1<<OCIE0) ;
		SREG  |= (1<<I) ;
	}
	else if ( state == INT_Dis )
	{
		TIMSK &= ~(1<<OCIE0) ;
	}
}
/*--------------------------------*/
/*__________________________________________________________*/
#elif ( F_PWM_mode == Enable_T0_m )
/*----- Fast PWM -----*/
/*--------------------------------*/
/*Enabling Fast PWM mode*/
void Set_PWM_mode (void)
{
	TCCR0 |= ( (1<<WGM00)|(1<<WGM01) ) ;
}
/*--------------------------------*/
void FPWM_Compare_Output_Mode ( u8 COMode )
{
	/*
	 *Set DDR of OC0 to output.
	 */
	if ( COMode == Set )
	{
		TCCR0 |= ( (1<<COM00)|(1<<COM01) ) ;
	}
	else if ( COMode == Clear )
	{
		TCCR0 |=  (1<<COM01) ;
		TCCR0 &= ~(1<<COM00) ;
	}

}

/*--------------------------------*/
/*__________________________________________________________*/
#elif ( PC_PWM_mode == Enable_T0_m )
/* Phase Correct PWM mode */
#endif


/*Functions*/
Timer_0_CLKset ( u8 PreScale )
{
	if ( PreScale == No_CLK )
	{/*No Clock*/
		TCCR0 &= ~ ( (1<<CS00)|(1<<CS01)|(1<<CS02) ) ;
	}
	else if ( PreScale == CLK_1 )
	{/*No PreScale*/
		TCCR0 &= ~( (1<<CS01)|(1<<CS02) ) ;
		TCCR0 |= (1<<CS00);
	}
	else if ( PreScale == CLK_8 )
	{/* Clock/8 */
		TCCR0 &= ~( (1<<CS00)|(1<<CS02) ) ;
		TCCR0 |= (1<<CS01);
	}
	else if ( PreScale == CLK_64 )
	{/* Clock/64 */
		TCCR0 &= ~( (1<<CS02) ) ;
		TCCR0 |= ( (1<<CS01)|(1<<CS00) );
	}
	else if ( PreScale == CLK_256 )
	{/* Clock/256 */
		TCCR0 &= ~( (1<<CS00)|(1<<CS01) ) ;
		TCCR0 |= (1<<CS02);
	}
	else if ( PreScale == CLK_1024 )
	{/* Clock/1024 */
		TCCR0 &= ~( (1<<CS01) ) ;
		TCCR0 |= ( (1<<CS02)|(1<<CS00) );
	}
	else if ( PreScale == Ext_FE )
	{/* External clock source on T0 pin, Clock on falling edge */
		TCCR0 &= ~( (1<<CS00) ) ;
		TCCR0 |= ( (1<<CS01)|(1<<CS02) );
	}
	else if ( PreScale == Ext_RE )
	{/* External clock source on T0 pin, Clock on Rising edge */
		TCCR0 |= ( (1<<CS00)|(1<<CS01)|(1<<CS02) );
	}
}

/*
 * Timer_0_Config.h
 * Author: Engr:M.Hussein
 */

#ifndef TIMER_0_CONFIG_H_
#define TIMER_0_CONFIG_H_

/*-------------- (Timer / Counter) Enable/Disable-----------------*/
#define Enable_T0_m  411
#define Disable_T0_m 410
/*_____________________________________________*/
#define Normal_mode Enable_T0_m
#define CTC_mode    Disable_T0_m
#define F_PWM_mode  Disable_T0_m
#define PC_PWM_mode Disable_T0_m
/*_____________________________________________*/
/*Compare Match Output Mode*/
/*COMode*/
#define Toggle 30
#define Set    31
#define Clear  32
/*_____________________________________________*/
/*CTC Interrupt Enable/Disable*/
/*state*/
#define INT_En  20
#define INT_Dis 21
/*_____________________________________________*/
/*------------- Clock Selection----------------*/
#define No_CLK   80         /*The Timer Stop*/
#define CLK_1    81			/*No PreScale*/
#define CLK_8    82			/* Clock/8 */
#define CLK_64   83			/* Clock/64 */
#define CLK_256  84			/* Clock/256 */
#define CLK_1024 85			/* Clock/1024 */
#define Ext_FE   86			/* External Clock Falling Edge @ T0 */
#define Ext_RE   87			/* External Clock Rising Edge @ T0  */
/*_____________________________________________*/






#endif /* TIMER_0_CONFIG_H_ */

/***************************************************************************************************************************************************************************************/
/************************************************* SWE     : TIMER DRIVER  *************************************************************************************************************/
/************************************************* BY      : Youssef Ayman *************************************************************************************************************/
/************************************************* Date    : 27Aug20       *************************************************************************************************************/
/************************************************* Version : v1.0          *************************************************************************************************************/
/***************************************************************************************************************************************************************************************/


# ifndef TIMER_INTERFACE_H
# define TIMER_INTERFACE_H


void TIMER_VidTIMER0InitCTC (void);

void TIMER_VidTIMER0InitOV (void);

void TIMER0_VidFPMInit (void);

void TIMER1_VidFPMInit (void);

void Timer1_VidSetAngle(u8 Copy_u8Angle);

void Timer0_VidSetDuty(u8 Copy_u8Duty);


# endif

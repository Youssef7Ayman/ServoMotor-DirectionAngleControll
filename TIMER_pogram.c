/***************************************************************************************************************************************************************************************/
/************************************************* SWE     : TIMER DRIVER  *************************************************************************************************************/
/************************************************* BY      : Youssef Ayman *************************************************************************************************************/
/************************************************* Date    : 27Aug20       *************************************************************************************************************/
/************************************************* Version : v1.0          *************************************************************************************************************/
/***************************************************************************************************************************************************************************************/

# include "STD_TYPES.h"
# include "BIT_MATH.h"
# include "TIMER_private.h"
# include "TIMER_config.h"
# include "TIMER_interface.h"


void TIMER_VidTIMER0InitCTC (void)
{
	/*Select Generation Mode*/
	#if GENERATION_MODE==NORMAL
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	#elif GENERATION_MODE==PWM_PHASE_CORRECT
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	#elif GENERATION_MODE==CTC
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	#elif GENERATION_MODE==FAST_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	#endif

	/*Select Prescaler*/
	TCCR0 &= 0b11111000;
	TCCR0 |= CLOCK_SELECT;

	/*Set a value in Output Compare Register to force the TCCR0 register to overflow at*/
	OCR0=100;

	/*Enable one Type from the Compare Mode Interrupts*/
	SET_BIT(TIMSK,TIMSK_OCIE0);      //Enable CTC Interrupt

}


void TIMER_VidTIMER0InitOV (void)
{
	/*Select Generation Mode*/
	#if GENERATION_MODE==NORMAL
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	#elif GENERATION_MODE==PWM_PHASE_CORRECT
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	#elif GENERATION_MODE==CTC
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	#elif GENERATION_MODE==FAST_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	#endif

	/*Preload TCNT0 register with 115*/
	TCNT0 =115;

	/*Enable one Type from the Compare Mode Interrupts*/
	SET_BIT(TIMSK,TIMSK_OCIE0);      //Enable Overflow Interrupt

	/*Select Prescaler*/
	TCCR0 &= 0b11111000;
	TCCR0 |= CLOCK_SELECT;

}

void TIMER0_VidFPMInit (void)
{
	/*Select Generation Mode*/
	#if GENERATION_MODE==NORMAL
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	#elif GENERATION_MODE==PWM_PHASE_CORRECT
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	#elif GENERATION_MODE==CTC
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	#elif GENERATION_MODE==FAST_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	#endif


	/*Select set on top and clear on compare*/
	SET_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);

	/*Set OCR0 (On time)*/
	// it is done in the function below

	/*Set Prescaler*/
	TCCR0 &= 0b11111000;
	TCCR0 |= CLOCK_SELECT;
}

void TIMER1_VidFPMInit (void)
{
	/*Select Generation Mode*/
	#if GENERATION_MODE==NORMAL
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	#elif GENERATION_MODE==PWM_PHASE_CORRECT
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	#elif GENERATION_MODE==CTC
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	#elif GENERATION_MODE==FAST_PWM
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

	#endif


	/*Select Set on top Clear on compare*/
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	SET_BIT(TCCR1B,TCCR1B_WGM12);


	/*Set ICR value*/
	ICR1=20000;

	/*Set Prescaler*/
	TCCR1B &= 0b11111000;
	TCCR1B |= CLOCK_SELECT;

}

void Timer1_VidSetAngle(u8 Copy_u8Angle)
{
	OCR1A=(65*Copy_u8Angle)/6+450;
}



void Timer0_VidSetDuty(u8 Copy_u8Duty)
{
	OCR0=(256*Copy_u8Duty)/100.0;
}

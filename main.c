/*
 * main.c
 *
 *  Created on: Sep 9, 2022
 *      Author: hp
 */
# include "STD_TYPES.h"
# include "DIO_interface.h"
# include "LCD_interface.h"
# include "KPD_interface.h"
# include "TIMER_interface.h"
# include <util/delay.h>


int main ()
{
	u8 Direction,DIRECTION,flag=1,i;
	u32 Angle,ANGLE=0;

/*----------------------------------------------------------LCD--------------------------------------------------------------------------------*/
	DIO_VidSetPortDirection(Port_D,0b00000111); // LCD CMD Pins  : Port_D {2,1,0--->OutPut} RS,RW,E respectively only
	DIO_VidSetPortDirection(Port_C,0b11111111); // LCD DATA Pins : Port_C {7,6,5,4,3,2,1,0--->OutPut}
//---------------------------------------------------------------------------------------------------------------------------------------------
/*----------------------------------------------------------KPD--------------------------------------------------------------------------------*/
	DIO_VidSetPortDirection(Port_A,0b00001111); // KPD Pins      : Port_A {7,6,5,4-->Input} R4,R3,R2,R1 | {3,2,1,0-->Output} C1,C2,C3,C4 (Gnd)
	DIO_VidSetPortValue(Port_A,0b11110000);     // Pullup Reseistors activation for KPD Input pins : R4,R3,R2,R1
//---------------------------------------------------------------------------------------------------------------------------------------------
/*-------------------------------------------------------Servo Motor-------------------------------------------------------------------------*/
	DIO_VidSetPinDirection(Port_D,Pin5,Output); // Servo Motor Pin--> PD5
//---------------------------------------------------------------------------------------------------------------------------------------------
/*-------------------------------------------------------LEDS&BUZZER-------------------------------------------------------------------------*/
	DIO_VidSetPortDirection(Port_B,0b10000111); // LEDs Pins     : Port_B {2(Green),1(Yellow),0(Red)-->Output}
												// Buzzer Pins   : Port_B {7-->Output}
//---------------------------------------------------------------------------------------------------------------------------------------------

	LCD_VidDisplayClear();
	TIMER1_VidFPMInit();
	LCD_VidInit();

	LCD_VidSendString("     WELCOME");
	LCD_VidGotoXY(1,1);
	LCD_VidSendString("   *-------*");
	_delay_ms(1000);
	LCD_VidDisplayClear();

	LCD_VidSendString("Servo Motor will");
	LCD_VidGotoXY(1,0);
	LCD_VidSendString("go to HomePlace!");
	DIO_VidSetPinValue(Port_B,Pin1,PinHigh);
	Timer1_VidSetAngle(0);
	DIO_VidSetPinValue(Port_B,Pin1,PinLow);
	//_delay_ms(delay);
	_delay_ms(1000);
	LCD_VidDisplayClear();

	LCD_VidSendString("Right Refered->R");
	LCD_VidGotoXY(1,0);
	LCD_VidSendString("Left Refered->L");
	_delay_ms(2000);

	while (1)
	{
		LCD_VidDisplayClear();
		LCD_VidSendString("Please enter the ");
		LCD_VidGotoXY(1,0);
		LCD_VidSendString("DIRECTION : [ ]");
		while (1)
		{
			Direction=KPD_u8GetPressedKey();
			if (Direction!=101)
			{
				LCD_VidDisplayClear();
				LCD_VidSendString("Please enter the ");
				LCD_VidGotoXY(1,0);
				LCD_VidSendString("DIRECTION : [ ]");

				LCD_VidGotoXY(1,13);

				if (Direction=='E')
				{
					LCD_VidDisplayClear();
					break;
				}
				DIRECTION=Direction;
				LCD_VidSendData(Direction);

			}
		}

		LCD_VidDisplayClear();
		LCD_VidSendString("Please enter the ");
		LCD_VidGotoXY(1,0);
		LCD_VidSendString("ANGLE(Deg) : ");

		while (1)
		{
			Angle=KPD_u8GetPressedKey();
			if (Angle!=101)
			{
				LCD_VidDisplayClear();
				LCD_VidSendString("Please enter the ");
				LCD_VidGotoXY(1,0);
				LCD_VidSendString("ANGLE(Deg) : ");

				if (Angle=='E')
				{
					LCD_VidDisplayClear();
					break;
				}

				else if (Angle=='B')
				{
					ANGLE=ANGLE/10;
					flag=0;
				}
				else if (flag==1)
				{
					ANGLE=(ANGLE*10)+Angle-48;
				}

				LCD_VidSendNumber(ANGLE);
				flag=1;


			}

		}

		switch (DIRECTION)
		{
		    case 'R':
		    {
		    	LCD_VidDisplayClear();
		    	LCD_VidSendString("ServoMotor runs");
		    	LCD_VidGotoXY(1,0);
		    	LCD_VidSendString("WRT RIGHT at ");
		    	LCD_VidSendNumber(ANGLE);
		    	//LCD_VidSendString(" deg");

		    	Timer1_VidSetAngle(ANGLE);

		    	for (i=0;i<5;i++)
		    	{
		    		DIO_VidSetPinValue(Port_B,Pin2,PinHigh);
		    		DIO_VidSetPinValue(Port_B,Pin7,PinHigh);
		    		_delay_ms(100);
		    		DIO_VidSetPinValue(Port_B,Pin2,PinLow);
		    		DIO_VidSetPinValue(Port_B,Pin7,PinLow);
		    		_delay_ms(50);
		    	}

		    	break;
		    }
			case 'L':
			{
				LCD_VidDisplayClear();
				LCD_VidSendString("ServoMotor runs");
				LCD_VidGotoXY(1,0);
		    	LCD_VidSendString("WRT LEFT at ");
				LCD_VidSendNumber(ANGLE);
				//LCD_VidSendString(" deg");

				Timer1_VidSetAngle(180-ANGLE);

				for (i=0;i<5;i++)
				{
					DIO_VidSetPinValue(Port_B,Pin2,PinHigh);
					DIO_VidSetPinValue(Port_B,Pin7,PinHigh);
					_delay_ms(100);
					DIO_VidSetPinValue(Port_B,Pin2,PinLow);
					DIO_VidSetPinValue(Port_B,Pin7,PinLow);
					_delay_ms(50);
				}

				break;
			}


			default :
			{
				DIO_VidSetPinValue(Port_B,Pin0,PinHigh);

				DIO_VidSetPinValue(Port_B,Pin7,PinHigh);

				LCD_VidDisplayClear();
				LCD_VidSendString("     InValid");
				LCD_VidGotoXY(1,4);
				LCD_VidSendString("Direction!");
				_delay_ms(1000);
				DIO_VidSetPinValue(Port_B,Pin0,PinLow);
				DIO_VidSetPinValue(Port_B,Pin7,PinLow);

				break;
			}

		}

		DIRECTION=0;
		ANGLE=0;

	}


}


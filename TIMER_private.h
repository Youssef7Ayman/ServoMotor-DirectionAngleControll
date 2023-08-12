/***************************************************************************************************************************************************************************************/
/************************************************* SWE     : TIMER DRIVER  *************************************************************************************************************/
/************************************************* BY      : Youssef Ayman *************************************************************************************************************/
/************************************************* Date    : 27Aug20       *************************************************************************************************************/
/************************************************* Version : v1.0          *************************************************************************************************************/
/***************************************************************************************************************************************************************************************/

# ifndef TIMER_PRIVATE_H
# define TIMER_PRIVATE_H


/********************************************************** TCCR0 Register ***********************************************************************/
#define TCCR0           		 *((volatile u8*)0x53)		/*Timer/Counter Control Register*/
#define TCCR0_FOC0							7				//Force Output Compare
#define TCCR0_WGM00							6				//Waveform Generation Mode
#define TCCR0_COM01							5				//Compare Match Output Mode
#define TCCR0_COM00							4				//Compare Match Output Mode
#define TCCR0_WGM01							3				//Waveform Generation Mode
#define TCCR0_CS02							2				//Clock Select Bit Description(Prescaler)
#define TCCR0_CS01							1				//Clock Select Bit Description(Prescaler)
#define TCCR0_CS00							0				//Clock Select Bit Description(Prescaler)
										/* Compare Match Output Mode */
#define NORMAL											0
#define PWM_PHASE_CORRECT                   			1
#define CTC                                 			2
#define FAST_PWM                            			3

#define NORMAL_PORT_OPERATION_OC0_DISCONNECTED		  	0
#define TOGGLE_OC0                  					1
#define CLEAR_OC0                                 		2
#define SETT_OC0                            			3

#define NORMAL_PORT_OPERATION_OC0_DISCONNECTED		  	0
#define CLEAR_OC0_SET_OC0_AT_TOP                        2
#define SET_OC0_CLEAR_OC0_AT_TOP                        3

#define NORMAL_PORT_OPERATION_OC0_DISCONNECTED		  	0
#define CLEAR_OC0_UPCOUNTING_SET_OC0_DOWNCOUNTING       2
#define SET_OC0_UPCOUNTING_CLEAR_OC0_DOWNCOUNTING       3
										/* Clock Select Bit Description(Prescaler) */
#define  NO_CLOCK_SOURCE								0
#define  CLK_DIV_BY_1									1
#define  CLK_DIV_BY_8									2
#define  CLK_DIV_BY_64									3
#define  CLK_DIV_BY_256									4
#define  CLK_DIV_BY_1024								5
#define  EXTERNAL_CLK_FALLING_EDGE						6
#define  EXTERNAL_CLK_RISING_EDGE						7

/********************************************************** TCNT0 Register ***********************************************************************/
#define TCNT0					*((volatile u8*)0x52)		/*Timer/Counter Register 8-bit (Counter 0 --> 255[Overflow])*/

/********************************************************** OCR0 Register ***********************************************************************/
#define OCR0					*((volatile u8*)0x5C)		/*Output Compare Register (Takes the value that the register TCNT0 will STOP at will counting incremently)*/

/********************************************************** TIMSK Register ***********************************************************************/
#define TIMSK            		*((volatile u8*)0x59)		/*Output Compare Register*/
#define TIMSK_OCIE0                		    1				//Timer/Counter0 Output Compare Match Interrupt Enable
#define TIMSK_TOIE0                			0				//Timer/Counter0 Overflow Interrupt Enable

/********************************************************** TIFR Register ***********************************************************************/
#define TIFR            		*((volatile u8*)0x58)		/*Timer/Counter Interrupt Flag Register*/
#define TIFR_OCF0							1				//Output Compare Flag 0
#define TIFR_TOV0							0				//Timer/Counter0 Overflow Flag

/********************************************************** TIFR Register ***********************************************************************/
/*Timer 1*/

//#define TCNT1H            		*((volatile u8*)0x)		/*Timer/Counter1 high register*/
//#define TCNT1L            		*((volatile u8*)0x)		/*Timer/Counter1 low register*/

//#define OCR1AH            		*((volatile u8*)0x)		/*Output Compare Register 1 A high*/
#define OCR1AL            		*((volatile u8*)0x4A)		/*Output Compare Register 1 A low*/
#define OCR1A            		*((volatile u16*)0x4A)		/*Output Compare Register 1 A all*/

//#define OCR1BH            		*((volatile u8*)0x)		/*Output Compare Register 1 B high*/
//#define OCR1BL            		*((volatile u8*)0x)		/*Output Compare Register 1 B low*/

//#define ICR1H            		*((volatile u8*)0x)		/*Input Capture Register 1 high*/
#define ICR1L            		*((volatile u8*)0x46)	/*Input Capture Register 1 low*/
#define ICR1            		*((volatile u16*)0x46)	/*Input Capture Register 1 all*/


#define TCCR1A            		*((volatile u8*)0x4F)			/*Timer/Counter1 Control Register A*/
#define TCCR1A_COM1A1							   7			//Compare Output Mode for Channel A
#define TCCR1A_COM1A0							   6			//Compare Output Mode for Channel A
#define TCCR1A_COM1B1							   5			//Compare Output Mode for Channel B
#define TCCR1A_COM1B0                              4			//Compare Output Mode for Channel B
#define TCCR1A_FOC1A                               3			//Force Output Compare for Channel A
#define TCCR1A_FOC1B                               2			//Force Output Compare for Channel B
#define TCCR1A_WGM11                               1			//Waveform Generation Mode
#define TCCR1A_WGM10                               0			//Waveform Generation Mode

#define TCCR1B            		*((volatile u8*)0x4E)			/*Timer/Counter1 Control Register B*/
#define TCCR1B_ICNC1							   7			//Input Capture Noise Canceler
#define TCCR1B_ICES1							   6			//Input Capture Edge Select
/*Bit 5 is reserved*/
#define TCCR1B_WGM13                               4			//Waveform Generation Mode
#define TCCR1B_WGM12                               3			//Waveform Generation Mode
#define TCCR1B_CS12                                2			//Clock Select
#define TCCR1B_CS11                                1			//Clock Select
#define TCCR1B_CS10                                0			//Clock Select




#endif





#include"DIO_priv.h"
#include"DIO_config.h"
#include"DIO_int.h"

#include "avr/io.h"
#include"BIT_MATH.h"
#include"STD_TYPES.h"

#define PORTA_DIRECTION CONCBIT(DIO_PIN7_DIR,DIO_PIN6_DIR ,DIO_PIN5_DIR ,DIO_PIN4_DIR ,DIO_PIN3_DIR ,DIO_PIN2_DIR ,DIO_PIN1_DIR ,DIO_PIN0_DIR)
#define PORTB_DIRECTION CONCBIT(DIO_PIN15_DIR,DIO_PIN14_DIR ,DIO_PIN13_DIR ,DIO_PIN12_DIR ,DIO_PIN11_DIR ,DIO_PIN10_DIR ,DIO_PIN9_DIR ,DIO_PIN8_DIR)
#define PORTC_DIRECTION CONCBIT(DIO_PIN23_DIR,DIO_PIN22_DIR ,DIO_PIN21_DIR ,DIO_PIN20_DIR ,DIO_PIN19_DIR ,DIO_PIN18_DIR ,DIO_PIN17_DIR ,DIO_PIN16_DIR)
#define PORTD_DIRECTION CONCBIT(DIO_PIN31_DIR,DIO_PIN30_DIR ,DIO_PIN29_DIR ,DIO_PIN28_DIR ,DIO_PIN27_DIR ,DIO_PIN26_DIR ,DIO_PIN25_DIR ,DIO_PIN24_DIR)

void DIO_voidInit(void)
{
	DDRA = PORTA_DIRECTION;
	DDRB = PORTB_DIRECTION;
	DDRC = PORTC_DIRECTION;
	DDRD = PORTD_DIRECTION;
}

void DIO_voidSetPin(u8 Local_PinNumber,u8 Local_Value)
{
	if(Local_PinNumber <8)
	{
		if(Local_Value == DIO_HIGH)
		{
			SETBIT(PORTA,Local_PinNumber);
		}
		else 
		{
			CLRBIT(PORTA,Local_PinNumber);
		}
	}
	else if(Local_PinNumber <16)
	{
		if(Local_Value == DIO_HIGH)
		{
			SETBIT(PORTB,(Local_PinNumber-8));
		}
		else 
		{
			CLRBIT(PORTB,(Local_PinNumber-8));
		}
	}	
	else if(Local_PinNumber <24)
	{
		if(Local_Value == DIO_HIGH)
		{
			SETBIT(PORTC,(Local_PinNumber-16));
		}
		else 
		{
			CLRBIT(PORTC,(Local_PinNumber-16));
		}
	}
	else if(Local_PinNumber <32)
	{
		if(Local_Value == DIO_HIGH)
		{
			SETBIT(PORTD,(Local_PinNumber-24));
		}
		else 
		{
			CLRBIT(PORTD,(Local_PinNumber-24));
		}
	}		
	else
	{
		
	}
}

u8 DIO_u8GetPin(u8 Local_PinNumber)
{
	u8 ret=DIO_LOW;
	
	if(Local_PinNumber <8)
	{
		if(GETBIT(PINA,Local_PinNumber)==1)
		{
			ret = DIO_HIGH;
		}
		else
		{
			ret = DIO_LOW;
		}
	}
	else if(Local_PinNumber <16)
	{
		if(GETBIT(PINB,Local_PinNumber-8)==1)
		{
			ret = DIO_HIGH;
		}
		else
		{
			ret = DIO_LOW;
		}
	}
	else if(Local_PinNumber <24)
	{
		if(GETBIT(PINC,Local_PinNumber-16)==1)
		{
			ret = DIO_HIGH;
		}
		else
		{
			ret = DIO_LOW;
		}
	}
	else if(Local_PinNumber <32)
	{
		if(GETBIT(PIND,Local_PinNumber-24)==1)
		{
			ret = DIO_HIGH;
		}
		else
		{
			ret = DIO_LOW;
		}
	}
	return ret;
}

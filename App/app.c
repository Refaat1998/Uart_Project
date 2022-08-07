#include "std_types.h"
#include "utils.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "UART_int.h"


void main(void){
	
	while(1){
		u8 data = 'H';
		UART_voidInit();
		UART_voidSetDataRegister(data);
		_delay_ms(100);
	}
}
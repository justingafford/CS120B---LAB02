
/*	Name & E-mail: Justin Gafford jgaff001@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab #2  Exercise #1
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

int main(void)
{
	//slightly modified code from last example
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char temp = 0x00;
	while(1)
	{
		tmpA = PINA & 0x01;
		temp = PINA & 0x02;
		if (tmpA == 0x01 && temp == 0x00) {
			//only goes off if PA0 = 1 AND PA1 = 0
			tmpB = (tmpB & 0xFC) | 0x01; //output is 1
		}
		else {
			tmpB = (tmpB & 0xFC) | 0x00; //output is 0
		}
		PORTB = tmpB;
	}
	return 0;
}


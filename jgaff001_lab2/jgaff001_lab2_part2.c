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
	DDRA = 0x00; PORTA = 0xFF; //inputs
	DDRC = 0xFF; PORTC = 0x00; //outputs
		unsigned char cntavail = 0;
		unsigned char full = 0;
		unsigned char spaces = 4; //4 because bits 0-3 are 4 spaces total
	while(1) {
		full = (PINA & 0x01) + ((PINA >> 1) & 0x01) + ((PINA  >> 2) & 0x01) + ((PINA >>3) & 0x01); //we compare once for each available space(are bits 0-3 1 or 0?)
		cntavail = spaces - full;
		PORTC = cntavail; 
	}
	return 0;
}

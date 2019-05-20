/*
 * GccApplication2.c
 *
 * Created: 10-05-2019 14:21:15
 * Author : G J S S BHANU
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define RS 7
#define E 5
void send_command(unsigned char command);
void send_character(unsigned char character);


int main(void)
{
	DDRC=0XFF;
	DDRD=0XFF;
	_delay_ms(50);

	send_command(0X01);
	send_command(0X38);
	send_command(0X0E);
	
	
	send_character(0X66);
	send_character(0X67);
	send_character(0X68);
	send_character(0X69);
	send_character(0X70);
}
	
	void send_command(unsigned char command)
	{
		PORTC=command;
		PORTD&=~(1<<RS);
		PORTD|=(1<<E);
		_delay_ms(50);
		PORTD &=~(1<<E);
		PORTC=0;
	}

   void send_character(unsigned char character)
  {
	PORTC=character;
	PORTD|=(1<<RS);
	PORTD|=(1<<E);
	_delay_ms(50);
	PORTD &=~(1<<E);
	PORTC=0;
 }  
	
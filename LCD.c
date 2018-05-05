/*
 * LCD.c
 *
 * Created: 4/30/2018 4:49:55 PM
 *  Author: Mark
 */ 
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL;
#include "LCD.h"
void vLcdInit(void)
{
	_delay_ms(15);
	//rs output
	Control_dir|=(OUTPUT<<RS);
	//enable output
	Control_dir|=(OUTPUT<<ENABLE);
	//set data lines as output
	Control_port&=~(1<<RS);
	Control_port&=~(1<<ENABLE);
	Data_dir|=(OUTPUT<<D4);
	Data_dir|=(OUTPUT<<D5);
	Data_dir|=(OUTPUT<<D6);
	Data_dir|=(OUTPUT<<D7);		
	
	vSendCommand(0x33);
	_delay_ms(100);
	vSendCommand(0x32);
	_delay_ms(100);
	vSendCommand(0x28);
	_delay_ms(100);
	vSendCommand(0x0e);
	_delay_ms(100);
	vSendCommand(0x01);
	_delay_ms(100);
	vSendCommand(0x06);
	_delay_ms(100);
	
}
void vRecieveExecute(){
	//turn enable ON
	Control_port|=(1<<ENABLE);
	_delay_ms(10);
	//turn enable OFF
	Control_port&=~(1<<ENABLE);
	_delay_ms(10);
}
static void vSendCommand(unsigned char cmd)
{
		Data_port = (cmd&0b11110000);
		Control_port &=~((1<<RS));
		vRecieveExecute();
		Data_port= ((cmd&0b00001111)<<4);
		Control_port &=~((1<<RS));
		vRecieveExecute();
	}

void vSendCharacter(unsigned char ch)
{
	Data_port = (ch&0b11110000);
	Control_port |=((1<<RS));
	vRecieveExecute();
	Data_port= ((ch&0b00001111)<<4);
	Control_port |=((1<<RS));
	vRecieveExecute();
}
vGotoXy(uint8_t x,uint8_t y)
{
	uint8_t first_char_address[]={0x80,0x88,0xc0,0xc8};
		vSendCommand(first_char_address[y]+(x));
		_delay_ms(100);
}
vSendString(char* str)
{
	uint8_t i=0;
	while (str[i]!=0)
	{
		vSendCharacter(str[i]);
		i++;
}
}

	
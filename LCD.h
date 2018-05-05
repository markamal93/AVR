/*
 * LCD.h
 *
 * Created: 4/30/2018 4:50:13 PM
 *  Author: Mark
 */ 

#include "LCD-config.h"
#ifndef LCD_H_
#define LCD_H_
void vLcdInit(void);
void vRecieveExecute(void);
void vSendCharacter(unsigned char);
static void vSendCommand(unsigned char);
void vSendString(char*);
void vGotoXy (uint8_t,uint8_t);
void vClearDisplay(unsigned char);
void vFourBitMode (unsigned char);

#endif /* LCD_H_ */
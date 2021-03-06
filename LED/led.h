/*
 *  led.c
 *
 *  The simple interrupt driven LED blink driver
 *
 *  Created on: 30 Aug 2017
 *  Version 0.0
 *
 *  Created by Piotr Jankowski
 *  http://www.diymat.co.uk
 *
 */

#ifndef LED_H_
#define LED_H_

#include <stdint.h>

#define LEDNUM					6               //Max number of LEDs
#define ONTIME					0               //|
#define OFFTIME					1               //| Position in the table
#define ONTIMECOUNTER			2               //| ON / OFF time & ON / OFF counters
#define OFFTIMECOUNTER			3               //|
#define NBLINKS					4               //|
#define LED_GLOBALON			5
#define LED_GLOBALOFF			6
#define LED_GLOBALONCOUNTER		7
#define LED_GLOBALOFFCOUNTER	8

#define SINK				0
#define SOURCE				1

#define CALLBACKSUPPORT		1				// End of blink callback
#define GLOBALONOFFSUPPORT  0				// global on/off

#define LED_DIVIDER			10				// Offload SysTick handler by skipping some of them


typedef struct
{
	GPIO_TypeDef 	*GPIO;
	uint8_t			pin;
#if CALLBACKSUPPORT == 1
	void (*CallBack)(int);
#endif
}LED_TypeDef;

void ToggleLED(int led);
int AddLED(GPIO_TypeDef *gpio, uint8_t pin, int type, void (*callback)(int));
#if GLOBALONOFFSUPPORT == 1
void SetTimeLED(int led, uint16_t ontime, uint16_t offtime, uint16_t nblinks, uint16_t globalON, uint16_t globalOFF);
#else
void SetTimeLED(int led, uint16_t ontime, uint16_t offtime, uint16_t nblinks);
#endif
void OnLED(int led);
void OffLED(int led);

void LED_ISR_Callback(void);

#endif /* LED_H_ */

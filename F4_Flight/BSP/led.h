#ifndef __LED_H__
#define __LED_H__

#include "system.h"
#include "systick.h"

void Led_Init(void);
// ��ɫLED
#define LED1_ON		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
#define LED1_OFF	GPIO_SetBits(GPIOB, GPIO_Pin_12);

// ��ɫLED
#define LED2_ON		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
#define LED2_OFF	GPIO_SetBits(GPIOB, GPIO_Pin_13);

void Led_Red_Twinkle(uint8_t count);

#endif	// __LED_H__


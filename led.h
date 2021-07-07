#ifndef _H_LED_
#define _H_LED_
#include "stm8s.h"
#include "stm8s_gpio.h"

/* Private defines -----------------------------------------------------------*/
/* LED 端口定义 */
#define LED_PORT	GPIOC	
#define LED_1       GPIO_PIN_3
#define LED_2       GPIO_PIN_4
#define LED_3       GPIO_PIN_5
#define LED_4       GPIO_PIN_6
#define LED_5       GPIO_PIN_7

#define LED1_PORT	GPIOB
#define LED_C       GPIO_PIN_4
#define O3          GPIO_PIN_5


#define LED2_PORT	GPIOD
#define LED_UV      GPIO_PIN_5
#define FAN      GPIO_PIN_4
#define HOT      GPIO_PIN_6
#define BUTTON      GPIO_PIN_3
#define ADC        GPIO_PIN_2

#define LED3_PORT	GPIOA
#define BEEZER      GPIO_PIN_2
#define KEY      GPIO_PIN_3 


#define ON  1		/* 低电平*/
#define OFF 0		/* 高电平*/

void LED_Init(void);
void LED_Config(GPIO_Pin_TypeDef led, u8 state);
u8 KEY_SCAN(void);
u8 BUTTON_SCAN(void);
u8 ADC_SCAN(void);
void BEER_ON(void);
void BEER_OFF(void);
void LED_ON(GPIO_Pin_TypeDef led);
void LED_OFF(GPIO_Pin_TypeDef led);
void LED_BLINK(GPIO_Pin_TypeDef led);
void HOT_ON(void);
void HOT_OFF(void);
void FAN_ON(void);
void FAN_OFF(void);
void LEDUV_ON(void);
void LEDUV_OFF(void);
void LEDC_ON(void);
void LEDC_OFF(void);
void O3_ON(void);
void O3_OFF(void);


#endif
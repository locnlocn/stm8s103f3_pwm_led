#include "stm8s.h"
#include "stm8s_gpio.h"
#include "led.h"


/*******************************************************************************
 * 名称: LED_Init
 * 功能: LED外设GPIO引脚初始化操作
 * 形参: 无
 * 返回: 无
 * 说明: 无 
 ******************************************************************************/
void LED_Init(void)
{       
        //定义LED的管脚为输出模式
	GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_SLOW );
        GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_OUT_PP_HIGH_SLOW );
        GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_SLOW );	
        GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_OUT_PP_HIGH_SLOW );
        GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_OUT_PP_HIGH_SLOW );
        GPIO_WriteLow(GPIOC, GPIO_PIN_3);
        GPIO_WriteLow(GPIOC, GPIO_PIN_4);
        GPIO_WriteLow(GPIOC, GPIO_PIN_5);
        GPIO_WriteLow(GPIOC, GPIO_PIN_6);
        GPIO_WriteLow(GPIOC, GPIO_PIN_7);

	GPIO_Init(LED2_PORT, LED_UV, GPIO_MODE_OUT_PP_HIGH_FAST );
        GPIO_Init(LED2_PORT, FAN, GPIO_MODE_OUT_PP_HIGH_FAST );
        GPIO_Init(LED2_PORT, HOT, GPIO_MODE_OUT_PP_HIGH_FAST );
	GPIO_WriteLow(LED2_PORT, LED_UV);
        GPIO_WriteLow(LED2_PORT, FAN);
        GPIO_WriteLow(LED2_PORT, HOT);
        
        GPIO_Init(LED1_PORT, LED_C, GPIO_MODE_OUT_OD_HIZ_FAST );
        GPIO_Init(LED1_PORT, O3, GPIO_MODE_OUT_OD_HIZ_FAST );	
        GPIO_WriteLow(LED1_PORT, LED_C);
        GPIO_WriteLow(LED1_PORT, O3);
        
        GPIO_Init(LED3_PORT, BEEZER, GPIO_MODE_OUT_PP_HIGH_FAST );
        GPIO_WriteLow(LED3_PORT, BEEZER);
        
        GPIO_Init(GPIOD, ADC, GPIO_MODE_IN_PU_NO_IT );
        GPIO_WriteLow(LED2_PORT, ADC);
        
        GPIO_Init(GPIOD, BUTTON, GPIO_MODE_IN_PU_NO_IT );
        GPIO_WriteLow(LED2_PORT, BUTTON);
        
        GPIO_Init(GPIOA, KEY, GPIO_MODE_IN_PU_NO_IT );
        
        
}                               

void LED_Config(GPIO_Pin_TypeDef led, u8 state)
{
    if(ON == state) 
    {
           GPIO_WriteHigh(LED_PORT, led);
    }
    else
    {
          GPIO_WriteLow(LED_PORT, led);
    }
}

u8 KEY_SCAN(void)
{
  if(GPIO_ReadInputPin(GPIOA, GPIO_PIN_3) != RESET) return 0;
  else return 1;
}

u8 BUTTON_SCAN(void)
{
  if(GPIO_ReadInputPin(GPIOD, GPIO_PIN_3) != RESET) return 0;
  else return 1;
}

u8 ADC_SCAN(void)
{
  if(GPIO_ReadInputPin(GPIOD, GPIO_PIN_2) != RESET) return 0;
 else return 1;
}

void BEER_ON(void)
{
    GPIO_WriteHigh(LED3_PORT, BEEZER);
}

void BEER_OFF(void)
{
    GPIO_WriteLow(LED3_PORT, BEEZER);
}

void LED_ON(GPIO_Pin_TypeDef led)
{
    GPIO_WriteHigh(LED_PORT, led);
}

void LED_OFF(GPIO_Pin_TypeDef led)
{
    GPIO_WriteLow(LED_PORT, led);
}

void LED_BLINK(GPIO_Pin_TypeDef led)
{
  if(GPIO_ReadOnputPin(LED_PORT,led)){
      LED_OFF(led);
  }
   else LED_ON(led);
}

void HOT_ON(void)
{
    GPIO_WriteHigh(LED2_PORT, HOT);
}

void HOT_OFF(void)
{
    GPIO_WriteLow(LED2_PORT, HOT);
}

void FAN_ON(void)
{
    GPIO_WriteHigh(LED2_PORT, FAN);
}

void FAN_OFF(void)
{
    GPIO_WriteLow(LED2_PORT, FAN);
}
void LEDUV_ON(void)
{
    GPIO_WriteHigh(LED2_PORT, LED_UV);
}

void LEDUV_OFF(void)
{
    GPIO_WriteLow(LED2_PORT, LED_UV);
}

void LEDC_ON(void)
{
    GPIO_WriteHigh(LED1_PORT, LED_C);
}

void LEDC_OFF(void)
{
    GPIO_WriteLow(LED1_PORT, LED_C);
}
void O3_ON(void)
{
    GPIO_WriteHigh(LED1_PORT, O3);
}

void O3_OFF(void)
{
    GPIO_WriteLow(LED1_PORT, O3);
}
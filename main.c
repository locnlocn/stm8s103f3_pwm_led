#include <stm8s.h>
#include <led.h>
#include <delay.h>
#include <sysclock.h>
#include <stm8s_adc1.h>
#include <stm8s_tim1.h> 

int main(void)
{
  
        signed int pwm_duty = 0;

	/* ϵͳʱ�ӳ�ʼ�� */
	disableInterrupts();
	SystemClock_Init();
	LED_Init();
	//timer1_init();
	//timer2_init();
	enableInterrupts();
        ADC1_DeInit();   //adc csh
        ADC1_Cmd(ENABLE);   //ADC CSH
      /*----- jishiqi pwm */
       

            
             GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_FAST);   //����������͵�ƽ��10MHz
	     TIM1_DeInit();             
	     TIM1_TimeBaseInit(0x0f, TIM1_COUNTERMODE_UP, 10000, 0x00);//               
             TIM1_CCxCmd(TIM1_CHANNEL_4, ENABLE);	   //ʹ�����
             TIM1_OC4PreloadConfig(ENABLE);    //���^��4Ԥ״̬ʹ��
	     TIM1_CtrlPWMOutputs(ENABLE);      //PWM����ʹ��
	     TIM1_Cmd(ENABLE);                 //ʹ�ܼ���
             TIM1_SetCompare4(0);              //�Ƚ�������
             TIM1_SetCounter(0);               //����������
             TIM1_OC4Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, 0, TIM1_OCPOLARITY_LOW, TIM1_OCIDLESTATE_RESET);//����0��ռ�ձȣ�����ΪOC4��ʼ������
  //-------BUTTON_SCAN���º���������---------// 
  /*           int key_num = 9000 ;
             
               while(1)
               {
                 if(BUTTON_SCAN())
                 {
                   delay_ms(20);
                   if(BUTTON_SCAN())
                   {delay_ms(100);
                   if(!BUTTON_SCAN())
                   {
                     key_num = key_num - 100 ;}}
                 }
                 
              TIM1_SetCompare4(key_num); 
               }
}
*/
  //---------������----------//   
             
             while(1)
             {
                  
               for(pwm_duty = 0 ;pwm_duty < 10000 ;pwm_duty = pwm_duty + 50)
             {
                       delay_ms(25);
                       TIM1_SetCompare4(pwm_duty);     //ռ�ձ�
                       if(pwm_duty == 9950){break;}
                       
             }
            //  delay_ms(50);
              for(pwm_duty = 10000 ;pwm_duty >0 ;pwm_duty = pwm_duty - 50 )
              {
                      delay_ms(25);
                       TIM1_SetCompare4(pwm_duty);
                       if(pwm_duty == 50){break;}
              }

               
               
            }                 
   
        
  }
 
		

	



#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
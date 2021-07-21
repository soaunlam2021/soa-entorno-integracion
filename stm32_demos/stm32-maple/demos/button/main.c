#define USE_STDPERIPH_DRIVER
#include "stm32f10x.h"
#include "stm32_f103RB.h"

int main(void)
{
    int last_button_state, new_button_state;

    init_led();
    init_button();

  last_button_state= GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);

   while(1)
   {

   	new_button_state =GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
       if(new_button_state ^ last_button_state)
       {
           if(new_button_state)
           {
				 GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_SET);
           }else
           {
        	   GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
           }
       }
       last_button_state = new_button_state;
   }
}

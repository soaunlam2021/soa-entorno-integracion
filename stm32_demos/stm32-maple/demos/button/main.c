#define USE_STDPERIPH_DRIVER
#include "stm32f10x.h"
#include "stm32_f103RB.h"
#include "profiling.h"

#define TIEMPO_MAX 100

int main(void)
{
    int last_button_state, new_button_state;
    uint32_t tiempo_inicial=0;

    profiling_init();
    init_led();
    init_button();

    last_button_state= GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);


    PROFILING_START("Inicializando");

    tiempo_inicial=get_count_ticks();

   while(1)
   {

	   new_button_state =GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
       if(new_button_state!=0)
       {
        	 PROFILING_STOP();
        	 break;
       }

       if(get_count_ticks()-tiempo_inicial>TIEMPO_MAX)
	   {
		   GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_SET);
		   tiempo_inicial=get_count_ticks();

		   PROFILING_EVENT("prende Led");
	   }
	   else
	   {
		   GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
	   }

   }
}

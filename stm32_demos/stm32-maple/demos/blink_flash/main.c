#define USE_STDPERIPH_DRIVER
#include "stm32f10x.h"
#include "stm32_f103RB.h"
#include "profiling.h"

void busyLoop(uint32_t delay )
{
  while(delay) delay--;
}

int main(void)
{
	int contador=0;
    init_led();
    profiling_init();
    PROFILING_START("Inicializando");
    while(1) {

    	//GPIO_WriteBit(GPIOA,GPIO_Pin_5,Bit_SET);
    	GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_SET);
    	//GPIOC->BRR = 0x00001000;
    	sleep(10);

    	PROFILING_EVENT("Apaga Led");

    	GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
       //GPIOC->BSRR = 0x00001000;
       sleep(20);
       PROFILING_EVENT("prende Led");

       if (contador++>10)
    	    PROFILING_STOP();

    }
}

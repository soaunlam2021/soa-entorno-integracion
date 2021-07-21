#define USE_STDPERIPH_DRIVER
#include "stm32f10x.h"
#include "stm32_f103RB.h"

void busyLoop(uint32_t delay )
{
  while(delay) delay--;
}

int main(void)
{
    init_led();

    while(1) {
    	//GPIO_WriteBit(GPIOA,GPIO_Pin_5,Bit_SET);
    	GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_SET);
    	//GPIOC->BRR = 0x00001000;
       busyLoop(500000);
       GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
       //GPIOC->BSRR = 0x00001000;
       busyLoop(500000);
    }
}

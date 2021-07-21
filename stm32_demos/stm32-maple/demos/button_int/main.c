#define USE_STDPERIPH_DRIVER
#include "stm32f10x.h"
#include "stm32_f103RB.h"

int led_state=0;

/* Handler predefined by STM32 library to handle interrupts on EXTI line 0
 * (which is mapped to the button on GPIO A Line 0).
 */
void EXTI0_IRQHandler(void)
{
    /* Make sure the line has a pending interrupt
     * (should this always be true if we are inside the interrupt handle?) */
    if(EXTI_GetITStatus(EXTI_Line0) != RESET) {
        /* Toggle  the LED */
    	if(led_state==0)
		{
			GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_SET);
			led_state=1;
		}else
		{
			GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
			led_state=0;

		}

        /* Clear the pending interrupt flag that triggered this interrupt.
         * If DO_NOT_CLEAR_IT_PENDING_FLAG is defined, this part is skipped.
         * This will cause the interrupt handler to repeatedly run in an
         * infinite loop (which will cause the LED to repeatedly toggle too
         * fast to be seen).
         */
#ifndef DO_NOT_CLEAR_IT_PENDING_FLAG
        EXTI_ClearITPendingBit(EXTI_Line0);
#endif
    }
}

int main(void)
{
    init_led();

    init_button();
    enable_button_interrupts();

    /* Go into an infinite loop.  When the button is pressed, the interrupt
     * routine will be called.
     */
    while(1);
}





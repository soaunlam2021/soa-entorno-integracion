#define USE_STDPERIPH_DRIVER
#include "stm32f10x.h"
#include "stm32_f103.h"

int led_status=0;

void SysTick_Handler(void)
{
	if(led_status==0)
	{
		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_SET);
		led_status=1;
	}
	else
	{
		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);
		led_status=0;
	}
}

int main(void)
{
    int last_button_state, new_button_state;
    uint32_t hclk_ticks_per_sec, ext_clock_ticks_per_sec;

    init_led();
    init_button();

    /* The Cortex System Timer (SysTick) clock can be driven by the Cortex
     * clock (HCLK), which is the output of the AHB prescaler, or from the
     * external clock, which is HLCK divided by 8.
     * Call SysTick_Config with the number of ticks between Systick interrupts.
     * We will choose this value such that there is one second
     * between interrupts when the external clock (HCLK / 8) is selected.
     * Initially, the Cortex clock (HCLK) will be selected, which means an
     * interrupt every 1/8th of a second.
     */
    hclk_ticks_per_sec = SystemCoreClock;
    ext_clock_ticks_per_sec = hclk_ticks_per_sec / 8;
    if (SysTick_Config(ext_clock_ticks_per_sec))
    {
        /* If SysTick_Config returns 1, that means the number ticks exceeds the
         * limit. */
        while (1);
    }

    /* Infinite loop - when the button changes state, toggle the SysTick clock
     * source.
     */
    last_button_state = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
    while(1) {
        new_button_state = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
        if(new_button_state ^ last_button_state) {
            if(new_button_state) {
                SysTick->CTRL ^= SysTick_CTRL_CLKSOURCE_Msk;
            }
        }
        last_button_state = new_button_state;
    }
}

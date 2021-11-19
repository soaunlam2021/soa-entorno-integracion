/***********************************************************************
 File Name    : 'profiling.c'
 Title        : PROFILER
 Description  : Code time profiler with output to ITM Stimulus Port 0
                Debug (printf) Viewer
                Time accuracy 1�S

                Examle output:
                Profiling "Start" sequence:
                --Event-----------------------|--timestamp--|---delta_t----
                GLCD_Init                     :       41 us | +       41 us
                OLED_Init                     :     5288 us | +     5247 us
                u8g_SetFont                   :     5292 us | +        4 us
                HAL_Delay(10)                 : 10004967 us | +  9999675 us

 Author       : Serj Bashlayev
                https://github.com/Serj-Bashlayev
                email: phreak_ua@yahoo.com
 Created      : 16/08/2016
 Revised      : 04/10/2018
 Version      : 3.0
 Target MCU   : STM32
 Compiler     : ARM Compiler v5.04 for �Vision armcc
 Editor Tabs  : 2
***********************************************************************/

/* Includes ----------------------------------------------------------*/
#include "profiling.h"

/* Private Definitions -----------------------------------------------*/
#define DEBUG_PRINTF myprintf
#define __PROF_STOPED 0xFF

/* External variables ------------------------------------------------*/
/* Private variables -------------------------------------------------*/
static uint32_t   time_start; // profiler start time
static const char *prof_name; // profiler name
static uint32_t   time_event[MAX_EVENT_COUNT]; // events time
static const char *event_name[MAX_EVENT_COUNT]; // events name
static uint8_t    event_count = __PROF_STOPED; // events counter

uint32_t count_ticks=0;
/* Private function prototypes ---------------------------------------*/
/* -------------------------------------------------------------------*/

/**
 * redefinition fputc() for output printf(..) to ITM Stimulus Port 0
 */
struct __FILE { int handle; /* Add whatever needed */ };
FILE __stdout;
FILE __stdin;



void SysTick_Handler(void)
{
	if (count_ticks<MAX_UINT32_T)
		count_ticks++;
	else
		count_ticks=0;


}

void sleep(uint32_t wait)
{
	uint32_t tickstart=count_ticks;

	while ((count_ticks - tickstart) < wait)
	{
	}
}


uint32_t get_count_ticks()
{
	return count_ticks;
}
void profiling_init()
{
	uint32_t hclk_ticks_per_sec, ext_clock_ticks_per_sec;

	SystemCoreClock  = 72000000U;

	hclk_ticks_per_sec = SystemCoreClock/1000U;

	// Update SystemCoreClock value
    //SystemCoreClockUpdate();
    // Configure the SysTick timer to overflow every 1 us
    if (SysTick_Config(hclk_ticks_per_sec))
    {
        /* If SysTick_Config returns 1, that means the number ticks exceeds the
         * limit. */
        while (1);
    }

    count_ticks=0;
	//myprintf_init();

}

/**
 * @brief Start profiler, save profiler name and start time
 *
 * @param profile_name Profiler name
 */
void PROFILING_START(const char *profile_name)
{
  prof_name = profile_name;
  event_count = 0;

  time_start=count_ticks;
}


/**
 * @brief  Event. Save events name and time
 *
 * @param event Event name
 */
void PROFILING_EVENT(const char *event)
{
  if (event_count == __PROF_STOPED)
    return;

  if (event_count < MAX_EVENT_COUNT)
  {
    time_event[event_count] = count_ticks;
    event_name[event_count] = event;
    event_count++;

  }
}


/**
 * @brief Stop profiler. Print event table to ITM Stimulus Port 0
 */
void PROFILING_STOP(void)
{
  int32_t tick_per_1us;
  int32_t time_prev;
  int32_t timestamp;
  int32_t delta_t;

  myprintf_init();


  if (event_count == __PROF_STOPED)
  {
   // DEBUG_PRINTF("\r\nWarning: PROFILING_STOP WITHOUT START.\r\n");
    return;
  }

  myprintf("Profiling \"%s\" sequence: \r\n"
           "--Event-----------------------|--timestamp--|----delta_t---\r\n", prof_name);
  time_prev = 0;

  for (int i = 0; i < event_count; i++)
  {
    timestamp = (time_event[i] - time_start);
    delta_t = timestamp - time_prev;
    time_prev = timestamp;
    myprintf("%-30s:%9d ms | +%9d ms\r\n", event_name[i], timestamp, delta_t);
  }
  myprintf("\r\n");
  event_count = __PROF_STOPED;
}


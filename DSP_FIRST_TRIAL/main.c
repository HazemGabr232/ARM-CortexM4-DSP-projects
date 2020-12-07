

#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "arm_math.h"                   // ARM::CMSIS:DSP

#define SIG_LENGTH	320

extern void SystemClock_Config(void);
extern float32_t inputSignal_f32_1kHz_15kHz[SIG_LENGTH];
void plot_input_signal(void);

uint32_t freq = 0;
float32_t inputSample; 

int main()
{
	HAL_Init();
	SystemClock_Config();
	
	freq = HAL_RCC_GetHCLKFreq();
	//count = 0;

	plot_input_signal();
	while(1)
	{
	

	}
}

void plot_input_signal(void)
{
	int i, j;
	for(i=0 ; i<SIG_LENGTH ; i++)
	{
		inputSample = inputSignal_f32_1kHz_15kHz[i];
		for(j=0 ; j<3000 ; j++){}	//small delay for the logic analyzer 
		
		if(i == SIG_LENGTH - 1)	//this line makes it infinit loop
			i = 0;
	}
	
}

void HAL_SysTick_Handler (void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

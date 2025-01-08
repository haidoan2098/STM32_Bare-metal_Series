#include "RCC.h"
#include "GPIO.h"
#include "AdvancedTimer.h"

#define NVIC_BASE_ADDRESS   0xE000E100UL
#define NVIC_ISER0_ADDRESS  (NVIC_BASE_ADDRESS + 0x00000000UL)


void TIM1_UP_IRQHandler(void)
{
	GPIO_TogglePin(GPIOC, 13);
  // Clean Flag 
  TIM1->TIMx_SR.REG = 0;
}

int main(void)
{
  Config_Clock_Tree();

  // enable clock TIM1
  Enable_RCC_APB2ENR(APB2_TIM1);
  GPIOC_Enable_Clock();


	// Timer TIMEBASE
	GPIO_Mode(GPIOC, 13, GPIO_MODE_OUTPUT_PUSHPULL_50MHz);
	TIM1->TIMx_CR2.REG  = 0;
	TIM1->TIMx_SMCR.REG = 0;
	TIM1->TIMx_DIER.REG = 1;
  TIM1->TIMx_PSC.REG  = 99;   // 100ms
	TIM1->TIMx_ARR.REG  = 7999; // 100ms
  TIM1->TIMx_CR1.REG |= (1 << 7) | (1 << 2) | (1 << 0);

  *((uint32_t *)(NVIC_ISER0_ADDRESS)) |= (1 << 25); // enable NVIC TIM1_UP

  while (1)
  {
  }
}

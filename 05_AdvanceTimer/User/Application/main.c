#include "RCC.h"
#include "GPIO.h"
#include "AdvancedTimer.h"

#define NVIC_BASE_ADDRESS 0xE000E100UL
#define NVIC_ISER0_ADDRESS (NVIC_BASE_ADDRESS + 0x00000000UL)

void TIM1_UP_IRQHandler(void)
{
  GPIO_TogglePin(GPIOC, 13);
  TIM1->TIMx_SR.REG = 0;    // Clean Flag
}

int main(void)
{
  Config_Clock_Tree();

  // Enable clock TIM1
  Enable_RCC_APB2ENR(APB2_TIM1);
  GPIOC_Enable_Clock();
  GPIOA_Enable_Clock();

  // Timer TIMEBASE
  GPIO_Mode(GPIOC, 13, GPIO_MODE_OUTPUT_PUSHPULL_50MHz);
  // TIM1->TIMx_CR2.REG  = 0;
  // TIM1->TIMx_SMCR.REG = 0;
  // TIM1->TIMx_DIER.REG = 1;
  // TIM1->TIMx_PSC.REG  = 7999;   // 100ms
  // TIM1->TIMx_ARR.REG  = 99;     // 100ms
  // TIM1->TIMx_CR1.REG |= (1 << 7) | (1 << 2) | (1 << 0);

  // *((uint32_t *)(NVIC_ISER0_ADDRESS)) |= (1 << 25); // enable NVIC TIM1_UP


  // PWM Register
  GPIO_Mode(GPIOA, 8, GPIO_MODE_AF_OUTPUT_PUSHPULL_50MHz);
  TIM1->TIMx_CCMR1.REG |= (6 << 4);

  TIM1->TIMx_BDTR.REG |= (1 << 15) | (1 << 11) | (1 << 10);

  TIM1->TIMx_CCER.REG |= 1;

  TIM1->TIMx_PSC.REG = 7999; // 100ms
  TIM1->TIMx_ARR.REG = 99;   // 100ms
  TIM1->TIMx_CCR1.REG = 40;  // 40%

  TIM1->TIMx_EGR.REG = 1;
  TIM1->TIMx_CR1.REG |= (1 << 7) | (1 << 2) | (1 << 0);

  while (1)
  {
  }
}

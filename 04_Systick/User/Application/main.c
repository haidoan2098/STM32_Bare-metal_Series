#include "SYSTICK.h"
#include "RCC.h"
#include "GPIO.h"

void SysTick_Handler(void)
{
  GPIO_TogglePin(GPIOC, 13);
}

int main(void)
{
  Config_Clock_Tree();

  GPIOC_Enable_Clock();

  GPIO_Mode(GPIOC, 13, GPIO_MODE_OUTPUT_PUSHPULL_50MHz);

  STK->STK_VAL = 3999999;
  STK->STK_LOAD = 3999999;

  STK->STK_CTRL.REG |= (1 << 2) | (1 << 1) | (1 << 0);

  while (1)
  {
  }
}

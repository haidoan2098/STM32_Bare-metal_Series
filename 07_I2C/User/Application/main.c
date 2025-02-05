#include "RCC.h"
#include "GPIO.h"
#include "I2C.h"

/* 
 *  TX: Check with Logic Analyzer 
 *  RX: Check with Hercules 
 */


void delay_ms(unsigned long ms) 
{
    for (unsigned long i = 0; i < ms*1000; i++) 
    {
        __asm("nop");
    }
}





int main(void)
{
  Config_Clock_Tree();
    
  Enable_RCC_APB1ENR(APB1_I2C1);  
  GPIOB_Enable_Clock();             // PB6 I2C1_SCL | PB7 I2C1_SDA 

  // PA9-UART1-TX, PA10-UART1-RX
	GPIO_Mode(GPIOB, 6, GPIO_MODE_AF_OUTPUT_OPENDRAIN_50MHz);
	GPIO_Mode(GPIOB, 7, GPIO_MODE_AF_OUTPUT_OPENDRAIN_50MHz);


  while (1)
  {

  }
}

#include "RCC.h"
#include "GPIO.h"
#include "UART.h"

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


// TX - Transmit 1 Byte
void UART1_Send_Char(uint8_t data)  
{
	while(!(USART1->USART_SR.BITS.TXE));
	USART1->USART_DR.REG = data;
}

// TX - Transmit String
void UART1_Send_String(uint8_t *TXBuffer, uint16_t leng) 
{
  for(uint16_t i = 0; i < leng; i++)
  {
    UART1_Send_Char(TXBuffer[i]);
  }
}

// RX Interrupt
uint8_t received_data;
void USART1_IRQHandler(void) 
{
	if(USART1->USART_SR.BITS.RXNE)
  {
	  received_data = USART1->USART_DR.REG;
		USART1->USART_DR.REG = received_data;
	}
}


uint8_t TXBuffer[12] = "Hello World";


int main(void)
{
  Config_Clock_Tree();

  GPIOA_Enable_Clock();
  Enable_RCC_APB2ENR(APB2_USART1);

  // PA9-UART1-TX, PA10-UART1-RX
  GPIO_Mode(GPIOA, 9, GPIO_MODE_AF_OUTPUT_PUSHPULL_50MHz);
  GPIO_Mode(GPIOA, 10, GPIO_MODE_INPUT_FLOATING);

  // Boud 9600
  USART1->USART_BRR.REG = 0x0341;

  USART1->USART_CR1.REG = (1 << 13) | (1 << 5) | (1 << 3) | (1 << 2);

  *((unsigned long *) 0xE000E104) = (1 << (37 - 32)); // Enable IRQ 37


  while (1)
  {
    UART1_Send_String(TXBuffer, 12);
		delay_ms(100);
  }
}

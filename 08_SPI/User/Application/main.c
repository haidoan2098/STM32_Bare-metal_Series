#include "RCC.h"
#include "GPIO.h"
#include "SPI.h"

void delay_ms(unsigned long ms) 
{
    for (unsigned long i = 0; i < ms*1000; i++) 
    {
        __asm("nop");
    }
}

void SPI1_Transmit_char(char data)
{
  while(!(SPI1->SPI_SR.BITS.TXE));
  SPI1->SPI_DR.REG = data;
}

void SPI1_Transmit_string(char *str, uint8_t leng)
{
  for(int i = 0; i < leng; i++)
  {
    SPI1_Transmit_char(str[i]);
  }
}

uint8_t SPI1_Receive(void)
{
  while(!(SPI1->SPI_SR.BITS.RXNE));
  return SPI1->SPI_DR.REG;
}


int main(void)
{
  Config_Clock_Tree();
    
  Enable_RCC_APB2ENR(APB2_SPI1);  
  GPIOA_Enable_Clock();             

  // PA9-UART1-TX, PA10-UART1-RX
	GPIO_Mode(GPIOA, 4, GPIO_MODE_AF_OUTPUT_PUSHPULL_50MHz);          // NSS
	GPIO_Mode(GPIOA, 5, GPIO_MODE_AF_OUTPUT_PUSHPULL_50MHz);          // CLK
  GPIO_Mode(GPIOA, 6, GPIO_MODE_INPUT_FLOATING);                    // MISO
  GPIO_Mode(GPIOA, 7, GPIO_MODE_AF_OUTPUT_PUSHPULL_50MHz);          // MOSI

  SPI1->SPI_CR1.REG |= (1 << 2) | (3 << 3) | (1 << 6);

  while (1)
  {
    SPI1_Transmit_char(0xA5);
    delay_ms(100);
  }
}

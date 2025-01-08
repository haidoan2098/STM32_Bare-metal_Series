#include "RCC.h"
#include "FLASH.h"
#include "GPIO.h"

// Delay Time (milliseconds)
void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++)
    {
        for (uint32_t j = 0; j < 1000; j++)
        {
            __asm("nop");
        }
    }
}


int main()
{
    /* Measure Clock at MCO Pin - A8 */

    // Enable Port A
    // RCC->RCC_APB2ENR.BITS.IOPAEN = 1;

    // Enable MCO
    // RCC->RCC_CFGR.BITS.MCO = 4;


    // Clock configuration at maximum - 72MHz
    FLASH->FLASH_ACR.REG |= 2;

	RCC->RCC_CR.REG |= 1 << 16;
    while(!RCC->RCC_CR.BITS.HSERDY);

    RCC->RCC_CFGR.REG |= 9 << 18;
	RCC->RCC_CFGR.REG |= 1 << 16;

    RCC->RCC_CR.REG |= 1 << 24;
	while(!RCC->RCC_CR.BITS.PLL_RDY);

    RCC->RCC_CFGR.BITS.SW = 2;
	while(!(RCC->RCC_CFGR.BITS.SWS == 2));


    // Enable Port C
    RCC->RCC_APB2ENR.BITS.IOPCEN = 1;

    // LED GPIOC_PIN_13
    GPIO_Mode(GPIOC, 13, GPIO_MODE_OUTPUT_PUSHPULL_50MHz);
    

    while (1)
    {
        /* Blink LED PC 13 */
        GPIO_TogglePin(GPIOC, 13);
        delay_ms(500);
    }
}

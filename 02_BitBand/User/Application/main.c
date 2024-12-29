#include "BITBAND.h"
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


#define RCC_APB2ENR (*((volatile uint32_t *)(0x40021000 + 0x18)))
#define RCC_IOPCEN  (1 << 4)


int main()
{
    // Enable Port C
    RCC_APB2ENR |= RCC_IOPCEN;

    // LED GPIOC_PIN_13
    GPIO_Mode(GPIOC, 13, GPIO_MODE_OUTPUT_PUSHPULL_10MHz);
    
    // GPIOC->ODR Bit 13
    // uint32_t *alias_address_GPIOC_ODR_13 = (uint32_t *)BITBAND_PERIPHERAL_ADDRESS(&GPIOC->ODR, 13);

    // GPIOC->BSRR Bit 13
    uint32_t *alias_address_GPIOC_BSRR_13 = (uint32_t *)BITBAND_PERIPHERAL_ADDRESS(&GPIOC->BSRR, 13);
    // GPIOC->BSRR Bit 29
    uint32_t *alias_address_GPIOC_BSRR_29 = (uint32_t *)BITBAND_PERIPHERAL_ADDRESS(&GPIOC->BSRR, 13 + 16);

    while (1)
    {
        /* Bit Band - Blink LED PC 13 */

        // *alias_address_GPIOC_ODR_13 = 0; 
        // delay_ms(1000);
        // *alias_address_GPIOC_ODR_13 = 1;
        // delay_ms(1000);

        *alias_address_GPIOC_BSRR_13 = 1;
        delay_ms(1000);
        *alias_address_GPIOC_BSRR_29 = 1;
        delay_ms(1000);
    }
}

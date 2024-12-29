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


// Check the status of the button.
GPIO_STATE testButton;  

int main()
{
    // Enable Port C
    RCC_APB2ENR |= RCC_IOPCEN;

    // LED GPIOC_PIN_13
    GPIO_Mode(GPIOC, 13, GPIO_MODE_OUTPUT_PUSHPULL_10MHz);
 
    // Button GPIOC_PIN_14
    GPIO_Mode(GPIOC, 14, GPIO_MODE_INPUT_PULL);

    while (1)
    {
        testButton = GPIO_ReadPin(GPIOC, 14);

        GPIO_TogglePin(GPIOC, 13);
        delay_ms(1000);

        // GPIO_WritePin(GPIOC, 13, GPIO_SET);
        // delay_ms(1000);
        // GPIO_WritePin(GPIOC, 13, GPIO_RESET);
        // delay_ms(1000);
    }
}

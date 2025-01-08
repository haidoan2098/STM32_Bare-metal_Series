/*
 *  GPIO.c
 *
 *  Created on: Dec 22, 2024
 *      Author: haidoan2098
 */

#include "GPIO.h"

/*
 * There are two variables: set and reset.
 * - `set` is used to enable "Mode" for the register.
 * - `reset` is used to clear the register value to 0.
 * I will reset the register first and then set the register value
 * register CRH for gpio 8 - 15
 * register CRL for gpio 0 - 8
 */
void GPIO_Mode(volatile GPIO_TypeDef *GPIOx, uint8_t GPIO_PIN_Number, GPIO_MODE Mode)
{
    uint32_t position = (GPIO_PIN_Number % 8) * 4;  // The 'Mode' position needs to be changed.
    uint32_t reset = 0xF << position;               // Bit mask to clear old bits
    uint32_t set = Mode << position;                // Bit mask to set new bits 

    if (GPIO_PIN_Number > 7)
    {
        GPIOx->CRH.REG &= ~reset;
        GPIOx->CRH.REG |= set;
    }
    else
    {
        GPIOx->CRL.REG &= ~reset;
        GPIOx->CRL.REG |= set;
    }
}

GPIO_STATE GPIO_ReadPin(volatile GPIO_TypeDef *GPIOx, uint8_t GPIO_PIN_Number)
{
    return (GPIO_STATE)((GPIOx->IDR.REG >> GPIO_PIN_Number) & 1);
}

void GPIO_WritePin(volatile GPIO_TypeDef *GPIOx, uint8_t GPIO_PIN_Number, GPIO_STATE SetOrRst)
{
    if (SetOrRst == GPIO_RESET)
    {
        GPIOx->BSRR.REG = (1UL << (16 + GPIO_PIN_Number)); // Reset bit (16–31)
    }
    else
    {
        GPIOx->BSRR.REG = (1UL << GPIO_PIN_Number); // Set bit (0–15)
    }
}

/*
 * Use the ODR register to read the status,
 * then based on the high or low level, move it to the high or low bit to set or clean.
 */
void GPIO_TogglePin(volatile GPIO_TypeDef *GPIOx, uint8_t GPIO_PIN_Number)
{
    GPIOx->BSRR.REG = (1UL << (16 * ((GPIOx->ODR.REG >> GPIO_PIN_Number) & 1) + GPIO_PIN_Number));
}

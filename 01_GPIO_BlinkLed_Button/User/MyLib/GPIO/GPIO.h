/*
 * stm32f103xx_gpio.h
 *
 *  Created on: Dec 22, 2024
 *      Author: haidoan2098
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>


/*
 * @brief: The structure definition of GPIO is a set of registers.
 */
typedef struct
{
	union
	{
		uint32_t REG;
		struct
		{
			uint32_t MODE_0  : 2;
			uint32_t  CNF_0  : 2;
			uint32_t MODE_1  : 2;
			uint32_t  CNF_1  : 2;
			uint32_t MODE_2  : 2;
			uint32_t  CNF_2  : 2;
			uint32_t MODE_3  : 2;
			uint32_t  CNF_3  : 2;
			uint32_t MODE_4  : 2;
			uint32_t  CNF_4  : 2;
			uint32_t MODE_5  : 2;
			uint32_t  CNF_5  : 2;
			uint32_t MODE_6  : 2;
			uint32_t  CNF_6  : 2;
			uint32_t MODE_7  : 2;
			uint32_t  CNF_7  : 2;
		} BITS;
	} CRL;

	union
	{
		uint32_t REG;
		struct
		{
			uint32_t MODE_8  : 2;
			uint32_t  CNF_8  : 2;
			uint32_t MODE_9  : 2;
			uint32_t  CNF_9  : 2;
			uint32_t MODE_10 : 2;
			uint32_t  CNF_10 : 2;
			uint32_t MODE_11 : 2;
			uint32_t  CNF_11 : 2;
			uint32_t MODE_12 : 2;
			uint32_t  CNF_12 : 2;
			uint32_t MODE_13 : 2;
			uint32_t  CNF_13 : 2;
			uint32_t MODE_14 : 2;
			uint32_t  CNF_14 : 2;
			uint32_t MODE_15 : 2;
			uint32_t  CNF_15 : 2;
		} BITS;
	} CRH;

	union
	{
		uint32_t REG;
		struct
		{
			uint32_t b0  : 1;
			uint32_t b1  : 1;
			uint32_t b2  : 1;
			uint32_t b3  : 1;
			uint32_t b4  : 1;
			uint32_t b5  : 1;
			uint32_t b6  : 1;
			uint32_t b7  : 1;
			uint32_t b8  : 1;
			uint32_t b9  : 1;
			uint32_t b10 : 1;
			uint32_t b11 : 1;
			uint32_t b12 : 1;
			uint32_t b13 : 1;
			uint32_t b14 : 1;
			uint32_t b15 : 1;
			uint32_t _reserved : 16;
		} BITS;
	} IDR;

	union
	{
		uint32_t REG;
		struct
		{
			uint32_t b0  : 1;
			uint32_t b1  : 1;
			uint32_t b2  : 1;
			uint32_t b3  : 1;
			uint32_t b4  : 1;
			uint32_t b5  : 1;
			uint32_t b6  : 1;
			uint32_t b7  : 1;
			uint32_t b8  : 1;
			uint32_t b9  : 1;
			uint32_t b10 : 1;
			uint32_t b11 : 1;
			uint32_t b12 : 1;
			uint32_t b13 : 1;
			uint32_t b14 : 1;
			uint32_t b15 : 1;
			uint32_t _reserved : 16;
		} BITS;
	} ODR;

    union
    {
        uint32_t REG;
        struct
        {
            struct
            {
                uint16_t b0  : 1;
                uint16_t b1  : 1;
                uint16_t b2  : 1;
                uint16_t b3  : 1;
                uint16_t b4  : 1;
                uint16_t b5  : 1;
                uint16_t b6  : 1;
                uint16_t b7  : 1;
                uint16_t b8  : 1;
                uint16_t b9  : 1;
                uint16_t b10 : 1;
                uint16_t b11 : 1;
                uint16_t b12 : 1;
                uint16_t b13 : 1;
                uint16_t b14 : 1;
                uint16_t b15 : 1;
            } BSR;

            struct
            {
                uint16_t b0  : 1;
                uint16_t b1  : 1;
                uint16_t b2  : 1;
                uint16_t b3  : 1;
                uint16_t b4  : 1;
                uint16_t b5  : 1;
                uint16_t b6  : 1;
                uint16_t b7  : 1;
                uint16_t b8  : 1;
                uint16_t b9  : 1;
                uint16_t b10 : 1;
                uint16_t b11 : 1;
                uint16_t b12 : 1;
                uint16_t b13 : 1;
                uint16_t b14 : 1;
                uint16_t b15 : 1;
            } BR;
        };
    } BSRR;

	union
	{
		uint32_t REG;
		struct
		{
			uint32_t b0  : 1;
			uint32_t b1  : 1;
			uint32_t b2  : 1;
			uint32_t b3  : 1;
			uint32_t b4  : 1;
			uint32_t b5  : 1;
			uint32_t b6  : 1;
			uint32_t b7  : 1;
			uint32_t b8  : 1;
			uint32_t b9  : 1;
			uint32_t b10 : 1;
			uint32_t b11 : 1;
			uint32_t b12 : 1;
			uint32_t b13 : 1;
			uint32_t b14 : 1;
			uint32_t b15 : 1;
			uint32_t _reserved : 16;
		} BITS;
	} BRR;

	union
	{
		uint32_t REG;
		struct
		{
			uint32_t b0  : 1;
			uint32_t b1  : 1;
			uint32_t b2  : 1;
			uint32_t b3  : 1;
			uint32_t b4  : 1;
			uint32_t b5  : 1;
			uint32_t b6  : 1;
			uint32_t b7  : 1;
			uint32_t b8  : 1;
			uint32_t b9  : 1;
			uint32_t b10 : 1;
			uint32_t b11 : 1;
			uint32_t b12 : 1;
			uint32_t b13 : 1;
			uint32_t b14 : 1;
			uint32_t b15 : 1;
			uint32_t LOCK : 1;
			uint32_t _reserved : 15;
		} BITS;
	} LCKR;

} GPIO_TypeDef;


/*
* @brief: Ep kieu con tro cho dia chi tho cua GPIO
*
* - Dia chi tho la dia chi so nguyen dai dien cho vi tri vat ly trong bo nho.
*   Vi du: 0x40020000 la dia chi vat ly dai dien cho base address cua GPIO_A.
*
* - Ban chat cua viec ep kieu la thay doi cach Compiler dien giai du lieu tai dia chi do:
*   + uint8_t*:  doc 1 byte tai dia chi do.
*   + uint16_t*: doc 2 byte lien tiep tu dia chi do.
*   + uint32_t*: doc 4 byte lien tiep tu dia chi do.
*
* - Viec ep kieu dia chi thanh con tro, ma con tro nay tro den vung cau truc thanh ghi ta da dinh nghia,
*   se quan ly toan bo dia chi trong day => quan ly toan bo du lieu.
*/

/* Address of GPIOx in Memory */
#define GPIOA ((GPIO_TypeDef *)0x40010800)		
#define GPIOB ((GPIO_TypeDef *)0x40010C00)
#define GPIOC ((GPIO_TypeDef *)0x40011000)


/*
* @brief: Consider 4 bits to configure the GPIO MODE (CNFx[1:0] MODEx[1:0])
*/
typedef enum
{															// CNF[1:0]	 MODE[1:0]
	GPIO_MODE_INPUT_ANALOG 				= (0 << 2) | 0,		//	 00			00
	GPIO_MODE_INPUT_FLOATING 			= (1 << 2) | 0,		// 	 01			00
	GPIO_MODE_INPUT_PULL 				= (2 << 2) | 0,		//	 10			00

	GPIO_MODE_OUTPUT_PUSHPULL_10MHz 	= (0 << 2) | 1, 	// 	 00			01
	GPIO_MODE_OUTPUT_OPENDRAIN_10MHz 	= (1 << 2) | 1, 	// 	 01			01
	GPIO_MODE_AF_OUTPUT_PUSHPULL_10MHz 	= (2 << 2) | 1, 	// 	 10			01
	GPIO_MODE_AF_OUTPUT_OPENDRAIN_10MHz = (3 << 2) | 1,		//	 11			01

	GPIO_MODE_OUTPUT_PUSHPULL_2MHz 		= (0 << 2) | 2, 	// 	 00			10
	GPIO_MODE_OUTPUT_OPENDRAIN_2MHz 	= (1 << 2) | 2, 	// 	 01			10
	GPIO_MODE_AF_OUTPUT_PUSHPULL_2MHz 	= (2 << 2) | 2, 	//	 10			10
	GPIO_MODE_AF_OUTPUT_OPENDRAIN_2MHz 	= (3 << 2) | 2, 	//	 11			10

	GPIO_MODE_OUTPUT_PUSHPULL_50MHz 	= (0 << 2) | 3, 	//	 00			11
	GPIO_MODE_OUTPUT_OPENDRAIN_50MHz 	= (1 << 2) | 3, 	//	 01			11
	GPIO_MODE_AF_OUTPUT_PUSHPULL_50MHz 	= (2 << 2) | 3, 	// 	 10 		11
	GPIO_MODE_AF_OUTPUT_OPENDRAIN_50MHz = (3 << 2) | 3		// 	 11			11
} GPIO_MODE;


/*
* @brief: GPIO State
*/
typedef enum
{
	GPIO_RESET 	= 0,
	GPIO_SET 	= 1
} GPIO_STATE;


/*
* @brief: Select the operating mode of the GPIO Pin
*/
void GPIO_Mode(volatile GPIO_TypeDef* GPIOx, uint8_t GPIO_PIN_Number, GPIO_MODE Mode);

/*
* @brief: Read the input state of a GPIO Pin
*/
GPIO_STATE GPIO_ReadPin(volatile GPIO_TypeDef* GPIOx, uint8_t GPIO_PIN_Number);

/*
* @brief: Write the output state of a GPIO Pin
*/
void GPIO_WritePin(volatile GPIO_TypeDef* GPIOx, uint8_t GPIO_PIN_Number, GPIO_STATE SetOrRst);

/*
* @brief: Toggle the output state of a GPIO Pin
*/
void GPIO_TogglePin(volatile GPIO_TypeDef* GPIOx, uint8_t GPIO_PIN_Number);


#endif /* GPIO_H_ */

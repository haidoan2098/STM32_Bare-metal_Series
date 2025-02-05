/*
 *  RCC.h
 *
 *  Created on: Dec 30, 2024
 *      Author: haidoan2098
 */

#ifndef _RCC_H_
#define _RCC_H_

#include <stdint.h>

typedef struct
{
	union 
    {
		uint32_t REG;
		struct 
        {
			uint32_t HSION       		: 1;  // Internal high-speed clock enable
			const uint32_t HSIRDY 		: 1;  // Internal high-speed clock ready flag. use const variabl to not allow write this bit
			uint32_t _reserved_1   	 	: 1;
			uint32_t HSITRIM      		: 5;  // Internal high-speed clock trimming
			const uint32_t HSICAL       : 8;  // Internal high-spped clock calibration
			uint32_t HSEON        		: 1;  // HSE clock enable
			const uint32_t HSERDY	    : 1;  // External high-speed clock ready flag
			uint32_t HSEBYP       		: 1;  // External high-speed clock bypass
			uint32_t CSSON        		: 1;
			uint32_t _reserved_2    	: 4;
			uint32_t PLLON   	   		: 1;
			uint32_t PLL_RDY      		: 1;
			uint32_t PLL2_ON      		: 1;
			const uint32_t PLL2_RDY  	: 1;
			uint32_t PLL3_ON      		: 1;
			const uint32_t PLL3_RDY     : 1;
			uint32_t _reserved_3    	: 2;
		} BITS;
	} RCC_CR;

	union 
    {
		uint32_t REG;
		struct 
        {
			uint32_t SW 		        : 2;
			const uint32_t SWS 	    	: 2;
			uint32_t HPRE				: 4;
			uint32_t PPRE1				: 3;
			uint32_t PPRE2				: 3;
			uint32_t ADCPRE 			: 2;
			uint32_t PLLSRC			    : 1;
			uint32_t PLLXTPRE			: 1;
			uint32_t PLLMUL			    : 4;
			uint32_t OTGFSPRE			: 1;
			uint32_t _reserved_1		: 1;
			uint32_t MCO   			    : 4;
			uint32_t _reserved_2		: 4;
		} BITS;
	} RCC_CFGR;

	union 
    {
		uint32_t REG;
		struct 
        {
			const uint32_t SIRDYF 		: 1;
			const uint32_t LSERDYF 	    : 1;
			const uint32_t HSIRDYF		: 1;
			const uint32_t HSERDYF		: 1;
			const uint32_t PLLRDYF		: 1;
			const uint32_t PLL2RDYF 	: 1;
			const uint32_t PLL3RDY		: 1;
			const uint32_t CSSF  		: 1;
			uint32_t LSIRDYIE			: 1;
			uint32_t LSERDYIE			: 1;
			uint32_t HSIRDYIE			: 1;
			uint32_t HSERDYIE   		: 1;
			uint32_t PLLRDYIE			: 1;
			uint32_t PLL2RDYIE			: 1;
			uint32_t PLL3RDYIE			: 1;
			uint32_t _reserved_1		: 1;
			uint32_t LSIRDYC			: 1;
			uint32_t LSERDYC			: 1;
			uint32_t HSIRDYC			: 1;
			uint32_t HSERDYC			: 1;
			uint32_t PLLRDYC			: 1;
			uint32_t PLL2RDYC			: 1;
			uint32_t PLL3RDYC			: 1;
			uint32_t CSSC  			    : 1;
			uint32_t _reserved_2		: 8;
		} BITS;
	} RCC_CIR;

	union 
    {
		uint32_t REG;
		struct 
        {
			uint32_t AFIORST 		    : 1;
			uint32_t _reserved_1		: 1;
			uint32_t IOPARST		    : 1;
			uint32_t IOPBRST			: 1;
			uint32_t IOPCRST			: 1;
			uint32_t IOPDRST 			: 1;
			uint32_t IOPERST			: 1;
			uint32_t _reserved_2  		: 2;
			uint32_t ADC1RST			: 1;
			uint32_t ADC2RST			: 1;
			uint32_t TIM1RST			: 1;
			uint32_t SPI1RST   		    : 1;
			uint32_t _reserved_3		: 1;
			uint32_t USART1RST			: 1;
			uint32_t _reserved_4		: 17;
		} BITS;
	} RCC_APB2RSTR;

	union 
    {
		uint32_t REG;
		struct 
        {
			uint32_t TIM2RST 		    : 1;
			uint32_t TIM3RST			: 1;
			uint32_t TIM4RST		    : 1;
			uint32_t TIM5RST			: 1;
			uint32_t TIM6RST			: 1;
			uint32_t TIM7RST 			: 1;
			uint32_t _reserved_1		: 5;
			uint32_t WWDGRST  	    	: 1;
			uint32_t _reserved_2		: 2;
			uint32_t SPI2RST			: 1;
			uint32_t SPI3RST			: 1;
			uint32_t _reserved_3   		: 1;
			uint32_t USART2RST			: 1;
			uint32_t USART3RST			: 1;
			uint32_t USART4RST			: 1;
			uint32_t USART5RST			: 1;
			uint32_t I2C1RST			: 1;
			uint32_t I2C2RST			: 1;
			uint32_t _reserved_4   		: 2;
			uint32_t CAN1RST			: 1;
			uint32_t CAN2RST			: 1;
			uint32_t BKPRST			    : 1;
			uint32_t PWRRST			    : 1;
			uint32_t DACRST			    : 1;
			uint32_t _reserved_5   		: 2;
		} BITS;
	} RCC_APB1RSTR;

	union 
    {
		uint32_t REG;
		struct 
        {
			uint32_t DMA1EN 		    : 1;
			uint32_t DMA2EN			    : 1;
			uint32_t SRAMEN		        : 1;
			uint32_t _reserved_1		: 1;
			uint32_t FLITFEN			: 1;
			uint32_t _reserved_2		: 1;
			uint32_t CRCEN				: 1;
			uint32_t _reserved_3  	    : 5;
			uint32_t OTGFSEN			: 1;
			uint32_t _reserved_4		: 1;
			uint32_t ETHMACEN			: 1;
			uint32_t ETHMACTXEN   		: 1;
			uint32_t ETHMACRXEN		    : 1;
			uint32_t _reserved_5   		: 15;
		} BITS;
	} RCC_AHBENR;

	union 
    {
		uint32_t REG;
		struct 
        {
			uint32_t AFIOEN		        : 1;
			uint32_t _reserved_1	    : 1;
			uint32_t IOPAEN		        : 1;
			uint32_t IOPBEN			    : 1;
			uint32_t IOPCEN			    : 1;
			uint32_t IOPDEN			    : 1;
			uint32_t IOPEEN			    : 1;
			uint32_t _reserved_2  		: 2;
			uint32_t ADC1EN			    : 1;
			uint32_t ADC2EN			    : 1;
			uint32_t TIM1EN			    : 1;
			uint32_t SPI1EN   		    : 1;
			uint32_t _reserved_3		: 1;
			uint32_t USART1EN			: 1;
			uint32_t _reserved_4		: 17;
		} BITS;
	} RCC_APB2ENR;

	union 
    {
		uint32_t REG;
		struct 
        {
			uint32_t TIM2EN 		    : 1;
			uint32_t TIM3EN	    		: 1;
			uint32_t TIM4EN		        : 1;
			uint32_t TIM5EN			    : 1;
			uint32_t TIM6EN			    : 1;
			uint32_t TIM7EN			    : 1;
			uint32_t _reserved_1		: 5;
			uint32_t WWDGEN  	    	: 1;
			uint32_t _reserved_2		: 2;
			uint32_t SPI2EN			    : 1;
			uint32_t SPI3EN			    : 1;
			uint32_t _reserved_3   		: 1;
			uint32_t USART2EN			: 1;
			uint32_t USART3EN			: 1;
			uint32_t USART4EN			: 1;
			uint32_t USART5EN			: 1;
			uint32_t I2C1EN		    	: 1;
			uint32_t I2C2EN			    : 1;
			uint32_t _reserved_4   		: 2;
			uint32_t CAN1EN			    : 1;
			uint32_t CAN2EN			    : 1;
			uint32_t BKPEN				: 1;
			uint32_t PWREN				: 1;
			uint32_t DACEN				: 1;
			uint32_t _reserved_5   		: 2;
		} BITS;
	} RCC_APB1ENR;

	union 
    {
		uint32_t REG;
		struct 
        {
			uint32_t LSEON 	 		    : 1;
			const uint32_t LSERDY 	 	: 1;
			uint32_t LSEBYP 	 		: 1;
			uint32_t _reserved_1		: 5;
			uint32_t RTCSEL 	 		: 2;
			uint32_t _reserved_2		: 5;
			uint32_t RTCEN  	 		: 1;
			uint32_t BDRST  	 		: 1;
			uint32_t _reserved_3		: 15;
		} BITS;
	} RCC_BDCR;

	union 
    {
		uint32_t REG;
		struct 
        {
			uint32_t LSION 	     		: 1;
			const uint32_t LSIRDY 	 	: 1;
			uint32_t _reserved_1		: 22;
			uint32_t RMVF 	 			: 1;
			uint32_t _reserved_2		: 1;
			uint32_t PINRSTF  	 		: 1;
			uint32_t PORRSTF  	 		: 1;
			uint32_t SFTRSTF			: 1;
			uint32_t IWDGRSTF			: 1;
			uint32_t WWDGRSTF			: 1;
			uint32_t LPWRRSTF			: 1;
		} BITS; 
	} RCC_CSR;

	union 
    {
		uint32_t REG;
		struct 
        {
			uint32_t _reserved_1		: 12;
			uint32_t OTGFSRst 	 		: 1;
			uint32_t _reserved_2		: 1;
			uint32_t ETHMACRST  	 	: 1;
			uint32_t _reserved_3  	 	: 17;
		} BITS;
	} RCC_AHBRSTR;

	union 
    {
		uint32_t REG;
		struct 
        {
			uint32_t PREDIV1			: 4;
			uint32_t PREDIV2 	 		: 4;
			uint32_t PLL2MUL			: 4;
			uint32_t PLL3MUL   	 	    : 4;
			uint32_t PREDIV1SRC  	 	: 1;
			uint32_t I2S2SRC   	 	    : 1;
			uint32_t I2S3SRC   	 	    : 1;
			uint32_t _reserved_1		: 13;
		} BITS;
	} RCC_CFGR2;
} RCC_TypeDef;

typedef enum 
{
	APB1_SPI2    = 14,
	APB1_USART2  = 17,
	APB1_I2C1    = 21,
	APB1_I2C2    = 22
} APB1EN_REG_TypeDef;

typedef enum 
{
	APB2_AFIO   = 0,
	APB2_PORT_A = 2,
	APB2_PORT_B = 3,
	APB2_PORT_C = 4,
	APB2_PORT_D = 5,
	APB2_PORT_E = 6,
	APB2_ADC1   = 9,
	APB2_ADC2   = 10,
	APB2_TIM1   = 11,
	APB2_SPI1   = 12,
	APB2_USART1 = 14
} APB2EN_REG_TypeDef;


#define RCC ((RCC_TypeDef *)0x40021000)


void Config_Clock_Tree(void);

void Enable_RCC_APB1ENR(APB1EN_REG_TypeDef REG);
void Enable_RCC_APB2ENR(APB2EN_REG_TypeDef REG);


#endif /* _RCC_H_ */
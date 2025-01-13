/*
 * 	UART.h
 *
 *  Created on: Jan 9, 2025
 *      Author: haidoan2098
 */

#ifndef _UART_H_
#define _UART_H_

#include <stdint.h>

typedef struct
{
    union
    {
        uint32_t REG;
        struct
        {
            const uint32_t PE      : 1;
            const uint32_t FE      : 1;
            const uint32_t NE      : 1;
            const uint32_t ORE     : 1;
            const uint32_t IDLE    : 1;
            uint32_t RXNE          : 1;
            uint32_t TC            : 1;
            const uint32_t TXE     : 1;
            uint32_t LBD           : 1;
            uint32_t CTS           : 1;
            uint32_t _reserved     : 22;
        } BITS;
    } USART_SR;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t DR            : 9;
            uint32_t _reserved     : 23;
        } BITS;
    } USART_DR;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t DIV_Fraction  : 4;
            uint32_t DIV_Mantissa  : 12;
            uint32_t _reserved     : 16;
        } BITS;
    } USART_BRR;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t SBK           : 1;
            uint32_t RWU           : 1;
            uint32_t RE            : 1;
            uint32_t TE            : 1;
            uint32_t IDLEIE        : 1;
            uint32_t RXNEIE        : 1;
            uint32_t TCIE          : 1;
            uint32_t TXEIE         : 1;
            uint32_t PEIE          : 1;
            uint32_t PS            : 1;
            uint32_t PCE           : 1;
            uint32_t WAKE          : 1;
            uint32_t M             : 1;
            uint32_t UE            : 1;
            uint32_t _reserved     : 18;
        } BITS;
    } USART_CR1;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t ADD           : 4;
            uint32_t _reserved1    : 1;
            uint32_t LBDL          : 1;
            uint32_t LBDIE         : 1;
            uint32_t _reserved2    : 1;
            uint32_t LBCL          : 1;
            uint32_t CPHA          : 1;
            uint32_t CPOL          : 1;
            uint32_t CLKEN         : 1;
            uint32_t STOP          : 2;
            uint32_t LINEN         : 1;
            uint32_t _reserved3    : 17;
        } BITS;
    } USART_CR2;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t EIE           : 1;
            uint32_t IREN          : 1;
            uint32_t IRLP          : 1;
            uint32_t HDSEL         : 1;
            uint32_t NACK          : 1;
            uint32_t SCEN          : 1;
            uint32_t DMAR          : 1;
            uint32_t DMAT          : 1;
            uint32_t RTSE          : 1;
            uint32_t CTSE          : 1;
            uint32_t CTSIE         : 1;
            uint32_t _reserved     : 21;
        } BITS;
    } USART_CR3;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t PSC           : 8;
            uint32_t GT            : 8;
            uint32_t _reserved     : 16;
        } BITS;
    } USART_GTPR;
} USART_TypeDef;


#define USART1 ((USART_TypeDef *)0x40013800)


#endif /* _UART_H_ */
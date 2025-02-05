/*
 * 	I2C.h
 *
 *  Created on: Jan 18, 2025
 *      Author: haidoan2098
 */

#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>

typedef struct
{
    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CPHA               : 1;
            uint32_t CPOL               : 1;
            uint32_t MSTR               : 1;
            uint32_t BR                 : 3;
            uint32_t SPE                : 1;
            uint32_t LSBFIRST           : 1;
            uint32_t SSI                : 1;
            uint32_t SSM                : 1;
            uint32_t RXONLY             : 1;
            uint32_t DFF                : 1;
            uint32_t CRCNEXT            : 1;
            uint32_t CRCEN              : 1;
            uint32_t BIDIOE             : 1;
            uint32_t BIDIMODE           : 1;
            uint32_t _reserved          : 16;
        } BITS;
    } SPI_CR1;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t RXDMAEN            : 1;
            uint32_t TXDMAEN            : 1;
            uint32_t SSOE               : 1;
            uint32_t _reserved1         : 2;
            uint32_t ERRIE              : 1;
            uint32_t RXNEIE             : 1;
            uint32_t TXEIE              : 1;
            uint32_t _reserved2         : 24;
        } BITS;
    } SPI_CR2;

    union
    {
        uint32_t REG;
        struct
        {
            const uint32_t RXNE         : 1;
            const uint32_t TXE          : 1;
            const uint32_t CHSIDE       : 1;
            const uint32_t UDR          : 1;
            uint32_t CRCERR             : 1;
            const uint32_t MODF         : 1;
            const uint32_t OVR          : 1;
            const uint32_t BSY          : 1;
            const uint32_t _reserved    : 24;
        } BITS;
    } SPI_SR;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t DR                 : 16;
            uint32_t _reserved          : 16;
        } BITS; 
    } SPI_DR;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CRCPOLY            : 16;
            uint32_t _reserved          : 16;
        } BITS;
    } SPI_CRCPR;

    union
    {
        uint32_t REG;
        struct
        {
            const uint32_t RxCRC        : 16;
            const uint32_t _reserved    : 16;
        } BITS;
    } SPI_RXCRCR;

    union
    {
        uint32_t REG;
        struct
        {
            const uint32_t TxCRC        : 16;
            const uint32_t _reserved    : 16;
        } BITS;
    } SPI_TXCRCR;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CHLEN              : 1;
            uint32_t DATLEN             : 2;
            uint32_t CKPOL              : 1;
            uint32_t I2SSTD             : 2;

            uint32_t _reserved1         : 1;
            uint32_t PCMSYNC            : 1;
            uint32_t I2SCFG             : 2;
            uint32_t I2SE               : 1;
            uint32_t I2SMOD             : 1;
            uint32_t _reserved2         : 20;
        } BITS;
    } SPI_I2SCFGR;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t I2SDIV             : 8;
            uint32_t ODD                : 1;
            uint32_t MCKOE              : 1;
            uint32_t _reserved          : 22;
        } BITS;
    } SPI_I2SPR;
} SPI_TypeDef;


#define SPI1 ((SPI_TypeDef *)0x40013000)


#endif /* I2C_H_ */
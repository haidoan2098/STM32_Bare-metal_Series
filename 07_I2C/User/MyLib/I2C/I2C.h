/*
 * 	I2C.h
 *
 *  Created on: Jan 15, 2025
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
            uint32_t PE                 : 1;
            uint32_t SMBUS              : 1;
            const uint32_t _reserved1   : 1;
            uint32_t SMBTYPE            : 1;
            uint32_t ENARP              : 1;
            uint32_t ENPEC              : 1;
            uint32_t ENGC               : 1;
            uint32_t NOSTRETCH          : 1;
            uint32_t START              : 1;
            uint32_t STOP               : 1;
            uint32_t ACK                : 1;
            uint32_t POS                : 1;
            uint32_t PEC                : 1;
            uint32_t ALERT              : 1;
            uint32_t _reserved2         : 1;
            uint32_t SWRST              : 1;
            const uint32_t _reserved3   : 16;
        } BITS;
    } I2C_CR1;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t FREQ               : 6;
            uint32_t _reserved1         : 2;
            uint32_t ITERREN            : 1;
            uint32_t ITEVTEN            : 1;
            uint32_t ITBUFEN            : 1;
            uint32_t DMAEN              : 1;
            uint32_t LAST               : 1;
            uint32_t _reserved2         : 19;
        } BITS;
    } I2C_CR2;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t ADD0               : 1;
            uint32_t ADD71              : 7;
            uint32_t ADD98              : 2;
            uint32_t _reserved1         : 5;
            uint32_t ADDMODE            : 1;
            uint32_t _reserved2         : 16;
        } BITS;
    } I2C_OAR1;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t ENDUAL             : 1;
            uint32_t ADD2               : 7;
            uint32_t _reserved          : 24;
        } BITS;
    } I2C_OAR2;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t DR                 : 8;
            uint32_t _reserved          : 24;
        } BITS;
    } I2C_DR;

    union
    {
        uint32_t REG;
        struct
        {
            const uint32_t SB           : 1;
            const uint32_t ADDR         : 1;
            const uint32_t BTF          : 1;
            const uint32_t ADD10        : 1;
            const uint32_t STOPF        : 1;
            const uint32_t _reserved1   : 1;
            const uint32_t RxNE         : 1;
            const uint32_t TxE          : 1;
            uint32_t BERR               : 1;
            uint32_t ARLO               : 1;
            uint32_t AF                 : 1;
            uint32_t OVR                : 1;
            uint32_t PECERR             : 1;
            uint32_t _reserved2         : 1;
            uint32_t TIMEOUT            : 1;
            uint32_t SMBALERT           : 1;
            const uint32_t _reserved3   : 16;
        } BITS;
    } I2C_SR1;

    union
    {
        uint32_t REG;
        struct
        {
            const uint32_t MSL          : 1;
            const uint32_t BUSY         : 1;
            const uint32_t TRA          : 1;
            const uint32_t _reserved1   : 1;
            const uint32_t GENCALL      : 1;
            const uint32_t SMBDEFAUL    : 1;
            const uint32_t SMBHOST      : 1;
            const uint32_t DUALF        : 1;
            const uint32_t PEC          : 8;
            const uint32_t _reserved2   : 16;
        } BITS;
    } I2C_SR2;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CCR                : 12;
            uint32_t _reserved1         : 2;
            uint32_t DUTY               : 1;
            uint32_t FS                 : 1;
            uint32_t _reserved2         : 16;
        } BITS;
    } I2C_CCR;
    union
    {
        uint32_t REG;
        struct
        {
            uint32_t TRISE              : 6;
            uint32_t _reserved          : 26;
        } BITS;
    } I2C_TRISE;
} I2C_TypeDef;


#define I2C1 ((I2C_TypeDef *)0x40005400)


#endif /* I2C_H_ */
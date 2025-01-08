/*
 *  AdvancedTimer.h
 *
 *  Created on: Jan 7, 2025
 *      Author: haidoan2098
 */

#ifndef _ADVANCED_TIMER_H_
#define _ADVANCED_TIMER_H_

#include <stdint.h>

typedef struct
{
    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CEN           : 1;
            uint32_t UDIS          : 1;
            uint32_t URS           : 1;
            uint32_t OPM           : 1;
            uint32_t DIR           : 1;
            uint32_t CMS           : 2;
            uint32_t ARPE          : 1;
            uint32_t CKD           : 2;
            uint32_t _reserved     : 22;
        } BITS;
    } TIMx_CR1;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CCPC          : 1;
            uint32_t _reserved1    : 1;
            uint32_t CCUS          : 1;
            uint32_t CCDS          : 3;
            uint32_t TI1S          : 1;
            uint32_t OIS1          : 1;
            uint32_t OIS1N         : 1;
            uint32_t OIS2          : 1;
            uint32_t OIS2N         : 1;
            uint32_t OIS3          : 1;
            uint32_t OIS3N         : 1;
            uint32_t OIS4          : 1;
            uint32_t _reserved2    : 17;
        } BITS;
    } TIMx_CR2;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t SMS           : 3;
            uint32_t _reserved1    : 1;
            uint32_t TS            : 3;
            uint32_t MSM           : 1;
            uint32_t ETF           : 4;
            uint32_t ETPS          : 2;
            uint32_t ECE           : 1;
            uint32_t ETP           : 1;
            uint32_t _reserved2    : 16;
        } BITS;
    } TIMx_SMCR;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t UIE           : 1;
            uint32_t CC1IE         : 1;
            uint32_t CC2IE         : 1;
            uint32_t CC3IE         : 1;
            uint32_t CC4IE         : 1;
            uint32_t COMIE         : 1;
            uint32_t TIE           : 1;
            uint32_t BIE           : 1;
            uint32_t UDE           : 1;
            uint32_t CC1DE         : 1;
            uint32_t CC2DE         : 1;
            uint32_t CC3DE         : 1;
            uint32_t CC4DE         : 1;
            uint32_t COMDE         : 1;
            uint32_t TDE           : 1;
            uint32_t _reserved1    : 17;
        } BITS;
    } TIMx_DIER;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t UIF           : 1;
            uint32_t CC1IF         : 1;
            uint32_t CC2IF         : 1;
            uint32_t CC3IF         : 1;
            uint32_t CC4IF         : 1;
            uint32_t COMIF         : 1;
            uint32_t TIF           : 1;
            uint32_t BIF           : 1;
            uint32_t _reserved1    : 1;
            uint32_t CC1DF         : 1;
            uint32_t CC2DF         : 1;
            uint32_t CC3DF         : 1;
            uint32_t CC4DF         : 1;
            uint32_t _reserved2    : 19;
        } BITS;
    } TIMx_SR;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t UG            : 1;
            uint32_t CC1G          : 1;
            uint32_t CC2G          : 1;
            uint32_t CC3G          : 1;
            uint32_t CC4G          : 1;
            uint32_t COMG          : 1;
            uint32_t TG            : 1;
            uint32_t BG            : 1;
            uint32_t _reserved1    : 24;
        } BITS;
    } TIMx_EGR;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CC1S          : 2; 
            uint32_t OC1FE         : 1; 
            uint32_t OC1PE         : 1; 
            uint32_t OC1M          : 3;  
            uint32_t OC1CE         : 1; 
            uint32_t CC2S          : 2;  
            uint32_t OC2FE         : 1; 
            uint32_t OC2PE         : 1; 
            uint32_t OC2M          : 3;  
            uint32_t OC2CE         : 1; 
            uint32_t _reserved1    : 16;
        } BITS_OUTPUT;

        struct
        {
            uint32_t CC1S          : 2;
            uint32_t IC1PSC        : 2;
            uint32_t IC1F          : 4;
            uint32_t CC2S          : 2;
            uint32_t IC2PSC        : 2;
            uint32_t IC2F          : 4;
            uint32_t _reserved     : 16;
        } BITS_INPUT;
    } TIMx_CCMR1;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CC3S          : 2;
            uint32_t OC3FE         : 1;
            uint32_t OC3PE         : 1;
            uint32_t OC3M          : 3;
            uint32_t OC3CE         : 1;
            uint32_t CC4S          : 2;
            uint32_t OC4FE         : 1;
            uint32_t OC4PE         : 1;
            uint32_t OC4M          : 3;
            uint32_t OC4CE         : 1;
            uint32_t _reserved1    : 16;
        } BITS_OUTPUT;

        struct
        {
            uint32_t CC3S          : 2;
            uint32_t IC3PSC        : 2;
            uint32_t IC3F          : 4;
            uint32_t CC4S          : 2;
            uint32_t IC4PSC        : 2;
            uint32_t IC4F          : 4;
            uint32_t _reserved     : 16;
        } BITS_INPUT;
    } TIMx_CCMR2;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CC1E          : 1;
            uint32_t CC1P          : 1;
            uint32_t CC1NE         : 1;
            uint32_t CC1NP         : 1;
            uint32_t CC2E          : 1;
            uint32_t CC2P          : 1;
            uint32_t CC2NE         : 1;
            uint32_t CC3E          : 1;
            uint32_t CC3P          : 1;
            uint32_t CC3NE         : 1;
            uint32_t CC3NP         : 1;
            uint32_t CC4E          : 1;
            uint32_t CC4P          : 1;
            uint32_t _reserved1    : 1;
            uint32_t CC4NP         : 1;
            uint32_t _reserved2    : 16;
        } BITS;
    } TIMx_CCER;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CNT           : 16;
            uint32_t _reserved     : 16;
        } BITS;
    } TIMx_CNT;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t PSC           : 16;
            uint32_t _reserved     : 16;
        } BITS;
    } TIMx_PSC;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t ARR           : 16;
            uint32_t _reserved     : 16;
        } BITS;
    } TIMx_ARR;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t REP           : 8;
            uint32_t _reserved     : 24;
        } BITS;
    } TIMx_RCR;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CCR1          : 16;
            uint32_t _reserved     : 16;
        } BITS;
    } TIMx_CCR1;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CCR2          : 16;
            uint32_t _reserved     : 16;
        } BITS;
    } TIMx_CCR2;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CCR3          : 16;
            uint32_t _reserved     : 16;
        } BITS;
    } TIMx_CCR3;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t CCR4          : 16;
            uint32_t _reserved     : 16;
        } BITS;
    } TIMx_CCR4;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t DBA           : 5;
            uint32_t _reserved1    : 3;
            uint32_t DBL           : 5;
            uint32_t _reserved2    : 19;
        } BITS;
    } TIMx_BDTR;

    union
    {
        uint32_t REG;
        struct
        {
            uint32_t DT            : 8;
            uint32_t LOCK          : 2;
            uint32_t OSSI          : 1;
            uint32_t OSSR          : 1;
            uint32_t BKE           : 1;
            uint32_t BKP           : 1;
            uint32_t AOE           : 1;
            uint32_t MOE           : 1;
            uint32_t _reserved     : 16;
        } BITS;
    } TIMx_DCR;

    union
    {
        uint32_t DMAB;
    } TIMx_DMAR;
} Advanced_Timer_TypeDef;

#define TIM1 ((Advanced_Timer_TypeDef *)0x40012C00)

#endif /* _ADVANCED_TIMER_H_ */
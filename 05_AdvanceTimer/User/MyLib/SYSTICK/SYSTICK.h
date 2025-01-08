/*
 *  SYSTICK.h
 *
 *  Created on: Jan 2, 2025
 *      Author: haidoan2098
 */

#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include <stdint.h>


typedef struct
{
  union
  {
    uint32_t REG;
    struct
    {
      uint32_t ENABLE               : 1;
      uint32_t TICK_INT             : 1;
      uint32_t CLK_SOURCE           : 1;
      uint32_t _reserved_1          : 13;
      uint32_t COUNT_FLAG           : 1;
      uint32_t _reserved_2          : 15;
    } BITS;
  } STK_CTRL;

  uint32_t STK_LOAD ;

  uint32_t STK_VAL  ;

  const union
  {
    uint32_t REG;
    struct
    {
      uint32_t TENMS                : 24;
      uint32_t _reserved4           : 6;
      uint32_t SKEW                 : 1;
      uint32_t NOREF                : 1;
    } BITS;
  } STK_CALIB;
} STK_TypeDef;


#define STK ((STK_TypeDef *)0xE000E010)


#endif /* _SYSTICK_H_ */
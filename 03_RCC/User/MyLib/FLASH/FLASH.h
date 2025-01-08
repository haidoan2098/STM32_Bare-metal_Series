/*
 *  FLASH.h
 *
 *  Created on: Jan 1, 2025
 *      Author: haidoan2098
 */

#ifndef _FLASH_H_
#define _FLASH_H_

#include <stdint.h>

typedef struct {
	union {
		unsigned long REG;
		struct {
			unsigned long LATENCY 		 : 3;
			unsigned long HLFCYA 		 : 1;
			unsigned long PRFTBE   		 : 1;
			const unsigned long PRFTBS	 : 1;
			unsigned long _reserved   	 : 26;
		} BITS;
	} FLASH_ACR;
} FLASH_TypeDef;

#define FLASH ((FLASH_TypeDef *)0x40022000)


#endif /* _FLASH_H_ */
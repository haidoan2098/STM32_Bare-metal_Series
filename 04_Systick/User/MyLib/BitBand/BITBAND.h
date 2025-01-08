/*
 *  BITBAND.c
 *
 *  Created on: Dec 29, 2024
 *      Author: haidoan2098
 */

#ifndef _BITBAND_H_
#define _BITBAND_H_

#include <stdint.h>


#define SRAM_BASE_ADDRESS               0x22000000
#define PERIPHERAL_BASE_ADDRESS         0x42000000


/*
 * @brief: Calculates the bit-band alias address for a given memory location and bit
 */
#define BITBAND_ADDRESS(base_address, address, bit)    ((base_address) + ((((uint32_t)(address)) & 0xFFFFF) * 32) + ((bit) * 4))

/*
 * @brief: Calculates the alias address for a bit in the SRAM region.
 */
#define BITBAND_SRAM_ADDRESS(address, bit)             BITBAND_ADDRESS(SRAM_BASE_ADDRESS, (uint32_t)(address), (bit))

/*
 * @brief: Calculates the alias address for a bit in the Peripheral region.
 */
#define BITBAND_PERIPHERAL_ADDRESS(address, bit)       BITBAND_ADDRESS(PERIPHERAL_BASE_ADDRESS, (uint32_t)(address), (bit))


/*
 * @brief: Convert address to pointer
 */
#define BITBAND_POINTER(base_address, address, bit)    (uint32_t *)((base_address) + ((((uint32_t)(address)) & 0xFFFFF) * 32) + ((bit) * 4))
#define BITBAND_SRAM_POINTER(address, bit)             (uint32_t *)BITBAND_ADDRESS(SRAM_BASE_ADDRESS, (uint32_t)(address), (bit))
#define BITBAND_PERIPHERAL_POINTER(address, bit)       (uint32_t *)BITBAND_ADDRESS(PERIPHERAL_BASE_ADDRESS, (uint32_t)(address), (bit))


#endif /* _BITBAND_H_ */
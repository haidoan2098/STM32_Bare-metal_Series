# 02 Bit-Band        

## Introduction     
Bit-Band is a special feature in ARM Cortex-M microcontrollers. It allows access and manipulation of each bit of a memory area without the need for complex operations.

### Terminology
#### 1. Bit-band Region: It is a special memory area mapped to support direct manipulation of each bit.
*  There are 2 types: SRAM Bit-band Region and Peripheral Bit-band Region (Addresses of peripherals and SRAM in memory).
#### 2. Alias Region: It is a mapped memory area, where each bit in the bit-band area is mapped to a word (32-bit) in the alias memory area.

![](https://github.com/s2nmt/STM32_Bare-metal_Tool_Series/raw/main/02_Bitband/image.png)

### Characteristics
#### 1. Normal bit operation (Read-Modify-Write).

```c
// Bước 1: Đọc giá trị hiện tại
uint32_t temp = GPIOC->ODR;
// Bước 2: Thay đổi bit cần thiết
temp |= (1 << 13);  // Thay đổi bit 3 thành bit 13
// Bước 3: Ghi lại giá trị
GPIOC->ODR = temp;
```

#### 2. Use bit-band.
Write directly to bit without going through 3 steps.

```c
uint32_t *alias_address_GPIOC_ODR_13 = (uint32_t *)BITBAND_PERIPHERAL_ADDRESS(&GPIOC->ODR, 13);
*alias_address_GPIOC_ODR_13 = 1;
```





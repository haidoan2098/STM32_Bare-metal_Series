/*
 *  RCC.c
 *
 *  Created on: Jan 6, 2025
 *      Author: haidoan2098
 */

#include "RCC.h"

void Config_Clock_Tree(void)
{
    // Bật HSI và chờ HSI sẵn sàng
    RCC->RCC_CR.BITS.HSION = 1;  // Bật HSI
    while (!RCC->RCC_CR.BITS.HSIRDY);  // Chờ HSI sẵn sàng

    // Cấu hình AHB prescaler để chia tần số xuống 8MHz (chia 2)
    RCC->RCC_CFGR.BITS.HPRE = 0;  // Chia tần số cho 2 (16MHz/2 = 8MHz)

    // Chọn HSI làm nguồn xung nhịp hệ thống
    RCC->RCC_CFGR.BITS.SW = 0;  // 0 là giá trị để chọn HSI
    while (RCC->RCC_CFGR.BITS.SWS != 0);  // Đợi cho đến khi HSI được chọn thành công
}


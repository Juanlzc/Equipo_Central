//#define delay_ms(uint32_t time_ms) delay_us(uint32_t time_us*1000)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define us_to_counts(x) (x)*CONFIG_ESP32_DEFAULT_CPU_FREQ_MHZ
void delay_us(uint32_t  time_us);

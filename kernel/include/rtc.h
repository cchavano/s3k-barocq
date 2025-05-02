#pragma once

#include <stdint.h>

extern volatile uint64_t __mtime[];
extern volatile uint64_t __mtimecmp[];

uint64_t rtc_time_get(void);
void rtc_time_set(uint64_t time);
uint64_t rtc_timeout_get(uint64_t hart);
void rtc_timeout_set(uint64_t hart, uint64_t time);

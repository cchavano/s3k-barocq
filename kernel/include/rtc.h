#pragma once

#include "libkernel.h"

u64 rtc_time_get(void);
void rtc_time_set(u64 time);
u64 rtc_timeout_get(u64 hart);
void rtc_timeout_set(u64 hart, u64 time);
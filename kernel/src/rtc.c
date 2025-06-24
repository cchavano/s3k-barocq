#include "rtc.h"

extern volatile u64 __mtime[];
extern volatile u64 __mtimecmp[];

u64 rtc_time_get(void)
{
	return __mtime[0];
}

void rtc_time_set(u64 time)
{
	__mtime[0] = time;
}

u64 rtc_timeout_get(u64 hart)
{
	return __mtimecmp[hart];
}

void rtc_timeout_set(u64 hart, u64 time)
{
	__mtimecmp[hart] = time;
}

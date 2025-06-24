#include "machine.h"

#include "csr.h"
#include "libkernel.h"
#include "rtc.h"

u64 Machine_time_read(mstate_t *mc)
{
	return rtc_time_get();
}

u64 Machine_timeout_read(mstate_t *mc, u64 hart)
{
	return rtc_timeout_get(hart);
}

u64 Machine_csrr_mhartid(mstate_t *mc)
{
	return csrr_mhartid();
}
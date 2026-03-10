#include "machine.h"

#include "csr.h"
#include "libkernel.h"
#include "rtc.h"

machine_t *Machine_rtc_time_get(machine_t *mc)
{
	return mc;
}

u64 Machine_time_read(machine_t *mc)
{
	return rtc_time_get();
}

u64 Machine_timeout_read(machine_t *mc, u64 hart)
{
	return rtc_timeout_get(hart);
}

u64 Machine_csrr_mhartid(machine_t *mc)
{
	return csrr_mhartid();
}
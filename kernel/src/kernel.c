#include "kernel.h"

#include "cap/table.h"
#include "csr.h"
#include "kassert.h"
#include "proc.h"
#include "sched.h"

bool kernel_preempt(void)
{
	return csrr_mip() & 0x80;
}

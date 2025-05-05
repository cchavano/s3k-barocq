#pragma once

#include "types.h"
#include "csr.h"

static inline bool preempt(void)
{
	return csrr_mip() & 0x80;
}

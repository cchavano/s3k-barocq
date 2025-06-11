#pragma once

#include "csr.h"
#include "types.h"

static inline bool preempt(void)
{
	return (csrr_mip() & csrr_mie()) != 0;
}

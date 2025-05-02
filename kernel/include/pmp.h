#pragma once

#include "types.h"

static inline word_t pmp_napot_decode_base(word_t addr)
{
	return ((addr + 1) & addr) << 2;
}

static inline word_t pmp_napot_decode_size(uint64_t addr)
{
	return (((addr + 1) ^ addr) + 1) << 2;
}

static inline uint64_t pmp_napot_encode(uint64_t base, uint64_t size)
{
	return (base | (size / 2 - 1)) >> 2;
}

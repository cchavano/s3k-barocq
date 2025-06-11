#pragma once

#include "types.h"

unsigned long long convert_cap(cap_t cap);
void kstate_init(const cap_t init_caps[], size_t size);

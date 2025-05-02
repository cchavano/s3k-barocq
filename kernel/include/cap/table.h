#pragma once

#include "kassert.h"
#include "types.h"

typedef struct cte *cte_t;

void ctable_init(const cap_t init_caps[], size_t size);
cte_t ctable_get(word_t pid, word_t index);
bool cte_is_empty(cte_t c);
void cte_set_next(cte_t c, cte_t next);
void cte_set_prev(cte_t c, cte_t prev);
void cte_set_cap(cte_t c, const cap_t *cap);
cte_t cte_next(cte_t c);
cte_t cte_prev(cte_t c);
void cte_cap(cte_t c, cap_t *cap);
word_t cte_pid(cte_t c);
void cte_move(cte_t src, cte_t dst);
void cte_delete(cte_t c);
void cte_insert(cte_t c, const cap_t *cap, cte_t prev);

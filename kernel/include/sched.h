#pragma once
/**
 * @file sched.h
 * @brief Scheduler.
 * @copyright MIT License
 * @author Henrik Karlsson (henrik10@kth.se)
 * @bug QEMU mret does not work properly if all pmp registers are 0, so we have
 * a temporary fix in sched_next.
 */

#include "proc.h"
#include "types.h"

#include <stddef.h>

// Let pid run on hartid, begin-end.
kstate_t *Sched_update(kstate_t *ks, u64 pid, u64 end, u64 from, u64 to);

// Delete scheduling at hartid, begin-end.
kstate_t *Sched_delete(kstate_t *ks, u64 from, u64 to);

/**
 * @brief Find the next process to schedule.
 *
 * This function finds the next process to schedule based on the current
 * state of the system.
 */
proc_t *sched(void);

kstate_t *Sched_sched(kstate_t *ks);

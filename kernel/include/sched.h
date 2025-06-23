#pragma once
/**
 * @file sched.h
 * @brief Scheduler.
 * @copyright MIT License
 * @author Henrik Karlsson (henrik10@kth.se)
 * @bug QEMU mret does not work properly if all pmp registers are 0, so we have
 * a temporary fix in sched_next.
 */

#include "libkernel.h"
#include "macro.h"
#include "proc.h"

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Find the next process to schedule.
 *
 * This function finds the next process to schedule based on the current
 * state of the system.
 */
proc_t *sched(void);

// Let pid run on hartid, begin-end.
struct Types_kstate *Sched_update(struct Types_kstate *ks, u64 pid, u64 end,
				  u64 from, u64 to);

// Delete scheduling at hartid, begin-end.
struct Types_kstate *Sched_delete(struct Types_kstate *ks, u64 from, u64 to);

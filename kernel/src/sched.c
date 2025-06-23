/* See LICENSE file for copyright and license details. */

#include "sched.h"

#include "csr.h"
#include "libkernel.h"
#include "proc.h"
#include "rtc.h"
#include "trap.h"
#include "wfi.h"

extern struct Types_kstate ks;

struct Types_kstate *Sched_update(struct Types_kstate *ks, u64 pid, u64 end,
				  u64 from, u64 to)
{
	for (u64 i = from; i < to; i++) {
		ks->tslots[i] = ((pid << 8) | (end - i));
	}
	return ks;
}

struct Types_kstate *Sched_delete(struct Types_kstate *ks, u64 from, u64 to)
{
	u64 mask = 0xFFFFull;
	for (u64 i = from; i < to; ++i)
		ks->tslots[i] &= ~mask;
	return ks;
}

proc_t *sched(void)
{
	// Hart ID
	u64 hart = csrr_mhartid();
	// Time slot
	u64 slot;
	// Process to schedule
	proc_t *proc;
	rtc_timeout_set(hart, (u64)-1);

	do {
		slot = rtc_time_get() / S3K_SLOT_LEN;

		// Try schedule process
		Sched_fetch(&ks, slot);
		proc = proc_get_opt(Vreg_read(&ks, Vreg_V0));
	} while (!proc);
	rtc_timeout_set(hart, proc->timeout);
	return proc;
}

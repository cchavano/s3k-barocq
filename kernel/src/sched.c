/* See LICENSE file for copyright and license details. */

#include "sched.h"

#include "csr.h"
#include "libkernel.h"
#include "rtc.h"

extern kstate_t ks;

kstate_t *Sched_update(kstate_t *ks, u64 pid, u64 end, u64 from, u64 to)
{
	for (u64 i = from; i < to; i++) {
		ks->tslots[i] = ((pid << 8) | (end - i));
	}
	return ks;
}

kstate_t *Sched_delete(kstate_t *ks, u64 from, u64 to)
{
	u64 mask = 0xFFFFull;
	for (u64 i = from; i < to; ++i)
		ks->tslots[i] &= ~mask;
	return ks;
}

kstate_t *Sched_sched(kstate_t *ks)
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
		Sched_fetch(ks, slot);
		proc = proc_get_opt(Vreg_read(ks, Vreg_V0));
	} while (!proc);
	rtc_timeout_set(hart, proc->timeout);
	return Vreg_write(ks, Vreg_V0, proc->pid);
}

proc_t *sched(void)
{
	Sched_sched(&ks);
	return proc_get(Vreg_read(&ks, Vreg_V0));
}

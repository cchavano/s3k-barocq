#include <libkernel.h>
#include <sched.h>
#include <trap.h>

extern kstate_t ks;

proc_t *trap_handler(proc_t *proc, u64 mcause, u64 mtval)
{
	if (mcause == 8) {
		Syscall_handler(&ks, proc->pid);
		proc_t *next = proc_get_opt(Vreg_read(&ks, Vreg_V0));
		if (next == proc)
			trap_return(proc);
		Ptable_release(&ks, proc->pid);
		if (next)
			return next;
		return sched();
	} else if ((i64)mcause < 0) {
		Interrupt_handler(&ks, proc->pid);
		return proc_get(Vreg_read(&ks, Vreg_V0));
	} else {
		Exception_handler(&ks, proc->pid, mcause, mtval);
		trap_return(proc_get(Vreg_read(&ks, Vreg_V0)));
	}
}

#include "cap/table.h"
#include "cap/util.h"
#include "proc.h"
#include "sched.h"
#include "types.h"

void kernel_init(void)
{
	cap_t init_caps[1];

	cap_mk_pmp(&init_caps[0], 0x20005fff, MEM_RWX);
	ctable_init(init_caps, ARRAY_SIZE(init_caps));
	sched_init();
	proc_init();
}

void kputc(char c)
{
}

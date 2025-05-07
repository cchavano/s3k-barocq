#include "proc.h"
#include "pmp.h"
#include "kprint.h"
#include "ks_init.h"
#include "kernel_core.h"

struct Kernel_state ks;

// Capabilities
static unsigned long long _cnext[S3K_PROC_CNT * S3K_CAP_CNT];
static unsigned long long _cprev[S3K_PROC_CNT * S3K_CAP_CNT];
static unsigned long long _ctable[S3K_PROC_CNT * S3K_CAP_CNT];

// Virtual registers
static unsigned long long _vregs[8];

static unsigned long long _convert_cap(cap_t cap)
{
	switch(cap.type) {
	case CAPTY_MEMORY:
		return Cap_mk_memory(cap.mem.rwx, cap.mem.lck, cap.mem.tag, cap.mem.bgn, cap.mem.mrk, cap.mem.end);
	case CAPTY_PMP:
		return Cap_mk_pmp(cap.pmp.rwx, cap.pmp.used, cap.pmp.slot, cap.pmp.addr);
	default:
		return Cap_mk_none();
	}
}

void ks_ctable_init(const cap_t init_caps[], size_t size)
{
	ks.cnext = _cnext;
	ks.cprev = _cprev;
	ks.ctable = _ctable;
	for (unsigned int i = 0; i < size; i++) {
		if (init_caps[i].type == CAPTY_NONE)
			continue;
		Ctable_insert(&ks, i, _convert_cap(init_caps[i]), 0);
		kprintf("# init_caps_br[%d]: %C\n", i, &init_caps[i]);
	}
}

void ks_vregs_init(void)
{
	ks.vregs = _vregs;
}
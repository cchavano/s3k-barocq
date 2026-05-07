#include "cap_ops.h"

#include "libkernel.h"
#include "preempt.h"

typedef void (*revoke_handler)(u64);

static const revoke_handler revoke_handlers[CAPTY_COUNT] = {
    NULL,
    CapOps_revoke_time,
    CapOps_revoke_memory,
    CapOps_revoke_pmp,
    CapOps_revoke_monitor,
    CapOps_revoke_channel,
    CapOps_revoke_socket,
};

void CapOps_revoke(u64 parent)
{
	u64 pcap = Kernel_ks->ctable[parent].cap;
	u64 type = Cap_get_type(pcap);
	if (type == Cap_Capty_none) {
		Kernel_ks->errcode = Error_Empty;
		return;
	}
	do {
		revoke_handlers[type](parent);
	} while (Kernel_ks->errcode == Error_Continue && !preempt());

	if (Kernel_ks->errcode == Error_Continue) {
		Kernel_ks->errcode = Error_Preempted;
	}
	return;
}
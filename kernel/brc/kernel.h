struct kernel_state {
	unsigned int *cnext;
	unsigned int *cprev;
	unsigned long long *ctable;
	unsigned long long *vregs;
	int errcode;
};

unsigned long long vreg_read(struct kernel_state *, unsigned int)
    __attribute__((alias("u_vreg_read")));

struct kernel_state *vreg_write(struct kernel_state *, unsigned int,
				unsigned long long)
    __attribute__((alias("u_vreg_write")));

unsigned long long cap_get_type(unsigned long long)
    __attribute__((alias("u_cap_get_type")));

unsigned long long cap_mk_none(void) __attribute__((alias("u_cap_mk_none")));

unsigned long long cap_mk_time(unsigned long long, unsigned long long,
			       unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_mk_time")));

unsigned long long cap_time_get_hart(unsigned long long)
    __attribute__((alias("u_cap_time_get_hart")));

unsigned long long cap_time_get_bgn(unsigned long long)
    __attribute__((alias("u_cap_time_get_bgn")));

unsigned long long cap_time_get_mrk(unsigned long long)
    __attribute__((alias("u_cap_time_get_mrk")));

unsigned long long cap_time_get_end(unsigned long long)
    __attribute__((alias("u_cap_time_get_end")));

unsigned long long cap_time_set_hart(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_time_set_hart")));

unsigned long long cap_time_set_bgn(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_time_set_bgn")));

unsigned long long cap_time_set_mrk(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_time_set_mrk")));

unsigned long long cap_time_set_end(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_time_set_end")));

unsigned long long cap_mk_memory(unsigned long long, unsigned long long,
				 unsigned long long, unsigned long long,
				 unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_mk_memory")));

unsigned long long cap_memory_get_rwx(unsigned long long)
    __attribute__((alias("u_cap_memory_get_rwx")));

unsigned long long cap_memory_get_lck(unsigned long long)
    __attribute__((alias("u_cap_memory_get_lck")));

unsigned long long cap_memory_get_tag(unsigned long long)
    __attribute__((alias("u_cap_memory_get_tag")));

unsigned long long cap_memory_get_bgn(unsigned long long)
    __attribute__((alias("u_cap_memory_get_bgn")));

unsigned long long cap_memory_get_mrk(unsigned long long)
    __attribute__((alias("u_cap_memory_get_mrk")));

unsigned long long cap_memory_get_end(unsigned long long)
    __attribute__((alias("u_cap_memory_get_end")));

unsigned long long cap_memory_set_rwx(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_memory_set_rwx")));

unsigned long long cap_memory_set_lck(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_memory_set_lck")));

unsigned long long cap_memory_set_tag(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_memory_set_tag")));

unsigned long long cap_memory_set_bgn(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_memory_set_bgn")));

unsigned long long cap_memory_set_mrk(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_memory_set_mrk")));

unsigned long long cap_memory_set_end(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_memory_set_end")));

unsigned long long cap_mk_pmp(unsigned long long, unsigned long long,
			      unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_mk_pmp")));

unsigned long long cap_pmp_get_rwx(unsigned long long)
    __attribute__((alias("u_cap_pmp_get_rwx")));

unsigned long long cap_pmp_get_used(unsigned long long)
    __attribute__((alias("u_cap_pmp_get_used")));

unsigned long long cap_pmp_get_slot(unsigned long long)
    __attribute__((alias("u_cap_pmp_get_slot")));

unsigned long long cap_pmp_get_addr(unsigned long long)
    __attribute__((alias("u_cap_pmp_get_addr")));

unsigned long long cap_pmp_set_rwx(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_pmp_set_rwx")));

unsigned long long cap_pmp_set_used(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_pmp_set_used")));

unsigned long long cap_pmp_set_slot(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_pmp_set_slot")));

unsigned long long cap_pmp_set_addr(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_pmp_set_addr")));

unsigned long long cap_mk_monitor(unsigned long long, unsigned long long,
				  unsigned long long)
    __attribute__((alias("u_cap_mk_monitor")));

unsigned long long cap_monitor_get_bgn(unsigned long long)
    __attribute__((alias("u_cap_monitor_get_bgn")));

unsigned long long cap_monitor_get_mrk(unsigned long long)
    __attribute__((alias("u_cap_monitor_get_mrk")));

unsigned long long cap_monitor_get_end(unsigned long long)
    __attribute__((alias("u_cap_monitor_get_end")));

unsigned long long cap_monitor_set_bgn(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_monitor_set_bgn")));

unsigned long long cap_monitor_set_mrk(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_monitor_set_mrk")));

unsigned long long cap_monitor_set_end(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_monitor_set_end")));

unsigned long long cap_mk_channel(unsigned long long, unsigned long long,
				  unsigned long long)
    __attribute__((alias("u_cap_mk_channel")));

unsigned long long cap_channel_get_bgn(unsigned long long)
    __attribute__((alias("u_cap_channel_get_bgn")));

unsigned long long cap_channel_get_mrk(unsigned long long)
    __attribute__((alias("u_cap_channel_get_mrk")));

unsigned long long cap_channel_get_end(unsigned long long)
    __attribute__((alias("u_cap_channel_get_end")));

unsigned long long cap_channel_set_bgn(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_channel_set_bgn")));

unsigned long long cap_channel_set_mrk(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_channel_set_mrk")));

unsigned long long cap_channel_set_end(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_channel_set_end")));

unsigned long long cap_mk_socket(unsigned long long, unsigned long long,
				 unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_mk_socket")));

unsigned long long cap_socket_get_mode(unsigned long long)
    __attribute__((alias("u_cap_socket_get_mode")));

unsigned long long cap_socket_get_perm(unsigned long long)
    __attribute__((alias("u_cap_socket_get_perm")));

unsigned long long cap_socket_get_chan(unsigned long long)
    __attribute__((alias("u_cap_socket_get_chan")));

unsigned long long cap_socket_get_tag(unsigned long long)
    __attribute__((alias("u_cap_socket_get_tag")));

unsigned long long cap_socket_set_mode(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_socket_set_mode")));

unsigned long long cap_socket_set_perm(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_socket_set_perm")));

unsigned long long cap_socket_set_chan(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_socket_set_chan")));

unsigned long long cap_socket_set_tag(unsigned long long, unsigned long long)
    __attribute__((alias("u_cap_socket_set_tag")));

_Bool ctable_is_empty_cap(struct kernel_state *, unsigned int)
    __attribute__((alias("u_ctable_is_empty_cap")));

struct kernel_state *ctable_set_cap(struct kernel_state *, unsigned int,
				    unsigned long long)
    __attribute__((alias("u_ctable_set_cap")));

struct kernel_state *ctable_set_next(struct kernel_state *, unsigned int,
				     unsigned int)
    __attribute__((alias("u_ctable_set_next")));

struct kernel_state *ctable_set_prev(struct kernel_state *, unsigned int,
				     unsigned int)
    __attribute__((alias("u_ctable_set_prev")));

struct kernel_state *ctable_move_cap(struct kernel_state *, unsigned int,
				     unsigned int)
    __attribute__((alias("u_ctable_move_cap")));

struct kernel_state *ctable_delete_cap(struct kernel_state *, unsigned int)
    __attribute__((alias("u_ctable_delete_cap")));

struct kernel_state *ctable_insert_cap(struct kernel_state *, unsigned int,
				       unsigned long long, unsigned int)
    __attribute__((alias("u_ctable_insert_cap")));

unsigned long long cap_pid(unsigned int) __attribute__((alias("u_cap_pid")));

unsigned long long pmp_napot_decode_base(unsigned long long)
    __attribute__((alias("u_pmp_napot_decode_base")));

unsigned long long pmp_napot_decode_size(unsigned long long)
    __attribute__((alias("u_pmp_napot_decode_size")));

unsigned long long tag_block_to_addr(unsigned long long, unsigned long long)
    __attribute__((alias("u_tag_block_to_addr")));

struct kernel_state *cap_delete_memory(struct kernel_state *, unsigned int)
    __attribute__((alias("u_cap_delete_memory")));

struct kernel_state *cap_revoke_memory(struct kernel_state *, unsigned int)
    __attribute__((alias("u_cap_revoke_memory")));

struct kernel_state *cap_derive_memory(struct kernel_state *, unsigned int,
				       unsigned int, unsigned long long)
    __attribute__((alias("u_cap_derive_memory")));

struct kernel_state *cap_delete_pmp(struct kernel_state *, unsigned int)
    __attribute__((alias("u_cap_delete_pmp")));

struct kernel_state *cap_revoke_pmp(struct kernel_state *)
    __attribute__((alias("u_cap_revoke_pmp")));

struct kernel_state *cap_derive_pmp(struct kernel_state *, unsigned int,
				    unsigned int, unsigned long long)
    __attribute__((alias("u_cap_derive_pmp")));

struct kernel_state *cap_read(struct kernel_state *, unsigned int)
    __attribute__((alias("u_cap_read")));

struct kernel_state *cap_move(struct kernel_state *, unsigned int, unsigned int)
    __attribute__((alias("u_cap_move")));

struct kernel_state *cap_delete(struct kernel_state *, unsigned int)
    __attribute__((alias("u_cap_delete")));

struct kernel_state *cap_derive(struct kernel_state *, unsigned int,
				unsigned int, unsigned long long)
    __attribute__((alias("u_cap_derive")));
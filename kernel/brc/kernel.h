struct kernel_state {
  unsigned int *cnext;
  unsigned int *cprev;
  unsigned long long *ctable;
  unsigned long long *vregs;
  int errcode;
};

static inline unsigned long long vreg_read(struct kernel_state *, unsigned int) __attribute__((alias("u_vreg_read")));

static inline struct kernel_state *vreg_write(struct kernel_state *, unsigned int, unsigned long long) __attribute__((alias("u_vreg_write")));

static inline unsigned long long cap_get_type(unsigned long long) __attribute__((alias("u_cap_get_type")));

static inline unsigned long long cap_mk_none(void) __attribute__((alias("u_cap_mk_none")));

static inline unsigned long long cap_mk_time(unsigned long long, unsigned long long, unsigned long long, unsigned long long) __attribute__((alias("u_cap_mk_time")));

static inline unsigned long long cap_time_get_hart(unsigned long long) __attribute__((alias("u_cap_time_get_hart")));

static inline unsigned long long cap_time_get_bgn(unsigned long long) __attribute__((alias("u_cap_time_get_bgn")));

static inline unsigned long long cap_time_get_mrk(unsigned long long) __attribute__((alias("u_cap_time_get_mrk")));

static inline unsigned long long cap_time_get_end(unsigned long long) __attribute__((alias("u_cap_time_get_end")));

static inline unsigned long long cap_time_set_hart(unsigned long long, unsigned long long) __attribute__((alias("u_cap_time_set_hart")));

static inline unsigned long long cap_time_set_bgn(unsigned long long, unsigned long long) __attribute__((alias("u_cap_time_set_bgn")));

static inline unsigned long long cap_time_set_mrk(unsigned long long, unsigned long long) __attribute__((alias("u_cap_time_set_mrk")));

static inline unsigned long long cap_time_set_end(unsigned long long, unsigned long long) __attribute__((alias("u_cap_time_set_end")));

static inline unsigned long long cap_mk_memory(unsigned long long, unsigned long long, unsigned long long, unsigned long long, unsigned long long, unsigned long long) __attribute__((alias("u_cap_mk_memory")));

static inline unsigned long long cap_memory_get_rwx(unsigned long long) __attribute__((alias("u_cap_memory_get_rwx")));

static inline unsigned long long cap_memory_get_lck(unsigned long long) __attribute__((alias("u_cap_memory_get_lck")));

static inline unsigned long long cap_memory_get_tag(unsigned long long) __attribute__((alias("u_cap_memory_get_tag")));

static inline unsigned long long cap_memory_get_bgn(unsigned long long) __attribute__((alias("u_cap_memory_get_bgn")));

static inline unsigned long long cap_memory_get_mrk(unsigned long long) __attribute__((alias("u_cap_memory_get_mrk")));

static inline unsigned long long cap_memory_get_end(unsigned long long) __attribute__((alias("u_cap_memory_get_end")));

static inline unsigned long long cap_memory_set_rwx(unsigned long long, unsigned long long) __attribute__((alias("u_cap_memory_set_rwx")));

static inline unsigned long long cap_memory_set_lck(unsigned long long, unsigned long long) __attribute__((alias("u_cap_memory_set_lck")));

static inline unsigned long long cap_memory_set_tag(unsigned long long, unsigned long long) __attribute__((alias("u_cap_memory_set_tag")));

static inline unsigned long long cap_memory_set_bgn(unsigned long long, unsigned long long) __attribute__((alias("u_cap_memory_set_bgn")));

static inline unsigned long long cap_memory_set_mrk(unsigned long long, unsigned long long) __attribute__((alias("u_cap_memory_set_mrk")));

static inline unsigned long long cap_memory_set_end(unsigned long long, unsigned long long) __attribute__((alias("u_cap_memory_set_end")));

static inline unsigned long long cap_mk_pmp(unsigned long long, unsigned long long, unsigned long long, unsigned long long) __attribute__((alias("u_cap_mk_pmp")));

static inline unsigned long long cap_pmp_get_rwx(unsigned long long) __attribute__((alias("u_cap_pmp_get_rwx")));

static inline unsigned long long cap_pmp_get_used(unsigned long long) __attribute__((alias("u_cap_pmp_get_used")));

static inline unsigned long long cap_pmp_get_slot(unsigned long long) __attribute__((alias("u_cap_pmp_get_slot")));

static inline unsigned long long cap_pmp_get_addr(unsigned long long) __attribute__((alias("u_cap_pmp_get_addr")));

static inline unsigned long long cap_pmp_set_rwx(unsigned long long, unsigned long long) __attribute__((alias("u_cap_pmp_set_rwx")));

static inline unsigned long long cap_pmp_set_used(unsigned long long, unsigned long long) __attribute__((alias("u_cap_pmp_set_used")));

static inline unsigned long long cap_pmp_set_slot(unsigned long long, unsigned long long) __attribute__((alias("u_cap_pmp_set_slot")));

static inline unsigned long long cap_pmp_set_addr(unsigned long long, unsigned long long) __attribute__((alias("u_cap_pmp_set_addr")));

static inline unsigned long long cap_mk_monitor(unsigned long long, unsigned long long, unsigned long long) __attribute__((alias("u_cap_mk_monitor")));

static inline unsigned long long cap_monitor_get_bgn(unsigned long long) __attribute__((alias("u_cap_monitor_get_bgn")));

static inline unsigned long long cap_monitor_get_mrk(unsigned long long) __attribute__((alias("u_cap_monitor_get_mrk")));

static inline unsigned long long cap_monitor_get_end(unsigned long long) __attribute__((alias("u_cap_monitor_get_end")));

static inline unsigned long long cap_monitor_set_bgn(unsigned long long, unsigned long long) __attribute__((alias("u_cap_monitor_set_bgn")));

static inline unsigned long long cap_monitor_set_mrk(unsigned long long, unsigned long long) __attribute__((alias("u_cap_monitor_set_mrk")));

static inline unsigned long long cap_monitor_set_end(unsigned long long, unsigned long long) __attribute__((alias("u_cap_monitor_set_end")));

static inline unsigned long long cap_mk_channel(unsigned long long, unsigned long long, unsigned long long) __attribute__((alias("u_cap_mk_channel")));

static inline unsigned long long cap_channel_get_bgn(unsigned long long) __attribute__((alias("u_cap_channel_get_bgn")));

static inline unsigned long long cap_channel_get_mrk(unsigned long long) __attribute__((alias("u_cap_channel_get_mrk")));

static inline unsigned long long cap_channel_get_end(unsigned long long) __attribute__((alias("u_cap_channel_get_end")));

static inline unsigned long long cap_channel_set_bgn(unsigned long long, unsigned long long) __attribute__((alias("u_cap_channel_set_bgn")));

static inline unsigned long long cap_channel_set_mrk(unsigned long long, unsigned long long) __attribute__((alias("u_cap_channel_set_mrk")));

static inline unsigned long long cap_channel_set_end(unsigned long long, unsigned long long) __attribute__((alias("u_cap_channel_set_end")));

static inline unsigned long long cap_mk_socket(unsigned long long, unsigned long long, unsigned long long, unsigned long long) __attribute__((alias("u_cap_mk_socket")));

static inline unsigned long long cap_socket_get_mode(unsigned long long) __attribute__((alias("u_cap_socket_get_mode")));

static inline unsigned long long cap_socket_get_perm(unsigned long long) __attribute__((alias("u_cap_socket_get_perm")));

static inline unsigned long long cap_socket_get_chan(unsigned long long) __attribute__((alias("u_cap_socket_get_chan")));

static inline unsigned long long cap_socket_get_tag(unsigned long long) __attribute__((alias("u_cap_socket_get_tag")));

static inline unsigned long long cap_socket_set_mode(unsigned long long, unsigned long long) __attribute__((alias("u_cap_socket_set_mode")));

static inline unsigned long long cap_socket_set_perm(unsigned long long, unsigned long long) __attribute__((alias("u_cap_socket_set_perm")));

static inline unsigned long long cap_socket_set_chan(unsigned long long, unsigned long long) __attribute__((alias("u_cap_socket_set_chan")));

static inline unsigned long long cap_socket_set_tag(unsigned long long, unsigned long long) __attribute__((alias("u_cap_socket_set_tag")));

static inline _Bool ctable_is_empty_cap(struct kernel_state *, unsigned int) __attribute__((alias("u_ctable_is_empty_cap")));

static inline struct kernel_state *ctable_set_cap(struct kernel_state *, unsigned int, unsigned long long) __attribute__((alias("u_ctable_set_cap")));

static inline struct kernel_state *ctable_set_next(struct kernel_state *, unsigned int, unsigned int) __attribute__((alias("u_ctable_set_next")));

static inline struct kernel_state *ctable_set_prev(struct kernel_state *, unsigned int, unsigned int) __attribute__((alias("u_ctable_set_prev")));

static inline struct kernel_state *ctable_move_cap(struct kernel_state *, unsigned int, unsigned int) __attribute__((alias("u_ctable_move_cap")));

static inline struct kernel_state *ctable_delete_cap(struct kernel_state *, unsigned int) __attribute__((alias("u_ctable_delete_cap")));

static inline struct kernel_state *ctable_insert_cap(struct kernel_state *, unsigned int, unsigned long long, unsigned int) __attribute__((alias("u_ctable_insert_cap")));

static inline unsigned long long cap_pid(unsigned int) __attribute__((alias("u_cap_pid")));

static inline unsigned long long pmp_napot_decode_base(unsigned long long) __attribute__((alias("u_pmp_napot_decode_base")));

static inline unsigned long long pmp_napot_decode_size(unsigned long long) __attribute__((alias("u_pmp_napot_decode_size")));

static inline unsigned long long tag_block_to_addr(unsigned long long, unsigned long long) __attribute__((alias("u_tag_block_to_addr")));

static inline struct kernel_state *cap_delete_memory(struct kernel_state *, unsigned int) __attribute__((alias("u_cap_delete_memory")));

static inline struct kernel_state *cap_revoke_memory(struct kernel_state *, unsigned int) __attribute__((alias("u_cap_revoke_memory")));

static inline struct kernel_state *cap_derive_memory(struct kernel_state *, unsigned int, unsigned int, unsigned long long) __attribute__((alias("u_cap_derive_memory")));

static inline struct kernel_state *cap_delete_pmp(struct kernel_state *, unsigned int) __attribute__((alias("u_cap_delete_pmp")));

static inline struct kernel_state *cap_revoke_pmp(struct kernel_state *) __attribute__((alias("u_cap_revoke_pmp")));

static inline struct kernel_state *cap_derive_pmp(struct kernel_state *, unsigned int, unsigned int, unsigned long long) __attribute__((alias("u_cap_derive_pmp")));

static inline struct kernel_state *cap_read(struct kernel_state *, unsigned int) __attribute__((alias("u_cap_read")));

static inline struct kernel_state *cap_move(struct kernel_state *, unsigned int, unsigned int) __attribute__((alias("u_cap_move")));

static inline struct kernel_state *cap_delete(struct kernel_state *, unsigned int) __attribute__((alias("u_cap_delete")));

static inline struct kernel_state *cap_derive(struct kernel_state *, unsigned int, unsigned int, unsigned long long) __attribute__((alias("u_cap_derive")));
struct Proc_proc_t;
struct Kernel_state;
struct Proc_proc_t {
  unsigned long long state;
  unsigned long long pc;
  unsigned long long ra;
  unsigned long long sp;
  unsigned long long gp;
  unsigned long long tp;
  unsigned long long t0;
  unsigned long long t1;
  unsigned long long t2;
  unsigned long long s0;
  unsigned long long s1;
  unsigned long long a0;
  unsigned long long a1;
  unsigned long long a2;
  unsigned long long a3;
  unsigned long long a4;
  unsigned long long a5;
  unsigned long long a6;
  unsigned long long a7;
  unsigned long long s2;
  unsigned long long s3;
  unsigned long long s4;
  unsigned long long s5;
  unsigned long long s6;
  unsigned long long s7;
  unsigned long long s8;
  unsigned long long s9;
  unsigned long long s10;
  unsigned long long s11;
  unsigned long long t3;
  unsigned long long t4;
  unsigned long long t5;
  unsigned long long t76;
  unsigned long long ecause;
  unsigned long long eval;
  unsigned long long servtime;
  unsigned int *pmpcfg;
  unsigned long long *pmpaddr;
  unsigned int pid;
  unsigned long long timeout;
  unsigned long long serv_time;
};

struct Kernel_state {
  unsigned int *cnext;
  unsigned int *cprev;
  unsigned long long *ctable;
  unsigned long long *tslots;
  struct Proc_proc_t **ptable;
  unsigned long long *vregs;
  long long errcode;
};

unsigned long long Cap_get_type(unsigned long long);
unsigned long long Cap_mk_none(void);
unsigned long long Cap_mk_time(unsigned long long, unsigned long long, unsigned long long, unsigned long long);
unsigned long long Cap_time_get_hart(unsigned long long);
unsigned long long Cap_time_get_bgn(unsigned long long);
unsigned long long Cap_time_get_mrk(unsigned long long);
unsigned long long Cap_time_get_end(unsigned long long);
unsigned long long Cap_time_set_hart(unsigned long long, unsigned long long);
unsigned long long Cap_time_set_bgn(unsigned long long, unsigned long long);
unsigned long long Cap_time_set_mrk(unsigned long long, unsigned long long);
unsigned long long Cap_time_set_end(unsigned long long, unsigned long long);
unsigned long long Cap_mk_memory(unsigned long long, unsigned long long, unsigned long long, unsigned long long, unsigned long long, unsigned long long);
unsigned long long Cap_memory_get_rwx(unsigned long long);
_Bool Cap_memory_get_lck(unsigned long long);
unsigned long long Cap_memory_get_tag(unsigned long long);
unsigned long long Cap_memory_get_bgn(unsigned long long);
unsigned long long Cap_memory_get_mrk(unsigned long long);
unsigned long long Cap_memory_get_end(unsigned long long);
unsigned long long Cap_memory_set_rwx(unsigned long long, unsigned long long);
unsigned long long Cap_memory_set_lck(unsigned long long, _Bool);
unsigned long long Cap_memory_set_tag(unsigned long long, unsigned long long);
unsigned long long Cap_memory_set_bgn(unsigned long long, unsigned long long);
unsigned long long Cap_memory_set_mrk(unsigned long long, unsigned long long);
unsigned long long Cap_memory_set_end(unsigned long long, unsigned long long);
unsigned long long Cap_mk_pmp(unsigned long long, unsigned long long, unsigned long long, unsigned long long);
unsigned long long Cap_pmp_get_rwx(unsigned long long);
_Bool Cap_pmp_get_used(unsigned long long);
unsigned long long Cap_pmp_get_slot(unsigned long long);
unsigned long long Cap_pmp_get_addr(unsigned long long);
unsigned long long Cap_pmp_set_rwx(unsigned long long, unsigned long long);
unsigned long long Cap_pmp_set_used(unsigned long long, _Bool);
unsigned long long Cap_pmp_set_slot(unsigned long long, unsigned long long);
unsigned long long Cap_pmp_set_addr(unsigned long long, unsigned long long);
unsigned long long Cap_mk_monitor(unsigned long long, unsigned long long, unsigned long long);
unsigned long long Cap_monitor_get_bgn(unsigned long long);
unsigned long long Cap_monitor_get_mrk(unsigned long long);
unsigned long long Cap_monitor_get_end(unsigned long long);
unsigned long long Cap_monitor_set_bgn(unsigned long long, unsigned long long);
unsigned long long Cap_monitor_set_mrk(unsigned long long, unsigned long long);
unsigned long long Cap_monitor_set_end(unsigned long long, unsigned long long);
unsigned long long Cap_mk_channel(unsigned long long, unsigned long long, unsigned long long);
unsigned long long Cap_channel_get_bgn(unsigned long long);
unsigned long long Cap_channel_get_mrk(unsigned long long);
unsigned long long Cap_channel_get_end(unsigned long long);
unsigned long long Cap_channel_set_bgn(unsigned long long, unsigned long long);
unsigned long long Cap_channel_set_mrk(unsigned long long, unsigned long long);
unsigned long long Cap_channel_set_end(unsigned long long, unsigned long long);
unsigned long long Cap_mk_socket(unsigned long long, unsigned long long, unsigned long long, unsigned long long);
unsigned long long Cap_socket_get_mode(unsigned long long);
unsigned long long Cap_socket_get_perm(unsigned long long);
unsigned long long Cap_socket_get_chan(unsigned long long);
unsigned long long Cap_socket_get_tag(unsigned long long);
unsigned long long Cap_socket_set_mode(unsigned long long, unsigned long long);
unsigned long long Cap_socket_set_perm(unsigned long long, unsigned long long);
unsigned long long Cap_socket_set_chan(unsigned long long, unsigned long long);
unsigned long long Cap_socket_set_tag(unsigned long long, unsigned long long);
struct Proc_proc_t *Proc_suspend(struct Proc_proc_t *);
struct Proc_proc_t *Proc_resume(struct Proc_proc_t *);
struct Proc_proc_t *Proc_release(struct Proc_proc_t *);
_Bool Proc_is_suspended(struct Proc_proc_t *);
_Bool Proc_pmp_avail(struct Proc_proc_t *, unsigned int);
struct Proc_proc_t *Proc_pmp_load(struct Proc_proc_t *, unsigned int, unsigned int, unsigned long long);
struct Proc_proc_t *Proc_pmp_unload(struct Proc_proc_t *, unsigned int);
unsigned long long Kernel_vreg_read(struct Kernel_state *, unsigned int);
struct Kernel_state *Kernel_vreg_write(struct Kernel_state *, unsigned int, unsigned long long);
struct Kernel_state *Sched_delete(struct Kernel_state *, unsigned long long, unsigned long long);
struct Kernel_state *Sched_update(struct Kernel_state *, unsigned long long, unsigned long long, unsigned long long, unsigned long long);
_Bool Ctable_is_empty_cap(struct Kernel_state *, unsigned int);
struct Kernel_state *Ctable_set_cap(struct Kernel_state *, unsigned int, unsigned long long);
struct Kernel_state *Ctable_set_next(struct Kernel_state *, unsigned int, unsigned int);
struct Kernel_state *Ctable_set_prev(struct Kernel_state *, unsigned int, unsigned int);
struct Kernel_state *Ctable_move(struct Kernel_state *, unsigned int, unsigned int);
struct Kernel_state *Ctable_delete(struct Kernel_state *, unsigned int);
struct Kernel_state *Ctable_insert(struct Kernel_state *, unsigned int, unsigned long long, unsigned int);
struct Kernel_state *Ptable_acquire(struct Kernel_state *, unsigned long long, unsigned int);
struct Kernel_state *Ptable_suspend(struct Kernel_state *, unsigned int);
struct Kernel_state *Ptable_resume(struct Kernel_state *, unsigned int);
struct Kernel_state *Ptable_release(struct Kernel_state *, unsigned int);
_Bool Ptable_is_suspended(struct Kernel_state *, unsigned int);
_Bool Ptable_pmp_avail(struct Kernel_state *, unsigned int, unsigned int);
struct Kernel_state *Ptable_pmp_load(struct Kernel_state *, unsigned int, unsigned int, unsigned int, unsigned long long);
struct Kernel_state *Ptable_pmp_unload(struct Kernel_state *, unsigned int, unsigned int);
unsigned int Cap_ops_cap_pid(unsigned int);
unsigned long long Cap_ops_pmp_napot_decode_base(unsigned long long);
unsigned long long Cap_ops_pmp_napot_decode_size(unsigned long long);
unsigned long long Cap_ops_tag_block_to_addr(unsigned long long, unsigned long long);
struct Kernel_state *Cap_ops_delete_memory(struct Kernel_state *, unsigned int);
struct Kernel_state *Cap_ops_revoke_memory(struct Kernel_state *, unsigned int);
struct Kernel_state *Cap_ops_derive_memory(struct Kernel_state *, unsigned int, unsigned int, unsigned long long);
struct Kernel_state *Cap_ops_delete_pmp(struct Kernel_state *, unsigned int);
struct Kernel_state *Cap_ops_revoke_pmp(struct Kernel_state *);
struct Kernel_state *Cap_ops_derive_pmp(struct Kernel_state *, unsigned int, unsigned int, unsigned long long);
struct Kernel_state *Cap_ops_delete_time(struct Kernel_state *, unsigned int);
struct Kernel_state *Cap_ops_revoke_time(struct Kernel_state *, unsigned int);
struct Kernel_state *Cap_ops_derive_time(struct Kernel_state *, unsigned int, unsigned int, unsigned long long);
struct Kernel_state *Cap_ops_delete_monitor(struct Kernel_state *, unsigned int);
struct Kernel_state *Cap_ops_revoke_monitor(struct Kernel_state *, unsigned int);
struct Kernel_state *Cap_ops_cap_derive_monitor(struct Kernel_state *, unsigned int, unsigned int, unsigned long long);
struct Kernel_state *Cap_ops_read(struct Kernel_state *, unsigned int);
struct Kernel_state *Cap_ops_move(struct Kernel_state *, unsigned int, unsigned int);
struct Kernel_state *Cap_ops_delete(struct Kernel_state *, unsigned int);
struct Kernel_state *Cap_ops_derive(struct Kernel_state *, unsigned int, unsigned int, unsigned long long);
struct Kernel_state *Pmp_load(struct Kernel_state *, unsigned int, unsigned int);
struct Kernel_state *Pmp_unload(struct Kernel_state *, unsigned int);
long long Monitor_check(struct Kernel_state *, unsigned int, unsigned int, _Bool);
long long Monitor_check_move(struct Kernel_state *, unsigned int, unsigned int, unsigned int);
struct Kernel_state *Monitor_cap_resume(struct Kernel_state *, unsigned int, unsigned int);
long long Error_SUCCESS = 0LL;

long long Error_ERR_EMPTY = 1LL;

long long Error_ERR_SRC_EMPTY = 2LL;

long long Error_ERR_DST_OCCUPIED = 3LL;

long long Error_ERR_INVALID_DERIVATION = 5LL;

long long Error_ERR_INVALID_MONITOR = 6LL;

long long Error_ERR_INVALID_STATE = 8LL;

long long Error_ERR_INVALID_PMP = 9LL;

long long Error_ERR_INVALID_CAPABILITY = 14LL;

long long Error_ERR_SUSPENDED = 18LL;

long long Error_CONTINUE = -1LL;

unsigned long long Cap_CAPTY_NONE = 0LL;

unsigned long long Cap_CAPTY_TIME = 1LL;

unsigned long long Cap_CAPTY_MEMORY = 2LL;

unsigned long long Cap_CAPTY_PMP = 3LL;

unsigned long long Cap_CAPTY_MONITOR = 4LL;

unsigned long long Cap_CAPTY_CHANNEL = 5LL;

unsigned long long Cap_CAPTY_SOCKET = 6LL;

unsigned long long Cap_CAPTY_COUNT = 7LL;

unsigned long long Cap_get_type(unsigned long long $p_cap)
{
  return $p_cap & 15LL;
}

unsigned long long Cap_mk_none(void)
{
  return Cap_CAPTY_NONE;
}

unsigned long long Cap_mk_time(unsigned long long $p_hart, unsigned long long $p_bgn, unsigned long long $p_mrk, unsigned long long $p_end)
{
  return Cap_CAPTY_TIME | $p_end << 48LL | $p_mrk << 32LL | $p_bgn << 16LL
           | $p_hart << 8LL;
}

unsigned long long Cap_time_get_hart(unsigned long long $p_cap)
{
  return $p_cap >> 8LL & 255LL;
}

unsigned long long Cap_time_get_bgn(unsigned long long $p_cap)
{
  return $p_cap >> 16LL & 65535LL;
}

unsigned long long Cap_time_get_mrk(unsigned long long $p_cap)
{
  return $p_cap >> 32LL & 65535LL;
}

unsigned long long Cap_time_get_end(unsigned long long $p_cap)
{
  return $p_cap >> 48LL & 65535LL;
}

unsigned long long Cap_time_set_hart(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~65280LL | $p_v << 8LL;
}

unsigned long long Cap_time_set_bgn(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~4294901760LL | $p_v << 16LL;
}

unsigned long long Cap_time_set_mrk(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~281470681743360LL | $p_v << 32LL;
}

unsigned long long Cap_time_set_end(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~-281474976710656LL | $p_v << 48LL;
}

unsigned long long Cap_mk_memory(unsigned long long $p_rwx, unsigned long long $p_lck, unsigned long long $p_tag, unsigned long long $p_bgn, unsigned long long $p_mrk, unsigned long long $p_end)
{
  return Cap_CAPTY_MEMORY | $p_end << 48LL | $p_mrk << 32LL | $p_bgn << 16LL
           | $p_tag << 8LL | $p_lck << 7LL | $p_rwx << 4LL;
}

unsigned long long Cap_memory_get_rwx(unsigned long long $p_cap)
{
  return $p_cap >> 4LL & 7LL;
}

_Bool Cap_memory_get_lck(unsigned long long $p_cap)
{
  return (_Bool) ($p_cap >> 7LL & 1LL);
}

unsigned long long Cap_memory_get_tag(unsigned long long $p_cap)
{
  return $p_cap >> 8LL & 255LL;
}

unsigned long long Cap_memory_get_bgn(unsigned long long $p_cap)
{
  return $p_cap >> 16LL & 65535LL;
}

unsigned long long Cap_memory_get_mrk(unsigned long long $p_cap)
{
  return $p_cap >> 32LL & 65535LL;
}

unsigned long long Cap_memory_get_end(unsigned long long $p_cap)
{
  return $p_cap >> 48LL & 65535LL;
}

unsigned long long Cap_memory_set_rwx(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~112LL | $p_v << 4LL;
}

unsigned long long Cap_memory_set_lck(unsigned long long $p_cap, _Bool $p_v)
{
  return $p_cap & ~1LL | (unsigned long long) $p_v << 7LL;
}

unsigned long long Cap_memory_set_tag(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~65280LL | $p_v << 8LL;
}

unsigned long long Cap_memory_set_bgn(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~4294901760LL | $p_v << 16LL;
}

unsigned long long Cap_memory_set_mrk(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~281470681743360LL | $p_v << 32LL;
}

unsigned long long Cap_memory_set_end(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~-281474976710656LL | $p_v << 48LL;
}

unsigned long long Cap_mk_pmp(unsigned long long $p_rwx, unsigned long long $p_used, unsigned long long $p_slot, unsigned long long $p_addr)
{
  return Cap_CAPTY_PMP | $p_addr << 16LL | $p_slot << 8LL | $p_used << 7LL
           | $p_rwx << 4LL;
}

unsigned long long Cap_pmp_get_rwx(unsigned long long $p_cap)
{
  return $p_cap >> 4LL & 7LL;
}

_Bool Cap_pmp_get_used(unsigned long long $p_cap)
{
  return (_Bool) ($p_cap >> 7LL & 1LL);
}

unsigned long long Cap_pmp_get_slot(unsigned long long $p_cap)
{
  return $p_cap >> 8LL & 255LL;
}

unsigned long long Cap_pmp_get_addr(unsigned long long $p_cap)
{
  return $p_cap >> 16LL & 281474976710655LL;
}

unsigned long long Cap_pmp_set_rwx(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~112LL | $p_v << 4LL;
}

unsigned long long Cap_pmp_set_used(unsigned long long $p_cap, _Bool $p_v)
{
  return $p_cap & ~1LL | (unsigned long long) $p_v << 7LL;
}

unsigned long long Cap_pmp_set_slot(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~65280LL | $p_v << 8LL;
}

unsigned long long Cap_pmp_set_addr(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~-65536LL | $p_v << 16LL;
}

unsigned long long Cap_mk_monitor(unsigned long long $p_bgn, unsigned long long $p_mrk, unsigned long long $p_end)
{
  return Cap_CAPTY_MONITOR | $p_end << 48LL | $p_mrk << 32LL | $p_bgn << 16LL;
}

unsigned long long Cap_monitor_get_bgn(unsigned long long $p_cap)
{
  return $p_cap >> 16LL & 65535LL;
}

unsigned long long Cap_monitor_get_mrk(unsigned long long $p_cap)
{
  return $p_cap >> 32LL & 65535LL;
}

unsigned long long Cap_monitor_get_end(unsigned long long $p_cap)
{
  return $p_cap >> 48LL & 65535LL;
}

unsigned long long Cap_monitor_set_bgn(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~4294901760LL | $p_v << 16LL;
}

unsigned long long Cap_monitor_set_mrk(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~281470681743360LL | $p_v << 32LL;
}

unsigned long long Cap_monitor_set_end(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~-281474976710656LL | $p_v << 48LL;
}

unsigned long long Cap_mk_channel(unsigned long long $p_bgn, unsigned long long $p_mrk, unsigned long long $p_end)
{
  return Cap_CAPTY_CHANNEL | $p_end << 48LL | $p_mrk << 32LL | $p_bgn << 16LL;
}

unsigned long long Cap_channel_get_bgn(unsigned long long $p_cap)
{
  return $p_cap >> 16LL & 65535LL;
}

unsigned long long Cap_channel_get_mrk(unsigned long long $p_cap)
{
  return $p_cap >> 32LL & 65535LL;
}

unsigned long long Cap_channel_get_end(unsigned long long $p_cap)
{
  return $p_cap >> 48LL & 65535LL;
}

unsigned long long Cap_channel_set_bgn(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~4294901760LL | $p_v << 16LL;
}

unsigned long long Cap_channel_set_mrk(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~281470681743360LL | $p_v << 32LL;
}

unsigned long long Cap_channel_set_end(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~-281474976710656LL | $p_v << 48LL;
}

unsigned long long Cap_mk_socket(unsigned long long $p_mode, unsigned long long $p_perm, unsigned long long $p_chan, unsigned long long $p_tag)
{
  return Cap_CAPTY_SOCKET | $p_tag << 32LL | $p_chan << 16LL | $p_perm << 8LL
           | $p_mode << 4LL;
}

unsigned long long Cap_socket_get_mode(unsigned long long $p_cap)
{
  return $p_cap >> 4LL & 15LL;
}

unsigned long long Cap_socket_get_perm(unsigned long long $p_cap)
{
  return $p_cap >> 8LL & 255LL;
}

unsigned long long Cap_socket_get_chan(unsigned long long $p_cap)
{
  return $p_cap >> 16LL & 65535LL;
}

unsigned long long Cap_socket_get_tag(unsigned long long $p_cap)
{
  return $p_cap >> 32LL & 4294967295LL;
}

unsigned long long Cap_socket_set_mode(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~240LL | $p_v << 4LL;
}

unsigned long long Cap_socket_set_perm(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~65280LL | $p_v << 8LL;
}

unsigned long long Cap_socket_set_chan(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~4294901760LL | $p_v << 16LL;
}

unsigned long long Cap_socket_set_tag(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap & ~-4294967296LL | $p_v << 32LL;
}

unsigned long long Proc_PSF_BUSY = 1LL;

unsigned long long Proc_PSF_BLOCKED = 2LL;

unsigned long long Proc_PSF_SUSPENDED = 4LL;

struct Proc_proc_t *Proc_suspend(struct Proc_proc_t *$p_proc)
{
  register unsigned long long $u_prev;
  register unsigned long long $b1;
  register unsigned long long $b0;
  register struct Proc_proc_t *$u_proc;
  register struct Proc_proc_t *$i0;
  $u_prev = (*$p_proc).state;
  $b1 = (*$p_proc).state;
  $b0 = $b1 | Proc_PSF_SUSPENDED;
  (*$p_proc).state = $b0;
  $u_proc = $p_proc;
  if ((_Bool) ($u_prev & Proc_PSF_BLOCKED)) {
    (*$u_proc).state = Proc_PSF_SUSPENDED;
    $u_proc = $u_proc;
    (*$u_proc).t0 = (unsigned long long) Error_ERR_SUSPENDED;
    $i0 = $u_proc;
    return $i0;
  } else {
    return $u_proc;
  }
}

struct Proc_proc_t *Proc_resume(struct Proc_proc_t *$p_proc)
{
  register unsigned long long $b3;
  register _Bool $b2;
  register struct Proc_proc_t *$i0;
  register unsigned long long $b1;
  register unsigned long long $b0;
  register struct Proc_proc_t *$i1;
  $b3 = (*$p_proc).state;
  $b2 = $b3 == Proc_PSF_SUSPENDED;
  if ($b2) {
    (*$p_proc).timeout = 0LL;
    $i0 = $p_proc;
    return $i0;
  } else {
    $b1 = (*$p_proc).state;
    $b0 = $b1 & ~Proc_PSF_SUSPENDED;
    (*$p_proc).state = $b0;
    $i1 = $p_proc;
    return $i1;
  }
}

struct Proc_proc_t *Proc_release(struct Proc_proc_t *$p_proc)
{
  register unsigned long long $b1;
  register unsigned long long $b0;
  register struct Proc_proc_t *$i0;
  $b1 = (*$p_proc).state;
  $b0 = $b1 & ~Proc_PSF_BUSY;
  (*$p_proc).state = $b0;
  $i0 = $p_proc;
  return $i0;
}

_Bool Proc_is_suspended(struct Proc_proc_t *$p_proc)
{
  register unsigned long long $b0;
  $b0 = (*$p_proc).state;
  return $b0 == Proc_PSF_SUSPENDED;
}

_Bool Proc_pmp_avail(struct Proc_proc_t *$p_proc, unsigned int $p_slot)
{
  register unsigned int $b0;
  $b0 = *((*$p_proc).pmpcfg + $p_slot);
  return $b0 == 0;
}

struct Proc_proc_t *Proc_pmp_load(struct Proc_proc_t *$p_proc, unsigned int $p_slot, unsigned int $p_rwx, unsigned long long $p_addr)
{
  register unsigned int *$u_pcfg;
  register unsigned long long *$u_paddr;
  register struct Proc_proc_t *$u_proc;
  register struct Proc_proc_t *$i0;
  $u_pcfg = (*$p_proc).pmpcfg;
  $u_paddr = (*$p_proc).pmpaddr;
  *($u_pcfg + $p_slot) = $p_rwx | 24;
  $u_pcfg = $u_pcfg;
  *($u_paddr + $p_slot) = $p_addr;
  $u_paddr = $u_paddr;
  (*$p_proc).pmpcfg = $u_pcfg;
  $u_proc = $p_proc;
  (*$u_proc).pmpaddr = $u_paddr;
  $i0 = $u_proc;
  return $i0;
}

struct Proc_proc_t *Proc_pmp_unload(struct Proc_proc_t *$p_proc, unsigned int $p_slot)
{
  register unsigned int *$u_pcfg;
  register struct Proc_proc_t *$i0;
  $u_pcfg = (*$p_proc).pmpcfg;
  *($u_pcfg + $p_slot) = 0;
  $u_pcfg = $u_pcfg;
  (*$p_proc).pmpcfg = $u_pcfg;
  $i0 = $p_proc;
  return $i0;
}

unsigned int Kernel_S3K_CAP_CNT = 32;

unsigned long long Kernel_MIN_BLOCK_SIZE = 12LL;

unsigned long long Kernel_MAX_BLOCK_SIZE = 27LL;

unsigned long long Kernel_vreg_read(struct Kernel_state *$p_ks, unsigned int $p_rid)
{
  register unsigned long long $i0;
  $i0 = *((*$p_ks).vregs + $p_rid);
  return $i0;
}

struct Kernel_state *Kernel_vreg_write(struct Kernel_state *$p_ks, unsigned int $p_rid, unsigned long long $p_v)
{
  register unsigned long long *$u_vregs;
  register struct Kernel_state *$i0;
  $u_vregs = (*$p_ks).vregs;
  *($u_vregs + $p_rid) = $p_v;
  $u_vregs = $u_vregs;
  (*$p_ks).vregs = $u_vregs;
  $i0 = $p_ks;
  return $i0;
}

struct Kernel_state *Sched_delete(struct Kernel_state *$p_ks, unsigned long long $p_from, unsigned long long $p_to)
{
  register unsigned long long $u_mask;
  $u_mask = 65535LL;
  return $p_ks;
}

struct Kernel_state *Sched_update(struct Kernel_state *$p_ks, unsigned long long $p_pid, unsigned long long $p_end, unsigned long long $p_from, unsigned long long $p_to)
{
  register unsigned long long $u_mask;
  $u_mask = 65535LL;
  return $p_ks;
}

_Bool Ctable_is_empty_cap(struct Kernel_state *$p_ks, unsigned int $p_cid)
{
  register unsigned long long $b1;
  register unsigned long long $b0;
  $b1 = *((*$p_ks).ctable + $p_cid);
  $b0 = Cap_get_type($b1);
  return $b0 == Cap_CAPTY_NONE;
}

struct Kernel_state *Ctable_set_cap(struct Kernel_state *$p_ks, unsigned int $p_cid, unsigned long long $p_cap)
{
  register unsigned long long *$u_ctable;
  register struct Kernel_state *$i0;
  $u_ctable = (*$p_ks).ctable;
  *($u_ctable + $p_cid) = $p_cap;
  $u_ctable = $u_ctable;
  (*$p_ks).ctable = $u_ctable;
  $i0 = $p_ks;
  return $i0;
}

struct Kernel_state *Ctable_set_next(struct Kernel_state *$p_ks, unsigned int $p_cid, unsigned int $p_nextid)
{
  register unsigned int *$u_cnext;
  register struct Kernel_state *$i0;
  $u_cnext = (*$p_ks).cnext;
  *($u_cnext + $p_cid) = $p_nextid;
  $u_cnext = $u_cnext;
  (*$p_ks).cnext = $u_cnext;
  $i0 = $p_ks;
  return $i0;
}

struct Kernel_state *Ctable_set_prev(struct Kernel_state *$p_ks, unsigned int $p_cid, unsigned int $p_previd)
{
  register unsigned int *$u_cprev;
  register struct Kernel_state *$i0;
  $u_cprev = (*$p_ks).cprev;
  *($u_cprev + $p_cid) = $p_previd;
  $u_cprev = $u_cprev;
  (*$p_ks).cprev = $u_cprev;
  $i0 = $p_ks;
  return $i0;
}

struct Kernel_state *Ctable_move(struct Kernel_state *$p_ks, unsigned int $p_src, unsigned int $p_dst)
{
  register unsigned long long $b0;
  register unsigned int $b1;
  register unsigned int $b2;
  register unsigned int $b3;
  register struct Kernel_state *$u_ks;
  register unsigned int $b4;
  register struct Kernel_state *$i0;
  if ($p_src == $p_dst) {
    return $p_ks;
  } else {
    $b0 = *((*$p_ks).ctable + $p_src);
    $u_ks = Ctable_set_cap($p_ks, $p_dst, $b0);
    $u_ks = Ctable_set_cap($u_ks, $p_src, 0LL);
    $b1 = *((*$u_ks).cprev + $p_src);
    $u_ks = Ctable_set_prev($u_ks, $p_dst, $b1);
    $b2 = *((*$u_ks).cnext + $p_src);
    $u_ks = Ctable_set_next($u_ks, $p_dst, $b2);
    $b3 = *((*$u_ks).cprev + $p_dst);
    $u_ks = Ctable_set_next($u_ks, $b3, $p_dst);
    $b4 = *((*$u_ks).cnext + $p_dst);
    $i0 = Ctable_set_prev($u_ks, $b4, $p_dst);
    return $i0;
  }
}

struct Kernel_state *Ctable_delete(struct Kernel_state *$p_ks, unsigned int $p_cid)
{
  register unsigned int $b0;
  register unsigned int $b1;
  register struct Kernel_state *$u_ks;
  register unsigned int $b2;
  register unsigned int $b3;
  register struct Kernel_state *$i0;
  $u_ks = Ctable_set_cap($p_ks, $p_cid, 0LL);
  $b0 = *((*$u_ks).cprev + $p_cid);
  $b1 = *((*$u_ks).cnext + $p_cid);
  $u_ks = Ctable_set_next($u_ks, $b0, $b1);
  $b2 = *((*$u_ks).cnext + $p_cid);
  $b3 = *((*$u_ks).cprev + $p_cid);
  $i0 = Ctable_set_prev($u_ks, $b2, $b3);
  return $i0;
}

struct Kernel_state *Ctable_insert(struct Kernel_state *$p_ks, unsigned int $p_cid, unsigned long long $p_cap, unsigned int $p_previd)
{
  register unsigned int $b0;
  register unsigned int $b1;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i0;
  $u_ks = Ctable_set_prev($p_ks, $p_cid, $p_previd);
  $b0 = *((*$u_ks).cnext + $p_previd);
  $u_ks = Ctable_set_next($u_ks, $p_cid, $b0);
  $u_ks = Ctable_set_next($u_ks, $p_previd, $p_cid);
  $b1 = *((*$u_ks).cnext + $p_cid);
  $u_ks = Ctable_set_prev($u_ks, $b1, $p_cid);
  $i0 = Ctable_set_cap($u_ks, $p_cid, $p_cap);
  return $i0;
}

struct Kernel_state *Ptable_acquire(struct Kernel_state *$p_ks, unsigned long long $p_time, unsigned int $p_pid)
{
  register unsigned long long $u_expected;
  register unsigned long long $u_desired;
  register struct Kernel_state *$i0;
  register unsigned long long $b1;
  register _Bool $b0;
  register struct Kernel_state *$i1;
  register struct Proc_proc_t *$u_proc;
  register struct Proc_proc_t **$u_ptable;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i2;
  $u_expected = (**((*$p_ks).ptable + $p_pid)).state;
  $u_desired = Proc_PSF_BUSY;
  if ((_Bool) ($u_expected & (Proc_PSF_BUSY | Proc_PSF_SUSPENDED))) {
    $i0 = Kernel_vreg_write($p_ks, 0, (unsigned long long) 0);
    return $i0;
  } else {
    $b1 = (**((*$p_ks).ptable + $p_pid)).timeout;
    $b0 = $p_time < $b1;
    if ($b0) {
      $i1 = Kernel_vreg_write($p_ks, 0, (unsigned long long) 0);
      return $i1;
    } else {
      $u_ptable = (*$p_ks).ptable;
      $u_proc = *($u_ptable + $p_pid);
      (*$u_proc).state = $u_desired;
      $u_proc = $u_proc;
      *($u_ptable + $p_pid) = $u_proc;
      $u_ptable = $u_ptable;
      (*$p_ks).ptable = $u_ptable;
      $u_ks = $p_ks;
      $i2 = Kernel_vreg_write($u_ks, 0, (unsigned long long) 1);
      return $i2;
    }
  }
}

struct Kernel_state *Ptable_suspend(struct Kernel_state *$p_ks, unsigned int $p_pid)
{
  register struct Proc_proc_t **$b1;
  register struct Proc_proc_t *$b0;
  register struct Proc_proc_t *$u_proc;
  register struct Proc_proc_t **$b2;
  register struct Proc_proc_t **$u_ptable;
  register struct Kernel_state *$i0;
  $b1 = (*$p_ks).ptable;
  $b0 = *($b1 + $p_pid);
  $u_proc = Proc_suspend($b0);
  $b2 = (*$p_ks).ptable;
  *($b2 + $p_pid) = $u_proc;
  $u_ptable = $b2;
  (*$p_ks).ptable = $u_ptable;
  $i0 = $p_ks;
  return $i0;
}

struct Kernel_state *Ptable_resume(struct Kernel_state *$p_ks, unsigned int $p_pid)
{
  register struct Proc_proc_t **$b1;
  register struct Proc_proc_t *$b0;
  register struct Proc_proc_t *$u_proc;
  register struct Proc_proc_t **$b2;
  register struct Proc_proc_t **$u_ptable;
  register struct Kernel_state *$i0;
  $b1 = (*$p_ks).ptable;
  $b0 = *($b1 + $p_pid);
  $u_proc = Proc_resume($b0);
  $b2 = (*$p_ks).ptable;
  *($b2 + $p_pid) = $u_proc;
  $u_ptable = $b2;
  (*$p_ks).ptable = $u_ptable;
  $i0 = $p_ks;
  return $i0;
}

struct Kernel_state *Ptable_release(struct Kernel_state *$p_ks, unsigned int $p_pid)
{
  register struct Proc_proc_t **$b1;
  register struct Proc_proc_t *$b0;
  register struct Proc_proc_t *$u_proc;
  register struct Proc_proc_t **$b2;
  register struct Proc_proc_t **$u_ptable;
  register struct Kernel_state *$i0;
  $b1 = (*$p_ks).ptable;
  $b0 = *($b1 + $p_pid);
  $u_proc = Proc_release($b0);
  $b2 = (*$p_ks).ptable;
  *($b2 + $p_pid) = $u_proc;
  $u_ptable = $b2;
  (*$p_ks).ptable = $u_ptable;
  $i0 = $p_ks;
  return $i0;
}

_Bool Ptable_is_suspended(struct Kernel_state *$p_ks, unsigned int $p_pid)
{
  register struct Proc_proc_t **$b1;
  register struct Proc_proc_t *$b0;
  register _Bool $i0;
  $b1 = (*$p_ks).ptable;
  $b0 = *($b1 + $p_pid);
  $i0 = Proc_is_suspended($b0);
  return $i0;
}

_Bool Ptable_pmp_avail(struct Kernel_state *$p_ks, unsigned int $p_pid, unsigned int $p_slot)
{
  register struct Proc_proc_t **$b1;
  register struct Proc_proc_t *$b0;
  register _Bool $i0;
  $b1 = (*$p_ks).ptable;
  $b0 = *($b1 + $p_pid);
  $i0 = Proc_pmp_avail($b0, $p_slot);
  return $i0;
}

struct Kernel_state *Ptable_pmp_load(struct Kernel_state *$p_ks, unsigned int $p_pid, unsigned int $p_slot, unsigned int $p_rwx, unsigned long long $p_addr)
{
  register struct Proc_proc_t **$b1;
  register struct Proc_proc_t *$b0;
  register struct Proc_proc_t *$u_proc;
  register struct Proc_proc_t **$b2;
  register struct Proc_proc_t **$u_ptable;
  register struct Kernel_state *$i0;
  $b1 = (*$p_ks).ptable;
  $b0 = *($b1 + $p_pid);
  $u_proc = Proc_pmp_load($b0, $p_slot, $p_rwx, $p_addr);
  $b2 = (*$p_ks).ptable;
  *($b2 + $p_pid) = $u_proc;
  $u_ptable = $b2;
  (*$p_ks).ptable = $u_ptable;
  $i0 = $p_ks;
  return $i0;
}

struct Kernel_state *Ptable_pmp_unload(struct Kernel_state *$p_ks, unsigned int $p_pid, unsigned int $p_slot)
{
  register struct Proc_proc_t **$b1;
  register struct Proc_proc_t *$b0;
  register struct Proc_proc_t *$u_proc;
  register struct Proc_proc_t **$b2;
  register struct Proc_proc_t **$u_ptable;
  register struct Kernel_state *$i0;
  $b1 = (*$p_ks).ptable;
  $b0 = *($b1 + $p_pid);
  $u_proc = Proc_pmp_unload($b0, $p_slot);
  $b2 = (*$p_ks).ptable;
  *($b2 + $p_pid) = $u_proc;
  $u_ptable = $b2;
  (*$p_ks).ptable = $u_ptable;
  $i0 = $p_ks;
  return $i0;
}

unsigned int Cap_ops_cap_pid(unsigned int $p_cid)
{
  return $p_cid / Kernel_S3K_CAP_CNT;
}

unsigned long long Cap_ops_pmp_napot_decode_base(unsigned long long $p_addr)
{
  return 0LL;
}

unsigned long long Cap_ops_pmp_napot_decode_size(unsigned long long $p_addr)
{
  return 0LL;
}

unsigned long long Cap_ops_tag_block_to_addr(unsigned long long $p_tag, unsigned long long $p_block)
{
  return ($p_tag << Kernel_MAX_BLOCK_SIZE)
           + ($p_block << Kernel_MIN_BLOCK_SIZE);
}

struct Kernel_state *Cap_ops_delete_memory(struct Kernel_state *$p_ks, unsigned int $p_cid)
{
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i0;
  $u_ks = Ctable_delete($p_ks, $p_cid);
  (*$u_ks).errcode = Error_SUCCESS;
  $i0 = $u_ks;
  return $i0;
}

struct Kernel_state *Cap_ops_revoke_memory(struct Kernel_state *$p_ks, unsigned int $p_parent)
{
  register unsigned int $u_child;
  register unsigned long long $u_ccap;
  register unsigned long long $b25;
  register _Bool $b24;
  register unsigned long long $b22;
  register unsigned long long $b23;
  register _Bool $b21;
  register unsigned long long $b19;
  register unsigned long long $b20;
  register _Bool $b18;
  register unsigned long long $b0;
  register _Bool $b1;
  register unsigned long long $b5;
  register unsigned long long $b6;
  register _Bool $b4;
  register _Bool $b3;
  register _Bool $b2;
  register struct Kernel_state *$i0;
  register struct Kernel_state *$i1;
  register unsigned long long $b7;
  register unsigned long long $u_base;
  register unsigned long long $b8;
  register unsigned long long $b9;
  register unsigned long long $u_pcap_tag_addr;
  register unsigned long long $b17;
  register _Bool $b16;
  register _Bool $b15;
  register _Bool $b13;
  register unsigned int $b10;
  register unsigned long long $b12;
  register unsigned int $b11;
  register struct Kernel_state *$i2;
  register unsigned long long $b14;
  register unsigned long long $u_pcap;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i3;
  $u_pcap = *((*$p_ks).ctable + $p_parent);
  $u_child = *((*$p_ks).cnext + $p_parent);
  $u_ccap = *((*$p_ks).ctable + $u_child);
  $b25 = Cap_get_type($u_ccap);
  $b24 = $b25 == Cap_CAPTY_MEMORY;
  if ($b24) {
    $b22 = Cap_memory_get_tag($u_pcap);
    $b23 = Cap_memory_get_tag($u_ccap);
    $b21 = $b22 == $b23;
  } else {
    $b21 = 0;
  }
  if ($b21) {
    $b19 = Cap_memory_get_bgn($u_pcap);
    $b20 = Cap_memory_get_bgn($u_ccap);
    $b18 = $b19 == $b20;
  } else {
    $b18 = 0;
  }
  if ($b18) {
    $u_ks = Ctable_delete($p_ks, $u_child);
    $b0 = Cap_memory_get_mrk($u_ccap);
    $u_pcap = Cap_memory_set_mrk($u_pcap, $b0);
    $b1 = Cap_memory_get_lck($u_ccap);
    $u_pcap = Cap_memory_set_lck($u_pcap, $b1);
    $u_ks = Ctable_set_cap($u_ks, $p_parent, $u_pcap);
    $b5 = Cap_memory_get_mrk($u_pcap);
    $b6 = Cap_memory_get_bgn($u_pcap);
    $b4 = $b5 == $b6;
    if ($b4) {
      $b3 = Cap_memory_get_lck($u_pcap);
      $b2 = !$b3;
    } else {
      $b2 = 0;
    }
    if ($b2) {
      (*$u_ks).errcode = Error_SUCCESS;
      $i0 = $u_ks;
      return $i0;
    } else {
      (*$u_ks).errcode = Error_CONTINUE;
      $i1 = $u_ks;
      return $i1;
    }
  } else {
    $b7 = Cap_pmp_get_addr($u_ccap);
    $u_base = Cap_ops_pmp_napot_decode_base($b7);
    $b8 = Cap_memory_get_tag($u_pcap);
    $b9 = Cap_memory_get_bgn($u_pcap);
    $u_pcap_tag_addr = Cap_ops_tag_block_to_addr($b8, $b9);
    $b17 = Cap_get_type($u_ccap);
    $b16 = $b17 == Cap_CAPTY_PMP;
    if ($b16) {
      $b15 = $u_pcap_tag_addr <= $u_base;
    } else {
      $b15 = 0;
    }
    if ($b15) {
      $u_ks = Ctable_delete($p_ks, $u_child);
      $b13 = Cap_pmp_get_used($u_ccap);
      if ($b13) {
        $b10 = Cap_ops_cap_pid($u_child);
        $b12 = Cap_pmp_get_slot($u_ccap);
        $b11 = (unsigned int) $b12;
        $u_ks = Ptable_pmp_unload($u_ks, $b10, $b11);
      } else {
        $u_ks = $u_ks;
      }
      (*$u_ks).errcode = Error_CONTINUE;
      $i2 = $u_ks;
      return $i2;
    } else {
      $b14 = Cap_memory_get_bgn($u_pcap);
      $u_pcap = Cap_memory_set_mrk($u_pcap, $b14);
      $u_pcap = Cap_memory_set_lck($u_pcap, 1);
      $u_ks = Ctable_set_cap($p_ks, $p_parent, $u_pcap);
      (*$u_ks).errcode = Error_SUCCESS;
      $i3 = $u_ks;
      return $i3;
    }
  }
}

struct Kernel_state *Cap_ops_derive_memory(struct Kernel_state *$p_ks, unsigned int $p_src, unsigned int $p_dst, unsigned long long $p_ncap)
{
  register unsigned long long $b35;
  register _Bool $b34;
  register unsigned long long $b32;
  register unsigned long long $b33;
  register _Bool $b31;
  register unsigned long long $b29;
  register unsigned long long $b30;
  register _Bool $b28;
  register unsigned long long $b26;
  register unsigned long long $b27;
  register _Bool $b25;
  register unsigned long long $b23;
  register unsigned long long $b24;
  register _Bool $b22;
  register unsigned long long $b19;
  register unsigned long long $b20;
  register unsigned long long $b18;
  register unsigned long long $b21;
  register _Bool $b17;
  register _Bool $b16;
  register _Bool $b15;
  register unsigned long long $b0;
  register struct Kernel_state *$i0;
  register unsigned long long $b1;
  register unsigned long long $u_pmp_begin;
  register unsigned long long $b2;
  register unsigned long long $u_pmp_size;
  register unsigned long long $u_pmp_end;
  register unsigned long long $b3;
  register unsigned long long $b4;
  register unsigned long long $u_mem_mrk;
  register unsigned long long $b5;
  register unsigned long long $b6;
  register unsigned long long $u_mem_end;
  register unsigned long long $b14;
  register _Bool $b13;
  register _Bool $b12;
  register unsigned long long $b9;
  register unsigned long long $b10;
  register unsigned long long $b8;
  register unsigned long long $b11;
  register _Bool $b7;
  register unsigned long long $u_cap;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i1;
  register struct Kernel_state *$i2;
  $u_cap = *((*$p_ks).ctable + $p_src);
  $b35 = Cap_get_type($p_ncap);
  $b34 = $b35 == Cap_CAPTY_MEMORY;
  if ($b34) {
    $b32 = Cap_memory_get_tag($u_cap);
    $b33 = Cap_memory_get_tag($p_ncap);
    $b31 = $b32 == $b33;
  } else {
    $b31 = 0;
  }
  if ($b31) {
    $b29 = Cap_memory_get_tag($u_cap);
    $b30 = Cap_memory_get_tag($p_ncap);
    $b28 = $b29 == $b30;
  } else {
    $b28 = 0;
  }
  if ($b28) {
    $b26 = Cap_memory_get_mrk($u_cap);
    $b27 = Cap_memory_get_bgn($p_ncap);
    $b25 = $b26 <= $b27;
  } else {
    $b25 = 0;
  }
  if ($b25) {
    $b23 = Cap_memory_get_end($p_ncap);
    $b24 = Cap_memory_get_end($u_cap);
    $b22 = $b23 <= $b24;
  } else {
    $b22 = 0;
  }
  if ($b22) {
    $b19 = Cap_memory_get_rwx($p_ncap);
    $b20 = Cap_memory_get_rwx($u_cap);
    $b18 = $b19 & $b20;
    $b21 = Cap_memory_get_rwx($p_ncap);
    $b17 = $b18 == $b21;
  } else {
    $b17 = 0;
  }
  if ($b17) {
    $b16 = Cap_memory_get_lck($u_cap);
    $b15 = !$b16;
  } else {
    $b15 = 0;
  }
  if ($b15) {
    $b0 = Cap_memory_get_end($p_ncap);
    $u_cap = Cap_memory_set_mrk($u_cap, $b0);
    $u_ks = Ctable_set_cap($p_ks, $p_src, $u_cap);
    $u_ks = Ctable_insert($u_ks, $p_dst, $u_cap, $p_src);
    (*$u_ks).errcode = Error_SUCCESS;
    $i0 = $u_ks;
    return $i0;
  } else {
    $b1 = Cap_pmp_get_addr($p_ncap);
    $u_pmp_begin = Cap_ops_pmp_napot_decode_base($b1);
    $b2 = Cap_pmp_get_addr($p_ncap);
    $u_pmp_size = Cap_ops_pmp_napot_decode_size($b2);
    $u_pmp_end = $u_pmp_begin + $u_pmp_size;
    $b3 = Cap_memory_get_tag($u_cap);
    $b4 = Cap_memory_get_mrk($u_cap);
    $u_mem_mrk = Cap_ops_tag_block_to_addr($b3, $b4);
    $b5 = Cap_memory_get_tag($u_cap);
    $b6 = Cap_memory_get_end($u_cap);
    $u_mem_end = Cap_ops_tag_block_to_addr($b5, $b6);
    $b14 = Cap_get_type($p_ncap);
    $b13 = $b14 == Cap_CAPTY_PMP;
    if ($b13) {
      $b12 = $u_mem_mrk <= $u_pmp_begin;
    } else {
      $b12 = 0;
    }
    if ($b12) {
      $b9 = Cap_memory_get_rwx($p_ncap);
      $b10 = Cap_memory_get_rwx($u_cap);
      $b8 = $b9 & $b10;
      $b11 = Cap_memory_get_rwx($p_ncap);
      $b7 = $b8 == $b11;
    } else {
      $b7 = 0;
    }
    if ($b7) {
      $u_cap = Cap_memory_set_lck($u_cap, 1);
      $u_ks = Ctable_set_cap($p_ks, $p_src, $u_cap);
      $u_ks = Ctable_insert($u_ks, $p_dst, $p_ncap, $p_src);
      (*$u_ks).errcode = Error_SUCCESS;
      $i1 = $u_ks;
      return $i1;
    } else {
      (*$p_ks).errcode = Error_ERR_INVALID_DERIVATION;
      $i2 = $p_ks;
      return $i2;
    }
  }
}

struct Kernel_state *Cap_ops_delete_pmp(struct Kernel_state *$p_ks, unsigned int $p_cid)
{
  register unsigned long long $u_cap;
  register _Bool $b3;
  register unsigned int $b0;
  register unsigned long long $b2;
  register unsigned int $b1;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i0;
  $u_cap = *((*$p_ks).ctable + $p_cid);
  $b3 = Cap_pmp_get_used($u_cap);
  if ($b3) {
    $b0 = Cap_ops_cap_pid($p_cid);
    $b2 = Cap_pmp_get_slot($u_cap);
    $b1 = (unsigned int) $b2;
    $u_ks = Ptable_pmp_unload($p_ks, $b0, $b1);
  } else {
    $u_ks = $p_ks;
  }
  $u_ks = Ctable_delete($u_ks, $p_cid);
  (*$u_ks).errcode = Error_SUCCESS;
  $i0 = $u_ks;
  return $i0;
}

struct Kernel_state *Cap_ops_revoke_pmp(struct Kernel_state *$p_ks)
{
  register struct Kernel_state *$i0;
  (*$p_ks).errcode = Error_SUCCESS;
  $i0 = $p_ks;
  return $i0;
}

struct Kernel_state *Cap_ops_derive_pmp(struct Kernel_state *$p_ks, unsigned int $p_src, unsigned int $p_dst, unsigned long long $p_ncap)
{
  register struct Kernel_state *$i0;
  (*$p_ks).errcode = Error_ERR_INVALID_DERIVATION;
  $i0 = $p_ks;
  return $i0;
}

struct Kernel_state *Cap_ops_delete_time(struct Kernel_state *$p_ks, unsigned int $p_cid)
{
  register unsigned long long $u_cap;
  register unsigned long long $b0;
  register unsigned long long $b1;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i0;
  $u_cap = *((*$p_ks).ctable + $p_cid);
  $b0 = Cap_time_get_mrk($u_cap);
  $b1 = Cap_time_get_end($u_cap);
  $u_ks = Sched_delete($p_ks, $b0, $b1);
  $u_ks = Ctable_delete($u_ks, $p_cid);
  (*$u_ks).errcode = Error_SUCCESS;
  $i0 = $u_ks;
  return $i0;
}

struct Kernel_state *Cap_ops_revoke_time(struct Kernel_state *$p_ks, unsigned int $p_parent)
{
  register unsigned int $u_child;
  register unsigned long long $u_ccap;
  register unsigned long long $b12;
  register _Bool $b11;
  register unsigned long long $b9;
  register unsigned long long $b10;
  register _Bool $b8;
  register unsigned long long $b6;
  register unsigned long long $b7;
  register _Bool $b5;
  register unsigned long long $b0;
  register unsigned long long $b2;
  register unsigned long long $b3;
  register _Bool $b1;
  register struct Kernel_state *$i0;
  register struct Kernel_state *$i1;
  register unsigned int $u_pid;
  register unsigned long long $u_end;
  register unsigned long long $u_from;
  register unsigned long long $u_to;
  register unsigned long long $b4;
  register unsigned long long $u_pcap;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i2;
  $u_pcap = *((*$p_ks).ctable + $p_parent);
  $u_child = *((*$p_ks).cnext + $p_parent);
  $u_ccap = *((*$p_ks).ctable + $u_child);
  $b12 = Cap_get_type($u_ccap);
  $b11 = $b12 == Cap_CAPTY_TIME;
  if ($b11) {
    $b9 = Cap_time_get_bgn($u_pcap);
    $b10 = Cap_time_get_bgn($u_ccap);
    $b8 = $b9 <= $b10;
  } else {
    $b8 = 0;
  }
  if ($b8) {
    $b6 = Cap_time_get_end($u_ccap);
    $b7 = Cap_time_get_end($u_pcap);
    $b5 = $b6 <= $b7;
  } else {
    $b5 = 0;
  }
  if ($b5) {
    $u_ks = Ctable_delete($p_ks, $u_child);
    $u_pid = Cap_ops_cap_pid($p_parent);
    $u_end = Cap_time_get_end($u_pcap);
    $u_from = Cap_time_get_mrk($u_ccap);
    $u_to = Cap_time_get_mrk($u_pcap);
    $u_ks =
      Sched_update
      ($u_ks, (unsigned long long) $u_pid, $u_end, $u_from, $u_to);
    $b0 = Cap_time_get_mrk($u_ccap);
    $u_pcap = Cap_time_set_mrk($u_pcap, $b0);
    $u_ks = Ctable_set_cap($u_ks, $p_parent, $u_pcap);
    $b2 = Cap_time_get_mrk($u_pcap);
    $b3 = Cap_time_get_bgn($u_pcap);
    $b1 = $b2 == $b3;
    if ($b1) {
      (*$u_ks).errcode = Error_SUCCESS;
      $i0 = $u_ks;
      return $i0;
    } else {
      (*$u_ks).errcode = Error_CONTINUE;
      $i1 = $u_ks;
      return $i1;
    }
  } else {
    $u_pid = Cap_ops_cap_pid($p_parent);
    $u_end = Cap_time_get_end($u_pcap);
    $u_from = Cap_time_get_bgn($u_pcap);
    $u_to = Cap_time_get_mrk($u_pcap);
    $u_ks =
      Sched_update
      ($p_ks, (unsigned long long) $u_pid, $u_end, $u_from, $u_to);
    $b4 = Cap_time_get_bgn($u_pcap);
    $u_pcap = Cap_time_set_mrk($u_pcap, $b4);
    $u_ks = Ctable_set_cap($u_ks, $p_parent, $u_pcap);
    (*$u_ks).errcode = Error_SUCCESS;
    $i2 = $u_ks;
    return $i2;
  }
}

struct Kernel_state *Cap_ops_derive_time(struct Kernel_state *$p_ks, unsigned int $p_src, unsigned int $p_dst, unsigned long long $p_ncap)
{
  register unsigned long long $b13;
  register _Bool $b12;
  register unsigned long long $b10;
  register unsigned long long $b11;
  register _Bool $b9;
  register unsigned long long $b7;
  register unsigned long long $b8;
  register _Bool $b6;
  register unsigned int $b1;
  register unsigned long long $b0;
  register unsigned long long $b2;
  register unsigned long long $b3;
  register unsigned long long $b4;
  register unsigned long long $b5;
  register unsigned long long $u_cap;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i0;
  register struct Kernel_state *$i1;
  $u_cap = *((*$p_ks).ctable + $p_src);
  $b13 = Cap_get_type($p_ncap);
  $b12 = $b13 == Cap_CAPTY_TIME;
  if ($b12) {
    $b10 = Cap_time_get_bgn($p_ncap);
    $b11 = Cap_time_get_mrk($u_cap);
    $b9 = $b10 <= $b11;
  } else {
    $b9 = 0;
  }
  if ($b9) {
    $b7 = Cap_time_get_end($p_ncap);
    $b8 = Cap_time_get_end($u_cap);
    $b6 = $b7 <= $b8;
  } else {
    $b6 = 0;
  }
  if ($b6) {
    $b1 = Cap_ops_cap_pid($p_dst);
    $b0 = (unsigned long long) $b1;
    $b2 = Cap_time_get_end($p_ncap);
    $b3 = Cap_time_get_bgn($p_ncap);
    $b4 = Cap_time_get_end($p_ncap);
    $u_ks = Sched_update($p_ks, $b0, $b2, $b3, $b4);
    $b5 = Cap_time_get_end($p_ncap);
    $u_cap = Cap_time_set_mrk($u_cap, $b5);
    $u_ks = Ctable_set_cap($u_ks, $p_src, $u_cap);
    $u_ks = Ctable_insert($u_ks, $p_dst, $p_ncap, $p_src);
    (*$u_ks).errcode = Error_SUCCESS;
    $i0 = $u_ks;
    return $i0;
  } else {
    (*$p_ks).errcode = Error_ERR_INVALID_DERIVATION;
    $i1 = $p_ks;
    return $i1;
  }
}

struct Kernel_state *Cap_ops_delete_monitor(struct Kernel_state *$p_ks, unsigned int $p_cid)
{
  register struct Kernel_state *$i0;
  $i0 = Ctable_delete($p_ks, $p_cid);
  return $i0;
}

struct Kernel_state *Cap_ops_revoke_monitor(struct Kernel_state *$p_ks, unsigned int $p_parent)
{
  register unsigned int $u_child;
  register unsigned long long $u_ccap;
  register unsigned long long $b9;
  register _Bool $b8;
  register unsigned long long $b6;
  register unsigned long long $b7;
  register _Bool $b5;
  register unsigned long long $b0;
  register unsigned long long $b2;
  register unsigned long long $b3;
  register _Bool $b1;
  register struct Kernel_state *$i0;
  register struct Kernel_state *$i1;
  register unsigned long long $b4;
  register unsigned long long $u_pcap;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i2;
  $u_pcap = *((*$p_ks).ctable + $p_parent);
  $u_child = *((*$p_ks).cnext + $p_parent);
  $u_ccap = *((*$p_ks).ctable + $u_child);
  $b9 = Cap_get_type($u_ccap);
  $b8 = $b9 == Cap_CAPTY_MONITOR;
  if ($b8) {
    $b6 = Cap_monitor_get_bgn($u_pcap);
    $b7 = Cap_monitor_get_bgn($u_pcap);
    $b5 = $b6 <= $b7;
  } else {
    $b5 = 0;
  }
  if ($b5) {
    $u_ks = Ctable_delete($p_ks, $u_child);
    $b0 = Cap_monitor_get_mrk($u_ccap);
    $u_pcap = Cap_monitor_set_mrk($u_pcap, $b0);
    $u_ks = Ctable_set_cap($u_ks, $p_parent, $u_pcap);
    $b2 = Cap_monitor_get_mrk($u_pcap);
    $b3 = Cap_monitor_get_bgn($u_pcap);
    $b1 = $b2 == $b3;
    if ($b1) {
      (*$u_ks).errcode = Error_SUCCESS;
      $i0 = $u_ks;
      return $i0;
    } else {
      (*$u_ks).errcode = Error_CONTINUE;
      $i1 = $u_ks;
      return $i1;
    }
  } else {
    $b4 = Cap_monitor_get_bgn($u_pcap);
    $u_pcap = Cap_monitor_set_mrk($u_pcap, $b4);
    $u_ks = Ctable_set_cap($p_ks, $p_parent, $u_pcap);
    (*$u_ks).errcode = Error_SUCCESS;
    $i2 = $u_ks;
    return $i2;
  }
}

struct Kernel_state *Cap_ops_cap_derive_monitor(struct Kernel_state *$p_ks, unsigned int $p_src, unsigned int $p_dst, unsigned long long $p_ncap)
{
  register unsigned long long $b8;
  register _Bool $b7;
  register unsigned long long $b5;
  register unsigned long long $b6;
  register _Bool $b4;
  register unsigned long long $b2;
  register unsigned long long $b3;
  register _Bool $b1;
  register unsigned long long $b0;
  register unsigned long long $u_cap;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i0;
  register struct Kernel_state *$i1;
  $u_cap = *((*$p_ks).ctable + $p_src);
  $b8 = Cap_get_type($p_ncap);
  $b7 = $b8 == Cap_CAPTY_MONITOR;
  if ($b7) {
    $b5 = Cap_monitor_get_mrk($u_cap);
    $b6 = Cap_monitor_get_bgn($p_ncap);
    $b4 = $b5 <= $b6;
  } else {
    $b4 = 0;
  }
  if ($b4) {
    $b2 = Cap_monitor_get_mrk($u_cap);
    $b3 = Cap_monitor_get_end($u_cap);
    $b1 = $b2 <= $b3;
  } else {
    $b1 = 0;
  }
  if ($b1) {
    $b0 = Cap_monitor_get_end($u_cap);
    $u_cap = Cap_monitor_set_mrk($u_cap, $b0);
    $u_ks = Ctable_set_cap($p_ks, $p_src, $u_cap);
    $u_ks = Ctable_insert($u_ks, $p_dst, $p_ncap, $p_src);
    (*$u_ks).errcode = Error_SUCCESS;
    $i0 = $u_ks;
    return $i0;
  } else {
    (*$p_ks).errcode = Error_ERR_INVALID_DERIVATION;
    $i1 = $p_ks;
    return $i1;
  }
}

struct Kernel_state *Cap_ops_read(struct Kernel_state *$p_ks, unsigned int $p_cid)
{
  register unsigned long long $u_cap;
  register unsigned long long $b1;
  register _Bool $b0;
  register struct Kernel_state *$i0;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i1;
  $u_cap = *((*$p_ks).ctable + $p_cid);
  $b1 = Cap_get_type($u_cap);
  $b0 = $b1 == Cap_CAPTY_NONE;
  if ($b0) {
    (*$p_ks).errcode = Error_ERR_EMPTY;
    $i0 = $p_ks;
    return $i0;
  } else {
    $u_ks = Kernel_vreg_write($p_ks, 0, $u_cap);
    (*$u_ks).errcode = Error_SUCCESS;
    $i1 = $u_ks;
    return $i1;
  }
}

struct Kernel_state *Cap_ops_move(struct Kernel_state *$p_ks, unsigned int $p_src, unsigned int $p_dst)
{
  register _Bool $b2;
  register struct Kernel_state *$i0;
  register _Bool $b1;
  register _Bool $b0;
  register struct Kernel_state *$i1;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i2;
  $b2 = Ctable_is_empty_cap($p_ks, $p_src);
  if ($b2) {
    (*$p_ks).errcode = Error_ERR_SRC_EMPTY;
    $i0 = $p_ks;
    return $i0;
  } else {
    $b1 = Ctable_is_empty_cap($p_ks, $p_dst);
    $b0 = !$b1;
    if ($b0) {
      (*$p_ks).errcode = Error_ERR_DST_OCCUPIED;
      $i1 = $p_ks;
      return $i1;
    } else {
      $u_ks = Ctable_move($p_ks, $p_src, $p_dst);
      (*$u_ks).errcode = Error_SUCCESS;
      $i2 = $u_ks;
      return $i2;
    }
  }
}

struct Kernel_state *Cap_ops_delete(struct Kernel_state *$p_ks, unsigned int $p_cid)
{
  register _Bool $b1;
  register struct Kernel_state *$i0;
  register unsigned long long $b0;
  register unsigned long long $u_cap_type;
  register struct Kernel_state *$i1;
  register struct Kernel_state *$i2;
  register struct Kernel_state *$i3;
  register struct Kernel_state *$i4;
  $b1 = Ctable_is_empty_cap($p_ks, $p_cid);
  if ($b1) {
    (*$p_ks).errcode = Error_ERR_EMPTY;
    $i0 = $p_ks;
    return $i0;
  } else {
    $b0 = *((*$p_ks).ctable + $p_cid);
    $u_cap_type = Cap_get_type($b0);
    if ($u_cap_type == Cap_CAPTY_MEMORY) {
      $i1 = Cap_ops_delete_memory($p_ks, $p_cid);
      return $i1;
    } else {
      if ($u_cap_type == Cap_CAPTY_PMP) {
        $i2 = Cap_ops_delete_pmp($p_ks, $p_cid);
        return $i2;
      } else {
        if ($u_cap_type == Cap_CAPTY_TIME) {
          $i3 = Cap_ops_delete_time($p_ks, $p_cid);
          return $i3;
        } else {
          (*$p_ks).errcode = Error_ERR_INVALID_CAPABILITY;
          $i4 = $p_ks;
          return $i4;
        }
      }
    }
  }
}

struct Kernel_state *Cap_ops_derive(struct Kernel_state *$p_ks, unsigned int $p_src, unsigned int $p_dst, unsigned long long $p_ncap)
{
  register _Bool $b3;
  register struct Kernel_state *$i0;
  register _Bool $b2;
  register _Bool $b1;
  register struct Kernel_state *$i1;
  register unsigned long long $b0;
  register unsigned long long $u_cap_type;
  register struct Kernel_state *$i2;
  register struct Kernel_state *$i3;
  register struct Kernel_state *$i4;
  register struct Kernel_state *$i5;
  $b3 = Ctable_is_empty_cap($p_ks, $p_src);
  if ($b3) {
    (*$p_ks).errcode = Error_ERR_SRC_EMPTY;
    $i0 = $p_ks;
    return $i0;
  } else {
    $b2 = Ctable_is_empty_cap($p_ks, $p_dst);
    $b1 = !$b2;
    if ($b1) {
      (*$p_ks).errcode = Error_ERR_DST_OCCUPIED;
      $i1 = $p_ks;
      return $i1;
    } else {
      $b0 = *((*$p_ks).ctable + $p_src);
      $u_cap_type = Cap_get_type($b0);
      if ($u_cap_type == Cap_CAPTY_MEMORY) {
        $i2 = Cap_ops_derive_memory($p_ks, $p_src, $p_dst, $p_ncap);
        return $i2;
      } else {
        if ($u_cap_type == Cap_CAPTY_PMP) {
          $i3 = Cap_ops_derive_pmp($p_ks, $p_src, $p_dst, $p_ncap);
          return $i3;
        } else {
          if ($u_cap_type == Cap_CAPTY_TIME) {
            $i4 = Cap_ops_derive_time($p_ks, $p_src, $p_dst, $p_ncap);
            return $i4;
          } else {
            (*$p_ks).errcode = Error_ERR_INVALID_CAPABILITY;
            $i5 = $p_ks;
            return $i5;
          }
        }
      }
    }
  }
}

struct Kernel_state *Pmp_load(struct Kernel_state *$p_ks, unsigned int $p_cid, unsigned int $p_slot)
{
  register unsigned int $u_pid;
  register unsigned long long $u_cap_type;
  register struct Kernel_state *$i0;
  register _Bool $b5;
  register struct Kernel_state *$i1;
  register _Bool $b4;
  register _Bool $b3;
  register struct Kernel_state *$i2;
  register unsigned long long $b1;
  register unsigned int $b0;
  register unsigned long long $b2;
  register unsigned long long $u_cap;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i3;
  $u_pid = Cap_ops_cap_pid($p_cid);
  $u_cap = *((*$p_ks).ctable + $p_cid);
  $u_cap_type = Cap_get_type($u_cap);
  if ($u_cap_type == Cap_CAPTY_NONE) {
    (*$p_ks).errcode = Error_ERR_EMPTY;
    $i0 = $p_ks;
    return $i0;
  } else {
    if ($u_cap_type != Cap_CAPTY_PMP) {
      $b5 = 1;
    } else {
      $b5 = Cap_pmp_get_used($u_cap);
    }
    if ($b5) {
      (*$p_ks).errcode = Error_ERR_INVALID_PMP;
      $i1 = $p_ks;
      return $i1;
    } else {
      $b4 = Ptable_pmp_avail($p_ks, $u_pid, $p_slot);
      $b3 = !$b4;
      if ($b3) {
        (*$p_ks).errcode = Error_ERR_DST_OCCUPIED;
        $i2 = $p_ks;
        return $i2;
      } else {
        $b1 = Cap_pmp_get_rwx($u_cap);
        $b0 = (unsigned int) $b1;
        $b2 = Cap_pmp_get_addr($u_cap);
        $u_ks = Ptable_pmp_load($p_ks, $u_pid, $p_slot, $b0, $b2);
        $u_cap = Cap_pmp_set_slot($u_cap, (unsigned long long) $p_slot);
        $u_cap = Cap_pmp_set_used($u_cap, 1);
        $u_ks = Ctable_set_cap($u_ks, $p_cid, $u_cap);
        (*$u_ks).errcode = Error_SUCCESS;
        $i3 = $u_ks;
        return $i3;
      }
    }
  }
}

struct Kernel_state *Pmp_unload(struct Kernel_state *$p_ks, unsigned int $p_cid)
{
  register unsigned int $u_pid;
  register unsigned long long $u_cap_type;
  register struct Kernel_state *$i0;
  register _Bool $b3;
  register _Bool $b2;
  register struct Kernel_state *$i1;
  register unsigned long long $b1;
  register unsigned int $b0;
  register unsigned long long $u_cap;
  register struct Kernel_state *$u_ks;
  register struct Kernel_state *$i2;
  $u_pid = Cap_ops_cap_pid($p_cid);
  $u_cap = *((*$p_ks).ctable + $p_cid);
  $u_cap_type = Cap_get_type($u_cap);
  if ($u_cap_type == Cap_CAPTY_NONE) {
    (*$p_ks).errcode = Error_ERR_EMPTY;
    $i0 = $p_ks;
    return $i0;
  } else {
    if ($u_cap_type != Cap_CAPTY_PMP) {
      $b2 = 1;
    } else {
      $b3 = Cap_pmp_get_used($u_cap);
      $b2 = !$b3;
    }
    if ($b2) {
      (*$p_ks).errcode = Error_ERR_INVALID_PMP;
      $i1 = $p_ks;
      return $i1;
    } else {
      $b1 = Cap_pmp_get_slot($u_cap);
      $b0 = (unsigned int) $b1;
      $u_ks = Ptable_pmp_unload($p_ks, $u_pid, $b0);
      $u_cap = Cap_pmp_set_slot($u_cap, 0LL);
      $u_cap = Cap_pmp_set_used($u_cap, 1);
      $u_ks = Ctable_set_cap($u_ks, $u_pid, $u_cap);
      (*$u_ks).errcode = Error_SUCCESS;
      $i2 = $u_ks;
      return $i2;
    }
  }
}

long long Monitor_check(struct Kernel_state *$p_ks, unsigned int $p_mon, unsigned int $p_pid, _Bool $p_check_suspended)
{
  register unsigned long long $u_mcap;
  register unsigned long long $u_mcap_type;
  register unsigned long long $b5;
  register _Bool $b4;
  register unsigned long long $b3;
  register _Bool $b2;
  register _Bool $b1;
  register _Bool $b0;
  $u_mcap = *((*$p_ks).ctable + $p_mon);
  $u_mcap_type = Cap_get_type($u_mcap);
  if ($u_mcap_type != Cap_CAPTY_MONITOR) {
    $b4 = 1;
  } else {
    $b5 = Cap_monitor_get_mrk($u_mcap);
    $b4 = $b5 > (unsigned long long) $p_pid;
  }
  if ($b4) {
    $b2 = 1;
  } else {
    $b3 = Cap_monitor_get_end($u_mcap);
    $b2 = (unsigned long long) $p_pid >= $b3;
  }
  if ($b2) {
    return Error_ERR_INVALID_MONITOR;
  } else {
    if ($p_check_suspended) {
      $b1 = Ptable_is_suspended($p_ks, (unsigned int) $p_pid);
      $b0 = !$b1;
    } else {
      $b0 = 0;
    }
    if ($b0) {
      return Error_ERR_INVALID_STATE;
    } else {
      return Error_SUCCESS;
    }
  }
}

long long Monitor_check_move(struct Kernel_state *$p_ks, unsigned int $p_mon, unsigned int $p_src, unsigned int $p_dst)
{
  register unsigned int $u_mon_pid;
  register unsigned int $u_src_pid;
  register unsigned int $u_dst_pid;
  register long long $u_err;
  register long long $i0;
  $u_mon_pid = Cap_ops_cap_pid($p_mon);
  $u_src_pid = Cap_ops_cap_pid($p_src);
  $u_dst_pid = Cap_ops_cap_pid($p_dst);
  if ($u_mon_pid != $u_src_pid) {
    $u_err = Monitor_check($p_ks, $p_mon, $u_src_pid, 1);
  } else {
    $u_err = Error_SUCCESS;
  }
  if ($u_err == Error_SUCCESS) {
    if ($u_mon_pid != $u_dst_pid) {
      $i0 = Monitor_check($p_ks, $p_mon, $u_src_pid, 1);
      return $i0;
    } else {
      return Error_SUCCESS;
    }
  } else {
    return $u_err;
  }
}

struct Kernel_state *Monitor_cap_resume(struct Kernel_state *$p_ks, unsigned int $p_mon, unsigned int $p_pid)
{
  register long long $u_err;
  register struct Kernel_state *$i0;
  register struct Kernel_state *$i1;
  $u_err = Monitor_check($p_ks, $p_mon, $p_pid, 0);
  if ($u_err == Error_SUCCESS) {
    $i0 = Ptable_resume($p_ks, $p_pid);
    return $i0;
  } else {
    (*$p_ks).errcode = $u_err;
    $i1 = $p_ks;
    return $i1;
  }
}



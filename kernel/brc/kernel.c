struct kernel_state;
struct kernel_state {
  unsigned int *cnext;
  unsigned int *cprev;
  unsigned long long *ctable;
  unsigned long long *vregs;
  int errcode;
};

unsigned long long u_vreg_read(struct kernel_state *, unsigned int);
struct kernel_state *u_vreg_write(struct kernel_state *, unsigned int, unsigned long long);
unsigned long long u_cap_get_type(unsigned long long);
unsigned long long u_cap_set_type(unsigned long long, unsigned long long);
unsigned long long u_cap_mem_get_rwx(unsigned long long);
_Bool u_cap_mem_get_lck(unsigned long long);
unsigned long long u_cap_mem_get_tag(unsigned long long);
unsigned long long u_cap_mem_get_bgn(unsigned long long);
unsigned long long u_cap_mem_get_mrk(unsigned long long);
unsigned long long u_cap_mem_get_end(unsigned long long);
unsigned long long u_cap_mem_set_rwx(unsigned long long, unsigned long long);
unsigned long long u_cap_mem_set_lck(unsigned long long, _Bool);
unsigned long long u_cap_mem_set_tag(unsigned long long, unsigned long long);
unsigned long long u_cap_mem_set_bgn(unsigned long long, unsigned long long);
unsigned long long u_cap_mem_set_mrk(unsigned long long, unsigned long long);
unsigned long long u_cap_mem_set_end(unsigned long long, unsigned long long);
unsigned long long u_cap_pmp_get_rwx(unsigned long long);
_Bool u_cap_pmp_get_used(unsigned long long);
unsigned long long u_cap_pmp_get_slot(unsigned long long);
unsigned long long u_cap_pmp_get_addr(unsigned long long);
unsigned long long u_cap_pmp_set_rwx(unsigned long long, unsigned long long);
unsigned long long u_cap_pmp_set_used(unsigned long long, _Bool);
unsigned long long u_cap_pmp_set_slot(unsigned long long, unsigned long long);
unsigned long long u_cap_pmp_set_addr(unsigned long long, unsigned long long);
_Bool u_ctable_is_empty_cap(struct kernel_state *, unsigned int);
struct kernel_state *u_ctable_set_cap(struct kernel_state *, unsigned int, unsigned long long);
struct kernel_state *u_ctable_set_next(struct kernel_state *, unsigned int, unsigned int);
struct kernel_state *u_ctable_set_prev(struct kernel_state *, unsigned int, unsigned int);
struct kernel_state *u_ctable_move_cap(struct kernel_state *, unsigned int, unsigned int);
struct kernel_state *u_ctable_delete_cap(struct kernel_state *, unsigned int);
struct kernel_state *u_ctable_insert_cap(struct kernel_state *, unsigned int, unsigned long long, unsigned int);
unsigned long long u_cap_pid(unsigned int);
unsigned long long u_pmp_napot_decode_base(unsigned long long);
unsigned long long u_pmp_napot_decode_size(unsigned long long);
unsigned long long u_tag_block_to_addr(unsigned long long, unsigned long long);
struct kernel_state *u_cap_delete_memory(struct kernel_state *, unsigned int);
struct kernel_state *u_cap_revoke_memory(struct kernel_state *, unsigned int);
struct kernel_state *u_cap_derive_memory(struct kernel_state *, unsigned int, unsigned int, unsigned long long);
struct kernel_state *u_cap_delete_pmp(struct kernel_state *, unsigned int);
struct kernel_state *u_cap_revoke_pmp(struct kernel_state *);
struct kernel_state *u_cap_derive_pmp(struct kernel_state *, unsigned int, unsigned int, unsigned long long);
struct kernel_state *u_cap_read(struct kernel_state *, unsigned int);
struct kernel_state *u_cap_move(struct kernel_state *, unsigned int, unsigned int);
struct kernel_state *u_cap_delete(struct kernel_state *, unsigned int);
struct kernel_state *u_cap_derive(struct kernel_state *, unsigned int, unsigned int, unsigned long long);
unsigned int u_S3K_CAP_CNT = 32;

int u_SUCCESS = 0;

int u_ERR_EMPTY = 1;

int u_ERR_SRC_EMPTY = 2;

int u_ERR_DST_OCCUPIED = 3;

int u_ERR_INVALID_DERIVATION = 5;

int u_ERR_INVALID_CAPABILITY = 14;

int u_CONTINUE = -1;

unsigned long long u_CAPTY_NONE = 0LL;

unsigned long long u_CAPTY_MEMORY = 2LL;

unsigned long long u_CAPTY_PMP = 3LL;

unsigned long long u_MIN_BLOCK_SIZE = 12LL;

unsigned long long u_MAX_BLOCK_SIZE = 27LL;

unsigned long long u_vreg_read(struct kernel_state *$p_ks, unsigned int $p_rid)
{
  register unsigned long long $i0;
  $i0 = *((*$p_ks).vregs + $p_rid);
  return $i0;
}

struct kernel_state *u_vreg_write(struct kernel_state *$p_ks, unsigned int $p_rid, unsigned long long $p_v)
{
  register unsigned long long *$u_vregs;
  register struct kernel_state *$i0;
  $u_vregs = (*$p_ks).vregs;
  *($u_vregs + $p_rid) = $p_v;
  $u_vregs = $u_vregs;
  (*$p_ks).vregs = $u_vregs;
  $i0 = $p_ks;
  return $i0;
}

unsigned long long u_cap_get_type(unsigned long long $p_cap)
{
  return $p_cap;
}

unsigned long long u_cap_set_type(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap;
}

unsigned long long u_cap_mem_get_rwx(unsigned long long $p_cap)
{
  return 0LL;
}

_Bool u_cap_mem_get_lck(unsigned long long $p_cap)
{
  return 1;
}

unsigned long long u_cap_mem_get_tag(unsigned long long $p_cap)
{
  return 0LL;
}

unsigned long long u_cap_mem_get_bgn(unsigned long long $p_cap)
{
  return 0LL;
}

unsigned long long u_cap_mem_get_mrk(unsigned long long $p_cap)
{
  return 0LL;
}

unsigned long long u_cap_mem_get_end(unsigned long long $p_cap)
{
  return 0LL;
}

unsigned long long u_cap_mem_set_rwx(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap;
}

unsigned long long u_cap_mem_set_lck(unsigned long long $p_cap, _Bool $p_v)
{
  return $p_cap;
}

unsigned long long u_cap_mem_set_tag(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap;
}

unsigned long long u_cap_mem_set_bgn(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap;
}

unsigned long long u_cap_mem_set_mrk(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap;
}

unsigned long long u_cap_mem_set_end(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap;
}

unsigned long long u_cap_pmp_get_rwx(unsigned long long $p_cap)
{
  return 0LL;
}

_Bool u_cap_pmp_get_used(unsigned long long $p_cap)
{
  return 1;
}

unsigned long long u_cap_pmp_get_slot(unsigned long long $p_cap)
{
  return 0LL;
}

unsigned long long u_cap_pmp_get_addr(unsigned long long $p_cap)
{
  return 0LL;
}

unsigned long long u_cap_pmp_set_rwx(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap;
}

unsigned long long u_cap_pmp_set_used(unsigned long long $p_cap, _Bool $p_v)
{
  return $p_cap;
}

unsigned long long u_cap_pmp_set_slot(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap;
}

unsigned long long u_cap_pmp_set_addr(unsigned long long $p_cap, unsigned long long $p_v)
{
  return $p_cap;
}

_Bool u_ctable_is_empty_cap(struct kernel_state *$p_ks, unsigned int $p_cid)
{
  register unsigned long long $b1;
  register unsigned long long $b0;
  $b1 = *((*$p_ks).ctable + $p_cid);
  $b0 = u_cap_get_type($b1);
  return $b0 == u_CAPTY_NONE;
}

struct kernel_state *u_ctable_set_cap(struct kernel_state *$p_ks, unsigned int $p_cid, unsigned long long $p_cap)
{
  register unsigned long long *$u_ctable;
  register struct kernel_state *$i0;
  $u_ctable = (*$p_ks).ctable;
  *($u_ctable + $p_cid) = $p_cap;
  $u_ctable = $u_ctable;
  (*$p_ks).ctable = $u_ctable;
  $i0 = $p_ks;
  return $i0;
}

struct kernel_state *u_ctable_set_next(struct kernel_state *$p_ks, unsigned int $p_cid, unsigned int $p_nextid)
{
  register unsigned int *$u_cnext;
  register struct kernel_state *$i0;
  $u_cnext = (*$p_ks).cnext;
  *($u_cnext + $p_cid) = $p_nextid;
  $u_cnext = $u_cnext;
  (*$p_ks).cnext = $u_cnext;
  $i0 = $p_ks;
  return $i0;
}

struct kernel_state *u_ctable_set_prev(struct kernel_state *$p_ks, unsigned int $p_cid, unsigned int $p_previd)
{
  register unsigned int *$u_cprev;
  register struct kernel_state *$i0;
  $u_cprev = (*$p_ks).cprev;
  *($u_cprev + $p_cid) = $p_previd;
  $u_cprev = $u_cprev;
  (*$p_ks).cprev = $u_cprev;
  $i0 = $p_ks;
  return $i0;
}

struct kernel_state *u_ctable_move_cap(struct kernel_state *$p_ks, unsigned int $p_src, unsigned int $p_dst)
{
  register unsigned long long $b0;
  register unsigned int $b1;
  register unsigned int $b2;
  register unsigned int $b3;
  register struct kernel_state *$u_ks;
  register unsigned int $b4;
  register struct kernel_state *$i0;
  if ($p_src == $p_dst) {
    return $p_ks;
  } else {
    $b0 = *((*$p_ks).ctable + $p_src);
    $u_ks = u_ctable_set_cap($p_ks, $p_dst, $b0);
    $u_ks = u_ctable_set_cap($u_ks, $p_src, 0LL);
    $b1 = *((*$u_ks).cprev + $p_src);
    $u_ks = u_ctable_set_prev($u_ks, $p_dst, $b1);
    $b2 = *((*$u_ks).cnext + $p_src);
    $u_ks = u_ctable_set_next($u_ks, $p_dst, $b2);
    $b3 = *((*$u_ks).cprev + $p_dst);
    $u_ks = u_ctable_set_next($u_ks, $b3, $p_dst);
    $b4 = *((*$u_ks).cnext + $p_dst);
    $i0 = u_ctable_set_prev($u_ks, $b4, $p_dst);
    return $i0;
  }
}

struct kernel_state *u_ctable_delete_cap(struct kernel_state *$p_ks, unsigned int $p_cid)
{
  register unsigned int $b0;
  register unsigned int $b1;
  register struct kernel_state *$u_ks;
  register unsigned int $b2;
  register unsigned int $b3;
  register struct kernel_state *$i0;
  $u_ks = u_ctable_set_cap($p_ks, $p_cid, 0LL);
  $b0 = *((*$u_ks).cprev + $p_cid);
  $b1 = *((*$u_ks).cnext + $p_cid);
  $u_ks = u_ctable_set_next($u_ks, $b0, $b1);
  $b2 = *((*$u_ks).cnext + $p_cid);
  $b3 = *((*$u_ks).cprev + $p_cid);
  $i0 = u_ctable_set_prev($u_ks, $b2, $b3);
  return $i0;
}

struct kernel_state *u_ctable_insert_cap(struct kernel_state *$p_ks, unsigned int $p_cid, unsigned long long $p_cap, unsigned int $p_previd)
{
  register unsigned int $b0;
  register unsigned int $b1;
  register struct kernel_state *$u_ks;
  register struct kernel_state *$i0;
  $u_ks = u_ctable_set_prev($p_ks, $p_cid, $p_previd);
  $b0 = *((*$u_ks).cnext + $p_previd);
  $u_ks = u_ctable_set_next($u_ks, $p_cid, $b0);
  $u_ks = u_ctable_set_next($u_ks, $p_previd, $p_cid);
  $b1 = *((*$u_ks).cnext + $p_cid);
  $u_ks = u_ctable_set_prev($u_ks, $b1, $p_cid);
  $i0 = u_ctable_set_cap($u_ks, $p_cid, $p_cap);
  return $i0;
}

unsigned long long u_cap_pid(unsigned int $p_cid)
{
  return (unsigned long long) ($p_cid / u_S3K_CAP_CNT);
}

unsigned long long u_pmp_napot_decode_base(unsigned long long $p_addr)
{
  return 0LL;
}

unsigned long long u_pmp_napot_decode_size(unsigned long long $p_addr)
{
  return 0LL;
}

unsigned long long u_tag_block_to_addr(unsigned long long $p_tag, unsigned long long $p_block)
{
  return ($p_tag << u_MAX_BLOCK_SIZE) + ($p_block << u_MIN_BLOCK_SIZE);
}

struct kernel_state *u_cap_delete_memory(struct kernel_state *$p_ks, unsigned int $p_cid)
{
  register struct kernel_state *$u_ks;
  register struct kernel_state *$i0;
  $u_ks = u_ctable_delete_cap($p_ks, $p_cid);
  (*$u_ks).errcode = u_SUCCESS;
  $i0 = $u_ks;
  return $i0;
}

struct kernel_state *u_cap_revoke_memory(struct kernel_state *$p_ks, unsigned int $p_parent)
{
  register unsigned int $u_child;
  register unsigned long long $u_ccap;
  register unsigned long long $b24;
  register _Bool $b23;
  register unsigned long long $b21;
  register unsigned long long $b22;
  register _Bool $b20;
  register unsigned long long $b18;
  register unsigned long long $b19;
  register _Bool $b17;
  register unsigned long long $b0;
  register _Bool $b1;
  register unsigned long long $b5;
  register unsigned long long $b6;
  register _Bool $b4;
  register _Bool $b3;
  register _Bool $b2;
  register struct kernel_state *$i0;
  register struct kernel_state *$i1;
  register unsigned long long $b7;
  register unsigned long long $u_base;
  register unsigned long long $b8;
  register unsigned long long $b9;
  register unsigned long long $u_pcap_tag_addr;
  register unsigned long long $b16;
  register _Bool $b15;
  register _Bool $b14;
  register _Bool $b12;
  register unsigned long long $b10;
  register unsigned long long $b11;
  register struct kernel_state *$i2;
  register unsigned long long $b13;
  register unsigned long long $u_pcap;
  register struct kernel_state *$u_ks;
  register struct kernel_state *$i3;
  $u_pcap = *((*$p_ks).ctable + $p_parent);
  $u_child = *((*$p_ks).cnext + $p_parent);
  $u_ccap = *((*$p_ks).ctable + $u_child);
  $b24 = u_cap_get_type($u_ccap);
  $b23 = $b24 == u_CAPTY_MEMORY;
  if ($b23) {
    $b21 = u_cap_mem_get_tag($u_pcap);
    $b22 = u_cap_mem_get_tag($u_ccap);
    $b20 = $b21 == $b22;
  } else {
    $b20 = 0;
  }
  if ($b20) {
    $b18 = u_cap_mem_get_bgn($u_pcap);
    $b19 = u_cap_mem_get_bgn($u_ccap);
    $b17 = $b18 == $b19;
  } else {
    $b17 = 0;
  }
  if ($b17) {
    $u_ks = u_ctable_delete_cap($p_ks, $u_child);
    $b0 = u_cap_mem_get_mrk($u_ccap);
    $u_pcap = u_cap_mem_set_mrk($u_pcap, $b0);
    $b1 = u_cap_mem_get_lck($u_ccap);
    $u_pcap = u_cap_mem_set_lck($u_pcap, $b1);
    $u_ks = u_ctable_set_cap($u_ks, $p_parent, $u_pcap);
    $b5 = u_cap_mem_get_mrk($u_pcap);
    $b6 = u_cap_mem_get_bgn($u_pcap);
    $b4 = $b5 == $b6;
    if ($b4) {
      $b3 = u_cap_mem_get_lck($u_pcap);
      $b2 = !$b3;
    } else {
      $b2 = 0;
    }
    if ($b2) {
      (*$u_ks).errcode = u_SUCCESS;
      $i0 = $u_ks;
      return $i0;
    } else {
      (*$u_ks).errcode = u_CONTINUE;
      $i1 = $u_ks;
      return $i1;
    }
  } else {
    $b7 = u_cap_pmp_get_addr($u_ccap);
    $u_base = u_pmp_napot_decode_base($b7);
    $b8 = u_cap_mem_get_tag($u_pcap);
    $b9 = u_cap_mem_get_bgn($u_pcap);
    $u_pcap_tag_addr = u_tag_block_to_addr($b8, $b9);
    $b16 = u_cap_get_type($u_ccap);
    $b15 = $b16 == u_CAPTY_PMP;
    if ($b15) {
      $b14 = $u_pcap_tag_addr <= $u_base;
    } else {
      $b14 = 0;
    }
    if ($b14) {
      $u_ks = u_ctable_delete_cap($p_ks, $u_child);
      $b12 = u_cap_pmp_get_used($u_ccap);
      if ($b12) {
        $u_ks = u_vreg_write($u_ks, 0, (unsigned long long) 1);
        $b10 = u_cap_pid($u_child);
        $u_ks = u_vreg_write($u_ks, 1, $b10);
        $b11 = u_cap_pmp_get_slot($u_ccap);
        $u_ks = u_vreg_write($u_ks, 2, $b11);
      } else {
        $u_ks = u_vreg_write($u_ks, 0, (unsigned long long) 0);
      }
      (*$u_ks).errcode = u_CONTINUE;
      $i2 = $u_ks;
      return $i2;
    } else {
      $b13 = u_cap_mem_get_bgn($u_pcap);
      $u_pcap = u_cap_mem_set_mrk($u_pcap, $b13);
      $u_pcap = u_cap_mem_set_lck($u_pcap, 1);
      $u_ks = u_ctable_set_cap($p_ks, $p_parent, $u_pcap);
      (*$u_ks).errcode = u_SUCCESS;
      $i3 = $u_ks;
      return $i3;
    }
  }
}

struct kernel_state *u_cap_derive_memory(struct kernel_state *$p_ks, unsigned int $p_src, unsigned int $p_dst, unsigned long long $p_ncap)
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
  register struct kernel_state *$i0;
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
  register struct kernel_state *$u_ks;
  register struct kernel_state *$i1;
  register struct kernel_state *$i2;
  $u_cap = *((*$p_ks).ctable + $p_src);
  $b35 = u_cap_get_type($p_ncap);
  $b34 = $b35 == u_CAPTY_MEMORY;
  if ($b34) {
    $b32 = u_cap_mem_get_tag($u_cap);
    $b33 = u_cap_mem_get_tag($p_ncap);
    $b31 = $b32 == $b33;
  } else {
    $b31 = 0;
  }
  if ($b31) {
    $b29 = u_cap_mem_get_tag($u_cap);
    $b30 = u_cap_mem_get_tag($p_ncap);
    $b28 = $b29 == $b30;
  } else {
    $b28 = 0;
  }
  if ($b28) {
    $b26 = u_cap_mem_get_mrk($u_cap);
    $b27 = u_cap_mem_get_bgn($p_ncap);
    $b25 = $b26 <= $b27;
  } else {
    $b25 = 0;
  }
  if ($b25) {
    $b23 = u_cap_mem_get_end($p_ncap);
    $b24 = u_cap_mem_get_end($u_cap);
    $b22 = $b23 <= $b24;
  } else {
    $b22 = 0;
  }
  if ($b22) {
    $b19 = u_cap_mem_get_rwx($p_ncap);
    $b20 = u_cap_mem_get_rwx($u_cap);
    $b18 = $b19 & $b20;
    $b21 = u_cap_mem_get_rwx($p_ncap);
    $b17 = $b18 == $b21;
  } else {
    $b17 = 0;
  }
  if ($b17) {
    $b16 = u_cap_mem_get_lck($u_cap);
    $b15 = !$b16;
  } else {
    $b15 = 0;
  }
  if ($b15) {
    $b0 = u_cap_mem_get_end($p_ncap);
    $u_cap = u_cap_mem_set_mrk($u_cap, $b0);
    $u_ks = u_ctable_set_cap($p_ks, $p_src, $u_cap);
    $u_ks = u_ctable_insert_cap($u_ks, $p_dst, $u_cap, $p_src);
    (*$u_ks).errcode = u_SUCCESS;
    $i0 = $u_ks;
    return $i0;
  } else {
    $b1 = u_cap_pmp_get_addr($p_ncap);
    $u_pmp_begin = u_pmp_napot_decode_base($b1);
    $b2 = u_cap_pmp_get_addr($p_ncap);
    $u_pmp_size = u_pmp_napot_decode_size($b2);
    $u_pmp_end = $u_pmp_begin + $u_pmp_size;
    $b3 = u_cap_mem_get_tag($u_cap);
    $b4 = u_cap_mem_get_mrk($u_cap);
    $u_mem_mrk = u_tag_block_to_addr($b3, $b4);
    $b5 = u_cap_mem_get_tag($u_cap);
    $b6 = u_cap_mem_get_end($u_cap);
    $u_mem_end = u_tag_block_to_addr($b5, $b6);
    $b14 = u_cap_get_type($p_ncap);
    $b13 = $b14 == u_CAPTY_PMP;
    if ($b13) {
      $b12 = $u_mem_mrk <= $u_pmp_begin;
    } else {
      $b12 = 0;
    }
    if ($b12) {
      $b9 = u_cap_mem_get_rwx($p_ncap);
      $b10 = u_cap_mem_get_rwx($u_cap);
      $b8 = $b9 & $b10;
      $b11 = u_cap_mem_get_rwx($p_ncap);
      $b7 = $b8 == $b11;
    } else {
      $b7 = 0;
    }
    if ($b7) {
      $u_cap = u_cap_mem_set_lck($u_cap, 1);
      $u_ks = u_ctable_set_cap($p_ks, $p_src, $u_cap);
      $u_ks = u_ctable_insert_cap($u_ks, $p_dst, $p_ncap, $p_src);
      (*$u_ks).errcode = u_SUCCESS;
      $i1 = $u_ks;
      return $i1;
    } else {
      (*$p_ks).errcode = u_ERR_INVALID_DERIVATION;
      $i2 = $p_ks;
      return $i2;
    }
  }
}

struct kernel_state *u_cap_delete_pmp(struct kernel_state *$p_ks, unsigned int $p_cid)
{
  register unsigned long long $u_cap;
  register _Bool $b2;
  register unsigned long long $b0;
  register unsigned long long $b1;
  register struct kernel_state *$u_ks;
  register struct kernel_state *$i0;
  $u_cap = *((*$p_ks).ctable + $p_cid);
  $b2 = u_cap_pmp_get_used($u_cap);
  if ($b2) {
    $u_ks = u_vreg_write($p_ks, 0, (unsigned long long) 1);
    $b0 = u_cap_pid($p_cid);
    $u_ks = u_vreg_write($u_ks, 1, $b0);
    $b1 = u_cap_pmp_get_slot($u_cap);
    $u_ks = u_vreg_write($u_ks, 2, $b1);
  } else {
    $u_ks = u_vreg_write($p_ks, 0, (unsigned long long) 0);
  }
  $u_ks = u_ctable_delete_cap($u_ks, $p_cid);
  (*$u_ks).errcode = u_SUCCESS;
  $i0 = $u_ks;
  return $i0;
}

struct kernel_state *u_cap_revoke_pmp(struct kernel_state *$p_ks)
{
  register struct kernel_state *$i0;
  (*$p_ks).errcode = u_SUCCESS;
  $i0 = $p_ks;
  return $i0;
}

struct kernel_state *u_cap_derive_pmp(struct kernel_state *$p_ks, unsigned int $p_src, unsigned int $p_dst, unsigned long long $p_ncap)
{
  register struct kernel_state *$i0;
  (*$p_ks).errcode = u_ERR_INVALID_DERIVATION;
  $i0 = $p_ks;
  return $i0;
}

struct kernel_state *u_cap_read(struct kernel_state *$p_ks, unsigned int $p_cid)
{
  register unsigned long long $u_cap;
  register unsigned long long $b1;
  register _Bool $b0;
  register struct kernel_state *$i0;
  register struct kernel_state *$u_ks;
  register struct kernel_state *$i1;
  $u_cap = *((*$p_ks).ctable + $p_cid);
  $b1 = u_cap_get_type($u_cap);
  $b0 = $b1 == u_CAPTY_NONE;
  if ($b0) {
    (*$p_ks).errcode = u_ERR_EMPTY;
    $i0 = $p_ks;
    return $i0;
  } else {
    $u_ks = u_vreg_write($p_ks, 0, $u_cap);
    (*$u_ks).errcode = u_SUCCESS;
    $i1 = $u_ks;
    return $i1;
  }
}

struct kernel_state *u_cap_move(struct kernel_state *$p_ks, unsigned int $p_src, unsigned int $p_dst)
{
  register _Bool $b2;
  register struct kernel_state *$i0;
  register _Bool $b1;
  register _Bool $b0;
  register struct kernel_state *$i1;
  register struct kernel_state *$u_ks;
  register struct kernel_state *$i2;
  $b2 = u_ctable_is_empty_cap($p_ks, $p_src);
  if ($b2) {
    (*$p_ks).errcode = u_ERR_SRC_EMPTY;
    $i0 = $p_ks;
    return $i0;
  } else {
    $b1 = u_ctable_is_empty_cap($p_ks, $p_dst);
    $b0 = !$b1;
    if ($b0) {
      (*$p_ks).errcode = u_ERR_DST_OCCUPIED;
      $i1 = $p_ks;
      return $i1;
    } else {
      $u_ks = u_ctable_move_cap($p_ks, $p_src, $p_dst);
      (*$u_ks).errcode = u_SUCCESS;
      $i2 = $u_ks;
      return $i2;
    }
  }
}

struct kernel_state *u_cap_delete(struct kernel_state *$p_ks, unsigned int $p_cid)
{
  register _Bool $b1;
  register struct kernel_state *$i0;
  register unsigned long long $b0;
  register unsigned long long $u_cap_type;
  register struct kernel_state *$i1;
  register struct kernel_state *$i2;
  register struct kernel_state *$i3;
  $b1 = u_ctable_is_empty_cap($p_ks, $p_cid);
  if ($b1) {
    (*$p_ks).errcode = u_ERR_EMPTY;
    $i0 = $p_ks;
    return $i0;
  } else {
    $b0 = *((*$p_ks).ctable + $p_cid);
    $u_cap_type = u_cap_get_type($b0);
    if ($u_cap_type == u_CAPTY_MEMORY) {
      $i1 = u_cap_delete_memory($p_ks, $p_cid);
      return $i1;
    } else {
      if ($u_cap_type == u_CAPTY_PMP) {
        $i2 = u_cap_delete_pmp($p_ks, $p_cid);
        return $i2;
      } else {
        (*$p_ks).errcode = u_ERR_INVALID_CAPABILITY;
        $i3 = $p_ks;
        return $i3;
      }
    }
  }
}

struct kernel_state *u_cap_derive(struct kernel_state *$p_ks, unsigned int $p_src, unsigned int $p_dst, unsigned long long $p_ncap)
{
  register _Bool $b3;
  register struct kernel_state *$i0;
  register _Bool $b2;
  register _Bool $b1;
  register struct kernel_state *$i1;
  register unsigned long long $b0;
  register unsigned long long $u_cap_type;
  register struct kernel_state *$i2;
  register struct kernel_state *$i3;
  register struct kernel_state *$i4;
  $b3 = u_ctable_is_empty_cap($p_ks, $p_src);
  if ($b3) {
    (*$p_ks).errcode = u_ERR_SRC_EMPTY;
    $i0 = $p_ks;
    return $i0;
  } else {
    $b2 = u_ctable_is_empty_cap($p_ks, $p_dst);
    $b1 = !$b2;
    if ($b1) {
      (*$p_ks).errcode = u_ERR_DST_OCCUPIED;
      $i1 = $p_ks;
      return $i1;
    } else {
      $b0 = *((*$p_ks).ctable + $p_src);
      $u_cap_type = u_cap_get_type($b0);
      if ($u_cap_type == u_CAPTY_MEMORY) {
        $i2 = u_cap_derive_memory($p_ks, $p_src, $p_dst, $p_ncap);
        return $i2;
      } else {
        if ($u_cap_type == u_CAPTY_PMP) {
          $i3 = u_cap_derive_pmp($p_ks, $p_src, $p_dst, $p_ncap);
          return $i3;
        } else {
          (*$p_ks).errcode = u_ERR_INVALID_CAPABILITY;
          $i4 = $p_ks;
          return $i4;
        }
      }
    }
  }
}



#include "ti_cpu.h"

#include "ti_mem.h"

/* used by cpu_ldi */

uint8_t a, b, c, d, e, h, l, f;
uint8_t a_, b_, c_, d_, e_, h_, l_, f_;
uint16_t sp, ix, iy;
uint16_t pc;

void cpu_init(void) {
  a = b = c = d = e = h = l = f = 0;
  a_ = b_ = c_ = d_ = e_ = h_ = l_ = f_ = 0;
  sp = 0xFFFE;
  ix = iy = 0;
  pc = 0;
}

uint8_t flag_z(void)  { return (f & FLAG_Z) ? 1 : 0; }
uint8_t flag_nz(void) { return (f & FLAG_Z) ? 0 : 1; }
uint8_t flag_c(void)  { return (f & FLAG_C) ? 1 : 0; }
uint8_t flag_nc(void) { return (f & FLAG_C) ? 0 : 1; }
uint8_t flag_pe(void) { return (f & FLAG_PV) ? 1 : 0; }
uint8_t flag_po(void) { return (f & FLAG_PV) ? 0 : 1; }
uint8_t flag_p(void)  { return (f & FLAG_S) ? 0 : 1; }
uint8_t flag_m(void)  { return (f & FLAG_S) ? 1 : 0; }

void flag_set_z(uint8_t v) {
  if (v) f |= FLAG_Z;
  else f = (uint8_t)(f & ~FLAG_Z);
}

void flag_cmp(uint8_t left, uint8_t right) {
  int r = (int)left - (int)right;
  f = (uint8_t)(FLAG_N);
  if ((r & 0xFF) == 0) f |= FLAG_Z;
  if (r & 0x80) f |= FLAG_S;
  if (r < 0) f |= FLAG_C;
  if (((left & 0x0F) - (right & 0x0F)) < 0) f |= FLAG_H;
}

void flag_logic(uint8_t result) {
  f = 0;
  if (result == 0) f |= FLAG_Z;
  if (result & 0x80) f |= FLAG_S;
  /* parity omitted for mechanical host */
}

void cpu_push16(uint16_t v) {
  sp = (uint16_t)(sp - 1);
  mem_write8(sp, (uint8_t)(v >> 8));
  sp = (uint16_t)(sp - 1);
  mem_write8(sp, (uint8_t)v);
}

uint16_t cpu_pop16(void) {
  uint8_t lo = mem_read8(sp);
  sp = (uint16_t)(sp + 1);
  uint8_t hi = mem_read8(sp);
  sp = (uint16_t)(sp + 1);
  return (uint16_t)((hi << 8) | lo);
}

void cpu_push_af(void) { cpu_push16((uint16_t)((a << 8) | f)); }
void cpu_push_bc(void) { cpu_push16(bc()); }
void cpu_push_de(void) { cpu_push16(de()); }
void cpu_push_hl(void) { cpu_push16(hl()); }

void cpu_pop_af(void) {
  uint16_t v = cpu_pop16();
  a = (uint8_t)(v >> 8);
  f = (uint8_t)v;
}
void cpu_pop_bc(void) { set_bc(cpu_pop16()); }
void cpu_pop_de(void) { set_de(cpu_pop16()); }
void cpu_pop_hl(void) { set_hl(cpu_pop16()); }

void cpu_ex_de_hl(void) {
  uint16_t t = de();
  set_de(hl());
  set_hl(t);
}

void cpu_exx(void) {
  uint8_t tb = b, tc = c, td = d, te = e, th = h, tl = l;
  b = b_; c = c_; d = d_; e = e_; h = h_; l = l_;
  b_ = tb; c_ = tc; d_ = td; e_ = te; h_ = th; l_ = tl;
}

void cpu_ex_af(void) {
  uint8_t ta = a, tf = f;
  a = a_; f = f_;
  a_ = ta; f_ = tf;
}

static void clear_nh(void) {
  f = (uint8_t)(f & (uint8_t)~(FLAG_N | FLAG_H));
}

void cpu_rla(void) {
  uint8_t old_c = (f & FLAG_C) ? 1u : 0u;
  uint8_t new_c = (uint8_t)((a >> 7) & 1u);
  a = (uint8_t)((a << 1) | old_c);
  f = (uint8_t)((f & (uint8_t)~(FLAG_C | FLAG_N | FLAG_H)) | (new_c ? FLAG_C : 0));
}

void cpu_rra(void) {
  uint8_t old_c = (f & FLAG_C) ? 1u : 0u;
  uint8_t new_c = (uint8_t)(a & 1u);
  a = (uint8_t)((a >> 1) | (old_c << 7));
  f = (uint8_t)((f & (uint8_t)~(FLAG_C | FLAG_N | FLAG_H)) | (new_c ? FLAG_C : 0));
}

void cpu_rlca(void) {
  uint8_t new_c = (uint8_t)((a >> 7) & 1u);
  a = (uint8_t)((a << 1) | new_c);
  f = (uint8_t)((f & (uint8_t)~(FLAG_C | FLAG_N | FLAG_H)) | (new_c ? FLAG_C : 0));
}

void cpu_rrca(void) {
  uint8_t new_c = (uint8_t)(a & 1u);
  a = (uint8_t)((a >> 1) | (new_c << 7));
  f = (uint8_t)((f & (uint8_t)~(FLAG_C | FLAG_N | FLAG_H)) | (new_c ? FLAG_C : 0));
}

static void sbc_hl(uint16_t rr) {
  uint32_t cur = hl();
  uint32_t sub = (uint32_t)rr + ((f & FLAG_C) ? 1u : 0u);
  uint32_t r = cur - sub;
  set_hl((uint16_t)r);
  f = FLAG_N;
  if ((r & 0xFFFF) == 0) f |= FLAG_Z;
  if (r & 0x8000) f |= FLAG_S;
  if (r > 0xFFFF) f |= FLAG_C;
}

void cpu_sbc_hl_bc(void) { sbc_hl(bc()); }
void cpu_sbc_hl_de(void) { sbc_hl(de()); }
void cpu_sbc_hl_hl(void) { sbc_hl(hl()); }
void cpu_sbc_hl_sp(void) { sbc_hl(sp); }

static void add_xy_sp(uint16_t *xy) {
  uint32_t r = (uint32_t)(*xy) + (uint32_t)sp;
  *xy = (uint16_t)r;
  f = (uint8_t)(f & (uint8_t)~(FLAG_N | FLAG_C));
  if (r > 0xFFFF) f |= FLAG_C;
}

void cpu_add_ix_sp(void) { add_xy_sp(&ix); }
void cpu_add_iy_sp(void) { add_xy_sp(&iy); }

void cpu_ldi(void) {
  mem_write8(de(), mem_read8(hl()));
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  set_bc((uint16_t)(bc() - 1));
  clear_nh();
  if (bc() != 0) f |= FLAG_PV;
  else f = (uint8_t)(f & (uint8_t)~FLAG_PV);
}

void cpu_ld_a_i(void) {
  a = 0; /* I not tracked; PE/PO from iff stubbed as PO */
  flag_logic(a);
  f = (uint8_t)(f & (uint8_t)~FLAG_PV); /* PO */
}

void cpu_cp_hl(void) {
  flag_cmp(a, mem_read8(hl()));
}

/* halt() is provided by the host (see main.c). */
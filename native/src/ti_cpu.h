#ifndef TI_CPU_H
#define TI_CPU_H

#include <stdint.h>

/* Global Z80 register file for mechanical ASM->C translation. */

extern uint8_t a, b, c, d, e, h, l, f;
extern uint8_t a_, b_, c_, d_, e_, h_, l_, f_;
extern uint16_t sp, ix, iy;
extern uint16_t pc;

/* Flag bits in F (Z80 layout). */
#define FLAG_C  0x01
#define FLAG_N  0x02
#define FLAG_PV 0x04
#define FLAG_H  0x10
#define FLAG_Z  0x40
#define FLAG_S  0x80

void cpu_init(void);

static inline uint16_t bc(void) { return (uint16_t)((b << 8) | c); }
static inline uint16_t de(void) { return (uint16_t)((d << 8) | e); }
static inline uint16_t hl(void) { return (uint16_t)((h << 8) | l); }
static inline void set_bc(uint16_t v) { b = (uint8_t)(v >> 8); c = (uint8_t)v; }
static inline void set_de(uint16_t v) { d = (uint8_t)(v >> 8); e = (uint8_t)v; }
static inline void set_hl(uint16_t v) { h = (uint8_t)(v >> 8); l = (uint8_t)v; }

uint8_t flag_z(void);
uint8_t flag_nz(void);
uint8_t flag_c(void);
uint8_t flag_nc(void);
uint8_t flag_pe(void);
uint8_t flag_po(void);
uint8_t flag_p(void);
uint8_t flag_m(void);

void flag_set_z(uint8_t v);
void flag_cmp(uint8_t left, uint8_t right);
void flag_logic(uint8_t result); /* after and/or/xor */

void cpu_push16(uint16_t v);
uint16_t cpu_pop16(void);
void cpu_push_af(void);
void cpu_push_bc(void);
void cpu_push_de(void);
void cpu_push_hl(void);
void cpu_pop_af(void);
void cpu_pop_bc(void);
void cpu_pop_de(void);
void cpu_pop_hl(void);

void cpu_ex_de_hl(void);
void cpu_exx(void);
void cpu_ex_af(void);

void cpu_rla(void);
void cpu_rra(void);
void cpu_rlca(void);
void cpu_rrca(void);
void cpu_sbc_hl_bc(void);
void cpu_sbc_hl_de(void);
void cpu_sbc_hl_hl(void);
void cpu_sbc_hl_sp(void);
void cpu_add_ix_sp(void);
void cpu_add_iy_sp(void);
void cpu_ldi(void);
void cpu_ld_a_i(void); /* I register stub */
void cpu_cp_hl(void);  /* cp (hl) */

/* Host implements halt() - yields; longjmp code 2 = HALT, 1 = step limit. */
void halt(void);

#endif

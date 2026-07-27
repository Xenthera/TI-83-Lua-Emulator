/* Recovered from flash page 31 (mechanical ASM->C) */
/* cpu window 0x4000..0x7FFF prefix=p31_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p31_L_4000(void);
void p31_str_2(void);
void p31_L_4021(void);
void p31_L_40D5(void);
void p31_L_40E3(void);
void p31_L_4100(void);
void p31_L_4170(void);
void p31_L_423F(void);
void p31_L_4272(void);
void p31_L_4282(void);
void p31_L_429F(void);
void p31_L_42C9(void);
void p31_L_4312(void);
void p31_L_431F(void);
void p31_L_4323(void);
void p31_L_4347(void);
void p31_L_4372(void);
void p31_L_4396(void);
void p31_L_43B3(void);
void p31_L_43C3(void);
void p31_L_4407(void);
void p31_L_443C(void);
void p31_L_4448(void);
void p31_L_4453(void);
void p31_L_4459(void);
void p31_L_445E(void);
void p31_L_4531(void);
void p31_L_45B9(void);
void p31_L_4616(void);
void p31_L_4621(void);
void p31_L_4643(void);
void p31_L_47C8(void);
void p31_L_47D0(void);
void p31_L_4C20(void);
void p31_L_4E20(void);
void p31_lcd_init(void);
void p31_lcd_write_cmd(void);
void p31_lcd_write_data(void);
void p31_lcd_put(void);
void p31_lcd_put_2(void);
void p31_L_4F14(void);
void p31_L_4F20(void);
void p31_L_4F24(void);
void p31_L_4F60(void);
void p31_L_4FC8(void);
void p31_L_4FFD(void);
void p31_L_51A3(void);
void p31_L_51D3(void);
void p31_L_51EF(void);
void p31_L_5220(void);
void p31_L_523E(void);
void p31_L_5256(void);
void p31_L_527B(void);
void p31_L_5283(void);
void p31_L_5293(void);
void p31_L_52A3(void);
void p31_L_52B3(void);
void p31_L_52C3(void);
void p31_L_52E1(void);
void p31_L_52F4(void);
void p31_L_534F(void);
void p31_mmu_set_bankA(void);
void p31_L_536D(void);
void p31_L_539F(void);
void p31_L_53A5(void);
void p31_L_53AC(void);
void p31_L_53AF(void);
void p31_L_53B5(void);
void p31_str_1(void);
void p31_L_53CB(void);
void p31_L_53DF(void);
void p31_L_54DD(void);
void p31_L_56DD(void);
void p31_L_56ED(void);
void p31_L_58CB(void);
void p31_L_5A01(void);
void p31_L_5B59(void);
void p31_L_5BB1(void);
void p31_L_5D1F(void);
void p31_L_5DDD(void);
void p31_L_5E1F(void);
void p31_L_606E(void);
void p31_L_6163(void);
void p31_L_616F(void);
void p31_L_6461(void);
void p31_L_6564(void);
void p31_L_65D6(void);
void p31_L_681F(void);
void p31_L_6974(void);
void p31_L_6B62(void);
void p31_L_6E6F(void);
void p31_L_6E77(void);
void p31_L_6F44(void);
void p31_L_6F63(void);
void p31_L_6F6C(void);
void p31_L_7109(void);
void p31_L_742E(void);
void p31_L_7564(void);
void p31_L_75DD(void);
void p31_L_76F3(void);
void p31_L_7835(void);
void p31_L_7C70(void);
void p31_L_7FF0(void);

/* flash page 31 cpu 0x4000 (offset 0x0000) */
void p31_L_4000(void) {
  a = 0x1F;
  mmu_set_bank_a(a);
  mmu_set_bank_b(a);
  os_banked_call(0x80D5);
  return;
}

/* flash page 31 cpu 0x400F (offset 0x000F) */
void p31_str_2(void) {
  sp = 0x2E31;
  mem_write8(0x3935, a);
  /* nop */
  p00_rst38_isr();
  p00_rst38_isr();
  if (flag_z()) return;
  c = a;
  cpu_rra();
  /* sbc a,a */
  d = e;
  cpu_rra();
  mem_write8(hl(), b);
  b = c;
  cpu_rra();
  p31_L_4021();
  return;
}

/* flash page 31 cpu 0x4021 (offset 0x0021) */
void p31_L_4021(void) {
  e = mem_read8(hl());
  b = h;
  cpu_rra();
  flag_cmp(a, c);
  b = l;
  cpu_rra();
  a = a | e;
  flag_logic(a);
  b = e;
  cpu_rra();
  e = c;
  b = h;
  cpu_rra();
  a = (uint8_t)(a - d);
  b = d;
  cpu_rra();
  /* sub (hl) */
  b = e;
  cpu_rra();
  a = a ^ h;
  flag_logic(a);
  d = e;
  cpu_rra();
  a = a ^ h;
  flag_logic(a);
  d = e;
  cpu_rra();
  a = a ^ h;
  flag_logic(a);
  d = e;
  cpu_rra();
  a = a ^ h;
  flag_logic(a);
  d = e;
  cpu_rra();
  a = a ^ h;
  flag_logic(a);
  d = e;
  cpu_rra();
  cpu_pop_hl();
  d = d;
  cpu_rra();
  /* ex (sp),hl */
  d = d;
  cpu_rra();
  if (flag_p()) p00_L_1F52();
  a = a | 0x52;
  flag_logic(a);
  cpu_rra();
  /* sbc a,a */
  d = e;
  cpu_rra();
  e = l;
  d = e;
  cpu_rra();
  l = l;
  d = e;
  cpu_rra();
  a = (uint8_t)(a + d);
  b = d;
  cpu_rra();
  cpu_rlca();
  b = h;
  cpu_rra();
  /* adc a,0x43 */
  cpu_rra();
  set_hl(0x1F46);
  /* sbc a,a */
  d = e;
  cpu_rra();
  /* sbc a,a */
  d = e;
  cpu_rra();
  /* sbc a,a */
  d = e;
  cpu_rra();
  b = e;
  b = mem_read8(hl());
  cpu_rra();
  b = e;
  b = mem_read8(hl());
  cpu_rra();
  /* sbc a,a */
  d = e;
  cpu_rra();
  p00_rst10();
  b = e;
  cpu_rra();
  p00_L_1F43();
  return;
}

/* flash page 31 cpu 0x40D5 (offset 0x00D5) */
void p31_L_40D5(void) {
  /* di */
  a = 0x1F;
  mmu_set_bank_a(a);
  mmu_set_bank_b(a);
  a = 0x06;
  hw_out(PORT_INTACK, a);
  p31_L_40E3();
  return;
}

/* flash page 31 cpu 0x40E3 (offset 0x00E3) */
void p31_L_40E3(void) {
  a = 0x40;
  mmu_set_bank_b(a);
  set_hl(0x0000);
  sp = hl();
  cpu_push_hl();
  cpu_push_hl();
  cpu_push_hl();
  a = 0;
  flag_logic(a);
  link_out(a); /* stub */
  a = 0xFF;
  hw_out(PORT_KEYPAD, a);
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  a = 0x0B;
  hw_out(PORT_INTMASK, a);
  p31_lcd_init();
  p31_L_4100();
  return;
}

/* flash page 31 cpu 0x4100 (offset 0x0100) */
void p31_L_4100(void) {
  p31_L_443C();
  a = 0x15;
  p31_L_53DF();
  a = 0x07;
  hw_out(PORT_ASYN, a);
  a = 0x0F;
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x16, a);
  p31_L_4448();
  a = a | a;
  flag_logic(a);
  set_hl(mem_read16(0x0056));
  set_bc(0xA55A);
  cpu_sbc_hl_bc();
  if (flag_z()) { p00_L_0053(); return; }
  a = 0x03;
  p31_lcd_write_cmd();
  p31_lcd_put();
  set_hl(0x0001);
  mem_write16(0x844B, hl());
  p31_L_53B5();
  p31_L_4F14();
  set_hl(0x4140);
  p31_L_4F24();
  /* di */
  halt();
  a = (uint8_t)(a - 0x2A);
  if (flag_nz()) goto lab_p31_L_4192;
  l = a;
  if (flag_nz()) goto lab_p31_L_4196;
  d = e;
  if (flag_nz()) goto lab_p31_L_4196;
  l = a;
  h = c;
  h = h;
  h = l;
  h = h;
  if (flag_nz()) goto lab_p31_L_417B;
  a = (uint8_t)(a - 0x44);
  l = a;
  mem_write8(hl(), a);
  l = mem_read8(hl());
  l = h;
  l = a;
  h = c;
  h = h;
  if (flag_nz()) goto lab_p31_L_41AB;
  d = e;
  a = mem_read8(0x65D6);
  h = h;
  mem_write8(hl(), l);
  h = e;
  h = c;
  mem_write8(hl(), h);
  l = c;
  l = a;
  l = mem_read8(hl());
  l = 0x74;
  l = c;
  l = 0x63;
  l = a;
  l = l;
  /* nop */
  p31_L_4170();
  return;
  lab_p31_L_4176: ;
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  cpu_cp_hl();
  if (flag_nz()) return;
  lab_p31_L_417B: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4176;
  return;
  lab_p31_L_4192: ;
  a = a | b;
  flag_logic(a);
  cpu_pop_de();
  cpu_pop_hl();
  a = mem_read8(de());
  lab_p31_L_4196: ;
  b = a;
  set_de((uint16_t)(de() + 1));
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  lab_p31_L_419A: ;
  ix = (uint16_t)(ix + 1);
  cpu_push16(ix);
  cpu_push_de();
  cpu_push_bc();
  lab_p31_L_41A0: ;
  a = mem_read8(de());
  cpu_push_de();
  e = mem_read8(hl());
  cpu_push_hl();
  p31_L_52E1();
  e = mem_read8(ix);
  d = mem_read8((uint16_t)(ix + 0x01));
  lab_p31_L_41AB: ;
  d = mem_read8(hl());
  set_bc(0xDD19);
  set_hl((uint16_t)(hl() + de()));
  /* ld (ix),ixl */
  mem_write8(hl(), l);
  /* nop */
  /* ld (ix+0x01),ixh */
  if (flag_nc()) goto lab_p31_L_41C1;
  cpu_push16(ix);
  lab_p31_L_41B8: ;
  ix = (uint16_t)(ix + 1);
  /* inc (ix+0x01) */
  if (flag_z()) goto lab_p31_L_41B8;
  ix = cpu_pop16();
  lab_p31_L_41C1: ;
  cpu_pop_hl();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  ix = (uint16_t)(ix + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_41A0;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_bc();
  cpu_pop_de();
  ix = cpu_pop16();
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p31_L_419A;
  return;
}

/* flash page 31 cpu 0x4170 (offset 0x0170) */
void p31_L_4170(void) {
  a = mem_read8(de());
  cpu_cp_hl();
  if (flag_nz()) return;
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  b = a;
  lab_p31_L_4176: ;
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  cpu_cp_hl();
  if (flag_nz()) return;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4176;
  return;
}

/* flash page 31 cpu 0x423F (offset 0x023F) */
void p31_L_423F(void) {
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p31_L_4271;
  cpu_push_bc();
  set_hl((uint16_t)(hl() + 1));
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  cpu_pop_bc();
  c = mem_read8(ix);
  ix = (uint16_t)(ix + 1);
  l = 0x00;
  lab_p31_L_4251: ;
  cpu_push_bc();
  cpu_push_af();
  a = mem_read8(ix);
  h = a;
  lab_p31_L_4257: ;
  set_hl((uint16_t)(hl() + hl()));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4257;
  l = a;
  cpu_pop_af();
  a = mem_read8(de());
  /* sbc a,h */
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  ix = (uint16_t)(ix + 1);
  cpu_pop_bc();
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p31_L_4251;
  cpu_push_af();
  h = 0x00;
  lab_p31_L_4269: ;
  set_hl((uint16_t)(hl() + hl()));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4269;
  cpu_pop_af();
  a = mem_read8(de());
  /* sbc a,h */
  mem_write8(de(), a);
  return;
  lab_p31_L_4271: ;
  set_hl((uint16_t)(hl() + bc()));
  p31_L_4272();
  return;
}

/* flash page 31 cpu 0x4272 (offset 0x0272) */
void p31_L_4272(void) {
  a = a | a;
  flag_logic(a);
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(ix);
  lab_p31_L_4277: ;
  a = mem_read8(hl());
  /* sbc a,(ix+0x01) */
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  ix = (uint16_t)(ix + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4277;
  return;
}

/* flash page 31 cpu 0x4282 (offset 0x0282) */
void p31_L_4282(void) {
  cpu_push_af();
  a = 0x1E;
  set_hl(0x4000);
  p31_mmu_set_bankA();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p31_L_4290;
  h = 0x60;
  lab_p31_L_4290: ;
  cpu_pop_af();
  return;
}

/* flash page 31 cpu 0x429F (offset 0x029F) */
void p31_L_429F(void) {
  cpu_ld_a_i();
  cpu_push_af();
  p31_L_443C();
  set_de(0x0A10);
  p31_L_43B3();
  if (flag_nz()) goto lab_p31_L_42BD;
  set_hl((uint16_t)(hl() + 1));
  d = c;
  p31_L_4407();
  e = d;
  d = c;
  cpu_push_de();
  set_de(0x8499);
  p31_L_536D();
  flag_cmp(a, a);
  cpu_pop_bc();
  lab_p31_L_42BD: ;
  p31_L_4448();
  cpu_pop_de();
  cpu_push_af();
  flag_set_z((e & (1u << 2)) == 0);
  if (flag_z()) goto lab_p31_L_42C7;
  /* ei */
  lab_p31_L_42C7: ;
  cpu_pop_af();
  return;
}

/* flash page 31 cpu 0x42C9 (offset 0x02C9) */
void p31_L_42C9(void) {
  cpu_push_hl();
  cpu_push_de();
  p31_L_4282();
  set_de(0x1FE0);
  set_hl((uint16_t)(hl() + de()));
  a = 0x1E;
  p31_mmu_set_bankA();
  a = a & 0x01;
  flag_logic(a);
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 31 cpu 0x4312 (offset 0x0312) */
void p31_L_4312(void) {
  set_hl(mem_read16(0x838F));
  set_de(0x0401);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  return;
}

/* flash page 31 cpu 0x431F (offset 0x031F) */
void p31_L_431F(void) {
  cpu_rlca();
  b = h;
  cpu_pop_de();
  set_hl((uint16_t)(hl() + bc()));
  p31_L_4323();
  return;
}

/* flash page 31 cpu 0x4323 (offset 0x0323) */
void p31_L_4323(void) {
  goto lab_p31_L_4323;
  lab_p31_L_431C: ;
  cpu_pop_af();
  cpu_push_de();
  p31_L_4407();
  cpu_pop_de();
  set_hl((uint16_t)(hl() + bc()));
  lab_p31_L_4323: ;
  cpu_push_af();
  p31_mmu_set_bankA();
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, d);
  if (flag_nz()) goto lab_p31_L_4339;
  cpu_pop_af();
  cpu_push_af();
  p31_mmu_set_bankA();
  a = a ^ e;
  flag_logic(a);
  a = a & 0xF0;
  flag_logic(a);
  if (flag_nz()) goto lab_p31_L_431C;
  cpu_pop_af();
  set_hl((uint16_t)(hl() - 1));
  flag_cmp(a, a);
  return;
  lab_p31_L_4339: ;
  a = (uint8_t)(a + 1);
  if (flag_nz()) goto lab_p31_L_431C;
  a = (uint8_t)(a + 1);
  cpu_pop_bc();
  a = b;
  return;
}

/* flash page 31 cpu 0x4347 (offset 0x0347) */
void p31_L_4347(void) {
  goto lab_p31_L_4347;
  lab_p31_L_4340: ;
  cpu_pop_af();
  cpu_push_de();
  p31_L_4407();
  cpu_pop_de();
  set_hl((uint16_t)(hl() + bc()));
  lab_p31_L_4347: ;
  cpu_push_af();
  p31_mmu_set_bankA();
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, d);
  if (flag_nz()) goto lab_p31_L_435D;
  cpu_pop_af();
  cpu_push_af();
  p31_mmu_set_bankA();
  a = a ^ e;
  flag_logic(a);
  a = a & 0xF0;
  flag_logic(a);
  if (flag_nz()) goto lab_p31_L_4340;
  cpu_pop_af();
  set_hl((uint16_t)(hl() - 1));
  flag_cmp(a, a);
  return;
  lab_p31_L_435D: ;
  flag_cmp(a, 0x80);
  if (flag_z()) goto lab_p31_L_4340;
  a = (uint8_t)(a - 0x02);
  if (flag_z()) goto lab_p31_L_4340;
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p31_L_4340;
  cpu_pop_bc();
  a = b;
  return;
}

/* flash page 31 cpu 0x4372 (offset 0x0372) */
void p31_L_4372(void) {
  goto lab_p31_L_4372;
  lab_p31_L_436B: ;
  cpu_pop_af();
  cpu_push_de();
  p31_L_4407();
  cpu_pop_de();
  set_hl((uint16_t)(hl() + bc()));
  lab_p31_L_4372: ;
  cpu_push_af();
  p31_mmu_set_bankA();
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, d);
  if (flag_nz()) goto lab_p31_L_4388;
  cpu_pop_af();
  cpu_push_af();
  p31_mmu_set_bankA();
  a = a ^ e;
  flag_logic(a);
  a = a & 0xF0;
  flag_logic(a);
  if (flag_nz()) goto lab_p31_L_436B;
  cpu_pop_af();
  set_hl((uint16_t)(hl() - 1));
  flag_cmp(a, a);
  return;
  lab_p31_L_4388: ;
  cpu_pop_bc();
  a = b;
  return;
}

/* flash page 31 cpu 0x4396 (offset 0x0396) */
void p31_L_4396(void) {
  goto lab_p31_L_4396;
  lab_p31_L_438B: ;
  cpu_pop_af();
  cpu_push_de();
  p31_L_4407();
  b = a;
  a = e;
  cpu_pop_de();
  flag_cmp(a, e);
  if (flag_nz()) return;
  set_hl((uint16_t)(hl() + bc()));
  lab_p31_L_4396: ;
  cpu_push_af();
  p31_mmu_set_bankA();
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, d);
  if (flag_nz()) goto lab_p31_L_43B0;
  cpu_pop_af();
  cpu_push_af();
  p31_mmu_set_bankA();
  a = a ^ e;
  flag_logic(a);
  a = a & 0xF0;
  flag_logic(a);
  if (flag_nz()) goto lab_p31_L_438B;
  cpu_pop_af();
  cpu_push_de();
  p31_L_4407();
  cpu_pop_de();
  flag_cmp(a, a);
  return;
  lab_p31_L_43B0: ;
  cpu_pop_bc();
  a = b;
  return;
}

/* flash page 31 cpu 0x43B3 (offset 0x03B3) */
void p31_L_43B3(void) {
  p31_L_4282();
  a = 0x1E;
  p31_mmu_set_bankA();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  a = 0x1E;
  set_hl((uint16_t)(hl() + 1));
  p31_L_4323();
  return;
}

/* flash page 31 cpu 0x43C3 (offset 0x03C3) */
void p31_L_43C3(void) {
  a = 0x1E;
  cpu_push_de();
  p31_L_4407();
  cpu_pop_de();
  set_hl((uint16_t)(hl() + bc()));
  p31_L_4323();
  return;
}

/* flash page 31 cpu 0x4407 (offset 0x0407) */
void p31_L_4407(void) {
  cpu_push_af();
  p31_mmu_set_bankA();
  e = a;
  a = a | 0xF0;
  flag_logic(a);
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p31_L_441E;
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p31_L_4427;
  b = 0x00;
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p31_L_442E;
  a = (uint8_t)(a + 0x0D);
  c = a;
  goto lab_p31_L_4435;
  lab_p31_L_441E: ;
  set_bc(0x0004);
  set_hl((uint16_t)(hl() + bc()));
  set_bc(0x0000);
  goto lab_p31_L_4435;
  lab_p31_L_4427: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  p31_mmu_set_bankA();
  b = a;
  lab_p31_L_442E: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  p31_mmu_set_bankA();
  c = a;
  lab_p31_L_4435: ;
  set_hl((uint16_t)(hl() + 1));
  a = e;
  a = a & 0x0F;
  flag_logic(a);
  e = a;
  cpu_pop_af();
  return;
}

/* flash page 31 cpu 0x443C (offset 0x043C) */
void p31_L_443C(void) {
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  cpu_pop_af();
  return;
}

/* flash page 31 cpu 0x4448 (offset 0x0448) */
void p31_L_4448(void) {
  cpu_push_af();
  a = 0;
  flag_logic(a);
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  cpu_pop_af();
  return;
}

/* flash page 31 cpu 0x4453 (offset 0x0453) */
void p31_L_4453(void) {
  flag_cmp(a, 0x1E);
  if (flag_c()) { p31_L_445E(); return; }
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 31 cpu 0x4459 (offset 0x0459) */
void p31_L_4459(void) {
  a = 0x1E;
  b = 0x00;
  cpu_ex_de_hl();
  p31_L_445E();
  return;
}

/* flash page 31 cpu 0x445E (offset 0x045E) */
void p31_L_445E(void) {
  set_hl(0x8478);
  mem_write8(hl(), b);
  set_bc(0x0001);
  p31_L_4531();
  return;
}

/* flash page 31 cpu 0x4531 (offset 0x0531) */
void p31_L_4531(void) {
  p31_L_53CB();
  a = (uint8_t)(a + l);
  mmu_set_bank_a(a);
  a = a & 0x40;
  flag_logic(a);
  if (flag_nz()) goto lab_p31_L_4591;
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p31_L_4591;
  a = 0xF0;
  mem_write8(0x3FFF, a);
  cpu_push_bc();
  a = hw_in(PORT_MMU_A);
  b = a;
  a = 0x02;
  mmu_set_bank_a(a);
  a = 0xAA;
  mem_write8(0x6AAA, a);
  a = 0x01;
  mmu_set_bank_a(a);
  a = 0x55;
  mem_write8(0x5555, a);
  a = 0x02;
  mmu_set_bank_a(a);
  a = 0xA0;
  mem_write8(0x6AAA, a);
  a = b;
  mmu_set_bank_a(a);
  cpu_pop_bc();
  a = mem_read8(hl());
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() - 1));
  cpu_push_bc();
  a = a & 0x80;
  flag_logic(a);
  b = a;
  lab_p31_L_456F: ;
  a = mem_read8(de());
  a = a ^ b;
  flag_logic(a);
  if (flag_p()) { os_banked_call(0x814A); return; }
  a = a & 0x20;
  flag_logic(a);
  if (flag_z()) goto lab_p31_L_456F;
  a = mem_read8(de());
  a = a ^ b;
  flag_logic(a);
  if (flag_m()) { os_banked_call(0x817F); return; }
  goto lab_p31_L_456F;
  lab_p31_L_4591: ;
  a = 0x1F;
  mmu_set_bank_a(a);
  cpu_push_hl();
  cpu_push_hl();
  cpu_push_hl();
  /* nop */
  /* nop */
  /* nop */
  goto lab_p31_L_459D;
  lab_p31_L_459D: ;
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_hl();
  a = 0xF0;
  mem_write8(0x3FFF, a);
  return;
}

/* flash page 31 cpu 0x45B9 (offset 0x05B9) */
void p31_L_45B9(void) {
  p31_L_53CB();
  e = d;
  cpu_push_af();
  a = a & 0x40;
  flag_logic(a);
  if (flag_nz()) goto lab_p31_L_4611;
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p31_L_4611;
  a = 0x02;
  mmu_set_bank_a(a);
  a = 0xAA;
  mem_write8(0x6AAA, a);
  a = 0x01;
  mmu_set_bank_a(a);
  a = 0x55;
  mem_write8(0x5555, a);
  a = 0x02;
  mmu_set_bank_a(a);
  a = 0x80;
  mem_write8(0x6AAA, a);
  a = 0x02;
  mmu_set_bank_a(a);
  a = 0xAA;
  mem_write8(0x6AAA, a);
  a = 0x01;
  mmu_set_bank_a(a);
  a = 0x55;
  mem_write8(0x5555, a);
  cpu_pop_af();
  mmu_set_bank_a(a);
  mem_write8(hl(), 0x30);
  lab_p31_L_45F8: ;
  a = mem_read8(hl());
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p31_L_4606;
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) goto lab_p31_L_45F8;
  a = mem_read8(hl());
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_z()) goto lab_p31_L_4612;
  lab_p31_L_4606: ;
  a = 0;
  flag_logic(a);
  lab_p31_L_4607: ;
  a = 0xF0;
  mem_write8(0x0000, a);
  a = 0x1F;
  mmu_set_bank_a(a);
  return;
  lab_p31_L_4611: ;
  cpu_pop_af();
  lab_p31_L_4612: ;
  a = a | 0xFF;
  flag_logic(a);
  goto lab_p31_L_4607;
}

/* flash page 31 cpu 0x4616 (offset 0x0616) */
void p31_L_4616(void) {
  flag_cmp(a, 0x1E);
  if (flag_z()) goto lab_p31_L_461F;
  set_hl(0x4000);
  p31_L_45B9();
  return;
  lab_p31_L_461F: ;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 31 cpu 0x4621 (offset 0x0621) */
void p31_L_4621(void) {
  cpu_push_af();
  a = l;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p31_L_4632;
  a = h;
  a = a & 0xDF;
  flag_logic(a);
  flag_cmp(a, 0x40);
  if (flag_nz()) goto lab_p31_L_4632;
  a = 0x1E;
  p31_L_45B9();
  lab_p31_L_4632: ;
  cpu_pop_af();
  return;
}

/* flash page 31 cpu 0x4643 (offset 0x0643) */
void p31_L_4643(void) {
  set_de(0x845A);
  a = 0x06;
  mem_write8(de(), a);
  cpu_push_de();
  set_de((uint16_t)(de() + 1));
  flag_set_z((mem_read8((uint16_t)(iy + 0x32)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p31_L_4664;
  cpu_push_de();
  lab_p31_L_4652: ;
  set_de(0x4678);
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_de();
  b = 0x07;
  lab_p31_L_4659: ;
  a = mem_read8(hl());
  a = (uint8_t)(a + a);
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4659;
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  cpu_pop_hl();
  return;
  lab_p31_L_4664: ;
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  d = a;
  e = a;
  mem_write16(0x8466, de());
  mem_write8(0x8468, a);
  goto lab_p31_L_4652;
}

/* flash page 31 cpu 0x47C8 (offset 0x07C8) */
void p31_L_47C8(void) {
  /* nop */
  b = (uint8_t)(b + 1);
  cpu_rra();
  c = 0x1F;
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x00;
  /* nop */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_rra();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  goto lab_p31_L_47E6;
  lab_p31_L_47E6: ;
  /* nop */
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  goto lab_p31_L_4807;
  lab_p31_L_4807: ;
  b = 0x0E;
  set_de(0x0601);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_482E;
  b = 0x0E;
  set_de(0x0601);
  set_bc(0x0E11);
  b = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  set_de(0x1F11);
  set_bc(0x0601);
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4833;
  c = 0x01;
  set_de(0x060E);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_484A;
  set_de(0x0E11);
  lab_p31_L_482E: ;
  c = 0x06;
  b = 0x1F;
  cpu_rra();
  set_bc(0x0202);
  lab_p31_L_4833: ;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = 0x0E;
  set_de(0x0E11);
  set_de(0x0E11);
  b = 0x0E;
  set_de(0x0F11);
  set_bc(0x0402);
  b = 0x00;
  /* nop */
  lab_p31_L_484A: ;
  goto lab_p31_L_4864;
  lab_p31_L_4864: ;
  /* nop */
  cpu_rra();
  /* nop */
  b = 0x00;
  /* nop */
  goto lab_p31_L_4872;
  lab_p31_L_4872: ;
  set_bc((uint16_t)(bc() + 1));
  b = 0x04;
  /* nop */
  b = (uint8_t)(b + 1);
  b = 0x0E;
  set_de(0x1513);
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_488E;
  b = 0x04;
  a = mem_read8(bc());
  a = mem_read8(bc());
  set_de(0x111F);
  set_de(0x1E06);
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  c = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  lab_p31_L_488E: ;
  e = 0x06;
  c = 0x11;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_48A4;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_48A7;
  c = 0x06;
  e = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  e = 0x06;
  cpu_rra();
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_af();
  c = 0x08;
  lab_p31_L_48A4: ;
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  cpu_rra();
  lab_p31_L_48A7: ;
  b = 0x1F;
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_af();
  c = 0x08;
  cpu_ex_af();
  goto lab_p31_L_48B6;
  lab_p31_L_48B6: ;
  cpu_rrca();
  b = 0x19;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  cpu_rrca();
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x0E;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  set_bc((uint16_t)(bc() + 1));
  set_bc(0x0101);
  set_de(0x0E11);
  b = 0x19;
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x1C;
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  cpu_rra();
  b = 0x11;
  set_de((uint16_t)(de() - 1));
  cpu_rra();
  d = (uint8_t)(d - 1);
  set_de(0x1111);
  b = 0x11;
  set_hl((uint16_t)(hl() + de()));
  e = (uint8_t)(e - 1);
  cpu_rla();
  set_de((uint16_t)(de() + 1));
  set_de(0x0611);
  c = 0x11;
  set_de(0x1111);
  set_de(0x060E);
  e = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  c = 0x08;
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  b = 0x0E;
  set_de(0x1111);
  d = (uint8_t)(d - 1);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = 0x1E;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  c = 0x0A;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x0F;
  set_de(0x0E10);
  set_bc(0x1E11);
  b = 0x1F;
  d = (uint8_t)(d - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  set_de(0x1111);
  set_de(0x1111);
  c = 0x06;
  set_de(0x1111);
  set_de(0x0A11);
  b = (uint8_t)(b + 1);
  b = 0x11;
  set_de(0x1511);
  cpu_rra();
  set_de((uint16_t)(de() - 1));
  set_de(0x1106);
  a = mem_read8(bc());
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  set_de(0x1106);
  set_de(0x040A);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  cpu_rra();
  set_de(0x0402);
  cpu_ex_af();
  set_de(0x061F);
  c = 0x11;
  set_de(0x111F);
  set_de(0x060E);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4962;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  set_bc(0x1C06);
  b = (uint8_t)(b + 1);
  lab_p31_L_4962: ;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  e = (uint8_t)(e + 1);
  b = 0x04;
  a = mem_read8(bc());
  set_de(0x0000);
  /* nop */
  /* nop */
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_rra();
  b = 0x0C;
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x00;
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = 0x12;
  c = (uint8_t)(c - 1);
  b = 0x18;
  cpu_ex_af();
  c = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  e = 0x06;
  /* nop */
  /* nop */
  c = 0x11;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_49A7;
  c = 0x06;
  b = 0x02;
  c = 0x12;
  mem_write8(de(), a);
  mem_write8(de(), a);
  cpu_rrca();
  b = 0x00;
  /* nop */
  c = 0x11;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_49B6;
  lab_p31_L_49A7: ;
  b = 0x03;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_rrca();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  /* nop */
  /* nop */
  cpu_rrca();
  set_de(0x010F);
  lab_p31_L_49B6: ;
  e = 0x06;
  goto lab_p31_L_49C2;
  lab_p31_L_49C2: ;
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  set_bc(0x0300);
  set_bc(0x1101);
  c = 0x06;
  goto lab_p31_L_49DA;
  lab_p31_L_49DA: ;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  /* nop */
  /* nop */
  a = mem_read8(de());
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  set_de(0x0006);
  /* nop */
  d = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x00;
  /* nop */
  c = 0x11;
  set_de(0x0E11);
  b = 0x00;
  /* nop */
  e = 0x09;
  c = 0x08;
  goto lab_p31_L_4A06;
  lab_p31_L_4A06: ;
  set_bc((uint16_t)(bc() + 1));
  b = 0x00;
  /* nop */
  d = 0x09;
  cpu_ex_af();
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  b = 0x00;
  /* nop */
  cpu_rrca();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4A23;
  set_bc(0x061E);
  /* nop */
  cpu_ex_af();
  e = 0x08;
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  b = 0x06;
  /* nop */
  /* nop */
  set_de((uint16_t)(de() + 1));
  lab_p31_L_4A23: ;
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = 0x00;
  /* nop */
  set_de(0x0A11);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = 0x00;
  /* nop */
  set_de(0x1515);
  d = (uint8_t)(d - 1);
  a = mem_read8(bc());
  b = 0x00;
  /* nop */
  set_de(0x040A);
  a = mem_read8(bc());
  set_de(0x0006);
  /* nop */
  set_de(0x040A);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4A4E;
  /* nop */
  /* nop */
  cpu_rra();
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  lab_p31_L_4A4E: ;
  cpu_rra();
  b = 0x06;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = 0x06;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = 0x0C;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = 0x00;
  /* nop */
  set_hl((uint16_t)(hl() + bc()));
  d = (uint8_t)(d - 1);
  mem_write8(de(), a);
  /* nop */
  /* nop */
  b = 0x1F;
  cpu_rra();
  set_de(0x111F);
  cpu_rra();
  cpu_rra();
  b = 0x00;
  /* nop */
  /* nop */
  cpu_ex_af();
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  cpu_ex_af();
  b = 0x00;
  /* nop */
  /* nop */
  cpu_ex_af();
  goto lab_p31_L_4A8E;
  lab_p31_L_4A8E: ;
  e = (uint8_t)(e + 1);
  b = 0x00;
  /* nop */
  /* nop */
  e = (uint8_t)(e + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  e = (uint8_t)(e + 1);
  b = 0x00;
  /* nop */
  /* nop */
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b + 1);
  b = 0x00;
  /* nop */
  /* nop */
  e = (uint8_t)(e + 1);
  goto lab_p31_L_4AAA;
  lab_p31_L_4AAA: ;
  /* nop */
  c = (uint8_t)(c + 1);
  goto lab_p31_L_4AC2;
  lab_p31_L_4AC2: ;
  /* nop */
  cpu_ex_af();
  d = (uint8_t)(d + 1);
  c = (uint8_t)(c + 1);
  goto lab_p31_L_4ACE;
  lab_p31_L_4ACE: ;
  set_de(0x0806);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  cpu_rra();
  set_de(0x0611);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  cpu_rra();
  set_de(0x0A06);
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  cpu_rra();
  set_de(0x0106);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = 0x12;
  c = (uint8_t)(c - 1);
  b = 0x08;
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = 0x12;
  c = (uint8_t)(c - 1);
  b = 0x04;
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = 0x12;
  c = (uint8_t)(c - 1);
  b = 0x0A;
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = 0x12;
  c = (uint8_t)(c - 1);
  b = 0x02;
  cpu_rra();
  cpu_ex_af();
  c = 0x08;
  set_hl((uint16_t)(hl() + bc()));
  cpu_rra();
  b = 0x08;
  cpu_rra();
  cpu_ex_af();
  c = 0x08;
  set_hl((uint16_t)(hl() + bc()));
  cpu_rra();
  b = 0x04;
  a = mem_read8(bc());
  cpu_rra();
  cpu_ex_af();
  c = 0x08;
  cpu_rra();
  b = 0x0A;
  cpu_rra();
  cpu_ex_af();
  c = 0x08;
  set_hl((uint16_t)(hl() + bc()));
  cpu_rra();
  b = 0x02;
  b = (uint8_t)(b + 1);
  c = 0x11;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4B3E;
  b = 0x08;
  b = (uint8_t)(b + 1);
  c = 0x11;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4B46;
  b = 0x04;
  a = mem_read8(bc());
  /* nop */
  c = 0x13;
  e = (uint8_t)(e + 1);
  lab_p31_L_4B3E: ;
  cpu_rrca();
  b = 0x0A;
  /* nop */
  c = 0x11;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4B56;
  lab_p31_L_4B46: ;
  cpu_rrca();
  b = 0x02;
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  cpu_ex_af();
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  lab_p31_L_4B56: ;
  c = 0x06;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x04;
  b = (uint8_t)(b + 1);
  c = 0x06;
  a = mem_read8(bc());
  /* nop */
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  a = mem_read8(bc());
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  set_bc(0x110E);
  set_de(0x1111);
  c = 0x06;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4BA0;
  set_de(0x1111);
  set_de(0x060E);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x11;
  set_de(0x0E11);
  b = 0x0A;
  lab_p31_L_4BA0: ;
  a = mem_read8(bc());
  c = 0x11;
  set_de(0x1111);
  c = 0x06;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x11;
  set_de(0x060E);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x11;
  set_de(0x060E);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x11;
  set_de(0x060E);
  a = mem_read8(bc());
  /* nop */
  c = 0x11;
  set_de(0x0E11);
  b = 0x02;
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de(0x060E);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de(0x060E);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  set_de(0x1111);
  c = 0x06;
  a = mem_read8(bc());
  /* nop */
  set_de(0x1111);
  set_de(0x060E);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = 0x08;
  b = (uint8_t)(b + 1);
  /* nop */
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = 0x04;
  a = mem_read8(bc());
  /* nop */
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = 0x0A;
  /* nop */
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = 0x0E;
  set_de(0x1010);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4C17;
  e = 0x06;
  /* nop */
  /* nop */
  c = 0x11;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4C1F;
  e = 0x06;
  lab_p31_L_4C17: ;
  b = 0x05;
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  set_de(0x1519);
  set_de((uint16_t)(de() + 1));
  set_de(0x0506);
  lab_p31_L_4C1F: ;
  b = 0x05;
  a = mem_read8(bc());
  /* nop */
  d = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x10;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x01;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x00;
  a = mem_read8(bc());
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x04;
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  goto lab_p31_L_4C5F;
  lab_p31_L_4C5F: ;
  b = 0x00;
  /* nop */
  set_hl((uint16_t)(hl() + bc()));
  d = (uint8_t)(d - 1);
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  b = 0x04;
  a = mem_read8(bc());
  a = mem_read8(bc());
  set_de(0x1111);
  cpu_rra();
  b = 0x06;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  c = 0x11;
  set_de(0x060E);
  /* nop */
  /* nop */
  cpu_rrca();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4C8B;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4C8E;
  b = 0x07;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_rlca();
  b = 0x10;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  lab_p31_L_4C8B: ;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  lab_p31_L_4C8E: ;
  set_de(0x0006);
  /* nop */
  mem_write8(de(), a);
  mem_write8(de(), a);
  d = 0x19;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4C9E;
  /* nop */
  /* nop */
  cpu_rra();
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  lab_p31_L_4C9E: ;
  set_de((uint16_t)(de() - 1));
  b = 0x00;
  /* nop */
  c = 0x11;
  set_de(0x101E);
  b = 0x1F;
  set_de(0x0408);
  cpu_ex_af();
  set_de(0x061F);
  /* nop */
  /* nop */
  cpu_rrca();
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = 0x00;
  /* nop */
  cpu_rra();
  d = (uint8_t)(d + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  b = 0x00;
  b = (uint8_t)(b + 1);
  c = 0x15;
  d = (uint8_t)(d - 1);
  c = 0x04;
  b = 0x0E;
  set_de(0x1111);
  set_de(0x110A);
  b = 0x1F;
  /* nop */
  set_de(0x040A);
  a = mem_read8(bc());
  set_de(0x1F06);
  /* nop */
  set_de(0x040A);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4CE6;
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  lab_p31_L_4CE6: ;
  /* nop */
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  d = (uint8_t)(d - 1);
  b = 0x00;
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  cpu_rra();
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = 0x00;
  cpu_rra();
  set_de(0x1111);
  cpu_rra();
  /* nop */
  b = 0x01;
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4D0E;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  c = 0x00;
  lab_p31_L_4D0E: ;
  /* nop */
  b = 0x1C;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  /* nop */
  /* nop */
  /* nop */
  b = 0x1C;
  d = (uint8_t)(d + 1);
  e = (uint8_t)(e + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x1C;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  e = (uint8_t)(e + 1);
  /* nop */
  /* nop */
  /* nop */
  b = 0x18;
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  set_de((uint16_t)(de() - 1));
  b = 0x05;
  mem_write8(bc(), a);
  b = 0x00;
  set_bc(0x0600);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = 0x06;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  e = 0x09;
  c = 0x18;
  b = 0x00;
  /* nop */
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de((uint16_t)(de() + 1));
  b = 0x1F;
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_af();
  c = 0x0A;
  cpu_ex_af();
  goto lab_p31_L_4D56;
  lab_p31_L_4D56: ;
  c = 0x06;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  b = 0x11;
  set_hl((uint16_t)(hl() + de()));
  e = (uint8_t)(e - 1);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x12;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write8(de(), a);
  b = 0x00;
  e = (uint8_t)(e + 1);
  d = 0x17;
  d = 0x1C;
  /* nop */
  b = 0x1F;
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  b = 0x1F;
  set_de((uint16_t)(de() - 1));
  set_de(0x1B1B);
  set_de((uint16_t)(de() - 1));
  cpu_rra();
  b = 0x1F;
  set_de((uint16_t)(de() - 1));
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  set_de(0x1F15);
  b = 0x1F;
  cpu_rra();
  set_hl((uint16_t)(hl() + de()));
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  set_hl((uint16_t)(hl() + de()));
  cpu_rra();
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_rra();
  b = 0x04;
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_rra();
  b = 0x04;
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x0A;
  /* nop */
  cpu_rra();
  b = 0x00;
  b = 0x0A;
  a = mem_read8(bc());
  b = 0x00;
  cpu_rra();
  b = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4DBE;
  lab_p31_L_4DBE: ;
  /* nop */
  b = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rrca();
  a = mem_read8(de());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4DC7;
  lab_p31_L_4DC7: ;
  b = 0x1F;
  cpu_rra();
  cpu_rra();
  a = mem_read8(de());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4DCE;
  lab_p31_L_4DCE: ;
  /* nop */
  b = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rrca();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  b = 0x00;
  /* nop */
  cpu_rlca();
  c = (uint8_t)(c - 1);
  cpu_rla();
  /* nop */
  /* nop */
  b = 0x00;
  /* nop */
  cpu_rlca();
  b = (uint8_t)(b - 1);
  cpu_rlca();
  /* nop */
  /* nop */
  b = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4DEE;
  lab_p31_L_4DEE: ;
  /* nop */
  b = 0x04;
  c = 0x1F;
  set_de(0x1F11);
  /* nop */
  b = 0x00;
  cpu_rra();
  set_de(0x1F11);
  c = 0x04;
  b = 0x1F;
  c = 0x15;
  set_de((uint16_t)(de() - 1));
  d = (uint8_t)(d - 1);
  c = 0x1F;
  b = 0x0E;
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d + 1);
  c = 0x05;
  d = (uint8_t)(d - 1);
  c = 0x06;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x0A0A);
  a = mem_read8(bc());
  c = 0x06;
}

/* flash page 31 cpu 0x47D0 (offset 0x07D0) */
void p31_L_47D0(void) {
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_rra();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  goto lab_p31_L_47E6;
  lab_p31_L_47E6: ;
  /* nop */
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  goto lab_p31_L_4807;
  lab_p31_L_4807: ;
  b = 0x0E;
  set_de(0x0601);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_482E;
  b = 0x0E;
  set_de(0x0601);
  set_bc(0x0E11);
  b = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  set_de(0x1F11);
  set_bc(0x0601);
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4833;
  c = 0x01;
  set_de(0x060E);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_484A;
  set_de(0x0E11);
  lab_p31_L_482E: ;
  c = 0x06;
  b = 0x1F;
  cpu_rra();
  set_bc(0x0202);
  lab_p31_L_4833: ;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = 0x0E;
  set_de(0x0E11);
  set_de(0x0E11);
  b = 0x0E;
  set_de(0x0F11);
  set_bc(0x0402);
  b = 0x00;
  /* nop */
  lab_p31_L_484A: ;
  goto lab_p31_L_4864;
  lab_p31_L_4864: ;
  /* nop */
  cpu_rra();
  /* nop */
  b = 0x00;
  /* nop */
  goto lab_p31_L_4872;
  lab_p31_L_4872: ;
  set_bc((uint16_t)(bc() + 1));
  b = 0x04;
  /* nop */
  b = (uint8_t)(b + 1);
  b = 0x0E;
  set_de(0x1513);
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_488E;
  b = 0x04;
  a = mem_read8(bc());
  a = mem_read8(bc());
  set_de(0x111F);
  set_de(0x1E06);
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  c = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  lab_p31_L_488E: ;
  e = 0x06;
  c = 0x11;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_48A4;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_48A7;
  c = 0x06;
  e = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  e = 0x06;
  cpu_rra();
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_af();
  c = 0x08;
  lab_p31_L_48A4: ;
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  cpu_rra();
  lab_p31_L_48A7: ;
  b = 0x1F;
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_af();
  c = 0x08;
  cpu_ex_af();
  goto lab_p31_L_48B6;
  lab_p31_L_48B6: ;
  cpu_rrca();
  b = 0x19;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  cpu_rrca();
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x0E;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  set_bc((uint16_t)(bc() + 1));
  set_bc(0x0101);
  set_de(0x0E11);
  b = 0x19;
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x1C;
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  cpu_rra();
  b = 0x11;
  set_de((uint16_t)(de() - 1));
  cpu_rra();
  d = (uint8_t)(d - 1);
  set_de(0x1111);
  b = 0x11;
  set_hl((uint16_t)(hl() + de()));
  e = (uint8_t)(e - 1);
  cpu_rla();
  set_de((uint16_t)(de() + 1));
  set_de(0x0611);
  c = 0x11;
  set_de(0x1111);
  set_de(0x060E);
  e = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  c = 0x08;
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  b = 0x0E;
  set_de(0x1111);
  d = (uint8_t)(d - 1);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = 0x1E;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  c = 0x0A;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x0F;
  set_de(0x0E10);
  set_bc(0x1E11);
  b = 0x1F;
  d = (uint8_t)(d - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  set_de(0x1111);
  set_de(0x1111);
  c = 0x06;
  set_de(0x1111);
  set_de(0x0A11);
  b = (uint8_t)(b + 1);
  b = 0x11;
  set_de(0x1511);
  cpu_rra();
  set_de((uint16_t)(de() - 1));
  set_de(0x1106);
  a = mem_read8(bc());
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  set_de(0x1106);
  set_de(0x040A);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  cpu_rra();
  set_de(0x0402);
  cpu_ex_af();
  set_de(0x061F);
  c = 0x11;
  set_de(0x111F);
  set_de(0x060E);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4962;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  set_bc(0x1C06);
  b = (uint8_t)(b + 1);
  lab_p31_L_4962: ;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  e = (uint8_t)(e + 1);
  b = 0x04;
  a = mem_read8(bc());
  set_de(0x0000);
  /* nop */
  /* nop */
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_rra();
  b = 0x0C;
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x00;
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = 0x12;
  c = (uint8_t)(c - 1);
  b = 0x18;
  cpu_ex_af();
  c = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  e = 0x06;
  /* nop */
  /* nop */
  c = 0x11;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_49A7;
  c = 0x06;
  b = 0x02;
  c = 0x12;
  mem_write8(de(), a);
  mem_write8(de(), a);
  cpu_rrca();
  b = 0x00;
  /* nop */
  c = 0x11;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_49B6;
  lab_p31_L_49A7: ;
  b = 0x03;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_rrca();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  /* nop */
  /* nop */
  cpu_rrca();
  set_de(0x010F);
  lab_p31_L_49B6: ;
  e = 0x06;
  goto lab_p31_L_49C2;
  lab_p31_L_49C2: ;
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  set_bc(0x0300);
  set_bc(0x1101);
  c = 0x06;
  goto lab_p31_L_49DA;
  lab_p31_L_49DA: ;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  /* nop */
  /* nop */
  a = mem_read8(de());
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  set_de(0x0006);
  /* nop */
  d = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x00;
  /* nop */
  c = 0x11;
  set_de(0x0E11);
  b = 0x00;
  /* nop */
  e = 0x09;
  c = 0x08;
  goto lab_p31_L_4A06;
  lab_p31_L_4A06: ;
  set_bc((uint16_t)(bc() + 1));
  b = 0x00;
  /* nop */
  d = 0x09;
  cpu_ex_af();
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  b = 0x00;
  /* nop */
  cpu_rrca();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4A23;
  set_bc(0x061E);
  /* nop */
  cpu_ex_af();
  e = 0x08;
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  b = 0x06;
  /* nop */
  /* nop */
  set_de((uint16_t)(de() + 1));
  lab_p31_L_4A23: ;
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = 0x00;
  /* nop */
  set_de(0x0A11);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = 0x00;
  /* nop */
  set_de(0x1515);
  d = (uint8_t)(d - 1);
  a = mem_read8(bc());
  b = 0x00;
  /* nop */
  set_de(0x040A);
  a = mem_read8(bc());
  set_de(0x0006);
  /* nop */
  set_de(0x040A);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4A4E;
  /* nop */
  /* nop */
  cpu_rra();
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  lab_p31_L_4A4E: ;
  cpu_rra();
  b = 0x06;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = 0x06;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = 0x0C;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = 0x00;
  /* nop */
  set_hl((uint16_t)(hl() + bc()));
  d = (uint8_t)(d - 1);
  mem_write8(de(), a);
  /* nop */
  /* nop */
  b = 0x1F;
  cpu_rra();
  set_de(0x111F);
  cpu_rra();
  cpu_rra();
  b = 0x00;
  /* nop */
  /* nop */
  cpu_ex_af();
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  cpu_ex_af();
  b = 0x00;
  /* nop */
  /* nop */
  cpu_ex_af();
  goto lab_p31_L_4A8E;
  lab_p31_L_4A8E: ;
  e = (uint8_t)(e + 1);
  b = 0x00;
  /* nop */
  /* nop */
  e = (uint8_t)(e + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  e = (uint8_t)(e + 1);
  b = 0x00;
  /* nop */
  /* nop */
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b + 1);
  b = 0x00;
  /* nop */
  /* nop */
  e = (uint8_t)(e + 1);
  goto lab_p31_L_4AAA;
  lab_p31_L_4AAA: ;
  /* nop */
  c = (uint8_t)(c + 1);
  goto lab_p31_L_4AC2;
  lab_p31_L_4AC2: ;
  /* nop */
  cpu_ex_af();
  d = (uint8_t)(d + 1);
  c = (uint8_t)(c + 1);
  goto lab_p31_L_4ACE;
  lab_p31_L_4ACE: ;
  set_de(0x0806);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  cpu_rra();
  set_de(0x0611);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  cpu_rra();
  set_de(0x0A06);
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  cpu_rra();
  set_de(0x0106);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = 0x12;
  c = (uint8_t)(c - 1);
  b = 0x08;
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = 0x12;
  c = (uint8_t)(c - 1);
  b = 0x04;
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = 0x12;
  c = (uint8_t)(c - 1);
  b = 0x0A;
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = 0x12;
  c = (uint8_t)(c - 1);
  b = 0x02;
  cpu_rra();
  cpu_ex_af();
  c = 0x08;
  set_hl((uint16_t)(hl() + bc()));
  cpu_rra();
  b = 0x08;
  cpu_rra();
  cpu_ex_af();
  c = 0x08;
  set_hl((uint16_t)(hl() + bc()));
  cpu_rra();
  b = 0x04;
  a = mem_read8(bc());
  cpu_rra();
  cpu_ex_af();
  c = 0x08;
  cpu_rra();
  b = 0x0A;
  cpu_rra();
  cpu_ex_af();
  c = 0x08;
  set_hl((uint16_t)(hl() + bc()));
  cpu_rra();
  b = 0x02;
  b = (uint8_t)(b + 1);
  c = 0x11;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4B3E;
  b = 0x08;
  b = (uint8_t)(b + 1);
  c = 0x11;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4B46;
  b = 0x04;
  a = mem_read8(bc());
  /* nop */
  c = 0x13;
  e = (uint8_t)(e + 1);
  lab_p31_L_4B3E: ;
  cpu_rrca();
  b = 0x0A;
  /* nop */
  c = 0x11;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4B56;
  lab_p31_L_4B46: ;
  cpu_rrca();
  b = 0x02;
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  cpu_ex_af();
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  lab_p31_L_4B56: ;
  c = 0x06;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x04;
  b = (uint8_t)(b + 1);
  c = 0x06;
  a = mem_read8(bc());
  /* nop */
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  a = mem_read8(bc());
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x06;
  set_bc(0x110E);
  set_de(0x1111);
  c = 0x06;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4BA0;
  set_de(0x1111);
  set_de(0x060E);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x11;
  set_de(0x0E11);
  b = 0x0A;
  lab_p31_L_4BA0: ;
  a = mem_read8(bc());
  c = 0x11;
  set_de(0x1111);
  c = 0x06;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x11;
  set_de(0x060E);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x11;
  set_de(0x060E);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x11;
  set_de(0x060E);
  a = mem_read8(bc());
  /* nop */
  c = 0x11;
  set_de(0x0E11);
  b = 0x02;
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de(0x060E);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de(0x060E);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  set_de(0x1111);
  c = 0x06;
  a = mem_read8(bc());
  /* nop */
  set_de(0x1111);
  set_de(0x060E);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = 0x08;
  b = (uint8_t)(b + 1);
  /* nop */
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = 0x04;
  a = mem_read8(bc());
  /* nop */
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = 0x0A;
  /* nop */
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = 0x0E;
  set_de(0x1010);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4C17;
  e = 0x06;
  /* nop */
  /* nop */
  c = 0x11;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4C1F;
  e = 0x06;
  lab_p31_L_4C17: ;
  b = 0x05;
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  set_de(0x1519);
  set_de((uint16_t)(de() + 1));
  set_de(0x0506);
  lab_p31_L_4C1F: ;
  b = 0x05;
  a = mem_read8(bc());
  /* nop */
  d = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x10;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x01;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x00;
  a = mem_read8(bc());
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x04;
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  goto lab_p31_L_4C5F;
  lab_p31_L_4C5F: ;
  b = 0x00;
  /* nop */
  set_hl((uint16_t)(hl() + bc()));
  d = (uint8_t)(d - 1);
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  b = 0x04;
  a = mem_read8(bc());
  a = mem_read8(bc());
  set_de(0x1111);
  cpu_rra();
  b = 0x06;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  c = 0x11;
  set_de(0x060E);
  /* nop */
  /* nop */
  cpu_rrca();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4C8B;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4C8E;
  b = 0x07;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_rlca();
  b = 0x10;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  lab_p31_L_4C8B: ;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  lab_p31_L_4C8E: ;
  set_de(0x0006);
  /* nop */
  mem_write8(de(), a);
  mem_write8(de(), a);
  d = 0x19;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4C9E;
  /* nop */
  /* nop */
  cpu_rra();
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  lab_p31_L_4C9E: ;
  set_de((uint16_t)(de() - 1));
  b = 0x00;
  /* nop */
  c = 0x11;
  set_de(0x101E);
  b = 0x1F;
  set_de(0x0408);
  cpu_ex_af();
  set_de(0x061F);
  /* nop */
  /* nop */
  cpu_rrca();
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = 0x00;
  /* nop */
  cpu_rra();
  d = (uint8_t)(d + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  b = 0x00;
  b = (uint8_t)(b + 1);
  c = 0x15;
  d = (uint8_t)(d - 1);
  c = 0x04;
  b = 0x0E;
  set_de(0x1111);
  set_de(0x110A);
  b = 0x1F;
  /* nop */
  set_de(0x040A);
  a = mem_read8(bc());
  set_de(0x1F06);
  /* nop */
  set_de(0x040A);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4CE6;
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  lab_p31_L_4CE6: ;
  /* nop */
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  d = (uint8_t)(d - 1);
  b = 0x00;
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  cpu_rra();
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = 0x00;
  cpu_rra();
  set_de(0x1111);
  cpu_rra();
  /* nop */
  b = 0x01;
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4D0E;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  c = 0x00;
  lab_p31_L_4D0E: ;
  /* nop */
  b = 0x1C;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  /* nop */
  /* nop */
  /* nop */
  b = 0x1C;
  d = (uint8_t)(d + 1);
  e = (uint8_t)(e + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x1C;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  e = (uint8_t)(e + 1);
  /* nop */
  /* nop */
  /* nop */
  b = 0x18;
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  set_de((uint16_t)(de() - 1));
  b = 0x05;
  mem_write8(bc(), a);
  b = 0x00;
  set_bc(0x0600);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = 0x06;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  e = 0x09;
  c = 0x18;
  b = 0x00;
  /* nop */
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de((uint16_t)(de() + 1));
  b = 0x1F;
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_af();
  c = 0x0A;
  cpu_ex_af();
  goto lab_p31_L_4D56;
  lab_p31_L_4D56: ;
  c = 0x06;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  b = 0x11;
  set_hl((uint16_t)(hl() + de()));
  e = (uint8_t)(e - 1);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x12;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write8(de(), a);
  b = 0x00;
  e = (uint8_t)(e + 1);
  d = 0x17;
  d = 0x1C;
  /* nop */
  b = 0x1F;
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  b = 0x1F;
  set_de((uint16_t)(de() - 1));
  set_de(0x1B1B);
  set_de((uint16_t)(de() - 1));
  cpu_rra();
  b = 0x1F;
  set_de((uint16_t)(de() - 1));
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  set_de(0x1F15);
  b = 0x1F;
  cpu_rra();
  set_hl((uint16_t)(hl() + de()));
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  set_hl((uint16_t)(hl() + de()));
  cpu_rra();
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_rra();
  b = 0x04;
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_rra();
  b = 0x04;
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x0A;
  /* nop */
  cpu_rra();
  b = 0x00;
  b = 0x0A;
  a = mem_read8(bc());
  b = 0x00;
  cpu_rra();
  b = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4DBE;
  lab_p31_L_4DBE: ;
  /* nop */
  b = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rrca();
  a = mem_read8(de());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4DC7;
  lab_p31_L_4DC7: ;
  b = 0x1F;
  cpu_rra();
  cpu_rra();
  a = mem_read8(de());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4DCE;
  lab_p31_L_4DCE: ;
  /* nop */
  b = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rrca();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  b = 0x00;
  /* nop */
  cpu_rlca();
  c = (uint8_t)(c - 1);
  cpu_rla();
  /* nop */
  /* nop */
  b = 0x00;
  /* nop */
  cpu_rlca();
  b = (uint8_t)(b - 1);
  cpu_rlca();
  /* nop */
  /* nop */
  b = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4DEE;
  lab_p31_L_4DEE: ;
  /* nop */
  b = 0x04;
  c = 0x1F;
  set_de(0x1F11);
  /* nop */
  b = 0x00;
  cpu_rra();
  set_de(0x1F11);
  c = 0x04;
  b = 0x1F;
  c = 0x15;
  set_de((uint16_t)(de() - 1));
  d = (uint8_t)(d - 1);
  c = 0x1F;
  b = 0x0E;
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d + 1);
  c = 0x05;
  d = (uint8_t)(d - 1);
  c = 0x06;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x0A0A);
  a = mem_read8(bc());
  c = 0x06;
  b = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  set_de((uint16_t)(de() - 1));
  a = mem_read8(bc());
  set_hl((uint16_t)(hl() + bc()));
  set_de((uint16_t)(de() - 1));
}

/* flash page 31 cpu 0x4C20 (offset 0x0C20) */
void p31_L_4C20(void) {
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  /* nop */
  d = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x10;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x01;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x00;
  a = mem_read8(bc());
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x04;
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  goto lab_p31_L_4C5F;
  lab_p31_L_4C5F: ;
  b = 0x00;
  /* nop */
  set_hl((uint16_t)(hl() + bc()));
  d = (uint8_t)(d - 1);
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  b = 0x04;
  a = mem_read8(bc());
  a = mem_read8(bc());
  set_de(0x1111);
  cpu_rra();
  b = 0x06;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  c = 0x11;
  set_de(0x060E);
  /* nop */
  /* nop */
  cpu_rrca();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4C8B;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4C8E;
  b = 0x07;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_rlca();
  b = 0x10;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  lab_p31_L_4C8B: ;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  lab_p31_L_4C8E: ;
  set_de(0x0006);
  /* nop */
  mem_write8(de(), a);
  mem_write8(de(), a);
  d = 0x19;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4C9E;
  /* nop */
  /* nop */
  cpu_rra();
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  lab_p31_L_4C9E: ;
  set_de((uint16_t)(de() - 1));
  b = 0x00;
  /* nop */
  c = 0x11;
  set_de(0x101E);
  b = 0x1F;
  set_de(0x0408);
  cpu_ex_af();
  set_de(0x061F);
  /* nop */
  /* nop */
  cpu_rrca();
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = 0x00;
  /* nop */
  cpu_rra();
  d = (uint8_t)(d + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  b = 0x00;
  b = (uint8_t)(b + 1);
  c = 0x15;
  d = (uint8_t)(d - 1);
  c = 0x04;
  b = 0x0E;
  set_de(0x1111);
  set_de(0x110A);
  b = 0x1F;
  /* nop */
  set_de(0x040A);
  a = mem_read8(bc());
  set_de(0x1F06);
  /* nop */
  set_de(0x040A);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4CE6;
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  lab_p31_L_4CE6: ;
  /* nop */
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  d = (uint8_t)(d - 1);
  b = 0x00;
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  cpu_rra();
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = 0x00;
  cpu_rra();
  set_de(0x1111);
  cpu_rra();
  /* nop */
  b = 0x01;
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4D0E;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  c = 0x00;
  lab_p31_L_4D0E: ;
  /* nop */
  b = 0x1C;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  /* nop */
  /* nop */
  /* nop */
  b = 0x1C;
  d = (uint8_t)(d + 1);
  e = (uint8_t)(e + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = 0x1C;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  e = (uint8_t)(e + 1);
  /* nop */
  /* nop */
  /* nop */
  b = 0x18;
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  set_de((uint16_t)(de() - 1));
  b = 0x05;
  mem_write8(bc(), a);
  b = 0x00;
  set_bc(0x0600);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = 0x06;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  e = 0x09;
  c = 0x18;
  b = 0x00;
  /* nop */
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de((uint16_t)(de() + 1));
  b = 0x1F;
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_af();
  c = 0x0A;
  cpu_ex_af();
  goto lab_p31_L_4D56;
  lab_p31_L_4D56: ;
  c = 0x06;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  b = 0x11;
  set_hl((uint16_t)(hl() + de()));
  e = (uint8_t)(e - 1);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  b = 0x12;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write8(de(), a);
  b = 0x00;
  e = (uint8_t)(e + 1);
  d = 0x17;
  d = 0x1C;
  /* nop */
  b = 0x1F;
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  b = 0x1F;
  set_de((uint16_t)(de() - 1));
  set_de(0x1B1B);
  set_de((uint16_t)(de() - 1));
  cpu_rra();
  b = 0x1F;
  set_de((uint16_t)(de() - 1));
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  set_de(0x1F15);
  b = 0x1F;
  cpu_rra();
  set_hl((uint16_t)(hl() + de()));
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  set_hl((uint16_t)(hl() + de()));
  cpu_rra();
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_rra();
  b = 0x04;
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_rra();
  b = 0x04;
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x0A;
  /* nop */
  cpu_rra();
  b = 0x00;
  b = 0x0A;
  a = mem_read8(bc());
  b = 0x00;
  cpu_rra();
  b = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4DBE;
  lab_p31_L_4DBE: ;
  /* nop */
  b = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rrca();
  a = mem_read8(de());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4DC7;
  lab_p31_L_4DC7: ;
  b = 0x1F;
  cpu_rra();
  cpu_rra();
  a = mem_read8(de());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4DCE;
  lab_p31_L_4DCE: ;
  /* nop */
  b = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rrca();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  b = 0x00;
  /* nop */
  cpu_rlca();
  c = (uint8_t)(c - 1);
  cpu_rla();
  /* nop */
  /* nop */
  b = 0x00;
  /* nop */
  cpu_rlca();
  b = (uint8_t)(b - 1);
  cpu_rlca();
  /* nop */
  /* nop */
  b = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4DEE;
  lab_p31_L_4DEE: ;
  /* nop */
  b = 0x04;
  c = 0x1F;
  set_de(0x1F11);
  /* nop */
  b = 0x00;
  cpu_rra();
  set_de(0x1F11);
  c = 0x04;
  b = 0x1F;
  c = 0x15;
  set_de((uint16_t)(de() - 1));
  d = (uint8_t)(d - 1);
  c = 0x1F;
  b = 0x0E;
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d + 1);
  c = 0x05;
  d = (uint8_t)(d - 1);
  c = 0x06;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x0A0A);
  a = mem_read8(bc());
  c = 0x06;
  b = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  set_de((uint16_t)(de() - 1));
  a = mem_read8(bc());
  set_hl((uint16_t)(hl() + bc()));
  set_de((uint16_t)(de() - 1));
  b = 0x1C;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E3B;
  cpu_rla();
  b = 0x01;
  b = 0x06;
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E43;
  set_de((uint16_t)(de() + 1));
  b = 0x05;
  mem_write8(bc(), a);
  b = 0x1C;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E4B;
  cpu_rla();
  set_bc(0x0202);
  b = 0x1C;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E56;
  lab_p31_L_4E3B: ;
  d = (uint8_t)(d - 1);
  cpu_rlca();
  b = (uint8_t)(b - 1);
  b = 0x06;
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E5B;
  lab_p31_L_4E43: ;
  mem_write8(de(), a);
  b = (uint8_t)(b - 1);
  set_bc((uint16_t)(bc() + 1));
  b = 0x06;
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E63;
  lab_p31_L_4E4B: ;
  mem_write8(de(), a);
  b = (uint8_t)(b - 1);
  cpu_rlca();
  b = (uint8_t)(b - 1);
  b = 0x1C;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E71;
  d = (uint8_t)(d - 1);
  b = 0x05;
  lab_p31_L_4E56: ;
  b = 0x06;
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E73;
  lab_p31_L_4E5B: ;
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  b = 0x1C;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E7B;
  lab_p31_L_4E63: ;
  d = 0x05;
  b = (uint8_t)(b - 1);
  b = 0x06;
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E86;
  mem_write8(de(), a);
  set_bc((uint16_t)(bc() + 1));
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  b = 0x1C;
  lab_p31_L_4E71: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E8B;
  lab_p31_L_4E73: ;
  cpu_rla();
  b = (uint8_t)(b + 1);
  b = 0x04;
  p31_lcd_init();
  return;
  lab_p31_L_4E7B: ;
  c = mem_read8(hl());
  a = 0x01;
  p31_lcd_write_cmd();
  a = 0x05;
  p31_lcd_write_cmd();
  lab_p31_L_4E86: ;
  a = 0xF0;
  p31_lcd_write_cmd();
  lab_p31_L_4E8B: ;
  return;
}

/* flash page 31 cpu 0x4E20 (offset 0x0E20) */
void p31_L_4E20(void) {
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E3B;
  cpu_rla();
  b = 0x01;
  b = 0x06;
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E43;
  set_de((uint16_t)(de() + 1));
  b = 0x05;
  mem_write8(bc(), a);
  b = 0x1C;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E4B;
  cpu_rla();
  set_bc(0x0202);
  b = 0x1C;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E56;
  lab_p31_L_4E3B: ;
  d = (uint8_t)(d - 1);
  cpu_rlca();
  b = (uint8_t)(b - 1);
  b = 0x06;
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E5B;
  lab_p31_L_4E43: ;
  mem_write8(de(), a);
  b = (uint8_t)(b - 1);
  set_bc((uint16_t)(bc() + 1));
  b = 0x06;
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E63;
  lab_p31_L_4E4B: ;
  mem_write8(de(), a);
  b = (uint8_t)(b - 1);
  cpu_rlca();
  b = (uint8_t)(b - 1);
  b = 0x1C;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E71;
  d = (uint8_t)(d - 1);
  b = 0x05;
  lab_p31_L_4E56: ;
  b = 0x06;
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E73;
  lab_p31_L_4E5B: ;
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  b = 0x1C;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E7B;
  lab_p31_L_4E63: ;
  d = 0x05;
  b = (uint8_t)(b - 1);
  b = 0x06;
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E86;
  mem_write8(de(), a);
  set_bc((uint16_t)(bc() + 1));
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  b = 0x1C;
  lab_p31_L_4E71: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4E8B;
  lab_p31_L_4E73: ;
  cpu_rla();
  b = (uint8_t)(b + 1);
  b = 0x04;
  p31_lcd_init();
  return;
  lab_p31_L_4E7B: ;
  c = mem_read8(hl());
  a = 0x01;
  p31_lcd_write_cmd();
  a = 0x05;
  p31_lcd_write_cmd();
  lab_p31_L_4E86: ;
  a = 0xF0;
  p31_lcd_write_cmd();
  lab_p31_L_4E8B: ;
  return;
}

/* flash page 31 cpu 0x4E77 (offset 0x0E77) */
void p31_lcd_init(void) {
  a = 0x18;
  p31_lcd_write_cmd();
  a = 0x01;
  p31_lcd_write_cmd();
  a = 0x05;
  p31_lcd_write_cmd();
  a = 0xF0;
  p31_lcd_write_cmd();
  return;
}

/* flash page 31 cpu 0x4E8C (offset 0x0E8C) */
void p31_lcd_write_cmd(void) {
  /* CURATED -> lcd_write_cmd */
  lcd_write_cmd();
}

/* flash page 31 cpu 0x4E98 (offset 0x0E98) */
void p31_lcd_write_data(void) {
  /* CURATED -> lcd_write_data */
  lcd_write_data();
}

/* flash page 31 cpu 0x4EA4 (offset 0x0EA4) */
void p31_lcd_put(void) {
  cpu_push_af();
  cpu_push_bc();
  a = 0x80;
  p31_lcd_write_cmd();
  a = 0x20;
  lab_p31_L_4EAD: ;
  c = a;
  p31_lcd_write_cmd();
  b = 0x40;
  a = 0;
  flag_logic(a);
  lab_p31_L_4EB4: ;
  p31_lcd_write_data();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4EB4;
  a = c;
  a = (uint8_t)(a + 1);
  flag_cmp(a, 0x2C);
  if (flag_c()) goto lab_p31_L_4EAD;
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 31 cpu 0x4EC2 (offset 0x0EC2) */
void p31_lcd_put_2(void) {
  flag_cmp(a, 0xD6);
  if (flag_z()) { p31_L_4F14(); return; }
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  l = a;
  h = 0x00;
  cpu_ld_a_i();
  cpu_push_af();
  /* di */
  a = h;
  p31_lcd_write_cmd();
  a = mem_read8(0x844B);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + 0x80);
  p31_lcd_write_cmd();
  set_hl((uint16_t)(hl() + hl()));
  set_hl((uint16_t)(hl() + hl()));
  set_hl((uint16_t)(hl() + hl()));
  set_de(0x4678);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(0x844C);
  a = (uint8_t)(a + 0x20);
  p31_lcd_write_cmd();
  b = 0x07;
  lab_p31_L_4EF1: ;
  a = mem_read8(hl());
  cpu_rla();
  set_hl((uint16_t)(hl() + 1));
  p31_lcd_write_data();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_4EF1;
  a = mem_read8(0x844C);
  a = (uint8_t)(a + 1);
  mem_write8(0x844C, a);
  flag_cmp(a, 0x10);
  if (flag_nc()) p31_L_4F14();
  a = 0x01;
  p31_lcd_write_cmd();
  cpu_pop_af();
  if (flag_po()) goto lab_p31_L_4F0F;
  /* ei */
  lab_p31_L_4F0F: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 31 cpu 0x4F14 (offset 0x0F14) */
void p31_L_4F14(void) {
  cpu_push_af();
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = mem_read8(0x844B);
  a = (uint8_t)(a + 1);
  a = a & 0x07;
  flag_logic(a);
  mem_write8(0x844B, a);
  cpu_pop_af();
  return;
}

/* flash page 31 cpu 0x4F20 (offset 0x0F20) */
void p31_L_4F20(void) {
  c = e;
  a = (uint8_t)(a + h);
  cpu_pop_af();
  return;
}

/* flash page 31 cpu 0x4F24 (offset 0x0F24) */
void p31_L_4F24(void) {
  cpu_push_af();
  lab_p31_L_4F25: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p31_L_4F2F;
  p31_lcd_put_2();
  goto lab_p31_L_4F25;
  lab_p31_L_4F2F: ;
  cpu_pop_af();
  return;
}

/* flash page 31 cpu 0x4F60 (offset 0x0F60) */
void p31_L_4F60(void) {
  lab_p31_L_4F60: ;
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) return;
  set_de(mem_read16(0x8269));
  /* srl d */
  a = e;
  cpu_rra();
  d = a;
  cpu_rrca();
  cpu_rrca();
  a = (uint8_t)(a + 0xA5);
  e = a;
  a = d;
  d = 0x83;
  lab_p31_L_4F74: ;
  a = (uint8_t)(a + 0x04);
  cpu_ldi();
  if (flag_c()) goto lab_p31_L_4F8A;
  if (flag_pe()) goto lab_p31_L_4F74;
  a = (uint8_t)(a + a);
  mem_write8(0x8269, a);
  a = mem_read8(0x826A);
  cpu_rra();
  cpu_rlca();
  mem_write8(0x826A, a);
  return;
  lab_p31_L_4F8A: ;
  cpu_push_hl();
  cpu_push_bc();
  a = (uint8_t)(a + a);
  set_hl(0x8269);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  cpu_rra();
  cpu_rlca();
  a = (uint8_t)(a + 0x02);
  mem_write8(hl(), a);
  if (flag_nc()) goto lab_p31_L_4F9E;
  lab_p31_L_4F9A: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  if (flag_z()) goto lab_p31_L_4F9A;
  lab_p31_L_4F9E: ;
  set_hl(0x8292);
  set_de(0x8259);
  set_bc(0x0010);
  while (bc() != 0) { cpu_ldi(); }
  p31_L_51A3();
  set_hl(0x8259);
  set_de(0x8292);
  p31_L_4FFD();
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  p31_L_4FFD();
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  p31_L_4FFD();
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  p31_L_4FFD();
  cpu_pop_bc();
  cpu_pop_hl();
  goto lab_p31_L_4F60;
}

/* flash page 31 cpu 0x4FC8 (offset 0x0FC8) */
void p31_L_4FC8(void) {
  set_hl(0x8269);
  set_de(0x8251);
  set_bc(0x0008);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(0x4FFB);
  set_bc(0x0001);
  p31_L_4F60();
  set_hl((uint16_t)(hl() + 1));
  lab_p31_L_4FDD: ;
  a = mem_read8(0x8269);
  flag_cmp(a, 0xC0);
  if (flag_z()) goto lab_p31_L_4FEB;
  lab_p31_L_4FE4: ;
  set_hl((uint16_t)(hl() - 1));
  c = (uint8_t)(c + 1);
  p31_L_4F60();
  goto lab_p31_L_4FDD;
  lab_p31_L_4FEB: ;
  a = mem_read8(0x826A);
  a = a & 0x01;
  flag_logic(a);
  if (flag_z()) goto lab_p31_L_4FE4;
  set_hl(0x8251);
  set_bc(0x0008);
  p31_L_4F60();
  return;
}

/* flash page 31 cpu 0x4FFD (offset 0x0FFD) */
void p31_L_4FFD(void) {
  a = mem_read8(de());
  /* add a,(hl) */
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  /* adc a,(hl) */
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  /* adc a,(hl) */
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  /* adc a,(hl) */
  mem_write8(de(), a);
  return;
}

/* flash page 31 cpu 0x51A3 (offset 0x11A3) */
void p31_L_51A3(void) {
  set_hl(0x5010);
  b = 0x10;
  ix = 0x519F;
  lab_p31_L_51AC: ;
  p31_L_51D3();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_51AC;
  b = 0x10;
  ix = 0x519F;
  lab_p31_L_51B7: ;
  p31_L_5220();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_51B7;
  b = 0x10;
  ix = 0x519F;
  lab_p31_L_51C2: ;
  p31_L_523E();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_51C2;
  b = 0x10;
  ix = 0x519F;
  lab_p31_L_51CD: ;
  p31_L_5256();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_51CD;
  return;
}

/* flash page 31 cpu 0x51D3 (offset 0x11D3) */
void p31_L_51D3(void) {
  cpu_push_bc();
  cpu_push_hl();
  /* ld ixl,(ix+0x02) */
  h = 0x82;
  p31_L_527B();
  /* ld ixl,(ix+0x03) */
  p31_L_52A3();
  /* ld ixl,(ix+0x01) */
  p31_L_5283();
  /* ld ixl,(ix+0x03) */
  p31_L_52A3();
  p31_L_51EF();
  return;
}

/* flash page 31 cpu 0x51EF (offset 0x11EF) */
void p31_L_51EF(void) {
  /* ld ixl,(ix) */
  p31_L_52B3();
  cpu_pop_hl();
  cpu_push_hl();
  l = mem_read8(hl());
  h = 0x83;
  p31_L_52B3();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  p31_L_52B3();
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p31_L_52C3();
  /* ld ixl,(ix+0x01) */
  h = 0x82;
  p31_L_52B3();
  /* ld ixl,(ix) */
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), c);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), b);
  ix = (uint16_t)(ix - 1);
  cpu_pop_hl();
  cpu_pop_bc();
  return;
}

/* flash page 31 cpu 0x5220 (offset 0x1220) */
void p31_L_5220(void) {
  cpu_push_bc();
  cpu_push_hl();
  /* ld ixl,(ix+0x01) */
  h = 0x82;
  p31_L_527B();
  /* ld ixl,(ix+0x02) */
  p31_L_52A3();
  /* ld ixl,(ix+0x03) */
  p31_L_5283();
  /* ld ixl,(ix+0x02) */
  p31_L_52A3();
  p31_L_51EF();
  return;
}

/* flash page 31 cpu 0x523E (offset 0x123E) */
void p31_L_523E(void) {
  cpu_push_bc();
  cpu_push_hl();
  /* ld ixl,(ix+0x01) */
  h = 0x82;
  p31_L_527B();
  /* ld ixl,(ix+0x02) */
  p31_L_52A3();
  /* ld ixl,(ix+0x03) */
  p31_L_52A3();
  p31_L_51EF();
  return;
}

/* flash page 31 cpu 0x5256 (offset 0x1256) */
void p31_L_5256(void) {
  cpu_push_bc();
  cpu_push_hl();
  /* ld ixl,(ix+0x03) */
  h = 0x82;
  a = mem_read8(hl());
  a = a ^ 0xFF;
  e = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a ^ 0xFF;
  d = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a ^ 0xFF;
  c = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a ^ 0xFF;
  b = a;
  /* ld ixl,(ix+0x01) */
  p31_L_5293();
  /* ld ixl,(ix+0x02) */
  p31_L_52A3();
  p31_L_51EF();
  return;
}

/* flash page 31 cpu 0x527B (offset 0x127B) */
void p31_L_527B(void) {
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  return;
}

/* flash page 31 cpu 0x5283 (offset 0x1283) */
void p31_L_5283(void) {
  a = mem_read8(hl());
  a = a & e;
  flag_logic(a);
  e = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a & d;
  flag_logic(a);
  d = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a & c;
  flag_logic(a);
  c = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a & b;
  flag_logic(a);
  b = a;
  return;
}

/* flash page 31 cpu 0x5293 (offset 0x1293) */
void p31_L_5293(void) {
  a = mem_read8(hl());
  a = a | e;
  flag_logic(a);
  e = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | d;
  flag_logic(a);
  d = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | c;
  flag_logic(a);
  c = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | b;
  flag_logic(a);
  b = a;
  return;
}

/* flash page 31 cpu 0x52A3 (offset 0x12A3) */
void p31_L_52A3(void) {
  a = mem_read8(hl());
  a = a ^ e;
  flag_logic(a);
  e = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a ^ d;
  flag_logic(a);
  d = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a ^ c;
  flag_logic(a);
  c = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a ^ b;
  flag_logic(a);
  b = a;
  return;
}

/* flash page 31 cpu 0x52B3 (offset 0x12B3) */
void p31_L_52B3(void) {
  a = mem_read8(hl());
  a = (uint8_t)(a + e);
  e = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  /* adc a,d */
  d = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  /* adc a,c */
  c = a;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  /* adc a,b */
  b = a;
  return;
}

/* flash page 31 cpu 0x52C3 (offset 0x12C3) */
void p31_L_52C3(void) {
  lab_p31_L_52C3: ;
  a = (uint8_t)(a - 0x08);
  if (flag_c()) goto lab_p31_L_52CE;
  l = b;
  b = c;
  c = d;
  d = e;
  e = l;
  goto lab_p31_L_52C3;
  lab_p31_L_52CE: ;
  a = (uint8_t)(a + 0x08);
  if (flag_z()) return;
  l = a;
  a = b;
  b = l;
  cpu_ex_de_hl();
  lab_p31_L_52D5: ;
  set_hl((uint16_t)(hl() + hl()));
  /* rl c */
  cpu_rla();
  if (flag_nc()) goto lab_p31_L_52DC;
  l = (uint8_t)(l + 1);
  lab_p31_L_52DC: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_52D5;
  cpu_ex_de_hl();
  b = a;
  return;
}

/* flash page 31 cpu 0x52E1 (offset 0x12E1) */
void p31_L_52E1(void) {
  d = 0x00;
  set_hl(0x0000);
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  lab_p31_L_52E8: ;
  cpu_rra();
  if (flag_nc()) goto lab_p31_L_52EC;
  set_hl((uint16_t)(hl() + de()));
  lab_p31_L_52EC: ;
  /* sla e */
  /* rl d */
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p31_L_52E8;
  return;
}

/* flash page 31 cpu 0x52F4 (offset 0x12F4) */
void p31_L_52F4(void) {
  d = 0x00;
  cpu_push_bc();
  a = h;
  c = l;
  set_hl(0x0000);
  b = 0x10;
  lab_p31_L_52FE: ;
  /* sll c */
  cpu_rla();
  /* adc hl,hl */
  if (flag_c()) goto lab_p31_L_5311;
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p31_L_530B;
  set_hl((uint16_t)(hl() + de()));
  c = (uint8_t)(c - 1);
  lab_p31_L_530B: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_52FE;
  lab_p31_L_530D: ;
  d = a;
  e = c;
  cpu_pop_bc();
  return;
  lab_p31_L_5311: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_52FE;
  goto lab_p31_L_530D;
}

/* flash page 31 cpu 0x534F (offset 0x134F) */
void p31_L_534F(void) {
  l = a;
  h = c;
  mem_write16(0x8478, hl());
  /* ld c,ixh */
  /* ld b,ixl */
  mem_write16(0x847A, bc());
  return;
}

/* flash page 31 cpu 0x535D (offset 0x135D) */
void p31_mmu_set_bankA(void) {
  /* CURATED -> mmu_set_bank_a */
  mmu_set_bank_a(a);
}

/* flash page 31 cpu 0x536D (offset 0x136D) */
void p31_L_536D(void) {
  p31_L_53CB();
  a = a ^ 0xFF;
  a = a & 0x1F;
  flag_logic(a);
  mmu_set_bank_a(a);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p31_L_5390;
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p31_L_5396;
  lab_p31_L_537C: ;
  cpu_ldi();
  if (flag_po()) { os_banked_call(0x8125); return; }
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_z()) goto lab_p31_L_537C;
  a = h;
  a = (uint8_t)(a - 0x40);
  h = a;
  a = hw_in(PORT_MMU_A);
  a = (uint8_t)(a + 1);
  mmu_set_bank_a(a);
  goto lab_p31_L_537C;
  lab_p31_L_5390: ;
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p31_L_5396;
  while (bc() != 0) { cpu_ldi(); }
  lab_p31_L_5396: ;
  a = hw_in(PORT_MMU_A);
  cpu_push_af();
  a = 0x1F;
  mmu_set_bank_a(a);
  cpu_pop_af();
  return;
}

/* flash page 31 cpu 0x539F (offset 0x139F) */
void p31_L_539F(void) {
  return;
}

/* flash page 31 cpu 0x53A5 (offset 0x13A5) */
void p31_L_53A5(void) {
  a = 0x00;
  return;
}

/* flash page 31 cpu 0x53AC (offset 0x13AC) */
void p31_L_53AC(void) {
  return;
}

/* flash page 31 cpu 0x53AF (offset 0x13AF) */
void p31_L_53AF(void) {
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p31_L_53B5();
  return;
}

/* flash page 31 cpu 0x53B5 (offset 0x13B5) */
void p31_L_53B5(void) {
  set_hl(0x53C1);
  p31_L_4F24();
  set_hl(0x400F);
  p31_L_4F24();
  return;
}

/* flash page 31 cpu 0x53C1 (offset 0x13C1) */
void p31_str_1(void) {
  b = d;
  l = a;
  l = a;
  mem_write8(hl(), h);
  b = mem_read8(hl());
  mem_write8(hl(), d);
  h = l;
  h = l;
  if (flag_nz()) { p31_L_53CB(); return; }
  p31_L_53CB();
  return;
}

/* flash page 31 cpu 0x53CB (offset 0x13CB) */
void p31_L_53CB(void) {
  /* ex (sp),hl */
  cpu_push_de();
  cpu_push_bc();
  cpu_push_af();
  c = mem_read8(hl());
  b = 0x00;
  set_hl((uint16_t)(hl() + 1));
  set_de(0x8100);
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  os_banked_call(0x8100);
  return;
}

/* flash page 31 cpu 0x53DF (offset 0x13DF) */
void p31_L_53DF(void) {
  /* di */
  a = (uint8_t)(a - 0x07);
  if (flag_c()) return;
  set_hl(0x0000);
  if (flag_z()) goto lab_p31_L_53ED;
  b = a;
  lab_p31_L_53E9: ;
  set_hl((uint16_t)(hl() + hl()));
  l = (uint8_t)(l + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p31_L_53E9;
  lab_p31_L_53ED: ;
  a = 0x01;
  hw_out(PORT_ASYN, a);
  a = h;
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x16, a);
  a = 0;
  flag_logic(a);
  hw_out(PORT_ASYN, a);
  a = l;
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x16, a);
  return;
}

/* flash page 31 cpu 0x54DD (offset 0x14DD) */
void p31_L_54DD(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_56DD();
  return;
}

/* flash page 31 cpu 0x56DD (offset 0x16DD) */
void p31_L_56DD(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_56ED();
  return;
}

/* flash page 31 cpu 0x56ED (offset 0x16ED) */
void p31_L_56ED(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_58CB();
  return;
}

/* flash page 31 cpu 0x58CB (offset 0x18CB) */
void p31_L_58CB(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_5A01();
  return;
}

/* flash page 31 cpu 0x5A01 (offset 0x1A01) */
void p31_L_5A01(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_5B59();
  return;
}

/* flash page 31 cpu 0x5B59 (offset 0x1B59) */
void p31_L_5B59(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_5BB1();
  return;
}

/* flash page 31 cpu 0x5BB1 (offset 0x1BB1) */
void p31_L_5BB1(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_5D1F();
  return;
}

/* flash page 31 cpu 0x5D1F (offset 0x1D1F) */
void p31_L_5D1F(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_5DDD();
  return;
}

/* flash page 31 cpu 0x5DDD (offset 0x1DDD) */
void p31_L_5DDD(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_5E1F();
  return;
}

/* flash page 31 cpu 0x5E1F (offset 0x1E1F) */
void p31_L_5E1F(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_606E();
  return;
}

/* flash page 31 cpu 0x606E (offset 0x206E) */
void p31_L_606E(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_6163();
  return;
}

/* flash page 31 cpu 0x6163 (offset 0x2163) */
void p31_L_6163(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_616F();
  return;
}

/* flash page 31 cpu 0x616F (offset 0x216F) */
void p31_L_616F(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_6461();
  return;
}

/* flash page 31 cpu 0x6461 (offset 0x2461) */
void p31_L_6461(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_6564();
  return;
}

/* flash page 31 cpu 0x6564 (offset 0x2564) */
void p31_L_6564(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_65D6();
  return;
}

/* flash page 31 cpu 0x65D6 (offset 0x25D6) */
void p31_L_65D6(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_681F();
  return;
}

/* flash page 31 cpu 0x681F (offset 0x281F) */
void p31_L_681F(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_6974();
  return;
}

/* flash page 31 cpu 0x6974 (offset 0x2974) */
void p31_L_6974(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_6B62();
  return;
}

/* flash page 31 cpu 0x6B62 (offset 0x2B62) */
void p31_L_6B62(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_6E6F();
  return;
}

/* flash page 31 cpu 0x6E6F (offset 0x2E6F) */
void p31_L_6E6F(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_6E77();
  return;
}

/* flash page 31 cpu 0x6E77 (offset 0x2E77) */
void p31_L_6E77(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_6F44();
  return;
}

/* flash page 31 cpu 0x6F44 (offset 0x2F44) */
void p31_L_6F44(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_6F63();
  return;
}

/* flash page 31 cpu 0x6F63 (offset 0x2F63) */
void p31_L_6F63(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_6F6C();
  return;
}

/* flash page 31 cpu 0x6F6C (offset 0x2F6C) */
void p31_L_6F6C(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_7109();
  return;
}

/* flash page 31 cpu 0x7109 (offset 0x3109) */
void p31_L_7109(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_742E();
  return;
}

/* flash page 31 cpu 0x742E (offset 0x342E) */
void p31_L_742E(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_7564();
  return;
}

/* flash page 31 cpu 0x7564 (offset 0x3564) */
void p31_L_7564(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_75DD();
  return;
}

/* flash page 31 cpu 0x75DD (offset 0x35DD) */
void p31_L_75DD(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_76F3();
  return;
}

/* flash page 31 cpu 0x76F3 (offset 0x36F3) */
void p31_L_76F3(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_7835();
  return;
}

/* flash page 31 cpu 0x7835 (offset 0x3835) */
void p31_L_7835(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
}

/* flash page 31 cpu 0x7C70 (offset 0x3C70) */
void p31_L_7C70(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p31_L_7FF0();
  return;
}

/* flash page 31 cpu 0x7FF0 (offset 0x3FF0) */
void p31_L_7FF0(void) {
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  return;
}


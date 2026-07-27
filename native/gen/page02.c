/* Recovered from flash page 2 (mechanical ASM->C) */
/* cpu window 0x4000..0x7FFF prefix=p02_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p02_L_4000(void);
void p02_L_4002(void);
void p02_L_402C(void);
void p02_L_4032(void);
void p02_L_403C(void);
void p02_L_4040(void);
void p02_L_4044(void);
void p02_L_4049(void);
void p02_L_404D(void);
void p02_L_4051(void);
void p02_L_405A(void);
void p02_L_405E(void);
void p02_L_4064(void);
void p02_L_4068(void);
void p02_L_406C(void);
void p02_L_4077(void);
void p02_L_407E(void);
void p02_L_408A(void);
void p02_L_408E(void);
void p02_L_4090(void);
void p02_L_40BA(void);
void p02_L_40D5(void);
void p02_L_40E3(void);
void p02_L_4100(void);
void p02_L_4102(void);
void p02_L_4124(void);
void p02_L_4144(void);
void p02_L_4148(void);
void p02_L_416F(void);
void p02_L_4172(void);
void p02_L_41B4(void);
void p02_L_41B8(void);
void p02_L_41C7(void);
void p02_L_4206(void);
void p02_L_4250(void);
void p02_L_4264(void);
void p02_L_4266(void);
void p02_L_426C(void);
void p02_L_429D(void);
void p02_L_42F7(void);
void p02_L_4303(void);
void p02_L_4370(void);
void p02_L_43C3(void);
void p02_L_43E2(void);
void p02_L_43ED(void);
void p02_L_447A(void);
void p02_L_447D(void);
void p02_L_4488(void);
void p02_L_448F(void);
void p02_L_449E(void);
void p02_L_44C8(void);
void p02_L_44D4(void);
void p02_L_451A(void);
void p02_L_4520(void);
void p02_L_4525(void);
void p02_L_4529(void);
void p02_L_452B(void);
void p02_L_453E(void);
void p02_L_45E1(void);
void p02_L_45EB(void);
void p02_L_45EE(void);
void p02_L_4608(void);
void p02_L_4639(void);
void p02_L_464F(void);
void p02_L_4684(void);
void p02_L_470A(void);
void p02_L_4719(void);
void p02_L_4748(void);
void p02_L_475B(void);
void p02_L_4781(void);
void p02_L_4784(void);
void p02_L_4785(void);
void p02_L_4795(void);
void p02_L_479B(void);
void p02_L_479E(void);
void p02_L_47A2(void);
void p02_L_47AE(void);
void p02_L_47B1(void);
void p02_L_47B5(void);
void p02_L_47BD(void);
void p02_L_47C0(void);
void p02_L_47C6(void);
void p02_L_47D8(void);
void p02_L_47DC(void);
void p02_L_47F3(void);
void p02_L_4801(void);
void p02_L_4805(void);
void p02_L_48DA(void);
void p02_L_48F8(void);
void p02_L_4950(void);
void p02_L_495E(void);
void p02_L_4969(void);
void p02_L_498C(void);
void p02_L_49B2(void);
void p02_L_49BE(void);
void p02_L_49C8(void);
void p02_L_49CD(void);
void p02_L_49DF(void);
void p02_L_4A01(void);
void p02_L_4A24(void);
void p02_L_4A45(void);
void p02_L_4AD3(void);
void p02_L_4B39(void);
void p02_L_4BED(void);
void p02_L_4C45(void);
void p02_L_4C49(void);
void p02_L_4C59(void);
void p02_L_4C72(void);
void p02_L_4CD1(void);
void p02_L_4CDB(void);
void p02_L_4D13(void);
void p02_L_4D14(void);
void p02_L_4DB8(void);
void p02_L_4DCD(void);
void p02_L_4DCF(void);
void p02_L_4E89(void);
void p02_L_4E95(void);
void p02_L_4EB6(void);
void p02_L_4ECE(void);
void p02_L_4F53(void);
void p02_L_4F82(void);
void p02_L_4FA0(void);
void p02_L_4FCB(void);
void p02_L_5007(void);
void p02_L_5028(void);
void p02_L_509B(void);
void p02_L_50A3(void);
void p02_L_512F(void);
void p02_L_5167(void);
void p02_L_5177(void);
void p02_L_51A0(void);
void p02_L_52E4(void);
void p02_L_5301(void);
void p02_L_5316(void);
void p02_L_531C(void);
void p02_L_5365(void);
void p02_L_536B(void);
void p02_L_53AF(void);
void p02_L_53C6(void);
void p02_L_53EA(void);
void p02_L_53F1(void);
void p02_L_544E(void);
void p02_L_5503(void);
void p02_L_550B(void);
void p02_L_5601(void);
void p02_L_5604(void);
void p02_L_561F(void);
void p02_L_5646(void);
void p02_L_5649(void);
void p02_L_56EF(void);
void p02_L_57DF(void);
void p02_L_57EF(void);
void p02_L_5891(void);
void p02_L_58B4(void);
void p02_L_592C(void);
void p02_L_5936(void);
void p02_L_594A(void);
void p02_L_59B1(void);
void p02_L_59BF(void);
void p02_L_59D5(void);
void p02_L_59F8(void);
void p02_L_59FB(void);
void p02_L_5A0F(void);
void p02_L_5A17(void);
void p02_L_5A1D(void);
void p02_L_5A22(void);
void p02_L_5A32(void);
void p02_L_5A4B(void);
void p02_L_5A53(void);
void p02_L_5B6B(void);
void p02_L_5B6E(void);
void p02_L_5B71(void);
void p02_L_5BED(void);
void p02_L_5BFB(void);
void p02_L_5C61(void);
void p02_L_5D20(void);
void p02_L_5D27(void);
void p02_L_5D32(void);
void p02_L_5D4A(void);
void p02_L_5E10(void);
void p02_L_5E18(void);
void p02_L_5E21(void);
void p02_L_5EF2(void);
void p02_L_5EF5(void);
void p02_L_5EF6(void);
void p02_L_5EF8(void);
void p02_L_5F7F(void);
void p02_L_5F9A(void);
void p02_L_5FC3(void);
void p02_L_5FDA(void);
void p02_L_5FE4(void);
void p02_L_6029(void);
void p02_L_6042(void);
void p02_L_604C(void);
void p02_L_6100(void);
void p02_L_6136(void);
void p02_L_614E(void);
void p02_L_6156(void);
void p02_L_6163(void);
void p02_L_616F(void);
void p02_L_6179(void);
void p02_L_620A(void);
void p02_L_62A9(void);
void p02_L_6341(void);
void p02_L_6347(void);
void p02_L_638E(void);
void p02_L_639D(void);
void p02_L_63A6(void);
void p02_L_63B3(void);
void p02_L_63EC(void);
void p02_L_640F(void);
void p02_L_641B(void);
void p02_L_6430(void);
void p02_L_6452(void);
void p02_L_64AB(void);
void p02_L_64C5(void);
void p02_L_6520(void);
void p02_L_6534(void);
void p02_L_6539(void);
void p02_L_653D(void);
void p02_L_655D(void);
void p02_L_656B(void);
void p02_L_6585(void);
void p02_L_658F(void);
void p02_L_65BE(void);
void p02_L_65C4(void);
void p02_L_65D4(void);
void p02_L_65D6(void);
void p02_L_65EE(void);
void p02_L_65F8(void);
void p02_L_6603(void);
void p02_L_660A(void);
void p02_L_66D3(void);
void p02_L_673A(void);
void p02_L_67A5(void);
void p02_L_67A9(void);
void p02_L_67D4(void);
void p02_L_67E5(void);
void p02_L_6869(void);
void p02_L_68CD(void);
void p02_L_68F8(void);
void p02_L_6910(void);
void p02_L_6966(void);
void p02_L_6969(void);
void p02_L_69EF(void);
void p02_L_6A02(void);
void p02_L_6A1E(void);
void p02_L_6A26(void);
void p02_L_6A2E(void);
void p02_L_6A44(void);
void p02_L_6A9E(void);
void p02_L_6AB3(void);
void p02_L_6AB9(void);
void p02_L_6AC8(void);
void p02_L_6AFB(void);
void p02_L_6B01(void);
void p02_L_6B0E(void);
void p02_L_6B60(void);
void p02_L_6B62(void);
void p02_L_6B6D(void);
void p02_L_6B7D(void);
void p02_L_6B8C(void);
void p02_L_6B8F(void);
void p02_L_6B9F(void);
void p02_L_6BE5(void);
void p02_L_6C02(void);
void p02_L_6C23(void);
void p02_L_6C38(void);
void p02_L_6C56(void);
void p02_L_6C63(void);
void p02_L_6C77(void);
void p02_L_6CC7(void);
void p02_L_6D0B(void);
void p02_L_6D0E(void);
void p02_L_6D17(void);
void p02_L_6D3D(void);
void p02_L_6D46(void);
void p02_L_6D49(void);
void p02_L_6D7C(void);
void p02_L_6E0B(void);
void p02_L_6E15(void);
void p02_L_6E20(void);
void p02_L_6E24(void);
void p02_L_6E29(void);
void p02_L_6F1A(void);
void p02_L_6F6A(void);
void p02_L_6F74(void);
void p02_L_6F77(void);
void p02_L_702B(void);
void p02_L_71C5(void);
void p02_L_71CD(void);
void p02_L_720F(void);
void p02_L_7210(void);
void p02_L_7213(void);
void p02_L_7220(void);
void p02_L_7228(void);
void p02_L_722B(void);
void p02_L_724C(void);
void p02_L_7250(void);
void p02_L_7254(void);
void p02_L_7258(void);
void p02_L_7397(void);
void p02_L_73C9(void);
void p02_L_7462(void);
void p02_L_74E7(void);
void p02_L_74FE(void);
void p02_L_7534(void);
void p02_L_7538(void);
void p02_L_753C(void);
void p02_L_7540(void);
void p02_L_75BB(void);
void p02_L_75C9(void);
void p02_L_75CA(void);
void p02_L_75D7(void);
void p02_L_75E2(void);
void p02_L_75ED(void);
void p02_L_75F7(void);
void p02_L_75FF(void);
void p02_L_7657(void);
void p02_L_7659(void);
void p02_L_76B4(void);
void p02_L_77DA(void);
void p02_L_77EB(void);
void p02_L_7817(void);
void p02_L_7835(void);
void p02_L_783E(void);
void p02_L_7852(void);
void p02_L_7864(void);
void p02_L_7872(void);
void p02_L_78CC(void);
void p02_L_78CD(void);
void p02_L_78D3(void);
void p02_L_78DB(void);
void p02_L_78E1(void);
void p02_L_78FF(void);
void p02_L_791C(void);
void p02_L_7925(void);
void p02_L_794A(void);
void p02_L_79E4(void);
void p02_L_7AD2(void);
void p02_L_7B96(void);
void p02_L_7BC8(void);
void p02_L_7C13(void);

/* flash page 2 cpu 0x4000 (offset 0x0000) */
void p02_L_4000(void) {
  c = 0x01;
  p02_L_4002();
  return;
}

/* flash page 2 cpu 0x4002 (offset 0x0002) */
void p02_L_4002(void) {
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_400B;
  lab_p02_L_4006: ;
  a = 0x78;
  p00_L_255F();
  return;
  lab_p02_L_400B: ;
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_4006;
  a = mem_read8(de());
  l = a;
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  a = 0;
  flag_logic(a);
  h = a;
  goto lab_p02_L_401B;
  lab_p02_L_4017: ;
  a = (uint8_t)(a + l);
  if (flag_nc()) goto lab_p02_L_401B;
  h = (uint8_t)(h + 1);
  lab_p02_L_401B: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_4017;
  c = (uint8_t)(c - 1);
  a = (uint8_t)(a + c);
  if (flag_nc()) goto lab_p02_L_4022;
  h = (uint8_t)(h + 1);
  lab_p02_L_4022: ;
  l = a;
  p00_L_1025();
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 2 cpu 0x402C (offset 0x002C) */
void p02_L_402C(void) {
  set_de(mem_read16(0x84D7));
  p02_L_4044();
  return;
}

/* flash page 2 cpu 0x4032 (offset 0x0032) */
void p02_L_4032(void) {
  set_bc(mem_read16(0x84B3));
  set_de(mem_read16(0x84D5));
  p02_L_4044();
  return;
}

/* flash page 2 cpu 0x403C (offset 0x003C) */
void p02_L_403C(void) {
  set_bc(mem_read16(0x84AF));
  p02_L_4040();
  return;
}

/* flash page 2 cpu 0x4040 (offset 0x0040) */
void p02_L_4040(void) {
  set_de(mem_read16(0x84D3));
  p02_L_4044();
  return;
}

/* flash page 2 cpu 0x4044 (offset 0x0044) */
void p02_L_4044(void) {
  p02_L_4002();
  p00_rst20();
  return;
}

/* flash page 2 cpu 0x4049 (offset 0x0049) */
void p02_L_4049(void) {
  set_bc(mem_read16(0x84B3));
  p02_L_404D();
  return;
}

/* flash page 2 cpu 0x404D (offset 0x004D) */
void p02_L_404D(void) {
  set_de(mem_read16(0x84D5));
  p02_L_4051();
  return;
}

/* flash page 2 cpu 0x4051 (offset 0x0051) */
void p02_L_4051(void) {
  p02_L_4002();
  set_de(0x8483);
  p00_L_1183();
  return;
}

/* flash page 2 cpu 0x405A (offset 0x005A) */
void p02_L_405A(void) {
  set_bc(mem_read16(0x84AF));
  p02_L_405E();
  return;
}

/* flash page 2 cpu 0x405E (offset 0x005E) */
void p02_L_405E(void) {
  set_de(mem_read16(0x84D3));
  p02_L_406C();
  return;
}

/* flash page 2 cpu 0x4064 (offset 0x0064) */
void p02_L_4064(void) {
  set_bc(mem_read16(0x84B7));
  p02_L_4068();
  return;
}

/* flash page 2 cpu 0x4068 (offset 0x0068) */
void p02_L_4068(void) {
  set_de(mem_read16(0x84D7));
  p02_L_406C();
  return;
}

/* flash page 2 cpu 0x406C (offset 0x006C) */
void p02_L_406C(void) {
  p02_L_4002();
  cpu_push_hl();
  p00_L_15FB();
  cpu_pop_de();
  p00_L_11FD();
  return;
}

/* flash page 2 cpu 0x4077 (offset 0x0077) */
void p02_L_4077(void) {
  set_bc(mem_read16(0x84AF));
  p02_L_4068();
  p02_L_407E();
  return;
}

/* flash page 2 cpu 0x407E (offset 0x007E) */
void p02_L_407E(void) {
  set_hl(0x84AF);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) return;
  a = mem_read8(0x84B7);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  return;
}

/* flash page 2 cpu 0x408A (offset 0x008A) */
void p02_L_408A(void) {
  a = 0x01;
  goto lab_p02_L_408F;
  lab_p02_L_408F: ;
  a = a | a;
  flag_logic(a);
  p02_L_4090();
  return;
}

/* flash page 2 cpu 0x408E (offset 0x008E) */
void p02_L_408E(void) {
  a = 0;
  flag_logic(a);
  a = a | a;
  flag_logic(a);
  p02_L_4090();
  return;
}

/* flash page 2 cpu 0x4090 (offset 0x0090) */
void p02_L_4090(void) {
  cpu_push_af();
  lab_p02_L_4091: ;
  p02_L_403C();
  set_bc(mem_read16(0x84AF));
  p02_L_404D();
  cpu_pop_af();
  if (flag_nc()) goto lab_p02_L_40A4;
  cpu_push_af();
  p00_L_0ED0();
  goto lab_p02_L_40AD;
  lab_p02_L_40A4: ;
  cpu_push_af();
  if (flag_z()) p00_L_0C34();
  cpu_pop_af();
  cpu_push_af();
  if (flag_nz()) p00_L_0C2D();
  lab_p02_L_40AD: ;
  p02_L_4077();
  set_hl(mem_read16(0x84AF));
  mem_write16(0x84B3, hl());
  if (flag_nz()) goto lab_p02_L_4091;
  cpu_pop_af();
  return;
}

/* flash page 2 cpu 0x40BA (offset 0x00BA) */
void p02_L_40BA(void) {
  set_hl(mem_read16(0x84B7));
  cpu_push_hl();
  set_bc(mem_read16(0x84B3));
  cpu_push_bc();
  p00_L_128A();
  p00_L_1171();
  p02_L_403C();
  p02_L_4049();
  p00_L_0D1F();
  p00_L_1108();
  p02_L_40D5();
  return;
}

/* flash page 2 cpu 0x40D5 (offset 0x00D5) */
void p02_L_40D5(void) {
  goto lab_p02_L_40D5;
  lab_p02_L_40C3: ;
  p00_L_128A();
  lab_p02_L_40C6: ;
  p00_L_1171();
  p02_L_403C();
  p02_L_4049();
  p00_L_0D1F();
  p00_L_1108();
  lab_p02_L_40D5: ;
  p00_rst30();
  cpu_pop_bc();
  cpu_push_bc();
  set_hl(0x84AF);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  cpu_push_hl();
  set_hl(0x84B4);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  cpu_pop_de();
  if (flag_nz()) goto lab_p02_L_40C6;
  mem_write8(hl(), b);
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  cpu_ex_de_hl();
  mem_write8(hl(), b);
  if (flag_nz()) goto lab_p02_L_40EF;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  cpu_ex_de_hl();
  mem_write8(hl(), c);
  lab_p02_L_40EF: ;
  p02_L_4064();
  set_hl(0x84B7);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) goto lab_p02_L_40C3;
  cpu_pop_bc();
  cpu_push_bc();
  mem_write8(hl(), c);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) goto lab_p02_L_40C3;
  cpu_pop_bc();
  p02_L_4100();
  return;
}

/* flash page 2 cpu 0x40E3 (offset 0x00E3) */
void p02_L_40E3(void) {
  goto lab_p02_L_40E3;
  lab_p02_L_40C3: ;
  p00_L_128A();
  p00_L_1171();
  p02_L_403C();
  p02_L_4049();
  p00_L_0D1F();
  p00_L_1108();
  p02_L_40D5();
  return;
  lab_p02_L_40E3: ;
  if (flag_po()) { p00_L_2B70(); return; }
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  cpu_ex_de_hl();
  mem_write8(hl(), b);
  if (flag_nz()) goto lab_p02_L_40EF;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  cpu_ex_de_hl();
  mem_write8(hl(), c);
  lab_p02_L_40EF: ;
  p02_L_4064();
  set_hl(0x84B7);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) goto lab_p02_L_40C3;
  cpu_pop_bc();
  cpu_push_bc();
  mem_write8(hl(), c);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) goto lab_p02_L_40C3;
  cpu_pop_bc();
  p02_L_4100();
  return;
}

/* flash page 2 cpu 0x4100 (offset 0x0100) */
void p02_L_4100(void) {
  cpu_pop_bc();
  return;
}

/* flash page 2 cpu 0x4102 (offset 0x0102) */
void p02_L_4102(void) {
  set_bc(mem_read16(0x84B7));
  mem_write16(0x84AF, bc());
  p00_L_1229();
  lab_p02_L_410D: ;
  p02_L_4077();
  if (flag_z()) return;
  set_hl(0x847A);
  mem_write8(hl(), 0x00);
  a = mem_read8(0x84AF);
  b = a;
  a = mem_read8(0x84B0);
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p02_L_410D;
  mem_write8(hl(), 0x10);
  goto lab_p02_L_410D;
}

/* flash page 2 cpu 0x4124 (offset 0x0124) */
void p02_L_4124(void) {
  set_hl(mem_read16(0x84AF));
  cpu_push_hl();
  lab_p02_L_4128: ;
  p02_L_403C();
  set_hl(mem_read16(0x84AF));
  b = l;
  c = h;
  p02_L_4068();
  set_hl(0x84AF);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) goto lab_p02_L_4128;
  cpu_pop_bc();
  cpu_push_bc();
  mem_write8(hl(), c);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) goto lab_p02_L_4128;
  cpu_pop_hl();
  b = l;
  c = h;
  return;
}

/* flash page 2 cpu 0x4144 (offset 0x0144) */
void p02_L_4144(void) {
  set_de(mem_read16(0x84D7));
  p02_L_4148();
  return;
}

/* flash page 2 cpu 0x4148 (offset 0x0148) */
void p02_L_4148(void) {
  a = mem_read8(de());
  l = a;
  h = 0x00;
  p00_L_1025();
  cpu_push_hl();
  a = mem_read8(0x84B3);
  b = a;
  cpu_push_de();
  p02_L_4000();
  cpu_pop_de();
  cpu_push_hl();
  a = mem_read8(0x84B4);
  b = a;
  p02_L_4000();
  cpu_pop_de();
  cpu_pop_bc();
  lab_p02_L_4163: ;
  cpu_push_bc();
  b = c;
  p00_L_14B8();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_m()) return;
  c = 0x00;
  goto lab_p02_L_4163;
}

/* flash page 2 cpu 0x416F (offset 0x016F) */
void p02_L_416F(void) {
  a = 0;
  flag_logic(a);
  goto lab_p02_L_4179;
  lab_p02_L_4179: ;
  mem_write8(0x84AF, a);
  a = mem_read8(0x84B7);
  mem_write8(0x84B5, a);
  lab_p02_L_4182: ;
  set_hl(0x84B3);
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  c = mem_read8(hl());
  cpu_push_bc();
  p02_L_402C();
  a = mem_read8(0x84AF);
  a = (uint8_t)(a - 0x01);
  if (flag_c()) goto lab_p02_L_419E;
  cpu_push_af();
  p00_L_1108();
  p00_L_0D1F();
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_41A9;
  lab_p02_L_419E: ;
  p00_rst08();
  cpu_pop_bc();
  a = mem_read8(0x84B4);
  b = a;
  cpu_push_bc();
  p02_L_402C();
  p00_rst30();
  lab_p02_L_41A9: ;
  cpu_pop_bc();
  p02_L_4068();
  set_hl(0x84B5);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) goto lab_p02_L_4182;
  return;
}

/* flash page 2 cpu 0x4172 (offset 0x0172) */
void p02_L_4172(void) {
  a = 0x01;
  cpu_push_af();
  p00_L_1171();
  cpu_pop_af();
  mem_write8(0x84AF, a);
  a = mem_read8(0x84B7);
  mem_write8(0x84B5, a);
  lab_p02_L_4182: ;
  set_hl(0x84B3);
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  c = mem_read8(hl());
  cpu_push_bc();
  p02_L_402C();
  a = mem_read8(0x84AF);
  a = (uint8_t)(a - 0x01);
  if (flag_c()) goto lab_p02_L_419E;
  cpu_push_af();
  p00_L_1108();
  p00_L_0D1F();
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_41A9;
  lab_p02_L_419E: ;
  p00_rst08();
  cpu_pop_bc();
  a = mem_read8(0x84B4);
  b = a;
  cpu_push_bc();
  p02_L_402C();
  p00_rst30();
  lab_p02_L_41A9: ;
  cpu_pop_bc();
  p02_L_4068();
  set_hl(0x84B5);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) goto lab_p02_L_4182;
  return;
}

/* flash page 2 cpu 0x41B4 (offset 0x01B4) */
void p02_L_41B4(void) {
  goto lab_p02_L_41B4;
  lab_p02_L_4174: ;
  cpu_push_af();
  p00_L_1171();
  cpu_pop_af();
  mem_write8(0x84AF, a);
  a = mem_read8(0x84B7);
  mem_write8(0x84B5, a);
  lab_p02_L_4182: ;
  set_hl(0x84B3);
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  c = mem_read8(hl());
  cpu_push_bc();
  p02_L_402C();
  a = mem_read8(0x84AF);
  a = (uint8_t)(a - 0x01);
  if (flag_c()) goto lab_p02_L_419E;
  cpu_push_af();
  p00_L_1108();
  p00_L_0D1F();
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_41A9;
  lab_p02_L_419E: ;
  p00_rst08();
  cpu_pop_bc();
  a = mem_read8(0x84B4);
  b = a;
  cpu_push_bc();
  p02_L_402C();
  p00_rst30();
  lab_p02_L_41A9: ;
  cpu_pop_bc();
  p02_L_4068();
  set_hl(0x84B5);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) goto lab_p02_L_4182;
  return;
  lab_p02_L_41B4: ;
  a = 0x02;
  goto lab_p02_L_4174;
}

/* flash page 2 cpu 0x41B8 (offset 0x01B8) */
void p02_L_41B8(void) {
  p00_L_1100();
  p00_L_22F7();
  p00_L_1078();
  cpu_push_af();
  p00_L_113F();
  cpu_pop_af();
  return;
}

/* flash page 2 cpu 0x41C7 (offset 0x01C7) */
void p02_L_41C7(void) {
  cpu_push_af();
  cpu_push_bc();
  p02_L_403C();
  p00_L_15D6();
  p00_L_1100();
  lab_p02_L_41D2: ;
  a = mem_read8(0x84B0);
  cpu_pop_bc();
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p02_L_41DB;
  cpu_pop_af();
  return;
  lab_p02_L_41DB: ;
  cpu_push_bc();
  a = (uint8_t)(a + 1);
  mem_write8(0x84B0, a);
  p02_L_403C();
  p00_L_10F8();
  p00_L_1078();
  if (flag_c()) goto lab_p02_L_41D2;
  if (flag_z()) goto lab_p02_L_41D2;
  p02_L_403C();
  p00_L_15D6();
  p00_L_1100();
  cpu_pop_bc();
  cpu_pop_af();
  a = a ^ 0x01;
  flag_logic(a);
  cpu_push_af();
  cpu_push_bc();
  c = b;
  b = a;
  a = mem_read8(0x84B0);
  p02_L_43C3();
  goto lab_p02_L_41D2;
}

/* flash page 2 cpu 0x4206 (offset 0x0206) */
void p02_L_4206(void) {
  lab_p02_L_4206: ;
  cpu_push_bc();
  set_hl(mem_read16(0x84D5));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  c = b;
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() - 1));
  b = c;
  lab_p02_L_4212: ;
  a = mem_read8(hl());
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p02_L_421B;
  set_hl((uint16_t)(hl() - 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_4212;
  cpu_pop_bc();
  return;
  lab_p02_L_421B: ;
  a = b;
  lab_p02_L_421C: ;
  set_hl((uint16_t)(hl() - 1));
  b = (uint8_t)(b - 1);
  cpu_cp_hl();
  if (flag_nz()) goto lab_p02_L_421C;
  c = a;
  cpu_push_bc();
  a = b;
  p02_L_4250();
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  lab_p02_L_422A: ;
  cpu_push_af();
  cpu_push_bc();
  b = a;
  set_de(mem_read16(0x84D3));
  p02_L_4002();
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  c = b;
  b = a;
  cpu_push_hl();
  set_de(mem_read16(0x84D3));
  p02_L_4002();
  cpu_pop_de();
  b = 0x09;
  p00_L_14B8();
  cpu_pop_bc();
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p02_L_422A;
  cpu_pop_bc();
  goto lab_p02_L_4206;
}

/* flash page 2 cpu 0x4250 (offset 0x0250) */
void p02_L_4250(void) {
  d = 0x00;
  e = a;
  set_hl(mem_read16(0x84D5));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  cpu_sbc_hl_de();
  e = c;
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_de();
  a = mem_read8(de());
  b = mem_read8(hl());
  mem_write8(hl(), a);
  a = b;
  mem_write8(de(), a);
  return;
}

/* flash page 2 cpu 0x4264 (offset 0x0264) */
void p02_L_4264(void) {
  a = 0x01;
  p02_L_4266();
  return;
}

/* flash page 2 cpu 0x4266 (offset 0x0266) */
void p02_L_4266(void) {
  mem_write8(0x84B3, a);
  p00_L_128A();
  p02_L_426C();
  return;
}

/* flash page 2 cpu 0x426C (offset 0x026C) */
void p02_L_426C(void) {
  set_hl(0x84B3);
  lab_p02_L_426F: ;
  c = mem_read8(hl());
  a = mem_read8(0x84B0);
  b = a;
  a = mem_read8(0x84B4);
  cpu_cp_hl();
  if (flag_c()) return;
  cpu_push_bc();
  p00_L_1171();
  cpu_pop_bc();
  p02_L_4040();
  set_bc(mem_read16(0x84AF));
  a = mem_read8(0x84B3);
  b = a;
  set_de(mem_read16(0x84D3));
  p02_L_4051();
  p00_L_0D1F();
  p00_L_1108();
  p00_rst30();
  set_hl(0x84B3);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p02_L_426F;
}

/* flash page 2 cpu 0x429D (offset 0x029D) */
void p02_L_429D(void) {
  cpu_push_af();
  set_hl(mem_read16(0x84AF));
  a = h;
  flag_cmp(a, l);
  if (flag_nz()) { p00_L_24ED(); return; }
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p02_L_42B6;
  p02_L_403C();
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  p00_L_0ECC();
  p02_L_405A();
  return;
  lab_p02_L_42B6: ;
  cpu_push_hl();
  set_hl(mem_read16(0x84AF));
  cpu_push_hl();
  p02_L_4608();
  cpu_pop_hl();
  mem_write16(0x84AF, hl());
  mem_write16(0x84B7, hl());
  h = 0x00;
  p00_L_3B55();
  p00_L_0D1F();
  p00_L_1221();
  a = 0x73;
  mem_write8(0x8484, a);
  p00_L_0D1F();
  p00_L_21E5();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_42EF;
  c = h;
  b = 0x00;
  set_hl(mem_read16(0x84D5));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + bc()));
  b = c;
  lab_p02_L_42EB: ;
  mem_write8(hl(), b);
  set_hl((uint16_t)(hl() - 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_42EB;
  lab_p02_L_42EF: ;
  set_bc(0x0000);
  mem_write16(0x84AF, bc());
  cpu_pop_af();
  p02_L_42F7();
  return;
}

/* flash page 2 cpu 0x42F7 (offset 0x02F7) */
void p02_L_42F7(void) {
  cpu_pop_hl();
  cpu_push_hl();
  a = a & 0x6F;
  flag_logic(a);
  cpu_push_af();
  c = b;
  c = (uint8_t)(c + 1);
  a = b;
  b = c;
  mem_write8(0x84B4, a);
  p02_L_4303();
  return;
}

/* flash page 2 cpu 0x4303 (offset 0x0303) */
void p02_L_4303(void) {
  goto lab_p02_L_4303;
  lab_p02_L_42F6: ;
  cpu_pop_af();
  p02_L_42F7();
  return;
  lab_p02_L_4303: ;
  mem_write16(0x84AF, bc());
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) goto lab_p02_L_4323;
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p02_L_431A;
  p00_L_1229();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 7));
  cpu_push_af();
  goto lab_p02_L_4346;
  lab_p02_L_431A: ;
  a = c;
  p02_L_4266();
  p00_L_0E4C();
  goto lab_p02_L_4346;
  lab_p02_L_4323: ;
  p02_L_4264();
  p02_L_447D();
  cpu_pop_af();
  flag_set_z((a & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p02_L_4345;
  a = a | a;
  flag_logic(a);
  a = (uint8_t)(a | (1u << 7));
  cpu_push_af();
  p02_L_405A();
  lab_p02_L_4335: ;
  cpu_pop_af();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_af();
  l = a;
  set_bc(mem_read16(0x84AF));
  a = h;
  flag_cmp(a, b);
  if (flag_z()) goto lab_p02_L_4373;
  b = (uint8_t)(b + 1);
  goto lab_p02_L_4303;
  lab_p02_L_4345: ;
  cpu_push_af();
  lab_p02_L_4346: ;
  set_bc(mem_read16(0x84AF));
  c = b;
  set_de(mem_read16(0x84D3));
  p02_L_4051();
  p00_L_0ED0();
  p02_L_405A();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_bc();
  flag_set_z((b & (1u << 5)) == 0);
  if (flag_z()) goto lab_p02_L_4366;
  set_hl(0x84B4);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p02_L_4335;
  lab_p02_L_4366: ;
  a = h;
  set_bc(mem_read16(0x84AF));
  flag_cmp(a, c);
  if (flag_z()) goto lab_p02_L_42F6;
  c = (uint8_t)(c + 1);
  p02_L_4370();
  return;
  lab_p02_L_4373: ;
  flag_cmp(a, c);
  if (flag_z()) goto lab_p02_L_437F;
  cpu_pop_af();
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) goto lab_p02_L_438E;
  b = c;
  p02_L_42F7();
  return;
  lab_p02_L_437F: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) { p02_L_43E2(); return; }
  p02_L_41B8();
  if (flag_c()) goto lab_p02_L_43AB;
  p02_L_43E2();
  return;
  lab_p02_L_438E: ;
  a = a | 0x10;
  flag_logic(a);
  cpu_push_bc();
  cpu_push_af();
  a = b;
  b = c;
  mem_write16(0x84AF, bc());
  c = a;
  cpu_pop_af();
  p02_L_41C7();
  cpu_push_af();
  p00_L_113F();
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_43AB;
  p02_L_41B8();
  if (flag_nc()) goto lab_p02_L_43B9;
  lab_p02_L_43AB: ;
  cpu_pop_af();
  cpu_pop_bc();
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_z()) { p00_L_24C5(); return; }
  cpu_pop_af();
  p00_L_21A7();
  p00_L_128A();
  return;
  lab_p02_L_43B9: ;
  cpu_pop_af();
  cpu_pop_bc();
  cpu_push_af();
  b = c;
  c = (uint8_t)(c + 1);
  a = a & 0x08;
  flag_logic(a);
  p02_L_4370();
  return;
}

/* flash page 2 cpu 0x4370 (offset 0x0370) */
void p02_L_4370(void) {
  p02_L_4303();
  return;
}

/* flash page 2 cpu 0x43C3 (offset 0x03C3) */
void p02_L_43C3(void) {
  flag_set_z((b & (1u << 6)) == 0);
  if (flag_z()) p02_L_4250();
  set_de(mem_read16(0x84D3));
  a = c;
  mem_write8(0x84B3, a);
  a = mem_read8(0x84B4);
  cpu_push_af();
  a = mem_read8(0x84B0);
  mem_write8(0x84B4, a);
  p02_L_4148();
  cpu_pop_af();
  mem_write8(0x84B4, a);
  return;
}

/* flash page 2 cpu 0x43E2 (offset 0x03E2) */
void p02_L_43E2(void) {
  cpu_pop_af();
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_z()) goto lab_p02_L_4409;
  cpu_push_af();
  p00_L_21A7();
  cpu_pop_af();
  cpu_pop_hl();
  p02_L_43ED();
  return;
  lab_p02_L_4409: ;
  cpu_pop_hl();
  cpu_push_hl();
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p02_L_4417;
  a = (uint8_t)(a | (1u << 5));
  set_bc(0x0000);
  p02_L_42F7();
  return;
  lab_p02_L_4417: ;
  p00_L_21A7();
  lab_p02_L_441A: ;
  cpu_pop_hl();
  cpu_push_hl();
  set_bc(mem_read16(0x84AF));
  b = (uint8_t)(b - 1);
  if (flag_z()) goto lab_p02_L_4446;
  c = h;
  lab_p02_L_4424: ;
  mem_write16(0x84AF, bc());
  l = b;
  l = (uint8_t)(l + 1);
  h = c;
  h = (uint8_t)(h - 1);
  mem_write16(0x84B3, hl());
  p02_L_403C();
  p02_L_426C();
  p00_L_0E4C();
  p02_L_405A();
  set_bc(mem_read16(0x84AF));
  c = (uint8_t)(c - 1);
  a = c;
  flag_cmp(a, b);
  if (flag_z()) goto lab_p02_L_441A;
  goto lab_p02_L_4424;
  lab_p02_L_4446: ;
  b = 0x01;
  cpu_pop_af();
  cpu_push_af();
  mem_write8(0x84B4, a);
  lab_p02_L_444D: ;
  c = 0x01;
  lab_p02_L_444F: ;
  p00_L_128A();
  mem_write16(0x84AF, bc());
  a = c;
  b = (uint8_t)(b + 1);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p02_L_445C;
  a = b;
  lab_p02_L_445C: ;
  mem_write8(0x84B3, a);
  if (flag_c()) p02_L_403C();
  p02_L_426C();
  p02_L_405A();
  set_bc(mem_read16(0x84AF));
  a = mem_read8(0x84B4);
  flag_cmp(a, c);
  if (flag_z()) goto lab_p02_L_4475;
  c = (uint8_t)(c + 1);
  goto lab_p02_L_444F;
  lab_p02_L_4475: ;
  b = (uint8_t)(b + 1);
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p02_L_444D;
  cpu_pop_bc();
  p02_L_447A();
  return;
}

/* flash page 2 cpu 0x43ED (offset 0x03ED) */
void p02_L_43ED(void) {
  cpu_push_af();
  p00_L_1229();
  lab_p02_L_43F1: ;
  p00_rst08();
  p02_L_403C();
  p00_L_0D1F();
  set_hl(0x84B0);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_z()) goto lab_p02_L_4402;
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  goto lab_p02_L_43F1;
  lab_p02_L_4402: ;
  cpu_pop_af();
  a = a & 0x01;
  flag_logic(a);
  if (flag_nz()) { p00_L_0E4C(); return; }
  return;
}

/* flash page 2 cpu 0x447A (offset 0x047A) */
void p02_L_447A(void) {
  p02_L_4206();
  return;
}

/* flash page 2 cpu 0x447D (offset 0x047D) */
void p02_L_447D(void) {
  p00_rst08();
  p02_L_403C();
  p00_L_0C2D();
  return;
}

/* flash page 2 cpu 0x4488 (offset 0x0488) */
void p02_L_4488(void) {
  mem_write8(0x84B4, a);
  a = 0x09;
  p02_L_448F();
  return;
}

/* flash page 2 cpu 0x448F (offset 0x048F) */
void p02_L_448F(void) {
  mem_write8(0x84B3, a);
  lab_p02_L_4492: ;
  p02_L_403C();
  p02_L_449E();
  p02_L_4077();
  if (flag_nz()) goto lab_p02_L_4492;
  return;
}

/* flash page 2 cpu 0x449E (offset 0x049E) */
void p02_L_449E(void) {
  a = mem_read8(0x84B3);
  flag_cmp(a, 0x04);
  if (flag_z()) { p00_L_15D6(); return; }
  flag_cmp(a, 0x06);
  if (flag_c()) { p00_L_0E4C(); return; }
  if (flag_z()) { p00_L_0C0F(); return; }
  flag_cmp(a, 0x08);
  if (flag_c()) { p00_L_0E72(); return; }
  if (flag_z()) { p00_L_0BF9(); return; }
  flag_cmp(a, 0x0A);
  if (flag_z()) { p00_L_0D1E(); return; }
  a = mem_read8(0x84B4);
  d = a;
  flag_cmp(a, 0x80);
  if (flag_nz()) { p00_L_0FB1(); return; }
  p02_L_65D4();
  return;
}

/* flash page 2 cpu 0x44C8 (offset 0x04C8) */
void p02_L_44C8(void) {
  a = mem_read8(0x84AF);
  mem_write8(0x84B7, a);
  lab_p02_L_44CE: ;
  p02_L_4077();
  if (flag_nz()) goto lab_p02_L_44CE;
  return;
}

/* flash page 2 cpu 0x44D4 (offset 0x04D4) */
void p02_L_44D4(void) {
  a = mem_read8(0x84B7);
  b = a;
  a = mem_read8(0x84B3);
  c = a;
  cpu_push_bc();
  lab_p02_L_44DD: ;
  p02_L_4032();
  p02_L_4064();
  a = mem_read8(0x84B7);
  a = (uint8_t)(a - 1);
  mem_write8(0x84B7, a);
  a = mem_read8(0x84B3);
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p02_L_44F5;
  mem_write8(0x84B3, a);
  goto lab_p02_L_44DD;
  lab_p02_L_44F5: ;
  set_bc(mem_read16(0x84B7));
  p02_L_4040();
  p02_L_4064();
  set_hl(mem_read16(0x84B7));
  l = (uint8_t)(l - 1);
  if (flag_z()) goto lab_p02_L_450A;
  mem_write16(0x84B7, hl());
  goto lab_p02_L_44F5;
  lab_p02_L_450A: ;
  cpu_pop_bc();
  h = (uint8_t)(h - 1);
  if (flag_z()) return;
  l = c;
  mem_write16(0x84B3, hl());
  l = b;
  mem_write16(0x84B7, hl());
  cpu_push_bc();
  goto lab_p02_L_44DD;
}

/* flash page 2 cpu 0x451A (offset 0x051A) */
void p02_L_451A(void) {
  set_de(mem_read16(0x84D7));
  p02_L_452B();
  return;
}

/* flash page 2 cpu 0x4520 (offset 0x0520) */
void p02_L_4520(void) {
  set_hl(mem_read16(0x84D3));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p02_L_4525();
  return;
}

/* flash page 2 cpu 0x4525 (offset 0x0525) */
void p02_L_4525(void) {
  set_de(mem_read16(0x84D7));
  p02_L_4529();
  return;
}

/* flash page 2 cpu 0x4529 (offset 0x0529) */
void p02_L_4529(void) {
  a = 0x02;
  p02_L_452B();
  return;
}

/* flash page 2 cpu 0x452B (offset 0x052B) */
void p02_L_452B(void) {
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  set_hl(mem_read16(0x84D3));
  p00_L_210A();
  b = d;
  c = e;
  set_bc((uint16_t)(bc() - 1));
  set_bc((uint16_t)(bc() - 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_de();
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 2 cpu 0x453E (offset 0x053E) */
void p02_L_453E(void) {
  p00_L_187F();
  p00_L_3B5B();
  set_hl(0x00FF);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) { p00_L_24C9(); return; }
  a = e;
  cpu_push_af();
  p00_L_113F();
  p02_L_59D5();
  cpu_push_af();
  a = h;
  flag_cmp(a, l);
  if (flag_nz()) { p00_L_24ED(); return; }
  cpu_pop_af();
  if (flag_z()) goto lab_p02_L_4566;
  p02_L_5A17();
  p02_L_4525();
  goto lab_p02_L_4569;
  lab_p02_L_4566: ;
  p00_L_21D6();
  lab_p02_L_4569: ;
  set_hl(mem_read16(0x84AF));
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_4579;
  mem_write16(0x84B7, hl());
  p02_L_4102();
  p00_L_219B();
  return;
  lab_p02_L_4579: ;
  d = a;
  b = 0x08;
  lab_p02_L_457C: ;
  b = (uint8_t)(b - 1);
  cpu_rla();
  if (flag_nc()) goto lab_p02_L_457C;
  cpu_push_bc();
  cpu_push_de();
  set_hl(mem_read16(0x84D7));
  mem_write16(0x84D3, hl());
  mem_write16(0x84D5, hl());
  set_hl(mem_read16(0x84AF));
  cpu_push_hl();
  p02_L_5A1D();
  p02_L_5936();
  set_bc(0x0100);
  lab_p02_L_4598: ;
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_af();
  a = a & b;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_45A9;
  cpu_push_hl();
  cpu_push_bc();
  p02_L_45EB();
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  /* sla b */
  goto lab_p02_L_4598;
  lab_p02_L_45A9: ;
  cpu_push_bc();
  cpu_push_hl();
  p00_L_1C7B();
  mem_write16(0x84D9, de());
  p02_L_4529();
  p00_L_21D6();
  lab_p02_L_45B8: ;
  cpu_pop_hl();
  cpu_pop_bc();
  lab_p02_L_45BA: ;
  cpu_pop_de();
  cpu_pop_af();
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p02_L_45CB;
  p00_L_2196();
  p00_L_22FC();
  p00_L_2333();
  p02_L_5B6B();
  return;
  lab_p02_L_45CB: ;
  cpu_push_af();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_hl();
  p02_L_45EB();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  c = (uint8_t)(c + 1);
  /* sla b */
  a = a & b;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_45BA;
  cpu_push_bc();
  cpu_push_hl();
  set_de(mem_read16(0x84D9));
  mem_write16(0x84D3, de());
  p02_L_45EE();
  goto lab_p02_L_45B8;
}

/* flash page 2 cpu 0x45E1 (offset 0x05E1) */
void p02_L_45E1(void) {
  goto lab_p02_L_45E1;
  lab_p02_L_45B8: ;
  cpu_pop_hl();
  cpu_pop_bc();
  lab_p02_L_45BA: ;
  cpu_pop_de();
  cpu_pop_af();
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p02_L_45CB;
  p00_L_2196();
  p00_L_22FC();
  p00_L_2333();
  p02_L_5B6B();
  return;
  lab_p02_L_45CB: ;
  cpu_push_af();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_hl();
  p02_L_45EB();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  c = (uint8_t)(c + 1);
  /* sla b */
  a = a & b;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_45BA;
  cpu_push_bc();
  cpu_push_hl();
  set_de(mem_read16(0x84D9));
  lab_p02_L_45E1: ;
  a = (uint8_t)(a + h);
  mem_write16(0x84D3, de());
  p02_L_45EE();
  goto lab_p02_L_45B8;
}

/* flash page 2 cpu 0x45EB (offset 0x05EB) */
void p02_L_45EB(void) {
  p00_L_171E();
  p02_L_45EE();
  return;
}

/* flash page 2 cpu 0x45EE (offset 0x05EE) */
void p02_L_45EE(void) {
  p02_L_53F1();
  p02_L_40BA();
  set_hl(mem_read16(0x84D7));
  set_de(mem_read16(0x84D3));
  mem_write16(0x84D3, hl());
  p02_L_4529();
  set_hl(mem_read16(0x84D5));
  mem_write16(0x84D3, hl());
  return;
}

/* flash page 2 cpu 0x4608 (offset 0x0608) */
void p02_L_4608(void) {
  a = mem_read8(0x84AF);
  mem_write8(0x84B7, a);
  p00_L_128A();
  p00_L_21E5();
  lab_p02_L_4614: ;
  p00_rst08();
  p02_L_403C();
  p00_L_0BF1();
  a = mem_read8(0x84AF);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p02_L_4631;
  p00_L_22F7();
  p00_L_1100();
  p00_L_107E();
  if (flag_nc()) p00_L_232E();
  p00_L_128A();
  lab_p02_L_4631: ;
  p02_L_407E();
  if (flag_nz()) goto lab_p02_L_4614;
  p00_L_219B();
  return;
}

/* flash page 2 cpu 0x4639 (offset 0x0639) */
void p02_L_4639(void) {
  cpu_push_af();
  set_hl(mem_read16(0x84AF));
  cpu_push_hl();
  l = h;
  mem_write16(0x84AF, hl());
  p02_L_4608();
  cpu_pop_hl();
  mem_write16(0x84AF, hl());
  mem_write16(0x84B7, hl());
  l = h;
  goto lab_p02_L_4663;
  lab_p02_L_4663: ;
  h = 0x00;
  p00_L_3B55();
  p00_L_0D1F();
  p00_L_1221();
  a = 0x73;
  mem_write8(0x8484, a);
  p00_L_0D1F();
  p00_rst18();
  set_bc(0x0101);
  mem_write16(0x84AF, bc());
  cpu_push_bc();
  a = mem_read8(0x84B0);
  b = a;
  a = mem_read8(0x84B8);
  c = a;
  a = (uint8_t)(a | (1u << 6));
  p02_L_41C7();
  p00_L_22F7();
  p00_L_113F();
  p00_L_107E();
  cpu_pop_bc();
  cpu_push_bc();
  if (flag_c()) goto lab_p02_L_469B;
  if (flag_nz()) goto lab_p02_L_46AE;
  lab_p02_L_469B: ;
  cpu_push_bc();
  p00_L_128A();
  p02_L_405E();
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  a = mem_read8(0x84B8);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p02_L_469B;
  cpu_pop_bc();
  p02_L_470A();
  return;
  lab_p02_L_46AE: ;
  mem_write16(0x84AF, bc());
  p02_L_403C();
  p00_rst18();
  cpu_pop_bc();
  lab_p02_L_46B7: ;
  cpu_push_bc();
  set_de(mem_read16(0x84D3));
  p02_L_4044();
  p00_L_22F7();
  p00_L_0ED0();
  cpu_pop_bc();
  cpu_push_bc();
  p02_L_405E();
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  if (flag_z()) goto lab_p02_L_46D4;
  a = mem_read8(0x84B7);
  flag_cmp(a, c);
  if (flag_nc()) goto lab_p02_L_46B7;
  lab_p02_L_46D4: ;
  p00_L_219B();
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p02_L_46EC;
  a = 0x01;
  set_hl(0x84B4);
  mem_write8(hl(), a);
  lab_p02_L_46E1: ;
  a = mem_read8(0x84B0);
  cpu_cp_hl();
  if (flag_z()) goto lab_p02_L_46EC;
  p02_L_4719();
  goto lab_p02_L_46E1;
  lab_p02_L_46EC: ;
  a = mem_read8(0x84B0);
  a = (uint8_t)(a + 1);
  set_hl(0x84B4);
  mem_write8(hl(), a);
  lab_p02_L_46F4: ;
  a = mem_read8(0x84B8);
  cpu_cp_hl();
  if (flag_c()) goto lab_p02_L_46FF;
  p02_L_4719();
  goto lab_p02_L_46F4;
  lab_p02_L_46FF: ;
  set_bc(mem_read16(0x84AF));
  b = (uint8_t)(b + 1);
  a = mem_read8(0x84B8);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p02_L_4714;
  p02_L_470A();
  return;
  lab_p02_L_4714: ;
  p00_L_21A7();
  cpu_pop_af();
  return;
}

/* flash page 2 cpu 0x464F (offset 0x064F) */
void p02_L_464F(void) {
  cpu_push_af();
  set_hl(mem_read16(0x84AF));
  cpu_push_hl();
  p02_L_4608();
  cpu_pop_hl();
  mem_write16(0x84AF, hl());
  mem_write16(0x84B7, hl());
  a = h;
  flag_cmp(a, l);
  if (flag_c()) goto lab_p02_L_4663;
  l = h;
  lab_p02_L_4663: ;
  h = 0x00;
  p00_L_3B55();
  p00_L_0D1F();
  p00_L_1221();
  a = 0x73;
  mem_write8(0x8484, a);
  p00_L_0D1F();
  p00_rst18();
  set_bc(0x0101);
  mem_write16(0x84AF, bc());
  cpu_push_bc();
  a = mem_read8(0x84B0);
  b = a;
  a = mem_read8(0x84B8);
  c = a;
  a = (uint8_t)(a | (1u << 6));
  p02_L_41C7();
  p00_L_22F7();
  p00_L_113F();
  p00_L_107E();
  cpu_pop_bc();
  cpu_push_bc();
  if (flag_c()) goto lab_p02_L_469B;
  if (flag_nz()) goto lab_p02_L_46AE;
  lab_p02_L_469B: ;
  cpu_push_bc();
  p00_L_128A();
  p02_L_405E();
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  a = mem_read8(0x84B8);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p02_L_469B;
  cpu_pop_bc();
  p02_L_470A();
  return;
  lab_p02_L_46AE: ;
  mem_write16(0x84AF, bc());
  p02_L_403C();
  p00_rst18();
  cpu_pop_bc();
  lab_p02_L_46B7: ;
  cpu_push_bc();
  set_de(mem_read16(0x84D3));
  p02_L_4044();
  p00_L_22F7();
  p00_L_0ED0();
  cpu_pop_bc();
  cpu_push_bc();
  p02_L_405E();
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  if (flag_z()) goto lab_p02_L_46D4;
  a = mem_read8(0x84B7);
  flag_cmp(a, c);
  if (flag_nc()) goto lab_p02_L_46B7;
  lab_p02_L_46D4: ;
  p00_L_219B();
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p02_L_46EC;
  a = 0x01;
  set_hl(0x84B4);
  mem_write8(hl(), a);
  lab_p02_L_46E1: ;
  a = mem_read8(0x84B0);
  cpu_cp_hl();
  if (flag_z()) goto lab_p02_L_46EC;
  p02_L_4719();
  goto lab_p02_L_46E1;
  lab_p02_L_46EC: ;
  a = mem_read8(0x84B0);
  a = (uint8_t)(a + 1);
  set_hl(0x84B4);
  mem_write8(hl(), a);
  lab_p02_L_46F4: ;
  a = mem_read8(0x84B8);
  cpu_cp_hl();
  if (flag_c()) goto lab_p02_L_46FF;
  p02_L_4719();
  goto lab_p02_L_46F4;
  lab_p02_L_46FF: ;
  set_bc(mem_read16(0x84AF));
  b = (uint8_t)(b + 1);
  a = mem_read8(0x84B8);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p02_L_4714;
  p02_L_470A();
  return;
  lab_p02_L_4714: ;
  p00_L_21A7();
  cpu_pop_af();
  return;
}

/* flash page 2 cpu 0x4684 (offset 0x0684) */
void p02_L_4684(void) {
  flag_cmp(a, b);
  a = (uint8_t)(a + h);
  c = a;
  a = (uint8_t)(a | (1u << 6));
  p02_L_41C7();
  p00_L_22F7();
  p00_L_113F();
  p00_L_107E();
  cpu_pop_bc();
  cpu_push_bc();
  if (flag_c()) goto lab_p02_L_469B;
  if (flag_nz()) goto lab_p02_L_46AE;
  lab_p02_L_469B: ;
  cpu_push_bc();
  p00_L_128A();
  p02_L_405E();
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  a = mem_read8(0x84B8);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p02_L_469B;
  cpu_pop_bc();
  p02_L_470A();
  return;
  lab_p02_L_46AE: ;
  mem_write16(0x84AF, bc());
  p02_L_403C();
  p00_rst18();
  cpu_pop_bc();
  lab_p02_L_46B7: ;
  cpu_push_bc();
  set_de(mem_read16(0x84D3));
  p02_L_4044();
  p00_L_22F7();
  p00_L_0ED0();
  cpu_pop_bc();
  cpu_push_bc();
  p02_L_405E();
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  if (flag_z()) goto lab_p02_L_46D4;
  a = mem_read8(0x84B7);
  flag_cmp(a, c);
  if (flag_nc()) goto lab_p02_L_46B7;
  lab_p02_L_46D4: ;
  p00_L_219B();
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p02_L_46EC;
  a = 0x01;
  set_hl(0x84B4);
  mem_write8(hl(), a);
  lab_p02_L_46E1: ;
  a = mem_read8(0x84B0);
  cpu_cp_hl();
  if (flag_z()) goto lab_p02_L_46EC;
  p02_L_4719();
  goto lab_p02_L_46E1;
  lab_p02_L_46EC: ;
  a = mem_read8(0x84B0);
  a = (uint8_t)(a + 1);
  set_hl(0x84B4);
  mem_write8(hl(), a);
  lab_p02_L_46F4: ;
  a = mem_read8(0x84B8);
  cpu_cp_hl();
  if (flag_c()) goto lab_p02_L_46FF;
  p02_L_4719();
  goto lab_p02_L_46F4;
  lab_p02_L_46FF: ;
  set_bc(mem_read16(0x84AF));
  b = (uint8_t)(b + 1);
  a = mem_read8(0x84B8);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p02_L_4714;
  p02_L_470A();
  return;
  lab_p02_L_4714: ;
  p00_L_21A7();
  cpu_pop_af();
  return;
}

/* flash page 2 cpu 0x470A (offset 0x070A) */
void p02_L_470A(void) {
  goto lab_p02_L_470A;
  lab_p02_L_467A: ;
  mem_write16(0x84AF, bc());
  cpu_push_bc();
  a = mem_read8(0x84B0);
  b = a;
  a = mem_read8(0x84B8);
  c = a;
  a = (uint8_t)(a | (1u << 6));
  p02_L_41C7();
  p00_L_22F7();
  p00_L_113F();
  p00_L_107E();
  cpu_pop_bc();
  cpu_push_bc();
  if (flag_c()) goto lab_p02_L_469B;
  if (flag_nz()) goto lab_p02_L_46AE;
  lab_p02_L_469B: ;
  cpu_push_bc();
  p00_L_128A();
  p02_L_405E();
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  a = mem_read8(0x84B8);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p02_L_469B;
  cpu_pop_bc();
  goto lab_p02_L_470A;
  lab_p02_L_46AE: ;
  mem_write16(0x84AF, bc());
  p02_L_403C();
  p00_rst18();
  cpu_pop_bc();
  lab_p02_L_46B7: ;
  cpu_push_bc();
  set_de(mem_read16(0x84D3));
  p02_L_4044();
  p00_L_22F7();
  p00_L_0ED0();
  cpu_pop_bc();
  cpu_push_bc();
  p02_L_405E();
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  if (flag_z()) goto lab_p02_L_46D4;
  a = mem_read8(0x84B7);
  flag_cmp(a, c);
  if (flag_nc()) goto lab_p02_L_46B7;
  lab_p02_L_46D4: ;
  p00_L_219B();
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p02_L_46EC;
  a = 0x01;
  set_hl(0x84B4);
  mem_write8(hl(), a);
  lab_p02_L_46E1: ;
  a = mem_read8(0x84B0);
  cpu_cp_hl();
  if (flag_z()) goto lab_p02_L_46EC;
  p02_L_4719();
  goto lab_p02_L_46E1;
  lab_p02_L_46EC: ;
  a = mem_read8(0x84B0);
  a = (uint8_t)(a + 1);
  set_hl(0x84B4);
  mem_write8(hl(), a);
  lab_p02_L_46F4: ;
  a = mem_read8(0x84B8);
  cpu_cp_hl();
  if (flag_c()) goto lab_p02_L_46FF;
  p02_L_4719();
  goto lab_p02_L_46F4;
  lab_p02_L_46FF: ;
  set_bc(mem_read16(0x84AF));
  b = (uint8_t)(b + 1);
  a = mem_read8(0x84B8);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p02_L_4714;
  lab_p02_L_470A: ;
  a = mem_read8(0x84B7);
  c = (uint8_t)(c + 1);
  if (flag_z()) goto lab_p02_L_4714;
  flag_cmp(a, c);
  if (flag_nc()) goto lab_p02_L_467A;
  lab_p02_L_4714: ;
  p00_L_21A7();
  cpu_pop_af();
  return;
}

/* flash page 2 cpu 0x4719 (offset 0x0719) */
void p02_L_4719(void) {
  a = mem_read8(0x84B7);
  mem_write8(0x84B3, a);
  lab_p02_L_471F: ;
  set_bc(mem_read16(0x84AF));
  a = mem_read8(0x84B3);
  c = a;
  p02_L_4040();
  p00_rst08();
  set_bc(mem_read16(0x84AF));
  a = mem_read8(0x84B4);
  b = a;
  p02_L_4040();
  p00_L_0D1F();
  p00_L_0E4C();
  p00_rst08();
  set_bc(mem_read16(0x84B3));
  p02_L_4040();
  p00_rst30();
  set_bc(mem_read16(0x84B3));
  p02_L_405E();
  set_hl(0x84B3);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  a = mem_read8(0x84AF);
  cpu_cp_hl();
  if (flag_c()) goto lab_p02_L_471F;
  if (flag_z()) goto lab_p02_L_471F;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  return;
}

/* flash page 2 cpu 0x4748 (offset 0x0748) */
void p02_L_4748(void) {
  goto lab_p02_L_4748;
  lab_p02_L_471F: ;
  set_bc(mem_read16(0x84AF));
  a = mem_read8(0x84B3);
  c = a;
  p02_L_4040();
  p00_rst08();
  set_bc(mem_read16(0x84AF));
  a = mem_read8(0x84B4);
  b = a;
  p02_L_4040();
  p00_L_0D1F();
  p00_L_0E4C();
  p00_rst08();
  set_bc(mem_read16(0x84B3));
  p02_L_4040();
  p00_rst30();
  set_bc(mem_read16(0x84B3));
  lab_p02_L_4748: ;
  a = (uint8_t)(a + h);
  p02_L_405E();
  set_hl(0x84B3);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  a = mem_read8(0x84AF);
  cpu_cp_hl();
  if (flag_c()) goto lab_p02_L_471F;
  if (flag_z()) goto lab_p02_L_471F;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  return;
}

/* flash page 2 cpu 0x475B (offset 0x075B) */
void p02_L_475B(void) {
  c = 0x00;
  lab_p02_L_475D: ;
  a = mem_read8(0x84AF);
  flag_cmp(a, c);
  if (flag_z()) return;
  c = (uint8_t)(c + 1);
  b = 0x01;
  cpu_push_bc();
  p02_L_4040();
  lab_p02_L_4769: ;
  cpu_pop_bc();
  cpu_push_bc();
  p02_L_4068();
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  a = mem_read8(0x84B0);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p02_L_475D;
  cpu_push_bc();
  set_de(mem_read16(0x84D3));
  p02_L_4051();
  p00_rst30();
  goto lab_p02_L_4769;
}

/* flash page 2 cpu 0x4781 (offset 0x0781) */
void p02_L_4781(void) {
  set_de(mem_read16(0x84D3));
  p02_L_4785();
  return;
}

/* flash page 2 cpu 0x4784 (offset 0x0784) */
void p02_L_4784(void) {
  a = (uint8_t)(a + h);
  p02_L_4785();
  return;
}

/* flash page 2 cpu 0x4785 (offset 0x0785) */
void p02_L_4785(void) {
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  a = a & 0x0C;
  flag_logic(a);
  cpu_push_af();
  set_hl((uint16_t)(hl() - 1));
  p00_L_1025();
  cpu_pop_af();
  if (flag_z()) goto lab_p02_L_4793;
  set_hl((uint16_t)(hl() + hl()));
  lab_p02_L_4793: ;
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 2 cpu 0x4795 (offset 0x0795) */
void p02_L_4795(void) {
  set_de(mem_read16(0x84D7));
  p02_L_47A2();
  return;
}

/* flash page 2 cpu 0x479B (offset 0x079B) */
void p02_L_479B(void) {
  set_hl(mem_read16(0x84AF));
  p02_L_479E();
  return;
}

/* flash page 2 cpu 0x479E (offset 0x079E) */
void p02_L_479E(void) {
  set_de(mem_read16(0x84D3));
  p02_L_47A2();
  return;
}

/* flash page 2 cpu 0x47A2 (offset 0x07A2) */
void p02_L_47A2(void) {
  p02_L_4785();
  set_de(0x8478);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_47F0;
  p00_L_214E();
  return;
  lab_p02_L_47F0: ;
  p00_L_1183();
  return;
}

/* flash page 2 cpu 0x47AE (offset 0x07AE) */
void p02_L_47AE(void) {
  set_hl(mem_read16(0x84AF));
  p02_L_47B1();
  return;
}

/* flash page 2 cpu 0x47B1 (offset 0x07B1) */
void p02_L_47B1(void) {
  set_de(mem_read16(0x84D3));
  p02_L_47B5();
  return;
}

/* flash page 2 cpu 0x47B5 (offset 0x07B5) */
void p02_L_47B5(void) {
  goto lab_p02_L_47B5;
  lab_p02_L_47A8: ;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_47F0;
  p00_L_214E();
  return;
  lab_p02_L_47B5: ;
  p02_L_4785();
  set_de(0x8483);
  goto lab_p02_L_47A8;
  lab_p02_L_47F0: ;
  p00_L_1183();
  return;
}

/* flash page 2 cpu 0x47BD (offset 0x07BD) */
void p02_L_47BD(void) {
  set_hl(mem_read16(0x84B3));
  p02_L_47C0();
  return;
}

/* flash page 2 cpu 0x47C0 (offset 0x07C0) */
void p02_L_47C0(void) {
  set_de(mem_read16(0x84D5));
  p02_L_47A2();
  return;
}

/* flash page 2 cpu 0x47C6 (offset 0x07C6) */
void p02_L_47C6(void) {
  goto lab_p02_L_47C6;
  lab_p02_L_47A8: ;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_47F0;
  p00_L_214E();
  return;
  lab_p02_L_47C6: ;
  set_hl(mem_read16(0x84AF));
  set_de(mem_read16(0x84D3));
  p02_L_4785();
  set_de(0x848E);
  goto lab_p02_L_47A8;
  lab_p02_L_47F0: ;
  p00_L_1183();
  return;
}

/* flash page 2 cpu 0x47D8 (offset 0x07D8) */
void p02_L_47D8(void) {
  set_de(mem_read16(0x84D7));
  p02_L_47DC();
  return;
}

/* flash page 2 cpu 0x47DC (offset 0x07DC) */
void p02_L_47DC(void) {
  p02_L_4785();
  cpu_push_hl();
  p00_L_15FB();
  cpu_pop_de();
  set_hl(0x8478);
  a = mem_read8(hl());
  p00_L_1183();
  a = a & 0x0C;
  flag_logic(a);
  if (flag_z()) return;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_1183();
  return;
}

/* flash page 2 cpu 0x47F3 (offset 0x07F3) */
void p02_L_47F3(void) {
  h = 0x00;
  p00_L_1025();
  cpu_ex_de_hl();
  set_hl(mem_read16(0x9824));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  p00_rst20();
  return;
}

/* flash page 2 cpu 0x4801 (offset 0x0801) */
void p02_L_4801(void) {
  b = 0x02;
  goto lab_p02_L_4807;
  lab_p02_L_4807: ;
  cpu_push_bc();
  mem_write8(0x84B4, a);
  p00_rst18();
  l = 0x01;
  a = 0;
  flag_logic(a);
  mem_write8(0x84B5, a);
  lab_p02_L_4812: ;
  cpu_push_hl();
  p02_L_47F3();
  p00_L_2429();
  p00_L_1641();
  if (flag_z()) { p00_L_24D5(); return; }
  flag_cmp(a, 0x5D);
  if (flag_nz()) { p00_L_24DD(); return; }
  a = mem_read8(0x847A);
  a = (uint8_t)(a + 1);
  b = a;
  a = 0x01;
  goto lab_p02_L_482E;
  lab_p02_L_482D: ;
  a = (uint8_t)(a + a);
  lab_p02_L_482E: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_482D;
  set_hl(0x84B5);
  b = a;
  /* and (hl) */
  if (flag_nz()) { p00_L_24D5(); return; }
  a = b;
  /* or (hl) */
  mem_write8(hl(), a);
  p00_L_17E6();
  cpu_pop_hl();
  l = (uint8_t)(l + 1);
  a = mem_read8(0x84B4);
  flag_cmp(a, l);
  if (flag_nc()) goto lab_p02_L_4812;
  p00_L_188D();
  mem_write16(0x84D3, de());
  a = a | h;
  flag_logic(a);
  if (flag_z()) { p00_L_24ED(); return; }
  mem_write16(0x84AF, hl());
  l = 0x01;
  lab_p02_L_4856: ;
  a = mem_read8(0x84B4);
  flag_cmp(a, l);
  if (flag_z()) goto lab_p02_L_4879;
  cpu_push_hl();
  p02_L_47F3();
  cpu_push_hl();
  p00_rst10();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), e);
  cpu_ex_de_hl();
  p00_L_0033();
  set_de(mem_read16(0x84AF));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nz()) { p00_L_24E9(); return; }
  cpu_pop_hl();
  l = (uint8_t)(l + 1);
  goto lab_p02_L_4856;
  lab_p02_L_4879: ;
  set_bc(mem_read16(0x84AF));
  lab_p02_L_487D: ;
  a = a | a;
  flag_logic(a);
  set_hl(0x0001);
  cpu_sbc_hl_bc();
  if (flag_z()) goto lab_p02_L_48CF;
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  flag_cmp(a, 0x02);
  a = 0x01;
  if (flag_c()) goto lab_p02_L_4890;
  a = (uint8_t)(a - 1);
  lab_p02_L_4890: ;
  p02_L_48F8();
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_z()) goto lab_p02_L_48CC;
  set_hl((uint16_t)(hl() + bc()));
  cpu_push_hl();
  cpu_push_bc();
  p02_L_48DA();
  set_hl(mem_read16(0x84D3));
  mem_write16(0x84D5, hl());
  l = 0x00;
  lab_p02_L_48A7: ;
  l = (uint8_t)(l + 1);
  a = mem_read8(0x84B4);
  flag_cmp(a, l);
  if (flag_z()) goto lab_p02_L_48C4;
  cpu_push_hl();
  p02_L_47F3();
  set_hl(mem_read16(0x847F));
  mem_write16(0x84D3, hl());
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  p02_L_48DA();
  cpu_pop_hl();
  goto lab_p02_L_48A7;
  lab_p02_L_48C4: ;
  set_hl(mem_read16(0x84D5));
  mem_write16(0x84D3, hl());
  cpu_pop_de();
  cpu_pop_de();
  lab_p02_L_48CC: ;
  set_bc((uint16_t)(bc() - 1));
  goto lab_p02_L_487D;
  lab_p02_L_48CF: ;
  a = mem_read8(0x84B4);
  l = a;
  h = 0x00;
  p00_L_21B2();
  goto lab_p02_L_48F1;
  lab_p02_L_48F1: ;
  cpu_pop_bc();
  return;
}

/* flash page 2 cpu 0x4805 (offset 0x0805) */
void p02_L_4805(void) {
  b = 0x00;
  cpu_push_bc();
  mem_write8(0x84B4, a);
  p00_rst18();
  l = 0x01;
  a = 0;
  flag_logic(a);
  mem_write8(0x84B5, a);
  lab_p02_L_4812: ;
  cpu_push_hl();
  p02_L_47F3();
  p00_L_2429();
  p00_L_1641();
  if (flag_z()) { p00_L_24D5(); return; }
  flag_cmp(a, 0x5D);
  if (flag_nz()) { p00_L_24DD(); return; }
  a = mem_read8(0x847A);
  a = (uint8_t)(a + 1);
  b = a;
  a = 0x01;
  goto lab_p02_L_482E;
  lab_p02_L_482D: ;
  a = (uint8_t)(a + a);
  lab_p02_L_482E: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_482D;
  set_hl(0x84B5);
  b = a;
  /* and (hl) */
  if (flag_nz()) { p00_L_24D5(); return; }
  a = b;
  /* or (hl) */
  mem_write8(hl(), a);
  p00_L_17E6();
  cpu_pop_hl();
  l = (uint8_t)(l + 1);
  a = mem_read8(0x84B4);
  flag_cmp(a, l);
  if (flag_nc()) goto lab_p02_L_4812;
  p00_L_188D();
  mem_write16(0x84D3, de());
  a = a | h;
  flag_logic(a);
  if (flag_z()) { p00_L_24ED(); return; }
  mem_write16(0x84AF, hl());
  l = 0x01;
  lab_p02_L_4856: ;
  a = mem_read8(0x84B4);
  flag_cmp(a, l);
  if (flag_z()) goto lab_p02_L_4879;
  cpu_push_hl();
  p02_L_47F3();
  cpu_push_hl();
  p00_rst10();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), e);
  cpu_ex_de_hl();
  p00_L_0033();
  set_de(mem_read16(0x84AF));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nz()) { p00_L_24E9(); return; }
  cpu_pop_hl();
  l = (uint8_t)(l + 1);
  goto lab_p02_L_4856;
  lab_p02_L_4879: ;
  set_bc(mem_read16(0x84AF));
  lab_p02_L_487D: ;
  a = a | a;
  flag_logic(a);
  set_hl(0x0001);
  cpu_sbc_hl_bc();
  if (flag_z()) goto lab_p02_L_48CF;
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  flag_cmp(a, 0x02);
  a = 0x01;
  if (flag_c()) goto lab_p02_L_4890;
  a = (uint8_t)(a - 1);
  lab_p02_L_4890: ;
  p02_L_48F8();
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_z()) goto lab_p02_L_48CC;
  set_hl((uint16_t)(hl() + bc()));
  cpu_push_hl();
  cpu_push_bc();
  p02_L_48DA();
  set_hl(mem_read16(0x84D3));
  mem_write16(0x84D5, hl());
  l = 0x00;
  lab_p02_L_48A7: ;
  l = (uint8_t)(l + 1);
  a = mem_read8(0x84B4);
  flag_cmp(a, l);
  if (flag_z()) goto lab_p02_L_48C4;
  cpu_push_hl();
  p02_L_47F3();
  set_hl(mem_read16(0x847F));
  mem_write16(0x84D3, hl());
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  p02_L_48DA();
  cpu_pop_hl();
  goto lab_p02_L_48A7;
  lab_p02_L_48C4: ;
  set_hl(mem_read16(0x84D5));
  mem_write16(0x84D3, hl());
  cpu_pop_de();
  cpu_pop_de();
  lab_p02_L_48CC: ;
  set_bc((uint16_t)(bc() - 1));
  goto lab_p02_L_487D;
  lab_p02_L_48CF: ;
  a = mem_read8(0x84B4);
  l = a;
  h = 0x00;
  p00_L_21B2();
  goto lab_p02_L_48F1;
  lab_p02_L_48F1: ;
  cpu_pop_bc();
  return;
}

/* flash page 2 cpu 0x48DA (offset 0x08DA) */
void p02_L_48DA(void) {
  cpu_push_bc();
  p02_L_4781();
  cpu_ex_de_hl();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_de();
  p02_L_4781();
  cpu_pop_de();
  b = 0x09;
  flag_set_z((mem_read8(hl()) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p02_L_48EE;
  b = 0x12;
  lab_p02_L_48EE: ;
  p00_L_14B8();
  cpu_pop_bc();
  return;
}

/* flash page 2 cpu 0x48F8 (offset 0x08F8) */
void p02_L_48F8(void) {
  mem_write8(0x84B5, a);
  a = mem_read8(0x84B4);
  cpu_push_af();
  mem_write16(0x84B3, hl());
  cpu_push_hl();
  cpu_push_bc();
  p02_L_479E();
  p00_L_102F();
  if (flag_z()) p02_L_6B8C();
  p00_L_1171();
  lab_p02_L_4910: ;
  cpu_pop_bc();
  cpu_pop_hl();
  lab_p02_L_4912: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nz()) goto lab_p02_L_491F;
  set_hl(mem_read16(0x84B3));
  cpu_pop_af();
  mem_write8(0x84B4, a);
  return;
  lab_p02_L_491F: ;
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  cpu_push_bc();
  p02_L_479E();
  p00_L_102F();
  if (flag_z()) p02_L_6B8C();
  p00_L_10DD();
  p00_L_1108();
  a = mem_read8(0x84B5);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_493F;
  p00_L_107E();
  if (flag_nc()) goto lab_p02_L_4910;
  goto lab_p02_L_4946;
  lab_p02_L_493F: ;
  p00_L_107E();
  if (flag_c()) goto lab_p02_L_4910;
  if (flag_z()) goto lab_p02_L_4910;
  lab_p02_L_4946: ;
  p00_L_1149();
  cpu_pop_bc();
  cpu_pop_hl();
  mem_write16(0x84B3, hl());
  goto lab_p02_L_4912;
}

/* flash page 2 cpu 0x4950 (offset 0x0950) */
void p02_L_4950(void) {
  a = 0;
  flag_logic(a);
  set_hl(0x0001);
  set_bc(mem_read16(0x84AF));
  p02_L_48F8();
  p02_L_479E();
  return;
}

/* flash page 2 cpu 0x495E (offset 0x095E) */
void p02_L_495E(void) {
  goto lab_p02_L_495E;
  lab_p02_L_4951: ;
  set_hl(0x0001);
  set_bc(mem_read16(0x84AF));
  p02_L_48F8();
  p02_L_479E();
  return;
  lab_p02_L_495E: ;
  a = 0x01;
  goto lab_p02_L_4951;
}

/* flash page 2 cpu 0x4969 (offset 0x0969) */
void p02_L_4969(void) {
  p00_L_128A();
  a = 0x70;
  cpu_push_af();
  lab_p02_L_496F: ;
  p00_L_2222();
  p02_L_479B();
  cpu_pop_af();
  cpu_push_af();
  p02_L_50A3();
  set_hl(mem_read16(0x84AF));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x84AF, hl());
  set_de(mem_read16(0x84B1));
  p00_L_192A();
  if (flag_nc()) goto lab_p02_L_496F;
  cpu_pop_af();
  return;
}

/* flash page 2 cpu 0x498C (offset 0x098C) */
void p02_L_498C(void) {
  set_hl(0x0001);
  cpu_push_hl();
  p02_L_479E();
  lab_p02_L_4993: ;
  cpu_pop_hl();
  cpu_push_hl();
  p02_L_47D8();
  cpu_pop_hl();
  set_de(mem_read16(0x84AF));
  p00_L_192A();
  if (flag_z()) return;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p00_L_2222();
  cpu_pop_hl();
  cpu_push_hl();
  p02_L_479E();
  a = 0x70;
  p02_L_50A3();
  goto lab_p02_L_4993;
}

/* flash page 2 cpu 0x49B2 (offset 0x09B2) */
void p02_L_49B2(void) {
  set_hl(mem_read16(0x84AF));
  lab_p02_L_49B5: ;
  p02_L_47D8();
  p02_L_49BE();
  if (flag_nz()) goto lab_p02_L_49B5;
  return;
}

/* flash page 2 cpu 0x49BE (offset 0x09BE) */
void p02_L_49BE(void) {
  set_hl(mem_read16(0x84AF));
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  mem_write16(0x84AF, hl());
  return;
}

/* flash page 2 cpu 0x49C8 (offset 0x09C8) */
void p02_L_49C8(void) {
  set_de(0x0000);
  p02_L_49DF();
  set_de(mem_read16(0x84D5));
  mem_write16(0x84D3, de());
  set_de(mem_read16(0x84B3));
  mem_write16(0x84AF, de());
  cpu_ex_de_hl();
  p02_L_49DF();
  return;
}

/* flash page 2 cpu 0x49CD (offset 0x09CD) */
void p02_L_49CD(void) {
  c = c;
  set_de(mem_read16(0x84D5));
  mem_write16(0x84D3, de());
  set_de(mem_read16(0x84B3));
  mem_write16(0x84AF, de());
  cpu_ex_de_hl();
  p02_L_49DF();
  return;
}

/* flash page 2 cpu 0x49DF (offset 0x09DF) */
void p02_L_49DF(void) {
  set_hl(0x0000);
  lab_p02_L_49E2: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  p02_L_479E();
  p00_L_184C();
  if (flag_z()) goto lab_p02_L_49F4;
  p00_L_102F();
  if (flag_nz()) p00_L_104B();
  lab_p02_L_49F4: ;
  cpu_pop_hl();
  cpu_push_hl();
  p02_L_47D8();
  p02_L_49BE();
  cpu_pop_de();
  cpu_pop_hl();
  if (flag_z()) return;
  goto lab_p02_L_49E2;
}

/* flash page 2 cpu 0x4A01 (offset 0x0A01) */
void p02_L_4A01(void) {
  set_hl(0x0001);
  cpu_push_hl();
  lab_p02_L_4A05: ;
  p02_L_49BE();
  cpu_pop_hl();
  if (flag_z()) return;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p02_L_479E();
  p00_L_2222();
  cpu_pop_hl();
  cpu_push_hl();
  set_hl((uint16_t)(hl() - 1));
  cpu_push_hl();
  p02_L_479E();
  a = 0x71;
  p02_L_50A3();
  cpu_pop_hl();
  p02_L_47D8();
  goto lab_p02_L_4A05;
}

/* flash page 2 cpu 0x4A24 (offset 0x0A24) */
void p02_L_4A24(void) {
  p00_L_3AD7();
  a = 0xFF;
  p00_L_1682();
  lab_p02_L_4A2C: ;
  p00_L_3ADD();
  if (flag_c()) return;
  p00_rst10();
  if (flag_c()) return;
  p00_L_1F55();
  if (flag_nz()) goto lab_p02_L_4A2C;
  p00_L_1F58();
  set_hl(0x0000);
  p00_L_1C46();
  p00_L_1135();
  goto lab_p02_L_4A2C;
}

/* flash page 2 cpu 0x4A45 (offset 0x0A45) */
void p02_L_4A45(void) {
  flag_cmp(a, 0x02);
  if (flag_c()) { p00_L_24E5(); return; }
  flag_cmp(a, 0x65);
  if (flag_nc()) { p00_L_24E5(); return; }
  a = (uint8_t)(a - 1);
  cpu_push_af();
  cpu_push_af();
  p00_L_241E();
  if (flag_nc()) goto lab_p02_L_4A60;
  set_hl(0x0101);
  p00_L_1C81();
  p00_L_1135();
  lab_p02_L_4A60: ;
  p00_L_1169();
  b = 0x00;
  set_hl(mem_read16(0x9824));
  cpu_pop_af();
  lab_p02_L_4A69: ;
  cpu_push_af();
  cpu_push_bc();
  p00_L_23CF();
  cpu_push_hl();
  p00_rst20();
  p00_L_188D();
  a = h;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p00_L_24ED(); return; }
  a = l;
  flag_cmp(a, 0x64);
  if (flag_nc()) { p00_L_24ED(); return; }
  cpu_pop_hl();
  cpu_pop_bc();
  flag_cmp(a, b);
  if (flag_c()) goto lab_p02_L_4A84;
  b = a;
  lab_p02_L_4A84: ;
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p02_L_4A69;
  cpu_pop_af();
  cpu_push_af();
  c = a;
  cpu_push_bc();
  p00_L_1130();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_3AE3();
  p00_L_1130();
  p00_L_241E();
  mem_write16(0x84D7, de());
  cpu_pop_bc();
  cpu_push_bc();
  lab_p02_L_4AA0: ;
  b = 0x01;
  cpu_push_bc();
  p00_L_219B();
  p00_L_16BC();
  p00_L_188D();
  mem_write16(0x84D3, de());
  cpu_pop_bc();
  lab_p02_L_4AB1: ;
  a = l;
  flag_cmp(a, b);
  cpu_push_hl();
  cpu_push_bc();
  if (flag_nc()) goto lab_p02_L_4ABC;
  p00_L_128A();
  goto lab_p02_L_4AC0;
  lab_p02_L_4ABC: ;
  l = b;
  p02_L_479E();
  lab_p02_L_4AC0: ;
  cpu_pop_bc();
  cpu_push_bc();
  p02_L_4068();
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  cpu_pop_hl();
  cpu_pop_af();
  flag_cmp(a, b);
  cpu_push_af();
  if (flag_nc()) goto lab_p02_L_4AB1;
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p02_L_4AA0;
  cpu_pop_af();
  cpu_pop_af();
  return;
}

/* flash page 2 cpu 0x4AD3 (offset 0x0AD3) */
void p02_L_4AD3(void) {
  p00_L_14DB();
  if (flag_z()) goto lab_p02_L_4ADB;
  lab_p02_L_4AD8: ;
  p00_L_24C9();
  return;
  lab_p02_L_4ADB: ;
  p00_L_15C6();
  if (flag_nz()) goto lab_p02_L_4AD8;
  set_hl(0x8484);
  p00_L_14E4();
  if (flag_nz()) goto lab_p02_L_4AD8;
  p00_L_1713();
  if (flag_nc()) goto lab_p02_L_4AD8;
  a = mem_read8(0x8484);
  a = (uint8_t)(a - e);
  if (flag_nc()) goto lab_p02_L_4AD8;
  p00_L_14C7();
  if (flag_nz()) goto lab_p02_L_4AFF;
  p00_L_14CC();
  if (flag_z()) return;
  p00_L_1179();
  return;
  lab_p02_L_4AFF: ;
  p00_L_14CC();
  if (flag_z()) return;
  lab_p02_L_4B03: ;
  p00_L_0ED0();
  p00_L_0E72();
  p00_L_0D1F();
  p00_L_11D8();
  set_hl(0x0FC3);
  p00_L_0BEC();
  p00_L_0C0F();
  p00_rst08();
  p00_L_113F();
  p00_L_14CC();
  if (flag_z()) return;
  goto lab_p02_L_4B03;
}

/* flash page 2 cpu 0x4B39 (offset 0x0B39) */
void p02_L_4B39(void) {
  p00_L_14E1();
  if (flag_z()) goto lab_p02_L_4B43;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x84);
  lab_p02_L_4B43: ;
  if (flag_nc()) goto lab_p02_L_4C29;
  a = (uint8_t)(a - 0x0B);
  cpu_push_af();
  set_de(0x85FE);
  p00_L_11FD();
  p00_L_11FD();
  p00_L_1229();
  p00_L_1171();
  set_de(0x8610);
  p00_L_11FD();
  a = 0;
  flag_logic(a);
  mem_write8(0x847A, a);
  p00_L_11FD();
  p00_L_1169();
  lab_p02_L_4B68: ;
  set_hl(0x8607);
  p00_rst20();
  set_hl(0x0FC3);
  p00_L_11F8();
  a = mem_read8(0x8478);
  mem_write8(0x8483, a);
  p00_rst30();
  p00_L_0C0F();
  p00_L_10DD();
  p00_rst08();
  set_hl(0x8607);
  p00_rst20();
  p00_L_0C2D();
  set_de(0x8607);
  p00_L_11FD();
  p00_L_1130();
  p00_L_10EF();
  p00_L_0D1F();
  set_hl(0x8610);
  p00_L_0BEC();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x84);
  if (flag_nc()) goto lab_p02_L_4BE6;
  p00_L_148B();
  set_de(0x8610);
  p00_L_11FD();
  p00_L_113A();
  p00_L_10EF();
  p00_L_0D1F();
  set_hl(0x8619);
  p00_L_0BEC();
  p00_L_1486();
  set_de(0x8619);
  p00_L_11FD();
  set_hl(0x8607);
  p00_rst20();
  p00_L_1251();
  a = 0x7D;
  mem_write8(0x8484, a);
  p00_L_1078();
  if (flag_c()) goto lab_p02_L_4BE6;
  if (flag_z()) goto lab_p02_L_4BE6;
  set_hl(0x8607);
  p00_rst20();
  p00_L_0ECC();
  set_de(0x8607);
  p00_L_11FD();
  goto lab_p02_L_4B68;
  lab_p02_L_4BE6: ;
  p00_L_1128();
  p00_L_14CC();
  if (flag_z()) goto lab_p02_L_4C24;
  p00_L_113A();
  p00_L_0ED0();
  p00_L_0E4C();
  set_hl(0x85FE);
  p00_L_0BEC();
  p00_L_1251();
  cpu_pop_af();
  mem_write8(0x8484, a);
  p00_L_1078();
  if (flag_nc()) goto lab_p02_L_4C25;
  p00_L_1128();
  p00_L_1229();
  p00_L_1078();
  if (flag_z()) goto lab_p02_L_4C25;
  p00_L_113A();
  p00_L_1128();
  p00_L_15D1();
  set_hl(0x8478);
  /* xor (hl) */
  mem_write8(hl(), a);
  a = a | a;
  flag_logic(a);
  return;
  lab_p02_L_4C24: ;
  cpu_pop_af();
  lab_p02_L_4C25: ;
  set_hl(0x85FE);
  p00_rst20();
  lab_p02_L_4C29: ;
  /* scf */
  return;
}

/* flash page 2 cpu 0x4BED (offset 0x0BED) */
void p02_L_4BED(void) {
  mem_write8(hl(), 0xCD);
  a = mem_read8(0xCD11);
  if (flag_nc()) return;
  c = 0xCD;
  c = h;
  c = 0x21;
  flag_cmp(a, 0x85);
  p00_L_0BEC();
  p00_L_1251();
  cpu_pop_af();
  mem_write8(0x8484, a);
  p00_L_1078();
  if (flag_nc()) goto lab_p02_L_4C25;
  p00_L_1128();
  p00_L_1229();
  p00_L_1078();
  if (flag_z()) goto lab_p02_L_4C25;
  p00_L_113A();
  p00_L_1128();
  p00_L_15D1();
  set_hl(0x8478);
  /* xor (hl) */
  mem_write8(hl(), a);
  a = a | a;
  flag_logic(a);
  return;
  lab_p02_L_4C25: ;
  set_hl(0x85FE);
  p00_rst20();
  /* scf */
  return;
}

/* flash page 2 cpu 0x4C45 (offset 0x0C45) */
void p02_L_4C45(void) {
  if (flag_z()) goto lab_p02_L_4C56;
  goto lab_p02_L_4C63;
  lab_p02_L_4C56: ;
  p00_L_1229();
  return;
  lab_p02_L_4C63: ;
  p00_L_128A();
  return;
}

/* flash page 2 cpu 0x4C49 (offset 0x0C49) */
void p02_L_4C49(void) {
  p00_L_14C7();
  p02_L_4C45();
  return;
}

/* flash page 2 cpu 0x4C59 (offset 0x0C59) */
void p02_L_4C59(void) {
  goto lab_p02_L_4C59;
  lab_p02_L_4C56: ;
  p00_L_1229();
  return;
  lab_p02_L_4C59: ;
  p00_L_14A7();
  p00_L_107E();
  if (flag_c()) goto lab_p02_L_4C56;
  if (flag_z()) goto lab_p02_L_4C56;
  p00_L_128A();
  return;
}

/* flash page 2 cpu 0x4C72 (offset 0x0C72) */
void p02_L_4C72(void) {
  goto lab_p02_L_4C72;
  lab_p02_L_4C56: ;
  p00_L_1229();
  return;
  lab_p02_L_4C63: ;
  p00_L_128A();
  return;
  lab_p02_L_4C6E: ;
  if (flag_c()) goto lab_p02_L_4C63;
  goto lab_p02_L_4C56;
  lab_p02_L_4C72: ;
  p00_L_14A7();
  p00_L_107E();
  goto lab_p02_L_4C6E;
}

/* flash page 2 cpu 0x4CD1 (offset 0x0CD1) */
void p02_L_4CD1(void) {
  p02_L_4EB6();
  set_hl(0x84E9);
  cpu_cp_hl();
  if (flag_c()) return;
  mem_write8(hl(), a);
  return;
}

/* flash page 2 cpu 0x4CDB (offset 0x0CDB) */
void p02_L_4CDB(void) {
  p00_rst18();
  a = 0;
  flag_logic(a);
  mem_write8(0x84E9, a);
  set_hl(0x91CE);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  set_hl(0x8FCE);
  if (flag_nz()) p02_L_4CD1();
  set_hl(0x91CE);
  flag_set_z((mem_read8(hl()) & (1u << 1)) == 0);
  set_hl(0x8FD7);
  if (flag_nz()) p02_L_4CD1();
  set_hl(0x91CE);
  flag_set_z((mem_read8(hl()) & (1u << 2)) == 0);
  set_hl(0x8FFB);
  if (flag_nz()) p02_L_4CD1();
  p00_L_128A();
  set_de(0x91D0);
  p00_L_11FD();
  set_hl(0x8FE0);
  p00_rst20();
  p00_L_39D5();
  p02_L_4D14();
  return;
}

/* flash page 2 cpu 0x4D13 (offset 0x0D13) */
void p02_L_4D13(void) {
  p00_rst18();
  p02_L_4D14();
  return;
}

/* flash page 2 cpu 0x4D14 (offset 0x0D14) */
void p02_L_4D14(void) {
  b = 0x01;
  cpu_push_bc();
  a = mem_read8(0x91CE);
  a = a & b;
  flag_logic(a);
  if (flag_z()) { p02_L_4DB8(); return; }
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p02_L_4D23;
  a = (uint8_t)(a - 1);
  lab_p02_L_4D23: ;
  cpu_push_af();
  p00_L_39DB();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p02_L_4D32;
  p00_L_2429();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  lab_p02_L_4D32: ;
  cpu_pop_af();
  set_hl(0x8FCE);
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p02_L_4D42;
  set_hl(0x8FD7);
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p02_L_4D42;
  set_hl(0x8FFB);
  lab_p02_L_4D42: ;
  p02_L_4EB6();
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_4D58;
  p00_L_019D();
  if (flag_z()) goto lab_p02_L_4D58;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_4D58;
  a = 0x01;
  lab_p02_L_4D58: ;
  mem_write8(0x91CF, a);
  cpu_push_de();
  cpu_push_hl();
  cpu_push_af();
  p00_L_1100();
  set_hl(0x91D0);
  p00_rst20();
  p00_L_0C1B();
  cpu_pop_af();
  l = a;
  h = 0x00;
  p00_L_3B55();
  a = mem_read8(0x847A);
  cpu_push_af();
  p00_L_107E();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_c()) goto lab_p02_L_4D7D;
  if (flag_nz()) goto lab_p02_L_4D9C;
  lab_p02_L_4D7D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_4D89;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p02_L_4D95;
  lab_p02_L_4D89: ;
  a = b;
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p02_L_4D95;
  a = mem_read8(0x91CF);
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_4D98;
  lab_p02_L_4D95: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  lab_p02_L_4D98: ;
  p00_rst20();
  p02_L_4DB8();
  return;
  lab_p02_L_4D9C: ;
  p00_L_39E1();
  p00_L_113F();
  set_hl(0x4EA1);
  p00_L_25A2();
  p00_L_39E7();
  p00_L_25C8();
  p00_rst08();
  p00_L_219B();
  p00_L_39ED();
  p00_L_1179();
  p02_L_4DB8();
  return;
}

/* flash page 2 cpu 0x4DB8 (offset 0x0DB8) */
void p02_L_4DB8(void) {
  p00_L_1037();
  if (flag_z()) goto lab_p02_L_4DC2;
  flag_cmp(a, 0x0E);
  if (flag_nz()) { p00_L_24DD(); return; }
  lab_p02_L_4DC2: ;
  p00_rst18();
  a = mem_read8(0x84E9);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_4DCE;
  a = 0x0E;
  mem_write8(0x8478, a);
  lab_p02_L_4DCE: ;
  p00_rst18();
  p02_L_4DCF();
  return;
}

/* flash page 2 cpu 0x4DCD (offset 0x0DCD) */
void p02_L_4DCD(void) {
  a = (uint8_t)(a + h);
  p00_rst18();
  p02_L_4DCF();
  return;
}

/* flash page 2 cpu 0x4DCF (offset 0x0DCF) */
void p02_L_4DCF(void) {
  goto lab_p02_L_4DCF;
  lab_p02_L_4D16: ;
  cpu_push_bc();
  a = mem_read8(0x91CE);
  a = a & b;
  flag_logic(a);
  if (flag_z()) { p02_L_4DB8(); return; }
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p02_L_4D23;
  a = (uint8_t)(a - 1);
  lab_p02_L_4D23: ;
  cpu_push_af();
  p00_L_39DB();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p02_L_4D32;
  p00_L_2429();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  lab_p02_L_4D32: ;
  cpu_pop_af();
  set_hl(0x8FCE);
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p02_L_4D42;
  set_hl(0x8FD7);
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p02_L_4D42;
  set_hl(0x8FFB);
  lab_p02_L_4D42: ;
  p02_L_4EB6();
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_4D58;
  p00_L_019D();
  if (flag_z()) goto lab_p02_L_4D58;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_4D58;
  a = 0x01;
  lab_p02_L_4D58: ;
  mem_write8(0x91CF, a);
  cpu_push_de();
  cpu_push_hl();
  cpu_push_af();
  p00_L_1100();
  set_hl(0x91D0);
  p00_rst20();
  p00_L_0C1B();
  cpu_pop_af();
  l = a;
  h = 0x00;
  p00_L_3B55();
  a = mem_read8(0x847A);
  cpu_push_af();
  p00_L_107E();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_c()) goto lab_p02_L_4D7D;
  if (flag_nz()) goto lab_p02_L_4D9C;
  lab_p02_L_4D7D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_4D89;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p02_L_4D95;
  lab_p02_L_4D89: ;
  a = b;
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p02_L_4D95;
  a = mem_read8(0x91CF);
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_4D98;
  lab_p02_L_4D95: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  lab_p02_L_4D98: ;
  p00_rst20();
  p02_L_4DB8();
  return;
  lab_p02_L_4D9C: ;
  p00_L_39E1();
  p00_L_113F();
  set_hl(0x4EA1);
  p00_L_25A2();
  p00_L_39E7();
  p00_L_25C8();
  p00_rst08();
  p00_L_219B();
  p00_L_39ED();
  p00_L_1179();
  p02_L_4DB8();
  return;
  lab_p02_L_4DCF: ;
  cpu_pop_af();
  a = (uint8_t)(a + a);
  b = a;
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p02_L_4D16;
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  set_hl(0x901F);
  p02_L_4E95();
  p02_L_4E95();
  p02_L_4E95();
  set_hl(0x8E2D);
  p02_L_4E95();
  p02_L_4E95();
  p02_L_4E95();
  p00_L_219B();
  set_de(0x9043);
  p00_L_11FD();
  p00_L_219B();
  set_de(0x8E51);
  p00_L_11FD();
  p00_L_219B();
  set_de(0x9031);
  p00_L_11FD();
  p00_L_219B();
  set_de(0x8E3F);
  p00_L_11FD();
  p00_L_219B();
  set_de(0x901F);
  p00_L_11FD();
  p00_L_219B();
  set_de(0x8E2D);
  p00_L_11FD();
  set_hl(0x84E9);
  a = mem_read8(hl());
  a = (uint8_t)(a - 0x01);
  if (flag_c()) goto lab_p02_L_4E63;
  mem_write8(hl(), a);
  if (flag_nz()) goto lab_p02_L_4E6E;
  set_hl(0x8FCE);
  p02_L_4EB6();
  set_hl(0x8E2D);
  set_de(0x901F);
  p02_L_4E89();
  set_hl(0x8FD7);
  p02_L_4EB6();
  set_hl(0x8E3F);
  set_de(0x9031);
  p02_L_4E89();
  set_hl(0x8FFB);
  p02_L_4EB6();
  set_hl(0x8E51);
  set_de(0x9043);
  p02_L_4E89();
  goto lab_p02_L_4E6E;
  lab_p02_L_4E63: ;
  set_hl(0x8E2D);
  set_de(0x901F);
  set_bc(0x0036);
  while (bc() != 0) { cpu_ldi(); }
  lab_p02_L_4E6E: ;
  p00_L_22F7();
  p00_L_39F3();
  p00_L_107E();
  if (flag_nc()) { p00_L_21A7(); return; }
  p00_L_1867();
  p00_L_39F3();
  p00_L_0C1B();
  p00_L_39D5();
  p02_L_4D14();
  return;
}

/* flash page 2 cpu 0x4E89 (offset 0x0E89) */
void p02_L_4E89(void) {
  flag_cmp(a, 0x01);
  if (flag_c()) return;
  if (flag_z()) { p00_L_1183(); return; }
  p00_L_1183();
  p00_L_1183();
  return;
}

/* flash page 2 cpu 0x4E95 (offset 0x0E95) */
void p02_L_4E95(void) {
  cpu_push_hl();
  set_de(0x0009);
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  cpu_pop_hl();
  p00_L_1183();
  cpu_ex_de_hl();
  return;
}

/* flash page 2 cpu 0x4EB6 (offset 0x0EB6) */
void p02_L_4EB6(void) {
  b = 0x00;
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x0E);
  if (flag_z()) goto lab_p02_L_4ECC;
  b = (uint8_t)(b + 1);
  set_de(0x001B);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x0E);
  if (flag_z()) goto lab_p02_L_4ECC;
  b = (uint8_t)(b + 1);
  lab_p02_L_4ECC: ;
  a = b;
  return;
}

/* flash page 2 cpu 0x4ECE (offset 0x0ECE) */
void p02_L_4ECE(void) {
  p00_L_187F();
  p00_L_15C6();
  if (flag_nz()) goto lab_p02_L_4EE2;
  p00_L_1171();
  p00_L_10E6();
  set_hl(0x8484);
  p00_L_14E4();
  lab_p02_L_4EE2: ;
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_14CC();
  if (flag_z()) { p00_L_1228(); return; }
  p00_L_0C2D();
  p00_L_15CB();
  if (flag_nz()) { p00_L_0EBD(); return; }
  return;
}

/* flash page 2 cpu 0x4F53 (offset 0x0F53) */
void p02_L_4F53(void) {
  p00_L_14E1();
  lab_p02_L_4F56: ;
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_14B0();
  p00_L_14E1();
  if (flag_nz()) goto lab_p02_L_4F56;
  p00_L_107E();
  if (flag_c()) p00_L_14B0();
  p00_L_21E0();
  p00_L_0C2D();
  p00_L_0C1B();
  p00_rst18();
  p00_L_39F9();
  p00_L_2196();
  p00_L_0D1F();
  p00_L_0BF9();
  p00_L_2196();
  p00_rst30();
  return;
}

/* flash page 2 cpu 0x4F82 (offset 0x0F82) */
void p02_L_4F82(void) {
  p00_L_1169();
  p00_L_1179();
  p02_L_7250();
  p00_L_10E6();
  p00_L_1128();
  p00_L_0D1F();
  p00_L_14A2();
  p00_L_1128();
  p00_L_0D1F();
  p00_L_10EF();
  return;
}

/* flash page 2 cpu 0x4FA0 (offset 0x0FA0) */
void p02_L_4FA0(void) {
  p00_L_1159();
  p00_L_1169();
  p00_L_0D1E();
  p00_L_10DD();
  p00_L_113A();
  p00_L_0D1E();
  p00_L_10EF();
  p00_rst30();
  p02_L_6D46();
  p00_L_1128();
  p00_L_1169();
  p00_L_113A();
  d = 0x00;
  p02_L_7657();
  p00_rst08();
  p00_L_1130();
  return;
}

/* flash page 2 cpu 0x4FCB (offset 0x0FCB) */
void p02_L_4FCB(void) {
  set_hl(0x4FD1);
  p00_L_0732();
  return;
}

/* flash page 2 cpu 0x5007 (offset 0x1007) */
void p02_L_5007(void) {
  cpu_push_af();
  p00_L_18B7();
  if (flag_z()) goto lab_p02_L_5018;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x4A);
  if (flag_z()) goto lab_p02_L_5026;
  flag_cmp(a, 0x44);
  if (flag_z()) goto lab_p02_L_5026;
  lab_p02_L_5018: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p02_L_5026;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  lab_p02_L_5026: ;
  cpu_pop_af();
  return;
}

/* flash page 2 cpu 0x5028 (offset 0x1028) */
void p02_L_5028(void) {
  p00_L_163B();
  if (flag_nc()) goto lab_p02_L_5049;
  flag_cmp(a, 0x70);
  if (flag_c()) goto lab_p02_L_5046;
  a = a | 0xF0;
  flag_logic(a);
  l = a;
  a = d;
  a = (uint8_t)(a + 1);
  a = (uint8_t)(a + l);
  if (flag_nc()) { p00_L_128A(); return; }
  a = a ^ 0xFF;
  a = a & 0x0F;
  flag_logic(a);
  a = (uint8_t)(a - 1);
  goto lab_p02_L_5051;
  lab_p02_L_5040: ;
  p00_L_14C7();
  if (flag_nz()) { p00_L_1040(); return; }
  lab_p02_L_5046: ;
  p00_L_128A();
  return;
  lab_p02_L_5049: ;
  a = (uint8_t)(a - 0x80);
  l = a;
  a = 0x0D;
  a = (uint8_t)(a - d);
  a = (uint8_t)(a - l);
  if (flag_c()) return;
  lab_p02_L_5051: ;
  /* srl a */
  set_hl(0x8480);
  if (flag_z()) goto lab_p02_L_505F;
  b = a;
  lab_p02_L_5059: ;
  a = mem_read8(hl());
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() - 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_5059;
  lab_p02_L_505F: ;
  if (flag_nc()) goto lab_p02_L_506F;
  a = mem_read8(hl());
  b = a;
  a = a & 0xF0;
  flag_logic(a);
  mem_write8(hl(), a);
  a = b;
  a = a & 0x0F;
  flag_logic(a);
  flag_cmp(a, 0x05);
  b = 0x10;
  goto lab_p02_L_5073;
  lab_p02_L_506F: ;
  flag_cmp(a, 0x50);
  b = 0x01;
  lab_p02_L_5073: ;
  if (flag_c()) goto lab_p02_L_5040;
  a = mem_read8(0x8479);
  cpu_push_af();
  a = mem_read8(0x8478);
  cpu_push_af();
  a = 0;
  flag_logic(a);
  mem_write8(0x8478, a);
  a = b;
  p00_L_138B();
  cpu_pop_af();
  a = a & 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  set_hl(0x8479);
  d = mem_read8(hl());
  cpu_pop_af();
  mem_write8(hl(), a);
  flag_cmp(a, d);
  if (flag_z()) return;
  set_hl(0x847A);
  mem_write8(hl(), 0x10);
  p00_L_15F3();
  return;
}

/* flash page 2 cpu 0x509B (offset 0x109B) */
void p02_L_509B(void) {
  p00_L_1847();
  set_hl(0x9817);
  mem_write8(hl(), 0x00);
  p02_L_50A3();
  return;
}

/* flash page 2 cpu 0x50A3 (offset 0x10A3) */
void p02_L_50A3(void) {
  lab_p02_L_50A3: ;
  cpu_push_af();
  p00_L_22F2();
  a = mem_read8(0x848E);
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x0E);
  if (flag_z()) { p00_L_24FD(); return; }
  d = a;
  flag_cmp(a, 0x0C);
  if (flag_nz()) p00_L_21A7();
  p00_L_12B9();
  b = a;
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_z()) { p00_L_24FD(); return; }
  a = (uint8_t)(a + b);
  if (flag_nz()) goto lab_p02_L_50CA;
  p00_rst08();
  p00_L_113F();
  lab_p02_L_50CA: ;
  c = a;
  cpu_pop_af();
  b = a;
  flag_cmp(a, 0xD0);
  if (flag_nz()) goto lab_p02_L_50E2;
  p02_L_5316();
  p00_rst18();
  p00_L_1179();
  a = 0x25;
  cpu_push_af();
  p02_L_5601();
  a = e;
  p02_L_5FE4();
  return;
  lab_p02_L_50E2: ;
  flag_cmp(a, 0xB6);
  if (flag_nz()) goto lab_p02_L_50FD;
  set_hl(0x3B3D);
  lab_p02_L_50E9: ;
  cpu_push_hl();
  a = c;
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p02_L_50F4;
  flag_cmp(a, 0xD0);
  if (flag_nz()) { p00_L_24DD(); return; }
  lab_p02_L_50F4: ;
  p00_L_21DB();
  h = 0xFF;
  cpu_push_hl();
  p02_L_6100();
  return;
  lab_p02_L_50FD: ;
  set_hl(0x4962);
  flag_cmp(a, 0xB7);
  if (flag_z()) goto lab_p02_L_50E9;
  flag_cmp(a, 0xE4);
  if (flag_nz()) goto lab_p02_L_510F;
  p02_L_5316();
  a = 0x12;
  goto lab_p02_L_515D;
  lab_p02_L_510F: ;
  flag_cmp(a, 0xE3);
  if (flag_nz()) goto lab_p02_L_5117;
  a = 0x28;
  goto lab_p02_L_515D;
  lab_p02_L_5117: ;
  flag_cmp(a, 0xCF);
  if (flag_nz()) goto lab_p02_L_513E;
  a = c;
  flag_cmp(a, 0x01);
  if (flag_nz()) { p00_L_24DD(); return; }
  p02_L_6042();
  p00_L_21DB();
  p02_L_59F8();
  cpu_ex_de_hl();
  a = 0;
  flag_logic(a);
  mem_write8(0x84D6, a);
  p02_L_512F();
  return;
  lab_p02_L_513E: ;
  set_hl(0x65AD);
  flag_cmp(a, 0xD3);
  if (flag_z()) goto lab_p02_L_5151;
  set_hl(0x65B1);
  flag_cmp(a, 0xD4);
  if (flag_z()) goto lab_p02_L_5151;
  set_hl(0x65A7);
  flag_cmp(a, 0xD5);
  lab_p02_L_5151: ;
  if (flag_z()) goto lab_p02_L_51D8;
  flag_cmp(a, 0xED);
  if (flag_nz()) goto lab_p02_L_5160;
  p02_L_5316();
  a = 0x24;
  lab_p02_L_515D: ;
  p02_L_658F();
  return;
  lab_p02_L_5160: ;
  flag_cmp(a, 0xDB);
  if (flag_nz()) goto lab_p02_L_5170;
  p02_L_57DF();
  p02_L_5167();
  return;
  lab_p02_L_5170: ;
  flag_cmp(a, 0xDC);
  if (flag_nz()) goto lab_p02_L_517C;
  p02_L_57DF();
  p02_L_5177();
  return;
  lab_p02_L_517C: ;
  flag_cmp(a, 0xD1);
  if (flag_nz()) goto lab_p02_L_518B;
  p02_L_5316();
  p00_L_222C();
  a = 0x26;
  lab_p02_L_5188: ;
  p02_L_5FDA();
  return;
  lab_p02_L_518B: ;
  flag_cmp(a, 0xD2);
  if (flag_nz()) goto lab_p02_L_5199;
  p02_L_5316();
  p00_L_222C();
  a = 0x27;
  goto lab_p02_L_5188;
  lab_p02_L_5199: ;
  flag_cmp(a, 0xD9);
  if (flag_nz()) goto lab_p02_L_51A4;
  p02_L_5316();
  p02_L_51A0();
  return;
  lab_p02_L_51A4: ;
  flag_cmp(a, 0xE9);
  if (flag_nz()) goto lab_p02_L_51B1;
  p02_L_5316();
  p00_L_222C();
  p02_L_5F9A();
  return;
  lab_p02_L_51B1: ;
  flag_cmp(a, 0xDF);
  if (flag_nz()) goto lab_p02_L_51C1;
  p02_L_5316();
  p00_L_222C();
  p00_L_1229();
  p02_L_620A();
  return;
  lab_p02_L_51C1: ;
  flag_cmp(a, 0xDE);
  if (flag_nz()) goto lab_p02_L_51D1;
  p02_L_5316();
  p00_L_222C();
  p00_L_128A();
  p02_L_62A9();
  return;
  lab_p02_L_51D1: ;
  flag_cmp(a, 0xE5);
  if (flag_nz()) goto lab_p02_L_51DB;
  set_hl(0x6593);
  lab_p02_L_51D8: ;
  p02_L_5301();
  return;
  lab_p02_L_51DB: ;
  flag_cmp(a, 0xE6);
  if (flag_nz()) goto lab_p02_L_51E4;
  set_hl(0x658E);
  goto lab_p02_L_51D8;
  lab_p02_L_51E4: ;
  flag_cmp(a, 0xE8);
  if (flag_nz()) goto lab_p02_L_51ED;
  set_hl(0x659B);
  goto lab_p02_L_51D8;
  lab_p02_L_51ED: ;
  flag_cmp(a, 0xE7);
  if (flag_nz()) goto lab_p02_L_51F6;
  set_hl(0x6597);
  goto lab_p02_L_51D8;
  lab_p02_L_51F6: ;
  flag_cmp(a, 0xEB);
  if (flag_nz()) goto lab_p02_L_51FF;
  set_hl(0x65A3);
  goto lab_p02_L_51D8;
  lab_p02_L_51FF: ;
  flag_cmp(a, 0xEA);
  if (flag_nz()) goto lab_p02_L_5208;
  set_hl(0x659F);
  goto lab_p02_L_51D8;
  lab_p02_L_5208: ;
  flag_cmp(a, 0x70);
  if (flag_z()) goto lab_p02_L_5724;
  flag_cmp(a, 0x71);
  if (flag_z()) goto lab_p02_L_5770;
  flag_cmp(a, 0x82);
  if (flag_z()) goto lab_p02_L_5777;
  flag_cmp(a, 0x83);
  if (flag_z()) goto lab_p02_L_57CD;
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p02_L_55A6;
  flag_cmp(a, 0xF1);
  if (flag_z()) goto lab_p02_L_55D1;
  flag_cmp(a, 0x6A);
  if (flag_z()) goto lab_p02_L_54F3;
  flag_cmp(a, 0x6F);
  if (flag_z()) goto lab_p02_L_54F3;
  flag_cmp(a, 0x12);
  if (flag_z()) goto lab_p02_L_55DE;
  flag_cmp(a, 0x93);
  if (flag_z()) goto lab_p02_L_5696;
  flag_cmp(a, 0x14);
  if (flag_z()) goto lab_p02_L_564F;
  flag_cmp(a, 0x19);
  if (flag_z()) goto lab_p02_L_5402;
  flag_cmp(a, 0x1A);
  if (flag_z()) goto lab_p02_L_53FB;
  flag_cmp(a, 0xD6);
  if (flag_z()) goto lab_p02_L_52F4;
  flag_cmp(a, 0xD7);
  if (flag_z()) goto lab_p02_L_52FE;
  flag_cmp(a, 0x26);
  if (flag_z()) goto lab_p02_L_57D4;
  flag_cmp(a, 0x1F);
  if (flag_z()) goto lab_p02_L_588E;
  flag_cmp(a, 0x21);
  if (flag_z()) goto lab_p02_L_5883;
  flag_cmp(a, 0xD8);
  if (flag_z()) goto lab_p02_L_52A7;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p02_L_52CB;
  flag_cmp(a, 0x3C);
  if (flag_z()) goto lab_p02_L_52D0;
  flag_cmp(a, 0x3D);
  if (flag_z()) goto lab_p02_L_52D5;
  flag_cmp(a, 0x95);
  if (flag_z()) goto lab_p02_L_52DA;
  flag_cmp(a, 0x94);
  if (flag_z()) goto lab_p02_L_52DF;
  flag_cmp(a, 0x6B);
  if (flag_z()) goto lab_p02_L_52E5;
  flag_cmp(a, 0x6D);
  if (flag_z()) goto lab_p02_L_52EA;
  flag_cmp(a, 0x6C);
  if (flag_z()) goto lab_p02_L_52EF;
  flag_cmp(a, 0x6E);
  if (flag_z()) goto lab_p02_L_52F9;
  flag_cmp(a, 0x20);
  if (flag_z()) goto lab_p02_L_58D2;
  flag_cmp(a, 0xDD);
  if (flag_z()) goto lab_p02_L_6215;
  flag_cmp(a, 0x13);
  if (flag_nz()) goto lab_p02_L_52AC;
  p02_L_5316();
  p00_L_222C();
  p00_L_3909();
  if (flag_z()) { p00_L_128A(); return; }
  p00_L_1229();
  return;
  lab_p02_L_52A7: ;
  set_hl(0x4F53);
  p02_L_5301();
  return;
  lab_p02_L_52AC: ;
  set_hl(0x6581);
  flag_cmp(a, 0x1B);
  if (flag_z()) { p02_L_5301(); return; }
  set_hl(0x6572);
  flag_cmp(a, 0x1C);
  if (flag_z()) { p02_L_5301(); return; }
  set_hl(0x657D);
  flag_cmp(a, 0x1D);
  if (flag_z()) { p02_L_5301(); return; }
  set_hl(0x6578);
  flag_cmp(a, 0x1E);
  if (flag_z()) { p02_L_5301(); return; }
  p00_L_24E5();
  return;
  lab_p02_L_52CB: ;
  set_hl(0x4C37);
  p02_L_5301();
  return;
  lab_p02_L_52D0: ;
  set_hl(0x4C2B);
  p02_L_5301();
  return;
  lab_p02_L_52D5: ;
  set_hl(0x4C3D);
  p02_L_5301();
  return;
  lab_p02_L_52DA: ;
  set_hl(0x4EF5);
  p02_L_5301();
  return;
  lab_p02_L_52DF: ;
  set_hl(0x4F49);
  p02_L_5301();
  return;
  lab_p02_L_52E5: ;
  set_hl(0x4C4E);
  p02_L_5301();
  return;
  lab_p02_L_52EA: ;
  set_hl(0x3AAD);
  p02_L_5301();
  return;
  lab_p02_L_52EF: ;
  set_hl(0x4C66);
  p02_L_5301();
  return;
  lab_p02_L_52F4: ;
  set_hl(0x4B22);
  p02_L_5301();
  return;
  lab_p02_L_52F9: ;
  set_hl(0x3AB3);
  p02_L_5301();
  return;
  lab_p02_L_52FE: ;
  set_hl(0x4AD3);
  p02_L_5301();
  return;
  lab_p02_L_534E: ;
  a = b;
  /* scf */
  cpu_push_af();
  p02_L_594A();
  if (flag_nz()) { p00_L_24E9(); return; }
  mem_write16(0x84B5, de());
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p02_L_536B(); return; }
  cpu_ex_de_hl();
  mem_write16(0x84B7, hl());
  p02_L_5A22();
  p02_L_5365();
  return;
  lab_p02_L_53FB: ;
  set_hl(0x0BDA);
  d = 0x01;
  goto lab_p02_L_5407;
  lab_p02_L_5402: ;
  set_hl(0x0BE3);
  d = 0x00;
  lab_p02_L_5407: ;
  a = c;
  flag_cmp(a, 0xDD);
  if (flag_z()) goto lab_p02_L_534E;
  flag_cmp(a, 0xCC);
  if (flag_z()) goto lab_p02_L_5424;
  p00_L_1842();
  flag_cmp(a, 0xDC);
  if (flag_z()) goto lab_p02_L_546A;
  flag_cmp(a, 0xCD);
  if (flag_z()) goto lab_p02_L_5475;
  p00_L_1847();
  p02_L_5301();
  return;
  lab_p02_L_5424: ;
  cpu_push_de();
  p00_L_2222();
  p02_L_6B62();
  p00_L_1169();
  p00_L_22CC();
  p02_L_6B62();
  p00_L_1128();
  p00_L_107E();
  cpu_pop_de();
  flag_set_z((d & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_5440;
  /* ccf */
  lab_p02_L_5440: ;
  cpu_push_af();
  p00_L_2148();
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) p00_L_2148();
  cpu_pop_af();
  if (flag_c()) { p00_L_21A4(); return; }
  return;
  lab_p02_L_546A: ;
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p00_L_2222();
  p00_L_113F();
  goto lab_p02_L_547E;
  lab_p02_L_5475: ;
  cpu_push_bc();
  a = a & 0xF0;
  flag_logic(a);
  if (flag_z()) p00_L_21DB();
  cpu_pop_af();
  /* scf */
  cpu_push_af();
  lab_p02_L_547E: ;
  p02_L_59D5();
  mem_write16(0x84B5, hl());
  if (flag_z()) goto lab_p02_L_5489;
  p02_L_5A22();
  lab_p02_L_5489: ;
  p00_L_2176();
  p00_L_21D6();
  p00_L_2222();
  lab_p02_L_5492: ;
  p02_L_47C6();
  p00_L_22FC();
  p00_L_102F();
  if (flag_nz()) goto lab_p02_L_54AD;
  p00_rst08();
  p00_L_2315();
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) goto lab_p02_L_54BA;
  p00_L_149D();
  p00_L_1490();
  goto lab_p02_L_54BA;
  lab_p02_L_54AD: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) goto lab_p02_L_54BA;
  p00_L_149D();
  p00_L_102F();
  if (flag_z()) p00_L_1490();
  lab_p02_L_54BA: ;
  p00_L_21CC();
  p00_L_220A();
  cpu_pop_af();
  cpu_push_af();
  p02_L_50A3();
  p02_L_53C6();
  if (flag_c()) goto lab_p02_L_54D8;
  if (flag_nz()) goto lab_p02_L_5492;
  cpu_pop_af();
  p00_L_21A7();
  flag_set_z((mem_read8(hl()) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_21A7();
  p02_L_5B6E();
  return;
  lab_p02_L_54D8: ;
  p00_L_2176();
  p00_L_218C();
  p00_L_2222();
  p00_L_21D6();
  p02_L_53AF();
  mem_write16(0x84D7, de());
  p00_L_1842();
  p00_L_218C();
  goto lab_p02_L_5489;
  lab_p02_L_54F3: ;
  flag_cmp(a, 0x6A);
  cpu_push_af();
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_5517;
  p00_L_14A7();
  p00_L_107E();
  lab_p02_L_5500: ;
  if (flag_nz()) goto lab_p02_L_550C;
  cpu_pop_af();
  p02_L_5503();
  return;
  lab_p02_L_550C: ;
  p00_L_128A();
  cpu_pop_af();
  if (flag_z()) return;
  a = 0x10;
  mem_write8(0x847A, a);
  return;
  lab_p02_L_5517: ;
  flag_cmp(a, 0xCC);
  if (flag_nz()) goto lab_p02_L_552C;
  p02_L_65BE();
  p00_L_2242();
  p02_L_65BE();
  p02_L_6AB3();
  p00_L_14C2();
  goto lab_p02_L_5500;
  lab_p02_L_552C: ;
  flag_cmp(a, 0x22);
  if (flag_nz()) goto lab_p02_L_5566;
  p02_L_59B1();
  if (flag_nz()) { p00_L_24E9(); return; }
  mem_write16(0x84B7, de());
  lab_p02_L_553A: ;
  p02_L_403C();
  p02_L_65D4();
  p00_rst08();
  set_bc(mem_read16(0x84AF));
  set_de(mem_read16(0x84D5));
  p02_L_4044();
  p02_L_65D4();
  p00_L_107E();
  if (flag_nz()) goto lab_p02_L_5560;
  p02_L_407E();
  if (flag_nz()) goto lab_p02_L_553A;
  lab_p02_L_5559: ;
  cpu_pop_af();
  p02_L_5503();
  lab_p02_L_555D: ;
  p02_L_5B71();
  return;
  lab_p02_L_5560: ;
  cpu_pop_af();
  p02_L_550B();
  goto lab_p02_L_555D;
  lab_p02_L_5566: ;
  flag_cmp(a, 0x44);
  if (flag_nz()) goto lab_p02_L_5587;
  p02_L_59B1();
  if (flag_nz()) goto lab_p02_L_5560;
  b = d;
  c = e;
  set_hl(mem_read16(0x84D3));
  set_de(mem_read16(0x84D5));
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  lab_p02_L_557A: ;
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_5559;
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  cpu_cp_hl();
  if (flag_nz()) goto lab_p02_L_5560;
  set_bc((uint16_t)(bc() - 1));
  goto lab_p02_L_557A;
  lab_p02_L_5587: ;
  cpu_pop_bc();
  flag_cmp(a, 0x11);
  lab_p02_L_558A: ;
  if (flag_z()) goto lab_p02_L_534E;
  flag_cmp(a, 0xDD);
  if (flag_z()) goto lab_p02_L_558A;
  flag_cmp(a, 0xCD);
  lab_p02_L_5593: ;
  if (flag_z()) goto lab_p02_L_5475;
  flag_cmp(a, 0xDC);
  lab_p02_L_5598: ;
  if (flag_z()) goto lab_p02_L_546A;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_5593;
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p02_L_5598;
  p00_L_24DD();
  return;
  lab_p02_L_55A6: ;
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_55AE;
  p00_L_3915();
  return;
  lab_p02_L_55AE: ;
  flag_cmp(a, 0x20);
  if (flag_z()) { p02_L_453E(); return; }
  set_hl(0x6C77);
  lab_p02_L_55B6: ;
  flag_cmp(a, 0xCC);
  if (flag_z()) goto lab_p02_L_55C3;
  flag_cmp(a, 0xC0);
  if (flag_nz()) goto lab_p02_L_55C4;
  cpu_push_hl();
  p00_L_1287();
  lab_p02_L_55C2: ;
  cpu_pop_hl();
  lab_p02_L_55C3: ;
  os_jp_hl();
  return;
  lab_p02_L_55C4: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p02_L_55DB;
  cpu_push_hl();
  p00_L_1276();
  p00_L_221D();
  goto lab_p02_L_55C2;
  lab_p02_L_55D1: ;
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_5EAA;
  set_hl(0x6C56);
  goto lab_p02_L_55B6;
  lab_p02_L_55DB: ;
  p02_L_531C();
  return;
  lab_p02_L_55DE: ;
  a = c;
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_z()) p00_L_1179();
  p02_L_5604();
  if (flag_c()) { p00_L_24C9(); return; }
  cpu_push_de();
  p00_L_113F();
  cpu_pop_de();
  d = e;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p00_L_0FB1(); return; }
  cpu_push_de();
  flag_cmp(a, 0xC0);
  if (flag_nz()) { p02_L_561F(); return; }
  p00_L_2148();
  cpu_pop_de();
  p02_L_65C4();
  return;
  lab_p02_L_5643: ;
  p02_L_5B6E();
  return;
  lab_p02_L_564C: ;
  p00_L_24ED();
  return;
  lab_p02_L_564F: ;
  a = c;
  flag_cmp(a, 0x22);
  if (flag_z()) goto lab_p02_L_5679;
  flag_cmp(a, 0x11);
  if (flag_z()) goto lab_p02_L_5660;
  p02_L_544E();
  if (flag_nz()) goto lab_p02_L_5676;
  p00_L_1842();
  lab_p02_L_5660: ;
  p02_L_59B1();
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84B7, hl());
  p00_L_1836();
  p02_L_5A22();
  p00_L_21D6();
  p02_L_49C8();
  goto lab_p02_L_5643;
  lab_p02_L_5676: ;
  p00_L_24DD();
  return;
  lab_p02_L_5679: ;
  p02_L_59B1();
  set_hl((uint16_t)(hl() + de()));
  a = h;
  flag_cmp(a, d);
  if (flag_nz()) { p00_L_24E9(); return; }
  a = l;
  a = (uint8_t)(a + e);
  if (flag_c()) goto lab_p02_L_564C;
  flag_cmp(a, 0x64);
  if (flag_nc()) goto lab_p02_L_564C;
  l = a;
  mem_write16(0x84B7, hl());
  p02_L_5A17();
  p02_L_44D4();
  goto lab_p02_L_5643;
  lab_p02_L_5696: ;
  a = c;
  cpu_push_af();
  p02_L_656B();
  cpu_pop_af();
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p02_L_56B3;
  p00_L_21DB();
  p02_L_59F8();
  mem_write16(0x84D7, de());
  p00_L_16F4();
  p00_L_219B();
  p02_L_44C8();
  return;
  lab_p02_L_56B3: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p02_L_56CA;
  p00_L_21DB();
  lab_p02_L_56BA: ;
  p02_L_59F8();
  mem_write16(0x84D7, de());
  p00_L_17E6();
  p00_L_2176();
  p02_L_49B2();
  return;
  lab_p02_L_56CA: ;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p02_L_56D6;
  p00_L_21DB();
  p00_L_391B();
  goto lab_p02_L_56BA;
  lab_p02_L_56D6: ;
  p00_L_1842();
  flag_cmp(a, 0xCD);
  if (flag_z()) goto lab_p02_L_56BA;
  flag_cmp(a, 0xC1);
  if (flag_nz()) goto lab_p02_L_5676;
  p00_L_2222();
  p00_L_241E();
  p00_L_390F();
  p00_L_219B();
  goto lab_p02_L_56BA;
  lab_p02_L_56FB: ;
  p02_L_59B1();
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84B7, hl());
  p00_L_1C89();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_hl(mem_read16(0x84D3));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_bc(mem_read16(0x84AF));
  while (bc() != 0) { cpu_ldi(); }
  set_hl(mem_read16(0x84D5));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_bc(mem_read16(0x84B3));
  while (bc() != 0) { cpu_ldi(); }
  p00_L_1135();
  p02_L_5B71();
  return;
  lab_p02_L_5724: ;
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p00_L_0C34(); return; }
  flag_cmp(a, 0x44);
  if (flag_z()) goto lab_p02_L_56FB;
  /* scf */
  lab_p02_L_572E: ;
  cpu_push_af();
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p02_L_5740;
  p00_L_1276();
  p00_L_221D();
  lab_p02_L_5739: ;
  cpu_pop_af();
  if (flag_c()) goto lab_p02_L_6AB6;
  p02_L_6AB3();
  return;
  lab_p02_L_5740: ;
  flag_cmp(a, 0xC0);
  if (flag_nz()) goto lab_p02_L_5749;
  p00_L_1287();
  goto lab_p02_L_5739;
  lab_p02_L_5749: ;
  flag_cmp(a, 0xCC);
  if (flag_z()) goto lab_p02_L_5739;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x22);
  if (flag_z()) goto lab_p02_L_5756;
  cpu_pop_af();
  goto lab_p02_L_57CA;
  lab_p02_L_5756: ;
  p02_L_56EF();
  if (flag_z()) goto lab_p02_L_5761;
  cpu_ex_de_hl();
  p02_L_5A17();
  goto lab_p02_L_5764;
  lab_p02_L_5761: ;
  p00_L_21D6();
  lab_p02_L_5764: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) p02_L_408E();
  cpu_pop_af();
  if (flag_nc()) p02_L_408A();
  lab_p02_L_576D: ;
  p02_L_5B6E();
  return;
  lab_p02_L_5770: ;
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p00_L_0C2D(); return; }
  goto lab_p02_L_572E;
  lab_p02_L_5777: ;
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p00_L_0D1F(); return; }
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p02_L_5787;
  flag_cmp(a, 0x20);
  if (flag_nz()) goto lab_p02_L_579A;
  p00_L_149D();
  lab_p02_L_5787: ;
  p02_L_5A0F();
  p00_L_10F8();
  lab_p02_L_578D: ;
  p02_L_403C();
  p00_L_0D1F();
  p02_L_4077();
  if (flag_nz()) goto lab_p02_L_578D;
  goto lab_p02_L_576D;
  lab_p02_L_579A: ;
  flag_cmp(a, 0x22);
  if (flag_nz()) goto lab_p02_L_57A9;
  p02_L_655D();
  p02_L_5A17();
  p02_L_40BA();
  goto lab_p02_L_576D;
  lab_p02_L_57A9: ;
  /* scf */
  lab_p02_L_57AA: ;
  cpu_push_af();
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p02_L_57BC;
  p00_L_1276();
  p00_L_221D();
  lab_p02_L_57B5: ;
  cpu_pop_af();
  if (flag_c()) { p02_L_6AC8(); return; }
  p02_L_6B0E();
  return;
  lab_p02_L_57BC: ;
  flag_cmp(a, 0xC0);
  if (flag_nz()) goto lab_p02_L_57C5;
  p00_L_1287();
  goto lab_p02_L_57B5;
  lab_p02_L_57C5: ;
  flag_cmp(a, 0xCC);
  if (flag_z()) goto lab_p02_L_57B5;
  cpu_pop_af();
  lab_p02_L_57CA: ;
  p02_L_531C();
  return;
  lab_p02_L_57CD: ;
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p00_L_0ED0(); return; }
  goto lab_p02_L_57AA;
  lab_p02_L_57D4: ;
  p02_L_5316();
  p00_rst18();
  p00_L_1179();
  p02_L_67A5();
  return;
  lab_p02_L_5883: ;
  p02_L_57DF();
  a = 0;
  flag_logic(a);
  /* scf */
  p02_L_57EF();
  p02_L_5B71();
  return;
  lab_p02_L_588E: ;
  p02_L_57DF();
  p02_L_5891();
  return;
  lab_p02_L_58D2: ;
  p02_L_5316();
  p02_L_6520();
  cpu_push_af();
  p00_L_1179();
  p02_L_6520();
  cpu_pop_hl();
  l = e;
  p02_L_53EA();
  p00_L_1C7B();
  mem_write16(0x84D7, de());
  p00_L_21D6();
  p00_L_21E5();
  lab_p02_L_58F1: ;
  p00_L_2338();
  p00_L_39F9();
  p00_L_1251();
  set_hl(0x8484);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x19);
  p00_L_0D1F();
  p00_L_0BF9();
  p00_L_1251();
  a = 0x90;
  mem_write8(0x8485, a);
  p00_L_0C2D();
  p00_L_22E8();
  set_hl(mem_read16(0x84B5));
  mem_write16(0x84B7, hl());
  p02_L_4077();
  set_hl(mem_read16(0x84B7));
  mem_write16(0x84B5, hl());
  if (flag_nz()) goto lab_p02_L_58F1;
  p00_L_21A7();
  p00_L_219B();
  return;
  lab_p02_L_5EAA: ;
  p00_L_3957();
  return;
  lab_p02_L_6215: ;
  set_de(0x0001);
  cpu_push_de();
  goto lab_p02_L_6233;
  lab_p02_L_6233: ;
  p00_L_1037();
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p02_L_62A2;
  a = mem_read8(0x848E);
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p02_L_62A2;
  p02_L_59B1();
  mem_write16(0x84B5, hl());
  cpu_pop_bc();
  if (flag_c()) { p00_L_128A(); return; }
  cpu_push_bc();
  set_bc((uint16_t)(bc() - 1));
  set_hl(mem_read16(0x84D3));
  set_de(mem_read16(0x84AF));
  p02_L_6341();
  if (flag_nc()) goto lab_p02_L_6287;
  cpu_push_hl();
  set_hl(mem_read16(0x84B5));
  lab_p02_L_6260: ;
  mem_write16(0x84B1, bc());
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p02_L_6286;
  cpu_pop_hl();
  cpu_push_hl();
  set_de(mem_read16(0x84D5));
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_bc(mem_read16(0x84B3));
  lab_p02_L_6275: ;
  a = mem_read8(de());
  set_de((uint16_t)(de() + 1));
  /* cpi */
  if (flag_nz()) goto lab_p02_L_628B;
  if (flag_pe()) goto lab_p02_L_6275;
  cpu_pop_hl();
  cpu_pop_hl();
  p00_L_3B55();
  p00_L_1179();
  return;
  lab_p02_L_6286: ;
  cpu_pop_hl();
  lab_p02_L_6287: ;
  cpu_pop_hl();
  p00_L_128A();
  return;
  lab_p02_L_628B: ;
  cpu_pop_hl();
  set_bc(mem_read16(0x84B1));
  p00_L_172F();
  if (flag_nz()) goto lab_p02_L_6297;
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() + 1));
  lab_p02_L_6297: ;
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  set_bc((uint16_t)(bc() + 1));
  set_hl(mem_read16(0x84B5));
  goto lab_p02_L_6260;
  lab_p02_L_62A2: ;
  p00_L_24DD();
  return;
  lab_p02_L_6AB6: ;
  p02_L_6AB9();
  p02_L_6AB9();
  return;
}

/* flash page 2 cpu 0x512F (offset 0x112F) */
void p02_L_512F(void) {
  mem_write16(0x90CC, de());
  p00_L_16B5();
  a = 0x2C;
  p00_L_38FD();
  p02_L_5B71();
  return;
}

/* flash page 2 cpu 0x5167 (offset 0x1167) */
void p02_L_5167(void) {
  p00_L_3903();
  p02_L_6D46();
  p02_L_5B71();
  return;
}

/* flash page 2 cpu 0x5177 (offset 0x1177) */
void p02_L_5177(void) {
  goto lab_p02_L_5177;
  lab_p02_L_516D: ;
  p02_L_5B71();
  return;
  lab_p02_L_5177: ;
  p00_L_3903();
  goto lab_p02_L_516D;
}

/* flash page 2 cpu 0x51A0 (offset 0x11A0) */
void p02_L_51A0(void) {
  goto lab_p02_L_51A0;
  lab_p02_L_515D: ;
  p02_L_658F();
  return;
  lab_p02_L_51A0: ;
  a = 0x26;
  goto lab_p02_L_515D;
}

/* flash page 2 cpu 0x52E4 (offset 0x12E4) */
void p02_L_52E4(void) {
  os_jp_hl();
  return;
}

/* flash page 2 cpu 0x5301 (offset 0x1301) */
void p02_L_5301(void) {
  a = c;
  flag_cmp(a, 0x11);
  if (flag_z()) goto lab_p02_L_534E;
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p02_L_5338;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_5345;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p00_L_24DD(); return; }
  p02_L_52E4();
  return;
  lab_p02_L_5338: ;
  if (flag_z()) goto lab_p02_L_546A;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p02_L_5345;
  flag_cmp(a, 0xC1);
  if (flag_z()) goto lab_p02_L_5345;
  flag_cmp(a, 0xCD);
  lab_p02_L_5345: ;
  if (flag_z()) goto lab_p02_L_5475;
  p02_L_544E();
  if (flag_nz()) { p00_L_24DD(); return; }
  lab_p02_L_534E: ;
  a = b;
  /* scf */
  cpu_push_af();
  p02_L_594A();
  if (flag_nz()) { p00_L_24E9(); return; }
  mem_write16(0x84B5, de());
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p02_L_536B(); return; }
  cpu_ex_de_hl();
  mem_write16(0x84B7, hl());
  p02_L_5A22();
  p02_L_5365();
  return;
  lab_p02_L_546A: ;
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p00_L_2222();
  p00_L_113F();
  goto lab_p02_L_547E;
  lab_p02_L_5475: ;
  cpu_push_bc();
  a = a & 0xF0;
  flag_logic(a);
  if (flag_z()) p00_L_21DB();
  cpu_pop_af();
  /* scf */
  cpu_push_af();
  lab_p02_L_547E: ;
  p02_L_59D5();
  mem_write16(0x84B5, hl());
  if (flag_z()) goto lab_p02_L_5489;
  p02_L_5A22();
  lab_p02_L_5489: ;
  p00_L_2176();
  p00_L_21D6();
  p00_L_2222();
  lab_p02_L_5492: ;
  p02_L_47C6();
  p00_L_22FC();
  p00_L_102F();
  if (flag_nz()) goto lab_p02_L_54AD;
  p00_rst08();
  p00_L_2315();
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) goto lab_p02_L_54BA;
  p00_L_149D();
  p00_L_1490();
  goto lab_p02_L_54BA;
  lab_p02_L_54AD: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) goto lab_p02_L_54BA;
  p00_L_149D();
  p00_L_102F();
  if (flag_z()) p00_L_1490();
  lab_p02_L_54BA: ;
  p00_L_21CC();
  p00_L_220A();
  cpu_pop_af();
  cpu_push_af();
  p02_L_50A3();
  p02_L_53C6();
  if (flag_c()) goto lab_p02_L_54D8;
  if (flag_nz()) goto lab_p02_L_5492;
  cpu_pop_af();
  p00_L_21A7();
  flag_set_z((mem_read8(hl()) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_21A7();
  p02_L_5B6E();
  return;
  lab_p02_L_54D8: ;
  p00_L_2176();
  p00_L_218C();
  p00_L_2222();
  p00_L_21D6();
  p02_L_53AF();
  mem_write16(0x84D7, de());
  p00_L_1842();
  p00_L_218C();
  goto lab_p02_L_5489;
}

/* flash page 2 cpu 0x5316 (offset 0x1316) */
void p02_L_5316(void) {
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p00_L_24DD(); return; }
  return;
}

/* flash page 2 cpu 0x531C (offset 0x131C) */
void p02_L_531C(void) {
  p00_L_1847();
  flag_cmp(a, 0x11);
  if (flag_z()) goto lab_p02_L_534E;
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p02_L_5338;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_5345;
  p00_L_1842();
  flag_cmp(a, 0x1C);
  if (flag_z()) goto lab_p02_L_5338;
  flag_cmp(a, 0xD0);
  if (flag_z()) goto lab_p02_L_5338;
  flag_cmp(a, 0xDC);
  lab_p02_L_5338: ;
  if (flag_z()) goto lab_p02_L_546A;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p02_L_5345;
  flag_cmp(a, 0xC1);
  if (flag_z()) goto lab_p02_L_5345;
  flag_cmp(a, 0xCD);
  lab_p02_L_5345: ;
  if (flag_z()) goto lab_p02_L_5475;
  p02_L_544E();
  if (flag_nz()) { p00_L_24DD(); return; }
  lab_p02_L_534E: ;
  a = b;
  /* scf */
  cpu_push_af();
  p02_L_594A();
  if (flag_nz()) { p00_L_24E9(); return; }
  mem_write16(0x84B5, de());
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p02_L_536B(); return; }
  cpu_ex_de_hl();
  mem_write16(0x84B7, hl());
  p02_L_5A22();
  p02_L_5365();
  return;
  lab_p02_L_546A: ;
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p00_L_2222();
  p00_L_113F();
  goto lab_p02_L_547E;
  lab_p02_L_5475: ;
  cpu_push_bc();
  a = a & 0xF0;
  flag_logic(a);
  if (flag_z()) p00_L_21DB();
  cpu_pop_af();
  /* scf */
  cpu_push_af();
  lab_p02_L_547E: ;
  p02_L_59D5();
  mem_write16(0x84B5, hl());
  if (flag_z()) goto lab_p02_L_5489;
  p02_L_5A22();
  lab_p02_L_5489: ;
  p00_L_2176();
  p00_L_21D6();
  p00_L_2222();
  lab_p02_L_5492: ;
  p02_L_47C6();
  p00_L_22FC();
  p00_L_102F();
  if (flag_nz()) goto lab_p02_L_54AD;
  p00_rst08();
  p00_L_2315();
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) goto lab_p02_L_54BA;
  p00_L_149D();
  p00_L_1490();
  goto lab_p02_L_54BA;
  lab_p02_L_54AD: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) goto lab_p02_L_54BA;
  p00_L_149D();
  p00_L_102F();
  if (flag_z()) p00_L_1490();
  lab_p02_L_54BA: ;
  p00_L_21CC();
  p00_L_220A();
  cpu_pop_af();
  cpu_push_af();
  p02_L_50A3();
  p02_L_53C6();
  if (flag_c()) goto lab_p02_L_54D8;
  if (flag_nz()) goto lab_p02_L_5492;
  cpu_pop_af();
  p00_L_21A7();
  flag_set_z((mem_read8(hl()) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_21A7();
  p02_L_5B6E();
  return;
  lab_p02_L_54D8: ;
  p00_L_2176();
  p00_L_218C();
  p00_L_2222();
  p00_L_21D6();
  p02_L_53AF();
  mem_write16(0x84D7, de());
  p00_L_1842();
  p00_L_218C();
  goto lab_p02_L_5489;
}

/* flash page 2 cpu 0x5365 (offset 0x1365) */
void p02_L_5365(void) {
  set_hl(mem_read16(0x84B7));
  mem_write16(0x84B5, hl());
  p02_L_536B();
  return;
}

/* flash page 2 cpu 0x536B (offset 0x136B) */
void p02_L_536B(void) {
  p00_L_21D6();
  lab_p02_L_536E: ;
  p00_L_21CC();
  p02_L_479B();
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p02_L_537D;
  p02_L_5A53();
  goto lab_p02_L_5388;
  lab_p02_L_537D: ;
  p00_L_2222();
  p02_L_47BD();
  cpu_pop_af();
  cpu_push_af();
  p02_L_50A3();
  lab_p02_L_5388: ;
  p02_L_53C6();
  if (flag_c()) goto lab_p02_L_5393;
  if (flag_nz()) goto lab_p02_L_536E;
  cpu_pop_af();
  p02_L_5B6E();
  return;
  lab_p02_L_5393: ;
  p02_L_53AF();
  set_bc(mem_read16(0x84D5));
  set_hl(mem_read16(0x84D7));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nz()) goto lab_p02_L_53A6;
  mem_write16(0x84D5, de());
  lab_p02_L_53A6: ;
  mem_write16(0x84D7, de());
  p00_L_1842();
  goto lab_p02_L_536E;
}

/* flash page 2 cpu 0x53AF (offset 0x13AF) */
void p02_L_53AF(void) {
  set_de(mem_read16(0x84D7));
  p00_L_390F();
  set_bc(mem_read16(0x84D3));
  set_hl(mem_read16(0x84D7));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nz()) return;
  mem_write16(0x84D3, de());
  return;
}

/* flash page 2 cpu 0x53C6 (offset 0x13C6) */
void p02_L_53C6(void) {
  p00_L_2182();
  p00_L_102F();
  if (flag_nz()) goto lab_p02_L_53D5;
  p00_L_184C();
  if (flag_nz()) goto lab_p02_L_53DB;
  /* scf */
  return;
  lab_p02_L_53D5: ;
  p00_L_184C();
  if (flag_nz()) p00_L_104B();
  lab_p02_L_53DB: ;
  set_hl(mem_read16(0x84B5));
  p02_L_47D8();
  set_hl(mem_read16(0x84B5));
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  mem_write16(0x84B3, hl());
  p02_L_53EA();
  return;
}

/* flash page 2 cpu 0x53EA (offset 0x13EA) */
void p02_L_53EA(void) {
  mem_write16(0x84B5, hl());
  mem_write16(0x84AF, hl());
  return;
}

/* flash page 2 cpu 0x53F1 (offset 0x13F1) */
void p02_L_53F1(void) {
  mem_write16(0x84B3, hl());
  mem_write16(0x84B7, hl());
  mem_write16(0x84AF, hl());
  return;
}

/* flash page 2 cpu 0x544E (offset 0x144E) */
void p02_L_544E(void) {
  flag_cmp(a, 0xDD);
  if (flag_z()) return;
  flag_cmp(a, 0x1D);
  if (flag_z()) return;
  flag_cmp(a, 0xD1);
  return;
}

/* flash page 2 cpu 0x5503 (offset 0x1503) */
void p02_L_5503(void) {
  cpu_push_af();
  p00_L_128A();
  cpu_pop_af();
  if (flag_nz()) return;
  goto lab_p02_L_5511;
  lab_p02_L_5511: ;
  a = 0x10;
  mem_write8(0x847A, a);
  return;
}

/* flash page 2 cpu 0x550B (offset 0x150B) */
void p02_L_550B(void) {
  cpu_push_af();
  p00_L_128A();
  cpu_pop_af();
  if (flag_z()) return;
  a = 0x10;
  mem_write8(0x847A, a);
  return;
}

/* flash page 2 cpu 0x5601 (offset 0x1601) */
void p02_L_5601(void) {
  p00_L_1037();
  p02_L_5604();
  return;
}

/* flash page 2 cpu 0x5604 (offset 0x1604) */
void p02_L_5604(void) {
  goto lab_p02_L_5604;
  lab_p02_L_55A3: ;
  p00_L_24DD();
  return;
  lab_p02_L_55E7: ;
  if (flag_c()) { p00_L_24C9(); return; }
  cpu_push_de();
  p00_L_113F();
  cpu_pop_de();
  d = e;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p00_L_0FB1(); return; }
  cpu_push_de();
  flag_cmp(a, 0xC0);
  if (flag_nz()) { p02_L_561F(); return; }
  p00_L_2148();
  cpu_pop_de();
  p02_L_65C4();
  return;
  lab_p02_L_5604: ;
  a = a & 0x0F;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_55A3;
  p00_L_187F();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x81);
  /* ccf */
  if (flag_c()) goto lab_p02_L_55E7;
  p00_rst08();
  p00_L_3B5B();
  set_hl(0x0009);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p02_L_55E7;
  return;
}

/* flash page 2 cpu 0x561F (offset 0x161F) */
void p02_L_561F(void) {
  flag_cmp(a, 0x20);
  if (flag_nz()) goto lab_p02_L_562C;
  p02_L_5A0F();
  cpu_pop_af();
  p02_L_4488();
  goto lab_p02_L_5643;
  lab_p02_L_562C: ;
  p00_L_1100();
  p00_L_1179();
  b = 0x12;
  cpu_pop_de();
  flag_set_z((d & (1u << 7)) == 0);
  if (flag_z()) { p02_L_531C(); return; }
  p00_L_12B1();
  p00_L_113F();
  p02_L_58B4();
  return;
  lab_p02_L_5643: ;
  p02_L_5B6E();
  return;
}

/* flash page 2 cpu 0x5646 (offset 0x1646) */
void p02_L_5646(void) {
  p02_L_59F8();
  p02_L_5649();
  return;
}

/* flash page 2 cpu 0x5649 (offset 0x1649) */
void p02_L_5649(void) {
  a = h;
  flag_cmp(a, l);
  if (flag_z()) return;
  p00_L_24ED();
  return;
}

/* flash page 2 cpu 0x56EF (offset 0x16EF) */
void p02_L_56EF(void) {
  p02_L_594A();
  if (flag_nz()) { p00_L_24E9(); return; }
  mem_write16(0x84B7, de());
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 2 cpu 0x57DF (offset 0x17DF) */
void p02_L_57DF(void) {
  goto lab_p02_L_57DF;
  lab_p02_L_5362: ;
  p02_L_5A22();
  p02_L_5365();
  return;
  lab_p02_L_57DF: ;
  a = c;
  flag_cmp(a, 0x11);
  if (flag_nz()) goto lab_p02_L_58C0;
  p02_L_6042();
  p02_L_59B1();
  if (flag_nz()) { p00_L_24E9(); return; }
  return;
  lab_p02_L_58C0: ;
  if (flag_nz()) { p00_L_24DD(); return; }
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p02_L_59D5();
  mem_write16(0x84B7, hl());
  if (flag_nz()) goto lab_p02_L_5362;
  p02_L_5365();
  return;
}

/* flash page 2 cpu 0x57EF (offset 0x17EF) */
void p02_L_57EF(void) {
  cpu_push_af();
  p00_L_128A();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  /* res 1,(iy) */
  lab_p02_L_57FA: ;
  p00_L_1229();
  set_de(mem_read16(0x84D5));
  a = d;
  a = a | a;
  flag_logic(a);
  set_hl(mem_read16(0x84AF));
  if (flag_nz()) p02_L_47A2();
  p00_L_15CB();
  if (flag_nz()) { p00_L_2515(); return; }
  p00_L_14E1();
  if (flag_z()) goto lab_p02_L_5818;
  /* set 1,(iy) */
  lab_p02_L_5818: ;
  p00_rst18();
  p00_L_2310();
  p00_rst30();
  p00_L_235C();
  p02_L_479B();
  cpu_pop_af();
  cpu_push_af();
  a = a & 0xFE;
  flag_logic(a);
  flag_cmp(a, 0x02);
  if (flag_z()) p02_L_6E0B();
  p00_L_22F7();
  p00_L_0D1F();
  p00_L_231F();
  p00_rst30();
  p00_L_2375();
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p02_L_5859;
  set_hl(mem_read16(0x84AF));
  p02_L_4795();
  cpu_pop_af();
  cpu_push_af();
  a = a & 0xFD;
  flag_logic(a);
  flag_cmp(a, 0x01);
  if (flag_z()) p02_L_6E0B();
  p00_L_22F7();
  p00_L_0D1F();
  p00_L_22C7();
  p00_rst30();
  p00_L_2389();
  lab_p02_L_5859: ;
  p00_L_21A7();
  set_hl(mem_read16(0x84AF));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x84AF, hl());
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_57FA;
  p00_L_2196();
  p00_L_219B();
  p00_L_1171();
  p00_L_0ED0();
  cpu_pop_af();
  if (flag_c()) { p00_L_21A7(); return; }
  p00_L_10DD();
  p00_L_219B();
  p00_L_1169();
  p00_L_0ED0();
  return;
}

/* flash page 2 cpu 0x5891 (offset 0x1891) */
void p02_L_5891(void) {
  goto lab_p02_L_5891;
  lab_p02_L_588B: ;
  p02_L_5B71();
  return;
  lab_p02_L_5891: ;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 4)));
  set_hl(mem_read16(0x84D5));
  mem_write16(0x84DB, hl());
  p00_L_3927();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 4)));
  p00_L_1100();
  p00_L_219B();
  p00_rst10();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  p00_L_113F();
  goto lab_p02_L_588B;
}

/* flash page 2 cpu 0x58B4 (offset 0x18B4) */
void p02_L_58B4(void) {
  goto lab_p02_L_58B4;
  lab_p02_L_5362: ;
  p02_L_5A22();
  p02_L_5365();
  return;
  lab_p02_L_58B4: ;
  p00_L_1847();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_58C3;
  p00_L_1842();
  flag_cmp(a, 0x0D);
  if (flag_nz()) { p00_L_24DD(); return; }
  lab_p02_L_58C3: ;
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p02_L_59D5();
  mem_write16(0x84B7, hl());
  if (flag_nz()) goto lab_p02_L_5362;
  p02_L_5365();
  return;
}

/* flash page 2 cpu 0x592C (offset 0x192C) */
void p02_L_592C(void) {
  p00_L_241E();
  if (flag_c()) { p00_L_24F1(); return; }
  p00_L_1641();
  if (flag_nz()) return;
  p02_L_5936();
  return;
}

/* flash page 2 cpu 0x5936 (offset 0x1936) */
void p02_L_5936(void) {
  a = mem_read8(0x9817);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_5941;
  mem_write16(0x981A, hl());
  goto lab_p02_L_5944;
  lab_p02_L_5941: ;
  mem_write16(0x9818, hl());
  lab_p02_L_5944: ;
  a = (uint8_t)(a + 1);
  mem_write8(0x9817, a);
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 2 cpu 0x594A (offset 0x194A) */
void p02_L_594A(void) {
  p02_L_59BF();
  cpu_push_hl();
  if (flag_nz()) goto lab_p02_L_595C;
  a = mem_read8(0x8478);
  p00_L_184C();
  if (flag_nz()) goto lab_p02_L_595F;
  flag_set_z((a & (1u << 3)) == 0);
  if (flag_z()) goto lab_p02_L_5963;
  lab_p02_L_595C: ;
  /* scf */
  goto lab_p02_L_5970;
  lab_p02_L_595F: ;
  flag_set_z((a & (1u << 3)) == 0);
  if (flag_z()) goto lab_p02_L_595C;
  lab_p02_L_5963: ;
  set_hl(mem_read16(0x84D5));
  mem_write16(0x84D7, hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x9817, a);
  p00_L_10DD();
  lab_p02_L_5970: ;
  cpu_push_af();
  p00_L_113F();
  p02_L_592C();
  if (flag_nz()) goto lab_p02_L_598A;
  cpu_pop_af();
  if (flag_nc()) goto lab_p02_L_59A6;
  a = mem_read8(0x8478);
  p00_L_184C();
  if (flag_nz()) goto lab_p02_L_598F;
  flag_set_z((a & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p02_L_59BB;
  goto lab_p02_L_5993;
  lab_p02_L_598A: ;
  cpu_pop_af();
  if (flag_nc()) goto lab_p02_L_59A6;
  goto lab_p02_L_59BB;
  lab_p02_L_598F: ;
  flag_set_z((a & (1u << 3)) == 0);
  if (flag_z()) goto lab_p02_L_59BB;
  lab_p02_L_5993: ;
  mem_write16(0x84D7, de());
  set_hl(0x9817);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  set_hl(mem_read16(0x981A));
  mem_write16(0x9818, hl());
  cpu_push_de();
  p00_L_10DD();
  cpu_pop_de();
  lab_p02_L_59A6: ;
  a = 0;
  flag_logic(a);
  lab_p02_L_59A7: ;
  cpu_push_af();
  p02_L_59FB();
  cpu_pop_af();
  cpu_pop_de();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  return;
  lab_p02_L_59BB: ;
  a = 0x01;
  goto lab_p02_L_59A7;
}

/* flash page 2 cpu 0x59B1 (offset 0x19B1) */
void p02_L_59B1(void) {
  goto lab_p02_L_59B1;
  lab_p02_L_59A7: ;
  cpu_push_af();
  p02_L_59FB();
  cpu_pop_af();
  cpu_pop_de();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  return;
  lab_p02_L_59B1: ;
  p02_L_59BF();
  cpu_push_hl();
  p00_L_113F();
  p02_L_592C();
  a = 0x01;
  goto lab_p02_L_59A7;
}

/* flash page 2 cpu 0x59BF (offset 0x19BF) */
void p02_L_59BF(void) {
  p02_L_592C();
  mem_write16(0x84D5, de());
  a = mem_read8(de());
  l = a;
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  cpu_push_af();
  a = a | l;
  flag_logic(a);
  if (flag_z()) { p00_L_24ED(); return; }
  cpu_pop_af();
  h = a;
  mem_write16(0x84B3, hl());
  return;
}

/* flash page 2 cpu 0x59D5 (offset 0x19D5) */
void p02_L_59D5(void) {
  p00_L_10DD();
  p02_L_59F8();
  set_de((uint16_t)(de() + 1));
  if (flag_nz()) return;
  a = mem_read8(0x8478);
  p00_L_184C();
  if (flag_nz()) goto lab_p02_L_59F2;
  flag_set_z((a & (1u << 3)) == 0);
  if (flag_nz()) return;
  lab_p02_L_59E8: ;
  set_de((uint16_t)(de() - 1));
  mem_write16(0x84D7, de());
  a = 0;
  flag_logic(a);
  mem_write8(0x9817, a);
  return;
  lab_p02_L_59F2: ;
  flag_set_z((a & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p02_L_59E8;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 2 cpu 0x59F8 (offset 0x19F8) */
void p02_L_59F8(void) {
  p02_L_592C();
  p02_L_59FB();
  return;
}

/* flash page 2 cpu 0x59FB (offset 0x19FB) */
void p02_L_59FB(void) {
  mem_write16(0x84D3, de());
  a = mem_read8(de());
  l = a;
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  set_de((uint16_t)(de() - 1));
  cpu_push_af();
  a = a | l;
  flag_logic(a);
  if (flag_z()) { p00_L_24ED(); return; }
  cpu_pop_af();
  h = a;
  mem_write16(0x84AF, hl());
  return;
}

/* flash page 2 cpu 0x5A0F (offset 0x1A0F) */
void p02_L_5A0F(void) {
  p02_L_59D5();
  mem_write16(0x84B7, hl());
  if (flag_z()) goto lab_p02_L_5A1A;
  p02_L_5A17();
  return;
  lab_p02_L_5A1A: ;
  p00_L_21D6();
  return;
}

/* flash page 2 cpu 0x5A17 (offset 0x1A17) */
void p02_L_5A17(void) {
  p02_L_5A1D();
  p00_L_21D6();
  return;
}

/* flash page 2 cpu 0x5A1D (offset 0x1A1D) */
void p02_L_5A1D(void) {
  p00_L_1C7B();
  goto lab_p02_L_5A2D;
  lab_p02_L_5A2D: ;
  mem_write16(0x84D7, de());
  return;
}

/* flash page 2 cpu 0x5A22 (offset 0x1A22) */
void p02_L_5A22(void) {
  p00_L_184C();
  cpu_push_af();
  if (flag_z()) p00_L_1C40();
  cpu_pop_af();
  if (flag_nz()) p00_L_1C6F();
  mem_write16(0x84D7, de());
  return;
}

/* flash page 2 cpu 0x5A32 (offset 0x1A32) */
void p02_L_5A32(void) {
  goto lab_p02_L_5A32;
  lab_p02_L_5A1A: ;
  p00_L_21D6();
  return;
  lab_p02_L_5A32: ;
  p02_L_59D5();
  mem_write16(0x84B7, hl());
  if (flag_z()) goto lab_p02_L_5A1A;
  p02_L_5A22();
  a = mem_read8(0x8499);
  p02_L_451A();
  set_hl(mem_read16(0x84D7));
  mem_write16(0x84D3, hl());
  goto lab_p02_L_5A1A;
}

/* flash page 2 cpu 0x5A4B (offset 0x1A4B) */
void p02_L_5A4B(void) {
  set_hl(0x9817);
  mem_write8(hl(), 0x00);
  p00_L_1847();
  p02_L_5A53();
  return;
}

/* flash page 2 cpu 0x5A53 (offset 0x1A53) */
void p02_L_5A53(void) {
  goto lab_p02_L_5A53;
  lab_p02_L_5362: ;
  p02_L_5A22();
  p02_L_5365();
  return;
  lab_p02_L_5457: ;
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p02_L_59F8();
  mem_write16(0x84B5, hl());
  p00_L_1C40();
  mem_write16(0x84D7, de());
  p02_L_536B();
  return;
  lab_p02_L_58BB: ;
  p00_L_1842();
  flag_cmp(a, 0x0D);
  if (flag_nz()) { p00_L_24DD(); return; }
  lab_p02_L_58C3: ;
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p02_L_59D5();
  mem_write16(0x84B7, hl());
  if (flag_nz()) goto lab_p02_L_5362;
  p02_L_5365();
  return;
  lab_p02_L_5A53: ;
  cpu_push_af();
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_z()) { p00_L_24FD(); return; }
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  a = b;
  flag_cmp(a, 0xC0);
  if (flag_nz()) goto lab_p02_L_5A73;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5A6B;
  p02_L_6E20();
  return;
  lab_p02_L_5A6B: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p02_L_5ACD;
  p02_L_6C02();
  return;
  lab_p02_L_5A73: ;
  flag_cmp(a, 0xC1);
  if (flag_nz()) goto lab_p02_L_5A86;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5A7E;
  p02_L_6F74();
  return;
  lab_p02_L_5A7E: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p02_L_5ACD;
  p02_L_6C23();
  return;
  lab_p02_L_5A86: ;
  flag_cmp(a, 0xBE);
  if (flag_nz()) goto lab_p02_L_5A99;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5A91;
  p02_L_6E15();
  return;
  lab_p02_L_5A91: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p02_L_5ACD;
  p02_L_6BE5();
  return;
  lab_p02_L_5A99: ;
  flag_cmp(a, 0xBF);
  if (flag_nz()) goto lab_p02_L_5AAC;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5AA4;
  p02_L_6F6A();
  return;
  lab_p02_L_5AA4: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_6C38();
  return;
  lab_p02_L_5AAC: ;
  flag_cmp(a, 0xB8);
  if (flag_nz()) goto lab_p02_L_5AB7;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_4C49();
  return;
  lab_p02_L_5AB7: ;
  flag_cmp(a, 0xC2);
  if (flag_nz()) goto lab_p02_L_5AC2;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_7250();
  return;
  lab_p02_L_5AC2: ;
  flag_cmp(a, 0xC3);
  if (flag_nz()) goto lab_p02_L_5ACF;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5ACD;
  p02_L_75FF();
  return;
  lab_p02_L_5ACD: ;
  goto lab_p02_L_5B06;
  lab_p02_L_5ACF: ;
  flag_cmp(a, 0xC4);
  if (flag_nz()) goto lab_p02_L_5ADA;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_7254();
  return;
  lab_p02_L_5ADA: ;
  flag_cmp(a, 0xC5);
  if (flag_nz()) goto lab_p02_L_5AE5;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_75ED();
  return;
  lab_p02_L_5AE5: ;
  flag_cmp(a, 0xC6);
  if (flag_nz()) goto lab_p02_L_5AF0;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_7258();
  return;
  lab_p02_L_5AF0: ;
  flag_cmp(a, 0xC7);
  if (flag_nz()) goto lab_p02_L_5AFB;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_75F7();
  return;
  lab_p02_L_5AFB: ;
  flag_cmp(a, 0xC8);
  if (flag_nz()) goto lab_p02_L_5B09;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_7540();
  return;
  lab_p02_L_5B06: ;
  p02_L_58B4();
  return;
  lab_p02_L_5B09: ;
  flag_cmp(a, 0xC9);
  if (flag_nz()) goto lab_p02_L_5B14;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_7864();
  return;
  lab_p02_L_5B14: ;
  flag_cmp(a, 0xCA);
  if (flag_nz()) goto lab_p02_L_5B1F;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_753C();
  return;
  lab_p02_L_5B1F: ;
  flag_cmp(a, 0xCB);
  if (flag_nz()) goto lab_p02_L_5B2A;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_7872();
  return;
  lab_p02_L_5B2A: ;
  flag_cmp(a, 0xCC);
  if (flag_nz()) goto lab_p02_L_5B35;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_7538();
  return;
  lab_p02_L_5B35: ;
  flag_cmp(a, 0xCD);
  if (flag_nz()) goto lab_p02_L_5B40;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_7817();
  return;
  lab_p02_L_5B40: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p02_L_5B88;
  cpu_pop_af();
  if (flag_z()) { p00_L_0ECC(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) { p02_L_6B01(); return; }
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p02_L_5B06;
  p02_L_5E10();
  a = mem_read8(0x84AF);
  h = 0x00;
  l = a;
  p00_L_1C89();
  mem_write16(0x84D5, de());
  p00_L_21D6();
  a = 0;
  flag_logic(a);
  p02_L_429D();
  p00_L_219B();
  p02_L_5B6B();
  return;
  lab_p02_L_5B88: ;
  flag_cmp(a, 0xB3);
  if (flag_nz()) goto lab_p02_L_5BAB;
  cpu_pop_af();
  p02_L_6534();
  p02_L_5646();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x24);
  if (flag_z()) goto lab_p02_L_5BA3;
  p02_L_5A1D();
  p02_L_5936();
  p02_L_5E21();
  lab_p02_L_5BA3: ;
  a = 0x40;
  p02_L_429D();
  p02_L_5B71();
  return;
  lab_p02_L_5BAB: ;
  flag_cmp(a, 0xBC);
  if (flag_nz()) goto lab_p02_L_5BBE;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5BB6;
  p02_L_6D49();
  return;
  lab_p02_L_5BB6: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p02_L_5BE9;
  p02_L_6B9F();
  return;
  lab_p02_L_5BBE: ;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p02_L_5BEC;
  cpu_pop_af();
  if (flag_z()) { p00_L_0D1E(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p02_L_6AC5;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p02_L_5BE9;
  p02_L_5646();
  p02_L_5A17();
  p02_L_4525();
  set_hl(mem_read16(0x84D3));
  mem_write16(0x84D5, hl());
  set_hl(mem_read16(0x84AF));
  p02_L_53F1();
  p02_L_40BA();
  goto lab_p02_L_5C07;
  lab_p02_L_5BE9: ;
  p02_L_58B4();
  return;
  lab_p02_L_5BEC: ;
  flag_cmp(a, 0xB0);
  if (flag_nz()) goto lab_p02_L_5C0D;
  cpu_pop_af();
  if (flag_z()) { p00_L_0E4C(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) { p00_L_0E49(); return; }
  d = 0x05;
  p02_L_5BFB();
  return;
  lab_p02_L_5C07: ;
  p02_L_5B6E();
  return;
  lab_p02_L_5C0D: ;
  flag_cmp(a, 0xB9);
  if (flag_nz()) goto lab_p02_L_5C1E;
  cpu_pop_af();
  if (flag_z()) { p00_L_0C0F(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p02_L_6CD8;
  d = 0x06;
  p02_L_5BFB();
  return;
  lab_p02_L_5C1E: ;
  flag_cmp(a, 0xBA);
  if (flag_nz()) goto lab_p02_L_5C2F;
  cpu_pop_af();
  if (flag_z()) { p00_L_0E72(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p02_L_6CEA;
  d = 0x07;
  p02_L_5BFB();
  return;
  lab_p02_L_5C2F: ;
  flag_cmp(a, 0xB1);
  if (flag_nz()) goto lab_p02_L_5C40;
  cpu_pop_af();
  if (flag_z()) { p00_L_0BF9(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p02_L_6CF8;
  d = 0x08;
  p02_L_5BFB();
  return;
  lab_p02_L_5C40: ;
  flag_cmp(a, 0x26);
  if (flag_nz()) goto lab_p02_L_5C51;
  cpu_pop_af();
  p02_L_660A();
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_z()) { p00_L_24FD(); return; }
  return;
  lab_p02_L_5C51: ;
  flag_cmp(a, 0x89);
  if (flag_nz()) goto lab_p02_L_5C76;
  cpu_pop_af();
  if (flag_z()) return;
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p02_L_6CAA;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p02_L_58BB;
  p02_L_5C61();
  return;
  lab_p02_L_5C76: ;
  flag_cmp(a, 0x2D);
  if (flag_nz()) goto lab_p02_L_5C88;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5C81;
  p00_L_394B();
  return;
  lab_p02_L_5C81: ;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_58C3;
  goto lab_p02_L_5C9F;
  lab_p02_L_5C88: ;
  flag_cmp(a, 0xB2);
  if (flag_nz()) goto lab_p02_L_5CA2;
  cpu_pop_af();
  if (flag_z()) { p00_L_15D6(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) { p02_L_6B62(); return; }
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p02_L_5457;
  d = 0x04;
  p02_L_5BFB();
  return;
  lab_p02_L_5C9F: ;
  p00_L_24DD();
  return;
  lab_p02_L_5CA2: ;
  flag_cmp(a, 0xB4);
  if (flag_nz()) goto lab_p02_L_5CC0;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5C9F;
  p02_L_6520();
  h = a;
  l = a;
  mem_write16(0x84B7, hl());
  p00_L_1C7B();
  mem_write16(0x84D7, de());
  p00_L_21D6();
  p02_L_4102();
  goto lab_p02_L_5CD8;
  lab_p02_L_5CC0: ;
  flag_cmp(a, 0x0E);
  if (flag_nz()) goto lab_p02_L_5CDB;
  cpu_pop_af();
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p02_L_5C9F;
  p02_L_59F8();
  a = h;
  h = l;
  l = a;
  mem_write16(0x84B7, hl());
  p02_L_5A17();
  p02_L_4124();
  lab_p02_L_5CD8: ;
  p02_L_5B6E();
  return;
  lab_p02_L_5CDB: ;
  flag_cmp(a, 0xB6);
  if (flag_nz()) goto lab_p02_L_5CE4;
  set_hl(0x3B3D);
  goto lab_p02_L_5CF4;
  lab_p02_L_5CE4: ;
  flag_cmp(a, 0xB7);
  if (flag_nz()) goto lab_p02_L_5CED;
  set_hl(0x4962);
  goto lab_p02_L_5CF4;
  lab_p02_L_5CED: ;
  flag_cmp(a, 0x1A);
  if (flag_nz()) goto lab_p02_L_5D03;
  set_hl(0x3B31);
  lab_p02_L_5CF4: ;
  p02_L_6042();
  cpu_pop_af();
  cpu_push_hl();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_5D17;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p02_L_5D17;
  goto lab_p02_L_5C9F;
  lab_p02_L_5D03: ;
  flag_cmp(a, 0x19);
  if (flag_nz()) goto lab_p02_L_5D35;
  set_hl(0x3B37);
  goto lab_p02_L_5CF4;
  lab_p02_L_5D17: ;
  p02_L_59F8();
  set_hl(0x0001);
  mem_write16(0x84B1, hl());
  p02_L_5D20();
  return;
  lab_p02_L_5D28: ;
  p00_L_24DD();
  return;
  lab_p02_L_5D35: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p02_L_5D3F;
  cpu_pop_af();
  if (flag_z()) { p02_L_4B39(); return; }
  goto lab_p02_L_5D28;
  lab_p02_L_5D3F: ;
  flag_cmp(a, 0x8A);
  if (flag_nz()) goto lab_p02_L_5D52;
  cpu_pop_af();
  if (flag_z()) return;
  flag_cmp(a, 0x0C);
  if (flag_z()) { p00_L_1040(); return; }
  p02_L_5D4A();
  return;
  lab_p02_L_5D52: ;
  flag_cmp(a, 0x8B);
  if (flag_nz()) goto lab_p02_L_5D66;
  cpu_pop_af();
  if (flag_z()) { p00_L_128A(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) { p00_L_103D(); return; }
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_5D95;
  p02_L_5D4A();
  return;
  lab_p02_L_5D66: ;
  flag_cmp(a, 0x8C);
  if (flag_nz()) goto lab_p02_L_5DA1;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5D78;
  p00_L_15CB();
  if (flag_z()) { p00_L_128A(); return; }
  a = 0x04;
  p00_L_152C();
  return;
  lab_p02_L_5D78: ;
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p02_L_65B5;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p02_L_5D8D;
  p02_L_5A0F();
  p00_L_128A();
  p02_L_44C8();
  p02_L_5D32();
  return;
  lab_p02_L_5D8D: ;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p02_L_5457;
  p02_L_58B4();
  return;
  lab_p02_L_5D95: ;
  p02_L_5A32();
  p00_L_128A();
  p02_L_49B2();
  p02_L_5D32();
  return;
  lab_p02_L_5DA1: ;
  flag_cmp(a, 0x8E);
  if (flag_nz()) goto lab_p02_L_5DF6;
  cpu_pop_af();
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p02_L_5D28;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1F)) & (1u << 0)) == 0);
  if (flag_nz()) { p00_L_2501(); return; }
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 0)));
  p00_L_241E();
  if (flag_c()) { p00_L_24F1(); return; }
  cpu_ex_de_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  flag_cmp(a, e);
  if (flag_z()) { p00_L_24FD(); return; }
  d = a;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x84DD, hl());
  cpu_ex_de_hl();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_3951();
  set_hl(mem_read16(0x84DD));
  cpu_pop_bc();
  while (bc() != 0) { cpu_ldi(); }
  p00_L_1135();
  set_hl(0x5DEF);
  p00_L_25A2();
  p00_L_39E7();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 0)));
  p00_L_1717();
  p02_L_5B71();
  return;
  lab_p02_L_5DF6: ;
  flag_cmp(a, 0x12);
  if (flag_nz()) goto lab_p02_L_5E30;
  cpu_pop_af();
  if (flag_z()) { p02_L_65D4(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) { p02_L_65BE(); return; }
  p00_L_12B9();
  set_de(0x8000);
  cpu_push_de();
  p02_L_561F();
  return;
  lab_p02_L_5E0D: ;
  p00_L_24DD();
  return;
  lab_p02_L_5E30: ;
  flag_cmp(a, 0x8F);
  if (flag_nz()) goto lab_p02_L_5E5D;
  cpu_pop_af();
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p02_L_5D28;
  p02_L_592C();
  cpu_ex_de_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  c = e;
  b = d;
  lab_p02_L_5E43: ;
  set_hl((uint16_t)(hl() + 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_5E53;
  set_bc((uint16_t)(bc() - 1));
  p00_L_172F();
  if (flag_nz()) goto lab_p02_L_5E43;
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() - 1));
  set_bc((uint16_t)(bc() - 1));
  goto lab_p02_L_5E43;
  lab_p02_L_5E53: ;
  cpu_ex_de_hl();
  p00_L_3B55();
  p00_L_1179();
  p02_L_5EF2();
  return;
  lab_p02_L_5E5D: ;
  flag_cmp(a, 0x0F);
  if (flag_nz()) goto lab_p02_L_5E87;
  cpu_pop_af();
  if (flag_z()) { p00_L_0D11(); return; }
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p02_L_5E79;
  p00_L_222C();
  p00_L_1235();
  p00_L_1287();
  p00_L_104E();
  p02_L_6C77();
  return;
  lab_p02_L_5E79: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) { p02_L_58B4(); return; }
  p00_L_1100();
  p00_L_1235();
  p02_L_453E();
  return;
  lab_p02_L_5E87: ;
  flag_cmp(a, 0xBD);
  if (flag_nz()) goto lab_p02_L_5EAE;
  cpu_pop_af();
  if (flag_z()) goto lab_p02_L_5EA6;
  flag_cmp(a, 0x0C);
  if (flag_nz()) { p02_L_58B4(); return; }
  set_hl(0x848E);
  p00_L_1224();
  p00_L_21DB();
  p00_L_127B();
  p00_L_21DB();
  p02_L_6C56();
  return;
  lab_p02_L_5EA6: ;
  p00_rst08();
  p00_L_1235();
  p00_L_3957();
  return;
  lab_p02_L_5EAE: ;
  flag_cmp(a, 0xB5);
  if (flag_nz()) goto lab_p02_L_5EFE;
  cpu_pop_af();
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p02_L_5EDB;
  p02_L_59F8();
  cpu_push_hl();
  set_hl(0x0002);
  p02_L_5A22();
  cpu_pop_hl();
  cpu_push_hl();
  p02_L_5EF6();
  set_hl(0x0002);
  p02_L_47D8();
  cpu_pop_hl();
  p02_L_5EF5();
  set_hl(0x0001);
  p02_L_47D8();
  p00_L_1135();
  goto lab_p02_L_5EEF;
  lab_p02_L_5EDB: ;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_5EE4;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p02_L_5E0D;
  lab_p02_L_5EE4: ;
  p02_L_592C();
  cpu_ex_de_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  cpu_ex_de_hl();
  p02_L_5EF8();
  lab_p02_L_5EEF: ;
  p02_L_6042();
  p02_L_5EF2();
  return;
  lab_p02_L_5EFE: ;
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p02_L_5F0E;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5C81;
  /* bit 2,(iy) */
  if (flag_z()) return;
  p00_L_0D09();
  return;
  lab_p02_L_5F0E: ;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p02_L_5F1E;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5C81;
  /* bit 2,(iy) */
  if (flag_nz()) return;
  p00_L_0D00();
  return;
  lab_p02_L_5F1E: ;
  flag_cmp(a, 0x21);
  if (flag_nz()) goto lab_p02_L_5F2A;
  cpu_pop_af();
  p02_L_6029();
  /* scf */
  p02_L_57EF();
  return;
  lab_p02_L_5F2A: ;
  flag_cmp(a, 0x1F);
  if (flag_nz()) goto lab_p02_L_5F35;
  cpu_pop_af();
  p02_L_6029();
  p02_L_5891();
  return;
  lab_p02_L_5F35: ;
  flag_cmp(a, 0x91);
  if (flag_nz()) goto lab_p02_L_5F59;
  cpu_pop_af();
  b = a;
  /* scf */
  lab_p02_L_5F3C: ;
  cpu_push_af();
  a = b;
  flag_cmp(a, 0x02);
  if (flag_nz()) { p00_L_24DD(); return; }
  p02_L_59D5();
  cpu_push_af();
  a = h;
  flag_cmp(a, l);
  if (flag_z()) goto lab_p02_L_5F4E;
  if (flag_nc()) { p00_L_24ED(); return; }
  lab_p02_L_5F4E: ;
  cpu_pop_af();
  p02_L_5E18();
  cpu_pop_af();
  p02_L_464F();
  p02_L_5B6E();
  return;
  lab_p02_L_5F59: ;
  flag_cmp(a, 0x92);
  if (flag_nz()) goto lab_p02_L_5F62;
  cpu_pop_af();
  b = a;
  a = 0;
  flag_logic(a);
  goto lab_p02_L_5F3C;
  lab_p02_L_5F62: ;
  flag_cmp(a, 0x8D);
  if (flag_nz()) goto lab_p02_L_5F8E;
  cpu_pop_af();
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p02_L_5F77;
  p02_L_5F7F();
  p02_L_5A32();
  p02_L_498C();
  lab_p02_L_5F74: ;
  p02_L_5B6E();
  return;
  lab_p02_L_5F77: ;
  p02_L_5A0F();
  p02_L_475B();
  goto lab_p02_L_5F74;
  lab_p02_L_5F8E: ;
  flag_cmp(a, 0xE9);
  if (flag_nz()) goto lab_p02_L_5FA0;
  cpu_pop_af();
  p00_L_2222();
  p00_L_128A();
  p00_rst18();
  p02_L_5F9A();
  return;
  lab_p02_L_5FA0: ;
  flag_cmp(a, 0xDF);
  if (flag_nz()) goto lab_p02_L_5FB2;
  cpu_pop_af();
  p00_L_2222();
  p00_L_128A();
  p00_rst18();
  p00_L_1229();
  p02_L_620A();
  return;
  lab_p02_L_5FB2: ;
  flag_cmp(a, 0x90);
  if (flag_nz()) goto lab_p02_L_5FCF;
  cpu_pop_af();
  p02_L_5F7F();
  p02_L_59F8();
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) { p00_L_24ED(); return; }
  p02_L_5FC3();
  return;
  lab_p02_L_5FCF: ;
  flag_cmp(a, 0xD0);
  if (flag_nz()) goto lab_p02_L_5FED;
  cpu_pop_af();
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_rst18();
  a = 0x25;
  p02_L_5FDA();
  return;
  lab_p02_L_5FED: ;
  flag_cmp(a, 0xDB);
  if (flag_nz()) goto lab_p02_L_5FF9;
  cpu_pop_af();
  p02_L_6029();
  cpu_ex_de_hl();
  p02_L_5167();
  return;
  lab_p02_L_5FF9: ;
  flag_cmp(a, 0xDC);
  if (flag_nz()) goto lab_p02_L_6005;
  cpu_pop_af();
  p02_L_6029();
  cpu_ex_de_hl();
  p02_L_5177();
  return;
  lab_p02_L_6005: ;
  flag_cmp(a, 0xAB);
  if (flag_z()) goto lab_p02_L_6159;
  flag_cmp(a, 0xDA);
  if (flag_nz()) { p00_L_24E5(); return; }
  cpu_pop_af();
  if (flag_z()) { p00_L_15DD(); return; }
  flag_cmp(a, 0x0C);
  if (flag_nz()) { p02_L_58B4(); return; }
  p00_rst18();
  p00_L_1179();
  p00_L_15DD();
  p00_rst08();
  p00_L_219B();
  p00_L_15DD();
  p00_L_104E();
  return;
  lab_p02_L_6159: ;
  cpu_pop_af();
  if (flag_nz()) { p00_L_24DD(); return; }
  cpu_push_bc();
  p00_L_222C();
  goto lab_p02_L_619B;
  lab_p02_L_619B: ;
  p00_L_14D5();
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_3B5B();
  cpu_ex_de_hl();
  p00_L_1836();
  mem_write16(0x84B1, hl());
  set_de(0x0001);
  mem_write16(0x84AF, de());
  p00_L_1C40();
  mem_write16(0x84D3, de());
  p00_L_2148();
  p00_L_21D6();
  p00_L_21CC();
  p00_L_222C();
  lab_p02_L_61C5: ;
  p00_L_171E();
  p00_L_2148();
  p00_L_222C();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0xAB);
  if (flag_nz()) goto lab_p02_L_61D9;
  p00_L_39F9();
  goto lab_p02_L_61EE;
  lab_p02_L_61D9: ;
  flag_cmp(a, 0xD9);
  if (flag_z()) goto lab_p02_L_61E6;
  if (flag_c()) goto lab_p02_L_61EB;
  a = 0x24;
  p00_L_396F();
  goto lab_p02_L_61EE;
  lab_p02_L_61E6: ;
  p02_L_51A0();
  goto lab_p02_L_61EE;
  lab_p02_L_61EB: ;
  p02_L_4F53();
  lab_p02_L_61EE: ;
  p02_L_616F();
  if (flag_nc()) goto lab_p02_L_61C5;
  cpu_pop_af();
  p00_L_21A4();
  p00_L_21A7();
  p00_L_219B();
  return;
  lab_p02_L_65B5: ;
  p00_L_14B0();
  d = 0x00;
  p02_L_7657();
  return;
  lab_p02_L_6AC5: ;
  p00_L_222C();
  p02_L_6AC8();
  return;
  lab_p02_L_6CAA: ;
  p00_L_0E5C();
  goto lab_p02_L_6CE8;
  lab_p02_L_6CD8: ;
  p00_L_11D8();
  p00_L_0C0F();
  p00_L_149D();
  p00_L_0C0F();
  p00_rst08();
  p00_L_113F();
  lab_p02_L_6CE8: ;
  goto lab_p02_L_6D08;
  lab_p02_L_6CEA: ;
  p00_L_0E72();
  p00_L_14B0();
  p00_L_0E72();
  p00_L_14B0();
  goto lab_p02_L_6D08;
  lab_p02_L_6CF8: ;
  p00_L_10E6();
  p00_L_0BF9();
  p00_L_14A2();
  p00_L_0BF9();
  p00_rst08();
  p00_L_1135();
  lab_p02_L_6D08: ;
  p00_L_104E();
  return;
}

/* flash page 2 cpu 0x5B6B (offset 0x1B6B) */
void p02_L_5B6B(void) {
  p00_rst10();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  p02_L_5B6E();
  return;
}

/* flash page 2 cpu 0x5B6E (offset 0x1B6E) */
void p02_L_5B6E(void) {
  p00_L_219B();
  p02_L_5B71();
  return;
}

/* flash page 2 cpu 0x5B71 (offset 0x1B71) */
void p02_L_5B71(void) {
  a = mem_read8(0x9817);
  flag_cmp(a, 0x01);
  if (flag_c()) return;
  set_hl(mem_read16(0x9818));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  if (flag_z()) goto lab_p02_L_5B83;
  set_hl(mem_read16(0x981A));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  lab_p02_L_5B83: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x9817, a);
  return;
}

/* flash page 2 cpu 0x5BED (offset 0x1BED) */
void p02_L_5BED(void) {
  goto lab_p02_L_5BED;
  lab_p02_L_5362: ;
  p02_L_5A22();
  p02_L_5365();
  return;
  lab_p02_L_5457: ;
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p02_L_59F8();
  mem_write16(0x84B5, hl());
  p00_L_1C40();
  mem_write16(0x84D7, de());
  p02_L_536B();
  return;
  lab_p02_L_58BB: ;
  p00_L_1842();
  flag_cmp(a, 0x0D);
  if (flag_nz()) { p00_L_24DD(); return; }
  lab_p02_L_58C3: ;
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p02_L_59D5();
  mem_write16(0x84B7, hl());
  if (flag_nz()) goto lab_p02_L_5362;
  p02_L_5365();
  return;
  lab_p02_L_5BED: ;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_5C0D;
  cpu_pop_af();
  if (flag_z()) { p00_L_0E4C(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) { p00_L_0E49(); return; }
  d = 0x05;
  p02_L_5BFB();
  return;
  lab_p02_L_5C0D: ;
  flag_cmp(a, 0xB9);
  if (flag_nz()) goto lab_p02_L_5C1E;
  cpu_pop_af();
  if (flag_z()) { p00_L_0C0F(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p02_L_6CD8;
  d = 0x06;
  p02_L_5BFB();
  return;
  lab_p02_L_5C1E: ;
  flag_cmp(a, 0xBA);
  if (flag_nz()) goto lab_p02_L_5C2F;
  cpu_pop_af();
  if (flag_z()) { p00_L_0E72(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p02_L_6CEA;
  d = 0x07;
  p02_L_5BFB();
  return;
  lab_p02_L_5C2F: ;
  flag_cmp(a, 0xB1);
  if (flag_nz()) goto lab_p02_L_5C40;
  cpu_pop_af();
  if (flag_z()) { p00_L_0BF9(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p02_L_6CF8;
  d = 0x08;
  p02_L_5BFB();
  return;
  lab_p02_L_5C40: ;
  flag_cmp(a, 0x26);
  if (flag_nz()) goto lab_p02_L_5C51;
  cpu_pop_af();
  p02_L_660A();
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_z()) { p00_L_24FD(); return; }
  return;
  lab_p02_L_5C51: ;
  flag_cmp(a, 0x89);
  if (flag_nz()) goto lab_p02_L_5C76;
  cpu_pop_af();
  if (flag_z()) return;
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p02_L_6CAA;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p02_L_58BB;
  p02_L_5C61();
  return;
  lab_p02_L_5C76: ;
  flag_cmp(a, 0x2D);
  if (flag_nz()) goto lab_p02_L_5C88;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5C81;
  p00_L_394B();
  return;
  lab_p02_L_5C81: ;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_58C3;
  goto lab_p02_L_5C9F;
  lab_p02_L_5C88: ;
  flag_cmp(a, 0xB2);
  if (flag_nz()) goto lab_p02_L_5CA2;
  cpu_pop_af();
  if (flag_z()) { p00_L_15D6(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) { p02_L_6B62(); return; }
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p02_L_5457;
  d = 0x04;
  p02_L_5BFB();
  return;
  lab_p02_L_5C9F: ;
  p00_L_24DD();
  return;
  lab_p02_L_5CA2: ;
  flag_cmp(a, 0xB4);
  if (flag_nz()) goto lab_p02_L_5CC0;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5C9F;
  p02_L_6520();
  h = a;
  l = a;
  mem_write16(0x84B7, hl());
  p00_L_1C7B();
  mem_write16(0x84D7, de());
  p00_L_21D6();
  p02_L_4102();
  goto lab_p02_L_5CD8;
  lab_p02_L_5CC0: ;
  flag_cmp(a, 0x0E);
  if (flag_nz()) goto lab_p02_L_5CDB;
  cpu_pop_af();
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p02_L_5C9F;
  p02_L_59F8();
  a = h;
  h = l;
  l = a;
  mem_write16(0x84B7, hl());
  p02_L_5A17();
  p02_L_4124();
  lab_p02_L_5CD8: ;
  p02_L_5B6E();
  return;
  lab_p02_L_5CDB: ;
  flag_cmp(a, 0xB6);
  if (flag_nz()) goto lab_p02_L_5CE4;
  set_hl(0x3B3D);
  goto lab_p02_L_5CF4;
  lab_p02_L_5CE4: ;
  flag_cmp(a, 0xB7);
  if (flag_nz()) goto lab_p02_L_5CED;
  set_hl(0x4962);
  goto lab_p02_L_5CF4;
  lab_p02_L_5CED: ;
  flag_cmp(a, 0x1A);
  if (flag_nz()) goto lab_p02_L_5D03;
  set_hl(0x3B31);
  lab_p02_L_5CF4: ;
  p02_L_6042();
  cpu_pop_af();
  cpu_push_hl();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_5D17;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p02_L_5D17;
  goto lab_p02_L_5C9F;
  lab_p02_L_5D03: ;
  flag_cmp(a, 0x19);
  if (flag_nz()) goto lab_p02_L_5D35;
  set_hl(0x3B37);
  goto lab_p02_L_5CF4;
  lab_p02_L_5D17: ;
  p02_L_59F8();
  set_hl(0x0001);
  mem_write16(0x84B1, hl());
  p02_L_5D20();
  return;
  lab_p02_L_5D28: ;
  p00_L_24DD();
  return;
  lab_p02_L_5D35: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p02_L_5D3F;
  cpu_pop_af();
  if (flag_z()) { p02_L_4B39(); return; }
  goto lab_p02_L_5D28;
  lab_p02_L_5D3F: ;
  flag_cmp(a, 0x8A);
  if (flag_nz()) goto lab_p02_L_5D52;
  cpu_pop_af();
  if (flag_z()) return;
  flag_cmp(a, 0x0C);
  if (flag_z()) { p00_L_1040(); return; }
  p02_L_5D4A();
  return;
  lab_p02_L_5D52: ;
  flag_cmp(a, 0x8B);
  if (flag_nz()) goto lab_p02_L_5D66;
  cpu_pop_af();
  if (flag_z()) { p00_L_128A(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) { p00_L_103D(); return; }
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_5D95;
  p02_L_5D4A();
  return;
  lab_p02_L_5D66: ;
  flag_cmp(a, 0x8C);
  if (flag_nz()) goto lab_p02_L_5DA1;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5D78;
  p00_L_15CB();
  if (flag_z()) { p00_L_128A(); return; }
  a = 0x04;
  p00_L_152C();
  return;
  lab_p02_L_5D78: ;
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p02_L_65B5;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p02_L_5D8D;
  p02_L_5A0F();
  p00_L_128A();
  p02_L_44C8();
  p02_L_5D32();
  return;
  lab_p02_L_5D8D: ;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p02_L_5457;
  p02_L_58B4();
  return;
  lab_p02_L_5D95: ;
  p02_L_5A32();
  p00_L_128A();
  p02_L_49B2();
  p02_L_5D32();
  return;
  lab_p02_L_5DA1: ;
  flag_cmp(a, 0x8E);
  if (flag_nz()) goto lab_p02_L_5DF6;
  cpu_pop_af();
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p02_L_5D28;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1F)) & (1u << 0)) == 0);
  if (flag_nz()) { p00_L_2501(); return; }
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 0)));
  p00_L_241E();
  if (flag_c()) { p00_L_24F1(); return; }
  cpu_ex_de_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  flag_cmp(a, e);
  if (flag_z()) { p00_L_24FD(); return; }
  d = a;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x84DD, hl());
  cpu_ex_de_hl();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_3951();
  set_hl(mem_read16(0x84DD));
  cpu_pop_bc();
  while (bc() != 0) { cpu_ldi(); }
  p00_L_1135();
  set_hl(0x5DEF);
  p00_L_25A2();
  p00_L_39E7();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 0)));
  p00_L_1717();
  p02_L_5B71();
  return;
  lab_p02_L_5DF6: ;
  flag_cmp(a, 0x12);
  if (flag_nz()) goto lab_p02_L_5E30;
  cpu_pop_af();
  if (flag_z()) { p02_L_65D4(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) { p02_L_65BE(); return; }
  p00_L_12B9();
  set_de(0x8000);
  cpu_push_de();
  p02_L_561F();
  return;
  lab_p02_L_5E0D: ;
  p00_L_24DD();
  return;
  lab_p02_L_5E30: ;
  flag_cmp(a, 0x8F);
  if (flag_nz()) goto lab_p02_L_5E5D;
  cpu_pop_af();
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p02_L_5D28;
  p02_L_592C();
  cpu_ex_de_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  c = e;
  b = d;
  lab_p02_L_5E43: ;
  set_hl((uint16_t)(hl() + 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_5E53;
  set_bc((uint16_t)(bc() - 1));
  p00_L_172F();
  if (flag_nz()) goto lab_p02_L_5E43;
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() - 1));
  set_bc((uint16_t)(bc() - 1));
  goto lab_p02_L_5E43;
  lab_p02_L_5E53: ;
  cpu_ex_de_hl();
  p00_L_3B55();
  p00_L_1179();
  p02_L_5EF2();
  return;
  lab_p02_L_5E5D: ;
  flag_cmp(a, 0x0F);
  if (flag_nz()) goto lab_p02_L_5E87;
  cpu_pop_af();
  if (flag_z()) { p00_L_0D11(); return; }
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p02_L_5E79;
  p00_L_222C();
  p00_L_1235();
  p00_L_1287();
  p00_L_104E();
  p02_L_6C77();
  return;
  lab_p02_L_5E79: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) { p02_L_58B4(); return; }
  p00_L_1100();
  p00_L_1235();
  p02_L_453E();
  return;
  lab_p02_L_5E87: ;
  flag_cmp(a, 0xBD);
  if (flag_nz()) goto lab_p02_L_5EAE;
  cpu_pop_af();
  if (flag_z()) goto lab_p02_L_5EA6;
  flag_cmp(a, 0x0C);
  if (flag_nz()) { p02_L_58B4(); return; }
  set_hl(0x848E);
  p00_L_1224();
  p00_L_21DB();
  p00_L_127B();
  p00_L_21DB();
  p02_L_6C56();
  return;
  lab_p02_L_5EA6: ;
  p00_rst08();
  p00_L_1235();
  p00_L_3957();
  return;
  lab_p02_L_5EAE: ;
  flag_cmp(a, 0xB5);
  if (flag_nz()) goto lab_p02_L_5EFE;
  cpu_pop_af();
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p02_L_5EDB;
  p02_L_59F8();
  cpu_push_hl();
  set_hl(0x0002);
  p02_L_5A22();
  cpu_pop_hl();
  cpu_push_hl();
  p02_L_5EF6();
  set_hl(0x0002);
  p02_L_47D8();
  cpu_pop_hl();
  p02_L_5EF5();
  set_hl(0x0001);
  p02_L_47D8();
  p00_L_1135();
  goto lab_p02_L_5EEF;
  lab_p02_L_5EDB: ;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_5EE4;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p02_L_5E0D;
  lab_p02_L_5EE4: ;
  p02_L_592C();
  cpu_ex_de_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  cpu_ex_de_hl();
  p02_L_5EF8();
  lab_p02_L_5EEF: ;
  p02_L_6042();
  p02_L_5EF2();
  return;
  lab_p02_L_5EFE: ;
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p02_L_5F0E;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5C81;
  /* bit 2,(iy) */
  if (flag_z()) return;
  p00_L_0D09();
  return;
  lab_p02_L_5F0E: ;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p02_L_5F1E;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_5C81;
  /* bit 2,(iy) */
  if (flag_nz()) return;
  p00_L_0D00();
  return;
  lab_p02_L_5F1E: ;
  flag_cmp(a, 0x21);
  if (flag_nz()) goto lab_p02_L_5F2A;
  cpu_pop_af();
  p02_L_6029();
  /* scf */
  p02_L_57EF();
  return;
  lab_p02_L_5F2A: ;
  flag_cmp(a, 0x1F);
  if (flag_nz()) goto lab_p02_L_5F35;
  cpu_pop_af();
  p02_L_6029();
  p02_L_5891();
  return;
  lab_p02_L_5F35: ;
  flag_cmp(a, 0x91);
  if (flag_nz()) goto lab_p02_L_5F59;
  cpu_pop_af();
  b = a;
  /* scf */
  lab_p02_L_5F3C: ;
  cpu_push_af();
  a = b;
  flag_cmp(a, 0x02);
  if (flag_nz()) { p00_L_24DD(); return; }
  p02_L_59D5();
  cpu_push_af();
  a = h;
  flag_cmp(a, l);
  if (flag_z()) goto lab_p02_L_5F4E;
  if (flag_nc()) { p00_L_24ED(); return; }
  lab_p02_L_5F4E: ;
  cpu_pop_af();
  p02_L_5E18();
  cpu_pop_af();
  p02_L_464F();
  p02_L_5B6E();
  return;
  lab_p02_L_5F59: ;
  flag_cmp(a, 0x92);
  if (flag_nz()) goto lab_p02_L_5F62;
  cpu_pop_af();
  b = a;
  a = 0;
  flag_logic(a);
  goto lab_p02_L_5F3C;
  lab_p02_L_5F62: ;
  flag_cmp(a, 0x8D);
  if (flag_nz()) goto lab_p02_L_5F8E;
  cpu_pop_af();
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p02_L_5F77;
  p02_L_5F7F();
  p02_L_5A32();
  p02_L_498C();
  lab_p02_L_5F74: ;
  p02_L_5B6E();
  return;
  lab_p02_L_5F77: ;
  p02_L_5A0F();
  p02_L_475B();
  goto lab_p02_L_5F74;
  lab_p02_L_5F8E: ;
  flag_cmp(a, 0xE9);
  if (flag_nz()) goto lab_p02_L_5FA0;
  cpu_pop_af();
  p00_L_2222();
  p00_L_128A();
  p00_rst18();
  p02_L_5F9A();
  return;
  lab_p02_L_5FA0: ;
  flag_cmp(a, 0xDF);
  if (flag_nz()) goto lab_p02_L_5FB2;
  cpu_pop_af();
  p00_L_2222();
  p00_L_128A();
  p00_rst18();
  p00_L_1229();
  p02_L_620A();
  return;
  lab_p02_L_5FB2: ;
  flag_cmp(a, 0x90);
  if (flag_nz()) goto lab_p02_L_5FCF;
  cpu_pop_af();
  p02_L_5F7F();
  p02_L_59F8();
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) { p00_L_24ED(); return; }
  p02_L_5FC3();
  return;
  lab_p02_L_5FCF: ;
  flag_cmp(a, 0xD0);
  if (flag_nz()) goto lab_p02_L_5FED;
  cpu_pop_af();
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_rst18();
  a = 0x25;
  p02_L_5FDA();
  return;
  lab_p02_L_5FED: ;
  flag_cmp(a, 0xDB);
  if (flag_nz()) goto lab_p02_L_5FF9;
  cpu_pop_af();
  p02_L_6029();
  cpu_ex_de_hl();
  p02_L_5167();
  return;
  lab_p02_L_5FF9: ;
  flag_cmp(a, 0xDC);
  if (flag_nz()) goto lab_p02_L_6005;
  cpu_pop_af();
  p02_L_6029();
  cpu_ex_de_hl();
  p02_L_5177();
  return;
  lab_p02_L_6005: ;
  flag_cmp(a, 0xAB);
  if (flag_z()) goto lab_p02_L_6159;
  flag_cmp(a, 0xDA);
  if (flag_nz()) { p00_L_24E5(); return; }
  cpu_pop_af();
  if (flag_z()) { p00_L_15DD(); return; }
  flag_cmp(a, 0x0C);
  if (flag_nz()) { p02_L_58B4(); return; }
  p00_rst18();
  p00_L_1179();
  p00_L_15DD();
  p00_rst08();
  p00_L_219B();
  p00_L_15DD();
  p00_L_104E();
  return;
  lab_p02_L_6159: ;
  cpu_pop_af();
  if (flag_nz()) { p00_L_24DD(); return; }
  cpu_push_bc();
  p00_L_222C();
  goto lab_p02_L_619B;
  lab_p02_L_619B: ;
  p00_L_14D5();
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_3B5B();
  cpu_ex_de_hl();
  p00_L_1836();
  mem_write16(0x84B1, hl());
  set_de(0x0001);
  mem_write16(0x84AF, de());
  p00_L_1C40();
  mem_write16(0x84D3, de());
  p00_L_2148();
  p00_L_21D6();
  p00_L_21CC();
  p00_L_222C();
  lab_p02_L_61C5: ;
  p00_L_171E();
  p00_L_2148();
  p00_L_222C();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0xAB);
  if (flag_nz()) goto lab_p02_L_61D9;
  p00_L_39F9();
  goto lab_p02_L_61EE;
  lab_p02_L_61D9: ;
  flag_cmp(a, 0xD9);
  if (flag_z()) goto lab_p02_L_61E6;
  if (flag_c()) goto lab_p02_L_61EB;
  a = 0x24;
  p00_L_396F();
  goto lab_p02_L_61EE;
  lab_p02_L_61E6: ;
  p02_L_51A0();
  goto lab_p02_L_61EE;
  lab_p02_L_61EB: ;
  p02_L_4F53();
  lab_p02_L_61EE: ;
  p02_L_616F();
  if (flag_nc()) goto lab_p02_L_61C5;
  cpu_pop_af();
  p00_L_21A4();
  p00_L_21A7();
  p00_L_219B();
  return;
  lab_p02_L_65B5: ;
  p00_L_14B0();
  d = 0x00;
  p02_L_7657();
  return;
  lab_p02_L_6CAA: ;
  p00_L_0E5C();
  goto lab_p02_L_6CE8;
  lab_p02_L_6CD8: ;
  p00_L_11D8();
  p00_L_0C0F();
  p00_L_149D();
  p00_L_0C0F();
  p00_rst08();
  p00_L_113F();
  lab_p02_L_6CE8: ;
  goto lab_p02_L_6D08;
  lab_p02_L_6CEA: ;
  p00_L_0E72();
  p00_L_14B0();
  p00_L_0E72();
  p00_L_14B0();
  goto lab_p02_L_6D08;
  lab_p02_L_6CF8: ;
  p00_L_10E6();
  p00_L_0BF9();
  p00_L_14A2();
  p00_L_0BF9();
  p00_rst08();
  p00_L_1135();
  lab_p02_L_6D08: ;
  p00_L_104E();
  return;
}

/* flash page 2 cpu 0x5BFB (offset 0x1BFB) */
void p02_L_5BFB(void) {
  goto lab_p02_L_5BFB;
  lab_p02_L_5BE9: ;
  p02_L_58B4();
  return;
  lab_p02_L_5BFB: ;
  cpu_push_de();
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p02_L_5C0A;
  p02_L_5A0F();
  cpu_pop_af();
  p02_L_448F();
  p02_L_5B6E();
  return;
  lab_p02_L_5C0A: ;
  cpu_pop_de();
  goto lab_p02_L_5BE9;
}

/* flash page 2 cpu 0x5C61 (offset 0x1C61) */
void p02_L_5C61(void) {
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p02_L_5C9F;
  p02_L_5A32();
  a = mem_read8(0x8499);
  a = a & 0x0F;
  flag_logic(a);
  set_de(mem_read16(0x84D7));
  p02_L_452B();
  goto lab_p02_L_5CBE;
  lab_p02_L_5C9F: ;
  p00_L_24DD();
  return;
  lab_p02_L_5CBE: ;
  goto lab_p02_L_5CD8;
  lab_p02_L_5CD8: ;
  p02_L_5B6E();
  return;
}

/* flash page 2 cpu 0x5D20 (offset 0x1D20) */
void p02_L_5D20(void) {
  cpu_pop_hl();
  p02_L_5D27();
  p02_L_5B71();
  return;
}

/* flash page 2 cpu 0x5D27 (offset 0x1D27) */
void p02_L_5D27(void) {
  os_jp_hl();
  return;
}

/* flash page 2 cpu 0x5D32 (offset 0x1D32) */
void p02_L_5D32(void) {
  p02_L_5B6E();
  return;
}

/* flash page 2 cpu 0x5D4A (offset 0x1D4A) */
void p02_L_5D4A(void) {
  goto lab_p02_L_5D4A;
  lab_p02_L_5457: ;
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p02_L_59F8();
  mem_write16(0x84B5, hl());
  p00_L_1C40();
  mem_write16(0x84D7, de());
  p02_L_536B();
  return;
  lab_p02_L_5D4A: ;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p02_L_5457;
  p02_L_5C61();
  return;
}

/* flash page 2 cpu 0x5E10 (offset 0x1E10) */
void p02_L_5E10(void) {
  p02_L_59D5();
  cpu_push_af();
  p02_L_5649();
  cpu_pop_af();
  p02_L_5E18();
  return;
}

/* flash page 2 cpu 0x5E18 (offset 0x1E18) */
void p02_L_5E18(void) {
  mem_write16(0x84B7, hl());
  if (flag_z()) { p00_L_21D6(); return; }
  p02_L_5A17();
  p02_L_5E21();
  return;
}

/* flash page 2 cpu 0x5E21 (offset 0x1E21) */
void p02_L_5E21(void) {
  p02_L_4525();
  set_de(mem_read16(0x84D7));
  mem_write16(0x84D3, de());
  return;
}

/* flash page 2 cpu 0x5EF2 (offset 0x1EF2) */
void p02_L_5EF2(void) {
  p02_L_5B71();
  return;
}

/* flash page 2 cpu 0x5EF5 (offset 0x1EF5) */
void p02_L_5EF5(void) {
  l = h;
  p02_L_5EF6();
  return;
}

/* flash page 2 cpu 0x5EF6 (offset 0x1EF6) */
void p02_L_5EF6(void) {
  h = 0x00;
  p02_L_5EF8();
  return;
}

/* flash page 2 cpu 0x5EF8 (offset 0x1EF8) */
void p02_L_5EF8(void) {
  p00_L_3B55();
  p00_L_1179();
  return;
}

/* flash page 2 cpu 0x5F7F (offset 0x1F7F) */
void p02_L_5F7F(void) {
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_5F8B;
  p00_L_1842();
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p02_L_602B;
  lab_p02_L_5F8B: ;
  p02_L_6042();
  return;
  lab_p02_L_602B: ;
  if (flag_nz()) goto lab_p02_L_62A2;
  p02_L_6042();
  p02_L_59F8();
  a = 0;
  flag_logic(a);
  mem_write8(0x84D6, a);
  mem_write8(0x84DC, a);
  return;
  lab_p02_L_62A2: ;
  p00_L_24DD();
  return;
}

/* flash page 2 cpu 0x5F9A (offset 0x1F9A) */
void p02_L_5F9A(void) {
  p00_L_1229();
  p02_L_614E();
  return;
}

/* flash page 2 cpu 0x5FC3 (offset 0x1FC3) */
void p02_L_5FC3(void) {
  p02_L_5A22();
  p00_L_21D6();
  p02_L_4A01();
  p02_L_5B6E();
  return;
}

/* flash page 2 cpu 0x5FDA (offset 0x1FDA) */
void p02_L_5FDA(void) {
  cpu_push_af();
  a = mem_read8(0x97B0);
  flag_cmp(a, 0xFF);
  if (flag_nz()) { p02_L_5FE4(); return; }
  a = 0x09;
  p02_L_5FE4();
  return;
}

/* flash page 2 cpu 0x5FE4 (offset 0x1FE4) */
void p02_L_5FE4(void) {
  mem_write8(0x8478, a);
  p00_rst18();
  cpu_pop_af();
  p00_L_395D();
  return;
}

/* flash page 2 cpu 0x6029 (offset 0x2029) */
void p02_L_6029(void) {
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p02_L_62A2;
  p02_L_6042();
  p02_L_59F8();
  a = 0;
  flag_logic(a);
  mem_write8(0x84D6, a);
  mem_write8(0x84DC, a);
  return;
  lab_p02_L_62A2: ;
  p00_L_24DD();
  return;
}

/* flash page 2 cpu 0x6042 (offset 0x2042) */
void p02_L_6042(void) {
  set_de(mem_read16(0x9665));
  set_de((uint16_t)(de() - 1));
  mem_write16(0x9665, de());
  return;
}

/* flash page 2 cpu 0x604C (offset 0x204C) */
void p02_L_604C(void) {
  goto lab_p02_L_604C;
  lab_p02_L_603C: ;
  p02_L_64AB();
  p00_L_3963();
  p02_L_6042();
  return;
  lab_p02_L_604C: ;
  p00_L_1847();
  set_hl(0x9817);
  mem_write8(hl(), 0x00);
  flag_cmp(a, 0xD1);
  if (flag_nz()) goto lab_p02_L_6065;
  a = 0x26;
  lab_p02_L_605A: ;
  cpu_push_af();
  p00_L_3969();
  p02_L_5601();
  a = e;
  p02_L_5FE4();
  return;
  lab_p02_L_6065: ;
  flag_cmp(a, 0xD2);
  if (flag_nz()) goto lab_p02_L_606D;
  a = 0x27;
  goto lab_p02_L_605A;
  lab_p02_L_606D: ;
  flag_cmp(a, 0xE3);
  if (flag_nz()) goto lab_p02_L_60BE;
  a = 0x0E;
  lab_p02_L_6073: ;
  cpu_push_af();
  p00_L_3969();
  p00_L_1037();
  if (flag_nz()) goto lab_p02_L_6080;
  cpu_pop_af();
  p02_L_6156();
  return;
  lab_p02_L_6080: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) { p00_L_24DD(); return; }
  p02_L_5A32();
  set_hl(mem_read16(0x84AF));
  mem_write16(0x84B1, hl());
  set_hl(0x0001);
  mem_write16(0x84AF, hl());
  p00_L_21CC();
  p00_rst18();
  p00_rst18();
  lab_p02_L_6099: ;
  p00_L_171E();
  p00_L_2267();
  p00_rst18();
  p00_L_2267();
  p00_rst18();
  p02_L_479B();
  cpu_pop_af();
  cpu_push_af();
  p02_L_658F();
  p02_L_616F();
  if (flag_nc()) goto lab_p02_L_6099;
  cpu_pop_af();
  set_de(0x001B);
  p00_L_21B6();
  p00_L_219B();
  p00_L_21A4();
  return;
  lab_p02_L_60BE: ;
  flag_cmp(a, 0xE4);
  if (flag_nz()) goto lab_p02_L_60C6;
  a = 0x10;
  goto lab_p02_L_6073;
  lab_p02_L_60C6: ;
  flag_cmp(a, 0xCF);
  if (flag_nz()) goto lab_p02_L_60D8;
  p02_L_6430();
  cpu_push_de();
  p00_L_22FC();
  p00_L_1653();
  cpu_pop_de();
  p02_L_512F();
  return;
  lab_p02_L_60D8: ;
  flag_cmp(a, 0xCE);
  if (flag_nz()) goto lab_p02_L_60F1;
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p02_L_615A;
  p02_L_6042();
  p02_L_59F8();
  cpu_ex_de_hl();
  a = 0;
  flag_logic(a);
  mem_write8(0x84D6, a);
  p02_L_641B();
  return;
  lab_p02_L_60F1: ;
  flag_cmp(a, 0xB6);
  if (flag_nz()) goto lab_p02_L_6143;
  set_hl(0x3B3D);
  lab_p02_L_60F8: ;
  cpu_push_hl();
  p02_L_6136();
  cpu_push_de();
  p00_L_2176();
  p02_L_6100();
  return;
  lab_p02_L_6143: ;
  flag_cmp(a, 0xB7);
  set_hl(0x4962);
  if (flag_z()) goto lab_p02_L_60F8;
  flag_cmp(a, 0xE9);
  if (flag_nz()) goto lab_p02_L_618F;
  p02_L_614E();
  return;
  lab_p02_L_615A: ;
  if (flag_nz()) { p00_L_24DD(); return; }
  cpu_push_bc();
  p00_L_222C();
  goto lab_p02_L_619B;
  lab_p02_L_618F: ;
  flag_cmp(a, 0xED);
  if (flag_nz()) goto lab_p02_L_61FD;
  lab_p02_L_6194: ;
  cpu_push_af();
  p00_L_1653();
  p00_L_3969();
  lab_p02_L_619B: ;
  p00_L_14D5();
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_3B5B();
  cpu_ex_de_hl();
  p00_L_1836();
  mem_write16(0x84B1, hl());
  set_de(0x0001);
  mem_write16(0x84AF, de());
  p00_L_1C40();
  mem_write16(0x84D3, de());
  p00_L_2148();
  p00_L_21D6();
  p00_L_21CC();
  p00_L_222C();
  lab_p02_L_61C5: ;
  p00_L_171E();
  p00_L_2148();
  p00_L_222C();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0xAB);
  if (flag_nz()) goto lab_p02_L_61D9;
  p00_L_39F9();
  goto lab_p02_L_61EE;
  lab_p02_L_61D9: ;
  flag_cmp(a, 0xD9);
  if (flag_z()) goto lab_p02_L_61E6;
  if (flag_c()) goto lab_p02_L_61EB;
  a = 0x24;
  p00_L_396F();
  goto lab_p02_L_61EE;
  lab_p02_L_61E6: ;
  p02_L_51A0();
  goto lab_p02_L_61EE;
  lab_p02_L_61EB: ;
  p02_L_4F53();
  lab_p02_L_61EE: ;
  p02_L_616F();
  if (flag_nc()) goto lab_p02_L_61C5;
  cpu_pop_af();
  p00_L_21A4();
  p00_L_21A7();
  p00_L_219B();
  return;
  lab_p02_L_61FD: ;
  flag_cmp(a, 0xD9);
  lab_p02_L_61FF: ;
  if (flag_z()) goto lab_p02_L_6194;
  flag_cmp(a, 0xD8);
  if (flag_z()) goto lab_p02_L_61FF;
  flag_cmp(a, 0xDF);
  if (flag_nz()) goto lab_p02_L_621B;
  p02_L_620A();
  return;
  lab_p02_L_621B: ;
  flag_cmp(a, 0xDD);
  if (flag_nz()) goto lab_p02_L_62A5;
  p00_L_14D1();
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_3B5B();
  if (flag_c()) { p00_L_24ED(); return; }
  cpu_push_de();
  p00_L_2176();
  p00_L_2166();
  p00_L_1037();
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p02_L_62A2;
  a = mem_read8(0x848E);
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p02_L_62A2;
  p02_L_59B1();
  mem_write16(0x84B5, hl());
  cpu_pop_bc();
  if (flag_c()) { p00_L_128A(); return; }
  cpu_push_bc();
  set_bc((uint16_t)(bc() - 1));
  set_hl(mem_read16(0x84D3));
  set_de(mem_read16(0x84AF));
  p02_L_6341();
  if (flag_nc()) goto lab_p02_L_6287;
  cpu_push_hl();
  set_hl(mem_read16(0x84B5));
  lab_p02_L_6260: ;
  mem_write16(0x84B1, bc());
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p02_L_6286;
  cpu_pop_hl();
  cpu_push_hl();
  set_de(mem_read16(0x84D5));
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_bc(mem_read16(0x84B3));
  lab_p02_L_6275: ;
  a = mem_read8(de());
  set_de((uint16_t)(de() + 1));
  /* cpi */
  if (flag_nz()) goto lab_p02_L_628B;
  if (flag_pe()) goto lab_p02_L_6275;
  cpu_pop_hl();
  cpu_pop_hl();
  p00_L_3B55();
  p00_L_1179();
  return;
  lab_p02_L_6286: ;
  cpu_pop_hl();
  lab_p02_L_6287: ;
  cpu_pop_hl();
  p00_L_128A();
  return;
  lab_p02_L_628B: ;
  cpu_pop_hl();
  set_bc(mem_read16(0x84B1));
  p00_L_172F();
  if (flag_nz()) goto lab_p02_L_6297;
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() + 1));
  lab_p02_L_6297: ;
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  set_bc((uint16_t)(bc() + 1));
  set_hl(mem_read16(0x84B5));
  goto lab_p02_L_6260;
  lab_p02_L_62A2: ;
  p00_L_24DD();
  return;
  lab_p02_L_62A5: ;
  flag_cmp(a, 0xDE);
  if (flag_nz()) goto lab_p02_L_62B2;
  p02_L_62A9();
  return;
  lab_p02_L_62B2: ;
  flag_cmp(a, 0xE0);
  if (flag_nz()) goto lab_p02_L_62C1;
  p00_L_1653();
  p00_L_3969();
  a = 0x18;
  p02_L_658F();
  return;
  lab_p02_L_62C1: ;
  flag_cmp(a, 0xEC);
  if (flag_nz()) goto lab_p02_L_62D0;
  p00_L_1653();
  p00_L_3969();
  a = 0x1C;
  p02_L_658F();
  return;
  lab_p02_L_62D0: ;
  flag_cmp(a, 0xE1);
  if (flag_nz()) goto lab_p02_L_62DF;
  p00_L_1653();
  p00_L_3969();
  a = 0x16;
  p02_L_658F();
  return;
  lab_p02_L_62DF: ;
  flag_cmp(a, 0xDA);
  if (flag_z()) goto lab_p02_L_62EC;
  flag_cmp(a, 0x25);
  if (flag_nz()) goto lab_p02_L_636A;
  p02_L_6969();
  return;
  lab_p02_L_62EC: ;
  p00_L_14D1();
  lab_p02_L_62EF: ;
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_3B5B();
  if (flag_c()) { p00_L_24ED(); return; }
  cpu_push_de();
  p00_L_2176();
  p00_L_14D1();
  if (flag_nz()) goto lab_p02_L_62EF;
  p00_L_3B5B();
  cpu_push_de();
  p00_L_2176();
  p00_L_1037();
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p02_L_62A2;
  p02_L_59F8();
  cpu_ex_de_hl();
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  p02_L_6341();
  if (flag_nc()) { p00_L_24ED(); return; }
  mem_write16(0x84D5, hl());
  cpu_pop_bc();
  p02_L_6347();
  if (flag_nc()) { p00_L_24ED(); return; }
  cpu_push_bc();
  h = b;
  l = c;
  p00_L_1C89();
  mem_write16(0x84D7, de());
  set_hl(mem_read16(0x84D5));
  set_de(mem_read16(0x84D7));
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_pop_bc();
  while (bc() != 0) { cpu_ldi(); }
  p00_L_1135();
  p02_L_5B71();
  return;
  lab_p02_L_636A: ;
  flag_cmp(a, 0x26);
  if (flag_nz()) goto lab_p02_L_6372;
  p02_L_67A9();
  return;
  lab_p02_L_6372: ;
  flag_cmp(a, 0x16);
  if (flag_z()) goto lab_p02_L_63AC;
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p02_L_63B6;
  flag_cmp(a, 0x17);
  if (flag_z()) goto lab_p02_L_63BF;
  flag_cmp(a, 0x18);
  if (flag_z()) goto lab_p02_L_64BB;
  flag_cmp(a, 0x22);
  if (flag_z()) goto lab_p02_L_603C;
  p00_L_24E5();
  return;
  lab_p02_L_63AC: ;
  a = 0;
  flag_logic(a);
  p02_L_64C5();
  p02_L_416F();
  p02_L_63B3();
  return;
  lab_p02_L_63B6: ;
  a = 0;
  flag_logic(a);
  p02_L_64C5();
  p02_L_4144();
  p02_L_63B3();
  return;
  lab_p02_L_63BF: ;
  p00_rst18();
  p00_L_1229();
  /* scf */
  p02_L_64C5();
  p02_L_41B4();
  p02_L_63B3();
  return;
  lab_p02_L_64BB: ;
  /* scf */
  p02_L_64C5();
  p02_L_4172();
  p02_L_63B3();
  return;
}

/* flash page 2 cpu 0x6100 (offset 0x2100) */
void p02_L_6100(void) {
  p02_L_6136();
  cpu_pop_hl();
  p00_L_192A();
  if (flag_c()) { p00_L_24ED(); return; }
  cpu_push_hl();
  cpu_push_de();
  p00_L_2176();
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_611A;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p02_L_615A;
  lab_p02_L_611A: ;
  p02_L_59F8();
  cpu_pop_hl();
  p02_L_6163();
  mem_write16(0x84B1, hl());
  cpu_pop_hl();
  a = h;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p02_L_6130;
  p02_L_6163();
  mem_write16(0x84AF, hl());
  lab_p02_L_6130: ;
  p02_L_6042();
  p02_L_5D20();
  return;
  lab_p02_L_615A: ;
  if (flag_nz()) { p00_L_24DD(); return; }
  cpu_push_bc();
  p00_L_222C();
  goto lab_p02_L_619B;
  lab_p02_L_619B: ;
  p00_L_14D5();
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_3B5B();
  cpu_ex_de_hl();
  p00_L_1836();
  mem_write16(0x84B1, hl());
  set_de(0x0001);
  mem_write16(0x84AF, de());
  p00_L_1C40();
  mem_write16(0x84D3, de());
  p00_L_2148();
  p00_L_21D6();
  p00_L_21CC();
  p00_L_222C();
  lab_p02_L_61C5: ;
  p00_L_171E();
  p00_L_2148();
  p00_L_222C();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0xAB);
  if (flag_nz()) goto lab_p02_L_61D9;
  p00_L_39F9();
  goto lab_p02_L_61EE;
  lab_p02_L_61D9: ;
  flag_cmp(a, 0xD9);
  if (flag_z()) goto lab_p02_L_61E6;
  if (flag_c()) goto lab_p02_L_61EB;
  a = 0x24;
  p00_L_396F();
  goto lab_p02_L_61EE;
  lab_p02_L_61E6: ;
  p02_L_51A0();
  goto lab_p02_L_61EE;
  lab_p02_L_61EB: ;
  p02_L_4F53();
  lab_p02_L_61EE: ;
  p02_L_616F();
  if (flag_nc()) goto lab_p02_L_61C5;
  cpu_pop_af();
  p00_L_21A4();
  p00_L_21A7();
  p00_L_219B();
  return;
}

/* flash page 2 cpu 0x6136 (offset 0x2136) */
void p02_L_6136(void) {
  p00_L_1653();
  p00_L_14D5();
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_3B5B();
  return;
}

/* flash page 2 cpu 0x614E (offset 0x214E) */
void p02_L_614E(void) {
  p00_L_1653();
  p00_L_3969();
  a = 0x0C;
  p02_L_6156();
  return;
}

/* flash page 2 cpu 0x6156 (offset 0x2156) */
void p02_L_6156(void) {
  p02_L_658F();
  return;
}

/* flash page 2 cpu 0x6163 (offset 0x2163) */
void p02_L_6163(void) {
  set_de(mem_read16(0x84AF));
  p00_L_192A();
  if (flag_c()) return;
  if (flag_nz()) { p00_L_24ED(); return; }
  return;
}

/* flash page 2 cpu 0x616F (offset 0x216F) */
void p02_L_616F(void) {
  p00_L_22C2();
  set_de(mem_read16(0x84D3));
  set_hl(mem_read16(0x84AF));
  p02_L_6179();
  return;
}

/* flash page 2 cpu 0x6179 (offset 0x2179) */
void p02_L_6179(void) {
  cpu_push_hl();
  p02_L_47DC();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  mem_write16(0x84AF, de());
  set_hl(mem_read16(0x84B1));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_push_af();
  p00_L_2370();
  cpu_pop_af();
  return;
}

/* flash page 2 cpu 0x620A (offset 0x220A) */
void p02_L_620A(void) {
  p00_L_1653();
  p00_L_3969();
  a = 0x20;
  p02_L_658F();
  return;
}

/* flash page 2 cpu 0x62A9 (offset 0x22A9) */
void p02_L_62A9(void) {
  p00_L_2222();
  p00_L_1229();
  p02_L_6452();
  return;
}

/* flash page 2 cpu 0x6341 (offset 0x2341) */
void p02_L_6341(void) {
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  cpu_pop_hl();
  p02_L_6347();
  return;
}

/* flash page 2 cpu 0x6347 (offset 0x2347) */
void p02_L_6347(void) {
  cpu_push16(ix);
  cpu_push_bc();
  ix = cpu_pop16();
  lab_p02_L_634C: ;
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_6363;
  cpu_push_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_pop_hl();
  if (flag_nc()) goto lab_p02_L_6367;
  p00_L_172F();
  if (flag_nz()) goto lab_p02_L_635F;
  set_hl((uint16_t)(hl() + 1));
  ix = (uint16_t)(ix + 1);
  lab_p02_L_635F: ;
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() - 1));
  goto lab_p02_L_634C;
  lab_p02_L_6363: ;
  cpu_push16(ix);
  cpu_pop_bc();
  /* scf */
  lab_p02_L_6367: ;
  ix = cpu_pop16();
  return;
}

/* flash page 2 cpu 0x638E (offset 0x238E) */
void p02_L_638E(void) {
  p00_L_2191();
  p00_L_2222();
  p00_L_113F();
  p00_L_3975();
  p00_L_2176();
  return;
}

/* flash page 2 cpu 0x639D (offset 0x239D) */
void p02_L_639D(void) {
  set_de(0x0012);
  p00_L_21B6();
  p00_L_219B();
  p02_L_63A6();
  return;
}

/* flash page 2 cpu 0x63A6 (offset 0x23A6) */
void p02_L_63A6(void) {
  p00_L_3975();
  p00_L_2565();
  return;
}

/* flash page 2 cpu 0x63B3 (offset 0x23B3) */
void p02_L_63B3(void) {
  p02_L_5B6E();
  return;
}

/* flash page 2 cpu 0x63EC (offset 0x23EC) */
void p02_L_63EC(void) {
  p02_L_6585();
  p00_L_1171();
  p00_L_219B();
  p00_L_1653();
  p00_L_1100();
  p00_L_219B();
  p00_L_1653();
  p00_rst08();
  p00_L_218C();
  p00_L_219B();
  cpu_pop_af();
  b = 0x01;
  p00_L_397B();
  return;
}

/* flash page 2 cpu 0x640F (offset 0x240F) */
void p02_L_640F(void) {
  goto lab_p02_L_640F;
  lab_p02_L_63CC: ;
  flag_cmp(a, 0x27);
  if (flag_z()) goto lab_p02_L_63E1;
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p02_L_63DE;
  flag_cmp(a, 0xE2);
  if (flag_nz()) { p00_L_24E5(); return; }
  a = 0x14;
  p02_L_658F();
  return;
  lab_p02_L_63DE: ;
  /* scf */
  goto lab_p02_L_63E2;
  lab_p02_L_63E1: ;
  a = 0;
  flag_logic(a);
  lab_p02_L_63E2: ;
  cpu_push_af();
  p00_rst18();
  p00_L_1229();
  a = 0x7B;
  mem_write8(0x8479, a);
  p02_L_63EC();
  return;
  lab_p02_L_640F: ;
  set_hl(0x9817);
  mem_write8(hl(), 0x00);
  flag_cmp(a, 0xCE);
  if (flag_nz()) goto lab_p02_L_644E;
  p02_L_6430();
  p02_L_641B();
  return;
  lab_p02_L_644E: ;
  flag_cmp(a, 0xDE);
  if (flag_nz()) goto lab_p02_L_645F;
  p02_L_6452();
  return;
  lab_p02_L_645F: ;
  flag_cmp(a, 0x18);
  if (flag_z()) goto lab_p02_L_64BB;
  flag_cmp(a, 0x23);
  if (flag_nz()) goto lab_p02_L_6471;
  p00_L_2222();
  p00_L_1229();
  p02_L_653D();
  return;
  lab_p02_L_6471: ;
  flag_cmp(a, 0x24);
  if (flag_nz()) goto lab_p02_L_6482;
  p00_rst18();
  p00_L_1229();
  a = 0x7B;
  mem_write8(0x8479, a);
  p00_L_3987();
  return;
  lab_p02_L_6482: ;
  flag_cmp(a, 0x25);
  if (flag_nz()) goto lab_p02_L_648D;
  p00_L_1887();
  p02_L_6966();
  return;
  lab_p02_L_648D: ;
  flag_cmp(a, 0x22);
  if (flag_nz()) goto lab_p02_L_63CC;
  p00_L_2191();
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p02_L_64B4;
  p00_L_149D();
  p02_L_64AB();
  p00_L_21DB();
  p00_L_398D();
  p02_L_6042();
  return;
  lab_p02_L_64B4: ;
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_L_16F4();
  return;
  lab_p02_L_64BB: ;
  /* scf */
  p02_L_64C5();
  p02_L_4172();
  p02_L_63B3();
  return;
}

/* flash page 2 cpu 0x641B (offset 0x241B) */
void p02_L_641B(void) {
  mem_write16(0x90CC, de());
  p00_L_3969();
  p00_L_16B5();
  a = 0x2B;
  p00_L_38FD();
  p00_L_21A4();
  p02_L_5B71();
  return;
}

/* flash page 2 cpu 0x6430 (offset 0x2430) */
void p02_L_6430(void) {
  p02_L_6042();
  p00_L_2166();
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p02_L_6444;
  a = mem_read8(0x848E);
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x01);
  lab_p02_L_6444: ;
  if (flag_nz()) { p00_L_24DD(); return; }
  p02_L_59B1();
  if (flag_nz()) { p00_L_24E9(); return; }
  return;
}

/* flash page 2 cpu 0x6452 (offset 0x2452) */
void p02_L_6452(void) {
  p00_L_1653();
  b = 0x03;
  p00_L_3981();
  a = 0x1A;
  p02_L_658F();
  return;
}

/* flash page 2 cpu 0x64AB (offset 0x24AB) */
void p02_L_64AB(void) {
  p00_L_1169();
  p00_L_1037();
  if (flag_z()) return;
  flag_cmp(a, 0x01);
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_L_16F4();
  return;
}

/* flash page 2 cpu 0x64C5 (offset 0x24C5) */
void p02_L_64C5(void) {
  cpu_push_af();
  p02_L_6520();
  mem_write8(0x84B4, a);
  p00_L_219B();
  p02_L_6520();
  mem_write8(0x84B3, a);
  p00_L_219B();
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p02_L_651D;
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p02_L_6511;
  lab_p02_L_64E5: ;
  p02_L_59D5();
  cpu_push_af();
  a = mem_read8(0x84B3);
  flag_cmp(a, h);
  if (flag_c()) goto lab_p02_L_64F2;
  lab_p02_L_64EF: ;
  if (flag_nz()) { p00_L_24ED(); return; }
  lab_p02_L_64F2: ;
  a = mem_read8(0x84B4);
  flag_cmp(a, h);
  if (flag_c()) goto lab_p02_L_64FA;
  if (flag_nz()) goto lab_p02_L_64EF;
  lab_p02_L_64FA: ;
  mem_write16(0x84B7, hl());
  cpu_pop_af();
  if (flag_z()) goto lab_p02_L_650A;
  p02_L_5A1D();
  p02_L_4520();
  set_de(mem_read16(0x84D7));
  lab_p02_L_650A: ;
  cpu_pop_af();
  if (flag_c()) p00_L_219B();
  p00_L_21D6();
  return;
  lab_p02_L_6511: ;
  if (flag_nz()) goto lab_p02_L_64E5;
  p00_L_22F7();
  a = mem_read8(0x8483);
  a = a & 0x1F;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_64E5;
  lab_p02_L_651D: ;
  p00_L_24DD();
  return;
}

/* flash page 2 cpu 0x6520 (offset 0x2520) */
void p02_L_6520(void) {
  p00_L_14D1();
  if (flag_nz()) goto lab_p02_L_6531;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x82);
  if (flag_nc()) goto lab_p02_L_6531;
  p00_L_3B5B();
  a = e;
  return;
  lab_p02_L_6531: ;
  p00_L_24ED();
  return;
}

/* flash page 2 cpu 0x6534 (offset 0x2534) */
void p02_L_6534(void) {
  goto lab_p02_L_6534;
  lab_p02_L_651D: ;
  p00_L_24DD();
  return;
  lab_p02_L_6534: ;
  flag_cmp(a, 0x02);
  if (flag_z()) return;
  goto lab_p02_L_651D;
}

/* flash page 2 cpu 0x6539 (offset 0x2539) */
void p02_L_6539(void) {
  flag_cmp(a, 0x23);
  if (flag_nz()) goto lab_p02_L_6541;
  p02_L_653D();
  return;
  lab_p02_L_6541: ;
  flag_cmp(a, 0x24);
  if (flag_nz()) goto lab_p02_L_654C;
  p02_L_6585();
  p00_L_3987();
  return;
  lab_p02_L_654C: ;
  flag_cmp(a, 0x27);
  if (flag_nz()) goto lab_p02_L_6555;
  a = a | a;
  flag_logic(a);
  lab_p02_L_6551: ;
  cpu_push_af();
  p02_L_63EC();
  return;
  lab_p02_L_6555: ;
  flag_cmp(a, 0x28);
  if (flag_nz()) { p00_L_24E5(); return; }
  /* scf */
  goto lab_p02_L_6551;
}

/* flash page 2 cpu 0x653D (offset 0x253D) */
void p02_L_653D(void) {
  p02_L_7BC8();
  return;
}

/* flash page 2 cpu 0x655D (offset 0x255D) */
void p02_L_655D(void) {
  p02_L_59B1();
  set_hl((uint16_t)(hl() + de()));
  a = d;
  flag_cmp(a, l);
  if (flag_nz()) { p00_L_24E9(); return; }
  l = e;
  mem_write16(0x84B7, hl());
  return;
}

/* flash page 2 cpu 0x656B (offset 0x256B) */
void p02_L_656B(void) {
  p00_L_1641();
  if (flag_nz()) return;
  p00_L_24D5();
  return;
}

/* flash page 2 cpu 0x6585 (offset 0x2585) */
void p02_L_6585(void) {
  p00_L_1653();
  p00_L_1873();
  p00_L_1887();
  return;
}

/* flash page 2 cpu 0x658F (offset 0x258F) */
void p02_L_658F(void) {
  p00_L_396F();
  return;
}

/* flash page 2 cpu 0x65BE (offset 0x25BE) */
void p02_L_65BE(void) {
  p00_L_14A7();
  p00_L_104E();
  return;
}

/* flash page 2 cpu 0x65C4 (offset 0x25C4) */
void p02_L_65C4(void) {
  goto lab_p02_L_65C4;
  lab_p02_L_65C1: ;
  p00_L_104E();
  return;
  lab_p02_L_65C4: ;
  cpu_push_de();
  p00_L_0FB1();
  p00_L_14B0();
  cpu_pop_de();
  p00_L_0FB1();
  p00_L_14B0();
  goto lab_p02_L_65C1;
}

/* flash page 2 cpu 0x65D4 (offset 0x25D4) */
void p02_L_65D4(void) {
  d = 0x09;
  p02_L_65D6();
  return;
}

/* flash page 2 cpu 0x65D6 (offset 0x25D6) */
void p02_L_65D6(void) {
  a = mem_read8(0x8479);
  cpu_push_af();
  a = 0x80;
  mem_write8(0x8479, a);
  p00_L_0FB1();
  cpu_pop_bc();
  set_hl(0x8479);
  a = mem_read8(hl());
  mem_write8(hl(), b);
  flag_cmp(a, 0x80);
  if (flag_z()) return;
  p00_L_15F3();
  return;
}

/* flash page 2 cpu 0x65EE (offset 0x25EE) */
void p02_L_65EE(void) {
  a = mem_read8(0x97B0);
  flag_cmp(a, 0xFF);
  if (flag_z()) return;
  d = a;
  p00_L_0FB1();
  return;
}

/* flash page 2 cpu 0x65F8 (offset 0x25F8) */
void p02_L_65F8(void) {
  p00_rst10();
  cpu_ex_de_hl();
  p00_L_0033();
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) { p00_L_24FD(); return; }
  return;
}

/* flash page 2 cpu 0x6603 (offset 0x2603) */
void p02_L_6603(void) {
  a = mem_read8(0x9305);
  cpu_push_af();
  p02_L_66D3();
  return;
}

/* flash page 2 cpu 0x660A (offset 0x260A) */
void p02_L_660A(void) {
  a = mem_read8(0x9305);
  a = (uint8_t)(a + 1);
  cpu_push_af();
  p00_L_22F7();
  a = mem_read8(0x8485);
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_z()) { p02_L_66D3(); return; }
  cpu_pop_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x07)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p02_L_663A;
  p00_L_019D();
  if (flag_z()) { p02_L_66D3(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p02_L_663A;
  p00_L_172A();
  if (flag_z()) { p02_L_66D3(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p02_L_692D;
  lab_p02_L_663A: ;
  p00_L_1653();
  p00_L_14E1();
  if (flag_nz()) { p00_L_24FD(); return; }
  set_hl(0x8FE0);
  p00_L_1073();
  if (flag_nc()) goto lab_p02_L_665B;
  a = mem_read8(0x84E9);
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p00_L_24FD(); return; }
  set_hl(0x8478);
  mem_write8(hl(), 0x0E);
  p00_L_21A7();
  return;
  lab_p02_L_665B: ;
  p00_rst08();
  p00_L_22FC();
  p02_L_65F8();
  p00_L_39F3();
  p00_L_0C2D();
  p00_L_1873();
  p00_L_1887();
  p00_L_1221();
  p00_L_107E();
  if (flag_nc()) { p00_L_24C9(); return; }
  p00_L_2196();
  a = mem_read8(0x8485);
  set_hl(0x901F);
  set_de(0x8E2D);
  set_bc(0x8FCE);
  flag_cmp(a, 0x81);
  if (flag_c()) goto lab_p02_L_669E;
  set_hl(0x9031);
  set_de(0x8E3F);
  set_bc(0x8FD7);
  if (flag_z()) goto lab_p02_L_669E;
  set_hl(0x9043);
  set_de(0x8E51);
  set_bc(0x8FFB);
  lab_p02_L_669E: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x10);
  cpu_push_af();
  cpu_push_hl();
  cpu_push_de();
  h = b;
  l = c;
  p02_L_4EB6();
  b = a;
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_af();
  a = b;
  if (flag_z()) goto lab_p02_L_66BD;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p02_L_66B7;
  cpu_ex_de_hl();
  lab_p02_L_66B7: ;
  set_de(0x0009);
  set_hl((uint16_t)(hl() + de()));
  goto lab_p02_L_66C1;
  lab_p02_L_66BD: ;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_66C1;
  cpu_ex_de_hl();
  lab_p02_L_66C1: ;
  p00_rst20();
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_nz()) return;
  a = mem_read8(0x84E9);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  p00_L_1040();
  p00_L_24FD();
  return;
  lab_p02_L_692D: ;
  p00_L_1653();
  p00_L_14DB();
  if (flag_nz()) { p00_L_24FD(); return; }
  p00_L_14C7();
  if (flag_nz()) { p00_L_24FD(); return; }
  p00_L_219B();
  a = mem_read8(0x847A);
  flag_cmp(a, 0x81);
  cpu_push_af();
  a = mem_read8(0x89F8);
  a = a & 0x60;
  flag_logic(a);
  flag_cmp(a, 0x40);
  if (flag_c()) goto lab_p02_L_695C;
  if (flag_nz()) goto lab_p02_L_6955;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_695F;
  goto lab_p02_L_6962;
  lab_p02_L_6955: ;
  cpu_pop_af();
  if (flag_c()) goto lab_p02_L_695F;
  if (flag_z()) goto lab_p02_L_695F;
  goto lab_p02_L_6962;
  lab_p02_L_695C: ;
  cpu_pop_af();
  if (flag_c()) goto lab_p02_L_6962;
  lab_p02_L_695F: ;
  p00_L_24FD();
  return;
  lab_p02_L_6962: ;
  p00_L_38F1();
  return;
}

/* flash page 2 cpu 0x66D3 (offset 0x26D3) */
void p02_L_66D3(void) {
  p00_L_2222();
  p00_L_1037();
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p02_L_66E3;
  p00_L_24DD();
  return;
  lab_p02_L_66E3: ;
  p00_L_2315();
  p02_L_65F8();
  set_hl(0x847A);
  a = 0x5B;
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p02_L_66FF;
  a = 0x54;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p02_L_66FF;
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p02_L_67DD;
  a = 0x58;
  lab_p02_L_66FF: ;
  cpu_push_af();
  p00_L_1295();
  cpu_pop_af();
  mem_write8(0x8479, a);
  p00_rst18();
  p00_L_38D9();
  p00_L_2315();
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p02_L_6757;
  cpu_pop_af();
  flag_cmp(a, 0x04);
  if (flag_z()) { p00_L_2501(); return; }
  mem_write8(0x9305, a);
  set_hl(0x674A);
  p00_L_25A2();
  p00_rst18();
  p00_L_2315();
  p00_L_38DF();
  p00_L_2324();
  p00_L_39E7();
  p00_L_1717();
  p02_L_638E();
  p00_L_25C8();
  p02_L_673A();
  return;
  lab_p02_L_6757: ;
  cpu_pop_af();
  flag_cmp(a, 0x03);
  if (flag_z()) { p00_L_2501(); return; }
  mem_write8(0x9305, a);
  p02_L_68F8();
  cpu_push_hl();
  lab_p02_L_6764: ;
  p00_L_2324();
  p00_rst10();
  cpu_pop_hl();
  cpu_push_hl();
  p02_L_47A2();
  set_hl(0x6745);
  p00_L_25A2();
  p00_rst18();
  p00_L_2324();
  p00_L_38DF();
  p00_L_22CF();
  p00_L_39E7();
  p00_L_1717();
  p00_L_1037();
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_L_25C8();
  cpu_pop_hl();
  p02_L_6910();
  if (flag_z()) goto lab_p02_L_6795;
  cpu_push_de();
  goto lab_p02_L_6764;
  lab_p02_L_6795: ;
  cpu_pop_af();
  p00_L_2324();
  p00_L_16BC();
  p00_L_219B();
  p02_L_638E();
  p02_L_673A();
  return;
  lab_p02_L_67DD: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x07)) & (1u << 5)) == 0);
  if (flag_nz()) { p00_L_24FD(); return; }
  cpu_pop_af();
  p02_L_67E5();
  return;
}

/* flash page 2 cpu 0x673A (offset 0x273A) */
void p02_L_673A(void) {
  set_de(0x0012);
  p00_L_21B6();
  set_hl(0x9305);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  return;
}

/* flash page 2 cpu 0x67A5 (offset 0x27A5) */
void p02_L_67A5(void) {
  p00_rst18();
  p00_L_1229();
  p02_L_67A9();
  return;
}

/* flash page 2 cpu 0x67A9 (offset 0x27A9) */
void p02_L_67A9(void) {
  p00_rst18();
  p00_L_22CF();
  p02_L_65F8();
  a = mem_read8(0x847A);
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_z()) goto lab_p02_L_67DA;
  p00_L_172A();
  if (flag_z()) goto lab_p02_L_67C2;
  p00_L_019D();
  if (flag_nz()) { p00_L_24FD(); return; }
  lab_p02_L_67C2: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x07)) & (1u << 5)) == 0);
  if (flag_nz()) { p00_L_24FD(); return; }
  set_hl(0x0000);
  p00_L_1C40();
  p00_L_21D6();
  goto lab_p02_L_6828;
  lab_p02_L_67DA: ;
  p00_L_24DD();
  return;
  lab_p02_L_6828: ;
  p00_L_38E5();
  if (flag_z()) { p00_L_24F1(); return; }
  p00_L_16B5();
  p00_L_289D();
  p02_L_67D4();
  p00_L_1887();
  p00_L_28CB();
  p02_L_67D4();
  p00_rst08();
  p00_L_28B5();
  p02_L_67D4();
  p00_L_107E();
  if (flag_c()) { p00_L_24CD(); return; }
  p00_L_28CB();
  set_hl(0x8FE0);
  p00_L_1073();
  if (flag_c()) { p00_L_24C9(); return; }
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 5)));
  set_hl(0x68E7);
  p00_L_25A2();
  p00_L_28CB();
  p02_L_4CDB();
  p02_L_6869();
  return;
}

/* flash page 2 cpu 0x67D4 (offset 0x27D4) */
void p02_L_67D4(void) {
  p00_L_1653();
  p00_L_187F();
  return;
}

/* flash page 2 cpu 0x67E5 (offset 0x27E5) */
void p02_L_67E5(void) {
  lab_p02_L_67E5: ;
  p00_L_22FC();
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p02_L_6822;
  p02_L_68F8();
  cpu_push_hl();
  lab_p02_L_67F3: ;
  p00_L_2324();
  p00_rst18();
  p00_L_2324();
  p00_rst10();
  cpu_pop_hl();
  cpu_push_hl();
  p02_L_47A2();
  p00_rst18();
  p02_L_67E5();
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_z()) { p00_L_24FD(); return; }
  cpu_pop_hl();
  p02_L_6910();
  if (flag_z()) goto lab_p02_L_6815;
  cpu_push_de();
  goto lab_p02_L_67F3;
  lab_p02_L_6815: ;
  cpu_pop_af();
  p00_L_2315();
  p00_L_16BC();
  p00_L_219B();
  p02_L_673A();
  return;
  lab_p02_L_6822: ;
  p00_rst18();
  p00_L_1229();
  p00_rst18();
  p00_rst18();
  p00_L_38E5();
  if (flag_z()) { p00_L_24F1(); return; }
  p00_L_16B5();
  p00_L_289D();
  p02_L_67D4();
  p00_L_1887();
  p00_L_28CB();
  p02_L_67D4();
  p00_rst08();
  p00_L_28B5();
  p02_L_67D4();
  p00_L_107E();
  if (flag_c()) { p00_L_24CD(); return; }
  p00_L_28CB();
  set_hl(0x8FE0);
  p00_L_1073();
  if (flag_c()) { p00_L_24C9(); return; }
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 5)));
  set_hl(0x68E7);
  p00_L_25A2();
  p00_L_28CB();
  p02_L_4CDB();
  p02_L_6869();
  return;
}

/* flash page 2 cpu 0x6869 (offset 0x2869) */
void p02_L_6869(void) {
  p00_L_16B5();
  p00_L_39F3();
  p00_L_0C1B();
  p00_L_39D5();
  p00_L_1867();
  p00_L_28E5();
  a = mem_read8(0x847A);
  set_hl(0x8E2D);
  flag_cmp(a, 0x81);
  if (flag_c()) goto lab_p02_L_688D;
  set_hl(0x8E3F);
  if (flag_z()) goto lab_p02_L_688D;
  set_hl(0x8E51);
  lab_p02_L_688D: ;
  p00_rst20();
  p00_L_15FB();
  p00_L_1169();
  p00_L_2902();
  p00_L_1037();
  if (flag_nz()) goto lab_p02_L_68B0;
  p00_L_2338();
  p00_L_25C8();
  p00_L_219B();
  set_de(0x0024);
  p00_L_21B6();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 5)));
  return;
  lab_p02_L_68B0: ;
  p00_rst10();
  a = 0x01;
  p00_L_38EB();
  p02_L_4785();
  cpu_ex_de_hl();
  set_hl(0x84AF);
  p00_L_1183();
  p00_L_28CB();
  p00_L_2893();
  p00_rst30();
  p00_L_28C3();
  p00_L_29D3();
  p02_L_68CD();
  return;
}

/* flash page 2 cpu 0x68CD (offset 0x28CD) */
void p02_L_68CD(void) {
  goto lab_p02_L_68CD;
  lab_p02_L_689F: ;
  p00_L_25C8();
  p00_L_219B();
  set_de(0x0024);
  p00_L_21B6();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 5)));
  return;
  lab_p02_L_68CD: ;
  p00_L_107E();
  if (flag_z()) { p00_L_24CD(); return; }
  p00_L_28B5();
  p00_L_28C3();
  p00_L_107E();
  if (flag_c()) goto lab_p02_L_689F;
  p00_L_28CB();
  p02_L_4D13();
  p02_L_6869();
  return;
}

/* flash page 2 cpu 0x68F8 (offset 0x28F8) */
void p02_L_68F8(void) {
  p00_rst10();
  cpu_ex_de_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_z()) { p00_L_24ED(); return; }
  cpu_pop_bc();
  cpu_push_de();
  cpu_push_bc();
  cpu_ex_de_hl();
  p00_L_1C40();
  p00_L_21D6();
  set_hl(0x0001);
  return;
}

/* flash page 2 cpu 0x6910 (offset 0x2910) */
void p02_L_6910(void) {
  cpu_push_hl();
  p00_L_1100();
  p00_L_22FC();
  p00_rst10();
  cpu_push_de();
  p00_L_113F();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_push_hl();
  p02_L_47DC();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_bc();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) return;
  set_de((uint16_t)(de() + 1));
  return;
}

/* flash page 2 cpu 0x6966 (offset 0x2966) */
void p02_L_6966(void) {
  cpu_push_af();
  goto lab_p02_L_6973;
  lab_p02_L_6973: ;
  p00_L_230B();
  p00_rst18();
  p00_L_2315();
  p00_L_1653();
  p00_L_113F();
  p00_L_38D9();
  p00_L_2315();
  set_hl(0x6A0D);
  p00_L_25A2();
  p02_L_6A02();
  p00_rst18();
  p00_L_113F();
  p00_L_38DF();
  p00_L_16B5();
  p00_L_28B5();
  p00_L_38B5();
  p00_rst18();
  p00_L_28FD();
  p00_rst30();
  p02_L_69EF();
  p00_L_2191();
  p00_L_16B5();
  p00_rst18();
  p00_L_28FD();
  p00_L_113F();
  p00_L_0C2D();
  p02_L_69EF();
  p00_L_2196();
  p00_L_0C13();
  p00_rst18();
  p00_L_2315();
  p00_L_0C18();
  p00_rst08();
  p00_L_219B();
  p00_L_0ED0();
  p00_L_25C8();
  set_de(0x0012);
  p00_L_21B6();
  set_hl(0x9304);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p02_L_638E();
  cpu_pop_af();
  if (flag_nz()) { p00_L_21A7(); return; }
  p00_L_2191();
  p00_rst18();
  p00_L_113F();
  p00_L_16BC();
  p00_L_219B();
  return;
}

/* flash page 2 cpu 0x6969 (offset 0x2969) */
void p02_L_6969(void) {
  cpu_push_af();
  p00_rst18();
  p00_L_1229();
  a = 0x7D;
  mem_write8(0x8479, a);
  p00_L_230B();
  p00_rst18();
  p00_L_2315();
  p00_L_1653();
  p00_L_113F();
  p00_L_38D9();
  p00_L_2315();
  set_hl(0x6A0D);
  p00_L_25A2();
  p02_L_6A02();
  p00_rst18();
  p00_L_113F();
  p00_L_38DF();
  p00_L_16B5();
  p00_L_28B5();
  p00_L_38B5();
  p00_rst18();
  p00_L_28FD();
  p00_rst30();
  p02_L_69EF();
  p00_L_2191();
  p00_L_16B5();
  p00_rst18();
  p00_L_28FD();
  p00_L_113F();
  p00_L_0C2D();
  p02_L_69EF();
  p00_L_2196();
  p00_L_0C13();
  p00_rst18();
  p00_L_2315();
  p00_L_0C18();
  p00_rst08();
  p00_L_219B();
  p00_L_0ED0();
  p00_L_25C8();
  set_de(0x0012);
  p00_L_21B6();
  set_hl(0x9304);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p02_L_638E();
  cpu_pop_af();
  if (flag_nz()) { p00_L_21A7(); return; }
  p00_L_2191();
  p00_rst18();
  p00_L_113F();
  p00_L_16BC();
  p00_L_219B();
  return;
}

/* flash page 2 cpu 0x69EF (offset 0x29EF) */
void p02_L_69EF(void) {
  p00_rst18();
  p00_L_28B5();
  p00_L_38DF();
  p00_L_28CB();
  p00_L_39E7();
  p00_L_1717();
  p00_L_1653();
  return;
}

/* flash page 2 cpu 0x6A02 (offset 0x2A02) */
void p02_L_6A02(void) {
  set_hl(0x9304);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0x03);
  if (flag_z()) { p00_L_2501(); return; }
  return;
}

/* flash page 2 cpu 0x6A1E (offset 0x2A1E) */
void p02_L_6A1E(void) {
  p00_L_21E5();
  p00_L_16A2();
  goto lab_p02_L_6A34;
  lab_p02_L_6A34: ;
  p00_rst18();
  p00_L_38B5();
  a = 0x25;
  p02_L_604C();
  p00_L_1037();
  if (flag_nz()) { p00_L_24C9(); return; }
  return;
}

/* flash page 2 cpu 0x6A26 (offset 0x2A26) */
void p02_L_6A26(void) {
  p00_L_21E5();
  p00_L_1689();
  goto lab_p02_L_6A34;
  lab_p02_L_6A34: ;
  p00_rst18();
  p00_L_38B5();
  a = 0x25;
  p02_L_604C();
  p00_L_1037();
  if (flag_nz()) { p00_L_24C9(); return; }
  return;
}

/* flash page 2 cpu 0x6A2E (offset 0x2A2E) */
void p02_L_6A2E(void) {
  p00_L_21E5();
  p00_L_16AA();
  p00_rst18();
  p00_L_38B5();
  a = 0x25;
  p02_L_604C();
  p00_L_1037();
  if (flag_nz()) { p00_L_24C9(); return; }
  return;
}

/* flash page 2 cpu 0x6A44 (offset 0x2A44) */
void p02_L_6A44(void) {
  p02_L_6A26();
  /* bit 2,(iy) */
  set_hl(0x6A15);
  if (flag_nz()) p00_L_0D19();
  p00_rst18();
  p00_L_1689();
  p00_L_38B5();
  p02_L_7250();
  p00_L_1161();
  p00_L_1171();
  p00_L_22F7();
  p00_L_0D1F();
  p00_L_10DD();
  p00_L_1130();
  p00_L_0D1F();
  p00_L_233D();
  p00_L_168D();
  p00_L_38B5();
  p00_rst08();
  p00_L_1130();
  p00_L_0D1F();
  p00_L_1169();
  p00_L_113A();
  p00_L_0D1F();
  p00_L_2196();
  p00_L_0C13();
  p00_L_1171();
  p00_L_1135();
  p00_L_1128();
  p00_L_0C34();
  p00_L_1108();
  return;
}

/* flash page 2 cpu 0x6A9E (offset 0x2A9E) */
void p02_L_6A9E(void) {
  p02_L_6A2E();
  p00_L_22F7();
  p00_L_233D();
  p00_L_1179();
  p02_L_6A2E();
  p00_L_2196();
  p00_L_0ED0();
  return;
}

/* flash page 2 cpu 0x6AB3 (offset 0x2AB3) */
void p02_L_6AB3(void) {
  p00_L_0E49();
  p02_L_6AB9();
  p02_L_6AB9();
  return;
}

/* flash page 2 cpu 0x6AB9 (offset 0x2AB9) */
void p02_L_6AB9(void) {
  p00_L_1100();
  p00_L_219B();
  p00_rst30();
  p00_L_10F8();
  goto lab_p02_L_6AFE;
  lab_p02_L_6AFE: ;
  p00_L_104E();
  return;
}

/* flash page 2 cpu 0x6AC8 (offset 0x2AC8) */
void p02_L_6AC8(void) {
  p00_L_21E5();
  p00_L_2324();
  p00_L_0D1F();
  p02_L_6D0B();
  set_hl(mem_read16(0x9824));
  set_de(0x8478);
  set_bc(0xFFF7);
  set_hl((uint16_t)(hl() + bc()));
  p00_L_2253();
  p00_rst08();
  p02_L_6D0E();
  p00_L_1490();
  p00_rst30();
  p00_L_14A2();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_2196();
  p00_L_0C2D();
  p00_L_21A4();
  p02_L_6AFB();
  return;
}

/* flash page 2 cpu 0x6AFB (offset 0x2AFB) */
void p02_L_6AFB(void) {
  p00_L_10EF();
  p00_L_104E();
  return;
}

/* flash page 2 cpu 0x6B01 (offset 0x2B01) */
void p02_L_6B01(void) {
  p00_L_1207();
  p00_L_21DB();
  a = 0;
  flag_logic(a);
  mem_write8(0x8490, a);
  p00_L_21DB();
  p02_L_6B0E();
  return;
}

/* flash page 2 cpu 0x6B0E (offset 0x2B0E) */
void p02_L_6B0E(void) {
  p02_L_6D17();
  cpu_push_de();
  p02_L_6D0B();
  p00_L_21E5();
  p00_L_1490();
  p02_L_6D0E();
  p00_L_22F7();
  p00_L_0C2D();
  p00_L_233D();
  p00_L_10F8();
  p00_L_2324();
  p00_L_0D1F();
  p00_L_2375();
  p00_L_1490();
  p02_L_6D0E();
  p00_L_231F();
  p00_rst30();
  p00_L_2375();
  p00_L_113F();
  p02_L_6B8F();
  a = mem_read8(0x8479);
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p00_L_24C9(); return; }
  cpu_pop_de();
  p02_L_6B6D();
  p00_L_1100();
  p00_L_2196();
  p00_L_21A7();
  p00_L_219B();
  p02_L_6CC7();
  p02_L_6B60();
  return;
}

/* flash page 2 cpu 0x6B60 (offset 0x2B60) */
void p02_L_6B60(void) {
  goto lab_p02_L_6B60;
  lab_p02_L_6AFE: ;
  p00_L_104E();
  return;
  lab_p02_L_6B60: ;
  goto lab_p02_L_6AFE;
}

/* flash page 2 cpu 0x6B62 (offset 0x2B62) */
void p02_L_6B62(void) {
  p02_L_6D17();
  cpu_push_de();
  p02_L_6B8C();
  p02_L_6D46();
  cpu_pop_de();
  p02_L_6B6D();
  return;
}

/* flash page 2 cpu 0x6B6D (offset 0x2B6D) */
void p02_L_6B6D(void) {
  flag_set_z((d & (1u << 7)) == 0);
  if (flag_z()) goto lab_p02_L_6B83;
  d = (uint8_t)(d & ~(1u << 7));
  p00_L_170A();
  if (flag_c()) { p00_L_128A(); return; }
  lab_p02_L_6B79: ;
  mem_write8(0x8479, a);
  return;
  lab_p02_L_6B83: ;
  a = mem_read8(0x8479);
  a = (uint8_t)(a + e);
  if (flag_c()) { p00_L_24BD(); return; }
  goto lab_p02_L_6B79;
}

/* flash page 2 cpu 0x6B7D (offset 0x2B7D) */
void p02_L_6B7D(void) {
  goto lab_p02_L_6B7D;
  lab_p02_L_6B73: ;
  p00_L_170A();
  if (flag_c()) { p00_L_128A(); return; }
  lab_p02_L_6B79: ;
  mem_write8(0x8479, a);
  return;
  lab_p02_L_6B7D: ;
  flag_set_z((d & (1u << 7)) == 0);
  if (flag_z()) goto lab_p02_L_6B73;
  d = (uint8_t)(d & ~(1u << 7));
  a = mem_read8(0x8479);
  a = (uint8_t)(a + e);
  if (flag_c()) { p00_L_24BD(); return; }
  goto lab_p02_L_6B79;
}

/* flash page 2 cpu 0x6B8C (offset 0x2B8C) */
void p02_L_6B8C(void) {
  p00_L_10E6();
  p02_L_6B8F();
  return;
}

/* flash page 2 cpu 0x6B8F (offset 0x2B8F) */
void p02_L_6B8F(void) {
  p00_L_0D1E();
  p00_L_14A2();
  p00_L_0D1E();
  p00_L_10EF();
  p00_rst30();
  p00_L_1040();
  return;
}

/* flash page 2 cpu 0x6B9F (offset 0x2B9F) */
void p02_L_6B9F(void) {
  p00_L_1171();
  p00_L_1161();
  p02_L_6B62();
  p00_L_1108();
  a = 0;
  flag_logic(a);
  mem_write8(0x8483, a);
  p00_rst30();
  p00_L_0D16();
  p02_L_6D46();
  p00_L_14C7();
  if (flag_nz()) goto lab_p02_L_6BBE;
  p00_rst08();
  goto lab_p02_L_6BE2;
  lab_p02_L_6BBE: ;
  p00_L_10DD();
  p00_L_0C18();
  p00_rst08();
  p00_L_1130();
  p00_L_0ED0();
  p00_L_10EF();
  a = mem_read8(0x84A4);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_6BDF;
  a = mem_read8(0x84AF);
  a = a & 0x80;
  flag_logic(a);
  if (flag_nz()) p00_L_0E49();
  goto lab_p02_L_6BE2;
  lab_p02_L_6BDF: ;
  p00_L_14B0();
  lab_p02_L_6BE2: ;
  p02_L_6B60();
  return;
}

/* flash page 2 cpu 0x6BE5 (offset 0x2BE5) */
void p02_L_6BE5(void) {
  goto lab_p02_L_6BE5;
  lab_p02_L_6BE2: ;
  p02_L_6B60();
  return;
  lab_p02_L_6BE5: ;
  p00_L_1161();
  p00_L_21E5();
  p02_L_6B62();
  p02_L_6E0B();
  p00_L_148B();
  p00_L_2196();
  d = 0x00;
  p02_L_75E2();
  p00_rst08();
  p00_L_1130();
  goto lab_p02_L_6BE2;
}

/* flash page 2 cpu 0x6C02 (offset 0x2C02) */
void p02_L_6C02(void) {
  goto lab_p02_L_6C02;
  lab_p02_L_6BE2: ;
  p02_L_6B60();
  return;
  lab_p02_L_6BFC: ;
  p00_rst08();
  p00_L_1130();
  goto lab_p02_L_6BE2;
  lab_p02_L_6C02: ;
  p00_L_1161();
  p00_L_21E5();
  p02_L_6B62();
  p02_L_6E24();
  p00_L_148B();
  p00_L_2196();
  d = 0x00;
  p02_L_75E2();
  a = 0x03;
  p00_L_1531();
  p00_L_0D1F();
  goto lab_p02_L_6BFC;
}

/* flash page 2 cpu 0x6C23 (offset 0x2C23) */
void p02_L_6C23(void) {
  p00_L_10E6();
  a = 0x03;
  p00_L_1531();
  p00_L_0ED0();
  p00_L_14A2();
  p00_L_0ED0();
  p00_rst08();
  p00_L_1135();
  p02_L_6C38();
  return;
}

/* flash page 2 cpu 0x6C38 (offset 0x2C38) */
void p02_L_6C38(void) {
  p00_L_1161();
  p02_L_6F6A();
  p00_L_148B();
  p02_L_724C();
  p00_L_1479();
  p00_L_0D1F();
  p00_L_10DD();
  p00_L_1130();
  p00_L_0D1F();
  p02_L_6AFB();
  return;
}

/* flash page 2 cpu 0x6C56 (offset 0x2C56) */
void p02_L_6C56(void) {
  p00_L_2242();
  p00_L_14C2();
  if (flag_z()) goto lab_p02_L_6C86;
  p02_L_6B01();
  p02_L_6C77();
  return;
  lab_p02_L_6C86: ;
  if (flag_z()) { p00_L_24C9(); return; }
  a = mem_read8(0x848E);
  a = a | a;
  flag_logic(a);
  if (flag_m()) { p00_L_24C9(); return; }
  p00_L_21A4();
  p00_L_1048();
  return;
}

/* flash page 2 cpu 0x6C63 (offset 0x2C63) */
void p02_L_6C63(void) {
  cpu_pop_af();
  p00_L_1280();
  p00_L_22FC();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_0ECC();
  p00_L_1287();
  p00_L_2333();
  p02_L_6C77();
  return;
}

/* flash page 2 cpu 0x6C77 (offset 0x2C77) */
void p02_L_6C77(void) {
  p00_L_1100();
  p00_L_2242();
  p00_L_14C2();
  if (flag_nz()) goto lab_p02_L_6C96;
  a = mem_read8(0x8490);
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p00_L_24C9(); return; }
  a = mem_read8(0x848E);
  a = a | a;
  flag_logic(a);
  if (flag_m()) { p00_L_24C9(); return; }
  p00_L_21A4();
  p00_L_1048();
  return;
  lab_p02_L_6C96: ;
  p02_L_6BE5();
  p02_L_6AC8();
  p02_L_6C38();
  return;
}

/* flash page 2 cpu 0x6CC7 (offset 0x2CC7) */
void p02_L_6CC7(void) {
  goto lab_p02_L_6CC7;
  lab_p02_L_6CAD: ;
  goto lab_p02_L_6CE8;
  lab_p02_L_6CBE: ;
  p00_L_11D8();
  p00_rst08();
  p00_L_1135();
  goto lab_p02_L_6CAD;
  lab_p02_L_6CC7: ;
  p00_L_10E6();
  p00_L_10F8();
  p00_L_0ED0();
  p00_L_14A2();
  p00_L_0ED0();
  goto lab_p02_L_6CBE;
  lab_p02_L_6CE8: ;
  goto lab_p02_L_6D08;
  lab_p02_L_6D08: ;
  p00_L_104E();
  return;
}

/* flash page 2 cpu 0x6D0B (offset 0x2D0B) */
void p02_L_6D0B(void) {
  p00_L_10DD();
  p02_L_6D0E();
  return;
}

/* flash page 2 cpu 0x6D0E (offset 0x2D0E) */
void p02_L_6D0E(void) {
  p00_L_2315();
  p00_L_0D1F();
  p00_L_11D8();
  return;
}

/* flash page 2 cpu 0x6D17 (offset 0x2D17) */
void p02_L_6D17(void) {
  p00_L_1700();
  d = 0x00;
  a = mem_read8(0x8479);
  if (flag_nc()) goto lab_p02_L_6D22;
  a = mem_read8(hl());
  lab_p02_L_6D22: ;
  a = (uint8_t)(a - 0x80);
  if (flag_nc()) goto lab_p02_L_6D2B;
  a = a ^ 0xFF;
  a = (uint8_t)(a + 0x01);
  d = (uint8_t)(d | (1u << 7));
  lab_p02_L_6D2B: ;
  e = a;
  cpu_push_de();
  p02_L_6B7D();
  p00_L_14B0();
  cpu_pop_de();
  cpu_push_de();
  p02_L_6B7D();
  p00_L_14B0();
  cpu_pop_de();
  return;
}

/* flash page 2 cpu 0x6D3D (offset 0x2D3D) */
void p02_L_6D3D(void) {
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 6)));
  p00_L_1873();
  goto lab_p02_L_6D50;
  lab_p02_L_6D50: ;
  p00_L_14C7();
  if (flag_z()) return;
  p00_L_129F();
  set_hl(0x8479);
  a = mem_read8(hl());
  cpu_rra();
  mem_write8(0x848F, a);
  a = 0x00;
  if (flag_c()) p00_L_1301();
  mem_write8(hl(), a);
  p00_L_129A();
  set_de(0x8490);
  a = 0x10;
  mem_write8(0x8483, a);
  c = 0x00;
  set_hl(0x8485);
  cpu_push_de();
  cpu_push_hl();
  b = 0x01;
  p00_L_1382();
  p02_L_6D7C();
  return;
}

/* flash page 2 cpu 0x6D46 (offset 0x2D46) */
void p02_L_6D46(void) {
  p00_L_1873();
  p02_L_6D49();
  return;
}

/* flash page 2 cpu 0x6D49 (offset 0x2D49) */
void p02_L_6D49(void) {
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 6)));
  p00_L_0FB5();
  p00_L_14C7();
  if (flag_z()) return;
  p00_L_129F();
  set_hl(0x8479);
  a = mem_read8(hl());
  cpu_rra();
  mem_write8(0x848F, a);
  a = 0x00;
  if (flag_c()) p00_L_1301();
  mem_write8(hl(), a);
  p00_L_129A();
  set_de(0x8490);
  a = 0x10;
  mem_write8(0x8483, a);
  c = 0x00;
  set_hl(0x8485);
  cpu_push_de();
  cpu_push_hl();
  b = 0x01;
  p00_L_1382();
  p02_L_6D7C();
  return;
}

/* flash page 2 cpu 0x6D7C (offset 0x2D7C) */
void p02_L_6D7C(void) {
  goto lab_p02_L_6D7C;
  lab_p02_L_6D76: ;
  cpu_push_hl();
  b = 0x01;
  p00_L_1382();
  lab_p02_L_6D7C: ;
  set_hl(0x848B);
  set_de(0x8480);
  p00_L_1430();
  if (flag_c()) goto lab_p02_L_6D92;
  c = (uint8_t)(c + 1);
  cpu_pop_hl();
  cpu_push_hl();
  b = 0x02;
  p00_L_1382();
  goto lab_p02_L_6D7C;
  lab_p02_L_6D92: ;
  set_hl(0x8483);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_z()) goto lab_p02_L_6DD2;
  a = c;
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_12B9();
  cpu_pop_bc();
  cpu_pop_de();
  mem_write8(de(), a);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p02_L_6DA8;
  set_bc((uint16_t)(bc() + 1));
  set_de((uint16_t)(de() + 1));
  a = 0;
  flag_logic(a);
  lab_p02_L_6DA8: ;
  cpu_push_de();
  cpu_push_bc();
  c = a;
  set_hl(0x848B);
  set_de(0x8480);
  a = a | a;
  flag_logic(a);
  p00_L_13BB();
  set_hl(0x8479);
  p00_L_12EF();
  /* rld */
  cpu_push_bc();
  p00_L_11B3();
  cpu_pop_bc();
  set_hl(0x848B);
  d = h;
  e = l;
  p00_L_13C1();
  mem_write8(hl(), 0x00);
  if (flag_nc()) goto lab_p02_L_6DCF;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p02_L_6DCF: ;
  cpu_pop_hl();
  goto lab_p02_L_6D76;
  lab_p02_L_6DD2: ;
  cpu_pop_af();
  cpu_pop_hl();
  mem_write8(hl(), c);
  a = mem_read8(0x8478);
  p00_L_113F();
  mem_write8(0x8478, a);
  a = mem_read8(0x8479);
  a = (uint8_t)(a + 0x40);
  mem_write8(0x8479, a);
  p00_L_15CB();
  if (flag_z()) goto lab_p02_L_6E03;
  p00_L_1280();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p02_L_6DF7;
  p00_L_0E07();
  lab_p02_L_6DF7: ;
  p00_rst08();
  p00_L_128A();
  a = 0x0C;
  mem_write8(0x8483, a);
  p00_L_104E();
  return;
  lab_p02_L_6E03: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 6)) == 0);
  if (flag_nz()) return;
  p02_L_78D3();
  return;
}

/* flash page 2 cpu 0x6E0B (offset 0x2E0B) */
void p02_L_6E0B(void) {
  p00_L_15CB();
  c = 0x02;
  if (flag_z()) { p02_L_6E29(); return; }
  p00_L_24C9();
  return;
}

/* flash page 2 cpu 0x6E15 (offset 0x2E15) */
void p02_L_6E15(void) {
  goto lab_p02_L_6E15;
  lab_p02_L_6E0E: ;
  c = 0x02;
  if (flag_z()) { p02_L_6E29(); return; }
  p00_L_24C9();
  return;
  lab_p02_L_6E15: ;
  p00_L_15CB();
  if (flag_z()) goto lab_p02_L_6E0E;
  p00_L_1280();
  p02_L_6BE5();
  return;
}

/* flash page 2 cpu 0x6E20 (offset 0x2E20) */
void p02_L_6E20(void) {
  c = 0x00;
  p02_L_6E29();
  return;
}

/* flash page 2 cpu 0x6E24 (offset 0x2E24) */
void p02_L_6E24(void) {
  c = 0x00;
  p00_L_1873();
  p02_L_6E29();
  return;
}

/* flash page 2 cpu 0x6E29 (offset 0x2E29) */
void p02_L_6E29(void) {
  p00_L_0FB5();
  p00_L_1887();
  p00_L_15CB();
  if (flag_z()) goto lab_p02_L_6E3B;
  p00_L_1280();
  p02_L_6C02();
  return;
  lab_p02_L_6E3B: ;
  cpu_push_bc();
  p00_L_1708();
  if (flag_nc()) goto lab_p02_L_6E8E;
  p00_L_10DD();
  p00_L_0C2A();
  p00_L_170F();
  if (flag_c()) goto lab_p02_L_6E53;
  if (flag_nz()) goto lab_p02_L_6E8B;
  p00_L_15CB();
  if (flag_nz()) goto lab_p02_L_6E8B;
  lab_p02_L_6E53: ;
  p00_L_1100();
  p00_L_1246();
  p00_rst30();
  p00_rst08();
  p00_L_113F();
  p00_L_0ED0();
  p00_L_1251();
  a = mem_read8(0x8478);
  cpu_push_af();
  p00_L_15EB();
  a = 0x80;
  p02_L_76B4();
  p00_L_0C18();
  cpu_pop_af();
  cpu_pop_bc();
  a = a & 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  flag_set_z((c & (1u << 1)) == 0);
  if (flag_nz()) return;
  cpu_push_bc();
  a = 0x03;
  p00_L_0CF7();
  cpu_pop_bc();
  flag_set_z((c & (1u << 0)) == 0);
  if (flag_nz()) return;
  p00_L_0E2D();
  return;
  lab_p02_L_6E8B: ;
  p00_L_1135();
  lab_p02_L_6E8E: ;
  p00_L_129A();
  mem_write8(0x848E, a);
  p00_L_1518();
  if (flag_z()) goto lab_p02_L_6F01;
  lab_p02_L_6E9A: ;
  p02_L_7210();
  goto lab_p02_L_6EA2;
  lab_p02_L_6E9F: ;
  p00_L_138F();
  lab_p02_L_6EA2: ;
  a = mem_read8(0x848E);
  p00_L_1328();
  p00_L_13B5();
  if (flag_nc()) goto lab_p02_L_6E9F;
  p00_L_151C();
  if (flag_z()) goto lab_p02_L_6EFC;
  p00_L_142A();
  set_hl(0x848E);
  a = mem_read8(hl());
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = a & 0x08;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_6E9A;
  set_de(0x8493);
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  set_hl(0x8481);
  p00_L_1448();
  lab_p02_L_6ECA: ;
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  p00_L_12B1();
  if (flag_z()) goto lab_p02_L_6EDD;
  cpu_push_de();
  p02_L_720F();
  lab_p02_L_6ED5: ;
  p00_L_138F();
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p02_L_6ED5;
  cpu_pop_de();
  lab_p02_L_6EDD: ;
  set_hl(0x848E);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  flag_set_z((mem_read8(hl()) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p02_L_6F0A;
  a = mem_read8(de());
  a = a & 0x0F;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_6EF6;
  cpu_push_de();
  p02_L_720F();
  lab_p02_L_6EEE: ;
  p00_L_138F();
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p02_L_6EEE;
  cpu_pop_de();
  lab_p02_L_6EF6: ;
  set_hl(0x848E);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p02_L_6ECA;
  lab_p02_L_6EFC: ;
  p00_L_138F();
  goto lab_p02_L_6F0A;
  lab_p02_L_6F01: ;
  p00_L_163B();
  if (flag_nc()) goto lab_p02_L_6F0A;
  a = (uint8_t)(a - 1);
  mem_write8(0x8479, a);
  lab_p02_L_6F0A: ;
  p00_L_163B();
  if (flag_nc()) goto lab_p02_L_6F1C;
  a = 0x80;
  mem_write8(0x8478, a);
  p00_L_15F3();
  p00_L_11AB();
  p02_L_6F1A();
  return;
  lab_p02_L_6F1C: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8478, a);
  p00_L_1290();
  p00_L_141D();
  p00_L_15A9();
  mem_write8(0x8479, a);
  e = 0x81;
  a = a & 0xF0;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_6F3D;
  e = (uint8_t)(e - 1);
  a = mem_read8(0x8479);
  a = a & 0x0F;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_6F40;
  e = (uint8_t)(e - 1);
  goto lab_p02_L_6F43;
  lab_p02_L_6F3D: ;
  p00_L_12C4();
  lab_p02_L_6F40: ;
  p00_L_12C4();
  lab_p02_L_6F43: ;
  a = e;
  mem_write8(0x8479, a);
  cpu_pop_bc();
  flag_set_z((c & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_6F50;
  p00_L_0F98();
  return;
  lab_p02_L_6F50: ;
  cpu_push_bc();
  p00_L_0E07();
  cpu_pop_bc();
  flag_set_z((c & (1u << 1)) == 0);
  if (flag_z()) return;
  a = 0x06;
  p00_L_0CF7();
  p00_L_0E2D();
  return;
}

/* flash page 2 cpu 0x6F1A (offset 0x2F1A) */
void p02_L_6F1A(void) {
  goto lab_p02_L_6F26;
  lab_p02_L_6F26: ;
  p00_L_15A9();
  mem_write8(0x8479, a);
  e = 0x81;
  a = a & 0xF0;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_6F3D;
  e = (uint8_t)(e - 1);
  a = mem_read8(0x8479);
  a = a & 0x0F;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_6F40;
  e = (uint8_t)(e - 1);
  goto lab_p02_L_6F43;
  lab_p02_L_6F3D: ;
  p00_L_12C4();
  lab_p02_L_6F40: ;
  p00_L_12C4();
  lab_p02_L_6F43: ;
  a = e;
  mem_write8(0x8479, a);
  cpu_pop_bc();
  flag_set_z((c & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_6F50;
  p00_L_0F98();
  return;
  lab_p02_L_6F50: ;
  cpu_push_bc();
  p00_L_0E07();
  cpu_pop_bc();
  flag_set_z((c & (1u << 1)) == 0);
  if (flag_z()) return;
  a = 0x06;
  p00_L_0CF7();
  p00_L_0E2D();
  return;
}

/* flash page 2 cpu 0x6F6A (offset 0x2F6A) */
void p02_L_6F6A(void) {
  p00_L_0FB5();
  a = 0x03;
  p00_L_0CF7();
  p02_L_6F77();
  return;
}

/* flash page 2 cpu 0x6F74 (offset 0x2F74) */
void p02_L_6F74(void) {
  p00_L_0FB5();
  p02_L_6F77();
  return;
}

/* flash page 2 cpu 0x6F77 (offset 0x2F77) */
void p02_L_6F77(void) {
  goto lab_p02_L_6F77;
  lab_p02_L_6F61: ;
  p00_L_15CB();
  if (flag_nz()) { p00_L_128A(); return; }
  p00_L_24BD();
  return;
  lab_p02_L_6F77: ;
  a = mem_read8(0x8479);
  a = (uint8_t)(a - 0x80);
  if (flag_c()) goto lab_p02_L_6FB0;
  b = a;
  a = 0;
  flag_logic(a);
  mem_write8(0x8479, a);
  a = b;
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p02_L_6F61;
  p00_L_1301();
  /* rld */
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_6F97;
  a = mem_read8(hl());
  p00_L_1301();
  /* rld */
  lab_p02_L_6F97: ;
  a = mem_read8(0x8479);
  c = 0x00;
  p00_L_12B1();
  if (flag_z()) goto lab_p02_L_6FA8;
  b = a;
  a = 0;
  flag_logic(a);
  lab_p02_L_6FA3: ;
  a = (uint8_t)(a + 0x0A);
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p02_L_6FA3;
  lab_p02_L_6FA8: ;
  b = a;
  a = mem_read8(hl());
  a = a & 0x0F;
  flag_logic(a);
  a = (uint8_t)(a + b);
  e = a;
  goto lab_p02_L_6FC1;
  lab_p02_L_6FB0: ;
  a = a ^ 0xFF;
  e = a;
  flag_cmp(a, 0x0F);
  if (flag_nc()) { p00_L_1229(); return; }
  cpu_push_de();
  p00_L_1328();
  p00_L_11CB();
  cpu_pop_bc();
  e = 0x00;
  lab_p02_L_6FC1: ;
  a = 0x80;
  a = (uint8_t)(a + e);
  mem_write8(0x8479, a);
  p00_L_15D6();
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_6FE7;
  a = mem_read8(0x8479);
  a = a ^ 0xFF;
  mem_write8(0x8479, a);
  p00_L_151C();
  if (flag_nz()) goto lab_p02_L_6FDF;
  p00_L_15F3();
  goto lab_p02_L_6FE7;
  lab_p02_L_6FDF: ;
  p00_rst08();
  p00_L_1290();
  c = a;
  p00_L_141D();
  lab_p02_L_6FE7: ;
  a = c;
  mem_write8(0x848E, a);
  set_hl(0x849B);
  p00_L_1260();
  b = a;
  set_hl(0x849B);
  /* srl c */
  set_hl((uint16_t)(hl() + bc()));
  lab_p02_L_6FF8: ;
  cpu_push_hl();
  a = 0;
  flag_logic(a);
  lab_p02_L_6FFA: ;
  c = a;
  set_de(0x8485);
  p02_L_7213();
  goto lab_p02_L_700B;
  lab_p02_L_7003: ;
  c = (uint8_t)(c + 1);
  a = c;
  a = a & 0x0F;
  flag_logic(a);
  flag_cmp(a, 0x09);
  if (flag_z()) goto lab_p02_L_7014;
  lab_p02_L_700B: ;
  p00_L_141D();
  if (flag_nc()) goto lab_p02_L_7003;
  p00_L_139F();
  lab_p02_L_7014: ;
  set_hl(0x848E);
  a = mem_read8(hl());
  flag_cmp(a, 0x0F);
  if (flag_z()) goto lab_p02_L_704E;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = a & 0x01;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_7026;
  cpu_pop_hl();
  mem_write8(hl(), c);
  set_hl((uint16_t)(hl() + 1));
  goto lab_p02_L_6FF8;
  lab_p02_L_7026: ;
  p00_L_12B8();
  goto lab_p02_L_6FFA;
  lab_p02_L_704E: ;
  cpu_pop_hl();
  mem_write8(hl(), c);
  set_hl(0x847A);
  p00_L_124D();
  set_de(0x8481);
  set_hl(0x84A2);
  set_bc(0x0003);
  /* lddr */
  a = mem_read8(hl());
  a = a & 0x0F;
  flag_logic(a);
  mem_write8(de(), a);
  c = 0x00;
  set_hl(0x849B);
  lab_p02_L_706A: ;
  cpu_push_hl();
  a = mem_read8(hl());
  cpu_push_af();
  p00_L_12B1();
  p02_L_702B();
  if (flag_nc()) goto lab_p02_L_707B;
  cpu_pop_af();
  lab_p02_L_7076: ;
  cpu_pop_hl();
  p00_L_0E07();
  return;
  lab_p02_L_707B: ;
  cpu_pop_af();
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p02_L_7076;
  c = (uint8_t)(c + 1);
  a = a & 0x0F;
  flag_logic(a);
  p02_L_702B();
  if (flag_c()) goto lab_p02_L_7076;
  cpu_pop_hl();
  c = (uint8_t)(c + 1);
  set_hl((uint16_t)(hl() + 1));
  goto lab_p02_L_706A;
}

/* flash page 2 cpu 0x702B (offset 0x302B) */
void p02_L_702B(void) {
  lab_p02_L_702B: ;
  if (flag_z()) return;
  cpu_push_af();
  cpu_push_bc();
  a = c;
  p00_L_1328();
  p00_L_13B5();
  if (flag_c()) goto lab_p02_L_703E;
  cpu_pop_bc();
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  a = (uint8_t)(a - 1);
  goto lab_p02_L_702B;
  lab_p02_L_703E: ;
  cpu_pop_hl();
  cpu_pop_hl();
  p00_L_15F3();
  set_hl(0x847A);
  p00_L_124D();
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x00);
  /* scf */
  return;
}

/* flash page 2 cpu 0x71C5 (offset 0x31C5) */
void p02_L_71C5(void) {
  a = (uint8_t)(a - l);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_71D8;
  /* nop */
  /* nop */
  /* nop */
  d = b;
  d = b;
  p02_L_71CD();
  return;
  lab_p02_L_71D8: ;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  d = b;
  d = b;
  d = c;
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  a = (uint8_t)(a - h);
  a = (uint8_t)(a - h);
  a = (uint8_t)(a - l);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_71E9;
  lab_p02_L_71E9: ;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  d = b;
  d = c;
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  a = (uint8_t)(a - h);
  a = (uint8_t)(a - l);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_71F9;
  lab_p02_L_71F9: ;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  d = c;
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  a = (uint8_t)(a - l);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_7209;
  lab_p02_L_7209: ;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc(0x114F);
  /* sbc a,e */
  a = (uint8_t)(a + h);
  p02_L_7213();
  return;
}

/* flash page 2 cpu 0x71CD (offset 0x31CD) */
void p02_L_71CD(void) {
  d = b;
  d = d;
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  a = (uint8_t)(a - h);
  a = (uint8_t)(a - h);
  a = (uint8_t)(a - h);
  a = (uint8_t)(a - l);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_71D9;
  lab_p02_L_71D9: ;
  /* nop */
  /* nop */
  /* nop */
  d = b;
  d = b;
  d = c;
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  a = (uint8_t)(a - h);
  a = (uint8_t)(a - h);
  a = (uint8_t)(a - l);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_71E9;
  lab_p02_L_71E9: ;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  d = b;
  d = c;
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  a = (uint8_t)(a - h);
  a = (uint8_t)(a - l);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_71F9;
  lab_p02_L_71F9: ;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  d = c;
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  /* sbc a,c */
  a = (uint8_t)(a - l);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_7209;
  lab_p02_L_7209: ;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc(0x114F);
  /* sbc a,e */
  a = (uint8_t)(a + h);
  p02_L_7213();
  return;
}

/* flash page 2 cpu 0x720F (offset 0x320F) */
void p02_L_720F(void) {
  c = a;
  p02_L_7210();
  return;
}

/* flash page 2 cpu 0x7210 (offset 0x3210) */
void p02_L_7210(void) {
  set_de(0x849B);
  p02_L_7213();
  return;
}

/* flash page 2 cpu 0x7213 (offset 0x3213) */
void p02_L_7213(void) {
  set_hl(0x708F);
  a = mem_read8(0x848E);
  cpu_push_bc();
  c = 0x08;
  b = a;
  a = 0;
  flag_logic(a);
  goto lab_p02_L_723F;
  lab_p02_L_723E: ;
  a = (uint8_t)(a + c);
  lab_p02_L_723F: ;
  b = (uint8_t)(b - 1);
  if (flag_p()) goto lab_p02_L_723E;
  c = a;
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  p00_L_1185();
  cpu_pop_bc();
  return;
}

/* flash page 2 cpu 0x7220 (offset 0x3220) */
void p02_L_7220(void) {
  set_hl(0x718F);
  set_de(0x8485);
  goto lab_p02_L_722E;
  lab_p02_L_722E: ;
  a = mem_read8(0x84A4);
  cpu_push_bc();
  a = a & 0x80;
  flag_logic(a);
  a = 0x00;
  c = 0x10;
  if (flag_z()) goto lab_p02_L_723F;
  a = (uint8_t)(a + 0x08);
  goto lab_p02_L_723F;
  lab_p02_L_723E: ;
  a = (uint8_t)(a + c);
  lab_p02_L_723F: ;
  b = (uint8_t)(b - 1);
  if (flag_p()) goto lab_p02_L_723E;
  c = a;
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  p00_L_1185();
  cpu_pop_bc();
  return;
}

/* flash page 2 cpu 0x7228 (offset 0x3228) */
void p02_L_7228(void) {
  set_de(0x849B);
  p02_L_722B();
  return;
}

/* flash page 2 cpu 0x722B (offset 0x322B) */
void p02_L_722B(void) {
  set_hl(0x710F);
  a = mem_read8(0x84A4);
  cpu_push_bc();
  a = a & 0x80;
  flag_logic(a);
  a = 0x00;
  c = 0x10;
  if (flag_z()) goto lab_p02_L_723F;
  a = (uint8_t)(a + 0x08);
  goto lab_p02_L_723F;
  lab_p02_L_723E: ;
  a = (uint8_t)(a + c);
  lab_p02_L_723F: ;
  b = (uint8_t)(b - 1);
  if (flag_p()) goto lab_p02_L_723E;
  c = a;
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  p00_L_1185();
  cpu_pop_bc();
  return;
}

/* flash page 2 cpu 0x724C (offset 0x324C) */
void p02_L_724C(void) {
  a = 0x81;
  goto lab_p02_L_7262;
  lab_p02_L_7262: ;
  mem_write8(0x8499, a);
  p00_L_0FB5();
  p00_L_129F();
  a = mem_read8(0x8479);
  a = (uint8_t)(a - 0x80);
  if (flag_c()) goto lab_p02_L_72E2;
  flag_cmp(a, 0x0C);
  if (flag_nc()) { p00_L_24C9(); return; }
  l = a;
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_728A;
  set_hl(0x1583);
  p00_L_11D3();
  b = 0x80;
  goto lab_p02_L_7296;
  lab_p02_L_728A: ;
  a = l;
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p02_L_72E2;
  a = 0x36;
  mem_write8(0x8490, a);
  b = 0x82;
  lab_p02_L_7296: ;
  c = 0x00;
  lab_p02_L_7298: ;
  p00_L_1470();
  if (flag_nc()) goto lab_p02_L_7298;
  c = (uint8_t)(c - 1);
  if (flag_p()) goto lab_p02_L_7298;
  p00_L_140C();
  set_hl(0x8479);
  a = b;
  cpu_cp_hl();
  if (flag_z()) goto lab_p02_L_72B2;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p00_L_12EF();
  c = a;
  goto lab_p02_L_7298;
  lab_p02_L_72B2: ;
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_72C6;
  p00_L_119E();
  set_hl(0x1590);
  p00_L_1461();
  if (flag_c()) goto lab_p02_L_72E2;
  goto lab_p02_L_72D4;
  lab_p02_L_72C6: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x18);
  if (flag_c()) goto lab_p02_L_72E2;
  if (flag_nz()) goto lab_p02_L_72D4;
  p00_L_151D();
  if (flag_z()) goto lab_p02_L_72E2;
  lab_p02_L_72D4: ;
  p00_L_1467();
  p00_L_11C3();
  a = mem_read8(0x8478);
  a = a ^ 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  lab_p02_L_72E2: ;
  p00_L_0F98();
  p00_L_15D6();
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_72EE;
  a = 0x03;
  lab_p02_L_72EE: ;
  cpu_push_af();
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_7383;
  p00_L_129F();
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_730F;
  set_hl(0x1598);
  p00_L_11D3();
  p00_L_163B();
  if (flag_c()) goto lab_p02_L_733F;
  c = 0x00;
  goto lab_p02_L_7324;
  lab_p02_L_730F: ;
  p00_L_1708();
  a = 0x90;
  mem_write8(0x8490, a);
  if (flag_c()) goto lab_p02_L_7373;
  c = 0x00;
  if (flag_z()) goto lab_p02_L_7324;
  p00_L_15EB();
  p00_L_12EF();
  c = a;
  lab_p02_L_7324: ;
  p00_L_1470();
  if (flag_nc()) goto lab_p02_L_7332;
  c = (uint8_t)(c - 1);
  if (flag_p()) goto lab_p02_L_7332;
  p00_L_140C();
  goto lab_p02_L_7338;
  lab_p02_L_7332: ;
  cpu_pop_af();
  a = a ^ 0x01;
  flag_logic(a);
  a = a | 0x08;
  flag_logic(a);
  cpu_push_af();
  lab_p02_L_7338: ;
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_7362;
  lab_p02_L_733F: ;
  p00_L_0F98();
  a = mem_read8(0x847A);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_7383;
  p00_L_170F();
  if (flag_c()) goto lab_p02_L_7383;
  if (flag_nz()) goto lab_p02_L_7369;
  p00_L_119E();
  set_hl(0x1597);
  p00_L_1461();
  if (flag_c()) goto lab_p02_L_7373;
  p00_L_12BE();
  p00_L_15F3();
  goto lab_p02_L_7369;
  lab_p02_L_7362: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x45);
  if (flag_c()) goto lab_p02_L_7373;
  lab_p02_L_7369: ;
  p00_L_1467();
  p00_L_11C3();
  cpu_pop_af();
  a = a ^ 0x08;
  flag_logic(a);
  cpu_push_af();
  lab_p02_L_7373: ;
  p00_L_0F98();
  p00_L_0FB5();
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_7383;
  p00_L_0CF2();
  lab_p02_L_7383: ;
  set_hl(0x8490);
  p00_L_124D();
  a = 0x02;
  mem_write8(0x8491, a);
  p00_L_1422();
  cpu_pop_bc();
  if (flag_c()) goto lab_p02_L_7396;
  b = (uint8_t)(b | (1u << 6));
  lab_p02_L_7396: ;
  a = b;
  p02_L_7397();
  return;
}

/* flash page 2 cpu 0x7250 (offset 0x3250) */
void p02_L_7250(void) {
  a = 0x01;
  goto lab_p02_L_725A;
  lab_p02_L_725A: ;
  /* bit 2,(iy) */
  if (flag_nz()) goto lab_p02_L_7262;
  a = a | 0x80;
  flag_logic(a);
  lab_p02_L_7262: ;
  mem_write8(0x8499, a);
  p00_L_0FB5();
  p00_L_129F();
  a = mem_read8(0x8479);
  a = (uint8_t)(a - 0x80);
  if (flag_c()) goto lab_p02_L_72E2;
  flag_cmp(a, 0x0C);
  if (flag_nc()) { p00_L_24C9(); return; }
  l = a;
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_728A;
  set_hl(0x1583);
  p00_L_11D3();
  b = 0x80;
  goto lab_p02_L_7296;
  lab_p02_L_728A: ;
  a = l;
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p02_L_72E2;
  a = 0x36;
  mem_write8(0x8490, a);
  b = 0x82;
  lab_p02_L_7296: ;
  c = 0x00;
  lab_p02_L_7298: ;
  p00_L_1470();
  if (flag_nc()) goto lab_p02_L_7298;
  c = (uint8_t)(c - 1);
  if (flag_p()) goto lab_p02_L_7298;
  p00_L_140C();
  set_hl(0x8479);
  a = b;
  cpu_cp_hl();
  if (flag_z()) goto lab_p02_L_72B2;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p00_L_12EF();
  c = a;
  goto lab_p02_L_7298;
  lab_p02_L_72B2: ;
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_72C6;
  p00_L_119E();
  set_hl(0x1590);
  p00_L_1461();
  if (flag_c()) goto lab_p02_L_72E2;
  goto lab_p02_L_72D4;
  lab_p02_L_72C6: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x18);
  if (flag_c()) goto lab_p02_L_72E2;
  if (flag_nz()) goto lab_p02_L_72D4;
  p00_L_151D();
  if (flag_z()) goto lab_p02_L_72E2;
  lab_p02_L_72D4: ;
  p00_L_1467();
  p00_L_11C3();
  a = mem_read8(0x8478);
  a = a ^ 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  lab_p02_L_72E2: ;
  p00_L_0F98();
  p00_L_15D6();
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_72EE;
  a = 0x03;
  lab_p02_L_72EE: ;
  cpu_push_af();
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_7383;
  p00_L_129F();
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_730F;
  set_hl(0x1598);
  p00_L_11D3();
  p00_L_163B();
  if (flag_c()) goto lab_p02_L_733F;
  c = 0x00;
  goto lab_p02_L_7324;
  lab_p02_L_730F: ;
  p00_L_1708();
  a = 0x90;
  mem_write8(0x8490, a);
  if (flag_c()) goto lab_p02_L_7373;
  c = 0x00;
  if (flag_z()) goto lab_p02_L_7324;
  p00_L_15EB();
  p00_L_12EF();
  c = a;
  lab_p02_L_7324: ;
  p00_L_1470();
  if (flag_nc()) goto lab_p02_L_7332;
  c = (uint8_t)(c - 1);
  if (flag_p()) goto lab_p02_L_7332;
  p00_L_140C();
  goto lab_p02_L_7338;
  lab_p02_L_7332: ;
  cpu_pop_af();
  a = a ^ 0x01;
  flag_logic(a);
  a = a | 0x08;
  flag_logic(a);
  cpu_push_af();
  lab_p02_L_7338: ;
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_7362;
  lab_p02_L_733F: ;
  p00_L_0F98();
  a = mem_read8(0x847A);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_7383;
  p00_L_170F();
  if (flag_c()) goto lab_p02_L_7383;
  if (flag_nz()) goto lab_p02_L_7369;
  p00_L_119E();
  set_hl(0x1597);
  p00_L_1461();
  if (flag_c()) goto lab_p02_L_7373;
  p00_L_12BE();
  p00_L_15F3();
  goto lab_p02_L_7369;
  lab_p02_L_7362: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x45);
  if (flag_c()) goto lab_p02_L_7373;
  lab_p02_L_7369: ;
  p00_L_1467();
  p00_L_11C3();
  cpu_pop_af();
  a = a ^ 0x08;
  flag_logic(a);
  cpu_push_af();
  lab_p02_L_7373: ;
  p00_L_0F98();
  p00_L_0FB5();
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_7383;
  p00_L_0CF2();
  lab_p02_L_7383: ;
  set_hl(0x8490);
  p00_L_124D();
  a = 0x02;
  mem_write8(0x8491, a);
  p00_L_1422();
  cpu_pop_bc();
  if (flag_c()) goto lab_p02_L_7396;
  b = (uint8_t)(b | (1u << 6));
  lab_p02_L_7396: ;
  a = b;
  p02_L_7397();
  return;
}

/* flash page 2 cpu 0x7254 (offset 0x3254) */
void p02_L_7254(void) {
  a = 0x02;
  goto lab_p02_L_725A;
  lab_p02_L_725A: ;
  /* bit 2,(iy) */
  if (flag_nz()) goto lab_p02_L_7262;
  a = a | 0x80;
  flag_logic(a);
  lab_p02_L_7262: ;
  mem_write8(0x8499, a);
  p00_L_0FB5();
  p00_L_129F();
  a = mem_read8(0x8479);
  a = (uint8_t)(a - 0x80);
  if (flag_c()) goto lab_p02_L_72E2;
  flag_cmp(a, 0x0C);
  if (flag_nc()) { p00_L_24C9(); return; }
  l = a;
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_728A;
  set_hl(0x1583);
  p00_L_11D3();
  b = 0x80;
  goto lab_p02_L_7296;
  lab_p02_L_728A: ;
  a = l;
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p02_L_72E2;
  a = 0x36;
  mem_write8(0x8490, a);
  b = 0x82;
  lab_p02_L_7296: ;
  c = 0x00;
  lab_p02_L_7298: ;
  p00_L_1470();
  if (flag_nc()) goto lab_p02_L_7298;
  c = (uint8_t)(c - 1);
  if (flag_p()) goto lab_p02_L_7298;
  p00_L_140C();
  set_hl(0x8479);
  a = b;
  cpu_cp_hl();
  if (flag_z()) goto lab_p02_L_72B2;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p00_L_12EF();
  c = a;
  goto lab_p02_L_7298;
  lab_p02_L_72B2: ;
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_72C6;
  p00_L_119E();
  set_hl(0x1590);
  p00_L_1461();
  if (flag_c()) goto lab_p02_L_72E2;
  goto lab_p02_L_72D4;
  lab_p02_L_72C6: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x18);
  if (flag_c()) goto lab_p02_L_72E2;
  if (flag_nz()) goto lab_p02_L_72D4;
  p00_L_151D();
  if (flag_z()) goto lab_p02_L_72E2;
  lab_p02_L_72D4: ;
  p00_L_1467();
  p00_L_11C3();
  a = mem_read8(0x8478);
  a = a ^ 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  lab_p02_L_72E2: ;
  p00_L_0F98();
  p00_L_15D6();
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_72EE;
  a = 0x03;
  lab_p02_L_72EE: ;
  cpu_push_af();
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_7383;
  p00_L_129F();
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_730F;
  set_hl(0x1598);
  p00_L_11D3();
  p00_L_163B();
  if (flag_c()) goto lab_p02_L_733F;
  c = 0x00;
  goto lab_p02_L_7324;
  lab_p02_L_730F: ;
  p00_L_1708();
  a = 0x90;
  mem_write8(0x8490, a);
  if (flag_c()) goto lab_p02_L_7373;
  c = 0x00;
  if (flag_z()) goto lab_p02_L_7324;
  p00_L_15EB();
  p00_L_12EF();
  c = a;
  lab_p02_L_7324: ;
  p00_L_1470();
  if (flag_nc()) goto lab_p02_L_7332;
  c = (uint8_t)(c - 1);
  if (flag_p()) goto lab_p02_L_7332;
  p00_L_140C();
  goto lab_p02_L_7338;
  lab_p02_L_7332: ;
  cpu_pop_af();
  a = a ^ 0x01;
  flag_logic(a);
  a = a | 0x08;
  flag_logic(a);
  cpu_push_af();
  lab_p02_L_7338: ;
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_7362;
  lab_p02_L_733F: ;
  p00_L_0F98();
  a = mem_read8(0x847A);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_7383;
  p00_L_170F();
  if (flag_c()) goto lab_p02_L_7383;
  if (flag_nz()) goto lab_p02_L_7369;
  p00_L_119E();
  set_hl(0x1597);
  p00_L_1461();
  if (flag_c()) goto lab_p02_L_7373;
  p00_L_12BE();
  p00_L_15F3();
  goto lab_p02_L_7369;
  lab_p02_L_7362: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x45);
  if (flag_c()) goto lab_p02_L_7373;
  lab_p02_L_7369: ;
  p00_L_1467();
  p00_L_11C3();
  cpu_pop_af();
  a = a ^ 0x08;
  flag_logic(a);
  cpu_push_af();
  lab_p02_L_7373: ;
  p00_L_0F98();
  p00_L_0FB5();
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_7383;
  p00_L_0CF2();
  lab_p02_L_7383: ;
  set_hl(0x8490);
  p00_L_124D();
  a = 0x02;
  mem_write8(0x8491, a);
  p00_L_1422();
  cpu_pop_bc();
  if (flag_c()) goto lab_p02_L_7396;
  b = (uint8_t)(b | (1u << 6));
  lab_p02_L_7396: ;
  a = b;
  p02_L_7397();
  return;
}

/* flash page 2 cpu 0x7258 (offset 0x3258) */
void p02_L_7258(void) {
  a = 0x04;
  /* bit 2,(iy) */
  if (flag_nz()) goto lab_p02_L_7262;
  a = a | 0x80;
  flag_logic(a);
  lab_p02_L_7262: ;
  mem_write8(0x8499, a);
  p00_L_0FB5();
  p00_L_129F();
  a = mem_read8(0x8479);
  a = (uint8_t)(a - 0x80);
  if (flag_c()) goto lab_p02_L_72E2;
  flag_cmp(a, 0x0C);
  if (flag_nc()) { p00_L_24C9(); return; }
  l = a;
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_728A;
  set_hl(0x1583);
  p00_L_11D3();
  b = 0x80;
  goto lab_p02_L_7296;
  lab_p02_L_728A: ;
  a = l;
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p02_L_72E2;
  a = 0x36;
  mem_write8(0x8490, a);
  b = 0x82;
  lab_p02_L_7296: ;
  c = 0x00;
  lab_p02_L_7298: ;
  p00_L_1470();
  if (flag_nc()) goto lab_p02_L_7298;
  c = (uint8_t)(c - 1);
  if (flag_p()) goto lab_p02_L_7298;
  p00_L_140C();
  set_hl(0x8479);
  a = b;
  cpu_cp_hl();
  if (flag_z()) goto lab_p02_L_72B2;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p00_L_12EF();
  c = a;
  goto lab_p02_L_7298;
  lab_p02_L_72B2: ;
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_72C6;
  p00_L_119E();
  set_hl(0x1590);
  p00_L_1461();
  if (flag_c()) goto lab_p02_L_72E2;
  goto lab_p02_L_72D4;
  lab_p02_L_72C6: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x18);
  if (flag_c()) goto lab_p02_L_72E2;
  if (flag_nz()) goto lab_p02_L_72D4;
  p00_L_151D();
  if (flag_z()) goto lab_p02_L_72E2;
  lab_p02_L_72D4: ;
  p00_L_1467();
  p00_L_11C3();
  a = mem_read8(0x8478);
  a = a ^ 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  lab_p02_L_72E2: ;
  p00_L_0F98();
  p00_L_15D6();
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_72EE;
  a = 0x03;
  lab_p02_L_72EE: ;
  cpu_push_af();
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_7383;
  p00_L_129F();
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_730F;
  set_hl(0x1598);
  p00_L_11D3();
  p00_L_163B();
  if (flag_c()) goto lab_p02_L_733F;
  c = 0x00;
  goto lab_p02_L_7324;
  lab_p02_L_730F: ;
  p00_L_1708();
  a = 0x90;
  mem_write8(0x8490, a);
  if (flag_c()) goto lab_p02_L_7373;
  c = 0x00;
  if (flag_z()) goto lab_p02_L_7324;
  p00_L_15EB();
  p00_L_12EF();
  c = a;
  lab_p02_L_7324: ;
  p00_L_1470();
  if (flag_nc()) goto lab_p02_L_7332;
  c = (uint8_t)(c - 1);
  if (flag_p()) goto lab_p02_L_7332;
  p00_L_140C();
  goto lab_p02_L_7338;
  lab_p02_L_7332: ;
  cpu_pop_af();
  a = a ^ 0x01;
  flag_logic(a);
  a = a | 0x08;
  flag_logic(a);
  cpu_push_af();
  lab_p02_L_7338: ;
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_7362;
  lab_p02_L_733F: ;
  p00_L_0F98();
  a = mem_read8(0x847A);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_7383;
  p00_L_170F();
  if (flag_c()) goto lab_p02_L_7383;
  if (flag_nz()) goto lab_p02_L_7369;
  p00_L_119E();
  set_hl(0x1597);
  p00_L_1461();
  if (flag_c()) goto lab_p02_L_7373;
  p00_L_12BE();
  p00_L_15F3();
  goto lab_p02_L_7369;
  lab_p02_L_7362: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x45);
  if (flag_c()) goto lab_p02_L_7373;
  lab_p02_L_7369: ;
  p00_L_1467();
  p00_L_11C3();
  cpu_pop_af();
  a = a ^ 0x08;
  flag_logic(a);
  cpu_push_af();
  lab_p02_L_7373: ;
  p00_L_0F98();
  p00_L_0FB5();
  a = mem_read8(0x8499);
  a = a & 0x80;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_7383;
  p00_L_0CF2();
  lab_p02_L_7383: ;
  set_hl(0x8490);
  p00_L_124D();
  a = 0x02;
  mem_write8(0x8491, a);
  p00_L_1422();
  cpu_pop_bc();
  if (flag_c()) goto lab_p02_L_7396;
  b = (uint8_t)(b | (1u << 6));
  lab_p02_L_7396: ;
  a = b;
  p02_L_7397();
  return;
}

/* flash page 2 cpu 0x7397 (offset 0x3397) */
void p02_L_7397(void) {
  mem_write8(0x84A4, a);
  p00_L_14C7();
  if (flag_nz()) goto lab_p02_L_73AB;
  lab_p02_L_739F: ;
  p00_L_1251();
  p00_L_0E2D();
  p00_L_14B0();
  p02_L_74FE();
  return;
  lab_p02_L_73AB: ;
  p02_L_75BB();
  if (flag_c()) goto lab_p02_L_739F;
  b = a;
  a = 0;
  flag_logic(a);
  lab_p02_L_73B2: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_af();
  set_de(0x8485);
  p02_L_722B();
  p00_L_132D();
  cpu_pop_af();
  b = 0x01;
  a = a & 0xF0;
  flag_logic(a);
  lab_p02_L_73C4: ;
  c = a;
  a = a | a;
  flag_logic(a);
  if (flag_m()) goto lab_p02_L_73D5;
  p02_L_73C9();
  return;
  lab_p02_L_73D3: ;
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  lab_p02_L_73D5: ;
  p00_L_13B5();
  if (flag_nc()) goto lab_p02_L_73D3;
  b = (uint8_t)(b + 1);
  a = c;
  a = a ^ 0x80;
  flag_logic(a);
  flag_set_z((b & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_73C4;
  c = a;
  a = (uint8_t)(a + 1);
  a = a & 0x0F;
  flag_logic(a);
  cpu_pop_hl();
  mem_write8(hl(), a);
  a = c;
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  flag_set_z((b & (1u << 3)) == 0);
  if (flag_z()) goto lab_p02_L_73B2;
  a = a | a;
  flag_logic(a);
  if (flag_m()) p00_L_13B5();
  a = mem_read8(0x84A5);
  b = a;
  p02_L_7220();
  set_hl(0x84A5);
  goto lab_p02_L_7402;
  lab_p02_L_7400: ;
  cpu_pop_bc();
  cpu_pop_hl();
  lab_p02_L_7402: ;
  flag_set_z((b & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p02_L_7438;
  b = (uint8_t)(b + 1);
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  cpu_push_bc();
  a = 0x0B;
  /* sub (hl) */
  /* srl a */
  if (flag_z()) goto lab_p02_L_7400;
  d = a;
  a = b;
  a = (uint8_t)(a + b);
  e = a;
  cpu_push_de();
  lab_p02_L_7416: ;
  p00_L_1332();
  p00_L_13EC();
  cpu_pop_de();
  d = (uint8_t)(d - 1);
  if (flag_z()) goto lab_p02_L_7400;
  a = e;
  cpu_push_de();
  flag_cmp(a, 0x09);
  if (flag_c()) goto lab_p02_L_7416;
  c = d;
  lab_p02_L_7427: ;
  p00_L_13FC();
  if (flag_nc()) goto lab_p02_L_7432;
  cpu_ex_de_hl();
  a = 0x01;
  p00_L_1375();
  lab_p02_L_7432: ;
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p02_L_7427;
  cpu_pop_de();
  goto lab_p02_L_7400;
  lab_p02_L_7438: ;
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 6)));
  p00_L_0D37();
  set_hl(0x84A4);
  a = mem_read8(hl());
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p02_L_7449;
  a = a | 0x10;
  flag_logic(a);
  lab_p02_L_7449: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  c = mem_read8(hl());
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = a & 0x40;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_7456;
  p00_L_15EB();
  goto lab_p02_L_745C;
  lab_p02_L_7456: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  cpu_ex_de_hl();
  p00_L_12CD();
  cpu_ex_de_hl();
  lab_p02_L_745C: ;
  p02_L_75C9();
  set_hl(0x84A5);
  p02_L_7462();
  return;
}

/* flash page 2 cpu 0x73C9 (offset 0x33C9) */
void p02_L_73C9(void) {
  goto lab_p02_L_73C9;
  lab_p02_L_73B2: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_af();
  set_de(0x8485);
  p02_L_722B();
  p00_L_132D();
  cpu_pop_af();
  b = 0x01;
  a = a & 0xF0;
  flag_logic(a);
  lab_p02_L_73C4: ;
  c = a;
  a = a | a;
  flag_logic(a);
  if (flag_m()) goto lab_p02_L_73D5;
  lab_p02_L_73C9: ;
  p00_L_142A();
  if (flag_c()) goto lab_p02_L_73DB;
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  goto lab_p02_L_73C9;
  lab_p02_L_73D3: ;
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  lab_p02_L_73D5: ;
  p00_L_13B5();
  if (flag_nc()) goto lab_p02_L_73D3;
  lab_p02_L_73DB: ;
  b = (uint8_t)(b + 1);
  a = c;
  a = a ^ 0x80;
  flag_logic(a);
  flag_set_z((b & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_73C4;
  c = a;
  a = (uint8_t)(a + 1);
  a = a & 0x0F;
  flag_logic(a);
  cpu_pop_hl();
  mem_write8(hl(), a);
  a = c;
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  flag_set_z((b & (1u << 3)) == 0);
  if (flag_z()) goto lab_p02_L_73B2;
  a = a | a;
  flag_logic(a);
  if (flag_m()) p00_L_13B5();
  a = mem_read8(0x84A5);
  b = a;
  p02_L_7220();
  set_hl(0x84A5);
  goto lab_p02_L_7402;
  lab_p02_L_7400: ;
  cpu_pop_bc();
  cpu_pop_hl();
  lab_p02_L_7402: ;
  flag_set_z((b & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p02_L_7438;
  b = (uint8_t)(b + 1);
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  cpu_push_bc();
  a = 0x0B;
  /* sub (hl) */
  /* srl a */
  if (flag_z()) goto lab_p02_L_7400;
  d = a;
  a = b;
  a = (uint8_t)(a + b);
  e = a;
  cpu_push_de();
  lab_p02_L_7416: ;
  p00_L_1332();
  p00_L_13EC();
  cpu_pop_de();
  d = (uint8_t)(d - 1);
  if (flag_z()) goto lab_p02_L_7400;
  a = e;
  cpu_push_de();
  flag_cmp(a, 0x09);
  if (flag_c()) goto lab_p02_L_7416;
  c = d;
  lab_p02_L_7427: ;
  p00_L_13FC();
  if (flag_nc()) goto lab_p02_L_7432;
  cpu_ex_de_hl();
  a = 0x01;
  p00_L_1375();
  lab_p02_L_7432: ;
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p02_L_7427;
  cpu_pop_de();
  goto lab_p02_L_7400;
  lab_p02_L_7438: ;
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 6)));
  p00_L_0D37();
  set_hl(0x84A4);
  a = mem_read8(hl());
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p02_L_7449;
  a = a | 0x10;
  flag_logic(a);
  lab_p02_L_7449: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  c = mem_read8(hl());
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = a & 0x40;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_7456;
  p00_L_15EB();
  goto lab_p02_L_745C;
  lab_p02_L_7456: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  cpu_ex_de_hl();
  p00_L_12CD();
  cpu_ex_de_hl();
  lab_p02_L_745C: ;
  p02_L_75C9();
  set_hl(0x84A5);
  p02_L_7462();
  return;
}

/* flash page 2 cpu 0x7462 (offset 0x3462) */
void p02_L_7462(void) {
  lab_p02_L_7462: ;
  c = (uint8_t)(c + 1);
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  cpu_push_hl();
  set_hl(0x8483);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x848E);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_z()) goto lab_p02_L_7481;
  a = mem_read8(0x84A4);
  a = a & 0x20;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_7483;
  b = (uint8_t)(b - 1);
  if (flag_p()) goto lab_p02_L_7483;
  cpu_pop_hl();
  p02_L_74E7();
  return;
  lab_p02_L_7481: ;
  b = (uint8_t)(b & ~(1u << 0));
  lab_p02_L_7483: ;
  cpu_push_bc();
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_74D2;
  a = mem_read8(0x848E);
  c = a;
  lab_p02_L_748C: ;
  cpu_push_bc();
  a = c;
  p00_L_119E();
  p00_L_1332();
  a = mem_read8(0x84A4);
  a = a & 0x20;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_74C1;
  p00_L_13B5();
  if (flag_nc()) goto lab_p02_L_74C4;
  p00_L_12CD();
  p00_L_15F3();
  set_hl(0x847A);
  a = 0x10;
  /* add a,(hl) */
  mem_write8(hl(), a);
  set_hl(0x84A5);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p00_L_131E();
  set_hl(0x8483);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  set_hl(0x848E);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  cpu_pop_bc();
  c = mem_read8(hl());
  goto lab_p02_L_74C8;
  lab_p02_L_74C1: ;
  p00_L_142A();
  lab_p02_L_74C4: ;
  p00_L_131E();
  cpu_pop_bc();
  lab_p02_L_74C8: ;
  a = mem_read8(0x84A4);
  a = a & 0x10;
  flag_logic(a);
  p00_L_13F1();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_748C;
  lab_p02_L_74D2: ;
  cpu_pop_bc();
  cpu_pop_hl();
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_nz()) { p02_L_74E7(); return; }
  a = mem_read8(hl());
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p02_L_7462;
  set_de(0x84A4);
  a = mem_read8(de());
  a = a ^ 0x30;
  flag_logic(a);
  mem_write8(de(), a);
  goto lab_p02_L_7462;
}

/* flash page 2 cpu 0x74E7 (offset 0x34E7) */
void p02_L_74E7(void) {
  p02_L_78CC();
  l = 0x7F;
  a = mem_read8(0x84A4);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_74F4;
  l = (uint8_t)(l + 1);
  lab_p02_L_74F4: ;
  a = l;
  mem_write8(0x8484, a);
  p00_L_14B0();
  p02_L_78D3();
  p02_L_74FE();
  return;
}

/* flash page 2 cpu 0x74FE (offset 0x34FE) */
void p02_L_74FE(void) {
  a = mem_read8(0x84A4);
  a = a & 0x08;
  flag_logic(a);
  if (flag_z()) p00_L_14B0();
  c = 0x00;
  a = mem_read8(0x84A4);
  a = a & 0x03;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_751C;
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p02_L_7517;
  c = 0x80;
  if (flag_nz()) goto lab_p02_L_751C;
  lab_p02_L_7517: ;
  a = 0x80;
  mem_write8(0x8483, a);
  lab_p02_L_751C: ;
  a = c;
  mem_write8(0x8478, a);
  a = mem_read8(0x8499);
  a = a & 0x07;
  flag_logic(a);
  flag_cmp(a, 0x02);
  if (flag_c()) return;
  if (flag_z()) { p00_L_1179(); return; }
  p00_L_14CC();
  if (flag_z()) { p00_L_24C9(); return; }
  p00_L_0ED0();
  return;
}

/* flash page 2 cpu 0x7534 (offset 0x3534) */
void p02_L_7534(void) {
  c = 0x81;
  goto lab_p02_L_7542;
  lab_p02_L_7542: ;
  p00_L_15D6();
  cpu_push_af();
  a = c;
  mem_write8(0x8499, a);
  p00_L_163B();
  if (flag_nc()) goto lab_p02_L_755E;
  a = 0x80;
  p02_L_7397();
  cpu_pop_af();
  set_hl(0x8499);
  flag_set_z((mem_read8(hl()) & (1u << 1)) == 0);
  if (flag_nz()) return;
  p02_L_78DB();
  return;
  lab_p02_L_755E: ;
  cpu_push_bc();
  flag_set_z((c & (1u << 2)) == 0);
  if (flag_z()) goto lab_p02_L_758E;
  p00_L_0C18();
  e = 0x82;
  p00_L_170A();
  if (flag_c()) goto lab_p02_L_7578;
  p00_L_1229();
  lab_p02_L_7570: ;
  cpu_pop_bc();
  lab_p02_L_7571: ;
  cpu_pop_af();
  flag_set_z((c & (1u << 1)) == 0);
  if (flag_nz()) return;
  p02_L_78DB();
  return;
  lab_p02_L_7578: ;
  p02_L_6F6A();
  p00_L_0C1B();
  p00_rst08();
  p00_L_1241();
  p00_L_0ED0();
  p00_rst08();
  p00_L_1229();
  p00_L_0C2D();
  goto lab_p02_L_7570;
  lab_p02_L_758E: ;
  p02_L_6F6A();
  p00_L_0ECC();
  p00_L_10DD();
  p00_L_1159();
  cpu_pop_bc();
  flag_set_z((c & (1u << 0)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_0E4C();
  p00_rst30();
  p00_L_0D16();
  cpu_pop_bc();
  flag_set_z((c & (1u << 7)) == 0);
  if (flag_z()) goto lab_p02_L_7571;
  cpu_push_bc();
  p00_L_14A2();
  p00_L_1108();
  p00_rst30();
  p00_L_0D16();
  p00_rst08();
  p00_L_1135();
  goto lab_p02_L_7570;
}

/* flash page 2 cpu 0x7538 (offset 0x3538) */
void p02_L_7538(void) {
  c = 0x04;
  goto lab_p02_L_7542;
  lab_p02_L_7542: ;
  p00_L_15D6();
  cpu_push_af();
  a = c;
  mem_write8(0x8499, a);
  p00_L_163B();
  if (flag_nc()) goto lab_p02_L_755E;
  a = 0x80;
  p02_L_7397();
  cpu_pop_af();
  set_hl(0x8499);
  flag_set_z((mem_read8(hl()) & (1u << 1)) == 0);
  if (flag_nz()) return;
  p02_L_78DB();
  return;
  lab_p02_L_755E: ;
  cpu_push_bc();
  flag_set_z((c & (1u << 2)) == 0);
  if (flag_z()) goto lab_p02_L_758E;
  p00_L_0C18();
  e = 0x82;
  p00_L_170A();
  if (flag_c()) goto lab_p02_L_7578;
  p00_L_1229();
  lab_p02_L_7570: ;
  cpu_pop_bc();
  lab_p02_L_7571: ;
  cpu_pop_af();
  flag_set_z((c & (1u << 1)) == 0);
  if (flag_nz()) return;
  p02_L_78DB();
  return;
  lab_p02_L_7578: ;
  p02_L_6F6A();
  p00_L_0C1B();
  p00_rst08();
  p00_L_1241();
  p00_L_0ED0();
  p00_rst08();
  p00_L_1229();
  p00_L_0C2D();
  goto lab_p02_L_7570;
  lab_p02_L_758E: ;
  p02_L_6F6A();
  p00_L_0ECC();
  p00_L_10DD();
  p00_L_1159();
  cpu_pop_bc();
  flag_set_z((c & (1u << 0)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_0E4C();
  p00_rst30();
  p00_L_0D16();
  cpu_pop_bc();
  flag_set_z((c & (1u << 7)) == 0);
  if (flag_z()) goto lab_p02_L_7571;
  cpu_push_bc();
  p00_L_14A2();
  p00_L_1108();
  p00_rst30();
  p00_L_0D16();
  p00_rst08();
  p00_L_1135();
  goto lab_p02_L_7570;
}

/* flash page 2 cpu 0x753C (offset 0x353C) */
void p02_L_753C(void) {
  c = 0x02;
  goto lab_p02_L_7542;
  lab_p02_L_7542: ;
  p00_L_15D6();
  cpu_push_af();
  a = c;
  mem_write8(0x8499, a);
  p00_L_163B();
  if (flag_nc()) goto lab_p02_L_755E;
  a = 0x80;
  p02_L_7397();
  cpu_pop_af();
  set_hl(0x8499);
  flag_set_z((mem_read8(hl()) & (1u << 1)) == 0);
  if (flag_nz()) return;
  p02_L_78DB();
  return;
  lab_p02_L_755E: ;
  cpu_push_bc();
  flag_set_z((c & (1u << 2)) == 0);
  if (flag_z()) goto lab_p02_L_758E;
  p00_L_0C18();
  e = 0x82;
  p00_L_170A();
  if (flag_c()) goto lab_p02_L_7578;
  p00_L_1229();
  lab_p02_L_7570: ;
  cpu_pop_bc();
  lab_p02_L_7571: ;
  cpu_pop_af();
  flag_set_z((c & (1u << 1)) == 0);
  if (flag_nz()) return;
  p02_L_78DB();
  return;
  lab_p02_L_7578: ;
  p02_L_6F6A();
  p00_L_0C1B();
  p00_rst08();
  p00_L_1241();
  p00_L_0ED0();
  p00_rst08();
  p00_L_1229();
  p00_L_0C2D();
  goto lab_p02_L_7570;
  lab_p02_L_758E: ;
  p02_L_6F6A();
  p00_L_0ECC();
  p00_L_10DD();
  p00_L_1159();
  cpu_pop_bc();
  flag_set_z((c & (1u << 0)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_0E4C();
  p00_rst30();
  p00_L_0D16();
  cpu_pop_bc();
  flag_set_z((c & (1u << 7)) == 0);
  if (flag_z()) goto lab_p02_L_7571;
  cpu_push_bc();
  p00_L_14A2();
  p00_L_1108();
  p00_rst30();
  p00_L_0D16();
  p00_rst08();
  p00_L_1135();
  goto lab_p02_L_7570;
}

/* flash page 2 cpu 0x7540 (offset 0x3540) */
void p02_L_7540(void) {
  c = 0x01;
  p00_L_15D6();
  cpu_push_af();
  a = c;
  mem_write8(0x8499, a);
  p00_L_163B();
  if (flag_nc()) goto lab_p02_L_755E;
  a = 0x80;
  p02_L_7397();
  cpu_pop_af();
  set_hl(0x8499);
  flag_set_z((mem_read8(hl()) & (1u << 1)) == 0);
  if (flag_nz()) return;
  p02_L_78DB();
  return;
  lab_p02_L_755E: ;
  cpu_push_bc();
  flag_set_z((c & (1u << 2)) == 0);
  if (flag_z()) goto lab_p02_L_758E;
  p00_L_0C18();
  e = 0x82;
  p00_L_170A();
  if (flag_c()) goto lab_p02_L_7578;
  p00_L_1229();
  lab_p02_L_7570: ;
  cpu_pop_bc();
  lab_p02_L_7571: ;
  cpu_pop_af();
  flag_set_z((c & (1u << 1)) == 0);
  if (flag_nz()) return;
  p02_L_78DB();
  return;
  lab_p02_L_7578: ;
  p02_L_6F6A();
  p00_L_0C1B();
  p00_rst08();
  p00_L_1241();
  p00_L_0ED0();
  p00_rst08();
  p00_L_1229();
  p00_L_0C2D();
  goto lab_p02_L_7570;
  lab_p02_L_758E: ;
  p02_L_6F6A();
  p00_L_0ECC();
  p00_L_10DD();
  p00_L_1159();
  cpu_pop_bc();
  flag_set_z((c & (1u << 0)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_0E4C();
  p00_rst30();
  p00_L_0D16();
  cpu_pop_bc();
  flag_set_z((c & (1u << 7)) == 0);
  if (flag_z()) goto lab_p02_L_7571;
  cpu_push_bc();
  p00_L_14A2();
  p00_L_1108();
  p00_rst30();
  p00_L_0D16();
  p00_rst08();
  p00_L_1135();
  goto lab_p02_L_7570;
}

/* flash page 2 cpu 0x75BB (offset 0x35BB) */
void p02_L_75BB(void) {
  a = mem_read8(0x8479);
  flag_cmp(a, 0x78);
  if (flag_c()) return;
  a = a ^ 0xFF;
  a = a & 0x7F;
  flag_logic(a);
  set_hl(0x84A5);
  mem_write8(hl(), a);
  return;
}

/* flash page 2 cpu 0x75C9 (offset 0x35C9) */
void p02_L_75C9(void) {
  a = mem_read8(0x84A5);
  d = a;
  a = (uint8_t)(a + c);
  mem_write8(0x8483, a);
  a = (uint8_t)(a - d);
  a = (uint8_t)(a - d);
  mem_write8(0x848E, a);
  return;
}

/* flash page 2 cpu 0x75CA (offset 0x35CA) */
void p02_L_75CA(void) {
  a = a & l;
  flag_logic(a);
  a = (uint8_t)(a + h);
  d = a;
  a = (uint8_t)(a + c);
  mem_write8(0x8483, a);
  a = (uint8_t)(a - d);
  a = (uint8_t)(a - d);
  mem_write8(0x848E, a);
  return;
}

/* flash page 2 cpu 0x75D7 (offset 0x35D7) */
void p02_L_75D7(void) {
  a = 0x01;
  b = 0x20;
  goto lab_p02_L_7609;
  lab_p02_L_7609: ;
  cpu_push_bc();
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p00_L_0FB5();
  e = 0x80;
  p00_L_170A();
  if (flag_c()) goto lab_p02_L_7623;
  if (flag_nz()) goto lab_p02_L_7620;
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_7623;
  p00_L_1518();
  lab_p02_L_7620: ;
  if (flag_nz()) { p00_L_24C9(); return; }
  lab_p02_L_7623: ;
  p00_L_1100();
  p00_L_10DD();
  p00_L_1251();
  p00_L_0C3D();
  p00_L_1171();
  p00_L_113F();
  p00_L_1251();
  p00_L_0C0A();
  p00_L_1108();
  p00_L_0CFA();
  p02_L_6D3D();
  a = 0;
  flag_logic(a);
  mem_write8(0x84A2, a);
  cpu_pop_af();
  if (flag_z()) goto lab_p02_L_7650;
  p00_L_10EF();
  goto lab_p02_L_7654;
  lab_p02_L_7650: ;
  p00_rst08();
  p00_L_1135();
  lab_p02_L_7654: ;
  d = a;
  goto lab_p02_L_765C;
  lab_p02_L_765C: ;
  p00_L_15CB();
  if (flag_z()) goto lab_p02_L_7665;
  a = d;
  a = (uint8_t)(a + 0x0C);
  d = a;
  lab_p02_L_7665: ;
  p00_L_15C6();
  if (flag_z()) goto lab_p02_L_766E;
  a = d;
  a = a ^ 0x04;
  flag_logic(a);
  d = a;
  lab_p02_L_766E: ;
  p00_L_14CC();
  if (flag_nz()) goto lab_p02_L_7684;
  p00_L_14C7();
  if (flag_nz()) goto lab_p02_L_767C;
  cpu_pop_bc();
  p00_L_128A();
  return;
  lab_p02_L_767C: ;
  d = (uint8_t)(d | (1u << 4));
  cpu_push_de();
  p00_L_14B0();
  goto lab_p02_L_769E;
  lab_p02_L_7684: ;
  cpu_push_de();
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_769E;
  p00_L_1100();
  p00_L_141D();
  a = mem_read8(0x8479);
  set_hl(0x8484);
  /* sbc a,(hl) */
  p00_L_113F();
  cpu_pop_de();
  if (flag_nc()) goto lab_p02_L_767C;
  cpu_push_de();
  lab_p02_L_769E: ;
  p00_L_1700();
  a = (uint8_t)(a + 0x80);
  if (flag_z()) goto lab_p02_L_76AB;
  if (flag_c()) goto lab_p02_L_76AD;
  flag_cmp(a, 0x80);
  if (flag_z()) goto lab_p02_L_76AD;
  lab_p02_L_76AB: ;
  a = 0x01;
  lab_p02_L_76AD: ;
  a = (uint8_t)(a - 1);
  mem_write8(0x8479, a);
  cpu_pop_af();
  cpu_pop_bc();
  a = (uint8_t)(a + b);
  p02_L_76B4();
  return;
}

/* flash page 2 cpu 0x75E2 (offset 0x35E2) */
void p02_L_75E2(void) {
  b = 0x20;
  cpu_push_bc();
  p02_L_7659();
  return;
}

/* flash page 2 cpu 0x75ED (offset 0x35ED) */
void p02_L_75ED(void) {
  p02_L_78E1();
  if (flag_c()) { p00_L_24C9(); return; }
  a = 0x01;
  goto lab_p02_L_7607;
  lab_p02_L_7607: ;
  b = 0x00;
  cpu_push_bc();
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p00_L_0FB5();
  e = 0x80;
  p00_L_170A();
  if (flag_c()) goto lab_p02_L_7623;
  if (flag_nz()) goto lab_p02_L_7620;
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_7623;
  p00_L_1518();
  lab_p02_L_7620: ;
  if (flag_nz()) { p00_L_24C9(); return; }
  lab_p02_L_7623: ;
  p00_L_1100();
  p00_L_10DD();
  p00_L_1251();
  p00_L_0C3D();
  p00_L_1171();
  p00_L_113F();
  p00_L_1251();
  p00_L_0C0A();
  p00_L_1108();
  p00_L_0CFA();
  p02_L_6D3D();
  a = 0;
  flag_logic(a);
  mem_write8(0x84A2, a);
  cpu_pop_af();
  if (flag_z()) goto lab_p02_L_7650;
  p00_L_10EF();
  goto lab_p02_L_7654;
  lab_p02_L_7650: ;
  p00_rst08();
  p00_L_1135();
  lab_p02_L_7654: ;
  d = a;
  goto lab_p02_L_765C;
  lab_p02_L_765C: ;
  p00_L_15CB();
  if (flag_z()) goto lab_p02_L_7665;
  a = d;
  a = (uint8_t)(a + 0x0C);
  d = a;
  lab_p02_L_7665: ;
  p00_L_15C6();
  if (flag_z()) goto lab_p02_L_766E;
  a = d;
  a = a ^ 0x04;
  flag_logic(a);
  d = a;
  lab_p02_L_766E: ;
  p00_L_14CC();
  if (flag_nz()) goto lab_p02_L_7684;
  p00_L_14C7();
  if (flag_nz()) goto lab_p02_L_767C;
  cpu_pop_bc();
  p00_L_128A();
  return;
  lab_p02_L_767C: ;
  d = (uint8_t)(d | (1u << 4));
  cpu_push_de();
  p00_L_14B0();
  goto lab_p02_L_769E;
  lab_p02_L_7684: ;
  cpu_push_de();
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_769E;
  p00_L_1100();
  p00_L_141D();
  a = mem_read8(0x8479);
  set_hl(0x8484);
  /* sbc a,(hl) */
  p00_L_113F();
  cpu_pop_de();
  if (flag_nc()) goto lab_p02_L_767C;
  cpu_push_de();
  lab_p02_L_769E: ;
  p00_L_1700();
  a = (uint8_t)(a + 0x80);
  if (flag_z()) goto lab_p02_L_76AB;
  if (flag_c()) goto lab_p02_L_76AD;
  flag_cmp(a, 0x80);
  if (flag_z()) goto lab_p02_L_76AD;
  lab_p02_L_76AB: ;
  a = 0x01;
  lab_p02_L_76AD: ;
  a = (uint8_t)(a - 1);
  mem_write8(0x8479, a);
  cpu_pop_af();
  cpu_pop_bc();
  a = (uint8_t)(a + b);
  p02_L_76B4();
  return;
}

/* flash page 2 cpu 0x75F7 (offset 0x35F7) */
void p02_L_75F7(void) {
  p00_L_1251();
  d = 0x02;
  p02_L_7657();
  return;
}

/* flash page 2 cpu 0x75FF (offset 0x35FF) */
void p02_L_75FF(void) {
  p02_L_78E1();
  if (flag_z()) return;
  if (flag_c()) { p00_L_24C9(); return; }
  a = 0;
  flag_logic(a);
  b = 0x00;
  cpu_push_bc();
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p00_L_0FB5();
  e = 0x80;
  p00_L_170A();
  if (flag_c()) goto lab_p02_L_7623;
  if (flag_nz()) goto lab_p02_L_7620;
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_7623;
  p00_L_1518();
  lab_p02_L_7620: ;
  if (flag_nz()) { p00_L_24C9(); return; }
  lab_p02_L_7623: ;
  p00_L_1100();
  p00_L_10DD();
  p00_L_1251();
  p00_L_0C3D();
  p00_L_1171();
  p00_L_113F();
  p00_L_1251();
  p00_L_0C0A();
  p00_L_1108();
  p00_L_0CFA();
  p02_L_6D3D();
  a = 0;
  flag_logic(a);
  mem_write8(0x84A2, a);
  cpu_pop_af();
  if (flag_z()) goto lab_p02_L_7650;
  p00_L_10EF();
  goto lab_p02_L_7654;
  lab_p02_L_7650: ;
  p00_rst08();
  p00_L_1135();
  lab_p02_L_7654: ;
  d = a;
  goto lab_p02_L_765C;
  lab_p02_L_765C: ;
  p00_L_15CB();
  if (flag_z()) goto lab_p02_L_7665;
  a = d;
  a = (uint8_t)(a + 0x0C);
  d = a;
  lab_p02_L_7665: ;
  p00_L_15C6();
  if (flag_z()) goto lab_p02_L_766E;
  a = d;
  a = a ^ 0x04;
  flag_logic(a);
  d = a;
  lab_p02_L_766E: ;
  p00_L_14CC();
  if (flag_nz()) goto lab_p02_L_7684;
  p00_L_14C7();
  if (flag_nz()) goto lab_p02_L_767C;
  cpu_pop_bc();
  p00_L_128A();
  return;
  lab_p02_L_767C: ;
  d = (uint8_t)(d | (1u << 4));
  cpu_push_de();
  p00_L_14B0();
  goto lab_p02_L_769E;
  lab_p02_L_7684: ;
  cpu_push_de();
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_769E;
  p00_L_1100();
  p00_L_141D();
  a = mem_read8(0x8479);
  set_hl(0x8484);
  /* sbc a,(hl) */
  p00_L_113F();
  cpu_pop_de();
  if (flag_nc()) goto lab_p02_L_767C;
  cpu_push_de();
  lab_p02_L_769E: ;
  p00_L_1700();
  a = (uint8_t)(a + 0x80);
  if (flag_z()) goto lab_p02_L_76AB;
  if (flag_c()) goto lab_p02_L_76AD;
  flag_cmp(a, 0x80);
  if (flag_z()) goto lab_p02_L_76AD;
  lab_p02_L_76AB: ;
  a = 0x01;
  lab_p02_L_76AD: ;
  a = (uint8_t)(a - 1);
  mem_write8(0x8479, a);
  cpu_pop_af();
  cpu_pop_bc();
  a = (uint8_t)(a + b);
  p02_L_76B4();
  return;
}

/* flash page 2 cpu 0x7657 (offset 0x3657) */
void p02_L_7657(void) {
  a = 0;
  flag_logic(a);
  cpu_push_af();
  p02_L_7659();
  return;
}

/* flash page 2 cpu 0x7659 (offset 0x3659) */
void p02_L_7659(void) {
  p00_L_0FB5();
  p00_L_15CB();
  if (flag_z()) goto lab_p02_L_7665;
  a = d;
  a = (uint8_t)(a + 0x0C);
  d = a;
  lab_p02_L_7665: ;
  p00_L_15C6();
  if (flag_z()) goto lab_p02_L_766E;
  a = d;
  a = a ^ 0x04;
  flag_logic(a);
  d = a;
  lab_p02_L_766E: ;
  p00_L_14CC();
  if (flag_nz()) goto lab_p02_L_7684;
  p00_L_14C7();
  if (flag_nz()) goto lab_p02_L_767C;
  cpu_pop_bc();
  p00_L_128A();
  return;
  lab_p02_L_767C: ;
  d = (uint8_t)(d | (1u << 4));
  cpu_push_de();
  p00_L_14B0();
  goto lab_p02_L_769E;
  lab_p02_L_7684: ;
  cpu_push_de();
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_769E;
  p00_L_1100();
  p00_L_141D();
  a = mem_read8(0x8479);
  set_hl(0x8484);
  /* sbc a,(hl) */
  p00_L_113F();
  cpu_pop_de();
  if (flag_nc()) goto lab_p02_L_767C;
  cpu_push_de();
  lab_p02_L_769E: ;
  p00_L_1700();
  a = (uint8_t)(a + 0x80);
  if (flag_z()) goto lab_p02_L_76AB;
  if (flag_c()) goto lab_p02_L_76AD;
  flag_cmp(a, 0x80);
  if (flag_z()) goto lab_p02_L_76AD;
  lab_p02_L_76AB: ;
  a = 0x01;
  lab_p02_L_76AD: ;
  a = (uint8_t)(a - 1);
  mem_write8(0x8479, a);
  cpu_pop_af();
  cpu_pop_bc();
  a = (uint8_t)(a + b);
  p02_L_76B4();
  return;
}

/* flash page 2 cpu 0x76B4 (offset 0x36B4) */
void p02_L_76B4(void) {
  cpu_push_af();
  a = 0x7F;
  mem_write8(0x8484, a);
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_76CA;
  p02_L_75BB();
  if (flag_nc()) goto lab_p02_L_76D2;
  p00_L_0ED0();
  p00_L_15D6();
  lab_p02_L_76CA: ;
  cpu_pop_af();
  mem_write8(0x84A4, a);
  b = a;
  p02_L_77DA();
  return;
  lab_p02_L_76D2: ;
  p00_L_1100();
  set_hl(0x848C);
  set_de(0x8497);
  p00_L_1430();
  cpu_pop_de();
  d = (uint8_t)(d | (1u << 6));
  set_hl(0x84A5);
  a = mem_read8(hl());
  if (flag_c()) goto lab_p02_L_76F6;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_76F3;
  cpu_push_de();
  a = 0x02;
  p00_L_152C();
  p02_L_77EB();
  return;
  lab_p02_L_76F3: ;
  a = (uint8_t)(a - 1);
  d = (uint8_t)(d & ~(1u << 6));
  lab_p02_L_76F6: ;
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), d);
  a = (uint8_t)(a + 1);
  c = a;
  cpu_push_bc();
  p02_L_75C9();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  b = 0x00;
  goto lab_p02_L_7707;
  lab_p02_L_7705: ;
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  lab_p02_L_7707: ;
  cpu_push_bc();
  p00_L_119E();
  a = mem_read8(0x848E);
  p00_L_1332();
  p00_L_142A();
  if (flag_c()) goto lab_p02_L_772A;
  p00_L_131E();
  p00_L_13EC();
  if (flag_nc()) goto lab_p02_L_7705;
  p00_L_12CD();
  set_hl(0x8485);
  p00_L_12F8();
  goto lab_p02_L_7705;
  lab_p02_L_772A: ;
  p00_L_11A6();
  cpu_pop_bc();
  cpu_pop_hl();
  mem_write8(hl(), b);
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p02_L_7743;
  c = (uint8_t)(c + 1);
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  set_hl(0x8483);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x848E);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  b = 0x00;
  goto lab_p02_L_7707;
  lab_p02_L_7743: ;
  p00_L_0F98();
  p00_L_1100();
  p00_L_1179();
  p00_L_0F98();
  p00_rst08();
  p00_L_113F();
  p00_L_0EC6();
  p00_L_15D6();
  set_hl(0x8485);
  p00_L_1260();
  set_hl(0x84A5);
  cpu_pop_bc();
  b = c;
  a = 0;
  flag_logic(a);
  mem_write8(0x848F, a);
  lab_p02_L_7768: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_779E;
  c = a;
  b = (uint8_t)(b - 1);
  p02_L_7228();
  a = mem_read8(0x84A4);
  a = a & 0x40;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_777B;
  b = (uint8_t)(b + 1);
  lab_p02_L_777B: ;
  cpu_push_bc();
  a = b;
  set_hl(0x84A5);
  /* sub (hl) */
  p00_L_1321();
  cpu_pop_bc();
  cpu_push_bc();
  lab_p02_L_7786: ;
  set_hl(0x8497);
  set_de(0x848C);
  p00_L_13BB();
  if (flag_c()) goto lab_p02_L_77A6;
  lab_p02_L_7791: ;
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p02_L_7786;
  cpu_pop_bc();
  a = mem_read8(0x84A4);
  a = a & 0x40;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_779E;
  b = (uint8_t)(b + 1);
  lab_p02_L_779E: ;
  cpu_pop_hl();
  flag_set_z((b & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p02_L_77AC;
  b = (uint8_t)(b + 1);
  goto lab_p02_L_7768;
  lab_p02_L_77A6: ;
  set_hl(0x848F);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p02_L_7791;
  lab_p02_L_77AC: ;
  a = 0x80;
  set_hl(0x84A5);
  /* sub (hl) */
  l = a;
  a = mem_read8(0x84A4);
  cpu_push_af();
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_z()) goto lab_p02_L_77BC;
  l = (uint8_t)(l - 1);
  lab_p02_L_77BC: ;
  a = l;
  mem_write8(0x8484, a);
  a = mem_read8(0x848F);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_77D0;
  set_hl(0x8484);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x8485);
  p00_L_12D1();
  lab_p02_L_77D0: ;
  p00_L_14B0();
  p00_L_0F98();
  p00_L_0C3D();
  cpu_pop_bc();
  p02_L_77DA();
  return;
}

/* flash page 2 cpu 0x77DA (offset 0x37DA) */
void p02_L_77DA(void) {
  flag_set_z((b & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p02_L_7813;
  flag_set_z((b & (1u << 4)) == 0);
  if (flag_z()) goto lab_p02_L_77EC;
  cpu_push_bc();
  a = 0x01;
  p00_L_1531();
  p00_L_0C0A();
  p02_L_77EB();
  return;
  lab_p02_L_77EC: ;
  cpu_push_bc();
  a = b;
  a = a & 0x0C;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_7800;
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p02_L_7804;
  cpu_push_bc();
  a = 0x04;
  p00_L_1531();
  p00_L_0C0A();
  cpu_pop_bc();
  lab_p02_L_7800: ;
  flag_set_z((b & (1u << 3)) == 0);
  if (flag_z()) goto lab_p02_L_7807;
  lab_p02_L_7804: ;
  p00_L_0E4C();
  lab_p02_L_7807: ;
  cpu_pop_af();
  a = a & 0x20;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_7813;
  /* bit 2,(iy) */
  if (flag_nz()) p00_L_0CF6();
  lab_p02_L_7813: ;
  p00_L_0E07();
  return;
}

/* flash page 2 cpu 0x77EB (offset 0x37EB) */
void p02_L_77EB(void) {
  cpu_pop_bc();
  cpu_push_bc();
  a = b;
  a = a & 0x0C;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_7800;
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p02_L_7804;
  cpu_push_bc();
  a = 0x04;
  p00_L_1531();
  p00_L_0C0A();
  cpu_pop_bc();
  lab_p02_L_7800: ;
  flag_set_z((b & (1u << 3)) == 0);
  if (flag_z()) goto lab_p02_L_7807;
  lab_p02_L_7804: ;
  p00_L_0E4C();
  lab_p02_L_7807: ;
  cpu_pop_af();
  a = a & 0x20;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_7813;
  /* bit 2,(iy) */
  if (flag_nz()) p00_L_0CF6();
  lab_p02_L_7813: ;
  p00_L_0E07();
  return;
}

/* flash page 2 cpu 0x7817 (offset 0x3817) */
void p02_L_7817(void) {
  p02_L_78E1();
  if (flag_z()) return;
  if (flag_c()) { p00_L_24C9(); return; }
  p00_L_170F();
  if (flag_c()) goto lab_p02_L_782C;
  if (flag_nz()) goto lab_p02_L_786F;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x70);
  if (flag_nc()) goto lab_p02_L_7846;
  lab_p02_L_782C: ;
  p00_L_1251();
  p00_L_15D6();
  a = a & 0x80;
  flag_logic(a);
  cpu_push_af();
  p02_L_7835();
  return;
  lab_p02_L_7846: ;
  p02_L_7852();
  p00_L_0ED0();
  p02_L_6E0B();
  p00_L_0D16();
  return;
  lab_p02_L_786F: ;
  p00_L_24C9();
  return;
}

/* flash page 2 cpu 0x7835 (offset 0x3835) */
void p02_L_7835(void) {
  a = a | 0x80;
  flag_logic(a);
  b = a;
  p00_L_15EB();
  p00_L_0FB5();
  p02_L_783E();
  return;
}

/* flash page 2 cpu 0x783E (offset 0x383E) */
void p02_L_783E(void) {
  a = b;
  p02_L_76B4();
  cpu_pop_af();
  p02_L_78DB();
  return;
}

/* flash page 2 cpu 0x7852 (offset 0x3852) */
void p02_L_7852(void) {
  p00_L_10DD();
  p00_L_0E4C();
  p00_L_0C1B();
  p00_L_14A2();
  p00_L_0C1B();
  p00_L_10EF();
  return;
}

/* flash page 2 cpu 0x7864 (offset 0x3864) */
void p02_L_7864(void) {
  p00_L_15D6();
  a = a & 0x80;
  flag_logic(a);
  cpu_push_af();
  a = mem_read8(0x8479);
  goto lab_p02_L_7885;
  lab_p02_L_7885: ;
  a = (uint8_t)(a - 0x90);
  if (flag_c()) goto lab_p02_L_7894;
  p00_rst08();
  goto lab_p02_L_78C4;
  lab_p02_L_788C: ;
  p00_L_0D1E();
  p00_L_0C1B();
  goto lab_p02_L_78AF;
  lab_p02_L_7894: ;
  p00_L_1171();
  cpu_pop_af();
  cpu_push_af();
  a = a & 0x01;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_788C;
  p00_L_0C1B();
  p00_L_1100();
  p00_L_113A();
  p00_L_0C2A();
  p00_L_10F8();
  p00_L_0D1F();
  lab_p02_L_78AF: ;
  p02_L_6D46();
  p00_L_1108();
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) p00_L_14B0();
  p00_L_163B();
  if (flag_nc()) goto lab_p02_L_78C4;
  p02_L_7835();
  return;
  lab_p02_L_78C4: ;
  p00_rst30();
  p02_L_6E0B();
  cpu_pop_af();
  p02_L_78DB();
  return;
}

/* flash page 2 cpu 0x7872 (offset 0x3872) */
void p02_L_7872(void) {
  p00_L_14C7();
  if (flag_z()) goto lab_p02_L_7882;
  p00_L_1873();
  a = 0x01;
  cpu_push_af();
  p00_L_163B();
  if (flag_nc()) goto lab_p02_L_7885;
  lab_p02_L_7882: ;
  p00_L_24C9();
  return;
  lab_p02_L_7885: ;
  a = (uint8_t)(a - 0x90);
  if (flag_c()) goto lab_p02_L_7894;
  p00_rst08();
  goto lab_p02_L_78C4;
  lab_p02_L_788C: ;
  p00_L_0D1E();
  p00_L_0C1B();
  goto lab_p02_L_78AF;
  lab_p02_L_7894: ;
  p00_L_1171();
  cpu_pop_af();
  cpu_push_af();
  a = a & 0x01;
  flag_logic(a);
  if (flag_z()) goto lab_p02_L_788C;
  p00_L_0C1B();
  p00_L_1100();
  p00_L_113A();
  p00_L_0C2A();
  p00_L_10F8();
  p00_L_0D1F();
  lab_p02_L_78AF: ;
  p02_L_6D46();
  p00_L_1108();
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) p00_L_14B0();
  p00_L_163B();
  if (flag_nc()) goto lab_p02_L_78C4;
  p02_L_7835();
  return;
  lab_p02_L_78C4: ;
  p00_rst30();
  p02_L_6E0B();
  cpu_pop_af();
  p02_L_78DB();
  return;
}

/* flash page 2 cpu 0x78CC (offset 0x38CC) */
void p02_L_78CC(void) {
  a = mem_read8(0x84A4);
  a = a | a;
  flag_logic(a);
  if (flag_m()) p00_L_15F3();
  p02_L_78D3();
  return;
}

/* flash page 2 cpu 0x78CD (offset 0x38CD) */
void p02_L_78CD(void) {
  a = a & h;
  flag_logic(a);
  a = (uint8_t)(a + h);
  a = a | a;
  flag_logic(a);
  if (flag_m()) p00_L_15F3();
  p02_L_78D3();
  return;
}

/* flash page 2 cpu 0x78D3 (offset 0x38D3) */
void p02_L_78D3(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x8478, a);
  p00_L_0E07();
  return;
}

/* flash page 2 cpu 0x78DB (offset 0x38DB) */
void p02_L_78DB(void) {
  a = a & 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  return;
}

/* flash page 2 cpu 0x78E1 (offset 0x38E1) */
void p02_L_78E1(void) {
  p00_L_14C7();
  if (flag_z()) return;
  p00_L_163B();
  if (flag_c()) goto lab_p02_L_78F3;
  flag_cmp(a, 0x80);
  if (flag_nz()) goto lab_p02_L_78F7;
  p00_L_1518();
  if (flag_nz()) goto lab_p02_L_78F7;
  lab_p02_L_78F3: ;
  a = 0x01;
  a = a | a;
  flag_logic(a);
  return;
  lab_p02_L_78F7: ;
  p00_L_1287();
  a = 0x01;
  flag_cmp(a, 0x02);
  return;
}

/* flash page 2 cpu 0x78FF (offset 0x38FF) */
void p02_L_78FF(void) {
  cpu_push_hl();
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  p00_L_2407();
  set_de(0x0009);
  p00_L_17B3();
  if (flag_z()) goto lab_p02_L_7915;
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p02_L_791A;
  lab_p02_L_7915: ;
  a = 0x06;
  /* add a,(hl) */
  a = (uint8_t)(a + 1);
  e = a;
  lab_p02_L_791A: ;
  cpu_pop_hl();
  return;
}

/* flash page 2 cpu 0x791C (offset 0x391C) */
void p02_L_791C(void) {
  mem_write16(0x83F1, hl());
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  cpu_push_hl();
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  p02_L_7925();
  return;
}

/* flash page 2 cpu 0x7925 (offset 0x3925) */
void p02_L_7925(void) {
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  d = mem_read8(hl());
  cpu_ex_de_hl();
  mem_write16(0x83F3, hl());
  p00_L_210A();
  mem_write16(0x83F7, de());
  set_hl(mem_read16(0x83F9));
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_de();
  p02_L_78FF();
  mem_write16(0x83F5, de());
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x83F9, hl());
  cpu_pop_hl();
  return;
}

/* flash page 2 cpu 0x794A (offset 0x394A) */
void p02_L_794A(void) {
  set_hl(0x788E);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  os_jp_hl();
  return;
}

/* flash page 2 cpu 0x79E4 (offset 0x39E4) */
void p02_L_79E4(void) {
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) | (1u << 6)));
  return;
}

/* flash page 2 cpu 0x7AD2 (offset 0x3AD2) */
void p02_L_7AD2(void) {
  cpu_push_af();
  cpu_push_bc();
  p00_rst18();
  cpu_pop_bc();
  set_hl(mem_read16(0x9824));
  a = mem_read8(0x9661);
  c = b;
  b = a;
  lab_p02_L_7ADE: ;
  cpu_push_bc();
  flag_set_z((c & (1u << 0)) == 0);
  cpu_push_af();
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  p00_rst20();
  p00_L_1653();
  mem_write8(0x8481, a);
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_af();
  if (flag_nz()) goto lab_p02_L_7AF9;
  p00_L_0013();
  if (flag_nz()) goto lab_p02_L_7AFC;
  lab_p02_L_7AF9: ;
  p00_L_1887();
  lab_p02_L_7AFC: ;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x80);
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_187F();
  b = 0x04;
  cpu_pop_af();
  if (flag_nz()) goto lab_p02_L_7B1C;
  b = 0x0A;
  p00_L_0013();
  if (flag_nz()) goto lab_p02_L_7B1C;
  b = 0x03;
  p00_L_019D();
  if (flag_nz()) goto lab_p02_L_7B1C;
  b = 0x07;
  lab_p02_L_7B1C: ;
  a = mem_read8(0x847A);
  p00_L_12B1();
  flag_cmp(a, b);
  if (flag_nc()) { p00_L_24C9(); return; }
  cpu_pop_hl();
  mem_write8(hl(), a);
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_7ADE;
  a = mem_read8(0x9661);
  b = a;
  lab_p02_L_7B2F: ;
  cpu_push_bc();
  flag_set_z((c & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_7B5E;
  p00_L_21A7();
  a = mem_read8(hl());
  set_hl(0x92C8);
  b = a;
  a = 0;
  flag_logic(a);
  lab_p02_L_7B3D: ;
  a = (uint8_t)(a + 0x11);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_7B3D;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  if (flag_c()) goto lab_p02_L_7B53;
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p02_L_7B91;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 0)));
  goto lab_p02_L_7B59;
  lab_p02_L_7B53: ;
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p02_L_7B91;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  lab_p02_L_7B59: ;
  p00_L_0087();
  goto lab_p02_L_7B91;
  lab_p02_L_7B5E: ;
  p00_L_21A7();
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_7B67;
  a = 0x0A;
  lab_p02_L_7B67: ;
  p00_L_385B();
  p00_rst10();
  cpu_ex_de_hl();
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  /* or (hl) */
  if (flag_z()) goto lab_p02_L_7B91;
  p00_L_01A2();
  if (flag_z()) goto lab_p02_L_7B89;
  cpu_push_de();
  p00_L_17E0();
  p00_rst10();
  cpu_ex_de_hl();
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  /* or (hl) */
  cpu_pop_hl();
  if (flag_z()) goto lab_p02_L_7B91;
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  p02_L_7B96();
  lab_p02_L_7B89: ;
  cpu_ex_de_hl();
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  p02_L_7B96();
  lab_p02_L_7B91: ;
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p02_L_7B2F;
  cpu_pop_af();
  return;
}

/* flash page 2 cpu 0x7B96 (offset 0x3B96) */
void p02_L_7B96(void) {
  if (flag_c()) goto lab_p02_L_7BAB;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_z()) return;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 5)));
  p00_L_019D();
  if (flag_nz()) goto lab_p02_L_7BC5;
  flag_set_z((mem_read8(hl()) & (1u << 3)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 1)));
  goto lab_p02_L_7BC5;
  lab_p02_L_7BAB: ;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_nz()) return;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  p00_L_019D();
  if (flag_nz()) goto lab_p02_L_7BC5;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p02_L_7BC5;
  a = mem_read8(hl());
  a = a & 0xE0;
  flag_logic(a);
  a = a | 0x0B;
  flag_logic(a);
  mem_write8(hl(), a);
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 0)));
  lab_p02_L_7BC5: ;
  p00_L_0091();
  return;
}

/* flash page 2 cpu 0x7BC8 (offset 0x3BC8) */
void p02_L_7BC8(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x07)) & (1u << 6)) == 0);
  if (flag_nz()) { p00_L_2501(); return; }
  p00_L_382B();
  p00_L_107E();
  if (flag_z()) goto lab_p02_L_7BE8;
  cpu_push_af();
  a = mem_read8(0x848E);
  a = a & 0x80;
  flag_logic(a);
  if (flag_nz()) goto lab_p02_L_7BE5;
  cpu_pop_af();
  if (flag_c()) goto lab_p02_L_7BE8;
  lab_p02_L_7BE2: ;
  p00_L_24CD();
  return;
  lab_p02_L_7BE5: ;
  cpu_pop_af();
  if (flag_c()) goto lab_p02_L_7BE2;
  lab_p02_L_7BE8: ;
  p00_L_39E1();
  set_hl(0x0000);
  p00_L_1C40();
  p00_L_21D6();
  p00_L_16B5();
  p00_L_28F1();
  p00_L_38D9();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 6)));
  set_hl(0x7CA3);
  p00_L_25A2();
  p00_L_1287();
  p00_L_21E0();
  p00_L_38DF();
  p00_L_28E5();
  p02_L_7C13();
  return;
}

/* flash page 2 cpu 0x7C13 (offset 0x3C13) */
void p02_L_7C13(void) {
  goto lab_p02_L_7C13;
  lab_p02_L_7BE2: ;
  p00_L_24CD();
  return;
  lab_p02_L_7C13: ;
  p00_rst08();
  p00_L_28F1();
  p00_rst10();
  set_hl(0x8483);
  p00_L_1183();
  p00_L_2910();
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p00_L_39E7();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  p00_L_1717();
  p00_L_16B5();
  p00_L_1653();
  p00_L_15FB();
  p00_L_1169();
  p00_L_2902();
  p00_rst10();
  a = 0x01;
  p00_L_38EB();
  p02_L_4785();
  cpu_ex_de_hl();
  set_hl(0x84AF);
  p00_L_1183();
  p00_L_28E5();
  p00_L_28B0();
  p00_L_15C6();
  cpu_push_af();
  p00_rst30();
  p00_L_28E0();
  p00_L_29D7();
  p00_L_107E();
  if (flag_z()) goto lab_p02_L_7BE2;
  p00_L_28E5();
  p00_L_28C3();
  p00_L_107E();
  if (flag_z()) goto lab_p02_L_7C9C;
  if (flag_c()) goto lab_p02_L_7C77;
  cpu_pop_af();
  if (flag_z()) goto lab_p02_L_7C7A;
  goto lab_p02_L_7C9D;
  lab_p02_L_7C77: ;
  cpu_pop_af();
  if (flag_z()) goto lab_p02_L_7C9D;
  lab_p02_L_7C7A: ;
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 6)));
  p00_L_28F1();
  p00_L_3975();
  p00_L_289D();
  p00_L_39ED();
  p00_L_2910();
  p00_L_16BC();
  p00_L_2902();
  set_de(0x003F);
  p00_L_21B6();
  return;
  lab_p02_L_7C9C: ;
  cpu_pop_af();
  lab_p02_L_7C9D: ;
  p00_L_28E5();
  goto lab_p02_L_7C13;
}


/* Recovered from flash page 25 (mechanical ASM->C) */
/* cpu window 0x4000..0x7FFF prefix=p25_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p25_L_4000(void);
void p25_L_4011(void);
void p25_L_403D(void);
void p25_L_4074(void);
void p25_L_4077(void);
void p25_L_40C1(void);
void p25_L_40CD(void);
void p25_L_40D5(void);
void p25_L_40E3(void);
void p25_L_4100(void);
void p25_L_410B(void);
void p25_L_4114(void);
void p25_L_4126(void);
void p25_L_4139(void);
void p25_L_4184(void);
void p25_L_418D(void);
void p25_L_419B(void);
void p25_L_41A0(void);
void p25_L_42B3(void);
void p25_L_42E0(void);
void p25_L_42FE(void);
void p25_L_4339(void);
void p25_L_437E(void);
void p25_L_43E0(void);
void p25_L_43E7(void);
void p25_L_43EC(void);
void p25_L_43FA(void);
void p25_L_43FE(void);
void p25_str_5(void);
void p25_str_6(void);
void p25_str_7(void);
void p25_str_1(void);
void p25_str_2(void);
void p25_str_3(void);
void p25_str_4(void);
void p25_L_4487(void);
void p25_L_448E(void);
void p25_L_44C6(void);
void p25_L_4516(void);
void p25_L_452E(void);
void p25_L_45BC(void);
void p25_L_45CD(void);
void p25_L_4605(void);
void p25_L_4676(void);
void p25_L_4679(void);
void p25_L_468B(void);
void p25_L_46B2(void);
void p25_L_46C9(void);
void p25_L_4721(void);
void p25_L_472C(void);
void p25_L_47DD(void);
void p25_L_4911(void);
void p25_L_4956(void);
void p25_L_4984(void);
void p25_L_4990(void);
void p25_L_4A8C(void);
void p25_L_4C1B(void);
void p25_L_4C96(void);
void p25_L_4CB3(void);
void p25_L_4CB9(void);
void p25_L_4CC6(void);
void p25_L_4CC9(void);
void p25_L_4D08(void);
void p25_L_4D0B(void);
void p25_L_4D75(void);
void p25_L_4D82(void);
void p25_L_4D96(void);
void p25_L_4DA9(void);
void p25_L_4DAF(void);
void p25_L_4DB6(void);
void p25_L_4DBD(void);
void p25_L_4DC3(void);
void p25_L_4DCA(void);
void p25_L_4DE3(void);
void p25_L_4DF9(void);
void p25_L_4E08(void);
void p25_L_4E11(void);
void p25_L_4E27(void);
void p25_L_4E34(void);
void p25_L_4E5B(void);
void p25_L_4E86(void);
void p25_L_4E92(void);
void p25_L_4E9B(void);
void p25_L_4EB6(void);
void p25_L_4ED5(void);
void p25_L_4EDD(void);
void p25_L_4EE3(void);
void p25_L_4EE9(void);
void p25_L_4EF3(void);
void p25_L_4EFB(void);
void p25_L_4EFF(void);
void p25_L_4F07(void);
void p25_L_4F0B(void);
void p25_L_4F0F(void);
void p25_L_4F2C(void);
void p25_L_4F43(void);
void p25_L_4F5E(void);
void p25_L_4F6F(void);
void p25_L_4FB3(void);
void p25_L_5004(void);
void p25_L_5053(void);
void p25_L_5055(void);
void p25_L_5067(void);
void p25_L_5069(void);
void p25_L_5087(void);
void p25_L_50C6(void);
void p25_L_50E5(void);
void p25_L_51CD(void);
void p25_L_51D6(void);
void p25_L_51FC(void);
void p25_L_5216(void);
void p25_L_5229(void);
void p25_L_5237(void);
void p25_L_5257(void);
void p25_L_5273(void);
void p25_L_5284(void);
void p25_L_52B8(void);
void p25_L_52F0(void);
void p25_L_5384(void);
void p25_L_5399(void);
void p25_L_53B5(void);
void p25_L_53D9(void);
void p25_L_53E3(void);
void p25_L_545D(void);
void p25_L_54DF(void);
void p25_L_5509(void);
void p25_L_55EE(void);
void p25_L_55FD(void);
void p25_L_562F(void);
void p25_L_5660(void);
void p25_L_566C(void);
void p25_L_5695(void);
void p25_L_572C(void);
void p25_L_57D8(void);
void p25_L_581C(void);
void p25_L_5830(void);
void p25_L_5852(void);
void p25_L_585B(void);
void p25_L_5890(void);
void p25_L_58A3(void);
void p25_L_58AA(void);
void p25_L_58B7(void);
void p25_L_5930(void);
void p25_L_59CD(void);
void p25_L_5A3B(void);
void p25_L_5B44(void);
void p25_L_5B96(void);
void p25_L_5BB3(void);
void p25_L_5BCE(void);
void p25_L_5BD1(void);
void p25_L_5BD3(void);
void p25_L_5BE3(void);
void p25_L_5BFC(void);
void p25_L_5C15(void);
void p25_L_5C21(void);
void p25_L_5C2E(void);
void p25_L_5C42(void);
void p25_L_5CCD(void);
void p25_L_5CD1(void);
void p25_L_5D0D(void);
void p25_L_5D19(void);
void p25_L_5D61(void);
void p25_L_5D6A(void);
void p25_L_5D73(void);
void p25_L_5D87(void);
void p25_L_5D8B(void);
void p25_L_5D96(void);
void p25_L_5D98(void);
void p25_L_5D9B(void);
void p25_L_5DB4(void);
void p25_L_5DCD(void);
void p25_L_5DD2(void);
void p25_L_5DD8(void);
void p25_L_5DDE(void);
void p25_L_5DE9(void);
void p25_L_5DF7(void);
void p25_L_5E4C(void);
void p25_L_5E77(void);
void p25_L_5E80(void);
void p25_L_5E8D(void);
void p25_L_5E94(void);
void p25_L_5E9C(void);
void p25_L_5EA1(void);
void p25_L_5EA8(void);
void p25_L_5EB0(void);
void p25_L_5EB5(void);
void p25_L_5EBD(void);
void p25_L_5EC5(void);
void p25_L_5ED2(void);
void p25_L_5EE0(void);
void p25_L_5EED(void);
void p25_L_5EFB(void);
void p25_L_5F23(void);
void p25_L_5F2C(void);
void p25_L_5F56(void);
void p25_L_5FB3(void);
void p25_L_5FBF(void);
void p25_L_60B2(void);
void p25_L_60BA(void);
void p25_L_60C2(void);
void p25_L_60CA(void);
void p25_L_60F9(void);
void p25_L_611A(void);
void p25_L_613B(void);
void p25_L_6156(void);
void p25_L_65FF(void);
void p25_L_6784(void);
void p25_L_6853(void);
void p25_L_6858(void);
void p25_L_687A(void);
void p25_L_688D(void);
void p25_L_68A8(void);
void p25_L_68CF(void);
void p25_L_68DD(void);
void p25_L_6913(void);
void p25_L_6925(void);
void p25_L_693A(void);
void p25_L_6940(void);
void p25_L_6951(void);
void p25_L_6966(void);
void p25_L_697A(void);
void p25_L_6985(void);
void p25_L_698E(void);
void p25_L_69A4(void);
void p25_L_69A9(void);
void p25_L_69AE(void);
void p25_L_69B1(void);
void p25_L_69C0(void);
void p25_L_69C8(void);
void p25_L_69EE(void);
void p25_L_6B33(void);
void p25_L_6BCA(void);
void p25_L_6C4B(void);
void p25_L_6C74(void);
void p25_L_6D33(void);
void p25_L_6D4E(void);
void p25_L_6DCC(void);
void p25_str_8(void);
void p25_L_6DE9(void);
void p25_L_6E19(void);
void p25_L_6E29(void);
void p25_L_6E2D(void);
void p25_L_6E60(void);
void p25_L_6ECD(void);
void p25_L_6F6E(void);
void p25_L_6F78(void);
void p25_L_70D3(void);
void p25_L_70DC(void);
void p25_L_71AB(void);
void p25_L_71B3(void);
void p25_L_71CD(void);
void p25_L_71D9(void);
void p25_L_7217(void);
void p25_L_723B(void);
void p25_L_7274(void);
void p25_L_7282(void);
void p25_L_7288(void);
void p25_L_728E(void);
void p25_L_7313(void);
void p25_L_7372(void);
void p25_L_737E(void);
void p25_L_73AE(void);
void p25_L_73C7(void);
void p25_L_73F9(void);
void p25_L_7468(void);
void p25_L_749B(void);
void p25_L_74A4(void);
void p25_L_74A8(void);
void p25_L_74BC(void);
void p25_L_74D5(void);
void p25_L_74E5(void);
void p25_L_74EB(void);
void p25_L_74FB(void);
void p25_L_7543(void);
void p25_L_75DE(void);
void p25_L_760A(void);
void p25_L_7703(void);
void p25_L_771B(void);
void p25_L_7726(void);
void p25_L_772C(void);
void p25_L_775B(void);
void p25_L_7765(void);
void p25_L_77CD(void);
void p25_L_7862(void);
void p25_L_7921(void);
void p25_L_79C0(void);
void p25_L_7AD2(void);
void p25_L_7AE4(void);
void p25_L_7AFD(void);
void p25_L_7B72(void);
void p25_L_7B7F(void);
void p25_L_7BC7(void);
void p25_L_7BD6(void);
void p25_L_7BD9(void);
void p25_L_7BF5(void);
void p25_L_7C09(void);
void p25_L_7C1A(void);
void p25_L_7CF8(void);
void p25_L_7D38(void);

/* flash page 25 cpu 0x4000 (offset 0x0000) */
void p25_L_4000(void) {
  set_de(0x9640);
  p25_L_4074();
  set_de(0x9640);
  p00_L_11FD();
  set_hl(0x40F3);
  set_de(0x9649);
  p25_L_4077();
  set_de(0x9649);
  p00_L_11FD();
  set_hl(0x9640);
  p00_L_11F8();
  p00_L_0C13();
  p00_L_1251();
  p00_L_107E();
  if (flag_nc()) goto lab_p25_L_4037;
  set_hl(0x40EA);
  p00_L_11F8();
  set_hl(0x8489);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p00_rst30();
  lab_p25_L_4037: ;
  set_hl(0x410B);
  p00_L_0D19();
  return;
}

/* flash page 25 cpu 0x4011 (offset 0x0011) */
void p25_L_4011(void) {
  /* sub (hl) */
  p25_L_4077();
  set_de(0x9649);
  p00_L_11FD();
  set_hl(0x9640);
  p00_L_11F8();
  p00_L_0C13();
  p00_L_1251();
  p00_L_107E();
  if (flag_nc()) goto lab_p25_L_4037;
  set_hl(0x40EA);
  p00_L_11F8();
  set_hl(0x8489);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p00_rst30();
  lab_p25_L_4037: ;
  set_hl(0x410B);
  p00_L_0D19();
  return;
}

/* flash page 25 cpu 0x403D (offset 0x003D) */
void p25_L_403D(void) {
  p00_L_1037();
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_L_1169();
  set_hl(0x8479);
  a = 0x88;
  cpu_cp_hl();
  if (flag_nc()) goto lab_p25_L_404F;
  mem_write8(hl(), a);
  lab_p25_L_404F: ;
  p00_L_15D6();
  p00_L_0C0F();
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_406E;
  set_de(0x9649);
  p00_L_11FD();
  set_de(0x9649);
  p25_L_4074();
  set_de(0x9640);
  p00_L_11FD();
  goto lab_p25_L_4071;
  lab_p25_L_406E: ;
  p25_L_40C1();
  lab_p25_L_4071: ;
  p00_L_1130();
  return;
}

/* flash page 25 cpu 0x4074 (offset 0x0074) */
void p25_L_4074(void) {
  set_hl(0x40DB);
  p25_L_4077();
  return;
}

/* flash page 25 cpu 0x4077 (offset 0x0077) */
void p25_L_4077(void) {
  cpu_push_de();
  p25_L_40CD();
  cpu_pop_hl();
  cpu_push_de();
  cpu_push_hl();
  p00_rst20();
  p00_L_0ED0();
  p00_L_1159();
  p00_L_0C0F();
  p00_L_10DD();
  p00_L_1108();
  p00_L_0D1F();
  cpu_pop_hl();
  p00_L_11F8();
  p00_L_0C13();
  cpu_pop_hl();
  p25_L_40CD();
  cpu_push_de();
  p00_L_0D1F();
  p00_L_1171();
  p00_L_1135();
  cpu_pop_hl();
  p25_L_40CD();
  cpu_push_de();
  p00_L_0D1F();
  p00_L_1108();
  p00_L_0C13();
  cpu_pop_hl();
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_40BE;
  p00_L_15CB();
  if (flag_z()) return;
  lab_p25_L_40BE: ;
  p00_L_0BEC();
  return;
}

/* flash page 25 cpu 0x40C1 (offset 0x00C1) */
void p25_L_40C1(void) {
  set_hl(0x4114);
  set_de(0x9640);
  set_bc(0x0012);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 25 cpu 0x40CD (offset 0x00CD) */
void p25_L_40CD(void) {
  set_de(0x8483);
  set_bc(0x0005);
  while (bc() != 0) { cpu_ldi(); }
  p25_L_40D5();
  return;
}

/* flash page 25 cpu 0x40D5 (offset 0x00D5) */
void p25_L_40D5(void) {
  cpu_ex_de_hl();
  b = 0x04;
  p00_L_12AA();
  return;
}

/* flash page 25 cpu 0x40E3 (offset 0x00E3) */
void p25_L_40E3(void) {
  set_bc(0x0040);
  a = (uint8_t)(a + h);
  mem_write8(de(), a);
  set_hl(0x0010);
  /* adc a,c */
  set_hl(0x4847);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  h = e;
  /* nop */
  /* nop */
  /* nop */
  a = (uint8_t)(a + h);
  d = d;
  mem_write8(hl(), a);
  b = b;
  /* nop */
  a = (uint8_t)(a + h);
  b = b;
  l = c;
  if (flag_nz()) goto lab_p25_L_40FE;
  lab_p25_L_40FE: ;
  a = (uint8_t)(a + e);
  /* scf */
  p25_L_4100();
  return;
}

/* flash page 25 cpu 0x4100 (offset 0x0100) */
void p25_L_4100(void) {
  a = (uint8_t)(a - c);
  /* nop */
  /* nop */
  /* adc a,c */
  set_hl(0x4847);
  sp = (uint16_t)(sp + 1);
  /* sbc a,c */
  /* nop */
  /* nop */
  p25_L_410B();
  return;
}

/* flash page 25 cpu 0x410B (offset 0x010B) */
void p25_L_410B(void) {
  /* nop */
  halt();
  b = mem_read8(hl());
  d = mem_read8(hl());
  h = c;
  if (flag_nc()) goto lab_p25_L_416B;
  d = l;
  d = b;
  p25_L_4114();
  return;
  lab_p25_L_416B: ;
  /* jp 0xCD0F - other page/RAM */
}

/* flash page 25 cpu 0x4114 (offset 0x0114) */
void p25_L_4114(void) {
  /* nop */
  a = (uint8_t)(a + h);
  mem_write8(de(), a);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  d = b;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  a = (uint8_t)(a + h);
  h = a;
  /* adc a,c */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p25_L_4126();
  return;
}

/* flash page 25 cpu 0x4126 (offset 0x0126) */
void p25_L_4126(void) {
  set_hl(mem_read16(0x9826));
  mem_write16(0x9828, hl());
  set_hl(mem_read16(0x9822));
  mem_write16(0x9824, hl());
  set_hl(mem_read16(0x85BC));
  mem_write16(0x86DE, hl());
  return;
}

/* flash page 25 cpu 0x4139 (offset 0x0139) */
void p25_L_4139(void) {
  p00_L_3E37();
  p00_L_1207();
  p00_L_15CB();
  if (flag_nz()) goto lab_p25_L_416A;
  p00_L_14C7();
  if (flag_z()) { p00_L_1229(); return; }
  p00_L_1100();
  lab_p25_L_414D: ;
  p00_L_0C2A();
  p00_L_14C7();
  if (flag_z()) { p00_L_113F(); return; }
  p00_L_15CB();
  if (flag_nz()) goto lab_p25_L_416A;
  p00_rst08();
  p00_L_113F();
  p00_L_0D1F();
  p00_L_1100();
  p00_L_1179();
  goto lab_p25_L_414D;
  lab_p25_L_416A: ;
  set_hl(0x0FC3);
  p00_L_11F8();
  p00_L_0E5C();
  p00_L_107E();
  if (flag_nz()) { p00_L_24C9(); return; }
  set_hl(0x4184);
  p00_rst20();
  p00_L_10F8();
  p00_L_0D1F();
  return;
}

/* flash page 25 cpu 0x4184 (offset 0x0184) */
void p25_L_4184(void) {
  /* nop */
  a = (uint8_t)(a + b);
  cpu_rla();
  mem_write8(hl(), d);
  b = l;
  if (flag_c()) goto lab_p25_L_41DB;
  a = (uint8_t)(a - b);
  d = mem_read8(hl());
  p25_L_418D();
  return;
  lab_p25_L_41DB: ;
  b = (uint8_t)(b - 1);
  set_bc((uint16_t)(bc() + 1));
  if (flag_c()) goto lab_p25_L_41EA;
  if (flag_z()) goto lab_p25_L_41EA;
  flag_cmp(a, 0x0F);
  if (flag_nz()) goto lab_p25_L_41EA;
  p00_L_3EE5();
  goto lab_p25_L_41F1;
  lab_p25_L_41EA: ;
  a = 0;
  flag_logic(a);
  p00_L_3EE5();
  p00_L_2D45();
  lab_p25_L_41F1: ;
  p25_L_44C6();
  a = 0;
  flag_logic(a);
  mem_write8(0x92CA, a);
  mem_write8(0x92DB, a);
  mem_write8(0x92EC, a);
  a = (uint8_t)(a + 1);
  mem_write8(0x92CF, a);
  mem_write8(0x92E0, a);
  mem_write8(0x92F1, a);
  a = 0x31;
  mem_write8(0x92D4, a);
  mem_write8(0x92E5, a);
  mem_write8(0x92F6, a);
  p25_L_418D();
  p00_L_128A();
  p00_L_39D5();
  b = 0x0A;
  lab_p25_L_421E: ;
  cpu_push_bc();
  a = b;
  p25_L_69A4();
  p00_L_1C9D();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x07);
  if (flag_nc()) goto lab_p25_L_4242;
  p25_L_698E();
  p00_L_1C9D();
  cpu_pop_af();
  cpu_push_af();
  p25_L_6985();
  p00_L_1C9D();
  cpu_pop_af();
  cpu_push_af();
  p25_L_69A9();
  p00_L_1C9D();
  lab_p25_L_4242: ;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x04);
  if (flag_nc()) goto lab_p25_L_424E;
  p25_L_69C0();
  p00_L_1C9D();
  lab_p25_L_424E: ;
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_421E;
  set_hl(0x9320);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  set_hl(0x932B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  a = 0x01;
  mem_write8(0x91D9, a);
  p00_L_128A();
  p00_L_3339();
  set_de(0x92B3);
  p00_L_11FD();
  a = 0x10;
  mem_write8(0x847A, a);
  p00_L_11FD();
  set_de(0x9082);
  p00_L_11FD();
  p00_L_11FD();
  set_hl(0x8DA9);
  mem_write16(0x8DA7, hl());
  p00_L_33CF();
  p00_L_2D63();
  p00_L_346B();
  p25_L_40C1();
  lab_p25_L_428F: ;
  a = hw_in(PORT_INTACK);
  a = a & 0x08;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_428F;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  a = 0x0B;
  hw_out(PORT_INTMASK, a);
  p00_L_3EEB();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 2)));
  /* ei */
  set_hl(0x0800);
  mem_write16(0x97A5, hl());
  p00_L_3E8B();
  return;
}

/* flash page 25 cpu 0x418D (offset 0x018D) */
void p25_L_418D(void) {
  a = 0x00;
  b = 0x16;
  set_hl(0x9776);
  p25_L_419B();
  a = 0x06;
  b = 0x03;
  p25_L_419B();
  return;
}

/* flash page 25 cpu 0x419B (offset 0x019B) */
void p25_L_419B(void) {
  lab_p25_L_419B: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_419B;
  return;
}

/* flash page 25 cpu 0x41A0 (offset 0x01A0) */
void p25_L_41A0(void) {
  p00_L_0BB1();
  p00_L_24A9();
  if (flag_z()) goto lab_p25_L_41B7;
  b = 0x00;
  os_bcall(0x80BA);
  flag_set_z((b & (1u << 0)) == 0);
  a = 0x1F;
  if (flag_z()) goto lab_p25_L_41B9;
  a = 0x1C;
  goto lab_p25_L_41B9;
  lab_p25_L_41B7: ;
  a = 0x17;
  lab_p25_L_41B9: ;
  mem_write8(0x8447, a);
  p00_L_3EEB();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 3)));
  p00_L_02AD();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x0A), (uint8_t)(mem_read8((uint16_t)(iy + 0x0A)) | (1u << 5)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  a = 0xFF;
  mem_write8(0x97B0, a);
  p25_L_42B3();
  p00_L_0305();
  if (flag_c()) goto lab_p25_L_41EA;
  if (flag_z()) goto lab_p25_L_41EA;
  flag_cmp(a, 0x0F);
  if (flag_nz()) goto lab_p25_L_41EA;
  p00_L_3EE5();
  goto lab_p25_L_41F1;
  lab_p25_L_41EA: ;
  a = 0;
  flag_logic(a);
  p00_L_3EE5();
  p00_L_2D45();
  lab_p25_L_41F1: ;
  p25_L_44C6();
  a = 0;
  flag_logic(a);
  mem_write8(0x92CA, a);
  mem_write8(0x92DB, a);
  mem_write8(0x92EC, a);
  a = (uint8_t)(a + 1);
  mem_write8(0x92CF, a);
  mem_write8(0x92E0, a);
  mem_write8(0x92F1, a);
  a = 0x31;
  mem_write8(0x92D4, a);
  mem_write8(0x92E5, a);
  mem_write8(0x92F6, a);
  p25_L_418D();
  p00_L_128A();
  p00_L_39D5();
  b = 0x0A;
  lab_p25_L_421E: ;
  cpu_push_bc();
  a = b;
  p25_L_69A4();
  p00_L_1C9D();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x07);
  if (flag_nc()) goto lab_p25_L_4242;
  p25_L_698E();
  p00_L_1C9D();
  cpu_pop_af();
  cpu_push_af();
  p25_L_6985();
  p00_L_1C9D();
  cpu_pop_af();
  cpu_push_af();
  p25_L_69A9();
  p00_L_1C9D();
  lab_p25_L_4242: ;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x04);
  if (flag_nc()) goto lab_p25_L_424E;
  p25_L_69C0();
  p00_L_1C9D();
  lab_p25_L_424E: ;
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_421E;
  set_hl(0x9320);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  set_hl(0x932B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  a = 0x01;
  mem_write8(0x91D9, a);
  p00_L_128A();
  p00_L_3339();
  set_de(0x92B3);
  p00_L_11FD();
  a = 0x10;
  mem_write8(0x847A, a);
  p00_L_11FD();
  set_de(0x9082);
  p00_L_11FD();
  p00_L_11FD();
  set_hl(0x8DA9);
  mem_write16(0x8DA7, hl());
  p00_L_33CF();
  p00_L_2D63();
  p00_L_346B();
  p25_L_40C1();
  lab_p25_L_428F: ;
  a = hw_in(PORT_INTACK);
  a = a & 0x08;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_428F;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  a = 0x0B;
  hw_out(PORT_INTMASK, a);
  p00_L_3EEB();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 2)));
  /* ei */
  set_hl(0x0800);
  mem_write16(0x97A5, hl());
  p00_L_3E8B();
  return;
}

/* flash page 25 cpu 0x42B3 (offset 0x02B3) */
void p25_L_42B3(void) {
  set_hl(0x9D95);
  mem_write16(0x9820, hl());
  mem_write16(0x9822, hl());
  mem_write16(0x9824, hl());
  mem_write16(0x9832, hl());
  set_hl(0xFE66);
  mem_write16(0x982E, hl());
  mem_write16(0x9826, hl());
  mem_write16(0x9828, hl());
  mem_write16(0x9830, hl());
  set_hl(0x8DA3);
  mem_write8(hl(), 0x40);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x60);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x5F);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x5E);
  return;
}

/* flash page 25 cpu 0x42E0 (offset 0x02E0) */
void p25_L_42E0(void) {
  p00_L_0B76();
  p00_L_3E8B();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 3)));
  p00_L_02AD();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x0A), (uint8_t)(mem_read8((uint16_t)(iy + 0x0A)) | (1u << 5)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  return;
}

/* flash page 25 cpu 0x42FE (offset 0x02FE) */
void p25_L_42FE(void) {
  a = 0x76;
  hw_out(PORT_INTACK, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  cpu_pop_hl();
  cpu_pop_hl();
  mem_write16(0x8A38, sp);
  p00_lcd_busy_wait();
  a = 0x02;
  lcd_write_cmd(); /* ti_lcd_command(a) */
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 0)));
  set_hl(0xA55A);
  mem_write16(0x85BE, hl());
  a = 0x01;
  hw_out(PORT_INTMASK, a);
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) & ~(1u << 7)));
  a = 0x36;
  hw_out(PORT_INTACK, a);
  a = 0;
  flag_logic(a);
  mmu_set_bank_b(a);
  /* ei */
  lab_p25_L_4336: ;
  halt();
  goto lab_p25_L_4336;
}

/* flash page 25 cpu 0x4339 (offset 0x0339) */
void p25_L_4339(void) {
  p00_L_3CFF();
  p00_L_3D2F();
  p00_L_3CD5();
  p00_L_3CD5();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4359;
  a = 0x40;
  p00_L_3C45();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  if (flag_z()) return;
  lab_p25_L_4359: ;
  set_hl(0x443C);
  p25_L_43FE();
  p00_L_3CD5();
  set_hl(0x444B);
  p25_L_43FE();
  p00_L_3CD5();
  set_hl(0x4473);
  p25_L_43FE();
  p00_L_3CD5();
  set_hl(0x447D);
  p25_L_43FE();
  p00_L_3CD5();
  return;
}

/* flash page 25 cpu 0x437E (offset 0x037E) */
void p25_L_437E(void) {
  p00_L_1916();
  if (flag_nz()) goto lab_p25_L_438C;
  p00_L_3D17();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 3)));
  goto lab_p25_L_4392;
  lab_p25_L_438C: ;
  p00_L_31B3();
  p00_L_3D29();
  lab_p25_L_4392: ;
  p00_L_36B7();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 5)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_43AA;
  a = 0x41;
  p00_L_3C45();
  if (flag_z()) goto lab_p25_L_43D3;
  lab_p25_L_43AA: ;
  set_hl(0x443C);
  set_de(0x0001);
  p25_L_43FA();
  set_de(0x0002);
  p25_L_43FA();
  set_de(0x0004);
  p25_L_43FA();
  set_de(0x0005);
  p25_L_43FA();
  set_de(0x0006);
  mem_write16(0x844B, de());
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  p25_L_43FE();
  lab_p25_L_43D3: ;
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  p00_L_3D2F();
  p00_L_3F0F();
  p00_L_0A26();
  return;
}

/* flash page 25 cpu 0x43E0 (offset 0x03E0) */
void p25_L_43E0(void) {
  set_hl(0x4417);
  a = 0x42;
  p25_L_43EC();
  return;
}

/* flash page 25 cpu 0x43E7 (offset 0x03E7) */
void p25_L_43E7(void) {
  set_hl(0x4423);
  a = 0x43;
  p25_L_43EC();
  return;
}

/* flash page 25 cpu 0x43EC (offset 0x03EC) */
void p25_L_43EC(void) {
  goto lab_p25_L_43EC;
  lab_p25_L_43C8: ;
  mem_write16(0x844B, de());
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  p25_L_43FE();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  p00_L_3D2F();
  p00_L_3F0F();
  p00_L_0A26();
  return;
  lab_p25_L_43EC: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  if (flag_nz()) goto lab_p25_L_43C8;
  set_de(0x0205);
  goto lab_p25_L_43C8;
}

/* flash page 25 cpu 0x43FA (offset 0x03FA) */
void p25_L_43FA(void) {
  mem_write16(0x844B, de());
  p25_L_43FE();
  return;
}

/* flash page 25 cpu 0x43FE (offset 0x03FE) */
void p25_L_43FE(void) {
  cpu_push_bc();
  cpu_push_af();
  a = mem_read8(0x97A6);
  b = a;
  lab_p25_L_4404: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  /* scf */
  if (flag_z()) goto lab_p25_L_4413;
  p00_L_3F9F();
  a = mem_read8(0x844B);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p25_L_4404;
  lab_p25_L_4413: ;
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  return;
}

/* flash page 25 cpu 0x4417 (offset 0x0417) */
void p25_str_5(void) {
  c = l;
  h = l;
  l = l;
  if (flag_nz()) goto lab_p25_L_447F;
  l = h;
  h = l;
  h = c;
  mem_write8(hl(), d);
  h = l;
  h = h;
  /* nop */
  p25_str_6();
  return;
  lab_p25_L_447F: ;
  mem_write8(hl(), c);
  mem_write8(hl(), l);
  l = c;
  mem_write8(hl(), d);
  h = l;
  h = h;
  l = 0x00;
  p25_L_4487();
  return;
}

/* flash page 25 cpu 0x4423 (offset 0x0423) */
void p25_str_6(void) {
  d = d;
  b = c;
  c = l;
  if (flag_nz()) goto lab_p25_L_448B;
  l = h;
  h = l;
  h = c;
  mem_write8(hl(), d);
  h = l;
  h = h;
  /* nop */
  p25_str_7();
  return;
  lab_p25_L_448B: ;
  flag_cmp(a, 0x52);
  if (flag_z()) return;
  p25_L_448E();
  return;
}

/* flash page 25 cpu 0x442F (offset 0x042F) */
void p25_str_7(void) {
  b = h;
  h = l;
  h = mem_read8(hl());
  h = c;
  mem_write8(hl(), l);
  l = h;
  mem_write8(hl(), h);
  mem_write8(hl(), e);
  if (flag_nz()) goto lab_p25_L_44AC;
  h = l;
  mem_write8(hl(), h);
  /* nop */
  p25_str_1();
  return;
  lab_p25_L_44AC: ;
  if (flag_nz()) goto lab_p25_L_44B4;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) | (1u << 3)));
  goto lab_p25_L_44C4;
  lab_p25_L_44B4: ;
  flag_cmp(a, 0x4A);
  if (flag_nz()) goto lab_p25_L_44BC;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) | (1u << 4)));
  lab_p25_L_44BC: ;
  flag_cmp(a, 0x49);
  if (flag_nz()) goto lab_p25_L_44C4;
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) | (1u << 0)));
  lab_p25_L_44C4: ;
  a = b;
  return;
}

/* flash page 25 cpu 0x443C (offset 0x043C) */
void p25_str_1(void) {
  e = c;
  l = a;
  mem_write8(hl(), l);
  mem_write8(hl(), d);
  if (flag_nz()) goto lab_p25_L_44A4;
  h = c;
  mem_write8(hl(), h);
  mem_write8(hl(), h);
  h = l;
  mem_write8(hl(), d);
  l = c;
  h = l;
  mem_write8(hl(), e);
  /* nop */
  p25_str_2();
  return;
  lab_p25_L_44A4: ;
  flag_cmp(a, 0x44);
  if (flag_z()) return;
  p25_L_448E();
  flag_cmp(a, 0x43);
  if (flag_nz()) goto lab_p25_L_44B4;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) | (1u << 3)));
  goto lab_p25_L_44C4;
  lab_p25_L_44B4: ;
  flag_cmp(a, 0x4A);
  if (flag_nz()) goto lab_p25_L_44BC;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) | (1u << 4)));
  lab_p25_L_44BC: ;
  flag_cmp(a, 0x49);
  if (flag_nz()) goto lab_p25_L_44C4;
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) | (1u << 0)));
  lab_p25_L_44C4: ;
  a = b;
  return;
}

/* flash page 25 cpu 0x444B (offset 0x044B) */
void p25_str_2(void) {
  h = c;
  mem_write8(hl(), d);
  h = l;
  if (flag_nz()) goto lab_p25_L_44BC;
  l = a;
  mem_write8(hl(), a);
  l = 0x00;
  d = d;
  h = l;
  h = e;
  l = a;
  l = l;
  l = l;
  h = l;
  l = mem_read8(hl());
  h = h;
  /* nop */
  h = e;
  l = b;
  h = c;
  l = mem_read8(hl());
  h = a;
  h = l;
  if (flag_nz()) goto lab_p25_L_44D5;
  h = mem_read8(hl());
  /* nop */
  h = d;
  h = c;
  mem_write8(hl(), h);
  mem_write8(hl(), h);
  h = l;
  mem_write8(hl(), d);
  l = c;
  h = l;
  mem_write8(hl(), e);
  l = 0x00;
  p25_str_3();
  return;
  lab_p25_L_44BC: ;
  flag_cmp(a, 0x49);
  if (flag_nz()) goto lab_p25_L_44C4;
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) | (1u << 0)));
  lab_p25_L_44C4: ;
  a = b;
  return;
  lab_p25_L_44D5: ;
  set_de(0x9711);
  lab_p25_L_44D8: ;
  set_hl(0x8478);
  flag_cmp(a, 0x06);
  if (flag_nc()) goto lab_p25_L_44E6;
  mem_write8(hl(), a);
  p00_L_118B();
  a = (uint8_t)(a + 1);
  goto lab_p25_L_44D8;
  lab_p25_L_44E6: ;
  cpu_ex_de_hl();
  mem_write8(hl(), 0x71);
  p00_L_1295();
  a = 0x5D;
  mem_write8(0x8479, a);
  lab_p25_L_44F1: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x06);
  if (flag_nc()) return;
  p00_L_2222();
  p00_rst10();
  if (flag_c()) goto lab_p25_L_4507;
  p00_L_1F55();
  if (flag_z()) goto lab_p25_L_450D;
  p00_L_321F();
  goto lab_p25_L_450D;
  lab_p25_L_4507: ;
  set_hl(0x0000);
  if (flag_c()) p00_L_1C46();
  lab_p25_L_450D: ;
  p00_L_2176();
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p25_L_44F1;
}

/* flash page 25 cpu 0x4473 (offset 0x0473) */
void p25_str_3(void) {
  h = e;
  l = b;
  h = c;
  l = mem_read8(hl());
  h = a;
  h = l;
  if (flag_nz()) goto lab_p25_L_44E4;
  mem_write8(hl(), e);
  /* nop */
  p25_str_4();
  return;
  lab_p25_L_44D8: ;
  set_hl(0x8478);
  flag_cmp(a, 0x06);
  if (flag_nc()) goto lab_p25_L_44E6;
  mem_write8(hl(), a);
  p00_L_118B();
  a = (uint8_t)(a + 1);
  lab_p25_L_44E4: ;
  goto lab_p25_L_44D8;
  lab_p25_L_44E6: ;
  cpu_ex_de_hl();
  mem_write8(hl(), 0x71);
  p00_L_1295();
  a = 0x5D;
  mem_write8(0x8479, a);
  lab_p25_L_44F1: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x06);
  if (flag_nc()) return;
  p00_L_2222();
  p00_rst10();
  if (flag_c()) goto lab_p25_L_4507;
  p00_L_1F55();
  if (flag_z()) goto lab_p25_L_450D;
  p00_L_321F();
  goto lab_p25_L_450D;
  lab_p25_L_4507: ;
  set_hl(0x0000);
  if (flag_c()) p00_L_1C46();
  lab_p25_L_450D: ;
  p00_L_2176();
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p25_L_44F1;
}

/* flash page 25 cpu 0x447D (offset 0x047D) */
void p25_str_4(void) {
  mem_write8(hl(), d);
  h = l;
  mem_write8(hl(), c);
  mem_write8(hl(), l);
  l = c;
  mem_write8(hl(), d);
  h = l;
  h = h;
  l = 0x00;
  p25_L_4487();
  return;
}

/* flash page 25 cpu 0x4487 (offset 0x0487) */
void p25_L_4487(void) {
  flag_cmp(a, 0x44);
  if (flag_z()) goto lab_p25_L_449B;
  flag_cmp(a, 0x52);
  if (flag_z()) return;
  p25_L_448E();
  return;
  lab_p25_L_449B: ;
  p00_L_17CE();
  if (flag_z()) { p25_L_448E(); return; }
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x44);
  if (flag_z()) return;
  p25_L_448E();
  flag_cmp(a, 0x43);
  if (flag_nz()) goto lab_p25_L_44B4;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) | (1u << 3)));
  goto lab_p25_L_44C4;
  lab_p25_L_44B4: ;
  flag_cmp(a, 0x4A);
  if (flag_nz()) goto lab_p25_L_44BC;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) | (1u << 4)));
  lab_p25_L_44BC: ;
  flag_cmp(a, 0x49);
  if (flag_nz()) goto lab_p25_L_44C4;
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) | (1u << 0)));
  lab_p25_L_44C4: ;
  a = b;
  return;
}

/* flash page 25 cpu 0x448E (offset 0x048E) */
void p25_L_448E(void) {
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 0)));
  return;
}

/* flash page 25 cpu 0x44C6 (offset 0x04C6) */
void p25_L_44C6(void) {
  a = 0x07;
  mem_write8(0x970E, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x970F, a);
  mem_write8(0x9710, a);
  p00_L_1295();
  set_de(0x9711);
  lab_p25_L_44D8: ;
  set_hl(0x8478);
  flag_cmp(a, 0x06);
  if (flag_nc()) goto lab_p25_L_44E6;
  mem_write8(hl(), a);
  p00_L_118B();
  a = (uint8_t)(a + 1);
  goto lab_p25_L_44D8;
  lab_p25_L_44E6: ;
  cpu_ex_de_hl();
  mem_write8(hl(), 0x71);
  p00_L_1295();
  a = 0x5D;
  mem_write8(0x8479, a);
  lab_p25_L_44F1: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x06);
  if (flag_nc()) return;
  p00_L_2222();
  p00_rst10();
  if (flag_c()) goto lab_p25_L_4507;
  p00_L_1F55();
  if (flag_z()) goto lab_p25_L_450D;
  p00_L_321F();
  goto lab_p25_L_450D;
  lab_p25_L_4507: ;
  set_hl(0x0000);
  if (flag_c()) p00_L_1C46();
  lab_p25_L_450D: ;
  p00_L_2176();
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p25_L_44F1;
}

/* flash page 25 cpu 0x4516 (offset 0x0516) */
void p25_L_4516(void) {
  p25_L_40C1();
  p00_L_0A59();
  mem_write8((uint16_t)(iy + 0x0A), (uint8_t)(mem_read8((uint16_t)(iy + 0x0A)) | (1u << 5)));
  p25_L_42E0();
  p00_L_3EC1();
  set_hl(0x442F);
  a = 0x44;
  p25_L_43EC();
  return;
}

/* flash page 25 cpu 0x452E (offset 0x052E) */
void p25_L_452E(void) {
  a = mem_read8(0x8446);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p25_L_45A7;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p25_L_45E5;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p25_L_45F3;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p25_L_458C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) { p00_L_09CA(); return; }
  set_hl(mem_read16(0x9B73));
  cpu_push_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 6)) == 0);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 0)) == 0);
  cpu_push_af();
  /* di */
  set_hl(0x8000);
  set_de(0x8001);
  set_bc(0x1BC3);
  mem_write8(hl(), 0x00);
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_af();
  if (flag_z()) goto lab_p25_L_456D;
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) | (1u << 0)));
  lab_p25_L_456D: ;
  cpu_pop_af();
  if (flag_z()) goto lab_p25_L_4574;
  mem_write8((uint16_t)(iy + 0x34), (uint8_t)(mem_read8((uint16_t)(iy + 0x34)) | (1u << 6)));
  lab_p25_L_4574: ;
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) | (1u << 1)));
  cpu_pop_hl();
  mem_write16(0x9B73, hl());
  set_hl(0x9BD0);
  set_de(0x9BD1);
  set_bc(0x642F);
  mem_write8(hl(), 0x00);
  while (bc() != 0) { cpu_ldi(); }
  p00_L_09DE();
  return;
  lab_p25_L_458C: ;
  p00_L_0AFB();
  if (flag_z()) p00_L_2E89();
  p00_L_3D0B();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  set_hl(0x2817);
  p00_L_3C87();
  p00_L_2D33();
  p00_L_09F8();
  return;
  lab_p25_L_45A7: ;
  p00_L_0AFB();
  if (flag_z()) p00_L_2E89();
  p00_L_2D39();
  set_hl(0x27A6);
  a = 0x55;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p25_L_45BC();
  return;
  lab_p25_L_45E5: ;
  p00_L_0AFB();
  if (flag_z()) p00_L_2E89();
  p00_L_2D3F();
  set_hl(0x27B7);
  p25_L_45BC();
  return;
  lab_p25_L_45F3: ;
  p00_L_0AFB();
  if (flag_z()) p00_L_2E89();
  p00_L_2D3F();
  p00_L_2D39();
  set_hl(0x27C6);
  p25_L_45BC();
  return;
}

/* flash page 25 cpu 0x45BC (offset 0x05BC) */
void p25_L_45BC(void) {
  cpu_push_hl();
  p00_L_2D63();
  p00_L_0A59();
  p00_L_3E8B();
  p00_L_3EC1();
  cpu_pop_hl();
  set_de(0x0005);
  p25_L_45CD();
  return;
}

/* flash page 25 cpu 0x45CD (offset 0x05CD) */
void p25_L_45CD(void) {
  mem_write16(0x844B, de());
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  p00_L_3C87();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  p00_L_3D2F();
  p00_L_3F0F();
  p00_L_0A26();
  return;
}

/* flash page 25 cpu 0x4605 (offset 0x0605) */
void p25_L_4605(void) {
  p00_L_0BB1();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 5)));
  a = 0;
  flag_logic(a);
  mem_write8(0x9C87, a);
  cpu_push16(iy);
  iy = 0x89F0;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 0)));
  a = 0x20;
  mem_write8((uint16_t)(iy + 0x0A), a);
  a = 0xFF;
  mem_write8(0x97B0, a);
  /* res 2,(iy) */
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 1)));
  a = mem_read8((uint16_t)(iy + 0x04));
  a = a & 0x80;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x04), a);
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 0)));
  iy = cpu_pop16();
  a = 0x10;
  b = 0x04;
  lab_p25_L_4652: ;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x02), a);
  a = 0x04;
  p00_L_351F();
  cpu_pop_af();
  /* sla a */
  if (flag_nc()) goto lab_p25_L_4652;
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 4)));
  b = 0x00;
  p00_L_2DA5();
  p25_L_418D();
  p00_L_33CF();
  p00_L_339F();
  p00_L_2D63();
  p25_L_4516();
  return;
}

/* flash page 25 cpu 0x4676 (offset 0x0676) */
void p25_L_4676(void) {
  d = 0x45;
  return;
}

/* flash page 25 cpu 0x4679 (offset 0x0679) */
void p25_L_4679(void) {
  p00_L_38F1();
  p00_L_1169();
  set_hl(0x8F50);
  p00_rst20();
  set_hl(0x8F59);
  p00_L_11F8();
  goto lab_p25_L_46A6;
  lab_p25_L_46A6: ;
  p25_L_4E86();
  p00_L_39E1();
  p25_L_4D75();
  cpu_push_hl();
  goto lab_p25_L_46DA;
  lab_p25_L_46DA: ;
  p00_L_2A17();
  p00_L_2A03();
  p00_L_107E();
  a = 0x91;
  if (flag_nc()) { p25_L_4C1B(); return; }
  cpu_pop_af();
  mem_write8(0x848E, a);
  set_hl(0x4E7A);
  p00_L_25A2();
  a = mem_read8(0x848E);
  cpu_push_af();
  p00_L_2970();
  p00_L_38D9();
  p00_L_2970();
  p00_L_16F4();
  mem_write16(0x9306, de());
  p00_L_1130();
  p00_L_1037();
  if (flag_z()) goto lab_p25_L_4735;
  p00_rst10();
  cpu_ex_de_hl();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 3));
  cpu_push_af();
  p25_L_4D82();
  p00_L_29DB();
  p00_L_29F7();
  p00_L_107E();
  cpu_push_af();
  p25_L_4721();
  return;
  lab_p25_L_4735: ;
  p00_L_29DF();
  p00_L_29DB();
  p00_L_2934();
  p00_L_107E();
  if (flag_nz()) goto lab_p25_L_4748;
  p25_L_4E5B();
  goto lab_p25_L_4764;
  lab_p25_L_4748: ;
  p00_L_290B();
  set_hl(0x4D6C);
  p00_rst20();
  p00_L_14CC();
  if (flag_z()) goto lab_p25_L_475B;
  p00_L_0D1F();
  p00_L_15D6();
  p00_rst30();
  lab_p25_L_475B: ;
  p00_L_2934();
  p00_L_0BDA();
  p00_L_29DB();
  lab_p25_L_4764: ;
  p00_L_2910();
  p25_L_4DF9();
  p00_L_28F1();
  p25_L_4DF9();
  p00_L_2910();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_478E;
  p25_L_4E5B();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_478E;
  p00_L_2945();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_4795;
  p00_L_2940();
  p00_L_29F7();
  lab_p25_L_478E: ;
  p00_L_29D7();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 1));
  cpu_push_af();
  lab_p25_L_4795: ;
  p00_L_28F1();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47BA;
  p00_L_292F();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47B4;
  cpu_pop_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4C26;
  cpu_push_af();
  p00_L_28F1();
  p00_L_2A13();
  goto lab_p25_L_47CC;
  lab_p25_L_47B4: ;
  p00_L_2934();
  p00_L_29F3();
  lab_p25_L_47BA: ;
  p00_L_29D3();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 2));
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p25_L_483D;
  p00_L_2910();
  p00_L_2A17();
  lab_p25_L_47CC: ;
  p25_L_4CC6();
  if (flag_c()) goto lab_p25_L_4800;
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47ED;
  cpu_pop_af();
  cpu_push_af();
  p25_L_47DD();
  goto lab_p25_L_47CC;
  lab_p25_L_47ED: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  cpu_push_af();
  if (flag_z()) p00_L_29D7();
  cpu_pop_af();
  if (flag_nz()) p00_L_29D3();
  cpu_pop_af();
  cpu_push_af();
  p25_L_47DD();
  goto lab_p25_L_483D;
  lab_p25_L_4800: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4820;
  p00_L_28E5();
  p00_L_29D3();
  p00_L_290B();
  p00_L_29F3();
  p25_L_4D96();
  p25_L_4D08();
  if (flag_c()) goto lab_p25_L_4C26;
  p00_L_29D7();
  goto lab_p25_L_4840;
  lab_p25_L_4820: ;
  p00_L_28CB();
  p00_L_29D7();
  p00_L_28EC();
  p25_L_4D96();
  p00_L_29DB();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_4C26;
  p00_L_29D3();
  p00_L_28E0();
  goto lab_p25_L_4843;
  lab_p25_L_483D: ;
  p00_L_28E5();
  lab_p25_L_4840: ;
  p00_L_28C3();
  lab_p25_L_4843: ;
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_4853;
  p00_L_14CC();
  if (flag_nz()) goto lab_p25_L_4856;
  p00_L_28F1();
  p00_L_29DF();
  lab_p25_L_4853: ;
  p25_L_4C96();
  return;
  lab_p25_L_4856: ;
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  p00_L_2910();
  p00_L_29E3();
  lab_p25_L_4862: ;
  p25_L_4CC6();
  if (flag_c()) goto lab_p25_L_487C;
  p25_L_4D08();
  if (flag_c()) goto lab_p25_L_4862;
  p00_L_28C3();
  p00_L_1100();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_4862;
  p00_L_1179();
  goto lab_p25_L_4882;
  lab_p25_L_487C: ;
  p00_L_291C();
  p25_L_4D08();
  lab_p25_L_4882: ;
  p00_L_29D7();
  p00_L_28C3();
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  lab_p25_L_488E: ;
  p00_L_28F1();
  p00_L_14C7();
  if (flag_z()) p00_L_1229();
  p00_L_15CB();
  if (flag_z()) goto lab_p25_L_48A2;
  p00_L_163B();
  if (flag_nc()) p00_L_0D16();
  lab_p25_L_48A2: ;
  p00_L_28EC();
  p00_L_15D6();
  p00_rst30();
  p25_L_4DCA();
  if (flag_c()) goto lab_p25_L_48F1;
  p00_L_29AA();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_48CA;
  p00_L_29D3();
  p00_L_2893();
  p00_L_29F3();
  p00_L_28E0();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_488E;
  p25_L_4956();
  return;
  lab_p25_L_48CA: ;
  p00_L_28F1();
  p00_L_2893();
  p25_L_4CC9();
  if (flag_c()) goto lab_p25_L_48E5;
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_48CA;
  p00_L_29D3();
  p00_L_2893();
  p00_L_29F3();
  goto lab_p25_L_48E8;
  lab_p25_L_48E5: ;
  p00_L_28CB();
  lab_p25_L_48E8: ;
  p00_L_28E0();
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  lab_p25_L_48F1: ;
  p00_L_2910();
  p00_L_14C7();
  if (flag_z()) p00_L_1241();
  p00_L_15CB();
  if (flag_nz()) goto lab_p25_L_4905;
  p00_L_163B();
  if (flag_nc()) p00_L_0D16();
  lab_p25_L_4905: ;
  p00_L_290B();
  p00_L_15D6();
  p00_L_0C13();
  p25_L_4DCA();
  p25_L_4911();
  return;
  lab_p25_L_4C26: ;
  a = 0x9A;
  p25_L_4C1B();
  return;
}

/* flash page 25 cpu 0x468B (offset 0x068B) */
void p25_L_468B(void) {
  p00_L_2310();
  p00_L_235C();
  p00_L_38F1();
  p00_L_1169();
  p00_L_16A2();
  p00_L_22F2();
  p00_L_233D();
  p00_L_1179();
  p00_L_10F8();
  p25_L_4E86();
  p00_L_39E1();
  p25_L_4D75();
  cpu_push_hl();
  goto lab_p25_L_46DA;
  lab_p25_L_46DA: ;
  p00_L_2A17();
  p00_L_2A03();
  p00_L_107E();
  a = 0x91;
  if (flag_nc()) { p25_L_4C1B(); return; }
  cpu_pop_af();
  mem_write8(0x848E, a);
  set_hl(0x4E7A);
  p00_L_25A2();
  a = mem_read8(0x848E);
  cpu_push_af();
  p00_L_2970();
  p00_L_38D9();
  p00_L_2970();
  p00_L_16F4();
  mem_write16(0x9306, de());
  p00_L_1130();
  p00_L_1037();
  if (flag_z()) goto lab_p25_L_4735;
  p00_rst10();
  cpu_ex_de_hl();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 3));
  cpu_push_af();
  p25_L_4D82();
  p00_L_29DB();
  p00_L_29F7();
  p00_L_107E();
  cpu_push_af();
  p25_L_4721();
  return;
  lab_p25_L_4735: ;
  p00_L_29DF();
  p00_L_29DB();
  p00_L_2934();
  p00_L_107E();
  if (flag_nz()) goto lab_p25_L_4748;
  p25_L_4E5B();
  goto lab_p25_L_4764;
  lab_p25_L_4748: ;
  p00_L_290B();
  set_hl(0x4D6C);
  p00_rst20();
  p00_L_14CC();
  if (flag_z()) goto lab_p25_L_475B;
  p00_L_0D1F();
  p00_L_15D6();
  p00_rst30();
  lab_p25_L_475B: ;
  p00_L_2934();
  p00_L_0BDA();
  p00_L_29DB();
  lab_p25_L_4764: ;
  p00_L_2910();
  p25_L_4DF9();
  p00_L_28F1();
  p25_L_4DF9();
  p00_L_2910();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_478E;
  p25_L_4E5B();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_478E;
  p00_L_2945();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_4795;
  p00_L_2940();
  p00_L_29F7();
  lab_p25_L_478E: ;
  p00_L_29D7();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 1));
  cpu_push_af();
  lab_p25_L_4795: ;
  p00_L_28F1();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47BA;
  p00_L_292F();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47B4;
  cpu_pop_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4C26;
  cpu_push_af();
  p00_L_28F1();
  p00_L_2A13();
  goto lab_p25_L_47CC;
  lab_p25_L_47B4: ;
  p00_L_2934();
  p00_L_29F3();
  lab_p25_L_47BA: ;
  p00_L_29D3();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 2));
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p25_L_483D;
  p00_L_2910();
  p00_L_2A17();
  lab_p25_L_47CC: ;
  p25_L_4CC6();
  if (flag_c()) goto lab_p25_L_4800;
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47ED;
  cpu_pop_af();
  cpu_push_af();
  p25_L_47DD();
  goto lab_p25_L_47CC;
  lab_p25_L_47ED: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  cpu_push_af();
  if (flag_z()) p00_L_29D7();
  cpu_pop_af();
  if (flag_nz()) p00_L_29D3();
  cpu_pop_af();
  cpu_push_af();
  p25_L_47DD();
  goto lab_p25_L_483D;
  lab_p25_L_4800: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4820;
  p00_L_28E5();
  p00_L_29D3();
  p00_L_290B();
  p00_L_29F3();
  p25_L_4D96();
  p25_L_4D08();
  if (flag_c()) goto lab_p25_L_4C26;
  p00_L_29D7();
  goto lab_p25_L_4840;
  lab_p25_L_4820: ;
  p00_L_28CB();
  p00_L_29D7();
  p00_L_28EC();
  p25_L_4D96();
  p00_L_29DB();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_4C26;
  p00_L_29D3();
  p00_L_28E0();
  goto lab_p25_L_4843;
  lab_p25_L_483D: ;
  p00_L_28E5();
  lab_p25_L_4840: ;
  p00_L_28C3();
  lab_p25_L_4843: ;
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_4853;
  p00_L_14CC();
  if (flag_nz()) goto lab_p25_L_4856;
  p00_L_28F1();
  p00_L_29DF();
  lab_p25_L_4853: ;
  p25_L_4C96();
  return;
  lab_p25_L_4856: ;
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  p00_L_2910();
  p00_L_29E3();
  lab_p25_L_4862: ;
  p25_L_4CC6();
  if (flag_c()) goto lab_p25_L_487C;
  p25_L_4D08();
  if (flag_c()) goto lab_p25_L_4862;
  p00_L_28C3();
  p00_L_1100();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_4862;
  p00_L_1179();
  goto lab_p25_L_4882;
  lab_p25_L_487C: ;
  p00_L_291C();
  p25_L_4D08();
  lab_p25_L_4882: ;
  p00_L_29D7();
  p00_L_28C3();
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  lab_p25_L_488E: ;
  p00_L_28F1();
  p00_L_14C7();
  if (flag_z()) p00_L_1229();
  p00_L_15CB();
  if (flag_z()) goto lab_p25_L_48A2;
  p00_L_163B();
  if (flag_nc()) p00_L_0D16();
  lab_p25_L_48A2: ;
  p00_L_28EC();
  p00_L_15D6();
  p00_rst30();
  p25_L_4DCA();
  if (flag_c()) goto lab_p25_L_48F1;
  p00_L_29AA();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_48CA;
  p00_L_29D3();
  p00_L_2893();
  p00_L_29F3();
  p00_L_28E0();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_488E;
  p25_L_4956();
  return;
  lab_p25_L_48CA: ;
  p00_L_28F1();
  p00_L_2893();
  p25_L_4CC9();
  if (flag_c()) goto lab_p25_L_48E5;
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_48CA;
  p00_L_29D3();
  p00_L_2893();
  p00_L_29F3();
  goto lab_p25_L_48E8;
  lab_p25_L_48E5: ;
  p00_L_28CB();
  lab_p25_L_48E8: ;
  p00_L_28E0();
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  lab_p25_L_48F1: ;
  p00_L_2910();
  p00_L_14C7();
  if (flag_z()) p00_L_1241();
  p00_L_15CB();
  if (flag_nz()) goto lab_p25_L_4905;
  p00_L_163B();
  if (flag_nc()) p00_L_0D16();
  lab_p25_L_4905: ;
  p00_L_290B();
  p00_L_15D6();
  p00_L_0C13();
  p25_L_4DCA();
  p25_L_4911();
  return;
  lab_p25_L_4C26: ;
  a = 0x9A;
  p25_L_4C1B();
  return;
}

/* flash page 25 cpu 0x46B2 (offset 0x06B2) */
void p25_L_46B2(void) {
  p25_L_4E86();
  p00_L_2191();
  p00_L_39E1();
  p25_L_4D75();
  cpu_push_hl();
  p00_L_113F();
  p00_rst10();
  cpu_ex_de_hl();
  p25_L_4D82();
  goto lab_p25_L_46DA;
  lab_p25_L_46DA: ;
  p00_L_2A17();
  p00_L_2A03();
  p00_L_107E();
  a = 0x91;
  if (flag_nc()) { p25_L_4C1B(); return; }
  cpu_pop_af();
  mem_write8(0x848E, a);
  set_hl(0x4E7A);
  p00_L_25A2();
  a = mem_read8(0x848E);
  cpu_push_af();
  p00_L_2970();
  p00_L_38D9();
  p00_L_2970();
  p00_L_16F4();
  mem_write16(0x9306, de());
  p00_L_1130();
  p00_L_1037();
  if (flag_z()) goto lab_p25_L_4735;
  p00_rst10();
  cpu_ex_de_hl();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 3));
  cpu_push_af();
  p25_L_4D82();
  p00_L_29DB();
  p00_L_29F7();
  p00_L_107E();
  cpu_push_af();
  p25_L_4721();
  return;
  lab_p25_L_4735: ;
  p00_L_29DF();
  p00_L_29DB();
  p00_L_2934();
  p00_L_107E();
  if (flag_nz()) goto lab_p25_L_4748;
  p25_L_4E5B();
  goto lab_p25_L_4764;
  lab_p25_L_4748: ;
  p00_L_290B();
  set_hl(0x4D6C);
  p00_rst20();
  p00_L_14CC();
  if (flag_z()) goto lab_p25_L_475B;
  p00_L_0D1F();
  p00_L_15D6();
  p00_rst30();
  lab_p25_L_475B: ;
  p00_L_2934();
  p00_L_0BDA();
  p00_L_29DB();
  lab_p25_L_4764: ;
  p00_L_2910();
  p25_L_4DF9();
  p00_L_28F1();
  p25_L_4DF9();
  p00_L_2910();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_478E;
  p25_L_4E5B();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_478E;
  p00_L_2945();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_4795;
  p00_L_2940();
  p00_L_29F7();
  lab_p25_L_478E: ;
  p00_L_29D7();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 1));
  cpu_push_af();
  lab_p25_L_4795: ;
  p00_L_28F1();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47BA;
  p00_L_292F();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47B4;
  cpu_pop_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4C26;
  cpu_push_af();
  p00_L_28F1();
  p00_L_2A13();
  goto lab_p25_L_47CC;
  lab_p25_L_47B4: ;
  p00_L_2934();
  p00_L_29F3();
  lab_p25_L_47BA: ;
  p00_L_29D3();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 2));
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p25_L_483D;
  p00_L_2910();
  p00_L_2A17();
  lab_p25_L_47CC: ;
  p25_L_4CC6();
  if (flag_c()) goto lab_p25_L_4800;
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47ED;
  cpu_pop_af();
  cpu_push_af();
  p25_L_47DD();
  goto lab_p25_L_47CC;
  lab_p25_L_47ED: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  cpu_push_af();
  if (flag_z()) p00_L_29D7();
  cpu_pop_af();
  if (flag_nz()) p00_L_29D3();
  cpu_pop_af();
  cpu_push_af();
  p25_L_47DD();
  goto lab_p25_L_483D;
  lab_p25_L_4800: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4820;
  p00_L_28E5();
  p00_L_29D3();
  p00_L_290B();
  p00_L_29F3();
  p25_L_4D96();
  p25_L_4D08();
  if (flag_c()) goto lab_p25_L_4C26;
  p00_L_29D7();
  goto lab_p25_L_4840;
  lab_p25_L_4820: ;
  p00_L_28CB();
  p00_L_29D7();
  p00_L_28EC();
  p25_L_4D96();
  p00_L_29DB();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_4C26;
  p00_L_29D3();
  p00_L_28E0();
  goto lab_p25_L_4843;
  lab_p25_L_483D: ;
  p00_L_28E5();
  lab_p25_L_4840: ;
  p00_L_28C3();
  lab_p25_L_4843: ;
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_4853;
  p00_L_14CC();
  if (flag_nz()) goto lab_p25_L_4856;
  p00_L_28F1();
  p00_L_29DF();
  lab_p25_L_4853: ;
  p25_L_4C96();
  return;
  lab_p25_L_4856: ;
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  p00_L_2910();
  p00_L_29E3();
  lab_p25_L_4862: ;
  p25_L_4CC6();
  if (flag_c()) goto lab_p25_L_487C;
  p25_L_4D08();
  if (flag_c()) goto lab_p25_L_4862;
  p00_L_28C3();
  p00_L_1100();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_4862;
  p00_L_1179();
  goto lab_p25_L_4882;
  lab_p25_L_487C: ;
  p00_L_291C();
  p25_L_4D08();
  lab_p25_L_4882: ;
  p00_L_29D7();
  p00_L_28C3();
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  lab_p25_L_488E: ;
  p00_L_28F1();
  p00_L_14C7();
  if (flag_z()) p00_L_1229();
  p00_L_15CB();
  if (flag_z()) goto lab_p25_L_48A2;
  p00_L_163B();
  if (flag_nc()) p00_L_0D16();
  lab_p25_L_48A2: ;
  p00_L_28EC();
  p00_L_15D6();
  p00_rst30();
  p25_L_4DCA();
  if (flag_c()) goto lab_p25_L_48F1;
  p00_L_29AA();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_48CA;
  p00_L_29D3();
  p00_L_2893();
  p00_L_29F3();
  p00_L_28E0();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_488E;
  p25_L_4956();
  return;
  lab_p25_L_48CA: ;
  p00_L_28F1();
  p00_L_2893();
  p25_L_4CC9();
  if (flag_c()) goto lab_p25_L_48E5;
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_48CA;
  p00_L_29D3();
  p00_L_2893();
  p00_L_29F3();
  goto lab_p25_L_48E8;
  lab_p25_L_48E5: ;
  p00_L_28CB();
  lab_p25_L_48E8: ;
  p00_L_28E0();
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  lab_p25_L_48F1: ;
  p00_L_2910();
  p00_L_14C7();
  if (flag_z()) p00_L_1241();
  p00_L_15CB();
  if (flag_nz()) goto lab_p25_L_4905;
  p00_L_163B();
  if (flag_nc()) p00_L_0D16();
  lab_p25_L_4905: ;
  p00_L_290B();
  p00_L_15D6();
  p00_L_0C13();
  p25_L_4DCA();
  p25_L_4911();
  return;
  lab_p25_L_4C26: ;
  a = 0x9A;
  p25_L_4C1B();
  return;
}

/* flash page 25 cpu 0x46C9 (offset 0x06C9) */
void p25_L_46C9(void) {
  p25_L_4E86();
  p00_L_39E1();
  p25_L_4D75();
  cpu_push_hl();
  p00_L_0FDE();
  p00_rst08();
  p00_L_0E4C();
  p00_L_2A17();
  p00_L_2A03();
  p00_L_107E();
  a = 0x91;
  if (flag_nc()) { p25_L_4C1B(); return; }
  cpu_pop_af();
  mem_write8(0x848E, a);
  set_hl(0x4E7A);
  p00_L_25A2();
  a = mem_read8(0x848E);
  cpu_push_af();
  p00_L_2970();
  p00_L_38D9();
  p00_L_2970();
  p00_L_16F4();
  mem_write16(0x9306, de());
  p00_L_1130();
  p00_L_1037();
  if (flag_z()) goto lab_p25_L_4735;
  p00_rst10();
  cpu_ex_de_hl();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 3));
  cpu_push_af();
  p25_L_4D82();
  p00_L_29DB();
  p00_L_29F7();
  p00_L_107E();
  cpu_push_af();
  p25_L_4721();
  return;
  lab_p25_L_4735: ;
  p00_L_29DF();
  p00_L_29DB();
  p00_L_2934();
  p00_L_107E();
  if (flag_nz()) goto lab_p25_L_4748;
  p25_L_4E5B();
  goto lab_p25_L_4764;
  lab_p25_L_4748: ;
  p00_L_290B();
  set_hl(0x4D6C);
  p00_rst20();
  p00_L_14CC();
  if (flag_z()) goto lab_p25_L_475B;
  p00_L_0D1F();
  p00_L_15D6();
  p00_rst30();
  lab_p25_L_475B: ;
  p00_L_2934();
  p00_L_0BDA();
  p00_L_29DB();
  lab_p25_L_4764: ;
  p00_L_2910();
  p25_L_4DF9();
  p00_L_28F1();
  p25_L_4DF9();
  p00_L_2910();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_478E;
  p25_L_4E5B();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_478E;
  p00_L_2945();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_4795;
  p00_L_2940();
  p00_L_29F7();
  lab_p25_L_478E: ;
  p00_L_29D7();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 1));
  cpu_push_af();
  lab_p25_L_4795: ;
  p00_L_28F1();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47BA;
  p00_L_292F();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47B4;
  cpu_pop_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4C26;
  cpu_push_af();
  p00_L_28F1();
  p00_L_2A13();
  goto lab_p25_L_47CC;
  lab_p25_L_47B4: ;
  p00_L_2934();
  p00_L_29F3();
  lab_p25_L_47BA: ;
  p00_L_29D3();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 2));
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p25_L_483D;
  p00_L_2910();
  p00_L_2A17();
  lab_p25_L_47CC: ;
  p25_L_4CC6();
  if (flag_c()) goto lab_p25_L_4800;
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47ED;
  cpu_pop_af();
  cpu_push_af();
  p25_L_47DD();
  goto lab_p25_L_47CC;
  lab_p25_L_47ED: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  cpu_push_af();
  if (flag_z()) p00_L_29D7();
  cpu_pop_af();
  if (flag_nz()) p00_L_29D3();
  cpu_pop_af();
  cpu_push_af();
  p25_L_47DD();
  goto lab_p25_L_483D;
  lab_p25_L_4800: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4820;
  p00_L_28E5();
  p00_L_29D3();
  p00_L_290B();
  p00_L_29F3();
  p25_L_4D96();
  p25_L_4D08();
  if (flag_c()) goto lab_p25_L_4C26;
  p00_L_29D7();
  goto lab_p25_L_4840;
  lab_p25_L_4820: ;
  p00_L_28CB();
  p00_L_29D7();
  p00_L_28EC();
  p25_L_4D96();
  p00_L_29DB();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_4C26;
  p00_L_29D3();
  p00_L_28E0();
  goto lab_p25_L_4843;
  lab_p25_L_483D: ;
  p00_L_28E5();
  lab_p25_L_4840: ;
  p00_L_28C3();
  lab_p25_L_4843: ;
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_4853;
  p00_L_14CC();
  if (flag_nz()) goto lab_p25_L_4856;
  p00_L_28F1();
  p00_L_29DF();
  lab_p25_L_4853: ;
  p25_L_4C96();
  return;
  lab_p25_L_4856: ;
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  p00_L_2910();
  p00_L_29E3();
  lab_p25_L_4862: ;
  p25_L_4CC6();
  if (flag_c()) goto lab_p25_L_487C;
  p25_L_4D08();
  if (flag_c()) goto lab_p25_L_4862;
  p00_L_28C3();
  p00_L_1100();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_4862;
  p00_L_1179();
  goto lab_p25_L_4882;
  lab_p25_L_487C: ;
  p00_L_291C();
  p25_L_4D08();
  lab_p25_L_4882: ;
  p00_L_29D7();
  p00_L_28C3();
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  lab_p25_L_488E: ;
  p00_L_28F1();
  p00_L_14C7();
  if (flag_z()) p00_L_1229();
  p00_L_15CB();
  if (flag_z()) goto lab_p25_L_48A2;
  p00_L_163B();
  if (flag_nc()) p00_L_0D16();
  lab_p25_L_48A2: ;
  p00_L_28EC();
  p00_L_15D6();
  p00_rst30();
  p25_L_4DCA();
  if (flag_c()) goto lab_p25_L_48F1;
  p00_L_29AA();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_48CA;
  p00_L_29D3();
  p00_L_2893();
  p00_L_29F3();
  p00_L_28E0();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_488E;
  p25_L_4956();
  return;
  lab_p25_L_48CA: ;
  p00_L_28F1();
  p00_L_2893();
  p25_L_4CC9();
  if (flag_c()) goto lab_p25_L_48E5;
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_48CA;
  p00_L_29D3();
  p00_L_2893();
  p00_L_29F3();
  goto lab_p25_L_48E8;
  lab_p25_L_48E5: ;
  p00_L_28CB();
  lab_p25_L_48E8: ;
  p00_L_28E0();
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  lab_p25_L_48F1: ;
  p00_L_2910();
  p00_L_14C7();
  if (flag_z()) p00_L_1241();
  p00_L_15CB();
  if (flag_nz()) goto lab_p25_L_4905;
  p00_L_163B();
  if (flag_nc()) p00_L_0D16();
  lab_p25_L_4905: ;
  p00_L_290B();
  p00_L_15D6();
  p00_L_0C13();
  p25_L_4DCA();
  p25_L_4911();
  return;
  lab_p25_L_4C26: ;
  a = 0x9A;
  p25_L_4C1B();
  return;
}

/* flash page 25 cpu 0x4721 (offset 0x0721) */
void p25_L_4721(void) {
  p00_L_290B();
  cpu_pop_af();
  if (flag_z()) goto lab_p25_L_4C26;
  if (flag_nc()) goto lab_p25_L_4764;
  p00_L_28F1();
  p00_L_29DF();
  p00_L_29F3();
  goto lab_p25_L_4764;
  lab_p25_L_4764: ;
  p00_L_2910();
  p25_L_4DF9();
  p00_L_28F1();
  p25_L_4DF9();
  p00_L_2910();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_478E;
  p25_L_4E5B();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_478E;
  p00_L_2945();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_4795;
  p00_L_2940();
  p00_L_29F7();
  lab_p25_L_478E: ;
  p00_L_29D7();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 1));
  cpu_push_af();
  lab_p25_L_4795: ;
  p00_L_28F1();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47BA;
  p00_L_292F();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47B4;
  cpu_pop_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4C26;
  cpu_push_af();
  p00_L_28F1();
  p00_L_2A13();
  goto lab_p25_L_47CC;
  lab_p25_L_47B4: ;
  p00_L_2934();
  p00_L_29F3();
  lab_p25_L_47BA: ;
  p00_L_29D3();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 2));
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p25_L_483D;
  p00_L_2910();
  p00_L_2A17();
  lab_p25_L_47CC: ;
  p25_L_4CC6();
  if (flag_c()) goto lab_p25_L_4800;
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47ED;
  cpu_pop_af();
  cpu_push_af();
  p25_L_47DD();
  goto lab_p25_L_47CC;
  lab_p25_L_47ED: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  cpu_push_af();
  if (flag_z()) p00_L_29D7();
  cpu_pop_af();
  if (flag_nz()) p00_L_29D3();
  cpu_pop_af();
  cpu_push_af();
  p25_L_47DD();
  goto lab_p25_L_483D;
  lab_p25_L_4800: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4820;
  p00_L_28E5();
  p00_L_29D3();
  p00_L_290B();
  p00_L_29F3();
  p25_L_4D96();
  p25_L_4D08();
  if (flag_c()) goto lab_p25_L_4C26;
  p00_L_29D7();
  goto lab_p25_L_4840;
  lab_p25_L_4820: ;
  p00_L_28CB();
  p00_L_29D7();
  p00_L_28EC();
  p25_L_4D96();
  p00_L_29DB();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_4C26;
  p00_L_29D3();
  p00_L_28E0();
  goto lab_p25_L_4843;
  lab_p25_L_483D: ;
  p00_L_28E5();
  lab_p25_L_4840: ;
  p00_L_28C3();
  lab_p25_L_4843: ;
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_4853;
  p00_L_14CC();
  if (flag_nz()) goto lab_p25_L_4856;
  p00_L_28F1();
  p00_L_29DF();
  lab_p25_L_4853: ;
  p25_L_4C96();
  return;
  lab_p25_L_4856: ;
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  p00_L_2910();
  p00_L_29E3();
  lab_p25_L_4862: ;
  p25_L_4CC6();
  if (flag_c()) goto lab_p25_L_487C;
  p25_L_4D08();
  if (flag_c()) goto lab_p25_L_4862;
  p00_L_28C3();
  p00_L_1100();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_4862;
  p00_L_1179();
  goto lab_p25_L_4882;
  lab_p25_L_487C: ;
  p00_L_291C();
  p25_L_4D08();
  lab_p25_L_4882: ;
  p00_L_29D7();
  p00_L_28C3();
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  lab_p25_L_488E: ;
  p00_L_28F1();
  p00_L_14C7();
  if (flag_z()) p00_L_1229();
  p00_L_15CB();
  if (flag_z()) goto lab_p25_L_48A2;
  p00_L_163B();
  if (flag_nc()) p00_L_0D16();
  lab_p25_L_48A2: ;
  p00_L_28EC();
  p00_L_15D6();
  p00_rst30();
  p25_L_4DCA();
  if (flag_c()) goto lab_p25_L_48F1;
  p00_L_29AA();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_48CA;
  p00_L_29D3();
  p00_L_2893();
  p00_L_29F3();
  p00_L_28E0();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_488E;
  p25_L_4956();
  return;
  lab_p25_L_48CA: ;
  p00_L_28F1();
  p00_L_2893();
  p25_L_4CC9();
  if (flag_c()) goto lab_p25_L_48E5;
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_48CA;
  p00_L_29D3();
  p00_L_2893();
  p00_L_29F3();
  goto lab_p25_L_48E8;
  lab_p25_L_48E5: ;
  p00_L_28CB();
  lab_p25_L_48E8: ;
  p00_L_28E0();
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  lab_p25_L_48F1: ;
  p00_L_2910();
  p00_L_14C7();
  if (flag_z()) p00_L_1241();
  p00_L_15CB();
  if (flag_nz()) goto lab_p25_L_4905;
  p00_L_163B();
  if (flag_nc()) p00_L_0D16();
  lab_p25_L_4905: ;
  p00_L_290B();
  p00_L_15D6();
  p00_L_0C13();
  p25_L_4DCA();
  p25_L_4911();
  return;
  lab_p25_L_4C26: ;
  a = 0x9A;
  p25_L_4C1B();
  return;
}

/* flash page 25 cpu 0x472C (offset 0x072C) */
void p25_L_472C(void) {
  goto lab_p25_L_472C;
  lab_p25_L_46CA: ;
  /* add a,(hl) */
  c = mem_read8(hl());
  p00_L_39E1();
  p25_L_4D75();
  cpu_push_hl();
  p00_L_0FDE();
  p00_rst08();
  p00_L_0E4C();
  p00_L_2A17();
  p00_L_2A03();
  p00_L_107E();
  a = 0x91;
  if (flag_nc()) { p25_L_4C1B(); return; }
  cpu_pop_af();
  mem_write8(0x848E, a);
  set_hl(0x4E7A);
  p00_L_25A2();
  a = mem_read8(0x848E);
  cpu_push_af();
  p00_L_2970();
  p00_L_38D9();
  lab_p25_L_46FB: ;
  if (flag_c()) goto lab_p25_L_46CA;
  p00_L_2970();
  mem_write8(hl(), b);
  set_hl((uint16_t)(hl() + hl()));
  p00_L_16F4();
  mem_write16(0x9306, de());
  p00_L_1130();
  p00_L_1037();
  if (flag_z()) goto lab_p25_L_4735;
  p00_rst10();
  cpu_ex_de_hl();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 3));
  cpu_push_af();
  p25_L_4D82();
  p00_L_29DB();
  p00_L_29F7();
  p00_L_107E();
  cpu_push_af();
  p25_L_4721();
  return;
  lab_p25_L_472C: ;
  if (flag_z()) goto lab_p25_L_46FB;
  p00_rst18();
  set_hl((uint16_t)(hl() + hl()));
  p00_L_29F3();
  goto lab_p25_L_4764;
  lab_p25_L_4735: ;
  p00_L_29DF();
  p00_L_29DB();
  p00_L_2934();
  p00_L_107E();
  if (flag_nz()) goto lab_p25_L_4748;
  p25_L_4E5B();
  goto lab_p25_L_4764;
  lab_p25_L_4748: ;
  p00_L_290B();
  set_hl(0x4D6C);
  p00_rst20();
  p00_L_14CC();
  if (flag_z()) goto lab_p25_L_475B;
  p00_L_0D1F();
  p00_L_15D6();
  p00_rst30();
  lab_p25_L_475B: ;
  p00_L_2934();
  p00_L_0BDA();
  p00_L_29DB();
  lab_p25_L_4764: ;
  p00_L_2910();
  p25_L_4DF9();
  p00_L_28F1();
  p25_L_4DF9();
  p00_L_2910();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_478E;
  p25_L_4E5B();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_478E;
  p00_L_2945();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_4795;
  p00_L_2940();
  p00_L_29F7();
  lab_p25_L_478E: ;
  p00_L_29D7();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 1));
  cpu_push_af();
  lab_p25_L_4795: ;
  p00_L_28F1();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47BA;
  p00_L_292F();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47B4;
  cpu_pop_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4C26;
  cpu_push_af();
  p00_L_28F1();
  p00_L_2A13();
  goto lab_p25_L_47CC;
  lab_p25_L_47B4: ;
  p00_L_2934();
  p00_L_29F3();
  lab_p25_L_47BA: ;
  p00_L_29D3();
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 2));
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p25_L_483D;
  p00_L_2910();
  p00_L_2A17();
  lab_p25_L_47CC: ;
  p25_L_4CC6();
  if (flag_c()) goto lab_p25_L_4800;
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_47ED;
  cpu_pop_af();
  cpu_push_af();
  p25_L_47DD();
  goto lab_p25_L_47CC;
  lab_p25_L_47ED: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  cpu_push_af();
  if (flag_z()) p00_L_29D7();
  cpu_pop_af();
  if (flag_nz()) p00_L_29D3();
  cpu_pop_af();
  cpu_push_af();
  p25_L_47DD();
  goto lab_p25_L_483D;
  lab_p25_L_4800: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4820;
  p00_L_28E5();
  p00_L_29D3();
  p00_L_290B();
  p00_L_29F3();
  p25_L_4D96();
  p25_L_4D08();
  if (flag_c()) goto lab_p25_L_4C26;
  p00_L_29D7();
  goto lab_p25_L_4840;
  lab_p25_L_4820: ;
  p00_L_28CB();
  p00_L_29D7();
  p00_L_28EC();
  p25_L_4D96();
  p00_L_29DB();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_4C26;
  p00_L_29D3();
  p00_L_28E0();
  goto lab_p25_L_4843;
  lab_p25_L_483D: ;
  p00_L_28E5();
  lab_p25_L_4840: ;
  p00_L_28C3();
  lab_p25_L_4843: ;
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_4853;
  p00_L_14CC();
  if (flag_nz()) goto lab_p25_L_4856;
  p00_L_28F1();
  p00_L_29DF();
  lab_p25_L_4853: ;
  p25_L_4C96();
  return;
  lab_p25_L_4856: ;
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  p00_L_2910();
  p00_L_29E3();
  lab_p25_L_4862: ;
  p25_L_4CC6();
  if (flag_c()) goto lab_p25_L_487C;
  p25_L_4D08();
  if (flag_c()) goto lab_p25_L_4862;
  p00_L_28C3();
  p00_L_1100();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_4862;
  p00_L_1179();
  goto lab_p25_L_4882;
  lab_p25_L_487C: ;
  p00_L_291C();
  p25_L_4D08();
  lab_p25_L_4882: ;
  p00_L_29D7();
  p00_L_28C3();
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  lab_p25_L_488E: ;
  p00_L_28F1();
  p00_L_14C7();
  if (flag_z()) p00_L_1229();
  p00_L_15CB();
  if (flag_z()) goto lab_p25_L_48A2;
  p00_L_163B();
  if (flag_nc()) p00_L_0D16();
  lab_p25_L_48A2: ;
  p00_L_28EC();
  p00_L_15D6();
  p00_rst30();
  p25_L_4DCA();
  if (flag_c()) goto lab_p25_L_48F1;
  p00_L_29AA();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_48CA;
  p00_L_29D3();
  p00_L_2893();
  p00_L_29F3();
  p00_L_28E0();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_488E;
  p25_L_4956();
  return;
  lab_p25_L_48CA: ;
  p00_L_28F1();
  p00_L_2893();
  p25_L_4CC9();
  if (flag_c()) goto lab_p25_L_48E5;
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_48CA;
  p00_L_29D3();
  p00_L_2893();
  p00_L_29F3();
  goto lab_p25_L_48E8;
  lab_p25_L_48E5: ;
  p00_L_28CB();
  lab_p25_L_48E8: ;
  p00_L_28E0();
  p00_L_107E();
  if (flag_nz()) { p25_L_4956(); return; }
  lab_p25_L_48F1: ;
  p00_L_2910();
  p00_L_14C7();
  if (flag_z()) p00_L_1241();
  p00_L_15CB();
  if (flag_nz()) goto lab_p25_L_4905;
  p00_L_163B();
  if (flag_nc()) p00_L_0D16();
  lab_p25_L_4905: ;
  p00_L_290B();
  p00_L_15D6();
  p00_L_0C13();
  p25_L_4DCA();
  p25_L_4911();
  return;
  lab_p25_L_4C26: ;
  a = 0x9A;
  p25_L_4C1B();
  return;
}

/* flash page 25 cpu 0x47DD (offset 0x07DD) */
void p25_L_47DD(void) {
  flag_set_z((a & (1u << 1)) == 0);
  cpu_push_af();
  p00_L_289D();
  cpu_pop_af();
  cpu_push_af();
  if (flag_z()) p00_L_29DF();
  cpu_pop_af();
  if (flag_nz()) p00_L_29DB();
  return;
}

/* flash page 25 cpu 0x4911 (offset 0x0911) */
void p25_L_4911(void) {
  goto lab_p25_L_4911;
  lab_p25_L_48F1: ;
  p00_L_2910();
  p00_L_14C7();
  if (flag_z()) p00_L_1241();
  p00_L_15CB();
  if (flag_nz()) goto lab_p25_L_4905;
  p00_L_163B();
  if (flag_nc()) p00_L_0D16();
  lab_p25_L_4905: ;
  p00_L_290B();
  p00_L_15D6();
  p00_L_0C13();
  p25_L_4DCA();
  lab_p25_L_4911: ;
  if (flag_c()) goto lab_p25_L_494A;
  p00_L_29AA();
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_492F;
  p00_L_29D7();
  p00_L_2893();
  p00_L_29F7();
  p00_L_28C3();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_48F1;
  p25_L_4956();
  return;
  lab_p25_L_492F: ;
  p00_L_289D();
  p00_L_290B();
  p25_L_4CC9();
  if (flag_c()) goto lab_p25_L_494A;
  p25_L_4D0B();
  if (flag_c()) goto lab_p25_L_492F;
  p00_L_29D7();
  p00_L_2893();
  p00_L_29F7();
  goto lab_p25_L_494D;
  lab_p25_L_494A: ;
  p00_L_28E5();
  lab_p25_L_494D: ;
  p00_L_28C3();
  p00_L_107E();
  if (flag_z()) { p00_L_251D(); return; }
  p25_L_4956();
  return;
}

/* flash page 25 cpu 0x4956 (offset 0x0956) */
void p25_L_4956(void) {
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p25_L_4A2C;
  p25_L_4CB3();
  if (flag_nz()) goto lab_p25_L_4A2C;
  p00_L_1078();
  if (flag_nc()) goto lab_p25_L_497D;
  p25_L_4DB6();
  p00_L_29DB();
  p00_L_29F7();
  p00_L_28E5();
  p00_L_28C3();
  p00_L_29D3();
  p00_L_29EF();
  lab_p25_L_497D: ;
  p25_L_4DA9();
  set_hl(0x0A07);
  cpu_push_hl();
  p25_L_4984();
  return;
  lab_p25_L_4A2C: ;
  cpu_pop_af();
  set_hl(0x0000);
  cpu_push_hl();
  cpu_push_hl();
  a = (uint8_t)(a | (1u << 1));
  a = (uint8_t)(a & ~(1u << 2));
  cpu_push_af();
  p25_L_4CB3();
  if (flag_nz()) goto lab_p25_L_4A65;
  p25_L_4E11();
  p00_L_292F();
  p25_L_4E92();
  p00_L_0BDA();
  p25_L_4E34();
  if (flag_nc()) goto lab_p25_L_4A65;
  p00_L_2945();
  p25_L_4E92();
  p00_L_14B0();
  p00_L_0E4C();
  p00_L_0BE3();
  p25_L_4E34();
  if (flag_nc()) goto lab_p25_L_4A65;
  cpu_pop_af();
  a = a ^ 0x02;
  flag_logic(a);
  cpu_push_af();
  lab_p25_L_4A65: ;
  p00_L_28C3();
  p00_L_28F1();
  p25_L_4DAF();
  p00_L_290B();
  p00_L_0C13();
  p00_L_15D6();
  p00_L_29C8();
  p00_L_28CB();
  p00_L_28E0();
  p00_L_15D6();
  p00_L_15D1();
  p00_L_0BE3();
  p00_L_29AA();
  p25_L_4A8C();
  return;
}

/* flash page 25 cpu 0x4984 (offset 0x0984) */
void p25_L_4984(void) {
  p00_L_28EC();
  p00_L_0C2D();
  p00_L_0C18();
  p00_L_28EC();
  p25_L_4990();
  return;
}

/* flash page 25 cpu 0x4990 (offset 0x0990) */
void p25_L_4990(void) {
  lab_p25_L_4990: ;
  p00_rst30();
  p00_L_29AA();
  p25_L_4DCA();
  if (flag_nc()) goto lab_p25_L_49A2;
  lab_p25_L_4999: ;
  cpu_pop_hl();
  lab_p25_L_499A: ;
  l = (uint8_t)(l - 1);
  if (flag_z()) goto lab_p25_L_4A2C;
  h = 0x0A;
  goto lab_p25_L_49DC;
  lab_p25_L_49A2: ;
  p00_L_289D();
  p25_L_4D0B();
  if (flag_nc()) goto lab_p25_L_49BF;
  p25_L_4DB6();
  p00_L_107E();
  cpu_push_af();
  p00_L_289D();
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) p00_L_2A17();
  cpu_pop_af();
  if (flag_nc()) p00_L_2A13();
  goto lab_p25_L_4999;
  lab_p25_L_49BF: ;
  p00_L_29C8();
  p00_L_28E0();
  p00_L_15CB();
  b = a;
  p00_L_15C6();
  a = a ^ b;
  flag_logic(a);
  if (flag_nz()) goto lab_p25_L_4A1C;
  p00_L_1078();
  if (flag_c()) goto lab_p25_L_4A03;
  if (flag_z()) goto lab_p25_L_4A03;
  cpu_pop_hl();
  a = h;
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p25_L_49F6;
  lab_p25_L_49DC: ;
  cpu_push_hl();
  p00_L_2902();
  p00_L_2923();
  p25_L_4DC3();
  p00_L_2893();
  p00_L_29AA();
  p00_L_0C13();
  p00_L_15E0();
  p00_L_29E3();
  cpu_pop_hl();
  lab_p25_L_49F6: ;
  h = (uint8_t)(h - 1);
  if (flag_z()) goto lab_p25_L_499A;
  cpu_push_hl();
  p00_L_291C();
  p00_L_2893();
  goto lab_p25_L_4990;
  lab_p25_L_4A03: ;
  p25_L_4DA9();
  p00_L_28B5();
  p00_L_29D7();
  p00_L_289D();
  p00_L_29DF();
  cpu_pop_hl();
  a = h;
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p25_L_49F6;
  cpu_push_hl();
  p25_L_4984();
  return;
  lab_p25_L_4A1C: ;
  cpu_pop_bc();
  p00_L_28E5();
  p00_L_29D3();
  p00_L_2910();
  p00_L_29DB();
  p25_L_4DBD();
  lab_p25_L_4A2C: ;
  cpu_pop_af();
  set_hl(0x0000);
  cpu_push_hl();
  cpu_push_hl();
  a = (uint8_t)(a | (1u << 1));
  a = (uint8_t)(a & ~(1u << 2));
  cpu_push_af();
  p25_L_4CB3();
  if (flag_nz()) goto lab_p25_L_4A65;
  p25_L_4E11();
  p00_L_292F();
  p25_L_4E92();
  p00_L_0BDA();
  p25_L_4E34();
  if (flag_nc()) goto lab_p25_L_4A65;
  p00_L_2945();
  p25_L_4E92();
  p00_L_14B0();
  p00_L_0E4C();
  p00_L_0BE3();
  p25_L_4E34();
  if (flag_nc()) goto lab_p25_L_4A65;
  cpu_pop_af();
  a = a ^ 0x02;
  flag_logic(a);
  cpu_push_af();
  lab_p25_L_4A65: ;
  p00_L_28C3();
  p00_L_28F1();
  p25_L_4DAF();
  p00_L_290B();
  p00_L_0C13();
  p00_L_15D6();
  p00_L_29C8();
  p00_L_28CB();
  p00_L_28E0();
  p00_L_15D6();
  p00_L_15D1();
  p00_L_0BE3();
  p00_L_29AA();
  p25_L_4A8C();
  return;
}

/* flash page 25 cpu 0x4A8C (offset 0x0A8C) */
void p25_L_4A8C(void) {
  lab_p25_L_4A8C: ;
  p25_L_4E11();
  cpu_pop_af();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_af();
  set_de(0x0015);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p25_L_4AAE;
  p25_L_4DB6();
  p00_L_107E();
  cpu_push_af();
  p00_L_28F1();
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) p00_L_2A13();
  cpu_pop_af();
  if (flag_nc()) p00_L_2A17();
  lab_p25_L_4AAE: ;
  p25_L_4CB3();
  cpu_push_af();
  p25_L_4DB6();
  p00_L_0C13();
  p00_L_0D16();
  p00_L_29E3();
  cpu_pop_af();
  if (flag_z()) goto lab_p25_L_4AD6;
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 1));
  cpu_push_af();
  p00_L_15CB();
  cpu_push_af();
  p25_L_4DB6();
  cpu_pop_af();
  if (flag_nz()) p00_L_14B0();
  p00_L_2A03();
  p00_L_2A17();
  lab_p25_L_4AD6: ;
  p00_L_28E5();
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_4C94;
  p25_L_4DE3();
  p00_L_10DD();
  p00_L_2917();
  p00_L_1078();
  if (flag_nc()) goto lab_p25_L_4C81;
  cpu_pop_af();
  cpu_pop_de();
  cpu_push_de();
  cpu_push_af();
  set_hl(0x01F3);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p25_L_4C19;
  p00_L_28E5();
  p00_L_2923();
  p00_L_0C13();
  p00_L_1169();
  p00_L_2910();
  p00_L_28FD();
  set_hl(0x4BBD);
  p00_L_25A2();
  p00_L_0C2D();
  p00_L_28E0();
  p00_L_0D1F();
  p00_L_25C8();
  p00_L_15CB();
  if (flag_z()) goto lab_p25_L_4B2F;
  p00_L_0E4C();
  a = mem_read8(0x84AF);
  a = a ^ 0x80;
  flag_logic(a);
  mem_write8(0x84AF, a);
  lab_p25_L_4B2F: ;
  p00_L_1171();
  p25_L_4DA9();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  cpu_push_af();
  cpu_push_de();
  cpu_push_bc();
  flag_cmp(a, 0x04);
  if (flag_c()) goto lab_p25_L_4B65;
  flag_set_z((b & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4B55;
  p00_L_291C();
  p00_L_120C();
  p00_L_0D1F();
  p00_L_28B0();
  p00_L_1078();
  if (flag_nc()) goto lab_p25_L_4BC0;
  lab_p25_L_4B55: ;
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_af();
  a = 0;
  flag_logic(a);
  cpu_push_af();
  cpu_push_hl();
  cpu_push_bc();
  p00_L_291C();
  p00_L_15D6();
  p00_L_29C8();
  lab_p25_L_4B65: ;
  p00_L_1130();
  p00_L_10EF();
  p00_L_0D1F();
  p00_L_1108();
  p00_L_1078();
  if (flag_c()) goto lab_p25_L_4B84;
  p00_L_1135();
  p00_L_2917();
  a = mem_read8(0x8483);
  mem_write8(0x8478, a);
  goto lab_p25_L_4BDE;
  lab_p25_L_4B84: ;
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_4B8F;
  p00_L_291C();
  goto lab_p25_L_4BA2;
  lab_p25_L_4B8F: ;
  p00_L_290B();
  a = mem_read8(0x84AF);
  a = a & 0x80;
  flag_logic(a);
  cpu_push_af();
  if (flag_z()) p00_L_292F();
  cpu_pop_af();
  if (flag_nz()) p00_L_2945();
  p00_L_0C2D();
  lab_p25_L_4BA2: ;
  p00_L_1128();
  set_hl(0x4BC0);
  p00_L_25A2();
  p00_L_0D1F();
  p00_L_25C8();
  p00_L_1108();
  p00_L_107E();
  if (flag_c()) goto lab_p25_L_4BC0;
  if (flag_nz()) goto lab_p25_L_4BCC;
  goto lab_p25_L_4BC0;
  lab_p25_L_4BC0: ;
  p00_L_2910();
  p00_L_28EC();
  p00_rst30();
  p00_L_0D16();
  goto lab_p25_L_4BE2;
  lab_p25_L_4BCC: ;
  p00_L_113A();
  p00_L_1128();
  set_hl(0x4BC0);
  p00_L_25A2();
  p00_L_0ED0();
  p00_L_25C8();
  lab_p25_L_4BDE: ;
  p00_L_290B();
  p00_rst30();
  lab_p25_L_4BE2: ;
  p00_L_29DF();
  cpu_pop_af();
  cpu_push_af();
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p25_L_4BF7;
  p00_L_28CB();
  p00_L_2A1B();
  p00_L_28F1();
  p00_L_2A1F();
  lab_p25_L_4BF7: ;
  p00_L_2910();
  p25_L_4D0B();
  cpu_pop_de();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  cpu_push_de();
  if (flag_nc()) goto lab_p25_L_4C56;
  set_bc(0x01F3);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p25_L_4C2A;
  p00_L_28F1();
  p00_L_15FB();
  set_de(mem_read16(0x9306));
  p00_L_11FD();
  lab_p25_L_4C19: ;
  a = 0x99;
  p25_L_4C1B();
  return;
  lab_p25_L_4C2A: ;
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 2));
  cpu_push_af();
  p25_L_4E27();
  p25_L_4DB6();
  p00_L_0C2D();
  p00_L_10DD();
  p25_L_4DE3();
  p00_L_10EF();
  p00_L_1078();
  if (flag_c()) goto lab_p25_L_4BC0;
  p00_L_28F1();
  p00_L_15FB();
  set_de(mem_read16(0x9306));
  p00_L_11FD();
  lab_p25_L_4C53: ;
  p00_L_251D();
  return;
  lab_p25_L_4C56: ;
  p00_L_29D7();
  cpu_pop_af();
  flag_set_z((a & (1u << 2)) == 0);
  a = (uint8_t)(a & ~(1u << 2));
  cpu_push_af();
  if (flag_z()) goto lab_p25_L_4C75;
  p00_L_28E0();
  p00_L_2951();
  p25_L_4CB9();
  if (flag_z()) goto lab_p25_L_4C75;
  p00_L_29D3();
  p00_L_295D();
  p00_L_29DB();
  lab_p25_L_4C75: ;
  p25_L_4CB3();
  if (flag_nz()) goto lab_p25_L_4A8C;
  p25_L_4E27();
  goto lab_p25_L_4A8C;
  lab_p25_L_4C81: ;
  p25_L_4CB3();
  if (flag_z()) goto lab_p25_L_4C53;
  p00_L_289D();
  p00_L_28E0();
  p00_L_1078();
  a = 0x97;
  if (flag_c()) { p25_L_4C1B(); return; }
  lab_p25_L_4C94: ;
  cpu_pop_af();
  cpu_pop_af();
  p25_L_4C96();
  return;
}

/* flash page 25 cpu 0x4C1B (offset 0x0C1B) */
void p25_L_4C1B(void) {
  cpu_push_af();
  p00_L_2969();
  p00_L_39ED();
  cpu_pop_af();
  p00_L_255F();
  return;
}

/* flash page 25 cpu 0x4C96 (offset 0x0C96) */
void p25_L_4C96(void) {
  cpu_pop_af();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 2)));
  p00_L_2970();
  p00_L_3975();
  p00_L_2969();
  p00_L_39ED();
  p00_L_2910();
  set_de(0x0090);
  p00_L_21B6();
  return;
}

/* flash page 25 cpu 0x4CB3 (offset 0x0CB3) */
void p25_L_4CB3(void) {
  p00_L_28CB();
  p00_L_28E0();
  p25_L_4CB9();
  return;
}

/* flash page 25 cpu 0x4CB9 (offset 0x0CB9) */
void p25_L_4CB9(void) {
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  b = a;
  a = mem_read8(0x8483);
  a = a & 0x80;
  flag_logic(a);
  a = a ^ b;
  flag_logic(a);
  return;
}

/* flash page 25 cpu 0x4CC6 (offset 0x0CC6) */
void p25_L_4CC6(void) {
  p25_L_4DB6();
  p25_L_4CC9();
  return;
}

/* flash page 25 cpu 0x4CC9 (offset 0x0CC9) */
void p25_L_4CC9(void) {
  p00_L_10DD();
  p00_L_0C13();
  p00_L_0D16();
  p00_L_1171();
  p00_L_15D6();
  a = mem_read8(0x849B);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p25_L_4CE9;
  set_hl(0x4D5A);
  p00_L_1073();
  if (flag_c()) return;
  if (flag_nz()) goto lab_p25_L_4CE9;
  lab_p25_L_4CE7: ;
  /* scf */
  return;
  lab_p25_L_4CE9: ;
  p00_L_1135();
  set_hl(0x4D63);
  p00_L_0D19();
  p00_rst08();
  p00_L_113A();
  p00_L_1078();
  if (flag_c()) return;
  if (flag_z()) goto lab_p25_L_4CE7;
  p00_L_113A();
  p00_L_10EF();
  p00_rst30();
  p00_L_29AA();
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 25 cpu 0x4D08 (offset 0x0D08) */
void p25_L_4D08(void) {
  p00_L_29DF();
  p25_L_4D0B();
  return;
}

/* flash page 25 cpu 0x4D0B (offset 0x0D0B) */
void p25_L_4D0B(void) {
  p00_L_15FB();
  set_de(mem_read16(0x9306));
  p00_L_11FD();
  p00_L_2990();
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  set_hl(0x4D40);
  p00_L_25A2();
  p00_L_39E7();
  p00_L_1717();
  p00_L_25C8();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  p00_L_16BC();
  a = mem_read8(0x8478);
  p00_L_171E();
  a = a & 0x1F;
  flag_logic(a);
  p00_L_16B5();
  if (flag_z()) return;
  /* scf */
  return;
}

/* flash page 25 cpu 0x4D75 (offset 0x0D75) */
void p25_L_4D75(void) {
  set_hl(0x0075);
  p00_L_21C3();
  mem_write16(0x9302, hl());
  set_hl(0x0000);
  return;
}

/* flash page 25 cpu 0x4D82 (offset 0x0D82) */
void p25_L_4D82(void) {
  a = mem_read8(hl());
  flag_cmp(a, 0x02);
  lab_p25_L_4D85: ;
  a = 0x8C;
  if (flag_nz()) { p25_L_4C1B(); return; }
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p25_L_4D85;
  set_hl((uint16_t)(hl() + 1));
  p00_rst20();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1183();
  return;
}

/* flash page 25 cpu 0x4D96 (offset 0x0D96) */
void p25_L_4D96(void) {
  set_hl(0x4D63);
  p00_rst20();
  p00_L_14CC();
  if (flag_z()) { p00_L_0E4C(); return; }
  p00_L_0D1F();
  p00_L_15D6();
  p00_L_0C13();
  return;
}

/* flash page 25 cpu 0x4DA9 (offset 0x0DA9) */
void p25_L_4DA9(void) {
  p00_L_2910();
  p00_L_28E0();
  p25_L_4DAF();
  return;
}

/* flash page 25 cpu 0x4DAF (offset 0x0DAF) */
void p25_L_4DAF(void) {
  p00_L_29FF();
  p00_L_29A1();
  return;
}

/* flash page 25 cpu 0x4DB6 (offset 0x0DB6) */
void p25_L_4DB6(void) {
  p00_L_2910();
  p00_L_28EC();
  return;
}

/* flash page 25 cpu 0x4DBD (offset 0x0DBD) */
void p25_L_4DBD(void) {
  p00_L_28B0();
  p00_L_289D();
  p25_L_4DC3();
  return;
}

/* flash page 25 cpu 0x4DC3 (offset 0x0DC3) */
void p25_L_4DC3(void) {
  p00_L_29DF();
  p00_L_29EF();
  return;
}

/* flash page 25 cpu 0x4DCA (offset 0x0DCA) */
void p25_L_4DCA(void) {
  p00_L_1100();
  p00_L_2940();
  p00_L_107E();
  if (flag_c()) return;
  p00_L_10F8();
  p00_L_292F();
  p00_L_107E();
  if (flag_c()) return;
  p00_L_113F();
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 25 cpu 0x4DE3 (offset 0x0DE3) */
void p25_L_4DE3(void) {
  p00_L_2910();
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_4DF4;
  set_hl(0x4D63);
  p00_L_0D19();
  p00_L_15D6();
  return;
  lab_p25_L_4DF4: ;
  set_hl(0x4D5A);
  p00_rst20();
  return;
}

/* flash page 25 cpu 0x4DF9 (offset 0x0DF9) */
void p25_L_4DF9(void) {
  p00_L_1100();
  p00_L_2940();
  p25_L_4E08();
  p00_L_10F8();
  p00_L_292F();
  p25_L_4E08();
  return;
}

/* flash page 25 cpu 0x4E08 (offset 0x0E08) */
void p25_L_4E08(void) {
  p00_L_107E();
  if (flag_nc()) return;
  a = 0x91;
  p25_L_4C1B();
  return;
}

/* flash page 25 cpu 0x4E11 (offset 0x0E11) */
void p25_L_4E11(void) {
  p00_L_28CB();
  p00_L_28E0();
  p00_L_1078();
  if (flag_nc()) return;
  p25_L_4DA9();
  p00_L_28F1();
  p00_L_28C3();
  p25_L_4DC3();
  p25_L_4E27();
  return;
}

/* flash page 25 cpu 0x4E27 (offset 0x0E27) */
void p25_L_4E27(void) {
  p00_L_2902();
  p00_L_29DB();
  p00_L_2928();
  p00_L_29D3();
  return;
}

/* flash page 25 cpu 0x4E34 (offset 0x0E34) */
void p25_L_4E34(void) {
  p00_rst18();
  p25_L_4D0B();
  cpu_push_af();
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9302, hl());
  cpu_pop_af();
  lab_p25_L_4E41: ;
  cpu_push_af();
  if (flag_c()) p00_L_21A7();
  cpu_pop_af();
  if (flag_c()) return;
  p00_L_28E0();
  p25_L_4CB9();
  /* scf */
  if (flag_z()) goto lab_p25_L_4E41;
  p00_L_29D3();
  p00_L_219B();
  p00_L_29DB();
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 25 cpu 0x4E5B (offset 0x0E5B) */
void p25_L_4E5B(void) {
  p00_L_290B();
  set_hl(0x4D6C);
  p00_rst20();
  p00_L_14CC();
  if (flag_z()) goto lab_p25_L_4E6D;
  p00_L_0D1F();
  p00_L_15D6();
  lab_p25_L_4E6D: ;
  p00_L_0C13();
  p00_L_2940();
  p00_L_0BE3();
  p00_L_29DF();
  return;
}

/* flash page 25 cpu 0x4E86 (offset 0x0E86) */
void p25_L_4E86(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x07)) & (1u << 2)) == 0);
  if (flag_nz()) { p00_L_2501(); return; }
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 2)));
  return;
}

/* flash page 25 cpu 0x4E92 (offset 0x0E92) */
void p25_L_4E92(void) {
  p00_L_1251();
  a = 0x8A;
  mem_write8(0x8484, a);
  return;
}

/* flash page 25 cpu 0x4E9B (offset 0x0E9B) */
void p25_L_4E9B(void) {
  flag_cmp(a, 0x3E);
  if (flag_nz()) goto lab_p25_L_4EA1;
  lab_p25_L_4E9F: ;
  a = a | a;
  flag_logic(a);
  return;
  lab_p25_L_4EA1: ;
  p25_L_4F6F();
  if (flag_c()) goto lab_p25_L_4F76;
  b = a;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x45);
  a = b;
  if (flag_z()) goto lab_p25_L_4E9F;
  p25_L_4EE9();
  if (flag_nz()) { p25_L_5509(); return; }
  p25_L_4EB6();
  return;
  lab_p25_L_4F76: ;
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 0)));
  p25_L_60B2();
  if (flag_z()) goto lab_p25_L_5024;
  p25_L_4F5E();
  if (flag_z()) { p25_L_58A3(); return; }
  p25_L_60BA();
  if (flag_nz()) goto lab_p25_L_4F96;
  set_hl(0x6844);
  b = 0x06;
  lab_p25_L_4F90: ;
  cpu_cp_hl();
  if (flag_z()) goto lab_p25_L_4FA3;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_4F90;
  lab_p25_L_4F96: ;
  p25_L_4EE9();
  if (flag_z()) goto lab_p25_L_4FC6;
  p25_L_4EF3();
  if (flag_z()) goto lab_p25_L_4FA3;
  p25_L_4F0F();
  lab_p25_L_4FA3: ;
  if (flag_z()) goto lab_p25_L_5024;
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 1)) == 0);
  if (flag_z()) { p25_L_4FB3(); return; }
  p00_L_3DA1();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  p25_L_4FB3();
  return;
  lab_p25_L_4FC6: ;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  cpu_push_af();
  a = 0;
  flag_logic(a);
  mem_write8(0x984B, a);
  mem_write8(0x84BF, a);
  p25_L_5053();
  if (flag_c()) goto lab_p25_L_4FF2;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  p25_L_5C21();
  p00_L_3F5D();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  cpu_pop_af();
  p00_L_03A4();
  p25_L_5087();
  goto lab_p25_L_5007;
  lab_p25_L_4FF2: ;
  p00_L_345F();
  if (flag_z()) goto lab_p25_L_4FFD;
  p00_L_07DE();
  if (flag_z()) p00_L_0745();
  lab_p25_L_4FFD: ;
  cpu_pop_af();
  p00_L_03A4();
  p25_L_5087();
  p25_L_5004();
  return;
  lab_p25_L_5007: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  p25_L_5BE3();
  p25_L_5BFC();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  p25_L_5216();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p25_L_52B8();
  p25_L_4EF3();
  if (flag_z()) goto lab_p25_L_5026;
  lab_p25_L_5024: ;
  /* scf */
  return;
  lab_p25_L_5026: ;
  a = 0xAA;
  mem_write8(0x8477, a);
  lab_p25_L_502B: ;
  p00_L_3F21();
  p00_L_0189();
  if (flag_z()) goto lab_p25_L_503B;
  p25_L_5C15();
  p00_L_3EF1();
  goto lab_p25_L_504D;
  lab_p25_L_503B: ;
  flag_cmp(a, 0x09);
  if (flag_z()) goto lab_p25_L_502B;
  flag_cmp(a, 0x40);
  if (flag_c()) goto lab_p25_L_5048;
  flag_cmp(a, 0x5A);
  if (flag_c()) goto lab_p25_L_502B;
  lab_p25_L_5048: ;
  p25_L_5509();
  if (flag_c()) goto lab_p25_L_502B;
  lab_p25_L_504D: ;
  a = 0xF0;
  mem_write8(0x8477, a);
  return;
}

/* flash page 25 cpu 0x4EB6 (offset 0x0EB6) */
void p25_L_4EB6(void) {
  flag_cmp(a, 0x40);
  if (flag_c()) goto lab_p25_L_52AC;
  flag_cmp(a, 0x5A);
  if (flag_c()) p25_L_51D6();
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p25_L_4ED2;
  flag_cmp(a, 0x5A);
  if (flag_z()) goto lab_p25_L_4ECC;
  flag_cmp(a, 0x5A);
  if (flag_nc()) goto lab_p25_L_4ED2;
  lab_p25_L_4ECC: ;
  p25_L_4F43();
  if (flag_z()) { p25_L_58A3(); return; }
  lab_p25_L_4ED2: ;
  p25_L_585B();
  return;
  lab_p25_L_52AC: ;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 25 cpu 0x4ED5 (offset 0x0ED5) */
void p25_L_4ED5(void) {
  b = a;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x45);
  a = b;
  return;
}

/* flash page 25 cpu 0x4EDD (offset 0x0EDD) */
void p25_L_4EDD(void) {
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x0D);
  return;
}

/* flash page 25 cpu 0x4EE3 (offset 0x0EE3) */
void p25_L_4EE3(void) {
  a = 0x45;
  mem_write8(0x85DE, a);
  return;
}

/* flash page 25 cpu 0x4EE9 (offset 0x0EE9) */
void p25_L_4EE9(void) {
  b = a;
  a = mem_read8(0x85DE);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p25_L_4EF1;
  a = 0;
  flag_logic(a);
  lab_p25_L_4EF1: ;
  a = b;
  return;
}

/* flash page 25 cpu 0x4EF3 (offset 0x0EF3) */
void p25_L_4EF3(void) {
  b = a;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x13);
  a = b;
  return;
}

/* flash page 25 cpu 0x4EFB (offset 0x0EFB) */
void p25_L_4EFB(void) {
  b = a;
  a = mem_read8(0x85DE);
  p25_L_4EFF();
  return;
}

/* flash page 25 cpu 0x4EFF (offset 0x0EFF) */
void p25_L_4EFF(void) {
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x29);
  goto lab_p25_L_4F41;
  lab_p25_L_4F41: ;
  a = b;
  return;
}

/* flash page 25 cpu 0x4F07 (offset 0x0F07) */
void p25_L_4F07(void) {
  b = a;
  a = mem_read8(0x85DE);
  p25_L_4F0B();
  return;
}

/* flash page 25 cpu 0x4F0B (offset 0x0F0B) */
void p25_L_4F0B(void) {
  flag_cmp(a, 0x20);
  goto lab_p25_L_4F41;
  lab_p25_L_4F41: ;
  a = b;
  return;
}

/* flash page 25 cpu 0x4F0F (offset 0x0F0F) */
void p25_L_4F0F(void) {
  b = a;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x41);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x43);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x36);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x35);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x34);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x33);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x42);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x37);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x38);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x32);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x31);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x30);
  lab_p25_L_4F41: ;
  a = b;
  return;
}

/* flash page 25 cpu 0x4F2C (offset 0x0F2C) */
void p25_L_4F2C(void) {
  b = d;
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x37);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x38);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x32);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x31);
  if (flag_z()) goto lab_p25_L_4F41;
  flag_cmp(a, 0x30);
  lab_p25_L_4F41: ;
  a = b;
  return;
}

/* flash page 25 cpu 0x4F43 (offset 0x0F43) */
void p25_L_4F43(void) {
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x41);
  a = b;
  if (flag_nz()) return;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p25_L_4F5B;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p25_L_4F5B;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p25_L_4F5B;
  a = 0;
  flag_logic(a);
  lab_p25_L_4F5B: ;
  a = a | a;
  flag_logic(a);
  a = b;
  return;
}

/* flash page 25 cpu 0x4F5E (offset 0x0F5E) */
void p25_L_4F5E(void) {
  goto lab_p25_L_4F5E;
  lab_p25_L_4F4B: ;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p25_L_4F5B;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p25_L_4F5B;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p25_L_4F5B;
  a = 0;
  flag_logic(a);
  lab_p25_L_4F5B: ;
  a = a | a;
  flag_logic(a);
  a = b;
  return;
  lab_p25_L_4F5E: ;
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x41);
  a = b;
  if (flag_nz()) return;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x11);
  if (flag_z()) goto lab_p25_L_4F5B;
  goto lab_p25_L_4F4B;
}

/* flash page 25 cpu 0x4F6F (offset 0x0F6F) */
void p25_L_4F6F(void) {
  flag_cmp(a, 0x3D);
  if (flag_nc()) return;
  flag_cmp(a, 0x2B);
  /* ccf */
  return;
}

/* flash page 25 cpu 0x4FB3 (offset 0x0FB3) */
void p25_L_4FB3(void) {
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  p25_L_6925();
  p00_L_03A4();
  p25_L_5087();
  goto lab_p25_L_5015;
  lab_p25_L_5015: ;
  p25_L_5216();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p25_L_52B8();
  p25_L_4EF3();
  if (flag_z()) goto lab_p25_L_5026;
  /* scf */
  return;
  lab_p25_L_5026: ;
  a = 0xAA;
  mem_write8(0x8477, a);
  lab_p25_L_502B: ;
  p00_L_3F21();
  p00_L_0189();
  if (flag_z()) goto lab_p25_L_503B;
  p25_L_5C15();
  p00_L_3EF1();
  goto lab_p25_L_504D;
  lab_p25_L_503B: ;
  flag_cmp(a, 0x09);
  if (flag_z()) goto lab_p25_L_502B;
  flag_cmp(a, 0x40);
  if (flag_c()) goto lab_p25_L_5048;
  flag_cmp(a, 0x5A);
  if (flag_c()) goto lab_p25_L_502B;
  lab_p25_L_5048: ;
  p25_L_5509();
  if (flag_c()) goto lab_p25_L_502B;
  lab_p25_L_504D: ;
  a = 0xF0;
  mem_write8(0x8477, a);
  return;
}

/* flash page 25 cpu 0x5004 (offset 0x1004) */
void p25_L_5004(void) {
  p00_L_3D71();
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  p25_L_5BE3();
  p25_L_5BFC();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  p25_L_5216();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p25_L_52B8();
  p25_L_4EF3();
  if (flag_z()) goto lab_p25_L_5026;
  /* scf */
  return;
  lab_p25_L_5026: ;
  a = 0xAA;
  mem_write8(0x8477, a);
  lab_p25_L_502B: ;
  p00_L_3F21();
  p00_L_0189();
  if (flag_z()) goto lab_p25_L_503B;
  p25_L_5C15();
  p00_L_3EF1();
  goto lab_p25_L_504D;
  lab_p25_L_503B: ;
  flag_cmp(a, 0x09);
  if (flag_z()) goto lab_p25_L_502B;
  flag_cmp(a, 0x40);
  if (flag_c()) goto lab_p25_L_5048;
  flag_cmp(a, 0x5A);
  if (flag_c()) goto lab_p25_L_502B;
  lab_p25_L_5048: ;
  p25_L_5509();
  if (flag_c()) goto lab_p25_L_502B;
  lab_p25_L_504D: ;
  a = 0xF0;
  mem_write8(0x8477, a);
  return;
}

/* flash page 25 cpu 0x5053 (offset 0x1053) */
void p25_L_5053(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p25_L_5065;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x57);
  if (flag_z()) return;
  flag_cmp(a, 0x4B);
  if (flag_z()) return;
  flag_cmp(a, 0x45);
  if (flag_z()) return;
  lab_p25_L_5065: ;
  /* scf */
  return;
}

/* flash page 25 cpu 0x5055 (offset 0x1055) */
void p25_L_5055(void) {
  set_hl((uint16_t)(hl() + bc()));
  b = mem_read8(hl());
  if (flag_z()) goto lab_p25_L_5065;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x57);
  if (flag_z()) return;
  flag_cmp(a, 0x4B);
  if (flag_z()) return;
  flag_cmp(a, 0x45);
  if (flag_z()) return;
  lab_p25_L_5065: ;
  /* scf */
  return;
}

/* flash page 25 cpu 0x5067 (offset 0x1067) */
void p25_L_5067(void) {
  l = 0x00;
  p25_L_5069();
  return;
}

/* flash page 25 cpu 0x5069 (offset 0x1069) */
void p25_L_5069(void) {
  goto lab_p25_L_5069;
  lab_p25_L_5015: ;
  p25_L_5216();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p25_L_52B8();
  p25_L_4EF3();
  if (flag_z()) goto lab_p25_L_5026;
  /* scf */
  return;
  lab_p25_L_5026: ;
  a = 0xAA;
  mem_write8(0x8477, a);
  lab_p25_L_502B: ;
  p00_L_3F21();
  p00_L_0189();
  if (flag_z()) goto lab_p25_L_503B;
  p25_L_5C15();
  p00_L_3EF1();
  goto lab_p25_L_504D;
  lab_p25_L_503B: ;
  flag_cmp(a, 0x09);
  if (flag_z()) goto lab_p25_L_502B;
  flag_cmp(a, 0x40);
  if (flag_c()) goto lab_p25_L_5048;
  flag_cmp(a, 0x5A);
  if (flag_c()) goto lab_p25_L_502B;
  lab_p25_L_5048: ;
  p25_L_5509();
  if (flag_c()) goto lab_p25_L_502B;
  lab_p25_L_504D: ;
  a = 0xF0;
  mem_write8(0x8477, a);
  return;
  lab_p25_L_5069: ;
  h = 0x00;
  p25_L_4EE9();
  if (flag_z()) goto lab_p25_L_5075;
  p25_L_50C6();
  goto lab_p25_L_5015;
  lab_p25_L_5075: ;
  cpu_push_af();
  a = 0;
  flag_logic(a);
  mem_write8(0x984B, a);
  mem_write8(0x984C, a);
  cpu_pop_af();
  p00_L_03A4();
  p25_L_50C6();
  p25_L_5004();
  return;
}

/* flash page 25 cpu 0x5087 (offset 0x1087) */
void p25_L_5087(void) {
  a = (uint8_t)(a - 0x2A);
  flag_cmp(a, 0x11);
  if (flag_nz()) goto lab_p25_L_50A3;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p25_L_50A3;
  a = (uint8_t)(a + 0x28);
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p25_L_50A3;
  a = (uint8_t)(a + 1);
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p25_L_50A3;
  a = (uint8_t)(a + 1);
  lab_p25_L_50A3: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p25_L_50C3;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p25_L_50C1;
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p25_L_50C1;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p25_L_50C1;
  flag_cmp(a, 0x07);
  if (flag_z()) goto lab_p25_L_50C1;
  flag_cmp(a, 0x08);
  if (flag_z()) goto lab_p25_L_50C1;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p25_L_50C3;
  lab_p25_L_50C1: ;
  a = (uint8_t)(a + 0x27);
  lab_p25_L_50C3: ;
  set_hl(0x0000);
  p25_L_50C6();
  return;
}

/* flash page 25 cpu 0x50C6 (offset 0x10C6) */
void p25_L_50C6(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p25_L_50D4;
  b = a;
  a = 0x04;
  p00_L_2D15();
  if (flag_nz()) return;
  a = b;
  lab_p25_L_50D4: ;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 5)));
  mem_write16(0x85DF, hl());
  mem_write8(0x85DE, a);
  p25_L_51FC();
  a = mem_read8(hl());
  mem_write8(0x85E1, a);
  p25_L_50E5();
  return;
}

/* flash page 25 cpu 0x50E5 (offset 0x10E5) */
void p25_L_50E5(void) {
  a = mem_read8(0x85DF);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p25_L_5103;
  b = a;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x13);
  if (flag_nz()) goto lab_p25_L_50FB;
  p00_L_22FC();
  a = mem_read8(0x8478);
  goto lab_p25_L_5100;
  lab_p25_L_50FB: ;
  b = (uint8_t)(b + 1);
  lab_p25_L_50FC: ;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_50FC;
  a = mem_read8(hl());
  lab_p25_L_5100: ;
  mem_write8(0x85E2, a);
  lab_p25_L_5103: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x85E0, a);
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 5)));
  a = mem_read8(0x85E2);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x31);
  if (flag_z()) return;
  flag_cmp(a, 0x40);
  if (flag_z()) return;
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p25_L_5122;
  p25_L_5D61();
  goto lab_p25_L_5153;
  lab_p25_L_5122: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p25_L_5145;
  p25_L_5E80();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 5)));
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) | (1u << 0)));
  p00_L_10DD();
  p25_L_5E8D();
  p25_L_5EB0();
  p00_L_2DAB();
  a = c;
  set_hl(0x85E2);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  /* add a,(hl) */
  mem_write8(hl(), a);
  return;
  lab_p25_L_5145: ;
  flag_cmp(a, 0x28);
  if (flag_nz()) goto lab_p25_L_5150;
  a = 0x17;
  p25_L_5D87();
  goto lab_p25_L_5153;
  lab_p25_L_5150: ;
  p25_L_5D96();
  lab_p25_L_5153: ;
  if (flag_c()) return;
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 5)));
  p00_L_10DD();
  p25_L_5E8D();
  p25_L_5EB0();
  set_hl(mem_read16(0x9830));
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  flag_cmp(a, 0x09);
  if (flag_z()) goto lab_p25_L_51C0;
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p25_L_51C0;
  flag_cmp(a, 0x17);
  if (flag_nz()) goto lab_p25_L_5183;
  p00_L_1037();
  flag_cmp(a, 0x17);
  if (flag_nz()) goto lab_p25_L_51C0;
  goto lab_p25_L_5196;
  lab_p25_L_5183: ;
  p00_L_17BE();
  if (flag_nz()) goto lab_p25_L_519E;
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p25_L_5191;
  p25_L_5FB3();
  if (flag_z()) goto lab_p25_L_51C0;
  lab_p25_L_5191: ;
  p00_L_17BB();
  if (flag_nz()) goto lab_p25_L_51C0;
  lab_p25_L_5196: ;
  a = mem_read8(hl());
  lab_p25_L_5197: ;
  p00_L_2D93();
  if (flag_c()) goto lab_p25_L_51C0;
  goto lab_p25_L_51B4;
  lab_p25_L_519E: ;
  p00_L_1037();
  p00_L_1830();
  if (flag_nz()) goto lab_p25_L_51C0;
  a = mem_read8(hl());
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p25_L_51C0;
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, 0x06);
  if (flag_c()) goto lab_p25_L_51B4;
  goto lab_p25_L_5197;
  lab_p25_L_51B4: ;
  cpu_push_hl();
  set_hl(0x85E2);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  if (flag_nz()) goto lab_p25_L_51BF;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  cpu_pop_hl();
  goto lab_p25_L_51D2;
  lab_p25_L_51BF: ;
  cpu_pop_hl();
  lab_p25_L_51C0: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = (uint8_t)(a + 1);
  e = a;
  d = 0x00;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  set_de(mem_read16(0x982E));
  p25_L_51CD();
  return;
  lab_p25_L_51D2: ;
  p25_L_5E77();
  return;
}

/* flash page 25 cpu 0x51CD (offset 0x11CD) */
void p25_L_51CD(void) {
  goto lab_p25_L_51CD;
  lab_p25_L_5164: ;
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  flag_cmp(a, 0x09);
  if (flag_z()) goto lab_p25_L_51C0;
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p25_L_51C0;
  flag_cmp(a, 0x17);
  if (flag_nz()) goto lab_p25_L_5183;
  p00_L_1037();
  flag_cmp(a, 0x17);
  if (flag_nz()) goto lab_p25_L_51C0;
  goto lab_p25_L_5196;
  lab_p25_L_5183: ;
  p00_L_17BE();
  if (flag_nz()) goto lab_p25_L_519E;
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p25_L_5191;
  p25_L_5FB3();
  if (flag_z()) goto lab_p25_L_51C0;
  lab_p25_L_5191: ;
  p00_L_17BB();
  if (flag_nz()) goto lab_p25_L_51C0;
  lab_p25_L_5196: ;
  a = mem_read8(hl());
  lab_p25_L_5197: ;
  p00_L_2D93();
  if (flag_c()) goto lab_p25_L_51C0;
  goto lab_p25_L_51B4;
  lab_p25_L_519E: ;
  p00_L_1037();
  p00_L_1830();
  if (flag_nz()) goto lab_p25_L_51C0;
  a = mem_read8(hl());
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p25_L_51C0;
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, 0x06);
  if (flag_c()) goto lab_p25_L_51B4;
  goto lab_p25_L_5197;
  lab_p25_L_51B4: ;
  cpu_push_hl();
  set_hl(0x85E2);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  if (flag_nz()) goto lab_p25_L_51BF;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  cpu_pop_hl();
  goto lab_p25_L_51D2;
  lab_p25_L_51BF: ;
  cpu_pop_hl();
  lab_p25_L_51C0: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = (uint8_t)(a + 1);
  e = a;
  d = 0x00;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  set_de(mem_read16(0x982E));
  lab_p25_L_51CD: ;
  p00_L_192A();
  if (flag_nz()) goto lab_p25_L_5164;
  lab_p25_L_51D2: ;
  p25_L_5E77();
  return;
}

/* flash page 25 cpu 0x51D6 (offset 0x11D6) */
void p25_L_51D6(void) {
  cpu_push_af();
  p25_L_5053();
  if (flag_c()) goto lab_p25_L_51FA;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p25_L_51F1;
  a = 0x04;
  mem_write8(0x97A5, a);
  p00_L_3E43();
  p00_L_3E55();
  lab_p25_L_51F1: ;
  p25_L_5C21();
  p00_L_3EF1();
  p00_L_3F5D();
  lab_p25_L_51FA: ;
  cpu_pop_af();
  return;
}

/* flash page 25 cpu 0x51FC (offset 0x11FC) */
void p25_L_51FC(void) {
  a = 0x00;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_2D15();
  if (flag_nz()) return;
  a = mem_read8(0x85DE);
  set_hl(0x6177);
  /* sla a */
  d = 0x00;
  e = a;
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  return;
}

/* flash page 25 cpu 0x5216 (offset 0x1216) */
void p25_L_5216(void) {
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x20);
  a = 0x01;
  if (flag_nz()) goto lab_p25_L_5220;
  a = (uint8_t)(a + 1);
  lab_p25_L_5220: ;
  mem_write8(0x984A, a);
  p00_L_3E43();
  a = 0;
  flag_logic(a);
  p25_L_5257();
  return;
}

/* flash page 25 cpu 0x5229 (offset 0x1229) */
void p25_L_5229(void) {
  set_hl(0x984A);
  a = mem_read8(0x844B);
  /* sub (hl) */
  b = a;
  a = mem_read8(0x85E0);
  a = (uint8_t)(a - b);
  if (flag_c()) goto lab_p25_L_524C;
  p25_L_5237();
  return;
  lab_p25_L_524C: ;
  p00_L_3E43();
  cpu_pop_hl();
  cpu_pop_af();
  a = 0x06;
  cpu_push_af();
  cpu_push_hl();
  a = 0x01;
  p25_L_5257();
  return;
}

/* flash page 25 cpu 0x5237 (offset 0x1237) */
void p25_L_5237(void) {
  c = a;
  cpu_push_bc();
  p25_L_5399();
  a = mem_read8(0x984A);
  a = (uint8_t)(a - 1);
  mem_write8(0x844B, a);
  cpu_pop_bc();
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p25_L_52AE;
  goto lab_p25_L_5279;
  lab_p25_L_5279: ;
  a = mem_read8(0x85E2);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_5294;
  a = c;
  /* sla a */
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  p25_L_53B5();
  a = mem_read8(0x984A);
  goto lab_p25_L_5290;
  lab_p25_L_528E: ;
  a = 0x01;
  lab_p25_L_5290: ;
  mem_write8(0x844B, a);
  return;
  lab_p25_L_5294: ;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p25_L_529F;
  flag_cmp(a, 0x31);
  if (flag_nz()) goto lab_p25_L_528E;
  lab_p25_L_529F: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x85DE, a);
  p25_L_5C15();
  p00_L_3EF1();
  cpu_pop_hl();
  a = 0x02;
  a = a | a;
  flag_logic(a);
  return;
  lab_p25_L_52AE: ;
  p25_L_5E4C();
  goto lab_p25_L_528E;
}

/* flash page 25 cpu 0x5257 (offset 0x1257) */
void p25_L_5257(void) {
  c = a;
  cpu_push_bc();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p00_L_3D1D();
  p25_L_60B2();
  if (flag_nz()) goto lab_p25_L_526C;
  p00_L_2E4D();
  goto lab_p25_L_526F;
  lab_p25_L_526C: ;
  p25_L_52F0();
  lab_p25_L_526F: ;
  p25_L_5399();
  cpu_pop_bc();
  p25_L_5273();
  return;
}

/* flash page 25 cpu 0x5273 (offset 0x1273) */
void p25_L_5273(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p25_L_52B3;
  a = mem_read8(0x85E2);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_5294;
  a = c;
  /* sla a */
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  p25_L_53B5();
  a = mem_read8(0x984A);
  goto lab_p25_L_5290;
  lab_p25_L_528E: ;
  a = 0x01;
  lab_p25_L_5290: ;
  mem_write8(0x844B, a);
  return;
  lab_p25_L_5294: ;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p25_L_529F;
  flag_cmp(a, 0x31);
  if (flag_nz()) goto lab_p25_L_528E;
  lab_p25_L_529F: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x85DE, a);
  p25_L_5C15();
  p00_L_3EF1();
  cpu_pop_hl();
  a = 0x02;
  a = a | a;
  flag_logic(a);
  return;
  lab_p25_L_52B3: ;
  p25_L_5DF7();
  goto lab_p25_L_528E;
}

/* flash page 25 cpu 0x5284 (offset 0x1284) */
void p25_L_5284(void) {
  /* nop */
  set_hl((uint16_t)(hl() + de()));
  p25_L_53B5();
  a = mem_read8(0x984A);
  goto lab_p25_L_5290;
  lab_p25_L_5290: ;
  mem_write8(0x844B, a);
  return;
}

/* flash page 25 cpu 0x52B8 (offset 0x12B8) */
void p25_L_52B8(void) {
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x23);
  if (flag_c()) goto lab_p25_L_52DF;
  flag_cmp(a, 0x28);
  if (flag_nc()) goto lab_p25_L_52DF;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x0004);
  a = (uint8_t)(a - 0x23);
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p25_L_52D2;
  l = 0x03;
  lab_p25_L_52D2: ;
  mem_write16(0x844B, hl());
  a = (uint8_t)(a + 0x16);
  lab_p25_L_52D7: ;
  p00_L_3BAF();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
  lab_p25_L_52DF: ;
  flag_cmp(a, 0x38);
  if (flag_nz()) return;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x0004);
  mem_write16(0x844B, hl());
  a = 0x1B;
  goto lab_p25_L_52D7;
}

/* flash page 25 cpu 0x52F0 (offset 0x12F0) */
void p25_L_52F0(void) {
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x13);
  if (flag_nz()) goto lab_p25_L_531D;
  set_hl(mem_read16(0x9311));
  p00_rst20();
  cpu_push_hl();
  ix = cpu_pop16();
  p00_L_2413();
  if (flag_c()) { p00_L_24DD(); return; }
  set_hl(0x8483);
  p00_L_2D81();
  a = 0;
  flag_logic(a);
  mem_write8(0x8493, a);
  set_hl(0x8483);
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  p00_L_3C87();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  return;
  lab_p25_L_531D: ;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x20);
  if (flag_nz()) goto lab_p25_L_5361;
  set_hl(0x265D);
  a = 0x03;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_343B();
  a = 0x0B;
  mem_write8(0x844C, a);
  p00_L_19B0();
  p00_L_3C7B();
  set_hl(0x0001);
  mem_write16(0x844B, hl());
  set_hl(0x2666);
  a = 0x04;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_343B();
  a = 0x0A;
  mem_write8(0x844C, a);
  p00_L_2EA1();
  a = 0x07;
  p00_L_3C75();
  return;
  lab_p25_L_5361: ;
  p25_L_51FC();
  b = mem_read8(hl());
  lab_p25_L_5365: ;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_5365;
  set_hl((uint16_t)(hl() + 1));
  c = 0x00;
  lab_p25_L_536B: ;
  a = mem_read8(0x85DF);
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p25_L_5375;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  lab_p25_L_5375: ;
  cpu_push_hl();
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_2D15();
  if (flag_nz()) goto lab_p25_L_5385;
  a = mem_read8(hl());
  p00_L_3BAF();
  lab_p25_L_5385: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  cpu_pop_hl();
  c = (uint8_t)(c + 1);
  a = mem_read8(0x85E1);
  flag_cmp(a, c);
  if (flag_z()) return;
  if (flag_c()) return;
  a = 0x20;
  p00_L_3F9F();
  set_hl((uint16_t)(hl() + 1));
  goto lab_p25_L_536B;
}

/* flash page 25 cpu 0x5384 (offset 0x1384) */
void p25_L_5384(void) {
  goto lab_p25_L_5384;
  lab_p25_L_536B: ;
  a = mem_read8(0x85DF);
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p25_L_5375;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  lab_p25_L_5375: ;
  cpu_push_hl();
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_2D15();
  if (flag_nz()) goto lab_p25_L_5385;
  a = mem_read8(hl());
  p00_L_3BAF();
  lab_p25_L_5384: ;
  sp = (uint16_t)(sp - 1);
  lab_p25_L_5385: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  cpu_pop_hl();
  c = (uint8_t)(c + 1);
  a = mem_read8(0x85E1);
  flag_cmp(a, c);
  if (flag_z()) return;
  if (flag_c()) return;
  a = 0x20;
  p00_L_3F9F();
  set_hl((uint16_t)(hl() + 1));
  goto lab_p25_L_536B;
}

/* flash page 25 cpu 0x5399 (offset 0x1399) */
void p25_L_5399(void) {
  p25_L_51FC();
  a = mem_read8(0x85DF);
  a = a | a;
  flag_logic(a);
  b = a;
  a = mem_read8(hl());
  c = a;
  if (flag_z()) goto lab_p25_L_53AB;
  cpu_push_hl();
  lab_p25_L_53A6: ;
  set_hl((uint16_t)(hl() + 1));
  /* add a,(hl) */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_53A6;
  cpu_pop_hl();
  lab_p25_L_53AB: ;
  /* sla a */
  a = (uint8_t)(a - c);
  /* add a,(hl) */
  set_hl((uint16_t)(hl() + 1));
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 25 cpu 0x53B5 (offset 0x13B5) */
void p25_L_53B5(void) {
  a = mem_read8(0x984A);
  lab_p25_L_53B8: ;
  mem_write8(0x844B, a);
  p25_L_53D9();
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  cpu_push_bc();
  p25_L_545D();
  cpu_pop_bc();
  cpu_pop_hl();
  c = (uint8_t)(c + 1);
  a = mem_read8(0x85E2);
  flag_cmp(a, c);
  if (flag_z()) return;
  if (flag_c()) return;
  a = mem_read8(0x844B);
  flag_cmp(a, 0x07);
  if (flag_z()) return;
  a = (uint8_t)(a + 1);
  goto lab_p25_L_53B8;
}

/* flash page 25 cpu 0x53D9 (offset 0x13D9) */
void p25_L_53D9(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = mem_read8(0x85E0);
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p25_L_53E7;
  p25_L_53E3();
  return;
  lab_p25_L_53E7: ;
  b = 0x31;
  a = c;
  e = a;
  flag_cmp(a, 0x09);
  if (flag_c()) goto lab_p25_L_542C;
  if (flag_nz()) goto lab_p25_L_53FD;
  a = 0x30;
  goto lab_p25_L_542D;
  lab_p25_L_53F5: ;
  a = 0x20;
  goto lab_p25_L_542D;
  lab_p25_L_53F9: ;
  a = 0x5B;
  goto lab_p25_L_542D;
  lab_p25_L_53FD: ;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p25_L_53F5;
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p25_L_53F5;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p25_L_53F5;
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p25_L_5418;
  a = mem_read8(0x85DF);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_53F5;
  goto lab_p25_L_5423;
  lab_p25_L_5418: ;
  flag_cmp(a, 0x2A);
  if (flag_nz()) goto lab_p25_L_5423;
  a = mem_read8(0x85DF);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p25_L_53F5;
  lab_p25_L_5423: ;
  a = e;
  b = 0x37;
  flag_cmp(a, 0x24);
  if (flag_z()) goto lab_p25_L_53F9;
  if (flag_nc()) goto lab_p25_L_53F5;
  lab_p25_L_542C: ;
  a = (uint8_t)(a + b);
  lab_p25_L_542D: ;
  p00_L_3F9F();
  cpu_push_bc();
  a = mem_read8(0x984A);
  b = a;
  a = mem_read8(0x844B);
  flag_cmp(a, b);
  cpu_pop_bc();
  if (flag_nz()) goto lab_p25_L_5444;
  a = e;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_5453;
  a = 0x1E;
  goto lab_p25_L_5455;
  lab_p25_L_5444: ;
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p25_L_5453;
  a = mem_read8(0x85E2);
  a = (uint8_t)(a - 1);
  flag_cmp(a, e);
  a = 0x1F;
  if (flag_z()) goto lab_p25_L_5453;
  if (flag_nc()) goto lab_p25_L_5455;
  lab_p25_L_5453: ;
  a = 0x3A;
  lab_p25_L_5455: ;
  p00_L_3F9F();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  return;
}

/* flash page 25 cpu 0x53E3 (offset 0x13E3) */
void p25_L_53E3(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  b = 0x31;
  a = c;
  e = a;
  flag_cmp(a, 0x09);
  if (flag_c()) goto lab_p25_L_542C;
  if (flag_nz()) goto lab_p25_L_53FD;
  a = 0x30;
  goto lab_p25_L_542D;
  lab_p25_L_53F5: ;
  a = 0x20;
  goto lab_p25_L_542D;
  lab_p25_L_53F9: ;
  a = 0x5B;
  goto lab_p25_L_542D;
  lab_p25_L_53FD: ;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p25_L_53F5;
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p25_L_53F5;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p25_L_53F5;
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p25_L_5418;
  a = mem_read8(0x85DF);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_53F5;
  goto lab_p25_L_5423;
  lab_p25_L_5418: ;
  flag_cmp(a, 0x2A);
  if (flag_nz()) goto lab_p25_L_5423;
  a = mem_read8(0x85DF);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p25_L_53F5;
  lab_p25_L_5423: ;
  a = e;
  b = 0x37;
  flag_cmp(a, 0x24);
  if (flag_z()) goto lab_p25_L_53F9;
  if (flag_nc()) goto lab_p25_L_53F5;
  lab_p25_L_542C: ;
  a = (uint8_t)(a + b);
  lab_p25_L_542D: ;
  p00_L_3F9F();
  cpu_push_bc();
  a = mem_read8(0x984A);
  b = a;
  a = mem_read8(0x844B);
  flag_cmp(a, b);
  cpu_pop_bc();
  if (flag_nz()) goto lab_p25_L_5444;
  a = e;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_5453;
  a = 0x1E;
  goto lab_p25_L_5455;
  lab_p25_L_5444: ;
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p25_L_5453;
  a = mem_read8(0x85E2);
  a = (uint8_t)(a - 1);
  flag_cmp(a, e);
  a = 0x1F;
  if (flag_z()) goto lab_p25_L_5453;
  if (flag_nc()) goto lab_p25_L_5455;
  lab_p25_L_5453: ;
  a = 0x3A;
  lab_p25_L_5455: ;
  p00_L_3F9F();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  return;
}

/* flash page 25 cpu 0x545D (offset 0x145D) */
void p25_L_545D(void) {
  a = d;
  flag_cmp(a, 0x1F);
  if (flag_nz()) goto lab_p25_L_548D;
  cpu_push16(ix);
  cpu_pop_hl();
  p00_rst20();
  p00_L_11F8();
  cpu_push_hl();
  ix = cpu_pop16();
  p00_L_2413();
  if (flag_c()) { p00_L_24DD(); return; }
  set_hl(0x8483);
  p00_L_2D81();
  a = 0;
  flag_logic(a);
  mem_write8(0x8491, a);
  set_hl(0x8483);
  p00_L_3C87();
  a = mem_read8(0x844C);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p25_L_54D6;
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  return;
  lab_p25_L_548D: ;
  flag_cmp(a, 0x82);
  if (flag_nz()) goto lab_p25_L_5499;
  a = e;
  a = (uint8_t)(a - 0x3D);
  p00_L_3BAF();
  goto lab_p25_L_54D6;
  lab_p25_L_5499: ;
  cpu_push_de();
  p25_L_68DD();
  cpu_pop_de();
  cpu_push_de();
  a = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_2D15();
  if (flag_nz()) goto lab_p25_L_54B7;
  a = d;
  flag_cmp(a, 0xFD);
  if (flag_nz()) goto lab_p25_L_54B1;
  d = 0x00;
  lab_p25_L_54B1: ;
  p00_L_3BC1();
  p00_L_3C8D();
  lab_p25_L_54B7: ;
  cpu_pop_de();
  p25_L_54DF();
  if (flag_c()) goto lab_p25_L_54C1;
  p00_L_329D();
  return;
  lab_p25_L_54C1: ;
  a = d;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p25_L_54D6;
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p25_L_54D6;
  a = e;
  flag_cmp(a, 0x55);
  if (flag_nz()) goto lab_p25_L_54D6;
  p00_L_3D1D();
  p00_L_314D();
  return;
  lab_p25_L_54D6: ;
  a = mem_read8(0x844C);
  flag_cmp(a, 0x0F);
  if (flag_c()) p00_L_3D1D();
  return;
}

/* flash page 25 cpu 0x54DF (offset 0x14DF) */
void p25_L_54DF(void) {
  a = d;
  flag_cmp(a, 0xFC);
  if (flag_nz()) goto lab_p25_L_54EF;
  a = e;
  flag_cmp(a, 0x41);
  if (flag_nc()) goto lab_p25_L_5507;
  a = (uint8_t)(a - 0x3C);
  if (flag_c()) return;
  a = (uint8_t)(a + 0x05);
  return;
  lab_p25_L_54EF: ;
  flag_cmp(a, 0xFE);
  a = e;
  if (flag_nz()) goto lab_p25_L_54FC;
  flag_cmp(a, 0x82);
  if (flag_nc()) goto lab_p25_L_5507;
  a = (uint8_t)(a - 0x7D);
  if (flag_c()) return;
  return;
  lab_p25_L_54FC: ;
  flag_cmp(a, 0x42);
  if (flag_nz()) goto lab_p25_L_5507;
  a = d;
  flag_cmp(a, 0x0A);
  if (flag_nc()) goto lab_p25_L_5507;
  a = a | a;
  flag_logic(a);
  return;
  lab_p25_L_5507: ;
  /* scf */
  return;
}

/* flash page 25 cpu 0x5509 (offset 0x1509) */
void p25_L_5509(void) {
  goto lab_p25_L_5509;
  lab_p25_L_5024: ;
  /* scf */
  return;
  lab_p25_L_5509: ;
  b = a;
  a = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_3123();
  a = b;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p25_L_554C;
  p25_L_60B2();
  if (flag_z()) { p25_L_5830(); return; }
  p25_L_4EFB();
  if (flag_z()) goto lab_p25_L_552E;
  p25_L_4F07();
  if (flag_z()) goto lab_p25_L_552E;
  p25_L_4F0F();
  if (flag_nz()) goto lab_p25_L_5533;
  lab_p25_L_552E: ;
  a = 0x40;
  p25_L_5830();
  return;
  lab_p25_L_5533: ;
  a = mem_read8(0x984B);
  b = a;
  p25_L_4EFF();
  if (flag_z()) goto lab_p25_L_5541;
  p25_L_4F0B();
  if (flag_nz()) goto lab_p25_L_5546;
  lab_p25_L_5541: ;
  l = 0x00;
  p25_L_5069();
  return;
  lab_p25_L_5546: ;
  p25_L_58B7();
  p25_L_58A3();
  return;
  lab_p25_L_554C: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p25_L_5574;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p25_L_5562;
  flag_cmp(a, 0x2A);
  if (flag_z()) goto lab_p25_L_5562;
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p25_L_55DE;
  lab_p25_L_5562: ;
  set_hl(0x85DF);
  a = mem_read8(0x85E1);
  a = (uint8_t)(a - 1);
  if (flag_z()) { p25_L_58A3(); return; }
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  cpu_cp_hl();
  if (flag_nc()) goto lab_p25_L_5572;
  a = 0;
  flag_logic(a);
  mem_write8(hl(), a);
  lab_p25_L_5572: ;
  goto lab_p25_L_559B;
  lab_p25_L_5574: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p25_L_55AA;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p25_L_558A;
  flag_cmp(a, 0x2A);
  if (flag_z()) goto lab_p25_L_558A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p25_L_5681;
  lab_p25_L_558A: ;
  set_hl(0x85DF);
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p25_L_559A;
  a = mem_read8(0x85E1);
  flag_cmp(a, 0x01);
  if (flag_z()) { p25_L_58A3(); return; }
  mem_write8(hl(), a);
  lab_p25_L_559A: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  lab_p25_L_559B: ;
  p25_L_51FC();
  p25_L_50E5();
  p25_L_58AA();
  p25_L_5216();
  p25_L_58A3();
  return;
  lab_p25_L_55AA: ;
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p25_L_5640;
  a = mem_read8(0x85E2);
  set_hl(0x85E0);
  /* sub (hl) */
  set_hl(0x844B);
  /* add a,(hl) */
  flag_cmp(a, 0x09);
  if (flag_c()) goto lab_p25_L_55CD;
  a = mem_read8(0x85E0);
  set_hl(0x844B);
  /* sub (hl) */
  a = (uint8_t)(a + 0x07);
  mem_write8(0x85E0, a);
  p25_L_5660();
  return;
  lab_p25_L_55CD: ;
  a = 0x06;
  mem_write8(0x844D, a);
  lab_p25_L_55D2: ;
  p25_L_5695();
  set_hl(0x844D);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) goto lab_p25_L_55D2;
  p25_L_58A3();
  return;
  lab_p25_L_55DE: ;
  set_hl(0x85DF);
  a = mem_read8(0x85E1);
  a = (uint8_t)(a - 1);
  if (flag_z()) { p25_L_58A3(); return; }
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  cpu_cp_hl();
  if (flag_nc()) { p25_L_55EE(); return; }
  a = 0;
  flag_logic(a);
  mem_write8(hl(), a);
  p25_L_55EE();
  return;
  lab_p25_L_5640: ;
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p25_L_5724;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p25_L_5659;
  a = mem_read8(0x85E0);
  set_hl(0x844B);
  /* sub (hl) */
  a = (uint8_t)(a + 0x01);
  a = (uint8_t)(a - 0x07);
  if (flag_nc()) goto lab_p25_L_565C;
  lab_p25_L_5659: ;
  a = 0;
  flag_logic(a);
  p25_L_566C();
  return;
  lab_p25_L_565C: ;
  set_hl(0x984A);
  /* add a,(hl) */
  p25_L_5660();
  return;
  lab_p25_L_5681: ;
  set_hl(0x85DF);
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p25_L_5691;
  a = mem_read8(0x85E1);
  flag_cmp(a, 0x01);
  if (flag_z()) { p25_L_58A3(); return; }
  mem_write8(hl(), a);
  lab_p25_L_5691: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p25_L_55EE();
  return;
  lab_p25_L_5724: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p25_L_57DB;
  set_hl(0x85E0);
  p25_L_572C();
  return;
  lab_p25_L_57DB: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p25_L_57F9;
  set_hl(0x85E0);
  a = mem_read8(0x85E2);
  a = (uint8_t)(a - 1);
  /* sub (hl) */
  if (flag_z()) goto lab_p25_L_57EF;
  p25_L_5695();
  p25_L_58A3();
  return;
  lab_p25_L_57EF: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 0)) == 0);
  if (flag_nz()) { p25_L_58A3(); return; }
  p25_L_566C();
  return;
  lab_p25_L_57F9: ;
  flag_cmp(a, 0x5A);
  if (flag_nz()) goto lab_p25_L_580B;
  p25_L_60B2();
  if (flag_z()) goto lab_p25_L_5024;
  p25_L_4EF3();
  if (flag_z()) goto lab_p25_L_5024;
  p25_L_581C();
  return;
  lab_p25_L_580B: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p25_L_5F41;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p25_L_5868;
  a = mem_read8(0x85E0);
  p25_L_5D19();
  p25_L_581C();
  return;
  lab_p25_L_5868: ;
  b = 0x8F;
  flag_cmp(a, 0x8F);
  if (flag_c()) goto lab_p25_L_5872;
  flag_cmp(a, 0x98);
  if (flag_c()) goto lab_p25_L_5888;
  lab_p25_L_5872: ;
  b = 0x85;
  flag_cmp(a, 0x8E);
  if (flag_z()) goto lab_p25_L_5888;
  b = 0x90;
  flag_cmp(a, 0x9A);
  if (flag_c()) { p25_L_5890(); return; }
  flag_cmp(a, 0xB4);
  if (flag_c()) goto lab_p25_L_5888;
  b = 0xA8;
  flag_cmp(a, 0xCC);
  if (flag_nz()) { p25_L_5890(); return; }
  lab_p25_L_5888: ;
  a = (uint8_t)(a - b);
  p25_L_5D19();
  if (flag_c()) { p25_L_581C(); return; }
  p25_L_58A3();
  return;
  lab_p25_L_5F41: ;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p25_L_5FC6;
  p25_L_5DDE();
  if (flag_nz()) { p25_L_5F56(); return; }
  lab_p25_L_5F4B: ;
  a = 0x82;
  mem_write8(0x8446, a);
  c = a;
  a = 0x4C;
  p25_L_581C();
  return;
  lab_p25_L_5FC6: ;
  b = 0x8F;
  flag_cmp(a, 0x8F);
  if (flag_c()) goto lab_p25_L_5FD1;
  flag_cmp(a, 0x98);
  if (flag_c()) goto lab_p25_L_607B;
  lab_p25_L_5FD1: ;
  b = 0x85;
  flag_cmp(a, 0x8E);
  if (flag_z()) goto lab_p25_L_607B;
  b = 0x90;
  flag_cmp(a, 0x9A);
  if (flag_c()) { p25_L_5890(); return; }
  flag_cmp(a, 0xB4);
  if (flag_c()) goto lab_p25_L_5FEA;
  b = 0xA8;
  flag_cmp(a, 0xCC);
  if (flag_nz()) { p25_L_5890(); return; }
  lab_p25_L_5FEA: ;
  a = (uint8_t)(a - 0x9A);
  a = (uint8_t)(a + 0x41);
  flag_cmp(a, 0x5B);
  if (flag_c()) goto lab_p25_L_5FF4;
  a = 0x5B;
  lab_p25_L_5FF4: ;
  mem_write8(0x85F2, a);
  a = 0x01;
  mem_write8(0x844B, a);
  p25_L_5DD2();
  if (flag_nz()) goto lab_p25_L_6029;
  p25_L_5E80();
  a = mem_read8(0x85F2);
  a = (uint8_t)(a - 1);
  mem_write8(0x8479, a);
  a = 0xFF;
  mem_write8(0x847A, a);
  p25_L_5D6A();
  if (flag_c()) goto lab_p25_L_6017;
  goto lab_p25_L_601D;
  lab_p25_L_6017: ;
  p25_L_5D73();
  if (flag_c()) goto lab_p25_L_6023;
  b = (uint8_t)(b - 1);
  lab_p25_L_601D: ;
  set_hl(0x844B);
  a = b;
  /* add a,(hl) */
  mem_write8(hl(), a);
  lab_p25_L_6023: ;
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p25_L_605B;
  lab_p25_L_6029: ;
  p25_L_5D8B();
  if (flag_c()) goto lab_p25_L_605B;
  goto lab_p25_L_6039;
  lab_p25_L_6030: ;
  p25_L_5D9B();
  if (flag_c()) goto lab_p25_L_604E;
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p25_L_6039: ;
  set_hl(0x8479);
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p25_L_6044;
  set_hl((uint16_t)(hl() + 1));
  lab_p25_L_6044: ;
  a = mem_read8(0x85F2);
  cpu_cp_hl();
  if (flag_z()) goto lab_p25_L_605B;
  if (flag_nc()) goto lab_p25_L_6030;
  goto lab_p25_L_605B;
  lab_p25_L_604E: ;
  p25_L_5FB3();
  if (flag_nz()) goto lab_p25_L_605B;
  p00_L_1037();
  flag_cmp(a, 0x06);
  if (flag_z()) p25_L_5DB4();
  lab_p25_L_605B: ;
  p25_L_5EBD();
  a = mem_read8(0x844B);
  a = (uint8_t)(a - 1);
  mem_write8(0x85E0, a);
  a = mem_read8(0x984A);
  mem_write8(0x844B, a);
  p00_L_3D29();
  a = 0;
  flag_logic(a);
  mem_write8(0x844B, a);
  a = mem_read8(0x85E0);
  p25_L_5237();
  p25_L_58A3();
  return;
  lab_p25_L_607B: ;
  a = (uint8_t)(a - b);
  set_hl(0x85E2);
  cpu_cp_hl();
  if (flag_nc()) { p25_L_58A3(); return; }
  mem_write8(0x85E0, a);
  p25_L_5DD2();
  if (flag_nz()) goto lab_p25_L_6094;
  set_hl(0x85E0);
  a = 0;
  flag_logic(a);
  cpu_cp_hl();
  if (flag_z()) goto lab_p25_L_5F4B;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  lab_p25_L_6094: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x844B, a);
  p25_L_5D8B();
  goto lab_p25_L_60A1;
  lab_p25_L_609D: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p25_L_5D9B();
  lab_p25_L_60A1: ;
  if (flag_c()) goto lab_p25_L_60AC;
  set_hl(0x844B);
  a = mem_read8(0x85E0);
  cpu_cp_hl();
  if (flag_nz()) goto lab_p25_L_609D;
  lab_p25_L_60AC: ;
  p25_L_5E8D();
  p25_L_5F56();
  return;
}

/* flash page 25 cpu 0x55EE (offset 0x15EE) */
void p25_L_55EE(void) {
  p25_L_55FD();
  cpu_push_af();
  a = 0;
  flag_logic(a);
  mem_write8(0x85F2, a);
  cpu_pop_af();
  p25_L_562F();
  p25_L_58A3();
  return;
}

/* flash page 25 cpu 0x55FD (offset 0x15FD) */
void p25_L_55FD(void) {
  p25_L_51FC();
  a = mem_read8(0x85E0);
  cpu_push_af();
  p25_L_50E5();
  cpu_pop_af();
  set_hl(0x85E2);
  cpu_cp_hl();
  if (flag_c()) goto lab_p25_L_5613;
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_5613;
  a = (uint8_t)(a - 1);
  lab_p25_L_5613: ;
  mem_write8(0x85E0, a);
  a = (uint8_t)(a - 0x06);
  if (flag_nc()) goto lab_p25_L_561B;
  a = 0;
  flag_logic(a);
  lab_p25_L_561B: ;
  cpu_push_af();
  a = mem_read8(0x8444);
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p25_L_562A;
  a = mem_read8(0x85E2);
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p25_L_562D;
  lab_p25_L_562A: ;
  p00_L_3E43();
  lab_p25_L_562D: ;
  cpu_pop_af();
  return;
}

/* flash page 25 cpu 0x562F (offset 0x162F) */
void p25_L_562F(void) {
  p25_L_5257();
  a = mem_read8(0x85E0);
  a = (uint8_t)(a + 1);
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p25_L_563C;
  a = 0x07;
  lab_p25_L_563C: ;
  mem_write8(0x844B, a);
  return;
}

/* flash page 25 cpu 0x5660 (offset 0x1660) */
void p25_L_5660(void) {
  mem_write8(0x85E0, a);
  p25_L_55FD();
  a = 0;
  flag_logic(a);
  mem_write8(0x85F2, a);
  goto lab_p25_L_5672;
  lab_p25_L_5672: ;
  a = mem_read8(0x85E0);
  p25_L_562F();
  a = mem_read8(0x984A);
  mem_write8(0x844B, a);
  p25_L_58A3();
  return;
}

/* flash page 25 cpu 0x566C (offset 0x166C) */
void p25_L_566C(void) {
  mem_write8(0x85E0, a);
  p25_L_55FD();
  a = mem_read8(0x85E0);
  p25_L_562F();
  a = mem_read8(0x984A);
  mem_write8(0x844B, a);
  p25_L_58A3();
  return;
}

/* flash page 25 cpu 0x5695 (offset 0x1695) */
void p25_L_5695(void) {
  set_hl(0x85E0);
  a = mem_read8(0x85E2);
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p25_L_57D8(); return; }
  a = (uint8_t)(a - 1);
  cpu_cp_hl();
  if (flag_z()) { p25_L_58A3(); return; }
  if (flag_c()) { p25_L_58A3(); return; }
  p25_L_5D0D();
  cpu_push_af();
  if (flag_nz()) goto lab_p25_L_56B7;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = mem_read8(0x844B);
  flag_cmp(a, 0x06);
  if (flag_nc()) goto lab_p25_L_5718;
  goto lab_p25_L_56FD;
  lab_p25_L_56B7: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  if (flag_nz()) goto lab_p25_L_56BF;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  cpu_pop_af();
  p25_L_58A3();
  return;
  lab_p25_L_56BF: ;
  a = mem_read8(0x844B);
  flag_cmp(a, 0x07);
  if (flag_c()) goto lab_p25_L_56FD;
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p25_L_5718;
  cpu_pop_af();
  p25_L_5EE0();
  if (flag_c()) goto lab_p25_L_56FA;
  a = mem_read8(0x85E0);
  a = (uint8_t)(a - 1);
  c = a;
  p25_L_53D9();
  p25_L_697A();
  a = mem_read8(0x97A5);
  cpu_push_af();
  a = 0x01;
  mem_write8(0x97A5, a);
  p00_L_3CE1();
  p25_L_5EC5();
  a = mem_read8(0x85E0);
  c = a;
  p25_L_5EFB();
  p25_L_6966();
  cpu_pop_af();
  mem_write8(0x97A5, a);
  lab_p25_L_56FA: ;
  p25_L_58A3();
  return;
  lab_p25_L_56FD: ;
  a = (uint8_t)(a + 1);
  c = mem_read8(hl());
  c = (uint8_t)(c - 1);
  p25_L_53D9();
  set_hl(0x85E0);
  c = mem_read8(hl());
  set_hl(0x844B);
  cpu_pop_af();
  if (flag_nz()) goto lab_p25_L_570E;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p25_L_570E: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p25_L_53D9();
  p25_L_5EC5();
  p25_L_58A3();
  return;
  lab_p25_L_5718: ;
  cpu_pop_hl();
  cpu_push_af();
  p25_L_5229();
  cpu_pop_af();
  mem_write8(0x844B, a);
  p25_L_57D8();
  return;
}

/* flash page 25 cpu 0x572C (offset 0x172C) */
void p25_L_572C(void) {
  goto lab_p25_L_572C;
  lab_p25_L_55CF: ;
  mem_write8(0x844D, a);
  lab_p25_L_55D2: ;
  p25_L_5695();
  set_hl(0x844D);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) goto lab_p25_L_55D2;
  p25_L_58A3();
  return;
  lab_p25_L_5719: ;
  cpu_push_af();
  p25_L_5229();
  cpu_pop_af();
  mem_write8(0x844B, a);
  p25_L_57D8();
  return;
  lab_p25_L_572C: ;
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p25_L_5770;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 0)) == 0);
  if (flag_nz()) { p25_L_58A3(); return; }
  a = mem_read8(0x85E2);
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p25_L_55CF;
  a = 0;
  flag_logic(a);
  mem_write8(0x85F2, a);
  a = mem_read8(0x85E2);
  a = (uint8_t)(a - 1);
  mem_write8(0x85E0, a);
  a = (uint8_t)(a - 0x07);
  set_hl(0x984A);
  /* add a,(hl) */
  c = a;
  cpu_push_bc();
  p25_L_5399();
  a = mem_read8(0x984A);
  a = (uint8_t)(a - 1);
  mem_write8(0x844B, a);
  cpu_pop_bc();
  p25_L_5273();
  set_hl(0x0007);
  mem_write16(0x844B, hl());
  a = mem_read8(0x85E0);
  c = a;
  p25_L_53E3();
  p25_L_58A3();
  return;
  lab_p25_L_5770: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p25_L_5D0D();
  a = mem_read8(0x844B);
  if (flag_nz()) goto lab_p25_L_577E;
  flag_cmp(a, 0x03);
  if (flag_c()) goto lab_p25_L_5719;
  lab_p25_L_577E: ;
  set_hl(0x984A);
  cpu_cp_hl();
  if (flag_z()) goto lab_p25_L_5786;
  if (flag_nc()) goto lab_p25_L_57BC;
  lab_p25_L_5786: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p25_L_5719;
  p25_L_5EED();
  if (flag_c()) goto lab_p25_L_57B9;
  a = mem_read8(0x85E0);
  a = (uint8_t)(a + 1);
  c = a;
  p25_L_53D9();
  p25_L_697A();
  a = mem_read8(0x97A5);
  cpu_push_af();
  a = 0x01;
  mem_write8(0x97A5, a);
  p00_L_3CF9();
  p25_L_5ED2();
  a = mem_read8(0x85E0);
  c = a;
  p25_L_5EFB();
  p25_L_6951();
  cpu_pop_af();
  mem_write8(0x97A5, a);
  lab_p25_L_57B9: ;
  p25_L_58A3();
  return;
  lab_p25_L_57BC: ;
  set_hl(0x85E0);
  c = mem_read8(hl());
  c = (uint8_t)(c + 1);
  p25_L_53D9();
  set_hl(0x85E0);
  c = mem_read8(hl());
  p25_L_5D0D();
  set_hl(0x844B);
  if (flag_nz()) goto lab_p25_L_57D1;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  lab_p25_L_57D1: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p25_L_53D9();
  p25_L_5ED2();
  p25_L_57D8();
  return;
}

/* flash page 25 cpu 0x57D8 (offset 0x17D8) */
void p25_L_57D8(void) {
  p25_L_58A3();
  return;
}

/* flash page 25 cpu 0x581C (offset 0x181C) */
void p25_L_581C(void) {
  p25_L_4EF3();
  if (flag_nz()) goto lab_p25_L_5825;
  p25_L_58B7();
  return;
  lab_p25_L_5825: ;
  cpu_push_af();
  a = c;
  flag_cmp(a, 0x82);
  if (flag_nz()) goto lab_p25_L_582F;
  cpu_pop_af();
  p25_L_4FB3();
  return;
  lab_p25_L_582F: ;
  cpu_pop_af();
  p25_L_5830();
  return;
}

/* flash page 25 cpu 0x5830 (offset 0x1830) */
void p25_L_5830(void) {
  flag_cmp(a, 0x5A);
  if (flag_z()) goto lab_p25_L_583E;
  flag_cmp(a, 0x40);
  if (flag_c()) goto lab_p25_L_5844;
  if (flag_z()) goto lab_p25_L_5844;
  flag_cmp(a, 0x5A);
  if (flag_nc()) goto lab_p25_L_5844;
  lab_p25_L_583E: ;
  p25_L_4F43();
  if (flag_z()) { p25_L_58A3(); return; }
  lab_p25_L_5844: ;
  flag_cmp(a, 0x17);
  if (flag_nz()) goto lab_p25_L_584C;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 5)));
  lab_p25_L_584C: ;
  p00_L_2F5B();
  if (flag_z()) { p25_L_58A3(); return; }
  p25_L_5852();
  return;
}

/* flash page 25 cpu 0x5852 (offset 0x1852) */
void p25_L_5852(void) {
  p25_L_58B7();
  flag_cmp(a, 0xFF);
  if (flag_nz()) { p25_L_585B(); return; }
  a = 0xFE;
  p25_L_585B();
  return;
}

/* flash page 25 cpu 0x585B (offset 0x185B) */
void p25_L_585B(void) {
  p25_L_60BA();
  if (flag_nz()) goto lab_p25_L_5866;
  flag_cmp(a, 0x40);
  if (flag_z()) return;
  flag_cmp(a, 0x5A);
  return;
  lab_p25_L_5866: ;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 25 cpu 0x5890 (offset 0x1890) */
void p25_L_5890(void) {
  flag_cmp(a, 0x5A);
  if (flag_z()) { p25_L_5830(); return; }
  flag_cmp(a, 0x40);
  if (flag_c()) { p25_L_58A3(); return; }
  if (flag_z()) { p25_L_5830(); return; }
  p25_L_60B2();
  if (flag_z()) { p25_L_58A3(); return; }
  flag_cmp(a, 0x5A);
  if (flag_c()) { p25_L_5830(); return; }
  p25_L_58A3();
  return;
}

/* flash page 25 cpu 0x58A3 (offset 0x18A3) */
void p25_L_58A3(void) {
  /* scf */
  cpu_push_af();
  p25_L_52B8();
  cpu_pop_af();
  return;
}

/* flash page 25 cpu 0x58AA (offset 0x18AA) */
void p25_L_58AA(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 1)) == 0);
  if (flag_z()) return;
  p00_L_3DA1();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  return;
}

/* flash page 25 cpu 0x58B7 (offset 0x18B7) */
void p25_L_58B7(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p25_L_58C5;
  b = a;
  a = 0x03;
  p00_L_2D15();
  if (flag_nz()) return;
  a = b;
  lab_p25_L_58C5: ;
  set_hl(0x85DE);
  mem_write8(hl(), 0x00);
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p25_L_58DE;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 5)));
  p25_L_5C15();
  cpu_pop_af();
  return;
  lab_p25_L_58DE: ;
  b = a;
  flag_cmp(a, 0x5A);
  if (flag_nz()) goto lab_p25_L_58E9;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p25_L_5903;
  lab_p25_L_58E9: ;
  flag_cmp(a, 0x40);
  if (flag_c()) goto lab_p25_L_5954;
  flag_cmp(a, 0x5A);
  if (flag_nc()) goto lab_p25_L_5954;
  a = mem_read8(0x859A);
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p25_L_5903;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p25_L_5954;
  flag_cmp(a, 0x49);
  if (flag_z()) goto lab_p25_L_5954;
  flag_cmp(a, 0x4D);
  if (flag_z()) goto lab_p25_L_5954;
  lab_p25_L_5903: ;
  p25_L_60BA();
  if (flag_z()) goto lab_p25_L_5954;
  p00_L_17CE();
  if (flag_nz()) goto lab_p25_L_5918;
  p25_L_60C2();
  if (flag_z()) p25_L_6853();
  p00_L_3EF1();
  goto lab_p25_L_593F;
  lab_p25_L_5918: ;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x5A);
  if (flag_z()) goto lab_p25_L_5922;
  flag_cmp(a, 0x44);
  if (flag_nz()) goto lab_p25_L_592B;
  lab_p25_L_5922: ;
  p00_L_3E43();
  p00_L_3E55();
  p25_L_5BB3();
  return;
  lab_p25_L_592B: ;
  p00_L_3EF1();
  cpu_pop_af();
  cpu_push_af();
  p25_L_5930();
  return;
  lab_p25_L_593F: ;
  p25_L_5BCE();
  return;
  lab_p25_L_5954: ;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x48);
  if (flag_nz()) goto lab_p25_L_5982;
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p25_L_5982;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x5A);
  if (flag_nc()) { p25_L_5BCE(); return; }
  a = mem_read8(0x859A);
  goto lab_p25_L_5982;
  lab_p25_L_5982: ;
  flag_cmp(a, 0x45);
  if (flag_z()) goto lab_p25_L_598A;
  flag_cmp(a, 0x57);
  if (flag_nz()) goto lab_p25_L_59A4;
  lab_p25_L_598A: ;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x28);
  if (flag_z()) { p25_L_5A3B(); return; }
  flag_cmp(a, 0x29);
  if (flag_z()) { p25_L_5A3B(); return; }
  flag_cmp(a, 0x5A);
  if (flag_nc()) { p25_L_5A3B(); return; }
  p00_L_3E43();
  p00_L_2FCD();
  p25_L_5A3B();
  return;
  lab_p25_L_59A4: ;
  flag_cmp(a, 0x4C);
  if (flag_nz()) goto lab_p25_L_59B7;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x29);
  if (flag_z()) { p25_L_5A3B(); return; }
  flag_cmp(a, 0x5A);
  if (flag_nc()) { p25_L_5A3B(); return; }
  a = mem_read8(0x859A);
  lab_p25_L_59B7: ;
  flag_cmp(a, 0x55);
  if (flag_nz()) goto lab_p25_L_59DB;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p25_L_5B28;
  p00_L_3141();
  if (flag_nz()) goto lab_p25_L_59DB;
  flag_cmp(a, 0x29);
  if (flag_z()) { p25_L_5A3B(); return; }
  flag_cmp(a, 0x5A);
  if (flag_nc()) { p25_L_5A3B(); return; }
  p00_L_3D7D();
  p00_L_313B();
  p25_L_5A3B();
  return;
  lab_p25_L_59DB: ;
  flag_cmp(a, 0x4B);
  if (flag_nz()) goto lab_p25_L_59EB;
  p00_L_2FD9();
  if (flag_nz()) goto lab_p25_L_59EB;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x29);
  if (flag_z()) { p25_L_5A3B(); return; }
  lab_p25_L_59EB: ;
  flag_cmp(a, 0x56);
  if (flag_nz()) goto lab_p25_L_5A16;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p25_L_5B28;
  b = a;
  a = mem_read8(0x85E3);
  flag_set_z((a & (1u << 6)) == 0);
  a = b;
  if (flag_z()) goto lab_p25_L_5A16;
  flag_cmp(a, 0x29);
  if (flag_z()) { p25_L_5A3B(); return; }
  flag_cmp(a, 0x5A);
  if (flag_nc()) { p25_L_5A3B(); return; }
  p25_L_5BD3();
  if (flag_nc()) goto lab_p25_L_5B70;
  p00_L_3D7D();
  p00_L_3477();
  p25_L_5A3B();
  return;
  lab_p25_L_5A16: ;
  flag_cmp(a, 0x53);
  if (flag_nz()) goto lab_p25_L_5A3E;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p25_L_5B28;
  p00_L_2FD9();
  if (flag_nz()) goto lab_p25_L_5A3E;
  flag_cmp(a, 0x29);
  if (flag_z()) { p25_L_5A3B(); return; }
  flag_cmp(a, 0x5A);
  if (flag_nc()) { p25_L_5A3B(); return; }
  p25_L_5BD3();
  if (flag_nc()) goto lab_p25_L_5B70;
  p00_L_3D7D();
  p00_L_36ED();
  p25_L_5A3B();
  return;
  lab_p25_L_5A3E: ;
  flag_cmp(a, 0x52);
  if (flag_nz()) goto lab_p25_L_5A5E;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0xD6);
  if (flag_nz()) goto lab_p25_L_5A5B;
  a = mem_read8(0x9652);
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p25_L_5A5B;
  a = mem_read8(0x9653);
  flag_cmp(a, 0x41);
  if (flag_nz()) goto lab_p25_L_5A5B;
  lab_p25_L_5A56: ;
  p00_L_3EF1();
  p25_L_5A3B();
  return;
  lab_p25_L_5A5B: ;
  a = mem_read8(0x859A);
  lab_p25_L_5A5E: ;
  p00_L_17CE();
  if (flag_z()) goto lab_p25_L_5A8B;
  p00_L_3E43();
  p25_L_5C15();
  p00_L_33B1();
  a = mem_read8(0x859A);
  flag_cmp(a, 0x44);
  if (flag_nz()) goto lab_p25_L_5B28;
  a = mem_read8(0x85E5);
  flag_cmp(a, 0x2F);
  if (flag_z()) { p25_L_5BB3(); return; }
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p25_L_5B9A;
  flag_cmp(a, 0x7F);
  if (flag_c()) { p25_L_5BB3(); return; }
  p25_L_5B44();
  return;
  lab_p25_L_5A8B: ;
  flag_cmp(a, 0x44);
  if (flag_nz()) goto lab_p25_L_5AFC;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p25_L_5A99;
  flag_cmp(a, 0x28);
  if (flag_nz()) goto lab_p25_L_5AB7;
  lab_p25_L_5A99: ;
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 0)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p25_L_5AAE;
  lab_p25_L_5AA3: ;
  p25_L_6853();
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p25_L_5B9A;
  p25_L_5B96();
  return;
  lab_p25_L_5AAE: ;
  a = mem_read8(0x85E5);
  flag_cmp(a, 0x2F);
  if (flag_nz()) goto lab_p25_L_5AA3;
  cpu_pop_af();
  cpu_push_af();
  lab_p25_L_5AB7: ;
  set_hl(0x684A);
  b = 0x09;
  lab_p25_L_5ABC: ;
  cpu_cp_hl();
  if (flag_z()) goto lab_p25_L_5A56;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_5ABC;
  flag_cmp(a, 0x29);
  if (flag_z()) goto lab_p25_L_5ACB;
  flag_cmp(a, 0x7F);
  if (flag_c()) goto lab_p25_L_5AEA;
  lab_p25_L_5ACB: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p25_L_5AEA;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p25_L_5AEA;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p25_L_5AEA;
  a = mem_read8(0x85E5);
  flag_cmp(a, 0x2F);
  if (flag_z()) goto lab_p25_L_5AEA;
  p25_L_6853();
  p25_L_5BCE();
  return;
  lab_p25_L_5AEA: ;
  p00_L_3E43();
  p25_L_5C15();
  p00_L_33B1();
  a = mem_read8(0x858B);
  mem_write8(0x8A02, a);
  p25_L_5BD1();
  return;
  lab_p25_L_5AFC: ;
  flag_cmp(a, 0x50);
  if (flag_z()) goto lab_p25_L_5B28;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x7F);
  if (flag_nc()) goto lab_p25_L_5B25;
  flag_cmp(a, 0x75);
  if (flag_nc()) goto lab_p25_L_5B1F;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x46);
  if (flag_z()) goto lab_p25_L_5B28;
  flag_cmp(a, 0x47);
  if (flag_z()) goto lab_p25_L_5B28;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x5A);
  if (flag_c()) goto lab_p25_L_5B25;
  flag_cmp(a, 0x69);
  if (flag_nc()) goto lab_p25_L_5B25;
  lab_p25_L_5B1F: ;
  p00_L_3EF1();
  p25_L_5BCE();
  return;
  lab_p25_L_5B25: ;
  a = mem_read8(0x859A);
  lab_p25_L_5B28: ;
  p00_L_07DE();
  if (flag_nz()) goto lab_p25_L_5B38;
  p25_L_5C15();
  p00_L_3D83();
  p00_L_0766();
  cpu_pop_af();
  return;
  lab_p25_L_5B38: ;
  flag_cmp(a, 0x40);
  if (flag_z()) { p25_L_5BB3(); return; }
  flag_cmp(a, 0x46);
  if (flag_z()) { p25_L_5BB3(); return; }
  flag_cmp(a, 0x50);
  if (flag_z()) { p25_L_5BB3(); return; }
  p25_L_5B44();
  return;
  lab_p25_L_5B70: ;
  flag_cmp(a, 0x29);
  if (flag_z()) { p25_L_5BB3(); return; }
  flag_cmp(a, 0xFF);
  if (flag_z()) { p25_L_5B96(); return; }
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p25_L_5BA7;
  flag_cmp(a, 0xFC);
  if (flag_nz()) goto lab_p25_L_5B88;
  a = mem_read8(0x8446);
  p25_L_68A8();
  if (flag_z()) goto lab_p25_L_5B9A;
  lab_p25_L_5B88: ;
  a = mem_read8(0x8446);
  flag_cmp(a, 0xFD);
  if (flag_nz()) goto lab_p25_L_5BA7;
  a = 0x00;
  mem_write8(0x8446, a);
  goto lab_p25_L_5B9A;
  lab_p25_L_5B9A: ;
  p00_L_3EF1();
  p25_L_5C15();
  a = 0x40;
  p00_mmu_set_bankA_4();
  p25_L_5BD1();
  return;
  lab_p25_L_5BA7: ;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x41);
  if (flag_nz()) { p25_L_5BB3(); return; }
  p25_L_60CA();
  p25_L_5BCE();
  return;
}

/* flash page 25 cpu 0x5930 (offset 0x1930) */
void p25_L_5930(void) {
  flag_cmp(a, 0x48);
  if (flag_z()) goto lab_p25_L_5942;
  p25_L_688D();
  if (flag_nz()) goto lab_p25_L_5942;
  p25_L_60C2();
  if (flag_z()) p25_L_6853();
  p25_L_5BCE();
  return;
  lab_p25_L_5942: ;
  a = 0x04;
  mem_write8(0x97A5, a);
  p00_L_3E43();
  p00_L_3E55();
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 2)));
  p25_L_5A3B();
  return;
}

/* flash page 25 cpu 0x59CD (offset 0x19CD) */
void p25_L_59CD(void) {
  e = d;
  if (flag_nc()) { p25_L_5A3B(); return; }
  p00_L_3D7D();
  p00_L_313B();
  p25_L_5A3B();
  return;
}

/* flash page 25 cpu 0x5A3B (offset 0x1A3B) */
void p25_L_5A3B(void) {
  p25_L_5BCE();
  return;
}

/* flash page 25 cpu 0x5B44 (offset 0x1B44) */
void p25_L_5B44(void) {
  goto lab_p25_L_5B44;
  lab_p25_L_5B28: ;
  p00_L_07DE();
  if (flag_nz()) goto lab_p25_L_5B38;
  p25_L_5C15();
  p00_L_3D83();
  p00_L_0766();
  cpu_pop_af();
  return;
  lab_p25_L_5B38: ;
  flag_cmp(a, 0x40);
  if (flag_z()) { p25_L_5BB3(); return; }
  flag_cmp(a, 0x46);
  if (flag_z()) { p25_L_5BB3(); return; }
  flag_cmp(a, 0x50);
  if (flag_z()) { p25_L_5BB3(); return; }
  lab_p25_L_5B44: ;
  flag_cmp(a, 0x43);
  if (flag_nz()) goto lab_p25_L_5B6E;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p25_L_5B28;
  flag_cmp(a, 0xFC);
  if (flag_nz()) goto lab_p25_L_5B5B;
  a = mem_read8(0x8446);
  p25_L_68A8();
  if (flag_z()) goto lab_p25_L_5B6E;
  lab_p25_L_5B5B: ;
  p00_L_07DE();
  if (flag_z()) goto lab_p25_L_5B6B;
  p25_L_5BD3();
  if (flag_nc()) goto lab_p25_L_5B70;
  p00_L_3D7D();
  p25_L_5C42();
  lab_p25_L_5B6B: ;
  p25_L_5BCE();
  return;
  lab_p25_L_5B6E: ;
  cpu_pop_af();
  cpu_push_af();
  lab_p25_L_5B70: ;
  flag_cmp(a, 0x29);
  if (flag_z()) { p25_L_5BB3(); return; }
  flag_cmp(a, 0xFF);
  if (flag_z()) { p25_L_5B96(); return; }
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p25_L_5BA7;
  flag_cmp(a, 0xFC);
  if (flag_nz()) goto lab_p25_L_5B88;
  a = mem_read8(0x8446);
  p25_L_68A8();
  if (flag_z()) goto lab_p25_L_5B9A;
  lab_p25_L_5B88: ;
  a = mem_read8(0x8446);
  flag_cmp(a, 0xFD);
  if (flag_nz()) goto lab_p25_L_5BA7;
  a = 0x00;
  mem_write8(0x8446, a);
  goto lab_p25_L_5B9A;
  lab_p25_L_5B9A: ;
  p00_L_3EF1();
  p25_L_5C15();
  a = 0x40;
  p00_mmu_set_bankA_4();
  p25_L_5BD1();
  return;
  lab_p25_L_5BA7: ;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x41);
  if (flag_nz()) { p25_L_5BB3(); return; }
  p25_L_60CA();
  p25_L_5BCE();
  return;
}

/* flash page 25 cpu 0x5B96 (offset 0x1B96) */
void p25_L_5B96(void) {
  cpu_pop_af();
  a = 0xFE;
  cpu_push_af();
  p00_L_3EF1();
  p25_L_5C15();
  a = 0x40;
  p00_mmu_set_bankA_4();
  p25_L_5BD1();
  return;
}

/* flash page 25 cpu 0x5BB3 (offset 0x1BB3) */
void p25_L_5BB3(void) {
  flag_cmp(a, 0x59);
  if (flag_nz()) goto lab_p25_L_5BBC;
  p25_L_60CA();
  p25_L_5BCE();
  return;
  lab_p25_L_5BBC: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 5)) == 0);
  if (flag_nz()) p00_L_36F3();
  if (flag_nz()) { p25_L_5BCE(); return; }
  p00_L_3D7D();
  p25_L_5C42();
  p25_L_5C2E();
  p25_L_5BCE();
  return;
}

/* flash page 25 cpu 0x5BCE (offset 0x1BCE) */
void p25_L_5BCE(void) {
  p25_L_5C15();
  p25_L_5BD1();
  return;
}

/* flash page 25 cpu 0x5BD1 (offset 0x1BD1) */
void p25_L_5BD1(void) {
  cpu_pop_af();
  return;
}

/* flash page 25 cpu 0x5BD3 (offset 0x1BD3) */
void p25_L_5BD3(void) {
  /* ccf */
  flag_cmp(a, 0x29);
  if (flag_z()) goto lab_p25_L_5BE1;
  flag_cmp(a, 0xFF);
  if (flag_z()) return;
  a = mem_read8(0x8446);
  flag_cmp(a, 0xFD);
  if (flag_z()) return;
  lab_p25_L_5BE1: ;
  /* scf */
  return;
}

/* flash page 25 cpu 0x5BE3 (offset 0x1BE3) */
void p25_L_5BE3(void) {
  a = mem_read8((uint16_t)(iy + 0x0C));
  mem_write8(0x85E4, a);
  a = mem_read8((uint16_t)(iy + 0x0D));
  mem_write8(0x85E3, a);
  a = mem_read8(0x8D17);
  mem_write8(0x85E5, a);
  a = mem_read8((uint16_t)(iy + 0x03));
  mem_write8(0x85E6, a);
  return;
}

/* flash page 25 cpu 0x5BFC (offset 0x1BFC) */
void p25_L_5BFC(void) {
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 5)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  a = 0;
  flag_logic(a);
  mem_write8(0x8D17, a);
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 3)));
  return;
}

/* flash page 25 cpu 0x5C15 (offset 0x1C15) */
void p25_L_5C15(void) {
  a = mem_read8(0x85E5);
  mem_write8(0x8D17, a);
  a = mem_read8(0x85E6);
  mem_write8((uint16_t)(iy + 0x03), a);
  p25_L_5C21();
  return;
}

/* flash page 25 cpu 0x5C21 (offset 0x1C21) */
void p25_L_5C21(void) {
  a = mem_read8(0x85E3);
  mem_write8((uint16_t)(iy + 0x0D), a);
  a = mem_read8(0x85E4);
  mem_write8((uint16_t)(iy + 0x0C), a);
  return;
}

/* flash page 25 cpu 0x5C2E (offset 0x1C2E) */
void p25_L_5C2E(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p25_L_5C54;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p25_L_5C98;
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 4)) == 0);
  if (flag_z()) return;
  p25_L_5CD1();
  return;
  lab_p25_L_5C54: ;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p00_L_322B();
  p00_L_3237();
  p00_L_345F();
  if (flag_nz()) p00_L_323D();
  p00_L_3219();
  p00_L_3225();
  goto lab_p25_L_5C71;
  lab_p25_L_5C71: ;
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
  lab_p25_L_5C98: ;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p00_L_2FEB();
  goto lab_p25_L_5C71;
}

/* flash page 25 cpu 0x5C42 (offset 0x1C42) */
void p25_L_5C42(void) {
  a = mem_read8(0x859A);
  flag_cmp(a, 0x42);
  if (flag_nz()) goto lab_p25_L_5C50;
  p00_L_3297();
  p00_L_3291();
  return;
  lab_p25_L_5C50: ;
  flag_cmp(a, 0x43);
  if (flag_nz()) goto lab_p25_L_5C6C;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p00_L_322B();
  p00_L_3237();
  p00_L_345F();
  if (flag_nz()) p00_L_323D();
  p00_L_3219();
  p00_L_3225();
  goto lab_p25_L_5C71;
  lab_p25_L_5C6C: ;
  flag_cmp(a, 0x48);
  if (flag_nz()) goto lab_p25_L_5C76;
  return;
  lab_p25_L_5C71: ;
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
  lab_p25_L_5C76: ;
  flag_cmp(a, 0x4B);
  if (flag_nz()) goto lab_p25_L_5C83;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p00_L_2FCD();
  goto lab_p25_L_5C71;
  lab_p25_L_5C83: ;
  flag_cmp(a, 0x53);
  if (flag_nz()) goto lab_p25_L_5C94;
  p00_L_345F();
  if (flag_z()) return;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p00_L_2FCD();
  goto lab_p25_L_5C71;
  lab_p25_L_5C94: ;
  flag_cmp(a, 0x49);
  if (flag_nz()) goto lab_p25_L_5CA7;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p00_L_2FEB();
  goto lab_p25_L_5C71;
  lab_p25_L_5CA7: ;
  flag_cmp(a, 0x55);
  if (flag_nz()) goto lab_p25_L_5CB4;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p00_L_313B();
  goto lab_p25_L_5C71;
  lab_p25_L_5CB4: ;
  flag_cmp(a, 0x56);
  if (flag_nz()) goto lab_p25_L_5CC1;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p00_L_3477();
  goto lab_p25_L_5C71;
  lab_p25_L_5CC1: ;
  flag_cmp(a, 0x4C);
  if (flag_z()) goto lab_p25_L_5D09;
  flag_cmp(a, 0x4A);
  if (flag_z()) { p25_L_5CD1(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 1)) == 0);
  p25_L_5CCD();
  return;
  lab_p25_L_5D09: ;
  p00_L_3E07();
  return;
}

/* flash page 25 cpu 0x5CCD (offset 0x1CCD) */
void p25_L_5CCD(void) {
  if (flag_z()) return;
  flag_cmp(a, 0x44);
  if (flag_nz()) return;
  p25_L_5CD1();
  return;
}

/* flash page 25 cpu 0x5CD1 (offset 0x1CD1) */
void p25_L_5CD1(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_5CE5;
  p00_L_3E55();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p00_L_31A1();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  lab_p25_L_5CE5: ;
  p00_L_324F();
  p00_L_31A7();
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_5CF8;
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_z()) p00_L_319B();
  lab_p25_L_5CF8: ;
  p00_L_3195();
  p00_L_345F();
  if (flag_z()) p00_L_3D89();
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3D89();
  return;
}

/* flash page 25 cpu 0x5D0D (offset 0x1D0D) */
void p25_L_5D0D(void) {
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x06);
  if (flag_nz()) return;
  a = 0x02;
  cpu_cp_hl();
  if (flag_c()) return;
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 25 cpu 0x5D19 (offset 0x1D19) */
void p25_L_5D19(void) {
  set_hl(0x85E2);
  cpu_cp_hl();
  if (flag_nc()) return;
  cpu_push_af();
  p25_L_5399();
  cpu_pop_bc();
  a = b;
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_5D2C;
  lab_p25_L_5D28: ;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_5D28;
  lab_p25_L_5D2C: ;
  a = mem_read8(hl());
  p25_L_4EF3();
  if (flag_nz()) goto lab_p25_L_5D3E;
  set_hl(mem_read16(0x9311));
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  p00_rst20();
  a = 0x8E;
  /* scf */
  return;
  lab_p25_L_5D3E: ;
  b = a;
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  c = a;
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p25_L_5D4B;
  a = b;
  b = 0xFF;
  goto lab_p25_L_5D5B;
  lab_p25_L_5D4B: ;
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p25_L_5D54;
  a = b;
  b = 0xFE;
  goto lab_p25_L_5D5B;
  lab_p25_L_5D54: ;
  flag_cmp(a, 0xFC);
  if (flag_nz()) goto lab_p25_L_5D5B;
  a = b;
  b = 0xFC;
  lab_p25_L_5D5B: ;
  mem_write8(0x8446, a);
  a = b;
  /* scf */
  return;
}

/* flash page 25 cpu 0x5D61 (offset 0x1D61) */
void p25_L_5D61(void) {
  p25_L_5EA1();
  p00_L_19ED();
  if (flag_nc()) return;
  p25_L_5D9B();
  return;
}

/* flash page 25 cpu 0x5D6A (offset 0x1D6A) */
void p25_L_5D6A(void) {
  p00_L_2DAB();
  a = 0x14;
  mem_write8(0x8478, a);
  return;
}

/* flash page 25 cpu 0x5D73 (offset 0x1D73) */
void p25_L_5D73(void) {
  set_hl(0x85E7);
  p25_L_5DE9();
  p00_L_2DBD();
  if (flag_nc()) goto lab_p25_L_5D81;
  p00_L_1295();
  lab_p25_L_5D81: ;
  a = 0x14;
  mem_write8(0x8478, a);
  return;
}

/* flash page 25 cpu 0x5D87 (offset 0x1D87) */
void p25_L_5D87(void) {
  a = 0x17;
  p25_L_5D98();
  return;
}

/* flash page 25 cpu 0x5D8B (offset 0x1D8B) */
void p25_L_5D8B(void) {
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x10);
  if (flag_z()) { p25_L_5D61(); return; }
  flag_cmp(a, 0x28);
  if (flag_z()) { p25_L_5D87(); return; }
  p25_L_5D96();
  return;
}

/* flash page 25 cpu 0x5D96 (offset 0x1D96) */
void p25_L_5D96(void) {
  a = 0x05;
  p25_L_5D98();
  return;
}

/* flash page 25 cpu 0x5D98 (offset 0x1D98) */
void p25_L_5D98(void) {
  p25_L_5E94();
  p25_L_5D9B();
  return;
}

/* flash page 25 cpu 0x5D9B (offset 0x1D9B) */
void p25_L_5D9B(void) {
  lab_p25_L_5D9B: ;
  p25_L_5DD2();
  if (flag_z()) { p25_L_5D6A(); return; }
  a = 0;
  flag_logic(a);
  p00_L_3ADD();
  if (flag_c()) return;
  p25_L_5FB3();
  if (flag_nz()) goto lab_p25_L_5DB1;
  p00_L_1037();
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p25_L_5D9B;
  lab_p25_L_5DB1: ;
  /* scf */
  /* ccf */
  return;
}

/* flash page 25 cpu 0x5DB4 (offset 0x1DB4) */
void p25_L_5DB4(void) {
  goto lab_p25_L_5DB4;
  lab_p25_L_5DB1: ;
  /* scf */
  /* ccf */
  return;
  lab_p25_L_5DB4: ;
  p25_L_5DD2();
  if (flag_z()) { p25_L_5D73(); return; }
  a = 0;
  flag_logic(a);
  p00_L_2F97();
  if (flag_c()) return;
  p25_L_5FB3();
  if (flag_nz()) goto lab_p25_L_5DB1;
  p00_L_1037();
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p25_L_5DB4;
  goto lab_p25_L_5DB1;
}

/* flash page 25 cpu 0x5DCD (offset 0x1DCD) */
void p25_L_5DCD(void) {
  /* sbc a,0x85 */
  flag_cmp(a, 0x10);
  return;
}

/* flash page 25 cpu 0x5DD2 (offset 0x1DD2) */
void p25_L_5DD2(void) {
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x02);
  return;
}

/* flash page 25 cpu 0x5DD8 (offset 0x1DD8) */
void p25_L_5DD8(void) {
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x28);
  return;
}

/* flash page 25 cpu 0x5DDE (offset 0x1DDE) */
void p25_L_5DDE(void) {
  set_hl(0x85E7);
  p25_L_5DD2();
  if (flag_nz()) return;
  a = mem_read8(hl());
  flag_cmp(a, 0x14);
  if (flag_nz()) return;
  p25_L_5DE9();
  return;
}

/* flash page 25 cpu 0x5DE9 (offset 0x1DE9) */
void p25_L_5DE9(void) {
  cpu_push_hl();
  b = 0x08;
  a = 0;
  flag_logic(a);
  lab_p25_L_5DED: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_cp_hl();
  if (flag_nz()) goto lab_p25_L_5DF3;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_5DED;
  lab_p25_L_5DF3: ;
  cpu_pop_hl();
  return;
}

/* flash page 25 cpu 0x5DF7 (offset 0x1DF7) */
void p25_L_5DF7(void) {
  goto lab_p25_L_5DF7;
  lab_p25_L_5DF5: ;
  cpu_pop_bc();
  return;
  lab_p25_L_5DF7: ;
  cpu_push_bc();
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p25_L_5E04;
  p25_L_5D61();
  goto lab_p25_L_5E20;
  lab_p25_L_5E04: ;
  p25_L_5DD8();
  if (flag_nz()) goto lab_p25_L_5E10;
  a = 0x17;
  p25_L_5D98();
  goto lab_p25_L_5E22;
  lab_p25_L_5E10: ;
  p25_L_5DD2();
  if (flag_nz()) goto lab_p25_L_5E1D;
  p00_L_3F2D();
  p25_L_5E80();
  goto lab_p25_L_5E22;
  lab_p25_L_5E1D: ;
  p25_L_5D96();
  lab_p25_L_5E20: ;
  if (flag_c()) goto lab_p25_L_5DF5;
  lab_p25_L_5E22: ;
  cpu_pop_bc();
  cpu_push_bc();
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_5E52;
  a = mem_read8(0x85F2);
  p00_L_17BE();
  if (flag_z()) goto lab_p25_L_5E4F;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p25_L_5E4F;
  a = 0x05;
  mem_write8(0x85F2, a);
  a = c;
  lab_p25_L_5E3A: ;
  cpu_push_af();
  p25_L_5D9B();
  if (flag_c()) goto lab_p25_L_5E49;
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p25_L_5E3A;
  p25_L_5EBD();
  goto lab_p25_L_5E52;
  lab_p25_L_5E49: ;
  cpu_pop_af();
  goto lab_p25_L_5E52;
  lab_p25_L_5E4F: ;
  p25_L_5EB5();
  lab_p25_L_5E52: ;
  a = mem_read8(0x85F2);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p25_L_5E5D;
  a = 0x05;
  mem_write8(0x85F2, a);
  lab_p25_L_5E5D: ;
  p00_L_3CD5();
  p25_L_5E8D();
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  cpu_push_bc();
  c = (uint8_t)(c - 1);
  p25_L_5EFB();
  a = mem_read8(0x844B);
  flag_cmp(a, 0x07);
  if (flag_nc()) goto lab_p25_L_5E76;
  p25_L_5D9B();
  if (flag_nc()) goto lab_p25_L_5E52;
  lab_p25_L_5E76: ;
  cpu_pop_bc();
  p25_L_5E77();
  return;
}

/* flash page 25 cpu 0x5E4C (offset 0x1E4C) */
void p25_L_5E4C(void) {
  cpu_push_bc();
  goto lab_p25_L_5E52;
  lab_p25_L_5E52: ;
  a = mem_read8(0x85F2);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p25_L_5E5D;
  a = 0x05;
  mem_write8(0x85F2, a);
  lab_p25_L_5E5D: ;
  p00_L_3CD5();
  p25_L_5E8D();
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  cpu_push_bc();
  c = (uint8_t)(c - 1);
  p25_L_5EFB();
  a = mem_read8(0x844B);
  flag_cmp(a, 0x07);
  if (flag_nc()) goto lab_p25_L_5E76;
  p25_L_5D9B();
  if (flag_nc()) goto lab_p25_L_5E52;
  lab_p25_L_5E76: ;
  cpu_pop_bc();
  p25_L_5E77();
  return;
}

/* flash page 25 cpu 0x5E77 (offset 0x1E77) */
void p25_L_5E77(void) {
  set_hl(0x8499);
  set_de(0x85E7);
  p00_L_1183();
  return;
}

/* flash page 25 cpu 0x5E80 (offset 0x1E80) */
void p25_L_5E80(void) {
  a = 0x14;
  mem_write8(0x85E7, a);
  p00_L_1295();
  a = 0x14;
  mem_write8(0x8478, a);
  p25_L_5E8D();
  return;
}

/* flash page 25 cpu 0x5E8D (offset 0x1E8D) */
void p25_L_5E8D(void) {
  goto lab_p25_L_5E8D;
  lab_p25_L_5E7A: ;
  set_de(0x85E7);
  p00_L_1183();
  return;
  lab_p25_L_5E8D: ;
  set_hl(0x8478);
  goto lab_p25_L_5E7A;
}

/* flash page 25 cpu 0x5E94 (offset 0x1E94) */
void p25_L_5E94(void) {
  mem_write8(0x85E7, a);
  a = 0x40;
  mem_write8(0x85E8, a);
  p25_L_5E9C();
  return;
}

/* flash page 25 cpu 0x5E9C (offset 0x1E9C) */
void p25_L_5E9C(void) {
  goto lab_p25_L_5E9C;
  lab_p25_L_5E7D: ;
  p00_L_1183();
  return;
  lab_p25_L_5E9C: ;
  set_de(0x8478);
  goto lab_p25_L_5EAB;
  lab_p25_L_5EAB: ;
  set_hl(0x85E7);
  goto lab_p25_L_5E7D;
}

/* flash page 25 cpu 0x5EA1 (offset 0x1EA1) */
void p25_L_5EA1(void) {
  a = 0x00;
  p00_L_1682();
  p25_L_5E8D();
  return;
}

/* flash page 25 cpu 0x5EA8 (offset 0x1EA8) */
void p25_L_5EA8(void) {
  goto lab_p25_L_5EA8;
  lab_p25_L_5E7D: ;
  p00_L_1183();
  return;
  lab_p25_L_5EA8: ;
  set_de(0x8499);
  set_hl(0x85E7);
  goto lab_p25_L_5E7D;
}

/* flash page 25 cpu 0x5EB0 (offset 0x1EB0) */
void p25_L_5EB0(void) {
  goto lab_p25_L_5EB0;
  lab_p25_L_5E7D: ;
  p00_L_1183();
  return;
  lab_p25_L_5EAB: ;
  set_hl(0x85E7);
  goto lab_p25_L_5E7D;
  lab_p25_L_5EB0: ;
  set_de(0x85F2);
  goto lab_p25_L_5EAB;
}

/* flash page 25 cpu 0x5EB5 (offset 0x1EB5) */
void p25_L_5EB5(void) {
  goto lab_p25_L_5EB5;
  lab_p25_L_5E7D: ;
  p00_L_1183();
  return;
  lab_p25_L_5EB5: ;
  set_de(0x8478);
  set_hl(0x85F2);
  goto lab_p25_L_5E7D;
}

/* flash page 25 cpu 0x5EBD (offset 0x1EBD) */
void p25_L_5EBD(void) {
  goto lab_p25_L_5EBD;
  lab_p25_L_5E7D: ;
  p00_L_1183();
  return;
  lab_p25_L_5EBD: ;
  set_hl(0x8478);
  set_de(0x85F2);
  goto lab_p25_L_5E7D;
}

/* flash page 25 cpu 0x5EC5 (offset 0x1EC5) */
void p25_L_5EC5(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 5)) == 0);
  if (flag_z()) return;
  p25_L_5E9C();
  p25_L_5D9B();
  goto lab_p25_L_5EDD;
  lab_p25_L_5EDD: ;
  if (flag_c()) return;
  p25_L_5E8D();
  return;
}

/* flash page 25 cpu 0x5ED2 (offset 0x1ED2) */
void p25_L_5ED2(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 5)) == 0);
  if (flag_z()) return;
  p25_L_5E9C();
  p25_L_5DB4();
  if (flag_c()) return;
  p25_L_5E8D();
  return;
}

/* flash page 25 cpu 0x5EE0 (offset 0x1EE0) */
void p25_L_5EE0(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 5)) == 0);
  if (flag_z()) return;
  p25_L_5EB5();
  p25_L_5D9B();
  goto lab_p25_L_5EF8;
  lab_p25_L_5EF8: ;
  if (flag_c()) return;
  p25_L_5EBD();
  return;
}

/* flash page 25 cpu 0x5EED (offset 0x1EED) */
void p25_L_5EED(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 5)) == 0);
  if (flag_z()) return;
  p25_L_5EB5();
  p25_L_5DB4();
  if (flag_c()) return;
  p25_L_5EBD();
  return;
}

/* flash page 25 cpu 0x5EFB (offset 0x1EFB) */
void p25_L_5EFB(void) {
  p25_L_53D9();
  a = mem_read8(0x85E0);
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p25_L_5F07;
  p25_L_5EA8();
  lab_p25_L_5F07: ;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p25_L_5F1B;
  p25_L_5DDE();
  if (flag_nz()) goto lab_p25_L_6864;
  d = 0x82;
  e = 0x4C;
  p25_L_545D();
  return;
  lab_p25_L_5F1B: ;
  set_hl(0x85E8);
  cpu_push_hl();
  p25_L_6913();
  cpu_pop_hl();
  p25_L_5F23();
  return;
  lab_p25_L_6864: ;
  p25_L_6913();
  set_hl(0x85E7);
  b = 0x08;
  lab_p25_L_686C: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_6876;
  p00_L_3F9F();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_686C;
  lab_p25_L_6876: ;
  p00_L_3D1D();
  return;
}

/* flash page 25 cpu 0x5F23 (offset 0x1F23) */
void p25_L_5F23(void) {
  a = mem_read8(hl());
  flag_cmp(a, 0x31);
  if (flag_z()) { p25_L_6858(); return; }
  flag_cmp(a, 0x5D);
  if (flag_nz()) { p25_L_6858(); return; }
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0x06);
  set_hl((uint16_t)(hl() - 1));
  if (flag_nc()) { p25_L_6858(); return; }
  a = (uint8_t)(a + 1);
  /* sla a */
  e = a;
  p00_L_3147();
  p00_L_3D1D();
  return;
}

/* flash page 25 cpu 0x5F2C (offset 0x1F2C) */
void p25_L_5F2C(void) {
  e = b;
  l = b;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0x06);
  set_hl((uint16_t)(hl() - 1));
  if (flag_nc()) { p25_L_6858(); return; }
  a = (uint8_t)(a + 1);
  /* sla a */
  e = a;
  p00_L_3147();
  p00_L_3D1D();
  return;
}

/* flash page 25 cpu 0x5F56 (offset 0x1F56) */
void p25_L_5F56(void) {
  set_de(0x84BF);
  set_hl(0x85E8);
  p00_L_1185();
  a = 0;
  flag_logic(a);
  mem_write8(0x8446, a);
  a = 0x58;
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p25_L_5FAE;
  p25_L_5FBF();
  if (flag_nz()) goto lab_p25_L_5F79;
  a = 0x01;
  mem_write8(0x8446, a);
  a = 0x59;
  goto lab_p25_L_5FAE;
  lab_p25_L_5F79: ;
  p25_L_5FB3();
  a = 0x46;
  if (flag_z()) goto lab_p25_L_5FAE;
  a = 0xFD;
  mem_write8(0x8446, a);
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p25_L_5FAC;
  a = mem_read8(0x85E9);
  flag_cmp(a, 0x06);
  if (flag_nc()) goto lab_p25_L_5F9C;
  a = (uint8_t)(a + 0x77);
  mem_write8(0x8446, a);
  a = 0xFE;
  goto lab_p25_L_5FAE;
  lab_p25_L_5F9C: ;
  set_hl(0x84C6);
  p00_L_1304();
  set_hl(0x84C6);
  p00_L_1304();
  a = 0x29;
  goto lab_p25_L_5FAE;
  lab_p25_L_5FAC: ;
  a = 0x28;
  lab_p25_L_5FAE: ;
  p25_L_58B7();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 25 cpu 0x5FB3 (offset 0x1FB3) */
void p25_L_5FB3(void) {
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x03);
  if (flag_nz()) return;
  a = mem_read8(0x85DF);
  flag_cmp(a, 0x01);
  return;
}

/* flash page 25 cpu 0x5FBF (offset 0x1FBF) */
void p25_L_5FBF(void) {
  goto lab_p25_L_5FBF;
  lab_p25_L_5FB8: ;
  if (flag_nz()) return;
  a = mem_read8(0x85DF);
  flag_cmp(a, 0x01);
  return;
  lab_p25_L_5FBF: ;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x28);
  goto lab_p25_L_5FB8;
}

/* flash page 25 cpu 0x60B2 (offset 0x20B2) */
void p25_L_60B2(void) {
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x52);
  a = b;
  return;
}

/* flash page 25 cpu 0x60BA (offset 0x20BA) */
void p25_L_60BA(void) {
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x50);
  a = b;
  return;
}

/* flash page 25 cpu 0x60C2 (offset 0x20C2) */
void p25_L_60C2(void) {
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x44);
  a = b;
  return;
}

/* flash page 25 cpu 0x60CA (offset 0x20CA) */
void p25_L_60CA(void) {
  p00_L_3D7D();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x04);
  if (flag_nz()) return;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  set_hl(0x26AE);
  a = 0x05;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  p00_L_3C87();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 25 cpu 0x60F9 (offset 0x20F9) */
void p25_L_60F9(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  cpu_push16(ix);
  b = 0x40;
  set_hl(0x86EC);
  a = mem_read8((uint16_t)(iy + 0x14));
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 1)));
  p00_L_33ED();
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x14), a);
  ix = cpu_pop16();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 25 cpu 0x611A (offset 0x211A) */
void p25_L_611A(void) {
  goto lab_p25_L_611A;
  lab_p25_L_6113: ;
  ix = cpu_pop16();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
  lab_p25_L_611A: ;
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  cpu_push16(ix);
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p25_L_6133;
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p25_L_6133;
  p00_L_3DA1();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  lab_p25_L_6133: ;
  set_hl(0x86EC);
  p25_L_613B();
  goto lab_p25_L_6113;
}

/* flash page 25 cpu 0x613B (offset 0x213B) */
void p25_L_613B(void) {
  b = 0x40;
  /* di */
  a = 0x07;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  a = 0x7F;
  cpu_push_bc();
  a = (uint8_t)(a + 1);
  mem_write8(0x8451, a);
  p00_lcd_cmd_07();
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  a = 0x20;
  p25_L_6156();
  return;
}

/* flash page 25 cpu 0x6156 (offset 0x2156) */
void p25_L_6156(void) {
  goto lab_p25_L_6156;
  lab_p25_L_6147: ;
  cpu_push_bc();
  a = (uint8_t)(a + 1);
  mem_write8(0x8451, a);
  p00_lcd_cmd_07();
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  a = 0x20;
  lab_p25_L_6156: ;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  b = 0x0C;
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  lab_p25_L_6162: ;
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_6162;
  cpu_pop_bc();
  a = mem_read8(0x8451);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_6147;
  a = 0x05;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  return;
}

/* flash page 25 cpu 0x65FF (offset 0x25FF) */
void p25_L_65FF(void) {
  goto lab_p25_L_65FF;
  lab_p25_L_65FD: ;
  a = mem_read8(0x38FC);
  lab_p25_L_65FF: ;
  if (flag_c()) goto lab_p25_L_65FD;
  /* call 0xFC42 - RAM/other */
  b = d;
  /* call 0xFE43 - RAM/other */
  b = e;
  flag_cmp(a, 0xBE);
  cpu_cp_hl();
  flag_cmp(a, 0xC2);
  /* call 0xFE90 - RAM/other */
  a = a ^ 0xFC;
  flag_logic(a);
  l = e;
  /* call 0xFC6C - RAM/other */
  a = (uint8_t)(a + h);
  /* call 0xFC87 - RAM/other */
  /* adc a,b */
  flag_cmp(a, 0xBD);
  flag_cmp(a, 0xB7);
  flag_cmp(a, 0xB8);
  flag_cmp(a, 0xB9);
  flag_cmp(a, 0xBB);
  flag_cmp(a, 0xBC);
  flag_cmp(a, 0xBA);
  /* call 0xFC94 - RAM/other */
  a = (uint8_t)(a - l);
  /* call 0xFC70 - RAM/other */
  mem_write8(hl(), c);
  /* call 0xFC72 - RAM/other */
  mem_write8(hl(), e);
  /* call 0xFC74 - RAM/other */
  mem_write8(hl(), l);
  /* call 0xFC76 - RAM/other */
  mem_write8(hl(), a);
  /* call 0xFC78 - RAM/other */
  /* add a,(hl) */
  /* call 0xFC79 - RAM/other */
  a = d;
  /* call 0xFC7B - RAM/other */
  a = h;
  /* call 0xFC7D - RAM/other */
  a = mem_read8(hl());
  /* call 0xFC7F - RAM/other */
  a = (uint8_t)(a + b);
  /* call 0xFE81 - RAM/other */
  /* jp 0xC4FE - other page/RAM */
}

/* flash page 25 cpu 0x6784 (offset 0x2784) */
void p25_L_6784(void) {
  d = (uint8_t)(d - 1);
  set_bc(0x2102);
  /* nop */
  a = mem_read8(de());
  /* nop */
  d = (uint8_t)(d - 1);
  set_bc(0x5501);
  /* nop */
  d = (uint8_t)(d - 1);
  set_bc(0x3608);
  set_bc(0x004C);
  c = l;
  p00_rst38_isr();
  a = a & h;
  flag_logic(a);
  p00_rst38_isr();
  /* call 0x9AFC - RAM/other */
  /* call 0x829B - RAM/other */
  c = c;
  a = (uint8_t)(a + d);
  d = d;
  set_bc(0x270D);
  /* nop */
  cpu_rra();
  set_bc(0x021F);
  cpu_rra();
  set_bc((uint16_t)(bc() + 1));
  cpu_rra();
  b = (uint8_t)(b + 1);
  cpu_rra();
  b = (uint8_t)(b - 1);
  cpu_rra();
  b = 0x1F;
  cpu_rlca();
  cpu_rra();
  cpu_ex_af();
  cpu_rra();
  set_hl((uint16_t)(hl() + bc()));
  cpu_rra();
  set_bc((uint16_t)(bc() - 1));
  cpu_rra();
  c = (uint8_t)(c + 1);
  cpu_rra();
  c = (uint8_t)(c - 1);
  cpu_rra();
  set_bc((uint16_t)(bc() + 1));
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  set_bc(0x1F45);
  e = (uint8_t)(e + 1);
  a = (uint8_t)(a + d);
  c = l;
  a = (uint8_t)(a + d);
  c = e;
  a = (uint8_t)(a + d);
  c = mem_read8(hl());
  a = (uint8_t)(a + d);
  c = a;
  a = (uint8_t)(a + d);
  d = b;
  a = (uint8_t)(a + d);
  d = c;
  set_bc(0x4C02);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_6819;
  set_bc(0x014E);
  mem_write8(bc(), a);
  c = e;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_6820;
  mem_write8(bc(), a);
  c = mem_read8(hl());
  set_bc(0x4A02);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_6827;
  set_bc((uint16_t)(bc() + 1));
  c = mem_read8(hl());
  set_bc(0x4E02);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_682E;
  b = (uint8_t)(b + 1);
  c = mem_read8(hl());
  set_bc(0x4F02);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_6835;
  /* nop */
  c = mem_read8(hl());
  set_bc(0x4D02);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_683C;
  /* nop */
  c = a;
  set_bc(0x0001);
  cpu_rra();
  mem_write8(de(), a);
  cpu_rra();
  h = (uint8_t)(h + 1);
  cpu_rra();
  mem_write8(hl(), 0x1F);
  c = b;
  cpu_rra();
  e = d;
  cpu_rra();
  l = h;
  cpu_rra();
  a = mem_read8(hl());
  set_bc(0x2E01);
  /* nop */
  b = b;
  set_bc(0x2E02);
  /* nop */
  b = b;
  lab_p25_L_6819: ;
  /* nop */
  a = (uint8_t)(a - 0x02);
  set_bc(0x6200);
  h = e;
  lab_p25_L_6820: ;
  /* nop */
  e = c;
  set_bc(0x620C);
  /* nop */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_6828;
  lab_p25_L_6827: ;
  /* nop */
  lab_p25_L_6828: ;
  set_de(0x1F06);
  set_bc((uint16_t)(bc() + 1));
  cpu_rra();
  cpu_ex_af();
  lab_p25_L_682E: ;
  cpu_rra();
  cpu_rlca();
  cpu_rra();
  b = (uint8_t)(b + 1);
  cpu_rra();
  set_bc(0x021F);
  lab_p25_L_6835: ;
  mem_write8(bc(), a);
  cpu_rra();
  b = (uint8_t)(b - 1);
  cpu_rra();
  set_hl((uint16_t)(hl() + bc()));
  cpu_rra();
  c = (uint8_t)(c + 1);
  lab_p25_L_683C: ;
  cpu_rra();
  mem_write8(bc(), a);
  /* nop */
  set_bc(0x6447);
  c = 0x1F;
  l = 0x2D;
  sp = 0x3B36;
  if (flag_nc()) goto lab_p25_L_68A9;
  h = b;
  h = d;
  h = e;
  h = h;
  h = l;
  l = b;
  l = e;
  e = e;
  p25_L_6853();
  return;
  lab_p25_L_68A9: ;
  set_bc((uint16_t)(bc() - 1));
  /* nop */
  set_hl(0x68B1);
  /* cpir */
  return;
}

/* flash page 25 cpu 0x6853 (offset 0x2853) */
void p25_L_6853(void) {
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) | (1u << 4)));
  return;
}

/* flash page 25 cpu 0x6858 (offset 0x2858) */
void p25_L_6858(void) {
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p25_L_6860;
  set_hl((uint16_t)(hl() - 1));
  lab_p25_L_6860: ;
  b = 0x05;
  goto lab_p25_L_686C;
  lab_p25_L_686C: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_6876;
  p00_L_3F9F();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_686C;
  lab_p25_L_6876: ;
  p00_L_3D1D();
  return;
}

/* flash page 25 cpu 0x687A (offset 0x287A) */
void p25_L_687A(void) {
  p25_L_5053();
  if (flag_c()) return;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  p25_L_5C21();
  p00_L_3F5D();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  return;
}

/* flash page 25 cpu 0x688D (offset 0x288D) */
void p25_L_688D(void) {
  set_bc(0x0012);
  set_hl(0x6896);
  /* cpir */
  return;
}

/* flash page 25 cpu 0x68A8 (offset 0x28A8) */
void p25_L_68A8(void) {
  set_bc(0x000B);
  set_hl(0x68B1);
  /* cpir */
  return;
}

/* flash page 25 cpu 0x68CF (offset 0x28CF) */
void p25_L_68CF(void) {
  b = 0x0A;
  lab_p25_L_68D1: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, d);
  if (flag_nz()) goto lab_p25_L_68D9;
  a = mem_read8(hl());
  flag_cmp(a, e);
  if (flag_z()) return;
  lab_p25_L_68D9: ;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_68D1;
  return;
}

/* flash page 25 cpu 0x68DD (offset 0x28DD) */
void p25_L_68DD(void) {
  set_hl(0x65C0);
  p25_L_68CF();
  if (flag_z()) goto lab_p25_L_68F5;
  set_hl(0x65A9);
  p25_L_68CF();
  if (flag_z()) goto lab_p25_L_68F5;
  set_hl(0x65D7);
  p25_L_68CF();
  if (flag_nz()) goto lab_p25_L_6908;
  lab_p25_L_68F5: ;
  a = e;
  mem_write8(0x8446, a);
  a = d;
  p00_L_3BBB();
  p00_L_1295();
  set_hl(0x8479);
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), e);
  goto lab_p25_L_690F;
  lab_p25_L_6908: ;
  p25_L_54DF();
  if (flag_c()) return;
  p00_L_328B();
  lab_p25_L_690F: ;
  p00_rst10();
  if (flag_c()) return;
  goto lab_p25_L_6919;
  lab_p25_L_6919: ;
  p00_L_2408();
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  a = 0x2A;
  p00_L_3F9F();
  return;
}

/* flash page 25 cpu 0x6913 (offset 0x2913) */
void p25_L_6913(void) {
  cpu_push_bc();
  p00_L_19ED();
  cpu_pop_bc();
  if (flag_c()) return;
  p00_L_2408();
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  a = 0x2A;
  p00_L_3F9F();
  return;
}

/* flash page 25 cpu 0x6925 (offset 0x2925) */
void p25_L_6925(void) {
  p25_L_4EFB();
  if (flag_z()) goto lab_p25_L_692E;
  p25_L_4F07();
  if (flag_nz()) return;
  lab_p25_L_692E: ;
  a = mem_read8(0x85DE);
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p25_L_6935;
  a = 0;
  flag_logic(a);
  lab_p25_L_6935: ;
  mem_write8(0x984B, a);
  a = b;
  return;
}

/* flash page 25 cpu 0x693A (offset 0x293A) */
void p25_L_693A(void) {
  p00_L_18B7();
  if (flag_nz()) goto lab_p25_L_6943;
  p00_L_17D6();
  if (flag_z()) return;
  lab_p25_L_6943: ;
  p00_L_339F();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 1)));
  p00_L_0087();
  return;
}

/* flash page 25 cpu 0x6940 (offset 0x2940) */
void p25_L_6940(void) {
  a = (uint8_t)(a - 0x17);
  if (flag_z()) return;
  p00_L_339F();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 1)));
  p00_L_0087();
  return;
}

/* flash page 25 cpu 0x6951 (offset 0x2951) */
void p25_L_6951(void) {
  a = mem_read8(0x85E2);
  set_hl(0x85E0);
  /* sub (hl) */
  flag_cmp(a, 0x08);
  if (flag_c()) return;
  a = mem_read8(0x97A6);
  a = (uint8_t)(a - 1);
  l = a;
  h = 0x01;
  a = 0x1F;
  goto lab_p25_L_696B;
  lab_p25_L_696B: ;
  set_de(mem_read16(0x844B));
  mem_write16(0x844B, hl());
  p00_L_3F9F();
  mem_write16(0x844B, de());
  return;
}

/* flash page 25 cpu 0x6966 (offset 0x2966) */
void p25_L_6966(void) {
  set_hl(0x0101);
  a = 0x1E;
  set_de(mem_read16(0x844B));
  mem_write16(0x844B, hl());
  p00_L_3F9F();
  mem_write16(0x844B, de());
  return;
}

/* flash page 25 cpu 0x697A (offset 0x297A) */
void p25_L_697A(void) {
  a = 0x01;
  mem_write8(0x844C, a);
  a = 0x3A;
  p00_L_3F9F();
  return;
}

/* flash page 25 cpu 0x6985 (offset 0x2985) */
void p25_L_6985(void) {
  p25_L_698E();
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  return;
}

/* flash page 25 cpu 0x698E (offset 0x298E) */
void p25_L_698E(void) {
  set_hl(0x5E20);
  a = (uint8_t)(a - 1);
  a = (uint8_t)(a + a);
  goto lab_p25_L_6996;
  lab_p25_L_6996: ;
  a = (uint8_t)(a + l);
  mem_write8(0x847A, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x847B, a);
  l = 0x03;
  mem_write16(0x8478, hl());
  return;
}

/* flash page 25 cpu 0x69A4 (offset 0x29A4) */
void p25_L_69A4(void) {
  goto lab_p25_L_69A4;
  lab_p25_L_6995: ;
  a = (uint8_t)(a - 1);
  a = (uint8_t)(a + l);
  mem_write8(0x847A, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x847B, a);
  l = 0x03;
  mem_write16(0x8478, hl());
  return;
  lab_p25_L_69A4: ;
  set_hl(0x5E10);
  goto lab_p25_L_6995;
}

/* flash page 25 cpu 0x69A9 (offset 0x29A9) */
void p25_L_69A9(void) {
  goto lab_p25_L_69A9;
  lab_p25_L_6995: ;
  a = (uint8_t)(a - 1);
  a = (uint8_t)(a + l);
  mem_write8(0x847A, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x847B, a);
  l = 0x03;
  mem_write16(0x8478, hl());
  return;
  lab_p25_L_69A9: ;
  set_hl(0x5E40);
  goto lab_p25_L_6995;
}

/* flash page 25 cpu 0x69AE (offset 0x29AE) */
void p25_L_69AE(void) {
  a = mem_read8(0x8D1B);
  p25_L_69B1();
  return;
}

/* flash page 25 cpu 0x69B1 (offset 0x29B1) */
void p25_L_69B1(void) {
  p00_L_0013();
  if (flag_nz()) { p25_L_69A4(); return; }
  p00_L_01A2();
  if (flag_nz()) { p25_L_698E(); return; }
  p00_L_019D();
  if (flag_z()) { p25_L_69A9(); return; }
  p25_L_69C0();
  return;
}

/* flash page 25 cpu 0x69C0 (offset 0x29C0) */
void p25_L_69C0(void) {
  goto lab_p25_L_69C0;
  lab_p25_L_6995: ;
  a = (uint8_t)(a - 1);
  a = (uint8_t)(a + l);
  mem_write8(0x847A, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x847B, a);
  l = 0x03;
  mem_write16(0x8478, hl());
  return;
  lab_p25_L_69C0: ;
  set_hl(0x5E80);
  goto lab_p25_L_6995;
}

/* flash page 25 cpu 0x69C8 (offset 0x29C8) */
void p25_L_69C8(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x8670, a);
  mem_write8(0x97A5, a);
  mem_write8(0x85D9, a);
  mem_write8(0x8672, a);
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  p00_L_2D7B();
  set_hl(0x6EC0);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 6)));
  p25_L_69EE();
  return;
}

/* flash page 25 cpu 0x69EE (offset 0x29EE) */
void p25_L_69EE(void) {
  /* res 0,(iy) */
  p25_L_7282();
  p00_L_19E3();
  if (flag_c()) { p25_L_6D4E(); return; }
  cpu_ex_de_hl();
  mem_write16(0x986C, hl());
  a = b;
  mem_write8(0x986B, a);
  set_de(0x0001);
  p00_L_2CC7();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  p00_L_2CCD();
  e = a;
  cpu_push_de();
  mem_write16(0x986C, hl());
  set_de(0x0001);
  p00_L_2CC7();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  cpu_pop_de();
  p00_L_2CCD();
  d = a;
  cpu_push_de();
  set_de(0x0001);
  p00_L_2CC7();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  cpu_pop_de();
  cpu_push_hl();
  p00_L_2CC7();
  a = mem_read8(0x986B);
  mem_write8(0x8392, a);
  set_hl(mem_read16(0x986C));
  mem_write16(0x8393, hl());
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  a = b;
  p00_L_23F6();
  if (flag_nc()) goto lab_p25_L_6A4F;
  a = (uint8_t)(a + 1);
  lab_p25_L_6A4F: ;
  mem_write8(0x986B, a);
  p00_L_2CCD();
  b = a;
  mem_write16(0x986C, hl());
  set_de(0x0001);
  p00_L_2CC7();
  lab_p25_L_6A5F: ;
  p00_L_2CC7();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_6A5F;
  set_de(0x0002);
  p00_L_2CC7();
  mem_write16(0x986C, hl());
  p00_L_3E8B();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  set_hl(0x2828);
  a = 0x66;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3C87();
  set_hl(0x0001);
  mem_write16(0x844B, hl());
  p25_L_7282();
  set_hl(0x8479);
  b = 0x08;
  lab_p25_L_6A93: ;
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_6A9D;
  p00_L_3F9F();
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_6A93;
  lab_p25_L_6A9D: ;
  p00_L_3CD5();
  p00_L_1295();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  mem_write8(0x8395, a);
  mem_write16(0x8396, hl());
  p00_L_2CCD();
  flag_cmp(a, 0xFF);
  if (flag_z()) { p25_L_6D4E(); return; }
  a = (uint8_t)(a & ~(1u << 7));
  mem_write8(0x8478, a);
  a = a | a;
  flag_logic(a);
  p00_L_23F6();
  if (flag_nc()) goto lab_p25_L_6AC9;
  a = mem_read8(0x986B);
  a = (uint8_t)(a + 1);
  mem_write8(0x986B, a);
  lab_p25_L_6AC9: ;
  p00_L_17B0();
  if (flag_z()) goto lab_p25_L_6AD7;
  p00_L_1830();
  if (flag_z()) goto lab_p25_L_6AD7;
  b = 0x03;
  goto lab_p25_L_6AF7;
  lab_p25_L_6AD7: ;
  a = mem_read8(0x986B);
  p00_L_2CCD();
  b = a;
  p00_L_1037();
  p00_L_1830();
  if (flag_nz()) goto lab_p25_L_6AE7;
  b = (uint8_t)(b - 1);
  lab_p25_L_6AE7: ;
  a = a | a;
  flag_logic(a);
  set_hl((uint16_t)(hl() + 1));
  cpu_push_bc();
  p00_L_23FC();
  if (flag_nc()) goto lab_p25_L_6AF6;
  a = mem_read8(0x986B);
  a = (uint8_t)(a + 1);
  mem_write8(0x986B, a);
  lab_p25_L_6AF6: ;
  cpu_pop_bc();
  lab_p25_L_6AF7: ;
  set_de(0x8479);
  lab_p25_L_6AFA: ;
  a = mem_read8(0x986B);
  p00_L_2CCD();
  mem_write8(de(), a);
  a = a | a;
  flag_logic(a);
  set_hl((uint16_t)(hl() + 1));
  cpu_push_de();
  cpu_push_bc();
  p00_L_23FC();
  if (flag_nc()) goto lab_p25_L_6B11;
  a = mem_read8(0x986B);
  a = (uint8_t)(a + 1);
  mem_write8(0x986B, a);
  lab_p25_L_6B11: ;
  cpu_pop_bc();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_6AFA;
  mem_write16(0x8390, hl());
  a = mem_read8(0x8478);
  flag_cmp(a, 0x0F);
  if (flag_z()) goto lab_p25_L_6D59;
  flag_cmp(a, 0x11);
  if (flag_z()) goto lab_p25_L_6D59;
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p25_L_6D59;
  p00_L_19ED();
  mem_write16(0x83F1, hl());
  if (flag_nc()) goto lab_p25_L_6B63;
  p25_L_6B33();
  return;
  lab_p25_L_6B63: ;
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_6B73;
  p00_L_1100();
  p00_L_10DD();
  b = 0x43;
  a = 0;
  flag_logic(a);
  p00_L_2E11();
  return;
  lab_p25_L_6B73: ;
  mem_write16(0x83F3, de());
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  p00_L_23FA();
  if (flag_nc()) goto lab_p25_L_6B83;
  a = (uint8_t)(a + 1);
  lab_p25_L_6B83: ;
  p00_L_2CCD();
  flag_cmp(a, 0x04);
  if (flag_c()) goto lab_p25_L_6B93;
  p00_L_1100();
  p00_L_10DD();
  p25_L_7288();
  return;
  lab_p25_L_6B93: ;
  p00_L_1100();
  p00_L_10DD();
  a = 0;
  flag_logic(a);
  mem_write8(0x8672, a);
  set_hl(mem_read16(0x83F1));
  p00_L_2DB7();
  if (flag_nz()) goto lab_p25_L_6BAB;
  p00_L_16F4();
  p25_L_6C74();
  return;
  lab_p25_L_6BAB: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p25_L_6BBF;
  a = 0x02;
  b = 0x42;
  p00_L_2E11();
  return;
  lab_p25_L_6BBF: ;
  p00_L_16F4();
  p00_L_18AE();
  if (flag_nc()) { p25_L_6BCA(); return; }
  p00_L_0087();
  p25_L_6BCA();
  return;
  lab_p25_L_6D59: ;
  cpu_push_af();
  p00_L_0087();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  set_de(0x0009);
  p00_L_2CC7();
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  cpu_push_af();
  cpu_push_hl();
  p00_L_2CCD();
  c = a;
  p00_L_2CDF();
  a = mem_read8(0x986B);
  p00_L_2CCD();
  b = a;
  set_bc((uint16_t)(bc() + 1));
  set_bc((uint16_t)(bc() + 1));
  p00_L_2CDF();
  cpu_pop_hl();
  cpu_pop_af();
  mem_write8(0x986B, a);
  cpu_pop_af();
  cpu_push_bc();
  cpu_push_hl();
  p00_L_2DC9();
  p00_L_2DE7();
  cpu_pop_hl();
  mem_write16(0x986C, hl());
  set_hl(0x8670);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 4)));
  a = mem_read8(0x85D0);
  p25_L_71AB();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  a = (uint8_t)(a - 0x0F);
  p00_L_2DF9();
  cpu_ex_de_hl();
  set_hl(mem_read16(0x986C));
  a = mem_read8(0x986B);
  cpu_pop_bc();
  cpu_push_bc();
  p00_L_2F8B();
  cpu_pop_de();
  p25_L_6D33();
  return;
}

/* flash page 25 cpu 0x6B33 (offset 0x2B33) */
void p25_L_6B33(void) {
  p00_L_2DC9();
  set_bc(mem_read16(0x986C));
  set_hl(mem_read16(0x8390));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  p00_L_1B33();
  if (flag_c()) { p00_L_24F9(); return; }
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  p00_L_23FA();
  if (flag_nc()) goto lab_p25_L_6B52;
  a = (uint8_t)(a + 1);
  lab_p25_L_6B52: ;
  p00_L_2CCD();
  flag_cmp(a, 0x04);
  if (flag_c()) goto lab_p25_L_6C86;
  p00_L_1100();
  p00_L_10DD();
  p25_L_7288();
  return;
  lab_p25_L_6C86: ;
  p25_L_728E();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  cpu_push_af();
  cpu_push_hl();
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  p00_L_2FC7();
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 4)));
  mem_write16(0x83F1, de());
  cpu_ex_de_hl();
  a = mem_read8(hl());
  mem_write8(0x85D0, a);
  cpu_pop_hl();
  cpu_pop_af();
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  p00_L_2DE7();
  set_hl(0x8670);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 4)));
  set_hl(mem_read16(0x83F1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  p00_L_2CCD();
  a = a & 0xE0;
  flag_logic(a);
  set_hl(mem_read16(0x83F1));
  b = a;
  a = mem_read8(hl());
  a = a | b;
  flag_logic(a);
  mem_write8(hl(), a);
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) p00_L_0087();
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) p00_L_0087();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  p00_L_2CD3();
  a = mem_read8(0x986B);
  p00_L_2CCD();
  e = a;
  cpu_push_de();
  set_de(0x0001);
  p00_L_2CC7();
  cpu_pop_de();
  a = mem_read8(0x986B);
  p00_L_2CCD();
  d = a;
  set_hl((uint16_t)(hl() - 1));
  cpu_push_hl();
  a = mem_read8(0x85D0);
  p00_L_20F8();
  cpu_push_de();
  cpu_pop_bc();
  cpu_push_bc();
  cpu_ex_de_hl();
  p00_L_1B33();
  if (flag_c()) goto lab_p25_L_6DB8;
  cpu_push_de();
  cpu_pop_bc();
  a = a | 0x01;
  flag_logic(a);
  p00_L_1A99();
  mem_write16(0x83EF, de());
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5E);
  if (flag_nz()) goto lab_p25_L_6D1C;
  mem_write16(0x9832, de());
  lab_p25_L_6D1C: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x83EE, a);
  set_hl(mem_read16(0x83F1));
  p00_L_2EDD();
  cpu_pop_bc();
  cpu_pop_hl();
  a = mem_read8(0x986B);
  cpu_push_bc();
  mem_write16(0x986C, hl());
  p00_L_2F8B();
  cpu_pop_de();
  p25_L_6D33();
  return;
  lab_p25_L_6DB8: ;
  set_hl(mem_read16(0x83F1));
  p00_L_1F38();
  p00_L_24F9();
  return;
}

/* flash page 25 cpu 0x6BCA (offset 0x2BCA) */
void p25_L_6BCA(void) {
  p00_L_2DC9();
  set_de(mem_read16(0x83F3));
  set_hl(mem_read16(0x83F1));
  b = 0x00;
  p00_L_1F58();
  p25_L_6B33();
  return;
}

/* flash page 25 cpu 0x6C4B (offset 0x2C4B) */
void p25_L_6C4B(void) {
  p00_L_2F61();
  p25_L_7274();
  set_hl(mem_read16(0x8398));
  mem_write16(0x844B, hl());
  p00_L_3D29();
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) | (1u << 4)));
  set_hl(0x8670);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  set_hl(mem_read16(0x83F1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  p00_L_1100();
  p00_L_18AE();
  if (flag_nc()) { p25_L_6B33(); return; }
  p00_L_16F4();
  p25_L_6C74();
  return;
}

/* flash page 25 cpu 0x6C74 (offset 0x2C74) */
void p25_L_6C74(void) {
  p25_L_728E();
  p00_rst10();
  if (flag_c()) return;
  mem_write16(0x83F1, hl());
  mem_write16(0x83F3, de());
  p00_L_113F();
  p25_L_6BCA();
  return;
}

/* flash page 25 cpu 0x6D33 (offset 0x2D33) */
void p25_L_6D33(void) {
  goto lab_p25_L_6D33;
  lab_p25_L_6AA0: ;
  p00_L_1295();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  mem_write8(0x8395, a);
  mem_write16(0x8396, hl());
  p00_L_2CCD();
  flag_cmp(a, 0xFF);
  if (flag_z()) { p25_L_6D4E(); return; }
  a = (uint8_t)(a & ~(1u << 7));
  mem_write8(0x8478, a);
  a = a | a;
  flag_logic(a);
  p00_L_23F6();
  if (flag_nc()) goto lab_p25_L_6AC9;
  a = mem_read8(0x986B);
  a = (uint8_t)(a + 1);
  mem_write8(0x986B, a);
  lab_p25_L_6AC9: ;
  p00_L_17B0();
  if (flag_z()) goto lab_p25_L_6AD7;
  p00_L_1830();
  if (flag_z()) goto lab_p25_L_6AD7;
  b = 0x03;
  goto lab_p25_L_6AF7;
  lab_p25_L_6AD7: ;
  a = mem_read8(0x986B);
  p00_L_2CCD();
  b = a;
  p00_L_1037();
  p00_L_1830();
  if (flag_nz()) goto lab_p25_L_6AE7;
  b = (uint8_t)(b - 1);
  lab_p25_L_6AE7: ;
  a = a | a;
  flag_logic(a);
  set_hl((uint16_t)(hl() + 1));
  cpu_push_bc();
  p00_L_23FC();
  if (flag_nc()) goto lab_p25_L_6AF6;
  a = mem_read8(0x986B);
  a = (uint8_t)(a + 1);
  mem_write8(0x986B, a);
  lab_p25_L_6AF6: ;
  cpu_pop_bc();
  lab_p25_L_6AF7: ;
  set_de(0x8479);
  lab_p25_L_6AFA: ;
  a = mem_read8(0x986B);
  p00_L_2CCD();
  mem_write8(de(), a);
  a = a | a;
  flag_logic(a);
  set_hl((uint16_t)(hl() + 1));
  cpu_push_de();
  cpu_push_bc();
  p00_L_23FC();
  if (flag_nc()) goto lab_p25_L_6B11;
  a = mem_read8(0x986B);
  a = (uint8_t)(a + 1);
  mem_write8(0x986B, a);
  lab_p25_L_6B11: ;
  cpu_pop_bc();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_6AFA;
  mem_write16(0x8390, hl());
  a = mem_read8(0x8478);
  flag_cmp(a, 0x0F);
  if (flag_z()) goto lab_p25_L_6D59;
  flag_cmp(a, 0x11);
  if (flag_z()) goto lab_p25_L_6D59;
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p25_L_6D59;
  p00_L_19ED();
  mem_write16(0x83F1, hl());
  if (flag_nc()) goto lab_p25_L_6B63;
  p25_L_6B33();
  return;
  lab_p25_L_6B63: ;
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_6B73;
  p00_L_1100();
  p00_L_10DD();
  b = 0x43;
  a = 0;
  flag_logic(a);
  p00_L_2E11();
  return;
  lab_p25_L_6B73: ;
  mem_write16(0x83F3, de());
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  p00_L_23FA();
  if (flag_nc()) goto lab_p25_L_6B83;
  a = (uint8_t)(a + 1);
  lab_p25_L_6B83: ;
  p00_L_2CCD();
  flag_cmp(a, 0x04);
  if (flag_c()) goto lab_p25_L_6B93;
  p00_L_1100();
  p00_L_10DD();
  p25_L_7288();
  return;
  lab_p25_L_6B93: ;
  p00_L_1100();
  p00_L_10DD();
  a = 0;
  flag_logic(a);
  mem_write8(0x8672, a);
  set_hl(mem_read16(0x83F1));
  p00_L_2DB7();
  if (flag_nz()) goto lab_p25_L_6BAB;
  p00_L_16F4();
  p25_L_6C74();
  return;
  lab_p25_L_6BAB: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p25_L_6BBF;
  a = 0x02;
  b = 0x42;
  p00_L_2E11();
  return;
  lab_p25_L_6BBF: ;
  p00_L_16F4();
  p00_L_18AE();
  if (flag_nc()) { p25_L_6BCA(); return; }
  p00_L_0087();
  p25_L_6BCA();
  return;
  lab_p25_L_6D33: ;
  p00_L_2CC7();
  a = mem_read8(0x986B);
  b = a;
  a = mem_read8(0x8392);
  a = (uint8_t)(a - b);
  if (flag_nz()) goto lab_p25_L_6AA0;
  set_hl(mem_read16(0x8393));
  set_bc(mem_read16(0x986C));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nz()) goto lab_p25_L_6AA0;
  p25_L_6D4E();
  return;
  lab_p25_L_6D59: ;
  cpu_push_af();
  p00_L_0087();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  set_de(0x0009);
  p00_L_2CC7();
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  cpu_push_af();
  cpu_push_hl();
  p00_L_2CCD();
  c = a;
  p00_L_2CDF();
  a = mem_read8(0x986B);
  p00_L_2CCD();
  b = a;
  set_bc((uint16_t)(bc() + 1));
  set_bc((uint16_t)(bc() + 1));
  p00_L_2CDF();
  cpu_pop_hl();
  cpu_pop_af();
  mem_write8(0x986B, a);
  cpu_pop_af();
  cpu_push_bc();
  cpu_push_hl();
  p00_L_2DC9();
  p00_L_2DE7();
  cpu_pop_hl();
  mem_write16(0x986C, hl());
  set_hl(0x8670);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 4)));
  a = mem_read8(0x85D0);
  p25_L_71AB();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  a = (uint8_t)(a - 0x0F);
  p00_L_2DF9();
  cpu_ex_de_hl();
  set_hl(mem_read16(0x986C));
  a = mem_read8(0x986B);
  cpu_pop_bc();
  cpu_push_bc();
  p00_L_2F8B();
  cpu_pop_de();
  goto lab_p25_L_6D33;
}

/* flash page 25 cpu 0x6D4E (offset 0x2D4E) */
void p25_L_6D4E(void) {
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p00_L_2CD9();
  return;
}

/* flash page 25 cpu 0x6DCC (offset 0x2DCC) */
void p25_L_6DCC(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x9652, a);
  a = mem_read8(0x9652);
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  set_hl(0x6DE3);
  set_de(0x848E);
  p00_L_1185();
  p00_L_30F9();
  return;
}

/* flash page 25 cpu 0x6DE3 (offset 0x2DE3) */
void p25_str_8(void) {
  b = a;
  d = d;
  c = a;
  d = l;
  d = b;
  /* nop */
  p25_L_6DE9();
  return;
}

/* flash page 25 cpu 0x6DE9 (offset 0x2DE9) */
void p25_L_6DE9(void) {
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 0)));
  p00_L_21E5();
  set_hl(0x6EAE);
  p00_L_07CC();
  p00_L_2D7B();
  a = 0;
  flag_logic(a);
  mem_write8(0x85D9, a);
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  /* res 0,(iy) */
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  p00_L_17FA();
  a = 0x29;
  p25_L_6E19();
  p25_L_6E2D();
  return;
}

/* flash page 25 cpu 0x6E19 (offset 0x2E19) */
void p25_L_6E19(void) {
  cpu_push_af();
  p00_L_3E8B();
  cpu_pop_af();
  p25_L_5067();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 5)));
  return;
}

/* flash page 25 cpu 0x6E29 (offset 0x2E29) */
void p25_L_6E29(void) {
  a = 0x04;
  goto lab_p25_L_6E2E;
  lab_p25_L_6E2E: ;
  mem_write8(0x8672, a);
  return;
}

/* flash page 25 cpu 0x6E2D (offset 0x2E2D) */
void p25_L_6E2D(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x8672, a);
  return;
}

/* flash page 25 cpu 0x6E60 (offset 0x2E60) */
void p25_L_6E60(void) {
  mem_write8(0x85D0, a);
  p25_L_6E29();
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) | (1u << 1)));
  a = 0xFF;
  mem_write8(0x85D1, a);
  p00_L_3E8B();
  p00_L_3D2F();
  a = 0;
  flag_logic(a);
  mem_write8(0x8670, a);
  p00_L_3D17();
  set_hl(0x26AE);
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  a = 0x05;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3C87();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  set_hl(0x27F5);
  a = 0x67;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3C87();
  a = 0x01;
  p00_L_2E5F();
  return;
}

/* flash page 25 cpu 0x6ECD (offset 0x2ECD) */
void p25_L_6ECD(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  a = 0;
  flag_logic(a);
  mem_write8(0x85DE, a);
  mem_write8(0x984B, a);
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  p25_L_4126();
  p00_L_2D7B();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 3)));
  return;
}

/* flash page 25 cpu 0x6F6E (offset 0x2F6E) */
void p25_L_6F6E(void) {
  l = 0x01;
  p25_L_5069();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 5)));
  return;
}

/* flash page 25 cpu 0x6F78 (offset 0x2F78) */
void p25_L_6F78(void) {
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) | (1u << 2)));
  p00_L_2EA1();
  set_hl(0x0000);
  mem_write16(0x83F9, hl());
  mem_write16(0x83F7, hl());
  p25_L_70D3();
  cpu_push_bc();
  set_hl(0xFFFE);
  set_hl((uint16_t)(hl() + de()));
  if (flag_nc()) goto lab_p25_L_70B3;
  set_hl(mem_read16(0x83F9));
  mem_write16(0x83F7, hl());
  p00_L_22FC();
  set_hl(mem_read16(0x83F9));
  p00_L_19C5();
  a = (uint8_t)(a + 1);
  a = (uint8_t)(a + 0x06);
  c = a;
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x83F5, bc());
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x83F9, hl());
  set_hl(mem_read16(0x839F));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p25_L_6FD5;
  set_hl(mem_read16(0x83A1));
  set_de(mem_read16(0x83F9));
  a = h;
  h = l;
  l = a;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p25_L_6FD5;
  set_bc(mem_read16(0x83F9));
  p00_L_2EB3();
  p00_L_2559();
  return;
  lab_p25_L_6FD5: ;
  a = 0x08;
  mem_write8(0x8672, a);
  p00_L_3E8B();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  set_hl(mem_read16(0x83F7));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_70C1;
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) | (1u << 0)));
  set_bc(mem_read16(0x83F9));
  p00_L_2EB3();
  if (flag_c()) p00_L_2ED7();
  mem_write8(0x83EE, a);
  mem_write16(0x83EF, hl());
  p00_L_22FC();
  cpu_pop_bc();
  p00_L_1CC3();
  mem_write16(0x83F1, hl());
  cpu_push_hl();
  set_hl(0x27FB);
  a = 0x68;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3C87();
  p00_L_3CD5();
  set_hl(0x2803);
  a = 0x69;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3C87();
  p00_L_3CD5();
  set_hl(0x2810);
  a = 0x6A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3C87();
  p00_L_3CD5();
  p00_L_22FC();
  set_hl(0x8479);
  b = 0x08;
  lab_p25_L_7048: ;
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_7052;
  p00_L_3F9F();
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_7048;
  lab_p25_L_7052: ;
  set_hl(0x83F7);
  mem_write16(0x83F3, hl());
  set_hl(mem_read16(0x83F9));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x83F9, hl());
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) | (1u << 5)));
  p00_L_2EAD();
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 5)));
  a = mem_read8(0x83EE);
  mem_write8(0x986B, a);
  set_hl(mem_read16(0x83EF));
  mem_write16(0x986C, hl());
  set_de(mem_read16(0x83F5));
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_2CC7();
  a = mem_read8(0x986B);
  mem_write8(0x83EE, a);
  set_hl(mem_read16(0x986C));
  mem_write16(0x83EF, hl());
  p25_L_723B();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 0)));
  cpu_pop_hl();
  p00_L_2CF7();
  lab_p25_L_70A3: ;
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 1)));
  p00_L_3CDB();
  p00_L_3DFB();
  /* ei */
  a = 0;
  flag_logic(a);
  mem_write8(0x85D9, a);
  return;
  lab_p25_L_70B3: ;
  a = 0x08;
  mem_write8(0x8672, a);
  p00_L_3E8B();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  lab_p25_L_70C1: ;
  cpu_pop_hl();
  set_hl(0x2861);
  a = 0x7B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3C87();
  goto lab_p25_L_70A3;
}

/* flash page 25 cpu 0x70D3 (offset 0x30D3) */
void p25_L_70D3(void) {
  a = 0;
  flag_logic(a);
  d = a;
  e = a;
  cpu_push_de();
  set_hl(0xFE66);
  b = 0x01;
  p25_L_70DC();
  return;
}

/* flash page 25 cpu 0x70DC (offset 0x30DC) */
void p25_L_70DC(void) {
  lab_p25_L_70DC: ;
  cpu_push_bc();
  set_bc(mem_read16(0x982E));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p25_L_717B;
  if (flag_z()) goto lab_p25_L_717B;
  set_hl((uint16_t)(hl() + bc()));
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p25_L_7171;
  cpu_push_hl();
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p25_L_710C;
  p00_L_2407();
  a = mem_read8(hl());
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p25_L_710A;
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  flag_cmp(a, 0x40);
  if (flag_nz()) goto lab_p25_L_710A;
  cpu_pop_hl();
  goto lab_p25_L_7171;
  lab_p25_L_710A: ;
  cpu_pop_hl();
  cpu_push_hl();
  lab_p25_L_710C: ;
  p00_L_2406();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  cpu_pop_hl();
  flag_cmp(a, 0x62);
  if (flag_z()) goto lab_p25_L_7171;
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p25_L_7171;
  flag_cmp(a, 0x3E);
  if (flag_z()) goto lab_p25_L_7171;
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p25_L_7171;
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p25_L_7171;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p25_L_7171;
  e = a;
  flag_cmp(a, 0x5E);
  if (flag_z()) goto lab_p25_L_7137;
  a = c;
  flag_cmp(a, 0x2A);
  if (flag_z()) goto lab_p25_L_7171;
  lab_p25_L_7137: ;
  p00_L_1F55();
  if (flag_nz()) goto lab_p25_L_7171;
  a = mem_read8(hl());
  p00_L_1857();
  if (flag_z()) goto lab_p25_L_7155;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p25_L_7152;
  p00_L_17BE();
  if (flag_nz()) goto lab_p25_L_715A;
  a = c;
  lab_p25_L_714C: ;
  flag_cmp(a, 0x41);
  if (flag_c()) goto lab_p25_L_7171;
  goto lab_p25_L_715A;
  lab_p25_L_7152: ;
  a = e;
  goto lab_p25_L_714C;
  lab_p25_L_7155: ;
  p00_L_2CFD();
  if (flag_z()) goto lab_p25_L_7171;
  lab_p25_L_715A: ;
  cpu_pop_bc();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  cpu_push_bc();
  p00_L_3885();
  p00_L_2EA7();
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_bc();
  flag_cmp(a, b);
  if (flag_c()) goto lab_p25_L_7172;
  b = a;
  goto lab_p25_L_7172;
  lab_p25_L_7171: ;
  cpu_pop_bc();
  lab_p25_L_7172: ;
  p00_L_387F();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  goto lab_p25_L_70DC;
  lab_p25_L_717B: ;
  a = 0x0F;
  p25_L_71AB();
  cpu_pop_bc();
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p25_L_718B;
  p25_L_71B3();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  lab_p25_L_718B: ;
  a = 0x11;
  p25_L_71AB();
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p25_L_719A;
  p25_L_71B3();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  lab_p25_L_719A: ;
  a = 0x10;
  p25_L_71AB();
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p25_L_71A9;
  p25_L_71B3();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  lab_p25_L_71A9: ;
  cpu_pop_de();
  return;
}

/* flash page 25 cpu 0x71AB (offset 0x31AB) */
void p25_L_71AB(void) {
  set_hl(0x8685);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 25 cpu 0x71B3 (offset 0x31B3) */
void p25_L_71B3(void) {
  cpu_push_bc();
  a = (uint8_t)(a - 0x0F);
  p00_L_2DF9();
  mem_write16(0x83F3, hl());
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_bc((uint16_t)(bc() + 1));
  set_bc((uint16_t)(bc() + 1));
  mem_write16(0x83F7, bc());
  set_hl(0x0009);
  mem_write16(0x83F5, hl());
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  set_bc(mem_read16(0x83F9));
  /* adc hl,bc */
  mem_write16(0x83F9, hl());
  cpu_pop_bc();
  return;
}

/* flash page 25 cpu 0x71CD (offset 0x31CD) */
void p25_L_71CD(void) {
  c = d;
  set_bc(mem_read16(0x83F9));
  /* adc hl,bc */
  mem_write16(0x83F9, hl());
  cpu_pop_bc();
  return;
}

/* flash page 25 cpu 0x71D9 (offset 0x31D9) */
void p25_L_71D9(void) {
  set_de(0x0000);
  mem_write16(0x83F9, de());
  flag_cmp(a, 0x0F);
  if (flag_z()) goto lab_p25_L_720F;
  flag_cmp(a, 0x11);
  if (flag_z()) goto lab_p25_L_720F;
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p25_L_720F;
  p00_L_3885();
  lab_p25_L_71EF: ;
  set_bc(mem_read16(0x83F9));
  a = mem_read8(0x83EE);
  mem_write8(0x986B, a);
  set_hl(mem_read16(0x83EF));
  mem_write16(0x986C, hl());
  p00_L_2D03();
  a = mem_read8(0x986B);
  mem_write8(0x83EE, a);
  set_hl(mem_read16(0x986C));
  mem_write16(0x83EF, hl());
  return;
  lab_p25_L_720F: ;
  mem_write8(0x82DF, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x82DE, a);
  mem_write8(0x82DC, a);
  mem_write8(0x82DB, a);
  mem_write8(0x82DA, a);
  mem_write8(0x82D9, a);
  mem_write8(0x82D8, a);
  mem_write8(0x82D7, a);
  a = 0x03;
  mem_write8(0x82DD, a);
  a = mem_read8(0x82DF);
  p25_L_71B3();
  set_hl(0x82DF);
  mem_write16(0x83F1, hl());
  goto lab_p25_L_71EF;
}

/* flash page 25 cpu 0x7217 (offset 0x3217) */
void p25_L_7217(void) {
  goto lab_p25_L_7217;
  lab_p25_L_71EF: ;
  set_bc(mem_read16(0x83F9));
  a = mem_read8(0x83EE);
  mem_write8(0x986B, a);
  set_hl(mem_read16(0x83EF));
  mem_write16(0x986C, hl());
  p00_L_2D03();
  a = mem_read8(0x986B);
  mem_write8(0x83EE, a);
  set_hl(mem_read16(0x986C));
  mem_write16(0x83EF, hl());
  return;
  lab_p25_L_7217: ;
  if (flag_c()) p00_L_3282();
  a = hw_in(0x82);
  mem_write8(0x82DA, a);
  mem_write8(0x82D9, a);
  mem_write8(0x82D8, a);
  mem_write8(0x82D7, a);
  a = 0x03;
  mem_write8(0x82DD, a);
  a = mem_read8(0x82DF);
  p25_L_71B3();
  set_hl(0x82DF);
  mem_write16(0x83F1, hl());
  goto lab_p25_L_71EF;
}

/* flash page 25 cpu 0x723B (offset 0x323B) */
void p25_L_723B(void) {
  a = 0xFF;
  mem_write8(0x85D1, a);
  a = 0x08;
  mem_write8(0x8672, a);
  p00_L_2D09();
  mem_write8(0x8478, a);
  flag_cmp(a, 0x01);
  a = 0x40;
  if (flag_nz()) goto lab_p25_L_7258;
  a = 0xFF;
  mem_write8(0x847A, a);
  a = 0x5D;
  lab_p25_L_7258: ;
  mem_write8(0x8479, a);
  lab_p25_L_725B: ;
  p00_L_2DD5();
  if (flag_c()) return;
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p25_L_725B;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  cpu_push_hl();
  p00_L_2DC9();
  cpu_pop_hl();
  p25_L_71D9();
  p00_L_2F91();
  goto lab_p25_L_725B;
}

/* flash page 25 cpu 0x7274 (offset 0x3274) */
void p25_L_7274(void) {
  p00_L_3D7D();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  set_hl(0x8673);
  a = mem_read8(hl());
  mem_write8(hl(), 0x00);
  return;
}

/* flash page 25 cpu 0x7282 (offset 0x3282) */
void p25_L_7282(void) {
  set_hl(0x85E7);
  p00_L_11F2();
  return;
}

/* flash page 25 cpu 0x7288 (offset 0x3288) */
void p25_L_7288(void) {
  b = 0x41;
  a = 0;
  flag_logic(a);
  p00_L_2E11();
  return;
}

/* flash page 25 cpu 0x728E (offset 0x328E) */
void p25_L_728E(void) {
  a = mem_read8(0x85D0);
  p00_L_18AE();
  if (flag_nc()) goto lab_p25_L_72A5;
  p00_rst10();
  if (flag_c()) return;
  mem_write8(hl(), 0x83);
  mem_write16(0x981C, hl());
  mem_write16(0x84DD, de());
  h = a;
  p00_L_380D();
  lab_p25_L_72A5: ;
  return;
}

/* flash page 25 cpu 0x7313 (offset 0x3313) */
void p25_L_7313(void) {
  a = (uint8_t)(a + 0x9C);
  cpu_push_af();
  a = (uint8_t)(a - 0x20);
  a = (uint8_t)(a + a);
  b = a;
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + b);
  a = (uint8_t)(a + l);
  b = l;
  set_hl(0x7353);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  cpu_push_bc();
  a = b;
  flag_cmp(a, 0x07);
  if (flag_nc()) { p00_L_24E5(); return; }
  p25_L_73AE();
  lab_p25_L_7330: ;
  cpu_pop_bc();
  cpu_pop_hl();
  p00_L_1653();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  cpu_push_hl();
  cpu_push_bc();
  d = 0x00;
  cpu_ex_de_hl();
  p00_L_1025();
  set_de(0x9094);
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  p00_L_11FD();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_z()) goto lab_p25_L_7351;
  cpu_push_bc();
  p00_L_219B();
  goto lab_p25_L_7330;
  lab_p25_L_7351: ;
  cpu_pop_bc();
  goto lab_p25_L_7376;
  lab_p25_L_7376: ;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x21);
  if (flag_nz()) p25_L_772C();
  cpu_pop_af();
  p25_L_737E();
  return;
}

/* flash page 25 cpu 0x7372 (offset 0x3372) */
void p25_L_7372(void) {
  cpu_push_af();
  p25_L_73AE();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x21);
  if (flag_nz()) p25_L_772C();
  cpu_pop_af();
  p25_L_737E();
  return;
}

/* flash page 25 cpu 0x737E (offset 0x337E) */
void p25_L_737E(void) {
  a = (uint8_t)(a - 0x20);
  if (flag_c()) { p00_L_24E5(); return; }
  flag_cmp(a, 0x0D);
  if (flag_nc()) { p00_L_24E5(); return; }
  a = (uint8_t)(a + a);
  e = a;
  d = 0x00;
  set_hl(0x7394);
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  os_jp_hl();
  return;
}

/* flash page 25 cpu 0x73AE (offset 0x33AE) */
void p25_L_73AE(void) {
  set_hl(0x9055);
  set_de(0x9094);
  set_bc(0x003F);
  while (bc() != 0) { cpu_ldi(); }
  p00_L_172A();
  if (flag_z()) return;
  b = 0x07;
  lab_p25_L_73BF: ;
  p00_L_23CF();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p25_L_73BF;
  return;
}

/* flash page 25 cpu 0x73C7 (offset 0x33C7) */
void p25_L_73C7(void) {
  p25_L_749B();
  if (flag_nc()) goto lab_p25_L_73DD;
  p00_L_1251();
  set_hl(0x8484);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p00_L_0E5C();
  p00_L_107E();
  if (flag_z()) goto lab_p25_L_73DD;
  if (flag_nc()) goto lab_p25_L_73E7;
  lab_p25_L_73DD: ;
  p00_L_0C1B();
  p00_L_3921();
  return;
  lab_p25_L_73E7: ;
  p00_rst18();
  p00_L_1246();
  p00_rst30();
  p00_rst08();
  p00_L_219B();
  p00_L_0ED0();
  p00_L_3945();
  p00_L_0C18();
  return;
}

/* flash page 25 cpu 0x73F9 (offset 0x33F9) */
void p25_L_73F9(void) {
  p00_L_14CC();
  if (flag_z()) { p00_L_1179(); return; }
  p00_rst18();
  p00_L_1179();
  p25_L_749B();
  if (flag_nz()) goto lab_p25_L_741E;
  p00_L_15CB();
  if (flag_z()) { p00_L_219B(); return; }
  p00_L_22FC();
  p00_L_0C1B();
  p00_rst08();
  p00_L_219B();
  p00_L_0E4C();
  p00_L_0ED0();
  return;
  lab_p25_L_741E: ;
  p00_rst08();
  p00_L_219B();
  p00_L_21E0();
  p25_L_73C7();
  p00_L_2196();
  p00_L_0D1F();
  p25_L_749B();
  cpu_push_af();
  cpu_pop_af();
  if (flag_nc()) goto lab_p25_L_7450;
  p00_L_386D();
  p00_rst18();
  p00_L_1179();
  p00_L_0C1B();
  p00_rst08();
  p00_L_22FC();
  p00_L_0ED0();
  p00_L_0C1B();
  p00_L_2196();
  p00_L_0D1F();
  return;
  lab_p25_L_7450: ;
  p00_L_3933();
  p00_L_0C2A();
  return;
}

/* flash page 25 cpu 0x7468 (offset 0x3468) */
void p25_L_7468(void) {
  p00_L_14CC();
  if (flag_z()) { p00_L_1229(); return; }
  p00_rst18();
  p00_L_1179();
  p25_L_749B();
  if (flag_nz()) goto lab_p25_L_7487;
  p00_rst08();
  p00_L_219B();
  p00_L_15C6();
  cpu_push_af();
  p00_L_0C1B();
  cpu_pop_af();
  if (flag_z()) return;
  p00_L_0ECC();
  return;
  lab_p25_L_7487: ;
  p00_rst08();
  p00_L_219B();
  p00_L_21E0();
  p25_L_73C7();
  p00_L_2196();
  p00_L_0D1F();
  p00_L_3933();
  return;
}

/* flash page 25 cpu 0x749B (offset 0x349B) */
void p25_L_749B(void) {
  p25_L_74A4();
  cpu_push_af();
  p00_L_219B();
  cpu_pop_af();
  return;
}

/* flash page 25 cpu 0x74A4 (offset 0x34A4) */
void p25_L_74A4(void) {
  p00_rst18();
  p00_L_15D6();
  p25_L_74A8();
  return;
}

/* flash page 25 cpu 0x74A8 (offset 0x34A8) */
void p25_L_74A8(void) {
  p00_L_1251();
  p00_L_107E();
  return;
}

/* flash page 25 cpu 0x74BC (offset 0x34BC) */
void p25_L_74BC(void) {
  p00_L_1251();
  p00_L_3E37();
  p00_L_14E1();
  if (flag_z()) return;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x84);
  if (flag_nc()) { p00_L_24C9(); return; }
  p00_L_107E();
  if (flag_c()) { p00_L_24C9(); return; }
  return;
}

/* flash page 25 cpu 0x74D5 (offset 0x34D5) */
void p25_L_74D5(void) {
  p00_L_14C7();
  if (flag_z()) { p00_L_1179(); return; }
  p00_rst18();
  p25_L_73F9();
  p00_L_2196();
  p00_L_0ED0();
  return;
}

/* flash page 25 cpu 0x74E5 (offset 0x34E5) */
void p25_L_74E5(void) {
  p00_L_222C();
  p25_L_74D5();
  p25_L_74EB();
  return;
}

/* flash page 25 cpu 0x74EB (offset 0x34EB) */
void p25_L_74EB(void) {
  p00_rst18();
  p00_L_2324();
  p00_L_2310();
  p25_L_7468();
  p00_L_2196();
  p00_L_21A4();
  return;
}

/* flash page 25 cpu 0x74FB (offset 0x34FB) */
void p25_L_74FB(void) {
  p00_L_14C7();
  if (flag_nz()) goto lab_p25_L_7514;
  p00_L_1179();
  p00_rst18();
  p00_L_0C2A();
  p00_L_22F7();
  p00_L_0D1F();
  p00_L_0D16();
  p00_rst08();
  p00_L_219B();
  return;
  lab_p25_L_7514: ;
  p00_L_222C();
  p00_L_113F();
  p00_L_0D1F();
  p00_L_1100();
  p00_L_2315();
  p00_L_0C1B();
  p00_rst08();
  p00_L_113F();
  p00_L_0ED0();
  p00_L_1171();
  p00_L_10EF();
  p00_L_0C2D();
  p00_L_2310();
  p00_L_0ED0();
  p00_rst08();
  p00_L_113A();
  p00_L_21A4();
  return;
}

/* flash page 25 cpu 0x7543 (offset 0x3543) */
void p25_L_7543(void) {
  p00_L_0C1B();
  p00_L_1171();
  p00_L_2196();
  p00_L_0D1F();
  p00_L_0D16();
  p00_L_1169();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_2310();
  p00_rst30();
  p00_L_10DD();
  p00_L_0D1E();
  p00_rst18();
  p00_L_113A();
  p00_L_0C1B();
  p00_L_22C7();
  p00_L_0D1F();
  p00_L_1221();
  p00_L_0ED0();
  p00_L_10EF();
  p00_L_0C13();
  p00_L_1128();
  p00_L_0D1F();
  p00_L_2310();
  p00_rst30();
  p00_L_22C7();
  p00_L_0D1F();
  p00_L_2196();
  p00_L_0C2D();
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_75A8;
  p00_L_14A2();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_10EF();
  p00_L_0ED0();
  lab_p25_L_75A8: ;
  p00_L_21A4();
  p00_L_21A7();
  return;
}

/* flash page 25 cpu 0x75DE (offset 0x35DE) */
void p25_L_75DE(void) {
  set_hl(0x8479);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  return;
}

/* flash page 25 cpu 0x760A (offset 0x360A) */
void p25_L_760A(void) {
  goto lab_p25_L_760A;
  lab_p25_L_7607: ;
  p00_L_24C9();
  return;
  lab_p25_L_760A: ;
  p25_L_74A8();
  if (flag_z()) goto lab_p25_L_7607;
  if (flag_c()) goto lab_p25_L_7607;
  p00_L_3E37();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x84);
  if (flag_nc()) goto lab_p25_L_7607;
  b = 0x00;
  flag_cmp(a, 0x82);
  if (flag_c()) goto lab_p25_L_7624;
  b = (uint8_t)(b + 1);
  goto lab_p25_L_7627;
  lab_p25_L_7624: ;
  p25_L_75DE();
  lab_p25_L_7627: ;
  flag_set_z((b & (1u << 0)) == 0);
  cpu_push_af();
  p00_L_10DD();
  p00_L_0C0F();
  p00_L_1171();
  p00_L_10EF();
  p00_L_0C13();
  p25_L_75DE();
  p00_L_14E1();
  if (flag_nz()) goto lab_p25_L_7607;
  a = 0x32;
  p25_L_7726();
  if (flag_nc()) goto lab_p25_L_764F;
  set_hl(0x0064);
  p00_L_3B55();
  p00_rst30();
  lab_p25_L_764F: ;
  p00_rst18();
  p00_L_1135();
  p00_L_15DD();
  p00_L_0C0F();
  p00_L_1884();
  p00_L_1169();
  p25_L_75DE();
  p00_L_1108();
  p00_L_0C13();
  p00_L_1884();
  cpu_pop_af();
  if (flag_z()) p00_L_148B();
  a = 0x0D;
  p25_L_7726();
  if (flag_nc()) { p00_L_24C9(); return; }
  p00_L_1171();
  p00_L_3B5B();
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p25_L_76BD;
  p00_L_22FC();
  set_hl(0x076C);
  p00_L_3B55();
  p00_rst30();
  p00_L_10DD();
  p00_L_121A();
  p00_L_0ED0();
  p00_L_14E1();
  if (flag_nz()) goto lab_p25_L_76AD;
  p00_L_1135();
  p25_L_771B();
  if (flag_nz()) goto lab_p25_L_76A9;
  p00_L_1251();
  p25_L_771B();
  if (flag_z()) goto lab_p25_L_76AD;
  lab_p25_L_76A9: ;
  a = 0x1D;
  goto lab_p25_L_76AF;
  lab_p25_L_76AD: ;
  a = 0x1C;
  lab_p25_L_76AF: ;
  p00_L_355B();
  p00_L_1128();
  p00_L_107E();
  if (flag_c()) { p00_L_24C9(); return; }
  goto lab_p25_L_76CE;
  lab_p25_L_76BD: ;
  set_hl(0x770E);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  p00_L_355B();
  p00_L_1128();
  p00_L_107E();
  if (flag_c()) { p00_L_24C9(); return; }
  lab_p25_L_76CE: ;
  p00_L_113A();
  a = 0x03;
  p25_L_7726();
  cpu_push_af();
  if (flag_c()) goto lab_p25_L_76DE;
  p00_L_0C2D();
  goto lab_p25_L_76E4;
  lab_p25_L_76DE: ;
  a = 0x09;
  p00_L_3561();
  p00_rst30();
  lab_p25_L_76E4: ;
  set_hl(0x7456);
  p00_L_0D19();
  set_hl(0x0FC3);
  p00_L_0C20();
  p00_L_0C0F();
  p00_L_1128();
  p00_rst30();
  p00_L_10DD();
  p00_L_219B();
  cpu_pop_af();
  if (flag_c()) p00_L_0C2A();
  set_hl(0x745F);
  p00_L_0D19();
  p00_L_0C0F();
  p00_L_10EF();
  p00_rst30();
  return;
}

/* flash page 25 cpu 0x7703 (offset 0x3703) */
void p25_L_7703(void) {
  mem_write8(hl(), h);
  p00_L_0D19();
  p00_L_0C0F();
  p00_L_10EF();
  p00_rst30();
  return;
}

/* flash page 25 cpu 0x771B (offset 0x371B) */
void p25_L_771B(void) {
  a = 0x82;
  mem_write8(0x8484, a);
  p00_L_0ED0();
  p00_L_14E1();
  return;
}

/* flash page 25 cpu 0x7726 (offset 0x3726) */
void p25_L_7726(void) {
  p00_L_3561();
  p00_L_107E();
  return;
}

/* flash page 25 cpu 0x772C (offset 0x372C) */
void p25_L_772C(void) {
  set_hl(0x90C1);
  p00_rst20();
  p00_rst08();
  set_hl(0x90CA);
  p00_rst20();
  p00_L_0ED0();
  p00_rst18();
  set_hl(0x909D);
  p00_rst20();
  set_hl(0x90CA);
  p00_L_0EC1();
  p00_L_15DD();
  p00_L_1251();
  p00_L_0E5C();
  p00_L_107E();
  if (flag_c()) { p00_L_24C9(); return; }
  if (flag_z()) { p00_L_24C9(); return; }
  p00_L_2196();
  p25_L_73F9();
  return;
}

/* flash page 25 cpu 0x775B (offset 0x375B) */
void p25_L_775B(void) {
  p00_L_1229();
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 3)) == 0);
  if (flag_z()) return;
  p00_rst30();
  return;
}

/* flash page 25 cpu 0x7765 (offset 0x3765) */
void p25_L_7765(void) {
  set_hl(0x90A6);
  p00_rst20();
  set_hl(0x90B8);
  p00_L_0C20();
  return;
}

/* flash page 25 cpu 0x77CD (offset 0x37CD) */
void p25_L_77CD(void) {
  a = (uint8_t)(a - b);
  p00_L_11F8();
  p25_L_74D5();
  p00_L_10DD();
  p25_L_7765();
  p00_L_10EF();
  p00_L_0ED0();
  p00_L_10DD();
  p00_L_2315();
  set_hl(0x90A6);
  p00_L_0D19();
  p00_L_10EF();
  p00_rst30();
  p00_L_0E4C();
  p00_L_2196();
  p00_L_0ED0();
  p00_L_21A7();
  return;
}

/* flash page 25 cpu 0x7862 (offset 0x3862) */
void p25_L_7862(void) {
  set_hl(0x90B8);
  p00_rst20();
  set_hl(0x90A6);
  p00_L_11F8();
  p00_L_14C7();
  if (flag_nz()) goto lab_p25_L_787B;
  p00_L_14CC();
  if (flag_z()) goto lab_p25_L_789F;
  p00_L_15C6();
  goto lab_p25_L_788C;
  lab_p25_L_787B: ;
  p00_L_15CB();
  b = a;
  p00_L_14CC();
  a = b;
  if (flag_z()) goto lab_p25_L_788C;
  p00_L_15C6();
  a = (uint8_t)(a + b);
  if (flag_nz()) goto lab_p25_L_78AD;
  a = b;
  lab_p25_L_788C: ;
  set_hl(0x9094);
  p00_rst20();
  set_hl(0x90AF);
  p00_L_11F8();
  b = a;
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_789F;
  p00_L_14CC();
  lab_p25_L_789F: ;
  if (flag_z()) { p00_L_251D(); return; }
  p00_L_15CB();
  c = a;
  p00_L_15C6();
  a = (uint8_t)(a + c);
  a = (uint8_t)(a + b);
  if (flag_z()) goto lab_p25_L_789F;
  lab_p25_L_78AD: ;
  set_hl(0x9094);
  p00_rst20();
  set_hl(0x90AF);
  p00_L_11F8();
  p00_L_14CC();
  if (flag_nz()) goto lab_p25_L_78DC;
  p00_L_0ECC();
  p00_L_10DD();
  set_hl(0x90A6);
  p00_rst20();
  set_hl(0x90B8);
  p00_L_0C20();
  p00_L_0E4C();
  set_hl(0x90A6);
  p00_L_0EC1();
  p00_L_10EF();
  p25_L_73F9();
  return;
  lab_p25_L_78DC: ;
  p00_L_1251();
  p00_L_107E();
  if (flag_nz()) goto lab_p25_L_7912;
  set_hl(0x90A6);
  p00_rst20();
  set_hl(0x90AF);
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_0C20();
  p00_L_1100();
  set_hl(0x90A6);
  p00_rst20();
  set_hl(0x90B8);
  p00_L_0C20();
  p00_L_0E4C();
  set_hl(0x90AF);
  p00_L_11F8();
  p00_L_0C2D();
  p00_L_10F8();
  p00_L_0ED0();
  return;
  lab_p25_L_7912: ;
  set_hl(0x90AF);
  p00_L_0D19();
  p00_rst18();
  set_hl(0x90A6);
  p00_rst20();
  set_hl(0x90B8);
  p00_L_0C20();
  p00_L_22F7();
  p00_rst30();
  p00_rst18();
  set_hl(0x90B8);
  p00_rst20();
  set_hl(0x9094);
  p00_L_0D19();
  p00_rst18();
  set_hl(0x9094);
  p00_rst20();
  p00_L_0C1B();
  p00_L_1171();
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p25_L_7949;
  p00_L_1246();
  p00_L_0C2D();
  lab_p25_L_7949: ;
  p00_L_0D16();
  p00_L_231F();
  p00_L_0E5C();
  p00_L_0D1F();
  p00_L_22F7();
  p00_L_0C2D();
  p00_rst18();
  set_hl(0x9094);
  p00_rst20();
  p00_L_1246();
  p00_rst30();
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p25_L_7970;
  p00_L_1221();
  p00_L_0C2D();
  lab_p25_L_7970: ;
  set_hl(0x8483);
  a = 0x60;
  p00_L_1256();
  p00_L_0ED0();
  p00_L_1108();
  p00_L_0D1F();
  p00_L_22C7();
  p00_L_0D1F();
  p00_L_10DD();
  p00_L_113A();
  p00_L_0D16();
  p00_L_1171();
  p00_L_2310();
  p00_L_0D1F();
  p00_L_10EF();
  p00_rst30();
  p00_L_231F();
  p00_L_2384();
  p00_L_22F7();
  p00_L_2366();
  p00_L_235C();
  p00_L_1229();
  p00_L_233D();
  set_hl(0x9094);
  p00_rst20();
  p25_L_7543();
  p00_rst18();
  a = 0x20;
  cpu_push_af();
  p00_L_1207();
  p25_L_79C0();
  return;
}

/* flash page 25 cpu 0x7921 (offset 0x3921) */
void p25_L_7921(void) {
  if (flag_nz()) goto lab_p25_L_792F;
  p00_L_22F7();
  p00_rst30();
  p00_rst18();
  set_hl(0x90B8);
  p00_rst20();
  set_hl(0x9094);
  lab_p25_L_792F: ;
  p00_L_0D19();
  p00_rst18();
  set_hl(0x9094);
  p00_rst20();
  p00_L_0C1B();
  p00_L_1171();
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p25_L_7949;
  p00_L_1246();
  p00_L_0C2D();
  lab_p25_L_7949: ;
  p00_L_0D16();
  p00_L_231F();
  p00_L_0E5C();
  p00_L_0D1F();
  p00_L_22F7();
  p00_L_0C2D();
  p00_rst18();
  set_hl(0x9094);
  p00_rst20();
  p00_L_1246();
  p00_rst30();
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p25_L_7970;
  p00_L_1221();
  p00_L_0C2D();
  lab_p25_L_7970: ;
  set_hl(0x8483);
  a = 0x60;
  p00_L_1256();
  p00_L_0ED0();
  p00_L_1108();
  p00_L_0D1F();
  p00_L_22C7();
  p00_L_0D1F();
  p00_L_10DD();
  p00_L_113A();
  p00_L_0D16();
  p00_L_1171();
  p00_L_2310();
  p00_L_0D1F();
  p00_L_10EF();
  p00_rst30();
  p00_L_231F();
  p00_L_2384();
  p00_L_22F7();
  p00_L_2366();
  p00_L_235C();
  p00_L_1229();
  p00_L_233D();
  set_hl(0x9094);
  p00_rst20();
  p25_L_7543();
  p00_rst18();
  a = 0x20;
  cpu_push_af();
  p00_L_1207();
  p25_L_79C0();
  return;
}

/* flash page 25 cpu 0x79C0 (offset 0x39C0) */
void p25_L_79C0(void) {
  lab_p25_L_79C0: ;
  p00_L_1251();
  p00_L_0E5C();
  p00_L_22FC();
  p00_L_107E();
  if (flag_c()) goto lab_p25_L_79D0;
  if (flag_nz()) goto lab_p25_L_79DF;
  lab_p25_L_79D0: ;
  p00_L_219B();
  p00_L_0E4C();
  p00_L_1100();
  p00_L_1287();
  p00_L_21E0();
  lab_p25_L_79DF: ;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x20);
  if (flag_nz()) goto lab_p25_L_79F3;
  set_hl(0x9094);
  cpu_push_hl();
  p00_rst20();
  p00_L_0E4C();
  cpu_pop_de();
  p00_L_11FD();
  goto lab_p25_L_7A04;
  lab_p25_L_79F3: ;
  a = mem_read8(0x8490);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_7A00;
  a = mem_read8(0x848F);
  flag_cmp(a, 0x74);
  if (flag_nc()) goto lab_p25_L_7A04;
  lab_p25_L_7A00: ;
  cpu_pop_af();
  p00_L_21A7();
  return;
  lab_p25_L_7A04: ;
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  if (flag_z()) { p00_L_2521(); return; }
  cpu_push_af();
  set_hl(0x9094);
  p00_L_11F8();
  p00_L_22FC();
  p25_L_74E5();
  p00_L_21E0();
  p00_rst18();
  set_hl(0x90B8);
  p00_L_0D19();
  p00_rst18();
  p00_L_22C7();
  p25_L_775B();
  set_hl(0x90AF);
  p00_L_0D19();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_2196();
  p00_L_0C2D();
  set_hl(0x90A6);
  p00_L_0C25();
  p00_L_2191();
  p00_L_22ED();
  p00_rst18();
  p00_L_2324();
  set_hl(0x9094);
  p00_L_11F8();
  p25_L_74FB();
  p00_L_21E0();
  p00_rst18();
  p00_L_22B3();
  p25_L_775B();
  p00_L_2310();
  p00_L_0D1F();
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p25_L_7A6C;
  p00_L_22C7();
  p00_rst30();
  lab_p25_L_7A6C: ;
  set_hl(0x90AF);
  p00_L_0D19();
  p00_L_10DD();
  set_hl(0x90B8);
  p00_L_11F8();
  p00_L_219B();
  p00_L_0D1F();
  p00_L_10EF();
  p00_L_0C13();
  p00_L_1171();
  p00_L_2315();
  p00_L_231F();
  p00_L_0ED0();
  p00_L_2196();
  p00_L_0D1F();
  p00_L_1108();
  p00_L_0C2D();
  p00_rst08();
  p00_L_219B();
  p00_L_0ED0();
  p00_L_1100();
  p00_L_21A7();
  p00_L_2196();
  p00_rst30();
  p00_rst18();
  goto lab_p25_L_79C0;
}

/* flash page 25 cpu 0x7AD2 (offset 0x3AD2) */
void p25_L_7AD2(void) {
  p00_L_219B();
  p00_L_187F();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x84);
  if (flag_nc()) { p00_L_24C9(); return; }
  p00_L_3B5B();
  return;
}

/* flash page 25 cpu 0x7AE4 (offset 0x3AE4) */
void p25_L_7AE4(void) {
  p00_L_0E4C();
  set_de(0x909D);
  p00_L_11FD();
  return;
}

/* flash page 25 cpu 0x7AFD (offset 0x3AFD) */
void p25_L_7AFD(void) {
  a = mem_read8(0x848E);
  mem_write8(0x84A6, a);
  p00_L_2315();
  p00_L_22F7();
  p00_L_107E();
  if (flag_c()) goto lab_p25_L_7B11;
  if (flag_nz()) { p00_L_24C9(); return; }
  lab_p25_L_7B11: ;
  p25_L_7AD2();
  cpu_push_de();
  p25_L_7AD2();
  set_de((uint16_t)(de() - 1));
  mem_write16(0x84A4, de());
  set_hl(0x90A6);
  p00_rst20();
  set_hl(0x0000);
  cpu_push_hl();
  goto lab_p25_L_7B53;
  lab_p25_L_7B27: ;
  set_de(0x0001);
  p00_L_192A();
  if (flag_nz()) goto lab_p25_L_7B38;
  p00_L_128A();
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p25_L_7B44;
  lab_p25_L_7B38: ;
  p00_L_1135();
  set_hl(0x909D);
  p00_L_0D19();
  p25_L_7B72();
  lab_p25_L_7B44: ;
  p00_L_10EF();
  p00_L_0C13();
  p00_rst08();
  set_hl(0x90AF);
  p00_rst20();
  p25_L_7B72();
  p00_rst30();
  lab_p25_L_7B53: ;
  p25_L_7B72();
  p00_L_10DD();
  cpu_pop_hl();
  cpu_push_hl();
  set_de(mem_read16(0x84A4));
  p00_L_192A();
  if (flag_z()) p00_L_1169();
  cpu_pop_hl();
  cpu_pop_de();
  p00_L_192A();
  if (flag_z()) { p00_L_1135(); return; }
  cpu_push_de();
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  goto lab_p25_L_7B27;
}

/* flash page 25 cpu 0x7B72 (offset 0x3B72) */
void p25_L_7B72(void) {
  a = mem_read8(0x84A6);
  d = a;
  p00_L_0FB1();
  return;
}

/* flash page 25 cpu 0x7B7F (offset 0x3B7F) */
void p25_L_7B7F(void) {
  p00_L_2315();
  p00_L_1887();
  p25_L_7AFD();
  p00_L_1128();
  p00_L_0C2D();
  return;
}

/* flash page 25 cpu 0x7BC7 (offset 0x3BC7) */
void p25_L_7BC7(void) {
  p00_L_14C7();
  if (flag_z()) { p00_L_1229(); return; }
  p00_L_222C();
  p25_L_73F9();
  p25_L_74EB();
  return;
}

/* flash page 25 cpu 0x7BD6 (offset 0x3BD6) */
void p25_L_7BD6(void) {
  set_hl(mem_read16(0x90CA));
  p25_L_7BD9();
  return;
}

/* flash page 25 cpu 0x7BD9 (offset 0x3BD9) */
void p25_L_7BD9(void) {
  a = h;
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) { p00_L_128A(); return; }
  a = a | l;
  flag_logic(a);
  if (flag_z()) goto lab_p25_L_7BF1;
  set_de(mem_read16(0x90CC));
  set_de((uint16_t)(de() + 1));
  p00_L_192A();
  if (flag_z()) { p00_L_128A(); return; }
  p00_L_3E6D();
  return;
  lab_p25_L_7BF1: ;
  p00_L_2902();
  return;
}

/* flash page 25 cpu 0x7BF5 (offset 0x3BF5) */
void p25_L_7BF5(void) {
  p00_L_1229();
  a = mem_read8(0x84D6);
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  set_hl(mem_read16(0x90CA));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) return;
  p00_L_3B0D();
  p25_L_74BC();
  return;
}

/* flash page 25 cpu 0x7C09 (offset 0x3C09) */
void p25_L_7C09(void) {
  cpu_push_af();
  p00_rst18();
  p00_L_128A();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  p00_L_1229();
  set_hl(0x0000);
  mem_write16(0x90CA, hl());
  p25_L_7C1A();
  return;
}

/* flash page 25 cpu 0x7C1A (offset 0x3C1A) */
void p25_L_7C1A(void) {
  lab_p25_L_7C1A: ;
  p00_rst18();
  p00_rst08();
  p00_L_22D9();
  p25_L_7BC7();
  p00_L_222C();
  p00_L_1100();
  p00_L_2277();
  p00_L_14C7();
  cpu_push_af();
  if (flag_z()) p00_L_21E0();
  cpu_pop_af();
  if (flag_nz()) p00_L_21DB();
  set_hl(mem_read16(0x90CA));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p25_L_7C45;
  p00_L_14C7();
  if (flag_nz()) p00_L_233D();
  goto lab_p25_L_7C5D;
  lab_p25_L_7C45: ;
  set_de(0x0001);
  p00_L_192A();
  if (flag_nz()) goto lab_p25_L_7C5D;
  p00_L_1287();
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_7C65;
  p00_L_1229();
  p00_L_233D();
  goto lab_p25_L_7C65;
  lab_p25_L_7C5D: ;
  set_hl(mem_read16(0x90CA));
  set_hl((uint16_t)(hl() - 1));
  p25_L_7BD9();
  p00_rst08();
  lab_p25_L_7C65: ;
  p25_L_7BD6();
  p00_L_0C2D();
  p00_L_1171();
  p00_L_2310();
  p00_L_0D1F();
  p00_L_10DD();
  p00_L_219B();
  p00_L_1108();
  p00_L_0D1F();
  p00_L_2262();
  p00_rst30();
  p00_L_23A4();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p25_L_7CB6;
  p00_L_1135();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_1100();
  p00_L_22B3();
  p00_rst30();
  p00_L_23B3();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p25_L_7CB6;
  p00_L_113F();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_22C7();
  p00_rst30();
  p00_L_2389();
  lab_p25_L_7CB6: ;
  set_de(mem_read16(0x90CA));
  set_hl(mem_read16(0x90CC));
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) return;
  cpu_push_bc();
  p25_L_7BF5();
  p00_rst08();
  set_hl(mem_read16(0x90CA));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x90CA, hl());
  p00_L_21A4();
  p00_L_219B();
  p00_L_0C2D();
  goto lab_p25_L_7C1A;
}

/* flash page 25 cpu 0x7CF8 (offset 0x3CF8) */
void p25_L_7CF8(void) {
  p00_L_2902();
  set_hl(mem_read16(0x90CC));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x84AF, hl());
  a = 0;
  flag_logic(a);
  cpu_push_af();
  goto lab_p25_L_7D0C;
  lab_p25_L_7D06: ;
  mem_write16(0x84AF, hl());
  p00_L_3AEF();
  lab_p25_L_7D0C: ;
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_7D22;
  cpu_pop_af();
  if (flag_nz()) goto lab_p25_L_7D19;
  a = mem_read8(0x8478);
  a = a | 0x01;
  flag_logic(a);
  lab_p25_L_7D19: ;
  cpu_push_af();
  set_hl(0x8478);
  /* xor (hl) */
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p25_L_7D2D;
  lab_p25_L_7D22: ;
  set_hl(mem_read16(0x84AF));
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) { p00_L_251D(); return; }
  goto lab_p25_L_7D06;
  lab_p25_L_7D2D: ;
  cpu_pop_af();
  return;
}

/* flash page 25 cpu 0x7D38 (offset 0x3D38) */
void p25_L_7D38(void) {
  lab_p25_L_7D38: ;
  p00_rst18();
  a = 0x20;
  cpu_push_af();
  p00_L_128A();
  a = 0x03;
  p25_L_7C09();
  p00_L_21A4();
  p00_L_22C7();
  p00_L_2324();
  p00_L_0C2D();
  p00_L_0D16();
  p00_L_10DD();
  p00_L_22C7();
  p00_L_2315();
  p00_L_0C2D();
  set_hl(0x8483);
  a = 0x60;
  p00_L_1256();
  p00_L_0ED0();
  p00_L_10EF();
  p00_L_0C2D();
  p00_L_235C();
  p00_L_22CF();
  p00_L_23B3();
  p00_L_1135();
  p00_L_2375();
  p00_L_22FC();
  p00_L_0E4C();
  p00_L_2262();
  p00_L_2333();
  p25_L_7543();
  p00_rst18();
  p00_L_1251();
  p00_L_0E5C();
  p00_L_107E();
  if (flag_c()) goto lab_p25_L_7E72;
  if (flag_z()) goto lab_p25_L_7E72;
  lab_p25_L_7D9E: ;
  p00_L_219B();
  a = 0x02;
  p25_L_7C09();
  p00_L_2272();
  p00_L_219B();
  p00_L_14CC();
  if (flag_z()) goto lab_p25_L_7DB7;
  p00_L_2262();
  p00_L_0ED0();
  lab_p25_L_7DB7: ;
  p00_L_2191();
  p00_L_1169();
  p00_L_10DD();
  p00_L_22D9();
  p00_L_22F7();
  p25_L_74FB();
  p00_L_2277();
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_7DEA;
  p00_L_10E6();
  p00_L_22CF();
  p00_L_1128();
  p00_L_0ED0();
  p00_L_10EF();
  p00_L_0D1F();
  p00_rst08();
  p00_L_2277();
  p00_L_0D1F();
  lab_p25_L_7DEA: ;
  p00_L_10DD();
  p00_L_1229();
  p00_L_22B3();
  p00_L_14CC();
  if (flag_z()) p00_L_1251();
  p00_rst30();
  p00_L_1100();
  p00_L_2324();
  p00_L_2262();
  p00_rst30();
  p00_L_10F8();
  p00_L_0ED0();
  p00_L_10EF();
  p00_L_0C13();
  p00_L_10DD();
  p00_L_22CF();
  p00_L_22B3();
  p00_L_14CC();
  if (flag_z()) goto lab_p25_L_7E24;
  p00_L_22B3();
  p00_L_0ED0();
  lab_p25_L_7E24: ;
  p00_L_10EF();
  p00_rst30();
  p00_L_22C7();
  p00_L_11D8();
  p00_L_2182();
  set_de(0x001B);
  p00_L_21B6();
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_7E4F;
  p00_rst08();
  p00_L_113F();
  p00_L_0ED0();
  p00_L_2389();
  p00_L_22F7();
  p00_rst30();
  p00_L_233D();
  goto lab_p25_L_7E58;
  lab_p25_L_7E4F: ;
  p00_L_1229();
  p00_L_0E4C();
  p00_L_233D();
  lab_p25_L_7E58: ;
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p25_L_7EB3;
  p00_L_22FC();
  p00_L_1251();
  p00_L_0E5C();
  p00_L_107E();
  if (flag_c()) goto lab_p25_L_7E72;
  if (flag_nz()) goto lab_p25_L_7E99;
  lab_p25_L_7E72: ;
  cpu_pop_bc();
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p25_L_7E85;
  a = (uint8_t)(a + 1);
  cpu_push_af();
  p00_L_128A();
  set_de(0x001B);
  p00_L_21B6();
  goto lab_p25_L_7D38;
  lab_p25_L_7E85: ;
  a = (uint8_t)(a + 1);
  cpu_push_af();
  cpu_push_bc();
  p00_L_22FC();
  p00_L_0E4C();
  p00_L_2389();
  p00_L_128A();
  p00_L_233D();
  goto lab_p25_L_7EC4;
  lab_p25_L_7E99: ;
  p00_L_22FC();
  p00_L_0C1B();
  p00_L_3921();
  p00_L_1128();
  p00_L_0D1F();
  set_hl(0x7EDB);
  p00_L_11F8();
  p00_L_107E();
  if (flag_nc()) goto lab_p25_L_7E72;
  lab_p25_L_7EB3: ;
  p00_L_22CF();
  p00_L_14C7();
  if (flag_z()) goto lab_p25_L_7ECD;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x74);
  if (flag_c()) goto lab_p25_L_7ECD;
  lab_p25_L_7EC4: ;
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  cpu_push_af();
  if (flag_nz()) goto lab_p25_L_7D9E;
  p00_L_2521();
  return;
  lab_p25_L_7ECD: ;
  cpu_pop_af();
  cpu_pop_af();
  p00_L_219B();
  set_de(0x0024);
  p00_L_21B6();
  p25_L_75DE();
  return;
}


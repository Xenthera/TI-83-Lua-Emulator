/* Recovered from flash page 3 (mechanical ASM->C) */
/* cpu window 0x4000..0x7FFF prefix=p03_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p03_L_4000(void);
void p03_L_407D(void);
void p03_L_409E(void);
void p03_L_40D5(void);
void p03_L_40E3(void);
void p03_L_40E7(void);
void p03_L_40FF(void);
void p03_L_4100(void);
void p03_L_4112(void);
void p03_L_412F(void);
void p03_L_4146(void);
void p03_L_4172(void);
void p03_L_41A1(void);
void p03_L_41AB(void);
void p03_L_4200(void);
void p03_lcd_write_data_2(void);
void p03_L_426F(void);
void p03_L_4274(void);
void p03_lcd_write_data(void);
void p03_L_4295(void);
void p03_L_429B(void);
void p03_L_4315(void);
void p03_L_4368(void);
void p03_L_43BE(void);
void p03_L_43C1(void);
void p03_L_43DD(void);
void p03_L_4421(void);
void p03_L_4492(void);
void p03_L_44C6(void);
void p03_L_44D9(void);
void p03_L_44F5(void);
void p03_L_4518(void);
void p03_L_4574(void);
void p03_L_4581(void);
void p03_L_4587(void);
void p03_L_45BA(void);
void p03_L_45C1(void);
void p03_L_45CC(void);
void p03_L_45CD(void);
void p03_L_45E3(void);
void p03_L_4613(void);
void p03_L_4616(void);
void p03_L_461E(void);
void p03_L_4629(void);
void p03_L_464A(void);
void p03_L_464D(void);
void p03_L_465E(void);
void p03_L_4671(void);
void p03_L_4727(void);
void p03_L_473A(void);
void p03_L_4742(void);
void p03_L_479B(void);
void p03_L_47E1(void);
void p03_L_47FE(void);
void p03_L_481D(void);
void p03_L_4866(void);
void p03_L_48F5(void);
void p03_L_4933(void);
void p03_L_4979(void);
void p03_L_4987(void);
void p03_L_49A6(void);
void p03_L_49C9(void);
void p03_L_49D5(void);
void p03_L_49D9(void);
void p03_L_49DE(void);
void p03_L_49E1(void);
void p03_L_49FA(void);
void p03_L_49FB(void);
void p03_L_4A0F(void);
void p03_L_4A21(void);
void p03_L_4A39(void);
void p03_L_4A40(void);
void p03_L_4A44(void);
void p03_L_4A4C(void);
void p03_L_4A51(void);
void p03_L_4A8B(void);
void p03_L_4A97(void);
void p03_L_4AE9(void);
void p03_L_4AF2(void);
void p03_L_4AFA(void);
void p03_L_4B19(void);
void p03_L_4B1C(void);
void p03_L_4B22(void);
void p03_L_4B4D(void);
void p03_L_4B65(void);
void p03_L_4B73(void);
void p03_L_4B7C(void);
void p03_L_4B7F(void);
void p03_L_4BCD(void);
void p03_L_4C83(void);
void p03_L_4C86(void);
void p03_L_4C95(void);
void p03_L_4CC6(void);
void p03_L_4D49(void);
void p03_L_4D67(void);
void p03_L_4D6B(void);
void p03_L_4D99(void);
void p03_L_4DBB(void);
void p03_L_4E35(void);
void p03_L_4E4F(void);
void p03_L_4E6C(void);
void p03_L_4F11(void);
void p03_L_4F31(void);
void p03_L_503A(void);
void p03_L_5320(void);
void p03_L_53ED(void);
void p03_L_5674(void);
void p03_L_5681(void);
void p03_L_56D4(void);
void p03_L_570B(void);
void p03_L_5751(void);
void p03_L_5779(void);
void p03_L_5780(void);
void p03_L_57AB(void);
void p03_L_57E3(void);
void p03_L_57EA(void);
void p03_L_57F1(void);
void p03_L_57F8(void);
void p03_L_5801(void);
void p03_L_5808(void);
void p03_ascii_map(void);
void p03_ascii_map_2(void);
void p03_str_4(void);
void p03_str_1(void);
void p03_str_3(void);
void p03_str_2(void);
void p03_L_597D(void);
void p03_L_5991(void);
void p03_L_5996(void);
void p03_L_59B1(void);
void p03_L_59FA(void);
void p03_L_5A13(void);
void p03_L_5A23(void);
void p03_L_5A27(void);
void p03_L_5A3B(void);
void p03_L_5A47(void);
void p03_L_5A7A(void);
void p03_L_5A9C(void);
void p03_L_5C20(void);
void p03_L_5C30(void);
void p03_L_5C38(void);
void p03_L_5C4D(void);
void p03_L_5C71(void);
void p03_L_5D0A(void);
void p03_L_5D38(void);
void p03_L_5D41(void);
void p03_L_5D53(void);
void p03_L_5E3D(void);
void p03_L_5EFC(void);
void p03_L_5F89(void);
void p03_L_5FA4(void);
void p03_L_5FC3(void);
void p03_L_5FE2(void);
void p03_L_5FEB(void);
void p03_L_60BA(void);
void p03_L_60E6(void);
void p03_L_612E(void);
void p03_L_6138(void);
void p03_L_614B(void);
void p03_L_6165(void);
void p03_L_61BD(void);
void p03_L_61CC(void);
void p03_L_627F(void);
void p03_L_6298(void);
void p03_L_62BC(void);
void p03_L_62D4(void);
void p03_L_62E2(void);
void p03_L_6320(void);
void p03_L_638D(void);
void p03_L_63A5(void);
void p03_L_63AF(void);
void p03_L_63E0(void);
void p03_L_6400(void);
void p03_L_640C(void);
void p03_L_654A(void);
void p03_L_6554(void);
void p03_L_6563(void);
void p03_L_6566(void);
void p03_L_656D(void);
void p03_L_6571(void);
void p03_L_6572(void);
void p03_L_657B(void);
void p03_L_6583(void);
void p03_L_6586(void);
void p03_L_65F5(void);
void p03_L_6646(void);
void p03_L_6653(void);
void p03_L_665C(void);
void p03_L_6675(void);
void p03_L_6692(void);
void p03_L_66A0(void);
void p03_L_66EF(void);
void p03_L_6716(void);
void p03_L_672A(void);
void p03_L_6738(void);
void p03_L_67AF(void);
void p03_L_67B2(void);
void p03_L_67CD(void);
void p03_L_67FF(void);
void p03_L_6854(void);
void p03_L_687F(void);
void p03_L_68CD(void);
void p03_L_68D6(void);
void p03_L_690A(void);
void p03_L_691B(void);
void p03_L_6933(void);
void p03_L_695A(void);
void p03_L_6969(void);
void p03_L_6980(void);
void p03_L_6989(void);
void p03_L_6991(void);
void p03_L_69A0(void);
void p03_L_69BE(void);
void p03_L_69C6(void);
void p03_L_69D4(void);
void p03_L_69DA(void);
void p03_L_69DE(void);
void p03_L_69E7(void);
void p03_L_69F7(void);
void p03_L_6A09(void);
void p03_L_6AB8(void);
void p03_L_6AD6(void);
void p03_L_6AF7(void);
void p03_L_6B07(void);
void p03_L_6C61(void);
void p03_L_6C63(void);
void p03_L_6C65(void);
void p03_L_6C69(void);
void p03_L_6D9E(void);
void p03_L_6D9F(void);
void p03_L_6DC1(void);
void p03_L_6DE3(void);
void p03_L_6E19(void);
void p03_L_6E2F(void);
void p03_L_6E61(void);
void p03_L_6F6D(void);
void p03_L_6F74(void);
void p03_L_6F88(void);
void p03_L_6F8B(void);
void p03_L_6FCD(void);
void p03_L_700C(void);
void p03_L_7033(void);
void p03_L_7053(void);
void p03_L_7070(void);
void p03_L_707D(void);
void p03_L_7084(void);
void p03_L_708B(void);
void p03_L_70B1(void);
void p03_L_70CC(void);
void p03_L_70F4(void);
void p03_L_71A6(void);
void p03_L_71FC(void);
void p03_L_7212(void);
void p03_L_722B(void);
void p03_L_7264(void);
void p03_L_7265(void);
void p03_L_7278(void);
void p03_L_7316(void);
void p03_L_7369(void);
void p03_L_7373(void);
void p03_L_73B7(void);
void p03_L_7407(void);
void p03_L_746E(void);
void p03_L_7473(void);
void p03_L_7474(void);
void p03_L_747A(void);
void p03_L_748F(void);
void p03_L_74AD(void);
void p03_L_74B9(void);
void p03_L_74C5(void);
void p03_L_7530(void);
void p03_L_7538(void);
void p03_L_75BB(void);
void p03_L_7720(void);
void p03_L_77CA(void);
void p03_L_7811(void);
void p03_L_7927(void);
void p03_L_793E(void);
void p03_L_7972(void);
void p03_str_5(void);
void p03_L_7AFE(void);
void p03_L_7BCD(void);
void p03_L_7C6C(void);
void p03_L_7C90(void);
void p03_L_7CBB(void);
void p03_L_7CCB(void);
void p03_L_7CCD(void);
void p03_L_7D23(void);
void p03_L_7D48(void);
void p03_L_7D60(void);
void p03_L_7D84(void);
void p03_L_7DBC(void);
void p03_L_7DC3(void);
void p03_L_7DEA(void);
void p03_L_7EEF(void);
void p03_L_7FCB(void);

/* flash page 3 cpu 0x4000 (offset 0x0000) */
void p03_L_4000(void) {
  p00_L_3CFF();
  os_bcall(0x808A);
  set_hl(0x0001);
  mem_write16(0x844B, hl());
  set_hl(0x284A);
  p00_L_3C87();
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p03_L_401F;
  a = 0x79;
  p00_L_3C45();
  if (flag_z()) goto lab_p03_L_4031;
  lab_p03_L_401F: ;
  set_hl(0x40FF);
  p03_L_40E7();
  set_hl(0x4112);
  p03_L_40E7();
  set_hl(0x412F);
  p03_L_40E7();
  lab_p03_L_4031: ;
  p00_L_3F09();
  p00_L_3F21();
  flag_cmp(a, 0x05);
  if (flag_nz()) { p00_L_05F1(); return; }
  p00_L_3E8B();
  set_hl(0x0403);
  mem_write16(0x844B, hl());
  set_hl(0x285A);
  p00_L_3C87();
  p00_L_3F21();
  flag_cmp(a, 0x05);
  if (flag_nz()) { p00_L_05F1(); return; }
  p00_L_3E8B();
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 2)));
  set_hl(0x0000);
  mem_write16(0x8D17, hl());
  os_bcall(0x807E);
  set_hl(0x26AB);
  if (flag_z()) goto lab_p03_L_4077;
  p03_L_429B();
  p00_L_3E8B();
  lab_p03_L_4077: ;
  p03_L_4146();
  sp = 0x8D4F;
  p03_L_407D();
  return;
}

/* flash page 3 cpu 0x407D (offset 0x007D) */
void p03_L_407D(void) {
  set_hl(0x0403);
  mem_write16(0x844B, hl());
  set_hl(mem_read16(0x8D17));
  cpu_push_hl();
  p00_L_3C7B();
  /* ei */
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x8D17, hl());
  a = 0;
  flag_logic(a);
  p03_L_409E();
  set_hl(0x26A7);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p03_L_4295(); return; }
  p03_L_4172();
  return;
}

/* flash page 3 cpu 0x409E (offset 0x009E) */
void p03_L_409E(void) {
  b = 0x00;
  goto lab_p03_L_40AC;
  lab_p03_L_40A2: ;
  b = 0x18;
  p00_L_24A9();
  if (flag_nz()) goto lab_p03_L_40AB;
  b = 0x78;
  lab_p03_L_40AB: ;
  cpu_pop_af();
  lab_p03_L_40AC: ;
  set_hl(0x4000);
  lab_p03_L_40AF: ;
  p00_L_01E3();
  a = (uint8_t)(a + c);
  set_hl((uint16_t)(hl() + 1));
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_z()) goto lab_p03_L_40AF;
  p00_L_0189();
  if (flag_nz()) { p03_L_41AB(); return; }
  cpu_push_af();
  b = (uint8_t)(b + 1);
  a = b;
  flag_cmp(a, 0x08);
  if (flag_z()) goto lab_p03_L_40A2;
  p00_L_24A9();
  if (flag_nz()) goto lab_p03_L_40CE;
  flag_cmp(a, 0x7A);
  goto lab_p03_L_40D0;
  lab_p03_L_40CE: ;
  flag_cmp(a, 0x1A);
  lab_p03_L_40D0: ;
  if (flag_nz()) goto lab_p03_L_40D8;
  cpu_pop_af();
  set_hl(0x4200);
  goto lab_p03_L_40AF;
  lab_p03_L_40D8: ;
  p00_L_24A9();
  if (flag_nz()) goto lab_p03_L_40E1;
  flag_cmp(a, 0x7E);
  p03_L_40E3();
  return;
  lab_p03_L_40E1: ;
  flag_cmp(a, 0x1E);
  p03_L_40E3();
  return;
}

/* flash page 3 cpu 0x40D5 (offset 0x00D5) */
void p03_L_40D5(void) {
  goto lab_p03_L_40D5;
  lab_p03_L_40A2: ;
  b = 0x18;
  p00_L_24A9();
  if (flag_nz()) goto lab_p03_L_40AB;
  b = 0x78;
  lab_p03_L_40AB: ;
  cpu_pop_af();
  set_hl(0x4000);
  lab_p03_L_40AF: ;
  p00_L_01E3();
  a = (uint8_t)(a + c);
  set_hl((uint16_t)(hl() + 1));
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_z()) goto lab_p03_L_40AF;
  p00_L_0189();
  if (flag_nz()) { p03_L_41AB(); return; }
  cpu_push_af();
  b = (uint8_t)(b + 1);
  a = b;
  flag_cmp(a, 0x08);
  if (flag_z()) goto lab_p03_L_40A2;
  p00_L_24A9();
  if (flag_nz()) goto lab_p03_L_40CE;
  flag_cmp(a, 0x7A);
  goto lab_p03_L_40D0;
  lab_p03_L_40CE: ;
  flag_cmp(a, 0x1A);
  lab_p03_L_40D0: ;
  if (flag_nz()) goto lab_p03_L_40D8;
  cpu_pop_af();
  set_hl(0x4200);
  lab_p03_L_40D5: ;
  b = d;
  goto lab_p03_L_40AF;
  lab_p03_L_40D8: ;
  p00_L_24A9();
  if (flag_nz()) goto lab_p03_L_40E1;
  flag_cmp(a, 0x7E);
  p03_L_40E3();
  return;
  lab_p03_L_40E1: ;
  flag_cmp(a, 0x1E);
  p03_L_40E3();
  return;
}

/* flash page 3 cpu 0x40E3 (offset 0x00E3) */
void p03_L_40E3(void) {
  goto lab_p03_L_40E3;
  lab_p03_L_40A2: ;
  b = 0x18;
  p00_L_24A9();
  if (flag_nz()) goto lab_p03_L_40AB;
  b = 0x78;
  lab_p03_L_40AB: ;
  cpu_pop_af();
  set_hl(0x4000);
  lab_p03_L_40AF: ;
  p00_L_01E3();
  a = (uint8_t)(a + c);
  set_hl((uint16_t)(hl() + 1));
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_z()) goto lab_p03_L_40AF;
  p00_L_0189();
  if (flag_nz()) { p03_L_41AB(); return; }
  cpu_push_af();
  b = (uint8_t)(b + 1);
  a = b;
  flag_cmp(a, 0x08);
  if (flag_z()) goto lab_p03_L_40A2;
  p00_L_24A9();
  if (flag_nz()) goto lab_p03_L_40CE;
  flag_cmp(a, 0x7A);
  goto lab_p03_L_40D0;
  lab_p03_L_40CE: ;
  flag_cmp(a, 0x1A);
  lab_p03_L_40D0: ;
  if (flag_nz()) goto lab_p03_L_40D8;
  cpu_pop_af();
  set_hl(0x4200);
  goto lab_p03_L_40AF;
  lab_p03_L_40D8: ;
  p00_L_24A9();
  if (flag_nz()) goto lab_p03_L_40E1;
  flag_cmp(a, 0x7E);
  goto lab_p03_L_40E3;
  lab_p03_L_40E1: ;
  flag_cmp(a, 0x1E);
  lab_p03_L_40E3: ;
  if (flag_nz()) goto lab_p03_L_40AB;
  cpu_pop_af();
  return;
}

/* flash page 3 cpu 0x40E7 (offset 0x00E7) */
void p03_L_40E7(void) {
  cpu_push_hl();
  p00_L_0033();
  mem_write16(0x86D7, hl());
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_bc(0x0020);
  set_de(0x8478);
  cpu_push_de();
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_hl();
  p00_L_3D4D();
  return;
}

/* flash page 3 cpu 0x40FF (offset 0x00FF) */
void p03_L_40FF(void) {
  mem_write8(de(), a);
  p03_L_4100();
  return;
}

/* flash page 3 cpu 0x4100 (offset 0x0100) */
void p03_L_4100(void) {
  goto lab_p03_L_4147;
  lab_p03_L_4147: ;
  a = a ^ c;
  flag_logic(a);
  h = (uint8_t)(h + 1);
  if (flag_nz()) return;
  /* di */
  a = 0x45;
  hw_out(0x36, a);
  a = 0;
  flag_logic(a);
  hw_out(0x37, a);
  a = 0x80;
  hw_out(0x38, a);
  set_hl(0x0000);
  lab_p03_L_4159: ;
  set_hl((uint16_t)(hl() + 1));
  a = hw_in(PORT_INTACK);
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_z()) goto lab_p03_L_4159;
  /* ei */
  set_de(0x0503);
  mem_write16(0x844B, de());
  p00_L_3C7B();
  p00_L_3F21();
  p00_L_3CFF();
  return;
}

/* flash page 3 cpu 0x4112 (offset 0x0112) */
void p03_L_4112(void) {
  b = (uint8_t)(b + 1);
  h = (uint8_t)(h + 1);
  d = h;
  l = b;
  l = c;
  mem_write8(hl(), e);
  if (flag_nz()) goto lab_p03_L_4191;
  l = c;
  l = h;
  l = h;
  if (flag_nz()) goto lab_p03_L_4182;
  l = h;
  h = l;
  h = c;
  mem_write8(hl(), d);
  if (flag_nz()) goto lab_p03_L_4186;
  l = h;
  l = h;
  if (flag_nz()) goto lab_p03_L_4196;
  h = l;
  l = l;
  l = a;
  mem_write8(hl(), d);
  a = c;
  /* nop */
  p03_L_412F();
  return;
  lab_p03_L_4182: ;
  a = 0x02;
  lab_p03_L_4184: ;
  cpu_push_af();
  hw_out(PORT_ASYN, a);
  lab_p03_L_4186: ;
  b = (uint8_t)(b - 1);
  set_de(0xC000);
  p03_L_4368();
  if (flag_nz()) goto lab_p03_L_419B;
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  lab_p03_L_4191: ;
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p03_L_4184;
  a = 0;
  flag_logic(a);
  lab_p03_L_4196: ;
  hw_out(PORT_ASYN, a);
  p03_L_407D();
  return;
  lab_p03_L_419B: ;
  cpu_pop_bc();
  a = 0;
  flag_logic(a);
  hw_out(PORT_ASYN, a);
  p03_L_41AB();
  return;
}

/* flash page 3 cpu 0x412F (offset 0x012F) */
void p03_L_412F(void) {
  goto lab_p03_L_412F;
  lab_p03_L_40F9: ;
  a = a | b;
  flag_logic(a);
  cpu_pop_hl();
  p00_L_3D4D();
  return;
  lab_p03_L_412F: ;
  c = (uint8_t)(c + 1);
  a = mem_read8(0x7250);
  h = l;
  mem_write8(hl(), e);
  mem_write8(hl(), e);
  if (flag_nz()) goto lab_p03_L_40F9;
  c = a;
  c = mem_read8(hl());
  e = l;
  if (flag_nz()) goto lab_p03_L_41B1;
  l = a;
  if (flag_nz()) goto lab_p03_L_41A3;
  h = c;
  l = mem_read8(hl());
  h = e;
  h = l;
  l = h;
  /* nop */
  p03_L_4146();
  return;
  lab_p03_L_41A3: ;
  a = a | 0xC0;
  flag_logic(a);
  /* di */
  p00_L_0AB9();
  /* ei */
  return;
  lab_p03_L_41B1: ;
  set_hl((uint16_t)(hl() + bc()));
  /* and (hl) */
  set_de(0x8181);
  p03_lcd_write_data_2();
  d = 0xFF;
  b = 0x80;
  p03_lcd_write_data();
  b = 0xBF;
  p03_lcd_write_data();
  p03_L_4274();
  a = 0xFF;
  p03_L_426F();
  a = 0;
  flag_logic(a);
  p03_L_426F();
  d = 0x55;
  e = 0xAA;
  p03_lcd_write_data_2();
  p00_L_3F21();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_41FE;
  set_de(0x00FF);
  p03_lcd_write_data_2();
  p00_L_3F21();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_41FE;
  a = 0xAA;
  p03_L_426F();
  c = 0x27;
  lab_p03_L_41F1: ;
  a = c;
  p03_L_41A1();
  p00_L_3F21();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_41FE;
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p03_L_41F1;
  lab_p03_L_41FE: ;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  p00_L_3E8B();
  a = mem_read8(0x8447);
  p03_L_41A1();
  ix = 0x42B3;
  b = 0x31;
  p00_L_0B8D();
  lab_p03_L_4214: ;
  set_hl(0x0503);
  mem_write16(0x844B, hl());
  /* ld ixl,(ix+0x01) */
  h = 0x00;
  p00_L_3C7B();
  /* ei */
  lab_p03_L_4223: ;
  p00_L_038C();
  p00_L_0189();
  if (flag_nz()) goto lab_p03_L_4248;
  /* cp (ix) */
  if (flag_nz()) goto lab_p03_L_4223;
  ix = (uint16_t)(ix + 1);
  ix = (uint16_t)(ix + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_4214;
  p00_L_3E8B();
  set_hl(0x0703);
  mem_write16(0x844B, hl());
  set_hl(0x267B);
  p00_L_3C87();
  p00_L_3F21();
  lab_p03_L_4248: ;
  p00_L_09CA();
  return;
}

/* flash page 3 cpu 0x4146 (offset 0x0146) */
void p03_L_4146(void) {
  p00_L_24A9();
  if (flag_nz()) return;
  /* di */
  a = 0x45;
  hw_out(0x36, a);
  a = 0;
  flag_logic(a);
  hw_out(0x37, a);
  a = 0x80;
  hw_out(0x38, a);
  set_hl(0x0000);
  lab_p03_L_4159: ;
  set_hl((uint16_t)(hl() + 1));
  a = hw_in(PORT_INTACK);
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_z()) goto lab_p03_L_4159;
  /* ei */
  set_de(0x0503);
  mem_write16(0x844B, de());
  p00_L_3C7B();
  p00_L_3F21();
  p00_L_3CFF();
  return;
}

/* flash page 3 cpu 0x4172 (offset 0x0172) */
void p03_L_4172(void) {
  set_de(0x8D4F);
  p03_L_4368();
  if (flag_nz()) { p03_L_41AB(); return; }
  p00_L_24A9();
  if (flag_nz()) goto lab_p03_L_4198;
  a = 0;
  flag_logic(a);
  hw_out(0x27, a);
  a = 0x02;
  lab_p03_L_4184: ;
  cpu_push_af();
  hw_out(PORT_ASYN, a);
  set_de(0xC000);
  p03_L_4368();
  if (flag_nz()) goto lab_p03_L_419B;
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p03_L_4184;
  a = 0;
  flag_logic(a);
  hw_out(PORT_ASYN, a);
  lab_p03_L_4198: ;
  p03_L_407D();
  return;
  lab_p03_L_419B: ;
  cpu_pop_bc();
  a = 0;
  flag_logic(a);
  hw_out(PORT_ASYN, a);
  p03_L_41AB();
  return;
}

/* flash page 3 cpu 0x41A1 (offset 0x01A1) */
void p03_L_41A1(void) {
  a = (uint8_t)(a + 0x18);
  a = a | 0xC0;
  flag_logic(a);
  /* di */
  p00_L_0AB9();
  /* ei */
  return;
}

/* flash page 3 cpu 0x41AB (offset 0x01AB) */
void p03_L_41AB(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x9CAF, a);
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  set_de(0x8181);
  p03_lcd_write_data_2();
  d = 0xFF;
  b = 0x80;
  p03_lcd_write_data();
  b = 0xBF;
  p03_lcd_write_data();
  p03_L_4274();
  a = 0xFF;
  p03_L_426F();
  a = 0;
  flag_logic(a);
  p03_L_426F();
  d = 0x55;
  e = 0xAA;
  p03_lcd_write_data_2();
  p00_L_3F21();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_41FE;
  set_de(0x00FF);
  p03_lcd_write_data_2();
  p00_L_3F21();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_41FE;
  a = 0xAA;
  p03_L_426F();
  c = 0x27;
  lab_p03_L_41F1: ;
  a = c;
  p03_L_41A1();
  p00_L_3F21();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_41FE;
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p03_L_41F1;
  lab_p03_L_41FE: ;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  p00_L_3E8B();
  a = mem_read8(0x8447);
  p03_L_41A1();
  ix = 0x42B3;
  b = 0x31;
  p00_L_0B8D();
  lab_p03_L_4214: ;
  set_hl(0x0503);
  mem_write16(0x844B, hl());
  /* ld ixl,(ix+0x01) */
  h = 0x00;
  p00_L_3C7B();
  /* ei */
  lab_p03_L_4223: ;
  p00_L_038C();
  p00_L_0189();
  if (flag_nz()) goto lab_p03_L_4248;
  /* cp (ix) */
  if (flag_nz()) goto lab_p03_L_4223;
  ix = (uint16_t)(ix + 1);
  ix = (uint16_t)(ix + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_4214;
  p00_L_3E8B();
  set_hl(0x0703);
  mem_write16(0x844B, hl());
  set_hl(0x267B);
  p00_L_3C87();
  p00_L_3F21();
  lab_p03_L_4248: ;
  p00_L_09CA();
  return;
}

/* flash page 3 cpu 0x4200 (offset 0x0200) */
void p03_L_4200(void) {
  set_hl((uint16_t)(hl() + bc()));
  /* and (hl) */
  p00_L_3E8B();
  a = mem_read8(0x8447);
  p03_L_41A1();
  ix = 0x42B3;
  b = 0x31;
  p00_L_0B8D();
  lab_p03_L_4214: ;
  set_hl(0x0503);
  mem_write16(0x844B, hl());
  /* ld ixl,(ix+0x01) */
  h = 0x00;
  p00_L_3C7B();
  /* ei */
  lab_p03_L_4223: ;
  p00_L_038C();
  p00_L_0189();
  if (flag_nz()) goto lab_p03_L_4248;
  /* cp (ix) */
  if (flag_nz()) goto lab_p03_L_4223;
  ix = (uint16_t)(ix + 1);
  ix = (uint16_t)(ix + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_4214;
  p00_L_3E8B();
  set_hl(0x0703);
  mem_write16(0x844B, hl());
  set_hl(0x267B);
  p00_L_3C87();
  p00_L_3F21();
  lab_p03_L_4248: ;
  p00_L_09CA();
  return;
}

/* flash page 3 cpu 0x424B (offset 0x024B) */
void p03_lcd_write_data_2(void) {
  /* CURATED -> lcd_write_data */
  lcd_write_data();
}

/* flash page 3 cpu 0x426F (offset 0x026F) */
void p03_L_426F(void) {
  d = a;
  e = a;
  p03_lcd_write_data_2();
  p03_L_4274();
  return;
}

/* flash page 3 cpu 0x4274 (offset 0x0274) */
void p03_L_4274(void) {
  goto lab_p03_L_4274;
  lab_p03_L_41FE: ;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  p00_L_3E8B();
  a = mem_read8(0x8447);
  p03_L_41A1();
  ix = 0x42B3;
  b = 0x31;
  p00_L_0B8D();
  lab_p03_L_4214: ;
  set_hl(0x0503);
  mem_write16(0x844B, hl());
  /* ld ixl,(ix+0x01) */
  h = 0x00;
  p00_L_3C7B();
  /* ei */
  lab_p03_L_4223: ;
  p00_L_038C();
  p00_L_0189();
  if (flag_nz()) goto lab_p03_L_4248;
  /* cp (ix) */
  if (flag_nz()) goto lab_p03_L_4223;
  ix = (uint16_t)(ix + 1);
  ix = (uint16_t)(ix + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_4214;
  p00_L_3E8B();
  set_hl(0x0703);
  mem_write16(0x844B, hl());
  set_hl(0x267B);
  p00_L_3C87();
  p00_L_3F21();
  lab_p03_L_4248: ;
  p00_L_09CA();
  return;
  lab_p03_L_4274: ;
  p00_L_3F21();
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_41FE;
  os_jp_hl();
  return;
}

/* flash page 3 cpu 0x427C (offset 0x027C) */
void p03_lcd_write_data(void) {
  /* CURATED -> lcd_write_data */
  lcd_write_data();
}

/* flash page 3 cpu 0x4295 (offset 0x0295) */
void p03_L_4295(void) {
  p03_L_429B();
  p00_L_09CA();
  return;
}

/* flash page 3 cpu 0x429B (offset 0x029B) */
void p03_L_429B(void) {
  cpu_push_hl();
  p00_L_3E8B();
  set_hl(0x0503);
  mem_write16(0x844B, hl());
  cpu_pop_hl();
  p00_L_3C87();
  set_hl(0x2657);
  p00_L_3C87();
  p00_L_3F21();
  return;
}

/* flash page 3 cpu 0x4315 (offset 0x0315) */
void p03_L_4315(void) {
  set_hl(0x8445);
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p03_L_4320;
  h = a;
  l = a;
  goto lab_p03_L_432A;
  lab_p03_L_4320: ;
  e = a;
  d = 0x00;
  mem_write8(hl(), d);
  set_hl(0x432F);
  set_hl((uint16_t)(hl() + de()));
  l = mem_read8(hl());
  h = d;
  lab_p03_L_432A: ;
  p03_L_59B1();
  p00_L_038C();
  return;
}

/* flash page 3 cpu 0x4368 (offset 0x0368) */
void p03_L_4368(void) {
  set_hl(0x0000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_ex_de_hl();
  cpu_push_de();
  cpu_push_hl();
  lab_p03_L_4371: ;
  b = 0x00;
  lab_p03_L_4373: ;
  mem_write8(hl(), b);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() - 1));
  a = e;
  a = a | d;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_4382;
  b = (uint8_t)(b + 1);
  a = b;
  flag_cmp(a, 0xFB);
  if (flag_c()) goto lab_p03_L_4373;
  goto lab_p03_L_4371;
  lab_p03_L_4382: ;
  cpu_pop_hl();
  cpu_pop_de();
  lab_p03_L_4384: ;
  b = 0x00;
  lab_p03_L_4386: ;
  cpu_push_de();
  cpu_push_hl();
  set_de(0x9C86);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_z()) goto lab_p03_L_4396;
  a = mem_read8(hl());
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p03_L_43A4;
  lab_p03_L_4396: ;
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() - 1));
  a = e;
  a = a | d;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_43B3;
  b = (uint8_t)(b + 1);
  a = b;
  flag_cmp(a, 0xFB);
  if (flag_c()) goto lab_p03_L_4386;
  goto lab_p03_L_4384;
  lab_p03_L_43A4: ;
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_43AD;
  a = 0;
  flag_logic(a);
  hw_out(PORT_ASYN, a);
  lab_p03_L_43AD: ;
  set_hl(0x26A3);
  p03_L_4295();
  return;
  lab_p03_L_43B3: ;
  p00_L_0189();
  return;
}

/* flash page 3 cpu 0x43BE (offset 0x03BE) */
void p03_L_43BE(void) {
  set_hl(0x848E);
  p03_L_43C1();
  return;
}

/* flash page 3 cpu 0x43C1 (offset 0x03C1) */
void p03_L_43C1(void) {
  a = 0x01;
  set_de(0x0000);
  p00_L_17CE();
  if (flag_z()) goto lab_p03_L_43CF;
  a = (uint8_t)(a + 0x03);
  e = a;
  a = (uint8_t)(a + 1);
  lab_p03_L_43CF: ;
  mem_write8(0x97A5, a);
  mem_write16(0x844B, de());
  p00_L_3C87();
  p00_L_3D1D();
  return;
}

/* flash page 3 cpu 0x43DD (offset 0x03DD) */
void p03_L_43DD(void) {
  cpu_push16(ix);
  /* ld ix,(0x9700) */
  a = 0x01;
  p00_L_17CE();
  if (flag_z()) goto lab_p03_L_43EC;
  a = 0x05;
  lab_p03_L_43EC: ;
  mem_write8(0x844B, a);
  a = mem_read8(0x859A);
  flag_cmp(a, 0x53);
  if (flag_nz()) goto lab_p03_L_43FA;
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  lab_p03_L_43FA: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = mem_read8(0x844B);
  set_hl(0x97A6);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p03_L_441E;
  p03_L_4E6C();
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p03_L_441B;
  p03_L_44F5();
  set_de(0x0003);
  /* add ix,de */
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p03_L_43FA;
  lab_p03_L_441B: ;
  p00_L_3D29();
  lab_p03_L_441E: ;
  ix = cpu_pop16();
  return;
}

/* flash page 3 cpu 0x4421 (offset 0x0421) */
void p03_L_4421(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = mem_read8(0x844B);
  set_hl(0x97A6);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p03_L_445C;
  a = 0x20;
  p00_L_3F9F();
  a = mem_read8(0x9813);
  e = a;
  d = 0x5E;
  p00_L_3DB9();
  p00_L_3C93();
  a = 0x28;
  p00_L_3F9F();
  e = 0x1F;
  d = 0x63;
  p00_L_3DB9();
  p00_L_3C93();
  a = 0x29;
  p00_L_3F9F();
  p00_L_3627();
  p00_L_3F9F();
  p00_L_3D1D();
  lab_p03_L_445C: ;
  p00_L_3CC9();
  p03_L_44D9();
  p00_L_3AC5();
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  cpu_push_af();
  a = 0x7B;
  p00_L_3CAB();
  p03_L_44D9();
  set_de(0x8478);
  p00_L_1183();
  p03_L_44C6();
  cpu_pop_af();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p03_L_4490;
  a = 0x2C;
  p03_L_4492();
  p03_L_44D9();
  cpu_ex_de_hl();
  set_de(0x8478);
  p00_L_1183();
  p03_L_44C6();
  lab_p03_L_4490: ;
  a = 0x7D;
  p03_L_4492();
  return;
}

/* flash page 3 cpu 0x4492 (offset 0x0492) */
void p03_L_4492(void) {
  b = a;
  a = mem_read8(0x844B);
  a = (uint8_t)(a + 1);
  set_hl(0x97A6);
  cpu_cp_hl();
  a = b;
  if (flag_nc()) goto lab_p03_L_44AB;
  lab_p03_L_449E: ;
  set_de(mem_read16(0x844B));
  cpu_push_de();
  p00_L_3CAB();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
  lab_p03_L_44AB: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_449E;
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  set_de(mem_read16(0x844B));
  cpu_push_de();
  p00_L_3CAB();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  return;
}

/* flash page 3 cpu 0x44C6 (offset 0x04C6) */
void p03_L_44C6(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 2)) == 0);
  if (flag_z()) { p03_L_4587(); return; }
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  p03_L_4587();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  return;
}

/* flash page 3 cpu 0x44D9 (offset 0x04D9) */
void p03_L_44D9(void) {
  a = mem_read8(0x9813);
  a = (uint8_t)(a & ~(1u << 7));
  set_hl(0x8FCE);
  set_de(0x8FE9);
  a = (uint8_t)(a - 1);
  if (flag_m()) return;
  set_hl(0x8FD7);
  set_de(0x8FF2);
  a = (uint8_t)(a - 1);
  if (flag_m()) return;
  set_hl(0x8FFB);
  set_de(0x9016);
  return;
}

/* flash page 3 cpu 0x44F5 (offset 0x04F5) */
void p03_L_44F5(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = mem_read8(0x97A6);
  a = (uint8_t)(a - 1);
  set_hl(0x844B);
  cpu_cp_hl();
  if (flag_nz()) goto lab_p03_L_451A;
  a = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_4510;
  p00_L_362D();
  if (flag_nz()) goto lab_p03_L_4513;
  lab_p03_L_4510: ;
  a = mem_read8((uint16_t)(ix + 0x03));
  lab_p03_L_4513: ;
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p03_L_453E;
  a = 0x1F;
  p03_L_4518();
  return;
  lab_p03_L_451A: ;
  a = mem_read8(0x97A5);
  cpu_cp_hl();
  if (flag_nz()) goto lab_p03_L_453E;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x53);
  if (flag_z()) goto lab_p03_L_453E;
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_4534;
  p00_L_362D();
  if (flag_nz()) goto lab_p03_L_4537;
  lab_p03_L_4534: ;
  /* ld a,(ix-0x03) */
  lab_p03_L_4537: ;
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p03_L_453E;
  a = 0x1E;
  goto lab_p03_L_4540;
  lab_p03_L_453E: ;
  a = 0x20;
  lab_p03_L_4540: ;
  p00_L_3F9F();
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_454F;
  a = 0x03;
  p00_L_362D();
  if (flag_nz()) return;
  lab_p03_L_454F: ;
  /* ld ixl,(ix+0x01) */
  /* ld ixh,(ix+0x02) */
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p03_L_4565;
  cpu_push_bc();
  b = mem_read8(ix);
  a = 0x14;
  p00_L_3C45();
  cpu_pop_bc();
  lab_p03_L_4565: ;
  p03_L_7530();
  if (flag_z()) return;
  p03_L_4D49();
  a = 0x3D;
  p00_L_3F9F();
  p00_L_3CC9();
  p03_L_4574();
  return;
}

/* flash page 3 cpu 0x4518 (offset 0x0518) */
void p03_L_4518(void) {
  goto lab_p03_L_4540;
  lab_p03_L_4540: ;
  p00_L_3F9F();
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_454F;
  a = 0x03;
  p00_L_362D();
  if (flag_nz()) return;
  lab_p03_L_454F: ;
  /* ld ixl,(ix+0x01) */
  /* ld ixh,(ix+0x02) */
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p03_L_4565;
  cpu_push_bc();
  b = mem_read8(ix);
  a = 0x14;
  p00_L_3C45();
  cpu_pop_bc();
  lab_p03_L_4565: ;
  p03_L_7530();
  if (flag_z()) return;
  p03_L_4D49();
  a = 0x3D;
  p00_L_3F9F();
  p00_L_3CC9();
  p03_L_4574();
  return;
}

/* flash page 3 cpu 0x4574 (offset 0x0574) */
void p03_L_4574(void) {
  p03_L_7530();
  if (flag_nz()) { p03_L_4581(); return; }
  a = mem_read8(ix);
  p00_L_18A3();
  p03_L_4587();
  return;
}

/* flash page 3 cpu 0x4581 (offset 0x0581) */
void p03_L_4581(void) {
  a = mem_read8(ix);
  p00_L_3633();
  p03_L_4587();
  return;
}

/* flash page 3 cpu 0x4587 (offset 0x0587) */
void p03_L_4587(void) {
  a = 0x15;
  p00_L_3639();
  set_hl(0x848E);
  p00_L_3CB7();
  a = mem_read8(ix);
  flag_cmp(a, 0x30);
  if (flag_nz()) return;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x53);
  if (flag_nz()) return;
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_L_3CC9();
  set_de(0x0003);
  /* add ix,de */
  p03_L_4581();
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p00_L_3CC9();
  set_de(0xFFFD);
  /* add ix,de */
  return;
}

/* flash page 3 cpu 0x45BA (offset 0x05BA) */
void p03_L_45BA(void) {
  a = 0x06;
  mem_write8(0x844B, a);
  p03_L_45E3();
  return;
}

/* flash page 3 cpu 0x45C1 (offset 0x05C1) */
void p03_L_45C1(void) {
  a = 0x02;
  p00_L_17CE();
  if (flag_z()) goto lab_p03_L_45D5;
  a = 0x06;
  goto lab_p03_L_45D5;
  lab_p03_L_45D5: ;
  mem_write8(0x844B, a);
  a = mem_read8(0x859A);
  flag_cmp(a, 0x53);
  if (flag_nz()) { p03_L_45E3(); return; }
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p03_L_45E3();
  return;
}

/* flash page 3 cpu 0x45CC (offset 0x05CC) */
void p03_L_45CC(void) {
  a = 0x01;
  p00_L_17CE();
  if (flag_z()) goto lab_p03_L_45D5;
  a = 0x05;
  lab_p03_L_45D5: ;
  mem_write8(0x844B, a);
  a = mem_read8(0x859A);
  flag_cmp(a, 0x53);
  if (flag_nz()) { p03_L_45E3(); return; }
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p03_L_45E3();
  return;
}

/* flash page 3 cpu 0x45CD (offset 0x05CD) */
void p03_L_45CD(void) {
  set_bc(0xCECD);
  cpu_rla();
  if (flag_z()) goto lab_p03_L_45D5;
  a = 0x05;
  lab_p03_L_45D5: ;
  mem_write8(0x844B, a);
  a = mem_read8(0x859A);
  flag_cmp(a, 0x53);
  if (flag_nz()) { p03_L_45E3(); return; }
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p03_L_45E3();
  return;
}

/* flash page 3 cpu 0x45E3 (offset 0x05E3) */
void p03_L_45E3(void) {
  p00_L_03A0();
  p03_L_464A();
  set_hl(mem_read16(0x9700));
  p03_L_7530();
  if (flag_nz()) goto lab_p03_L_4602;
  a = mem_read8(hl());
  p00_L_18A3();
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_nz()) goto lab_p03_L_4600;
  a = 0;
  flag_logic(a);
  mem_write8(0x8478, a);
  lab_p03_L_4600: ;
  p03_L_4613();
  return;
  lab_p03_L_4602: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_460F;
  a = 0x05;
  p00_L_362D();
  if (flag_nz()) { p03_L_4613(); return; }
  lab_p03_L_460F: ;
  a = mem_read8(hl());
  p00_L_3633();
  p03_L_4613();
  return;
}

/* flash page 3 cpu 0x4613 (offset 0x0613) */
void p03_L_4613(void) {
  p00_L_363F();
  p03_L_4616();
  return;
}

/* flash page 3 cpu 0x4616 (offset 0x0616) */
void p03_L_4616(void) {
  if (flag_nc()) { p03_L_461E(); return; }
  p03_L_4AF2();
  p00_L_24F9();
  return;
}

/* flash page 3 cpu 0x461E (offset 0x061E) */
void p03_L_461E(void) {
  p00_L_3645();
  p00_L_3DE3();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 5)));
  return;
}

/* flash page 3 cpu 0x4629 (offset 0x0629) */
void p03_L_4629(void) {
  p03_L_464A();
  p03_L_44D9();
  p00_L_3AC5();
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  p00_L_364B();
  if (flag_nc()) goto lab_p03_L_463F;
  p03_L_4AF2();
  p00_L_24F9();
  return;
  lab_p03_L_463F: ;
  p00_L_3645();
  p00_L_3DE3();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 5)));
  return;
}

/* flash page 3 cpu 0x464A (offset 0x064A) */
void p03_L_464A(void) {
  p03_L_4A0F();
  p03_L_464D();
  return;
}

/* flash page 3 cpu 0x464D (offset 0x064D) */
void p03_L_464D(void) {
  p03_L_49FB();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 6)));
  p03_L_465E();
  mem_write16(0x9706, hl());
  p00_L_3651();
  return;
}

/* flash page 3 cpu 0x465E (offset 0x065E) */
void p03_L_465E(void) {
  p03_L_4AF2();
  set_hl(0x24F9);
  p00_L_25A2();
  set_hl(0x0014);
  p00_L_1CA8();
  p00_L_25C8();
  return;
}

/* flash page 3 cpu 0x4671 (offset 0x0671) */
void p03_L_4671(void) {
  cpu_push_af();
  p03_L_481D();
  cpu_pop_af();
  return;
}

/* flash page 3 cpu 0x4727 (offset 0x0727) */
void p03_L_4727(void) {
  p03_L_4A97();
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 4)) == 0);
  if (flag_z()) p03_L_4AFA();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 4)));
  /* ld ix,(0x9700) */
  return;
}

/* flash page 3 cpu 0x473A (offset 0x073A) */
void p03_L_473A(void) {
  set_hl(mem_read16(0x9700));
  a = mem_read8(hl());
  flag_cmp(a, 0x1F);
  if (flag_z()) goto lab_p03_L_4749;
  p03_L_4742();
  return;
  lab_p03_L_4749: ;
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 3 cpu 0x4742 (offset 0x0742) */
void p03_L_4742(void) {
  a = mem_read8(0x859A);
  flag_cmp(a, 0x49);
  if (flag_z()) goto lab_p03_L_474B;
  a = 0;
  flag_logic(a);
  return;
  lab_p03_L_474B: ;
  p00_L_019D();
  return;
}

/* flash page 3 cpu 0x479B (offset 0x079B) */
void p03_L_479B(void) {
  p03_L_473A();
  if (flag_nz()) { p03_L_47FE(); return; }
  p00_L_1916();
  if (flag_z()) return;
  p03_L_4A97();
  p03_L_4AFA();
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_47B7;
  p00_L_362D();
  if (flag_nz()) goto lab_p03_L_47BA;
  lab_p03_L_47B7: ;
  /* ld a,(ix-0x03) */
  lab_p03_L_47BA: ;
  a = (uint8_t)(a + 1);
  if (flag_nz()) goto lab_p03_L_47C8;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x49);
  if (flag_nz()) goto lab_p03_L_47DE;
  p00_L_367B();
  return;
  lab_p03_L_47C8: ;
  set_de(0xFFFD);
  /* add ix,de */
  /* ld (0x9700),ix */
  p03_L_49A6();
  if (flag_nc()) goto lab_p03_L_47DB;
  p03_L_44F5();
  goto lab_p03_L_47DE;
  lab_p03_L_47DB: ;
  mem_write8(0x844B, a);
  lab_p03_L_47DE: ;
  p03_L_45E3();
  return;
}

/* flash page 3 cpu 0x47E1 (offset 0x07E1) */
void p03_L_47E1(void) {
  set_de(0xFFFD);
  /* add ix,de */
  /* ld (0x9700),ix */
  p03_L_49A6();
  if (flag_nc()) goto lab_p03_L_47F4;
  p03_L_4421();
  goto lab_p03_L_47F7;
  lab_p03_L_47F4: ;
  mem_write8(0x844B, a);
  lab_p03_L_47F7: ;
  p03_L_4629();
  p03_L_57E3();
  return;
}

/* flash page 3 cpu 0x47FE (offset 0x07FE) */
void p03_L_47FE(void) {
  p03_L_4727();
  /* ld a,(ix-0x03) */
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p03_L_4810;
  set_de(0xFFFD);
  /* add ix,de */
  /* ld (0x9700),ix */
  lab_p03_L_4810: ;
  p00_L_3687();
  return;
}

/* flash page 3 cpu 0x481D (offset 0x081D) */
void p03_L_481D(void) {
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p03_L_482E;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  p00_L_03A0();
  p00_L_366F();
  p03_L_49C9();
  return;
  lab_p03_L_482E: ;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p03_L_4858;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 5)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  p00_L_366F();
  p00_L_03A0();
  p00_L_3645();
  p03_L_49FB();
  p00_L_1748();
  p00_L_368D();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 5)));
  p00_L_3645();
  p00_L_3DE3();
  return;
  lab_p03_L_4858: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p03_L_489E;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  p00_L_3BD3();
  if (flag_z()) { p03_L_48F5(); return; }
  p03_L_4866();
  return;
  lab_p03_L_4888: ;
  mem_write8(0x844C, a);
  p00_L_3DE3();
  p03_L_48F5();
  return;
  lab_p03_L_4890: ;
  a = mem_read8(0x97A7);
  a = (uint8_t)(a + 1);
  mem_write8(0x844C, a);
  cpu_push_af();
  p00_L_3BD9();
  cpu_pop_af();
  goto lab_p03_L_4888;
  lab_p03_L_489E: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p03_L_48FA;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  p00_L_3693();
  if (flag_z()) return;
  p00_L_3DAD();
  set_hl(0x844C);
  /* add a,(hl) */
  cpu_push_af();
  p00_L_3699();
  cpu_pop_bc();
  a = b;
  flag_cmp(a, 0x0F);
  if (flag_c()) goto lab_p03_L_48F2;
  if (flag_nz()) goto lab_p03_L_48C3;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p03_L_48F2;
  lab_p03_L_48C3: ;
  a = 0x0E;
  mem_write8(0x844C, a);
  p00_L_3699();
  if (flag_nz()) goto lab_p03_L_48DA;
  p00_L_3BD3();
  cpu_push_de();
  p00_L_3699();
  cpu_pop_de();
  p00_L_3C9F();
  p03_L_48F5();
  return;
  lab_p03_L_48DA: ;
  cpu_push_de();
  p00_L_3DAD();
  cpu_pop_de();
  cpu_push_af();
  /* scf */
  p00_L_3CA5();
  p00_L_3BD3();
  cpu_pop_bc();
  a = mem_read8(0x844C);
  a = (uint8_t)(a - b);
  set_hl(0x97A7);
  cpu_cp_hl();
  if (flag_c()) goto lab_p03_L_4890;
  lab_p03_L_48F2: ;
  mem_write8(0x844C, a);
  p03_L_48F5();
  return;
  lab_p03_L_48FA: ;
  flag_cmp(a, 0x0E);
  if (flag_nz()) goto lab_p03_L_4903;
  p03_L_4B65();
  p03_L_48F5();
  return;
  lab_p03_L_4903: ;
  flag_cmp(a, 0x0F);
  if (flag_nz()) goto lab_p03_L_490C;
  p03_L_4B73();
  p03_L_48F5();
  return;
  lab_p03_L_490C: ;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p03_L_4917;
  p03_L_48F5();
  p00_L_369F();
  return;
  lab_p03_L_4917: ;
  flag_cmp(a, 0x21);
  if (flag_nz()) goto lab_p03_L_4929;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  p00_L_3BD3();
  if (flag_z()) { p03_L_48F5(); return; }
  p03_L_4866();
  goto lab_p03_L_492D;
  lab_p03_L_4929: ;
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p03_L_4943;
  lab_p03_L_492D: ;
  p00_L_366F();
  p03_L_48F5();
  p03_L_4933();
  return;
  lab_p03_L_4943: ;
  flag_cmp(a, 0x0C);
  if (flag_z()) p00_L_36AB();
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  flag_cmp(a, 0x5A);
  if (flag_c()) return;
  flag_cmp(a, 0xFB);
  if (flag_nz()) goto lab_p03_L_4960;
  a = mem_read8(0x8446);
  flag_cmp(a, 0x0D);
  if (flag_c()) goto lab_p03_L_495E;
  flag_cmp(a, 0x8C);
  if (flag_c()) return;
  flag_cmp(a, 0xA6);
  if (flag_nc()) return;
  lab_p03_L_495E: ;
  a = 0xFB;
  lab_p03_L_4960: ;
  p00_L_366F();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p03_L_4972;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p03_L_4972;
  flag_cmp(a, 0xC6);
  if (flag_z()) return;
  lab_p03_L_4972: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 6)) == 0);
  if (flag_nz()) p03_L_49C9();
  p00_L_1808();
  if (flag_nz()) { p03_L_49DE(); return; }
  p00_L_36B1();
  return;
}

/* flash page 3 cpu 0x4866 (offset 0x0866) */
void p03_L_4866(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 2)));
  p00_L_191A();
  if (flag_z()) goto lab_p03_L_48FE;
  set_hl(mem_read16(0x96F8));
  p00_L_3C0F();
  p00_L_3DAD();
  b = a;
  a = mem_read8(0x844C);
  a = (uint8_t)(a - b);
  if (flag_c()) goto lab_p03_L_4890;
  set_hl(0x97A7);
  cpu_cp_hl();
  if (flag_c()) goto lab_p03_L_4890;
  if (flag_z()) goto lab_p03_L_4890;
  lab_p03_L_4888: ;
  mem_write8(0x844C, a);
  p00_L_3DE3();
  p03_L_48F5();
  return;
  lab_p03_L_4890: ;
  a = mem_read8(0x97A7);
  a = (uint8_t)(a + 1);
  mem_write8(0x844C, a);
  cpu_push_af();
  p00_L_3BD9();
  cpu_pop_af();
  goto lab_p03_L_4888;
  lab_p03_L_48FE: ;
  p03_L_4B65();
  p03_L_48F5();
  return;
}

/* flash page 3 cpu 0x48F5 (offset 0x08F5) */
void p03_L_48F5(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 6)));
  return;
}

/* flash page 3 cpu 0x4933 (offset 0x0933) */
void p03_L_4933(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  p00_L_36A5();
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  p00_L_3DE3();
  return;
}

/* flash page 3 cpu 0x4979 (offset 0x0979) */
void p03_L_4979(void) {
  halt();
  if (flag_nz()) p03_L_49C9();
  p00_L_1808();
  if (flag_nz()) { p03_L_49DE(); return; }
  p00_L_36B1();
  return;
}

/* flash page 3 cpu 0x4987 (offset 0x0987) */
void p03_L_4987(void) {
  a = mem_read8(0x844B);
  a = (uint8_t)(a + 1);
  set_hl(0x97A6);
  cpu_cp_hl();
  if (flag_c()) return;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x49);
  if (flag_nz()) goto lab_p03_L_499B;
  p00_L_3CE1();
  return;
  lab_p03_L_499B: ;
  p03_L_4A4C();
  p00_L_3CE1();
  p03_L_4A39();
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 3 cpu 0x49A6 (offset 0x09A6) */
void p03_L_49A6(void) {
  a = mem_read8(0x844B);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_49BE;
  a = (uint8_t)(a - 1);
  set_hl(0x97A5);
  cpu_cp_hl();
  if (flag_nc()) return;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x49);
  if (flag_nz()) goto lab_p03_L_49BE;
  p00_L_3CF9();
  /* scf */
  return;
  lab_p03_L_49BE: ;
  p03_L_4A4C();
  p00_L_3CF9();
  p03_L_4A40();
  /* scf */
  return;
}

/* flash page 3 cpu 0x49C9 (offset 0x09C9) */
void p03_L_49C9(void) {
  p03_L_48F5();
  p00_L_36B7();
  p03_L_49FB();
  p00_L_3D1D();
  p03_L_49D5();
  return;
}

/* flash page 3 cpu 0x49D5 (offset 0x09D5) */
void p03_L_49D5(void) {
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 0)));
  p03_L_49D9();
  return;
}

/* flash page 3 cpu 0x49D9 (offset 0x09D9) */
void p03_L_49D9(void) {
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 1)));
  return;
}

/* flash page 3 cpu 0x49DE (offset 0x09DE) */
void p03_L_49DE(void) {
  p00_L_3BBB();
  p03_L_49E1();
  return;
}

/* flash page 3 cpu 0x49E1 (offset 0x09E1) */
void p03_L_49E1(void) {
  cpu_push_de();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p03_L_49F1;
  p00_L_36BD();
  cpu_pop_de();
  if (flag_z()) return;
  p00_L_3C9F();
  return;
  lab_p03_L_49F1: ;
  p00_L_36C3();
  cpu_pop_de();
  if (flag_z()) return;
  p00_L_3C9F();
  return;
}

/* flash page 3 cpu 0x49FA (offset 0x09FA) */
void p03_L_49FA(void) {
  return;
}

/* flash page 3 cpu 0x49FB (offset 0x09FB) */
void p03_L_49FB(void) {
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p03_L_4A07;
  cpu_pop_af();
  p00_L_36C9();
  return;
  lab_p03_L_4A07: ;
  a = mem_read8(0x97A7);
  mem_write8(0x844C, a);
  cpu_pop_af();
  return;
}

/* flash page 3 cpu 0x4A0F (offset 0x0A0F) */
void p03_L_4A0F(void) {
  a = 0x01;
  mem_write8(0x844C, a);
  c = a;
  p00_L_3D35();
  b = 0x0E;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  c = (uint8_t)(c + 1);
  flag_cmp(a, 0x3D);
  if (flag_z()) goto lab_p03_L_4A31;
  p03_L_4A21();
  return;
  lab_p03_L_4A31: ;
  a = c;
  mem_write8(0x97A7, a);
  mem_write8(0x844C, a);
  return;
}

/* flash page 3 cpu 0x4A21 (offset 0x0A21) */
void p03_L_4A21(void) {
  goto lab_p03_L_4A21;
  lab_p03_L_4A1A: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  c = (uint8_t)(c + 1);
  flag_cmp(a, 0x3D);
  if (flag_z()) goto lab_p03_L_4A31;
  lab_p03_L_4A21: ;
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p03_L_4A31;
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p03_L_4A31;
  flag_cmp(a, 0x7F);
  if (flag_z()) goto lab_p03_L_4A31;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_4A1A;
  a = 0;
  flag_logic(a);
  return;
  lab_p03_L_4A31: ;
  a = c;
  mem_write8(0x97A7, a);
  mem_write8(0x844C, a);
  return;
}

/* flash page 3 cpu 0x4A39 (offset 0x0A39) */
void p03_L_4A39(void) {
  c = 0x1E;
  a = mem_read8(0x97A5);
  p03_L_4A51();
  return;
}

/* flash page 3 cpu 0x4A40 (offset 0x0A40) */
void p03_L_4A40(void) {
  c = 0x1F;
  goto lab_p03_L_4A46;
  lab_p03_L_4A46: ;
  a = mem_read8(0x97A6);
  a = (uint8_t)(a - 1);
  p03_L_4A51();
  return;
}

/* flash page 3 cpu 0x4A44 (offset 0x0A44) */
void p03_L_4A44(void) {
  c = 0x20;
  a = mem_read8(0x97A6);
  a = (uint8_t)(a - 1);
  p03_L_4A51();
  return;
}

/* flash page 3 cpu 0x4A4C (offset 0x0A4C) */
void p03_L_4A4C(void) {
  a = mem_read8(0x844B);
  c = 0x20;
  p03_L_4A51();
  return;
}

/* flash page 3 cpu 0x4A51 (offset 0x0A51) */
void p03_L_4A51(void) {
  b = a;
  a = mem_read8(0x97A7);
  cpu_push_af();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x844B);
  mem_write8(hl(), b);
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = c;
  p00_L_3F9F();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  cpu_pop_af();
  mem_write8(0x97A7, a);
  return;
}

/* flash page 3 cpu 0x4A8B (offset 0x0A8B) */
void p03_L_4A8B(void) {
  p00_L_03A0();
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_z()) return;
  p00_L_36CF();
  return;
}

/* flash page 3 cpu 0x4A97 (offset 0x0A97) */
void p03_L_4A97(void) {
  p00_L_1916();
  if (flag_nz()) goto lab_p03_L_4AAB;
  p03_L_4742();
  if (flag_z()) goto lab_p03_L_4AAB;
  p03_L_4A8B();
  a = 0x0E;
  mem_write8(0x8478, a);
  goto lab_p03_L_4ABE;
  lab_p03_L_4AAB: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 6)));
  p03_L_4A8B();
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 4)) == 0);
  if (flag_nz()) { p03_L_4AE9(); return; }
  p00_L_166E();
  p00_L_36D5();
  lab_p03_L_4ABE: ;
  set_hl(mem_read16(0x9700));
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 5)) == 0);
  if (flag_z()) { p03_L_4AE9(); return; }
  p03_L_7530();
  if (flag_nz()) goto lab_p03_L_4AD8;
  p00_L_1717();
  p00_L_1653();
  a = mem_read8(hl());
  p00_L_1897();
  p03_L_4AE9();
  return;
  lab_p03_L_4AD8: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_4AE5;
  a = 0x06;
  p00_L_362D();
  if (flag_nz()) { p03_L_4AE9(); return; }
  lab_p03_L_4AE5: ;
  a = mem_read8(hl());
  p00_L_3675();
  p03_L_4AE9();
  return;
}

/* flash page 3 cpu 0x4AE9 (offset 0x0AE9) */
void p03_L_4AE9(void) {
  p00_L_36DB();
  p03_L_4AF2();
  return;
}

/* flash page 3 cpu 0x4AF2 (offset 0x0AF2) */
void p03_L_4AF2(void) {
  p00_L_166E();
  p00_rst10();
  if (flag_nc()) p00_L_1F58();
  return;
}

/* flash page 3 cpu 0x4AFA (offset 0x0AFA) */
void p03_L_4AFA(void) {
  goto lab_p03_L_4AFA;
  lab_p03_L_445F: ;
  p03_L_44D9();
  p00_L_3AC5();
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  cpu_push_af();
  a = 0x7B;
  p00_L_3CAB();
  p03_L_44D9();
  set_de(0x8478);
  p00_L_1183();
  p03_L_44C6();
  cpu_pop_af();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p03_L_4490;
  a = 0x2C;
  p03_L_4492();
  p03_L_44D9();
  cpu_ex_de_hl();
  set_de(0x8478);
  p00_L_1183();
  p03_L_44C6();
  lab_p03_L_4490: ;
  a = 0x7D;
  p03_L_4492();
  return;
  lab_p03_L_4AFA: ;
  p03_L_49FB();
  p00_L_3CC9();
  /* ld ix,(0x9700) */
  p03_L_473A();
  if (flag_nz()) goto lab_p03_L_445F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_4B16;
  a = 0x09;
  p00_L_362D();
  if (flag_nz()) return;
  lab_p03_L_4B16: ;
  p03_L_4574();
  return;
}

/* flash page 3 cpu 0x4B19 (offset 0x0B19) */
void p03_L_4B19(void) {
  set_hl(mem_read16(0x9706));
  p03_L_4B1C();
  return;
}

/* flash page 3 cpu 0x4B1C (offset 0x0B1C) */
void p03_L_4B1C(void) {
  cpu_push_hl();
  p00_L_1295();
  cpu_pop_hl();
  a = mem_read8(hl());
  p03_L_4B22();
  return;
}

/* flash page 3 cpu 0x4B22 (offset 0x0B22) */
void p03_L_4B22(void) {
  a = a & 0x1F;
  flag_logic(a);
  mem_write8(0x8478, a);
  b = 0x02;
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p03_L_4B37;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p03_L_4B48;
  lab_p03_L_4B37: ;
  a = mem_read8(hl());
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p03_L_4B40;
  b = mem_read8(hl());
  b = (uint8_t)(b - 1);
  goto lab_p03_L_4B47;
  lab_p03_L_4B40: ;
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_4B48;
  b = mem_read8(hl());
  lab_p03_L_4B47: ;
  set_hl((uint16_t)(hl() - 1));
  lab_p03_L_4B48: ;
  set_de(0x8479);
  goto lab_p03_L_4B5E;
  lab_p03_L_4B5E: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_4B5E;
  return;
}

/* flash page 3 cpu 0x4B4D (offset 0x0B4D) */
void p03_L_4B4D(void) {
  p00_L_1295();
  set_hl(mem_read16(0x9706));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  b = mem_read8(hl());
  b = (uint8_t)(b + 1);
  set_de(0x8479);
  lab_p03_L_4B5E: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_4B5E;
  return;
}

/* flash page 3 cpu 0x4B65 (offset 0x0B65) */
void p03_L_4B65(void) {
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 0)));
  p00_L_3645();
  p03_L_49FB();
  p00_L_3DE3();
  return;
}

/* flash page 3 cpu 0x4B73 (offset 0x0B73) */
void p03_L_4B73(void) {
  lab_p03_L_4B73: ;
  p00_L_3699();
  if (flag_z()) return;
  p00_L_3C9F();
  goto lab_p03_L_4B73;
}

/* flash page 3 cpu 0x4B7C (offset 0x0B7C) */
void p03_L_4B7C(void) {
  p00_L_3D6B();
  return;
}

/* flash page 3 cpu 0x4B7F (offset 0x0B7F) */
void p03_L_4B7F(void) {
  set_hl(0x4AEE);
  p00_L_25A2();
  p03_L_4A97();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 3)));
  return;
}

/* flash page 3 cpu 0x4BCD (offset 0x0BCD) */
void p03_L_4BCD(void) {
  cpu_rra();
  a = b;
  p03_L_4A51();
  return;
}

/* flash page 3 cpu 0x4C83 (offset 0x0C83) */
void p03_L_4C83(void) {
  p00_L_3D77();
  return;
}

/* flash page 3 cpu 0x4C86 (offset 0x0C86) */
void p03_L_4C86(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 5)) == 0);
  if (flag_nz()) p00_L_36F3();
  if (flag_nz()) { p03_L_4C95(); return; }
  p00_L_3D7D();
  p00_L_36F9();
  p03_L_4C95();
  return;
}

/* flash page 3 cpu 0x4C95 (offset 0x0C95) */
void p03_L_4C95(void) {
  goto lab_p03_L_4C95;
  lab_p03_L_4A6F: ;
  p03_L_48F5();
  set_bc(mem_read16(0x86E0));
  lab_p03_L_4A76: ;
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_4A87;
  p00_L_3699();
  if (flag_z()) goto lab_p03_L_4A87;
  cpu_push_bc();
  p00_L_3C9F();
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  goto lab_p03_L_4A76;
  lab_p03_L_4A87: ;
  p00_L_3DE3();
  return;
  lab_p03_L_4C95: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p03_L_4CAA;
  p00_L_166E();
  p00_L_36FF();
  set_hl(0x4CBD);
  p00_L_25A2();
  p00_L_25C8();
  lab_p03_L_4CAA: ;
  p00_L_3645();
  p03_L_49D5();
  p03_L_49FB();
  p00_L_0193();
  if (flag_nz()) goto lab_p03_L_4A6F;
  p00_L_3DE3();
  return;
}

/* flash page 3 cpu 0x4CC6 (offset 0x0CC6) */
void p03_L_4CC6(void) {
  cpu_push_hl();
  set_hl(mem_read16(0x84DD));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  /* or (hl) */
  a = mem_read8(0x847A);
  if (flag_z()) goto lab_p03_L_4D27;
  cpu_pop_bc();
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) goto lab_p03_L_4CEF;
  cpu_push_bc();
  cpu_push_af();
  a = a ^ 0x01;
  flag_logic(a);
  mem_write8(0x847A, a);
  p00_rst10();
  if (flag_c()) { p00_L_24F1(); return; }
  cpu_pop_af();
  cpu_pop_bc();
  mem_write8(0x847A, a);
  cpu_ex_de_hl();
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  /* or (hl) */
  if (flag_z()) return;
  cpu_ex_de_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  lab_p03_L_4CEF: ;
  set_hl(mem_read16(0x981C));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  lab_p03_L_4CF4: ;
  a = mem_read8(0x847A);
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_z()) goto lab_p03_L_4D15;
  p00_L_0198();
  lab_p03_L_4CFE: ;
  if (flag_z()) return;
  a = b;
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_z()) { p00_L_0087(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 1)) == 0);
  if (flag_nz()) { p00_L_0087(); return; }
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 0)));
  p00_L_0091();
  return;
  lab_p03_L_4D15: ;
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p03_L_4D44;
  flag_set_z((a & (1u << 4)) == 0);
  if (flag_z()) goto lab_p03_L_4D22;
  p00_L_0013();
  goto lab_p03_L_4CFE;
  lab_p03_L_4D22: ;
  p00_L_019D();
  goto lab_p03_L_4CFE;
  lab_p03_L_4D27: ;
  cpu_pop_bc();
  set_hl(mem_read16(0x981C));
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_z()) return;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 5)));
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) goto lab_p03_L_4CF4;
  cpu_push_af();
  a = a ^ 0x01;
  flag_logic(a);
  mem_write8(0x847A, a);
  p00_rst10();
  if (flag_c()) { p00_L_24F1(); return; }
  cpu_pop_af();
  mem_write8(0x847A, a);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 5)));
  lab_p03_L_4D44: ;
  p00_L_01A2();
  goto lab_p03_L_4CFE;
}

/* flash page 3 cpu 0x4D49 (offset 0x0D49) */
void p03_L_4D49(void) {
  cpu_push_bc();
  cpu_push_af();
  a = mem_read8(0x97A6);
  b = a;
  lab_p03_L_4D4F: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  /* scf */
  if (flag_z()) goto lab_p03_L_4D5E;
  p00_L_3F9F();
  a = mem_read8(0x844B);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p03_L_4D4F;
  lab_p03_L_4D5E: ;
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  return;
}

/* flash page 3 cpu 0x4D67 (offset 0x0D67) */
void p03_L_4D67(void) {
  a = mem_read8(ix);
  return;
}

/* flash page 3 cpu 0x4D6B (offset 0x0D6B) */
void p03_L_4D6B(void) {
  cpu_push_bc();
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p03_L_4D7B;
  b = a;
  a = 0x00;
  p00_L_3705();
  a = b;
  if (flag_z()) goto lab_p03_L_4D97;
  lab_p03_L_4D7B: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p03_L_4D8A;
  b = a;
  a = 0x75;
  p00_L_3C45();
  a = b;
  if (flag_z()) goto lab_p03_L_4D97;
  lab_p03_L_4D8A: ;
  set_de(0x4E74);
  set_hl((uint16_t)(hl() + de()));
  set_de(0x8462);
  p00_L_1185();
  set_hl(0x8462);
  lab_p03_L_4D97: ;
  cpu_pop_bc();
  return;
}

/* flash page 3 cpu 0x4D99 (offset 0x0D99) */
void p03_L_4D99(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p03_L_4DA7;
  b = a;
  a = 0x02;
  p00_L_3705();
  a = b;
  if (flag_z()) return;
  lab_p03_L_4DA7: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p03_L_4DB5;
  b = a;
  a = 0x77;
  p00_L_3C45();
  a = b;
  if (flag_z()) return;
  lab_p03_L_4DB5: ;
  set_de(0x4E74);
  set_hl((uint16_t)(hl() + de()));
  b = mem_read8(hl());
  return;
}

/* flash page 3 cpu 0x4DBB (offset 0x0DBB) */
void p03_L_4DBB(void) {
  cpu_push_bc();
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p00_L_24C9(); return; }
  p00_L_17CE();
  if (flag_z()) goto lab_p03_L_4DC7;
  a = (uint8_t)(a + 0x04);
  lab_p03_L_4DC7: ;
  cpu_pop_hl();
  l = a;
  cpu_push_hl();
  p00_L_113F();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_3ED3();
  cpu_pop_hl();
  a = h;
  a = (uint8_t)(a - 1);
  if (flag_m()) { p00_L_24C9(); return; }
  flag_cmp(a, 0x10);
  if (flag_p()) { p00_L_24C9(); return; }
  h = a;
  a = mem_read8(0x97A6);
  b = a;
  a = l;
  a = (uint8_t)(a - 1);
  if (flag_m()) { p00_L_24C9(); return; }
  flag_cmp(a, b);
  if (flag_p()) { p00_L_24C9(); return; }
  l = a;
  set_de(mem_read16(0x844B));
  cpu_push_de();
  mem_write16(0x844B, hl());
  set_hl(0x4E65);
  p00_L_25A2();
  set_hl(mem_read16(0x9824));
  mem_write16(0x96F4, hl());
  mem_write16(0x96F6, hl());
  cpu_ex_de_hl();
  set_hl(mem_read16(0x9828));
  mem_write16(0x96F8, hl());
  mem_write16(0x96FA, hl());
  p00_L_192A();
  if (flag_c()) { p00_L_24F9(); return; }
  set_de(0x865F);
  p00_L_11FD();
  set_hl(0x865F);
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_4E40;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p03_L_4E3E;
  p00_rst10();
  if (flag_nc()) goto lab_p03_L_4E3F;
  a = 0x0C;
  set_hl(0x8478);
  set_de(0x848E);
  p00_L_1183();
  set_hl(0x8483);
  p00_L_1183();
  set_hl(0x848E);
  goto lab_p03_L_4E40;
  lab_p03_L_4E3E: ;
  p00_rst10();
  lab_p03_L_4E3F: ;
  cpu_ex_de_hl();
  lab_p03_L_4E40: ;
  p00_L_370B();
  if (flag_c()) { p00_L_24F5(); return; }
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  set_hl(mem_read16(0x96F6));
  set_de(mem_read16(0x86D9));
  p00_L_3E01();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  /* res 5,(iy) */
  /* ei */
  return;
}

/* flash page 3 cpu 0x4E35 (offset 0x0E35) */
void p03_L_4E35(void) {
  a = (uint8_t)(a + h);
  p00_L_1183();
  set_hl(0x848E);
  goto lab_p03_L_4E40;
  lab_p03_L_4E40: ;
  p00_L_370B();
  if (flag_c()) { p00_L_24F5(); return; }
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  set_hl(mem_read16(0x96F6));
  set_de(mem_read16(0x86D9));
  p00_L_3E01();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  /* res 5,(iy) */
  /* ei */
  return;
}

/* flash page 3 cpu 0x4E4F (offset 0x0E4F) */
void p03_L_4E4F(void) {
  /* sub (hl) */
  set_de(mem_read16(0x86D9));
  p00_L_3E01();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  /* res 5,(iy) */
  /* ei */
  return;
}

/* flash page 3 cpu 0x4E6C (offset 0x0E6C) */
void p03_L_4E6C(void) {
  a = 0x00;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_4E78;
  p00_L_362D();
  if (flag_nz()) return;
  lab_p03_L_4E78: ;
  a = mem_read8(ix);
  return;
}

/* flash page 3 cpu 0x4F11 (offset 0x0F11) */
void p03_L_4F11(void) {
  cpu_ex_af();
  c = 0x00;
  b = (uint8_t)(b - 1);
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  d = 0x18;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_4F32;
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x04;
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  b = 0x18;
  b = 0x00;
  lab_p03_L_4F32: ;
  e = 0x00;
  b = 0x00;
  b = (uint8_t)(b + 1);
  a = 0x08;
  a = 0x10;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  goto lab_p03_L_4F46;
  lab_p03_L_4F46: ;
  /* nop */
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x08;
  c = (uint8_t)(c + 1);
  cpu_ex_af();
  c = 0x00;
  b = (uint8_t)(b - 1);
  /* nop */
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  e = 0x04;
  cpu_ex_af();
  /* nop */
  b = 0x00;
  /* nop */
  l = 0x2A;
  set_hl(mem_read16(0x002E));
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  mem_write8(bc(), a);
  cpu_rlca();
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  cpu_rlca();
  mem_write8(bc(), a);
  /* nop */
  set_bc(0x0000);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  /* nop */
  /* nop */
  /* nop */
  b = 0x00;
  d = (uint8_t)(d + 1);
  a = 0x14;
  a = 0x14;
  /* nop */
  b = 0x00;
  e = (uint8_t)(e + 1);
  if (flag_z()) goto lab_p03_L_4FB5;
  a = mem_read8(bc());
  a = (uint8_t)(a + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  cpu_ex_af();
  d = (uint8_t)(d + 1);
  cpu_ex_af();
  d = (uint8_t)(d + 1);
  a = mem_read8(bc());
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  /* nop */
  /* nop */
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  lab_p03_L_4FB5: ;
  /* nop */
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x00;
  cpu_ex_af();
  set_hl(mem_read16(0x2A1C));
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  c = 0x04;
  /* nop */
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* nop */
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  c = 0x00;
  /* nop */
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  a = mem_read8(bc());
  c = 0x02;
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x08;
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x08;
  c = 0x0A;
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x02;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x0A;
  c = 0x0A;
  p03_L_503A();
  return;
}

/* flash page 3 cpu 0x4F31 (offset 0x0F31) */
void p03_L_4F31(void) {
  /* nop */
  e = 0x00;
  b = 0x00;
  b = (uint8_t)(b + 1);
  a = 0x08;
  a = 0x10;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  goto lab_p03_L_4F46;
  lab_p03_L_4F46: ;
  /* nop */
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x08;
  c = (uint8_t)(c + 1);
  cpu_ex_af();
  c = 0x00;
  b = (uint8_t)(b - 1);
  /* nop */
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  e = 0x04;
  cpu_ex_af();
  /* nop */
  b = 0x00;
  /* nop */
  l = 0x2A;
  set_hl(mem_read16(0x002E));
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  mem_write8(bc(), a);
  cpu_rlca();
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  cpu_rlca();
  mem_write8(bc(), a);
  /* nop */
  set_bc(0x0000);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  /* nop */
  /* nop */
  /* nop */
  b = 0x00;
  d = (uint8_t)(d + 1);
  a = 0x14;
  a = 0x14;
  /* nop */
  b = 0x00;
  e = (uint8_t)(e + 1);
  if (flag_z()) goto lab_p03_L_4FB5;
  a = mem_read8(bc());
  a = (uint8_t)(a + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  cpu_ex_af();
  d = (uint8_t)(d + 1);
  cpu_ex_af();
  d = (uint8_t)(d + 1);
  a = mem_read8(bc());
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  /* nop */
  /* nop */
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  lab_p03_L_4FB5: ;
  /* nop */
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x00;
  cpu_ex_af();
  set_hl(mem_read16(0x2A1C));
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  c = 0x04;
  /* nop */
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* nop */
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  c = 0x00;
  /* nop */
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  a = mem_read8(bc());
  c = 0x02;
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x08;
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x08;
  c = 0x0A;
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x02;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x0A;
  c = 0x0A;
  p03_L_503A();
  return;
}

/* flash page 3 cpu 0x503A (offset 0x103A) */
void p03_L_503A(void) {
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x0A;
  c = 0x02;
  c = (uint8_t)(c + 1);
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  c = 0x00;
  c = 0x00;
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x00;
  e = (uint8_t)(e + 1);
  mem_write8(bc(), a);
  a = mem_read8(de());
  set_hl(mem_read16(0x001C));
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x0A;
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x08;
  cpu_ex_af();
  cpu_ex_af();
  b = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x08;
  c = (uint8_t)(c + 1);
  cpu_ex_af();
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x08;
  c = (uint8_t)(c + 1);
  cpu_ex_af();
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x08;
  a = mem_read8(bc());
  a = mem_read8(bc());
  b = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x0A;
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  a = mem_read8(bc());
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  c = 0x0E;
  a = mem_read8(bc());
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x0A;
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  cpu_ex_af();
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x0A;
  a = mem_read8(bc());
  c = 0x06;
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x08;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x0A;
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x02;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x0A;
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  b = 0x02;
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  c = 0x00;
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  b = 0x0A;
  a = mem_read8(bc());
  b = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  b = 0x08;
  cpu_ex_af();
  b = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  mem_write8(bc(), a);
  b = 0x0A;
  a = mem_read8(bc());
  b = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  b = 0x00;
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  b = 0x04;
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x0A;
  b = 0x02;
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  cpu_ex_af();
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  b = 0x02;
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  /* nop */
  b = 0x00;
  /* nop */
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(mem_read16(0x222A));
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  b = 0x0A;
  b = 0x02;
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  cpu_ex_af();
  cpu_ex_af();
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* nop */
  b = 0x04;
  mem_write8(bc(), a);
  b = 0x00;
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  b = (uint8_t)(b + 1);
  b = 0x04;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x00;
  /* nop */
  mem_write16(0x2A2A, hl());
  d = (uint8_t)(d + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  e = 0x04;
  cpu_ex_af();
  e = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x04;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  b = 0x00;
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  a = mem_read8(bc());
  d = (uint8_t)(d + 1);
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x00;
  c = 0x00;
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x0A;
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x00;
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  mem_write8(bc(), a);
  b = 0x02;
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  a = mem_read8(bc());
  c = 0x02;
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x08;
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x08;
  c = 0x0A;
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x02;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x0A;
  c = 0x0A;
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x0A;
  c = 0x02;
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  mem_write8(de(), a);
  e = 0x12;
  /* nop */
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_52D7;
  c = (uint8_t)(c + 1);
  mem_write8(de(), a);
  e = 0x12;
  /* nop */
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  mem_write8(de(), a);
  lab_p03_L_52D7: ;
  c = (uint8_t)(c + 1);
  mem_write8(de(), a);
  e = 0x12;
  /* nop */
  b = (uint8_t)(b - 1);
  mem_write8(de(), a);
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(de(), a);
  e = 0x12;
  /* nop */
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  /* nop */
  c = (uint8_t)(c + 1);
  d = (uint8_t)(d + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_52F7;
  /* nop */
  c = (uint8_t)(c + 1);
  d = (uint8_t)(d + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  d = (uint8_t)(d + 1);
  lab_p03_L_52F7: ;
  /* nop */
  c = (uint8_t)(c + 1);
  d = (uint8_t)(d + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  d = (uint8_t)(d + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  d = (uint8_t)(d + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_5315;
  cpu_ex_af();
  c = (uint8_t)(c + 1);
  cpu_ex_af();
  c = 0x00;
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_5329;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_532F;
  /* nop */
  b = (uint8_t)(b + 1);
  lab_p03_L_5315: ;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x0C;
  c = 0x00;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x08;
  p03_L_5320();
  return;
  lab_p03_L_5329: ;
  c = (uint8_t)(c + 1);
  b = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  lab_p03_L_532F: ;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  b = 0x00;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  b = 0x00;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  b = 0x00;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = 0x04;
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  c = 0x04;
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x04;
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x04;
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = 0x04;
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  mem_write16(0x1C22, hl());
  /* nop */
  b = 0x10;
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  mem_write16(0x1C22, hl());
  /* nop */
  b = 0x08;
  d = (uint8_t)(d + 1);
  e = (uint8_t)(e + 1);
  mem_write16(0x1C22, hl());
  /* nop */
  b = 0x14;
  /* nop */
  e = (uint8_t)(e + 1);
  mem_write16(0x1C22, hl());
  /* nop */
  b = 0x04;
  cpu_ex_af();
  /* nop */
  e = (uint8_t)(e + 1);
  mem_write16(0x001C, hl());
  b = 0x10;
  cpu_ex_af();
  /* nop */
  e = (uint8_t)(e + 1);
  mem_write16(0x001C, hl());
  b = 0x08;
  d = (uint8_t)(d + 1);
  /* nop */
  e = (uint8_t)(e + 1);
  mem_write16(0x001C, hl());
  b = 0x00;
  d = (uint8_t)(d + 1);
  /* nop */
  e = (uint8_t)(e + 1);
  mem_write16(0x001C, hl());
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x00;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x00;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x00;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x00;
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  /* nop */
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b - 1);
  p03_L_53ED();
  return;
}

/* flash page 3 cpu 0x5320 (offset 0x1320) */
void p03_L_5320(void) {
  c = (uint8_t)(c + 1);
  cpu_ex_af();
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  b = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  b = 0x00;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  b = 0x00;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  b = 0x00;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = 0x04;
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  c = 0x04;
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x04;
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x04;
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  c = 0x00;
  b = 0x04;
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  mem_write16(0x1C22, hl());
  /* nop */
  b = 0x10;
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  mem_write16(0x1C22, hl());
  /* nop */
  b = 0x08;
  d = (uint8_t)(d + 1);
  e = (uint8_t)(e + 1);
  mem_write16(0x1C22, hl());
  /* nop */
  b = 0x14;
  /* nop */
  e = (uint8_t)(e + 1);
  mem_write16(0x1C22, hl());
  /* nop */
  b = 0x04;
  cpu_ex_af();
  /* nop */
  e = (uint8_t)(e + 1);
  mem_write16(0x001C, hl());
  b = 0x10;
  cpu_ex_af();
  /* nop */
  e = (uint8_t)(e + 1);
  mem_write16(0x001C, hl());
  b = 0x08;
  d = (uint8_t)(d + 1);
  /* nop */
  e = (uint8_t)(e + 1);
  mem_write16(0x001C, hl());
  b = 0x00;
  d = (uint8_t)(d + 1);
  /* nop */
  e = (uint8_t)(e + 1);
  mem_write16(0x001C, hl());
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x00;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x00;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x00;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x00;
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  /* nop */
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b - 1);
  p03_L_53ED();
  return;
}

/* flash page 3 cpu 0x53ED (offset 0x13ED) */
void p03_L_53ED(void) {
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_53F7;
  /* nop */
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  d = (uint8_t)(d + 1);
  lab_p03_L_53F7: ;
  /* nop */
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  d = (uint8_t)(d + 1);
  /* nop */
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x08;
  cpu_ex_af();
  b = 0x0C;
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  b = 0x08;
  b = 0x0C;
  /* nop */
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  d = (uint8_t)(d + 1);
  mem_write8(de(), a);
  a = mem_read8(de());
  d = 0x12;
  /* nop */
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  d = (uint8_t)(d + 1);
  /* nop */
  e = (uint8_t)(e + 1);
  mem_write8(de(), a);
  mem_write8(de(), a);
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = 0x00;
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  a = mem_read8(bc());
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  mem_write8(bc(), a);
  a = mem_read8(bc());
  d = (uint8_t)(d + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x00;
  /* nop */
  cpu_ex_af();
  d = (uint8_t)(d + 1);
  mem_write16(0x003E, hl());
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x08;
  c = 0x08;
  b = 0x00;
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  b = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = 0x00;
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  e = 0x10;
  /* nop */
  b = 0x00;
  /* nop */
  a = 0x14;
  d = (uint8_t)(d + 1);
  d = (uint8_t)(d + 1);
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_54A4;
  lab_p03_L_54A4: ;
  b = (uint8_t)(b - 1);
  /* nop */
  e = 0x08;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  e = 0x00;
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x14;
  d = (uint8_t)(d + 1);
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  e = (uint8_t)(e + 1);
  cpu_ex_af();
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  /* nop */
  b = 0x00;
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  set_hl(mem_read16(0x081C));
  /* nop */
  b = 0x00;
  e = (uint8_t)(e + 1);
  mem_write16(0x1422, hl());
  mem_write8(hl(), 0x00);
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x00;
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x00;
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  /* nop */
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_rlca();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  mem_write8(bc(), a);
  b = 0x0E;
  b = 0x02;
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* nop */
  b = 0x06;
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_ex_af();
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* nop */
  /* nop */
  b = 0x00;
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = 0x00;
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x04;
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  /* nop */
  cpu_ex_af();
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x08;
  c = 0x08;
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  b = 0x00;
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_rlca();
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  b = 0x05;
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  b = 0x04;
  b = 0x04;
  b = 0x00;
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  mem_write8(bc(), a);
  cpu_rlca();
  cpu_rlca();
  cpu_rlca();
  mem_write8(bc(), a);
  /* nop */
  b = 0x20;
  if (flag_nz()) goto lab_p03_L_55A1;
  h = (uint8_t)(h + 1);
  if (flag_z()) goto lab_p03_L_55A3;
  /* ccf */
  b = (uint8_t)(b - 1);
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  cpu_ex_af();
  /* nop */
  /* nop */
  cpu_rra();
  b = 0x20;
  if (flag_nz()) goto lab_p03_L_55B3;
  h = (uint8_t)(h + 1);
  if (flag_z()) goto lab_p03_L_55C3;
  /* ccf */
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x0000);
  /* nop */
  cpu_rra();
  b = 0x0F;
  set_hl((uint16_t)(hl() + hl()));
  set_hl((uint16_t)(hl() + sp));
  set_hl((uint16_t)(hl() + hl()));
  lab_p03_L_55A1: ;
  cpu_rrca();
  /* nop */
  lab_p03_L_55A3: ;
  /* ccf */
  b = (uint8_t)(b - 1);
  goto lab_p03_L_55B0;
  lab_p03_L_55B0: ;
  a = mem_read8(bc());
  a = mem_read8(0x3F2A);
  lab_p03_L_55B3: ;
  /* ccf */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_55D5;
  cpu_rla();
  d = (uint8_t)(d - 1);
  cpu_rra();
  b = 0x0E;
  set_hl(mem_read16(0x2A3B));
  c = 0x00;
  lab_p03_L_55C3: ;
  /* ccf */
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_55DD;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_55CA;
  lab_p03_L_55CA: ;
  /* nop */
  cpu_rra();
  b = 0x20;
  if (flag_nz()) goto lab_p03_L_55F1;
  h = 0x28;
  if (flag_nz()) goto lab_p03_L_5613;
  b = (uint8_t)(b - 1);
  lab_p03_L_55D5: ;
  b = 0x08;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_55D9;
  lab_p03_L_55D9: ;
  /* nop */
  /* nop */
  cpu_rra();
  mem_write8(bc(), a);
  lab_p03_L_55DD: ;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  lab_p03_L_55F1: ;
  /* nop */
  /* nop */
  /* nop */
  b = 0x00;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  b = 0x00;
  e = (uint8_t)(e + 1);
  if (flag_z()) goto lab_p03_L_5625;
  a = mem_read8(bc());
  a = (uint8_t)(a + 1);
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b + 1);
  c = 0x1F;
  c = 0x00;
  lab_p03_L_5613: ;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(de(), a);
  d = (uint8_t)(d + 1);
  mem_write8(de(), a);
  d = (uint8_t)(d + 1);
  /* nop */
  set_bc(0x0000);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc(0x0000);
  lab_p03_L_5625: ;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc(0x0000);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc(0x0000);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc(0x0000);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc(0x0000);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc(0x0000);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc(0x0000);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc(0x0000);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc(0x0000);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  set_bc(0x0000);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p03_L_5674();
  return;
}

/* flash page 3 cpu 0x5674 (offset 0x1674) */
void p03_L_5674(void) {
  set_hl(0x569D);
  p00_L_07CC();
  p00_L_36DB();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  p03_L_5681();
  return;
}

/* flash page 3 cpu 0x5681 (offset 0x1681) */
void p03_L_5681(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  p00_L_3D17();
  p00_L_3E07();
  goto lab_p03_L_568D;
  lab_p03_L_568D: ;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  return;
}

/* flash page 3 cpu 0x56D4 (offset 0x16D4) */
void p03_L_56D4(void) {
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  p00_L_17FA();
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p03_L_56F0;
  p00_L_3F5D();
  p00_L_0753();
  a = 0x53;
  mem_write8(0x859A, a);
  lab_p03_L_56F0: ;
  set_hl(0x5814);
  p00_L_07CC();
  set_hl(0x58AB);
  mem_write16(0x9700, hl());
  p03_L_43DD();
  a = 0x07;
  p00_L_36E7();
  p00_L_35F1();
  p03_L_45CC();
  return;
}

/* flash page 3 cpu 0x570B (offset 0x170B) */
void p03_L_570B(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p03_L_571C;
  p00_L_3F5D();
  p00_L_0753();
  a = 0x48;
  mem_write8(0x859A, a);
  lab_p03_L_571C: ;
  p00_L_176F();
  set_hl(0x5814);
  p00_L_07CC();
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_5732;
  a = 0x04;
  p00_L_362D();
  if (flag_nz()) goto lab_p03_L_574A;
  lab_p03_L_5732: ;
  set_hl(0x595D);
  a = 0x11;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  set_de(0x848E);
  p00_L_1185();
  p00_L_1185();
  p03_L_43BE();
  lab_p03_L_574A: ;
  p03_L_5751();
  p03_L_45CC();
  return;
}

/* flash page 3 cpu 0x5751 (offset 0x1751) */
void p03_L_5751(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_575E;
  a = 0x07;
  p00_L_362D();
  if (flag_nz()) { p03_L_5779(); return; }
  lab_p03_L_575E: ;
  set_hl(0x5836);
  p00_L_0013();
  if (flag_nz()) { p03_L_5779(); return; }
  set_hl(0x584E);
  p00_L_0198();
  if (flag_nz()) { p03_L_5779(); return; }
  set_hl(0x588D);
  p00_L_01A2();
  if (flag_nz()) { p03_L_5779(); return; }
  set_hl(0x586C);
  p03_L_5779();
  return;
}

/* flash page 3 cpu 0x5779 (offset 0x1779) */
void p03_L_5779(void) {
  mem_write16(0x9700, hl());
  p03_L_43DD();
  return;
}

/* flash page 3 cpu 0x5780 (offset 0x1780) */
void p03_L_5780(void) {
  set_hl(0x5814);
  p00_L_07CC();
  p00_L_176F();
  set_hl(0x5970);
  a = 0x12;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  set_de(0x848E);
  p00_L_1185();
  p00_L_1185();
  p03_L_43BE();
  set_hl(0x5824);
  p03_L_5779();
  p03_L_45CC();
  return;
}

/* flash page 3 cpu 0x57AB (offset 0x17AB) */
void p03_L_57AB(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) { p00_L_35F7(); return; }
  p03_L_57E3();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  set_hl(0x5964);
  a = 0x13;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  set_de(0x848E);
  p00_L_1185();
  p00_L_1185();
  p03_L_43BE();
  set_hl(0x582D);
  p03_L_5779();
  a = 0x03;
  p00_L_35FD();
  p00_L_3603();
  p03_L_45CC();
  return;
}

/* flash page 3 cpu 0x57E3 (offset 0x17E3) */
void p03_L_57E3(void) {
  set_hl(0x5814);
  p00_L_07CC();
  return;
}

/* flash page 3 cpu 0x57EA (offset 0x17EA) */
void p03_L_57EA(void) {
  p03_L_57E3();
  p03_L_45C1();
  return;
}

/* flash page 3 cpu 0x57F1 (offset 0x17F1) */
void p03_L_57F1(void) {
  p03_L_57E3();
  p03_L_45BA();
  return;
}

/* flash page 3 cpu 0x57F8 (offset 0x17F8) */
void p03_L_57F8(void) {
  ix = 0x586C;
  /* ld (0x9700),ix */
  return;
}

/* flash page 3 cpu 0x5801 (offset 0x1801) */
void p03_L_5801(void) {
  set_hl(0x58C3);
  mem_write16(0x9700, hl());
  return;
}

/* flash page 3 cpu 0x5808 (offset 0x1808) */
void p03_L_5808(void) {
  cpu_push16(ix);
  ix = 0x586C;
  p03_L_44F5();
  ix = cpu_pop16();
  return;
}

/* flash page 3 cpu 0x5836 (offset 0x1836) */
void p03_ascii_map(void) {
  a = mem_read8(bc());
  /* nop */
  e = c;
  set_bc((uint16_t)(bc() - 1));
  /* ei */
  e = b;
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  e = c;
  c = (uint8_t)(c + 1);
  cpu_rrca();
  e = c;
  c = (uint8_t)(c - 1);
  a = mem_read8(bc());
  e = c;
  set_bc((uint16_t)(bc() + 1));
  d = (uint8_t)(d + 1);
  e = c;
  mem_write8(hl(), 0x19);
  e = c;
  p00_rst38_isr();
  /* nop */
  /* nop */
  p03_ascii_map_2();
  return;
}

/* flash page 3 cpu 0x584E (offset 0x184E) */
void p03_ascii_map_2(void) {
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_5873;
  e = c;
  set_de(0x591E);
  set_hl((uint16_t)(hl() + 1));
  if (flag_z()) goto lab_p03_L_58B0;
  a = mem_read8(bc());
  /* nop */
  e = c;
  set_bc((uint16_t)(bc() - 1));
  /* ei */
  e = b;
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  e = c;
  c = (uint8_t)(c + 1);
  cpu_rrca();
  e = c;
  c = (uint8_t)(c - 1);
  a = mem_read8(bc());
  e = c;
  set_bc((uint16_t)(bc() + 1));
  d = (uint8_t)(d + 1);
  e = c;
  p00_rst38_isr();
  /* nop */
  /* nop */
  cpu_rra();
  if (flag_p()) return;
  e = b;
  e = (uint8_t)(e - 1);
  e = b;
  e = c;
  set_de((uint16_t)(de() - 1));
  lab_p03_L_5873: ;
  b = l;
  e = c;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  c = a;
  e = c;
  a = mem_read8(bc());
  /* nop */
  e = c;
  set_bc((uint16_t)(bc() - 1));
  /* ei */
  e = b;
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  e = c;
  c = (uint8_t)(c + 1);
  cpu_rrca();
  e = c;
  c = (uint8_t)(c - 1);
  a = mem_read8(bc());
  e = c;
  set_bc((uint16_t)(bc() + 1));
  d = (uint8_t)(d + 1);
  e = c;
  p00_rst38_isr();
  /* nop */
  /* nop */
  c = 0xD6;
  h = 0x0F;
  cpu_pop_de();
  h = 0x22;
  cpu_push_af();
  e = b;
  a = mem_read8(bc());
  /* nop */
  e = c;
  set_bc((uint16_t)(bc() - 1));
  /* ei */
  e = b;
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  e = c;
  c = (uint8_t)(c + 1);
  cpu_rrca();
  e = c;
  c = (uint8_t)(c - 1);
  a = mem_read8(bc());
  e = c;
  set_bc((uint16_t)(bc() + 1));
  d = (uint8_t)(d + 1);
  e = c;
  p00_rst38_isr();
  /* nop */
  /* nop */
  set_hl((uint16_t)(hl() - 1));
  l = 0x59;
  l = (uint8_t)(l + 1);
  if (flag_nc()) goto lab_p03_L_590A;
  lab_p03_L_58B0: ;
  e = c;
  l = (uint8_t)(l - 1);
  sp = (uint16_t)(sp + 1);
  e = c;
  l = 0x36;
  e = c;
  a = a ^ 0xFF;
  a = mem_read8(0x3059);
  a = (uint8_t)(a - 1);
  e = c;
  sp = 0x5941;
  p00_rst38_isr();
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  if (flag_p()) return;
  e = b;
  b = (uint8_t)(b + 1);
  if (flag_p()) return;
  e = b;
  b = (uint8_t)(b - 1);
  if (flag_p()) return;
  e = b;
  b = (uint8_t)(b - 1);
  if (flag_p()) return;
  e = b;
  mem_write8(0x58F0, a);
  mem_write8(0x58F0, a);
  p00_rst38_isr();
  e = b;
  b = mem_read8(hl());
  h = c;
  h = e;
  mem_write8(hl(), h);
  /* nop */
  e = c;
  b = mem_read8(hl());
  h = c;
  h = e;
  mem_write8(hl(), h);
  /* nop */
  d = h;
  h = d;
  l = h;
  d = e;
  mem_write8(hl(), h);
  h = c;
  mem_write8(hl(), d);
  mem_write8(hl(), h);
  /* nop */
  cpu_cp_hl();
  d = h;
  h = d;
  l = h;
  /* nop */
  set_bc(0x694D);
  l = mem_read8(hl());
  /* nop */
  d = h;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  h = l;
  mem_write8(hl(), b);
  /* nop */
  e = b;
  l = l;
  h = c;
  a = b;
  /* nop */
  e = b;
  l = l;
  l = c;
  l = mem_read8(hl());
  /* nop */
  e = b;
  mem_write8(hl(), e);
  h = e;
  l = h;
  /* nop */
  lab_p03_L_590A: ;
  e = c;
  l = l;
  h = c;
  a = b;
  /* nop */
  e = c;
  l = l;
  l = c;
  l = mem_read8(hl());
  /* nop */
  e = c;
  mem_write8(hl(), e);
  h = e;
  l = h;
  /* nop */
  e = b;
  mem_write8(hl(), d);
  h = l;
  mem_write8(hl(), e);
  /* nop */
  p03_str_4();
  return;
}

/* flash page 3 cpu 0x591E (offset 0x191E) */
void p03_str_4(void) {
  e = e;
  l = l;
  h = c;
  a = b;
  /* nop */
  e = e;
  l = l;
  l = c;
  l = mem_read8(hl());
  /* nop */
  e = e;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  h = l;
  mem_write8(hl(), b);
  /* nop */
  /* db 0xDD */
  /* nop */
  c = c;
  h = (uint8_t)(h - 1);
  /* nop */
  d = b;
  d = mem_read8(hl());
  /* nop */
  d = b;
  c = l;
  d = h;
  /* nop */
  b = mem_read8(hl());
  d = mem_read8(hl());
  /* nop */
  d = b;
  a = a ^ 0xFF;
  e = c;
  /* nop */
  b = e;
  a = a ^ 0xFF;
  e = c;
  /* nop */
  d = b;
  l = h;
  l = a;
  mem_write8(hl(), h);
  d = e;
  mem_write8(hl(), h);
  h = c;
  mem_write8(hl(), d);
  mem_write8(hl(), h);
  /* nop */
  d = b;
  l = h;
  l = a;
  mem_write8(hl(), h);
  d = e;
  mem_write8(hl(), h);
  h = l;
  mem_write8(hl(), b);
  /* nop */
  set_bc(0x614D);
  a = b;
  /* nop */
  p03_str_1();
  return;
}

/* flash page 3 cpu 0x595D (offset 0x195D) */
void p03_str_1(void) {
  d = a;
  c = c;
  c = mem_read8(hl());
  b = h;
  c = a;
  d = a;
  /* nop */
  p03_str_3();
  return;
}

/* flash page 3 cpu 0x5964 (offset 0x1964) */
void p03_str_3(void) {
  d = h;
  b = c;
  b = d;
  c = h;
  b = l;
  if (flag_nz()) goto lab_p03_L_59BE;
  b = l;
  d = h;
  d = l;
  d = b;
  /* nop */
  p03_str_2();
  return;
  lab_p03_L_59BE: ;
  /* daa */
  mem_write8(0x8487, a);
  a = h;
  p00_L_12B1();
  set_de(0x4096);
  p03_L_59FA();
  a = h;
  a = a & 0x0F;
  flag_logic(a);
  set_de(0x0256);
  p03_L_59FA();
  a = l;
  p00_L_12B1();
  set_de(0x0016);
  p03_L_59FA();
  set_hl(0x8484);
  mem_write8(hl(), 0x85);
  lab_p03_L_59E4: ;
  a = mem_read8(0x8485);
  flag_cmp(a, 0x10);
  if (flag_nc()) return;
  set_hl(0x8487);
  a = 0;
  flag_logic(a);
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  goto lab_p03_L_59E4;
}

/* flash page 3 cpu 0x5970 (offset 0x1970) */
void p03_str_2(void) {
  e = d;
  c = a;
  c = a;
  c = l;
  if (flag_nz()) goto lab_p03_L_59BC;
  b = c;
  b = e;
  d = h;
  c = a;
  d = d;
  d = e;
  /* nop */
  p03_L_597D();
  return;
  lab_p03_L_59BC: ;
  a = (uint8_t)(a + 0x00);
  /* daa */
  mem_write8(0x8487, a);
  a = h;
  p00_L_12B1();
  set_de(0x4096);
  p03_L_59FA();
  a = h;
  a = a & 0x0F;
  flag_logic(a);
  set_de(0x0256);
  p03_L_59FA();
  a = l;
  p00_L_12B1();
  set_de(0x0016);
  p03_L_59FA();
  set_hl(0x8484);
  mem_write8(hl(), 0x85);
  lab_p03_L_59E4: ;
  a = mem_read8(0x8485);
  flag_cmp(a, 0x10);
  if (flag_nc()) return;
  set_hl(0x8487);
  a = 0;
  flag_logic(a);
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  goto lab_p03_L_59E4;
}

/* flash page 3 cpu 0x597D (offset 0x197D) */
void p03_L_597D(void) {
  cpu_push_af();
  p00_L_12B1();
  b = a;
  cpu_pop_af();
  a = a & 0x0F;
  flag_logic(a);
  b = (uint8_t)(b + 1);
  a = (uint8_t)(a + 0x00);
  /* daa */
  goto lab_p03_L_598E;
  lab_p03_L_598B: ;
  a = (uint8_t)(a + 0x16);
  /* daa */
  lab_p03_L_598E: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_598B;
  return;
}

/* flash page 3 cpu 0x5991 (offset 0x1991) */
void p03_L_5991(void) {
  set_hl(0x8478);
  goto lab_p03_L_5999;
  lab_p03_L_5999: ;
  cpu_push_hl();
  cpu_push_af();
  p00_L_128D();
  cpu_pop_af();
  p03_L_597D();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, 0x10);
  if (flag_nc()) goto lab_p03_L_59AD;
  p00_L_12B9();
  goto lab_p03_L_59AE;
  lab_p03_L_59AD: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p03_L_59AE: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  return;
}

/* flash page 3 cpu 0x5996 (offset 0x1996) */
void p03_L_5996(void) {
  set_hl(0x8483);
  cpu_push_hl();
  cpu_push_af();
  p00_L_128D();
  cpu_pop_af();
  p03_L_597D();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, 0x10);
  if (flag_nc()) goto lab_p03_L_59AD;
  p00_L_12B9();
  goto lab_p03_L_59AE;
  lab_p03_L_59AD: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p03_L_59AE: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  return;
}

/* flash page 3 cpu 0x59B1 (offset 0x19B1) */
void p03_L_59B1(void) {
  cpu_push_hl();
  p00_L_1287();
  cpu_pop_hl();
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) return;
  a = l;
  a = a & 0x0F;
  flag_logic(a);
  a = (uint8_t)(a + 0x00);
  /* daa */
  mem_write8(0x8487, a);
  a = h;
  p00_L_12B1();
  set_de(0x4096);
  p03_L_59FA();
  a = h;
  a = a & 0x0F;
  flag_logic(a);
  set_de(0x0256);
  p03_L_59FA();
  a = l;
  p00_L_12B1();
  set_de(0x0016);
  p03_L_59FA();
  set_hl(0x8484);
  mem_write8(hl(), 0x85);
  lab_p03_L_59E4: ;
  a = mem_read8(0x8485);
  flag_cmp(a, 0x10);
  if (flag_nc()) return;
  set_hl(0x8487);
  a = 0;
  flag_logic(a);
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  goto lab_p03_L_59E4;
}

/* flash page 3 cpu 0x59FA (offset 0x19FA) */
void p03_L_59FA(void) {
  if (flag_z()) return;
  cpu_push_hl();
  b = a;
  lab_p03_L_59FD: ;
  set_hl(0x8487);
  a = mem_read8(hl());
  a = (uint8_t)(a + e);
  /* daa */
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  /* adc a,d */
  /* daa */
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  /* adc a,0x00 */
  /* daa */
  mem_write8(hl(), a);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_59FD;
  cpu_pop_hl();
  return;
}

/* flash page 3 cpu 0x5A13 (offset 0x1A13) */
void p03_L_5A13(void) {
  p00_L_2182();
  p00_L_2187();
  set_de(0x84A4);
  set_hl(0x84AF);
  p00_L_347D();
  return;
}

/* flash page 3 cpu 0x5A23 (offset 0x1A23) */
void p03_L_5A23(void) {
  cpu_push_af();
  /* scf */
  goto lab_p03_L_5A49;
  lab_p03_L_5A49: ;
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_3483();
  if (flag_z()) goto lab_p03_L_5A57;
  cpu_pop_af();
  return;
  lab_p03_L_5A57: ;
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  cpu_push_af();
  c = 0x01;
  cpu_push_bc();
  ix = 0x0000;
  cpu_add_ix_sp();
  a = 0x0A;
  cpu_push_af();
  set_de(0xFFE5);
  p00_L_3489();
  if (flag_nz()) { p03_L_5C20(); return; }
  set_de(0xFFF7);
  p00_L_3489();
  if (flag_nz()) goto lab_p03_L_5C10;
  p03_L_5C38();
  if (flag_z()) goto lab_p03_L_5A96;
  p00_L_22CF();
  set_de(0x8478);
  p00_L_348F();
  mem_write8(0x9188, a);
  p00_L_2315();
  set_de(0x8478);
  p00_L_348F();
  mem_write8(0x9189, a);
  lab_p03_L_5A96: ;
  p03_L_5A27();
  mem_write16(0x918A, hl());
  p03_L_5A9C();
  return;
  lab_p03_L_5C10: ;
  p00_L_21A4();
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_af();
  a = 0x01;
  if (flag_nc()) goto lab_p03_L_5C1B;
  a = (uint8_t)(a - 1);
  lab_p03_L_5C1B: ;
  p00_L_349B();
  goto lab_p03_L_5C33;
  lab_p03_L_5C33: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 3 cpu 0x5A27 (offset 0x1A27) */
void p03_L_5A27(void) {
  set_hl(mem_read16(0x9824));
  set_de(0xFFE5);
  set_hl((uint16_t)(hl() + de()));
  set_de(0xFFF7);
  p03_L_7084();
  cpu_push_af();
  p03_L_707D();
  cpu_pop_hl();
  l = a;
  return;
}

/* flash page 3 cpu 0x5A3B (offset 0x1A3B) */
void p03_L_5A3B(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p03_L_5A41;
  lab_p03_L_5A41: ;
  p00_L_221D();
  p00_L_222C();
  p03_L_5A47();
  return;
}

/* flash page 3 cpu 0x5A47 (offset 0x1A47) */
void p03_L_5A47(void) {
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_3483();
  if (flag_z()) goto lab_p03_L_5A57;
  cpu_pop_af();
  return;
  lab_p03_L_5A57: ;
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  cpu_push_af();
  c = 0x01;
  cpu_push_bc();
  ix = 0x0000;
  cpu_add_ix_sp();
  a = 0x0A;
  cpu_push_af();
  set_de(0xFFE5);
  p00_L_3489();
  if (flag_nz()) { p03_L_5C20(); return; }
  set_de(0xFFF7);
  p00_L_3489();
  if (flag_nz()) goto lab_p03_L_5C10;
  p03_L_5C38();
  if (flag_z()) goto lab_p03_L_5A96;
  p00_L_22CF();
  set_de(0x8478);
  p00_L_348F();
  mem_write8(0x9188, a);
  p00_L_2315();
  set_de(0x8478);
  p00_L_348F();
  mem_write8(0x9189, a);
  lab_p03_L_5A96: ;
  p03_L_5A27();
  mem_write16(0x918A, hl());
  p03_L_5A9C();
  return;
  lab_p03_L_5C10: ;
  p00_L_21A4();
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_af();
  a = 0x01;
  if (flag_nc()) goto lab_p03_L_5C1B;
  a = (uint8_t)(a - 1);
  lab_p03_L_5C1B: ;
  p00_L_349B();
  goto lab_p03_L_5C33;
  lab_p03_L_5C33: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 3 cpu 0x5A7A (offset 0x1A7A) */
void p03_L_5A7A(void) {
  if (flag_c()) goto lab_p03_L_5AD8;
  if (flag_z()) goto lab_p03_L_5A96;
  p00_L_22CF();
  set_de(0x8478);
  p00_L_348F();
  mem_write8(0x9188, a);
  p00_L_2315();
  set_de(0x8478);
  p00_L_348F();
  mem_write8(0x9189, a);
  lab_p03_L_5A96: ;
  p03_L_5A27();
  mem_write16(0x918A, hl());
  p03_L_5A9C();
  return;
  lab_p03_L_5AD8: ;
  mem_write16(0x84DF, hl());
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84DD, hl());
  /* bit 0,(ix) */
  if (flag_z()) goto lab_p03_L_5B24;
  /* res 0,(ix) */
  p00_L_2315();
  p00_L_22C7();
  b = 0x0C;
  p03_L_5D0A();
  p00_L_0C2D();
  p00_L_14C7();
  if (flag_nz()) goto lab_p03_L_5B05;
  lab_p03_L_5AFF: ;
  /* set 2,(ix) */
  goto lab_p03_L_5B24;
  lab_p03_L_5B05: ;
  p00_L_1171();
  p00_L_22FC();
  p00_L_231F();
  b = 0x03;
  p03_L_5D0A();
  p00_L_0C2D();
  p00_L_14C7();
  if (flag_z()) goto lab_p03_L_5AFF;
  p00_L_1108();
  p00_L_0ED0();
  p00_L_1169();
  lab_p03_L_5B24: ;
  cpu_pop_hl();
  /* bit 1,(ix) */
  if (flag_nz()) goto lab_p03_L_5B33;
  a = 0;
  flag_logic(a);
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p03_L_5B44;
  /* set 1,(ix) */
  lab_p03_L_5B33: ;
  cpu_push_hl();
  set_hl(mem_read16(0x9824));
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84DF, hl());
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84DD, hl());
  cpu_pop_hl();
  h = l;
  lab_p03_L_5B44: ;
  flag_set_z((h & (1u << 0)) == 0);
  if (flag_z()) goto lab_p03_L_5B5D;
  set_hl(0x8F74);
  lab_p03_L_5B4B: ;
  mem_write16(0x84DF, hl());
  /* bit 2,(ix) */
  if (flag_nz()) goto lab_p03_L_5B8A;
  /* scf */
  p03_L_5C71();
  set_de(0x8478);
  goto lab_p03_L_5B8E;
  lab_p03_L_5B5D: ;
  flag_set_z((h & (1u << 1)) == 0);
  if (flag_z()) goto lab_p03_L_5B66;
  set_hl(0x8F6B);
  goto lab_p03_L_5B4B;
  lab_p03_L_5B66: ;
  flag_set_z((h & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_5B6F;
  set_de(0x8F59);
  goto lab_p03_L_5B76;
  lab_p03_L_5B6F: ;
  flag_set_z((h & (1u << 3)) == 0);
  if (flag_z()) goto lab_p03_L_5B8A;
  set_de(0x8F50);
  lab_p03_L_5B76: ;
  /* bit 2,(ix) */
  if (flag_nz()) goto lab_p03_L_5B8E;
  cpu_ex_de_hl();
  mem_write16(0x84DD, hl());
  a = a | a;
  flag_logic(a);
  p03_L_5C71();
  set_hl(0x8478);
  mem_write16(0x84DF, hl());
  lab_p03_L_5B8A: ;
  set_de(mem_read16(0x84DD));
  lab_p03_L_5B8E: ;
  /* bit 1,(ix) */
  if (flag_nz()) goto lab_p03_L_5BA5;
  p00_L_238C();
  set_de(mem_read16(0x84DF));
  p00_L_2378();
  /* set 3,(ix) */
  p03_L_5A9C();
  return;
  lab_p03_L_5BA5: ;
  p00_L_235F();
  set_de(mem_read16(0x84DF));
  p00_L_2340();
  p03_L_5A9C();
  return;
}

/* flash page 3 cpu 0x5A9C (offset 0x1A9C) */
void p03_L_5A9C(void) {
  lab_p03_L_5A9C: ;
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  cpu_push_af();
  if (flag_z()) { p03_L_5D38(); return; }
  p03_L_5A27();
  a = a & h;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_5ACB;
  flag_cmp(a, 0x04);
  if (flag_nc()) goto lab_p03_L_5AC4;
  cpu_push_af();
  p03_L_5C38();
  if (flag_z()) goto lab_p03_L_5D37;
  a = mem_read8(0x9189);
  b = a;
  a = mem_read8(0x9188);
  cpu_pop_hl();
  flag_set_z((h & (1u << 0)) == 0);
  if (flag_z()) goto lab_p03_L_5AC7;
  e = 0x3F;
  lab_p03_L_5AC1: ;
  p03_L_5C4D();
  lab_p03_L_5AC4: ;
  p03_L_5D38();
  return;
  lab_p03_L_5AC7: ;
  e = 0x01;
  goto lab_p03_L_5AC1;
  lab_p03_L_5ACB: ;
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_5BB2;
  cpu_push_hl();
  set_hl(mem_read16(0x9824));
  set_de(0xFFE5);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84DF, hl());
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84DD, hl());
  /* bit 0,(ix) */
  if (flag_z()) goto lab_p03_L_5B24;
  /* res 0,(ix) */
  p00_L_2315();
  p00_L_22C7();
  b = 0x0C;
  p03_L_5D0A();
  p00_L_0C2D();
  p00_L_14C7();
  if (flag_nz()) goto lab_p03_L_5B05;
  lab_p03_L_5AFF: ;
  /* set 2,(ix) */
  goto lab_p03_L_5B24;
  lab_p03_L_5B05: ;
  p00_L_1171();
  p00_L_22FC();
  p00_L_231F();
  b = 0x03;
  p03_L_5D0A();
  p00_L_0C2D();
  p00_L_14C7();
  if (flag_z()) goto lab_p03_L_5AFF;
  p00_L_1108();
  p00_L_0ED0();
  p00_L_1169();
  lab_p03_L_5B24: ;
  cpu_pop_hl();
  /* bit 1,(ix) */
  if (flag_nz()) goto lab_p03_L_5B33;
  a = 0;
  flag_logic(a);
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p03_L_5B44;
  /* set 1,(ix) */
  lab_p03_L_5B33: ;
  cpu_push_hl();
  set_hl(mem_read16(0x9824));
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84DF, hl());
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84DD, hl());
  cpu_pop_hl();
  h = l;
  lab_p03_L_5B44: ;
  flag_set_z((h & (1u << 0)) == 0);
  if (flag_z()) goto lab_p03_L_5B5D;
  set_hl(0x8F74);
  lab_p03_L_5B4B: ;
  mem_write16(0x84DF, hl());
  /* bit 2,(ix) */
  if (flag_nz()) goto lab_p03_L_5B8A;
  /* scf */
  p03_L_5C71();
  set_de(0x8478);
  goto lab_p03_L_5B8E;
  lab_p03_L_5B5D: ;
  flag_set_z((h & (1u << 1)) == 0);
  if (flag_z()) goto lab_p03_L_5B66;
  set_hl(0x8F6B);
  goto lab_p03_L_5B4B;
  lab_p03_L_5B66: ;
  flag_set_z((h & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_5B6F;
  set_de(0x8F59);
  goto lab_p03_L_5B76;
  lab_p03_L_5B6F: ;
  flag_set_z((h & (1u << 3)) == 0);
  if (flag_z()) goto lab_p03_L_5B8A;
  set_de(0x8F50);
  lab_p03_L_5B76: ;
  /* bit 2,(ix) */
  if (flag_nz()) goto lab_p03_L_5B8E;
  cpu_ex_de_hl();
  mem_write16(0x84DD, hl());
  a = a | a;
  flag_logic(a);
  p03_L_5C71();
  set_hl(0x8478);
  mem_write16(0x84DF, hl());
  lab_p03_L_5B8A: ;
  set_de(mem_read16(0x84DD));
  lab_p03_L_5B8E: ;
  /* bit 1,(ix) */
  if (flag_nz()) goto lab_p03_L_5BA5;
  p00_L_238C();
  set_de(mem_read16(0x84DF));
  p00_L_2378();
  /* set 3,(ix) */
  goto lab_p03_L_5A9C;
  lab_p03_L_5BA5: ;
  p00_L_235F();
  set_de(mem_read16(0x84DF));
  p00_L_2340();
  goto lab_p03_L_5A9C;
  lab_p03_L_5BB2: ;
  p03_L_5A13();
  cpu_push_bc();
  p03_L_5A13();
  cpu_push_bc();
  p03_L_5C38();
  if (flag_z()) goto lab_p03_L_5BD7;
  a = mem_read8(0x9188);
  flag_cmp(a, b);
  if (flag_z()) goto lab_p03_L_5BD7;
  set_hl(mem_read16(0x918A));
  flag_set_z((h & (1u << 0)) == 0);
  if (flag_z()) goto lab_p03_L_5BD3;
  e = 0x3F;
  lab_p03_L_5BCE: ;
  p03_L_5C4D();
  goto lab_p03_L_5BD7;
  lab_p03_L_5BD3: ;
  e = 0x01;
  goto lab_p03_L_5BCE;
  lab_p03_L_5BD7: ;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_af();
  h = 0x01;
  if (flag_nc()) goto lab_p03_L_5BE1;
  h = (uint8_t)(h - 1);
  lab_p03_L_5BE1: ;
  cpu_push_de();
  p00_L_3495();
  cpu_pop_de();
  p03_L_5C38();
  if (flag_z()) goto lab_p03_L_5C33;
  a = mem_read8(0x9189);
  flag_cmp(a, d);
  if (flag_z()) goto lab_p03_L_5C33;
  b = a;
  a = d;
  set_hl(0x8DA6);
  cpu_cp_hl();
  if (flag_z()) goto lab_p03_L_5C33;
  set_hl(mem_read16(0x918A));
  flag_set_z((l & (1u << 0)) == 0);
  if (flag_z()) goto lab_p03_L_5C07;
  e = 0x3F;
  lab_p03_L_5C02: ;
  p03_L_5C4D();
  goto lab_p03_L_5C33;
  lab_p03_L_5C07: ;
  e = 0x01;
  goto lab_p03_L_5C02;
  lab_p03_L_5C33: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
  lab_p03_L_5D37: ;
  cpu_pop_af();
  p03_L_5D38();
  return;
}

/* flash page 3 cpu 0x5C20 (offset 0x1C20) */
void p03_L_5C20(void) {
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_af();
  a = 0x01;
  if (flag_nc()) goto lab_p03_L_5C28;
  a = (uint8_t)(a - 1);
  lab_p03_L_5C28: ;
  p00_L_349B();
  p00_L_21A4();
  goto lab_p03_L_5C33;
  lab_p03_L_5C33: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 3 cpu 0x5C30 (offset 0x1C30) */
void p03_L_5C30(void) {
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 3 cpu 0x5C38 (offset 0x1C38) */
void p03_L_5C38(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 5)) == 0);
  if (flag_z()) return;
  a = mem_read8(0x9775);
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p03_L_5C4B;
  flag_cmp(a, 0x04);
  if (flag_nc()) goto lab_p03_L_5C4B;
  a = a | 0x01;
  flag_logic(a);
  return;
  lab_p03_L_5C4B: ;
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 3 cpu 0x5C4D (offset 0x1C4D) */
void p03_L_5C4D(void) {
  cpu_push_bc();
  c = e;
  b = a;
  a = mem_read8(0x9775);
  flag_cmp(a, 0x02);
  a = e;
  if (flag_z()) goto lab_p03_L_5C5E;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p03_L_5C62;
  lab_p03_L_5C5C: ;
  cpu_pop_af();
  return;
  lab_p03_L_5C5E: ;
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p03_L_5C5C;
  lab_p03_L_5C62: ;
  cpu_pop_af();
  lab_p03_L_5C63: ;
  cpu_push_af();
  cpu_push_bc();
  d = 0x03;
  p00_L_34A1();
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  cpu_pop_af();
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p03_L_5C63;
  return;
}

/* flash page 3 cpu 0x5C71 (offset 0x1C71) */
void p03_L_5C71(void) {
  goto lab_p03_L_5C71;
  lab_p03_L_5C10: ;
  p00_L_21A4();
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_af();
  a = 0x01;
  if (flag_nc()) goto lab_p03_L_5C1B;
  a = (uint8_t)(a - 1);
  lab_p03_L_5C1B: ;
  p00_L_349B();
  goto lab_p03_L_5C33;
  lab_p03_L_5C33: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
  lab_p03_L_5C71: ;
  cpu_push_af();
  p00_rst20();
  set_hl(mem_read16(0x9824));
  set_de(0xFFDC);
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  set_hl(0x0009);
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p03_L_5C84;
  cpu_ex_de_hl();
  lab_p03_L_5C84: ;
  cpu_push_hl();
  set_bc(0x0012);
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_5CCB;
  p00_L_14C7();
  if (flag_z()) goto lab_p03_L_5CD2;
  cpu_push_de();
  cpu_push_hl();
  cpu_push_bc();
  p00_L_11F8();
  p00_L_14CC();
  if (flag_z()) goto lab_p03_L_5CC6;
  a = mem_read8(0x8484);
  d = a;
  a = mem_read8(0x8479);
  a = (uint8_t)(a + 0x0D);
  flag_cmp(a, d);
  cpu_pop_bc();
  if (flag_nc()) goto lab_p03_L_5CEF;
  a = (uint8_t)(a - b);
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_nc()) goto lab_p03_L_5CCB;
  cpu_pop_af();
  cpu_pop_hl();
  /* bit 3,(ix) */
  if (flag_nz()) { p03_L_5C20(); return; }
  /* bit 1,(ix) */
  if (flag_nz()) goto lab_p03_L_5C10;
  p03_L_5C20();
  return;
  lab_p03_L_5CC6: ;
  cpu_pop_bc();
  lab_p03_L_5CC7: ;
  cpu_pop_hl();
  cpu_pop_de();
  goto lab_p03_L_5CD2;
  lab_p03_L_5CCB: ;
  set_bc(0x0012);
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  lab_p03_L_5CD2: ;
  cpu_pop_af();
  cpu_push_de();
  cpu_push_af();
  p00_L_0C25();
  p00_L_1128();
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) p00_L_0ED0();
  cpu_pop_af();
  if (flag_nc()) p00_L_0D1F();
  cpu_pop_hl();
  p00_L_0BEC();
  set_hl(0x8478);
  p00_L_34A7();
  return;
  lab_p03_L_5CEF: ;
  a = (uint8_t)(a - b);
  if (flag_c()) goto lab_p03_L_5CC7;
  a = (uint8_t)(a - 0x0D);
  if (flag_nc()) goto lab_p03_L_5CF7;
  a = a ^ 0xFF;
  lab_p03_L_5CF7: ;
  b = a;
  a = mem_read8(0x8484);
  d = a;
  a = mem_read8(0x8479);
  a = (uint8_t)(a - d);
  if (flag_nc()) goto lab_p03_L_5D03;
  a = a ^ 0xFF;
  lab_p03_L_5D03: ;
  a = (uint8_t)(a - b);
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_c()) goto lab_p03_L_5CD2;
  goto lab_p03_L_5CCB;
}

/* flash page 3 cpu 0x5D0A (offset 0x1D0A) */
void p03_L_5D0A(void) {
  p00_L_14C7();
  if (flag_z()) return;
  p00_L_14CC();
  if (flag_z()) return;
  a = mem_read8(0x8479);
  set_hl(0x8484);
  /* sub (hl) */
  if (flag_c()) goto lab_p03_L_5D32;
  a = (uint8_t)(a - 0x0C);
  if (flag_c()) return;
  lab_p03_L_5D1E: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_af();
  a = d;
  a = a & b;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_5D29;
  a = e;
  a = a & b;
  flag_logic(a);
  if (flag_nz()) goto lab_p03_L_5D37;
  lab_p03_L_5D29: ;
  cpu_pop_af();
  cpu_push_de();
  cpu_push_hl();
  if (flag_nc()) { p00_L_1287(); return; }
  p00_L_128A();
  return;
  lab_p03_L_5D32: ;
  a = (uint8_t)(a - 0xF5);
  if (flag_nc()) return;
  goto lab_p03_L_5D1E;
  lab_p03_L_5D37: ;
  cpu_pop_af();
  p03_L_5D38();
  return;
}

/* flash page 3 cpu 0x5D38 (offset 0x1D38) */
void p03_L_5D38(void) {
  set_de(0x0024);
  p00_L_21B6();
  p03_L_5C30();
  return;
}

/* flash page 3 cpu 0x5D41 (offset 0x1D41) */
void p03_L_5D41(void) {
  p00_L_14C7();
  if (flag_z()) goto lab_p03_L_5D6C;
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) | (1u << 2)));
  p00_L_14B0();
  goto lab_p03_L_5D5B;
  lab_p03_L_5D5B: ;
  p00_L_0FB5();
  p00_L_14C7();
  if (flag_nz()) goto lab_p03_L_5D6F;
  p00_L_14CC();
  if (flag_z()) goto lab_p03_L_5D6C;
  p00_L_15C6();
  if (flag_z()) return;
  lab_p03_L_5D6C: ;
  p00_L_24C9();
  return;
  lab_p03_L_5D6F: ;
  p00_L_14CC();
  if (flag_z()) { p00_L_1229(); return; }
  a = 0;
  flag_logic(a);
  cpu_push_af();
  p00_L_1161();
  p00_L_15CB();
  if (flag_z()) goto lab_p03_L_5DDF;
  p00_L_222C();
  a = mem_read8(0x8484);
  flag_cmp(a, 0x75);
  if (flag_c()) { p00_L_38AF(); return; }
  p00_L_1179();
  p00_L_163B();
  if (flag_nc()) goto lab_p03_L_5D9D;
  a = mem_read8((uint16_t)(iy + 0x1E));
  a = a ^ 0x04;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x1E), a);
  p00_L_0ECC();
  lab_p03_L_5D9D: ;
  p00_L_3AA7();
  if (flag_c()) goto lab_p03_L_5DB3;
  set_hl(0x8484);
  p00_L_14E8();
  if (flag_nz()) goto lab_p03_L_5DC1;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 2)) == 0);
  if (flag_z()) { p00_L_38AF(); return; }
  goto lab_p03_L_5DD6;
  lab_p03_L_5DB3: ;
  d = 0x0C;
  p00_L_39C9();
  set_hl(0x8479);
  p00_L_14E4();
  if (flag_nz()) { p00_L_38AF(); return; }
  lab_p03_L_5DC1: ;
  set_hl(0x8479);
  p00_L_14E8();
  if (flag_nz()) goto lab_p03_L_5DD2;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 2)) == 0);
  if (flag_nz()) { p00_L_38AF(); return; }
  goto lab_p03_L_5DD6;
  lab_p03_L_5DD2: ;
  cpu_pop_af();
  a = a | 0x80;
  flag_logic(a);
  cpu_push_af();
  lab_p03_L_5DD6: ;
  p00_L_2196();
  p00_L_219B();
  p00_L_15D6();
  lab_p03_L_5DDF: ;
  p00_L_1169();
  p00_L_1179();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_0ECC();
  p00_rst08();
  p00_L_148B();
  a = mem_read8(0x8484);
  flag_cmp(a, 0x82);
  if (flag_nc()) goto lab_p03_L_5E1D;
  set_hl(0x8483);
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p03_L_5E1D;
  set_hl((uint16_t)(hl() + 1));
  p00_L_14E4();
  if (flag_nz()) goto lab_p03_L_5E1D;
  a = mem_read8(0x8484);
  flag_cmp(a, 0x80);
  a = mem_read8(0x8485);
  if (flag_z()) p00_L_12B1();
  p00_rst08();
  goto lab_p03_L_5E18;
  lab_p03_L_5E12: ;
  /* daa */
  cpu_push_af();
  p00_L_0D1F();
  cpu_pop_af();
  lab_p03_L_5E18: ;
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p03_L_5E12;
  goto lab_p03_L_5E38;
  lab_p03_L_5E1D: ;
  c = 0x01;
  p00_L_3861();
  p00_L_14C7();
  if (flag_nz()) goto lab_p03_L_5E2C;
  p00_L_1229();
  goto lab_p03_L_5E38;
  lab_p03_L_5E2C: ;
  p00_L_1128();
  p00_L_0CFA();
  p00_L_0F98();
  p00_L_3867();
  lab_p03_L_5E38: ;
  cpu_pop_af();
  mem_write8(0x8478, a);
  return;
}

/* flash page 3 cpu 0x5D53 (offset 0x1D53) */
void p03_L_5D53(void) {
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 2)));
  p00_L_0FB5();
  p00_L_14C7();
  if (flag_nz()) goto lab_p03_L_5D6F;
  p00_L_14CC();
  if (flag_z()) goto lab_p03_L_5D6C;
  p00_L_15C6();
  if (flag_z()) return;
  lab_p03_L_5D6C: ;
  p00_L_24C9();
  return;
  lab_p03_L_5D6F: ;
  p00_L_14CC();
  if (flag_z()) { p00_L_1229(); return; }
  a = 0;
  flag_logic(a);
  cpu_push_af();
  p00_L_1161();
  p00_L_15CB();
  if (flag_z()) goto lab_p03_L_5DDF;
  p00_L_222C();
  a = mem_read8(0x8484);
  flag_cmp(a, 0x75);
  if (flag_c()) { p00_L_38AF(); return; }
  p00_L_1179();
  p00_L_163B();
  if (flag_nc()) goto lab_p03_L_5D9D;
  a = mem_read8((uint16_t)(iy + 0x1E));
  a = a ^ 0x04;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x1E), a);
  p00_L_0ECC();
  lab_p03_L_5D9D: ;
  p00_L_3AA7();
  if (flag_c()) goto lab_p03_L_5DB3;
  set_hl(0x8484);
  p00_L_14E8();
  if (flag_nz()) goto lab_p03_L_5DC1;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 2)) == 0);
  if (flag_z()) { p00_L_38AF(); return; }
  goto lab_p03_L_5DD6;
  lab_p03_L_5DB3: ;
  d = 0x0C;
  p00_L_39C9();
  set_hl(0x8479);
  p00_L_14E4();
  if (flag_nz()) { p00_L_38AF(); return; }
  lab_p03_L_5DC1: ;
  set_hl(0x8479);
  p00_L_14E8();
  if (flag_nz()) goto lab_p03_L_5DD2;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 2)) == 0);
  if (flag_nz()) { p00_L_38AF(); return; }
  goto lab_p03_L_5DD6;
  lab_p03_L_5DD2: ;
  cpu_pop_af();
  a = a | 0x80;
  flag_logic(a);
  cpu_push_af();
  lab_p03_L_5DD6: ;
  p00_L_2196();
  p00_L_219B();
  p00_L_15D6();
  lab_p03_L_5DDF: ;
  p00_L_1169();
  p00_L_1179();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_0ECC();
  p00_rst08();
  p00_L_148B();
  a = mem_read8(0x8484);
  flag_cmp(a, 0x82);
  if (flag_nc()) goto lab_p03_L_5E1D;
  set_hl(0x8483);
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p03_L_5E1D;
  set_hl((uint16_t)(hl() + 1));
  p00_L_14E4();
  if (flag_nz()) goto lab_p03_L_5E1D;
  a = mem_read8(0x8484);
  flag_cmp(a, 0x80);
  a = mem_read8(0x8485);
  if (flag_z()) p00_L_12B1();
  p00_rst08();
  goto lab_p03_L_5E18;
  lab_p03_L_5E12: ;
  /* daa */
  cpu_push_af();
  p00_L_0D1F();
  cpu_pop_af();
  lab_p03_L_5E18: ;
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p03_L_5E12;
  goto lab_p03_L_5E38;
  lab_p03_L_5E1D: ;
  c = 0x01;
  p00_L_3861();
  p00_L_14C7();
  if (flag_nz()) goto lab_p03_L_5E2C;
  p00_L_1229();
  goto lab_p03_L_5E38;
  lab_p03_L_5E2C: ;
  p00_L_1128();
  p00_L_0CFA();
  p00_L_0F98();
  p00_L_3867();
  lab_p03_L_5E38: ;
  cpu_pop_af();
  mem_write8(0x8478, a);
  return;
}

/* flash page 3 cpu 0x5E3D (offset 0x1E3D) */
void p03_L_5E3D(void) {
  p03_L_67B2();
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_z()) return;
  flag_cmp(a, 0x03);
  if (flag_nz()) return;
  cpu_push_af();
  cpu_push_hl();
  p03_L_7053();
  cpu_pop_hl();
  cpu_pop_af();
  p03_L_65F5();
  p03_L_6AF7();
  set_hl(mem_read16(0x84E5));
  a = h;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p03_L_5E65;
  cpu_push_bc();
  cpu_pop_hl();
  cpu_push_hl();
  p03_L_59B1();
  p00_L_1179();
  goto lab_p03_L_5E79;
  lab_p03_L_5E65: ;
  cpu_push_bc();
  mem_write16(0x84AF, bc());
  mem_write16(0x84D3, hl());
  set_hl(0x0001);
  mem_write16(0x84B1, hl());
  p00_L_3B3D();
  p03_L_6AF7();
  lab_p03_L_5E79: ;
  p00_L_38A3();
  set_hl(0x6AFE);
  p00_L_0EC1();
  p00_L_0C1B();
  p00_L_0FAF();
  p00_rst18();
  cpu_pop_hl();
  cpu_push_hl();
  mem_write16(0x84AF, hl());
  p00_L_3B31();
  p00_rst18();
  p03_L_6B07();
  if (flag_z()) goto lab_p03_L_5EA5;
  p00_L_1100();
  p00_L_231F();
  p00_L_107E();
  if (flag_nc()) goto lab_p03_L_5EA8;
  p00_L_113F();
  lab_p03_L_5EA5: ;
  p00_L_2375();
  lab_p03_L_5EA8: ;
  cpu_pop_hl();
  mem_write16(0x84AF, hl());
  p00_L_3B37();
  p00_L_2196();
  p00_L_1171();
  p00_L_0C2D();
  p00_L_2196();
  p00_L_0ED0();
  p03_L_6B07();
  if (flag_z()) goto lab_p03_L_5ED1;
  p00_L_1100();
  p00_L_22B3();
  p00_L_107E();
  if (flag_c()) goto lab_p03_L_5ED4;
  p00_L_113F();
  lab_p03_L_5ED1: ;
  p00_L_23B3();
  lab_p03_L_5ED4: ;
  p00_L_113A();
  p00_L_22B3();
  p00_rst30();
  p03_L_6B07();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) | (1u << 4)));
  if (flag_z()) goto lab_p03_L_5EF9;
  p00_L_1100();
  p00_L_2310();
  p00_L_107E();
  if (flag_c()) return;
  p00_L_113F();
  lab_p03_L_5EF9: ;
  p00_L_235C();
  return;
}

/* flash page 3 cpu 0x5EFC (offset 0x1EFC) */
void p03_L_5EFC(void) {
  mem_write8(0x8E63, a);
  p03_L_67B2();
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_z()) return;
  flag_cmp(a, 0x03);
  if (flag_z()) return;
  cpu_push_af();
  cpu_push_af();
  cpu_push_hl();
  p03_L_7053();
  cpu_pop_hl();
  cpu_pop_af();
  p03_L_65F5();
  p03_L_6AF7();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  mem_write16(0x84AF, bc());
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p03_L_5F3B;
  set_hl(mem_read16(0x9192));
  mem_write16(0x84D3, hl());
  p00_L_3B37();
  p03_L_5FEB();
  cpu_pop_hl();
  cpu_push_hl();
  mem_write16(0x84AF, hl());
  p00_L_3B31();
  p03_L_6AF7();
  p03_L_5FC3();
  lab_p03_L_5F3B: ;
  cpu_pop_hl();
  cpu_push_hl();
  mem_write16(0x84AF, hl());
  p00_L_3B37();
  p03_L_5FE2();
  if (flag_nz()) goto lab_p03_L_5F53;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p03_L_5F53;
  p03_L_5FEB();
  goto lab_p03_L_5F56;
  lab_p03_L_5F53: ;
  p03_L_5F89();
  lab_p03_L_5F56: ;
  cpu_pop_hl();
  cpu_push_hl();
  mem_write16(0x84AF, hl());
  p00_L_3B31();
  p03_L_5FE2();
  if (flag_nz()) goto lab_p03_L_5F6E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p03_L_5F6E;
  p03_L_5FC3();
  goto lab_p03_L_5F71;
  lab_p03_L_5F6E: ;
  p03_L_5FA4();
  lab_p03_L_5F71: ;
  cpu_pop_hl();
  cpu_pop_af();
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p03_L_5F88;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 2)));
  p00_L_0087();
  set_hl(0x8E63);
  p03_L_640C();
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 2)));
  lab_p03_L_5F88: ;
  return;
}

/* flash page 3 cpu 0x5F89 (offset 0x1F89) */
void p03_L_5F89(void) {
  p00_L_1100();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p03_L_5F9C;
  p00_L_2310();
  p00_L_107E();
  if (flag_c()) return;
  p00_L_113F();
  lab_p03_L_5F9C: ;
  p00_L_235C();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 7)));
  return;
}

/* flash page 3 cpu 0x5FA4 (offset 0x1FA4) */
void p03_L_5FA4(void) {
  p00_L_1100();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 4)) == 0);
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) | (1u << 4)));
  if (flag_z()) goto lab_p03_L_5FBB;
  p00_L_22F7();
  p00_L_107E();
  if (flag_nc()) return;
  p00_L_113F();
  lab_p03_L_5FBB: ;
  p00_L_233D();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 7)));
  return;
}

/* flash page 3 cpu 0x5FC3 (offset 0x1FC3) */
void p03_L_5FC3(void) {
  p00_L_1100();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 1)) == 0);
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) | (1u << 1)));
  if (flag_z()) goto lab_p03_L_5FDA;
  p00_L_231F();
  p00_L_107E();
  if (flag_nc()) return;
  p00_L_113F();
  lab_p03_L_5FDA: ;
  p00_L_2375();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 7)));
  return;
}

/* flash page 3 cpu 0x5FE2 (offset 0x1FE2) */
void p03_L_5FE2(void) {
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_hl();
  cpu_push_de();
  flag_cmp(a, 0x05);
  return;
}

/* flash page 3 cpu 0x5FEB (offset 0x1FEB) */
void p03_L_5FEB(void) {
  p00_L_1100();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p03_L_5FFE;
  p00_L_22C7();
  p00_L_107E();
  if (flag_c()) return;
  p00_L_113F();
  lab_p03_L_5FFE: ;
  p00_L_2389();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 7)));
  return;
}

/* flash page 3 cpu 0x60BA (offset 0x20BA) */
void p03_L_60BA(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 4)) == 0);
  set_de(0x002D);
  if (flag_z()) { p00_L_21B6(); return; }
  a = 0x0A;
  flag_cmp(a, a);
  p03_L_60E6();
  p00_L_2324();
  p00_L_15FB();
  a = 0x02;
  p00_L_3675();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 1)) == 0);
  a = 0x0C;
  cpu_push_af();
  if (flag_z()) p00_L_21A4();
  cpu_pop_af();
  if (flag_nz()) p03_L_60E6();
  p00_L_21A7();
  return;
}

/* flash page 3 cpu 0x60E6 (offset 0x20E6) */
void p03_L_60E6(void) {
  cpu_push_af();
  p00_L_2315();
  p00_L_22F7();
  p00_L_0C2D();
  p00_L_15D6();
  p00_L_1251();
  a = 0x7F;
  mem_write8(0x8484, a);
  cpu_pop_af();
  cpu_push_af();
  if (flag_z()) goto lab_p03_L_6104;
  a = 0x17;
  mem_write8(0x8485, a);
  lab_p03_L_6104: ;
  p00_L_0D1F();
  p03_L_6B07();
  if (flag_nz()) p00_L_128A();
  p00_L_22F7();
  p00_L_233D();
  p00_L_0C13();
  p00_L_15FB();
  cpu_pop_af();
  cpu_push_af();
  p00_L_3675();
  p00_L_219B();
  p00_L_2196();
  p00_rst30();
  p00_L_15FB();
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  p00_L_3675();
  return;
}

/* flash page 3 cpu 0x612E (offset 0x212E) */
void p03_L_612E(void) {
  p00_L_22F7();
  p00_L_107E();
  if (flag_c()) return;
  p00_L_233D();
  return;
}

/* flash page 3 cpu 0x6138 (offset 0x2138) */
void p03_L_6138(void) {
  p03_L_67B2();
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_z()) return;
  flag_cmp(a, 0x03);
  if (flag_nz()) return;
  cpu_push_af();
  cpu_push_hl();
  p03_L_7053();
  cpu_pop_hl();
  cpu_pop_af();
  p03_L_65F5();
  p03_L_614B();
  return;
}

/* flash page 3 cpu 0x614B (offset 0x214B) */
void p03_L_614B(void) {
  p00_L_128A();
  p03_L_6B07();
  if (flag_nz()) p00_L_21E5();
  set_hl(0x8F59);
  p00_rst20();
  set_hl(0x8F50);
  p00_L_11F8();
  p00_rst18();
  p00_L_21E0();
  p00_rst18();
  p00_rst18();
  p00_L_0C2D();
  set_hl(0x8F62);
  p00_L_11F8();
  p00_L_14CC();
  if (flag_z()) { p00_L_2515(); return; }
  p00_L_0ED0();
  p00_L_15D6();
  p00_rst18();
  p00_L_34B3();
  p00_L_14C7();
  if (flag_z()) { p00_L_2515(); return; }
  a = 0x30;
  p03_L_5996();
  p00_L_107E();
  if (flag_nc()) { p00_L_2515(); return; }
  p00_L_2196();
  p00_L_107E();
  if (flag_z()) p00_L_0C1B();
  p00_L_2389();
  p00_L_3B5B();
  cpu_push_af();
  set_hl(0x8F50);
  p00_rst20();
  set_de(0x848E);
  p00_L_1183();
  p00_L_1287();
  p00_L_1276();
  p03_L_6B07();
  if (flag_nz()) goto lab_p03_L_61BA;
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 3)) == 0);
  if (flag_z()) p03_L_5A3B();
  lab_p03_L_61BA: ;
  cpu_pop_bc();
  c = 0x01;
  p03_L_61BD();
  return;
}

/* flash page 3 cpu 0x6165 (offset 0x2165) */
void p03_L_6165(void) {
  l = (uint8_t)(l - 1);
  c = (uint8_t)(c + 1);
  set_hl(0x8F62);
  p00_L_11F8();
  p00_L_14CC();
  if (flag_z()) { p00_L_2515(); return; }
  p00_L_0ED0();
  p00_L_15D6();
  p00_rst18();
  p00_L_34B3();
  p00_L_14C7();
  if (flag_z()) { p00_L_2515(); return; }
  a = 0x30;
  p03_L_5996();
  p00_L_107E();
  if (flag_nc()) { p00_L_2515(); return; }
  p00_L_2196();
  p00_L_107E();
  if (flag_z()) p00_L_0C1B();
  p00_L_2389();
  p00_L_3B5B();
  cpu_push_af();
  set_hl(0x8F50);
  p00_rst20();
  set_de(0x848E);
  p00_L_1183();
  p00_L_1287();
  p00_L_1276();
  p03_L_6B07();
  if (flag_nz()) goto lab_p03_L_61BA;
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 3)) == 0);
  if (flag_z()) p03_L_5A3B();
  lab_p03_L_61BA: ;
  cpu_pop_bc();
  c = 0x01;
  p03_L_61BD();
  return;
}

/* flash page 3 cpu 0x61BD (offset 0x21BD) */
void p03_L_61BD(void) {
  set_hl(mem_read16(0x918E));
  p00_L_0033();
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_hl();
  p03_L_62BC();
  p00_L_235C();
  p03_L_61CC();
  return;
}

/* flash page 3 cpu 0x61CC (offset 0x21CC) */
void p03_L_61CC(void) {
  goto lab_p03_L_61CC;
  lab_p03_L_61C3: ;
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_hl();
  p03_L_62BC();
  p00_L_235C();
  lab_p03_L_61CC: ;
  p00_L_23CC();
  cpu_ex_de_hl();
  p00_L_101A();
  cpu_pop_hl();
  lab_p03_L_61D4: ;
  p03_L_6B07();
  if (flag_nz()) goto lab_p03_L_61DE;
  p00_L_0189();
  if (flag_nz()) goto lab_p03_L_6224;
  lab_p03_L_61DE: ;
  cpu_push_hl();
  set_de(mem_read16(0x918E));
  p00_L_3AF5();
  p00_L_231F();
  p00_L_107E();
  if (flag_c()) goto lab_p03_L_6213;
  p00_L_2310();
  p00_L_107E();
  if (flag_nc()) goto lab_p03_L_6213;
  p00_L_1229();
  set_de(mem_read16(0x84E5));
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_620C;
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_3AF5();
  p00_L_15CB();
  if (flag_nz()) { p00_L_2515(); return; }
  lab_p03_L_620C: ;
  p00_L_22F7();
  p00_rst30();
  p00_L_233D();
  lab_p03_L_6213: ;
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p03_L_61D4;
  p03_L_6B07();
  if (flag_nz()) goto lab_p03_L_626B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p03_L_6227;
  lab_p03_L_6224: ;
  cpu_pop_hl();
  cpu_pop_bc();
  return;
  lab_p03_L_6227: ;
  p00_L_22ED();
  p00_L_22DE();
  p00_L_1287();
  p00_L_113F();
  p03_L_5A3B();
  p00_L_22ED();
  p00_L_230B();
  p00_L_10EF();
  p00_L_2324();
  p03_L_5A3B();
  p00_L_1276();
  p00_L_230B();
  p00_L_22F7();
  p00_L_113F();
  p00_L_2375();
  p03_L_5A3B();
  lab_p03_L_6257: ;
  cpu_pop_hl();
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p03_L_61C3;
  set_de(0x0024);
  p00_L_21B6();
  p03_L_6B07();
  if (flag_z()) return;
  p00_L_219B();
  return;
  lab_p03_L_626B: ;
  p00_L_22FC();
  p00_L_22B3();
  p00_L_107E();
  if (flag_nc()) p00_L_23B3();
  p00_L_2315();
  p00_L_2375();
  goto lab_p03_L_6257;
}

/* flash page 3 cpu 0x627F (offset 0x227F) */
void p03_L_627F(void) {
  p00_L_22CF();
  p00_L_3B5B();
  set_hl(0x8E65);
  cpu_cp_hl();
  if (flag_z()) return;
  c = mem_read8(hl());
  c = (uint8_t)(c + 1);
  cpu_push_bc();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_L_2315();
  p00_L_2375();
  cpu_pop_bc();
  p03_L_61BD();
  return;
}

/* flash page 3 cpu 0x6298 (offset 0x2298) */
void p03_L_6298(void) {
  a = mem_read8(0x8E65);
  a = (uint8_t)(a - 1);
  if (flag_z()) return;
  c = a;
  mem_write8(0x8E65, a);
  cpu_push_bc();
  p00_L_2324();
  p00_L_235C();
  cpu_pop_bc();
  cpu_push_bc();
  c = (uint8_t)(c - 1);
  p03_L_62BC();
  p00_L_2375();
  set_hl(mem_read16(0x918E));
  p00_L_0033();
  cpu_push_hl();
  cpu_push_hl();
  p03_L_61CC();
  return;
}

/* flash page 3 cpu 0x62BC (offset 0x22BC) */
void p03_L_62BC(void) {
  a = c;
  p03_L_5991();
  set_hl(0x8F62);
  p00_L_11F8();
  set_hl(0x8483);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  p00_L_0D1F();
  set_hl(0x8F50);
  p00_L_0BEC();
  return;
}

/* flash page 3 cpu 0x62D4 (offset 0x22D4) */
void p03_L_62D4(void) {
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 4)));
  goto lab_p03_L_62DE;
  lab_p03_L_62DE: ;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 3)));
  p03_L_62E2();
  return;
}

/* flash page 3 cpu 0x62E2 (offset 0x22E2) */
void p03_L_62E2(void) {
  b = d;
  set_hl(mem_read16(0x918E));
  p00_L_0033();
  cpu_push_hl();
  set_de(0x0001);
  cpu_push_de();
  cpu_push_bc();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p03_L_6306;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nz()) goto lab_p03_L_62FE;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 4)));
  lab_p03_L_62FE: ;
  p00_rst18();
  p00_rst18();
  p00_L_0189();
  if (flag_nz()) goto lab_p03_L_639A;
  lab_p03_L_6306: ;
  cpu_pop_af();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_af();
  cpu_push_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p03_L_633D;
  cpu_pop_hl();
  p03_L_6AD6();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_6338;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p03_L_632C;
  p03_L_5FEB();
  p00_L_113F();
  p03_L_5FC3();
  goto lab_p03_L_6335;
  lab_p03_L_632C: ;
  p03_L_5F89();
  p00_L_113F();
  p03_L_5FA4();
  lab_p03_L_6335: ;
  p03_L_638D();
  return;
  lab_p03_L_6338: ;
  p00_L_222C();
  goto lab_p03_L_634E;
  lab_p03_L_633D: ;
  set_de(mem_read16(0x918E));
  p00_L_3AF5();
  p00_rst18();
  cpu_pop_hl();
  set_de(mem_read16(0x9192));
  p00_L_3AF5();
  p00_rst18();
  lab_p03_L_634E: ;
  p03_L_63AF();
  if (flag_z()) goto lab_p03_L_635B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p03_L_6373;
  p03_L_638D();
  return;
  lab_p03_L_635B: ;
  cpu_pop_af();
  cpu_push_af();
  p00_L_34B9();
  if (flag_c()) goto lab_p03_L_636D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p03_L_6373;
  p00_L_34BF();
  p03_L_638D();
  return;
  lab_p03_L_636D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_z()) { p03_L_638D(); return; }
  lab_p03_L_6373: ;
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  p00_L_230B();
  p00_L_22ED();
  p00_L_235C();
  p00_L_2333();
  cpu_pop_af();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_af();
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) p03_L_5A3B();
  p03_L_638D();
  return;
  lab_p03_L_639A: ;
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  p00_L_21A4();
  return;
}

/* flash page 3 cpu 0x6320 (offset 0x2320) */
void p03_L_6320(void) {
  set_bc((uint16_t)(bc() - 1));
  p03_L_5FEB();
  p00_L_113F();
  p03_L_5FC3();
  goto lab_p03_L_6335;
  lab_p03_L_6335: ;
  p03_L_638D();
  return;
}

/* flash page 3 cpu 0x638D (offset 0x238D) */
void p03_L_638D(void) {
  goto lab_p03_L_638D;
  lab_p03_L_6300: ;
  p00_L_0189();
  if (flag_nz()) goto lab_p03_L_639A;
  cpu_pop_af();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_af();
  cpu_push_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p03_L_633D;
  cpu_pop_hl();
  p03_L_6AD6();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_6338;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p03_L_632C;
  p03_L_5FEB();
  p00_L_113F();
  p03_L_5FC3();
  goto lab_p03_L_6335;
  lab_p03_L_632C: ;
  p03_L_5F89();
  p00_L_113F();
  p03_L_5FA4();
  lab_p03_L_6335: ;
  goto lab_p03_L_638D;
  lab_p03_L_6338: ;
  p00_L_222C();
  goto lab_p03_L_634E;
  lab_p03_L_633D: ;
  set_de(mem_read16(0x918E));
  p00_L_3AF5();
  p00_rst18();
  cpu_pop_hl();
  set_de(mem_read16(0x9192));
  p00_L_3AF5();
  p00_rst18();
  lab_p03_L_634E: ;
  p03_L_63AF();
  if (flag_z()) goto lab_p03_L_635B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p03_L_6373;
  goto lab_p03_L_638D;
  lab_p03_L_635B: ;
  cpu_pop_af();
  cpu_push_af();
  p00_L_34B9();
  if (flag_c()) goto lab_p03_L_636D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p03_L_6373;
  p00_L_34BF();
  goto lab_p03_L_638D;
  lab_p03_L_636D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p03_L_638D;
  lab_p03_L_6373: ;
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  p00_L_230B();
  p00_L_22ED();
  p00_L_235C();
  p00_L_2333();
  cpu_pop_af();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_af();
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) p03_L_5A3B();
  lab_p03_L_638D: ;
  cpu_pop_af();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_push_hl();
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p03_L_6300;
  lab_p03_L_639A: ;
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  p00_L_21A4();
  return;
}

/* flash page 3 cpu 0x63A5 (offset 0x23A5) */
void p03_L_63A5(void) {
  return;
}

/* flash page 3 cpu 0x63AF (offset 0x23AF) */
void p03_L_63AF(void) {
  set_de(0xFFF7);
  p00_L_3489();
  if (flag_nz()) goto lab_p03_L_63BD;
  p03_L_707D();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_63C3;
  lab_p03_L_63BD: ;
  p00_L_2148();
  a = a | 0x01;
  flag_logic(a);
  return;
  lab_p03_L_63C3: ;
  p00_L_2315();
  set_de(0x8478);
  p00_L_348F();
  mem_write8(0x8D19, a);
  p00_L_22FC();
  set_de(0x8478);
  p00_L_34CB();
  mem_write8(0x8D18, a);
  p00_L_2148();
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 3 cpu 0x63E0 (offset 0x23E0) */
void p03_L_63E0(void) {
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 4)));
  p03_L_6AF7();
  set_hl(mem_read16(0x84E5));
  mem_write16(0x84DB, hl());
  p00_L_3927();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 3)));
  return;
}

/* flash page 3 cpu 0x6400 (offset 0x2400) */
void p03_L_6400(void) {
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 2)));
  set_hl(0x8E63);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p03_L_640C();
  return;
}

/* flash page 3 cpu 0x640C (offset 0x240C) */
void p03_L_640C(void) {
  goto lab_p03_L_640C;
  lab_p03_L_62DA: ;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 3)));
  p03_L_62E2();
  return;
  lab_p03_L_63F9: ;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_62DA;
  p03_L_62D4();
  return;
  lab_p03_L_640C: ;
  a = mem_read8(hl());
  cpu_push_af();
  p03_L_69E7();
  p00_rst10();
  if (flag_nc()) p00_L_1F58();
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 3)));
  p03_L_67B2();
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_z()) return;
  cpu_push_af();
  cpu_push_hl();
  p03_L_7053();
  cpu_pop_hl();
  cpu_pop_af();
  p03_L_65F5();
  if (flag_c()) goto lab_p03_L_63F9;
  flag_cmp(a, 0x03);
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 6)));
  if (flag_c()) goto lab_p03_L_6485;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 6)));
  if (flag_z()) { p03_L_614B(); return; }
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p03_L_6481;
  cpu_push_de();
  p03_L_6AF7();
  p00_L_0033();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + hl()));
  p03_L_69E7();
  p00_L_1C8F();
  mem_write16(0x84D9, de());
  mem_write16(0x9192, de());
  cpu_pop_hl();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  lab_p03_L_645A: ;
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_6468;
  cpu_push_bc();
  cpu_pop_hl();
  cpu_push_hl();
  p03_L_69C6();
  goto lab_p03_L_645A;
  lab_p03_L_6468: ;
  cpu_pop_hl();
  set_de(0x0001);
  p03_L_69F7();
  set_hl(mem_read16(0x84D9));
  mem_write16(0x84E7, hl());
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 4)));
  cpu_pop_de();
  p03_L_62E2();
  return;
  lab_p03_L_6481: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 6)));
  lab_p03_L_6485: ;
  cpu_push_de();
  p03_L_63E0();
  p03_L_6583();
  p00_rst18();
  mem_write16(0x9302, de());
  p00_rst08();
  p00_L_28F1();
  p00_L_28AB();
  p00_L_10E6();
  p03_L_5A3B();
  p00_L_22F7();
  p00_L_10E6();
  p00_L_289D();
  p00_L_28D6();
  p03_L_5A3B();
  set_de(0x65D1);
  p03_L_6586();
  p00_L_233D();
  p00_L_289D();
  p00_L_22F7();
  p03_L_6571();
  set_de(0x65DA);
  p03_L_6586();
  p00_rst18();
  p00_rst08();
  p00_L_28B5();
  p03_L_6571();
  p00_L_28B5();
  p00_L_22F7();
  p03_L_657B();
  p00_L_289D();
  p00_L_28FD();
  p03_L_657B();
  p00_L_22ED();
  p00_L_28FD();
  p00_L_28CB();
  p00_L_1100();
  p03_L_5A3B();
  set_de(0x65E3);
  p03_L_6586();
  p00_L_235C();
  set_de(0x65EC);
  p03_L_6586();
  p00_L_233D();
  p00_L_28F1();
  p03_L_6566();
  p00_L_28E5();
  p03_L_6566();
  p03_L_6583();
  p00_L_233D();
  p00_L_2910();
  p00_L_1169();
  cpu_pop_af();
  mem_write8(0x84B5, a);
  lab_p03_L_651C: ;
  set_bc(mem_read16(0x84AF));
  set_bc((uint16_t)(bc() - 1));
  mem_write16(0x84AF, bc());
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_652E;
  p03_L_654A();
  goto lab_p03_L_651C;
  lab_p03_L_652E: ;
  set_bc(mem_read16(0x84B1));
  set_bc((uint16_t)(bc() + 1));
  mem_write16(0x84B1, bc());
  set_hl(mem_read16(0x84B3));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p03_L_6544;
  p03_L_654A();
  goto lab_p03_L_652E;
  lab_p03_L_6544: ;
  set_de(0x0048);
  p00_L_21B6();
  return;
}

/* flash page 3 cpu 0x654A (offset 0x254A) */
void p03_L_654A(void) {
  mem_write16(0x84AF, bc());
  p00_L_18BC();
  p00_L_22F7();
  p03_L_6554();
  return;
}

/* flash page 3 cpu 0x6554 (offset 0x2554) */
void p03_L_6554(void) {
  p00_L_222C();
  p03_L_63AF();
  if (flag_nz()) return;
  a = mem_read8(0x84B5);
  p00_L_34B9();
  if (flag_c()) return;
  p00_L_34BF();
  return;
}

/* flash page 3 cpu 0x6563 (offset 0x2563) */
void p03_L_6563(void) {
  flag_cmp(a, a);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  return;
}

/* flash page 3 cpu 0x6566 (offset 0x2566) */
void p03_L_6566(void) {
  p00_L_1100();
  p00_L_2310();
  p00_L_22ED();
  goto lab_p03_L_6577;
  lab_p03_L_6577: ;
  p03_L_5A3B();
  return;
}

/* flash page 3 cpu 0x656D (offset 0x256D) */
void p03_L_656D(void) {
  /* db 0xED,0x22 */
  goto lab_p03_L_6577;
  lab_p03_L_6577: ;
  p03_L_5A3B();
  return;
}

/* flash page 3 cpu 0x6571 (offset 0x2571) */
void p03_L_6571(void) {
  p00_L_28AB();
  p00_L_28F8();
  p03_L_5A3B();
  return;
}

/* flash page 3 cpu 0x6572 (offset 0x2572) */
void p03_L_6572(void) {
  goto lab_p03_L_6572;
  lab_p03_L_652E: ;
  set_bc(mem_read16(0x84B1));
  set_bc((uint16_t)(bc() + 1));
  mem_write16(0x84B1, bc());
  set_hl(mem_read16(0x84B3));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p03_L_6544;
  p03_L_654A();
  lab_p03_L_6542: ;
  goto lab_p03_L_652E;
  lab_p03_L_6544: ;
  set_de(0x0048);
  lab_p03_L_6545: ;
  c = b;
  /* nop */
  p00_L_21B6();
  return;
  lab_p03_L_6572: ;
  a = a ^ e;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_6542;
  if (flag_m()) return;
  if (flag_z()) goto lab_p03_L_6545;
  sp = (uint16_t)(sp - 1);
  e = d;
  return;
}

/* flash page 3 cpu 0x657B (offset 0x257B) */
void p03_L_657B(void) {
  goto lab_p03_L_657B;
  lab_p03_L_6577: ;
  p03_L_5A3B();
  return;
  lab_p03_L_657B: ;
  p00_L_28A6();
  p00_L_22ED();
  goto lab_p03_L_6577;
}

/* flash page 3 cpu 0x6583 (offset 0x2583) */
void p03_L_6583(void) {
  set_de(0x65C8);
  p03_L_6586();
  return;
}

/* flash page 3 cpu 0x6586 (offset 0x2586) */
void p03_L_6586(void) {
  a = mem_read8(0x8E64);
  c = a;
  set_hl(0x8E63);
  a = a & 0x0F;
  flag_logic(a);
  cpu_cp_hl();
  a = 0x01;
  if (flag_z()) goto lab_p03_L_659F;
  a = c;
  p00_L_12B1();
  cpu_cp_hl();
  a = 0x02;
  if (flag_z()) goto lab_p03_L_659F;
  a = 0x03;
  lab_p03_L_659F: ;
  a = (uint8_t)(a - 1);
  p00_L_17CE();
  if (flag_z()) goto lab_p03_L_65A7;
  a = (uint8_t)(a + 0x03);
  lab_p03_L_65A7: ;
  p00_L_18B7();
  if (flag_z()) goto lab_p03_L_65AE;
  a = (uint8_t)(a + 0x06);
  lab_p03_L_65AE: ;
  l = a;
  h = 0x00;
  set_hl((uint16_t)(hl() + de()));
  l = mem_read8(hl());
  h = 0x00;
  p03_L_59B1();
  set_hl(0x915B);
  p00_rst20();
  p00_L_0D1F();
  set_hl(0x8F74);
  p00_L_11F8();
  p00_L_0C13();
  return;
}

/* flash page 3 cpu 0x65F5 (offset 0x25F5) */
void p03_L_65F5(void) {
  set_de(0xFFF0);
  set_hl((uint16_t)(hl() + de()));
  b = a;
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  p00_L_12B1();
  cpu_push_af();
  a = b;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) | (1u << 6)));
  a = mem_read8(hl());
  p00_L_12B1();
  if (flag_z()) goto lab_p03_L_6612;
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 6)));
  lab_p03_L_6612: ;
  set_de(0xFFF1);
  set_hl((uint16_t)(hl() + de()));
  p03_L_6646();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p03_L_663A;
  flag_cmp(a, 0x02);
  cpu_push_de();
  if (flag_c()) goto lab_p03_L_663E;
  set_hl((uint16_t)(hl() + bc()));
  p03_L_665C();
  cpu_ex_de_hl();
  cpu_pop_bc();
  a = mem_read8(0x84E6);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_6635;
  lab_p03_L_6630: ;
  cpu_sbc_hl_bc();
  if (flag_nz()) { p00_L_24E9(); return; }
  lab_p03_L_6635: ;
  cpu_pop_af();
  flag_cmp(a, 0x02);
  cpu_pop_de();
  return;
  lab_p03_L_663A: ;
  cpu_push_de();
  cpu_pop_bc();
  goto lab_p03_L_6635;
  lab_p03_L_663E: ;
  p03_L_6653();
  cpu_ex_de_hl();
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  goto lab_p03_L_6630;
}

/* flash page 3 cpu 0x6646 (offset 0x2646) */
void p03_L_6646(void) {
  cpu_push_hl();
  p03_L_6675();
  mem_write16(0x918E, hl());
  cpu_pop_hl();
  set_bc(0x0005);
  set_hl((uint16_t)(hl() + bc()));
  return;
}

/* flash page 3 cpu 0x6653 (offset 0x2653) */
void p03_L_6653(void) {
  goto lab_p03_L_6653;
  lab_p03_L_664D: ;
  cpu_pop_hl();
  set_bc(0x0005);
  set_hl((uint16_t)(hl() + bc()));
  return;
  lab_p03_L_6653: ;
  cpu_push_hl();
  p03_L_6675();
  mem_write16(0x9192, hl());
  goto lab_p03_L_664D;
}

/* flash page 3 cpu 0x665C (offset 0x265C) */
void p03_L_665C(void) {
  goto lab_p03_L_665C;
  lab_p03_L_664D: ;
  cpu_pop_hl();
  set_bc(0x0005);
  set_hl((uint16_t)(hl() + bc()));
  return;
  lab_p03_L_665C: ;
  cpu_push_hl();
  a = mem_read8(hl());
  flag_cmp(a, 0x31);
  if (flag_nz()) goto lab_p03_L_6668;
  a = 0;
  flag_logic(a);
  mem_write8(0x84E6, a);
  goto lab_p03_L_664D;
  lab_p03_L_6668: ;
  p03_L_6675();
  mem_write16(0x84E5, hl());
  goto lab_p03_L_664D;
}

/* flash page 3 cpu 0x6675 (offset 0x2675) */
void p03_L_6675(void) {
  p03_L_6692();
  p00_L_241E();
  if (flag_c()) { p00_L_252D(); return; }
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x0D);
  if (flag_z()) { p00_L_252D(); return; }
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  cpu_ex_de_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_z()) { p00_L_24ED(); return; }
  return;
}

/* flash page 3 cpu 0x6692 (offset 0x2692) */
void p03_L_6692(void) {
  set_de(0x8479);
  a = 0x5D;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  p00_L_118B();
  cpu_ex_de_hl();
  mem_write8(hl(), 0x00);
  return;
}

/* flash page 3 cpu 0x66A0 (offset 0x26A0) */
void p03_L_66A0(void) {
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 7)));
  p00_L_34D1();
  mem_write8(0x8E63, a);
  set_hl(mem_read16(0x8D1F));
  mem_write16(0x8E65, hl());
  p03_L_67B2();
  p03_L_65F5();
  b = a;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p03_L_66BC;
  lab_p03_L_66BB: ;
  a = 0;
  flag_logic(a);
  lab_p03_L_66BC: ;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p03_L_66BB;
  set_hl(0x8D1E);
  cpu_cp_hl();
  if (flag_z()) goto lab_p03_L_66CC;
  set_hl(0x0001);
  mem_write16(0x8E65, hl());
  lab_p03_L_66CC: ;
  a = b;
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p03_L_6897;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 6)));
  if (flag_z()) goto lab_p03_L_671A;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 6)));
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p03_L_671A;
  if (flag_nc()) goto lab_p03_L_68C5;
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) | (1u << 3)));
  p03_L_614B();
  p03_L_66EF();
  return;
  lab_p03_L_671A: ;
  set_de(0x0003);
  cpu_cp_hl();
  if (flag_z()) goto lab_p03_L_6724;
  mem_write16(0x8E65, de());
  lab_p03_L_6724: ;
  mem_write8(0x8D1E, a);
  p03_L_63E0();
  p03_L_672A();
  return;
  lab_p03_L_677E: ;
  mem_write16(0x8D1F, bc());
  p03_L_63A5();
  l = c;
  h = b;
  cpu_pop_af();
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p03_L_679A;
  p03_L_6AD6();
  p00_L_21E0();
  p00_L_34DD();
  p00_L_219B();
  goto lab_p03_L_67A9;
  lab_p03_L_679A: ;
  cpu_push_hl();
  p00_L_3AF5();
  p00_L_34DD();
  set_de(mem_read16(0x9192));
  cpu_pop_hl();
  p00_L_3AF5();
  lab_p03_L_67A9: ;
  p00_L_34D7();
  p03_L_6716();
  return;
  lab_p03_L_6897: ;
  cpu_push_af();
  a = 0;
  flag_logic(a);
  mem_write8(0x8D1E, a);
  set_hl(mem_read16(0x918E));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  cpu_ex_de_hl();
  set_bc(mem_read16(0x8E65));
  lab_p03_L_68A8: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nc()) goto lab_p03_L_677E;
  set_hl((uint16_t)(hl() + bc()));
  set_bc((uint16_t)(bc() - 1));
  mem_write16(0x8E65, bc());
  goto lab_p03_L_68A8;
  lab_p03_L_68C5: ;
  p03_L_69E7();
  p00_L_241E();
  if (flag_c()) { p00_L_2515(); return; }
  mem_write16(0x84E7, de());
  a = 0x05;
  goto lab_p03_L_6897;
}

/* flash page 3 cpu 0x66EF (offset 0x26EF) */
void p03_L_66EF(void) {
  a = 0x04;
  mem_write8(0x8D1E, a);
  p03_L_63A5();
  p00_L_22FC();
  p00_L_34D7();
  p00_L_2310();
  p00_L_2324();
  p00_L_0C13();
  p00_L_0D16();
  p00_L_231F();
  p00_rst30();
  p00_L_34DD();
  set_hl(mem_read16(0x8D18));
  mem_write16(0x8D1C, hl());
  p03_L_6716();
  return;
}

/* flash page 3 cpu 0x6716 (offset 0x2716) */
void p03_L_6716(void) {
  p00_L_34E3();
  return;
}

/* flash page 3 cpu 0x672A (offset 0x272A) */
void p03_L_672A(void) {
  goto lab_p03_L_672A;
  lab_p03_L_670D: ;
  p00_L_34DD();
  set_hl(mem_read16(0x8D18));
  mem_write16(0x8D1C, hl());
  p03_L_6716();
  return;
  lab_p03_L_672A: ;
  p03_L_6583();
  p03_L_63A5();
  p00_L_34D7();
  p03_L_6738();
  goto lab_p03_L_670D;
}

/* flash page 3 cpu 0x6738 (offset 0x2738) */
void p03_L_6738(void) {
  p00_L_2267();
  set_hl(mem_read16(0x8E65));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_674A;
  set_de(0x0006);
  p00_L_192A();
  if (flag_c()) goto lab_p03_L_6768;
  lab_p03_L_674A: ;
  set_de(mem_read16(0x8478));
  set_hl((uint16_t)(hl() - 1));
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p03_L_675B;
  set_de(0xFFFC);
  set_hl((uint16_t)(hl() + de()));
  set_de(mem_read16(0x847A));
  lab_p03_L_675B: ;
  set_hl((uint16_t)(hl() + de()));
  b = h;
  c = l;
  p00_L_18BC();
  set_hl(0x0003);
  mem_write16(0x8D1F, hl());
  return;
  lab_p03_L_6768: ;
  mem_write16(0x8D1F, hl());
  flag_cmp(a, 0x02);
  if (flag_z()) { p00_L_2315(); return; }
  if (flag_c()) { p00_L_22D9(); return; }
  flag_cmp(a, 0x04);
  if (flag_z()) { p00_L_22FC(); return; }
  if (flag_c()) { p00_L_2324(); return; }
  p00_L_22CF();
  return;
}

/* flash page 3 cpu 0x67AF (offset 0x27AF) */
void p03_L_67AF(void) {
  a = mem_read8(0x8E63);
  p03_L_67B2();
  return;
}

/* flash page 3 cpu 0x67B2 (offset 0x27B2) */
void p03_L_67B2(void) {
  a = (uint8_t)(a + a);
  e = a;
  d = 0x00;
  set_hl(0x67C5);
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  cpu_push_hl();
  set_bc(0xFFF0);
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  a = a & 0x0F;
  flag_logic(a);
  cpu_pop_hl();
  return;
}

/* flash page 3 cpu 0x67CD (offset 0x27CD) */
void p03_L_67CD(void) {
  a = mem_read8(hl());
  flag_cmp(a, 0x0F);
  if (flag_z()) return;
  set_de(mem_read16(0x8D18));
  cpu_push_de();
  p03_L_6692();
  cpu_push_de();
  p00_L_19C5();
  c = a;
  c = (uint8_t)(c - 1);
  set_hl(0x8479);
  a = mem_read8(0x847A);
  flag_cmp(a, 0x06);
  if (flag_nc()) goto lab_p03_L_67EB;
  c = (uint8_t)(c + 1);
  set_hl((uint16_t)(hl() - 1));
  lab_p03_L_67EB: ;
  b = 0x00;
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 4)));
  p00_L_34E9();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 4)));
  cpu_pop_hl();
  cpu_pop_de();
  mem_write16(0x8D18, de());
  return;
}

/* flash page 3 cpu 0x67FF (offset 0x27FF) */
void p03_L_67FF(void) {
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p03_L_6847;
  set_hl(0x0000);
  mem_write16(0x86D7, hl());
  a = 0x50;
  p00_L_3D47();
  cpu_pop_af();
  cpu_push_af();
  p00_L_34EF();
  a = 0x3A;
  p00_L_3D47();
  cpu_pop_af();
  p03_L_67B2();
  cpu_push_af();
  set_de(0xFFF1);
  set_hl((uint16_t)(hl() + de()));
  p03_L_67CD();
  cpu_pop_af();
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p03_L_683D;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p03_L_6868;
  set_de(0x0005);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  flag_cmp(a, 0x31);
  if (flag_z()) goto lab_p03_L_6868;
  lab_p03_L_683D: ;
  a = 0x2C;
  p00_L_3D47();
  p03_L_67CD();
  goto lab_p03_L_6868;
  lab_p03_L_6847: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p03_L_684F;
  cpu_pop_af();
  return;
  lab_p03_L_684F: ;
  set_hl(0x0056);
  p00_L_18B7();
  if (flag_z()) goto lab_p03_L_6859;
  l = 0x26;
  lab_p03_L_6859: ;
  mem_write16(0x86D7, hl());
  p00_L_34F5();
  a = 0x50;
  p00_L_3D47();
  cpu_pop_af();
  p00_L_34EF();
  lab_p03_L_6868: ;
  p03_L_67AF();
  flag_cmp(a, 0x05);
  if (flag_z()) { p00_L_34FB(); return; }
  flag_cmp(a, 0x02);
  if (flag_c()) { p00_L_34FB(); return; }
  if (flag_z()) goto lab_p03_L_687C;
  flag_cmp(a, 0x04);
  if (flag_nz()) { p00_L_3501(); return; }
  lab_p03_L_687C: ;
  p00_L_3507();
  return;
}

/* flash page 3 cpu 0x6854 (offset 0x2854) */
void p03_L_6854(void) {
  goto lab_p03_L_687E;
  lab_p03_L_687E: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p03_L_687F();
  return;
}

/* flash page 3 cpu 0x687F (offset 0x287F) */
void p03_L_687F(void) {
  goto lab_p03_L_687F;
  lab_p03_L_66EC: ;
  p03_L_627F();
  p03_L_66EF();
  return;
  lab_p03_L_677E: ;
  mem_write16(0x8D1F, bc());
  p03_L_63A5();
  l = c;
  h = b;
  cpu_pop_af();
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p03_L_679A;
  p03_L_6AD6();
  p00_L_21E0();
  p00_L_34DD();
  p00_L_219B();
  goto lab_p03_L_67A9;
  lab_p03_L_679A: ;
  cpu_push_hl();
  p00_L_3AF5();
  p00_L_34DD();
  set_de(mem_read16(0x9192));
  cpu_pop_hl();
  p00_L_3AF5();
  lab_p03_L_67A9: ;
  p00_L_34D7();
  p03_L_6716();
  return;
  lab_p03_L_687F: ;
  p00_L_3EFD();
  p00_L_34D1();
  p03_L_67B2();
  set_hl(mem_read16(0x8E65));
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p03_L_6893;
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p03_L_68B6;
  lab_p03_L_6893: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x8E65, hl());
  cpu_push_af();
  a = 0;
  flag_logic(a);
  mem_write8(0x8D1E, a);
  set_hl(mem_read16(0x918E));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  cpu_ex_de_hl();
  set_bc(mem_read16(0x8E65));
  lab_p03_L_68A8: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nc()) goto lab_p03_L_677E;
  set_hl((uint16_t)(hl() + bc()));
  set_bc((uint16_t)(bc() - 1));
  mem_write16(0x8E65, bc());
  goto lab_p03_L_68A8;
  lab_p03_L_68B6: ;
  if (flag_z()) goto lab_p03_L_68BD;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p03_L_66EC;
  lab_p03_L_68BD: ;
  p03_L_691B();
  if (flag_z()) goto lab_p03_L_6907;
  set_hl((uint16_t)(hl() + 1));
  goto lab_p03_L_6904;
  lab_p03_L_6904: ;
  mem_write16(0x8E65, hl());
  lab_p03_L_6907: ;
  p03_L_672A();
  return;
}

/* flash page 3 cpu 0x68CD (offset 0x28CD) */
void p03_L_68CD(void) {
  goto lab_p03_L_68CD;
  lab_p03_L_677E: ;
  mem_write16(0x8D1F, bc());
  p03_L_63A5();
  l = c;
  h = b;
  cpu_pop_af();
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p03_L_679A;
  p03_L_6AD6();
  p00_L_21E0();
  p00_L_34DD();
  p00_L_219B();
  goto lab_p03_L_67A9;
  lab_p03_L_679A: ;
  cpu_push_hl();
  p00_L_3AF5();
  p00_L_34DD();
  set_de(mem_read16(0x9192));
  cpu_pop_hl();
  p00_L_3AF5();
  lab_p03_L_67A9: ;
  p00_L_34D7();
  p03_L_6716();
  return;
  lab_p03_L_6897: ;
  cpu_push_af();
  a = 0;
  flag_logic(a);
  mem_write8(0x8D1E, a);
  set_hl(mem_read16(0x918E));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  cpu_ex_de_hl();
  set_bc(mem_read16(0x8E65));
  lab_p03_L_68A8: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nc()) goto lab_p03_L_677E;
  set_hl((uint16_t)(hl() + bc()));
  set_bc((uint16_t)(bc() - 1));
  mem_write16(0x8E65, bc());
  goto lab_p03_L_68A8;
  lab_p03_L_68CD: ;
  h = (uint8_t)(h - 1);
  mem_write16(0x84E7, de());
  a = 0x05;
  goto lab_p03_L_6897;
}

/* flash page 3 cpu 0x68D6 (offset 0x28D6) */
void p03_L_68D6(void) {
  goto lab_p03_L_68D6;
  lab_p03_L_677E: ;
  mem_write16(0x8D1F, bc());
  p03_L_63A5();
  l = c;
  h = b;
  cpu_pop_af();
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p03_L_679A;
  p03_L_6AD6();
  p00_L_21E0();
  p00_L_34DD();
  p00_L_219B();
  goto lab_p03_L_67A9;
  lab_p03_L_679A: ;
  cpu_push_hl();
  p00_L_3AF5();
  p00_L_34DD();
  set_de(mem_read16(0x9192));
  cpu_pop_hl();
  p00_L_3AF5();
  lab_p03_L_67A9: ;
  p00_L_34D7();
  p03_L_6716();
  return;
  lab_p03_L_6894: ;
  mem_write16(0x8E65, hl());
  lab_p03_L_6897: ;
  cpu_push_af();
  a = 0;
  flag_logic(a);
  mem_write8(0x8D1E, a);
  set_hl(mem_read16(0x918E));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  cpu_ex_de_hl();
  set_bc(mem_read16(0x8E65));
  lab_p03_L_68A8: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nc()) goto lab_p03_L_677E;
  set_hl((uint16_t)(hl() + bc()));
  set_bc((uint16_t)(bc() - 1));
  mem_write16(0x8E65, bc());
  goto lab_p03_L_68A8;
  lab_p03_L_68D6: ;
  p00_L_3EFD();
  p00_L_34D1();
  p03_L_67B2();
  set_hl(mem_read16(0x8E65));
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p03_L_68EA;
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p03_L_68F3;
  lab_p03_L_68EA: ;
  set_hl((uint16_t)(hl() - 1));
  b = a;
  a = h;
  a = a | l;
  flag_logic(a);
  a = b;
  if (flag_nz()) goto lab_p03_L_6894;
  goto lab_p03_L_6897;
  lab_p03_L_68F3: ;
  if (flag_z()) goto lab_p03_L_68FF;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p03_L_68FF;
  p03_L_6298();
  p03_L_66EF();
  return;
  lab_p03_L_68FF: ;
  p03_L_690A();
  if (flag_z()) goto lab_p03_L_6907;
  mem_write16(0x8E65, hl());
  lab_p03_L_6907: ;
  p03_L_672A();
  return;
}

/* flash page 3 cpu 0x690A (offset 0x290A) */
void p03_L_690A(void) {
  set_hl((uint16_t)(hl() - 1));
  cpu_push_hl();
  p00_L_2262();
  cpu_pop_hl();
  cpu_push_hl();
  set_de(mem_read16(0x8483));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  cpu_pop_hl();
  return;
}

/* flash page 3 cpu 0x691B (offset 0x291B) */
void p03_L_691B(void) {
  cpu_push_hl();
  p00_L_2262();
  set_de(mem_read16(0x8487));
  set_hl(0x0005);
  set_hl((uint16_t)(hl() + de()));
  set_de(mem_read16(0x8485));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_ex_de_hl();
  cpu_pop_hl();
  p00_L_192A();
  return;
}

/* flash page 3 cpu 0x6933 (offset 0x2933) */
void p03_L_6933(void) {
  a = 0x03;
  mem_write8(0x8E63, a);
  a = 0;
  flag_logic(a);
  cpu_push_af();
  lab_p03_L_693A: ;
  p03_L_67AF();
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  set_hl(0x8E63);
  if (flag_z()) goto lab_p03_L_6952;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p03_L_694C;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p03_L_6952;
  lab_p03_L_694C: ;
  cpu_pop_af();
  p00_L_12B9();
  /* or (hl) */
  cpu_push_af();
  lab_p03_L_6952: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) goto lab_p03_L_693A;
  cpu_pop_af();
  mem_write8(0x8E64, a);
  return;
}

/* flash page 3 cpu 0x695A (offset 0x295A) */
void p03_L_695A(void) {
  cpu_pop_hl();
  b = a;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x7F);
  if (flag_z()) goto lab_p03_L_6967;
  flag_cmp(a, 0x51);
  if (flag_nz()) goto lab_p03_L_6987;
  lab_p03_L_6967: ;
  a = b;
  os_jp_hl();
  return;
  lab_p03_L_6987: ;
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 3 cpu 0x6969 (offset 0x2969) */
void p03_L_6969(void) {
  cpu_push_af();
  p03_L_67B2();
  b = a;
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p03_L_697C;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x7F);
  if (flag_nz()) goto lab_p03_L_697C;
  cpu_pop_af();
  flag_cmp(a, a);
  return;
  lab_p03_L_697C: ;
  cpu_pop_af();
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  return;
}

/* flash page 3 cpu 0x6980 (offset 0x2980) */
void p03_L_6980(void) {
  p03_L_695A();
  flag_cmp(a, 0x03);
  if (flag_nz()) { p03_L_6989(); return; }
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 3 cpu 0x6989 (offset 0x2989) */
void p03_L_6989(void) {
  goto lab_p03_L_6989;
  lab_p03_L_6983: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p03_L_6989;
  a = 0;
  flag_logic(a);
  return;
  lab_p03_L_6989: ;
  a = (uint8_t)(a + 1);
  p03_L_6969();
  if (flag_z()) goto lab_p03_L_6983;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 3 cpu 0x6991 (offset 0x2991) */
void p03_L_6991(void) {
  goto lab_p03_L_6991;
  lab_p03_L_6987: ;
  a = 0;
  flag_logic(a);
  return;
  lab_p03_L_6991: ;
  p03_L_695A();
  lab_p03_L_6994: ;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p03_L_6987;
  a = (uint8_t)(a - 1);
  p03_L_6969();
  if (flag_z()) goto lab_p03_L_6994;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 3 cpu 0x69A0 (offset 0x29A0) */
void p03_L_69A0(void) {
  p03_L_67B2();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p03_L_69B4;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p03_L_69AF;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p03_L_69BA;
  lab_p03_L_69AF: ;
  set_de(0x0036);
  goto lab_p03_L_69B7;
  lab_p03_L_69B4: ;
  set_de(0x0024);
  lab_p03_L_69B7: ;
  p00_L_21B6();
  lab_p03_L_69BA: ;
  a = mem_read8(0x8E63);
  return;
}

/* flash page 3 cpu 0x69BE (offset 0x29BE) */
void p03_L_69BE(void) {
  cpu_push_hl();
  set_hl(mem_read16(0x84B7));
  set_hl((uint16_t)(hl() + bc()));
  b = h;
  c = l;
  cpu_pop_hl();
  p03_L_69C6();
  return;
}

/* flash page 3 cpu 0x69C6 (offset 0x29C6) */
void p03_L_69C6(void) {
  set_de(mem_read16(0x84D9));
  /* sla c */
  /* rl b */
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + bc()));
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), d);
  return;
}

/* flash page 3 cpu 0x69D4 (offset 0x29D4) */
void p03_L_69D4(void) {
  set_hl(mem_read16(0x84B7));
  set_hl((uint16_t)(hl() + bc()));
  b = h;
  c = l;
  p03_L_69DA();
  return;
}

/* flash page 3 cpu 0x69DA (offset 0x29DA) */
void p03_L_69DA(void) {
  set_de(mem_read16(0x84D9));
  p03_L_69DE();
  return;
}

/* flash page 3 cpu 0x69DE (offset 0x29DE) */
void p03_L_69DE(void) {
  /* sla c */
  /* rl b */
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + bc()));
  p00_L_0033();
  return;
}

/* flash page 3 cpu 0x69E7 (offset 0x29E7) */
void p03_L_69E7(void) {
  a = mem_read8(0x8E63);
  a = (uint8_t)(a + 0x26);
  mem_write8(0x8479, a);
  set_de(0x0000);
  mem_write16(0x847A, de());
  return;
}

/* flash page 3 cpu 0x69F7 (offset 0x29F7) */
void p03_L_69F7(void) {
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x84B3, hl());
  set_de((uint16_t)(de() - 1));
  mem_write16(0x84B7, de());
  /* sra h */
  /* rr l */
  if (flag_z()) return;
  set_hl((uint16_t)(hl() + 1));
  p03_L_6A09();
  return;
}

/* flash page 3 cpu 0x6A09 (offset 0x2A09) */
void p03_L_6A09(void) {
  lab_p03_L_6A09: ;
  set_de(0x0002);
  p00_L_192A();
  if (flag_nc()) goto lab_p03_L_6A3D;
  cpu_push_hl();
  set_bc(mem_read16(0x84B3));
  cpu_push_bc();
  p03_L_69D4();
  mem_write16(0x84B5, hl());
  set_bc(0x0001);
  p03_L_69D4();
  cpu_pop_bc();
  cpu_push_bc();
  p03_L_69BE();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x84B3, hl());
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p03_L_6A47;
  set_bc(0x0001);
  set_hl(mem_read16(0x84B5));
  p03_L_69BE();
  cpu_pop_hl();
  return;
  lab_p03_L_6A3D: ;
  set_hl((uint16_t)(hl() - 1));
  cpu_push_hl();
  cpu_pop_bc();
  cpu_push_bc();
  p03_L_69D4();
  mem_write16(0x84B5, hl());
  lab_p03_L_6A47: ;
  cpu_pop_hl();
  cpu_push_hl();
  mem_write16(0x84B1, hl());
  set_hl((uint16_t)(hl() + hl()));
  lab_p03_L_6A4D: ;
  mem_write16(0x84AF, hl());
  set_de(mem_read16(0x84B3));
  p00_L_192A();
  if (flag_z()) goto lab_p03_L_6A5B;
  if (flag_nc()) goto lab_p03_L_6AAA;
  lab_p03_L_6A5B: ;
  cpu_push_af();
  cpu_push_hl();
  cpu_pop_bc();
  cpu_push_bc();
  p03_L_69D4();
  p00_L_3B01();
  cpu_pop_bc();
  cpu_pop_af();
  if (flag_z()) goto lab_p03_L_6A77;
  set_bc((uint16_t)(bc() + 1));
  p03_L_69D4();
  p00_L_3E6D();
  p00_L_107E();
  if (flag_z()) goto lab_p03_L_6A77;
  if (flag_nc()) goto lab_p03_L_6A7C;
  lab_p03_L_6A77: ;
  p00_L_1179();
  goto lab_p03_L_6A83;
  lab_p03_L_6A7C: ;
  set_hl(mem_read16(0x84AF));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x84AF, hl());
  lab_p03_L_6A83: ;
  set_hl(mem_read16(0x84B5));
  p00_L_3B01();
  p00_L_107E();
  if (flag_c()) goto lab_p03_L_6AA4;
  set_bc(mem_read16(0x84AF));
  cpu_push_bc();
  p03_L_69D4();
  set_bc(mem_read16(0x84B1));
  p03_L_69BE();
  cpu_pop_hl();
  mem_write16(0x84B1, hl());
  set_hl((uint16_t)(hl() + hl()));
  goto lab_p03_L_6A4D;
  lab_p03_L_6AA4: ;
  set_hl(mem_read16(0x84B3));
  set_hl((uint16_t)(hl() + 1));
  goto lab_p03_L_6A4D;
  lab_p03_L_6AAA: ;
  set_hl(mem_read16(0x84B5));
  set_bc(mem_read16(0x84B1));
  p03_L_69BE();
  cpu_pop_hl();
  goto lab_p03_L_6A09;
}

/* flash page 3 cpu 0x6AB8 (offset 0x2AB8) */
void p03_L_6AB8(void) {
  p03_L_59B1();
  set_hl(0x0FC3);
  p00_rst20();
  p00_L_0C13();
  set_hl(mem_read16(0x918E));
  p00_L_0033();
  p03_L_59B1();
  p00_L_0ED0();
  a = 0x1E;
  p00_L_396F();
  p00_L_0E4C();
  return;
}

/* flash page 3 cpu 0x6AD6 (offset 0x2AD6) */
void p03_L_6AD6(void) {
  cpu_push_hl();
  p03_L_6AB8();
  p00_rst08();
  set_de(mem_read16(0x84E7));
  cpu_pop_bc();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  p03_L_69DE();
  set_de(mem_read16(0x918E));
  p00_L_3AF5();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 6)) == 0);
  if (flag_z()) p00_L_14B0();
  return;
}

/* flash page 3 cpu 0x6AF7 (offset 0x2AF7) */
void p03_L_6AF7(void) {
  set_hl(mem_read16(0x918E));
  mem_write16(0x84D3, hl());
  return;
}

/* flash page 3 cpu 0x6B07 (offset 0x2B07) */
void p03_L_6B07(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 7)) == 0);
  return;
}

/* flash page 3 cpu 0x6C61 (offset 0x2C61) */
void p03_L_6C61(void) {
  /* rr (hl) */
  p03_L_6C63();
  return;
}

/* flash page 3 cpu 0x6C63 (offset 0x2C63) */
void p03_L_6C63(void) {
  /* adc a,0x3E */
  p03_L_6C65();
  return;
}

/* flash page 3 cpu 0x6C65 (offset 0x2C65) */
void p03_L_6C65(void) {
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_6C75;
  set_hl((uint16_t)(hl() + sp));
  b = 0x1E;
  flag_set_z((mem_read8(hl()) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p03_L_6C83;
  a = (uint8_t)(a + a);
  c = 0x54;
  b = 0x12;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  lab_p03_L_6C75: ;
  if (flag_nz()) goto lab_p03_L_6C83;
  a = (uint8_t)(a + a);
  b = 0x24;
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p03_L_6C83;
  a = (uint8_t)(a + a);
  c = 0x66;
  b = 0x06;
  lab_p03_L_6C83: ;
  cpu_push_af();
  cpu_push_bc();
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  cpu_sbc_hl_bc();
  cpu_pop_bc();
  c = b;
  b = 0x00;
  cpu_sbc_hl_bc();
  cpu_pop_bc();
  cpu_push_hl();
  a = mem_read8((uint16_t)(iy + 0x02));
  c = a;
  cpu_push_bc();
  a = a & 0x0F;
  flag_logic(a);
  a = a | b;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x02), a);
  p00_L_350D();
  set_de(mem_read16(0x848E));
  p00_L_21A4();
  cpu_pop_bc();
  cpu_pop_hl();
  a = mem_read8(0x8490);
  p00_L_01A2();
  if (flag_z()) goto lab_p03_L_6CB4;
  /* srl a */
  lab_p03_L_6CB4: ;
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p03_L_6CD0;
  if (flag_z()) goto lab_p03_L_6CD0;
  cpu_push_bc();
  mem_write16(0x8493, hl());
  set_hl(0x6D97);
  p00_L_25A2();
  set_hl(mem_read16(0x8493));
  p00_L_23BD();
  p00_L_25C8();
  cpu_pop_bc();
  lab_p03_L_6CD0: ;
  p00_L_0087();
  flag_set_z((b & (1u << 4)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_3843();
  cpu_pop_bc();
  flag_set_z((b & (1u << 5)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_384F();
  cpu_pop_bc();
  flag_set_z((b & (1u << 6)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_3849();
  cpu_pop_bc();
  flag_set_z((b & (1u << 7)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_3855();
  cpu_pop_bc();
  a = 0x05;
  p00_L_351F();
  set_hl(mem_read16(0x84DD));
  p03_L_6E19();
  if (flag_nz()) goto lab_p03_L_6CFD;
  set_hl((uint16_t)(hl() + 1));
  lab_p03_L_6CFD: ;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  mem_write8((uint16_t)(iy + 0x04), a);
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = (uint8_t)(a & ~(1u << 7));
  p03_L_6E19();
  if (flag_z()) goto lab_p03_L_6D0F;
  a = a & 0x01;
  flag_logic(a);
  lab_p03_L_6D0F: ;
  mem_write8((uint16_t)(iy + 0x0F), a);
  p03_L_6E19();
  if (flag_nz()) goto lab_p03_L_6D25;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 0)));
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) goto lab_p03_L_6D25;
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) | (1u << 0)));
  lab_p03_L_6D25: ;
  set_hl((uint16_t)(hl() + 1));
  set_de(0x8F50);
  set_bc(0x0036);
  while (bc() != 0) { cpu_ldi(); }
  p03_L_6E19();
  if (flag_z()) goto lab_p03_L_6D47;
  p00_L_0013();
  if (flag_nz()) goto lab_p03_L_6D58;
  p00_L_019D();
  if (flag_z()) goto lab_p03_L_6D47;
  set_de(0x8FBC);
  set_bc(0x002D);
  while (bc() != 0) { cpu_ldi(); }
  goto lab_p03_L_6D64;
  lab_p03_L_6D47: ;
  p03_L_6D9E();
  cpu_ex_de_hl();
  while (bc() != 0) { cpu_ldi(); }
  p00_L_019D();
  if (flag_z()) goto lab_p03_L_6D58;
  set_de(0x9016);
  p00_L_1183();
  lab_p03_L_6D58: ;
  p03_L_6E19();
  if (flag_nz()) goto lab_p03_L_6D64;
  cpu_ex_de_hl();
  p03_L_6DC1();
  cpu_ex_de_hl();
  while (bc() != 0) { cpu_ldi(); }
  lab_p03_L_6D64: ;
  mem_write16(0x84DD, hl());
  a = 0;
  flag_logic(a);
  cpu_pop_bc();
  lab_p03_L_6D69: ;
  cpu_push_bc();
  set_hl(mem_read16(0x84DD));
  a = (uint8_t)(a + 1);
  cpu_push_af();
  p00_L_385B();
  set_hl(mem_read16(0x84DD));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p03_L_6DE3();
  p00_L_01A2();
  if (flag_z()) goto lab_p03_L_6D91;
  cpu_pop_af();
  cpu_push_af();
  p00_L_385B();
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  set_hl(mem_read16(0x84DD));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p03_L_6DE3();
  lab_p03_L_6D91: ;
  cpu_pop_af();
  cpu_pop_bc();
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p03_L_6D69;
  return;
}

/* flash page 3 cpu 0x6C69 (offset 0x2C69) */
void p03_L_6C69(void) {
  e = 0xCB;
  h = mem_read8(hl());
  if (flag_nz()) goto lab_p03_L_6C83;
  a = (uint8_t)(a + a);
  c = 0x54;
  b = 0x12;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p03_L_6C83;
  a = (uint8_t)(a + a);
  b = 0x24;
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p03_L_6C83;
  a = (uint8_t)(a + a);
  c = 0x66;
  b = 0x06;
  lab_p03_L_6C83: ;
  cpu_push_af();
  cpu_push_bc();
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  cpu_sbc_hl_bc();
  cpu_pop_bc();
  c = b;
  b = 0x00;
  cpu_sbc_hl_bc();
  cpu_pop_bc();
  cpu_push_hl();
  a = mem_read8((uint16_t)(iy + 0x02));
  c = a;
  cpu_push_bc();
  a = a & 0x0F;
  flag_logic(a);
  a = a | b;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x02), a);
  p00_L_350D();
  set_de(mem_read16(0x848E));
  p00_L_21A4();
  cpu_pop_bc();
  cpu_pop_hl();
  a = mem_read8(0x8490);
  p00_L_01A2();
  if (flag_z()) goto lab_p03_L_6CB4;
  /* srl a */
  lab_p03_L_6CB4: ;
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p03_L_6CD0;
  if (flag_z()) goto lab_p03_L_6CD0;
  cpu_push_bc();
  mem_write16(0x8493, hl());
  set_hl(0x6D97);
  p00_L_25A2();
  set_hl(mem_read16(0x8493));
  p00_L_23BD();
  p00_L_25C8();
  cpu_pop_bc();
  lab_p03_L_6CD0: ;
  p00_L_0087();
  flag_set_z((b & (1u << 4)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_3843();
  cpu_pop_bc();
  flag_set_z((b & (1u << 5)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_384F();
  cpu_pop_bc();
  flag_set_z((b & (1u << 6)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_3849();
  cpu_pop_bc();
  flag_set_z((b & (1u << 7)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_3855();
  cpu_pop_bc();
  a = 0x05;
  p00_L_351F();
  set_hl(mem_read16(0x84DD));
  p03_L_6E19();
  if (flag_nz()) goto lab_p03_L_6CFD;
  set_hl((uint16_t)(hl() + 1));
  lab_p03_L_6CFD: ;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  mem_write8((uint16_t)(iy + 0x04), a);
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = (uint8_t)(a & ~(1u << 7));
  p03_L_6E19();
  if (flag_z()) goto lab_p03_L_6D0F;
  a = a & 0x01;
  flag_logic(a);
  lab_p03_L_6D0F: ;
  mem_write8((uint16_t)(iy + 0x0F), a);
  p03_L_6E19();
  if (flag_nz()) goto lab_p03_L_6D25;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 0)));
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) goto lab_p03_L_6D25;
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) | (1u << 0)));
  lab_p03_L_6D25: ;
  set_hl((uint16_t)(hl() + 1));
  set_de(0x8F50);
  set_bc(0x0036);
  while (bc() != 0) { cpu_ldi(); }
  p03_L_6E19();
  if (flag_z()) goto lab_p03_L_6D47;
  p00_L_0013();
  if (flag_nz()) goto lab_p03_L_6D58;
  p00_L_019D();
  if (flag_z()) goto lab_p03_L_6D47;
  set_de(0x8FBC);
  set_bc(0x002D);
  while (bc() != 0) { cpu_ldi(); }
  goto lab_p03_L_6D64;
  lab_p03_L_6D47: ;
  p03_L_6D9E();
  cpu_ex_de_hl();
  while (bc() != 0) { cpu_ldi(); }
  p00_L_019D();
  if (flag_z()) goto lab_p03_L_6D58;
  set_de(0x9016);
  p00_L_1183();
  lab_p03_L_6D58: ;
  p03_L_6E19();
  if (flag_nz()) goto lab_p03_L_6D64;
  cpu_ex_de_hl();
  p03_L_6DC1();
  cpu_ex_de_hl();
  while (bc() != 0) { cpu_ldi(); }
  lab_p03_L_6D64: ;
  mem_write16(0x84DD, hl());
  a = 0;
  flag_logic(a);
  cpu_pop_bc();
  lab_p03_L_6D69: ;
  cpu_push_bc();
  set_hl(mem_read16(0x84DD));
  a = (uint8_t)(a + 1);
  cpu_push_af();
  p00_L_385B();
  set_hl(mem_read16(0x84DD));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p03_L_6DE3();
  p00_L_01A2();
  if (flag_z()) goto lab_p03_L_6D91;
  cpu_pop_af();
  cpu_push_af();
  p00_L_385B();
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  set_hl(mem_read16(0x84DD));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p03_L_6DE3();
  lab_p03_L_6D91: ;
  cpu_pop_af();
  cpu_pop_bc();
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p03_L_6D69;
  return;
}

/* flash page 3 cpu 0x6D9E (offset 0x2D9E) */
void p03_L_6D9E(void) {
  cpu_ex_de_hl();
  p03_L_6D9F();
  return;
}

/* flash page 3 cpu 0x6D9F (offset 0x2D9F) */
void p03_L_6D9F(void) {
  set_hl(0x900D);
  set_bc(0x0009);
  p00_L_0013();
  if (flag_nz()) return;
  set_hl(0x8F86);
  set_bc(0x001B);
  p00_L_0198();
  if (flag_nz()) return;
  set_hl(0x8FA1);
  p00_L_01A2();
  if (flag_nz()) return;
  set_bc(0x0051);
  set_hl(0x8FBC);
  return;
}

/* flash page 3 cpu 0x6DC1 (offset 0x2DC1) */
void p03_L_6DC1(void) {
  set_bc(0x0006);
  set_hl(0x9786);
  p00_L_0198();
  if (flag_nz()) return;
  set_hl(0x9780);
  p00_L_01A2();
  if (flag_nz()) return;
  set_bc(0x000A);
  set_hl(0x9776);
  p00_L_0013();
  if (flag_nz()) return;
  set_bc(0x0003);
  set_hl(0x978C);
  return;
}

/* flash page 3 cpu 0x6DE3 (offset 0x2DE3) */
void p03_L_6DE3(void) {
  cpu_push_af();
  p03_L_6E19();
  if (flag_z()) goto lab_p03_L_6DF5;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x82);
  if (flag_nz()) goto lab_p03_L_6DF5;
  p00_L_1C9D();
  cpu_pop_af();
  return;
  lab_p03_L_6DF5: ;
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x84DD, hl());
  cpu_ex_de_hl();
  cpu_push_hl();
  p00_L_1CA8();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_pop_bc();
  cpu_push_hl();
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_6E11;
  set_hl(mem_read16(0x84DD));
  while (bc() != 0) { cpu_ldi(); }
  mem_write16(0x84DD, hl());
  lab_p03_L_6E11: ;
  cpu_pop_hl();
  cpu_pop_af();
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) return;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  return;
}

/* flash page 3 cpu 0x6E19 (offset 0x2E19) */
void p03_L_6E19(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 1)) == 0);
  return;
}

/* flash page 3 cpu 0x6E2F (offset 0x2E2F) */
void p03_L_6E2F(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x3C)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p03_L_6E39;
  p00_L_352B();
  return;
  lab_p03_L_6E39: ;
  set_hl(mem_read16(0x9824));
  mem_write16(0x9196, hl());
  p00_L_128A();
  p00_rst18();
  a = 0x60;
  mem_write8(0x847A, a);
  /* bit 2,(iy) */
  if (flag_z()) p00_L_0D00();
  p00_rst18();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  b = 0x3D;
  cpu_push_bc();
  set_hl(mem_read16(0x9196));
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  p00_rst20();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p03_L_6E61();
  return;
}

/* flash page 3 cpu 0x6E61 (offset 0x2E61) */
void p03_L_6E61(void) {
  goto lab_p03_L_6E61;
  lab_p03_L_6E56: ;
  cpu_push_bc();
  set_hl(mem_read16(0x9196));
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  p00_rst20();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  lab_p03_L_6E61: ;
  p00_L_1183();
  set_hl(0x6ED3);
  p00_L_25A2();
  p00_L_3ACB();
  p00_L_10DD();
  set_hl(mem_read16(0x9196));
  set_de(0xFFEE);
  set_hl((uint16_t)(hl() + de()));
  p00_rst20();
  p00_rst30();
  p00_L_10EF();
  p00_L_10DD();
  set_hl(mem_read16(0x9196));
  set_de(0xFFE5);
  set_hl((uint16_t)(hl() + de()));
  p00_rst20();
  p00_rst30();
  p00_L_10EF();
  p00_L_25C8();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p03_L_6E9D;
  p00_L_222C();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  goto lab_p03_L_6EB4;
  lab_p03_L_6E9D: ;
  set_de(0x848E);
  p00_L_2318();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1183();
  p00_L_235C();
  set_de(0x8483);
  p00_L_2340();
  p03_L_5A3B();
  lab_p03_L_6EB4: ;
  set_hl(mem_read16(0x9196));
  p00_rst20();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1183();
  p00_rst30();
  set_de(mem_read16(0x9196));
  p00_L_11FD();
  cpu_pop_bc();
  p00_L_0189();
  if (flag_nz()) goto lab_p03_L_6ECD;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_6E56;
  lab_p03_L_6ECD: ;
  set_de(0x003F);
  p00_L_21B6();
  return;
}

/* flash page 3 cpu 0x6F6D (offset 0x2F6D) */
void p03_L_6F6D(void) {
  set_hl(mem_read16(0x980C));
  mem_write16(0x9824, hl());
  set_de(0x8E6A);
  p03_L_6F8B();
  set_de(0x8F50);
  p03_L_6F8B();
  set_de(0x8F6B);
  p03_L_6F8B();
  set_de(0x9152);
  p03_L_6F88();
  return;
}

/* flash page 3 cpu 0x6F74 (offset 0x2F74) */
void p03_L_6F74(void) {
  l = d;
  /* adc a,(hl) */
  p03_L_6F8B();
  set_de(0x8F50);
  p03_L_6F8B();
  set_de(0x8F6B);
  p03_L_6F8B();
  set_de(0x9152);
  p03_L_6F88();
  return;
}

/* flash page 3 cpu 0x6F88 (offset 0x2F88) */
void p03_L_6F88(void) {
  p03_L_6F8B();
  p03_L_6F8B();
  return;
}

/* flash page 3 cpu 0x6F8B (offset 0x2F8B) */
void p03_L_6F8B(void) {
  p00_L_1183();
  p00_L_1183();
  return;
}

/* flash page 3 cpu 0x6FCD (offset 0x2FCD) */
void p03_L_6FCD(void) {
  p00_L_018E();
  if (flag_z()) return;
  set_hl(mem_read16(0x9824));
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  a = (uint8_t)(a + 1);
  if (flag_nz()) goto lab_p03_L_6FE2;
  p00_L_235C();
  p00_L_233D();
  return;
  lab_p03_L_6FE2: ;
  p00_L_1171();
  p00_L_2310();
  p00_L_107E();
  if (flag_c()) { p00_L_2352(); return; }
  p00_L_1108();
  p00_L_22FC();
  p00_L_107E();
  if (flag_nc()) return;
  p00_L_113A();
  p00_L_233D();
  return;
}

/* flash page 3 cpu 0x700C (offset 0x300C) */
void p03_L_700C(void) {
  cpu_push_de();
  cpu_push_af();
  cpu_push_hl();
  p00_L_38F1();
  p00_rst18();
  p00_L_353D();
  p00_L_1171();
  set_hl(0x8F6B);
  cpu_pop_de();
  cpu_pop_af();
  cpu_push_af();
  p00_L_3543();
  p00_L_10EF();
  p00_L_2187();
  p00_L_222C();
  set_hl(0x8F50);
  cpu_pop_af();
  cpu_pop_de();
  p00_L_3543();
  p03_L_7033();
  return;
}

/* flash page 3 cpu 0x7033 (offset 0x3033) */
void p03_L_7033(void) {
  p00_L_3549();
  set_de(0x8F50);
  p00_L_11FD();
  set_hl(0x8499);
  p00_L_1183();
  p00_L_2196();
  p00_L_219B();
  set_de(0x8F6B);
  p00_L_11FD();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_1183();
  return;
}

/* flash page 3 cpu 0x7053 (offset 0x3053) */
void p03_L_7053(void) {
  cpu_push_af();
  set_de(0xFFF1);
  set_hl((uint16_t)(hl() + de()));
  p03_L_7070();
  cpu_pop_af();
  flag_cmp(a, 0x05);
  if (flag_z()) return;
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p03_L_706C;
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  flag_cmp(a, 0x31);
  if (flag_z()) return;
  p03_L_7070();
  return;
  lab_p03_L_706C: ;
  p03_L_7070();
  return;
}

/* flash page 3 cpu 0x7070 (offset 0x3070) */
void p03_L_7070(void) {
  cpu_push_hl();
  p03_L_6692();
  p00_L_354F();
  cpu_pop_hl();
  set_bc(0x0005);
  set_hl((uint16_t)(hl() + bc()));
  return;
}

/* flash page 3 cpu 0x707D (offset 0x307D) */
void p03_L_707D(void) {
  set_hl(mem_read16(0x9824));
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  p03_L_7084();
  return;
}

/* flash page 3 cpu 0x7084 (offset 0x3084) */
void p03_L_7084(void) {
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  p00_L_3555();
  return;
}

/* flash page 3 cpu 0x708B (offset 0x308B) */
void p03_L_708B(void) {
  goto lab_p03_L_708B;
  lab_p03_L_6006: ;
  p00_L_3549();
  p00_L_18B7();
  if (flag_z()) goto lab_p03_L_6019;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_34AD();
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 2)));
  lab_p03_L_6019: ;
  set_hl(0x002D);
  p00_L_21C3();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 7)));
  set_hl(0x8F62);
  p00_rst20();
  p00_L_23B3();
  set_hl(0x8F6B);
  p00_rst20();
  p00_L_2375();
  set_hl(0x8F74);
  p00_rst20();
  p00_L_2389();
  a = 0;
  flag_logic(a);
  a = 0x01;
  p03_L_5E3D();
  a = 0x02;
  p03_L_5E3D();
  a = 0x03;
  p03_L_5E3D();
  p03_L_6B07();
  if (flag_z()) goto lab_p03_L_60AB;
  b = 0x05;
  lab_p03_L_6057: ;
  cpu_push_bc();
  p00_L_22D9();
  p00_rst18();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_6057;
  p03_L_60BA();
  p00_L_128A();
  p00_rst18();
  a = 0x01;
  p03_L_6138();
  p03_L_612E();
  a = 0x02;
  p03_L_6138();
  p03_L_612E();
  a = 0x03;
  p03_L_6138();
  p03_L_612E();
  p00_L_219B();
  p00_L_1251();
  a = 0x11;
  mem_write8(0x8485, a);
  a = 0x70;
  mem_write8(0x8486, a);
  p00_L_0D1F();
  p00_L_2389();
  set_hl(0x257F);
  p00_L_17CE();
  if (flag_z()) goto lab_p03_L_609F;
  set_hl(0x807F);
  lab_p03_L_609F: ;
  mem_write16(0x8484, hl());
  p00_L_0D1F();
  p00_L_0E4C();
  p00_L_2375();
  lab_p03_L_60AB: ;
  a = 0x01;
  p03_L_5EFC();
  a = 0x02;
  p03_L_5EFC();
  a = 0x03;
  p03_L_5EFC();
  p03_L_60BA();
  return;
  lab_p03_L_6B0C: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x867D, a);
  set_de(0x867E);
  p00_L_11FD();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x61);
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_L_350D();
  p00_L_1135();
  a = mem_read8(0x8490);
  e = a;
  d = 0x00;
  set_hl(mem_read16(0x848E));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_de(0x0057);
  p00_L_0198();
  if (flag_nz()) goto lab_p03_L_6B4D;
  p00_L_01A2();
  if (flag_nz()) goto lab_p03_L_6B4D;
  set_de(0x0049);
  p00_L_0013();
  if (flag_nz()) goto lab_p03_L_6B4D;
  set_de(0x0093);
  lab_p03_L_6B4D: ;
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  a = mem_read8(0x8478);
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p03_L_6B62;
  p00_L_1CB3();
  mem_write16(0x84DD, de());
  mem_write16(0x981C, hl());
  goto lab_p03_L_6B73;
  lab_p03_L_6B62: ;
  mem_write8(0x8478, a);
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  set_hl(mem_read16(0x981C));
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_0087();
  p00_L_1CFC();
  lab_p03_L_6B73: ;
  set_hl(mem_read16(0x84DD));
  cpu_pop_bc();
  mem_write8(hl(), c);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), b);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8((uint16_t)(iy + 0x02));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8((uint16_t)(iy + 0x04));
  a = (uint8_t)(a & ~(1u << 7));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8((uint16_t)(iy + 0x0F));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8((uint16_t)(iy + 0x18));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  set_hl(0x8F50);
  set_bc(0x0036);
  while (bc() != 0) { cpu_ldi(); }
  p03_L_6D9F();
  while (bc() != 0) { cpu_ldi(); }
  p00_L_019D();
  if (flag_z()) goto lab_p03_L_6BAD;
  set_hl(0x9016);
  p00_L_1183();
  lab_p03_L_6BAD: ;
  p03_L_6DC1();
  while (bc() != 0) { cpu_ldi(); }
  mem_write16(0x84DD, de());
  a = 0;
  flag_logic(a);
  lab_p03_L_6BB7: ;
  p00_L_3513();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p03_L_6BCC;
  set_hl(0x867E);
  p00_rst20();
  p00_rst10();
  p00_L_240B();
  a = mem_read8(0x867D);
  mem_write8(hl(), a);
  p00_L_21A4();
  return;
  lab_p03_L_6BCC: ;
  cpu_push_af();
  lab_p03_L_6BCD: ;
  p00_L_241E();
  cpu_push_hl();
  cpu_push_de();
  p00_L_240A();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  b = mem_read8(hl());
  p00_L_3519();
  d = a;
  a = mem_read8(0x867D);
  flag_cmp(a, d);
  if (flag_nc()) goto lab_p03_L_6BE8;
  a = d;
  mem_write8(0x867D, a);
  lab_p03_L_6BE8: ;
  cpu_pop_de();
  cpu_pop_hl();
  a = mem_read8(hl());
  set_hl(mem_read16(0x84DD));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  set_bc((uint16_t)(bc() + 1));
  set_bc((uint16_t)(bc() + 1));
  while (bc() != 0) { cpu_ldi(); }
  mem_write16(0x84DD, de());
  p00_L_01A2();
  if (flag_z()) goto lab_p03_L_6C0D;
  set_hl(0x847A);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p03_L_6C0D;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  goto lab_p03_L_6BCD;
  lab_p03_L_6C0D: ;
  cpu_pop_af();
  goto lab_p03_L_6BB7;
  lab_p03_L_6C1F: ;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x61);
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_L_1037();
  flag_cmp(a, 0x1F);
  if (flag_z()) { p00_L_24F1(); return; }
  set_hl(mem_read16(0x84DD));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 1)));
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p03_L_6C60;
  a = 0x10;
  c = 0x4C;
  b = 0x1E;
  set_hl((uint16_t)(hl() + 1));
  flag_set_z((mem_read8(hl()) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p03_L_6C83;
  a = (uint8_t)(a + a);
  c = 0x5A;
  b = 0x12;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p03_L_6C83;
  a = (uint8_t)(a + a);
  b = 0x24;
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p03_L_6C83;
  a = (uint8_t)(a + a);
  c = 0x96;
  b = 0x09;
  goto lab_p03_L_6C83;
  lab_p03_L_6C60: ;
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) | (1u << 1)));
  a = 0x10;
  c = 0x39;
  b = 0x1E;
  flag_set_z((mem_read8(hl()) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p03_L_6C83;
  a = (uint8_t)(a + a);
  c = 0x54;
  b = 0x12;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p03_L_6C83;
  a = (uint8_t)(a + a);
  b = 0x24;
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p03_L_6C83;
  a = (uint8_t)(a + a);
  c = 0x66;
  b = 0x06;
  lab_p03_L_6C83: ;
  cpu_push_af();
  cpu_push_bc();
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  cpu_sbc_hl_bc();
  cpu_pop_bc();
  c = b;
  b = 0x00;
  cpu_sbc_hl_bc();
  cpu_pop_bc();
  cpu_push_hl();
  a = mem_read8((uint16_t)(iy + 0x02));
  c = a;
  cpu_push_bc();
  a = a & 0x0F;
  flag_logic(a);
  a = a | b;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x02), a);
  p00_L_350D();
  set_de(mem_read16(0x848E));
  p00_L_21A4();
  cpu_pop_bc();
  cpu_pop_hl();
  a = mem_read8(0x8490);
  p00_L_01A2();
  if (flag_z()) goto lab_p03_L_6CB4;
  /* srl a */
  lab_p03_L_6CB4: ;
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p03_L_6CD0;
  if (flag_z()) goto lab_p03_L_6CD0;
  cpu_push_bc();
  mem_write16(0x8493, hl());
  set_hl(0x6D97);
  p00_L_25A2();
  set_hl(mem_read16(0x8493));
  p00_L_23BD();
  p00_L_25C8();
  cpu_pop_bc();
  lab_p03_L_6CD0: ;
  p00_L_0087();
  flag_set_z((b & (1u << 4)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_3843();
  cpu_pop_bc();
  flag_set_z((b & (1u << 5)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_384F();
  cpu_pop_bc();
  flag_set_z((b & (1u << 6)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_3849();
  cpu_pop_bc();
  flag_set_z((b & (1u << 7)) == 0);
  cpu_push_bc();
  if (flag_nz()) p00_L_3855();
  cpu_pop_bc();
  a = 0x05;
  p00_L_351F();
  set_hl(mem_read16(0x84DD));
  p03_L_6E19();
  if (flag_nz()) goto lab_p03_L_6CFD;
  set_hl((uint16_t)(hl() + 1));
  lab_p03_L_6CFD: ;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  mem_write8((uint16_t)(iy + 0x04), a);
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = (uint8_t)(a & ~(1u << 7));
  p03_L_6E19();
  if (flag_z()) goto lab_p03_L_6D0F;
  a = a & 0x01;
  flag_logic(a);
  lab_p03_L_6D0F: ;
  mem_write8((uint16_t)(iy + 0x0F), a);
  p03_L_6E19();
  if (flag_nz()) goto lab_p03_L_6D25;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 0)));
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) goto lab_p03_L_6D25;
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) | (1u << 0)));
  lab_p03_L_6D25: ;
  set_hl((uint16_t)(hl() + 1));
  set_de(0x8F50);
  set_bc(0x0036);
  while (bc() != 0) { cpu_ldi(); }
  p03_L_6E19();
  if (flag_z()) goto lab_p03_L_6D47;
  p00_L_0013();
  if (flag_nz()) goto lab_p03_L_6D58;
  p00_L_019D();
  if (flag_z()) goto lab_p03_L_6D47;
  set_de(0x8FBC);
  set_bc(0x002D);
  while (bc() != 0) { cpu_ldi(); }
  goto lab_p03_L_6D64;
  lab_p03_L_6D47: ;
  p03_L_6D9E();
  cpu_ex_de_hl();
  while (bc() != 0) { cpu_ldi(); }
  p00_L_019D();
  if (flag_z()) goto lab_p03_L_6D58;
  set_de(0x9016);
  p00_L_1183();
  lab_p03_L_6D58: ;
  p03_L_6E19();
  if (flag_nz()) goto lab_p03_L_6D64;
  cpu_ex_de_hl();
  p03_L_6DC1();
  cpu_ex_de_hl();
  while (bc() != 0) { cpu_ldi(); }
  lab_p03_L_6D64: ;
  mem_write16(0x84DD, hl());
  a = 0;
  flag_logic(a);
  cpu_pop_bc();
  lab_p03_L_6D69: ;
  cpu_push_bc();
  set_hl(mem_read16(0x84DD));
  a = (uint8_t)(a + 1);
  cpu_push_af();
  p00_L_385B();
  set_hl(mem_read16(0x84DD));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p03_L_6DE3();
  p00_L_01A2();
  if (flag_z()) goto lab_p03_L_6D91;
  cpu_pop_af();
  cpu_push_af();
  p00_L_385B();
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  set_hl(mem_read16(0x84DD));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p03_L_6DE3();
  lab_p03_L_6D91: ;
  cpu_pop_af();
  cpu_pop_bc();
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p03_L_6D69;
  return;
  lab_p03_L_6E1E: ;
  p00_L_3525();
  p00_L_0189();
  if (flag_z()) goto lab_p03_L_6E2A;
  lab_p03_L_6E26: ;
  p00_L_34C5();
  return;
  lab_p03_L_6E2A: ;
  p03_L_6E2F();
  goto lab_p03_L_6E26;
  lab_p03_L_6EDD: ;
  set_hl(mem_read16(0x9824));
  mem_write16(0x980C, hl());
  set_hl(0x005A);
  p00_L_21C3();
  set_de(mem_read16(0x980C));
  set_hl(0x8E6A);
  p03_L_6F8B();
  set_hl(0x8F50);
  p03_L_6F8B();
  set_hl(0x8F6B);
  p03_L_6F8B();
  set_hl(0x9152);
  p03_L_6F88();
  set_hl(0x6F91);
  p00_L_25A2();
  p00_L_128A();
  set_de(0x8E6A);
  p00_L_11FD();
  p00_L_11FD();
  set_de(0x8F50);
  p00_L_11FD();
  set_hl(0x6F97);
  p00_L_1183();
  set_de(0x8F6B);
  p00_L_11FD();
  set_hl(0x6FA0);
  p00_L_1183();
  set_de(0x9152);
  p03_L_6F88();
  set_bc(mem_read16(0x8D1A));
  p00_L_3531();
  p00_rst18();
  p00_L_21D6();
  set_bc(mem_read16(0x8D18));
  p00_L_3531();
  p00_L_2310();
  p00_L_0C2D();
  p00_L_0D1E();
  p00_L_1171();
  p00_L_1135();
  p00_L_22F7();
  p00_L_0C2D();
  p00_L_0D1E();
  p00_L_1108();
  p00_rst30();
  p00_L_3A05();
  p00_rst18();
  p03_L_6E2F();
  p00_L_25C8();
  p03_L_6F6D();
  return;
  lab_p03_L_6FFE: ;
  /* scf */
  lab_p03_L_6FFF: ;
  cpu_push_de();
  cpu_push_af();
  cpu_push_hl();
  a = 0x01;
  p00_L_3537();
  p00_L_21D1();
  goto lab_p03_L_7016;
  lab_p03_L_7016: ;
  p00_L_1171();
  set_hl(0x8F6B);
  cpu_pop_de();
  cpu_pop_af();
  cpu_push_af();
  p00_L_3543();
  p00_L_10EF();
  p00_L_2187();
  p00_L_222C();
  set_hl(0x8F50);
  cpu_pop_af();
  cpu_pop_de();
  p00_L_3543();
  p03_L_7033();
  return;
  lab_p03_L_708B: ;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_6EDD;
  flag_cmp(a, 0x8F);
  if (flag_z()) goto lab_p03_L_6006;
  flag_cmp(a, 0x9A);
  if (flag_z()) goto lab_p03_L_6B0C;
  flag_cmp(a, 0x9B);
  if (flag_z()) goto lab_p03_L_6C1F;
  flag_cmp(a, 0xA5);
  if (flag_z()) goto lab_p03_L_6E1E;
  flag_cmp(a, 0x8A);
  if (flag_z()) goto lab_p03_L_6FFF;
  flag_cmp(a, 0x89);
  if (flag_z()) goto lab_p03_L_6FFE;
  return;
}

/* flash page 3 cpu 0x70B1 (offset 0x30B1) */
void p03_L_70B1(void) {
  a = mem_read8(0x8446);
  p03_L_7CBB();
  if (flag_z()) goto lab_p03_L_70BF;
  a = (uint8_t)(a | (1u << 4));
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) | (1u << 4)));
  lab_p03_L_70BF: ;
  mem_write8(0x8D0A, a);
  set_hl(0x7650);
  p00_L_07C1();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  p03_L_70CC();
  return;
}

/* flash page 3 cpu 0x70CC (offset 0x30CC) */
void p03_L_70CC(void) {
  p03_L_71FC();
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  cpu_ex_de_hl();
  a = 0x74;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  set_de(0x848E);
  p00_L_1185();
  p00_L_1185();
  p03_L_43BE();
  p00_L_3D17();
  p03_L_722B();
  a = 0x01;
  mem_write8(0x844B, a);
  p03_L_70F4();
  return;
}

/* flash page 3 cpu 0x70F4 (offset 0x30F4) */
void p03_L_70F4(void) {
  p03_L_74AD();
  set_hl(mem_read16(0x9700));
  a = mem_read8(hl());
  mem_write8(0x8D0B, a);
  p03_L_7264();
  p03_L_7316();
  if (flag_nz()) goto lab_p03_L_710B;
  p03_L_45E3();
  return;
  lab_p03_L_710B: ;
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) | (1u << 5)));
  flag_cmp(a, 0x08);
  if (flag_z()) goto lab_p03_L_7132;
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) & ~(1u << 5)));
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p03_L_7132;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p03_L_7129;
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) | (1u << 1)));
  goto lab_p03_L_7132;
  lab_p03_L_7129: ;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p03_L_71CB;
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) | (1u << 6)));
  lab_p03_L_7132: ;
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) | (1u << 7)));
  p03_L_4A0F();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 6)));
  p00_L_3417();
  set_hl(0x84C9);
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p03_L_7152;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p03_L_7152;
  set_hl(0x84CC);
  lab_p03_L_7152: ;
  mem_write16(0x96FA, hl());
  mem_write16(0x96F8, hl());
  a = mem_read8(0x8D0B);
  p00_L_3E61();
  set_hl((uint16_t)(hl() + 1));
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p03_L_716E;
  a = mem_read8(hl());
  flag_cmp(a, 0x5E);
  if (flag_z()) goto lab_p03_L_7174;
  p00_L_03A4();
  return;
  lab_p03_L_716E: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p03_L_7185;
  lab_p03_L_7174: ;
  set_de(0x84C7);
  p00_L_118B();
  p00_L_03A4();
  p03_L_49FB();
  set_bc(0x0002);
  goto lab_p03_L_7191;
  lab_p03_L_7185: ;
  p00_L_341D();
  p00_L_3423();
  p03_L_49FB();
  p00_L_3429();
  lab_p03_L_7191: ;
  set_hl(mem_read16(0x96FA));
  cpu_sbc_hl_bc();
  mem_write16(0x96F8, hl());
  set_hl(0x84C7);
  set_hl((uint16_t)(hl() + bc()));
  set_hl((uint16_t)(hl() - 1));
  set_de(mem_read16(0x96FA));
  set_de((uint16_t)(de() - 1));
  /* lddr */
  return;
  lab_p03_L_71CB: ;
  a = mem_read8(0x8D0B);
  p03_L_71A6();
  mem_write16(0x97A3, hl());
  a = mem_read8(0x8D0B);
  flag_cmp(a, 0x58);
  if (flag_z()) goto lab_p03_L_71DF;
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) & ~(1u << 4)));
  lab_p03_L_71DF: ;
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  p00_L_03A0();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 4)) == 0);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) & ~(1u << 4)));
  p03_L_7CBB();
  if (flag_z()) return;
  a = 0x01;
  p03_L_7D84();
  return;
}

/* flash page 3 cpu 0x71A6 (offset 0x31A6) */
void p03_L_71A6(void) {
  cpu_push_af();
  a = (uint8_t)(a - 0x52);
  set_hl(0x7AD2);
  p00_L_0732();
  cpu_pop_af();
  flag_cmp(a, 0x58);
  if (flag_c()) goto lab_p03_L_71BA;
  flag_cmp(a, 0x5A);
  if (flag_z()) goto lab_p03_L_71BE;
  goto lab_p03_L_71C2;
  lab_p03_L_71BA: ;
  a = 0x03;
  goto lab_p03_L_71C4;
  lab_p03_L_71BE: ;
  a = 0x01;
  goto lab_p03_L_71C4;
  lab_p03_L_71C2: ;
  a = 0x02;
  lab_p03_L_71C4: ;
  mem_write8(0x97A1, a);
  mem_write16(0x979F, hl());
  return;
}

/* flash page 3 cpu 0x71FC (offset 0x31FC) */
void p03_L_71FC(void) {
  a = mem_read8(0x8D0A);
  /* sla a */
  /* sla a */
  e = a;
  d = 0x00;
  set_hl(0x78AF);
  set_hl((uint16_t)(hl() + de()));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  mem_write16(0x9700, de());
  return;
}

/* flash page 3 cpu 0x7212 (offset 0x3212) */
void p03_L_7212(void) {
  cpu_push16(ix);
  /* ld ix,(0x9700) */
  a = mem_read8(0x844B);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_7235;
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p03_L_7235;
  b = a;
  set_de(0xFFFD);
  lab_p03_L_7225: ;
  /* add ix,de */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_7225;
  goto lab_p03_L_7235;
  lab_p03_L_7235: ;
  a = 0x01;
  mem_write8(0x844B, a);
  lab_p03_L_723A: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = mem_read8(0x844B);
  set_hl(0x97A6);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p03_L_7261;
  a = mem_read8(ix);
  mem_write8(0x8D0B, a);
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p03_L_725E;
  p03_L_7278();
  set_de(0x0003);
  /* add ix,de */
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p03_L_723A;
  lab_p03_L_725E: ;
  p00_L_3D29();
  lab_p03_L_7261: ;
  ix = cpu_pop16();
  return;
}

/* flash page 3 cpu 0x722B (offset 0x322B) */
void p03_L_722B(void) {
  cpu_push16(ix);
  /* ld ix,(0x9700) */
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 5)));
  a = 0x01;
  mem_write8(0x844B, a);
  lab_p03_L_723A: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = mem_read8(0x844B);
  set_hl(0x97A6);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p03_L_7261;
  a = mem_read8(ix);
  mem_write8(0x8D0B, a);
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p03_L_725E;
  p03_L_7278();
  set_de(0x0003);
  /* add ix,de */
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p03_L_723A;
  lab_p03_L_725E: ;
  p00_L_3D29();
  lab_p03_L_7261: ;
  ix = cpu_pop16();
  return;
}

/* flash page 3 cpu 0x7264 (offset 0x3264) */
void p03_L_7264(void) {
  cpu_push_hl();
  p03_L_7265();
  return;
}

/* flash page 3 cpu 0x7265 (offset 0x3265) */
void p03_L_7265(void) {
  a = (uint8_t)(a - 0x47);
  e = a;
  a = 0x00;
  if (flag_c()) goto lab_p03_L_7273;
  d = 0x00;
  set_hl(0x765D);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  lab_p03_L_7273: ;
  mem_write8(0x8D0C, a);
  cpu_pop_hl();
  return;
}

/* flash page 3 cpu 0x7278 (offset 0x3278) */
void p03_L_7278(void) {
  p03_L_7264();
  p03_L_44F5();
  p03_L_4D49();
  a = mem_read8(ix);
  flag_cmp(a, 0x5A);
  if (flag_z()) return;
  flag_cmp(a, 0x5B);
  if (flag_nc()) goto lab_p03_L_72BC;
  flag_cmp(a, 0x54);
  if (flag_z()) goto lab_p03_L_7295;
  a = 0x3A;
  p00_L_3F9F();
  lab_p03_L_7295: ;
  a = mem_read8(ix);
  flag_cmp(a, 0x52);
  if (flag_c()) goto lab_p03_L_72D9;
  p03_L_71A6();
  cpu_push16(ix);
  p03_L_7D48();
  ix = cpu_pop16();
  return;
  lab_p03_L_72BC: ;
  a = 0x20;
  p00_L_3F9F();
  set_hl(0x7A64);
  a = 0x71;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p03_L_4D49();
  if (flag_c()) return;
  a = mem_read8(0x844B);
  a = (uint8_t)(a - 1);
  mem_write8(0x844B, a);
  return;
  lab_p03_L_72D9: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 5)) == 0);
  if (flag_nz()) return;
  p00_L_18A3();
  a = mem_read8(ix);
  flag_cmp(a, 0x51);
  if (flag_nz()) goto lab_p03_L_72F1;
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_nz()) return;
  p03_L_7DBC();
  return;
  lab_p03_L_72F1: ;
  p00_L_1037();
  flag_cmp(a, 0x02);
  if (flag_z()) { p03_L_7DBC(); return; }
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p03_L_7301;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p03_L_7308;
  lab_p03_L_7301: ;
  set_hl(0x8479);
  p00_L_3423();
  return;
  lab_p03_L_7308: ;
  flag_cmp(a, 0x0E);
  if (flag_nz()) goto lab_p03_L_7310;
  a = 0;
  flag_logic(a);
  mem_write8(0x8478, a);
  lab_p03_L_7310: ;
  p00_L_3CC9();
  p03_L_4587();
  return;
}

/* flash page 3 cpu 0x7316 (offset 0x3316) */
void p03_L_7316(void) {
  b = a;
  a = mem_read8(0x8D0C);
  a = a | a;
  flag_logic(a);
  a = b;
  return;
}

/* flash page 3 cpu 0x7369 (offset 0x3369) */
void p03_L_7369(void) {
  p03_L_7474();
  /* ld ix,(0x9700) */
  a = mem_read8((uint16_t)(ix + 0x03));
  p03_L_7373();
  return;
}

/* flash page 3 cpu 0x7373 (offset 0x3373) */
void p03_L_7373(void) {
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p03_L_7392;
  set_de(0x0003);
  /* add ix,de */
  /* ld (0x9700),ix */
  p03_L_4987();
  if (flag_c()) goto lab_p03_L_738F;
  mem_write8(0x844C, a);
  a = mem_read8(ix);
  p03_L_7278();
  goto lab_p03_L_7392;
  lab_p03_L_738F: ;
  mem_write8(0x844B, a);
  lab_p03_L_7392: ;
  p03_L_70F4();
  return;
}

/* flash page 3 cpu 0x73B7 (offset 0x33B7) */
void p03_L_73B7(void) {
  goto lab_p03_L_73B7;
  lab_p03_L_7387: ;
  a = mem_read8(ix);
  p03_L_7278();
  goto lab_p03_L_7392;
  lab_p03_L_738F: ;
  mem_write8(0x844B, a);
  lab_p03_L_7392: ;
  p03_L_70F4();
  return;
  lab_p03_L_73B7: ;
  p03_L_74B9();
  p03_L_7474();
  /* ld ix,(0x9700) */
  /* ld a,(ix-0x03) */
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p03_L_7392;
  set_de(0xFFFD);
  /* add ix,de */
  /* ld (0x9700),ix */
  p03_L_49A6();
  if (flag_nc()) goto lab_p03_L_738F;
  goto lab_p03_L_7387;
}

/* flash page 3 cpu 0x7407 (offset 0x3407) */
void p03_L_7407(void) {
  goto lab_p03_L_7407;
  lab_p03_L_7366: ;
  p03_L_74B9();
  p03_L_7369();
  return;
  lab_p03_L_7407: ;
  p00_L_03A0();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p03_L_7426;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p03_L_7426;
  set_hl(0x84C7);
  set_de(0x8479);
  set_bc(0x0005);
  while (bc() != 0) { cpu_ldi(); }
  a = 0x01;
  mem_write8(0x8478, a);
  lab_p03_L_7426: ;
  set_hl(0x746C);
  p00_L_25A2();
  a = mem_read8(0x8D0B);
  p00_L_1897();
  set_de(0x8478);
  a = mem_read8(de());
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p03_L_7457;
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  flag_cmp(a, 0x31);
  if (flag_z()) goto lab_p03_L_7457;
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p03_L_7450;
  a = 0x5D;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  set_hl(0x84C7);
  set_bc(0x0005);
  while (bc() != 0) { cpu_ldi(); }
  lab_p03_L_7450: ;
  p00_rst10();
  set_hl(0x0000);
  if (flag_c()) p00_L_1C46();
  lab_p03_L_7457: ;
  p00_L_25C8();
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 4)) == 0);
  if (flag_nz()) return;
  set_hl(0x92C5);
  flag_set_z((mem_read8(hl()) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_7366;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 2)));
  p03_L_73B7();
  return;
}

/* flash page 3 cpu 0x746E (offset 0x346E) */
void p03_L_746E(void) {
  set_bc(0xC066);
  p00_L_255F();
  return;
}

/* flash page 3 cpu 0x7473 (offset 0x3473) */
void p03_L_7473(void) {
  h = (uint8_t)(h - 1);
  p03_L_7474();
  return;
}

/* flash page 3 cpu 0x7474 (offset 0x3474) */
void p03_L_7474(void) {
  a = 0x08;
  mem_write8(0x97A6, a);
  return;
}

/* flash page 3 cpu 0x747A (offset 0x347A) */
void p03_L_747A(void) {
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) | (1u << 4)));
  set_hl(0x748A);
  p00_L_25A2();
  p00_L_3435();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 4)));
  return;
}

/* flash page 3 cpu 0x748F (offset 0x348F) */
void p03_L_748F(void) {
  p03_L_74B9();
  p03_L_7316();
  if (flag_z()) goto lab_p03_L_74A0;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 7)) == 0);
  if (flag_nz()) p03_L_747A();
  goto lab_p03_L_74A3;
  lab_p03_L_74A0: ;
  p03_L_4B7F();
  lab_p03_L_74A3: ;
  p00_L_0740();
  p03_L_7474();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 3)));
  p03_L_74AD();
  return;
}

/* flash page 3 cpu 0x74AD (offset 0x34AD) */
void p03_L_74AD(void) {
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) & ~(1u << 6)));
  p03_L_74B9();
  return;
}

/* flash page 3 cpu 0x74B9 (offset 0x34B9) */
void p03_L_74B9(void) {
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  return;
}

/* flash page 3 cpu 0x74C5 (offset 0x34C5) */
void p03_L_74C5(void) {
  p00_L_128A();
  a = 0x3D;
  p00_L_3E61();
  cpu_ex_de_hl();
  a = 0x09;
  lab_p03_L_74D0: ;
  p00_L_11FD();
  a = (uint8_t)(a - 0x01);
  if (flag_nz()) goto lab_p03_L_74D0;
  set_hl(0x957F);
  mem_write16(0x8479, hl());
  p00_L_11FD();
  a = 0x01;
  mem_write8(0x8478, a);
  set_hl(0x0031);
  mem_write16(0x8479, hl());
  p00_L_11FD();
  p00_L_11FD();
  p00_L_11FD();
  a = 0x5D;
  mem_write8(0x8479, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x847A, a);
  p00_L_11FD();
  p00_L_11FD();
  p00_L_11FD();
  a = 0x01;
  mem_write8(0x847A, a);
  p00_L_11FD();
  p00_L_11FD();
  p00_L_1295();
  set_hl(0x5C02);
  mem_write16(0x8478, hl());
  p00_L_11FD();
  a = 0x01;
  mem_write8(0x847A, a);
  p00_L_11FD();
  /* ld (iy+0x1C),0x00 */
  p00_L_1295();
  p00_L_11FD();
  return;
}

/* flash page 3 cpu 0x7530 (offset 0x3530) */
void p03_L_7530(void) {
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x56);
  a = b;
  return;
}

/* flash page 3 cpu 0x7538 (offset 0x3538) */
void p03_L_7538(void) {
  cpu_push_bc();
  a = mem_read8(0x89F5);
  cpu_push_af();
  a = mem_read8(0x844B);
  cpu_push_af();
  a = mem_read8((uint16_t)(ix + 0x05));
  mem_write8(0x844C, a);
  if (flag_nc()) goto lab_p03_L_756F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p03_L_755C;
  /* ld ixh,(ix+0x0D) */
  /* ld ixl,(ix+0x0E) */
  a = 0x00;
  p00_L_3C45();
  if (flag_z()) goto lab_p03_L_7561;
  lab_p03_L_755C: ;
  a = mem_read8((uint16_t)(ix + 0x06));
  a = a & 0x0F;
  flag_logic(a);
  lab_p03_L_7561: ;
  b = a;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  a = 0x20;
  lab_p03_L_7568: ;
  p00_L_3F9F();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_7568;
  goto lab_p03_L_75B1;
  lab_p03_L_756F: ;
  /* ld ixl,(ix+0x09) */
  /* ld ixh,(ix+0x0A) */
  a = mem_read8(hl());
  /* and (ix+0x0C) */
  /* cp (ix+0x0B) */
  if (flag_nz()) goto lab_p03_L_7584;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  goto lab_p03_L_7588;
  lab_p03_L_7584: ;
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 0)));
  lab_p03_L_7588: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p03_L_759B;
  /* ld ixh,(ix+0x0D) */
  /* ld ixl,(ix+0x0E) */
  a = 0x01;
  p00_L_3C45();
  if (flag_z()) goto lab_p03_L_75B1;
  lab_p03_L_759B: ;
  /* ld ixl,(ix+0x07) */
  /* ld ixh,(ix+0x08) */
  set_de(0x8478);
  lab_p03_L_75A4: ;
  a = mem_read8(hl());
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p03_L_75A4;
  set_hl(0x8478);
  p00_L_343B();
  lab_p03_L_75B1: ;
  cpu_pop_af();
  mem_write8(0x844B, a);
  cpu_pop_af();
  mem_write8(0x89F5, a);
  cpu_pop_bc();
  return;
}

/* flash page 3 cpu 0x75BB (offset 0x35BB) */
void p03_L_75BB(void) {
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) | (1u << 5)));
  return;
}

/* flash page 3 cpu 0x7720 (offset 0x3720) */
void p03_L_7720(void) {
  goto lab_p03_L_7720;
  lab_p03_L_4679: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  d = mem_read8(hl());
  if (flag_z()) goto lab_p03_L_4690;
  b = a;
  cpu_push16(ix);
  /* ld ix,(0x9700) */
  /* ld c,(ix-0x03) */
  a = 0x0A;
  p00_L_362D();
  ix = cpu_pop16();
  if (flag_nz()) return;
  a = b;
  lab_p03_L_4690: ;
  flag_cmp(a, 0x27);
  if (flag_nz()) goto lab_p03_L_46B4;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x49);
  if (flag_z()) return;
  p03_L_4B7F();
  a = mem_read8(0x859A);
  flag_cmp(a, 0x48);
  if (flag_z()) { p03_L_570B(); return; }
  flag_cmp(a, 0x51);
  if (flag_z()) { p03_L_5780(); return; }
  flag_cmp(a, 0x4B);
  if (flag_z()) { p03_L_57AB(); return; }
  flag_cmp(a, 0x53);
  if (flag_z()) { p03_L_56D4(); return; }
  lab_p03_L_46B4: ;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p03_L_46BD;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p03_L_474F;
  lab_p03_L_46BD: ;
  p03_L_473A();
  if (flag_nz()) goto lab_p03_L_4710;
  p00_L_1916();
  if (flag_z()) return;
  p03_L_4A97();
  p03_L_4AFA();
  a = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_46D9;
  p00_L_362D();
  if (flag_nz()) goto lab_p03_L_46DC;
  lab_p03_L_46D9: ;
  a = mem_read8((uint16_t)(ix + 0x03));
  lab_p03_L_46DC: ;
  a = (uint8_t)(a + 1);
  if (flag_nz()) goto lab_p03_L_46EE;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x4B);
  if (flag_z()) { p00_L_3657(); return; }
  flag_cmp(a, 0x53);
  if (flag_nz()) goto lab_p03_L_470D;
  p00_L_365D();
  return;
  lab_p03_L_46EE: ;
  p03_L_4742();
  if (flag_nz()) { p00_L_3663(); return; }
  set_de(0x0003);
  /* add ix,de */
  /* ld (0x9700),ix */
  p03_L_4987();
  if (flag_c()) goto lab_p03_L_470A;
  mem_write8(0x844C, a);
  p03_L_44F5();
  goto lab_p03_L_470D;
  lab_p03_L_470A: ;
  mem_write8(0x844B, a);
  lab_p03_L_470D: ;
  p03_L_45E3();
  return;
  lab_p03_L_4710: ;
  p03_L_4727();
  a = mem_read8((uint16_t)(ix + 0x03));
  a = (uint8_t)(a + 1);
  if (flag_z()) { p03_L_4629(); return; }
  set_de(0x0003);
  /* add ix,de */
  /* ld (0x9700),ix */
  p00_L_3669();
  return;
  lab_p03_L_474F: ;
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p03_L_4797;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x53);
  if (flag_nz()) return;
  set_hl(mem_read16(0x9700));
  a = mem_read8(hl());
  flag_cmp(a, 0x30);
  if (flag_nc()) return;
  cpu_push_af();
  p00_L_366F();
  p03_L_4A8B();
  cpu_pop_af();
  a = (uint8_t)(a - 0x2B);
  set_hl(0x4D62);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  p00_L_395D();
  set_hl(mem_read16(0x9700));
  a = mem_read8(hl());
  p00_L_3675();
  p03_L_4AE9();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 1)));
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = 0xD0;
  p00_L_3F9F();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  p03_L_45E3();
  return;
  lab_p03_L_4797: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p03_L_4814;
  p03_L_479B();
  return;
  lab_p03_L_4814: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_nz()) { p03_L_481D(); return; }
  flag_cmp(a, 0x8A);
  if (flag_z()) return;
  p03_L_481D();
  return;
  lab_p03_L_7720: ;
  e = e;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  e = b;
  l = c;
  a = d;
  a = 0xCC;
  a = c;
  c = e;
  /* adc a,0x79 */
  b = a;
  hw_out(0x79, a);
  b = mem_read8(hl());
  cpu_rla();
  a = d;
  e = d;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  e = b;
  l = c;
  a = d;
  c = e;
  /* adc a,0x79 */
  b = a;
  hw_out(0x79, a);
  b = mem_read8(hl());
  cpu_rla();
  a = d;
  e = d;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  e = b;
  l = c;
  a = d;
  c = h;
  if (flag_c()) return;
  a = c;
  c = mem_read8(hl());
  /* sbc a,0x79 */
  c = b;
  if (flag_po()) p03_L_4979();
  if (flag_pe()) goto lab_p03_L_4679;
  cpu_rla();
  a = d;
  e = c;
  l = mem_read8(hl());
  a = d;
  e = d;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  e = b;
  l = c;
  a = d;
  /* ccf */
  b = (uint8_t)(b + 1);
  a = d;
  b = b;
  cpu_rlca();
  a = d;
  c = h;
  if (flag_c()) return;
  a = c;
  c = mem_read8(hl());
  /* sbc a,0x79 */
  c = b;
  if (flag_po()) p03_L_4979();
  if (flag_pe()) goto lab_p03_L_4679;
  cpu_rla();
  a = d;
  e = d;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  b = d;
  c = (uint8_t)(c - 1);
  a = d;
  b = e;
  cpu_rrca();
  a = d;
  b = mem_read8(hl());
  cpu_rla();
  a = d;
  e = d;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  b = h;
  set_de(0x2D7A);
  if (flag_p()) return;
  lab_p03_L_779A: ;
  a = c;
  b = l;
  d = (uint8_t)(d + 1);
  a = d;
  if (flag_nc()) goto lab_p03_L_779A;
  a = c;
  b = mem_read8(hl());
  cpu_rla();
  a = d;
  e = d;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  c = d;
  sp = 0x4D7A;
  /* scf */
  a = d;
  b = a;
  hw_out(0x79, a);
  d = a;
  d = h;
  a = d;
  d = c;
  if (flag_z()) p03_L_5A7A();
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  e = b;
  l = c;
  a = d;
  a = (uint8_t)(a - 1);
  return;
}

/* flash page 3 cpu 0x77CA (offset 0x37CA) */
void p03_L_77CA(void) {
  a = d;
  mem_write8(bc(), a);
  /* ccf */
  a = d;
  d = d;
  b = h;
  a = d;
  e = e;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  e = b;
  l = c;
  a = d;
  a = (uint8_t)(a - 1);
  return;
}

/* flash page 3 cpu 0x7811 (offset 0x3811) */
void p03_L_7811(void) {
  l = c;
  a = d;
  /* ccf */
  b = (uint8_t)(b + 1);
  a = d;
  b = b;
  cpu_rlca();
  a = d;
  set_hl((uint16_t)(hl() - 1));
  /* di */
  a = c;
  l = (uint8_t)(l - 1);
  if (flag_p()) return;
  lab_p03_L_781E: ;
  a = c;
  l = 0xFD;
  a = c;
  if (flag_nc()) goto lab_p03_L_781E;
  a = c;
  d = e;
  b = mem_read8(hl());
  a = d;
  e = e;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  e = b;
  l = c;
  a = d;
  l = (uint8_t)(l + 1);
  a = a | 0x79;
  flag_logic(a);
  l = (uint8_t)(l - 1);
  if (flag_p()) return;
  lab_p03_L_7836: ;
  a = c;
  a = a ^ 0xFF;
  /* nop */
  a = d;
  if (flag_nc()) goto lab_p03_L_7836;
  a = c;
  d = mem_read8(hl());
  d = c;
  a = d;
  e = e;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  e = b;
  l = c;
  a = d;
  a = 0xCC;
  a = c;
  set_bc((uint16_t)(bc() + 1));
  a = (uint8_t)(a - 1);
  a = d;
  mem_write8(bc(), a);
  /* ccf */
  a = d;
  b = mem_read8(hl());
  cpu_rla();
  a = d;
  e = d;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  e = b;
  l = c;
  a = d;
  set_bc((uint16_t)(bc() + 1));
  a = (uint8_t)(a - 1);
  a = d;
  b = 0x41;
  a = d;
  mem_write8(bc(), a);
  /* ccf */
  a = d;
  b = mem_read8(hl());
  cpu_rla();
  a = d;
  e = d;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  e = b;
  l = c;
  a = d;
  set_hl((uint16_t)(hl() - 1));
  /* di */
  a = c;
  l = (uint8_t)(l + 1);
  a = a | 0x79;
  flag_logic(a);
  l = (uint8_t)(l - 1);
  if (flag_p()) return;
  a = c;
  l = 0xFD;
  lab_p03_L_787E: ;
  a = c;
  a = a ^ 0xFF;
  /* nop */
  a = d;
  if (flag_nc()) goto lab_p03_L_787E;
  a = c;
  b = mem_read8(hl());
  cpu_rla();
  a = d;
  e = c;
  l = mem_read8(hl());
  a = d;
  e = d;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  e = b;
  l = c;
  a = d;
  /* ccf */
  b = (uint8_t)(b + 1);
  a = d;
  b = b;
  cpu_rlca();
  a = d;
  set_hl((uint16_t)(hl() - 1));
  /* di */
  a = c;
  l = (uint8_t)(l - 1);
  if (flag_p()) return;
  lab_p03_L_789F: ;
  a = c;
  l = 0xFD;
  a = c;
  if (flag_nc()) goto lab_p03_L_789F;
  a = c;
  b = mem_read8(hl());
  cpu_rla();
  a = d;
  e = d;
  e = d;
  a = d;
  p00_rst38_isr();
  /* nop */
  /* nop */
  mem_write8(hl(), l);
  halt();
  set_hl((uint16_t)(hl() - 1));
  a = c;
  /* adc a,l */
  halt();
  mem_write8(0xBD79, a);
  halt();
  b = l;
  a = c;
  a = a & d;
  flag_logic(a);
  halt();
  set_hl((uint16_t)(hl() + sp));
  a = c;
  a = hw_in(0x76);
  d = c;
  a = c;
  /* db 0xED,0x76 */
  e = l;
  a = c;
  h = 0x77;
  a = l;
  a = c;
  sp = (uint16_t)(sp - 1);
  mem_write8(hl(), a);
  a = (uint8_t)(a + a);
  a = c;
  l = b;
  mem_write8(hl(), a);
  /* sbc a,h */
  a = c;
  c = l;
  mem_write8(hl(), a);
  a = (uint8_t)(a - c);
  a = c;
  /* add a,(hl) */
  mem_write8(hl(), a);
  a = a & a;
  flag_logic(a);
  a = c;
  a = (uint8_t)(a - l);
  mem_write8(hl(), a);
  a = a | d;
  flag_logic(a);
  a = c;
  mem_write8(bc(), a);
  mem_write8(hl(), a);
  l = c;
  a = c;
  c = 0x77;
  mem_write8(hl(), c);
  a = c;
  a = a ^ d;
  flag_logic(a);
  mem_write8(hl(), a);
  flag_cmp(a, l);
  a = c;
  a = a ^ d;
  flag_logic(a);
  mem_write8(hl(), a);
  flag_cmp(a, l);
  a = c;
  flag_cmp(a, a);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() - 1));
  a = c;
  p00_rst10();
  mem_write8(hl(), a);
  mem_write8(0x1079, a);
  a = b;
  b = l;
  a = c;
  os_bcall(0x3977);
  a = c;
  a = hw_in(0x76);
  d = c;
  a = c;
  /* db 0xED,0x76 */
  e = l;
  a = c;
  b = mem_read8(hl());
  a = b;
  a = l;
  a = c;
  e = e;
  a = b;
  a = (uint8_t)(a + a);
  a = c;
  a = (uint8_t)(a - c);
  a = b;
  /* sbc a,h */
  a = c;
  mem_write8(hl(), b);
  a = b;
  a = (uint8_t)(a - c);
  a = c;
  /* add a,(hl) */
  mem_write8(hl(), a);
  a = a & a;
  flag_logic(a);
  a = c;
  a = (uint8_t)(a - l);
  mem_write8(hl(), a);
  a = a | d;
  flag_logic(a);
  a = c;
  mem_write8(bc(), a);
  mem_write8(hl(), a);
  l = c;
  a = c;
  l = 0x78;
  mem_write8(hl(), c);
  a = c;
  p03_L_7927();
  return;
}

/* flash page 3 cpu 0x7927 (offset 0x3927) */
void p03_L_7927(void) {
  a = a ^ d;
  flag_logic(a);
  mem_write8(hl(), a);
  flag_cmp(a, l);
  a = c;
  e = d;
  l = (uint8_t)(l - 1);
  d = h;
  h = l;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  /* nop */
  d = h;
  l = (uint8_t)(l - 1);
  d = h;
  h = l;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  /* nop */
  mem_write8(0x532D, a);
  h = c;
  l = l;
  p03_L_793E();
  return;
}

/* flash page 3 cpu 0x793E (offset 0x393E) */
void p03_L_793E(void) {
  mem_write8(hl(), b);
  d = h;
  d = h;
  h = l;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  /* nop */
  mem_write8(0x532D, a);
  h = c;
  l = l;
  mem_write8(hl(), b);
  e = d;
  d = h;
  h = l;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  /* nop */
  sp = 0x502D;
  mem_write8(hl(), d);
  l = a;
  mem_write8(hl(), b);
  e = d;
  d = h;
  h = l;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  /* nop */
  mem_write8(0x502D, a);
  mem_write8(hl(), d);
  l = a;
  mem_write8(hl(), b);
  e = d;
  d = h;
  h = l;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  /* nop */
  cpu_exx();
  mem_write8(de(), a);
  l = (uint8_t)(l - 1);
  d = h;
  h = l;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  /* nop */
  mem_write8(0x532D, a);
  h = c;
  l = l;
  mem_write8(hl(), b);
  if (flag_c()) { p03_L_6554(); return; }
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  /* nop */
  e = d;
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), h);
  h = l;
  mem_write8(hl(), d);
  halt();
  h = c;
  l = h;
  /* nop */
  d = h;
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), h);
  h = l;
  mem_write8(hl(), d);
  halt();
  h = c;
  l = h;
  /* nop */
  mem_write8(0x532D, a);
  h = c;
  l = l;
  mem_write8(hl(), b);
  d = h;
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), h);
  /* nop */
  mem_write8(0x532D, a);
  h = c;
  l = l;
  mem_write8(hl(), b);
  e = d;
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), h);
  /* nop */
  sp = 0x502D;
  mem_write8(hl(), d);
  l = a;
  mem_write8(hl(), b);
  e = d;
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), h);
  /* nop */
  mem_write8(0x502D, a);
  mem_write8(hl(), d);
  l = a;
  mem_write8(hl(), b);
  e = d;
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), h);
  /* nop */
  c = h;
  l = c;
  l = mem_read8(hl());
  d = d;
  h = l;
  h = a;
  d = h;
  d = h;
  h = l;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  /* nop */
  p00_L_0080();
  return;
}

/* flash page 3 cpu 0x7972 (offset 0x3972) */
void p03_L_7972(void) {
  l = (uint8_t)(l - 1);
  d = e;
  h = c;
  l = l;
  mem_write8(hl(), b);
  if (flag_c()) { p03_L_6554(); return; }
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  /* nop */
  e = d;
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), h);
  h = l;
  mem_write8(hl(), d);
  halt();
  h = c;
  l = h;
  /* nop */
  d = h;
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), h);
  h = l;
  mem_write8(hl(), d);
  halt();
  h = c;
  l = h;
  /* nop */
  mem_write8(0x532D, a);
  h = c;
  l = l;
  mem_write8(hl(), b);
  d = h;
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), h);
  /* nop */
  mem_write8(0x532D, a);
  h = c;
  l = l;
  mem_write8(hl(), b);
  e = d;
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), h);
  /* nop */
  sp = 0x502D;
  mem_write8(hl(), d);
  l = a;
  mem_write8(hl(), b);
  e = d;
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), h);
  /* nop */
  mem_write8(0x502D, a);
  mem_write8(hl(), d);
  l = a;
  mem_write8(hl(), b);
  e = d;
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), h);
  /* nop */
  c = h;
  l = c;
  l = mem_read8(hl());
  d = d;
  h = l;
  h = a;
  d = h;
  d = h;
  h = l;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  /* nop */
  p00_L_0080();
  return;
}

/* flash page 3 cpu 0x7A64 (offset 0x3A64) */
void p03_str_5(void) {
  goto lab_p03_str_5;
  lab_p03_L_7A1E: ;
  /* nop */
  c = a;
  h = d;
  mem_write8(hl(), e);
  h = l;
  mem_write8(hl(), d);
  halt();
  h = l;
  h = h;
  /* nop */
  b = l;
  a = b;
  mem_write8(hl(), b);
  h = l;
  h = e;
  mem_write8(hl(), h);
  h = l;
  h = h;
  /* nop */
  e = b;
  l = h;
  l = c;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  /* nop */
  e = c;
  l = h;
  l = c;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  /* nop */
  /* rlc b */
  l = mem_read8(hl());
  /* nop */
  d = e;
  a = b;
  /* nop */
  /* jp 0xC300 - other page/RAM */
  lab_p03_L_7A4C: ;
  mem_write8(hl(), b);
  /* nop */
  mem_write8(hl(), b);
  sp = 0xC700;
  sp = 0xBC00;
  if (flag_nz()) goto lab_p03_L_7A7D;
  if (flag_nz()) goto lab_p03_L_7A1E;
  /* nop */
  b = e;
  h = c;
  l = h;
  h = e;
  mem_write8(hl(), l);
  l = h;
  h = c;
  mem_write8(hl(), h);
  h = l;
  /* nop */
  lab_p03_str_5: ;
  b = h;
  mem_write8(hl(), d);
  h = c;
  mem_write8(hl(), a);
  /* nop */
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), b);
  mem_write8(hl(), h);
  /* nop */
  d = b;
  l = a;
  l = a;
  l = h;
  h = l;
  h = h;
  /* nop */
  e = c;
  h = l;
  mem_write8(hl(), e);
  /* nop */
  c = mem_read8(hl());
  l = a;
  /* nop */
  b = h;
  lab_p03_L_7A7D: ;
  h = c;
  mem_write8(hl(), h);
  h = c;
  /* nop */
  d = e;
  mem_write8(hl(), h);
  h = c;
  mem_write8(hl(), h);
  mem_write8(hl(), e);
  /* nop */
  goto lab_p03_L_7A4C;
}

/* flash page 3 cpu 0x7AFE (offset 0x3AFE) */
void p03_L_7AFE(void) {
  c = (uint8_t)(c + 1);
  /* adc a,d */
  set_bc(0xFE03);
  a = mem_read8(hl());
  mem_write8(bc(), a);
  set_bc(0xFEFE);
  b = (uint8_t)(b - 1);
  set_bc((uint16_t)(bc() - 1));
  set_bc((uint16_t)(bc() + 1));
  /* adc a,e */
  a = d;
  c = (uint8_t)(c + 1);
  /* adc a,d */
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x7F);
  set_bc(0xFE00);
  flag_cmp(a, 0x05);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  a = (uint8_t)(a - e);
  a = d;
  c = (uint8_t)(c + 1);
  /* adc a,d */
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x80);
  mem_write8(bc(), a);
  /* nop */
  flag_cmp(a, 0xFE);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  set_bc((uint16_t)(bc() + 1));
  /* sbc a,e */
  a = d;
  c = (uint8_t)(c + 1);
  /* adc a,d */
  set_bc(0xFE03);
  a = (uint8_t)(a + c);
  mem_write8(bc(), a);
  set_bc(0xFEFE);
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  set_bc((uint16_t)(bc() + 1));
  a = 0;
  flag_logic(a);
  a = d;
  c = (uint8_t)(c + 1);
  /* adc a,d */
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x82);
  set_bc(0xFE00);
  flag_cmp(a, 0x05);
  b = (uint8_t)(b - 1);
  set_bc((uint16_t)(bc() + 1));
  /* sbc a,a */
  a = d;
  c = (uint8_t)(c + 1);
  /* adc a,d */
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x83);
  mem_write8(bc(), a);
  /* nop */
  flag_cmp(a, 0xFE);
  b = (uint8_t)(b - 1);
  set_hl((uint16_t)(hl() + bc()));
  set_bc((uint16_t)(bc() + 1));
  a = a & a;
  flag_logic(a);
  a = d;
  c = (uint8_t)(c + 1);
  /* adc a,d */
  set_bc(0xFE03);
  a = (uint8_t)(a + h);
  mem_write8(bc(), a);
  set_bc(0xFEFE);
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c - 1);
  set_bc((uint16_t)(bc() + 1));
  a = a & e;
  flag_logic(a);
  a = d;
  c = (uint8_t)(c + 1);
  /* adc a,d */
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x85);
  set_bc(0xFE00);
  flag_cmp(a, 0x05);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  a = a ^ e;
  flag_logic(a);
  a = d;
  c = (uint8_t)(c + 1);
  /* adc a,d */
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x86);
  mem_write8(bc(), a);
  /* nop */
  flag_cmp(a, 0xFE);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  set_bc((uint16_t)(bc() + 1));
  a = a | e;
  flag_logic(a);
  a = d;
  c = (uint8_t)(c + 1);
  /* adc a,d */
  set_bc(0xFE03);
  a = (uint8_t)(a + a);
  mem_write8(bc(), a);
  set_bc(0xFEFE);
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  set_bc((uint16_t)(bc() + 1));
  a = 0;
  flag_logic(a);
  a = d;
  c = (uint8_t)(c + 1);
  /* adc a,d */
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x88);
  set_bc(0xFE00);
  flag_cmp(a, 0x05);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  a = a | a;
  flag_logic(a);
  a = d;
  c = (uint8_t)(c + 1);
  /* adc a,d */
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x89);
  mem_write8(bc(), a);
  /* nop */
  flag_cmp(a, 0xFE);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, a);
  a = d;
  c = (uint8_t)(c + 1);
  /* adc a,d */
  set_bc(0xFE03);
  /* adc a,d */
  mem_write8(bc(), a);
  set_bc(0xFEFE);
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, e);
  a = d;
  c = (uint8_t)(c + 1);
  /* adc a,d */
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x8B);
  set_bc(0xFE00);
  flag_cmp(a, 0x05);
  cpu_rlca();
  p03_L_7BCD();
  return;
}

/* flash page 3 cpu 0x7BCD (offset 0x3BCD) */
void p03_L_7BCD(void) {
  mem_write8(bc(), a);
  p00_L_0C7A();
  return;
}

/* flash page 3 cpu 0x7C6C (offset 0x3C6C) */
void p03_L_7C6C(void) {
  p03_L_71FC();
  cpu_push16(ix);
  /* ld ix,(0x9700) */
  a = 0x00;
  mem_write8(0x84C7, a);
  lab_p03_L_7C7A: ;
  a = mem_read8(ix);
  mem_write8(0x8D0B, a);
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p03_L_7C8D;
  p03_L_7C90();
  set_de(0x0003);
  /* add ix,de */
  goto lab_p03_L_7C7A;
  lab_p03_L_7C8D: ;
  ix = cpu_pop16();
  return;
}

/* flash page 3 cpu 0x7C90 (offset 0x3C90) */
void p03_L_7C90(void) {
  p03_L_7264();
  p00_L_128A();
  a = mem_read8(ix);
  flag_cmp(a, 0x5A);
  if (flag_z()) return;
  flag_cmp(a, 0x5B);
  if (flag_z()) goto lab_p03_L_7CD7;
  flag_cmp(a, 0x52);
  if (flag_c()) goto lab_p03_L_7CDF;
  flag_cmp(a, 0x58);
  if (flag_c()) goto lab_p03_L_7CC0;
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p03_L_7CB3;
  lab_p03_L_7CB0: ;
  p00_L_1229();
  lab_p03_L_7CB3: ;
  set_hl(0x84C7);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_L_21E5();
  return;
  lab_p03_L_7CC0: ;
  a = mem_read8(0x8A0C);
  a = a & 0x03;
  flag_logic(a);
  if (flag_z()) goto lab_p03_L_7CB3;
  cpu_push_af();
  p00_L_1229();
  p03_L_7CCB();
  return;
  lab_p03_L_7CD7: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p03_L_7CB0;
  goto lab_p03_L_7CB3;
  lab_p03_L_7CDF: ;
  p00_L_18A3();
  a = mem_read8(ix);
  flag_cmp(a, 0x51);
  if (flag_nz()) goto lab_p03_L_7CF1;
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_nz()) return;
  goto lab_p03_L_7CB3;
  lab_p03_L_7CF1: ;
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p03_L_7CFC;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p03_L_7D19;
  lab_p03_L_7CFC: ;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x31);
  if (flag_z()) return;
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p03_L_7D14;
  set_hl(0x847D);
  set_de(0x847E);
  set_bc(0x0005);
  /* lddr */
  a = 0x5D;
  mem_write8(de(), a);
  lab_p03_L_7D14: ;
  p00_L_354F();
  goto lab_p03_L_7CB3;
  lab_p03_L_7D19: ;
  flag_cmp(a, 0x0E);
  if (flag_nz()) goto lab_p03_L_7D21;
  a = 0;
  flag_logic(a);
  mem_write8(0x8478, a);
  lab_p03_L_7D21: ;
  goto lab_p03_L_7CB3;
}

/* flash page 3 cpu 0x7CBB (offset 0x3CBB) */
void p03_L_7CBB(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 3)) == 0);
  return;
}

/* flash page 3 cpu 0x7CCB (offset 0x3CCB) */
void p03_L_7CCB(void) {
  goto lab_p03_L_7CCB;
  lab_p03_L_7CB3: ;
  set_hl(0x84C7);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_L_21E5();
  return;
  lab_p03_L_7CCB: ;
  cpu_pop_af();
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p03_L_7CB3;
  a = 0x80;
  mem_write8(0x8478, a);
  goto lab_p03_L_7CB3;
}

/* flash page 3 cpu 0x7CCD (offset 0x3CCD) */
void p03_L_7CCD(void) {
  goto lab_p03_L_7CCD;
  lab_p03_L_7CB3: ;
  set_hl(0x84C7);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_L_21E5();
  return;
  lab_p03_L_7CCD: ;
  mem_write8(bc(), a);
  if (flag_z()) goto lab_p03_L_7CB3;
  a = 0x80;
  mem_write8(0x8478, a);
  goto lab_p03_L_7CB3;
}

/* flash page 3 cpu 0x7D23 (offset 0x3D23) */
void p03_L_7D23(void) {
  /* ld ix,(0x97A3) */
  p03_L_7D60();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 4)) == 0);
  if (flag_z()) { p03_L_7D48(); return; }
  set_hl(0x8D0A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 4)));
  p03_L_7CBB();
  if (flag_z()) goto lab_p03_L_7D3C;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 4)));
  lab_p03_L_7D3C: ;
  p03_L_74B9();
  p03_L_7474();
  p00_L_3E8B();
  p03_L_70CC();
  return;
}

/* flash page 3 cpu 0x7D48 (offset 0x3D48) */
void p03_L_7D48(void) {
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  a = mem_read8(0x97A1);
  b = a;
  /* ld ix,(0x979F) */
  lab_p03_L_7D54: ;
  a = a | a;
  flag_logic(a);
  p03_L_7538();
  set_de(0x000F);
  /* add ix,de */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p03_L_7D54;
  return;
}

/* flash page 3 cpu 0x7D60 (offset 0x3D60) */
void p03_L_7D60(void) {
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) & ~(1u << 4)));
  /* ld ixl,(ix+0x09) */
  /* ld ixh,(ix+0x0A) */
  a = mem_read8(hl());
  /* and (ix+0x0C) */
  /* cp (ix+0x0B) */
  if (flag_z()) return;
  a = mem_read8((uint16_t)(ix + 0x0C));
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p03_L_7D7D;
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) | (1u << 4)));
  lab_p03_L_7D7D: ;
  a = a ^ 0xFF;
  /* and (hl) */
  /* or (ix+0x0B) */
  mem_write8(hl(), a);
  return;
}

/* flash page 3 cpu 0x7D84 (offset 0x3D84) */
void p03_L_7D84(void) {
  /* ld ix,(0x97A3) */
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p03_L_7D91;
  flag_cmp(a, 0x02);
  if (flag_nz()) { p00_L_3453(); return; }
  lab_p03_L_7D91: ;
  a = (uint8_t)(a - 1);
  e = a;
  d = 0x00;
  /* add ix,de */
  a = mem_read8(ix);
  mem_write8(0x97A2, a);
  a = mem_read8(0x97A2);
  l = a;
  h = 0x00;
  e = l;
  d = h;
  set_hl((uint16_t)(hl() + hl()));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + hl()));
  set_hl((uint16_t)(hl() + hl()));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  set_de(mem_read16(0x979F));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x97A3, hl());
  cpu_push_hl();
  ix = cpu_pop16();
  return;
}

/* flash page 3 cpu 0x7DBC (offset 0x3DBC) */
void p03_L_7DBC(void) {
  set_de(mem_read16(0x8479));
  a = e;
  e = d;
  d = a;
  p03_L_7DC3();
  return;
}

/* flash page 3 cpu 0x7DC3 (offset 0x3DC3) */
void p03_L_7DC3(void) {
  p00_L_3459();
  return;
}

/* flash page 3 cpu 0x7DEA (offset 0x3DEA) */
void p03_L_7DEA(void) {
  p03_L_74B9();
  a = mem_read8(0x97A7);
  cpu_push_af();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(mem_read16(0x8D0B));
  cpu_push_hl();
  a = mem_read8(0x97A1);
  cpu_push_af();
  set_hl(mem_read16(0x979F));
  cpu_push_hl();
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 5)));
  p00_L_345F();
  if (flag_nz()) goto lab_p03_L_7E15;
  set_hl(mem_read16(0x85C0));
  mem_write16(0x844B, hl());
  a = 0x07;
  mem_write8(0x97A6, a);
  lab_p03_L_7E15: ;
  p03_L_7212();
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 5)));
  p03_L_7474();
  cpu_pop_hl();
  mem_write16(0x979F, hl());
  cpu_pop_af();
  mem_write8(0x97A1, a);
  cpu_pop_hl();
  mem_write16(0x8D0B, hl());
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  cpu_pop_af();
  mem_write8(0x97A7, a);
  return;
}

/* flash page 3 cpu 0x7EEF (offset 0x3EEF) */
void p03_L_7EEF(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p03_L_7FCB();
  return;
}

/* flash page 3 cpu 0x7FCB (offset 0x3FCB) */
void p03_L_7FCB(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
}


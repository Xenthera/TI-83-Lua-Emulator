/* Recovered from flash page 27 (mechanical ASM->C) */
/* cpu window 0x4000..0x7FFF prefix=p27_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p27_L_4000(void);
void p27_L_4002(void);
void p27_L_40D5(void);
void p27_L_40E3(void);
void p27_L_4100(void);
void p27_L_415A(void);
void p27_L_4400(void);
void p27_L_4500(void);
void p27_L_4802(void);
void p27_L_4C00(void);
void p27_L_4FA0(void);
void p27_L_5002(void);
void p27_L_50EC(void);
void p27_L_5100(void);
void p27_L_51B4(void);
void p27_L_51D0(void);
void p27_L_51E6(void);
void p27_L_5203(void);
void p27_L_525E(void);
void p27_L_525F(void);
void p27_L_5270(void);
void p27_L_5275(void);
void p27_L_52AD(void);
void p27_L_52B2(void);
void p27_L_5328(void);
void p27_L_5338(void);
void p27_L_5347(void);
void p27_L_5348(void);
void p27_L_5349(void);
void p27_L_534A(void);
void p27_L_5357(void);
void p27_L_536F(void);
void p27_L_5373(void);
void p27_L_5380(void);
void p27_L_5381(void);
void p27_L_5396(void);
void p27_L_53B2(void);
void p27_L_53ED(void);
void p27_L_53F3(void);
void p27_L_54B0(void);
void p27_L_554B(void);
void p27_L_5565(void);
void p27_L_557A(void);
void p27_L_5582(void);
void p27_L_5589(void);
void p27_L_5591(void);
void p27_L_5598(void);
void p27_L_55C5(void);
void p27_L_55D3(void);
void p27_L_55E3(void);
void p27_L_55F8(void);
void p27_L_5690(void);
void p27_L_569B(void);
void p27_L_56B7(void);
void p27_L_56BC(void);
void p27_L_56C5(void);
void p27_L_56D5(void);
void p27_L_56DF(void);
void p27_L_5702(void);
void p27_L_5706(void);
void p27_L_5719(void);
void p27_L_573A(void);
void p27_L_5743(void);
void p27_L_5802(void);
void p27_L_580C(void);
void p27_L_5816(void);
void p27_L_588E(void);
void p27_L_58A0(void);
void p27_L_5935(void);
void p27_L_5A1A(void);
void p27_L_5A2C(void);
void p27_L_5A45(void);
void p27_L_5AB4(void);
void p27_L_5AC3(void);
void p27_L_5AE1(void);
void p27_L_5B53(void);
void p27_L_5B85(void);
void p27_L_5BA8(void);
void p27_L_5BB5(void);
void p27_L_5BB8(void);
void p27_L_5BD7(void);
void p27_L_5BF3(void);
void p27_L_5C0D(void);
void p27_L_5C3D(void);
void p27_L_5C44(void);
void p27_L_5C50(void);
void p27_L_5C59(void);
void p27_L_5C5C(void);
void p27_L_5CF4(void);
void p27_L_5CF5(void);
void p27_L_5DCC(void);
void p27_L_5DE1(void);
void p27_L_5DE4(void);
void p27_L_5DEA(void);
void p27_L_5EA2(void);
void p27_L_5EC9(void);
void p27_L_5F15(void);
void p27_L_5F56(void);
void p27_L_5F81(void);
void p27_L_5F8D(void);
void p27_L_5FC6(void);
void p27_L_5FFB(void);
void p27_L_6005(void);
void p27_L_600C(void);
void p27_L_6048(void);
void p27_L_6067(void);
void p27_L_60A1(void);
void p27_L_60E2(void);
void p27_L_60E9(void);
void p27_L_6100(void);
void p27_L_610D(void);
void p27_L_6144(void);
void p27_L_618B(void);
void p27_L_6199(void);
void p27_L_61EB(void);
void p27_L_61EE(void);
void p27_L_6205(void);
void p27_L_6211(void);
void p27_L_6247(void);
void p27_L_6297(void);
void p27_L_638B(void);
void p27_L_63EE(void);
void p27_L_63F3(void);
void p27_L_6402(void);
void p27_L_6406(void);
void p27_L_6424(void);
void p27_L_642E(void);
void p27_L_6503(void);
void p27_L_6512(void);
void p27_L_6516(void);
void p27_L_6556(void);
void p27_L_655A(void);
void p27_L_65B5(void);
void p27_L_65EE(void);
void p27_L_663A(void);
void p27_L_6659(void);
void p27_L_6667(void);
void p27_L_6682(void);
void p27_L_67DC(void);
void p27_L_68A6(void);
void p27_L_6937(void);
void p27_L_6943(void);
void p27_L_6949(void);
void p27_L_6952(void);
void p27_L_6957(void);
void p27_L_695A(void);
void p27_L_6985(void);
void p27_L_69AB(void);
void p27_L_69AE(void);
void p27_L_69CE(void);
void p27_L_69EC(void);
void p27_L_69F9(void);
void p27_L_6A30(void);
void p27_L_6A42(void);
void p27_L_6A43(void);
void p27_L_6AD9(void);
void p27_L_6ADC(void);
void p27_L_6B00(void);
void p27_L_6B06(void);
void p27_L_6B17(void);
void p27_L_6B2A(void);
void p27_L_6BAE(void);
void p27_L_6BC5(void);
void p27_L_6BE6(void);
void p27_L_6BFD(void);
void p27_L_6C02(void);
void p27_L_6C05(void);
void p27_L_6C0B(void);
void p27_L_6C19(void);
void p27_L_6C21(void);
void p27_L_6C38(void);
void p27_L_6C61(void);
void p27_L_6D1A(void);
void p27_L_6D37(void);
void p27_L_6D46(void);
void p27_L_6D58(void);
void p27_L_6D70(void);
void p27_L_6D88(void);
void p27_L_6E24(void);
void p27_L_6F14(void);
void p27_L_6F2F(void);
void p27_L_6F45(void);
void p27_L_6F4A(void);
void p27_L_6F6A(void);
void p27_L_6FD0(void);
void p27_L_6FE1(void);
void p27_L_703B(void);
void p27_L_704E(void);
void p27_L_70FF(void);
void p27_L_7100(void);
void p27_L_715A(void);
void p27_ascii_map_2(void);
void p27_ascii_map_3(void);
void p27_ascii_map_4(void);
void p27_L_71E4(void);
void p27_L_71FC(void);
void p27_L_7200(void);
void p27_L_7208(void);
void p27_L_7245(void);
void p27_L_724C(void);
void p27_L_7254(void);
void p27_L_7279(void);
void p27_lcd_write_data_2(void);
void p27_lcd_write_data(void);
void p27_L_72B1(void);
void p27_L_72B4(void);
void p27_L_72DF(void);
void p27_L_72F1(void);
void p27_L_7300(void);
void p27_L_7355(void);
void p27_L_7358(void);
void p27_L_7402(void);
void p27_L_740D(void);
void p27_L_7450(void);
void p27_L_74AC(void);
void p27_L_74C0(void);
void p27_lcd_cmd(void);
void p27_L_751A(void);
void p27_L_7533(void);
void p27_L_7534(void);
void p27_L_753C(void);
void p27_L_7547(void);
void p27_L_7586(void);
void p27_L_75B7(void);
void p27_L_75D7(void);
void p27_L_75E2(void);
void p27_L_75E5(void);
void p27_L_75ED(void);
void p27_L_75FF(void);
void p27_L_7682(void);
void p27_L_769A(void);
void p27_L_76EA(void);
void p27_L_7700(void);
void p27_L_7706(void);
void p27_L_7713(void);
void p27_L_7718(void);
void p27_L_7729(void);
void p27_L_7738(void);
void p27_L_7759(void);
void p27_L_77B6(void);
void p27_L_77C5(void);
void p27_L_77E0(void);
void p27_L_77F0(void);
void p27_L_7802(void);
void p27_L_7812(void);
void p27_L_7817(void);
void p27_L_7824(void);
void p27_L_7835(void);
void p27_L_7845(void);
void p27_L_7857(void);
void p27_L_785D(void);
void p27_L_7866(void);
void p27_L_7869(void);
void p27_L_7871(void);
void p27_L_7872(void);
void p27_L_787B(void);
void p27_L_788D(void);
void p27_L_78A6(void);
void p27_L_78B8(void);
void p27_L_78C8(void);
void p27_L_78DA(void);
void p27_L_7915(void);
void p27_L_7920(void);
void p27_L_795B(void);
void p27_L_7972(void);
void p27_L_79E6(void);
void p27_L_79F5(void);
void p27_L_7B00(void);
void p27_L_7B57(void);
void p27_L_7B5A(void);
void p27_L_7B5C(void);
void p27_L_7B5D(void);
void p27_L_7B69(void);
void p27_L_7B6A(void);
void p27_L_7B70(void);
void p27_L_7B71(void);
void p27_L_7B78(void);
void p27_L_7C43(void);
void p27_L_7E00(void);
void p27_ascii_map(void);
void p27_L_7FF1(void);

/* flash page 27 cpu 0x4000 (offset 0x0000) */
void p27_L_4000(void) {
  h = l;
  h = (uint8_t)(h - 1);
  p27_L_4002();
  return;
}

/* flash page 27 cpu 0x4002 (offset 0x0002) */
void p27_L_4002(void) {
  /* nop */
  h = (uint8_t)(h + 1);
  a = b;
  a = e;
  cpu_push_bc();
  mem_write8(hl(), a);
  a = e;
  sp = (uint16_t)(sp + 1);
  /* nop */
  /* nop */
  set_hl(mem_read16(0x0019));
  a = a ^ l;
  flag_logic(a);
  set_bc(0xAF00);
  set_bc(0xB300);
  mem_write8(bc(), a);
  /* nop */
  /* adc a,h */
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  cpu_push_bc();
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  p00_rst08();
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  mem_write8(de(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  d = (uint8_t)(d - 1);
  b = (uint8_t)(b - 1);
  /* nop */
  cpu_pop_af();
  b = (uint8_t)(b - 1);
  /* nop */
  if (flag_p()) { p00_L_0005(); return; }
  d = (uint8_t)(d - 1);
  b = 0x00;
  mem_write16(0x0006, hl());
  sp = (uint16_t)(sp + 1);
  b = 0x00;
  a = mem_read8(0x0007);
  b = l;
  cpu_rlca();
  /* nop */
  d = e;
  cpu_rlca();
  /* nop */
  l = e;
  cpu_rlca();
  /* nop */
  a = h;
  cpu_rlca();
  /* nop */
  a = (uint8_t)(a - b);
  cpu_rlca();
  /* nop */
  a = a ^ l;
  flag_logic(a);
  cpu_rlca();
  /* nop */
  if (flag_z()) p00_L_0007();
  if (flag_z()) { p00_L_0009(); return; }
  /* xor (hl) */
  a = mem_read8(bc());
  /* nop */
  if (flag_c()) { p00_L_000B(); return; }
  /* ex (sp),hl */
  set_bc((uint16_t)(bc() - 1));
  /* nop */
  cpu_pop_af();
  set_bc((uint16_t)(bc() - 1));
  /* nop */
  sp = hl();
  set_bc((uint16_t)(bc() - 1));
  /* nop */
  cpu_rrca();
  c = (uint8_t)(c + 1);
  /* nop */
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c + 1);
  /* nop */
  goto lab_p27_L_4074;
  lab_p27_L_4074: ;
  /* nop */
  /* nop */
  c = (uint8_t)(c - 1);
  /* nop */
  set_hl((uint16_t)(hl() + bc()));
  c = (uint8_t)(c - 1);
  /* nop */
  set_de(0x000D);
  d = 0x0D;
  /* nop */
  e = 0x0D;
  /* nop */
  cpu_rra();
  c = (uint8_t)(c - 1);
  /* nop */
  cpu_rlca();
  c = 0x00;
  c = c;
  c = 0x00;
  c = h;
  c = 0x00;
  e = h;
  c = 0x00;
  mem_write8(hl(), d);
  c = 0x00;
  if (flag_z()) p00_L_000E();
  if (flag_nc()) return;
  c = 0x00;
  b = mem_read8(hl());
  l = l;
  mem_write8(bc(), a);
  if (flag_nc()) p00_L_0265();
  a = a ^ 0x65;
  flag_logic(a);
  mem_write8(bc(), a);
  a = 0;
  flag_logic(a);
  cpu_rrca();
  /* nop */
  a = a | c;
  flag_logic(a);
  cpu_rrca();
  /* nop */
  set_bc((uint16_t)(bc() - 1));
  l = mem_read8(hl());
  mem_write8(bc(), a);
  h = (uint8_t)(h + 1);
  l = mem_read8(hl());
  mem_write8(bc(), a);
  /* sbc a,b */
  cpu_rrca();
  /* nop */
  l = d;
  l = a;
  mem_write8(bc(), a);
  mem_write8(hl(), h);
  l = a;
  mem_write8(bc(), a);
  c = h;
  mem_write8(hl(), d);
  mem_write8(bc(), a);
  d = b;
  mem_write8(hl(), d);
  mem_write8(bc(), a);
  d = h;
  mem_write8(hl(), d);
  mem_write8(bc(), a);
  e = b;
  mem_write8(hl(), d);
  mem_write8(bc(), a);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  mem_write8(hl(), l);
  mem_write8(bc(), a);
  if (flag_c()) goto lab_p27_L_4140;
  mem_write8(bc(), a);
  a = (uint8_t)(a + 1);
  mem_write8(hl(), l);
  mem_write8(bc(), a);
  b = b;
  mem_write8(hl(), l);
  mem_write8(bc(), a);
  p00_rst10();
  mem_write8(hl(), l);
  mem_write8(bc(), a);
  p27_L_40D5();
  return;
  lab_p27_L_4140: ;
  /* nop */
  b = h;
  set_de(0x4900);
  set_de(0x5100);
  set_de(0x5900);
  set_de(0x6100);
  set_de(0x6900);
  set_de(0x7100);
  set_de(0x7900);
  set_de(0x7F00);
  p27_L_415A();
  return;
}

/* flash page 27 cpu 0x40D5 (offset 0x00D5) */
void p27_L_40D5(void) {
  /* ld (ix+0x02),ixl */
  if (flag_po()) { p00_L_0275(); return; }
  if (flag_pe()) return;
  mem_write8(hl(), l);
  mem_write8(bc(), a);
  /* db 0xED,0x75 */
  mem_write8(bc(), a);
  p00_rst30();
  mem_write8(hl(), l);
  p27_L_40E3();
  return;
}

/* flash page 27 cpu 0x40E3 (offset 0x00E3) */
void p27_L_40E3(void) {
  mem_write8(bc(), a);
  p00_rst38_isr();
  mem_write8(hl(), l);
  mem_write8(bc(), a);
  d = a;
  halt();
  mem_write8(bc(), a);
  cpu_rla();
  a = b;
  mem_write8(bc(), a);
  h = h;
  a = b;
  mem_write8(bc(), a);
  mem_write8(hl(), d);
  a = b;
  mem_write8(bc(), a);
  a = (uint8_t)(a + d);
  c = a;
  mem_write8(bc(), a);
  a = a & b;
  flag_logic(a);
  c = a;
  mem_write8(bc(), a);
  h = (uint8_t)(h - 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_40FC;
  lab_p27_L_40FC: ;
  a = a ^ 0xFF;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_40FF;
  lab_p27_L_40FF: ;
  /* scf */
  p27_L_4100();
  return;
}

/* flash page 27 cpu 0x4100 (offset 0x0100) */
void p27_L_4100(void) {
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_4102;
  lab_p27_L_4102: ;
  a = a | l;
  flag_logic(a);
  h = l;
  mem_write8(bc(), a);
  c = b;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_4108;
  lab_p27_L_4108: ;
  l = e;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_410B;
  lab_p27_L_410B: ;
  mem_write8(hl(), e);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_410E;
  lab_p27_L_410E: ;
  a = b;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_4111;
  lab_p27_L_4111: ;
  a = mem_read8(hl());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_4114;
  lab_p27_L_4114: ;
  if (flag_nc()) p00_rst10();
  /* db 0xDD */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_411A;
  lab_p27_L_411A: ;
  a = a & 0x10;
  flag_logic(a);
  /* nop */
  os_bcall(0x0010);
  if (flag_m()) return;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_4123;
  lab_p27_L_4123: ;
  /* nop */
  set_de(0x0800);
  set_de(0x1000);
  set_de(0x1800);
  set_de(0x2000);
  set_de(0x2800);
  set_de(0x3000);
  set_de(0x3500);
  set_de(0x3A00);
  set_de(0x3F00);
  set_de(0x4400);
  set_de(0x4900);
  set_de(0x5100);
  set_de(0x5900);
  set_de(0x6100);
  set_de(0x6900);
  set_de(0x7100);
  set_de(0x7900);
  set_de(0x7F00);
  p27_L_415A();
  return;
}

/* flash page 27 cpu 0x415A (offset 0x015A) */
void p27_L_415A(void) {
  set_de(0x8100);
  set_de(0x8300);
  set_de(0x8300);
  set_de(0x8500);
  set_de(0x8700);
  set_de(0x8700);
  set_de(0xD800);
  set_de(0xE000);
  set_de(0xE500);
  set_de(0xEA00);
  set_de(0xF200);
  set_de(0xF700);
  set_de(0xF800);
  set_de(0xFD00);
  set_de(0x0200);
  mem_write8(de(), a);
  /* nop */
  cpu_rlca();
  mem_write8(de(), a);
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(de(), a);
  /* nop */
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  /* nop */
  d = (uint8_t)(d - 1);
  mem_write8(de(), a);
  /* nop */
  a = mem_read8(de());
  mem_write8(de(), a);
  /* nop */
  set_hl(0x0012);
  set_hl((uint16_t)(hl() + hl()));
  mem_write8(de(), a);
  /* nop */
  l = 0x12;
  /* nop */
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  mem_write8(de(), a);
  /* nop */
  a = (uint8_t)(a + 1);
  mem_write8(de(), a);
  /* nop */
  b = c;
  mem_write8(de(), a);
  /* nop */
  b = mem_read8(hl());
  mem_write8(de(), a);
  /* nop */
  d = c;
  mem_write8(de(), a);
  /* nop */
  h = b;
  mem_write8(de(), a);
  /* nop */
  mem_write8(hl(), c);
  mem_write8(de(), a);
  /* nop */
  halt();
  mem_write8(de(), a);
  /* nop */
  a = e;
  mem_write8(de(), a);
  /* nop */
  a = (uint8_t)(a + a);
  mem_write8(de(), a);
  /* nop */
  /* adc a,d */
  mem_write8(de(), a);
  /* nop */
  /* adc a,l */
  mem_write8(de(), a);
  /* nop */
  a = (uint8_t)(a - l);
  mem_write8(de(), a);
  /* nop */
  /* sbc a,d */
  mem_write8(de(), a);
  /* nop */
  /* sbc a,a */
  mem_write8(de(), a);
  /* nop */
  a = a & d;
  flag_logic(a);
  mem_write8(de(), a);
  /* nop */
  a = a ^ d;
  flag_logic(a);
  mem_write8(de(), a);
  /* nop */
  a = a | c;
  flag_logic(a);
  mem_write8(de(), a);
  /* nop */
  flag_cmp(a, c);
  mem_write8(de(), a);
  /* nop */
  p00_rst00_boot();
  mem_write8(de(), a);
  /* nop */
  if (flag_z()) return;
  mem_write8(de(), a);
  /* nop */
  if (flag_nc()) return;
  mem_write8(de(), a);
  /* nop */
  if (flag_nc()) p00_L_0012();
  b = (uint8_t)(b + 1);
  set_de((uint16_t)(de() + 1));
  /* nop */
  cpu_ex_af();
  set_de((uint16_t)(de() + 1));
  /* nop */
  if (flag_z()) goto lab_p27_L_4201;
  /* nop */
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  set_de((uint16_t)(de() + 1));
  /* nop */
  mem_write8(hl(), l);
  set_de((uint16_t)(de() + 1));
  /* nop */
  mem_write8(hl(), a);
  set_de((uint16_t)(de() + 1));
  /* nop */
  a = b;
  set_de((uint16_t)(de() + 1));
  /* nop */
  flag_cmp(a, e);
  set_de((uint16_t)(de() + 1));
  /* nop */
  cpu_pop_bc();
  set_de((uint16_t)(de() + 1));
  /* nop */
  lab_p27_L_4201: ;
  if (flag_nc()) goto lab_p27_L_4217;
  /* nop */
  mem_write8(hl(), 0x14);
  /* nop */
  a = c;
  d = (uint8_t)(d + 1);
  /* nop */
  a = mem_read8(hl());
  d = (uint8_t)(d + 1);
  /* nop */
  /* add a,(hl) */
  d = (uint8_t)(d + 1);
  /* nop */
  /* adc a,e */
  d = (uint8_t)(d + 1);
  /* nop */
  a = (uint8_t)(a - b);
  d = (uint8_t)(d + 1);
  /* nop */
  a = (uint8_t)(a - l);
  lab_p27_L_4217: ;
  d = (uint8_t)(d + 1);
  /* nop */
  /* sbc a,l */
  d = (uint8_t)(d + 1);
  /* nop */
  a = a & d;
  flag_logic(a);
  d = (uint8_t)(d + 1);
  /* nop */
  a = a | b;
  flag_logic(a);
  d = (uint8_t)(d + 1);
  /* nop */
  flag_cmp(a, b);
  d = (uint8_t)(d + 1);
  /* nop */
  if (flag_nz()) { p00_L_0014(); return; }
  p00_rst00_boot();
  d = (uint8_t)(d + 1);
  /* nop */
  if (flag_z()) p00_L_0014();
  cpu_push_de();
  d = (uint8_t)(d + 1);
  /* nop */
  a = hw_in(0x14);
  /* nop */
  if (flag_po()) p00_L_0014();
  if (flag_pe()) return;
  d = (uint8_t)(d + 1);
  /* nop */
  e = (uint8_t)(e - 1);
  d = (uint8_t)(d - 1);
  /* nop */
  l = (uint8_t)(l + 1);
  d = (uint8_t)(d - 1);
  /* nop */
  sp = 0x0015;
  c = l;
  d = (uint8_t)(d - 1);
  /* nop */
  d = mem_read8(hl());
  d = (uint8_t)(d - 1);
  /* nop */
  a = (uint8_t)(a + e);
  d = (uint8_t)(d - 1);
  /* nop */
  /* adc a,d */
  d = (uint8_t)(d - 1);
  /* nop */
  /* sbc a,a */
  d = (uint8_t)(d - 1);
  /* nop */
  a = a ^ c;
  flag_logic(a);
  d = (uint8_t)(d - 1);
  /* nop */
  a = (uint8_t)(a + 0x15);
  /* nop */
  /* rl l */
  /* nop */
  cpu_pop_de();
  d = (uint8_t)(d - 1);
  /* nop */
  a = (uint8_t)(a - 0x15);
  /* nop */
  /* db 0xDD */
  d = (uint8_t)(d - 1);
  /* nop */
  if (flag_po()) return;
  d = (uint8_t)(d - 1);
  /* nop */
  cpu_ex_de_hl();
  d = (uint8_t)(d - 1);
  /* nop */
  /* di */
  d = (uint8_t)(d - 1);
  /* nop */
  a = a | 0x15;
  flag_logic(a);
  /* nop */
  /* ei */
  d = (uint8_t)(d - 1);
  /* nop */
  sp = (uint16_t)(sp - 1);
  d = 0x00;
  b = a;
  d = 0x00;
  d = e;
  d = 0x00;
  /* adc a,c */
  d = 0x00;
  /* adc a,l */
  d = 0x00;
  a = (uint8_t)(a - c);
  d = 0x00;
  a = 0;
  flag_logic(a);
  d = 0x00;
  a = a & d;
  flag_logic(a);
  d = 0x00;
  /* and (hl) */
  d = 0x00;
  a = a ^ d;
  flag_logic(a);
  d = 0x00;
  a = a ^ h;
  flag_logic(a);
  d = 0x00;
  a = a | l;
  flag_logic(a);
  d = 0x00;
  flag_cmp(a, h);
  d = 0x00;
  /* nop */
  cpu_rla();
  /* nop */
  a = mem_read8(bc());
  cpu_rla();
  /* nop */
  e = 0x17;
  /* nop */
  if (flag_nc()) goto lab_p27_L_42BC;
  /* nop */
  c = b;
  cpu_rla();
  /* nop */
  h = e;
  cpu_rla();
  /* nop */
  a = c;
  cpu_rla();
  /* nop */
  if (flag_m()) { p00_L_0017(); return; }
  set_de((uint16_t)(de() + 1));
  goto lab_p27_L_42B5;
  lab_p27_L_42B5: ;
  e = (uint8_t)(e - 1);
  goto lab_p27_L_42B8;
  lab_p27_L_42B8: ;
  mem_write16(0x0018, hl());
  set_hl(mem_read16(0x0018));
  lab_p27_L_42BC: ;
  goto lab_p27_L_42BE;
  lab_p27_L_42BE: ;
  if (flag_nc()) goto lab_p27_L_42D8;
  /* nop */
  mem_write8(hl(), 0x18);
  /* nop */
  d = a;
  goto lab_p27_L_42C7;
  lab_p27_L_42C7: ;
  mem_write8(hl(), e);
  goto lab_p27_L_42CA;
  lab_p27_L_42CA: ;
  a = d;
  goto lab_p27_L_42CD;
  lab_p27_L_42CD: ;
  a = a;
  goto lab_p27_L_42D0;
  lab_p27_L_42D0: ;
  a = (uint8_t)(a + h);
  goto lab_p27_L_42D3;
  lab_p27_L_42D3: ;
  a = (uint8_t)(a + a);
  goto lab_p27_L_42D6;
  lab_p27_L_42D6: ;
  /* adc a,l */
  goto lab_p27_L_42D9;
  lab_p27_L_42D8: ;
  /* nop */
  lab_p27_L_42D9: ;
  a = 0;
  flag_logic(a);
  goto lab_p27_L_42DC;
  lab_p27_L_42DC: ;
  a = a & e;
  flag_logic(a);
  goto lab_p27_L_42DF;
  lab_p27_L_42DF: ;
  a = a ^ b;
  flag_logic(a);
  goto lab_p27_L_42E2;
  lab_p27_L_42E2: ;
  flag_cmp(a, h);
  goto lab_p27_L_42E5;
  lab_p27_L_42E5: ;
  a = a | b;
  flag_logic(a);
  set_hl((uint16_t)(hl() + de()));
  /* nop */
  if (flag_nz()) { p00_L_0019(); return; }
  cpu_push_bc();
  set_hl((uint16_t)(hl() + de()));
  /* nop */
  p00_rst20();
  set_hl((uint16_t)(hl() + de()));
  /* nop */
  /* db 0xED,0x19 */
  /* nop */
  if (flag_p()) { p00_L_0019(); return; }
  c = 0x1B;
  /* nop */
  goto lab_p27_L_4317;
  lab_p27_L_4317: ;
  /* nop */
  l = a;
  e = (uint8_t)(e + 1);
  /* nop */
  mem_write8(hl(), l);
  e = (uint8_t)(e + 1);
  /* nop */
  a = e;
  e = (uint8_t)(e + 1);
  /* nop */
  a = (uint8_t)(a + c);
  e = (uint8_t)(e + 1);
  /* nop */
  /* adc a,c */
  e = (uint8_t)(e + 1);
  /* nop */
  /* adc a,a */
  e = (uint8_t)(e + 1);
  /* nop */
  /* sbc a,l */
  e = (uint8_t)(e + 1);
  /* nop */
  a = a & d;
  flag_logic(a);
  e = (uint8_t)(e + 1);
  /* nop */
  a = a ^ b;
  flag_logic(a);
  e = (uint8_t)(e + 1);
  /* nop */
  a = a ^ h;
  flag_logic(a);
  e = (uint8_t)(e + 1);
  /* nop */
  a = a | e;
  flag_logic(a);
  e = (uint8_t)(e + 1);
  /* nop */
  flag_cmp(a, a);
  e = (uint8_t)(e + 1);
  /* nop */
  /* di */
  e = (uint8_t)(e + 1);
  /* nop */
  if (flag_m()) p00_L_001C();
  /* scf */
  e = (uint8_t)(e - 1);
  /* nop */
  e = b;
  e = (uint8_t)(e - 1);
  /* nop */
  a = a ^ l;
  flag_logic(a);
  e = (uint8_t)(e - 1);
  /* nop */
  /* sbc a,0x1E */
  /* nop */
  if (flag_p()) p00_L_001E();
  e = b;
  cpu_rra();
  /* nop */
  e = a;
  cpu_rra();
  /* nop */
  flag_cmp(a, b);
  cpu_rra();
  /* nop */
  flag_cmp(a, e);
  cpu_rra();
  /* nop */
  if (flag_nz()) return;
  cpu_rra();
  /* nop */
  if (flag_pe()) return;
  cpu_rra();
  /* nop */
  b = b;
  if (flag_nz()) goto lab_p27_L_4366;
  lab_p27_L_4366: ;
  h = d;
  if (flag_nz()) goto lab_p27_L_4369;
  lab_p27_L_4369: ;
  if (flag_p()) { p00_rst20(); return; }
  a = mem_read8(bc());
  set_hl(0x4800);
  set_hl(0x4B00);
  set_hl(0x4E00);
  set_hl(0x5600);
  set_hl(0x6600);
  set_hl(0x7600);
  set_hl(0x8200);
  set_hl(0x8700);
  set_hl(0x8C00);
  set_hl(0x9100);
  set_hl(0x9600);
  set_hl(0x9B00);
  set_hl(0x9E00);
  set_hl(0xA400);
  set_hl(0xA700);
  set_hl(0xAA00);
  set_hl(0xB200);
  set_hl(0xB600);
  set_hl(0xC000);
  set_hl(0xC300);
  set_hl(0xCC00);
  set_hl(0xD100);
  set_hl(0xD600);
  set_hl(0xDB00);
  set_hl(0xE000);
  set_hl(0xE500);
  set_hl(0xE800);
  set_hl(0xFC00);
  set_hl(0x0A00);
  mem_write16(0x1D00, hl());
  mem_write16(0x2200, hl());
  mem_write16(0x2C00, hl());
  mem_write16(0x2F00, hl());
  mem_write16(0x4200, hl());
  mem_write16(0x5300, hl());
  mem_write16(0x5800, hl());
  mem_write16(0x6200, hl());
  mem_write16(0x6700, hl());
  mem_write16(0x7200, hl());
  mem_write16(0x7700, hl());
  mem_write16(0x8100, hl());
  mem_write16(0x8600, hl());
  mem_write16(0x9000, hl());
  mem_write16(0x9500, hl());
  mem_write16(0x9F00, hl());
  mem_write16(0xA900, hl());
  mem_write16(0xB300, hl());
  mem_write16(0xBD00, hl());
  mem_write16(0xC200, hl());
  p27_L_4400();
  return;
}

/* flash page 27 cpu 0x4400 (offset 0x0400) */
void p27_L_4400(void) {
  mem_write16(0xC700, hl());
  mem_write16(0xCC00, hl());
  mem_write16(0xCF00, hl());
  mem_write16(0xD200, hl());
  mem_write16(0xD900, hl());
  mem_write16(0xDE00, hl());
  mem_write16(0xE300, hl());
  mem_write16(0xE800, hl());
  mem_write16(0xED00, hl());
  mem_write16(0xF200, hl());
  mem_write16(0xF700, hl());
  mem_write16(0xFC00, hl());
  mem_write16(0xFF00, hl());
  mem_write16(0x0400, hl());
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  set_bc((uint16_t)(bc() - 1));
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_4454;
  /* nop */
  d = (uint8_t)(d - 1);
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  goto lab_p27_L_445A;
  lab_p27_L_4454: ;
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  d = d;
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  d = a;
  lab_p27_L_445A: ;
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  e = h;
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  e = a;
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  h = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  l = e;
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  mem_write8(hl(), b);
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  mem_write8(hl(), l);
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  a = b;
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  a = a;
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  a = (uint8_t)(a + h);
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  /* adc a,c */
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  /* adc a,h */
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  a = (uint8_t)(a - e);
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  /* sbc a,d */
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  a = a & h;
  flag_logic(a);
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  /* xor (hl) */
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  a = a | e;
  flag_logic(a);
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  flag_cmp(a, l);
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  if (flag_z()) p00_L_0023();
  p00_rst08();
  set_hl((uint16_t)(hl() + 1));
  /* nop */
  flag_cmp(a, l);
  h = (uint8_t)(h + 1);
  /* nop */
  cpu_pop_bc();
  h = (uint8_t)(h + 1);
  /* nop */
  cpu_push_bc();
  h = (uint8_t)(h + 1);
  /* nop */
  return;
}

/* flash page 27 cpu 0x4500 (offset 0x0500) */
void p27_L_4500(void) {
  set_bc(0x55F4);
  set_bc(0x56A8);
  set_bc(0x5752);
  set_bc(0x5795);
  set_bc(0x57AE);
  set_bc(0x57CF);
  set_bc(0x57E5);
  set_bc(0x57F3);
  set_bc(0x57F4);
  set_bc(0x5897);
  set_bc(0x5943);
  set_bc(0x5957);
  set_bc(0x5974);
  set_bc(0x5999);
  set_bc(0x59AC);
  set_bc(0x59E7);
  set_bc(0x5A63);
  set_bc(0x5A71);
  set_bc(0x5AAF);
  set_bc(0x5AC3);
  set_bc(0x5AF6);
  set_bc(0x5B76);
  set_bc(0x5B87);
  set_bc(0x5BEE);
  set_bc(0x5BF3);
  set_bc(0x5BFB);
  set_bc(0x5C09);
  set_bc(0x5C51);
  set_bc(0x5C80);
  set_bc(0x5C9F);
  set_bc(0x5CAA);
  set_bc(0x5D0E);
  set_bc(0x5E9C);
  set_bc(0x5EAF);
  set_bc(0x5EC1);
  set_bc(0x5F2E);
  set_bc(0x5F59);
  set_bc(0x5F72);
  set_bc(0x5FA8);
  set_bc(0x5FBD);
  set_bc(0x5FF2);
  set_bc(0x6048);
  set_bc(0x6055);
  set_bc(0x6064);
  set_bc(0x6087);
  set_bc(0x6096);
  set_bc(0x60D3);
  set_bc(0x610D);
  set_bc(0x6113);
  set_bc(0x6118);
  set_bc(0x6130);
  set_bc(0x61E9);
  set_bc(0x61F1);
  set_bc(0x61F4);
  set_bc(0x6286);
  set_bc(0x62BF);
  set_bc(0x62F0);
  set_bc(0x6376);
  set_bc(0x637C);
  set_bc(0x6390);
  set_bc(0x63D0);
  set_bc(0x63E8);
  set_bc(0x7986);
  b = (uint8_t)(b - 1);
  a = a & b;
  flag_logic(a);
  a = c;
  b = (uint8_t)(b - 1);
  p00_rst08();
  a = c;
  b = (uint8_t)(b - 1);
  d = b;
  a = d;
  b = (uint8_t)(b - 1);
  h = b;
  a = d;
  b = (uint8_t)(b - 1);
  h = mem_read8(hl());
  h = mem_read8(hl());
  set_bc(0x4E9B);
  a = c;
  /* or (hl) */
  c = mem_read8(hl());
  a = c;
  /* ex (sp),hl */
  c = mem_read8(hl());
  a = c;
  d = e;
  d = b;
  a = c;
  h = a;
  d = b;
  a = c;
  l = c;
  d = b;
  a = c;
  set_hl((uint16_t)(hl() + bc()));
  d = l;
  a = c;
  d = d;
  e = b;
  a = c;
  a = (uint8_t)(a - b);
  e = b;
  a = c;
  /* ex (sp),hl */
  e = e;
  a = c;
  if (flag_m()) p27_L_795B();
  set_hl(0x795C);
  b = d;
  e = h;
  a = c;
  set_hl((uint16_t)(hl() + 1));
  e = a;
  a = c;
  sp = hl();
  h = b;
  a = c;
  a = mem_read8(de());
  h = c;
  a = c;
  e = b;
  l = b;
  a = c;
  a = d;
  l = b;
  a = c;
  /* adc a,l */
  l = b;
  a = c;
  /* nop */
  b = b;
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = b;
  mem_write8(bc(), a);
  l = (uint8_t)(l + 1);
  b = b;
  mem_write8(bc(), a);
  a = (uint8_t)(a + 1);
  b = b;
  mem_write8(bc(), a);
  b = b;
  b = b;
  mem_write8(bc(), a);
  b = h;
  b = b;
  mem_write8(bc(), a);
  e = mem_read8(hl());
  b = b;
  mem_write8(bc(), a);
  l = b;
  b = b;
  mem_write8(bc(), a);
  l = h;
  b = b;
  mem_write8(bc(), a);
  a = (uint8_t)(a - b);
  b = b;
  mem_write8(bc(), a);
  /* adc a,a */
  b = h;
  mem_write8(bc(), a);
  set_hl((uint16_t)(hl() + sp));
  b = mem_read8(hl());
  mem_write8(bc(), a);
  c = a;
  b = mem_read8(hl());
  mem_write8(bc(), a);
  a = (uint8_t)(a + l);
  b = a;
  mem_write8(bc(), a);
  /* sbc a,e */
  b = a;
  mem_write8(bc(), a);
  /* sbc a,(hl) */
  b = a;
  mem_write8(bc(), a);
  a = a & d;
  flag_logic(a);
  b = a;
  mem_write8(bc(), a);
  /* xor (hl) */
  b = a;
  mem_write8(bc(), a);
  a = a | c;
  flag_logic(a);
  b = a;
  mem_write8(bc(), a);
  if (flag_nz()) return;
  b = a;
  mem_write8(bc(), a);
  if (flag_c()) return;
  b = a;
  mem_write8(bc(), a);
  if (flag_c()) p00_L_0247();
  if (flag_m()) return;
  c = b;
  mem_write8(bc(), a);
  d = b;
  c = c;
  mem_write8(bc(), a);
  e = mem_read8(hl());
  c = c;
  mem_write8(bc(), a);
  l = c;
  c = c;
  mem_write8(bc(), a);
  /* adc a,h */
  c = c;
  mem_write8(bc(), a);
  set_hl((uint16_t)(hl() + sp));
  c = e;
  mem_write8(bc(), a);
  a = hw_in(0x4C);
  mem_write8(bc(), a);
  set_de((uint16_t)(de() + 1));
  c = l;
  mem_write8(bc(), a);
  /* or (hl) */
  c = mem_read8(hl());
  mem_write8(bc(), a);
  /* sbc a,e */
  d = b;
  mem_write8(bc(), a);
  os_bcall(0x0257);
  a = a | c;
  flag_logic(a);
  e = c;
  mem_write8(bc(), a);
  if (flag_m()) return;
  e = c;
  mem_write8(bc(), a);
  mem_write16(0x025A, hl());
  c = e;
  e = d;
  mem_write8(bc(), a);
  c = h;
  h = b;
  mem_write8(bc(), a);
  /* and (hl) */
  h = e;
  mem_write8(bc(), a);
  cpu_rrca();
  h = h;
  mem_write8(bc(), a);
  set_hl((uint16_t)(hl() + sp));
  h = l;
  mem_write8(bc(), a);
  a = (uint8_t)(a - e);
  if (flag_z()) goto lab_p27_L_4684;
  lab_p27_L_4684: ;
  /* sbc a,b */
  if (flag_z()) goto lab_p27_L_4687;
  lab_p27_L_4687: ;
  /* sbc a,l */
  if (flag_z()) goto lab_p27_L_468A;
  lab_p27_L_468A: ;
  /* and (hl) */
  if (flag_z()) goto lab_p27_L_468D;
  lab_p27_L_468D: ;
  a = a ^ e;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_4690;
  lab_p27_L_4690: ;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_4693;
  lab_p27_L_4693: ;
  a = a | l;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_4696;
  lab_p27_L_4696: ;
  p00_rst28_bcall();
  return;
}

/* flash page 27 cpu 0x4802 (offset 0x0802) */
void p27_L_4802(void) {
  b = h;
  b = (uint8_t)(b + 1);
  set_hl((uint16_t)(hl() - 1));
  b = h;
  b = (uint8_t)(b + 1);
  if (flag_po()) p00_L_0444();
  b = e;
  b = l;
  b = (uint8_t)(b + 1);
  h = h;
  b = a;
  b = (uint8_t)(b + 1);
  flag_cmp(a, h);
  b = a;
  b = (uint8_t)(b + 1);
  flag_cmp(a, e);
  c = b;
  b = (uint8_t)(b + 1);
  cpu_cp_hl();
  c = b;
  b = (uint8_t)(b + 1);
  /* scf */
  c = l;
  b = (uint8_t)(b + 1);
  a = a & c;
  flag_logic(a);
  e = e;
  b = (uint8_t)(b + 1);
  flag_cmp(a, e);
  e = e;
  b = (uint8_t)(b + 1);
  cpu_rrca();
  e = h;
  b = (uint8_t)(b + 1);
  e = l;
  e = h;
  b = (uint8_t)(b + 1);
  l = l;
  e = h;
  b = (uint8_t)(b + 1);
  a = a | c;
  flag_logic(a);
  e = h;
  b = (uint8_t)(b + 1);
  /* sbc a,0x5C */
  b = (uint8_t)(b + 1);
  mem_write8(de(), a);
  e = l;
  b = (uint8_t)(b + 1);
  mem_write8(hl(), l);
  e = l;
  b = (uint8_t)(b + 1);
  p00_rst38_isr();
  l = a;
  set_bc((uint16_t)(bc() + 1));
  a = (uint8_t)(a + 0x5D);
  b = (uint8_t)(b + 1);
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  b = (uint8_t)(b + 1);
  l = mem_read8(hl());
  e = mem_read8(hl());
  b = (uint8_t)(b + 1);
  a = h;
  e = mem_read8(hl());
  b = (uint8_t)(b + 1);
  /* adc a,c */
  e = mem_read8(hl());
  b = (uint8_t)(b + 1);
  /* sub (hl) */
  e = mem_read8(hl());
  b = (uint8_t)(b + 1);
  a = a & e;
  flag_logic(a);
  e = mem_read8(hl());
  b = (uint8_t)(b + 1);
  e = (uint8_t)(e + 1);
  e = a;
  b = (uint8_t)(b + 1);
  c = c;
  e = a;
  b = (uint8_t)(b + 1);
  h = l;
  e = a;
  b = (uint8_t)(b + 1);
  flag_cmp(a, c);
  e = a;
  b = (uint8_t)(b + 1);
  flag_cmp(a, h);
  e = a;
  b = (uint8_t)(b + 1);
  a = a ^ 0xFF;
  h = b;
  b = (uint8_t)(b + 1);
  a = a & a;
  flag_logic(a);
  h = b;
  b = (uint8_t)(b + 1);
  p00_rst18();
  h = b;
  b = (uint8_t)(b + 1);
  if (flag_m()) return;
  h = b;
  b = (uint8_t)(b + 1);
  /* and (hl) */
  h = c;
  b = (uint8_t)(b + 1);
  a = hw_in(0x61);
  b = (uint8_t)(b + 1);
  b = 0x62;
  b = (uint8_t)(b + 1);
  d = l;
  h = d;
  b = (uint8_t)(b + 1);
  h = d;
  h = d;
  b = (uint8_t)(b + 1);
  h = a;
  h = d;
  b = (uint8_t)(b + 1);
  if (flag_c()) return;
  h = e;
  b = (uint8_t)(b + 1);
  if (flag_c()) p00_L_0463();
  a = (uint8_t)(a - h);
  h = h;
  b = (uint8_t)(b + 1);
  flag_cmp(a, l);
  h = h;
  b = (uint8_t)(b + 1);
  a = a & 0x65;
  flag_logic(a);
  b = (uint8_t)(b + 1);
  a = (uint8_t)(a + a);
  h = mem_read8(hl());
  b = (uint8_t)(b + 1);
  /* adc a,a */
  h = a;
  b = (uint8_t)(b + 1);
  a = a | a;
  flag_logic(a);
  l = c;
  b = (uint8_t)(b + 1);
  d = c;
  mem_write8(hl(), c);
  b = (uint8_t)(b + 1);
  a = e;
  mem_write8(hl(), c);
  b = (uint8_t)(b + 1);
  mem_write8(hl(), 0x75);
  b = (uint8_t)(b + 1);
  c = mem_read8(hl());
  halt();
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x77);
  b = (uint8_t)(b + 1);
  a = a | d;
  flag_logic(a);
  a = d;
  b = (uint8_t)(b + 1);
  if (flag_pe()) p00_L_047A();
  set_bc((uint16_t)(bc() + 1));
  a = e;
  b = (uint8_t)(b + 1);
  goto lab_p27_L_4929;
  lab_p27_L_4929: ;
  b = 0xBE;
  b = h;
  b = 0x16;
  set_hl((uint16_t)(hl() + de()));
  /* nop */
  a = mem_read8(de());
  set_hl((uint16_t)(hl() + de()));
  /* nop */
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + de()));
  /* nop */
  if (flag_z()) return;
  b = h;
  b = 0xD5;
  b = h;
  b = 0xEB;
  b = h;
  b = 0xFD;
  b = h;
  b = 0x3B;
  b = l;
  b = 0xA8;
  b = l;
  b = 0xF4;
  b = l;
  b = 0x56;
  b = mem_read8(hl());
  b = 0x71;
  b = mem_read8(hl());
  b = 0xDE;
  b = mem_read8(hl());
  b = 0xFC;
  b = mem_read8(hl());
  b = 0x95;
  b = a;
  b = 0xD1;
  b = a;
  b = 0xDA;
  b = a;
  b = 0xE3;
  b = a;
  b = 0xF4;
  b = a;
  b = 0x25;
  c = b;
  b = 0x26;
  c = b;
  b = 0x44;
  c = b;
  b = 0x71;
  c = b;
  b = 0x8B;
  c = c;
  b = 0xA0;
  c = h;
  b = 0x0E;
  c = l;
  b = 0x86;
  c = l;
  b = 0xF0;
  d = b;
  b = 0xCD;
  d = d;
  b = 0xEC;
  d = d;
  b = 0xFA;
  d = d;
  b = 0x08;
  d = e;
  b = 0x16;
  d = e;
  b = 0x7D;
  d = l;
  b = 0x99;
  d = l;
  b = 0xF9;
  d = a;
  b = 0xF5;
  e = b;
  b = 0xCD;
  e = e;
  b = 0x93;
  e = h;
  b = 0x0F;
  e = l;
  b = 0x34;
  e = l;
  b = 0x6C;
  e = l;
  b = 0xBF;
  e = l;
  b = 0xC2;
  e = l;
  b = 0xDB;
  e = l;
  b = 0xF9;
  e = l;
  b = 0x54;
  e = a;
  b = 0xA8;
  e = a;
  b = 0xD5;
  e = a;
  b = 0x0A;
  h = b;
  b = 0x5B;
  l = a;
  b = 0x85;
  l = a;
  b = 0x8C;
  l = a;
  b = 0x2D;
  mem_write8(hl(), c);
  b = 0x9C;
  mem_write8(hl(), c);
  b = 0xF7;
  mem_write8(hl(), c);
  b = 0x07;
  mem_write8(hl(), d);
  b = 0xB2;
  mem_write8(hl(), d);
  b = 0xEE;
  mem_write8(hl(), d);
  b = 0xEB;
  l = mem_read8(hl());
  cpu_rlca();
  b = b;
  mem_write8(hl(), c);
  cpu_rlca();
  h = mem_read8(hl());
  mem_write8(hl(), c);
  cpu_rlca();
  /* adc a,h */
  mem_write8(hl(), h);
  b = 0xA4;
  mem_write8(hl(), h);
  b = 0xCE;
  mem_write8(hl(), h);
  b = 0xCE;
  cpu_rla();
  /* nop */
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  halt();
  b = 0x47;
  halt();
  b = 0xF2;
  mem_write8(hl(), a);
  b = 0x64;
  a = mem_read8(hl());
  b = 0x69;
  a = mem_read8(hl());
  b = 0x74;
  b = h;
  cpu_rlca();
  a = 0;
  flag_logic(a);
  b = h;
  cpu_rlca();
  a = a | a;
  flag_logic(a);
  b = h;
  cpu_rlca();
  p00_rst08();
  b = h;
  cpu_rlca();
  l = b;
  b = b;
  a = h;
  c = a;
  c = mem_read8(hl());
  a = h;
  set_hl((uint16_t)(hl() + 1));
  c = a;
  a = h;
  c = c;
  c = a;
  a = h;
  a = (uint8_t)(a - c);
  c = a;
  a = h;
  d = d;
  e = d;
  a = h;
  e = b;
  halt();
  cpu_rlca();
  a = h;
  c = l;
  cpu_rlca();
  flag_cmp(a, b);
  c = l;
  cpu_rlca();
  l = e;
  c = a;
  cpu_rlca();
  a = mem_read8(hl());
  c = a;
  cpu_rlca();
  flag_cmp(a, d);
  c = a;
  cpu_rlca();
  if (flag_po()) { p00_L_074F(); return; }
  /* daa */
  d = b;
  cpu_rlca();
  c = e;
  d = b;
  cpu_rlca();
  e = a;
  d = b;
  cpu_rlca();
  a = (uint8_t)(a - d);
  d = b;
  cpu_rlca();
  /* di */
  d = b;
  cpu_rlca();
  if (flag_z()) goto lab_p27_L_4A97;
  cpu_rlca();
  set_hl((uint16_t)(hl() - 1));
  d = c;
  cpu_rlca();
  sp = 0x0752;
  if (flag_c()) { p00_L_0752(); return; }
  c = e;
  d = e;
  cpu_rlca();
  if (flag_z()) return;
  d = e;
  cpu_rlca();
  if (flag_po()) p00_L_0753();
  e = e;
  d = h;
  cpu_rlca();
  l = h;
  d = h;
  cpu_rlca();
  a = (uint8_t)(a - c);
  d = h;
  cpu_rlca();
  flag_cmp(a, l);
  d = h;
  cpu_rlca();
  /* adc a,(hl) */
  e = c;
  cpu_rlca();
  /* sbc a,b */
  e = c;
  cpu_rlca();
  p00_rst10();
  e = e;
  cpu_rlca();
  a = hw_in(0x5B);
  cpu_rlca();
  a = (uint8_t)(a + b);
  e = h;
  cpu_rlca();
  a = (uint8_t)(a + b);
  e = h;
  cpu_rlca();
  set_de((uint16_t)(de() + 1));
  e = l;
  cpu_rlca();
  d = 0x5D;
  cpu_rlca();
  c = mem_read8(hl());
  e = l;
  cpu_rlca();
  a = (uint8_t)(a - 0x60);
  cpu_rlca();
  if (flag_m()) { p00_L_0767(); return; }
  d = mem_read8(hl());
  l = h;
  cpu_rlca();
  /* sbc a,(hl) */
  b = d;
  a = b;
  a = a & b;
  flag_logic(a);
  b = d;
  a = b;
  a = a | e;
  flag_logic(a);
  d = b;
  a = b;
  a = (uint8_t)(a + e);
  e = b;
  a = b;
  a = a & d;
  flag_logic(a);
  e = b;
  lab_p27_L_4A97: ;
  a = b;
  a = a ^ b;
  flag_logic(a);
  e = b;
  a = b;
  mem_write8(0x7859, a);
  a = (uint8_t)(a - 1);
  e = c;
  a = b;
  a = d;
  e = d;
  a = b;
  a = (uint8_t)(a + e);
  e = d;
  a = b;
  a = a | e;
  flag_logic(a);
  e = d;
  a = b;
  cpu_ex_af();
  e = e;
  a = b;
  cpu_pop_hl();
  e = e;
  a = b;
  a = a ^ e;
  flag_logic(a);
  e = h;
  a = b;
  set_hl((uint16_t)(hl() + sp));
  h = b;
  a = b;
  /* ccf */
  h = b;
  a = b;
  c = l;
  h = b;
  a = b;
  if (flag_pe()) return;
  h = b;
  a = b;
  p00_rst38_isr();
  h = b;
  a = b;
  cpu_rrca();
  h = c;
  a = b;
  cpu_rla();
  h = c;
  a = b;
  cpu_rra();
  h = c;
  a = b;
  /* daa */
  h = c;
  a = b;
  c = a;
  h = c;
  a = b;
  d = a;
  h = c;
  a = b;
  e = l;
  h = c;
  a = b;
  a = mem_read8(0x7866);
  /* ccf */
  h = mem_read8(hl());
  a = b;
  b = h;
  h = mem_read8(hl());
  a = b;
  c = c;
  h = mem_read8(hl());
  a = b;
  c = h;
  h = mem_read8(hl());
  a = b;
  if (flag_nz()) p27_L_7866();
  a = mem_read8(de());
  l = e;
  a = b;
  set_hl((uint16_t)(hl() + 1));
  l = e;
  a = b;
  if (flag_m()) return;
  mem_write8(hl(), c);
  a = b;
  /* daa */
  mem_write8(hl(), l);
  a = b;
  set_hl(mem_read16(0x7875));
  p00_rst20();
  e = h;
  a = b;
  if (flag_m()) p27_L_785D();
  mem_write16(0x785E, hl());
  if (flag_nz()) goto lab_p27_L_4B5C;
  a = b;
  set_hl((uint16_t)(hl() + 1));
  e = c;
  a = b;
  a = a ^ 0xFF;
  e = c;
  a = b;
  set_bc((uint16_t)(bc() - 1));
  h = mem_read8(hl());
  a = b;
  e = (uint8_t)(e - 1);
  h = mem_read8(hl());
  a = b;
  p00_rst00_boot();
  l = b;
  a = b;
  a = 0x6F;
  a = b;
  b = c;
  l = a;
  a = b;
  c = b;
  l = a;
  a = b;
  c = e;
  l = a;
  a = b;
  d = mem_read8(hl());
  l = a;
  a = b;
  e = h;
  l = a;
  a = b;
  e = a;
  l = a;
  a = b;
  h = h;
  l = a;
  a = b;
  set_hl((uint16_t)(hl() + de()));
  mem_write8(hl(), b);
  a = b;
  b = mem_read8(hl());
  mem_write8(hl(), b);
  a = b;
  c = c;
  mem_write8(hl(), b);
  a = b;
  mem_write8(hl(), c);
  mem_write8(hl(), b);
  a = b;
  a = (uint8_t)(a - e);
  mem_write8(hl(), b);
  a = b;
  /* sub (hl) */
  mem_write8(hl(), b);
  a = b;
  /* sbc a,(hl) */
  mem_write8(hl(), b);
  a = b;
  a = a ^ h;
  flag_logic(a);
  mem_write8(hl(), b);
  a = b;
  if (flag_po()) p27_L_7871();
  p00_rst20();
  mem_write8(hl(), c);
  a = b;
  e = l;
  mem_write8(hl(), d);
  a = b;
  h = c;
  mem_write8(hl(), d);
  a = b;
  h = l;
  mem_write8(hl(), d);
  a = b;
  /* sbc a,d */
  mem_write8(hl(), e);
  a = b;
  a = a & e;
  flag_logic(a);
  mem_write8(hl(), e);
  a = b;
  /* adc a,e */
  mem_write8(hl(), h);
  a = b;
  /* sbc a,b */
  lab_p27_L_4B5C: ;
  mem_write8(hl(), h);
  a = b;
  a = a ^ b;
  flag_logic(a);
  mem_write8(hl(), h);
  a = b;
  a = a | c;
  flag_logic(a);
  mem_write8(hl(), h);
  a = b;
  if (flag_nz()) goto lab_p27_L_7874;
  set_hl((uint16_t)(hl() + hl()));
  h = (uint8_t)(h + 1);
  /* nop */
  mem_write8(hl(), c);
  l = a;
  a = b;
  if (flag_nz()) return;
  l = a;
  a = b;
  mem_write8(bc(), a);
  mem_write8(hl(), b);
  a = b;
  b = (uint8_t)(b - 1);
  mem_write8(hl(), b);
  a = b;
  c = (uint8_t)(c + 1);
  mem_write8(hl(), b);
  a = b;
  /* nop */
  b = b;
  a = c;
  a = (uint8_t)(a - 1);
  b = b;
  a = c;
  cpu_pop_bc();
  b = b;
  a = c;
  h = 0x41;
  a = c;
  set_hl((uint16_t)(hl() + sp));
  b = c;
  a = c;
  if (flag_nc()) { p00_L_027A(); return; }
  /* sub (hl) */
  a = e;
  mem_write8(bc(), a);
  a = c;
  b = mem_read8(hl());
  a = c;
  /* adc a,e */
  b = mem_read8(hl());
  a = c;
  a = a | d;
  flag_logic(a);
  b = mem_read8(hl());
  a = c;
  return;
  lab_p27_L_7874: ;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) & ~(1u << 2)));
  return;
}

/* flash page 27 cpu 0x4C00 (offset 0x0C00) */
void p27_L_4C00(void) {
  a = (uint8_t)(a + a);
  /* nop */
  /* nop */
  /* sub (hl) */
  d = e;
  a = e;
  d = a;
  d = mem_read8(hl());
  a = e;
  flag_cmp(a, h);
  d = mem_read8(hl());
  a = e;
  if (flag_z()) goto lab_p27_L_7B56;
  p00_rst18();
  d = mem_read8(hl());
  a = e;
  /* di */
  d = mem_read8(hl());
  a = e;
  a = (uint8_t)(a - b);
  d = mem_read8(hl());
  a = e;
  /* sbc a,e */
  d = mem_read8(hl());
  a = e;
  b = h;
  d = h;
  a = e;
  /* adc a,e */
  d = e;
  a = e;
  a = (uint8_t)(a - c);
  d = e;
  a = e;
  a = a & b;
  flag_logic(a);
  d = mem_read8(hl());
  a = e;
  a = a ^ h;
  flag_logic(a);
  d = mem_read8(hl());
  a = e;
  mem_write8(hl(), h);
  d = mem_read8(hl());
  a = e;
  if (flag_pe()) goto lab_p27_L_7B56;
  c = a;
  l = l;
  a = e;
  d = b;
  l = l;
  a = e;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  mem_write8(hl(), b);
  a = e;
  d = l;
  b = c;
  b = (uint8_t)(b + 1);
  if (flag_nc()) goto lab_p27_L_4C57;
  /* nop */
  b = c;
  d = mem_read8(hl());
  b = 0xC0;
  e = h;
  set_bc(0x01CD);
  /* nop */
  cpu_push_hl();
  h = b;
  a = l;
  os_jp_hl();
  return;
  lab_p27_L_4C57: ;
  b = d;
  mem_write8(hl(), b);
  a = e;
  b = mem_read8(hl());
  mem_write8(hl(), b);
  a = e;
  b = e;
  d = a;
  a = e;
  if (flag_pe()) { p00_L_0442(); return; }
  a = a | e;
  flag_logic(a);
  b = d;
  b = (uint8_t)(b + 1);
  /* adc a,b */
  l = l;
  a = e;
  a = a & b;
  flag_logic(a);
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  h = mem_read8(hl());
  cpu_rlca();
  /* nop */
  if (flag_z()) return;
  set_bc(0x1A00);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_4C75;
  lab_p27_L_4C75: ;
  /* nop */
  d = c;
  a = e;
  h = (uint8_t)(h - 1);
  d = c;
  a = e;
  sp = (uint16_t)(sp - 1);
  h = c;
  a = c;
  /* db 0xDD */
  halt();
  a = e;
  if (flag_po()) goto lab_p27_L_7B76;
  hw_out(0x76, a);
  a = e;
  if (flag_c()) return;
  halt();
  a = e;
  sp = hl();
  mem_write8(hl(), b);
  a = e;
  /* adc a,0x76 */
  a = e;
  e = c;
  a = mem_read8(bc());
  /* nop */
  a = a ^ l;
  flag_logic(a);
  mem_write8(bc(), a);
  /* nop */
  h = d;
  d = a;
  a = e;
  e = d;
  mem_write8(hl(), c);
  a = e;
  a = (uint8_t)(a + h);
  mem_write8(bc(), a);
  /* nop */
  if (flag_m()) p27_L_7B70();
  d = mem_read8(hl());
  e = d;
  a = e;
  /* adc a,0x57 */
  a = e;
  if (flag_p()) return;
  d = a;
  a = e;
  flag_set_z((b & (1u << 3)) == 0);
  a = e;
  if (flag_c()) { p00_L_0161(); return; }
  if (flag_po()) { p00_L_015C(); return; }
  if (flag_z()) p27_L_7B5D();
  d = b;
  e = h;
  a = e;
  /* adc a,c */
  e = d;
  a = e;
  a = e;
  e = d;
  a = e;
  b = h;
  e = d;
  a = e;
  l = (uint8_t)(l + 1);
  e = d;
  a = e;
  a = h;
  e = d;
  a = e;
  if (flag_p()) p27_L_7B5C();
  e = c;
  e = h;
  a = e;
  d = e;
  e = e;
  a = e;
  cpu_pop_hl();
  e = d;
  a = e;
  if (flag_pe()) { p27_L_7B5D(); return; }
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  b = mem_read8(hl());
  b = 0x82;
  h = d;
  a = e;
  /* adc a,c */
  e = d;
  a = e;
  a = (uint8_t)(a - l);
  h = d;
  a = e;
  b = h;
  e = d;
  a = e;
  l = (uint8_t)(l + 1);
  e = d;
  a = e;
  hw_out(0x63, a);
  a = e;
  d = h;
  h = e;
  set_bc(0x5AC3);
  a = e;
  p00_rst10();
  e = e;
  a = e;
  cpu_push_af();
  e = h;
  a = e;
  if (flag_po()) p27_L_7B5D();
  return;
  lab_p27_L_7B56: ;
  p00_rst38_isr();
  p27_L_7B57();
  return;
  lab_p27_L_7B76: ;
  p00_rst38_isr();
  p00_rst38_isr();
  p27_L_7B78();
  return;
}

/* flash page 27 cpu 0x4FA0 (offset 0x0FA0) */
void p27_L_4FA0(void) {
  mem_write8(hl(), h);
  b = (uint8_t)(b - 1);
  if (flag_m()) { p00_L_0571(); return; }
  cpu_pop_bc();
  b = mem_read8(hl());
  b = (uint8_t)(b - 1);
  a = a | a;
  flag_logic(a);
  goto lab_p27_L_4FAB;
  lab_p27_L_4FAB: ;
  b = c;
  a = c;
  a = e;
  cpu_ex_de_hl();
  mem_write8(hl(), a);
  a = e;
  c = h;
  a = c;
  a = e;
  mem_write8((uint16_t)(iy + 0x7B), a);
  d = a;
  a = c;
  a = e;
  c = (uint8_t)(c - 1);
  a = b;
  a = e;
  a = 0;
  flag_logic(a);
  c = d;
  set_bc((uint16_t)(bc() + 1));
  if (flag_m()) { p00_L_034A(); return; }
  e = (uint8_t)(e + 1);
  d = a;
  set_bc((uint16_t)(bc() + 1));
  l = (uint8_t)(l + 1);
  cpu_rra();
  /* nop */
  e = mem_read8(hl());
  cpu_rra();
  /* nop */
  a = (uint8_t)(a - e);
  c = b;
  a = b;
  h = d;
  a = c;
  a = e;
  cpu_rra();
  a = b;
  a = e;
  cpu_push_bc();
  l = d;
  b = 0x11;
  h = a;
  cpu_rlca();
  flag_cmp(a, l);
  h = l;
  cpu_rlca();
  /* or (hl) */
  h = mem_read8(hl());
  cpu_rlca();
  a = c;
  d = mem_read8(hl());
  a = e;
  l = l;
  a = c;
  a = e;
  if (flag_nc()) goto lab_p27_L_5061;
  a = e;
  a = b;
  a = c;
  a = e;
  d = d;
  a = b;
  a = e;
  b = l;
  a = b;
  a = e;
  a = (uint8_t)(a + e);
  a = c;
  a = e;
  b = b;
  a = b;
  a = e;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  a = b;
  a = e;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  l = d;
  mem_write8(bc(), a);
  b = h;
  l = d;
  mem_write8(bc(), a);
  p27_L_5002();
  return;
  lab_p27_L_5061: ;
  a = c;
  d = 0x52;
  a = c;
  if (flag_p()) return;
  d = d;
  a = c;
  l = 0x5C;
  a = c;
  cpu_push_bc();
  a = c;
  a = e;
  p27_L_7B78();
  return;
}

/* flash page 27 cpu 0x5002 (offset 0x1002) */
void p27_L_5002(void) {
  a = (uint8_t)(a + 1);
  h = mem_read8(hl());
  set_bc(0x663E);
  set_bc(0x086E);
  /* nop */
  a = (uint8_t)(a + a);
  c = c;
  b = 0xE3;
  set_hl((uint16_t)(hl() + de()));
  /* nop */
  h = b;
  set_hl((uint16_t)(hl() + de()));
  /* nop */
  a = a | c;
  flag_logic(a);
  h = l;
  a = l;
  c = c;
  l = e;
  a = l;
  e = (uint8_t)(e + 1);
  l = l;
  a = h;
  /* ex (sp),hl */
  set_bc(0x2F00);
  h = (uint8_t)(h + 1);
  /* nop */
  a = 0x24;
  /* nop */
  /* adc a,(hl) */
  a = c;
  a = e;
  h = h;
  a = b;
  a = e;
  /* sbc a,c */
  a = c;
  a = e;
  halt();
  a = b;
  a = e;
  a = a & h;
  flag_logic(a);
  a = c;
  a = e;
  /* adc a,b */
  a = b;
  a = e;
  h = l;
  b = c;
  b = (uint8_t)(b + 1);
  /* scf */
  b = b;
  b = (uint8_t)(b + 1);
  d = mem_read8(hl());
  e = d;
  set_bc((uint16_t)(bc() + 1));
  a = (uint8_t)(a - l);
  d = l;
  cpu_rlca();
  a = 0;
  flag_logic(a);
  a = c;
  a = e;
  a = a & c;
  flag_logic(a);
  a = b;
  a = e;
  flag_cmp(a, d);
  a = c;
  a = e;
  a = a | e;
  flag_logic(a);
  a = b;
  a = e;
  cpu_exx();
  e = a;
  cpu_rlca();
  set_hl((uint16_t)(hl() + de()));
  e = l;
  a = c;
  a = a ^ 0xFF;
  e = mem_read8(hl());
  cpu_rlca();
  goto lab_p27_L_50D2;
  lab_p27_L_50D2: ;
  a = b;
  a = e;
  mem_write8(hl(), e);
  h = e;
  a = d;
  l = mem_read8(hl());
  l = mem_read8(hl());
  a = b;
  p00_rst20();
  l = a;
  a = b;
  a = a & d;
  flag_logic(a);
  halt();
  cpu_rlca();
  a = a ^ c;
  flag_logic(a);
  h = (uint8_t)(h + 1);
  /* nop */
  mem_write8(0x7D79, a);
  set_hl(mem_read16(0x7D7C));
  b = mem_read8(hl());
  l = a;
  a = h;
  p27_L_50EC();
  return;
}

/* flash page 27 cpu 0x50EC (offset 0x10EC) */
void p27_L_50EC(void) {
  set_hl(0x50F3);
  p00_L_07CC();
  return;
}

/* flash page 27 cpu 0x5100 (offset 0x1100) */
void p27_L_5100(void) {
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) & ~(1u << 2)));
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p27_L_5117;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 2)));
  lab_p27_L_5117: ;
  /* di */
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 0)));
  a = 0x15;
  mem_write8(0x8672, a);
  p00_L_2D8D();
  return;
}

/* flash page 27 cpu 0x51B4 (offset 0x11B4) */
void p27_L_51B4(void) {
  p00_L_36CF();
  p00_L_166E();
  p00_L_36D5();
  p00_L_1653();
  p27_L_5706();
  cpu_push_af();
  if (flag_z()) p27_L_56C5();
  cpu_pop_af();
  return;
}

/* flash page 27 cpu 0x51D0 (offset 0x11D0) */
void p27_L_51D0(void) {
  set_bc(mem_read16(0x844B));
  cpu_push_bc();
  p27_L_5582();
  p27_L_5203();
  p27_L_5591();
  cpu_pop_bc();
  mem_write16(0x844B, bc());
  p27_L_536F();
  return;
}

/* flash page 27 cpu 0x51E6 (offset 0x11E6) */
void p27_L_51E6(void) {
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  a = 0;
  flag_logic(a);
  mem_write8(0x97A8, a);
  a = 0x08;
  mem_write8(0x97A6, a);
  p00_L_17FA();
  return;
}

/* flash page 27 cpu 0x5203 (offset 0x1203) */
void p27_L_5203(void) {
  mem_write8((uint16_t)(iy + 0x2E), (uint8_t)(mem_read8((uint16_t)(iy + 0x2E)) & ~(1u << 0)));
  p27_L_51E6();
  p00_L_3D2F();
  set_hl(0x8100);
  a = 0;
  flag_logic(a);
  mem_write8(0x8006, a);
  goto lab_p27_L_521E;
  lab_p27_L_5216: ;
  set_hl(0x8006);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  cpu_pop_hl();
  p27_L_5381();
  lab_p27_L_521E: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p27_L_522E;
  cpu_pop_hl();
  p00_L_3D29();
  a = 0x01;
  p27_L_5719();
  return;
  lab_p27_L_522E: ;
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p27_L_5216;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p27_L_5242;
  lab_p27_L_5236: ;
  p27_L_5348();
  cpu_ex_de_hl();
  p00_L_3C8D();
  p27_L_5357();
  goto lab_p27_L_5216;
  lab_p27_L_5242: ;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p27_L_5236;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p27_L_524F;
  p27_L_5275();
  goto lab_p27_L_5216;
  lab_p27_L_524F: ;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p27_L_5259;
  p27_L_525F();
  set_hl((uint16_t)(hl() - 1));
  goto lab_p27_L_5236;
  lab_p27_L_5259: ;
  p27_L_52B2();
  goto lab_p27_L_5216;
}

/* flash page 27 cpu 0x525E (offset 0x125E) */
void p27_L_525E(void) {
  set_hl((uint16_t)(hl() + 1));
  p27_L_525F();
  return;
}

/* flash page 27 cpu 0x525F (offset 0x125F) */
void p27_L_525F(void) {
  set_hl((uint16_t)(hl() + 1));
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = mem_read8(hl());
  a = (uint8_t)(a + 0x30);
  p00_L_3F9F();
  a = 0x3A;
  p00_L_3F9F();
  return;
}

/* flash page 27 cpu 0x5270 (offset 0x1270) */
void p27_L_5270(void) {
  p27_L_536F();
  if (flag_z()) return;
  set_hl((uint16_t)(hl() + 1));
  p27_L_5275();
  return;
}

/* flash page 27 cpu 0x5275 (offset 0x1275) */
void p27_L_5275(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  set_hl((uint16_t)(hl() + 1));
  p27_L_5349();
  cpu_ex_de_hl();
  p00_L_3D1D();
  a = mem_read8(hl());
  /* neg */
  a = (uint8_t)(a + 0x10);
  cpu_push_af();
  p00_L_3C8D();
  p27_L_56B7();
  a = 0x10;
  p00_L_3639();
  set_hl(0x848D);
  cpu_pop_af();
  flag_cmp(a, c);
  if (flag_nc()) goto lab_p27_L_52A5;
  mem_write8(hl(), a);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  a = 0xCE;
  mem_write8(hl(), a);
  cpu_sbc_hl_de();
  goto lab_p27_L_52A6;
  lab_p27_L_52A5: ;
  mem_write8(hl(), c);
  lab_p27_L_52A6: ;
  p00_L_3C8D();
  p27_L_5357();
  return;
}

/* flash page 27 cpu 0x52AD (offset 0x12AD) */
void p27_L_52AD(void) {
  p27_L_536F();
  if (flag_z()) return;
  set_hl((uint16_t)(hl() + 1));
  p27_L_52B2();
  return;
}

/* flash page 27 cpu 0x52B2 (offset 0x12B2) */
void p27_L_52B2(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = (uint8_t)(a - 1);
  mem_write8(0x8019, a);
  a = mem_read8(hl());
  a = (uint8_t)(a + 1);
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  lab_p27_L_52BE: ;
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p27_L_52C9;
  a = mem_read8(0x844C);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) p27_L_5357();
  return;
  lab_p27_L_52C9: ;
  cpu_push_af();
  p27_L_534A();
  cpu_ex_de_hl();
  cpu_push_de();
  a = mem_read8(hl());
  b = a;
  a = mem_read8(0x844C);
  a = (uint8_t)(a + b);
  flag_cmp(a, 0x11);
  if (flag_c()) goto lab_p27_L_52E1;
  p27_L_5357();
  p27_L_5328();
  a = mem_read8(hl());
  a = (uint8_t)(a + 1);
  lab_p27_L_52E1: ;
  cpu_push_af();
  cpu_push_hl();
  p27_L_5338();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2E)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p27_L_52ED;
  b = a;
  lab_p27_L_52ED: ;
  set_hl(0x8019);
  a = mem_read8(hl());
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  flag_cmp(a, b);
  cpu_pop_hl();
  if (flag_nz()) goto lab_p27_L_5304;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2E)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p27_L_5300;
  cpu_pop_af();
  cpu_pop_af();
  cpu_pop_af();
  return;
  lab_p27_L_5300: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  lab_p27_L_5304: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2E)) & (1u << 0)) == 0);
  if (flag_z()) p00_L_3C8D();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  cpu_pop_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2E)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p27_L_5319;
  mem_write8(0x844C, a);
  lab_p27_L_5319: ;
  flag_cmp(a, 0x10);
  if (flag_nc()) goto lab_p27_L_5324;
  a = mem_read8(0x8019);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) p27_L_5328();
  lab_p27_L_5324: ;
  cpu_pop_hl();
  cpu_pop_af();
  goto lab_p27_L_52BE;
}

/* flash page 27 cpu 0x5328 (offset 0x1328) */
void p27_L_5328(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x2E)) & (1u << 0)) == 0);
  a = 0x20;
  if (flag_z()) p00_L_3C6F();
  cpu_push_hl();
  set_hl(0x844C);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  cpu_pop_hl();
  return;
}

/* flash page 27 cpu 0x5338 (offset 0x1338) */
void p27_L_5338(void) {
  set_hl(0x8009);
  a = mem_read8(0x8006);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  b = mem_read8(hl());
  a = mem_read8(0x8007);
  return;
}

/* flash page 27 cpu 0x5347 (offset 0x1347) */
void p27_L_5347(void) {
  set_hl((uint16_t)(hl() + 1));
  p27_L_5348();
  return;
}

/* flash page 27 cpu 0x5348 (offset 0x1348) */
void p27_L_5348(void) {
  set_hl((uint16_t)(hl() + 1));
  p27_L_5349();
  return;
}

/* flash page 27 cpu 0x5349 (offset 0x1349) */
void p27_L_5349(void) {
  set_hl((uint16_t)(hl() + 1));
  p27_L_534A();
  return;
}

/* flash page 27 cpu 0x534A (offset 0x134A) */
void p27_L_534A(void) {
  cpu_push_hl();
  p00_L_0033();
  set_de(0x8100);
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  return;
}

/* flash page 27 cpu 0x5357 (offset 0x1357) */
void p27_L_5357(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x2E)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p27_L_5365;
  a = mem_read8(0x844C);
  flag_cmp(a, 0x0F);
  if (flag_nz()) p00_L_3D1D();
  lab_p27_L_5365: ;
  cpu_push_hl();
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl((uint16_t)(hl() + 1));
  a = 0;
  flag_logic(a);
  mem_write8(hl(), a);
  cpu_pop_hl();
  return;
}

/* flash page 27 cpu 0x536F (offset 0x136F) */
void p27_L_536F(void) {
  a = mem_read8(0x8006);
  b = a;
  p27_L_5373();
  return;
}

/* flash page 27 cpu 0x5373 (offset 0x1373) */
void p27_L_5373(void) {
  set_hl(0x8100);
  lab_p27_L_5376: ;
  b = (uint8_t)(b - 1);
  a = mem_read8(hl());
  if (flag_m()) return;
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  p27_L_5380();
  goto lab_p27_L_5376;
}

/* flash page 27 cpu 0x5380 (offset 0x1380) */
void p27_L_5380(void) {
  set_hl((uint16_t)(hl() + 1));
  p27_L_5381();
  return;
}

/* flash page 27 cpu 0x5381 (offset 0x1381) */
void p27_L_5381(void) {
  a = mem_read8(hl());
  /* sla a */
  a = (uint8_t)(a + 0x02);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 27 cpu 0x5396 (offset 0x1396) */
void p27_L_5396(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x8033, a);
  p27_L_569B();
  goto lab_p27_L_539F;
  lab_p27_L_539F: ;
  mem_write8((uint16_t)(iy + 0x2D), (uint8_t)(mem_read8((uint16_t)(iy + 0x2D)) | (1u << 7)));
  a = 0;
  flag_logic(a);
  mem_write8(0x8006, a);
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p27_L_51D0();
  goto lab_p27_L_53C3;
  lab_p27_L_53C3: ;
  mem_write16(0x8036, hl());
  p27_L_554B();
  if (flag_z()) { p27_L_53B2(); return; }
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p27_L_53E2;
  cpu_push_hl();
  a = mem_read8(0x8033);
  set_hl(0x8006);
  cpu_cp_hl();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_53E2;
  if (flag_c()) goto lab_p27_L_53E2;
  cpu_pop_af();
  p27_L_53B2();
  return;
  lab_p27_L_53E2: ;
  mem_write8((uint16_t)(iy + 0x2D), (uint8_t)(mem_read8((uint16_t)(iy + 0x2D)) & ~(1u << 7)));
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p27_L_53F3(); return; }
  p27_L_5589();
  p27_L_53ED();
  return;
}

/* flash page 27 cpu 0x53B2 (offset 0x13B2) */
void p27_L_53B2(void) {
  lab_p27_L_53B2: ;
  a = mem_read8(0x844B);
  a = (uint8_t)(a + b);
  mem_write8(0x844B, a);
  p27_L_5380();
  a = mem_read8(0x8006);
  a = (uint8_t)(a + 1);
  mem_write8(0x8006, a);
  mem_write16(0x8036, hl());
  p27_L_554B();
  if (flag_z()) goto lab_p27_L_53B2;
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p27_L_53E2;
  cpu_push_hl();
  a = mem_read8(0x8033);
  set_hl(0x8006);
  cpu_cp_hl();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_53E2;
  if (flag_c()) goto lab_p27_L_53E2;
  cpu_pop_af();
  goto lab_p27_L_53B2;
  lab_p27_L_53E2: ;
  mem_write8((uint16_t)(iy + 0x2D), (uint8_t)(mem_read8((uint16_t)(iy + 0x2D)) & ~(1u << 7)));
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p27_L_53F3(); return; }
  p27_L_5589();
  p27_L_53ED();
  return;
}

/* flash page 27 cpu 0x53ED (offset 0x13ED) */
void p27_L_53ED(void) {
  p27_L_536F();
  mem_write16(0x8036, hl());
  p27_L_53F3();
  return;
}

/* flash page 27 cpu 0x53F3 (offset 0x13F3) */
void p27_L_53F3(void) {
  goto lab_p27_L_53F3;
  lab_p27_L_5149: ;
  cpu_pop_af();
  p27_L_5743();
  if (flag_z()) return;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p27_L_5180;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p27_L_5180;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p27_L_5180;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p27_L_5162;
  p00_L_375F();
  return;
  lab_p27_L_5162: ;
  set_hl(0x516E);
  p00_L_25A2();
  p27_L_51B4();
  p00_L_25C8();
  a = 0x40;
  set_hl(0x8025);
  p27_L_573A();
  lab_p27_L_5176: ;
  sp = mem_read16(0x801D);
  cpu_push_af();
  p00_L_3F09();
  cpu_pop_af();
  return;
  lab_p27_L_5180: ;
  cpu_push_af();
  set_hl(0x51AD);
  p00_L_25A2();
  p27_L_51B4();
  if (flag_z()) goto lab_p27_L_5191;
  p27_L_51D0();
  goto lab_p27_L_519E;
  lab_p27_L_5191: ;
  set_bc(mem_read16(0x844B));
  cpu_push_bc();
  p27_L_5270();
  cpu_pop_bc();
  mem_write16(0x844B, bc());
  lab_p27_L_519E: ;
  p00_L_25C8();
  p00_L_37CB();
  p27_L_51E6();
  p27_L_536F();
  cpu_pop_af();
  goto lab_p27_L_5176;
  lab_p27_L_53EA: ;
  p27_L_5589();
  p27_L_53ED();
  return;
  lab_p27_L_53F3: ;
  cpu_push_hl();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 6)));
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p27_L_5402;
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 6)));
  goto lab_p27_L_5429;
  lab_p27_L_5402: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p27_L_540C;
  cpu_pop_hl();
  p27_L_5598();
  goto lab_p27_L_544F;
  lab_p27_L_540C: ;
  cpu_push_af();
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  cpu_pop_af();
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p27_L_5425;
  cpu_pop_hl();
  cpu_push_hl();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  p27_L_525E();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  goto lab_p27_L_542C;
  lab_p27_L_5425: ;
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 6)));
  lab_p27_L_5429: ;
  p00_L_3F0F();
  lab_p27_L_542C: ;
  p00_L_3F21();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  p00_L_3EFD();
  cpu_pop_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p27_L_5444;
  set_hl(0x801F);
  cpu_push_hl();
  p00_L_2B3C();
  return;
  lab_p27_L_5444: ;
  cpu_push_af();
  set_hl(mem_read16(0x8036));
  a = mem_read8(hl());
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p27_L_5149;
  cpu_pop_af();
  lab_p27_L_544F: ;
  p27_L_5743();
  if (flag_z()) { p27_L_53ED(); return; }
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p27_L_547F;
  p27_L_55C5();
  p27_L_557A();
  lab_p27_L_545E: ;
  a = mem_read8(0x8006);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_53EA;
  a = (uint8_t)(a - 1);
  mem_write8(0x8006, a);
  p27_L_536F();
  mem_write16(0x8036, hl());
  p27_L_554B();
  cpu_push_af();
  a = mem_read8(0x844B);
  a = (uint8_t)(a - b);
  mem_write8(0x844B, a);
  cpu_pop_af();
  if (flag_z()) goto lab_p27_L_545E;
  goto lab_p27_L_53F3;
  lab_p27_L_547F: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p27_L_548F;
  lab_p27_L_5483: ;
  p27_L_55C5();
  p27_L_557A();
  p27_L_5565();
  p27_L_53B2();
  return;
  lab_p27_L_548F: ;
  flag_cmp(a, 0x40);
  if (flag_nz()) goto lab_p27_L_549B;
  set_hl(0x8025);
  p27_L_573A();
  a = (uint8_t)(a + 1);
  return;
  lab_p27_L_549B: ;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p27_L_54C4;
  a = mem_read8(hl());
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p27_L_54B8;
  p27_L_5338();
  mem_write8(hl(), a);
  p27_L_5706();
  if (flag_z()) goto lab_p27_L_54B3;
  p27_L_51D0();
  p27_L_54B0();
  return;
  lab_p27_L_54B3: ;
  p27_L_55D3();
  p27_L_54B0();
  return;
  lab_p27_L_54B8: ;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p27_L_5483;
  lab_p27_L_54BC: ;
  set_hl(0x8025);
  p27_L_573A();
  a = 0;
  flag_logic(a);
  return;
  lab_p27_L_54C4: ;
  flag_cmp(a, 0x8F);
  if (flag_c()) goto lab_p27_L_54F0;
  flag_cmp(a, 0x96);
  if (flag_nc()) goto lab_p27_L_54F0;
  a = (uint8_t)(a - 0x8E);
  b = a;
  set_hl(0x8100);
  c = 0x00;
  goto lab_p27_L_54DA;
  lab_p27_L_54D6: ;
  c = (uint8_t)(c + 1);
  p27_L_5380();
  lab_p27_L_54DA: ;
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_54F0;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p27_L_54D6;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p27_L_54D6;
  a = c;
  mem_write8(0x8006, a);
  goto lab_p27_L_54BC;
  lab_p27_L_54F0: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p27_L_551B;
  p27_L_55E3();
  if (flag_nz()) goto lab_p27_L_5509;
  set_hl(0x8009);
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_5548;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  lab_p27_L_5501: ;
  a = 0;
  flag_logic(a);
  b = a;
  p27_L_5719();
  p27_L_5396();
  return;
  lab_p27_L_5509: ;
  a = mem_read8(hl());
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p27_L_5548;
  set_hl(0x8007);
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_5548;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  lab_p27_L_5516: ;
  p27_L_55D3();
  goto lab_p27_L_5548;
  lab_p27_L_551B: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p27_L_5548;
  p27_L_55E3();
  if (flag_nz()) goto lab_p27_L_5534;
  a = mem_read8(0x8101);
  a = (uint8_t)(a - 1);
  a = (uint8_t)(a - 1);
  b = a;
  set_hl(0x8009);
  a = mem_read8(hl());
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p27_L_5548;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p27_L_5501;
  lab_p27_L_5534: ;
  a = mem_read8(hl());
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p27_L_5548;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = (uint8_t)(a - 1);
  a = (uint8_t)(a - 1);
  b = a;
  set_hl(0x8007);
  a = mem_read8(hl());
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p27_L_5548;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p27_L_5516;
  lab_p27_L_5548: ;
  p27_L_54B0();
  return;
}

/* flash page 27 cpu 0x54B0 (offset 0x14B0) */
void p27_L_54B0(void) {
  p27_L_53ED();
  return;
}

/* flash page 27 cpu 0x554B (offset 0x154B) */
void p27_L_554B(void) {
  a = mem_read8(0x8006);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p27_L_555C;
  p27_L_55E3();
  if (flag_nz()) goto lab_p27_L_555C;
  a = mem_read8(0x8102);
  b = a;
  a = 0;
  flag_logic(a);
  return;
  lab_p27_L_555C: ;
  a = mem_read8(hl());
  flag_cmp(a, 0x02);
  if (flag_nz()) { p27_L_5565(); return; }
  a = 0;
  flag_logic(a);
  mem_write8(0x8007, a);
  p27_L_5565();
  return;
}

/* flash page 27 cpu 0x5565 (offset 0x1565) */
void p27_L_5565(void) {
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  flag_cmp(a, 0x03);
  if (flag_c()) goto lab_p27_L_5571;
  b = 0x01;
  lab_p27_L_5571: ;
  flag_cmp(a, 0x01);
  if (flag_z()) return;
  flag_cmp(a, 0x06);
  if (flag_nz()) return;
  b = 0x00;
  return;
}

/* flash page 27 cpu 0x557A (offset 0x157A) */
void p27_L_557A(void) {
  set_bc(mem_read16(0x844B));
  mem_write16(0x801A, bc());
  p27_L_5582();
  return;
}

/* flash page 27 cpu 0x5582 (offset 0x1582) */
void p27_L_5582(void) {
  a = mem_read8(0x8006);
  mem_write8(0x801C, a);
  return;
}

/* flash page 27 cpu 0x5589 (offset 0x1589) */
void p27_L_5589(void) {
  set_bc(mem_read16(0x801A));
  mem_write16(0x844B, bc());
  p27_L_5591();
  return;
}

/* flash page 27 cpu 0x5591 (offset 0x1591) */
void p27_L_5591(void) {
  a = mem_read8(0x801C);
  mem_write8(0x8006, a);
  return;
}

/* flash page 27 cpu 0x5598 (offset 0x1598) */
void p27_L_5598(void) {
  p27_L_5347();
  a = mem_read8(de());
  mem_write8(0x97A7, a);
  mem_write8(0x844C, a);
  p00_L_3753();
  p27_L_56B7();
  p00_L_363F();
  p00_L_3645();
  p00_L_3DE3();
  a = 0x01;
  mem_write8(0x986F, a);
  a = 0x58;
  mem_write8(0x859A, a);
  mem_write16(0x801D, sp);
  p00_L_03CF();
  a = 0x40;
  return;
}

/* flash page 27 cpu 0x55C5 (offset 0x15C5) */
void p27_L_55C5(void) {
  a = mem_read8(hl());
  flag_cmp(a, 0x05);
  if (flag_nz()) return;
  cpu_push_hl();
  p27_L_525E();
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  cpu_pop_hl();
  return;
}

/* flash page 27 cpu 0x55D3 (offset 0x15D3) */
void p27_L_55D3(void) {
  set_bc(mem_read16(0x844B));
  cpu_push_bc();
  p27_L_52AD();
  cpu_pop_bc();
  mem_write16(0x844B, bc());
  p27_L_536F();
  return;
}

/* flash page 27 cpu 0x55E3 (offset 0x15E3) */
void p27_L_55E3(void) {
  cpu_push_de();
  cpu_push_hl();
  cpu_push_af();
  set_hl(0x8100);
  a = mem_read8(hl());
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p27_L_55F3;
  p27_L_5347();
  a = mem_read8(de());
  a = a | a;
  flag_logic(a);
  lab_p27_L_55F3: ;
  cpu_pop_hl();
  a = h;
  cpu_pop_hl();
  cpu_pop_de();
  return;
}

/* flash page 27 cpu 0x55F8 (offset 0x15F8) */
void p27_L_55F8(void) {
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  set_bc(mem_read16(0x844B));
  cpu_push_bc();
  mem_write8((uint16_t)(iy + 0x2E), (uint8_t)(mem_read8((uint16_t)(iy + 0x2E)) | (1u << 0)));
  cpu_push_af();
  p27_L_536F();
  a = mem_read8(hl());
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p27_L_5617;
  p27_L_5347();
  cpu_ex_de_hl();
  mem_write8((uint16_t)(iy + 0x2E), (uint8_t)(mem_read8((uint16_t)(iy + 0x2E)) & ~(1u << 0)));
  goto lab_p27_L_561A;
  lab_p27_L_5617: ;
  p27_L_52AD();
  lab_p27_L_561A: ;
  cpu_pop_af();
  if (flag_nc()) goto lab_p27_L_562B;
  b = mem_read8(hl());
  a = 0x20;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  lab_p27_L_5624: ;
  p00_L_3F9F();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_5624;
  goto lab_p27_L_5646;
  lab_p27_L_562B: ;
  cpu_push_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2E)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p27_L_563E;
  p27_L_5338();
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p27_L_563E;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  goto lab_p27_L_5642;
  lab_p27_L_563E: ;
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 0)));
  lab_p27_L_5642: ;
  cpu_pop_hl();
  p00_L_3C8D();
  lab_p27_L_5646: ;
  cpu_pop_bc();
  mem_write16(0x844B, bc());
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x2E), (uint8_t)(mem_read8((uint16_t)(iy + 0x2E)) & ~(1u << 0)));
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 27 cpu 0x5690 (offset 0x1690) */
void p27_L_5690(void) {
  mem_write16(0x801F, hl());
  mem_write8(0x8021, a);
  mem_write8((uint16_t)(iy + 0x2D), (uint8_t)(mem_read8((uint16_t)(iy + 0x2D)) | (1u << 5)));
  return;
}

/* flash page 27 cpu 0x569B (offset 0x169B) */
void p27_L_569B(void) {
  mem_write8((uint16_t)(iy + 0x2D), (uint8_t)(mem_read8((uint16_t)(iy + 0x2D)) & ~(1u << 5)));
  return;
}

/* flash page 27 cpu 0x56B7 (offset 0x16B7) */
void p27_L_56B7(void) {
  p27_L_56D5();
  goto lab_p27_L_56BF;
  lab_p27_L_56BF: ;
  p00_rst20();
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  return;
}

/* flash page 27 cpu 0x56BC (offset 0x16BC) */
void p27_L_56BC(void) {
  p27_L_56DF();
  p00_rst20();
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  return;
}

/* flash page 27 cpu 0x56C5 (offset 0x16C5) */
void p27_L_56C5(void) {
  p27_L_56D5();
  goto lab_p27_L_56CD;
  lab_p27_L_56CD: ;
  cpu_ex_de_hl();
  set_hl(0x8478);
  p00_L_1183();
  return;
}

/* flash page 27 cpu 0x56D5 (offset 0x16D5) */
void p27_L_56D5(void) {
  a = mem_read8(0x8006);
  b = a;
  p27_L_5373();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  p27_L_56DF();
  return;
}

/* flash page 27 cpu 0x56DF (offset 0x16DF) */
void p27_L_56DF(void) {
  h = 0x00;
  l = a;
  p00_L_1025();
  set_de(0x8038);
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 27 cpu 0x5702 (offset 0x1702) */
void p27_L_5702(void) {
  goto lab_p27_L_5702;
  lab_p27_L_56F8: ;
  p00_L_24E5();
  return;
  lab_p27_L_5702: ;
  if (flag_z()) return;
  if (flag_nc()) goto lab_p27_L_56F8;
  return;
}

/* flash page 27 cpu 0x5706 (offset 0x1706) */
void p27_L_5706(void) {
  p27_L_557A();
  a = mem_read8(0x8006);
  b = a;
  a = 0;
  flag_logic(a);
  p27_L_5719();
  p27_L_5589();
  a = mem_read8(0x8008);
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 27 cpu 0x5719 (offset 0x1719) */
void p27_L_5719(void) {
  mem_write8(0x8008, a);
  a = mem_read8(0x8005);
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  cpu_push_bc();
  set_hl(0x2B53);
  set_de(0x8000);
  set_bc(0x0003);
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_bc();
  a = mem_read8(0x8008);
  a = a | a;
  flag_logic(a);
  /* call 0x8000 - RAM/other */
  mem_write8(0x8008, a);
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 27 cpu 0x573A (offset 0x173A) */
void p27_L_573A(void) {
  set_de(0x858D);
  set_bc(0x000E);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 27 cpu 0x5743 (offset 0x1743) */
void p27_L_5743(void) {
  cpu_push_hl();
  cpu_push_bc();
  set_hl(0x5750);
  set_bc(0x0012);
  /* cpir */
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 27 cpu 0x5802 (offset 0x1802) */
void p27_L_5802(void) {
  set_hl((uint16_t)(hl() - 1));
  halt();
  if (flag_nz()) p27_L_69CE();
  /* ei */
  p00_L_03CF();
  return;
}

/* flash page 27 cpu 0x580C (offset 0x180C) */
void p27_L_580C(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x2B)) & (1u << 6)) == 0);
  if (flag_z()) return;
  p27_L_69CE();
  /* ei */
  return;
}

/* flash page 27 cpu 0x5816 (offset 0x1816) */
void p27_L_5816(void) {
  mem_write8((uint16_t)(iy + 0x2B), (uint8_t)(mem_read8((uint16_t)(iy + 0x2B)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  cpu_push_hl();
  set_hl(0x0800);
  mem_write16(0x97A5, hl());
  p00_L_3EFD();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  set_hl(0x858D);
  set_de(0x817C);
  set_bc(0x000E);
  while (bc() != 0) { cpu_ldi(); }
  a = mem_read8(0x843E);
  mem_write8(0x8197, a);
  set_hl(mem_read16(0x9870));
  mem_write16(0x8195, hl());
  cpu_pop_hl();
  p00_L_07CC();
  p27_L_588E();
  a = mem_read8(0x86D7);
  mem_write8(0x817B, a);
  cpu_push_af();
  p00_L_1120();
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 6)));
  p00_L_3759();
  mem_write16(0x9706, hl());
  p00_L_3651();
  p00_L_3645();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p27_L_5881;
  p00_L_1179();
  p00_rst10();
  if (flag_c()) goto lab_p27_L_587F;
  cpu_ex_de_hl();
  lab_p27_L_5879: ;
  p00_L_3039();
  p00_L_3645();
  lab_p27_L_587F: ;
  cpu_pop_af();
  return;
  lab_p27_L_5881: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 4)) == 0);
  a = 0x00;
  set_hl(0x8483);
  if (flag_nz()) goto lab_p27_L_5879;
  goto lab_p27_L_587F;
}

/* flash page 27 cpu 0x588E (offset 0x188E) */
void p27_L_588E(void) {
  set_hl(mem_read16(0x8177));
  mem_write16(0x86D7, hl());
  set_hl(0x81CC);
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  b = a;
  set_hl((uint16_t)(hl() + 1));
  p00_L_3D53();
  return;
}

/* flash page 27 cpu 0x58A0 (offset 0x18A0) */
void p27_L_58A0(void) {
  set_hl(0x58BE);
  p27_L_5816();
  b = a;
  a = mem_read8(0x8179);
  a = (uint8_t)(a - b);
  a = (uint8_t)(a + 1);
  mem_write8(0x8198, a);
  p27_L_5C59();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 5)));
  p27_L_5BF3();
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 1)));
  return;
}

/* flash page 27 cpu 0x5935 (offset 0x1935) */
void p27_L_5935(void) {
  p27_L_5BD7();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 2)));
  p00_L_191A();
  if (flag_z()) goto lab_p27_L_597E;
  set_hl(mem_read16(0x96F8));
  p00_L_3C0F();
  p27_L_5C3D();
  a = mem_read8(0x86D7);
  a = (uint8_t)(a - b);
  if (flag_c()) goto lab_p27_L_596C;
  set_hl(0x817B);
  cpu_cp_hl();
  if (flag_c()) goto lab_p27_L_596C;
  set_hl(0x819A);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p27_L_5963;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p27_L_596C;
  lab_p27_L_5963: ;
  mem_write8(0x86D7, a);
  p27_L_5C59();
  p27_L_5A1A();
  return;
  lab_p27_L_596C: ;
  p27_L_5B85();
  a = mem_read8(0x817B);
  a = (uint8_t)(a + 0x03);
  mem_write8(0x86D7, a);
  cpu_push_af();
  p27_L_5AE1();
  cpu_pop_af();
  goto lab_p27_L_5963;
  lab_p27_L_597E: ;
  p00_L_37E3();
  p27_L_5A1A();
  return;
}

/* flash page 27 cpu 0x5A1A (offset 0x1A1A) */
void p27_L_5A1A(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 6)));
  p27_L_5BD7();
  goto lab_p27_L_5A29;
  lab_p27_L_5A29: ;
  p27_L_580C();
  return;
}

/* flash page 27 cpu 0x5A2C (offset 0x1A2C) */
void p27_L_5A2C(void) {
  set_hl(mem_read16(0x86D7));
  mem_write16(0x819B, hl());
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x34), (uint8_t)(mem_read8((uint16_t)(iy + 0x34)) & ~(1u << 7)));
  set_hl(0x9872);
  p00_L_2D27();
  p00_L_3D71();
  return;
}

/* flash page 27 cpu 0x5A45 (offset 0x1A45) */
void p27_L_5A45(void) {
  sp = mem_read16(0x9D88);
  set_hl(mem_read16(0x818F));
  cpu_push_hl();
  set_hl(mem_read16(0x818D));
  cpu_push_hl();
  set_hl(mem_read16(0x818B));
  cpu_push_hl();
  return;
}

/* flash page 27 cpu 0x5AB4 (offset 0x1AB4) */
void p27_L_5AB4(void) {
  a = mem_read8(0x86D7);
  mem_write8(0x819D, a);
  a = 0xFF;
  mem_write8(0x819E, a);
  mem_write8(0x819F, a);
  return;
}

/* flash page 27 cpu 0x5AC3 (offset 0x1AC3) */
void p27_L_5AC3(void) {
  p00_L_191A();
  if (flag_z()) { p27_L_5AE1(); return; }
  set_hl((uint16_t)(hl() - 1));
  p00_L_191D();
  d = 0x00;
  if (flag_z()) goto lab_p27_L_5AD9;
  cpu_push_hl();
  set_hl((uint16_t)(hl() - 1));
  p00_L_172F();
  cpu_pop_hl();
  if (flag_nz()) goto lab_p27_L_5AD9;
  set_hl((uint16_t)(hl() - 1));
  lab_p27_L_5AD9: ;
  cpu_ex_de_hl();
  set_hl(mem_read16(0x86D7));
  cpu_push_hl();
  cpu_ex_de_hl();
  goto lab_p27_L_5AE8;
  lab_p27_L_5AE8: ;
  p27_L_5AB4();
  a = mem_read8(0x89FD);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  lab_p27_L_5AF3: ;
  set_de(mem_read16(0x96F4));
  p00_L_192A();
  /* ccf */
  if (flag_z()) goto lab_p27_L_5B49;
  p00_L_3C1B();
  a = a | 0x01;
  flag_logic(a);
  p27_L_5DEA();
  if (flag_c()) goto lab_p27_L_5AF3;
  set_hl(0x817B);
  a = mem_read8(0x819D);
  /* sub (hl) */
  flag_cmp(a, 0x03);
  if (flag_nc()) goto lab_p27_L_5B2A;
  a = mem_read8(0x819E);
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p27_L_5B1D;
  lab_p27_L_5B19: ;
  a = 0x03;
  goto lab_p27_L_5B2A;
  lab_p27_L_5B1D: ;
  /* sub (hl) */
  flag_cmp(a, 0x03);
  if (flag_nc()) goto lab_p27_L_5B2A;
  a = mem_read8(0x819F);
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p27_L_5B19;
  /* sub (hl) */
  lab_p27_L_5B2A: ;
  b = a;
  /* add a,(hl) */
  a = mem_read8(0x817B);
  mem_write8(0x86D7, a);
  cpu_push_af();
  lab_p27_L_5B33: ;
  p00_L_34F5();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_5B33;
  cpu_pop_af();
  mem_write8(0x86D7, a);
  a = (uint8_t)(a + 0x02);
  mem_write8(0x819A, a);
  p27_L_5BB5();
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 0)));
  a = a | a;
  flag_logic(a);
  lab_p27_L_5B49: ;
  cpu_pop_bc();
  a = b;
  mem_write8(0x89FD, a);
  cpu_pop_hl();
  mem_write16(0x86D7, hl());
  return;
}

/* flash page 27 cpu 0x5AE1 (offset 0x1AE1) */
void p27_L_5AE1(void) {
  set_hl(mem_read16(0x86D7));
  cpu_push_hl();
  set_hl(mem_read16(0x96F6));
  p27_L_5AB4();
  a = mem_read8(0x89FD);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  lab_p27_L_5AF3: ;
  set_de(mem_read16(0x96F4));
  p00_L_192A();
  /* ccf */
  if (flag_z()) goto lab_p27_L_5B49;
  p00_L_3C1B();
  a = a | 0x01;
  flag_logic(a);
  p27_L_5DEA();
  if (flag_c()) goto lab_p27_L_5AF3;
  set_hl(0x817B);
  a = mem_read8(0x819D);
  /* sub (hl) */
  flag_cmp(a, 0x03);
  if (flag_nc()) goto lab_p27_L_5B2A;
  a = mem_read8(0x819E);
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p27_L_5B1D;
  lab_p27_L_5B19: ;
  a = 0x03;
  goto lab_p27_L_5B2A;
  lab_p27_L_5B1D: ;
  /* sub (hl) */
  flag_cmp(a, 0x03);
  if (flag_nc()) goto lab_p27_L_5B2A;
  a = mem_read8(0x819F);
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p27_L_5B19;
  /* sub (hl) */
  lab_p27_L_5B2A: ;
  b = a;
  /* add a,(hl) */
  a = mem_read8(0x817B);
  mem_write8(0x86D7, a);
  cpu_push_af();
  lab_p27_L_5B33: ;
  p00_L_34F5();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_5B33;
  cpu_pop_af();
  mem_write8(0x86D7, a);
  a = (uint8_t)(a + 0x02);
  mem_write8(0x819A, a);
  p27_L_5BB5();
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 0)));
  a = a | a;
  flag_logic(a);
  lab_p27_L_5B49: ;
  cpu_pop_bc();
  a = b;
  mem_write8(0x89FD, a);
  cpu_pop_hl();
  mem_write16(0x86D7, hl());
  return;
}

/* flash page 27 cpu 0x5B53 (offset 0x1B53) */
void p27_L_5B53(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  a = mem_read8(0x8179);
  a = (uint8_t)(a + 1);
  b = a;
  a = mem_read8(0x86D7);
  cpu_push_af();
  a = (uint8_t)(a - b);
  if (flag_nc()) goto lab_p27_L_5B7C;
  /* neg */
  lab_p27_L_5B65: ;
  b = a;
  flag_cmp(a, 0x04);
  if (flag_c()) goto lab_p27_L_5B77;
  a = (uint8_t)(a - 0x04);
  cpu_push_af();
  a = 0x06;
  p00_L_3D47();
  cpu_pop_af();
  if (flag_nz()) goto lab_p27_L_5B65;
  if (flag_z()) goto lab_p27_L_5B7C;
  lab_p27_L_5B77: ;
  p00_L_34F5();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_5B77;
  lab_p27_L_5B7C: ;
  cpu_pop_af();
  mem_write8(0x86D7, a);
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 27 cpu 0x5B85 (offset 0x1B85) */
void p27_L_5B85(void) {
  cpu_push_hl();
  cpu_push_de();
  a = mem_read8(0x86D7);
  cpu_push_af();
  a = mem_read8(0x817B);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 0)) == 0);
  if (flag_nz()) p27_L_5BA8();
  a = mem_read8(0x8179);
  a = (uint8_t)(a - 0x02);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 1)) == 0);
  if (flag_nz()) p27_L_5BA8();
  cpu_pop_af();
  mem_write8(0x86D7, a);
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 27 cpu 0x5BA8 (offset 0x1BA8) */
void p27_L_5BA8(void) {
  mem_write8(0x86D7, a);
  p00_L_34F5();
  p00_L_34F5();
  p00_L_34F5();
  return;
}

/* flash page 27 cpu 0x5BB5 (offset 0x1BB5) */
void p27_L_5BB5(void) {
  set_hl(0x5BC7);
  p27_L_5BB8();
  return;
}

/* flash page 27 cpu 0x5BB8 (offset 0x1BB8) */
void p27_L_5BB8(void) {
  set_de(0x865F);
  p00_L_1181();
  a = 0x06;
  set_hl(0x865F);
  p00_L_3D3B();
  return;
}

/* flash page 27 cpu 0x5BD7 (offset 0x1BD7) */
void p27_L_5BD7(void) {
  p00_L_3693();
  b = 0x20;
  a = 0x01;
  if (flag_z()) goto lab_p27_L_5BE3;
  p27_L_5C44();
  lab_p27_L_5BE3: ;
  mem_write8(0x81A0, a);
  mem_write8(0x81A8, a);
  set_hl(0x844E);
  mem_write8(hl(), b);
  cpu_push_af();
  p27_L_5C0D();
  cpu_pop_af();
  return;
}

/* flash page 27 cpu 0x5BF3 (offset 0x1BF3) */
void p27_L_5BF3(void) {
  a = 0x01;
  mem_write8(0x81A0, a);
  mem_write8(0x81A8, a);
  p00_L_1916();
  a = 0x20;
  if (flag_z()) goto lab_p27_L_5C0A;
  p00_L_3693();
  p00_L_3DBF();
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  lab_p27_L_5C0A: ;
  mem_write8(0x844E, a);
  p27_L_5C0D();
  return;
}

/* flash page 27 cpu 0x5C0D (offset 0x1C0D) */
void p27_L_5C0D(void) {
  a = mem_read8(0x81A0);
  e = a;
  d = 0x00;
  set_hl(0x5C35);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  set_hl(0x81A1);
  mem_write8(hl(), 0x00);
  b = 0x06;
  lab_p27_L_5C1F: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_5C1F;
  set_hl((uint16_t)(hl() + 1));
  b = 0x05;
  lab_p27_L_5C26: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x00);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_5C26;
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p27_L_5C31;
  a = (uint8_t)(a & ~(1u << 0));
  lab_p27_L_5C31: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  return;
}

/* flash page 27 cpu 0x5C3D (offset 0x1C3D) */
void p27_L_5C3D(void) {
  p00_L_3DBF();
  p27_L_5DCC();
  return;
}

/* flash page 27 cpu 0x5C44 (offset 0x1C44) */
void p27_L_5C44(void) {
  p00_L_3DBF();
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  cpu_push_af();
  p00_L_3D41();
  a = mem_read8(hl());
  cpu_pop_bc();
  return;
}

/* flash page 27 cpu 0x5C50 (offset 0x1C50) */
void p27_L_5C50(void) {
  cpu_push_af();
  a = mem_read8(0x817B);
  mem_write8(0x86D7, a);
  cpu_pop_af();
  return;
}

/* flash page 27 cpu 0x5C59 (offset 0x1C59) */
void p27_L_5C59(void) {
  p27_L_5AB4();
  p27_L_5C5C();
  return;
}

/* flash page 27 cpu 0x5C5C (offset 0x1C5C) */
void p27_L_5C5C(void) {
  p00_L_3C3F();
  a = mem_read8(0x86D7);
  cpu_push_af();
  set_hl(mem_read16(0x96F8));
  lab_p27_L_5C66: ;
  p00_L_3C33();
  if (flag_z()) goto lab_p27_L_5CE9;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p00_L_3DBF();
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(0x8179);
  a = (uint8_t)(a + 1);
  c = a;
  lab_p27_L_5C77: ;
  cpu_push_bc();
  cpu_push_hl();
  a = mem_read8(hl());
  p00_L_3D41();
  a = mem_read8(0x86D7);
  /* add a,(hl) */
  d = mem_read8(hl());
  flag_cmp(a, c);
  cpu_pop_hl();
  cpu_pop_bc();
  if (flag_nc()) goto lab_p27_L_5C9F;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p00_L_3D47();
  a = mem_read8(0x86D7);
  set_de(mem_read16(0x819D));
  mem_write16(0x819E, de());
  mem_write8(0x819D, a);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_5C77;
  cpu_pop_hl();
  goto lab_p27_L_5C66;
  lab_p27_L_5C9F: ;
  a = d;
  mem_write8(0x81B0, a);
  cpu_pop_hl();
  a = mem_read8(0x8179);
  set_hl(0x819D);
  /* sub (hl) */
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p27_L_5CC1;
  /* add a,(hl) */
  set_hl((uint16_t)(hl() + 1));
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p27_L_5CCC;
  /* sub (hl) */
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p27_L_5CC1;
  /* add a,(hl) */
  set_hl((uint16_t)(hl() + 1));
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p27_L_5CCC;
  /* sub (hl) */
  lab_p27_L_5CC1: ;
  a = (uint8_t)(a + 1);
  b = a;
  a = mem_read8(hl());
  mem_write8(0x86D7, a);
  lab_p27_L_5CC7: ;
  p00_L_34F5();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_5CC7;
  lab_p27_L_5CCC: ;
  a = mem_read8(0x8179);
  a = (uint8_t)(a - 0x02);
  mem_write8(0x86D7, a);
  mem_write8(0x8199, a);
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 1)));
  mem_write8(0x86D7, a);
  set_hl(0x5BCF);
  p27_L_5BB8();
  cpu_pop_af();
  mem_write8(0x86D7, a);
  return;
  lab_p27_L_5CE9: ;
  p27_L_5B53();
  p00_L_3C3F();
  cpu_pop_af();
  mem_write8(0x86D7, a);
  return;
}

/* flash page 27 cpu 0x5CF4 (offset 0x1CF4) */
void p27_L_5CF4(void) {
  a = 0;
  flag_logic(a);
  p27_L_5CF5();
  return;
}

/* flash page 27 cpu 0x5CF5 (offset 0x1CF5) */
void p27_L_5CF5(void) {
  mem_write16(0x81B1, de());
  cpu_push_af();
  p27_L_5B85();
  p27_L_5C3D();
  cpu_push_hl();
  b = (uint8_t)(b + 1);
  set_hl(0x86D7);
  a = mem_read8(0x8179);
  cpu_push_af();
  /* sub (hl) */
  flag_cmp(a, b);
  if (flag_c()) goto lab_p27_L_5D14;
  cpu_pop_af();
  cpu_pop_hl();
  a = mem_read8(0x86D7);
  goto lab_p27_L_5D5A;
  lab_p27_L_5D14: ;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p27_L_5D25;
  a = mem_read8(0x81A0);
  flag_cmp(a, 0x03);
  if (flag_c()) goto lab_p27_L_5D25;
  a = (uint8_t)(a + b);
  b = a;
  lab_p27_L_5D25: ;
  cpu_pop_af();
  a = (uint8_t)(a - b);
  mem_write8(hl(), a);
  cpu_pop_hl();
  if (flag_c()) goto lab_p27_L_5D35;
  cpu_push_af();
  c = a;
  a = mem_read8(0x817B);
  c = (uint8_t)(c + 1);
  flag_cmp(a, c);
  if (flag_c()) goto lab_p27_L_5D5B;
  cpu_pop_hl();
  lab_p27_L_5D35: ;
  cpu_pop_de();
  p00_L_3693();
  a = 0x00;
  if (flag_z()) goto lab_p27_L_5D42;
  p27_L_5C44();
  a = (uint8_t)(a + 0x02);
  lab_p27_L_5D42: ;
  b = a;
  set_hl(0x8179);
  a = mem_read8(hl());
  a = (uint8_t)(a - b);
  cpu_push_af();
  mem_write8(0x86D7, a);
  p27_L_5C59();
  cpu_pop_af();
  cpu_push_af();
  mem_write8(0x86D7, a);
  p27_L_5AE1();
  cpu_pop_af();
  goto lab_p27_L_5DC5;
  lab_p27_L_5D5A: ;
  cpu_push_af();
  lab_p27_L_5D5B: ;
  cpu_push_hl();
  b = mem_read8(hl());
  p27_L_5AB4();
  lab_p27_L_5D60: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  p00_L_3D47();
  a = mem_read8(0x86D7);
  set_de(mem_read16(0x819D));
  mem_write16(0x819E, de());
  mem_write8(0x819D, a);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_5D60;
  p27_L_5C5C();
  cpu_pop_hl();
  cpu_pop_bc();
  a = mem_read8(0x86D7);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p27_L_5DBB;
  d = a;
  set_hl(0x81B0);
  /* add a,(hl) */
  a = (uint8_t)(a - 1);
  c = a;
  a = mem_read8(0x8199);
  a = (uint8_t)(a - 1);
  flag_cmp(a, c);
  a = d;
  if (flag_nc()) goto lab_p27_L_5DBB;
  cpu_pop_af();
  a = d;
  if (flag_c()) goto lab_p27_L_5DBC;
  cpu_push_af();
  a = mem_read8(0x817B);
  flag_cmp(a, b);
  if (flag_z()) goto lab_p27_L_5D35;
  cpu_push_bc();
  set_de(mem_read16(0x81B1));
  p00_L_3DBF();
  a = mem_read8(0x81B0);
  b = a;
  cpu_pop_af();
  a = (uint8_t)(a - b);
  cpu_push_hl();
  set_hl(0x817B);
  cpu_cp_hl();
  cpu_pop_hl();
  if (flag_c()) goto lab_p27_L_5D35;
  mem_write8(0x86D7, a);
  p27_L_5B85();
  goto lab_p27_L_5D5A;
  lab_p27_L_5DBB: ;
  cpu_pop_de();
  lab_p27_L_5DBC: ;
  cpu_push_af();
  a = b;
  mem_write8(0x86D7, a);
  p27_L_5AC3();
  cpu_pop_af();
  lab_p27_L_5DC5: ;
  mem_write8(0x86D7, a);
  p27_L_5BD7();
  return;
}

/* flash page 27 cpu 0x5DCC (offset 0x1DCC) */
void p27_L_5DCC(void) {
  cpu_push_hl();
  b = mem_read8(hl());
  a = 0;
  flag_logic(a);
  lab_p27_L_5DCF: ;
  cpu_push_bc();
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  a = mem_read8(hl());
  p00_L_3D41();
  d = mem_read8(hl());
  cpu_pop_hl();
  cpu_pop_af();
  a = (uint8_t)(a + d);
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_5DCF;
  b = a;
  cpu_pop_hl();
  return;
}

/* flash page 27 cpu 0x5DE1 (offset 0x1DE1) */
void p27_L_5DE1(void) {
  p00_L_3C1B();
  p27_L_5DE4();
  return;
}

/* flash page 27 cpu 0x5DE4 (offset 0x1DE4) */
void p27_L_5DE4(void) {
  cpu_push_bc();
  a = 0;
  flag_logic(a);
  b = 0x00;
  goto lab_p27_L_5DED;
  lab_p27_L_5DED: ;
  cpu_push_de();
  cpu_push_hl();
  cpu_push_af();
  cpu_push_bc();
  p00_L_3DBF();
  b = mem_read8(hl());
  e = b;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  lab_p27_L_5DF9: ;
  a = mem_read8(0x817B);
  cpu_pop_de();
  cpu_push_de();
  flag_set_z((d & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p27_L_5E3B;
  a = mem_read8(hl());
  flag_cmp(a, 0xD6);
  if (flag_nz()) goto lab_p27_L_5E38;
  p27_L_610D();
  a = mem_read8(0x86D8);
  set_hl(0x8178);
  cpu_cp_hl();
  if (flag_m()) goto lab_p27_L_5E9D;
  set_hl(mem_read16(0x96F6));
  lab_p27_L_5E17: ;
  set_de(mem_read16(0x96F4));
  set_hl((uint16_t)(hl() - 1));
  p00_L_192A();
  if (flag_c()) goto lab_p27_L_5E2A;
  set_hl((uint16_t)(hl() + 1));
  p00_L_3C1B();
  p00_L_17C7();
  if (flag_nz()) goto lab_p27_L_5E17;
  lab_p27_L_5E2A: ;
  set_hl((uint16_t)(hl() + 1));
  set_de(mem_read16(0x96F6));
  p00_L_3C21();
  a = e;
  mem_write8(0x86D7, a);
  goto lab_p27_L_5E74;
  lab_p27_L_5E38: ;
  a = mem_read8(0x8177);
  lab_p27_L_5E3B: ;
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_af();
  a = mem_read8(hl());
  p00_L_3D41();
  cpu_pop_af();
  c = a;
  a = mem_read8(0x86D7);
  /* sub (hl) */
  if (flag_m()) goto lab_p27_L_5E7B;
  flag_cmp(a, c);
  if (flag_c()) goto lab_p27_L_5E7B;
  mem_write8(0x86D7, a);
  lab_p27_L_5E51: ;
  set_hl(mem_read16(0x819D));
  mem_write16(0x819E, hl());
  mem_write8(0x819D, a);
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_af();
  a = mem_read8(hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 7)) == 0);
  if (flag_z()) p00_L_3D47();
  a = mem_read8(0x86D7);
  mem_write8(0x819E, a);
  cpu_pop_af();
  mem_write8(0x86D7, a);
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_5DF9;
  lab_p27_L_5E74: ;
  cpu_pop_de();
  cpu_pop_af();
  /* scf */
  lab_p27_L_5E77: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  return;
  lab_p27_L_5E7B: ;
  a = mem_read8(hl());
  mem_write8(0x81B0, a);
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_af();
  if (flag_nz()) goto lab_p27_L_5E9F;
  cpu_push_af();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_hl();
  p27_L_610D();
  a = mem_read8(0x86D8);
  cpu_push_hl();
  set_hl(0x8178);
  cpu_cp_hl();
  cpu_pop_hl();
  a = mem_read8(0x86D7);
  if (flag_p()) goto lab_p27_L_5E51;
  cpu_pop_hl();
  cpu_pop_bc();
  lab_p27_L_5E9D: ;
  cpu_pop_de();
  cpu_pop_af();
  lab_p27_L_5E9F: ;
  a = a | a;
  flag_logic(a);
  goto lab_p27_L_5E77;
}

/* flash page 27 cpu 0x5DEA (offset 0x1DEA) */
void p27_L_5DEA(void) {
  cpu_push_bc();
  b = 0x01;
  cpu_push_de();
  cpu_push_hl();
  cpu_push_af();
  cpu_push_bc();
  p00_L_3DBF();
  b = mem_read8(hl());
  e = b;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  lab_p27_L_5DF9: ;
  a = mem_read8(0x817B);
  cpu_pop_de();
  cpu_push_de();
  flag_set_z((d & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p27_L_5E3B;
  a = mem_read8(hl());
  flag_cmp(a, 0xD6);
  if (flag_nz()) goto lab_p27_L_5E38;
  p27_L_610D();
  a = mem_read8(0x86D8);
  set_hl(0x8178);
  cpu_cp_hl();
  if (flag_m()) goto lab_p27_L_5E9D;
  set_hl(mem_read16(0x96F6));
  lab_p27_L_5E17: ;
  set_de(mem_read16(0x96F4));
  set_hl((uint16_t)(hl() - 1));
  p00_L_192A();
  if (flag_c()) goto lab_p27_L_5E2A;
  set_hl((uint16_t)(hl() + 1));
  p00_L_3C1B();
  p00_L_17C7();
  if (flag_nz()) goto lab_p27_L_5E17;
  lab_p27_L_5E2A: ;
  set_hl((uint16_t)(hl() + 1));
  set_de(mem_read16(0x96F6));
  p00_L_3C21();
  a = e;
  mem_write8(0x86D7, a);
  goto lab_p27_L_5E74;
  lab_p27_L_5E38: ;
  a = mem_read8(0x8177);
  lab_p27_L_5E3B: ;
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_af();
  a = mem_read8(hl());
  p00_L_3D41();
  cpu_pop_af();
  c = a;
  a = mem_read8(0x86D7);
  /* sub (hl) */
  if (flag_m()) goto lab_p27_L_5E7B;
  flag_cmp(a, c);
  if (flag_c()) goto lab_p27_L_5E7B;
  mem_write8(0x86D7, a);
  lab_p27_L_5E51: ;
  set_hl(mem_read16(0x819D));
  mem_write16(0x819E, hl());
  mem_write8(0x819D, a);
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_af();
  a = mem_read8(hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 7)) == 0);
  if (flag_z()) p00_L_3D47();
  a = mem_read8(0x86D7);
  mem_write8(0x819E, a);
  cpu_pop_af();
  mem_write8(0x86D7, a);
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_5DF9;
  lab_p27_L_5E74: ;
  cpu_pop_de();
  cpu_pop_af();
  /* scf */
  lab_p27_L_5E77: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  return;
  lab_p27_L_5E7B: ;
  a = mem_read8(hl());
  mem_write8(0x81B0, a);
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_af();
  if (flag_nz()) goto lab_p27_L_5E9F;
  cpu_push_af();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_hl();
  p27_L_610D();
  a = mem_read8(0x86D8);
  cpu_push_hl();
  set_hl(0x8178);
  cpu_cp_hl();
  cpu_pop_hl();
  a = mem_read8(0x86D7);
  if (flag_p()) goto lab_p27_L_5E51;
  cpu_pop_hl();
  cpu_pop_bc();
  lab_p27_L_5E9D: ;
  cpu_pop_de();
  cpu_pop_af();
  lab_p27_L_5E9F: ;
  a = a | a;
  flag_logic(a);
  goto lab_p27_L_5E77;
}

/* flash page 27 cpu 0x5EA2 (offset 0x1EA2) */
void p27_L_5EA2(void) {
  cpu_push_af();
  /* srl a */
  /* srl a */
  /* srl a */
  a = a | 0x20;
  flag_logic(a);
  b = a;
  cpu_pop_af();
  lab_p27_L_5EAD: ;
  a = (uint8_t)(a - 0x08);
  if (flag_nc()) goto lab_p27_L_5EAD;
  a = (uint8_t)(a + 0x08);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  return;
}

/* flash page 27 cpu 0x5EC9 (offset 0x1EC9) */
void p27_L_5EC9(void) {
  a = 0;
  flag_logic(a);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 2)));
  set_de(mem_read16(0x96F4));
  set_bc(mem_read16(0x86D7));
  c = (uint8_t)(c + 1);
  lab_p27_L_5ED8: ;
  p00_L_325B();
  set_hl(mem_read16(0x96F6));
  a = mem_read8(0x86D8);
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p27_L_5EF1;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p27_L_5EF1;
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p27_L_5EF8;
  goto lab_p27_L_5F0D;
  lab_p27_L_5EF1: ;
  b = a;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  a = a | 0x01;
  flag_logic(a);
  cpu_push_af();
  lab_p27_L_5EF8: ;
  a = mem_read8(0x86D7);
  flag_cmp(a, c);
  if (flag_c()) goto lab_p27_L_5F12;
  cpu_push_de();
  cpu_push_hl();
  p00_L_3C1B();
  cpu_pop_hl();
  mem_write16(0x96F6, hl());
  p00_L_17C7();
  cpu_pop_de();
  if (flag_z()) goto lab_p27_L_5F12;
  lab_p27_L_5F0D: ;
  p00_L_192A();
  if (flag_nz()) goto lab_p27_L_5ED8;
  lab_p27_L_5F12: ;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 27 cpu 0x5F15 (offset 0x1F15) */
void p27_L_5F15(void) {
  a = 0;
  flag_logic(a);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 2)));
  set_de(mem_read16(0x96FA));
  set_bc(mem_read16(0x86D7));
  lab_p27_L_5F23: ;
  p00_L_30ED();
  set_hl(mem_read16(0x96F8));
  a = mem_read8(0x86D8);
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p27_L_5F3C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p27_L_5F3C;
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p27_L_5F43;
  goto lab_p27_L_5F4E;
  lab_p27_L_5F3C: ;
  b = a;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  a = a | 0x01;
  flag_logic(a);
  cpu_push_af();
  lab_p27_L_5F43: ;
  a = mem_read8(0x86D7);
  flag_cmp(a, c);
  if (flag_nc()) goto lab_p27_L_5F53;
  a = mem_read8(hl());
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p27_L_5F53;
  lab_p27_L_5F4E: ;
  p00_L_192A();
  if (flag_nz()) goto lab_p27_L_5F23;
  lab_p27_L_5F53: ;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 27 cpu 0x5F56 (offset 0x1F56) */
void p27_L_5F56(void) {
  set_hl(mem_read16(0x86D7));
  cpu_push_hl();
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 7)));
  p27_L_5F8D();
  a = mem_read8(0x8177);
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 7)) == 0);
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 7)));
  if (flag_nz()) goto lab_p27_L_5F71;
  a = mem_read8(0x817B);
  lab_p27_L_5F71: ;
  set_hl(0x86D7);
  /* sub (hl) */
  cpu_pop_hl();
  if (flag_z()) { p27_L_5F81(); return; }
  a = (uint8_t)(a + l);
  l = a;
  p27_L_5F81();
  p27_L_5FC6();
  return;
}

/* flash page 27 cpu 0x5F81 (offset 0x1F81) */
void p27_L_5F81(void) {
  cpu_push_hl();
  mem_write16(0x86D7, hl());
  p27_L_5F8D();
  cpu_pop_hl();
  mem_write16(0x86D7, hl());
  return;
}

/* flash page 27 cpu 0x5F8D (offset 0x1F8D) */
void p27_L_5F8D(void) {
  a = mem_read8(0x8198);
  cpu_push_af();
  set_hl(mem_read16(0x96F6));
  set_de(mem_read16(0x96F4));
  a = mem_read8(0x89FD);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  lab_p27_L_5FA0: ;
  p00_L_192A();
  if (flag_nz()) goto lab_p27_L_5FB6;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p27_L_5FB1;
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 7)));
  goto lab_p27_L_5FBD;
  lab_p27_L_5FB1: ;
  p27_L_588E();
  goto lab_p27_L_5FBD;
  lab_p27_L_5FB6: ;
  cpu_push_de();
  p27_L_5DE1();
  cpu_pop_de();
  if (flag_c()) goto lab_p27_L_5FA0;
  lab_p27_L_5FBD: ;
  cpu_pop_af();
  mem_write8(0x89FD, a);
  cpu_pop_af();
  mem_write8(0x8198, a);
  return;
}

/* flash page 27 cpu 0x5FC6 (offset 0x1FC6) */
void p27_L_5FC6(void) {
  a = mem_read8(0x8198);
  cpu_push_af();
  set_hl(mem_read16(0x86D7));
  cpu_push_hl();
  set_hl(mem_read16(0x96F8));
  a = mem_read8(0x89FD);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  lab_p27_L_5FD9: ;
  p00_L_3C33();
  if (flag_z()) goto lab_p27_L_5FF3;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 6)));
  p27_L_6005();
  a = mem_read8(0x8198);
  set_hl(0x81B7);
  cpu_cp_hl();
  cpu_pop_hl();
  if (flag_c()) goto lab_p27_L_5FD9;
  goto lab_p27_L_5FF7;
  lab_p27_L_5FF3: ;
  p27_L_6247();
  /* scf */
  lab_p27_L_5FF7: ;
  cpu_pop_de();
  mem_write8((uint16_t)(iy + 0x0D), d);
  p27_L_5FFB();
  return;
}

/* flash page 27 cpu 0x5FFB (offset 0x1FFB) */
void p27_L_5FFB(void) {
  cpu_pop_hl();
  mem_write16(0x86D7, hl());
  cpu_pop_hl();
  a = h;
  mem_write8(0x8198, a);
  return;
}

/* flash page 27 cpu 0x6005 (offset 0x2005) */
void p27_L_6005(void) {
  p00_L_3DBF();
  p27_L_6048();
  return;
}

/* flash page 27 cpu 0x600C (offset 0x200C) */
void p27_L_600C(void) {
  cpu_push_af();
  cpu_push_de();
  set_hl(mem_read16(0x96F6));
  p00_L_3C1B();
  p00_L_3C1B();
  p00_L_3DBF();
  b = mem_read8(hl());
  e = b;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  p00_L_3D41();
  a = mem_read8(0x86D7);
  cpu_push_af();
  /* sub (hl) */
  p27_L_61EB();
  cpu_pop_af();
  mem_write8(0x86D7, a);
  cpu_pop_de();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 2)));
  p00_L_3DBF();
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 6)));
  p27_L_6048();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 2)) == 0);
  if (flag_z()) return;
  p27_L_5FC6();
  return;
}

/* flash page 27 cpu 0x6048 (offset 0x2048) */
void p27_L_6048(void) {
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  lab_p27_L_604D: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p27_L_6067();
  a = mem_read8(0x8198);
  c = a;
  a = mem_read8(0x81B7);
  flag_cmp(a, c);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p27_L_6064;
  set_hl((uint16_t)(hl() - 1));
  goto lab_p27_L_604D;
  lab_p27_L_6064: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_604D;
  return;
}

/* flash page 27 cpu 0x6067 (offset 0x2067) */
void p27_L_6067(void) {
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 5)));
  cpu_push_af();
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  flag_cmp(a, 0xD6);
  if (flag_nz()) goto lab_p27_L_6078;
  p27_L_60A1();
  goto lab_p27_L_609C;
  lab_p27_L_6078: ;
  cpu_push_af();
  p00_L_3D41();
  a = mem_read8(hl());
  p27_L_6424();
  cpu_pop_hl();
  a = h;
  if (flag_c()) goto lab_p27_L_608D;
  p27_L_60A1();
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 5)));
  goto lab_p27_L_609C;
  lab_p27_L_608D: ;
  cpu_push_af();
  p27_L_61EE();
  cpu_pop_af();
  p00_L_3D47();
  a = 0;
  flag_logic(a);
  p27_L_6424();
  if (flag_nc()) p27_L_60A1();
  lab_p27_L_609C: ;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 27 cpu 0x60A1 (offset 0x20A1) */
void p27_L_60A1(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  cpu_push16(ix);
  p27_L_5B53();
  a = mem_read8(0x8177);
  mem_write8(0x86D7, a);
  a = mem_read8(0x8198);
  a = (uint8_t)(a + 1);
  set_hl(0x81B7);
  cpu_cp_hl();
  if (flag_c()) goto lab_p27_L_60D6;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p27_L_60D6;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 2)));
  p27_L_60E9();
  a = e;
  p27_L_6199();
  set_hl(0x81B9);
  set_de(0x81B8);
  p00_L_1183();
  p27_L_60E2();
  return;
  lab_p27_L_60D6: ;
  set_hl(0x8198);
  mem_write8(hl(), a);
  a = mem_read8(0x86D8);
  a = (uint8_t)(a + 0x06);
  mem_write8(0x86D8, a);
  p27_L_60E2();
  return;
}

/* flash page 27 cpu 0x60E2 (offset 0x20E2) */
void p27_L_60E2(void) {
  ix = cpu_pop16();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 27 cpu 0x60E9 (offset 0x20E9) */
void p27_L_60E9(void) {
  set_hl(mem_read16(0x81B5));
  mem_write16(0x8478, hl());
  set_hl(mem_read16(0x81B3));
  mem_write16(0x847A, hl());
  c = 0x06;
  a = mem_read8(0x81B7);
  a = (uint8_t)(a - 1);
  b = a;
  h = 0x06;
  a = mem_read8(0x8178);
  if (flag_nz()) goto lab_p27_L_6107;
  a = (uint8_t)(a + 0x80);
  e = a;
  return;
  lab_p27_L_6107: ;
  a = (uint8_t)(a + 0x80);
  p00_L_2FA3();
  return;
}

/* flash page 27 cpu 0x6100 (offset 0x2100) */
void p27_L_6100(void) {
  a = (uint8_t)(a + c);
  if (flag_nz()) goto lab_p27_L_6107;
  a = (uint8_t)(a + 0x80);
  e = a;
  return;
  lab_p27_L_6107: ;
  a = (uint8_t)(a + 0x80);
  p00_L_2FA3();
  return;
}

/* flash page 27 cpu 0x610D (offset 0x210D) */
void p27_L_610D(void) {
  cpu_push_af();
  cpu_push_de();
  cpu_push_hl();
  set_de(0x8198);
  a = mem_read8(de());
  a = (uint8_t)(a - 0x01);
  if (flag_nc()) goto lab_p27_L_612E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p27_L_6137;
  p27_L_6144();
  a = mem_read8(0x8179);
  set_hl(0x81B0);
  /* sub (hl) */
  a = (uint8_t)(a + 1);
  p27_L_61EB();
  goto lab_p27_L_6140;
  lab_p27_L_612E: ;
  mem_write8(de(), a);
  p27_L_6205();
  mem_write8(0x86D7, a);
  goto lab_p27_L_6138;
  lab_p27_L_6137: ;
  mem_write8(de(), a);
  lab_p27_L_6138: ;
  a = mem_read8(0x86D8);
  a = (uint8_t)(a - 0x06);
  mem_write8(0x86D8, a);
  lab_p27_L_6140: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_af();
  return;
}

/* flash page 27 cpu 0x6144 (offset 0x2144) */
void p27_L_6144(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  cpu_push16(ix);
  p00_L_3F09();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 2)));
  a = mem_read8(0x81B7);
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p27_L_615C;
  p27_L_618B();
  goto lab_p27_L_6181;
  lab_p27_L_615C: ;
  b = a;
  c = 0xFA;
  set_hl(mem_read16(0x81B5));
  mem_write16(0x8478, hl());
  set_hl(mem_read16(0x81B3));
  mem_write16(0x847A, hl());
  h = 0x06;
  p27_L_618B();
  p00_L_2FA3();
  a = e;
  cpu_push_af();
  set_hl(0x81C1);
  set_de(0x81C2);
  set_bc(0x0009);
  /* lddr */
  cpu_pop_af();
  lab_p27_L_6181: ;
  p27_L_6199();
  /* ei */
  p00_L_3F2D();
  p27_L_60E2();
  return;
}

/* flash page 27 cpu 0x618B (offset 0x218B) */
void p27_L_618B(void) {
  cpu_push_bc();
  a = (uint8_t)(a + a);
  b = a;
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + b);
  a = (uint8_t)(a + 0x80);
  c = a;
  a = mem_read8(0x8178);
  a = (uint8_t)(a + c);
  cpu_pop_bc();
  return;
}

/* flash page 27 cpu 0x6199 (offset 0x2199) */
void p27_L_6199(void) {
  /* di */
  d = a;
  a = mem_read8(0x81B5);
  e = a;
  a = mem_read8(0x81B3);
  lab_p27_L_61A2: ;
  c = a;
  p00_lcd_cmd_07();
  p00_lcd_busy_wait();
  a = e;
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p00_lcd_busy_wait();
  a = d;
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p00_lcd_cmd_05();
  b = 0x06;
  lab_p27_L_61B7: ;
  p00_lcd_cmd_07();
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  a = a | c;
  flag_logic(a);
  a = a ^ c;
  flag_logic(a);
  cpu_push_af();
  p00_lcd_cmd_05();
  a = e;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  cpu_pop_af();
  p00_lcd_busy_wait();
  lcd_write_data(); /* ti_lcd_op_write(a) */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_61B7;
  a = e;
  set_hl(0x81B6);
  cpu_cp_hl();
  if (flag_z()) return;
  a = (uint8_t)(a + 1);
  e = a;
  cpu_cp_hl();
  a = 0xFF;
  if (flag_nz()) goto lab_p27_L_61A2;
  a = mem_read8(0x81B4);
  goto lab_p27_L_61A2;
}

/* flash page 27 cpu 0x61EB (offset 0x21EB) */
void p27_L_61EB(void) {
  mem_write8(0x86D7, a);
  p27_L_61EE();
  return;
}

/* flash page 27 cpu 0x61EE (offset 0x21EE) */
void p27_L_61EE(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 6)) == 0);
  if (flag_nz()) return;
  set_hl(0x81B8);
  a = mem_read8(0x8198);
  flag_cmp(a, 0x0A);
  if (flag_nc()) return;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(0x86D7);
  mem_write8(hl(), a);
  return;
}

/* flash page 27 cpu 0x6205 (offset 0x2205) */
void p27_L_6205(void) {
  set_hl(0x81B8);
  a = mem_read8(0x8198);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  return;
}

/* flash page 27 cpu 0x6211 (offset 0x2211) */
void p27_L_6211(void) {
  set_hl(mem_read16(0x96FA));
  set_de(mem_read16(0x96F8));
  a = mem_read8((uint16_t)(iy + 0x0D));
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  cpu_ex_de_hl();
  lab_p27_L_6221: ;
  cpu_push_de();
  p00_L_315F();
  if (flag_z()) goto lab_p27_L_623D;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 6)));
  p27_L_6005();
  a = mem_read8(0x8198);
  set_hl(0x81B7);
  cpu_cp_hl();
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_nc()) goto lab_p27_L_6242;
  goto lab_p27_L_6221;
  lab_p27_L_623D: ;
  cpu_pop_de();
  p27_L_5B53();
  /* scf */
  lab_p27_L_6242: ;
  cpu_pop_de();
  mem_write8((uint16_t)(iy + 0x0D), d);
  return;
}

/* flash page 27 cpu 0x6247 (offset 0x2247) */
void p27_L_6247(void) {
  cpu_push_af();
  cpu_push_hl();
  a = mem_read8(0x8198);
  cpu_push_af();
  set_hl(mem_read16(0x86D7));
  cpu_push_hl();
  set_hl(0x81B7);
  /* sub (hl) */
  if (flag_z()) goto lab_p27_L_6262;
  lab_p27_L_6257: ;
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p27_L_625F;
  p27_L_60A1();
  goto lab_p27_L_6257;
  lab_p27_L_625F: ;
  p27_L_5B53();
  lab_p27_L_6262: ;
  cpu_pop_hl();
  mem_write16(0x86D7, hl());
  cpu_pop_hl();
  a = h;
  mem_write8(0x8198, a);
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 27 cpu 0x6297 (offset 0x2297) */
void p27_L_6297(void) {
  set_hl(0x62D0);
  p27_L_5816();
  a = 0;
  flag_logic(a);
  mem_write8(0x8198, a);
  a = mem_read8(0x8177);
  set_hl(0x5EB9);
  p27_L_5EA2();
  mem_write8(0x81B3, a);
  a = b;
  mem_write8(0x81B5, a);
  a = mem_read8(0x8179);
  set_hl(0x5EC1);
  p27_L_5EA2();
  mem_write8(0x81B4, a);
  a = b;
  mem_write8(0x81B6, a);
  p27_L_5FC6();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 5)));
  p27_L_5BF3();
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 1)));
  return;
}

/* flash page 27 cpu 0x638B (offset 0x238B) */
void p27_L_638B(void) {
  a = mem_read8(0x8198);
  cpu_push_af();
  set_hl(mem_read16(0x86D7));
  cpu_push_hl();
  p27_L_6211();
  p27_L_6247();
  p27_L_5BD7();
  p27_L_5FFB();
  return;
}

/* flash page 27 cpu 0x63EE (offset 0x23EE) */
void p27_L_63EE(void) {
  goto lab_p27_L_63EE;
  lab_p27_L_63CD: ;
  p27_L_5BD7();
  p27_L_580C();
  return;
  lab_p27_L_63EE: ;
  p27_L_63F3();
  goto lab_p27_L_63CD;
}

/* flash page 27 cpu 0x63F3 (offset 0x23F3) */
void p27_L_63F3(void) {
  set_hl(mem_read16(0x8160));
  set_de(mem_read16(0x8172));
  a = mem_read8(0x8162);
  cpu_push_af();
  p27_L_6BC5();
  cpu_pop_af();
  p27_L_6402();
  return;
}

/* flash page 27 cpu 0x6402 (offset 0x2402) */
void p27_L_6402(void) {
  mem_write8(0x8162, a);
  return;
}

/* flash page 27 cpu 0x6406 (offset 0x2406) */
void p27_L_6406(void) {
  goto lab_p27_L_6406;
  lab_p27_L_5A89: ;
  b = 0x40;
  set_hl(0x9872);
  a = mem_read8((uint16_t)(iy + 0x14));
  cpu_push_af();
  p00_L_33ED();
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x14), a);
  set_hl(mem_read16(0x819B));
  mem_write16(0x86D7, hl());
  p00_L_345F();
  if (flag_nz()) goto lab_p27_L_5AAE;
  a = a | a;
  flag_logic(a);
  p27_L_6406();
  p00_L_3D89();
  lab_p27_L_5AAB: ;
  p27_L_580C();
  return;
  lab_p27_L_5AAE: ;
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 1)));
  goto lab_p27_L_5AAB;
  lab_p27_L_6406: ;
  if (flag_c()) goto lab_p27_L_5A89;
  p27_L_5A2C();
  a = mem_read8(0x86D8);
  flag_cmp(a, 0x33);
  if (flag_c()) return;
  a = 0x80;
  d = a;
  set_hl(0x0800);
  set_bc(0x0708);
  p00_L_2FA9();
  a = e;
  p00_L_3DE9();
  return;
}

/* flash page 27 cpu 0x6424 (offset 0x2424) */
void p27_L_6424(void) {
  a = (uint8_t)(a - 1);
  set_hl(0x86D7);
  /* add a,(hl) */
  set_hl(0x8179);
  cpu_cp_hl();
  return;
}

/* flash page 27 cpu 0x642E (offset 0x242E) */
void p27_L_642E(void) {
  a = a & 0x7F;
  flag_logic(a);
  l = a;
  h = 0x00;
  set_hl((uint16_t)(hl() + hl()));
  set_hl((uint16_t)(hl() + hl()));
  cpu_push_hl();
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 27 cpu 0x6503 (offset 0x2503) */
void p27_L_6503(void) {
  mem_write8((uint16_t)(iy + 0x32), (uint8_t)(mem_read8((uint16_t)(iy + 0x32)) | (1u << 7)));
  set_hl(0x8661);
  p00_L_3D3B();
  mem_write8((uint16_t)(iy + 0x32), (uint8_t)(mem_read8((uint16_t)(iy + 0x32)) & ~(1u << 7)));
  return;
}

/* flash page 27 cpu 0x6512 (offset 0x2512) */
void p27_L_6512(void) {
  b = 0x00;
  goto lab_p27_L_6518;
  lab_p27_L_6518: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2B)) & (1u << 2)) == 0);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x2B), (uint8_t)(mem_read8((uint16_t)(iy + 0x2B)) | (1u << 2)));
  a = 0x3F;
  a = (uint8_t)(a - h);
  h = l;
  l = a;
  a = 0x3F;
  a = (uint8_t)(a - d);
  d = e;
  e = a;
  cpu_push_hl();
  h = b;
  cpu_pop_bc();
  cpu_push_bc();
  b = d;
  p00_L_3495();
  cpu_pop_bc();
  cpu_push_bc();
  c = e;
  p00_L_3495();
  cpu_pop_bc();
  cpu_push_de();
  d = b;
  p00_L_3495();
  cpu_pop_de();
  e = c;
  p00_L_3495();
  cpu_pop_af();
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x2B), (uint8_t)(mem_read8((uint16_t)(iy + 0x2B)) & ~(1u << 2)));
  return;
}

/* flash page 27 cpu 0x6516 (offset 0x2516) */
void p27_L_6516(void) {
  b = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2B)) & (1u << 2)) == 0);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x2B), (uint8_t)(mem_read8((uint16_t)(iy + 0x2B)) | (1u << 2)));
  a = 0x3F;
  a = (uint8_t)(a - h);
  h = l;
  l = a;
  a = 0x3F;
  a = (uint8_t)(a - d);
  d = e;
  e = a;
  cpu_push_hl();
  h = b;
  cpu_pop_bc();
  cpu_push_bc();
  b = d;
  p00_L_3495();
  cpu_pop_bc();
  cpu_push_bc();
  c = e;
  p00_L_3495();
  cpu_pop_bc();
  cpu_push_de();
  d = b;
  p00_L_3495();
  cpu_pop_de();
  e = c;
  p00_L_3495();
  cpu_pop_af();
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x2B), (uint8_t)(mem_read8((uint16_t)(iy + 0x2B)) & ~(1u << 2)));
  return;
}

/* flash page 27 cpu 0x6556 (offset 0x2556) */
void p27_L_6556(void) {
  c = 0x02;
  goto lab_p27_L_6560;
  lab_p27_L_6560: ;
  cpu_ld_a_i();
  cpu_push_af();
  /* di */
  a = d;
  a = (uint8_t)(a - h);
  a = (uint8_t)(a + 1);
  mem_write8(0x8127, a);
  a = h;
  a = (uint8_t)(a + 0x80);
  mem_write8(0x8125, a);
  cpu_push_de();
  a = l;
  set_hl(0x5EB9);
  p27_L_5EA2();
  mem_write8(0x8128, a);
  a = b;
  mem_write8(0x8124, a);
  cpu_pop_de();
  a = e;
  set_hl(0x5EC1);
  p27_L_5EA2();
  mem_write8(0x8129, a);
  a = b;
  set_hl(0x8124);
  /* sub (hl) */
  a = (uint8_t)(a + 1);
  mem_write8(0x8126, a);
  p00_lcd_cmd_07();
  a = mem_read8(0x8127);
  b = a;
  a = mem_read8(0x8125);
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 4)));
  cpu_push_bc();
  cpu_push_af();
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p27_L_642E();
  cpu_ex_de_hl();
  a = mem_read8(0x8124);
  a = a & 0x1F;
  flag_logic(a);
  l = a;
  h = 0x00;
  set_hl((uint16_t)(hl() + de()));
  p27_L_65B5();
  return;
}

/* flash page 27 cpu 0x655A (offset 0x255A) */
void p27_L_655A(void) {
  c = 0x00;
  goto lab_p27_L_6560;
  lab_p27_L_6560: ;
  cpu_ld_a_i();
  cpu_push_af();
  /* di */
  a = d;
  a = (uint8_t)(a - h);
  a = (uint8_t)(a + 1);
  mem_write8(0x8127, a);
  a = h;
  a = (uint8_t)(a + 0x80);
  mem_write8(0x8125, a);
  cpu_push_de();
  a = l;
  set_hl(0x5EB9);
  p27_L_5EA2();
  mem_write8(0x8128, a);
  a = b;
  mem_write8(0x8124, a);
  cpu_pop_de();
  a = e;
  set_hl(0x5EC1);
  p27_L_5EA2();
  mem_write8(0x8129, a);
  a = b;
  set_hl(0x8124);
  /* sub (hl) */
  a = (uint8_t)(a + 1);
  mem_write8(0x8126, a);
  p00_lcd_cmd_07();
  a = mem_read8(0x8127);
  b = a;
  a = mem_read8(0x8125);
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 4)));
  cpu_push_bc();
  cpu_push_af();
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p27_L_642E();
  cpu_ex_de_hl();
  a = mem_read8(0x8124);
  a = a & 0x1F;
  flag_logic(a);
  l = a;
  h = 0x00;
  set_hl((uint16_t)(hl() + de()));
  p27_L_65B5();
  return;
}

/* flash page 27 cpu 0x65B5 (offset 0x25B5) */
void p27_L_65B5(void) {
  goto lab_p27_L_65B5;
  lab_p27_L_659D: ;
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 4)));
  cpu_push_bc();
  cpu_push_af();
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p27_L_642E();
  cpu_ex_de_hl();
  a = mem_read8(0x8124);
  a = a & 0x1F;
  flag_logic(a);
  l = a;
  h = 0x00;
  set_hl((uint16_t)(hl() + de()));
  lab_p27_L_65B5: ;
  cpu_ex_de_hl();
  set_hl(0x86EC);
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  cpu_push_bc();
  set_bc(0x9340);
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_bc();
  cpu_push_hl();
  cpu_push_de();
  p27_L_663A();
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  lab_p27_L_65CB: ;
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  cpu_push_hl();
  set_hl(0x812A);
  flag_set_z((c & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p27_L_65DD;
  /* or (hl) */
  flag_set_z((c & (1u << 1)) == 0);
  if (flag_z()) goto lab_p27_L_65DE;
  lab_p27_L_65DD: ;
  /* xor (hl) */
  lab_p27_L_65DE: ;
  mem_write8(de(), a);
  mem_write8(hl(), 0xFF);
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_65FC;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_65CB;
  a = mem_read8(0x8129);
  mem_write8(0x812A, a);
  b = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 4)) == 0);
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 4)));
  if (flag_z()) goto lab_p27_L_65CB;
  lab_p27_L_65FC: ;
  cpu_pop_de();
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 4)));
  p27_L_663A();
  lab_p27_L_6605: ;
  a = mem_read8(de());
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p27_L_660D;
  mem_write8(hl(), a);
  lab_p27_L_660D: ;
  p00_lcd_busy_wait();
  lcd_write_data(); /* ti_lcd_op_write(a) */
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_662C;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_6605;
  a = mem_read8(0x8129);
  mem_write8(0x812A, a);
  b = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 4)) == 0);
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 4)));
  if (flag_z()) goto lab_p27_L_6605;
  lab_p27_L_662C: ;
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p27_L_659D;
  p00_lcd_cmd_05();
  cpu_pop_af();
  if (flag_po()) return;
  /* ei */
  return;
}

/* flash page 27 cpu 0x65EE (offset 0x25EE) */
void p27_L_65EE(void) {
  goto lab_p27_L_65EE;
  lab_p27_L_659D: ;
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 4)));
  cpu_push_bc();
  cpu_push_af();
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p27_L_642E();
  cpu_ex_de_hl();
  a = mem_read8(0x8124);
  a = a & 0x1F;
  flag_logic(a);
  l = a;
  h = 0x00;
  set_hl((uint16_t)(hl() + de()));
  p27_L_65B5();
  return;
  lab_p27_L_65EE: ;
  set_hl(mem_read16(0x0681));
  set_bc(0xCBFD);
  set_hl(mem_read16(0xFD66));
  /* sra d */
  a = a & 0x28;
  flag_logic(a);
  p00_rst08();
  cpu_pop_de();
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 4)));
  p27_L_663A();
  lab_p27_L_6605: ;
  a = mem_read8(de());
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p27_L_660D;
  mem_write8(hl(), a);
  lab_p27_L_660D: ;
  p00_lcd_busy_wait();
  lcd_write_data(); /* ti_lcd_op_write(a) */
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_662C;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_6605;
  a = mem_read8(0x8129);
  mem_write8(0x812A, a);
  b = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 4)) == 0);
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 4)));
  if (flag_z()) goto lab_p27_L_6605;
  lab_p27_L_662C: ;
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p27_L_659D;
  p00_lcd_cmd_05();
  cpu_pop_af();
  if (flag_po()) return;
  /* ei */
  return;
}

/* flash page 27 cpu 0x663A (offset 0x263A) */
void p27_L_663A(void) {
  a = mem_read8(0x8126);
  a = (uint8_t)(a - 1);
  b = a;
  a = mem_read8(0x8128);
  if (flag_nz()) goto lab_p27_L_664A;
  cpu_push_hl();
  set_hl(0x8129);
  /* and (hl) */
  cpu_pop_hl();
  lab_p27_L_664A: ;
  mem_write8(0x812A, a);
  a = mem_read8(0x8124);
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) return;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  return;
}

/* flash page 27 cpu 0x6659 (offset 0x2659) */
void p27_L_6659(void) {
  goto lab_p27_L_6659;
  lab_p27_L_663F: ;
  a = mem_read8(0x8128);
  if (flag_nz()) goto lab_p27_L_664A;
  cpu_push_hl();
  set_hl(0x8129);
  /* and (hl) */
  cpu_pop_hl();
  lab_p27_L_664A: ;
  mem_write8(0x812A, a);
  a = mem_read8(0x8124);
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) return;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  return;
  lab_p27_L_6659: ;
  a = mem_read8(0x8126);
  a = (uint8_t)(a - 1);
  b = a;
  a = mem_read8(0x8664);
  set_hl(0x8124);
  cpu_cp_hl();
  goto lab_p27_L_663F;
}

/* flash page 27 cpu 0x6667 (offset 0x2667) */
void p27_L_6667(void) {
  set_hl(0x5EB9);
  p27_L_5EA2();
  mem_write8(0x8128, a);
  c = 0x00;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p27_L_667D;
  lab_p27_L_6676: ;
  /* srl a */
  if (flag_nc()) goto lab_p27_L_667D;
  c = (uint8_t)(c + 1);
  goto lab_p27_L_6676;
  lab_p27_L_667D: ;
  a = c;
  mem_write8(0x865F, a);
  return;
}

/* flash page 27 cpu 0x6682 (offset 0x2682) */
void p27_L_6682(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 3)) == 0);
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2B)) & (1u << 5)) == 0);
  if (flag_nz()) return;
  flag_cmp(a, a);
  return;
}

/* flash page 27 cpu 0x67DC (offset 0x27DC) */
void p27_L_67DC(void) {
  goto lab_p27_L_67DC;
  lab_p27_L_671D: ;
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 4)));
  cpu_push_af();
  cpu_push_bc();
  cpu_push_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2B)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p27_L_6732;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p27_L_642E();
  lab_p27_L_6732: ;
  a = mem_read8(0x8660);
  mem_write8(0x8665, a);
  a = mem_read8(0x8124);
  mem_write8(0x844F, a);
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_z()) goto lab_p27_L_6746;
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 3)));
  lab_p27_L_6746: ;
  cpu_ex_de_hl();
  a = mem_read8(0x844F);
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p27_L_675B;
  set_hl(0x865F);
  /* add a,(hl) */
  mem_write8(0x844F, a);
  a = 0x00;
  goto lab_p27_L_6760;
  lab_p27_L_675B: ;
  mem_write8(0x844F, a);
  a = a & 0x1F;
  flag_logic(a);
  lab_p27_L_6760: ;
  l = a;
  h = 0x00;
  set_hl((uint16_t)(hl() + de()));
  set_bc(0x9340);
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x8661, hl());
  p27_L_6659();
  p27_L_6682();
  if (flag_nz()) goto lab_p27_L_6795;
  a = mem_read8(0x8664);
  set_hl(0x8124);
  cpu_cp_hl();
  cpu_pop_hl();
  cpu_push_bc();
  if (flag_nz()) goto lab_p27_L_679E;
  a = mem_read8(0x812A);
  b = 0x00;
  lab_p27_L_6783: ;
  /* sla a */
  if (flag_c()) goto lab_p27_L_678A;
  b = (uint8_t)(b + 1);
  goto lab_p27_L_6783;
  lab_p27_L_678A: ;
  a = b;
  a = a | a;
  flag_logic(a);
  a = mem_read8(hl());
  if (flag_z()) goto lab_p27_L_6793;
  lab_p27_L_678F: ;
  /* srl a */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_678F;
  lab_p27_L_6793: ;
  goto lab_p27_L_67C0;
  lab_p27_L_6795: ;
  cpu_pop_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2B)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p27_L_6885;
  cpu_push_bc();
  lab_p27_L_679E: ;
  a = mem_read8(0x865F);
  a = a | a;
  flag_logic(a);
  b = a;
  a = mem_read8(hl());
  if (flag_z()) goto lab_p27_L_67C0;
  c = 0x00;
  lab_p27_L_67A8: ;
  /* sla a */
  /* rl c */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_67A8;
  mem_write8(0x8663, a);
  a = mem_read8(0x8124);
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_z()) goto lab_p27_L_67BF;
  a = 0x20;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  lab_p27_L_67BF: ;
  a = c;
  lab_p27_L_67C0: ;
  cpu_push_hl();
  cpu_push_af();
  a = mem_read8(0x8665);
  b = a;
  set_hl(0x865F);
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p27_L_67CF;
  a = 0x08;
  lab_p27_L_67CF: ;
  /* neg */
  a = (uint8_t)(a + b);
  mem_write8(0x8665, a);
  cpu_pop_af();
  set_hl(0x812A);
  p27_L_68A6();
  lab_p27_L_67DC: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p27_L_67F3;
  set_hl(0x844F);
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 3)) == 0);
  set_hl(mem_read16(0x8661));
  if (flag_nz()) goto lab_p27_L_67F3;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x8661, hl());
  lab_p27_L_67F3: ;
  a = mem_read8(0x844F);
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p27_L_6810;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_6803;
  a = (uint8_t)(a + 0x08);
  goto lab_p27_L_6812;
  lab_p27_L_6803: ;
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 3)));
  a = 0x20;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  goto lab_p27_L_6812;
  lab_p27_L_6810: ;
  c = a;
  a = (uint8_t)(a + 1);
  lab_p27_L_6812: ;
  mem_write8(0x844F, a);
  cpu_pop_hl();
  a = mem_read8(0x8665);
  a = a | a;
  flag_logic(a);
  b = a;
  if (flag_z()) goto lab_p27_L_6887;
  a = c;
  flag_cmp(a, 0x2B);
  if (flag_nz()) goto lab_p27_L_6824;
  goto lab_p27_L_6887;
  lab_p27_L_6824: ;
  a = mem_read8(0x865F);
  b = a;
  a = mem_read8(0x8665);
  flag_cmp(a, 0x09);
  if (flag_nc()) goto lab_p27_L_683B;
  cpu_pop_af();
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 4)));
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p27_L_683B;
  a = 0;
  flag_logic(a);
  goto lab_p27_L_6840;
  lab_p27_L_683B: ;
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  lab_p27_L_6840: ;
  cpu_push_hl();
  c = a;
  a = b;
  a = a | a;
  flag_logic(a);
  a = c;
  if (flag_z()) goto lab_p27_L_6856;
  e = 0x00;
  lab_p27_L_6849: ;
  /* sla a */
  /* rl e */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_6849;
  set_hl(0x8663);
  c = mem_read8(hl());
  mem_write8(hl(), a);
  a = c;
  a = a | e;
  flag_logic(a);
  lab_p27_L_6856: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p27_L_6864;
  set_hl(0x8129);
  p27_L_68A6();
  goto lab_p27_L_6874;
  lab_p27_L_6864: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x3C)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p27_L_6874;
  p27_L_6682();
  if (flag_nz()) goto lab_p27_L_6874;
  p00_lcd_busy_wait();
  lcd_write_data(); /* ti_lcd_op_write(a) */
  lab_p27_L_6874: ;
  cpu_push_af();
  a = mem_read8(0x8665);
  a = (uint8_t)(a - 0x08);
  if (flag_nc()) goto lab_p27_L_687E;
  a = 0x00;
  lab_p27_L_687E: ;
  mem_write8(0x8665, a);
  cpu_pop_af();
  goto lab_p27_L_67DC;
  lab_p27_L_6885: ;
  a = b;
  cpu_push_af();
  lab_p27_L_6887: ;
  cpu_pop_af();
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_6890;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  lab_p27_L_6890: ;
  cpu_pop_bc();
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  if (flag_nz()) goto lab_p27_L_689B;
  a = 0x80;
  mem_write8((uint16_t)(iy + 0x2B), (uint8_t)(mem_read8((uint16_t)(iy + 0x2B)) & ~(1u << 5)));
  lab_p27_L_689B: ;
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p27_L_671D;
  p00_lcd_cmd_05();
  cpu_pop_af();
  if (flag_po()) return;
  /* ei */
  return;
}

/* flash page 27 cpu 0x68A6 (offset 0x28A6) */
void p27_L_68A6(void) {
  cpu_push_hl();
  /* and (hl) */
  c = a;
  set_hl(0x844F);
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p27_L_68C8;
  flag_set_z((mem_read8((uint16_t)(iy + 0x3C)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p27_L_68BE;
  set_hl(mem_read16(0x8661));
  a = mem_read8(hl());
  goto lab_p27_L_68C8;
  lab_p27_L_68BE: ;
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  lab_p27_L_68C8: ;
  cpu_pop_hl();
  /* or (hl) */
  /* xor (hl) */
  a = a | c;
  flag_logic(a);
  c = a;
  a = mem_read8(0x844F);
  p27_L_6682();
  if (flag_nz()) return;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p00_lcd_busy_wait();
  a = c;
  flag_set_z((mem_read8((uint16_t)(iy + 0x3C)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  lcd_write_data(); /* ti_lcd_op_write(a) */
  return;
}

/* flash page 27 cpu 0x6937 (offset 0x2937) */
void p27_L_6937(void) {
  goto lab_p27_L_6937;
  lab_p27_L_6918: ;
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p27_L_692D;
  mem_write8(0x8446, a);
  a = e;
  mem_write8(0x8444, a);
  flag_cmp(a, 0x07);
  if (flag_z()) goto lab_p27_L_693B;
  flag_cmp(a, 0x08);
  if (flag_z()) goto lab_p27_L_693B;
  goto lab_p27_L_6934;
  lab_p27_L_692D: ;
  mem_write8(0x8444, a);
  a = e;
  mem_write8(0x8446, a);
  lab_p27_L_6934: ;
  a = 0x29;
  return;
  lab_p27_L_6937: ;
  flag_cmp(a, 0x29);
  if (flag_z()) goto lab_p27_L_6918;
  lab_p27_L_693B: ;
  /* di */
  p27_L_6A43();
  /* ei */
  a = 0x28;
  return;
}

/* flash page 27 cpu 0x6943 (offset 0x2943) */
void p27_L_6943(void) {
  p27_L_695A();
  a = a | c;
  flag_logic(a);
  mem_write8(hl(), a);
  return;
}

/* flash page 27 cpu 0x6949 (offset 0x2949) */
void p27_L_6949(void) {
  p27_L_6943();
  a = a ^ c;
  flag_logic(a);
  mem_write8(hl(), a);
  return;
}

/* flash page 27 cpu 0x6952 (offset 0x2952) */
void p27_L_6952(void) {
  p27_L_695A();
  a = a & c;
  flag_logic(a);
  return;
}

/* flash page 27 cpu 0x6957 (offset 0x2957) */
void p27_L_6957(void) {
  a = mem_read8(0x8162);
  p27_L_695A();
  return;
}

/* flash page 27 cpu 0x695A (offset 0x295A) */
void p27_L_695A(void) {
  cpu_push_af();
  a = mem_read8(0x8171);
  p27_L_6985();
  cpu_pop_bc();
  a = (uint8_t)(a + b);
  a = (uint8_t)(a - 1);
  b = a;
  a = a & 0x07;
  flag_logic(a);
  e = a;
  d = 0x00;
  set_hl(0x697D);
  set_hl((uint16_t)(hl() + de()));
  c = mem_read8(hl());
  a = b;
  /* srl a */
  /* srl a */
  /* srl a */
  e = a;
  set_hl(mem_read16(0x8163));
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  return;
}

/* flash page 27 cpu 0x6985 (offset 0x2985) */
void p27_L_6985(void) {
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p27_L_6992;
  set_hl(mem_read16(0x8157));
  p00_L_190B();
  mem_write8(0x812B, a);
  return;
  lab_p27_L_6992: ;
  b = a;
  cpu_push_bc();
  set_hl(mem_read16(0x8157));
  p00_L_190B();
  a = (uint8_t)(a + 1);
  lab_p27_L_699B: ;
  cpu_push_af();
  p27_L_6FE1();
  cpu_pop_af();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_z()) return;
  set_hl(0x812B);
  /* add a,(hl) */
  a = (uint8_t)(a + 1);
  cpu_push_bc();
  goto lab_p27_L_699B;
}

/* flash page 27 cpu 0x69AB (offset 0x29AB) */
void p27_L_69AB(void) {
  a = mem_read8(0x8162);
  p27_L_69AE();
  return;
}

/* flash page 27 cpu 0x69AE (offset 0x29AE) */
void p27_L_69AE(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x2B)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p27_L_69BB;
  b = a;
  a = 0x2B;
  p27_L_6D37();
  if (flag_nz()) return;
  lab_p27_L_69BB: ;
  b = a;
  a = mem_read8(0x8171);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p27_L_69CA;
  cpu_push_bc();
  p27_L_6985();
  cpu_pop_bc();
  a = (uint8_t)(a + b);
  b = a;
  lab_p27_L_69CA: ;
  a = b;
  p27_L_6FE1();
  return;
}

/* flash page 27 cpu 0x69CE (offset 0x29CE) */
void p27_L_69CE(void) {
  /* di */
  p27_L_69AB();
  a = mem_read8(0x812B);
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) return;
  a = hw_in(PORT_MMU_A);
  set_hl(0x6AE6);
  p27_L_7915();
  mem_write8((uint16_t)(iy + 0x37), (uint8_t)(mem_read8((uint16_t)(iy + 0x37)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  p00_L_3F0F();
  return;
}

/* flash page 27 cpu 0x69EC (offset 0x29EC) */
void p27_L_69EC(void) {
  mem_write8(0x8162, a);
  p27_L_69CE();
  /* ei */
  p00_L_3F21();
  mem_write8(0x8444, a);
  p27_L_69F9();
  return;
}

/* flash page 27 cpu 0x69F9 (offset 0x29F9) */
void p27_L_69F9(void) {
  cpu_push_af();
  p00_L_3EFD();
  p27_L_7713();
  p27_L_69AB();
  cpu_pop_af();
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p27_L_6A26;
  set_hl(mem_read16(0x812E));
  set_de(mem_read16(0x8130));
  b = h;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p27_L_6A1F;
  b = l;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p27_L_6A1F;
  b = e;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p27_L_6A1F;
  b = d;
  lab_p27_L_6A1F: ;
  a = b;
  mem_write8(0x816C, a);
  a = 0x28;
  return;
  lab_p27_L_6A26: ;
  a = 0x04;
  if (flag_nz()) return;
  set_de(mem_read16(0x8132));
  a = 0x29;
  return;
}

/* flash page 27 cpu 0x6A30 (offset 0x2A30) */
void p27_L_6A30(void) {
  a = mem_read8(0x8170);
  b = a;
  lab_p27_L_6A34: ;
  cpu_push_bc();
  a = b;
  p27_L_6C05();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_6A34;
  a = 0x01;
  mem_write8(0x8162, a);
  return;
}

/* flash page 27 cpu 0x6A42 (offset 0x2A42) */
void p27_L_6A42(void) {
  if (flag_z()) return;
  p27_L_6A43();
  return;
}

/* flash page 27 cpu 0x6A43 (offset 0x2A43) */
void p27_L_6A43(void) {
  a = mem_read8(0x8444);
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p27_L_6A62;
  p27_L_6A30();
  set_hl(0x8171);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p27_L_6A51: ;
  a = mem_read8(hl());
  p27_L_6985();
  a = mem_read8(0x812B);
  b = a;
  p27_L_6BE6();
  a = 0x01;
  mem_write8(0x8162, a);
  return;
  lab_p27_L_6A62: ;
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p27_L_6A6F;
  p27_L_6A30();
  set_hl(0x8171);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  goto lab_p27_L_6A51;
  lab_p27_L_6A6F: ;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p27_L_6A8D;
  if (flag_nc()) return;
  p27_L_6AD9();
  p27_L_6C02();
  set_hl(0x8162);
  a = mem_read8(hl());
  mem_write8(hl(), 0x00);
  p27_L_6C21();
  a = mem_read8(0x816C);
  mem_write8(0x8162, a);
  p27_L_6C21();
  return;
  lab_p27_L_6A8D: ;
  set_hl(0x812B);
  flag_set_z((mem_read8(hl()) & (1u << 3)) == 0);
  if (flag_z()) return;
  p27_L_6957();
  cpu_push_bc();
  cpu_push_hl();
  p27_L_69AB();
  cpu_pop_hl();
  cpu_pop_bc();
  a = mem_read8(0x8134);
  a = a | a;
  flag_logic(a);
  a = mem_read8(hl());
  if (flag_z()) goto lab_p27_L_6AD2;
  a = a & c;
  flag_logic(a);
  if (flag_nz()) goto lab_p27_L_6B14;
  a = mem_read8(hl());
  a = a | c;
  flag_logic(a);
  mem_write8(hl(), a);
  set_hl(0x812B);
  a = mem_read8(0x8134);
  lab_p27_L_6AB0: ;
  cpu_push_af();
  cpu_push_hl();
  p27_L_6FD0();
  cpu_pop_hl();
  cpu_push_hl();
  a = mem_read8(0x8162);
  cpu_cp_hl();
  if (flag_z()) goto lab_p27_L_6AC9;
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_6ACE;
  cpu_push_af();
  p27_L_6949();
  cpu_pop_af();
  p27_L_6ADC();
  lab_p27_L_6AC9: ;
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  goto lab_p27_L_6AB0;
  lab_p27_L_6ACE: ;
  cpu_pop_hl();
  cpu_pop_af();
  goto lab_p27_L_6B14;
  lab_p27_L_6AD2: ;
  a = a ^ c;
  flag_logic(a);
  mem_write8(hl(), a);
  a = a & c;
  flag_logic(a);
  if (flag_nz()) goto lab_p27_L_6B14;
  p27_L_6AD9();
  return;
  lab_p27_L_6B14: ;
  a = mem_read8(0x8162);
  p27_L_6B17();
  return;
}

/* flash page 27 cpu 0x6AD9 (offset 0x2AD9) */
void p27_L_6AD9(void) {
  a = mem_read8(0x8162);
  p27_L_6ADC();
  return;
}

/* flash page 27 cpu 0x6ADC (offset 0x2ADC) */
void p27_L_6ADC(void) {
  mem_write8(0x8176, a);
  p27_L_69AE();
  a = 0x24;
  p27_L_6B2A();
  return;
}

/* flash page 27 cpu 0x6B00 (offset 0x2B00) */
void p27_L_6B00(void) {
  a = (uint8_t)(a + c);
  flag_set_z((a & (1u << 2)) == 0);
  cpu_pop_bc();
  a = b;
  return;
}

/* flash page 27 cpu 0x6B06 (offset 0x2B06) */
void p27_L_6B06(void) {
  set_hl((uint16_t)(hl() + 1));
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  if (flag_nz()) return;
  d = 0x00;
  e = (uint8_t)(e + 1);
  set_hl((uint16_t)(hl() + de()));
  /* add a,(hl) */
  return;
}

/* flash page 27 cpu 0x6B17 (offset 0x2B17) */
void p27_L_6B17(void) {
  mem_write8(0x8176, a);
  p27_L_69AE();
  a = 0x23;
  p27_L_6B2A();
  return;
}

/* flash page 27 cpu 0x6B2A (offset 0x2B2A) */
void p27_L_6B2A(void) {
  set_hl(0x812B);
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p27_L_6B38;
  b = a;
  a = 0x2A;
  p27_L_6D37();
  return;
  lab_p27_L_6B38: ;
  flag_set_z((mem_read8(hl()) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p27_L_6B47;
  flag_cmp(a, 0x24);
  cpu_push_af();
  if (flag_nz()) p27_L_6BFD();
  cpu_pop_af();
  if (flag_z()) p27_L_6C19();
  return;
  lab_p27_L_6B47: ;
  flag_set_z((mem_read8(hl()) & (1u << 1)) == 0);
  set_hl(0x8135);
  if (flag_z()) goto lab_p27_L_6B5C;
  flag_cmp(a, 0x24);
  cpu_push_af();
  p27_L_6BFD();
  p27_L_6C19();
  cpu_pop_af();
  if (flag_nz()) p27_L_6C0B();
  return;
  lab_p27_L_6B5C: ;
  flag_cmp(a, 0x24);
  cpu_push_af();
  a = mem_read8(hl());
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p27_L_6B81;
  if (flag_nc()) goto lab_p27_L_6B97;
  p27_L_5DCC();
  set_hl(mem_read16(0x812C));
  h = (uint8_t)(h - 1);
  l = (uint8_t)(l - 1);
  l = (uint8_t)(l - 1);
  a = (uint8_t)(a + l);
  a = (uint8_t)(a + 0x03);
  e = a;
  a = h;
  a = (uint8_t)(a + 0x08);
  lab_p27_L_6B76: ;
  d = a;
  cpu_pop_af();
  cpu_push_af();
  if (flag_nz()) p27_L_6516();
  cpu_pop_af();
  if (flag_z()) p27_L_6512();
  return;
  lab_p27_L_6B81: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  /* add a,(hl) */
  /* add a,(hl) */
  set_hl(mem_read16(0x812C));
  l = (uint8_t)(l - 1);
  l = (uint8_t)(l - 1);
  h = (uint8_t)(h - 1);
  h = (uint8_t)(h - 1);
  a = (uint8_t)(a + l);
  a = (uint8_t)(a + 0x02);
  e = a;
  a = h;
  a = (uint8_t)(a + 0x0A);
  goto lab_p27_L_6B76;
  lab_p27_L_6B97: ;
  p27_L_6B06();
  set_hl(mem_read16(0x812C));
  l = (uint8_t)(l - 1);
  l = (uint8_t)(l - 1);
  h = (uint8_t)(h - 1);
  h = (uint8_t)(h - 1);
  a = (uint8_t)(a + l);
  a = (uint8_t)(a + 0x03);
  e = a;
  a = mem_read8(0x8137);
  a = (uint8_t)(a + 0x02);
  a = (uint8_t)(a + h);
  d = a;
  goto lab_p27_L_6B76;
}

/* flash page 27 cpu 0x6BAE (offset 0x2BAE) */
void p27_L_6BAE(void) {
  a = 0x01;
  if (flag_nc()) goto lab_p27_L_6BB3;
  a = (uint8_t)(a - 1);
  lab_p27_L_6BB3: ;
  mem_write8(0x8174, a);
  a = 0x01;
  mem_write8(0x8171, a);
  a = mem_read8((uint16_t)(iy + 0x0C));
  mem_write8(0x816B, a);
  mem_write16(0x8163, bc());
  p27_L_6BC5();
  return;
}

/* flash page 27 cpu 0x6BC5 (offset 0x2BC5) */
void p27_L_6BC5(void) {
  mem_write16(0x8160, hl());
  mem_write16(0x8172, de());
  cpu_push_de();
  p27_L_6556();
  cpu_pop_de();
  a = mem_read8(0x8174);
  a = (uint8_t)(a - 0x01);
  set_hl(mem_read16(0x8160));
  if (flag_c()) p27_L_6516();
  a = mem_read8(0x8171);
  p27_L_6985();
  a = mem_read8(0x812B);
  b = a;
  p27_L_6BE6();
  return;
}

/* flash page 27 cpu 0x6BE6 (offset 0x2BE6) */
void p27_L_6BE6(void) {
  mem_write8(0x8170, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x8162, a);
  lab_p27_L_6BED: ;
  cpu_push_bc();
  a = b;
  p27_L_6C21();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_6BED;
  return;
}

/* flash page 27 cpu 0x6BFD (offset 0x2BFD) */
void p27_L_6BFD(void) {
  a = mem_read8(0x8176);
  p27_L_6C05();
  return;
}

/* flash page 27 cpu 0x6C02 (offset 0x2C02) */
void p27_L_6C02(void) {
  a = mem_read8(0x8162);
  p27_L_6C05();
  return;
}

/* flash page 27 cpu 0x6C05 (offset 0x2C05) */
void p27_L_6C05(void) {
  c = 0x02;
  d = 0x26;
  goto lab_p27_L_6C25;
  lab_p27_L_6C25: ;
  b = a;
  a = d;
  p27_L_6D37();
  if (flag_nz()) return;
  a = b;
  set_hl(mem_read16(0x86D7));
  cpu_push_hl();
  p27_L_6C38();
  cpu_pop_hl();
  mem_write16(0x86D7, hl());
  return;
}

/* flash page 27 cpu 0x6C0B (offset 0x2C0B) */
void p27_L_6C0B(void) {
  a = mem_read8(0x8176);
  goto lab_p27_L_6C13;
  lab_p27_L_6C13: ;
  c = 0x01;
  d = 0x27;
  goto lab_p27_L_6C25;
  lab_p27_L_6C25: ;
  b = a;
  a = d;
  p27_L_6D37();
  if (flag_nz()) return;
  a = b;
  set_hl(mem_read16(0x86D7));
  cpu_push_hl();
  p27_L_6C38();
  cpu_pop_hl();
  mem_write16(0x86D7, hl());
  return;
}

/* flash page 27 cpu 0x6C19 (offset 0x2C19) */
void p27_L_6C19(void) {
  a = mem_read8(0x8176);
  p27_L_6C21();
  return;
}

/* flash page 27 cpu 0x6C21 (offset 0x2C21) */
void p27_L_6C21(void) {
  c = 0x00;
  d = 0x25;
  b = a;
  a = d;
  p27_L_6D37();
  if (flag_nz()) return;
  a = b;
  set_hl(mem_read16(0x86D7));
  cpu_push_hl();
  p27_L_6C38();
  cpu_pop_hl();
  mem_write16(0x86D7, hl());
  return;
}

/* flash page 27 cpu 0x6C38 (offset 0x2C38) */
void p27_L_6C38(void) {
  goto lab_p27_L_6C38;
  lab_p27_L_6C13: ;
  c = 0x01;
  d = 0x27;
  goto lab_p27_L_6C25;
  lab_p27_L_6C25: ;
  b = a;
  a = d;
  p27_L_6D37();
  if (flag_nz()) return;
  a = b;
  set_hl(mem_read16(0x86D7));
  cpu_push_hl();
  p27_L_6C38();
  cpu_pop_hl();
  mem_write16(0x86D7, hl());
  return;
  lab_p27_L_6C38: ;
  mem_write8(0x8175, a);
  cpu_push_bc();
  p27_L_69AE();
  set_hl(mem_read16(0x812C));
  mem_write16(0x86D7, hl());
  cpu_pop_bc();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  a = mem_read8(0x8135);
  flag_cmp(a, 0xFE);
  a = c;
  if (flag_z()) goto lab_p27_L_6CCA;
  if (flag_nc()) goto lab_p27_L_6CE7;
  set_hl(0x8135);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_6C8E;
  cpu_push_af();
  p27_L_5DCC();
  b = 0x05;
  p27_L_6C61();
  return;
  lab_p27_L_6C8E: ;
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p00_L_3D53();
  mem_write8((uint16_t)(iy + 0x32), (uint8_t)(mem_read8((uint16_t)(iy + 0x32)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x32), (uint8_t)(mem_read8((uint16_t)(iy + 0x32)) & ~(1u << 6)));
  lab_p27_L_6C9B: ;
  set_hl(0x812B);
  flag_set_z((mem_read8(hl()) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p27_L_6CB7;
  a = mem_read8(0x8175);
  p27_L_6952();
  if (flag_z()) return;
  a = mem_read8(0x8175);
  p27_L_69AE();
  set_hl(0x812B);
  a = mem_read8(0x8175);
  goto lab_p27_L_6CBF;
  lab_p27_L_6CB7: ;
  a = mem_read8(0x8162);
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_nz()) return;
  lab_p27_L_6CBF: ;
  flag_set_z((mem_read8(hl()) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p27_L_6C13;
  flag_set_z((mem_read8(hl()) & (1u << 2)) == 0);
  if (flag_z()) return;
  p27_L_6B17();
  return;
  lab_p27_L_6CCA: ;
  mem_write8((uint16_t)(iy + 0x32), (uint8_t)(mem_read8((uint16_t)(iy + 0x32)) | (1u << 2)));
  set_hl(0x8136);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_6C8E;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x32), (uint8_t)(mem_read8((uint16_t)(iy + 0x32)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x32), (uint8_t)(mem_read8((uint16_t)(iy + 0x32)) & ~(1u << 2)));
  a = mem_read8(hl());
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  /* add a,(hl) */
  /* add a,(hl) */
  b = 0x07;
  p27_L_6C61();
  return;
  lab_p27_L_6CE7: ;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_6CFE;
  cpu_push_af();
  a = mem_read8(0x8137);
  a = (uint8_t)(a - 1);
  b = a;
  a = mem_read8(0x8138);
  set_hl(0x8136);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p27_L_6CFB;
  a = (uint8_t)(a + a);
  lab_p27_L_6CFB: ;
  p27_L_6C61();
  return;
  lab_p27_L_6CFE: ;
  set_hl(0x8138);
  p27_L_6D1A();
  a = mem_read8(0x8136);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p27_L_6C9B;
  set_hl(0x8139);
  set_de(mem_read16(0x8137));
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  p27_L_6D1A();
  goto lab_p27_L_6C9B;
}

/* flash page 27 cpu 0x6C61 (offset 0x2C61) */
void p27_L_6C61(void) {
  goto lab_p27_L_6C61;
  lab_p27_L_655E: ;
  c = 0x01;
  cpu_ld_a_i();
  cpu_push_af();
  /* di */
  a = d;
  a = (uint8_t)(a - h);
  a = (uint8_t)(a + 1);
  mem_write8(0x8127, a);
  a = h;
  a = (uint8_t)(a + 0x80);
  mem_write8(0x8125, a);
  cpu_push_de();
  a = l;
  set_hl(0x5EB9);
  p27_L_5EA2();
  mem_write8(0x8128, a);
  a = b;
  mem_write8(0x8124, a);
  cpu_pop_de();
  a = e;
  set_hl(0x5EC1);
  p27_L_5EA2();
  mem_write8(0x8129, a);
  a = b;
  set_hl(0x8124);
  /* sub (hl) */
  a = (uint8_t)(a + 1);
  mem_write8(0x8126, a);
  p00_lcd_cmd_07();
  a = mem_read8(0x8127);
  b = a;
  a = mem_read8(0x8125);
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 4)));
  cpu_push_bc();
  cpu_push_af();
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p27_L_642E();
  cpu_ex_de_hl();
  a = mem_read8(0x8124);
  a = a & 0x1F;
  flag_logic(a);
  l = a;
  h = 0x00;
  set_hl((uint16_t)(hl() + de()));
  p27_L_65B5();
  return;
  lab_p27_L_6C61: ;
  set_hl(mem_read16(0x86D7));
  a = (uint8_t)(a + l);
  a = (uint8_t)(a - 1);
  e = a;
  a = h;
  a = (uint8_t)(a + b);
  d = a;
  a = mem_read8(0x8135);
  flag_cmp(a, 0xFE);
  if (flag_c()) goto lab_p27_L_6C75;
  if (flag_nz()) goto lab_p27_L_6C82;
  goto lab_p27_L_6C7C;
  lab_p27_L_6C75: ;
  a = d;
  a = (uint8_t)(a + 1);
  flag_cmp(a, 0x41);
  if (flag_z()) goto lab_p27_L_6C7C;
  d = a;
  lab_p27_L_6C7C: ;
  a = l;
  a = (uint8_t)(a - 0x01);
  if (flag_c()) goto lab_p27_L_6C82;
  l = a;
  lab_p27_L_6C82: ;
  cpu_pop_af();
  a = (uint8_t)(a - 0x02);
  if (flag_c()) goto lab_p27_L_655E;
  if (flag_z()) { p27_L_6556(); return; }
  p27_L_655A();
  return;
}

/* flash page 27 cpu 0x6D1A (offset 0x2D1A) */
void p27_L_6D1A(void) {
  a = mem_read8(0x8137);
  mem_write8(0x9B72, a);
  mem_write8((uint16_t)(iy + 0x32), (uint8_t)(mem_read8((uint16_t)(iy + 0x32)) | (1u << 7)));
  p00_L_3D3B();
  mem_write8((uint16_t)(iy + 0x32), (uint8_t)(mem_read8((uint16_t)(iy + 0x32)) & ~(1u << 7)));
  return;
}

/* flash page 27 cpu 0x6D37 (offset 0x2D37) */
void p27_L_6D37(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x2B)) & (1u << 1)) == 0);
  if (flag_z()) return;
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  set_hl(0x2B53);
  set_de(0x815A);
  p00_L_118F();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  /* call 0x815A - RAM/other */
  return;
}

/* flash page 27 cpu 0x6D46 (offset 0x2D46) */
void p27_L_6D46(void) {
  /* adc a,a */
  set_de(0xE1D1);
  cpu_pop_bc();
  /* call 0x815A - RAM/other */
  return;
}

/* flash page 27 cpu 0x6D58 (offset 0x2D58) */
void p27_L_6D58(void) {
  set_hl(0x6D75);
  p00_rst20();
  p00_L_19ED();
  if (flag_c()) return;
  p00_L_1F55();
  if (flag_nz()) return;
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_de(0x8000);
  while (bc() != 0) { cpu_ldi(); }
  os_banked_call(0x8000);
  return;
}

/* flash page 27 cpu 0x6D70 (offset 0x2D70) */
void p27_L_6D70(void) {
  goto lab_p27_L_6D70;
  lab_p27_L_6D5B: ;
  p00_rst20();
  p00_L_19ED();
  if (flag_c()) return;
  p00_L_1F55();
  if (flag_nz()) return;
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_de(0x8000);
  while (bc() != 0) { cpu_ldi(); }
  os_banked_call(0x8000);
  return;
  lab_p27_L_6D70: ;
  set_hl(0x6D7E);
  goto lab_p27_L_6D5B;
}

/* flash page 27 cpu 0x6D88 (offset 0x2D88) */
void p27_L_6D88(void) {
  set_hl(0x00A2);
  p00_L_21C3();
  p27_L_6F45();
  p00_rst20();
  set_de(0x0009);
  set_hl((uint16_t)(hl() + de()));
  p00_L_11F8();
  cpu_push_hl();
  p00_rst30();
  cpu_pop_de();
  p00_L_11FD();
  p27_L_6F4A();
  cpu_push_hl();
  p00_L_1183();
  p00_L_11FD();
  cpu_pop_hl();
  p00_L_1183();
  cpu_push_de();
  p27_L_6F45();
  p00_rst20();
  set_de(0x0009);
  set_hl((uint16_t)(hl() + de()));
  p00_L_11F8();
  p00_L_0C2D();
  cpu_pop_de();
  p00_L_11FD();
  p27_L_6F4A();
  cpu_push_hl();
  p00_L_1183();
  p00_L_11FD();
  cpu_pop_hl();
  p00_L_1183();
  p27_L_6F45();
  p00_L_1183();
  cpu_push_de();
  p00_rst20();
  p00_L_11F8();
  p00_rst30();
  cpu_pop_de();
  p00_L_11FD();
  p27_L_6F45();
  cpu_push_hl();
  p00_L_1183();
  p00_L_11FD();
  cpu_pop_hl();
  p00_L_1183();
  cpu_push_de();
  p00_rst20();
  p00_L_11F8();
  p00_L_0C2D();
  cpu_pop_de();
  p00_L_11FD();
  p27_L_6F45();
  p00_L_1183();
  p00_L_11FD();
  set_hl(0x6F52);
  a = 0x07;
  lab_p27_L_6E06: ;
  cpu_push_af();
  p00_rst20();
  cpu_push_hl();
  set_bc(0xFF55);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_L_11F8();
  p00_L_0D1F();
  p00_L_235C();
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p00_L_0D1F();
  p00_L_233D();
  p27_L_6F45();
  p00_L_11F8();
  cpu_push_hl();
  p00_rst30();
  p00_L_10DD();
  cpu_pop_hl();
  p00_L_11F8();
  p00_L_2315();
  p00_rst30();
  p00_rst08();
  p00_L_1135();
  set_bc(0xFF5E);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p27_L_6F14();
  cpu_push_hl();
  p27_L_6F4A();
  p00_rst20();
  p00_L_2310();
  p00_L_0C2D();
  p00_rst08();
  set_bc(0xFF5E);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_rst20();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_push_hl();
  p00_L_22F7();
  p27_L_6F45();
  p00_rst20();
  p00_L_0C2D();
  set_bc(0xFF67);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_L_11F8();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_push_hl();
  set_bc(0xFF79);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_L_11F8();
  p00_rst20();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_push_hl();
  p00_L_2315();
  p27_L_6F45();
  p00_L_11F8();
  p00_rst30();
  p00_L_10DD();
  p27_L_6F4A();
  p00_L_11F8();
  p00_L_22FC();
  p00_rst30();
  p00_rst08();
  p00_L_1135();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_push_hl();
  p27_L_6F45();
  p00_rst20();
  p00_L_2310();
  p00_L_0C2D();
  set_bc(0xFFAF);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_L_11F8();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_push_hl();
  p00_L_22F7();
  p27_L_6F4A();
  p00_rst20();
  p00_L_0C2D();
  p00_rst08();
  set_bc(0xFFA6);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_rst20();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_push_hl();
  set_bc(0xFFB8);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_rst20();
  set_bc(0xFFD3);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_L_11F8();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_pop_hl();
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p27_L_6E06;
  p00_L_21A4();
  set_bc(0xFFA6);
  p27_L_6F2F();
  set_bc(0xFF94);
  p27_L_6F2F();
  set_bc(0xFFB8);
  p27_L_6F2F();
  set_bc(0xFFA6);
  p27_L_6F2F();
  set_de(0x0063);
  p00_L_21B6();
  return;
}

/* flash page 27 cpu 0x6E24 (offset 0x2E24) */
void p27_L_6E24(void) {
  goto lab_p27_L_6E24;
  lab_p27_L_6E06: ;
  cpu_push_af();
  p00_rst20();
  cpu_push_hl();
  set_bc(0xFF55);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_L_11F8();
  p00_L_0D1F();
  p00_L_235C();
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p00_L_0D1F();
  p00_L_233D();
  p27_L_6F45();
  lab_p27_L_6E24: ;
  l = a;
  p00_L_11F8();
  cpu_push_hl();
  p00_rst30();
  p00_L_10DD();
  cpu_pop_hl();
  p00_L_11F8();
  p00_L_2315();
  p00_rst30();
  p00_rst08();
  p00_L_1135();
  set_bc(0xFF5E);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p27_L_6F14();
  cpu_push_hl();
  p27_L_6F4A();
  p00_rst20();
  p00_L_2310();
  p00_L_0C2D();
  p00_rst08();
  set_bc(0xFF5E);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_rst20();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_push_hl();
  p00_L_22F7();
  p27_L_6F45();
  p00_rst20();
  p00_L_0C2D();
  set_bc(0xFF67);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_L_11F8();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_push_hl();
  set_bc(0xFF79);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_L_11F8();
  p00_rst20();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_push_hl();
  p00_L_2315();
  p27_L_6F45();
  p00_L_11F8();
  p00_rst30();
  p00_L_10DD();
  p27_L_6F4A();
  p00_L_11F8();
  p00_L_22FC();
  p00_rst30();
  p00_rst08();
  p00_L_1135();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_push_hl();
  p27_L_6F45();
  p00_rst20();
  p00_L_2310();
  p00_L_0C2D();
  set_bc(0xFFAF);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_L_11F8();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_push_hl();
  p00_L_22F7();
  p27_L_6F4A();
  p00_rst20();
  p00_L_0C2D();
  p00_rst08();
  set_bc(0xFFA6);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_rst20();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_push_hl();
  set_bc(0xFFB8);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_rst20();
  set_bc(0xFFD3);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  p00_L_11F8();
  cpu_pop_hl();
  p27_L_6F14();
  cpu_pop_hl();
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p27_L_6E06;
  p00_L_21A4();
  set_bc(0xFFA6);
  p27_L_6F2F();
  set_bc(0xFF94);
  p27_L_6F2F();
  set_bc(0xFFB8);
  p27_L_6F2F();
  set_bc(0xFFA6);
  p27_L_6F2F();
  set_de(0x0063);
  p00_L_21B6();
  return;
}

/* flash page 27 cpu 0x6F14 (offset 0x2F14) */
void p27_L_6F14(void) {
  cpu_push_hl();
  set_de(0x848E);
  p00_L_1183();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1183();
  cpu_pop_de();
  p00_L_11FD();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_1183();
  cpu_push_de();
  p00_L_356D();
  cpu_pop_hl();
  return;
}

/* flash page 27 cpu 0x6F2F (offset 0x2F2F) */
void p27_L_6F2F(void) {
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  set_de(0x848E);
  p00_L_1183();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1183();
  p00_L_2148();
  p00_L_356D();
  return;
}

/* flash page 27 cpu 0x6F45 (offset 0x2F45) */
void p27_L_6F45(void) {
  set_bc(0xFF43);
  goto lab_p27_L_6F4D;
  lab_p27_L_6F4D: ;
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  return;
}

/* flash page 27 cpu 0x6F4A (offset 0x2F4A) */
void p27_L_6F4A(void) {
  set_bc(0xFF4C);
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  return;
}

/* flash page 27 cpu 0x6F6A (offset 0x2F6A) */
void p27_L_6F6A(void) {
  goto lab_p27_L_6F6A;
  lab_p27_L_6F0A: ;
  p27_L_6F2F();
  set_de(0x0063);
  p00_L_21B6();
  return;
  lab_p27_L_6F6A: ;
  cpu_ex_af();
  cpu_rla();
  halt();
  /* nop */
  a = a;
  a = 0;
  flag_logic(a);
  a = (uint8_t)(a + c);
  b = a;
  h = b;
  cpu_rlca();
  sp = (uint16_t)(sp + 1);
  a = (uint8_t)(a + c);
  /* nop */
  a = a;
  if (flag_nc()) goto lab_p27_L_6F0A;
  d = 0x99;
  b = e;
  mem_write8(hl(), h);
  a = (uint8_t)(a - l);
  /* nop */
  a = a;
  a = (uint8_t)(a - l);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_6FDA;
  d = c;
  h = d;
  a = (uint8_t)(a - l);
  d = (uint8_t)(d - 1);
  /* nop */
  a = a;
  b = b;
  h = a;
  mem_write8(hl(), 0x64);
  if (flag_nc()) goto lab_p27_L_7005;
  a = (uint8_t)(a + b);
  /* nop */
  a = a;
  a = (uint8_t)(a - c);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  b = l;
  b = l;
  halt();
  b = d;
  h = b;
  /* nop */
  a = a;
  d = b;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  a = a;
  lab_p27_L_6FA5: ;
  /* add a,(hl) */
  h = b;
  h = (uint8_t)(h - 1);
  b = b;
  /* scf */
  a = (uint8_t)(a + h);
  b = h;
  /* nop */
  a = a;
  e = b;
  mem_write8(hl(), a);
  a = (uint8_t)(a + l);
  h = (uint8_t)(h - 1);
  mem_write16(0x4792, hl());
  /* nop */
  a = a;
  a = (uint8_t)(a + b);
  a = (uint8_t)(a - b);
  d = 0x99;
  b = e;
  mem_write8(hl(), h);
  a = (uint8_t)(a - l);
  /* nop */
  a = a;
  h = mem_read8(hl());
  a = (uint8_t)(a - c);
  if (flag_nc()) goto lab_p27_L_7024;
  h = e;
  e = b;
  /* add a,(hl) */
  /* nop */
  a = a;
  mem_write8(hl(), h);
  sp = 0x8244;
  d = h;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + sp));
  p27_L_6FD0();
  return;
  lab_p27_L_6FDA: ;
  goto lab_p27_L_6FA5;
  lab_p27_L_6FF2: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_7005;
  p00_L_18E5();
  set_hl(mem_read16(0x8160));
  set_de(mem_read16(0x812C));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x812C, hl());
  a = a | 0x01;
  flag_logic(a);
  return;
  lab_p27_L_7005: ;
  set_de(0x000A);
  set_hl((uint16_t)(hl() + de()));
  p00_L_190B();
  flag_cmp(a, 0xFC);
  if (flag_nz()) goto lab_p27_L_7013;
  set_hl((uint16_t)(hl() + 1));
  goto lab_p27_L_6FF2;
  lab_p27_L_7013: ;
  flag_cmp(a, 0xFE);
  if (flag_c()) goto lab_p27_L_702B;
  set_hl((uint16_t)(hl() + 1));
  if (flag_z()) goto lab_p27_L_702B;
  p00_L_190B();
  flag_cmp(a, 0x01);
  set_hl((uint16_t)(hl() + 1));
  p00_L_190B();
  if (flag_z()) goto lab_p27_L_7027;
  lab_p27_L_7024: ;
  mem_write8(bc(), a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + 1);
  lab_p27_L_7027: ;
  a = (uint8_t)(a + 0x02);
  goto lab_p27_L_702F;
  lab_p27_L_702B: ;
  p00_L_190B();
  a = (uint8_t)(a + 1);
  lab_p27_L_702F: ;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  goto lab_p27_L_6FF2;
}

/* flash page 27 cpu 0x6FD0 (offset 0x2FD0) */
void p27_L_6FD0(void) {
  b = a;
  set_hl(mem_read16(0x8157));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  lab_p27_L_6FD6: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_6FDC;
  p00_L_18E5();
  return;
  lab_p27_L_6FDC: ;
  p00_L_18F4();
  goto lab_p27_L_6FD6;
}

/* flash page 27 cpu 0x6FE1 (offset 0x2FE1) */
void p27_L_6FE1(void) {
  b = a;
  cpu_push_bc();
  set_hl(mem_read16(0x8157));
  set_hl((uint16_t)(hl() + 1));
  p00_L_190B();
  b = a;
  set_hl((uint16_t)(hl() + 1));
  lab_p27_L_6FEC: ;
  p00_L_18F4();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_6FEC;
  cpu_pop_bc();
  lab_p27_L_6FF2: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_7005;
  p00_L_18E5();
  set_hl(mem_read16(0x8160));
  set_de(mem_read16(0x812C));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x812C, hl());
  a = a | 0x01;
  flag_logic(a);
  return;
  lab_p27_L_7005: ;
  set_de(0x000A);
  set_hl((uint16_t)(hl() + de()));
  p00_L_190B();
  flag_cmp(a, 0xFC);
  if (flag_nz()) goto lab_p27_L_7013;
  set_hl((uint16_t)(hl() + 1));
  goto lab_p27_L_6FF2;
  lab_p27_L_7013: ;
  flag_cmp(a, 0xFE);
  if (flag_c()) goto lab_p27_L_702B;
  set_hl((uint16_t)(hl() + 1));
  if (flag_z()) goto lab_p27_L_702B;
  p00_L_190B();
  flag_cmp(a, 0x01);
  set_hl((uint16_t)(hl() + 1));
  p00_L_190B();
  if (flag_z()) goto lab_p27_L_7027;
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + 1);
  lab_p27_L_7027: ;
  a = (uint8_t)(a + 0x02);
  goto lab_p27_L_702F;
  lab_p27_L_702B: ;
  p00_L_190B();
  a = (uint8_t)(a + 1);
  lab_p27_L_702F: ;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  goto lab_p27_L_6FF2;
}

/* flash page 27 cpu 0x703B (offset 0x303B) */
void p27_L_703B(void) {
  set_hl(0x25A1);
  mem_write16(0x8595, hl());
  return;
}

/* flash page 27 cpu 0x704E (offset 0x304E) */
void p27_L_704E(void) {
  a = mem_read8(0x8478);
  flag_cmp(a, 0x24);
  if (flag_z()) goto lab_p27_L_705D;
  p00_L_17BB();
  if (flag_z()) goto lab_p27_L_7088;
  p00_L_24DD();
  return;
  lab_p27_L_705D: ;
  p00_L_2E77();
  if (flag_c()) { p00_L_24F1(); return; }
  set_de(0x84BF);
  set_hl(0x849A);
  set_bc(0x0008);
  while (bc() != 0) { cpu_ldi(); }
  sp = mem_read16(0x85BC);
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  a = 0x40;
  mem_write8(0x859A, a);
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 5)));
  a = 0x58;
  p00_L_05C2();
  return;
  lab_p27_L_7088: ;
  p00_L_240E();
  set_hl(0x8000);
  mem_write16(0x86D9, hl());
  if (flag_c()) goto lab_p27_L_70B3;
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_70B3;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0xBB);
  if (flag_nz()) goto lab_p27_L_70B3;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0x6D);
  if (flag_z()) goto lab_p27_L_70AB;
  flag_cmp(a, 0x6C);
  if (flag_nz()) goto lab_p27_L_70B3;
  lab_p27_L_70AB: ;
  a = 0xBB;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  a = 0x6A;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  lab_p27_L_70B3: ;
  set_hl(0x8499);
  a = 0x5F;
  mem_write8(hl(), a);
  p00_L_25D8();
  a = 0x3F;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) | (1u << 2)));
  mem_write16(0x86DB, de());
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  p00_L_165F();
  p00_L_19E7();
  if (flag_nc()) p00_L_1F58();
  set_hl(0x0000);
  mem_write16(0x96F2, hl());
  p00_L_1CBF();
  p00_L_3E8B();
  p00_L_3D2F();
  p00_L_3D65();
  a = 0x40;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) | (1u << 6)));
  p00_L_05F2();
  return;
}

/* flash page 27 cpu 0x70FF (offset 0x30FF) */
void p27_L_70FF(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x29)) & (1u << 0)) == 0);
  mem_write8((uint16_t)(iy + 0x29), (uint8_t)(mem_read8((uint16_t)(iy + 0x29)) & ~(1u << 0)));
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 0)));
  a = mem_read8(0x843E);
  cpu_push_af();
  set_hl(0x4000);
  p00_L_2C97();
  os_bcall(0x80A8);
  if (flag_nz()) goto lab_p27_L_714B;
  cpu_pop_af();
  cpu_push_af();
  p00_L_2C9D();
  if (flag_c()) goto lab_p27_L_7124;
  if (flag_z()) goto lab_p27_L_714B;
  lab_p27_L_7124: ;
  cpu_pop_af();
  cpu_push_af();
  p00_L_24A9();
  if (flag_nz()) goto lab_p27_L_712D;
  a = (uint8_t)(a - 0x54);
  lab_p27_L_712D: ;
  a = (uint8_t)(a - 0x15);
  /* neg */
  b = 0x00;
  c = a;
  cpu_push_bc();
  ix = cpu_pop16();
  p00_L_2CA3();
  if (flag_c()) goto lab_p27_L_714B;
  if (flag_nz()) goto lab_p27_L_714B;
  p00_L_0AFB();
  if (flag_z()) goto lab_p27_L_714B;
  cpu_pop_af();
  cpu_push_af();
  p00_L_2CA9();
  p00_L_2E65();
  lab_p27_L_714B: ;
  cpu_pop_af();
  p27_L_51E6();
  set_hl(0x7198);
  set_de(0x858D);
  set_bc(0x000C);
  while (bc() != 0) { cpu_ldi(); }
  p27_L_715A();
  return;
}

/* flash page 27 cpu 0x7100 (offset 0x3100) */
void p27_L_7100(void) {
  /* sra c */
  b = mem_read8(hl());
  mem_write8((uint16_t)(iy + 0x29), (uint8_t)(mem_read8((uint16_t)(iy + 0x29)) & ~(1u << 0)));
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 0)));
  a = mem_read8(0x843E);
  cpu_push_af();
  set_hl(0x4000);
  p00_L_2C97();
  os_bcall(0x80A8);
  if (flag_nz()) goto lab_p27_L_714B;
  cpu_pop_af();
  cpu_push_af();
  p00_L_2C9D();
  if (flag_c()) goto lab_p27_L_7124;
  if (flag_z()) goto lab_p27_L_714B;
  lab_p27_L_7124: ;
  cpu_pop_af();
  cpu_push_af();
  p00_L_24A9();
  if (flag_nz()) goto lab_p27_L_712D;
  a = (uint8_t)(a - 0x54);
  lab_p27_L_712D: ;
  a = (uint8_t)(a - 0x15);
  /* neg */
  b = 0x00;
  c = a;
  cpu_push_bc();
  ix = cpu_pop16();
  p00_L_2CA3();
  if (flag_c()) goto lab_p27_L_714B;
  if (flag_nz()) goto lab_p27_L_714B;
  p00_L_0AFB();
  if (flag_z()) goto lab_p27_L_714B;
  cpu_pop_af();
  cpu_push_af();
  p00_L_2CA9();
  p00_L_2E65();
  lab_p27_L_714B: ;
  cpu_pop_af();
  p27_L_51E6();
  set_hl(0x7198);
  set_de(0x858D);
  set_bc(0x000C);
  while (bc() != 0) { cpu_ldi(); }
  p27_L_715A();
  return;
}

/* flash page 27 cpu 0x715A (offset 0x315A) */
void p27_L_715A(void) {
  mem_write8((uint16_t)(iy + 0x3C), (uint8_t)(mem_read8((uint16_t)(iy + 0x3C)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 4)));
  /* ld (iy+0x05),0x00 */
  a = mem_read8((uint16_t)(iy + 0x37));
  a = a ^ 0xFF;
  set_hl(0x8A24);
  /* and (hl) */
  mem_write8(hl(), a);
  a = mem_read8((uint16_t)(iy + 0x38));
  a = a ^ 0xFF;
  set_hl(0x8A25);
  /* and (hl) */
  mem_write8(hl(), a);
  a = mem_read8((uint16_t)(iy + 0x39));
  a = a ^ 0xFF;
  set_hl(0x8A26);
  /* and (hl) */
  mem_write8(hl(), a);
  a = 0;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x28), a);
  mem_write8((uint16_t)(iy + 0x29), a);
  mem_write8((uint16_t)(iy + 0x2A), a);
  mem_write8((uint16_t)(iy + 0x2B), a);
  mem_write8((uint16_t)(iy + 0x37), a);
  mem_write8((uint16_t)(iy + 0x38), a);
  mem_write8((uint16_t)(iy + 0x39), a);
  return;
}

/* flash page 27 cpu 0x71A5 (offset 0x31A5) */
void p27_ascii_map_2(void) {
  a = a & h;
  flag_logic(a);
  mem_write8(hl(), c);
  a = a & h;
  flag_logic(a);
  mem_write8(hl(), c);
  p00_rst38_isr();
  mem_write8(hl(), b);
  a = a & h;
  flag_logic(a);
  mem_write8(hl(), c);
  a = a & h;
  flag_logic(a);
  mem_write8(hl(), c);
  a = a & h;
  flag_logic(a);
  mem_write8(hl(), c);
  a = mem_read8(bc());
  p27_ascii_map_3();
  return;
}

/* flash page 27 cpu 0x71B2 (offset 0x31B2) */
void p27_ascii_map_3(void) {
  /* sbc a,a */
  h = (uint8_t)(h - 1);
  p27_ascii_map_4();
  return;
}

/* flash page 27 cpu 0x71B4 (offset 0x31B4) */
void p27_ascii_map_4(void) {
  goto lab_p27_ascii_map_4;
  lab_p27_L_7174: ;
  h = (uint8_t)(h - 1);
  /* adc a,d */
  /* and (hl) */
  mem_write8(hl(), a);
  a = mem_read8((uint16_t)(iy + 0x39));
  a = a ^ 0xFF;
  set_hl(0x8A26);
  /* and (hl) */
  mem_write8(hl(), a);
  a = 0;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x28), a);
  mem_write8((uint16_t)(iy + 0x29), a);
  mem_write8((uint16_t)(iy + 0x2A), a);
  mem_write8((uint16_t)(iy + 0x2B), a);
  mem_write8((uint16_t)(iy + 0x37), a);
  mem_write8((uint16_t)(iy + 0x38), a);
  mem_write8((uint16_t)(iy + 0x39), a);
  return;
  lab_p27_L_71A4: ;
  return;
  lab_p27_ascii_map_4: ;
  set_bc(0x0100);
  lab_p27_L_71B7: ;
  set_bc(0x0100);
  set_bc(0x0100);
  /* nop */
  /* nop */
  /* nop */
  if (flag_p()) return;
  if (flag_po()) return;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_71A4;
  if (flag_nz()) return;
  if (flag_nz()) goto lab_p27_L_71B7;
  a = a & b;
  flag_logic(a);
  d = b;
  flag_cmp(a, b);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_7174;
  cpu_rra();
  c = 0x11;
  e = 0x0C;
  mem_write8(de(), a);
  cpu_rra();
  a = mem_read8(bc());
  d = (uint8_t)(d - 1);
  set_bc((uint16_t)(bc() - 1));
  set_bc(0x000A);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  a = (uint8_t)(a + b);
  /* nop */
  a = (uint8_t)(a + b);
  p27_L_71E4();
  return;
}

/* flash page 27 cpu 0x71E4 (offset 0x31E4) */
void p27_L_71E4(void) {
  p00_L_3EFD();
  p00_L_3F09();
  set_hl(0x301F);
  mem_write16(0x986D, hl());
  set_hl(0x71B2);
  set_de(0x8100);
  set_bc(0x001A);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 27 cpu 0x71FC (offset 0x31FC) */
void p27_L_71FC(void) {
  cpu_ex_de_hl();
  a = mem_read8(hl());
  a = (uint8_t)(a + a);
  mem_write8(hl(), a);
  p27_L_7200();
  return;
}

/* flash page 27 cpu 0x7200 (offset 0x3200) */
void p27_L_7200(void) {
  cpu_ex_de_hl();
  /* rl (hl) */
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) { p27_L_71FC(); return; }
  return;
}

/* flash page 27 cpu 0x7208 (offset 0x3208) */
void p27_L_7208(void) {
  a = mem_read8(0x986D);
  flag_cmp(a, 0x3D);
  if (flag_nc()) goto lab_p27_L_7221;
  c = 0x00;
  d = 0x03;
  set_hl(0x811A);
  p27_lcd_write_data_2();
  c = 0x01;
  set_hl(0x811E);
  p27_lcd_write_data_2();
  lab_p27_L_7221: ;
  set_hl(0x8120);
  set_de(0x8121);
  set_bc(0x0007);
  /* lddr */
  c = 0x00;
  set_hl(0x811A);
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 3)) == 0);
  if (flag_z()) p27_L_72B4();
  c = 0x01;
  set_hl(0x811E);
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 4)) == 0);
  if (flag_z()) p27_L_72B4();
  return;
}

/* flash page 27 cpu 0x7245 (offset 0x3245) */
void p27_L_7245(void) {
  c = 0x00;
  d = 0x00;
  a = mem_read8(0x811A);
  p27_L_724C();
  return;
}

/* flash page 27 cpu 0x724C (offset 0x324C) */
void p27_L_724C(void) {
  p27_lcd_write_data();
  c = 0x01;
  a = mem_read8(0x811E);
  p27_L_7254();
  return;
}

/* flash page 27 cpu 0x7254 (offset 0x3254) */
void p27_L_7254(void) {
  p27_lcd_write_data();
  set_hl(0x811B);
  set_de(0x811A);
  p00_L_1187();
  c = 0x00;
  set_hl(0x811A);
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 3)) == 0);
  if (flag_z()) p27_L_72B1();
  c = 0x01;
  set_hl(0x811E);
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 4)) == 0);
  if (flag_z()) p27_L_72B1();
  return;
}

/* flash page 27 cpu 0x7279 (offset 0x3279) */
void p27_L_7279(void) {
  cpu_push_de();
  cpu_push_hl();
  set_hl(0x986D);
  a = 0x3F;
  /* sub (hl) */
  flag_cmp(a, 0x04);
  if (flag_c()) goto lab_p27_L_7287;
  a = 0x03;
  lab_p27_L_7287: ;
  e = a;
  d = 0x00;
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_de();
  return;
}

/* flash page 27 cpu 0x728E (offset 0x328E) */
void p27_lcd_write_data_2(void) {
  /* CURATED -> lcd_write_data */
  lcd_write_data();
}

/* flash page 27 cpu 0x7292 (offset 0x3292) */
void p27_lcd_write_data(void) {
  /* CURATED -> lcd_write_data */
  lcd_write_data();
}

/* flash page 27 cpu 0x72B1 (offset 0x32B1) */
void p27_L_72B1(void) {
  p27_L_7279();
  p27_L_72B4();
  return;
}

/* flash page 27 cpu 0x72B4 (offset 0x32B4) */
void p27_L_72B4(void) {
  a = mem_read8(0x8101);
  a = (uint8_t)(a + c);
  flag_cmp(a, 0x2C);
  if (flag_z()) return;
  p27_lcd_cmd();
  a = mem_read8(0x8100);
  a = (uint8_t)(a - 1);
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p27_L_72D0;
  a = (uint8_t)(a + 0x05);
  flag_cmp(a, 0xC0);
  if (flag_c()) goto lab_p27_L_72D0;
  a = 0xBF;
  lab_p27_L_72D0: ;
  p27_lcd_cmd();
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  mem_write8(hl(), a);
  return;
}

/* flash page 27 cpu 0x72DF (offset 0x32DF) */
void p27_L_72DF(void) {
  set_hl(0x8100);
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p27_L_72E9;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  lab_p27_L_72E9: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p27_L_72F0;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p27_L_72F0: ;
  return;
}

/* flash page 27 cpu 0x72F1 (offset 0x32F1) */
void p27_L_72F1(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p27_L_732E;
  set_hl(0x8102);
  a = mem_read8(0x8101);
  set_de(0x811A);
  p27_L_7300();
  return;
  lab_p27_L_732E: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p27_L_73A1;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p27_L_7378;
  set_hl(0x8102);
  set_de(0x810E);
  b = 0x0C;
  p27_L_71FC();
  a = mem_read8(0x986E);
  flag_cmp(a, 0x5F);
  if (flag_nz()) { p27_L_7355(); return; }
  set_hl(0x8117);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  p27_L_7355();
  return;
  lab_p27_L_7378: ;
  set_hl(0x71B4);
  set_de(0x8102);
  set_bc(0x0018);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(0x8101);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  set_hl(0x811A);
  set_de(0x811E);
  p00_L_118D();
  a = mem_read8(0x8101);
  p27_lcd_cmd();
  set_de(0x811A);
  p27_L_72DF();
  p27_L_74C0();
  p27_L_7358();
  return;
  lab_p27_L_73A1: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 1)) == 0);
  if (flag_z()) { p27_L_7355(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p27_L_73D8;
  set_hl(0x8119);
  set_de(0x810D);
  b = 0x0C;
  lab_p27_L_73B6: ;
  cpu_ex_de_hl();
  a = mem_read8(hl());
  /* srl a */
  mem_write8(hl(), a);
  cpu_ex_de_hl();
  /* rr (hl) */
  set_hl((uint16_t)(hl() - 1));
  set_de((uint16_t)(de() - 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_73B6;
  a = mem_read8(0x986E);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p27_L_7355(); return; }
  set_hl(0x8102);
  p27_L_7682();
  p27_L_7682();
  p27_L_7682();
  p27_L_7355();
  return;
  lab_p27_L_73D8: ;
  set_hl(0x71CC);
  set_de(0x8102);
  set_bc(0x0018);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(0x8101);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_de(0x811A);
  set_hl(0x811E);
  p00_L_118D();
  a = mem_read8(0x8101);
  a = (uint8_t)(a + 1);
  p27_lcd_cmd();
  set_de(0x811E);
  p27_L_72DF();
  p27_L_74C0();
  p27_L_7358();
  return;
}

/* flash page 27 cpu 0x7300 (offset 0x3300) */
void p27_L_7300(void) {
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x2D), (uint8_t)(mem_read8((uint16_t)(iy + 0x2D)) | (1u << 3)));
  p27_L_7450();
  set_hl(0x810E);
  a = mem_read8(0x8101);
  a = (uint8_t)(a + 1);
  set_de(0x811E);
  p27_L_7450();
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x2D), (uint8_t)(mem_read8((uint16_t)(iy + 0x2D)) & ~(1u << 3)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 5)) == 0);
  if (flag_nz()) p27_L_7208();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 6)) == 0);
  if (flag_nz()) p27_L_7245();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p27_L_73A1;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p27_L_7378;
  set_hl(0x8102);
  set_de(0x810E);
  b = 0x0C;
  p27_L_71FC();
  a = mem_read8(0x986E);
  flag_cmp(a, 0x5F);
  if (flag_nz()) { p27_L_7355(); return; }
  set_hl(0x8117);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  p27_L_7355();
  return;
  lab_p27_L_7378: ;
  set_hl(0x71B4);
  set_de(0x8102);
  set_bc(0x0018);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(0x8101);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  set_hl(0x811A);
  set_de(0x811E);
  p00_L_118D();
  a = mem_read8(0x8101);
  p27_lcd_cmd();
  set_de(0x811A);
  p27_L_72DF();
  p27_L_74C0();
  p27_L_7358();
  return;
  lab_p27_L_73A1: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 1)) == 0);
  if (flag_z()) { p27_L_7355(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p27_L_73D8;
  set_hl(0x8119);
  set_de(0x810D);
  b = 0x0C;
  lab_p27_L_73B6: ;
  cpu_ex_de_hl();
  a = mem_read8(hl());
  /* srl a */
  mem_write8(hl(), a);
  cpu_ex_de_hl();
  /* rr (hl) */
  set_hl((uint16_t)(hl() - 1));
  set_de((uint16_t)(de() - 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_73B6;
  a = mem_read8(0x986E);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p27_L_7355(); return; }
  set_hl(0x8102);
  p27_L_7682();
  p27_L_7682();
  p27_L_7682();
  p27_L_7355();
  return;
  lab_p27_L_73D8: ;
  set_hl(0x71CC);
  set_de(0x8102);
  set_bc(0x0018);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(0x8101);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_de(0x811A);
  set_hl(0x811E);
  p00_L_118D();
  a = mem_read8(0x8101);
  a = (uint8_t)(a + 1);
  p27_lcd_cmd();
  set_de(0x811E);
  p27_L_72DF();
  p27_L_74C0();
  p27_L_7358();
  return;
}

/* flash page 27 cpu 0x7355 (offset 0x3355) */
void p27_L_7355(void) {
  p27_L_72DF();
  p27_L_7358();
  return;
}

/* flash page 27 cpu 0x7358 (offset 0x3358) */
void p27_L_7358(void) {
  set_hl(mem_read16(0x8122));
  mem_write16(0x986D, hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p27_L_7368;
  mem_write8((uint16_t)(iy + 0x2D), (uint8_t)(mem_read8((uint16_t)(iy + 0x2D)) | (1u << 2)));
  lab_p27_L_7368: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 4)) == 0);
  if (flag_z()) p27_L_740D();
  /* ld (iy+0x2C),0x00 */
  /* ld (iy+0x2D),0x00 */
  return;
}

/* flash page 27 cpu 0x7402 (offset 0x3402) */
void p27_L_7402(void) {
  mem_write8(hl(), e);
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 2)));
  goto lab_p27_L_7415;
  lab_p27_L_7415: ;
  p00_lcd_cmd_05();
  set_hl(0x8102);
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p27_L_742C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p27_L_7435;
  a = mem_read8(0x810E);
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_z()) goto lab_p27_L_7435;
  lab_p27_L_742C: ;
  a = mem_read8(0x8101);
  set_de(0x811A);
  p27_L_7450();
  lab_p27_L_7435: ;
  a = mem_read8(0x8117);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p27_L_7446;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 2)) == 0);
  if (flag_z()) return;
  a = mem_read8(0x810B);
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) return;
  lab_p27_L_7446: ;
  set_hl(0x810E);
  a = mem_read8(0x8101);
  a = (uint8_t)(a + 1);
  set_de(0x811E);
  p27_L_7450();
  return;
}

/* flash page 27 cpu 0x740D (offset 0x340D) */
void p27_L_740D(void) {
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) & ~(1u << 2)));
  p00_lcd_cmd_05();
  set_hl(0x8102);
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p27_L_742C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p27_L_7435;
  a = mem_read8(0x810E);
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_z()) goto lab_p27_L_7435;
  lab_p27_L_742C: ;
  a = mem_read8(0x8101);
  set_de(0x811A);
  p27_L_7450();
  lab_p27_L_7435: ;
  a = mem_read8(0x8117);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p27_L_7446;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 2)) == 0);
  if (flag_z()) return;
  a = mem_read8(0x810B);
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) return;
  lab_p27_L_7446: ;
  set_hl(0x810E);
  a = mem_read8(0x8101);
  a = (uint8_t)(a + 1);
  set_de(0x811E);
  p27_L_7450();
  return;
}

/* flash page 27 cpu 0x7450 (offset 0x3450) */
void p27_L_7450(void) {
  p27_lcd_cmd();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p27_L_7470;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p27_L_746B;
  cpu_push_de();
  set_de(0x8452);
  p27_L_74C0();
  set_de(0x8452);
  goto lab_p27_L_7470;
  lab_p27_L_746B: ;
  cpu_push_de();
  p27_L_74C0();
  cpu_pop_de();
  lab_p27_L_7470: ;
  p27_L_74AC();
  lab_p27_L_7473: ;
  a = mem_read8(de());
  c = mem_read8(hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p27_L_7492;
  a = a | c;
  flag_logic(a);
  a = a ^ c;
  flag_logic(a);
  /* ex (sp),hl */
  /* or (hl) */
  flag_set_z((mem_read8((uint16_t)(iy + 0x2D)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p27_L_748C;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  /* ex (sp),hl */
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  goto lab_p27_L_749F;
  lab_p27_L_748C: ;
  set_hl((uint16_t)(hl() + 1));
  /* ex (sp),hl */
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  goto lab_p27_L_749A;
  lab_p27_L_7492: ;
  /* and (hl) */
  c = a;
  a = mem_read8(de());
  set_hl((uint16_t)(hl() + 1));
  /* or (hl) */
  set_hl((uint16_t)(hl() + 1));
  /* or (hl) */
  /* xor (hl) */
  lab_p27_L_749A: ;
  p00_lcd_busy_wait();
  lcd_write_data(); /* ti_lcd_op_write(a) */
  lab_p27_L_749F: ;
  a = c;
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_7473;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 2)) == 0);
  if (flag_z()) return;
  cpu_pop_hl();
  return;
}

/* flash page 27 cpu 0x74AC (offset 0x34AC) */
void p27_L_74AC(void) {
  a = mem_read8(0x8100);
  p27_lcd_cmd();
  flag_cmp(a, 0xBD);
  if (flag_c()) goto lab_p27_L_74BD;
  /* neg */
  a = (uint8_t)(a + 0xC0);
  b = a;
  goto lab_p27_L_74BF;
  lab_p27_L_74BD: ;
  b = 0x04;
  lab_p27_L_74BF: ;
  return;
}

/* flash page 27 cpu 0x74C0 (offset 0x34C0) */
void p27_L_74C0(void) {
  p27_L_74AC();
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  lab_p27_L_74C8: ;
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_74C8;
  return;
}

/* flash page 27 cpu 0x74DA (offset 0x34DA) */
void p27_lcd_cmd(void) {
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  return;
}

/* flash page 27 cpu 0x751A (offset 0x351A) */
void p27_L_751A(void) {
  cpu_push_af();
  cpu_push_hl();
  p27_L_7547();
  mem_write8((uint16_t)(iy + 0x2D), (uint8_t)(mem_read8((uint16_t)(iy + 0x2D)) | (1u << 4)));
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 7)));
  p27_L_72F1();
  cpu_pop_hl();
  cpu_pop_bc();
  return;
}

/* flash page 27 cpu 0x7533 (offset 0x3533) */
void p27_L_7533(void) {
  lab_p27_L_7533: ;
  a = 0x01;
  mem_write8(0x0032, a);
  mem_write8(0x000A, a);
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 0)));
  /* ei */
  halt();
  p00_L_038C();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_7533;
  p27_L_7547();
  return;
}

/* flash page 27 cpu 0x7534 (offset 0x3534) */
void p27_L_7534(void) {
  set_bc(0x3232);
  /* nop */
  mem_write8(0x000A, a);
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 0)));
  /* ei */
  halt();
  p00_L_038C();
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p27_L_7533(); return; }
  p27_L_7547();
  return;
}

/* flash page 27 cpu 0x753C (offset 0x353C) */
void p27_L_753C(void) {
  /* sra h */
  a = (uint8_t)(a + 0xFB);
  halt();
  p00_L_038C();
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p27_L_7533(); return; }
  p27_L_7547();
  return;
}

/* flash page 27 cpu 0x7547 (offset 0x3547) */
void p27_L_7547(void) {
  /* di */
  set_hl(mem_read16(0x986D));
  mem_write16(0x8122, hl());
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) & ~(1u << 0)));
  flag_cmp(a, 0x0A);
  if (flag_c()) goto lab_p27_L_7568;
  flag_cmp(a, 0xF3);
  if (flag_nc()) goto lab_p27_L_7568;
  flag_cmp(a, 0x36);
  if (flag_nz()) { p27_L_7533(); return; }
  a = mem_read8((uint16_t)(iy + 0x12));
  a = a ^ 0x00;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x12), a);
  p27_L_7533();
  return;
  lab_p27_L_7568: ;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p27_L_7574;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 3)));
  a = 0x0C;
  /* ei */
  return;
  lab_p27_L_7574: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p27_L_7597;
  lab_p27_L_7578: ;
  a = mem_read8(0x986D);
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p27_L_7533(); return; }
  a = (uint8_t)(a - 1);
  mem_write8(0x8122, a);
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 5)));
  p27_L_7586();
  return;
  lab_p27_L_7597: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p27_L_75AC;
  lab_p27_L_759B: ;
  a = mem_read8(0x986D);
  flag_cmp(a, 0x3F);
  if (flag_z()) { p27_L_7533(); return; }
  a = (uint8_t)(a + 1);
  mem_write8(0x8122, a);
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 6)));
  p27_L_7586();
  return;
  lab_p27_L_75AC: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p27_L_75DA;
  lab_p27_L_75B0: ;
  p27_L_75B7();
  if (flag_nz()) return;
  p27_L_7533();
  return;
  lab_p27_L_75DA: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p27_L_7607;
  lab_p27_L_75DE: ;
  p27_L_75E5();
  if (flag_nz()) return;
  p27_L_75E2();
  return;
  lab_p27_L_7607: ;
  flag_cmp(a, 0xF5);
  if (flag_nz()) goto lab_p27_L_7625;
  a = mem_read8(0x986D);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_75DE;
  p27_L_75E5();
  if (flag_z()) goto lab_p27_L_7578;
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 5)));
  a = mem_read8(0x986D);
  a = (uint8_t)(a - 1);
  mem_write8(0x8122, a);
  lab_p27_L_7622: ;
  p27_L_7586();
  return;
  lab_p27_L_7625: ;
  flag_cmp(a, 0xF3);
  if (flag_nz()) goto lab_p27_L_7643;
  a = mem_read8(0x986D);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_75B0;
  p27_L_75B7();
  if (flag_z()) goto lab_p27_L_7578;
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 5)));
  a = mem_read8(0x986D);
  a = (uint8_t)(a - 1);
  mem_write8(0x8122, a);
  goto lab_p27_L_7622;
  lab_p27_L_7643: ;
  flag_cmp(a, 0xFA);
  if (flag_nz()) goto lab_p27_L_7662;
  a = mem_read8(0x986D);
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p27_L_75B0;
  p27_L_75B7();
  if (flag_z()) goto lab_p27_L_759B;
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 6)));
  a = mem_read8(0x986D);
  a = (uint8_t)(a + 1);
  mem_write8(0x8122, a);
  goto lab_p27_L_7622;
  lab_p27_L_7662: ;
  flag_cmp(a, 0xFC);
  if (flag_nz()) { p27_L_7533(); return; }
  a = mem_read8(0x986D);
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p27_L_75DE;
  p27_L_75E5();
  if (flag_z()) goto lab_p27_L_759B;
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 6)));
  a = mem_read8(0x986D);
  a = (uint8_t)(a + 1);
  mem_write8(0x8122, a);
  goto lab_p27_L_7622;
}

/* flash page 27 cpu 0x7586 (offset 0x3586) */
void p27_L_7586(void) {
  a = 0x0A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p27_L_7593;
  set_hl(mem_read16(0x8122));
  a = a | a;
  flag_logic(a);
  return;
  lab_p27_L_7593: ;
  a = 0x08;
  /* ei */
  return;
}

/* flash page 27 cpu 0x75B7 (offset 0x35B7) */
void p27_L_75B7(void) {
  a = mem_read8(0x986E);
  flag_cmp(a, 0x5F);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x2D), (uint8_t)(mem_read8((uint16_t)(iy + 0x2D)) | (1u << 1)));
  a = (uint8_t)(a + 1);
  mem_write8(0x8123, a);
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) & ~(1u << 3)));
  set_hl(0x8119);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p27_L_75D8;
  flag_cmp(a, 0x5F);
  if (flag_z()) goto lab_p27_L_75D8;
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 3)));
  lab_p27_L_75D8: ;
  p27_L_7586();
  return;
}

/* flash page 27 cpu 0x75D7 (offset 0x35D7) */
void p27_L_75D7(void) {
  goto lab_p27_L_75D7;
  lab_p27_L_7578: ;
  a = mem_read8(0x986D);
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p27_L_7533(); return; }
  a = (uint8_t)(a - 1);
  mem_write8(0x8122, a);
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 5)));
  p27_L_7586();
  return;
  lab_p27_L_759B: ;
  a = mem_read8(0x986D);
  flag_cmp(a, 0x3F);
  if (flag_z()) { p27_L_7533(); return; }
  a = (uint8_t)(a + 1);
  mem_write8(0x8122, a);
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 6)));
  p27_L_7586();
  return;
  lab_p27_L_75B0: ;
  p27_L_75B7();
  if (flag_nz()) return;
  p27_L_7533();
  return;
  lab_p27_L_75D7: ;
  /* sbc a,0x18 */
  a = a ^ h;
  flag_logic(a);
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p27_L_7607;
  lab_p27_L_75DE: ;
  p27_L_75E5();
  if (flag_nz()) return;
  p27_L_75E2();
  return;
  lab_p27_L_7607: ;
  flag_cmp(a, 0xF5);
  if (flag_nz()) goto lab_p27_L_7625;
  a = mem_read8(0x986D);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_75DE;
  p27_L_75E5();
  if (flag_z()) goto lab_p27_L_7578;
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 5)));
  a = mem_read8(0x986D);
  a = (uint8_t)(a - 1);
  mem_write8(0x8122, a);
  lab_p27_L_7622: ;
  p27_L_7586();
  return;
  lab_p27_L_7625: ;
  flag_cmp(a, 0xF3);
  if (flag_nz()) goto lab_p27_L_7643;
  a = mem_read8(0x986D);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_75B0;
  p27_L_75B7();
  if (flag_z()) goto lab_p27_L_7578;
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 5)));
  a = mem_read8(0x986D);
  a = (uint8_t)(a - 1);
  mem_write8(0x8122, a);
  goto lab_p27_L_7622;
  lab_p27_L_7643: ;
  flag_cmp(a, 0xFA);
  if (flag_nz()) goto lab_p27_L_7662;
  a = mem_read8(0x986D);
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p27_L_75B0;
  p27_L_75B7();
  if (flag_z()) goto lab_p27_L_759B;
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 6)));
  a = mem_read8(0x986D);
  a = (uint8_t)(a + 1);
  mem_write8(0x8122, a);
  goto lab_p27_L_7622;
  lab_p27_L_7662: ;
  flag_cmp(a, 0xFC);
  if (flag_nz()) { p27_L_7533(); return; }
  a = mem_read8(0x986D);
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p27_L_75DE;
  p27_L_75E5();
  if (flag_z()) goto lab_p27_L_759B;
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 6)));
  a = mem_read8(0x986D);
  a = (uint8_t)(a + 1);
  mem_write8(0x8122, a);
  goto lab_p27_L_7622;
}

/* flash page 27 cpu 0x75E2 (offset 0x35E2) */
void p27_L_75E2(void) {
  p27_L_7533();
  return;
}

/* flash page 27 cpu 0x75E5 (offset 0x35E5) */
void p27_L_75E5(void) {
  a = mem_read8(0x986E);
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x2D), (uint8_t)(mem_read8((uint16_t)(iy + 0x2D)) | (1u << 0)));
  a = (uint8_t)(a - 1);
  mem_write8(0x8123, a);
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) & ~(1u << 4)));
  set_hl(0x8102);
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p27_L_7604;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_7604;
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 4)));
  lab_p27_L_7604: ;
  p27_L_7586();
  return;
}

/* flash page 27 cpu 0x75ED (offset 0x35ED) */
void p27_L_75ED(void) {
  a = (uint8_t)(a + 0x3D);
  mem_write8(0x8123, a);
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) & ~(1u << 4)));
  set_hl(0x8102);
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p27_L_7604;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p27_L_7604;
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 4)));
  lab_p27_L_7604: ;
  p27_L_7586();
  return;
}

/* flash page 27 cpu 0x75FF (offset 0x35FF) */
void p27_L_75FF(void) {
  b = (uint8_t)(b + 1);
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) | (1u << 4)));
  p27_L_7586();
  return;
}

/* flash page 27 cpu 0x7682 (offset 0x3682) */
void p27_L_7682(void) {
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  set_hl((uint16_t)(hl() + 1));
  return;
}

/* flash page 27 cpu 0x769A (offset 0x369A) */
void p27_L_769A(void) {
  p00_L_2CAF();
  cpu_push_hl();
  set_hl(0x71A5);
  p00_L_07C1();
  p27_L_703B();
  p27_L_715A();
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) | (1u << 4)));
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) | (1u << 6)));
  cpu_pop_hl();
  mem_write16(0x843C, hl());
  mem_write8((uint16_t)(iy + 0x2C), (uint8_t)(mem_read8((uint16_t)(iy + 0x2C)) & ~(1u << 0)));
  /* ld (iy+0x37),0x00 */
  /* ld (iy+0x38),0x00 */
  goto lab_p27_L_76C7;
  lab_p27_L_76C7: ;
  set_hl(0x843C);
  cpu_push_hl();
  p00_L_2B3C();
  return;
}

/* flash page 27 cpu 0x76EA (offset 0x36EA) */
void p27_L_76EA(void) {
  cpu_push_bc();
  cpu_push_de();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p27_L_7701;
  mem_write8(0x9B77, a);
  cpu_ex_de_hl();
  p00_L_18D8();
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x9B75, hl());
  p27_L_7700();
  return;
  lab_p27_L_7701: ;
  cpu_pop_de();
  cpu_pop_bc();
  flag_cmp(a, 0x83);
  return;
}

/* flash page 27 cpu 0x7700 (offset 0x3700) */
void p27_L_7700(void) {
  a = b;
  cpu_pop_de();
  cpu_pop_bc();
  flag_cmp(a, 0x83);
  return;
}

/* flash page 27 cpu 0x7706 (offset 0x3706) */
void p27_L_7706(void) {
  cpu_push_af();
  set_hl(0x9B7C);
  p27_L_76EA();
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  a = b;
  p27_L_7713();
  return;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
}

/* flash page 27 cpu 0x7713 (offset 0x3713) */
void p27_L_7713(void) {
  mem_write8((uint16_t)(iy + 0x34), (uint8_t)(mem_read8((uint16_t)(iy + 0x34)) & ~(1u << 7)));
  return;
}

/* flash page 27 cpu 0x7718 (offset 0x3718) */
void p27_L_7718(void) {
  cpu_push_af();
  cpu_push_hl();
  set_hl(0x9BC4);
  p27_L_76EA();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x34), (uint8_t)(mem_read8((uint16_t)(iy + 0x34)) & ~(1u << 6)));
  return;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
}

/* flash page 27 cpu 0x7729 (offset 0x3729) */
void p27_L_7729(void) {
  cpu_push_af();
  set_hl(0x9B78);
  p27_L_76EA();
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 4)));
  return;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
}

/* flash page 27 cpu 0x7738 (offset 0x3738) */
void p27_L_7738(void) {
  cpu_push_af();
  set_hl(0x9B88);
  p27_L_76EA();
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  a = b;
  mem_write8((uint16_t)(iy + 0x34), (uint8_t)(mem_read8((uint16_t)(iy + 0x34)) & ~(1u << 0)));
  return;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
}

/* flash page 27 cpu 0x7759 (offset 0x3759) */
void p27_L_7759(void) {
  cpu_push_af();
  set_hl(0x9B84);
  p27_L_76EA();
  if (flag_nz()) goto lab_p27_L_77B0;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77B0: ;
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x34), (uint8_t)(mem_read8((uint16_t)(iy + 0x34)) & ~(1u << 5)));
  return;
}

/* flash page 27 cpu 0x77B6 (offset 0x37B6) */
void p27_L_77B6(void) {
  goto lab_p27_L_77B6;
  lab_p27_L_7763: ;
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77B6: ;
  cpu_push_hl();
  set_hl(0x9BC8);
  p27_L_76EA();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_7763;
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 0)));
  return;
}

/* flash page 27 cpu 0x77C5 (offset 0x37C5) */
void p27_L_77C5(void) {
  goto lab_p27_L_77C5;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77C5: ;
  cpu_push_af();
  cpu_push_hl();
  set_hl(0x9BCC);
  p27_L_76EA();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
}

/* flash page 27 cpu 0x77E0 (offset 0x37E0) */
void p27_L_77E0(void) {
  goto lab_p27_L_77E0;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_77E0: ;
  cpu_push_af();
  set_hl(0x9B8C);
  p27_L_76EA();
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x34), (uint8_t)(mem_read8((uint16_t)(iy + 0x34)) & ~(1u << 4)));
  return;
}

/* flash page 27 cpu 0x77F0 (offset 0x37F0) */
void p27_L_77F0(void) {
  goto lab_p27_L_77F0;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_77F0: ;
  cpu_push_af();
  cpu_push_hl();
  set_hl(0x9B90);
  p27_L_76EA();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 2)));
  return;
}

/* flash page 27 cpu 0x7802 (offset 0x3802) */
void p27_L_7802(void) {
  goto lab_p27_L_7802;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7802: ;
  cpu_push_af();
  set_hl(0x9B94);
  p27_L_76EA();
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
}

/* flash page 27 cpu 0x7812 (offset 0x3812) */
void p27_L_7812(void) {
  cpu_push_af();
  cpu_push_hl();
  set_hl(0x9B98);
  p27_L_7817();
  return;
}

/* flash page 27 cpu 0x7817 (offset 0x3817) */
void p27_L_7817(void) {
  goto lab_p27_L_7817;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7809: ;
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
  lab_p27_L_7817: ;
  p27_L_76EA();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_7809;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 4)));
  return;
}

/* flash page 27 cpu 0x7824 (offset 0x3824) */
void p27_L_7824(void) {
  goto lab_p27_L_7824;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7809: ;
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
  lab_p27_L_7824: ;
  cpu_push_af();
  cpu_push_hl();
  set_hl(0x9B9C);
  p27_L_76EA();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_7809;
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 5)));
  return;
}

/* flash page 27 cpu 0x7835 (offset 0x3835) */
void p27_L_7835(void) {
  goto lab_p27_L_7835;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7809: ;
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
  lab_p27_L_7835: ;
  cpu_push_af();
  set_hl(0x9BA8);
  p27_L_76EA();
  if (flag_z()) goto lab_p27_L_7809;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) & ~(1u << 0)));
  return;
}

/* flash page 27 cpu 0x7845 (offset 0x3845) */
void p27_L_7845(void) {
  goto lab_p27_L_7845;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7809: ;
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
  lab_p27_L_7845: ;
  cpu_push_af();
  cpu_push_hl();
  set_hl(0x9BA0);
  p27_L_76EA();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_7809;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 6)));
  return;
}

/* flash page 27 cpu 0x7857 (offset 0x3857) */
void p27_L_7857(void) {
  goto lab_p27_L_7857;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7809: ;
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
  lab_p27_L_7857: ;
  cpu_push_af();
  cpu_push_hl();
  set_hl(0x9BAC);
  p27_L_76EA();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_7809;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) & ~(1u << 1)));
  return;
}

/* flash page 27 cpu 0x785D (offset 0x385D) */
void p27_L_785D(void) {
  goto lab_p27_L_785D;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7809: ;
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
  lab_p27_L_785D: ;
  /* jp pe,0xE176 - other page/RAM */
  if (flag_z()) goto lab_p27_L_7809;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) & ~(1u << 1)));
  return;
}

/* flash page 27 cpu 0x7866 (offset 0x3866) */
void p27_L_7866(void) {
  mem_write8(hl(), 0x8E);
  return;
}

/* flash page 27 cpu 0x7869 (offset 0x3869) */
void p27_L_7869(void) {
  cpu_push_af();
  cpu_push_hl();
  set_hl(0x9BB0);
  p27_L_76EA();
  p27_L_7871();
  return;
}

/* flash page 27 cpu 0x7871 (offset 0x3871) */
void p27_L_7871(void) {
  cpu_pop_hl();
  p27_L_7872();
  return;
}

/* flash page 27 cpu 0x7872 (offset 0x3872) */
void p27_L_7872(void) {
  goto lab_p27_L_7872;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7809: ;
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
  lab_p27_L_7872: ;
  if (flag_z()) goto lab_p27_L_7809;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) & ~(1u << 2)));
  return;
}

/* flash page 27 cpu 0x787B (offset 0x387B) */
void p27_L_787B(void) {
  goto lab_p27_L_787B;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7809: ;
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
  lab_p27_L_787B: ;
  cpu_push_af();
  cpu_push_hl();
  set_hl(0x9BA4);
  p27_L_76EA();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_7809;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 7)));
  return;
}

/* flash page 27 cpu 0x788D (offset 0x388D) */
void p27_L_788D(void) {
  goto lab_p27_L_788D;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7809: ;
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
  lab_p27_L_7884: ;
  if (flag_z()) goto lab_p27_L_7809;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 7)));
  return;
  lab_p27_L_788D: ;
  cpu_push_af();
  cpu_push_hl();
  set_hl(0x9BB4);
  p27_L_76EA();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_7884;
  cpu_pop_af();
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p27_L_78A0;
  a = a | a;
  flag_logic(a);
  goto lab_p27_L_78A1;
  lab_p27_L_78A0: ;
  flag_cmp(a, a);
  lab_p27_L_78A1: ;
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) & ~(1u << 3)));
  return;
}

/* flash page 27 cpu 0x78A6 (offset 0x38A6) */
void p27_L_78A6(void) {
  goto lab_p27_L_78A6;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7809: ;
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
  lab_p27_L_7884: ;
  if (flag_z()) goto lab_p27_L_7809;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 7)));
  return;
  lab_p27_L_78A6: ;
  cpu_push_af();
  cpu_push_hl();
  set_hl(0x9BB8);
  p27_L_76EA();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_7884;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) & ~(1u << 4)));
  return;
}

/* flash page 27 cpu 0x78B8 (offset 0x38B8) */
void p27_L_78B8(void) {
  goto lab_p27_L_78B8;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7809: ;
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
  lab_p27_L_7884: ;
  if (flag_z()) goto lab_p27_L_7809;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 7)));
  return;
  lab_p27_L_78B8: ;
  cpu_push_af();
  set_hl(0x9BBC);
  p27_L_76EA();
  if (flag_z()) goto lab_p27_L_7884;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) & ~(1u << 5)));
  return;
}

/* flash page 27 cpu 0x78C8 (offset 0x38C8) */
void p27_L_78C8(void) {
  goto lab_p27_L_78C8;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7809: ;
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
  lab_p27_L_7884: ;
  if (flag_z()) goto lab_p27_L_7809;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 7)));
  return;
  lab_p27_L_78C8: ;
  cpu_push_af();
  cpu_push_hl();
  set_hl(0x9BC0);
  p27_L_76EA();
  cpu_pop_hl();
  if (flag_z()) goto lab_p27_L_7884;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) & ~(1u << 6)));
  return;
}

/* flash page 27 cpu 0x78DA (offset 0x38DA) */
void p27_L_78DA(void) {
  goto lab_p27_L_78DA;
  lab_p27_L_7762: ;
  cpu_pop_af();
  mem_write8(0x9C22, a);
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x9C22);
  cpu_push_hl();
  set_hl(0x9CAE);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0BBD);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x778B);
  /* ex (sp),hl */
  cpu_push_hl();
  set_hl(0x9B75);
  /* ex (sp),hl */
  p00_L_2B07();
  return;
  lab_p27_L_77CE: ;
  if (flag_z()) goto lab_p27_L_7762;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  cpu_push_hl();
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 1)));
  return;
  lab_p27_L_7809: ;
  if (flag_z()) goto lab_p27_L_77CE;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 3)));
  return;
  lab_p27_L_7884: ;
  if (flag_z()) goto lab_p27_L_7809;
  cpu_pop_af();
  flag_cmp(a, a);
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) & ~(1u << 7)));
  return;
  lab_p27_L_78DA: ;
  cpu_push_af();
  set_hl(0x9BD0);
  p27_L_76EA();
  if (flag_z()) goto lab_p27_L_7884;
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) & ~(1u << 7)));
  return;
}

/* flash page 27 cpu 0x7915 (offset 0x3915) */
void p27_L_7915(void) {
  mem_write16(0x9B7C, hl());
  mem_write8(0x9B7E, a);
  mem_write8((uint16_t)(iy + 0x34), (uint8_t)(mem_read8((uint16_t)(iy + 0x34)) | (1u << 7)));
  return;
}

/* flash page 27 cpu 0x7920 (offset 0x3920) */
void p27_L_7920(void) {
  mem_write16(0x9B84, hl());
  mem_write8(0x9B86, a);
  mem_write8((uint16_t)(iy + 0x34), (uint8_t)(mem_read8((uint16_t)(iy + 0x34)) | (1u << 5)));
  return;
}

/* flash page 27 cpu 0x795B (offset 0x395B) */
void p27_L_795B(void) {
  /* sub (hl) */
  /* sbc a,e */
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) | (1u << 3)));
  return;
}

/* flash page 27 cpu 0x7972 (offset 0x3972) */
void p27_L_7972(void) {
  /* sbc a,e */
  mem_write8((uint16_t)(iy + 0x35), (uint8_t)(mem_read8((uint16_t)(iy + 0x35)) | (1u << 5)));
  return;
}

/* flash page 27 cpu 0x79E6 (offset 0x39E6) */
void p27_L_79E6(void) {
  set_hl(0x9B7A);
  b = 0x17;
  set_de(0x0003);
  lab_p27_L_79EE: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + de()));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_79EE;
  return;
}

/* flash page 27 cpu 0x79F5 (offset 0x39F5) */
void p27_L_79F5(void) {
  cpu_push_af();
  a = (uint8_t)(a - c);
  a = (uint8_t)(a + 1);
  d = a;
  cpu_pop_af();
  set_hl(0x9B7B);
  b = 0x17;
  lab_p27_L_79FF: ;
  cpu_push_af();
  cpu_cp_hl();
  if (flag_z()) goto lab_p27_L_7A19;
  if (flag_nc()) goto lab_p27_L_7A0D;
  lab_p27_L_7A05: ;
  cpu_pop_af();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p27_L_79FF;
  return;
  lab_p27_L_7A0D: ;
  a = mem_read8(hl());
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p27_L_7A05;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p27_L_7A05;
  flag_cmp(a, d);
  if (flag_c()) goto lab_p27_L_7A21;
  lab_p27_L_7A19: ;
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), 0xFF);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0xFF);
  goto lab_p27_L_7A05;
  lab_p27_L_7A21: ;
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  a = (uint8_t)(a + c);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  goto lab_p27_L_7A05;
}

/* flash page 27 cpu 0x7B00 (offset 0x3B00) */
void p27_L_7B00(void) {
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
  p27_L_7B57();
  return;
}

/* flash page 27 cpu 0x7B57 (offset 0x3B57) */
void p27_L_7B57(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p27_L_7B5A();
  return;
}

/* flash page 27 cpu 0x7B5A (offset 0x3B5A) */
void p27_L_7B5A(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p27_L_7B5C();
  return;
}

/* flash page 27 cpu 0x7B5C (offset 0x3B5C) */
void p27_L_7B5C(void) {
  p00_rst38_isr();
  p27_L_7B5D();
  return;
}

/* flash page 27 cpu 0x7B5D (offset 0x3B5D) */
void p27_L_7B5D(void) {
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
  p27_L_7B69();
  return;
}

/* flash page 27 cpu 0x7B69 (offset 0x3B69) */
void p27_L_7B69(void) {
  p00_rst38_isr();
  p27_L_7B6A();
  return;
}

/* flash page 27 cpu 0x7B6A (offset 0x3B6A) */
void p27_L_7B6A(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p27_L_7B70();
  return;
}

/* flash page 27 cpu 0x7B70 (offset 0x3B70) */
void p27_L_7B70(void) {
  p00_rst38_isr();
  p27_L_7B71();
  return;
}

/* flash page 27 cpu 0x7B71 (offset 0x3B71) */
void p27_L_7B71(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p27_L_7B78();
  return;
}

/* flash page 27 cpu 0x7B78 (offset 0x3B78) */
void p27_L_7B78(void) {
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
  p27_L_7C43();
  return;
}

/* flash page 27 cpu 0x7C43 (offset 0x3C43) */
void p27_L_7C43(void) {
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
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p27_L_7E00();
  return;
}

/* flash page 27 cpu 0x7E00 (offset 0x3E00) */
void p27_L_7E00(void) {
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
  p27_ascii_map();
  return;
}

/* flash page 27 cpu 0x7F00 (offset 0x3F00) */
void p27_ascii_map(void) {
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
  p27_L_7FF1();
  return;
}

/* flash page 27 cpu 0x7FF1 (offset 0x3FF1) */
void p27_L_7FF1(void) {
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


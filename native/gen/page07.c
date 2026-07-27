/* Recovered from flash page 7 (mechanical ASM->C) */
/* cpu window 0x4000..0x7FFF prefix=p07_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p07_L_4000(void);
void p07_L_406D(void);
void p07_L_40BB(void);
void p07_L_40D5(void);
void p07_L_40E3(void);
void p07_L_4100(void);
void p07_L_41BB(void);
void p07_L_4241(void);
void p07_L_42BB(void);
void p07_L_42ED(void);
void p07_L_43BB(void);
void p07_L_43FC(void);
void p07_L_4443(void);
void p07_L_4474(void);
void p07_L_4494(void);
void p07_L_44BB(void);
void p07_L_44CF(void);
void p07_L_44FC(void);
void p07_L_451E(void);
void p07_L_4548(void);
void p07_L_4579(void);
void p07_L_45BB(void);
void p07_L_4645(void);
void p07_L_46BB(void);
void p07_L_47BB(void);
void p07_L_4847(void);
void p07_L_48BB(void);
void p07_L_49BB(void);
void p07_L_49FF(void);
void p07_L_4A49(void);
void p07_L_4ABB(void);
void p07_L_4BBB(void);
void p07_L_4C4B(void);
void p07_L_4CBB(void);
void p07_L_4D7C(void);
void p07_L_4DB8(void);
void p07_L_4DBB(void);
void p07_L_4DFB(void);
void p07_L_4E4D(void);
void p07_L_4E52(void);
void p07_L_4EBB(void);
void p07_L_4ED2(void);
void p07_L_4EEA(void);
void p07_L_4EEF(void);
void p07_L_4EF6(void);
void p07_L_4EF9(void);
void p07_L_4F07(void);
void p07_L_4F16(void);
void p07_L_4F2F(void);
void p07_L_4F32(void);
void p07_L_4F6B(void);
void p07_L_4F7E(void);
void p07_L_4FBA(void);
void p07_L_4FBB(void);
void p07_L_4FDD(void);
void p07_L_4FE2(void);
void p07_L_5027(void);
void p07_L_504B(void);
void p07_L_504F(void);
void p07_L_505F(void);
void p07_L_5092(void);
void p07_L_50BB(void);
void p07_L_50EC(void);
void p07_L_50F3(void);
void p07_L_5119(void);
void p07_L_5128(void);
void p07_L_512B(void);
void p07_L_5171(void);
void p07_L_51BB(void);
void p07_L_522C(void);
void p07_L_5231(void);
void p07_L_5251(void);
void p07_L_52BB(void);
void p07_L_52DA(void);
void p07_L_534B(void);
void p07_L_53BB(void);
void p07_L_53C8(void);
void p07_L_53E4(void);
void p07_L_5453(void);
void p07_L_545B(void);
void p07_L_546C(void);
void p07_L_5491(void);
void p07_L_54A5(void);
void p07_L_54AB(void);
void p07_L_54BA(void);
void p07_L_54BB(void);
void p07_L_54BD(void);
void p07_L_54D2(void);
void p07_L_54DE(void);
void p07_L_5595(void);
void p07_L_55C6(void);
void p07_L_55FF(void);
void p07_L_5646(void);
void p07_L_5655(void);
void p07_L_56B1(void);
void p07_L_570C(void);
void p07_L_5760(void);
void p07_L_5769(void);
void p07_L_576F(void);
void p07_L_5786(void);
void p07_L_578B(void);
void p07_L_57AA(void);
void p07_L_57BB(void);
void p07_L_5845(void);
void p07_L_5857(void);
void p07_L_5865(void);
void p07_L_586D(void);
void p07_L_5886(void);
void p07_L_589E(void);
void p07_L_598E(void);
void p07_L_5998(void);
void p07_L_59B5(void);
void p07_L_59BB(void);
void p07_L_59CD(void);
void p07_L_59FE(void);
void p07_L_5A3B(void);
void p07_L_5A51(void);
void p07_L_5A59(void);
void p07_L_5ABB(void);
void p07_L_5AD8(void);
void p07_L_5ADE(void);
void p07_L_5BD7(void);
void p07_L_5BDB(void);
void p07_L_5C80(void);
void p07_L_5C8A(void);
void p07_L_5D13(void);
void p07_L_5D16(void);
void p07_L_5D21(void);
void p07_L_5D40(void);
void p07_str_1(void);
void p07_L_5D4E(void);
void p07_L_5D95(void);
void p07_L_5DE5(void);
void p07_L_5DE7(void);
void p07_L_5E04(void);
void p07_L_5E0D(void);
void p07_L_5E2F(void);
void p07_L_5E53(void);
void p07_L_5F74(void);
void p07_L_5FA1(void);
void p07_L_5FA4(void);
void p07_L_5FAA(void);
void p07_L_6005(void);
void p07_L_601E(void);
void p07_L_604D(void);
void p07_L_6068(void);
void p07_L_6088(void);
void p07_L_60B3(void);
void p07_L_60C0(void);
void p07_L_60C3(void);
void p07_L_60CB(void);
void p07_L_60D6(void);
void p07_L_63AF(void);
void p07_L_643A(void);
void p07_L_6515(void);
void p07_L_651D(void);
void p07_L_6553(void);
void p07_L_6564(void);
void p07_L_65A1(void);
void p07_L_65BD(void);
void p07_L_65D2(void);
void p07_L_65E2(void);
void p07_L_6602(void);
void p07_L_662E(void);
void p07_L_667A(void);
void p07_L_667C(void);
void p07_L_669E(void);
void p07_L_66AA(void);
void p07_L_66B6(void);
void p07_L_66FF(void);
void p07_L_6711(void);
void p07_L_6754(void);
void p07_L_6766(void);
void p07_L_67A2(void);
void p07_L_67DC(void);
void p07_L_67FA(void);
void p07_L_688C(void);
void p07_L_6968(void);
void p07_L_6A1D(void);
void p07_L_6AB2(void);
void p07_L_6AD4(void);
void p07_L_6ADC(void);
void p07_L_6AFD(void);
void p07_L_6B6E(void);
void p07_L_6BCA(void);
void p07_L_6BD0(void);
void p07_L_6BE8(void);
void p07_L_6BF0(void);
void p07_L_6BFD(void);
void p07_L_6C0C(void);
void p07_L_6C14(void);
void p07_L_6C30(void);
void p07_L_6C40(void);
void p07_L_6C47(void);
void p07_L_6C51(void);
void p07_L_6C56(void);
void p07_L_6C6F(void);
void p07_L_6CE3(void);
void p07_L_6E8F(void);
void p07_L_6EEB(void);
void p07_L_7140(void);
void p07_L_7156(void);
void p07_L_7166(void);
void p07_L_716D(void);
void p07_L_7170(void);
void p07_L_71DB(void);
void p07_L_71F0(void);
void p07_L_72F0(void);
void p07_L_72FB(void);
void p07_L_7300(void);
void p07_L_732C(void);
void p07_L_7358(void);
void p07_L_7380(void);
void p07_L_73A6(void);
void p07_L_73B4(void);
void p07_L_73D3(void);
void p07_L_73E2(void);
void p07_L_7406(void);
void p07_L_7427(void);
void p07_L_742F(void);
void p07_L_7461(void);
void p07_L_7472(void);
void p07_L_7473(void);
void p07_L_7498(void);
void p07_L_753A(void);
void p07_L_759D(void);
void p07_L_75B8(void);
void p07_L_7641(void);
void p07_L_7658(void);
void p07_L_7675(void);
void p07_L_7683(void);
void p07_L_7685(void);
void p07_L_76C6(void);
void p07_L_76D2(void);
void p07_L_7732(void);
void p07_L_778D(void);
void p07_L_77D2(void);
void p07_L_77F6(void);
void p07_L_77FC(void);
void p07_L_77FF(void);
void p07_L_7827(void);
void p07_L_7877(void);
void p07_L_78E6(void);
void p07_L_792D(void);
void p07_L_793B(void);
void p07_L_79E2(void);
void p07_L_7A79(void);
void p07_L_7B2E(void);
void p07_L_7BA1(void);
void p07_L_7BCA(void);
void p07_L_7BD3(void);
void p07_L_7C00(void);
void p07_L_7C09(void);
void p07_L_7C0D(void);
void p07_L_7C32(void);
void p07_L_7C47(void);
void p07_L_7C65(void);
void p07_L_7C7B(void);
void p07_L_7C9A(void);
void p07_L_7CBD(void);
void p07_L_7D07(void);
void p07_L_7F05(void);
void p07_L_7FBB(void);

/* flash page 7 cpu 0x4000 (offset 0x0000) */
void p07_L_4000(void) {
  a = (uint8_t)(a + h);
  /* nop */
  /* adc a,c */
  /* adc a,d */
  /* adc a,l */
  /* adc a,b */
  /* adc a,(hl) */
  /* nop */
  /* adc a,e */
  /* add a,(hl) */
  a = (uint8_t)(a + a);
  a = (uint8_t)(a - b);
  a = (uint8_t)(a - d);
  /* adc a,h */
  /* adc a,a */
  /* nop */
  a = a & l;
  flag_logic(a);
  a = (uint8_t)(a + l);
  /* sbc a,h */
  /* nop */
  a = a & b;
  flag_logic(a);
  /* sbc a,a */
  /* sbc a,(hl) */
  /* sbc a,l */
  /* and (hl) */
  a = (uint8_t)(a - e);
  a = a & a;
  flag_logic(a);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_ex_de_hl();
  mem_write8(hl(), b);
  mem_write8(hl(), c);
  a = (uint8_t)(a + d);
  a = (uint8_t)(a + e);
  if (flag_p()) return;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_403E;
  b = 0x07;
  a = a & h;
  flag_logic(a);
  b = (uint8_t)(b + 1);
  set_hl((uint16_t)(hl() - 1));
  a = a | b;
  flag_logic(a);
  a = mem_read8(0x3130);
  mem_write8(0x3433, a);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  mem_write8(hl(), 0x37);
  if (flag_c()) goto lab_p07_L_4077;
  lab_p07_L_403E: ;
  sp = (uint16_t)(sp - 1);
  set_hl((uint16_t)(hl() + hl()));
  b = c;
  b = d;
  lab_p07_L_4042: ;
  b = e;
  b = h;
  b = l;
  b = mem_read8(hl());
  b = a;
  c = b;
  c = c;
  c = d;
  c = e;
  c = h;
  c = l;
  c = mem_read8(hl());
  c = a;
  d = b;
  d = c;
  d = d;
  d = e;
  d = h;
  d = l;
  d = mem_read8(hl());
  d = a;
  e = b;
  e = c;
  e = d;
  /* nop */
  a = a ^ h;
  flag_logic(a);
  c = (uint8_t)(c + 1);
  /* jp nz,0xC4C3 - other page/RAM */
  cpu_push_bc();
  a = (uint8_t)(a + 0xC7);
  c = (uint8_t)(c - 1);
  flag_cmp(a, h);
  cpu_cp_hl();
  flag_cmp(a, a);
  if (flag_nz()) return;
  cpu_pop_bc();
  set_bc((uint16_t)(bc() + 1));
  /* ei */
  mem_write8(hl(), d);
  a = 0x25;
  h = (uint8_t)(h + 1);
  mem_write16(0x2AAF, hl());
  e = e;
  /* adc a,0xCF */
  if (flag_nc()) return;
  hw_out(0xD1, a);
  lab_p07_L_4077: ;
  cpu_pop_de();
  /* jp nc,0xD8D4 - other page/RAM */
  a = (uint8_t)(a - 0xD7);
  /* jp c,0xE6DB - other page/RAM */
  e = a;
  cpu_push_de();
  cpu_exx();
  /* call 0xDEDD - RAM/other */
  p00_rst18();
  cpu_push_hl();
  if (flag_po()) return;
  a = a ^ l;
  flag_logic(a);
  cpu_pop_hl();
  a = (uint8_t)(a - c);
  if (flag_z()) return;
  /* jp z,0xC9CC - other page/RAM */
  l = (uint8_t)(l | (1u << 1));
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  l = (uint8_t)(l + 1);
  /* nop */
  a = a ^ 0x27;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_4042;
  a = a ^ c;
  flag_logic(a);
  a = a & c;
  flag_logic(a);
  a = a & d;
  flag_logic(a);
  set_de((uint16_t)(de() + 1));
  /* sbc a,e */
  /* sbc a,c */
  /* sbc a,d */
  /* sbc a,b */
  a = a | d;
  flag_logic(a);
  l = d;
  l = a;
  l = h;
  l = mem_read8(hl());
  l = e;
  l = l;
  b = b;
  a = (uint8_t)(a + 1);
  a = (uint8_t)(a - 1);
  flag_cmp(a, b);
  p00_rst38_isr();
  cpu_pop_af();
  cpu_rrca();
  flag_cmp(a, l);
  mem_write8(bc(), a);
  l = 0x2F;
  if (flag_pe()) p00_L_12ED();
  flag_cmp(a, c);
  flag_cmp(a, d);
  a = a | c;
  flag_logic(a);
  a = a ^ e;
  flag_logic(a);
  p07_L_40BB();
  return;
}

/* flash page 7 cpu 0x406D (offset 0x006D) */
void p07_L_406D(void) {
  goto lab_p07_L_406D;
  lab_p07_L_4042: ;
  b = e;
  b = h;
  b = l;
  b = mem_read8(hl());
  b = a;
  c = b;
  c = c;
  c = d;
  c = e;
  c = h;
  c = l;
  c = mem_read8(hl());
  c = a;
  d = b;
  d = c;
  d = d;
  d = e;
  d = h;
  d = l;
  d = mem_read8(hl());
  d = a;
  e = b;
  e = c;
  e = d;
  /* nop */
  a = a ^ h;
  flag_logic(a);
  c = (uint8_t)(c + 1);
  /* jp nz,0xC4C3 - other page/RAM */
  cpu_push_bc();
  a = (uint8_t)(a + 0xC7);
  c = (uint8_t)(c - 1);
  flag_cmp(a, h);
  cpu_cp_hl();
  flag_cmp(a, a);
  if (flag_nz()) return;
  cpu_pop_bc();
  set_bc((uint16_t)(bc() + 1));
  /* ei */
  mem_write8(hl(), d);
  a = 0x25;
  lab_p07_L_406D: ;
  h = (uint8_t)(h - 1);
  h = (uint8_t)(h + 1);
  mem_write16(0x2AAF, hl());
  e = e;
  /* adc a,0xCF */
  if (flag_nc()) return;
  hw_out(0xD1, a);
  /* jp nc,0xD8D4 - other page/RAM */
  a = (uint8_t)(a - 0xD7);
  /* jp c,0xE6DB - other page/RAM */
  e = a;
  cpu_push_de();
  cpu_exx();
  /* call 0xDEDD - RAM/other */
  p00_rst18();
  cpu_push_hl();
  if (flag_po()) return;
  a = a ^ l;
  flag_logic(a);
  cpu_pop_hl();
  a = (uint8_t)(a - c);
  if (flag_z()) return;
  /* jp z,0xC9CC - other page/RAM */
  l = (uint8_t)(l | (1u << 1));
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  l = (uint8_t)(l + 1);
  /* nop */
  a = a ^ 0x27;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_4042;
  a = a ^ c;
  flag_logic(a);
  a = a & c;
  flag_logic(a);
  a = a & d;
  flag_logic(a);
  set_de((uint16_t)(de() + 1));
  /* sbc a,e */
  /* sbc a,c */
  /* sbc a,d */
  /* sbc a,b */
  a = a | d;
  flag_logic(a);
  l = d;
  l = a;
  l = h;
  l = mem_read8(hl());
  l = e;
  l = l;
  b = b;
  a = (uint8_t)(a + 1);
  a = (uint8_t)(a - 1);
  flag_cmp(a, b);
  p00_rst38_isr();
  cpu_pop_af();
  cpu_rrca();
  flag_cmp(a, l);
  mem_write8(bc(), a);
  l = 0x2F;
  if (flag_pe()) p00_L_12ED();
  flag_cmp(a, c);
  flag_cmp(a, d);
  a = a | c;
  flag_logic(a);
  a = a ^ e;
  flag_logic(a);
  p07_L_40BB();
  return;
}

/* flash page 7 cpu 0x40BB (offset 0x00BB) */
void p07_L_40BB(void) {
  goto lab_p07_L_40BB;
  lab_p07_L_40AE: ;
  cpu_pop_af();
  cpu_rrca();
  flag_cmp(a, l);
  mem_write8(bc(), a);
  l = 0x2F;
  if (flag_pe()) p00_L_12ED();
  flag_cmp(a, c);
  flag_cmp(a, d);
  a = a | c;
  flag_logic(a);
  a = a ^ e;
  flag_logic(a);
  lab_p07_L_40BB: ;
  a = (uint8_t)(a - h);
  a = (uint8_t)(a - l);
  l = (uint8_t)(l - 1);
  a = mem_read8(bc());
  set_bc((uint16_t)(bc() - 1));
  /* xor (hl) */
  set_bc(0x1B1C);
  e = (uint8_t)(e - 1);
  e = 0x15;
  d = 0x17;
  goto lab_p07_L_40AE;
}

/* flash page 7 cpu 0x40D5 (offset 0x00D5) */
void p07_L_40D5(void) {
  a = a | l;
  flag_logic(a);
  if (flag_po()) { p00_L_20B4(); return; }
  d = (uint8_t)(d + 1);
  /* jp p,0xF4F3 - other page/RAM */
  cpu_push_af();
  a = a | 0xF7;
  flag_logic(a);
  if (flag_m()) return;
  sp = hl();
  /* jp m,0xFDFC - other page/RAM */
  flag_cmp(a, 0x64);
  h = l;
  h = mem_read8(hl());
  h = a;
  l = b;
  l = c;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  mem_write8(hl(), l);
  halt();
  mem_write8(hl(), a);
  a = b;
  a = c;
  a = d;
  a = e;
  a = h;
  a = l;
  /* sub (hl) */
  a = 0;
  flag_logic(a);
  os_jp_hl();
  return;
}

/* flash page 7 cpu 0x40E3 (offset 0x00E3) */
void p07_L_40E3(void) {
  /* call 0xFEFD - RAM/other */
  h = h;
  h = l;
  h = mem_read8(hl());
  h = a;
  l = b;
  l = c;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  mem_write8(hl(), l);
  halt();
  mem_write8(hl(), a);
  a = b;
  a = c;
  a = d;
  a = e;
  a = h;
  a = l;
  /* sub (hl) */
  a = 0;
  flag_logic(a);
  os_jp_hl();
  return;
}

/* flash page 7 cpu 0x4100 (offset 0x0100) */
void p07_L_4100(void) {
  a = (uint8_t)(a + b);
  a = (uint8_t)(a + c);
  a = mem_read8(hl());
  /* nop */
  a = mem_read8(hl());
  set_bc(0x027E);
  a = mem_read8(hl());
  set_bc((uint16_t)(bc() + 1));
  a = mem_read8(hl());
  b = (uint8_t)(b + 1);
  a = mem_read8(hl());
  b = (uint8_t)(b - 1);
  a = mem_read8(hl());
  b = 0x7E;
  cpu_rlca();
  a = mem_read8(hl());
  cpu_ex_af();
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  a = mem_read8(bc());
  a = mem_read8(hl());
  set_bc((uint16_t)(bc() - 1));
  a = mem_read8(hl());
  c = (uint8_t)(c + 1);
  a = mem_read8(hl());
  c = (uint8_t)(c - 1);
  e = l;
  /* nop */
  e = l;
  set_bc(0x025D);
  e = l;
  set_bc((uint16_t)(bc() + 1));
  e = l;
  b = (uint8_t)(b + 1);
  e = l;
  b = (uint8_t)(b - 1);
  e = h;
  /* nop */
  e = h;
  set_bc(0x025C);
  e = h;
  set_bc((uint16_t)(bc() + 1));
  e = h;
  b = (uint8_t)(b + 1);
  h = e;
  a = mem_read8(bc());
  h = e;
  set_bc((uint16_t)(bc() - 1));
  h = e;
  mem_write8(bc(), a);
  h = e;
  c = (uint8_t)(c + 1);
  h = e;
  c = (uint8_t)(c - 1);
  h = e;
  set_bc((uint16_t)(bc() + 1));
  h = e;
  c = 0x63;
  cpu_rrca();
  h = e;
  mem_write16(0x1063, hl());
  h = e;
  set_de(0x2363);
  h = e;
  b = (uint8_t)(b + 1);
  h = e;
  b = (uint8_t)(b - 1);
  h = e;
  cpu_rra();
  h = e;
  e = (uint8_t)(e - 1);
  h = e;
  /* daa */
  h = e;
  h = 0x63;
  mem_write8(de(), a);
  h = e;
  set_de((uint16_t)(de() + 1));
  h = e;
  /* nop */
  h = e;
  d = (uint8_t)(d + 1);
  h = e;
  d = (uint8_t)(d - 1);
  h = e;
  set_bc(0x1863);
  h = e;
  set_hl((uint16_t)(hl() + de()));
  h = e;
  h = (uint8_t)(h + 1);
  h = e;
  d = 0x63;
  cpu_rla();
  h = e;
  h = (uint8_t)(h - 1);
  h = e;
  cpu_ex_af();
  h = e;
  set_hl((uint16_t)(hl() + bc()));
  h = e;
  if (flag_nz()) goto lab_p07_L_41DA;
  e = 0xBB;
  d = a;
  flag_cmp(a, e);
  mem_write8(0x31BB, a);
  h = b;
  /* nop */
  h = b;
  set_bc(0x0260);
  flag_cmp(a, e);
  d = h;
  flag_cmp(a, e);
  d = e;
  flag_cmp(a, e);
  c = l;
  flag_cmp(a, e);
  c = mem_read8(hl());
  flag_cmp(a, e);
  c = a;
  a = mem_read8(hl());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_420F;
  set_de(0x127E);
  flag_cmp(a, e);
  c = e;
  flag_cmp(a, e);
  c = h;
  flag_cmp(a, e);
  b = l;
  flag_cmp(a, e);
  d = b;
  flag_cmp(a, e);
  d = c;
  h = d;
  d = 0x62;
  cpu_rla();
  h = d;
  goto lab_p07_L_4207;
  lab_p07_L_41A6: ;
  h = d;
  set_hl((uint16_t)(hl() + de()));
  h = d;
  a = mem_read8(de());
  h = d;
  set_bc(0x0862);
  h = d;
  d = (uint8_t)(d + 1);
  h = d;
  set_de((uint16_t)(de() + 1));
  h = d;
  d = (uint8_t)(d - 1);
  h = d;
  set_hl((uint16_t)(hl() + bc()));
  h = d;
  set_de((uint16_t)(de() - 1));
  h = d;
  e = 0x62;
  p07_L_41BB();
  return;
  lab_p07_L_41DA: ;
  flag_cmp(a, e);
  b = a;
  flag_cmp(a, e);
  b = c;
  flag_cmp(a, e);
  c = b;
  flag_cmp(a, e);
  c = c;
  flag_cmp(a, e);
  b = d;
  flag_cmp(a, e);
  b = e;
  flag_cmp(a, e);
  b = h;
  flag_cmp(a, e);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_41A6;
  set_de(0x12BB);
  flag_cmp(a, e);
  set_de((uint16_t)(de() + 1));
  flag_cmp(a, e);
  d = (uint8_t)(d + 1);
  flag_cmp(a, e);
  d = (uint8_t)(d - 1);
  flag_cmp(a, e);
  d = 0xBB;
  cpu_rla();
  flag_cmp(a, e);
  goto lab_p07_L_4259;
  lab_p07_L_4207: ;
  if (flag_z()) goto lab_p07_L_426C;
  set_hl((uint16_t)(hl() + hl()));
  flag_cmp(a, e);
  e = c;
  h = d;
  set_bc((uint16_t)(bc() - 1));
  a = mem_read8(hl());
  lab_p07_L_420F: ;
  c = 0x7E;
  cpu_rrca();
  h = e;
  set_hl(mem_read16(0x19BB));
  flag_cmp(a, e);
  a = mem_read8(de());
  flag_cmp(a, e);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  flag_cmp(a, e);
  mem_write8(hl(), 0xBB);
  /* scf */
  flag_cmp(a, e);
  if (flag_c()) goto lab_p07_L_4284;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  h = e;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  flag_cmp(a, e);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  flag_cmp(a, e);
  h = h;
  flag_cmp(a, e);
  e = b;
  flag_cmp(a, e);
  h = l;
  h = c;
  /* nop */
  h = c;
  set_bc(0x0261);
  e = mem_read8(hl());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4293;
  set_de(0x125E);
  e = mem_read8(hl());
  set_de((uint16_t)(de() + 1));
  e = mem_read8(hl());
  d = (uint8_t)(d + 1);
  e = mem_read8(hl());
  d = (uint8_t)(d - 1);
  e = mem_read8(hl());
  d = 0x5E;
  p07_L_4241();
  return;
  lab_p07_L_424C: ;
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  h = (uint8_t)(h + 1);
  e = mem_read8(hl());
  h = (uint8_t)(h - 1);
  e = mem_read8(hl());
  h = 0x5E;
  /* daa */
  lab_p07_L_4256: ;
  e = mem_read8(hl());
  if (flag_z()) goto lab_p07_L_42B7;
  lab_p07_L_4259: ;
  set_hl((uint16_t)(hl() + hl()));
  e = mem_read8(hl());
  set_hl(mem_read16(0x2B5E));
  e = mem_read8(hl());
  b = b;
  e = mem_read8(hl());
  b = c;
  e = mem_read8(hl());
  b = d;
  e = mem_read8(hl());
  b = e;
  e = mem_read8(hl());
  b = h;
  e = mem_read8(hl());
  b = l;
  h = c;
  set_bc((uint16_t)(bc() + 1));
  lab_p07_L_426C: ;
  h = c;
  b = (uint8_t)(b + 1);
  h = c;
  b = (uint8_t)(b - 1);
  lab_p07_L_4270: ;
  h = b;
  set_bc((uint16_t)(bc() + 1));
  h = b;
  b = (uint8_t)(b + 1);
  h = b;
  b = (uint8_t)(b - 1);
  h = c;
  b = 0x61;
  cpu_rlca();
  h = c;
  cpu_ex_af();
  h = c;
  set_hl((uint16_t)(hl() + bc()));
  h = b;
  b = 0x60;
  cpu_rlca();
  h = b;
  cpu_ex_af();
  lab_p07_L_4284: ;
  h = b;
  set_hl((uint16_t)(hl() + bc()));
  h = d;
  mem_write8(bc(), a);
  h = d;
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, e);
  h = (uint8_t)(h - 1);
  flag_cmp(a, e);
  h = 0xBB;
  if (flag_z()) goto lab_p07_L_424C;
  cpu_ex_af();
  flag_cmp(a, e);
  lab_p07_L_4293: ;
  set_hl((uint16_t)(hl() + bc()));
  flag_cmp(a, e);
  a = mem_read8(bc());
  flag_cmp(a, e);
  cpu_rra();
  flag_cmp(a, e);
  if (flag_nc()) goto lab_p07_L_4256;
  a = a ^ 0xFF;
  h = d;
  c = (uint8_t)(c + 1);
  h = d;
  b = 0x62;
  cpu_rlca();
  h = e;
  mem_write8(0x055C, a);
  e = h;
  b = 0x5C;
  cpu_rlca();
  e = h;
  cpu_ex_af();
  e = h;
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  /* nop */
  h = d;
  cpu_rrca();
  h = d;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4270;
  set_hl((uint16_t)(hl() + sp));
  flag_cmp(a, e);
  lab_p07_L_42B7: ;
  a = mem_read8(0x29BB);
  flag_cmp(a, e);
  p07_L_42BB();
  return;
}

/* flash page 7 cpu 0x41BB (offset 0x01BB) */
void p07_L_41BB(void) {
  goto lab_p07_L_41BB;
  lab_p07_L_41A6: ;
  h = d;
  set_hl((uint16_t)(hl() + de()));
  h = d;
  a = mem_read8(de());
  h = d;
  set_bc(0x0862);
  h = d;
  d = (uint8_t)(d + 1);
  h = d;
  set_de((uint16_t)(de() + 1));
  h = d;
  d = (uint8_t)(d - 1);
  h = d;
  set_hl((uint16_t)(hl() + bc()));
  h = d;
  set_de((uint16_t)(de() - 1));
  h = d;
  e = 0x62;
  lab_p07_L_41BB: ;
  e = (uint8_t)(e + 1);
  h = d;
  cpu_rra();
  h = d;
  e = (uint8_t)(e - 1);
  h = d;
  if (flag_nz()) goto lab_p07_L_4226;
  a = mem_read8(de());
  h = e;
  set_hl(0x4ABB);
  flag_cmp(a, e);
  d = d;
  flag_cmp(a, e);
  sp = (uint16_t)(sp + 1);
  flag_cmp(a, e);
  sp = (uint16_t)(sp - 1);
  flag_cmp(a, e);
  a = (uint8_t)(a + 1);
  flag_cmp(a, e);
  a = (uint8_t)(a - 1);
  flag_cmp(a, e);
  b = mem_read8(hl());
  flag_cmp(a, e);
  a = 0xBB;
  /* ccf */
  flag_cmp(a, e);
  b = b;
  flag_cmp(a, e);
  b = a;
  flag_cmp(a, e);
  b = c;
  flag_cmp(a, e);
  c = b;
  flag_cmp(a, e);
  c = c;
  flag_cmp(a, e);
  b = d;
  flag_cmp(a, e);
  b = e;
  flag_cmp(a, e);
  b = h;
  flag_cmp(a, e);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_41A6;
  set_de(0x12BB);
  flag_cmp(a, e);
  set_de((uint16_t)(de() + 1));
  flag_cmp(a, e);
  d = (uint8_t)(d + 1);
  flag_cmp(a, e);
  d = (uint8_t)(d - 1);
  flag_cmp(a, e);
  d = 0xBB;
  cpu_rla();
  flag_cmp(a, e);
  goto lab_p07_L_4259;
  lab_p07_L_4226: ;
  flag_cmp(a, e);
  h = h;
  flag_cmp(a, e);
  e = b;
  flag_cmp(a, e);
  h = l;
  h = c;
  /* nop */
  h = c;
  set_bc(0x0261);
  e = mem_read8(hl());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4293;
  set_de(0x125E);
  e = mem_read8(hl());
  set_de((uint16_t)(de() + 1));
  e = mem_read8(hl());
  d = (uint8_t)(d + 1);
  e = mem_read8(hl());
  d = (uint8_t)(d - 1);
  e = mem_read8(hl());
  d = 0x5E;
  p07_L_4241();
  return;
  lab_p07_L_424C: ;
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  h = (uint8_t)(h + 1);
  e = mem_read8(hl());
  h = (uint8_t)(h - 1);
  e = mem_read8(hl());
  h = 0x5E;
  /* daa */
  lab_p07_L_4256: ;
  e = mem_read8(hl());
  if (flag_z()) goto lab_p07_L_42B7;
  lab_p07_L_4259: ;
  set_hl((uint16_t)(hl() + hl()));
  e = mem_read8(hl());
  set_hl(mem_read16(0x2B5E));
  e = mem_read8(hl());
  b = b;
  e = mem_read8(hl());
  b = c;
  e = mem_read8(hl());
  b = d;
  e = mem_read8(hl());
  b = e;
  e = mem_read8(hl());
  b = h;
  e = mem_read8(hl());
  b = l;
  h = c;
  set_bc((uint16_t)(bc() + 1));
  h = c;
  b = (uint8_t)(b + 1);
  h = c;
  b = (uint8_t)(b - 1);
  lab_p07_L_4270: ;
  h = b;
  set_bc((uint16_t)(bc() + 1));
  h = b;
  b = (uint8_t)(b + 1);
  h = b;
  b = (uint8_t)(b - 1);
  h = c;
  b = 0x61;
  cpu_rlca();
  h = c;
  cpu_ex_af();
  h = c;
  set_hl((uint16_t)(hl() + bc()));
  h = b;
  b = 0x60;
  cpu_rlca();
  h = b;
  cpu_ex_af();
  h = b;
  set_hl((uint16_t)(hl() + bc()));
  h = d;
  mem_write8(bc(), a);
  h = d;
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, e);
  h = (uint8_t)(h - 1);
  flag_cmp(a, e);
  h = 0xBB;
  if (flag_z()) goto lab_p07_L_424C;
  cpu_ex_af();
  flag_cmp(a, e);
  lab_p07_L_4293: ;
  set_hl((uint16_t)(hl() + bc()));
  flag_cmp(a, e);
  a = mem_read8(bc());
  flag_cmp(a, e);
  cpu_rra();
  flag_cmp(a, e);
  if (flag_nc()) goto lab_p07_L_4256;
  a = a ^ 0xFF;
  h = d;
  c = (uint8_t)(c + 1);
  h = d;
  b = 0x62;
  cpu_rlca();
  h = e;
  mem_write8(0x055C, a);
  e = h;
  b = 0x5C;
  cpu_rlca();
  e = h;
  cpu_ex_af();
  e = h;
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  /* nop */
  h = d;
  cpu_rrca();
  h = d;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4270;
  set_hl((uint16_t)(hl() + sp));
  flag_cmp(a, e);
  lab_p07_L_42B7: ;
  a = mem_read8(0x29BB);
  flag_cmp(a, e);
  p07_L_42BB();
  return;
}

/* flash page 7 cpu 0x4241 (offset 0x0241) */
void p07_L_4241(void) {
  cpu_rla();
  e = mem_read8(hl());
  goto lab_p07_L_42A3;
  lab_p07_L_424C: ;
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  h = (uint8_t)(h + 1);
  e = mem_read8(hl());
  h = (uint8_t)(h - 1);
  e = mem_read8(hl());
  h = 0x5E;
  /* daa */
  lab_p07_L_4256: ;
  e = mem_read8(hl());
  if (flag_z()) goto lab_p07_L_42B7;
  set_hl((uint16_t)(hl() + hl()));
  e = mem_read8(hl());
  set_hl(mem_read16(0x2B5E));
  e = mem_read8(hl());
  b = b;
  e = mem_read8(hl());
  b = c;
  e = mem_read8(hl());
  b = d;
  e = mem_read8(hl());
  b = e;
  e = mem_read8(hl());
  b = h;
  e = mem_read8(hl());
  b = l;
  h = c;
  set_bc((uint16_t)(bc() + 1));
  h = c;
  b = (uint8_t)(b + 1);
  h = c;
  b = (uint8_t)(b - 1);
  lab_p07_L_4270: ;
  h = b;
  set_bc((uint16_t)(bc() + 1));
  h = b;
  b = (uint8_t)(b + 1);
  h = b;
  b = (uint8_t)(b - 1);
  h = c;
  b = 0x61;
  cpu_rlca();
  h = c;
  cpu_ex_af();
  h = c;
  set_hl((uint16_t)(hl() + bc()));
  h = b;
  b = 0x60;
  cpu_rlca();
  h = b;
  cpu_ex_af();
  h = b;
  set_hl((uint16_t)(hl() + bc()));
  h = d;
  mem_write8(bc(), a);
  h = d;
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, e);
  h = (uint8_t)(h - 1);
  flag_cmp(a, e);
  h = 0xBB;
  if (flag_z()) goto lab_p07_L_424C;
  cpu_ex_af();
  flag_cmp(a, e);
  set_hl((uint16_t)(hl() + bc()));
  flag_cmp(a, e);
  a = mem_read8(bc());
  flag_cmp(a, e);
  cpu_rra();
  flag_cmp(a, e);
  if (flag_nc()) goto lab_p07_L_4256;
  a = a ^ 0xFF;
  h = d;
  c = (uint8_t)(c + 1);
  h = d;
  b = 0x62;
  cpu_rlca();
  h = e;
  lab_p07_L_42A3: ;
  mem_write8(0x055C, a);
  e = h;
  b = 0x5C;
  cpu_rlca();
  e = h;
  cpu_ex_af();
  e = h;
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  /* nop */
  h = d;
  cpu_rrca();
  h = d;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4270;
  set_hl((uint16_t)(hl() + sp));
  flag_cmp(a, e);
  lab_p07_L_42B7: ;
  a = mem_read8(0x29BB);
  flag_cmp(a, e);
  p07_L_42BB();
  return;
}

/* flash page 7 cpu 0x42BB (offset 0x02BB) */
void p07_L_42BB(void) {
  l = (uint8_t)(l + 1);
  flag_cmp(a, e);
  c = (uint8_t)(c - 1);
  flag_cmp(a, e);
  c = 0xBB;
  set_hl((uint16_t)(hl() - 1));
  flag_cmp(a, e);
  d = l;
  flag_cmp(a, e);
  d = mem_read8(hl());
  flag_cmp(a, e);
  set_hl(mem_read16(0x0CBB));
  flag_cmp(a, e);
  cpu_rrca();
  a = a ^ d;
  flag_logic(a);
  /* nop */
  a = a ^ d;
  flag_logic(a);
  set_bc(0x02AA);
  a = a ^ d;
  flag_logic(a);
  set_bc((uint16_t)(bc() + 1));
  a = a ^ d;
  flag_logic(a);
  b = (uint8_t)(b + 1);
  a = a ^ d;
  flag_logic(a);
  b = (uint8_t)(b - 1);
  a = a ^ d;
  flag_logic(a);
  b = 0xAA;
  cpu_rlca();
  a = a ^ d;
  flag_logic(a);
  cpu_ex_af();
  a = a ^ d;
  flag_logic(a);
  set_hl((uint16_t)(hl() + bc()));
  h = e;
  set_hl((uint16_t)(hl() - 1));
  h = e;
  l = (uint8_t)(l + 1);
  h = e;
  l = (uint8_t)(l - 1);
  h = e;
  l = 0x63;
  a = a ^ 0xFF;
  h = e;
  if (flag_nc()) goto lab_p07_L_4350;
  p07_L_42ED();
  return;
  lab_p07_L_4350: ;
  flag_cmp(a, e);
  l = (uint8_t)(l - 1);
  flag_cmp(a, e);
  l = 0x62;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  h = d;
  mem_write8(hl(), 0xBB);
  h = mem_read8(hl());
  flag_cmp(a, e);
  h = a;
  h = e;
  b = 0x63;
  cpu_rlca();
  flag_cmp(a, e);
  l = b;
  flag_cmp(a, e);
  l = c;
  flag_cmp(a, e);
  l = d;
  flag_cmp(a, e);
  l = h;
  flag_cmp(a, e);
  l = e;
  flag_cmp(a, e);
  l = mem_read8(hl());
  flag_cmp(a, e);
  l = a;
  flag_cmp(a, e);
  mem_write8(hl(), b);
  flag_cmp(a, e);
  mem_write8(hl(), c);
  flag_cmp(a, e);
  mem_write8(hl(), d);
  flag_cmp(a, e);
  mem_write8(hl(), e);
  flag_cmp(a, e);
  mem_write8(hl(), h);
  flag_cmp(a, e);
  mem_write8(hl(), l);
  flag_cmp(a, e);
  halt();
  flag_cmp(a, e);
  mem_write8(hl(), a);
  flag_cmp(a, e);
  a = b;
  flag_cmp(a, e);
  a = c;
  flag_cmp(a, e);
  a = d;
  flag_cmp(a, e);
  a = e;
  flag_cmp(a, e);
  a = h;
  flag_cmp(a, e);
  a = l;
  flag_cmp(a, e);
  p07_L_7FBB();
  flag_cmp(a, e);
  a = (uint8_t)(a + b);
  flag_cmp(a, e);
  a = (uint8_t)(a + c);
  flag_cmp(a, e);
  a = (uint8_t)(a + d);
  flag_cmp(a, e);
  a = (uint8_t)(a + e);
  flag_cmp(a, e);
  a = (uint8_t)(a + h);
  flag_cmp(a, e);
  a = (uint8_t)(a + l);
  flag_cmp(a, e);
  /* add a,(hl) */
  flag_cmp(a, e);
  a = (uint8_t)(a + a);
  flag_cmp(a, e);
  /* adc a,b */
  flag_cmp(a, e);
  /* adc a,c */
  flag_cmp(a, e);
  /* adc a,d */
  flag_cmp(a, e);
  /* adc a,e */
  flag_cmp(a, e);
  /* adc a,h */
  flag_cmp(a, e);
  /* adc a,l */
  flag_cmp(a, e);
  /* adc a,(hl) */
  flag_cmp(a, e);
  /* adc a,a */
  flag_cmp(a, e);
  a = (uint8_t)(a - b);
  flag_cmp(a, e);
  a = (uint8_t)(a - c);
  flag_cmp(a, e);
  a = (uint8_t)(a - d);
  flag_cmp(a, e);
  a = (uint8_t)(a - e);
  flag_cmp(a, e);
  a = (uint8_t)(a - h);
  flag_cmp(a, e);
  a = (uint8_t)(a - l);
  flag_cmp(a, e);
  p07_L_43BB();
  return;
}

/* flash page 7 cpu 0x42ED (offset 0x02ED) */
void p07_L_42ED(void) {
  sp = 0x20BB;
  flag_cmp(a, e);
  set_hl(0x22BB);
  flag_cmp(a, e);
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, e);
  h = (uint8_t)(h + 1);
  flag_cmp(a, e);
  /* nop */
  flag_cmp(a, e);
  set_bc(0x02BB);
  flag_cmp(a, e);
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, e);
  b = (uint8_t)(b + 1);
  h = d;
  b = (uint8_t)(b + 1);
  h = d;
  b = (uint8_t)(b - 1);
  flag_cmp(a, e);
  b = (uint8_t)(b - 1);
  flag_cmp(a, e);
  b = 0xBB;
  cpu_rlca();
  h = d;
  mem_write16(0x2362, hl());
  h = d;
  h = (uint8_t)(h + 1);
  h = d;
  h = (uint8_t)(h - 1);
  h = d;
  h = 0x62;
  /* daa */
  h = d;
  if (flag_z()) goto lab_p07_L_437D;
  set_hl((uint16_t)(hl() + hl()));
  h = d;
  set_hl(mem_read16(0x2B62));
  h = d;
  l = 0x62;
  l = (uint8_t)(l + 1);
  h = d;
  a = a ^ 0xFF;
  h = d;
  sp = 0x2D62;
  h = d;
  if (flag_nc()) goto lab_p07_L_438F;
  mem_write8(0x3362, a);
  h = e;
  sp = (uint16_t)(sp + 1);
  flag_cmp(a, e);
  /* daa */
  h = d;
  c = (uint8_t)(c - 1);
  h = e;
  mem_write8(hl(), 0x62);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  h = d;
  c = 0x62;
  set_de(0x3763);
  flag_cmp(a, e);
  e = d;
  flag_cmp(a, e);
  e = e;
  flag_cmp(a, e);
  set_de((uint16_t)(de() - 1));
  flag_cmp(a, e);
  e = (uint8_t)(e + 1);
  flag_cmp(a, e);
  e = (uint8_t)(e - 1);
  flag_cmp(a, e);
  e = 0x62;
  a = mem_read8(bc());
  flag_cmp(a, e);
  set_bc((uint16_t)(bc() - 1));
  flag_cmp(a, e);
  l = (uint8_t)(l - 1);
  flag_cmp(a, e);
  l = 0x62;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  h = d;
  mem_write8(hl(), 0xBB);
  h = mem_read8(hl());
  flag_cmp(a, e);
  h = a;
  h = e;
  b = 0x63;
  cpu_rlca();
  flag_cmp(a, e);
  l = b;
  flag_cmp(a, e);
  l = c;
  flag_cmp(a, e);
  l = d;
  flag_cmp(a, e);
  l = h;
  flag_cmp(a, e);
  l = e;
  flag_cmp(a, e);
  l = mem_read8(hl());
  flag_cmp(a, e);
  l = a;
  flag_cmp(a, e);
  mem_write8(hl(), b);
  flag_cmp(a, e);
  mem_write8(hl(), c);
  flag_cmp(a, e);
  mem_write8(hl(), d);
  flag_cmp(a, e);
  mem_write8(hl(), e);
  flag_cmp(a, e);
  mem_write8(hl(), h);
  flag_cmp(a, e);
  mem_write8(hl(), l);
  flag_cmp(a, e);
  halt();
  flag_cmp(a, e);
  lab_p07_L_437D: ;
  mem_write8(hl(), a);
  flag_cmp(a, e);
  a = b;
  flag_cmp(a, e);
  a = c;
  flag_cmp(a, e);
  a = d;
  flag_cmp(a, e);
  a = e;
  flag_cmp(a, e);
  a = h;
  flag_cmp(a, e);
  a = l;
  flag_cmp(a, e);
  p07_L_7FBB();
  flag_cmp(a, e);
  lab_p07_L_438F: ;
  a = (uint8_t)(a + b);
  flag_cmp(a, e);
  a = (uint8_t)(a + c);
  flag_cmp(a, e);
  a = (uint8_t)(a + d);
  flag_cmp(a, e);
  a = (uint8_t)(a + e);
  flag_cmp(a, e);
  a = (uint8_t)(a + h);
  flag_cmp(a, e);
  a = (uint8_t)(a + l);
  flag_cmp(a, e);
  /* add a,(hl) */
  flag_cmp(a, e);
  a = (uint8_t)(a + a);
  flag_cmp(a, e);
  /* adc a,b */
  flag_cmp(a, e);
  /* adc a,c */
  flag_cmp(a, e);
  /* adc a,d */
  flag_cmp(a, e);
  /* adc a,e */
  flag_cmp(a, e);
  /* adc a,h */
  flag_cmp(a, e);
  /* adc a,l */
  flag_cmp(a, e);
  /* adc a,(hl) */
  flag_cmp(a, e);
  /* adc a,a */
  flag_cmp(a, e);
  a = (uint8_t)(a - b);
  flag_cmp(a, e);
  a = (uint8_t)(a - c);
  flag_cmp(a, e);
  a = (uint8_t)(a - d);
  flag_cmp(a, e);
  a = (uint8_t)(a - e);
  flag_cmp(a, e);
  a = (uint8_t)(a - h);
  flag_cmp(a, e);
  a = (uint8_t)(a - l);
  flag_cmp(a, e);
  p07_L_43BB();
  return;
}

/* flash page 7 cpu 0x43BB (offset 0x03BB) */
void p07_L_43BB(void) {
  /* sub (hl) */
  flag_cmp(a, e);
  a = 0;
  flag_logic(a);
  flag_cmp(a, e);
  /* sbc a,b */
  flag_cmp(a, e);
  /* sbc a,c */
  flag_cmp(a, e);
  /* sbc a,d */
  flag_cmp(a, e);
  /* sbc a,e */
  flag_cmp(a, e);
  /* sbc a,h */
  flag_cmp(a, e);
  /* sbc a,l */
  flag_cmp(a, e);
  /* sbc a,(hl) */
  flag_cmp(a, e);
  /* sbc a,a */
  flag_cmp(a, e);
  a = a & b;
  flag_logic(a);
  flag_cmp(a, e);
  a = a & c;
  flag_logic(a);
  flag_cmp(a, e);
  a = a & d;
  flag_logic(a);
  flag_cmp(a, e);
  a = a & e;
  flag_logic(a);
  flag_cmp(a, e);
  a = a & h;
  flag_logic(a);
  flag_cmp(a, e);
  a = a & l;
  flag_logic(a);
  flag_cmp(a, e);
  /* and (hl) */
  flag_cmp(a, e);
  a = a & a;
  flag_logic(a);
  flag_cmp(a, e);
  a = a ^ b;
  flag_logic(a);
  flag_cmp(a, e);
  a = a ^ c;
  flag_logic(a);
  flag_cmp(a, e);
  e = (uint8_t)(e & ~(1u << 7));
  /* call 0xABBB - RAM/other */
  flag_cmp(a, e);
  a = a ^ h;
  flag_logic(a);
  flag_cmp(a, e);
  a = a ^ l;
  flag_logic(a);
  flag_cmp(a, e);
  /* xor (hl) */
  flag_cmp(a, e);
  a = 0;
  flag_logic(a);
  flag_cmp(a, e);
  a = a | b;
  flag_logic(a);
  flag_cmp(a, e);
  a = a | c;
  flag_logic(a);
  flag_cmp(a, e);
  a = a | d;
  flag_logic(a);
  flag_cmp(a, e);
  a = a | e;
  flag_logic(a);
  flag_cmp(a, e);
  a = a | h;
  flag_logic(a);
  flag_cmp(a, e);
  a = a | l;
  flag_logic(a);
  p07_L_43FC();
  return;
}

/* flash page 7 cpu 0x43FC (offset 0x03FC) */
void p07_L_43FC(void) {
  flag_cmp(a, e);
  /* or (hl) */
  flag_cmp(a, e);
  a = a | a;
  flag_logic(a);
  flag_cmp(a, e);
  flag_cmp(a, b);
  flag_cmp(a, e);
  flag_cmp(a, c);
  flag_cmp(a, e);
  flag_cmp(a, d);
  flag_cmp(a, e);
  flag_cmp(a, h);
  flag_cmp(a, e);
  flag_cmp(a, l);
  flag_cmp(a, e);
  cpu_cp_hl();
  flag_cmp(a, e);
  flag_cmp(a, a);
  flag_cmp(a, e);
  if (flag_nz()) return;
  flag_cmp(a, e);
  cpu_pop_bc();
  flag_cmp(a, e);
  /* jp nz,0xC3BB - other page/RAM */
  flag_cmp(a, e);
  /* call 0xC5BB - RAM/other */
  flag_cmp(a, e);
  a = (uint8_t)(a + 0xBB);
  p00_rst00_boot();
  flag_cmp(a, e);
  if (flag_z()) return;
  flag_cmp(a, e);
  return;
}

/* flash page 7 cpu 0x4443 (offset 0x0443) */
void p07_L_4443(void) {
  /* call 0xDDBB - RAM/other */
  flag_cmp(a, e);
  /* sbc a,0xBB */
  p00_rst18();
  flag_cmp(a, e);
  if (flag_po()) return;
  flag_cmp(a, e);
  cpu_pop_hl();
  flag_cmp(a, e);
  /* jp po,0xE3BB - other page/RAM */
  flag_cmp(a, e);
  /* call 0xE5BB - RAM/other */
  flag_cmp(a, e);
  a = a & 0xBB;
  flag_logic(a);
  p00_rst20();
  flag_cmp(a, e);
  if (flag_pe()) return;
  flag_cmp(a, e);
  os_jp_hl();
  return;
}

/* flash page 7 cpu 0x4474 (offset 0x0474) */
void p07_L_4474(void) {
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p07_L_44B4;
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p07_L_44AC;
  flag_cmp(a, 0xFB);
  if (flag_z()) goto lab_p07_L_449E;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p07_L_4489;
  e = 0x3F;
  d = 0x00;
  return;
  lab_p07_L_4489: ;
  a = (uint8_t)(a - 0x5A);
  set_hl(0x4000);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  e = mem_read8(hl());
  return;
  lab_p07_L_449E: ;
  a = mem_read8(0x8446);
  flag_cmp(a, 0x8C);
  if (flag_c()) goto lab_p07_L_44A7;
  a = (uint8_t)(a - 0x7F);
  lab_p07_L_44A7: ;
  set_de(0x4426);
  goto lab_p07_L_44C5;
  lab_p07_L_44AC: ;
  a = mem_read8(0x8446);
  set_de(0x422C);
  goto lab_p07_L_44C5;
  lab_p07_L_44B4: ;
  a = mem_read8(0x8446);
  flag_cmp(a, 0x69);
  if (flag_nc()) goto lab_p07_L_44C0;
  p07_L_44BB();
  return;
  lab_p07_L_44C0: ;
  a = (uint8_t)(a - 0x69);
  set_de(0x4102);
  lab_p07_L_44C5: ;
  l = a;
  h = 0x00;
  set_hl((uint16_t)(hl() + hl()));
  set_hl((uint16_t)(hl() + de()));
  e = mem_read8(hl());
  d = e;
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  return;
}

/* flash page 7 cpu 0x4494 (offset 0x0494) */
void p07_L_4494(void) {
  h = (uint8_t)(h - 1);
  if (flag_z()) goto lab_p07_L_44B7;
  flag_cmp(a, 0xFC);
  a = e;
  if (flag_z()) goto lab_p07_L_44AF;
  goto lab_p07_L_44A1;
  lab_p07_L_44A1: ;
  flag_cmp(a, 0x8C);
  if (flag_c()) goto lab_p07_L_44A7;
  a = (uint8_t)(a - 0x7F);
  lab_p07_L_44A7: ;
  set_de(0x4426);
  goto lab_p07_L_44C5;
  lab_p07_L_44AF: ;
  set_de(0x422C);
  goto lab_p07_L_44C5;
  lab_p07_L_44B7: ;
  flag_cmp(a, 0x69);
  if (flag_nc()) goto lab_p07_L_44C0;
  p07_L_44BB();
  return;
  lab_p07_L_44C0: ;
  a = (uint8_t)(a - 0x69);
  set_de(0x4102);
  lab_p07_L_44C5: ;
  l = a;
  h = 0x00;
  set_hl((uint16_t)(hl() + hl()));
  set_hl((uint16_t)(hl() + de()));
  e = mem_read8(hl());
  d = e;
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  return;
}

/* flash page 7 cpu 0x44BB (offset 0x04BB) */
void p07_L_44BB(void) {
  goto lab_p07_L_44BB;
  lab_p07_L_448E: ;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  e = mem_read8(hl());
  return;
  lab_p07_L_44BB: ;
  set_hl(0x4099);
  goto lab_p07_L_448E;
}

/* flash page 7 cpu 0x44CF (offset 0x04CF) */
void p07_L_44CF(void) {
  cpu_push_de();
  p00_L_3DA7();
  cpu_pop_bc();
  e = a;
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_44E6;
  set_hl(0x4099);
  a = c;
  set_bc(0x0069);
  /* cpir */
  if (flag_z()) goto lab_p07_L_4517;
  a = e;
  return;
  lab_p07_L_44E6: ;
  a = e;
  mem_write8(0x8446, a);
  d = c;
  e = b;
  set_hl(0x422C);
  cpu_push_hl();
  p00_L_0033();
  p00_L_192A();
  cpu_pop_hl();
  if (flag_z()) goto lab_p07_L_4507;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_push_de();
  p07_L_44FC();
  return;
  lab_p07_L_4507: ;
  cpu_push_de();
  set_de(0x4426);
  p00_L_192A();
  cpu_pop_de();
  if (flag_nc()) goto lab_p07_L_4514;
  a = 0xFC;
  return;
  lab_p07_L_4514: ;
  a = 0xFB;
  return;
  lab_p07_L_4517: ;
  a = e;
  mem_write8(0x8446, a);
  a = 0xFE;
  return;
}

/* flash page 7 cpu 0x44FC (offset 0x04FC) */
void p07_L_44FC(void) {
  goto lab_p07_L_44FC;
  lab_p07_L_44EF: ;
  cpu_push_hl();
  p00_L_0033();
  p00_L_192A();
  cpu_pop_hl();
  if (flag_z()) goto lab_p07_L_4507;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_push_de();
  lab_p07_L_44FC: ;
  set_de(0x4474);
  p00_L_192A();
  cpu_pop_de();
  if (flag_nc()) goto lab_p07_L_451B;
  goto lab_p07_L_44EF;
  lab_p07_L_4507: ;
  cpu_push_de();
  set_de(0x4426);
  p00_L_192A();
  cpu_pop_de();
  if (flag_nc()) goto lab_p07_L_4514;
  a = 0xFC;
  return;
  lab_p07_L_4514: ;
  a = 0xFB;
  return;
  lab_p07_L_451B: ;
  a = 0xFE;
  return;
}

/* flash page 7 cpu 0x451E (offset 0x051E) */
void p07_L_451E(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p07_L_452C;
  b = a;
  a = 0x01;
  p00_L_3705();
  a = b;
  if (flag_z()) return;
  lab_p07_L_452C: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_453A;
  b = a;
  a = 0x76;
  p00_L_3C45();
  a = b;
  if (flag_z()) return;
  lab_p07_L_453A: ;
  set_de(0x457D);
  set_hl((uint16_t)(hl() + de()));
  set_de(0x845A);
  p00_L_1185();
  set_hl(0x845A);
  return;
}

/* flash page 7 cpu 0x4548 (offset 0x0548) */
void p07_L_4548(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p07_L_4555;
  a = 0x03;
  p00_L_3705();
  if (flag_z()) goto lab_p07_L_4566;
  lab_p07_L_4555: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_4562;
  a = 0x78;
  p00_L_3C45();
  if (flag_z()) goto lab_p07_L_4566;
  lab_p07_L_4562: ;
  set_de(0x457D);
  set_hl((uint16_t)(hl() + de()));
  lab_p07_L_4566: ;
  set_de(0x845A);
  cpu_push_de();
  a = 0x06;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  goto lab_p07_L_4573;
  lab_p07_L_4570: ;
  mem_write8(de(), a);
  cpu_pop_hl();
  return;
  lab_p07_L_4573: ;
  p07_L_4579();
  a = 0;
  flag_logic(a);
  goto lab_p07_L_4570;
}

/* flash page 7 cpu 0x4579 (offset 0x0579) */
void p07_L_4579(void) {
  b = 0x07;
  lab_p07_L_457B: ;
  a = mem_read8(hl());
  /* sla a */
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_457B;
  return;
}

/* flash page 7 cpu 0x45BB (offset 0x05BB) */
void p07_L_45BB(void) {
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  d = (uint8_t)(d + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  /* nop */
  set_de(0x040A);
  a = mem_read8(bc());
  set_de(0x0500);
  /* nop */
  /* nop */
  /* nop */
  c = 0x0A;
  c = 0x00;
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  c = 0x04;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  e = (uint8_t)(e + 1);
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rra();
  goto lab_p07_L_4610;
  lab_p07_L_4610: ;
  cpu_ex_af();
  c = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_bc(0x0402);
  cpu_ex_af();
  cpu_rra();
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  d = 0x18;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4639;
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  set_bc(0x1806);
  b = 0x01;
  lab_p07_L_4639: ;
  set_bc(0x1F00);
  /* nop */
  cpu_rra();
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  cpu_rra();
  b = (uint8_t)(b + 1);
  cpu_rra();
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  p07_L_4645();
  return;
}

/* flash page 7 cpu 0x4645 (offset 0x0645) */
void p07_L_4645(void) {
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4653;
  set_bc((uint16_t)(bc() + 1));
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_464B;
  lab_p07_L_464B: ;
  cpu_rra();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_rlca();
  /* nop */
  /* nop */
  /* nop */
  lab_p07_L_4653: ;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_rrca();
  cpu_ex_af();
  c = 0x08;
  cpu_rrca();
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  cpu_rra();
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_rla();
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  cpu_rla();
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  c = 0x15;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  d = (uint8_t)(d - 1);
  c = 0x04;
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  cpu_rra();
  a = mem_read8(bc());
  cpu_rra();
  a = mem_read8(bc());
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  a = mem_read8(bc());
  c = 0x02;
  mem_write8(bc(), a);
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  goto lab_p07_L_46C0;
  lab_p07_L_46C0: ;
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b + 1);
  d = (uint8_t)(d - 1);
  c = 0x15;
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_rra();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  cpu_rra();
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  set_bc(0x0402);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_46FC;
  lab_p07_L_46FC: ;
  b = (uint8_t)(b - 1);
  c = 0x11;
  set_de((uint16_t)(de() + 1));
  d = (uint8_t)(d - 1);
  set_hl((uint16_t)(hl() + de()));
  set_de(0x050E);
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  c = 0x11;
  set_bc(0x0402);
  cpu_ex_af();
  cpu_rra();
  b = (uint8_t)(b - 1);
  cpu_rra();
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  set_bc(0x0E11);
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = 0x0A;
  mem_write8(de(), a);
  cpu_rra();
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4746;
  set_bc(0x1101);
  c = 0x05;
  b = 0x08;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_474F;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  cpu_rra();
  set_bc(0x0402);
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  c = 0x11;
  set_de(0x110E);
  set_de(0x050E);
  c = 0x11;
  lab_p07_L_4746: ;
  set_de(0x0F11);
  set_de(0x010F);
  set_bc(0x0C02);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  c = (uint8_t)(c + 1);
  lab_p07_L_474F: ;
  c = (uint8_t)(c + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_476A;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_rra();
  /* nop */
  cpu_rra();
  lab_p07_L_476A: ;
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  set_bc(0x0402);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  c = 0x11;
  set_bc(0x0402);
  /* nop */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  c = 0x11;
  d = (uint8_t)(d - 1);
  cpu_rla();
  d = (uint8_t)(d + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4793;
  b = (uint8_t)(b - 1);
  c = 0x11;
  set_de(0x111F);
  set_de(0x0511);
  e = 0x11;
  set_de(0x111E);
  set_de(0x051E);
  lab_p07_L_4793: ;
  e = 0x05;
  c = 0x11;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47A9;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47AC;
  c = 0x05;
  e = 0x11;
  set_de(0x1111);
  set_de(0x051E);
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47B8;
  e = 0x10;
  lab_p07_L_47A9: ;
  b = (uint8_t)(b - 1);
  if (b != 0) { p07_L_47BB(); return; }
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47CB;
  cpu_rra();
  lab_p07_L_47AC: ;
  b = (uint8_t)(b - 1);
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47C0;
  e = 0x10;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47C4;
  b = (uint8_t)(b - 1);
  c = 0x11;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47D0;
  lab_p07_L_47B8: ;
  cpu_rla();
  set_de(0x0F11);
  b = (uint8_t)(b - 1);
  set_de(0x1111);
  lab_p07_L_47C0: ;
  cpu_rra();
  set_de(0x1111);
  lab_p07_L_47C4: ;
  b = (uint8_t)(b - 1);
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  lab_p07_L_47CB: ;
  c = 0x05;
  cpu_rlca();
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  lab_p07_L_47D0: ;
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  set_de(0x1412);
  goto lab_p07_L_47EE;
  lab_p07_L_47EE: ;
  set_de(0x1519);
  set_de((uint16_t)(de() + 1));
  set_de(0x0511);
  c = 0x11;
  set_de(0x1111);
  set_de(0x050E);
  e = 0x11;
  set_de(0x101E);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4814;
  b = (uint8_t)(b - 1);
  c = 0x11;
  set_de(0x1511);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  e = 0x11;
  set_de(0x141E);
  mem_write8(de(), a);
  set_de(0x0F05);
  lab_p07_L_4814: ;
  b = (uint8_t)(b - 1);
  cpu_rrca();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4828;
  c = 0x01;
  set_bc(0x051E);
  cpu_rra();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  set_de(0x1111);
  lab_p07_L_4828: ;
  set_de(0x1111);
  c = 0x05;
  set_de(0x1111);
  set_de(0x0A0A);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  set_de(0x1111);
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  set_de(0x0A11);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x0511);
  set_de(0x1111);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  cpu_rra();
  set_bc(0x0402);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4873;
  b = (uint8_t)(b - 1);
  b = 0x09;
  set_de(0x111F);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4868;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  set_bc(0x0500);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  lab_p07_L_4868: ;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x0000);
  /* nop */
  lab_p07_L_4873: ;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_rra();
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x01;
  cpu_rrca();
  set_de(0x050F);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_489F;
  d = 0x19;
  set_de(0x1E11);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x10;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_48AC;
  c = 0x05;
  set_bc(0x0D01);
  lab_p07_L_489F: ;
  c = (uint8_t)(c - 1);
  set_de((uint16_t)(de() + 1));
  set_de(0x0F11);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x11;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_48BA;
  lab_p07_L_48AC: ;
  b = (uint8_t)(b - 1);
  b = 0x09;
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  /* nop */
  cpu_rrca();
  set_de(0x0F11);
  lab_p07_L_48BA: ;
  set_bc(0x050E);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_48CF;
  d = 0x19;
  set_de(0x1111);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  mem_write8(bc(), a);
  /* nop */
  lab_p07_L_48CF: ;
  b = 0x02;
  mem_write8(bc(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  set_hl((uint16_t)(hl() + bc()));
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  /* nop */
  /* nop */
  a = mem_read8(de());
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  set_de(0x0511);
  /* nop */
  /* nop */
  d = 0x19;
  set_de(0x1111);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x11;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  e = 0x11;
  e = 0x10;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_490A;
  /* nop */
  /* nop */
  c = (uint8_t)(c - 1);
  set_de((uint16_t)(de() + 1));
  cpu_rrca();
  lab_p07_L_490A: ;
  set_bc(0x0501);
  /* nop */
  /* nop */
  d = 0x19;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4923;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_491A;
  /* nop */
  /* nop */
  c = 0x10;
  c = 0x01;
  lab_p07_L_491A: ;
  set_bc(0x051E);
  e = 0x05;
  cpu_ex_af();
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  cpu_ex_af();
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  lab_p07_L_4923: ;
  b = 0x05;
  /* nop */
  /* nop */
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x1111);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x1511);
  d = (uint8_t)(d - 1);
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x040A);
  a = mem_read8(bc());
  set_de(0x0005);
  /* nop */
  set_de(0x0F11);
  set_bc(0x050E);
  /* nop */
  /* nop */
  cpu_rra();
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_rra();
  b = (uint8_t)(b - 1);
  set_bc((uint16_t)(bc() + 1));
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  goto lab_p07_L_496B;
  lab_p07_L_496B: ;
  goto lab_p07_L_4972;
  lab_p07_L_4972: ;
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rra();
  cpu_rra();
  set_de(0x111F);
  cpu_rra();
  cpu_rra();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x0A;
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x05;
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  c = 0x05;
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_ex_af();
  a = mem_read8(bc());
  c = 0x02;
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x08;
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  b = 0x08;
  c = 0x0A;
  c = 0x05;
  /* nop */
  /* nop */
  c = 0x02;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  p07_L_49BB();
  return;
}

/* flash page 7 cpu 0x46BB (offset 0x06BB) */
void p07_L_46BB(void) {
  /* nop */
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b + 1);
  d = (uint8_t)(d - 1);
  c = 0x15;
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_rra();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  cpu_rra();
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  set_bc(0x0402);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_46FC;
  lab_p07_L_46FC: ;
  b = (uint8_t)(b - 1);
  c = 0x11;
  set_de((uint16_t)(de() + 1));
  d = (uint8_t)(d - 1);
  set_hl((uint16_t)(hl() + de()));
  set_de(0x050E);
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  c = 0x11;
  set_bc(0x0402);
  cpu_ex_af();
  cpu_rra();
  b = (uint8_t)(b - 1);
  cpu_rra();
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  set_bc(0x0E11);
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = 0x0A;
  mem_write8(de(), a);
  cpu_rra();
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4746;
  set_bc(0x1101);
  c = 0x05;
  b = 0x08;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_474F;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  cpu_rra();
  set_bc(0x0402);
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  c = 0x11;
  set_de(0x110E);
  set_de(0x050E);
  c = 0x11;
  lab_p07_L_4746: ;
  set_de(0x0F11);
  set_de(0x010F);
  set_bc(0x0C02);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  c = (uint8_t)(c + 1);
  lab_p07_L_474F: ;
  c = (uint8_t)(c + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_476A;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_rra();
  /* nop */
  cpu_rra();
  lab_p07_L_476A: ;
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  set_bc(0x0402);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  c = 0x11;
  set_bc(0x0402);
  /* nop */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  c = 0x11;
  d = (uint8_t)(d - 1);
  cpu_rla();
  d = (uint8_t)(d + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4793;
  b = (uint8_t)(b - 1);
  c = 0x11;
  set_de(0x111F);
  set_de(0x0511);
  e = 0x11;
  set_de(0x111E);
  set_de(0x051E);
  lab_p07_L_4793: ;
  e = 0x05;
  c = 0x11;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47A9;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47AC;
  c = 0x05;
  e = 0x11;
  set_de(0x1111);
  set_de(0x051E);
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47B8;
  e = 0x10;
  lab_p07_L_47A9: ;
  b = (uint8_t)(b - 1);
  if (b != 0) { p07_L_47BB(); return; }
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47CB;
  cpu_rra();
  lab_p07_L_47AC: ;
  b = (uint8_t)(b - 1);
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47C0;
  e = 0x10;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47C4;
  b = (uint8_t)(b - 1);
  c = 0x11;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_47D0;
  lab_p07_L_47B8: ;
  cpu_rla();
  set_de(0x0F11);
  b = (uint8_t)(b - 1);
  set_de(0x1111);
  lab_p07_L_47C0: ;
  cpu_rra();
  set_de(0x1111);
  lab_p07_L_47C4: ;
  b = (uint8_t)(b - 1);
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  lab_p07_L_47CB: ;
  c = 0x05;
  cpu_rlca();
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  lab_p07_L_47D0: ;
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  set_de(0x1412);
  goto lab_p07_L_47EE;
  lab_p07_L_47EE: ;
  set_de(0x1519);
  set_de((uint16_t)(de() + 1));
  set_de(0x0511);
  c = 0x11;
  set_de(0x1111);
  set_de(0x050E);
  e = 0x11;
  set_de(0x101E);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4814;
  b = (uint8_t)(b - 1);
  c = 0x11;
  set_de(0x1511);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  e = 0x11;
  set_de(0x141E);
  mem_write8(de(), a);
  set_de(0x0F05);
  lab_p07_L_4814: ;
  b = (uint8_t)(b - 1);
  cpu_rrca();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4828;
  c = 0x01;
  set_bc(0x051E);
  cpu_rra();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  set_de(0x1111);
  lab_p07_L_4828: ;
  set_de(0x1111);
  c = 0x05;
  set_de(0x1111);
  set_de(0x0A0A);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  set_de(0x1111);
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  set_de(0x0A11);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x0511);
  set_de(0x1111);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  cpu_rra();
  set_bc(0x0402);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4873;
  b = (uint8_t)(b - 1);
  b = 0x09;
  set_de(0x111F);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4868;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  set_bc(0x0500);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  lab_p07_L_4868: ;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x0000);
  /* nop */
  lab_p07_L_4873: ;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_rra();
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x01;
  cpu_rrca();
  set_de(0x050F);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_489F;
  d = 0x19;
  set_de(0x1E11);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x10;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_48AC;
  c = 0x05;
  set_bc(0x0D01);
  lab_p07_L_489F: ;
  c = (uint8_t)(c - 1);
  set_de((uint16_t)(de() + 1));
  set_de(0x0F11);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x11;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_48BA;
  lab_p07_L_48AC: ;
  b = (uint8_t)(b - 1);
  b = 0x09;
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  /* nop */
  cpu_rrca();
  set_de(0x0F11);
  lab_p07_L_48BA: ;
  set_bc(0x050E);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_48CF;
  d = 0x19;
  set_de(0x1111);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  mem_write8(bc(), a);
  /* nop */
  lab_p07_L_48CF: ;
  b = 0x02;
  mem_write8(bc(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  set_hl((uint16_t)(hl() + bc()));
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  /* nop */
  /* nop */
  a = mem_read8(de());
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  set_de(0x0511);
  /* nop */
  /* nop */
  d = 0x19;
  set_de(0x1111);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x11;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  e = 0x11;
  e = 0x10;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_490A;
  /* nop */
  /* nop */
  c = (uint8_t)(c - 1);
  set_de((uint16_t)(de() + 1));
  cpu_rrca();
  lab_p07_L_490A: ;
  set_bc(0x0501);
  /* nop */
  /* nop */
  d = 0x19;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4923;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_491A;
  /* nop */
  /* nop */
  c = 0x10;
  c = 0x01;
  lab_p07_L_491A: ;
  set_bc(0x051E);
  e = 0x05;
  cpu_ex_af();
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  cpu_ex_af();
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  lab_p07_L_4923: ;
  b = 0x05;
  /* nop */
  /* nop */
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x1111);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x1511);
  d = (uint8_t)(d - 1);
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x040A);
  a = mem_read8(bc());
  set_de(0x0005);
  /* nop */
  set_de(0x0F11);
  set_bc(0x050E);
  /* nop */
  /* nop */
  cpu_rra();
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_rra();
  b = (uint8_t)(b - 1);
  set_bc((uint16_t)(bc() + 1));
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  goto lab_p07_L_496B;
  lab_p07_L_496B: ;
  goto lab_p07_L_4972;
  lab_p07_L_4972: ;
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rra();
  cpu_rra();
  set_de(0x111F);
  cpu_rra();
  cpu_rra();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x0A;
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x05;
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  c = 0x05;
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_ex_af();
  a = mem_read8(bc());
  c = 0x02;
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x08;
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  b = 0x08;
  c = 0x0A;
  c = 0x05;
  /* nop */
  /* nop */
  c = 0x02;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  p07_L_49BB();
  return;
}

/* flash page 7 cpu 0x47BB (offset 0x07BB) */
void p07_L_47BB(void) {
  cpu_rrca();
  b = (uint8_t)(b - 1);
  set_de(0x1111);
  cpu_rra();
  set_de(0x1111);
  b = (uint8_t)(b - 1);
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  cpu_rlca();
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  set_de(0x1412);
  goto lab_p07_L_47EE;
  lab_p07_L_47EE: ;
  set_de(0x1519);
  set_de((uint16_t)(de() + 1));
  set_de(0x0511);
  c = 0x11;
  set_de(0x1111);
  set_de(0x050E);
  e = 0x11;
  set_de(0x101E);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4814;
  b = (uint8_t)(b - 1);
  c = 0x11;
  set_de(0x1511);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  e = 0x11;
  set_de(0x141E);
  mem_write8(de(), a);
  set_de(0x0F05);
  lab_p07_L_4814: ;
  b = (uint8_t)(b - 1);
  cpu_rrca();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4828;
  c = 0x01;
  set_bc(0x051E);
  cpu_rra();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  set_de(0x1111);
  lab_p07_L_4828: ;
  set_de(0x1111);
  c = 0x05;
  set_de(0x1111);
  set_de(0x0A0A);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  set_de(0x1111);
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  set_de(0x0A11);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x0511);
  set_de(0x1111);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  cpu_rra();
  set_bc(0x0402);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4873;
  b = (uint8_t)(b - 1);
  b = 0x09;
  set_de(0x111F);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4868;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  set_bc(0x0500);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  lab_p07_L_4868: ;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x0000);
  /* nop */
  lab_p07_L_4873: ;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_rra();
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x01;
  cpu_rrca();
  set_de(0x050F);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_489F;
  d = 0x19;
  set_de(0x1E11);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x10;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_48AC;
  c = 0x05;
  set_bc(0x0D01);
  lab_p07_L_489F: ;
  c = (uint8_t)(c - 1);
  set_de((uint16_t)(de() + 1));
  set_de(0x0F11);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x11;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_48BA;
  lab_p07_L_48AC: ;
  b = (uint8_t)(b - 1);
  b = 0x09;
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  /* nop */
  cpu_rrca();
  set_de(0x0F11);
  lab_p07_L_48BA: ;
  set_bc(0x050E);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_48CF;
  d = 0x19;
  set_de(0x1111);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  mem_write8(bc(), a);
  /* nop */
  lab_p07_L_48CF: ;
  b = 0x02;
  mem_write8(bc(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  set_hl((uint16_t)(hl() + bc()));
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  /* nop */
  /* nop */
  a = mem_read8(de());
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  set_de(0x0511);
  /* nop */
  /* nop */
  d = 0x19;
  set_de(0x1111);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x11;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  e = 0x11;
  e = 0x10;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_490A;
  /* nop */
  /* nop */
  c = (uint8_t)(c - 1);
  set_de((uint16_t)(de() + 1));
  cpu_rrca();
  lab_p07_L_490A: ;
  set_bc(0x0501);
  /* nop */
  /* nop */
  d = 0x19;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4923;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_491A;
  /* nop */
  /* nop */
  c = 0x10;
  c = 0x01;
  lab_p07_L_491A: ;
  set_bc(0x051E);
  e = 0x05;
  cpu_ex_af();
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  cpu_ex_af();
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  lab_p07_L_4923: ;
  b = 0x05;
  /* nop */
  /* nop */
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x1111);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x1511);
  d = (uint8_t)(d - 1);
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x040A);
  a = mem_read8(bc());
  set_de(0x0005);
  /* nop */
  set_de(0x0F11);
  set_bc(0x050E);
  /* nop */
  /* nop */
  cpu_rra();
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_rra();
  b = (uint8_t)(b - 1);
  set_bc((uint16_t)(bc() + 1));
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  goto lab_p07_L_496B;
  lab_p07_L_496B: ;
  goto lab_p07_L_4972;
  lab_p07_L_4972: ;
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rra();
  cpu_rra();
  set_de(0x111F);
  cpu_rra();
  cpu_rra();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x0A;
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x05;
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  c = 0x05;
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_ex_af();
  a = mem_read8(bc());
  c = 0x02;
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x08;
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  b = 0x08;
  c = 0x0A;
  c = 0x05;
  /* nop */
  /* nop */
  c = 0x02;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  p07_L_49BB();
  return;
}

/* flash page 7 cpu 0x4847 (offset 0x0847) */
void p07_L_4847(void) {
  set_de(0x040A);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  cpu_rra();
  set_bc(0x0402);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4873;
  b = (uint8_t)(b - 1);
  b = 0x09;
  set_de(0x111F);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4868;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  set_bc(0x0500);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  lab_p07_L_4868: ;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x0000);
  /* nop */
  lab_p07_L_4873: ;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_rra();
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x01;
  cpu_rrca();
  set_de(0x050F);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_489F;
  d = 0x19;
  set_de(0x1E11);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x10;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_48AC;
  c = 0x05;
  set_bc(0x0D01);
  lab_p07_L_489F: ;
  c = (uint8_t)(c - 1);
  set_de((uint16_t)(de() + 1));
  set_de(0x0F11);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x11;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_48BA;
  lab_p07_L_48AC: ;
  b = (uint8_t)(b - 1);
  b = 0x09;
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  /* nop */
  cpu_rrca();
  set_de(0x0F11);
  lab_p07_L_48BA: ;
  set_bc(0x050E);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_48CF;
  d = 0x19;
  set_de(0x1111);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  mem_write8(bc(), a);
  /* nop */
  lab_p07_L_48CF: ;
  b = 0x02;
  mem_write8(bc(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  set_hl((uint16_t)(hl() + bc()));
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  /* nop */
  /* nop */
  a = mem_read8(de());
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  set_de(0x0511);
  /* nop */
  /* nop */
  d = 0x19;
  set_de(0x1111);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x11;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  e = 0x11;
  e = 0x10;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_490A;
  /* nop */
  /* nop */
  c = (uint8_t)(c - 1);
  set_de((uint16_t)(de() + 1));
  cpu_rrca();
  lab_p07_L_490A: ;
  set_bc(0x0501);
  /* nop */
  /* nop */
  d = 0x19;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4923;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_491A;
  /* nop */
  /* nop */
  c = 0x10;
  c = 0x01;
  lab_p07_L_491A: ;
  set_bc(0x051E);
  e = 0x05;
  cpu_ex_af();
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  cpu_ex_af();
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  lab_p07_L_4923: ;
  b = 0x05;
  /* nop */
  /* nop */
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x1111);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x1511);
  d = (uint8_t)(d - 1);
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x040A);
  a = mem_read8(bc());
  set_de(0x0005);
  /* nop */
  set_de(0x0F11);
  set_bc(0x050E);
  /* nop */
  /* nop */
  cpu_rra();
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_rra();
  b = (uint8_t)(b - 1);
  set_bc((uint16_t)(bc() + 1));
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  goto lab_p07_L_496B;
  lab_p07_L_496B: ;
  goto lab_p07_L_4972;
  lab_p07_L_4972: ;
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rra();
  cpu_rra();
  set_de(0x111F);
  cpu_rra();
  cpu_rra();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x0A;
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x05;
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  c = 0x05;
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_ex_af();
  a = mem_read8(bc());
  c = 0x02;
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x08;
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  b = 0x08;
  c = 0x0A;
  c = 0x05;
  /* nop */
  /* nop */
  c = 0x02;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  p07_L_49BB();
  return;
}

/* flash page 7 cpu 0x48BB (offset 0x08BB) */
void p07_L_48BB(void) {
  c = 0x05;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_48CF;
  d = 0x19;
  set_de(0x1111);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  mem_write8(bc(), a);
  /* nop */
  lab_p07_L_48CF: ;
  b = 0x02;
  mem_write8(bc(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(bc());
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  set_hl((uint16_t)(hl() + bc()));
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  /* nop */
  /* nop */
  a = mem_read8(de());
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d - 1);
  set_de(0x0511);
  /* nop */
  /* nop */
  d = 0x19;
  set_de(0x1111);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x11;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  e = 0x11;
  e = 0x10;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_490A;
  /* nop */
  /* nop */
  c = (uint8_t)(c - 1);
  set_de((uint16_t)(de() + 1));
  cpu_rrca();
  lab_p07_L_490A: ;
  set_bc(0x0501);
  /* nop */
  /* nop */
  d = 0x19;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4923;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_491A;
  /* nop */
  /* nop */
  c = 0x10;
  c = 0x01;
  lab_p07_L_491A: ;
  set_bc(0x051E);
  e = 0x05;
  cpu_ex_af();
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  cpu_ex_af();
  cpu_ex_af();
  set_hl((uint16_t)(hl() + bc()));
  lab_p07_L_4923: ;
  b = 0x05;
  /* nop */
  /* nop */
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x1111);
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x1511);
  d = (uint8_t)(d - 1);
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  set_de(0x040A);
  a = mem_read8(bc());
  set_de(0x0005);
  /* nop */
  set_de(0x0F11);
  set_bc(0x050E);
  /* nop */
  /* nop */
  cpu_rra();
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_rra();
  b = (uint8_t)(b - 1);
  set_bc((uint16_t)(bc() + 1));
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  goto lab_p07_L_496B;
  lab_p07_L_496B: ;
  goto lab_p07_L_4972;
  lab_p07_L_4972: ;
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rra();
  cpu_rra();
  set_de(0x111F);
  cpu_rra();
  cpu_rra();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x0A;
  a = mem_read8(bc());
  a = mem_read8(bc());
  c = 0x05;
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  c = 0x05;
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_ex_af();
  a = mem_read8(bc());
  c = 0x02;
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x08;
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  b = 0x08;
  c = 0x0A;
  c = 0x05;
  /* nop */
  /* nop */
  c = 0x02;
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  p07_L_49BB();
  return;
}

/* flash page 7 cpu 0x49BB (offset 0x09BB) */
void p07_L_49BB(void) {
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x0A;
  c = 0x0A;
  c = 0x05;
  /* nop */
  /* nop */
  c = 0x0A;
  c = 0x02;
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = 0x11;
  set_de(0x111F);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  c = 0x11;
  set_de(0x111F);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x11;
  cpu_rra();
  set_de(0x0A05);
  /* nop */
  c = 0x11;
  set_de(0x111F);
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = 0x01;
  cpu_rrca();
  set_de(0x050F);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  c = 0x01;
  cpu_rrca();
  set_de(0x050F);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  p07_L_49FF();
  return;
}

/* flash page 7 cpu 0x49FF (offset 0x09FF) */
void p07_L_49FF(void) {
  c = 0x01;
  cpu_rrca();
  set_de(0x050F);
  a = mem_read8(bc());
  /* nop */
  c = 0x01;
  cpu_rrca();
  set_de(0x050F);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4A30;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4A33;
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4A38;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4A3B;
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4A40;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4A43;
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  /* nop */
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4A48;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4A4B;
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = 0x11;
  lab_p07_L_4A30: ;
  set_de(0x101F);
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4A42;
  lab_p07_L_4A33: ;
  c = 0x05;
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  c = 0x11;
  lab_p07_L_4A38: ;
  set_de(0x101F);
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4A4A;
  lab_p07_L_4A3B: ;
  c = 0x05;
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x11;
  lab_p07_L_4A40: ;
  set_de(0x101F);
  cpu_rra();
  lab_p07_L_4A42: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4A52;
  lab_p07_L_4A43: ;
  c = 0x05;
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x11;
  p07_L_4A49();
  return;
  lab_p07_L_4A48: ;
  set_de(0x101F);
  lab_p07_L_4A4A: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4A5A;
  lab_p07_L_4A4B: ;
  c = 0x05;
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = 0x04;
  b = (uint8_t)(b + 1);
  lab_p07_L_4A52: ;
  b = (uint8_t)(b + 1);
  c = 0x05;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  c = 0x04;
  b = (uint8_t)(b + 1);
  lab_p07_L_4A5A: ;
  b = (uint8_t)(b + 1);
  c = 0x05;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  a = mem_read8(bc());
  /* nop */
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  a = mem_read8(bc());
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = 0x11;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  c = 0x11;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x11;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x11;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x11;
  set_de(0x050E);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x11;
  set_de(0x050E);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x11;
  set_de(0x050E);
  a = mem_read8(bc());
  /* nop */
  /* nop */
  c = 0x11;
  set_de(0x050E);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de(0x050E);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de(0x050E);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  set_de(0x1111);
  c = 0x05;
  a = mem_read8(bc());
  /* nop */
  set_de(0x1111);
  set_de(0x050E);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  set_de(0x1311);
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  /* nop */
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  c = 0x11;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4B22;
  c = 0x04;
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x10;
  set_de(0x1C0E);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  set_de(0x1519);
  lab_p07_L_4B22: ;
  set_de((uint16_t)(de() + 1));
  set_de(0x0505);
  a = mem_read8(bc());
  /* nop */
  d = 0x19;
  set_de(0x0511);
  set_bc(0x0402);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4B3F;
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  a = mem_read8(bc());
  lab_p07_L_4B3F: ;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4B5C;
  c = 0x05;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = (uint8_t)(c - 1);
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  lab_p07_L_4B5C: ;
  b = (uint8_t)(b - 1);
  b = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  c = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  d = 0x05;
  /* nop */
  /* nop */
  set_hl((uint16_t)(hl() + bc()));
  d = (uint8_t)(d - 1);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x051F);
  b = 0x08;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  cpu_rrca();
  set_de(0x050E);
  /* nop */
  /* nop */
  c = 0x10;
  e = 0x10;
  c = 0x05;
  b = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = 0x05;
  /* nop */
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = 0x09;
  set_de(0x0005);
  /* nop */
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  e = (uint8_t)(e - 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4BA2;
  /* nop */
  /* nop */
  cpu_rra();
  a = mem_read8(bc());
  a = mem_read8(bc());
  lab_p07_L_4BA2: ;
  a = mem_read8(bc());
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  /* nop */
  b = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  c = 0x08;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4BB2;
  cpu_rra();
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  lab_p07_L_4BB2: ;
  cpu_ex_af();
  cpu_rra();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_rrca();
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  p07_L_4BBB();
  return;
}

/* flash page 7 cpu 0x4A49 (offset 0x0A49) */
void p07_L_4A49(void) {
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4A5A;
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  c = 0x04;
  b = (uint8_t)(b + 1);
  lab_p07_L_4A5A: ;
  b = (uint8_t)(b + 1);
  c = 0x05;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  a = mem_read8(bc());
  /* nop */
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  a = mem_read8(bc());
  /* nop */
  /* nop */
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x05;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  c = 0x11;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  c = 0x11;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x11;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x11;
  set_de(0x0E11);
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x11;
  set_de(0x050E);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  /* nop */
  c = 0x11;
  set_de(0x050E);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x11;
  set_de(0x050E);
  a = mem_read8(bc());
  /* nop */
  /* nop */
  c = 0x11;
  set_de(0x050E);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de(0x050E);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de(0x050E);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  set_de(0x1111);
  c = 0x05;
  a = mem_read8(bc());
  /* nop */
  set_de(0x1111);
  set_de(0x050E);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  set_de(0x1311);
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  /* nop */
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  c = 0x11;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4B22;
  c = 0x04;
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x10;
  set_de(0x1C0E);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  set_de(0x1519);
  lab_p07_L_4B22: ;
  set_de((uint16_t)(de() + 1));
  set_de(0x0505);
  a = mem_read8(bc());
  /* nop */
  d = 0x19;
  set_de(0x0511);
  set_bc(0x0402);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4B3F;
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  a = mem_read8(bc());
  lab_p07_L_4B3F: ;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4B5C;
  c = 0x05;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = (uint8_t)(c - 1);
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  lab_p07_L_4B5C: ;
  b = (uint8_t)(b - 1);
  b = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  c = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  d = 0x05;
  /* nop */
  /* nop */
  set_hl((uint16_t)(hl() + bc()));
  d = (uint8_t)(d - 1);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x051F);
  b = 0x08;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  cpu_rrca();
  set_de(0x050E);
  /* nop */
  /* nop */
  c = 0x10;
  e = 0x10;
  c = 0x05;
  b = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = 0x05;
  /* nop */
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = 0x09;
  set_de(0x0005);
  /* nop */
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  e = (uint8_t)(e - 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4BA2;
  /* nop */
  /* nop */
  cpu_rra();
  a = mem_read8(bc());
  a = mem_read8(bc());
  lab_p07_L_4BA2: ;
  a = mem_read8(bc());
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  /* nop */
  b = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  c = 0x08;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4BB2;
  cpu_rra();
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  lab_p07_L_4BB2: ;
  cpu_ex_af();
  cpu_rra();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_rrca();
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  p07_L_4BBB();
  return;
}

/* flash page 7 cpu 0x4ABB (offset 0x0ABB) */
void p07_L_4ABB(void) {
  c = 0x05;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x11;
  set_de(0x050E);
  a = mem_read8(bc());
  /* nop */
  /* nop */
  c = 0x11;
  set_de(0x050E);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de(0x050E);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de(0x050E);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  set_de(0x1111);
  c = 0x05;
  a = mem_read8(bc());
  /* nop */
  set_de(0x1111);
  set_de(0x050E);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  /* nop */
  set_de(0x1311);
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  /* nop */
  set_de(0x1111);
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  c = 0x11;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4B22;
  c = 0x04;
  e = (uint8_t)(e + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x10;
  set_de(0x1C0E);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  set_de(0x1519);
  lab_p07_L_4B22: ;
  set_de((uint16_t)(de() + 1));
  set_de(0x0505);
  a = mem_read8(bc());
  /* nop */
  d = 0x19;
  set_de(0x0511);
  set_bc(0x0402);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4B3F;
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  a = mem_read8(bc());
  lab_p07_L_4B3F: ;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4B5C;
  c = 0x05;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = (uint8_t)(c - 1);
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  c = (uint8_t)(c - 1);
  lab_p07_L_4B5C: ;
  b = (uint8_t)(b - 1);
  b = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  c = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  d = 0x05;
  /* nop */
  /* nop */
  set_hl((uint16_t)(hl() + bc()));
  d = (uint8_t)(d - 1);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_de(0x051F);
  b = 0x08;
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  cpu_rrca();
  set_de(0x050E);
  /* nop */
  /* nop */
  c = 0x10;
  e = 0x10;
  c = 0x05;
  b = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = 0x05;
  /* nop */
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = 0x09;
  set_de(0x0005);
  /* nop */
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  e = (uint8_t)(e - 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4BA2;
  /* nop */
  /* nop */
  cpu_rra();
  a = mem_read8(bc());
  a = mem_read8(bc());
  lab_p07_L_4BA2: ;
  a = mem_read8(bc());
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  /* nop */
  b = 0x09;
  set_hl((uint16_t)(hl() + bc()));
  c = 0x08;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4BB2;
  cpu_rra();
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  lab_p07_L_4BB2: ;
  cpu_ex_af();
  cpu_rra();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_rrca();
  mem_write8(de(), a);
  mem_write8(de(), a);
  mem_write8(de(), a);
  p07_L_4BBB();
  return;
}

/* flash page 7 cpu 0x4BBB (offset 0x0BBB) */
void p07_L_4BBB(void) {
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_rrca();
  d = (uint8_t)(d + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = 0x15;
  c = 0x04;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  c = 0x11;
  set_de(0x0A11);
  a = mem_read8(bc());
  set_de((uint16_t)(de() - 1));
  b = (uint8_t)(b - 1);
  cpu_rra();
  /* nop */
  set_de(0x040A);
  a = mem_read8(bc());
  set_de(0x1F05);
  /* nop */
  set_de(0x0F11);
  set_bc(0x050E);
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  d = (uint8_t)(d - 1);
  b = (uint8_t)(b - 1);
  /* nop */
  mem_write8(bc(), a);
  b = 0x0E;
  b = 0x02;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  e = (uint8_t)(e + 1);
  e = (uint8_t)(e + 1);
  e = (uint8_t)(e + 1);
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  cpu_ex_af();
  cpu_ex_af();
  cpu_ex_af();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  c = 0x00;
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  c = 0x02;
  c = 0x08;
  c = 0x00;
  /* nop */
  b = (uint8_t)(b - 1);
  c = 0x0A;
  c = 0x00;
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
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
  b = (uint8_t)(b - 1);
  cpu_ex_af();
  /* nop */
  goto lab_p07_L_4C41;
  lab_p07_L_4C41: ;
  e = 0x10;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4C4A;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4C50;
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  lab_p07_L_4C4A: ;
  mem_write8(de(), a);
  p07_L_4C4B();
  return;
  lab_p07_L_4C50: ;
  e = (uint8_t)(e + 1);
  d = (uint8_t)(d + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4C64;
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x11;
  e = 0x10;
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_rlca();
  lab_p07_L_4C64: ;
  b = (uint8_t)(b - 1);
  set_de(0x1D19);
  cpu_rra();
  cpu_rla();
  set_de((uint16_t)(de() + 1));
  set_de(0x1405);
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  d = (uint8_t)(d + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  e = 0x1C;
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  b = (uint8_t)(b - 1);
  cpu_rra();
  set_de((uint16_t)(de() - 1));
  set_de(0x1B0A);
  set_de((uint16_t)(de() - 1));
  set_de((uint16_t)(de() - 1));
  b = (uint8_t)(b - 1);
  cpu_rra();
  set_de((uint16_t)(de() - 1));
  d = (uint8_t)(d - 1);
  set_de(0x1515);
  cpu_rra();
  b = (uint8_t)(b - 1);
  cpu_rra();
  set_de((uint16_t)(de() - 1));
  e = (uint8_t)(e - 1);
  set_hl((uint16_t)(hl() + de()));
  d = (uint8_t)(d - 1);
  set_hl((uint16_t)(hl() + de()));
  cpu_rra();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_rra();
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  c = 0x15;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_rra();
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x0A;
  a = mem_read8(bc());
  /* nop */
  cpu_rra();
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = 0x0A;
  b = 0x00;
  p07_L_4CBB();
  return;
}

/* flash page 7 cpu 0x4C4B (offset 0x0C4B) */
void p07_L_4C4B(void) {
  set_bc(0x1F05);
  set_de(0x1C14);
  d = (uint8_t)(d + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4C64;
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  c = 0x11;
  e = 0x10;
  c = (uint8_t)(c + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  cpu_rlca();
  lab_p07_L_4C64: ;
  b = (uint8_t)(b - 1);
  set_de(0x1D19);
  cpu_rra();
  cpu_rla();
  set_de((uint16_t)(de() + 1));
  set_de(0x1405);
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  a = mem_read8(bc());
  d = (uint8_t)(d + 1);
  b = (uint8_t)(b - 1);
  /* nop */
  cpu_ex_af();
  e = (uint8_t)(e + 1);
  e = 0x1C;
  cpu_ex_af();
  /* nop */
  b = (uint8_t)(b - 1);
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  b = (uint8_t)(b - 1);
  cpu_rra();
  set_de((uint16_t)(de() - 1));
  set_de(0x1B0A);
  set_de((uint16_t)(de() - 1));
  set_de((uint16_t)(de() - 1));
  b = (uint8_t)(b - 1);
  cpu_rra();
  set_de((uint16_t)(de() - 1));
  d = (uint8_t)(d - 1);
  set_de(0x1515);
  cpu_rra();
  b = (uint8_t)(b - 1);
  cpu_rra();
  set_de((uint16_t)(de() - 1));
  e = (uint8_t)(e - 1);
  set_hl((uint16_t)(hl() + de()));
  d = (uint8_t)(d - 1);
  set_hl((uint16_t)(hl() + de()));
  cpu_rra();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_rra();
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  c = 0x15;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_rra();
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  c = 0x0A;
  a = mem_read8(bc());
  /* nop */
  cpu_rra();
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = 0x0A;
  b = 0x00;
  p07_L_4CBB();
  return;
}

/* flash page 7 cpu 0x4CBB (offset 0x0CBB) */
void p07_L_4CBB(void) {
  cpu_rra();
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  cpu_ex_af();
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  set_bc(0x0500);
  goto lab_p07_L_4CE3;
  lab_p07_L_4CE3: ;
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = mem_read8(bc());
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4CF0;
  lab_p07_L_4CF0: ;
  b = (uint8_t)(b + 1);
  /* nop */
  set_bc(0x0500);
  b = (uint8_t)(b + 1);
  c = 0x1F;
  c = 0x0E;
  c = 0x00;
  b = (uint8_t)(b - 1);
  /* nop */
  c = 0x0E;
  c = 0x1F;
  c = 0x04;
  b = (uint8_t)(b - 1);
  d = (uint8_t)(d - 1);
  a = mem_read8(bc());
  d = (uint8_t)(d - 1);
  a = mem_read8(bc());
  d = (uint8_t)(d - 1);
  a = mem_read8(bc());
  d = (uint8_t)(d - 1);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  cpu_rrca();
  d = (uint8_t)(d + 1);
  c = 0x05;
  e = 0x04;
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  c = 0x1F;
  c = 0x0E;
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  mem_write8(de(), a);
  mem_write8(de(), a);
  d = 0x11;
  set_de(0x0516);
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
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
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
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
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
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
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
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
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
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p07_L_4D7C();
  return;
}

/* flash page 7 cpu 0x4D7C (offset 0x0D7C) */
void p07_L_4D7C(void) {
  p00_L_2429();
  cpu_push_hl();
  cpu_ex_de_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  cpu_ex_de_hl();
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_4D8E;
  cpu_pop_hl();
  goto lab_p07_L_4DAF;
  lab_p07_L_4D8E: ;
  p00_L_1025();
  cpu_pop_de();
  cpu_push_hl();
  h = d;
  l = e;
  cpu_push_bc();
  lab_p07_L_4D96: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 3)));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 2)));
  p00_L_1183();
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_4DAA;
  cpu_push_bc();
  set_bc(0x0009);
  set_hl((uint16_t)(hl() + bc()));
  goto lab_p07_L_4D96;
  lab_p07_L_4DAA: ;
  cpu_ex_de_hl();
  cpu_pop_de();
  p00_L_1FB8();
  lab_p07_L_4DAF: ;
  cpu_pop_hl();
  a = mem_read8(hl());
  a = (uint8_t)(a - 0x0C);
  mem_write8(hl(), a);
  mem_write8(0x8478, a);
  return;
}

/* flash page 7 cpu 0x4DB8 (offset 0x0DB8) */
void p07_L_4DB8(void) {
  p00_L_1847();
  p07_L_4DBB();
  return;
}

/* flash page 7 cpu 0x4DBB (offset 0x0DBB) */
void p07_L_4DBB(void) {
  cpu_push_hl();
  p00_L_1647();
  cpu_push_hl();
  p00_L_2429();
  mem_write16(0x84D3, de());
  cpu_ex_de_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  mem_write16(0x848E, de());
  cpu_ex_de_hl();
  p00_L_1647();
  cpu_pop_de();
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p07_L_4DE2;
  if (flag_c()) goto lab_p07_L_4DE2;
  p07_L_4EF9();
  p00_L_23BD();
  lab_p07_L_4DE2: ;
  cpu_pop_hl();
  set_bc(mem_read16(0x848E));
  a = b;
  a = (uint8_t)(a - h);
  if (flag_c()) goto lab_p07_L_4E32;
  b = a;
  p07_L_4EEF();
  c = a;
  cpu_push_bc();
  if (flag_c()) goto lab_p07_L_4E49;
  cpu_push_hl();
  p07_L_4ED2();
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  cpu_pop_hl();
  b = l;
  p07_L_4DFB();
  return;
  lab_p07_L_4E32: ;
  a = h;
  a = (uint8_t)(a - b);
  b = a;
  p07_L_4EEF();
  c = a;
  cpu_push_bc();
  if (flag_c()) goto lab_p07_L_4E9E;
  b = c;
  c = l;
  c = (uint8_t)(c + 1);
  p07_L_4DFB();
  cpu_pop_bc();
  a = mem_read8(0x848F);
  c = a;
  goto lab_p07_L_4EAB;
  lab_p07_L_4E49: ;
  p07_L_4ED2();
  cpu_pop_bc();
  p07_L_4E4D();
  return;
  lab_p07_L_4E9E: ;
  b = c;
  a = mem_read8(0x848E);
  c = a;
  p07_L_4E52();
  cpu_pop_bc();
  a = mem_read8(0x848F);
  c = a;
  lab_p07_L_4EAB: ;
  p07_L_4F16();
  if (flag_z()) return;
  cpu_push_bc();
  cpu_push_hl();
  b = c;
  b = (uint8_t)(b + 1);
  cpu_push_bc();
  p00_L_23BD();
  cpu_pop_bc();
  set_de(mem_read16(0x84D3));
  p00_L_3B61();
  cpu_ex_de_hl();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_1B0E();
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  p07_L_4F2F();
  set_hl(mem_read16(0x84D3));
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  /* add a,(hl) */
  mem_write8(hl(), a);
  return;
}

/* flash page 7 cpu 0x4DFB (offset 0x0DFB) */
void p07_L_4DFB(void) {
  cpu_push_bc();
  p07_L_4F07();
  if (flag_nz()) goto lab_p07_L_4E03;
  cpu_pop_bc();
  return;
  lab_p07_L_4E03: ;
  b = a;
  set_hl(mem_read16(0x9824));
  cpu_push_hl();
  lab_p07_L_4E08: ;
  cpu_push_bc();
  cpu_push_de();
  set_de(mem_read16(0x84D3));
  p00_L_3B67();
  cpu_pop_de();
  cpu_push_de();
  p00_L_1EDE();
  cpu_pop_de();
  cpu_pop_bc();
  p00_L_21B6();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4E08;
  cpu_pop_hl();
  mem_write16(0x9824, hl());
  set_bc(mem_read16(0x9815));
  set_de(mem_read16(0x84D3));
  p00_L_1FBB();
  set_hl(mem_read16(0x84D3));
  p07_L_4EEA();
  return;
}

/* flash page 7 cpu 0x4E4D (offset 0x0E4D) */
void p07_L_4E4D(void) {
  b = c;
  a = mem_read8(0x848E);
  c = a;
  p07_L_4E52();
  return;
}

/* flash page 7 cpu 0x4E52 (offset 0x0E52) */
void p07_L_4E52(void) {
  cpu_push_bc();
  p07_L_4F07();
  if (flag_nz()) goto lab_p07_L_4E5A;
  cpu_pop_bc();
  return;
  lab_p07_L_4E5A: ;
  b = a;
  c = (uint8_t)(c + 1);
  cpu_push_bc();
  cpu_push_de();
  p00_L_23BD();
  cpu_pop_de();
  cpu_pop_bc();
  set_hl(mem_read16(0x9824));
  cpu_push_hl();
  lab_p07_L_4E67: ;
  cpu_push_bc();
  cpu_push_de();
  set_de(mem_read16(0x84D3));
  p00_L_3B67();
  cpu_ex_de_hl();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_1B18();
  cpu_pop_hl();
  cpu_push_hl();
  set_bc(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x9824, hl());
  cpu_sbc_hl_bc();
  a = a | a;
  flag_logic(a);
  p07_L_4F2F();
  cpu_pop_de();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4E67;
  cpu_pop_hl();
  mem_write16(0x9824, hl());
  set_bc(mem_read16(0x9815));
  set_de(mem_read16(0x84D3));
  p00_L_1FE8();
  set_hl(mem_read16(0x84D3));
  goto lab_p07_L_4ECE;
  lab_p07_L_4ECE: ;
  cpu_pop_af();
  /* add a,(hl) */
  mem_write8(hl(), a);
  return;
}

/* flash page 7 cpu 0x4EBB (offset 0x0EBB) */
void p07_L_4EBB(void) {
  a = (uint8_t)(a + h);
  p00_L_3B61();
  cpu_ex_de_hl();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_1B0E();
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  p07_L_4F2F();
  set_hl(mem_read16(0x84D3));
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  /* add a,(hl) */
  mem_write8(hl(), a);
  return;
}

/* flash page 7 cpu 0x4ED2 (offset 0x0ED2) */
void p07_L_4ED2(void) {
  c = h;
  c = (uint8_t)(c + 1);
  p07_L_4F16();
  if (flag_z()) return;
  cpu_push_bc();
  cpu_push_hl();
  b = c;
  set_de(mem_read16(0x84D3));
  p00_L_3B61();
  cpu_pop_de();
  p00_L_1FB8();
  set_hl(mem_read16(0x84D3));
  set_hl((uint16_t)(hl() + 1));
  p07_L_4EEA();
  return;
}

/* flash page 7 cpu 0x4EEA (offset 0x0EEA) */
void p07_L_4EEA(void) {
  cpu_pop_bc();
  a = mem_read8(hl());
  a = (uint8_t)(a - b);
  mem_write8(hl(), a);
  return;
}

/* flash page 7 cpu 0x4EEF (offset 0x0EEF) */
void p07_L_4EEF(void) {
  a = c;
  a = (uint8_t)(a - l);
  if (flag_nc()) return;
  a = l;
  a = (uint8_t)(a - c);
  /* scf */
  return;
}

/* flash page 7 cpu 0x4EF6 (offset 0x0EF6) */
void p07_L_4EF6(void) {
  l = b;
  h = 0x00;
  p07_L_4EF9();
  return;
}

/* flash page 7 cpu 0x4EF9 (offset 0x0EF9) */
void p07_L_4EF9(void) {
  p00_L_1025();
  lab_p07_L_4EFC: ;
  if (flag_c()) { p00_L_24F5(); return; }
  p00_L_184C();
  if (flag_z()) return;
  set_hl((uint16_t)(hl() + hl()));
  if (flag_c()) goto lab_p07_L_4EFC;
  return;
}

/* flash page 7 cpu 0x4F07 (offset 0x0F07) */
void p07_L_4F07(void) {
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  cpu_push_bc();
  p07_L_4EF6();
  cpu_ex_de_hl();
  set_hl(mem_read16(0x84D3));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  goto lab_p07_L_4F22;
  lab_p07_L_4F22: ;
  b = a;
  set_hl(0x0000);
  lab_p07_L_4F26: ;
  set_hl((uint16_t)(hl() + de()));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4F26;
  mem_write16(0x9815, hl());
  b = (uint8_t)(b - 1);
  cpu_pop_bc();
  return;
}

/* flash page 7 cpu 0x4F16 (offset 0x0F16) */
void p07_L_4F16(void) {
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  cpu_push_bc();
  set_hl(mem_read16(0x84D3));
  b = mem_read8(hl());
  p07_L_4EF6();
  cpu_ex_de_hl();
  b = a;
  set_hl(0x0000);
  lab_p07_L_4F26: ;
  set_hl((uint16_t)(hl() + de()));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_4F26;
  mem_write16(0x9815, hl());
  b = (uint8_t)(b - 1);
  cpu_pop_bc();
  return;
}

/* flash page 7 cpu 0x4F2F (offset 0x0F2F) */
void p07_L_4F2F(void) {
  p00_L_1847();
  p07_L_4F32();
  return;
}

/* flash page 7 cpu 0x4F32 (offset 0x0F32) */
void p07_L_4F32(void) {
  cpu_push_af();
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_af();
  p00_L_184C();
  if (flag_nz()) goto lab_p07_L_4F51;
  lab_p07_L_4F3C: ;
  cpu_pop_af();
  if (flag_nc()) goto lab_p07_L_4F44;
  p00_L_1020();
  goto lab_p07_L_4F47;
  lab_p07_L_4F44: ;
  p00_L_101A();
  lab_p07_L_4F47: ;
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_af();
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p07_L_4F68;
  goto lab_p07_L_4F3C;
  lab_p07_L_4F51: ;
  cpu_pop_af();
  set_hl(0x0FF6);
  if (flag_nc()) goto lab_p07_L_4F5A;
  set_hl(0x0FED);
  lab_p07_L_4F5A: ;
  p00_L_1183();
  p00_L_1183();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_af();
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nz()) goto lab_p07_L_4F51;
  lab_p07_L_4F68: ;
  cpu_pop_hl();
  cpu_pop_hl();
  return;
}

/* flash page 7 cpu 0x4F6B (offset 0x0F6B) */
void p07_L_4F6B(void) {
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  cpu_ex_de_hl();
  set_hl(0x03E7);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_z()) { p00_L_24ED(); return; }
  set_hl(0x0001);
  a = a | a;
  flag_logic(a);
  p07_L_4F7E();
  return;
}

/* flash page 7 cpu 0x4F7E (offset 0x0F7E) */
void p07_L_4F7E(void) {
  mem_write16(0x84E1, de());
  cpu_push_hl();
  cpu_push_af();
  cpu_push_bc();
  p00_L_1847();
  a = a & 0x08;
  flag_logic(a);
  if (flag_nz()) p00_L_1842();
  p07_L_4EF9();
  p00_L_23BD();
  cpu_pop_hl();
  cpu_push_de();
  set_hl((uint16_t)(hl() + 1));
  set_de(mem_read16(0x84E1));
  p00_L_3AE9();
  cpu_ex_de_hl();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_1B0E();
  cpu_pop_hl();
  cpu_pop_af();
  p07_L_4F32();
  cpu_pop_de();
  set_hl(mem_read16(0x84E1));
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_4FB3;
  lab_p07_L_4FB3: ;
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + bc()));
  p07_L_4FDD();
  cpu_ex_de_hl();
  return;
}

/* flash page 7 cpu 0x4FBA (offset 0x0FBA) */
void p07_L_4FBA(void) {
  a = a & 0x1F;
  flag_logic(a);
  mem_write16(0x84E1, de());
  cpu_push_hl();
  cpu_push_bc();
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p07_L_4FC7;
  set_hl((uint16_t)(hl() + hl()));
  lab_p07_L_4FC7: ;
  p00_L_1025();
  /* ex (sp),hl */
  p00_L_3AE9();
  cpu_pop_de();
  p00_L_1FB8();
  set_hl(mem_read16(0x84E1));
  cpu_pop_bc();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  p07_L_4FDD();
  return;
}

/* flash page 7 cpu 0x4FBB (offset 0x0FBB) */
void p07_L_4FBB(void) {
  cpu_rra();
  mem_write16(0x84E1, de());
  cpu_push_hl();
  cpu_push_bc();
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p07_L_4FC7;
  set_hl((uint16_t)(hl() + hl()));
  lab_p07_L_4FC7: ;
  p00_L_1025();
  /* ex (sp),hl */
  p00_L_3AE9();
  cpu_pop_de();
  p00_L_1FB8();
  set_hl(mem_read16(0x84E1));
  cpu_pop_bc();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  p07_L_4FDD();
  return;
}

/* flash page 7 cpu 0x4FDD (offset 0x0FDD) */
void p07_L_4FDD(void) {
  cpu_ex_de_hl();
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), e);
  return;
}

/* flash page 7 cpu 0x4FE2 (offset 0x0FE2) */
void p07_L_4FE2(void) {
  cpu_ex_de_hl();
  mem_write16(0x84D3, hl());
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x84D5, hl());
  cpu_ex_de_hl();
  set_hl(mem_read16(0x9824));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  mem_write16(0x84D9, hl());
  if (flag_nz()) goto lab_p07_L_5002;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() - 1));
  cpu_push_hl();
  set_hl(mem_read16(0x9828));
  goto lab_p07_L_500E;
  lab_p07_L_5002: ;
  b = h;
  c = l;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() - 1));
  set_de(mem_read16(0x9828));
  /* lddr */
  cpu_ex_de_hl();
  cpu_push_de();
  lab_p07_L_500E: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x84D7, hl());
  set_de(mem_read16(0x84D5));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  a = l;
  a = a ^ 0xFF;
  c = a;
  a = h;
  a = a ^ 0xFF;
  b = a;
  set_bc((uint16_t)(bc() + 1));
  cpu_pop_de();
  p00_L_1DAD();
  p00_L_1FC0();
  return;
}

/* flash page 7 cpu 0x5027 (offset 0x1027) */
void p07_L_5027(void) {
  set_bc(mem_read16(0x84D9));
  set_hl(mem_read16(0x84D5));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_5038;
  cpu_ex_de_hl();
  set_hl(mem_read16(0x84D7));
  while (bc() != 0) { cpu_ldi(); }
  lab_p07_L_5038: ;
  set_hl(mem_read16(0x84D7));
  set_de(mem_read16(0x84D5));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  b = h;
  c = l;
  set_de((uint16_t)(de() - 1));
  p00_L_1DAD();
  p00_L_1FC0();
  return;
}

/* flash page 7 cpu 0x504B (offset 0x104B) */
void p07_L_504B(void) {
  set_hl(0xFE66);
  set_bc(mem_read16(0x9826));
  set_bc((uint16_t)(bc() + 1));
  a = a | a;
  flag_logic(a);
  lab_p07_L_5054: ;
  cpu_sbc_hl_bc();
  if (flag_c()) return;
  set_hl((uint16_t)(hl() + bc()));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  p07_L_53C8();
  goto lab_p07_L_5054;
}

/* flash page 7 cpu 0x504F (offset 0x104F) */
void p07_L_504F(void) {
  c = e;
  h = 0x98;
  set_bc((uint16_t)(bc() + 1));
  a = a | a;
  flag_logic(a);
  lab_p07_L_5054: ;
  cpu_sbc_hl_bc();
  if (flag_c()) return;
  set_hl((uint16_t)(hl() + bc()));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  p07_L_53C8();
  goto lab_p07_L_5054;
}

/* flash page 7 cpu 0x505F (offset 0x105F) */
void p07_L_505F(void) {
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_z()) { p07_L_534B(); return; }
  mem_write16(0x982A, de());
  set_hl(mem_read16(0x982E));
  lab_p07_L_506B: ;
  cpu_push_hl();
  p00_L_2406();
  a = a | a;
  flag_logic(a);
  set_bc(mem_read16(0x9826));
  cpu_sbc_hl_bc();
  if (flag_nc()) goto lab_p07_L_507A;
  cpu_pop_hl();
  return;
  lab_p07_L_507A: ;
  set_hl((uint16_t)(hl() + bc()));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  cpu_pop_bc();
  cpu_push_hl();
  set_hl(mem_read16(0x982A));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p07_L_508B;
  if (flag_nz()) goto lab_p07_L_508F;
  lab_p07_L_508B: ;
  h = b;
  l = c;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  lab_p07_L_508F: ;
  cpu_pop_hl();
  goto lab_p07_L_506B;
}

/* flash page 7 cpu 0x5092 (offset 0x1092) */
void p07_L_5092(void) {
  p00_rst18();
  p00_L_241E();
  if (flag_nc()) goto lab_p07_L_50A3;
  p00_L_1C39();
  p00_L_101A();
  p00_L_128A();
  goto lab_p07_L_50B2;
  lab_p07_L_50A3: ;
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_50AF;
  p00_L_38B5();
  goto lab_p07_L_50B2;
  lab_p07_L_50AF: ;
  p00_L_128A();
  lab_p07_L_50B2: ;
  p00_L_2222();
  a = mem_read8(0x9814);
  cpu_push_af();
  h = a;
  a = (uint8_t)(a + 1);
  p07_L_50BB();
  return;
}

/* flash page 7 cpu 0x50BB (offset 0x10BB) */
void p07_L_50BB(void) {
  mem_write8(0x9814, a);
  a = 0;
  flag_logic(a);
  l = a;
  mem_write16(0x8479, hl());
  mem_write8(0x847B, a);
  p00_L_38DF();
  cpu_pop_af();
  h = a;
  a = 0;
  flag_logic(a);
  l = a;
  mem_write16(0x8479, hl());
  mem_write8(0x847B, a);
  p00_rst10();
  cpu_push_de();
  cpu_push_hl();
  p00_L_219B();
  p00_L_2429();
  /* ex (sp),hl */
  p07_L_50EC();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_de();
  a = mem_read8(de());
  b = mem_read8(hl());
  mem_write8(hl(), a);
  a = b;
  mem_write8(de(), a);
  cpu_ex_de_hl();
  cpu_pop_de();
  p07_L_50EC();
  return;
}

/* flash page 7 cpu 0x50EC (offset 0x10EC) */
void p07_L_50EC(void) {
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), d);
  return;
}

/* flash page 7 cpu 0x50F3 (offset 0x10F3) */
void p07_L_50F3(void) {
  p00_L_241E();
  lab_p07_L_50F6: ;
  a = mem_read8(0x9814);
  a = (uint8_t)(a - 0x01);
  if (flag_c()) return;
  mem_write8(0x9814, a);
  b = a;
  a = 0;
  flag_logic(a);
  c = a;
  mem_write16(0x8479, bc());
  mem_write8(0x847B, a);
  cpu_push_de();
  cpu_push_hl();
  p00_L_241E();
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_c()) goto lab_p07_L_50F6;
  p07_L_5119();
  p00_rst10();
  p00_L_1F58();
  return;
}

/* flash page 7 cpu 0x5119 (offset 0x1119) */
void p07_L_5119(void) {
  goto lab_p07_L_5119;
  lab_p07_L_50DC: ;
  /* ex (sp),hl */
  p07_L_50EC();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_de();
  a = mem_read8(de());
  b = mem_read8(hl());
  mem_write8(hl(), a);
  a = b;
  mem_write8(de(), a);
  cpu_ex_de_hl();
  cpu_pop_de();
  p07_L_50EC();
  return;
  lab_p07_L_5119: ;
  cpu_push_de();
  cpu_push_hl();
  p00_L_241E();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_50DC;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  goto lab_p07_L_50DC;
}

/* flash page 7 cpu 0x5128 (offset 0x1128) */
void p07_L_5128(void) {
  /* scf */
  goto lab_p07_L_512D;
  lab_p07_L_512D: ;
  cpu_push_hl();
  a = 0x00;
  cpu_push_af();
  p00_L_1100();
  p00_L_1037();
  p00_L_1830();
  if (flag_nz()) goto lab_p07_L_5142;
  a = mem_read8(0x8479);
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p07_L_5149;
  lab_p07_L_5142: ;
  p00_L_1822();
  a = 0x05;
  if (flag_nz()) goto lab_p07_L_515B;
  lab_p07_L_5149: ;
  p00_L_19C5();
  set_hl(mem_read16(0x9830));
  set_de(mem_read16(0x982E));
  b = a;
  a = 0x08;
  a = (uint8_t)(a - b);
  if (flag_z()) goto lab_p07_L_516D;
  goto lab_p07_L_5162;
  lab_p07_L_515B: ;
  set_de(mem_read16(0x9830));
  set_hl(0xFE66);
  lab_p07_L_5162: ;
  cpu_push_hl();
  set_hl(0x8481);
  b = a;
  lab_p07_L_5167: ;
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), 0x00);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_5167;
  cpu_pop_hl();
  lab_p07_L_516D: ;
  cpu_pop_af();
  cpu_pop_bc();
  goto lab_p07_L_5174;
  lab_p07_L_5174: ;
  cpu_push_de();
  cpu_push_bc();
  cpu_push_af();
  p00_L_1037();
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p07_L_5182;
  a = 0x01;
  goto lab_p07_L_5187;
  lab_p07_L_5182: ;
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p07_L_5187;
  a = (uint8_t)(a - 1);
  lab_p07_L_5187: ;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p07_L_518D;
  a = 0x03;
  lab_p07_L_518D: ;
  b = a;
  a = a | a;
  flag_logic(a);
  set_de((uint16_t)(de() + 1));
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p07_L_5221;
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84E3, hl());
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p07_L_51A4;
  a = 0x01;
  goto lab_p07_L_51A9;
  lab_p07_L_51A4: ;
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p07_L_51A9;
  a = (uint8_t)(a - 1);
  lab_p07_L_51A9: ;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p07_L_51AF;
  a = 0x03;
  lab_p07_L_51AF: ;
  flag_cmp(a, b);
  if (flag_z()) goto lab_p07_L_51DF;
  set_de(0x0009);
  p00_L_17B3();
  if (flag_z()) goto lab_p07_L_51C7;
  p00_L_1830();
  if (flag_z()) goto lab_p07_L_51C7;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p07_L_51D9;
  flag_cmp(a, 0x0A);
  if (flag_z()) goto lab_p07_L_51D9;
  lab_p07_L_51C7: ;
  p00_L_2407();
  a = mem_read8(hl());
  flag_cmp(a, 0x72);
  if (flag_nz()) goto lab_p07_L_51D3;
  lab_p07_L_51CF: ;
  e = 0x03;
  goto lab_p07_L_51D9;
  lab_p07_L_51D3: ;
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p07_L_51CF;
  e = mem_read8(hl());
  e = (uint8_t)(e + 1);
  lab_p07_L_51D9: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  lab_p07_L_51DC: ;
  p07_L_5171();
  return;
  lab_p07_L_51DF: ;
  p07_L_5251();
  if (flag_c()) goto lab_p07_L_51DC;
  a = mem_read8(0x847A);
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p07_L_520E;
  cpu_push_hl();
  set_de(0x8480);
  p07_L_522C();
  cpu_pop_hl();
  if (flag_c()) goto lab_p07_L_520E;
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p07_L_51DC;
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p07_L_51DC;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_523E;
  cpu_push_hl();
  set_de(0x8496);
  p07_L_522C();
  if (flag_c()) goto lab_p07_L_5243;
  lab_p07_L_520A: ;
  cpu_pop_hl();
  lab_p07_L_520B: ;
  p07_L_5171();
  return;
  lab_p07_L_520E: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) goto lab_p07_L_520B;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_523E;
  cpu_push_hl();
  set_de(0x8496);
  p07_L_522C();
  if (flag_c()) goto lab_p07_L_520A;
  goto lab_p07_L_5243;
  lab_p07_L_5221: ;
  p00_L_113F();
  cpu_pop_af();
  cpu_pop_hl();
  cpu_pop_de();
  a = (uint8_t)(a & ~(1u << 0));
  a = (uint8_t)(a - 0x02);
  return;
  lab_p07_L_523E: ;
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 1));
  cpu_push_af();
  cpu_push_hl();
  lab_p07_L_5243: ;
  p00_L_11D8();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_pop_de();
  set_de(mem_read16(0x84E3));
  cpu_push_de();
  cpu_push_af();
  goto lab_p07_L_520B;
}

/* flash page 7 cpu 0x512B (offset 0x112B) */
void p07_L_512B(void) {
  /* scf */
  /* ccf */
  cpu_push_hl();
  a = 0x00;
  cpu_push_af();
  p00_L_1100();
  p00_L_1037();
  p00_L_1830();
  if (flag_nz()) goto lab_p07_L_5142;
  a = mem_read8(0x8479);
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p07_L_5149;
  lab_p07_L_5142: ;
  p00_L_1822();
  a = 0x05;
  if (flag_nz()) goto lab_p07_L_515B;
  lab_p07_L_5149: ;
  p00_L_19C5();
  set_hl(mem_read16(0x9830));
  set_de(mem_read16(0x982E));
  b = a;
  a = 0x08;
  a = (uint8_t)(a - b);
  if (flag_z()) goto lab_p07_L_516D;
  goto lab_p07_L_5162;
  lab_p07_L_515B: ;
  set_de(mem_read16(0x9830));
  set_hl(0xFE66);
  lab_p07_L_5162: ;
  cpu_push_hl();
  set_hl(0x8481);
  b = a;
  lab_p07_L_5167: ;
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), 0x00);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_5167;
  cpu_pop_hl();
  lab_p07_L_516D: ;
  cpu_pop_af();
  cpu_pop_bc();
  goto lab_p07_L_5174;
  lab_p07_L_5174: ;
  cpu_push_de();
  cpu_push_bc();
  cpu_push_af();
  p00_L_1037();
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p07_L_5182;
  a = 0x01;
  goto lab_p07_L_5187;
  lab_p07_L_5182: ;
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p07_L_5187;
  a = (uint8_t)(a - 1);
  lab_p07_L_5187: ;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p07_L_518D;
  a = 0x03;
  lab_p07_L_518D: ;
  b = a;
  a = a | a;
  flag_logic(a);
  set_de((uint16_t)(de() + 1));
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p07_L_5221;
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84E3, hl());
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p07_L_51A4;
  a = 0x01;
  goto lab_p07_L_51A9;
  lab_p07_L_51A4: ;
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p07_L_51A9;
  a = (uint8_t)(a - 1);
  lab_p07_L_51A9: ;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p07_L_51AF;
  a = 0x03;
  lab_p07_L_51AF: ;
  flag_cmp(a, b);
  if (flag_z()) goto lab_p07_L_51DF;
  set_de(0x0009);
  p00_L_17B3();
  if (flag_z()) goto lab_p07_L_51C7;
  p00_L_1830();
  if (flag_z()) goto lab_p07_L_51C7;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p07_L_51D9;
  flag_cmp(a, 0x0A);
  if (flag_z()) goto lab_p07_L_51D9;
  lab_p07_L_51C7: ;
  p00_L_2407();
  a = mem_read8(hl());
  flag_cmp(a, 0x72);
  if (flag_nz()) goto lab_p07_L_51D3;
  lab_p07_L_51CF: ;
  e = 0x03;
  goto lab_p07_L_51D9;
  lab_p07_L_51D3: ;
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p07_L_51CF;
  e = mem_read8(hl());
  e = (uint8_t)(e + 1);
  lab_p07_L_51D9: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  lab_p07_L_51DC: ;
  p07_L_5171();
  return;
  lab_p07_L_51DF: ;
  p07_L_5251();
  if (flag_c()) goto lab_p07_L_51DC;
  a = mem_read8(0x847A);
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p07_L_520E;
  cpu_push_hl();
  set_de(0x8480);
  p07_L_522C();
  cpu_pop_hl();
  if (flag_c()) goto lab_p07_L_520E;
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p07_L_51DC;
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p07_L_51DC;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_523E;
  cpu_push_hl();
  set_de(0x8496);
  p07_L_522C();
  if (flag_c()) goto lab_p07_L_5243;
  lab_p07_L_520A: ;
  cpu_pop_hl();
  lab_p07_L_520B: ;
  p07_L_5171();
  return;
  lab_p07_L_520E: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) goto lab_p07_L_520B;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_523E;
  cpu_push_hl();
  set_de(0x8496);
  p07_L_522C();
  if (flag_c()) goto lab_p07_L_520A;
  goto lab_p07_L_5243;
  lab_p07_L_5221: ;
  p00_L_113F();
  cpu_pop_af();
  cpu_pop_hl();
  cpu_pop_de();
  a = (uint8_t)(a & ~(1u << 0));
  a = (uint8_t)(a - 0x02);
  return;
  lab_p07_L_523E: ;
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 1));
  cpu_push_af();
  cpu_push_hl();
  lab_p07_L_5243: ;
  p00_L_11D8();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_pop_de();
  set_de(mem_read16(0x84E3));
  cpu_push_de();
  cpu_push_af();
  goto lab_p07_L_520B;
}

/* flash page 7 cpu 0x5171 (offset 0x1171) */
void p07_L_5171(void) {
  lab_p07_L_5171: ;
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_af();
  p00_L_1037();
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p07_L_5182;
  a = 0x01;
  goto lab_p07_L_5187;
  lab_p07_L_5182: ;
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p07_L_5187;
  a = (uint8_t)(a - 1);
  lab_p07_L_5187: ;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p07_L_518D;
  a = 0x03;
  lab_p07_L_518D: ;
  b = a;
  a = a | a;
  flag_logic(a);
  set_de((uint16_t)(de() + 1));
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p07_L_5221;
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84E3, hl());
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p07_L_51A4;
  a = 0x01;
  goto lab_p07_L_51A9;
  lab_p07_L_51A4: ;
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p07_L_51A9;
  a = (uint8_t)(a - 1);
  lab_p07_L_51A9: ;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p07_L_51AF;
  a = 0x03;
  lab_p07_L_51AF: ;
  flag_cmp(a, b);
  if (flag_z()) goto lab_p07_L_51DF;
  set_de(0x0009);
  p00_L_17B3();
  if (flag_z()) goto lab_p07_L_51C7;
  p00_L_1830();
  if (flag_z()) goto lab_p07_L_51C7;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p07_L_51D9;
  flag_cmp(a, 0x0A);
  if (flag_z()) goto lab_p07_L_51D9;
  lab_p07_L_51C7: ;
  p00_L_2407();
  a = mem_read8(hl());
  flag_cmp(a, 0x72);
  if (flag_nz()) goto lab_p07_L_51D3;
  lab_p07_L_51CF: ;
  e = 0x03;
  goto lab_p07_L_51D9;
  lab_p07_L_51D3: ;
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p07_L_51CF;
  e = mem_read8(hl());
  e = (uint8_t)(e + 1);
  lab_p07_L_51D9: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  lab_p07_L_51DC: ;
  goto lab_p07_L_5171;
  lab_p07_L_51DF: ;
  p07_L_5251();
  if (flag_c()) goto lab_p07_L_51DC;
  a = mem_read8(0x847A);
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p07_L_520E;
  cpu_push_hl();
  set_de(0x8480);
  p07_L_522C();
  cpu_pop_hl();
  if (flag_c()) goto lab_p07_L_520E;
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p07_L_51DC;
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p07_L_51DC;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_523E;
  cpu_push_hl();
  set_de(0x8496);
  p07_L_522C();
  if (flag_c()) goto lab_p07_L_5243;
  lab_p07_L_520A: ;
  cpu_pop_hl();
  lab_p07_L_520B: ;
  goto lab_p07_L_5171;
  lab_p07_L_520E: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) goto lab_p07_L_520B;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_523E;
  cpu_push_hl();
  set_de(0x8496);
  p07_L_522C();
  if (flag_c()) goto lab_p07_L_520A;
  goto lab_p07_L_5243;
  lab_p07_L_5221: ;
  p00_L_113F();
  cpu_pop_af();
  cpu_pop_hl();
  cpu_pop_de();
  a = (uint8_t)(a & ~(1u << 0));
  a = (uint8_t)(a - 0x02);
  return;
  lab_p07_L_523E: ;
  cpu_pop_af();
  a = (uint8_t)(a | (1u << 1));
  cpu_push_af();
  cpu_push_hl();
  lab_p07_L_5243: ;
  p00_L_11D8();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_pop_de();
  set_de(mem_read16(0x84E3));
  cpu_push_de();
  cpu_push_af();
  goto lab_p07_L_520B;
}

/* flash page 7 cpu 0x51BB (offset 0x11BB) */
void p07_L_51BB(void) {
  if (flag_nc()) goto lab_p07_L_51D5;
  if (flag_z()) goto lab_p07_L_51C7;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p07_L_51D9;
  flag_cmp(a, 0x0A);
  if (flag_z()) goto lab_p07_L_51D9;
  lab_p07_L_51C7: ;
  p00_L_2407();
  a = mem_read8(hl());
  flag_cmp(a, 0x72);
  if (flag_nz()) goto lab_p07_L_51D3;
  lab_p07_L_51CF: ;
  e = 0x03;
  goto lab_p07_L_51D9;
  lab_p07_L_51D3: ;
  flag_cmp(a, 0x3A);
  lab_p07_L_51D5: ;
  if (flag_z()) goto lab_p07_L_51CF;
  e = mem_read8(hl());
  e = (uint8_t)(e + 1);
  lab_p07_L_51D9: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  p07_L_5171();
  return;
}

/* flash page 7 cpu 0x522C (offset 0x122C) */
void p07_L_522C(void) {
  set_hl(0x848B);
  b = 0x08;
  p07_L_5231();
  return;
}

/* flash page 7 cpu 0x5231 (offset 0x1231) */
void p07_L_5231(void) {
  a = 0;
  flag_logic(a);
  c = 0x00;
  lab_p07_L_5234: ;
  a = mem_read8(de());
  /* sbc a,(hl) */
  if (flag_nz()) goto lab_p07_L_5239;
  c = (uint8_t)(c + 1);
  lab_p07_L_5239: ;
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_5234;
  return;
}

/* flash page 7 cpu 0x5251 (offset 0x1251) */
void p07_L_5251(void) {
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  b = mem_read8(hl());
  cpu_push_bc();
  b = 0x03;
  p00_L_1830();
  if (flag_z()) goto lab_p07_L_5267;
  p00_L_17B3();
  if (flag_nz()) goto lab_p07_L_527E;
  lab_p07_L_5267: ;
  set_hl((uint16_t)(hl() - 1));
  cpu_push_af();
  a = mem_read8(hl());
  flag_cmp(a, 0x72);
  if (flag_nz()) goto lab_p07_L_5272;
  lab_p07_L_526E: ;
  cpu_pop_af();
  set_hl((uint16_t)(hl() + 1));
  goto lab_p07_L_527E;
  lab_p07_L_5272: ;
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p07_L_526E;
  cpu_pop_af();
  b = mem_read8(hl());
  p00_L_1830();
  if (flag_nz()) goto lab_p07_L_527E;
  b = (uint8_t)(b - 1);
  lab_p07_L_527E: ;
  cpu_push_af();
  cpu_push_hl();
  p00_L_129A();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_af();
  set_de(0x8483);
  mem_write8(de(), a);
  lab_p07_L_528A: ;
  set_hl((uint16_t)(hl() - 1));
  set_de((uint16_t)(de() + 1));
  a = mem_read8(hl());
  mem_write8(de(), a);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_528A;
  set_hl((uint16_t)(hl() - 1));
  cpu_pop_af();
  cpu_pop_bc();
  p00_L_1830();
  if (flag_nz()) goto lab_p07_L_52C6;
  a = mem_read8(0x8484);
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p07_L_52D5;
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p07_L_52D5;
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p07_L_52C1;
  a = mem_read8(0x8485);
  flag_cmp(a, 0x40);
  if (flag_nz()) goto lab_p07_L_52C1;
  set_hl((uint16_t)(hl() - 1));
  p00_L_0B86();
  if (flag_nz()) goto lab_p07_L_52BF;
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p07_L_52BF;
  /* bit 0,(iy) */
  if (flag_nz()) return;
  lab_p07_L_52BF: ;
  /* scf */
  return;
  lab_p07_L_52C1: ;
  a = mem_read8(hl());
  mem_write8(0x848C, a);
  set_hl((uint16_t)(hl() - 1));
  lab_p07_L_52C6: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_52D0;
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_52D5;
  lab_p07_L_52D0: ;
  a = mem_read8(0x8484);
  flag_cmp(a, 0x72);
  lab_p07_L_52D5: ;
  /* scf */
  if (flag_z()) return;
  flag_cmp(a, 0x41);
  return;
}

/* flash page 7 cpu 0x52BB (offset 0x12BB) */
void p07_L_52BB(void) {
  /* rlc b */
  b = mem_read8(hl());
  if (flag_nz()) return;
  /* scf */
  return;
}

/* flash page 7 cpu 0x52DA (offset 0x12DA) */
void p07_L_52DA(void) {
  cpu_push_hl();
  cpu_push_af();
  set_hl(mem_read16(0x982A));
  mem_write16(0x847A, hl());
  set_hl((uint16_t)(hl() + 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) { p00_L_24F5(); return; }
  mem_write16(0x982A, hl());
  a = 0x24;
  mem_write8(0x8479, a);
  p00_rst10();
  if (flag_nc()) goto lab_p07_L_52F7;
  cpu_pop_af();
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  return;
  lab_p07_L_52F7: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  cpu_ex_de_hl();
  p00_L_210A();
  mem_write16(0x84E1, hl());
  cpu_pop_af();
  cpu_pop_bc();
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  p00_L_20F2();
  cpu_pop_hl();
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p07_L_533F;
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  p00_L_23BD();
  cpu_ex_de_hl();
  set_de(mem_read16(0x84E1));
  set_de((uint16_t)(de() + 1));
  p00_L_1B0E();
  lab_p07_L_531E: ;
  cpu_pop_de();
  set_hl(mem_read16(0x84E1));
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), d);
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_5334;
  cpu_pop_af();
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, 0x0D);
  a = 0x0C;
  if (flag_z()) goto lab_p07_L_5333;
  a = 0;
  flag_logic(a);
  lab_p07_L_5333: ;
  mem_write8(hl(), a);
  lab_p07_L_5334: ;
  p00_L_10DD();
  p00_rst10();
  cpu_pop_af();
  mem_write8(hl(), a);
  mem_write8(0x8499, a);
  /* scf */
  return;
  lab_p07_L_533F: ;
  if (flag_z()) goto lab_p07_L_531E;
  cpu_ex_de_hl();
  set_hl(mem_read16(0x84E1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_1FB8();
  goto lab_p07_L_531E;
}

/* flash page 7 cpu 0x534B (offset 0x134B) */
void p07_L_534B(void) {
  a = 0;
  flag_logic(a);
  h = 0x00;
  l = 0x00;
  mem_write16(0x982A, hl());
  mem_write16(0x982C, hl());
  set_hl(mem_read16(0x9822));
  set_de(mem_read16(0x9820));
  cpu_sbc_hl_de();
  if (flag_z()) return;
  if (flag_c()) return;
  cpu_push_hl();
  set_hl(mem_read16(0x9824));
  set_de(mem_read16(0x9822));
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p07_L_538B;
  b = h;
  c = l;
  cpu_ex_de_hl();
  set_de(mem_read16(0x9820));
  lab_p07_L_5374: ;
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_5374;
  lab_p07_L_538B: ;
  set_hl(mem_read16(0x9824));
  cpu_pop_bc();
  cpu_sbc_hl_bc();
  mem_write16(0x9824, hl());
  set_de(mem_read16(0x9820));
  mem_write16(0x9822, de());
  set_de((uint16_t)(de() - 1));
  p00_L_1D58();
  set_hl(mem_read16(0x9826));
  set_de(mem_read16(0x9828));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p07_L_53BE;
  b = h;
  c = l;
  set_hl((uint16_t)(hl() + de()));
  set_de(mem_read16(0x982E));
  mem_write16(0x9826, de());
  /* lddr */
  mem_write16(0x9828, de());
  return;
  lab_p07_L_53BE: ;
  set_hl(mem_read16(0x982E));
  mem_write16(0x9826, hl());
  mem_write16(0x9828, hl());
  return;
}

/* flash page 7 cpu 0x53BB (offset 0x13BB) */
void p07_L_53BB(void) {
  goto lab_p07_L_53BB;
  lab_p07_L_5355: ;
  /* sbc a,b */
  set_hl(mem_read16(0x9822));
  set_de(mem_read16(0x9820));
  cpu_sbc_hl_de();
  if (flag_z()) return;
  if (flag_c()) return;
  cpu_push_hl();
  set_hl(mem_read16(0x9824));
  set_de(mem_read16(0x9822));
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p07_L_538B;
  b = h;
  c = l;
  cpu_ex_de_hl();
  set_de(mem_read16(0x9820));
  lab_p07_L_5374: ;
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_5374;
  lab_p07_L_538B: ;
  set_hl(mem_read16(0x9824));
  cpu_pop_bc();
  cpu_sbc_hl_bc();
  mem_write16(0x9824, hl());
  set_de(mem_read16(0x9820));
  mem_write16(0x9822, de());
  set_de((uint16_t)(de() - 1));
  p00_L_1D58();
  set_hl(mem_read16(0x9826));
  set_de(mem_read16(0x9828));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p07_L_53BE;
  b = h;
  c = l;
  set_hl((uint16_t)(hl() + de()));
  set_de(mem_read16(0x982E));
  mem_write16(0x9826, de());
  /* lddr */
  mem_write16(0x9828, de());
  lab_p07_L_53BB: ;
  if (flag_z()) goto lab_p07_L_5355;
  return;
  lab_p07_L_53BE: ;
  set_hl(mem_read16(0x982E));
  mem_write16(0x9826, hl());
  mem_write16(0x9828, hl());
  return;
}

/* flash page 7 cpu 0x53C8 (offset 0x13C8) */
void p07_L_53C8(void) {
  p00_L_2040();
  if (flag_z()) goto lab_p07_L_53D1;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p07_L_53DD;
  lab_p07_L_53D1: ;
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  e = (uint8_t)(e + 1);
  d = 0x00;
  goto lab_p07_L_53E0;
  lab_p07_L_53DD: ;
  set_de(0x0009);
  lab_p07_L_53E0: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  return;
}

/* flash page 7 cpu 0x53E4 (offset 0x13E4) */
void p07_L_53E4(void) {
  a = mem_read8(de());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_53EE;
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  set_de((uint16_t)(de() - 1));
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_544B;
  lab_p07_L_53EE: ;
  mem_write16(0x84E1, de());
  cpu_ex_de_hl();
  a = 0x01;
  p00_L_210A();
  set_de((uint16_t)(de() - 1));
  set_de((uint16_t)(de() - 1));
  cpu_ex_de_hl();
  p00_L_23BD();
  set_hl(mem_read16(0x84E1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  p00_L_1B0E();
  cpu_ex_de_hl();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + hl()));
  set_de(mem_read16(0x84E1));
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  lab_p07_L_5414: ;
  cpu_pop_de();
  cpu_push_hl();
  set_hl(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_bc();
  cpu_push_hl();
  set_de(mem_read16(0x84E1));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p07_L_5446;
  h = b;
  l = c;
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  cpu_ex_de_hl();
  set_hl(0x0FF6);
  p00_L_1183();
  cpu_pop_hl();
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_de();
  cpu_push_de();
  cpu_push_hl();
  cpu_ex_de_hl();
  p00_L_1183();
  cpu_pop_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 3)));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 2)));
  goto lab_p07_L_5414;
  lab_p07_L_5446: ;
  cpu_pop_hl();
  set_de(mem_read16(0x84E1));
  lab_p07_L_544B: ;
  cpu_push_de();
  p00_L_22FC();
  p00_rst10();
  a = (uint8_t)(a + 0x0C);
  mem_write8(hl(), a);
  p07_L_5453();
  return;
}

/* flash page 7 cpu 0x5453 (offset 0x1453) */
void p07_L_5453(void) {
  mem_write8(0x8478, a);
  p00_L_233D();
  cpu_pop_de();
  return;
}

/* flash page 7 cpu 0x545B (offset 0x145B) */
void p07_L_545B(void) {
  b = 0x06;
  d = 0xAF;
  p00_L_17CE();
  if (flag_z()) goto lab_p07_L_5468;
  b = 0x01;
  d = 0xB1;
  lab_p07_L_5468: ;
  c = 0xFA;
  goto lab_p07_L_547B;
  lab_p07_L_547B: ;
  l = 0x00;
  p00_L_18B7();
  if (flag_z()) goto lab_p07_L_548B;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x43);
  if (flag_z()) goto lab_p07_L_548B;
  l = 0x06;
  lab_p07_L_548B: ;
  h = 0x05;
  cpu_push_bc();
  a = d;
  goto lab_p07_L_54CF;
  lab_p07_L_54CF: ;
  a = (uint8_t)(a + c);
  e = a;
  /* di */
  p07_L_54D2();
  return;
}

/* flash page 7 cpu 0x546C (offset 0x146C) */
void p07_L_546C(void) {
  b = 0x06;
  d = 0x8B;
  p00_L_17CE();
  if (flag_z()) goto lab_p07_L_5479;
  b = 0x01;
  d = 0xAB;
  lab_p07_L_5479: ;
  c = 0x06;
  l = 0x00;
  p00_L_18B7();
  if (flag_z()) goto lab_p07_L_548B;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x43);
  if (flag_z()) goto lab_p07_L_548B;
  l = 0x06;
  lab_p07_L_548B: ;
  h = 0x05;
  cpu_push_bc();
  a = d;
  goto lab_p07_L_54CF;
  lab_p07_L_54CF: ;
  a = (uint8_t)(a + c);
  e = a;
  /* di */
  p07_L_54D2();
  return;
}

/* flash page 7 cpu 0x5491 (offset 0x1491) */
void p07_L_5491(void) {
  a = mem_read8((uint16_t)(ix + 0x01));
  /* sub (ix) */
  a = (uint8_t)(a - 1);
  b = a;
  c = 0x08;
  a = mem_read8(ix);
  if (flag_nz()) { p07_L_54BD(); return; }
  p07_L_54A5();
  e = a;
  return;
}

/* flash page 7 cpu 0x54A5 (offset 0x14A5) */
void p07_L_54A5(void) {
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + 0x80);
  return;
}

/* flash page 7 cpu 0x54AB (offset 0x14AB) */
void p07_L_54AB(void) {
  cpu_push_bc();
  cpu_push_af();
  a = mem_read8(0x8478);
  a = (uint8_t)(a - 0x20);
  l = a;
  cpu_pop_af();
  d = a;
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 2)));
  cpu_pop_bc();
  p07_L_54BA();
  return;
}

/* flash page 7 cpu 0x54BA (offset 0x14BA) */
void p07_L_54BA(void) {
  cpu_push_bc();
  p07_L_54BB();
  return;
}

/* flash page 7 cpu 0x54BB (offset 0x14BB) */
void p07_L_54BB(void) {
  goto lab_p07_L_54CF;
  lab_p07_L_54CF: ;
  a = (uint8_t)(a + c);
  e = a;
  /* di */
  p07_L_54D2();
  return;
}

/* flash page 7 cpu 0x54BD (offset 0x14BD) */
void p07_L_54BD(void) {
  cpu_push_bc();
  p07_L_54A5();
  d = a;
  h = 0x07;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x56);
  a = d;
  if (flag_nz()) goto lab_p07_L_54CD;
  h = (uint8_t)(h + 1);
  lab_p07_L_54CD: ;
  l = 0x00;
  a = (uint8_t)(a + c);
  e = a;
  /* di */
  p07_L_54D2();
  return;
}

/* flash page 7 cpu 0x54D2 (offset 0x14D2) */
void p07_L_54D2(void) {
  cpu_push_hl();
  a = 0x20;
  a = (uint8_t)(a + l);
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 4)));
  p07_L_54DE();
  return;
}

/* flash page 7 cpu 0x54DE (offset 0x14DE) */
void p07_L_54DE(void) {
  lab_p07_L_54DE: ;
  c = a;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  a = e;
  p00_lcd_cmd_07();
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p00_lcd_cmd_05();
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  cpu_pop_hl();
  cpu_push_hl();
  b = h;
  set_hl(0x8451);
  lab_p07_L_54FB: ;
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_54FB;
  a = d;
  p00_lcd_cmd_07();
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p00_lcd_cmd_05();
  cpu_pop_hl();
  cpu_push_hl();
  b = h;
  set_hl(0x8451);
  lab_p07_L_5516: ;
  set_hl((uint16_t)(hl() + 1));
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p07_L_5553;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p07_L_5528;
  a = mem_read8(0x847A);
  goto lab_p07_L_5531;
  lab_p07_L_5528: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p07_L_5553;
  a = mem_read8(0x847B);
  lab_p07_L_5531: ;
  cpu_push_bc();
  b = a;
  /* and (hl) */
  mem_write8(hl(), a);
  p00_lcd_cmd_07();
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  a = a | b;
  flag_logic(a);
  a = a ^ b;
  flag_logic(a);
  /* or (hl) */
  mem_write8(hl(), a);
  p00_lcd_cmd_05();
  a = c;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  a = mem_read8(hl());
  cpu_pop_bc();
  goto lab_p07_L_5554;
  lab_p07_L_5553: ;
  a = mem_read8(hl());
  lab_p07_L_5554: ;
  p00_lcd_busy_wait();
  lcd_write_data(); /* ti_lcd_op_write(a) */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_5516;
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 4)));
  a = c;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p07_L_557B;
  set_hl(0x8479);
  cpu_cp_hl();
  if (flag_z()) goto lab_p07_L_5580;
  a = (uint8_t)(a + 1);
  cpu_cp_hl();
  if (flag_nz()) goto lab_p07_L_5578;
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 4)));
  lab_p07_L_5578: ;
  goto lab_p07_L_54DE;
  lab_p07_L_557B: ;
  a = (uint8_t)(a + 1);
  flag_cmp(a, 0x2C);
  if (flag_nz()) goto lab_p07_L_5578;
  lab_p07_L_5580: ;
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_z()) goto lab_p07_L_558F;
  cpu_push_bc();
  a = d;
  a = (uint8_t)(a + c);
  d = a;
  a = e;
  a = (uint8_t)(a + c);
  e = a;
  p07_L_54D2();
  return;
  lab_p07_L_558F: ;
  /* ei */
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 2)));
  return;
}

/* flash page 7 cpu 0x5595 (offset 0x1595) */
void p07_L_5595(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 6)) == 0);
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 6)));
  if (flag_nz()) return;
  p00_L_10DD();
  p00_L_1295();
  set_hl(0x55C2);
  p00_L_25A2();
  lab_p07_L_55AA: ;
  a = 0x16;
  mem_write8(0x8478, a);
  a = 0;
  flag_logic(a);
  p07_L_5128();
  if (flag_c()) goto lab_p07_L_55BF;
  p00_L_19ED();
  if (flag_c()) goto lab_p07_L_55AA;
  p00_L_1F2C();
  goto lab_p07_L_55AA;
  lab_p07_L_55BF: ;
  p00_L_25C8();
  p00_L_1135();
  return;
}

/* flash page 7 cpu 0x55C6 (offset 0x15C6) */
void p07_L_55C6(void) {
  a = 0x01;
  mem_write8(0x970E, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x970F, a);
  mem_write8(0x9710, a);
  set_de(0x9711);
  cpu_push_de();
  p00_L_1295();
  a = 0x5D;
  mem_write8(0x8479, a);
  lab_p07_L_55DE: ;
  set_hl(0x5627);
  p00_L_25A2();
  p00_L_2222();
  p00_rst10();
  if (flag_c()) goto lab_p07_L_55F4;
  p00_L_1F55();
  if (flag_z()) goto lab_p07_L_55FD;
  p07_L_66B6();
  goto lab_p07_L_55FA;
  lab_p07_L_55F4: ;
  set_hl(0x0000);
  p00_L_1C46();
  lab_p07_L_55FA: ;
  p00_L_22FC();
  lab_p07_L_55FD: ;
  p00_L_25C8();
  a = mem_read8(0x847A);
  cpu_push_af();
  p00_L_1295();
  cpu_pop_af();
  mem_write8(0x8478, a);
  cpu_pop_de();
  set_hl(0x8478);
  p00_L_118B();
  cpu_push_de();
  set_hl(0x970E);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_L_2176();
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0x06);
  if (flag_c()) goto lab_p07_L_55DE;
  cpu_pop_hl();
  mem_write8(hl(), 0x71);
  return;
}

/* flash page 7 cpu 0x55FF (offset 0x15FF) */
void p07_L_55FF(void) {
  goto lab_p07_L_55FF;
  lab_p07_L_55DE: ;
  set_hl(0x5627);
  p00_L_25A2();
  p00_L_2222();
  p00_rst10();
  if (flag_c()) goto lab_p07_L_55F4;
  p00_L_1F55();
  if (flag_z()) goto lab_p07_L_55FD;
  p07_L_66B6();
  goto lab_p07_L_55FA;
  lab_p07_L_55F4: ;
  set_hl(0x0000);
  p00_L_1C46();
  lab_p07_L_55FA: ;
  p00_L_22FC();
  lab_p07_L_55FD: ;
  p00_L_25C8();
  lab_p07_L_55FF: ;
  h = (uint8_t)(h - 1);
  a = mem_read8(0x847A);
  cpu_push_af();
  p00_L_1295();
  cpu_pop_af();
  mem_write8(0x8478, a);
  cpu_pop_de();
  set_hl(0x8478);
  p00_L_118B();
  cpu_push_de();
  set_hl(0x970E);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_L_2176();
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0x06);
  if (flag_c()) goto lab_p07_L_55DE;
  cpu_pop_hl();
  mem_write8(hl(), 0x71);
  return;
}

/* flash page 7 cpu 0x5646 (offset 0x1646) */
void p07_L_5646(void) {
  cpu_push_af();
  p00_L_19C5();
  set_de(mem_read16(0x982E));
  set_hl(mem_read16(0x9830));
  cpu_pop_bc();
  c = a;
  cpu_push_bc();
  set_de((uint16_t)(de() + 1));
  p07_L_5655();
  return;
}

/* flash page 7 cpu 0x5655 (offset 0x1655) */
void p07_L_5655(void) {
  a = 0;
  flag_logic(a);
  b = a;
  lab_p07_L_5657: ;
  a = mem_read8(hl());
  p00_L_2407();
  a = a & 0x1F;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p07_L_56AF;
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_bc();
  cpu_push_bc();
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p07_L_566D;
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p07_L_56A7;
  goto lab_p07_L_567F;
  lab_p07_L_566D: ;
  flag_cmp(a, 0x17);
  if (flag_nz()) goto lab_p07_L_5676;
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p07_L_56A7;
  goto lab_p07_L_567F;
  lab_p07_L_5676: ;
  a = b;
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p07_L_56A7;
  flag_cmp(a, 0x17);
  if (flag_z()) goto lab_p07_L_56A7;
  lab_p07_L_567F: ;
  a = c;
  c = mem_read8(hl());
  c = (uint8_t)(c + 1);
  cpu_cp_hl();
  if (flag_nz()) goto lab_p07_L_56A9;
  b = a;
  p00_L_182A();
  if (flag_nz()) goto lab_p07_L_568C;
  b = (uint8_t)(b - 1);
  lab_p07_L_568C: ;
  cpu_push_de();
  cpu_push_hl();
  set_de(0x8478);
  lab_p07_L_5691: ;
  set_hl((uint16_t)(hl() - 1));
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  cpu_cp_hl();
  if (flag_nz()) goto lab_p07_L_56A3;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_5691;
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  mem_write8(0x8481, a);
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  goto lab_p07_L_56F8;
  lab_p07_L_56A3: ;
  cpu_pop_hl();
  cpu_pop_de();
  goto lab_p07_L_56A9;
  lab_p07_L_56A7: ;
  c = mem_read8(hl());
  c = (uint8_t)(c + 1);
  lab_p07_L_56A9: ;
  a = 0;
  flag_logic(a);
  b = a;
  cpu_sbc_hl_bc();
  goto lab_p07_L_5657;
  lab_p07_L_56AF: ;
  cpu_pop_de();
  return;
  lab_p07_L_56F8: ;
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  mem_write8(0x8478, a);
  return;
}

/* flash page 7 cpu 0x56B1 (offset 0x16B1) */
void p07_L_56B1(void) {
  goto lab_p07_L_56B1;
  lab_p07_L_563D: ;
  a = 0x01;
  cpu_push_af();
  p00_L_19C5();
  a = (uint8_t)(a + 1);
  goto lab_p07_L_564A;
  lab_p07_L_564A: ;
  set_de(mem_read16(0x982E));
  set_hl(mem_read16(0x9830));
  cpu_pop_bc();
  c = a;
  cpu_push_bc();
  set_de((uint16_t)(de() + 1));
  p07_L_5655();
  return;
  lab_p07_L_56B1: ;
  p00_L_182A();
  if (flag_z()) goto lab_p07_L_563D;
  set_de(mem_read16(0x9830));
  a = mem_read8(0x8479);
  flag_cmp(a, 0x24);
  if (flag_nz()) goto lab_p07_L_56CB;
  set_hl(mem_read16(0x982E));
  set_de(mem_read16(0x9826));
  goto lab_p07_L_56CE;
  lab_p07_L_56CB: ;
  set_hl(0xFE66);
  lab_p07_L_56CE: ;
  set_de((uint16_t)(de() + 1));
  a = 0;
  flag_logic(a);
  b = a;
  lab_p07_L_56D1: ;
  a = mem_read8(hl());
  p00_L_2407();
  a = a & 0x1F;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) return;
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(0x8479);
  cpu_cp_hl();
  if (flag_z()) goto lab_p07_L_56E8;
  lab_p07_L_56E1: ;
  c = 0x03;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  goto lab_p07_L_56D1;
  lab_p07_L_56E8: ;
  cpu_push_hl();
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(0x847A);
  cpu_cp_hl();
  if (flag_nz()) goto lab_p07_L_5706;
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(0x847B);
  cpu_cp_hl();
  if (flag_nz()) goto lab_p07_L_5706;
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  mem_write8(0x8478, a);
  return;
  lab_p07_L_5706: ;
  cpu_pop_hl();
  a = mem_read8(0x8479);
  goto lab_p07_L_56E1;
}

/* flash page 7 cpu 0x570C (offset 0x170C) */
void p07_L_570C(void) {
  p00_L_2F6D();
  p00_L_2F73();
  p00_L_21E5();
  p00_L_2F79();
  p00_L_2F6D();
  p00_L_2F7F();
  if (flag_z()) goto lab_p07_L_572E;
  mem_write16(0x965D, bc());
  flag_cmp(a, 0x11);
  if (flag_nz()) goto lab_p07_L_572B;
  p00_L_2F7F();
  lab_p07_L_572B: ;
  if (flag_nz()) { p00_L_24D5(); return; }
  lab_p07_L_572E: ;
  p00_L_21E5();
  p00_L_2315();
  p07_L_5769();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  mem_write16(0x8485, de());
  p00_L_22FC();
  p00_L_19E7();
  if (flag_nc()) goto lab_p07_L_5766;
  set_hl(mem_read16(0x8485));
  p00_L_1CBB();
  p00_L_240B();
  mem_write8(hl(), 0x01);
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0xBB);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x6D);
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  cpu_push_de();
  p00_L_2315();
  cpu_pop_de();
  p07_L_5786();
  p00_L_21A4();
  return;
  lab_p07_L_5766: ;
  p00_L_24B9();
  return;
}

/* flash page 7 cpu 0x5760 (offset 0x1760) */
void p07_L_5760(void) {
  /* add a,(hl) */
  d = a;
  p00_L_21A4();
  return;
}

/* flash page 7 cpu 0x5769 (offset 0x1769) */
void p07_L_5769(void) {
  p07_L_5886();
  set_de(0x0000);
  p07_L_576F();
  return;
}

/* flash page 7 cpu 0x576F (offset 0x176F) */
void p07_L_576F(void) {
  lab_p07_L_576F: ;
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) return;
  set_bc((uint16_t)(bc() - 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p07_L_576F;
  p07_L_586D();
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p07_L_586D();
  set_de((uint16_t)(de() + 1));
  set_bc((uint16_t)(bc() - 1));
  goto lab_p07_L_576F;
}

/* flash page 7 cpu 0x5786 (offset 0x1786) */
void p07_L_5786(void) {
  cpu_push_de();
  p07_L_5886();
  cpu_pop_de();
  p07_L_578B();
  return;
}

/* flash page 7 cpu 0x578B (offset 0x178B) */
void p07_L_578B(void) {
  lab_p07_L_578B: ;
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) return;
  set_bc((uint16_t)(bc() - 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p07_L_578B;
  cpu_push_de();
  p07_L_586D();
  d = a;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p07_L_586D();
  e = a;
  p07_L_5865();
  cpu_pop_de();
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  set_bc((uint16_t)(bc() - 1));
  goto lab_p07_L_578B;
}

/* flash page 7 cpu 0x57AA (offset 0x17AA) */
void p07_L_57AA(void) {
  p00_L_240E();
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0xBB);
  if (flag_nz()) { p00_L_24FD(); return; }
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0x6D);
  if (flag_nz()) goto lab_p07_L_581C;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  cpu_push_bc();
  cpu_pop_de();
  cpu_push_de();
  set_hl(0x2000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) { p00_L_24FD(); return; }
  cpu_ex_de_hl();
  p00_L_23BD();
  cpu_pop_hl();
  cpu_push_hl();
  set_de(0x9D95);
  p00_L_1B0E();
  cpu_pop_hl();
  mem_write16(0x89EC, hl());
  cpu_pop_hl();
  set_de(0x9D95);
  set_bc(mem_read16(0x89EC));
  set_hl((uint16_t)(hl() + bc()));
  while (bc() != 0) { cpu_ldi(); }
  lab_p07_L_57E7: ;
  p00_L_24A9();
  if (flag_nz()) goto lab_p07_L_57F6;
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  lab_p07_L_57F6: ;
  set_hl(0x5848);
  p00_L_25A2();
  p07_L_5845();
  p00_L_25C8();
  p00_L_24A9();
  if (flag_nz()) goto lab_p07_L_580C;
  cpu_pop_af();
  a = a & 0x01;
  flag_logic(a);
  hw_out(PORT_SE_STATUS, a);
  lab_p07_L_580C: ;
  set_de(mem_read16(0x89EC));
  set_hl(0x0000);
  mem_write16(0x89EC, hl());
  set_hl(0x9D95);
  p00_L_1FB8();
  return;
  lab_p07_L_581C: ;
  p00_rst18();
  p07_L_5769();
  set_hl(0x2000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) { p00_L_24FD(); return; }
  cpu_ex_de_hl();
  cpu_push_hl();
  p00_L_23BD();
  cpu_pop_hl();
  cpu_push_hl();
  set_de(0x9D95);
  p00_L_1B0E();
  cpu_pop_hl();
  mem_write16(0x89EC, hl());
  p00_L_219B();
  set_de(0x9D95);
  p07_L_5786();
  goto lab_p07_L_57E7;
}

/* flash page 7 cpu 0x57BB (offset 0x17BB) */
void p07_L_57BB(void) {
  l = l;
  if (flag_nz()) goto lab_p07_L_581C;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  cpu_push_bc();
  cpu_pop_de();
  cpu_push_de();
  set_hl(0x2000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) { p00_L_24FD(); return; }
  cpu_ex_de_hl();
  p00_L_23BD();
  cpu_pop_hl();
  cpu_push_hl();
  set_de(0x9D95);
  p00_L_1B0E();
  cpu_pop_hl();
  mem_write16(0x89EC, hl());
  cpu_pop_hl();
  set_de(0x9D95);
  set_bc(mem_read16(0x89EC));
  set_hl((uint16_t)(hl() + bc()));
  while (bc() != 0) { cpu_ldi(); }
  lab_p07_L_57E7: ;
  p00_L_24A9();
  if (flag_nz()) goto lab_p07_L_57F6;
  a = hw_in(PORT_SE_STATUS);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  p00_L_0BAF();
  lab_p07_L_57F6: ;
  set_hl(0x5848);
  p00_L_25A2();
  p07_L_5845();
  p00_L_25C8();
  p00_L_24A9();
  if (flag_nz()) goto lab_p07_L_580C;
  cpu_pop_af();
  a = a & 0x01;
  flag_logic(a);
  hw_out(PORT_SE_STATUS, a);
  lab_p07_L_580C: ;
  set_de(mem_read16(0x89EC));
  set_hl(0x0000);
  mem_write16(0x89EC, hl());
  set_hl(0x9D95);
  p00_L_1FB8();
  return;
  lab_p07_L_581C: ;
  p00_rst18();
  p07_L_5769();
  set_hl(0x2000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) { p00_L_24FD(); return; }
  cpu_ex_de_hl();
  cpu_push_hl();
  p00_L_23BD();
  cpu_pop_hl();
  cpu_push_hl();
  set_de(0x9D95);
  p00_L_1B0E();
  cpu_pop_hl();
  mem_write16(0x89EC, hl());
  p00_L_219B();
  set_de(0x9D95);
  p07_L_5786();
  goto lab_p07_L_57E7;
}

/* flash page 7 cpu 0x5845 (offset 0x1845) */
void p07_L_5845(void) {
  os_banked_call(0x9D95);
  return;
}

/* flash page 7 cpu 0x5857 (offset 0x1857) */
void p07_L_5857(void) {
  /* nop */
  /* nop */
  mem_write16(0x89EC, hl());
  set_hl(0x9D95);
  p00_L_1FB8();
  p00_L_2565();
  return;
}

/* flash page 7 cpu 0x5865 (offset 0x1865) */
void p07_L_5865(void) {
  cpu_push_hl();
  a = d;
  p00_L_12B9();
  a = (uint8_t)(a + e);
  cpu_pop_hl();
  return;
}

/* flash page 7 cpu 0x586D (offset 0x186D) */
void p07_L_586D(void) {
  flag_cmp(a, 0x30);
  if (flag_c()) { p00_L_24D5(); return; }
  flag_cmp(a, 0x3A);
  if (flag_nc()) goto lab_p07_L_5879;
  a = (uint8_t)(a - 0x30);
  return;
  lab_p07_L_5879: ;
  flag_cmp(a, 0x41);
  if (flag_c()) { p00_L_24D5(); return; }
  flag_cmp(a, 0x47);
  if (flag_nc()) { p00_L_24D5(); return; }
  a = (uint8_t)(a - 0x37);
  return;
}

/* flash page 7 cpu 0x5886 (offset 0x1886) */
void p07_L_5886(void) {
  p00_L_240E();
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_bc((uint16_t)(bc() - 1));
  set_bc((uint16_t)(bc() - 1));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0xBB);
  lab_p07_L_5893: ;
  if (flag_nz()) { p00_L_24FD(); return; }
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0x6C);
  if (flag_nz()) goto lab_p07_L_5893;
  set_hl((uint16_t)(hl() + 1));
  return;
}

/* flash page 7 cpu 0x589E (offset 0x189E) */
void p07_L_589E(void) {
  cpu_push_af();
  cpu_push_hl();
  cpu_push_af();
  cpu_push_hl();
  p00_L_2F85();
  set_hl(0x0006);
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_af();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_23FC();
  if (flag_nc()) goto lab_p07_L_58B6;
  a = (uint8_t)(a + 1);
  lab_p07_L_58B6: ;
  set_de(0x8478);
  cpu_push_bc();
  p00_L_2F8B();
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p07_L_5939;
  p00_L_1100();
  p00_L_10E6();
  p00_L_2F91();
  p00_L_19C5();
  c = a;
  a = mem_read8(0x8478);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p07_L_58E7;
  p00_L_1830();
  if (flag_nz()) goto lab_p07_L_58E8;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x06);
  if (flag_nc()) goto lab_p07_L_58E7;
  c = 0x03;
  goto lab_p07_L_58E8;
  lab_p07_L_58E7: ;
  c = (uint8_t)(c + 1);
  lab_p07_L_58E8: ;
  set_hl(0x8483);
  set_hl(0x848E);
  a = mem_read8(hl());
  b = 0x06;
  lab_p07_L_58F1: ;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_58F1;
  a = mem_read8(0x8478);
  p00_L_2495();
  if (flag_nz()) goto lab_p07_L_58FF;
  a = c;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  lab_p07_L_58FF: ;
  set_de(0x8479);
  b = c;
  lab_p07_L_5903: ;
  a = mem_read8(de());
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_5903;
  cpu_push_hl();
  lab_p07_L_590D: ;
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_5918;
  a = 0x00;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  goto lab_p07_L_590D;
  lab_p07_L_5918: ;
  cpu_pop_hl();
  cpu_pop_bc();
  set_bc(0x848E);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  p00_L_113F();
  p00_L_10EF();
  cpu_pop_bc();
  a = mem_read8(0x85D0);
  p00_L_2495();
  if (flag_z()) goto lab_p07_L_5933;
  set_bc(0x0009);
  lab_p07_L_5933: ;
  mem_write16(0x83F5, bc());
  goto lab_p07_L_596A;
  lab_p07_L_5939: ;
  p00_L_1100();
  p00_L_10E6();
  p00_L_1037();
  set_bc(0x0003);
  set_hl(0x847E);
  p00_L_2495();
  if (flag_nz()) goto lab_p07_L_594F;
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  lab_p07_L_594F: ;
  set_de(0x8479);
  while (bc() != 0) { cpu_ldi(); }
  a = 0;
  flag_logic(a);
  b = 0x07;
  lab_p07_L_5957: ;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_5957;
  p00_L_19ED();
  if (flag_c()) goto lab_p07_L_5963;
  p00_L_1F2C();
  lab_p07_L_5963: ;
  p00_L_113F();
  p00_L_10EF();
  cpu_pop_bc();
  lab_p07_L_596A: ;
  a = mem_read8(0x847D);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_5976;
  set_hl(mem_read16(0x9832));
  mem_write16(0x847B, hl());
  lab_p07_L_5976: ;
  p00_L_19F8();
  cpu_push_hl();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 7 cpu 0x598E (offset 0x198E) */
void p07_L_598E(void) {
  set_hl(mem_read16(0x858D));
  set_de(0x5ADE);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  return;
}

/* flash page 7 cpu 0x5998 (offset 0x1998) */
void p07_L_5998(void) {
  b = a;
  p07_L_598E();
  if (flag_nz()) return;
  flag_cmp(a, 0x40);
  if (flag_c()) goto lab_p07_L_59B1;
  flag_cmp(a, 0x5A);
  if (flag_nc()) goto lab_p07_L_59B1;
  a = mem_read8(0x859A);
  flag_cmp(a, b);
  a = b;
  if (flag_nz()) return;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p07_L_59B1;
  flag_cmp(a, a);
  return;
  lab_p07_L_59B1: ;
  a = a | 0x01;
  flag_logic(a);
  a = b;
  return;
}

/* flash page 7 cpu 0x59B5 (offset 0x19B5) */
void p07_L_59B5(void) {
  p07_L_59BB();
  p00_L_2F49();
  return;
}

/* flash page 7 cpu 0x59BB (offset 0x19BB) */
void p07_L_59BB(void) {
  set_hl(0x262D);
  a = 0x10;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  cpu_ex_de_hl();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  /* scf */
  p07_L_59CD();
  return;
}

/* flash page 7 cpu 0x59CD (offset 0x19CD) */
void p07_L_59CD(void) {
  cpu_pop_hl();
  cpu_push_af();
  cpu_push_de();
  p07_L_59FE();
  p07_L_5A3B();
  set_hl(0x5AC5);
  p00_L_07CC();
  p07_L_5ABB();
  cpu_pop_hl();
  p00_L_3C87();
  p00_L_3D1D();
  p00_L_03A0();
  cpu_pop_af();
  if (flag_c()) p00_L_03B8();
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  return;
}

/* flash page 7 cpu 0x59FE (offset 0x19FE) */
void p07_L_59FE(void) {
  mem_write16(0x85C4, hl());
  set_hl(0x85DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = a | a;
  flag_logic(a);
  p00_L_076B();
  set_hl(0x85DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  set_hl(mem_read16(0x844B));
  mem_write16(0x85C0, hl());
  a = mem_read8(0x89F5);
  a = a & 0x10;
  flag_logic(a);
  mem_write8(0x85C2, a);
  a = mem_read8(0x8A02);
  a = a & 0x70;
  flag_logic(a);
  mem_write8(0x85C3, a);
  set_hl(0x858D);
  set_de(0x859B);
  set_bc(0x000E);
  while (bc() != 0) { cpu_ldi(); }
  a = mem_read8(0x89FD);
  mem_write8(de(), a);
  set_hl(0x96F4);
  set_de(0x85C8);
  p00_L_1185();
  return;
}

/* flash page 7 cpu 0x5A3B (offset 0x1A3B) */
void p07_L_5A3B(void) {
  set_hl(0x84C7);
  mem_write16(0x96F4, hl());
  mem_write16(0x96F6, hl());
  p00_L_12A2();
  set_hl(0x84D0);
  mem_write16(0x96F8, hl());
  mem_write16(0x96FA, hl());
  return;
}

/* flash page 7 cpu 0x5A51 (offset 0x1A51) */
void p07_L_5A51(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 1)) == 0);
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 1)));
  p07_L_5A59();
  return;
}

/* flash page 7 cpu 0x5A59 (offset 0x1A59) */
void p07_L_5A59(void) {
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 5)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  cpu_push_af();
  cpu_push_hl();
  p07_L_5ABB();
  p00_L_3D1D();
  set_hl(0x89F5);
  a = mem_read8(0x85C2);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 4)));
  /* or (hl) */
  mem_write8(hl(), a);
  a = mem_read8(0x8A02);
  a = a & 0x8F;
  flag_logic(a);
  set_hl(0x85C3);
  /* or (hl) */
  mem_write8(0x8A02, a);
  set_hl(mem_read16(0x85C0));
  mem_write16(0x844B, hl());
  set_hl(0x85C8);
  set_de(0x96F4);
  p00_L_1185();
  set_hl(0x859B);
  set_de(0x858D);
  set_bc(0x000E);
  while (bc() != 0) { cpu_ldi(); }
  a = mem_read8(hl());
  mem_write8(0x89FD, a);
  set_hl(0x8478);
  b = 0x0B;
  lab_p07_L_5AA2: ;
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  cpu_push_de();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_5AA2;
  cpu_push_hl();
  /* scf */
  p00_L_076B();
  cpu_pop_hl();
  b = 0x0B;
  lab_p07_L_5AB1: ;
  cpu_pop_de();
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), e);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_5AB1;
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 7 cpu 0x5ABB (offset 0x1ABB) */
void p07_L_5ABB(void) {
  set_hl(mem_read16(0x97A6));
  l = (uint8_t)(l - 1);
  h = 0x00;
  mem_write16(0x844B, hl());
  return;
}

/* flash page 7 cpu 0x5AD8 (offset 0x1AD8) */
void p07_L_5AD8(void) {
  cpu_pop_hl();
  mem_write16(0x85C4, hl());
  goto lab_p07_L_5B0B;
  lab_p07_L_5B02: ;
  set_hl(mem_read16(0x85C4));
  os_jp_hl();
  return;
  lab_p07_L_5B0B: ;
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  set_hl(mem_read16(0x96F4));
  set_de(mem_read16(0x96F6));
  p00_L_192A();
  if (flag_nz()) goto lab_p07_L_5B33;
  set_hl(mem_read16(0x96FA));
  set_de(mem_read16(0x96F8));
  p00_L_192A();
  if (flag_nz()) goto lab_p07_L_5B36;
  a = 0x05;
  mem_write8(0x8444, a);
  a = a | a;
  flag_logic(a);
  goto lab_p07_L_5B02;
  lab_p07_L_5B33: ;
  p00_L_31B3();
  lab_p07_L_5B36: ;
  p00_L_3D1D();
  p00_L_36B7();
  set_hl(0x84C7);
  p00_L_12A2();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  return;
}

/* flash page 7 cpu 0x5ADE (offset 0x1ADE) */
void p07_L_5ADE(void) {
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p07_L_5B06;
  p00_L_30C3();
  set_hl(mem_read16(0x96F6));
  a = 0;
  flag_logic(a);
  mem_write8(hl(), a);
  set_hl(0x84C7);
  set_de(0x8479);
  p00_L_117F();
  set_hl(mem_read16(0x96F6));
  set_de(0x84C7);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p07_L_5B02;
  a = l;
  mem_write8(0x8478, a);
  /* scf */
  lab_p07_L_5B02: ;
  set_hl(mem_read16(0x85C4));
  os_jp_hl();
  return;
  lab_p07_L_5B06: ;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p07_L_5B47;
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  set_hl(mem_read16(0x96F4));
  set_de(mem_read16(0x96F6));
  p00_L_192A();
  if (flag_nz()) goto lab_p07_L_5B33;
  set_hl(mem_read16(0x96FA));
  set_de(mem_read16(0x96F8));
  p00_L_192A();
  if (flag_nz()) goto lab_p07_L_5B36;
  a = 0x05;
  mem_write8(0x8444, a);
  a = a | a;
  flag_logic(a);
  goto lab_p07_L_5B02;
  lab_p07_L_5B33: ;
  p00_L_31B3();
  lab_p07_L_5B36: ;
  p00_L_3D1D();
  p00_L_36B7();
  set_hl(0x84C7);
  p00_L_12A2();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  return;
  lab_p07_L_5B47: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 5)) == 0);
  if (flag_nz()) { p00_L_31B9(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 1)) == 0);
  if (flag_nz()) { p00_L_31B9(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 1)) == 0);
  if (flag_nz()) return;
  cpu_push_af();
  p07_L_4474();
  cpu_pop_bc();
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_5B64;
  a = e;
  lab_p07_L_5B64: ;
  flag_cmp(a, 0xEB);
  if (flag_z()) goto lab_p07_L_5B97;
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p07_L_5B86;
  flag_cmp(a, 0xAA);
  if (flag_z()) goto lab_p07_L_5B97;
  flag_cmp(a, 0x5F);
  if (flag_z()) goto lab_p07_L_5B97;
  flag_cmp(a, 0x41);
  if (flag_c()) return;
  flag_cmp(a, 0x5C);
  if (flag_c()) goto lab_p07_L_5B86;
  flag_cmp(a, 0x64);
  if (flag_nc()) return;
  flag_cmp(a, 0x62);
  if (flag_nz()) goto lab_p07_L_5B86;
  a = e;
  flag_cmp(a, 0x01);
  if (flag_z()) return;
  lab_p07_L_5B86: ;
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p00_L_03A0();
  a = b;
  p00_L_30E7();
  a = a | a;
  flag_logic(a);
  return;
  lab_p07_L_5B97: ;
  set_hl(0x5B9F);
  mem_write16(0x858D, hl());
  goto lab_p07_L_5B86;
}

/* flash page 7 cpu 0x5BD7 (offset 0x1BD7) */
void p07_L_5BD7(void) {
  p07_L_5BDB();
  return;
}

/* flash page 7 cpu 0x5BDB (offset 0x1BDB) */
void p07_L_5BDB(void) {
  set_hl(0x2633);
  cpu_push_af();
  a = 0x0E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  cpu_pop_af();
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  p07_L_59CD();
  if (flag_nc()) goto lab_p07_L_5BFA;
  lab_p07_L_5BF0: ;
  p07_L_5C8A();
  if (flag_nc()) goto lab_p07_L_5C31;
  p07_L_5AD8();
  if (flag_c()) goto lab_p07_L_5BF0;
  lab_p07_L_5BFA: ;
  set_hl(mem_read16(0x9706));
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p07_L_5C05;
  mem_write8(hl(), 0x05);
  lab_p07_L_5C05: ;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x49);
  if (flag_z()) goto lab_p07_L_5C20;
  flag_cmp(a, 0x54);
  if (flag_nz()) goto lab_p07_L_5C16;
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p07_L_5C20;
  lab_p07_L_5C16: ;
  flag_cmp(a, 0x4A);
  if (flag_nz()) goto lab_p07_L_5C2E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p07_L_5C2E;
  lab_p07_L_5C20: ;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 7)));
  a = mem_read8(hl());
  a = a & 0xE0;
  flag_logic(a);
  cpu_ex_de_hl();
  set_hl(0x84D2);
  /* or (hl) */
  cpu_ex_de_hl();
  mem_write8(hl(), a);
  lab_p07_L_5C2E: ;
  p07_L_5A51();
  return;
  lab_p07_L_5C31: ;
  p07_L_5A51();
  cpu_push_af();
  cpu_push_hl();
  set_hl(mem_read16(0x9706));
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p07_L_5C41;
  mem_write8(hl(), 0x05);
  lab_p07_L_5C41: ;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x49);
  if (flag_z()) goto lab_p07_L_5C5C;
  flag_cmp(a, 0x54);
  if (flag_nz()) goto lab_p07_L_5C52;
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p07_L_5C5C;
  lab_p07_L_5C52: ;
  flag_cmp(a, 0x4A);
  if (flag_nz()) goto lab_p07_L_5C6A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p07_L_5C6A;
  lab_p07_L_5C5C: ;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 7)));
  a = mem_read8(hl());
  a = a & 0xE0;
  flag_logic(a);
  cpu_ex_de_hl();
  set_hl(0x84D2);
  /* or (hl) */
  cpu_ex_de_hl();
  mem_write8(hl(), a);
  lab_p07_L_5C6A: ;
  cpu_pop_hl();
  cpu_pop_af();
  p00_L_370B();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 4)));
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 6)));
  return;
}

/* flash page 7 cpu 0x5C80 (offset 0x1C80) */
void p07_L_5C80(void) {
  goto lab_p07_L_5C80;
  lab_p07_L_5C6C: ;
  p00_L_370B();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 4)));
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 6)));
  return;
  lab_p07_L_5C80: ;
  p00_L_1691();
  p00_rst10();
  if (flag_c()) return;
  cpu_ex_de_hl();
  a = 0x03;
  goto lab_p07_L_5C6C;
}

/* flash page 7 cpu 0x5C8A (offset 0x1C8A) */
void p07_L_5C8A(void) {
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5F);
  if (flag_nz()) goto lab_p07_L_5CB6;
  a = mem_read8(0x847A);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_5D11;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x46);
  if (flag_nz()) goto lab_p07_L_5D11;
  set_hl(0x8479);
  p00_rst20();
  p00_L_19E7();
  if (flag_c()) goto lab_p07_L_5CDA;
  p00_L_1F55();
  a = mem_read8(hl());
  if (flag_nz()) goto lab_p07_L_5CDA;
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p07_L_5D11;
  cpu_ex_de_hl();
  goto lab_p07_L_5D00;
  lab_p07_L_5CB6: ;
  flag_cmp(a, 0xEB);
  if (flag_nz()) goto lab_p07_L_5CC5;
  a = mem_read8(0x847A);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_5D11;
  a = 0x5D;
  mem_write8(0x8479, a);
  lab_p07_L_5CC5: ;
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p07_L_5CD1;
  flag_cmp(a, 0xAA);
  if (flag_z()) goto lab_p07_L_5CD1;
  flag_cmp(a, 0x62);
  if (flag_nc()) goto lab_p07_L_5CDC;
  lab_p07_L_5CD1: ;
  p00_rst10();
  if (flag_c()) goto lab_p07_L_5CDA;
  p00_L_1F55();
  a = mem_read8(hl());
  if (flag_z()) goto lab_p07_L_5D02;
  lab_p07_L_5CDA: ;
  /* scf */
  return;
  lab_p07_L_5CDC: ;
  a = mem_read8(0x847A);
  if (flag_nz()) goto lab_p07_L_5CF3;
  flag_cmp(a, 0x21);
  if (flag_z()) goto lab_p07_L_5CD1;
  set_hl(0x5CDA);
  p00_L_25A2();
  p00_L_2F4F();
  p00_L_25C8();
  a = 0;
  flag_logic(a);
  return;
  lab_p07_L_5CF3: ;
  p00_L_2F55();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p07_L_5D00;
  a = mem_read8(hl());
  flag_cmp(a, 0x0E);
  if (flag_z()) goto lab_p07_L_5CDA;
  a = 0;
  flag_logic(a);
  lab_p07_L_5D00: ;
  a = a | a;
  flag_logic(a);
  return;
  lab_p07_L_5D02: ;
  cpu_ex_de_hl();
  a = mem_read8(de());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x05);
  if (flag_c()) goto lab_p07_L_5D0F;
  flag_cmp(a, 0x0B);
  if (flag_c()) return;
  flag_cmp(a, 0x0E);
  lab_p07_L_5D0F: ;
  /* ccf */
  if (flag_nc()) return;
  lab_p07_L_5D11: ;
  /* scf */
  return;
}

/* flash page 7 cpu 0x5D13 (offset 0x1D13) */
void p07_L_5D13(void) {
  p07_L_5D21();
  p07_L_5D16();
  return;
}

/* flash page 7 cpu 0x5D16 (offset 0x1D16) */
void p07_L_5D16(void) {
  p07_L_5A3B();
  p00_L_03B8();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 0)));
  return;
}

/* flash page 7 cpu 0x5D21 (offset 0x1D21) */
void p07_L_5D21(void) {
  set_hl(0x266F);
  a = 0x0F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  a = 0x01;
  mem_write8(0x844B, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  p00_L_3C87();
  p07_L_5D40();
  p00_L_3CC9();
  return;
}

/* flash page 7 cpu 0x5D40 (offset 0x1D40) */
void p07_L_5D40(void) {
  a = 0x3D;
  p00_L_3F9F();
  return;
}

/* flash page 7 cpu 0x5D46 (offset 0x1D46) */
void p07_str_1(void) {
  b = e;
  b = c;
  d = h;
  b = c;
  c = h;
  c = a;
  b = a;
  /* nop */
  p07_L_5D4E();
  return;
}

/* flash page 7 cpu 0x5D4E (offset 0x1D4E) */
void p07_L_5D4E(void) {
  flag_cmp(a, 0x3E);
  if (flag_z()) goto lab_p07_L_5D5C;
  p00_L_2EFB();
  if (flag_z()) { p07_L_5E53(); return; }
  p00_L_2F01();
  return;
  lab_p07_L_5D5C: ;
  mem_write8((uint16_t)(iy + 0x29), (uint8_t)(mem_read8((uint16_t)(iy + 0x29)) & ~(1u << 4)));
  p00_L_2F07();
  if (flag_z()) { p07_L_5DE5(); return; }
  a = mem_read8(0x859A);
  flag_cmp(a, 0x4C);
  if (flag_z()) goto lab_p07_L_5D76;
  flag_cmp(a, 0x4D);
  if (flag_z()) goto lab_p07_L_5D76;
  flag_cmp(a, 0x41);
  a = b;
  if (flag_nz()) goto lab_p07_L_5D7A;
  lab_p07_L_5D76: ;
  a = b;
  p07_L_5DE5();
  return;
  lab_p07_L_5D7A: ;
  cpu_push_af();
  p00_L_2F0D();
  if (flag_c()) goto lab_p07_L_5D96;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  p00_L_2F13();
  p07_L_7140();
  cpu_pop_af();
  p07_L_6005();
  p00_L_2F19();
  p00_L_2F1F();
  goto lab_p07_L_5DB5;
  lab_p07_L_5D96: ;
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p07_L_5DB1;
  p07_L_598E();
  if (flag_z()) goto lab_p07_L_5DA8;
  p00_L_07DE();
  if (flag_z()) p00_L_0745();
  lab_p07_L_5DA8: ;
  p00_L_3D71();
  p00_L_2F19();
  p00_L_2F1F();
  lab_p07_L_5DB1: ;
  cpu_pop_af();
  p07_L_6005();
  lab_p07_L_5DB5: ;
  a = 0x07;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_2F25();
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p07_L_5DC8;
  p00_L_2F2B();
  if (flag_z()) return;
  lab_p07_L_5DC8: ;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  p00_L_2F31();
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  p07_L_5DE7();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p00_L_03B8();
  p07_L_5DE5();
  return;
}

/* flash page 7 cpu 0x5D95 (offset 0x1D95) */
void p07_L_5D95(void) {
  cpu_rra();
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p07_L_5DB1;
  p07_L_598E();
  if (flag_z()) goto lab_p07_L_5DA8;
  p00_L_07DE();
  if (flag_z()) p00_L_0745();
  lab_p07_L_5DA8: ;
  p00_L_3D71();
  p00_L_2F19();
  p00_L_2F1F();
  lab_p07_L_5DB1: ;
  cpu_pop_af();
  p07_L_6005();
  a = 0x07;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_2F25();
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p07_L_5DC8;
  p00_L_2F2B();
  if (flag_z()) return;
  lab_p07_L_5DC8: ;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  p00_L_2F31();
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  p07_L_5DE7();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p00_L_03B8();
  p07_L_5DE5();
  return;
}

/* flash page 7 cpu 0x5DE5 (offset 0x1DE5) */
void p07_L_5DE5(void) {
  /* scf */
  return;
}

/* flash page 7 cpu 0x5DE7 (offset 0x1DE7) */
void p07_L_5DE7(void) {
  set_hl(0x0000);
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 5)));
  mem_write16(0x85DF, hl());
  p07_L_5E0D();
  a = 0x01;
  set_de(0x0000);
  mem_write8(0x97A5, a);
  mem_write16(0x844B, de());
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p07_L_5E04();
  return;
}

/* flash page 7 cpu 0x5E04 (offset 0x1E04) */
void p07_L_5E04(void) {
  p07_L_5FA1();
  p07_L_6005();
  p07_L_60C0();
  return;
}

/* flash page 7 cpu 0x5E0D (offset 0x1E0D) */
void p07_L_5E0D(void) {
  mem_write16(0x844B, hl());
  set_hl(0x5D46);
  a = 0x33;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  set_de(0x848E);
  p00_L_1185();
  p00_L_1185();
  set_hl(0x848E);
  p00_L_3C87();
  p00_L_3D1D();
  return;
}

/* flash page 7 cpu 0x5E2F (offset 0x1E2F) */
void p07_L_5E2F(void) {
  set_hl(mem_read16(0x85DA));
  a = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_2F25();
  if (flag_nz()) goto lab_p07_L_5E4B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p07_L_5E4B;
  a = 0x01;
  mem_write8(0x844C, a);
  p00_L_2F2B();
  lab_p07_L_5E4B: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  b = a;
  set_hl((uint16_t)(hl() - 1));
  /* or (hl) */
  a = mem_read8(hl());
  c = a;
  return;
}

/* flash page 7 cpu 0x5E53 (offset 0x1E53) */
void p07_L_5E53(void) {
  b = a;
  a = 0x00;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_3123();
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p07_L_5E6A;
  a = 0x08;
  p00_L_2F2B();
  if (flag_z()) return;
  lab_p07_L_5E6A: ;
  a = b;
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p07_L_5E73;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p07_L_5E99;
  lab_p07_L_5E73: ;
  p07_L_5E2F();
  if (flag_z()) return;
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p07_L_5E80;
  a = b;
  b = 0xFF;
  goto lab_p07_L_5E90;
  lab_p07_L_5E80: ;
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p07_L_5E89;
  a = b;
  b = 0xFE;
  goto lab_p07_L_5E90;
  lab_p07_L_5E89: ;
  flag_cmp(a, 0xFC);
  if (flag_nz()) goto lab_p07_L_5E90;
  a = b;
  b = 0xFC;
  lab_p07_L_5E90: ;
  mem_write8(0x8446, a);
  a = b;
  a = a | a;
  flag_logic(a);
  p00_L_2F37();
  return;
  lab_p07_L_5E99: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p07_L_5EDD;
  lab_p07_L_5E9D: ;
  p07_L_6088();
  if (flag_c()) goto lab_p07_L_5ECE;
  mem_write8((uint16_t)(iy + 0x29), (uint8_t)(mem_read8((uint16_t)(iy + 0x29)) & ~(1u << 4)));
  set_hl(0x639E);
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p07_L_5EB4;
  p00_L_2F2B();
  lab_p07_L_5EB4: ;
  mem_write16(0x85DA, hl());
  p07_L_5FA4();
  set_hl(0x63AA);
  a = 0x03;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p07_L_5EC8;
  p00_L_2F2B();
  lab_p07_L_5EC8: ;
  mem_write16(0x85DA, hl());
  p07_L_60B3();
  return;
  lab_p07_L_5ECE: ;
  p07_L_6068();
  p07_L_60CB();
  p00_L_3CF3();
  if (flag_c()) p07_L_5F74();
  p07_L_60C3();
  return;
  lab_p07_L_5EDD: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p07_L_5EFC;
  lab_p07_L_5EE1: ;
  p07_L_604D();
  if (flag_z()) goto lab_p07_L_5EF6;
  p07_L_601E();
  if (flag_nc()) return;
  p07_L_60CB();
  p00_L_3CDB();
  if (flag_nc()) p07_L_5F74();
  p07_L_60C3();
  return;
  lab_p07_L_5EF6: ;
  p07_L_60CB();
  p07_L_5E04();
  return;
  lab_p07_L_5EFC: ;
  flag_cmp(a, 0x07);
  if (flag_z()) goto lab_p07_L_5E9D;
  flag_cmp(a, 0x08);
  if (flag_z()) goto lab_p07_L_5EE1;
  flag_cmp(a, 0x27);
  if (flag_z()) { p07_L_5E04(); return; }
  goto lab_p07_L_5F10;
  lab_p07_L_5F10: ;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p07_L_5F18;
  p00_L_2F3D();
  return;
  lab_p07_L_5F18: ;
  flag_cmp(a, 0xCC);
  if (flag_nz()) goto lab_p07_L_5F20;
  a = 0xB4;
  goto lab_p07_L_5F28;
  lab_p07_L_5F20: ;
  flag_cmp(a, 0x9A);
  if (flag_c()) goto lab_p07_L_5F54;
  flag_cmp(a, 0xB4);
  if (flag_nc()) goto lab_p07_L_5F54;
  lab_p07_L_5F28: ;
  a = (uint8_t)(a - 0x9A);
  a = (uint8_t)(a + a);
  set_hl(0x60F0);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  a = 0x04;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_2F25();
  if (flag_nz()) goto lab_p07_L_5F4B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p07_L_5F48;
  p00_L_2F2B();
  if (flag_z()) goto lab_p07_L_5F4B;
  lab_p07_L_5F48: ;
  p00_L_0033();
  lab_p07_L_5F4B: ;
  mem_write16(0x85DA, hl());
  p07_L_5FA4();
  p07_L_60C0();
  return;
  lab_p07_L_5F54: ;
  p00_L_2F43();
  return;
}

/* flash page 7 cpu 0x5F74 (offset 0x1F74) */
void p07_L_5F74(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = 0x20;
  p00_L_3F9F();
  set_hl(mem_read16(0x85DA));
  a = 0x09;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_2F25();
  if (flag_nz()) return;
  a = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_2F2B();
  if (flag_nz()) return;
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  p00_L_3BC1();
  p00_L_3C8D();
  p00_L_3D1D();
  return;
}

/* flash page 7 cpu 0x5FA1 (offset 0x1FA1) */
void p07_L_5FA1(void) {
  p07_L_6005();
  p07_L_5FA4();
  return;
}

/* flash page 7 cpu 0x5FA4 (offset 0x1FA4) */
void p07_L_5FA4(void) {
  set_hl(0x0001);
  mem_write16(0x844B, hl());
  p07_L_5FAA();
  return;
}

/* flash page 7 cpu 0x5FAA (offset 0x1FAA) */
void p07_L_5FAA(void) {
  set_hl(mem_read16(0x85DA));
  cpu_push_hl();
  a = mem_read8(0x8A19);
  cpu_push_af();
  lab_p07_L_5FB2: ;
  p07_L_5F74();
  a = mem_read8(0x844B);
  flag_cmp(a, 0x07);
  if (flag_z()) goto lab_p07_L_5FC7;
  p00_L_3CD5();
  p07_L_601E();
  if (flag_c()) goto lab_p07_L_5FB2;
  p00_L_3D29();
  lab_p07_L_5FC7: ;
  cpu_pop_af();
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x29), (uint8_t)(mem_read8((uint16_t)(iy + 0x29)) & ~(1u << 4)));
  flag_set_z((a & (1u << 4)) == 0);
  if (flag_z()) goto lab_p07_L_5FD5;
  mem_write8((uint16_t)(iy + 0x29), (uint8_t)(mem_read8((uint16_t)(iy + 0x29)) | (1u << 4)));
  lab_p07_L_5FD5: ;
  mem_write16(0x85DA, hl());
  return;
}

/* flash page 7 cpu 0x6005 (offset 0x2005) */
void p07_L_6005(void) {
  set_hl(0x6126);
  a = 0x05;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_2F25();
  if (flag_nz()) goto lab_p07_L_601A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_2F2B();
  lab_p07_L_601A: ;
  mem_write16(0x85DA, hl());
  return;
}

/* flash page 7 cpu 0x601E (offset 0x201E) */
void p07_L_601E(void) {
  p07_L_604D();
  if (flag_nc()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p07_L_6046;
  flag_set_z((mem_read8((uint16_t)(iy + 0x29)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p07_L_6046;
  a = 0x0C;
  p00_L_2F25();
  if (flag_nz()) goto lab_p07_L_6046;
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) & ~(1u << 3)));
  p07_L_6005();
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x29), (uint8_t)(mem_read8((uint16_t)(iy + 0x29)) & ~(1u << 4)));
  goto lab_p07_L_604B;
  lab_p07_L_6046: ;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x85DA, hl());
  lab_p07_L_604B: ;
  /* scf */
  return;
}

/* flash page 7 cpu 0x604D (offset 0x204D) */
void p07_L_604D(void) {
  set_hl(mem_read16(0x85DA));
  set_de(0x63AA);
  a = 0x06;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_2F25();
  if (flag_nz()) goto lab_p07_L_6065;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_2F2B();
  lab_p07_L_6065: ;
  p00_L_192A();
  return;
}

/* flash page 7 cpu 0x6068 (offset 0x2068) */
void p07_L_6068(void) {
  set_de(mem_read16(0x85DA));
  set_hl(0x6126);
  a = 0x0A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_2F25();
  if (flag_nz()) goto lab_p07_L_6083;
  a = 0x05;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_2F2B();
  lab_p07_L_6083: ;
  p00_L_192A();
  cpu_ex_de_hl();
  return;
}

/* flash page 7 cpu 0x6088 (offset 0x2088) */
void p07_L_6088(void) {
  p07_L_6068();
  if (flag_nc()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p07_L_60AC;
  flag_set_z((mem_read8((uint16_t)(iy + 0x29)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p07_L_60AC;
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) & ~(1u << 3)));
  p07_L_6068();
  mem_write8((uint16_t)(iy + 0x36), (uint8_t)(mem_read8((uint16_t)(iy + 0x36)) | (1u << 3)));
  if (flag_c()) goto lab_p07_L_60AC;
  a = 0x0B;
  p00_L_2F25();
  goto lab_p07_L_60AE;
  lab_p07_L_60AC: ;
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  lab_p07_L_60AE: ;
  mem_write16(0x85DA, hl());
  /* scf */
  return;
}

/* flash page 7 cpu 0x60B3 (offset 0x20B3) */
void p07_L_60B3(void) {
  cpu_push_hl();
  set_hl(mem_read16(0x97A6));
  l = (uint8_t)(l - 1);
  h = 0x00;
  mem_write16(0x844B, hl());
  cpu_pop_hl();
  p07_L_60C3();
  return;
}

/* flash page 7 cpu 0x60C0 (offset 0x20C0) */
void p07_L_60C0(void) {
  p00_L_3D2F();
  p07_L_60C3();
  return;
}

/* flash page 7 cpu 0x60C3 (offset 0x20C3) */
void p07_L_60C3(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = 0x05;
  goto lab_p07_L_60D1;
  lab_p07_L_60D1: ;
  p00_L_3C6F();
  /* scf */
  return;
}

/* flash page 7 cpu 0x60CB (offset 0x20CB) */
void p07_L_60CB(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = 0x20;
  p00_L_3C6F();
  /* scf */
  return;
}

/* flash page 7 cpu 0x60D6 (offset 0x20D6) */
void p07_L_60D6(void) {
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 1)));
  p00_L_03A0();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  a = 0;
  flag_logic(a);
  mem_write8(0x844B, a);
  a = 0x0F;
  mem_write8(0x844C, a);
  a = 0x20;
  p00_L_3F9F();
  return;
}

/* flash page 7 cpu 0x63AF (offset 0x23AF) */
void p07_L_63AF(void) {
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  /* set 0,(iy) */
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  p00_L_17FA();
  set_hl(0x6428);
  p00_L_07CC();
  a = mem_read8(0x8446);
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p07_L_63D5;
  p00_L_2E53();
  p00_L_05F1();
  return;
  lab_p07_L_63D5: ;
  a = 0x20;
  p00_L_2E59();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 5)));
  return;
}

/* flash page 7 cpu 0x643A (offset 0x243A) */
void p07_L_643A(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  a = 0;
  flag_logic(a);
  mem_write8(0x85DE, a);
  mem_write8(0x984B, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x25)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p07_L_6452;
  p00_L_2E65();
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 3)));
  lab_p07_L_6452: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 3)));
  return;
}

/* flash page 7 cpu 0x6515 (offset 0x2515) */
void p07_L_6515(void) {
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  if (flag_z()) p00_L_321F();
  p07_L_651D();
  return;
}

/* flash page 7 cpu 0x651D (offset 0x251D) */
void p07_L_651D(void) {
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p07_L_6553();
  p00_L_2E8F();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  p00_L_2E83();
  if (flag_z()) goto lab_p07_L_6535;
  p00_L_2E95();
  return;
  lab_p07_L_6535: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  p00_L_3D29();
  p00_L_2E9B();
  return;
}

/* flash page 7 cpu 0x6553 (offset 0x2553) */
void p07_L_6553(void) {
  p00_L_3F2D();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
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
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 7 cpu 0x6564 (offset 0x2564) */
void p07_L_6564(void) {
  set_bc((uint16_t)(bc() + 1));
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
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 7 cpu 0x65A1 (offset 0x25A1) */
void p07_L_65A1(void) {
  b = 0x20;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_65A8;
  b = 0x2A;
  lab_p07_L_65A8: ;
  a = 0x01;
  mem_write8(0x844C, a);
  a = b;
  p00_L_3F9F();
  a = mem_read8(0x844B);
  cpu_push_af();
  p07_L_6553();
  cpu_pop_af();
  mem_write8(0x844B, a);
  return;
}

/* flash page 7 cpu 0x65BD (offset 0x25BD) */
void p07_L_65BD(void) {
  p07_L_7BA1();
  /* di */
  p07_L_6602();
  p00_L_2EAD();
  set_hl(mem_read16(0x83F3));
  set_de(mem_read16(0x83F7));
  p00_L_1FB8();
  return;
}

/* flash page 7 cpu 0x65D2 (offset 0x25D2) */
void p07_L_65D2(void) {
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 0)));
  p07_L_662E();
  if (flag_c()) { p00_L_2559(); return; }
  goto lab_p07_L_6624;
  lab_p07_L_6624: ;
  mem_write8(0x83EE, a);
  mem_write16(0x83EF, hl());
  set_hl(mem_read16(0x83F1));
  return;
}

/* flash page 7 cpu 0x65E2 (offset 0x25E2) */
void p07_L_65E2(void) {
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 0)));
  mem_write16(0x83F3, de());
  mem_write16(0x83F1, hl());
  p00_L_1B6B();
  mem_write16(0x83F5, bc());
  p07_L_662E();
  d = 0x00;
  if (flag_c()) p07_L_667C();
  goto lab_p07_L_6624;
  lab_p07_L_6624: ;
  mem_write8(0x83EE, a);
  mem_write16(0x83EF, hl());
  set_hl(mem_read16(0x83F1));
  return;
}

/* flash page 7 cpu 0x6602 (offset 0x2602) */
void p07_L_6602(void) {
  mem_write16(0x83F3, de());
  mem_write16(0x83F1, hl());
  p00_L_1B6B();
  mem_write16(0x83F5, bc());
  set_hl(mem_read16(0x83F1));
  a = mem_read8(hl());
  set_hl(mem_read16(0x83F3));
  p00_L_210A();
  mem_write16(0x83F7, de());
  p07_L_662E();
  if (flag_c()) p07_L_667A();
  mem_write8(0x83EE, a);
  mem_write16(0x83EF, hl());
  set_hl(mem_read16(0x83F1));
  return;
}

/* flash page 7 cpu 0x662E (offset 0x262E) */
void p07_L_662E(void) {
  cpu_push_af();
  set_hl(mem_read16(0x83F1));
  a = mem_read8(hl());
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) p00_L_0087();
  a = a & 0x1F;
  flag_logic(a);
  mem_write8(hl(), a);
  cpu_pop_af();
  set_hl(mem_read16(0x83F7));
  a = a | a;
  flag_logic(a);
  set_bc(mem_read16(0x83F5));
  /* adc hl,bc */
  if (flag_c()) { p00_L_24FD(); return; }
  mem_write16(0x83F9, hl());
  set_bc(0x0003);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  if (flag_c()) { p00_L_24FD(); return; }
  cpu_push_hl();
  p00_L_2EA1();
  cpu_pop_bc();
  set_hl(mem_read16(0x839F));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_6676;
  set_hl(mem_read16(0x83A1));
  a = h;
  h = l;
  l = a;
  set_de(mem_read16(0x83F9));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p07_L_6676;
  p00_L_2EB3();
  p00_L_2559();
  return;
  lab_p07_L_6676: ;
  p00_L_2EB3();
  return;
}

/* flash page 7 cpu 0x667A (offset 0x267A) */
void p07_L_667A(void) {
  d = 0x01;
  p07_L_667C();
  return;
}

/* flash page 7 cpu 0x667C (offset 0x267C) */
void p07_L_667C(void) {
  cpu_push_bc();
  cpu_push_de();
  p07_L_669E();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p07_L_668D;
  p00_L_0AFB();
  if (flag_z()) p00_L_2E89();
  lab_p07_L_668D: ;
  a = 0x00;
  cpu_pop_bc();
  p00_L_2EB9();
  p07_L_66AA();
  cpu_pop_bc();
  p00_L_2EB3();
  if (flag_c()) { p00_L_2559(); return; }
  return;
}

/* flash page 7 cpu 0x669E (offset 0x269E) */
void p07_L_669E(void) {
  set_hl(0x83F1);
  set_de(0x8406);
  set_bc(0x000C);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 7 cpu 0x66AA (offset 0x26AA) */
void p07_L_66AA(void) {
  set_hl(0x8406);
  set_de(0x83F1);
  set_bc(0x000C);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 7 cpu 0x66B6 (offset 0x26B6) */
void p07_L_66B6(void) {
  mem_write16(0x83F1, hl());
  mem_write16(0x83EF, de());
  mem_write8(0x83EE, a);
  p00_L_1B6B();
  mem_write16(0x83F5, bc());
  a = mem_read8(0x83EE);
  set_hl(mem_read16(0x83EF));
  p00_L_3267();
  mem_write16(0x83F7, bc());
  set_de(mem_read16(0x83F7));
  set_hl(mem_read16(0x83F1));
  a = mem_read8(hl());
  p00_L_20F8();
  mem_write16(0x83F9, de());
  mem_write16(0x83F7, de());
  cpu_ex_de_hl();
  p00_L_1B33();
  if (flag_c()) { p00_L_24F5(); return; }
  set_bc(mem_read16(0x83F9));
  a = a | 0x01;
  flag_logic(a);
  p00_L_1A99();
  mem_write16(0x83F3, de());
  p00_L_2EBF();
  return;
}

/* flash page 7 cpu 0x66FF (offset 0x26FF) */
void p07_L_66FF(void) {
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(0x83EF);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(0x83F0);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(0x83EE);
  mem_write8(hl(), a);
  return;
}

/* flash page 7 cpu 0x6711 (offset 0x2711) */
void p07_L_6711(void) {
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) | (1u << 0)));
  p07_L_6754();
  if (flag_z()) { p00_L_24B5(); return; }
  p00_L_1100();
  p00_L_19ED();
  if (flag_c()) { p00_L_24F1(); return; }
  /* di */
  mem_write16(0x981C, hl());
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_673B;
  a = mem_read8(hl());
  flag_cmp(a, 0x17);
  if (flag_z()) { p00_L_24B5(); return; }
  a = b;
  p07_L_66B6();
  a = a | 0x01;
  flag_logic(a);
  a = 0x00;
  return;
  lab_p07_L_673B: ;
  p07_L_65BD();
  p00_L_113F();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p07_L_674E;
  p00_L_321F();
  p00_L_2EC5();
  lab_p07_L_674E: ;
  a = mem_read8(0x83EE);
  a = a | a;
  flag_logic(a);
  /* ei */
  return;
}

/* flash page 7 cpu 0x6754 (offset 0x2754) */
void p07_L_6754(void) {
  p00_L_1037();
  if (flag_nz()) goto lab_p07_L_6771;
  lab_p07_L_6759: ;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x58);
  if (flag_z()) return;
  flag_cmp(a, 0x59);
  if (flag_z()) return;
  flag_cmp(a, 0x54);
  if (flag_z()) return;
  flag_cmp(a, 0x5B);
  if (flag_z()) return;
  flag_cmp(a, 0x52);
  if (flag_z()) return;
  flag_cmp(a, 0x72);
  if (flag_z()) return;
  flag_cmp(a, 0xFC);
  return;
  lab_p07_L_6771: ;
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p07_L_6759;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p07_L_6783;
  lab_p07_L_6779: ;
  p07_L_67DC();
  if (flag_z()) return;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x40);
  return;
  lab_p07_L_6783: ;
  flag_cmp(a, 0x14);
  if (flag_z()) return;
  flag_cmp(a, 0x09);
  if (flag_z()) return;
  flag_cmp(a, 0x18);
  if (flag_nc()) goto lab_p07_L_67A0;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p07_L_6779;
  flag_cmp(a, 0x17);
  if (flag_z()) return;
  flag_cmp(a, 0x0E);
  if (flag_z()) return;
  flag_cmp(a, 0x0B);
  if (flag_z()) return;
  flag_cmp(a, 0x0A);
  if (flag_z()) return;
  flag_cmp(a, 0x03);
  return;
  lab_p07_L_67A0: ;
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 7 cpu 0x6766 (offset 0x2766) */
void p07_L_6766(void) {
  e = e;
  if (flag_z()) return;
  flag_cmp(a, 0x52);
  if (flag_z()) return;
  flag_cmp(a, 0x72);
  if (flag_z()) return;
  flag_cmp(a, 0xFC);
  return;
}

/* flash page 7 cpu 0x67A2 (offset 0x27A2) */
void p07_L_67A2(void) {
  set_hl(0xFE66);
  lab_p07_L_67A5: ;
  set_bc(mem_read16(0x982E));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) return;
  if (flag_z()) return;
  set_hl((uint16_t)(hl() + bc()));
  b = 0x00;
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  cpu_push_hl();
  p00_L_2408();
  c = 0x09;
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  p00_L_17B3();
  if (flag_z()) goto lab_p07_L_67C8;
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p07_L_67CC;
  lab_p07_L_67C8: ;
  a = mem_read8(hl());
  a = (uint8_t)(a + 0x07);
  c = a;
  lab_p07_L_67CC: ;
  cpu_pop_hl();
  a = e;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_67D8;
  cpu_push_hl();
  p00_L_1F06();
  cpu_pop_hl();
  goto lab_p07_L_67A5;
  lab_p07_L_67D8: ;
  cpu_sbc_hl_bc();
  goto lab_p07_L_67A5;
}

/* flash page 7 cpu 0x67DC (offset 0x27DC) */
void p07_L_67DC(void) {
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  set_hl(0x8478);
  set_de(0x67F2);
  b = 0x07;
  lab_p07_L_67E7: ;
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  cpu_cp_hl();
  if (flag_nz()) goto lab_p07_L_67EF;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_67E7;
  lab_p07_L_67EF: ;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 7 cpu 0x67FA (offset 0x27FA) */
void p07_L_67FA(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x07)) & (1u << 1)) == 0);
  if (flag_nz()) { p00_L_2501(); return; }
  p00_rst18();
  p00_L_231F();
  a = mem_read8(0x8483);
  a = a & 0x0F;
  flag_logic(a);
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_L_2315();
  p00_L_1653();
  p00_L_10DD();
  p00_L_1078();
  cpu_push_af();
  p00_L_1135();
  p00_L_231F();
  cpu_pop_af();
  a = mem_read8(0x8484);
  if (flag_c()) goto lab_p07_L_6829;
  a = mem_read8(0x8479);
  lab_p07_L_6829: ;
  cpu_push_af();
  p00_L_0C2D();
  p00_L_39E1();
  p00_L_2375();
  p00_L_128A();
  b = 0x0C;
  lab_p07_L_6838: ;
  cpu_push_bc();
  p00_rst18();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_6838;
  mem_write16(0x9302, de());
  mem_write16(0x9311, de());
  p00_L_2970();
  p00_L_0D16();
  p00_L_29E3();
  p00_L_1229();
  p00_L_2A13();
  p00_L_1295();
  cpu_pop_af();
  mem_write8(0x847F, a);
  set_hl(0x0001);
  mem_write16(0x8478, hl());
  p00_L_29AA();
  p00_L_1169();
  p00_L_2977();
  p07_L_5092();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 1)));
  set_hl(0x6B03);
  p00_L_25A2();
  p00_L_128A();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  p07_L_6C30();
  p00_L_113F();
  p00_L_235C();
  p00_L_28B5();
  p07_L_6C0C();
  p07_L_688C();
  return;
}

/* flash page 7 cpu 0x688C (offset 0x288C) */
void p07_L_688C(void) {
  lab_p07_L_688C: ;
  p00_L_28CB();
  p07_L_6BD0();
  p00_L_29A1();
  p00_L_28B0();
  p00_L_1078();
  if (flag_nc()) goto lab_p07_L_69F5;
  a = mem_read8(0x84AF);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_68AF;
  a = mem_read8(0x84B7);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p00_L_24F5(); return; }
  p00_L_2529();
  return;
  lab_p07_L_68AF: ;
  b = a;
  a = mem_read8(0x84B1);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_68F1;
  a = b;
  mem_write8(0x84B1, a);
  p00_L_292F();
  p00_L_0C18();
  p00_L_2A13();
  a = mem_read8(0x847A);
  flag_cmp(a, 0x35);
  if (flag_z()) p07_L_6BCA();
  p00_L_0C18();
  p00_rst08();
  p00_L_2970();
  p00_L_0ED0();
  p00_L_29E3();
  a = mem_read8(0x84B3);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_68F1;
  p00_L_14C7();
  if (flag_z()) goto lab_p07_L_68EE;
  set_hl(0x8479);
  a = mem_read8(0x84B6);
  /* sub (hl) */
  if (flag_c()) goto lab_p07_L_68F1;
  a = (uint8_t)(a - 0x0C);
  lab_p07_L_68EE: ;
  if (flag_nc()) p07_L_6BCA();
  lab_p07_L_68F1: ;
  p00_L_28B5();
  p00_L_294C();
  p00_L_0C2D();
  p00_L_15D6();
  p00_rst08();
  p00_L_2902();
  p00_L_0C2D();
  p00_L_1100();
  set_hl(mem_read16(0x84B1));
  p00_L_3B55();
  p00_L_1179();
  set_hl(mem_read16(0x84AF));
  p00_L_3B55();
  p00_rst30();
  p00_rst08();
  p00_L_113F();
  p00_L_0ED0();
  p00_L_1171();
  p00_L_2902();
  p00_L_2934();
  p00_L_0ED0();
  p00_L_1108();
  p00_L_0BE3();
  p00_L_29A1();
  p00_L_2324();
  p00_L_0E4C();
  p07_L_6BE8();
  p00_L_2315();
  p00_L_0E4C();
  p00_L_1100();
  p07_L_6AD4();
  p00_L_113F();
  p07_L_6C0C();
  a = mem_read8(0x84AF);
  a = (uint8_t)(a - 1);
  mem_write8(0x84AF, a);
  flag_cmp(a, 0x7F);
  if (flag_z()) p07_L_6BCA();
  set_hl(0x84B1);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p00_L_22FC();
  p00_L_0C18();
  p00_L_2A17();
  p07_L_6C30();
  p00_L_2945();
  p00_L_0C1B();
  p07_L_6A1D();
  p00_L_1151();
  a = mem_read8(0x84B3);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_6997;
  p00_L_1151();
  p00_L_2310();
  p00_L_2902();
  p00_L_1078();
  if (flag_c()) goto lab_p07_L_699F;
  p00_L_2902();
  p00_L_1108();
  p00_L_1078();
  if (flag_c()) goto lab_p07_L_69CC;
  lab_p07_L_6997: ;
  set_de(0x001B);
  p00_L_21B6();
  goto lab_p07_L_69E0;
  lab_p07_L_699F: ;
  p00_L_2324();
  p00_L_2310();
  p07_L_6BF0();
  p00_L_2948();
  p00_L_2902();
  p00_L_1108();
  p00_L_1078();
  if (flag_nc()) goto lab_p07_L_69E0;
  set_hl(0x001B);
  p00_L_1B33();
  if (flag_nc()) goto lab_p07_L_69C8;
  p07_L_6BCA();
  a = 0x01;
  mem_write8(0x84B7, a);
  goto lab_p07_L_69E0;
  lab_p07_L_69C8: ;
  cpu_ex_de_hl();
  p00_L_21C3();
  lab_p07_L_69CC: ;
  p00_L_28E5();
  p00_L_1108();
  p07_L_6BF0();
  cpu_push_de();
  p00_L_2945();
  p00_L_0C1B();
  cpu_pop_de();
  p00_L_11FD();
  lab_p07_L_69E0: ;
  set_hl(mem_read16(0x84AF));
  set_hl((uint16_t)(hl() + hl()));
  set_bc(mem_read16(0x84B4));
  set_hl((uint16_t)(hl() + bc()));
  set_de(0x00FF);
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) p07_L_6BCA();
  goto lab_p07_L_688C;
  lab_p07_L_69F5: ;
  p00_L_25C8();
  p00_L_2977();
  p07_L_50F3();
  set_hl(mem_read16(0x9302));
  mem_write16(0x9824, hl());
  p00_L_295D();
  p00_L_39ED();
  p00_L_297E();
  p00_L_16BC();
  p00_L_28CB();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 1)));
  set_de(0x00A2);
  p00_L_21B6();
  return;
}

/* flash page 7 cpu 0x6968 (offset 0x2968) */
void p07_L_6968(void) {
  if (flag_nc()) goto lab_p07_L_69D6;
  p00_L_2945();
  p00_L_0C1B();
  p07_L_6A1D();
  p00_L_1151();
  a = mem_read8(0x84B3);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_6997;
  p00_L_1151();
  p00_L_2310();
  p00_L_2902();
  p00_L_1078();
  if (flag_c()) goto lab_p07_L_699F;
  p00_L_2902();
  p00_L_1108();
  p00_L_1078();
  if (flag_c()) goto lab_p07_L_69CC;
  lab_p07_L_6997: ;
  set_de(0x001B);
  p00_L_21B6();
  goto lab_p07_L_69E0;
  lab_p07_L_699F: ;
  p00_L_2324();
  p00_L_2310();
  p07_L_6BF0();
  p00_L_2948();
  p00_L_2902();
  p00_L_1108();
  p00_L_1078();
  if (flag_nc()) goto lab_p07_L_69E0;
  set_hl(0x001B);
  p00_L_1B33();
  if (flag_nc()) goto lab_p07_L_69C8;
  p07_L_6BCA();
  a = 0x01;
  mem_write8(0x84B7, a);
  goto lab_p07_L_69E0;
  lab_p07_L_69C8: ;
  cpu_ex_de_hl();
  p00_L_21C3();
  lab_p07_L_69CC: ;
  p00_L_28E5();
  p00_L_1108();
  p07_L_6BF0();
  cpu_push_de();
  lab_p07_L_69D6: ;
  p00_L_2945();
  p00_L_0C1B();
  cpu_pop_de();
  p00_L_11FD();
  lab_p07_L_69E0: ;
  set_hl(mem_read16(0x84AF));
  set_hl((uint16_t)(hl() + hl()));
  set_bc(mem_read16(0x84B4));
  set_hl((uint16_t)(hl() + bc()));
  set_de(0x00FF);
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) p07_L_6BCA();
  p07_L_688C();
  return;
}

/* flash page 7 cpu 0x6A1D (offset 0x2A1D) */
void p07_L_6A1D(void) {
  p00_L_29BC();
  p00_L_0C18();
  p00_L_0C1B();
  p00_L_2917();
  p00_L_0D1F();
  p00_rst08();
  p00_L_2990();
  p00_rst30();
  p00_L_29DB();
  p07_L_6ADC();
  p00_L_10DD();
  set_hl(0x6B16);
  p00_L_0D19();
  p00_L_29DF();
  p00_L_1135();
  set_hl(0x6B9D);
  p00_L_0D19();
  p00_L_29D7();
  a = 0;
  flag_logic(a);
  lab_p07_L_6A50: ;
  a = (uint8_t)(a + 1);
  cpu_push_af();
  p00_L_291C();
  p07_L_6C40();
  p00_L_2A0F();
  p00_L_28EC();
  p00_rst30();
  p07_L_6ADC();
  p00_L_2923();
  p00_L_2A0F();
  p00_L_28F1();
  p00_L_0C2D();
  p07_L_6ADC();
  p00_L_2923();
  p00_rst30();
  p00_L_2A0F();
  p07_L_6C51();
  p00_L_290B();
  p00_rst30();
  p00_L_29DF();
  p00_L_2928();
  cpu_pop_af();
  cpu_push_af();
  /* srl a */
  if (flag_c()) goto lab_p07_L_6A98;
  set_de(0x6B9D);
  p07_L_6C47();
  p00_L_28E0();
  p00_rst30();
  p00_L_29D7();
  lab_p07_L_6A98: ;
  cpu_pop_af();
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p07_L_6A50;
  p00_L_2910();
  p00_L_2A0F();
  p00_L_2917();
  p00_L_0D1F();
  p00_L_29DF();
  p00_L_28E5();
  p00_L_0D1F();
  p07_L_6AB2();
  return;
}

/* flash page 7 cpu 0x6AB2 (offset 0x2AB2) */
void p07_L_6AB2(void) {
  p00_L_290B();
  p00_L_29EF();
  p00_L_0C2D();
  p00_L_29DF();
  p00_L_2898();
  p00_L_28E5();
  p07_L_6BE8();
  p00_L_2910();
  p00_L_1100();
  set_hl(mem_read16(0x84B4));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x84B4, hl());
  p07_L_6AD4();
  return;
}

/* flash page 7 cpu 0x6AD4 (offset 0x2AD4) */
void p07_L_6AD4(void) {
  p00_L_28B0();
  p00_rst30();
  p00_L_29C8();
  return;
}

/* flash page 7 cpu 0x6ADC (offset 0x2ADC) */
void p07_L_6ADC(void) {
  p00_rst08();
  p00_L_2977();
  p00_L_2429();
  set_hl(0x8483);
  p00_L_1183();
  p00_L_297E();
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p00_L_39E7();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  p00_L_1717();
  set_hl(mem_read16(0x9311));
  p07_L_6AFD();
  return;
}

/* flash page 7 cpu 0x6AFD (offset 0x2AFD) */
void p07_L_6AFD(void) {
  mem_write16(0x9302, hl());
  p00_L_1653();
  return;
}

/* flash page 7 cpu 0x6B6E (offset 0x2B6E) */
void p07_L_6B6E(void) {
  mem_write8(hl(), a);
  b = b;
  /* nop */
  a = a;
  e = b;
  h = b;
  a = (uint8_t)(a + a);
  set_hl((uint16_t)(hl() + 1));
  d = h;
  h = a;
  l = c;
  /* nop */
  a = a;
  mem_write8(hl(), h);
  d = (uint8_t)(d - 1);
  sp = 0x5518;
  /* sbc a,c */
  set_hl((uint16_t)(hl() + sp));
  /* nop */
  a = a;
  /* add a,(hl) */
  c = b;
  h = h;
  b = d;
  sp = (uint16_t)(sp + 1);
  e = c;
  mem_write8(hl(), a);
  /* nop */
  a = a;
  a = (uint8_t)(a - h);
  a = (uint8_t)(a - c);
  cpu_rlca();
  a = (uint8_t)(a - c);
  set_hl((uint16_t)(hl() + 1));
  b = d;
  halt();
  /* nop */
  a = a;
  /* sbc a,c */
  d = (uint8_t)(d + 1);
  d = l;
  /* scf */
  set_de(0x8120);
  /* nop */
  a = a;
  b = c;
  a = c;
  e = c;
  goto lab_p07_L_6BDA;
  lab_p07_L_6BDA: ;
  cpu_rrca();
  p00_L_0D1F();
  p00_L_1120();
  p00_L_2969();
  p00_L_0BE3();
  return;
}

/* flash page 7 cpu 0x6BCA (offset 0x2BCA) */
void p07_L_6BCA(void) {
  set_hl(0x84B3);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  return;
}

/* flash page 7 cpu 0x6BD0 (offset 0x2BD0) */
void p07_L_6BD0(void) {
  p00_L_15D6();
  a = 0x74;
  set_hl(0x8483);
  p00_L_0FE3();
  p00_L_0D1F();
  p00_L_1120();
  p00_L_2969();
  p00_L_0BE3();
  return;
}

/* flash page 7 cpu 0x6BE8 (offset 0x2BE8) */
void p07_L_6BE8(void) {
  p00_L_28C3();
  p00_rst30();
  p00_L_29D3();
  return;
}

/* flash page 7 cpu 0x6BF0 (offset 0x2BF0) */
void p07_L_6BF0(void) {
  set_hl(0x84AF);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p07_L_6C14();
  set_de(mem_read16(0x9302));
  p00_L_11FD();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_1183();
  cpu_push_de();
  p00_L_1179();
  p07_L_6C0C();
  cpu_pop_de();
  return;
}

/* flash page 7 cpu 0x6BFD (offset 0x2BFD) */
void p07_L_6BFD(void) {
  set_de(0x2323);
  p00_L_1183();
  cpu_push_de();
  p00_L_1179();
  p07_L_6C0C();
  cpu_pop_de();
  return;
}

/* flash page 7 cpu 0x6C0C (offset 0x2C0C) */
void p07_L_6C0C(void) {
  p00_L_294C();
  p00_rst30();
  p00_L_2A1B();
  return;
}

/* flash page 7 cpu 0x6C14 (offset 0x2C14) */
void p07_L_6C14(void) {
  set_hl(mem_read16(0x9824));
  set_de(0x001B);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  set_de(mem_read16(0x9302));
  cpu_sbc_hl_de();
  if (flag_z()) return;
  b = h;
  c = l;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() - 1));
  set_de(mem_read16(0x9824));
  set_de((uint16_t)(de() - 1));
  /* lddr */
  return;
}

/* flash page 7 cpu 0x6C30 (offset 0x2C30) */
void p07_L_6C30(void) {
  p07_L_6A1D();
  p00_L_113F();
  p00_L_235C();
  p00_L_28E5();
  p00_L_2375();
  return;
}

/* flash page 7 cpu 0x6C40 (offset 0x2C40) */
void p07_L_6C40(void) {
  set_de(0x6B55);
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_hl();
  p07_L_6C47();
  return;
}

/* flash page 7 cpu 0x6C47 (offset 0x2C47) */
void p07_L_6C47(void) {
  l = a;
  h = 0x00;
  p00_L_1025();
  set_hl((uint16_t)(hl() + de()));
  p00_L_0D19();
  return;
}

/* flash page 7 cpu 0x6C51 (offset 0x2C51) */
void p07_L_6C51(void) {
  goto lab_p07_L_6C51;
  lab_p07_L_6C43: ;
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_hl();
  p07_L_6C47();
  return;
  lab_p07_L_6C51: ;
  set_de(0x6B16);
  goto lab_p07_L_6C43;
}

/* flash page 7 cpu 0x6C56 (offset 0x2C56) */
void p07_L_6C56(void) {
  p00_rst18();
  p00_L_38F1();
  p00_rst18();
  p00_rst08();
  p00_L_2315();
  p00_rst18();
  p00_L_16A2();
  p00_rst18();
  p00_L_22D9();
  p00_rst18();
  p00_L_21E0();
  p00_L_107E();
  cpu_push_af();
  p07_L_6C6F();
  return;
}

/* flash page 7 cpu 0x6C6F (offset 0x2C6F) */
void p07_L_6C6F(void) {
  p00_L_1229();
  a = 0x7D;
  mem_write8(0x8479, a);
  p07_L_67FA();
  p00_rst18();
  cpu_pop_af();
  if (flag_c()) goto lab_p07_L_6C8D;
  p00_L_22C7();
  p00_L_2315();
  p00_L_2389();
  p00_L_1179();
  p00_L_235C();
  lab_p07_L_6C8D: ;
  p00_L_2315();
  p00_L_34DD();
  cpu_push_af();
  p00_L_22CF();
  p00_L_34DD();
  cpu_push_af();
  lab_p07_L_6C9B: ;
  set_hl(0x8483);
  cpu_pop_af();
  cpu_push_af();
  p00_L_340B();
  p00_L_2389();
  p00_L_3321();
  p00_L_2324();
  set_hl(0x6CDA);
  p00_L_25A2();
  p00_L_39E7();
  p00_L_25C8();
  p00_L_10DD();
  p00_L_22CF();
  p00_L_1100();
  p00_L_1287();
  p00_L_356D();
  cpu_pop_af();
  cpu_pop_bc();
  flag_cmp(a, b);
  if (flag_z()) goto lab_p07_L_6CD1;
  cpu_push_bc();
  a = (uint8_t)(a + 1);
  cpu_push_af();
  goto lab_p07_L_6C9B;
  lab_p07_L_6CD1: ;
  p00_L_219B();
  set_de(0x001B);
  p00_L_21B6();
  return;
}

/* flash page 7 cpu 0x6CE3 (offset 0x2CE3) */
void p07_L_6CE3(void) {
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x3C), (uint8_t)(mem_read8((uint16_t)(iy + 0x3C)) & ~(1u << 4)));
  set_hl(0x6D9B);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) | (1u << 4)));
  p00_L_19B0();
  set_de(0x0064);
  p00_L_192A();
  if (flag_c()) goto lab_p07_L_6D27;
  a = mem_read8(0x86DD);
  cpu_rla();
  if (flag_nc()) goto lab_p07_L_6D27;
  p07_L_6E8F();
  if (flag_nz()) goto lab_p07_L_6D1A;
  set_hl(mem_read16(0x85A3));
  set_de(0x25A1);
  p00_L_192A();
  if (flag_z()) goto lab_p07_L_6D27;
  lab_p07_L_6D1A: ;
  a = mem_read8(0x9652);
  a = a & 0x0F;
  flag_logic(a);
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p07_L_6D27;
  a = 0x3E;
  goto lab_p07_L_6D29;
  lab_p07_L_6D27: ;
  a = 0x3D;
  lab_p07_L_6D29: ;
  cpu_push_af();
  p00_L_33C9();
  cpu_pop_af();
  p00_L_2E59();
  a = 0x05;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_3123();
  a = mem_read8(0x85A8);
  flag_cmp(a, 0x50);
  if (flag_nz()) goto lab_p07_L_6D49;
  set_de(mem_read16(0x982C));
  p07_L_505F();
  return;
  lab_p07_L_6D49: ;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 6)));
  p07_L_534B();
  a = mem_read8(0x86DD);
  flag_cmp(a, 0x31);
  if (flag_nz()) return;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  a = 0x7A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  if (flag_nz()) goto lab_p07_L_6D8F;
  set_hl(0x0004);
  mem_write16(0x844B, hl());
  set_hl(0x286E);
  p00_L_3C87();
  set_hl(0x0105);
  mem_write16(0x844B, hl());
  set_hl(0x287E);
  p00_L_3C87();
  set_hl(mem_read16(0x9869));
  p00_L_3C7B();
  set_hl(0x0106);
  mem_write16(0x844B, hl());
  set_hl(0x2889);
  p00_L_3C87();
  lab_p07_L_6D8F: ;
  p00_L_2E41();
  a = b;
  p07_L_77D2();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 7 cpu 0x6E8F (offset 0x2E8F) */
void p07_L_6E8F(void) {
  p00_L_0193();
  if (flag_z()) return;
  p00_L_1100();
  set_hl(0x9652);
  p00_rst20();
  set_hl(mem_read16(0x965D));
  set_de(mem_read16(0x965B));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  lab_p07_L_6EA4: ;
  mem_write16(0x86E0, hl());
  a = mem_read8(0x8479);
  flag_cmp(a, 0x24);
  if (flag_nz()) goto lab_p07_L_6EDA;
  p00_rst10();
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_6ED3;
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p00_L_1295();
  ix = cpu_pop16();
  p07_L_7156();
  ix = (uint16_t)(ix + 1);
  cpu_pop_af();
  mem_write8(0x8478, a);
  e = mem_read8(ix);
  d = mem_read8((uint16_t)(ix + 0x01));
  set_hl(mem_read16(0x86E0));
  set_hl((uint16_t)(hl() + de()));
  goto lab_p07_L_6EA4;
  lab_p07_L_6ED3: ;
  p00_L_113F();
  p00_L_002B();
  return;
  lab_p07_L_6EDA: ;
  cpu_push_hl();
  set_de(0x9652);
  p00_L_11FD();
  cpu_pop_hl();
  mem_write16(0x86E0, hl());
  p00_L_113F();
  a = 0;
  flag_logic(a);
  a = (uint8_t)(a + 1);
  return;
}

/* flash page 7 cpu 0x6EEB (offset 0x2EEB) */
void p07_L_6EEB(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  set_hl(0x261A);
  a = 0x0B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3C87();
  a = mem_read8(0x86DD);
  a = a & 0x7F;
  flag_logic(a);
  flag_cmp(a, 0x34);
  if (flag_c()) goto lab_p07_L_6F16;
  set_hl(0x70C0);
  goto lab_p07_L_6F2B;
  lab_p07_L_6F16: ;
  a = (uint8_t)(a - 1);
  e = a;
  d = 0x00;
  set_hl(0x6F3C);
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  a = 0x0C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  lab_p07_L_6F2B: ;
  set_de(0x85FE);
  p00_L_25D8();
  set_hl(0x85FE);
  p00_L_3C87();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 7 cpu 0x7140 (offset 0x3140) */
void p07_L_7140(void) {
  set_hl(0x859B);
  set_de(0x858D);
  set_bc(0x000E);
  while (bc() != 0) { cpu_ldi(); }
  a = mem_read8(hl());
  mem_write8((uint16_t)(iy + 0x0D), a);
  p00_L_179D();
  if (flag_z()) p00_L_176F();
  return;
}

/* flash page 7 cpu 0x7156 (offset 0x3156) */
void p07_L_7156(void) {
  set_hl(0x8479);
  b = mem_read8(ix);
  lab_p07_L_715C: ;
  ix = (uint16_t)(ix + 1);
  a = mem_read8(ix);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_715C;
  return;
}

/* flash page 7 cpu 0x7166 (offset 0x3166) */
void p07_L_7166(void) {
  set_hl(0x25A1);
  mem_write16(0x8595, hl());
  return;
}

/* flash page 7 cpu 0x716D (offset 0x316D) */
void p07_L_716D(void) {
  mem_write8(0x9D8E, a);
  p07_L_7170();
  return;
}

/* flash page 7 cpu 0x7170 (offset 0x3170) */
void p07_L_7170(void) {
  flag_cmp(a, 0x1E);
  if (flag_nz()) goto lab_p07_L_7179;
  p00_rst18();
  goto lab_p07_L_7192;
  lab_p07_L_7179: ;
  flag_cmp(a, 0x1D);
  if (flag_nz()) goto lab_p07_L_7185;
  p00_rst18();
  p00_L_1884();
  goto lab_p07_L_7198;
  lab_p07_L_7185: ;
  flag_cmp(a, 0x1F);
  if (flag_nz()) goto lab_p07_L_7198;
  p00_L_14D5();
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_2315();
  lab_p07_L_7192: ;
  p00_L_14D5();
  if (flag_nz()) { p00_L_24C9(); return; }
  lab_p07_L_7198: ;
  p00_L_3525();
  p00_L_32B5();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 3)));
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p00_L_22C7();
  p00_L_2324();
  p00_L_107E();
  cpu_push_af();
  if (flag_nc()) goto lab_p07_L_71B8;
  p00_L_2389();
  p00_L_2366();
  lab_p07_L_71B8: ;
  p00_L_3309();
  a = 0;
  flag_logic(a);
  mem_write8(0x8E67, a);
  set_hl(0x8F50);
  p00_rst20();
  p00_rst18();
  p00_L_3321();
  set_hl(mem_read16(0x84DD));
  mem_write16(0x9196, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p00_L_128A();
  p00_rst18();
  p00_rst18();
  d = 0x01;
  e = 0x01;
  cpu_push_de();
  p07_L_71DB();
  return;
}

/* flash page 7 cpu 0x71DB (offset 0x31DB) */
void p07_L_71DB(void) {
  set_hl(0x72D4);
  p00_L_25A2();
  p07_L_72F0();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 5)));
  p00_L_25C8();
  p07_L_71F0();
  return;
}

/* flash page 7 cpu 0x71F0 (offset 0x31F0) */
void p07_L_71F0(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 5)) == 0);
  if (flag_nz()) p00_L_233D();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  p00_L_3387();
  p00_L_22DE();
  p00_L_22ED();
  p00_rst08();
  p00_L_233D();
  set_hl(mem_read16(0x9196));
  p00_rst20();
  p00_L_2375();
  p00_L_338D();
  p00_L_0189();
  if (flag_nz()) goto lab_p07_L_72C2;
  p00_L_3393();
  p00_L_22F7();
  p00_L_2315();
  cpu_pop_de();
  e = (uint8_t)(e - 1);
  if (flag_z()) goto lab_p07_L_7228;
  cpu_push_de();
  goto lab_p07_L_7264;
  lab_p07_L_7228: ;
  e = d;
  cpu_push_de();
  p00_L_107E();
  if (flag_nc()) goto lab_p07_L_7264;
  p00_L_018E();
  if (flag_z()) goto lab_p07_L_7264;
  set_hl(mem_read16(0x9196));
  set_de(0x848E);
  p00_L_1183();
  set_hl(0x848E);
  p00_L_34A7();
  set_hl(mem_read16(0x9824));
  set_de(0xFFC1);
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  set_hl(0x848E);
  a = 0;
  flag_logic(a);
  p00_L_3405();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_7264;
  p00_L_113F();
  set_de(0x8499);
  p00_L_22FF();
  p00_L_2310();
  p00_L_356D();
  lab_p07_L_7264: ;
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + 1);
  flag_cmp(a, 0x5F);
  if (flag_nc()) goto lab_p07_L_7278;
  mem_write8(0x8E67, a);
  set_hl(mem_read16(0x9196));
  p00_L_340B();
  p07_L_71DB();
  return;
  lab_p07_L_7278: ;
  p00_L_333F();
  p00_L_21A7();
  p00_L_21A4();
  cpu_pop_de();
  cpu_pop_af();
  if (flag_nc()) goto lab_p07_L_7291;
  p00_L_2324();
  p00_L_22C7();
  p00_L_2389();
  p00_L_2366();
  lab_p07_L_7291: ;
  p00_L_22CF();
  set_hl(0x73DC);
  p00_L_25A2();
  p07_L_73B4();
  p00_L_32C7();
  p00_L_2324();
  p07_L_73A6();
  p07_L_7358();
  p00_L_219B();
  p07_L_732C();
  p07_L_7380();
  p00_L_25C8();
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 3)));
  mem_write16(0x982A, hl());
  return;
  lab_p07_L_72C2: ;
  p00_L_21A7();
  p00_L_21A4();
  p00_L_21A4();
  cpu_pop_de();
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  p00_L_32AF();
  return;
}

/* flash page 7 cpu 0x72F0 (offset 0x32F0) */
void p07_L_72F0(void) {
  p00_L_38F1();
  p00_L_22C7();
  a = mem_read8(0x9D8E);
  flag_cmp(a, 0x1E);
  p07_L_72FB();
  return;
}

/* flash page 7 cpu 0x72FB (offset 0x32FB) */
void p07_L_72FB(void) {
  if (flag_nz()) goto lab_p07_L_7304;
  a = 0x0A;
  p07_L_7300();
  return;
  lab_p07_L_7304: ;
  flag_cmp(a, 0x1D);
  if (flag_nz()) goto lab_p07_L_730E;
  a = 0x08;
  p07_L_7300();
  return;
  lab_p07_L_730E: ;
  p00_L_21E5();
  p00_L_2267();
  p00_L_21E5();
  p00_L_1179();
  a = mem_read8(0x9D8E);
  flag_cmp(a, 0x1F);
  if (flag_nz()) goto lab_p07_L_7327;
  a = 0x1C;
  p07_L_7300();
  return;
  lab_p07_L_7327: ;
  a = 0x0C;
  p07_L_7300();
  return;
}

/* flash page 7 cpu 0x7300 (offset 0x3300) */
void p07_L_7300(void) {
  p00_L_396F();
  return;
}

/* flash page 7 cpu 0x732C (offset 0x332C) */
void p07_L_732C(void) {
  a = mem_read8(0x9D8E);
  flag_cmp(a, 0x1E);
  if (flag_nz()) goto lab_p07_L_733C;
  p00_L_21A7();
  a = 0x16;
  p07_L_7300();
  return;
  lab_p07_L_733C: ;
  flag_cmp(a, 0x1D);
  if (flag_nz()) goto lab_p07_L_7349;
  p00_L_21A7();
  a = 0x18;
  p07_L_7300();
  return;
  lab_p07_L_7349: ;
  flag_cmp(a, 0x1F);
  if (flag_nz()) goto lab_p07_L_7353;
  a = 0x14;
  p07_L_7300();
  return;
  lab_p07_L_7353: ;
  a = 0x1A;
  p07_L_7300();
  return;
}

/* flash page 7 cpu 0x7358 (offset 0x3358) */
void p07_L_7358(void) {
  a = mem_read8(0x9D8E);
  flag_cmp(a, 0x1E);
  if (flag_z()) goto lab_p07_L_7362;
  flag_cmp(a, 0x1D);
  if (flag_nz()) return;
  lab_p07_L_7362: ;
  p00_L_18B7();
  if (flag_z()) goto lab_p07_L_736C;
  p00_L_32CD();
  goto lab_p07_L_736F;
  lab_p07_L_736C: ;
  p00_L_32D3();
  lab_p07_L_736F: ;
  p00_L_22FC();
  set_hl(0x27E2);
  a = 0x6C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p07_L_73C0;
  lab_p07_L_73C0: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p00_L_3345();
  p00_L_3D4D();
  a = 0x07;
  p00_L_32DF();
  p07_L_73D3();
  return;
}

/* flash page 7 cpu 0x7380 (offset 0x3380) */
void p07_L_7380(void) {
  a = mem_read8(0x9D8E);
  flag_cmp(a, 0x1E);
  if (flag_z()) goto lab_p07_L_738B;
  flag_cmp(a, 0x1D);
  if (flag_nz()) goto lab_p07_L_7395;
  lab_p07_L_738B: ;
  p00_L_18B7();
  if (flag_z()) goto lab_p07_L_7395;
  p00_L_32D3();
  goto lab_p07_L_7398;
  lab_p07_L_7395: ;
  p00_L_32CD();
  lab_p07_L_7398: ;
  set_hl(0x27E6);
  a = 0x6E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p07_L_73C0;
  lab_p07_L_73C0: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p00_L_3345();
  p00_L_3D4D();
  a = 0x07;
  p00_L_32DF();
  p07_L_73D3();
  return;
}

/* flash page 7 cpu 0x73A6 (offset 0x33A6) */
void p07_L_73A6(void) {
  set_hl(0x27EC);
  a = 0x6D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p07_L_73C0;
  lab_p07_L_73C0: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p00_L_3345();
  p00_L_3D4D();
  a = 0x07;
  p00_L_32DF();
  p07_L_73D3();
  return;
}

/* flash page 7 cpu 0x73B4 (offset 0x33B4) */
void p07_L_73B4(void) {
  set_hl(0x27F0);
  a = 0x6F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p00_L_3345();
  p00_L_3D4D();
  a = 0x07;
  p00_L_32DF();
  p07_L_73D3();
  return;
}

/* flash page 7 cpu 0x73D3 (offset 0x33D3) */
void p07_L_73D3(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 7)));
  return;
}

/* flash page 7 cpu 0x73E2 (offset 0x33E2) */
void p07_L_73E2(void) {
  lab_p07_L_73E2: ;
  p00_L_1037();
  flag_cmp(a, 0x0F);
  if (flag_c()) goto lab_p07_L_7437;
  flag_cmp(a, 0x17);
  if (flag_z()) goto lab_p07_L_7437;
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p07_L_7437;
  flag_cmp(a, 0x16);
  if (flag_z()) goto lab_p07_L_7437;
  flag_cmp(a, 0x14);
  if (flag_z()) goto lab_p07_L_73FF;
  flag_cmp(a, 0x11);
  if (flag_z()) goto lab_p07_L_745F;
  goto lab_p07_L_7426;
  lab_p07_L_73FF: ;
  p00_L_2DAB();
  a = 0x14;
  if (flag_c()) goto lab_p07_L_743F;
  p07_L_7406();
  return;
  lab_p07_L_7426: ;
  a = (uint8_t)(a + 1);
  p07_L_7427();
  return;
  lab_p07_L_7437: ;
  cpu_push_af();
  lab_p07_L_7438: ;
  a = 0;
  flag_logic(a);
  p07_L_5128();
  if (flag_nc()) goto lab_p07_L_746B;
  cpu_pop_af();
  lab_p07_L_743F: ;
  p07_L_7498();
  if (flag_c()) return;
  mem_write8(0x8478, a);
  cpu_push_hl();
  set_hl(0x8479);
  mem_write8(hl(), 0xFE);
  cpu_pop_hl();
  if (flag_nz()) return;
  flag_cmp(a, 0x14);
  if (flag_z()) goto lab_p07_L_7464;
  p00_L_17B3();
  if (flag_z()) goto lab_p07_L_7464;
  b = 0xFF;
  mem_write16(0x8479, bc());
  goto lab_p07_L_73E2;
  lab_p07_L_745F: ;
  a = 0x00;
  p07_L_7461();
  return;
  lab_p07_L_7464: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8479, a);
  goto lab_p07_L_73E2;
  lab_p07_L_746B: ;
  p07_L_7472();
  if (flag_c()) goto lab_p07_L_7438;
  cpu_pop_bc();
  return;
}

/* flash page 7 cpu 0x7406 (offset 0x3406) */
void p07_L_7406(void) {
  a = d;
  goto lab_p07_L_740C;
  lab_p07_L_740C: ;
  cpu_push_af();
  a = 0x14;
  mem_write8(0x8478, a);
  cpu_pop_af();
  set_hl(0x8697);
  p00_L_24A9();
  if (flag_z()) goto lab_p07_L_741F;
  a = a & 0x1F;
  flag_logic(a);
  goto lab_p07_L_7432;
  lab_p07_L_741F: ;
  b = a;
  p00_L_2DB1();
  /* scf */
  /* ccf */
  return;
  lab_p07_L_7432: ;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 7 cpu 0x7427 (offset 0x3427) */
void p07_L_7427(void) {
  mem_write8(0x8478, a);
  set_hl(0x8479);
  mem_write8(hl(), 0xFE);
  p07_L_742F();
  return;
}

/* flash page 7 cpu 0x742F (offset 0x342F) */
void p07_L_742F(void) {
  set_hl(0x8685);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 7 cpu 0x7461 (offset 0x3461) */
void p07_L_7461(void) {
  mem_write8(0x8478, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x8479, a);
  p07_L_73E2();
  return;
}

/* flash page 7 cpu 0x7472 (offset 0x3472) */
void p07_L_7472(void) {
  a = mem_read8(0x8479);
  flag_cmp(a, 0x62);
  if (flag_z()) goto lab_p07_L_748C;
  p00_L_2DB7();
  if (flag_z()) goto lab_p07_L_748C;
  a = mem_read8(0x85D9);
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p07_L_7496;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x06);
  if (flag_c()) goto lab_p07_L_748F;
  lab_p07_L_748C: ;
  /* scf */
  goto lab_p07_L_7497;
  lab_p07_L_748F: ;
  p00_L_1037();
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p07_L_748C;
  lab_p07_L_7496: ;
  a = a | a;
  flag_logic(a);
  lab_p07_L_7497: ;
  return;
}

/* flash page 7 cpu 0x7473 (offset 0x3473) */
void p07_L_7473(void) {
  a = c;
  a = (uint8_t)(a + h);
  flag_cmp(a, 0x62);
  if (flag_z()) goto lab_p07_L_748C;
  p00_L_2DB7();
  if (flag_z()) goto lab_p07_L_748C;
  a = mem_read8(0x85D9);
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p07_L_7496;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x06);
  if (flag_c()) goto lab_p07_L_748F;
  lab_p07_L_748C: ;
  /* scf */
  goto lab_p07_L_7497;
  lab_p07_L_748F: ;
  p00_L_1037();
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p07_L_748C;
  lab_p07_L_7496: ;
  a = a | a;
  flag_logic(a);
  lab_p07_L_7497: ;
  return;
}

/* flash page 7 cpu 0x7498 (offset 0x3498) */
void p07_L_7498(void) {
  p07_L_7641();
  if (flag_c()) return;
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p07_L_74A3;
  a = 0x0C;
  return;
  lab_p07_L_74A3: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p07_L_74AA;
  a = 0x04;
  return;
  lab_p07_L_74AA: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p07_L_74BC;
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_74B6;
  /* scf */
  return;
  lab_p07_L_74B6: ;
  cpu_pop_af();
  a = 0x14;
  p07_L_7461();
  return;
  lab_p07_L_74BC: ;
  flag_cmp(a, 0x0B);
  if (flag_z()) goto lab_p07_L_74C4;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p07_L_74C8;
  lab_p07_L_74C4: ;
  a = 0;
  flag_logic(a);
  a = 0x15;
  return;
  lab_p07_L_74C8: ;
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p07_L_74CE;
  /* scf */
  return;
  lab_p07_L_74CE: ;
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p07_L_74DB;
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p07_L_74E7;
  a = 0x17;
  return;
  lab_p07_L_74DB: ;
  flag_cmp(a, 0x17);
  if (flag_nz()) goto lab_p07_L_74EE;
  /* bit 0,(iy) */
  a = 0x00;
  if (flag_nz()) goto lab_p07_L_74EC;
  lab_p07_L_74E7: ;
  set_hl(0x8694);
  a = 0x0F;
  lab_p07_L_74EC: ;
  a = a | a;
  flag_logic(a);
  return;
  lab_p07_L_74EE: ;
  flag_cmp(a, 0x0F);
  if (flag_nz()) goto lab_p07_L_74F8;
  set_hl(0x8695);
  lab_p07_L_74F5: ;
  a = (uint8_t)(a + 1);
  a = a | a;
  flag_logic(a);
  return;
  lab_p07_L_74F8: ;
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p07_L_7500;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p07_L_7505;
  lab_p07_L_7500: ;
  a = 0x08;
  c = 0x61;
  return;
  lab_p07_L_7505: ;
  set_hl(0x8696);
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p07_L_74F5;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p07_L_7514;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p07_L_7519;
  lab_p07_L_7514: ;
  a = 0x02;
  c = 0x5C;
  return;
  lab_p07_L_7519: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p07_L_7522;
  a = 0x03;
  c = 0x5E;
  return;
  lab_p07_L_7522: ;
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p07_L_752B;
  a = 0x01;
  c = 0x5D;
  return;
  lab_p07_L_752B: ;
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p07_L_7534;
  a = 0x07;
  c = 0x60;
  return;
  lab_p07_L_7534: ;
  a = 0x08;
  flag_cmp(a, a);
  c = 0x61;
  return;
}

/* flash page 7 cpu 0x753A (offset 0x353A) */
void p07_L_753A(void) {
  lab_p07_L_753A: ;
  p00_L_1037();
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p07_L_754B;
  p00_L_2DBD();
  a = 0x14;
  if (flag_c()) goto lab_p07_L_7571;
  p07_L_7406();
  return;
  lab_p07_L_754B: ;
  flag_cmp(a, 0x17);
  if (flag_z()) goto lab_p07_L_7568;
  flag_cmp(a, 0x0F);
  if (flag_c()) goto lab_p07_L_7568;
  if (flag_nz()) goto lab_p07_L_755D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 1)) == 0);
  if (flag_nz()) { p07_L_759D(); return; }
  goto lab_p07_L_75A4;
  lab_p07_L_755D: ;
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p07_L_7568;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_7568;
  a = (uint8_t)(a - 1);
  p07_L_7427();
  return;
  lab_p07_L_7568: ;
  cpu_push_af();
  lab_p07_L_7569: ;
  a = 0;
  flag_logic(a);
  p07_L_512B();
  if (flag_nc()) goto lab_p07_L_75B1;
  cpu_pop_af();
  lab_p07_L_7571: ;
  p07_L_75B8();
  if (flag_c()) return;
  mem_write8(0x8478, a);
  cpu_push_hl();
  set_hl(0x8479);
  mem_write8(hl(), 0xFE);
  cpu_pop_hl();
  if (flag_nz()) return;
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p07_L_7588;
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p07_L_7592;
  lab_p07_L_7588: ;
  b = 0x00;
  c = 0x5C;
  mem_write16(0x8479, bc());
  goto lab_p07_L_753A;
  lab_p07_L_7592: ;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p07_L_75A8;
  lab_p07_L_7596: ;
  a = 0xFE;
  mem_write8(0x8479, a);
  goto lab_p07_L_753A;
  lab_p07_L_759F: ;
  mem_write8(0x8478, a);
  goto lab_p07_L_7596;
  lab_p07_L_75A4: ;
  a = 0x17;
  goto lab_p07_L_759F;
  lab_p07_L_75A8: ;
  b = 0xFE;
  mem_write16(0x8479, bc());
  goto lab_p07_L_753A;
  lab_p07_L_75B1: ;
  p07_L_7472();
  if (flag_c()) goto lab_p07_L_7569;
  cpu_pop_bc();
  return;
}

/* flash page 7 cpu 0x759D (offset 0x359D) */
void p07_L_759D(void) {
  goto lab_p07_L_759D;
  lab_p07_L_7596: ;
  a = 0xFE;
  mem_write8(0x8479, a);
  p07_L_753A();
  return;
  lab_p07_L_759D: ;
  a = 0x15;
  mem_write8(0x8478, a);
  goto lab_p07_L_7596;
}

/* flash page 7 cpu 0x75B8 (offset 0x35B8) */
void p07_L_75B8(void) {
  goto lab_p07_L_75B8;
  lab_p07_L_7596: ;
  a = 0xFE;
  mem_write8(0x8479, a);
  p07_L_753A();
  return;
  lab_p07_L_759F: ;
  mem_write8(0x8478, a);
  goto lab_p07_L_7596;
  lab_p07_L_75A4: ;
  a = 0x17;
  goto lab_p07_L_759F;
  lab_p07_L_75B8: ;
  p07_L_7641();
  if (flag_c()) return;
  flag_cmp(a, 0x05);
  /* scf */
  if (flag_z()) return;
  flag_cmp(a, 0x06);
  /* scf */
  if (flag_z()) return;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_75D7;
  /* bit 0,(iy) */
  if (flag_z()) goto lab_p07_L_75D0;
  cpu_pop_af();
  goto lab_p07_L_75A4;
  lab_p07_L_75D0: ;
  set_hl(0x8696);
  a = 0x11;
  a = a | a;
  flag_logic(a);
  return;
  lab_p07_L_75D7: ;
  flag_cmp(a, 0x11);
  if (flag_nz()) goto lab_p07_L_75E1;
  set_hl(0x8695);
  lab_p07_L_75DE: ;
  a = (uint8_t)(a - 1);
  a = a | a;
  flag_logic(a);
  return;
  lab_p07_L_75E1: ;
  set_hl(0x8694);
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p07_L_75DE;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p07_L_75F1;
  a = 0x01;
  c = 0x5D;
  return;
  lab_p07_L_75F1: ;
  flag_cmp(a, 0x0B);
  if (flag_z()) goto lab_p07_L_75F9;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p07_L_75FE;
  lab_p07_L_75F9: ;
  a = 0x02;
  c = 0x5C;
  return;
  lab_p07_L_75FE: ;
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p07_L_7608;
  a = 0;
  flag_logic(a);
  a = 0x03;
  c = 0x5E;
  return;
  lab_p07_L_7608: ;
  flag_cmp(a, 0x17);
  if (flag_nz()) goto lab_p07_L_7610;
  cpu_pop_af();
  p07_L_759D();
  return;
  lab_p07_L_7610: ;
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p07_L_7619;
  a = 0x04;
  c = 0xAA;
  return;
  lab_p07_L_7619: ;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p07_L_7621;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p07_L_7626;
  lab_p07_L_7621: ;
  a = 0x07;
  c = 0x60;
  return;
  lab_p07_L_7626: ;
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p07_L_762F;
  a = 0x08;
  c = 0x61;
  return;
  lab_p07_L_762F: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p07_L_7636;
  a = 0x00;
  return;
  lab_p07_L_7636: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p07_L_763D;
  a = 0x0C;
  return;
  lab_p07_L_763D: ;
  a = 0x05;
  flag_cmp(a, a);
  return;
}

/* flash page 7 cpu 0x7641 (offset 0x3641) */
void p07_L_7641(void) {
  c = a;
  /* bit 0,(iy) */
  if (flag_nz()) goto lab_p07_L_764F;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p07_L_7654;
  lab_p07_L_764F: ;
  a = mem_read8(0x85D9);
  flag_cmp(a, 0x09);
  lab_p07_L_7654: ;
  a = c;
  if (flag_z()) return;
  /* scf */
  return;
}

/* flash page 7 cpu 0x7658 (offset 0x3658) */
void p07_L_7658(void) {
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 6)));
  a = 0x0E;
  set_hl(0x8A3A);
  b = 0x35;
  set_de(0x0009);
  lab_p07_L_7666: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + de()));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_7666;
  p00_L_1691();
  p00_rst10();
  if (flag_nc()) p00_L_1F58();
  a = 0xFF;
  set_hl(0x8D2A);
  mem_write8(hl(), a);
  set_de(0x8D2B);
  set_bc(0x0063);
  while (bc() != 0) { cpu_ldi(); }
  mem_write8(0x8D8E, a);
  return;
}

/* flash page 7 cpu 0x7675 (offset 0x3675) */
void p07_L_7675(void) {
  /* adc a,l */
  mem_write8(hl(), a);
  set_de(0x8D2B);
  set_bc(0x0063);
  while (bc() != 0) { cpu_ldi(); }
  mem_write8(0x8D8E, a);
  return;
}

/* flash page 7 cpu 0x7683 (offset 0x3683) */
void p07_L_7683(void) {
  goto lab_p07_L_7683;
  lab_p07_L_7409: ;
  p00_L_2E77();
  cpu_push_af();
  a = 0x14;
  mem_write8(0x8478, a);
  cpu_pop_af();
  set_hl(0x8697);
  p00_L_24A9();
  if (flag_z()) goto lab_p07_L_741F;
  a = a & 0x1F;
  flag_logic(a);
  goto lab_p07_L_7432;
  lab_p07_L_741F: ;
  b = a;
  p00_L_2DB1();
  /* scf */
  /* ccf */
  return;
  lab_p07_L_7432: ;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  return;
  lab_p07_L_7683: ;
  p00_L_1037();
  flag_cmp(a, 0x0F);
  if (flag_c()) { p00_L_19ED(); return; }
  flag_cmp(a, 0x15);
  if (flag_z()) { p00_L_19ED(); return; }
  flag_cmp(a, 0x16);
  if (flag_z()) { p00_L_19ED(); return; }
  flag_cmp(a, 0x17);
  if (flag_z()) { p00_L_19ED(); return; }
  flag_cmp(a, 0x14);
  if (flag_z()) goto lab_p07_L_7409;
  p07_L_742F();
  return;
}

/* flash page 7 cpu 0x7685 (offset 0x3685) */
void p07_L_7685(void) {
  goto lab_p07_L_7685;
  lab_p07_L_7409: ;
  p00_L_2E77();
  cpu_push_af();
  a = 0x14;
  mem_write8(0x8478, a);
  cpu_pop_af();
  set_hl(0x8697);
  p00_L_24A9();
  if (flag_z()) goto lab_p07_L_741F;
  a = a & 0x1F;
  flag_logic(a);
  goto lab_p07_L_7432;
  lab_p07_L_741F: ;
  b = a;
  p00_L_2DB1();
  /* scf */
  /* ccf */
  return;
  lab_p07_L_7432: ;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  return;
  lab_p07_L_7685: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_7685;
  cpu_rrca();
  if (flag_c()) { p00_L_19ED(); return; }
  flag_cmp(a, 0x15);
  if (flag_z()) { p00_L_19ED(); return; }
  flag_cmp(a, 0x16);
  if (flag_z()) { p00_L_19ED(); return; }
  flag_cmp(a, 0x17);
  if (flag_z()) { p00_L_19ED(); return; }
  flag_cmp(a, 0x14);
  if (flag_z()) goto lab_p07_L_7409;
  p07_L_742F();
  return;
}

/* flash page 7 cpu 0x76C6 (offset 0x36C6) */
void p07_L_76C6(void) {
  set_hl(0x8670);
  flag_set_z((mem_read8(hl()) & (1u << 4)) == 0);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 4)));
  if (flag_z()) { p07_L_76D2(); return; }
  p00_L_3CDB();
  p07_L_76D2();
  return;
}

/* flash page 7 cpu 0x76D2 (offset 0x36D2) */
void p07_L_76D2(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = 0x20;
  p00_L_3F9F();
  a = 0x20;
  p00_L_3F9F();
  /* ei */
  set_hl(0x85D0);
  a = mem_read8(0x85D9);
  flag_cmp(a, 0x14);
  if (flag_z()) goto lab_p07_L_77A3;
  a = mem_read8(hl());
  flag_cmp(a, 0x14);
  if (flag_z()) goto lab_p07_L_77A3;
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p07_L_7709;
  flag_cmp(a, 0x17);
  if (flag_z()) goto lab_p07_L_7709;
  a = (uint8_t)(a - 0x0F);
  if (flag_nc()) goto lab_p07_L_7807;
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  p00_L_17BE();
  if (flag_nz()) goto lab_p07_L_7718;
  lab_p07_L_7709: ;
  b = 0x08;
  lab_p07_L_770B: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_7735;
  p00_L_3F9F();
  /* ei */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_770B;
  goto lab_p07_L_7735;
  lab_p07_L_7718: ;
  set_hl((uint16_t)(hl() + 1));
  p00_L_1830();
  if (flag_nz()) goto lab_p07_L_7724;
  set_hl((uint16_t)(hl() + 1));
  p00_L_3135();
  goto lab_p07_L_7739;
  lab_p07_L_7724: ;
  p00_L_172F();
  d = 0x00;
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  if (flag_nz()) goto lab_p07_L_772F;
  d = e;
  e = mem_read8(hl());
  lab_p07_L_772F: ;
  p00_L_3DB9();
  p07_L_7732();
  return;
  lab_p07_L_7735: ;
  p00_L_3D1D();
  /* ei */
  lab_p07_L_7739: ;
  p00_L_2F91();
  p00_L_19ED();
  cpu_push_af();
  a = 0x01;
  mem_write8(0x844C, a);
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  if (flag_z()) goto lab_p07_L_7755;
  cpu_push_hl();
  cpu_ex_de_hl();
  p00_L_3267();
  d = b;
  e = c;
  cpu_pop_hl();
  p07_L_77F6();
  lab_p07_L_7755: ;
  /* bit 0,(iy) */
  if (flag_z()) goto lab_p07_L_778B;
  a = 0x0B;
  mem_write8(0x844C, a);
  p00_L_1822();
  a = 0x03;
  if (flag_nz()) goto lab_p07_L_776F;
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  a = (uint8_t)(a + 1);
  lab_p07_L_776F: ;
  a = (uint8_t)(a + 0x06);
  c = a;
  cpu_pop_af();
  cpu_pop_hl();
  a = h;
  b = 0x00;
  cpu_push_bc();
  if (flag_z()) goto lab_p07_L_777F;
  p00_L_20F8();
  goto lab_p07_L_7783;
  lab_p07_L_777F: ;
  cpu_ex_de_hl();
  p00_L_210A();
  lab_p07_L_7783: ;
  cpu_ex_de_hl();
  cpu_pop_bc();
  set_hl((uint16_t)(hl() + bc()));
  p00_L_3C7B();
  /* ei */
  return;
  lab_p07_L_778B: ;
  cpu_pop_af();
  cpu_pop_af();
  p07_L_778D();
  return;
  lab_p07_L_77A3: ;
  mem_write8(hl(), a);
  set_hl(0x844C);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  a = 0x2A;
  p00_L_3F9F();
  set_hl(0x8479);
  p00_L_3C87();
  p00_L_3D1D();
  a = mem_read8(0x859A);
  flag_cmp(a, 0x41);
  if (flag_z()) goto lab_p07_L_77F1;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x19);
  if (flag_z()) goto lab_p07_L_77F1;
  a = 0x0A;
  mem_write8(0x844C, a);
  /* di */
  p00_L_2E77();
  /* di */
  p00_L_2DC3();
  a = c;
  p07_L_77D2();
  return;
  lab_p07_L_77F1: ;
  p07_L_778D();
  /* ei */
  return;
  lab_p07_L_7807: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_7815;
  b = a;
  a = 0x3A;
  p00_L_3C45();
  if (flag_z()) goto lab_p07_L_781B;
  lab_p07_L_7815: ;
  set_hl(0x78C8);
  p07_L_77FF();
  lab_p07_L_781B: ;
  set_de(0x8483);
  p00_L_1181();
  set_hl(0x8483);
  p07_L_7732();
  return;
}

/* flash page 7 cpu 0x7732 (offset 0x3732) */
void p07_L_7732(void) {
  p00_L_3C93();
  p00_L_3D1D();
  /* ei */
  p00_L_2F91();
  p00_L_19ED();
  cpu_push_af();
  a = 0x01;
  mem_write8(0x844C, a);
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  if (flag_z()) goto lab_p07_L_7755;
  cpu_push_hl();
  cpu_ex_de_hl();
  p00_L_3267();
  d = b;
  e = c;
  cpu_pop_hl();
  p07_L_77F6();
  lab_p07_L_7755: ;
  /* bit 0,(iy) */
  if (flag_z()) goto lab_p07_L_778B;
  a = 0x0B;
  mem_write8(0x844C, a);
  p00_L_1822();
  a = 0x03;
  if (flag_nz()) goto lab_p07_L_776F;
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  a = (uint8_t)(a + 1);
  lab_p07_L_776F: ;
  a = (uint8_t)(a + 0x06);
  c = a;
  cpu_pop_af();
  cpu_pop_hl();
  a = h;
  b = 0x00;
  cpu_push_bc();
  if (flag_z()) goto lab_p07_L_777F;
  p00_L_20F8();
  goto lab_p07_L_7783;
  lab_p07_L_777F: ;
  cpu_ex_de_hl();
  p00_L_210A();
  lab_p07_L_7783: ;
  cpu_ex_de_hl();
  cpu_pop_bc();
  set_hl((uint16_t)(hl() + bc()));
  p00_L_3C7B();
  /* ei */
  return;
  lab_p07_L_778B: ;
  cpu_pop_af();
  cpu_pop_af();
  p07_L_778D();
  return;
}

/* flash page 7 cpu 0x778D (offset 0x378D) */
void p07_L_778D(void) {
  a = 0x0B;
  mem_write8(0x844C, a);
  a = mem_read8(0x85D0);
  p07_L_7827();
  p00_L_11F8();
  set_hl(0x8483);
  p00_L_3C81();
  /* ei */
  return;
}

/* flash page 7 cpu 0x77D2 (offset 0x37D2) */
void p07_L_77D2(void) {
  set_hl(0x0000);
  mem_write16(0x839F, hl());
  mem_write16(0x83A1, hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_77EB;
  set_de(0x0040);
  b = a;
  lab_p07_L_77E2: ;
  set_hl((uint16_t)(hl() + de()));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_77E2;
  a = h;
  h = l;
  l = a;
  mem_write16(0x83A0, hl());
  lab_p07_L_77EB: ;
  a = 0x06;
  p00_L_3C75();
  return;
}

/* flash page 7 cpu 0x77F6 (offset 0x37F6) */
void p07_L_77F6(void) {
  a = 0x2A;
  p00_L_3F9F();
  return;
}

/* flash page 7 cpu 0x77FC (offset 0x37FC) */
void p07_L_77FC(void) {
  set_hl(0x78C2);
  p07_L_77FF();
  return;
}

/* flash page 7 cpu 0x77FF (offset 0x37FF) */
void p07_L_77FF(void) {
  a = (uint8_t)(a + a);
  d = 0x00;
  e = a;
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  return;
}

/* flash page 7 cpu 0x7827 (offset 0x3827) */
void p07_L_7827(void) {
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x18);
  if (flag_c()) goto lab_p07_L_782F;
  a = 0x09;
  lab_p07_L_782F: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_783C;
  b = a;
  a = 0x3B;
  p00_L_3C45();
  if (flag_z()) return;
  lab_p07_L_783C: ;
  set_hl(0x7841);
  p07_L_77FF();
  return;
}

/* flash page 7 cpu 0x7877 (offset 0x3877) */
void p07_L_7877(void) {
  c = c;
  d = e;
  d = h;
  /* nop */
  c = l;
  b = c;
  d = h;
  d = d;
  e = b;
  /* nop */
  b = l;
  d = c;
  d = l;
  /* nop */
  b = a;
  b = h;
  b = d;
  /* nop */
  d = b;
  c = c;
  b = e;
  /* nop */
  d = b;
  d = d;
  b = a;
  c = l;
  /* nop */
  b = e;
  d = b;
  c = h;
  e = b;
  /* nop */
  d = a;
  c = c;
  c = mem_read8(hl());
  b = h;
  d = a;
  /* nop */
  e = d;
  d = e;
  d = h;
  c = a;
  /* nop */
  d = h;
  b = c;
  b = d;
  c = h;
  b = l;
  /* nop */
  d = e;
  d = h;
  d = d;
  c = mem_read8(hl());
  b = a;
  /* nop */
  b = c;
  d = b;
  d = b;
  /* nop */
  b = c;
  d = mem_read8(hl());
  b = c;
  d = d;
  /* nop */
  d = l;
  c = mem_read8(hl());
  c = e;
  c = mem_read8(hl());
  /* nop */
  b = a;
  d = d;
  c = a;
  d = l;
  d = b;
  /* nop */
  c = l;
  /* adc a,a */
  a = h;
  /* adc a,(hl) */
  a = a | c;
  flag_logic(a);
  a = (uint8_t)(a - d);
  /* adc a,0x78 */
  cpu_push_de();
  a = b;
  p00_rst18();
  a = b;
  b = 0x57;
  l = c;
  l = mem_read8(hl());
  h = h;
  l = a;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + bc()));
  d = d;
  h = e;
  l = h;
  d = a;
  l = c;
  l = mem_read8(hl());
  h = h;
  l = a;
  mem_write8(hl(), a);
  b = 0x54;
  h = d;
  l = h;
  d = e;
  h = l;
  mem_write8(hl(), h);
  p07_L_78E6();
  return;
}

/* flash page 7 cpu 0x78E6 (offset 0x38E6) */
void p07_L_78E6(void) {
  mem_write8(0x9CB0, a);
  a = a & 0x7F;
  flag_logic(a);
  flag_cmp(a, 0x7F);
  if (flag_z()) goto lab_p07_L_792B;
  flag_cmp(a, 0x60);
  if (flag_nc()) goto lab_p07_L_792B;
  flag_cmp(a, 0x50);
  if (flag_c()) goto lab_p07_L_7905;
  a = a & 0x0F;
  flag_logic(a);
  b = a;
  a = 0xF0;
  /* and (iy+0x3D) */
  a = a | b;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x3D), a);
  goto lab_p07_L_7933;
  lab_p07_L_7905: ;
  flag_cmp(a, 0x41);
  if (flag_nc()) goto lab_p07_L_792B;
  flag_cmp(a, 0x12);
  if (flag_z()) goto lab_p07_L_792B;
  flag_cmp(a, 0x1A);
  if (flag_z()) goto lab_p07_L_792B;
  flag_cmp(a, 0x24);
  if (flag_z()) goto lab_p07_L_792B;
  flag_cmp(a, 0x2C);
  if (flag_z()) goto lab_p07_L_792B;
  p07_L_793B();
  cpu_push_af();
  a = mem_read8(0x9CB0);
  b = a;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_7933;
  c = a;
  a = c;
  mem_write8(0x8444, a);
  return;
  lab_p07_L_792B: ;
  a = mem_read8((uint16_t)(iy + 0x3D));
  a = a & 0xF0;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x3D), a);
  lab_p07_L_7933: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x9CB0, a);
  mem_write8(0x9CB1, a);
  return;
}

/* flash page 7 cpu 0x792D (offset 0x392D) */
void p07_L_792D(void) {
  a = (uint8_t)(a - 1);
  a = a & 0xF0;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x3D), a);
  a = 0;
  flag_logic(a);
  mem_write8(0x9CB0, a);
  mem_write8(0x9CB1, a);
  return;
}

/* flash page 7 cpu 0x793B (offset 0x393B) */
void p07_L_793B(void) {
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  a = (uint8_t)(a - 1);
  c = a;
  set_hl(0x7AEE);
  a = mem_read8((uint16_t)(iy + 0x3D));
  a = a & 0x0F;
  flag_logic(a);
  flag_cmp(a, 0x08);
  if (flag_z()) goto lab_p07_L_7952;
  set_hl(0x7AAE);
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p07_L_795E;
  lab_p07_L_7952: ;
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  lab_p07_L_7956: ;
  mem_write8(0x8446, a);
  a = 0xFB;
  p07_L_79E2();
  return;
  lab_p07_L_795E: ;
  flag_cmp(a, 0x03);
  if (flag_c()) goto lab_p07_L_796C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x3D)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p07_L_796C;
  a = 0x8B;
  goto lab_p07_L_7956;
  lab_p07_L_796C: ;
  set_hl(0x7A47);
  a = a & 0x03;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_7976;
  set_hl(0x79EE);
  lab_p07_L_7976: ;
  cpu_push_hl();
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  cpu_pop_hl();
  cpu_push_af();
  cpu_push_hl();
  set_de(0x0008);
  cpu_sbc_hl_de();
  a = c;
  /* srl a */
  /* srl a */
  /* srl a */
  e = a;
  set_hl((uint16_t)(hl() + de()));
  a = c;
  a = a & 0x07;
  flag_logic(a);
  a = (uint8_t)(a + 1);
  b = a;
  a = mem_read8(hl());
  lab_p07_L_7992: ;
  /* srl a */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_7992;
  a = 0x32;
  if (flag_c()) goto lab_p07_L_799B;
  a = 0;
  flag_logic(a);
  lab_p07_L_799B: ;
  mem_write8(0x9CB1, a);
  cpu_pop_hl();
  set_de(0x0040);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_79B0;
  b = a;
  a = c;
  lab_p07_L_79A9: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_cp_hl();
  if (flag_z()) goto lab_p07_L_79D9;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_79A9;
  lab_p07_L_79B0: ;
  cpu_pop_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 3)) == 0);
  if (flag_z()) return;
  b = a;
  a = mem_read8((uint16_t)(iy + 0x3D));
  a = a & 0x03;
  flag_logic(a);
  a = mem_read8(0x9CB0);
  if (flag_z()) goto lab_p07_L_79C7;
  a = a & 0x80;
  flag_logic(a);
  a = b;
  if (flag_z()) return;
  goto lab_p07_L_79CB;
  lab_p07_L_79C7: ;
  a = a & 0x80;
  flag_logic(a);
  a = b;
  if (flag_nz()) return;
  lab_p07_L_79CB: ;
  flag_cmp(a, 0x9A);
  if (flag_c()) return;
  flag_cmp(a, 0xB4);
  if (flag_nc()) return;
  a = (uint8_t)(a + 0x48);
  mem_write8(0x8446, a);
  a = 0xFC;
  return;
  lab_p07_L_79D9: ;
  cpu_pop_af();
  mem_write8(0x8446, a);
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0xFB);
  if (flag_nz()) return;
  p07_L_79E2();
  return;
}

/* flash page 7 cpu 0x79E2 (offset 0x39E2) */
void p07_L_79E2(void) {
  p07_L_7B2E();
  return;
}

/* flash page 7 cpu 0x7A79 (offset 0x3A79) */
void p07_L_7A79(void) {
  a = a ^ c;
  flag_logic(a);
  /* call 0x8BCB - RAM/other */
  c = 0x15;
  set_hl(0x0980);
  /* db 0xED,0x05 */
  if (flag_z()) { p00_L_160C(); return; }
  set_de((uint16_t)(de() + 1));
  /* nop */
  flag_cmp(a, 0x01);
  /* ei */
  mem_write8(bc(), a);
  /* ei */
  b = (uint8_t)(b - 1);
  /* ei */
  cpu_rlca();
  /* ei */
  cpu_ex_af();
  lab_p07_L_7A93: ;
  /* ei */
  set_hl((uint16_t)(hl() + bc()));
  lab_p07_L_7A95: ;
  /* ei */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_7A93;
  goto lab_p07_L_7A95;
}

/* flash page 7 cpu 0x7B2E (offset 0x3B2E) */
void p07_L_7B2E(void) {
  c = a;
  a = mem_read8(0x8446);
  flag_set_z((mem_read8((uint16_t)(iy + 0x3E)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p07_L_7B42;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p07_L_7B40;
  flag_cmp(a, 0x0E);
  if (flag_nz()) goto lab_p07_L_7B42;
  lab_p07_L_7B40: ;
  a = c;
  return;
  lab_p07_L_7B42: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x3D)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p07_L_7B40;
  b = 0x14;
  set_hl(0x7B65);
  lab_p07_L_7B4D: ;
  cpu_cp_hl();
  set_hl((uint16_t)(hl() + 1));
  if (flag_z()) goto lab_p07_L_7B5E;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p07_L_7B4D;
  flag_cmp(a, 0x0D);
  a = c;
  if (flag_c()) return;
  a = 0;
  flag_logic(a);
  mem_write8(0x8446, a);
  return;
  lab_p07_L_7B5E: ;
  a = mem_read8(hl());
  mem_write8(0x8446, a);
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  return;
}

/* flash page 7 cpu 0x7BA1 (offset 0x3BA1) */
void p07_L_7BA1(void) {
  cpu_push_af();
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p07_L_7BB3;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p07_L_7BB3;
  flag_cmp(a, 0x0B);
  if (flag_z()) goto lab_p07_L_7BB3;
  cpu_pop_af();
  return;
  lab_p07_L_7BB3: ;
  cpu_push_hl();
  p00_L_240A();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  b = mem_read8(hl());
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_7BC7;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_3519();
  mem_write8(hl(), a);
  lab_p07_L_7BC7: ;
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 7 cpu 0x7BCA (offset 0x3BCA) */
void p07_L_7BCA(void) {
  set_hl(0x8499);
  set_de(0x85D0);
  p00_L_1183();
  return;
}

/* flash page 7 cpu 0x7BD3 (offset 0x3BD3) */
void p07_L_7BD3(void) {
  p00_L_1037();
  flag_cmp(a, 0x06);
  if (flag_z()) { p07_L_7C00(); return; }
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 1)));
  p00_L_22FC();
  p00_L_17B0();
  if (flag_nz()) goto lab_p07_L_7BEA;
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 1)));
  lab_p07_L_7BEA: ;
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 5)));
  p00_L_182A();
  if (flag_nz()) goto lab_p07_L_7BF7;
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) | (1u << 5)));
  lab_p07_L_7BF7: ;
  set_hl(mem_read16(0x848E));
  mem_write16(0x9D8B, hl());
  p07_L_59B5();
  return;
}

/* flash page 7 cpu 0x7C00 (offset 0x3C00) */
void p07_L_7C00(void) {
  b = 0x42;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x5A);
  if (flag_z()) goto lab_p07_L_7C0B;
  p07_L_7C09();
  return;
  lab_p07_L_7C0B: ;
  a = 0x02;
  p07_L_7C0D();
  return;
}

/* flash page 7 cpu 0x7C09 (offset 0x3C09) */
void p07_L_7C09(void) {
  b = 0x33;
  a = 0x02;
  p07_L_7C0D();
  return;
}

/* flash page 7 cpu 0x7C0D (offset 0x3C0D) */
void p07_L_7C0D(void) {
  p07_L_7C32();
  p00_L_2F91();
  p00_L_1171();
  p07_L_7BCA();
  a = mem_read8(0x844B);
  cpu_push_af();
  a = 0x07;
  mem_write8(0x844B, a);
  p07_L_76D2();
  cpu_pop_af();
  mem_write8(0x844B, a);
  p00_L_113A();
  p00_L_2DC9();
  p00_L_1135();
  return;
}

/* flash page 7 cpu 0x7C32 (offset 0x3C32) */
void p07_L_7C32(void) {
  mem_write8(0x8673, a);
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_z()) { p00_L_2565(); return; }
  flag_cmp(a, 0x0A);
  if (flag_z()) goto lab_p07_L_7C61;
  flag_cmp(a, 0x0B);
  if (flag_z()) goto lab_p07_L_7C61;
  p07_L_7C47();
  return;
  lab_p07_L_7C61: ;
  p00_L_2DCF();
  return;
}

/* flash page 7 cpu 0x7C47 (offset 0x3C47) */
void p07_L_7C47(void) {
  cpu_push_bc();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  p00_L_3D71();
  cpu_pop_af();
  cpu_push_af();
  p00_L_3E8B();
  cpu_pop_af();
  p00_L_2E59();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 5)));
  return;
}

/* flash page 7 cpu 0x7C65 (offset 0x3C65) */
void p07_L_7C65(void) {
  cpu_push_af();
  p00_L_1295();
  a = 0x01;
  set_hl(0x8000);
  set_de(0x8040);
  /* nop */
  os_bcall(0x8075);
  set_hl((uint16_t)(hl() + 1));
  a = 0x01;
  /* nop */
  /* nop */
  os_bcall(0x805A);
  p07_L_7C7B();
  return;
  a = 0x08;
  flag_cmp(a, c);
  if (flag_nc()) goto lab_p07_L_7C85;
  set_bc(0x0008);
  lab_p07_L_7C85: ;
  set_de(0x8479);
  a = 0x01;
  os_bcall(0x8054);
  a = 0x14;
  mem_write8(0x8478, a);
  mem_write8(0x85D9, a);
  p00_L_2DC9();
  cpu_pop_af();
  return;
}

/* flash page 7 cpu 0x7C7B (offset 0x3C7B) */
void p07_L_7C7B(void) {
  e = d;
  a = (uint8_t)(a + b);
  a = 0x08;
  flag_cmp(a, c);
  if (flag_nc()) goto lab_p07_L_7C85;
  set_bc(0x0008);
  lab_p07_L_7C85: ;
  set_de(0x8479);
  a = 0x01;
  os_bcall(0x8054);
  a = 0x14;
  mem_write8(0x8478, a);
  mem_write8(0x85D9, a);
  p00_L_2DC9();
  cpu_pop_af();
  return;
}

/* flash page 7 cpu 0x7C9A (offset 0x3C9A) */
void p07_L_7C9A(void) {
  p07_L_7C32();
  a = mem_read8(0x867F);
  flag_cmp(a, 0x13);
  if (flag_z()) return;
  flag_cmp(a, 0x23);
  if (flag_z()) return;
  p07_L_7BCA();
  a = mem_read8(0x844B);
  cpu_push_af();
  a = 0x07;
  mem_write8(0x844B, a);
  p07_L_76D2();
  cpu_pop_af();
  mem_write8(0x844B, a);
  p00_L_1135();
  return;
}

/* flash page 7 cpu 0x7CBD (offset 0x3CBD) */
void p07_L_7CBD(void) {
  set_de(0x0000);
  set_hl(0xFE66);
  lab_p07_L_7CC3: ;
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  c = 0x09;
  p00_L_1830();
  if (flag_z()) goto lab_p07_L_7CD2;
  p00_L_17B3();
  if (flag_nz()) goto lab_p07_L_7CE6;
  lab_p07_L_7CD2: ;
  cpu_push_hl();
  set_bc(0xFFFA);
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p07_L_7CE0;
  flag_cmp(a, 0x72);
  if (flag_nz()) goto lab_p07_L_7CE2;
  lab_p07_L_7CE0: ;
  a = 0x02;
  lab_p07_L_7CE2: ;
  a = (uint8_t)(a + 0x07);
  c = a;
  cpu_pop_hl();
  lab_p07_L_7CE6: ;
  cpu_push_hl();
  b = 0x00;
  cpu_push_bc();
  set_bc(0xFFFB);
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p07_L_7CF6;
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  lab_p07_L_7CF6: ;
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_de();
  set_de(mem_read16(0x982E));
  p00_L_192A();
  cpu_pop_de();
  if (flag_z()) return;
  if (flag_nc()) goto lab_p07_L_7CC3;
  return;
}

/* flash page 7 cpu 0x7D07 (offset 0x3D07) */
void p07_L_7D07(void) {
  set_bc(0x0578);
  lab_p07_L_7D0A: ;
  cpu_push_bc();
  flag_set_z((mem_read8((uint16_t)(iy + 0x3E)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p07_L_7D1C;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p07_L_7D22;
  cpu_pop_bc();
  goto lab_p07_L_7D35;
  lab_p07_L_7D1C: ;
  a = hw_in(0x09);
  a = a & 0x19;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_7D2C;
  lab_p07_L_7D22: ;
  p00_L_0AC9();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  p00_L_038C();
  lab_p07_L_7D2C: ;
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_7D35;
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p07_L_7D0A;
  lab_p07_L_7D35: ;
  p00_L_3D2F();
  p00_L_3E8B();
  return;
}

/* flash page 7 cpu 0x7F05 (offset 0x3F05) */
void p07_L_7F05(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p07_L_7FBB();
  return;
}

/* flash page 7 cpu 0x7FBB (offset 0x3FBB) */
void p07_L_7FBB(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
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


/* Recovered from flash page 0 (mechanical ASM->C) */
/* cpu window 0x0000..0x3FFF prefix=p00_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p00_rst00_boot(void);
void p00_rst08(void);
void p00_rst10(void);
void p00_L_0013(void);
void p00_rst18(void);
void p00_rst20(void);
void p00_rst28_bcall(void);
void p00_L_002B(void);
void p00_rst30(void);
void p00_L_0033(void);
void p00_rst38_isr(void);
void p00_L_0053(void);
void p00_str_1(void);
void p00_L_0087(void);
void p00_L_0155(void);
void p00_L_0156(void);
void p00_L_0157(void);
void p00_L_0161(void);
void p00_L_0189(void);
void p00_L_018E(void);
void p00_L_0198(void);
void p00_L_01A2(void);
void p00_L_01BF(void);
void p00_L_0247(void);
void p00_L_0254(void);
void p00_L_0265(void);
void p00_L_02A8(void);
void p00_L_02AD(void);
void p00_L_02B3(void);
void p00_L_0305(void);
void p00_L_0345(void);
void p00_L_0356(void);
void p00_key_scan(void);
void p00_L_036F(void);
void p00_L_037F(void);
void p00_L_038C(void);
void p00_L_03A0(void);
void p00_L_0443(void);
void p00_L_0444(void);
void p00_L_045A(void);
void p00_L_0463(void);
void p00_mmu_set_bankA_4(void);
void p00_mmu_set_bankA(void);
void p00_L_0633(void);
void p00_L_0643(void);
void p00_L_0646(void);
void p00_L_0647(void);
void p00_L_0652(void);
void p00_L_065B(void);
void p00_L_066A(void);
void p00_L_071D(void);
void p00_L_073A(void);
void p00_L_073D(void);
void p00_L_0745(void);
void p00_L_0753(void);
void p00_L_0767(void);
void p00_L_0777(void);
void p00_L_077F(void);
void p00_L_0790(void);
void p00_L_07A1(void);
void p00_L_07DE(void);
void p00_L_07E6(void);
void p00_L_0A3A(void);
void p00_L_0A59(void);
void p00_L_0A6C(void);
void p00_lcd_busy_wait(void);
void p00_lcd_write_cmd(void);
void p00_L_0AC4(void);
void p00_L_0AC9(void);
void p00_L_0ACB(void);
void p00_L_0ADA(void);
void p00_L_0AEF(void);
void p00_L_0AF8(void);
void p00_L_0B2A(void);
void p00_L_0B76(void);
void p00_L_0B86(void);
void p00_L_0B8D(void);
void p00_L_0B93(void);
void p00_L_0BA2(void);
void p00_L_0BB1(void);
void p00_L_0BD1(void);
void p00_L_0C0F(void);
void p00_L_0C1B(void);
void p00_L_0CDF(void);
void p00_L_0CF2(void);
void p00_L_0CF6(void);
void p00_L_0D1E(void);
void p00_L_0E4C(void);
void p00_L_0E5C(void);
void p00_L_0E72(void);
void p00_L_0E96(void);
void p00_L_0E9E(void);
void p00_L_0FB5(void);
void p00_L_1025(void);
void p00_L_1037(void);
void p00_L_104E(void);
void p00_L_10D4(void);
void p00_L_10DD(void);
void p00_L_10E6(void);
void p00_L_10F8(void);
void p00_L_1100(void);
void p00_L_1103(void);
void p00_L_1110(void);
void p00_L_1135(void);
void p00_L_113F(void);
void p00_L_1179(void);
void p00_L_1183(void);
void p00_L_1185(void);
void p00_L_11CB(void);
void p00_L_11F8(void);
void p00_L_11FD(void);
void p00_L_1229(void);
void p00_L_1251(void);
void p00_L_1254(void);
void p00_L_1287(void);
void p00_L_128A(void);
void p00_L_1295(void);
void p00_L_129A(void);
void p00_L_129F(void);
void p00_L_12AA(void);
void p00_L_12B1(void);
void p00_L_12B9(void);
void p00_L_12D0(void);
void p00_L_12D4(void);
void p00_L_12EF(void);
void p00_L_12F5(void);
void p00_L_1301(void);
void p00_L_1373(void);
void p00_L_1397(void);
void p00_L_139F(void);
void p00_L_13BB(void);
void p00_L_1415(void);
void p00_L_141D(void);
void p00_L_1430(void);
void p00_L_14B0(void);
void p00_L_14B8(void);
void p00_L_14C7(void);
void p00_L_14CC(void);
void p00_L_14DB(void);
void p00_L_14E1(void);
void p00_L_1525(void);
void p00_L_1531(void);
void p00_L_159F(void);
void p00_L_15CB(void);
void p00_L_15D1(void);
void p00_L_15D6(void);
void p00_L_15E0(void);
void p00_L_15EB(void);
void p00_L_15F3(void);
void p00_L_15FB(void);
void p00_L_1641(void);
void p00_L_1647(void);
void p00_L_1653(void);
void p00_L_1664(void);
void p00_L_1671(void);
void p00_L_1680(void);
void p00_L_16C4(void);
void p00_L_16F4(void);
void p00_L_1700(void);
void p00_L_172F(void);
void p00_ascii_map(void);
void p00_L_17B0(void);
void p00_L_17B3(void);
void p00_L_17BB(void);
void p00_L_17CE(void);
void p00_L_17DB(void);
void p00_lcd_cmd_07(void);
void p00_lcd_cmd_05(void);
void p00_L_182A(void);
void p00_L_1830(void);
void p00_L_1873(void);
void p00_L_18C3(void);
void p00_mmu_set_bankA_3(void);
void p00_L_1923(void);
void p00_L_192A(void);
void p00_L_19A4(void);
void p00_L_19B0(void);
void p00_L_19C5(void);
void p00_L_19E7(void);
void p00_L_19ED(void);
void p00_L_19F6(void);
void p00_L_19F8(void);
void p00_L_1A99(void);
void p00_L_1B0E(void);
void p00_L_1B18(void);
void p00_L_1B33(void);
void p00_L_1B7E(void);
void p00_L_1B90(void);
void p00_L_1B9D(void);
void p00_L_1BA3(void);
void p00_L_1C46(void);
void p00_L_1C91(void);
void p00_L_1D37(void);
void p00_L_1D58(void);
void p00_L_1EDE(void);
void p00_L_1EF4(void);
void p00_L_1F06(void);
void p00_L_1F38(void);
void p00_L_1F55(void);
void p00_L_1F58(void);
void p00_L_1FA3(void);
void p00_L_1FB8(void);
void p00_L_1FE8(void);
void p00_L_1FF3(void);
void p00_L_2040(void);
void p00_L_2062(void);
void p00_L_207C(void);
void p00_L_210A(void);
void p00_L_2187(void);
void p00_L_2191(void);
void p00_L_219B(void);
void p00_L_21A4(void);
void p00_L_21A7(void);
void p00_L_231F(void);
void p00_L_23BD(void);
void p00_L_23C4(void);
void p00_L_2407(void);
void p00_L_2420(void);
void p00_L_2429(void);
void p00_mmu_set_bankA_2(void);
void p00_L_24A9(void);
void p00_L_25A2(void);
void p00_L_25C8(void);
void p00_L_25D8(void);
void p00_L_25E7(void);
void p00_L_28B0(void);
void p00_L_2B07(void);
void p00_L_2B3C(void);
void p00_L_3E0D(void);
void p00_L_3E13(void);
void p00_L_3E19(void);
void p00_L_3E1F(void);
void p00_L_3E25(void);
void p00_L_3E31(void);
void p00_L_3E37(void);
void p00_L_3E3D(void);
void p00_L_3E43(void);
void p00_L_3E49(void);
void p00_L_3E4F(void);
void p00_L_3E55(void);
void p00_L_3E5B(void);
void p00_L_3E61(void);
void p00_L_3E67(void);
void p00_L_3E6D(void);
void p00_L_3E73(void);
void p00_L_3E79(void);
void p00_L_3E7F(void);
void p00_L_3E85(void);
void p00_L_3E8B(void);
void p00_L_3E91(void);
void p00_L_3E97(void);
void p00_L_3E9D(void);
void p00_L_3EA3(void);
void p00_L_3EA9(void);
void p00_L_3EAF(void);
void p00_L_3EB5(void);
void p00_L_3EBB(void);
void p00_L_3EC1(void);
void p00_L_3ED3(void);
void p00_L_3ED9(void);
void p00_L_3EE5(void);
void p00_L_3EEB(void);
void p00_L_3EF1(void);
void p00_L_3EF7(void);
void p00_L_3EFD(void);
void p00_L_3F03(void);
void p00_L_3F09(void);
void p00_L_3F0E(void);
void p00_L_3F0F(void);
void p00_L_3F15(void);
void p00_L_3F1B(void);
void p00_L_3F21(void);
void p00_L_3F27(void);
void p00_L_3F2D(void);
void p00_L_3F33(void);
void p00_L_3F39(void);
void p00_L_3F3F(void);
void p00_L_3F45(void);
void p00_L_3F4B(void);
void p00_L_3F51(void);
void p00_L_3F57(void);
void p00_L_3F5D(void);
void p00_L_3F63(void);
void p00_L_3F69(void);
void p00_L_3F75(void);
void p00_L_3F7B(void);
void p00_L_3F81(void);
void p00_L_3F87(void);
void p00_L_3F8D(void);
void p00_L_3F93(void);
void p00_L_3F99(void);
void p00_L_3F9F(void);
void p00_L_3FA5(void);

/* flash page 0 cpu 0x0000 (offset 0x0000) */
void p00_rst00_boot(void) {
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  goto lab_p00_L_01D0;
  lab_p00_L_01D0: ;
  a = 0x1F;
  if (flag_z()) goto lab_p00_L_01DA;
  a = 0x03;
  hw_out(0x0E, a);
  a = 0x7F;
  lab_p00_L_01DA: ;
  mmu_set_bank_a(a);
  a = 0x77;
  hw_out(PORT_INTACK, a);
  os_banked_call(0x80D5);
  return;
}

/* flash page 0 cpu 0x0008 (offset 0x0008) */
void p00_rst08(void) {
  goto lab_p00_L_1120;
  lab_p00_L_1120: ;
  set_hl(0x8478);
  set_de(0x8483);
  goto lab_p00_L_117F;
  lab_p00_L_117F: ;
  cpu_ldi();
  cpu_ldi();
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x0010 (offset 0x0010) */
void p00_rst10(void) {
  goto lab_p00_L_19F2;
  lab_p00_L_19F2: ;
  p00_L_3E19();
  return;
}

/* flash page 0 cpu 0x0013 (offset 0x0013) */
void p00_L_0013(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 4)) == 0);
  return;
}

/* flash page 0 cpu 0x0018 (offset 0x0018) */
void p00_rst18(void) {
  goto lab_p00_L_21E5;
  lab_p00_L_21E5: ;
  set_hl(0x8478);
  cpu_push_hl();
  set_hl(0x0009);
  p00_L_23BD();
  cpu_pop_hl();
  set_de(mem_read16(0x9824));
  p00_L_1183();
  mem_write16(0x9824, de());
  return;
}

/* flash page 0 cpu 0x0020 (offset 0x0020) */
void p00_rst20(void) {
  goto lab_p00_L_11F2;
  lab_p00_L_11F2: ;
  set_de(0x8478);
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x0028 (offset 0x0028) */
void p00_rst28_bcall(void) {
  goto lab_p00_L_2A37;
  lab_p00_L_2A37: ;
  cpu_push_hl();
  cpu_push_hl();
  cpu_push_hl();
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  set_hl(0x000F);
  set_hl((uint16_t)(hl() + sp));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), d);
  a = hw_in(PORT_MMU_A);
  c = a;
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), 0x2B);
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), 0x34);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  h = a;
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  l = a;
  b = 0x00;
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p00_L_2A6D;
  flag_set_z((h & (1u << 6)) == 0);
  if (flag_z()) goto lab_p00_L_2A73;
  h = (uint8_t)(h & ~(1u << 6));
  a = 0x7B;
  goto lab_p00_L_2A88;
  lab_p00_L_2A6D: ;
  h = (uint8_t)(h & ~(1u << 7));
  a = 0x7F;
  goto lab_p00_L_2A88;
  lab_p00_L_2A73: ;
  set_de(0x8230);
  a = hw_in(PORT_MMU_A);
  a = a & 0x7F;
  flag_logic(a);
  flag_cmp(a, 0x20);
  if (flag_c()) goto lab_p00_L_2A81;
  set_de(0x9C06);
  lab_p00_L_2A81: ;
  a = (uint8_t)(a + e);
  e = a;
  if (flag_nc()) goto lab_p00_L_2A86;
  d = (uint8_t)(d + 1);
  lab_p00_L_2A86: ;
  a = mem_read8(de());
  b = a;
  lab_p00_L_2A88: ;
  p00_mmu_set_bankA_2();
  set_de(0x4000);
  set_hl((uint16_t)(hl() + de()));
  e = l;
  d = h;
  set_hl(0x0008);
  set_hl((uint16_t)(hl() + sp));
  a = mem_read8(de());
  mem_write8(hl(), a);
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(de());
  mem_write8(hl(), a);
  set_de((uint16_t)(de() + 1));
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_2AA6;
  a = mem_read8(de());
  /* neg */
  a = (uint8_t)(a + b);
  goto lab_p00_L_2AAB;
  lab_p00_L_2AA6: ;
  a = mem_read8(de());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_2AAB;
  a = c;
  lab_p00_L_2AAB: ;
  p00_mmu_set_bankA_2();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 0 cpu 0x002B (offset 0x002B) */
void p00_L_002B(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x9653, a);
  return;
}

/* flash page 0 cpu 0x0030 (offset 0x0030) */
void p00_rst30(void) {
  goto lab_p00_L_0C34;
  lab_p00_L_0C34: ;
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 6)));
  p00_L_0FB5();
  goto lab_p00_L_0C41;
  lab_p00_L_0C41: ;
  p00_L_14CC();
  if (flag_z()) return;
  p00_L_14C7();
  if (flag_z()) { p00_L_1179(); return; }
  p00_L_1700();
  if (flag_nc()) goto lab_p00_L_0C8E;
  /* add a,(hl) */
  d = mem_read8(hl());
  e = a;
  a = d;
  mem_write8(0x8479, a);
  a = (uint8_t)(a - e);
  flag_cmp(a, 0x10);
  if (flag_nc()) { p00_L_1179(); return; }
  b = a;
  lab_p00_L_0C5E: ;
  set_hl(0x847A);
  p00_L_12D0();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0C5E;
  a = mem_read8(0x8483);
  a = a & 0x80;
  flag_logic(a);
  c = a;
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  a = a ^ c;
  flag_logic(a);
  a = c;
  mem_write8(0x8478, a);
  if (flag_z()) goto lab_p00_L_0CAD;
  p00_L_1415();
  if (flag_nc()) goto lab_p00_L_0CCF;
  p00_L_1397();
  p00_L_141D();
  a = mem_read8(0x8478);
  a = a ^ 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  goto lab_p00_L_0CD2;
  lab_p00_L_0C8E: ;
  if (flag_z()) goto lab_p00_L_0C9C;
  flag_cmp(a, 0x10);
  if (flag_nc()) return;
  b = a;
  lab_p00_L_0C94: ;
  set_hl(0x8485);
  p00_L_12D0();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0C94;
  lab_p00_L_0C9C: ;
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  c = a;
  a = mem_read8(0x8483);
  a = a & 0x80;
  flag_logic(a);
  a = a ^ c;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_0CC4;
  lab_p00_L_0CAD: ;
  p00_L_139F();
  if (flag_nc()) goto lab_p00_L_0CB8;
  p00_L_12F5();
  p00_L_15F3();
  lab_p00_L_0CB8: ;
  p00_L_0CDF();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p00_L_0D06;
  goto lab_p00_L_0F98;
  lab_p00_L_0CC4: ;
  p00_L_141D();
  if (flag_nc()) goto lab_p00_L_0CD2;
  p00_L_139F();
  p00_L_1415();
  lab_p00_L_0CCF: ;
  p00_L_1179();
  lab_p00_L_0CD2: ;
  p00_L_0CDF();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p00_L_0E07;
  goto lab_p00_L_0F98;
  lab_p00_L_0D06: ;
  goto lab_p00_L_0E2D;
  lab_p00_L_0E07: ;
  set_hl(0x847A);
  a = mem_read8(hl());
  a = a & 0xF0;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_0E2D;
  c = 0x10;
  lab_p00_L_0E11: ;
  c = (uint8_t)(c - 1);
  if (flag_z()) { p00_L_128A(); return; }
  p00_L_1301();
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a & 0xF0;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0E11;
  a = 0x10;
  a = (uint8_t)(a - c);
  c = a;
  a = mem_read8(0x8479);
  a = (uint8_t)(a - c);
  if (flag_c()) { p00_L_128A(); return; }
  mem_write8(0x8479, a);
  lab_p00_L_0E2D: ;
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  set_hl(0x8481);
  a = mem_read8(hl());
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() - 1));
  a = (uint8_t)(a + 0xB0);
  if (flag_nc()) return;
  p00_L_1373();
  if (flag_nc()) return;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x10);
  p00_L_15F3();
  return;
  lab_p00_L_0F98: ;
  c = 0x11;
  lab_p00_L_0F9A: ;
  a = mem_read8(0x847A);
  a = a & 0xF0;
  flag_logic(a);
  if (flag_nz()) return;
  c = (uint8_t)(c - 1);
  if (flag_z()) goto lab_p00_L_0FAC;
  p00_L_1301();
  p00_L_15EB();
  if (flag_nc()) goto lab_p00_L_0F9A;
  return;
  lab_p00_L_0FAC: ;
  p00_L_128A();
  return;
}

/* flash page 0 cpu 0x0033 (offset 0x0033) */
void p00_L_0033(void) {
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  h = mem_read8(hl());
  l = a;
  return;
}

/* flash page 0 cpu 0x0038 (offset 0x0038) */
void p00_rst38_isr(void) {
  goto lab_p00_L_006A;
  lab_p00_L_003A: ;
  a = hw_in(PORT_INTACK);
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p00_L_0135;
  flag_set_z((a & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p00_L_0124;
  cpu_rra();
  if (flag_c()) goto lab_p00_L_00A0;
  cpu_rra();
  if (flag_c()) goto lab_p00_L_00AB;
  goto lab_p00_L_0076;
  lab_p00_L_006A: ;
  cpu_ex_af();
  cpu_exx();
  goto lab_p00_L_003A;
  lab_p00_L_006E: ;
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  lab_p00_L_0076: ;
  a = 0x0B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_0080;
  lab_p00_L_007E: ;
  a = (uint8_t)(a + 0x04);
  lab_p00_L_0080: ;
  hw_out(PORT_INTMASK, a);
  cpu_ex_af();
  cpu_exx();
  /* ei */
  return;
  lab_p00_L_00A0: ;
  p00_L_07E6();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 1)));
  a = 0x0A;
  goto lab_p00_L_006E;
  lab_p00_L_00AB: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_00C4;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_3F8D();
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) | (1u << 7)));
  lab_p00_L_00C4: ;
  a = mem_read8(0x9C86);
  a = (uint8_t)(a - 1);
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p00_L_00CF;
  mem_write8(0x9C86, a);
  lab_p00_L_00CF: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_01BF();
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p00_L_011F;
  p00_L_02B3();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 2)) == 0);
  if (flag_nz()) p00_L_3F93();
  p00_L_0254();
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p00_L_011F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p00_L_011F;
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_0105;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_nz()) p00_L_3F99();
  goto lab_p00_L_011F;
  lab_p00_L_0105: ;
  a = hw_in(0x09);
  a = a & 0x18;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_011F;
  a = 0xFA;
  mem_write8(0x9C86, a);
  a = 0x80;
  hw_out(0x08, a);
  a = 0x00;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) | (1u << 0)));
  p00_L_3F99();
  lab_p00_L_011F: ;
  a = 0x09;
  goto lab_p00_L_006E;
  lab_p00_L_0124: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 3)));
  cpu_push_hl();
  a = 0;
  flag_logic(a);
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  goto lab_p00_L_083D;
  lab_p00_L_0135: ;
  a = 0x04;
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_006E;
  a = mem_read8((uint16_t)(iy + 0x16));
  a = a ^ 0x02;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x16), a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p00_L_0170;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 2)));
  a = hw_in(PORT_STATUS);
  flag_set_z((a & (1u << 0)) == 0);
  p00_L_0155();
  return;
  lab_p00_L_0170: ;
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) | (1u << 2)));
  a = 0x76;
  hw_out(PORT_INTACK, a);
  a = 0x76;
  hw_out(PORT_INTACK, a);
  a = 0x09;
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  goto lab_p00_L_007E;
  lab_p00_L_03C5: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p00_L_3EFD();
  p00_L_3F03();
  lab_p00_L_03CF: ;
  p00_L_3F09();
  p00_L_3F0F();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 7)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x1F)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0408;
  /* di */
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 5)));
  set_hl(0x0403);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  a = mem_read8(0x859A);
  flag_cmp(a, 0x52);
  if (flag_nz()) goto lab_p00_L_03FD;
  a = mem_read8(0x86DD);
  p00_L_3F15();
  goto lab_p00_L_0400;
  lab_p00_L_03FD: ;
  p00_L_3F1B();
  lab_p00_L_0400: ;
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  /* ei */
  lab_p00_L_0408: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8444, a);
  mem_write8(0x8446, a);
  p00_L_3F21();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 1)));
  mem_write8(0x8444, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_0433;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 3)) == 0);
  if (flag_z()) p00_L_3F27();
  a = mem_read8(0x8444);
  goto lab_p00_L_0436;
  lab_p00_L_0433: ;
  p00_L_3EFD();
  lab_p00_L_0436: ;
  p00_L_3F2D();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_044D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_0448;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  goto lab_p00_L_04B2;
  lab_p00_L_0448: ;
  a = 0x05;
  goto lab_p00_L_0515;
  lab_p00_L_044D: ;
  flag_cmp(a, 0xB4);
  if (flag_nz()) goto lab_p00_L_0470;
  a = 0xCC;
  p00_L_0198();
  if (flag_nz()) goto lab_p00_L_046D;
  a = 0xAD;
  p00_L_045A();
  return;
  lab_p00_L_046D: ;
  mem_write8(0x8444, a);
  lab_p00_L_0470: ;
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  p00_L_3F33();
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p00_L_04B2;
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  cpu_push_af();
  goto lab_p00_L_053E;
  lab_p00_L_0491: ;
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p00_L_04A2;
  p00_L_3F39();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_3F3F();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_07DE();
  lab_p00_L_04A2: ;
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x29);
  if (flag_z()) goto lab_p00_L_0515;
  goto lab_p00_L_04D0;
  lab_p00_L_04AE: ;
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_04BA;
  lab_p00_L_04B2: ;
  goto lab_p00_L_03C5;
  lab_p00_L_04B5: ;
  b = 0x08;
  set_hl(0x84BE);
  lab_p00_L_04BA: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04B2;
  cpu_push_bc();
  cpu_push_hl();
  d = 0x00;
  e = a;
  p00_L_3F45();
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  goto lab_p00_L_04AE;
  lab_p00_L_04D0: ;
  flag_cmp(a, 0x7F);
  if (flag_c()) goto lab_p00_L_0595;
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFB);
  if (flag_nz()) goto lab_p00_L_04FA;
  a = mem_read8(0x8446);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04F7;
  flag_cmp(a, 0x0D);
  if (flag_c()) goto lab_p00_L_04F3;
  flag_cmp(a, 0x8C);
  if (flag_c()) goto lab_p00_L_0549;
  flag_cmp(a, 0xA6);
  if (flag_nc()) goto lab_p00_L_0549;
  lab_p00_L_04F3: ;
  a = 0xFB;
  goto lab_p00_L_0515;
  lab_p00_L_04F7: ;
  a = mem_read8(0x8444);
  lab_p00_L_04FA: ;
  flag_cmp(a, 0xEF);
  if (flag_nz()) goto lab_p00_L_0502;
  a = 0xA6;
  goto lab_p00_L_0510;
  lab_p00_L_0502: ;
  flag_cmp(a, 0xF9);
  if (flag_c()) goto lab_p00_L_050A;
  a = (uint8_t)(a - 0x14);
  goto lab_p00_L_0510;
  lab_p00_L_050A: ;
  flag_cmp(a, 0xF3);
  if (flag_c()) goto lab_p00_L_0515;
  a = (uint8_t)(a - 0x7C);
  lab_p00_L_0510: ;
  mem_write8(0x8446, a);
  a = 0xFE;
  lab_p00_L_0515: ;
  flag_cmp(a, 0x69);
  if (flag_nz()) goto lab_p00_L_051D;
  a = 0xFC;
  goto lab_p00_L_0510;
  lab_p00_L_051D: ;
  flag_cmp(a, 0x5B);
  if (flag_nz()) goto lab_p00_L_0525;
  a = 0xFD;
  goto lab_p00_L_0510;
  lab_p00_L_0525: ;
  flag_cmp(a, 0x28);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_0532;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 7)));
  a = 0xDA;
  goto lab_p00_L_053E;
  lab_p00_L_0532: ;
  cpu_pop_af();
  flag_cmp(a, 0x29);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_053E;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 1)));
  a = 0x7F;
  lab_p00_L_053E: ;
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  cpu_pop_af();
  if (flag_z()) goto lab_p00_L_04B5;
  lab_p00_L_0549: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p00_L_058E;
  set_de(mem_read16(0x86D9));
  set_hl(mem_read16(0x96F6));
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0560;
  set_hl(mem_read16(0x86DB));
  cpu_ex_de_hl();
  lab_p00_L_0560: ;
  p00_L_192A();
  if (flag_nc()) goto lab_p00_L_0580;
  a = mem_read8(hl());
  p00_L_172F();
  d = 0x00;
  e = a;
  if (flag_nz()) goto lab_p00_L_0571;
  d = a;
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  lab_p00_L_0571: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_057B;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x86D9, hl());
  lab_p00_L_057B: ;
  p00_L_3F45();
  lab_p00_L_057E: ;
  goto lab_p00_L_0515;
  lab_p00_L_0580: ;
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 7)));
  set_hl(0x89F5);
  a = mem_read8(0x85C2);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 4)));
  /* or (hl) */
  mem_write8(hl(), a);
  lab_p00_L_058E: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 2)));
  goto lab_p00_L_03CF;
  lab_p00_L_0595: ;
  flag_cmp(a, 0x27);
  if (flag_c()) goto lab_p00_L_057E;
  flag_cmp(a, 0x5A);
  if (flag_c()) goto lab_p00_L_05C2;
  flag_cmp(a, 0x75);
  if (flag_nc()) goto lab_p00_L_05BC;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_057E;
  flag_cmp(a, 0x69);
  if (flag_c()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x6D);
  if (flag_z()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x69);
  if (flag_z()) goto lab_p00_L_057E;
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x44);
  a = b;
  if (flag_nz()) goto lab_p00_L_057E;
  lab_p00_L_05BC: ;
  b = a;
  a = 0x44;
  goto lab_p00_L_05D0;
  lab_p00_L_05C2: ;
  b = a;
  flag_cmp(a, 0x59);
  if (flag_nz()) goto lab_p00_L_05D0;
  a = mem_read8(0x8446);
  a = (uint8_t)(a + b);
  flag_cmp(a, 0x5B);
  if (flag_nc()) goto lab_p00_L_05F1;
  b = a;
  lab_p00_L_05D0: ;
  c = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x50);
  if (flag_nz()) goto lab_p00_L_05E1;
  a = b;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p00_L_05F1;
  a = 0x50;
  goto lab_p00_L_05EA;
  lab_p00_L_05E1: ;
  flag_cmp(a, 0x52);
  a = c;
  if (flag_nz()) goto lab_p00_L_05EA;
  flag_cmp(a, 0x40);
  if (flag_nz()) goto lab_p00_L_058E;
  lab_p00_L_05EA: ;
  p00_L_0633();
  a = b;
  goto lab_p00_L_0525;
  lab_p00_L_05F1: ;
  a = 0;
  flag_logic(a);
  b = a;
  sp = mem_read16(0x85BC);
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 6)));
  p00_L_0BB1();
  a = 0x40;
  p00_L_0633();
  a = b;
  flag_cmp(a, 0xDA);
  if (flag_nz()) goto lab_p00_L_060D;
  a = 0x28;
  lab_p00_L_060A: ;
  goto lab_p00_L_0515;
  lab_p00_L_060D: ;
  flag_cmp(a, 0x7F);
  if (flag_nz()) goto lab_p00_L_060A;
  a = 0x29;
  goto lab_p00_L_060A;
  lab_p00_L_083D: ;
  a = 0x76;
  hw_out(PORT_INTACK, a);
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_084D;
  a = hw_in(PORT_MMU_B);
  flag_cmp(a, 0x81);
  goto lab_p00_L_0853;
  lab_p00_L_084D: ;
  a = hw_in(PORT_MMU_B);
  a = a & 0x4F;
  flag_logic(a);
  flag_cmp(a, 0x41);
  lab_p00_L_0853: ;
  if (flag_nz()) goto lab_p00_L_0952;
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p00_L_08E4;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p00_L_0869;
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p00_L_086E;
  lab_p00_L_0869: ;
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) | (1u << 3)));
  return;
  lab_p00_L_086E: ;
  a = 0x08;
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  p00_lcd_write_cmd();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0887;
  flag_set_z((mem_read8((uint16_t)(iy + 0x08)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_08C6;
  lab_p00_L_0887: ;
  p00_L_0BB1();
  p00_L_0B76();
  p00_L_3E79();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) | (1u << 4)));
  set_hl(0x9D8D);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  p00_L_0A59();
  set_hl(0x9D8D);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 4)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3E7F();
  p00_L_3E85();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  p00_lcd_write_cmd();
  set_hl(0x89F9);
  flag_set_z((mem_read8(hl()) & (1u << 2)) == 0);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 2)));
  if (flag_nz()) p00_L_3E8B();
  p00_L_0A3A();
  mem_write16(0x85BE, hl());
  lab_p00_L_08C6: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 5)));
  a = 0x36;
  hw_out(PORT_INTACK, a);
  a = 0x11;
  hw_out(PORT_INTMASK, a);
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 3)));
  cpu_ex_af();
  cpu_exx();
  /* ei */
  lab_p00_L_08E1: ;
  halt();
  goto lab_p00_L_08E1;
  lab_p00_L_08E4: ;
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) & ~(1u << 7)));
  p00_L_02AD();
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p00_L_094D;
  lab_p00_L_08F1: ;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 3)));
  set_hl(0x89F8);
  flag_set_z((mem_read8(hl()) & (1u << 4)) == 0);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 4)));
  if (flag_nz()) goto lab_p00_L_092C;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 1)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_090D;
  flag_set_z((mem_read8(hl()) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_09CA;
  lab_p00_L_090D: ;
  sp = mem_read16(0x85BC);
  p00_L_3E91();
  a = 0;
  flag_logic(a);
  mem_write8(0x85DE, a);
  p00_L_0B2A();
  p00_L_0ADA();
  p00_L_3E97();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_3E9D();
  /* ei */
  goto lab_p00_L_03CF;
  lab_p00_L_092C: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3EA3();
  a = 0x08;
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  p00_L_3EA9();
  cpu_pop_de();
  cpu_pop_de();
  cpu_pop_de();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 3)));
  p00_L_0ADA();
  cpu_ex_af();
  cpu_exx();
  /* ei */
  return;
  lab_p00_L_094D: ;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 4)));
  return;
  lab_p00_L_0952: ;
  a = 0x76;
  hw_out(PORT_INTACK, a);
  a = 0xC0;
  link_out(a); /* stub */
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  a = 0x41;
  if (flag_z()) goto lab_p00_L_096B;
  a = 0x01;
  hw_out(PORT_SE_STATUS, a);
  a = 0;
  flag_logic(a);
  hw_out(0x0F, a);
  a = 0x81;
  lab_p00_L_096B: ;
  mmu_set_bank_b(a);
  a = 0;
  flag_logic(a);
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  iy = 0x89F0;
  p00_L_24A9();
  if (flag_z()) p00_L_3EAF();
  set_hl(mem_read16(0x85BE));
  set_de(0xA55A);
  p00_L_192A();
  if (flag_z()) goto lab_p00_L_0B38;
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_09A0;
  b = 0x00;
  os_bcall(0x80BA);
  flag_set_z((b & (1u << 0)) == 0);
  a = 0x1F;
  if (flag_z()) goto lab_p00_L_09A2;
  a = 0x1C;
  goto lab_p00_L_09A2;
  lab_p00_L_09A0: ;
  a = 0x17;
  lab_p00_L_09A2: ;
  mem_write8(0x8447, a);
  p00_L_0A3A();
  set_de(mem_read16(0x85BE));
  p00_L_192A();
  if (flag_nz()) goto lab_p00_L_09CA;
  set_de((uint16_t)(de() - 1));
  mem_write16(0x85BE, de());
  p00_L_3EB5();
  p00_L_0B76();
  a = 0x0B;
  hw_out(PORT_INTMASK, a);
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 4)));
  p00_L_0A59();
  goto lab_p00_L_08F1;
  lab_p00_L_09CA: ;
  /* di */
  set_hl(0x8000);
  set_de(0x8001);
  set_bc(0x7FFF);
  mem_write8(hl(), 0x00);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  a = 0xC0;
  link_out(a); /* stub */
  sp = 0xFFF7;
  p00_L_3EBB();
  set_hl(0x07AD);
  p00_L_25A2();
  mem_write16(0x85BC, sp);
  p00_L_3EC1();
  goto lab_p00_L_3EC7;
  lab_p00_L_0B38: ;
  set_hl(0x0000);
  mem_write16(0x85BE, hl());
  sp = mem_read16(0x85BC);
  iy = 0x89F0;
  p00_L_3EE5();
  p00_L_0B76();
  p00_L_0A59();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 4)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_3E9D();
  a = 0x0B;
  hw_out(PORT_INTMASK, a);
  p00_L_3EEB();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 3)));
  p00_L_0AF8();
  if (flag_z()) p00_L_0AEF();
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3EA3();
  /* ei */
  goto lab_p00_L_03CF;
  lab_p00_L_3EC7: ;
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x43E7);
  return; /* banked jump */
}

/* flash page 0 cpu 0x0053 (offset 0x0053) */
void p00_L_0053(void) {
  p00_L_0A6C();
  return;
}

/* flash page 0 cpu 0x0064 (offset 0x0064) */
void p00_str_1(void) {
  goto lab_p00_str_1;
  lab_p00_L_003A: ;
  a = hw_in(PORT_INTACK);
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p00_L_0135;
  flag_set_z((a & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p00_L_0124;
  cpu_rra();
  if (flag_c()) goto lab_p00_L_00A0;
  cpu_rra();
  if (flag_c()) goto lab_p00_L_00AB;
  goto lab_p00_L_0076;
  lab_p00_str_1: ;
  sp = 0x312E;
  set_hl((uint16_t)(hl() + sp));
  if (flag_nz()) goto lab_p00_L_006A;
  lab_p00_L_006A: ;
  cpu_ex_af();
  cpu_exx();
  goto lab_p00_L_003A;
  lab_p00_L_006E: ;
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  lab_p00_L_0076: ;
  a = 0x0B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_0080;
  lab_p00_L_007E: ;
  a = (uint8_t)(a + 0x04);
  lab_p00_L_0080: ;
  hw_out(PORT_INTMASK, a);
  cpu_ex_af();
  cpu_exx();
  /* ei */
  return;
  lab_p00_L_00A0: ;
  p00_L_07E6();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 1)));
  a = 0x0A;
  goto lab_p00_L_006E;
  lab_p00_L_00AB: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_00C4;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_3F8D();
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) | (1u << 7)));
  lab_p00_L_00C4: ;
  a = mem_read8(0x9C86);
  a = (uint8_t)(a - 1);
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p00_L_00CF;
  mem_write8(0x9C86, a);
  lab_p00_L_00CF: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_01BF();
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p00_L_011F;
  p00_L_02B3();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 2)) == 0);
  if (flag_nz()) p00_L_3F93();
  p00_L_0254();
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p00_L_011F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p00_L_011F;
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_0105;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_nz()) p00_L_3F99();
  goto lab_p00_L_011F;
  lab_p00_L_0105: ;
  a = hw_in(0x09);
  a = a & 0x18;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_011F;
  a = 0xFA;
  mem_write8(0x9C86, a);
  a = 0x80;
  hw_out(0x08, a);
  a = 0x00;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) | (1u << 0)));
  p00_L_3F99();
  lab_p00_L_011F: ;
  a = 0x09;
  goto lab_p00_L_006E;
  lab_p00_L_0124: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 3)));
  cpu_push_hl();
  a = 0;
  flag_logic(a);
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  goto lab_p00_L_083D;
  lab_p00_L_0135: ;
  a = 0x04;
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_006E;
  a = mem_read8((uint16_t)(iy + 0x16));
  a = a ^ 0x02;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x16), a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p00_L_0170;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 2)));
  a = hw_in(PORT_STATUS);
  flag_set_z((a & (1u << 0)) == 0);
  p00_L_0155();
  return;
  lab_p00_L_0170: ;
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) | (1u << 2)));
  a = 0x76;
  hw_out(PORT_INTACK, a);
  a = 0x76;
  hw_out(PORT_INTACK, a);
  a = 0x09;
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  goto lab_p00_L_007E;
  lab_p00_L_03C5: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p00_L_3EFD();
  p00_L_3F03();
  lab_p00_L_03CF: ;
  p00_L_3F09();
  p00_L_3F0F();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 7)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x1F)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0408;
  /* di */
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 5)));
  set_hl(0x0403);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  a = mem_read8(0x859A);
  flag_cmp(a, 0x52);
  if (flag_nz()) goto lab_p00_L_03FD;
  a = mem_read8(0x86DD);
  p00_L_3F15();
  goto lab_p00_L_0400;
  lab_p00_L_03FD: ;
  p00_L_3F1B();
  lab_p00_L_0400: ;
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  /* ei */
  lab_p00_L_0408: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8444, a);
  mem_write8(0x8446, a);
  p00_L_3F21();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 1)));
  mem_write8(0x8444, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_0433;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 3)) == 0);
  if (flag_z()) p00_L_3F27();
  a = mem_read8(0x8444);
  goto lab_p00_L_0436;
  lab_p00_L_0433: ;
  p00_L_3EFD();
  lab_p00_L_0436: ;
  p00_L_3F2D();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_044D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_0448;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  goto lab_p00_L_04B2;
  lab_p00_L_0448: ;
  a = 0x05;
  goto lab_p00_L_0515;
  lab_p00_L_044D: ;
  flag_cmp(a, 0xB4);
  if (flag_nz()) goto lab_p00_L_0470;
  a = 0xCC;
  p00_L_0198();
  if (flag_nz()) goto lab_p00_L_046D;
  a = 0xAD;
  p00_L_045A();
  return;
  lab_p00_L_046D: ;
  mem_write8(0x8444, a);
  lab_p00_L_0470: ;
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  p00_L_3F33();
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p00_L_04B2;
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  cpu_push_af();
  goto lab_p00_L_053E;
  lab_p00_L_0491: ;
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p00_L_04A2;
  p00_L_3F39();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_3F3F();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_07DE();
  lab_p00_L_04A2: ;
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x29);
  if (flag_z()) goto lab_p00_L_0515;
  goto lab_p00_L_04D0;
  lab_p00_L_04AE: ;
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_04BA;
  lab_p00_L_04B2: ;
  goto lab_p00_L_03C5;
  lab_p00_L_04B5: ;
  b = 0x08;
  set_hl(0x84BE);
  lab_p00_L_04BA: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04B2;
  cpu_push_bc();
  cpu_push_hl();
  d = 0x00;
  e = a;
  p00_L_3F45();
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  goto lab_p00_L_04AE;
  lab_p00_L_04D0: ;
  flag_cmp(a, 0x7F);
  if (flag_c()) goto lab_p00_L_0595;
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFB);
  if (flag_nz()) goto lab_p00_L_04FA;
  a = mem_read8(0x8446);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04F7;
  flag_cmp(a, 0x0D);
  if (flag_c()) goto lab_p00_L_04F3;
  flag_cmp(a, 0x8C);
  if (flag_c()) goto lab_p00_L_0549;
  flag_cmp(a, 0xA6);
  if (flag_nc()) goto lab_p00_L_0549;
  lab_p00_L_04F3: ;
  a = 0xFB;
  goto lab_p00_L_0515;
  lab_p00_L_04F7: ;
  a = mem_read8(0x8444);
  lab_p00_L_04FA: ;
  flag_cmp(a, 0xEF);
  if (flag_nz()) goto lab_p00_L_0502;
  a = 0xA6;
  goto lab_p00_L_0510;
  lab_p00_L_0502: ;
  flag_cmp(a, 0xF9);
  if (flag_c()) goto lab_p00_L_050A;
  a = (uint8_t)(a - 0x14);
  goto lab_p00_L_0510;
  lab_p00_L_050A: ;
  flag_cmp(a, 0xF3);
  if (flag_c()) goto lab_p00_L_0515;
  a = (uint8_t)(a - 0x7C);
  lab_p00_L_0510: ;
  mem_write8(0x8446, a);
  a = 0xFE;
  lab_p00_L_0515: ;
  flag_cmp(a, 0x69);
  if (flag_nz()) goto lab_p00_L_051D;
  a = 0xFC;
  goto lab_p00_L_0510;
  lab_p00_L_051D: ;
  flag_cmp(a, 0x5B);
  if (flag_nz()) goto lab_p00_L_0525;
  a = 0xFD;
  goto lab_p00_L_0510;
  lab_p00_L_0525: ;
  flag_cmp(a, 0x28);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_0532;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 7)));
  a = 0xDA;
  goto lab_p00_L_053E;
  lab_p00_L_0532: ;
  cpu_pop_af();
  flag_cmp(a, 0x29);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_053E;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 1)));
  a = 0x7F;
  lab_p00_L_053E: ;
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  cpu_pop_af();
  if (flag_z()) goto lab_p00_L_04B5;
  lab_p00_L_0549: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p00_L_058E;
  set_de(mem_read16(0x86D9));
  set_hl(mem_read16(0x96F6));
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0560;
  set_hl(mem_read16(0x86DB));
  cpu_ex_de_hl();
  lab_p00_L_0560: ;
  p00_L_192A();
  if (flag_nc()) goto lab_p00_L_0580;
  a = mem_read8(hl());
  p00_L_172F();
  d = 0x00;
  e = a;
  if (flag_nz()) goto lab_p00_L_0571;
  d = a;
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  lab_p00_L_0571: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_057B;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x86D9, hl());
  lab_p00_L_057B: ;
  p00_L_3F45();
  lab_p00_L_057E: ;
  goto lab_p00_L_0515;
  lab_p00_L_0580: ;
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 7)));
  set_hl(0x89F5);
  a = mem_read8(0x85C2);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 4)));
  /* or (hl) */
  mem_write8(hl(), a);
  lab_p00_L_058E: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 2)));
  goto lab_p00_L_03CF;
  lab_p00_L_0595: ;
  flag_cmp(a, 0x27);
  if (flag_c()) goto lab_p00_L_057E;
  flag_cmp(a, 0x5A);
  if (flag_c()) goto lab_p00_L_05C2;
  flag_cmp(a, 0x75);
  if (flag_nc()) goto lab_p00_L_05BC;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_057E;
  flag_cmp(a, 0x69);
  if (flag_c()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x6D);
  if (flag_z()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x69);
  if (flag_z()) goto lab_p00_L_057E;
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x44);
  a = b;
  if (flag_nz()) goto lab_p00_L_057E;
  lab_p00_L_05BC: ;
  b = a;
  a = 0x44;
  goto lab_p00_L_05D0;
  lab_p00_L_05C2: ;
  b = a;
  flag_cmp(a, 0x59);
  if (flag_nz()) goto lab_p00_L_05D0;
  a = mem_read8(0x8446);
  a = (uint8_t)(a + b);
  flag_cmp(a, 0x5B);
  if (flag_nc()) goto lab_p00_L_05F1;
  b = a;
  lab_p00_L_05D0: ;
  c = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x50);
  if (flag_nz()) goto lab_p00_L_05E1;
  a = b;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p00_L_05F1;
  a = 0x50;
  goto lab_p00_L_05EA;
  lab_p00_L_05E1: ;
  flag_cmp(a, 0x52);
  a = c;
  if (flag_nz()) goto lab_p00_L_05EA;
  flag_cmp(a, 0x40);
  if (flag_nz()) goto lab_p00_L_058E;
  lab_p00_L_05EA: ;
  p00_L_0633();
  a = b;
  goto lab_p00_L_0525;
  lab_p00_L_05F1: ;
  a = 0;
  flag_logic(a);
  b = a;
  sp = mem_read16(0x85BC);
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 6)));
  p00_L_0BB1();
  a = 0x40;
  p00_L_0633();
  a = b;
  flag_cmp(a, 0xDA);
  if (flag_nz()) goto lab_p00_L_060D;
  a = 0x28;
  lab_p00_L_060A: ;
  goto lab_p00_L_0515;
  lab_p00_L_060D: ;
  flag_cmp(a, 0x7F);
  if (flag_nz()) goto lab_p00_L_060A;
  a = 0x29;
  goto lab_p00_L_060A;
  lab_p00_L_083D: ;
  a = 0x76;
  hw_out(PORT_INTACK, a);
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_084D;
  a = hw_in(PORT_MMU_B);
  flag_cmp(a, 0x81);
  goto lab_p00_L_0853;
  lab_p00_L_084D: ;
  a = hw_in(PORT_MMU_B);
  a = a & 0x4F;
  flag_logic(a);
  flag_cmp(a, 0x41);
  lab_p00_L_0853: ;
  if (flag_nz()) goto lab_p00_L_0952;
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p00_L_08E4;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p00_L_0869;
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p00_L_086E;
  lab_p00_L_0869: ;
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) | (1u << 3)));
  return;
  lab_p00_L_086E: ;
  a = 0x08;
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  p00_lcd_write_cmd();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0887;
  flag_set_z((mem_read8((uint16_t)(iy + 0x08)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_08C6;
  lab_p00_L_0887: ;
  p00_L_0BB1();
  p00_L_0B76();
  p00_L_3E79();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) | (1u << 4)));
  set_hl(0x9D8D);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  p00_L_0A59();
  set_hl(0x9D8D);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 4)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3E7F();
  p00_L_3E85();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  p00_lcd_write_cmd();
  set_hl(0x89F9);
  flag_set_z((mem_read8(hl()) & (1u << 2)) == 0);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 2)));
  if (flag_nz()) p00_L_3E8B();
  p00_L_0A3A();
  mem_write16(0x85BE, hl());
  lab_p00_L_08C6: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 5)));
  a = 0x36;
  hw_out(PORT_INTACK, a);
  a = 0x11;
  hw_out(PORT_INTMASK, a);
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 3)));
  cpu_ex_af();
  cpu_exx();
  /* ei */
  lab_p00_L_08E1: ;
  halt();
  goto lab_p00_L_08E1;
  lab_p00_L_08E4: ;
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) & ~(1u << 7)));
  p00_L_02AD();
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p00_L_094D;
  lab_p00_L_08F1: ;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 3)));
  set_hl(0x89F8);
  flag_set_z((mem_read8(hl()) & (1u << 4)) == 0);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 4)));
  if (flag_nz()) goto lab_p00_L_092C;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 1)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_090D;
  flag_set_z((mem_read8(hl()) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_09CA;
  lab_p00_L_090D: ;
  sp = mem_read16(0x85BC);
  p00_L_3E91();
  a = 0;
  flag_logic(a);
  mem_write8(0x85DE, a);
  p00_L_0B2A();
  p00_L_0ADA();
  p00_L_3E97();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_3E9D();
  /* ei */
  goto lab_p00_L_03CF;
  lab_p00_L_092C: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3EA3();
  a = 0x08;
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  p00_L_3EA9();
  cpu_pop_de();
  cpu_pop_de();
  cpu_pop_de();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 3)));
  p00_L_0ADA();
  cpu_ex_af();
  cpu_exx();
  /* ei */
  return;
  lab_p00_L_094D: ;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 4)));
  return;
  lab_p00_L_0952: ;
  a = 0x76;
  hw_out(PORT_INTACK, a);
  a = 0xC0;
  link_out(a); /* stub */
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  a = 0x41;
  if (flag_z()) goto lab_p00_L_096B;
  a = 0x01;
  hw_out(PORT_SE_STATUS, a);
  a = 0;
  flag_logic(a);
  hw_out(0x0F, a);
  a = 0x81;
  lab_p00_L_096B: ;
  mmu_set_bank_b(a);
  a = 0;
  flag_logic(a);
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  iy = 0x89F0;
  p00_L_24A9();
  if (flag_z()) p00_L_3EAF();
  set_hl(mem_read16(0x85BE));
  set_de(0xA55A);
  p00_L_192A();
  if (flag_z()) goto lab_p00_L_0B38;
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_09A0;
  b = 0x00;
  os_bcall(0x80BA);
  flag_set_z((b & (1u << 0)) == 0);
  a = 0x1F;
  if (flag_z()) goto lab_p00_L_09A2;
  a = 0x1C;
  goto lab_p00_L_09A2;
  lab_p00_L_09A0: ;
  a = 0x17;
  lab_p00_L_09A2: ;
  mem_write8(0x8447, a);
  p00_L_0A3A();
  set_de(mem_read16(0x85BE));
  p00_L_192A();
  if (flag_nz()) goto lab_p00_L_09CA;
  set_de((uint16_t)(de() - 1));
  mem_write16(0x85BE, de());
  p00_L_3EB5();
  p00_L_0B76();
  a = 0x0B;
  hw_out(PORT_INTMASK, a);
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 4)));
  p00_L_0A59();
  goto lab_p00_L_08F1;
  lab_p00_L_09CA: ;
  /* di */
  set_hl(0x8000);
  set_de(0x8001);
  set_bc(0x7FFF);
  mem_write8(hl(), 0x00);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  a = 0xC0;
  link_out(a); /* stub */
  sp = 0xFFF7;
  p00_L_3EBB();
  set_hl(0x07AD);
  p00_L_25A2();
  mem_write16(0x85BC, sp);
  p00_L_3EC1();
  goto lab_p00_L_3EC7;
  lab_p00_L_0B38: ;
  set_hl(0x0000);
  mem_write16(0x85BE, hl());
  sp = mem_read16(0x85BC);
  iy = 0x89F0;
  p00_L_3EE5();
  p00_L_0B76();
  p00_L_0A59();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 4)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_3E9D();
  a = 0x0B;
  hw_out(PORT_INTMASK, a);
  p00_L_3EEB();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 3)));
  p00_L_0AF8();
  if (flag_z()) p00_L_0AEF();
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3EA3();
  /* ei */
  goto lab_p00_L_03CF;
  lab_p00_L_3EC7: ;
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x43E7);
  return; /* banked jump */
}

/* flash page 0 cpu 0x0087 (offset 0x0087) */
void p00_L_0087(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p00_L_009B;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 1)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p00_L_009B;
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) | (1u << 6)));
  lab_p00_L_009B: ;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 0)));
  return;
}

/* flash page 0 cpu 0x0155 (offset 0x0155) */
void p00_L_0155(void) {
  goto lab_p00_L_0155;
  lab_p00_L_006E: ;
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  a = 0x0B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_0080;
  a = (uint8_t)(a + 0x04);
  lab_p00_L_0080: ;
  hw_out(PORT_INTMASK, a);
  cpu_ex_af();
  cpu_exx();
  /* ei */
  return;
  lab_p00_L_0155: ;
  if (flag_nz()) goto lab_p00_L_015B;
  p00_L_0157();
  return;
  lab_p00_L_015B: ;
  a = 0x76;
  hw_out(PORT_INTACK, a);
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) | (1u << 7)));
  a = 0x09;
  goto lab_p00_L_006E;
}

/* flash page 0 cpu 0x0156 (offset 0x0156) */
void p00_L_0156(void) {
  b = (uint8_t)(b + 1);
  p00_L_0157();
  return;
}

/* flash page 0 cpu 0x0157 (offset 0x0157) */
void p00_L_0157(void) {
  goto lab_p00_L_0157;
  lab_p00_L_006E: ;
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  a = 0x0B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_0080;
  a = (uint8_t)(a + 0x04);
  lab_p00_L_0080: ;
  hw_out(PORT_INTMASK, a);
  cpu_ex_af();
  cpu_exx();
  /* ei */
  return;
  lab_p00_L_0157: ;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 2)));
  a = 0x76;
  hw_out(PORT_INTACK, a);
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) | (1u << 7)));
  a = 0x09;
  goto lab_p00_L_006E;
}

/* flash page 0 cpu 0x0161 (offset 0x0161) */
void p00_L_0161(void) {
  goto lab_p00_L_0161;
  lab_p00_L_006E: ;
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  a = 0x0B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_0080;
  a = (uint8_t)(a + 0x04);
  lab_p00_L_0080: ;
  hw_out(PORT_INTMASK, a);
  cpu_ex_af();
  cpu_exx();
  /* ei */
  return;
  lab_p00_L_00F9: ;
  set_bc((uint16_t)(bc() - 1));
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_nz()) p00_L_3F99();
  goto lab_p00_L_011F;
  lab_p00_L_011F: ;
  a = 0x09;
  goto lab_p00_L_006E;
  lab_p00_L_0161: ;
  goto lab_p00_L_00F9;
}

/* flash page 0 cpu 0x0189 (offset 0x0189) */
void p00_L_0189(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 4)) == 0);
  return;
}

/* flash page 0 cpu 0x018E (offset 0x018E) */
void p00_L_018E(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x07)) & (1u << 0)) == 0);
  return;
}

/* flash page 0 cpu 0x0198 (offset 0x0198) */
void p00_L_0198(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 5)) == 0);
  return;
}

/* flash page 0 cpu 0x01A2 (offset 0x01A2) */
void p00_L_01A2(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 6)) == 0);
  return;
}

/* flash page 0 cpu 0x01BF (offset 0x01BF) */
void p00_L_01BF(void) {
  set_hl(0x8476);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) return;
  p00_L_3FA5();
  return;
}

/* flash page 0 cpu 0x0247 (offset 0x0247) */
void p00_L_0247(void) {
  goto lab_p00_L_0247;
  lab_p00_L_0207: ;
  p00_rst00_boot();
  return;
  lab_p00_L_023C: ;
  a = mem_read8(hl());
  b = a;
  a = a ^ 0xFF;
  mem_write8(hl(), a);
  a = mem_read8(hl());
  a = a ^ 0xFF;
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p00_L_0207;
  mem_write8(hl(), a);
  a = c;
  lab_p00_L_0247: ;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_0251;
  set_hl(0x8000);
  c = 0x01;
  goto lab_p00_L_023C;
  lab_p00_L_0251: ;
  cpu_pop_hl();
  cpu_pop_bc();
  return;
}

/* flash page 0 cpu 0x0254 (offset 0x0254) */
void p00_L_0254(void) {
  a = mem_read8(0x89F8);
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_z()) return;
  set_hl(mem_read16(0x9C24));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) { p00_L_0265(); return; }
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x9C24, hl());
  p00_L_0265();
  return;
}

/* flash page 0 cpu 0x0265 (offset 0x0265) */
void p00_L_0265(void) {
  a = mem_read8(0x89F8);
  flag_set_z((a & (1u << 3)) == 0);
  if (flag_z()) return;
  set_hl(0x8448);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) return;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) return;
  p00_lcd_write_cmd();
  p00_L_3F7B();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 4)));
  goto lab_p00_L_08AC;
  lab_p00_L_08AC: ;
  p00_L_3E85();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  p00_lcd_write_cmd();
  set_hl(0x89F9);
  flag_set_z((mem_read8(hl()) & (1u << 2)) == 0);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 2)));
  if (flag_nz()) p00_L_3E8B();
  p00_L_0A3A();
  mem_write16(0x85BE, hl());
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 5)));
  a = 0x36;
  hw_out(PORT_INTACK, a);
  a = 0x11;
  hw_out(PORT_INTMASK, a);
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 3)));
  cpu_ex_af();
  cpu_exx();
  /* ei */
  lab_p00_L_08E1: ;
  halt();
  goto lab_p00_L_08E1;
}

/* flash page 0 cpu 0x02A8 (offset 0x02A8) */
void p00_L_02A8(void) {
  mem_write8((uint16_t)(iy + 0x3D), (uint8_t)(mem_read8((uint16_t)(iy + 0x3D)) | (1u << 7)));
  return;
}

/* flash page 0 cpu 0x02AD (offset 0x02AD) */
void p00_L_02AD(void) {
  set_hl(0x8449);
  mem_write8(hl(), 0x74);
  return;
}

/* flash page 0 cpu 0x02B3 (offset 0x02B3) */
void p00_L_02B3(void) {
  p00_L_0305();
  if (flag_c()) goto lab_p00_L_02FA;
  set_hl(0x8441);
  cpu_cp_hl();
  set_hl(0x8443);
  if (flag_z()) goto lab_p00_L_02C6;
  mem_write8(0x8441, a);
  mem_write8(hl(), 0x05);
  lab_p00_L_02C6: ;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_02CC;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) return;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p00_L_02CC: ;
  set_hl(0x8440);
  cpu_cp_hl();
  if (flag_nz()) goto lab_p00_L_02E9;
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  flag_cmp(a, 0xF3);
  if (flag_nc()) goto lab_p00_L_02DF;
  flag_cmp(a, 0x38);
  if (flag_z()) goto lab_p00_L_02DF;
  flag_cmp(a, 0x05);
  if (flag_nc()) return;
  lab_p00_L_02DF: ;
  set_hl(0x8442);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) return;
  mem_write8(hl(), 0x0A);
  p00_L_037F();
  return;
  lab_p00_L_02E9: ;
  p00_L_037F();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_02F3;
  /* set 4,(iy) */
  lab_p00_L_02F3: ;
  mem_write8(hl(), a);
  a = 0x32;
  mem_write8(0x8442, a);
  return;
  lab_p00_L_02FA: ;
  a = 0xFF;
  mem_write8(0x8441, a);
  a = 0x05;
  mem_write8(0x8443, a);
  return;
}

/* flash page 0 cpu 0x0305 (offset 0x0305) */
void p00_L_0305(void) {
  a = 0;
  flag_logic(a);
  p00_key_scan();
  a = a ^ 0xFF;
  flag_logic(a);
  if (flag_z()) return;
  set_hl(0x0000);
  c = 0xFE;
  d = 0x01;
  lab_p00_L_0313: ;
  a = c;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_032F;
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p00_L_032F;
  p00_key_scan();
  flag_cmp(a, 0xF5);
  if (flag_z()) return;
  flag_cmp(a, 0xF3);
  if (flag_z()) return;
  flag_cmp(a, 0xFA);
  if (flag_z()) return;
  flag_cmp(a, 0xFC);
  if (flag_z()) return;
  goto lab_p00_L_0332;
  lab_p00_L_032F: ;
  p00_key_scan();
  lab_p00_L_0332: ;
  e = 0x00;
  b = 0x08;
  lab_p00_L_0336: ;
  cpu_rla();
  if (flag_c()) goto lab_p00_L_033B;
  e = (uint8_t)(e + 1);
  l = b;
  lab_p00_L_033B: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0336;
  a = e;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_034A;
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p00_L_0358;
  p00_L_0345();
  return;
  lab_p00_L_034A: ;
  d = (uint8_t)(d + 1);
  /* rlc c */
  if (flag_c()) goto lab_p00_L_0313;
  a = h;
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  a = (uint8_t)(a - 1);
  cpu_rla();
  cpu_rla();
  cpu_rla();
  p00_L_0356();
  return;
  lab_p00_L_0358: ;
  /* scf */
  return;
}

/* flash page 0 cpu 0x0345 (offset 0x0345) */
void p00_L_0345(void) {
  goto lab_p00_L_0345;
  lab_p00_L_0313: ;
  a = c;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2C)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_032F;
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p00_L_032F;
  p00_key_scan();
  flag_cmp(a, 0xF5);
  if (flag_z()) return;
  flag_cmp(a, 0xF3);
  if (flag_z()) return;
  flag_cmp(a, 0xFA);
  if (flag_z()) return;
  flag_cmp(a, 0xFC);
  if (flag_z()) return;
  goto lab_p00_L_0332;
  lab_p00_L_032F: ;
  p00_key_scan();
  lab_p00_L_0332: ;
  e = 0x00;
  b = 0x08;
  lab_p00_L_0336: ;
  cpu_rla();
  if (flag_c()) goto lab_p00_L_033B;
  e = (uint8_t)(e + 1);
  l = b;
  lab_p00_L_033B: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0336;
  a = e;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_034A;
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p00_L_0358;
  lab_p00_L_0345: ;
  a = h;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_0358;
  h = d;
  lab_p00_L_034A: ;
  d = (uint8_t)(d + 1);
  /* rlc c */
  if (flag_c()) goto lab_p00_L_0313;
  a = h;
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  a = (uint8_t)(a - 1);
  cpu_rla();
  cpu_rla();
  cpu_rla();
  p00_L_0356();
  return;
  lab_p00_L_0358: ;
  /* scf */
  return;
}

/* flash page 0 cpu 0x0356 (offset 0x0356) */
void p00_L_0356(void) {
  a = (uint8_t)(a + l);
  return;
}

/* flash page 0 cpu 0x035A (offset 0x035A) */
void p00_key_scan(void) {
  /* CURATED -> key_scan */
  a = key_scan(a);
}

/* flash page 0 cpu 0x036F (offset 0x036F) */
void p00_L_036F(void) {
  a = b;
  return;
}

/* flash page 0 cpu 0x037F (offset 0x037F) */
void p00_L_037F(void) {
  mem_write8(0x843F, a);
  /* set 3,(iy) */
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  mem_write8(0x8445, a);
  return;
}

/* flash page 0 cpu 0x038C (offset 0x038C) */
void p00_L_038C(void) {
  set_hl(0x843F);
  /* di */
  a = mem_read8(hl());
  mem_write8(hl(), 0x00);
  /* res 3,(iy) */
  /* ei */
  return;
}

/* flash page 0 cpu 0x03A0 (offset 0x03A0) */
void p00_L_03A0(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 6)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 7)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 4)));
  return;
}

/* flash page 0 cpu 0x0443 (offset 0x0443) */
void p00_L_0443(void) {
  goto lab_p00_L_0443;
  lab_p00_L_03C5: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p00_L_3EFD();
  p00_L_3F03();
  lab_p00_L_03CF: ;
  p00_L_3F09();
  p00_L_3F0F();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 7)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x1F)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0408;
  /* di */
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 5)));
  set_hl(0x0403);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  a = mem_read8(0x859A);
  flag_cmp(a, 0x52);
  if (flag_nz()) goto lab_p00_L_03FD;
  a = mem_read8(0x86DD);
  p00_L_3F15();
  goto lab_p00_L_0400;
  lab_p00_L_03FD: ;
  p00_L_3F1B();
  lab_p00_L_0400: ;
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  /* ei */
  lab_p00_L_0408: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8444, a);
  mem_write8(0x8446, a);
  p00_L_3F21();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 1)));
  mem_write8(0x8444, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_0433;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 3)) == 0);
  if (flag_z()) p00_L_3F27();
  a = mem_read8(0x8444);
  goto lab_p00_L_0436;
  lab_p00_L_0433: ;
  p00_L_3EFD();
  lab_p00_L_0436: ;
  p00_L_3F2D();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_044D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_0448;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  lab_p00_L_0443: ;
  /* rrc c */
  /* and (hl) */
  goto lab_p00_L_04B2;
  lab_p00_L_0448: ;
  a = 0x05;
  goto lab_p00_L_0515;
  lab_p00_L_044D: ;
  flag_cmp(a, 0xB4);
  if (flag_nz()) goto lab_p00_L_0470;
  a = 0xCC;
  p00_L_0198();
  if (flag_nz()) goto lab_p00_L_046D;
  a = 0xAD;
  p00_L_045A();
  return;
  lab_p00_L_046D: ;
  mem_write8(0x8444, a);
  lab_p00_L_0470: ;
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  p00_L_3F33();
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p00_L_04B2;
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  cpu_push_af();
  goto lab_p00_L_053E;
  lab_p00_L_0491: ;
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p00_L_04A2;
  p00_L_3F39();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_3F3F();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_07DE();
  lab_p00_L_04A2: ;
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x29);
  if (flag_z()) goto lab_p00_L_0515;
  goto lab_p00_L_04D0;
  lab_p00_L_04AE: ;
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_04BA;
  lab_p00_L_04B2: ;
  goto lab_p00_L_03C5;
  lab_p00_L_04B5: ;
  b = 0x08;
  set_hl(0x84BE);
  lab_p00_L_04BA: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04B2;
  cpu_push_bc();
  cpu_push_hl();
  d = 0x00;
  e = a;
  p00_L_3F45();
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  goto lab_p00_L_04AE;
  lab_p00_L_04D0: ;
  flag_cmp(a, 0x7F);
  if (flag_c()) goto lab_p00_L_0595;
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFB);
  if (flag_nz()) goto lab_p00_L_04FA;
  a = mem_read8(0x8446);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04F7;
  flag_cmp(a, 0x0D);
  if (flag_c()) goto lab_p00_L_04F3;
  flag_cmp(a, 0x8C);
  if (flag_c()) goto lab_p00_L_0549;
  flag_cmp(a, 0xA6);
  if (flag_nc()) goto lab_p00_L_0549;
  lab_p00_L_04F3: ;
  a = 0xFB;
  goto lab_p00_L_0515;
  lab_p00_L_04F7: ;
  a = mem_read8(0x8444);
  lab_p00_L_04FA: ;
  flag_cmp(a, 0xEF);
  if (flag_nz()) goto lab_p00_L_0502;
  a = 0xA6;
  goto lab_p00_L_0510;
  lab_p00_L_0502: ;
  flag_cmp(a, 0xF9);
  if (flag_c()) goto lab_p00_L_050A;
  a = (uint8_t)(a - 0x14);
  goto lab_p00_L_0510;
  lab_p00_L_050A: ;
  flag_cmp(a, 0xF3);
  if (flag_c()) goto lab_p00_L_0515;
  a = (uint8_t)(a - 0x7C);
  lab_p00_L_0510: ;
  mem_write8(0x8446, a);
  a = 0xFE;
  lab_p00_L_0515: ;
  flag_cmp(a, 0x69);
  if (flag_nz()) goto lab_p00_L_051D;
  a = 0xFC;
  goto lab_p00_L_0510;
  lab_p00_L_051D: ;
  flag_cmp(a, 0x5B);
  if (flag_nz()) goto lab_p00_L_0525;
  a = 0xFD;
  goto lab_p00_L_0510;
  lab_p00_L_0525: ;
  flag_cmp(a, 0x28);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_0532;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 7)));
  a = 0xDA;
  goto lab_p00_L_053E;
  lab_p00_L_0532: ;
  cpu_pop_af();
  flag_cmp(a, 0x29);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_053E;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 1)));
  a = 0x7F;
  lab_p00_L_053E: ;
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  cpu_pop_af();
  if (flag_z()) goto lab_p00_L_04B5;
  lab_p00_L_0549: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p00_L_058E;
  set_de(mem_read16(0x86D9));
  set_hl(mem_read16(0x96F6));
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0560;
  set_hl(mem_read16(0x86DB));
  cpu_ex_de_hl();
  lab_p00_L_0560: ;
  p00_L_192A();
  if (flag_nc()) goto lab_p00_L_0580;
  a = mem_read8(hl());
  p00_L_172F();
  d = 0x00;
  e = a;
  if (flag_nz()) goto lab_p00_L_0571;
  d = a;
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  lab_p00_L_0571: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_057B;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x86D9, hl());
  lab_p00_L_057B: ;
  p00_L_3F45();
  lab_p00_L_057E: ;
  goto lab_p00_L_0515;
  lab_p00_L_0580: ;
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 7)));
  set_hl(0x89F5);
  a = mem_read8(0x85C2);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 4)));
  /* or (hl) */
  mem_write8(hl(), a);
  lab_p00_L_058E: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 2)));
  goto lab_p00_L_03CF;
  lab_p00_L_0595: ;
  flag_cmp(a, 0x27);
  if (flag_c()) goto lab_p00_L_057E;
  flag_cmp(a, 0x5A);
  if (flag_c()) goto lab_p00_L_05C2;
  flag_cmp(a, 0x75);
  if (flag_nc()) goto lab_p00_L_05BC;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_057E;
  flag_cmp(a, 0x69);
  if (flag_c()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x6D);
  if (flag_z()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x69);
  if (flag_z()) goto lab_p00_L_057E;
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x44);
  a = b;
  if (flag_nz()) goto lab_p00_L_057E;
  lab_p00_L_05BC: ;
  b = a;
  a = 0x44;
  goto lab_p00_L_05D0;
  lab_p00_L_05C2: ;
  b = a;
  flag_cmp(a, 0x59);
  if (flag_nz()) goto lab_p00_L_05D0;
  a = mem_read8(0x8446);
  a = (uint8_t)(a + b);
  flag_cmp(a, 0x5B);
  if (flag_nc()) goto lab_p00_L_05F1;
  b = a;
  lab_p00_L_05D0: ;
  c = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x50);
  if (flag_nz()) goto lab_p00_L_05E1;
  a = b;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p00_L_05F1;
  a = 0x50;
  goto lab_p00_L_05EA;
  lab_p00_L_05E1: ;
  flag_cmp(a, 0x52);
  a = c;
  if (flag_nz()) goto lab_p00_L_05EA;
  flag_cmp(a, 0x40);
  if (flag_nz()) goto lab_p00_L_058E;
  lab_p00_L_05EA: ;
  p00_L_0633();
  a = b;
  goto lab_p00_L_0525;
  lab_p00_L_05F1: ;
  a = 0;
  flag_logic(a);
  b = a;
  sp = mem_read16(0x85BC);
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 6)));
  p00_L_0BB1();
  a = 0x40;
  p00_L_0633();
  a = b;
  flag_cmp(a, 0xDA);
  if (flag_nz()) goto lab_p00_L_060D;
  a = 0x28;
  lab_p00_L_060A: ;
  goto lab_p00_L_0515;
  lab_p00_L_060D: ;
  flag_cmp(a, 0x7F);
  if (flag_nz()) goto lab_p00_L_060A;
  a = 0x29;
  goto lab_p00_L_060A;
}

/* flash page 0 cpu 0x0444 (offset 0x0444) */
void p00_L_0444(void) {
  goto lab_p00_L_0444;
  lab_p00_L_03C5: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p00_L_3EFD();
  p00_L_3F03();
  lab_p00_L_03CF: ;
  p00_L_3F09();
  p00_L_3F0F();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 7)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x1F)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0408;
  /* di */
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 5)));
  set_hl(0x0403);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  a = mem_read8(0x859A);
  flag_cmp(a, 0x52);
  if (flag_nz()) goto lab_p00_L_03FD;
  a = mem_read8(0x86DD);
  p00_L_3F15();
  goto lab_p00_L_0400;
  lab_p00_L_03FD: ;
  p00_L_3F1B();
  lab_p00_L_0400: ;
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  /* ei */
  lab_p00_L_0408: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8444, a);
  mem_write8(0x8446, a);
  p00_L_3F21();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 1)));
  mem_write8(0x8444, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_0433;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 3)) == 0);
  if (flag_z()) p00_L_3F27();
  a = mem_read8(0x8444);
  goto lab_p00_L_0436;
  lab_p00_L_0433: ;
  p00_L_3EFD();
  lab_p00_L_0436: ;
  p00_L_3F2D();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_044D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_0448;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  lab_p00_L_0444: ;
  set_hl((uint16_t)(hl() + bc()));
  /* and (hl) */
  goto lab_p00_L_04B2;
  lab_p00_L_0448: ;
  a = 0x05;
  goto lab_p00_L_0515;
  lab_p00_L_044D: ;
  flag_cmp(a, 0xB4);
  if (flag_nz()) goto lab_p00_L_0470;
  a = 0xCC;
  p00_L_0198();
  if (flag_nz()) goto lab_p00_L_046D;
  a = 0xAD;
  p00_L_045A();
  return;
  lab_p00_L_046D: ;
  mem_write8(0x8444, a);
  lab_p00_L_0470: ;
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  p00_L_3F33();
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p00_L_04B2;
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  cpu_push_af();
  goto lab_p00_L_053E;
  lab_p00_L_0491: ;
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p00_L_04A2;
  p00_L_3F39();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_3F3F();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_07DE();
  lab_p00_L_04A2: ;
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x29);
  if (flag_z()) goto lab_p00_L_0515;
  goto lab_p00_L_04D0;
  lab_p00_L_04AE: ;
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_04BA;
  lab_p00_L_04B2: ;
  goto lab_p00_L_03C5;
  lab_p00_L_04B5: ;
  b = 0x08;
  set_hl(0x84BE);
  lab_p00_L_04BA: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04B2;
  cpu_push_bc();
  cpu_push_hl();
  d = 0x00;
  e = a;
  p00_L_3F45();
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  goto lab_p00_L_04AE;
  lab_p00_L_04D0: ;
  flag_cmp(a, 0x7F);
  if (flag_c()) goto lab_p00_L_0595;
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFB);
  if (flag_nz()) goto lab_p00_L_04FA;
  a = mem_read8(0x8446);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04F7;
  flag_cmp(a, 0x0D);
  if (flag_c()) goto lab_p00_L_04F3;
  flag_cmp(a, 0x8C);
  if (flag_c()) goto lab_p00_L_0549;
  flag_cmp(a, 0xA6);
  if (flag_nc()) goto lab_p00_L_0549;
  lab_p00_L_04F3: ;
  a = 0xFB;
  goto lab_p00_L_0515;
  lab_p00_L_04F7: ;
  a = mem_read8(0x8444);
  lab_p00_L_04FA: ;
  flag_cmp(a, 0xEF);
  if (flag_nz()) goto lab_p00_L_0502;
  a = 0xA6;
  goto lab_p00_L_0510;
  lab_p00_L_0502: ;
  flag_cmp(a, 0xF9);
  if (flag_c()) goto lab_p00_L_050A;
  a = (uint8_t)(a - 0x14);
  goto lab_p00_L_0510;
  lab_p00_L_050A: ;
  flag_cmp(a, 0xF3);
  if (flag_c()) goto lab_p00_L_0515;
  a = (uint8_t)(a - 0x7C);
  lab_p00_L_0510: ;
  mem_write8(0x8446, a);
  a = 0xFE;
  lab_p00_L_0515: ;
  flag_cmp(a, 0x69);
  if (flag_nz()) goto lab_p00_L_051D;
  a = 0xFC;
  goto lab_p00_L_0510;
  lab_p00_L_051D: ;
  flag_cmp(a, 0x5B);
  if (flag_nz()) goto lab_p00_L_0525;
  a = 0xFD;
  goto lab_p00_L_0510;
  lab_p00_L_0525: ;
  flag_cmp(a, 0x28);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_0532;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 7)));
  a = 0xDA;
  goto lab_p00_L_053E;
  lab_p00_L_0532: ;
  cpu_pop_af();
  flag_cmp(a, 0x29);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_053E;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 1)));
  a = 0x7F;
  lab_p00_L_053E: ;
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  cpu_pop_af();
  if (flag_z()) goto lab_p00_L_04B5;
  lab_p00_L_0549: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p00_L_058E;
  set_de(mem_read16(0x86D9));
  set_hl(mem_read16(0x96F6));
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0560;
  set_hl(mem_read16(0x86DB));
  cpu_ex_de_hl();
  lab_p00_L_0560: ;
  p00_L_192A();
  if (flag_nc()) goto lab_p00_L_0580;
  a = mem_read8(hl());
  p00_L_172F();
  d = 0x00;
  e = a;
  if (flag_nz()) goto lab_p00_L_0571;
  d = a;
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  lab_p00_L_0571: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_057B;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x86D9, hl());
  lab_p00_L_057B: ;
  p00_L_3F45();
  lab_p00_L_057E: ;
  goto lab_p00_L_0515;
  lab_p00_L_0580: ;
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 7)));
  set_hl(0x89F5);
  a = mem_read8(0x85C2);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 4)));
  /* or (hl) */
  mem_write8(hl(), a);
  lab_p00_L_058E: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 2)));
  goto lab_p00_L_03CF;
  lab_p00_L_0595: ;
  flag_cmp(a, 0x27);
  if (flag_c()) goto lab_p00_L_057E;
  flag_cmp(a, 0x5A);
  if (flag_c()) goto lab_p00_L_05C2;
  flag_cmp(a, 0x75);
  if (flag_nc()) goto lab_p00_L_05BC;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_057E;
  flag_cmp(a, 0x69);
  if (flag_c()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x6D);
  if (flag_z()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x69);
  if (flag_z()) goto lab_p00_L_057E;
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x44);
  a = b;
  if (flag_nz()) goto lab_p00_L_057E;
  lab_p00_L_05BC: ;
  b = a;
  a = 0x44;
  goto lab_p00_L_05D0;
  lab_p00_L_05C2: ;
  b = a;
  flag_cmp(a, 0x59);
  if (flag_nz()) goto lab_p00_L_05D0;
  a = mem_read8(0x8446);
  a = (uint8_t)(a + b);
  flag_cmp(a, 0x5B);
  if (flag_nc()) goto lab_p00_L_05F1;
  b = a;
  lab_p00_L_05D0: ;
  c = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x50);
  if (flag_nz()) goto lab_p00_L_05E1;
  a = b;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p00_L_05F1;
  a = 0x50;
  goto lab_p00_L_05EA;
  lab_p00_L_05E1: ;
  flag_cmp(a, 0x52);
  a = c;
  if (flag_nz()) goto lab_p00_L_05EA;
  flag_cmp(a, 0x40);
  if (flag_nz()) goto lab_p00_L_058E;
  lab_p00_L_05EA: ;
  p00_L_0633();
  a = b;
  goto lab_p00_L_0525;
  lab_p00_L_05F1: ;
  a = 0;
  flag_logic(a);
  b = a;
  sp = mem_read16(0x85BC);
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 6)));
  p00_L_0BB1();
  a = 0x40;
  p00_L_0633();
  a = b;
  flag_cmp(a, 0xDA);
  if (flag_nz()) goto lab_p00_L_060D;
  a = 0x28;
  lab_p00_L_060A: ;
  goto lab_p00_L_0515;
  lab_p00_L_060D: ;
  flag_cmp(a, 0x7F);
  if (flag_nz()) goto lab_p00_L_060A;
  a = 0x29;
  goto lab_p00_L_060A;
}

/* flash page 0 cpu 0x045A (offset 0x045A) */
void p00_L_045A(void) {
  goto lab_p00_L_045A;
  lab_p00_L_03C5: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p00_L_3EFD();
  p00_L_3F03();
  lab_p00_L_03CF: ;
  p00_L_3F09();
  p00_L_3F0F();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 7)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x1F)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0408;
  /* di */
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 5)));
  set_hl(0x0403);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  a = mem_read8(0x859A);
  flag_cmp(a, 0x52);
  if (flag_nz()) goto lab_p00_L_03FD;
  a = mem_read8(0x86DD);
  p00_L_3F15();
  goto lab_p00_L_0400;
  lab_p00_L_03FD: ;
  p00_L_3F1B();
  lab_p00_L_0400: ;
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  /* ei */
  lab_p00_L_0408: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8444, a);
  mem_write8(0x8446, a);
  p00_L_3F21();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 1)));
  mem_write8(0x8444, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_0433;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 3)) == 0);
  if (flag_z()) p00_L_3F27();
  a = mem_read8(0x8444);
  goto lab_p00_L_0436;
  lab_p00_L_0433: ;
  p00_L_3EFD();
  lab_p00_L_0436: ;
  p00_L_3F2D();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_044D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_0448;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  goto lab_p00_L_04B2;
  lab_p00_L_0448: ;
  a = 0x05;
  goto lab_p00_L_0515;
  lab_p00_L_044D: ;
  flag_cmp(a, 0xB4);
  if (flag_nz()) goto lab_p00_L_0470;
  a = 0xCC;
  p00_L_0198();
  if (flag_nz()) goto lab_p00_L_046D;
  a = 0xAD;
  lab_p00_L_045A: ;
  p00_L_01A2();
  if (flag_nz()) goto lab_p00_L_046D;
  a = 0xB1;
  p00_L_0013();
  if (flag_nz()) goto lab_p00_L_046D;
  a = 0xE8;
  mem_write8(0x8446, a);
  a = 0xFE;
  lab_p00_L_046D: ;
  mem_write8(0x8444, a);
  lab_p00_L_0470: ;
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  p00_L_3F33();
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p00_L_04B2;
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  cpu_push_af();
  goto lab_p00_L_053E;
  lab_p00_L_0491: ;
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p00_L_04A2;
  p00_L_3F39();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_3F3F();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_07DE();
  lab_p00_L_04A2: ;
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x29);
  if (flag_z()) goto lab_p00_L_0515;
  goto lab_p00_L_04D0;
  lab_p00_L_04AE: ;
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_04BA;
  lab_p00_L_04B2: ;
  goto lab_p00_L_03C5;
  lab_p00_L_04B5: ;
  b = 0x08;
  set_hl(0x84BE);
  lab_p00_L_04BA: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04B2;
  cpu_push_bc();
  cpu_push_hl();
  d = 0x00;
  e = a;
  p00_L_3F45();
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  goto lab_p00_L_04AE;
  lab_p00_L_04D0: ;
  flag_cmp(a, 0x7F);
  if (flag_c()) goto lab_p00_L_0595;
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFB);
  if (flag_nz()) goto lab_p00_L_04FA;
  a = mem_read8(0x8446);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04F7;
  flag_cmp(a, 0x0D);
  if (flag_c()) goto lab_p00_L_04F3;
  flag_cmp(a, 0x8C);
  if (flag_c()) goto lab_p00_L_0549;
  flag_cmp(a, 0xA6);
  if (flag_nc()) goto lab_p00_L_0549;
  lab_p00_L_04F3: ;
  a = 0xFB;
  goto lab_p00_L_0515;
  lab_p00_L_04F7: ;
  a = mem_read8(0x8444);
  lab_p00_L_04FA: ;
  flag_cmp(a, 0xEF);
  if (flag_nz()) goto lab_p00_L_0502;
  a = 0xA6;
  goto lab_p00_L_0510;
  lab_p00_L_0502: ;
  flag_cmp(a, 0xF9);
  if (flag_c()) goto lab_p00_L_050A;
  a = (uint8_t)(a - 0x14);
  goto lab_p00_L_0510;
  lab_p00_L_050A: ;
  flag_cmp(a, 0xF3);
  if (flag_c()) goto lab_p00_L_0515;
  a = (uint8_t)(a - 0x7C);
  lab_p00_L_0510: ;
  mem_write8(0x8446, a);
  a = 0xFE;
  lab_p00_L_0515: ;
  flag_cmp(a, 0x69);
  if (flag_nz()) goto lab_p00_L_051D;
  a = 0xFC;
  goto lab_p00_L_0510;
  lab_p00_L_051D: ;
  flag_cmp(a, 0x5B);
  if (flag_nz()) goto lab_p00_L_0525;
  a = 0xFD;
  goto lab_p00_L_0510;
  lab_p00_L_0525: ;
  flag_cmp(a, 0x28);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_0532;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 7)));
  a = 0xDA;
  goto lab_p00_L_053E;
  lab_p00_L_0532: ;
  cpu_pop_af();
  flag_cmp(a, 0x29);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_053E;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 1)));
  a = 0x7F;
  lab_p00_L_053E: ;
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  cpu_pop_af();
  if (flag_z()) goto lab_p00_L_04B5;
  lab_p00_L_0549: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p00_L_058E;
  set_de(mem_read16(0x86D9));
  set_hl(mem_read16(0x96F6));
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0560;
  set_hl(mem_read16(0x86DB));
  cpu_ex_de_hl();
  lab_p00_L_0560: ;
  p00_L_192A();
  if (flag_nc()) goto lab_p00_L_0580;
  a = mem_read8(hl());
  p00_L_172F();
  d = 0x00;
  e = a;
  if (flag_nz()) goto lab_p00_L_0571;
  d = a;
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  lab_p00_L_0571: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_057B;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x86D9, hl());
  lab_p00_L_057B: ;
  p00_L_3F45();
  lab_p00_L_057E: ;
  goto lab_p00_L_0515;
  lab_p00_L_0580: ;
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 7)));
  set_hl(0x89F5);
  a = mem_read8(0x85C2);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 4)));
  /* or (hl) */
  mem_write8(hl(), a);
  lab_p00_L_058E: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 2)));
  goto lab_p00_L_03CF;
  lab_p00_L_0595: ;
  flag_cmp(a, 0x27);
  if (flag_c()) goto lab_p00_L_057E;
  flag_cmp(a, 0x5A);
  if (flag_c()) goto lab_p00_L_05C2;
  flag_cmp(a, 0x75);
  if (flag_nc()) goto lab_p00_L_05BC;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_057E;
  flag_cmp(a, 0x69);
  if (flag_c()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x6D);
  if (flag_z()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x69);
  if (flag_z()) goto lab_p00_L_057E;
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x44);
  a = b;
  if (flag_nz()) goto lab_p00_L_057E;
  lab_p00_L_05BC: ;
  b = a;
  a = 0x44;
  goto lab_p00_L_05D0;
  lab_p00_L_05C2: ;
  b = a;
  flag_cmp(a, 0x59);
  if (flag_nz()) goto lab_p00_L_05D0;
  a = mem_read8(0x8446);
  a = (uint8_t)(a + b);
  flag_cmp(a, 0x5B);
  if (flag_nc()) goto lab_p00_L_05F1;
  b = a;
  lab_p00_L_05D0: ;
  c = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x50);
  if (flag_nz()) goto lab_p00_L_05E1;
  a = b;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p00_L_05F1;
  a = 0x50;
  goto lab_p00_L_05EA;
  lab_p00_L_05E1: ;
  flag_cmp(a, 0x52);
  a = c;
  if (flag_nz()) goto lab_p00_L_05EA;
  flag_cmp(a, 0x40);
  if (flag_nz()) goto lab_p00_L_058E;
  lab_p00_L_05EA: ;
  p00_L_0633();
  a = b;
  goto lab_p00_L_0525;
  lab_p00_L_05F1: ;
  a = 0;
  flag_logic(a);
  b = a;
  sp = mem_read16(0x85BC);
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 6)));
  p00_L_0BB1();
  a = 0x40;
  p00_L_0633();
  a = b;
  flag_cmp(a, 0xDA);
  if (flag_nz()) goto lab_p00_L_060D;
  a = 0x28;
  lab_p00_L_060A: ;
  goto lab_p00_L_0515;
  lab_p00_L_060D: ;
  flag_cmp(a, 0x7F);
  if (flag_nz()) goto lab_p00_L_060A;
  a = 0x29;
  goto lab_p00_L_060A;
}

/* flash page 0 cpu 0x0463 (offset 0x0463) */
void p00_L_0463(void) {
  goto lab_p00_L_0463;
  lab_p00_L_03C5: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p00_L_3EFD();
  p00_L_3F03();
  lab_p00_L_03CF: ;
  p00_L_3F09();
  p00_L_3F0F();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 7)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x1F)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0408;
  /* di */
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 5)));
  set_hl(0x0403);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  a = mem_read8(0x859A);
  flag_cmp(a, 0x52);
  if (flag_nz()) goto lab_p00_L_03FD;
  a = mem_read8(0x86DD);
  p00_L_3F15();
  goto lab_p00_L_0400;
  lab_p00_L_03FD: ;
  p00_L_3F1B();
  lab_p00_L_0400: ;
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  /* ei */
  lab_p00_L_0408: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8444, a);
  mem_write8(0x8446, a);
  p00_L_3F21();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 1)));
  mem_write8(0x8444, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_0433;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 3)) == 0);
  if (flag_z()) p00_L_3F27();
  a = mem_read8(0x8444);
  goto lab_p00_L_0436;
  lab_p00_L_0433: ;
  p00_L_3EFD();
  lab_p00_L_0436: ;
  p00_L_3F2D();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_044D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_0448;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  goto lab_p00_L_04B2;
  lab_p00_L_0448: ;
  a = 0x05;
  goto lab_p00_L_0515;
  lab_p00_L_044D: ;
  flag_cmp(a, 0xB4);
  if (flag_nz()) goto lab_p00_L_0470;
  a = 0xCC;
  p00_L_0198();
  if (flag_nz()) goto lab_p00_L_046D;
  a = 0xAD;
  p00_L_045A();
  return;
  lab_p00_L_0463: ;
  /* nop */
  if (flag_nz()) goto lab_p00_L_046D;
  a = 0xE8;
  mem_write8(0x8446, a);
  a = 0xFE;
  lab_p00_L_046D: ;
  mem_write8(0x8444, a);
  lab_p00_L_0470: ;
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  p00_L_3F33();
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p00_L_04B2;
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  cpu_push_af();
  goto lab_p00_L_053E;
  lab_p00_L_0491: ;
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p00_L_04A2;
  p00_L_3F39();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_3F3F();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_07DE();
  lab_p00_L_04A2: ;
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x29);
  if (flag_z()) goto lab_p00_L_0515;
  goto lab_p00_L_04D0;
  lab_p00_L_04AE: ;
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_04BA;
  lab_p00_L_04B2: ;
  goto lab_p00_L_03C5;
  lab_p00_L_04B5: ;
  b = 0x08;
  set_hl(0x84BE);
  lab_p00_L_04BA: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04B2;
  cpu_push_bc();
  cpu_push_hl();
  d = 0x00;
  e = a;
  p00_L_3F45();
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  goto lab_p00_L_04AE;
  lab_p00_L_04D0: ;
  flag_cmp(a, 0x7F);
  if (flag_c()) goto lab_p00_L_0595;
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFB);
  if (flag_nz()) goto lab_p00_L_04FA;
  a = mem_read8(0x8446);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04F7;
  flag_cmp(a, 0x0D);
  if (flag_c()) goto lab_p00_L_04F3;
  flag_cmp(a, 0x8C);
  if (flag_c()) goto lab_p00_L_0549;
  flag_cmp(a, 0xA6);
  if (flag_nc()) goto lab_p00_L_0549;
  lab_p00_L_04F3: ;
  a = 0xFB;
  goto lab_p00_L_0515;
  lab_p00_L_04F7: ;
  a = mem_read8(0x8444);
  lab_p00_L_04FA: ;
  flag_cmp(a, 0xEF);
  if (flag_nz()) goto lab_p00_L_0502;
  a = 0xA6;
  goto lab_p00_L_0510;
  lab_p00_L_0502: ;
  flag_cmp(a, 0xF9);
  if (flag_c()) goto lab_p00_L_050A;
  a = (uint8_t)(a - 0x14);
  goto lab_p00_L_0510;
  lab_p00_L_050A: ;
  flag_cmp(a, 0xF3);
  if (flag_c()) goto lab_p00_L_0515;
  a = (uint8_t)(a - 0x7C);
  lab_p00_L_0510: ;
  mem_write8(0x8446, a);
  a = 0xFE;
  lab_p00_L_0515: ;
  flag_cmp(a, 0x69);
  if (flag_nz()) goto lab_p00_L_051D;
  a = 0xFC;
  goto lab_p00_L_0510;
  lab_p00_L_051D: ;
  flag_cmp(a, 0x5B);
  if (flag_nz()) goto lab_p00_L_0525;
  a = 0xFD;
  goto lab_p00_L_0510;
  lab_p00_L_0525: ;
  flag_cmp(a, 0x28);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_0532;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 7)));
  a = 0xDA;
  goto lab_p00_L_053E;
  lab_p00_L_0532: ;
  cpu_pop_af();
  flag_cmp(a, 0x29);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_053E;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 1)));
  a = 0x7F;
  lab_p00_L_053E: ;
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  cpu_pop_af();
  if (flag_z()) goto lab_p00_L_04B5;
  lab_p00_L_0549: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p00_L_058E;
  set_de(mem_read16(0x86D9));
  set_hl(mem_read16(0x96F6));
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0560;
  set_hl(mem_read16(0x86DB));
  cpu_ex_de_hl();
  lab_p00_L_0560: ;
  p00_L_192A();
  if (flag_nc()) goto lab_p00_L_0580;
  a = mem_read8(hl());
  p00_L_172F();
  d = 0x00;
  e = a;
  if (flag_nz()) goto lab_p00_L_0571;
  d = a;
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  lab_p00_L_0571: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_057B;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x86D9, hl());
  lab_p00_L_057B: ;
  p00_L_3F45();
  lab_p00_L_057E: ;
  goto lab_p00_L_0515;
  lab_p00_L_0580: ;
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 7)));
  set_hl(0x89F5);
  a = mem_read8(0x85C2);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 4)));
  /* or (hl) */
  mem_write8(hl(), a);
  lab_p00_L_058E: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 2)));
  goto lab_p00_L_03CF;
  lab_p00_L_0595: ;
  flag_cmp(a, 0x27);
  if (flag_c()) goto lab_p00_L_057E;
  flag_cmp(a, 0x5A);
  if (flag_c()) goto lab_p00_L_05C2;
  flag_cmp(a, 0x75);
  if (flag_nc()) goto lab_p00_L_05BC;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_057E;
  flag_cmp(a, 0x69);
  if (flag_c()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x6D);
  if (flag_z()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x69);
  if (flag_z()) goto lab_p00_L_057E;
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x44);
  a = b;
  if (flag_nz()) goto lab_p00_L_057E;
  lab_p00_L_05BC: ;
  b = a;
  a = 0x44;
  goto lab_p00_L_05D0;
  lab_p00_L_05C2: ;
  b = a;
  flag_cmp(a, 0x59);
  if (flag_nz()) goto lab_p00_L_05D0;
  a = mem_read8(0x8446);
  a = (uint8_t)(a + b);
  flag_cmp(a, 0x5B);
  if (flag_nc()) goto lab_p00_L_05F1;
  b = a;
  lab_p00_L_05D0: ;
  c = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x50);
  if (flag_nz()) goto lab_p00_L_05E1;
  a = b;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p00_L_05F1;
  a = 0x50;
  goto lab_p00_L_05EA;
  lab_p00_L_05E1: ;
  flag_cmp(a, 0x52);
  a = c;
  if (flag_nz()) goto lab_p00_L_05EA;
  flag_cmp(a, 0x40);
  if (flag_nz()) goto lab_p00_L_058E;
  lab_p00_L_05EA: ;
  p00_L_0633();
  a = b;
  goto lab_p00_L_0525;
  lab_p00_L_05F1: ;
  a = 0;
  flag_logic(a);
  b = a;
  sp = mem_read16(0x85BC);
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 6)));
  p00_L_0BB1();
  a = 0x40;
  p00_L_0633();
  a = b;
  flag_cmp(a, 0xDA);
  if (flag_nz()) goto lab_p00_L_060D;
  a = 0x28;
  lab_p00_L_060A: ;
  goto lab_p00_L_0515;
  lab_p00_L_060D: ;
  flag_cmp(a, 0x7F);
  if (flag_nz()) goto lab_p00_L_060A;
  a = 0x29;
  goto lab_p00_L_060A;
}

/* flash page 0 cpu 0x0622 (offset 0x0622) */
void p00_mmu_set_bankA_4(void) {
  /* CURATED -> mmu_set_bank_a */
  mmu_set_bank_a(a);
}

/* flash page 0 cpu 0x0630 (offset 0x0630) */
void p00_mmu_set_bankA(void) {
  /* CURATED -> mmu_set_bank_a */
  mmu_set_bank_a(a);
}

/* flash page 0 cpu 0x0633 (offset 0x0633) */
void p00_L_0633(void) {
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 7)));
  set_hl(0x859A);
  cpu_cp_hl();
  if (flag_nz()) goto lab_p00_L_064E;
  flag_cmp(a, 0x44);
  if (flag_nz()) { p00_L_0647(); return; }
  cpu_push_bc();
  p00_L_3F4B();
  cpu_pop_bc();
  p00_L_0646();
  return;
  lab_p00_L_064E: ;
  cpu_push_bc();
  cpu_push_af();
  cpu_pop_af();
  flag_cmp(a, 0x3F);
  if (flag_nz()) { p00_L_065B(); return; }
  a = 0x40;
  cpu_push_af();
  a = 0;
  flag_logic(a);
  goto lab_p00_L_0664;
  lab_p00_L_0664: ;
  p00_L_3F51();
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_af();
  p00_L_066A();
  return;
}

/* flash page 0 cpu 0x0643 (offset 0x0643) */
void p00_L_0643(void) {
  c = e;
  /* ccf */
  cpu_pop_bc();
  p00_L_0646();
  return;
}

/* flash page 0 cpu 0x0646 (offset 0x0646) */
void p00_L_0646(void) {
  return;
}

/* flash page 0 cpu 0x0647 (offset 0x0647) */
void p00_L_0647(void) {
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p00_L_064E;
  b = 0x27;
  return;
  lab_p00_L_064E: ;
  cpu_push_bc();
  cpu_push_af();
  cpu_pop_af();
  flag_cmp(a, 0x3F);
  if (flag_nz()) { p00_L_065B(); return; }
  a = 0x40;
  cpu_push_af();
  a = 0;
  flag_logic(a);
  goto lab_p00_L_0664;
  lab_p00_L_0664: ;
  p00_L_3F51();
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_af();
  p00_L_066A();
  return;
}

/* flash page 0 cpu 0x0652 (offset 0x0652) */
void p00_L_0652(void) {
  /* ccf */
  if (flag_nz()) { p00_L_065B(); return; }
  a = 0x40;
  cpu_push_af();
  a = 0;
  flag_logic(a);
  goto lab_p00_L_0664;
  lab_p00_L_0664: ;
  p00_L_3F51();
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_af();
  p00_L_066A();
  return;
}

/* flash page 0 cpu 0x065B (offset 0x065B) */
void p00_L_065B(void) {
  cpu_push_af();
  a = (uint8_t)(a - 0x40);
  if (flag_nz()) goto lab_p00_L_0664;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 6)));
  lab_p00_L_0664: ;
  p00_L_3F51();
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_af();
  p00_L_066A();
  return;
}

/* flash page 0 cpu 0x066A (offset 0x066A) */
void p00_L_066A(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  p00_L_0745();
  cpu_pop_af();
  cpu_push_af();
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x47);
  a = b;
  if (flag_z()) goto lab_p00_L_068E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_068E;
  flag_cmp(a, 0x57);
  if (flag_z()) goto lab_p00_L_069E;
  flag_cmp(a, 0x45);
  if (flag_z()) goto lab_p00_L_069E;
  flag_cmp(a, 0x4B);
  if (flag_z()) goto lab_p00_L_069E;
  lab_p00_L_068E: ;
  p00_L_3F57();
  flag_cmp(a, 0x52);
  if (flag_z()) goto lab_p00_L_069E;
  p00_L_0753();
  p00_L_07DE();
  if (flag_z()) p00_L_0BB1();
  lab_p00_L_069E: ;
  a = mem_read8(0x859A);
  cpu_pop_bc();
  cpu_push_af();
  cpu_push_bc();
  flag_cmp(a, 0x52);
  if (flag_nz()) goto lab_p00_L_06B4;
  p00_L_3F5D();
  p00_L_073D();
  p00_L_07DE();
  if (flag_z()) p00_L_0BB1();
  lab_p00_L_06B4: ;
  set_hl(0x858D);
  set_de(0x859B);
  set_bc(0x000E);
  while (bc() != 0) { cpu_ldi(); }
  a = mem_read8(0x89FD);
  mem_write8(de(), a);
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x4A);
  if (flag_nz()) goto lab_p00_L_06CE;
  p00_L_3F63();
  goto lab_p00_L_0707;
  lab_p00_L_06CE: ;
  flag_cmp(a, 0x44);
  if (flag_z()) p00_L_3F63();
  if (flag_z()) goto lab_p00_L_06DF;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  goto lab_p00_L_0707;
  lab_p00_L_06DF: ;
  p00_L_17DB();
  p00_L_17CE();
  if (flag_z()) goto lab_p00_L_0707;
  a = mem_read8(0x859A);
  p00_L_3F69();
  if (flag_nz()) goto lab_p00_L_0707;
  a = 0x40;
  mem_write8(0x859A, a);
  set_hl(0x3F6F);
  a = mem_read8((uint16_t)(iy + 0x12));
  cpu_push_af();
  a = 0x40;
  p00_L_071D();
  p00_L_073A();
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x12), a);
  lab_p00_L_0707: ;
  cpu_pop_af();
  cpu_pop_bc();
  flag_cmp(a, 0x46);
  if (flag_nz()) goto lab_p00_L_0718;
  cpu_push_af();
  a = b;
  flag_cmp(a, 0x52);
  if (flag_z()) goto lab_p00_L_0717;
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 0)));
  lab_p00_L_0717: ;
  cpu_pop_af();
  lab_p00_L_0718: ;
  cpu_pop_hl();
  mem_write8(0x859A, a);
  cpu_pop_af();
  p00_L_071D();
  return;
}

/* flash page 0 cpu 0x071D (offset 0x071D) */
void p00_L_071D(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 2)) == 0);
  if (flag_nz()) p00_L_3F75();
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) | (1u << 5)));
  p00_L_07A1();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 5)));
  cpu_pop_bc();
  return;
}

/* flash page 0 cpu 0x073A (offset 0x073A) */
void p00_L_073A(void) {
  p00_L_0745();
  p00_L_073D();
  return;
}

/* flash page 0 cpu 0x073D (offset 0x073D) */
void p00_L_073D(void) {
  p00_L_0753();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 0)));
  return;
}

/* flash page 0 cpu 0x0745 (offset 0x0745) */
void p00_L_0745(void) {
  goto lab_p00_L_0745;
  lab_p00_L_03A4: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 6)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 7)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 4)));
  return;
  lab_p00_L_0745: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x25)) & (1u << 5)) == 0);
  if (flag_nz()) return;
  cpu_push_hl();
  set_hl(mem_read16(0x858F));
  p00_L_077F();
  goto lab_p00_L_0762;
  lab_p00_L_0762: ;
  cpu_pop_hl();
  goto lab_p00_L_03A4;
}

/* flash page 0 cpu 0x0753 (offset 0x0753) */
void p00_L_0753(void) {
  goto lab_p00_L_0753;
  lab_p00_L_03A4: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 6)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 7)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 4)));
  return;
  lab_p00_L_0753: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x25)) & (1u << 5)) == 0);
  if (flag_nz()) return;
  cpu_push_hl();
  set_hl(mem_read16(0x8591));
  p00_L_077F();
  p00_L_002B();
  cpu_pop_hl();
  goto lab_p00_L_03A4;
}

/* flash page 0 cpu 0x0767 (offset 0x0767) */
void p00_L_0767(void) {
  a = (uint8_t)(a - e);
  a = (uint8_t)(a + l);
  p00_L_077F();
  return;
}

/* flash page 0 cpu 0x0777 (offset 0x0777) */
void p00_L_0777(void) {
  p00_L_077F();
  cpu_pop_af();
  return;
}

/* flash page 0 cpu 0x077F (offset 0x077F) */
void p00_L_077F(void) {
  a = hw_in(PORT_MMU_A);
  cpu_push_af();
  a = mem_read8(0x8599);
  p00_mmu_set_bankA();
  p00_L_07A1();
  cpu_pop_af();
  p00_mmu_set_bankA();
  return;
}

/* flash page 0 cpu 0x0790 (offset 0x0790) */
void p00_L_0790(void) {
  cpu_push_hl();
  set_hl(mem_read16(0x858D));
  cpu_push_af();
  a = mem_read8(0x8599);
  p00_mmu_set_bankA();
  cpu_pop_af();
  p00_L_07A1();
  cpu_pop_hl();
  return;
}

/* flash page 0 cpu 0x07A1 (offset 0x07A1) */
void p00_L_07A1(void) {
  os_jp_hl();
  return;
}

/* flash page 0 cpu 0x07DE (offset 0x07DE) */
void p00_L_07DE(void) {
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x58);
  a = b;
  return;
}

/* flash page 0 cpu 0x07E6 (offset 0x07E6) */
void p00_L_07E6(void) {
  goto lab_p00_L_07E6;
  lab_p00_L_0080: ;
  hw_out(PORT_INTMASK, a);
  cpu_ex_af();
  cpu_exx();
  /* ei */
  return;
  lab_p00_L_03C5: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p00_L_3EFD();
  p00_L_3F03();
  lab_p00_L_03CF: ;
  p00_L_3F09();
  p00_L_3F0F();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 7)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x1F)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0408;
  /* di */
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 5)));
  set_hl(0x0403);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  a = mem_read8(0x859A);
  flag_cmp(a, 0x52);
  if (flag_nz()) goto lab_p00_L_03FD;
  a = mem_read8(0x86DD);
  p00_L_3F15();
  goto lab_p00_L_0400;
  lab_p00_L_03FD: ;
  p00_L_3F1B();
  lab_p00_L_0400: ;
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  /* ei */
  lab_p00_L_0408: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8444, a);
  mem_write8(0x8446, a);
  p00_L_3F21();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 1)));
  mem_write8(0x8444, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_0433;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 3)) == 0);
  if (flag_z()) p00_L_3F27();
  a = mem_read8(0x8444);
  goto lab_p00_L_0436;
  lab_p00_L_0433: ;
  p00_L_3EFD();
  lab_p00_L_0436: ;
  p00_L_3F2D();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_044D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_0448;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  goto lab_p00_L_04B2;
  lab_p00_L_0448: ;
  a = 0x05;
  goto lab_p00_L_0515;
  lab_p00_L_044D: ;
  flag_cmp(a, 0xB4);
  if (flag_nz()) goto lab_p00_L_0470;
  a = 0xCC;
  p00_L_0198();
  if (flag_nz()) goto lab_p00_L_046D;
  a = 0xAD;
  p00_L_045A();
  return;
  lab_p00_L_046D: ;
  mem_write8(0x8444, a);
  lab_p00_L_0470: ;
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  p00_L_3F33();
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p00_L_04B2;
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0491;
  cpu_push_af();
  goto lab_p00_L_053E;
  lab_p00_L_0491: ;
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p00_L_04A2;
  p00_L_3F39();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_3F3F();
  if (flag_c()) goto lab_p00_L_04B2;
  p00_L_07DE();
  lab_p00_L_04A2: ;
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x28);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0x29);
  if (flag_z()) goto lab_p00_L_0515;
  goto lab_p00_L_04D0;
  lab_p00_L_04AE: ;
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_04BA;
  lab_p00_L_04B2: ;
  goto lab_p00_L_03C5;
  lab_p00_L_04B5: ;
  b = 0x08;
  set_hl(0x84BE);
  lab_p00_L_04BA: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04B2;
  cpu_push_bc();
  cpu_push_hl();
  d = 0x00;
  e = a;
  p00_L_3F45();
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  goto lab_p00_L_04AE;
  lab_p00_L_04D0: ;
  flag_cmp(a, 0x7F);
  if (flag_c()) goto lab_p00_L_0595;
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p00_L_0515;
  flag_cmp(a, 0xFB);
  if (flag_nz()) goto lab_p00_L_04FA;
  a = mem_read8(0x8446);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_04F7;
  flag_cmp(a, 0x0D);
  if (flag_c()) goto lab_p00_L_04F3;
  flag_cmp(a, 0x8C);
  if (flag_c()) goto lab_p00_L_0549;
  flag_cmp(a, 0xA6);
  if (flag_nc()) goto lab_p00_L_0549;
  lab_p00_L_04F3: ;
  a = 0xFB;
  goto lab_p00_L_0515;
  lab_p00_L_04F7: ;
  a = mem_read8(0x8444);
  lab_p00_L_04FA: ;
  flag_cmp(a, 0xEF);
  if (flag_nz()) goto lab_p00_L_0502;
  a = 0xA6;
  goto lab_p00_L_0510;
  lab_p00_L_0502: ;
  flag_cmp(a, 0xF9);
  if (flag_c()) goto lab_p00_L_050A;
  a = (uint8_t)(a - 0x14);
  goto lab_p00_L_0510;
  lab_p00_L_050A: ;
  flag_cmp(a, 0xF3);
  if (flag_c()) goto lab_p00_L_0515;
  a = (uint8_t)(a - 0x7C);
  lab_p00_L_0510: ;
  mem_write8(0x8446, a);
  a = 0xFE;
  lab_p00_L_0515: ;
  flag_cmp(a, 0x69);
  if (flag_nz()) goto lab_p00_L_051D;
  a = 0xFC;
  goto lab_p00_L_0510;
  lab_p00_L_051D: ;
  flag_cmp(a, 0x5B);
  if (flag_nz()) goto lab_p00_L_0525;
  a = 0xFD;
  goto lab_p00_L_0510;
  lab_p00_L_0525: ;
  flag_cmp(a, 0x28);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_0532;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 7)));
  a = 0xDA;
  goto lab_p00_L_053E;
  lab_p00_L_0532: ;
  cpu_pop_af();
  flag_cmp(a, 0x29);
  cpu_push_af();
  if (flag_nz()) goto lab_p00_L_053E;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 1)));
  a = 0x7F;
  lab_p00_L_053E: ;
  p00_L_0790();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  cpu_pop_af();
  if (flag_z()) goto lab_p00_L_04B5;
  lab_p00_L_0549: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p00_L_058E;
  set_de(mem_read16(0x86D9));
  set_hl(mem_read16(0x96F6));
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0560;
  set_hl(mem_read16(0x86DB));
  cpu_ex_de_hl();
  lab_p00_L_0560: ;
  p00_L_192A();
  if (flag_nc()) goto lab_p00_L_0580;
  a = mem_read8(hl());
  p00_L_172F();
  d = 0x00;
  e = a;
  if (flag_nz()) goto lab_p00_L_0571;
  d = a;
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  lab_p00_L_0571: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_057B;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x86D9, hl());
  lab_p00_L_057B: ;
  p00_L_3F45();
  lab_p00_L_057E: ;
  goto lab_p00_L_0515;
  lab_p00_L_0580: ;
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 7)));
  set_hl(0x89F5);
  a = mem_read8(0x85C2);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 4)));
  /* or (hl) */
  mem_write8(hl(), a);
  lab_p00_L_058E: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 2)));
  goto lab_p00_L_03CF;
  lab_p00_L_0595: ;
  flag_cmp(a, 0x27);
  if (flag_c()) goto lab_p00_L_057E;
  flag_cmp(a, 0x5A);
  if (flag_c()) goto lab_p00_L_05C2;
  flag_cmp(a, 0x75);
  if (flag_nc()) goto lab_p00_L_05BC;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_057E;
  flag_cmp(a, 0x69);
  if (flag_c()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x6D);
  if (flag_z()) goto lab_p00_L_05BC;
  flag_cmp(a, 0x69);
  if (flag_z()) goto lab_p00_L_057E;
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x44);
  a = b;
  if (flag_nz()) goto lab_p00_L_057E;
  lab_p00_L_05BC: ;
  b = a;
  a = 0x44;
  goto lab_p00_L_05D0;
  lab_p00_L_05C2: ;
  b = a;
  flag_cmp(a, 0x59);
  if (flag_nz()) goto lab_p00_L_05D0;
  a = mem_read8(0x8446);
  a = (uint8_t)(a + b);
  flag_cmp(a, 0x5B);
  if (flag_nc()) goto lab_p00_L_05F1;
  b = a;
  lab_p00_L_05D0: ;
  c = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x50);
  if (flag_nz()) goto lab_p00_L_05E1;
  a = b;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p00_L_05F1;
  a = 0x50;
  goto lab_p00_L_05EA;
  lab_p00_L_05E1: ;
  flag_cmp(a, 0x52);
  a = c;
  if (flag_nz()) goto lab_p00_L_05EA;
  flag_cmp(a, 0x40);
  if (flag_nz()) goto lab_p00_L_058E;
  lab_p00_L_05EA: ;
  p00_L_0633();
  a = b;
  goto lab_p00_L_0525;
  lab_p00_L_05F1: ;
  a = 0;
  flag_logic(a);
  b = a;
  sp = mem_read16(0x85BC);
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 6)));
  p00_L_0BB1();
  a = 0x40;
  p00_L_0633();
  a = b;
  flag_cmp(a, 0xDA);
  if (flag_nz()) goto lab_p00_L_060D;
  a = 0x28;
  lab_p00_L_060A: ;
  goto lab_p00_L_0515;
  lab_p00_L_060D: ;
  flag_cmp(a, 0x7F);
  if (flag_nz()) goto lab_p00_L_060A;
  a = 0x29;
  goto lab_p00_L_060A;
  lab_p00_L_07E6: ;
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_07F2;
  a = hw_in(PORT_SE_STATUS);
  e = a;
  a = 0;
  flag_logic(a);
  hw_out(PORT_SE_STATUS, a);
  lab_p00_L_07F2: ;
  b = 0x00;
  lab_p00_L_07F4: ;
  set_hl(0x1016);
  lab_p00_L_07F7: ;
  a = hw_in(PORT_INTACK);
  a = a & 0x08;
  flag_logic(a);
  flag_cmp(a, b);
  b = a;
  if (flag_nz()) goto lab_p00_L_07F4;
  set_hl((uint16_t)(hl() - 1));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_07F7;
  flag_cmp(a, b);
  if (flag_z()) goto lab_p00_L_0834;
  a = hw_in(PORT_MMU_B);
  b = a;
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0818;
  a = e;
  hw_out(PORT_SE_STATUS, a);
  a = b;
  flag_cmp(a, 0x81);
  goto lab_p00_L_081D;
  lab_p00_L_0818: ;
  a = b;
  a = a & 0x4F;
  flag_logic(a);
  flag_cmp(a, 0x41);
  lab_p00_L_081D: ;
  if (flag_nz()) goto lab_p00_L_0A9B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 3)) == 0);
  if (flag_nz()) return;
  cpu_pop_hl();
  a = 0;
  flag_logic(a);
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  a = 0x11;
  goto lab_p00_L_0080;
  lab_p00_L_0834: ;
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_083D;
  a = e;
  hw_out(PORT_SE_STATUS, a);
  lab_p00_L_083D: ;
  a = 0x76;
  hw_out(PORT_INTACK, a);
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_084D;
  a = hw_in(PORT_MMU_B);
  flag_cmp(a, 0x81);
  goto lab_p00_L_0853;
  lab_p00_L_084D: ;
  a = hw_in(PORT_MMU_B);
  a = a & 0x4F;
  flag_logic(a);
  flag_cmp(a, 0x41);
  lab_p00_L_0853: ;
  if (flag_nz()) goto lab_p00_L_0952;
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p00_L_08E4;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p00_L_0869;
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p00_L_086E;
  lab_p00_L_0869: ;
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) | (1u << 3)));
  return;
  lab_p00_L_086E: ;
  a = 0x08;
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  p00_lcd_write_cmd();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_0887;
  flag_set_z((mem_read8((uint16_t)(iy + 0x08)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_08C6;
  lab_p00_L_0887: ;
  p00_L_0BB1();
  p00_L_0B76();
  p00_L_3E79();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) | (1u << 4)));
  set_hl(0x9D8D);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  p00_L_0A59();
  set_hl(0x9D8D);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 4)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3E7F();
  p00_L_3E85();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  p00_lcd_write_cmd();
  set_hl(0x89F9);
  flag_set_z((mem_read8(hl()) & (1u << 2)) == 0);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 2)));
  if (flag_nz()) p00_L_3E8B();
  p00_L_0A3A();
  mem_write16(0x85BE, hl());
  lab_p00_L_08C6: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 5)));
  a = 0x36;
  hw_out(PORT_INTACK, a);
  a = 0x11;
  hw_out(PORT_INTMASK, a);
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 3)));
  cpu_ex_af();
  cpu_exx();
  /* ei */
  lab_p00_L_08E1: ;
  halt();
  goto lab_p00_L_08E1;
  lab_p00_L_08E4: ;
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) & ~(1u << 7)));
  p00_L_02AD();
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p00_L_094D;
  lab_p00_L_08F1: ;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 3)));
  set_hl(0x89F8);
  flag_set_z((mem_read8(hl()) & (1u << 4)) == 0);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 4)));
  if (flag_nz()) goto lab_p00_L_092C;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 1)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_090D;
  flag_set_z((mem_read8(hl()) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p00_L_09CA;
  lab_p00_L_090D: ;
  sp = mem_read16(0x85BC);
  p00_L_3E91();
  a = 0;
  flag_logic(a);
  mem_write8(0x85DE, a);
  p00_L_0B2A();
  p00_L_0ADA();
  p00_L_3E97();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_3E9D();
  /* ei */
  goto lab_p00_L_03CF;
  lab_p00_L_092C: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3EA3();
  a = 0x08;
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  p00_L_3EA9();
  cpu_pop_de();
  cpu_pop_de();
  cpu_pop_de();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 3)));
  p00_L_0ADA();
  cpu_ex_af();
  cpu_exx();
  /* ei */
  return;
  lab_p00_L_094D: ;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 4)));
  return;
  lab_p00_L_0952: ;
  a = 0x76;
  hw_out(PORT_INTACK, a);
  a = 0xC0;
  link_out(a); /* stub */
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  a = 0x41;
  if (flag_z()) goto lab_p00_L_096B;
  a = 0x01;
  hw_out(PORT_SE_STATUS, a);
  a = 0;
  flag_logic(a);
  hw_out(0x0F, a);
  a = 0x81;
  lab_p00_L_096B: ;
  mmu_set_bank_b(a);
  a = 0;
  flag_logic(a);
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  iy = 0x89F0;
  p00_L_24A9();
  if (flag_z()) p00_L_3EAF();
  set_hl(mem_read16(0x85BE));
  set_de(0xA55A);
  p00_L_192A();
  if (flag_z()) goto lab_p00_L_0B38;
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_09A0;
  b = 0x00;
  os_bcall(0x80BA);
  flag_set_z((b & (1u << 0)) == 0);
  a = 0x1F;
  if (flag_z()) goto lab_p00_L_09A2;
  a = 0x1C;
  goto lab_p00_L_09A2;
  lab_p00_L_09A0: ;
  a = 0x17;
  lab_p00_L_09A2: ;
  mem_write8(0x8447, a);
  p00_L_0A3A();
  set_de(mem_read16(0x85BE));
  p00_L_192A();
  if (flag_nz()) goto lab_p00_L_09CA;
  set_de((uint16_t)(de() - 1));
  mem_write16(0x85BE, de());
  p00_L_3EB5();
  p00_L_0B76();
  a = 0x0B;
  hw_out(PORT_INTMASK, a);
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 4)));
  p00_L_0A59();
  goto lab_p00_L_08F1;
  lab_p00_L_09CA: ;
  /* di */
  set_hl(0x8000);
  set_de(0x8001);
  set_bc(0x7FFF);
  mem_write8(hl(), 0x00);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(0x0109);
  mem_write16(0x9B73, hl());
  a = 0xC0;
  link_out(a); /* stub */
  sp = 0xFFF7;
  p00_L_3EBB();
  set_hl(0x07AD);
  p00_L_25A2();
  mem_write16(0x85BC, sp);
  p00_L_3EC1();
  goto lab_p00_L_3EC7;
  lab_p00_L_0A9B: ;
  a = 0x37;
  hw_out(PORT_INTACK, a);
  a = 0;
  flag_logic(a);
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  a = 0x11;
  hw_out(PORT_INTMASK, a);
  /* ei */
  halt();
  p00_lcd_busy_wait();
  return;
  lab_p00_L_0B38: ;
  set_hl(0x0000);
  mem_write16(0x85BE, hl());
  sp = mem_read16(0x85BC);
  iy = 0x89F0;
  p00_L_3EE5();
  p00_L_0B76();
  p00_L_0A59();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 4)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_3E9D();
  a = 0x0B;
  hw_out(PORT_INTMASK, a);
  p00_L_3EEB();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 3)));
  p00_L_0AF8();
  if (flag_z()) p00_L_0AEF();
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3EA3();
  /* ei */
  goto lab_p00_L_03CF;
  lab_p00_L_3EC7: ;
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x43E7);
  return; /* banked jump */
}

/* flash page 0 cpu 0x0A3A (offset 0x0A3A) */
void p00_L_0A3A(void) {
  cpu_push16(ix);
  ix = 0x9D95;
  set_bc(0x60DB);
  set_hl(0x0011);
  d = h;
  lab_p00_L_0A47: ;
  e = mem_read8(ix);
  ix = (uint16_t)(ix + 1);
  set_hl((uint16_t)(hl() + de()));
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_0A47;
  e = d;
  cpu_ex_de_hl();
  cpu_sbc_hl_de();
  ix = cpu_pop16();
  return;
}

/* flash page 0 cpu 0x0A59 (offset 0x0A59) */
void p00_L_0A59(void) {
  p00_L_03A0();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  p00_L_3ED3();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 6)));
  a = 0x40;
  p00_L_0633();
  return;
}

/* flash page 0 cpu 0x0A6C (offset 0x0A6C) */
void p00_L_0A6C(void) {
  p00_L_0B8D();
  a = 0x77;
  hw_out(PORT_INTACK, a);
  b = 0x00;
  sp = 0xFDFA;
  lab_p00_L_0A78: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0A78;
  ix = 0x0001;
  cpu_add_ix_sp();
  sp = ix;
  if (flag_nc()) goto lab_p00_L_0A78;
  sp = 0xFFC5;
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0A91;
  a = 0x01;
  hw_out(PORT_SE_STATUS, a);
  lab_p00_L_0A91: ;
  a = 0x77;
  hw_out(PORT_INTACK, a);
  /* im 1 */
  a = 0xC0;
  link_out(a); /* stub */
  a = 0x37;
  hw_out(PORT_INTACK, a);
  a = 0;
  flag_logic(a);
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  a = 0x11;
  hw_out(PORT_INTMASK, a);
  /* ei */
  halt();
  p00_lcd_busy_wait();
  return;
}

/* flash page 0 cpu 0x0AAE (offset 0x0AAE) */
void p00_lcd_busy_wait(void) {
  /* CURATED -> lcd_busy_wait */
  lcd_busy_wait();
}

/* flash page 0 cpu 0x0AB7 (offset 0x0AB7) */
void p00_lcd_write_cmd(void) {
  /* CURATED -> lcd_write_cmd */
  lcd_write_cmd();
}

/* flash page 0 cpu 0x0AC4 (offset 0x0AC4) */
void p00_L_0AC4(void) {
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() - 1));
  cpu_pop_af();
  return;
}

/* flash page 0 cpu 0x0AC9 (offset 0x0AC9) */
void p00_L_0AC9(void) {
  a = 0xFF;
  p00_L_0ACB();
  return;
}

/* flash page 0 cpu 0x0ACB (offset 0x0ACB) */
void p00_L_0ACB(void) {
  cpu_push_af();
  p00_L_0B93();
  cpu_pop_af();
  lab_p00_L_0AD0: ;
  p00_L_0AC4();
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p00_L_0AD0;
  p00_L_0BA2();
  return;
}

/* flash page 0 cpu 0x0ADA (offset 0x0ADA) */
void p00_L_0ADA(void) {
  goto lab_p00_L_0ADA;
  lab_p00_L_08C6: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 5)));
  a = 0x36;
  hw_out(PORT_INTACK, a);
  a = 0x11;
  hw_out(PORT_INTMASK, a);
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 3)));
  cpu_ex_af();
  cpu_exx();
  /* ei */
  lab_p00_L_08E1: ;
  halt();
  goto lab_p00_L_08E1;
  lab_p00_L_0ADA: ;
  a = 0x0B;
  hw_out(PORT_INTMASK, a);
  p00_L_3EEB();
  p00_L_0AF8();
  if (flag_nz()) return;
  p00_L_0B2A();
  a = hw_in(PORT_STATUS);
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) goto lab_p00_L_08C6;
  p00_L_0AEF();
  return;
}

/* flash page 0 cpu 0x0AEF (offset 0x0AEF) */
void p00_L_0AEF(void) {
  p00_L_3ED9();
  p00_L_0A59();
  goto lab_p00_L_3EDF;
  lab_p00_L_3EDF: ;
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x437E);
  return; /* banked jump */
}

/* flash page 0 cpu 0x0AF8 (offset 0x0AF8) */
void p00_L_0AF8(void) {
  p00_L_0B2A();
  a = 0x76;
  hw_out(PORT_INTACK, a);
  a = 0xF6;
  hw_out(PORT_INTACK, a);
  b = 0x05;
  lab_p00_L_0B05: ;
  p00_L_0AC9();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0B05;
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) | (1u << 5)));
  a = hw_in(PORT_STATUS);
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_0B18;
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 5)));
  lab_p00_L_0B18: ;
  a = 0x76;
  hw_out(PORT_INTACK, a);
  a = 0x0A;
  p00_L_0ACB();
  a = 0x76;
  hw_out(PORT_INTACK, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 5)) == 0);
  return;
}

/* flash page 0 cpu 0x0B2A (offset 0x0B2A) */
void p00_L_0B2A(void) {
  set_bc(0x2710);
  set_hl(0x8000);
  lab_p00_L_0B30: ;
  a = mem_read8(hl());
  mem_write8(hl(), a);
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_0B30;
  return;
}

/* flash page 0 cpu 0x0B76 (offset 0x0B76) */
void p00_L_0B76(void) {
  p00_L_0B86();
  if (flag_z()) goto lab_p00_L_0B82;
  a = 0;
  flag_logic(a);
  mem_write8(0x85DE, a);
  p00_L_3EF1();
  lab_p00_L_0B82: ;
  p00_L_3EF7();
  return;
}

/* flash page 0 cpu 0x0B86 (offset 0x0B86) */
void p00_L_0B86(void) {
  b = a;
  a = mem_read8(0x85DE);
  a = a | a;
  flag_logic(a);
  a = b;
  return;
}

/* flash page 0 cpu 0x0B8D (offset 0x0B8D) */
void p00_L_0B8D(void) {
  p00_L_24A9();
  if (flag_nz()) return;
  goto lab_p00_L_0B9C;
  lab_p00_L_0B9C: ;
  cpu_push_af();
  a = 0;
  flag_logic(a);
  hw_out(PORT_SE_STATUS, a);
  cpu_pop_af();
  return;
}

/* flash page 0 cpu 0x0B93 (offset 0x0B93) */
void p00_L_0B93(void) {
  p00_L_24A9();
  if (flag_nz()) return;
  a = hw_in(PORT_SE_STATUS);
  mem_write8(0x9C21, a);
  cpu_push_af();
  a = 0;
  flag_logic(a);
  hw_out(PORT_SE_STATUS, a);
  cpu_pop_af();
  return;
}

/* flash page 0 cpu 0x0BA2 (offset 0x0BA2) */
void p00_L_0BA2(void) {
  p00_L_24A9();
  if (flag_nz()) return;
  a = mem_read8(0x9C21);
  a = a & 0x01;
  flag_logic(a);
  hw_out(PORT_SE_STATUS, a);
  return;
}

/* flash page 0 cpu 0x0BB1 (offset 0x0BB1) */
void p00_L_0BB1(void) {
  cpu_push_af();
  p00_L_24A9();
  if (flag_nz()) goto lab_p00_L_0BBB;
  a = 0x01;
  hw_out(PORT_SE_STATUS, a);
  lab_p00_L_0BBB: ;
  cpu_pop_af();
  return;
}

/* flash page 0 cpu 0x0BD1 (offset 0x0BD1) */
void p00_L_0BD1(void) {
  p00_L_1100();
  p00_L_10E6();
  goto lab_p00_L_107E;
  lab_p00_L_107E: ;
  a = mem_read8(0x847A);
  a = a | a;
  flag_logic(a);
  if (flag_z()) p00_L_1295();
  a = mem_read8(0x8485);
  a = a | a;
  flag_logic(a);
  if (flag_z()) p00_L_129A();
  a = mem_read8(0x8478);
  a = a | a;
  flag_logic(a);
  a = mem_read8(0x8483);
  if (flag_m()) goto lab_p00_L_10B0;
  a = a & 0x80;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_10C3;
  p00_L_1700();
  set_hl(0x8485);
  set_de(0x847A);
  lab_p00_L_10A3: ;
  if (flag_nz()) goto lab_p00_L_10C3;
  b = 0x07;
  lab_p00_L_10A7: ;
  a = mem_read8(de());
  cpu_cp_hl();
  if (flag_nz()) return;
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_10A7;
  goto lab_p00_L_10C3;
  lab_p00_L_10B0: ;
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_10C1;
  set_hl(0x8479);
  a = mem_read8(0x8484);
  /* sub (hl) */
  set_hl((uint16_t)(hl() + 1));
  set_de(0x8485);
  goto lab_p00_L_10A3;
  lab_p00_L_10C1: ;
  a = (uint8_t)(a - 0x01);
  lab_p00_L_10C3: ;
  cpu_push_af();
  a = mem_read8(0x8479);
  a = a | a;
  flag_logic(a);
  if (flag_z()) p00_L_128A();
  a = mem_read8(0x8484);
  a = a | a;
  flag_logic(a);
  if (flag_z()) p00_L_1287();
  cpu_pop_af();
  return;
}

/* flash page 0 cpu 0x0C0F (offset 0x0C0F) */
void p00_L_0C0F(void) {
  p00_rst08();
  p00_L_0E72();
  p00_L_0E4C();
  goto lab_p00_L_0C34;
  lab_p00_L_0C34: ;
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 6)));
  p00_L_0FB5();
  goto lab_p00_L_0C41;
  lab_p00_L_0C41: ;
  p00_L_14CC();
  if (flag_z()) return;
  p00_L_14C7();
  if (flag_z()) { p00_L_1179(); return; }
  p00_L_1700();
  if (flag_nc()) goto lab_p00_L_0C8E;
  /* add a,(hl) */
  d = mem_read8(hl());
  e = a;
  a = d;
  mem_write8(0x8479, a);
  a = (uint8_t)(a - e);
  flag_cmp(a, 0x10);
  if (flag_nc()) { p00_L_1179(); return; }
  b = a;
  lab_p00_L_0C5E: ;
  set_hl(0x847A);
  p00_L_12D0();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0C5E;
  a = mem_read8(0x8483);
  a = a & 0x80;
  flag_logic(a);
  c = a;
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  a = a ^ c;
  flag_logic(a);
  a = c;
  mem_write8(0x8478, a);
  if (flag_z()) goto lab_p00_L_0CAD;
  p00_L_1415();
  if (flag_nc()) goto lab_p00_L_0CCF;
  p00_L_1397();
  p00_L_141D();
  a = mem_read8(0x8478);
  a = a ^ 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  goto lab_p00_L_0CD2;
  lab_p00_L_0C8E: ;
  if (flag_z()) goto lab_p00_L_0C9C;
  flag_cmp(a, 0x10);
  if (flag_nc()) return;
  b = a;
  lab_p00_L_0C94: ;
  set_hl(0x8485);
  p00_L_12D0();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0C94;
  lab_p00_L_0C9C: ;
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  c = a;
  a = mem_read8(0x8483);
  a = a & 0x80;
  flag_logic(a);
  a = a ^ c;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_0CC4;
  lab_p00_L_0CAD: ;
  p00_L_139F();
  if (flag_nc()) goto lab_p00_L_0CB8;
  p00_L_12F5();
  p00_L_15F3();
  lab_p00_L_0CB8: ;
  p00_L_0CDF();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p00_L_0D06;
  goto lab_p00_L_0F98;
  lab_p00_L_0CC4: ;
  p00_L_141D();
  if (flag_nc()) goto lab_p00_L_0CD2;
  p00_L_139F();
  p00_L_1415();
  lab_p00_L_0CCF: ;
  p00_L_1179();
  lab_p00_L_0CD2: ;
  p00_L_0CDF();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p00_L_0E07;
  goto lab_p00_L_0F98;
  lab_p00_L_0D06: ;
  goto lab_p00_L_0E2D;
  lab_p00_L_0E07: ;
  set_hl(0x847A);
  a = mem_read8(hl());
  a = a & 0xF0;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_0E2D;
  c = 0x10;
  lab_p00_L_0E11: ;
  c = (uint8_t)(c - 1);
  if (flag_z()) { p00_L_128A(); return; }
  p00_L_1301();
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a & 0xF0;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0E11;
  a = 0x10;
  a = (uint8_t)(a - c);
  c = a;
  a = mem_read8(0x8479);
  a = (uint8_t)(a - c);
  if (flag_c()) { p00_L_128A(); return; }
  mem_write8(0x8479, a);
  lab_p00_L_0E2D: ;
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  set_hl(0x8481);
  a = mem_read8(hl());
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() - 1));
  a = (uint8_t)(a + 0xB0);
  if (flag_nc()) return;
  p00_L_1373();
  if (flag_nc()) return;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x10);
  p00_L_15F3();
  return;
  lab_p00_L_0F98: ;
  c = 0x11;
  lab_p00_L_0F9A: ;
  a = mem_read8(0x847A);
  a = a & 0xF0;
  flag_logic(a);
  if (flag_nz()) return;
  c = (uint8_t)(c - 1);
  if (flag_z()) goto lab_p00_L_0FAC;
  p00_L_1301();
  p00_L_15EB();
  if (flag_nc()) goto lab_p00_L_0F9A;
  return;
  lab_p00_L_0FAC: ;
  p00_L_128A();
  return;
}

/* flash page 0 cpu 0x0C1B (offset 0x0C1B) */
void p00_L_0C1B(void) {
  p00_L_1251();
  goto lab_p00_L_0C34;
  lab_p00_L_0C34: ;
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 6)));
  p00_L_0FB5();
  goto lab_p00_L_0C41;
  lab_p00_L_0C41: ;
  p00_L_14CC();
  if (flag_z()) return;
  p00_L_14C7();
  if (flag_z()) { p00_L_1179(); return; }
  p00_L_1700();
  if (flag_nc()) goto lab_p00_L_0C8E;
  /* add a,(hl) */
  d = mem_read8(hl());
  e = a;
  a = d;
  mem_write8(0x8479, a);
  a = (uint8_t)(a - e);
  flag_cmp(a, 0x10);
  if (flag_nc()) { p00_L_1179(); return; }
  b = a;
  lab_p00_L_0C5E: ;
  set_hl(0x847A);
  p00_L_12D0();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0C5E;
  a = mem_read8(0x8483);
  a = a & 0x80;
  flag_logic(a);
  c = a;
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  a = a ^ c;
  flag_logic(a);
  a = c;
  mem_write8(0x8478, a);
  if (flag_z()) goto lab_p00_L_0CAD;
  p00_L_1415();
  if (flag_nc()) goto lab_p00_L_0CCF;
  p00_L_1397();
  p00_L_141D();
  a = mem_read8(0x8478);
  a = a ^ 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  goto lab_p00_L_0CD2;
  lab_p00_L_0C8E: ;
  if (flag_z()) goto lab_p00_L_0C9C;
  flag_cmp(a, 0x10);
  if (flag_nc()) return;
  b = a;
  lab_p00_L_0C94: ;
  set_hl(0x8485);
  p00_L_12D0();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0C94;
  lab_p00_L_0C9C: ;
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  c = a;
  a = mem_read8(0x8483);
  a = a & 0x80;
  flag_logic(a);
  a = a ^ c;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_0CC4;
  lab_p00_L_0CAD: ;
  p00_L_139F();
  if (flag_nc()) goto lab_p00_L_0CB8;
  p00_L_12F5();
  p00_L_15F3();
  lab_p00_L_0CB8: ;
  p00_L_0CDF();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p00_L_0D06;
  goto lab_p00_L_0F98;
  lab_p00_L_0CC4: ;
  p00_L_141D();
  if (flag_nc()) goto lab_p00_L_0CD2;
  p00_L_139F();
  p00_L_1415();
  lab_p00_L_0CCF: ;
  p00_L_1179();
  lab_p00_L_0CD2: ;
  p00_L_0CDF();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p00_L_0E07;
  goto lab_p00_L_0F98;
  lab_p00_L_0D06: ;
  goto lab_p00_L_0E2D;
  lab_p00_L_0E07: ;
  set_hl(0x847A);
  a = mem_read8(hl());
  a = a & 0xF0;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_0E2D;
  c = 0x10;
  lab_p00_L_0E11: ;
  c = (uint8_t)(c - 1);
  if (flag_z()) { p00_L_128A(); return; }
  p00_L_1301();
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a & 0xF0;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0E11;
  a = 0x10;
  a = (uint8_t)(a - c);
  c = a;
  a = mem_read8(0x8479);
  a = (uint8_t)(a - c);
  if (flag_c()) { p00_L_128A(); return; }
  mem_write8(0x8479, a);
  lab_p00_L_0E2D: ;
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  set_hl(0x8481);
  a = mem_read8(hl());
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() - 1));
  a = (uint8_t)(a + 0xB0);
  if (flag_nc()) return;
  p00_L_1373();
  if (flag_nc()) return;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x10);
  p00_L_15F3();
  return;
  lab_p00_L_0F98: ;
  c = 0x11;
  lab_p00_L_0F9A: ;
  a = mem_read8(0x847A);
  a = a & 0xF0;
  flag_logic(a);
  if (flag_nz()) return;
  c = (uint8_t)(c - 1);
  if (flag_z()) goto lab_p00_L_0FAC;
  p00_L_1301();
  p00_L_15EB();
  if (flag_nc()) goto lab_p00_L_0F9A;
  return;
  lab_p00_L_0FAC: ;
  p00_L_128A();
  return;
}

/* flash page 0 cpu 0x0CDF (offset 0x0CDF) */
void p00_L_0CDF(void) {
  set_hl(0x847A);
  b = 0x06;
  p00_L_1525();
  if (flag_nz()) return;
  a = mem_read8(hl());
  flag_cmp(a, 0x10);
  if (flag_nc()) return;
  a = 0;
  flag_logic(a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  p00_L_128A();
  return;
}

/* flash page 0 cpu 0x0CF2 (offset 0x0CF2) */
void p00_L_0CF2(void) {
  a = 0x05;
  goto lab_p00_L_0CF7;
  lab_p00_L_0CF7: ;
  p00_L_1531();
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 6)));
  goto lab_p00_L_0D26;
  lab_p00_L_0D26: ;
  p00_L_14C7();
  if (flag_z()) return;
  p00_L_14CC();
  if (flag_z()) { p00_L_1179(); return; }
  p00_L_0E9E();
  a = d;
  mem_write8(0x8479, a);
  p00_L_129F();
  b = 0x08;
  set_hl(0x848D);
  lab_p00_L_0D3F: ;
  set_hl((uint16_t)(hl() - 1));
  cpu_cp_hl();
  if (flag_nz()) goto lab_p00_L_0D4F;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0D3F;
  lab_p00_L_0D45: ;
  set_hl(0x848F);
  p00_L_12D0();
  /* rrd */
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  lab_p00_L_0D4F: ;
  cpu_push_hl();
  cpu_push_bc();
  a = mem_read8(hl());
  c = a;
  a = a & 0x0F;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0D96;
  b = a;
  lab_p00_L_0D58: ;
  set_de(0x8497);
  set_hl(mem_read16(0x8480));
  a = mem_read8(de());
  a = (uint8_t)(a + h);
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847E));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847C));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847A));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  if (flag_nc()) goto lab_p00_L_0D94;
  set_de((uint16_t)(de() - 1));
  cpu_ex_de_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p00_L_0D94: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0D58;
  lab_p00_L_0D96: ;
  set_hl(0x848F);
  p00_L_12D0();
  /* rrd */
  a = c;
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  a = a & 0x0F;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0DE6;
  b = a;
  lab_p00_L_0DA8: ;
  set_de(0x8497);
  set_hl(mem_read16(0x8480));
  a = mem_read8(de());
  a = (uint8_t)(a + h);
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847E));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847C));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847A));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  if (flag_nc()) goto lab_p00_L_0DE4;
  set_de((uint16_t)(de() - 1));
  cpu_ex_de_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p00_L_0DE4: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0DA8;
  lab_p00_L_0DE6: ;
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p00_L_0D45;
  cpu_pop_hl();
  a = mem_read8(0x848F);
  a = a & a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0DFD;
  set_hl(0x848F);
  p00_L_12D0();
  /* rrd */
  p00_L_15F3();
  lab_p00_L_0DFD: ;
  p00_L_11CB();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 6)) == 0);
  if (flag_nz()) return;
  goto lab_p00_L_0E2D;
  lab_p00_L_0E2D: ;
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  set_hl(0x8481);
  a = mem_read8(hl());
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() - 1));
  a = (uint8_t)(a + 0xB0);
  if (flag_nc()) return;
  p00_L_1373();
  if (flag_nc()) return;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x10);
  p00_L_15F3();
  return;
}

/* flash page 0 cpu 0x0CF6 (offset 0x0CF6) */
void p00_L_0CF6(void) {
  a = 0;
  flag_logic(a);
  p00_L_1531();
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 6)));
  goto lab_p00_L_0D26;
  lab_p00_L_0D26: ;
  p00_L_14C7();
  if (flag_z()) return;
  p00_L_14CC();
  if (flag_z()) { p00_L_1179(); return; }
  p00_L_0E9E();
  a = d;
  mem_write8(0x8479, a);
  p00_L_129F();
  b = 0x08;
  set_hl(0x848D);
  lab_p00_L_0D3F: ;
  set_hl((uint16_t)(hl() - 1));
  cpu_cp_hl();
  if (flag_nz()) goto lab_p00_L_0D4F;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0D3F;
  lab_p00_L_0D45: ;
  set_hl(0x848F);
  p00_L_12D0();
  /* rrd */
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  lab_p00_L_0D4F: ;
  cpu_push_hl();
  cpu_push_bc();
  a = mem_read8(hl());
  c = a;
  a = a & 0x0F;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0D96;
  b = a;
  lab_p00_L_0D58: ;
  set_de(0x8497);
  set_hl(mem_read16(0x8480));
  a = mem_read8(de());
  a = (uint8_t)(a + h);
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847E));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847C));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847A));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  if (flag_nc()) goto lab_p00_L_0D94;
  set_de((uint16_t)(de() - 1));
  cpu_ex_de_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p00_L_0D94: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0D58;
  lab_p00_L_0D96: ;
  set_hl(0x848F);
  p00_L_12D0();
  /* rrd */
  a = c;
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  a = a & 0x0F;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0DE6;
  b = a;
  lab_p00_L_0DA8: ;
  set_de(0x8497);
  set_hl(mem_read16(0x8480));
  a = mem_read8(de());
  a = (uint8_t)(a + h);
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847E));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847C));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847A));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  if (flag_nc()) goto lab_p00_L_0DE4;
  set_de((uint16_t)(de() - 1));
  cpu_ex_de_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p00_L_0DE4: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0DA8;
  lab_p00_L_0DE6: ;
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p00_L_0D45;
  cpu_pop_hl();
  a = mem_read8(0x848F);
  a = a & a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0DFD;
  set_hl(0x848F);
  p00_L_12D0();
  /* rrd */
  p00_L_15F3();
  lab_p00_L_0DFD: ;
  p00_L_11CB();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 6)) == 0);
  if (flag_nz()) return;
  goto lab_p00_L_0E2D;
  lab_p00_L_0E2D: ;
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  set_hl(0x8481);
  a = mem_read8(hl());
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() - 1));
  a = (uint8_t)(a + 0xB0);
  if (flag_nc()) return;
  p00_L_1373();
  if (flag_nc()) return;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x10);
  p00_L_15F3();
  return;
}

/* flash page 0 cpu 0x0D1E (offset 0x0D1E) */
void p00_L_0D1E(void) {
  p00_rst08();
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 6)));
  p00_L_0FB5();
  p00_L_14C7();
  if (flag_z()) return;
  p00_L_14CC();
  if (flag_z()) { p00_L_1179(); return; }
  p00_L_0E9E();
  a = d;
  mem_write8(0x8479, a);
  p00_L_129F();
  b = 0x08;
  set_hl(0x848D);
  lab_p00_L_0D3F: ;
  set_hl((uint16_t)(hl() - 1));
  cpu_cp_hl();
  if (flag_nz()) goto lab_p00_L_0D4F;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0D3F;
  lab_p00_L_0D45: ;
  set_hl(0x848F);
  p00_L_12D0();
  /* rrd */
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  lab_p00_L_0D4F: ;
  cpu_push_hl();
  cpu_push_bc();
  a = mem_read8(hl());
  c = a;
  a = a & 0x0F;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0D96;
  b = a;
  lab_p00_L_0D58: ;
  set_de(0x8497);
  set_hl(mem_read16(0x8480));
  a = mem_read8(de());
  a = (uint8_t)(a + h);
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847E));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847C));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847A));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  if (flag_nc()) goto lab_p00_L_0D94;
  set_de((uint16_t)(de() - 1));
  cpu_ex_de_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p00_L_0D94: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0D58;
  lab_p00_L_0D96: ;
  set_hl(0x848F);
  p00_L_12D0();
  /* rrd */
  a = c;
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  a = a & 0x0F;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0DE6;
  b = a;
  lab_p00_L_0DA8: ;
  set_de(0x8497);
  set_hl(mem_read16(0x8480));
  a = mem_read8(de());
  a = (uint8_t)(a + h);
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847E));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847C));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x847A));
  a = mem_read8(de());
  /* adc a,h */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  /* adc a,l */
  /* daa */
  mem_write8(de(), a);
  if (flag_nc()) goto lab_p00_L_0DE4;
  set_de((uint16_t)(de() - 1));
  cpu_ex_de_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p00_L_0DE4: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_0DA8;
  lab_p00_L_0DE6: ;
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p00_L_0D45;
  cpu_pop_hl();
  a = mem_read8(0x848F);
  a = a & a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0DFD;
  set_hl(0x848F);
  p00_L_12D0();
  /* rrd */
  p00_L_15F3();
  lab_p00_L_0DFD: ;
  p00_L_11CB();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 6)) == 0);
  if (flag_nz()) return;
  goto lab_p00_L_0E2D;
  lab_p00_L_0E2D: ;
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  set_hl(0x8481);
  a = mem_read8(hl());
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() - 1));
  a = (uint8_t)(a + 0xB0);
  if (flag_nc()) return;
  p00_L_1373();
  if (flag_nc()) return;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x10);
  p00_L_15F3();
  return;
}

/* flash page 0 cpu 0x0E4C (offset 0x0E4C) */
void p00_L_0E4C(void) {
  p00_L_14C7();
  a = mem_read8(0x8478);
  if (flag_nz()) goto lab_p00_L_0E56;
  a = a | 0x80;
  flag_logic(a);
  lab_p00_L_0E56: ;
  a = a ^ 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  return;
}

/* flash page 0 cpu 0x0E5C (offset 0x0E5C) */
void p00_L_0E5C(void) {
  p00_L_14CC();
  a = mem_read8(0x8483);
  if (flag_nz()) goto lab_p00_L_0E66;
  a = a | 0x80;
  flag_logic(a);
  lab_p00_L_0E66: ;
  a = a ^ 0x80;
  flag_logic(a);
  mem_write8(0x8483, a);
  return;
}

/* flash page 0 cpu 0x0E72 (offset 0x0E72) */
void p00_L_0E72(void) {
  goto lab_p00_L_0E72;
  lab_p00_L_0E07: ;
  set_hl(0x847A);
  a = mem_read8(hl());
  a = a & 0xF0;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_0E2D;
  c = 0x10;
  lab_p00_L_0E11: ;
  c = (uint8_t)(c - 1);
  if (flag_z()) { p00_L_128A(); return; }
  p00_L_1301();
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a & 0xF0;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_0E11;
  a = 0x10;
  a = (uint8_t)(a - c);
  c = a;
  a = mem_read8(0x8479);
  a = (uint8_t)(a - c);
  if (flag_c()) { p00_L_128A(); return; }
  mem_write8(0x8479, a);
  lab_p00_L_0E2D: ;
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  mem_write8(0x8478, a);
  set_hl(0x8481);
  a = mem_read8(hl());
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() - 1));
  a = (uint8_t)(a + 0xB0);
  if (flag_nc()) return;
  p00_L_1373();
  if (flag_nc()) return;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x10);
  p00_L_15F3();
  return;
  lab_p00_L_0E72: ;
  p00_L_14C7();
  if (flag_z()) return;
  a = 0;
  flag_logic(a);
  mem_write8(0x8481, a);
  a = mem_read8(0x8479);
  a = (uint8_t)(a - 0x80);
  if (flag_c()) return;
  flag_cmp(a, 0x0F);
  if (flag_c()) goto lab_p00_L_0E8E;
  goto lab_p00_L_0EBE;
  lab_p00_L_0E86: ;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x80);
  if (flag_c()) goto lab_p00_L_0E07;
  lab_p00_L_0E8E: ;
  p00_L_12EF();
  p00_L_15EB();
  goto lab_p00_L_0E86;
  lab_p00_L_0EBE: ;
  p00_L_128A();
  return;
}

/* flash page 0 cpu 0x0E96 (offset 0x0E96) */
void p00_L_0E96(void) {
  a = mem_read8(0x8484);
  a = a ^ 0xFF;
  a = (uint8_t)(a + 1);
  d = a;
  goto lab_p00_L_0EA2;
  lab_p00_L_0EA2: ;
  a = mem_read8(0x8479);
  a = (uint8_t)(a + d);
  if (flag_nc()) goto lab_p00_L_0EAF;
  a = (uint8_t)(a + 0x80);
  if (flag_nc()) goto lab_p00_L_0EB3;
  goto lab_p00_L_24BD;
  lab_p00_L_0EAF: ;
  a = (uint8_t)(a + 0x80);
  if (flag_nc()) goto lab_p00_L_0EBD;
  lab_p00_L_0EB3: ;
  d = a;
  a = mem_read8(0x8483);
  set_hl(0x8478);
  /* xor (hl) */
  mem_write8(hl(), a);
  return;
  lab_p00_L_0EBD: ;
  cpu_pop_bc();
  p00_L_128A();
  return;
  lab_p00_L_24BD: ;
  a = 0x81;
  goto lab_p00_L_24DF;
  lab_p00_L_24DF: ;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x0E9E (offset 0x0E9E) */
void p00_L_0E9E(void) {
  a = mem_read8(0x8484);
  d = a;
  a = mem_read8(0x8479);
  a = (uint8_t)(a + d);
  if (flag_nc()) goto lab_p00_L_0EAF;
  a = (uint8_t)(a + 0x80);
  if (flag_nc()) goto lab_p00_L_0EB3;
  goto lab_p00_L_24BD;
  lab_p00_L_0EAF: ;
  a = (uint8_t)(a + 0x80);
  if (flag_nc()) goto lab_p00_L_0EBD;
  lab_p00_L_0EB3: ;
  d = a;
  a = mem_read8(0x8483);
  set_hl(0x8478);
  /* xor (hl) */
  mem_write8(hl(), a);
  return;
  lab_p00_L_0EBD: ;
  cpu_pop_bc();
  p00_L_128A();
  return;
  lab_p00_L_24BD: ;
  a = 0x81;
  goto lab_p00_L_24DF;
  lab_p00_L_24DF: ;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x0FB5 (offset 0x0FB5) */
void p00_L_0FB5(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x8481, a);
  mem_write8(0x848C, a);
  mem_write8(0x8482, a);
  mem_write8(0x848D, a);
  return;
}

/* flash page 0 cpu 0x1025 (offset 0x1025) */
void p00_L_1025(void) {
  b = h;
  c = l;
  set_hl((uint16_t)(hl() + hl()));
  if (flag_c()) return;
  set_hl((uint16_t)(hl() + hl()));
  if (flag_c()) return;
  set_hl((uint16_t)(hl() + hl()));
  if (flag_c()) return;
  set_hl((uint16_t)(hl() + bc()));
  return;
}

/* flash page 0 cpu 0x1037 (offset 0x1037) */
void p00_L_1037(void) {
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  return;
}

/* flash page 0 cpu 0x104E (offset 0x104E) */
void p00_L_104E(void) {
  a = mem_read8(0x8478);
  a = a & 0xE0;
  flag_logic(a);
  a = a | 0x0C;
  flag_logic(a);
  mem_write8(0x8478, a);
  a = mem_read8(0x8483);
  a = a & 0xE0;
  flag_logic(a);
  a = a | 0x0C;
  flag_logic(a);
  mem_write8(0x8483, a);
  return;
}

/* flash page 0 cpu 0x10D4 (offset 0x10D4) */
void p00_L_10D4(void) {
  set_hl(0x848E);
  set_de(0x8499);
  goto lab_p00_L_117F;
  lab_p00_L_117F: ;
  cpu_ldi();
  cpu_ldi();
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x10DD (offset 0x10DD) */
void p00_L_10DD(void) {
  set_hl(0x8478);
  set_de(0x8499);
  goto lab_p00_L_117F;
  lab_p00_L_117F: ;
  cpu_ldi();
  cpu_ldi();
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x10E6 (offset 0x10E6) */
void p00_L_10E6(void) {
  set_hl(0x8483);
  set_de(0x8499);
  goto lab_p00_L_117F;
  lab_p00_L_117F: ;
  cpu_ldi();
  cpu_ldi();
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x10F8 (offset 0x10F8) */
void p00_L_10F8(void) {
  set_hl(0x848E);
  set_de(0x8483);
  goto lab_p00_L_117F;
  lab_p00_L_117F: ;
  cpu_ldi();
  cpu_ldi();
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x1100 (offset 0x1100) */
void p00_L_1100(void) {
  set_de(0x848E);
  p00_L_1103();
  return;
}

/* flash page 0 cpu 0x1103 (offset 0x1103) */
void p00_L_1103(void) {
  set_hl(0x8478);
  goto lab_p00_L_117F;
  lab_p00_L_117F: ;
  cpu_ldi();
  cpu_ldi();
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x1110 (offset 0x1110) */
void p00_L_1110(void) {
  set_hl(0x84A4);
  set_de(0x84AF);
  goto lab_p00_L_117F;
  lab_p00_L_117F: ;
  cpu_ldi();
  cpu_ldi();
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x1135 (offset 0x1135) */
void p00_L_1135(void) {
  set_hl(0x8499);
  goto lab_p00_L_117C;
  lab_p00_L_117C: ;
  set_de(0x8478);
  cpu_ldi();
  cpu_ldi();
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x113F (offset 0x113F) */
void p00_L_113F(void) {
  set_hl(0x848E);
  goto lab_p00_L_117C;
  lab_p00_L_117C: ;
  set_de(0x8478);
  cpu_ldi();
  cpu_ldi();
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x1179 (offset 0x1179) */
void p00_L_1179(void) {
  set_hl(0x8483);
  set_de(0x8478);
  cpu_ldi();
  cpu_ldi();
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x1183 (offset 0x1183) */
void p00_L_1183(void) {
  cpu_ldi();
  p00_L_1185();
  return;
}

/* flash page 0 cpu 0x1185 (offset 0x1185) */
void p00_L_1185(void) {
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  cpu_ldi();
  return;
}

/* flash page 0 cpu 0x11CB (offset 0x11CB) */
void p00_L_11CB(void) {
  set_de(0x847A);
  set_hl(0x8490);
  p00_L_1185();
  return;
}

/* flash page 0 cpu 0x11F8 (offset 0x11F8) */
void p00_L_11F8(void) {
  goto lab_p00_L_11F8;
  lab_p00_L_11F5: ;
  p00_L_1183();
  return;
  lab_p00_L_11F8: ;
  set_de(0x8483);
  goto lab_p00_L_11F5;
}

/* flash page 0 cpu 0x11FD (offset 0x11FD) */
void p00_L_11FD(void) {
  goto lab_p00_L_11FD;
  lab_p00_L_11F5: ;
  p00_L_1183();
  return;
  lab_p00_L_11FD: ;
  set_hl(0x8478);
  goto lab_p00_L_11F5;
}

/* flash page 0 cpu 0x1229 (offset 0x1229) */
void p00_L_1229(void) {
  set_hl(0x8478);
  p00_L_1254();
  return;
}

/* flash page 0 cpu 0x1251 (offset 0x1251) */
void p00_L_1251(void) {
  set_hl(0x8483);
  p00_L_1254();
  return;
}

/* flash page 0 cpu 0x1254 (offset 0x1254) */
void p00_L_1254(void) {
  a = 0x10;
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x80);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  a = 0;
  flag_logic(a);
  goto lab_p00_L_1262;
  lab_p00_L_1262: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  return;
}

/* flash page 0 cpu 0x1287 (offset 0x1287) */
void p00_L_1287(void) {
  goto lab_p00_L_1287;
  lab_p00_L_1215: ;
  set_hl(0x8483);
  goto lab_p00_L_1256;
  lab_p00_L_1256: ;
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x80);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  a = 0;
  flag_logic(a);
  goto lab_p00_L_1262;
  lab_p00_L_1262: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  return;
  lab_p00_L_1287: ;
  a = 0;
  flag_logic(a);
  goto lab_p00_L_1215;
}

/* flash page 0 cpu 0x128A (offset 0x128A) */
void p00_L_128A(void) {
  goto lab_p00_L_128A;
  lab_p00_L_1256: ;
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x80);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  a = 0;
  flag_logic(a);
  goto lab_p00_L_1262;
  lab_p00_L_1262: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  return;
  lab_p00_L_128A: ;
  set_hl(0x8478);
  a = 0;
  flag_logic(a);
  goto lab_p00_L_1256;
}

/* flash page 0 cpu 0x1295 (offset 0x1295) */
void p00_L_1295(void) {
  goto lab_p00_L_1295;
  lab_p00_L_125B: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  a = 0;
  flag_logic(a);
  goto lab_p00_L_1262;
  lab_p00_L_1262: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  return;
  lab_p00_L_1295: ;
  set_hl(0x8478);
  goto lab_p00_L_12A2;
  lab_p00_L_12A2: ;
  a = 0;
  flag_logic(a);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  goto lab_p00_L_125B;
}

/* flash page 0 cpu 0x129A (offset 0x129A) */
void p00_L_129A(void) {
  goto lab_p00_L_129A;
  lab_p00_L_125B: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  a = 0;
  flag_logic(a);
  goto lab_p00_L_1262;
  lab_p00_L_1262: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  return;
  lab_p00_L_129A: ;
  set_hl(0x8483);
  goto lab_p00_L_12A2;
  lab_p00_L_12A2: ;
  a = 0;
  flag_logic(a);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  goto lab_p00_L_125B;
}

/* flash page 0 cpu 0x129F (offset 0x129F) */
void p00_L_129F(void) {
  goto lab_p00_L_129F;
  lab_p00_L_125B: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  a = 0;
  flag_logic(a);
  goto lab_p00_L_1262;
  lab_p00_L_1262: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  return;
  lab_p00_L_129F: ;
  set_hl(0x848E);
  a = 0;
  flag_logic(a);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  goto lab_p00_L_125B;
}

/* flash page 0 cpu 0x12AA (offset 0x12AA) */
void p00_L_12AA(void) {
  lab_p00_L_12AA: ;
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_12AA;
  return;
}

/* flash page 0 cpu 0x12B1 (offset 0x12B1) */
void p00_L_12B1(void) {
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  a = a & 0x0F;
  flag_logic(a);
  return;
}

/* flash page 0 cpu 0x12B9 (offset 0x12B9) */
void p00_L_12B9(void) {
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  return;
}

/* flash page 0 cpu 0x12D0 (offset 0x12D0) */
void p00_L_12D0(void) {
  a = 0;
  flag_logic(a);
  /* rrd */
  set_hl((uint16_t)(hl() + 1));
  p00_L_12D4();
  return;
}

/* flash page 0 cpu 0x12D4 (offset 0x12D4) */
void p00_L_12D4(void) {
  /* rrd */
  set_hl((uint16_t)(hl() + 1));
  /* rrd */
  set_hl((uint16_t)(hl() + 1));
  /* rrd */
  set_hl((uint16_t)(hl() + 1));
  /* rrd */
  set_hl((uint16_t)(hl() + 1));
  /* rrd */
  set_hl((uint16_t)(hl() + 1));
  /* rrd */
  set_hl((uint16_t)(hl() + 1));
  /* rrd */
  set_hl((uint16_t)(hl() + 1));
  return;
}

/* flash page 0 cpu 0x12EF (offset 0x12EF) */
void p00_L_12EF(void) {
  set_hl(0x8480);
  a = 0;
  flag_logic(a);
  goto lab_p00_L_1308;
  lab_p00_L_1308: ;
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  return;
}

/* flash page 0 cpu 0x12F5 (offset 0x12F5) */
void p00_L_12F5(void) {
  goto lab_p00_L_12F5;
  lab_p00_L_12D1: ;
  /* rrd */
  set_hl((uint16_t)(hl() + 1));
  p00_L_12D4();
  return;
  lab_p00_L_12F5: ;
  set_hl(0x847A);
  a = 0x01;
  goto lab_p00_L_12D1;
}

/* flash page 0 cpu 0x1301 (offset 0x1301) */
void p00_L_1301(void) {
  set_hl(0x8481);
  a = 0;
  flag_logic(a);
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  /* rld */
  set_hl((uint16_t)(hl() - 1));
  return;
}

/* flash page 0 cpu 0x1373 (offset 0x1373) */
void p00_L_1373(void) {
  a = 0x01;
  b = 0x07;
  a = a | a;
  flag_logic(a);
  lab_p00_L_1378: ;
  /* adc a,(hl) */
  /* daa */
  mem_write8(hl(), a);
  if (flag_nc()) return;
  set_hl((uint16_t)(hl() - 1));
  a = 0x00;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_1378;
  return;
}

/* flash page 0 cpu 0x1397 (offset 0x1397) */
void p00_L_1397(void) {
  set_hl(0x8481);
  set_de(0x848C);
  p00_L_13BB();
  return;
}

/* flash page 0 cpu 0x139F (offset 0x139F) */
void p00_L_139F(void) {
  set_hl(0x848C);
  set_de(0x8481);
  p00_L_13BB();
  return;
}

/* flash page 0 cpu 0x13BB (offset 0x13BB) */
void p00_L_13BB(void) {
  a = mem_read8(de());
  /* add a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* adc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* adc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* adc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* adc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* adc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* adc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* adc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  return;
}

/* flash page 0 cpu 0x1415 (offset 0x1415) */
void p00_L_1415(void) {
  set_hl(0x8481);
  set_de(0x848C);
  p00_L_1430();
  return;
}

/* flash page 0 cpu 0x141D (offset 0x141D) */
void p00_L_141D(void) {
  set_hl(0x848C);
  goto lab_p00_L_142D;
  lab_p00_L_142D: ;
  set_de(0x8481);
  p00_L_1430();
  return;
}

/* flash page 0 cpu 0x1430 (offset 0x1430) */
void p00_L_1430(void) {
  a = mem_read8(de());
  /* sub (hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* sbc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* sbc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* sbc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* sbc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* sbc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* sbc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  /* sbc a,(hl) */
  /* daa */
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() - 1));
  return;
}

/* flash page 0 cpu 0x14B0 (offset 0x14B0) */
void p00_L_14B0(void) {
  set_hl(0x8483);
  set_de(0x8478);
  b = 0x0B;
  p00_L_14B8();
  return;
}

/* flash page 0 cpu 0x14B8 (offset 0x14B8) */
void p00_L_14B8(void) {
  lab_p00_L_14B8: ;
  a = mem_read8(de());
  c = mem_read8(hl());
  mem_write8(hl(), a);
  a = c;
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_14B8;
  return;
}

/* flash page 0 cpu 0x14C7 (offset 0x14C7) */
void p00_L_14C7(void) {
  a = mem_read8(0x847A);
  a = a & a;
  flag_logic(a);
  return;
}

/* flash page 0 cpu 0x14CC (offset 0x14CC) */
void p00_L_14CC(void) {
  a = mem_read8(0x8485);
  a = a & a;
  flag_logic(a);
  return;
}

/* flash page 0 cpu 0x14DB (offset 0x14DB) */
void p00_L_14DB(void) {
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  if (flag_nz()) return;
  p00_L_14E1();
  return;
}

/* flash page 0 cpu 0x14E1 (offset 0x14E1) */
void p00_L_14E1(void) {
  set_hl(0x8479);
  d = 0x01;
  goto lab_p00_L_14EA;
  lab_p00_L_14EA: ;
  a = mem_read8(hl());
  e = a;
  a = (uint8_t)(a - 0x80);
  if (flag_c()) return;
  flag_cmp(a, 0x0E);
  if (flag_c()) goto lab_p00_L_14F5;
  a = 0;
  flag_logic(a);
  return;
  lab_p00_L_14F5: ;
  /* srl a */
  b = 0x00;
  c = a;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  flag_set_z((d & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_1509;
  flag_set_z((e & (1u << 0)) == 0);
  if (flag_z()) p00_L_12B1();
  a = a & 0x01;
  flag_logic(a);
  return;
  lab_p00_L_1509: ;
  flag_set_z((e & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p00_L_1510;
  a = a & 0x0F;
  flag_logic(a);
  if (flag_nz()) return;
  lab_p00_L_1510: ;
  a = 0x06;
  a = (uint8_t)(a - c);
  if (flag_z()) return;
  set_hl((uint16_t)(hl() + 1));
  b = a;
  p00_L_1525();
  return;
}

/* flash page 0 cpu 0x1525 (offset 0x1525) */
void p00_L_1525(void) {
  a = 0;
  flag_logic(a);
  lab_p00_L_1526: ;
  cpu_cp_hl();
  if (flag_nz()) return;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_1526;
  return;
}

/* flash page 0 cpu 0x1531 (offset 0x1531) */
void p00_L_1531(void) {
  set_de(0x8483);
  cpu_push_af();
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  cpu_pop_af();
  set_hl(0x1544);
  p00_L_18C3();
  cpu_ldi();
  cpu_ldi();
  return;
}

/* flash page 0 cpu 0x159F (offset 0x159F) */
void p00_L_159F(void) {
  a = 0x80;
  /* sub (hl) */
  if (flag_nc()) goto lab_p00_L_15A7;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  return;
  lab_p00_L_15A7: ;
  mem_write8(hl(), a);
  return;
}

/* flash page 0 cpu 0x15CB (offset 0x15CB) */
void p00_L_15CB(void) {
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  return;
}

/* flash page 0 cpu 0x15D1 (offset 0x15D1) */
void p00_L_15D1(void) {
  set_hl(0x8483);
  goto lab_p00_L_15D9;
  lab_p00_L_15D9: ;
  a = mem_read8(hl());
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  return;
}

/* flash page 0 cpu 0x15D6 (offset 0x15D6) */
void p00_L_15D6(void) {
  set_hl(0x8478);
  a = mem_read8(hl());
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  return;
}

/* flash page 0 cpu 0x15E0 (offset 0x15E0) */
void p00_L_15E0(void) {
  p00_L_14C7();
  if (flag_z()) return;
  p00_L_15EB();
  if (flag_z()) { p00_L_128A(); return; }
  return;
}

/* flash page 0 cpu 0x15EB (offset 0x15EB) */
void p00_L_15EB(void) {
  a = mem_read8(0x8479);
  a = (uint8_t)(a - 1);
  mem_write8(0x8479, a);
  return;
}

/* flash page 0 cpu 0x15F3 (offset 0x15F3) */
void p00_L_15F3(void) {
  set_hl(0x8479);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  if (flag_nz()) return;
  goto lab_p00_L_24BD;
  lab_p00_L_24BD: ;
  a = 0x81;
  goto lab_p00_L_24DF;
  lab_p00_L_24DF: ;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x15FB (offset 0x15FB) */
void p00_L_15FB(void) {
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  cpu_push_af();
  if (flag_z()) goto lab_p00_L_1620;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p00_L_1639;
  p00_L_14CC();
  if (flag_nz()) goto lab_p00_L_1614;
  lab_p00_L_160C: ;
  p00_L_1287();
  cpu_pop_af();
  mem_write8(0x8483, a);
  cpu_push_af();
  lab_p00_L_1614: ;
  a = mem_read8(0x8484);
  flag_cmp(a, 0xE4);
  if (flag_nc()) goto lab_p00_L_24BD;
  flag_cmp(a, 0x1D);
  if (flag_c()) goto lab_p00_L_160C;
  lab_p00_L_1620: ;
  p00_L_14C7();
  if (flag_nz()) goto lab_p00_L_162D;
  lab_p00_L_1625: ;
  p00_L_128A();
  cpu_pop_af();
  mem_write8(0x8478, a);
  return;
  lab_p00_L_162D: ;
  a = mem_read8(0x8479);
  flag_cmp(a, 0xE4);
  if (flag_nc()) goto lab_p00_L_24BD;
  flag_cmp(a, 0x1D);
  if (flag_c()) goto lab_p00_L_1625;
  lab_p00_L_1639: ;
  cpu_pop_af();
  return;
  lab_p00_L_24BD: ;
  a = 0x81;
  goto lab_p00_L_24DF;
  lab_p00_L_24DF: ;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x1641 (offset 0x1641) */
void p00_L_1641(void) {
  a = mem_read8(0x8479);
  flag_cmp(a, 0x24);
  return;
}

/* flash page 0 cpu 0x1647 (offset 0x1647) */
void p00_L_1647(void) {
  b = h;
  h = 0x00;
  d = h;
  e = h;
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  lab_p00_L_164E: ;
  /* adc hl,de */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_164E;
  return;
}

/* flash page 0 cpu 0x1653 (offset 0x1653) */
void p00_L_1653(void) {
  p00_L_1037();
  if (flag_z()) return;
  flag_cmp(a, 0x0E);
  if (flag_z()) goto lab_p00_L_24FD;
  goto lab_p00_L_24DD;
  lab_p00_L_24DD: ;
  a = 0x89;
  goto lab_p00_L_255F;
  lab_p00_L_24FD: ;
  a = 0x8F;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x1664 (offset 0x1664) */
void p00_L_1664(void) {
  set_hl(0x0023);
  a = 0x05;
  mem_write8(0x8478, a);
  goto lab_p00_L_1678;
  lab_p00_L_1678: ;
  mem_write16(0x8479, hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x847B, a);
  return;
}

/* flash page 0 cpu 0x1671 (offset 0x1671) */
void p00_L_1671(void) {
  goto lab_p00_L_1671;
  lab_p00_L_1669: ;
  mem_write8(0x8478, a);
  goto lab_p00_L_1678;
  lab_p00_L_1671: ;
  a = 0x03;
  goto lab_p00_L_1669;
  lab_p00_L_1678: ;
  mem_write16(0x8479, hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x847B, a);
  return;
}

/* flash page 0 cpu 0x1680 (offset 0x1680) */
void p00_L_1680(void) {
  goto lab_p00_L_1680;
  lab_p00_L_1669: ;
  mem_write8(0x8478, a);
  goto lab_p00_L_1678;
  lab_p00_L_1678: ;
  mem_write16(0x8479, hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x847B, a);
  return;
  lab_p00_L_1680: ;
  a = 0x40;
  h = a;
  l = 0x5D;
  a = 0x01;
  goto lab_p00_L_1669;
}

/* flash page 0 cpu 0x16C4 (offset 0x16C4) */
void p00_L_16C4(void) {
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5C);
  if (flag_nz()) goto lab_p00_L_16D3;
  a = mem_read8(0x847A);
  set_hl(0x8D8E);
  cpu_cp_hl();
  return;
  lab_p00_L_16D3: ;
  flag_cmp(a, 0x5D);
  if (flag_nz()) return;
  set_hl(0x8D2E);
  b = 0x14;
  lab_p00_L_16DB: ;
  cpu_push_bc();
  cpu_push_hl();
  set_de(0x847E);
  b = 0x05;
  p00_L_3E3D();
  a = c;
  cpu_pop_hl();
  set_bc(0x0005);
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_bc();
  flag_cmp(a, 0x05);
  if (flag_z()) return;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_16DB;
  a = a | 0x01;
  flag_logic(a);
  return;
}

/* flash page 0 cpu 0x16F4 (offset 0x16F4) */
void p00_L_16F4(void) {
  p00_L_19ED();
  if (flag_c()) goto lab_p00_L_24F1;
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_z()) return;
  p00_L_0087();
  return;
  lab_p00_L_24F1: ;
  a = 0x8D;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x1700 (offset 0x1700) */
void p00_L_1700(void) {
  a = mem_read8(0x8479);
  set_hl(0x8484);
  /* sub (hl) */
  return;
}

/* flash page 0 cpu 0x172F (offset 0x172F) */
void p00_L_172F(void) {
  a = mem_read8(hl());
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x173E);
  set_bc(0x000A);
  a = a | a;
  flag_logic(a);
  /* cpir */
  cpu_pop_hl();
  cpu_pop_bc();
  return;
}

/* flash page 0 cpu 0x173E (offset 0x173E) */
void p00_ascii_map(void) {
  e = h;
  e = l;
  e = mem_read8(hl());
  h = b;
  h = c;
  h = d;
  h = e;
  a = mem_read8(hl());
  flag_cmp(a, e);
  a = a ^ d;
  flag_logic(a);
  set_hl(0x8E2A);
  b = mem_read8(hl());
  a = mem_read8(0x8E29);
  flag_cmp(a, b);
  if (flag_z()) goto lab_p00_L_1755;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p00_L_1757;
  lab_p00_L_1755: ;
  mem_write8(hl(), 0x00);
  lab_p00_L_1757: ;
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_1763;
  p00_L_1664();
  p00_L_19E7();
  cpu_ex_de_hl();
  return;
  lab_p00_L_1763: ;
  set_hl(0x8DA9);
  lab_p00_L_1766: ;
  a = (uint8_t)(a - 1);
  if (flag_z()) return;
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + 1));
  goto lab_p00_L_1766;
}

/* flash page 0 cpu 0x17B0 (offset 0x17B0) */
void p00_L_17B0(void) {
  p00_L_1037();
  p00_L_17B3();
  return;
}

/* flash page 0 cpu 0x17B3 (offset 0x17B3) */
void p00_L_17B3(void) {
  flag_cmp(a, 0x15);
  if (flag_z()) return;
  flag_cmp(a, 0x17);
  if (flag_z()) return;
  goto lab_p00_L_17BE;
  lab_p00_L_17BE: ;
  flag_cmp(a, 0x05);
  if (flag_z()) return;
  flag_cmp(a, 0x16);
  if (flag_z()) return;
  flag_cmp(a, 0x06);
  return;
}

/* flash page 0 cpu 0x17BB (offset 0x17BB) */
void p00_L_17BB(void) {
  p00_L_1037();
  flag_cmp(a, 0x05);
  if (flag_z()) return;
  flag_cmp(a, 0x16);
  if (flag_z()) return;
  flag_cmp(a, 0x06);
  return;
}

/* flash page 0 cpu 0x17CE (offset 0x17CE) */
void p00_L_17CE(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p00_L_17D6;
  flag_cmp(a, a);
  return;
  lab_p00_L_17D6: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  return;
}

/* flash page 0 cpu 0x17DB (offset 0x17DB) */
void p00_L_17DB(void) {
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 3)));
  return;
}

/* flash page 0 cpu 0x1813 (offset 0x1813) */
void p00_lcd_cmd_07(void) {
  cpu_push_af();
  a = 0x07;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  cpu_pop_af();
  return;
}

/* flash page 0 cpu 0x181D (offset 0x181D) */
void p00_lcd_cmd_05(void) {
  goto lab_p00_lcd_cmd_05;
  lab_p00_L_1816: ;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  cpu_pop_af();
  return;
  lab_p00_lcd_cmd_05: ;
  cpu_push_af();
  a = 0x05;
  goto lab_p00_L_1816;
}

/* flash page 0 cpu 0x182A (offset 0x182A) */
void p00_L_182A(void) {
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  return;
}

/* flash page 0 cpu 0x1830 (offset 0x1830) */
void p00_L_1830(void) {
  flag_cmp(a, 0x01);
  if (flag_z()) return;
  flag_cmp(a, 0x0D);
  return;
}

/* flash page 0 cpu 0x1873 (offset 0x1873) */
void p00_L_1873(void) {
  p00_L_15CB();
  if (flag_z()) return;
  goto lab_p00_L_24C9;
  lab_p00_L_24C9: ;
  a = 0x84;
  goto lab_p00_L_24DF;
  lab_p00_L_24DF: ;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x18C3 (offset 0x18C3) */
void p00_L_18C3(void) {
  cpu_push_bc();
  c = 0x09;
  b = a;
  a = 0;
  flag_logic(a);
  goto lab_p00_L_18CB;
  lab_p00_L_18CA: ;
  a = (uint8_t)(a + c);
  lab_p00_L_18CB: ;
  b = (uint8_t)(b - 1);
  if (flag_p()) goto lab_p00_L_18CA;
  c = a;
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  p00_L_1185();
  cpu_pop_bc();
  return;
}

/* flash page 0 cpu 0x1901 (offset 0x1901) */
void p00_mmu_set_bankA_3(void) {
  /* CURATED -> mmu_set_bank_a */
  mmu_set_bank_a(a);
}

/* flash page 0 cpu 0x1923 (offset 0x1923) */
void p00_L_1923(void) {
  set_de(mem_read16(0x96F8));
  set_hl(mem_read16(0x96FA));
  p00_L_192A();
  return;
}

/* flash page 0 cpu 0x192A (offset 0x192A) */
void p00_L_192A(void) {
  cpu_push_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_pop_hl();
  return;
}

/* flash page 0 cpu 0x19A4 (offset 0x19A4) */
void p00_L_19A4(void) {
  set_de((uint16_t)(de() - 1));
  set_hl(0x9C25);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nz()) return;
  set_de(0x824F);
  return;
}

/* flash page 0 cpu 0x19B0 (offset 0x19B0) */
void p00_L_19B0(void) {
  set_hl(mem_read16(0x9828));
  set_bc(mem_read16(0x9824));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nc()) goto lab_p00_L_19C0;
  set_hl(0x0000);
  return;
  lab_p00_L_19C0: ;
  set_hl((uint16_t)(hl() + 1));
  return;
}

/* flash page 0 cpu 0x19C5 (offset 0x19C5) */
void p00_L_19C5(void) {
  cpu_push_hl();
  set_hl(0x8479);
  a = mem_read8(hl());
  a = (uint8_t)(a - 0x5D);
  d = a;
  set_bc(0x0008);
  a = 0;
  flag_logic(a);
  /* cpir */
  cpu_pop_hl();
  a = 0x08;
  if (flag_nz()) return;
  c = (uint8_t)(c + 1);
  a = (uint8_t)(a - c);
  flag_cmp(a, 0x01);
  if (flag_nz()) return;
  e = a;
  a = d;
  a = a | a;
  flag_logic(a);
  a = e;
  if (flag_nz()) return;
  a = (uint8_t)(a + 1);
  return;
}

/* flash page 0 cpu 0x19E7 (offset 0x19E7) */
void p00_L_19E7(void) {
  a = 0x05;
  p00_L_3E13();
  return;
}

/* flash page 0 cpu 0x19ED (offset 0x19ED) */
void p00_L_19ED(void) {
  goto lab_p00_L_19ED;
  lab_p00_L_19E9: ;
  p00_L_3E13();
  return;
  lab_p00_L_19ED: ;
  p00_L_17B0();
  if (flag_z()) goto lab_p00_L_19E9;
  p00_L_3E19();
  return;
}

/* flash page 0 cpu 0x19F6 (offset 0x19F6) */
void p00_L_19F6(void) {
  c = 0x09;
  p00_L_19F8();
  return;
}

/* flash page 0 cpu 0x19F8 (offset 0x19F8) */
void p00_L_19F8(void) {
  b = 0x00;
  cpu_push_bc();
  set_hl(mem_read16(0x9826));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9826, hl());
  a = mem_read8(0x847E);
  flag_cmp(a, 0x24);
  if (flag_z()) goto lab_p00_L_1A32;
  set_hl(mem_read16(0x982E));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x982E, hl());
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p00_L_1A29;
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p00_L_1A29;
  p00_L_1037();
  p00_L_1830();
  if (flag_z()) goto lab_p00_L_1A32;
  p00_L_17B0();
  if (flag_z()) goto lab_p00_L_1A32;
  lab_p00_L_1A29: ;
  set_hl(mem_read16(0x9830));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9830, hl());
  lab_p00_L_1A32: ;
  set_de(mem_read16(0x9828));
  set_hl((uint16_t)(hl() + bc()));
  cpu_push_hl();
  cpu_sbc_hl_de();
  cpu_push_af();
  cpu_push_hl();
  cpu_ex_de_hl();
  cpu_sbc_hl_bc();
  mem_write16(0x9828, hl());
  set_hl((uint16_t)(hl() + 1));
  d = h;
  e = l;
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_bc();
  cpu_pop_af();
  if (flag_z()) goto lab_p00_L_1A4C;
  while (bc() != 0) { cpu_ldi(); }
  lab_p00_L_1A4C: ;
  cpu_pop_de();
  cpu_pop_bc();
  cpu_push_de();
  cpu_push_bc();
  b = c;
  set_hl(0x8478);
  b = (uint8_t)(b - 1);
  lab_p00_L_1A55: ;
  a = mem_read8(hl());
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() - 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p00_L_1A55;
  p00_L_1037();
  p00_L_1830();
  if (flag_nz()) goto lab_p00_L_1A6C;
  a = mem_read8(0x847E);
  flag_cmp(a, 0x24);
  if (flag_z()) goto lab_p00_L_1A6C;
  mem_write8(hl(), 0x00);
  lab_p00_L_1A6C: ;
  a = mem_read8(hl());
  mem_write8(de(), a);
  cpu_pop_bc();
  a = mem_read8(0x847E);
  flag_cmp(a, 0x24);
  if (flag_z()) goto lab_p00_L_1A97;
  flag_cmp(a, 0x5E);
  if (flag_z()) goto lab_p00_L_1A82;
  flag_cmp(a, 0x21);
  if (flag_z()) goto lab_p00_L_1A82;
  flag_cmp(a, 0x23);
  if (flag_nz()) goto lab_p00_L_1A8E;
  lab_p00_L_1A82: ;
  a = mem_read8(0x847D);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_1A8E;
  set_hl(mem_read16(0x847B));
  mem_write16(0x9832, hl());
  lab_p00_L_1A8E: ;
  p00_L_23C4();
  cpu_pop_de();
  cpu_push_de();
  set_de((uint16_t)(de() + 1));
  p00_L_207C();
  lab_p00_L_1A97: ;
  cpu_pop_hl();
  return;
}

/* flash page 0 cpu 0x1A99 (offset 0x1A99) */
void p00_L_1A99(void) {
  cpu_push_af();
  set_hl(mem_read16(0x9822));
  cpu_push_bc();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x9822, hl());
  cpu_sbc_hl_bc();
  cpu_ex_de_hl();
  set_hl(mem_read16(0x9824));
  cpu_sbc_hl_de();
  cpu_push_hl();
  cpu_push_af();
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x9824, hl());
  set_hl((uint16_t)(hl() - 1));
  d = h;
  e = l;
  cpu_sbc_hl_bc();
  cpu_pop_af();
  cpu_pop_bc();
  if (flag_z()) goto lab_p00_L_1AD2;
  lab_p00_L_1ABB: ;
  /* ldd */
  /* ldd */
  /* ldd */
  /* ldd */
  /* ldd */
  /* ldd */
  /* ldd */
  /* ldd */
  /* ldd */
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_1ABB;
  lab_p00_L_1AD2: ;
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  if (flag_z()) goto lab_p00_L_1B07;
  set_hl(mem_read16(0x9820));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x9820, hl());
  set_hl(mem_read16(0x9832));
  cpu_push_hl();
  cpu_ex_de_hl();
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p00_L_1B08;
  cpu_push_bc();
  b = h;
  c = l;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() - 1));
  set_de(mem_read16(0x9822));
  set_de((uint16_t)(de() - 1));
  /* lddr */
  cpu_ex_de_hl();
  cpu_pop_bc();
  p00_L_23C4();
  p00_L_1FF3();
  set_bc(mem_read16(0x9815));
  lab_p00_L_1AFF: ;
  p00_L_1D37();
  p00_L_1D58();
  cpu_pop_de();
  return;
  lab_p00_L_1B07: ;
  cpu_push_de();
  lab_p00_L_1B08: ;
  set_de((uint16_t)(de() - 1));
  p00_L_23C4();
  goto lab_p00_L_1AFF;
}

/* flash page 0 cpu 0x1B0E (offset 0x1B0E) */
void p00_L_1B0E(void) {
  p00_L_1B18();
  cpu_push_de();
  set_de((uint16_t)(de() - 1));
  p00_L_1FE8();
  cpu_pop_de();
  return;
}

/* flash page 0 cpu 0x1B18 (offset 0x1B18) */
void p00_L_1B18(void) {
  cpu_push_de();
  cpu_push_hl();
  set_hl(mem_read16(0x9824));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p00_L_1B30;
  b = h;
  c = l;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() - 1));
  cpu_pop_de();
  cpu_push_de();
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() - 1));
  /* lddr */
  lab_p00_L_1B30: ;
  cpu_pop_bc();
  cpu_pop_de();
  return;
}

/* flash page 0 cpu 0x1B33 (offset 0x1B33) */
void p00_L_1B33(void) {
  cpu_ex_de_hl();
  lab_p00_L_1B34: ;
  p00_L_19B0();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) return;
  cpu_push_de();
  set_hl(mem_read16(0x982E));
  set_bc(mem_read16(0x9826));
  set_bc((uint16_t)(bc() + 1));
  d = 0x00;
  lab_p00_L_1B46: ;
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p00_L_1B69;
  set_hl((uint16_t)(hl() + bc()));
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p00_L_1B63;
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_1F58();
  cpu_pop_de();
  goto lab_p00_L_1B34;
  lab_p00_L_1B63: ;
  e = 0x09;
  cpu_sbc_hl_de();
  goto lab_p00_L_1B46;
  lab_p00_L_1B69: ;
  cpu_pop_de();
  return;
}

/* flash page 0 cpu 0x1B7E (offset 0x1B7E) */
void p00_L_1B7E(void) {
  a = (uint8_t)(a + 0x07);
  b = 0x00;
  c = a;
  p00_L_17B0();
  if (flag_z()) return;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  if (flag_z()) return;
  c = 0x09;
  return;
}

/* flash page 0 cpu 0x1B90 (offset 0x1B90) */
void p00_L_1B90(void) {
  cpu_push_hl();
  p00_L_1B7E();
  set_hl((uint16_t)(hl() + bc()));
  p00_L_1B33();
  cpu_pop_bc();
  return;
}

/* flash page 0 cpu 0x1B9D (offset 0x1B9D) */
void p00_L_1B9D(void) {
  p00_L_1025();
  if (flag_c()) goto lab_p00_L_24F5;
  p00_L_1BA3();
  return;
  lab_p00_L_24F5: ;
  a = 0x8E;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x1BA3 (offset 0x1BA3) */
void p00_L_1BA3(void) {
  goto lab_p00_L_1BA3;
  lab_p00_L_1BA0: ;
  if (flag_c()) goto lab_p00_L_24F5;
  lab_p00_L_1BA3: ;
  set_de(0x0002);
  set_hl((uint16_t)(hl() + de()));
  if (flag_c()) goto lab_p00_L_1BA0;
  mem_write8(0x8478, a);
  p00_L_17B3();
  if (flag_z()) goto lab_p00_L_1BC3;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p00_L_1BFF;
  p00_L_19C5();
  flag_cmp(a, 0x07);
  if (flag_nc()) goto lab_p00_L_24D5;
  a = (uint8_t)(a + 1);
  goto lab_p00_L_1BC6;
  lab_p00_L_1BC3: ;
  p00_L_19C5();
  lab_p00_L_1BC6: ;
  cpu_push_af();
  p00_L_1B90();
  if (flag_c()) goto lab_p00_L_1BA0;
  a = a | 0x01;
  flag_logic(a);
  p00_L_1A99();
  cpu_push_de();
  p00_L_10DD();
  set_de(0x8486);
  set_hl(0x8480);
  set_bc(0x0008);
  /* lddr */
  cpu_pop_de();
  mem_write16(0x847B, de());
  a = 0;
  flag_logic(a);
  mem_write8(0x847A, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x847D, a);
  mem_write8(0x8479, a);
  cpu_pop_af();
  mem_write8(0x847E, a);
  a = (uint8_t)(a + 0x07);
  c = a;
  p00_L_19F8();
  set_de(mem_read16(0x847B));
  return;
  lab_p00_L_1BFF: ;
  p00_L_1B90();
  if (flag_c()) goto lab_p00_L_1BA0;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x24);
  p00_L_1A99();
  cpu_push_de();
  p00_L_10DD();
  set_de(0x8480);
  set_hl(0x847B);
  set_bc(0x0003);
  /* lddr */
  cpu_pop_de();
  mem_write16(0x847B, de());
  a = 0;
  flag_logic(a);
  mem_write8(0x847D, a);
  mem_write8(0x8479, a);
  mem_write8(0x847A, a);
  p00_L_19F6();
  set_de(mem_read16(0x847B));
  return;
  lab_p00_L_24D5: ;
  a = 0x88;
  goto lab_p00_L_24DF;
  lab_p00_L_24DF: ;
  goto lab_p00_L_255F;
  lab_p00_L_24F5: ;
  a = 0x8E;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x1C46 (offset 0x1C46) */
void p00_L_1C46(void) {
  a = 0x01;
  cpu_push_hl();
  p00_L_1B9D();
  cpu_pop_bc();
  cpu_push_hl();
  h = b;
  l = c;
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p00_L_1C5A;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  cpu_pop_hl();
  return;
  lab_p00_L_1C5A: ;
  cpu_ex_de_hl();
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x00);
  a = mem_read8(0x8499);
  flag_set_z((a & (1u << 3)) == 0);
  if (flag_z()) goto lab_p00_L_1C6A;
  mem_write8(hl(), 0x0C);
  lab_p00_L_1C6A: ;
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  cpu_ex_de_hl();
  cpu_pop_hl();
  return;
}

/* flash page 0 cpu 0x1C91 (offset 0x1C91) */
void p00_L_1C91(void) {
  cpu_push_hl();
  p00_L_1BA3();
  cpu_pop_bc();
  cpu_ex_de_hl();
  mem_write8(hl(), c);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), b);
  set_hl((uint16_t)(hl() - 1));
  cpu_ex_de_hl();
  return;
}

/* flash page 0 cpu 0x1D37 (offset 0x1D37) */
void p00_L_1D37(void) {
  set_hl(mem_read16(0x965B));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) return;
  if (flag_z()) return;
  set_hl((uint16_t)(hl() + de()));
  cpu_sbc_hl_bc();
  mem_write16(0x965B, hl());
  set_hl(mem_read16(0x965D));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x965D, hl());
  set_hl(mem_read16(0x965F));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x965F, hl());
  return;
}

/* flash page 0 cpu 0x1D58 (offset 0x1D58) */
void p00_L_1D58(void) {
  set_hl(mem_read16(0x84D3));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1D69;
  if (flag_z()) goto lab_p00_L_1D69;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x84D3, hl());
  lab_p00_L_1D69: ;
  set_hl(mem_read16(0x84D5));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1D7A;
  if (flag_z()) goto lab_p00_L_1D7A;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x84D5, hl());
  lab_p00_L_1D7A: ;
  set_hl(mem_read16(0x84D7));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1D8B;
  if (flag_z()) goto lab_p00_L_1D8B;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x84D7, hl());
  lab_p00_L_1D8B: ;
  set_hl(mem_read16(0x84D9));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1D9C;
  if (flag_z()) goto lab_p00_L_1D9C;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x84D9, hl());
  lab_p00_L_1D9C: ;
  set_hl(mem_read16(0x84DB));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1DAD;
  if (flag_z()) goto lab_p00_L_1DAD;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x84DB, hl());
  lab_p00_L_1DAD: ;
  set_hl(mem_read16(0x84EB));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1DBE;
  if (flag_z()) goto lab_p00_L_1DBE;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x84EB, hl());
  lab_p00_L_1DBE: ;
  set_hl(mem_read16(0x84ED));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1DCF;
  if (flag_z()) goto lab_p00_L_1DCF;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x84ED, hl());
  lab_p00_L_1DCF: ;
  set_hl(mem_read16(0x980A));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1DE0;
  if (flag_z()) goto lab_p00_L_1DE0;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x980A, hl());
  lab_p00_L_1DE0: ;
  set_hl(mem_read16(0x9832));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1DF1;
  if (flag_z()) goto lab_p00_L_1DF1;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9832, hl());
  lab_p00_L_1DF1: ;
  set_hl(mem_read16(0x980C));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1E02;
  if (flag_z()) goto lab_p00_L_1E02;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x980C, hl());
  lab_p00_L_1E02: ;
  set_hl(mem_read16(0x9313));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1E13;
  if (flag_z()) goto lab_p00_L_1E13;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9313, hl());
  lab_p00_L_1E13: ;
  set_hl(mem_read16(0x9302));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1E24;
  if (flag_z()) goto lab_p00_L_1E24;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9302, hl());
  lab_p00_L_1E24: ;
  set_hl(mem_read16(0x84E1));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1E35;
  if (flag_z()) goto lab_p00_L_1E35;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x84E1, hl());
  lab_p00_L_1E35: ;
  set_hl(mem_read16(0x9306));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1E46;
  if (flag_z()) goto lab_p00_L_1E46;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9306, hl());
  lab_p00_L_1E46: ;
  set_hl(mem_read16(0x9311));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1E57;
  if (flag_z()) goto lab_p00_L_1E57;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9311, hl());
  lab_p00_L_1E57: ;
  set_hl(mem_read16(0x9708));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1E68;
  if (flag_z()) goto lab_p00_L_1E68;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9708, hl());
  lab_p00_L_1E68: ;
  set_hl(mem_read16(0x84DD));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1E79;
  if (flag_z()) goto lab_p00_L_1E79;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x84DD, hl());
  lab_p00_L_1E79: ;
  set_hl(mem_read16(0x918E));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1E8A;
  if (flag_z()) goto lab_p00_L_1E8A;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x918E, hl());
  lab_p00_L_1E8A: ;
  set_hl(mem_read16(0x9192));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1E9B;
  if (flag_z()) goto lab_p00_L_1E9B;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9192, hl());
  lab_p00_L_1E9B: ;
  set_hl(mem_read16(0x84E5));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1EAC;
  if (flag_z()) goto lab_p00_L_1EAC;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x84E5, hl());
  lab_p00_L_1EAC: ;
  set_hl(mem_read16(0x84E7));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1EBD;
  if (flag_z()) goto lab_p00_L_1EBD;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x84E7, hl());
  lab_p00_L_1EBD: ;
  set_hl(mem_read16(0x9196));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1ECE;
  if (flag_z()) goto lab_p00_L_1ECE;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9196, hl());
  lab_p00_L_1ECE: ;
  set_hl(mem_read16(0x84DF));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) return;
  if (flag_z()) return;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x84DF, hl());
  return;
}

/* flash page 0 cpu 0x1EDE (offset 0x1EDE) */
void p00_L_1EDE(void) {
  cpu_push_de();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  set_hl(mem_read16(0x9824));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  b = h;
  c = l;
  cpu_pop_hl();
  cpu_push_hl();
  cpu_ex_de_hl();
  if (flag_z()) goto lab_p00_L_1EF1;
  while (bc() != 0) { cpu_ldi(); }
  lab_p00_L_1EF1: ;
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 0 cpu 0x1EF4 (offset 0x1EF4) */
void p00_L_1EF4(void) {
  p00_L_2407();
  a = mem_read8(hl());
  flag_cmp(a, 0x24);
  if (flag_nz()) goto lab_p00_L_1EFE;
  a = 0;
  flag_logic(a);
  return;
  lab_p00_L_1EFE: ;
  b = 0x00;
  c = a;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  a = mem_read8(hl());
  return;
}

/* flash page 0 cpu 0x1F06 (offset 0x1F06) */
void p00_L_1F06(void) {
  cpu_push_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_pop_de();
  cpu_push_bc();
  set_bc(mem_read16(0x9828));
  cpu_push_hl();
  cpu_sbc_hl_bc();
  b = h;
  c = l;
  cpu_pop_hl();
  cpu_push_de();
  if (flag_z()) goto lab_p00_L_1F1B;
  /* lddr */
  lab_p00_L_1F1B: ;
  mem_write16(0x9828, de());
  cpu_pop_de();
  cpu_pop_bc();
  set_hl(mem_read16(0x9826));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x9826, hl());
  p00_L_2062();
  return;
}

/* flash page 0 cpu 0x1F38 (offset 0x1F38) */
void p00_L_1F38(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  set_bc(0x0009);
  p00_L_2040();
  if (flag_nz()) goto lab_p00_L_1F4E;
  cpu_push_hl();
  p00_L_2407();
  a = mem_read8(hl());
  a = (uint8_t)(a + 0x07);
  b = 0x00;
  c = a;
  cpu_pop_hl();
  lab_p00_L_1F4E: ;
  p00_L_1F06();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 0 cpu 0x1F55 (offset 0x1F55) */
void p00_L_1F55(void) {
  a = b;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 0 cpu 0x1F58 (offset 0x1F58) */
void p00_L_1F58(void) {
  goto lab_p00_L_1F58;
  lab_p00_L_117C: ;
  set_de(0x8478);
  cpu_ldi();
  cpu_ldi();
  p00_L_1183();
  return;
  lab_p00_L_1F58: ;
  p00_L_1F55();
  if (flag_nz()) goto lab_p00_L_254D;
  a = mem_read8(hl());
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) p00_L_0087();
  cpu_push_af();
  set_bc(0x0009);
  cpu_push_de();
  p00_L_2040();
  if (flag_nz()) goto lab_p00_L_1FB0;
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  p00_L_1830();
  if (flag_nz()) goto lab_p00_L_1FA5;
  cpu_pop_de();
  cpu_push_hl();
  p00_L_1EF4();
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p00_L_1FA4;
  cpu_pop_bc();
  cpu_push_af();
  p00_L_1FA3();
  set_de(0x9315);
  p00_L_1103();
  cpu_pop_hl();
  l = 0x3F;
  p00_L_1671();
  p00_rst10();
  if (flag_nc()) p00_L_1F58();
  a = mem_read8(0x847A);
  p00_L_25E7();
  a = a ^ 0xFF;
  /* and (hl) */
  mem_write8(hl(), a);
  set_hl(0x9315);
  goto lab_p00_L_117C;
  lab_p00_L_1FA4: ;
  cpu_push_de();
  lab_p00_L_1FA5: ;
  b = 0x00;
  cpu_push_hl();
  p00_L_2407();
  a = mem_read8(hl());
  a = (uint8_t)(a + 0x07);
  c = a;
  cpu_pop_hl();
  lab_p00_L_1FB0: ;
  p00_L_1F06();
  cpu_pop_hl();
  cpu_pop_af();
  p00_L_210A();
  p00_L_1FB8();
  return;
  lab_p00_L_254D: ;
  a = 0xAF;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x1FA3 (offset 0x1FA3) */
void p00_L_1FA3(void) {
  cpu_push_bc();
  cpu_push_de();
  b = 0x00;
  cpu_push_hl();
  p00_L_2407();
  a = mem_read8(hl());
  a = (uint8_t)(a + 0x07);
  c = a;
  cpu_pop_hl();
  p00_L_1F06();
  cpu_pop_hl();
  cpu_pop_af();
  p00_L_210A();
  p00_L_1FB8();
  return;
}

/* flash page 0 cpu 0x1FB8 (offset 0x1FB8) */
void p00_L_1FB8(void) {
  p00_L_1EDE();
  p00_L_1D58();
  /* nop */
  /* nop */
  set_hl(mem_read16(0x9822));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9822, hl());
  set_hl(mem_read16(0x9824));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9824, hl());
  p00_L_1D37();
  set_hl(mem_read16(0x9820));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1FED;
  if (flag_z()) goto lab_p00_L_1FED;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9820, hl());
  p00_L_1FF3();
  return;
  lab_p00_L_1FED: ;
  set_hl(mem_read16(0x982E));
  a = a | a;
  flag_logic(a);
  goto lab_p00_L_1FF6;
  lab_p00_L_1FF6: ;
  mem_write16(0x9815, bc());
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  lab_p00_L_1FFD: ;
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  b = mem_read8(hl());
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nc()) goto lab_p00_L_2019;
  set_hl((uint16_t)(hl() + bc()));
  cpu_push_hl();
  h = b;
  l = c;
  set_bc(mem_read16(0x9815));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_ex_de_hl();
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() - 1));
  cpu_pop_de();
  goto lab_p00_L_201B;
  lab_p00_L_2019: ;
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  lab_p00_L_201B: ;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_push_af();
  p00_L_2040();
  c = 0x0C;
  if (flag_nz()) goto lab_p00_L_202F;
  p00_L_2407();
  c = mem_read8(hl());
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  lab_p00_L_202F: ;
  b = 0x00;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  set_bc(mem_read16(0x9826));
  cpu_sbc_hl_bc();
  if (flag_c()) return;
  set_hl((uint16_t)(hl() + bc()));
  goto lab_p00_L_1FFD;
}

/* flash page 0 cpu 0x1FE8 (offset 0x1FE8) */
void p00_L_1FE8(void) {
  goto lab_p00_L_1FE8;
  lab_p00_L_1FBB: ;
  p00_L_1D58();
  /* nop */
  /* nop */
  set_hl(mem_read16(0x9822));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9822, hl());
  set_hl(mem_read16(0x9824));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9824, hl());
  p00_L_1D37();
  set_hl(mem_read16(0x9820));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p00_L_1FED;
  if (flag_z()) goto lab_p00_L_1FED;
  set_hl((uint16_t)(hl() + de()));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9820, hl());
  p00_L_1FF3();
  return;
  lab_p00_L_1FE8: ;
  p00_L_23C4();
  goto lab_p00_L_1FBB;
  lab_p00_L_1FED: ;
  set_hl(mem_read16(0x982E));
  a = a | a;
  flag_logic(a);
  goto lab_p00_L_1FF6;
  lab_p00_L_1FF6: ;
  mem_write16(0x9815, bc());
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  lab_p00_L_1FFD: ;
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  b = mem_read8(hl());
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nc()) goto lab_p00_L_2019;
  set_hl((uint16_t)(hl() + bc()));
  cpu_push_hl();
  h = b;
  l = c;
  set_bc(mem_read16(0x9815));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_ex_de_hl();
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() - 1));
  cpu_pop_de();
  goto lab_p00_L_201B;
  lab_p00_L_2019: ;
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  lab_p00_L_201B: ;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_push_af();
  p00_L_2040();
  c = 0x0C;
  if (flag_nz()) goto lab_p00_L_202F;
  p00_L_2407();
  c = mem_read8(hl());
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  lab_p00_L_202F: ;
  b = 0x00;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  set_bc(mem_read16(0x9826));
  cpu_sbc_hl_bc();
  if (flag_c()) return;
  set_hl((uint16_t)(hl() + bc()));
  goto lab_p00_L_1FFD;
}

/* flash page 0 cpu 0x1FF3 (offset 0x1FF3) */
void p00_L_1FF3(void) {
  set_hl(0xFE66);
  mem_write16(0x9815, bc());
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  lab_p00_L_1FFD: ;
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  b = mem_read8(hl());
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nc()) goto lab_p00_L_2019;
  set_hl((uint16_t)(hl() + bc()));
  cpu_push_hl();
  h = b;
  l = c;
  set_bc(mem_read16(0x9815));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_ex_de_hl();
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() - 1));
  cpu_pop_de();
  goto lab_p00_L_201B;
  lab_p00_L_2019: ;
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  lab_p00_L_201B: ;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_push_af();
  p00_L_2040();
  c = 0x0C;
  if (flag_nz()) goto lab_p00_L_202F;
  p00_L_2407();
  c = mem_read8(hl());
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  lab_p00_L_202F: ;
  b = 0x00;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  set_bc(mem_read16(0x9826));
  cpu_sbc_hl_bc();
  if (flag_c()) return;
  set_hl((uint16_t)(hl() + bc()));
  goto lab_p00_L_1FFD;
}

/* flash page 0 cpu 0x2040 (offset 0x2040) */
void p00_L_2040(void) {
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  p00_L_17B3();
  if (flag_z()) return;
  p00_L_1830();
  if (flag_nz()) return;
  cpu_push_hl();
  p00_L_2407();
  a = mem_read8(hl());
  flag_cmp(a, 0x24);
  if (flag_z()) goto lab_p00_L_205E;
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p00_L_205E;
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p00_L_205E;
  a = 0x01;
  lab_p00_L_205E: ;
  flag_cmp(a, 0x01);
  cpu_pop_hl();
  return;
}

/* flash page 0 cpu 0x2062 (offset 0x2062) */
void p00_L_2062(void) {
  set_hl(mem_read16(0x982E));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p00_L_206F;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x982E, hl());
  lab_p00_L_206F: ;
  set_hl(mem_read16(0x9830));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) { p00_L_207C(); return; }
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x9830, hl());
  p00_L_207C();
  return;
}

/* flash page 0 cpu 0x207C (offset 0x207C) */
void p00_L_207C(void) {
  set_hl(mem_read16(0x9706));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p00_L_2089;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x9706, hl());
  lab_p00_L_2089: ;
  set_hl(mem_read16(0x9818));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p00_L_2096;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x9818, hl());
  lab_p00_L_2096: ;
  set_hl(mem_read16(0x981A));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p00_L_20A3;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x981A, hl());
  lab_p00_L_20A3: ;
  set_hl(mem_read16(0x981C));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p00_L_20B0;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x981C, hl());
  lab_p00_L_20B0: ;
  set_hl(mem_read16(0x981E));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p00_L_20BD;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x981E, hl());
  lab_p00_L_20BD: ;
  set_hl(mem_read16(0x918C));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p00_L_20CA;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x918C, hl());
  lab_p00_L_20CA: ;
  set_hl(mem_read16(0x9190));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p00_L_20D7;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x9190, hl());
  lab_p00_L_20D7: ;
  set_hl(mem_read16(0x9194));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p00_L_20E5;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x9194, hl());
  return;
  lab_p00_L_20E5: ;
  set_hl(mem_read16(0x9808));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) return;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x9808, hl());
  return;
}

/* flash page 0 cpu 0x210A (offset 0x210A) */
void p00_L_210A(void) {
  set_de(0x0009);
  a = a & 0x1F;
  flag_logic(a);
  if (flag_z()) return;
  set_de(0x0012);
  flag_cmp(a, 0x0C);
  if (flag_z()) return;
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  cpu_push_hl();
  cpu_ex_de_hl();
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p00_L_213D;
  flag_cmp(a, 0x17);
  if (flag_z()) goto lab_p00_L_213D;
  flag_cmp(a, 0x16);
  if (flag_z()) goto lab_p00_L_213D;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p00_L_212F;
  set_hl((uint16_t)(hl() + hl()));
  goto lab_p00_L_2138;
  lab_p00_L_212F: ;
  flag_cmp(a, 0x03);
  if (flag_nc()) goto lab_p00_L_213D;
  flag_cmp(a, 0x01);
  if (flag_nz()) p00_L_1647();
  lab_p00_L_2138: ;
  p00_L_1025();
  if (flag_c()) goto lab_p00_L_2141;
  lab_p00_L_213D: ;
  set_de(0x0002);
  set_hl((uint16_t)(hl() + de()));
  lab_p00_L_2141: ;
  if (flag_c()) goto lab_p00_L_24F5;
  cpu_ex_de_hl();
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  return;
  lab_p00_L_24F5: ;
  a = 0x8E;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x2187 (offset 0x2187) */
void p00_L_2187(void) {
  set_de(0x84A4);
  goto lab_p00_L_219E;
  lab_p00_L_219E: ;
  p00_L_21A7();
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x2191 (offset 0x2191) */
void p00_L_2191(void) {
  set_de(0x848E);
  goto lab_p00_L_219E;
  lab_p00_L_219E: ;
  p00_L_21A7();
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x219B (offset 0x219B) */
void p00_L_219B(void) {
  set_de(0x8478);
  p00_L_21A7();
  p00_L_1183();
  return;
}

/* flash page 0 cpu 0x21A4 (offset 0x21A4) */
void p00_L_21A4(void) {
  p00_L_21A7();
  p00_L_21A7();
  return;
}

/* flash page 0 cpu 0x21A7 (offset 0x21A7) */
void p00_L_21A7(void) {
  set_bc(0x0009);
  set_hl(mem_read16(0x9824));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  goto lab_p00_L_21BC;
  lab_p00_L_21BC: ;
  mem_write16(0x9824, hl());
  return;
}

/* flash page 0 cpu 0x231F (offset 0x231F) */
void p00_L_231F(void) {
  goto lab_p00_L_231F;
  lab_p00_L_2304: ;
  a = 0;
  flag_logic(a);
  b = a;
  cpu_sbc_hl_bc();
  p00_L_1183();
  return;
  lab_p00_L_231F: ;
  set_de(0x8483);
  goto lab_p00_L_2327;
  lab_p00_L_2327: ;
  set_hl(mem_read16(0x9824));
  c = 0x1B;
  goto lab_p00_L_2304;
}

/* flash page 0 cpu 0x23BD (offset 0x23BD) */
void p00_L_23BD(void) {
  p00_L_1B33();
  if (flag_nc()) return;
  goto lab_p00_L_24F5;
  lab_p00_L_24F5: ;
  a = 0x8E;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x23C4 (offset 0x23C4) */
void p00_L_23C4(void) {
  a = 0;
  flag_logic(a);
  h = a;
  l = a;
  cpu_sbc_hl_bc();
  b = h;
  c = l;
  return;
}

/* flash page 0 cpu 0x2407 (offset 0x2407) */
void p00_L_2407(void) {
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  return;
}

/* flash page 0 cpu 0x2420 (offset 0x2420) */
void p00_L_2420(void) {
  cpu_push_af();
  p00_L_1F55();
  if (flag_nz()) goto lab_p00_L_254D;
  cpu_pop_af();
  return;
  lab_p00_L_254D: ;
  a = 0xAF;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x2429 (offset 0x2429) */
void p00_L_2429(void) {
  p00_rst10();
  if (flag_c()) goto lab_p00_L_24F1;
  p00_L_2420();
  return;
  lab_p00_L_24F1: ;
  a = 0x8D;
  goto lab_p00_L_255F;
  lab_p00_L_255F: ;
  p00_L_3E0D();
  mem_write8(0x86DD, a);
  p00_L_3E0D();
  p00_L_24A9();
  if (flag_z()) goto lab_p00_L_2573;
  a = 0xC0;
  link_out(a); /* stub */
  goto lab_p00_L_257B;
  lab_p00_L_2573: ;
  a = 0x80;
  hw_out(0x08, a);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p00_L_257B: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  sp = mem_read16(0x86DE);
  set_hl(mem_read16(0x9826));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  cpu_pop_de();
  set_hl(mem_read16(0x9822));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  cpu_pop_hl();
  mem_write16(0x86DE, hl());
  cpu_pop_af();
  mmu_set_bank_a(a);
  a = mem_read8(0x86DD);
  return;
}

/* flash page 0 cpu 0x249F (offset 0x249F) */
void p00_mmu_set_bankA_2(void) {
  /* CURATED -> mmu_set_bank_a */
  mmu_set_bank_a(a);
}

/* flash page 0 cpu 0x24A9 (offset 0x24A9) */
void p00_L_24A9(void) {
  cpu_push_bc();
  cpu_push_af();
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  a = a ^ 0x80;
  flag_logic(a);
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  return;
}

/* flash page 0 cpu 0x25A2 (offset 0x25A2) */
void p00_L_25A2(void) {
  /* C-ABI stack switch (Z80 pop-retaddr/jp hl omitted) */
  cpu_push_hl();
  b = a;
  a = hw_in(PORT_MMU_A);
  cpu_push_af();
  a = b;
  set_hl(mem_read16(0x86DE));
  cpu_push_hl();
  set_bc(mem_read16(0x9822));
  set_hl(mem_read16(0x9824));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  set_bc(mem_read16(0x9826));
  set_hl(mem_read16(0x9828));
  cpu_sbc_hl_bc();
  cpu_push_hl();
  mem_write16(0x86DE, sp);
}

/* flash page 0 cpu 0x25C8 (offset 0x25C8) */
void p00_L_25C8(void) {
  cpu_pop_bc();
  sp = mem_read16(0x86DE);
  cpu_pop_af();
  cpu_pop_af();
  /* ex (sp),hl */
  mem_write16(0x86DE, hl());
  cpu_pop_hl();
  cpu_pop_af();
  cpu_pop_af();
  cpu_push_bc();
  return;
}

/* flash page 0 cpu 0x25D8 (offset 0x25D8) */
void p00_L_25D8(void) {
  lab_p00_L_25D8: ;
  a = mem_read8(hl());
  mem_write8(de(), a);
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  goto lab_p00_L_25D8;
}

/* flash page 0 cpu 0x25E7 (offset 0x25E7) */
void p00_L_25E7(void) {
  set_hl(0x9320);
  cpu_push_bc();
  c = a;
  a = a & 0xF8;
  flag_logic(a);
  cpu_rrca();
  cpu_rrca();
  cpu_rrca();
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  a = c;
  a = a & 0x07;
  flag_logic(a);
  e = a;
  a = mem_read8(hl());
  set_hl(0x2605);
  set_hl((uint16_t)(hl() + de()));
  c = mem_read8(hl());
  a = a & c;
  flag_logic(a);
  a = c;
  cpu_pop_hl();
  cpu_pop_bc();
  return;
}

/* flash page 0 cpu 0x28B0 (offset 0x28B0) */
void p00_L_28B0(void) {
  goto lab_p00_L_28B0;
  lab_p00_L_2304: ;
  a = 0;
  flag_logic(a);
  b = a;
  cpu_sbc_hl_bc();
  p00_L_1183();
  return;
  lab_p00_L_232A: ;
  c = 0x1B;
  goto lab_p00_L_2304;
  lab_p00_L_28B0: ;
  set_de(0x8483);
  goto lab_p00_L_28B8;
  lab_p00_L_28B8: ;
  set_hl(mem_read16(0x9302));
  goto lab_p00_L_232A;
}

/* flash page 0 cpu 0x2B07 (offset 0x2B07) */
void p00_L_2B07(void) {
  cpu_push_hl();
  cpu_push_hl();
  cpu_push_af();
  cpu_push_de();
  cpu_push_hl();
  set_hl(0x000B);
  set_hl((uint16_t)(hl() + sp));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  a = hw_in(PORT_MMU_A);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), 0x2B);
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), 0x34);
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(de());
  set_de((uint16_t)(de() + 1));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(de());
  set_de((uint16_t)(de() + 1));
  mem_write8(hl(), a);
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  a = mem_read8(de());
  if (flag_nz()) goto lab_p00_L_2B2E;
  a = a & 0x1F;
  flag_logic(a);
  lab_p00_L_2B2E: ;
  mmu_set_bank_a(a);
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_af();
  return;
}

/* flash page 0 cpu 0x2B3C (offset 0x2B3C) */
void p00_L_2B3C(void) {
  /* ex (sp),hl */
  cpu_push_af();
  cpu_push_de();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  a = mem_read8(hl());
  if (flag_nz()) goto lab_p00_L_2B4C;
  a = a & 0x1F;
  flag_logic(a);
  lab_p00_L_2B4C: ;
  mmu_set_bank_a(a);
  cpu_ex_de_hl();
  cpu_pop_de();
  cpu_pop_af();
  /* ex (sp),hl */
  return;
}

/* flash page 0 cpu 0x3E0D (offset 0x3E0D) */
void p00_L_3E0D(void) {
  mmu_set_bank_a(0x7D); /* banked trampoline */
  os_banked_call(0x5FED);
  p00_L_3E13();
  return;
}

/* flash page 0 cpu 0x3E13 (offset 0x3E13) */
void p00_L_3E13(void) {
  mmu_set_bank_a(0x07); /* banked trampoline */
  os_banked_call(0x5646);
  p00_L_3E19();
  return;
}

/* flash page 0 cpu 0x3E19 (offset 0x3E19) */
void p00_L_3E19(void) {
  mmu_set_bank_a(0x07); /* banked trampoline */
  os_banked_call(0x56B1);
  p00_L_3E1F();
  return;
}

/* flash page 0 cpu 0x3E1F (offset 0x3E1F) */
void p00_L_3E1F(void) {
  mmu_set_bank_a(0x07); /* banked trampoline */
  os_banked_call(0x52DA);
  p00_L_3E25();
  return;
}

/* flash page 0 cpu 0x3E25 (offset 0x3E25) */
void p00_L_3E25(void) {
  mmu_set_bank_a(0x7D); /* banked trampoline */
  os_banked_call(0x6BBE);
  mmu_set_bank_a(0x7B); /* banked trampoline */
  os_banked_call(0x704E);
  return; /* banked jump */
}

/* flash page 0 cpu 0x3E31 (offset 0x3E31) */
void p00_L_3E31(void) {
  mmu_set_bank_a(0x7C); /* banked trampoline */
  os_banked_call(0x6D2E);
  p00_L_3E37();
  return;
}

/* flash page 0 cpu 0x3E37 (offset 0x3E37) */
void p00_L_3E37(void) {
  mmu_set_bank_a(0x02); /* banked trampoline */
  os_banked_call(0x65D4);
  p00_L_3E3D();
  return;
}

/* flash page 0 cpu 0x3E3D (offset 0x3E3D) */
void p00_L_3E3D(void) {
  mmu_set_bank_a(0x07); /* banked trampoline */
  os_banked_call(0x5231);
  p00_L_3E43();
  return;
}

/* flash page 0 cpu 0x3E43 (offset 0x3E43) */
void p00_L_3E43(void) {
  mmu_set_bank_a(0x01); /* banked trampoline */
  os_banked_call(0x5B76);
  p00_L_3E49();
  return;
}

/* flash page 0 cpu 0x3E49 (offset 0x3E49) */
void p00_L_3E49(void) {
  mmu_set_bank_a(0x07); /* banked trampoline */
  os_banked_call(0x7166);
  p00_L_3E4F();
  return;
}

/* flash page 0 cpu 0x3E4F (offset 0x3E4F) */
void p00_L_3E4F(void) {
  mmu_set_bank_a(0x04); /* banked trampoline */
  os_banked_call(0x678F);
  p00_L_3E55();
  return;
}

/* flash page 0 cpu 0x3E55 (offset 0x3E55) */
void p00_L_3E55(void) {
  mmu_set_bank_a(0x04); /* banked trampoline */
  os_banked_call(0x61A6);
  p00_L_3E5B();
  return;
}

/* flash page 0 cpu 0x3E5B (offset 0x3E5B) */
void p00_L_3E5B(void) {
  mmu_set_bank_a(0x07); /* banked trampoline */
  os_banked_call(0x7658);
  p00_L_3E61();
  return;
}

/* flash page 0 cpu 0x3E61 (offset 0x3E61) */
void p00_L_3E61(void) {
  mmu_set_bank_a(0x78); /* banked trampoline */
  os_banked_call(0x603F);
  p00_L_3E67();
  return;
}

/* flash page 0 cpu 0x3E67 (offset 0x3E67) */
void p00_L_3E67(void) {
  mmu_set_bank_a(0x03); /* banked trampoline */
  os_banked_call(0x69DA);
  p00_L_3E6D();
  return;
}

/* flash page 0 cpu 0x3E6D (offset 0x3E6D) */
void p00_L_3E6D(void) {
  mmu_set_bank_a(0x02); /* banked trampoline */
  os_banked_call(0x479E);
  p00_L_3E73();
  return;
}

/* flash page 0 cpu 0x3E73 (offset 0x3E73) */
void p00_L_3E73(void) {
  mmu_set_bank_a(0x02); /* banked trampoline */
  os_banked_call(0x5028);
  p00_L_3E79();
  return;
}

/* flash page 0 cpu 0x3E79 (offset 0x3E79) */
void p00_L_3E79(void) {
  mmu_set_bank_a(0x05); /* banked trampoline */
  os_banked_call(0x79CF);
  p00_L_3E7F();
  return;
}

/* flash page 0 cpu 0x3E7F (offset 0x3E7F) */
void p00_L_3E7F(void) {
  mmu_set_bank_a(0x7B); /* banked trampoline */
  os_banked_call(0x6D70);
  p00_L_3E85();
  return;
}

/* flash page 0 cpu 0x3E85 (offset 0x3E85) */
void p00_L_3E85(void) {
  mmu_set_bank_a(0x06); /* banked trampoline */
  os_banked_call(0x49FD);
  p00_L_3E8B();
  return;
}

/* flash page 0 cpu 0x3E8B (offset 0x3E8B) */
void p00_L_3E8B(void) {
  mmu_set_bank_a(0x01); /* banked trampoline */
  os_banked_call(0x5BF3);
  p00_L_3E91();
  return;
}

/* flash page 0 cpu 0x3E91 (offset 0x3E91) */
void p00_L_3E91(void) {
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x4126);
  p00_L_3E97();
  return;
}

/* flash page 0 cpu 0x3E97 (offset 0x3E97) */
void p00_L_3E97(void) {
  mmu_set_bank_a(0x7D); /* banked trampoline */
  os_banked_call(0x4908);
  p00_L_3E9D();
  return;
}

/* flash page 0 cpu 0x3E9D (offset 0x3E9D) */
void p00_L_3E9D(void) {
  mmu_set_bank_a(0x78); /* banked trampoline */
  os_banked_call(0x7B10);
  p00_L_3EA3();
  return;
}

/* flash page 0 cpu 0x3EA3 (offset 0x3EA3) */
void p00_L_3EA3(void) {
  mmu_set_bank_a(0x7B); /* banked trampoline */
  os_banked_call(0x6D58);
  p00_L_3EA9();
  return;
}

/* flash page 0 cpu 0x3EA9 (offset 0x3EA9) */
void p00_L_3EA9(void) {
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x60F9);
  p00_L_3EAF();
  return;
}

/* flash page 0 cpu 0x3EAF (offset 0x3EAF) */
void p00_L_3EAF(void) {
  mmu_set_bank_a(0x7C); /* banked trampoline */
  os_banked_call(0x6E0A);
  p00_L_3EB5();
  return;
}

/* flash page 0 cpu 0x3EB5 (offset 0x3EB5) */
void p00_L_3EB5(void) {
  mmu_set_bank_a(0x7D); /* banked trampoline */
  os_banked_call(0x7C0F);
  p00_L_3EBB();
  return;
}

/* flash page 0 cpu 0x3EBB (offset 0x3EBB) */
void p00_L_3EBB(void) {
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x41A0);
  p00_L_3EC1();
  return;
}

/* flash page 0 cpu 0x3EC1 (offset 0x3EC1) */
void p00_L_3EC1(void) {
  mmu_set_bank_a(0x01); /* banked trampoline */
  os_banked_call(0x640A);
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x43E7);
  return; /* banked jump */
}

/* flash page 0 cpu 0x3ED3 (offset 0x3ED3) */
void p00_L_3ED3(void) {
  mmu_set_bank_a(0x78); /* banked trampoline */
  os_banked_call(0x7F3A);
  p00_L_3ED9();
  return;
}

/* flash page 0 cpu 0x3ED9 (offset 0x3ED9) */
void p00_L_3ED9(void) {
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x42E0);
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x437E);
  return; /* banked jump */
}

/* flash page 0 cpu 0x3EE5 (offset 0x3EE5) */
void p00_L_3EE5(void) {
  mmu_set_bank_a(0x7D); /* banked trampoline */
  os_banked_call(0x646F);
  p00_L_3EEB();
  return;
}

/* flash page 0 cpu 0x3EEB (offset 0x3EEB) */
void p00_L_3EEB(void) {
  mmu_set_bank_a(0x06); /* banked trampoline */
  os_banked_call(0x4D0E);
  p00_L_3EF1();
  return;
}

/* flash page 0 cpu 0x3EF1 (offset 0x3EF1) */
void p00_L_3EF1(void) {
  mmu_set_bank_a(0x01); /* banked trampoline */
  os_banked_call(0x6048);
  p00_L_3EF7();
  return;
}

/* flash page 0 cpu 0x3EF7 (offset 0x3EF7) */
void p00_L_3EF7(void) {
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x687A);
  p00_L_3EFD();
  return;
}

/* flash page 0 cpu 0x3EFD (offset 0x3EFD) */
void p00_L_3EFD(void) {
  mmu_set_bank_a(0x05); /* banked trampoline */
  os_banked_call(0x79A0);
  p00_L_3F03();
  return;
}

/* flash page 0 cpu 0x3F03 (offset 0x3F03) */
void p00_L_3F03(void) {
  mmu_set_bank_a(0x04); /* banked trampoline */
  os_banked_call(0x48BE);
  p00_L_3F09();
  return;
}

/* flash page 0 cpu 0x3F09 (offset 0x3F09) */
void p00_L_3F09(void) {
  mmu_set_bank_a(0x01); /* banked trampoline */
  os_banked_call(0x5F72);
  p00_L_3F0F();
  return;
}

/* flash page 0 cpu 0x3F0E (offset 0x3F0E) */
void p00_L_3F0E(void) {
  set_bc(0x07CD);
  set_hl((uint16_t)(hl() - 1));
  d = b;
  a = d;
  b = (uint8_t)(b - 1);
  p00_L_3F15();
  return;
}

/* flash page 0 cpu 0x3F0F (offset 0x3F0F) */
void p00_L_3F0F(void) {
  mmu_set_bank_a(0x05); /* banked trampoline */
  os_banked_call(0x7A50);
  p00_L_3F15();
  return;
}

/* flash page 0 cpu 0x3F15 (offset 0x3F15) */
void p00_L_3F15(void) {
  mmu_set_bank_a(0x7C); /* banked trampoline */
  os_banked_call(0x4068);
  p00_L_3F1B();
  return;
}

/* flash page 0 cpu 0x3F1B (offset 0x3F1B) */
void p00_L_3F1B(void) {
  mmu_set_bank_a(0x7C); /* banked trampoline */
  os_banked_call(0x42F2);
  p00_L_3F21();
  return;
}

/* flash page 0 cpu 0x3F21 (offset 0x3F21) */
void p00_L_3F21(void) {
  mmu_set_bank_a(0x06); /* banked trampoline */
  os_banked_call(0x498B);
  p00_L_3F27();
  return;
}

/* flash page 0 cpu 0x3F27 (offset 0x3F27) */
void p00_L_3F27(void) {
  mmu_set_bank_a(0x04); /* banked trampoline */
  os_banked_call(0x6494);
  p00_L_3F2D();
  return;
}

/* flash page 0 cpu 0x3F2D (offset 0x3F2D) */
void p00_L_3F2D(void) {
  mmu_set_bank_a(0x01); /* banked trampoline */
  os_banked_call(0x5F59);
  p00_L_3F33();
  return;
}

/* flash page 0 cpu 0x3F33 (offset 0x3F33) */
void p00_L_3F33(void) {
  mmu_set_bank_a(0x7B); /* banked trampoline */
  os_banked_call(0x7759);
  p00_L_3F39();
  return;
}

/* flash page 0 cpu 0x3F39 (offset 0x3F39) */
void p00_L_3F39(void) {
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x4E9B);
  p00_L_3F3F();
  return;
}

/* flash page 0 cpu 0x3F3F (offset 0x3F3F) */
void p00_L_3F3F(void) {
  mmu_set_bank_a(0x07); /* banked trampoline */
  os_banked_call(0x5D4E);
  p00_L_3F45();
  return;
}

/* flash page 0 cpu 0x3F45 (offset 0x3F45) */
void p00_L_3F45(void) {
  mmu_set_bank_a(0x07); /* banked trampoline */
  os_banked_call(0x44CF);
  p00_L_3F4B();
  return;
}

/* flash page 0 cpu 0x3F4B (offset 0x3F4B) */
void p00_L_3F4B(void) {
  mmu_set_bank_a(0x04); /* banked trampoline */
  os_banked_call(0x5CB1);
  p00_L_3F51();
  return;
}

/* flash page 0 cpu 0x3F51 (offset 0x3F51) */
void p00_L_3F51(void) {
  mmu_set_bank_a(0x02); /* banked trampoline */
  os_banked_call(0x4FCB);
  p00_L_3F57();
  return;
}

/* flash page 0 cpu 0x3F57 (offset 0x3F57) */
void p00_L_3F57(void) {
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x4487);
  p00_L_3F5D();
  return;
}

/* flash page 0 cpu 0x3F5D (offset 0x3F5D) */
void p00_L_3F5D(void) {
  mmu_set_bank_a(0x07); /* banked trampoline */
  os_banked_call(0x7140);
  p00_L_3F63();
  return;
}

/* flash page 0 cpu 0x3F63 (offset 0x3F63) */
void p00_L_3F63(void) {
  mmu_set_bank_a(0x02); /* banked trampoline */
  os_banked_call(0x5007);
  p00_L_3F69();
  return;
}

/* flash page 0 cpu 0x3F69 (offset 0x3F69) */
void p00_L_3F69(void) {
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x688D);
  mmu_set_bank_a(0x78); /* banked trampoline */
  os_banked_call(0x76B4);
  p00_L_3F75();
  return;
}

/* flash page 0 cpu 0x3F75 (offset 0x3F75) */
void p00_L_3F75(void) {
  mmu_set_bank_a(0x7B); /* banked trampoline */
  os_banked_call(0x7869);
  p00_L_3F7B();
  return;
}

/* flash page 0 cpu 0x3F7B (offset 0x3F7B) */
void p00_L_3F7B(void) {
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x611A);
  p00_L_3F81();
  return;
}

/* flash page 0 cpu 0x3F81 (offset 0x3F81) */
void p00_L_3F81(void) {
  mmu_set_bank_a(0x7C); /* banked trampoline */
  os_banked_call(0x4436);
  p00_L_3F87();
  return;
}

/* flash page 0 cpu 0x3F87 (offset 0x3F87) */
void p00_L_3F87(void) {
  mmu_set_bank_a(0x7C); /* banked trampoline */
  os_banked_call(0x4204);
  p00_L_3F8D();
  return;
}

/* flash page 0 cpu 0x3F8D (offset 0x3F8D) */
void p00_L_3F8D(void) {
  mmu_set_bank_a(0x79); /* banked trampoline */
  os_banked_call(0x42FE);
  p00_L_3F93();
  return;
}

/* flash page 0 cpu 0x3F93 (offset 0x3F93) */
void p00_L_3F93(void) {
  mmu_set_bank_a(0x05); /* banked trampoline */
  os_banked_call(0x7986);
  p00_L_3F99();
  return;
}

/* flash page 0 cpu 0x3F99 (offset 0x3F99) */
void p00_L_3F99(void) {
  mmu_set_bank_a(0x7B); /* banked trampoline */
  os_banked_call(0x7729);
  p00_L_3F9F();
  return;
}

/* flash page 0 cpu 0x3F9F (offset 0x3F9F) */
void p00_L_3F9F(void) {
  mmu_set_bank_a(0x01); /* banked trampoline */
  os_banked_call(0x56A8);
  p00_L_3FA5();
  return;
}

/* flash page 0 cpu 0x3FA5 (offset 0x3FA5) */
void p00_L_3FA5(void) {
  mmu_set_bank_a(0x01); /* banked trampoline */
  os_banked_call(0x65FB);
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
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


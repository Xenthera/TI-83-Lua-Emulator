/* Recovered from flash page 24 (mechanical ASM->C) */
/* cpu window 0x4000..0x7FFF prefix=p24_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p24_L_4000(void);
void p24_L_40C0(void);
void p24_L_40D2(void);
void p24_L_40D5(void);
void p24_L_40D6(void);
void p24_L_40E3(void);
void p24_L_40E7(void);
void p24_L_4100(void);
void p24_L_4137(void);
void p24_L_4156(void);
void p24_L_4183(void);
void p24_L_4190(void);
void p24_L_419C(void);
void p24_L_41A7(void);
void p24_L_41B7(void);
void p24_L_41C1(void);
void p24_L_41DD(void);
void p24_L_41E1(void);
void p24_L_41EB(void);
void p24_L_41FB(void);
void p24_L_4213(void);
void p24_L_4217(void);
void p24_L_421B(void);
void p24_L_4226(void);
void p24_L_4229(void);
void p24_L_4295(void);
void p24_L_429E(void);
void p24_L_42A0(void);
void p24_L_42B3(void);
void p24_L_42B8(void);
void p24_L_42BD(void);
void p24_L_42C2(void);
void p24_L_42C7(void);
void p24_L_42CC(void);
void p24_L_42D1(void);
void p24_L_42D6(void);
void p24_L_42DB(void);
void p24_L_42E0(void);
void p24_L_42E5(void);
void p24_L_42EA(void);
void p24_L_42EF(void);
void p24_L_431F(void);
void p24_L_4321(void);
void p24_L_437F(void);
void p24_L_4391(void);
void p24_L_43CF(void);
void p24_L_43D1(void);
void p24_L_43D7(void);
void p24_L_43DB(void);
void p24_L_43ED(void);
void p24_L_43FE(void);
void p24_L_448B(void);
void p24_L_44CA(void);
void p24_L_44E4(void);
void p24_L_44FD(void);
void p24_L_452C(void);
void p24_L_455A(void);
void p24_L_455D(void);
void p24_L_457D(void);
void p24_L_4580(void);
void p24_L_45AB(void);
void p24_L_45C3(void);
void p24_L_46D6(void);
void p24_L_46E1(void);
void p24_L_46F7(void);
void p24_L_470B(void);
void p24_L_4727(void);
void p24_L_472E(void);
void p24_L_4742(void);
void p24_L_4747(void);
void p24_L_4767(void);
void p24_L_476A(void);
void p24_L_47B9(void);
void p24_L_47BC(void);
void p24_L_4811(void);
void p24_L_4831(void);
void p24_L_488A(void);
void p24_L_4893(void);
void p24_L_489C(void);
void p24_L_48AE(void);
void p24_L_48D3(void);
void p24_L_490D(void);
void p24_L_4913(void);
void p24_L_491E(void);
void p24_L_4938(void);
void p24_L_4945(void);
void p24_L_494A(void);
void p24_L_494E(void);
void p24_L_4952(void);
void p24_L_4956(void);
void p24_L_495A(void);
void p24_L_495E(void);
void p24_L_4962(void);
void p24_L_4966(void);
void p24_L_496A(void);
void p24_L_4970(void);
void p24_L_4974(void);
void p24_L_4978(void);
void p24_L_498A(void);
void p24_L_498E(void);
void p24_L_49B8(void);
void p24_L_49D4(void);
void p24_L_49F6(void);
void p24_L_49F9(void);
void p24_L_4A36(void);
void p24_L_4B62(void);
void p24_L_4B65(void);
void p24_L_4BE8(void);
void p24_L_4C2A(void);
void p24_L_4C2D(void);
void p24_L_4C32(void);
void p24_L_4C37(void);
void p24_L_4D1B(void);
void p24_L_4D28(void);
void p24_L_4DEA(void);
void p24_L_4DEC(void);
void p24_L_4E14(void);
void p24_L_4EBD(void);
void p24_L_4FEF(void);
void p24_L_4FF4(void);
void p24_L_50B0(void);
void p24_L_50B3(void);
void p24_L_50CF(void);
void p24_L_51E8(void);
void p24_L_51FA(void);
void p24_L_520A(void);
void p24_L_529D(void);
void p24_L_52DF(void);
void p24_L_52FE(void);
void p24_L_5370(void);
void p24_L_5379(void);
void p24_L_538F(void);
void p24_L_53B4(void);
void p24_L_53C8(void);
void p24_L_53CD(void);
void p24_L_53D4(void);
void p24_L_5403(void);
void p24_L_5407(void);
void p24_L_544C(void);
void p24_L_547B(void);
void p24_L_54A9(void);
void p24_L_54D1(void);
void p24_L_5580(void);
void p24_L_55EA(void);
void p24_L_55F6(void);
void p24_L_560B(void);
void p24_L_5639(void);
void p24_L_5647(void);
void p24_L_5655(void);
void p24_L_566C(void);
void p24_L_567E(void);
void p24_L_5694(void);
void p24_L_569C(void);
void p24_L_56A4(void);
void p24_L_56AC(void);
void p24_L_56B4(void);
void p24_L_56BA(void);
void p24_L_56C2(void);
void p24_L_5721(void);
void p24_L_5732(void);
void p24_L_5744(void);
void p24_L_576B(void);
void p24_L_5789(void);
void p24_L_5809(void);
void p24_L_5825(void);
void p24_L_5858(void);
void p24_L_585B(void);
void p24_L_5869(void);
void p24_L_5877(void);
void p24_L_5883(void);
void p24_L_58A2(void);
void p24_L_58A8(void);
void p24_L_5905(void);
void p24_L_5910(void);
void p24_L_5920(void);
void p24_L_5923(void);
void p24_L_592F(void);
void p24_L_5932(void);
void p24_L_593D(void);
void p24_L_595E(void);
void p24_L_5971(void);
void p24_L_5974(void);
void p24_L_5A59(void);
void p24_L_5A7A(void);
void p24_L_5A80(void);
void p24_L_5A83(void);
void p24_L_5AB3(void);
void p24_L_5AC8(void);
void p24_L_5AD1(void);
void p24_L_5AE6(void);
void p24_L_5B08(void);
void p24_L_5B18(void);
void p24_L_5B50(void);
void p24_L_5B77(void);
void p24_L_5BAF(void);
void p24_L_5BE1(void);
void p24_L_5BE5(void);
void p24_L_5BEC(void);
void p24_L_5CAB(void);
void p24_L_5CB8(void);
void p24_L_5CBA(void);
void p24_L_5D75(void);
void p24_L_5DBF(void);
void p24_L_5DCC(void);
void p24_L_5DDB(void);
void p24_L_5DF2(void);
void p24_L_5DFC(void);
void p24_L_5EA0(void);
void p24_L_5ECA(void);
void p24_L_5F2A(void);
void p24_L_5F3E(void);
void p24_L_5F41(void);
void p24_L_6026(void);
void p24_L_6039(void);
void p24_L_603F(void);
void p24_L_604D(void);
void p24_L_60E8(void);
void p24_L_60FF(void);
void p24_L_610F(void);
void p24_L_6117(void);
void p24_L_611F(void);
void p24_L_6127(void);
void p24_L_6128(void);
void p24_L_614F(void);
void p24_L_6157(void);
void p24_L_615D(void);
void p24_L_6171(void);
void p24_L_61A2(void);
void p24_L_61C7(void);
void p24_L_6223(void);
void p24_L_6225(void);
void p24_L_6227(void);
void p24_L_6297(void);
void p24_L_629D(void);
void p24_L_6311(void);
void p24_L_646D(void);
void p24_L_6475(void);
void p24_L_64C4(void);
void p24_L_6506(void);
void p24_L_6510(void);
void p24_L_6531(void);
void p24_L_6545(void);
void p24_L_654E(void);
void p24_L_6557(void);
void p24_L_65DF(void);
void p24_L_660B(void);
void p24_L_661D(void);
void p24_L_663A(void);
void p24_L_663F(void);
void p24_L_6644(void);
void p24_L_6649(void);
void p24_L_664C(void);
void p24_L_664F(void);
void p24_L_6661(void);
void p24_L_66C4(void);
void p24_L_66D7(void);
void p24_L_66D9(void);
void p24_L_67DA(void);
void p24_L_67EC(void);
void p24_L_6846(void);
void p24_L_684A(void);
void p24_L_6852(void);
void p24_L_685A(void);
void p24_L_686A(void);
void p24_L_6873(void);
void p24_L_688A(void);
void p24_L_6895(void);
void p24_L_689B(void);
void p24_L_68C7(void);
void p24_L_6949(void);
void p24_L_694C(void);
void p24_L_6984(void);
void p24_L_69DA(void);
void p24_L_6A0B(void);
void p24_L_6B1A(void);
void p24_L_6B23(void);
void p24_L_6B2B(void);
void p24_L_6CA6(void);
void p24_L_6CBB(void);
void p24_L_6CC3(void);
void p24_L_6CDA(void);
void p24_L_6D35(void);
void p24_L_6D4B(void);
void p24_L_6D98(void);
void p24_L_6E9E(void);
void p24_L_6ECE(void);
void p24_L_6F3E(void);
void p24_L_6F41(void);
void p24_L_6F48(void);
void p24_L_6F4B(void);
void p24_L_6F56(void);
void p24_L_6F5C(void);
void p24_L_6F5F(void);
void p24_L_6F64(void);
void p24_L_6F71(void);
void p24_L_6FC0(void);
void p24_L_7001(void);
void p24_L_7002(void);
void p24_L_7005(void);
void p24_L_700C(void);
void p24_L_7019(void);
void p24_L_7020(void);
void p24_L_7026(void);
void p24_L_702C(void);
void p24_L_703E(void);
void p24_L_7046(void);
void p24_L_7049(void);
void p24_L_7071(void);
void p24_L_7093(void);
void p24_L_7096(void);
void p24_L_7099(void);
void p24_L_709E(void);
void p24_L_70AC(void);
void p24_L_70B8(void);
void p24_L_70CD(void);
void p24_L_70D9(void);
void p24_L_714B(void);
void p24_L_71CD(void);
void p24_L_71E1(void);
void p24_L_71E4(void);
void p24_L_71E7(void);
void p24_L_71F8(void);
void p24_L_7216(void);
void p24_L_7238(void);
void p24_L_723C(void);
void p24_L_725D(void);
void p24_L_7261(void);
void p24_L_7265(void);
void p24_L_726F(void);
void p24_L_735A(void);
void p24_L_735F(void);
void p24_L_7370(void);
void p24_L_7395(void);
void p24_L_739A(void);
void p24_L_73A3(void);
void p24_L_73D5(void);
void p24_L_73DF(void);
void p24_L_748D(void);
void p24_L_7498(void);
void p24_L_74A8(void);
void p24_L_74B1(void);
void p24_L_74C2(void);
void p24_L_74C9(void);
void p24_L_74DA(void);
void p24_L_74F1(void);
void p24_L_7516(void);
void p24_L_7527(void);
void p24_L_752A(void);
void p24_L_759D(void);
void p24_L_75AC(void);
void p24_L_75DE(void);
void p24_L_76B4(void);
void p24_L_7AE4(void);
void p24_L_7B10(void);
void p24_L_7B21(void);
void p24_L_7B2A(void);
void p24_L_7BB4(void);
void p24_L_7BD5(void);
void p24_L_7CE0(void);
void p24_L_7D37(void);
void p24_L_7D40(void);
void p24_L_7D49(void);
void p24_L_7D57(void);
void p24_L_7D5D(void);
void p24_L_7EA6(void);
void p24_L_7EAD(void);
void p24_L_7EEC(void);
void p24_L_7EF2(void);
void p24_L_7EFA(void);
void p24_L_7F00(void);
void p24_L_7F2E(void);
void p24_L_7F3A(void);
void p24_L_7F5E(void);
void p24_L_7F6C(void);
void p24_L_7F94(void);

/* flash page 24 cpu 0x4000 (offset 0x0000) */
void p24_L_4000(void) {
  d = mem_read8(hl());
  b = c;
  a = l;
  b = l;
  /* db 0xDD */
  b = c;
  a = (uint8_t)(a + e);
  b = c;
  a = (uint8_t)(a - b);
  b = c;
  /* sbc a,h */
  b = c;
  cpu_pop_bc();
  b = c;
  cpu_pop_hl();
  b = c;
  b = a;
  b = a;
  h = a;
  b = a;
  set_bc((uint16_t)(bc() - 1));
  b = a;
  /* ei */
  b = c;
  h = 0x42;
  set_hl((uint16_t)(hl() + hl()));
  b = d;
  flag_cmp(a, 0x43);
  /* ld b,iyh */
  l = (uint8_t)(l + 1);
  b = l;
  flag_cmp(a, c);
  b = a;
  b = d;
  b = a;
  /* daa */
  b = a;
  hw_out(0x48, a);
  p00_rst10();
  b = e;
  a = hw_in(0x43);
  h = l;
  c = e;
  /* nop */
  /* nop */
  a = a & a;
  flag_logic(a);
  b = c;
  a = (uint8_t)(a + b);
  b = l;
  /* adc a,d */
  c = b;
  /* xor (hl) */
  c = b;
  a = a;
  b = e;
  flag_cmp(a, l);
  b = d;
  /* jp nz,0xD642 - other page/RAM */
  b = d;
  a = hw_in(0x42);
  if (flag_po()) return;
  b = d;
  cpu_pop_de();
  b = d;
  cpu_push_hl();
  b = d;
  if (flag_pe()) return;
  c = e;
  l = 0x47;
  /* jp pe,0xEF42 - other page/RAM */
  b = d;
  /* scf */
  c = h;
  l = (uint8_t)(l - 1);
  c = h;
  mem_write8(0xCC4C, a);
  b = d;
  a = a | e;
  flag_logic(a);
  b = d;
  flag_cmp(a, b);
  b = d;
  p00_rst00_boot();
  b = d;
  l = d;
  c = c;
  l = d;
  c = c;
  l = d;
  c = c;
  l = d;
  c = c;
  a = mem_read8(bc());
  d = d;
  /* sbc a,l */
  d = d;
  /* adc a,d */
  c = c;
  /* adc a,(hl) */
  c = c;
  mem_write8(hl(), b);
  c = c;
  c = mem_read8(hl());
  c = c;
  c = d;
  c = c;
  set_bc((uint16_t)(bc() - 1));
  d = mem_read8(hl());
  h = mem_read8(hl());
  c = c;
  d = d;
  c = c;
  d = mem_read8(hl());
  c = c;
  e = d;
  c = c;
  e = 0x49;
  a = b;
  c = c;
  mem_write8(hl(), h);
  c = c;
  h = d;
  c = c;
  e = mem_read8(hl());
  c = c;
  cpu_pop_de();
  d = h;
  set_hl((uint16_t)(hl() + sp));
  d = mem_read8(hl());
  b = a;
  d = mem_read8(hl());
  d = l;
  d = mem_read8(hl());
  l = h;
  d = mem_read8(hl());
  a = mem_read8(hl());
  d = mem_read8(hl());
  a = (uint8_t)(a - h);
  d = mem_read8(hl());
  /* sbc a,h */
  d = mem_read8(hl());
  set_bc((uint16_t)(bc() + 1));
  d = h;
  a = a ^ e;
  flag_logic(a);
  b = l;
  cpu_rlca();
  d = h;
  a = e;
  d = h;
  c = h;
  d = h;
  cpu_ex_de_hl();
  b = c;
  /* call 0xEA49 - RAM/other */
  d = l;
  cpu_push_de();
  h = (uint8_t)(h + 1);
  cpu_push_de();
  h = (uint8_t)(h + 1);
  if (flag_nc()) p00_L_3153();
  c = b;
  a = a & h;
  flag_logic(a);
  d = mem_read8(hl());
  a = a ^ h;
  flag_logic(a);
  d = mem_read8(hl());
  a = a | h;
  flag_logic(a);
  d = mem_read8(hl());
  flag_cmp(a, d);
  d = mem_read8(hl());
  a = (uint8_t)(a - 0x40);
  if (flag_nc()) { p00_L_2140(); return; }
  d = a;
  p24_L_40C0();
  return;
}

/* flash page 24 cpu 0x40C0 (offset 0x00C0) */
void p24_L_40C0(void) {
  p24_L_7005();
  flag_cmp(a, 0x5F);
  if (flag_nz()) { p00_L_24D5(); return; }
  p24_L_5DCC();
  mem_write8(hl(), 0x05);
  b = 0x09;
  p24_L_5DFC();
  return;
}

/* flash page 24 cpu 0x40D2 (offset 0x00D2) */
void p24_L_40D2(void) {
  p00_L_2FBB();
  p24_L_40D5();
  return;
}

/* flash page 24 cpu 0x40D5 (offset 0x00D5) */
void p24_L_40D5(void) {
  return;
}

/* flash page 24 cpu 0x40D6 (offset 0x00D6) */
void p24_L_40D6(void) {
  p24_L_40C0();
  p24_L_7093();
  if (flag_nz()) p24_L_4217();
  p00_L_2FC1();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  return;
}

/* flash page 24 cpu 0x40E3 (offset 0x00E3) */
void p24_L_40E3(void) {
  /* rlc a */
  /* add a,(hl) */
  return;
}

/* flash page 24 cpu 0x40E7 (offset 0x00E7) */
void p24_L_40E7(void) {
  set_de(0x0000);
  lab_p24_L_40EA: ;
  p24_L_7019();
  if (flag_c()) return;
  flag_cmp(a, 0xD0);
  if (flag_nz()) goto lab_p24_L_4102;
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_410D;
  a = 0xD0;
  lab_p24_L_40F8: ;
  mem_write16(0x965D, bc());
  cpu_push_af();
  p24_L_5BE1();
  p24_L_4100();
  return;
  lab_p24_L_4102: ;
  flag_cmp(a, 0xD4);
  if (flag_nz()) goto lab_p24_L_4114;
  a = d;
  a = a | e;
  flag_logic(a);
  a = 0xD4;
  if (flag_z()) goto lab_p24_L_40F8;
  set_de((uint16_t)(de() - 1));
  lab_p24_L_410D: ;
  cpu_push_de();
  p24_L_4137();
  cpu_pop_de();
  goto lab_p24_L_40EA;
  lab_p24_L_4114: ;
  flag_cmp(a, 0xD3);
  if (flag_nz()) goto lab_p24_L_411B;
  lab_p24_L_4118: ;
  set_de((uint16_t)(de() + 1));
  goto lab_p24_L_410D;
  lab_p24_L_411B: ;
  flag_cmp(a, 0xD1);
  if (flag_z()) goto lab_p24_L_4118;
  flag_cmp(a, 0xD2);
  if (flag_z()) goto lab_p24_L_4118;
  flag_cmp(a, 0xCE);
  if (flag_nz()) goto lab_p24_L_410D;
  cpu_push_de();
  p24_L_4137();
  cpu_pop_de();
  p24_L_7019();
  if (flag_c()) return;
  flag_cmp(a, 0xCF);
  if (flag_nz()) goto lab_p24_L_40EA;
  set_de((uint16_t)(de() + 1));
  goto lab_p24_L_410D;
}

/* flash page 24 cpu 0x4100 (offset 0x0100) */
void p24_L_4100(void) {
  cpu_pop_af();
  return;
}

/* flash page 24 cpu 0x4137 (offset 0x0137) */
void p24_L_4137(void) {
  lab_p24_L_4137: ;
  p24_L_7093();
  mem_write16(0x965D, bc());
  if (flag_z()) return;
  flag_cmp(a, 0x2A);
  if (flag_nz()) goto lab_p24_L_414C;
  p24_L_5379();
  p24_L_7096();
  if (flag_nz()) goto lab_p24_L_4137;
  return;
  lab_p24_L_414C: ;
  p00_L_1730();
  if (flag_nz()) goto lab_p24_L_4137;
  p24_L_7005();
  goto lab_p24_L_4137;
}

/* flash page 24 cpu 0x4156 (offset 0x0156) */
void p24_L_4156(void) {
  p24_L_6FC0();
  if (flag_z()) { p00_L_24E5(); return; }
  p24_L_6F71();
  p24_L_7002();
  lab_p24_L_4162: ;
  if (flag_c()) { p00_L_24D5(); return; }
  p24_L_7019();
  if (flag_c()) goto lab_p24_L_4162;
  flag_cmp(a, 0xCF);
  if (flag_nz()) goto lab_p24_L_4179;
  mem_write16(0x965D, bc());
  p24_L_5BE1();
  cpu_pop_hl();
  p24_L_5825();
  return;
  lab_p24_L_4179: ;
  p00_rst18();
  p24_L_5370();
  if (flag_nz()) { p00_L_24DD(); return; }
  p24_L_4295();
  return;
}

/* flash page 24 cpu 0x4183 (offset 0x0183) */
void p24_L_4183(void) {
  p24_L_6FC0();
  if (flag_z()) { p00_L_24E5(); return; }
  p24_L_6F71();
  cpu_pop_hl();
  p24_L_5732();
  return;
}

/* flash page 24 cpu 0x4190 (offset 0x0190) */
void p24_L_4190(void) {
  goto lab_p24_L_4190;
  lab_p24_L_4186: ;
  if (flag_z()) { p00_L_24E5(); return; }
  p24_L_6F71();
  cpu_pop_hl();
  p24_L_5732();
  return;
  lab_p24_L_4190: ;
  p24_L_6FC0();
  if (flag_z()) goto lab_p24_L_4186;
  p24_L_6F71();
  cpu_pop_hl();
  p24_L_576B();
  return;
}

/* flash page 24 cpu 0x419C (offset 0x019C) */
void p24_L_419C(void) {
  b = 0x0E;
  p24_L_41B7();
  p24_L_7046();
  p24_L_4945();
  return;
}

/* flash page 24 cpu 0x41A7 (offset 0x01A7) */
void p24_L_41A7(void) {
  goto lab_p24_L_41A7;
  lab_p24_L_41A1: ;
  p24_L_7046();
  p24_L_4945();
  return;
  lab_p24_L_41A7: ;
  p24_L_7093();
  b = 0x14;
  p24_L_41B7();
  p24_L_7019();
  flag_cmp(a, 0x08);
  if (flag_z()) return;
  goto lab_p24_L_41A1;
}

/* flash page 24 cpu 0x41B7 (offset 0x01B7) */
void p24_L_41B7(void) {
  c = 0x01;
  p24_L_7498();
  a = 0x10;
  p24_L_74B1();
  return;
}

/* flash page 24 cpu 0x41C1 (offset 0x01C1) */
void p24_L_41C1(void) {
  a = 0x01;
  mem_write8(0x848E, a);
  p24_L_5BE1();
  p24_L_74C2();
  p24_L_74A8();
  cpu_pop_hl();
  cpu_push_bc();
  p24_L_709E();
  if (flag_z()) goto lab_p24_L_4223;
  p24_L_74A8();
  a = mem_read8(0x848E);
  return;
  lab_p24_L_4223: ;
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x41DD (offset 0x01DD) */
void p24_L_41DD(void) {
  goto lab_p24_L_41DD;
  lab_p24_L_41C3: ;
  mem_write8(0x848E, a);
  p24_L_5BE1();
  p24_L_74C2();
  p24_L_74A8();
  cpu_pop_hl();
  cpu_push_bc();
  p24_L_709E();
  if (flag_z()) goto lab_p24_L_4223;
  p24_L_74A8();
  a = mem_read8(0x848E);
  return;
  lab_p24_L_41DD: ;
  a = 0x02;
  goto lab_p24_L_41C3;
  lab_p24_L_4223: ;
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x41E1 (offset 0x01E1) */
void p24_L_41E1(void) {
  p24_L_5BE1();
  set_hl(mem_read16(0x965F));
  mem_write16(0x965D, hl());
  return;
}

/* flash page 24 cpu 0x41EB (offset 0x01EB) */
void p24_L_41EB(void) {
  p24_L_5BE1();
  set_hl(0x8DA9);
  mem_write16(0x8DA7, hl());
  set_hl(0x0000);
  mem_write16(0x8E29, hl());
  return;
}

/* flash page 24 cpu 0x41FB (offset 0x01FB) */
void p24_L_41FB(void) {
  p24_L_41E1();
  set_hl(mem_read16(0x9822));
  set_de(0x0009);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  set_hl(mem_read16(0x9826));
  set_de(0xFFF5);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9828, hl());
  return;
}

/* flash page 24 cpu 0x4213 (offset 0x0213) */
void p24_L_4213(void) {
  p24_L_7093();
  if (flag_z()) return;
  p24_L_4217();
  return;
}

/* flash page 24 cpu 0x4217 (offset 0x0217) */
void p24_L_4217(void) {
  mem_write16(0x965D, bc());
  p24_L_421B();
  return;
}

/* flash page 24 cpu 0x421B (offset 0x021B) */
void p24_L_421B(void) {
  flag_cmp(a, 0x11);
  if (flag_nz()) goto lab_p24_L_4223;
  p24_L_7093();
  if (flag_z()) return;
  lab_p24_L_4223: ;
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x4226 (offset 0x0226) */
void p24_L_4226(void) {
  goto lab_p24_L_4226;
  lab_p24_L_4223: ;
  p00_L_24D5();
  return;
  lab_p24_L_4226: ;
  a = 0;
  flag_logic(a);
  goto lab_p24_L_422B;
  lab_p24_L_422B: ;
  cpu_push_af();
  p24_L_7002();
  p24_L_7049();
  mem_write16(0x965D, bc());
  p24_L_6F4B();
  p00_L_2429();
  mem_write16(0x9196, de());
  a = a & 0x1F;
  flag_logic(a);
  lab_p24_L_4242: ;
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_L_1169();
  p24_L_725D();
  set_bc((uint16_t)(bc() - 1));
  mem_write16(0x965D, bc());
  a = a | a;
  flag_logic(a);
  p24_L_6F64();
  p24_L_4213();
  p24_L_7002();
  if (flag_c()) goto lab_p24_L_4223;
  p24_L_7019();
  if (flag_c()) goto lab_p24_L_4223;
  p00_rst18();
  p00_L_21CC();
  p24_L_5370();
  if (flag_nz()) goto lab_p24_L_4242;
  p00_L_1169();
  set_hl(mem_read16(0x9196));
  p00_rst20();
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_427B;
  p00_L_0C2A();
  goto lab_p24_L_427E;
  lab_p24_L_427B: ;
  p00_L_0C1B();
  lab_p24_L_427E: ;
  p00_rst08();
  p00_L_219B();
  p00_L_21E0();
  p24_L_615D();
  p00_L_1128();
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  if (flag_z()) p00_L_3AAD();
  cpu_pop_af();
  if (flag_nz()) p00_L_3AB3();
  p24_L_4295();
  return;
}

/* flash page 24 cpu 0x4229 (offset 0x0229) */
void p24_L_4229(void) {
  goto lab_p24_L_4229;
  lab_p24_L_4223: ;
  p00_L_24D5();
  return;
  lab_p24_L_4229: ;
  a = 0x01;
  cpu_push_af();
  p24_L_7002();
  p24_L_7049();
  mem_write16(0x965D, bc());
  p24_L_6F4B();
  p00_L_2429();
  mem_write16(0x9196, de());
  a = a & 0x1F;
  flag_logic(a);
  lab_p24_L_4242: ;
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_L_1169();
  p24_L_725D();
  set_bc((uint16_t)(bc() - 1));
  mem_write16(0x965D, bc());
  a = a | a;
  flag_logic(a);
  p24_L_6F64();
  p24_L_4213();
  p24_L_7002();
  if (flag_c()) goto lab_p24_L_4223;
  p24_L_7019();
  if (flag_c()) goto lab_p24_L_4223;
  p00_rst18();
  p00_L_21CC();
  p24_L_5370();
  if (flag_nz()) goto lab_p24_L_4242;
  p00_L_1169();
  set_hl(mem_read16(0x9196));
  p00_rst20();
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_427B;
  p00_L_0C2A();
  goto lab_p24_L_427E;
  lab_p24_L_427B: ;
  p00_L_0C1B();
  lab_p24_L_427E: ;
  p00_rst08();
  p00_L_219B();
  p00_L_21E0();
  p24_L_615D();
  p00_L_1128();
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  if (flag_z()) p00_L_3AAD();
  cpu_pop_af();
  if (flag_nz()) p00_L_3AB3();
  p24_L_4295();
  return;
}

/* flash page 24 cpu 0x4295 (offset 0x0295) */
void p24_L_4295(void) {
  p00_L_14C7();
  if (flag_z()) p24_L_4137();
  p24_L_49B8();
  return;
}

/* flash page 24 cpu 0x429E (offset 0x029E) */
void p24_L_429E(void) {
  b = 0x02;
  p24_L_42A0();
  return;
}

/* flash page 24 cpu 0x42A0 (offset 0x02A0) */
void p24_L_42A0(void) {
  p00_L_23CC();
  lab_p24_L_42A3: ;
  cpu_push_bc();
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_42B0;
  p00_L_23CF();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p24_L_42A3;
  return;
  lab_p24_L_42B0: ;
  p00_L_24DD();
  return;
}

/* flash page 24 cpu 0x42B3 (offset 0x02B3) */
void p24_L_42B3(void) {
  set_de(0x4F57);
  goto lab_p24_L_42F2;
  lab_p24_L_42F2: ;
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_4391();
  p24_L_431F();
  return;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x42B8 (offset 0x02B8) */
void p24_L_42B8(void) {
  set_de(0x4F5B);
  goto lab_p24_L_42F2;
  lab_p24_L_42F2: ;
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_4391();
  p24_L_431F();
  return;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x42BD (offset 0x02BD) */
void p24_L_42BD(void) {
  set_de(0x4F5F);
  goto lab_p24_L_42F2;
  lab_p24_L_42F2: ;
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_4391();
  p24_L_431F();
  return;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x42C2 (offset 0x02C2) */
void p24_L_42C2(void) {
  set_de(0x4F6F);
  goto lab_p24_L_42F2;
  lab_p24_L_42F2: ;
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_4391();
  p24_L_431F();
  return;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x42C7 (offset 0x02C7) */
void p24_L_42C7(void) {
  set_de(0x4F6B);
  goto lab_p24_L_42F2;
  lab_p24_L_42F2: ;
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_4391();
  p24_L_431F();
  return;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x42CC (offset 0x02CC) */
void p24_L_42CC(void) {
  set_de(0x4F63);
  goto lab_p24_L_42F2;
  lab_p24_L_42F2: ;
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_4391();
  p24_L_431F();
  return;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x42D1 (offset 0x02D1) */
void p24_L_42D1(void) {
  set_de(0x4F67);
  goto lab_p24_L_42F2;
  lab_p24_L_42F2: ;
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_4391();
  p24_L_431F();
  return;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x42D6 (offset 0x02D6) */
void p24_L_42D6(void) {
  set_de(0x4F7B);
  goto lab_p24_L_42F2;
  lab_p24_L_42F2: ;
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_4391();
  p24_L_431F();
  return;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x42DB (offset 0x02DB) */
void p24_L_42DB(void) {
  set_de(0x4F7F);
  goto lab_p24_L_42F2;
  lab_p24_L_42F2: ;
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_4391();
  p24_L_431F();
  return;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x42E0 (offset 0x02E0) */
void p24_L_42E0(void) {
  set_de(0x4F83);
  goto lab_p24_L_42F2;
  lab_p24_L_42F2: ;
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_4391();
  p24_L_431F();
  return;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x42E5 (offset 0x02E5) */
void p24_L_42E5(void) {
  set_de(0x4F87);
  goto lab_p24_L_42F2;
  lab_p24_L_42F2: ;
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_4391();
  p24_L_431F();
  return;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x42EA (offset 0x02EA) */
void p24_L_42EA(void) {
  set_de(0x4F8B);
  goto lab_p24_L_42F2;
  lab_p24_L_42F2: ;
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_4391();
  p24_L_431F();
  return;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x42EF (offset 0x02EF) */
void p24_L_42EF(void) {
  set_de(0x4F8F);
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_4391();
  p24_L_431F();
  return;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x431F (offset 0x031F) */
void p24_L_431F(void) {
  cpu_pop_hl();
  os_jp_hl();
  return;
}

/* flash page 24 cpu 0x4321 (offset 0x0321) */
void p24_L_4321(void) {
  flag_cmp(a, 0x10);
  cpu_push_af();
  if (flag_nz()) goto lab_p24_L_432A;
  mem_write16(0x965D, bc());
  lab_p24_L_432A: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8E67, a);
  lab_p24_L_432E: ;
  p24_L_7093();
  if (flag_z()) goto lab_p24_L_4374;
  flag_cmp(a, 0x5E);
  if (flag_z()) goto lab_p24_L_434C;
  flag_cmp(a, 0xEB);
  if (flag_z()) goto lab_p24_L_434C;
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p24_L_434C;
  cpu_pop_af();
  cpu_push_af();
  p24_L_54A9();
  mem_write16(0x982A, hl());
  a = mem_read8(0x8E67);
  goto lab_p24_L_4369;
  lab_p24_L_434C: ;
  p24_L_7046();
  p00_L_2EF5();
  if (flag_z()) { p00_L_24E1(); return; }
  p24_L_455D();
  a = 0x03;
  mem_write8(0x8478, a);
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  if (flag_z()) p24_L_7527();
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + 1);
  lab_p24_L_4369: ;
  flag_cmp(a, 0x0A);
  if (flag_z()) { p00_L_24E5(); return; }
  mem_write8(0x8E67, a);
  p00_rst18();
  goto lab_p24_L_432E;
  lab_p24_L_4374: ;
  cpu_pop_af();
  p00_L_219B();
  p24_L_5BE1();
  a = mem_read8(0x8E67);
  return;
}

/* flash page 24 cpu 0x437F (offset 0x037F) */
void p24_L_437F(void) {
  goto lab_p24_L_437F;
  lab_p24_L_42FD: ;
  p24_L_4321();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p24_L_431F(); return; }
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_4316;
  a = a | a;
  flag_logic(a);
  a = 0x01;
  if (flag_nz()) { p24_L_431F(); return; }
  p00_rst18();
  p24_L_4391();
  goto lab_p24_L_431D;
  lab_p24_L_4316: ;
  p24_L_4391();
  p00_rst18();
  p00_L_1179();
  lab_p24_L_431D: ;
  a = 0x03;
  p24_L_431F();
  return;
  lab_p24_L_437F: ;
  set_de(0x4F4E);
  p24_L_7093();
  cpu_push_de();
  if (flag_nz()) goto lab_p24_L_42FD;
  p24_L_43CF();
  a = 0x01;
  p24_L_431F();
  return;
}

/* flash page 24 cpu 0x4391 (offset 0x0391) */
void p24_L_4391(void) {
  p00_rst18();
  p24_L_43CF();
  p00_L_2196();
  p00_rst18();
  p00_L_21E0();
  a = 0x01;
  p24_L_43D1();
  p00_L_2196();
  a = 0x02;
  return;
}

/* flash page 24 cpu 0x43CF (offset 0x03CF) */
void p24_L_43CF(void) {
  a = 0x00;
  p24_L_43D1();
  return;
}

/* flash page 24 cpu 0x43D1 (offset 0x03D1) */
void p24_L_43D1(void) {
  p00_L_1682();
  p24_L_7527();
  return;
}

/* flash page 24 cpu 0x43D7 (offset 0x03D7) */
void p24_L_43D7(void) {
  b = 0x0C;
  goto lab_p24_L_43DD;
  lab_p24_L_43DD: ;
  p24_L_4913();
  return;
}

/* flash page 24 cpu 0x43DB (offset 0x03DB) */
void p24_L_43DB(void) {
  b = 0x0D;
  p24_L_4913();
  return;
}

/* flash page 24 cpu 0x43ED (offset 0x03ED) */
void p24_L_43ED(void) {
  a = 0;
  flag_logic(a);
  cpu_push_af();
  p00_L_3525();
  set_hl(0x8D1C);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = 0x04;
  p00_L_33B7();
  p24_L_4A36();
  return;
}

/* flash page 24 cpu 0x43FE (offset 0x03FE) */
void p24_L_43FE(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x8478, a);
  p24_L_7093();
  if (flag_z()) { p24_L_43ED(); return; }
  flag_cmp(a, 0x10);
  cpu_push_af();
  if (flag_nz()) goto lab_p24_L_4413;
  mem_write16(0x965D, bc());
  p24_L_7093();
  lab_p24_L_4413: ;
  p24_L_7265();
  if (flag_c()) goto lab_p24_L_4429;
  p24_L_6F5F();
  p24_L_5370();
  p00_L_1037();
  flag_cmp(a, 0x04);
  if (flag_nz()) { p00_L_24DD(); return; }
  p24_L_7005();
  lab_p24_L_4429: ;
  p00_L_1169();
  p24_L_448B();
  p24_L_7093();
  if (flag_z()) goto lab_p24_L_4447;
  mem_write16(0x965D, bc());
  flag_cmp(a, 0x11);
  lab_p24_L_443A: ;
  if (flag_nz()) { p00_L_24D5(); return; }
  cpu_pop_af();
  cpu_push_af();
  if (flag_nz()) goto lab_p24_L_443A;
  p24_L_7093();
  if (flag_nz()) goto lab_p24_L_443A;
  lab_p24_L_4447: ;
  cpu_pop_af();
  a = mem_read8(0x8479);
  cpu_push_af();
  p00_L_1130();
  a = mem_read8(0x8478);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_4460;
  p00_L_241E();
  set_hl(0x865F);
  p24_L_7EAD();
  goto lab_p24_L_4463;
  lab_p24_L_4460: ;
  p24_L_7EA6();
  lab_p24_L_4463: ;
  /* ei */
  cpu_pop_af();
  flag_cmp(a, 0xAA);
  if (flag_nz()) goto lab_p24_L_4485;
  set_hl(mem_read16(0x982C));
  cpu_push_hl();
  set_hl(mem_read16(0x982A));
  mem_write16(0x982C, hl());
  p24_L_7EFA();
  cpu_pop_hl();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  a = 0x04;
  mem_write8(0x8478, a);
  p24_L_44E4();
  goto lab_p24_L_4488;
  lab_p24_L_4485: ;
  p24_L_44CA();
  lab_p24_L_4488: ;
  p24_L_4FEF();
  return;
}

/* flash page 24 cpu 0x448B (offset 0x048B) */
void p24_L_448B(void) {
  p24_L_7002();
  cpu_push_af();
  cpu_push_bc();
  flag_cmp(a, 0x63);
  cpu_push_af();
  if (flag_z()) p24_L_7071();
  cpu_pop_af();
  if (flag_nz()) p24_L_7049();
  cpu_push_bc();
  p00_L_1171();
  cpu_pop_hl();
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p24_L_6F71();
  p00_rst18();
  p00_rst10();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  a = (uint8_t)(a + 0x03);
  l = a;
  h = 0x00;
  set_hl((uint16_t)(hl() + de()));
  a = 0x63;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  a = 0x40;
  mem_write8(hl(), a);
  p00_L_113A();
  cpu_pop_af();
  flag_cmp(a, 0x63);
  if (flag_z()) return;
  p00_L_241E();
  if (flag_nc()) p24_L_660B();
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 24 cpu 0x44CA (offset 0x04CA) */
void p24_L_44CA(void) {
  set_hl(mem_read16(0x982C));
  cpu_push_hl();
  set_hl(mem_read16(0x982A));
  mem_write16(0x982C, hl());
  p24_L_5AB3();
  p24_L_7F00();
  p00_L_1169();
  p24_L_5A80();
  p00_L_1130();
  cpu_pop_hl();
  p24_L_44E4();
  return;
}

/* flash page 24 cpu 0x44E4 (offset 0x04E4) */
void p24_L_44E4(void) {
  mem_write16(0x982C, hl());
  p00_L_171E();
  p00_L_1717();
  p00_L_2191();
  p00_L_2222();
  p00_L_113F();
  p24_L_5920();
  p24_L_7EF2();
  return;
}

/* flash page 24 cpu 0x44FD (offset 0x04FD) */
void p24_L_44FD(void) {
  p24_L_7093();
  if (flag_z()) { p00_L_24E5(); return; }
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  flag_cmp(a, 0x10);
  cpu_push_af();
  if (flag_nz()) goto lab_p24_L_4510;
  mem_write16(0x965D, bc());
  lab_p24_L_4510: ;
  p24_L_448B();
  p24_L_455D();
  p00_L_3DF5();
  p24_L_44CA();
  cpu_pop_af();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_af();
  mem_write16(0x982A, hl());
  p24_L_7093();
  if (flag_nz()) goto lab_p24_L_4510;
  cpu_pop_hl();
  cpu_pop_hl();
  p24_L_455A();
  return;
}

/* flash page 24 cpu 0x452C (offset 0x052C) */
void p24_L_452C(void) {
  p24_L_7093();
  if (flag_nz()) goto lab_p24_L_4537;
  p24_L_7F3A();
  /* ei */
  p24_L_455A();
  return;
  lab_p24_L_4537: ;
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  cpu_push_af();
  p24_L_725D();
  lab_p24_L_453F: ;
  p24_L_6F56();
  p24_L_455D();
  p24_L_5370();
  p24_L_7F5E();
  /* ei */
  cpu_pop_af();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_af();
  mem_write16(0x982A, hl());
  p24_L_7093();
  if (flag_nz()) goto lab_p24_L_453F;
  cpu_pop_hl();
  cpu_pop_hl();
  p24_L_455A();
  return;
}

/* flash page 24 cpu 0x455A (offset 0x055A) */
void p24_L_455A(void) {
  p24_L_4FEF();
  return;
}

/* flash page 24 cpu 0x455D (offset 0x055D) */
void p24_L_455D(void) {
  p24_L_7093();
  if (flag_z()) return;
  mem_write16(0x965D, bc());
  flag_cmp(a, 0x2B);
  if (flag_nz()) goto lab_p24_L_456F;
  p24_L_7093();
  if (flag_nz()) return;
  p24_L_457D();
  return;
  lab_p24_L_456F: ;
  flag_cmp(a, 0x11);
  if (flag_nz()) { p24_L_457D(); return; }
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_hl();
  if (flag_nz()) { p24_L_457D(); return; }
  p24_L_7093();
  if (flag_z()) return;
  p24_L_457D();
  return;
}

/* flash page 24 cpu 0x457D (offset 0x057D) */
void p24_L_457D(void) {
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x4580 (offset 0x0580) */
void p24_L_4580(void) {
  p24_L_7093();
  flag_cmp(a, 0x2A);
  if (flag_nz()) goto lab_p24_L_45A5;
  mem_write16(0x965D, bc());
  p24_L_7005();
  flag_cmp(a, 0x4C);
  if (flag_nz()) { p24_L_457D(); return; }
  p24_L_7093();
  if (flag_nz()) { p24_L_457D(); return; }
  set_hl(mem_read16(0x9B73));
  p00_L_3B55();
  p00_L_1179();
  p24_L_60FF();
  p24_L_455A();
  return;
  lab_p24_L_45A5: ;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) & ~(1u << 0)));
  goto lab_p24_L_45AF;
  lab_p24_L_45AF: ;
  p00_L_2D87();
  p24_L_7046();
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p24_L_45C0;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 2)));
  lab_p24_L_45C0: ;
  a = mem_read8(0x8479);
  p24_L_45C3();
  return;
}

/* flash page 24 cpu 0x45AB (offset 0x05AB) */
void p24_L_45AB(void) {
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 0)));
  p00_L_2D87();
  p24_L_7046();
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p24_L_45C0;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 2)));
  lab_p24_L_45C0: ;
  a = mem_read8(0x8479);
  p24_L_45C3();
  return;
}

/* flash page 24 cpu 0x45C3 (offset 0x05C3) */
void p24_L_45C3(void) {
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p24_L_45D7;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p24_L_4619;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) & ~(1u << 2)));
  goto lab_p24_L_4619;
  lab_p24_L_45D7: ;
  flag_cmp(a, 0x5C);
  if (flag_z()) goto lab_p24_L_4619;
  cpu_pop_af();
  lab_p24_L_45DC: ;
  p24_L_4213();
  set_hl(0x45FC);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 0)));
  /* di */
  a = 0x15;
  mem_write8(0x8672, a);
  p00_L_2D8D();
  p00_L_25C8();
  p24_L_455A();
  return;
  lab_p24_L_4619: ;
  b = a;
  cpu_pop_af();
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p24_L_45DC;
  cpu_push_bc();
  p00_rst18();
  p00_L_2429();
  p24_L_7005();
  cpu_pop_af();
  cpu_push_af();
  set_de(0x03E7);
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p24_L_4633;
  set_de(0x0063);
  lab_p24_L_4633: ;
  p24_L_46F7();
  cpu_pop_af();
  cpu_push_de();
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p24_L_468C;
  p24_L_7093();
  lab_p24_L_463F: ;
  if (flag_z()) { p00_L_24E5(); return; }
  flag_cmp(a, 0x2B);
  if (flag_nz()) { p00_L_24D5(); return; }
  mem_write16(0x965D, bc());
  p24_L_7093();
  if (flag_z()) goto lab_p24_L_463F;
  set_de(0x0063);
  p24_L_46F7();
  cpu_pop_bc();
  d = c;
  cpu_push_de();
  p24_L_7093();
  if (flag_z()) goto lab_p24_L_466A;
  flag_cmp(a, 0x11);
  if (flag_nz()) { p00_L_24D5(); return; }
  mem_write16(0x965D, bc());
  p24_L_4213();
  lab_p24_L_466A: ;
  p24_L_46D6();
  cpu_pop_de();
  a = h;
  flag_cmp(a, d);
  lab_p24_L_4670: ;
  if (flag_c()) { p00_L_24ED(); return; }
  a = l;
  flag_cmp(a, e);
  if (flag_c()) goto lab_p24_L_4670;
  cpu_push_de();
  p24_L_46E1();
  cpu_pop_bc();
  if (flag_nz()) goto lab_p24_L_4685;
  set_de(mem_read16(0x9311));
  p00_L_3B91();
  lab_p24_L_4685: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 3)));
  p24_L_4FEF();
  return;
  lab_p24_L_468C: ;
  p24_L_7093();
  if (flag_z()) goto lab_p24_L_469D;
  flag_cmp(a, 0x11);
  if (flag_nz()) { p00_L_24D5(); return; }
  mem_write16(0x965D, bc());
  p24_L_4213();
  lab_p24_L_469D: ;
  p24_L_46D6();
  cpu_pop_de();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) { p00_L_24ED(); return; }
  cpu_push_de();
  p00_rst18();
  cpu_pop_de();
  cpu_push_de();
  p24_L_46E1();
  cpu_pop_hl();
  if (flag_z()) goto lab_p24_L_46B6;
  p00_L_21A7();
  goto lab_p24_L_4685;
  lab_p24_L_46B6: ;
  cpu_push_hl();
  p00_L_1037();
  if (flag_z()) goto lab_p24_L_46C7;
  set_de(0x848B);
  set_hl(0x8489);
  set_bc(0x0009);
  /* lddr */
  lab_p24_L_46C7: ;
  p00_L_2191();
  p00_L_2222();
  p00_L_113F();
  cpu_pop_bc();
  p24_L_6B23();
  goto lab_p24_L_4685;
}

/* flash page 24 cpu 0x46D6 (offset 0x06D6) */
void p24_L_46D6(void) {
  p00_L_219B();
  p00_L_188D();
  mem_write16(0x9311, de());
  return;
}

/* flash page 24 cpu 0x46E1 (offset 0x06E1) */
void p24_L_46E1(void) {
  mem_write16(0x847F, de());
  a = 0x16;
  mem_write8(0x8672, a);
  a = 0xFF;
  mem_write8(0x848C, a);
  p00_L_2D8D();
  a = mem_read8(0x848C);
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 24 cpu 0x46F7 (offset 0x06F7) */
void p24_L_46F7(void) {
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  cpu_push_de();
  p24_L_6F56();
  p24_L_5370();
  cpu_pop_hl();
  p24_L_71E7();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  return;
}

/* flash page 24 cpu 0x470B (offset 0x070B) */
void p24_L_470B(void) {
  p24_L_6FC0();
  if (flag_z()) goto lab_p24_L_4720;
  p24_L_6F71();
  p00_rst18();
  p24_L_5370();
  p24_L_60FF();
  p24_L_7F94();
  p24_L_49B8();
  return;
  lab_p24_L_4720: ;
  p24_L_4811();
  p24_L_7F6C();
  return;
}

/* flash page 24 cpu 0x4727 (offset 0x0727) */
void p24_L_4727(void) {
  p24_L_5BE1();
  p24_L_7F2E();
  return;
}

/* flash page 24 cpu 0x472E (offset 0x072E) */
void p24_L_472E(void) {
  p24_L_5BE1();
  set_hl(0x91D9);
  p00_L_16FA();
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) | (1u << 6)));
  set_hl(0x0000);
  mem_write16(0x91E0, hl());
  return;
}

/* flash page 24 cpu 0x4742 (offset 0x0742) */
void p24_L_4742(void) {
  b = 0x0F;
  p24_L_4913();
  return;
}

/* flash page 24 cpu 0x4747 (offset 0x0747) */
void p24_L_4747(void) {
  p24_L_7005();
  if (flag_c()) { p24_L_457D(); return; }
  p24_L_5DBF();
  l = 0x00;
  h = a;
  cpu_push_hl();
  p24_L_7093();
  if (flag_z()) goto lab_p24_L_4765;
  p24_L_7005();
  p24_L_5DBF();
  cpu_pop_hl();
  l = a;
  cpu_push_hl();
  p24_L_5BE1();
  lab_p24_L_4765: ;
  cpu_pop_hl();
  return;
}

/* flash page 24 cpu 0x4767 (offset 0x0767) */
void p24_L_4767(void) {
  p24_L_4747();
  p24_L_476A();
  return;
}

/* flash page 24 cpu 0x476A (offset 0x076A) */
void p24_L_476A(void) {
  cpu_ex_de_hl();
  set_hl(mem_read16(0x965D));
  cpu_push_hl();
  set_hl(mem_read16(0x965B));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x965D, hl());
  cpu_push_de();
  goto lab_p24_L_479B;
  lab_p24_L_4779: ;
  cpu_push_de();
  lab_p24_L_477A: ;
  p24_L_7005();
  lab_p24_L_477D: ;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_47AF;
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p24_L_479B;
  flag_cmp(a, 0x3E);
  if (flag_z()) goto lab_p24_L_479B;
  p00_L_1730();
  if (flag_nz()) goto lab_p24_L_4792;
  p24_L_7005();
  goto lab_p24_L_477A;
  lab_p24_L_4792: ;
  flag_cmp(a, 0x2A);
  if (flag_nz()) goto lab_p24_L_477A;
  p24_L_5379();
  goto lab_p24_L_477D;
  lab_p24_L_479B: ;
  p24_L_7005();
  flag_cmp(a, 0xD6);
  if (flag_nz()) goto lab_p24_L_477D;
  p24_L_4747();
  cpu_pop_de();
  p00_L_192A();
  if (flag_nz()) goto lab_p24_L_4779;
  cpu_pop_de();
  p24_L_4FEF();
  return;
  lab_p24_L_47AF: ;
  cpu_pop_af();
  cpu_pop_hl();
  mem_write16(0x965D, hl());
  a = 0x14;
  p00_L_255F();
  return;
}

/* flash page 24 cpu 0x47B9 (offset 0x07B9) */
void p24_L_47B9(void) {
  p24_L_5BE1();
  p24_L_47BC();
  return;
}

/* flash page 24 cpu 0x47BC (offset 0x07BC) */
void p24_L_47BC(void) {
  p00_L_3525();
  p24_L_4FEF();
  return;
}

/* flash page 24 cpu 0x4811 (offset 0x0811) */
void p24_L_4811(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 2)) == 0);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  if (flag_z()) return;
  goto lab_p24_L_485F;
  lab_p24_L_485F: ;
  p00_L_3E4F();
  p00_L_33C3();
  p24_L_4FEF();
  return;
}

/* flash page 24 cpu 0x4831 (offset 0x0831) */
void p24_L_4831(void) {
  a = 0x65;
  goto lab_p24_L_4885;
  lab_p24_L_485C: ;
  p00_L_0087();
  p00_L_3E4F();
  p00_L_33C3();
  p24_L_4FEF();
  return;
  lab_p24_L_4885: ;
  p00_L_3537();
  goto lab_p24_L_485C;
}

/* flash page 24 cpu 0x488A (offset 0x088A) */
void p24_L_488A(void) {
  p24_L_7093();
  b = 0x17;
  if (flag_nz()) { p24_L_490D(); return; }
  b = 0x01;
  p24_L_4893();
  return;
}

/* flash page 24 cpu 0x4893 (offset 0x0893) */
void p24_L_4893(void) {
  set_hl(0x92D9);
  p24_L_489C();
  p24_L_489C();
  p24_L_489C();
  return;
}

/* flash page 24 cpu 0x489C (offset 0x089C) */
void p24_L_489C(void) {
  a = mem_read8(hl());
  c = a;
  a = a & 0x01;
  flag_logic(a);
  a = a ^ b;
  flag_logic(a);
  if (flag_nz()) p00_L_0087();
  a = c;
  a = a & 0xF0;
  flag_logic(a);
  a = a | b;
  flag_logic(a);
  mem_write8(hl(), a);
  set_de(0x0011);
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 24 cpu 0x48AE (offset 0x08AE) */
void p24_L_48AE(void) {
  p24_L_7093();
  b = 0x18;
  if (flag_nz()) { p24_L_490D(); return; }
  b = 0x00;
  p24_L_4893();
  return;
}

/* flash page 24 cpu 0x48D3 (offset 0x08D3) */
void p24_L_48D3(void) {
  p24_L_7005();
  set_bc((uint16_t)(bc() - 1));
  cpu_push_bc();
  p24_L_7265();
  if (flag_c()) goto lab_p24_L_48ED;
  mem_write16(0x965D, bc());
  p24_L_7005();
  flag_cmp(a, 0x62);
  lab_p24_L_48E6: ;
  if (flag_z()) { p00_L_24E1(); return; }
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p24_L_48E6;
  lab_p24_L_48ED: ;
  cpu_pop_hl();
  mem_write16(0x965D, hl());
  b = 0x0B;
  p24_L_4913();
  return;
}

/* flash page 24 cpu 0x490D (offset 0x090D) */
void p24_L_490D(void) {
  c = 0x01;
  p24_L_7498();
  return;
}

/* flash page 24 cpu 0x4913 (offset 0x0913) */
void p24_L_4913(void) {
  c = 0x01;
  p24_L_7498();
  a = 0x10;
  p24_L_74B1();
  return;
}

/* flash page 24 cpu 0x491E (offset 0x091E) */
void p24_L_491E(void) {
  b = 0x1A;
  p24_L_4913();
  return;
}

/* flash page 24 cpu 0x4938 (offset 0x0938) */
void p24_L_4938(void) {
  c = 0x01;
  p24_L_7498();
  a = 0x10;
  p24_L_74B1();
  p24_L_6F5C();
  p24_L_4945();
  return;
}

/* flash page 24 cpu 0x4945 (offset 0x0945) */
void p24_L_4945(void) {
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  return;
}

/* flash page 24 cpu 0x494A (offset 0x094A) */
void p24_L_494A(void) {
  b = 0x26;
  p24_L_4913();
  return;
}

/* flash page 24 cpu 0x494E (offset 0x094E) */
void p24_L_494E(void) {
  b = 0x25;
  p24_L_4913();
  return;
}

/* flash page 24 cpu 0x4952 (offset 0x0952) */
void p24_L_4952(void) {
  b = 0x29;
  p24_L_4913();
  return;
}

/* flash page 24 cpu 0x4956 (offset 0x0956) */
void p24_L_4956(void) {
  b = 0x2A;
  p24_L_4913();
  return;
}

/* flash page 24 cpu 0x495A (offset 0x095A) */
void p24_L_495A(void) {
  b = 0x2B;
  p24_L_4913();
  return;
}

/* flash page 24 cpu 0x495E (offset 0x095E) */
void p24_L_495E(void) {
  b = 0x30;
  goto lab_p24_L_497A;
  lab_p24_L_497A: ;
  cpu_push_bc();
  p24_L_7093();
  cpu_pop_bc();
  if (flag_nz()) { p24_L_490D(); return; }
  e = b;
  a = a ^ 0x00;
  flag_logic(a);
  p24_L_4EBD();
  return;
}

/* flash page 24 cpu 0x4962 (offset 0x0962) */
void p24_L_4962(void) {
  b = 0x2F;
  goto lab_p24_L_497A;
  lab_p24_L_497A: ;
  cpu_push_bc();
  p24_L_7093();
  cpu_pop_bc();
  if (flag_nz()) { p24_L_490D(); return; }
  e = b;
  a = a ^ 0x00;
  flag_logic(a);
  p24_L_4EBD();
  return;
}

/* flash page 24 cpu 0x4966 (offset 0x0966) */
void p24_L_4966(void) {
  b = 0x28;
  p24_L_490D();
  return;
}

/* flash page 24 cpu 0x496A (offset 0x096A) */
void p24_L_496A(void) {
  a = e;
  a = (uint8_t)(a + 0xEC);
  b = a;
  p24_L_4913();
  return;
}

/* flash page 24 cpu 0x4970 (offset 0x0970) */
void p24_L_4970(void) {
  b = 0x24;
  p24_L_4913();
  return;
}

/* flash page 24 cpu 0x4974 (offset 0x0974) */
void p24_L_4974(void) {
  b = 0x2E;
  goto lab_p24_L_497A;
  lab_p24_L_497A: ;
  cpu_push_bc();
  p24_L_7093();
  cpu_pop_bc();
  if (flag_nz()) { p24_L_490D(); return; }
  e = b;
  a = a ^ 0x00;
  flag_logic(a);
  p24_L_4EBD();
  return;
}

/* flash page 24 cpu 0x4978 (offset 0x0978) */
void p24_L_4978(void) {
  b = 0x2D;
  cpu_push_bc();
  p24_L_7093();
  cpu_pop_bc();
  if (flag_nz()) { p24_L_490D(); return; }
  e = b;
  a = a ^ 0x00;
  flag_logic(a);
  p24_L_4EBD();
  return;
}

/* flash page 24 cpu 0x498A (offset 0x098A) */
void p24_L_498A(void) {
  b = 0x22;
  p24_L_4913();
  return;
}

/* flash page 24 cpu 0x498E (offset 0x098E) */
void p24_L_498E(void) {
  b = 0x23;
  p24_L_490D();
  return;
}

/* flash page 24 cpu 0x49B8 (offset 0x09B8) */
void p24_L_49B8(void) {
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  p00_L_219B();
  p00_L_16BC();
  return;
}

/* flash page 24 cpu 0x49D4 (offset 0x09D4) */
void p24_L_49D4(void) {
  p24_L_49F6();
  p00_rst18();
  p24_L_6F48();
  p24_L_49F6();
  p00_rst18();
  p24_L_4213();
  a = 0;
  flag_logic(a);
  cpu_push_af();
  lab_p24_L_49E4: ;
  cpu_pop_af();
  p00_L_35B5();
  if (flag_z()) { p00_L_24FD(); return; }
  cpu_push_af();
  a = b;
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p24_L_49E4;
  cpu_pop_af();
  a = 0x69;
  goto lab_p24_L_4A11;
  lab_p24_L_4A11: ;
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  if (flag_z()) p00_L_3E55();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 5)));
  cpu_pop_af();
  p00_L_33B7();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 5)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) { p24_L_4FEF(); return; }
  a = mem_read8(0x8D17);
  a = (uint8_t)(a - 0x51);
  if (flag_z()) goto lab_p24_L_4A35;
  a = 0x01;
  lab_p24_L_4A35: ;
  cpu_push_af();
  p24_L_4A36();
  return;
}

/* flash page 24 cpu 0x49F6 (offset 0x09F6) */
void p24_L_49F6(void) {
  p24_L_7093();
  p24_L_49F9();
  return;
}

/* flash page 24 cpu 0x49F9 (offset 0x09F9) */
void p24_L_49F9(void) {
  p24_L_73DF();
  if (flag_c()) goto lab_p24_L_4A03;
  a = 0xEB;
  p24_L_7049();
  return;
  lab_p24_L_4A03: ;
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p24_L_4A09;
  flag_cmp(a, 0xEB);
  lab_p24_L_4A09: ;
  if (flag_z()) { p24_L_7046(); return; }
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x4A36 (offset 0x0A36) */
void p24_L_4A36(void) {
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 5)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x08)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p24_L_4A45;
  a = 0xAA;
  mem_write8(0x8477, a);
  lab_p24_L_4A45: ;
  p00_L_3F0F();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 7)));
  p00_L_3F21();
  p00_L_3EFD();
  p00_L_0189();
  if (flag_nz()) goto lab_p24_L_4A62;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p24_L_4A62;
  flag_cmp(a, 0x05);
  if (flag_c()) p00_L_33B7();
  lab_p24_L_4A60: ;
  goto lab_p24_L_4A45;
  lab_p24_L_4A62: ;
  cpu_pop_af();
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) goto lab_p24_L_4B52;
  p00_L_0189();
  if (flag_nz()) goto lab_p24_L_4B52;
  flag_set_z((a & (1u << 1)) == 0);
  cpu_push_af();
  a = 0x05;
  p00_L_33B7();
  cpu_pop_af();
  if (flag_nz()) goto lab_p24_L_4A7E;
  a = (uint8_t)(a | (1u << 1));
  cpu_push_af();
  goto lab_p24_L_4A60;
  lab_p24_L_4A7E: ;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x81);
  if (flag_nz()) goto lab_p24_L_4B52;
  p00_L_34C5();
  set_hl(0x4B4D);
  p00_L_25A2();
  set_hl(0x8D8F);
  p00_rst20();
  p00_rst18();
  p00_rst08();
  p24_L_6649();
  p00_rst18();
  p00_L_107E();
  if (flag_c()) { p00_L_2505(); return; }
  set_hl(0x0000);
  p00_L_1C40();
  mem_write16(0x84D3, de());
  mem_write16(0x9818, hl());
  p00_L_21D6();
  set_hl(0x0000);
  p00_L_1C40();
  mem_write16(0x84D5, de());
  mem_write16(0x981A, hl());
  p00_L_21D6();
  set_hl(mem_read16(0x918E));
  p00_L_0033();
  cpu_ex_de_hl();
  set_hl(0x0000);
  lab_p24_L_4AC9: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_de();
  cpu_push_hl();
  set_de(mem_read16(0x918E));
  p00_L_3AF5();
  p00_L_22C7();
  p00_L_107E();
  if (flag_c()) goto lab_p24_L_4B06;
  p00_L_231F();
  p00_L_107E();
  if (flag_c()) goto lab_p24_L_4AE5;
  if (flag_nz()) goto lab_p24_L_4B06;
  lab_p24_L_4AE5: ;
  set_de(mem_read16(0x84D3));
  a = 0x01;
  p00_L_38EB();
  p00_L_3B19();
  cpu_pop_hl();
  cpu_push_hl();
  set_de(mem_read16(0x9192));
  p00_L_3AF5();
  set_de(mem_read16(0x84D5));
  a = 0x01;
  p00_L_38EB();
  p00_L_3B19();
  lab_p24_L_4B06: ;
  cpu_pop_hl();
  cpu_pop_de();
  p00_L_192A();
  if (flag_nz()) goto lab_p24_L_4AC9;
  p00_L_22D9();
  p24_L_615D();
  p00_L_22D9();
  p24_L_615D();
  p00_L_22CF();
  a = mem_read8(0x8E63);
  set_de(0x92CA);
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p24_L_4B2E;
  set_de(0x92DB);
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p24_L_4B2E;
  set_de(0x92EC);
  lab_p24_L_4B2E: ;
  p00_L_25C8();
  set_hl(0x847A);
  cpu_push_hl();
  p00_L_118B();
  cpu_push_de();
  p00_L_2324();
  cpu_pop_de();
  cpu_pop_hl();
  p00_L_118B();
  p00_L_0087();
  set_bc(0x0024);
  p00_L_21AA();
  p24_L_47BC();
  return;
  lab_p24_L_4B52: ;
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 5)));
  a = 0;
  flag_logic(a);
  mem_write8(0x8445, a);
  a = 0xF0;
  mem_write8(0x8477, a);
  p00_L_34C5();
  p24_L_4B62();
  return;
}

/* flash page 24 cpu 0x4B62 (offset 0x0B62) */
void p24_L_4B62(void) {
  p24_L_4FEF();
  return;
}

/* flash page 24 cpu 0x4B65 (offset 0x0B65) */
void p24_L_4B65(void) {
  p24_L_6D98();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x4BD3);
  p00_L_25A2();
  p24_L_5AB3();
  p00_L_3189();
  /* ei */
  p00_L_25C8();
  a = 0xAA;
  mem_write8(0x8477, a);
  lab_p24_L_4B81: ;
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  cpu_push_hl();
  p00_L_3F21();
  p00_L_0189();
  if (flag_nz()) goto lab_p24_L_4BA5;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p24_L_4BA5;
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p24_L_4B81;
  set_hl(0x4BD3);
  p00_L_25A2();
  p00_L_31AD();
  p00_L_25C8();
  /* ei */
  goto lab_p24_L_4B81;
  lab_p24_L_4BA5: ;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 2)));
  p00_L_320D();
  p24_L_7D37();
  p00_L_219B();
  p24_L_5A83();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x8445, a);
  a = 0xF0;
  mem_write8(0x8477, a);
  p00_L_2FD3();
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  p24_L_4B62();
  return;
}

/* flash page 24 cpu 0x4BE8 (offset 0x0BE8) */
void p24_L_4BE8(void) {
  p24_L_7005();
  flag_cmp(a, 0x10);
  cpu_push_af();
  if (flag_nz()) goto lab_p24_L_4BF3;
  lab_p24_L_4BF0: ;
  p24_L_7005();
  lab_p24_L_4BF3: ;
  p24_L_7049();
  p00_L_182A();
  if (flag_nz()) goto lab_p24_L_4C20;
  p00_rst10();
  if (flag_c()) goto lab_p24_L_4C0E;
  p00_L_2420();
  p00_L_17E6();
  p00_rst10();
  p00_L_1F58();
  set_hl(0x0000);
  p00_L_1C46();
  lab_p24_L_4C0E: ;
  p24_L_7093();
  if (flag_z()) goto lab_p24_L_4C29;
  p24_L_7005();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_4C29;
  flag_cmp(a, 0x2B);
  if (flag_z()) goto lab_p24_L_4BF0;
  b = a;
  cpu_pop_af();
  a = b;
  lab_p24_L_4C20: ;
  if (flag_nz()) { p00_L_24D5(); return; }
  flag_cmp(a, 0x11);
  if (flag_nz()) goto lab_p24_L_4C20;
  p24_L_4C2A();
  return;
  lab_p24_L_4C29: ;
  cpu_pop_af();
  p24_L_4C2A();
  return;
}

/* flash page 24 cpu 0x4C2A (offset 0x0C2A) */
void p24_L_4C2A(void) {
  p24_L_4B62();
  return;
}

/* flash page 24 cpu 0x4C2D (offset 0x0C2D) */
void p24_L_4C2D(void) {
  set_de(0x92DA);
  goto lab_p24_L_4C3A;
  lab_p24_L_4C3A: ;
  cpu_push_de();
  p24_L_7005();
  b = 0x00;
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p24_L_4C7F;
  lab_p24_L_4C44: ;
  p24_L_538F();
  p24_L_53C8();
  set_hl(0x847A);
  p00_L_118B();
  p24_L_53C8();
  set_hl(0x847A);
  p00_L_118B();
  lab_p24_L_4C59: ;
  p24_L_53B4();
  lab_p24_L_4C5C: ;
  p24_L_7005();
  lab_p24_L_4C5F: ;
  b = 0x00;
  flag_cmp(a, 0x7F);
  if (flag_z()) goto lab_p24_L_4C6A;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x80);
  if (flag_nz()) goto lab_p24_L_4C77;
  lab_p24_L_4C6A: ;
  cpu_pop_de();
  a = b;
  p00_L_12B9();
  cpu_ex_de_hl();
  /* or (hl) */
  mem_write8(hl(), a);
  p24_L_4213();
  p24_L_4C2A();
  return;
  lab_p24_L_4C77: ;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x81);
  if (flag_z()) goto lab_p24_L_4C6A;
  p24_L_4D1B();
  return;
  lab_p24_L_4C7F: ;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0xFD);
  if (flag_z()) goto lab_p24_L_4C44;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0xBB);
  if (flag_nz()) goto lab_p24_L_4CBB;
  p24_L_7005();
  b = 0x02;
  flag_cmp(a, 0x5A);
  if (flag_z()) goto lab_p24_L_4CC5;
  b = 0x05;
  flag_cmp(a, 0x5B);
  if (flag_nz()) { p00_L_24D5(); return; }
  p24_L_538F();
  p24_L_53C8();
  set_hl(0x847A);
  p00_L_118B();
  p24_L_53B4();
  p24_L_7005();
  flag_cmp(a, 0x58);
  if (flag_z()) goto lab_p24_L_4C59;
  flag_cmp(a, 0x59);
  if (flag_nz()) goto lab_p24_L_4C5F;
  set_hl(0x000A);
  set_hl((uint16_t)(hl() + de()));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 4)));
  goto lab_p24_L_4C59;
  lab_p24_L_4CBB: ;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p24_L_4CC5;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p24_L_4D16;
  lab_p24_L_4CC5: ;
  a = b;
  mem_write8(0x8483, a);
  p24_L_538F();
  p24_L_53C8();
  set_hl(0x847A);
  p00_L_118B();
  p24_L_53B4();
  p24_L_7093();
  flag_cmp(a, 0x82);
  if (flag_nc()) goto lab_p24_L_4CEE;
  flag_cmp(a, 0x7F);
  if (flag_c()) goto lab_p24_L_4CEE;
  b = a;
  a = mem_read8(0x8483);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p24_L_4C5C;
  p24_L_4D1B();
  return;
  lab_p24_L_4CEE: ;
  set_hl(0x0005);
  set_hl((uint16_t)(hl() + de()));
  flag_cmp(a, 0x31);
  if (flag_nz()) goto lab_p24_L_4CFC;
  mem_write16(0x965D, bc());
  goto lab_p24_L_4D07;
  lab_p24_L_4CFC: ;
  cpu_push_hl();
  p24_L_49F9();
  cpu_pop_de();
  set_hl(0x847A);
  p00_L_118B();
  lab_p24_L_4D07: ;
  a = mem_read8(0x8483);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p24_L_4C59;
  cpu_pop_de();
  p24_L_4213();
  p24_L_4C2A();
  return;
  lab_p24_L_4D16: ;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p24_L_4CC5;
  p24_L_4D1B();
  return;
}

/* flash page 24 cpu 0x4C32 (offset 0x0C32) */
void p24_L_4C32(void) {
  set_de(0x92EB);
  goto lab_p24_L_4C3A;
  lab_p24_L_4C3A: ;
  cpu_push_de();
  p24_L_7005();
  b = 0x00;
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p24_L_4C7F;
  lab_p24_L_4C44: ;
  p24_L_538F();
  p24_L_53C8();
  set_hl(0x847A);
  p00_L_118B();
  p24_L_53C8();
  set_hl(0x847A);
  p00_L_118B();
  lab_p24_L_4C59: ;
  p24_L_53B4();
  lab_p24_L_4C5C: ;
  p24_L_7005();
  lab_p24_L_4C5F: ;
  b = 0x00;
  flag_cmp(a, 0x7F);
  if (flag_z()) goto lab_p24_L_4C6A;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x80);
  if (flag_nz()) goto lab_p24_L_4C77;
  lab_p24_L_4C6A: ;
  cpu_pop_de();
  a = b;
  p00_L_12B9();
  cpu_ex_de_hl();
  /* or (hl) */
  mem_write8(hl(), a);
  p24_L_4213();
  p24_L_4C2A();
  return;
  lab_p24_L_4C77: ;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x81);
  if (flag_z()) goto lab_p24_L_4C6A;
  p24_L_4D1B();
  return;
  lab_p24_L_4C7F: ;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0xFD);
  if (flag_z()) goto lab_p24_L_4C44;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0xBB);
  if (flag_nz()) goto lab_p24_L_4CBB;
  p24_L_7005();
  b = 0x02;
  flag_cmp(a, 0x5A);
  if (flag_z()) goto lab_p24_L_4CC5;
  b = 0x05;
  flag_cmp(a, 0x5B);
  if (flag_nz()) { p00_L_24D5(); return; }
  p24_L_538F();
  p24_L_53C8();
  set_hl(0x847A);
  p00_L_118B();
  p24_L_53B4();
  p24_L_7005();
  flag_cmp(a, 0x58);
  if (flag_z()) goto lab_p24_L_4C59;
  flag_cmp(a, 0x59);
  if (flag_nz()) goto lab_p24_L_4C5F;
  set_hl(0x000A);
  set_hl((uint16_t)(hl() + de()));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 4)));
  goto lab_p24_L_4C59;
  lab_p24_L_4CBB: ;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p24_L_4CC5;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p24_L_4D16;
  lab_p24_L_4CC5: ;
  a = b;
  mem_write8(0x8483, a);
  p24_L_538F();
  p24_L_53C8();
  set_hl(0x847A);
  p00_L_118B();
  p24_L_53B4();
  p24_L_7093();
  flag_cmp(a, 0x82);
  if (flag_nc()) goto lab_p24_L_4CEE;
  flag_cmp(a, 0x7F);
  if (flag_c()) goto lab_p24_L_4CEE;
  b = a;
  a = mem_read8(0x8483);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p24_L_4C5C;
  p24_L_4D1B();
  return;
  lab_p24_L_4CEE: ;
  set_hl(0x0005);
  set_hl((uint16_t)(hl() + de()));
  flag_cmp(a, 0x31);
  if (flag_nz()) goto lab_p24_L_4CFC;
  mem_write16(0x965D, bc());
  goto lab_p24_L_4D07;
  lab_p24_L_4CFC: ;
  cpu_push_hl();
  p24_L_49F9();
  cpu_pop_de();
  set_hl(0x847A);
  p00_L_118B();
  lab_p24_L_4D07: ;
  a = mem_read8(0x8483);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p24_L_4C59;
  cpu_pop_de();
  p24_L_4213();
  p24_L_4C2A();
  return;
  lab_p24_L_4D16: ;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p24_L_4CC5;
  p24_L_4D1B();
  return;
}

/* flash page 24 cpu 0x4C37 (offset 0x0C37) */
void p24_L_4C37(void) {
  set_de(0x92C9);
  cpu_push_de();
  p24_L_7005();
  b = 0x00;
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p24_L_4C7F;
  lab_p24_L_4C44: ;
  p24_L_538F();
  p24_L_53C8();
  set_hl(0x847A);
  p00_L_118B();
  p24_L_53C8();
  set_hl(0x847A);
  p00_L_118B();
  lab_p24_L_4C59: ;
  p24_L_53B4();
  lab_p24_L_4C5C: ;
  p24_L_7005();
  lab_p24_L_4C5F: ;
  b = 0x00;
  flag_cmp(a, 0x7F);
  if (flag_z()) goto lab_p24_L_4C6A;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x80);
  if (flag_nz()) goto lab_p24_L_4C77;
  lab_p24_L_4C6A: ;
  cpu_pop_de();
  a = b;
  p00_L_12B9();
  cpu_ex_de_hl();
  /* or (hl) */
  mem_write8(hl(), a);
  p24_L_4213();
  p24_L_4C2A();
  return;
  lab_p24_L_4C77: ;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x81);
  if (flag_z()) goto lab_p24_L_4C6A;
  p24_L_4D1B();
  return;
  lab_p24_L_4C7F: ;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0xFD);
  if (flag_z()) goto lab_p24_L_4C44;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0xBB);
  if (flag_nz()) goto lab_p24_L_4CBB;
  p24_L_7005();
  b = 0x02;
  flag_cmp(a, 0x5A);
  if (flag_z()) goto lab_p24_L_4CC5;
  b = 0x05;
  flag_cmp(a, 0x5B);
  if (flag_nz()) { p00_L_24D5(); return; }
  p24_L_538F();
  p24_L_53C8();
  set_hl(0x847A);
  p00_L_118B();
  p24_L_53B4();
  p24_L_7005();
  flag_cmp(a, 0x58);
  if (flag_z()) goto lab_p24_L_4C59;
  flag_cmp(a, 0x59);
  if (flag_nz()) goto lab_p24_L_4C5F;
  set_hl(0x000A);
  set_hl((uint16_t)(hl() + de()));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 4)));
  goto lab_p24_L_4C59;
  lab_p24_L_4CBB: ;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p24_L_4CC5;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p24_L_4D16;
  lab_p24_L_4CC5: ;
  a = b;
  mem_write8(0x8483, a);
  p24_L_538F();
  p24_L_53C8();
  set_hl(0x847A);
  p00_L_118B();
  p24_L_53B4();
  p24_L_7093();
  flag_cmp(a, 0x82);
  if (flag_nc()) goto lab_p24_L_4CEE;
  flag_cmp(a, 0x7F);
  if (flag_c()) goto lab_p24_L_4CEE;
  b = a;
  a = mem_read8(0x8483);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p24_L_4C5C;
  p24_L_4D1B();
  return;
  lab_p24_L_4CEE: ;
  set_hl(0x0005);
  set_hl((uint16_t)(hl() + de()));
  flag_cmp(a, 0x31);
  if (flag_nz()) goto lab_p24_L_4CFC;
  mem_write16(0x965D, bc());
  goto lab_p24_L_4D07;
  lab_p24_L_4CFC: ;
  cpu_push_hl();
  p24_L_49F9();
  cpu_pop_de();
  set_hl(0x847A);
  p00_L_118B();
  lab_p24_L_4D07: ;
  a = mem_read8(0x8483);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p24_L_4C59;
  cpu_pop_de();
  p24_L_4213();
  p24_L_4C2A();
  return;
  lab_p24_L_4D16: ;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p24_L_4CC5;
  p24_L_4D1B();
  return;
}

/* flash page 24 cpu 0x4D1B (offset 0x0D1B) */
void p24_L_4D1B(void) {
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x4D28 (offset 0x0D28) */
void p24_L_4D28(void) {
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p00_L_34C5();
  p00_L_219B();
  p00_L_0189();
  if (flag_nz()) { p24_L_4C2A(); return; }
  p24_L_4E14();
  p00_L_1037();
  flag_cmp(a, 0x1F);
  if (flag_nz()) goto lab_p24_L_4D4B;
  p00_L_1CAC();
  mem_write16(0x84DD, de());
  mem_write16(0x981C, hl());
  goto lab_p24_L_4D5E;
  lab_p24_L_4D4B: ;
  a = 0x07;
  mem_write8(0x8478, a);
  set_de(0x02F6);
  set_hl(mem_read16(0x981C));
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_0087();
  p00_L_1CFC();
  lab_p24_L_4D5E: ;
  set_hl(mem_read16(0x84DD));
  set_bc(0x02F4);
  mem_write8(hl(), c);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), b);
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  set_hl(0x9340);
  while (bc() != 0) { cpu_ldi(); }
  p24_L_4FEF();
  return;
}

/* flash page 24 cpu 0x4DEA (offset 0x0DEA) */
void p24_L_4DEA(void) {
  d = 0x60;
  p24_L_4DEC();
  return;
}

/* flash page 24 cpu 0x4DEC (offset 0x0DEC) */
void p24_L_4DEC(void) {
  p24_L_7005();
  flag_cmp(a, 0x30);
  if (flag_c()) goto lab_p24_L_4E0E;
  flag_cmp(a, 0x3A);
  if (flag_nc()) goto lab_p24_L_4E0E;
  a = (uint8_t)(a - 0x31);
  if (flag_nc()) goto lab_p24_L_4DFD;
  a = 0x09;
  lab_p24_L_4DFD: ;
  cpu_push_af();
  p00_L_1295();
  a = d;
  mem_write8(0x8479, a);
  cpu_pop_af();
  mem_write8(0x847A, a);
  p24_L_5BE1();
  p24_L_4E14();
  return;
  lab_p24_L_4E0E: ;
  p24_L_7049();
  if (flag_nz()) { p00_L_24D5(); return; }
  p24_L_4E14();
  return;
}

/* flash page 24 cpu 0x4E14 (offset 0x0E14) */
void p24_L_4E14(void) {
  a = 0xFF;
  mem_write8(0x8478, a);
  p00_L_241E();
  mem_write16(0x981C, hl());
  mem_write16(0x84DD, de());
  p00_L_10DD();
  a = mem_read8(0x8479);
  return;
}

/* flash page 24 cpu 0x4EBD (offset 0x0EBD) */
void p24_L_4EBD(void) {
  mem_write16(0x848E, de());
  set_hl(0x4ED4);
  p00_L_25A2();
  set_de(mem_read16(0x848E));
  p00_L_3447();
  p00_L_25C8();
  p24_L_4FEF();
  return;
}

/* flash page 24 cpu 0x4FEF (offset 0x0FEF) */
void p24_L_4FEF(void) {
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  return;
}

/* flash page 24 cpu 0x4FF4 (offset 0x0FF4) */
void p24_L_4FF4(void) {
  p00_L_1037();
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_L_0FB5();
  p00_L_14C7();
  if (flag_z()) return;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x82);
  if (flag_nc()) { p00_L_24C9(); return; }
  p00_L_187F();
  p24_L_71F8();
  return;
}

/* flash page 24 cpu 0x50B0 (offset 0x10B0) */
void p24_L_50B0(void) {
  p24_L_4FEF();
  return;
}

/* flash page 24 cpu 0x50B3 (offset 0x10B3) */
void p24_L_50B3(void) {
  lab_p24_L_50B3: ;
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) return;
  set_bc((uint16_t)(bc() - 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_3C0F();
  if (flag_nc()) goto lab_p24_L_50BE;
  set_bc((uint16_t)(bc() - 1));
  lab_p24_L_50BE: ;
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_z()) return;
  cpu_push_hl();
  cpu_push_bc();
  a = 0x93;
  p00_L_3537();
  cpu_pop_bc();
  cpu_pop_hl();
  if (flag_c()) goto lab_p24_L_50B3;
  a = a | 0x01;
  flag_logic(a);
  return;
}

/* flash page 24 cpu 0x50CF (offset 0x10CF) */
void p24_L_50CF(void) {
  cpu_ex_de_hl();
  set_hl(mem_read16(0x9824));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_push_de();
  p00_rst20();
  cpu_pop_hl();
  p00_L_23CF();
  return;
}

/* flash page 24 cpu 0x51E8 (offset 0x11E8) */
void p24_L_51E8(void) {
  p24_L_6F5C();
  p24_L_5370();
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x04);
  if (flag_nz()) { p00_L_24DD(); return; }
  p24_L_6F48();
  p00_rst18();
  return;
}

/* flash page 24 cpu 0x51FA (offset 0x11FA) */
void p24_L_51FA(void) {
  l = b;
  h = 0x00;
  p00_L_1C40();
  mem_write16(0x84D7, de());
  mem_write16(0x9818, hl());
  p00_L_21D6();
  return;
}

/* flash page 24 cpu 0x520A (offset 0x120A) */
void p24_L_520A(void) {
  a = a | 0x01;
  flag_logic(a);
  p24_L_54A9();
  p00_L_1037();
  flag_cmp(a, 0x02);
  if (flag_nz()) { p00_L_24DD(); return; }
  p24_L_7093();
  if (flag_z()) { p00_L_24E5(); return; }
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p24_L_5264;
  flag_cmp(a, 0xEB);
  if (flag_z()) goto lab_p24_L_5264;
  p00_rst18();
  a = a | 0x01;
  flag_logic(a);
  p24_L_54A9();
  mem_write16(0x982A, hl());
  p00_L_1653();
  p24_L_71E4();
  cpu_push_af();
  p24_L_49F6();
  p24_L_4213();
  p00_rst18();
  p00_L_2315();
  p00_L_188D();
  mem_write16(0x84D3, de());
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, l);
  if (flag_c()) goto lab_p24_L_524E;
  if (flag_nz()) { p00_L_24ED(); return; }
  lab_p24_L_524E: ;
  cpu_push_hl();
  b = h;
  p24_L_51FA();
  p00_L_2315();
  cpu_pop_hl();
  cpu_pop_af();
  l = a;
  p24_L_52DF();
  set_bc(0x001B);
  p00_L_21AA();
  goto lab_p24_L_529A;
  lab_p24_L_5264: ;
  p00_L_188D();
  mem_write16(0x84D3, de());
  a = 0;
  flag_logic(a);
  p24_L_5580();
  c = 0x01;
  cpu_push_bc();
  p24_L_51FA();
  cpu_pop_hl();
  lab_p24_L_5276: ;
  cpu_push_hl();
  set_hl(mem_read16(0x9818));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  set_hl(mem_read16(0x9302));
  p00_rst20();
  mem_write16(0x9302, hl());
  cpu_pop_hl();
  cpu_push_hl();
  p24_L_52DF();
  cpu_pop_hl();
  l = (uint8_t)(l + 1);
  a = mem_read8(0x8E67);
  flag_cmp(a, l);
  if (flag_nc()) goto lab_p24_L_5276;
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + 1);
  l = a;
  h = 0x00;
  p00_L_21B2();
  lab_p24_L_529A: ;
  p24_L_4FEF();
  return;
}

/* flash page 24 cpu 0x529D (offset 0x129D) */
void p24_L_529D(void) {
  goto lab_p24_L_529D;
  lab_p24_L_529A: ;
  p24_L_4FEF();
  return;
  lab_p24_L_529D: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8E67, a);
  lab_p24_L_52A1: ;
  a = a | 0x01;
  flag_logic(a);
  p24_L_54A9();
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_nz()) { p00_L_24DD(); return; }
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  if (flag_z()) p24_L_7527();
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p24_L_52C5;
  p00_L_188D();
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) { p00_L_24ED(); return; }
  lab_p24_L_52C5: ;
  p00_rst18();
  p24_L_7093();
  if (flag_z()) { p00_L_24E5(); return; }
  flag_cmp(a, 0x5C);
  if (flag_nz()) goto lab_p24_L_52A1;
  p24_L_7046();
  p24_L_4213();
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + 1);
  p00_L_3B4F();
  goto lab_p24_L_529A;
}

/* flash page 24 cpu 0x52DF (offset 0x12DF) */
void p24_L_52DF(void) {
  cpu_push_hl();
  p00_L_10DD();
  cpu_pop_bc();
  lab_p24_L_52E4: ;
  cpu_push_bc();
  p00_L_3B79();
  cpu_pop_hl();
  cpu_push_hl();
  l = h;
  h = 0x00;
  p00_L_3B13();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p24_L_52E4;
  p00_L_22FC();
  p00_rst18();
  p00_L_1135();
  p24_L_615D();
  return;
}

/* flash page 24 cpu 0x52FE (offset 0x12FE) */
void p24_L_52FE(void) {
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  set_hl(mem_read16(0x9824));
  mem_write16(0x9311, hl());
  p24_L_51E8();
  a = 0;
  flag_logic(a);
  cpu_push_af();
  lab_p24_L_530D: ;
  p24_L_51E8();
  p24_L_7005();
  p24_L_5DBF();
  mem_write8(0x8479, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x8478, a);
  p24_L_7019();
  p24_L_73DF();
  if (flag_nc()) goto lab_p24_L_532D;
  flag_cmp(a, 0x30);
  if (flag_c()) goto lab_p24_L_5333;
  flag_cmp(a, 0x3A);
  if (flag_nc()) goto lab_p24_L_5333;
  lab_p24_L_532D: ;
  p24_L_7005();
  mem_write8(0x8478, a);
  lab_p24_L_5333: ;
  p00_rst18();
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  cpu_push_af();
  p24_L_7093();
  if (flag_z()) goto lab_p24_L_5347;
  mem_write16(0x965D, bc());
  flag_cmp(a, 0x2B);
  if (flag_z()) goto lab_p24_L_530D;
  p24_L_421B();
  lab_p24_L_5347: ;
  cpu_pop_af();
  flag_cmp(a, 0x08);
  if (flag_nc()) { p00_L_24E5(); return; }
  mem_write8(0x8478, a);
  p00_rst18();
  a = 0x13;
  p00_L_2E59();
  p00_L_0189();
  if (flag_nz()) { p00_L_2511(); return; }
  set_hl(mem_read16(0x9311));
  mem_write16(0x9824, hl());
  cpu_pop_de();
  p00_L_31F5();
  a = 0;
  flag_logic(a);
  mem_write8(0x8445, a);
  set_hl(mem_read16(0x8478));
  p24_L_476A();
  return;
}

/* flash page 24 cpu 0x5370 (offset 0x1370) */
void p24_L_5370(void) {
  p24_L_5920();
  p00_L_1717();
  p00_L_1037();
  return;
}

/* flash page 24 cpu 0x5379 (offset 0x1379) */
void p24_L_5379(void) {
  lab_p24_L_5379: ;
  p24_L_7005();
  if (flag_c()) return;
  p00_L_1730();
  if (flag_nz()) goto lab_p24_L_5387;
  p24_L_7005();
  goto lab_p24_L_5379;
  lab_p24_L_5387: ;
  flag_cmp(a, 0x2A);
  if (flag_z()) return;
  flag_cmp(a, 0x3F);
  if (flag_z()) return;
  goto lab_p24_L_5379;
}

/* flash page 24 cpu 0x538F (offset 0x138F) */
void p24_L_538F(void) {
  cpu_ex_de_hl();
  mem_write8(hl(), b);
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  cpu_ex_de_hl();
  p00_L_1295();
  set_hl(0x847A);
  p00_L_118B();
  set_hl(0x847A);
  mem_write8(hl(), 0x01);
  p00_L_118B();
  set_hl(0x847A);
  mem_write8(hl(), 0x31);
  p00_L_118B();
  cpu_ex_de_hl();
  mem_write8(hl(), 0x01);
  cpu_pop_de();
  p00_L_009B();
  return;
}

/* flash page 24 cpu 0x53B4 (offset 0x13B4) */
void p24_L_53B4(void) {
  p24_L_7093();
  if (flag_z()) goto lab_p24_L_53C3;
  mem_write16(0x965D, bc());
  flag_cmp(a, 0x2B);
  if (flag_z()) return;
  p24_L_421B();
  lab_p24_L_53C3: ;
  cpu_pop_af();
  cpu_pop_de();
  p24_L_4FEF();
  return;
}

/* flash page 24 cpu 0x53C8 (offset 0x13C8) */
void p24_L_53C8(void) {
  cpu_push_de();
  p00_L_1295();
  p24_L_6F48();
  p24_L_49F6();
  cpu_pop_de();
  return;
}

/* flash page 24 cpu 0x53CD (offset 0x13CD) */
void p24_L_53CD(void) {
  c = b;
  l = a;
  p24_L_49F6();
  cpu_pop_de();
  return;
}

/* flash page 24 cpu 0x53D4 (offset 0x13D4) */
void p24_L_53D4(void) {
  p24_L_5BE1();
  p00_L_18B7();
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 2)));
  p00_L_33A5();
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  p00_L_17FA();
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) | (1u << 6)));
  p24_L_7F2E();
  p00_L_0087();
  return;
}

/* flash page 24 cpu 0x5403 (offset 0x1403) */
void p24_L_5403(void) {
  p00_L_3B49();
  return;
}

/* flash page 24 cpu 0x5407 (offset 0x1407) */
void p24_L_5407(void) {
  p24_L_7046();
  p00_L_241E();
  if (flag_c()) return;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5E);
  if (flag_nz()) goto lab_p24_L_543A;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_nz()) p00_L_0087();
  p00_L_1F58();
  p00_L_1037();
  p00_L_1857();
  if (flag_nz()) return;
  p00_L_1C9D();
  a = mem_read8(0x849B);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) goto lab_p24_L_5439;
  a = a ^ 0x01;
  flag_logic(a);
  mem_write8(0x849B, a);
  p00_L_1135();
  p00_rst10();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 5)));
  lab_p24_L_5439: ;
  return;
  lab_p24_L_543A: ;
  p00_L_17E9();
  p00_L_19ED();
  p00_L_1F58();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  if (flag_z()) p00_L_321F();
  return;
}

/* flash page 24 cpu 0x544C (offset 0x144C) */
void p24_L_544C(void) {
  p24_L_6F5C();
  p24_L_5370();
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x04);
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_rst18();
  p24_L_6F48();
  p24_L_6F3E();
  flag_cmp(a, 0x5E);
  if (flag_nz()) goto lab_p24_L_5469;
  p24_L_7071();
  goto lab_p24_L_54A3;
  lab_p24_L_5469: ;
  flag_cmp(a, 0x41);
  if (flag_nc()) goto lab_p24_L_5470;
  lab_p24_L_546D: ;
  p00_L_24D5();
  return;
  lab_p24_L_5470: ;
  flag_cmp(a, 0xAA);
  if (flag_z()) goto lab_p24_L_5478;
  flag_cmp(a, 0x62);
  if (flag_nc()) goto lab_p24_L_546D;
  lab_p24_L_5478: ;
  p00_L_24DD();
  return;
  lab_p24_L_54A3: ;
  if (flag_nz()) p24_L_4217();
  p24_L_615D();
  return;
}

/* flash page 24 cpu 0x547B (offset 0x147B) */
void p24_L_547B(void) {
  goto lab_p24_L_547B;
  lab_p24_L_5469: ;
  flag_cmp(a, 0x41);
  if (flag_nc()) goto lab_p24_L_5470;
  lab_p24_L_546D: ;
  p00_L_24D5();
  return;
  lab_p24_L_5470: ;
  flag_cmp(a, 0xAA);
  if (flag_z()) goto lab_p24_L_5478;
  flag_cmp(a, 0x62);
  if (flag_nc()) goto lab_p24_L_546D;
  lab_p24_L_5478: ;
  p00_L_24DD();
  return;
  lab_p24_L_547B: ;
  p24_L_6F3E();
  flag_cmp(a, 0x5E);
  if (flag_nz()) goto lab_p24_L_5469;
  cpu_push_af();
  p24_L_7071();
  p24_L_6F48();
  cpu_pop_af();
  p00_L_2429();
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_5498;
  flag_cmp(a, 0x0B);
  if (flag_nz()) { p00_L_24DD(); return; }
  lab_p24_L_5498: ;
  p00_rst18();
  p24_L_6F3E();
  flag_cmp(a, 0xAA);
  if (flag_nz()) goto lab_p24_L_5469;
  p24_L_7071();
  if (flag_nz()) p24_L_4217();
  p24_L_615D();
  return;
}

/* flash page 24 cpu 0x54A9 (offset 0x14A9) */
void p24_L_54A9(void) {
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  cpu_push_af();
  p24_L_6F56();
  p24_L_455D();
  p00_rst18();
  p24_L_5370();
  p00_L_2191();
  p00_L_2222();
  p00_L_113F();
  p00_rst10();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  p00_L_2176();
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + 1);
  mem_write8(0x8E67, a);
  cpu_pop_af();
  cpu_pop_hl();
  return;
}

/* flash page 24 cpu 0x54D1 (offset 0x14D1) */
void p24_L_54D1(void) {
  p24_L_7093();
  if (flag_nz()) goto lab_p24_L_54DA;
  p00_L_2FB5();
  return;
  lab_p24_L_54DA: ;
  flag_cmp(a, 0x10);
  cpu_push_af();
  if (flag_z()) p24_L_7005();
  l = 0x14;
  a = 0x01;
  p24_L_5580();
  flag_cmp(a, 0x11);
  if (flag_nz()) goto lab_p24_L_54F0;
  cpu_pop_af();
  if (flag_nz()) { p00_L_24D5(); return; }
  cpu_push_af();
  lab_p24_L_54F0: ;
  cpu_pop_af();
  a = 0x01;
  mem_write8(0x970E, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x970F, a);
  mem_write8(0x9710, a);
  a = mem_read8(0x8E67);
  b = a;
  set_hl(mem_read16(0x9302));
  set_de(0x9711);
  lab_p24_L_5507: ;
  cpu_push_bc();
  cpu_push_de();
  p00_L_11F2();
  set_hl(0x5564);
  p00_L_25A2();
  p00_rst10();
  if (flag_c()) goto lab_p24_L_551F;
  p00_L_1F55();
  if (flag_z()) goto lab_p24_L_5525;
  p00_L_2F67();
  goto lab_p24_L_5525;
  lab_p24_L_551F: ;
  set_hl(0x0000);
  p00_L_1C46();
  lab_p24_L_5525: ;
  p00_L_25C8();
  set_hl(0x970E);
  a = mem_read8(hl());
  a = (uint8_t)(a - 1);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  l = a;
  h = 0x00;
  p00_L_1025();
  set_de(mem_read16(0x9302));
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_de();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_118B();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p24_L_5507;
  cpu_ex_de_hl();
  a = mem_read8(0x8E67);
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p24_L_5551;
  mem_write8(0x970E, a);
  goto lab_p24_L_555D;
  lab_p24_L_5551: ;
  mem_write8(hl(), 0x71);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p24_L_555D;
  set_de(0x0005);
  set_hl((uint16_t)(hl() + de()));
  mem_write8(hl(), 0x71);
  lab_p24_L_555D: ;
  set_hl(mem_read16(0x9302));
  mem_write16(0x9824, hl());
  return;
}

/* flash page 24 cpu 0x5580 (offset 0x1580) */
void p24_L_5580(void) {
  cpu_push_hl();
  cpu_push_af();
  p00_L_16B5();
  set_hl(0x0000);
  mem_write16(0x8E67, hl());
  lab_p24_L_558B: ;
  p24_L_7093();
  if (flag_z()) { p00_L_24E5(); return; }
  p24_L_49F6();
  a = mem_read8(0x8E67);
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_bc();
  flag_cmp(a, l);
  if (flag_z()) goto lab_p24_L_55D5;
  a = (uint8_t)(a + 1);
  mem_write8(0x8E67, a);
  flag_set_z((b & (1u << 1)) == 0);
  if (flag_z()) goto lab_p24_L_55AB;
  p24_L_7527();
  goto lab_p24_L_55D4;
  lab_p24_L_55AB: ;
  flag_set_z((b & (1u << 0)) == 0);
  if (flag_z()) goto lab_p24_L_55D4;
  set_hl(mem_read16(0x9302));
  set_de(0x0006);
  lab_p24_L_55B5: ;
  set_hl((uint16_t)(hl() + de()));
  set_de(mem_read16(0x9824));
  p00_L_192A();
  if (flag_nc()) goto lab_p24_L_55D4;
  cpu_push_hl();
  set_de(0x847E);
  b = 0x05;
  p00_L_3E3D();
  a = c;
  flag_cmp(a, 0x05);
  if (flag_z()) { p00_L_24FD(); return; }
  set_de(0x0009);
  cpu_pop_hl();
  goto lab_p24_L_55B5;
  lab_p24_L_55D4: ;
  p00_rst18();
  lab_p24_L_55D5: ;
  p24_L_7093();
  if (flag_z()) goto lab_p24_L_55E7;
  flag_cmp(a, 0x2B);
  if (flag_nz()) goto lab_p24_L_55E4;
  mem_write16(0x965D, bc());
  goto lab_p24_L_558B;
  lab_p24_L_55E4: ;
  p24_L_4213();
  lab_p24_L_55E7: ;
  cpu_pop_bc();
  cpu_pop_bc();
  return;
}

/* flash page 24 cpu 0x55EA (offset 0x15EA) */
void p24_L_55EA(void) {
  l = 0x14;
  a = 0x02;
  p24_L_5580();
  e = 0x2C;
  p24_L_4EBD();
  return;
}

/* flash page 24 cpu 0x55F6 (offset 0x15F6) */
void p24_L_55F6(void) {
  p24_L_7046();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5C);
  if (flag_nz()) { p00_L_24FD(); return; }
  a = 0x02;
  mem_write8(0x8478, a);
  p00_rst18();
  a = mem_read8(0x847A);
  return;
}

/* flash page 24 cpu 0x560B (offset 0x160B) */
void p24_L_560B(void) {
  p24_L_55F6();
  cpu_push_af();
  p24_L_6F48();
  p24_L_55F6();
  cpu_pop_bc();
  flag_cmp(a, b);
  if (flag_z()) { p00_L_24FD(); return; }
  p00_L_128A();
  p24_L_7093();
  flag_cmp(a, 0x2B);
  if (flag_nz()) goto lab_p24_L_5631;
  p24_L_7005();
  flag_cmp(a, a);
  p24_L_54A9();
  mem_write16(0x982A, hl());
  p00_L_1653();
  lab_p24_L_5631: ;
  p24_L_4213();
  e = 0x27;
  p24_L_4EBD();
  return;
}

/* flash page 24 cpu 0x5639 (offset 0x1639) */
void p24_L_5639(void) {
  p24_L_5BE1();
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 3)) == 0);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 3)));
  goto lab_p24_L_5669;
  lab_p24_L_5669: ;
  p00_L_0087();
  return;
}

/* flash page 24 cpu 0x5647 (offset 0x1647) */
void p24_L_5647(void) {
  p24_L_5BE1();
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 3)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) | (1u << 3)));
  goto lab_p24_L_5669;
  lab_p24_L_5669: ;
  p00_L_0087();
  return;
}

/* flash page 24 cpu 0x5655 (offset 0x1655) */
void p24_L_5655(void) {
  p24_L_5BE1();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0A)) & (1u << 5)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x0A), (uint8_t)(mem_read8((uint16_t)(iy + 0x0A)) | (1u << 5)));
  mem_write8((uint16_t)(iy + 0x0A), (uint8_t)(mem_read8((uint16_t)(iy + 0x0A)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x0A), (uint8_t)(mem_read8((uint16_t)(iy + 0x0A)) & ~(1u << 6)));
  p00_L_0087();
  return;
}

/* flash page 24 cpu 0x566C (offset 0x166C) */
void p24_L_566C(void) {
  goto lab_p24_L_566C;
  lab_p24_L_5665: ;
  mem_write8((uint16_t)(iy + 0x0A), (uint8_t)(mem_read8((uint16_t)(iy + 0x0A)) & ~(1u << 6)));
  p00_L_0087();
  return;
  lab_p24_L_566C: ;
  p24_L_5BE1();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0A)) & (1u << 7)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x0A), (uint8_t)(mem_read8((uint16_t)(iy + 0x0A)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x0A), (uint8_t)(mem_read8((uint16_t)(iy + 0x0A)) & ~(1u << 5)));
  goto lab_p24_L_5665;
}

/* flash page 24 cpu 0x567E (offset 0x167E) */
void p24_L_567E(void) {
  goto lab_p24_L_567E;
  lab_p24_L_5669: ;
  p00_L_0087();
  return;
  lab_p24_L_567E: ;
  p24_L_5BE1();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0A)) & (1u << 6)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x0A), (uint8_t)(mem_read8((uint16_t)(iy + 0x0A)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x0A), (uint8_t)(mem_read8((uint16_t)(iy + 0x0A)) & ~(1u << 5)));
  mem_write8((uint16_t)(iy + 0x0A), (uint8_t)(mem_read8((uint16_t)(iy + 0x0A)) & ~(1u << 7)));
  goto lab_p24_L_5669;
}

/* flash page 24 cpu 0x5694 (offset 0x1694) */
void p24_L_5694(void) {
  p24_L_5BE1();
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 0)));
  return;
}

/* flash page 24 cpu 0x569C (offset 0x169C) */
void p24_L_569C(void) {
  p24_L_5BE1();
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) | (1u << 0)));
  return;
}

/* flash page 24 cpu 0x56A4 (offset 0x16A4) */
void p24_L_56A4(void) {
  p24_L_5BE1();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) | (1u << 0)));
  return;
}

/* flash page 24 cpu 0x56AC (offset 0x16AC) */
void p24_L_56AC(void) {
  p24_L_5BE1();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 0)));
  return;
}

/* flash page 24 cpu 0x56B4 (offset 0x16B4) */
void p24_L_56B4(void) {
  p24_L_56C2();
  if (flag_nz()) return;
  goto lab_p24_L_56BE;
  lab_p24_L_56BE: ;
  p00_L_2EE3();
  return;
}

/* flash page 24 cpu 0x56BA (offset 0x16BA) */
void p24_L_56BA(void) {
  p24_L_56C2();
  if (flag_z()) return;
  p00_L_2EE3();
  return;
}

/* flash page 24 cpu 0x56C2 (offset 0x16C2) */
void p24_L_56C2(void) {
  p24_L_7005();
  flag_cmp(a, 0x5F);
  if (flag_z()) goto lab_p24_L_56D7;
  flag_cmp(a, 0x62);
  lab_p24_L_56CB: ;
  if (flag_z()) { p00_L_24B5(); return; }
  flag_cmp(a, 0x63);
  if (flag_z()) goto lab_p24_L_56CB;
  p24_L_7049();
  goto lab_p24_L_56E1;
  lab_p24_L_56D7: ;
  p24_L_5DCC();
  mem_write8(hl(), 0x05);
  b = 0x09;
  p24_L_5DFC();
  lab_p24_L_56E1: ;
  p24_L_5BE1();
  p00_L_19ED();
  if (flag_c()) goto lab_p24_L_56FE;
  lab_p24_L_56E9: ;
  p00_L_17BB();
  if (flag_nz()) goto lab_p24_L_56FA;
  flag_cmp(a, 0x16);
  if (flag_z()) { p00_L_24B5(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x08)) & (1u << 1)) == 0);
  if (flag_nz()) { p00_L_24FD(); return; }
  lab_p24_L_56FA: ;
  p00_L_1F55();
  return;
  lab_p24_L_56FE: ;
  p00_L_1037();
  if (flag_nz()) { p00_L_24F1(); return; }
  a = mem_read8(0x8479);
  p24_L_73DF();
  if (flag_c()) { p00_L_24F1(); return; }
  p00_L_1C39();
  p00_L_128A();
  p00_L_11FD();
  p00_L_1135();
  p00_L_19ED();
  if (flag_nc()) goto lab_p24_L_56E9;
  p00_L_24F1();
  return;
}

/* flash page 24 cpu 0x5721 (offset 0x1721) */
void p24_L_5721(void) {
  p24_L_5BE1();
  p00_L_0AFB();
  if (flag_z()) p00_L_2E89();
  a = 0x00;
  b = 0x01;
  p00_L_2EB9();
  return;
}

/* flash page 24 cpu 0x5732 (offset 0x1732) */
void p24_L_5732(void) {
  p24_L_5858();
  p24_L_5877();
  if (flag_nz()) goto lab_p24_L_574A;
  lab_p24_L_573A: ;
  p24_L_40E7();
  flag_cmp(a, 0xD0);
  if (flag_z()) goto lab_p24_L_573A;
  lab_p24_L_5741: ;
  p00_L_21A7();
  p24_L_5744();
  return;
  lab_p24_L_574A: ;
  p24_L_5905();
  lab_p24_L_574D: ;
  flag_cmp(a, 0x01);
  if (flag_nc()) goto lab_p24_L_5757;
  p00_L_21A7();
  p24_L_5869();
  return;
  lab_p24_L_5757: ;
  if (flag_z()) goto lab_p24_L_575C;
  p00_L_24D5();
  return;
  lab_p24_L_575C: ;
  cpu_push_bc();
  p00_L_22FC();
  p24_L_5877();
  cpu_pop_hl();
  if (flag_z()) goto lab_p24_L_5741;
  p24_L_5910();
  goto lab_p24_L_574D;
}

/* flash page 24 cpu 0x5744 (offset 0x1744) */
void p24_L_5744(void) {
  p24_L_5869();
  p24_L_685A();
  return;
}

/* flash page 24 cpu 0x576B (offset 0x176B) */
void p24_L_576B(void) {
  goto lab_p24_L_576B;
  lab_p24_L_5741: ;
  p00_L_21A7();
  p24_L_5744();
  return;
  lab_p24_L_5751: ;
  p00_L_21A7();
  p24_L_5869();
  return;
  lab_p24_L_576B: ;
  p24_L_5858();
  p24_L_5905();
  lab_p24_L_5771: ;
  flag_cmp(a, 0x01);
  if (flag_c()) goto lab_p24_L_5751;
  if (flag_z()) goto lab_p24_L_577A;
  p00_L_24D5();
  return;
  lab_p24_L_577A: ;
  cpu_push_bc();
  p00_L_22FC();
  p24_L_5877();
  cpu_pop_hl();
  if (flag_nz()) goto lab_p24_L_5741;
  p24_L_5910();
  goto lab_p24_L_5771;
}

/* flash page 24 cpu 0x5789 (offset 0x1789) */
void p24_L_5789(void) {
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p24_L_5796;
  flag_cmp(a, 0x03);
  if (flag_nz()) { p00_L_24E5(); return; }
  p00_rst18();
  p00_L_1229();
  lab_p24_L_5796: ;
  p24_L_5883();
  p24_L_585B();
  p00_L_22CF();
  p00_L_231F();
  p00_L_21E0();
  p24_L_615D();
  p24_L_5809();
  if (flag_c()) goto lab_p24_L_57BD;
  lab_p24_L_57AD: ;
  p24_L_40E7();
  flag_cmp(a, 0xD0);
  if (flag_z()) goto lab_p24_L_57AD;
  lab_p24_L_57B4: ;
  set_de(0x0024);
  p00_L_21B6();
  p24_L_5744();
  return;
  lab_p24_L_57BD: ;
  p24_L_5905();
  lab_p24_L_57C0: ;
  flag_cmp(a, 0x01);
  if (flag_nc()) goto lab_p24_L_57CD;
  set_de(0x0024);
  p00_L_21B6();
  p24_L_5869();
  return;
  lab_p24_L_57CD: ;
  if (flag_z()) goto lab_p24_L_57D2;
  p00_L_24D5();
  return;
  lab_p24_L_57D2: ;
  cpu_push_bc();
  p00_L_22F7();
  p00_L_22CF();
  p00_L_16F4();
  p00_L_2420();
  p00_L_1653();
  cpu_push_de();
  cpu_ex_de_hl();
  p00_rst20();
  p00_L_10DD();
  p00_rst30();
  p00_L_1171();
  cpu_pop_de();
  p00_L_11FD();
  p24_L_5809();
  cpu_pop_hl();
  if (flag_nc()) goto lab_p24_L_57B4;
  cpu_push_hl();
  p00_L_10EF();
  p00_L_113A();
  p00_L_107E();
  if (flag_z()) { p00_L_24CD(); return; }
  cpu_pop_hl();
  p24_L_5910();
  goto lab_p24_L_57C0;
}

/* flash page 24 cpu 0x5809 (offset 0x1809) */
void p24_L_5809(void) {
  p00_L_22F7();
  p00_L_15C6();
  /* scf */
  cpu_push_af();
  p00_L_2310();
  p00_L_107E();
  if (flag_nz()) goto lab_p24_L_581B;
  cpu_pop_af();
  return;
  lab_p24_L_581B: ;
  if (flag_c()) goto lab_p24_L_5821;
  cpu_pop_af();
  if (flag_z()) goto lab_p24_L_5823;
  return;
  lab_p24_L_5821: ;
  cpu_pop_af();
  if (flag_z()) return;
  lab_p24_L_5823: ;
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 24 cpu 0x5825 (offset 0x1825) */
void p24_L_5825(void) {
  goto lab_p24_L_5825;
  lab_p24_L_5741: ;
  p00_L_21A7();
  p24_L_5744();
  return;
  lab_p24_L_5751: ;
  p00_L_21A7();
  p24_L_5869();
  return;
  lab_p24_L_5825: ;
  p24_L_5858();
  p24_L_5877();
  if (flag_nz()) goto lab_p24_L_5842;
  p24_L_40E7();
  flag_cmp(a, 0xD0);
  if (flag_nz()) goto lab_p24_L_5741;
  p24_L_5905();
  flag_cmp(a, 0x01);
  if (flag_c()) goto lab_p24_L_5751;
  if (flag_z()) goto lab_p24_L_5741;
  goto lab_p24_L_5855;
  lab_p24_L_5842: ;
  p24_L_5905();
  flag_cmp(a, 0x01);
  if (flag_c()) goto lab_p24_L_5751;
  if (flag_z()) goto lab_p24_L_5741;
  p24_L_40E7();
  flag_cmp(a, 0xD0);
  if (flag_nz()) goto lab_p24_L_5741;
  lab_p24_L_5855: ;
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x5858 (offset 0x1858) */
void p24_L_5858(void) {
  p00_L_21E5();
  p24_L_585B();
  return;
}

/* flash page 24 cpu 0x585B (offset 0x185B) */
void p24_L_585B(void) {
  set_bc(mem_read16(0x982C));
  p24_L_7498();
  set_hl(mem_read16(0x982A));
  mem_write16(0x982C, hl());
  return;
}

/* flash page 24 cpu 0x5869 (offset 0x1869) */
void p24_L_5869(void) {
  set_hl(mem_read16(0x982C));
  mem_write16(0x982A, hl());
  p24_L_74A8();
  mem_write16(0x982C, bc());
  return;
}

/* flash page 24 cpu 0x5877 (offset 0x1877) */
void p24_L_5877(void) {
  p24_L_5920();
  p00_L_1717();
  p00_L_1653();
  p00_L_14C7();
  return;
}

/* flash page 24 cpu 0x5883 (offset 0x1883) */
void p24_L_5883(void) {
  p00_L_1653();
  p00_L_14C7();
  if (flag_z()) { p00_L_24CD(); return; }
  p00_L_1100();
  p00_L_219B();
  p00_L_1653();
  p00_rst08();
  p00_L_219B();
  p00_L_1851();
  p00_L_21E0();
  p00_L_21DB();
  return;
}

/* flash page 24 cpu 0x58A2 (offset 0x18A2) */
void p24_L_58A2(void) {
  a = mem_read8(0x8D1B);
  p00_L_385B();
  p24_L_58A8();
  return;
}

/* flash page 24 cpu 0x58A8 (offset 0x18A8) */
void p24_L_58A8(void) {
  a = 0x08;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_32F7();
  if (flag_nz()) return;
  set_hl(0x0000);
  mem_write16(0x9665, hl());
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p24_L_5AB3();
  set_hl(0x58E7);
  p00_L_25A2();
  p24_L_5920();
  p00_L_25C8();
  p00_L_21A7();
  p24_L_74A8();
  cpu_pop_hl();
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 5)));
  p00_L_018E();
  if (flag_z()) goto lab_p24_L_58F8;
  p00_L_1037();
  if (flag_z()) return;
  flag_cmp(a, 0x0E);
  if (flag_z()) { p00_L_24FD(); return; }
  goto lab_p24_L_58F8;
  lab_p24_L_58F8: ;
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  return;
}

/* flash page 24 cpu 0x5905 (offset 0x1905) */
void p24_L_5905(void) {
  set_hl(mem_read16(0x965D));
  set_de(mem_read16(0x965B));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  set_hl((uint16_t)(hl() + 1));
  p24_L_5910();
  return;
}

/* flash page 24 cpu 0x5910 (offset 0x1910) */
void p24_L_5910(void) {
  cpu_push_hl();
  set_de(mem_read16(0x965B));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x965D, hl());
  cpu_pop_bc();
  p24_L_7498();
  cpu_pop_bc();
  goto lab_p24_L_594F;
  lab_p24_L_594F: ;
  p24_L_7498();
  a = 0x00;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_2D69();
  if (flag_nz()) goto lab_p24_L_67B8;
  p24_L_595E();
  return;
  lab_p24_L_67B8: ;
  p24_L_74A8();
  cpu_push_bc();
  p24_L_709E();
  if (flag_z()) return;
  p24_L_74A8();
  cpu_pop_hl();
  a = 0;
  flag_logic(a);
  p24_L_7001();
  p24_L_74C2();
  goto lab_p24_L_67B8;
}

/* flash page 24 cpu 0x5920 (offset 0x1920) */
void p24_L_5920(void) {
  p24_L_5B08();
  p24_L_5923();
  return;
}

/* flash page 24 cpu 0x5923 (offset 0x1923) */
void p24_L_5923(void) {
  p24_L_5AC8();
  cpu_pop_bc();
  p24_L_7498();
  set_bc(0x5A67);
  goto lab_p24_L_594F;
  lab_p24_L_594F: ;
  p24_L_7498();
  a = 0x00;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_2D69();
  if (flag_nz()) goto lab_p24_L_67B8;
  p24_L_595E();
  return;
  lab_p24_L_67B8: ;
  p24_L_74A8();
  cpu_push_bc();
  p24_L_709E();
  if (flag_z()) return;
  p24_L_74A8();
  cpu_pop_hl();
  a = 0;
  flag_logic(a);
  p24_L_7001();
  p24_L_74C2();
  goto lab_p24_L_67B8;
}

/* flash page 24 cpu 0x592F (offset 0x192F) */
void p24_L_592F(void) {
  p00_L_1664();
  p24_L_5932();
  return;
}

/* flash page 24 cpu 0x5932 (offset 0x1932) */
void p24_L_5932(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x9305, a);
  p24_L_5B08();
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 3)));
  p24_L_593D();
  return;
}

/* flash page 24 cpu 0x593D (offset 0x193D) */
void p24_L_593D(void) {
  p24_L_5AC8();
  cpu_pop_bc();
  p24_L_7498();
  cpu_pop_bc();
  p24_L_7498();
  cpu_pop_bc();
  p24_L_7498();
  set_bc(0x5A5F);
  p24_L_7498();
  a = 0x00;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_2D69();
  if (flag_nz()) goto lab_p24_L_67B8;
  p24_L_595E();
  return;
  lab_p24_L_67B8: ;
  p24_L_74A8();
  cpu_push_bc();
  p24_L_709E();
  if (flag_z()) return;
  p24_L_74A8();
  cpu_pop_hl();
  a = 0;
  flag_logic(a);
  p24_L_7001();
  p24_L_74C2();
  goto lab_p24_L_67B8;
}

/* flash page 24 cpu 0x595E (offset 0x195E) */
void p24_L_595E(void) {
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  a = 0x00;
  p24_L_74B1();
  set_hl(0x0001);
  mem_write16(0x9661, hl());
  p24_L_5971();
  return;
}

/* flash page 24 cpu 0x5971 (offset 0x1971) */
void p24_L_5971(void) {
  p24_L_700C();
  p24_L_5974();
  return;
}

/* flash page 24 cpu 0x5974 (offset 0x1974) */
void p24_L_5974(void) {
  p00_L_171E();
  p24_L_7099();
  if (flag_z()) goto lab_p24_L_679F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_17FA();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 7)));
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p24_L_6839;
  if (flag_c()) { p24_L_6ECE(); return; }
  flag_cmp(a, 0x07);
  if (flag_z()) goto lab_p24_L_5D6E;
  if (flag_c()) goto lab_p24_L_5D24;
  flag_cmp(a, 0x09);
  if (flag_z()) goto lab_p24_L_5D8B;
  if (flag_c()) goto lab_p24_L_5D78;
  flag_cmp(a, 0x10);
  if (flag_c()) { p24_L_67DA(); return; }
  flag_cmp(a, 0x11);
  if (flag_z()) goto lab_p24_L_5A56;
  if (flag_c()) goto lab_p24_L_6850;
  flag_cmp(a, 0x29);
  if (flag_z()) goto lab_p24_L_5A53;
  if (flag_c()) { p24_L_67EC(); return; }
  flag_cmp(a, 0x2C);
  if (flag_z()) goto lab_p24_L_5B7E;
  flag_cmp(a, 0x2B);
  if (flag_z()) goto lab_p24_L_5A56;
  if (flag_c()) goto lab_p24_L_5CDF;
  flag_cmp(a, 0x2D);
  if (flag_z()) { p24_L_67DA(); return; }
  flag_cmp(a, 0x30);
  if (flag_c()) goto lab_p24_L_6E3F;
  flag_cmp(a, 0x3C);
  if (flag_c()) goto lab_p24_L_5B1F;
  flag_cmp(a, 0x3E);
  if (flag_z()) goto lab_p24_L_6799;
  if (flag_c()) goto lab_p24_L_5A56;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p24_L_5A56;
  flag_cmp(a, 0x64);
  if (flag_c()) goto lab_p24_L_5E22;
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p24_L_5E22;
  flag_cmp(a, 0x6A);
  if (flag_c()) goto lab_p24_L_6EA8;
  flag_cmp(a, 0x70);
  if (flag_c()) goto lab_p24_L_5A56;
  flag_cmp(a, 0x73);
  if (flag_z()) goto lab_p24_L_6EC2;
  if (flag_c()) goto lab_p24_L_5A56;
  flag_cmp(a, 0x7E);
  if (flag_c()) goto lab_p24_L_6EA6;
  if (flag_z()) goto lab_p24_L_6EA1;
  flag_cmp(a, 0x82);
  if (flag_c()) goto lab_p24_L_5A53;
  flag_cmp(a, 0x84);
  if (flag_c()) goto lab_p24_L_5A56;
  flag_cmp(a, 0x94);
  if (flag_c()) goto lab_p24_L_6E55;
  flag_cmp(a, 0x96);
  if (flag_c()) goto lab_p24_L_5A56;
  flag_cmp(a, 0xAA);
  if (flag_c()) goto lab_p24_L_6E53;
  flag_cmp(a, 0xAA);
  if (flag_z()) goto lab_p24_L_5E22;
  flag_cmp(a, 0xAE);
  if (flag_c()) goto lab_p24_L_5B7E;
  flag_cmp(a, 0xB0);
  if (flag_z()) { p24_L_5A59(); return; }
  flag_cmp(a, 0xBB);
  if (flag_z()) goto lab_p24_L_6DBF;
  flag_cmp(a, 0xB0);
  if (flag_c()) goto lab_p24_L_5A53;
  flag_cmp(a, 0xCE);
  if (flag_c()) goto lab_p24_L_6860;
  flag_cmp(a, 0xE6);
  if (flag_z()) goto lab_p24_L_6DA0;
  flag_cmp(a, 0xEB);
  if (flag_c()) goto lab_p24_L_6E43;
  if (flag_z()) goto lab_p24_L_5E22;
  flag_cmp(a, 0xEF);
  if (flag_c()) goto lab_p24_L_6E3A;
  if (flag_z()) { p00_L_2555(); return; }
  flag_cmp(a, 0xF2);
  if (flag_c()) goto lab_p24_L_5A56;
  flag_cmp(a, 0xFC);
  if (flag_c()) goto lab_p24_L_6E41;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p24_L_6E36;
  lab_p24_L_5A53: ;
  p00_L_24D5();
  return;
  lab_p24_L_5A56: ;
  p24_L_6846();
  return;
  lab_p24_L_5B1F: ;
  p24_L_6895();
  p24_L_5BEC();
  p24_L_700C();
  flag_cmp(a, 0x0B);
  if (flag_nz()) { p24_L_5B77(); return; }
  p24_L_73D5();
  if (flag_nc()) goto lab_p24_L_5B3A;
  set_hl(mem_read16(0x965D));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x965D, hl());
  p24_L_5B77();
  return;
  lab_p24_L_5B3A: ;
  p00_L_1169();
  p24_L_5BEC();
  p24_L_700C();
  flag_cmp(a, 0xAE);
  if (flag_nz()) { p00_L_24D5(); return; }
  p24_L_5CAB();
  p00_L_0ED0();
  p00_L_1128();
  p00_rst30();
  p24_L_73D5();
  if (flag_c()) { p24_L_5B77(); return; }
  p00_L_1169();
  p24_L_5BEC();
  p24_L_5CAB();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = 0x36;
  mem_write8(0x8485, a);
  p00_L_0ED0();
  p00_L_1128();
  p00_rst30();
  p24_L_700C();
  flag_cmp(a, 0x2A);
  if (flag_nz()) goto lab_p24_L_5BE9;
  p24_L_5BAF();
  return;
  lab_p24_L_5B7E: ;
  cpu_push_af();
  flag_cmp(a, 0xAB);
  if (flag_nz()) goto lab_p24_L_5B92;
  p24_L_7093();
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p24_L_5B92;
  mem_write16(0x965D, bc());
  cpu_pop_af();
  p24_L_5A59();
  return;
  lab_p24_L_5B92: ;
  p24_L_6895();
  cpu_pop_af();
  flag_cmp(a, 0x2C);
  if (flag_z()) goto lab_p24_L_5BB6;
  flag_cmp(a, 0xAC);
  if (flag_z()) goto lab_p24_L_5BC0;
  if (flag_c()) goto lab_p24_L_5BC7;
  p24_L_6D98();
  p00_L_24A9();
  if (flag_z()) p00_L_0284();
  p00_L_381F();
  p00_L_1179();
  p24_L_5BAF();
  return;
  lab_p24_L_5BB6: ;
  p00_L_1048();
  a = 0x10;
  mem_write8(0x8485, a);
  p24_L_5BAF();
  return;
  lab_p24_L_5BC0: ;
  a = 0x04;
  p00_L_152C();
  p24_L_5BAF();
  return;
  lab_p24_L_5BC7: ;
  p24_L_7020();
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p24_L_5BD3;
  p00_L_39F9();
  p24_L_5BAF();
  return;
  lab_p24_L_5BD3: ;
  p24_L_5BE1();
  p24_L_74C2();
  p00_L_219B();
  p00_L_2D6F();
  p24_L_5BAF();
  return;
  lab_p24_L_5BE9: ;
  p00_L_24D5();
  return;
  lab_p24_L_5CDF: ;
  p00_L_018E();
  if (flag_nz()) { p00_L_24D5(); return; }
  e = 0x00;
  cpu_push_de();
  set_bc(mem_read16(0x965D));
  cpu_push_bc();
  lab_p24_L_5CED: ;
  p24_L_7261();
  mem_write16(0x965D, bc());
  if (flag_nc()) goto lab_p24_L_5CED;
  flag_cmp(a, 0x11);
  if (flag_z()) goto lab_p24_L_5CED;
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  h = b;
  l = c;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_push_af();
  cpu_push_hl();
  p00_L_1C89();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_pop_bc();
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_5D14;
  set_hl(mem_read16(0x965D));
  cpu_sbc_hl_bc();
  while (bc() != 0) { cpu_ldi(); }
  lab_p24_L_5D14: ;
  p00_L_1135();
  cpu_pop_af();
  cpu_pop_de();
  flag_set_z((e & (1u << 0)) == 0);
  if (flag_nz()) return;
  flag_cmp(a, 0x2A);
  if (flag_z()) { p24_L_5BAF(); return; }
  p24_L_5B77();
  return;
  lab_p24_L_5D24: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 5)) == 0);
  if (flag_nz()) { p24_L_5D75(); return; }
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p24_L_5D62;
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p24_L_5D51;
  mem_write8((uint16_t)(iy + 0x06), (uint8_t)(mem_read8((uint16_t)(iy + 0x06)) | (1u << 7)));
  lab_p24_L_5D3B: ;
  p00_L_018E();
  if (flag_nz()) { p24_L_5D75(); return; }
  p24_L_7020();
  flag_cmp(a, 0x06);
  if (flag_nz()) { p24_L_5D75(); return; }
  set_hl(0x9664);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  if (flag_nz()) goto lab_p24_L_6856;
  p00_L_24ED();
  return;
  lab_p24_L_5D51: ;
  set_hl(0x0000);
  mem_write16(0x9663, hl());
  /* ld (iy+0x06),iyh */
  mem_write8((uint16_t)(iy + 0x06), (uint8_t)(mem_read8((uint16_t)(iy + 0x06)) | (1u << 6)));
  cpu_pop_af();
  lab_p24_L_5D5F: ;
  p24_L_6852();
  return;
  lab_p24_L_5D62: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 6)) == 0);
  if (flag_nz()) { p24_L_5D75(); return; }
  mem_write8((uint16_t)(iy + 0x06), (uint8_t)(mem_read8((uint16_t)(iy + 0x06)) | (1u << 6)));
  goto lab_p24_L_5D3B;
  lab_p24_L_5D6E: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 7)) == 0);
  lab_p24_L_5D72: ;
  if (flag_nz()) { p24_L_6846(); return; }
  p24_L_5D75();
  return;
  lab_p24_L_5D78: ;
  a = mem_read8((uint16_t)(iy + 0x06));
  a = a & 0xE0;
  flag_logic(a);
  if (flag_nz()) { p24_L_5D75(); return; }
  /* ld (iy+0x06),0x00 */
  mem_write8((uint16_t)(iy + 0x06), (uint8_t)(mem_read8((uint16_t)(iy + 0x06)) | (1u << 5)));
  a = 0x08;
  goto lab_p24_L_5D5F;
  lab_p24_L_5D8B: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 5)) == 0);
  goto lab_p24_L_5D72;
  lab_p24_L_5D91: ;
  cpu_pop_af();
  set_hl(mem_read16(0x965D));
  set_de(0x8478);
  p00_L_118B();
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x965D, hl());
  set_hl(mem_read16(0x8479));
  mem_write16(0x9810, hl());
  set_hl(mem_read16(0x847B));
  mem_write16(0x980E, hl());
  goto lab_p24_L_5DBC;
  lab_p24_L_5DAD: ;
  cpu_pop_af();
  p00_L_2191();
  p00_L_2176();
  p00_L_21DB();
  d = 0x04;
  p24_L_68C7();
  lab_p24_L_5DBC: ;
  p24_L_684A();
  return;
  lab_p24_L_5DE5: ;
  p24_L_5DCC();
  mem_write8(hl(), 0x05);
  b = 0x09;
  p24_L_5DFC();
  p24_L_5ECA();
  return;
  lab_p24_L_5E22: ;
  cpu_push_af();
  p24_L_6895();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x5F);
  if (flag_z()) goto lab_p24_L_5DE5;
  flag_cmp(a, 0xEB);
  if (flag_z()) { p24_L_5DDB(); return; }
  p24_L_73DF();
  if (flag_c()) goto lab_p24_L_5E59;
  p24_L_7020();
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p24_L_5E57;
  p00_L_22F7();
  a = mem_read8(0x8483);
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p24_L_5E4D;
  p00_L_1830();
  if (flag_nz()) goto lab_p24_L_5E57;
  lab_p24_L_5E4D: ;
  set_hl(mem_read16(0x965D));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x965D, hl());
  p24_L_5DDB();
  return;
  lab_p24_L_5E57: ;
  cpu_pop_af();
  cpu_push_af();
  lab_p24_L_5E59: ;
  p24_L_7071();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x62);
  if (flag_c()) { p24_L_5EA0(); return; }
  if (flag_z()) goto lab_p24_L_6017;
  flag_cmp(a, 0xAA);
  if (flag_z()) { p24_L_5EA0(); return; }
  flag_cmp(a, 0x72);
  if (flag_nz()) goto lab_p24_L_5E75;
  p00_L_172A();
  if (flag_nz()) { p00_L_24FD(); return; }
  p24_L_5EA0();
  return;
  lab_p24_L_5E75: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x06);
  lab_p24_L_5E7A: ;
  if (flag_z()) { p00_L_24FD(); return; }
  flag_cmp(a, 0x07);
  if (flag_z()) goto lab_p24_L_5E7A;
  flag_cmp(a, 0x41);
  if (flag_z()) goto lab_p24_L_5D91;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p24_L_5DAD;
  p00_L_172A();
  if (flag_nz()) p24_L_735F();
  p24_L_604D();
  mem_write8(0x8478, a);
  mem_write16(0x981C, de());
  mem_write16(0x84DD, hl());
  p24_L_5ECA();
  return;
  lab_p24_L_6017: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x21);
  if (flag_z()) { p24_L_5EA0(); return; }
  cpu_pop_hl();
  p24_L_6026();
  p24_L_5BAF();
  return;
  lab_p24_L_6799: ;
  p24_L_703E();
  if (flag_nz()) { p00_L_24D5(); return; }
  lab_p24_L_679F: ;
  a = 0;
  flag_logic(a);
  p24_L_689B();
  /* ei */
  p24_L_74C2();
  p24_L_703E();
  if (flag_nz()) goto lab_p24_L_67B2;
  p00_L_018E();
  if (flag_nz()) p24_L_60FF();
  lab_p24_L_67B2: ;
  p24_L_7002();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_67CD;
  lab_p24_L_67B8: ;
  p24_L_74A8();
  cpu_push_bc();
  p24_L_709E();
  if (flag_z()) return;
  p24_L_74A8();
  cpu_pop_hl();
  a = 0;
  flag_logic(a);
  p24_L_7001();
  p24_L_74C2();
  goto lab_p24_L_67B8;
  lab_p24_L_67CD: ;
  p24_L_5B18();
  set_de(mem_read16(0x982C));
  p00_L_31F5();
  p24_L_595E();
  return;
  lab_p24_L_6836: ;
  p00_L_24D5();
  return;
  lab_p24_L_6839: ;
  p24_L_703E();
  if (flag_nz()) goto lab_p24_L_6836;
  p24_L_7019();
  p24_L_70B8();
  a = 0x04;
  p24_L_6846();
  return;
  lab_p24_L_6850: ;
  a = 0x10;
  p24_L_6852();
  return;
  lab_p24_L_6856: ;
  cpu_pop_af();
  p24_L_74B1();
  p24_L_685A();
  return;
  lab_p24_L_6860: ;
  flag_cmp(a, 0xB5);
  if (flag_z()) p24_L_70D9();
  p24_L_688A();
  p24_L_684A();
  return;
  lab_p24_L_6DA0: ;
  p24_L_6D98();
  p24_L_702C();
  p24_L_52FE();
  p24_L_6E9E();
  return;
  lab_p24_L_6DB5: ;
  p24_L_6895();
  set_hl(0x6DAC);
  p00_rst20();
  lab_p24_L_6DBC: ;
  p24_L_5BAF();
  return;
  lab_p24_L_6DBF: ;
  p24_L_7005();
  flag_cmp(a, 0x6D);
  lab_p24_L_6DC4: ;
  if (flag_z()) { p00_L_24D5(); return; }
  flag_cmp(a, 0x6C);
  if (flag_z()) goto lab_p24_L_6DC4;
  flag_cmp(a, 0x6E);
  if (flag_c()) goto lab_p24_L_6DE6;
  flag_cmp(a, 0xCE);
  if (flag_nz()) goto lab_p24_L_6DD7;
  a = 0x5F;
  goto lab_p24_L_6E4A;
  lab_p24_L_6DD7: ;
  flag_cmp(a, 0xDA);
  if (flag_nz()) goto lab_p24_L_6DDE;
  p24_L_67DA();
  return;
  lab_p24_L_6DDE: ;
  flag_cmp(a, 0xF6);
  if (flag_c()) { p00_L_24D5(); return; }
  p00_L_2555();
  return;
  lab_p24_L_6DE6: ;
  flag_cmp(a, 0x20);
  if (flag_nc()) goto lab_p24_L_6DEF;
  a = (uint8_t)(a + 0xCE);
  p24_L_67EC();
  return;
  lab_p24_L_6DEF: ;
  flag_cmp(a, 0x32);
  if (flag_nc()) goto lab_p24_L_6E22;
  flag_cmp(a, 0x31);
  if (flag_z()) goto lab_p24_L_6DB5;
  flag_cmp(a, 0x2F);
  if (flag_c()) goto lab_p24_L_6E00;
  a = (uint8_t)(a + 0xC3);
  p24_L_6ECE();
  return;
  lab_p24_L_6E00: ;
  flag_cmp(a, 0x25);
  if (flag_nc()) goto lab_p24_L_6E1D;
  cpu_push_af();
  p24_L_7019();
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p24_L_6E18;
  p24_L_6895();
  cpu_pop_af();
  p00_L_395D();
  p00_L_15FB();
  goto lab_p24_L_6DBC;
  lab_p24_L_6E18: ;
  mem_write16(0x965D, bc());
  cpu_pop_af();
  lab_p24_L_6E1D: ;
  a = (uint8_t)(a + 0x64);
  p24_L_67EC();
  return;
  lab_p24_L_6E22: ;
  flag_cmp(a, 0x5C);
  if (flag_c()) goto lab_p24_L_6E32;
  flag_cmp(a, 0x64);
  if (flag_c()) { p00_L_24FD(); return; }
  flag_cmp(a, 0xF6);
  if (flag_nc()) { p00_L_2555(); return; }
  a = (uint8_t)(a - 0x08);
  lab_p24_L_6E32: ;
  a = (uint8_t)(a + 0xBE);
  goto lab_p24_L_6E3D;
  lab_p24_L_6E36: ;
  a = 0xEF;
  goto lab_p24_L_6E3D;
  lab_p24_L_6E3A: ;
  p24_L_6D98();
  lab_p24_L_6E3D: ;
  a = (uint8_t)(a - 0xBC);
  lab_p24_L_6E3F: ;
  a = (uint8_t)(a + 0xCE);
  lab_p24_L_6E41: ;
  a = (uint8_t)(a - 0x07);
  lab_p24_L_6E43: ;
  a = (uint8_t)(a - 0xCE);
  flag_cmp(a, 0x14);
  if (flag_c()) p24_L_6D98();
  lab_p24_L_6E4A: ;
  cpu_push_af();
  p24_L_702C();
  cpu_pop_af();
  c = 0x01;
  goto lab_p24_L_6E6E;
  lab_p24_L_6E53: ;
  a = (uint8_t)(a - 0x02);
  lab_p24_L_6E55: ;
  flag_cmp(a, 0x85);
  if (flag_z()) goto lab_p24_L_6E5E;
  flag_cmp(a, 0x93);
  if (flag_c()) p24_L_6D98();
  lab_p24_L_6E5E: ;
  cpu_push_af();
  p24_L_702C();
  cpu_pop_af();
  flag_cmp(a, 0x93);
  if (flag_nc()) goto lab_p24_L_6E6C;
  cpu_push_af();
  p24_L_5BE1();
  cpu_pop_af();
  lab_p24_L_6E6C: ;
  c = 0x02;
  lab_p24_L_6E6E: ;
  b = a;
  a = c;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p24_L_6E7F;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_6E84;
  set_hl(0x4000);
  c = 0x01;
  goto lab_p24_L_6E87;
  lab_p24_L_6E7F: ;
  set_hl(0x46BA);
  goto lab_p24_L_6E87;
  lab_p24_L_6E84: ;
  set_hl(0x6EE2);
  lab_p24_L_6E87: ;
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_2D69();
  if (flag_nz()) { p24_L_6E9E(); return; }
  a = b;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  p24_L_7001();
  p24_L_6E9E();
  return;
  lab_p24_L_6EA1: ;
  p24_L_7005();
  a = (uint8_t)(a + 0x7E);
  lab_p24_L_6EA6: ;
  a = (uint8_t)(a - 0x09);
  lab_p24_L_6EA8: ;
  cpu_push_af();
  p24_L_702C();
  p24_L_5BE1();
  cpu_pop_af();
  c = 0x00;
  b = a;
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_2D69();
  a = b;
  if (flag_z()) p00_L_388B();
  p24_L_6E9E();
  return;
  lab_p24_L_6EC2: ;
  p24_L_702C();
  b = 0x00;
  c = 0x01;
  p24_L_7498();
  p24_L_6E9E();
  return;
}

/* flash page 24 cpu 0x5A59 (offset 0x1A59) */
void p24_L_5A59(void) {
  p24_L_688A();
  p24_L_684A();
  return;
}

/* flash page 24 cpu 0x5A7A (offset 0x1A7A) */
void p24_L_5A7A(void) {
  p24_L_5AC8();
  p24_L_759D();
  p24_L_5A80();
  return;
}

/* flash page 24 cpu 0x5A80 (offset 0x1A80) */
void p24_L_5A80(void) {
  p00_L_219B();
  p24_L_5A83();
  return;
}

/* flash page 24 cpu 0x5A83 (offset 0x1A83) */
void p24_L_5A83(void) {
  p24_L_74A8();
  a = mem_read8(0x8479);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_5AAD;
  cpu_push_bc();
  p00_L_19ED();
  cpu_ex_de_hl();
  cpu_pop_de();
  if (flag_nc()) goto lab_p24_L_5A9A;
  a = 0;
  flag_logic(a);
  mem_write8(0x8479, a);
  goto lab_p24_L_5AAD;
  lab_p24_L_5A9A: ;
  p00_L_2420();
  p24_L_5AE6();
  mem_write16(0x965B, hl());
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x965D, hl());
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x965F, hl());
  lab_p24_L_5AAD: ;
  set_de(0x9652);
  p00_L_11FD();
  return;
}

/* flash page 24 cpu 0x5AB3 (offset 0x1AB3) */
void p24_L_5AB3(void) {
  set_hl(mem_read16(0x965D));
  set_bc(mem_read16(0x965B));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  b = h;
  c = l;
  p24_L_7498();
  set_hl(0x9652);
  p00_L_21E8();
  return;
}

/* flash page 24 cpu 0x5AC8 (offset 0x1AC8) */
void p24_L_5AC8(void) {
  p00_L_19ED();
  if (flag_c()) { p00_L_24F1(); return; }
  p00_L_2420();
  p24_L_5AD1();
  return;
}

/* flash page 24 cpu 0x5AD1 (offset 0x1AD1) */
void p24_L_5AD1(void) {
  goto lab_p24_L_5AD1;
  lab_p24_L_5AA9: ;
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x965F, hl());
  set_de(0x9652);
  p00_L_11FD();
  return;
  lab_p24_L_5AD1: ;
  mem_write16(0x84DD, de());
  p24_L_5AB3();
  set_hl(mem_read16(0x84DD));
  p24_L_5AE6();
  mem_write16(0x965B, hl());
  mem_write16(0x965D, hl());
  goto lab_p24_L_5AA9;
}

/* flash page 24 cpu 0x5AE6 (offset 0x1AE6) */
void p24_L_5AE6(void) {
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_bc((uint16_t)(bc() - 1));
  set_hl((uint16_t)(hl() + 1));
  a = a & 0x0F;
  flag_logic(a);
  p00_L_17BE();
  if (flag_z()) return;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x24);
  if (flag_nz()) return;
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() - 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_5B05;
  a = (uint8_t)(a + 0x03);
  lab_p24_L_5AFF: ;
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() - 1));
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p24_L_5AFF;
  return;
  lab_p24_L_5B05: ;
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() - 1));
  return;
}

/* flash page 24 cpu 0x5B08 (offset 0x1B08) */
void p24_L_5B08(void) {
  /* ld (iy+0x06),0x00 */
  /* ld (iy+0x07),0x00 */
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 0)));
  p24_L_5B18();
  return;
}

/* flash page 24 cpu 0x5B18 (offset 0x1B18) */
void p24_L_5B18(void) {
  a = mem_read8((uint16_t)(iy + 0x0A));
  mem_write8((uint16_t)(iy + 0x0B), a);
  return;
}

/* flash page 24 cpu 0x5B50 (offset 0x1B50) */
void p24_L_5B50(void) {
  set_de(0xCDF7);
  cpu_push_de();
  mem_write8(hl(), e);
  if (flag_c()) { p24_L_5B77(); return; }
  p00_L_1169();
  p24_L_5BEC();
  p24_L_5CAB();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = 0x36;
  mem_write8(0x8485, a);
  p00_L_0ED0();
  p00_L_1128();
  p00_rst30();
  p24_L_700C();
  flag_cmp(a, 0x2A);
  if (flag_nz()) goto lab_p24_L_5BE9;
  p24_L_5BAF();
  return;
  lab_p24_L_5BE9: ;
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x5B77 (offset 0x1B77) */
void p24_L_5B77(void) {
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  p24_L_5971();
  return;
}

/* flash page 24 cpu 0x5BAF (offset 0x1BAF) */
void p24_L_5BAF(void) {
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  p24_L_684A();
  return;
}

/* flash page 24 cpu 0x5BE1 (offset 0x1BE1) */
void p24_L_5BE1(void) {
  p24_L_7093();
  if (flag_z()) return;
  p24_L_5BE5();
  return;
}

/* flash page 24 cpu 0x5BE5 (offset 0x1BE5) */
void p24_L_5BE5(void) {
  mem_write16(0x965D, bc());
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x5BEC (offset 0x1BEC) */
void p24_L_5BEC(void) {
  p00_L_128A();
  p00_L_15EB();
  c = 0x00;
  b = 0x03;
  cpu_push_bc();
  p24_L_700C();
  flag_cmp(a, 0x3B);
  if (flag_z()) goto lab_p24_L_5C52;
  lab_p24_L_5BFE: ;
  cpu_pop_bc();
  flag_cmp(a, 0xB0);
  if (flag_z()) goto lab_p24_L_5C42;
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p24_L_5C36;
  flag_cmp(a, 0x3B);
  if (flag_z()) goto lab_p24_L_5C5C;
  if (flag_nc()) goto lab_p24_L_5C78;
  flag_cmp(a, 0x30);
  if (flag_c()) goto lab_p24_L_5C78;
  flag_set_z((c & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p24_L_5C6E;
  c = (uint8_t)(c | (1u << 3));
  flag_cmp(a, 0x30);
  if (flag_z()) goto lab_p24_L_5C26;
  lab_p24_L_5C1B: ;
  c = (uint8_t)(c | (1u << 7));
  cpu_push_bc();
  p24_L_5CBA();
  lab_p24_L_5C21: ;
  p24_L_7002();
  goto lab_p24_L_5BFE;
  lab_p24_L_5C26: ;
  flag_set_z((c & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p24_L_5C1B;
  flag_set_z((c & (1u << 6)) == 0);
  if (flag_z()) goto lab_p24_L_5C4F;
  p00_L_15EB();
  if (flag_p()) goto lab_p24_L_5C4F;
  goto lab_p24_L_5C75;
  lab_p24_L_5C36: ;
  flag_set_z((c & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p24_L_5C75;
  flag_set_z((c & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p24_L_5C75;
  c = (uint8_t)(c | (1u << 6));
  goto lab_p24_L_5C4F;
  lab_p24_L_5C42: ;
  flag_set_z((c & (1u << 5)) == 0);
  if (flag_z()) goto lab_p24_L_5C75;
  a = b;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p24_L_5C75;
  a = c;
  a = a ^ 0x10;
  flag_logic(a);
  c = a;
  lab_p24_L_5C4F: ;
  cpu_push_bc();
  goto lab_p24_L_5C21;
  lab_p24_L_5C52: ;
  cpu_pop_bc();
  cpu_push_bc();
  p24_L_5CB8();
  cpu_pop_bc();
  c = (uint8_t)(c | (1u << 7));
  c = (uint8_t)(c | (1u << 3));
  lab_p24_L_5C5C: ;
  set_hl(0x0000);
  mem_write16(0x8483, hl());
  flag_set_z((c & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p24_L_5C75;
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_z()) goto lab_p24_L_5C75;
  c = (uint8_t)(c | (1u << 5));
  goto lab_p24_L_5C4F;
  lab_p24_L_5C6E: ;
  set_hl(0x8484);
  /* rld */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p24_L_5C4F;
  lab_p24_L_5C75: ;
  p00_L_24D5();
  return;
  lab_p24_L_5C78: ;
  flag_set_z((c & (1u << 5)) == 0);
  if (flag_z()) goto lab_p24_L_5C9B;
  a = b;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_5C75;
  flag_set_z((c & (1u << 7)) == 0);
  if (flag_z()) goto lab_p24_L_5C9B;
  cpu_push_bc();
  set_hl(0x8484);
  p24_L_7216();
  cpu_pop_bc();
  a = mem_read8(0x8479);
  flag_set_z((c & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p24_L_5CA5;
  a = (uint8_t)(a + e);
  if (flag_c()) { p00_L_24BD(); return; }
  lab_p24_L_5C98: ;
  mem_write8(0x8479, a);
  lab_p24_L_5C9B: ;
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_z()) goto lab_p24_L_5C75;
  p00_L_1040();
  p00_L_15FB();
  return;
  lab_p24_L_5CA5: ;
  a = (uint8_t)(a - e);
  if (flag_nc()) goto lab_p24_L_5C98;
  p00_L_128A();
  return;
}

/* flash page 24 cpu 0x5CAB (offset 0x1CAB) */
void p24_L_5CAB(void) {
  p00_L_1287();
  a = 0x60;
  mem_write8(0x8485, a);
  set_hl(0x8484);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  return;
}

/* flash page 24 cpu 0x5CB8 (offset 0x1CB8) */
void p24_L_5CB8(void) {
  a = 0x31;
  p24_L_5CBA();
  return;
}

/* flash page 24 cpu 0x5CBA (offset 0x1CBA) */
void p24_L_5CBA(void) {
  cpu_push_bc();
  a = a & 0x0F;
  flag_logic(a);
  b = a;
  set_hl(0x8478);
  a = mem_read8(hl());
  flag_set_z((a & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p24_L_5CD8;
  a = a & 0x0F;
  flag_logic(a);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  c = a;
  a = b;
  b = 0x00;
  set_hl(0x847A);
  /* srl c */
  if (flag_nc()) p00_L_12B9();
  set_hl((uint16_t)(hl() + bc()));
  /* add a,(hl) */
  mem_write8(hl(), a);
  lab_p24_L_5CD8: ;
  cpu_pop_bc();
  flag_set_z((c & (1u << 6)) == 0);
  if (flag_nz()) return;
  p00_L_15F3();
  return;
}

/* flash page 24 cpu 0x5D75 (offset 0x1D75) */
void p24_L_5D75(void) {
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x5DBF (offset 0x1DBF) */
void p24_L_5DBF(void) {
  p24_L_73DF();
  if (flag_nc()) return;
  flag_cmp(a, 0x30);
  if (flag_c()) { p24_L_5D75(); return; }
  flag_cmp(a, 0x3A);
  if (flag_nc()) { p24_L_5D75(); return; }
  return;
}

/* flash page 24 cpu 0x5DCC (offset 0x1DCC) */
void p24_L_5DCC(void) {
  p24_L_7019();
  p24_L_73DF();
  if (flag_c()) { p24_L_5D75(); return; }
  p00_L_1295();
  set_hl(0x8478);
  return;
}

/* flash page 24 cpu 0x5DDB (offset 0x1DDB) */
void p24_L_5DDB(void) {
  cpu_pop_af();
  a = 0x5D;
  cpu_push_af();
  p24_L_5DF2();
  p24_L_5EA0();
  return;
}

/* flash page 24 cpu 0x5DF2 (offset 0x1DF2) */
void p24_L_5DF2(void) {
  p24_L_5DCC();
  mem_write8(hl(), 0x01);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x5D);
  b = 0x06;
  p24_L_5DFC();
  return;
}

/* flash page 24 cpu 0x5DFC (offset 0x1DFC) */
void p24_L_5DFC(void) {
  lab_p24_L_5DFC: ;
  cpu_push_hl();
  cpu_push_bc();
  p24_L_7093();
  if (flag_z()) goto lab_p24_L_5E1F;
  p24_L_73DF();
  if (flag_nc()) goto lab_p24_L_5E12;
  flag_cmp(a, 0x30);
  if (flag_nc()) goto lab_p24_L_5E0E;
  lab_p24_L_5E0C: ;
  goto lab_p24_L_5E1F;
  lab_p24_L_5E0E: ;
  flag_cmp(a, 0x3A);
  if (flag_nc()) goto lab_p24_L_5E0C;
  lab_p24_L_5E12: ;
  mem_write16(0x965D, bc());
  cpu_pop_bc();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p24_L_5DFC;
  p24_L_5D75();
  return;
  lab_p24_L_5E1F: ;
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 24 cpu 0x5EA0 (offset 0x1EA0) */
void p24_L_5EA0(void) {
  cpu_pop_af();
  cpu_push_af();
  a = 0xFF;
  mem_write8(0x8478, a);
  lab_p24_L_5EA7: ;
  p00_L_241E();
  if (flag_nc()) goto lab_p24_L_5EB9;
  a = mem_read8(0x8479);
  p24_L_73DF();
  if (flag_c()) goto lab_p24_L_5EB9;
  p24_L_5F3E();
  goto lab_p24_L_5EA7;
  lab_p24_L_5EB9: ;
  mem_write16(0x981C, hl());
  mem_write16(0x84DD, de());
  p00_L_10DD();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 3)) == 0);
  if (flag_nz()) p24_L_7395();
  p24_L_5ECA();
  return;
}

/* flash page 24 cpu 0x5ECA (offset 0x1ECA) */
void p24_L_5ECA(void) {
  p24_L_7370();
  p24_L_7020();
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p24_L_5FB1;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_5EEB;
  p24_L_703E();
  if (flag_nz()) goto lab_p24_L_5EEB;
  p00_L_1037();
  flag_cmp(a, 0x05);
  lab_p24_L_5EE4: ;
  if (flag_z()) goto lab_p24_L_5F92;
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p24_L_5EE4;
  lab_p24_L_5EEB: ;
  a = mem_read8(0x8478);
  flag_cmp(a, 0xFF);
  if (flag_z()) { p00_L_24F1(); return; }
  p00_L_17B0();
  if (flag_z()) goto lab_p24_L_5F71;
  p00_L_172A();
  if (flag_z()) goto lab_p24_L_5F03;
  set_hl(mem_read16(0x981C));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  lab_p24_L_5F03: ;
  p00_L_1857();
  cpu_pop_hl();
  if (flag_nz()) goto lab_p24_L_5F4A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p24_L_5F21;
  p00_L_019D();
  if (flag_z()) goto lab_p24_L_5F21;
  p00_L_18AE();
  if (flag_nc()) goto lab_p24_L_5F21;
  a = mem_read8(0x847A);
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) { p00_L_24FD(); return; }
  lab_p24_L_5F21: ;
  p24_L_7019();
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p24_L_5F33;
  p24_L_7005();
  a = 0x26;
  p24_L_688A();
  p00_rst18();
  goto lab_p24_L_5F7E;
  lab_p24_L_5F33: ;
  p24_L_5923();
  p00_L_1717();
  p24_L_5B18();
  goto lab_p24_L_5F7E;
  lab_p24_L_5F4A: ;
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  p00_L_1037();
  if (flag_z()) goto lab_p24_L_5F74;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p24_L_5F7E;
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p24_L_5F74;
  p00_L_182A();
  if (flag_nz()) goto lab_p24_L_5F66;
  set_hl(mem_read16(0x981C));
  p24_L_752A();
  lab_p24_L_5F66: ;
  p00_L_1037();
  flag_cmp(a, 0x03);
  if (flag_c()) goto lab_p24_L_5F81;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p24_L_5F81;
  lab_p24_L_5F71: ;
  p00_L_24DD();
  return;
  lab_p24_L_5F74: ;
  set_hl(mem_read16(0x981C));
  set_de(mem_read16(0x84DD));
  p24_L_664F();
  lab_p24_L_5F7E: ;
  p24_L_684A();
  return;
  lab_p24_L_5F81: ;
  p24_L_7019();
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p24_L_6001;
  p24_L_7005();
  lab_p24_L_5F8B: ;
  d = 0x29;
  p24_L_68C7();
  goto lab_p24_L_5F7E;
  lab_p24_L_5F92: ;
  cpu_pop_hl();
  p24_L_7093();
  if (flag_nz()) { p00_L_24D5(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x08)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p24_L_5FAC;
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 1)));
  p24_L_5920();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 1)));
  goto lab_p24_L_5FAF;
  lab_p24_L_5FAC: ;
  p24_L_5920();
  lab_p24_L_5FAF: ;
  goto lab_p24_L_5F7E;
  lab_p24_L_5FB1: ;
  p24_L_7093();
  if (flag_z()) goto lab_p24_L_5FDE;
  p24_L_7005();
  flag_cmp(a, 0x10);
  if (flag_nz()) { p00_L_24D5(); return; }
  a = mem_read8(0x8478);
  p24_L_660B();
  cpu_pop_af();
  mem_write8(0x8478, a);
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p24_L_5F8B;
  flag_cmp(a, 0x5C);
  if (flag_z()) goto lab_p24_L_5F8B;
  flag_cmp(a, 0x63);
  if (flag_nz()) goto lab_p24_L_5FDB;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x2A);
  if (flag_z()) goto lab_p24_L_5F8B;
  lab_p24_L_5FDB: ;
  p00_L_24DD();
  return;
  lab_p24_L_5FDE: ;
  p24_L_74C2();
  cpu_pop_bc();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x62);
  a = b;
  if (flag_nz()) goto lab_p24_L_5FF2;
  p00_L_22FC();
  p24_L_6128();
  goto lab_p24_L_5FF5;
  lab_p24_L_5FF2: ;
  p24_L_6171();
  lab_p24_L_5FF5: ;
  p00_L_1037();
  p00_L_1857();
  if (flag_z()) { p24_L_684A(); return; }
  p24_L_5BAF();
  return;
  lab_p24_L_6001: ;
  b = 0x00;
  p24_L_66D9();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x63);
  if (flag_nz()) goto lab_p24_L_5FAF;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x2A);
  if (flag_z()) p24_L_6661();
  goto lab_p24_L_5FAF;
}

/* flash page 24 cpu 0x5F2A (offset 0x1F2A) */
void p24_L_5F2A(void) {
  mem_write8(hl(), b);
  a = 0x26;
  p24_L_688A();
  p00_rst18();
  goto lab_p24_L_5F7E;
  lab_p24_L_5F7E: ;
  p24_L_684A();
  return;
}

/* flash page 24 cpu 0x5F3E (offset 0x1F3E) */
void p24_L_5F3E(void) {
  p00_L_1C39();
  p24_L_5F41();
  return;
}

/* flash page 24 cpu 0x5F41 (offset 0x1F41) */
void p24_L_5F41(void) {
  p00_L_128A();
  p00_L_11FD();
  p00_L_1135();
  return;
}

/* flash page 24 cpu 0x6026 (offset 0x2026) */
void p24_L_6026(void) {
  p24_L_6039();
  p00_L_172A();
  if (flag_z()) goto lab_p24_L_6030;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  lab_p24_L_6030: ;
  p00_rst20();
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_z()) goto lab_p24_L_604A;
  return;
  lab_p24_L_604A: ;
  p00_L_24F1();
  return;
}

/* flash page 24 cpu 0x6039 (offset 0x2039) */
void p24_L_6039(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p24_L_604A;
  p24_L_603F();
  return;
  lab_p24_L_604A: ;
  p00_L_24F1();
  return;
}

/* flash page 24 cpu 0x603F (offset 0x203F) */
void p24_L_603F(void) {
  l = a;
  h = 0x00;
  p00_L_1025();
  set_de(0x8A28);
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 24 cpu 0x604D (offset 0x204D) */
void p24_L_604D(void) {
  cpu_push_af();
  set_hl(0x606A);
  a = (uint8_t)(a + a);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  d = h;
  e = l;
  cpu_pop_af();
  flag_cmp(a, 0x2A);
  a = 0x00;
  if (flag_nz()) return;
  set_hl(0x91E0);
  set_de(0x91D9);
  a = 0x01;
  return;
}

/* flash page 24 cpu 0x60E8 (offset 0x20E8) */
void p24_L_60E8(void) {
  cpu_push_af();
  p00_L_2222();
  a = 0x01;
  mem_write8(0x849A, a);
  cpu_pop_af();
  mem_write8(0x849B, a);
  p24_L_604D();
  mem_write16(0x84DD, hl());
  p24_L_61A2();
  return;
}

/* flash page 24 cpu 0x60FF (offset 0x20FF) */
void p24_L_60FF(void) {
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_z()) { p00_L_24FD(); return; }
  p00_L_2222();
  p24_L_739A();
  p24_L_615D();
  return;
}

/* flash page 24 cpu 0x610F (offset 0x210F) */
void p24_L_610F(void) {
  p00_L_2222();
  p00_L_1689();
  p24_L_615D();
  return;
}

/* flash page 24 cpu 0x6117 (offset 0x2117) */
void p24_L_6117(void) {
  p00_L_2222();
  p00_L_168D();
  p24_L_615D();
  return;
}

/* flash page 24 cpu 0x611F (offset 0x211F) */
void p24_L_611F(void) {
  p00_L_2222();
  p00_L_16A6();
  p24_L_615D();
  return;
}

/* flash page 24 cpu 0x6127 (offset 0x2127) */
void p24_L_6127(void) {
  p00_rst18();
  p24_L_6128();
  return;
}

/* flash page 24 cpu 0x6128 (offset 0x2128) */
void p24_L_6128(void) {
  p00_L_187F();
  p00_L_1653();
  p00_L_1697();
  p24_L_615D();
  flag_set_z((mem_read8((uint16_t)(iy + 0x07)) & (1u << 5)) == 0);
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 1)) == 0);
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  p00_L_019D();
  if (flag_nz()) p00_L_0087();
  return;
}

/* flash page 24 cpu 0x614F (offset 0x214F) */
void p24_L_614F(void) {
  p00_L_2222();
  p00_L_16AA();
  p24_L_615D();
  return;
}

/* flash page 24 cpu 0x6157 (offset 0x2157) */
void p24_L_6157(void) {
  p00_L_2222();
  p00_L_16A2();
  p24_L_615D();
  return;
}

/* flash page 24 cpu 0x615D (offset 0x215D) */
void p24_L_615D(void) {
  a = 0xFF;
  mem_write8(0x8478, a);
  p00_L_241E();
  if (flag_nc()) goto lab_p24_L_616A;
  a = mem_read8(0x8479);
  lab_p24_L_616A: ;
  mem_write16(0x981C, hl());
  mem_write16(0x84DD, de());
  p24_L_6171();
  return;
}

/* flash page 24 cpu 0x6171 (offset 0x2171) */
void p24_L_6171(void) {
  cpu_push_af();
  a = mem_read8(0x8478);
  p24_L_660B();
  p00_L_10DD();
  p00_L_22FC();
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_z()) { p00_L_24FD(); return; }
  cpu_pop_af();
  flag_cmp(a, 0xAA);
  if (flag_z()) goto lab_p24_L_619F;
  flag_cmp(a, 0x62);
  if (flag_c()) { p24_L_6311(); return; }
  if (flag_nz()) goto lab_p24_L_619D;
  a = mem_read8(0x849B);
  flag_cmp(a, 0x21);
  if (flag_nz()) { p00_L_24E1(); return; }
  p24_L_6311();
  return;
  lab_p24_L_619D: ;
  flag_cmp(a, 0x72);
  lab_p24_L_619F: ;
  if (flag_z()) { p24_L_6311(); return; }
  p24_L_61A2();
  return;
}

/* flash page 24 cpu 0x61A2 (offset 0x21A2) */
void p24_L_61A2(void) {
  a = mem_read8(0x849B);
  flag_cmp(a, 0x2A);
  if (flag_nz()) goto lab_p24_L_61BB;
  p00_L_1037();
  p24_L_6557();
  flag_cmp(a, 0x08);
  if (flag_nc()) { p00_L_24ED(); return; }
  set_hl(mem_read16(0x981C));
  a = mem_read8(hl());
  p24_L_6475();
  return;
  lab_p24_L_61BB: ;
  p24_L_6545();
  if (flag_z()) goto lab_p24_L_6568;
  p00_L_1037();
  if (flag_nz()) { p00_L_24DD(); return; }
  p24_L_61C7();
  return;
  lab_p24_L_6568: ;
  set_hl(mem_read16(0x84DD));
  p00_L_3AC5();
  mem_write8(0x91CF, a);
  p00_L_1037();
  if (flag_nz()) goto lab_p24_L_6581;
  a = mem_read8(0x91CF);
  flag_cmp(a, 0x01);
  if (flag_nz()) p24_L_6531();
  p24_L_61C7();
  return;
  lab_p24_L_6581: ;
  flag_cmp(a, 0x0E);
  if (flag_nz()) goto lab_p24_L_6592;
  p24_L_6531();
  set_hl(mem_read16(0x84DD));
  a = mem_read8(hl());
  a = a & 0x40;
  flag_logic(a);
  a = a | 0x0E;
  flag_logic(a);
  mem_write8(hl(), a);
  return;
  lab_p24_L_6592: ;
  p24_L_6557();
  flag_cmp(a, 0x03);
  if (flag_nc()) { p00_L_24ED(); return; }
  cpu_push_af();
  p00_rst18();
  set_hl(0x91CF);
  cpu_cp_hl();
  if (flag_nz()) p24_L_6531();
  b = 0x01;
  set_hl(mem_read16(0x84DD));
  cpu_push_hl();
  a = mem_read8(hl());
  set_de(0x001B);
  set_hl((uint16_t)(hl() + de()));
  a = a & 0x40;
  flag_logic(a);
  /* or (hl) */
  mem_write8(hl(), a);
  cpu_pop_hl();
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_65BF;
  a = mem_read8(hl());
  a = a & 0x40;
  flag_logic(a);
  a = a | 0x0E;
  flag_logic(a);
  mem_write8(hl(), a);
  goto lab_p24_L_65DC;
  lab_p24_L_65BF: ;
  cpu_push_af();
  cpu_push_bc();
  cpu_push_hl();
  l = b;
  h = 0x00;
  set_de(mem_read16(0x84DF));
  p00_L_3AF5();
  cpu_pop_hl();
  cpu_push_hl();
  p24_L_629D();
  cpu_pop_hl();
  set_de(0x001B);
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p24_L_65BF;
  lab_p24_L_65DC: ;
  p00_L_219B();
  return;
}

/* flash page 24 cpu 0x61C7 (offset 0x21C7) */
void p24_L_61C7(void) {
  a = mem_read8(0x849B);
  flag_cmp(a, 0x0A);
  if (flag_c()) goto lab_p24_L_6220;
  flag_cmp(a, 0x0E);
  if (flag_nc()) goto lab_p24_L_61EE;
  cpu_push_af();
  p24_L_6227();
  p00_rst18();
  cpu_pop_af();
  set_hl(0x61EB);
  p00_L_25A2();
  flag_cmp(a, 0x0C);
  cpu_push_af();
  if (flag_nc()) p00_L_33D5();
  cpu_pop_af();
  if (flag_c()) p00_L_33DB();
  p00_L_25C8();
  p00_L_219B();
  return;
  lab_p24_L_61EE: ;
  flag_cmp(a, 0x1A);
  if (flag_c()) { p24_L_6227(); return; }
  if (flag_nz()) goto lab_p24_L_6203;
  p00_L_219B();
  set_hl(mem_read16(0x84DD));
  p24_L_73A3();
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) | (1u << 6)));
  return;
  lab_p24_L_6203: ;
  flag_cmp(a, 0x21);
  if (flag_nc()) goto lab_p24_L_6219;
  flag_cmp(a, 0x1D);
  if (flag_c()) goto lab_p24_L_62DB;
  p00_L_219B();
  p00_L_3E37();
  p00_L_14DB();
  if (flag_z()) goto lab_p24_L_622D;
  goto lab_p24_L_6235;
  lab_p24_L_6219: ;
  flag_cmp(a, 0x26);
  if (flag_nc()) goto lab_p24_L_6238;
  p00_L_1887();
  lab_p24_L_6220: ;
  p24_L_6297();
  return;
  lab_p24_L_622D: ;
  a = mem_read8(0x8479);
  flag_cmp(a, 0xE4);
  if (flag_c()) goto lab_p24_L_629A;
  lab_p24_L_6235: ;
  p00_L_24C9();
  return;
  lab_p24_L_6238: ;
  flag_cmp(a, 0x28);
  if (flag_nc()) goto lab_p24_L_628B;
  flag_cmp(a, 0x26);
  set_hl(mem_read16(0x8DA6));
  h = 0x00;
  set_de(0x8F50);
  b = 0x0B;
  if (flag_z()) goto lab_p24_L_6257;
  a = mem_read8(0x8DA3);
  a = (uint8_t)(a - 0x02);
  l = a;
  h = 0x00;
  set_de(0x8F6B);
  b = 0x0D;
  lab_p24_L_6257: ;
  cpu_push_bc();
  cpu_push_de();
  p00_L_3B55();
  p00_L_1887();
  p00_L_1873();
  p00_L_0D1F();
  cpu_pop_hl();
  p00_L_11F8();
  cpu_push_hl();
  p00_rst30();
  a = mem_read8(0x8479);
  flag_cmp(a, 0xE4);
  if (flag_nc()) goto lab_p24_L_6235;
  p00_L_15FB();
  cpu_pop_hl();
  cpu_pop_af();
  set_de(mem_read16(0x84DD));
  cpu_push_de();
  mem_write16(0x84DD, hl());
  p24_L_6225();
  cpu_pop_hl();
  mem_write16(0x84DD, hl());
  p24_L_6297();
  return;
  lab_p24_L_628B: ;
  flag_cmp(a, 0x2A);
  if (flag_nc()) goto lab_p24_L_62B3;
  p00_L_1251();
  p00_L_107E();
  if (flag_c()) goto lab_p24_L_6235;
  p24_L_6297();
  return;
  lab_p24_L_629A: ;
  set_hl(mem_read16(0x84DD));
  p24_L_629D();
  return;
  lab_p24_L_62B3: ;
  flag_cmp(a, 0x30);
  if (flag_c()) goto lab_p24_L_62D3;
  flag_cmp(a, 0x32);
  if (flag_nc()) goto lab_p24_L_62D3;
  cpu_push_af();
  p00_L_1884();
  p00_L_187F();
  cpu_pop_af();
  flag_cmp(a, 0x30);
  if (flag_nz()) { p24_L_6297(); return; }
  p00_rst18();
  p24_L_6297();
  p00_L_219B();
  a = 0x31;
  p24_L_60E8();
  return;
  lab_p24_L_62D3: ;
  flag_cmp(a, 0x34);
  if (flag_c()) { p24_L_6297(); return; }
  flag_cmp(a, 0x36);
  if (flag_nc()) goto lab_p24_L_62E6;
  lab_p24_L_62DB: ;
  p00_L_3E37();
  p00_L_14D1();
  if (flag_nz()) { p00_L_24C9(); return; }
  p24_L_6297();
  return;
  lab_p24_L_62E6: ;
  flag_cmp(a, 0x38);
  if (flag_nc()) { p24_L_6297(); return; }
  p00_L_3E37();
  p00_L_14D1();
  if (flag_nz()) { p00_L_24C9(); return; }
  a = mem_read8(0x8479);
  flag_cmp(a, 0x81);
  if (flag_nc()) goto lab_p24_L_6235;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x90);
  if (flag_nc()) goto lab_p24_L_6235;
  set_hl(mem_read16(0x84DD));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  p00_L_0013();
  if (flag_z()) { p24_L_6297(); return; }
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  p24_L_6297();
  return;
}

/* flash page 24 cpu 0x6223 (offset 0x2223) */
void p24_L_6223(void) {
  a = 0xFF;
  p24_L_6225();
  return;
}

/* flash page 24 cpu 0x6225 (offset 0x2225) */
void p24_L_6225(void) {
  goto lab_p24_L_622A;
  lab_p24_L_622A: ;
  p00_L_3E37();
  a = mem_read8(0x8479);
  flag_cmp(a, 0xE4);
  if (flag_c()) goto lab_p24_L_629A;
  p00_L_24C9();
  return;
  lab_p24_L_629A: ;
  set_hl(mem_read16(0x84DD));
  p24_L_629D();
  return;
}

/* flash page 24 cpu 0x6227 (offset 0x2227) */
void p24_L_6227(void) {
  p00_L_219B();
  p00_L_3E37();
  a = mem_read8(0x8479);
  flag_cmp(a, 0xE4);
  if (flag_c()) goto lab_p24_L_629A;
  p00_L_24C9();
  return;
  lab_p24_L_629A: ;
  set_hl(mem_read16(0x84DD));
  p24_L_629D();
  return;
}

/* flash page 24 cpu 0x6297 (offset 0x2297) */
void p24_L_6297(void) {
  p00_L_219B();
  set_hl(mem_read16(0x84DD));
  p24_L_629D();
  return;
}

/* flash page 24 cpu 0x629D (offset 0x229D) */
void p24_L_629D(void) {
  cpu_push_hl();
  p24_L_73A3();
  cpu_pop_hl();
  cpu_push_af();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  flag_set_z((b & (1u << 6)) == 0);
  if (flag_z()) goto lab_p24_L_62B1;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  cpu_pop_af();
  if (flag_z()) return;
  p00_L_0087();
  return;
  lab_p24_L_62B1: ;
  cpu_pop_af();
  return;
}

/* flash page 24 cpu 0x6311 (offset 0x2311) */
void p24_L_6311(void) {
  goto lab_p24_L_6311;
  lab_p24_L_6288: ;
  p00_L_24DD();
  return;
  lab_p24_L_6311: ;
  a = mem_read8(0x849A);
  b = a;
  p00_L_1037();
  if (flag_nz()) goto lab_p24_L_632F;
  lab_p24_L_631A: ;
  a = b;
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p24_L_6385;
  flag_cmp(a, 0x62);
  if (flag_z()) goto lab_p24_L_6385;
  flag_cmp(a, 0xAA);
  if (flag_z()) goto lab_p24_L_6288;
  flag_cmp(a, 0x5C);
  if (flag_nc()) goto lab_p24_L_6288;
  goto lab_p24_L_6385;
  lab_p24_L_632F: ;
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p24_L_631A;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p24_L_6362;
  flag_cmp(a, 0x0B);
  if (flag_z()) goto lab_p24_L_6344;
  flag_cmp(a, 0x05);
  if (flag_nc()) { p00_L_24D5(); return; }
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p24_L_635C;
  lab_p24_L_6344: ;
  a = b;
  flag_cmp(a, 0x5E);
  if (flag_z()) goto lab_p24_L_6355;
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p24_L_6355;
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p24_L_637B;
  flag_cmp(a, 0xAA);
  goto lab_p24_L_636B;
  lab_p24_L_6355: ;
  p00_L_23CC();
  mem_write8(hl(), 0x03);
  goto lab_p24_L_637B;
  lab_p24_L_635C: ;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_6344;
  flag_cmp(a, 0x01);
  lab_p24_L_6362: ;
  a = b;
  if (flag_nz()) goto lab_p24_L_6369;
  flag_cmp(a, 0x5D);
  goto lab_p24_L_636B;
  lab_p24_L_6369: ;
  flag_cmp(a, 0x5C);
  lab_p24_L_636B: ;
  cpu_push_af();
  flag_cmp(a, 0x72);
  if (flag_nz()) goto lab_p24_L_6373;
  lab_p24_L_6370: ;
  cpu_pop_af();
  goto lab_p24_L_637B;
  lab_p24_L_6373: ;
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p24_L_6370;
  cpu_pop_af();
  if (flag_nz()) goto lab_p24_L_6288;
  lab_p24_L_637B: ;
  p24_L_7516();
  mem_write16(0x981E, hl());
  mem_write16(0x84DF, de());
  lab_p24_L_6385: ;
  a = mem_read8(0x8499);
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p24_L_643D;
  p00_L_1037();
  set_hl(mem_read16(0x981C));
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p24_L_63E4;
  a = mem_read8(0x849A);
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p24_L_63E4;
  cpu_push_hl();
  set_hl(mem_read16(0x84DF));
  p00_L_0033();
  a = h;
  a = a | l;
  flag_logic(a);
  cpu_pop_hl();
  if (flag_nz()) goto lab_p24_L_63B4;
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 3)));
  p24_L_74F1();
  p24_L_6510();
  return;
  lab_p24_L_63B4: ;
  p00_L_1EF4();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_63C8;
  p24_L_65DF();
  cpu_push_af();
  lab_p24_L_63BE: ;
  cpu_push_hl();
  p00_L_1EF4();
  mem_write8(hl(), 0x00);
  cpu_pop_hl();
  p24_L_6506();
  return;
  lab_p24_L_63C8: ;
  cpu_push_af();
  p00_rst18();
  p00_L_11EA();
  cpu_pop_hl();
  cpu_push_hl();
  l = 0x3F;
  p00_L_1671();
  p24_L_615D();
  set_hl(mem_read16(0x981C));
  mem_write8(hl(), 0x03);
  p00_L_1130();
  p00_L_241E();
  goto lab_p24_L_63BE;
  lab_p24_L_63E4: ;
  a = mem_read8(hl());
  cpu_push_af();
  p00_L_1CF3();
  p00_L_1135();
  p00_L_182A();
  if (flag_z()) p24_L_74F1();
  a = mem_read8(0x8479);
  flag_cmp(a, 0xAA);
  if (flag_nz()) goto lab_p24_L_6409;
  set_hl(mem_read16(0x981C));
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p24_L_6419;
  a = mem_read8(hl());
  a = a & 0xE0;
  flag_logic(a);
  a = a | 0x04;
  flag_logic(a);
  mem_write8(hl(), a);
  lab_p24_L_6409: ;
  p00_L_18AE();
  if (flag_nc()) goto lab_p24_L_6419;
  set_hl(mem_read16(0x981C));
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_6419;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  lab_p24_L_6419: ;
  p00_L_17E9();
  goto lab_p24_L_6476;
  lab_p24_L_641E: ;
  p00_L_1C75();
  p24_L_646D();
  return;
  lab_p24_L_6423: ;
  p00_L_1C32();
  mem_write16(0x84DD, de());
  a = 0;
  flag_logic(a);
  cpu_push_af();
  p00_L_2148();
  lab_p24_L_642F: ;
  set_hl(mem_read16(0x84DD));
  a = a | 0x01;
  flag_logic(a);
  cpu_push_af();
  cpu_ex_de_hl();
  p00_L_1063();
  cpu_pop_af();
  p24_L_64C4();
  return;
  lab_p24_L_643D: ;
  p00_L_1037();
  p00_L_1135();
  set_hl(mem_read16(0x84DF));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  cpu_ex_de_hl();
  flag_cmp(a, 0x01);
  if (flag_c()) goto lab_p24_L_64AF;
  if (flag_z()) goto lab_p24_L_646A;
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p24_L_6423;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p24_L_641E;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p24_L_64DF;
  flag_cmp(a, 0x0B);
  if (flag_z()) goto lab_p24_L_64DF;
  flag_cmp(a, 0x03);
  if (flag_c()) goto lab_p24_L_64DA;
  if (flag_z()) goto lab_p24_L_64DF;
  p00_L_24D5();
  return;
  lab_p24_L_646A: ;
  p00_L_1C46();
  p24_L_646D();
  return;
  lab_p24_L_6476: ;
  p00_L_2176();
  a = mem_read8(0x8478);
  mem_write8(0x8499, a);
  a = a & 0x1F;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_64BE;
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p24_L_642F;
  set_hl(mem_read16(0x84DF));
  p00_L_210A();
  b = d;
  c = e;
  set_de(mem_read16(0x84DD));
  while (bc() != 0) { cpu_ldi(); }
  a = mem_read8(0x8479);
  flag_cmp(a, 0x24);
  if (flag_nz()) goto lab_p24_L_64A1;
  set_hl(mem_read16(0x981E));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  lab_p24_L_64A1: ;
  p00_L_1135();
  p00_L_18AE();
  cpu_pop_hl();
  cpu_push_hl();
  if (flag_c()) p00_L_380D();
  cpu_pop_hl();
  goto lab_p24_L_64C6;
  lab_p24_L_64AF: ;
  p00_L_1C39();
  mem_write16(0x981C, hl());
  mem_write16(0x84DD, de());
  a = 0;
  flag_logic(a);
  cpu_push_af();
  p00_L_219B();
  lab_p24_L_64BE: ;
  set_hl(mem_read16(0x84DD));
  p24_L_73A3();
  p24_L_64C4();
  return;
  lab_p24_L_64C6: ;
  flag_set_z((h & (1u << 6)) == 0);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 3)) == 0);
  if (flag_nz()) return;
  p00_L_172A();
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  p00_L_0087();
  return;
  lab_p24_L_64DA: ;
  p00_L_1C81();
  p24_L_646D();
  return;
  lab_p24_L_64DF: ;
  a = mem_read8(0x8479);
  flag_cmp(a, 0xAA);
  if (flag_nz()) goto lab_p24_L_64EB;
  p00_L_1C8F();
  p24_L_646D();
  return;
  lab_p24_L_64EB: ;
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p24_L_6521;
  set_hl(0x0000);
  p00_L_1C46();
  set_hl(mem_read16(0x84DF));
  p00_L_0033();
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) { p24_L_6510(); return; }
  p00_L_22FC();
  p24_L_65DF();
  cpu_push_af();
  p24_L_6506();
  return;
  lab_p24_L_6521: ;
  cpu_push_hl();
  a = mem_read8(0x847A);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) p24_L_661D();
  cpu_pop_hl();
  p00_L_1CA8();
  p24_L_646D();
  return;
}

/* flash page 24 cpu 0x646D (offset 0x246D) */
void p24_L_646D(void) {
  mem_write16(0x84DD, de());
  mem_write16(0x981C, hl());
  a = 0;
  flag_logic(a);
  p24_L_6475();
  return;
}

/* flash page 24 cpu 0x6475 (offset 0x2475) */
void p24_L_6475(void) {
  goto lab_p24_L_6475;
  lab_p24_L_642F: ;
  set_hl(mem_read16(0x84DD));
  a = a | 0x01;
  flag_logic(a);
  cpu_push_af();
  cpu_ex_de_hl();
  p00_L_1063();
  cpu_pop_af();
  p24_L_64C4();
  return;
  lab_p24_L_6475: ;
  cpu_push_af();
  p00_L_2176();
  a = mem_read8(0x8478);
  mem_write8(0x8499, a);
  a = a & 0x1F;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_64BE;
  flag_cmp(a, 0x0C);
  if (flag_z()) goto lab_p24_L_642F;
  set_hl(mem_read16(0x84DF));
  p00_L_210A();
  b = d;
  c = e;
  set_de(mem_read16(0x84DD));
  while (bc() != 0) { cpu_ldi(); }
  a = mem_read8(0x8479);
  flag_cmp(a, 0x24);
  if (flag_nz()) goto lab_p24_L_64A1;
  set_hl(mem_read16(0x981E));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  lab_p24_L_64A1: ;
  p00_L_1135();
  p00_L_18AE();
  cpu_pop_hl();
  cpu_push_hl();
  if (flag_c()) p00_L_380D();
  cpu_pop_hl();
  goto lab_p24_L_64C6;
  lab_p24_L_64BE: ;
  set_hl(mem_read16(0x84DD));
  p24_L_73A3();
  p24_L_64C4();
  return;
  lab_p24_L_64C6: ;
  flag_set_z((h & (1u << 6)) == 0);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 3)) == 0);
  if (flag_nz()) return;
  p00_L_172A();
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  p00_L_0087();
  return;
}

/* flash page 24 cpu 0x64C4 (offset 0x24C4) */
void p24_L_64C4(void) {
  cpu_pop_hl();
  if (flag_z()) return;
  flag_set_z((h & (1u << 6)) == 0);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 3)) == 0);
  if (flag_nz()) return;
  p00_L_172A();
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  p00_L_0087();
  return;
}

/* flash page 24 cpu 0x6506 (offset 0x2506) */
void p24_L_6506(void) {
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_0087();
  p00_L_1EF4();
  cpu_pop_af();
  mem_write8(hl(), a);
  p24_L_6510();
  return;
}

/* flash page 24 cpu 0x6510 (offset 0x2510) */
void p24_L_6510(void) {
  p00_L_219B();
  p00_L_1641();
  if (flag_nz()) goto lab_p24_L_651B;
  p00_rst10();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  lab_p24_L_651B: ;
  a = 0x04;
  mem_write8(0x8478, a);
  return;
}

/* flash page 24 cpu 0x6531 (offset 0x2531) */
void p24_L_6531(void) {
  p24_L_654E();
  a = mem_read8(hl());
  a = a & 0x40;
  flag_logic(a);
  set_de(0x001B);
  set_hl((uint16_t)(hl() + de()));
  a = (uint8_t)(a + 0x0E);
  mem_write8(hl(), a);
  return;
}

/* flash page 24 cpu 0x6545 (offset 0x2545) */
void p24_L_6545(void) {
  set_hl(0x653F);
  set_bc(0x0006);
  /* cpir */
  return;
}

/* flash page 24 cpu 0x654E (offset 0x254E) */
void p24_L_654E(void) {
  set_hl(mem_read16(0x84DD));
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_0087();
  return;
}

/* flash page 24 cpu 0x6557 (offset 0x2557) */
void p24_L_6557(void) {
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p24_L_661A;
  p24_L_7516();
  mem_write16(0x981E, hl());
  mem_write16(0x84DF, de());
  a = mem_read8(de());
  return;
  lab_p24_L_661A: ;
  p00_L_24DD();
  return;
}

/* flash page 24 cpu 0x65DF (offset 0x25DF) */
void p24_L_65DF(void) {
  p00_rst18();
  p00_L_11EA();
  p24_L_74DA();
  h = a;
  l = 0x3F;
  p00_L_1671();
  p24_L_615D();
  set_hl(mem_read16(0x981C));
  mem_write8(hl(), 0x03);
  a = mem_read8(0x847A);
  cpu_push_af();
  p00_L_25E7();
  /* or (hl) */
  mem_write8(hl(), a);
  p00_L_1130();
  p00_rst10();
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_af();
  p00_L_1EF4();
  cpu_pop_af();
  mem_write8(hl(), a);
  cpu_pop_hl();
  return;
}

/* flash page 24 cpu 0x660B (offset 0x260B) */
void p24_L_660B(void) {
  flag_cmp(a, 0xFF);
  if (flag_z()) return;
  a = a & 0x0F;
  flag_logic(a);
  flag_cmp(a, 0x05);
  if (flag_c()) return;
  flag_cmp(a, 0x0E);
  if (flag_nc()) goto lab_p24_L_661A;
  flag_cmp(a, 0x0B);
  if (flag_nc()) return;
  lab_p24_L_661A: ;
  p00_L_24DD();
  return;
}

/* flash page 24 cpu 0x661D (offset 0x261D) */
void p24_L_661D(void) {
  cpu_push_hl();
  e = 0x10;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  p00_L_23BD();
  p00_rst18();
  a = mem_read8(0x847A);
  a = a ^ 0x01;
  flag_logic(a);
  mem_write8(0x847A, a);
  set_hl(0x0000);
  p00_L_1CA8();
  p00_L_219B();
  cpu_pop_hl();
  return;
}

/* flash page 24 cpu 0x663A (offset 0x263A) */
void p24_L_663A(void) {
  p24_L_739A();
  p24_L_664C();
  return;
}

/* flash page 24 cpu 0x663F (offset 0x263F) */
void p24_L_663F(void) {
  p00_L_16A6();
  p24_L_664C();
  return;
}

/* flash page 24 cpu 0x6644 (offset 0x2644) */
void p24_L_6644(void) {
  p00_L_1697();
  p24_L_664C();
  return;
}

/* flash page 24 cpu 0x6649 (offset 0x2649) */
void p24_L_6649(void) {
  p00_L_16A2();
  p24_L_664C();
  return;
}

/* flash page 24 cpu 0x664C (offset 0x264C) */
void p24_L_664C(void) {
  p00_L_2429();
  p24_L_664F();
  return;
}

/* flash page 24 cpu 0x664F (offset 0x264F) */
void p24_L_664F(void) {
  a = mem_read8(0x8479);
  flag_cmp(a, 0x63);
  if (flag_nz()) goto lab_p24_L_66B2;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x2A);
  if (flag_nz()) goto lab_p24_L_667C;
  p24_L_6661();
  return;
  lab_p24_L_667C: ;
  cpu_push_hl();
  p24_L_6545();
  cpu_pop_hl();
  if (flag_nz()) goto lab_p24_L_66B2;
  cpu_ex_de_hl();
  cpu_push_hl();
  p00_L_3AC5();
  cpu_push_af();
  l = a;
  h = 0x00;
  p00_L_1847();
  p00_L_39AB();
  cpu_pop_af();
  cpu_pop_hl();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_push_hl();
  a = (uint8_t)(a + 1);
  lab_p24_L_6698: ;
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p24_L_66A4;
  p00_L_1183();
  set_bc(0x0012);
  set_hl((uint16_t)(hl() + bc()));
  goto lab_p24_L_6698;
  lab_p24_L_66A4: ;
  cpu_pop_hl();
  p00_L_172A();
  if (flag_z()) goto lab_p24_L_66AC;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  lab_p24_L_66AC: ;
  p00_L_1135();
  p24_L_66D7();
  return;
  lab_p24_L_66B2: ;
  p00_L_1037();
  if (flag_z()) goto lab_p24_L_66C1;
  flag_cmp(a, 0x0C);
  if (flag_nz()) return;
  cpu_ex_de_hl();
  p00_rst20();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1183();
  return;
  lab_p24_L_66C1: ;
  cpu_ex_de_hl();
  goto lab_p24_L_66D0;
  lab_p24_L_66D0: ;
  p00_rst20();
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  return;
}

/* flash page 24 cpu 0x6661 (offset 0x2661) */
void p24_L_6661(void) {
  set_hl(0x91E0);
  a = 0x01;
  p00_L_210A();
  cpu_push_de();
  p00_L_0033();
  p00_L_1847();
  p00_L_39AB();
  cpu_pop_bc();
  set_hl(0x91E0);
  while (bc() != 0) { cpu_ldi(); }
  p00_L_1135();
  return;
}

/* flash page 24 cpu 0x66C4 (offset 0x26C4) */
void p24_L_66C4(void) {
  p24_L_604D();
  p00_L_172A();
  if (flag_z()) goto lab_p24_L_66D0;
  cpu_ex_de_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  cpu_ex_de_hl();
  lab_p24_L_66D0: ;
  p00_rst20();
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  return;
}

/* flash page 24 cpu 0x66D7 (offset 0x26D7) */
void p24_L_66D7(void) {
  b = 0x01;
  p24_L_66D9();
  return;
}

/* flash page 24 cpu 0x66D9 (offset 0x26D9) */
void p24_L_66D9(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p24_L_66E3;
  p00_L_172A();
  if (flag_z()) return;
  lab_p24_L_66E3: ;
  p00_L_019D();
  if (flag_nz()) return;
  set_hl(mem_read16(0x9665));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) return;
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  p00_L_1830();
  if (flag_nz()) return;
  /* rlc b */
  if (flag_z()) goto lab_p24_L_6704;
  p00_L_241E();
  mem_write16(0x84DD, de());
  mem_write16(0x981C, hl());
  lab_p24_L_6704: ;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x24);
  if (flag_nz()) goto lab_p24_L_6710;
  set_hl(mem_read16(0x981C));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  lab_p24_L_6710: ;
  set_hl(mem_read16(0x84DD));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_z()) { p00_L_24ED(); return; }
  a = mem_read8(0x859A);
  flag_cmp(a, 0x4A);
  if (flag_nz()) goto lab_p24_L_672F;
  p00_L_18B7();
  if (flag_z()) goto lab_p24_L_6784;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1F)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p24_L_6784;
  goto lab_p24_L_673B;
  lab_p24_L_672F: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1F)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p24_L_6784;
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p24_L_6784;
  lab_p24_L_673B: ;
  set_hl(mem_read16(0x9810));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_6758;
  mem_write16(0x9810, de());
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p24_L_675E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p24_L_6784;
  mem_write16(0x980E, de());
  goto lab_p24_L_6784;
  lab_p24_L_6758: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nz()) { p00_L_24E9(); return; }
  lab_p24_L_675E: ;
  p00_L_172A();
  if (flag_z()) goto lab_p24_L_6784;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p24_L_6784;
  set_hl(mem_read16(0x980E));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_push_af();
  a = mem_read8(0x8D1B);
  set_hl(mem_read16(0x980C));
  set_de(0x0012);
  set_hl((uint16_t)(hl() + de()));
  p00_L_25EA();
  b = a;
  cpu_pop_af();
  a = b;
  if (flag_nc()) goto lab_p24_L_678F;
  /* or (hl) */
  mem_write8(hl(), a);
  lab_p24_L_6784: ;
  set_de(mem_read16(0x84DD));
  set_hl(mem_read16(0x980E));
  p00_L_3AF5();
  return;
  lab_p24_L_678F: ;
  cpu_push_af();
  a = a ^ 0xFF;
  /* and (hl) */
  mem_write8(hl(), a);
  cpu_pop_af();
  if (flag_z()) goto lab_p24_L_6784;
  p00_L_24BD();
  return;
}

/* flash page 24 cpu 0x67DA (offset 0x27DA) */
void p24_L_67DA(void) {
  p00_L_018E();
  if (flag_z()) { p00_L_24D5(); return; }
  set_hl(0x0001);
  p24_L_6984();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  p24_L_684A();
  return;
}

/* flash page 24 cpu 0x67EC (offset 0x27EC) */
void p24_L_67EC(void) {
  cpu_push_af();
  p24_L_688A();
  cpu_pop_af();
  flag_cmp(a, 0x22);
  if (flag_c()) { p24_L_684A(); return; }
  flag_cmp(a, 0x29);
  if (flag_nc()) { p24_L_684A(); return; }
  p24_L_6F5C();
  p24_L_7002();
  d = a;
  p24_L_68C7();
  p24_L_7046();
  cpu_push_af();
  p24_L_70AC();
  p24_L_7370();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x62);
  if (flag_z()) goto lab_p24_L_681C;
  flag_cmp(a, 0x41);
  if (flag_c()) goto lab_p24_L_6836;
  flag_cmp(a, 0x5C);
  if (flag_nc()) goto lab_p24_L_6836;
  lab_p24_L_681C: ;
  cpu_pop_af();
  if (flag_z()) goto lab_p24_L_6833;
  flag_cmp(a, 0x2B);
  if (flag_z()) goto lab_p24_L_6833;
  flag_cmp(a, 0x11);
  if (flag_z()) goto lab_p24_L_6833;
  flag_cmp(a, 0xF4);
  if (flag_nc()) goto lab_p24_L_682F;
  flag_cmp(a, 0xF2);
  if (flag_nc()) goto lab_p24_L_6833;
  lab_p24_L_682F: ;
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p24_L_6836;
  lab_p24_L_6833: ;
  p24_L_5BAF();
  return;
  lab_p24_L_6836: ;
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x6846 (offset 0x2846) */
void p24_L_6846(void) {
  p24_L_689B();
  /* ei */
  p24_L_684A();
  return;
}

/* flash page 24 cpu 0x684A (offset 0x284A) */
void p24_L_684A(void) {
  p24_L_7002();
  p24_L_5974();
  return;
}

/* flash page 24 cpu 0x6852 (offset 0x2852) */
void p24_L_6852(void) {
  cpu_push_af();
  p24_L_6895();
  cpu_pop_af();
  p24_L_74B1();
  p24_L_685A();
  return;
}

/* flash page 24 cpu 0x685A (offset 0x285A) */
void p24_L_685A(void) {
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  p24_L_684A();
  return;
}

/* flash page 24 cpu 0x686A (offset 0x286A) */
void p24_L_686A(void) {
  set_hl(0x687B);
  set_bc(0x000F);
  /* cpir */
  if (flag_nz()) return;
  p24_L_6873();
  return;
}

/* flash page 24 cpu 0x6873 (offset 0x2873) */
void p24_L_6873(void) {
  set_hl(mem_read16(0x9665));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x9665, hl());
  return;
}

/* flash page 24 cpu 0x688A (offset 0x288A) */
void p24_L_688A(void) {
  cpu_push_af();
  p24_L_6895();
  cpu_pop_af();
  cpu_push_af();
  p24_L_686A();
  goto lab_p24_L_68D0;
  lab_p24_L_68D0: ;
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  cpu_pop_af();
  p24_L_74B1();
  return;
}

/* flash page 24 cpu 0x6895 (offset 0x2895) */
void p24_L_6895(void) {
  a = 0x82;
  p00_L_018E();
  if (flag_z()) return;
  p24_L_689B();
  return;
}

/* flash page 24 cpu 0x689B (offset 0x289B) */
void p24_L_689B(void) {
  /* ei */
  d = a;
  flag_cmp(a, 0xF4);
  if (flag_nc()) goto lab_p24_L_68A6;
  flag_cmp(a, 0xF2);
  if (flag_c()) goto lab_p24_L_68A6;
  a = 0;
  flag_logic(a);
  lab_p24_L_68A6: ;
  a = a & 0xF0;
  flag_logic(a);
  e = a;
  p24_L_7020();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_68E2;
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  p00_L_018E();
  if (flag_z()) { p00_L_24D5(); return; }
  flag_cmp(a, 0xF4);
  if (flag_nc()) goto lab_p24_L_68BF;
  flag_cmp(a, 0xF2);
  if (flag_nc()) return;
  lab_p24_L_68BF: ;
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p24_L_68D8;
  a = d;
  flag_cmp(a, 0x04);
  if (flag_c()) return;
  p24_L_68C7();
  return;
  lab_p24_L_68D8: ;
  flag_cmp(a, 0x12);
  if (flag_c()) goto lab_p24_L_690D;
  flag_cmp(a, 0x2B);
  if (flag_z()) goto lab_p24_L_690D;
  p24_L_68C7();
  return;
  lab_p24_L_68E2: ;
  b = a;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p24_L_690D;
  p00_L_018E();
  if (flag_nz()) goto lab_p24_L_68F5;
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p24_L_690D;
  a = d;
  flag_cmp(a, 0x08);
  if (flag_nc()) goto lab_p24_L_690D;
  lab_p24_L_68F5: ;
  a = d;
  flag_cmp(a, 0x2B);
  if (flag_nz()) goto lab_p24_L_691D;
  a = b;
  flag_cmp(a, 0x2B);
  if (flag_nz()) goto lab_p24_L_6910;
  p24_L_7026();
  flag_cmp(a, 0x10);
  if (flag_nz()) { p24_L_68C7(); return; }
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0x01);
  if (flag_z()) { p24_L_68C7(); return; }
  lab_p24_L_690D: ;
  p00_L_24D5();
  return;
  lab_p24_L_6910: ;
  flag_cmp(a, 0x2A);
  if (flag_c()) { p24_L_68C7(); return; }
  p24_L_74C9();
  if (flag_nc()) { p24_L_68C7(); return; }
  p24_L_694C();
  return;
  lab_p24_L_691D: ;
  flag_cmp(a, 0x07);
  if (flag_z()) goto lab_p24_L_6925;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p24_L_692E;
  lab_p24_L_6925: ;
  a = b;
  flag_cmp(a, 0x10);
  if (flag_c()) goto lab_p24_L_692E;
  flag_cmp(a, 0x2A);
  if (flag_c()) goto lab_p24_L_690D;
  lab_p24_L_692E: ;
  a = b;
  p24_L_74C9();
  if (flag_c()) goto lab_p24_L_693B;
  c = a;
  a = 0x28;
  lab_p24_L_6937: ;
  flag_cmp(a, e);
  a = c;
  p24_L_6949();
  return;
  lab_p24_L_693B: ;
  flag_cmp(a, 0x89);
  if (flag_c()) goto lab_p24_L_6948;
  flag_cmp(a, 0x93);
  if (flag_nc()) goto lab_p24_L_6948;
  c = a;
  a = 0xC2;
  goto lab_p24_L_6937;
  lab_p24_L_6948: ;
  flag_cmp(a, e);
  p24_L_6949();
  return;
}

/* flash page 24 cpu 0x68C7 (offset 0x28C7) */
void p24_L_68C7(void) {
  a = 0x11;
  flag_cmp(a, d);
  if (flag_z()) goto lab_p24_L_690D;
  cpu_push_de();
  p00_L_2222();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  cpu_pop_af();
  p24_L_74B1();
  return;
  lab_p24_L_690D: ;
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x6949 (offset 0x2949) */
void p24_L_6949(void) {
  if (flag_c()) { p24_L_68C7(); return; }
  p24_L_694C();
  return;
}

/* flash page 24 cpu 0x694C (offset 0x294C) */
void p24_L_694C(void) {
  e = b;
  cpu_push_de();
  p24_L_74C2();
  set_hl(mem_read16(0x9661));
  p24_L_74C9();
  if (flag_nc()) goto lab_p24_L_696E;
  flag_cmp(a, 0x89);
  if (flag_c()) goto lab_p24_L_6961;
  flag_cmp(a, 0x93);
  if (flag_c()) goto lab_p24_L_696E;
  lab_p24_L_6961: ;
  flag_cmp(a, 0x3C);
  if (flag_c()) goto lab_p24_L_696E;
  flag_cmp(a, 0xA1);
  if (flag_c()) goto lab_p24_L_696D;
  flag_cmp(a, 0xE0);
  if (flag_c()) goto lab_p24_L_696E;
  lab_p24_L_696D: ;
  set_hl((uint16_t)(hl() + 1));
  lab_p24_L_696E: ;
  p24_L_6984();
  cpu_pop_de();
  a = d;
  flag_cmp(a, 0x11);
  if (flag_nz()) { p24_L_689B(); return; }
  a = e;
  flag_cmp(a, 0x2B);
  if (flag_c()) return;
  p24_L_74C9();
  if (flag_nc()) return;
  a = d;
  p24_L_689B();
  return;
}

/* flash page 24 cpu 0x6984 (offset 0x2984) */
void p24_L_6984(void) {
  flag_cmp(a, 0x08);
  if (flag_z()) goto lab_p24_L_6A90;
  /* rlc h */
  if (flag_nz()) { p00_L_24E5(); return; }
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p24_L_6A34;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p24_L_6FD7;
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p24_L_6A27;
  flag_cmp(a, 0x29);
  if (flag_z()) goto lab_p24_L_6AD1;
  flag_cmp(a, 0x2B);
  if (flag_z()) goto lab_p24_L_69F9;
  flag_cmp(a, 0x84);
  if (flag_c()) goto lab_p24_L_69B4;
  flag_cmp(a, 0x89);
  if (flag_nc()) goto lab_p24_L_69B4;
  p00_L_2D75();
  goto lab_p24_L_69D4;
  lab_p24_L_69B4: ;
  b = a;
  a = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_2D69();
  if (flag_nz()) goto lab_p24_L_69D4;
  a = b;
  l = (uint8_t)(l - 1);
  if (flag_z()) goto lab_p24_L_69E5;
  l = (uint8_t)(l - 1);
  if (flag_z()) goto lab_p24_L_69EA;
  l = (uint8_t)(l - 1);
  if (flag_z()) goto lab_p24_L_69EF;
  l = (uint8_t)(l - 1);
  if (flag_z()) goto lab_p24_L_69F4;
  l = (uint8_t)(l - 1);
  if (flag_nz()) { p00_L_24E5(); return; }
  p00_L_39C3();
  lab_p24_L_69D4: ;
  p00_L_15FB();
  p24_L_66D7();
  p24_L_69DA();
  return;
  lab_p24_L_69E5: ;
  p00_L_39B1();
  goto lab_p24_L_69D4;
  lab_p24_L_69EA: ;
  p00_L_3993();
  goto lab_p24_L_69D4;
  lab_p24_L_69EF: ;
  p00_L_39B7();
  goto lab_p24_L_69D4;
  lab_p24_L_69F4: ;
  p00_L_39BD();
  goto lab_p24_L_69D4;
  lab_p24_L_69F9: ;
  set_hl(mem_read16(0x9661));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x9661, hl());
  p24_L_7020();
  flag_cmp(a, 0x2B);
  if (flag_nz()) return;
  p24_L_74C2();
  goto lab_p24_L_69F9;
  lab_p24_L_6A27: ;
  cpu_push_hl();
  p24_L_7020();
  flag_cmp(a, 0x01);
  cpu_pop_hl();
  if (flag_z()) goto lab_p24_L_6FD4;
  l = (uint8_t)(l - 1);
  if (flag_z()) { p24_L_69DA(); return; }
  lab_p24_L_6A34: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p24_L_6A64;
  p00_L_018E();
  if (flag_z()) { p00_L_24D5(); return; }
  mem_write8((uint16_t)(iy + 0x06), (uint8_t)(mem_read8((uint16_t)(iy + 0x06)) & ~(1u << 6)));
  cpu_push_hl();
  p00_rst18();
  cpu_pop_bc();
  a = mem_read8(0x9663);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_6A51;
  a = c;
  mem_write8(0x9663, a);
  lab_p24_L_6A51: ;
  flag_cmp(a, c);
  if (flag_nz()) { p00_L_24ED(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 7)) == 0);
  if (flag_z()) { p00_L_24D5(); return; }
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  a = 0x07;
  goto lab_p24_L_6A82;
  lab_p24_L_6A64: ;
  p00_L_018E();
  if (flag_nz()) { p00_L_24D5(); return; }
  mem_write8((uint16_t)(iy + 0x06), (uint8_t)(mem_read8((uint16_t)(iy + 0x06)) & ~(1u << 7)));
  set_hl(mem_read16(0x9663));
  p00_L_1C7B();
  goto lab_p24_L_6A76;
  lab_p24_L_6A76: ;
  p24_L_6CDA();
  p00_L_1135();
  a = 0x07;
  lab_p24_L_6A7E: ;
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  lab_p24_L_6A82: ;
  set_hl(0x0001);
  mem_write16(0x9661, hl());
  cpu_pop_de();
  cpu_pop_de();
  flag_cmp(a, d);
  if (flag_z()) return;
  a = d;
  p24_L_689B();
  return;
  lab_p24_L_6A90: ;
  mem_write8((uint16_t)(iy + 0x06), (uint8_t)(mem_read8((uint16_t)(iy + 0x06)) & ~(1u << 5)));
  mem_write16(0x9663, hl());
  set_de(0x03E8);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) { p00_L_24ED(); return; }
  p00_L_2222();
  set_bc(mem_read16(0x9663));
  p24_L_6A0B();
  set_hl(mem_read16(0x9663));
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p24_L_6AB8;
  p00_L_1C6F();
  goto lab_p24_L_6ABB;
  lab_p24_L_6AB8: ;
  p00_L_1C40();
  lab_p24_L_6ABB: ;
  mem_write16(0x84DD, de());
  mem_write16(0x981C, hl());
  p24_L_6D35();
  p00_L_1135();
  b = 0x00;
  p24_L_66D9();
  a = 0x09;
  goto lab_p24_L_6A7E;
  lab_p24_L_6AD1: ;
  a = l;
  flag_cmp(a, 0x03);
  if (flag_nc()) { p00_L_24E5(); return; }
  mem_write8(0x8485, a);
  b = a;
  cpu_push_bc();
  p24_L_7020();
  mem_write8(0x8484, a);
  goto lab_p24_L_6AE8;
  lab_p24_L_6AE4: ;
  cpu_push_bc();
  p00_L_2176();
  lab_p24_L_6AE8: ;
  set_hl(0x03E7);
  p24_L_71E7();
  b = d;
  c = e;
  p24_L_7498();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p24_L_6AE4;
  p00_L_219B();
  a = mem_read8(0x8484);
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p24_L_6C6F;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_push_de();
  cpu_push_bc();
  /* rlc d */
  if (flag_nz()) p24_L_5BE1();
  p24_L_6B2B();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  set_hl(0x0001);
  mem_write16(0x9661, hl());
  p24_L_74C2();
  return;
  lab_p24_L_6C6F: ;
  p24_L_7516();
  mem_write16(0x84DD, de());
  p00_L_172A();
  if (flag_z()) goto lab_p24_L_6C7D;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  lab_p24_L_6C7D: ;
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p24_L_6C98;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p24_L_6C98;
  a = mem_read8(0x8485);
  flag_cmp(a, 0x02);
  if (flag_nz()) { p00_L_24E5(); return; }
  p24_L_6CA6();
  p00_L_3B7F();
  lab_p24_L_6C95: ;
  p24_L_69DA();
  return;
  lab_p24_L_6C98: ;
  p24_L_6CBB();
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p24_L_6CB8;
  h = b;
  l = c;
  p00_L_3AF5();
  goto lab_p24_L_6C95;
  lab_p24_L_6CB8: ;
  p00_L_24ED();
  return;
  lab_p24_L_6FD4: ;
  p24_L_74C2();
  lab_p24_L_6FD7: ;
  cpu_pop_de();
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_6FE4;
  flag_cmp(a, 0x11);
  if (flag_nz()) { p00_L_24D5(); return; }
  p24_L_5BE1();
  lab_p24_L_6FE4: ;
  p24_L_74C2();
  b = a;
  a = 0x03;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_2D69();
  a = b;
  if (flag_nz()) return;
  set_hl(0x4E2A);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  a = mem_read8(0x9661);
  p24_L_7001();
  return;
}

/* flash page 24 cpu 0x69DA (offset 0x29DA) */
void p24_L_69DA(void) {
  mem_write8((uint16_t)(iy + 0x06), (uint8_t)(mem_read8((uint16_t)(iy + 0x06)) | (1u << 0)));
  set_hl(0x0001);
  mem_write16(0x9661, hl());
  return;
}

/* flash page 24 cpu 0x6A0B (offset 0x2A0B) */
void p24_L_6A0B(void) {
  set_hl(mem_read16(0x9824));
  set_de(0xFFF7);
  lab_p24_L_6A11: ;
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_6A21;
  flag_cmp(a, 0x0C);
  if (flag_nz()) { p00_L_24DD(); return; }
  mem_write8((uint16_t)(iy + 0x06), (uint8_t)(mem_read8((uint16_t)(iy + 0x06)) | (1u << 1)));
  set_hl((uint16_t)(hl() + de()));
  lab_p24_L_6A21: ;
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_6A11;
  return;
}

/* flash page 24 cpu 0x6B1A (offset 0x2B1A) */
void p24_L_6B1A(void) {
  cpu_push_de();
  p24_L_7498();
  cpu_pop_bc();
  a = 0x02;
  goto lab_p24_L_6B25;
  lab_p24_L_6B25: ;
  mem_write8(0x8485, a);
  p24_L_7498();
  p24_L_6B2B();
  return;
}

/* flash page 24 cpu 0x6B23 (offset 0x2B23) */
void p24_L_6B23(void) {
  a = 0x01;
  mem_write8(0x8485, a);
  p24_L_7498();
  p24_L_6B2B();
  return;
}

/* flash page 24 cpu 0x6B2B (offset 0x2B2B) */
void p24_L_6B2B(void) {
  p00_L_10DD();
  a = 0xFF;
  mem_write8(0x8478, a);
  a = mem_read8(0x8479);
  flag_cmp(a, 0x63);
  if (flag_z()) goto lab_p24_L_6B3F;
  p00_L_241E();
  goto lab_p24_L_6B42;
  lab_p24_L_6B3F: ;
  p24_L_7516();
  lab_p24_L_6B42: ;
  mem_write8(0x8499, a);
  a = mem_read8(hl());
  cpu_push_af();
  mem_write16(0x981C, hl());
  mem_write16(0x84DD, de());
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5C);
  if (flag_c()) goto lab_p24_L_6B60;
  if (flag_z()) goto lab_p24_L_6C37;
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p24_L_6B92;
  flag_cmp(a, 0x63);
  if (flag_z()) goto lab_p24_L_6B92;
  lab_p24_L_6B60: ;
  p00_L_24DD();
  return;
  lab_p24_L_6B63: ;
  p24_L_6CBB();
  set_hl(0x0001);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nz()) goto lab_p24_L_6BB1;
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p24_L_6B76;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p24_L_6B60;
  lab_p24_L_6B76: ;
  cpu_push_af();
  p24_L_7498();
  set_hl(0x0001);
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  if (flag_z()) p00_L_1C46();
  cpu_pop_af();
  if (flag_nz()) p00_L_1C75();
  mem_write16(0x84DD, de());
  a = 0;
  flag_logic(a);
  cpu_push_af();
  p24_L_6CC3();
  goto lab_p24_L_6B99;
  lab_p24_L_6B92: ;
  cpu_pop_af();
  if (flag_c()) goto lab_p24_L_6B63;
  cpu_push_af();
  p24_L_6CBB();
  lab_p24_L_6B99: ;
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p24_L_6BAB;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p24_L_6B60;
  cpu_push_af();
  a = mem_read8(0x849A);
  flag_cmp(a, 0x63);
  if (flag_z()) { p00_L_24DD(); return; }
  cpu_pop_af();
  lab_p24_L_6BAB: ;
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nc()) goto lab_p24_L_6BB4;
  lab_p24_L_6BB1: ;
  p00_L_24ED();
  return;
  lab_p24_L_6BB4: ;
  cpu_push_bc();
  cpu_push_af();
  a = a & 0x08;
  flag_logic(a);
  b = a;
  a = mem_read8(0x8499);
  a = a & 0x08;
  flag_logic(a);
  flag_cmp(a, b);
  if (flag_z()) goto lab_p24_L_6BDE;
  flag_set_z((a & (1u << 3)) == 0);
  if (flag_z()) goto lab_p24_L_6BCD;
  p00_L_22FC();
  p00_L_104B();
  goto lab_p24_L_6BE4;
  lab_p24_L_6BCD: ;
  p00_L_21D6();
  set_de(mem_read16(0x84DD));
  p00_L_390F();
  mem_write16(0x84DD, de());
  p00_L_218C();
  lab_p24_L_6BDE: ;
  p00_L_2176();
  p00_L_2222();
  lab_p24_L_6BE4: ;
  set_de(mem_read16(0x84DD));
  cpu_pop_af();
  if (flag_nz()) goto lab_p24_L_6C20;
  set_de(mem_read16(0x84DD));
  a = mem_read8(0x849A);
  flag_cmp(a, 0x63);
  if (flag_nz()) goto lab_p24_L_6C07;
  mem_write16(0x84E1, de());
  cpu_pop_hl();
  cpu_push_hl();
  a = l;
  flag_cmp(a, 0x08);
  if (flag_nc()) goto lab_p24_L_6BB1;
  mem_write8(de(), a);
  p00_L_2176();
  goto lab_p24_L_6C19;
  lab_p24_L_6C07: ;
  p00_L_2222();
  set_de(mem_read16(0x84DD));
  a = mem_read8(0x8499);
  p00_L_38EB();
  p00_L_2176();
  goto lab_p24_L_6C1C;
  lab_p24_L_6C19: ;
  p00_L_2222();
  lab_p24_L_6C1C: ;
  set_de(mem_read16(0x84E1));
  lab_p24_L_6C20: ;
  cpu_pop_hl();
  p00_L_3B19();
  p00_L_1135();
  p00_L_17E9();
  p24_L_74F1();
  lab_p24_L_6C2D: ;
  p00_L_2176();
  cpu_pop_af();
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_z()) return;
  p00_L_0087();
  return;
  lab_p24_L_6C37: ;
  cpu_pop_af();
  if (flag_c()) { p00_L_24F1(); return; }
  cpu_push_af();
  a = mem_read8(0x8485);
  flag_cmp(a, 0x02);
  if (flag_nz()) { p00_L_24E5(); return; }
  p24_L_6CC3();
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p24_L_6B60;
  cpu_push_hl();
  cpu_push_bc();
  p24_L_74A8();
  cpu_pop_hl();
  b = l;
  cpu_push_bc();
  cpu_pop_hl();
  /* ex (sp),hl */
  a = l;
  flag_cmp(a, c);
  if (flag_c()) goto lab_p24_L_6C5C;
  a = h;
  flag_cmp(a, b);
  lab_p24_L_6C5C: ;
  if (flag_c()) { p00_L_24ED(); return; }
  p00_L_2176();
  p00_L_2222();
  cpu_pop_bc();
  set_de(mem_read16(0x84DD));
  p24_L_6D4B();
  goto lab_p24_L_6C2D;
}

/* flash page 24 cpu 0x6CA6 (offset 0x2CA6) */
void p24_L_6CA6(void) {
  p24_L_6CC3();
  cpu_push_hl();
  cpu_push_bc();
  p24_L_74A8();
  cpu_pop_hl();
  b = l;
  cpu_pop_hl();
  a = l;
  flag_cmp(a, c);
  if (flag_c()) goto lab_p24_L_6CB8;
  cpu_sbc_hl_bc();
  if (flag_nc()) return;
  lab_p24_L_6CB8: ;
  p00_L_24ED();
  return;
}

/* flash page 24 cpu 0x6CBB (offset 0x2CBB) */
void p24_L_6CBB(void) {
  a = mem_read8(0x8485);
  flag_cmp(a, 0x01);
  if (flag_nz()) { p00_L_24E5(); return; }
  p24_L_6CC3();
  return;
}

/* flash page 24 cpu 0x6CC3 (offset 0x2CC3) */
void p24_L_6CC3(void) {
  p24_L_74A8();
  h = b;
  l = c;
  p00_L_1836();
  p00_L_23CC();
  a = mem_read8(hl());
  a = a & 0x0F;
  flag_logic(a);
  set_hl(mem_read16(0x84DD));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  cpu_ex_de_hl();
  set_de((uint16_t)(de() - 1));
  return;
}

/* flash page 24 cpu 0x6CDA (offset 0x2CDA) */
void p24_L_6CDA(void) {
  mem_write8((uint16_t)(iy + 0x06), (uint8_t)(mem_read8((uint16_t)(iy + 0x06)) & ~(1u << 1)));
  set_hl(mem_read16(0x9663));
  cpu_push_de();
  p00_L_1647();
  cpu_pop_de();
  cpu_push_hl();
  set_bc(mem_read16(0x9663));
  p00_L_3B67();
  cpu_pop_bc();
  lab_p24_L_6CEF: ;
  cpu_push_bc();
  cpu_push_hl();
  p00_L_21A7();
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_6D13;
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p24_L_6D26;
  p00_rst20();
  cpu_pop_de();
  set_hl(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  cpu_push_de();
  p00_L_104B();
  cpu_pop_de();
  p00_L_1063();
  set_hl(0xFFE5);
  goto lab_p24_L_6D2D;
  lab_p24_L_6D13: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 1)) == 0);
  if (flag_z()) { p00_L_24DD(); return; }
  cpu_pop_de();
  p00_L_1183();
  set_hl(0xFFEE);
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  p00_L_21A7();
  lab_p24_L_6D26: ;
  cpu_pop_de();
  p00_L_1183();
  set_hl(0xFFEE);
  lab_p24_L_6D2D: ;
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_6CEF;
  return;
}

/* flash page 24 cpu 0x6D35 (offset 0x2D35) */
void p24_L_6D35(void) {
  goto lab_p24_L_6D35;
  lab_p24_L_6CEF: ;
  cpu_push_bc();
  cpu_push_hl();
  p00_L_21A7();
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_6D13;
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p24_L_6D26;
  p00_rst20();
  cpu_pop_de();
  set_hl(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  cpu_push_de();
  p00_L_104B();
  cpu_pop_de();
  p00_L_1063();
  set_hl(0xFFE5);
  goto lab_p24_L_6D2D;
  lab_p24_L_6D13: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 1)) == 0);
  if (flag_z()) { p00_L_24DD(); return; }
  cpu_pop_de();
  p00_L_1183();
  set_hl(0xFFEE);
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  p00_L_21A7();
  lab_p24_L_6D26: ;
  cpu_pop_de();
  p00_L_1183();
  set_hl(0xFFEE);
  lab_p24_L_6D2D: ;
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_6CEF;
  return;
  lab_p24_L_6D35: ;
  set_hl(mem_read16(0x9663));
  p00_L_3AE9();
  set_bc(mem_read16(0x9663));
  flag_set_z((mem_read8((uint16_t)(iy + 0x06)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p24_L_6CEF;
  set_de(0x0009);
  set_hl((uint16_t)(hl() + de()));
  goto lab_p24_L_6CEF;
}

/* flash page 24 cpu 0x6D4B (offset 0x2D4B) */
void p24_L_6D4B(void) {
  a = mem_read8(de());
  cpu_push_af();
  cpu_push_de();
  p00_L_3B67();
  /* ex (sp),hl */
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_1037();
  if (flag_z()) goto lab_p24_L_6D93;
  a = mem_read8(hl());
  a = a & 0x01;
  flag_logic(a);
  cpu_push_af();
  p00_rst10();
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a & 0x01;
  flag_logic(a);
  cpu_pop_de();
  cpu_pop_de();
  lab_p24_L_6D68: ;
  cpu_push_bc();
  cpu_push_hl();
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  l = c;
  h = 0x00;
  if (flag_z()) goto lab_p24_L_6D72;
  set_hl((uint16_t)(hl() + hl()));
  lab_p24_L_6D72: ;
  p00_L_1025();
  b = h;
  c = l;
  cpu_pop_hl();
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_bc();
  cpu_pop_af();
  b = (uint8_t)(b - 1);
  if (flag_z()) return;
  cpu_push_af();
  cpu_push_bc();
  cpu_push_hl();
  a = (uint8_t)(a - c);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  l = a;
  h = 0x00;
  if (flag_z()) goto lab_p24_L_6D8A;
  set_hl((uint16_t)(hl() + hl()));
  lab_p24_L_6D8A: ;
  p00_L_1025();
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  cpu_pop_hl();
  cpu_pop_bc();
  goto lab_p24_L_6D68;
  lab_p24_L_6D93: ;
  cpu_pop_de();
  cpu_pop_af();
  p00_L_11FD();
  return;
}

/* flash page 24 cpu 0x6D98 (offset 0x2D98) */
void p24_L_6D98(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x08)) & (1u << 1)) == 0);
  if (flag_z()) { p00_L_24FD(); return; }
  return;
}

/* flash page 24 cpu 0x6E9E (offset 0x2E9E) */
void p24_L_6E9E(void) {
  p24_L_684A();
  return;
}

/* flash page 24 cpu 0x6ECE (offset 0x2ECE) */
void p24_L_6ECE(void) {
  goto lab_p24_L_6ECE;
  lab_p24_L_6E6E: ;
  b = a;
  a = c;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p24_L_6E7F;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p24_L_6E84;
  set_hl(0x4000);
  c = 0x01;
  goto lab_p24_L_6E87;
  lab_p24_L_6E7F: ;
  set_hl(0x46BA);
  goto lab_p24_L_6E87;
  lab_p24_L_6E84: ;
  set_hl(0x6EE2);
  lab_p24_L_6E87: ;
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_2D69();
  if (flag_nz()) { p24_L_6E9E(); return; }
  a = b;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  p24_L_7001();
  p24_L_6E9E();
  return;
  lab_p24_L_6ECE: ;
  cpu_push_af();
  p24_L_7093();
  if (flag_nz()) { p00_L_24D5(); return; }
  cpu_pop_af();
  p24_L_689B();
  /* ei */
  flag_cmp(a, 0xF2);
  if (flag_c()) goto lab_p24_L_6EE0;
  a = (uint8_t)(a + 0x12);
  lab_p24_L_6EE0: ;
  c = 0x03;
  goto lab_p24_L_6E6E;
}

/* flash page 24 cpu 0x6F3E (offset 0x2F3E) */
void p24_L_6F3E(void) {
  p24_L_7002();
  p24_L_6F41();
  return;
}

/* flash page 24 cpu 0x6F41 (offset 0x2F41) */
void p24_L_6F41(void) {
  p24_L_7096();
  if (flag_nz()) return;
  p00_L_24E5();
  return;
}

/* flash page 24 cpu 0x6F48 (offset 0x2F48) */
void p24_L_6F48(void) {
  p24_L_7005();
  p24_L_6F4B();
  return;
}

/* flash page 24 cpu 0x6F4B (offset 0x2F4B) */
void p24_L_6F4B(void) {
  goto lab_p24_L_6F4B;
  lab_p24_L_6F45: ;
  p00_L_24E5();
  return;
  lab_p24_L_6F4B: ;
  flag_cmp(a, 0x2B);
  if (flag_z()) return;
  p24_L_7096();
  if (flag_z()) goto lab_p24_L_6F45;
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x6F56 (offset 0x2F56) */
void p24_L_6F56(void) {
  p24_L_7265();
  a = a | a;
  flag_logic(a);
  p24_L_6F5F();
  return;
}

/* flash page 24 cpu 0x6F5C (offset 0x2F5C) */
void p24_L_6F5C(void) {
  p24_L_7265();
  p24_L_6F5F();
  return;
}

/* flash page 24 cpu 0x6F5F (offset 0x2F5F) */
void p24_L_6F5F(void) {
  set_bc((uint16_t)(bc() - 1));
  mem_write16(0x965D, bc());
  p24_L_6F64();
  return;
}

/* flash page 24 cpu 0x6F64 (offset 0x2F64) */
void p24_L_6F64(void) {
  goto lab_p24_L_6F64;
  lab_p24_L_6F45: ;
  p00_L_24E5();
  return;
  lab_p24_L_6F51: ;
  if (flag_z()) goto lab_p24_L_6F45;
  lab_p24_L_6F53: ;
  p00_L_24D5();
  return;
  lab_p24_L_6F64: ;
  if (flag_nc()) goto lab_p24_L_6F69;
  a = a | a;
  flag_logic(a);
  goto lab_p24_L_6F51;
  lab_p24_L_6F69: ;
  cpu_ex_de_hl();
  h = b;
  l = c;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p24_L_6F53;
  p24_L_6F71();
  return;
}

/* flash page 24 cpu 0x6F71 (offset 0x2F71) */
void p24_L_6F71(void) {
  cpu_push_hl();
  set_hl(0x9652);
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  p00_L_1857();
  if (flag_z()) goto lab_p24_L_6F83;
  set_hl((uint16_t)(hl() + 1));
  p00_L_19C2();
  goto lab_p24_L_6F85;
  lab_p24_L_6F83: ;
  a = 0x03;
  lab_p24_L_6F85: ;
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_af();
  a = (uint8_t)(a + 0x04);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  p00_L_1CA2();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_hl(0x9652);
  a = mem_read8(hl());
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  cpu_pop_af();
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  c = a;
  b = 0x00;
  set_hl((uint16_t)(hl() + 1));
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_bc();
  set_hl(mem_read16(0x965D));
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_push_de();
  set_de(mem_read16(0x965B));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_ex_de_hl();
  cpu_pop_hl();
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  cpu_pop_hl();
  while (bc() != 0) { cpu_ldi(); }
  p00_L_1135();
  return;
}

/* flash page 24 cpu 0x6FC0 (offset 0x2FC0) */
void p24_L_6FC0(void) {
  set_hl(mem_read16(0x965D));
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p24_L_4137();
  h = b;
  l = c;
  set_bc((uint16_t)(bc() - 1));
  mem_write16(0x965D, bc());
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  return;
}

/* flash page 24 cpu 0x7001 (offset 0x3001) */
void p24_L_7001(void) {
  os_jp_hl();
  return;
}

/* flash page 24 cpu 0x7002 (offset 0x3002) */
void p24_L_7002(void) {
  p00_L_171E();
  p24_L_7005();
  return;
}

/* flash page 24 cpu 0x7005 (offset 0x3005) */
void p24_L_7005(void) {
  set_hl(mem_read16(0x965D));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x965D, hl());
  p24_L_700C();
  return;
}

/* flash page 24 cpu 0x700C (offset 0x300C) */
void p24_L_700C(void) {
  set_bc(mem_read16(0x965D));
  set_hl(mem_read16(0x965F));
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) return;
  a = mem_read8(bc());
  return;
}

/* flash page 24 cpu 0x7019 (offset 0x3019) */
void p24_L_7019(void) {
  goto lab_p24_L_7019;
  lab_p24_L_7010: ;
  set_hl(mem_read16(0x965F));
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) return;
  a = mem_read8(bc());
  return;
  lab_p24_L_7019: ;
  set_bc(mem_read16(0x965D));
  set_bc((uint16_t)(bc() + 1));
  goto lab_p24_L_7010;
}

/* flash page 24 cpu 0x7020 (offset 0x3020) */
void p24_L_7020(void) {
  set_hl(mem_read16(0x9828));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  return;
}

/* flash page 24 cpu 0x7026 (offset 0x3026) */
void p24_L_7026(void) {
  goto lab_p24_L_7026;
  lab_p24_L_7023: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  return;
  lab_p24_L_7026: ;
  set_hl(mem_read16(0x9828));
  set_hl((uint16_t)(hl() + 1));
  goto lab_p24_L_7023;
}

/* flash page 24 cpu 0x702C (offset 0x302C) */
void p24_L_702C(void) {
  p24_L_703E();
  if (flag_nz()) goto lab_p24_L_703B;
  p00_L_018E();
  if (flag_nz()) goto lab_p24_L_703B;
  p24_L_7020();
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  lab_p24_L_703B: ;
  p00_L_24D5();
  return;
}

/* flash page 24 cpu 0x703E (offset 0x303E) */
void p24_L_703E(void) {
  a = mem_read8(0x9652);
  a = a & 0x0F;
  flag_logic(a);
  p00_L_17BE();
  return;
}

/* flash page 24 cpu 0x7046 (offset 0x3046) */
void p24_L_7046(void) {
  p24_L_7005();
  p24_L_7049();
  return;
}

/* flash page 24 cpu 0x7049 (offset 0x3049) */
void p24_L_7049(void) {
  goto lab_p24_L_7049;
  lab_p24_L_703B: ;
  p00_L_24D5();
  return;
  lab_p24_L_7049: ;
  p24_L_6F41();
  flag_cmp(a, 0x5F);
  if (flag_z()) goto lab_p24_L_703B;
  flag_cmp(a, 0xEB);
  if (flag_nz()) goto lab_p24_L_7059;
  p24_L_5DF2();
  p24_L_7093();
  return;
  lab_p24_L_7059: ;
  flag_cmp(a, 0xAA);
  if (flag_z()) { p24_L_7071(); return; }
  flag_cmp(a, 0x62);
  if (flag_c()) goto lab_p24_L_706D;
  if (flag_nz()) goto lab_p24_L_703B;
  cpu_push_af();
  p24_L_7093();
  flag_cmp(a, 0x21);
  if (flag_z()) goto lab_p24_L_7072;
  goto lab_p24_L_703B;
  lab_p24_L_706D: ;
  flag_cmp(a, 0x41);
  if (flag_c()) goto lab_p24_L_703B;
  p24_L_7071();
  return;
  lab_p24_L_7072: ;
  p00_L_1295();
  cpu_pop_af();
  mem_write8(0x8479, a);
  flag_cmp(a, 0x72);
  if (flag_z()) { p24_L_7093(); return; }
  flag_cmp(a, 0x41);
  if (flag_c()) goto lab_p24_L_703B;
  flag_cmp(a, 0x5C);
  if (flag_c()) { p24_L_7093(); return; }
  flag_cmp(a, 0xAA);
  if (flag_z()) goto lab_p24_L_708D;
  flag_cmp(a, 0x64);
  if (flag_nc()) goto lab_p24_L_703B;
  lab_p24_L_708D: ;
  p24_L_7005();
  mem_write8(0x847A, a);
  p24_L_7093();
  return;
}

/* flash page 24 cpu 0x7071 (offset 0x3071) */
void p24_L_7071(void) {
  goto lab_p24_L_7071;
  lab_p24_L_703B: ;
  p00_L_24D5();
  return;
  lab_p24_L_7071: ;
  cpu_push_af();
  p00_L_1295();
  cpu_pop_af();
  mem_write8(0x8479, a);
  flag_cmp(a, 0x72);
  if (flag_z()) { p24_L_7093(); return; }
  flag_cmp(a, 0x41);
  if (flag_c()) goto lab_p24_L_703B;
  flag_cmp(a, 0x5C);
  if (flag_c()) { p24_L_7093(); return; }
  flag_cmp(a, 0xAA);
  if (flag_z()) goto lab_p24_L_708D;
  flag_cmp(a, 0x64);
  if (flag_nc()) goto lab_p24_L_703B;
  lab_p24_L_708D: ;
  p24_L_7005();
  mem_write8(0x847A, a);
  p24_L_7093();
  return;
}

/* flash page 24 cpu 0x7093 (offset 0x3093) */
void p24_L_7093(void) {
  p24_L_7019();
  p24_L_7096();
  return;
}

/* flash page 24 cpu 0x7096 (offset 0x3096) */
void p24_L_7096(void) {
  flag_cmp(a, 0x3E);
  if (flag_z()) return;
  p24_L_7099();
  return;
}

/* flash page 24 cpu 0x7099 (offset 0x3099) */
void p24_L_7099(void) {
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  flag_cmp(a, 0x3F);
  return;
}

/* flash page 24 cpu 0x709E (offset 0x309E) */
void p24_L_709E(void) {
  set_hl(0x5A67);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_z()) return;
  set_hl(0x5A5F);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  return;
}

/* flash page 24 cpu 0x70AC (offset 0x30AC) */
void p24_L_70AC(void) {
  p00_L_241E();
  if (flag_c()) return;
  p24_L_660B();
  a = 0;
  flag_logic(a);
  mem_write8(0x8478, a);
  return;
}

/* flash page 24 cpu 0x70B8 (offset 0x30B8) */
void p24_L_70B8(void) {
  flag_cmp(a, 0xB5);
  if (flag_z()) return;
  flag_cmp(a, 0xAB);
  if (flag_z()) return;
  flag_cmp(a, 0xEB);
  if (flag_z()) return;
  flag_cmp(a, 0x41);
  if (flag_c()) goto lab_p24_L_70D6;
  flag_cmp(a, 0x62);
  if (flag_nz()) goto lab_p24_L_70D0;
  set_bc((uint16_t)(bc() + 1));
  a = mem_read8(bc());
  flag_cmp(a, 0x21);
  p24_L_70CD();
  return;
  lab_p24_L_70D0: ;
  flag_cmp(a, 0xAA);
  if (flag_z()) return;
  flag_cmp(a, 0x64);
  if (flag_c()) return;
  lab_p24_L_70D6: ;
  p24_L_5BE5();
  return;
}

/* flash page 24 cpu 0x70CD (offset 0x30CD) */
void p24_L_70CD(void) {
  if (flag_z()) return;
  goto lab_p24_L_70D6;
  lab_p24_L_70D6: ;
  p24_L_5BE5();
  return;
}

/* flash page 24 cpu 0x70D9 (offset 0x30D9) */
void p24_L_70D9(void) {
  p24_L_7020();
  flag_cmp(a, 0x04);
  a = 0xB5;
  if (flag_nz()) return;
  cpu_pop_hl();
  p24_L_74C2();
  p24_L_7002();
  p24_L_7049();
  if (flag_z()) goto lab_p24_L_70FD;
  mem_write16(0x965D, bc());
  flag_cmp(a, 0x11);
  if (flag_nz()) goto lab_p24_L_70FA;
  p24_L_7093();
  if (flag_z()) goto lab_p24_L_70FD;
  lab_p24_L_70FA: ;
  p00_L_24D5();
  return;
  lab_p24_L_70FD: ;
  p00_L_241E();
  cpu_push_af();
  mem_write16(0x84DD, de());
  mem_write16(0x981C, hl());
  p00_L_10DD();
  p00_L_22FC();
  p00_L_1037();
  if (flag_z()) goto lab_p24_L_7188;
  flag_cmp(a, 0x01);
  lab_p24_L_7115: ;
  if (flag_nz()) { p00_L_24DD(); return; }
  a = mem_read8(0x849A);
  flag_cmp(a, 0x5C);
  if (flag_nz()) goto lab_p24_L_7115;
  p00_L_2429();
  cpu_ex_de_hl();
  mem_write16(0x84DF, hl());
  a = mem_read8(hl());
  flag_cmp(a, 0x02);
  if (flag_nz()) { p00_L_24ED(); return; }
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_rst20();
  cpu_push_hl();
  p24_L_71E4();
  cpu_pop_hl();
  cpu_push_de();
  p00_rst20();
  p24_L_71E4();
  cpu_pop_hl();
  d = l;
  cpu_pop_af();
  if (flag_nc()) goto lab_p24_L_715F;
  cpu_push_de();
  p00_L_1135();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_1647();
  /* ex (sp),hl */
  p00_L_1C81();
  p24_L_714B();
  return;
  lab_p24_L_715F: ;
  set_hl(mem_read16(0x84DD));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  h = mem_read8(hl());
  l = a;
  p00_L_192A();
  if (flag_z()) goto lab_p24_L_7182;
  cpu_push_de();
  p00_L_1135();
  cpu_pop_hl();
  p00_L_3AE3();
  lab_p24_L_7174: ;
  set_hl(mem_read16(0x981C));
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_0087();
  p00_L_1135();
  p00_L_17E9();
  lab_p24_L_7182: ;
  p00_L_219B();
  p24_L_5BAF();
  return;
  lab_p24_L_7188: ;
  a = mem_read8(0x849A);
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p24_L_7115;
  p00_L_0FB5();
  p00_L_14DB();
  if (flag_nz()) { p00_L_24ED(); return; }
  set_hl(0x03E7);
  p24_L_71E1();
  cpu_pop_af();
  cpu_push_de();
  cpu_push_af();
  p00_L_1135();
  cpu_pop_af();
  if (flag_c()) goto lab_p24_L_71C6;
  set_hl(mem_read16(0x84DD));
  p00_L_0033();
  cpu_pop_de();
  p00_L_192A();
  if (flag_z()) goto lab_p24_L_7182;
  if (flag_c()) goto lab_p24_L_71CE;
  b = d;
  c = e;
  set_bc((uint16_t)(bc() + 1));
  cpu_sbc_hl_de();
  set_de(mem_read16(0x84DD));
  a = mem_read8(0x8478);
  p00_L_31D7();
  goto lab_p24_L_7174;
  lab_p24_L_71C6: ;
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_1C46();
  p24_L_714B();
  return;
  lab_p24_L_71CE: ;
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  c = e;
  b = d;
  set_de(mem_read16(0x84DD));
  a = mem_read8(0x8478);
  a = a | a;
  flag_logic(a);
  p00_L_31DD();
  goto lab_p24_L_7174;
}

/* flash page 24 cpu 0x714B (offset 0x314B) */
void p24_L_714B(void) {
  mem_write16(0x84DD, de());
  mem_write16(0x981C, hl());
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_128A();
  cpu_pop_hl();
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) p24_L_748D();
  goto lab_p24_L_7174;
  lab_p24_L_7174: ;
  set_hl(mem_read16(0x981C));
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_0087();
  p00_L_1135();
  p00_L_17E9();
  p00_L_219B();
  p24_L_5BAF();
  return;
}

/* flash page 24 cpu 0x71CD (offset 0x31CD) */
void p24_L_71CD(void) {
  goto lab_p24_L_71CD;
  lab_p24_L_7174: ;
  set_hl(mem_read16(0x981C));
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_0087();
  p00_L_1135();
  p00_L_17E9();
  p00_L_219B();
  p24_L_5BAF();
  return;
  lab_p24_L_71CD: ;
  mem_write8(hl(), c);
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  c = e;
  b = d;
  set_de(mem_read16(0x84DD));
  a = mem_read8(0x8478);
  a = a | a;
  flag_logic(a);
  p00_L_31DD();
  goto lab_p24_L_7174;
}

/* flash page 24 cpu 0x71E1 (offset 0x31E1) */
void p24_L_71E1(void) {
  cpu_push_hl();
  goto lab_p24_L_71ED;
  lab_p24_L_71ED: ;
  p24_L_71F8();
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) return;
  p00_L_24ED();
  return;
}

/* flash page 24 cpu 0x71E4 (offset 0x31E4) */
void p24_L_71E4(void) {
  set_hl(0x0063);
  p24_L_71E7();
  return;
}

/* flash page 24 cpu 0x71E7 (offset 0x31E7) */
void p24_L_71E7(void) {
  cpu_push_hl();
  p00_L_14D1();
  if (flag_nz()) goto lab_p24_L_71F5;
  p24_L_71F8();
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) return;
  lab_p24_L_71F5: ;
  p00_L_24ED();
  return;
}

/* flash page 24 cpu 0x71F8 (offset 0x31F8) */
void p24_L_71F8(void) {
  goto lab_p24_L_71F8;
  lab_p24_L_71F5: ;
  p00_L_24ED();
  return;
  lab_p24_L_71F8: ;
  a = mem_read8(0x847A);
  a = a | a;
  flag_logic(a);
  if (flag_z()) p00_L_128A();
  set_hl(0x8479);
  a = 0x83;
  /* sub (hl) */
  if (flag_c()) goto lab_p24_L_71F5;
  b = a;
  set_hl(0x847B);
  if (flag_z()) { p24_L_7216(); return; }
  lab_p24_L_720D: ;
  a = 0;
  flag_logic(a);
  set_hl((uint16_t)(hl() - 1));
  /* rrd */
  set_hl((uint16_t)(hl() + 1));
  /* rrd */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p24_L_720D;
  p24_L_7216();
  return;
}

/* flash page 24 cpu 0x7216 (offset 0x3216) */
void p24_L_7216(void) {
  cpu_ex_de_hl();
  a = mem_read8(de());
  a = a & 0x0F;
  flag_logic(a);
  l = a;
  h = 0x00;
  c = 0x0A;
  b = h;
  p24_L_7238();
  set_de((uint16_t)(de() - 1));
  a = mem_read8(de());
  c = 0x64;
  a = a & 0x0F;
  flag_logic(a);
  p24_L_723C();
  set_bc(0x03E8);
  p24_L_7238();
  cpu_ex_de_hl();
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), e);
  a = e;
  return;
}

/* flash page 24 cpu 0x7238 (offset 0x3238) */
void p24_L_7238(void) {
  a = mem_read8(de());
  p00_L_12B1();
  p24_L_723C();
  return;
}

/* flash page 24 cpu 0x723C (offset 0x323C) */
void p24_L_723C(void) {
  lab_p24_L_723C: ;
  a = (uint8_t)(a - 1);
  if (flag_m()) return;
  set_hl((uint16_t)(hl() + bc()));
  goto lab_p24_L_723C;
}

/* flash page 24 cpu 0x725D (offset 0x325D) */
void p24_L_725D(void) {
  b = 0xFF;
  goto lab_p24_L_7267;
  lab_p24_L_7267: ;
  set_hl(mem_read16(0x965D));
  cpu_push_hl();
  set_de(0x0000);
  cpu_push_bc();
  p24_L_726F();
  return;
}

/* flash page 24 cpu 0x7261 (offset 0x3261) */
void p24_L_7261(void) {
  b = 0x01;
  goto lab_p24_L_7267;
  lab_p24_L_7267: ;
  set_hl(mem_read16(0x965D));
  cpu_push_hl();
  set_de(0x0000);
  cpu_push_bc();
  p24_L_726F();
  return;
}

/* flash page 24 cpu 0x7265 (offset 0x3265) */
void p24_L_7265(void) {
  b = 0x00;
  set_hl(mem_read16(0x965D));
  cpu_push_hl();
  set_de(0x0000);
  cpu_push_bc();
  p24_L_726F();
  return;
}

/* flash page 24 cpu 0x726F (offset 0x326F) */
void p24_L_726F(void) {
  lab_p24_L_726F: ;
  p24_L_7019();
  flag_cmp(a, 0x3E);
  if (flag_nz()) goto lab_p24_L_7282;
  cpu_pop_hl();
  cpu_push_hl();
  /* rl h */
  if (flag_c()) { p24_L_735A(); return; }
  if (flag_z()) goto lab_p24_L_735B;
  goto lab_p24_L_72A9;
  lab_p24_L_7282: ;
  p24_L_7099();
  if (flag_z()) { p24_L_735A(); return; }
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p24_L_735C;
  flag_cmp(a, 0x2A);
  if (flag_nz()) goto lab_p24_L_72A9;
  cpu_pop_hl();
  cpu_push_hl();
  /* rl h */
  if (flag_c()) goto lab_p24_L_729A;
  if (flag_nz()) goto lab_p24_L_735B;
  lab_p24_L_729A: ;
  mem_write16(0x965D, bc());
  p24_L_5379();
  p24_L_7096();
  if (flag_nz()) goto lab_p24_L_726F;
  p24_L_735A();
  return;
  lab_p24_L_72A9: ;
  mem_write16(0x965D, bc());
  flag_cmp(a, 0xBB);
  if (flag_nz()) goto lab_p24_L_72DE;
  p24_L_7005();
  flag_cmp(a, 0x20);
  if (flag_c()) goto lab_p24_L_7302;
  flag_cmp(a, 0x25);
  if (flag_c()) goto lab_p24_L_726F;
  flag_cmp(a, 0x2F);
  if (flag_c()) goto lab_p24_L_7302;
  flag_cmp(a, 0x35);
  if (flag_c()) goto lab_p24_L_726F;
  flag_cmp(a, 0x3C);
  if (flag_c()) goto lab_p24_L_7302;
  flag_cmp(a, 0x42);
  if (flag_c()) goto lab_p24_L_72D0;
  flag_cmp(a, 0x48);
  if (flag_c()) goto lab_p24_L_7302;
  lab_p24_L_72D0: ;
  set_hl(0x7253);
  cpu_push_bc();
  set_bc(0x000A);
  /* cpir */
  cpu_pop_bc();
  if (flag_nz()) goto lab_p24_L_726F;
  goto lab_p24_L_7302;
  lab_p24_L_72DE: ;
  flag_cmp(a, 0xB1);
  if (flag_c()) goto lab_p24_L_72E6;
  flag_cmp(a, 0xCE);
  if (flag_c()) goto lab_p24_L_7302;
  lab_p24_L_72E6: ;
  flag_cmp(a, 0x12);
  if (flag_c()) goto lab_p24_L_72F6;
  flag_cmp(a, 0x29);
  if (flag_c()) goto lab_p24_L_7302;
  flag_cmp(a, 0x9E);
  if (flag_c()) goto lab_p24_L_72F6;
  flag_cmp(a, 0xA6);
  if (flag_c()) goto lab_p24_L_7302;
  lab_p24_L_72F6: ;
  set_hl(0x7241);
  cpu_push_bc();
  set_bc(0x0012);
  /* cpir */
  cpu_pop_bc();
  if (flag_nz()) goto lab_p24_L_730A;
  lab_p24_L_7302: ;
  a = e;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_7307;
  d = (uint8_t)(d + 1);
  lab_p24_L_7307: ;
  goto lab_p24_L_726F;
  lab_p24_L_730A: ;
  p00_L_1730();
  if (flag_nz()) goto lab_p24_L_7316;
  set_bc((uint16_t)(bc() + 1));
  mem_write16(0x965D, bc());
  goto lab_p24_L_7307;
  lab_p24_L_7316: ;
  cpu_pop_hl();
  cpu_push_hl();
  a = a | a;
  flag_logic(a);
  /* rl h */
  if (flag_c()) goto lab_p24_L_731F;
  if (flag_nz()) goto lab_p24_L_7307;
  lab_p24_L_731F: ;
  flag_cmp(a, 0x11);
  if (flag_nz()) goto lab_p24_L_732B;
  a = e;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_7307;
  d = (uint8_t)(d - 1);
  if (flag_m()) goto lab_p24_L_735C;
  lab_p24_L_732B: ;
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p24_L_7333;
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p24_L_7336;
  lab_p24_L_7333: ;
  e = (uint8_t)(e + 1);
  goto lab_p24_L_7343;
  lab_p24_L_7336: ;
  flag_cmp(a, 0x07);
  if (flag_z()) goto lab_p24_L_733E;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p24_L_7346;
  lab_p24_L_733E: ;
  a = e;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_7343;
  e = (uint8_t)(e - 1);
  lab_p24_L_7343: ;
  goto lab_p24_L_726F;
  lab_p24_L_7346: ;
  cpu_pop_hl();
  cpu_push_hl();
  /* rl h */
  if (flag_c()) goto lab_p24_L_7343;
  flag_cmp(a, 0x2B);
  if (flag_nz()) goto lab_p24_L_7343;
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_7343;
  lab_p24_L_7354: ;
  cpu_pop_hl();
  cpu_pop_hl();
  mem_write16(0x965D, hl());
  return;
  lab_p24_L_735B: ;
  a = a | a;
  flag_logic(a);
  lab_p24_L_735C: ;
  /* scf */
  goto lab_p24_L_7354;
}

/* flash page 24 cpu 0x735A (offset 0x335A) */
void p24_L_735A(void) {
  goto lab_p24_L_735A;
  lab_p24_L_7354: ;
  cpu_pop_hl();
  cpu_pop_hl();
  mem_write16(0x965D, hl());
  return;
  lab_p24_L_735A: ;
  a = 0;
  flag_logic(a);
  a = a | a;
  flag_logic(a);
  /* scf */
  goto lab_p24_L_7354;
}

/* flash page 24 cpu 0x735F (offset 0x335F) */
void p24_L_735F(void) {
  a = mem_read8(0x847A);
  flag_cmp(a, 0x0A);
  if (flag_z()) goto lab_p24_L_736D;
  flag_cmp(a, 0x0B);
  if (flag_z()) goto lab_p24_L_736D;
  flag_cmp(a, 0x1A);
  if (flag_nz()) return;
  lab_p24_L_736D: ;
  p00_L_24FD();
  return;
}

/* flash page 24 cpu 0x7370 (offset 0x3370) */
void p24_L_7370(void) {
  goto lab_p24_L_7370;
  lab_p24_L_736D: ;
  p00_L_24FD();
  return;
  lab_p24_L_7370: ;
  p00_L_172A();
  if (flag_z()) return;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x63);
  if (flag_nz()) goto lab_p24_L_7383;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x2A);
  if (flag_z()) goto lab_p24_L_736D;
  return;
  lab_p24_L_7383: ;
  p00_L_0013();
  if (flag_nz()) { p24_L_7395(); return; }
  flag_cmp(a, 0x58);
  if (flag_z()) goto lab_p24_L_736D;
  p00_L_0198();
  if (flag_z()) { p24_L_7395(); return; }
  flag_cmp(a, 0x52);
  if (flag_z()) goto lab_p24_L_736D;
  p24_L_7395();
  return;
}

/* flash page 24 cpu 0x7395 (offset 0x3395) */
void p24_L_7395(void) {
  goto lab_p24_L_7395;
  lab_p24_L_736D: ;
  p00_L_24FD();
  return;
  lab_p24_L_7395: ;
  flag_cmp(a, 0x59);
  if (flag_nz()) return;
  goto lab_p24_L_736D;
}

/* flash page 24 cpu 0x739A (offset 0x339A) */
void p24_L_739A(void) {
  p00_L_1295();
  a = 0x72;
  mem_write8(0x8479, a);
  return;
}

/* flash page 24 cpu 0x73A3 (offset 0x33A3) */
void p24_L_73A3(void) {
  set_de(0x8478);
  a = mem_read8(hl());
  cpu_push_af();
  cpu_push_hl();
  a = mem_read8(0x847A);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_73B6;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_cp_hl();
  if (flag_z()) goto lab_p24_L_73CA;
  cpu_pop_hl();
  cpu_push_hl();
  lab_p24_L_73B6: ;
  a = mem_read8(hl());
  a = a & 0x9F;
  flag_logic(a);
  b = a;
  a = mem_read8(de());
  a = a & 0x9F;
  flag_logic(a);
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p24_L_73CA;
  b = 0x08;
  lab_p24_L_73C2: ;
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(de());
  cpu_cp_hl();
  if (flag_nz()) goto lab_p24_L_73CA;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p24_L_73C2;
  lab_p24_L_73CA: ;
  cpu_pop_hl();
  cpu_push_af();
  cpu_push_hl();
  cpu_ex_de_hl();
  p00_L_11FD();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_pop_bc();
  return;
}

/* flash page 24 cpu 0x73D5 (offset 0x33D5) */
void p24_L_73D5(void) {
  p24_L_7005();
  flag_cmp(a, 0x30);
  if (flag_c()) return;
  flag_cmp(a, 0x3C);
  /* ccf */
  return;
}

/* flash page 24 cpu 0x73DF (offset 0x33DF) */
void p24_L_73DF(void) {
  flag_cmp(a, 0x41);
  if (flag_c()) return;
  flag_cmp(a, 0x5C);
  /* ccf */
  return;
}

/* flash page 24 cpu 0x748D (offset 0x348D) */
void p24_L_748D(void) {
  lab_p24_L_748D: ;
  cpu_push_hl();
  p00_L_11FD();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_748D;
  return;
}

/* flash page 24 cpu 0x7498 (offset 0x3498) */
void p24_L_7498(void) {
  cpu_push_bc();
  set_hl(0x0002);
  p00_L_23BD();
  cpu_pop_bc();
  set_hl(mem_read16(0x9828));
  mem_write8(hl(), b);
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), c);
  goto lab_p24_L_74BD;
  lab_p24_L_74BD: ;
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x9828, hl());
  return;
}

/* flash page 24 cpu 0x74A8 (offset 0x34A8) */
void p24_L_74A8(void) {
  set_hl(mem_read16(0x9828));
  set_hl((uint16_t)(hl() + 1));
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  goto lab_p24_L_74BE;
  lab_p24_L_74BE: ;
  mem_write16(0x9828, hl());
  return;
}

/* flash page 24 cpu 0x74B1 (offset 0x34B1) */
void p24_L_74B1(void) {
  cpu_push_af();
  set_hl(0x0001);
  p00_L_23BD();
  cpu_pop_af();
  set_hl(mem_read16(0x9828));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x9828, hl());
  return;
}

/* flash page 24 cpu 0x74C2 (offset 0x34C2) */
void p24_L_74C2(void) {
  goto lab_p24_L_74C2;
  lab_p24_L_74BE: ;
  mem_write16(0x9828, hl());
  return;
  lab_p24_L_74C2: ;
  set_hl(mem_read16(0x9828));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  goto lab_p24_L_74BE;
}

/* flash page 24 cpu 0x74C9 (offset 0x34C9) */
void p24_L_74C9(void) {
  flag_cmp(a, 0xAB);
  if (flag_z()) return;
  flag_cmp(a, 0x84);
  if (flag_c()) return;
  flag_cmp(a, 0x93);
  /* ccf */
  if (flag_nc()) return;
  flag_cmp(a, 0xB1);
  if (flag_c()) return;
  flag_cmp(a, 0xF0);
  /* ccf */
  return;
}

/* flash page 24 cpu 0x74DA (offset 0x34DA) */
void p24_L_74DA(void) {
  set_hl(0x9320);
  c = 0x00;
  lab_p24_L_74DF: ;
  a = mem_read8(hl());
  b = 0x08;
  lab_p24_L_74E2: ;
  /* rr a */
  if (flag_nc()) goto lab_p24_L_74EF;
  c = (uint8_t)(c + 1);
  if (flag_z()) { p00_L_24F5(); return; }
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p24_L_74E2;
  set_hl((uint16_t)(hl() + 1));
  goto lab_p24_L_74DF;
  lab_p24_L_74EF: ;
  a = c;
  return;
}

/* flash page 24 cpu 0x74F1 (offset 0x34F1) */
void p24_L_74F1(void) {
  set_hl(mem_read16(0x981C));
  p00_L_1EF4();
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p24_L_7513;
  b = 0x00;
  mem_write8(hl(), b);
  cpu_push_af();
  h = a;
  l = 0x3F;
  p00_L_1671();
  p00_rst10();
  if (flag_nc()) p00_L_1F58();
  cpu_pop_af();
  p00_L_25E7();
  /* xor (hl) */
  mem_write8(hl(), a);
  lab_p24_L_7513: ;
  p00_L_1135();
  return;
}

/* flash page 24 cpu 0x7516 (offset 0x3516) */
void p24_L_7516(void) {
  a = mem_read8(0x8479);
  flag_cmp(a, 0x63);
  set_hl(0x91D9);
  set_de(0x91E0);
  a = 0x01;
  if (flag_z()) return;
  p00_L_2429();
  return;
}

/* flash page 24 cpu 0x7527 (offset 0x3527) */
void p24_L_7527(void) {
  p00_L_2429();
  p24_L_752A();
  return;
}

/* flash page 24 cpu 0x752A (offset 0x352A) */
void p24_L_752A(void) {
  p00_L_1EF4();
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  mem_write8(0x8483, a);
  p24_L_5AB3();
  a = mem_read8(0x8483);
  cpu_push_af();
  p00_rst18();
  cpu_pop_hl();
  l = 0x3F;
  p00_L_1671();
  cpu_pop_bc();
  p24_L_7498();
  set_bc(mem_read16(0x982A));
  p24_L_7498();
  p24_L_6873();
  p24_L_5923();
  set_hl(mem_read16(0x9665));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x9665, hl());
  p00_L_1717();
  p24_L_5B18();
  p00_L_1037();
  p00_L_1830();
  if (flag_nz()) { p00_L_24DD(); return; }
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) | (1u << 3)));
  p00_L_22F7();
  p00_rst18();
  p00_rst18();
  p00_L_1179();
  p24_L_615D();
  p00_rst08();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 3)));
  p00_L_219B();
  p00_L_1641();
  if (flag_nz()) goto lab_p24_L_7586;
  p00_rst10();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  lab_p24_L_7586: ;
  p00_L_21A7();
  p24_L_74A8();
  mem_write16(0x982A, bc());
  p24_L_74A8();
  cpu_push_bc();
  p00_L_219B();
  p24_L_5A83();
  p00_L_1179();
  return;
}

/* flash page 24 cpu 0x759D (offset 0x359D) */
void p24_L_759D(void) {
  p00_L_0087();
  p00_L_32EB();
  p00_L_2D7B();
  set_hl(0x0000);
  mem_write16(0x84B0, hl());
  p24_L_75AC();
  return;
}

/* flash page 24 cpu 0x75AC (offset 0x35AC) */
void p24_L_75AC(void) {
  lab_p24_L_75AC: ;
  p24_L_700C();
  if (flag_nc()) goto lab_p24_L_75C3;
  lab_p24_L_75B1: ;
  set_hl(mem_read16(0x84B0));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) return;
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x84B0, hl());
  p24_L_5A80();
  lab_p24_L_75BE: ;
  p24_L_7005();
  if (flag_c()) goto lab_p24_L_75B1;
  lab_p24_L_75C3: ;
  flag_cmp(a, 0xD6);
  if (flag_z()) goto lab_p24_L_75D4;
  flag_cmp(a, 0xD7);
  if (flag_z()) goto lab_p24_L_75D4;
  flag_cmp(a, 0x2A);
  if (flag_nz()) goto lab_p24_L_75D9;
  p24_L_5379();
  goto lab_p24_L_75BE;
  lab_p24_L_75D4: ;
  p24_L_6FC0();
  goto lab_p24_L_75BE;
  lab_p24_L_75D9: ;
  p24_L_73DF();
  if (flag_c()) goto lab_p24_L_75F0;
  p24_L_75DE();
  return;
  lab_p24_L_75E9: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  p24_L_5F41();
  goto lab_p24_L_75BE;
  lab_p24_L_75F0: ;
  flag_cmp(a, 0x5C);
  if (flag_nz()) goto lab_p24_L_7606;
  p24_L_7071();
  p00_L_241E();
  if (flag_nc()) goto lab_p24_L_763A;
  set_hl(0x0101);
  p00_L_1C81();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  goto lab_p24_L_75E9;
  lab_p24_L_7606: ;
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p24_L_7620;
  lab_p24_L_760A: ;
  p24_L_7049();
  p00_L_241E();
  if (flag_c()) goto lab_p24_L_7616;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  goto lab_p24_L_75BE;
  lab_p24_L_7616: ;
  set_hl(0x0000);
  p00_L_1C46();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  goto lab_p24_L_75BE;
  lab_p24_L_7620: ;
  flag_cmp(a, 0xEB);
  if (flag_z()) goto lab_p24_L_760A;
  flag_cmp(a, 0xAA);
  if (flag_nz()) goto lab_p24_L_766C;
  p24_L_7071();
  p00_L_241E();
  if (flag_nc()) goto lab_p24_L_763A;
  set_hl(0x0000);
  p00_L_1C8F();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  lab_p24_L_7638: ;
  goto lab_p24_L_75BE;
  lab_p24_L_763A: ;
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p24_L_75BE;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  mem_write16(0x848E, hl());
  set_bc(0x0009);
  set_de(0x84A1);
  /* lddr */
  set_hl((uint16_t)(hl() + 1));
  set_de(mem_read16(0x9830));
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p24_L_7661;
  b = h;
  c = l;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() - 1));
  set_de(mem_read16(0x848E));
  /* lddr */
  lab_p24_L_7661: ;
  cpu_pop_de();
  set_hl(0x8499);
  set_bc(0x0009);
  while (bc() != 0) { cpu_ldi(); }
  goto lab_p24_L_7638;
  lab_p24_L_766C: ;
  flag_cmp(a, 0x5E);
  if (flag_nz()) goto lab_p24_L_7694;
  p24_L_7071();
  p00_L_2429();
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p24_L_7685;
  lab_p24_L_767A: ;
  p24_L_700C();
  p00_L_1730();
  if (flag_z()) p24_L_7005();
  goto lab_p24_L_7638;
  lab_p24_L_7685: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  p24_L_5AD1();
  set_hl(mem_read16(0x84B0));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x84B0, hl());
  goto lab_p24_L_75AC;
  lab_p24_L_7694: ;
  flag_cmp(a, 0x72);
  if (flag_z()) { p00_L_24FD(); return; }
  flag_cmp(a, 0x63);
  if (flag_z()) goto lab_p24_L_767A;
  flag_cmp(a, 0x5F);
  if (flag_c()) goto lab_p24_L_767A;
  flag_cmp(a, 0x62);
  if (flag_c()) { p00_L_24DD(); return; }
  if (flag_nz()) goto lab_p24_L_767A;
  p24_L_7093();
  flag_cmp(a, 0x21);
  if (flag_nz()) goto lab_p24_L_767A;
  a = 0x62;
  p24_L_75DE();
  return;
}

/* flash page 24 cpu 0x75DE (offset 0x35DE) */
void p24_L_75DE(void) {
  goto lab_p24_L_75DE;
  lab_p24_L_75B1: ;
  set_hl(mem_read16(0x84B0));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) return;
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x84B0, hl());
  p24_L_5A80();
  lab_p24_L_75BE: ;
  p24_L_7005();
  if (flag_c()) goto lab_p24_L_75B1;
  flag_cmp(a, 0xD6);
  if (flag_z()) goto lab_p24_L_75D4;
  flag_cmp(a, 0xD7);
  if (flag_z()) goto lab_p24_L_75D4;
  flag_cmp(a, 0x2A);
  if (flag_nz()) goto lab_p24_L_75D9;
  p24_L_5379();
  goto lab_p24_L_75BE;
  lab_p24_L_75D4: ;
  p24_L_6FC0();
  goto lab_p24_L_75BE;
  lab_p24_L_75D9: ;
  p24_L_73DF();
  if (flag_c()) goto lab_p24_L_75F0;
  lab_p24_L_75DE: ;
  p24_L_7071();
  p00_L_241E();
  if (flag_nc()) goto lab_p24_L_763A;
  p00_L_1C39();
  lab_p24_L_75E9: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  p24_L_5F41();
  goto lab_p24_L_75BE;
  lab_p24_L_75F0: ;
  flag_cmp(a, 0x5C);
  if (flag_nz()) goto lab_p24_L_7606;
  p24_L_7071();
  p00_L_241E();
  if (flag_nc()) goto lab_p24_L_763A;
  set_hl(0x0101);
  p00_L_1C81();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  goto lab_p24_L_75E9;
  lab_p24_L_7606: ;
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p24_L_7620;
  lab_p24_L_760A: ;
  p24_L_7049();
  p00_L_241E();
  if (flag_c()) goto lab_p24_L_7616;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  goto lab_p24_L_75BE;
  lab_p24_L_7616: ;
  set_hl(0x0000);
  p00_L_1C46();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  goto lab_p24_L_75BE;
  lab_p24_L_7620: ;
  flag_cmp(a, 0xEB);
  if (flag_z()) goto lab_p24_L_760A;
  flag_cmp(a, 0xAA);
  if (flag_nz()) goto lab_p24_L_766C;
  p24_L_7071();
  p00_L_241E();
  if (flag_nc()) goto lab_p24_L_763A;
  set_hl(0x0000);
  p00_L_1C8F();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  lab_p24_L_7638: ;
  goto lab_p24_L_75BE;
  lab_p24_L_763A: ;
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p24_L_75BE;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  mem_write16(0x848E, hl());
  set_bc(0x0009);
  set_de(0x84A1);
  /* lddr */
  set_hl((uint16_t)(hl() + 1));
  set_de(mem_read16(0x9830));
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p24_L_7661;
  b = h;
  c = l;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() - 1));
  set_de(mem_read16(0x848E));
  /* lddr */
  lab_p24_L_7661: ;
  cpu_pop_de();
  set_hl(0x8499);
  set_bc(0x0009);
  while (bc() != 0) { cpu_ldi(); }
  goto lab_p24_L_7638;
  lab_p24_L_766C: ;
  flag_cmp(a, 0x5E);
  if (flag_nz()) goto lab_p24_L_7694;
  p24_L_7071();
  p00_L_2429();
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p24_L_7685;
  lab_p24_L_767A: ;
  p24_L_700C();
  p00_L_1730();
  if (flag_z()) p24_L_7005();
  goto lab_p24_L_7638;
  lab_p24_L_7685: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  p24_L_5AD1();
  set_hl(mem_read16(0x84B0));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x84B0, hl());
  p24_L_75AC();
  return;
  lab_p24_L_7694: ;
  flag_cmp(a, 0x72);
  if (flag_z()) { p00_L_24FD(); return; }
  flag_cmp(a, 0x63);
  if (flag_z()) goto lab_p24_L_767A;
  flag_cmp(a, 0x5F);
  if (flag_c()) goto lab_p24_L_767A;
  flag_cmp(a, 0x62);
  if (flag_c()) { p00_L_24DD(); return; }
  if (flag_nz()) goto lab_p24_L_767A;
  p24_L_7093();
  flag_cmp(a, 0x21);
  if (flag_nz()) goto lab_p24_L_767A;
  a = 0x62;
  goto lab_p24_L_75DE;
}

/* flash page 24 cpu 0x76B4 (offset 0x36B4) */
void p24_L_76B4(void) {
  a = 0x03;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_2D51();
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x29)) & (1u << 2)) == 0);
  if (flag_nz()) p00_L_30F3();
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 3)));
  a = mem_read8((uint16_t)(iy + 0x3C));
  a = a & 0xF4;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x3C), a);
  p00_L_17DB();
  a = mem_read8(0x9CAE);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) p00_L_0BAF();
  a = 0;
  flag_logic(a);
  mem_write8(0x9CAE, a);
  mem_write8(0x97A7, a);
  mem_write8(0x8E2A, a);
  set_hl(0x7845);
  p00_L_07CC();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p24_L_76FA;
  mem_write8((uint16_t)(iy + 0x1C), (uint8_t)(mem_read8((uint16_t)(iy + 0x1C)) & ~(1u << 6)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 7)) == 0);
  if (flag_nz()) return;
  lab_p24_L_76FA: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p24_L_77A6;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 0)));
  p00_L_3E91();
  p00_L_36DB();
  p00_L_2FAF();
  p24_L_7D37();
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 5)));
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 7)));
  p00_L_17FA();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 4)));
  p24_L_7EF2();
  set_hl(0x0800);
  p00_L_17CE();
  if (flag_z()) goto lab_p24_L_773E;
  l = 0x04;
  lab_p24_L_773E: ;
  mem_write16(0x858A, hl());
  set_hl(mem_read16(0x96F0));
  mem_write16(0x858B, hl());
  set_hl(0x966E);
  set_de(0x8508);
  set_bc(0x0080);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(mem_read16(0x96EE));
  mem_write16(0x8588, hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 2)) == 0);
  if (flag_z()) p00_L_3D7D();
  set_hl(0x7789);
  p00_L_25A2();
  p00_L_176F();
  p00_L_25C8();
  set_hl(0x9D8D);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 0)));
  p00_L_30B1();
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 2)) == 0);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 2)));
  p00_L_3D2F();
  set_hl(mem_read16(0x96F2));
  mem_write16(0x86E0, hl());
  p00_L_30CF();
  return;
  lab_p24_L_77A6: ;
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 7)));
  p00_L_17FA();
  p00_L_3D17();
  p24_L_7B10();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 5)));
  set_hl(0x9652);
  p00_rst20();
  p00_L_1037();
  flag_cmp(a, 0x06);
  if (flag_z()) { p00_L_24F9(); return; }
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p24_L_77D5;
  p00_L_19E7();
  if (flag_c()) goto lab_p24_L_77D8;
  p00_L_2415();
  goto lab_p24_L_77D8;
  lab_p24_L_77D5: ;
  p00_L_3033();
  lab_p24_L_77D8: ;
  if (flag_c()) { p00_L_24F9(); return; }
  set_de(0x002A);
  p00_L_36C3();
  if (flag_z()) goto lab_p24_L_7835;
  set_de(0x0004);
  p00_L_36C3();
  if (flag_z()) goto lab_p24_L_7835;
  set_hl(0x9653);
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  a = d;
  flag_cmp(a, 0x3F);
  if (flag_nz()) goto lab_p24_L_7827;
  cpu_push_de();
  a = 0xFF;
  p00_L_1682();
  cpu_pop_de();
  lab_p24_L_77FD: ;
  cpu_push_de();
  p00_L_3ADD();
  if (flag_c()) { p00_L_24FD(); return; }
  a = mem_read8(0x8481);
  cpu_pop_de();
  flag_cmp(a, e);
  if (flag_nz()) goto lab_p24_L_77FD;
  set_hl(0x8479);
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  a = e;
  flag_cmp(a, 0x06);
  if (flag_c()) goto lab_p24_L_7827;
  lab_p24_L_7816: ;
  d = 0x00;
  cpu_push_hl();
  p00_L_36C3();
  if (flag_z()) goto lab_p24_L_7835;
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p24_L_782C;
  e = a;
  goto lab_p24_L_7816;
  lab_p24_L_7827: ;
  p00_L_36C3();
  if (flag_z()) goto lab_p24_L_7835;
  lab_p24_L_782C: ;
  p00_L_3645();
  set_de(0x002A);
  p00_L_36C3();
  lab_p24_L_7835: ;
  if (flag_z()) { p00_L_24F9(); return; }
  set_hl(mem_read16(0x86E0));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x86E0, hl());
  p00_L_30CF();
  p00_L_002B();
  return;
}

/* flash page 24 cpu 0x7AE4 (offset 0x3AE4) */
void p24_L_7AE4(void) {
  p00_L_1664();
  p00_L_19E7();
  if (flag_nc()) p00_L_1F58();
  set_hl(0x0000);
  p00_L_1CBF();
  p00_L_165F();
  p00_L_19E7();
  if (flag_nc()) p00_L_1F58();
  set_hl(0x0000);
  mem_write16(0x96F2, hl());
  p00_L_1CBF();
  set_hl(0x7845);
  p00_L_07CC();
  a = 0x40;
  mem_write8(0x859A, a);
  p24_L_7B10();
  return;
}

/* flash page 24 cpu 0x7B10 (offset 0x3B10) */
void p24_L_7B10(void) {
  p00_L_165F();
  p00_L_19E7();
  p00_L_3651();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 0)));
  p24_L_7B21();
  return;
}

/* flash page 24 cpu 0x7B21 (offset 0x3B21) */
void p24_L_7B21(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 5)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  return;
}

/* flash page 24 cpu 0x7B2A (offset 0x3B2A) */
void p24_L_7B2A(void) {
  p24_L_7B10();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  p00_L_3E8B();
  p24_L_7D57();
  a = mem_read8(0x8A36);
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p24_L_7B64;
  b = 0x1D;
  flag_cmp(a, 0x0E);
  if (flag_z()) goto lab_p24_L_7B6B;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p24_L_7B6B;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x12);
  if (flag_z()) goto lab_p24_L_7B6B;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x13);
  if (flag_z()) goto lab_p24_L_7B6B;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p24_L_7B6B;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x16);
  if (flag_z()) goto lab_p24_L_7B6B;
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x0B);
  if (flag_z()) goto lab_p24_L_7B6B;
  lab_p24_L_7B64: ;
  p00_L_1725();
  if (flag_z()) goto lab_p24_L_7B6C;
  b = 0x0A;
  lab_p24_L_7B6B: ;
  a = b;
  lab_p24_L_7B6C: ;
  e = a;
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + e);
  e = a;
  d = 0x00;
  set_hl(0x7BF4);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p24_L_7B98;
  p00_L_1725();
  if (flag_nz()) goto lab_p24_L_7B98;
  b = a;
  a = mem_read8(0x8A36);
  flag_cmp(a, 0x09);
  if (flag_nc()) goto lab_p24_L_7B97;
  flag_cmp(a, 0x05);
  if (flag_c()) goto lab_p24_L_7B95;
  flag_cmp(a, 0x08);
  if (flag_z()) goto lab_p24_L_7B97;
  goto lab_p24_L_7B96;
  lab_p24_L_7B95: ;
  b = (uint8_t)(b - 1);
  lab_p24_L_7B96: ;
  b = (uint8_t)(b - 1);
  lab_p24_L_7B97: ;
  a = b;
  lab_p24_L_7B98: ;
  mem_write8(0x85D1, a);
  a = 0x01;
  mem_write8(0x85D2, a);
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  mem_write16(0x85D4, de());
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = a;
  a = mem_read8(hl());
  p00_L_2D57();
  p00_L_3D2F();
  a = 0;
  flag_logic(a);
  p24_L_7BB4();
  return;
}

/* flash page 24 cpu 0x7BB4 (offset 0x3BB4) */
void p24_L_7BB4(void) {
  lab_p24_L_7BB4: ;
  a = (uint8_t)(a + 1);
  cpu_push_af();
  p24_L_7CE0();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  p00_L_3CD5();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  p00_L_3CCF();
  if (flag_nc()) goto lab_p24_L_7BD1;
  cpu_pop_af();
  set_hl(0x85D1);
  cpu_cp_hl();
  if (flag_nz()) goto lab_p24_L_7BB4;
  cpu_push_af();
  lab_p24_L_7BD1: ;
  cpu_pop_af();
  mem_write8(0x85D3, a);
  p24_L_7BD5();
  return;
}

/* flash page 24 cpu 0x7BD5 (offset 0x3BD5) */
void p24_L_7BD5(void) {
  p24_L_7D40();
  if (flag_z()) goto lab_p24_L_7BDF;
  a = 0x1E;
  p00_L_3F9F();
  lab_p24_L_7BDF: ;
  p24_L_7D49();
  if (flag_z()) goto lab_p24_L_7BE9;
  a = 0x1F;
  p00_L_3F9F();
  lab_p24_L_7BE9: ;
  set_hl(0x0007);
  mem_write16(0x844B, hl());
  set_hl(0x97A6);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  return;
}

/* flash page 24 cpu 0x7CE0 (offset 0x3CE0) */
void p24_L_7CE0(void) {
  a = (uint8_t)(a - 1);
  set_hl(mem_read16(0x85D4));
  e = a;
  d = 0x00;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  a = mem_read8(hl());
  flag_cmp(a, 0xFE);
  if (flag_c()) goto lab_p24_L_7CF3;
  p00_L_2D5D();
  return;
  lab_p24_L_7CF3: ;
  cpu_push_af();
  d = 0x62;
  e = a;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x37);
  a = 0x01;
  if (flag_c()) goto lab_p24_L_7D00;
  a = (uint8_t)(a + 1);
  lab_p24_L_7D00: ;
  mem_write8(0x844C, a);
  p00_L_3DB9();
  p00_L_3C93();
  a = 0x3D;
  p00_L_3F9F();
  p00_L_3279();
  p24_L_7D37();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 2)));
  cpu_pop_af();
  p00_L_18A3();
  a = 0;
  flag_logic(a);
  mem_write8(0x848E, a);
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_z()) goto lab_p24_L_7D30;
  a = 0x0F;
  set_hl(0x97A7);
  /* sub (hl) */
  p00_L_326D();
  lab_p24_L_7D30: ;
  set_hl(0x848E);
  p00_L_327F();
  return;
}

/* flash page 24 cpu 0x7D37 (offset 0x3D37) */
void p24_L_7D37(void) {
  a = mem_read8(0x89FE);
  a = a & 0xC0;
  flag_logic(a);
  mem_write8(0x89FE, a);
  return;
}

/* flash page 24 cpu 0x7D40 (offset 0x3D40) */
void p24_L_7D40(void) {
  p00_L_3D2F();
  a = mem_read8(0x85D2);
  flag_cmp(a, 0x01);
  return;
}

/* flash page 24 cpu 0x7D49 (offset 0x3D49) */
void p24_L_7D49(void) {
  set_hl(0x0006);
  mem_write16(0x844B, hl());
  a = mem_read8(0x85D3);
  set_hl(0x85D1);
  cpu_cp_hl();
  return;
}

/* flash page 24 cpu 0x7D57 (offset 0x3D57) */
void p24_L_7D57(void) {
  a = 0x07;
  mem_write8(0x97A6, a);
  return;
}

/* flash page 24 cpu 0x7D5D (offset 0x3D5D) */
void p24_L_7D5D(void) {
  set_hl(0x7D81);
  p00_L_07CC();
  p00_L_3D7D();
  p24_L_7EEC();
  p00_rst10();
  if (flag_nc()) goto lab_p24_L_7D72;
  set_hl(0x0000);
  p00_L_1CA8();
  lab_p24_L_7D72: ;
  mem_write16(0x9706, hl());
  mem_write8(hl(), 0x03);
  p00_L_3651();
  set_hl(0x865F);
  p00_L_3C87();
  return;
}

/* flash page 24 cpu 0x7EA6 (offset 0x3EA6) */
void p24_L_7EA6(void) {
  set_hl(0x003F);
  mem_write16(0x865F, hl());
  return;
}

/* flash page 24 cpu 0x7EAD (offset 0x3EAD) */
void p24_L_7EAD(void) {
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x865E, a);
  goto lab_p24_L_7ECF;
  lab_p24_L_7EB7: ;
  set_bc((uint16_t)(bc() - 1));
  cpu_push_de();
  set_hl((uint16_t)(hl() + 1));
  p00_L_3C0F();
  if (flag_nc()) goto lab_p24_L_7EC0;
  set_bc((uint16_t)(bc() - 1));
  lab_p24_L_7EC0: ;
  /* ex (sp),hl */
  cpu_push_bc();
  cpu_push_hl();
  p00_L_3DAD();
  cpu_pop_de();
  set_hl((uint16_t)(hl() + 1));
  p00_L_3DEF();
  cpu_pop_bc();
  cpu_pop_hl();
  if (flag_z()) goto lab_p24_L_7ED3;
  lab_p24_L_7ECF: ;
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p24_L_7EB7;
  lab_p24_L_7ED3: ;
  cpu_ex_de_hl();
  mem_write8(hl(), 0x00);
  return;
}

/* flash page 24 cpu 0x7EEC (offset 0x3EEC) */
void p24_L_7EEC(void) {
  set_hl(0x002D);
  p00_L_1671();
  return;
}

/* flash page 24 cpu 0x7EF2 (offset 0x3EF2) */
void p24_L_7EF2(void) {
  p24_L_7EEC();
  p00_rst10();
  if (flag_nc()) p00_L_1F58();
  return;
}

/* flash page 24 cpu 0x7EFA (offset 0x3EFA) */
void p24_L_7EFA(void) {
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 1)));
  goto lab_p24_L_7F04;
  lab_p24_L_7F04: ;
  a = mem_read8(0x9653);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x29), (uint8_t)(mem_read8((uint16_t)(iy + 0x29)) | (1u << 0)));
  a = 0x50;
  p00_mmu_set_bankA_4();
  p00_L_03CF();
  /* set 5,(iy) */
  p00_L_2222();
  p00_L_3D29();
  mem_write8((uint16_t)(iy + 0x29), (uint8_t)(mem_read8((uint16_t)(iy + 0x29)) | (1u << 1)));
  a = 0x3F;
  p00_mmu_set_bankA_4();
  cpu_pop_af();
  mem_write8(0x9653, a);
  p00_L_2176();
  return;
}

/* flash page 24 cpu 0x7F00 (offset 0x3F00) */
void p24_L_7F00(void) {
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 1)));
  a = mem_read8(0x9653);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x29), (uint8_t)(mem_read8((uint16_t)(iy + 0x29)) | (1u << 0)));
  a = 0x50;
  p00_mmu_set_bankA_4();
  p00_L_03CF();
  /* set 5,(iy) */
  p00_L_2222();
  p00_L_3D29();
  mem_write8((uint16_t)(iy + 0x29), (uint8_t)(mem_read8((uint16_t)(iy + 0x29)) | (1u << 1)));
  a = 0x3F;
  p00_mmu_set_bankA_4();
  cpu_pop_af();
  mem_write8(0x9653, a);
  p00_L_2176();
  return;
}

/* flash page 24 cpu 0x7F2E (offset 0x3F2E) */
void p24_L_7F2E(void) {
  p00_L_3D17();
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 2)));
  /* set 5,(iy) */
  return;
}

/* flash page 24 cpu 0x7F3A (offset 0x3F3A) */
void p24_L_7F3A(void) {
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 2)) == 0);
  if (flag_z()) return;
  a = 0;
  flag_logic(a);
  mem_write8(0x8D17, a);
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 5)));
  p00_L_3D71();
  p00_L_3D7D();
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  return;
}

/* flash page 24 cpu 0x7F5E (offset 0x3F5E) */
void p24_L_7F5E(void) {
  /* set 5,(iy) */
  p24_L_7F3A();
  p00_L_3003();
  p00_L_302D();
  return;
}

/* flash page 24 cpu 0x7F6C (offset 0x3F6C) */
void p24_L_7F6C(void) {
  a = 0xAA;
  mem_write8(0x8477, a);
  lab_p24_L_7F71: ;
  p00_L_3F21();
  p00_L_0189();
  if (flag_nz()) goto lab_p24_L_7F7D;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p24_L_7F71;
  lab_p24_L_7F7D: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8445, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p24_L_7F8E;
  p00_L_3DA1();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  lab_p24_L_7F8E: ;
  a = 0xF0;
  mem_write8(0x8477, a);
  return;
}

/* flash page 24 cpu 0x7F94 (offset 0x3F94) */
void p24_L_7F94(void) {
  goto lab_p24_L_7F94;
  lab_p24_L_7F7D: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8445, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p24_L_7F8E;
  p00_L_3DA1();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  lab_p24_L_7F8E: ;
  a = 0xF0;
  mem_write8(0x8477, a);
  return;
  lab_p24_L_7F94: ;
  /* set 5,(iy) */
  p24_L_7F3A();
  p00_L_3003();
  a = 0xAA;
  mem_write8(0x8477, a);
  lab_p24_L_7FA3: ;
  p00_L_3F21();
  p00_L_0189();
  if (flag_nz()) goto lab_p24_L_7FD3;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p24_L_7FB4;
  p00_L_3021();
  goto lab_p24_L_7FA3;
  lab_p24_L_7FB4: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p24_L_7FBD;
  p00_L_300F();
  goto lab_p24_L_7FA3;
  lab_p24_L_7FBD: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p24_L_7FC6;
  p00_L_3015();
  goto lab_p24_L_7FA3;
  lab_p24_L_7FC6: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p24_L_7FCF;
  p00_L_301B();
  goto lab_p24_L_7FA3;
  lab_p24_L_7FCF: ;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p24_L_7FA3;
  lab_p24_L_7FD3: ;
  p00_L_302D();
  goto lab_p24_L_7F7D;
}


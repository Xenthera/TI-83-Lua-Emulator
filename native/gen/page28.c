/* Recovered from flash page 28 (mechanical ASM->C) */
/* cpu window 0x4000..0x7FFF prefix=p28_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p28_str_1(void);
void p28_str_2(void);
void p28_L_4006(void);
void p28_L_4008(void);
void p28_L_4047(void);
void p28_L_404A(void);
void p28_L_404C(void);
void p28_L_4053(void);
void p28_L_405D(void);
void p28_L_4068(void);
void p28_L_406B(void);
void p28_L_4073(void);
void p28_L_40C5(void);
void p28_L_40C9(void);
void p28_L_40D1(void);
void p28_L_40D5(void);
void p28_L_40E3(void);
void p28_L_4100(void);
void p28_L_412D(void);
void p28_L_4130(void);
void p28_L_4163(void);
void p28_L_416F(void);
void p28_L_418C(void);
void p28_L_4190(void);
void p28_L_4192(void);
void p28_L_41A2(void);
void p28_L_41AF(void);
void p28_L_41B3(void);
void p28_L_41BA(void);
void p28_L_4204(void);
void p28_L_421B(void);
void p28_L_424C(void);
void p28_L_4258(void);
void p28_L_4275(void);
void p28_L_4289(void);
void p28_L_42F2(void);
void p28_L_42F8(void);
void p28_L_4306(void);
void p28_L_430F(void);
void p28_L_4317(void);
void p28_L_432F(void);
void p28_L_4332(void);
void p28_L_4380(void);
void p28_L_4393(void);
void p28_L_439A(void);
void p28_L_43C4(void);
void p28_L_43C7(void);
void p28_L_442B(void);
void p28_L_4436(void);
void p28_L_443A(void);
void p28_L_4441(void);
void p28_L_4476(void);
void p28_L_447D(void);
void p28_L_44A9(void);
void p28_L_44FB(void);
void p28_L_4557(void);
void p28_L_472C(void);
void p28_L_4759(void);
void p28_L_478C(void);
void p28_L_47CB(void);
void p28_L_482B(void);
void p28_L_485F(void);
void p28_L_48EE(void);
void p28_L_4906(void);
void p28_L_4956(void);
void p28_L_4976(void);
void p28_L_49C9(void);
void p28_L_4A71(void);
void p28_L_4A9D(void);
void p28_L_4AA1(void);
void p28_L_4B12(void);
void p28_L_4B1A(void);
void p28_L_4B25(void);
void p28_L_4B3B(void);
void p28_L_4B62(void);
void p28_L_4C43(void);
void p28_L_4C6C(void);
void p28_L_4C78(void);
void p28_L_4CD1(void);
void p28_L_4E01(void);
void p28_L_4E0E(void);
void p28_L_4E18(void);
void p28_L_4E1F(void);
void p28_L_4E4F(void);
void p28_L_4F11(void);
void p28_L_4F23(void);
void p28_L_4F79(void);
void p28_L_4F85(void);
void p28_L_4F91(void);
void p28_L_512D(void);
void p28_L_5132(void);
void p28_L_5157(void);
void p28_L_5173(void);
void p28_L_533D(void);
void p28_L_53ED(void);
void p28_L_54EA(void);
void p28_L_5556(void);
void p28_L_5580(void);
void p28_L_561B(void);
void p28_L_5690(void);
void p28_L_56B2(void);
void p28_L_56BB(void);
void p28_L_56F5(void);
void p28_L_56FB(void);
void p28_L_56FE(void);
void p28_L_5737(void);
void p28_L_575D(void);
void p28_L_5852(void);
void p28_L_5897(void);
void p28_L_589A(void);
void p28_L_58A6(void);
void p28_L_5922(void);
void p28_L_593A(void);
void p28_L_594D(void);
void p28_L_5966(void);
void p28_L_59B8(void);
void p28_L_59CE(void);
void p28_L_59DE(void);
void p28_L_5A39(void);
void p28_L_5A52(void);
void p28_L_5A56(void);
void p28_L_5A8F(void);
void p28_L_5A9A(void);
void p28_L_5ABF(void);
void p28_L_5ACD(void);
void p28_L_5B03(void);
void p28_L_5B10(void);
void p28_L_5BED(void);
void p28_L_5C20(void);
void p28_L_5C50(void);
void p28_L_5CAD(void);
void p28_L_5CBA(void);
void p28_L_5DC3(void);
void p28_L_5DCC(void);
void p28_L_5E00(void);
void p28_L_5FCD(void);
void p28_L_5FD4(void);
void p28_L_6001(void);
void p28_L_6013(void);
void p28_L_6023(void);
void p28_str_3(void);
void p28_str_4(void);
void p28_L_60D7(void);
void p28_L_60ED(void);
void p28_L_60F8(void);
void p28_L_610C(void);
void p28_L_6114(void);
void p28_L_6144(void);
void p28_L_6158(void);
void p28_L_6190(void);
void p28_L_619D(void);
void p28_L_619F(void);
void p28_L_61C5(void);
void p28_L_61D8(void);
void p28_L_61F5(void);
void p28_L_61FE(void);
void p28_L_6206(void);
void p28_L_6215(void);
void p28_L_621A(void);
void p28_L_6223(void);
void p28_L_6228(void);
void p28_L_6237(void);
void p28_L_6246(void);
void p28_L_6252(void);
void p28_L_6259(void);
void p28_L_626B(void);
void p28_L_626E(void);
void p28_L_6271(void);
void p28_L_6275(void);
void p28_L_62CF(void);
void p28_L_6313(void);
void p28_L_6320(void);
void p28_L_6329(void);
void p28_L_634F(void);
void p28_L_635E(void);
void p28_L_637A(void);
void p28_L_6393(void);
void p28_L_63C3(void);
void p28_L_6421(void);
void p28_L_6439(void);
void p28_L_6444(void);
void p28_L_644C(void);
void p28_L_6467(void);
void p28_L_64BB(void);
void p28_L_64D6(void);
void p28_L_64DF(void);
void p28_L_651A(void);
void p28_L_6530(void);
void p28_L_656B(void);
void p28_L_6586(void);
void p28_L_658D(void);
void p28_L_6595(void);
void p28_L_65A1(void);
void p28_L_65D5(void);
void p28_L_660B(void);
void p28_L_6640(void);
void p28_L_665A(void);
void p28_L_6673(void);
void p28_L_66FE(void);
void p28_L_6786(void);
void p28_L_6795(void);
void p28_L_67BD(void);
void p28_L_67C5(void);
void p28_L_689C(void);
void p28_L_68B2(void);
void p28_L_68BD(void);
void p28_L_6918(void);
void p28_L_6924(void);
void p28_L_69D3(void);
void p28_L_6A1E(void);
void p28_L_6A30(void);
void p28_L_6A3D(void);
void p28_L_6A43(void);
void p28_L_6A62(void);
void p28_L_6A79(void);
void p28_L_6A89(void);
void p28_L_6A93(void);
void p28_L_6B25(void);
void p28_L_6B2A(void);
void p28_L_6B48(void);
void p28_L_6B57(void);
void p28_L_6C11(void);
void p28_L_6C65(void);
void p28_L_6CCA(void);
void p28_L_6CD3(void);
void p28_L_6D10(void);
void p28_L_6D1C(void);
void p28_L_6D2E(void);
void p28_L_6D5F(void);
void p28_L_6D6E(void);
void p28_L_6D77(void);
void p28_L_6DA1(void);
void p28_L_6DB3(void);
void p28_L_6DCD(void);
void p28_L_6DDC(void);
void p28_L_6E0A(void);
void p28_L_6E1A(void);
void p28_L_6E29(void);
void p28_L_6E31(void);
void p28_L_6E37(void);
void p28_L_6E5A(void);
void p28_L_6E7E(void);
void p28_L_6E90(void);
void p28_L_6EE6(void);
void p28_L_6EF5(void);
void p28_L_6F20(void);
void p28_L_6F2A(void);
void p28_L_6F2D(void);
void p28_L_6F33(void);
void p28_L_6F37(void);
void p28_L_6FEA(void);
void p28_L_7022(void);
void p28_L_705F(void);
void p28_L_709C(void);
void p28_L_7119(void);
void p28_L_7145(void);
void p28_L_714F(void);
void p28_L_71E5(void);
void p28_L_71FA(void);
void p28_L_7222(void);
void p28_L_722B(void);
void p28_L_723A(void);
void p28_L_7251(void);
void p28_L_7257(void);
void p28_L_725D(void);
void p28_L_728E(void);
void p28_L_72B2(void);
void p28_L_72E9(void);
void p28_L_735B(void);
void p28_L_7371(void);
void p28_L_73E2(void);
void p28_L_73FE(void);
void p28_L_7417(void);
void p28_L_7422(void);
void p28_L_74B2(void);
void p28_L_74C1(void);
void p28_L_74CB(void);
void p28_L_74F8(void);
void p28_L_750C(void);
void p28_L_7529(void);
void p28_L_7532(void);
void p28_L_754B(void);
void p28_L_7569(void);
void p28_L_757B(void);
void p28_L_7581(void);
void p28_L_758D(void);
void p28_L_759B(void);
void p28_L_75F5(void);
void p28_L_7607(void);
void p28_L_7622(void);
void p28_L_7626(void);
void p28_L_762A(void);
void p28_L_763E(void);
void p28_L_7653(void);
void p28_L_765B(void);
void p28_L_766E(void);
void p28_L_767D(void);
void p28_L_7692(void);
void p28_L_76AE(void);
void p28_L_76D6(void);
void p28_L_76DE(void);
void p28_L_76F9(void);
void p28_L_770E(void);
void p28_L_772C(void);
void p28_L_7758(void);
void p28_L_7782(void);
void p28_L_778D(void);
void p28_L_77BD(void);
void p28_L_77DA(void);
void p28_L_7822(void);
void p28_L_783F(void);
void p28_L_7843(void);
void p28_L_786A(void);
void p28_L_787C(void);
void p28_L_78B5(void);
void p28_L_78BF(void);
void p28_L_78C9(void);
void p28_L_78D2(void);
void p28_L_78DD(void);
void p28_L_7958(void);
void p28_L_797E(void);
void p28_L_7987(void);
void p28_L_79A1(void);
void p28_L_79C2(void);
void p28_L_79CE(void);
void p28_L_79E2(void);
void p28_L_79EA(void);
void p28_L_7A09(void);
void p28_L_7A37(void);
void p28_L_7A5E(void);
void p28_L_7A71(void);
void p28_L_7AB9(void);
void p28_L_7AC2(void);
void p28_L_7AD0(void);
void p28_L_7AD8(void);
void p28_L_7AF1(void);
void p28_L_7AF3(void);
void p28_L_7B0D(void);
void p28_L_7B21(void);
void p28_L_7B3E(void);
void p28_L_7B46(void);
void p28_L_7B4F(void);
void p28_L_7B58(void);
void p28_L_7B89(void);
void p28_L_7B9F(void);
void p28_L_7BAC(void);
void p28_L_7BE3(void);
void p28_L_7C20(void);
void p28_L_7C2B(void);
void p28_L_7C2C(void);
void p28_L_7C3B(void);
void p28_L_7D11(void);
void p28_L_7D17(void);
void p28_L_7D1A(void);
void p28_L_7D21(void);
void p28_L_7D53(void);
void p28_L_7D99(void);
void p28_L_7DBE(void);
void p28_L_7DC5(void);
void p28_L_7DCD(void);
void p28_L_7DE3(void);
void p28_L_7DEA(void);
void p28_L_7E06(void);
void p28_L_7E10(void);
void p28_L_7E19(void);
void p28_L_7E2B(void);
void p28_L_7E37(void);
void p28_L_7E47(void);
void p28_L_7E52(void);
void p28_L_7E5C(void);
void p28_L_7E71(void);
void p28_L_7E7E(void);
void p28_L_7E7F(void);
void p28_L_7E85(void);
void p28_L_7E8C(void);
void p28_L_7E97(void);
void p28_L_7EA2(void);
void p28_L_7EAD(void);
void p28_L_7EB8(void);
void p28_L_7EC3(void);
void p28_L_7ECE(void);
void p28_L_7ED9(void);
void p28_L_7EE2(void);
void p28_L_7EE9(void);
void p28_L_7EF2(void);
void p28_L_7F0D(void);
void p28_L_7F11(void);
void p28_L_7F30(void);
void p28_L_7F3E(void);
void p28_L_7F58(void);
void p28_L_7F63(void);
void p28_L_7F97(void);

/* flash page 28 cpu 0x4000 (offset 0x0000) */
void p28_str_1(void) {
  sp = 0x312E;
  set_hl((uint16_t)(hl() + sp));
  if (flag_nz()) { p28_L_4006(); return; }
  p28_L_4006();
  return;
}

/* flash page 28 cpu 0x4001 (offset 0x0001) */
void p28_str_2(void) {
  l = 0x31;
  set_hl((uint16_t)(hl() + sp));
  if (flag_nz()) { p28_L_4006(); return; }
  p28_L_4006();
  return;
}

/* flash page 28 cpu 0x4006 (offset 0x0006) */
void p28_L_4006(void) {
  a = 0x06;
  p28_L_4008();
  return;
}

/* flash page 28 cpu 0x4008 (offset 0x0008) */
void p28_L_4008(void) {
  mem_write16(0x867D, de());
  set_de(0x867F);
  p00_L_11FD();
  set_hl(0x000B);
  cpu_push_af();
  a = mem_read8(0x8A0B);
  a = a & 0x1E;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_403E;
  set_hl(mem_read16(0x848C));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_4041;
  cpu_push_hl();
  p00_L_2408();
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_402E;
  a = 0x80;
  lab_p28_L_402E: ;
  b = a;
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  a = a | b;
  flag_logic(a);
  mem_write8(0x8689, a);
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  lab_p28_L_4038: ;
  mem_write8(0x8688, a);
  set_hl(0x000D);
  lab_p28_L_403E: ;
  cpu_pop_af();
  p28_L_404C();
  return;
  lab_p28_L_4041: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8689, a);
  goto lab_p28_L_4038;
}

/* flash page 28 cpu 0x4047 (offset 0x0047) */
void p28_L_4047(void) {
  set_hl(0x000A);
  p28_L_404A();
  return;
}

/* flash page 28 cpu 0x404A (offset 0x004A) */
void p28_L_404A(void) {
  a = 0x06;
  p28_L_404C();
  return;
}

/* flash page 28 cpu 0x404C (offset 0x004C) */
void p28_L_404C(void) {
  set_de(0x867D);
  cpu_ex_de_hl();
  p28_L_40D1();
  return;
}

/* flash page 28 cpu 0x4053 (offset 0x0053) */
void p28_L_4053(void) {
  p28_L_689C();
  set_de(0x0005);
  p28_L_405D();
  return;
}

/* flash page 28 cpu 0x405D (offset 0x005D) */
void p28_L_405D(void) {
  set_hl(0x867E);
  mem_write8(hl(), a);
  set_hl(0x867C);
  a = 0x36;
  p28_L_40D1();
  return;
}

/* flash page 28 cpu 0x4068 (offset 0x0068) */
void p28_L_4068(void) {
  set_de(0x0001);
  p28_L_406B();
  return;
}

/* flash page 28 cpu 0x406B (offset 0x006B) */
void p28_L_406B(void) {
  set_hl(0x867C);
  mem_write8(hl(), a);
  a = 0x36;
  p28_L_40D1();
  return;
}

/* flash page 28 cpu 0x4073 (offset 0x0073) */
void p28_L_4073(void) {
  p28_L_42F2();
  set_de(0x0300);
  mem_write16(0x8676, de());
  p28_L_6393();
  h = 0x15;
  mem_write16(0x8674, hl());
  p28_L_41BA();
  /* di */
  a = 0x07;
  p00_L_0AB9();
  a = 0x7F;
  b = 0x40;
  lab_p28_L_4092: ;
  cpu_push_bc();
  a = (uint8_t)(a + 1);
  mem_write8(0x8451, a);
  p00_lcd_cmd_07();
  p00_L_0AB9();
  a = 0x20;
  p00_L_0AB9();
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  b = 0x0C;
  lab_p28_L_40A9: ;
  cpu_push_bc();
  p00_lcd_busy_wait();
  a = hw_in(PORT_LCD_DATA);
  c = a;
  p28_L_41A2();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_40A9;
  cpu_pop_bc();
  a = mem_read8(0x8451);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_4092;
  a = 0x05;
  p00_L_0AB9();
  /* ei */
  p28_L_4163();
  return;
}

/* flash page 28 cpu 0x40C5 (offset 0x00C5) */
void p28_L_40C5(void) {
  b = 0x00;
  goto lab_p28_L_40CD;
  lab_p28_L_40CD: ;
  a = 0x15;
  goto lab_p28_L_40D3;
  lab_p28_L_40D3: ;
  cpu_ex_de_hl();
  p00_L_242F();
  cpu_ex_de_hl();
  mem_write16(0x84DB, hl());
  mem_write16(0x8676, de());
  h = a;
  p28_L_6F33();
  p28_L_40E3();
  return;
}

/* flash page 28 cpu 0x40C9 (offset 0x00C9) */
void p28_L_40C9(void) {
  a = mem_read8(0x848B);
  b = a;
  a = 0x15;
  goto lab_p28_L_40D3;
  lab_p28_L_40D3: ;
  cpu_ex_de_hl();
  p00_L_242F();
  cpu_ex_de_hl();
  mem_write16(0x84DB, hl());
  mem_write16(0x8676, de());
  h = a;
  p28_L_6F33();
  p28_L_40E3();
  return;
}

/* flash page 28 cpu 0x40D1 (offset 0x00D1) */
void p28_L_40D1(void) {
  b = 0x00;
  cpu_ex_de_hl();
  p00_L_242F();
  cpu_ex_de_hl();
  mem_write16(0x84DB, hl());
  mem_write16(0x8676, de());
  h = a;
  p28_L_6F33();
  p28_L_40E3();
  return;
}

/* flash page 28 cpu 0x40D5 (offset 0x00D5) */
void p28_L_40D5(void) {
  a = a ^ 0xFF;
  h = (uint8_t)(h + 1);
  cpu_ex_de_hl();
  mem_write16(0x84DB, hl());
  mem_write16(0x8676, de());
  h = a;
  p28_L_6F33();
  p28_L_40E3();
  return;
}

/* flash page 28 cpu 0x40E3 (offset 0x00E3) */
void p28_L_40E3(void) {
  p28_L_6B25();
  p28_L_6393();
  mem_write16(0x8674, hl());
  a = mem_read8(0x8672);
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p28_L_4134;
  a = mem_read8(0x85D9);
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p28_L_4134;
  set_de(mem_read16(0x8676));
  set_hl(0x037D);
  p00_L_192A();
  if (flag_nc()) goto lab_p28_L_4134;
  mem_write16(0x8676, hl());
  p28_L_41BA();
  set_bc(0x0000);
  mem_write16(0x8678, bc());
  c = 0x63;
  p28_L_41A2();
  c = 0x00;
  p28_L_41A2();
  set_de(mem_read16(0x8676));
  set_de((uint16_t)(de() - 1));
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x84DB));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_243E();
  p00_L_243E();
  goto lab_p28_L_415E;
  lab_p28_L_4134: ;
  p28_L_41BA();
  set_de(mem_read16(0x8676));
  set_hl(mem_read16(0x84DB));
  set_bc(0x0000);
  mem_write16(0x8678, bc());
  goto lab_p28_L_415E;
  lab_p28_L_4147: ;
  p00_L_171E();
  cpu_push_de();
  a = mem_read8(0x9835);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_4157;
  p00_L_243E();
  c = a;
  goto lab_p28_L_4158;
  lab_p28_L_4157: ;
  c = mem_read8(hl());
  lab_p28_L_4158: ;
  p28_L_41A2();
  cpu_pop_de();
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() + 1));
  lab_p28_L_415E: ;
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_4147;
  /* di */
  p28_L_4163();
  return;
}

/* flash page 28 cpu 0x4100 (offset 0x0100) */
void p28_L_4100(void) {
  set_bc((uint16_t)(bc() + 1));
  p00_L_192A();
  if (flag_nc()) goto lab_p28_L_4134;
  mem_write16(0x8676, hl());
  p28_L_41BA();
  set_bc(0x0000);
  mem_write16(0x8678, bc());
  c = 0x63;
  p28_L_41A2();
  c = 0x00;
  p28_L_41A2();
  set_de(mem_read16(0x8676));
  set_de((uint16_t)(de() - 1));
  set_de((uint16_t)(de() - 1));
  set_hl(mem_read16(0x84DB));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_243E();
  p00_L_243E();
  goto lab_p28_L_415E;
  lab_p28_L_4134: ;
  p28_L_41BA();
  set_de(mem_read16(0x8676));
  set_hl(mem_read16(0x84DB));
  set_bc(0x0000);
  mem_write16(0x8678, bc());
  goto lab_p28_L_415E;
  lab_p28_L_4147: ;
  p00_L_171E();
  cpu_push_de();
  a = mem_read8(0x9835);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_4157;
  p00_L_243E();
  c = a;
  goto lab_p28_L_4158;
  lab_p28_L_4157: ;
  c = mem_read8(hl());
  lab_p28_L_4158: ;
  p28_L_41A2();
  cpu_pop_de();
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() + 1));
  lab_p28_L_415E: ;
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_4147;
  /* di */
  p28_L_4163();
  return;
}

/* flash page 28 cpu 0x412D (offset 0x012D) */
void p28_L_412D(void) {
  h = (uint8_t)(h + 1);
  goto lab_p28_L_415E;
  lab_p28_L_4147: ;
  p00_L_171E();
  cpu_push_de();
  a = mem_read8(0x9835);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_4157;
  p00_L_243E();
  c = a;
  goto lab_p28_L_4158;
  lab_p28_L_4157: ;
  c = mem_read8(hl());
  lab_p28_L_4158: ;
  p28_L_41A2();
  cpu_pop_de();
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() + 1));
  lab_p28_L_415E: ;
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_4147;
  /* di */
  p28_L_4163();
  return;
}

/* flash page 28 cpu 0x4130 (offset 0x0130) */
void p28_L_4130(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x9835, a);
  p28_L_41BA();
  set_de(mem_read16(0x8676));
  set_hl(mem_read16(0x84DB));
  set_bc(0x0000);
  mem_write16(0x8678, bc());
  goto lab_p28_L_415E;
  lab_p28_L_4147: ;
  p00_L_171E();
  cpu_push_de();
  a = mem_read8(0x9835);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_4157;
  p00_L_243E();
  c = a;
  goto lab_p28_L_4158;
  lab_p28_L_4157: ;
  c = mem_read8(hl());
  lab_p28_L_4158: ;
  p28_L_41A2();
  cpu_pop_de();
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() + 1));
  lab_p28_L_415E: ;
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_4147;
  /* di */
  p28_L_4163();
  return;
}

/* flash page 28 cpu 0x4163 (offset 0x0163) */
void p28_L_4163(void) {
  set_hl(mem_read16(0x8678));
  a = l;
  cpu_push_hl();
  p28_L_4204();
  cpu_pop_af();
  p28_L_4204();
  p28_L_416F();
  return;
}

/* flash page 28 cpu 0x416F (offset 0x016F) */
void p28_L_416F(void) {
  p28_L_430F();
  p28_L_432F();
  a = mem_read8(0x8675);
  cpu_push_af();
  a = mem_read8(0x8674);
  set_hl(mem_read16(0x8676));
  cpu_push_hl();
  p28_L_4306();
  cpu_pop_hl();
  b = a;
  cpu_pop_af();
  flag_cmp(a, 0x56);
  if (flag_z()) return;
  p00_L_2565();
  return;
}

/* flash page 28 cpu 0x418C (offset 0x018C) */
void p28_L_418C(void) {
  h = 0x92;
  p28_L_4192();
  return;
}

/* flash page 28 cpu 0x4190 (offset 0x0190) */
void p28_L_4190(void) {
  h = 0x09;
  p28_L_4192();
  return;
}

/* flash page 28 cpu 0x4192 (offset 0x0192) */
void p28_L_4192(void) {
  p28_L_6B25();
  p28_L_6393();
  mem_write16(0x8674, hl());
  /* di */
  p28_L_41BA();
  /* ei */
  p28_L_416F();
  return;
}

/* flash page 28 cpu 0x41A2 (offset 0x01A2) */
void p28_L_41A2(void) {
  b = 0x00;
  cpu_ex_de_hl();
  set_hl(mem_read16(0x8678));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x8678, hl());
  cpu_ex_de_hl();
  goto lab_p28_L_4205;
  lab_p28_L_4205: ;
  p00_L_24A9();
  if (flag_z()) goto lab_p28_L_6D81;
  b = 0x08;
  set_de(0xFFFF);
  /* rr c */
  if (flag_nc()) goto lab_p28_L_4219;
  a = 0x02;
  p28_L_421B();
  return;
  lab_p28_L_4219: ;
  a = 0x01;
  p28_L_421B();
  return;
  lab_p28_L_6D81: ;
  p28_L_6F37();
  p28_L_6DA1();
  p28_L_6DA1();
  lab_p28_L_6D8A: ;
  a = 0xFA;
  mem_write8(0x9C86, a);
  a = hw_in(0x09);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) goto lab_p28_L_6D99;
  a = c;
  hw_out(0x0D, a);
  return;
  lab_p28_L_6D99: ;
  p28_L_6DB3();
  if (flag_z()) goto lab_p28_L_6D8A;
  p28_L_442B();
  return;
}

/* flash page 28 cpu 0x41AF (offset 0x01AF) */
void p28_L_41AF(void) {
  l = 0x83;
  goto lab_p28_L_41B5;
  lab_p28_L_41B5: ;
  h = 0x68;
  mem_write16(0x8674, hl());
  p28_L_41BA();
  return;
}

/* flash page 28 cpu 0x41B3 (offset 0x01B3) */
void p28_L_41B3(void) {
  l = 0x73;
  h = 0x68;
  mem_write16(0x8674, hl());
  p28_L_41BA();
  return;
}

/* flash page 28 cpu 0x41BA (offset 0x01BA) */
void p28_L_41BA(void) {
  p28_L_6F33();
  set_hl(0x00FA);
  lab_p28_L_41C0: ;
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_41C0;
  lab_p28_L_41C5: ;
  p00_L_24A9();
  if (flag_z()) goto lab_p28_L_41E3;
  a = 0x00;
  link_out(a); /* stub */
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p28_L_41E9;
  lab_p28_L_41D6: ;
  p28_L_447D();
  p28_L_4441();
  if (flag_c()) goto lab_p28_L_41E0;
  if (flag_z()) goto lab_p28_L_41C5;
  lab_p28_L_41E0: ;
  p00_L_255D();
  return;
  lab_p28_L_41E3: ;
  a = hw_in(0x09);
  a = a & 0x19;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_41D6;
  lab_p28_L_41E9: ;
  set_hl(0x0000);
  mem_write16(0x8678, hl());
  a = mem_read8(0x8674);
  p28_L_4204();
  a = mem_read8(0x8675);
  p28_L_4204();
  a = mem_read8(0x8676);
  p28_L_4204();
  a = mem_read8(0x8677);
  p28_L_4204();
  return;
}

/* flash page 28 cpu 0x4204 (offset 0x0204) */
void p28_L_4204(void) {
  c = a;
  p00_L_24A9();
  if (flag_z()) goto lab_p28_L_6D81;
  b = 0x08;
  set_de(0xFFFF);
  /* rr c */
  if (flag_nc()) goto lab_p28_L_4219;
  a = 0x02;
  p28_L_421B();
  return;
  lab_p28_L_4219: ;
  a = 0x01;
  p28_L_421B();
  return;
  lab_p28_L_6D81: ;
  p28_L_6F37();
  p28_L_6DA1();
  p28_L_6DA1();
  lab_p28_L_6D8A: ;
  a = 0xFA;
  mem_write8(0x9C86, a);
  a = hw_in(0x09);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) goto lab_p28_L_6D99;
  a = c;
  hw_out(0x0D, a);
  return;
  lab_p28_L_6D99: ;
  p28_L_6DB3();
  if (flag_z()) goto lab_p28_L_6D8A;
  p28_L_442B();
  return;
}

/* flash page 28 cpu 0x421B (offset 0x021B) */
void p28_L_421B(void) {
  goto lab_p28_L_421B;
  lab_p28_L_420D: ;
  set_de(0xFFFF);
  /* rr c */
  if (flag_nc()) goto lab_p28_L_4219;
  a = 0x02;
  goto lab_p28_L_421B;
  lab_p28_L_4219: ;
  a = 0x01;
  lab_p28_L_421B: ;
  link_out(a); /* stub */
  lab_p28_L_421D: ;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_4234;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_4234;
  set_de((uint16_t)(de() - 1));
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_421D;
  lab_p28_L_4231: ;
  p00_L_2565();
  return;
  lab_p28_L_4234: ;
  a = 0x00;
  link_out(a); /* stub */
  set_de(0xFFFF);
  lab_p28_L_423B: ;
  set_de((uint16_t)(de() - 1));
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_4231;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p28_L_423B;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_420D;
  return;
}

/* flash page 28 cpu 0x424C (offset 0x024C) */
void p28_L_424C(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x8688, a);
  mem_write8(0x8689, a);
  set_hl(0x867D);
  goto lab_p28_L_4278;
  lab_p28_L_4278: ;
  mem_write16(0x84DB, hl());
  set_hl(mem_read16(0x8676));
  set_de(0x000F);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) { p28_L_4289(); return; }
  p00_L_255D();
  return;
}

/* flash page 28 cpu 0x4258 (offset 0x0258) */
void p28_L_4258(void) {
  goto lab_p28_L_4258;
  lab_p28_L_4231: ;
  p00_L_2565();
  return;
  lab_p28_L_4258: ;
  mem_write16(0x84DB, de());
  cpu_push_bc();
  p28_L_432F();
  cpu_pop_bc();
  set_hl(0x8670);
  a = mem_read8(0x8675);
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p28_L_4231;
  set_hl(mem_read16(0x8676));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nz()) goto lab_p28_L_4231;
  p28_L_4289();
  return;
}

/* flash page 28 cpu 0x4275 (offset 0x0275) */
void p28_L_4275(void) {
  set_hl(0x867C);
  mem_write16(0x84DB, hl());
  set_hl(mem_read16(0x8676));
  set_de(0x000F);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) { p28_L_4289(); return; }
  p00_L_255D();
  return;
}

/* flash page 28 cpu 0x4289 (offset 0x0289) */
void p28_L_4289(void) {
  set_bc(mem_read16(0x8676));
  set_de(0x0000);
  mem_write16(0x8678, de());
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_42E6;
  set_hl(0x983A);
  mem_write16(0x9836, hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x9834, a);
  set_hl(mem_read16(0x84DB));
  lab_p28_L_42A5: ;
  p00_L_171E();
  if (flag_nz()) { p00_L_2565(); return; }
  cpu_push_bc();
  p28_L_4436();
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p28_L_42CB;
  cpu_push_hl();
  set_hl(mem_read16(0x9836));
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x9836, hl());
  cpu_pop_hl();
  a = mem_read8(0x9834);
  a = (uint8_t)(a + 1);
  mem_write8(0x9834, a);
  flag_cmp(a, 0x10);
  if (flag_z()) p28_L_6C65();
  goto lab_p28_L_42CD;
  lab_p28_L_42CB: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  lab_p28_L_42CD: ;
  cpu_ex_de_hl();
  b = 0x00;
  set_hl(mem_read16(0x8678));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x8678, hl());
  cpu_ex_de_hl();
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_42A5;
  a = mem_read8(0x9834);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) p28_L_6C65();
  lab_p28_L_42E6: ;
  p28_L_4436();
  cpu_push_af();
  p28_L_4436();
  b = a;
  cpu_pop_af();
  p28_L_64DF();
  p28_L_42F2();
  return;
}

/* flash page 28 cpu 0x42F2 (offset 0x02F2) */
void p28_L_42F2(void) {
  p28_L_430F();
  set_hl(0x0000);
  p28_L_42F8();
  return;
}

/* flash page 28 cpu 0x42F8 (offset 0x02F8) */
void p28_L_42F8(void) {
  mem_write16(0x8676, hl());
  p28_L_6393();
  h = 0x56;
  mem_write16(0x8674, hl());
  p28_L_41BA();
  p28_L_4306();
  return;
}

/* flash page 28 cpu 0x4306 (offset 0x0306) */
void p28_L_4306(void) {
  set_hl(0x868B);
  set_de(0x8674);
  p00_L_1183();
  return;
}

/* flash page 28 cpu 0x430F (offset 0x030F) */
void p28_L_430F(void) {
  goto lab_p28_L_430F;
  lab_p28_L_430C: ;
  p00_L_1183();
  return;
  lab_p28_L_430F: ;
  set_hl(0x8674);
  set_de(0x868B);
  goto lab_p28_L_430C;
}

/* flash page 28 cpu 0x4317 (offset 0x0317) */
void p28_L_4317(void) {
  a = mem_read8(0x8A0B);
  a = a & 0x1E;
  flag_logic(a);
  if (flag_nz()) return;
  p28_L_41AF();
  p28_L_6313();
  a = mem_read8(0x8674);
  flag_cmp(a, 0x73);
  if (flag_z()) goto lab_p28_L_432E;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 3)));
  lab_p28_L_432E: ;
  return;
}

/* flash page 28 cpu 0x432F (offset 0x032F) */
void p28_L_432F(void) {
  p28_L_4436();
  p28_L_4332();
  return;
}

/* flash page 28 cpu 0x4332 (offset 0x0332) */
void p28_L_4332(void) {
  mem_write8(0x8674, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p28_L_433F;
  flag_cmp(a, 0x95);
  p28_L_4380();
  return;
  lab_p28_L_433F: ;
  flag_cmp(a, 0x73);
  if (flag_z()) { p28_L_4380(); return; }
  flag_cmp(a, 0x23);
  if (flag_z()) { p28_L_4380(); return; }
  flag_cmp(a, 0x74);
  if (flag_z()) { p28_L_4380(); return; }
  flag_cmp(a, 0x82);
  if (flag_z()) { p28_L_4380(); return; }
  flag_cmp(a, 0x02);
  if (flag_z()) { p28_L_4380(); return; }
  flag_cmp(a, 0x12);
  if (flag_z()) { p28_L_4380(); return; }
  flag_cmp(a, 0x83);
  if (flag_z()) { p28_L_4380(); return; }
  flag_cmp(a, 0x03);
  if (flag_z()) { p28_L_4380(); return; }
  flag_cmp(a, 0x13);
  if (flag_z()) { p28_L_4380(); return; }
  flag_cmp(a, 0x08);
  if (flag_z()) { p28_L_4380(); return; }
  p28_L_4436();
  mem_write8(0x8675, a);
  flag_cmp(a, 0x68);
  if (flag_z()) goto lab_p28_L_4386;
  flag_cmp(a, 0x47);
  if (flag_z()) goto lab_p28_L_4386;
  flag_cmp(a, 0x74);
  if (flag_z()) goto lab_p28_L_4386;
  flag_cmp(a, 0x2D);
  if (flag_z()) goto lab_p28_L_4386;
  p00_L_2565();
  return;
  lab_p28_L_4386: ;
  p28_L_4436();
  mem_write8(0x8676, a);
  p28_L_4436();
  mem_write8(0x8677, a);
  return;
}

/* flash page 28 cpu 0x4380 (offset 0x0380) */
void p28_L_4380(void) {
  p28_L_4436();
  mem_write8(0x8675, a);
  p28_L_4436();
  mem_write8(0x8676, a);
  p28_L_4436();
  mem_write8(0x8677, a);
  return;
}

/* flash page 28 cpu 0x4393 (offset 0x0393) */
void p28_L_4393(void) {
  p00_L_3117();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 3)));
  p28_L_439A();
  return;
}

/* flash page 28 cpu 0x439A (offset 0x039A) */
void p28_L_439A(void) {
  p28_L_4F79();
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_43AB;
  p28_L_6F37();
  p28_L_6DCD();
  p28_L_443A();
  return;
  lab_p28_L_43AB: ;
  p00_L_171E();
  p00_L_0284();
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p28_L_43AB;
  p28_L_6B25();
  b = 0x08;
  p28_L_44A9();
  p28_L_443A();
  return;
}

/* flash page 28 cpu 0x43C4 (offset 0x03C4) */
void p28_L_43C4(void) {
  p28_L_6B25();
  p28_L_43C7();
  return;
}

/* flash page 28 cpu 0x43C7 (offset 0x03C7) */
void p28_L_43C7(void) {
  /* di */
  mem_write8((uint16_t)(iy + 0x3D), (uint8_t)(mem_read8((uint16_t)(iy + 0x3D)) & ~(1u << 5)));
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_43E2;
  /* di */
  p28_L_6DDC();
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p28_L_43EC;
  a = c;
  flag_cmp(a, 0xE0);
  if (flag_z()) goto lab_p28_L_4410;
  p28_L_442B();
  return;
  lab_p28_L_43E1: ;
  return;
  lab_p28_L_43E2: ;
  b = 0x08;
  p28_L_44A9();
  flag_cmp(a, 0x00);
  if (flag_nz()) { p00_L_255D(); return; }
  lab_p28_L_43EC: ;
  a = c;
  flag_cmp(a, 0xE0);
  if (flag_nz()) goto lab_p28_L_43E1;
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_4404;
  a = hw_in(0x09);
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p28_L_4410;
  a = a & 0x19;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_4428;
  p28_L_6F2A();
  lab_p28_L_4404: ;
  p28_L_6E7E();
  if (flag_c()) { p28_L_4476(); return; }
  if (flag_z()) goto lab_p28_L_440F;
  p28_L_4476();
  return;
  lab_p28_L_440F: ;
  /* nop */
  lab_p28_L_4410: ;
  p28_L_6EE6();
  if (flag_nz()) goto lab_p28_L_442A;
  mem_write8((uint16_t)(iy + 0x3D), (uint8_t)(mem_read8((uint16_t)(iy + 0x3D)) | (1u << 5)));
  b = a;
  a = mem_read8(0x9CAF);
  a = a | a;
  flag_logic(a);
  a = b;
  if (flag_nz()) return;
  p00_L_3051();
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 0)));
  return;
  lab_p28_L_4428: ;
  a = c;
  return;
  lab_p28_L_442A: ;
  /* nop */
  p28_L_442B();
  return;
}

/* flash page 28 cpu 0x442B (offset 0x042B) */
void p28_L_442B(void) {
  a = mem_read8((uint16_t)(iy + 0x3D));
  a = a & 0xF0;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x3D), a);
  p00_L_255D();
  return;
}

/* flash page 28 cpu 0x4436 (offset 0x0436) */
void p28_L_4436(void) {
  /* di */
  p28_L_447D();
  p28_L_443A();
  return;
}

/* flash page 28 cpu 0x443A (offset 0x043A) */
void p28_L_443A(void) {
  p28_L_4441();
  if (flag_c()) return;
  if (flag_nz()) return;
  if (flag_z()) { p28_L_4436(); return; }
  p28_L_4441();
  return;
}

/* flash page 28 cpu 0x4441 (offset 0x0441) */
void p28_L_4441(void) {
  flag_cmp(a, 0x01);
  a = c;
  if (flag_nz()) goto lab_p28_L_444D;
  flag_cmp(a, 0xE0);
  if (flag_nz()) { p00_L_255D(); return; }
  goto lab_p28_L_446D;
  lab_p28_L_444D: ;
  flag_cmp(a, 0xE0);
  if (flag_nz()) return;
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_4466;
  a = hw_in(0x09);
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p28_L_446D;
  a = a & 0x19;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_4473;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  lab_p28_L_4466: ;
  p28_L_6E90();
  if (flag_c()) goto lab_p28_L_4475;
  if (flag_nz()) { p28_L_4476(); return; }
  lab_p28_L_446D: ;
  p28_L_6EE6();
  /* nop */
  a = 0;
  flag_logic(a);
  return;
  lab_p28_L_4473: ;
  a = c;
  return;
  lab_p28_L_4475: ;
  /* nop */
  p28_L_4476();
  return;
}

/* flash page 28 cpu 0x4476 (offset 0x0476) */
void p28_L_4476(void) {
  p28_L_6F33();
  /* nop */
  a = c;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x447D (offset 0x047D) */
void p28_L_447D(void) {
  b = 0x08;
  p00_L_24A9();
  if (flag_z()) { p28_L_6DDC(); return; }
  set_de(0xFFFF);
  goto lab_p28_L_44A0;
  lab_p28_L_448A: ;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_44F8;
  flag_cmp(a, 0x03);
  if (flag_nz()) { p28_L_44A9(); return; }
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_44F8;
  flag_cmp(a, 0x03);
  if (flag_nz()) { p28_L_44A9(); return; }
  lab_p28_L_44A0: ;
  set_de((uint16_t)(de() - 1));
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_448A;
  p00_L_255D();
  return;
  lab_p28_L_44F8: ;
  p28_L_442B();
  return;
}

/* flash page 28 cpu 0x44A9 (offset 0x04A9) */
void p28_L_44A9(void) {
  goto lab_p28_L_44A9;
  lab_p28_L_447F: ;
  p00_L_24A9();
  if (flag_z()) { p28_L_6DDC(); return; }
  set_de(0xFFFF);
  goto lab_p28_L_44A0;
  lab_p28_L_448A: ;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_44F8;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p28_L_44A9;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_44F8;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p28_L_44A9;
  lab_p28_L_44A0: ;
  set_de((uint16_t)(de() - 1));
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_448A;
  p00_L_255D();
  return;
  lab_p28_L_44A9: ;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p28_L_44DD;
  a = 0x01;
  link_out(a); /* stub */
  /* rr c */
  set_de(0xFFFF);
  lab_p28_L_44B6: ;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p28_L_44C7;
  set_de((uint16_t)(de() - 1));
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_44B6;
  goto lab_p28_L_44F5;
  lab_p28_L_44C7: ;
  a = 0x00;
  link_out(a); /* stub */
  d = 0x04;
  lab_p28_L_44CD: ;
  d = (uint8_t)(d - 1);
  if (flag_z()) goto lab_p28_L_44D8;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p28_L_44CD;
  lab_p28_L_44D8: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_447F;
  a = 0x00;
  return;
  lab_p28_L_44DD: ;
  a = 0x02;
  link_out(a); /* stub */
  /* rr c */
  set_de(0xFFFF);
  lab_p28_L_44E6: ;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p28_L_44C7;
  set_de((uint16_t)(de() - 1));
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_44E6;
  lab_p28_L_44F5: ;
  p00_L_2565();
  return;
  lab_p28_L_44F8: ;
  p28_L_442B();
  return;
}

/* flash page 28 cpu 0x44FB (offset 0x04FB) */
void p28_L_44FB(void) {
  goto lab_p28_L_44FB;
  lab_p28_L_44F5: ;
  p00_L_2565();
  return;
  lab_p28_L_44FB: ;
  p28_L_6F33();
  set_hl(0x62CF);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  p28_L_6439();
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 6)));
  a = 0x10;
  mem_write8(0x8672, a);
  p28_L_5A52();
  p00_L_3D17();
  set_hl(0x6088);
  a = 0x34;
  p28_L_658D();
  p28_L_60D7();
  a = 0;
  flag_logic(a);
  mem_write8(0x8670, a);
  p28_L_6313();
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p28_L_456A;
  flag_cmp(a, 0x68);
  if (flag_nz()) goto lab_p28_L_44F5;
  p28_L_42F2();
  p00_L_25C8();
  goto lab_p28_L_44FB;
  lab_p28_L_456A: ;
  a = mem_read8(0x8674);
  flag_cmp(a, 0x83);
  if (flag_z()) goto lab_p28_L_458B;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p28_L_458B;
  flag_cmp(a, 0x13);
  if (flag_z()) goto lab_p28_L_458B;
  flag_cmp(a, 0x82);
  if (flag_z()) goto lab_p28_L_4585;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p28_L_4585;
  flag_cmp(a, 0x12);
  if (flag_nz()) goto lab_p28_L_458F;
  lab_p28_L_4585: ;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 2)));
  goto lab_p28_L_458F;
  lab_p28_L_458B: ;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 3)));
  lab_p28_L_458F: ;
  p28_L_424C();
  p28_L_6A30();
  if (flag_nc()) goto lab_p28_L_464E;
  p28_L_4557();
  flag_cmp(a, 0x13);
  if (flag_z()) goto lab_p28_L_4674;
  a = mem_read8(0x867F);
  flag_cmp(a, 0x24);
  if (flag_nz()) goto lab_p28_L_45B3;
  a = mem_read8(0x8674);
  flag_cmp(a, 0x73);
  if (flag_nz()) { p00_L_255F(); return; }
  p28_L_5173();
  return;
  lab_p28_L_45B3: ;
  flag_cmp(a, 0x23);
  if (flag_nz()) goto lab_p28_L_4620;
  a = 0x38;
  p28_L_5B03();
  a = 0;
  flag_logic(a);
  mem_write8(0x8444, a);
  mem_write8(0x8446, a);
  p28_L_4F79();
  lab_p28_L_45C6: ;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  /* ei */
  p00_L_3F21();
  mem_write8(0x8444, a);
  p00_L_3F39();
  /* di */
  if (flag_c()) goto lab_p28_L_45C6;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  flag_cmp(a, 0x1A);
  if (flag_nz()) goto lab_p28_L_45E2;
  p28_L_5852();
  return;
  lab_p28_L_45E2: ;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p28_L_45EB;
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p28_L_45C6;
  lab_p28_L_45EB: ;
  p28_L_6F33();
  p28_L_626B();
  p00_L_25C8();
  set_hl(0x62CF);
  p00_L_25A2();
  p28_L_430F();
  a = 0x73;
  mem_write8(0x8674, a);
  a = 0x01;
  mem_write8(0x867E, a);
  set_bc(0x0000);
  mem_write16(0x8676, bc());
  set_de(0x0005);
  p28_L_405D();
  p28_L_4306();
  p00_L_25C8();
  p28_L_4F79();
  p28_L_4E18();
  return;
  lab_p28_L_4620: ;
  flag_cmp(a, 0x25);
  if (flag_nz()) goto lab_p28_L_4630;
  a = mem_read8(0x8674);
  flag_cmp(a, 0x73);
  if (flag_nz()) { p00_L_255F(); return; }
  p28_L_5157();
  return;
  lab_p28_L_4630: ;
  flag_cmp(a, 0x28);
  if (flag_nz()) goto lab_p28_L_4646;
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) | (1u << 6)));
  p28_L_5580();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 6)));
  goto lab_p28_L_44FB;
  lab_p28_L_4646: ;
  flag_cmp(a, 0x22);
  if (flag_z()) { p00_L_255F(); return; }
  p28_L_4759();
  return;
  lab_p28_L_464E: ;
  set_hl(0x867F);
  p00_rst20();
  p00_L_25C8();
  b = 0x41;
  cpu_push_bc();
  p28_L_4F79();
  p00_L_10DD();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p28_L_466D;
  a = 0x04;
  p28_L_4068();
  p00_L_2565();
  return;
  lab_p28_L_466D: ;
  a = 0x03;
  cpu_pop_bc();
  p00_L_2E29();
  return;
  lab_p28_L_4674: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 2)) == 0);
  if (flag_nz()) { p00_L_2565(); return; }
  p28_L_6444();
  if (flag_nz()) { p00_L_2565(); return; }
  a = mem_read8(0x8674);
  flag_cmp(a, 0x73);
  if (flag_z()) goto lab_p28_L_468D;
  flag_cmp(a, 0x23);
  if (flag_nz()) { p00_L_2565(); return; }
  lab_p28_L_468D: ;
  p00_L_25C8();
  p28_L_4F79();
  set_hl(mem_read16(0x8684));
  mem_write16(0x8494, hl());
  set_hl(mem_read16(0x867D));
  mem_write16(0x848E, hl());
  set_hl(mem_read16(0x8680));
  mem_write16(0x8490, hl());
  set_de(mem_read16(0x8682));
  mem_write16(0x8492, de());
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  p00_L_2E2F();
  set_hl(0xFE67);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  set_de(0x9D95);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_ex_de_hl();
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p28_L_46C7;
  if (flag_nc()) goto lab_p28_L_46DC;
  lab_p28_L_46C7: ;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p28_L_46FB;
  a = 0x13;
  mem_write8(0x8672, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  a = 0x35;
  p28_L_5B03();
  return;
  lab_p28_L_46DC: ;
  mem_write16(0x867D, hl());
  set_hl(0x62CF);
  p00_L_25A2();
  a = 0x03;
  set_de(0x0003);
  p28_L_406B();
  p00_L_25C8();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p28_L_44FB;
  p00_L_2565();
  return;
  lab_p28_L_46FB: ;
  set_hl(0x62CF);
  p00_L_25A2();
  goto lab_p28_L_470E;
  lab_p28_L_470E: ;
  p28_L_4190();
  set_hl(0x8670);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 1)));
  set_bc(mem_read16(0x848E));
  set_de(0x89F0);
  p28_L_4258();
  set_bc(mem_read16(0x8490));
  set_de(0x9D95);
  p28_L_4258();
  set_hl(0xFE66);
  set_bc(mem_read16(0x8492));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_ex_de_hl();
  set_de((uint16_t)(de() + 1));
  p28_L_4258();
  set_hl(mem_read16(0x8494));
  set_de(0x9D95);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p28_L_474C;
  b = h;
  c = l;
  set_de(0x0001);
  p00_L_1FC0();
  lab_p28_L_474C: ;
  p00_L_2EEF();
  p00_L_2D45();
  a = 0;
  flag_logic(a);
  mem_write8(0x9C87, a);
  p28_L_4C43();
  return;
}

/* flash page 28 cpu 0x4557 (offset 0x0557) */
void p28_L_4557(void) {
  a = mem_read8(0x867F);
  a = a & 0x1F;
  flag_logic(a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 2)) == 0);
  if (flag_z()) return;
  flag_cmp(a, 0x0B);
  if (flag_c()) return;
  a = (uint8_t)(a + 0x04);
  mem_write8(0x867F, a);
  return;
}

/* flash page 28 cpu 0x472C (offset 0x072C) */
void p28_L_472C(void) {
  flag_cmp(a, 0xED);
  c = e;
  a = (uint8_t)(a - d);
  a = (uint8_t)(a + h);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_ex_de_hl();
  set_de((uint16_t)(de() + 1));
  p28_L_4258();
  set_hl(mem_read16(0x8494));
  set_de(0x9D95);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p28_L_474C;
  b = h;
  c = l;
  set_de(0x0001);
  p00_L_1FC0();
  lab_p28_L_474C: ;
  p00_L_2EEF();
  p00_L_2D45();
  a = 0;
  flag_logic(a);
  mem_write8(0x9C87, a);
  p28_L_4C43();
  return;
}

/* flash page 28 cpu 0x4759 (offset 0x0759) */
void p28_L_4759(void) {
  goto lab_p28_L_4759;
  lab_p28_L_46F8: ;
  p00_L_2565();
  return;
  lab_p28_L_4759: ;
  flag_cmp(a, 0x12);
  if (flag_z()) goto lab_p28_L_46F8;
  p00_L_25C8();
  p28_L_6B25();
  a = 0x11;
  set_hl(0x8672);
  cpu_cp_hl();
  if (flag_z()) { p28_L_478C(); return; }
  mem_write8(hl(), a);
  set_hl(0xFF01);
  mem_write16(0x85D1, hl());
  p00_L_3D17();
  set_hl(0x6091);
  a = 0x35;
  p28_L_658D();
  p28_L_60D7();
  a = 0x01;
  mem_write8(0x97A5, a);
  p00_L_3D2F();
  a = 0;
  flag_logic(a);
  mem_write8(0x8670, a);
  p28_L_478C();
  return;
}

/* flash page 28 cpu 0x478C (offset 0x078C) */
void p28_L_478C(void) {
  set_hl(0x867F);
  p00_rst20();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_1130();
  p00_L_1037();
  flag_cmp(a, 0x15);
  if (flag_nc()) goto lab_p28_L_47D3;
  flag_cmp(a, 0x0F);
  if (flag_c()) goto lab_p28_L_47D3;
  p00_L_0087();
  p00_L_1037();
  p28_L_6E29();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  a = (uint8_t)(a - 0x0F);
  p00_L_2DF9();
  mem_write16(0x8483, hl());
  cpu_push_hl();
  set_hl(0x627C);
  p00_L_25A2();
  p00_L_10DD();
  set_bc(mem_read16(0x867D));
  cpu_push_bc();
  set_de(mem_read16(0x8483));
  p28_L_49C9();
  return;
  lab_p28_L_47D3: ;
  mem_write8(0x8483, a);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_47E4;
  set_hl(mem_read16(0x867D));
  set_de(0x0009);
  cpu_sbc_hl_de();
  if (flag_nz()) { p00_L_24DD(); return; }
  lab_p28_L_47E4: ;
  p28_L_47CB();
  if (flag_z()) goto lab_p28_L_47FB;
  p00_L_0AFB();
  if (flag_z()) { p28_L_5922(); return; }
  set_hl(mem_read16(0x867D));
  mem_write16(0x83F7, hl());
  set_hl(0x0004);
  mem_write16(0x867D, hl());
  lab_p28_L_47FB: ;
  p00_L_19ED();
  if (flag_c()) { p28_L_4956(); return; }
  a = mem_read8(0x8483);
  mem_write8(0x8478, a);
  set_hl(mem_read16(0x867D));
  mem_write16(0x848E, hl());
  p00_L_21E5();
  p00_L_10DD();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_z()) { p28_L_4906(); return; }
  p28_L_4F79();
  p00_L_19ED();
  p28_L_4C6C();
  if (flag_z()) { p28_L_4906(); return; }
  p00_L_2E0B();
  return;
}

/* flash page 28 cpu 0x47CB (offset 0x07CB) */
void p28_L_47CB(void) {
  cpu_push_hl();
  set_hl(0x8689);
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  cpu_pop_hl();
  return;
}

/* flash page 28 cpu 0x482B (offset 0x082B) */
void p28_L_482B(void) {
  a = 0x02;
  b = 0x37;
  p00_L_2E17();
  a = mem_read8(0x844B);
  cpu_push_af();
  a = 0x07;
  mem_write8(0x844B, a);
  a = 0x01;
  mem_write8(0x844C, a);
  set_hl(0x8479);
  p00_L_3C87();
  a = 0x14;
  mem_write8(0x85D9, a);
  mem_write8(0x85D0, a);
  p00_L_2DF3();
  cpu_pop_af();
  mem_write8(0x844B, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x8444, a);
  mem_write8(0x8446, a);
  p28_L_4F79();
  p28_L_485F();
  return;
}

/* flash page 28 cpu 0x485F (offset 0x085F) */
void p28_L_485F(void) {
  lab_p28_L_485F: ;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  /* ei */
  p00_L_3F21();
  mem_write8(0x8444, a);
  p00_L_3F39();
  /* di */
  if (flag_c()) goto lab_p28_L_485F;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  flag_cmp(a, 0x19);
  if (flag_nz()) goto lab_p28_L_489E;
  p28_L_626B();
  set_hl(0x62CF);
  p00_L_25A2();
  p28_L_430F();
  a = 0x73;
  mem_write8(0x8674, a);
  a = 0x92;
  mem_write8(0x8675, a);
  p28_L_41BA();
  p28_L_4306();
  p00_L_25C8();
  p28_L_6B25();
  a = 0x01;
  goto lab_p28_L_48AF;
  lab_p28_L_489E: ;
  flag_cmp(a, 0x18);
  if (flag_nz()) goto lab_p28_L_48B3;
  p28_L_626B();
  a = mem_read8(0x8433);
  p00_L_2E7D();
  p28_L_6B25();
  a = 0;
  flag_logic(a);
  lab_p28_L_48AF: ;
  mem_write8(0x8432, a);
  return;
  lab_p28_L_48B3: ;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p28_L_48BB;
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p28_L_48EB;
  lab_p28_L_48BB: ;
  p28_L_626B();
  set_hl(0x62CF);
  p00_L_25A2();
  p28_L_430F();
  a = 0x73;
  mem_write8(0x8674, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x867E, a);
  set_bc(0x0000);
  mem_write16(0x8676, bc());
  set_de(0x0005);
  p28_L_405D();
  p28_L_4306();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  a = 0x02;
  goto lab_p28_L_48AF;
  lab_p28_L_48EB: ;
  goto lab_p28_L_485F;
}

/* flash page 28 cpu 0x48EE (offset 0x08EE) */
void p28_L_48EE(void) {
  p28_L_6320();
  a = mem_read8(0x8675);
  flag_cmp(a, 0x92);
  if (flag_nz()) goto lab_p28_L_48FC;
  a = 0x02;
  goto lab_p28_L_4902;
  lab_p28_L_48FC: ;
  flag_cmp(a, 0x56);
  if (flag_nz()) { p00_L_255F(); return; }
  a = 0;
  flag_logic(a);
  lab_p28_L_4902: ;
  mem_write8(0x8432, a);
  return;
}

/* flash page 28 cpu 0x4906 (offset 0x0906) */
void p28_L_4906(void) {
  p00_L_22FC();
  p00_L_10DD();
  p00_L_19ED();
  cpu_push_af();
  p00_L_1F55();
  if (flag_nz()) goto lab_p28_L_494C;
  cpu_pop_af();
  cpu_ex_de_hl();
  p00_L_210A();
  set_hl(mem_read16(0x848E));
  mem_write16(0x867D, hl());
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p28_L_4930;
  if (flag_z()) goto lab_p28_L_4930;
  p00_L_1B33();
  if (flag_nc()) goto lab_p28_L_4930;
  p00_L_21A7();
  p28_L_4976();
  return;
  lab_p28_L_4930: ;
  p00_L_16C4();
  if (flag_nz()) goto lab_p28_L_4940;
  p00_L_10DD();
  /* di */
  p00_L_3E5B();
  /* ei */
  p00_L_1135();
  lab_p28_L_4940: ;
  p00_L_16F4();
  p00_L_1F2C();
  p00_L_219B();
  a = 0;
  flag_logic(a);
  goto lab_p28_L_4959;
  lab_p28_L_494C: ;
  cpu_pop_af();
  p00_L_1F2C();
  p00_L_219B();
  p00_L_1135();
  p28_L_4956();
  return;
  lab_p28_L_4959: ;
  set_hl(mem_read16(0x867D));
  goto lab_p28_L_495E;
  lab_p28_L_495E: ;
  p00_L_17B0();
  if (flag_nz()) goto lab_p28_L_4968;
  p00_L_19C5();
  goto lab_p28_L_4971;
  lab_p28_L_4968: ;
  p00_L_182A();
  if (flag_nz()) goto lab_p28_L_4971;
  p00_L_19C5();
  a = (uint8_t)(a + 1);
  lab_p28_L_4971: ;
  p00_L_1B90();
  if (flag_nc()) goto lab_p28_L_498E;
  p28_L_4976();
  return;
  lab_p28_L_498E: ;
  mem_write16(0x8483, bc());
  cpu_push_bc();
  set_hl(0x627C);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  set_bc(mem_read16(0x8483));
  cpu_push_bc();
  p00_L_17B0();
  if (flag_z()) goto lab_p28_L_49B3;
  p00_L_182A();
  if (flag_nz()) goto lab_p28_L_49BD;
  cpu_push_bc();
  p00_L_19C5();
  a = (uint8_t)(a + 1);
  goto lab_p28_L_49B7;
  lab_p28_L_49B3: ;
  cpu_push_bc();
  p00_L_19C5();
  lab_p28_L_49B7: ;
  cpu_pop_bc();
  p00_L_1B9A();
  goto lab_p28_L_49C0;
  lab_p28_L_49BD: ;
  p00_L_1C04();
  lab_p28_L_49C0: ;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_z()) { p28_L_49C9(); return; }
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  p28_L_49C9();
  return;
}

/* flash page 28 cpu 0x4956 (offset 0x0956) */
void p28_L_4956(void) {
  p00_L_18AE();
  set_hl(mem_read16(0x867D));
  goto lab_p28_L_495E;
  lab_p28_L_495E: ;
  p00_L_17B0();
  if (flag_nz()) goto lab_p28_L_4968;
  p00_L_19C5();
  goto lab_p28_L_4971;
  lab_p28_L_4968: ;
  p00_L_182A();
  if (flag_nz()) goto lab_p28_L_4971;
  p00_L_19C5();
  a = (uint8_t)(a + 1);
  lab_p28_L_4971: ;
  p00_L_1B90();
  if (flag_nc()) goto lab_p28_L_498E;
  p28_L_4976();
  return;
  lab_p28_L_498E: ;
  mem_write16(0x8483, bc());
  cpu_push_bc();
  set_hl(0x627C);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  set_bc(mem_read16(0x8483));
  cpu_push_bc();
  p00_L_17B0();
  if (flag_z()) goto lab_p28_L_49B3;
  p00_L_182A();
  if (flag_nz()) goto lab_p28_L_49BD;
  cpu_push_bc();
  p00_L_19C5();
  a = (uint8_t)(a + 1);
  goto lab_p28_L_49B7;
  lab_p28_L_49B3: ;
  cpu_push_bc();
  p00_L_19C5();
  lab_p28_L_49B7: ;
  cpu_pop_bc();
  p00_L_1B9A();
  goto lab_p28_L_49C0;
  lab_p28_L_49BD: ;
  p00_L_1C04();
  lab_p28_L_49C0: ;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_z()) { p28_L_49C9(); return; }
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  p28_L_49C9();
  return;
}

/* flash page 28 cpu 0x4976 (offset 0x0976) */
void p28_L_4976(void) {
  p28_L_4F79();
  p00_L_10DD();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  a = 0x03;
  if (flag_z()) p28_L_4068();
  a = 0x03;
  b = 0x34;
  p00_L_2E17();
  return;
}

/* flash page 28 cpu 0x49C9 (offset 0x09C9) */
void p28_L_49C9(void) {
  a = mem_read8(0x8688);
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), a);
  cpu_push_de();
  p00_L_1135();
  p28_L_61F5();
  set_hl(0x8670);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 1)));
  cpu_pop_de();
  cpu_pop_bc();
  p28_L_47CB();
  if (flag_z()) goto lab_p28_L_4A2F;
  /* di */
  set_hl(0x62F6);
  p00_L_25A2();
  p00_L_19ED();
  mem_write16(0x981C, hl());
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p28_L_4A00;
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  p00_L_321F();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  lab_p28_L_4A00: ;
  p28_L_7145();
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) | (1u << 3)));
  p00_L_2EAD();
  cpu_pop_af();
  set_hl(mem_read16(0x83F1));
  mem_write8(hl(), a);
  p00_L_25C8();
  set_hl(mem_read16(0x83F3));
  set_de(0x0004);
  p00_L_1FB8();
  p28_L_4190();
  set_de(mem_read16(0x83FB));
  set_bc(mem_read16(0x83F7));
  p28_L_4258();
  p28_L_7119();
  goto lab_p28_L_4A39;
  lab_p28_L_4A2F: ;
  cpu_push_bc();
  cpu_push_de();
  p28_L_4190();
  cpu_pop_de();
  cpu_pop_bc();
  p28_L_4258();
  lab_p28_L_4A39: ;
  p28_L_61FE();
  p00_L_18AE();
  if (flag_nc()) goto lab_p28_L_4A5A;
  p00_rst10();
  mem_write8(hl(), 0x03);
  cpu_push_af();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p28_L_4A4E;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  lab_p28_L_4A4E: ;
  cpu_pop_af();
  mem_write16(0x981C, hl());
  mem_write16(0x84DD, de());
  h = a;
  p00_L_380D();
  lab_p28_L_4A5A: ;
  set_hl(0x8670);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 1)));
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_nz()) p00_L_2DE7();
  p00_L_25C8();
  cpu_pop_bc();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_z()) return;
  p28_L_4A71();
  return;
}

/* flash page 28 cpu 0x4A71 (offset 0x0A71) */
void p28_L_4A71(void) {
  goto lab_p28_L_4A71;
  lab_p28_L_453D: ;
  p28_L_42F2();
  p00_L_25C8();
  set_hl(0x62CF);
  p00_L_25A2();
  p28_L_6313();
  flag_cmp(a, 0x06);
  if (flag_nz()) { p00_L_2565(); return; }
  p28_L_424C();
  p28_L_5173();
  return;
  lab_p28_L_464E: ;
  set_hl(0x867F);
  p00_rst20();
  p00_L_25C8();
  b = 0x41;
  cpu_push_bc();
  p28_L_4F79();
  p00_L_10DD();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p28_L_466D;
  a = 0x04;
  p28_L_4068();
  p00_L_2565();
  return;
  lab_p28_L_466D: ;
  a = 0x03;
  cpu_pop_bc();
  p00_L_2E29();
  return;
  lab_p28_L_4A71: ;
  set_hl(0x62CF);
  p00_L_25A2();
  p28_L_6313();
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p28_L_4A8D;
  p28_L_424C();
  p28_L_6A30();
  if (flag_nc()) goto lab_p28_L_464E;
  p28_L_4557();
  p28_L_4759();
  return;
  lab_p28_L_4A8D: ;
  flag_cmp(a, 0x68);
  if (flag_z()) goto lab_p28_L_453D;
  flag_cmp(a, 0x92);
  if (flag_nz()) goto lab_p28_L_4B5F;
  p28_L_42F2();
  p00_L_25C8();
  p28_L_4A9D();
  return;
  lab_p28_L_4B5F: ;
  p00_L_2565();
  return;
}

/* flash page 28 cpu 0x4A9D (offset 0x0A9D) */
void p28_L_4A9D(void) {
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) & ~(1u << 2)));
  p28_L_4AA1();
  return;
}

/* flash page 28 cpu 0x4AA1 (offset 0x0AA1) */
void p28_L_4AA1(void) {
  p28_L_4F79();
  a = mem_read8(0x8670);
  flag_set_z((a & (1u << 4)) == 0);
  if (flag_z()) { p28_L_4E18(); return; }
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) goto lab_p28_L_4E3D;
  a = 0x02;
  mem_write8(0x8672, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x8670, a);
  p28_L_61FE();
  a = mem_read8(0x844B);
  b = a;
  b = (uint8_t)(b - 1);
  p00_L_1037();
  flag_cmp(a, 0x0F);
  if (flag_c()) goto lab_p28_L_4ACD;
  flag_cmp(a, 0x14);
  if (flag_c()) goto lab_p28_L_4ADA;
  lab_p28_L_4ACD: ;
  set_hl(0x8479);
  p00_L_17B0();
  a = 0xFE;
  if (flag_z()) goto lab_p28_L_4AD8;
  set_hl((uint16_t)(hl() + 1));
  lab_p28_L_4AD8: ;
  mem_write8(hl(), a);
  b = (uint8_t)(b + 1);
  lab_p28_L_4ADA: ;
  cpu_push_bc();
  lab_p28_L_4ADB: ;
  p00_L_2DDB();
  if (flag_nc()) goto lab_p28_L_4AE6;
  cpu_pop_bc();
  p28_L_61FE();
  goto lab_p28_L_4AF1;
  lab_p28_L_4AE6: ;
  p28_L_4B12();
  if (flag_z()) goto lab_p28_L_4ADB;
  p28_L_6215();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_4ADA;
  lab_p28_L_4AF1: ;
  p00_L_3E8B();
  p00_L_3D2F();
  goto lab_p28_L_4AFC;
  lab_p28_L_4AF9: ;
  p00_L_3CDB();
  lab_p28_L_4AFC: ;
  p28_L_6215();
  p00_L_2DED();
  p28_L_61FE();
  lab_p28_L_4B05: ;
  p00_L_2DD5();
  if (flag_c()) goto lab_p28_L_4E3D;
  p28_L_4B12();
  if (flag_z()) goto lab_p28_L_4B05;
  goto lab_p28_L_4AF9;
  lab_p28_L_4E3D: ;
  p28_L_4F79();
  a = 0x02;
  mem_write8(0x8672, a);
  p28_L_4E1F();
  p28_L_6259();
  return;
}

/* flash page 28 cpu 0x4B12 (offset 0x0B12) */
void p28_L_4B12(void) {
  b = a;
  p00_L_1037();
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p28_L_4B22;
  p28_L_4B1A();
  return;
  lab_p28_L_4B22: ;
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  return;
}

/* flash page 28 cpu 0x4B1A (offset 0x0B1A) */
void p28_L_4B1A(void) {
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_4B22;
  a = b;
  /* and (hl) */
  return;
  lab_p28_L_4B22: ;
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  return;
}

/* flash page 28 cpu 0x4B25 (offset 0x0B25) */
void p28_L_4B25(void) {
  b = a;
  p00_L_1037();
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p28_L_4B36;
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_4B36;
  a = b;
  /* xor (hl) */
  mem_write8(hl(), a);
  return;
  lab_p28_L_4B36: ;
  a = mem_read8(hl());
  a = a ^ 0x80;
  flag_logic(a);
  mem_write8(hl(), a);
  return;
}

/* flash page 28 cpu 0x4B3B (offset 0x0B3B) */
void p28_L_4B3B(void) {
  b = a;
  p00_L_1037();
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p28_L_4B4C;
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_4B4C;
  a = b;
  /* xor (hl) */
  mem_write8(hl(), a);
  return;
  lab_p28_L_4B4C: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  return;
}

/* flash page 28 cpu 0x4B62 (offset 0x0B62) */
void p28_L_4B62(void) {
  goto lab_p28_L_4B62;
  lab_p28_L_4B5F: ;
  p00_L_2565();
  return;
  lab_p28_L_4B62: ;
  set_hl(0x62CF);
  p00_L_25A2();
  p28_L_6444();
  if (flag_nz()) { p00_L_2565(); return; }
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  a = 0x13;
  mem_write8(0x867F, a);
  set_hl(0x13A5);
  mem_write16(0x867D, hl());
  set_hl(mem_read16(0x9824));
  set_de(0x9D95);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  mem_write16(0x8680, hl());
  mem_write16(0x848E, hl());
  set_hl(0xFE66);
  set_de(mem_read16(0x9828));
  cpu_sbc_hl_de();
  mem_write16(0x8682, hl());
  mem_write16(0x8490, hl());
  set_hl(0x9D95);
  mem_write16(0x8684, hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x8686, a);
  mem_write8(0x8687, a);
  p28_L_6FEA();
  mem_write8(0x8688, a);
  set_hl(0x000C);
  p28_L_404A();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p28_L_4BC0;
  p28_L_6320();
  goto lab_p28_L_4BC3;
  lab_p28_L_4BC0: ;
  p28_L_6313();
  lab_p28_L_4BC3: ;
  flag_cmp(a, 0x09);
  if (flag_z()) goto lab_p28_L_4C1D;
  flag_cmp(a, 0x36);
  if (flag_nz()) goto lab_p28_L_4B5F;
  p28_L_4275();
  p00_L_25C8();
  p28_L_4F79();
  a = mem_read8(0x867C);
  flag_cmp(a, 0x01);
  if (flag_z()) { p28_L_5ACD(); return; }
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p28_L_4BEF;
  set_hl(0x62CF);
  p00_L_25A2();
  p28_L_418C();
  p00_L_25C8();
  p28_L_5ACD();
  return;
  lab_p28_L_4BEF: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) { p00_L_255D(); return; }
  a = 0x04;
  b = 0x36;
  p00_L_2E17();
  set_bc(0x000C);
  set_de(0x0003);
  set_hl(0x609C);
  a = 0x36;
  p28_L_658D();
  set_bc(0x0015);
  p28_L_60ED();
  set_hl(0x0703);
  mem_write16(0x844B, hl());
  set_hl(mem_read16(0x867D));
  p00_L_3C7B();
  /* ei */
  return;
  lab_p28_L_4C1D: ;
  p28_L_42F2();
  a = 0x02;
  mem_write8(0x8670, a);
  set_hl(0x89F0);
  set_de(0x13A5);
  p28_L_40C5();
  set_hl(0x9D95);
  set_de(mem_read16(0x848E));
  p28_L_40C5();
  set_hl(mem_read16(0x9828));
  set_hl((uint16_t)(hl() + 1));
  set_de(mem_read16(0x8490));
  p28_L_40C5();
  p28_L_4C43();
  return;
}

/* flash page 28 cpu 0x4C43 (offset 0x0C43) */
void p28_L_4C43(void) {
  p00_L_25C8();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x0A);
  if (flag_z()) return;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_z()) { p00_L_2565(); return; }
  p28_L_4F79();
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  p00_L_3E8B();
  p00_L_3D2F();
  set_hl(0x26DB);
  a = 0x3C;
  p28_L_6586();
  p28_L_4E18();
  return;
}

/* flash page 28 cpu 0x4C6C (offset 0x0C6C) */
void p28_L_4C6C(void) {
  p00_L_1037();
  p00_L_1857();
  if (flag_nz()) return;
  a = 0x03;
  mem_write8(0x8478, a);
  p28_L_4C78();
  return;
}

/* flash page 28 cpu 0x4C78 (offset 0x0C78) */
void p28_L_4C78(void) {
  cpu_push_hl();
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  d = mem_read8(hl());
  cpu_ex_de_hl();
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  /* or (hl) */
  cpu_pop_hl();
  return;
}

/* flash page 28 cpu 0x4CD1 (offset 0x0CD1) */
void p28_L_4CD1(void) {
  lab_p28_L_4CD1: ;
  p00_L_2DD5();
  if (flag_nc()) goto lab_p28_L_4CF7;
  lab_p28_L_4CD6: ;
  set_hl(0x8670);
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_z()) { p28_L_4E0E(); return; }
  lab_p28_L_4CDE: ;
  a = 0x14;
  mem_write8(0x85D9, a);
  set_hl(0x62CF);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  a = 0;
  flag_logic(a);
  mem_write8(0x8670, a);
  p00_L_3CDB();
  p28_L_5E00();
  return;
  lab_p28_L_4CF7: ;
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_4D14;
  cpu_push_af();
  p00_L_1037();
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p28_L_4D13;
  cpu_pop_af();
  set_hl(0x8697);
  b = 0x0E;
  a = 0;
  flag_logic(a);
  lab_p28_L_4D0B: ;
  cpu_cp_hl();
  if (flag_nz()) goto lab_p28_L_4CDE;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_4D0B;
  goto lab_p28_L_4CD6;
  lab_p28_L_4D13: ;
  cpu_pop_af();
  lab_p28_L_4D14: ;
  p28_L_4B12();
  if (flag_z()) goto lab_p28_L_4CD1;
  mem_write16(0x848C, hl());
  p28_L_6A89();
  if (flag_c()) goto lab_p28_L_4D37;
  p00_L_2EA7();
  p28_L_6A3D();
  if (flag_c()) goto lab_p28_L_4D37;
  p28_L_4F79();
  p00_L_10DD();
  a = 0x06;
  b = 0x41;
  p00_L_2E29();
  return;
  lab_p28_L_4D37: ;
  p00_L_1037();
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p28_L_4D46;
  set_hl(0x8670);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  goto lab_p28_L_4CD1;
  lab_p28_L_4D46: ;
  set_hl(0x62C4);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  set_hl(mem_read16(0x848C));
  cpu_push_hl();
  p28_L_6215();
  p00_L_2DE7();
  cpu_pop_hl();
  p28_L_6A89();
  if (flag_nc()) goto lab_p28_L_4D6C;
  set_de(0x0000);
  mem_write16(0x848C, de());
  p00_L_2DF9();
  goto lab_p28_L_4D78;
  lab_p28_L_4D6C: ;
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  mem_write8(0x848B, a);
  cpu_ex_de_hl();
  lab_p28_L_4D78: ;
  p00_L_1037();
  p28_L_6A62();
  cpu_push_hl();
  cpu_push_de();
  a = mem_read8(0x85D9);
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p28_L_4D90;
  set_hl(0x037D);
  p00_L_192A();
  if (flag_nc()) goto lab_p28_L_4D90;
  cpu_ex_de_hl();
  lab_p28_L_4D90: ;
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  mem_write8(0x8478, a);
  p28_L_4006();
  p28_L_6313();
  cpu_push_af();
  a = mem_read8(0x8674);
  flag_cmp(a, 0x73);
  if (flag_z()) goto lab_p28_L_4DB7;
  a = mem_read8(0x867F);
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x14);
  if (flag_c()) goto lab_p28_L_4DB2;
  lab_p28_L_4DAF: ;
  p00_L_2565();
  return;
  lab_p28_L_4DB2: ;
  p28_L_6A43();
  if (flag_nc()) goto lab_p28_L_4DAF;
  lab_p28_L_4DB7: ;
  cpu_pop_af();
  flag_cmp(a, 0x09);
  if (flag_z()) goto lab_p28_L_4DED;
  flag_cmp(a, 0x36);
  if (flag_nz()) goto lab_p28_L_4DEA;
  p28_L_4275();
  cpu_pop_af();
  cpu_pop_af();
  a = mem_read8(0x867C);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p28_L_4DE6;
  p00_L_25C8();
  p28_L_4F79();
  lab_p28_L_4DD2: ;
  p00_L_2DD5();
  if (flag_c()) goto lab_p28_L_4DDD;
  p28_L_4B3B();
  goto lab_p28_L_4DD2;
  lab_p28_L_4DDD: ;
  a = mem_read8(0x8670);
  a = a & 0x10;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_4E3D;
  p28_L_4E18();
  return;
  lab_p28_L_4DE6: ;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p28_L_4DF5;
  lab_p28_L_4DEA: ;
  p00_L_2565();
  return;
  lab_p28_L_4DED: ;
  p28_L_42F2();
  cpu_pop_de();
  cpu_pop_hl();
  p28_L_40C9();
  lab_p28_L_4DF5: ;
  p00_L_25C8();
  goto lab_p28_L_4CD1;
  lab_p28_L_4E3D: ;
  p28_L_4F79();
  a = 0x02;
  mem_write8(0x8672, a);
  p28_L_4E1F();
  p28_L_6259();
  return;
}

/* flash page 28 cpu 0x4E01 (offset 0x0E01) */
void p28_L_4E01(void) {
  h = b;
  set_hl(0x62CF);
  p00_L_25A2();
  p28_L_634F();
  p00_L_25C8();
  p28_L_4E0E();
  return;
}

/* flash page 28 cpu 0x4E0E (offset 0x0E0E) */
void p28_L_4E0E(void) {
  p28_L_4F79();
  a = mem_read8(0x8670);
  a = a & 0x10;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_4E31;
  p28_L_4E18();
  return;
  lab_p28_L_4E31: ;
  set_hl(0x62CF);
  p00_L_25A2();
  p28_L_418C();
  p00_L_25C8();
  p28_L_4F79();
  a = 0x02;
  mem_write8(0x8672, a);
  p28_L_4E1F();
  p28_L_6259();
  return;
}

/* flash page 28 cpu 0x4E18 (offset 0x0E18) */
void p28_L_4E18(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x8670, a);
  p28_L_6023();
  p28_L_4E1F();
  return;
}

/* flash page 28 cpu 0x4E1F (offset 0x0E1F) */
void p28_L_4E1F(void) {
  p00_L_3CDB();
  p00_L_3DFB();
  p00_L_3CF3();
  p00_L_3CF3();
  /* ei */
  a = 0;
  flag_logic(a);
  mem_write8(0x85D9, a);
  return;
}

/* flash page 28 cpu 0x4E4F (offset 0x0E4F) */
void p28_L_4E4F(void) {
  goto lab_p28_L_4E4F;
  lab_p28_L_4DEA: ;
  p00_L_2565();
  return;
  lab_p28_L_4E4F: ;
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_4E62;
  set_bc(0x1689);
  a = hw_in(PORT_SE_STATUS);
  a = a & 0x01;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_4E62;
  lab_p28_L_4E5D: ;
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_4E5D;
  lab_p28_L_4E62: ;
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) & ~(1u << 3)));
  a = mem_read8((uint16_t)(iy + 0x0C));
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  set_hl(0x4F85);
  p00_L_25A2();
  p00_L_1169();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p28_L_4E93;
  set_hl(0x0104);
  mem_write16(0x8478, hl());
  a = 0x41;
  mem_write8(0x847A, a);
  a = 0x01;
  mem_write8(0x84AF, a);
  goto lab_p28_L_4E9D;
  lab_p28_L_4E93: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p28_L_4E9D;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 4)));
  lab_p28_L_4E9D: ;
  set_de(0x867F);
  p00_L_11FD();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  a = 0xA2;
  if (flag_z()) goto lab_p28_L_4EAE;
  a = 0xB7;
  lab_p28_L_4EAE: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  /* ei */
  set_hl(0x000B);
  p28_L_404C();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  p28_L_6320();
  flag_cmp(a, 0x36);
  if (flag_nz()) goto lab_p28_L_4ECA;
  p28_L_4275();
  p00_L_2565();
  return;
  lab_p28_L_4ECA: ;
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p28_L_4DEA;
  p28_L_424C();
  p28_L_6A30();
  if (flag_nc()) { p00_L_2565(); return; }
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p28_L_4EFD;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  p28_L_478C();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p28_L_4EF3;
  p28_L_635E();
  lab_p28_L_4EF3: ;
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 1)));
  p00_L_25C8();
  p28_L_4F85();
  return;
  lab_p28_L_4EFD: ;
  a = 0xFF;
  mem_write8(0x848C, a);
  p28_L_4190();
  set_de(0x8478);
  set_bc(mem_read16(0x867D));
  p28_L_4258();
  a = 0;
  flag_logic(a);
  mem_write8(0x848C, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p28_L_4EF3;
  set_hl(0x8478);
  cpu_push_hl();
  cpu_pop_de();
  p28_L_637A();
  goto lab_p28_L_4EF3;
}

/* flash page 28 cpu 0x4F11 (offset 0x0F11) */
void p28_L_4F11(void) {
  goto lab_p28_L_4F11;
  lab_p28_L_4EF3: ;
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 1)));
  p00_L_25C8();
  p28_L_4F85();
  return;
  lab_p28_L_4F11: ;
  /* adc a,h */
  a = (uint8_t)(a + h);
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p28_L_4EF3;
  set_hl(0x8478);
  cpu_push_hl();
  cpu_pop_de();
  p28_L_637A();
  goto lab_p28_L_4EF3;
}

/* flash page 28 cpu 0x4F23 (offset 0x0F23) */
void p28_L_4F23(void) {
  goto lab_p28_L_4F23;
  lab_p28_L_4EF3: ;
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 1)));
  p00_L_25C8();
  p28_L_4F85();
  return;
  lab_p28_L_4F23: ;
  /* di */
  a = mem_read8((uint16_t)(iy + 0x0C));
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  set_hl(0x4F85);
  p00_L_25A2();
  a = 0x0B;
  mem_write8(0x8672, a);
  a = 0xC9;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  p28_L_6439();
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 2)));
  p28_L_59DE();
  goto lab_p28_L_4EF3;
}

/* flash page 28 cpu 0x4F79 (offset 0x0F79) */
void p28_L_4F79(void) {
  /* di */
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 2)));
  a = 0x05;
  p00_L_0AB9();
  /* ei */
  return;
}

/* flash page 28 cpu 0x4F85 (offset 0x0F85) */
void p28_L_4F85(void) {
  goto lab_p28_L_4F85;
  lab_p28_L_4F78: ;
  /* nop */
  p28_L_4F79();
  return;
  lab_p28_L_4F85: ;
  /* di */
  cpu_pop_af();
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_z()) goto lab_p28_L_4F8F;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 2)));
  lab_p28_L_4F8F: ;
  goto lab_p28_L_4F78;
}

/* flash page 28 cpu 0x4F91 (offset 0x0F91) */
void p28_L_4F91(void) {
  goto lab_p28_L_4F91;
  lab_p28_L_4665: ;
  a = 0x04;
  p28_L_4068();
  p00_L_2565();
  return;
  lab_p28_L_467B: ;
  p28_L_6444();
  if (flag_nz()) { p00_L_2565(); return; }
  a = mem_read8(0x8674);
  flag_cmp(a, 0x73);
  if (flag_z()) goto lab_p28_L_468D;
  flag_cmp(a, 0x23);
  if (flag_nz()) { p00_L_2565(); return; }
  lab_p28_L_468D: ;
  p00_L_25C8();
  p28_L_4F79();
  set_hl(mem_read16(0x8684));
  mem_write16(0x8494, hl());
  set_hl(mem_read16(0x867D));
  mem_write16(0x848E, hl());
  set_hl(mem_read16(0x8680));
  mem_write16(0x8490, hl());
  set_de(mem_read16(0x8682));
  mem_write16(0x8492, de());
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  p00_L_2E2F();
  set_hl(0xFE67);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  set_de(0x9D95);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_ex_de_hl();
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p28_L_46C7;
  if (flag_nc()) goto lab_p28_L_46DC;
  lab_p28_L_46C7: ;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p28_L_46FB;
  a = 0x13;
  mem_write8(0x8672, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  a = 0x35;
  p28_L_5B03();
  return;
  lab_p28_L_46DC: ;
  mem_write16(0x867D, hl());
  set_hl(0x62CF);
  p00_L_25A2();
  a = 0x03;
  set_de(0x0003);
  p28_L_406B();
  p00_L_25C8();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x15);
  if (flag_nz()) { p28_L_44FB(); return; }
  p00_L_2565();
  return;
  lab_p28_L_46FB: ;
  set_hl(0x62CF);
  p00_L_25A2();
  goto lab_p28_L_470E;
  lab_p28_L_470E: ;
  p28_L_4190();
  set_hl(0x8670);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 1)));
  set_bc(mem_read16(0x848E));
  set_de(0x89F0);
  p28_L_4258();
  set_bc(mem_read16(0x8490));
  set_de(0x9D95);
  p28_L_4258();
  set_hl(0xFE66);
  set_bc(mem_read16(0x8492));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_ex_de_hl();
  set_de((uint16_t)(de() + 1));
  p28_L_4258();
  set_hl(mem_read16(0x8494));
  set_de(0x9D95);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p28_L_474C;
  b = h;
  c = l;
  set_de(0x0001);
  p00_L_1FC0();
  lab_p28_L_474C: ;
  p00_L_2EEF();
  p00_L_2D45();
  a = 0;
  flag_logic(a);
  mem_write8(0x9C87, a);
  p28_L_4C43();
  return;
  lab_p28_L_4F83: ;
  /* ei */
  return;
  lab_p28_L_4F91: ;
  /* di */
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 0)));
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_4FA3;
  b = a;
  a = mem_read8(0x9CAF);
  a = a | a;
  flag_logic(a);
  a = b;
  if (flag_nz()) goto lab_p28_L_4FAB;
  lab_p28_L_4FA3: ;
  p28_L_6A93();
  if (flag_nz()) goto lab_p28_L_4F83;
  p28_L_6F33();
  lab_p28_L_4FAB: ;
  p28_L_6439();
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 6)));
  p00_L_02AD();
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p28_L_4FBF;
  p00_L_2CB5();
  if (flag_z()) return;
  lab_p28_L_4FBF: ;
  a = mem_read8(0x8673);
  cpu_push_af();
  a = mem_read8(0x8672);
  cpu_push_af();
  a = mem_read8(0x8670);
  cpu_push_af();
  set_hl(0x8670);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 1)));
  a = 0x07;
  mem_write8(0x8672, a);
  a = mem_read8((uint16_t)(iy + 0x0C));
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  set_hl(0x5969);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_5017;
  a = mem_read8(0x9CAF);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_5017;
  a = (uint8_t)(a - 1);
  mem_write8(0x9CAF, a);
  a = mem_read8(0x9CB2);
  set_de(0x9CB2);
  set_hl(0x9CB3);
  set_bc(0x000F);
  while (bc() != 0) { cpu_ldi(); }
  flag_cmp(a, 0x41);
  if (flag_nz()) goto lab_p28_L_5012;
  a = 0;
  flag_logic(a);
  mem_write8(0x9CAF, a);
  a = mem_read8(0x9CB2);
  goto lab_p28_L_505F;
  lab_p28_L_5012: ;
  p00_L_3051();
  goto lab_p28_L_505C;
  lab_p28_L_5017: ;
  a = mem_read8(0x867D);
  p28_L_43C4();
  flag_set_z((mem_read8((uint16_t)(iy + 0x3D)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p28_L_505F;
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_505C;
  lab_p28_L_5029: ;
  a = hw_in(0x09);
  a = a & 0x19;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_5059;
  a = mem_read8(0x9CAF);
  flag_cmp(a, 0x0F);
  if (flag_nc()) goto lab_p28_L_505C;
  a = (uint8_t)(a + 1);
  mem_write8(0x9CAF, a);
  p28_L_43C4();
  set_hl(0x9CAF);
  e = mem_read8(hl());
  d = 0x00;
  set_hl(0x9CB1);
  set_hl((uint16_t)(hl() + de()));
  flag_set_z((mem_read8((uint16_t)(iy + 0x3D)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p28_L_5056;
  b = a;
  a = 0x41;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  a = b;
  mem_write8(hl(), a);
  goto lab_p28_L_505C;
  lab_p28_L_5056: ;
  mem_write8(hl(), a);
  goto lab_p28_L_5029;
  lab_p28_L_5059: ;
  p28_L_6F20();
  lab_p28_L_505C: ;
  p28_L_5966();
  return;
  lab_p28_L_505F: ;
  p28_L_4332();
  a = mem_read8(0x8675);
  flag_cmp(a, 0x2B);
  if (flag_nz()) goto lab_p28_L_506F;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) | (1u << 5)));
  goto lab_p28_L_50B2;
  lab_p28_L_506F: ;
  flag_cmp(a, 0x2C);
  if (flag_nz()) goto lab_p28_L_5079;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 5)));
  goto lab_p28_L_50B2;
  lab_p28_L_5079: ;
  flag_cmp(a, 0x29);
  if (flag_nz()) goto lab_p28_L_5092;
  a = hw_in(PORT_MMU_A);
  mem_write8(0x9B7A, a);
  set_hl(0x6ABC);
  mem_write16(0x9B78, hl());
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) | (1u << 4)));
  goto lab_p28_L_50B2;
  lab_p28_L_5092: ;
  flag_cmp(a, 0x2A);
  if (flag_nz()) goto lab_p28_L_509C;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 4)));
  goto lab_p28_L_50B2;
  lab_p28_L_509C: ;
  flag_cmp(a, 0x68);
  if (flag_nz()) goto lab_p28_L_50B8;
  p00_L_0AFB();
  if (flag_nz()) goto lab_p28_L_50B2;
  set_hl(0x1000);
  cpu_push_hl();
  p28_L_430F();
  cpu_pop_hl();
  p28_L_42F8();
  goto lab_p28_L_50B5;
  lab_p28_L_50B2: ;
  p28_L_42F2();
  lab_p28_L_50B5: ;
  p28_L_5966();
  return;
  lab_p28_L_50B8: ;
  flag_cmp(a, 0x2D);
  if (flag_nz()) goto lab_p28_L_50FD;
  p28_L_42F2();
  p28_L_6320();
  flag_cmp(a, 0x09);
  if (flag_nz()) { p00_L_255F(); return; }
  p28_L_42F2();
  set_hl(0x867D);
  mem_write8(hl(), 0x01);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x13);
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x80B7);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), b);
  cpu_push_hl();
  p00_L_0AFB();
  a = 0x00;
  if (flag_nz()) goto lab_p28_L_50E3;
  a = 0x01;
  lab_p28_L_50E3: ;
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  os_bcall(0x80BA);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_de(mem_read16(0x9B73));
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), d);
  a = 0x15;
  set_hl(0x000B);
  p28_L_404C();
  goto lab_p28_L_50B5;
  lab_p28_L_50FD: ;
  flag_cmp(a, 0x47);
  if (flag_nz()) goto lab_p28_L_5118;
  set_hl(0x86B7);
  mem_write16(0x84DB, hl());
  set_hl(mem_read16(0x8676));
  set_de(0x0020);
  p00_L_192A();
  if (flag_nz()) { p00_L_255F(); return; }
  p28_L_4289();
  goto lab_p28_L_50B5;
  lab_p28_L_5118: ;
  flag_cmp(a, 0x74);
  if (flag_nz()) goto lab_p28_L_5129;
  a = 0x47;
  set_hl(0x86B7);
  set_de(0x0020);
  p28_L_40D1();
  goto lab_p28_L_50B5;
  lab_p28_L_5129: ;
  flag_cmp(a, 0x87);
  if (flag_nz()) goto lab_p28_L_534D;
  p28_L_42F2();
  a = mem_read8(0x8676);
  mem_write8(0x8444, a);
  a = mem_read8(0x8677);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_514D;
  b = a;
  a = mem_read8(0x8444);
  mem_write8(0x8446, a);
  a = b;
  mem_write8(0x8444, a);
  a = mem_read8(0x8446);
  goto lab_p28_L_5150;
  lab_p28_L_514D: ;
  mem_write8(0x8446, a);
  lab_p28_L_5150: ;
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 5)));
  p28_L_5966();
  return;
  lab_p28_L_51C4: ;
  b = 0x08;
  set_de(0x8479);
  set_hl(0x8680);
  lab_p28_L_51CC: ;
  a = mem_read8(hl());
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_51CC;
  p00_L_2E77();
  if (flag_c()) { p00_L_24F1(); return; }
  p28_L_6795();
  p28_L_418C();
  p28_L_5966();
  return;
  lab_p28_L_51E1: ;
  p28_L_6530();
  set_hl(0x59B8);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  a = mem_read8(0x867F);
  flag_cmp(a, 0x26);
  if (flag_nz()) goto lab_p28_L_5321;
  a = 0x73;
  mem_write8(0x8674, a);
  a = 0x06;
  mem_write8(0x8675, a);
  p00_L_2B95();
  if (flag_nz()) goto lab_p28_L_5257;
  cpu_push_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  a = 0x09;
  os_bcall(0x8045);
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x867D, hl());
  set_de(0x000B);
  mem_write16(0x8676, de());
  a = 0x26;
  mem_write8(0x867F, a);
  set_hl(0x867D);
  a = 0x06;
  p28_L_40D1();
  p28_L_432F();
  a = mem_read8(0x8675);
  flag_cmp(a, 0x09);
  if (flag_nz()) { p00_L_2565(); return; }
  p28_L_42F2();
  a = 0x73;
  mem_write8(0x8674, a);
  a = 0x15;
  mem_write8(0x8675, a);
  set_hl(mem_read16(0x867D));
  mem_write16(0x8676, hl());
  cpu_pop_hl();
  mem_write16(0x84DB, hl());
  p28_L_4130();
  p00_L_25C8();
  /* nop */
  /* nop */
  /* nop */
  p28_L_59B8();
  return;
  lab_p28_L_5257: ;
  a = 0x03;
  p28_L_4053();
  p00_L_2565();
  return;
  lab_p28_L_525F: ;
  p00_L_0AFB();
  if (flag_nz()) goto lab_p28_L_5272;
  lab_p28_L_5264: ;
  a = 0x0C;
  p28_L_4068();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p28_L_593A();
  return;
  lab_p28_L_5272: ;
  p28_L_6530();
  set_hl(0x598A);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  a = mem_read8(0x867F);
  flag_cmp(a, 0x27);
  if (flag_nz()) goto lab_p28_L_5321;
  a = 0x73;
  mem_write8(0x8674, a);
  a = 0x06;
  mem_write8(0x8675, a);
  set_bc(0x0000);
  mem_write16(0x8676, bc());
  p28_L_41BA();
  p28_L_416F();
  p28_L_432F();
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p00_L_2B9B();
  p28_L_689C();
  if (flag_nz()) goto lab_p28_L_5306;
  lab_p28_L_52BE: ;
  cpu_push_hl();
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  /* di */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p00_L_2BA1();
  a = (uint8_t)(a + 1);
  a = (uint8_t)(a + 1);
  p00_L_2BA7();
  p28_L_689C();
  set_hl(0x8000);
  cpu_push_hl();
  p28_L_42F2();
  set_de(0x0100);
  cpu_pop_hl();
  p28_L_40C5();
  p28_L_432F();
  cpu_pop_hl();
  set_bc(0x0100);
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  set_hl(mem_read16(0x839F));
  cpu_sbc_hl_bc();
  mem_write16(0x839F, hl());
  cpu_ex_de_hl();
  if (flag_z()) goto lab_p28_L_531B;
  if (flag_c()) goto lab_p28_L_531B;
  goto lab_p28_L_52BE;
  lab_p28_L_5306: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 2)) == 0);
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 2)));
  if (flag_z()) goto lab_p28_L_5264;
  p28_L_42F2();
  h = 0x5A;
  p28_L_4192();
  goto lab_p28_L_5321;
  lab_p28_L_531B: ;
  p28_L_42F2();
  p28_L_418C();
  lab_p28_L_5321: ;
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p00_L_2BAD();
  p28_L_6D10();
  p00_L_2565();
  return;
  lab_p28_L_534D: ;
  cpu_push_af();
  a = mem_read8(0x8674);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p28_L_5359;
  flag_cmp(a, 0x13);
  if (flag_nz()) goto lab_p28_L_535D;
  lab_p28_L_5359: ;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 3)));
  lab_p28_L_535D: ;
  cpu_pop_af();
  flag_cmp(a, 0x6E);
  if (flag_z()) goto lab_p28_L_702E;
  flag_cmp(a, 0x6F);
  if (flag_z()) goto lab_p28_L_70B0;
  flag_cmp(a, 0x6D);
  if (flag_nz()) goto lab_p28_L_5381;
  a = mem_read8(0x8674);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p28_L_5377;
  flag_cmp(a, 0x12);
  if (flag_nz()) goto lab_p28_L_537B;
  lab_p28_L_5377: ;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 2)));
  lab_p28_L_537B: ;
  p28_L_4073();
  lab_p28_L_537E: ;
  p28_L_5966();
  return;
  lab_p28_L_5381: ;
  flag_cmp(a, 0xCA);
  if (flag_z()) goto lab_p28_L_5389;
  flag_cmp(a, 0xC9);
  if (flag_nz()) goto lab_p28_L_53F8;
  lab_p28_L_5389: ;
  p28_L_424C();
  p28_L_6A30();
  if (flag_nc()) goto lab_p28_L_4665;
  a = mem_read8(0x867F);
  flag_cmp(a, 0x22);
  if (flag_z()) goto lab_p28_L_5869;
  p28_L_6421();
  flag_cmp(a, 0x12);
  if (flag_z()) goto lab_p28_L_537E;
  p28_L_6530();
  a = mem_read8(0x867F);
  set_hl(0x05F1);
  p00_L_25A2();
  cpu_push_af();
  a = 0x15;
  mem_write8(0x8672, a);
  p28_L_6B25();
  cpu_pop_af();
  flag_cmp(a, 0x13);
  if (flag_z()) goto lab_p28_L_467B;
  a = mem_read8(0x8675);
  cpu_push_af();
  p28_L_478C();
  p28_L_430F();
  p28_L_432F();
  a = mem_read8(0x8675);
  cpu_push_af();
  a = mem_read8(0x8674);
  p28_L_4306();
  b = a;
  cpu_pop_af();
  flag_cmp(a, 0x92);
  if (flag_nz()) { p00_L_2565(); return; }
  cpu_pop_af();
  flag_cmp(a, 0xCA);
  if (flag_nz()) goto lab_p28_L_53EF;
  a = mem_read8(0x8478);
  flag_cmp(a, 0x16);
  if (flag_nz()) goto lab_p28_L_53EF;
  p00_L_25C8();
  p28_L_4F79();
  p28_L_54EA();
  return;
  lab_p28_L_53EF: ;
  p00_L_25C8();
  p28_L_4F79();
  p00_L_05F1();
  return;
  lab_p28_L_53F8: ;
  flag_cmp(a, 0xA2);
  if (flag_nz()) goto lab_p28_L_5451;
  a = mem_read8(0x8674);
  flag_cmp(a, 0x83);
  if (flag_nz()) goto lab_p28_L_5407;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 3)));
  lab_p28_L_5407: ;
  p28_L_424C();
  set_hl(0x867F);
  a = mem_read8(hl());
  flag_cmp(a, 0x26);
  if (flag_z()) goto lab_p28_L_51E1;
  flag_cmp(a, 0x27);
  if (flag_z()) goto lab_p28_L_525F;
  flag_cmp(a, 0x24);
  if (flag_z()) goto lab_p28_L_51C4;
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x19);
  if (flag_z()) goto lab_p28_L_63B2;
  p00_rst20();
  a = 0x0A;
  mem_write8(0x8672, a);
  p00_L_1037();
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p28_L_5449;
  flag_cmp(a, 0x17);
  if (flag_z()) goto lab_p28_L_5449;
  flag_cmp(a, 0x13);
  if (flag_z()) goto lab_p28_L_6559;
  a = (uint8_t)(a - 0x0F);
  if (flag_c()) goto lab_p28_L_5449;
  p00_L_2DF9();
  a = 0x06;
  p28_L_59CE();
  p28_L_5556();
  return;
  lab_p28_L_5449: ;
  a = 0x06;
  p28_L_59DE();
  p28_L_5556();
  return;
  lab_p28_L_5451: ;
  flag_cmp(a, 0x88);
  if (flag_nz()) goto lab_p28_L_54D7;
  p28_L_6530();
  set_hl(0x25A1);
  mem_write16(0x8595, hl());
  set_hl(0x05F1);
  p00_L_25A2();
  p28_L_6B48();
  flag_cmp(a, 0x18);
  if (flag_nc()) { p00_L_2565(); return; }
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p28_L_5489;
  p00_L_0AFB();
  if (flag_nz()) goto lab_p28_L_547E;
  a = 0x0C;
  p28_L_4068();
  p00_L_2565();
  return;
  lab_p28_L_547E: ;
  p00_L_2E77();
  if (flag_nc()) p00_L_2E7D();
  p28_L_71E5();
  goto lab_p28_L_54C2;
  lab_p28_L_5489: ;
  p00_L_19ED();
  if (flag_c()) goto lab_p28_L_54C2;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5E);
  if (flag_nz()) goto lab_p28_L_54B7;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_nz()) p00_L_0087();
  p00_L_1F2C();
  set_hl(0x0000);
  p00_L_1CA8();
  a = mem_read8(0x849B);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) goto lab_p28_L_54B5;
  a = a ^ 0x01;
  flag_logic(a);
  mem_write8(0x849B, a);
  p00_L_1135();
  p00_rst10();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 5)));
  lab_p28_L_54B5: ;
  goto lab_p28_L_54C2;
  lab_p28_L_54B7: ;
  p00_L_1F2C();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  if (flag_z()) p00_L_321F();
  lab_p28_L_54C2: ;
  p28_L_42F2();
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_54D4;
  lab_p28_L_54CA: ;
  a = hw_in(0x09);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) goto lab_p28_L_54CA;
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p28_L_54CA;
  lab_p28_L_54D4: ;
  p00_L_2565();
  return;
  lab_p28_L_54D7: ;
  flag_cmp(a, 0x89);
  if (flag_nz()) goto lab_p28_L_54F4;
  p28_L_6530();
  set_hl(0x05F1);
  p00_L_25A2();
  p28_L_6B48();
  p28_L_42F2();
  p28_L_54EA();
  return;
  lab_p28_L_54F4: ;
  flag_cmp(a, 0xB7);
  if (flag_nz()) { p28_L_5556(); return; }
  p28_L_424C();
  set_hl(0x867F);
  p00_rst20();
  p00_rst10();
  if (flag_c()) goto lab_p28_L_5551;
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_5551;
  cpu_push_de();
  cpu_ex_de_hl();
  p00_L_0033();
  set_de(mem_read16(0x847F));
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p28_L_5541;
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p28_L_5551;
  cpu_ex_de_hl();
  cpu_pop_de();
  p00_L_3AE9();
  lab_p28_L_551F: ;
  cpu_push_hl();
  set_de(0x0009);
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_552B;
  set_de(0x0012);
  lab_p28_L_552B: ;
  cpu_push_de();
  p28_L_4006();
  p28_L_6320();
  flag_cmp(a, 0x09);
  if (flag_nz()) { p00_L_2565(); return; }
  p28_L_42F2();
  cpu_pop_de();
  cpu_pop_hl();
  p28_L_40C5();
  p28_L_5556();
  return;
  lab_p28_L_5541: ;
  a = h;
  a = (uint8_t)(a - d);
  if (flag_c()) goto lab_p28_L_5551;
  a = l;
  flag_cmp(a, e);
  if (flag_c()) goto lab_p28_L_5551;
  b = d;
  c = e;
  cpu_pop_de();
  p00_L_3B67();
  goto lab_p28_L_551F;
  lab_p28_L_5551: ;
  a = 0x01;
  p28_L_4068();
  p28_L_5556();
  return;
  lab_p28_L_5869: ;
  flag_cmp(a, 0x22);
  if (flag_nz()) goto lab_p28_L_58B2;
  p28_L_6530();
  set_hl(0x59B8);
  p00_L_25A2();
  p28_L_6B25();
  p00_L_23DE();
  if (flag_nc()) goto lab_p28_L_5882;
  p00_L_23E3();
  lab_p28_L_5882: ;
  p28_L_6B57();
  p00_L_2C07();
  p28_L_42F2();
  p28_L_4F79();
  p00_L_25C8();
  p00_L_2E35();
  p00_L_05F1();
  return;
  lab_p28_L_58B2: ;
  p00_L_3D05();
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p00_L_2BAD();
  p28_L_689C();
  p00_L_2565();
  return;
  lab_p28_L_63B2: ;
  p28_L_6530();
  set_hl(0x05F1);
  p00_L_25A2();
  p28_L_6B25();
  p00_L_19B0();
  mem_write16(0x867D, hl());
  a = 0x15;
  set_hl(0x0002);
  p28_L_404C();
  set_hl(0xFE66);
  lab_p28_L_63CF: ;
  p00_L_2F9D();
  if (flag_c()) goto lab_p28_L_63F4;
  cpu_push_hl();
  p00_L_1179();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x62);
  if (flag_z()) goto lab_p28_L_63F3;
  p28_L_6A79();
  cpu_push_de();
  p28_L_4C6C();
  cpu_pop_de();
  if (flag_z()) goto lab_p28_L_63F3;
  p00_L_1037();
  cpu_ex_de_hl();
  p28_L_6A62();
  p28_L_4006();
  lab_p28_L_63F3: ;
  cpu_pop_hl();
  lab_p28_L_63F4: ;
  set_de(mem_read16(0x982E));
  p00_L_192A();
  if (flag_nz()) goto lab_p28_L_63CF;
  p00_L_1295();
  lab_p28_L_6400: ;
  a = 0x14;
  mem_write8(0x8478, a);
  p00_L_2DAB();
  if (flag_c()) goto lab_p28_L_641B;
  a = d;
  cpu_push_af();
  p00_L_2DC3();
  cpu_pop_de();
  e = c;
  a = 0x24;
  mem_write8(0x8478, a);
  p28_L_4006();
  goto lab_p28_L_6400;
  lab_p28_L_641B: ;
  p28_L_418C();
  p28_L_58A6();
  return;
  lab_p28_L_6559: ;
  p28_L_6530();
  set_hl(0x05F1);
  p00_L_25A2();
  p28_L_6B25();
  p28_L_4B62();
  p00_L_2565();
  return;
  lab_p28_L_702E: ;
  p28_L_42F2();
  set_hl(0x867D);
  p28_L_705F();
  set_de(0x0009);
  mem_write16(0x8676, de());
  p28_L_6393();
  h = 0x15;
  mem_write16(0x8674, hl());
  p28_L_41BA();
  set_hl(0x867D);
  d = 0x09;
  lab_p28_L_704E: ;
  cpu_push_de();
  c = mem_read8(hl());
  p28_L_41A2();
  cpu_pop_de();
  set_hl((uint16_t)(hl() + 1));
  d = (uint8_t)(d - 1);
  if (flag_nz()) goto lab_p28_L_704E;
  /* ei */
  p28_L_4163();
  p28_L_5966();
  return;
  lab_p28_L_70B0: ;
  p28_L_424C();
  set_bc(mem_read16(0x867D));
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p00_L_24C9(); return; }
  set_hl(mem_read16(0x9834));
  cpu_push_hl();
  set_hl(mem_read16(0x9836));
  cpu_push_hl();
  set_hl(mem_read16(0x9836));
  cpu_push_hl();
  set_hl(0x7110);
  p00_L_25A2();
  set_bc(mem_read16(0x867D));
  b = c;
  set_de(mem_read16(0x867F));
  p00_L_242F();
  set_de(mem_read16(0x8681));
  mem_write16(0x8676, de());
  p28_L_6393();
  h = 0x15;
  mem_write16(0x8674, hl());
  p28_L_41BA();
  set_de(mem_read16(0x8676));
  lab_p28_L_70F1: ;
  cpu_push_de();
  c = mem_read8(hl());
  p00_L_243E();
  c = a;
  p28_L_41A2();
  cpu_pop_de();
  set_de((uint16_t)(de() - 1));
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_70F1;
  p00_L_25C8();
  cpu_pop_de();
  cpu_pop_de();
  cpu_pop_bc();
  p00_L_242F();
  /* ei */
  p28_L_4163();
  p28_L_5966();
  return;
}

/* flash page 28 cpu 0x512D (offset 0x112D) */
void p28_L_512D(void) {
  d = e;
  p28_L_42F2();
  a = mem_read8(0x8676);
  mem_write8(0x8444, a);
  a = mem_read8(0x8677);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_514D;
  b = a;
  a = mem_read8(0x8444);
  mem_write8(0x8446, a);
  a = b;
  mem_write8(0x8444, a);
  a = mem_read8(0x8446);
  goto lab_p28_L_5150;
  lab_p28_L_514D: ;
  mem_write8(0x8446, a);
  lab_p28_L_5150: ;
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 5)));
  p28_L_5966();
  return;
}

/* flash page 28 cpu 0x5132 (offset 0x1132) */
void p28_L_5132(void) {
  halt();
  /* add a,(hl) */
  mem_write8(0x8444, a);
  a = mem_read8(0x8677);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_514D;
  b = a;
  a = mem_read8(0x8444);
  mem_write8(0x8446, a);
  a = b;
  mem_write8(0x8444, a);
  a = mem_read8(0x8446);
  goto lab_p28_L_5150;
  lab_p28_L_514D: ;
  mem_write8(0x8446, a);
  lab_p28_L_5150: ;
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 5)));
  p28_L_5966();
  return;
}

/* flash page 28 cpu 0x5157 (offset 0x1157) */
void p28_L_5157(void) {
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) | (1u << 6)));
  p28_L_575D();
  p28_L_42F2();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 6)));
  a = 0;
  flag_logic(a);
  mem_write8(0x85D9, a);
  p28_L_44FB();
  return;
}

/* flash page 28 cpu 0x5173 (offset 0x1173) */
void p28_L_5173(void) {
  goto lab_p28_L_5173;
  lab_p28_L_4E3D: ;
  p28_L_4F79();
  a = 0x02;
  mem_write8(0x8672, a);
  p28_L_4E1F();
  p28_L_6259();
  return;
  lab_p28_L_5173: ;
  p00_L_0AFB();
  if (flag_z()) goto lab_p28_L_593F;
  a = 0;
  flag_logic(a);
  mem_write8(0x8432, a);
  a = mem_read8(0x8670);
  a = a | a;
  flag_logic(a);
  if (flag_z()) p00_L_3D05();
  lab_p28_L_5184: ;
  p28_L_561B();
  a = mem_read8(0x8432);
  a = a | a;
  flag_logic(a);
  if (flag_z()) p28_L_42F2();
  lab_p28_L_518E: ;
  p28_L_6313();
  flag_cmp(a, 0x92);
  if (flag_z()) goto lab_p28_L_51B3;
  flag_cmp(a, 0x68);
  if (flag_nz()) goto lab_p28_L_519F;
  p28_L_41B3();
  goto lab_p28_L_518E;
  lab_p28_L_519F: ;
  flag_cmp(a, 0x06);
  if (flag_nz()) { p00_L_2565(); return; }
  p28_L_424C();
  p00_L_0AFB();
  if (flag_z()) goto lab_p28_L_593F;
  a = 0;
  flag_logic(a);
  mem_write8(0x8432, a);
  goto lab_p28_L_5184;
  lab_p28_L_51B3: ;
  p28_L_42F2();
  p00_L_25C8();
  set_hl(0x8670);
  flag_set_z((mem_read8(hl()) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p28_L_4E3D;
  p28_L_4E0E();
  return;
  lab_p28_L_593F: ;
  p28_L_594D();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 3)));
  p28_L_4F79();
  return;
}

/* flash page 28 cpu 0x533D (offset 0x133D) */
void p28_L_533D(void) {
  p00_L_2BB3();
  a = mem_read8(0x8432);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_534C;
  p28_L_6320();
  a = mem_read8(0x8675);
  lab_p28_L_534C: ;
  return;
}

/* flash page 28 cpu 0x53ED (offset 0x13ED) */
void p28_L_53ED(void) {
  /* jp pe,0xCD54 - other page/RAM */
  if (flag_z()) return;
  h = (uint8_t)(h - 1);
  p28_L_4F79();
  p00_L_05F1();
  return;
}

/* flash page 28 cpu 0x54EA (offset 0x14EA) */
void p28_L_54EA(void) {
  p00_L_10DD();
  a = 0;
  flag_logic(a);
  mem_write8(0x84A2, a);
  p00_L_3E2B();
  return;
}

/* flash page 28 cpu 0x5556 (offset 0x1556) */
void p28_L_5556(void) {
  flag_cmp(a, 0x06);
  if (flag_nz()) { p28_L_5966(); return; }
  a = mem_read8(0x8674);
  flag_cmp(a, 0x23);
  if (flag_nz()) { p28_L_5966(); return; }
  p28_L_424C();
  p00_L_0AFB();
  if (flag_z()) { p28_L_593A(); return; }
  p28_L_6530();
  set_hl(0x59B8);
  p00_L_25A2();
  p28_L_6B25();
  a = mem_read8(0x867F);
  flag_cmp(a, 0x28);
  if (flag_nz()) goto lab_p28_L_55E4;
  p28_L_5580();
  return;
  lab_p28_L_55E4: ;
  flag_cmp(a, 0x24);
  if (flag_nz()) goto lab_p28_L_574F;
  p00_L_25C8();
  set_hl(0x59A0);
  p00_L_25A2();
  a = mem_read8(0x8674);
  flag_cmp(a, 0x23);
  if (flag_nz()) goto lab_p28_L_574F;
  a = 0;
  flag_logic(a);
  mem_write8(0x8670, a);
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) | (1u << 0)));
  p00_L_3D05();
  set_hl(mem_read16(0x8683));
  set_bc(0x4000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nz()) { p00_L_2565(); return; }
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p28_L_561B();
  return;
  lab_p28_L_574F: ;
  flag_cmp(a, 0x25);
  if (flag_nz()) goto lab_p28_L_584D;
  p00_L_25C8();
  set_hl(0x59B8);
  p00_L_25A2();
  p28_L_575D();
  return;
  lab_p28_L_584D: ;
  flag_cmp(a, 0x23);
  if (flag_nz()) goto lab_p28_L_58B2;
  p28_L_5852();
  return;
  lab_p28_L_58B2: ;
  p00_L_3D05();
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p00_L_2BAD();
  p28_L_689C();
  p00_L_2565();
  return;
}

/* flash page 28 cpu 0x5580 (offset 0x1580) */
void p28_L_5580(void) {
  set_hl(mem_read16(0x8683));
  set_bc(0x8001);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nc()) { p00_L_2BB9(); return; }
  set_hl(mem_read16(0x8683));
  cpu_push_hl();
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p28_L_6CD3();
  set_bc(0x0100);
  set_de(0x4000);
  p28_L_6D6E();
  p28_L_6467();
  p28_L_6D6E();
  p00_L_2BBF();
  if (flag_nc()) goto lab_p28_L_55D4;
  /* nop */
  /* nop */
  /* nop */
  p00_L_2BC5();
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  p00_L_2BCB();
  if (flag_z()) goto lab_p28_L_55CE;
  goto lab_p28_L_55D4;
  lab_p28_L_55CE: ;
  p00_L_2BD1();
  if (flag_z()) goto lab_p28_L_55D4;
  lab_p28_L_55D4: ;
  cpu_pop_hl();
  p00_L_2BD7();
  p28_L_56F5();
  if (flag_z()) { p28_L_589A(); return; }
  p28_L_42F2();
  p28_L_689C();
  return;
}

/* flash page 28 cpu 0x561B (offset 0x161B) */
void p28_L_561B(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x822F, a);
  mem_write8(0x9C87, a);
  mem_write8(0x8432, a);
  os_bcall(0x808D);
  a = 0x01;
  mem_write8(0x83A4, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x83A3, a);
  a = mem_read8(0x8670);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_5643;
  p00_L_3D05();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p00_L_3CD5();
  lab_p28_L_5643: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8685, a);
  a = 0x08;
  mem_write8(0x8434, a);
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  p28_L_533D();
  cpu_push_af();
  a = mem_read8(0x8432);
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p28_L_565F;
  cpu_pop_af();
  p28_L_56B2();
  return;
  lab_p28_L_565F: ;
  set_hl(0x60B0);
  a = 0x37;
  p28_L_6595();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  set_hl(0x838D);
  p00_L_3C87();
  p00_L_3D1D();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  cpu_pop_af();
  flag_cmp(a, 0x92);
  cpu_push_af();
  if (flag_z()) goto lab_p28_L_568C;
  p28_L_424C();
  a = 0xFF;
  mem_write8(0x822F, a);
  lab_p28_L_568C: ;
  cpu_pop_af();
  if (flag_z()) goto lab_p28_L_56A1;
  p28_L_5690();
  return;
  lab_p28_L_56A1: ;
  os_bcall(0x8018);
  set_hl(0x60CA);
  a = 0x39;
  p28_L_6595();
  p00_L_2BDD();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_56C9;
  p28_L_56B2();
  return;
  lab_p28_L_56C9: ;
  cpu_push_af();
  p00_L_3D2F();
  p28_L_56F5();
  cpu_pop_bc();
  cpu_push_af();
  a = b;
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p28_L_56E6;
  p28_L_56FB();
  cpu_pop_af();
  if (flag_z()) goto lab_p28_L_56E0;
  p00_L_25C8();
  lab_p28_L_56E0: ;
  p00_L_3E8B();
  p00_L_2539();
  return;
  lab_p28_L_56E6: ;
  p28_L_56FB();
  cpu_pop_af();
  if (flag_z()) goto lab_p28_L_56EF;
  p00_L_25C8();
  lab_p28_L_56EF: ;
  p00_L_3E8B();
  p00_L_253D();
  return;
}

/* flash page 28 cpu 0x5690 (offset 0x1690) */
void p28_L_5690(void) {
  lab_p28_L_5690: ;
  a = mem_read8(0x8434);
  p28_L_533D();
  flag_cmp(a, 0x92);
  if (flag_z()) goto lab_p28_L_56A1;
  p28_L_424C();
  goto lab_p28_L_5690;
  lab_p28_L_56A1: ;
  os_bcall(0x8018);
  set_hl(0x60CA);
  a = 0x39;
  p28_L_6595();
  p00_L_2BDD();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_56C9;
  p28_L_56B2();
  return;
  lab_p28_L_56C9: ;
  cpu_push_af();
  p00_L_3D2F();
  p28_L_56F5();
  cpu_pop_bc();
  cpu_push_af();
  a = b;
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p28_L_56E6;
  p28_L_56FB();
  cpu_pop_af();
  if (flag_z()) goto lab_p28_L_56E0;
  p00_L_25C8();
  lab_p28_L_56E0: ;
  p00_L_3E8B();
  p00_L_2539();
  return;
  lab_p28_L_56E6: ;
  p28_L_56FB();
  cpu_pop_af();
  if (flag_z()) goto lab_p28_L_56EF;
  p00_L_25C8();
  lab_p28_L_56EF: ;
  p00_L_3E8B();
  p00_L_253D();
  return;
}

/* flash page 28 cpu 0x56B2 (offset 0x16B2) */
void p28_L_56B2(void) {
  a = mem_read8(0x8674);
  flag_cmp(a, 0x23);
  if (flag_nz()) return;
  p28_L_589A();
  return;
}

/* flash page 28 cpu 0x56BB (offset 0x16BB) */
void p28_L_56BB(void) {
  p00_L_3D2F();
  p28_L_56F5();
  cpu_push_af();
  a = 0x0A;
  p28_L_4053();
  goto lab_p28_L_56DA;
  lab_p28_L_56DA: ;
  cpu_pop_af();
  if (flag_z()) goto lab_p28_L_56E0;
  p00_L_25C8();
  lab_p28_L_56E0: ;
  p00_L_3E8B();
  p00_L_2539();
  return;
}

/* flash page 28 cpu 0x56F5 (offset 0x16F5) */
void p28_L_56F5(void) {
  a = mem_read8(0x8674);
  flag_cmp(a, 0x23);
  return;
}

/* flash page 28 cpu 0x56FB (offset 0x16FB) */
void p28_L_56FB(void) {
  cpu_push_af();
  /* nop */
  /* nop */
  p28_L_56FE();
  return;
}

/* flash page 28 cpu 0x56FE (offset 0x16FE) */
void p28_L_56FE(void) {
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  a = mem_read8(0x8434);
  p00_L_2BE3();
  p00_L_3D2F();
  p00_L_3D05();
  p00_L_2BAD();
  p28_L_689C();
  set_de(0x0005);
  a = 0;
  flag_logic(a);
  mem_write8(0x867C, a);
  mem_write8(0x867D, a);
  mem_write8(0x867F, a);
  mem_write8(0x8680, a);
  cpu_pop_af();
  p28_L_405D();
  return;
}

/* flash page 28 cpu 0x5737 (offset 0x1737) */
void p28_L_5737(void) {
  os_bcall(0x8057);
  p00_L_2BE9();
  cpu_push_hl();
  p00_L_2BAD();
  set_hl(mem_read16(0x867D));
  p00_L_2BEF();
  if (flag_c()) { p00_L_2BB9(); return; }
  cpu_pop_de();
  set_bc(0x00E8);
  return;
}

/* flash page 28 cpu 0x575D (offset 0x175D) */
void p28_L_575D(void) {
  p00_L_3D05();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  set_hl(0x60B0);
  a = 0x37;
  p28_L_6595();
  set_hl(0x838D);
  p00_L_3C87();
  p00_L_3CD5();
  set_hl(0x60BD);
  a = 0x38;
  p28_L_6595();
  set_hl(0x838D);
  p00_L_3C87();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  set_de(0x0A10);
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  os_bcall(0x8027);
  if (flag_z()) goto lab_p28_L_57CC;
  p28_L_5737();
  cpu_push_de();
  p28_L_6C11();
  cpu_pop_hl();
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p00_L_2BF5();
  p28_L_689C();
  p28_L_589A();
  return;
  lab_p28_L_57CC: ;
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p28_L_5737();
  p28_L_6C11();
  cpu_push_hl();
  p28_L_689C();
  set_hl(0x60CA);
  a = 0x39;
  p28_L_6595();
  set_hl(0x838D);
  p00_L_3C87();
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p00_L_2BCB();
  if (flag_nz()) { p28_L_56BB(); return; }
  cpu_pop_hl();
  a = h;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p28_L_58D3;
  a = l;
  a = a & 0xF0;
  flag_logic(a);
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p28_L_582A;
  flag_cmp(a, 0x20);
  if (flag_nz()) goto lab_p28_L_582F;
  p00_L_2BFB();
  goto lab_p28_L_5840;
  lab_p28_L_582A: ;
  p00_L_2BD1();
  goto lab_p28_L_5840;
  lab_p28_L_582F: ;
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p28_L_5838;
  p00_L_2C01();
  goto lab_p28_L_5840;
  lab_p28_L_5838: ;
  flag_cmp(a, 0x30);
  if (flag_nz()) goto lab_p28_L_58B2;
  os_bcall(0x804E);
  lab_p28_L_5840: ;
  if (flag_nz()) goto lab_p28_L_58D3;
  a = mem_read8(0x8674);
  flag_cmp(a, 0x23);
  if (flag_nz()) { p28_L_689C(); return; }
  p28_L_589A();
  return;
  lab_p28_L_58B2: ;
  p00_L_3D05();
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p00_L_2BAD();
  p28_L_689C();
  p00_L_2565();
  return;
  lab_p28_L_58D3: ;
  p28_L_689C();
  p00_L_3D2F();
  p00_L_3D05();
  flag_set_z((mem_read8((uint16_t)(iy + 0x25)) & (1u << 6)) == 0);
  if (flag_nz()) return;
  p00_L_25C8();
  set_hl(0x59B8);
  p00_L_25A2();
  p28_L_56BB();
  return;
}

/* flash page 28 cpu 0x5852 (offset 0x1852) */
void p28_L_5852(void) {
  p28_L_6F33();
  a = 0xFF;
  mem_write8(0x82A3, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x822F, a);
  mem_write8(0x83A4, a);
  os_bcall(0x808D);
  os_bcall(0x8072);
  p28_L_589A();
  return;
}

/* flash page 28 cpu 0x5897 (offset 0x1897) */
void p28_L_5897(void) {
  p28_L_56FB();
  return;
}

/* flash page 28 cpu 0x589A (offset 0x189A) */
void p28_L_589A(void) {
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p00_L_3D05();
  p28_L_42F2();
  p28_L_58A6();
  return;
}

/* flash page 28 cpu 0x58A6 (offset 0x18A6) */
void p28_L_58A6(void) {
  p00_L_25C8();
  p28_L_4F79();
  p28_L_689C();
  p00_L_05F1();
  return;
}

/* flash page 28 cpu 0x5922 (offset 0x1922) */
void p28_L_5922(void) {
  p28_L_689C();
  p00_L_2D4B();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 3)));
  p28_L_4F79();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  /* ei */
  p00_L_3F21();
  p00_L_05F1();
  return;
}

/* flash page 28 cpu 0x593A (offset 0x193A) */
void p28_L_593A(void) {
  p28_L_594D();
  p28_L_5966();
  return;
}

/* flash page 28 cpu 0x594D (offset 0x194D) */
void p28_L_594D(void) {
  p00_L_3D05();
  p00_L_2D4B();
  p00_L_0B93();
  b = 0x64;
  lab_p28_L_5958: ;
  cpu_push_bc();
  p00_L_038C();
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_5962;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_5958;
  lab_p28_L_5962: ;
  p00_L_0BA2();
  return;
}

/* flash page 28 cpu 0x5966 (offset 0x1966) */
void p28_L_5966(void) {
  p00_L_25C8();
  /* di */
  cpu_pop_af();
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_z()) goto lab_p28_L_5973;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 2)));
  lab_p28_L_5973: ;
  cpu_pop_af();
  mem_write8(0x8670, a);
  cpu_pop_af();
  mem_write8(0x8672, a);
  cpu_pop_af();
  mem_write8(0x8673, a);
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 3)));
  p28_L_4F79();
  p28_L_6F20();
  return;
}

/* flash page 28 cpu 0x59B8 (offset 0x19B8) */
void p28_L_59B8(void) {
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p00_L_3D05();
  p28_L_689C();
  b = a;
  a = mem_read8(0x8672);
  a = (uint8_t)(a + 1);
  b = a;
  if (flag_z()) return;
  p00_L_05F1();
  return;
}

/* flash page 28 cpu 0x59CE (offset 0x19CE) */
void p28_L_59CE(void) {
  cpu_push_af();
  a = mem_read8(0x8478);
  set_de(0x0000);
  mem_write16(0x848C, de());
  p00_L_210A();
  goto lab_p28_L_5A05;
  lab_p28_L_5A05: ;
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_de();
  p28_L_4008();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x0A);
  if (flag_z()) goto lab_p28_L_5A20;
  a = b;
  flag_cmp(a, 0x82);
  lab_p28_L_5A15: ;
  if (flag_z()) { p00_L_2565(); return; }
  flag_cmp(a, 0x83);
  if (flag_z()) goto lab_p28_L_5A15;
  flag_cmp(a, 0x73);
  if (flag_z()) goto lab_p28_L_5A15;
  lab_p28_L_5A20: ;
  p28_L_6320();
  flag_cmp(a, 0x09);
  if (flag_nz()) { p00_L_2565(); return; }
  p28_L_42F2();
  cpu_pop_de();
  cpu_pop_hl();
  p28_L_40C9();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x0B);
  if (flag_z()) { p28_L_418C(); return; }
  return;
}

/* flash page 28 cpu 0x59DE (offset 0x19DE) */
void p28_L_59DE(void) {
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) | (1u << 1)));
  cpu_push_af();
  p28_L_6A79();
  if (flag_nc()) goto lab_p28_L_59EF;
  lab_p28_L_59E8: ;
  cpu_pop_af();
  a = 0x01;
  p28_L_4068();
  return;
  lab_p28_L_59EF: ;
  p28_L_6A3D();
  if (flag_nc()) goto lab_p28_L_59E8;
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x09);
  if (flag_z()) goto lab_p28_L_59E8;
  flag_cmp(a, 0x0A);
  if (flag_z()) goto lab_p28_L_59E8;
  mem_write8(0x8478, a);
  cpu_ex_de_hl();
  p28_L_6A62();
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_de();
  p28_L_4008();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x0A);
  if (flag_z()) goto lab_p28_L_5A20;
  a = b;
  flag_cmp(a, 0x82);
  lab_p28_L_5A15: ;
  if (flag_z()) { p00_L_2565(); return; }
  flag_cmp(a, 0x83);
  if (flag_z()) goto lab_p28_L_5A15;
  flag_cmp(a, 0x73);
  if (flag_z()) goto lab_p28_L_5A15;
  lab_p28_L_5A20: ;
  p28_L_6320();
  flag_cmp(a, 0x09);
  if (flag_nz()) { p00_L_2565(); return; }
  p28_L_42F2();
  cpu_pop_de();
  cpu_pop_hl();
  p28_L_40C9();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x0B);
  if (flag_z()) { p28_L_418C(); return; }
  return;
}

/* flash page 28 cpu 0x5A39 (offset 0x1A39) */
void p28_L_5A39(void) {
  set_hl(0x8694);
  b = 0x23;
  lab_p28_L_5A3E: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_5A3E;
  p00_L_24A9();
  if (flag_nz()) return;
  set_hl(0x8697);
  b = 0x20;
  a = 0;
  flag_logic(a);
  lab_p28_L_5A4D: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_5A4D;
  return;
}

/* flash page 28 cpu 0x5A52 (offset 0x1A52) */
void p28_L_5A52(void) {
  p28_L_5A39();
  a = 0;
  flag_logic(a);
  p28_L_5A56();
  return;
}

/* flash page 28 cpu 0x5A56 (offset 0x1A56) */
void p28_L_5A56(void) {
  cpu_push_af();
  set_hl(0xFE66);
  d = 0x00;
  set_bc(mem_read16(0x982E));
  lab_p28_L_5A60: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p28_L_5A8D;
  if (flag_z()) goto lab_p28_L_5A8D;
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) goto lab_p28_L_5A70;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  goto lab_p28_L_5A72;
  lab_p28_L_5A70: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  lab_p28_L_5A72: ;
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  p00_L_2407();
  e = 0x03;
  p00_L_17B3();
  if (flag_z()) goto lab_p28_L_5A86;
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p28_L_5A88;
  lab_p28_L_5A86: ;
  e = mem_read8(hl());
  e = (uint8_t)(e + 1);
  lab_p28_L_5A88: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  goto lab_p28_L_5A60;
  lab_p28_L_5A8D: ;
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x5A8F (offset 0x1A8F) */
void p28_L_5A8F(void) {
  set_hl(0x8694);
  b = 0x03;
  lab_p28_L_5A94: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_5A94;
  return;
}

/* flash page 28 cpu 0x5A9A (offset 0x1A9A) */
void p28_L_5A9A(void) {
  p00_L_1295();
  lab_p28_L_5A9D: ;
  p00_L_2DAB();
  if (flag_c()) return;
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_5AAD;
  a = mem_read8(0x9C87);
  flag_cmp(a, 0x69);
  if (flag_z()) goto lab_p28_L_5AB3;
  lab_p28_L_5AAD: ;
  a = d;
  p00_L_2C13();
  goto lab_p28_L_5A9D;
  lab_p28_L_5AB3: ;
  set_bc(0x000E);
  set_hl(0x9C88);
  set_de(0x8697);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 28 cpu 0x5ABF (offset 0x1ABF) */
void p28_L_5ABF(void) {
  p28_L_5A39();
  p28_L_5A8F();
  p28_L_5A9A();
  /* scf */
  p28_L_5A56();
  return;
}

/* flash page 28 cpu 0x5ACD (offset 0x1ACD) */
void p28_L_5ACD(void) {
  p28_L_5A52();
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) | (1u << 3)));
  a = 0;
  flag_logic(a);
  mem_write8(0x85D9, a);
  p28_L_6439();
  set_hl(0x6029);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  /* res 0,(iy) */
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  a = 0x30;
  p28_L_5B03();
  p28_L_6023();
  p28_L_6275();
  p28_L_4F79();
  return;
}

/* flash page 28 cpu 0x5B03 (offset 0x1B03) */
void p28_L_5B03(void) {
  cpu_push_af();
  p00_L_3E8B();
  cpu_pop_af();
  p00_L_2E59();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 5)));
  return;
}

/* flash page 28 cpu 0x5B10 (offset 0x1B10) */
void p28_L_5B10(void) {
  goto lab_p28_L_5B10;
  lab_p28_L_4703: ;
  set_hl(0x62CF);
  p00_L_25A2();
  a = 0x14;
  mem_write8(0x8672, a);
  p28_L_4190();
  set_hl(0x8670);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 1)));
  set_bc(mem_read16(0x848E));
  set_de(0x89F0);
  p28_L_4258();
  set_bc(mem_read16(0x8490));
  set_de(0x9D95);
  p28_L_4258();
  set_hl(0xFE66);
  set_bc(mem_read16(0x8492));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_ex_de_hl();
  set_de((uint16_t)(de() + 1));
  p28_L_4258();
  set_hl(mem_read16(0x8494));
  set_de(0x9D95);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p28_L_474C;
  b = h;
  c = l;
  set_de(0x0001);
  p00_L_1FC0();
  lab_p28_L_474C: ;
  p00_L_2EEF();
  p00_L_2D45();
  a = 0;
  flag_logic(a);
  mem_write8(0x9C87, a);
  p28_L_4C43();
  return;
  lab_p28_L_4B4F: ;
  p28_L_6444();
  if (flag_nz()) { p00_L_2565(); return; }
  a = 0x05;
  mem_write8(0x8672, a);
  a = 0x32;
  p28_L_5B03();
  return;
  lab_p28_L_4C85: ;
  p28_L_6F33();
  a = mem_read8(0x85D9);
  flag_cmp(a, 0x14);
  if (flag_z()) goto lab_p28_L_5DE5;
  a = 0xFF;
  mem_write8(0x85D1, a);
  a = mem_read8(0x8672);
  flag_cmp(a, 0x05);
  if (flag_z()) { p28_L_4B62(); return; }
  set_hl(0x62C4);
  p00_L_25A2();
  p28_L_4317();
  p00_L_25C8();
  a = 0x08;
  mem_write8(0x8672, a);
  p00_L_3E8B();
  p00_L_3D2F();
  a = 0;
  flag_logic(a);
  mem_write8(0x8670, a);
  mem_write8(0x97A5, a);
  p28_L_6013();
  mem_write8(0x8478, a);
  flag_cmp(a, 0x01);
  a = 0x40;
  if (flag_nz()) goto lab_p28_L_4CCE;
  a = 0xFF;
  mem_write8(0x847A, a);
  a = 0x5D;
  lab_p28_L_4CCE: ;
  mem_write8(0x8479, a);
  p28_L_4CD1();
  return;
  lab_p28_L_4DFB: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8670, a);
  p28_L_6023();
  set_hl(0x62CF);
  p00_L_25A2();
  p28_L_634F();
  p00_L_25C8();
  p28_L_4E0E();
  return;
  lab_p28_L_5AD0: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) | (1u << 3)));
  a = 0;
  flag_logic(a);
  mem_write8(0x85D9, a);
  p28_L_6439();
  set_hl(0x6029);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  /* res 0,(iy) */
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  a = 0x30;
  p28_L_5B03();
  p28_L_6023();
  p28_L_6275();
  p28_L_4F79();
  return;
  lab_p28_L_5B10: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p28_L_5B2D;
  cpu_push_af();
  a = mem_read8(0x8672);
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p28_L_5B26;
  flag_cmp(a, 0x17);
  if (flag_z()) goto lab_p28_L_5B26;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p28_L_5B2C;
  lab_p28_L_5B26: ;
  p00_L_03A0();
  p00_L_3DA1();
  lab_p28_L_5B2C: ;
  cpu_pop_af();
  lab_p28_L_5B2D: ;
  b = a;
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_3123();
  a = b;
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p28_L_5B45;
  p00_L_24A9();
  if (flag_z()) p28_L_6E1A();
  p28_L_44FB();
  return;
  lab_p28_L_5B45: ;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p28_L_5B63;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x17);
  if (flag_z()) goto lab_p28_L_5B53;
  flag_cmp(a, 0x04);
  if (flag_nz()) return;
  lab_p28_L_5B53: ;
  p28_L_61FE();
  p28_L_6223();
  if (flag_z()) return;
  p00_L_2DE1();
  p28_L_4B25();
  p28_L_6259();
  return;
  lab_p28_L_5B63: ;
  flag_cmp(a, 0x16);
  if (flag_z()) goto lab_p28_L_4C85;
  flag_cmp(a, 0x04);
  if (flag_z()) { p28_L_6158(); return; }
  flag_cmp(a, 0x03);
  if (flag_z()) { p28_L_610C(); return; }
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p28_L_5B7A;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p28_L_5BBA;
  lab_p28_L_5B7A: ;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p28_L_5B93;
  flag_cmp(a, 0x17);
  if (flag_z()) goto lab_p28_L_5B93;
  flag_cmp(a, 0x09);
  if (flag_nz()) return;
  a = mem_read8(0x85D9);
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p28_L_5FD2;
  p28_L_5FD4();
  return;
  lab_p28_L_5B93: ;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) & ~(1u << 2)));
  a = mem_read8(0x8672);
  flag_cmp(a, 0x17);
  if (flag_nz()) goto lab_p28_L_5BA2;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 2)));
  lab_p28_L_5BA2: ;
  a = 0x09;
  mem_write8(0x8672, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  p00_L_3E8B();
  a = 0x31;
  l = 0x01;
  p00_L_2D1B();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 5)));
  return;
  lab_p28_L_5BBA: ;
  flag_cmp(a, 0x1A);
  if (flag_z()) goto lab_p28_L_4703;
  flag_cmp(a, 0x27);
  if (flag_nz()) goto lab_p28_L_5BCB;
  a = mem_read8(0x8673);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_5AD0;
  return;
  lab_p28_L_5BCB: ;
  flag_cmp(a, 0x19);
  if (flag_nz()) goto lab_p28_L_5BF4;
  a = mem_read8(0x867F);
  flag_cmp(a, 0x13);
  if (flag_z()) goto lab_p28_L_5BF9;
  p28_L_626E();
  flag_cmp(a, 0x06);
  if (flag_z()) { p28_L_4CD1(); return; }
  flag_cmp(a, 0x02);
  if (flag_z()) p00_L_21A7();
  set_hl(0x62CF);
  p00_L_25A2();
  a = 0x02;
  p28_L_4068();
  p00_L_25C8();
  p28_L_4A71();
  return;
  lab_p28_L_5BF4: ;
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p28_L_5C87;
  lab_p28_L_5BF9: ;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x13);
  if (flag_nz()) goto lab_p28_L_5C08;
  p28_L_6023();
  p28_L_634F();
  goto lab_p28_L_5C36;
  lab_p28_L_5C08: ;
  p28_L_626E();
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p28_L_4DFB;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p28_L_5C19;
  p00_L_21A7();
  goto lab_p28_L_5C1D;
  lab_p28_L_5C19: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p28_L_5C23;
  lab_p28_L_5C1D: ;
  p28_L_634F();
  p28_L_5C20();
  return;
  lab_p28_L_5C23: ;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p28_L_5C36;
  a = mem_read8(0x8672);
  set_hl(0x8670);
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p28_L_5C39;
  flag_set_z((mem_read8(hl()) & (1u << 1)) == 0);
  if (flag_nz()) { p00_L_09CA(); return; }
  lab_p28_L_5C36: ;
  p28_L_5ACD();
  return;
  lab_p28_L_5C39: ;
  flag_cmp(a, 0x11);
  if (flag_nz()) goto lab_p28_L_5C84;
  p28_L_61FE();
  lab_p28_L_5C41: ;
  p00_L_2DDB();
  if (flag_c()) goto lab_p28_L_5C81;
  p28_L_4B12();
  if (flag_z()) goto lab_p28_L_5C41;
  p28_L_6215();
  p28_L_5C20();
  return;
  lab_p28_L_5C81: ;
  p28_L_5C20();
  return;
  lab_p28_L_5C84: ;
  p28_L_5ACD();
  return;
  lab_p28_L_5C87: ;
  flag_cmp(a, 0x18);
  if (flag_nz()) goto lab_p28_L_5CA5;
  p28_L_626E();
  goto lab_p28_L_5CA2;
  lab_p28_L_5CA2: ;
  p28_L_4906();
  return;
  lab_p28_L_5CA5: ;
  flag_cmp(a, 0x17);
  if (flag_nz()) goto lab_p28_L_5DA6;
  p00_L_2DFF();
  return;
  lab_p28_L_5DA6: ;
  flag_cmp(a, 0x13);
  if (flag_z()) goto lab_p28_L_4B4F;
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p28_L_5FC5;
  p28_L_5ABF();
  p28_L_5FCD();
  return;
  lab_p28_L_5DB6: ;
  flag_cmp(a, 0x1F);
  if (flag_nz()) { p28_L_5DC3(); return; }
  p28_L_5DCC();
  mem_write8(0x85D9, a);
  p28_L_5FD4();
  return;
  lab_p28_L_5DE5: ;
  a = 0x14;
  mem_write8(0x85D9, a);
  set_hl(0x62CF);
  p00_L_25A2();
  p28_L_6B25();
  a = 0;
  flag_logic(a);
  mem_write8(0x8670, a);
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p00_L_3D05();
  p28_L_5E00();
  return;
  lab_p28_L_5FC5: ;
  flag_cmp(a, 0x11);
  if (flag_nz()) goto lab_p28_L_5DB6;
  p28_L_5A52();
  p28_L_5FCD();
  return;
  lab_p28_L_5FD2: ;
  a = 0x05;
  p28_L_5FD4();
  return;
}

/* flash page 28 cpu 0x5BED (offset 0x1BED) */
void p28_L_5BED(void) {
  b = b;
  p00_L_25C8();
  p28_L_4A71();
  return;
}

/* flash page 28 cpu 0x5C20 (offset 0x1C20) */
void p28_L_5C20(void) {
  p28_L_4A9D();
  return;
}

/* flash page 28 cpu 0x5C50 (offset 0x1C50) */
void p28_L_5C50(void) {
  p00_L_1037();
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p28_L_5C6C;
  flag_cmp(a, 0x0F);
  if (flag_c()) goto lab_p28_L_5C6C;
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p28_L_5C6B;
  set_hl(0x8F50);
  set_de(0x8E7E);
  set_bc(0x0099);
  while (bc() != 0) { cpu_ldi(); }
  return;
  lab_p28_L_5C6B: ;
  return;
  lab_p28_L_5C6C: ;
  p00_L_19ED();
  cpu_ex_de_hl();
  set_bc(mem_read16(0x9815));
  set_bc((uint16_t)(bc() - 1));
  set_bc((uint16_t)(bc() - 1));
  mem_write8(hl(), c);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), b);
  set_hl((uint16_t)(hl() - 1));
  cpu_ex_de_hl();
  a = 0x03;
  p00_L_1F5F();
  return;
}

/* flash page 28 cpu 0x5CAD (offset 0x1CAD) */
void p28_L_5CAD(void) {
  p00_L_2F61();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p00_L_22FC();
  p00_L_2DFF();
  return;
}

/* flash page 28 cpu 0x5CBA (offset 0x1CBA) */
void p28_L_5CBA(void) {
  goto lab_p28_L_5CBA;
  lab_p28_L_5C90: ;
  set_hl(0x8670);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  p00_L_233D();
  p00_L_2F61();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p28_L_6271();
  p28_L_4906();
  return;
  lab_p28_L_5CBA: ;
  set_hl(mem_read16(0x9D8B));
  mem_write16(0x848E, hl());
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  if (flag_c()) goto lab_p28_L_5CD4;
  p00_L_2F61();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p00_L_22ED();
  p00_L_2E05();
  return;
  lab_p28_L_5CD4: ;
  p00_L_22F7();
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p28_L_5CFA;
  a = mem_read8(0x8479);
  p00_L_2D93();
  if (flag_c()) { p28_L_5CAD(); return; }
  a = mem_read8(0x8483);
  mem_write8(0x8478, a);
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 1)));
  lab_p28_L_5CEF: ;
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 5)));
  p00_L_19ED();
  if (flag_nc()) { p28_L_5CAD(); return; }
  goto lab_p28_L_5D78;
  lab_p28_L_5CFA: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p28_L_5D46;
  a = mem_read8(0x8478);
  b = a;
  flag_cmp(a, 0x06);
  if (flag_nc()) { p28_L_5CAD(); return; }
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p28_L_5D1B;
  a = b;
  flag_cmp(a, 0x02);
  if (flag_nz()) { p28_L_5CAD(); return; }
  lab_p28_L_5D14: ;
  a = 0x01;
  mem_write8(0x8478, a);
  goto lab_p28_L_5CEF;
  lab_p28_L_5D1B: ;
  set_hl(0x8479);
  a = mem_read8(hl());
  p00_L_2D93();
  if (flag_c()) { p28_L_5CAD(); return; }
  lab_p28_L_5D24: ;
  a = mem_read8(hl());
  p00_L_2D93();
  if (flag_nc()) goto lab_p28_L_5D34;
  flag_cmp(a, 0x30);
  if (flag_c()) { p28_L_5CAD(); return; }
  flag_cmp(a, 0x3A);
  if (flag_nc()) { p28_L_5CAD(); return; }
  lab_p28_L_5D34: ;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_5D24;
  mem_write8(hl(), 0x00);
  p00_L_12C4();
  p00_L_12C4();
  a = 0x5D;
  mem_write8(0x8479, a);
  goto lab_p28_L_5D14;
  lab_p28_L_5D46: ;
  a = mem_read8(0x8483);
  a = a & 0x1F;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_5D5B;
  a = mem_read8(0x8478);
  flag_cmp(a, 0x02);
  if (flag_nc()) { p28_L_5CAD(); return; }
  p00_rst10();
  if (flag_c()) goto lab_p28_L_5D78;
  p28_L_5CAD();
  return;
  lab_p28_L_5D5B: ;
  a = mem_read8(0x8484);
  set_hl(0x8479);
  cpu_cp_hl();
  if (flag_nz()) { p28_L_5CAD(); return; }
  p00_rst10();
  if (flag_c()) goto lab_p28_L_5D78;
  p28_L_4C6C();
  if (flag_nz()) { p28_L_5CAD(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p28_L_5C90;
  p00_L_2D0F();
  return;
  lab_p28_L_5D78: ;
  set_hl(0x8670);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  set_hl(mem_read16(0x848E));
  cpu_push_hl();
  p00_L_2F61();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 0)));
  cpu_pop_hl();
  mem_write16(0x867D, hl());
  p28_L_6271();
  p00_L_2196();
  a = mem_read8(0x8483);
  mem_write8(0x8478, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 1)) == 0);
  if (flag_nz()) { p00_L_2D0F(); return; }
  p28_L_4956();
  return;
}

/* flash page 28 cpu 0x5DC3 (offset 0x1DC3) */
void p28_L_5DC3(void) {
  goto lab_p28_L_5DC3;
  lab_p28_L_5DBD: ;
  mem_write8(0x85D9, a);
  p28_L_5FD4();
  return;
  lab_p28_L_5DC3: ;
  flag_cmp(a, 0x27);
  if (flag_nz()) goto lab_p28_L_5F01;
  a = 0x14;
  goto lab_p28_L_5DBD;
  lab_p28_L_5F01: ;
  flag_cmp(a, 0x1B);
  if (flag_nz()) goto lab_p28_L_5F69;
  p28_L_6F33();
  p00_L_2B95();
  if (flag_nz()) { p00_L_2535(); return; }
  set_hl(0x62CF);
  p00_L_25A2();
  p00_L_2B95();
  cpu_push_hl();
  a = 0x73;
  mem_write8(0x8674, a);
  a = 0x22;
  mem_write8(0x867F, a);
  set_hl(0x000B);
  a = 0xC9;
  set_de(0x867D);
  cpu_ex_de_hl();
  p28_L_40D1();
  p28_L_4190();
  a = 0x15;
  mem_write8(0x8675, a);
  cpu_pop_hl();
  cpu_push_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  a = 0x09;
  os_bcall(0x8045);
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x8676, hl());
  cpu_pop_hl();
  mem_write16(0x84DB, hl());
  p28_L_4130();
  p00_L_2E53();
  p00_L_25C8();
  p28_L_4F79();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p00_L_3E8B();
  set_hl(0x26E9);
  a = 0x3D;
  p28_L_6586();
  p28_L_4E18();
  return;
  lab_p28_L_5F69: ;
  flag_cmp(a, 0x1C);
  if (flag_nz()) goto lab_p28_L_5FB4;
  p28_L_6F33();
  set_hl(0x62CF);
  p00_L_25A2();
  p28_L_41AF();
  p28_L_6313();
  a = mem_read8(0x8674);
  flag_cmp(a, 0x73);
  if (flag_z()) goto lab_p28_L_5F88;
  a = 0x01;
  p28_L_4068();
  return;
  lab_p28_L_5F88: ;
  p00_L_3D05();
  a = 0;
  flag_logic(a);
  mem_write8(0x844B, a);
  mem_write8(0x844C, a);
  set_hl(0x2795);
  a = 0x3E;
  p28_L_6586();
  p00_L_3CD5();
  a = 0x01;
  mem_write8(0x844B, a);
  set_hl(0x0064);
  p00_L_3C87();
  p28_L_69D3();
  p00_L_25C8();
  p28_L_4F79();
  p28_L_4E18();
  return;
  lab_p28_L_5FB4: ;
  flag_cmp(a, 0x12);
  if (flag_nz()) return;
  a = 0x01;
  mem_write8(0x85D0, a);
  a = 0x0A;
  mem_write8(0x85D9, a);
  a = 0x17;
  goto lab_p28_L_5FD9;
  lab_p28_L_5FD9: ;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) & ~(1u << 2)));
  mem_write8(0x8672, a);
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p00_L_3D17();
  set_hl(0x26AE);
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  a = 0x05;
  p28_L_6586();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  set_hl(0x26B5);
  a = 0x06;
  p28_L_6586();
  a = 0x01;
  p28_L_6001();
  return;
}

/* flash page 28 cpu 0x5DCC (offset 0x1DCC) */
void p28_L_5DCC(void) {
  a = mem_read8(0x8446);
  set_hl(0x5DD7);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  return;
}

/* flash page 28 cpu 0x5E00 (offset 0x1E00) */
void p28_L_5E00(void) {
  goto lab_p28_L_5E00;
  lab_p28_L_4E3D: ;
  p28_L_4F79();
  a = 0x02;
  mem_write8(0x8672, a);
  p28_L_4E1F();
  p28_L_6259();
  return;
  lab_p28_L_5E00: ;
  b = 0x0D;
  c = 0x15;
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_5E0D;
  b = 0x61;
  c = 0x69;
  lab_p28_L_5E0D: ;
  cpu_push_bc();
  p00_L_24A9();
  if (flag_z()) goto lab_p28_L_5E1D;
  set_hl(0x8697);
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  goto lab_p28_L_5E25;
  lab_p28_L_5E1D: ;
  b = c;
  p28_L_7EF2();
  b = a;
  p28_L_4B1A();
  lab_p28_L_5E25: ;
  if (flag_z()) goto lab_p28_L_5EDE;
  a = mem_read8(0x8670);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_5E40;
  p28_L_41AF();
  p28_L_6313();
  a = mem_read8(0x8674);
  flag_cmp(a, 0x73);
  if (flag_z()) goto lab_p28_L_5E40;
  a = 0x01;
  p28_L_4068();
  return;
  lab_p28_L_5E40: ;
  cpu_pop_bc();
  cpu_push_bc();
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  a = c;
  cpu_push_af();
  os_bcall(0x8096);
  if (flag_nz()) goto lab_p28_L_5E97;
  cpu_push_hl();
  set_hl(0x838E);
  a = mem_read8(hl());
  a = a & 0x0F;
  flag_logic(a);
  mem_write8(hl(), a);
  cpu_pop_hl();
  os_bcall(0x80A8);
  if (flag_z()) goto lab_p28_L_5E97;
  cpu_push_hl();
  p00_L_2C19();
  if (flag_nz()) goto lab_p28_L_5E76;
  a = 0x73;
  mem_write8(0x8674, a);
  p28_L_660B();
  lab_p28_L_5E76: ;
  cpu_pop_hl();
  /* nop */
  /* nop */
  /* nop */
  p00_L_2C1F();
  if (flag_nz()) goto lab_p28_L_5E97;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p28_L_6640();
  lab_p28_L_5E97: ;
  cpu_pop_af();
  cpu_push_af();
  p00_L_2C25();
  p28_L_6215();
  p00_L_2DE7();
  /* di */
  a = 0xFF;
  mem_write8(0x8670, a);
  cpu_pop_af();
  p28_L_6795();
  a = mem_read8(0x8432);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p28_L_5EDE;
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p28_L_5EBA;
  cpu_pop_bc();
  goto lab_p28_L_5EEA;
  lab_p28_L_5EBA: ;
  a = 0x92;
  mem_write8(0x8675, a);
  a = 0x73;
  mem_write8(0x8674, a);
  set_bc(0x0000);
  mem_write16(0x8676, bc());
  p28_L_41BA();
  p28_L_6320();
  a = mem_read8(0x8675);
  flag_cmp(a, 0x36);
  if (flag_z()) goto lab_p28_L_6764;
  flag_cmp(a, 0x56);
  if (flag_nz()) { p00_L_2565(); return; }
  lab_p28_L_5EDE: ;
  cpu_pop_bc();
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p28_L_5E0D;
  a = mem_read8(0x8670);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_5EF0;
  lab_p28_L_5EEA: ;
  p28_L_418C();
  p28_L_6259();
  lab_p28_L_5EF0: ;
  p00_L_25C8();
  p28_L_689C();
  set_hl(0x8670);
  flag_set_z((mem_read8(hl()) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p28_L_4E3D;
  p28_L_4E0E();
  return;
  lab_p28_L_675E: ;
  a = 0x02;
  mem_write8(0x8432, a);
  return;
  lab_p28_L_6764: ;
  p28_L_424C();
  a = mem_read8(0x867F);
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p28_L_675E;
  p00_L_25C8();
  a = mem_read8(0x867F);
  flag_cmp(a, 0x01);
  if (flag_z()) { p00_L_24F5(); return; }
  flag_cmp(a, 0x07);
  if (flag_z()) { p00_L_2539(); return; }
  flag_cmp(a, 0x08);
  if (flag_z()) { p00_L_2539(); return; }
  flag_cmp(a, 0x09);
  if (flag_z()) { p00_L_253D(); return; }
  flag_cmp(a, 0x0B);
  if (flag_z()) { p00_L_2541(); return; }
  flag_cmp(a, 0x01);
  if (flag_z()) { p28_L_4E18(); return; }
  p00_L_255F();
  return;
}

/* flash page 28 cpu 0x5FCD (offset 0x1FCD) */
void p28_L_5FCD(void) {
  a = 0x09;
  mem_write8(0x85D9, a);
  a = 0x05;
  p28_L_5FD4();
  return;
}

/* flash page 28 cpu 0x5FD4 (offset 0x1FD4) */
void p28_L_5FD4(void) {
  mem_write8(0x85D0, a);
  a = 0x04;
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) & ~(1u << 2)));
  mem_write8(0x8672, a);
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p00_L_3D17();
  set_hl(0x26AE);
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  a = 0x05;
  p28_L_6586();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  set_hl(0x26B5);
  a = 0x06;
  p28_L_6586();
  a = 0x01;
  p28_L_6001();
  return;
}

/* flash page 28 cpu 0x6001 (offset 0x2001) */
void p28_L_6001(void) {
  mem_write8(0x97A5, a);
  p28_L_6013();
  mem_write8(0x85D0, a);
  p28_L_61C5();
  p28_L_6223();
  p28_L_6252();
  return;
}

/* flash page 28 cpu 0x6013 (offset 0x2013) */
void p28_L_6013(void) {
  a = mem_read8(0x85D9);
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p28_L_601D;
  a = 0x01;
  return;
  lab_p28_L_601D: ;
  flag_cmp(a, 0x09);
  if (flag_nz()) return;
  a = 0x05;
  return;
}

/* flash page 28 cpu 0x6023 (offset 0x2023) */
void p28_L_6023(void) {
  a = 0x01;
  mem_write8(0x8672, a);
  return;
}

/* flash page 28 cpu 0x609C (offset 0x209C) */
void p28_str_3(void) {
  b = h;
  b = l;
  c = h;
  b = l;
  d = h;
  b = l;
  if (flag_nz()) goto lab_p28_L_60C4;
  if (flag_nz()) goto lab_p28_L_60C6;
  if (flag_nz()) goto lab_p28_L_60C8;
  if (flag_nz()) goto lab_p28_L_60CA;
  b = d;
  e = c;
  d = h;
  b = l;
  d = e;
  /* nop */
  if (flag_nz()) goto lab_p28_L_6104;
  h = l;
  h = e;
  h = l;
  l = c;
  halt();
  l = c;
  l = mem_read8(hl());
  h = a;
  /* adc a,0x00 */
  /* nop */
  p28_str_4();
  return;
  lab_p28_L_60C4: ;
  h = e;
  h = c;
  lab_p28_L_60C6: ;
  mem_write8(hl(), h);
  h = l;
  lab_p28_L_60C8: ;
  /* nop */
  /* nop */
  lab_p28_L_60CA: ;
  d = mem_read8(hl());
  h = c;
  l = h;
  l = c;
  h = h;
  h = c;
  mem_write8(hl(), h);
  l = c;
  l = mem_read8(hl());
  h = a;
  /* adc a,0x00 */
  /* nop */
  p28_L_60D7();
  return;
  lab_p28_L_6104: ;
  b = (uint8_t)(b + 1);
  if (flag_z()) return;
  flag_cmp(a, 0x17);
  if (flag_z()) return;
  flag_cmp(a, 0x02);
  return;
}

/* flash page 28 cpu 0x60BD (offset 0x20BD) */
void p28_str_4(void) {
  b = e;
  h = l;
  mem_write8(hl(), d);
  mem_write8(hl(), h);
  l = c;
  h = mem_read8(hl());
  l = c;
  h = e;
  h = c;
  mem_write8(hl(), h);
  h = l;
  /* nop */
  /* nop */
  d = mem_read8(hl());
  h = c;
  l = h;
  l = c;
  h = h;
  h = c;
  mem_write8(hl(), h);
  l = c;
  l = mem_read8(hl());
  h = a;
  /* adc a,0x00 */
  /* nop */
  p28_L_60D7();
  return;
}

/* flash page 28 cpu 0x60D7 (offset 0x20D7) */
void p28_L_60D7(void) {
  set_de(0x8478);
  set_bc(0x0011);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(0x0100);
  mem_write16(0x844B, hl());
  set_hl(0x8478);
  p00_L_3C87();
  /* ei */
  return;
}

/* flash page 28 cpu 0x60ED (offset 0x20ED) */
void p28_L_60ED(void) {
  goto lab_p28_L_60ED;
  lab_p28_L_60E5: ;
  set_hl(0x8478);
  p00_L_3C87();
  /* ei */
  return;
  lab_p28_L_60ED: ;
  mem_write16(0x844B, de());
  set_de(0x8478);
  while (bc() != 0) { cpu_ldi(); }
  goto lab_p28_L_60E5;
}

/* flash page 28 cpu 0x60F8 (offset 0x20F8) */
void p28_L_60F8(void) {
  /* bit 0,(iy) */
  if (flag_z()) goto lab_p28_L_6100;
  a = 0;
  flag_logic(a);
  return;
  lab_p28_L_6100: ;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x04);
  if (flag_z()) return;
  flag_cmp(a, 0x17);
  if (flag_z()) return;
  flag_cmp(a, 0x02);
  return;
}

/* flash page 28 cpu 0x610C (offset 0x210C) */
void p28_L_610C(void) {
  p28_L_60F8();
  if (flag_nz()) return;
  p28_L_6223();
  if (flag_z()) return;
  p28_L_6114();
  return;
}

/* flash page 28 cpu 0x6114 (offset 0x2114) */
void p28_L_6114(void) {
  p28_L_6144();
  if (flag_nz()) goto lab_p28_L_612F;
  lab_p28_L_6119: ;
  p00_L_2DDB();
  if (flag_c()) { p28_L_61F5(); return; }
  /* bit 0,(iy) */
  if (flag_nz()) goto lab_p28_L_612A;
  p28_L_4B12();
  if (flag_z()) goto lab_p28_L_6119;
  lab_p28_L_612A: ;
  p28_L_6215();
  goto lab_p28_L_6135;
  lab_p28_L_612F: ;
  p28_L_6237();
  if (flag_z()) { p28_L_61F5(); return; }
  lab_p28_L_6135: ;
  p28_L_6190();
  p28_L_61FE();
  p00_L_3CF3();
  if (flag_m()) p00_L_2DED();
  p28_L_6259();
  return;
}

/* flash page 28 cpu 0x6144 (offset 0x2144) */
void p28_L_6144(void) {
  p28_L_6206();
  /* bit 0,(iy) */
  if (flag_nz()) goto lab_p28_L_6153;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x02);
  if (flag_nz()) return;
  lab_p28_L_6153: ;
  p00_L_1135();
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x6158 (offset 0x2158) */
void p28_L_6158(void) {
  p28_L_60F8();
  if (flag_nz()) return;
  p28_L_6223();
  if (flag_z()) return;
  p28_L_6144();
  if (flag_nz()) goto lab_p28_L_617B;
  lab_p28_L_6165: ;
  p00_L_2DD5();
  if (flag_c()) { p28_L_61F5(); return; }
  /* bit 0,(iy) */
  if (flag_nz()) goto lab_p28_L_6176;
  p28_L_4B12();
  if (flag_z()) goto lab_p28_L_6165;
  lab_p28_L_6176: ;
  p28_L_6215();
  goto lab_p28_L_6181;
  lab_p28_L_617B: ;
  p28_L_621A();
  if (flag_z()) { p28_L_61F5(); return; }
  lab_p28_L_6181: ;
  p28_L_6190();
  p28_L_61FE();
  p00_L_3CDB();
  if (flag_nc()) p00_L_2DED();
  p28_L_6259();
  return;
}

/* flash page 28 cpu 0x6190 (offset 0x2190) */
void p28_L_6190(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = 0x20;
  p00_L_3C6F();
  /* ei */
  p00_L_1135();
  p28_L_619D();
  return;
}

/* flash page 28 cpu 0x619D (offset 0x219D) */
void p28_L_619D(void) {
  a = 0xD0;
  p28_L_619F();
  return;
}

/* flash page 28 cpu 0x619F (offset 0x219F) */
void p28_L_619F(void) {
  cpu_push_af();
  /* bit 0,(iy) */
  if (flag_nz()) goto lab_p28_L_61B1;
  a = mem_read8(0x8672);
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p28_L_61B3;
  flag_cmp(a, 0x17);
  if (flag_z()) goto lab_p28_L_61B3;
  lab_p28_L_61B1: ;
  cpu_pop_af();
  return;
  lab_p28_L_61B3: ;
  p00_L_2DE1();
  p28_L_4B12();
  if (flag_z()) goto lab_p28_L_61B1;
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  cpu_pop_af();
  p00_L_3C6F();
  /* ei */
  return;
}

/* flash page 28 cpu 0x61C5 (offset 0x21C5) */
void p28_L_61C5(void) {
  flag_cmp(a, 0x01);
  a = 0x40;
  if (flag_nz()) goto lab_p28_L_61D2;
  a = 0xFF;
  mem_write8(0x85D2, a);
  a = 0x5D;
  lab_p28_L_61D2: ;
  mem_write8(0x85D1, a);
  p00_L_3D2F();
  p28_L_61D8();
  return;
}

/* flash page 28 cpu 0x61D8 (offset 0x21D8) */
void p28_L_61D8(void) {
  p28_L_621A();
  if (flag_z()) return;
  p28_L_6206();
  lab_p28_L_61DF: ;
  p00_L_2DED();
  p28_L_619D();
  p00_L_3CD5();
  p00_L_3CCF();
  if (flag_nc()) { p28_L_61F5(); return; }
  p28_L_621A();
  if (flag_nz()) goto lab_p28_L_61DF;
  p00_L_3D29();
  p28_L_61F5();
  return;
}

/* flash page 28 cpu 0x61F5 (offset 0x21F5) */
void p28_L_61F5(void) {
  set_hl(0x8499);
  set_de(0x85D0);
  p00_L_1183();
  return;
}

/* flash page 28 cpu 0x61FE (offset 0x21FE) */
void p28_L_61FE(void) {
  goto lab_p28_L_61FE;
  lab_p28_L_61FB: ;
  p00_L_1183();
  return;
  lab_p28_L_61FE: ;
  set_de(0x8478);
  set_hl(0x8481);
  goto lab_p28_L_620C;
  lab_p28_L_620C: ;
  a = 0;
  flag_logic(a);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl(0x85D0);
  goto lab_p28_L_61FB;
}

/* flash page 28 cpu 0x6206 (offset 0x2206) */
void p28_L_6206(void) {
  goto lab_p28_L_6206;
  lab_p28_L_61FB: ;
  p00_L_1183();
  return;
  lab_p28_L_6206: ;
  set_de(0x8499);
  set_hl(0x84A2);
  a = 0;
  flag_logic(a);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  set_hl(0x85D0);
  goto lab_p28_L_61FB;
}

/* flash page 28 cpu 0x6215 (offset 0x2215) */
void p28_L_6215(void) {
  goto lab_p28_L_6215;
  lab_p28_L_61F8: ;
  set_de(0x85D0);
  p00_L_1183();
  return;
  lab_p28_L_6215: ;
  set_hl(0x8478);
  goto lab_p28_L_61F8;
}

/* flash page 28 cpu 0x621A (offset 0x221A) */
void p28_L_621A(void) {
  p28_L_61FE();
  p28_L_6228();
  p28_L_6215();
  p28_L_6223();
  return;
}

/* flash page 28 cpu 0x6223 (offset 0x2223) */
void p28_L_6223(void) {
  a = mem_read8(0x85D1);
  a = (uint8_t)(a + 1);
  return;
}

/* flash page 28 cpu 0x6228 (offset 0x2228) */
void p28_L_6228(void) {
  p00_L_2DD5();
  if (flag_c()) goto lab_p28_L_622E;
  return;
  lab_p28_L_622E: ;
  p28_L_61FE();
  a = 0xFF;
  mem_write8(0x8479, a);
  return;
}

/* flash page 28 cpu 0x6237 (offset 0x2237) */
void p28_L_6237(void) {
  p28_L_61FE();
  p28_L_6246();
  p28_L_6215();
  a = mem_read8(0x85D1);
  flag_cmp(a, 0x40);
  return;
}

/* flash page 28 cpu 0x6246 (offset 0x2246) */
void p28_L_6246(void) {
  p00_L_2DDB();
  if (flag_c()) goto lab_p28_L_624E;
  return;
  lab_p28_L_624E: ;
  p00_L_166E();
  return;
}

/* flash page 28 cpu 0x6252 (offset 0x2252) */
void p28_L_6252(void) {
  p28_L_6223();
  if (flag_z()) return;
  p00_L_3D2F();
  p28_L_6259();
  return;
}

/* flash page 28 cpu 0x6259 (offset 0x2259) */
void p28_L_6259(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = 0x05;
  p00_L_3C6F();
  /* ei */
  p28_L_61FE();
  a = 0xDF;
  p28_L_619F();
  return;
}

/* flash page 28 cpu 0x626B (offset 0x226B) */
void p28_L_626B(void) {
  p00_L_3D05();
  p28_L_626E();
  return;
}

/* flash page 28 cpu 0x626E (offset 0x226E) */
void p28_L_626E(void) {
  p00_L_3D7D();
  p28_L_6271();
  return;
}

/* flash page 28 cpu 0x6271 (offset 0x2271) */
void p28_L_6271(void) {
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  p28_L_6275();
  return;
}

/* flash page 28 cpu 0x6275 (offset 0x2275) */
void p28_L_6275(void) {
  set_hl(0x8673);
  a = mem_read8(hl());
  mem_write8(hl(), 0x00);
  return;
}

/* flash page 28 cpu 0x62CF (offset 0x22CF) */
void p28_L_62CF(void) {
  a = mem_read8(0x8672);
  flag_cmp(a, 0x0A);
  lab_p28_L_62D4: ;
  if (flag_z()) { p00_L_2565(); return; }
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p28_L_62E5;
  set_hl(0x8670);
  flag_set_z((mem_read8(hl()) & (1u << 1)) == 0);
  if (flag_nz()) { p00_L_09CA(); return; }
  goto lab_p28_L_62D4;
  lab_p28_L_62E5: ;
  a = 0;
  flag_logic(a);
  cpu_push_af();
  p28_L_6329();
  p28_L_4F79();
  a = 0x01;
  b = 0x36;
  p00_L_2E17();
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x6313 (offset 0x2313) */
void p28_L_6313(void) {
  p00_L_02AD();
  p28_L_4393();
  p28_L_4332();
  a = mem_read8(0x8675);
  return;
}

/* flash page 28 cpu 0x6320 (offset 0x2320) */
void p28_L_6320(void) {
  goto lab_p28_L_6320;
  lab_p28_L_6319: ;
  p28_L_4332();
  a = mem_read8(0x8675);
  return;
  lab_p28_L_6320: ;
  p00_L_02AD();
  /* ei */
  p28_L_439A();
  goto lab_p28_L_6319;
}

/* flash page 28 cpu 0x6329 (offset 0x2329) */
void p28_L_6329(void) {
  p28_L_6B25();
  a = 0x03;
  link_out(a); /* stub */
  p00_L_0B93();
  set_hl(0xFFFF);
  lab_p28_L_6336: ;
  a = 0x04;
  lab_p28_L_6338: ;
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p28_L_6338;
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_6336;
  p00_L_0BA2();
  a = 0x00;
  link_out(a); /* stub */
  p28_L_4F79();
  return;
}

/* flash page 28 cpu 0x634F (offset 0x234F) */
void p28_L_634F(void) {
  set_hl(0x635D);
  p00_L_25A2();
  a = 0x01;
  p28_L_4068();
  p00_L_25C8();
  return;
}

/* flash page 28 cpu 0x635E (offset 0x235E) */
void p28_L_635E(void) {
  p00_L_188D();
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  cpu_pop_hl();
  lab_p28_L_6367: ;
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6373;
  cpu_push_bc();
  p28_L_637A();
  goto lab_p28_L_6367;
  lab_p28_L_6373: ;
  cpu_sbc_hl_de();
  if (flag_z()) return;
  cpu_ex_de_hl();
  p00_L_1FB8();
  return;
}

/* flash page 28 cpu 0x637A (offset 0x237A) */
void p28_L_637A(void) {
  a = mem_read8(hl());
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_push_hl();
  p00_L_0033();
  set_bc(0xFC00);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  a = l;
  a = (uint8_t)(a + 0x80);
  mem_write8(de(), a);
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1187();
  return;
}

/* flash page 28 cpu 0x6393 (offset 0x2393) */
void p28_L_6393(void) {
  l = 0x82;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  l = 0x95;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 1)) == 0);
  if (flag_nz()) return;
  l = 0x83;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 3)) == 0);
  if (flag_nz()) return;
  l = 0x03;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 4)) == 0);
  if (flag_nz()) return;
  l = 0x73;
  return;
}

/* flash page 28 cpu 0x63C3 (offset 0x23C3) */
void p28_L_63C3(void) {
  /* add a,(hl) */
  a = 0x15;
  set_hl(0x0002);
  p28_L_404C();
  set_hl(0xFE66);
  lab_p28_L_63CF: ;
  p00_L_2F9D();
  if (flag_c()) goto lab_p28_L_63F4;
  cpu_push_hl();
  p00_L_1179();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x62);
  if (flag_z()) goto lab_p28_L_63F3;
  p28_L_6A79();
  cpu_push_de();
  p28_L_4C6C();
  cpu_pop_de();
  if (flag_z()) goto lab_p28_L_63F3;
  p00_L_1037();
  cpu_ex_de_hl();
  p28_L_6A62();
  p28_L_4006();
  lab_p28_L_63F3: ;
  cpu_pop_hl();
  lab_p28_L_63F4: ;
  set_de(mem_read16(0x982E));
  p00_L_192A();
  if (flag_nz()) goto lab_p28_L_63CF;
  p00_L_1295();
  lab_p28_L_6400: ;
  a = 0x14;
  mem_write8(0x8478, a);
  p00_L_2DAB();
  if (flag_c()) goto lab_p28_L_641B;
  a = d;
  cpu_push_af();
  p00_L_2DC3();
  cpu_pop_de();
  e = c;
  a = 0x24;
  mem_write8(0x8478, a);
  p28_L_4006();
  goto lab_p28_L_6400;
  lab_p28_L_641B: ;
  p28_L_418C();
  p28_L_58A6();
  return;
}

/* flash page 28 cpu 0x6421 (offset 0x2421) */
void p28_L_6421(void) {
  goto lab_p28_L_6421;
  lab_p28_L_58ED: ;
  p28_L_6530();
  set_hl(0x59B8);
  p00_L_25A2();
  a = mem_read8(0x8681);
  flag_cmp(a, 0x25);
  if (flag_nz()) { p00_L_255F(); return; }
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  set_de(0x0A10);
  os_bcall(0x8027);
  if (flag_z()) { p00_L_255F(); return; }
  os_bcall(0x8081);
  p00_L_3D05();
  p00_L_255F();
  return;
  lab_p28_L_6421: ;
  b = a;
  a = mem_read8(0x8674);
  flag_cmp(a, 0x08);
  if (flag_z()) goto lab_p28_L_58ED;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p28_L_6437;
  flag_cmp(a, 0x23);
  if (flag_z()) goto lab_p28_L_6437;
  flag_cmp(a, 0x13);
  if (flag_nz()) { p00_L_2565(); return; }
  lab_p28_L_6437: ;
  a = b;
  return;
}

/* flash page 28 cpu 0x6439 (offset 0x2439) */
void p28_L_6439(void) {
  cpu_push_af();
  a = mem_read8(0x8A0B);
  a = a & 0xE1;
  flag_logic(a);
  mem_write8(0x8A0B, a);
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x6444 (offset 0x2444) */
void p28_L_6444(void) {
  b = a;
  a = mem_read8(0x8A0B);
  a = a & 0x0E;
  flag_logic(a);
  a = b;
  return;
}

/* flash page 28 cpu 0x644C (offset 0x244C) */
void p28_L_644C(void) {
  cpu_push_de();
  cpu_push_bc();
  cpu_push_hl();
  h = 0x09;
  p28_L_4192();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_de();
  mem_write16(0x84DB, de());
  cpu_push_bc();
  p28_L_432F();
  cpu_pop_bc();
  set_hl(0x8670);
  a = mem_read8(0x8675);
  return;
}

/* flash page 28 cpu 0x6467 (offset 0x2467) */
void p28_L_6467(void) {
  lab_p28_L_6467: ;
  mem_write8(0x82A3, a);
  p28_L_644C();
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p28_L_6477;
  flag_cmp(a, 0x92);
  if (flag_nz()) { p00_L_2565(); return; }
  return;
  lab_p28_L_6477: ;
  set_hl(mem_read16(0x8676));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nz()) { p00_L_2565(); return; }
  set_hl(0x8000);
  p28_L_64BB();
  p28_L_42F2();
  set_de(mem_read16(0x84DB));
  set_bc(mem_read16(0x8676));
  set_hl(0x8000);
  a = mem_read8(0x82A3);
  os_bcall(0x80C9);
  set_hl(mem_read16(0x84DB));
  set_bc(mem_read16(0x8676));
  set_hl((uint16_t)(hl() + bc()));
  a = 0x80;
  flag_cmp(a, h);
  if (flag_nz()) goto lab_p28_L_64B1;
  a = mem_read8(0x82A3);
  a = (uint8_t)(a + 1);
  mem_write8(0x82A3, a);
  set_hl(0x4000);
  lab_p28_L_64B1: ;
  cpu_ex_de_hl();
  set_bc(0x0100);
  a = mem_read8(0x82A3);
  goto lab_p28_L_6467;
}

/* flash page 28 cpu 0x64BB (offset 0x24BB) */
void p28_L_64BB(void) {
  set_bc(mem_read16(0x8676));
  set_de(0x0000);
  mem_write16(0x8678, de());
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) { p28_L_64D6(); return; }
  lab_p28_L_64CA: ;
  p00_L_171E();
  if (flag_nz()) { p00_L_2565(); return; }
  /* di */
  p28_L_651A();
  if (flag_nz()) goto lab_p28_L_64CA;
  p28_L_64D6();
  return;
}

/* flash page 28 cpu 0x64D6 (offset 0x24D6) */
void p28_L_64D6(void) {
  os_bcall(0x807B);
  cpu_push_af();
  os_bcall(0x807B);
  b = a;
  cpu_pop_af();
  p28_L_64DF();
  return;
}

/* flash page 28 cpu 0x64DF (offset 0x24DF) */
void p28_L_64DF(void) {
  c = a;
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_64FD;
  a = hw_in(PORT_SE_STATUS);
  a = a & 0x01;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_64FD;
  a = 0;
  flag_logic(a);
  hw_out(PORT_SE_STATUS, a);
  set_de(0x00FE);
  lab_p28_L_64F2: ;
  set_de((uint16_t)(de() - 1));
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_64F2;
  a = 0x01;
  hw_out(PORT_SE_STATUS, a);
  goto lab_p28_L_6505;
  lab_p28_L_64FD: ;
  set_de(0x0100);
  lab_p28_L_6500: ;
  set_de((uint16_t)(de() - 1));
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_6500;
  lab_p28_L_6505: ;
  set_hl(mem_read16(0x8678));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nz()) goto lab_p28_L_650E;
  return;
  lab_p28_L_650E: ;
  set_hl(mem_read16(0x8676));
  cpu_push_hl();
  h = 0x5A;
  p28_L_4192();
  p00_L_2565();
  return;
}

/* flash page 28 cpu 0x651A (offset 0x251A) */
void p28_L_651A(void) {
  cpu_push_bc();
  os_bcall(0x807B);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  b = 0x00;
  set_hl(mem_read16(0x8678));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x8678, hl());
  cpu_ex_de_hl();
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x6530 (offset 0x2530) */
void p28_L_6530(void) {
  a = 0x09;
  p00_L_3F39();
  if (flag_nc()) p00_L_3F3F();
  if (flag_c()) goto lab_p28_L_653D;
  p00_L_2D21();
  lab_p28_L_653D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x08)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_34C5();
  p00_L_3EFD();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) | (1u << 4)));
  p00_L_073A();
  a = mem_read8(0x859A);
  flag_cmp(a, 0x40);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) | (1u << 5)));
  return;
}

/* flash page 28 cpu 0x656B (offset 0x256B) */
void p28_L_656B(void) {
  cpu_push_hl();
  cpu_push16(ix);
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p00_L_3D05();
  set_hl(0x272D);
  a = 0x3F;
  p28_L_6586();
  p00_L_3CD5();
  ix = cpu_pop16();
  cpu_pop_hl();
  return;
}

/* flash page 28 cpu 0x6586 (offset 0x2586) */
void p28_L_6586(void) {
  p28_L_658D();
  p00_L_3C87();
  return;
}

/* flash page 28 cpu 0x658D (offset 0x258D) */
void p28_L_658D(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  return;
}

/* flash page 28 cpu 0x6595 (offset 0x2595) */
void p28_L_6595(void) {
  p28_L_658D();
  set_de(0x838D);
  set_bc(0x0010);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 28 cpu 0x65A1 (offset 0x25A1) */
void p28_L_65A1(void) {
  cpu_push_bc();
  cpu_push_af();
  cpu_push_hl();
  cpu_push16(ix);
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + 1));
  p28_L_6D77();
  os_bcall(0x8051);
  cpu_push_af();
  a = a & 0xF0;
  flag_logic(a);
  c = a;
  cpu_pop_af();
  a = a ^ c;
  flag_logic(a);
  mem_write8(0x838D, a);
  set_hl((uint16_t)(hl() + 1));
  c = a;
  b = 0x00;
  p28_L_6D77();
  set_de(0x838E);
  os_bcall(0x8054);
  set_hl(0x844C);
  mem_write8(hl(), 0x00);
  set_hl(0x838D);
  p00_L_3C93();
  ix = cpu_pop16();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_pop_bc();
  return;
}

/* flash page 28 cpu 0x65D5 (offset 0x25D5) */
void p28_L_65D5(void) {
  cpu_push_bc();
  cpu_push_af();
  cpu_push_hl();
  cpu_push16(ix);
  cpu_push_af();
  set_hl(0x4000);
  set_de(0x8040);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p28_L_6608;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x805A);
  a = c;
  mem_write8(0x838D, a);
  cpu_pop_af();
  set_de(0x838E);
  os_bcall(0x8054);
  set_hl(0x844C);
  mem_write8(hl(), 0x00);
  set_hl(0x838D);
  p00_L_3C93();
  lab_p28_L_6602: ;
  ix = cpu_pop16();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_pop_bc();
  return;
  lab_p28_L_6608: ;
  cpu_pop_af();
  goto lab_p28_L_6602;
}

/* flash page 28 cpu 0x660B (offset 0x260B) */
void p28_L_660B(void) {
  p00_L_2C19();
  if (flag_nz()) return;
  a = 0x28;
  mem_write8(0x867F, a);
  a = 0x73;
  mem_write8(0x8674, a);
  set_hl(0x0100);
  mem_write16(0x867D, hl());
  p28_L_6D6E();
  cpu_push_af();
  set_hl(0x4001);
  os_bcall(0x8051);
  c = a;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8051);
  b = a;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  mem_write16(0x8683, bc());
  cpu_push_bc();
  set_hl(0x4000);
  cpu_push_hl();
  cpu_push_af();
  p28_L_6673();
  return;
}

/* flash page 28 cpu 0x6640 (offset 0x2640) */
void p28_L_6640(void) {
  os_bcall(0x8057);
  p00_L_2BE9();
  cpu_push_hl();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + 1));
  p28_L_6D77();
  os_bcall(0x805A);
  /* adc hl,bc */
  set_hl((uint16_t)(hl() + 1));
  p28_L_6D77();
  os_bcall(0x805A);
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_bc();
  p28_L_665A();
  return;
}

/* flash page 28 cpu 0x665A (offset 0x265A) */
void p28_L_665A(void) {
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_af();
  a = 0x25;
  mem_write8(0x867F, a);
  a = 0x73;
  mem_write8(0x8674, a);
  set_hl(0x00E8);
  mem_write16(0x867D, hl());
  p28_L_6673();
  return;
}

/* flash page 28 cpu 0x6673 (offset 0x2673) */
void p28_L_6673(void) {
  p28_L_4047();
  cpu_pop_af();
  cpu_pop_hl();
  cpu_pop_bc();
  lab_p28_L_6679: ;
  cpu_push_bc();
  cpu_push_hl();
  mem_write8(0x82A3, a);
  p28_L_6320();
  a = mem_read8(0x8675);
  flag_cmp(a, 0x09);
  if (flag_nz()) { p00_L_2565(); return; }
  p28_L_42F2();
  set_de(0x8000);
  set_bc(mem_read16(0x867D));
  a = mem_read8(0x82A3);
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_bc();
  os_bcall(0x8054);
  cpu_pop_bc();
  set_hl(0x8000);
  set_de(mem_read16(0x867D));
  p28_L_40C5();
  cpu_pop_hl();
  set_bc(mem_read16(0x867D));
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  cpu_ex_de_hl();
  if (flag_c()) goto lab_p28_L_66CB;
  a = h;
  flag_cmp(a, 0x80);
  if (flag_nz()) goto lab_p28_L_66C6;
  set_hl(0x4000);
  a = mem_read8(0x82A3);
  a = (uint8_t)(a + 1);
  mem_write8(0x82A3, a);
  lab_p28_L_66C6: ;
  a = mem_read8(0x82A3);
  goto lab_p28_L_6679;
  lab_p28_L_66CB: ;
  p28_L_6320();
  a = mem_read8(0x8675);
  flag_cmp(a, 0x09);
  if (flag_nz()) { p00_L_2565(); return; }
  p28_L_42F2();
  a = 0x92;
  mem_write8(0x8675, a);
  a = 0x73;
  mem_write8(0x8674, a);
  set_bc(0x0000);
  mem_write16(0x8676, bc());
  p28_L_41BA();
  p28_L_6320();
  a = mem_read8(0x8675);
  flag_cmp(a, 0x56);
  if (flag_z()) return;
  flag_cmp(a, 0x36);
  if (flag_z()) goto lab_p28_L_6764;
  p00_L_2565();
  return;
  lab_p28_L_675E: ;
  a = 0x02;
  mem_write8(0x8432, a);
  return;
  lab_p28_L_6764: ;
  p28_L_424C();
  a = mem_read8(0x867F);
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p28_L_675E;
  p00_L_25C8();
  a = mem_read8(0x867F);
  flag_cmp(a, 0x01);
  if (flag_z()) { p00_L_24F5(); return; }
  flag_cmp(a, 0x07);
  if (flag_z()) { p00_L_2539(); return; }
  flag_cmp(a, 0x08);
  if (flag_z()) { p00_L_2539(); return; }
  flag_cmp(a, 0x09);
  if (flag_z()) { p00_L_253D(); return; }
  flag_cmp(a, 0x0B);
  if (flag_z()) { p00_L_2541(); return; }
  flag_cmp(a, 0x01);
  if (flag_z()) { p28_L_4E18(); return; }
  p00_L_255F();
  return;
}

/* flash page 28 cpu 0x66FE (offset 0x26FE) */
void p28_L_66FE(void) {
  a = 0x15;
  mem_write16(0x84DB, hl());
  mem_write16(0x8676, de());
  h = a;
  p28_L_6B25();
  p28_L_6393();
  mem_write16(0x8674, hl());
  a = mem_read8(0x8672);
  flag_cmp(a, 0x08);
  p28_L_41BA();
  set_de(mem_read16(0x8676));
  set_hl(mem_read16(0x84DB));
  set_bc(0x0000);
  mem_write16(0x8678, bc());
  goto lab_p28_L_6734;
  lab_p28_L_6729: ;
  p00_L_171E();
  cpu_push_de();
  c = mem_read8(hl());
  p28_L_41A2();
  cpu_pop_de();
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() + 1));
  lab_p28_L_6734: ;
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_6729;
  /* di */
  set_hl(mem_read16(0x8678));
  a = l;
  cpu_push_hl();
  p28_L_4204();
  cpu_pop_af();
  p28_L_4204();
  p28_L_6320();
  flag_cmp(a, 0x56);
  if (flag_z()) goto lab_p28_L_6757;
  flag_cmp(a, 0x92);
  if (flag_z()) goto lab_p28_L_675A;
  flag_cmp(a, 0x36);
  if (flag_nz()) { p00_L_2565(); return; }
  goto lab_p28_L_6764;
  lab_p28_L_6757: ;
  a = 0;
  flag_logic(a);
  goto lab_p28_L_6760;
  lab_p28_L_675A: ;
  a = 0x01;
  goto lab_p28_L_6760;
  lab_p28_L_675E: ;
  a = 0x02;
  lab_p28_L_6760: ;
  mem_write8(0x8432, a);
  return;
  lab_p28_L_6764: ;
  p28_L_424C();
  a = mem_read8(0x867F);
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p28_L_675E;
  p00_L_25C8();
  a = mem_read8(0x867F);
  flag_cmp(a, 0x01);
  if (flag_z()) { p00_L_24F5(); return; }
  flag_cmp(a, 0x07);
  if (flag_z()) { p00_L_2539(); return; }
  flag_cmp(a, 0x08);
  if (flag_z()) { p00_L_2539(); return; }
  flag_cmp(a, 0x09);
  if (flag_z()) { p00_L_253D(); return; }
  flag_cmp(a, 0x0B);
  if (flag_z()) { p00_L_2541(); return; }
  flag_cmp(a, 0x01);
  if (flag_z()) { p28_L_4E18(); return; }
  p00_L_255F();
  return;
}

/* flash page 28 cpu 0x6786 (offset 0x2786) */
void p28_L_6786(void) {
  a = (uint8_t)(a - 1);
  h = (uint8_t)(h - 1);
  flag_cmp(a, 0x0B);
  if (flag_z()) { p00_L_2541(); return; }
  flag_cmp(a, 0x01);
  if (flag_z()) { p28_L_4E18(); return; }
  p00_L_255F();
  return;
}

/* flash page 28 cpu 0x6795 (offset 0x2795) */
void p28_L_6795(void) {
  set_bc(0x0000);
  mem_write16(0x83A5, bc());
  mem_write16(0x83A3, bc());
  cpu_push_af();
  a = 0xFF;
  mem_write8(0x83A4, a);
  cpu_pop_af();
  set_hl(0x4000);
  set_de(0x8080);
  cpu_push_af();
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p28_L_689B;
  cpu_pop_af();
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x8051);
  c = a;
  cpu_pop_af();
  p28_L_67BD();
  return;
  lab_p28_L_689B: ;
  return;
}

/* flash page 28 cpu 0x67BD (offset 0x27BD) */
void p28_L_67BD(void) {
  set_de(0x4000);
  set_hl(0x4000);
  cpu_push_de();
  cpu_push_bc();
  p28_L_67C5();
  return;
}

/* flash page 28 cpu 0x67C5 (offset 0x27C5) */
void p28_L_67C5(void) {
  goto lab_p28_L_67C5;
  lab_p28_L_675E: ;
  a = 0x02;
  mem_write8(0x8432, a);
  return;
  lab_p28_L_6764: ;
  p28_L_424C();
  a = mem_read8(0x867F);
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p28_L_675E;
  p00_L_25C8();
  a = mem_read8(0x867F);
  flag_cmp(a, 0x01);
  if (flag_z()) { p00_L_24F5(); return; }
  flag_cmp(a, 0x07);
  if (flag_z()) { p00_L_2539(); return; }
  flag_cmp(a, 0x08);
  if (flag_z()) { p00_L_2539(); return; }
  flag_cmp(a, 0x09);
  if (flag_z()) { p00_L_253D(); return; }
  flag_cmp(a, 0x0B);
  if (flag_z()) { p00_L_2541(); return; }
  flag_cmp(a, 0x01);
  if (flag_z()) { p28_L_4E18(); return; }
  p00_L_255F();
  return;
  lab_p28_L_67C5: ;
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_af();
  a = 0x24;
  mem_write8(0x867F, a);
  a = 0x73;
  mem_write8(0x8674, a);
  a = b;
  mem_write8(0x8685, a);
  mem_write16(0x8683, de());
  a = 0;
  flag_logic(a);
  mem_write8(0x8680, a);
  mem_write8(0x8681, a);
  mem_write8(0x8686, a);
  a = 0x04;
  mem_write8(0x8682, a);
  set_hl(0x0080);
  mem_write16(0x867D, hl());
  p28_L_4047();
  p28_L_6320();
  a = mem_read8(0x8675);
  flag_cmp(a, 0x36);
  if (flag_z()) goto lab_p28_L_6764;
  flag_cmp(a, 0x09);
  if (flag_nz()) { p00_L_2565(); return; }
  p28_L_42F2();
  set_de(0x8000);
  cpu_pop_af();
  set_bc(0x0080);
  cpu_pop_hl();
  cpu_push_af();
  mem_write8(0x822F, a);
  cpu_push_hl();
  cpu_push_bc();
  os_bcall(0x8054);
  cpu_pop_bc();
  set_hl(0x8000);
  set_de(0x0080);
  a = 0x00;
  cpu_push_hl();
  set_hl(0x83A3);
  cpu_cp_hl();
  cpu_pop_hl();
  if (flag_nz()) goto lab_p28_L_6841;
  a = mem_read8(0x822F);
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p00_L_2C2B();
  p28_L_689C();
  lab_p28_L_6841: ;
  p28_L_66FE();
  a = mem_read8(0x8432);
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p28_L_6853;
  cpu_pop_hl();
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_push_af();
  goto lab_p28_L_689A;
  lab_p28_L_6853: ;
  cpu_pop_hl();
  set_bc(0x0080);
  /* adc hl,bc */
  cpu_push_hl();
  cpu_pop_de();
  a = 0xFF;
  mem_write8(0x83A3, a);
  set_bc(0x0080);
  p28_L_6E37();
  if (flag_c()) goto lab_p28_L_6883;
  set_hl(mem_read16(0x83A5));
  p28_L_6E31();
  set_hl((uint16_t)(hl() + bc()));
  p28_L_6E31();
  mem_write16(0x83A5, hl());
  a = mem_read8(0x83A5);
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p28_L_6883;
  cpu_pop_af();
  cpu_pop_bc();
  cpu_push_de();
  cpu_pop_hl();
  goto lab_p28_L_67C5;
  lab_p28_L_6883: ;
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  cpu_pop_de();
  cpu_push_af();
  c = (uint8_t)(c - 1);
  a = 0x00;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_689A;
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  set_hl(0x0000);
  mem_write16(0x83A5, hl());
  p28_L_67BD();
  return;
  lab_p28_L_689A: ;
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x689C (offset 0x289C) */
void p28_L_689C(void) {
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0;
  flag_logic(a);
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p00_rst00_boot(); return; }
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x68B2 (offset 0x28B2) */
void p28_L_68B2(void) {
  set_hl(0x4000);
  set_de(0x8000);
  set_bc(0x0100);
  goto lab_p28_L_68D0;
  lab_p28_L_68D0: ;
  a = 0x7A;
  os_bcall(0x8054);
  cpu_push_hl();
  set_bc(0x0100);
  mem_write16(0x867D, bc());
  a = 0x23;
  mem_write8(0x867F, a);
  a = 0x80;
  mem_write8(0x8682, a);
  a = 0x73;
  mem_write8(0x8674, a);
  set_hl(0x4000);
  mem_write16(0x8683, hl());
  a = 0x1A;
  mem_write8(0x8685, a);
  p28_L_4047();
  p28_L_6313();
  a = mem_read8(0x8675);
  flag_cmp(a, 0x36);
  if (flag_z()) { p28_L_6918(); return; }
  flag_cmp(a, 0x09);
  if (flag_nz()) { p00_L_255F(); return; }
  p28_L_42F2();
  set_hl(0x8000);
  set_de(0x0100);
  p28_L_66FE();
  cpu_pop_hl();
  return;
}

/* flash page 28 cpu 0x68BD (offset 0x28BD) */
void p28_L_68BD(void) {
  set_hl(0x4100);
  set_de(0x8000);
  cpu_ex_de_hl();
  a = 0x02;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  a = 0x0D;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  set_bc(0x00FE);
  a = 0x7A;
  os_bcall(0x8054);
  cpu_push_hl();
  set_bc(0x0100);
  mem_write16(0x867D, bc());
  a = 0x23;
  mem_write8(0x867F, a);
  a = 0x80;
  mem_write8(0x8682, a);
  a = 0x73;
  mem_write8(0x8674, a);
  set_hl(0x4000);
  mem_write16(0x8683, hl());
  a = 0x1A;
  mem_write8(0x8685, a);
  p28_L_4047();
  p28_L_6313();
  a = mem_read8(0x8675);
  flag_cmp(a, 0x36);
  if (flag_z()) { p28_L_6918(); return; }
  flag_cmp(a, 0x09);
  if (flag_nz()) { p00_L_255F(); return; }
  p28_L_42F2();
  set_hl(0x8000);
  set_de(0x0100);
  p28_L_66FE();
  cpu_pop_hl();
  return;
}

/* flash page 28 cpu 0x6918 (offset 0x2918) */
void p28_L_6918(void) {
  p28_L_424C();
  p00_L_25C8();
  p28_L_4F79();
  p28_L_4E18();
  return;
}

/* flash page 28 cpu 0x6924 (offset 0x2924) */
void p28_L_6924(void) {
  cpu_push_hl();
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p28_L_6937;
  set_hl(0x4000);
  mem_write16(0x839F, hl());
  set_hl(0x0000);
  set_de(0x0000);
  goto lab_p28_L_6943;
  lab_p28_L_6937: ;
  set_hl(0x8000);
  mem_write16(0x839F, hl());
  set_hl(0x4000);
  set_de(0x4000);
  lab_p28_L_6943: ;
  mem_write8(0x83A1, a);
  lab_p28_L_6946: ;
  cpu_push_hl();
  a = 0x23;
  mem_write8(0x867F, a);
  a = 0x73;
  mem_write8(0x8674, a);
  a = 0x00;
  mem_write8(0x8682, a);
  a = mem_read8(0x83A1);
  a = a & 0x1F;
  flag_logic(a);
  mem_write8(0x8685, a);
  mem_write16(0x8683, de());
  set_hl(0x0100);
  mem_write16(0x867D, hl());
  p28_L_4047();
  p28_L_6313();
  a = mem_read8(0x8675);
  flag_cmp(a, 0x09);
  if (flag_nz()) { p00_L_255F(); return; }
  p28_L_42F2();
  set_de(0x8000);
  set_bc(0x0100);
  cpu_pop_hl();
  a = mem_read8(0x83A1);
  mem_write8(0x822F, a);
  cpu_push_hl();
  cpu_push_bc();
  os_bcall(0x8054);
  a = mem_read8(0x83A1);
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p28_L_69A2;
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_bc();
  flag_cmp(a, h);
  if (flag_nz()) goto lab_p28_L_69A2;
  set_hl(0x8056);
  a = 0xFF;
  mem_write8(hl(), a);
  a = mem_read8(0x83A1);
  lab_p28_L_69A2: ;
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x1A);
  if (flag_nz()) goto lab_p28_L_69B4;
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_bc();
  a = 0x42;
  flag_cmp(a, h);
  if (flag_c()) goto lab_p28_L_69B4;
  if (flag_nz()) p28_L_6A1E();
  lab_p28_L_69B4: ;
  cpu_pop_bc();
  set_hl(0x8000);
  set_de(0x0100);
  a = 0x15;
  p28_L_40D1();
  cpu_pop_hl();
  set_bc(0x0100);
  set_hl((uint16_t)(hl() + bc()));
  d = h;
  e = l;
  a = mem_read8(0x83A0);
  flag_cmp(a, h);
  if (flag_nz()) goto lab_p28_L_6946;
  a = mem_read8(0x83A1);
  cpu_pop_hl();
  return;
}

/* flash page 28 cpu 0x69D3 (offset 0x29D3) */
void p28_L_69D3(void) {
  goto lab_p28_L_69D3;
  lab_p28_L_675E: ;
  a = 0x02;
  mem_write8(0x8432, a);
  return;
  lab_p28_L_6764: ;
  p28_L_424C();
  a = mem_read8(0x867F);
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p28_L_675E;
  p00_L_25C8();
  a = mem_read8(0x867F);
  flag_cmp(a, 0x01);
  if (flag_z()) { p00_L_24F5(); return; }
  flag_cmp(a, 0x07);
  if (flag_z()) { p00_L_2539(); return; }
  flag_cmp(a, 0x08);
  if (flag_z()) { p00_L_2539(); return; }
  flag_cmp(a, 0x09);
  if (flag_z()) { p00_L_253D(); return; }
  flag_cmp(a, 0x0B);
  if (flag_z()) { p00_L_2541(); return; }
  flag_cmp(a, 0x01);
  if (flag_z()) { p28_L_4E18(); return; }
  p00_L_255F();
  return;
  lab_p28_L_69D3: ;
  p28_L_68B2();
  set_hl(0x6A0F);
  lab_p28_L_69D9: ;
  a = mem_read8(hl());
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p28_L_69EB;
  p00_L_24A9();
  if (flag_z()) goto lab_p28_L_69E5;
  a = a & 0x1F;
  flag_logic(a);
  lab_p28_L_69E5: ;
  p28_L_6924();
  set_hl((uint16_t)(hl() + 1));
  goto lab_p28_L_69D9;
  lab_p28_L_69EB: ;
  p28_L_68BD();
  p28_L_6393();
  mem_write16(0x8674, hl());
  /* di */
  a = 0x92;
  mem_write8(0x8675, a);
  p28_L_41BA();
  /* ei */
  p28_L_6313();
  a = mem_read8(0x8675);
  flag_cmp(a, 0x56);
  if (flag_z()) return;
  flag_cmp(a, 0x36);
  if (flag_z()) goto lab_p28_L_6764;
  p00_L_2565();
  return;
}

/* flash page 28 cpu 0x6A1E (offset 0x2A1E) */
void p28_L_6A1E(void) {
  set_hl(0x8000);
  set_bc(0x0100);
  a = 0xFF;
  lab_p28_L_6A26: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  a = 0xFF;
  if (flag_nz()) goto lab_p28_L_6A26;
  return;
}

/* flash page 28 cpu 0x6A30 (offset 0x2A30) */
void p28_L_6A30(void) {
  a = mem_read8(0x8A0B);
  a = a & 0x1E;
  flag_logic(a);
  /* scf */
  if (flag_nz()) return;
  a = mem_read8(0x8688);
  flag_cmp(a, 0x04);
  return;
}

/* flash page 28 cpu 0x6A3D (offset 0x2A3D) */
void p28_L_6A3D(void) {
  /* scf */
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 3)) == 0);
  if (flag_z()) return;
  p28_L_6A43();
  return;
}

/* flash page 28 cpu 0x6A43 (offset 0x2A43) */
void p28_L_6A43(void) {
  cpu_push_hl();
  cpu_push_af();
  set_hl(mem_read16(0x848C));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6A5E;
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x14);
  if (flag_c()) goto lab_p28_L_6A58;
  lab_p28_L_6A53: ;
  cpu_pop_af();
  cpu_pop_hl();
  /* scf */
  /* ccf */
  return;
  lab_p28_L_6A58: ;
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_6A53;
  lab_p28_L_6A5E: ;
  cpu_pop_af();
  cpu_pop_hl();
  /* scf */
  return;
}

/* flash page 28 cpu 0x6A62 (offset 0x2A62) */
void p28_L_6A62(void) {
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p28_L_6A75;
  a = mem_read8(0x848B);
  p00_L_3267();
  d = b;
  e = c;
  p00_L_1037();
  p00_L_20F8();
  return;
  lab_p28_L_6A75: ;
  p00_L_210A();
  return;
}

/* flash page 28 cpu 0x6A79 (offset 0x2A79) */
void p28_L_6A79(void) {
  p00_L_19ED();
  p00_L_2EA7();
  mem_write16(0x848C, hl());
  cpu_push_af();
  a = b;
  mem_write8(0x848B, a);
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x6A89 (offset 0x2A89) */
void p28_L_6A89(void) {
  p00_L_1037();
  flag_cmp(a, 0x14);
  if (flag_nc()) return;
  a = (uint8_t)(a - 0x0F);
  /* ccf */
  return;
}

/* flash page 28 cpu 0x6A93 (offset 0x2A93) */
void p28_L_6A93(void) {
  set_bc(0x000F);
  set_hl(0x867D);
  mem_write8(hl(), a);
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_6AAE;
  flag_set_z((mem_read8((uint16_t)(iy + 0x3E)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p28_L_6ABA;
  a = hw_in(PORT_SE_STATUS);
  a = a & 0x01;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6AAE;
  set_bc(0x0020);
  lab_p28_L_6AAE: ;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  cpu_cp_hl();
  if (flag_nz()) return;
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_6AAE;
  return;
  lab_p28_L_6ABA: ;
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x6B25 (offset 0x2B25) */
void p28_L_6B25(void) {
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 2)));
  return;
}

/* flash page 28 cpu 0x6B2A (offset 0x2B2A) */
void p28_L_6B2A(void) {
  cpu_push_af();
  set_hl(0x6B42);
  p00_L_25A2();
  set_hl(0x8773);
  mem_write16(0x8674, hl());
  mem_write8(0x8676, a);
  p28_L_41BA();
  p00_L_25C8();
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x6B48 (offset 0x2B48) */
void p28_L_6B48(void) {
  p28_L_6B25();
  p28_L_424C();
  p28_L_6421();
  set_hl(0x867F);
  a = mem_read8(hl());
  p00_rst20();
  return;
}

/* flash page 28 cpu 0x6B57 (offset 0x2B57) */
void p28_L_6B57(void) {
  cpu_push_de();
  p28_L_6F33();
  p28_L_432F();
  cpu_pop_de();
  set_hl(0x8670);
  a = mem_read8(0x8675);
  flag_cmp(a, 0x09);
  if (flag_nz()) { p00_L_2565(); return; }
  cpu_push_de();
  p28_L_42F2();
  p28_L_432F();
  cpu_pop_de();
  set_hl(0x8670);
  a = mem_read8(0x8675);
  flag_cmp(a, 0x15);
  if (flag_nz()) { p00_L_2565(); return; }
  cpu_push_de();
  set_bc(mem_read16(0x8676));
  set_de(0x0000);
  mem_write16(0x8678, de());
  a = c;
  a = a | b;
  flag_logic(a);
  cpu_pop_de();
  if (flag_z()) goto lab_p28_L_6C0A;
  set_bc(mem_read16(0x8676));
  cpu_push_de();
  os_bcall(0x807B);
  l = a;
  cpu_push_hl();
  set_hl(mem_read16(0x8678));
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x8678, hl());
  cpu_pop_hl();
  os_bcall(0x807B);
  h = a;
  cpu_push_hl();
  set_hl(mem_read16(0x8678));
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x8678, hl());
  cpu_pop_hl();
  set_bc(mem_read16(0x8676));
  set_bc((uint16_t)(bc() - 1));
  set_bc((uint16_t)(bc() - 1));
  cpu_pop_de();
  lab_p28_L_6BB9: ;
  cpu_push_hl();
  cpu_push_de();
  set_de(0x0000);
  set_hl(0x8478);
  lab_p28_L_6BC1: ;
  p00_L_171E();
  if (flag_nz()) { p00_L_2565(); return; }
  cpu_push_de();
  p28_L_651A();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  a = e;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p28_L_6BC1;
  cpu_pop_de();
  cpu_push_bc();
  cpu_push_de();
  set_bc(0x0009);
  set_hl(0x847A);
  set_de(0x8499);
  while (bc() != 0) { cpu_ldi(); }
  p00_L_1100();
  cpu_pop_de();
  p00_L_2C31();
  if (flag_nz()) goto lab_p28_L_6BFF;
  cpu_push_de();
  p00_L_113F();
  cpu_pop_de();
  a = 0x01;
  p00_L_38EB();
  p00_L_3AE9();
  cpu_ex_de_hl();
  set_hl(0x8478);
  a = mem_read8(hl());
  p00_L_1183();
  lab_p28_L_6BFF: ;
  cpu_pop_bc();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  set_de(mem_read16(0x84E1));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_6BB9;
  lab_p28_L_6C0A: ;
  p28_L_64D6();
  p28_L_42F2();
  return;
}

/* flash page 28 cpu 0x6C11 (offset 0x2C11) */
void p28_L_6C11(void) {
  lab_p28_L_6C11: ;
  p28_L_644C();
  flag_cmp(a, 0x15);
  if (flag_z()) goto lab_p28_L_6C35;
  flag_cmp(a, 0x92);
  if (flag_nz()) { p00_L_2565(); return; }
  os_bcall(0x8057);
  p00_L_2BE9();
  p28_L_6D77();
  os_bcall(0x8051);
  cpu_push_af();
  p28_L_6D77();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x8051);
  l = a;
  cpu_pop_af();
  h = a;
  return;
  lab_p28_L_6C35: ;
  set_hl(mem_read16(0x8676));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nz()) { p00_L_2565(); return; }
  set_hl(mem_read16(0x8676));
  cpu_push_hl();
  set_hl(mem_read16(0x84DB));
  cpu_push_hl();
  set_hl(0x82A5);
  p28_L_64BB();
  cpu_pop_de();
  cpu_pop_bc();
  p28_L_6D77();
  set_hl(0x82A5);
  os_bcall(0x8087);
  p28_L_42F2();
  set_hl(mem_read16(0x84DB));
  set_bc(0x00E8);
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  goto lab_p28_L_6C11;
}

/* flash page 28 cpu 0x6C65 (offset 0x2C65) */
void p28_L_6C65(void) {
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  a = mem_read8(0x9834);
  c = a;
  a = 0;
  flag_logic(a);
  mem_write8(0x9834, a);
  set_hl(0x983A);
  mem_write16(0x9836, hl());
  set_de(mem_read16(0x84DB));
  a = mem_read8(0x83EE);
  cpu_push_de();
  mem_write8(0x83EB, a);
  cpu_ld_a_i();
  /* di */
  cpu_push_af();
  a = mem_read8(0x83EB);
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  b = 0x00;
  p28_L_6D5F();
  if (flag_nc()) goto lab_p28_L_6CA7;
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p28_L_6CA7;
  os_bcall(0x80C9);
  lab_p28_L_6CA7: ;
  p28_L_689C();
  mem_write8(0x83EB, a);
  cpu_pop_af();
  if (flag_po()) goto lab_p28_L_6CB2;
  /* ei */
  lab_p28_L_6CB2: ;
  a = mem_read8(0x83EB);
  mem_write16(0x84DB, de());
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p28_L_6CC6;
  a = mem_read8(0x83EE);
  a = (uint8_t)(a + 1);
  mem_write8(0x83EE, a);
  lab_p28_L_6CC6: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 28 cpu 0x6CCA (offset 0x2CCA) */
void p28_L_6CCA(void) {
  a = 0x15;
  p00_L_24A9();
  if (flag_nz()) return;
  a = 0x69;
  return;
}

/* flash page 28 cpu 0x6CD3 (offset 0x2CD3) */
void p28_L_6CD3(void) {
  p28_L_6CCA();
  set_hl(0x4000);
  p00_L_2DC3();
  a = 0;
  flag_logic(a);
  flag_cmp(a, c);
  if (flag_z()) goto lab_p28_L_6D0A;
  p00_L_2BA1();
  a = (uint8_t)(a + 1);
  b = a;
  p28_L_6CCA();
  p00_L_2C37();
  a = (uint8_t)(a - 1);
  b = (uint8_t)(b + 1);
  p00_L_2C37();
  p28_L_6D6E();
  os_bcall(0x8084);
  p00_L_2BA1();
  a = (uint8_t)(a + 1);
  cpu_push_af();
  p28_L_6CCA();
  b = a;
  cpu_pop_af();
  p00_L_2C37();
  a = (uint8_t)(a + 1);
  b = (uint8_t)(b - 1);
  p00_L_2C37();
  p28_L_6D10();
  return;
  lab_p28_L_6D0A: ;
  p28_L_6D6E();
  os_bcall(0x8084);
}

/* flash page 28 cpu 0x6D10 (offset 0x2D10) */
void p28_L_6D10(void) {
  p00_L_2BA1();
  cpu_push_af();
  os_bcall(0x8084);
  cpu_pop_af();
  p00_L_2C3D();
  return;
}

/* flash page 28 cpu 0x6D1C (offset 0x2D1C) */
void p28_L_6D1C(void) {
  p00_L_01E3();
  e = c;
  set_hl((uint16_t)(hl() + 1));
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_z()) goto lab_p28_L_6D29;
  b = (uint8_t)(b + 1);
  set_hl(0x4000);
  lab_p28_L_6D29: ;
  p00_L_01E3();
  d = c;
  return;
}

/* flash page 28 cpu 0x6D2E (offset 0x2D2E) */
void p28_L_6D2E(void) {
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_af();
  b = a;
  p28_L_6D1C();
  cpu_ex_de_hl();
  e = h;
  d = l;
  set_hl(0x8000);
  a = 0x0F;
  a = a | l;
  flag_logic(a);
  l = a;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nz()) goto lab_p28_L_6D4A;
  lab_p28_L_6D45: ;
  cpu_pop_af();
  b = a;
  a = 0;
  flag_logic(a);
  goto lab_p28_L_6D5A;
  lab_p28_L_6D4A: ;
  cpu_pop_af();
  cpu_push_af();
  h = 0x00;
  l = 0x0F;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p28_L_6D45;
  cpu_pop_af();
  b = a;
  a = 0x01;
  a = a | a;
  flag_logic(a);
  lab_p28_L_6D5A: ;
  a = b;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 28 cpu 0x6D5F (offset 0x2D5F) */
void p28_L_6D5F(void) {
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_6D69;
  a = a & 0x7F;
  flag_logic(a);
  flag_cmp(a, 0x6A);
  return;
  lab_p28_L_6D69: ;
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x16);
  return;
}

/* flash page 28 cpu 0x6D6E (offset 0x2D6E) */
void p28_L_6D6E(void) {
  a = 0x16;
  p00_L_24A9();
  if (flag_nz()) return;
  a = 0x6A;
  return;
}

/* flash page 28 cpu 0x6D77 (offset 0x2D77) */
void p28_L_6D77(void) {
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  a = 0x1E;
  if (flag_z()) return;
  a = 0x7E;
  return;
}

/* flash page 28 cpu 0x6DA1 (offset 0x2DA1) */
void p28_L_6DA1(void) {
  cpu_push_hl();
  set_hl(0xFFFF);
  a = hw_in(PORT_SE_STATUS);
  a = a & 0x01;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_6DAE;
  set_hl(0x6800);
  lab_p28_L_6DAE: ;
  mem_write16(0x9CAC, hl());
  cpu_pop_hl();
  return;
}

/* flash page 28 cpu 0x6DB3 (offset 0x2DB3) */
void p28_L_6DB3(void) {
  cpu_push_hl();
  h = 0x02;
  lab_p28_L_6DB6: ;
  h = (uint8_t)(h - 1);
  if (flag_nz()) goto lab_p28_L_6DB6;
  set_hl(mem_read16(0x9CAC));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x9CAC, hl());
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_6DC8;
  a = 0x01;
  goto lab_p28_L_6DCA;
  lab_p28_L_6DC8: ;
  a = 0x00;
  lab_p28_L_6DCA: ;
  a = a | a;
  flag_logic(a);
  cpu_pop_hl();
  return;
}

/* flash page 28 cpu 0x6DCD (offset 0x2DCD) */
void p28_L_6DCD(void) {
  lab_p28_L_6DCD: ;
  p00_L_171E();
  p00_L_0284();
  a = hw_in(0x09);
  a = a & 0x58;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6DCD;
  p28_L_6B25();
  p28_L_6DDC();
  return;
}

/* flash page 28 cpu 0x6DDC (offset 0x2DDC) */
void p28_L_6DDC(void) {
  goto lab_p28_L_6DDC;
  lab_p28_L_44F8: ;
  p28_L_442B();
  return;
  lab_p28_L_6D9E: ;
  p28_L_442B();
  return;
  lab_p28_L_6DDC: ;
  p28_L_6F37();
  p28_L_6DA1();
  p28_L_6DA1();
  lab_p28_L_6DE5: ;
  a = 0x00;
  mem_write8(0x9C86, a);
  p28_L_6DB3();
  if (flag_nz()) goto lab_p28_L_6D9E;
  a = hw_in(0x09);
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p28_L_6DFF;
  a = a & 0x11;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6DE5;
  a = hw_in(0x0A);
  c = a;
  a = 0x00;
  return;
  lab_p28_L_6DFF: ;
  a = a & 0x11;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_44F8;
  a = hw_in(0x0A);
  c = a;
  a = 0x01;
  return;
}

/* flash page 28 cpu 0x6E0A (offset 0x2E0A) */
void p28_L_6E0A(void) {
  a = 0x00;
  link_out(a); /* stub */
  a = 0x97;
  hw_out(0x09, a);
  a = 0xB4;
  hw_out(0x0A, a);
  hw_out(0x0B, a);
  hw_out(0x0C, a);
  p28_L_6E1A();
  return;
}

/* flash page 28 cpu 0x6E1A (offset 0x2E1A) */
void p28_L_6E1A(void) {
  a = 0x80;
  hw_out(0x08, a);
  a = 0;
  flag_logic(a);
  hw_out(0x08, a);
  a = hw_in(0x09);
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) | (1u << 0)));
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x6E29 (offset 0x2E29) */
void p28_L_6E29(void) {
  set_hl(0x8685);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 28 cpu 0x6E31 (offset 0x2E31) */
void p28_L_6E31(void) {
  cpu_push_af();
  a = l;
  l = h;
  h = a;
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x6E37 (offset 0x2E37) */
void p28_L_6E37(void) {
  a = mem_read8(0x83A4);
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  set_hl(mem_read16(0x83A1));
  p28_L_6E31();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  p28_L_6E31();
  mem_write16(0x83A1, hl());
  if (flag_nc()) return;
  set_hl(0x83A0);
  a = mem_read8(hl());
  a = (uint8_t)(a - 0x01);
  mem_write8(hl(), a);
  if (flag_nc()) return;
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  a = (uint8_t)(a - 0x01);
  mem_write8(hl(), a);
  return;
}

/* flash page 28 cpu 0x6E5A (offset 0x2E5A) */
void p28_L_6E5A(void) {
  cpu_push_hl();
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6E6A;
  set_hl(0x0039);
  a = hw_in(PORT_SE_STATUS);
  a = a & 0x01;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_6E6D;
  lab_p28_L_6E6A: ;
  set_hl(0x0017);
  lab_p28_L_6E6D: ;
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6E7B;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6E6D;
  lab_p28_L_6E78: ;
  cpu_pop_hl();
  a = c;
  return;
  lab_p28_L_6E7B: ;
  /* scf */
  goto lab_p28_L_6E78;
}

/* flash page 28 cpu 0x6E7E (offset 0x2E7E) */
void p28_L_6E7E(void) {
  cpu_push_hl();
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6EC4;
  set_hl(0x0037);
  a = hw_in(PORT_SE_STATUS);
  a = a & 0x01;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6EC4;
  goto lab_p28_L_6EC7;
  lab_p28_L_6EC4: ;
  set_hl(0x0016);
  lab_p28_L_6EC7: ;
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6EE0;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p28_L_6EC7;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p28_L_6EC7;
  a = a | a;
  flag_logic(a);
  lab_p28_L_6EDD: ;
  cpu_pop_hl();
  a = c;
  return;
  lab_p28_L_6EE0: ;
  /* scf */
  goto lab_p28_L_6EDD;
}

/* flash page 28 cpu 0x6E90 (offset 0x2E90) */
void p28_L_6E90(void) {
  cpu_push_hl();
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6EC4;
  set_hl(0x0028);
  a = hw_in(PORT_SE_STATUS);
  a = a & 0x01;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_6EA2;
  l = 0x10;
  lab_p28_L_6EA2: ;
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6EE0;
  a = hw_in(0x09);
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p28_L_6EC1;
  flag_set_z((a & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p28_L_6EDD;
  a = a & 0x08;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6EA2;
  a = hw_in(0x09);
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p28_L_6EC1;
  a = a & 0x19;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6EA2;
  if (flag_nz()) goto lab_p28_L_6EDD;
  lab_p28_L_6EC1: ;
  a = 0;
  flag_logic(a);
  goto lab_p28_L_6EDD;
  lab_p28_L_6EC4: ;
  set_hl(0x0016);
  lab_p28_L_6EC7: ;
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_6EE0;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p28_L_6EC7;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p28_L_6EC7;
  a = a | a;
  flag_logic(a);
  lab_p28_L_6EDD: ;
  cpu_pop_hl();
  a = c;
  return;
  lab_p28_L_6EE0: ;
  /* scf */
  goto lab_p28_L_6EDD;
}

/* flash page 28 cpu 0x6EE6 (offset 0x2EE6) */
void p28_L_6EE6(void) {
  goto lab_p28_L_6EE6;
  lab_p28_L_6EE3: ;
  if (flag_c()) { p00_L_255D(); return; }
  lab_p28_L_6EE6: ;
  p28_L_6F20();
  p28_L_6E5A();
  if (flag_c()) goto lab_p28_L_6EE3;
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_nz()) p28_L_6E1A();
  p28_L_6EF5();
  return;
}

/* flash page 28 cpu 0x6EF5 (offset 0x2EF5) */
void p28_L_6EF5(void) {
  p28_L_447D();
  d = a;
  a = c;
  flag_cmp(a, 0x01);
  cpu_push_af();
  cpu_push_de();
  p28_L_447D();
  cpu_pop_de();
  e = a;
  cpu_pop_af();
  b = a;
  a = c;
  return;
}

/* flash page 28 cpu 0x6F20 (offset 0x2F20) */
void p28_L_6F20(void) {
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) return;
  a = hw_in(0x09);
  a = a & 0x99;
  flag_logic(a);
  if (flag_nz()) return;
  p28_L_6F2A();
  return;
}

/* flash page 28 cpu 0x6F2A (offset 0x2F2A) */
void p28_L_6F2A(void) {
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  a = 0x80;
  hw_out(0x08, a);
  return;
}

/* flash page 28 cpu 0x6F2D (offset 0x2F2D) */
void p28_L_6F2D(void) {
  /* add a,(hl) */
  a = 0x80;
  hw_out(0x08, a);
  return;
}

/* flash page 28 cpu 0x6F33 (offset 0x2F33) */
void p28_L_6F33(void) {
  p00_L_24A9();
  if (flag_nz()) return;
  p28_L_6F37();
  return;
}

/* flash page 28 cpu 0x6F37 (offset 0x2F37) */
void p28_L_6F37(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x3E)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) | (1u << 0)));
  a = hw_in(0x09);
  a = 0;
  flag_logic(a);
  hw_out(0x08, a);
  return;
}

/* flash page 28 cpu 0x6FEA (offset 0x2FEA) */
void p28_L_6FEA(void) {
  p00_L_1664();
  p28_L_7022();
  p00_L_165F();
  p28_L_7022();
  set_hl(0xFE66);
  b = 0x00;
  lab_p28_L_6FFB: ;
  cpu_ex_de_hl();
  set_hl(mem_read16(0x982E));
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) return;
  cpu_ex_de_hl();
  cpu_push_bc();
  p00_L_2EA7();
  p00_L_2408();
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  cpu_pop_bc();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  if (flag_nz()) goto lab_p28_L_701B;
  a = mem_read8(hl());
  flag_cmp(a, b);
  if (flag_c()) goto lab_p28_L_701B;
  if (flag_z()) goto lab_p28_L_701B;
  b = a;
  lab_p28_L_701B: ;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_33AB();
  goto lab_p28_L_6FFB;
}

/* flash page 28 cpu 0x7022 (offset 0x3022) */
void p28_L_7022(void) {
  p00_L_19E7();
  if (flag_c()) return;
  p00_L_3519();
  p00_L_240B();
  mem_write8(hl(), a);
  return;
}

/* flash page 28 cpu 0x705F (offset 0x305F) */
void p28_L_705F(void) {
  p00_L_128D();
  a = mem_read8(0x8478);
  cpu_push_af();
  /* di */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  set_de(0x0A10);
  os_bcall(0x8027);
  if (flag_nz()) goto lab_p28_L_7094;
  set_de(0x867F);
  p28_L_709C();
  set_de(0x0410);
  os_bcall(0x8027);
  if (flag_nz()) goto lab_p28_L_7094;
  set_de(0x8684);
  p28_L_709C();
  lab_p28_L_7094: ;
  p28_L_689C();
  cpu_pop_af();
  mem_write8(0x8478, a);
  return;
}

/* flash page 28 cpu 0x709C (offset 0x309C) */
void p28_L_709C(void) {
  set_hl((uint16_t)(hl() + 1));
  p28_L_6D77();
  p00_L_2CCD();
  a = a & 0x0F;
  flag_logic(a);
  c = a;
  b = 0x00;
  set_hl((uint16_t)(hl() + 1));
  p28_L_6D77();
  p00_L_2F8B();
  return;
}

/* flash page 28 cpu 0x7119 (offset 0x3119) */
void p28_L_7119(void) {
  set_de(mem_read16(0x8402));
  b = 0xFC;
  a = mem_read8(0x8404);
  /* di */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p28_L_6D5F();
  if (flag_nc()) goto lab_p28_L_7141;
  p00_L_2C43();
  if (flag_c()) goto lab_p28_L_7141;
  os_bcall(0x80C6);
  lab_p28_L_7141: ;
  p28_L_689C();
  return;
}

/* flash page 28 cpu 0x7145 (offset 0x3145) */
void p28_L_7145(void) {
  a = mem_read8(hl());
  cpu_push_af();
  a = a & 0x1F;
  flag_logic(a);
  mem_write8(hl(), a);
  p00_L_2ED1();
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x714F (offset 0x314F) */
void p28_L_714F(void) {
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p28_L_7714;
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p28_L_7F17;
  flag_set_z((mem_read8((uint16_t)(iy + 0x25)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p28_L_7178;
  flag_cmp(a, 0x03);
  if (flag_z()) { p28_L_7251(); return; }
  flag_cmp(a, 0x04);
  if (flag_z()) { p28_L_7257(); return; }
  flag_cmp(a, 0x01);
  if (flag_z()) { p28_L_7222(); return; }
  flag_cmp(a, 0x00);
  if (flag_nz()) return;
  a = b;
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p28_L_7237;
  a = 0;
  flag_logic(a);
  lab_p28_L_7178: ;
  cpu_push_af();
  b = 0x3F;
  p00_L_2E1D();
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 5)));
  a = 0;
  flag_logic(a);
  mem_write8(0x8444, a);
  mem_write8(0x8446, a);
  p28_L_4F79();
  p00_L_3F2D();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  lab_p28_L_7193: ;
  /* ei */
  p00_L_3F21();
  flag_cmp(a, 0x8F);
  if (flag_z()) goto lab_p28_L_71AD;
  flag_cmp(a, 0x90);
  if (flag_z()) goto lab_p28_L_71AD;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p28_L_71AD;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p28_L_71AD;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p28_L_71AD;
  goto lab_p28_L_7193;
  lab_p28_L_71AD: ;
  p00_L_3F39();
  /* di */
  if (flag_c()) goto lab_p28_L_7193;
  flag_cmp(a, 0x1D);
  if (flag_nz()) goto lab_p28_L_71CD;
  cpu_pop_af();
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p28_L_71D0;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p28_L_71D5;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p28_L_71DA;
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p28_L_71DD;
  p28_L_722B();
  goto lab_p28_L_71DD;
  lab_p28_L_71CD: ;
  cpu_pop_af();
  goto lab_p28_L_71DD;
  lab_p28_L_71D0: ;
  p28_L_7251();
  goto lab_p28_L_71DD;
  lab_p28_L_71D5: ;
  p28_L_7257();
  goto lab_p28_L_71DD;
  lab_p28_L_71DA: ;
  p28_L_7222();
  lab_p28_L_71DD: ;
  p00_L_3D7D();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  return;
  lab_p28_L_7237: ;
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  p00_L_3D71();
  /* di */
  p28_L_7E19();
  p28_L_725D();
  p28_L_7758();
  /* ei */
  p00_L_3D7D();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  return;
  lab_p28_L_7714: ;
  /* di */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p28_L_7EE2();
  p28_L_7E06();
  p28_L_77DA();
  a = 0x08;
  p28_L_78BF();
  a = b;
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p28_L_774E;
  a = 0x0C;
  p28_L_786A();
  a = 0x08;
  b = 0xFE;
  p28_L_797E();
  p28_L_770E();
  p28_L_7782();
  return;
  lab_p28_L_774E: ;
  a = 0x08;
  p28_L_78D2();
  p28_L_7D17();
  p28_L_7782();
  return;
  lab_p28_L_7F17: ;
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  p00_L_3D71();
  /* di */
  p28_L_7E19();
  p28_L_7F30();
  cpu_push_af();
  /* ei */
  p00_L_3D7D();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x71E5 (offset 0x31E5) */
void p28_L_71E5(void) {
  p28_L_71FA();
  if (flag_c()) return;
  /* di */
  p28_L_7E37();
  p28_L_725D();
  set_hl(0x9D8D);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_nz()) p00_lcd_write_cmd();
  /* ei */
  return;
}

/* flash page 28 cpu 0x71FA (offset 0x31FA) */
void p28_L_71FA(void) {
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p28_L_72B2();
  cpu_push_af();
  cpu_push_af();
  a = 0;
  flag_logic(a);
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p00_rst00_boot(); return; }
  cpu_pop_af();
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x7222 (offset 0x3222) */
void p28_L_7222(void) {
  /* di */
  p28_L_7E37();
  p28_L_725D();
  /* ei */
  return;
}

/* flash page 28 cpu 0x722B (offset 0x322B) */
void p28_L_722B(void) {
  /* di */
  p28_L_7E19();
  p28_L_725D();
  p28_L_7758();
  /* ei */
  return;
}

/* flash page 28 cpu 0x723A (offset 0x323A) */
void p28_L_723A(void) {
  /* adc a,(hl) */
  p00_L_3D71();
  /* di */
  p28_L_7E19();
  p28_L_725D();
  p28_L_7758();
  /* ei */
  p00_L_3D7D();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  return;
}

/* flash page 28 cpu 0x7251 (offset 0x3251) */
void p28_L_7251(void) {
  /* di */
  p28_L_7758();
  /* ei */
  return;
}

/* flash page 28 cpu 0x7257 (offset 0x3257) */
void p28_L_7257(void) {
  /* di */
  p28_L_725D();
  /* ei */
  return;
}

/* flash page 28 cpu 0x725D (offset 0x325D) */
void p28_L_725D(void) {
  /* di */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p28_L_72B2();
  if (flag_c()) goto lab_p28_L_728A;
  p28_L_7EE2();
  p28_L_7E06();
  p28_L_72E9();
  p28_L_728E();
  p28_L_7C20();
  p00_L_1960();
  lab_p28_L_728A: ;
  p00_L_3E0D();
  return;
}

/* flash page 28 cpu 0x728E (offset 0x328E) */
void p28_L_728E(void) {
  lab_p28_L_728E: ;
  p28_L_7B46();
  p28_L_750C();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_72AE;
  cpu_push_af();
  a = b;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p28_L_72A5;
  cpu_pop_af();
  cpu_push_af();
  p28_L_7569();
  p28_L_7B46();
  lab_p28_L_72A5: ;
  cpu_pop_af();
  p28_L_7626();
  p28_L_7B46();
  goto lab_p28_L_728E;
  lab_p28_L_72AE: ;
  p28_L_76D6();
  return;
}

/* flash page 28 cpu 0x72B2 (offset 0x32B2) */
void p28_L_72B2(void) {
  p00_L_2B53();
  p28_L_7ED9();
  lab_p28_L_72B8: ;
  flag_cmp(a, b);
  if (flag_z()) goto lab_p28_L_72E3;
  if (flag_c()) goto lab_p28_L_72E3;
  cpu_push_bc();
  cpu_push_af();
  set_hl(0x4000);
  p00_L_2CCD();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_72E5;
  flag_cmp(a, 0x80);
  if (flag_nz()) goto lab_p28_L_72E5;
  cpu_pop_af();
  cpu_push_af();
  set_hl(0x4000);
  p00_L_2C97();
  p00_L_2B59();
  if (flag_nz()) goto lab_p28_L_72E5;
  cpu_pop_af();
  cpu_push_af();
  p00_L_2DC3();
  cpu_pop_af();
  a = (uint8_t)(a - c);
  cpu_pop_bc();
  goto lab_p28_L_72B8;
  lab_p28_L_72E3: ;
  /* scf */
  return;
  lab_p28_L_72E5: ;
  cpu_pop_af();
  cpu_pop_af();
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x72E9 (offset 0x32E9) */
void p28_L_72E9(void) {
  p00_L_2CBB();
  p28_L_7E7F();
  set_hl(0x82A5);
  b = 0x0A;
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_72FE;
  set_hl(0x8000);
  b = 0x5E;
  lab_p28_L_72FE: ;
  /* sla b */
  a = 0xFF;
  lab_p28_L_7302: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_7302;
  p28_L_735B();
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 7)));
  a = 0;
  flag_logic(a);
  mem_write8(0x9C87, a);
  b = 0xFE;
  p28_L_7E85();
  a = 0x08;
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p28_L_732B;
  b = 0xFD;
  p28_L_7E85();
  lab_p28_L_732B: ;
  p00_L_2B53();
  a = b;
  a = (uint8_t)(a + 1);
  p28_L_7E97();
  mem_write8(hl(), a);
  set_hl(0x836D);
  a = 0x01;
  /* and (hl) */
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  p00_L_24A9();
  if (flag_z()) goto lab_p28_L_7347;
  a = mem_read8(hl());
  a = a & 0x80;
  flag_logic(a);
  mem_write8(hl(), a);
  goto lab_p28_L_7352;
  lab_p28_L_7347: ;
  a = 0;
  flag_logic(a);
  b = 0x0B;
  lab_p28_L_734A: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_734A;
  a = mem_read8(hl());
  a = a & 0xFC;
  flag_logic(a);
  mem_write8(hl(), a);
  lab_p28_L_7352: ;
  p28_L_7371();
  a = 0x04;
  p00_L_2B5F();
  return;
}

/* flash page 28 cpu 0x735B (offset 0x335B) */
void p28_L_735B(void) {
  set_hl(0x82A5);
  b = 0x64;
  p00_L_24A9();
  if (flag_z()) goto lab_p28_L_736A;
  set_hl(0x837B);
  b = 0x12;
  lab_p28_L_736A: ;
  a = 0xFF;
  lab_p28_L_736C: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_736C;
  return;
}

/* flash page 28 cpu 0x7371 (offset 0x3371) */
void p28_L_7371(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x8436, a);
  a = 0xF0;
  mem_write8(0x8477, a);
  p28_L_7EA2();
  a = 0xFE;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  p28_L_7ED9();
  lab_p28_L_7385: ;
  mem_write8(0x8435, a);
  p28_L_7E97();
  cpu_cp_hl();
  if (flag_c()) goto lab_p28_L_73AA;
  a = mem_read8(0x8435);
  cpu_push_af();
  p28_L_73E2();
  if (flag_c()) goto lab_p28_L_739D;
  cpu_pop_af();
  p28_L_73FE();
  goto lab_p28_L_73A1;
  lab_p28_L_739D: ;
  cpu_pop_af();
  p28_L_7417();
  lab_p28_L_73A1: ;
  a = mem_read8(0x8435);
  p00_L_2DC3();
  a = (uint8_t)(a - c);
  goto lab_p28_L_7385;
  lab_p28_L_73AA: ;
  a = mem_read8(0x8435);
  p28_L_74C1();
  lab_p28_L_73B0: ;
  a = b;
  mem_write8(0x8435, a);
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p28_L_73C9;
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p28_L_73D0;
  a = 0xFF;
  p28_L_74CB();
  goto lab_p28_L_73D3;
  lab_p28_L_73C9: ;
  a = 0x7E;
  p28_L_74CB();
  goto lab_p28_L_73D3;
  lab_p28_L_73D0: ;
  p28_L_74F8();
  lab_p28_L_73D3: ;
  a = mem_read8(0x8435);
  b = a;
  a = 0x08;
  a = (uint8_t)(a + 1);
  flag_cmp(a, b);
  if (flag_nc()) return;
  a = b;
  a = (uint8_t)(a - 0x04);
  b = a;
  goto lab_p28_L_73B0;
}

/* flash page 28 cpu 0x73E2 (offset 0x33E2) */
void p28_L_73E2(void) {
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p28_L_73FC;
  a = mem_read8(0x8435);
  set_hl(0x4000);
  p00_L_2C97();
  p00_L_2B59();
  if (flag_nz()) goto lab_p28_L_73FC;
  /* scf */
  return;
  lab_p28_L_73FC: ;
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x73FE (offset 0x33FE) */
void p28_L_73FE(void) {
  cpu_push_af();
  p28_L_74B2();
  cpu_push_hl();
  p00_L_2DC3();
  cpu_pop_hl();
  cpu_push_bc();
  b = c;
  a = 0xFC;
  lab_p28_L_740B: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_740B;
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  p00_L_2CC1();
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x7417 (offset 0x3417) */
void p28_L_7417(void) {
  p28_L_74B2();
  p00_L_2DC3();
  b = c;
  a = 0xFE;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  p28_L_7422();
  return;
}

/* flash page 28 cpu 0x7422 (offset 0x3422) */
void p28_L_7422(void) {
  goto lab_p28_L_7422;
  lab_p28_L_7420: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  lab_p28_L_7422: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_7420;
  set_hl(0x82A5);
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_742F;
  set_hl(0x8000);
  lab_p28_L_742F: ;
  a = mem_read8(0x8436);
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  cpu_push_de();
  p00_L_2B65();
  a = mem_read8(0x8435);
  b = a;
  p28_L_7ED9();
  a = (uint8_t)(a - b);
  /* sla a */
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  p28_L_7F0D();
  set_bc(0x0002);
  cpu_pop_de();
  os_bcall(0x8054);
  a = mem_read8(0x8436);
  /* sra a */
  b = a;
  p28_L_7ED9();
  a = (uint8_t)(a - b);
  c = a;
  p00_L_24A9();
  if (flag_z()) goto lab_p28_L_7492;
  b = 0x00;
  set_hl(0x8697);
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  a = mem_read8(0x8435);
  c = a;
  b = 0x00;
  set_hl(0x8697);
  set_hl((uint16_t)(hl() + bc()));
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  cpu_ex_de_hl();
  if (flag_z()) goto lab_p28_L_747D;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  goto lab_p28_L_747F;
  lab_p28_L_747D: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  lab_p28_L_747F: ;
  cpu_ex_de_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  lab_p28_L_7482: ;
  a = mem_read8(0x8435);
  p00_L_2DC3();
  /* sla c */
  a = mem_read8(0x8436);
  a = (uint8_t)(a + c);
  mem_write8(0x8436, a);
  return;
  lab_p28_L_7492: ;
  cpu_push_bc();
  a = mem_read8(0x8435);
  b = a;
  p28_L_7EF2();
  cpu_pop_bc();
  /* and (hl) */
  cpu_push_af();
  if (flag_z()) goto lab_p28_L_74A1;
  /* xor (hl) */
  mem_write8(hl(), a);
  lab_p28_L_74A1: ;
  b = c;
  p28_L_7EF2();
  b = a;
  cpu_pop_af();
  a = b;
  if (flag_z()) goto lab_p28_L_74AE;
  /* or (hl) */
  lab_p28_L_74AB: ;
  mem_write8(hl(), a);
  goto lab_p28_L_7482;
  lab_p28_L_74AE: ;
  a = a ^ 0xFF;
  /* and (hl) */
  goto lab_p28_L_74AB;
}

/* flash page 28 cpu 0x74B2 (offset 0x34B2) */
void p28_L_74B2(void) {
  cpu_push_af();
  b = a;
  p28_L_7EE9();
  a = (uint8_t)(a - b);
  c = a;
  b = 0x00;
  p28_L_7EA2();
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x74C1 (offset 0x34C1) */
void p28_L_74C1(void) {
  a = mem_read8(0x8435);
  a = a | 0x03;
  flag_logic(a);
  c = a;
  a = a & 0xFC;
  flag_logic(a);
  b = a;
  return;
}

/* flash page 28 cpu 0x74CB (offset 0x34CB) */
void p28_L_74CB(void) {
  cpu_push_af();
  a = mem_read8(0x8435);
  a = (uint8_t)(a + 0x03);
  cpu_push_af();
  p00_L_2B53();
  cpu_pop_af();
  a = (uint8_t)(a - b);
  if (flag_c()) goto lab_p28_L_74E8;
  a = b;
  p28_L_74B2();
  cpu_push_af();
  a = mem_read8(0x8435);
  b = a;
  cpu_pop_af();
  a = (uint8_t)(a - b);
  a = (uint8_t)(a + 1);
  b = a;
  goto lab_p28_L_74F2;
  lab_p28_L_74E8: ;
  a = mem_read8(0x8435);
  a = (uint8_t)(a + 0x03);
  p28_L_74B2();
  b = 0x04;
  lab_p28_L_74F2: ;
  cpu_pop_af();
  lab_p28_L_74F3: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_74F3;
  return;
}

/* flash page 28 cpu 0x74F8 (offset 0x34F8) */
void p28_L_74F8(void) {
  a = mem_read8(0x8435);
  a = (uint8_t)(a + 0x03);
  p28_L_74B2();
  b = 0x03;
  a = 0xFF;
  lab_p28_L_7504: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_7504;
  a = 0xFC;
  mem_write8(hl(), a);
  return;
}

/* flash page 28 cpu 0x750C (offset 0x350C) */
void p28_L_750C(void) {
  p28_L_7EE9();
  lab_p28_L_750F: ;
  cpu_push_af();
  p28_L_7529();
  if (flag_c()) goto lab_p28_L_7526;
  cpu_pop_af();
  cpu_push_af();
  p28_L_7532();
  if (flag_nc()) goto lab_p28_L_7521;
  cpu_pop_af();
  p28_L_754B();
  return;
  lab_p28_L_7521: ;
  cpu_pop_af();
  a = (uint8_t)(a - 0x04);
  goto lab_p28_L_750F;
  lab_p28_L_7526: ;
  cpu_pop_af();
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x7529 (offset 0x3529) */
void p28_L_7529(void) {
  cpu_push_af();
  p28_L_7E97();
  a = mem_read8(hl());
  b = a;
  cpu_pop_af();
  a = (uint8_t)(a - b);
  return;
}

/* flash page 28 cpu 0x7532 (offset 0x3532) */
void p28_L_7532(void) {
  p28_L_74B2();
  b = 0x00;
  lab_p28_L_7537: ;
  a = mem_read8(hl());
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p28_L_7549;
  flag_cmp(a, 0x7C);
  if (flag_z()) goto lab_p28_L_7549;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b + 1);
  a = b;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p28_L_7537;
  a = 0;
  flag_logic(a);
  return;
  lab_p28_L_7549: ;
  /* scf */
  return;
}

/* flash page 28 cpu 0x754B (offset 0x354B) */
void p28_L_754B(void) {
  cpu_push_af();
  p28_L_74B2();
  b = 0x00;
  lab_p28_L_7551: ;
  a = mem_read8(hl());
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p28_L_7565;
  flag_cmp(a, 0x7E);
  if (flag_z()) goto lab_p28_L_7565;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b + 1);
  a = b;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p28_L_7551;
  b = 0x02;
  goto lab_p28_L_7567;
  lab_p28_L_7565: ;
  b = 0x01;
  lab_p28_L_7567: ;
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x7569 (offset 0x3569) */
void p28_L_7569(void) {
  cpu_push_af();
  p28_L_7581();
  cpu_push_af();
  os_bcall(0x8084);
  cpu_pop_af();
  cpu_push_af();
  p28_L_758D();
  cpu_pop_bc();
  cpu_pop_af();
  p28_L_759B();
  p28_L_757B();
  return;
}

/* flash page 28 cpu 0x757B (offset 0x357B) */
void p28_L_757B(void) {
  a = 0x03;
  p00_L_2B5F();
  return;
}

/* flash page 28 cpu 0x7581 (offset 0x3581) */
void p28_L_7581(void) {
  p28_L_7E8C();
  a = mem_read8(hl());
  a = a & 0x02;
  flag_logic(a);
  a = 0x0B;
  if (flag_nz()) return;
  a = 0x0F;
  return;
}

/* flash page 28 cpu 0x758D (offset 0x358D) */
void p28_L_758D(void) {
  cpu_push_af();
  p28_L_74B2();
  a = 0xFF;
  b = 0x04;
  lab_p28_L_7595: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_7595;
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x759B (offset 0x359B) */
void p28_L_759B(void) {
  mem_write8(0x8435, a);
  mem_write8(0x97B1, a);
  a = (uint8_t)(a - 0x03);
  mem_write8(0x8436, a);
  a = b;
  mem_write8(0x8437, a);
  mem_write8(0x97B2, a);
  a = mem_read8(0x97B1);
  lab_p28_L_75B0: ;
  cpu_push_af();
  a = mem_read8(0x8436);
  d = a;
  cpu_pop_af();
  flag_cmp(a, d);
  if (flag_c()) return;
  cpu_push_bc();
  p28_L_74B2();
  cpu_pop_bc();
  a = mem_read8(hl());
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p28_L_75D8;
  flag_cmp(a, 0x7E);
  if (flag_z()) goto lab_p28_L_75CF;
  a = mem_read8(0x97B1);
  a = (uint8_t)(a - 1);
  mem_write8(0x97B1, a);
  goto lab_p28_L_75B0;
  lab_p28_L_75CF: ;
  cpu_push_af();
  p28_L_75F5();
  a = b;
  mem_write8(0x97B2, a);
  cpu_pop_af();
  lab_p28_L_75D8: ;
  p28_L_7607();
  a = mem_read8(0x97B2);
  b = a;
  a = mem_read8(0x97B1);
  p00_L_2C37();
  p28_L_7B46();
  set_hl(0x97B2);
  a = mem_read8(hl());
  a = (uint8_t)(a - 1);
  b = a;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  a = (uint8_t)(a - 1);
  mem_write8(hl(), a);
  goto lab_p28_L_75B0;
}

/* flash page 28 cpu 0x75F5 (offset 0x35F5) */
void p28_L_75F5(void) {
  cpu_push_af();
  a = mem_read8(0x97B1);
  b = a;
  a = mem_read8(0x8435);
  a = (uint8_t)(a - b);
  cpu_push_af();
  a = mem_read8(0x8437);
  cpu_pop_bc();
  a = (uint8_t)(a - b);
  b = a;
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x7607 (offset 0x3607) */
void p28_L_7607(void) {
  cpu_push_af();
  a = mem_read8(0x97B1);
  p28_L_74B2();
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_af();
  a = mem_read8(0x97B2);
  p28_L_74B2();
  cpu_pop_af();
  mem_write8(hl(), a);
  cpu_pop_hl();
  flag_cmp(a, 0xFE);
  if (flag_nz()) { p28_L_7622(); return; }
  a = 0xFC;
  mem_write8(hl(), a);
  return;
}

/* flash page 28 cpu 0x7622 (offset 0x3622) */
void p28_L_7622(void) {
  a = 0x7C;
  mem_write8(hl(), a);
  return;
}

/* flash page 28 cpu 0x7626 (offset 0x3626) */
void p28_L_7626(void) {
  cpu_push_af();
  os_bcall(0x8084);
}

/* flash page 28 cpu 0x762A (offset 0x362A) */
void p28_L_762A(void) {
  cpu_pop_af();
  p28_L_758D();
  cpu_push_af();
  p28_L_7581();
  cpu_pop_bc();
  cpu_push_bc();
  p28_L_759B();
  cpu_pop_af();
  p28_L_763E();
  p28_L_757B();
  return;
}

/* flash page 28 cpu 0x763E (offset 0x363E) */
void p28_L_763E(void) {
  p28_L_766E();
  cpu_push_bc();
  cpu_push_af();
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_766B;
  cpu_pop_af();
  cpu_push_af();
  p28_L_76AE();
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_766B;
  cpu_pop_de();
  cpu_pop_bc();
  cpu_push_de();
  p28_L_7653();
  return;
  lab_p28_L_766B: ;
  cpu_pop_af();
  cpu_pop_bc();
  return;
}

/* flash page 28 cpu 0x7653 (offset 0x3653) */
void p28_L_7653(void) {
  cpu_push_bc();
  cpu_push_af();
  p00_L_2C37();
  p28_L_7B46();
  p28_L_765B();
  return;
}

/* flash page 28 cpu 0x765B (offset 0x365B) */
void p28_L_765B(void) {
  set_hl(0x97B1);
  cpu_pop_af();
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  mem_write8(hl(), a);
  a = 0xFE;
  p28_L_7607();
  cpu_pop_af();
  p28_L_763E();
  return;
}

/* flash page 28 cpu 0x766E (offset 0x366E) */
void p28_L_766E(void) {
  cpu_push_af();
  p28_L_767D();
  if (flag_c()) goto lab_p28_L_7679;
  cpu_pop_af();
  p28_L_7692();
  return;
  lab_p28_L_7679: ;
  cpu_pop_af();
  b = 0x00;
  return;
}

/* flash page 28 cpu 0x767D (offset 0x367D) */
void p28_L_767D(void) {
  p28_L_74B2();
  b = 0x00;
  lab_p28_L_7682: ;
  a = mem_read8(hl());
  flag_cmp(a, 0x7E);
  if (flag_z()) goto lab_p28_L_7690;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b + 1);
  a = b;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p28_L_7682;
  a = 0;
  flag_logic(a);
  return;
  lab_p28_L_7690: ;
  /* scf */
  return;
}

/* flash page 28 cpu 0x7692 (offset 0x3692) */
void p28_L_7692(void) {
  cpu_push_af();
  p28_L_74B2();
  b = 0x00;
  lab_p28_L_7698: ;
  a = mem_read8(hl());
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p28_L_76A8;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b + 1);
  a = b;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p28_L_7698;
  b = 0x00;
  goto lab_p28_L_76AC;
  lab_p28_L_76A8: ;
  cpu_pop_af();
  cpu_push_af();
  a = (uint8_t)(a - b);
  b = a;
  lab_p28_L_76AC: ;
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x76AE (offset 0x36AE) */
void p28_L_76AE(void) {
  a = (uint8_t)(a - 0x04);
  cpu_push_af();
  p28_L_7E97();
  a = mem_read8(hl());
  b = a;
  cpu_pop_af();
  cpu_push_bc();
  cpu_push_af();
  lab_p28_L_76B9: ;
  a = (uint8_t)(a - b);
  if (flag_c()) goto lab_p28_L_76D0;
  cpu_pop_af();
  cpu_push_af();
  p28_L_74B2();
  a = mem_read8(hl());
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p28_L_76CD;
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  cpu_pop_bc();
  cpu_push_bc();
  cpu_push_af();
  goto lab_p28_L_76B9;
  lab_p28_L_76CD: ;
  cpu_pop_bc();
  cpu_pop_af();
  return;
  lab_p28_L_76D0: ;
  b = 0x00;
  cpu_pop_af();
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x76D6 (offset 0x36D6) */
void p28_L_76D6(void) {
  p28_L_76DE();
  /* nop */
  p28_L_770E();
  return;
}

/* flash page 28 cpu 0x76DE (offset 0x36DE) */
void p28_L_76DE(void) {
  p28_L_7581();
  cpu_push_af();
  p28_L_76F9();
  if (flag_nc()) goto lab_p28_L_76EC;
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8084);
  lab_p28_L_76EC: ;
  cpu_pop_af();
  a = (uint8_t)(a - 0x03);
  set_de(0x4000);
  b = 0xFE;
  os_bcall(0x8021);
  return;
}

/* flash page 28 cpu 0x76F9 (offset 0x36F9) */
void p28_L_76F9(void) {
  p28_L_74B2();
  b = 0x00;
  lab_p28_L_76FE: ;
  a = mem_read8(hl());
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p28_L_770C;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b + 1);
  a = b;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p28_L_76FE;
  a = 0;
  flag_logic(a);
  return;
  lab_p28_L_770C: ;
  /* scf */
  return;
}

/* flash page 28 cpu 0x770E (offset 0x370E) */
void p28_L_770E(void) {
  p28_L_735B();
  p28_L_757B();
  return;
}

/* flash page 28 cpu 0x772C (offset 0x372C) */
void p28_L_772C(void) {
  a = mem_read8(hl());
  p28_L_7E06();
  p28_L_77DA();
  a = 0x08;
  p28_L_78BF();
  a = b;
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p28_L_774E;
  a = 0x0C;
  p28_L_786A();
  a = 0x08;
  b = 0xFE;
  p28_L_797E();
  p28_L_770E();
  p28_L_7782();
  return;
  lab_p28_L_774E: ;
  a = 0x08;
  p28_L_78D2();
  p28_L_7D17();
  p28_L_7782();
  return;
}

/* flash page 28 cpu 0x7758 (offset 0x3758) */
void p28_L_7758(void) {
  /* di */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p28_L_778D();
  if (flag_c()) goto lab_p28_L_7789;
  p28_L_7EE2();
  p28_L_7E06();
  p28_L_6D10();
  p28_L_77DA();
  p28_L_7D17();
  p28_L_7782();
  return;
  lab_p28_L_7789: ;
  p00_L_3E0D();
  return;
}

/* flash page 28 cpu 0x7782 (offset 0x3782) */
void p28_L_7782(void) {
  p00_L_2B53();
  a = b;
  os_bcall(0x80CF);
  p00_L_3E0D();
  return;
}

/* flash page 28 cpu 0x778D (offset 0x378D) */
void p28_L_778D(void) {
  p00_L_2B53();
  a = b;
  mem_write8(0x8435, a);
  p28_L_74C1();
  a = b;
  lab_p28_L_7798: ;
  cpu_push_af();
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p28_L_77B7;
  cpu_pop_af();
  cpu_push_af();
  set_hl(0x4000);
  p00_L_2CCD();
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p28_L_77AE;
  lab_p28_L_77A9: ;
  cpu_pop_af();
  a = (uint8_t)(a - 0x04);
  goto lab_p28_L_7798;
  lab_p28_L_77AE: ;
  cpu_pop_af();
  cpu_push_af();
  p28_L_77BD();
  if (flag_c()) goto lab_p28_L_77BA;
  goto lab_p28_L_77A9;
  lab_p28_L_77B7: ;
  cpu_pop_af();
  /* scf */
  return;
  lab_p28_L_77BA: ;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x77BD (offset 0x37BD) */
void p28_L_77BD(void) {
  cpu_push_af();
  set_hl(0x4001);
  cpu_push_hl();
  c = 0xF0;
  p00_L_2B6B();
  if (flag_z()) goto lab_p28_L_77CD;
  cpu_pop_hl();
  cpu_pop_af();
  /* scf */
  return;
  lab_p28_L_77CD: ;
  cpu_pop_hl();
  cpu_pop_af();
  c = 0xFE;
  p00_L_2B6B();
  if (flag_z()) goto lab_p28_L_77D8;
  /* scf */
  return;
  lab_p28_L_77D8: ;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x77DA (offset 0x37DA) */
void p28_L_77DA(void) {
  a = 0xF0;
  mem_write8(0x8477, a);
  p28_L_7E7F();
  p28_L_735B();
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 7)));
  b = 0xFB;
  p28_L_7E85();
  p00_L_2B53();
  a = b;
  a = (uint8_t)(a + 1);
  p28_L_7E97();
  mem_write8(hl(), a);
  cpu_push_af();
  mem_write8(0x8435, a);
  p28_L_74C1();
  cpu_pop_af();
  flag_cmp(a, b);
  if (flag_z()) goto lab_p28_L_7811;
  a = b;
  cpu_push_af();
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p28_L_7826;
  cpu_pop_af();
  goto lab_p28_L_7812;
  lab_p28_L_7811: ;
  a = b;
  lab_p28_L_7812: ;
  a = (uint8_t)(a - 0x04);
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p28_L_7837;
  cpu_push_af();
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p28_L_782B;
  cpu_pop_af();
  goto lab_p28_L_7812;
  lab_p28_L_7826: ;
  b = 0xF7;
  p28_L_7E85();
  lab_p28_L_782B: ;
  cpu_pop_af();
  p28_L_7EA2();
  mem_write8(hl(), a);
  p28_L_757B();
  p28_L_7AD8();
  return;
  lab_p28_L_7837: ;
  p28_L_7EA2();
  mem_write8(hl(), 0x08);
  p28_L_757B();
  return;
}

/* flash page 28 cpu 0x7822 (offset 0x3822) */
void p28_L_7822(void) {
  goto lab_p28_L_7822;
  lab_p28_L_7812: ;
  a = (uint8_t)(a - 0x04);
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p28_L_7837;
  cpu_push_af();
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p28_L_782B;
  lab_p28_L_7822: ;
  cpu_ex_af();
  cpu_pop_af();
  goto lab_p28_L_7812;
  lab_p28_L_782B: ;
  cpu_pop_af();
  p28_L_7EA2();
  mem_write8(hl(), a);
  p28_L_757B();
  p28_L_7AD8();
  return;
  lab_p28_L_7837: ;
  p28_L_7EA2();
  mem_write8(hl(), 0x08);
  p28_L_757B();
  return;
}

/* flash page 28 cpu 0x783F (offset 0x383F) */
void p28_L_783F(void) {
  a = 0x08;
  cpu_push_af();
  cpu_pop_af();
  p28_L_7843();
  return;
}

/* flash page 28 cpu 0x7843 (offset 0x3843) */
void p28_L_7843(void) {
  goto lab_p28_L_7843;
  lab_p28_L_7842: ;
  cpu_pop_af();
  lab_p28_L_7843: ;
  p28_L_787C();
  cpu_push_af();
  cpu_push_af();
  a = b;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p28_L_7858;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p28_L_785E;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p28_L_7864;
  cpu_pop_af();
  cpu_pop_af();
  return;
  lab_p28_L_7858: ;
  cpu_pop_af();
  p28_L_78D2();
  goto lab_p28_L_7842;
  lab_p28_L_785E: ;
  cpu_pop_af();
  p28_L_7A09();
  goto lab_p28_L_7842;
  lab_p28_L_7864: ;
  cpu_pop_af();
  p28_L_786A();
  goto lab_p28_L_7842;
}

/* flash page 28 cpu 0x786A (offset 0x386A) */
void p28_L_786A(void) {
  cpu_push_af();
  b = 0xFE;
  p28_L_7DC5();
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8084);
  cpu_pop_af();
  b = 0xFC;
  p28_L_7DC5();
  return;
}

/* flash page 28 cpu 0x787C (offset 0x387C) */
void p28_L_787C(void) {
  lab_p28_L_787C: ;
  p28_L_78B5();
  if (flag_c()) goto lab_p28_L_78B2;
  p28_L_78BF();
  cpu_push_af();
  a = b;
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p28_L_7893;
  flag_cmp(a, 0x70);
  if (flag_z()) goto lab_p28_L_78AE;
  cpu_pop_af();
  a = (uint8_t)(a + 0x04);
  goto lab_p28_L_787C;
  lab_p28_L_7893: ;
  cpu_pop_af();
  cpu_push_af();
  p28_L_77BD();
  if (flag_c()) goto lab_p28_L_789F;
  cpu_pop_af();
  a = (uint8_t)(a + 0x04);
  goto lab_p28_L_787C;
  lab_p28_L_789F: ;
  cpu_pop_af();
  cpu_push_af();
  p28_L_78C9();
  if (flag_z()) goto lab_p28_L_78AA;
  cpu_pop_af();
  b = 0x01;
  return;
  lab_p28_L_78AA: ;
  cpu_pop_af();
  b = 0x03;
  return;
  lab_p28_L_78AE: ;
  cpu_pop_af();
  b = 0x02;
  return;
  lab_p28_L_78B2: ;
  b = 0x04;
  return;
}

/* flash page 28 cpu 0x78B5 (offset 0x38B5) */
void p28_L_78B5(void) {
  cpu_push_bc();
  p28_L_7EA2();
  b = a;
  a = mem_read8(hl());
  a = (uint8_t)(a - b);
  a = b;
  cpu_pop_bc();
  return;
}

/* flash page 28 cpu 0x78BF (offset 0x38BF) */
void p28_L_78BF(void) {
  cpu_push_af();
  set_hl(0x4000);
  os_bcall(0x8051);
  b = a;
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x78C9 (offset 0x38C9) */
void p28_L_78C9(void) {
  c = 0xFC;
  set_hl(0x4001);
  p00_L_2B6B();
  return;
}

/* flash page 28 cpu 0x78D2 (offset 0x38D2) */
void p28_L_78D2(void) {
  cpu_push_af();
  p28_L_7958();
  b = 0xFC;
  p28_L_797E();
  b = a;
  cpu_pop_af();
  p28_L_78DD();
  return;
}

/* flash page 28 cpu 0x78DD (offset 0x38DD) */
void p28_L_78DD(void) {
  p28_L_7987();
  p28_L_79E2();
  lab_p28_L_78E3: ;
  p28_L_78B5();
  if (flag_c()) goto lab_p28_L_794E;
  cpu_push_bc();
  a = c;
  p28_L_78BF();
  a = b;
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p28_L_78FD;
  flag_cmp(a, 0x70);
  if (flag_z()) goto lab_p28_L_78FD;
  cpu_pop_bc();
  lab_p28_L_78F7: ;
  a = c;
  a = (uint8_t)(a + 0x04);
  c = a;
  goto lab_p28_L_78E3;
  lab_p28_L_78FD: ;
  cpu_pop_bc();
  a = c;
  set_hl(0x4001);
  lab_p28_L_7902: ;
  cpu_push_bc();
  c = 0xFC;
  p00_L_2B6B();
  cpu_push_bc();
  cpu_pop_de();
  cpu_pop_bc();
  if (flag_z()) goto lab_p28_L_78F7;
  cpu_push_af();
  cpu_push_hl();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  cpu_push_bc();
  a = b;
  set_hl(0x4001);
  c = 0xFF;
  p00_L_2B6B();
  b = 0x16;
  p00_L_2B71();
  cpu_pop_bc();
  cpu_ex_de_hl();
  set_de(0x000D);
  a = 0;
  flag_logic(a);
  cpu_push_hl();
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p28_L_794A;
  cpu_pop_hl();
  cpu_pop_de();
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p28_L_7941;
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_hl();
  cpu_push_bc();
  p28_L_79C2();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_af();
  goto lab_p28_L_7902;
  lab_p28_L_7941: ;
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_bc();
  p28_L_7D99();
  cpu_pop_bc();
  goto lab_p28_L_7902;
  lab_p28_L_794A: ;
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_hl();
  lab_p28_L_794E: ;
  a = b;
  b = 0xF8;
  p28_L_797E();
  p28_L_79EA();
  return;
}

/* flash page 28 cpu 0x7958 (offset 0x3958) */
void p28_L_7958(void) {
  a = 0x08;
  lab_p28_L_795A: ;
  p00_L_24A9();
  if (flag_nz()) goto lab_p28_L_7963;
  flag_cmp(a, 0x68);
  goto lab_p28_L_7965;
  lab_p28_L_7963: ;
  flag_cmp(a, 0x14);
  lab_p28_L_7965: ;
  if (flag_z()) goto lab_p28_L_797C;
  p28_L_78BF();
  cpu_push_af();
  a = b;
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p28_L_7979;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p28_L_7979;
  cpu_pop_af();
  a = (uint8_t)(a + 0x04);
  goto lab_p28_L_795A;
  lab_p28_L_7979: ;
  cpu_pop_af();
  /* scf */
  return;
  lab_p28_L_797C: ;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x797E (offset 0x397E) */
void p28_L_797E(void) {
  cpu_push_af();
  set_de(0x4000);
  os_bcall(0x8021);
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x7987 (offset 0x3987) */
void p28_L_7987(void) {
  cpu_push_af();
  cpu_push_bc();
  set_hl(0x4001);
  lab_p28_L_798C: ;
  c = 0xFC;
  p00_L_2B6B();
  if (flag_z()) goto lab_p28_L_799E;
  cpu_pop_bc();
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_af();
  p28_L_79C2();
  cpu_pop_af();
  cpu_pop_hl();
  goto lab_p28_L_798C;
  lab_p28_L_799E: ;
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x79A1 (offset 0x39A1) */
void p28_L_79A1(void) {
  cpu_push_hl();
  cpu_push_af();
  a = b;
  set_hl(0x4001);
  c = 0xFF;
  p00_L_2B6B();
  b = a;
  cpu_push_hl();
  cpu_pop_de();
  cpu_pop_af();
  cpu_pop_hl();
  p00_L_2B77();
  cpu_push_af();
  cpu_push_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x25)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p28_L_79BF;
  p28_L_79CE();
  lab_p28_L_79BF: ;
  cpu_pop_de();
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x79C2 (offset 0x39C2) */
void p28_L_79C2(void) {
  p28_L_79A1();
  b = 0xF8;
  os_bcall(0x8021);
  p28_L_7B46();
  return;
}

/* flash page 28 cpu 0x79CE (offset 0x39CE) */
void p28_L_79CE(void) {
  cpu_push_de();
  cpu_push_bc();
  p00_L_19ED();
  cpu_pop_bc();
  a = b;
  mem_write8(0x83EE, a);
  cpu_pop_de();
  cpu_ex_de_hl();
  mem_write16(0x83EF, hl());
  cpu_ex_de_hl();
  p00_L_2EDD();
  return;
}

/* flash page 28 cpu 0x79E2 (offset 0x39E2) */
void p28_L_79E2(void) {
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p28_L_79E6;
  a = b;
  lab_p28_L_79E6: ;
  a = (uint8_t)(a + 0x04);
  c = a;
  return;
}

/* flash page 28 cpu 0x79EA (offset 0x39EA) */
void p28_L_79EA(void) {
  a = 0x08;
  lab_p28_L_79EC: ;
  p28_L_78B5();
  if (flag_c()) return;
  lab_p28_L_79F0: ;
  cpu_push_af();
  set_hl(0x4001);
  c = 0xF8;
  p00_L_2B6B();
  if (flag_z()) goto lab_p28_L_7A04;
  b = 0xF0;
  cpu_ex_de_hl();
  os_bcall(0x8021);
  cpu_pop_af();
  goto lab_p28_L_79F0;
  lab_p28_L_7A04: ;
  cpu_pop_af();
  a = (uint8_t)(a + 0x04);
  goto lab_p28_L_79EC;
}

/* flash page 28 cpu 0x7A09 (offset 0x3A09) */
void p28_L_7A09(void) {
  cpu_push_af();
  p28_L_7958();
  p28_L_7EB8();
  mem_write8(hl(), a);
  set_de(0x0012);
  p28_L_7E5C();
  p28_L_7AD0();
  b = 0x7C;
  p28_L_797E();
  b = a;
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  p28_L_7B21();
  cpu_pop_bc();
  cpu_pop_af();
  p28_L_7A37();
  cpu_push_af();
  a = b;
  b = 0x78;
  p28_L_797E();
  cpu_pop_af();
  os_bcall(0x8084);
  return;
}

/* flash page 28 cpu 0x7A37 (offset 0x3A37) */
void p28_L_7A37(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_af();
  a = b;
  a = (uint8_t)(a + 0x03);
  b = a;
  cpu_pop_af();
  a = (uint8_t)(a + 0x03);
  cpu_push_af();
  p28_L_7A5E();
  lab_p28_L_7A45: ;
  cpu_pop_af();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_af();
  p00_L_2C37();
  p28_L_7B46();
  cpu_pop_af();
  cpu_pop_bc();
  a = (uint8_t)(a - 1);
  b = (uint8_t)(b - 1);
  cpu_pop_de();
  cpu_push_af();
  d = (uint8_t)(d + 1);
  a = e;
  flag_cmp(a, d);
  if (flag_nz()) goto lab_p28_L_7A45;
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x7A5E (offset 0x3A5E) */
void p28_L_7A5E(void) {
  p28_L_7E97();
  d = mem_read8(hl());
  cpu_push_af();
  a = (uint8_t)(a - b);
  if (flag_c()) goto lab_p28_L_7A69;
  cpu_pop_af();
  goto lab_p28_L_7A6B;
  lab_p28_L_7A69: ;
  cpu_pop_af();
  a = b;
  lab_p28_L_7A6B: ;
  a = (uint8_t)(a - d);
  a = (uint8_t)(a + 1);
  e = a;
  d = 0x00;
  return;
}

/* flash page 28 cpu 0x7A71 (offset 0x3A71) */
void p28_L_7A71(void) {
  b = 0x78;
  p28_L_7AF1();
  b = a;
  set_hl(0x4001);
  os_bcall(0x8051);
  flag_cmp(a, 0xFF);
  if (flag_z()) { p28_L_7AB9(); return; }
  cpu_push_bc();
  p28_L_7B0D();
  cpu_pop_bc();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p28_L_7AA2;
  p28_L_7AB9();
  cpu_push_af();
  b = 0xFF;
  p28_L_7AF1();
  p28_L_7ECE();
  mem_write8(hl(), a);
  set_de(0x0013);
  p28_L_7E5C();
  p28_L_7AD0();
  goto lab_p28_L_7AA7;
  lab_p28_L_7AA2: ;
  p28_L_7AB9();
  cpu_push_af();
  a = b;
  lab_p28_L_7AA7: ;
  b = 0xFC;
  p28_L_797E();
  b = a;
  cpu_pop_af();
  cpu_push_bc();
  p28_L_7B21();
  cpu_pop_af();
  b = 0xF8;
  p28_L_797E();
  return;
}

/* flash page 28 cpu 0x7AB9 (offset 0x3AB9) */
void p28_L_7AB9(void) {
  a = b;
  p28_L_7EA2();
  b = mem_read8(hl());
  p28_L_7A37();
  return;
}

/* flash page 28 cpu 0x7AC2 (offset 0x3AC2) */
void p28_L_7AC2(void) {
  set_de(0x0011);
  p28_L_7E5C();
  p28_L_7AD0();
  p28_L_7EAD();
  mem_write8(hl(), a);
  return;
}

/* flash page 28 cpu 0x7AD0 (offset 0x3AD0) */
void p28_L_7AD0(void) {
  cpu_ex_de_hl();
  cpu_push_af();
  b = a;
  p28_L_7DE3();
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x7AD8 (offset 0x3AD8) */
void p28_L_7AD8(void) {
  p28_L_7E8C();
  flag_set_z((mem_read8(hl()) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p28_L_7AEB;
  p28_L_7EA2();
  a = mem_read8(hl());
  b = 0x70;
  set_de(0x4000);
  os_bcall(0x8021);
  lab_p28_L_7AEB: ;
  a = 0xFE;
  p28_L_7AC2();
  return;
}

/* flash page 28 cpu 0x7AF1 (offset 0x3AF1) */
void p28_L_7AF1(void) {
  a = 0x08;
  p28_L_7AF3();
  return;
}

/* flash page 28 cpu 0x7AF3 (offset 0x3AF3) */
void p28_L_7AF3(void) {
  lab_p28_L_7AF3: ;
  cpu_push_af();
  p28_L_78B5();
  if (flag_c()) goto lab_p28_L_7B07;
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, b);
  if (flag_z()) goto lab_p28_L_7B0A;
  cpu_pop_af();
  a = (uint8_t)(a + 0x04);
  goto lab_p28_L_7AF3;
  lab_p28_L_7B07: ;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  return;
  lab_p28_L_7B0A: ;
  cpu_pop_af();
  /* scf */
  return;
}

/* flash page 28 cpu 0x7B0D (offset 0x3B0D) */
void p28_L_7B0D(void) {
  b = 0xFF;
  p28_L_7AF1();
  if (flag_nc()) goto lab_p28_L_7B1F;
  b = 0xFF;
  p28_L_7AF3();
  a = 0x01;
  if (flag_nc()) return;
  a = 0x02;
  return;
  lab_p28_L_7B1F: ;
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x7B21 (offset 0x3B21) */
void p28_L_7B21(void) {
  cpu_push_af();
  cpu_push_bc();
  set_hl(0x4001);
  lab_p28_L_7B26: ;
  c = 0xFC;
  p00_L_2B6B();
  if (flag_z()) goto lab_p28_L_7B3B;
  cpu_pop_bc();
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_af();
  p28_L_7B3E();
  cpu_pop_af();
  cpu_pop_hl();
  p28_L_7D99();
  goto lab_p28_L_7B26;
  lab_p28_L_7B3B: ;
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x7B3E (offset 0x3B3E) */
void p28_L_7B3E(void) {
  p28_L_79A1();
  flag_set_z((mem_read8((uint16_t)(iy + 0x25)) & (1u << 4)) == 0);
  if (flag_nz()) return;
  p28_L_7B46();
  return;
}

/* flash page 28 cpu 0x7B46 (offset 0x3B46) */
void p28_L_7B46(void) {
  a = 0x01;
  mem_write8(0x8476, a);
  p00_L_01BF();
  return;
}

/* flash page 28 cpu 0x7B4F (offset 0x3B4F) */
void p28_L_7B4F(void) {
  b = 0x78;
  p28_L_7AF1();
  os_bcall(0x8084);
  return;
}

/* flash page 28 cpu 0x7B58 (offset 0x3B58) */
void p28_L_7B58(void) {
  a = 0x08;
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0xFE);
  if (flag_z()) return;
  b = a;
  a = 0x0C;
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0xFE);
  if (flag_z()) return;
  c = a;
  a = b;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p28_L_7B7C;
  a = c;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p28_L_7B80;
  /* scf */
  return;
  lab_p28_L_7B7C: ;
  a = 0x08;
  goto lab_p28_L_7B82;
  lab_p28_L_7B80: ;
  a = 0x0C;
  lab_p28_L_7B82: ;
  b = 0xFE;
  p28_L_797E();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x7B89 (offset 0x3B89) */
void p28_L_7B89(void) {
  p28_L_7958();
  cpu_push_af();
  b = 0xFC;
  p28_L_797E();
  cpu_pop_bc();
  cpu_push_bc();
  a = 0x08;
  p28_L_7B21();
  cpu_pop_af();
  b = 0xF8;
  p28_L_797E();
  p28_L_7B9F();
  return;
}

/* flash page 28 cpu 0x7B9F (offset 0x3B9F) */
void p28_L_7B9F(void) {
  a = 0x08;
  os_bcall(0x8084);
  a = 0x08;
  b = 0xFE;
  p28_L_797E();
  return;
}

/* flash page 28 cpu 0x7BAC (offset 0x3BAC) */
void p28_L_7BAC(void) {
  p28_L_7E97();
  a = mem_read8(hl());
  a = (uint8_t)(a - 1);
  mem_write8(0x8435, a);
  p28_L_74C1();
  a = b;
  lab_p28_L_7BB8: ;
  cpu_push_af();
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0xF8);
  if (flag_nz()) goto lab_p28_L_7BCA;
  cpu_pop_af();
  cpu_push_af();
  b = 0xF0;
  p28_L_797E();
  lab_p28_L_7BCA: ;
  cpu_pop_af();
  a = (uint8_t)(a - 0x04);
  flag_cmp(a, 0x08);
  if (flag_nc()) goto lab_p28_L_7BB8;
  p28_L_770E();
  return;
}

/* flash page 28 cpu 0x7BE3 (offset 0x3BE3) */
void p28_L_7BE3(void) {
  set_de(0x000E);
  p28_L_7E5C();
  p28_L_7F0D();
  p00_L_2CCD();
  b = a;
  a = a & 0x01;
  flag_logic(a);
  if (flag_z()) goto lab_p28_L_7C11;
  a = b;
  a = a & 0x04;
  flag_logic(a);
  if (flag_nz()) { p28_L_7C20(); return; }
  p28_L_7E7F();
  p28_L_7C2C();
  p28_L_7E19();
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) | (1u << 4)));
  p28_L_7C3B();
  p28_L_7C20();
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 4)));
  return;
  lab_p28_L_7C11: ;
  p28_L_7E7F();
  p28_L_7C2C();
  p28_L_7E37();
  p28_L_728E();
  p00_L_1960();
  p28_L_7C20();
  return;
}

/* flash page 28 cpu 0x7C20 (offset 0x3C20) */
void p28_L_7C20(void) {
  p00_L_2B53();
  a = b;
  os_bcall(0x80CF);
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) | (1u << 2)));
  p28_L_7C2B();
  return;
}

/* flash page 28 cpu 0x7C2B (offset 0x3C2B) */
void p28_L_7C2B(void) {
  return;
}

/* flash page 28 cpu 0x7C2C (offset 0x3C2C) */
void p28_L_7C2C(void) {
  p28_L_7EE2();
  a = 0x08;
  a = (uint8_t)(a - 1);
  mem_write8(0x97A6, a);
  a = 0xF0;
  mem_write8(0x8477, a);
  return;
}

/* flash page 28 cpu 0x7C3B (offset 0x3C3B) */
void p28_L_7C3B(void) {
  p28_L_7B46();
  p28_L_7EAD();
  a = mem_read8(hl());
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p28_L_7C5F;
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p28_L_7C64;
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p28_L_7CE2;
  flag_cmp(a, 0xF8);
  if (flag_z()) goto lab_p28_L_7CF6;
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p28_L_7CFF;
  flag_cmp(a, 0xE0);
  if (flag_z()) goto lab_p28_L_7D4C;
  return;
  lab_p28_L_7C5F: ;
  p28_L_7AD8();
  goto lab_p28_L_7CA0;
  lab_p28_L_7C64: ;
  p28_L_7DEA();
  if (flag_nc()) goto lab_p28_L_7C75;
  cpu_push_af();
  os_bcall(0x8084);
  cpu_pop_af();
  b = 0xFC;
  p28_L_7DC5();
  goto lab_p28_L_7CA0;
  lab_p28_L_7C75: ;
  p28_L_7EA2();
  a = mem_read8(hl());
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p28_L_7C8E;
  a = (uint8_t)(a + 0x04);
  p28_L_78BF();
  cpu_push_af();
  a = b;
  flag_cmp(a, 0xFC);
  if (flag_nz()) goto lab_p28_L_7C8B;
  cpu_pop_af();
  goto lab_p28_L_7C95;
  lab_p28_L_7C8B: ;
  cpu_pop_af();
  goto lab_p28_L_7CA3;
  lab_p28_L_7C8E: ;
  b = 0xFC;
  p28_L_7AF1();
  if (flag_nc()) goto lab_p28_L_7CA3;
  lab_p28_L_7C95: ;
  cpu_push_af();
  os_bcall(0x8084);
  cpu_pop_bc();
  p28_L_7D53();
  p28_L_78DD();
  lab_p28_L_7CA0: ;
  p28_L_7D17();
  return;
  lab_p28_L_7CA3: ;
  p28_L_7EA2();
  a = mem_read8(hl());
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p28_L_7CBC;
  a = (uint8_t)(a + 0x04);
  p28_L_78BF();
  cpu_push_af();
  a = b;
  flag_cmp(a, 0xF8);
  if (flag_nz()) goto lab_p28_L_7CB9;
  cpu_pop_af();
  goto lab_p28_L_7CC3;
  lab_p28_L_7CB9: ;
  cpu_pop_af();
  goto lab_p28_L_7CC6;
  lab_p28_L_7CBC: ;
  b = 0xF8;
  p28_L_7AF1();
  if (flag_nc()) goto lab_p28_L_7CC6;
  lab_p28_L_7CC3: ;
  p28_L_79EA();
  lab_p28_L_7CC6: ;
  b = 0x7C;
  p28_L_7AF1();
  if (flag_nc()) goto lab_p28_L_7CD2;
  os_bcall(0x8084);
  p28_L_7D17();
  return;
  lab_p28_L_7CD2: ;
  b = 0x78;
  p28_L_7AF1();
  if (flag_nc()) { p28_L_7D17(); return; }
  p28_L_7EA2();
  a = mem_read8(hl());
  os_bcall(0x8084);
  p28_L_7D21();
  return;
  lab_p28_L_7CE2: ;
  p28_L_7EA2();
  a = mem_read8(hl());
  os_bcall(0x8084);
  p28_L_7ECE();
  a = mem_read8(hl());
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p28_L_7D26;
  os_bcall(0x8084);
  goto lab_p28_L_7D26;
  lab_p28_L_7CF6: ;
  p28_L_7EB8();
  a = mem_read8(hl());
  os_bcall(0x8084);
  goto lab_p28_L_7D37;
  lab_p28_L_7CFF: ;
  b = 0xFC;
  p28_L_7AF1();
  if (flag_c()) goto lab_p28_L_7D12;
  b = 0xF8;
  p28_L_7AF1();
  if (flag_nc()) goto lab_p28_L_7D41;
  p28_L_7B9F();
  goto lab_p28_L_7D47;
  lab_p28_L_7D12: ;
  os_bcall(0x8084);
  goto lab_p28_L_7D41;
  lab_p28_L_7D26: ;
  p28_L_7A71();
  p28_L_7B46();
  a = 0xF8;
  p28_L_7AC2();
  p28_L_7B4F();
  p28_L_7B46();
  lab_p28_L_7D37: ;
  p28_L_7B58();
  if (flag_nc()) goto lab_p28_L_7D47;
  a = 0xF0;
  p28_L_7AC2();
  lab_p28_L_7D41: ;
  p28_L_7B89();
  p28_L_7B46();
  lab_p28_L_7D47: ;
  a = 0xE0;
  p28_L_7AC2();
  lab_p28_L_7D4C: ;
  p28_L_7BAC();
  p28_L_7B46();
  return;
}

/* flash page 28 cpu 0x7D11 (offset 0x3D11) */
void p28_L_7D11(void) {
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  os_bcall(0x8084);
  goto lab_p28_L_7D41;
  lab_p28_L_7D41: ;
  p28_L_7B89();
  p28_L_7B46();
  a = 0xE0;
  p28_L_7AC2();
  p28_L_7BAC();
  p28_L_7B46();
  return;
}

/* flash page 28 cpu 0x7D17 (offset 0x3D17) */
void p28_L_7D17(void) {
  p28_L_783F();
  p28_L_7D1A();
  return;
}

/* flash page 28 cpu 0x7D1A (offset 0x3D1A) */
void p28_L_7D1A(void) {
  p28_L_7E8C();
  flag_set_z((mem_read8(hl()) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p28_L_7D37;
  p28_L_7D21();
  return;
  lab_p28_L_7D37: ;
  p28_L_7B58();
  if (flag_nc()) goto lab_p28_L_7D47;
  a = 0xF0;
  p28_L_7AC2();
  p28_L_7B89();
  p28_L_7B46();
  lab_p28_L_7D47: ;
  a = 0xE0;
  p28_L_7AC2();
  p28_L_7BAC();
  p28_L_7B46();
  return;
}

/* flash page 28 cpu 0x7D21 (offset 0x3D21) */
void p28_L_7D21(void) {
  a = 0xFC;
  p28_L_7AC2();
  p28_L_7A71();
  p28_L_7B46();
  a = 0xF8;
  p28_L_7AC2();
  p28_L_7B4F();
  p28_L_7B46();
  p28_L_7B58();
  if (flag_nc()) goto lab_p28_L_7D47;
  a = 0xF0;
  p28_L_7AC2();
  p28_L_7B89();
  p28_L_7B46();
  lab_p28_L_7D47: ;
  a = 0xE0;
  p28_L_7AC2();
  p28_L_7BAC();
  p28_L_7B46();
  return;
}

/* flash page 28 cpu 0x7D53 (offset 0x3D53) */
void p28_L_7D53(void) {
  a = b;
  mem_write8(0x8436, a);
  b = 0xFC;
  p28_L_797E();
  a = 0x08;
  mem_write8(0x8435, a);
  lab_p28_L_7D61: ;
  p28_L_78B5();
  if (flag_c()) goto lab_p28_L_7D8B;
  cpu_push_af();
  set_hl(0x4001);
  lab_p28_L_7D6A: ;
  c = 0xF8;
  p00_L_2B6B();
  if (flag_z()) goto lab_p28_L_7D86;
  cpu_push_af();
  a = mem_read8(0x8436);
  b = a;
  cpu_pop_af();
  mem_write8(0x8435, a);
  cpu_push_af();
  cpu_push_hl();
  p28_L_7B3E();
  cpu_pop_hl();
  cpu_pop_af();
  p28_L_7D99();
  goto lab_p28_L_7D6A;
  lab_p28_L_7D86: ;
  cpu_pop_af();
  a = (uint8_t)(a + 0x04);
  goto lab_p28_L_7D61;
  lab_p28_L_7D8B: ;
  a = mem_read8(0x8435);
  p28_L_74C1();
  a = b;
  cpu_push_af();
  a = mem_read8(0x8436);
  b = a;
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x7D99 (offset 0x3D99) */
void p28_L_7D99(void) {
  p28_L_7DBE();
  cpu_push_af();
  os_bcall(0x8051);
  e = a;
  cpu_pop_af();
  p28_L_7DBE();
  cpu_push_af();
  os_bcall(0x8051);
  d = a;
  cpu_pop_af();
  p28_L_7DBE();
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  p00_L_2CC7();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  return;
}

/* flash page 28 cpu 0x7DBE (offset 0x3DBE) */
void p28_L_7DBE(void) {
  set_hl((uint16_t)(hl() + 1));
  p00_L_23FC();
  if (flag_nc()) return;
  a = (uint8_t)(a + 1);
  return;
}

/* flash page 28 cpu 0x7DC5 (offset 0x3DC5) */
void p28_L_7DC5(void) {
  cpu_push_bc();
  /* sra a */
  /* sra a */
  a = (uint8_t)(a - 0x02);
  cpu_push_af();
  p28_L_7DCD();
  return;
}

/* flash page 28 cpu 0x7DCD (offset 0x3DCD) */
void p28_L_7DCD(void) {
  d = 0x00;
  e = a;
  p28_L_7EC3();
  set_hl((uint16_t)(hl() + de()));
  a = b;
  mem_write8(hl(), a);
  set_de(0x0014);
  p28_L_7E5C();
  cpu_pop_af();
  d = 0x00;
  e = a;
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  cpu_pop_bc();
  p28_L_7DE3();
  return;
}

/* flash page 28 cpu 0x7DE3 (offset 0x3DE3) */
void p28_L_7DE3(void) {
  p28_L_7F0D();
  os_bcall(0x8021);
  return;
}

/* flash page 28 cpu 0x7DEA (offset 0x3DEA) */
void p28_L_7DEA(void) {
  b = 0x00;
  p28_L_7EC3();
  lab_p28_L_7DEF: ;
  a = mem_read8(hl());
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p28_L_7DFD;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b + 1);
  a = b;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p28_L_7DEF;
  a = a | a;
  flag_logic(a);
  return;
  lab_p28_L_7DFD: ;
  a = b;
  a = (uint8_t)(a + 0x02);
  /* sla a */
  /* sla a */
  /* scf */
  return;
}

/* flash page 28 cpu 0x7E06 (offset 0x3E06) */
void p28_L_7E06(void) {
  os_bcall(0x8057);
  p00_L_2BE9();
  os_bcall(0x8060);
  return;
}

/* flash page 28 cpu 0x7E10 (offset 0x3E10) */
void p28_L_7E10(void) {
  p28_L_7E7F();
  p28_L_735B();
  p28_L_757B();
  return;
}

/* flash page 28 cpu 0x7E19 (offset 0x3E19) */
void p28_L_7E19(void) {
  set_hl(0x9D8D);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3EEB();
  p28_L_7E52();
  set_hl(0x2834);
  a = 0x72;
  /* nop */
  p28_L_7E47();
  p00_L_3CD5();
  set_hl(0x283C);
  a = 0x73;
  p28_L_7E47();
  return;
}

/* flash page 28 cpu 0x7E2B (offset 0x3E2B) */
void p28_L_7E2B(void) {
  b = a;
  a = mem_read8(hl());
  p00_L_3CD5();
  set_hl(0x283C);
  a = 0x73;
  p28_L_7E47();
  return;
}

/* flash page 28 cpu 0x7E37 (offset 0x3E37) */
void p28_L_7E37(void) {
  set_hl(0x9D8D);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3EEB();
  p28_L_7E52();
  set_hl(0x276D);
  a = 0x4F;
  p28_L_7E47();
  return;
}

/* flash page 28 cpu 0x7E47 (offset 0x3E47) */
void p28_L_7E47(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3C87();
  return;
}

/* flash page 28 cpu 0x7E52 (offset 0x3E52) */
void p28_L_7E52(void) {
  p00_L_3D05();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  return;
}

/* flash page 28 cpu 0x7E5C (offset 0x3E5C) */
void p28_L_7E5C(void) {
  cpu_push_af();
  p00_L_24A9();
  if (flag_z()) goto lab_p28_L_7E68;
  p00_L_2B7D();
  lab_p28_L_7E65: ;
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_af();
  return;
  lab_p28_L_7E68: ;
  p28_L_7E71();
  a = e;
  a = (uint8_t)(a - 0x0E);
  e = a;
  goto lab_p28_L_7E65;
}

/* flash page 28 cpu 0x7E71 (offset 0x3E71) */
void p28_L_7E71(void) {
  cpu_push_bc();
  cpu_push16(ix);
  os_bcall(0x8057);
  set_bc(0x1DEA);
  set_hl((uint16_t)(hl() + bc()));
  ix = cpu_pop16();
  cpu_pop_bc();
  p28_L_7E7E();
  return;
}

/* flash page 28 cpu 0x7E7E (offset 0x3E7E) */
void p28_L_7E7E(void) {
  return;
}

/* flash page 28 cpu 0x7E7F (offset 0x3E7F) */
void p28_L_7E7F(void) {
  a = 0x03;
  p00_L_2B83();
  return;
}

/* flash page 28 cpu 0x7E85 (offset 0x3E85) */
void p28_L_7E85(void) {
  p28_L_7E8C();
  a = b;
  /* and (hl) */
  mem_write8(hl(), a);
  return;
}

/* flash page 28 cpu 0x7E8C (offset 0x3E8C) */
void p28_L_7E8C(void) {
  set_hl(0x837B);
  p00_L_24A9();
  if (flag_nz()) return;
  set_hl(0x82A5);
  return;
}

/* flash page 28 cpu 0x7E97 (offset 0x3E97) */
void p28_L_7E97(void) {
  set_hl(0x837C);
  p00_L_24A9();
  if (flag_nz()) return;
  set_hl(0x82A6);
  return;
}

/* flash page 28 cpu 0x7EA2 (offset 0x3EA2) */
void p28_L_7EA2(void) {
  set_hl(0x837D);
  p00_L_24A9();
  if (flag_nz()) return;
  set_hl(0x82A7);
  return;
}

/* flash page 28 cpu 0x7EAD (offset 0x3EAD) */
void p28_L_7EAD(void) {
  set_hl(0x837E);
  p00_L_24A9();
  if (flag_nz()) return;
  set_hl(0x82A8);
  return;
}

/* flash page 28 cpu 0x7EB8 (offset 0x3EB8) */
void p28_L_7EB8(void) {
  set_hl(0x837F);
  p00_L_24A9();
  if (flag_nz()) return;
  set_hl(0x82A9);
  return;
}

/* flash page 28 cpu 0x7EC3 (offset 0x3EC3) */
void p28_L_7EC3(void) {
  set_hl(0x8381);
  p00_L_24A9();
  if (flag_nz()) return;
  set_hl(0x82AB);
  return;
}

/* flash page 28 cpu 0x7ECE (offset 0x3ECE) */
void p28_L_7ECE(void) {
  set_hl(0x8380);
  p00_L_24A9();
  if (flag_nz()) return;
  set_hl(0x82AA);
  return;
}

/* flash page 28 cpu 0x7ED9 (offset 0x3ED9) */
void p28_L_7ED9(void) {
  a = 0x15;
  p00_L_24A9();
  if (flag_nz()) return;
  a = 0x69;
  return;
}

/* flash page 28 cpu 0x7EE2 (offset 0x3EE2) */
void p28_L_7EE2(void) {
  p28_L_7EE9();
  os_bcall(0x80CF);
  return;
}

/* flash page 28 cpu 0x7EE9 (offset 0x3EE9) */
void p28_L_7EE9(void) {
  a = 0x17;
  p00_L_24A9();
  if (flag_nz()) return;
  a = 0x6B;
  return;
}

/* flash page 28 cpu 0x7EF2 (offset 0x3EF2) */
void p28_L_7EF2(void) {
  a = b;
  a = (uint8_t)(a - 0x08);
  set_hl(0x8697);
  c = a;
  b = 0x00;
  /* sra c */
  /* sra c */
  /* sra c */
  set_hl((uint16_t)(hl() + bc()));
  a = a & 0x07;
  flag_logic(a);
  c = a;
  b = c;
  a = 0x80;
  b = (uint8_t)(b + 1);
  lab_p28_L_7F09: ;
  cpu_rlca();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p28_L_7F09;
  return;
}

/* flash page 28 cpu 0x7F0D (offset 0x3F0D) */
void p28_L_7F0D(void) {
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  p28_L_7F11();
  return;
}

/* flash page 28 cpu 0x7F11 (offset 0x3F11) */
void p28_L_7F11(void) {
  a = 0x1E;
  if (flag_z()) return;
  a = 0x7E;
  return;
}

/* flash page 28 cpu 0x7F30 (offset 0x3F30) */
void p28_L_7F30(void) {
  /* di */
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  cpu_push_af();
  a = 0x01;
  /* nop */
  /* di */
  /* nop */
  /* nop */
  /* im 1 */
  p28_L_7F3E();
  return;
}

/* flash page 28 cpu 0x7F3E (offset 0x3F3E) */
void p28_L_7F3E(void) {
  /* di */
  hw_out(0x14, a);
  /* di */
  p00_L_01F8();
  cpu_pop_af();
  p28_L_7EE2();
  p28_L_7E06();
  p28_L_77DA();
  p28_L_7F58();
  cpu_push_af();
  p28_L_7782();
  cpu_pop_af();
  return;
}

/* flash page 28 cpu 0x7F58 (offset 0x3F58) */
void p28_L_7F58(void) {
  p28_L_7F63();
  cpu_push_de();
  p28_L_7D1A();
  cpu_pop_de();
  a = e;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 28 cpu 0x7F63 (offset 0x3F63) */
void p28_L_7F63(void) {
  a = 0x08;
  set_de(0x0000);
  cpu_push_af();
  lab_p28_L_7F69: ;
  cpu_pop_af();
  p28_L_7F97();
  cpu_push_af();
  cpu_push_af();
  a = b;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p28_L_7F7F;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p28_L_7F86;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p28_L_7F8D;
  cpu_pop_af();
  cpu_pop_af();
  return;
  lab_p28_L_7F7F: ;
  cpu_pop_af();
  cpu_push_de();
  p28_L_78D2();
  goto lab_p28_L_7F92;
  lab_p28_L_7F86: ;
  cpu_pop_af();
  cpu_push_de();
  p28_L_7A09();
  goto lab_p28_L_7F92;
  lab_p28_L_7F8D: ;
  cpu_pop_af();
  cpu_push_de();
  p28_L_786A();
  lab_p28_L_7F92: ;
  cpu_pop_de();
  e = 0x01;
  goto lab_p28_L_7F69;
}

/* flash page 28 cpu 0x7F97 (offset 0x3F97) */
void p28_L_7F97(void) {
  lab_p28_L_7F97: ;
  cpu_push_de();
  p28_L_78B5();
  if (flag_c()) goto lab_p28_L_7FE1;
  p28_L_78BF();
  cpu_pop_de();
  cpu_push_af();
  a = b;
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p28_L_7FB6;
  flag_cmp(a, 0x70);
  if (flag_z()) goto lab_p28_L_7FDD;
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p28_L_7FB1;
  d = 0x01;
  lab_p28_L_7FB1: ;
  cpu_pop_af();
  a = (uint8_t)(a + 0x04);
  goto lab_p28_L_7F97;
  lab_p28_L_7FB6: ;
  cpu_pop_af();
  cpu_push_af();
  cpu_push_de();
  p28_L_77BD();
  cpu_pop_de();
  if (flag_c()) goto lab_p28_L_7FCC;
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p28_L_7FC8;
  cpu_pop_af();
  a = (uint8_t)(a + 0x04);
  goto lab_p28_L_7F97;
  lab_p28_L_7FC8: ;
  cpu_pop_af();
  b = 0x01;
  return;
  lab_p28_L_7FCC: ;
  cpu_pop_af();
  cpu_push_af();
  cpu_push_de();
  p28_L_78C9();
  cpu_pop_de();
  if (flag_z()) goto lab_p28_L_7FD9;
  cpu_pop_af();
  b = 0x01;
  return;
  lab_p28_L_7FD9: ;
  cpu_pop_af();
  b = 0x03;
  return;
  lab_p28_L_7FDD: ;
  cpu_pop_af();
  b = 0x02;
  return;
  lab_p28_L_7FE1: ;
  cpu_pop_de();
  b = 0x04;
  return;
}


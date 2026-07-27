/* Recovered from flash page 6 (mechanical ASM->C) */
/* cpu window 0x4000..0x7FFF prefix=p06_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p06_str_1(void);
void p06_L_4008(void);
void p06_L_4021(void);
void p06_L_403E(void);
void p06_L_404B(void);
void p06_L_4080(void);
void p06_L_4089(void);
void p06_L_408A(void);
void p06_L_40D5(void);
void p06_L_40E3(void);
void p06_L_40FE(void);
void p06_L_4100(void);
void p06_L_4152(void);
void p06_L_417F(void);
void p06_L_4216(void);
void p06_L_427F(void);
void p06_L_4286(void);
void p06_L_4289(void);
void p06_L_428C(void);
void p06_L_428D(void);
void p06_L_4296(void);
void p06_L_42A3(void);
void p06_L_42CC(void);
void p06_L_42E6(void);
void p06_L_433C(void);
void p06_L_4344(void);
void p06_L_4369(void);
void p06_L_4378(void);
void p06_L_4391(void);
void p06_L_43A1(void);
void p06_L_43BE(void);
void p06_L_43DA(void);
void p06_L_43F4(void);
void p06_L_4443(void);
void p06_L_444C(void);
void p06_L_445C(void);
void p06_L_445F(void);
void p06_L_4463(void);
void p06_L_4467(void);
void p06_L_4477(void);
void p06_L_4492(void);
void p06_L_4493(void);
void p06_L_449C(void);
void p06_L_44BE(void);
void p06_L_44C1(void);
void p06_L_44C8(void);
void p06_L_44D5(void);
void p06_L_44EB(void);
void p06_L_44FD(void);
void p06_L_4501(void);
void p06_L_453B(void);
void p06_L_453F(void);
void p06_L_4589(void);
void p06_L_45A8(void);
void p06_L_45C4(void);
void p06_L_45F4(void);
void p06_L_4609(void);
void p06_L_4635(void);
void p06_L_4656(void);
void p06_L_4671(void);
void p06_L_46DE(void);
void p06_L_46FC(void);
void p06_L_473C(void);
void p06_L_474F(void);
void p06_L_4795(void);
void p06_L_47D1(void);
void p06_L_47DA(void);
void p06_L_47E3(void);
void p06_L_47F4(void);
void p06_L_4815(void);
void p06_L_4825(void);
void p06_L_4826(void);
void p06_L_4829(void);
void p06_L_483D(void);
void p06_L_4844(void);
void p06_L_4868(void);
void p06_L_4871(void);
void p06_L_487F(void);
void p06_L_492D(void);
void p06_L_4953(void);
void p06_L_498B(void);
void p06_L_49BE(void);
void p06_L_49E7(void);
void p06_L_49FD(void);
void p06_L_4A95(void);
void p06_L_4B1B(void);
void p06_L_4B22(void);
void p06_L_4C89(void);
void p06_L_4CFC(void);
void p06_L_4D0E(void);
void p06_L_4D15(void);
void p06_L_4D86(void);
void p06_L_4E29(void);
void p06_L_4E35(void);
void p06_L_4EB1(void);
void p06_L_5070(void);
void p06_L_50DE(void);
void p06_L_50F0(void);
void p06_L_5189(void);
void p06_L_51DB(void);
void p06_L_5250(void);
void p06_L_5297(void);
void p06_L_52CD(void);
void p06_L_52EC(void);
void p06_L_52FA(void);
void p06_L_5308(void);
void p06_L_5316(void);
void p06_L_5333(void);
void p06_L_5341(void);
void p06_L_5350(void);
void p06_L_53F6(void);
void p06_L_549D(void);
void p06_L_54B1(void);
void p06_L_555D(void);
void p06_L_557D(void);
void p06_L_558C(void);
void p06_L_5599(void);
void p06_L_55A8(void);
void p06_L_55AA(void);
void p06_L_55D0(void);
void p06_L_563A(void);
void p06_L_563D(void);
void p06_L_563E(void);
void p06_L_5797(void);
void p06_L_57AA(void);
void p06_L_57AE(void);
void p06_L_57B9(void);
void p06_L_57C0(void);
void p06_L_57C2(void);
void p06_L_57C9(void);
void p06_L_57DC(void);
void p06_L_57F9(void);
void p06_L_57FD(void);
void p06_L_5837(void);
void p06_L_58E1(void);
void p06_L_58F5(void);
void p06_L_5923(void);
void p06_L_59FE(void);
void p06_L_5AD6(void);
void p06_L_5AE7(void);
void p06_L_5B09(void);
void p06_L_5B20(void);
void p06_L_5B54(void);
void p06_L_5B75(void);
void p06_L_5BC4(void);
void p06_L_5BCD(void);
void p06_L_5C0C(void);
void p06_L_5C19(void);
void p06_L_5C22(void);
void p06_L_5C48(void);
void p06_L_5C4D(void);
void p06_L_5C52(void);
void p06_L_5C5B(void);
void p06_L_5C75(void);
void p06_L_5C7E(void);
void p06_L_5C93(void);
void p06_L_5CA3(void);
void p06_L_5CD6(void);
void p06_L_5CF0(void);
void p06_L_5D0F(void);
void p06_L_5D34(void);
void p06_L_5D6C(void);
void p06_L_5DBF(void);
void p06_L_5DC2(void);
void p06_L_5DC3(void);
void p06_L_5DDB(void);
void p06_L_5DDF(void);
void p06_L_5DF9(void);
void p06_L_5F45(void);
void p06_L_5F54(void);
void p06_L_5F57(void);
void p06_L_5F93(void);
void p06_L_5F9C(void);
void p06_L_5FA2(void);
void p06_L_5FA8(void);
void p06_L_5FD5(void);
void p06_L_600A(void);
void p06_L_6041(void);
void p06_L_6043(void);
void p06_L_6055(void);
void p06_L_6063(void);
void p06_L_6079(void);
void p06_L_6126(void);
void p06_L_618B(void);
void p06_L_6192(void);
void p06_L_622D(void);
void p06_L_6250(void);
void p06_L_6352(void);
void p06_L_645A(void);
void p06_L_6464(void);
void p06_L_6486(void);
void p06_L_64A3(void);
void p06_L_64CA(void);
void p06_L_64D6(void);
void p06_L_6506(void);
void p06_L_650F(void);
void p06_L_652D(void);
void p06_L_6539(void);
void p06_L_6558(void);
void p06_L_6571(void);
void p06_L_6589(void);
void p06_L_659C(void);
void p06_L_65AF(void);
void p06_L_65B6(void);
void p06_L_65CB(void);
void p06_L_65D9(void);
void p06_L_65EB(void);
void p06_L_6605(void);
void p06_L_6613(void);
void p06_L_6618(void);
void p06_L_661F(void);
void p06_L_66C4(void);
void p06_L_66FC(void);
void p06_L_671A(void);
void p06_L_672A(void);
void p06_L_673A(void);
void p06_L_674B(void);
void p06_L_675C(void);
void p06_L_6763(void);
void p06_L_6772(void);
void p06_L_67CA(void);
void p06_L_6802(void);
void p06_L_680C(void);
void p06_L_6822(void);
void p06_L_68CA(void);
void p06_L_68D0(void);
void p06_L_68DC(void);
void p06_L_6910(void);
void p06_L_693D(void);
void p06_L_69DE(void);
void p06_L_6A0F(void);
void p06_L_6A5A(void);
void p06_L_6A8E(void);
void p06_L_6A94(void);
void p06_str_2(void);
void p06_str_3(void);
void p06_str_4(void);
void p06_str_5(void);
void p06_L_6AC5(void);
void p06_L_6ACB(void);
void p06_L_6ACD(void);
void p06_L_6B45(void);
void p06_L_6BC1(void);
void p06_L_6C42(void);
void p06_L_6C4E(void);
void p06_L_6CB2(void);
void p06_L_6CF9(void);
void p06_L_6CFF(void);
void p06_L_6D8E(void);
void p06_L_6E15(void);
void p06_L_6F4C(void);
void p06_L_6F4F(void);
void p06_L_6F5B(void);
void p06_L_6F66(void);
void p06_L_6F72(void);
void p06_L_6F85(void);
void p06_L_6F8C(void);
void p06_L_70A2(void);
void p06_L_70CF(void);
void p06_L_70D8(void);
void p06_L_7100(void);
void p06_L_7107(void);
void p06_L_712D(void);
void p06_L_719C(void);
void p06_L_71C3(void);
void p06_L_71F7(void);
void p06_L_7200(void);
void p06_L_7207(void);
void p06_L_7221(void);
void p06_L_7235(void);
void p06_L_7257(void);
void p06_L_727C(void);
void p06_L_7285(void);
void p06_L_72AF(void);
void p06_L_72B2(void);
void p06_L_72EE(void);
void p06_L_7328(void);
void p06_L_7331(void);
void p06_L_7337(void);
void p06_L_7421(void);
void p06_L_7447(void);
void p06_L_7466(void);
void p06_L_7473(void);
void p06_L_748C(void);
void p06_L_74A4(void);
void p06_L_74CE(void);
void p06_L_74EC(void);
void p06_L_7546(void);
void p06_L_757C(void);
void p06_L_759E(void);
void p06_L_75A3(void);
void p06_L_75BA(void);
void p06_L_75C4(void);
void p06_L_75D2(void);
void p06_L_75DF(void);
void p06_L_75ED(void);
void p06_L_7612(void);
void p06_L_7618(void);
void p06_L_7635(void);
void p06_L_7641(void);
void p06_L_7647(void);
void p06_L_764F(void);
void p06_L_765F(void);
void p06_L_768A(void);
void p06_L_7690(void);
void p06_L_76B5(void);
void p06_L_76B8(void);
void p06_L_76BD(void);
void p06_L_7728(void);
void p06_L_777A(void);
void p06_L_77A0(void);
void p06_L_77F2(void);
void p06_L_7869(void);
void p06_L_78C3(void);
void p06_L_78CD(void);
void p06_L_78DB(void);
void p06_L_78EA(void);
void p06_L_78EF(void);
void p06_L_78F5(void);
void p06_L_7911(void);
void p06_L_793A(void);
void p06_L_7D0A(void);
void p06_L_7D1E(void);
void p06_L_7DE7(void);
void p06_L_7E15(void);
void p06_str_6(void);
void p06_str_9(void);
void p06_str_7(void);
void p06_str_8(void);
void p06_L_7E64(void);
void p06_L_7E69(void);
void p06_L_7E6C(void);

/* flash page 6 cpu 0x4000 (offset 0x0000) */
void p06_str_1(void) {
  d = b;
  d = d;
  c = a;
  b = a;
  d = d;
  b = c;
  c = l;
  /* nop */
  p06_L_4008();
  return;
}

/* flash page 6 cpu 0x4008 (offset 0x0008) */
void p06_L_4008(void) {
  set_hl(0x4000);
  a = 0x56;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  set_de(0x848E);
  p00_L_1185();
  p00_L_1185();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 0)));
  p06_L_4021();
  return;
}

/* flash page 6 cpu 0x4021 (offset 0x0021) */
void p06_L_4021(void) {
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  set_hl(0x403E);
  p00_L_07CC();
  p00_L_3E8B();
  p00_L_3711();
  p00_L_30BD();
  set_hl(0x84CF);
  mem_write16(0x96F8, hl());
  mem_write16(0x96FA, hl());
  return;
}

/* flash page 6 cpu 0x403E (offset 0x003E) */
void p06_L_403E(void) {
  c = e;
  b = b;
  /* adc a,c */
  b = d;
  /* sub (hl) */
  b = d;
  /* add a,(hl) */
  b = d;
  /* add a,(hl) */
  b = d;
  /* adc a,h */
  b = d;
  c = 0xFE;
  /* daa */
  if (flag_nz()) goto lab_p06_L_405B;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x59);
  if (flag_nz()) return;
  p06_L_4296();
  p00_L_3A9B();
  return;
  lab_p06_L_405B: ;
  flag_cmp(a, 0x05);
  if (flag_z()) { p06_L_408A(); return; }
  flag_cmp(a, 0x06);
  if (flag_z()) { p06_L_408A(); return; }
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p06_L_407D;
  p06_L_47D1();
  p00_L_3D1D();
  p06_L_44C8();
  set_hl(0x84C7);
  p00_L_12A2();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  return;
  lab_p06_L_407D: ;
  p06_L_487F();
  return;
}

/* flash page 6 cpu 0x404B (offset 0x004B) */
void p06_L_404B(void) {
  flag_cmp(a, 0x27);
  if (flag_nz()) goto lab_p06_L_405B;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x59);
  if (flag_nz()) return;
  p06_L_4296();
  p00_L_3A9B();
  return;
  lab_p06_L_405B: ;
  flag_cmp(a, 0x05);
  if (flag_z()) { p06_L_408A(); return; }
  flag_cmp(a, 0x06);
  if (flag_z()) { p06_L_408A(); return; }
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p06_L_407D;
  p06_L_47D1();
  p00_L_3D1D();
  p06_L_44C8();
  set_hl(0x84C7);
  p00_L_12A2();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  return;
  lab_p06_L_407D: ;
  p06_L_487F();
  return;
}

/* flash page 6 cpu 0x4080 (offset 0x0080) */
void p06_L_4080(void) {
  set_hl(mem_read16(0x96F6));
  set_de(0x84C7);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  p06_L_4089();
  return;
}

/* flash page 6 cpu 0x4089 (offset 0x0089) */
void p06_L_4089(void) {
  return;
}

/* flash page 6 cpu 0x408A (offset 0x008A) */
void p06_L_408A(void) {
  p06_L_45F4();
  set_hl(0x84C7);
  set_de(0x8479);
  p00_L_117F();
  p06_L_4080();
  if (flag_z()) return;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x41);
  if (flag_c()) goto lab_p06_L_40A5;
  flag_cmp(a, 0x5C);
  if (flag_c()) goto lab_p06_L_40A8;
  lab_p06_L_40A5: ;
  p00_L_24D5();
  return;
  lab_p06_L_40A8: ;
  a = l;
  cpu_push_af();
  a = 0x08;
  a = (uint8_t)(a - l);
  if (flag_z()) goto lab_p06_L_40B9;
  set_hl(0x8481);
  e = a;
  d = 0x00;
  cpu_sbc_hl_de();
  mem_write8(hl(), 0x00);
  lab_p06_L_40B9: ;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x59);
  if (flag_nz()) goto lab_p06_L_40CA;
  cpu_pop_af();
  p00_L_19E3();
  if (flag_nc()) { p00_L_24B9(); return; }
  p00_L_30C9();
  return;
  lab_p06_L_40CA: ;
  cpu_pop_af();
  p00_L_19E7();
  if (flag_c()) goto lab_p06_L_40DD;
  flag_cmp(a, 0x06);
  if (flag_z()) { p00_L_24D5(); return; }
  p06_L_40D5();
  return;
  lab_p06_L_40DD: ;
  set_hl(0x24F9);
  p00_L_25A2();
  p06_L_40E3();
  return;
}

/* flash page 6 cpu 0x40D5 (offset 0x00D5) */
void p06_L_40D5(void) {
  p00_L_2415();
  p00_L_10DD();
  goto lab_p06_L_40EC;
  lab_p06_L_40EC: ;
  set_de(0x84BF);
  set_hl(0x849A);
  p00_L_1185();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 0)));
  a = 0x46;
  mem_write8(0x859A, a);
  p06_L_40FE();
  return;
}

/* flash page 6 cpu 0x40E3 (offset 0x00E3) */
void p06_L_40E3(void) {
  set_hl(0x0000);
  p00_L_1CBF();
  p00_L_25C8();
  set_de(0x84BF);
  set_hl(0x849A);
  p00_L_1185();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 0)));
  a = 0x46;
  mem_write8(0x859A, a);
  p06_L_40FE();
  return;
}

/* flash page 6 cpu 0x40FE (offset 0x00FE) */
void p06_L_40FE(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  set_hl(0x4172);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 0)));
  p00_L_3E8B();
  set_hl(0x4000);
  a = 0x56;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  set_de(0x848E);
  p00_L_1185();
  p00_L_1185();
  p00_L_3711();
  set_hl(0x84BE);
  p00_rst20();
  p00_L_19E7();
  if (flag_c()) { p00_L_24F1(); return; }
  flag_cmp(a, 0x06);
  if (flag_z()) { p00_L_24D5(); return; }
  p00_L_2415();
  p00_L_03A0();
  mem_write16(0x9706, hl());
  p06_L_483D();
  p00_L_3D17();
  set_hl(0x0700);
  mem_write16(0x844B, hl());
  p00_L_01A7();
  p06_L_4152();
  return;
}

/* flash page 6 cpu 0x4100 (offset 0x0100) */
void p06_L_4100(void) {
  c = (uint8_t)(c + 1);
  /* or (hl) */
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  set_hl(0x4172);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 0)));
  p00_L_3E8B();
  set_hl(0x4000);
  a = 0x56;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  set_de(0x848E);
  p00_L_1185();
  p00_L_1185();
  p00_L_3711();
  set_hl(0x84BE);
  p00_rst20();
  p00_L_19E7();
  if (flag_c()) { p00_L_24F1(); return; }
  flag_cmp(a, 0x06);
  if (flag_z()) { p00_L_24D5(); return; }
  p00_L_2415();
  p00_L_03A0();
  mem_write16(0x9706, hl());
  p06_L_483D();
  p00_L_3D17();
  set_hl(0x0700);
  mem_write16(0x844B, hl());
  p00_L_01A7();
  p06_L_4152();
  return;
}

/* flash page 6 cpu 0x4152 (offset 0x0152) */
void p06_L_4152(void) {
  p00_L_37DD();
  set_hl(0x8479);
  p00_L_3C93();
  p00_L_3D2F();
  p00_L_01A7();
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_416B;
  p06_L_4656();
  return;
  lab_p06_L_416B: ;
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 0)));
  p06_L_4795();
  return;
}

/* flash page 6 cpu 0x417F (offset 0x017F) */
void p06_L_417F(void) {
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p06_L_41A3;
  p00_L_03A4();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p06_L_419E;
  lab_p06_L_418C: ;
  p06_L_4378();
  if (flag_z()) goto lab_p06_L_419E;
  cpu_push_de();
  p06_L_47E3();
  cpu_pop_de();
  p00_L_17C7();
  if (flag_nz()) goto lab_p06_L_418C;
  p06_L_4795();
  return;
  lab_p06_L_419E: ;
  a = 0x05;
  p06_L_4671();
  return;
  lab_p06_L_41A3: ;
  if (flag_c()) { p06_L_487F(); return; }
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p06_L_41BB;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_z()) { p06_L_45A8(); return; }
  b = 0x06;
  lab_p06_L_41B3: ;
  cpu_push_bc();
  p06_L_45A8();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_41B3;
  return;
  lab_p06_L_41BB: ;
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p06_L_41D0;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_z()) { p06_L_45F4(); return; }
  b = 0x06;
  lab_p06_L_41C8: ;
  cpu_push_bc();
  p06_L_45F4();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_41C8;
  return;
  lab_p06_L_41D0: ;
  flag_cmp(a, 0x0E);
  if (flag_z()) { p06_L_44D5(); return; }
  flag_cmp(a, 0x0F);
  if (flag_z()) { p06_L_44EB(); return; }
  flag_cmp(a, 0x0B);
  if (flag_z()) { p06_L_4868(); return; }
  flag_cmp(a, 0x21);
  if (flag_nz()) goto lab_p06_L_41E9;
  p06_L_44FD();
  if (flag_z()) return;
  goto lab_p06_L_41ED;
  lab_p06_L_41E9: ;
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p06_L_41F7;
  lab_p06_L_41ED: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  p06_L_4443();
  p06_L_4795();
  return;
  lab_p06_L_41F7: ;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p06_L_4212;
  p06_L_4216();
  p00_L_03A0();
  p00_L_1748();
  a = 0x05;
  p06_L_5DF9();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 4)));
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 7)));
  return;
  lab_p06_L_4212: ;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p06_L_422A;
  p06_L_4216();
  return;
  lab_p06_L_422A: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p06_L_423A;
  set_hl(mem_read16(0x9706));
  a = mem_read8(hl());
  a = a & 0xE0;
  flag_logic(a);
  a = a | 0x09;
  flag_logic(a);
  mem_write8(hl(), a);
  p00_L_316B();
  return;
  lab_p06_L_423A: ;
  flag_cmp(a, 0x5A);
  if (flag_c()) return;
  p00_L_1808();
  if (flag_z()) { p00_L_30E1(); return; }
  p06_L_4671();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_z()) return;
  set_hl(mem_read16(0x86D9));
  set_de(mem_read16(0x96F6));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) return;
  c = l;
  b = h;
  cpu_push_bc();
  set_hl(mem_read16(0x86D9));
  set_hl((uint16_t)(hl() - 1));
  set_de(mem_read16(0x96F8));
  set_de((uint16_t)(de() - 1));
  /* lddr */
  set_de((uint16_t)(de() + 1));
  mem_write16(0x96F8, de());
  cpu_pop_bc();
  lab_p06_L_426A: ;
  set_hl(mem_read16(0x96F8));
  p00_L_172F();
  if (flag_nz()) goto lab_p06_L_4273;
  set_bc((uint16_t)(bc() - 1));
  lab_p06_L_4273: ;
  p06_L_453B();
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_426A;
  p06_L_4795();
  return;
}

/* flash page 6 cpu 0x4216 (offset 0x0216) */
void p06_L_4216(void) {
  p06_L_42CC();
  lab_p06_L_4219: ;
  p06_L_445C();
  if (flag_z()) { p06_L_4795(); return; }
  p00_L_17C7();
  if (flag_z()) { p06_L_4795(); return; }
  p06_L_4443();
  goto lab_p06_L_4219;
}

/* flash page 6 cpu 0x427F (offset 0x027F) */
void p06_L_427F(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x29)) & (1u << 2)) == 0);
  if (flag_nz()) p00_L_30F3();
  p06_L_4286();
  return;
}

/* flash page 6 cpu 0x4286 (offset 0x0286) */
void p06_L_4286(void) {
  p00_L_3D77();
  return;
}

/* flash page 6 cpu 0x4289 (offset 0x0289) */
void p06_L_4289(void) {
  p00_L_3D6B();
  return;
}

/* flash page 6 cpu 0x428C (offset 0x028C) */
void p06_L_428C(void) {
  return;
}

/* flash page 6 cpu 0x428D (offset 0x028D) */
void p06_L_428D(void) {
  if (flag_nc()) { p00_L_3CE7(); return; }
  p00_L_3D8F();
  p06_L_4795();
  return;
}

/* flash page 6 cpu 0x4296 (offset 0x0296) */
void p06_L_4296(void) {
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 0)));
  return;
}

/* flash page 6 cpu 0x42A3 (offset 0x02A3) */
void p06_L_42A3(void) {
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 0)));
  p00_L_03A0();
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_z()) return;
  set_hl(mem_read16(0x9706));
  mem_write8(hl(), 0x05);
  p06_L_4844();
  set_de(mem_read16(0x84D3));
  b = 0x00;
  p06_L_42E6();
  set_hl(mem_read16(0x9706));
  p00_L_240B();
  mem_write8(hl(), a);
  return;
}

/* flash page 6 cpu 0x42CC (offset 0x02CC) */
void p06_L_42CC(void) {
  lab_p06_L_42CC: ;
  p06_L_4344();
  if (flag_z()) goto lab_p06_L_42DE;
  p00_L_17C7();
  if (flag_z()) goto lab_p06_L_42DB;
  p00_L_3DD1();
  goto lab_p06_L_42CC;
  lab_p06_L_42DB: ;
  p06_L_4378();
  lab_p06_L_42DE: ;
  set_hl(0x844C);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p00_L_01A7();
  return;
}

/* flash page 6 cpu 0x42E6 (offset 0x02E6) */
void p06_L_42E6(void) {
  cpu_push_de();
  cpu_push_bc();
  p00_L_242F();
  p00_L_243E();
  e = a;
  p00_L_243E();
  d = a;
  b = 0x00;
  goto lab_p06_L_42FB;
  lab_p06_L_42F7: ;
  p00_L_243E();
  set_de((uint16_t)(de() - 1));
  lab_p06_L_42FB: ;
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_4304;
  lab_p06_L_42FF: ;
  a = b;
  a = a | a;
  flag_logic(a);
  cpu_pop_bc();
  cpu_pop_de();
  return;
  lab_p06_L_4304: ;
  p00_L_243E();
  flag_cmp(a, 0xEF);
  if (flag_z()) goto lab_p06_L_4338;
  set_de((uint16_t)(de() - 1));
  p00_L_1730();
  if (flag_nz()) goto lab_p06_L_42FB;
  flag_cmp(a, 0xBB);
  if (flag_nz()) goto lab_p06_L_42F7;
  p00_L_243E();
  set_de((uint16_t)(de() - 1));
  flag_cmp(a, 0x68);
  if (flag_c()) goto lab_p06_L_42FB;
  c = 0x01;
  p06_L_433C();
  flag_cmp(a, 0xCF);
  if (flag_c()) goto lab_p06_L_42FB;
  c = 0x02;
  p06_L_433C();
  flag_cmp(a, 0xDB);
  if (flag_c()) goto lab_p06_L_42FB;
  c = 0x03;
  p06_L_433C();
  flag_cmp(a, 0xF6);
  if (flag_c()) goto lab_p06_L_42FB;
  lab_p06_L_4338: ;
  b = 0xFF;
  goto lab_p06_L_42FF;
}

/* flash page 6 cpu 0x433C (offset 0x033C) */
void p06_L_433C(void) {
  cpu_push_af();
  a = b;
  flag_cmp(a, c);
  if (flag_nc()) goto lab_p06_L_4342;
  b = c;
  lab_p06_L_4342: ;
  cpu_pop_af();
  return;
}

/* flash page 6 cpu 0x4344 (offset 0x0344) */
void p06_L_4344(void) {
  p00_L_191A();
  if (flag_z()) return;
  set_hl((uint16_t)(hl() - 1));
  p00_L_191D();
  d = 0x00;
  if (flag_z()) { p06_L_4369(); return; }
  cpu_push_hl();
  set_hl((uint16_t)(hl() - 1));
  p00_L_172F();
  cpu_pop_hl();
  if (flag_nz()) { p06_L_4369(); return; }
  cpu_push_hl();
  p06_L_4369();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  a = e;
  cpu_push_af();
  p06_L_4369();
  d = e;
  cpu_pop_af();
  e = a;
  a = a | 0x01;
  flag_logic(a);
  return;
}

/* flash page 6 cpu 0x4369 (offset 0x0369) */
void p06_L_4369(void) {
  e = mem_read8(hl());
  mem_write16(0x96F6, hl());
  set_hl(mem_read16(0x96F8));
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), e);
  mem_write16(0x96F8, hl());
  a = a | 0x01;
  flag_logic(a);
  return;
}

/* flash page 6 cpu 0x4378 (offset 0x0378) */
void p06_L_4378(void) {
  set_hl(mem_read16(0x96F8));
  set_de(mem_read16(0x96FA));
  p00_L_192A();
  if (flag_z()) return;
  p00_L_172F();
  d = 0x00;
  if (flag_nz()) { p06_L_4391(); return; }
  cpu_push_hl();
  p06_L_4391();
  cpu_pop_hl();
  d = e;
  set_hl((uint16_t)(hl() + 1));
  p06_L_4391();
  return;
}

/* flash page 6 cpu 0x4391 (offset 0x0391) */
void p06_L_4391(void) {
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96F8, hl());
  set_hl(mem_read16(0x96F6));
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96F6, hl());
  a = a | 0x01;
  flag_logic(a);
  return;
}

/* flash page 6 cpu 0x43A1 (offset 0x03A1) */
void p06_L_43A1(void) {
  cpu_push_de();
  p06_L_44BE();
  cpu_pop_bc();
  if (flag_z()) return;
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_43B6;
  set_hl((uint16_t)(hl() + 1));
  p06_L_44C1();
  if (flag_z()) return;
  mem_write8(hl(), c);
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), b);
  set_hl((uint16_t)(hl() + 1));
  goto lab_p06_L_43B7;
  lab_p06_L_43B6: ;
  mem_write8(hl(), c);
  lab_p06_L_43B7: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96F6, hl());
  a = a | 0x01;
  flag_logic(a);
  return;
}

/* flash page 6 cpu 0x43BE (offset 0x03BE) */
void p06_L_43BE(void) {
  cpu_push_de();
  cpu_push_hl();
  cpu_push_af();
  set_hl(mem_read16(0x86D9));
  set_de(mem_read16(0x96F8));
  p00_L_192A();
  cpu_pop_de();
  if (flag_z()) goto lab_p06_L_43D6;
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x86D9, hl());
  a = a | a;
  flag_logic(a);
  goto lab_p06_L_43D7;
  lab_p06_L_43D6: ;
  /* scf */
  lab_p06_L_43D7: ;
  cpu_pop_hl();
  cpu_pop_de();
  return;
}

/* flash page 6 cpu 0x43DA (offset 0x03DA) */
void p06_L_43DA(void) {
  set_hl(mem_read16(0x86D9));
  set_de(mem_read16(0x96F8));
  lab_p06_L_43E1: ;
  p00_L_192A();
  if (flag_z()) goto lab_p06_L_43EF;
  a = mem_read8(bc());
  set_bc((uint16_t)(bc() + 1));
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_43F0;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  goto lab_p06_L_43E1;
  lab_p06_L_43EF: ;
  /* scf */
  lab_p06_L_43F0: ;
  mem_write16(0x86D9, hl());
  return;
}

/* flash page 6 cpu 0x43F4 (offset 0x03F4) */
void p06_L_43F4(void) {
  cpu_push_de();
  set_hl(mem_read16(0x96F6));
  set_de(mem_read16(0x96FA));
  p00_L_192A();
  cpu_pop_de();
  if (flag_z()) return;
  cpu_push_hl();
  cpu_push_de();
  p06_L_445C();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_push_af();
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_4434;
  cpu_pop_af();
  if (flag_c()) goto lab_p06_L_4431;
  cpu_push_de();
  cpu_push_hl();
  set_hl(mem_read16(0x96F8));
  set_de(mem_read16(0x96FA));
  p00_L_192A();
  if (flag_nz()) goto lab_p06_L_4427;
  set_hl(mem_read16(0x96F6));
  set_hl((uint16_t)(hl() + 1));
  p06_L_44C1();
  goto lab_p06_L_442A;
  lab_p06_L_4427: ;
  p06_L_44BE();
  lab_p06_L_442A: ;
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_nz()) goto lab_p06_L_4430;
  a = 0;
  flag_logic(a);
  return;
  lab_p06_L_4430: ;
  a = 0;
  flag_logic(a);
  lab_p06_L_4431: ;
  cpu_push_af();
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_4434: ;
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96F6, hl());
  p06_L_444C();
  cpu_pop_af();
  if (flag_c()) p06_L_4443();
  a = a | 0x01;
  flag_logic(a);
  return;
}

/* flash page 6 cpu 0x4443 (offset 0x0443) */
void p06_L_4443(void) {
  p06_L_445C();
  cpu_push_af();
  p06_L_444C();
  cpu_pop_af();
  if (flag_nc()) return;
  p06_L_444C();
  return;
}

/* flash page 6 cpu 0x444C (offset 0x044C) */
void p06_L_444C(void) {
  set_hl(mem_read16(0x96F8));
  set_de(mem_read16(0x96FA));
  p00_L_192A();
  if (flag_z()) return;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96F8, hl());
  return;
}

/* flash page 6 cpu 0x445C (offset 0x045C) */
void p06_L_445C(void) {
  set_hl(mem_read16(0x96F8));
  p06_L_445F();
  return;
}

/* flash page 6 cpu 0x445F (offset 0x045F) */
void p06_L_445F(void) {
  set_de(mem_read16(0x96FA));
  p06_L_4463();
  return;
}

/* flash page 6 cpu 0x4463 (offset 0x0463) */
void p06_L_4463(void) {
  p00_L_192A();
  if (flag_z()) return;
  p06_L_4467();
  return;
}

/* flash page 6 cpu 0x4467 (offset 0x0467) */
void p06_L_4467(void) {
  d = 0x00;
  e = mem_read8(hl());
  p00_L_172F();
  a = e;
  if (flag_nz()) return;
  d = a;
  a = a | 0x01;
  flag_logic(a);
  a = d;
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  /* scf */
  return;
}

/* flash page 6 cpu 0x4477 (offset 0x0477) */
void p06_L_4477(void) {
  set_hl(mem_read16(0x96FA));
  set_de(mem_read16(0x96F8));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) return;
  c = l;
  b = h;
  set_hl(mem_read16(0x96F6));
  cpu_ex_de_hl();
  while (bc() != 0) { cpu_ldi(); }
  mem_write16(0x96F8, hl());
  mem_write16(0x96F6, de());
  return;
}

/* flash page 6 cpu 0x4492 (offset 0x0492) */
void p06_L_4492(void) {
  p00_rst10();
  p06_L_4493();
  return;
}

/* flash page 6 cpu 0x4493 (offset 0x0493) */
void p06_L_4493(void) {
  p06_L_4815();
  set_hl(mem_read16(0x84D5));
  p06_L_4829();
  p06_L_449C();
  return;
}

/* flash page 6 cpu 0x449C (offset 0x049C) */
void p06_L_449C(void) {
  set_hl(mem_read16(0x96F6));
  set_de(mem_read16(0x96F4));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) return;
  c = l;
  b = h;
  set_hl(mem_read16(0x96F6));
  set_hl((uint16_t)(hl() - 1));
  set_de(mem_read16(0x96F8));
  set_de((uint16_t)(de() - 1));
  /* lddr */
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96F6, hl());
  set_de((uint16_t)(de() + 1));
  mem_write16(0x96F8, de());
  return;
}

/* flash page 6 cpu 0x44BE (offset 0x04BE) */
void p06_L_44BE(void) {
  set_hl(mem_read16(0x96F6));
  p06_L_44C1();
  return;
}

/* flash page 6 cpu 0x44C1 (offset 0x04C1) */
void p06_L_44C1(void) {
  set_de(mem_read16(0x96F8));
  p00_L_192A();
  return;
}

/* flash page 6 cpu 0x44C8 (offset 0x04C8) */
void p06_L_44C8(void) {
  set_hl(mem_read16(0x96F4));
  mem_write16(0x96F6, hl());
  set_hl(mem_read16(0x96FA));
  mem_write16(0x96F8, hl());
  return;
}

/* flash page 6 cpu 0x44D5 (offset 0x04D5) */
void p06_L_44D5(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 2)));
  lab_p06_L_44D9: ;
  p06_L_44FD();
  p00_L_191A();
  if (flag_z()) return;
  p06_L_4871();
  if (flag_z()) goto lab_p06_L_44D9;
  a = e;
  flag_cmp(a, 0x3F);
  if (flag_nz()) goto lab_p06_L_44D9;
  return;
}

/* flash page 6 cpu 0x44EB (offset 0x04EB) */
void p06_L_44EB(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 2)));
  lab_p06_L_44EF: ;
  p06_L_453B();
  p06_L_445C();
  if (flag_c()) goto lab_p06_L_44EF;
  if (flag_z()) return;
  flag_cmp(a, 0x3F);
  if (flag_nz()) goto lab_p06_L_44EF;
  return;
}

/* flash page 6 cpu 0x44FD (offset 0x04FD) */
void p06_L_44FD(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  p06_L_4501();
  return;
}

/* flash page 6 cpu 0x4501 (offset 0x0501) */
void p06_L_4501(void) {
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  p06_L_4344();
  if (flag_z()) goto lab_p06_L_4585;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_452E;
  a = mem_read8(0x8198);
  cpu_push_af();
  p00_L_3063();
  cpu_pop_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 2)) == 0);
  cpu_push_af();
  set_hl(0x8198);
  cpu_cp_hl();
  if (flag_nz()) p00_L_3069();
  cpu_pop_af();
  if (flag_nz()) p00_L_306F();
  goto lab_p06_L_4538;
  lab_p06_L_452E: ;
  p00_L_3DD1();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 2)) == 0);
  if (flag_nz()) p06_L_473C();
  lab_p06_L_4538: ;
  cpu_pop_af();
  goto lab_p06_L_4585;
  lab_p06_L_4585: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 6 cpu 0x453B (offset 0x053B) */
void p06_L_453B(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  p06_L_453F();
  return;
}

/* flash page 6 cpu 0x453F (offset 0x053F) */
void p06_L_453F(void) {
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  p06_L_4378();
  if (flag_z()) goto lab_p06_L_4585;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) | (1u << 6)));
  p06_L_47E3();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_4572;
  p06_L_445C();
  if (flag_z()) goto lab_p06_L_4572;
  p00_L_3DBF();
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  p00_L_3D41();
  a = mem_read8(hl());
  a = (uint8_t)(a - 1);
  set_hl(0x86D7);
  /* add a,(hl) */
  set_hl(0x8179);
  cpu_cp_hl();
  if (flag_nc()) p00_L_3075();
  lab_p06_L_4572: ;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  mem_write8((uint16_t)(iy + 0x2A), (uint8_t)(mem_read8((uint16_t)(iy + 0x2A)) & ~(1u << 6)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 2)) == 0);
  if (flag_nz()) p06_L_4589();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  lab_p06_L_4585: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 6 cpu 0x4589 (offset 0x0589) */
void p06_L_4589(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_45A4;
  a = mem_read8(0x8198);
  cpu_push_af();
  set_hl(mem_read16(0x86D7));
  cpu_push_hl();
  p00_L_307B();
  cpu_pop_hl();
  mem_write16(0x86D7, hl());
  cpu_pop_hl();
  a = h;
  mem_write8(0x8198, a);
  return;
  lab_p06_L_45A4: ;
  p06_L_7200();
  return;
}

/* flash page 6 cpu 0x45A8 (offset 0x05A8) */
void p06_L_45A8(void) {
  a = 0;
  flag_logic(a);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 2)));
  set_de(mem_read16(0x96F4));
  set_bc(mem_read16(0x844B));
  b = (uint8_t)(b + 1);
  lab_p06_L_45B7: ;
  p06_L_44FD();
  set_hl(mem_read16(0x96F6));
  a = mem_read8(0x844B);
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p06_L_45D0;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p06_L_45D0;
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_45D7;
  goto lab_p06_L_45EC;
  lab_p06_L_45D0: ;
  c = a;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  a = a | 0x01;
  flag_logic(a);
  cpu_push_af();
  lab_p06_L_45D7: ;
  a = mem_read8(0x844C);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p06_L_45F1;
  cpu_push_de();
  cpu_push_hl();
  p06_L_4871();
  cpu_pop_hl();
  mem_write16(0x96F6, hl());
  p00_L_17C7();
  cpu_pop_de();
  if (flag_z()) goto lab_p06_L_45F1;
  lab_p06_L_45EC: ;
  p00_L_192A();
  if (flag_nz()) goto lab_p06_L_45B7;
  lab_p06_L_45F1: ;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 6 cpu 0x45C4 (offset 0x05C4) */
void p06_L_45C4(void) {
  goto lab_p06_L_45C4;
  lab_p06_L_45B7: ;
  p06_L_44FD();
  set_hl(mem_read16(0x96F6));
  a = mem_read8(0x844B);
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p06_L_45D0;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 2)) == 0);
  lab_p06_L_45C4: ;
  /* rlc l */
  d = mem_read8(hl());
  if (flag_nz()) goto lab_p06_L_45D0;
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_45D7;
  goto lab_p06_L_45EC;
  lab_p06_L_45D0: ;
  c = a;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  a = a | 0x01;
  flag_logic(a);
  cpu_push_af();
  lab_p06_L_45D7: ;
  a = mem_read8(0x844C);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p06_L_45F1;
  cpu_push_de();
  cpu_push_hl();
  p06_L_4871();
  cpu_pop_hl();
  mem_write16(0x96F6, hl());
  p00_L_17C7();
  cpu_pop_de();
  if (flag_z()) goto lab_p06_L_45F1;
  lab_p06_L_45EC: ;
  p00_L_192A();
  if (flag_nz()) goto lab_p06_L_45B7;
  lab_p06_L_45F1: ;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 6 cpu 0x45F4 (offset 0x05F4) */
void p06_L_45F4(void) {
  a = 0;
  flag_logic(a);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 2)));
  set_de(mem_read16(0x96FA));
  set_bc(mem_read16(0x844B));
  lab_p06_L_4602: ;
  p06_L_453B();
  set_hl(mem_read16(0x96F8));
  a = mem_read8(0x844B);
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p06_L_461B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p06_L_461B;
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_4622;
  goto lab_p06_L_462D;
  lab_p06_L_461B: ;
  c = a;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  a = a | 0x01;
  flag_logic(a);
  cpu_push_af();
  lab_p06_L_4622: ;
  a = mem_read8(0x844C);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p06_L_4632;
  a = mem_read8(hl());
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p06_L_4632;
  lab_p06_L_462D: ;
  p00_L_192A();
  if (flag_nz()) goto lab_p06_L_4602;
  lab_p06_L_4632: ;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 6 cpu 0x4609 (offset 0x0609) */
void p06_L_4609(void) {
  goto lab_p06_L_4609;
  lab_p06_L_4602: ;
  p06_L_453B();
  set_hl(mem_read16(0x96F8));
  a = mem_read8(0x844B);
  lab_p06_L_4609: ;
  c = e;
  a = (uint8_t)(a + h);
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p06_L_461B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p06_L_461B;
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_4622;
  goto lab_p06_L_462D;
  lab_p06_L_461B: ;
  c = a;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  a = a | 0x01;
  flag_logic(a);
  cpu_push_af();
  lab_p06_L_4622: ;
  a = mem_read8(0x844C);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p06_L_4632;
  a = mem_read8(hl());
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p06_L_4632;
  lab_p06_L_462D: ;
  p00_L_192A();
  if (flag_nz()) goto lab_p06_L_4602;
  lab_p06_L_4632: ;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 6 cpu 0x4635 (offset 0x0635) */
void p06_L_4635(void) {
  p06_L_449C();
  set_bc(mem_read16(0x86E0));
  set_hl(mem_read16(0x96F6));
  set_hl((uint16_t)(hl() + bc()));
  lab_p06_L_4640: ;
  set_de(mem_read16(0x96F6));
  p00_L_192A();
  if (flag_z()) return;
  if (flag_c()) return;
  cpu_push_hl();
  p06_L_4378();
  cpu_pop_hl();
  if (flag_z()) return;
  cpu_push_hl();
  p06_L_47E3();
  cpu_pop_hl();
  goto lab_p06_L_4640;
}

/* flash page 6 cpu 0x4656 (offset 0x0656) */
void p06_L_4656(void) {
  p06_L_4635();
  p06_L_4795();
  return;
}

/* flash page 6 cpu 0x4671 (offset 0x0671) */
void p06_L_4671(void) {
  p00_L_3BBB();
  cpu_push_de();
  set_hl(mem_read16(0x96F8));
  set_de(mem_read16(0x96FA));
  p00_L_192A();
  cpu_pop_de();
  cpu_push_af();
  cpu_push_de();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p06_L_46D2;
  p06_L_445C();
  if (flag_c()) goto lab_p06_L_4693;
  if (flag_z()) goto lab_p06_L_4693;
  flag_cmp(a, 0x3F);
  if (flag_z()) goto lab_p06_L_46D2;
  lab_p06_L_4693: ;
  cpu_pop_de();
  cpu_push_de();
  p06_L_43F4();
  if (flag_z()) goto lab_p06_L_46DB;
  lab_p06_L_469A: ;
  cpu_pop_de();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_46C2;
  cpu_pop_af();
  cpu_push_af();
  p00_L_3081();
  cpu_pop_af();
  if (flag_z()) return;
  p00_L_3069();
  p00_L_3087();
  a = mem_read8(0x81A0);
  a = (uint8_t)(a - 1);
  set_hl(0x86D7);
  /* add a,(hl) */
  set_hl(0x8179);
  cpu_cp_hl();
  if (flag_c()) return;
  p06_L_453F();
  p06_L_4501();
  return;
  lab_p06_L_46C2: ;
  cpu_pop_af();
  cpu_push_af();
  p00_L_3DD7();
  cpu_pop_af();
  if (flag_z()) return;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x49);
  if (flag_z()) return;
  p06_L_4795();
  return;
  lab_p06_L_46D2: ;
  cpu_pop_de();
  cpu_push_de();
  p06_L_43A1();
  if (flag_z()) goto lab_p06_L_46DB;
  goto lab_p06_L_469A;
  lab_p06_L_46DB: ;
  cpu_pop_de();
  cpu_pop_af();
  return;
}

/* flash page 6 cpu 0x46DE (offset 0x06DE) */
void p06_L_46DE(void) {
  p00_L_191A();
  if (flag_z()) { p06_L_46FC(); return; }
  set_hl((uint16_t)(hl() - 1));
  p00_L_191D();
  d = 0x00;
  if (flag_z()) goto lab_p06_L_46F4;
  cpu_push_hl();
  set_hl((uint16_t)(hl() - 1));
  p00_L_172F();
  cpu_pop_hl();
  if (flag_nz()) goto lab_p06_L_46F4;
  set_hl((uint16_t)(hl() - 1));
  lab_p06_L_46F4: ;
  cpu_ex_de_hl();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  cpu_ex_de_hl();
  goto lab_p06_L_4703;
  lab_p06_L_4703: ;
  a = mem_read8(0x89FD);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  lab_p06_L_470B: ;
  p00_L_191D();
  /* ccf */
  if (flag_z()) goto lab_p06_L_4732;
  set_hl((uint16_t)(hl() - 1));
  p00_L_191D();
  d = 0x00;
  e = mem_read8(hl());
  if (flag_z()) goto lab_p06_L_471E;
  set_hl((uint16_t)(hl() + 1));
  p06_L_4871();
  lab_p06_L_471E: ;
  a = a | 0x01;
  flag_logic(a);
  p00_L_3DC5();
  if (flag_c()) goto lab_p06_L_470B;
  p00_L_37A7();
  a = 0xCE;
  p00_L_3F9F();
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 0)));
  a = a | a;
  flag_logic(a);
  lab_p06_L_4732: ;
  cpu_pop_bc();
  a = b;
  mem_write8(0x89FD, a);
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x46FC (offset 0x06FC) */
void p06_L_46FC(void) {
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(mem_read16(0x96F6));
  a = mem_read8(0x89FD);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  lab_p06_L_470B: ;
  p00_L_191D();
  /* ccf */
  if (flag_z()) goto lab_p06_L_4732;
  set_hl((uint16_t)(hl() - 1));
  p00_L_191D();
  d = 0x00;
  e = mem_read8(hl());
  if (flag_z()) goto lab_p06_L_471E;
  set_hl((uint16_t)(hl() + 1));
  p06_L_4871();
  lab_p06_L_471E: ;
  a = a | 0x01;
  flag_logic(a);
  p00_L_3DC5();
  if (flag_c()) goto lab_p06_L_470B;
  p00_L_37A7();
  a = 0xCE;
  p00_L_3F9F();
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 0)));
  a = a | a;
  flag_logic(a);
  lab_p06_L_4732: ;
  cpu_pop_bc();
  a = b;
  mem_write8(0x89FD, a);
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x473C (offset 0x073C) */
void p06_L_473C(void) {
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(mem_read16(0x96F6));
  set_de(mem_read16(0x96F4));
  a = mem_read8(0x89FD);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  p06_L_474F();
  return;
}

/* flash page 6 cpu 0x474F (offset 0x074F) */
void p06_L_474F(void) {
  lab_p06_L_474F: ;
  p00_L_192A();
  if (flag_nz()) goto lab_p06_L_4785;
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = mem_read8(0x859A);
  flag_cmp(a, 0x49);
  if (flag_nz()) goto lab_p06_L_4767;
  a = mem_read8(0x9813);
  p06_L_72AF();
  goto lab_p06_L_478C;
  lab_p06_L_4767: ;
  flag_cmp(a, 0x54);
  if (flag_nz()) goto lab_p06_L_4770;
  p06_L_6192();
  goto lab_p06_L_478C;
  lab_p06_L_4770: ;
  flag_cmp(a, 0x46);
  if (flag_nz()) goto lab_p06_L_4779;
  p00_L_01A7();
  goto lab_p06_L_478C;
  lab_p06_L_4779: ;
  flag_cmp(a, 0x50);
  if (flag_nz()) goto lab_p06_L_478C;
  set_hl(0x865F);
  p00_L_3C87();
  goto lab_p06_L_478C;
  lab_p06_L_4785: ;
  cpu_push_de();
  p00_L_3DCB();
  cpu_pop_de();
  if (flag_c()) goto lab_p06_L_474F;
  lab_p06_L_478C: ;
  cpu_pop_af();
  mem_write8(0x89FD, a);
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x4795 (offset 0x0795) */
void p06_L_4795(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_479F;
  p00_L_3069();
  return;
  lab_p06_L_479F: ;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(mem_read16(0x96F8));
  a = mem_read8(0x89FD);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  lab_p06_L_47AE: ;
  p06_L_445F();
  if (flag_z()) goto lab_p06_L_47C4;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p06_L_47E3();
  a = mem_read8(0x844B);
  set_hl(0x97A6);
  cpu_cp_hl();
  cpu_pop_hl();
  if (flag_c()) goto lab_p06_L_47AE;
  goto lab_p06_L_47C8;
  lab_p06_L_47C4: ;
  p00_L_3D29();
  /* scf */
  lab_p06_L_47C8: ;
  cpu_pop_de();
  mem_write8((uint16_t)(iy + 0x0D), d);
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x47D1 (offset 0x07D1) */
void p06_L_47D1(void) {
  lab_p06_L_47D1: ;
  p06_L_4344();
  if (flag_z()) return;
  p00_L_3DD1();
  goto lab_p06_L_47D1;
}

/* flash page 6 cpu 0x47DA (offset 0x07DA) */
void p06_L_47DA(void) {
  lab_p06_L_47DA: ;
  p06_L_4378();
  if (flag_z()) return;
  p06_L_47E3();
  goto lab_p06_L_47DA;
}

/* flash page 6 cpu 0x47E3 (offset 0x07E3) */
void p06_L_47E3(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_47ED;
  p00_L_308D();
  return;
  lab_p06_L_47ED: ;
  p00_L_3DB9();
  p00_L_3C93();
  return;
}

/* flash page 6 cpu 0x47F4 (offset 0x07F4) */
void p06_L_47F4(void) {
  p00_L_165F();
  p00_L_19E7();
  p06_L_4493();
  set_bc(mem_read16(0x96F2));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) return;
  set_hl(mem_read16(0x96F8));
  set_de(mem_read16(0x96F4));
  while (bc() != 0) { cpu_ldi(); }
  mem_write16(0x96F6, de());
  mem_write16(0x96F8, hl());
  return;
}

/* flash page 6 cpu 0x4815 (offset 0x0815) */
void p06_L_4815(void) {
  p00_L_3093();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) | (1u << 2)));
  set_hl(mem_read16(0x84D3));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96F4, hl());
  return;
}

/* flash page 6 cpu 0x4825 (offset 0x0825) */
void p06_L_4825(void) {
  p00_rst10();
  p06_L_4826();
  return;
}

/* flash page 6 cpu 0x4826 (offset 0x0826) */
void p06_L_4826(void) {
  p06_L_4815();
  p06_L_4829();
  return;
}

/* flash page 6 cpu 0x4829 (offset 0x0829) */
void p06_L_4829(void) {
  mem_write16(0x96F6, hl());
  cpu_ex_de_hl();
  set_hl(mem_read16(0x84D7));
  p00_L_192A();
  if (flag_nc()) goto lab_p06_L_4836;
  cpu_ex_de_hl();
  lab_p06_L_4836: ;
  mem_write16(0x96FA, hl());
  mem_write16(0x96F8, hl());
  return;
}

/* flash page 6 cpu 0x483D (offset 0x083D) */
void p06_L_483D(void) {
  p06_L_4493();
  p06_L_449C();
  return;
}

/* flash page 6 cpu 0x4844 (offset 0x0844) */
void p06_L_4844(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_z()) return;
  p06_L_4477();
  set_hl(mem_read16(0x96F6));
  mem_write16(0x84D5, hl());
  set_de(mem_read16(0x96F4));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_ex_de_hl();
  set_hl(mem_read16(0x84D3));
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), d);
  p00_L_3099();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 2)));
  return;
}

/* flash page 6 cpu 0x4868 (offset 0x0868) */
void p06_L_4868(void) {
  a = mem_read8(0x89F5);
  a = a ^ 0x10;
  flag_logic(a);
  mem_write8(0x89F5, a);
  return;
}

/* flash page 6 cpu 0x4871 (offset 0x0871) */
void p06_L_4871(void) {
  set_hl((uint16_t)(hl() - 1));
  cpu_push_hl();
  set_hl((uint16_t)(hl() - 1));
  p00_L_172F();
  cpu_pop_hl();
  d = 0x00;
  e = mem_read8(hl());
  if (flag_nz()) return;
  set_hl((uint16_t)(hl() - 1));
  d = mem_read8(hl());
  return;
}

/* flash page 6 cpu 0x487F (offset 0x087F) */
void p06_L_487F(void) {
  flag_cmp(a, 0x02);
  if (flag_z()) { p06_L_44FD(); return; }
  flag_cmp(a, 0x01);
  if (flag_z()) { p06_L_453B(); return; }
  flag_cmp(a, 0x0E);
  if (flag_z()) goto lab_p06_L_488F;
  flag_cmp(a, 0x03);
  lab_p06_L_488F: ;
  if (flag_z()) { p06_L_45A8(); return; }
  flag_cmp(a, 0x0F);
  if (flag_z()) goto lab_p06_L_4898;
  flag_cmp(a, 0x04);
  lab_p06_L_4898: ;
  if (flag_z()) { p06_L_45F4(); return; }
  flag_cmp(a, 0x0B);
  if (flag_z()) { p06_L_4868(); return; }
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p06_L_48AE;
  lab_p06_L_48A3: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  p06_L_4443();
  p00_L_3DDD();
  return;
  lab_p06_L_48AE: ;
  flag_cmp(a, 0x21);
  if (flag_nz()) goto lab_p06_L_48B8;
  p06_L_44FD();
  if (flag_z()) return;
  goto lab_p06_L_48A3;
  lab_p06_L_48B8: ;
  flag_cmp(a, 0x7F);
  if (flag_c()) return;
  cpu_push_af();
  p00_L_3BBB();
  cpu_pop_bc();
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_48F9;
  cpu_push_af();
  a = mem_read8(0x859A);
  flag_cmp(a, 0x43);
  if (flag_z()) goto lab_p06_L_48F3;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p06_L_48F3;
  flag_cmp(a, 0x55);
  if (flag_z()) goto lab_p06_L_48F3;
  flag_cmp(a, 0x56);
  if (flag_z()) goto lab_p06_L_48DC;
  cpu_pop_af();
  return;
  lab_p06_L_48DC: ;
  cpu_pop_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p06_L_48E8;
  flag_cmp(a, 0x5C);
  if (flag_nz()) return;
  goto lab_p06_L_491D;
  lab_p06_L_48E8: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p06_L_48F4;
  flag_cmp(a, 0x5E);
  if (flag_nz()) return;
  goto lab_p06_L_491D;
  lab_p06_L_48F3: ;
  cpu_pop_af();
  lab_p06_L_48F4: ;
  flag_cmp(a, 0x5D);
  if (flag_nz()) return;
  goto lab_p06_L_491D;
  lab_p06_L_48F9: ;
  flag_cmp(a, 0x5F);
  if (flag_z()) return;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x56);
  if (flag_nz()) goto lab_p06_L_490D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 5)) == 0);
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 6)) == 0);
  if (flag_nz()) return;
  lab_p06_L_490D: ;
  a = e;
  flag_cmp(a, 0x41);
  if (flag_c()) goto lab_p06_L_4917;
  flag_cmp(a, 0x5C);
  if (flag_c()) goto lab_p06_L_491D;
  return;
  lab_p06_L_4917: ;
  flag_cmp(a, 0x3A);
  if (flag_nc()) return;
  flag_cmp(a, 0x30);
  if (flag_c()) return;
  lab_p06_L_491D: ;
  a = b;
  set_hl(mem_read16(0x96F4));
  set_de(0x84C7);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) { p00_L_3795(); return; }
  p06_L_4671();
  return;
}

/* flash page 6 cpu 0x492D (offset 0x092D) */
void p06_L_492D(void) {
  cpu_push_af();
  set_hl(0x496A);
  set_bc(0x0011);
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p06_L_495B;
  set_hl(0x497B);
  c = 0x02;
  flag_cmp(a, 0xFC);
  if (flag_z()) goto lab_p06_L_495B;
  c = 0x01;
  set_hl(0x497D);
  flag_cmp(a, 0xFB);
  if (flag_z()) goto lab_p06_L_495B;
  cpu_pop_af();
  set_hl(0x497E);
  c = 0x09;
  /* cpir */
  if (flag_nz()) return;
  p06_L_4953();
  return;
  lab_p06_L_495B: ;
  a = mem_read8(0x8446);
  /* cpir */
  if (flag_nz()) goto lab_p06_L_4968;
  p06_L_4953();
  mem_write8(0x8446, a);
  lab_p06_L_4968: ;
  cpu_pop_af();
  return;
}

/* flash page 6 cpu 0x4953 (offset 0x0953) */
void p06_L_4953(void) {
  cpu_push_af();
  a = 0xC5;
  p06_L_4671();
  cpu_pop_af();
  return;
}

/* flash page 6 cpu 0x498B (offset 0x098B) */
void p06_L_498B(void) {
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 3)));
  a = mem_read8((uint16_t)(iy + 0x33));
  mem_write8(0x9D8A, a);
  lab_p06_L_4995: ;
  mem_write8((uint16_t)(iy + 0x3D), (uint8_t)(mem_read8((uint16_t)(iy + 0x3D)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x3D), (uint8_t)(mem_read8((uint16_t)(iy + 0x3D)) & ~(1u << 5)));
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) { p06_L_49BE(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x3E)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_49BA;
  a = hw_in(0x09);
  a = a & 0x99;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_49B6;
  a = a & 0x19;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_4A59;
  p06_L_49BE();
  return;
  lab_p06_L_49B6: ;
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p06_L_49BA: ;
  a = 0x80;
  hw_out(0x08, a);
  p06_L_49BE();
  return;
  lab_p06_L_49D8: ;
  p00_L_038C();
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 3)) == 0);
  if (flag_z()) { p06_L_49E7(); return; }
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 3)));
  a = 0xFF;
  p06_L_49E7();
  return;
  lab_p06_L_4A59: ;
  if (flag_nz()) goto lab_p06_L_4A81;
  a = mem_read8(0x9CB1);
  a = a | a;
  flag_logic(a);
  lab_p06_L_4A5F: ;
  if (flag_z()) goto lab_p06_L_49D8;
  a = (uint8_t)(a - 1);
  mem_write8(0x9CB1, a);
  if (flag_nz()) goto lab_p06_L_49D8;
  a = mem_read8(0x9CB0);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_49D8;
  p00_L_3051();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_4A5F;
  a = 0x0A;
  mem_write8(0x9CB1, a);
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 0)));
  goto lab_p06_L_4A8E;
  lab_p06_L_4A81: ;
  set_hl(0x9CB0);
  mem_write8(hl(), 0x00);
  set_hl(0x8444);
  mem_write8(hl(), 0x00);
  p00_L_3057();
  lab_p06_L_4A8E: ;
  a = mem_read8(0x8444);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_4995;
  p06_L_4A95();
  return;
}

/* flash page 6 cpu 0x49BE (offset 0x09BE) */
void p06_L_49BE(void) {
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) | (1u << 3)));
  a = 0x1A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_49CE;
  p00_L_304B();
  if (flag_z()) return;
  lab_p06_L_49CE: ;
  p06_L_4C89();
  p00_L_3117();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 3)));
  p00_L_038C();
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 3)) == 0);
  if (flag_z()) { p06_L_49E7(); return; }
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 3)));
  a = 0xFF;
  p06_L_49E7();
  return;
}

/* flash page 6 cpu 0x49E7 (offset 0x09E7) */
void p06_L_49E7(void) {
  goto lab_p06_L_49E7;
  lab_p06_L_4995: ;
  mem_write8((uint16_t)(iy + 0x3D), (uint8_t)(mem_read8((uint16_t)(iy + 0x3D)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x3D), (uint8_t)(mem_read8((uint16_t)(iy + 0x3D)) & ~(1u << 5)));
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) { p06_L_49BE(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x3E)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_49BA;
  a = hw_in(0x09);
  a = a & 0x99;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_49B6;
  a = a & 0x19;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_4A59;
  p06_L_49BE();
  return;
  lab_p06_L_49B6: ;
  mem_write8((uint16_t)(iy + 0x3E), (uint8_t)(mem_read8((uint16_t)(iy + 0x3E)) & ~(1u << 0)));
  lab_p06_L_49BA: ;
  a = 0x80;
  hw_out(0x08, a);
  p06_L_49BE();
  return;
  lab_p06_L_49D8: ;
  p00_L_038C();
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p06_L_49E7;
  mem_write8((uint16_t)(iy + 0x28), (uint8_t)(mem_read8((uint16_t)(iy + 0x28)) & ~(1u << 3)));
  a = 0xFF;
  lab_p06_L_49E7: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_49F4;
  b = a;
  a = 0x1B;
  p00_L_304B();
  if (flag_z()) return;
  lab_p06_L_49F4: ;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_4AA0;
  p00_L_0189();
  if (flag_z()) goto lab_p06_L_4A10;
  p06_L_49FD();
  return;
  lab_p06_L_4A10: ;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 0)));
  lab_p06_L_4A18: ;
  p00_L_0284();
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p06_L_4A18;
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p06_L_4A10;
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_4A39;
  a = mem_read8(0x9CAF);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_4A59;
  flag_set_z((mem_read8((uint16_t)(iy + 0x3E)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_4A47;
  lab_p06_L_4A39: ;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  flag_cmp(a, 0x03);
  goto lab_p06_L_4A59;
  lab_p06_L_4A47: ;
  a = hw_in(0x09);
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_z()) goto lab_p06_L_4A57;
  cpu_push_af();
  a = 0;
  flag_logic(a);
  mem_write8(0x9CB0, a);
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x3D), (uint8_t)(mem_read8((uint16_t)(iy + 0x3D)) | (1u << 7)));
  lab_p06_L_4A57: ;
  a = a & 0x19;
  flag_logic(a);
  lab_p06_L_4A59: ;
  if (flag_nz()) goto lab_p06_L_4A81;
  a = mem_read8(0x9CB1);
  a = a | a;
  flag_logic(a);
  lab_p06_L_4A5F: ;
  if (flag_z()) goto lab_p06_L_49D8;
  a = (uint8_t)(a - 1);
  mem_write8(0x9CB1, a);
  if (flag_nz()) goto lab_p06_L_49D8;
  a = mem_read8(0x9CB0);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_49D8;
  p00_L_3051();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_4A5F;
  a = 0x0A;
  mem_write8(0x9CB1, a);
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 0)));
  goto lab_p06_L_4A8E;
  lab_p06_L_4A81: ;
  set_hl(0x9CB0);
  mem_write8(hl(), 0x00);
  set_hl(0x8444);
  mem_write8(hl(), 0x00);
  p00_L_3057();
  lab_p06_L_4A8E: ;
  a = mem_read8(0x8444);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_4995;
  p06_L_4A95();
  return;
  lab_p06_L_4AA0: ;
  cpu_push_af();
  a = 0;
  flag_logic(a);
  mem_write8(0x9CB1, a);
  mem_write8(0x9CB0, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x33)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p06_L_4ABB;
  a = mem_read8(0x858D);
  flag_cmp(a, 0x41);
  if (flag_z()) goto lab_p06_L_4ABB;
  cpu_pop_af();
  p00_L_305D();
  goto lab_p06_L_4ABC;
  lab_p06_L_4ABB: ;
  cpu_pop_af();
  lab_p06_L_4ABC: ;
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p06_L_4ACF;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 3)));
  a = 0x3F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x28)) & (1u << 7)) == 0);
  if (flag_nz()) { p06_L_4A95(); return; }
  p00_L_086E();
  return;
  lab_p06_L_4ACF: ;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 0)));
  /* bit 4,(iy) */
  if (flag_z()) goto lab_p06_L_4AEC;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 3)));
  /* res 4,(iy) */
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 2)));
  p00_L_02AD();
  lab_p06_L_4AEC: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p06_L_4B61;
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p06_L_4C1D;
  flag_cmp(a, 0x36);
  if (flag_nz()) goto lab_p06_L_4B08;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 6)));
  p06_L_49BE();
  return;
  lab_p06_L_4B08: ;
  flag_cmp(a, 0x30);
  if (flag_nz()) { p06_L_4B1B(); return; }
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 4)));
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 5)));
  p06_L_49BE();
  return;
  lab_p06_L_4B5E: ;
  p06_L_49BE();
  return;
  lab_p06_L_4B61: ;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 3)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_4B74;
  cpu_push_af();
  p00_L_3DA1();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  cpu_pop_af();
  lab_p06_L_4B74: ;
  flag_cmp(a, 0x36);
  if (flag_z()) goto lab_p06_L_4B88;
  flag_cmp(a, 0x30);
  if (flag_nz()) goto lab_p06_L_4B8E;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 4)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 7)));
  lab_p06_L_4B88: ;
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 6)));
  goto lab_p06_L_4B5E;
  lab_p06_L_4B8E: ;
  b = 0x32;
  lab_p06_L_4B90: ;
  set_hl(0x8447);
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p06_L_4B9F;
  a = mem_read8(hl());
  flag_cmp(a, 0x27);
  if (flag_nc()) goto lab_p06_L_4BB8;
  a = (uint8_t)(a + 1);
  goto lab_p06_L_4BA8;
  lab_p06_L_4B9F: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p06_L_4C18;
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_4BB8;
  a = (uint8_t)(a - 1);
  lab_p06_L_4BA8: ;
  mem_write8(hl(), a);
  a = (uint8_t)(a + 0x18);
  a = a | 0xC0;
  flag_logic(a);
  /* di */
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  /* ei */
  set_hl(0x8442);
  mem_write8(hl(), b);
  lab_p06_L_4BB8: ;
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 3)));
  p00_L_3D9B();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x0F00);
  mem_write16(0x844B, hl());
  /* ld iyl,(iy+0x05) */
  /* ld iyh,(iy+0x0D) */
  cpu_push_hl();
  a = mem_read8(0x89F2);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  a = mem_read8(0x8447);
  e = a;
  d = 0x00;
  set_hl(0x4D5E);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  /* di */
  p00_L_3C6F();
  /* ei */
  cpu_pop_af();
  mem_write8(0x89F2, a);
  cpu_pop_hl();
  /* ld (iy+0x0D),iyh */
  /* ld (iy+0x05),iyl */
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  lab_p06_L_4BFB: ;
  p00_L_0284();
  /* bit 3,(iy) */
  if (flag_z()) goto lab_p06_L_4BFB;
  p00_L_038C();
  b = 0x0A;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p06_L_4B90;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p06_L_4B90;
  p00_L_3DA1();
  goto lab_p06_L_49E7;
  lab_p06_L_4C18: ;
  a = (uint8_t)(a + 0x38);
  lab_p06_L_4C1A: ;
  p06_L_4B1B();
  return;
  lab_p06_L_4C1D: ;
  flag_cmp(a, 0x30);
  if (flag_nz()) goto lab_p06_L_4C3D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p06_L_4C33;
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p06_L_4C33;
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 5)));
  goto lab_p06_L_4C3A;
  lab_p06_L_4C33: ;
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 7)));
  p00_L_03A4();
  lab_p06_L_4C3A: ;
  p06_L_49BE();
  return;
  lab_p06_L_4C3D: ;
  flag_cmp(a, 0x36);
  if (flag_nz()) goto lab_p06_L_4C4B;
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) | (1u << 3)));
  goto lab_p06_L_4C3A;
  lab_p06_L_4C4B: ;
  p00_L_0399();
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p06_L_4C64;
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_4C64;
  cpu_push_af();
  p00_L_3DA1();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  cpu_pop_af();
  lab_p06_L_4C64: ;
  a = (uint8_t)(a + 0x70);
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p06_L_4C1A;
  a = (uint8_t)(a + 0x38);
  l = a;
  h = 0x00;
  set_de(0x7E7B);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  flag_cmp(a, 0xE2);
  if (flag_c()) goto lab_p06_L_4C86;
  flag_cmp(a, 0xFC);
  if (flag_nc()) goto lab_p06_L_4C86;
  mem_write8(0x8446, a);
  a = 0xFC;
  p06_L_4A95();
  return;
  lab_p06_L_4C86: ;
  p06_L_4B22();
  return;
}

/* flash page 6 cpu 0x49FD (offset 0x09FD) */
void p06_L_49FD(void) {
  a = mem_read8((uint16_t)(iy + 0x3D));
  a = a & 0xF0;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x3D), a);
  a = 0;
  flag_logic(a);
  mem_write8(0x9CB1, a);
  mem_write8(0x9CB0, a);
  mem_write8(0x9CAF, a);
  return;
}

/* flash page 6 cpu 0x4A95 (offset 0x0A95) */
void p06_L_4A95(void) {
  set_hl(0x9D8A);
  flag_set_z((mem_read8(hl()) & (1u << 3)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x33), (uint8_t)(mem_read8((uint16_t)(iy + 0x33)) & ~(1u << 3)));
  return;
}

/* flash page 6 cpu 0x4B1B (offset 0x0B1B) */
void p06_L_4B1B(void) {
  l = a;
  h = 0x00;
  set_de(0x7E7B);
  set_hl((uint16_t)(hl() + de()));
  p06_L_4B22();
  return;
}

/* flash page 6 cpu 0x4B22 (offset 0x0B22) */
void p06_L_4B22(void) {
  a = mem_read8(0x85DE);
  flag_cmp(a, 0x00);
  a = mem_read8(hl());
  if (flag_nz()) goto lab_p06_L_4B5A;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x54);
  if (flag_z()) goto lab_p06_L_4B33;
  flag_cmp(a, 0x53);
  lab_p06_L_4B33: ;
  a = mem_read8(hl());
  if (flag_z()) goto lab_p06_L_4B3E;
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p06_L_4B3E;
  a = 0x05;
  goto lab_p06_L_4B5A;
  lab_p06_L_4B3E: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_4B5A;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x43);
  a = mem_read8(hl());
  if (flag_z()) goto lab_p06_L_4B5A;
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p06_L_4B54;
  a = 0x03;
  goto lab_p06_L_4B5A;
  lab_p06_L_4B54: ;
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p06_L_4B5A;
  a = 0x04;
  lab_p06_L_4B5A: ;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p06_L_4A95(); return; }
  p06_L_49BE();
  return;
}

/* flash page 6 cpu 0x4C89 (offset 0x0C89) */
void p06_L_4C89(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p06_L_4CAD;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p06_L_4CAD;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p06_L_4CAD;
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 1)) == 0);
  if (flag_z()) return;
  p00_L_3DA1();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  return;
  lab_p06_L_4CAD: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_4CC0;
  p06_L_4CFC();
  if (flag_nz()) goto lab_p06_L_4CCB;
  p00_L_3DA1();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  return;
  lab_p06_L_4CC0: ;
  p06_L_4CFC();
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) | (1u << 1)));
  p00_L_3D9B();
  lab_p06_L_4CCB: ;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x0F00);
  mem_write16(0x844B, hl());
  /* ld iyl,(iy+0x05) */
  /* ld iyh,(iy+0x0D) */
  cpu_push_hl();
  a = mem_read8(0x89F2);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  p06_L_4CFC();
  /* di */
  p00_L_3C6F();
  /* ei */
  cpu_pop_af();
  mem_write8(0x89F2, a);
  cpu_pop_hl();
  /* ld (iy+0x0D),iyh */
  /* ld (iy+0x05),iyl */
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x4CFC (offset 0x0CFC) */
void p06_L_4CFC(void) {
  a = 0xE1;
  /* ld iyh,(iy+0x12) */
  flag_set_z((h & (1u << 3)) == 0);
  if (flag_nz()) return;
  flag_set_z((h & (1u << 4)) == 0);
  if (flag_z()) return;
  a = (uint8_t)(a + 0x02);
  flag_set_z((h & (1u << 5)) == 0);
  if (flag_nz()) return;
  a = (uint8_t)(a - 1);
  return;
}

/* flash page 6 cpu 0x4D0E (offset 0x0D0E) */
void p06_L_4D0E(void) {
  a = 0x40;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p06_L_4D15();
  return;
}

/* flash page 6 cpu 0x4D15 (offset 0x0D15) */
void p06_L_4D15(void) {
  a = 0x05;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  a = 0x01;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  a = 0x03;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p00_L_24A9();
  if (flag_z()) goto lab_p06_L_4D43;
  b = 0x00;
  os_bcall(0x80BA);
  flag_set_z((b & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_4D43;
  a = 0x16;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  a = 0x08;
  goto lab_p06_L_4D4C;
  lab_p06_L_4D43: ;
  a = 0x17;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  a = 0x0B;
  lab_p06_L_4D4C: ;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  a = mem_read8(0x8447);
  a = (uint8_t)(a + 0x18);
  a = a | 0xC0;
  flag_logic(a);
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  return;
}

/* flash page 6 cpu 0x4D86 (offset 0x0D86) */
void p06_L_4D86(void) {
  cpu_push_af();
  cpu_push_bc();
  p00_L_1169();
  flag_set_z((mem_read8((uint16_t)(iy + 0x07)) & (1u << 3)) == 0);
  if (flag_nz()) { p00_L_2501(); return; }
  p00_L_39E1();
  p00_L_21D1();
  p00_L_21D6();
  set_hl(0x0087);
  p00_L_21C3();
  p00_L_21CC();
  p00_L_16B5();
  p00_L_113F();
  p00_L_29AA();
  p00_L_29CC();
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_4DCF;
  p00_L_38F1();
  p00_L_2A27();
  p00_L_107E();
  if (flag_c()) goto lab_p06_L_4DD5;
  p00_L_289D();
  p00_L_2964();
  p00_L_107E();
  if (flag_c()) goto lab_p06_L_4DD5;
  p00_L_2969();
  goto lab_p06_L_4DEB;
  lab_p06_L_4DCF: ;
  p00_L_0C2D();
  p00_L_15CB();
  lab_p06_L_4DD5: ;
  if (flag_nz()) { p00_L_2505(); return; }
  p00_L_14C7();
  if (flag_z()) { p00_L_2505(); return; }
  set_hl(0x50D5);
  p00_L_0D19();
  p00_L_28B0();
  p00_rst30();
  p00_L_2A27();
  lab_p06_L_4DEB: ;
  p00_L_2A2B();
  p00_L_2A2F();
  p00_L_2977();
  p00_L_38D9();
  cpu_pop_hl();
  mem_write16(0x848E, hl());
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 3)));
  set_hl(0x5099);
  p00_L_25A2();
  p00_L_1287();
  p00_L_21E0();
  p00_L_38DF();
  p00_L_2969();
  set_hl(mem_read16(0x848E));
  cpu_push_hl();
  cpu_pop_af();
  cpu_push_af();
  p06_L_5070();
  p00_L_2A13();
  p00_L_2A17();
  p00_L_2A1B();
  p00_L_128A();
  p00_L_29E3();
  p06_L_4E29();
  return;
}

/* flash page 6 cpu 0x4E29 (offset 0x0E29) */
void p06_L_4E29(void) {
  p00_L_2969();
  p00_L_15D6();
  set_hl(0x50CC);
  p00_L_0D19();
  p06_L_4E35();
  return;
}

/* flash page 6 cpu 0x4E35 (offset 0x0E35) */
void p06_L_4E35(void) {
  p00_L_10DD();
  p00_L_297E();
  p00_L_1221();
  p00_L_0ED0();
  p00_L_10EF();
  p00_rst30();
  p00_L_29DB();
  p00_L_0C18();
  p00_L_29D7();
  p00_L_289D();
  p00_L_28B0();
  p00_rst30();
  p00_L_0D16();
  p00_L_29D3();
  p00_L_2964();
  p00_L_0C13();
  p00_L_15D6();
  p00_L_10DD();
  p00_L_289D();
  p00_L_28B0();
  p00_L_0C2D();
  p00_L_0D16();
  p00_L_28E0();
  p00_L_0C13();
  p00_L_10EF();
  p00_L_107E();
  if (flag_nc()) goto lab_p06_L_50A9;
  p00_L_28F1();
  p00_L_2917();
  p00_L_1078();
  if (flag_c()) goto lab_p06_L_4F7F;
  lab_p06_L_4E8E: ;
  p00_L_2969();
  p00_L_28C3();
  p00_L_107E();
  cpu_push_af();
  if (flag_c()) p00_L_289D();
  cpu_pop_af();
  if (flag_nc()) p00_L_28B5();
  p00_L_2964();
  p00_L_0C2D();
  p00_L_29E3();
  set_hl(0x50D5);
  p00_L_0D19();
  p00_L_29DF();
  p06_L_4EB1();
  return;
  lab_p06_L_4F7F: ;
  p00_L_2990();
  p00_L_2964();
  p00_L_0C13();
  p00_L_1100();
  p00_L_292F();
  p00_L_2940();
  p00_L_0C2D();
  p00_L_10F8();
  p00_L_0D1F();
  p00_L_1169();
  p00_L_0D1F();
  p00_L_1171();
  p00_L_289D();
  p00_L_2964();
  p00_L_0C13();
  p00_L_1100();
  p00_L_292F();
  p00_L_294C();
  p00_L_0C2D();
  p00_L_10F8();
  p00_L_0D1F();
  p00_L_10DD();
  p00_L_0D1F();
  p00_L_1108();
  p00_L_0C13();
  p00_L_1171();
  p00_L_1130();
  p00_L_10EF();
  p00_L_0C2D();
  p00_L_0C18();
  p00_L_14C7();
  if (flag_z()) goto lab_p06_L_4FEB;
  p00_L_15CB();
  if (flag_nz()) goto lab_p06_L_4FEB;
  a = mem_read8(0x84AF);
  a = a ^ 0x80;
  flag_logic(a);
  mem_write8(0x84AF, a);
  lab_p06_L_4FEB: ;
  p00_L_15D6();
  p00_L_1169();
  p00_L_291C();
  p00_L_290B();
  p00_L_29FB();
  p00_L_1128();
  p00_L_0D1F();
  p00_L_0D16();
  p00_L_1108();
  p00_L_1078();
  if (flag_c()) goto lab_p06_L_4E8E;
  if (flag_z()) goto lab_p06_L_4E8E;
  p00_L_28B5();
  p06_L_50DE();
  if (flag_nc()) goto lab_p06_L_4E8E;
  p00_L_289D();
  p06_L_50DE();
  if (flag_nc()) goto lab_p06_L_4E8E;
  p00_L_113A();
  p00_L_1128();
  p00_L_0ED0();
  p00_L_29DF();
  p00_L_2964();
  p00_rst30();
  p00_L_2A1F();
  p00_L_28B0();
  p00_L_0C2D();
  p00_L_28E0();
  p00_L_107E();
  if (flag_c()) goto lab_p06_L_5053;
  p00_L_289D();
  p00_L_2958();
  p00_L_0C2D();
  p00_L_28E0();
  p00_L_107E();
  if (flag_nc()) goto lab_p06_L_506A;
  lab_p06_L_5053: ;
  p00_L_28CB();
  p00_L_2964();
  p00_L_0C2D();
  a = mem_read8(0x8478);
  cpu_push_af();
  p00_L_28F1();
  cpu_pop_af();
  mem_write8(0x8478, a);
  p06_L_4EB1();
  return;
  lab_p06_L_506A: ;
  p00_L_2910();
  p06_L_4EB1();
  return;
  lab_p06_L_50A9: ;
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 3)));
  cpu_pop_af();
  p00_L_25C8();
  p00_L_2985();
  p00_L_39ED();
  p00_L_2977();
  p00_L_3975();
  p00_L_2902();
  p00_L_16BC();
  p00_L_2969();
  set_de(0x00AB);
  p00_L_21B6();
  return;
}

/* flash page 6 cpu 0x4EB1 (offset 0x0EB1) */
void p06_L_4EB1(void) {
  a = mem_read8(0x8478);
  cpu_push_af();
  p00_L_28EC();
  p00_L_1078();
  if (flag_c()) goto lab_p06_L_4EC3;
  cpu_pop_af();
  p00_L_2910();
  goto lab_p06_L_4ECA;
  lab_p06_L_4EC3: ;
  p00_L_28F1();
  cpu_pop_af();
  mem_write8(0x8478, a);
  lab_p06_L_4ECA: ;
  p00_L_2964();
  p00_rst30();
  p00_L_2A1F();
  p00_L_2964();
  p00_L_107E();
  cpu_push_af();
  p00_L_295D();
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  p06_L_5070();
  p00_L_2A0F();
  p00_L_2934();
  p00_L_107E();
  if (flag_c()) goto lab_p06_L_4F5F;
  if (flag_z()) goto lab_p06_L_4F5F;
  p00_L_295D();
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) p00_L_29C8();
  cpu_pop_af();
  if (flag_nc()) p00_L_29AA();
  p00_L_2945();
  p00_L_2923();
  p00_L_107E();
  if (flag_nc()) goto lab_p06_L_4F35;
  p00_L_2970();
  p00_L_2964();
  p00_L_107E();
  if (flag_z()) goto lab_p06_L_4F35;
  p00_L_2951();
  p00_L_2923();
  p00_L_107E();
  if (flag_nc()) goto lab_p06_L_4F50;
  p00_L_2990();
  p00_L_2964();
  p00_L_107E();
  if (flag_z()) goto lab_p06_L_4F50;
  p00_L_2970();
  p00_L_2997();
  p00_L_107E();
  if (flag_nz()) { p06_L_4E29(); return; }
  lab_p06_L_4F35: ;
  p00_L_2970();
  p00_L_2A2F();
  p00_L_2945();
  p00_L_2A1B();
  p00_L_295D();
  p00_L_2A2B();
  p00_L_2928();
  p00_L_2A17();
  p06_L_4E29();
  return;
  lab_p06_L_4F50: ;
  p00_L_295D();
  p00_L_2A2F();
  p00_L_2928();
  p00_L_2A1B();
  p06_L_4E29();
  return;
  lab_p06_L_4F5F: ;
  p00_L_2969();
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) p00_L_29AA();
  cpu_pop_af();
  if (flag_nc()) p00_L_29C8();
  set_hl(mem_read16(0x9302));
  set_de(0xFF70);
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  set_hl(0x0009);
  set_hl((uint16_t)(hl() + de()));
  set_bc(0x003F);
  while (bc() != 0) { cpu_ldi(); }
  p06_L_4E29();
  return;
}

/* flash page 6 cpu 0x5070 (offset 0x1070) */
void p06_L_5070(void) {
  cpu_push_af();
  p00_rst08();
  p00_L_2977();
  p00_rst10();
  set_hl(0x8483);
  p00_L_1183();
  p00_L_2902();
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p00_L_39E7();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  p00_L_1717();
  p00_L_16B5();
  cpu_pop_af();
  if (flag_nc()) goto lab_p06_L_5096;
  p00_L_0E4C();
  lab_p06_L_5096: ;
  p00_L_1653();
  return;
}

/* flash page 6 cpu 0x50DE (offset 0x10DE) */
void p06_L_50DE(void) {
  p00_L_2964();
  p00_L_0C2D();
  p00_L_1128();
  p00_L_0D1F();
  p00_L_1108();
  p00_L_107E();
  return;
}

/* flash page 6 cpu 0x50F0 (offset 0x10F0) */
void p06_L_50F0(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x97A7, a);
  p00_L_1037();
  if (flag_nz()) goto lab_p06_L_5113;
  a = 0x0E;
  p06_L_55AA();
  a = c;
  flag_cmp(a, 0x11);
  if (flag_nc()) goto lab_p06_L_510D;
  p06_L_5C0C();
  set_hl(0x848E);
  p00_L_3C87();
  return;
  lab_p06_L_510D: ;
  p06_L_5C7E();
  p06_L_5333();
  return;
  lab_p06_L_5113: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p06_L_512F;
  p06_L_57F9();
  a = c;
  flag_cmp(a, 0x11);
  if (flag_nc()) goto lab_p06_L_5129;
  p06_L_5C0C();
  set_hl(0x97B1);
  p00_L_3C87();
  return;
  lab_p06_L_5129: ;
  p06_L_5C7E();
  p06_L_5341();
  return;
  lab_p06_L_512F: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p06_L_5147;
  p06_L_5C7E();
  p06_L_5B20();
  a = c;
  flag_cmp(a, 0x11);
  if (flag_nc()) goto lab_p06_L_5144;
  a = 0x10;
  a = (uint8_t)(a - c);
  mem_write8(0x97AE, a);
  lab_p06_L_5144: ;
  p06_L_5350();
  return;
  lab_p06_L_5147: ;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p06_L_515F;
  p06_L_5C7E();
  p06_L_5297();
  a = c;
  flag_cmp(a, 0x11);
  if (flag_nc()) goto lab_p06_L_515C;
  a = 0x10;
  a = (uint8_t)(a - c);
  mem_write8(0x97AE, a);
  lab_p06_L_515C: ;
  p06_L_53F6();
  return;
  lab_p06_L_515F: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p06_L_516F;
  p06_L_5CA3();
  p06_L_5B75();
  p06_L_5C19();
  p06_L_549D();
  return;
  lab_p06_L_516F: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p06_L_5185;
  p06_L_5C7E();
  p06_L_5189();
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p06_L_5BC4(); return; }
  a = 0;
  flag_logic(a);
  mem_write8(0x97AE, a);
  p06_L_51DB();
  return;
  lab_p06_L_5185: ;
  p00_L_3DFB();
  return;
}

/* flash page 6 cpu 0x5189 (offset 0x1189) */
void p06_L_5189(void) {
  set_hl(0x0000);
  mem_write16(0x9804, hl());
  p00_L_2429();
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x9806, bc());
  mem_write16(0x84DD, hl());
  mem_write16(0x981C, hl());
  cpu_push16(ix);
  ix = 0x0000;
  cpu_add_ix_sp();
  sp = (uint16_t)(sp - 1);
  /* ld (ix-0x01),0x00 */
  lab_p06_L_51AE: ;
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_51D1;
  cpu_push_hl();
  p06_L_4467();
  if (flag_nc()) goto lab_p06_L_51B9;
  set_bc((uint16_t)(bc() - 1));
  lab_p06_L_51B9: ;
  cpu_pop_de();
  cpu_push_bc();
  cpu_push_hl();
  cpu_ex_de_hl();
  p00_L_3DB3();
  /* ld a,(ix-0x01) */
  a = (uint8_t)(a + c);
  /* ld (ix-0x01),a */
  cpu_pop_hl();
  cpu_pop_bc();
  flag_cmp(a, 0x11);
  if (flag_nc()) goto lab_p06_L_51D1;
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() - 1));
  goto lab_p06_L_51AE;
  lab_p06_L_51D1: ;
  /* ld c,(ix-0x01) */
  b = 0x00;
  sp = ix;
  ix = cpu_pop16();
  return;
}

/* flash page 6 cpu 0x51DB (offset 0x11DB) */
void p06_L_51DB(void) {
  p06_L_5BC4();
  set_hl(mem_read16(0x97A8));
  set_de(mem_read16(0x9804));
  p00_L_192A();
  if (flag_p()) goto lab_p06_L_5220;
  set_hl(mem_read16(0x84DD));
  set_hl((uint16_t)(hl() - 1));
  set_de(mem_read16(0x981C));
  a = a | 0x01;
  flag_logic(a);
  cpu_push_af();
  p00_L_192A();
  if (flag_z()) goto lab_p06_L_5204;
  cpu_pop_af();
  set_hl((uint16_t)(hl() - 1));
  p00_L_172F();
  cpu_push_af();
  if (flag_z()) goto lab_p06_L_5204;
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_5204: ;
  mem_write16(0x84DD, hl());
  p00_L_3DB3();
  set_hl(mem_read16(0x9804));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9804, hl());
  set_hl(mem_read16(0x9806));
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  if (flag_nz()) goto lab_p06_L_521B;
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_521B: ;
  mem_write16(0x9806, hl());
  goto lab_p06_L_524E;
  lab_p06_L_5220: ;
  set_hl(mem_read16(0x84DD));
  p00_L_3DB3();
  set_hl(mem_read16(0x9804));
  set_hl((uint16_t)(hl() + bc()));
  set_de(mem_read16(0x97A8));
  p00_L_192A();
  if (flag_p()) goto lab_p06_L_524E;
  mem_write16(0x9804, hl());
  set_hl(mem_read16(0x84DD));
  p00_L_172F();
  set_de(mem_read16(0x9806));
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() + 1));
  if (flag_nz()) goto lab_p06_L_5247;
  set_de((uint16_t)(de() - 1));
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_5247: ;
  mem_write16(0x84DD, hl());
  mem_write16(0x9806, de());
  lab_p06_L_524E: ;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(mem_read16(0x84DD));
  set_bc(mem_read16(0x9806));
  cpu_push_bc();
  cpu_push_hl();
  p00_L_3DB3();
  a = mem_read8(0x848E);
  p00_L_3CAB();
  set_hl(mem_read16(0x97AE));
  set_de(mem_read16(0x9804));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x97AE, hl());
  set_hl(0x848F);
  goto lab_p06_L_527C;
  lab_p06_L_5274: ;
  cpu_push_bc();
  cpu_push_hl();
  p00_L_3DB3();
  set_hl(0x848E);
  lab_p06_L_527C: ;
  p00_L_3CB1();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_push_af();
  p00_L_172F();
  set_bc((uint16_t)(bc() - 1));
  set_hl((uint16_t)(hl() + 1));
  if (flag_nz()) goto lab_p06_L_528B;
  set_bc((uint16_t)(bc() - 1));
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_528B: ;
  cpu_pop_af();
  if (flag_c()) goto lab_p06_L_5292;
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_5274;
  lab_p06_L_5292: ;
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x5250 (offset 0x1250) */
void p06_L_5250(void) {
  a = (uint8_t)(a + h);
  cpu_push_hl();
  set_hl(mem_read16(0x84DD));
  set_bc(mem_read16(0x9806));
  cpu_push_bc();
  cpu_push_hl();
  p00_L_3DB3();
  a = mem_read8(0x848E);
  p00_L_3CAB();
  set_hl(mem_read16(0x97AE));
  set_de(mem_read16(0x9804));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x97AE, hl());
  set_hl(0x848F);
  goto lab_p06_L_527C;
  lab_p06_L_5274: ;
  cpu_push_bc();
  cpu_push_hl();
  p00_L_3DB3();
  set_hl(0x848E);
  lab_p06_L_527C: ;
  p00_L_3CB1();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_push_af();
  p00_L_172F();
  set_bc((uint16_t)(bc() - 1));
  set_hl((uint16_t)(hl() + 1));
  if (flag_nz()) goto lab_p06_L_528B;
  set_bc((uint16_t)(bc() - 1));
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_528B: ;
  cpu_pop_af();
  if (flag_c()) goto lab_p06_L_5292;
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_5274;
  lab_p06_L_5292: ;
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x5297 (offset 0x1297) */
void p06_L_5297(void) {
  p06_L_5B54();
  cpu_push16(ix);
  ix = 0x0000;
  cpu_add_ix_sp();
  sp = (uint16_t)(sp - 1);
  /* ld (ix-0x01),0x02 */
  lab_p06_L_52A7: ;
  cpu_push_bc();
  p00_L_11F7();
  cpu_push_hl();
  p06_L_57F9();
  cpu_pop_hl();
  c = (uint8_t)(c + 1);
  /* ld a,(ix-0x01) */
  a = (uint8_t)(a + c);
  /* ld (ix-0x01),a */
  cpu_pop_bc();
  flag_cmp(a, 0x11);
  if (flag_nc()) goto lab_p06_L_52C2;
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_52A7;
  lab_p06_L_52C2: ;
  /* ld c,(ix-0x01) */
  b = 0x00;
  set_bc((uint16_t)(bc() - 1));
  sp = ix;
  ix = cpu_pop16();
  return;
}

/* flash page 6 cpu 0x52CD (offset 0x12CD) */
void p06_L_52CD(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 3)) == 0);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p06_L_52E1;
  set_hl(mem_read16(0x97AA));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x97AA, hl());
  goto lab_p06_L_52E6;
  lab_p06_L_52E1: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 3)) == 0);
  if (flag_z()) return;
  lab_p06_L_52E6: ;
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p06_L_5322;
  lab_p06_L_5322: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x97A7, a);
  p00_L_3CC3();
  p00_L_32C1();
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_533D;
  p06_L_5333();
  return;
  lab_p06_L_533D: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p06_L_534B;
  p06_L_5341();
  return;
  lab_p06_L_534B: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p06_L_53EC;
  p06_L_5350();
  return;
  lab_p06_L_53EC: ;
  flag_cmp(a, 0x04);
  if (flag_z()) { p06_L_51DB(); return; }
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p06_L_5498;
  p06_L_53F6();
  return;
  lab_p06_L_5498: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p06_L_555C;
  p06_L_549D();
  return;
  lab_p06_L_555C: ;
  return;
}

/* flash page 6 cpu 0x52EC (offset 0x12EC) */
void p06_L_52EC(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 4)) == 0);
  if (flag_z()) return;
  set_hl(mem_read16(0x97A8));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x97A8, hl());
  goto lab_p06_L_5322;
  lab_p06_L_5322: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x97A7, a);
  p00_L_3CC3();
  p00_L_32C1();
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_533D;
  p06_L_5333();
  return;
  lab_p06_L_533D: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p06_L_534B;
  p06_L_5341();
  return;
  lab_p06_L_534B: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p06_L_53EC;
  p06_L_5350();
  return;
  lab_p06_L_53EC: ;
  flag_cmp(a, 0x04);
  if (flag_z()) { p06_L_51DB(); return; }
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p06_L_5498;
  p06_L_53F6();
  return;
  lab_p06_L_5498: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p06_L_555C;
  p06_L_549D();
  return;
  lab_p06_L_555C: ;
  return;
}

/* flash page 6 cpu 0x52FA (offset 0x12FA) */
void p06_L_52FA(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 2)) == 0);
  if (flag_z()) return;
  set_hl(mem_read16(0x97AA));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x97AA, hl());
  goto lab_p06_L_5322;
  lab_p06_L_5322: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x97A7, a);
  p00_L_3CC3();
  p00_L_32C1();
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_533D;
  p06_L_5333();
  return;
  lab_p06_L_533D: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p06_L_534B;
  p06_L_5341();
  return;
  lab_p06_L_534B: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p06_L_53EC;
  p06_L_5350();
  return;
  lab_p06_L_53EC: ;
  flag_cmp(a, 0x04);
  if (flag_z()) { p06_L_51DB(); return; }
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p06_L_5498;
  p06_L_53F6();
  return;
  lab_p06_L_5498: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p06_L_555C;
  p06_L_549D();
  return;
  lab_p06_L_555C: ;
  return;
}

/* flash page 6 cpu 0x5308 (offset 0x1308) */
void p06_L_5308(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 3)) == 0);
  if (flag_z()) return;
  set_hl(mem_read16(0x97AA));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x97AA, hl());
  goto lab_p06_L_5322;
  lab_p06_L_5322: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x97A7, a);
  p00_L_3CC3();
  p00_L_32C1();
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_533D;
  p06_L_5333();
  return;
  lab_p06_L_533D: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p06_L_534B;
  p06_L_5341();
  return;
  lab_p06_L_534B: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p06_L_53EC;
  p06_L_5350();
  return;
  lab_p06_L_53EC: ;
  flag_cmp(a, 0x04);
  if (flag_z()) { p06_L_51DB(); return; }
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p06_L_5498;
  p06_L_53F6();
  return;
  lab_p06_L_5498: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p06_L_555C;
  p06_L_549D();
  return;
  lab_p06_L_555C: ;
  return;
}

/* flash page 6 cpu 0x5316 (offset 0x1316) */
void p06_L_5316(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 5)) == 0);
  if (flag_z()) return;
  set_hl(mem_read16(0x97A8));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x97A8, hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x97A7, a);
  p00_L_3CC3();
  p00_L_32C1();
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_533D;
  p06_L_5333();
  return;
  lab_p06_L_533D: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p06_L_534B;
  p06_L_5341();
  return;
  lab_p06_L_534B: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p06_L_53EC;
  p06_L_5350();
  return;
  lab_p06_L_53EC: ;
  flag_cmp(a, 0x04);
  if (flag_z()) { p06_L_51DB(); return; }
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p06_L_5498;
  p06_L_53F6();
  return;
  lab_p06_L_5498: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p06_L_555C;
  p06_L_549D();
  return;
  lab_p06_L_555C: ;
  return;
}

/* flash page 6 cpu 0x5333 (offset 0x1333) */
void p06_L_5333(void) {
  p06_L_5BC4();
  set_hl(0x848E);
  p00_L_3CB1();
  return;
}

/* flash page 6 cpu 0x5341 (offset 0x1341) */
void p06_L_5341(void) {
  p06_L_5BC4();
  set_hl(0x97B1);
  p00_L_3CB1();
  return;
}

/* flash page 6 cpu 0x5350 (offset 0x1350) */
void p06_L_5350(void) {
  p06_L_5BC4();
  set_hl(mem_read16(0x97A8));
  set_de(mem_read16(0x9804));
  p00_L_192A();
  if (flag_p()) goto lab_p06_L_5381;
  set_hl(mem_read16(0x84DD));
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84DD, hl());
  p00_rst20();
  p06_L_55A8();
  c = (uint8_t)(c + 1);
  set_hl(mem_read16(0x9804));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9804, hl());
  set_hl(mem_read16(0x9806));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x9806, hl());
  goto lab_p06_L_53AB;
  lab_p06_L_5381: ;
  set_hl(mem_read16(0x84DD));
  p00_rst20();
  p06_L_55A8();
  c = (uint8_t)(c + 1);
  set_hl(mem_read16(0x9804));
  set_hl((uint16_t)(hl() + bc()));
  set_de(mem_read16(0x97A8));
  p00_L_192A();
  if (flag_p()) goto lab_p06_L_53AB;
  mem_write16(0x9804, hl());
  set_hl(mem_read16(0x84DD));
  set_de(0x0009);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84DD, hl());
  set_hl(mem_read16(0x9806));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x9806, hl());
  lab_p06_L_53AB: ;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  a = 0x7B;
  p00_L_3CAB();
  set_hl(mem_read16(0x97AE));
  set_de(mem_read16(0x9804));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x97AE, hl());
  set_bc(mem_read16(0x9806));
  set_hl(mem_read16(0x84DD));
  goto lab_p06_L_53CD;
  lab_p06_L_53C8: ;
  p06_L_5FA2();
  if (flag_c()) goto lab_p06_L_53E7;
  lab_p06_L_53CD: ;
  cpu_push_bc();
  p00_rst20();
  cpu_push_hl();
  p06_L_55A8();
  set_hl(0x848E);
  p00_L_3CB1();
  cpu_pop_hl();
  cpu_pop_bc();
  if (flag_c()) goto lab_p06_L_53E7;
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_53C8;
  a = 0x7D;
  p00_L_3CAB();
  lab_p06_L_53E7: ;
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x53F6 (offset 0x13F6) */
void p06_L_53F6(void) {
  p06_L_5BC4();
  set_hl(mem_read16(0x97A8));
  set_de(mem_read16(0x9804));
  p00_L_192A();
  if (flag_p()) goto lab_p06_L_5429;
  set_hl(mem_read16(0x84DD));
  set_de(0xFFEE);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84DD, hl());
  p00_L_11F7();
  p06_L_57F9();
  c = (uint8_t)(c + 1);
  set_hl(mem_read16(0x9804));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  mem_write16(0x9804, hl());
  set_hl(mem_read16(0x9806));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x9806, hl());
  goto lab_p06_L_5455;
  lab_p06_L_5429: ;
  set_hl(mem_read16(0x84DD));
  p00_L_11F7();
  p06_L_57F9();
  c = (uint8_t)(c + 1);
  set_hl(mem_read16(0x9804));
  set_hl((uint16_t)(hl() + bc()));
  set_de(mem_read16(0x97A8));
  p00_L_192A();
  if (flag_p()) goto lab_p06_L_5455;
  mem_write16(0x9804, hl());
  set_hl(mem_read16(0x84DD));
  set_de(0x0012);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x84DD, hl());
  set_hl(mem_read16(0x9806));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x9806, hl());
  lab_p06_L_5455: ;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  a = 0x7B;
  p00_L_3CAB();
  set_hl(mem_read16(0x97AE));
  set_de(mem_read16(0x9804));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x97AE, hl());
  set_bc(mem_read16(0x9806));
  set_hl(mem_read16(0x84DD));
  goto lab_p06_L_5477;
  lab_p06_L_5472: ;
  p06_L_5FA2();
  if (flag_c()) goto lab_p06_L_5493;
  lab_p06_L_5477: ;
  cpu_push_bc();
  p00_L_11F7();
  cpu_push_hl();
  p06_L_57F9();
  set_hl(0x97B1);
  p00_L_3CB1();
  cpu_pop_hl();
  cpu_pop_bc();
  if (flag_c()) goto lab_p06_L_5493;
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_5472;
  a = 0x7D;
  p00_L_3CAB();
  lab_p06_L_5493: ;
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x549D (offset 0x149D) */
void p06_L_549D(void) {
  cpu_push16(ix);
  ix = 0x0000;
  cpu_add_ix_sp();
  cpu_push_hl();
  cpu_push_hl();
  cpu_push_hl();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p06_L_555D();
  goto lab_p06_L_54CB;
  lab_p06_L_54CB: ;
  p00_L_3CAB();
  if (flag_c()) goto lab_p06_L_5535;
  p06_L_5CD6();
  /* ld b,(ix-0x03) */
  c = 0x01;
  /* ld (ix-0x05),c */
  set_de(mem_read16(0x84DD));
  p00_L_3B67();
  a = 0xC1;
  p00_L_3CAB();
  goto lab_p06_L_54EE;
  lab_p06_L_54E9: ;
  p06_L_5FA2();
  if (flag_c()) goto lab_p06_L_5535;
  lab_p06_L_54EE: ;
  p00_rst20();
  cpu_push_hl();
  p06_L_5CF0();
  set_hl(mem_read16(0x97AE));
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  set_hl(mem_read16(0x97A8));
  set_hl((uint16_t)(hl() + 1));
  p00_L_192A();
  if (flag_m()) goto lab_p06_L_5509;
  mem_write16(0x97AE, de());
  cpu_pop_hl();
  goto lab_p06_L_5523;
  lab_p06_L_5509: ;
  cpu_push_bc();
  p06_L_55A8();
  set_hl(0x848E);
  p00_L_3CB1();
  cpu_pop_de();
  cpu_pop_hl();
  if (flag_c()) goto lab_p06_L_5535;
  a = e;
  a = (uint8_t)(a - c);
  if (flag_z()) goto lab_p06_L_5523;
  b = a;
  lab_p06_L_551C: ;
  p06_L_5FA2();
  if (flag_c()) goto lab_p06_L_5535;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_551C;
  lab_p06_L_5523: ;
  /* ld a,(ix-0x05) */
  /* cp (ix-0x06) */
  if (flag_z()) goto lab_p06_L_5530;
  /* inc (ix-0x05) */
  goto lab_p06_L_54E9;
  lab_p06_L_5530: ;
  a = 0x5D;
  p00_L_3CAB();
  lab_p06_L_5535: ;
  /* ld a,(ix-0x03) */
  /* cp (ix-0x04) */
  if (flag_z()) goto lab_p06_L_5543;
  /* inc (ix-0x03) */
  p06_L_54B1();
  return;
  lab_p06_L_5543: ;
  a = 0x5D;
  p00_L_3CAB();
  p06_L_5C5B();
  set_hl(0x97A6);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  sp = ix;
  ix = cpu_pop16();
  return;
}

/* flash page 6 cpu 0x54B1 (offset 0x14B1) */
void p06_L_54B1(void) {
  lab_p06_L_54B1: ;
  p06_L_5FA2();
  set_hl(mem_read16(0x97AC));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x97AC, hl());
  set_hl(0x0000);
  mem_write16(0x97AE, hl());
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 1)));
  a = 0x20;
  p00_L_3CAB();
  if (flag_c()) goto lab_p06_L_5535;
  p06_L_5CD6();
  /* ld b,(ix-0x03) */
  c = 0x01;
  /* ld (ix-0x05),c */
  set_de(mem_read16(0x84DD));
  p00_L_3B67();
  a = 0xC1;
  p00_L_3CAB();
  goto lab_p06_L_54EE;
  lab_p06_L_54E9: ;
  p06_L_5FA2();
  if (flag_c()) goto lab_p06_L_5535;
  lab_p06_L_54EE: ;
  p00_rst20();
  cpu_push_hl();
  p06_L_5CF0();
  set_hl(mem_read16(0x97AE));
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  set_hl(mem_read16(0x97A8));
  set_hl((uint16_t)(hl() + 1));
  p00_L_192A();
  if (flag_m()) goto lab_p06_L_5509;
  mem_write16(0x97AE, de());
  cpu_pop_hl();
  goto lab_p06_L_5523;
  lab_p06_L_5509: ;
  cpu_push_bc();
  p06_L_55A8();
  set_hl(0x848E);
  p00_L_3CB1();
  cpu_pop_de();
  cpu_pop_hl();
  if (flag_c()) goto lab_p06_L_5535;
  a = e;
  a = (uint8_t)(a - c);
  if (flag_z()) goto lab_p06_L_5523;
  b = a;
  lab_p06_L_551C: ;
  p06_L_5FA2();
  if (flag_c()) goto lab_p06_L_5535;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_551C;
  lab_p06_L_5523: ;
  /* ld a,(ix-0x05) */
  /* cp (ix-0x06) */
  if (flag_z()) goto lab_p06_L_5530;
  /* inc (ix-0x05) */
  goto lab_p06_L_54E9;
  lab_p06_L_5530: ;
  a = 0x5D;
  p00_L_3CAB();
  lab_p06_L_5535: ;
  /* ld a,(ix-0x03) */
  /* cp (ix-0x04) */
  if (flag_z()) goto lab_p06_L_5543;
  /* inc (ix-0x03) */
  goto lab_p06_L_54B1;
  lab_p06_L_5543: ;
  a = 0x5D;
  p00_L_3CAB();
  p06_L_5C5B();
  set_hl(0x97A6);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  sp = ix;
  ix = cpu_pop16();
  return;
}

/* flash page 6 cpu 0x555D (offset 0x155D) */
void p06_L_555D(void) {
  p06_L_5BC4();
  set_hl(0x97A6);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  set_hl(mem_read16(0x84DD));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  /* ld (ix-0x06),a */
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  /* ld (ix-0x04),a */
  a = 0x01;
  /* ld (ix-0x03),a */
  a = 0xC1;
  return;
}

/* flash page 6 cpu 0x557D (offset 0x157D) */
void p06_L_557D(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 0)));
  p06_L_558C();
  p06_L_58F5();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 0)));
  return;
}

/* flash page 6 cpu 0x558C (offset 0x158C) */
void p06_L_558C(void) {
  b = a;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x53);
  a = b;
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 0)));
  return;
}

/* flash page 6 cpu 0x5599 (offset 0x1599) */
void p06_L_5599(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 0)));
  p06_L_58F5();
  p06_L_5F54();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 0)));
  return;
}

/* flash page 6 cpu 0x55A8 (offset 0x15A8) */
void p06_L_55A8(void) {
  a = 0x13;
  p06_L_55AA();
  return;
}

/* flash page 6 cpu 0x55AA (offset 0x15AA) */
void p06_L_55AA(void) {
  cpu_push16(ix);
  ix = 0x0000;
  cpu_add_ix_sp();
  cpu_push_hl();
  set_hl(0xFFD1);
  set_hl((uint16_t)(hl() + sp));
  sp = hl();
  /* ld ixl,(ix-0x02) */
  /* ld ixh,(ix-0x01) */
  /* ld (ix-0x15),a */
  b = mem_read8((uint16_t)(iy + 0x0A));
  p06_L_5B09();
  /* ld (ix-0x13),a */
  b = mem_read8((uint16_t)(iy + 0x0B));
  p06_L_5B09();
  p06_L_55D0();
  return;
}

/* flash page 6 cpu 0x55D0 (offset 0x15D0) */
void p06_L_55D0(void) {
  lab_p06_L_55D0: ;
  /* ld (ix-0x14),a */
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_55E4;
  /* ld a,(ix-0x15) */
  p06_L_58F5();
  sp = ix;
  ix = cpu_pop16();
  return;
  lab_p06_L_55E1: ;
  a = 0;
  flag_logic(a);
  goto lab_p06_L_55D0;
  lab_p06_L_55E4: ;
  p06_L_5797();
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p06_L_5654;
  p00_L_3AA7();
  if (flag_nc()) goto lab_p06_L_55F6;
  p06_L_57AE();
  goto lab_p06_L_55E1;
  lab_p06_L_55F6: ;
  a = 0;
  flag_logic(a);
  p06_L_57C9();
  l = 0xDE;
  p06_L_57C2();
  set_de(0x8478);
  p06_L_57AA();
  p00_L_1179();
  a = 0x10;
  p06_L_58F5();
  p06_L_57C0();
  cpu_ex_de_hl();
  set_hl(0x848E);
  p00_L_25D8();
  l = 0xDE;
  p06_L_57C2();
  p00_rst20();
  a = 0x10;
  p06_L_58F5();
  p06_L_57DC();
  set_hl(0x848E);
  set_hl((uint16_t)(hl() + bc()));
  mem_write8(hl(), 0x2F);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x00);
  p06_L_57C0();
  set_de(0x848E);
  p00_L_25E0();
  p06_L_57AE();
  p06_L_563A();
  return;
  lab_p06_L_5654: ;
  p00_L_15D6();
  p00_rst08();
  p00_L_0E72();
  p00_L_10DD();
  p00_L_0C13();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x86);
  if (flag_nc()) goto lab_p06_L_5790;
  e = a;
  a = 0x8C;
  a = (uint8_t)(a - e);
  cpu_push_af();
  l = 0xDE;
  p06_L_57C2();
  set_de(0x8478);
  p06_L_57AA();
  p00_L_1135();
  p00_L_2FFD();
  p00_L_0D1F();
  p00_rst08();
  p00_L_0E72();
  p00_L_10DD();
  p00_L_0C13();
  cpu_pop_hl();
  h = (uint8_t)(h - 1);
  h = (uint8_t)(h - 1);
  a = mem_read8(0x8479);
  flag_cmp(a, 0x80);
  a = mem_read8(0x847A);
  if (flag_nz()) goto lab_p06_L_569D;
  p00_L_12B1();
  h = (uint8_t)(h + 1);
  lab_p06_L_569D: ;
  cpu_push_hl();
  /* ld (ix-0x2F),a */
  p00_L_1135();
  p00_L_2FFD();
  p00_L_0D1F();
  a = 0xFF;
  p06_L_57C9();
  a = mem_read8(0x8479);
  a = (uint8_t)(a - 0x80);
  if (flag_nc()) goto lab_p06_L_56D9;
  a = (uint8_t)(a + 0x84);
  a = (uint8_t)(a - 0x80);
  if (flag_c()) goto lab_p06_L_56D6;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_56D2;
  a = mem_read8(0x847A);
  a = (uint8_t)(a + 0x50);
  /* daa */
  if (flag_nc()) goto lab_p06_L_56D6;
  set_hl(0x0010);
  mem_write16(0x847A, hl());
  a = 0x7D;
  mem_write8(0x8479, a);
  lab_p06_L_56D2: ;
  a = 0x04;
  goto lab_p06_L_56E0;
  lab_p06_L_56D6: ;
  p00_L_128A();
  lab_p06_L_56D9: ;
  a = mem_read8(0x8479);
  a = (uint8_t)(a - 0x80);
  a = (uint8_t)(a + 0x05);
  lab_p06_L_56E0: ;
  cpu_pop_de();
  flag_cmp(a, d);
  if (flag_c()) goto lab_p06_L_56E5;
  a = d;
  lab_p06_L_56E5: ;
  p06_L_58F5();
  set_hl(mem_read16(0x848E));
  set_de(0x3036);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  /* ld a,(ix-0x2F) */
  if (flag_nz()) goto lab_p06_L_5701;
  set_hl(0x848E);
  mem_write8(hl(), 0x30);
  set_bc(0x0001);
  a = (uint8_t)(a + 0x01);
  /* daa */
  lab_p06_L_5701: ;
  set_hl(0x848E);
  set_hl((uint16_t)(hl() + bc()));
  mem_write8(hl(), 0x22);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x00);
  flag_cmp(a, 0x60);
  cpu_push_af();
  if (flag_nz()) goto lab_p06_L_5710;
  a = 0;
  flag_logic(a);
  lab_p06_L_5710: ;
  set_hl(0x8483);
  flag_cmp(a, 0x10);
  if (flag_c()) goto lab_p06_L_5720;
  cpu_push_af();
  p00_L_12B1();
  a = (uint8_t)(a + 0x30);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  lab_p06_L_5720: ;
  a = a & 0x0F;
  flag_logic(a);
  a = (uint8_t)(a + 0x30);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x27);
  a = mem_read8(0x848E);
  flag_cmp(a, 0x2E);
  if (flag_nz()) goto lab_p06_L_5733;
  set_hl((uint16_t)(hl() + 1));
  a = 0x30;
  mem_write8(hl(), a);
  lab_p06_L_5733: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  set_hl(0x848E);
  p00_L_25D8();
  l = 0xDE;
  p06_L_57C2();
  cpu_push_hl();
  p00_rst20();
  cpu_pop_de();
  set_hl(0x8483);
  p00_L_25D8();
  cpu_pop_af();
  if (flag_nz()) goto lab_p06_L_5756;
  p00_L_0C1B();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x88);
  if (flag_z()) goto lab_p06_L_578D;
  lab_p06_L_5756: ;
  a = 0x08;
  p06_L_58F5();
  set_hl(0x848E);
  set_hl((uint16_t)(hl() + bc()));
  mem_write8(hl(), 0x14);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x00);
  l = 0xDE;
  p06_L_57C2();
  set_de(0x848E);
  p00_L_25E0();
  p06_L_57B9();
  p00_L_15CB();
  if (flag_z()) goto lab_p06_L_5787;
  set_hl(0x84A1);
  set_de(0x84A2);
  set_bc(0x0014);
  /* lddr */
  a = 0x1A;
  mem_write8(0x848E, a);
  lab_p06_L_5787: ;
  p06_L_57DC();
  p06_L_563A();
  return;
  lab_p06_L_578D: ;
  p06_L_57DC();
  lab_p06_L_5790: ;
  p06_L_57B9();
  a = 0;
  flag_logic(a);
  goto lab_p06_L_55D0;
}

/* flash page 6 cpu 0x563A (offset 0x163A) */
void p06_L_563A(void) {
  set_hl(0x848E);
  p06_L_563D();
  return;
}

/* flash page 6 cpu 0x563D (offset 0x163D) */
void p06_L_563D(void) {
  sp = ix;
  ix = cpu_pop16();
  cpu_push_af();
  cpu_push_hl();
  set_bc(0x0000);
  cpu_push_bc();
  a = 0;
  flag_logic(a);
  /* cpir */
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  set_hl((uint16_t)(hl() - 1));
  c = l;
  b = h;
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 6 cpu 0x563E (offset 0x163E) */
void p06_L_563E(void) {
  sp = hl();
  ix = cpu_pop16();
  cpu_push_af();
  cpu_push_hl();
  set_bc(0x0000);
  cpu_push_bc();
  a = 0;
  flag_logic(a);
  /* cpir */
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  set_hl((uint16_t)(hl() - 1));
  c = l;
  b = h;
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 6 cpu 0x5797 (offset 0x1797) */
void p06_L_5797(void) {
  l = 0xF7;
  p06_L_57C2();
  set_de(0x8478);
  p06_L_57AA();
  l = 0xEE;
  p06_L_57C2();
  set_de(0x8483);
  p06_L_57AA();
  return;
}

/* flash page 6 cpu 0x57AA (offset 0x17AA) */
void p06_L_57AA(void) {
  cpu_ex_de_hl();
  p00_L_1183();
  return;
}

/* flash page 6 cpu 0x57AE (offset 0x17AE) */
void p06_L_57AE(void) {
  p06_L_57B9();
  l = 0xEE;
  p06_L_57C2();
  p00_L_11F8();
  return;
}

/* flash page 6 cpu 0x57B9 (offset 0x17B9) */
void p06_L_57B9(void) {
  l = 0xF7;
  p06_L_57C2();
  p00_rst20();
  return;
}

/* flash page 6 cpu 0x57C0 (offset 0x17C0) */
void p06_L_57C0(void) {
  l = 0xD1;
  p06_L_57C2();
  return;
}

/* flash page 6 cpu 0x57C2 (offset 0x17C2) */
void p06_L_57C2(void) {
  cpu_push16(ix);
  cpu_pop_de();
  h = 0xFF;
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 6 cpu 0x57C9 (offset 0x17C9) */
void p06_L_57C9(void) {
  set_hl(0x97B0);
  b = mem_read8(hl());
  /* ld (ix-0x30),b */
  mem_write8(hl(), a);
  a = mem_read8(0x89FA);
  /* ld (ix-0x31),a */
  /* ld (iy+0x0A),0x00 */
  return;
}

/* flash page 6 cpu 0x57DC (offset 0x17DC) */
void p06_L_57DC(void) {
  /* ld a,(ix-0x30) */
  mem_write8(0x97B0, a);
  /* ld a,(ix-0x31) */
  mem_write8(0x89FA, a);
  return;
}

/* flash page 6 cpu 0x57F9 (offset 0x17F9) */
void p06_L_57F9(void) {
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) & ~(1u << 7)));
  p06_L_57FD();
  return;
}

/* flash page 6 cpu 0x57FD (offset 0x17FD) */
void p06_L_57FD(void) {
  cpu_push16(ix);
  ix = 0x0000;
  cpu_add_ix_sp();
  sp = (uint16_t)(sp - 1);
  p00_L_15C6();
  /* ld (ix-0x01),0x2B */
  if (flag_z()) goto lab_p06_L_5813;
  /* ld (ix-0x01),0x2D */
  lab_p06_L_5813: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0B)) & (1u << 7)) == 0);
  if (flag_z()) { p06_L_5837(); return; }
  set_hl(0x8478);
  set_de(0x97F2);
  p00_L_1063();
  set_hl(0x58EC);
  p00_L_25A2();
  p00_L_3AD1();
  a = 0x0C;
  p00_L_15FE();
  p00_L_25C8();
  /* ld (ix-0x01),0xDB */
  p06_L_5837();
  return;
}

/* flash page 6 cpu 0x5837 (offset 0x1837) */
void p06_L_5837(void) {
  set_hl(0x0000);
  mem_write16(0x97B1, hl());
  set_de(0x97B1);
  p00_L_14CC();
  if (flag_nz()) goto lab_p06_L_584B;
  p06_L_5C4D();
  p06_L_58E1();
  return;
  lab_p06_L_584B: ;
  p00_L_14C7();
  if (flag_nz()) goto lab_p06_L_5860;
  /* ld a,(ix-0x01) */
  flag_cmp(a, 0xDB);
  if (flag_z()) goto lab_p06_L_5860;
  flag_cmp(a, 0x2D);
  a = 0x1A;
  if (flag_z()) p06_L_5C48();
  goto lab_p06_L_5881;
  lab_p06_L_5860: ;
  p06_L_5C4D();
  /* ld a,(ix-0x01) */
  flag_cmp(a, 0xDB);
  if (flag_nz()) goto lab_p06_L_587E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p06_L_5874;
  a = 0xBF;
  goto lab_p06_L_587E;
  lab_p06_L_5874: ;
  p06_L_5C48();
  a = 0x5E;
  p06_L_5C48();
  a = 0x28;
  lab_p06_L_587E: ;
  p06_L_5C48();
  lab_p06_L_5881: ;
  cpu_push_de();
  p00_L_14B0();
  cpu_pop_de();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x80);
  if (flag_nz()) goto lab_p06_L_58AF;
  set_hl(0x847A);
  a = mem_read8(hl());
  flag_cmp(a, 0x10);
  if (flag_nz()) goto lab_p06_L_58AF;
  b = 0x06;
  lab_p06_L_5897: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_58AF;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_5897;
  /* ld a,(ix-0x01) */
  flag_cmp(a, 0xDB);
  if (flag_nz()) goto lab_p06_L_58C8;
  p00_L_15CB();
  a = 0x2D;
  if (flag_nz()) p06_L_5C48();
  goto lab_p06_L_58C8;
  lab_p06_L_58AF: ;
  /* ld a,(ix-0x01) */
  flag_cmp(a, 0xDB);
  a = mem_read8(0x8478);
  cpu_push_af();
  if (flag_nz()) p00_L_15D6();
  p06_L_55A8();
  cpu_pop_af();
  mem_write8(0x8478, a);
  p00_L_14B0();
  p06_L_5C52();
  lab_p06_L_58C8: ;
  a = 0xD7;
  p06_L_5C48();
  /* ld a,(ix-0x01) */
  flag_cmp(a, 0xDB);
  if (flag_nz()) { p06_L_58E1(); return; }
  a = 0x29;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1B)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p06_L_58DE;
  a = 0x11;
  lab_p06_L_58DE: ;
  p06_L_5C48();
  p06_L_58E1();
  return;
}

/* flash page 6 cpu 0x58E1 (offset 0x18E1) */
void p06_L_58E1(void) {
  a = 0x0C;
  mem_write8(0x8478, a);
  set_hl(0x97B1);
  p06_L_563D();
  return;
}

/* flash page 6 cpu 0x58F5 (offset 0x18F5) */
void p06_L_58F5(void) {
  cpu_push16(ix);
  ix = 0x0000;
  cpu_add_ix_sp();
  cpu_push_hl();
  cpu_push_hl();
  sp = (uint16_t)(sp - 1);
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 1)));
  /* ld (ix-0x03),a */
  /* ld (ix-0x02),a */
  p00_L_0FB5();
  p00_L_14C7();
  if (flag_z()) p00_L_128A();
  p00_L_1171();
  a = 0;
  flag_logic(a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_5920;
  a = mem_read8(0x89FA);
  lab_p06_L_5920: ;
  /* ld (ix-0x01),a */
  p06_L_5923();
  return;
}

/* flash page 6 cpu 0x5923 (offset 0x1923) */
void p06_L_5923(void) {
  goto lab_p06_L_5923;
  lab_p06_L_5920: ;
  /* ld (ix-0x01),a */
  lab_p06_L_5923: ;
  a = mem_read8(0x8478);
  a = a | a;
  flag_logic(a);
  if (flag_p()) goto lab_p06_L_592D;
  /* dec (ix-0x03) */
  lab_p06_L_592D: ;
  a = mem_read8(0x8479);
  /* bit 0,(ix-0x01) */
  if (flag_nz()) goto lab_p06_L_5954;
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p06_L_59DE;
  flag_cmp(a, 0x7D);
  if (flag_c()) goto lab_p06_L_5950;
  lab_p06_L_593F: ;
  mem_write8(0x8479, a);
  flag_cmp(a, 0x7F);
  if (flag_z()) goto lab_p06_L_59DE;
  p00_L_12CD();
  a = mem_read8(0x8479);
  a = (uint8_t)(a + 1);
  goto lab_p06_L_593F;
  lab_p06_L_5950: ;
  /* set 0,(ix-0x01) */
  lab_p06_L_5954: ;
  /* bit 1,(ix-0x01) */
  if (flag_z()) goto lab_p06_L_598B;
  a = mem_read8(0x8479);
  a = (uint8_t)(a + 1);
  l = a;
  h = 0x00;
  a = 0x03;
  p00_L_01AF();
  e = a;
  a = mem_read8(0x8479);
  a = (uint8_t)(a - e);
  h = a;
  a = e;
  a = (uint8_t)(a + 0x80);
  mem_write8(0x8479, a);
  goto lab_p06_L_5991;
  lab_p06_L_5974: ;
  /* ld a,(ix-0x02) */
  /* ld (ix-0x03),a */
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_5987;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0A)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_113A();
  lab_p06_L_5987: ;
  a = 0x01;
  goto lab_p06_L_5920;
  lab_p06_L_598B: ;
  h = a;
  a = 0x80;
  mem_write8(0x8479, a);
  lab_p06_L_5991: ;
  a = h;
  /* dec (ix-0x03) */
  a = (uint8_t)(a + 0x80);
  l = a;
  if (flag_c()) goto lab_p06_L_59A4;
  a = a ^ 0xFF;
  a = (uint8_t)(a + 1);
  /* dec (ix-0x03) */
  l = a;
  a = 0x1A;
  goto lab_p06_L_59A5;
  lab_p06_L_59A4: ;
  a = 0;
  flag_logic(a);
  lab_p06_L_59A5: ;
  /* ld (ix-0x04),a */
  a = 0;
  flag_logic(a);
  cpu_push_af();
  h = 0x00;
  lab_p06_L_59AC: ;
  p00_L_01AD();
  a = (uint8_t)(a + 0x30);
  cpu_push_af();
  /* dec (ix-0x03) */
  if (flag_m()) { p00_L_24BD(); return; }
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_59AC;
  /* ld a,(ix-0x03) */
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_59CA;
  cpu_pop_af();
  cpu_pop_af();
  a = 0xCE;
  cpu_push_af();
  /* inc (ix-0x03) */
  lab_p06_L_59CA: ;
  set_hl(0x84AF);
  mem_write8(hl(), 0x1B);
  set_hl((uint16_t)(hl() + 1));
  /* ld a,(ix-0x04) */
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_59D8;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_59D8: ;
  cpu_pop_af();
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_59D8;
  lab_p06_L_59DE: ;
  a = mem_read8(0x8479);
  a = (uint8_t)(a + 0x81);
  /* ld (ix-0x05),a */
  l = a;
  /* ld (ix-0x05),ixl */
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_5A03;
  flag_cmp(a, 0x0F);
  if (flag_nc()) goto lab_p06_L_5974;
  /* cp (ix-0x03) */
  if (flag_z()) goto lab_p06_L_5A6C;
  if (flag_nc()) goto lab_p06_L_5974;
  /* dec (ix-0x03) */
  l = 0x0E;
  goto lab_p06_L_5A28;
  lab_p06_L_5A03: ;
  flag_cmp(a, 0x0B);
  if (flag_nc()) goto lab_p06_L_5974;
  /* cp (ix-0x03) */
  if (flag_z()) goto lab_p06_L_5A1D;
  if (flag_nc()) goto lab_p06_L_5974;
  /* dec (ix-0x03) */
  a = 0x0A;
  /* cp (ix-0x03) */
  if (flag_nc()) goto lab_p06_L_5A1D;
  /* ld (ix-0x03),a */
  lab_p06_L_5A1D: ;
  a = mem_read8(0x97B0);
  a = a | a;
  flag_logic(a);
  if (flag_m()) goto lab_p06_L_5A37;
  /* add a,(ix-0x05) */
  l = a;
  lab_p06_L_5A28: ;
  /* ld a,(ix-0x03) */
  flag_cmp(a, l);
  if (flag_c()) goto lab_p06_L_5A37;
  /* ld (ix-0x03),ixl */
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_5A6C;
  lab_p06_L_5A37: ;
  a = 0x05;
  /* ld c,(ix-0x03) */
  /* sra c */
  if (flag_c()) goto lab_p06_L_5A42;
  a = 0x50;
  lab_p06_L_5A42: ;
  set_hl(0x847A);
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  b = c;
  b = (uint8_t)(b + 1);
  p00_L_1377();
  if (flag_nc()) goto lab_p06_L_5A6C;
  p00_L_11BB();
  a = mem_read8(0x84A5);
  flag_cmp(a, 0xE3);
  if (flag_z()) goto lab_p06_L_5A6C;
  a = (uint8_t)(a + 1);
  mem_write8(0x8479, a);
  set_hl(0x847A);
  p00_L_124D();
  /* ld a,(ix-0x02) */
  /* ld (ix-0x03),a */
  goto lab_p06_L_5923;
  lab_p06_L_5A6C: ;
  /* ld c,(ix-0x05) */
  set_hl(0x847A);
  set_de(0x848E);
  a = mem_read8(0x84A4);
  a = a | a;
  flag_logic(a);
  if (flag_p()) goto lab_p06_L_5A80;
  a = 0x1A;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  lab_p06_L_5A80: ;
  /* ld a,(ix-0x03) */
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_5A8B;
  p06_L_5AE7();
  goto lab_p06_L_5AAC;
  lab_p06_L_5A8B: ;
  p06_L_5AD6();
  a = mem_read8(hl());
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  a = a & 0x0F;
  flag_logic(a);
  p06_L_5AE7();
  /* dec (ix-0x03) */
  if (flag_z()) goto lab_p06_L_5AAC;
  p06_L_5AD6();
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a & 0x0F;
  flag_logic(a);
  p06_L_5AE7();
  /* dec (ix-0x03) */
  if (flag_nz()) goto lab_p06_L_5A8B;
  lab_p06_L_5AAC: ;
  set_de(mem_read16(0x84B7));
  /* bit 0,(ix-0x01) */
  if (flag_z()) goto lab_p06_L_5AC2;
  set_hl(0x84AF);
  lab_p06_L_5AB9: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_5AC2;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  goto lab_p06_L_5AB9;
  lab_p06_L_5AC2: ;
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  cpu_ex_de_hl();
  set_de(0x848E);
  cpu_sbc_hl_de();
  c = l;
  b = h;
  cpu_push_bc();
  p00_L_113A();
  cpu_pop_bc();
  sp = ix;
  ix = cpu_pop16();
  return;
}

/* flash page 6 cpu 0x59FE (offset 0x19FE) */
void p06_L_59FE(void) {
  /* ld iyl,0x0E */
  goto lab_p06_L_5A28;
  lab_p06_L_5A28: ;
  /* ld a,(ix-0x03) */
  flag_cmp(a, l);
  if (flag_c()) goto lab_p06_L_5A37;
  /* ld (ix-0x03),ixl */
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_5A6C;
  lab_p06_L_5A37: ;
  a = 0x05;
  /* ld c,(ix-0x03) */
  /* sra c */
  if (flag_c()) goto lab_p06_L_5A42;
  a = 0x50;
  lab_p06_L_5A42: ;
  set_hl(0x847A);
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  b = c;
  b = (uint8_t)(b + 1);
  p00_L_1377();
  if (flag_nc()) goto lab_p06_L_5A6C;
  p00_L_11BB();
  a = mem_read8(0x84A5);
  flag_cmp(a, 0xE3);
  if (flag_z()) goto lab_p06_L_5A6C;
  a = (uint8_t)(a + 1);
  mem_write8(0x8479, a);
  set_hl(0x847A);
  p00_L_124D();
  /* ld a,(ix-0x02) */
  /* ld (ix-0x03),a */
  p06_L_5923();
  return;
  lab_p06_L_5A6C: ;
  /* ld c,(ix-0x05) */
  set_hl(0x847A);
  set_de(0x848E);
  a = mem_read8(0x84A4);
  a = a | a;
  flag_logic(a);
  if (flag_p()) goto lab_p06_L_5A80;
  a = 0x1A;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  lab_p06_L_5A80: ;
  /* ld a,(ix-0x03) */
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_5A8B;
  p06_L_5AE7();
  goto lab_p06_L_5AAC;
  lab_p06_L_5A8B: ;
  p06_L_5AD6();
  a = mem_read8(hl());
  cpu_rra();
  cpu_rra();
  cpu_rra();
  cpu_rra();
  a = a & 0x0F;
  flag_logic(a);
  p06_L_5AE7();
  /* dec (ix-0x03) */
  if (flag_z()) goto lab_p06_L_5AAC;
  p06_L_5AD6();
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a & 0x0F;
  flag_logic(a);
  p06_L_5AE7();
  /* dec (ix-0x03) */
  if (flag_nz()) goto lab_p06_L_5A8B;
  lab_p06_L_5AAC: ;
  set_de(mem_read16(0x84B7));
  /* bit 0,(ix-0x01) */
  if (flag_z()) goto lab_p06_L_5AC2;
  set_hl(0x84AF);
  lab_p06_L_5AB9: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_5AC2;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  goto lab_p06_L_5AB9;
  lab_p06_L_5AC2: ;
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  cpu_ex_de_hl();
  set_de(0x848E);
  cpu_sbc_hl_de();
  c = l;
  b = h;
  cpu_push_bc();
  p00_L_113A();
  cpu_pop_bc();
  sp = ix;
  ix = cpu_pop16();
  return;
}

/* flash page 6 cpu 0x5AD6 (offset 0x1AD6) */
void p06_L_5AD6(void) {
  a = c;
  c = (uint8_t)(c - 1);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  a = 0x2E;
  mem_write8(de(), a);
  mem_write16(0x84B7, de());
  set_de((uint16_t)(de() + 1));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 1)));
  return;
}

/* flash page 6 cpu 0x5AE7 (offset 0x1AE7) */
void p06_L_5AE7(void) {
  flag_cmp(a, 0x0A);
  if (flag_nc()) goto lab_p06_L_5AED;
  a = (uint8_t)(a + 0x30);
  lab_p06_L_5AED: ;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_5B04;
  flag_cmp(a, 0x30);
  if (flag_nz()) goto lab_p06_L_5B04;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  a = mem_read8(0x97B0);
  flag_cmp(a, 0xFF);
  if (flag_z()) return;
  lab_p06_L_5B04: ;
  mem_write16(0x84B7, de());
  return;
}

/* flash page 6 cpu 0x5B09 (offset 0x1B09) */
void p06_L_5B09(void) {
  a = b;
  a = a & 0x1C;
  flag_logic(a);
  cpu_rrca();
  cpu_rrca();
  e = a;
  d = 0x00;
  set_hl(0x5B18);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 6 cpu 0x5B20 (offset 0x1B20) */
void p06_L_5B20(void) {
  p06_L_5B54();
  cpu_push16(ix);
  ix = 0x0000;
  cpu_add_ix_sp();
  sp = (uint16_t)(sp - 1);
  /* ld (ix-0x01),0x02 */
  lab_p06_L_5B30: ;
  cpu_push_bc();
  p00_rst20();
  cpu_push_hl();
  p06_L_55A8();
  cpu_pop_hl();
  c = (uint8_t)(c + 1);
  /* ld a,(ix-0x01) */
  a = (uint8_t)(a + c);
  /* ld (ix-0x01),a */
  cpu_pop_bc();
  flag_cmp(a, 0x11);
  if (flag_nc()) goto lab_p06_L_5B49;
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_5B30;
  lab_p06_L_5B49: ;
  /* ld c,(ix-0x01) */
  b = 0x00;
  c = (uint8_t)(c - 1);
  sp = ix;
  ix = cpu_pop16();
  return;
}

/* flash page 6 cpu 0x5B54 (offset 0x1B54) */
void p06_L_5B54(void) {
  set_hl(0x0000);
  mem_write16(0x9804, hl());
  p00_L_2429();
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x9806, bc());
  mem_write16(0x84DD, hl());
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) return;
  set_hl(0xFFFF);
  mem_write16(0x86E0, hl());
  p00_L_24ED();
  return;
}

/* flash page 6 cpu 0x5B75 (offset 0x1B75) */
void p06_L_5B75(void) {
  cpu_push16(ix);
  ix = 0x0000;
  cpu_add_ix_sp();
  sp = (uint16_t)(sp - 1);
  p06_L_5C22();
  set_hl(mem_read16(0x84DD));
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  /* ld (ix-0x01),a */
  lab_p06_L_5B8A: ;
  set_de(mem_read16(0x980A));
  b = c;
  lab_p06_L_5B8F: ;
  cpu_push_bc();
  cpu_push_de();
  p00_rst20();
  cpu_push_hl();
  p06_L_55A8();
  cpu_pop_hl();
  cpu_pop_de();
  a = mem_read8(de());
  flag_cmp(a, c);
  if (flag_nc()) goto lab_p06_L_5B9E;
  a = c;
  mem_write8(de(), a);
  lab_p06_L_5B9E: ;
  set_de((uint16_t)(de() + 1));
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_5B8F;
  /* dec (ix-0x01) */
  if (flag_nz()) goto lab_p06_L_5B8A;
  /* ld (ix-0x01),c */
  set_hl(0x0003);
  set_bc(mem_read16(0x980A));
  d = 0x00;
  lab_p06_L_5BB3: ;
  a = mem_read8(bc());
  set_bc((uint16_t)(bc() + 1));
  a = (uint8_t)(a + 1);
  e = a;
  set_hl((uint16_t)(hl() + de()));
  /* dec (ix-0x01) */
  if (flag_nz()) goto lab_p06_L_5BB3;
  c = l;
  b = h;
  sp = ix;
  ix = cpu_pop16();
  return;
}

/* flash page 6 cpu 0x5BC4 (offset 0x1BC4) */
void p06_L_5BC4(void) {
  a = mem_read8(0x89FE);
  a = a & 0xC0;
  flag_logic(a);
  mem_write8(0x89FE, a);
  return;
}

/* flash page 6 cpu 0x5BCD (offset 0x1BCD) */
void p06_L_5BCD(void) {
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  p00_L_32C1();
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_5C08;
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p06_L_5C08;
  set_hl(mem_read16(0x97AA));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x97AA, hl());
  cpu_ex_de_hl();
  set_hl(0x0000);
  p00_L_192A();
  if (flag_p()) goto lab_p06_L_5C08;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 2)));
  set_hl(mem_read16(0x97A5));
  h = 0x0F;
  mem_write16(0x844B, hl());
  a = 0x1E;
  p00_L_3C6F();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  lab_p06_L_5C08: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 6 cpu 0x5C0C (offset 0x1C0C) */
void p06_L_5C0C(void) {
  a = 0x10;
  a = (uint8_t)(a - c);
  if (flag_z()) return;
  b = a;
  a = 0x20;
  lab_p06_L_5C13: ;
  p00_L_3F9F();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_5C13;
  return;
}

/* flash page 6 cpu 0x5C19 (offset 0x1C19) */
void p06_L_5C19(void) {
  set_hl(0xFFF0);
  set_hl((uint16_t)(hl() + bc()));
  if (flag_c()) return;
  mem_write16(0x97A8, hl());
  return;
}

/* flash page 6 cpu 0x5C22 (offset 0x1C22) */
void p06_L_5C22(void) {
  set_hl(mem_read16(0x84DD));
  l = mem_read8(hl());
  cpu_push_hl();
  h = 0x00;
  set_de(0x2501);
  mem_write16(0x8479, de());
  p00_L_1C8F();
  mem_write16(0x9808, hl());
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  mem_write16(0x980A, de());
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 7)));
  cpu_pop_bc();
  b = c;
  a = 0;
  flag_logic(a);
  lab_p06_L_5C43: ;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_5C43;
  return;
}

/* flash page 6 cpu 0x5C48 (offset 0x1C48) */
void p06_L_5C48(void) {
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  return;
}

/* flash page 6 cpu 0x5C4D (offset 0x1C4D) */
void p06_L_5C4D(void) {
  a = 0x14;
  p06_L_55AA();
  p06_L_5C52();
  return;
}

/* flash page 6 cpu 0x5C52 (offset 0x1C52) */
void p06_L_5C52(void) {
  set_hl(0x848E);
  set_de(0x97B1);
  p00_L_25E0();
  return;
}

/* flash page 6 cpu 0x5C5B (offset 0x1C5B) */
void p06_L_5C5B(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p06_L_5C69;
  set_hl(mem_read16(0x97A5));
  a = 0x1E;
  p06_L_5C75();
  lab_p06_L_5C69: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 3)) == 0);
  if (flag_z()) return;
  a = mem_read8(0x97A6);
  a = (uint8_t)(a - 1);
  l = a;
  a = 0x1F;
  p06_L_5C75();
  return;
}

/* flash page 6 cpu 0x5C75 (offset 0x1C75) */
void p06_L_5C75(void) {
  h = 0x0F;
  mem_write16(0x844B, hl());
  p00_L_3C6F();
  return;
}

/* flash page 6 cpu 0x5C7E (offset 0x1C7E) */
void p06_L_5C7E(void) {
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) | (1u << 3)));
  p00_L_3CD5();
  p00_L_3CC3();
  mem_write16(0x97A8, hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x97A7, a);
  a = mem_read8(0x844B);
  a = (uint8_t)(a - 1);
  p06_L_5C93();
  return;
}

/* flash page 6 cpu 0x5C93 (offset 0x1C93) */
void p06_L_5C93(void) {
  e = a;
  d = h;
  p00_L_17CE();
  if (flag_z()) goto lab_p06_L_5C9C;
  l = 0x04;
  lab_p06_L_5C9C: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  mem_write16(0x97AA, hl());
  return;
}

/* flash page 6 cpu 0x5CA3 (offset 0x1CA3) */
void p06_L_5CA3(void) {
  p00_L_2429();
  cpu_ex_de_hl();
  mem_write16(0x84DD, hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  a = mem_read8(0x97A6);
  set_hl(0x97A5);
  /* sub (hl) */
  a = (uint8_t)(a - 1);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p06_L_5CB8;
  b = a;
  lab_p06_L_5CB8: ;
  c = b;
  lab_p06_L_5CB9: ;
  p00_L_3CD5();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_5CB9;
  p00_L_3CC3();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) | (1u << 3)));
  mem_write16(0x97A8, hl());
  a = mem_read8(0x844B);
  a = (uint8_t)(a - c);
  p06_L_5C93();
  return;
}

/* flash page 6 cpu 0x5CD6 (offset 0x1CD6) */
void p06_L_5CD6(void) {
  set_de(mem_read16(0x980A));
  /* ld (ix-0x02),e */
  /* ld (ix-0x01),d */
  return;
}

/* flash page 6 cpu 0x5CF0 (offset 0x1CF0) */
void p06_L_5CF0(void) {
  /* ld ixl,(ix-0x02) */
  /* ld ixh,(ix-0x01) */
  c = mem_read8(hl());
  b = 0x00;
  set_hl((uint16_t)(hl() + 1));
  /* ld (ix-0x02),ixl */
  /* ld (ix-0x01),ixh */
  return;
}

/* flash page 6 cpu 0x5D0F (offset 0x1D0F) */
void p06_L_5D0F(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_17FA();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 3)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 7)) == 0);
  if (flag_z()) return;
  set_hl(mem_read16(0x9808));
  set_de(mem_read16(0x980A));
  set_de((uint16_t)(de() - 1));
  set_de((uint16_t)(de() - 1));
  p00_L_1F5E();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 7)));
  return;
}

/* flash page 6 cpu 0x5D34 (offset 0x1D34) */
void p06_L_5D34(void) {
  p06_L_44C8();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 0)));
  p06_L_558C();
  set_hl(mem_read16(0x96F6));
  mem_write16(0x86D9, hl());
  a = mem_read8(0x89FA);
  mem_write8(0x89FB, a);
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_5D56;
  p06_L_5F45();
  goto lab_p06_L_5D60;
  lab_p06_L_5D56: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p06_L_5D5F;
  p06_L_5DDF();
  goto lab_p06_L_5D60;
  lab_p06_L_5D5F: ;
  /* scf */
  lab_p06_L_5D60: ;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 0)));
  if (flag_c()) return;
  set_hl(mem_read16(0x86D9));
  mem_write16(0x96F6, hl());
  return;
}

/* flash page 6 cpu 0x5D6C (offset 0x1D6C) */
void p06_L_5D6C(void) {
  p06_L_44C8();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 0)));
  set_hl(mem_read16(0x96F6));
  mem_write16(0x86D9, hl());
  a = mem_read8(0x89FA);
  mem_write8(0x89FB, a);
  a = 0x08;
  p06_L_43BE();
  if (flag_c()) return;
  p00_L_3723();
  set_de(0x8478);
  p00_L_1183();
  p06_L_5F45();
  p00_L_3723();
  p00_L_3AC5();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p06_L_5DAE;
  a = 0x2B;
  p06_L_43BE();
  if (flag_c()) return;
  p00_L_3723();
  cpu_ex_de_hl();
  set_de(0x8478);
  p00_L_1183();
  p06_L_5F45();
  lab_p06_L_5DAE: ;
  a = 0x09;
  p06_L_43BE();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 0)));
  if (flag_c()) return;
  set_hl(mem_read16(0x86D9));
  mem_write16(0x96F6, hl());
  return;
}

/* flash page 6 cpu 0x5DBF (offset 0x1DBF) */
void p06_L_5DBF(void) {
  p00_L_2429();
  p06_L_5DC2();
  return;
}

/* flash page 6 cpu 0x5DC2 (offset 0x1DC2) */
void p06_L_5DC2(void) {
  cpu_ex_de_hl();
  p06_L_5DC3();
  return;
}

/* flash page 6 cpu 0x5DC3 (offset 0x1DC3) */
void p06_L_5DC3(void) {
  cpu_ex_de_hl();
  p06_L_44C8();
  cpu_ex_de_hl();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 0)));
  p06_L_5DF9();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 0)));
  if (flag_c()) return;
  set_hl(mem_read16(0x86D9));
  mem_write16(0x96F6, hl());
  return;
}

/* flash page 6 cpu 0x5DDB (offset 0x1DDB) */
void p06_L_5DDB(void) {
  a = 0x05;
  p06_L_5DC3();
  return;
}

/* flash page 6 cpu 0x5DDF (offset 0x1DDF) */
void p06_L_5DDF(void) {
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) | (1u << 7)));
  a = 0x2B;
  p06_L_57FD();
  mem_write8((uint16_t)(iy + 0x1B), (uint8_t)(mem_read8((uint16_t)(iy + 0x1B)) & ~(1u << 7)));
  set_hl(0x97B0);
  p06_L_5F57();
  set_bc(0x97B1);
  p06_L_43DA();
  return;
}

/* flash page 6 cpu 0x5DF9 (offset 0x1DF9) */
void p06_L_5DF9(void) {
  cpu_push_af();
  set_de(mem_read16(0x96F6));
  mem_write16(0x86D9, de());
  a = mem_read8(0x89FA);
  mem_write8(0x89FB, a);
  cpu_pop_af();
  mem_write16(0x84DD, hl());
  a = a & 0x1F;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_5E14;
  p00_rst20();
  p06_L_5F45();
  return;
  lab_p06_L_5E14: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p06_L_5E1E;
  p00_rst20();
  p00_L_11F8();
  p06_L_5DDF();
  return;
  lab_p06_L_5E1E: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p06_L_5E4E;
  a = 0x08;
  p06_L_43BE();
  if (flag_c()) return;
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_5E48;
  lab_p06_L_5E30: ;
  cpu_push_bc();
  p00_rst20();
  cpu_push_hl();
  p06_L_5F45();
  a = 0x2B;
  p06_L_43BE();
  cpu_pop_hl();
  cpu_pop_bc();
  if (flag_c()) return;
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_5E30;
  a = 0x09;
  p06_L_5F93();
  return;
  lab_p06_L_5E48: ;
  a = 0x09;
  p06_L_43BE();
  return;
  lab_p06_L_5E4E: ;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p06_L_5E81;
  a = 0x08;
  p06_L_43BE();
  if (flag_c()) return;
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_5E7B;
  lab_p06_L_5E60: ;
  cpu_push_bc();
  p00_rst20();
  p00_L_11F8();
  cpu_push_hl();
  p06_L_5DDF();
  a = 0x2B;
  p06_L_43BE();
  cpu_pop_hl();
  cpu_pop_bc();
  if (flag_c()) return;
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p06_L_5E60;
  a = 0x09;
  p06_L_5F93();
  return;
  lab_p06_L_5E7B: ;
  a = 0x09;
  p06_L_43BE();
  return;
  lab_p06_L_5E81: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p06_L_5EC2;
  p06_L_5F9C();
  if (flag_c()) return;
  cpu_push16(ix);
  ix = 0x0000;
  cpu_add_ix_sp();
  sp = (uint16_t)(sp - 1);
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  /* ld (ix-0x01),c */
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_5E99: ;
  p06_L_5F9C();
  lab_p06_L_5E9C: ;
  cpu_push_bc();
  p00_rst20();
  cpu_push_hl();
  p06_L_5F45();
  a = 0x2B;
  p06_L_43BE();
  cpu_pop_hl();
  cpu_pop_bc();
  if (flag_c()) goto lab_p06_L_5EBD;
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p06_L_5E9C;
  a = 0x07;
  p06_L_5F93();
  /* ld c,(ix-0x01) */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_5E99;
  a = 0x07;
  p06_L_43BE();
  lab_p06_L_5EBD: ;
  sp = ix;
  ix = cpu_pop16();
  return;
  lab_p06_L_5EC2: ;
  p00_L_1857();
  if (flag_z()) goto lab_p06_L_5ECC;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p06_L_5F1D;
  lab_p06_L_5ECC: ;
  set_hl(mem_read16(0x96F4));
  cpu_push_hl();
  set_hl(mem_read16(0x96FA));
  cpu_push_hl();
  set_hl(mem_read16(0x96F6));
  cpu_push_hl();
  mem_write16(0x96F4, hl());
  set_hl(mem_read16(0x96F8));
  cpu_push_hl();
  mem_write16(0x96FA, hl());
  set_hl(mem_read16(0x84DD));
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_5EE9: ;
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_5F02;
  cpu_push_bc();
  p06_L_4467();
  if (flag_nc()) goto lab_p06_L_5EF6;
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  cpu_push_bc();
  lab_p06_L_5EF6: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p06_L_43A1();
  cpu_pop_hl();
  cpu_pop_bc();
  if (flag_z()) goto lab_p06_L_5F1A;
  set_bc((uint16_t)(bc() - 1));
  goto lab_p06_L_5EE9;
  lab_p06_L_5F02: ;
  set_hl(mem_read16(0x96F6));
  mem_write16(0x86D9, hl());
  a = a | a;
  flag_logic(a);
  lab_p06_L_5F09: ;
  cpu_pop_hl();
  mem_write16(0x96F8, hl());
  cpu_pop_hl();
  mem_write16(0x96F6, hl());
  cpu_pop_hl();
  mem_write16(0x96FA, hl());
  cpu_pop_hl();
  mem_write16(0x96F4, hl());
  return;
  lab_p06_L_5F1A: ;
  /* scf */
  goto lab_p06_L_5F09;
  lab_p06_L_5F1D: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p06_L_5F44;
  a = 0x2A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_z()) p06_L_43BE();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_5F2E: ;
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_5F3B;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p06_L_43BE();
  if (flag_c()) return;
  set_bc((uint16_t)(bc() - 1));
  goto lab_p06_L_5F2E;
  lab_p06_L_5F3B: ;
  a = 0x2A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_z()) p06_L_43BE();
  lab_p06_L_5F44: ;
  return;
}

/* flash page 6 cpu 0x5F45 (offset 0x1F45) */
void p06_L_5F45(void) {
  a = 0x14;
  p06_L_55AA();
  p06_L_5F54();
  set_bc(0x848E);
  p06_L_43DA();
  return;
}

/* flash page 6 cpu 0x5F54 (offset 0x1F54) */
void p06_L_5F54(void) {
  set_hl(0x848D);
  p06_L_5F57();
  return;
}

/* flash page 6 cpu 0x5F57 (offset 0x1F57) */
void p06_L_5F57(void) {
  lab_p06_L_5F57: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  flag_cmp(a, 0x2E);
  if (flag_nz()) goto lab_p06_L_5F63;
  mem_write8(hl(), 0x3A);
  goto lab_p06_L_5F57;
  lab_p06_L_5F63: ;
  flag_cmp(a, 0x1B);
  if (flag_nz()) goto lab_p06_L_5F6B;
  mem_write8(hl(), 0x3B);
  goto lab_p06_L_5F57;
  lab_p06_L_5F6B: ;
  flag_cmp(a, 0x20);
  if (flag_nz()) goto lab_p06_L_5F73;
  mem_write8(hl(), 0x29);
  goto lab_p06_L_5F57;
  lab_p06_L_5F73: ;
  flag_cmp(a, 0x1A);
  if (flag_nz()) goto lab_p06_L_5F7B;
  mem_write8(hl(), 0xB0);
  goto lab_p06_L_5F57;
  lab_p06_L_5F7B: ;
  flag_cmp(a, 0x2B);
  if (flag_nz()) goto lab_p06_L_5F83;
  mem_write8(hl(), 0x70);
  goto lab_p06_L_5F57;
  lab_p06_L_5F83: ;
  flag_cmp(a, 0x2D);
  if (flag_nz()) goto lab_p06_L_5F8B;
  mem_write8(hl(), 0x71);
  goto lab_p06_L_5F57;
  lab_p06_L_5F8B: ;
  flag_cmp(a, 0xD7);
  if (flag_nz()) goto lab_p06_L_5F57;
  mem_write8(hl(), 0x2C);
  goto lab_p06_L_5F57;
}

/* flash page 6 cpu 0x5F93 (offset 0x1F93) */
void p06_L_5F93(void) {
  cpu_push_hl();
  set_hl(mem_read16(0x86D9));
  set_hl((uint16_t)(hl() - 1));
  mem_write8(hl(), a);
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 6 cpu 0x5F9C (offset 0x1F9C) */
void p06_L_5F9C(void) {
  a = 0x06;
  p06_L_43BE();
  return;
}

/* flash page 6 cpu 0x5FA2 (offset 0x1FA2) */
void p06_L_5FA2(void) {
  a = 0x20;
  p00_L_3CAB();
  return;
}

/* flash page 6 cpu 0x5FA8 (offset 0x1FA8) */
void p06_L_5FA8(void) {
  set_hl(0x8BEA);
  p00_rst20();
  p00_L_11F8();
  set_hl(0x0028);
  mem_write16(0x97B1, hl());
  a = 0x06;
  p06_L_55AA();
  p06_L_5C52();
  a = 0x2C;
  p06_L_5C48();
  p00_L_14B0();
  a = 0x06;
  p06_L_55AA();
  p00_L_14B0();
  p06_L_5C52();
  a = 0x29;
  p06_L_5C48();
  return;
}

/* flash page 6 cpu 0x5FD5 (offset 0x1FD5) */
void p06_L_5FD5(void) {
  a = 0x01;
  p06_L_6043();
  a = mem_read8(0x970F);
  a = (uint8_t)(a + b);
  p06_L_6055();
  p06_L_600A();
  cpu_push_bc();
  a = mem_read8(0x970F);
  a = (uint8_t)(a + b);
  p00_L_3243();
  p00_rst10();
  if (flag_c()) goto lab_p06_L_6008;
  p00_L_1F55();
  if (flag_nz()) goto lab_p06_L_6008;
  p00_L_1EF4();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_6008;
  cpu_pop_bc();
  cpu_push_bc();
  p06_L_6041();
  a = 0xE0;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  p00_L_3D47();
  lab_p06_L_6008: ;
  cpu_pop_bc();
  return;
}

/* flash page 6 cpu 0x600A (offset 0x200A) */
void p06_L_600A(void) {
  cpu_push16(ix);
  a = mem_read8(hl());
  flag_cmp(a, 0x06);
  if (flag_nc()) goto lab_p06_L_601B;
  a = (uint8_t)(a + 0x81);
  cpu_push_bc();
  b = a;
  p00_L_3231();
  cpu_pop_bc();
  goto lab_p06_L_603E;
  lab_p06_L_601B: ;
  flag_cmp(a, 0x71);
  if (flag_nz()) goto lab_p06_L_602C;
  set_hl(0x263F);
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  p00_L_3D4D();
  goto lab_p06_L_603E;
  lab_p06_L_602C: ;
  set_de(0x84C7);
  cpu_push_bc();
  set_bc(0x0005);
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_bc();
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  set_hl(0x84C7);
  p00_L_3D4D();
  lab_p06_L_603E: ;
  ix = cpu_pop16();
  return;
}

/* flash page 6 cpu 0x6041 (offset 0x2041) */
void p06_L_6041(void) {
  a = 0x16;
  p06_L_6043();
  return;
}

/* flash page 6 cpu 0x6043 (offset 0x2043) */
void p06_L_6043(void) {
  flag_set_z((b & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_604B;
  a = (uint8_t)(a + 0x20);
  goto lab_p06_L_6051;
  lab_p06_L_604B: ;
  flag_set_z((b & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_6051;
  a = (uint8_t)(a + 0x3E);
  lab_p06_L_6051: ;
  mem_write8(0x86D7, a);
  return;
}

/* flash page 6 cpu 0x6055 (offset 0x2055) */
void p06_L_6055(void) {
  set_hl(0x9711);
  cpu_push_de();
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_de();
  return;
}

/* flash page 6 cpu 0x6063 (offset 0x2063) */
void p06_L_6063(void) {
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 0)));
  p00_L_17FA();
  a = 0x54;
  mem_write8(0x859A, a);
  set_hl(0x61A8);
  p00_L_07C1();
  p06_L_6079();
  return;
}

/* flash page 6 cpu 0x6079 (offset 0x2079) */
void p06_L_6079(void) {
  a = mem_read8(0x8444);
  flag_cmp(a, 0x54);
  if (flag_nz()) goto lab_p06_L_6084;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 0)));
  lab_p06_L_6084: ;
  p06_L_65EB();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 1)));
  p00_L_3E8B();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_681C;
  p06_L_6802();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 2)));
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  p06_L_618B();
  p00_rst10();
  if (flag_c()) goto lab_p06_L_60B5;
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p06_L_60C4;
  p00_L_1F58();
  lab_p06_L_60B5: ;
  set_hl(0x24F9);
  p00_L_25A2();
  set_hl(0x0000);
  p00_L_1CA8();
  p00_L_25C8();
  lab_p06_L_60C4: ;
  p06_L_483D();
  p00_L_1916();
  if (flag_nz()) goto lab_p06_L_60D8;
  p06_L_618B();
  p06_L_4844();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 0)));
  p06_L_6126();
  return;
  lab_p06_L_60D8: ;
  p06_L_7235();
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 6)));
  p06_L_618B();
  p06_L_4844();
  cpu_pop_af();
  if (flag_nc()) goto lab_p06_L_60F0;
  a = mem_read8(0x844C);
  flag_cmp(a, 0x0F);
  if (flag_c()) goto lab_p06_L_60FA;
  lab_p06_L_60F0: ;
  a = 0x0D;
  mem_write8(0x844C, a);
  a = 0xCE;
  p00_L_3F9F();
  lab_p06_L_60FA: ;
  set_hl(0x2612);
  p00_L_3C87();
  p00_L_3CD5();
  p06_L_6822();
  return;
  lab_p06_L_681C: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  goto lab_p06_L_6832;
  lab_p06_L_6832: ;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 2)));
  p06_L_65AF();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 2)));
  p06_L_68D0();
  p06_L_483D();
  set_hl(mem_read16(0x9708));
  a = 0x03;
  p06_L_5DC3();
  if (flag_c()) { p00_L_24F9(); return; }
  p00_L_3D2F();
  p00_L_3CC9();
  p06_L_449C();
  p00_L_3CBD();
  p06_L_4844();
  a = 0x01;
  mem_write8(0x97A5, a);
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 2)));
  p06_L_6539();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_687F;
  p06_L_68DC();
  a = mem_read8(0x97A2);
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p06_L_645A(); return; }
  p00_L_37AD();
  p06_L_6352();
  return;
  lab_p06_L_687F: ;
  a = 0x01;
  mem_write8(0x97A5, a);
  p06_L_6539();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 0)));
  a = 0x01;
  mem_write8(0x844B, a);
  p00_L_37AD();
  p06_L_652D();
  if (flag_z()) p06_L_6613();
  mem_write16(0x9706, hl());
  p06_L_6464();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 6)));
  return;
}

/* flash page 6 cpu 0x6126 (offset 0x2126) */
void p06_L_6126(void) {
  set_hl(0x6AA0);
  p00_rst20();
  p00_L_1185();
  set_hl(0x8478);
  a = 0x31;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3717();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 2)));
  p00_L_3CD5();
  p06_L_6192();
  p06_L_618B();
  p00_rst10();
  mem_write16(0x9706, hl());
  p06_L_483D();
  p00_L_37AD();
  a = (uint8_t)(a + 0x02);
  mem_write8(0x97A7, a);
  mem_write8(0x844C, a);
  p00_L_37A7();
  p00_L_3CC9();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p06_L_7200();
  p00_L_3D29();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 7)) == 0);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 7)));
  p06_L_4635();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p06_L_7200();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x618B (offset 0x218B) */
void p06_L_618B(void) {
  set_hl(0x003E);
  p00_L_1671();
  return;
}

/* flash page 6 cpu 0x6192 (offset 0x2192) */
void p06_L_6192(void) {
  set_hl(0x6AB0);
  p06_L_6A94();
  a = 0x19;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3C87();
  return;
}

/* flash page 6 cpu 0x622D (offset 0x222D) */
void p06_L_622D(void) {
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p06_L_7200();
  p00_L_3D29();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  p06_L_6250();
  return;
}

/* flash page 6 cpu 0x6250 (offset 0x2250) */
void p06_L_6250(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 1)) == 0);
  if (flag_z()) return;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 1)));
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x0001);
  a = mem_read8(0x859A);
  flag_cmp(a, 0x53);
  if (flag_nz()) goto lab_p06_L_6269;
  set_hl((uint16_t)(hl() - 1));
  lab_p06_L_6269: ;
  mem_write16(0x844B, hl());
  a = mem_read8(0x97A6);
  a = (uint8_t)(a - 1);
  b = a;
  lab_p06_L_6271: ;
  p00_L_3D35();
  a = mem_read8(hl());
  flag_cmp(a, 0xD0);
  if (flag_z()) goto lab_p06_L_6289;
  flag_cmp(a, 0xEF);
  if (flag_z()) goto lab_p06_L_6285;
  flag_cmp(a, 0xF0);
  if (flag_nz()) goto lab_p06_L_628E;
  a = 0x1F;
  goto lab_p06_L_628B;
  lab_p06_L_6285: ;
  a = 0x1E;
  goto lab_p06_L_628B;
  lab_p06_L_6289: ;
  a = 0x20;
  lab_p06_L_628B: ;
  p00_L_3C6F();
  lab_p06_L_628E: ;
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_6271;
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  cpu_pop_af();
  return;
}

/* flash page 6 cpu 0x6352 (offset 0x2352) */
void p06_L_6352(void) {
  p06_L_693D();
  set_hl(mem_read16(0x9706));
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p06_L_637C;
  set_hl(0x9176);
  p00_rst20();
  set_hl(0x917F);
  p00_L_0BEC();
  p00_L_0D16();
  set_de(mem_read16(0x9708));
  set_hl(0x8478);
  p00_L_1183();
  set_hl(mem_read16(0x9706));
  a = 0x00;
  mem_write8(hl(), a);
  lab_p06_L_637C: ;
  set_hl(mem_read16(0x9708));
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p06_L_639A;
  flag_cmp(a, 0x01);
  if (flag_nz()) { p00_L_24DD(); return; }
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  set_hl(0x0002);
  p00_L_192A();
  if (flag_nz()) { p00_L_24ED(); return; }
  cpu_pop_hl();
  p06_L_6558();
  lab_p06_L_639A: ;
  p06_L_6558();
  p06_L_618B();
  p00_L_2222();
  p00_L_37D1();
  p00_L_241E();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  p00_L_2222();
  a = 0;
  flag_logic(a);
  mem_write8(0x86DD, a);
  p06_L_659C();
  p06_L_65D9();
  p00_L_2222();
  set_hl(mem_read16(0x9708));
  set_de(0x84AF);
  p00_L_1183();
  set_hl(0x641A);
  p00_L_25A2();
  p00_L_398D();
  p00_L_15FB();
  p00_L_2222();
  set_hl(0x9308);
  p00_rst20();
  p00_L_38DF();
  p00_L_36DB();
  p06_L_680C();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 1)));
  p00_L_25C8();
  p06_L_65AF();
  p06_L_65B6();
  p06_L_6772();
  p06_L_64CA();
  p06_L_645A();
  return;
}

/* flash page 6 cpu 0x645A (offset 0x245A) */
void p06_L_645A(void) {
  p00_L_37AD();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 6)));
  set_hl(mem_read16(0x9706));
  p06_L_6464();
  return;
}

/* flash page 6 cpu 0x6464 (offset 0x2464) */
void p06_L_6464(void) {
  a = mem_read8(hl());
  cpu_push_af();
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p00_L_254D(); return; }
  mem_write16(0x9708, de());
  cpu_push_de();
  p00_L_3759();
  p06_L_4826();
  cpu_pop_hl();
  cpu_pop_af();
  p06_L_5DC3();
  p06_L_449C();
  return;
}

/* flash page 6 cpu 0x6486 (offset 0x2486) */
void p06_L_6486(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 6)));
  p00_L_03A0();
  set_hl(mem_read16(0x9706));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  p06_L_64A3();
  set_hl(mem_read16(0x9706));
  p06_L_65CB();
  if (flag_z()) goto lab_p06_L_649F;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  lab_p06_L_649F: ;
  p00_L_37CB();
  return;
}

/* flash page 6 cpu 0x64A3 (offset 0x24A3) */
void p06_L_64A3(void) {
  p06_L_4844();
  p00_L_166E();
  p00_L_36D5();
  flag_set_z((mem_read8((uint16_t)(iy + 0x07)) & (1u << 0)) == 0);
  if (flag_z()) return;
  p00_L_2222();
  p00_L_1295();
  p00_L_37D1();
  p00_L_38DF();
  p00_L_36DB();
  set_hl(mem_read16(0x9706));
  p06_L_65CB();
  if (flag_nz()) return;
  p06_L_6910();
  return;
}

/* flash page 6 cpu 0x64CA (offset 0x24CA) */
void p06_L_64CA(void) {
  p00_L_37A7();
  p00_L_37D1();
  set_hl(mem_read16(0x9706));
  p06_L_66C4();
  return;
}

/* flash page 6 cpu 0x64D6 (offset 0x24D6) */
void p06_L_64D6(void) {
  cpu_push_de();
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  p00_L_2407();
  set_de(0x0003);
  p00_L_17B3();
  if (flag_z()) goto lab_p06_L_64ED;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p06_L_64ED;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p06_L_64FA;
  lab_p06_L_64ED: ;
  a = mem_read8(hl());
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p06_L_64FA;
  flag_cmp(a, 0x3A);
  if (flag_z()) goto lab_p06_L_64FA;
  e = a;
  e = (uint8_t)(e + 1);
  d = 0x00;
  lab_p06_L_64FA: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  set_de(mem_read16(0x982E));
  p00_L_192A();
  cpu_pop_de();
  return;
}

/* flash page 6 cpu 0x6506 (offset 0x2506) */
void p06_L_6506(void) {
  lab_p06_L_6506: ;
  p06_L_64D6();
  if (flag_z()) return;
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p06_L_6506;
  return;
}

/* flash page 6 cpu 0x650F (offset 0x250F) */
void p06_L_650F(void) {
  cpu_push_bc();
  cpu_push_de();
  set_bc(0x0000);
  cpu_ex_de_hl();
  p06_L_652D();
  lab_p06_L_6518: ;
  p00_L_192A();
  if (flag_c()) goto lab_p06_L_6526;
  if (flag_z()) goto lab_p06_L_6526;
  c = l;
  b = h;
  p06_L_6506();
  if (flag_nz()) goto lab_p06_L_6518;
  lab_p06_L_6526: ;
  a = c;
  a = a | b;
  flag_logic(a);
  l = c;
  h = b;
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 6 cpu 0x652D (offset 0x252D) */
void p06_L_652D(void) {
  set_hl(0xFE66);
  lab_p06_L_6530: ;
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_nz()) return;
  p06_L_64D6();
  if (flag_nz()) goto lab_p06_L_6530;
  return;
}

/* flash page 6 cpu 0x6539 (offset 0x2539) */
void p06_L_6539(void) {
  p00_L_3D2F();
  set_hl(0xFE66);
  lab_p06_L_653F: ;
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p06_L_654D;
  p06_L_661F();
  p00_L_3CD5();
  p00_L_3CCF();
  if (flag_nc()) return;
  lab_p06_L_654D: ;
  p06_L_64D6();
  if (flag_nz()) goto lab_p06_L_653F;
  p06_L_6618();
  p06_L_6772();
  return;
}

/* flash page 6 cpu 0x6558 (offset 0x2558) */
void p06_L_6558(void) {
  cpu_push_hl();
  p00_rst20();
  set_hl(0x9176);
  p00_L_1073();
  if (flag_c()) { p00_L_2525(); return; }
  set_hl(0x917F);
  p00_rst20();
  cpu_pop_hl();
  p00_L_1073();
  cpu_push_hl();
  if (flag_c()) { p00_L_2525(); return; }
  cpu_pop_hl();
  return;
}

/* flash page 6 cpu 0x6571 (offset 0x2571) */
void p06_L_6571(void) {
  set_hl(mem_read16(0x9706));
  p06_L_65CB();
  if (flag_nz()) goto lab_p06_L_657C;
  set_hl(mem_read16(0x982E));
  lab_p06_L_657C: ;
  p06_L_650F();
  if (flag_z()) return;
  p06_L_65CB();
  if (flag_z()) goto lab_p06_L_657C;
  mem_write16(0x9706, hl());
  return;
}

/* flash page 6 cpu 0x6589 (offset 0x2589) */
void p06_L_6589(void) {
  set_hl(mem_read16(0x9706));
  p06_L_65CB();
  if (flag_z()) return;
  p06_L_6506();
  if (flag_z()) p06_L_6613();
  mem_write16(0x9706, hl());
  a = 0;
  flag_logic(a);
  a = (uint8_t)(a + 1);
  return;
}

/* flash page 6 cpu 0x659C (offset 0x259C) */
void p06_L_659C(void) {
  p00_L_2222();
  p00_L_37D1();
  set_hl(0x8478);
  set_de(0x9308);
  p00_L_1183();
  p00_L_2176();
  return;
}

/* flash page 6 cpu 0x65AF (offset 0x25AF) */
void p06_L_65AF(void) {
  p06_L_618B();
  p00_L_2FF7();
  return;
}

/* flash page 6 cpu 0x65B6 (offset 0x25B6) */
void p06_L_65B6(void) {
  set_hl(0x9308);
  p00_rst20();
  p00_L_241E();
  if (flag_c()) p06_L_6613();
  mem_write16(0x9706, hl());
  mem_write16(0x918C, hl());
  mem_write16(0x9708, de());
  return;
}

/* flash page 6 cpu 0x65CB (offset 0x25CB) */
void p06_L_65CB(void) {
  cpu_push_hl();
  ix = cpu_pop16();
  /* ld a,(ix-0x06) */
  flag_cmp(a, 0x3A);
  if (flag_nz()) return;
  /* ld a,(ix-0x07) */
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 6 cpu 0x65D9 (offset 0x25D9) */
void p06_L_65D9(void) {
  a = 0x01;
  mem_write8(0x8478, a);
  l = 0x3A;
  h = 0x00;
  mem_write16(0x8479, hl());
  a = 0x00;
  mem_write8(0x847B, a);
  return;
}

/* flash page 6 cpu 0x65EB (offset 0x25EB) */
void p06_L_65EB(void) {
  p06_L_6613();
  if (flag_nc()) return;
  p06_L_65D9();
  set_hl(0x24F9);
  p00_L_25A2();
  set_hl(0x0002);
  p00_L_1C46();
  p00_L_25C8();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_hl(0x9176);
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 0)) == 0);
  set_hl(0x694E);
  p00_L_1183();
  p00_L_1183();
  return;
}

/* flash page 6 cpu 0x6605 (offset 0x2605) */
void p06_L_6605(void) {
  a = (uint8_t)(a - c);
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 0)) == 0);
  set_hl(0x694E);
  p00_L_1183();
  p00_L_1183();
  return;
}

/* flash page 6 cpu 0x6613 (offset 0x2613) */
void p06_L_6613(void) {
  p06_L_65D9();
  p00_rst10();
  return;
}

/* flash page 6 cpu 0x6618 (offset 0x2618) */
void p06_L_6618(void) {
  p06_L_6613();
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  p06_L_661F();
  return;
}

/* flash page 6 cpu 0x661F (offset 0x261F) */
void p06_L_661F(void) {
  cpu_push_de();
  cpu_push_hl();
  a = mem_read8(0x844B);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p06_L_663B;
  cpu_ex_de_hl();
  p06_L_652D();
  p00_L_192A();
  cpu_ex_de_hl();
  if (flag_z()) goto lab_p06_L_665C;
  p06_L_65CB();
  if (flag_z()) goto lab_p06_L_665C;
  a = 0x1E;
  goto lab_p06_L_665E;
  lab_p06_L_663B: ;
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p06_L_665C;
  p06_L_65CB();
  if (flag_nz()) goto lab_p06_L_6653;
  cpu_push_hl();
  cpu_push_de();
  p00_L_1675();
  p00_rst10();
  p06_L_65D9();
  cpu_pop_de();
  cpu_pop_hl();
  if (flag_c()) goto lab_p06_L_665C;
  goto lab_p06_L_6658;
  lab_p06_L_6653: ;
  p06_L_6763();
  if (flag_z()) goto lab_p06_L_665C;
  lab_p06_L_6658: ;
  a = 0x1F;
  goto lab_p06_L_665E;
  lab_p06_L_665C: ;
  a = 0x20;
  lab_p06_L_665E: ;
  p00_L_3F9F();
  p06_L_65CB();
  if (flag_nz()) goto lab_p06_L_6677;
  set_hl(0x6AB7);
  p06_L_6A94();
  a = 0x17;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p06_L_669C;
  lab_p06_L_6677: ;
  p06_L_6763();
  if (flag_nz()) goto lab_p06_L_668F;
  set_hl(0x6ABD);
  p06_L_6A94();
  cpu_push_af();
  a = 0x18;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  cpu_pop_af();
  goto lab_p06_L_66A7;
  lab_p06_L_668F: ;
  p00_L_37D7();
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  set_hl(0x8479);
  a = mem_read8(hl());
  flag_cmp(a, 0x62);
  if (flag_z()) goto lab_p06_L_66AF;
  lab_p06_L_669C: ;
  a = mem_read8(hl());
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p06_L_66A7;
  set_hl((uint16_t)(hl() + 1));
  p00_L_3135();
  goto lab_p06_L_66BD;
  lab_p06_L_66A7: ;
  flag_cmp(a, 0xAA);
  if (flag_z()) goto lab_p06_L_66AF;
  flag_cmp(a, 0x5C);
  if (flag_nz()) goto lab_p06_L_66BA;
  lab_p06_L_66AF: ;
  d = a;
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  p00_L_3DB9();
  p00_L_3C93();
  goto lab_p06_L_66BD;
  lab_p06_L_66BA: ;
  p00_L_3C87();
  lab_p06_L_66BD: ;
  a = 0x3D;
  p00_L_3F9F();
  cpu_pop_hl();
  cpu_pop_de();
  p06_L_66C4();
  return;
}

/* flash page 6 cpu 0x66C4 (offset 0x26C4) */
void p06_L_66C4(void) {
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x09);
  if (flag_z()) return;
  cpu_push_de();
  cpu_push_hl();
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  p06_L_66FC();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  h = mem_read8(hl());
  l = e;
  p06_L_5DC3();
  if (flag_c()) { p00_L_24F9(); return; }
  p00_L_3CC9();
  p06_L_449C();
  p00_L_3DE3();
  cpu_pop_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_66FA;
  set_de(mem_read16(0x918C));
  p00_L_192A();
  if (flag_nz()) goto lab_p06_L_66FA;
  cpu_push_hl();
  p06_L_69DE();
  cpu_pop_hl();
  lab_p06_L_66FA: ;
  cpu_pop_de();
  return;
}

/* flash page 6 cpu 0x66FC (offset 0x26FC) */
void p06_L_66FC(void) {
  cpu_push_de();
  cpu_push_hl();
  set_hl(mem_read16(0x9824));
  mem_write16(0x96F4, hl());
  mem_write16(0x96F6, hl());
  cpu_ex_de_hl();
  set_hl(mem_read16(0x9828));
  mem_write16(0x96F8, hl());
  mem_write16(0x96FA, hl());
  p00_L_192A();
  if (flag_c()) { p00_L_24F9(); return; }
  cpu_pop_hl();
  cpu_pop_de();
  return;
}

/* flash page 6 cpu 0x671A (offset 0x271A) */
void p06_L_671A(void) {
  a = mem_read8(0x8518);
  flag_cmp(a, 0xEF);
  if (flag_nz()) goto lab_p06_L_6723;
  c = 0xD0;
  lab_p06_L_6723: ;
  a = mem_read8(0x97A5);
  p00_L_37BF();
  return;
}

/* flash page 6 cpu 0x672A (offset 0x272A) */
void p06_L_672A(void) {
  a = mem_read8(0x8518);
  flag_cmp(a, 0x20);
  if (flag_z()) goto lab_p06_L_6733;
  c = 0xEF;
  lab_p06_L_6733: ;
  a = mem_read8(0x97A5);
  p00_L_37BF();
  return;
}

/* flash page 6 cpu 0x673A (offset 0x273A) */
void p06_L_673A(void) {
  a = mem_read8(0x8578);
  flag_cmp(a, 0xF0);
  if (flag_nz()) goto lab_p06_L_6743;
  c = 0xD0;
  lab_p06_L_6743: ;
  a = mem_read8(0x97A6);
  a = (uint8_t)(a - 1);
  p00_L_37BF();
  return;
}

/* flash page 6 cpu 0x674B (offset 0x274B) */
void p06_L_674B(void) {
  a = mem_read8(0x8578);
  flag_cmp(a, 0x20);
  if (flag_z()) goto lab_p06_L_6754;
  c = 0xF0;
  lab_p06_L_6754: ;
  a = mem_read8(0x97A6);
  a = (uint8_t)(a - 1);
  p00_L_37BF();
  return;
}

/* flash page 6 cpu 0x675C (offset 0x275C) */
void p06_L_675C(void) {
  p06_L_6613();
  if (flag_nc()) p00_L_1F58();
  return;
}

/* flash page 6 cpu 0x6763 (offset 0x2763) */
void p06_L_6763(void) {
  cpu_push_hl();
  ix = cpu_pop16();
  /* ld a,(ix-0x06) */
  flag_cmp(a, 0x01);
  if (flag_nz()) return;
  /* ld a,(ix-0x07) */
  flag_cmp(a, 0x2A);
  return;
}

/* flash page 6 cpu 0x6772 (offset 0x2772) */
void p06_L_6772(void) {
  p00_L_1675();
  p00_rst10();
  if (flag_c()) return;
  cpu_push_de();
  set_hl(mem_read16(0x844B));
  /* ex (sp),hl */
  cpu_push_hl();
  p06_L_67CA();
  if (flag_z()) goto lab_p06_L_6791;
  cpu_pop_hl();
  a = mem_read8(0x8578);
  flag_cmp(a, 0x1F);
  if (flag_z()) goto lab_p06_L_67C5;
  c = 0x1F;
  p06_L_674B();
  goto lab_p06_L_67C5;
  lab_p06_L_6791: ;
  a = 0x20;
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_679B;
  a = 0xD0;
  lab_p06_L_679B: ;
  p00_L_3F9F();
  set_hl(0x6ABD);
  p06_L_6A94();
  a = 0x18;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3C87();
  a = 0x3D;
  p00_L_3F9F();
  cpu_pop_hl();
  p00_rst20();
  a = 0x07;
  p06_L_557D();
  set_hl(0x848E);
  p00_L_3C87();
  p00_L_3D29();
  lab_p06_L_67C5: ;
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x67CA (offset 0x27CA) */
void p06_L_67CA(void) {
  set_hl(0x0101);
  mem_write16(0x844B, hl());
  a = mem_read8(0x97A6);
  a = (uint8_t)(a - 1);
  b = a;
  lab_p06_L_67D5: ;
  p00_L_3D35();
  a = mem_read8(hl());
  flag_cmp(a, 0x20);
  if (flag_z()) goto lab_p06_L_67FD;
  set_de(0x6ABD);
  cpu_ex_de_hl();
  cpu_push_bc();
  a = 0x18;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  cpu_ex_de_hl();
  cpu_pop_bc();
  lab_p06_L_67ED: ;
  a = mem_read8(de());
  set_de((uint16_t)(de() + 1));
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_67FD;
  cpu_cp_hl();
  set_hl((uint16_t)(hl() + 1));
  if (flag_z()) goto lab_p06_L_67ED;
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_67D5;
  return;
  lab_p06_L_67FD: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  return;
}

/* flash page 6 cpu 0x6802 (offset 0x2802) */
void p06_L_6802(void) {
  cpu_push_hl();
  p00_L_1675();
  p00_rst10();
  if (flag_nc()) p00_L_1F58();
  cpu_pop_hl();
  return;
}

/* flash page 6 cpu 0x680C (offset 0x280C) */
void p06_L_680C(void) {
  p06_L_618B();
  p00_L_36D5();
  p00_L_2222();
  p00_L_1675();
  p00_L_38DF();
  return;
}

/* flash page 6 cpu 0x6822 (offset 0x2822) */
void p06_L_6822(void) {
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 2)));
  p06_L_65AF();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 2)));
  p06_L_68D0();
  goto lab_p06_L_687F;
  lab_p06_L_687F: ;
  a = 0x01;
  mem_write8(0x97A5, a);
  p06_L_6539();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 0)));
  a = 0x01;
  mem_write8(0x844B, a);
  p00_L_37AD();
  p06_L_652D();
  if (flag_z()) p06_L_6613();
  mem_write16(0x9706, hl());
  p06_L_6464();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 6)));
  return;
}

/* flash page 6 cpu 0x68CA (offset 0x28CA) */
void p06_L_68CA(void) {
  /* jp nz,0xCD5D - other page/RAM */
  sp = (uint16_t)(sp - 1);
  /* scf */
  return;
}

/* flash page 6 cpu 0x68D0 (offset 0x28D0) */
void p06_L_68D0(void) {
  p06_L_618B();
  p00_rst10();
  mem_write16(0x9706, hl());
  mem_write16(0x9708, de());
  return;
}

/* flash page 6 cpu 0x68DC (offset 0x28DC) */
void p06_L_68DC(void) {
  p06_L_65B6();
  cpu_ex_de_hl();
  a = 0x01;
  mem_write8(0x844B, a);
  p06_L_652D();
  if (flag_z()) return;
  lab_p06_L_68E9: ;
  p00_L_192A();
  if (flag_z()) return;
  p06_L_6506();
  if (flag_nz()) goto lab_p06_L_68F4;
  l = e;
  h = d;
  lab_p06_L_68F4: ;
  a = mem_read8(0x97A6);
  b = a;
  a = mem_read8(0x844B);
  a = (uint8_t)(a + 1);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p06_L_6904;
  mem_write8(0x844B, a);
  goto lab_p06_L_68E9;
  lab_p06_L_6904: ;
  p00_L_3CE1();
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  p06_L_661F();
  goto lab_p06_L_68E9;
}

/* flash page 6 cpu 0x6910 (offset 0x2910) */
void p06_L_6910(void) {
  p06_L_6613();
  if (flag_c()) return;
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p06_L_6937;
  cpu_ex_de_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  cpu_push_hl();
  set_hl(0x0002);
  p00_L_192A();
  if (flag_nz()) { p00_L_24ED(); return; }
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p00_rst20();
  p00_L_11F8();
  p00_L_107E();
  if (flag_nc()) { p00_L_2505(); return; }
  cpu_pop_hl();
  return;
  lab_p06_L_6937: ;
  flag_cmp(a, 0x09);
  if (flag_z()) return;
  p00_L_24DD();
  return;
}

/* flash page 6 cpu 0x693D (offset 0x293D) */
void p06_L_693D(void) {
  p06_L_6910();
  if (flag_c()) goto lab_p06_L_6945;
  set_hl(0x694E);
  lab_p06_L_6945: ;
  set_de(0x9176);
  p00_L_1181();
  p00_L_1181();
  return;
}

/* flash page 6 cpu 0x69DE (offset 0x29DE) */
void p06_L_69DE(void) {
  a = mem_read8(0x844B);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p06_L_69F4;
  cpu_ex_de_hl();
  p06_L_652D();
  p00_L_192A();
  cpu_ex_de_hl();
  if (flag_z()) goto lab_p06_L_69FD;
  c = 0xD0;
  p06_L_672A();
  return;
  lab_p06_L_69F4: ;
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p06_L_69FD;
  c = 0xD0;
  p06_L_674B();
  return;
  lab_p06_L_69FD: ;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = 0xD0;
  p00_L_3F9F();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x6A0F (offset 0x2A0F) */
void p06_L_6A0F(void) {
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  a = mem_read8(0x89FE);
  cpu_push_af();
  set_hl(0xFFF7);
  set_hl((uint16_t)(hl() + sp));
  sp = hl();
  cpu_ex_de_hl();
  set_hl(0x97A7);
  p00_L_1183();
  p00_L_3CD5();
  set_hl(mem_read16(0x9706));
  p06_L_65CB();
  if (flag_z()) goto lab_p06_L_6A43;
  lab_p06_L_6A2E: ;
  p06_L_6506();
  if (flag_z()) goto lab_p06_L_6A40;
  p06_L_661F();
  p00_L_3CD5();
  p00_L_3CCF();
  if (flag_c()) goto lab_p06_L_6A2E;
  goto lab_p06_L_6A46;
  lab_p06_L_6A40: ;
  p06_L_6618();
  lab_p06_L_6A43: ;
  p06_L_6772();
  lab_p06_L_6A46: ;
  set_hl(0x0000);
  set_hl((uint16_t)(hl() + sp));
  set_de(0x97A7);
  p00_L_1183();
  sp = hl();
  cpu_pop_af();
  mem_write8(0x89FE, a);
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x6A5A (offset 0x2A5A) */
void p06_L_6A5A(void) {
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 1)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p06_L_6A79;
  set_hl(0x6A74);
  p00_L_25A2();
  p06_L_6486();
  p00_L_25C8();
  p00_L_37CB();
  goto lab_p06_L_6A7C;
  lab_p06_L_6A79: ;
  p06_L_6F85();
  lab_p06_L_6A7C: ;
  p06_L_675C();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 2)));
  set_hl(0xFE66);
  lab_p06_L_6A86: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  p06_L_64D6();
  if (flag_nz()) goto lab_p06_L_6A86;
  return;
}

/* flash page 6 cpu 0x6A8E (offset 0x2A8E) */
void p06_L_6A8E(void) {
  p06_L_675C();
  p06_L_6802();
  return;
}

/* flash page 6 cpu 0x6A94 (offset 0x2A94) */
void p06_L_6A94(void) {
  set_de(0x8D8F);
  cpu_push_de();
  p00_L_1183();
  p00_L_1183();
  cpu_pop_hl();
  return;
}

/* flash page 6 cpu 0x6AA0 (offset 0x2AA0) */
void p06_str_2(void) {
  b = l;
  d = c;
  d = l;
  b = c;
  d = h;
  c = c;
  c = a;
  c = mem_read8(hl());
  if (flag_nz()) goto lab_p06_L_6AFD;
  c = a;
  c = h;
  d = mem_read8(hl());
  b = l;
  d = d;
  /* nop */
  p06_str_3();
  return;
  lab_p06_L_6AFD: ;
  a = (uint8_t)(a + h);
  set_hl(0x97A5);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x100A);
  p00_L_0013();
  if (flag_nz()) goto lab_p06_L_6B1F;
  l = 0x0C;
  /* sla h */
  p00_L_01A2();
  if (flag_nz()) goto lab_p06_L_6B1F;
  l = 0x06;
  /* sla h */
  p00_L_0198();
  if (flag_nz()) goto lab_p06_L_6B1F;
  set_hl(0x8003);
  lab_p06_L_6B1F: ;
  mem_write16(0x9812, hl());
  a = 0x01;
  p00_L_17CE();
  if (flag_z()) goto lab_p06_L_6B2B;
  a = 0x05;
  lab_p06_L_6B2B: ;
  mem_write8(0x844B, a);
  p00_L_176F();
  p06_L_6C4E();
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_6B42;
  p00_L_3621();
  p00_L_3CD5();
  p00_L_361B();
  lab_p06_L_6B42: ;
  a = mem_read8(0x9813);
  p06_L_6B45();
  return;
}

/* flash page 6 cpu 0x6AB0 (offset 0x2AB0) */
void p06_str_3(void) {
  h = l;
  mem_write8(hl(), c);
  l = mem_read8(hl());
  a = mem_read8(0x3D30);
  /* nop */
  p06_str_4();
  return;
}

/* flash page 6 cpu 0x6AB7 (offset 0x2AB7) */
void p06_str_4(void) {
  h = d;
  l = a;
  mem_write8(hl(), l);
  l = mem_read8(hl());
  h = h;
  /* nop */
  p06_str_5();
  return;
}

/* flash page 6 cpu 0x6ABD (offset 0x2ABD) */
void p06_str_5(void) {
  l = h;
  h = l;
  h = mem_read8(hl());
  mem_write8(hl(), h);
  l = (uint8_t)(l - 1);
  mem_write8(hl(), d);
  mem_write8(hl(), h);
  /* nop */
  p06_L_6AC5();
  return;
}

/* flash page 6 cpu 0x6AC5 (offset 0x2AC5) */
void p06_L_6AC5(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 7)));
  goto lab_p06_L_6AD7;
  lab_p06_L_6AD7: ;
  p00_L_17DB();
  a = 0;
  flag_logic(a);
  mem_write8(0x8E2A, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p06_L_6AE9;
  a = 0x00;
  p00_L_2FDF();
  lab_p06_L_6AE9: ;
  set_hl(0x6B95);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 7)));
  p00_L_17FA();
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  set_hl(0x97A5);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x100A);
  p00_L_0013();
  if (flag_nz()) goto lab_p06_L_6B1F;
  l = 0x0C;
  /* sla h */
  p00_L_01A2();
  if (flag_nz()) goto lab_p06_L_6B1F;
  l = 0x06;
  /* sla h */
  p00_L_0198();
  if (flag_nz()) goto lab_p06_L_6B1F;
  set_hl(0x8003);
  lab_p06_L_6B1F: ;
  mem_write16(0x9812, hl());
  a = 0x01;
  p00_L_17CE();
  if (flag_z()) goto lab_p06_L_6B2B;
  a = 0x05;
  lab_p06_L_6B2B: ;
  mem_write8(0x844B, a);
  p00_L_176F();
  p06_L_6C4E();
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_6B42;
  p00_L_3621();
  p00_L_3CD5();
  p00_L_361B();
  lab_p06_L_6B42: ;
  a = mem_read8(0x9813);
  p06_L_6B45();
  return;
}

/* flash page 6 cpu 0x6ACB (offset 0x2ACB) */
void p06_L_6ACB(void) {
  goto lab_p06_L_6AD1;
  lab_p06_L_6AD1: ;
  p00_L_17FA();
  p00_L_3D17();
  p00_L_17DB();
  a = 0;
  flag_logic(a);
  mem_write8(0x8E2A, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p06_L_6AE9;
  a = 0x00;
  p00_L_2FDF();
  lab_p06_L_6AE9: ;
  set_hl(0x6B95);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 7)));
  p00_L_17FA();
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  set_hl(0x97A5);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x100A);
  p00_L_0013();
  if (flag_nz()) goto lab_p06_L_6B1F;
  l = 0x0C;
  /* sla h */
  p00_L_01A2();
  if (flag_nz()) goto lab_p06_L_6B1F;
  l = 0x06;
  /* sla h */
  p00_L_0198();
  if (flag_nz()) goto lab_p06_L_6B1F;
  set_hl(0x8003);
  lab_p06_L_6B1F: ;
  mem_write16(0x9812, hl());
  a = 0x01;
  p00_L_17CE();
  if (flag_z()) goto lab_p06_L_6B2B;
  a = 0x05;
  lab_p06_L_6B2B: ;
  mem_write8(0x844B, a);
  p00_L_176F();
  p06_L_6C4E();
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_6B42;
  p00_L_3621();
  p00_L_3CD5();
  p00_L_361B();
  lab_p06_L_6B42: ;
  a = mem_read8(0x9813);
  p06_L_6B45();
  return;
}

/* flash page 6 cpu 0x6ACD (offset 0x2ACD) */
void p06_L_6ACD(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 7)));
  p00_L_17FA();
  p00_L_3D17();
  p00_L_17DB();
  a = 0;
  flag_logic(a);
  mem_write8(0x8E2A, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p06_L_6AE9;
  a = 0x00;
  p00_L_2FDF();
  lab_p06_L_6AE9: ;
  set_hl(0x6B95);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 7)));
  p00_L_17FA();
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  set_hl(0x97A5);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x100A);
  p00_L_0013();
  if (flag_nz()) goto lab_p06_L_6B1F;
  l = 0x0C;
  /* sla h */
  p00_L_01A2();
  if (flag_nz()) goto lab_p06_L_6B1F;
  l = 0x06;
  /* sla h */
  p00_L_0198();
  if (flag_nz()) goto lab_p06_L_6B1F;
  set_hl(0x8003);
  lab_p06_L_6B1F: ;
  mem_write16(0x9812, hl());
  a = 0x01;
  p00_L_17CE();
  if (flag_z()) goto lab_p06_L_6B2B;
  a = 0x05;
  lab_p06_L_6B2B: ;
  mem_write8(0x844B, a);
  p00_L_176F();
  p06_L_6C4E();
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_6B42;
  p00_L_3621();
  p00_L_3CD5();
  p00_L_361B();
  lab_p06_L_6B42: ;
  a = mem_read8(0x9813);
  p06_L_6B45();
  return;
}

/* flash page 6 cpu 0x6B45 (offset 0x2B45) */
void p06_L_6B45(void) {
  p06_L_72AF();
  p06_L_6F72();
  p06_L_712D();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 7)) == 0);
  if (flag_z()) return;
  a = 0x03;
  p00_L_01A2();
  if (flag_z()) goto lab_p06_L_6B5D;
  a = (uint8_t)(a + 1);
  goto lab_p06_L_6B68;
  lab_p06_L_6B5D: ;
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_6B68;
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) | (1u << 0)));
  a = (uint8_t)(a + 0x02);
  lab_p06_L_6B68: ;
  mem_write8(0x844C, a);
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 7)));
  lab_p06_L_6B6F: ;
  a = mem_read8(0x9813);
  set_hl(0x9654);
  cpu_cp_hl();
  if (flag_z()) goto lab_p06_L_6B7D;
  p06_L_7331();
  goto lab_p06_L_6B6F;
  lab_p06_L_6B7D: ;
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 0)));
  set_hl(0x844C);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p06_L_4635();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p06_L_7200();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x6BC1 (offset 0x2BC1) */
void p06_L_6BC1(void) {
  set_hl(mem_read16(0x9812));
  a = h;
  a = (uint8_t)(a + 1);
  a = a & 0x0F;
  flag_logic(a);
  flag_cmp(a, l);
  if (flag_nz()) goto lab_p06_L_6BD9;
  p00_L_019D();
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 7)) == 0);
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  lab_p06_L_6BD9: ;
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_6BED;
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p06_L_6C02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_6D1F;
  goto lab_p06_L_6C02;
  lab_p06_L_6BED: ;
  p00_L_01A2();
  if (flag_z()) goto lab_p06_L_6C02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p06_L_6C02;
  set_hl(mem_read16(0x9812));
  a = h;
  a = (uint8_t)(a + 1);
  a = (uint8_t)(a + 1);
  a = a & 0x0F;
  flag_logic(a);
  flag_cmp(a, l);
  if (flag_z()) return;
  lab_p06_L_6C02: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8E2A, a);
  p06_L_47DA();
  p06_L_6F85();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  p00_L_3CD5();
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p06_L_6C1F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_6C37;
  lab_p06_L_6C1F: ;
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_6C37;
  /* ld ix,(0x9700) */
  set_de(0x0006);
  /* add ix,de */
  /* ld (0x9700),ix */
  p00_L_371D();
  p00_L_3CD5();
  lab_p06_L_6C37: ;
  set_hl(mem_read16(0x9812));
  h = (uint8_t)(h + 1);
  a = h;
  mem_write8(0x9813, a);
  p06_L_6B45();
  return;
  lab_p06_L_6D1F: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8E2A, a);
  p06_L_47DA();
  p06_L_6F85();
  p00_L_002B();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  /* ld ix,(0x9700) */
  set_de(0x0003);
  /* add ix,de */
  /* ld (0x9700),ix */
  a = mem_read8(0x844B);
  cpu_push_af();
  p00_L_3CD5();
  cpu_pop_af();
  set_hl(0x844B);
  cpu_cp_hl();
  if (flag_z()) p00_L_371D();
  p00_L_3747();
  a = 0x03;
  mem_write8(0x84D2, a);
  p00_L_3681();
  return;
}

/* flash page 6 cpu 0x6C42 (offset 0x2C42) */
void p06_L_6C42(void) {
  goto lab_p06_L_6C42;
  lab_p06_L_6C0C: ;
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  p00_L_3CD5();
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p06_L_6C1F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_6C37;
  lab_p06_L_6C1F: ;
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_6C37;
  /* ld ix,(0x9700) */
  set_de(0x0006);
  /* add ix,de */
  /* ld (0x9700),ix */
  p00_L_371D();
  p00_L_3CD5();
  lab_p06_L_6C37: ;
  set_hl(mem_read16(0x9812));
  h = (uint8_t)(h + 1);
  a = h;
  mem_write8(0x9813, a);
  p06_L_6B45();
  return;
  lab_p06_L_6C42: ;
  set_hl(0x6B95);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 0)));
  goto lab_p06_L_6C0C;
}

/* flash page 6 cpu 0x6C4E (offset 0x2C4E) */
void p06_L_6C4E(void) {
  a = 0x03;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_2FDF();
  if (flag_nz()) return;
  set_hl(0x0006);
  p00_L_17CE();
  if (flag_z()) goto lab_p06_L_6C62;
  h = 0x20;
  lab_p06_L_6C62: ;
  mem_write16(0x86D7, hl());
  set_hl(0x267E);
  a = 0x1A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  a = mem_read8(0x92D9);
  p06_L_6CB2();
  set_hl(0x001E);
  p00_L_17CE();
  if (flag_z()) goto lab_p06_L_6C81;
  h = 0x20;
  lab_p06_L_6C81: ;
  mem_write16(0x86D7, hl());
  set_hl(0x2684);
  a = 0x1B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  a = mem_read8(0x92EA);
  p06_L_6CB2();
  set_hl(0x0036);
  p00_L_17CE();
  if (flag_z()) goto lab_p06_L_6CA0;
  h = 0x20;
  lab_p06_L_6CA0: ;
  mem_write16(0x86D7, hl());
  set_hl(0x268A);
  a = 0x1C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  a = mem_read8(0x92FB);
  p06_L_6CB2();
  return;
}

/* flash page 6 cpu 0x6CB2 (offset 0x2CB2) */
void p06_L_6CB2(void) {
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_6CBA;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  lab_p06_L_6CBA: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p00_L_3D4D();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  return;
}

/* flash page 6 cpu 0x6CF9 (offset 0x2CF9) */
void p06_L_6CF9(void) {
  goto lab_p06_L_6CF9;
  lab_p06_L_6CED: ;
  p00_L_3681();
  a = 0x03;
  mem_write8(0x84D2, a);
  p00_L_372F();
  return;
  lab_p06_L_6CF9: ;
  p00_L_3615();
  goto lab_p06_L_6CED;
}

/* flash page 6 cpu 0x6CFF (offset 0x2CFF) */
void p06_L_6CFF(void) {
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p06_L_6D58;
  p00_L_1923();
  if (flag_nz()) goto lab_p06_L_6D0D;
  p00_L_019D();
  if (flag_nz()) goto lab_p06_L_6D1F;
  lab_p06_L_6D0D: ;
  p06_L_45F4();
  a = 0xFF;
  if (flag_nz()) return;
  a = 0;
  flag_logic(a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  p00_L_019D();
  if (flag_z()) { p06_L_6BC1(); return; }
  lab_p06_L_6D1F: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8E2A, a);
  p06_L_47DA();
  p06_L_6F85();
  p00_L_002B();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  /* ld ix,(0x9700) */
  set_de(0x0003);
  /* add ix,de */
  /* ld (0x9700),ix */
  a = mem_read8(0x844B);
  cpu_push_af();
  p00_L_3CD5();
  cpu_pop_af();
  set_hl(0x844B);
  cpu_cp_hl();
  if (flag_z()) p00_L_371D();
  p00_L_3747();
  a = 0x03;
  mem_write8(0x84D2, a);
  p00_L_3681();
  return;
  lab_p06_L_6D58: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p06_L_6D76;
  p00_L_191A();
  if (flag_z()) goto lab_p06_L_6D65;
  p06_L_44FD();
  return;
  lab_p06_L_6D65: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  set_hl(0x844C);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) | (1u << 0)));
  p00_L_03A0();
  return;
  lab_p06_L_6D76: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p06_L_6D7E;
  p06_L_453B();
  return;
  lab_p06_L_6D7E: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p06_L_6E1D;
  p00_L_191A();
  if (flag_nz()) { p06_L_45A8(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  p06_L_6D8E();
  return;
  lab_p06_L_6E1D: ;
  flag_cmp(a, 0x0E);
  if (flag_z()) { p06_L_44D5(); return; }
  flag_cmp(a, 0x0F);
  if (flag_z()) { p06_L_44EB(); return; }
  flag_cmp(a, 0x0B);
  if (flag_z()) { p06_L_4868(); return; }
  flag_cmp(a, 0x21);
  if (flag_nz()) goto lab_p06_L_6E36;
  p06_L_44FD();
  if (flag_z()) return;
  goto lab_p06_L_6E3A;
  lab_p06_L_6E36: ;
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p06_L_6E4F;
  lab_p06_L_6E3A: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  p06_L_4443();
  cpu_push_af();
  if (flag_nz()) p00_L_0091();
  p06_L_712D();
  cpu_pop_af();
  if (flag_z()) return;
  c = 0x01;
  p06_L_6F8C();
  return;
  lab_p06_L_6E4F: ;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p06_L_6E9A;
  p00_L_03A0();
  p00_L_1916();
  if (flag_z()) goto lab_p06_L_6E8D;
  lab_p06_L_6E5B: ;
  p00_L_191A();
  if (flag_z()) goto lab_p06_L_6E65;
  p06_L_45A8();
  goto lab_p06_L_6E5B;
  lab_p06_L_6E65: ;
  a = mem_read8(0x9813);
  p06_L_7257();
  a = 0x06;
  p00_L_019D();
  if (flag_nz()) goto lab_p06_L_6E74;
  a = 0x00;
  lab_p06_L_6E74: ;
  mem_write8(hl(), a);
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = mem_read8(0x9813);
  p06_L_7285();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  p06_L_44C8();
  p06_L_712D();
  lab_p06_L_6E8D: ;
  set_hl(mem_read16(0x9706));
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_0087();
  c = 0x00;
  p06_L_6F8C();
  return;
  lab_p06_L_6E9A: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p06_L_6EB0;
  set_hl(mem_read16(0x9706));
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  mem_write8(0x84D2, a);
  a = mem_read8(hl());
  a = a & 0xE0;
  flag_logic(a);
  a = a | 0x0A;
  flag_logic(a);
  mem_write8(hl(), a);
  p00_L_316B();
  return;
  lab_p06_L_6EB0: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p06_L_6EB9;
  flag_cmp(a, 0x8A);
  if (flag_z()) return;
  lab_p06_L_6EB9: ;
  flag_cmp(a, 0x27);
  if (flag_nz()) goto lab_p06_L_6EBE;
  return;
  lab_p06_L_6EBE: ;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p06_L_6EF7;
  p00_L_0091();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 5)));
  p00_L_03A0();
  lab_p06_L_6ECD: ;
  p00_L_191A();
  if (flag_z()) goto lab_p06_L_6ED7;
  p06_L_45A8();
  goto lab_p06_L_6ECD;
  lab_p06_L_6ED7: ;
  p00_L_1748();
  p06_L_5DDB();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 5)));
  p06_L_449C();
  a = mem_read8(0x859A);
  flag_cmp(a, 0x54);
  if (flag_nz()) goto lab_p06_L_6EEF;
  p06_L_622D();
  return;
  lab_p06_L_6EEF: ;
  p06_L_712D();
  c = 0x01;
  p06_L_6F8C();
  return;
  lab_p06_L_6EF7: ;
  flag_cmp(a, 0x5A);
  if (flag_c()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p06_L_6F09;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p06_L_6F09;
  flag_cmp(a, 0xC6);
  if (flag_z()) return;
  lab_p06_L_6F09: ;
  p00_L_1808();
  if (flag_z()) { p00_L_30E1(); return; }
  p06_L_4671();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 1)) == 0);
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  c = 0x01;
  p06_L_6F8C();
  p00_L_0091();
  return;
}

/* flash page 6 cpu 0x6D8E (offset 0x2D8E) */
void p06_L_6D8E(void) {
  goto lab_p06_L_6D8E;
  lab_p06_L_6CCA: ;
  p00_L_019D();
  if (flag_nz()) goto lab_p06_L_6CDD;
  a = 0x04;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_2FDF();
  if (flag_nz()) return;
  p00_L_367B();
  return;
  lab_p06_L_6CDD: ;
  p00_L_3615();
  p00_L_3789();
  if (flag_nc()) goto lab_p06_L_6CEA;
  p00_L_3729();
  goto lab_p06_L_6CED;
  lab_p06_L_6CEA: ;
  mem_write8(0x844B, a);
  lab_p06_L_6CED: ;
  p00_L_3681();
  a = 0x03;
  mem_write8(0x84D2, a);
  p00_L_372F();
  return;
  lab_p06_L_6D8E: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8E2A, a);
  p06_L_6F85();
  a = mem_read8(0x9813);
  b = a;
  a = a & 0x0F;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_6CCA;
  a = b;
  a = (uint8_t)(a - 1);
  mem_write8(0x9813, a);
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_6DC3;
  /* ld ix,(0x9700) */
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p06_L_6DB8;
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_6DBF;
  lab_p06_L_6DB8: ;
  p00_L_376B();
  p00_L_3771();
  return;
  lab_p06_L_6DBF: ;
  p00_L_376B();
  return;
  lab_p06_L_6DC3: ;
  p06_L_6F72();
  set_hl(mem_read16(0x96F8));
  set_de(mem_read16(0x96FA));
  p06_L_7107();
  set_de((uint16_t)(de() + 1));
  a = 0;
  flag_logic(a);
  set_hl(mem_read16(0x844B));
  h = a;
  a = mem_read8(0x844C);
  flag_cmp(a, 0x07);
  if (flag_c()) goto lab_p06_L_6DE5;
  a = (uint8_t)(a - 0x03);
  mem_write8(0x844C, a);
  mem_write8(0x97A7, a);
  lab_p06_L_6DE5: ;
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_m()) goto lab_p06_L_6DFB;
  a = l;
  flag_cmp(a, 0x01);
  if (flag_c()) goto lab_p06_L_6DFB;
  p00_L_17CE();
  if (flag_z()) goto lab_p06_L_6E10;
  a = l;
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p06_L_6E10;
  lab_p06_L_6DFB: ;
  a = mem_read8(0x844C);
  cpu_push_af();
  p00_L_3D2F();
  a = mem_read8(0x9813);
  p06_L_72AF();
  p06_L_712D();
  cpu_pop_af();
  mem_write8(0x844C, a);
  return;
  lab_p06_L_6E10: ;
  a = l;
  mem_write8(0x844B, a);
  return;
}

/* flash page 6 cpu 0x6E15 (offset 0x2E15) */
void p06_L_6E15(void) {
  goto lab_p06_L_6E15;
  lab_p06_L_6DC3: ;
  p06_L_6F72();
  set_hl(mem_read16(0x96F8));
  set_de(mem_read16(0x96FA));
  p06_L_7107();
  set_de((uint16_t)(de() + 1));
  a = 0;
  flag_logic(a);
  set_hl(mem_read16(0x844B));
  h = a;
  a = mem_read8(0x844C);
  flag_cmp(a, 0x07);
  if (flag_c()) goto lab_p06_L_6DE5;
  a = (uint8_t)(a - 0x03);
  mem_write8(0x844C, a);
  mem_write8(0x97A7, a);
  lab_p06_L_6DE5: ;
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_m()) goto lab_p06_L_6DFB;
  a = l;
  flag_cmp(a, 0x01);
  if (flag_c()) goto lab_p06_L_6DFB;
  p00_L_17CE();
  if (flag_z()) goto lab_p06_L_6E10;
  a = l;
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p06_L_6E10;
  lab_p06_L_6DFB: ;
  a = mem_read8(0x844C);
  cpu_push_af();
  p00_L_3D2F();
  a = mem_read8(0x9813);
  p06_L_72AF();
  p06_L_712D();
  cpu_pop_af();
  mem_write8(0x844C, a);
  return;
  lab_p06_L_6E10: ;
  a = l;
  mem_write8(0x844B, a);
  return;
  lab_p06_L_6E15: ;
  set_hl(0x6B95);
  p00_L_07CC();
  goto lab_p06_L_6DC3;
}

/* flash page 6 cpu 0x6F4C (offset 0x2F4C) */
void p06_L_6F4C(void) {
  a = mem_read8(0x9813);
  p06_L_6F4F();
  return;
}

/* flash page 6 cpu 0x6F4F (offset 0x2F4F) */
void p06_L_6F4F(void) {
  h = a;
  l = 0x5E;
  mem_write16(0x8479, hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x847B, a);
  a = h;
  return;
}

/* flash page 6 cpu 0x6F5B (offset 0x2F5B) */
void p06_L_6F5B(void) {
  p06_L_6F4C();
  p00_rst10();
  mem_write16(0x9706, hl());
  p06_L_483D();
  return;
}

/* flash page 6 cpu 0x6F66 (offset 0x2F66) */
void p06_L_6F66(void) {
  p06_L_6F4C();
  p00_rst10();
  a = 0x3D;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_z()) return;
  a = 0x7F;
  return;
}

/* flash page 6 cpu 0x6F72 (offset 0x2F72) */
void p06_L_6F72(void) {
  p06_L_6F5B();
  a = 0x09;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_2FDF();
  if (flag_z()) p00_L_37AD();
  p00_L_3CC9();
  return;
}

/* flash page 6 cpu 0x6F85 (offset 0x2F85) */
void p06_L_6F85(void) {
  p00_L_03A0();
  p06_L_4844();
  return;
}

/* flash page 6 cpu 0x6F8C (offset 0x2F8C) */
void p06_L_6F8C(void) {
  set_hl(mem_read16(0x9706));
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p06_L_6F99;
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p06_L_6FA1;
  goto lab_p06_L_6F9D;
  lab_p06_L_6F99: ;
  flag_set_z((mem_read8(hl()) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p06_L_6FA1;
  lab_p06_L_6F9D: ;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 1)));
  lab_p06_L_6FA1: ;
  p06_L_70A2();
  p06_L_70CF();
  flag_cmp(a, c);
  if (flag_z()) return;
  a = 0x05;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_2FDF();
  if (flag_nz()) return;
  p06_L_70D8();
  set_hl(mem_read16(0x96F4));
  set_de(mem_read16(0x96F6));
  p06_L_7107();
  a = 0x7F;
  flag_set_z((c & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_6FC8;
  a = 0x3D;
  lab_p06_L_6FC8: ;
  c = a;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  cpu_push_de();
  a = 0;
  flag_logic(a);
  h = a;
  cpu_sbc_hl_de();
  if (flag_m()) goto lab_p06_L_6FF6;
  p00_L_17CE();
  if (flag_z()) goto lab_p06_L_6FDF;
  a = l;
  flag_cmp(a, 0x04);
  if (flag_c()) goto lab_p06_L_6FF6;
  lab_p06_L_6FDF: ;
  a = mem_read8(0x97A7);
  a = (uint8_t)(a - 1);
  h = a;
  mem_write16(0x844B, hl());
  a = 0x07;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_2FDF();
  if (flag_nz()) goto lab_p06_L_6FF6;
  a = c;
  p00_L_3C6F();
  lab_p06_L_6FF6: ;
  cpu_pop_de();
  cpu_pop_hl();
  cpu_push_hl();
  mem_write16(0x844B, hl());
  a = mem_read8(0x859A);
  flag_cmp(a, 0x4A);
  if (flag_z()) goto lab_p06_L_7097;
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_700C;
  cpu_push_bc();
  goto lab_p06_L_7045;
  lab_p06_L_700C: ;
  p00_L_01A2();
  if (flag_z()) goto lab_p06_L_7097;
  cpu_push_bc();
  a = mem_read8(0x9813);
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_7045;
  cpu_push_de();
  a = (uint8_t)(a - 1);
  p06_L_6F4F();
  p00_L_188D();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  p06_L_7107();
  set_de((uint16_t)(de() + 1));
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  set_hl(mem_read16(0x844B));
  a = 0;
  flag_logic(a);
  h = a;
  cpu_sbc_hl_de();
  if (flag_m()) goto lab_p06_L_7097;
  p00_L_17CE();
  if (flag_z()) goto lab_p06_L_7043;
  a = l;
  flag_cmp(a, 0x04);
  if (flag_c()) goto lab_p06_L_7097;
  lab_p06_L_7043: ;
  goto lab_p06_L_7078;
  lab_p06_L_7045: ;
  set_hl(mem_read16(0x96F8));
  set_de(mem_read16(0x96FA));
  p06_L_72EE();
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_7056;
  set_de((uint16_t)(de() + 1));
  lab_p06_L_7056: ;
  a = mem_read8(0x844C);
  l = a;
  h = 0x00;
  set_hl((uint16_t)(hl() + de()));
  b = 0x04;
  lab_p06_L_705F: ;
  /* srl h */
  /* rr l */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_705F;
  cpu_pop_bc();
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  set_hl(mem_read16(0x844B));
  a = 0;
  flag_logic(a);
  h = a;
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  set_de(0x0008);
  cpu_sbc_hl_de();
  cpu_pop_hl();
  if (flag_p()) goto lab_p06_L_7097;
  lab_p06_L_7078: ;
  a = l;
  mem_write8(0x844B, a);
  a = mem_read8(0x97A7);
  a = (uint8_t)(a - 1);
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_7087;
  a = 0x08;
  lab_p06_L_7087: ;
  mem_write8(0x844C, a);
  a = mem_read8(0x844B);
  set_hl(0x97A5);
  cpu_cp_hl();
  if (flag_c()) goto lab_p06_L_7097;
  a = c;
  p00_L_3C6F();
  lab_p06_L_7097: ;
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x70A2 (offset 0x30A2) */
void p06_L_70A2(void) {
  p00_L_01A2();
  if (flag_nz()) goto lab_p06_L_70AE;
  p00_L_1916();
  if (flag_nz()) return;
  lab_p06_L_70AB: ;
  c = 0x00;
  return;
  lab_p06_L_70AE: ;
  a = mem_read8(0x9813);
  cpu_push_af();
  cpu_push_bc();
  a = a ^ 0x01;
  flag_logic(a);
  mem_write8(0x9813, a);
  p06_L_6F4C();
  p00_rst10();
  mem_write16(0x981C, hl());
  cpu_pop_bc();
  cpu_pop_af();
  mem_write8(0x9813, a);
  p06_L_7100();
  if (flag_z()) goto lab_p06_L_70AB;
  p00_L_1916();
  if (flag_z()) goto lab_p06_L_70AB;
  return;
}

/* flash page 6 cpu 0x70CF (offset 0x30CF) */
void p06_L_70CF(void) {
  a = 0;
  flag_logic(a);
  set_hl(mem_read16(0x9706));
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_z()) return;
  a = (uint8_t)(a + 1);
  return;
}

/* flash page 6 cpu 0x70D8 (offset 0x30D8) */
void p06_L_70D8(void) {
  p00_L_0091();
  set_hl(mem_read16(0x9706));
  flag_set_z((c & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_70F0;
  a = 0;
  flag_logic(a);
  p00_L_3897();
  p00_L_01A2();
  if (flag_z()) return;
  set_hl(mem_read16(0x981C));
  a = 0;
  flag_logic(a);
  goto lab_p06_L_70FC;
  lab_p06_L_70F0: ;
  /* scf */
  p00_L_3897();
  p00_L_01A2();
  if (flag_z()) return;
  set_hl(mem_read16(0x981C));
  /* scf */
  lab_p06_L_70FC: ;
  p00_L_3897();
  return;
}

/* flash page 6 cpu 0x7100 (offset 0x3100) */
void p06_L_7100(void) {
  cpu_ex_de_hl();
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  /* or (hl) */
  set_hl((uint16_t)(hl() - 1));
  cpu_ex_de_hl();
  return;
}

/* flash page 6 cpu 0x7107 (offset 0x3107) */
void p06_L_7107(void) {
  cpu_push_bc();
  p06_L_72EE();
  l = 0x04;
  p00_L_01A2();
  if (flag_z()) goto lab_p06_L_7115;
  l = (uint8_t)(l + 1);
  goto lab_p06_L_711C;
  lab_p06_L_7115: ;
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_711C;
  l = (uint8_t)(l + 1);
  l = (uint8_t)(l + 1);
  lab_p06_L_711C: ;
  h = 0x00;
  set_hl((uint16_t)(hl() + de()));
  b = 0x04;
  lab_p06_L_7121: ;
  /* srl h */
  /* rr l */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_7121;
  cpu_ex_de_hl();
  cpu_pop_bc();
  return;
}

/* flash page 6 cpu 0x712D (offset 0x312D) */
void p06_L_712D(void) {
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_7136;
  a = mem_read8(0x97A7);
  cpu_push_af();
  lab_p06_L_7136: ;
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p06_L_7200();
  if (flag_nc()) goto lab_p06_L_7188;
  a = mem_read8(0x9813);
  cpu_push_af();
  cpu_push_af();
  lab_p06_L_7148: ;
  a = mem_read8(0x844B);
  a = (uint8_t)(a + 1);
  set_hl(0x97A6);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p06_L_7180;
  p00_L_3CD5();
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_7165;
  p00_L_371D();
  p00_L_3CD5();
  p00_L_3CCF();
  if (flag_nc()) goto lab_p06_L_7180;
  lab_p06_L_7165: ;
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  cpu_push_af();
  mem_write8(0x9813, a);
  a = a & 0x0F;
  flag_logic(a);
  set_hl(0x9812);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p06_L_7180;
  cpu_pop_af();
  cpu_push_af();
  p06_L_72AF();
  p06_L_71F7();
  p06_L_7207();
  if (flag_c()) goto lab_p06_L_7148;
  lab_p06_L_7180: ;
  p00_L_3D29();
  cpu_pop_af();
  cpu_pop_af();
  mem_write8(0x9813, a);
  lab_p06_L_7188: ;
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  p00_L_019D();
  if (flag_z()) return;
  p00_L_3CC9();
  cpu_pop_af();
  mem_write8(0x97A7, a);
  return;
}

/* flash page 6 cpu 0x719C (offset 0x319C) */
void p06_L_719C(void) {
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  a = mem_read8(0x9813);
  cpu_push_af();
  cpu_push_af();
  p00_L_3813();
  flag_cmp(a, 0x1F);
  if (flag_nz()) goto lab_p06_L_71AF;
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  cpu_push_af();
  lab_p06_L_71AF: ;
  a = mem_read8(0x844B);
  a = (uint8_t)(a + 1);
  set_hl(0x97A6);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p06_L_71F1;
  p00_L_3CD5();
  p00_L_3CCF();
  if (flag_nc()) goto lab_p06_L_71EE;
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  p06_L_71C3();
  return;
  lab_p06_L_71EE: ;
  p00_L_3D29();
  lab_p06_L_71F1: ;
  cpu_pop_af();
  cpu_pop_af();
  mem_write8(0x9813, a);
  return;
}

/* flash page 6 cpu 0x71C3 (offset 0x31C3) */
void p06_L_71C3(void) {
  goto lab_p06_L_71C3;
  lab_p06_L_71AF: ;
  a = mem_read8(0x844B);
  a = (uint8_t)(a + 1);
  set_hl(0x97A6);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p06_L_71F1;
  p00_L_3CD5();
  p00_L_3CCF();
  if (flag_nc()) goto lab_p06_L_71EE;
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  lab_p06_L_71C3: ;
  cpu_push_af();
  mem_write8(0x9813, a);
  a = a & 0x0F;
  flag_logic(a);
  set_hl(0x9812);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p06_L_71EE;
  cpu_pop_af();
  cpu_push_af();
  p06_L_72AF();
  p06_L_71F7();
  p06_L_7207();
  if (flag_nc()) goto lab_p06_L_71EE;
  a = mem_read8(0x844B);
  flag_cmp(a, 0x07);
  if (flag_z()) goto lab_p06_L_71F1;
  p00_L_3CD5();
  p00_L_371D();
  p00_L_3CCF();
  if (flag_c()) goto lab_p06_L_71AF;
  lab_p06_L_71EE: ;
  p00_L_3D29();
  lab_p06_L_71F1: ;
  cpu_pop_af();
  cpu_pop_af();
  mem_write8(0x9813, a);
  return;
}

/* flash page 6 cpu 0x71F7 (offset 0x31F7) */
void p06_L_71F7(void) {
  p00_rst10();
  cpu_ex_de_hl();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 6 cpu 0x7200 (offset 0x3200) */
void p06_L_7200(void) {
  set_hl(mem_read16(0x96FA));
  set_de(mem_read16(0x96F8));
  p06_L_7207();
  return;
}

/* flash page 6 cpu 0x7207 (offset 0x3207) */
void p06_L_7207(void) {
  a = mem_read8((uint16_t)(iy + 0x0D));
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  cpu_ex_de_hl();
  cpu_push_de();
  p06_L_4463();
  if (flag_z()) goto lab_p06_L_722B;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p00_L_3DB9();
  p00_L_3C93();
  a = mem_read8(0x844B);
  p06_L_7221();
  return;
  lab_p06_L_722B: ;
  cpu_pop_de();
  p00_L_3D1D();
  /* scf */
  cpu_pop_de();
  mem_write8((uint16_t)(iy + 0x0D), d);
  return;
}

/* flash page 6 cpu 0x7221 (offset 0x3221) */
void p06_L_7221(void) {
  goto lab_p06_L_7221;
  lab_p06_L_7210: ;
  cpu_push_de();
  p06_L_4463();
  if (flag_z()) goto lab_p06_L_722B;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p00_L_3DB9();
  p00_L_3C93();
  a = mem_read8(0x844B);
  lab_p06_L_7221: ;
  set_hl(0x97A6);
  cpu_cp_hl();
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_nc()) goto lab_p06_L_7230;
  goto lab_p06_L_7210;
  lab_p06_L_722B: ;
  cpu_pop_de();
  p00_L_3D1D();
  /* scf */
  lab_p06_L_7230: ;
  cpu_pop_de();
  mem_write8((uint16_t)(iy + 0x0D), d);
  return;
}

/* flash page 6 cpu 0x7235 (offset 0x3235) */
void p06_L_7235(void) {
  set_hl(mem_read16(0x96FA));
  set_de(mem_read16(0x96F8));
  a = mem_read8(0x97A6);
  cpu_push_af();
  a = mem_read8(0x844B);
  a = (uint8_t)(a + 1);
  mem_write8(0x97A6, a);
  p06_L_7207();
  cpu_pop_de();
  cpu_push_af();
  a = d;
  mem_write8(0x97A6, a);
  cpu_pop_af();
  if (flag_c()) return;
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  return;
}

/* flash page 6 cpu 0x7257 (offset 0x3257) */
void p06_L_7257(void) {
  set_hl(0x9776);
  flag_set_z((a & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p06_L_7275;
  set_hl(0x9780);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) goto lab_p06_L_726B;
  a = a & 0x0F;
  flag_logic(a);
  /* sra a */
  goto lab_p06_L_7275;
  lab_p06_L_726B: ;
  set_hl(0x9786);
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p06_L_7275;
  set_hl(0x978C);
  lab_p06_L_7275: ;
  a = a & 0x0F;
  flag_logic(a);
  d = 0x00;
  e = a;
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 6 cpu 0x727C (offset 0x327C) */
void p06_L_727C(void) {
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) return;
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) return;
  a = 0xFF;
  return;
}

/* flash page 6 cpu 0x7285 (offset 0x3285) */
void p06_L_7285(void) {
  b = a;
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_2FDF();
  a = b;
  if (flag_nz()) return;
  cpu_push_af();
  p06_L_727C();
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p06_L_729D;
  a = 0x20;
  goto lab_p06_L_72AA;
  lab_p06_L_729D: ;
  p06_L_7257();
  a = mem_read8(0x859A);
  flag_cmp(a, 0x4A);
  if (flag_z()) goto lab_p06_L_72AD;
  a = 0xE8;
  /* add a,(hl) */
  lab_p06_L_72AA: ;
  p00_L_3F9F();
  lab_p06_L_72AD: ;
  cpu_pop_af();
  return;
}

/* flash page 6 cpu 0x72AF (offset 0x32AF) */
void p06_L_72AF(void) {
  p06_L_7285();
  p06_L_72B2();
  return;
}

/* flash page 6 cpu 0x72B2 (offset 0x32B2) */
void p06_L_72B2(void) {
  cpu_push_af();
  e = a;
  d = 0x5E;
  p00_L_3DB9();
  p00_L_3C93();
  p00_L_019D();
  if (flag_z()) goto lab_p06_L_72D0;
  a = 0x28;
  p00_L_3F9F();
  a = 0x01;
  p00_L_3F9F();
  a = 0x29;
  p00_L_3F9F();
  lab_p06_L_72D0: ;
  cpu_pop_af();
  cpu_push_af();
  p06_L_6F4F();
  p00_rst10();
  a = 0x08;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_2FDF();
  if (flag_nz()) goto lab_p06_L_72EC;
  a = 0x7F;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p06_L_72E9;
  a = 0x3D;
  lab_p06_L_72E9: ;
  p00_L_3F9F();
  lab_p06_L_72EC: ;
  cpu_pop_af();
  return;
}

/* flash page 6 cpu 0x72EE (offset 0x32EE) */
void p06_L_72EE(void) {
  set_bc(0x0000);
  cpu_push_de();
  cpu_push_bc();
  lab_p06_L_72F3: ;
  p06_L_4463();
  if (flag_z()) goto lab_p06_L_730B;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p00_L_3DAD();
  cpu_pop_de();
  cpu_pop_bc();
  l = a;
  h = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_bc();
  cpu_push_bc();
  cpu_push_hl();
  cpu_ex_de_hl();
  d = b;
  e = c;
  goto lab_p06_L_72F3;
  lab_p06_L_730B: ;
  cpu_pop_de();
  cpu_pop_af();
  return;
}

/* flash page 6 cpu 0x7328 (offset 0x3328) */
void p06_L_7328(void) {
  set_hl(0x844C);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  return;
}

/* flash page 6 cpu 0x7331 (offset 0x3331) */
void p06_L_7331(void) {
  p06_L_7328();
  p06_L_6BC1();
  p06_L_7337();
  return;
}

/* flash page 6 cpu 0x7337 (offset 0x3337) */
void p06_L_7337(void) {
  set_hl(0x844C);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  return;
}

/* flash page 6 cpu 0x7421 (offset 0x3421) */
void p06_L_7421(void) {
  a = mem_read8(0x96FC);
  mem_write8(0x844C, a);
  return;
}

/* flash page 6 cpu 0x7447 (offset 0x3447) */
void p06_L_7447(void) {
  set_hl(0x75AD);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) p06_L_748C();
  p06_L_75C4();
  p06_L_75D2();
  p00_L_3D0B();
  set_hl(0x78FF);
  a = 0x1E;
  p06_L_7466();
  return;
}

/* flash page 6 cpu 0x7466 (offset 0x3466) */
void p06_L_7466(void) {
  mem_write16(0x979F, hl());
  mem_write8(0x97A1, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x97A2, a);
  p06_L_777A();
  p06_L_7473();
  return;
}

/* flash page 6 cpu 0x7473 (offset 0x3473) */
void p06_L_7473(void) {
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  a = mem_read8(0x97A1);
  b = a;
  set_de(0x000F);
  /* ld ix,(0x979F) */
  lab_p06_L_7482: ;
  a = a | a;
  flag_logic(a);
  p06_L_77F2();
  /* add ix,de */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_7482;
  return;
}

/* flash page 6 cpu 0x748C (offset 0x348C) */
void p06_L_748C(void) {
  p00_L_3D71();
  a = mem_read8((uint16_t)(iy + 0x0C));
  mem_write8(0x85E4, a);
  a = mem_read8((uint16_t)(iy + 0x0D));
  mem_write8(0x85E3, a);
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 5)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  return;
}

/* flash page 6 cpu 0x74A4 (offset 0x34A4) */
void p06_L_74A4(void) {
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_74BD;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_74BD;
  a = 0x04;
  mem_write8(0x97A5, a);
  p00_L_3E55();
  lab_p06_L_74BD: ;
  p00_L_3D7D();
  a = mem_read8(0x85E3);
  mem_write8((uint16_t)(iy + 0x0D), a);
  a = mem_read8(0x85E4);
  mem_write8((uint16_t)(iy + 0x0C), a);
  cpu_pop_af();
  return;
}

/* flash page 6 cpu 0x74CE (offset 0x34CE) */
void p06_L_74CE(void) {
  goto lab_p06_L_74CE;
  lab_p06_L_74C0: ;
  a = mem_read8(0x85E3);
  mem_write8((uint16_t)(iy + 0x0D), a);
  a = mem_read8(0x85E4);
  mem_write8((uint16_t)(iy + 0x0C), a);
  cpu_pop_af();
  return;
  lab_p06_L_74CE: ;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_74E7;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_74E7;
  a = 0x04;
  mem_write8(0x97A5, a);
  p00_L_3E55();
  lab_p06_L_74E7: ;
  p00_L_3EF1();
  goto lab_p06_L_74C0;
}

/* flash page 6 cpu 0x74EC (offset 0x34EC) */
void p06_L_74EC(void) {
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  p00_L_3D0B();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 3)));
  a = mem_read8(0x859A);
  flag_cmp(a, 0x4B);
  if (flag_z()) goto lab_p06_L_7570;
  p00_L_18B7();
  if (flag_z()) goto lab_p06_L_751B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p06_L_7527;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 2)));
  p06_L_7E69();
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  goto lab_p06_L_7524;
  lab_p06_L_751B: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p06_L_7527;
  p06_L_7E64();
  lab_p06_L_7524: ;
  p00_L_0087();
  lab_p06_L_7527: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_753D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 6)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 2)));
  a = 0x01;
  mem_write8(0x91DC, a);
  goto lab_p06_L_7542;
  lab_p06_L_753D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 6)) == 0);
  if (flag_z()) return;
  lab_p06_L_7542: ;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) | (1u << 2)));
  p06_L_7546();
  return;
  lab_p06_L_7570: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p06_L_7586;
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p06_L_758C;
  p06_L_757C();
  return;
  lab_p06_L_7586: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 6)) == 0);
  if (flag_nz()) { p06_L_759E(); return; }
  lab_p06_L_758C: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p06_L_7599;
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 6)) == 0);
  if (flag_z()) return;
  p06_L_759E();
  return;
  lab_p06_L_7599: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 6)) == 0);
  if (flag_nz()) return;
  p06_L_759E();
  return;
}

/* flash page 6 cpu 0x7546 (offset 0x3546) */
void p06_L_7546(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_7556;
  p00_L_18B7();
  if (flag_nz()) goto lab_p06_L_756D;
  p06_L_7E64();
  goto lab_p06_L_756D;
  lab_p06_L_7556: ;
  set_hl(0x0004);
  mem_write16(0x844B, hl());
  a = 0x04;
  mem_write8(0x97A5, a);
  p00_L_3D11();
  p00_L_3D65();
  set_hl(0x7E5F);
  p06_L_7E6C();
  lab_p06_L_756D: ;
  p00_L_0087();
  return;
}

/* flash page 6 cpu 0x757C (offset 0x357C) */
void p06_L_757C(void) {
  a = 0x00;
  mem_write8(0x91E0, a);
  p00_L_318F();
  p06_L_759E();
  return;
}

/* flash page 6 cpu 0x759E (offset 0x359E) */
void p06_L_759E(void) {
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) | (1u << 6)));
  return;
}

/* flash page 6 cpu 0x75A3 (offset 0x35A3) */
void p06_L_75A3(void) {
  set_hl(mem_read16(0x858D));
  set_de(0x76BD);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  return;
}

/* flash page 6 cpu 0x75BA (offset 0x35BA) */
void p06_L_75BA(void) {
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 6)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 4)) == 0);
  goto lab_p06_L_75CC;
  lab_p06_L_75CC: ;
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 6)));
  return;
}

/* flash page 6 cpu 0x75C4 (offset 0x35C4) */
void p06_L_75C4(void) {
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 6)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 6)));
  return;
}

/* flash page 6 cpu 0x75D2 (offset 0x35D2) */
void p06_L_75D2(void) {
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 4)));
  p00_L_18B7();
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) | (1u << 4)));
  return;
}

/* flash page 6 cpu 0x75DF (offset 0x35DF) */
void p06_L_75DF(void) {
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 6)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 5)) == 0);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 6)));
  return;
}

/* flash page 6 cpu 0x75ED (offset 0x35ED) */
void p06_L_75ED(void) {
  set_hl(0x7628);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) p06_L_748C();
  p06_L_75C4();
  p06_L_75D2();
  p00_L_3D0B();
  p06_L_7612();
  a = 0;
  flag_logic(a);
  mem_write8(0x97A2, a);
  p06_L_777A();
  return;
}

/* flash page 6 cpu 0x7612 (offset 0x3612) */
void p06_L_7612(void) {
  p06_L_7618();
  p06_L_7466();
  return;
}

/* flash page 6 cpu 0x7618 (offset 0x3618) */
void p06_L_7618(void) {
  set_hl(0x7AC1);
  a = 0x0C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 7)) == 0);
  if (flag_z()) return;
  set_hl(0x7B75);
  a = 0x11;
  return;
}

/* flash page 6 cpu 0x7635 (offset 0x3635) */
void p06_L_7635(void) {
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p06_L_7647();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 6 cpu 0x7641 (offset 0x3641) */
void p06_L_7641(void) {
  set_hl(0x7628);
  p00_L_07CC();
  p06_L_7647();
  return;
}

/* flash page 6 cpu 0x7647 (offset 0x3647) */
void p06_L_7647(void) {
  set_hl(0x7CB0);
  a = 0x02;
  p06_L_7466();
  return;
}

/* flash page 6 cpu 0x764F (offset 0x364F) */
void p06_L_764F(void) {
  set_hl(0x7628);
  p00_L_07CC();
  p06_L_75BA();
  p06_L_75DF();
  p06_L_76B5();
  return;
}

/* flash page 6 cpu 0x765F (offset 0x365F) */
void p06_L_765F(void) {
  set_hl(0x7628);
  p00_L_07CC();
  p06_L_75BA();
  p06_L_75DF();
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) p06_L_748C();
  p00_L_3E8B();
  set_hl(0x7E34);
  set_de(0x848E);
  p00_L_1185();
  p00_L_1185();
  p00_L_3711();
  a = 0x01;
  p06_L_7690();
  set_hl(0x7C74);
  p06_L_76B8();
  return;
}

/* flash page 6 cpu 0x768A (offset 0x368A) */
void p06_L_768A(void) {
  mem_write8(hl(), h);
  a = h;
  p06_L_76B8();
  return;
}

/* flash page 6 cpu 0x7690 (offset 0x3690) */
void p06_L_7690(void) {
  mem_write8(0x844B, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  set_hl(0x7E45);
  a = 0x15;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p06_L_78EF();
  set_hl(0x7E4D);
  a = 0x16;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p06_L_7D1E();
  return;
}

/* flash page 6 cpu 0x76B5 (offset 0x36B5) */
void p06_L_76B5(void) {
  set_hl(0x7CCE);
  p06_L_76B8();
  return;
}

/* flash page 6 cpu 0x76B8 (offset 0x36B8) */
void p06_L_76B8(void) {
  a = 0x04;
  p06_L_7466();
  return;
}

/* flash page 6 cpu 0x76BD (offset 0x36BD) */
void p06_L_76BD(void) {
  /* ld ix,(0x97A3) */
  b = a;
  a = 0x03;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_3123();
  a = b;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p06_L_7757;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p06_L_7722;
  a = 0;
  flag_logic(a);
  mem_write8(0x8479, a);
  a = (uint8_t)(a + 1);
  mem_write8(0x8478, a);
  /* ld ixl,(ix+0x07) */
  /* ld ixh,(ix+0x08) */
  a = mem_read8(hl());
  flag_cmp(a, 0x30);
  if (flag_c()) goto lab_p06_L_7707;
  flag_cmp(a, 0x3A);
  if (flag_nc()) goto lab_p06_L_7707;
  set_hl(0x0002);
  mem_write16(0x8478, hl());
  a = 0x73;
  mem_write8(0x847A, a);
  a = mem_read8((uint16_t)(ix + 0x0D));
  p00_L_3BBB();
  set_hl(0x847B);
  p06_L_78DB();
  goto lab_p06_L_7713;
  lab_p06_L_7707: ;
  a = mem_read8((uint16_t)(ix + 0x0E));
  mem_write8(0x8446, a);
  a = mem_read8((uint16_t)(ix + 0x0D));
  lab_p06_L_7710: ;
  p06_L_78C3();
  lab_p06_L_7713: ;
  p06_L_74A4();
  p00_L_3F5D();
  a = mem_read8(0x89F5);
  a = a & 0x10;
  flag_logic(a);
  mem_write8(0x85C2, a);
  return;
  lab_p06_L_7722: ;
  p06_L_7728();
  p06_L_7473();
  return;
  lab_p06_L_7757: ;
  flag_cmp(a, 0x01);
  if (flag_c()) goto lab_p06_L_7795;
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p06_L_7795;
  a = (uint8_t)(a - 1);
  e = a;
  d = 0x00;
  /* add ix,de */
  a = mem_read8(ix);
  mem_write8(0x97A2, a);
  flag_cmp(a, 0xFE);
  if (flag_nz()) { p06_L_777A(); return; }
  a = mem_read8(0x859A);
  flag_cmp(a, 0x4B);
  if (flag_z()) { p00_L_3609(); return; }
  p00_L_360F();
  return;
  lab_p06_L_7795: ;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p06_L_77A7;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_z()) { p00_L_05F1(); return; }
  p06_L_77A0();
  return;
  lab_p06_L_77A7: ;
  flag_cmp(a, 0x27);
  if (flag_nz()) goto lab_p06_L_77C8;
  p06_L_74EC();
  a = mem_read8(0x859A);
  flag_cmp(a, 0x48);
  if (flag_z()) { p00_L_3A35(); return; }
  flag_cmp(a, 0x57);
  if (flag_z()) { p06_L_75ED(); return; }
  flag_cmp(a, 0x4B);
  if (flag_z()) { p00_L_3A47(); return; }
  flag_cmp(a, 0x53);
  if (flag_z()) { p00_L_3A77(); return; }
  p06_L_7447();
  return;
  lab_p06_L_77C8: ;
  flag_cmp(a, 0xAC);
  if (flag_nz()) goto lab_p06_L_77DA;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_77DA;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x45);
  if (flag_z()) { p00_L_3825(); return; }
  lab_p06_L_77DA: ;
  flag_cmp(a, 0x5A);
  if (flag_nz()) goto lab_p06_L_77E5;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_7710;
  lab_p06_L_77E5: ;
  flag_cmp(a, 0x5A);
  if (flag_c()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_z()) { p00_L_05F2(); return; }
  p06_L_77A0();
  return;
}

/* flash page 6 cpu 0x7728 (offset 0x3728) */
void p06_L_7728(void) {
  a = mem_read8(0x859A);
  flag_cmp(a, 0x45);
  if (flag_nz()) goto lab_p06_L_7754;
  a = mem_read8(0x97A2);
  flag_cmp(a, 0x10);
  if (flag_c()) goto lab_p06_L_7754;
  if (flag_z()) goto lab_p06_L_7748;
  flag_cmp(a, 0x12);
  if (flag_z()) goto lab_p06_L_774C;
  flag_cmp(a, 0x11);
  if (flag_z()) goto lab_p06_L_7750;
  flag_cmp(a, 0x13);
  if (flag_nz()) goto lab_p06_L_7754;
  p00_L_3855();
  return;
  lab_p06_L_7748: ;
  p00_L_3843();
  return;
  lab_p06_L_774C: ;
  p00_L_384F();
  return;
  lab_p06_L_7750: ;
  p00_L_3849();
  return;
  lab_p06_L_7754: ;
  p06_L_7869();
  return;
}

/* flash page 6 cpu 0x777A (offset 0x377A) */
void p06_L_777A(void) {
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

/* flash page 6 cpu 0x77A0 (offset 0x37A0) */
void p06_L_77A0(void) {
  p06_L_74A4();
  p00_L_3F5D();
  return;
}

/* flash page 6 cpu 0x77F2 (offset 0x37F2) */
void p06_L_77F2(void) {
  cpu_push_bc();
  a = mem_read8(0x89F5);
  cpu_push_af();
  /* ld ixl,(ix+0x04) */
  /* ld ixh,(ix+0x05) */
  mem_write16(0x844B, hl());
  if (flag_nc()) goto lab_p06_L_7828;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_7815;
  a = 0x00;
  /* ld ixh,(ix+0x0D) */
  /* ld ixl,(ix+0x0E) */
  p00_L_3C45();
  if (flag_z()) goto lab_p06_L_7818;
  lab_p06_L_7815: ;
  a = mem_read8((uint16_t)(ix + 0x06));
  lab_p06_L_7818: ;
  a = a & 0x0F;
  flag_logic(a);
  b = a;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  a = 0x20;
  lab_p06_L_7821: ;
  p00_L_3F9F();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_7821;
  goto lab_p06_L_7863;
  lab_p06_L_7828: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p06_L_7843;
  /* ld ixl,(ix+0x09) */
  /* ld ixh,(ix+0x0A) */
  a = mem_read8(hl());
  /* and (ix+0x0C) */
  /* cp (ix+0x0B) */
  if (flag_nz()) goto lab_p06_L_7843;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  goto lab_p06_L_7847;
  lab_p06_L_7843: ;
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 0)));
  lab_p06_L_7847: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p06_L_785A;
  a = 0x01;
  /* ld ixh,(ix+0x0D) */
  /* ld ixl,(ix+0x0E) */
  p00_L_3C45();
  if (flag_z()) goto lab_p06_L_7863;
  lab_p06_L_785A: ;
  /* ld ixl,(ix+0x07) */
  /* ld ixh,(ix+0x08) */
  p06_L_7D1E();
  lab_p06_L_7863: ;
  cpu_pop_af();
  mem_write8(0x89F5, a);
  cpu_pop_bc();
  return;
}

/* flash page 6 cpu 0x7869 (offset 0x3869) */
void p06_L_7869(void) {
  /* ld ixl,(ix+0x09) */
  /* ld ixh,(ix+0x0A) */
  a = mem_read8(0x859A);
  flag_cmp(a, 0x49);
  if (flag_nz()) goto lab_p06_L_787C;
  a = mem_read8(hl());
  a = a ^ 0x01;
  flag_logic(a);
  goto lab_p06_L_78A8;
  lab_p06_L_787C: ;
  a = mem_read8((uint16_t)(ix + 0x0E));
  flag_cmp(a, 0x6F);
  if (flag_nz()) goto lab_p06_L_7887;
  a = 0x00;
  goto lab_p06_L_788D;
  lab_p06_L_7887: ;
  flag_cmp(a, 0x70);
  if (flag_nz()) goto lab_p06_L_7898;
  a = 0x06;
  lab_p06_L_788D: ;
  b = 0x19;
  cpu_push_hl();
  set_hl(0x9776);
  lab_p06_L_7893: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_7893;
  cpu_pop_hl();
  lab_p06_L_7898: ;
  a = mem_read8(hl());
  /* and (ix+0x0C) */
  /* cp (ix+0x0B) */
  if (flag_z()) return;
  a = mem_read8((uint16_t)(ix + 0x0C));
  a = a ^ 0xFF;
  /* and (hl) */
  /* or (ix+0x0B) */
  lab_p06_L_78A8: ;
  mem_write8(hl(), a);
  flag_set_z((mem_read8((uint16_t)(ix + 0x06)) & (1u << 6)) == 0);
  if (flag_nz()) p06_L_759E();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 1)) == 0);
  if (flag_nz()) p06_L_6250();
  flag_set_z((mem_read8((uint16_t)(ix + 0x06)) & (1u << 7)) == 0);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 1)));
  p00_L_009B();
  return;
}

/* flash page 6 cpu 0x78C3 (offset 0x38C3) */
void p06_L_78C3(void) {
  p00_L_3BBB();
  set_hl(0x0001);
  mem_write16(0x8478, hl());
  set_hl(0x847A);
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p06_L_78DB(); return; }
  p06_L_78EA();
  a = 0x02;
  mem_write8(0x8478, a);
  p06_L_78DB();
  return;
}

/* flash page 6 cpu 0x78CD (offset 0x38CD) */
void p06_L_78CD(void) {
  a = d;
  a = (uint8_t)(a + h);
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p06_L_78DB(); return; }
  p06_L_78EA();
  a = 0x02;
  mem_write8(0x8478, a);
  p06_L_78DB();
  return;
}

/* flash page 6 cpu 0x78DB (offset 0x38DB) */
void p06_L_78DB(void) {
  a = e;
  mem_write8(hl(), a);
  set_hl(0x8478);
  a = 0x05;
  p06_L_5DF9();
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) | (1u << 7)));
  return;
}

/* flash page 6 cpu 0x78EA (offset 0x38EA) */
void p06_L_78EA(void) {
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  return;
}

/* flash page 6 cpu 0x78EF (offset 0x38EF) */
void p06_L_78EF(void) {
  p06_L_7D1E();
  set_hl(0x844B);
  p06_L_78F5();
  return;
}

/* flash page 6 cpu 0x78F5 (offset 0x38F5) */
void p06_L_78F5(void) {
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = 0;
  flag_logic(a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  return;
}

/* flash page 6 cpu 0x7911 (offset 0x3911) */
void p06_L_7911(void) {
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  cpu_rlca();
  set_bc((uint16_t)(bc() + 1));
  /* jp 0xFA7D - other page/RAM */
}

/* flash page 6 cpu 0x793A (offset 0x393A) */
void p06_L_793A(void) {
  d = d;
  b = (uint8_t)(b - 1);
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  c = 0x01;
  b = 0x01;
  /* scf */
  a = l;
  a = a | b;
  flag_logic(a);
  a = 0;
  flag_logic(a);
  /* nop */
  p00_rst38_isr();
  /* adc a,(hl) */
  /* nop */
  b = 0x04;
  /* nop */
  c = 0x01;
  cpu_rlca();
  set_bc(0x7D39);
  a = a | b;
  flag_logic(a);
  a = 0;
  flag_logic(a);
  set_bc(0x8FFF);
  /* nop */
  cpu_rlca();
  b = (uint8_t)(b - 1);
  /* nop */
  c = 0x01;
  cpu_ex_af();
  set_bc(0x7D3B);
  a = a | b;
  flag_logic(a);
  a = 0;
  flag_logic(a);
  mem_write8(bc(), a);
  p00_rst38_isr();
  a = (uint8_t)(a - b);
  /* nop */
  cpu_ex_af();
  b = 0x00;
  c = 0x01;
  set_hl((uint16_t)(hl() + bc()));
  set_bc(0x7D3D);
  a = a | b;
  flag_logic(a);
  a = 0;
  flag_logic(a);
  set_bc((uint16_t)(bc() + 1));
  p00_rst38_isr();
  a = (uint8_t)(a - c);
  /* nop */
  set_hl((uint16_t)(hl() + bc()));
  cpu_rlca();
  /* nop */
  c = 0x01;
  a = mem_read8(bc());
  set_bc(0x7D3F);
  a = a | b;
  flag_logic(a);
  a = 0;
  flag_logic(a);
  b = (uint8_t)(b + 1);
  p00_rst38_isr();
  a = (uint8_t)(a - d);
  /* nop */
  a = mem_read8(bc());
  cpu_ex_af();
  /* nop */
  c = 0x01;
  set_bc((uint16_t)(bc() - 1));
  set_bc(0x7D41);
  a = a | b;
  flag_logic(a);
  a = 0;
  flag_logic(a);
  b = (uint8_t)(b - 1);
  p00_rst38_isr();
  a = (uint8_t)(a - e);
  /* nop */
  set_bc((uint16_t)(bc() - 1));
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  c = 0x01;
  c = (uint8_t)(c + 1);
  set_bc(0x7D43);
  a = a | b;
  flag_logic(a);
  a = 0;
  flag_logic(a);
  b = 0xFF;
  a = (uint8_t)(a - h);
  /* nop */
  c = (uint8_t)(c + 1);
  a = mem_read8(bc());
  /* nop */
  c = 0x01;
  c = (uint8_t)(c - 1);
  set_bc(0x7D45);
  a = a | b;
  flag_logic(a);
  a = 0;
  flag_logic(a);
  cpu_rlca();
  p00_rst38_isr();
  a = (uint8_t)(a - l);
  /* nop */
  c = (uint8_t)(c - 1);
  set_bc((uint16_t)(bc() - 1));
  /* nop */
  c = 0x01;
  c = 0x01;
  b = a;
  a = l;
  a = a | b;
  flag_logic(a);
  a = 0;
  flag_logic(a);
  cpu_ex_af();
  p00_rst38_isr();
  /* sub (hl) */
  /* nop */
  c = (uint8_t)(c - 1);
  c = (uint8_t)(c + 1);
  /* nop */
  c = 0x01;
  cpu_rrca();
  set_bc(0x7D49);
  a = a | b;
  flag_logic(a);
  a = 0;
  flag_logic(a);
  set_hl((uint16_t)(hl() + bc()));
  p00_rst38_isr();
  a = 0;
  flag_logic(a);
  /* nop */
  cpu_rrca();
  c = 0x03;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_79D8;
  /* nop */
  a = (uint8_t)(a + 0x0A);
  lab_p06_L_79D8: ;
  a = mem_read8(bc());
  a = mem_read8(hl());
  if (flag_p()) return;
  /* adc a,c */
  /* nop */
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x4D);
  cpu_rrca();
  c = 0x03;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_79E7;
  cpu_rlca();
  a = (uint8_t)(a + 0x70);
  lab_p06_L_79E7: ;
  mem_write8(hl(), b);
  a = l;
  if (flag_p()) return;
  /* adc a,c */
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x4E);
  set_de(0x0E10);
  d = (uint8_t)(d + 1);
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  a = (uint8_t)(a + h);
  /* adc a,a */
  a = l;
  if (flag_p()) { p00_L_1089(); return; }
  if (flag_p()) return;
  flag_cmp(a, 0x56);
  mem_write8(de(), a);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_7A0F;
  d = (uint8_t)(d + 1);
  set_bc((uint16_t)(bc() + 1));
  b = (uint8_t)(b - 1);
  a = (uint8_t)(a + e);
  l = (uint8_t)(l + 1);
  a = mem_read8(hl());
  if (flag_p()) { p06_L_4089(); return; }
  if (flag_p()) return;
  flag_cmp(a, 0x57);
  set_de((uint16_t)(de() + 1));
  set_de(0x140E);
  lab_p06_L_7A0F: ;
  c = 0x14;
  set_bc((uint16_t)(bc() + 1));
  set_hl((uint16_t)(hl() + bc()));
  a = (uint8_t)(a + e);
  if (flag_nc()) goto lab_p06_L_7A94;
  if (flag_p()) { p00_L_2089(); return; }
  if (flag_p()) return;
  flag_cmp(a, 0x58);
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  c = 0x14;
  set_bc((uint16_t)(bc() + 1));
  c = (uint8_t)(c - 1);
  a = (uint8_t)(a + e);
  b = 0x7E;
  if (flag_p()) { os_banked_call(0x8089); return; }
  if (flag_p()) return;
  flag_cmp(a, 0x59);
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_7A45;
  b = (uint8_t)(b + 1);
  /* nop */
  /* adc a,c */
  a = e;
  a = l;
  if (flag_p()) p00_L_0089();
  set_bc(0x6FFE);
  d = (uint8_t)(d - 1);
  d = (uint8_t)(d + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_7A54;
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  a = (uint8_t)(a + e);
  mem_write8(hl(), a);
  a = l;
  if (flag_p()) p00_L_0189();
  lab_p06_L_7A45: ;
  set_bc(0xFE01);
  set_bc(0x70FE);
  mem_write8(hl(), b);
  cpu_rla();
  d = 0x14;
  goto lab_p06_L_7A53;
  lab_p06_L_7A53: ;
  /* adc a,c */
  lab_p06_L_7A54: ;
  /* nop */
  mem_write8(bc(), a);
  flag_cmp(a, 0x69);
  cpu_rla();
  d = 0x14;
  goto lab_p06_L_7A62;
  lab_p06_L_7A62: ;
  /* adc a,c */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  flag_cmp(a, 0x6A);
  set_hl((uint16_t)(hl() + de()));
  goto lab_p06_L_7A80;
  lab_p06_L_7A80: ;
  /* adc a,c */
  b = b;
  if (flag_po()) return;
  flag_cmp(a, 0xAE);
  a = mem_read8(de());
  set_hl((uint16_t)(hl() + de()));
  d = 0x1B;
  b = 0x0A;
  a = (uint8_t)(a + l);
  /* nop */
  a = mem_read8(hl());
  if (flag_m()) { os_banked_call(0x8089); return; }
  if (flag_po()) return;
  flag_cmp(a, 0xAD);
  lab_p06_L_7A94: ;
  e = (uint8_t)(e + 1);
  set_de((uint16_t)(de() - 1));
  goto lab_p06_L_7AB3;
  lab_p06_L_7AB3: ;
  e = (uint8_t)(e + 1);
  goto lab_p06_L_7AD3;
  lab_p06_L_7AD3: ;
  mem_write8(bc(), a);
  /* nop */
  cpu_rlca();
  cpu_rlca();
  a = mem_read8(de());
  a = mem_read8(hl());
  if (flag_p()) p00_L_0889();
  cpu_ex_af();
  flag_cmp(a, 0x6B);
  set_bc((uint16_t)(bc() + 1));
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  set_bc(0x0700);
  l = b;
  a = l;
  if (flag_p()) p00_L_0089();
  lab_p06_L_7AEB: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_7AEB;
  l = l;
  set_bc((uint16_t)(bc() + 1));
  mem_write8(bc(), a);
  /* nop */
  b = (uint8_t)(b + 1);
  set_bc(0x0808);
  e = a;
  a = l;
  if (flag_p()) p00_L_1089();
  lab_p06_L_7AFA: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p06_L_7AFA;
  l = mem_read8(hl());
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = 0x02;
  /* nop */
  a = (uint8_t)(a + a);
  a = (uint8_t)(a - h);
  a = l;
  if (flag_p()) p00_L_0089();
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x74);
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b + 1);
  mem_write8(bc(), a);
  b = 0x02;
  cpu_ex_af();
  /* add a,(hl) */
  /* sbc a,h */
  a = l;
  if (flag_p()) p00_L_0489();
  b = (uint8_t)(b + 1);
  flag_cmp(a, 0x73);
  cpu_rlca();
  b = 0x04;
  cpu_ex_af();
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* add a,(hl) */
  e = b;
  a = l;
  if (flag_p()) p00_L_0089();
  lab_p06_L_7B27: ;
  if (flag_nz()) goto lab_p06_L_7B27;
  mem_write8(hl(), c);
  cpu_rlca();
  b = 0x04;
  cpu_ex_af();
  set_bc((uint16_t)(bc() + 1));
  cpu_rlca();
  a = (uint8_t)(a + a);
  d = b;
  a = l;
  if (flag_p()) p00_L_2089();
  lab_p06_L_7B36: ;
  if (flag_nz()) goto lab_p06_L_7B36;
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_af();
  b = 0x0A;
  b = (uint8_t)(b + 1);
  /* nop */
  cpu_ex_af();
  a = a & e;
  flag_logic(a);
  a = l;
  if (flag_p()) p00_L_0089();
  b = b;
  flag_cmp(a, 0x76);
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_af();
  b = 0x0A;
  b = (uint8_t)(b + 1);
  set_hl((uint16_t)(hl() + bc()));
  cpu_rlca();
  a = a ^ h;
  flag_logic(a);
  a = l;
  if (flag_p()) p06_L_4089();
  b = b;
  flag_cmp(a, 0x75);
  set_bc((uint16_t)(bc() - 1));
  a = mem_read8(bc());
  cpu_ex_af();
  a = mem_read8(bc());
  b = (uint8_t)(b - 1);
  /* nop */
  b = 0xBC;
  a = l;
  cpu_ex_af();
  /* adc a,d */
  /* nop */
  set_bc(0xB5FE);
  set_bc((uint16_t)(bc() - 1));
  a = mem_read8(bc());
  cpu_ex_af();
  set_bc((uint16_t)(bc() - 1));
  b = (uint8_t)(b - 1);
  cpu_rlca();
  cpu_rlca();
  a = a | h;
  flag_logic(a);
  a = l;
  cpu_ex_af();
  /* adc a,d */
  set_bc(0xFE01);
  /* or (hl) */
  set_bc(0x0000);
  b = (uint8_t)(b - 1);
  /* nop */
  /* nop */
  if (flag_nz()) p06_L_7E15();
  p00_rst38_isr();
  /* adc a,c */
  /* nop */
  e = (uint8_t)(e - 1);
  flag_cmp(a, 0xF0);
  mem_write8(bc(), a);
  /* nop */
  set_bc(0x0005);
  b = (uint8_t)(b + 1);
  p06_L_7DE7();
  return;
}

/* flash page 6 cpu 0x7D0A (offset 0x3D0A) */
void p06_L_7D0A(void) {
  mem_write8(0x844B, a);
  a = 0x01;
  mem_write8(0x844C, a);
  set_hl(0x7E40);
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p06_L_7D1E();
  return;
}

/* flash page 6 cpu 0x7D1E (offset 0x3D1E) */
void p06_L_7D1E(void) {
  cpu_push_bc();
  cpu_push_af();
  a = mem_read8(0x97A6);
  b = a;
  lab_p06_L_7D24: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  /* scf */
  if (flag_z()) goto lab_p06_L_7D33;
  p00_L_3F9F();
  a = mem_read8(0x844B);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p06_L_7D24;
  lab_p06_L_7D33: ;
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  return;
}

/* flash page 6 cpu 0x7DE7 (offset 0x3DE7) */
void p06_L_7DE7(void) {
  d = a;
  h = l;
  h = d;
  /* nop */
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  b = (uint8_t)(b + 1);
  /* nop */
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  /* nop */
  d = d;
  h = l;
  h = e;
  mem_write8(hl(), h);
  b = a;
  b = e;
  /* nop */
  h = c;
  set_hl((uint16_t)(hl() - 1));
  h = d;
  p00_rst10();
  /* nop */
  mem_write8(hl(), d);
  a = hw_in(0x5E);
  e = e;
  p00_rst10();
  /* nop */
  d = e;
  h = l;
  mem_write8(hl(), c);
  /* nop */
  d = d;
  h = c;
  h = h;
  l = c;
  h = c;
  l = mem_read8(hl());
  /* nop */
  b = c;
  mem_write8(hl(), e);
  l = e;
  /* nop */
  p06_L_7E15();
  return;
}

/* flash page 6 cpu 0x7E15 (offset 0x3E15) */
void p06_L_7E15(void) {
  d = h;
  l = c;
  l = l;
  h = l;
  /* nop */
  d = b;
  l = a;
  l = h;
  h = c;
  mem_write8(hl(), d);
  b = a;
  b = e;
  /* nop */
  b = d;
  b = l;
  b = a;
  c = c;
  c = mem_read8(hl());
  /* nop */
  b = l;
  c = mem_read8(hl());
  b = h;
  /* nop */
  d = b;
  h = c;
  mem_write8(hl(), d);
  /* nop */
  d = b;
  l = a;
  l = h;
  /* nop */
  p06_str_6();
  return;
}

/* flash page 6 cpu 0x7E34 (offset 0x3E34) */
void p06_str_6(void) {
  goto lab_p06_str_6;
  lab_p06_L_4400: ;
  if (flag_z()) return;
  cpu_push_hl();
  cpu_push_de();
  p06_L_445C();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_push_af();
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_4434;
  cpu_pop_af();
  if (flag_c()) goto lab_p06_L_4431;
  cpu_push_de();
  cpu_push_hl();
  set_hl(mem_read16(0x96F8));
  set_de(mem_read16(0x96FA));
  p00_L_192A();
  if (flag_nz()) goto lab_p06_L_4427;
  set_hl(mem_read16(0x96F6));
  set_hl((uint16_t)(hl() + 1));
  p06_L_44C1();
  goto lab_p06_L_442A;
  lab_p06_L_4427: ;
  p06_L_44BE();
  lab_p06_L_442A: ;
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_nz()) goto lab_p06_L_4430;
  a = 0;
  flag_logic(a);
  return;
  lab_p06_L_4430: ;
  a = 0;
  flag_logic(a);
  lab_p06_L_4431: ;
  cpu_push_af();
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_4434: ;
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96F6, hl());
  p06_L_444C();
  cpu_pop_af();
  if (flag_c()) p06_L_4443();
  a = a | 0x01;
  flag_logic(a);
  return;
  lab_p06_str_6: ;
  d = h;
  b = c;
  b = d;
  c = h;
  b = l;
  if (flag_nz()) goto lab_p06_L_7E8E;
  b = l;
  d = h;
  d = l;
  d = b;
  /* nop */
  p06_str_9();
  return;
  lab_p06_L_7E8E: ;
  a = (uint8_t)(a - h);
  a = 0;
  flag_logic(a);
  /* add a,(hl) */
  flag_cmp(a, e);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  /* nop */
  /* adc a,l */
  a = (uint8_t)(a - b);
  a = (uint8_t)(a - e);
  /* sub (hl) */
  a = (uint8_t)(a + l);
  flag_cmp(a, c);
  l = (uint8_t)(l - 1);
  sp = 0x8F8E;
  a = (uint8_t)(a - d);
  a = (uint8_t)(a - l);
  /* adc a,e */
  a = a | a;
  flag_logic(a);
  l = (uint8_t)(l + 1);
  a = a | h;
  flag_logic(a);
  /* nop */
  /* adc a,d */
  flag_cmp(a, a);
  cpu_pop_bc();
  flag_cmp(a, l);
  /* or (hl) */
  mem_write8(0x4400, a);
  e = d;
  l = 0x48;
  c = c;
  /* nop */
  b = l;
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  c = 0x0F;
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  c = (uint8_t)(c - 1);
  mem_write8(hl(), 0x88);
  a = (uint8_t)(a + a);
  os_bcall(0x09B5);
  /* nop */
  cpu_push_bc();
  cpu_push_af();
  if (flag_m()) return;
  /* ei */
  /* db 0xED,0xBC */
  if (flag_c()) goto lab_p06_L_7ECC;
  lab_p06_L_7ECC: ;
  a = a ^ 0xF4;
  flag_logic(a);
  p00_rst30();
  if (flag_m()) { os_banked_call(0xBAEC); return; }
  a = a ^ 0xFF;
  a = mem_read8(0xF33E);
  a = a | 0xF9;
  flag_logic(a);
  /* sbc a,b */
  flag_cmp(a, b);
  set_hl((uint16_t)(hl() + sp));
  b = c;
  /* nop */
  c = (uint8_t)(c + 1);
  if (flag_nz()) return;
  if (flag_nz()) { p00_L_37BE(); return; }
  sp = (uint16_t)(sp + 1);
  /* nop */
  c = d;
  sp = (uint16_t)(sp - 1);
  d = a;
  c = e;
  if (flag_nc()) goto lab_p06_L_7EEA;
  lab_p06_L_7EEA: ;
  b = b;
  set_bc((uint16_t)(bc() - 1));
  cpu_ex_af();
  mem_write8(bc(), a);
  set_bc(0x0007);
  /* nop */
  /* nop */
  /* nop */
  b = 0xCB;
  a = a | b;
  flag_logic(a);
  a = a ^ e;
  flag_logic(a);
  /* and (hl) */
  a = a & c;
  flag_logic(a);
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  if (flag_z()) { os_banked_call(0xAFCC); return; }
  a = a ^ d;
  flag_logic(a);
  a = a & l;
  flag_logic(a);
  a = a & b;
  flag_logic(a);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  /* nop */
  a = (uint8_t)(a + 0xB3);
  /* xor (hl) */
  a = a ^ c;
  flag_logic(a);
  a = a & h;
  flag_logic(a);
  /* sbc a,a */
  /* sbc a,h */
  sp = 0xB299;
  a = a ^ l;
  flag_logic(a);
  a = a ^ b;
  flag_logic(a);
  a = a & e;
  flag_logic(a);
  /* sbc a,(hl) */
  /* sbc a,e */
  a = a | h;
  flag_logic(a);
  /* nop */
  a = a | c;
  flag_logic(a);
  a = a ^ h;
  flag_logic(a);
  a = a & a;
  flag_logic(a);
  a = a & d;
  flag_logic(a);
  /* sbc a,l */
  /* sbc a,d */
  /* nop */
  b = h;
  e = d;
  l = 0x48;
  c = c;
  /* nop */
  b = l;
  a = mem_read8(bc());
  cpu_ex_af();
  mem_write8(bc(), a);
  set_bc(0x0007);
  /* nop */
  /* nop */
  /* nop */
  b = 0xCB;
  if (flag_m()) return;
  /* di */
  a = a ^ 0xE9;
  flag_logic(a);
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  /* jp z,0xF7CC - other page/RAM */
  /* jp p,0xE8ED - other page/RAM */
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  /* nop */
  a = (uint8_t)(a + 0xFB);
  a = a | 0xF1;
  flag_logic(a);
  /* call 0xE4E7 - RAM/other */
  sp = 0xFA99;
  cpu_push_af();
  if (flag_p()) return;
  cpu_ex_de_hl();
  a = a & 0xE3;
  flag_logic(a);
  a = a | h;
  flag_logic(a);
  /* nop */
  sp = hl();
  /* call 0xEAEF - RAM/other */
  cpu_push_hl();
  if (flag_po()) goto lab_p06_L_4400;
  e = d;
  l = 0x48;
  c = c;
  /* nop */
  b = l;
  a = mem_read8(bc());
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
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

/* flash page 6 cpu 0x7E40 (offset 0x3E40) */
void p06_str_9(void) {
  goto lab_p06_str_9;
  lab_p06_L_4400: ;
  if (flag_z()) return;
  cpu_push_hl();
  cpu_push_de();
  p06_L_445C();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_push_af();
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_4434;
  cpu_pop_af();
  if (flag_c()) goto lab_p06_L_4431;
  cpu_push_de();
  cpu_push_hl();
  set_hl(mem_read16(0x96F8));
  set_de(mem_read16(0x96FA));
  p00_L_192A();
  if (flag_nz()) goto lab_p06_L_4427;
  set_hl(mem_read16(0x96F6));
  set_hl((uint16_t)(hl() + 1));
  p06_L_44C1();
  goto lab_p06_L_442A;
  lab_p06_L_4427: ;
  p06_L_44BE();
  lab_p06_L_442A: ;
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_nz()) goto lab_p06_L_4430;
  a = 0;
  flag_logic(a);
  return;
  lab_p06_L_4430: ;
  a = 0;
  flag_logic(a);
  lab_p06_L_4431: ;
  cpu_push_af();
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_4434: ;
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96F6, hl());
  p06_L_444C();
  cpu_pop_af();
  if (flag_c()) p06_L_4443();
  a = a | 0x01;
  flag_logic(a);
  return;
  lab_p06_str_9: ;
  d = b;
  c = l;
  d = h;
  a = mem_read8(0x4900);
  l = mem_read8(hl());
  h = h;
  mem_write8(hl(), b);
  l = mem_read8(hl());
  mem_write8(hl(), h);
  a = mem_read8(0x4400);
  h = l;
  mem_write8(hl(), b);
  h = l;
  l = mem_read8(hl());
  h = h;
  a = mem_read8(0x0C00);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  if (flag_nc()) goto lab_p06_L_7E88;
  l = 0x00;
  b = b;
  h = b;
  e = a;
  e = mem_read8(hl());
  if (flag_nz()) goto lab_p06_L_7E81;
  h = b;
  e = a;
  e = mem_read8(hl());
  p06_L_7E64();
  return;
  lab_p06_L_7E81: ;
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  a = (uint8_t)(a + b);
  a = (uint8_t)(a + c);
  a = (uint8_t)(a + d);
  lab_p06_L_7E88: ;
  a = (uint8_t)(a + e);
  a = (uint8_t)(a + h);
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  /* adc a,h */
  a = (uint8_t)(a - c);
  a = (uint8_t)(a - h);
  a = 0;
  flag_logic(a);
  /* add a,(hl) */
  flag_cmp(a, e);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  /* nop */
  /* adc a,l */
  a = (uint8_t)(a - b);
  a = (uint8_t)(a - e);
  /* sub (hl) */
  a = (uint8_t)(a + l);
  flag_cmp(a, c);
  l = (uint8_t)(l - 1);
  sp = 0x8F8E;
  a = (uint8_t)(a - d);
  a = (uint8_t)(a - l);
  /* adc a,e */
  a = a | a;
  flag_logic(a);
  l = (uint8_t)(l + 1);
  a = a | h;
  flag_logic(a);
  /* nop */
  /* adc a,d */
  flag_cmp(a, a);
  cpu_pop_bc();
  flag_cmp(a, l);
  /* or (hl) */
  mem_write8(0x4400, a);
  e = d;
  l = 0x48;
  c = c;
  /* nop */
  b = l;
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  c = 0x0F;
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  c = (uint8_t)(c - 1);
  mem_write8(hl(), 0x88);
  a = (uint8_t)(a + a);
  os_bcall(0x09B5);
  /* nop */
  cpu_push_bc();
  cpu_push_af();
  if (flag_m()) return;
  /* ei */
  /* db 0xED,0xBC */
  if (flag_c()) goto lab_p06_L_7ECC;
  lab_p06_L_7ECC: ;
  a = a ^ 0xF4;
  flag_logic(a);
  p00_rst30();
  if (flag_m()) { os_banked_call(0xBAEC); return; }
  a = a ^ 0xFF;
  a = mem_read8(0xF33E);
  a = a | 0xF9;
  flag_logic(a);
  /* sbc a,b */
  flag_cmp(a, b);
  set_hl((uint16_t)(hl() + sp));
  b = c;
  /* nop */
  c = (uint8_t)(c + 1);
  if (flag_nz()) return;
  if (flag_nz()) { p00_L_37BE(); return; }
  sp = (uint16_t)(sp + 1);
  /* nop */
  c = d;
  sp = (uint16_t)(sp - 1);
  d = a;
  c = e;
  if (flag_nc()) goto lab_p06_L_7EEA;
  lab_p06_L_7EEA: ;
  b = b;
  set_bc((uint16_t)(bc() - 1));
  cpu_ex_af();
  mem_write8(bc(), a);
  set_bc(0x0007);
  /* nop */
  /* nop */
  /* nop */
  b = 0xCB;
  a = a | b;
  flag_logic(a);
  a = a ^ e;
  flag_logic(a);
  /* and (hl) */
  a = a & c;
  flag_logic(a);
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  if (flag_z()) { os_banked_call(0xAFCC); return; }
  a = a ^ d;
  flag_logic(a);
  a = a & l;
  flag_logic(a);
  a = a & b;
  flag_logic(a);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  /* nop */
  a = (uint8_t)(a + 0xB3);
  /* xor (hl) */
  a = a ^ c;
  flag_logic(a);
  a = a & h;
  flag_logic(a);
  /* sbc a,a */
  /* sbc a,h */
  sp = 0xB299;
  a = a ^ l;
  flag_logic(a);
  a = a ^ b;
  flag_logic(a);
  a = a & e;
  flag_logic(a);
  /* sbc a,(hl) */
  /* sbc a,e */
  a = a | h;
  flag_logic(a);
  /* nop */
  a = a | c;
  flag_logic(a);
  a = a ^ h;
  flag_logic(a);
  a = a & a;
  flag_logic(a);
  a = a & d;
  flag_logic(a);
  /* sbc a,l */
  /* sbc a,d */
  /* nop */
  b = h;
  e = d;
  l = 0x48;
  c = c;
  /* nop */
  b = l;
  a = mem_read8(bc());
  cpu_ex_af();
  mem_write8(bc(), a);
  set_bc(0x0007);
  /* nop */
  /* nop */
  /* nop */
  b = 0xCB;
  if (flag_m()) return;
  /* di */
  a = a ^ 0xE9;
  flag_logic(a);
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  /* jp z,0xF7CC - other page/RAM */
  /* jp p,0xE8ED - other page/RAM */
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  /* nop */
  a = (uint8_t)(a + 0xFB);
  a = a | 0xF1;
  flag_logic(a);
  /* call 0xE4E7 - RAM/other */
  sp = 0xFA99;
  cpu_push_af();
  if (flag_p()) return;
  cpu_ex_de_hl();
  a = a & 0xE3;
  flag_logic(a);
  a = a | h;
  flag_logic(a);
  /* nop */
  sp = hl();
  /* call 0xEAEF - RAM/other */
  cpu_push_hl();
  if (flag_po()) goto lab_p06_L_4400;
  e = d;
  l = 0x48;
  c = c;
  /* nop */
  b = l;
  a = mem_read8(bc());
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
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

/* flash page 6 cpu 0x7E45 (offset 0x3E45) */
void p06_str_7(void) {
  goto lab_p06_str_7;
  lab_p06_L_4400: ;
  if (flag_z()) return;
  cpu_push_hl();
  cpu_push_de();
  p06_L_445C();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_push_af();
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_4434;
  cpu_pop_af();
  if (flag_c()) goto lab_p06_L_4431;
  cpu_push_de();
  cpu_push_hl();
  set_hl(mem_read16(0x96F8));
  set_de(mem_read16(0x96FA));
  p00_L_192A();
  if (flag_nz()) goto lab_p06_L_4427;
  set_hl(mem_read16(0x96F6));
  set_hl((uint16_t)(hl() + 1));
  p06_L_44C1();
  goto lab_p06_L_442A;
  lab_p06_L_4427: ;
  p06_L_44BE();
  lab_p06_L_442A: ;
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_nz()) goto lab_p06_L_4430;
  a = 0;
  flag_logic(a);
  return;
  lab_p06_L_4430: ;
  a = 0;
  flag_logic(a);
  lab_p06_L_4431: ;
  cpu_push_af();
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_4434: ;
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96F6, hl());
  p06_L_444C();
  cpu_pop_af();
  if (flag_c()) p06_L_4443();
  a = a | 0x01;
  flag_logic(a);
  return;
  lab_p06_str_7: ;
  c = c;
  l = mem_read8(hl());
  h = h;
  mem_write8(hl(), b);
  l = mem_read8(hl());
  mem_write8(hl(), h);
  a = mem_read8(0x4400);
  h = l;
  mem_write8(hl(), b);
  h = l;
  l = mem_read8(hl());
  h = h;
  a = mem_read8(0x0C00);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  if (flag_nc()) goto lab_p06_L_7E88;
  l = 0x00;
  b = b;
  h = b;
  e = a;
  e = mem_read8(hl());
  if (flag_nz()) goto lab_p06_L_7E81;
  h = b;
  e = a;
  e = mem_read8(hl());
  p06_L_7E64();
  return;
  lab_p06_L_7E81: ;
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  a = (uint8_t)(a + b);
  a = (uint8_t)(a + c);
  a = (uint8_t)(a + d);
  lab_p06_L_7E88: ;
  a = (uint8_t)(a + e);
  a = (uint8_t)(a + h);
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  /* adc a,h */
  a = (uint8_t)(a - c);
  a = (uint8_t)(a - h);
  a = 0;
  flag_logic(a);
  /* add a,(hl) */
  flag_cmp(a, e);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  /* nop */
  /* adc a,l */
  a = (uint8_t)(a - b);
  a = (uint8_t)(a - e);
  /* sub (hl) */
  a = (uint8_t)(a + l);
  flag_cmp(a, c);
  l = (uint8_t)(l - 1);
  sp = 0x8F8E;
  a = (uint8_t)(a - d);
  a = (uint8_t)(a - l);
  /* adc a,e */
  a = a | a;
  flag_logic(a);
  l = (uint8_t)(l + 1);
  a = a | h;
  flag_logic(a);
  /* nop */
  /* adc a,d */
  flag_cmp(a, a);
  cpu_pop_bc();
  flag_cmp(a, l);
  /* or (hl) */
  mem_write8(0x4400, a);
  e = d;
  l = 0x48;
  c = c;
  /* nop */
  b = l;
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  c = 0x0F;
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  c = (uint8_t)(c - 1);
  mem_write8(hl(), 0x88);
  a = (uint8_t)(a + a);
  os_bcall(0x09B5);
  /* nop */
  cpu_push_bc();
  cpu_push_af();
  if (flag_m()) return;
  /* ei */
  /* db 0xED,0xBC */
  if (flag_c()) goto lab_p06_L_7ECC;
  lab_p06_L_7ECC: ;
  a = a ^ 0xF4;
  flag_logic(a);
  p00_rst30();
  if (flag_m()) { os_banked_call(0xBAEC); return; }
  a = a ^ 0xFF;
  a = mem_read8(0xF33E);
  a = a | 0xF9;
  flag_logic(a);
  /* sbc a,b */
  flag_cmp(a, b);
  set_hl((uint16_t)(hl() + sp));
  b = c;
  /* nop */
  c = (uint8_t)(c + 1);
  if (flag_nz()) return;
  if (flag_nz()) { p00_L_37BE(); return; }
  sp = (uint16_t)(sp + 1);
  /* nop */
  c = d;
  sp = (uint16_t)(sp - 1);
  d = a;
  c = e;
  if (flag_nc()) goto lab_p06_L_7EEA;
  lab_p06_L_7EEA: ;
  b = b;
  set_bc((uint16_t)(bc() - 1));
  cpu_ex_af();
  mem_write8(bc(), a);
  set_bc(0x0007);
  /* nop */
  /* nop */
  /* nop */
  b = 0xCB;
  a = a | b;
  flag_logic(a);
  a = a ^ e;
  flag_logic(a);
  /* and (hl) */
  a = a & c;
  flag_logic(a);
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  if (flag_z()) { os_banked_call(0xAFCC); return; }
  a = a ^ d;
  flag_logic(a);
  a = a & l;
  flag_logic(a);
  a = a & b;
  flag_logic(a);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  /* nop */
  a = (uint8_t)(a + 0xB3);
  /* xor (hl) */
  a = a ^ c;
  flag_logic(a);
  a = a & h;
  flag_logic(a);
  /* sbc a,a */
  /* sbc a,h */
  sp = 0xB299;
  a = a ^ l;
  flag_logic(a);
  a = a ^ b;
  flag_logic(a);
  a = a & e;
  flag_logic(a);
  /* sbc a,(hl) */
  /* sbc a,e */
  a = a | h;
  flag_logic(a);
  /* nop */
  a = a | c;
  flag_logic(a);
  a = a ^ h;
  flag_logic(a);
  a = a & a;
  flag_logic(a);
  a = a & d;
  flag_logic(a);
  /* sbc a,l */
  /* sbc a,d */
  /* nop */
  b = h;
  e = d;
  l = 0x48;
  c = c;
  /* nop */
  b = l;
  a = mem_read8(bc());
  cpu_ex_af();
  mem_write8(bc(), a);
  set_bc(0x0007);
  /* nop */
  /* nop */
  /* nop */
  b = 0xCB;
  if (flag_m()) return;
  /* di */
  a = a ^ 0xE9;
  flag_logic(a);
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  /* jp z,0xF7CC - other page/RAM */
  /* jp p,0xE8ED - other page/RAM */
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  /* nop */
  a = (uint8_t)(a + 0xFB);
  a = a | 0xF1;
  flag_logic(a);
  /* call 0xE4E7 - RAM/other */
  sp = 0xFA99;
  cpu_push_af();
  if (flag_p()) return;
  cpu_ex_de_hl();
  a = a & 0xE3;
  flag_logic(a);
  a = a | h;
  flag_logic(a);
  /* nop */
  sp = hl();
  /* call 0xEAEF - RAM/other */
  cpu_push_hl();
  if (flag_po()) goto lab_p06_L_4400;
  e = d;
  l = 0x48;
  c = c;
  /* nop */
  b = l;
  a = mem_read8(bc());
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
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

/* flash page 6 cpu 0x7E4D (offset 0x3E4D) */
void p06_str_8(void) {
  goto lab_p06_str_8;
  lab_p06_L_4400: ;
  if (flag_z()) return;
  cpu_push_hl();
  cpu_push_de();
  p06_L_445C();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_push_af();
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p06_L_4434;
  cpu_pop_af();
  if (flag_c()) goto lab_p06_L_4431;
  cpu_push_de();
  cpu_push_hl();
  set_hl(mem_read16(0x96F8));
  set_de(mem_read16(0x96FA));
  p00_L_192A();
  if (flag_nz()) goto lab_p06_L_4427;
  set_hl(mem_read16(0x96F6));
  set_hl((uint16_t)(hl() + 1));
  p06_L_44C1();
  goto lab_p06_L_442A;
  lab_p06_L_4427: ;
  p06_L_44BE();
  lab_p06_L_442A: ;
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_nz()) goto lab_p06_L_4430;
  a = 0;
  flag_logic(a);
  return;
  lab_p06_L_4430: ;
  a = 0;
  flag_logic(a);
  lab_p06_L_4431: ;
  cpu_push_af();
  mem_write8(hl(), d);
  set_hl((uint16_t)(hl() + 1));
  lab_p06_L_4434: ;
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96F6, hl());
  p06_L_444C();
  cpu_pop_af();
  if (flag_c()) p06_L_4443();
  a = a | 0x01;
  flag_logic(a);
  return;
  lab_p06_str_8: ;
  b = h;
  h = l;
  mem_write8(hl(), b);
  h = l;
  l = mem_read8(hl());
  h = h;
  a = mem_read8(0x0C00);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  if (flag_nc()) goto lab_p06_L_7E88;
  l = 0x00;
  b = b;
  h = b;
  e = a;
  e = mem_read8(hl());
  if (flag_nz()) goto lab_p06_L_7E81;
  h = b;
  e = a;
  e = mem_read8(hl());
  p06_L_7E64();
  return;
  lab_p06_L_7E81: ;
  /* nop */
  /* nop */
  /* nop */
  b = (uint8_t)(b - 1);
  a = (uint8_t)(a + b);
  a = (uint8_t)(a + c);
  a = (uint8_t)(a + d);
  lab_p06_L_7E88: ;
  a = (uint8_t)(a + e);
  a = (uint8_t)(a + h);
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  /* adc a,h */
  a = (uint8_t)(a - c);
  a = (uint8_t)(a - h);
  a = 0;
  flag_logic(a);
  /* add a,(hl) */
  flag_cmp(a, e);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  /* nop */
  /* adc a,l */
  a = (uint8_t)(a - b);
  a = (uint8_t)(a - e);
  /* sub (hl) */
  a = (uint8_t)(a + l);
  flag_cmp(a, c);
  l = (uint8_t)(l - 1);
  sp = 0x8F8E;
  a = (uint8_t)(a - d);
  a = (uint8_t)(a - l);
  /* adc a,e */
  a = a | a;
  flag_logic(a);
  l = (uint8_t)(l + 1);
  a = a | h;
  flag_logic(a);
  /* nop */
  /* adc a,d */
  flag_cmp(a, a);
  cpu_pop_bc();
  flag_cmp(a, l);
  /* or (hl) */
  mem_write8(0x4400, a);
  e = d;
  l = 0x48;
  c = c;
  /* nop */
  b = l;
  a = mem_read8(bc());
  b = (uint8_t)(b + 1);
  c = 0x0F;
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  /* nop */
  /* nop */
  /* nop */
  c = (uint8_t)(c - 1);
  mem_write8(hl(), 0x88);
  a = (uint8_t)(a + a);
  os_bcall(0x09B5);
  /* nop */
  cpu_push_bc();
  cpu_push_af();
  if (flag_m()) return;
  /* ei */
  /* db 0xED,0xBC */
  if (flag_c()) goto lab_p06_L_7ECC;
  lab_p06_L_7ECC: ;
  a = a ^ 0xF4;
  flag_logic(a);
  p00_rst30();
  if (flag_m()) { os_banked_call(0xBAEC); return; }
  a = a ^ 0xFF;
  a = mem_read8(0xF33E);
  a = a | 0xF9;
  flag_logic(a);
  /* sbc a,b */
  flag_cmp(a, b);
  set_hl((uint16_t)(hl() + sp));
  b = c;
  /* nop */
  c = (uint8_t)(c + 1);
  if (flag_nz()) return;
  if (flag_nz()) { p00_L_37BE(); return; }
  sp = (uint16_t)(sp + 1);
  /* nop */
  c = d;
  sp = (uint16_t)(sp - 1);
  d = a;
  c = e;
  if (flag_nc()) goto lab_p06_L_7EEA;
  lab_p06_L_7EEA: ;
  b = b;
  set_bc((uint16_t)(bc() - 1));
  cpu_ex_af();
  mem_write8(bc(), a);
  set_bc(0x0007);
  /* nop */
  /* nop */
  /* nop */
  b = 0xCB;
  a = a | b;
  flag_logic(a);
  a = a ^ e;
  flag_logic(a);
  /* and (hl) */
  a = a & c;
  flag_logic(a);
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  if (flag_z()) { os_banked_call(0xAFCC); return; }
  a = a ^ d;
  flag_logic(a);
  a = a & l;
  flag_logic(a);
  a = a & b;
  flag_logic(a);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  /* nop */
  a = (uint8_t)(a + 0xB3);
  /* xor (hl) */
  a = a ^ c;
  flag_logic(a);
  a = a & h;
  flag_logic(a);
  /* sbc a,a */
  /* sbc a,h */
  sp = 0xB299;
  a = a ^ l;
  flag_logic(a);
  a = a ^ b;
  flag_logic(a);
  a = a & e;
  flag_logic(a);
  /* sbc a,(hl) */
  /* sbc a,e */
  a = a | h;
  flag_logic(a);
  /* nop */
  a = a | c;
  flag_logic(a);
  a = a ^ h;
  flag_logic(a);
  a = a & a;
  flag_logic(a);
  a = a & d;
  flag_logic(a);
  /* sbc a,l */
  /* sbc a,d */
  /* nop */
  b = h;
  e = d;
  l = 0x48;
  c = c;
  /* nop */
  b = l;
  a = mem_read8(bc());
  cpu_ex_af();
  mem_write8(bc(), a);
  set_bc(0x0007);
  /* nop */
  /* nop */
  /* nop */
  b = 0xCB;
  if (flag_m()) return;
  /* di */
  a = a ^ 0xE9;
  flag_logic(a);
  set_hl((uint16_t)(hl() + bc()));
  /* nop */
  /* jp z,0xF7CC - other page/RAM */
  /* jp p,0xE8ED - other page/RAM */
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  /* nop */
  a = (uint8_t)(a + 0xFB);
  a = a | 0xF1;
  flag_logic(a);
  /* call 0xE4E7 - RAM/other */
  sp = 0xFA99;
  cpu_push_af();
  if (flag_p()) return;
  cpu_ex_de_hl();
  a = a & 0xE3;
  flag_logic(a);
  a = a | h;
  flag_logic(a);
  /* nop */
  sp = hl();
  /* call 0xEAEF - RAM/other */
  cpu_push_hl();
  if (flag_po()) goto lab_p06_L_4400;
  e = d;
  l = 0x48;
  c = c;
  /* nop */
  b = l;
  a = mem_read8(bc());
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
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

/* flash page 6 cpu 0x7E64 (offset 0x3E64) */
void p06_L_7E64(void) {
  set_hl(0x7E5A);
  p06_L_7E6C();
  return;
}

/* flash page 6 cpu 0x7E69 (offset 0x3E69) */
void p06_L_7E69(void) {
  set_hl(0x7E55);
  p06_L_7E6C();
  return;
}

/* flash page 6 cpu 0x7E6C (offset 0x3E6C) */
void p06_L_7E6C(void) {
  set_de(0x8DA2);
  p00_L_118B();
  return;
}


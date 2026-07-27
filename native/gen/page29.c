/* Recovered from flash page 29 (mechanical ASM->C) */
/* cpu window 0x4000..0x7FFF prefix=p29_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p29_L_4000(void);
void p29_L_4022(void);
void p29_L_403F(void);
void p29_L_407A(void);
void p29_L_4083(void);
void p29_L_40A6(void);
void p29_L_40A9(void);
void p29_L_40CC(void);
void p29_L_40D5(void);
void p29_L_40E3(void);
void p29_L_4100(void);
void p29_L_4117(void);
void p29_L_4211(void);
void p29_L_4214(void);
void p29_L_421D(void);
void p29_L_4228(void);
void p29_L_4230(void);
void p29_L_4238(void);
void p29_L_4243(void);
void p29_L_424C(void);
void p29_L_4253(void);
void p29_L_425E(void);
void p29_L_4261(void);
void p29_L_4269(void);
void p29_L_4274(void);
void p29_L_427C(void);
void p29_L_427F(void);
void p29_L_4287(void);
void p29_L_428F(void);
void p29_L_429A(void);
void p29_L_42A2(void);
void p29_L_42AE(void);
void p29_L_42D3(void);
void p29_L_42DF(void);
void p29_L_42ED(void);
void p29_L_430E(void);
void p29_L_4330(void);
void p29_L_4340(void);
void p29_L_43ED(void);
void p29_L_43F6(void);
void p29_L_442C(void);
void p29_L_4442(void);
void p29_L_4490(void);
void p29_L_4498(void);
void p29_L_44C3(void);
void p29_L_44F9(void);
void p29_L_4533(void);
void p29_L_455C(void);
void p29_L_4565(void);
void p29_L_4566(void);
void p29_L_456D(void);
void p29_L_4574(void);
void p29_L_4575(void);
void p29_L_457C(void);
void p29_L_4583(void);
void p29_L_45E4(void);
void p29_L_464E(void);
void p29_L_468A(void);
void p29_L_46C7(void);
void p29_L_4718(void);
void p29_L_475F(void);
void p29_L_476B(void);
void p29_L_47B5(void);
void p29_L_47B6(void);
void p29_L_47CD(void);
void p29_L_47E3(void);
void p29_L_484E(void);
void p29_L_4873(void);
void p29_L_4894(void);
void p29_L_4897(void);
void p29_L_489E(void);
void p29_L_48B5(void);
void p29_L_48BC(void);
void p29_L_48DE(void);
void p29_L_48EB(void);
void p29_L_4908(void);
void p29_L_4926(void);
void p29_L_4992(void);
void p29_L_49D8(void);
void p29_L_4A21(void);
void p29_L_4A3F(void);
void p29_L_4A5A(void);
void p29_L_4AC9(void);
void p29_L_4ADC(void);
void p29_L_4B73(void);
void p29_L_4B82(void);
void p29_L_4B8E(void);
void p29_L_4C0C(void);
void p29_L_4C73(void);
void p29_L_4C8B(void);
void p29_L_4CAE(void);
void p29_L_4D38(void);
void p29_L_4D5E(void);
void p29_L_4DCD(void);
void p29_L_4E44(void);
void p29_L_4E9B(void);
void p29_L_4EBD(void);
void p29_L_4ECE(void);
void p29_L_4F10(void);
void p29_L_4F62(void);
void p29_L_4F6E(void);
void p29_L_4F81(void);
void p29_L_4F95(void);
void p29_L_4FB9(void);
void p29_L_4FF9(void);
void p29_L_503F(void);
void p29_L_5083(void);
void p29_L_508A(void);
void p29_L_50A8(void);
void p29_L_50C5(void);
void p29_L_5124(void);
void p29_L_5156(void);
void p29_L_5185(void);
void p29_L_519D(void);
void p29_L_51C3(void);
void p29_L_51DB(void);
void p29_L_5217(void);
void p29_L_521D(void);
void p29_L_522B(void);
void p29_L_5231(void);
void p29_L_5236(void);
void p29_L_523C(void);
void p29_L_5242(void);
void p29_L_5287(void);
void p29_L_5298(void);
void p29_L_529F(void);
void p29_L_52D9(void);
void p29_L_52F0(void);
void p29_L_52F7(void);
void p29_L_533B(void);
void p29_L_5365(void);
void p29_L_536F(void);
void p29_L_53B3(void);
void p29_L_53D1(void);
void p29_L_53E5(void);
void p29_L_540C(void);
void p29_L_543D(void);
void p29_L_54A0(void);
void p29_L_54DA(void);
void p29_L_5525(void);
void p29_L_55CE(void);
void p29_L_560B(void);
void p29_L_5646(void);
void p29_L_56A0(void);
void p29_L_56E5(void);
void p29_L_573C(void);
void p29_L_5757(void);
void p29_L_576D(void);
void p29_L_578D(void);
void p29_L_57C5(void);
void p29_L_57CB(void);
void p29_L_5928(void);
void p29_L_597A(void);
void p29_L_5980(void);
void p29_L_598E(void);
void p29_L_59B3(void);
void p29_L_5A68(void);
void p29_L_5AA5(void);
void p29_L_5ACC(void);
void p29_L_5ADE(void);
void p29_L_5B11(void);
void p29_L_5B2F(void);
void p29_L_5B4D(void);
void p29_L_5BCA(void);
void p29_L_5BE0(void);
void p29_L_5BED(void);
void p29_L_5C2D(void);
void p29_L_5C37(void);
void p29_L_5C45(void);
void p29_L_5C7C(void);
void p29_L_5C8E(void);
void p29_L_5CC5(void);
void p29_L_5CFF(void);
void p29_L_5D1E(void);
void p29_L_5D43(void);
void p29_L_5D68(void);
void p29_L_5DC7(void);
void p29_L_5DE5(void);
void p29_L_5E0A(void);
void p29_L_5E31(void);
void p29_L_5E34(void);
void p29_L_5E59(void);
void p29_L_5E78(void);
void p29_L_5E90(void);
void p29_L_5ECD(void);
void p29_L_5EFC(void);
void p29_L_5F20(void);
void p29_L_5F2A(void);
void p29_L_5F9F(void);
void p29_L_5FDB(void);
void p29_L_5FED(void);
void p29_L_6006(void);
void p29_L_6011(void);
void p29_L_6021(void);
void p29_L_6067(void);
void p29_L_607A(void);
void p29_L_60E5(void);
void p29_L_60E9(void);
void p29_L_60EF(void);
void p29_L_6172(void);
void p29_L_6177(void);
void p29_L_6186(void);
void p29_L_6196(void);
void p29_L_61A4(void);
void p29_L_61BC(void);
void p29_L_61CD(void);
void p29_L_62B3(void);
void p29_L_62C1(void);
void p29_L_6388(void);
void p29_L_638B(void);
void p29_L_6428(void);
void p29_L_646F(void);
void p29_L_6503(void);
void p29_L_650D(void);
void p29_L_651E(void);
void p29_L_6523(void);
void p29_L_652E(void);
void p29_L_6550(void);
void p29_L_6559(void);
void p29_L_6598(void);
void p29_L_65A0(void);
void p29_L_65B1(void);
void p29_L_6621(void);
void p29_L_6626(void);
void p29_L_662F(void);
void p29_L_66A9(void);
void p29_L_66BF(void);
void p29_L_66CD(void);
void p29_L_673D(void);
void p29_L_6769(void);
void p29_L_67EC(void);
void p29_L_6800(void);
void p29_L_682D(void);
void p29_L_687E(void);
void p29_L_6897(void);
void p29_L_692E(void);
void p29_L_69CD(void);
void p29_L_69D4(void);
void p29_L_69E4(void);
void p29_L_69E8(void);
void p29_L_6A03(void);
void p29_L_6A07(void);
void p29_L_6A10(void);
void p29_L_6A55(void);
void p29_L_6A77(void);
void p29_L_6AD1(void);
void p29_L_6B36(void);
void p29_L_6B49(void);
void p29_L_6B87(void);
void p29_L_6BAD(void);
void p29_L_6BB0(void);
void p29_L_6BBE(void);
void p29_L_6BE2(void);
void p29_L_6C19(void);
void p29_L_6CB5(void);
void p29_L_6CCB(void);
void p29_L_6D37(void);
void p29_L_6DCD(void);
void p29_L_6E40(void);
void p29_L_6ECE(void);
void p29_L_6ED5(void);
void p29_L_6EDB(void);
void p29_L_6F54(void);
void p29_L_6F82(void);
void p29_L_6FAC(void);
void p29_L_6FC0(void);
void p29_L_6FF9(void);
void p29_str_2(void);
void p29_str_1(void);
void p29_L_7045(void);
void p29_L_705E(void);
void p29_L_7060(void);
void p29_L_70A9(void);
void p29_L_70D1(void);
void p29_str_3(void);
void p29_L_70E9(void);
void p29_L_7124(void);
void p29_L_712A(void);
void p29_L_7150(void);
void p29_L_717A(void);
void p29_L_7182(void);
void p29_L_7240(void);
void p29_L_72A5(void);
void p29_L_732F(void);
void p29_L_7336(void);
void p29_L_733B(void);
void p29_L_739B(void);
void p29_L_756F(void);
void p29_L_75B8(void);
void p29_L_75E1(void);
void p29_L_75EC(void);
void p29_L_75F5(void);
void p29_L_75FD(void);
void p29_L_761F(void);
void p29_L_762A(void);
void p29_L_7634(void);
void p29_L_7643(void);
void p29_L_764E(void);
void p29_L_7656(void);
void p29_L_7663(void);
void p29_L_7666(void);
void p29_L_7700(void);
void p29_L_7707(void);
void p29_L_770A(void);
void p29_L_7724(void);
void p29_L_777E(void);
void p29_L_780B(void);
void p29_L_780D(void);
void p29_L_7865(void);
void p29_L_78A3(void);
void p29_L_78C2(void);
void p29_L_78F5(void);
void p29_L_7915(void);
void p29_L_7932(void);
void p29_L_794D(void);
void p29_L_795C(void);
void p29_L_7984(void);
void p29_L_7A67(void);
void p29_L_7A75(void);
void p29_L_7A85(void);
void p29_L_7A8D(void);
void p29_L_7A96(void);
void p29_L_7AB7(void);
void p29_L_7AD0(void);
void p29_L_7B41(void);
void p29_L_7B72(void);
void p29_L_7BA4(void);
void p29_L_7BAF(void);
void p29_L_7BB5(void);
void p29_L_7BBA(void);
void p29_L_7BCA(void);
void p29_L_7BCC(void);
void p29_L_7BD4(void);
void p29_L_7BEA(void);
void p29_L_7C0F(void);
void p29_L_7C64(void);
void p29_L_7C96(void);
void p29_L_7CA5(void);
void p29_L_7CB2(void);
void p29_L_7CBB(void);
void p29_L_7CCD(void);
void p29_L_7CCF(void);
void p29_L_7CDA(void);
void p29_L_7D52(void);
void p29_L_7D67(void);
void p29_L_7E40(void);
void p29_L_7FCD(void);

/* flash page 29 cpu 0x4000 (offset 0x0000) */
void p29_L_4000(void) {
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
  p29_L_6FAC();
  if (flag_c()) { p29_L_5FDB(); return; }
  cpu_push_af();
  p29_L_576D();
  cpu_pop_af();
  p29_L_403F();
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x4022 (offset 0x0022) */
void p29_L_4022(void) {
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
  p29_L_6FAC();
  if (flag_c()) { p29_L_5FDB(); return; }
  p29_L_403F();
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x403F (offset 0x003F) */
void p29_L_403F(void) {
  b = a;
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0xFF);
  a = b;
  if (flag_z()) goto lab_p29_L_4077;
  p29_L_4A3F();
  b = c;
  cpu_push_af();
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_4078;
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 7)));
  a = 0;
  flag_logic(a);
  mem_write8(0x9C87, a);
  cpu_pop_af();
  lab_p29_L_4061: ;
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) | (1u << 0)));
  cpu_push_af();
  cpu_push_bc();
  set_de(0x4000);
  b = 0x00;
  os_bcall(0x80C6);
  cpu_pop_bc();
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_4061;
  mem_write8(0x82A4, a);
  lab_p29_L_4077: ;
  return;
  lab_p29_L_4078: ;
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x407A (offset 0x007A) */
void p29_L_407A(void) {
  cpu_push_hl();
  p29_L_4894();
  p29_L_457C();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x4083 (offset 0x0083) */
void p29_L_4083(void) {
  p29_L_7700();
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  cpu_push_af();
  lab_p29_L_408A: ;
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_af();
  p29_L_6B36();
  b = a;
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8021);
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  cpu_push_af();
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_408A;
  cpu_pop_af();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x40A6 (offset 0x00A6) */
void p29_L_40A6(void) {
  p29_L_7700();
  p29_L_40A9();
  return;
}

/* flash page 29 cpu 0x40A9 (offset 0x00A9) */
void p29_L_40A9(void) {
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  cpu_push_af();
  lab_p29_L_40AD: ;
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_af();
  os_bcall(0x8051);
  b = a;
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x8483);
  os_bcall(0x8021);
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  cpu_push_af();
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_40AD;
  cpu_pop_af();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x40CC (offset 0x00CC) */
void p29_L_40CC(void) {
  mem_write8(0x9C20, a);
  cpu_push_de();
  cpu_push_bc();
  cpu_push_hl();
  p29_L_4894();
  p29_L_40D5();
  return;
}

/* flash page 29 cpu 0x40D5 (offset 0x00D5) */
void p29_L_40D5(void) {
  p29_L_4566();
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p29_L_40E5;
  set_bc(0x0000);
  mem_write16(0x84AF, bc());
  p29_L_40E3();
  return;
  lab_p29_L_40E5: ;
  set_bc(0x0001);
  mem_write16(0x84AF, bc());
  cpu_push_hl();
  p29_L_4574();
  set_hl((uint16_t)(hl() + bc()));
  p29_L_4574();
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_bc();
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  p29_L_4894();
  set_de(0x4000);
  p29_L_4100();
  return;
}

/* flash page 29 cpu 0x40E3 (offset 0x00E3) */
void p29_L_40E3(void) {
  goto lab_p29_L_4105;
  lab_p29_L_4105: ;
  p29_L_4894();
  os_bcall(0x8060);
  os_bcall(0x8057);
  cpu_push_hl();
  cpu_push_hl();
  p29_L_4897();
  cpu_ex_de_hl();
  cpu_pop_hl();
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  p29_L_4117();
  return;
}

/* flash page 29 cpu 0x4100 (offset 0x0100) */
void p29_L_4100(void) {
  cpu_push_de();
  cpu_push_bc();
  p29_L_42DF();
  p29_L_4894();
  os_bcall(0x8060);
  os_bcall(0x8057);
  cpu_push_hl();
  cpu_push_hl();
  p29_L_4897();
  cpu_ex_de_hl();
  cpu_pop_hl();
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  p29_L_4117();
  return;
}

/* flash page 29 cpu 0x4117 (offset 0x0117) */
void p29_L_4117(void) {
  lab_p29_L_4117: ;
  p29_L_4566();
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p29_L_415C;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p29_L_417B;
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_hl();
  p29_L_521D();
  p00_L_24A9();
  if (flag_nz()) goto lab_p29_L_4131;
  p29_L_522B();
  lab_p29_L_4131: ;
  cpu_push_hl();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_sbc_hl_bc();
  if (flag_nc()) goto lab_p29_L_417B;
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  mem_write16(0x83EE, de());
  p29_L_4574();
  cpu_pop_de();
  cpu_push_de();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  a = l;
  a = (uint8_t)(a + c);
  c = a;
  if (flag_nc()) goto lab_p29_L_414D;
  b = (uint8_t)(b + 1);
  lab_p29_L_414D: ;
  cpu_pop_hl();
  set_de(mem_read16(0x83EE));
  p29_L_4083();
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + bc()));
  cpu_ex_de_hl();
  goto lab_p29_L_4117;
  lab_p29_L_415C: ;
  cpu_push_de();
  p29_L_4574();
  cpu_pop_de();
  set_hl((uint16_t)(hl() + bc()));
  p29_L_4566();
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p29_L_4178;
  cpu_push_de();
  cpu_push_hl();
  p29_L_4574();
  cpu_pop_de();
  cpu_sbc_hl_de();
  /* adc hl,bc */
  cpu_push_hl();
  cpu_pop_bc();
  cpu_ex_de_hl();
  cpu_pop_de();
  set_hl((uint16_t)(hl() + bc()));
  lab_p29_L_4178: ;
  goto lab_p29_L_4117;
  lab_p29_L_417B: ;
  p00_L_24A9();
  if (flag_nz()) goto lab_p29_L_41DF;
  a = mem_read8(0x9C20);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_41DF;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p29_L_41A4;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p29_L_41B2;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p29_L_41C0;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p29_L_41D1;
  p29_L_427F();
  p29_L_4211();
  p29_L_425E();
  p29_L_4228();
  goto lab_p29_L_41E2;
  lab_p29_L_41A4: ;
  p29_L_4261();
  p29_L_4211();
  p29_L_427C();
  p29_L_4230();
  goto lab_p29_L_41E2;
  lab_p29_L_41B2: ;
  p29_L_4214();
  p29_L_425E();
  p29_L_427C();
  p29_L_4238();
  goto lab_p29_L_41E2;
  lab_p29_L_41C0: ;
  p29_L_4214();
  p29_L_42A2();
  p29_L_4269();
  p29_L_428F();
  p29_L_4238();
  goto lab_p29_L_41E2;
  lab_p29_L_41D1: ;
  p29_L_42A2();
  p29_L_425E();
  p29_L_428F();
  p29_L_4211();
  goto lab_p29_L_41E2;
  lab_p29_L_41DF: ;
  p29_L_427F();
  lab_p29_L_41E2: ;
  p29_L_4894();
  cpu_ex_de_hl();
  b = 0x8F;
  p29_L_456D();
  cpu_pop_hl();
  cpu_ex_de_hl();
  p29_L_4894();
  cpu_ex_de_hl();
  cpu_push_de();
  p29_L_457C();
  cpu_pop_de();
  b = 0x00;
  p29_L_456D();
  set_bc(mem_read16(0x84AF));
  a = c;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p29_L_420D;
  p29_L_4894();
  cpu_ex_de_hl();
  cpu_pop_bc();
  cpu_pop_hl();
  p29_L_42AE();
  lab_p29_L_420D: ;
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_de();
  return;
}

/* flash page 29 cpu 0x4211 (offset 0x0211) */
void p29_L_4211(void) {
  p29_L_4243();
  p29_L_4214();
  return;
}

/* flash page 29 cpu 0x4214 (offset 0x0214) */
void p29_L_4214(void) {
  p29_L_522B();
  set_bc(0x0066);
  set_de(0x82A5);
  p29_L_421D();
  return;
}

/* flash page 29 cpu 0x421D (offset 0x021D) */
void p29_L_421D(void) {
  p29_L_4897();
  cpu_ex_de_hl();
  p29_L_7700();
  p29_L_7666();
  return;
}

/* flash page 29 cpu 0x4228 (offset 0x0228) */
void p29_L_4228(void) {
  p29_L_521D();
  set_bc(0x00E8);
  goto lab_p29_L_423E;
  lab_p29_L_423E: ;
  p29_L_4897();
  goto lab_p29_L_4249;
  lab_p29_L_4249: ;
  set_de(0x82A5);
  p29_L_424C();
  return;
}

/* flash page 29 cpu 0x4230 (offset 0x0230) */
void p29_L_4230(void) {
  p29_L_5236();
  set_bc(0x00C8);
  goto lab_p29_L_423E;
  lab_p29_L_423E: ;
  p29_L_4897();
  goto lab_p29_L_4249;
  lab_p29_L_4249: ;
  set_de(0x82A5);
  p29_L_424C();
  return;
}

/* flash page 29 cpu 0x4238 (offset 0x0238) */
void p29_L_4238(void) {
  p29_L_522B();
  set_bc(0x0066);
  p29_L_4897();
  goto lab_p29_L_4249;
  lab_p29_L_4249: ;
  set_de(0x82A5);
  p29_L_424C();
  return;
}

/* flash page 29 cpu 0x4243 (offset 0x0243) */
void p29_L_4243(void) {
  p29_L_522B();
  set_bc(0x0066);
  set_de(0x82A5);
  p29_L_424C();
  return;
}

/* flash page 29 cpu 0x424C (offset 0x024C) */
void p29_L_424C(void) {
  p29_L_7700();
  p29_L_6B49();
  return;
}

/* flash page 29 cpu 0x4253 (offset 0x0253) */
void p29_L_4253(void) {
  p29_L_5217();
  set_bc(0x0020);
  set_de(0x836D);
  p29_L_424C();
  return;
}

/* flash page 29 cpu 0x425E (offset 0x025E) */
void p29_L_425E(void) {
  p29_L_4274();
  p29_L_4261();
  return;
}

/* flash page 29 cpu 0x4261 (offset 0x0261) */
void p29_L_4261(void) {
  goto lab_p29_L_4261;
  lab_p29_L_421A: ;
  set_de(0x82A5);
  p29_L_421D();
  return;
  lab_p29_L_4261: ;
  p29_L_5236();
  set_bc(0x00C8);
  goto lab_p29_L_421A;
}

/* flash page 29 cpu 0x4269 (offset 0x0269) */
void p29_L_4269(void) {
  p29_L_5236();
  set_bc(0x00C8);
  set_de(0x8000);
  p29_L_421D();
  return;
}

/* flash page 29 cpu 0x4274 (offset 0x0274) */
void p29_L_4274(void) {
  goto lab_p29_L_4274;
  lab_p29_L_4249: ;
  set_de(0x82A5);
  p29_L_424C();
  return;
  lab_p29_L_4274: ;
  p29_L_5236();
  set_bc(0x00C8);
  goto lab_p29_L_4249;
}

/* flash page 29 cpu 0x427C (offset 0x027C) */
void p29_L_427C(void) {
  p29_L_4287();
  p29_L_427F();
  return;
}

/* flash page 29 cpu 0x427F (offset 0x027F) */
void p29_L_427F(void) {
  goto lab_p29_L_427F;
  lab_p29_L_421A: ;
  set_de(0x82A5);
  p29_L_421D();
  return;
  lab_p29_L_427F: ;
  p29_L_521D();
  set_bc(0x00E8);
  goto lab_p29_L_421A;
}

/* flash page 29 cpu 0x4287 (offset 0x0287) */
void p29_L_4287(void) {
  goto lab_p29_L_4287;
  lab_p29_L_4249: ;
  set_de(0x82A5);
  p29_L_424C();
  return;
  lab_p29_L_4287: ;
  p29_L_521D();
  set_bc(0x00E8);
  goto lab_p29_L_4249;
}

/* flash page 29 cpu 0x428F (offset 0x028F) */
void p29_L_428F(void) {
  goto lab_p29_L_428F;
  lab_p29_L_421A: ;
  set_de(0x82A5);
  p29_L_421D();
  return;
  lab_p29_L_428F: ;
  p29_L_429A();
  p29_L_521D();
  set_bc(0x00C8);
  goto lab_p29_L_421A;
}

/* flash page 29 cpu 0x429A (offset 0x029A) */
void p29_L_429A(void) {
  goto lab_p29_L_429A;
  lab_p29_L_4249: ;
  set_de(0x82A5);
  p29_L_424C();
  return;
  lab_p29_L_429A: ;
  p29_L_521D();
  set_bc(0x00C8);
  goto lab_p29_L_4249;
}

/* flash page 29 cpu 0x42A2 (offset 0x02A2) */
void p29_L_42A2(void) {
  p29_L_523C();
  set_bc(0x0020);
  set_de(0x836D);
  p29_L_421D();
  return;
}

/* flash page 29 cpu 0x42AE (offset 0x02AE) */
void p29_L_42AE(void) {
  lab_p29_L_42AE: ;
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  p29_L_5242();
  a = (uint8_t)(a + 1);
  set_de(0x8478);
  set_bc(0x0001);
  p29_L_6B49();
  cpu_pop_de();
  cpu_push_de();
  set_hl(0x8478);
  p29_L_7700();
  p29_L_7663();
  cpu_pop_de();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_42AE;
  p29_L_42D3();
  return;
}

/* flash page 29 cpu 0x42D3 (offset 0x02D3) */
void p29_L_42D3(void) {
  p29_L_5242();
  cpu_push_af();
  os_bcall(0x8084);
  cpu_pop_af();
  p29_L_5287();
  return;
}

/* flash page 29 cpu 0x42DF (offset 0x02DF) */
void p29_L_42DF(void) {
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  p29_L_42D3();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  lab_p29_L_42E8: ;
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  set_de(0x8478);
  set_bc(0x0001);
  p29_L_424C();
  cpu_pop_de();
  cpu_push_de();
  set_hl(0x8478);
  p29_L_5242();
  a = (uint8_t)(a + 1);
  set_bc(0x0001);
  os_bcall(0x8087);
  cpu_pop_de();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_42E8;
  return;
}

/* flash page 29 cpu 0x42ED (offset 0x02ED) */
void p29_L_42ED(void) {
  goto lab_p29_L_42ED;
  lab_p29_L_42E8: ;
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  set_de(0x8478);
  lab_p29_L_42ED: ;
  a = (uint8_t)(a + h);
  set_bc(0x0001);
  p29_L_424C();
  cpu_pop_de();
  cpu_push_de();
  set_hl(0x8478);
  p29_L_5242();
  a = (uint8_t)(a + 1);
  set_bc(0x0001);
  os_bcall(0x8087);
  cpu_pop_de();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_42E8;
  return;
}

/* flash page 29 cpu 0x430E (offset 0x030E) */
void p29_L_430E(void) {
  cpu_push_bc();
  cpu_push_de();
  a = 0x02;
  p29_L_40CC();
  os_bcall(0x802D);
  cpu_push_hl();
  os_bcall(0x8057);
  set_de(0x1F18);
  p00_L_24A9();
  if (flag_nz()) goto lab_p29_L_4327;
  set_de(0x1DEA);
  lab_p29_L_4327: ;
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_de();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p29_L_433D;
  cpu_sbc_hl_bc();
  p29_L_4330();
  return;
  lab_p29_L_433D: ;
  cpu_pop_de();
  cpu_pop_de();
  return;
}

/* flash page 29 cpu 0x4330 (offset 0x0330) */
void p29_L_4330(void) {
  if (flag_c()) goto lab_p29_L_433D;
  os_bcall(0x802D);
  cpu_pop_de();
  cpu_ex_de_hl();
  cpu_pop_bc();
  p29_L_4083();
  a = 0;
  flag_logic(a);
  return;
  lab_p29_L_433D: ;
  cpu_pop_de();
  cpu_pop_de();
  return;
}

/* flash page 29 cpu 0x4340 (offset 0x0340) */
void p29_L_4340(void) {
  cpu_push_hl();
  p29_L_4894();
  p29_L_4574();
  cpu_push_bc();
  cpu_push_hl();
  p29_L_4894();
  cpu_push_hl();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  cpu_pop_hl();
  /* adc hl,bc */
  cpu_push_hl();
  cpu_pop_bc();
  p29_L_4894();
  os_bcall(0x808D);
  lab_p29_L_435E: ;
  cpu_push_hl();
  cpu_push_bc();
  set_bc(0x0001);
  set_de(0x82A5);
  p29_L_424C();
  set_bc(0x0001);
  set_hl(0x82A5);
  os_bcall(0x8090);
  cpu_pop_bc();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_435E;
  os_bcall(0x8018);
  p29_L_4894();
  p29_L_7700();
  p29_L_55CE();
  if (flag_nz()) goto lab_p29_L_43EC;
  set_hl(0x82A5);
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  p29_L_4894();
  set_hl((uint16_t)(hl() + 1));
  p29_L_4566();
  a = a & 0xF0;
  flag_logic(a);
  set_hl(0x0310);
  flag_cmp(a, l);
  if (flag_nz()) goto lab_p29_L_43B9;
  p29_L_7700();
  p29_L_762A();
  p29_L_4442();
  if (flag_nz()) goto lab_p29_L_43DA;
  /* adc hl,bc */
  p29_L_7700();
  set_de(0x0830);
  os_bcall(0x8030);
  if (flag_nz()) goto lab_p29_L_43DA;
  goto lab_p29_L_43CF;
  lab_p29_L_43B9: ;
  set_hl(0x0320);
  flag_cmp(a, l);
  if (flag_nz()) goto lab_p29_L_43C4;
  os_bcall(0x80CC);
  goto lab_p29_L_43DA;
  lab_p29_L_43C4: ;
  set_de(0x0A20);
  os_bcall(0x8027);
  if (flag_nz()) goto lab_p29_L_43DA;
  p29_L_4574();
  lab_p29_L_43CF: ;
  set_hl((uint16_t)(hl() - 1));
  set_bc((uint16_t)(bc() + 1));
  p29_L_7700();
  set_de(0x8000);
  os_bcall(0x8054);
  lab_p29_L_43DA: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  os_bcall(0x801B);
  set_de(0x8478);
  set_hl(0x8291);
  os_bcall(0x801E);
  if (flag_z()) goto lab_p29_L_43F4;
  lab_p29_L_43EC: ;
  cpu_push_af();
  p29_L_43ED();
  return;
  lab_p29_L_43F4: ;
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x43ED (offset 0x03ED) */
void p29_L_43ED(void) {
  p29_L_4894();
  os_bcall(0x8060);
  cpu_pop_af();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x43F6 (offset 0x03F6) */
void p29_L_43F6(void) {
  cpu_push_af();
  p29_L_5525();
  if (flag_nz()) goto lab_p29_L_4429;
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8051);
  mem_write8(0x83E6, a);
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  os_bcall(0x8051);
  mem_write8(0x83E7, a);
  cpu_pop_af();
  os_bcall(0x809F);
  set_hl(0x82A5);
  os_bcall(0x80A2);
  os_bcall(0x80A5);
  set_de(0x83A5);
  set_hl(0x8478);
  os_bcall(0x801E);
  return;
  lab_p29_L_4429: ;
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 29 cpu 0x442C (offset 0x042C) */
void p29_L_442C(void) {
  cpu_push_hl();
  cpu_push_af();
  c = a;
  set_de(0x0400);
  os_bcall(0x805D);
  if (flag_nz()) goto lab_p29_L_4441;
  set_hl((uint16_t)(hl() + 1));
  a = c;
  cpu_push_de();
  os_bcall(0x805A);
  cpu_pop_de();
  cpu_ex_de_hl();
  cpu_pop_af();
  cpu_pop_hl();
  lab_p29_L_4441: ;
  return;
}

/* flash page 29 cpu 0x4442 (offset 0x0442) */
void p29_L_4442(void) {
  cpu_push_hl();
  cpu_push_bc();
  p29_L_70D1();
  set_de(0x0800);
  p29_L_777E();
  p29_L_4574();
  cpu_pop_bc();
  cpu_pop_de();
  lab_p29_L_4452: ;
  cpu_push_de();
  cpu_push_bc();
  cpu_push_bc();
  cpu_push_de();
  set_de(0x0810);
  p29_L_7700();
  os_bcall(0x8030);
  cpu_pop_de();
  a = c;
  cpu_pop_bc();
  if (flag_nz()) goto lab_p29_L_4489;
  flag_cmp(a, c);
  cpu_push_hl();
  c = a;
  b = 0x00;
  cpu_push_bc();
  if (flag_nz()) goto lab_p29_L_4482;
  b = c;
  lab_p29_L_446D: ;
  p29_L_7700();
  p29_L_4C73();
  if (flag_nz()) goto lab_p29_L_4482;
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_446D;
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_de();
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  return;
  lab_p29_L_4482: ;
  cpu_pop_bc();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_bc();
  cpu_pop_de();
  goto lab_p29_L_4452;
  lab_p29_L_4489: ;
  cpu_pop_bc();
  cpu_pop_de();
  a = 0xFF;
  flag_set_z((a & (1u << 7)) == 0);
  return;
}

/* flash page 29 cpu 0x4490 (offset 0x0490) */
void p29_L_4490(void) {
  cpu_push_hl();
  cpu_push_bc();
  p29_L_4442();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x4498 (offset 0x0498) */
void p29_L_4498(void) {
  p29_L_7700();
  p29_L_4894();
  p29_L_7700();
  p29_L_4873();
  p29_L_70D1();
  if (flag_nz()) goto lab_p29_L_44B8;
  p29_L_7700();
  cpu_push_bc();
  p29_L_4873();
  cpu_push_bc();
  cpu_pop_hl();
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nc()) goto lab_p29_L_44BE;
  lab_p29_L_44B8: ;
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  goto lab_p29_L_44C2;
  lab_p29_L_44BE: ;
  a = 0xFF;
  flag_set_z((a & (1u << 7)) == 0);
  lab_p29_L_44C2: ;
  return;
}

/* flash page 29 cpu 0x44C3 (offset 0x04C3) */
void p29_L_44C3(void) {
  p29_L_4894();
  p29_L_7700();
  p29_L_442C();
  cpu_push_de();
  cpu_push_bc();
  set_de(0x0A10);
  os_bcall(0x8027);
  cpu_push_de();
  p29_L_4574();
  cpu_pop_de();
  a = c;
  cpu_pop_bc();
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p29_L_44F7;
  cpu_ex_de_hl();
  cpu_pop_hl();
  b = c;
  lab_p29_L_44E1: ;
  cpu_ex_de_hl();
  p29_L_4566();
  c = a;
  cpu_ex_de_hl();
  p29_L_4566();
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p29_L_44F8;
  b = (uint8_t)(b - 1);
  a = b;
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p29_L_44F8;
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  goto lab_p29_L_44E1;
  lab_p29_L_44F7: ;
  cpu_pop_bc();
  lab_p29_L_44F8: ;
  return;
}

/* flash page 29 cpu 0x44F9 (offset 0x04F9) */
void p29_L_44F9(void) {
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
  p29_L_7700();
  p29_L_4894();
  p29_L_4574();
  p29_L_7700();
  p29_L_50C5();
  if (flag_nz()) goto lab_p29_L_4530;
  set_de(0x0320);
  os_bcall(0x8027);
  if (flag_nz()) goto lab_p29_L_4529;
  p29_L_7700();
  os_bcall(0x802A);
  lab_p29_L_4529: ;
  p29_L_4894();
  p29_L_5083();
  a = 0;
  flag_logic(a);
  lab_p29_L_4530: ;
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x4533 (offset 0x0533) */
void p29_L_4533(void) {
  p29_L_5217();
  p29_L_4566();
  mem_write8(0x843A, a);
  set_hl((uint16_t)(hl() + 1));
  p29_L_4566();
  mem_write8(0x843B, a);
  p00_L_24A9();
  if (flag_nz()) return;
  set_hl((uint16_t)(hl() + 1));
  p29_L_7700();
  set_bc(0x000B);
  set_de(0x9C9E);
  p29_L_6B49();
  set_hl(0x9CA8);
  a = 0xFE;
  /* or (hl) */
  mem_write8(hl(), a);
  return;
}

/* flash page 29 cpu 0x455C (offset 0x055C) */
void p29_L_455C(void) {
  p29_L_4565();
  e = a;
  p29_L_4565();
  d = a;
  return;
}

/* flash page 29 cpu 0x4565 (offset 0x0565) */
void p29_L_4565(void) {
  set_hl((uint16_t)(hl() + 1));
  p29_L_4566();
  return;
}

/* flash page 29 cpu 0x4566 (offset 0x0566) */
void p29_L_4566(void) {
  p29_L_7700();
  p29_L_6B36();
  return;
}

/* flash page 29 cpu 0x456D (offset 0x056D) */
void p29_L_456D(void) {
  p29_L_7700();
  os_bcall(0x8021);
  return;
}

/* flash page 29 cpu 0x4574 (offset 0x0574) */
void p29_L_4574(void) {
  set_hl((uint16_t)(hl() + 1));
  p29_L_4575();
  return;
}

/* flash page 29 cpu 0x4575 (offset 0x0575) */
void p29_L_4575(void) {
  p29_L_7700();
  os_bcall(0x805A);
  return;
}

/* flash page 29 cpu 0x457C (offset 0x057C) */
void p29_L_457C(void) {
  p29_L_7700();
  os_bcall(0x8024);
  return;
}

/* flash page 29 cpu 0x4583 (offset 0x0583) */
void p29_L_4583(void) {
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
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  cpu_push16(ix);
  p29_L_4533();
  p29_L_44C3();
  if (flag_nz()) goto lab_p29_L_45D9;
  p29_L_4498();
  if (flag_nz()) goto lab_p29_L_45D9;
  p29_L_50A8();
  p29_L_4C8B();
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 6)));
  a = 0;
  flag_logic(a);
  mem_write8(0x9C87, a);
  p29_L_70D1();
  set_bc(0x0000);
  if (flag_nz()) goto lab_p29_L_45BF;
  os_bcall(0x802A);
  lab_p29_L_45BF: ;
  p29_L_468A();
  p29_L_70D1();
  p29_L_45E4();
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  lab_p29_L_45CC: ;
  cpu_push_af();
  p29_L_4926();
  cpu_pop_af();
  ix = cpu_pop16();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  p29_L_5FDB();
  return;
  lab_p29_L_45D9: ;
  p29_L_4894();
  os_bcall(0x8060);
  a = 0xFF;
  a = a | a;
  flag_logic(a);
  goto lab_p29_L_45CC;
}

/* flash page 29 cpu 0x45E4 (offset 0x05E4) */
void p29_L_45E4(void) {
  cpu_push_bc();
  cpu_push_de();
  a = mem_read8(0x843A);
  b = a;
  p29_L_5217();
  cpu_ex_de_hl();
  p29_L_456D();
  a = mem_read8(0x843B);
  b = a;
  p29_L_456D();
  p00_L_24A9();
  if (flag_nz()) goto lab_p29_L_4609;
  p29_L_7700();
  set_bc(0x000B);
  set_hl(0x9C9E);
  os_bcall(0x8087);
  lab_p29_L_4609: ;
  p29_L_70D1();
  if (flag_nz()) goto lab_p29_L_464B;
  p29_L_464E();
  p29_L_4574();
  set_hl((uint16_t)(hl() + bc()));
  p29_L_70D1();
  set_de(0x0800);
  p29_L_777E();
  p29_L_4574();
  lab_p29_L_4621: ;
  set_de(0x0810);
  p29_L_7700();
  os_bcall(0x8030);
  if (flag_nz()) goto lab_p29_L_464B;
  cpu_push_hl();
  cpu_push_bc();
  b = c;
  mem_write16(0x8483, bc());
  b = 0x00;
  p29_L_7700();
  set_de(0x8484);
  os_bcall(0x8054);
  os_bcall(0x8066);
  if (flag_nz()) goto lab_p29_L_4646;
  p29_L_464E();
  lab_p29_L_4646: ;
  cpu_pop_bc();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + bc()));
  goto lab_p29_L_4621;
  lab_p29_L_464B: ;
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x464E (offset 0x064E) */
void p29_L_464E(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  cpu_push16(ix);
  os_bcall(0x8099);
  set_de(0x0700);
  p29_L_777E();
  p29_L_4574();
  lab_p29_L_4660: ;
  set_de(0x0710);
  p29_L_705E();
  if (flag_nz()) goto lab_p29_L_4683;
  p29_L_4574();
  cpu_push_bc();
  cpu_push_hl();
  p29_L_7700();
  set_de(0x838F);
  os_bcall(0x8054);
  os_bcall(0x80A8);
  if (flag_z()) goto lab_p29_L_467E;
  p29_L_51C3();
  lab_p29_L_467E: ;
  cpu_pop_hl();
  cpu_pop_bc();
  set_hl((uint16_t)(hl() + bc()));
  goto lab_p29_L_4660;
  lab_p29_L_4683: ;
  ix = cpu_pop16();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x468A (offset 0x068A) */
void p29_L_468A(void) {
  p29_L_4894();
  cpu_push_hl();
  p29_L_4574();
  set_hl((uint16_t)(hl() + bc()));
  p29_L_4574();
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_bc();
  cpu_push_bc();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_bc();
  cpu_push_hl();
  set_de(0x4000);
  p29_L_42DF();
  cpu_pop_hl();
  cpu_push_hl();
  os_bcall(0x8060);
  cpu_pop_de();
  cpu_pop_bc();
  set_hl(0x4000);
  cpu_push_bc();
  p29_L_42AE();
  p29_L_4894();
  cpu_pop_bc();
  cpu_ex_de_hl();
  a = d;
  a = a ^ 0x20;
  flag_logic(a);
  d = a;
  p29_L_430E();
  if (flag_z()) return;
  p29_L_5FDB();
  p00_L_2565();
  return;
}

/* flash page 29 cpu 0x46C7 (offset 0x06C7) */
void p29_L_46C7(void) {
  cpu_push_de();
  cpu_push_bc();
  p29_L_762A();
  mem_write16(0x8483, bc());
  set_de(0x8484);
  p29_L_7700();
  os_bcall(0x8054);
  os_bcall(0x8066);
  if (flag_nz()) goto lab_p29_L_4715;
  cpu_push_hl();
  set_de(0x0100);
  p29_L_777E();
  if (flag_nz()) goto lab_p29_L_4714;
  p29_L_4574();
  cpu_push_hl();
  p29_L_4894();
  set_de(0x0100);
  p29_L_777E();
  p29_L_4574();
  cpu_pop_de();
  cpu_ex_de_hl();
  p29_L_7700();
  p29_L_5CFF();
  p29_L_5D1E();
  cpu_ex_de_hl();
  p29_L_7700();
  p29_L_5CFF();
  p29_L_5D43();
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  lab_p29_L_4714: ;
  cpu_pop_hl();
  lab_p29_L_4715: ;
  cpu_pop_bc();
  cpu_pop_de();
  return;
}

/* flash page 29 cpu 0x4718 (offset 0x0718) */
void p29_L_4718(void) {
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  p29_L_7634();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  p29_L_4490();
  if (flag_nz()) goto lab_p29_L_47A5;
  p29_L_46C7();
  if (flag_nz()) goto lab_p29_L_4746;
  if (flag_nc()) goto lab_p29_L_47A5;
  os_bcall(0x8066);
  if (flag_nz()) goto lab_p29_L_4746;
  p29_L_50A8();
  p29_L_46C7();
  os_bcall(0x8066);
  p29_L_47E3();
  os_bcall(0x802A);
  goto lab_p29_L_474C;
  lab_p29_L_4746: ;
  p29_L_50A8();
  p29_L_5124();
  lab_p29_L_474C: ;
  set_de(0x836D);
  p29_L_5217();
  set_bc(0x0020);
  p29_L_7700();
  os_bcall(0x8054);
  p29_L_521D();
  set_bc(0x000D);
  /* sla c */
  p29_L_7700();
  set_de(0x82A5);
  os_bcall(0x8054);
  p29_L_762A();
  mem_write16(0x838D, bc());
  set_de(0x838E);
  p29_L_7700();
  os_bcall(0x8054);
  p29_L_468A();
  set_bc(mem_read16(0x838D));
  b = 0x00;
  mem_write16(0x8483, bc());
  set_hl(0x838E);
  set_de(0x8484);
  while (bc() != 0) { cpu_ldi(); }
  os_bcall(0x8066);
  p29_L_45E4();
  p29_L_4894();
  os_bcall(0x8060);
  p29_L_4926();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  a = 0;
  flag_logic(a);
  return;
  lab_p29_L_47A5: ;
  p29_L_4894();
  os_bcall(0x8060);
  p29_L_4926();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  a = 0xFF;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 29 cpu 0x475F (offset 0x075F) */
void p29_L_475F(void) {
  c = (uint8_t)(c - 1);
  /* nop */
  /* sla c */
  p29_L_7700();
  set_de(0x82A5);
  os_bcall(0x8054);
  p29_L_762A();
  mem_write16(0x838D, bc());
  set_de(0x838E);
  p29_L_7700();
  os_bcall(0x8054);
  p29_L_468A();
  set_bc(mem_read16(0x838D));
  b = 0x00;
  mem_write16(0x8483, bc());
  set_hl(0x838E);
  set_de(0x8484);
  while (bc() != 0) { cpu_ldi(); }
  os_bcall(0x8066);
  p29_L_45E4();
  p29_L_4894();
  os_bcall(0x8060);
  p29_L_4926();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 29 cpu 0x476B (offset 0x076B) */
void p29_L_476B(void) {
  a = (uint8_t)(a + b);
  p29_L_762A();
  mem_write16(0x838D, bc());
  set_de(0x838E);
  p29_L_7700();
  os_bcall(0x8054);
  p29_L_468A();
  set_bc(mem_read16(0x838D));
  b = 0x00;
  mem_write16(0x8483, bc());
  set_hl(0x838E);
  set_de(0x8484);
  while (bc() != 0) { cpu_ldi(); }
  os_bcall(0x8066);
  p29_L_45E4();
  p29_L_4894();
  os_bcall(0x8060);
  p29_L_4926();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 29 cpu 0x47B5 (offset 0x07B5) */
void p29_L_47B5(void) {
  a = 0;
  flag_logic(a);
  p29_L_47B6();
  return;
}

/* flash page 29 cpu 0x47B6 (offset 0x07B6) */
void p29_L_47B6(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  cpu_push16(ix);
  p00_L_24A9();
  if (flag_nz()) goto lab_p29_L_47D9;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p29_L_47D1;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p29_L_47D9;
  p29_L_4243();
  p29_L_4253();
  goto lab_p29_L_47DC;
  lab_p29_L_47D1: ;
  p29_L_4274();
  p29_L_4253();
  goto lab_p29_L_47DC;
  lab_p29_L_47D9: ;
  p29_L_4287();
  lab_p29_L_47DC: ;
  ix = cpu_pop16();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x47CD (offset 0x07CD) */
void p29_L_47CD(void) {
  d = e;
  b = d;
  goto lab_p29_L_47DC;
  lab_p29_L_47DC: ;
  ix = cpu_pop16();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x47E3 (offset 0x07E3) */
void p29_L_47E3(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_af();
  p29_L_47B5();
  set_de(0x0700);
  p29_L_777E();
  p29_L_4574();
  cpu_push_hl();
  p29_L_4894();
  set_de(0x0700);
  p29_L_777E();
  p29_L_4574();
  cpu_pop_de();
  cpu_push_hl();
  cpu_push_de();
  p29_L_762A();
  cpu_push_hl();
  cpu_push_bc();
  p29_L_484E();
  ix = (uint16_t)(ix + 1);
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push16(ix);
  p29_L_4442();
  set_hl((uint16_t)(hl() + bc()));
  p29_L_7700();
  set_de(0x0810);
  os_bcall(0x8030);
  if (flag_nz()) goto lab_p29_L_4825;
  p29_L_484E();
  goto lab_p29_L_483E;
  lab_p29_L_4825: ;
  set_hl(0x838D);
  a = 0xFF;
  b = 0x05;
  lab_p29_L_482C: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_482C;
  set_hl(0x84AF);
  mem_write8(hl(), 0x01);
  os_bcall(0x8069);
  p29_L_764E();
  cpu_push_hl();
  ix = cpu_pop16();
  lab_p29_L_483E: ;
  cpu_push16(ix);
  cpu_pop_bc();
  ix = cpu_pop16();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_bc();
  p29_L_4D5E();
  ix = (uint16_t)(ix + 1);
  p29_L_5156();
  return;
}

/* flash page 29 cpu 0x484E (offset 0x084E) */
void p29_L_484E(void) {
  d = c;
  d = (uint8_t)(d | (1u << 4));
  e = 0x07;
  mem_write16(0x838D, de());
  set_de(0x838F);
  p29_L_7700();
  os_bcall(0x8054);
  set_hl(0x84AF);
  mem_write8(hl(), 0x01);
  os_bcall(0x8069);
  if (flag_z()) goto lab_p29_L_486C;
  ix = (uint16_t)(ix - 1);
  lab_p29_L_486C: ;
  p29_L_764E();
  cpu_push_hl();
  ix = cpu_pop16();
  return;
}

/* flash page 29 cpu 0x4873 (offset 0x0873) */
void p29_L_4873(void) {
  cpu_push_hl();
  cpu_push_af();
  cpu_push_de();
  cpu_push_af();
  set_de(0x0100);
  os_bcall(0x805D);
  if (flag_nz()) goto lab_p29_L_488F;
  cpu_pop_af();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  p29_L_7700();
  p29_L_5CFF();
  p29_L_5D43();
  goto lab_p29_L_4890;
  lab_p29_L_488F: ;
  cpu_pop_af();
  lab_p29_L_4890: ;
  cpu_pop_de();
  cpu_pop_af();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x4894 (offset 0x0894) */
void p29_L_4894(void) {
  os_bcall(0x8057);
}

/* flash page 29 cpu 0x4897 (offset 0x0897) */
void p29_L_4897(void) {
  cpu_push_af();
  a = h;
  a = a ^ 0x20;
  flag_logic(a);
  h = a;
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x489E (offset 0x089E) */
void p29_L_489E(void) {
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
  p29_L_48B5();
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x48B5 (offset 0x08B5) */
void p29_L_48B5(void) {
  p29_L_5231();
  p29_L_48BC();
  return;
}

/* flash page 29 cpu 0x48BC (offset 0x08BC) */
void p29_L_48BC(void) {
  cpu_push16(ix);
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push16(ix);
  cpu_pop_hl();
  set_bc(0x00C9);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nc()) { p00_L_2541(); return; }
  set_hl((uint16_t)(hl() + bc()));
  set_bc(0x0000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_m()) { p00_L_2541(); return; }
  cpu_pop_bc();
  cpu_pop_hl();
  p29_L_48EB();
  return;
}

/* flash page 29 cpu 0x48DE (offset 0x08DE) */
void p29_L_48DE(void) {
  cpu_push16(ix);
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  p29_L_521D();
  set_bc(0x000D);
  /* add ix,bc */
  p29_L_48EB();
  return;
}

/* flash page 29 cpu 0x48EB (offset 0x08EB) */
void p29_L_48EB(void) {
  cpu_push16(ix);
  cpu_pop_bc();
  /* sla c */
  set_hl((uint16_t)(hl() + bc()));
  p29_L_4566();
  flag_cmp(a, 0x80);
  /* scf */
  if (flag_z()) goto lab_p29_L_4902;
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p29_L_4902;
  p29_L_4565();
  flag_cmp(a, 0x00);
  lab_p29_L_4902: ;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  ix = cpu_pop16();
  return;
}

/* flash page 29 cpu 0x4908 (offset 0x0908) */
void p29_L_4908(void) {
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
  p29_L_6800();
  a = b;
  os_bcall(0x80CF);
  p29_L_4926();
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x4926 (offset 0x0926) */
void p29_L_4926(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  cpu_push16(ix);
  a = 0x00;
  mem_write8(0x8670, a);
  p29_L_4AC9();
  if (flag_nz()) goto lab_p29_L_4939;
  p29_L_4B82();
  lab_p29_L_4939: ;
  p29_L_4A5A();
  a = mem_read8(0x8670);
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p29_L_498B;
  set_hl(0x7037);
  a = 0x4D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p29_L_7045();
  p00_L_3CD5();
  set_hl(0x702B);
  a = 0x4E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p29_L_7045();
  p00_L_3CD5();
  p00_L_0B93();
  b = 0x05;
  lab_p29_L_496C: ;
  c = b;
  b = 0xFF;
  lab_p29_L_496F: ;
  a = 0xFF;
  lab_p29_L_4971: ;
  p00_L_0AC4();
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p29_L_4971;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_496F;
  b = c;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_496C;
  p00_L_0BA2();
  p00_L_2E65();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  p00_L_3D05();
  lab_p29_L_498B: ;
  ix = cpu_pop16();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x4992 (offset 0x0992) */
void p29_L_4992(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  p29_L_4565();
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
  p29_L_7700();
  set_de(0x838E);
  os_bcall(0x8054);
  p29_L_6021();
  if (flag_c()) goto lab_p29_L_49B7;
  p29_L_403F();
  lab_p29_L_49B7: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x49D8 (offset 0x09D8) */
void p29_L_49D8(void) {
  cpu_push_hl();
  set_hl(0x4000);
  cpu_push_af();
  p29_L_6B36();
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p29_L_4A1E;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x7E);
  if (flag_z()) goto lab_p29_L_4A1E;
  flag_cmp(a, 0x7F);
  if (flag_z()) goto lab_p29_L_4A1E;
  a = b;
  flag_cmp(a, 0x7E);
  if (flag_z()) goto lab_p29_L_4A1E;
  flag_cmp(a, 0x7F);
  if (flag_z()) goto lab_p29_L_4A1E;
  cpu_pop_af();
  lab_p29_L_49F8: ;
  cpu_push_bc();
  set_bc(0x0100);
  set_de(0x8000);
  cpu_push_hl();
  cpu_push_de();
  cpu_push_af();
  p29_L_6B49();
  cpu_pop_af();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_push_af();
  a = b;
  set_bc(0x0100);
  cpu_ex_de_hl();
  cpu_push_af();
  p29_L_7666();
  cpu_pop_af();
  cpu_ex_de_hl();
  b = a;
  a = 0x80;
  flag_cmp(a, h);
  if (flag_z()) goto lab_p29_L_4A1E;
  cpu_pop_af();
  goto lab_p29_L_49F8;
  lab_p29_L_4A1E: ;
  cpu_pop_af();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x4A21 (offset 0x0A21) */
void p29_L_4A21(void) {
  cpu_push_hl();
  a = 0x08;
  set_hl(0x4000);
  lab_p29_L_4A27: ;
  cpu_push_af();
  os_bcall(0x8051);
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p29_L_4A3C;
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  p29_L_75E1();
  if (flag_nz()) goto lab_p29_L_4A27;
  a = 0xFF;
  flag_set_z((a & (1u << 7)) == 0);
  cpu_pop_hl();
  return;
  lab_p29_L_4A3C: ;
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x4A3F (offset 0x0A3F) */
void p29_L_4A3F(void) {
  cpu_push_hl();
  cpu_push_af();
  set_hl(0x4000);
  set_de(0x8080);
  a = a | a;
  flag_logic(a);
  os_bcall(0x80AB);
  c = 0x00;
  if (flag_nz()) goto lab_p29_L_4A57;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8051);
  c = a;
  lab_p29_L_4A57: ;
  cpu_pop_af();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x4A5A (offset 0x0A5A) */
void p29_L_4A5A(void) {
  p29_L_7643();
  b = c;
  p29_L_75EC();
  lab_p29_L_4A61: ;
  cpu_push_af();
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p29_L_4A77;
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p29_L_4A77;
  flag_cmp(a, 0x80);
  if (flag_nz()) goto lab_p29_L_4A77;
  cpu_pop_af();
  goto lab_p29_L_4A80;
  lab_p29_L_4A77: ;
  cpu_pop_af();
  lab_p29_L_4A78: ;
  a = (uint8_t)(a - 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_4A61;
  return;
  lab_p29_L_4A7C: ;
  cpu_pop_af();
  cpu_pop_bc();
  goto lab_p29_L_4A77;
  lab_p29_L_4A80: ;
  cpu_push_af();
  cpu_push_bc();
  cpu_push_af();
  p00_L_3E31();
  if (flag_nz()) goto lab_p29_L_4A7C;
  cpu_pop_af();
  cpu_push_af();
  p29_L_5E31();
  os_bcall(0x80A8);
  if (flag_nz()) goto lab_p29_L_4AC4;
  cpu_pop_af();
  cpu_push_af();
  p29_L_52D9();
  if (flag_c()) goto lab_p29_L_4AC4;
  if (flag_z()) goto lab_p29_L_4AC4;
  cpu_pop_af();
  cpu_push_af();
  b = a;
  p29_L_75EC();
  a = (uint8_t)(a - b);
  set_bc(0x0000);
  c = a;
  cpu_push_bc();
  ix = cpu_pop16();
  p29_L_48B5();
  if (flag_c()) goto lab_p29_L_4AC4;
  if (flag_nz()) goto lab_p29_L_4AC4;
  a = mem_read8(0x8670);
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p29_L_4ABF;
  p00_L_2C7F();
  a = 0xFF;
  mem_write8(0x8670, a);
  lab_p29_L_4ABF: ;
  cpu_pop_af();
  cpu_push_af();
  p29_L_403F();
  lab_p29_L_4AC4: ;
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_af();
  goto lab_p29_L_4A78;
}

/* flash page 29 cpu 0x4AC9 (offset 0x0AC9) */
void p29_L_4AC9(void) {
  p29_L_70D1();
  if (flag_nz()) goto lab_p29_L_4B69;
  set_de(0x0700);
  p29_L_777E();
  p29_L_4574();
  ix = 0x0000;
  p29_L_4ADC();
  return;
  lab_p29_L_4B69: ;
  a = 0xFF;
  flag_set_z((a & (1u << 7)) == 0);
  return;
}

/* flash page 29 cpu 0x4ADC (offset 0x0ADC) */
void p29_L_4ADC(void) {
  lab_p29_L_4ADC: ;
  set_de(0x0710);
  p29_L_705E();
  if (flag_nz()) goto lab_p29_L_4B6E;
  cpu_push_hl();
  p29_L_4574();
  a = c;
  mem_write8(0x838E, a);
  set_de(0x838F);
  p29_L_424C();
  os_bcall(0x80A8);
  cpu_pop_hl();
  cpu_push_hl();
  if (flag_z()) goto lab_p29_L_4B5F;
  set_de(0x0740);
  p29_L_705E();
  if (flag_nz()) goto lab_p29_L_4B14;
  p29_L_7700();
  p29_L_50C5();
  if (flag_z()) goto lab_p29_L_4B14;
  p29_L_536F();
  p29_L_48DE();
  if (flag_c()) goto lab_p29_L_4B14;
  if (flag_z()) goto lab_p29_L_4B20;
  lab_p29_L_4B14: ;
  p29_L_540C();
  if (flag_z()) goto lab_p29_L_4B5F;
  cpu_pop_hl();
  cpu_push_hl();
  p29_L_4992();
  goto lab_p29_L_4B5F;
  lab_p29_L_4B20: ;
  a = mem_read8(0x8670);
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p29_L_4B3D;
  cpu_pop_de();
  cpu_push_de();
  cpu_push_hl();
  p29_L_4B73();
  p29_L_6021();
  if (flag_c()) goto lab_p29_L_4B51;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_de();
  p00_L_2C7F();
  a = 0xFF;
  mem_write8(0x8670, a);
  lab_p29_L_4B3D: ;
  cpu_pop_de();
  cpu_push_de();
  cpu_push_hl();
  p29_L_4B73();
  p29_L_6021();
  if (flag_c()) goto lab_p29_L_4B51;
  p00_L_2C8B();
  p00_L_3CD5();
  p29_L_403F();
  lab_p29_L_4B51: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_ex_de_hl();
  cpu_push_de();
  p29_L_4574();
  cpu_pop_de();
  set_hl((uint16_t)(hl() + bc()));
  ix = (uint16_t)(ix + 1);
  goto lab_p29_L_4ADC;
  lab_p29_L_4B5F: ;
  cpu_pop_hl();
  p29_L_4574();
  set_hl((uint16_t)(hl() + bc()));
  ix = (uint16_t)(ix + 1);
  goto lab_p29_L_4ADC;
  lab_p29_L_4B6E: ;
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  return;
}

/* flash page 29 cpu 0x4B73 (offset 0x0B73) */
void p29_L_4B73(void) {
  cpu_ex_de_hl();
  p29_L_4574();
  a = c;
  mem_write8(0x838D, a);
  set_de(0x838E);
  p29_L_424C();
  return;
}

/* flash page 29 cpu 0x4B82 (offset 0x0B82) */
void p29_L_4B82(void) {
  p29_L_70D1();
  set_de(0x0800);
  p29_L_777E();
  p29_L_4574();
  p29_L_4B8E();
  return;
}

/* flash page 29 cpu 0x4B8E (offset 0x0B8E) */
void p29_L_4B8E(void) {
  lab_p29_L_4B8E: ;
  set_de(0x0810);
  p29_L_705E();
  if (flag_nz()) goto lab_p29_L_4C0B;
  cpu_push_hl();
  set_de(0x0840);
  p29_L_705E();
  if (flag_nz()) goto lab_p29_L_4BC9;
  p29_L_7700();
  p29_L_50C5();
  if (flag_z()) goto lab_p29_L_4BE4;
  p29_L_536F();
  p29_L_48DE();
  if (flag_c()) goto lab_p29_L_4BC9;
  if (flag_nz()) goto lab_p29_L_4BE4;
  a = mem_read8(0x8670);
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p29_L_4BC9;
  p00_L_2C7F();
  a = 0xFF;
  mem_write8(0x8670, a);
  cpu_pop_de();
  cpu_push_de();
  p00_L_2C85();
  p00_L_3CD5();
  lab_p29_L_4BC9: ;
  cpu_pop_de();
  cpu_ex_de_hl();
  cpu_push_hl();
  p29_L_4574();
  set_de(0x8484);
  mem_write16(0x8483, bc());
  p29_L_7700();
  os_bcall(0x8054);
  os_bcall(0x8066);
  if (flag_nz()) goto lab_p29_L_4BE4;
  os_bcall(0x802A);
  lab_p29_L_4BE4: ;
  cpu_pop_de();
  cpu_ex_de_hl();
  cpu_push_hl();
  p29_L_4574();
  set_de(0x8484);
  mem_write16(0x8483, bc());
  p29_L_7700();
  os_bcall(0x8054);
  os_bcall(0x8066);
  if (flag_nz()) goto lab_p29_L_4C01;
  ix = (uint16_t)(ix + 1);
  p29_L_4C0C();
  lab_p29_L_4C01: ;
  cpu_pop_hl();
  p29_L_4574();
  set_hl((uint16_t)(hl() + bc()));
  ix = (uint16_t)(ix + 1);
  goto lab_p29_L_4B8E;
  lab_p29_L_4C0B: ;
  return;
}

/* flash page 29 cpu 0x4C0C (offset 0x0C0C) */
void p29_L_4C0C(void) {
  set_de(0x0700);
  p29_L_777E();
  p29_L_4574();
  lab_p29_L_4C15: ;
  set_de(0x0710);
  p29_L_705E();
  if (flag_nz()) goto lab_p29_L_4C70;
  cpu_push_hl();
  set_de(0x0740);
  p29_L_705E();
  if (flag_nz()) goto lab_p29_L_4C38;
  p29_L_7700();
  p29_L_50C5();
  if (flag_z()) goto lab_p29_L_4C38;
  p29_L_536F();
  p29_L_48DE();
  if (flag_c()) goto lab_p29_L_4C38;
  if (flag_z()) goto lab_p29_L_4C3B;
  lab_p29_L_4C38: ;
  cpu_pop_hl();
  goto lab_p29_L_4C68;
  lab_p29_L_4C3B: ;
  a = mem_read8(0x8670);
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p29_L_4C55;
  cpu_pop_de();
  cpu_push_de();
  cpu_push_hl();
  p29_L_6021();
  if (flag_c()) goto lab_p29_L_4C66;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_de();
  p00_L_2C7F();
  a = 0xFF;
  mem_write8(0x8670, a);
  lab_p29_L_4C55: ;
  cpu_pop_de();
  cpu_push_de();
  cpu_push_hl();
  p29_L_6021();
  if (flag_c()) goto lab_p29_L_4C66;
  p00_L_2C8B();
  p00_L_3CD5();
  p29_L_403F();
  lab_p29_L_4C66: ;
  cpu_pop_hl();
  cpu_pop_de();
  lab_p29_L_4C68: ;
  p29_L_4574();
  set_hl((uint16_t)(hl() + bc()));
  ix = (uint16_t)(ix + 1);
  goto lab_p29_L_4C15;
  lab_p29_L_4C70: ;
  ix = (uint16_t)(ix - 1);
  return;
}

/* flash page 29 cpu 0x4C73 (offset 0x0C73) */
void p29_L_4C73(void) {
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  cpu_push_af();
  os_bcall(0x8051);
  mem_write8(0x8483, a);
  cpu_ex_de_hl();
  cpu_pop_af();
  os_bcall(0x8051);
  set_bc(mem_read16(0x8483));
  flag_cmp(a, c);
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x4C8B (offset 0x0C8B) */
void p29_L_4C8B(void) {
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_af();
  p29_L_4F62();
  p29_L_4D38();
  p29_L_4CAE();
  p29_L_521D();
  set_bc(0x000D);
  /* sla c */
  p29_L_7700();
  set_de(0x82A5);
  os_bcall(0x8054);
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x4CAE (offset 0x0CAE) */
void p29_L_4CAE(void) {
  p29_L_70D1();
  if (flag_nz()) goto lab_p29_L_4CF7;
  set_de(0x0800);
  p29_L_777E();
  if (flag_nz()) goto lab_p29_L_4CF7;
  p29_L_4574();
  cpu_push_hl();
  p29_L_4894();
  set_de(0x0800);
  p29_L_777E();
  if (flag_nz()) goto lab_p29_L_4D36;
  p29_L_4574();
  cpu_pop_de();
  cpu_ex_de_hl();
  ix = (uint16_t)(ix + 1);
  lab_p29_L_4CD2: ;
  cpu_push_hl();
  lab_p29_L_4CD3: ;
  p29_L_4F95();
  if (flag_nz()) goto lab_p29_L_4CDD;
  p29_L_4F10();
  goto lab_p29_L_4D1D;
  lab_p29_L_4CDD: ;
  cpu_push_de();
  cpu_push16(ix);
  set_de(0x0810);
  p29_L_7700();
  os_bcall(0x8030);
  set_hl((uint16_t)(hl() + bc()));
  p29_L_705E();
  ix = cpu_pop16();
  cpu_pop_de();
  if (flag_nz()) p29_L_4E44();
  if (flag_nz()) goto lab_p29_L_4D1D;
  goto lab_p29_L_4CD3;
  lab_p29_L_4CF7: ;
  p29_L_4894();
  set_de(0x0800);
  p29_L_777E();
  if (flag_nz()) goto lab_p29_L_4D35;
  ix = (uint16_t)(ix + 1);
  p29_L_4574();
  lab_p29_L_4D07: ;
  set_de(0x0810);
  p29_L_705E();
  if (flag_nz()) goto lab_p29_L_4D35;
  cpu_push_hl();
  cpu_ex_de_hl();
  p29_L_4E44();
  cpu_pop_hl();
  p29_L_4574();
  set_hl((uint16_t)(hl() + bc()));
  ix = (uint16_t)(ix + 1);
  goto lab_p29_L_4D07;
  lab_p29_L_4D1D: ;
  cpu_pop_hl();
  cpu_ex_de_hl();
  cpu_push_de();
  p29_L_7700();
  set_de(0x0810);
  os_bcall(0x8030);
  set_hl((uint16_t)(hl() + bc()));
  p29_L_705E();
  cpu_pop_de();
  ix = (uint16_t)(ix + 1);
  if (flag_nz()) goto lab_p29_L_4D35;
  cpu_ex_de_hl();
  goto lab_p29_L_4CD2;
  lab_p29_L_4D35: ;
  return;
  lab_p29_L_4D36: ;
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x4D38 (offset 0x0D38) */
void p29_L_4D38(void) {
  p29_L_70D1();
  if (flag_nz()) goto lab_p29_L_4D82;
  set_de(0x0700);
  p29_L_777E();
  if (flag_nz()) goto lab_p29_L_4D82;
  p29_L_4574();
  cpu_push_hl();
  p29_L_4894();
  set_de(0x0700);
  p29_L_777E();
  if (flag_nz()) goto lab_p29_L_4DCB;
  p29_L_4574();
  cpu_pop_de();
  cpu_ex_de_hl();
  ix = 0x000D;
  p29_L_4D5E();
  return;
  lab_p29_L_4D82: ;
  ix = 0x000C;
  p29_L_4894();
  set_de(0x0700);
  p29_L_777E();
  if (flag_nz()) goto lab_p29_L_4DCA;
  ix = (uint16_t)(ix + 1);
  p29_L_4574();
  lab_p29_L_4D97: ;
  set_de(0x0710);
  p29_L_705E();
  if (flag_nz()) goto lab_p29_L_4DC8;
  cpu_push_hl();
  cpu_ex_de_hl();
  p29_L_4DCD();
  cpu_pop_hl();
  p29_L_4574();
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  ix = (uint16_t)(ix + 1);
  goto lab_p29_L_4D97;
  lab_p29_L_4DC8: ;
  ix = (uint16_t)(ix - 1);
  lab_p29_L_4DCA: ;
  return;
  lab_p29_L_4DCB: ;
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x4D5E (offset 0x0D5E) */
void p29_L_4D5E(void) {
  lab_p29_L_4D5E: ;
  cpu_push_hl();
  lab_p29_L_4D5F: ;
  p29_L_4F6E();
  if (flag_z()) p29_L_4EBD();
  if (flag_z()) goto lab_p29_L_4DAF;
  cpu_push_de();
  cpu_push16(ix);
  set_de(0x0710);
  a = 0x7E;
  os_bcall(0x8030);
  set_hl((uint16_t)(hl() + bc()));
  p29_L_705E();
  ix = cpu_pop16();
  cpu_pop_de();
  if (flag_nz()) p29_L_4DCD();
  if (flag_nz()) goto lab_p29_L_4DAF;
  goto lab_p29_L_4D5F;
  lab_p29_L_4D80: ;
  goto lab_p29_L_4D5E;
  lab_p29_L_4DAF: ;
  cpu_pop_hl();
  cpu_ex_de_hl();
  cpu_push_de();
  a = 0x7E;
  set_de(0x0710);
  os_bcall(0x8030);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  p29_L_705E();
  cpu_pop_de();
  if (flag_nz()) goto lab_p29_L_4DCA;
  cpu_ex_de_hl();
  ix = (uint16_t)(ix + 1);
  goto lab_p29_L_4D80;
  lab_p29_L_4DCA: ;
  return;
}

/* flash page 29 cpu 0x4DCD (offset 0x0DCD) */
void p29_L_4DCD(void) {
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  cpu_push16(ix);
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 7)));
  cpu_ex_de_hl();
  cpu_push_hl();
  a = 0x7E;
  set_de(0x0740);
  os_bcall(0x8030);
  if (flag_nz()) goto lab_p29_L_4DE6;
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) | (1u << 7)));
  lab_p29_L_4DE6: ;
  cpu_pop_hl();
  a = 0x7E;
  set_de(0x0760);
  os_bcall(0x8030);
  if (flag_z()) goto lab_p29_L_4E01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x25)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p29_L_4DFC;
  set_de(0x0000);
  goto lab_p29_L_4E27;
  lab_p29_L_4DFC: ;
  set_de(0x0080);
  goto lab_p29_L_4E27;
  lab_p29_L_4E01: ;
  a = c;
  a = a | b;
  flag_logic(a);
  a = 0x00;
  if (flag_z()) goto lab_p29_L_4E0A;
  p29_L_4566();
  lab_p29_L_4E0A: ;
  cpu_push_af();
  b = 0x09;
  a = (uint8_t)(a - b);
  if (flag_c()) goto lab_p29_L_4E20;
  cpu_pop_af();
  b = 0x08;
  a = (uint8_t)(a - b);
  p29_L_4E9B();
  d = a;
  a = 0x08;
  p29_L_4E9B();
  e = a;
  goto lab_p29_L_4E27;
  lab_p29_L_4E20: ;
  d = 0x00;
  cpu_pop_af();
  p29_L_4E9B();
  e = a;
  lab_p29_L_4E27: ;
  set_hl(0x82A5);
  cpu_push16(ix);
  cpu_pop_bc();
  /* sla c */
  b = 0x00;
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), d);
  a = 0xFF;
  a = a | a;
  flag_logic(a);
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 7)));
  ix = cpu_pop16();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x4E44 (offset 0x0E44) */
void p29_L_4E44(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  cpu_push16(ix);
  cpu_ex_de_hl();
  a = 0x7E;
  set_de(0x0860);
  os_bcall(0x8030);
  if (flag_z()) goto lab_p29_L_4E5A;
  set_de(0x0080);
  goto lab_p29_L_4E80;
  lab_p29_L_4E5A: ;
  a = c;
  a = a | b;
  flag_logic(a);
  a = 0x00;
  if (flag_z()) goto lab_p29_L_4E63;
  p29_L_4566();
  lab_p29_L_4E63: ;
  cpu_push_af();
  b = 0x09;
  a = (uint8_t)(a - b);
  if (flag_c()) goto lab_p29_L_4E79;
  cpu_pop_af();
  b = 0x08;
  a = (uint8_t)(a - b);
  p29_L_4E9B();
  d = a;
  a = 0x08;
  p29_L_4E9B();
  e = a;
  goto lab_p29_L_4E80;
  lab_p29_L_4E79: ;
  d = 0x00;
  cpu_pop_af();
  p29_L_4E9B();
  e = a;
  lab_p29_L_4E80: ;
  set_hl(0x82A5);
  cpu_push16(ix);
  cpu_pop_bc();
  /* sla c */
  b = 0x00;
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), d);
  a = 0xFF;
  flag_set_z((a & (1u << 7)) == 0);
  ix = cpu_pop16();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x4E9B (offset 0x0E9B) */
void p29_L_4E9B(void) {
  cpu_push_bc();
  c = 0x11;
  a = (uint8_t)(a - c);
  if (flag_nc()) goto lab_p29_L_4EB9;
  a = a | a;
  flag_logic(a);
  /* adc a,c */
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p29_L_4EB9;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p29_L_4EBB;
  b = a;
  b = (uint8_t)(b - 1);
  a = 0x02;
  lab_p29_L_4EB0: ;
  /* sla a */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_4EB0;
  b = 0x01;
  a = (uint8_t)(a - b);
  goto lab_p29_L_4EBB;
  lab_p29_L_4EB9: ;
  a = 0x00;
  lab_p29_L_4EBB: ;
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x4EBD (offset 0x0EBD) */
void p29_L_4EBD(void) {
  cpu_push_af();
  cpu_push_hl();
  cpu_push_de();
  cpu_push16(ix);
  set_de(0x0710);
  p29_L_4ECE();
  ix = cpu_pop16();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x4ECE (offset 0x0ECE) */
void p29_L_4ECE(void) {
  p29_L_705E();
  p29_L_4574();
  set_de(0x838F);
  p29_L_424C();
  cpu_push_hl();
  set_hl(0x84AF);
  mem_write8(hl(), 0x01);
  cpu_pop_hl();
  os_bcall(0x8069);
  if (flag_z()) goto lab_p29_L_4EE8;
  ix = (uint16_t)(ix - 1);
  lab_p29_L_4EE8: ;
  p29_L_764E();
  cpu_push_hl();
  ix = cpu_pop16();
  cpu_push16(ix);
  cpu_pop_bc();
  /* sla c */
  p29_L_521D();
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  a = 0x7E;
  set_de(0x82A5);
  cpu_ex_de_hl();
  cpu_pop_bc();
  cpu_push_bc();
  /* sla c */
  b = 0x00;
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_ex_de_hl();
  set_bc(0x0002);
  p29_L_6B49();
  return;
}

/* flash page 29 cpu 0x4F10 (offset 0x0F10) */
void p29_L_4F10(void) {
  cpu_push_af();
  cpu_push_hl();
  cpu_push_de();
  cpu_push16(ix);
  set_de(0x0810);
  p29_L_4ECE();
  set_bc(mem_read16(0x838E));
  b = 0x00;
  a = c;
  cpu_push_af();
  a = a & 0xF0;
  flag_logic(a);
  c = a;
  cpu_pop_af();
  a = a ^ c;
  flag_logic(a);
  c = a;
  mem_write16(0x8483, bc());
  set_hl(0x838F);
  set_de(0x8484);
  while (bc() != 0) { cpu_ldi(); }
  os_bcall(0x8066);
  ix = cpu_pop16();
  if (flag_nz()) goto lab_p29_L_4F5E;
  ix = (uint16_t)(ix + 1);
  set_de(0x0700);
  p29_L_777E();
  p29_L_4574();
  lab_p29_L_4F47: ;
  p29_L_4EBD();
  ix = (uint16_t)(ix + 1);
  a = 0x7E;
  set_de(0x0710);
  os_bcall(0x8030);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  p29_L_705E();
  if (flag_z()) goto lab_p29_L_4F47;
  ix = (uint16_t)(ix - 1);
  lab_p29_L_4F5E: ;
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x4F62 (offset 0x0F62) */
void p29_L_4F62(void) {
  set_hl(0x82A5);
  a = 0xFF;
  b = 0xE8;
  lab_p29_L_4F69: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_4F69;
  return;
}

/* flash page 29 cpu 0x4F6E (offset 0x0F6E) */
void p29_L_4F6E(void) {
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  cpu_push16(ix);
  cpu_push_de();
  a = 0x7E;
  set_de(0x0710);
  os_bcall(0x8030);
  cpu_pop_de();
  cpu_push_hl();
  cpu_push_bc();
  cpu_ex_de_hl();
  a = 0x7E;
  set_de(0x0710);
  os_bcall(0x8030);
  cpu_pop_de();
  a = e;
  cpu_pop_de();
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p29_L_4FE9;
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_4FEF;
  p29_L_4FB9();
  return;
  lab_p29_L_4FE9: ;
  a = 0xFF;
  flag_set_z((a & (1u << 7)) == 0);
  goto lab_p29_L_4FF3;
  lab_p29_L_4FEF: ;
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  lab_p29_L_4FF3: ;
  ix = cpu_pop16();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x4F81 (offset 0x0F81) */
void p29_L_4F81(void) {
  a = mem_read8(hl());
  set_de(0x0710);
  os_bcall(0x8030);
  cpu_pop_de();
  a = e;
  cpu_pop_de();
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p29_L_4FE9;
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_4FEF;
  p29_L_4FB9();
  return;
  lab_p29_L_4FE9: ;
  a = 0xFF;
  flag_set_z((a & (1u << 7)) == 0);
  goto lab_p29_L_4FF3;
  lab_p29_L_4FEF: ;
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  lab_p29_L_4FF3: ;
  ix = cpu_pop16();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x4F95 (offset 0x0F95) */
void p29_L_4F95(void) {
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  cpu_push16(ix);
  cpu_push_de();
  a = 0x7E;
  set_de(0x0810);
  os_bcall(0x8030);
  cpu_pop_de();
  cpu_push_hl();
  cpu_push_bc();
  cpu_ex_de_hl();
  a = 0x7E;
  set_de(0x0810);
  os_bcall(0x8030);
  cpu_pop_de();
  a = e;
  cpu_pop_de();
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p29_L_4FE9;
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_4FEF;
  p29_L_4FB9();
  return;
  lab_p29_L_4FE9: ;
  a = 0xFF;
  flag_set_z((a & (1u << 7)) == 0);
  goto lab_p29_L_4FF3;
  lab_p29_L_4FEF: ;
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  lab_p29_L_4FF3: ;
  ix = cpu_pop16();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x4FB9 (offset 0x0FB9) */
void p29_L_4FB9(void) {
  b = c;
  lab_p29_L_4FBA: ;
  a = 0x7E;
  p29_L_4C73();
  if (flag_nz()) goto lab_p29_L_4FE9;
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_4FBA;
  p29_L_4565();
  a = a & 0xF0;
  flag_logic(a);
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p29_L_4FEF;
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p29_L_4FEF;
  set_hl((uint16_t)(hl() - 1));
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  p29_L_4574();
  cpu_pop_de();
  cpu_ex_de_hl();
  cpu_push_bc();
  cpu_push_de();
  p29_L_4575();
  cpu_pop_de();
  cpu_ex_de_hl();
  a = c;
  cpu_pop_bc();
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p29_L_4FE9;
  b = c;
  goto lab_p29_L_4FBA;
  lab_p29_L_4FE9: ;
  a = 0xFF;
  flag_set_z((a & (1u << 7)) == 0);
  goto lab_p29_L_4FF3;
  lab_p29_L_4FEF: ;
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  lab_p29_L_4FF3: ;
  ix = cpu_pop16();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x4FF9 (offset 0x0FF9) */
void p29_L_4FF9(void) {
  cpu_push_af();
  cpu_push_de();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_af();
  cpu_push_hl();
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_pop_af();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_pop_de();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_push_hl();
  cpu_pop_bc();
  cpu_ex_de_hl();
  cpu_pop_af();
  set_de(0x82A5);
  cpu_push_bc();
  os_bcall(0x8054);
  cpu_pop_bc();
  a = 0x7E;
  p29_L_4894();
  cpu_push_hl();
  cpu_push_hl();
  os_bcall(0x8060);
  cpu_pop_hl();
  cpu_ex_de_hl();
  set_hl(0x82A5);
  a = 0x7E;
  os_bcall(0x8087);
  set_de(0x0320);
  os_bcall(0x8027);
  if (flag_nz()) goto lab_p29_L_503E;
  os_bcall(0x802A);
  lab_p29_L_503E: ;
  cpu_pop_hl();
  p29_L_503F();
  return;
}

/* flash page 29 cpu 0x503F (offset 0x103F) */
void p29_L_503F(void) {
  goto lab_p29_L_503F;
  lab_p29_L_46C1: ;
  p29_L_5FDB();
  p00_L_2565();
  return;
  lab_p29_L_503F: ;
  /* scf */
  a = 0x7E;
  cpu_push_af();
  cpu_push_af();
  cpu_push_hl();
  cpu_push_hl();
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_pop_af();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_pop_de();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_push_hl();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_bc();
  cpu_push_hl();
  p29_L_521D();
  set_bc(0x00E8);
  a = 0x7E;
  set_de(0x82A5);
  os_bcall(0x8054);
  cpu_pop_de();
  cpu_pop_bc();
  a = d;
  a = a ^ 0x20;
  flag_logic(a);
  d = a;
  p29_L_430E();
  if (flag_nz()) goto lab_p29_L_46C1;
  cpu_pop_af();
  if (flag_c()) p29_L_4926();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x5083 (offset 0x1083) */
void p29_L_5083(void) {
  cpu_push_af();
  cpu_push_de();
  cpu_push_hl();
  cpu_push_bc();
  p29_L_503F();
  return;
}

/* flash page 29 cpu 0x508A (offset 0x108A) */
void p29_L_508A(void) {
  goto lab_p29_L_508A;
  lab_p29_L_46C1: ;
  p29_L_5FDB();
  p00_L_2565();
  return;
  lab_p29_L_5040: ;
  a = 0x7E;
  cpu_push_af();
  cpu_push_af();
  cpu_push_hl();
  cpu_push_hl();
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_pop_af();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_pop_de();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_push_hl();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_bc();
  cpu_push_hl();
  p29_L_521D();
  set_bc(0x00E8);
  a = 0x7E;
  set_de(0x82A5);
  os_bcall(0x8054);
  cpu_pop_de();
  cpu_pop_bc();
  a = d;
  a = a ^ 0x20;
  flag_logic(a);
  d = a;
  p29_L_430E();
  if (flag_nz()) goto lab_p29_L_46C1;
  cpu_pop_af();
  if (flag_c()) p29_L_4926();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_af();
  return;
  lab_p29_L_508A: ;
  cpu_push_af();
  cpu_push_de();
  cpu_push_hl();
  cpu_push_bc();
  p29_L_4894();
  set_de(0x0320);
  p29_L_777E();
  cpu_push_hl();
  set_de(0x0320);
  os_bcall(0x8027);
  if (flag_nz()) goto lab_p29_L_50A3;
  os_bcall(0x802A);
  lab_p29_L_50A3: ;
  cpu_pop_hl();
  /* scf */
  /* ccf */
  goto lab_p29_L_5040;
}

/* flash page 29 cpu 0x50A8 (offset 0x10A8) */
void p29_L_50A8(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  p29_L_4894();
  set_de(0x0320);
  p29_L_777E();
  p29_L_4574();
  a = 0x7E;
  p29_L_50C5();
  if (flag_z()) p29_L_508A();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x50C5 (offset 0x10C5) */
void p29_L_50C5(void) {
  cpu_push16(ix);
  cpu_push_hl();
  cpu_push_de();
  cpu_push_af();
  cpu_push_hl();
  set_de(0x0320);
  os_bcall(0x8027);
  if (flag_nz()) goto lab_p29_L_5119;
  p29_L_4574();
  cpu_ex_de_hl();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_pop_af();
  b = a;
  os_bcall(0x8051);
  cpu_push_af();
  a = a & 0xF0;
  flag_logic(a);
  c = a;
  cpu_pop_af();
  a = a ^ c;
  flag_logic(a);
  cpu_push_af();
  cpu_ex_de_hl();
  p29_L_4566();
  c = a;
  cpu_pop_af();
  a = (uint8_t)(a - c);
  if (flag_z()) goto lab_p29_L_50F3;
  if (flag_nc()) goto lab_p29_L_511B;
  if (flag_c()) goto lab_p29_L_5113;
  lab_p29_L_50F3: ;
  a = b;
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  b = c;
  cpu_ex_de_hl();
  lab_p29_L_50F8: ;
  cpu_push_af();
  os_bcall(0x8051);
  cpu_push_af();
  cpu_ex_de_hl();
  p29_L_4566();
  c = a;
  cpu_pop_af();
  a = (uint8_t)(a - c);
  if (flag_z()) goto lab_p29_L_510A;
  if (flag_nc()) goto lab_p29_L_511A;
  if (flag_c()) goto lab_p29_L_5112;
  lab_p29_L_510A: ;
  cpu_pop_af();
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_50F8;
  goto lab_p29_L_5113;
  lab_p29_L_5112: ;
  cpu_pop_af();
  lab_p29_L_5113: ;
  a = 0xFF;
  flag_set_z((a & (1u << 7)) == 0);
  goto lab_p29_L_511F;
  lab_p29_L_5119: ;
  cpu_pop_af();
  lab_p29_L_511A: ;
  cpu_pop_af();
  lab_p29_L_511B: ;
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  lab_p29_L_511F: ;
  cpu_pop_de();
  cpu_pop_hl();
  ix = cpu_pop16();
  return;
}

/* flash page 29 cpu 0x5124 (offset 0x1124) */
void p29_L_5124(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_af();
  p29_L_47B5();
  p29_L_762A();
  p29_L_484E();
  ix = (uint16_t)(ix + 1);
  cpu_push16(ix);
  p29_L_4894();
  set_de(0x0700);
  p29_L_777E();
  p29_L_4574();
  lab_p29_L_5141: ;
  set_de(0x0710);
  p29_L_705E();
  if (flag_nz()) { p29_L_5156(); return; }
  cpu_ex_de_hl();
  p29_L_4DCD();
  cpu_ex_de_hl();
  ix = (uint16_t)(ix + 1);
  p29_L_4574();
  set_hl((uint16_t)(hl() + bc()));
  goto lab_p29_L_5141;
}

/* flash page 29 cpu 0x5156 (offset 0x1156) */
void p29_L_5156(void) {
  set_hl(0x82A5);
  cpu_push16(ix);
  cpu_pop_bc();
  /* sla c */
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_de();
  cpu_push_hl();
  /* sla e */
  p29_L_521D();
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  a = c;
  a = (uint8_t)(a - e);
  if (flag_nc()) goto lab_p29_L_516F;
  a = e;
  e = c;
  a = (uint8_t)(a - e);
  lab_p29_L_516F: ;
  c = a;
  set_hl(0x00C8);
  cpu_sbc_hl_de();
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_de();
  a = 0x7E;
  os_bcall(0x8054);
  cpu_pop_af();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x5185 (offset 0x1185) */
void p29_L_5185(void) {
  cpu_push_bc();
  cpu_push_hl();
  p29_L_521D();
  cpu_pop_de();
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_ex_de_hl();
  set_hl(0x82A5);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(0x9C20);
  p29_L_47B6();
  cpu_pop_bc();
  mem_write8(hl(), b);
  return;
}

/* flash page 29 cpu 0x519D (offset 0x119D) */
void p29_L_519D(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_hl();
  p29_L_51DB();
  p29_L_7BCC();
  c = a;
  p29_L_4566();
  cpu_push_af();
  a = a | c;
  flag_logic(a);
  b = a;
  cpu_pop_af();
  a = a & c;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_51BB;
  p29_L_5185();
  a = 0x05;
  p29_L_40CC();
  goto lab_p29_L_51BF;
  lab_p29_L_51BB: ;
  cpu_ex_de_hl();
  p29_L_456D();
  lab_p29_L_51BF: ;
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x51C3 (offset 0x11C3) */
void p29_L_51C3(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_hl();
  p29_L_51DB();
  p29_L_7BCC();
  a = a ^ 0xFF;
  c = a;
  p29_L_4566();
  a = a & c;
  flag_logic(a);
  b = a;
  cpu_ex_de_hl();
  p29_L_456D();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x51DB (offset 0x11DB) */
void p29_L_51DB(void) {
  cpu_push_de();
  cpu_push_af();
  b = a;
  os_bcall(0x80A8);
  if (flag_nz()) goto lab_p29_L_51ED;
  p29_L_75EC();
  a = (uint8_t)(a - b);
  a = (uint8_t)(a + 1);
  c = a;
  b = 0x00;
  goto lab_p29_L_5202;
  lab_p29_L_51ED: ;
  cpu_push_hl();
  set_hl(0x84AF);
  mem_write8(hl(), 0x00);
  cpu_pop_hl();
  os_bcall(0x8069);
  ix = (uint16_t)(ix + 1);
  cpu_push16(ix);
  cpu_pop_hl();
  p29_L_7643();
  set_hl((uint16_t)(hl() + bc()));
  cpu_push_hl();
  cpu_pop_bc();
  lab_p29_L_5202: ;
  cpu_push_bc();
  p29_L_5217();
  /* sra c */
  /* sra c */
  /* sra c */
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_pop_bc();
  a = c;
  a = a & 0x07;
  flag_logic(a);
  c = a;
  cpu_pop_af();
  cpu_pop_de();
  return;
}

/* flash page 29 cpu 0x5217 (offset 0x1217) */
void p29_L_5217(void) {
  cpu_push_bc();
  set_bc(0x1FE0);
  goto lab_p29_L_5221;
  lab_p29_L_5221: ;
  cpu_push16(ix);
  os_bcall(0x8057);
  set_hl((uint16_t)(hl() + bc()));
  ix = cpu_pop16();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x521D (offset 0x121D) */
void p29_L_521D(void) {
  cpu_push_bc();
  set_bc(0x1F18);
  cpu_push16(ix);
  os_bcall(0x8057);
  set_hl((uint16_t)(hl() + bc()));
  ix = cpu_pop16();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x522B (offset 0x122B) */
void p29_L_522B(void) {
  goto lab_p29_L_522B;
  lab_p29_L_5221: ;
  cpu_push16(ix);
  os_bcall(0x8057);
  set_hl((uint16_t)(hl() + bc()));
  ix = cpu_pop16();
  cpu_pop_bc();
  return;
  lab_p29_L_522B: ;
  cpu_push_bc();
  set_bc(0x1DEA);
  goto lab_p29_L_5221;
}

/* flash page 29 cpu 0x5231 (offset 0x1231) */
void p29_L_5231(void) {
  p00_L_24A9();
  if (flag_nz()) { p29_L_521D(); return; }
  p29_L_5236();
  return;
}

/* flash page 29 cpu 0x5236 (offset 0x1236) */
void p29_L_5236(void) {
  goto lab_p29_L_5236;
  lab_p29_L_5221: ;
  cpu_push16(ix);
  os_bcall(0x8057);
  set_hl((uint16_t)(hl() + bc()));
  ix = cpu_pop16();
  cpu_pop_bc();
  return;
  lab_p29_L_5236: ;
  cpu_push_bc();
  set_bc(0x1E50);
  goto lab_p29_L_5221;
}

/* flash page 29 cpu 0x523C (offset 0x123C) */
void p29_L_523C(void) {
  goto lab_p29_L_523C;
  lab_p29_L_5221: ;
  cpu_push16(ix);
  os_bcall(0x8057);
  set_hl((uint16_t)(hl() + bc()));
  ix = cpu_pop16();
  cpu_pop_bc();
  return;
  lab_p29_L_523C: ;
  cpu_push_bc();
  set_bc(0x1FE0);
  goto lab_p29_L_5221;
}

/* flash page 29 cpu 0x5242 (offset 0x1242) */
void p29_L_5242(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push16(ix);
  a = mem_read8(0x8478);
  cpu_push_af();
  a = 0x08;
  lab_p29_L_524C: ;
  cpu_push_af();
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p29_L_527B;
  cpu_pop_af();
  a = (uint8_t)(a + 0x04);
  p29_L_75E1();
  if (flag_c()) goto lab_p29_L_524C;
  a = 0x08;
  lab_p29_L_5261: ;
  cpu_push_af();
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p29_L_5278;
  cpu_pop_af();
  a = (uint8_t)(a + 0x04);
  p29_L_75E1();
  if (flag_c()) goto lab_p29_L_5261;
  a = 0x08;
  goto lab_p29_L_5279;
  lab_p29_L_5278: ;
  cpu_pop_af();
  lab_p29_L_5279: ;
  goto lab_p29_L_527C;
  lab_p29_L_527B: ;
  cpu_pop_af();
  lab_p29_L_527C: ;
  b = a;
  cpu_pop_af();
  mem_write8(0x8478, a);
  a = b;
  ix = cpu_pop16();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x5287 (offset 0x1287) */
void p29_L_5287(void) {
  cpu_push_af();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  b = 0xFE;
  set_de(0x4000);
  os_bcall(0x8021);
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x5298 (offset 0x1298) */
void p29_L_5298(void) {
  os_bcall(0x8066);
  if (flag_nz()) goto lab_p29_L_52D8;
  a = 0x7E;
  p29_L_529F();
  return;
  lab_p29_L_52D8: ;
  return;
}

/* flash page 29 cpu 0x529F (offset 0x129F) */
void p29_L_529F(void) {
  mem_write8(0x82A3, a);
  cpu_push_hl();
  cpu_push_hl();
  a = mem_read8(0x82A3);
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(0x82A3);
  os_bcall(0x805A);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_pop_de();
  cpu_sbc_hl_de();
  cpu_push_hl();
  cpu_pop_bc();
  p29_L_4894();
  cpu_ex_de_hl();
  cpu_pop_hl();
  lab_p29_L_52C2: ;
  cpu_push_bc();
  a = mem_read8(0x82A3);
  os_bcall(0x8051);
  b = a;
  cpu_push_hl();
  p29_L_456D();
  cpu_pop_hl();
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_52D8;
  set_hl((uint16_t)(hl() + 1));
  goto lab_p29_L_52C2;
  lab_p29_L_52D8: ;
  return;
}

/* flash page 29 cpu 0x52D9 (offset 0x12D9) */
void p29_L_52D9(void) {
  set_de(0x8050);
  set_hl(0x4000);
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_52ED;
  cpu_pop_af();
  p29_L_50C5();
  /* scf */
  /* ccf */
  return;
  lab_p29_L_52ED: ;
  cpu_pop_af();
  /* scf */
  return;
}

/* flash page 29 cpu 0x52F0 (offset 0x12F0) */
void p29_L_52F0(void) {
  set_de(0x8050);
  cpu_push_de();
  p29_L_52F7();
  return;
}

/* flash page 29 cpu 0x52F7 (offset 0x12F7) */
void p29_L_52F7(void) {
  set_hl(0x4000);
  cpu_pop_de();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_5338;
  cpu_pop_af();
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
  p29_L_50C5();
  p29_L_6006();
  p29_L_5FDB();
  mem_write8(0x83EB, a);
  cpu_pop_af();
  if (flag_po()) goto lab_p29_L_532F;
  /* ei */
  lab_p29_L_532F: ;
  a = mem_read8(0x83EB);
  p29_L_6011();
  /* scf */
  /* ccf */
  return;
  lab_p29_L_5338: ;
  cpu_pop_af();
  /* scf */
  return;
}

/* flash page 29 cpu 0x533B (offset 0x133B) */
void p29_L_533B(void) {
  goto lab_p29_L_533B;
  lab_p29_L_5338: ;
  cpu_pop_af();
  /* scf */
  return;
  lab_p29_L_533B: ;
  cpu_push_af();
  p29_L_6021();
  if (flag_c()) goto lab_p29_L_5338;
  set_hl(0x4000);
  set_de(0x0320);
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_5338;
  cpu_pop_af();
  cpu_push_af();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  p29_L_50C5();
  if (flag_nz()) goto lab_p29_L_5362;
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_hl();
  p29_L_4FF9();
  lab_p29_L_5362: ;
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x5365 (offset 0x1365) */
void p29_L_5365(void) {
  cpu_push16(ix);
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  p29_L_5231();
  goto lab_p29_L_537C;
  lab_p29_L_537C: ;
  cpu_push16(ix);
  cpu_pop_bc();
  /* sla c */
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_push_hl();
  p29_L_4566();
  flag_cmp(a, 0x80);
  if (flag_z()) goto lab_p29_L_53AC;
  cpu_push_af();
  p29_L_4565();
  flag_cmp(a, 0x00);
  cpu_pop_bc();
  if (flag_z()) goto lab_p29_L_5399;
  /* srl a */
  goto lab_p29_L_539B;
  lab_p29_L_5399: ;
  /* srl b */
  lab_p29_L_539B: ;
  cpu_pop_de();
  c = a;
  cpu_push_bc();
  p29_L_456D();
  cpu_pop_bc();
  b = c;
  p29_L_456D();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  ix = cpu_pop16();
  return;
  lab_p29_L_53AC: ;
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  ix = cpu_pop16();
  return;
}

/* flash page 29 cpu 0x536F (offset 0x136F) */
void p29_L_536F(void) {
  cpu_push16(ix);
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  p29_L_521D();
  set_bc(0x000D);
  /* add ix,bc */
  cpu_push16(ix);
  cpu_pop_bc();
  /* sla c */
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_push_hl();
  p29_L_4566();
  flag_cmp(a, 0x80);
  if (flag_z()) goto lab_p29_L_53AC;
  cpu_push_af();
  p29_L_4565();
  flag_cmp(a, 0x00);
  cpu_pop_bc();
  if (flag_z()) goto lab_p29_L_5399;
  /* srl a */
  goto lab_p29_L_539B;
  lab_p29_L_5399: ;
  /* srl b */
  lab_p29_L_539B: ;
  cpu_pop_de();
  c = a;
  cpu_push_bc();
  p29_L_456D();
  cpu_pop_bc();
  b = c;
  p29_L_456D();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  ix = cpu_pop16();
  return;
  lab_p29_L_53AC: ;
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  ix = cpu_pop16();
  return;
}

/* flash page 29 cpu 0x53B3 (offset 0x13B3) */
void p29_L_53B3(void) {
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
  p29_L_53E5();
  p29_L_53D1();
  return;
}

/* flash page 29 cpu 0x53D1 (offset 0x13D1) */
void p29_L_53D1(void) {
  p29_L_6006();
  p29_L_5FDB();
  mem_write8(0x83EB, a);
  cpu_pop_af();
  if (flag_po()) goto lab_p29_L_53DF;
  /* ei */
  lab_p29_L_53DF: ;
  a = mem_read8(0x83EB);
  p29_L_6011();
  return;
}

/* flash page 29 cpu 0x53E5 (offset 0x13E5) */
void p29_L_53E5(void) {
  cpu_push_de();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push16(ix);
  b = a;
  os_bcall(0x80A8);
  if (flag_nz()) goto lab_p29_L_53FA;
  p29_L_75EC();
  a = (uint8_t)(a - b);
  a = (uint8_t)(a + 1);
  c = a;
  b = 0x00;
  goto lab_p29_L_541E;
  lab_p29_L_53FA: ;
  set_hl(0x84AF);
  mem_write8(hl(), 0x00);
  a = mem_read8(0x82A3);
  cpu_push_af();
  os_bcall(0x8069);
  cpu_pop_af();
  mem_write8(0x82A3, a);
  goto lab_p29_L_5411;
  lab_p29_L_5411: ;
  ix = (uint16_t)(ix + 1);
  cpu_push16(ix);
  cpu_pop_hl();
  p29_L_7643();
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_push_hl();
  cpu_pop_bc();
  lab_p29_L_541E: ;
  cpu_push_bc();
  p29_L_5217();
  /* sra c */
  /* sra c */
  /* sra c */
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_pop_bc();
  a = c;
  a = a & 0x07;
  flag_logic(a);
  p29_L_7BCC();
  c = a;
  p29_L_4566();
  a = a & c;
  flag_logic(a);
  ix = cpu_pop16();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_de();
  return;
}

/* flash page 29 cpu 0x540C (offset 0x140C) */
void p29_L_540C(void) {
  cpu_push_de();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push16(ix);
  ix = (uint16_t)(ix + 1);
  cpu_push16(ix);
  cpu_pop_hl();
  p29_L_7643();
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_push_hl();
  cpu_pop_bc();
  cpu_push_bc();
  p29_L_5217();
  /* sra c */
  /* sra c */
  /* sra c */
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_pop_bc();
  a = c;
  a = a & 0x07;
  flag_logic(a);
  p29_L_7BCC();
  c = a;
  p29_L_4566();
  a = a & c;
  flag_logic(a);
  ix = cpu_pop16();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_de();
  return;
}

/* flash page 29 cpu 0x543D (offset 0x143D) */
void p29_L_543D(void) {
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
  b = a;
  set_de(0x8060);
  set_hl(0x4000);
  a = a | a;
  flag_logic(a);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_549D;
  p29_L_75EC();
  c = b;
  a = (uint8_t)(a - c);
  set_bc(0x0000);
  c = a;
  /* sla c */
  p29_L_5231();
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  a = 0x7E;
  set_de(0x8478);
  set_bc(0x0002);
  os_bcall(0x8054);
  a = mem_read8(0x8478);
  set_bc(0x0000);
  lab_p29_L_547D: ;
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p29_L_5486;
  /* srl a */
  c = (uint8_t)(c + 1);
  goto lab_p29_L_547D;
  lab_p29_L_5486: ;
  a = mem_read8(0x8479);
  lab_p29_L_5489: ;
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p29_L_5492;
  /* srl a */
  c = (uint8_t)(c + 1);
  goto lab_p29_L_5489;
  lab_p29_L_5492: ;
  a = c;
  mem_write8(0x8478, a);
  a = 0x00;
  mem_write8(0x8479, a);
  flag_set_z((a & (1u << 7)) == 0);
  lab_p29_L_549D: ;
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x54A0 (offset 0x14A0) */
void p29_L_54A0(void) {
  b = a;
  set_de(0x8050);
  set_hl(0x4000);
  a = a | a;
  flag_logic(a);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_54BE;
  a = b;
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  cpu_pop_af();
  set_de(0x8478);
  os_bcall(0x8054);
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  lab_p29_L_54BE: ;
  return;
}

/* flash page 29 cpu 0x54DA (offset 0x14DA) */
void p29_L_54DA(void) {
  mem_write8(0x83EB, a);
  cpu_ld_a_i();
  /* di */
  cpu_push_af();
  a = mem_read8(0x83EB);
  cpu_push_hl();
  cpu_push_de();
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
  set_de(0x0510);
  cpu_push_de();
  goto lab_p29_L_54FD;
  lab_p29_L_54FD: ;
  p29_L_70D1();
  if (flag_nz()) goto lab_p29_L_551F;
  set_de(0x0500);
  p29_L_777E();
  if (flag_nz()) goto lab_p29_L_551F;
  p29_L_4574();
  a = 0x7E;
  cpu_pop_de();
  os_bcall(0x8030);
  if (flag_nz()) goto lab_p29_L_5520;
  set_de(0x82A5);
  b = c;
  cpu_push_bc();
  a = 0x7E;
  p29_L_761F();
  lab_p29_L_551F: ;
  cpu_pop_bc();
  lab_p29_L_5520: ;
  cpu_pop_de();
  cpu_pop_hl();
  p29_L_53D1();
  return;
}

/* flash page 29 cpu 0x5525 (offset 0x1525) */
void p29_L_5525(void) {
  cpu_push_af();
  set_hl(0x4000);
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x8051);
  p29_L_75FD();
  if (flag_nz()) goto lab_p29_L_55C8;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  p29_L_761F();
  set_bc(0x4000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_push_af();
  set_hl(0x4000);
  set_de(0x8080);
  a = a | a;
  flag_logic(a);
  os_bcall(0x8075);
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x805A);
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8051);
  a = (uint8_t)(a - 1);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_5574;
  c = a;
  cpu_pop_af();
  a = (uint8_t)(a - c);
  cpu_push_af();
  set_hl(mem_read16(0x83A1));
  p29_L_57C5();
  b = c;
  lab_p29_L_5564: ;
  cpu_push_bc();
  set_bc(0x4000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_5564;
  p29_L_57C5();
  mem_write16(0x83A1, hl());
  lab_p29_L_5574: ;
  set_hl(mem_read16(0x83A1));
  p29_L_57C5();
  cpu_push_hl();
  cpu_pop_bc();
  set_hl(0x4000);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_pop_af();
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_push_af();
  lab_p29_L_5588: ;
  os_bcall(0x8051);
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p29_L_55C8;
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x8051);
  a = a & 0xF0;
  flag_logic(a);
  flag_cmp(a, 0x20);
  if (flag_z()) goto lab_p29_L_55A8;
  cpu_pop_af();
  cpu_pop_hl();
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  goto lab_p29_L_5588;
  lab_p29_L_55A8: ;
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x805A);
  set_hl((uint16_t)(hl() - 1));
  set_bc((uint16_t)(bc() + 1));
  set_de(0x82A5);
  lab_p29_L_55B2: ;
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8051);
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_55B2;
  cpu_pop_af();
  cpu_pop_hl();
  b = a;
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  a = b;
  return;
  lab_p29_L_55C8: ;
  cpu_pop_af();
  a = 0xFF;
  flag_set_z((a & (1u << 7)) == 0);
  return;
}

/* flash page 29 cpu 0x55CE (offset 0x15CE) */
void p29_L_55CE(void) {
  set_hl((uint16_t)(hl() + 1));
  cpu_push_af();
  os_bcall(0x805A);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  lab_p29_L_55D6: ;
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8051);
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p29_L_5609;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8051);
  a = a & 0xF0;
  flag_logic(a);
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p29_L_55F5;
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x805A);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  goto lab_p29_L_55D6;
  lab_p29_L_55F5: ;
  cpu_pop_af();
  os_bcall(0x805A);
  set_hl((uint16_t)(hl() - 1));
  set_bc((uint16_t)(bc() + 1));
  set_de(0x82A5);
  os_bcall(0x8054);
  b = c;
  c = 0x00;
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  return;
  lab_p29_L_5609: ;
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x560B (offset 0x160B) */
void p29_L_560B(void) {
  cpu_push_de();
  cpu_push_hl();
  cpu_push_bc();
  os_bcall(0x807E);
  if (flag_nz()) goto lab_p29_L_5640;
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
  os_bcall(0x8057);
  a = 0x7E;
  set_de(0x0410);
  os_bcall(0x8027);
  if (flag_nz()) goto lab_p29_L_5640;
  p29_L_4574();
  a = 0x7E;
  set_de(0x849E);
  os_bcall(0x8054);
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  lab_p29_L_5640: ;
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_de();
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x5646 (offset 0x1646) */
void p29_L_5646(void) {
  p00_L_23DE();
  if (flag_nc()) goto lab_p29_L_5650;
  p00_L_23E3();
  goto lab_p29_L_565A;
  lab_p29_L_5650: ;
  p29_L_560B();
  if (flag_nz()) goto lab_p29_L_5695;
  p29_L_56A0();
  if (flag_nz()) goto lab_p29_L_5695;
  lab_p29_L_565A: ;
  a = 0x01;
  p00_L_38EB();
  cpu_push_de();
  cpu_push_hl();
  p29_L_560B();
  if (flag_nz()) goto lab_p29_L_5689;
  p00_L_128A();
  set_de(0x847A);
  set_hl(0x8499);
  c = 0x07;
  b = 0x00;
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_de();
  p00_L_3AE9();
  cpu_ex_de_hl();
  set_hl(0x8478);
  a = mem_read8(hl());
  p00_L_1183();
  cpu_pop_hl();
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  return;
  lab_p29_L_5689: ;
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  os_bcall(0x807E);
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  return;
  lab_p29_L_5695: ;
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  os_bcall(0x807E);
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_ex_de_hl();
  return;
}

/* flash page 29 cpu 0x56A0 (offset 0x16A0) */
void p29_L_56A0(void) {
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  p00_L_23DE();
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  cpu_ex_de_hl();
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_56D6;
  set_hl(0x0001);
  lab_p29_L_56B3: ;
  cpu_push_de();
  cpu_push_hl();
  cpu_push_bc();
  p00_L_3B07();
  set_de(0x8499);
  set_hl(0x8485);
  b = 0x07;
  lab_p29_L_56C1: ;
  a = mem_read8(de());
  cpu_cp_hl();
  if (flag_nz()) goto lab_p29_L_56CB;
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_56C1;
  goto lab_p29_L_56DA;
  lab_p29_L_56CB: ;
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_de();
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_56D6;
  goto lab_p29_L_56B3;
  lab_p29_L_56D6: ;
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  return;
  lab_p29_L_56DA: ;
  a = 0xFF;
  flag_set_z((a & (1u << 7)) == 0);
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x56E5 (offset 0x16E5) */
void p29_L_56E5(void) {
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_af();
  set_hl(0x4000);
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x8051);
  p29_L_75FD();
  if (flag_nz()) goto lab_p29_L_5737;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  p29_L_761F();
  set_hl(mem_read16(0x839F));
  cpu_push_hl();
  set_hl(mem_read16(0x83A1));
  cpu_push_hl();
  cpu_push_af();
  p29_L_5525();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_pop_af();
  cpu_pop_bc();
  mem_write16(0x83A1, bc());
  cpu_pop_bc();
  mem_write16(0x839F, bc());
  cpu_push_af();
  cpu_push_hl();
  set_hl(0x4000);
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  set_bc(0x4000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  p29_L_573C();
  cpu_pop_bc();
  set_bc((uint16_t)(bc() + 1));
  set_bc((uint16_t)(bc() + 1));
  p29_L_573C();
  lab_p29_L_5737: ;
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x573C (offset 0x173C) */
void p29_L_573C(void) {
  set_hl(mem_read16(0x83A1));
  p29_L_57C5();
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  p29_L_57C5();
  mem_write16(0x83A1, hl());
  if (flag_nc()) return;
  set_hl(mem_read16(0x839F));
  h = (uint8_t)(h + 1);
  if (flag_nz()) goto lab_p29_L_5753;
  l = (uint8_t)(l + 1);
  lab_p29_L_5753: ;
  mem_write16(0x839F, hl());
  return;
}

/* flash page 29 cpu 0x5757 (offset 0x1757) */
void p29_L_5757(void) {
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  p29_L_75FD();
  if (flag_nz()) goto lab_p29_L_5768;
  lab_p29_L_5762: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(hl());
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_5762;
  lab_p29_L_5768: ;
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x576D (offset 0x176D) */
void p29_L_576D(void) {
  cpu_push_af();
  a = 0x01;
  p29_L_47B6();
  b = a;
  p29_L_75EC();
  a = (uint8_t)(a - b);
  b = 0x00;
  c = a;
  set_hl(0x82A5);
  /* sla c */
  set_hl((uint16_t)(hl() + bc()));
  a = 0xFF;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  a = 0x01;
  p29_L_40CC();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x578D (offset 0x178D) */
void p29_L_578D(void) {
  cpu_push_af();
  a = mem_read8(0x83A4);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_57C3;
  set_hl(mem_read16(0x83A1));
  p29_L_57C5();
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_57B2;
  set_hl(mem_read16(0x839F));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_57C3;
  p29_L_57C5();
  set_hl((uint16_t)(hl() - 1));
  p29_L_57C5();
  mem_write16(0x839F, hl());
  set_hl(0x0000);
  lab_p29_L_57B2: ;
  set_hl((uint16_t)(hl() - 1));
  p29_L_57C5();
  mem_write16(0x83A1, hl());
  set_hl(mem_read16(0x839F));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_57C3;
  set_hl(mem_read16(0x83A1));
  lab_p29_L_57C3: ;
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x57C5 (offset 0x17C5) */
void p29_L_57C5(void) {
  cpu_push_af();
  a = l;
  l = h;
  h = a;
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x57CB (offset 0x17CB) */
void p29_L_57CB(void) {
  cpu_push_bc();
  cpu_push_de();
  p29_L_5980();
  if (flag_z()) goto lab_p29_L_5973;
  os_bcall(0x8057);
  cpu_push_hl();
  cpu_push_hl();
  cpu_pop_bc();
  os_bcall(0x802D);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x8432, hl());
  cpu_push_hl();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  p29_L_4565();
  set_hl((uint16_t)(hl() - 1));
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p29_L_5972;
  flag_cmp(a, 0x00);
  if (flag_z()) { p00_L_2565(); return; }
  p29_L_42D3();
  p29_L_5980();
  if (flag_z()) goto lab_p29_L_5972;
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  cpu_ex_de_hl();
  p29_L_597A();
  mem_write8(0x8483, a);
  p29_L_40A6();
  a = a | a;
  flag_logic(a);
  cpu_ex_de_hl();
  /* adc hl,bc */
  cpu_push_hl();
  set_de(0x0A20);
  os_bcall(0x8027);
  if (flag_nz()) goto lab_p29_L_5832;
  a = h;
  a = a & 0x0F;
  flag_logic(a);
  a = a | 0x40;
  flag_logic(a);
  h = a;
  p29_L_597A();
  os_bcall(0x805A);
  lab_p29_L_5823: ;
  b = 0x00;
  cpu_push_bc();
  p29_L_597A();
  cpu_ex_de_hl();
  os_bcall(0x8021);
  cpu_ex_de_hl();
  cpu_pop_bc();
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p29_L_5823;
  lab_p29_L_5832: ;
  p29_L_5980();
  if (flag_z()) goto lab_p29_L_5972;
  set_hl(0x4000);
  a = 0x7A;
  set_de(0x8070);
  os_bcall(0x8075);
  set_hl((uint16_t)(hl() + 1));
  a = 0x7A;
  os_bcall(0x805A);
  set_bc(0x4000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  set_de(0x8000);
  set_hl(0x4000);
  a = 0x7A;
  cpu_push_bc();
  os_bcall(0x8054);
  cpu_pop_bc();
  cpu_pop_de();
  set_hl(0x8000);
  p29_L_597A();
  cpu_push_bc();
  os_bcall(0x8087);
  cpu_pop_bc();
  cpu_push_de();
  set_hl(mem_read16(0x8432));
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  mem_write16(0x8432, hl());
  p29_L_75F5();
  lab_p29_L_5877: ;
  p00_L_1295();
  p29_L_638B();
  p00_L_1179();
  if (flag_c()) goto lab_p29_L_58AD;
  p29_L_61A4();
  cpu_pop_de();
  set_bc(0x4000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  set_hl(mem_read16(0x8432));
  /* adc hl,bc */
  mem_write16(0x8432, hl());
  set_hl(0x4000);
  cpu_push_af();
  p29_L_597A();
  mem_write8(0x8483, a);
  cpu_pop_af();
  p29_L_40A9();
  a = a | a;
  flag_logic(a);
  cpu_ex_de_hl();
  /* adc hl,bc */
  cpu_ex_de_hl();
  cpu_push_de();
  goto lab_p29_L_5877;
  lab_p29_L_58AD: ;
  cpu_pop_de();
  os_bcall(0x808D);
  set_hl(0x4000);
  cpu_push_hl();
  set_hl(0x0000);
  mem_write16(0x839F, hl());
  set_hl(mem_read16(0x8432));
  p29_L_57C5();
  mem_write16(0x83A1, hl());
  cpu_pop_hl();
  a = 0x01;
  mem_write8(0x83A4, a);
  lab_p29_L_58CA: ;
  a = 0x01;
  mem_write8(0x83A3, a);
  p29_L_597A();
  set_de(0x8000);
  set_bc(0x0001);
  cpu_push_hl();
  p29_L_6B49();
  p29_L_5E0A();
  p29_L_578D();
  a = h;
  a = a | l;
  flag_logic(a);
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  if (flag_nz()) goto lab_p29_L_58CA;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  os_bcall(0x8018);
  set_hl(0x0D02);
  mem_write16(0x8478, hl());
  set_hl(0x8478);
  cpu_pop_de();
  cpu_push_de();
  set_de((uint16_t)(de() - 1));
  set_de((uint16_t)(de() - 1));
  set_bc(0x0002);
  p29_L_597A();
  os_bcall(0x8087);
  p29_L_5980();
  if (flag_z()) goto lab_p29_L_5972;
  set_de(0x0A20);
  os_bcall(0x8027);
  p29_L_4574();
  set_bc((uint16_t)(bc() + 1));
  set_hl((uint16_t)(hl() - 1));
  set_de(0x8000);
  os_bcall(0x8054);
  set_de(0x8182);
  b = 0x00;
  a = mem_read8(0x8291);
  c = a;
  set_hl(0x8291);
  set_bc((uint16_t)(bc() + 1));
  p29_L_5928();
  return;
  lab_p29_L_5972: ;
  cpu_pop_hl();
  lab_p29_L_5973: ;
  cpu_pop_de();
  cpu_pop_bc();
  a = 0xFF;
  flag_set_z((a & (1u << 7)) == 0);
  return;
}

/* flash page 29 cpu 0x5928 (offset 0x1928) */
void p29_L_5928(void) {
  while (bc() != 0) { cpu_ldi(); }
  os_bcall(0x80C0);
  cpu_pop_de();
  set_hl(0x8478);
  b = 0x00;
  a = mem_read8(hl());
  c = a;
  set_bc((uint16_t)(bc() + 1));
  p29_L_597A();
  cpu_push_bc();
  os_bcall(0x8087);
  set_hl(mem_read16(0x8432));
  cpu_pop_bc();
  set_bc((uint16_t)(bc() + 1));
  set_bc((uint16_t)(bc() + 1));
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  mem_write16(0x839F, hl());
  p29_L_597A();
  mem_write8(0x8483, a);
  p29_L_7700();
  cpu_push_de();
  os_bcall(0x8057);
  set_bc(0x1D00);
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_de();
  set_bc(0x0300);
  p29_L_40A6();
  set_hl(mem_read16(0x839F));
  set_bc(0x0300);
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x839F, hl());
  set_hl(0x4000);
  a = 0;
  flag_logic(a);
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x597A (offset 0x197A) */
void p29_L_597A(void) {
  p29_L_5242();
  a = (uint8_t)(a + 1);
  a = (uint8_t)(a + 1);
  return;
}

/* flash page 29 cpu 0x5980 (offset 0x1980) */
void p29_L_5980(void) {
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) | (1u << 2)));
  a = hw_in(PORT_STATUS);
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 2)));
  return;
}

/* flash page 29 cpu 0x598E (offset 0x198E) */
void p29_L_598E(void) {
  cpu_push_bc();
  set_de(0x847C);
  b = 0x05;
  lab_p29_L_5994: ;
  p00_L_01AD();
  a = (uint8_t)(a + 0x30);
  mem_write8(de(), a);
  set_de((uint16_t)(de() - 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_5994;
  a = 0;
  flag_logic(a);
  mem_write8(0x847D, a);
  cpu_ex_de_hl();
  a = 0x30;
  b = 0x04;
  lab_p29_L_59A6: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_cp_hl();
  if (flag_nz()) goto lab_p29_L_59AE;
  mem_write8(hl(), 0x20);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_59A6;
  lab_p29_L_59AE: ;
  cpu_pop_bc();
  p00_L_3D4D();
  return;
}

/* flash page 29 cpu 0x59B3 (offset 0x19B3) */
void p29_L_59B3(void) {
  cpu_push_af();
  set_de(0x0E10);
  os_bcall(0x80B1);
  set_de(0x0018);
  os_bcall(0x80B1);
  set_hl(mem_read16(0x847A));
  p29_L_57C5();
  set_de(0x016D);
  os_bcall(0x804B);
  cpu_push_de();
  cpu_pop_hl();
  set_bc(0x07CD);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  p29_L_5A68();
  a = a | a;
  flag_logic(a);
  set_hl(mem_read16(0x847A));
  p29_L_57C5();
  cpu_sbc_hl_bc();
  p29_L_57C5();
  mem_write16(0x847A, hl());
  p29_L_57C5();
  set_de(0x016D);
  os_bcall(0x804B);
  cpu_push_de();
  cpu_pop_hl();
  set_bc(0x07CD);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  cpu_push_hl();
  mem_write16(0x82A5, hl());
  a = e;
  set_de(0x016D);
  os_bcall(0x8045);
  cpu_push_hl();
  cpu_pop_bc();
  set_hl(mem_read16(0x847A));
  p29_L_57C5();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  set_bc(0x0000);
  lab_p29_L_5A10: ;
  cpu_push_hl();
  a = 0x02;
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p29_L_5A26;
  set_hl(mem_read16(0x82A5));
  p29_L_5AA5();
  if (flag_nz()) goto lab_p29_L_5A26;
  set_hl(0x5FD9);
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  goto lab_p29_L_5A31;
  lab_p29_L_5A26: ;
  a = a | a;
  flag_logic(a);
  set_hl(0x5FBF);
  /* adc hl,bc */
  /* adc hl,bc */
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  lab_p29_L_5A31: ;
  a = a | a;
  flag_logic(a);
  cpu_pop_hl();
  cpu_push_hl();
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p29_L_5A3C;
  cpu_pop_hl();
  set_bc((uint16_t)(bc() + 1));
  goto lab_p29_L_5A10;
  lab_p29_L_5A3C: ;
  cpu_pop_hl();
  cpu_push_hl();
  set_bc((uint16_t)(bc() - 1));
  a = 0x02;
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p29_L_5A54;
  set_hl(mem_read16(0x82A5));
  p29_L_5AA5();
  if (flag_nz()) goto lab_p29_L_5A54;
  set_hl(0x5FD9);
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  goto lab_p29_L_5A5F;
  lab_p29_L_5A54: ;
  set_hl(0x5FBF);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  /* adc hl,bc */
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  lab_p29_L_5A5F: ;
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_pop_de();
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() + 1));
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x5A68 (offset 0x1A68) */
void p29_L_5A68(void) {
  cpu_push_af();
  cpu_push_hl();
  cpu_push_de();
  cpu_push_hl();
  set_bc(0x07CD);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_pop_hl();
  if (flag_c()) return;
  if (flag_z()) goto lab_p29_L_5A77;
  set_hl((uint16_t)(hl() - 1));
  lab_p29_L_5A77: ;
  cpu_push_hl();
  set_de(0x0004);
  os_bcall(0x804B);
  cpu_pop_hl();
  cpu_push_de();
  cpu_push_hl();
  set_de(0x0064);
  os_bcall(0x804B);
  cpu_pop_hl();
  cpu_push_de();
  set_de(0x0190);
  os_bcall(0x804B);
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_de();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  set_bc(0x01E4);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x5AA5 (offset 0x1AA5) */
void p29_L_5AA5(void) {
  cpu_push_hl();
  set_de(0x0004);
  os_bcall(0x804B);
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_5ACA;
  cpu_pop_hl();
  cpu_push_hl();
  set_de(0x0064);
  os_bcall(0x804B);
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_5AC6;
  cpu_pop_hl();
  cpu_push_hl();
  set_de(0x0190);
  os_bcall(0x804B);
  if (flag_nz()) goto lab_p29_L_5ACA;
  lab_p29_L_5AC6: ;
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  lab_p29_L_5ACA: ;
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x5ACC (offset 0x1ACC) */
void p29_L_5ACC(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_af();
  set_de(0x8000);
  set_bc(0x0100);
  os_bcall(0x8054);
  cpu_pop_af();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x5ADE (offset 0x1ADE) */
void p29_L_5ADE(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_af();
  p00_L_3D0B();
  p00_L_3D2F();
  set_hl(0x26E9);
  a = 0x3D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p29_L_7045();
  p00_L_23DE();
  if (flag_c()) goto lab_p29_L_5B0D;
  a = mem_read8(de());
  set_hl(mem_read16(0x844C));
  set_bc(0x0005);
  /* adc hl,bc */
  mem_write16(0x844C, hl());
  l = a;
  h = 0x00;
  p00_L_3C7B();
  lab_p29_L_5B0D: ;
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x5B11 (offset 0x1B11) */
void p29_L_5B11(void) {
  lab_p29_L_5B11: ;
  p00_L_23DE();
  if (flag_c()) goto lab_p29_L_5B2E;
  cpu_push_af();
  a = mem_read8(de());
  l = a;
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  h = a;
  set_de((uint16_t)(de() - 1));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_5B2A;
  cpu_pop_af();
  set_bc(0x0001);
  p00_L_31D7();
  goto lab_p29_L_5B11;
  lab_p29_L_5B2A: ;
  cpu_pop_af();
  p00_L_23D4();
  lab_p29_L_5B2E: ;
  return;
}

/* flash page 29 cpu 0x5B2F (offset 0x1B2F) */
void p29_L_5B2F(void) {
  cpu_push_af();
  set_de(0x0A10);
  os_bcall(0x8027);
  if (flag_nz()) goto lab_p29_L_5B49;
  p29_L_4574();
  set_de(0x8483);
  b = c;
  a = 0x7E;
  p29_L_761F();
  cpu_pop_af();
  p29_L_5B4D();
  return;
  lab_p29_L_5B49: ;
  cpu_pop_af();
  /* scf */
  /* ccf */
  return;
}

/* flash page 29 cpu 0x5B4D (offset 0x1B4D) */
void p29_L_5B4D(void) {
  cpu_push_bc();
  cpu_push_de();
  p29_L_7656();
  set_hl(0x4003);
  mem_write8(0x82A3, a);
  lab_p29_L_5B58: ;
  cpu_push_hl();
  os_bcall(0x8051);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p29_L_5B67;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p29_L_5BA8;
  cpu_pop_hl();
  goto lab_p29_L_5BC2;
  lab_p29_L_5B67: ;
  a = mem_read8(0x82A3);
  p29_L_442C();
  cpu_push_bc();
  cpu_push_de();
  set_hl(0x8483);
  cpu_pop_de();
  cpu_pop_bc();
  if (flag_nz()) goto lab_p29_L_5BC2;
  b = c;
  lab_p29_L_5B77: ;
  a = mem_read8(hl());
  c = a;
  cpu_ex_de_hl();
  a = mem_read8(0x82A3);
  os_bcall(0x8051);
  cpu_ex_de_hl();
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p29_L_5B8E;
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_5B77;
  cpu_pop_hl();
  a = mem_read8(0x82A3);
  goto lab_p29_L_5BC6;
  lab_p29_L_5B8E: ;
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(0x82A3);
  cpu_push_de();
  os_bcall(0x805A);
  cpu_pop_de();
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(0x82A3);
  cpu_push_de();
  os_bcall(0x805A);
  cpu_pop_de();
  /* adc hl,bc */
  goto lab_p29_L_5B58;
  lab_p29_L_5BA8: ;
  cpu_pop_hl();
  a = mem_read8(0x82A3);
  a = (uint8_t)(a + 1);
  mem_write8(0x82A3, a);
  p00_L_24A9();
  if (flag_nz()) goto lab_p29_L_5BB9;
  flag_cmp(a, 0x6C);
  goto lab_p29_L_5BBB;
  lab_p29_L_5BB9: ;
  flag_cmp(a, 0x18);
  lab_p29_L_5BBB: ;
  if (flag_z()) goto lab_p29_L_5BC2;
  set_hl(0x4000);
  goto lab_p29_L_5B58;
  lab_p29_L_5BC2: ;
  /* scf */
  /* ccf */
  goto lab_p29_L_5BC7;
  lab_p29_L_5BC6: ;
  /* scf */
  lab_p29_L_5BC7: ;
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x5BCA (offset 0x1BCA) */
void p29_L_5BCA(void) {
  cpu_push_de();
  cpu_push_bc();
  cpu_push_hl();
  mem_write8(0x82A3, a);
  p29_L_4894();
  p29_L_457C();
  a = mem_read8(0x82A3);
  cpu_pop_hl();
  p29_L_529F();
  cpu_pop_bc();
  cpu_pop_de();
  return;
}

/* flash page 29 cpu 0x5BE0 (offset 0x1BE0) */
void p29_L_5BE0(void) {
  mem_write8(0x83EB, a);
  cpu_ld_a_i();
  /* di */
  cpu_push_af();
  a = mem_read8(0x83EB);
  cpu_push_af();
  a = 0x01;
  p29_L_5BED();
  return;
}

/* flash page 29 cpu 0x5BED (offset 0x1BED) */
void p29_L_5BED(void) {
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
  cpu_push_de();
  cpu_push_bc();
  lab_p29_L_5BFD: ;
  set_de(0x0410);
  os_bcall(0x8027);
  if (flag_z()) goto lab_p29_L_5C0A;
  os_bcall(0x80AE);
  goto lab_p29_L_5BFD;
  lab_p29_L_5C0A: ;
  p29_L_4574();
  set_de(0x8483);
  os_bcall(0x8051);
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  p29_L_4565();
  mem_write8(de(), a);
  set_hl(0x8483);
  cpu_pop_bc();
  cpu_pop_de();
  p29_L_5FDB();
  mem_write8(0x83EB, a);
  cpu_pop_af();
  if (flag_po()) goto lab_p29_L_5C29;
  /* ei */
  lab_p29_L_5C29: ;
  a = mem_read8(0x83EB);
  return;
}

/* flash page 29 cpu 0x5C2D (offset 0x1C2D) */
void p29_L_5C2D(void) {
  set_hl(0x4000);
  set_de(0x8090);
  os_bcall(0x8075);
  return;
}

/* flash page 29 cpu 0x5C37 (offset 0x1C37) */
void p29_L_5C37(void) {
  cpu_push_hl();
  p29_L_7656();
  set_hl(0x4000);
  os_bcall(0x8051);
  flag_cmp(a, 0x00);
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x5C45 (offset 0x1C45) */
void p29_L_5C45(void) {
  cpu_push_de();
  cpu_push_bc();
  cpu_push_af();
  cpu_push_hl();
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
  set_de(0x4000);
  b = 0x00;
  p29_L_7656();
  os_bcall(0x80C6);
  cpu_pop_hl();
  cpu_push_hl();
  b = l;
  p29_L_7656();
  os_bcall(0x80C6);
  cpu_pop_hl();
  b = h;
  p29_L_7656();
  os_bcall(0x80C6);
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_de();
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x5C7C (offset 0x1C7C) */
void p29_L_5C7C(void) {
  cpu_push_hl();
  lab_p29_L_5C7D: ;
  a = mem_read8(ix);
  cpu_push_bc();
  p29_L_5C8E();
  cpu_pop_bc();
  ix = (uint16_t)(ix + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_5C7D;
  p29_L_6503();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x5C8E (offset 0x1C8E) */
void p29_L_5C8E(void) {
  a = mem_read8(ix);
  cpu_push_af();
  a = a & 0xF0;
  flag_logic(a);
  /* srl a */
  /* srl a */
  /* srl a */
  /* srl a */
  b = 0x02;
  lab_p29_L_5C9E: ;
  cpu_push_af();
  a = (uint8_t)(a - 0x0A);
  if (flag_c()) goto lab_p29_L_5CB2;
  cpu_pop_af();
  a = (uint8_t)(a + 0x37);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  a = b;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_5CC1;
  cpu_pop_af();
  a = a & 0x0F;
  flag_logic(a);
  goto lab_p29_L_5C9E;
  lab_p29_L_5CB2: ;
  cpu_pop_af();
  a = (uint8_t)(a + 0x30);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  a = b;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_5CC1;
  cpu_pop_af();
  a = a & 0x0F;
  flag_logic(a);
  goto lab_p29_L_5C9E;
  lab_p29_L_5CC1: ;
  a = 0x00;
  mem_write8(hl(), a);
  return;
}

/* flash page 29 cpu 0x5CC5 (offset 0x1CC5) */
void p29_L_5CC5(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  a = mem_read8(hl());
  cpu_push_af();
  a = a & 0xF0;
  flag_logic(a);
  /* srl a */
  /* srl a */
  /* srl a */
  /* srl a */
  b = 0x02;
  lab_p29_L_5CD6: ;
  cpu_push_af();
  a = (uint8_t)(a - 0x0A);
  if (flag_c()) goto lab_p29_L_5CEB;
  cpu_pop_af();
  a = (uint8_t)(a + 0x37);
  p00_L_3D47();
  b = (uint8_t)(b - 1);
  a = b;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_5CFB;
  cpu_pop_af();
  a = a & 0x0F;
  flag_logic(a);
  goto lab_p29_L_5CD6;
  lab_p29_L_5CEB: ;
  cpu_pop_af();
  a = (uint8_t)(a + 0x30);
  p00_L_3D47();
  b = (uint8_t)(b - 1);
  a = b;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_5CFB;
  cpu_pop_af();
  a = a & 0x0F;
  flag_logic(a);
  goto lab_p29_L_5CD6;
  lab_p29_L_5CFB: ;
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x5CFF (offset 0x1CFF) */
void p29_L_5CFF(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  cpu_push_af();
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_5D18;
  set_de(0x83A5);
  lab_p29_L_5D0B: ;
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8051);
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_5D0B;
  lab_p29_L_5D18: ;
  cpu_pop_af();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x5D1E (offset 0x1D1E) */
void p29_L_5D1E(void) {
  cpu_push_bc();
  cpu_push_de();
  cpu_push_af();
  b = a;
  a = 0x00;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_5D3D;
  a = b;
  set_de(0x83A5);
  b = c;
  set_hl(0x0000);
  a = mem_read8(de());
  l = a;
  b = (uint8_t)(b - 1);
  a = b;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_5D3F;
  set_de((uint16_t)(de() + 1));
  a = l;
  h = a;
  a = mem_read8(de());
  h = a;
  goto lab_p29_L_5D3F;
  lab_p29_L_5D3D: ;
  h = a;
  l = a;
  lab_p29_L_5D3F: ;
  cpu_pop_af();
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x5D43 (offset 0x1D43) */
void p29_L_5D43(void) {
  cpu_push_hl();
  cpu_push_de();
  cpu_push_af();
  b = a;
  a = 0x00;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_5D62;
  a = b;
  set_hl(0x83A5);
  e = c;
  set_bc(0x0000);
  a = mem_read8(hl());
  c = a;
  e = (uint8_t)(e - 1);
  a = e;
  a = a | e;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_5D64;
  set_hl((uint16_t)(hl() + 1));
  a = c;
  b = a;
  a = mem_read8(hl());
  c = a;
  goto lab_p29_L_5D64;
  lab_p29_L_5D62: ;
  b = a;
  c = a;
  lab_p29_L_5D64: ;
  cpu_pop_af();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x5D68 (offset 0x1D68) */
void p29_L_5D68(void) {
  cpu_push_af();
  cpu_push_hl();
  p29_L_6800();
  e = b;
  d = 0x00;
  cpu_push_de();
  b = (uint8_t)(b + 1);
  c = 0x00;
  a = 0x08;
  lab_p29_L_5D76: ;
  flag_cmp(a, b);
  if (flag_z()) goto lab_p29_L_5DC2;
  if (flag_nc()) goto lab_p29_L_5DC0;
  cpu_push_bc();
  set_hl(0x4000);
  cpu_push_af();
  p29_L_6B36();
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p29_L_5D8D;
  cpu_pop_af();
  a = (uint8_t)(a + 0x04);
  lab_p29_L_5D8A: ;
  cpu_pop_bc();
  goto lab_p29_L_5D76;
  lab_p29_L_5D8D: ;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p29_L_5D9F;
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_push_af();
  a = c;
  a = (uint8_t)(a + d);
  d = a;
  cpu_pop_af();
  cpu_push_de();
  c = 0x00;
  cpu_push_bc();
  cpu_push_af();
  set_hl((uint16_t)(hl() + 1));
  lab_p29_L_5D9F: ;
  cpu_pop_af();
  c = 0xFF;
  p29_L_6769();
  set_bc(0x4000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nz()) goto lab_p29_L_5DB0;
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  cpu_push_bc();
  lab_p29_L_5DB0: ;
  a = (uint8_t)(a + 1);
  cpu_pop_bc();
  flag_cmp(a, b);
  if (flag_z()) goto lab_p29_L_5DC2;
  cpu_push_bc();
  p29_L_67EC();
  if (flag_z()) goto lab_p29_L_5D8A;
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  cpu_push_bc();
  goto lab_p29_L_5DB0;
  lab_p29_L_5DC0: ;
  a = 0;
  flag_logic(a);
  c = a;
  lab_p29_L_5DC2: ;
  b = c;
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x5DC7 (offset 0x1DC7) */
void p29_L_5DC7(void) {
  p29_L_5D68();
  c = e;
  cpu_push_bc();
  cpu_push_de();
  a = 0x01;
  set_hl(0x8000);
  set_de(0x8080);
  os_bcall(0x8075);
  set_hl((uint16_t)(hl() + 1));
  a = 0x01;
  os_bcall(0x805A);
  a = mem_read8(hl());
  cpu_pop_de();
  e = d;
  d = a;
  cpu_pop_bc();
  a = (uint8_t)(a - b);
  return;
}

/* flash page 29 cpu 0x5DE5 (offset 0x1DE5) */
void p29_L_5DE5(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  os_bcall(0x802D);
  cpu_ex_de_hl();
  os_bcall(0x8057);
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_ex_de_hl();
  set_hl(0x1F18);
  p00_L_24A9();
  if (flag_nz()) goto lab_p29_L_5E00;
  set_hl(0x1DEA);
  lab_p29_L_5E00: ;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_pop_bc();
  cpu_sbc_hl_bc();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x5E0A (offset 0x1E0A) */
void p29_L_5E0A(void) {
  a = mem_read8(0x83A3);
  b = a;
  c = 0x00;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_5E23;
  set_hl(0x8000);
  lab_p29_L_5E16: ;
  cpu_push_bc();
  cpu_push_hl();
  set_bc(0x0001);
  os_bcall(0x8090);
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_5E16;
  lab_p29_L_5E23: ;
  a = 0x00;
  mem_write8(0x83A3, a);
  return;
}

/* flash page 29 cpu 0x5E31 (offset 0x1E31) */
void p29_L_5E31(void) {
  set_hl(0x4000);
  p29_L_5E34();
  return;
}

/* flash page 29 cpu 0x5E34 (offset 0x1E34) */
void p29_L_5E34(void) {
  goto lab_p29_L_5E34;
  lab_p29_L_5E29: ;
  a = 0x0C;
  p00_L_2C49();
  p00_L_2565();
  return;
  lab_p29_L_5E34: ;
  cpu_push_af();
  set_de(0x8010);
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_5E29;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x805A);
  set_de(0x838D);
  a = 0x07;
  mem_write8(de(), a);
  set_de(0x838F);
  mem_write16(0x838E, bc());
  cpu_pop_af();
  os_bcall(0x8054);
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x5E59 (offset 0x1E59) */
void p29_L_5E59(void) {
  goto lab_p29_L_5E59;
  lab_p29_L_5E29: ;
  a = 0x0C;
  p00_L_2C49();
  p00_L_2565();
  return;
  lab_p29_L_5E59: ;
  cpu_push_af();
  set_de(0x8010);
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_5E29;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x805A);
  set_de(0x838E);
  mem_write16(0x838D, bc());
  cpu_pop_af();
  os_bcall(0x8054);
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x5E78 (offset 0x1E78) */
void p29_L_5E78(void) {
  b = a;
  p29_L_75EC();
  a = (uint8_t)(a - b);
  b = 0x00;
  c = a;
  cpu_push_bc();
  ix = cpu_pop16();
  p29_L_48B5();
  if (flag_c()) goto lab_p29_L_5E8F;
  if (flag_z()) goto lab_p29_L_5E8F;
  cpu_push_af();
  p29_L_5365();
  cpu_pop_af();
  lab_p29_L_5E8F: ;
  return;
}

/* flash page 29 cpu 0x5E90 (offset 0x1E90) */
void p29_L_5E90(void) {
  cpu_push_af();
  cpu_push_af();
  a = 0x01;
  a = a | a;
  flag_logic(a);
  set_hl(0x8000);
  set_de(0x8060);
  os_bcall(0x8075);
  if (flag_z()) goto lab_p29_L_5EB5;
  set_hl(0x8000);
  set_de(0x8050);
  os_bcall(0x8075);
  if (flag_z()) goto lab_p29_L_5EB0;
  set_de(0x0080);
  goto lab_p29_L_5EDD;
  lab_p29_L_5EB0: ;
  set_de(0x0000);
  goto lab_p29_L_5EDD;
  lab_p29_L_5EB5: ;
  set_hl((uint16_t)(hl() + 1));
  a = 0x01;
  os_bcall(0x805A);
  a = 0x01;
  os_bcall(0x8051);
  cpu_push_af();
  b = 0x09;
  a = (uint8_t)(a - b);
  if (flag_c()) goto lab_p29_L_5ED6;
  cpu_pop_af();
  b = 0x08;
  a = (uint8_t)(a - b);
  p29_L_4E9B();
  p29_L_5ECD();
  return;
  lab_p29_L_5ED6: ;
  d = 0x00;
  cpu_pop_af();
  p29_L_4E9B();
  e = a;
  lab_p29_L_5EDD: ;
  cpu_pop_af();
  b = a;
  p29_L_75EC();
  a = (uint8_t)(a - b);
  set_bc(0x0000);
  c = a;
  p29_L_5231();
  /* sla c */
  set_hl((uint16_t)(hl() + bc()));
  b = e;
  cpu_ex_de_hl();
  cpu_push_hl();
  p29_L_456D();
  cpu_pop_hl();
  cpu_ex_de_hl();
  b = d;
  cpu_ex_de_hl();
  p29_L_456D();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x5ECD (offset 0x1ECD) */
void p29_L_5ECD(void) {
  d = a;
  a = 0x08;
  p29_L_4E9B();
  e = a;
  goto lab_p29_L_5EDD;
  lab_p29_L_5EDD: ;
  cpu_pop_af();
  b = a;
  p29_L_75EC();
  a = (uint8_t)(a - b);
  set_bc(0x0000);
  c = a;
  p29_L_5231();
  /* sla c */
  set_hl((uint16_t)(hl() + bc()));
  b = e;
  cpu_ex_de_hl();
  cpu_push_hl();
  p29_L_456D();
  cpu_pop_hl();
  cpu_ex_de_hl();
  b = d;
  cpu_ex_de_hl();
  p29_L_456D();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x5EFC (offset 0x1EFC) */
void p29_L_5EFC(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  cpu_pop_de();
  b = a;
  c = 0x08;
  a = (uint8_t)(a - c);
  if (flag_c()) goto lab_p29_L_5F25;
  p29_L_75EC();
  a = (uint8_t)(a + 1);
  c = a;
  a = b;
  a = (uint8_t)(a - c);
  if (flag_nc()) goto lab_p29_L_5F25;
  set_bc(0x4000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p29_L_5F25;
  cpu_push_de();
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  set_bc(0x8000);
  cpu_sbc_hl_bc();
  p29_L_5F20();
  return;
  lab_p29_L_5F25: ;
  /* scf */
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x5F20 (offset 0x1F20) */
void p29_L_5F20(void) {
  if (flag_nc()) goto lab_p29_L_5F25;
  a = a | a;
  flag_logic(a);
  goto lab_p29_L_5F26;
  lab_p29_L_5F25: ;
  /* scf */
  lab_p29_L_5F26: ;
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x5F2A (offset 0x1F2A) */
void p29_L_5F2A(void) {
  cpu_push_hl();
  os_bcall(0x8057);
  set_de(0x0A10);
  p29_L_777E();
  if (flag_z()) { p00_L_255F(); return; }
  cpu_pop_hl();
  set_de(0x0A10);
  p29_L_777E();
  if (flag_nz()) { p00_L_255F(); return; }
  cpu_ex_de_hl();
  cpu_push_de();
  os_bcall(0x802D);
  cpu_pop_de();
  set_bc(0x0002);
  cpu_ex_de_hl();
  lab_p29_L_5F4B: ;
  cpu_push_bc();
  p29_L_4566();
  b = a;
  cpu_push_hl();
  p29_L_456D();
  cpu_pop_hl();
  p29_L_4565();
  b = a;
  cpu_push_hl();
  p29_L_456D();
  cpu_pop_hl();
  cpu_push_de();
  cpu_push_hl();
  p29_L_4575();
  cpu_pop_de();
  cpu_push_bc();
  cpu_push_hl();
  cpu_sbc_hl_de();
  b = l;
  b = (uint8_t)(b - 1);
  cpu_pop_hl();
  a = 0x00;
  flag_cmp(a, b);
  if (flag_z()) goto lab_p29_L_5F74;
  lab_p29_L_5F70: ;
  a = (uint8_t)(a + 1);
  set_hl((uint16_t)(hl() - 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_5F70;
  lab_p29_L_5F74: ;
  cpu_pop_bc();
  cpu_pop_de();
  a = a | a;
  flag_logic(a);
  /* adc a,c */
  c = a;
  a = 0x7E;
  cpu_push_de();
  cpu_push_bc();
  set_de(0x83A5);
  os_bcall(0x8054);
  cpu_push_hl();
  set_hl(0x83A5);
  p29_L_5F9F();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_push_hl();
  set_hl(0x83A5);
  a = 0x7E;
  os_bcall(0x8087);
  cpu_pop_hl();
  cpu_pop_bc();
  c = (uint8_t)(c - 1);
  a = c;
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p29_L_5F4B;
  return;
}

/* flash page 29 cpu 0x5F9F (offset 0x1F9F) */
void p29_L_5F9F(void) {
  cpu_push_hl();
  a = mem_read8(hl());
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p29_L_5FBD;
  cpu_push_hl();
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  e = mem_read8(hl());
  cpu_push_de();
  os_bcall(0x80C3);
  cpu_push_de();
  cpu_pop_bc();
  cpu_pop_de();
  cpu_ex_de_hl();
  h = b;
  a = l;
  a = a & 0x0F;
  flag_logic(a);
  a = a | a;
  flag_logic(a);
  /* adc a,c */
  l = a;
  cpu_ex_de_hl();
  cpu_pop_hl();
  mem_write8(hl(), e);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), d);
  lab_p29_L_5FBD: ;
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x5FDB (offset 0x1FDB) */
void p29_L_5FDB(void) {
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

/* flash page 29 cpu 0x5FED (offset 0x1FED) */
void p29_L_5FED(void) {
  mem_write8(0x83EB, a);
  cpu_ld_a_i();
  /* di */
  cpu_push_af();
  a = mem_read8(0x83EB);
  p29_L_5FDB();
  mem_write8(0x83EB, a);
  cpu_pop_af();
  if (flag_po()) goto lab_p29_L_6002;
  /* ei */
  lab_p29_L_6002: ;
  a = mem_read8(0x83EB);
  return;
}

/* flash page 29 cpu 0x6006 (offset 0x2006) */
void p29_L_6006(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_af();
  cpu_pop_bc();
  a = c;
  mem_write8(0x83EA, a);
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x6011 (offset 0x2011) */
void p29_L_6011(void) {
  mem_write8(0x83EC, a);
  cpu_push_bc();
  b = a;
  a = mem_read8(0x83EA);
  c = a;
  cpu_push_bc();
  cpu_pop_af();
  cpu_pop_bc();
  a = mem_read8(0x83EC);
  return;
}

/* flash page 29 cpu 0x6021 (offset 0x2021) */
void p29_L_6021(void) {
  p29_L_75F5();
  lab_p29_L_6024: ;
  a = mem_read8(0x838D);
  c = a;
  b = 0x00;
  set_hl(0x838E);
  set_de(0x8000);
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  while (bc() != 0) { cpu_ldi(); }
  p29_L_607A();
  cpu_push_af();
  a = mem_read8(0x8000);
  c = a;
  b = 0x00;
  set_hl(0x8001);
  set_de(0x838D);
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_af();
  if (flag_c()) return;
  p29_L_6067();
  if (flag_nz()) goto lab_p29_L_6053;
  a = a | a;
  flag_logic(a);
  p29_L_61A4();
  return;
  lab_p29_L_6053: ;
  cpu_push_af();
  a = mem_read8(0x8000);
  c = a;
  b = 0x00;
  set_hl(0x8001);
  set_de(0x838D);
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_af();
  goto lab_p29_L_6024;
}

/* flash page 29 cpu 0x6067 (offset 0x2067) */
void p29_L_6067(void) {
  set_de(0x8483);
  set_hl(0x838D);
  a = mem_read8(de());
  c = mem_read8(hl());
  flag_cmp(a, c);
  if (flag_nz()) return;
  b = c;
  lab_p29_L_6072: ;
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  a = mem_read8(de());
  cpu_cp_hl();
  if (flag_nz()) return;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_6072;
  return;
}

/* flash page 29 cpu 0x607A (offset 0x207A) */
void p29_L_607A(void) {
  lab_p29_L_607A: ;
  set_de(0x82A3);
  a = mem_read8(de());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_60E4;
  a = (uint8_t)(a - 1);
  mem_write8(de(), a);
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p29_L_608A;
  /* scf */
  goto lab_p29_L_60E4;
  lab_p29_L_608A: ;
  a = mem_read8(0x82A3);
  set_hl(0x4000);
  p00_L_3E31();
  if (flag_nz()) goto lab_p29_L_607A;
  set_de(0x8010);
  a = a | a;
  flag_logic(a);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_607A;
  a = mem_read8(0x82A3);
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  a = mem_read8(0x82A3);
  os_bcall(0x8051);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_607A;
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p29_L_607A;
  a = mem_read8(0x82A3);
  cpu_push_hl();
  cpu_push_bc();
  p29_L_5E31();
  p29_L_53E5();
  if (flag_z()) goto lab_p29_L_60C2;
  cpu_pop_bc();
  cpu_pop_hl();
  goto lab_p29_L_607A;
  lab_p29_L_60C2: ;
  p00_L_129A();
  cpu_pop_bc();
  cpu_pop_hl();
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_60D2;
  a = 0;
  flag_logic(a);
  a = c;
  e = 0x09;
  a = (uint8_t)(a - e);
  if (flag_c()) goto lab_p29_L_60D5;
  lab_p29_L_60D2: ;
  set_bc(0x0008);
  lab_p29_L_60D5: ;
  a = c;
  mem_write8(0x8483, a);
  a = mem_read8(0x82A3);
  set_de(0x8484);
  os_bcall(0x8054);
  /* scf */
  /* ccf */
  lab_p29_L_60E4: ;
  return;
}

/* flash page 29 cpu 0x60E5 (offset 0x20E5) */
void p29_L_60E5(void) {
  a = 0x01;
  goto lab_p29_L_60EA;
  lab_p29_L_60EA: ;
  set_bc(0x0000);
  cpu_push_bc();
  p00_L_1100();
  cpu_push_af();
  a = mem_read8(0x9C87);
  flag_cmp(a, 0x69);
  if (flag_nz()) p29_L_7BA4();
  p29_L_75F5();
  cpu_pop_af();
  lab_p29_L_60FE: ;
  cpu_push_af();
  p29_L_6388();
  cpu_pop_hl();
  a = h;
  if (flag_c()) goto lab_p29_L_6140;
  cpu_push_af();
  a = mem_read8(0x9C87);
  flag_cmp(a, 0x69);
  a = mem_read8(0x82A3);
  if (flag_nz()) p29_L_7BAF();
  cpu_pop_af();
  p29_L_6172();
  if (flag_c()) goto lab_p29_L_612E;
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p29_L_60FE;
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  cpu_push_bc();
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p29_L_60FE;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p29_L_6163;
  p29_L_6177();
  if (flag_c()) goto lab_p29_L_6165;
  goto lab_p29_L_60FE;
  lab_p29_L_612E: ;
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  cpu_push_bc();
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) goto lab_p29_L_60FE;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p29_L_6163;
  p29_L_6177();
  if (flag_c()) goto lab_p29_L_60FE;
  goto lab_p29_L_6165;
  lab_p29_L_6140: ;
  p00_L_113F();
  a = (uint8_t)(a & ~(1u << 0));
  a = (uint8_t)(a - 0x02);
  cpu_pop_bc();
  cpu_push_af();
  a = mem_read8(0x8497);
  d = a;
  a = 0;
  flag_logic(a);
  mem_write8(0x8497, a);
  mem_write8(0x8481, a);
  a = mem_read8(0x9C87);
  flag_cmp(a, 0x01);
  a = 0x69;
  if (flag_nz()) goto lab_p29_L_615E;
  a = 0;
  flag_logic(a);
  lab_p29_L_615E: ;
  mem_write8(0x9C87, a);
  cpu_pop_af();
  return;
  lab_p29_L_6163: ;
  a = (uint8_t)(a | (1u << 1));
  lab_p29_L_6165: ;
  p00_L_11D8();
  cpu_push_af();
  a = mem_read8(0x82A3);
  mem_write8(0x8497, a);
  cpu_pop_af();
  goto lab_p29_L_60FE;
}

/* flash page 29 cpu 0x60E9 (offset 0x20E9) */
void p29_L_60E9(void) {
  a = 0;
  flag_logic(a);
  set_bc(0x0000);
  cpu_push_bc();
  p00_L_1100();
  cpu_push_af();
  a = mem_read8(0x9C87);
  flag_cmp(a, 0x69);
  if (flag_nz()) p29_L_7BA4();
  p29_L_75F5();
  cpu_pop_af();
  lab_p29_L_60FE: ;
  cpu_push_af();
  p29_L_6388();
  cpu_pop_hl();
  a = h;
  if (flag_c()) goto lab_p29_L_6140;
  cpu_push_af();
  a = mem_read8(0x9C87);
  flag_cmp(a, 0x69);
  a = mem_read8(0x82A3);
  if (flag_nz()) p29_L_7BAF();
  cpu_pop_af();
  p29_L_6172();
  if (flag_c()) goto lab_p29_L_612E;
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p29_L_60FE;
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  cpu_push_bc();
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p29_L_60FE;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p29_L_6163;
  p29_L_6177();
  if (flag_c()) goto lab_p29_L_6165;
  goto lab_p29_L_60FE;
  lab_p29_L_612E: ;
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  cpu_push_bc();
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) goto lab_p29_L_60FE;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p29_L_6163;
  p29_L_6177();
  if (flag_c()) goto lab_p29_L_60FE;
  goto lab_p29_L_6165;
  lab_p29_L_6140: ;
  p00_L_113F();
  a = (uint8_t)(a & ~(1u << 0));
  a = (uint8_t)(a - 0x02);
  cpu_pop_bc();
  cpu_push_af();
  a = mem_read8(0x8497);
  d = a;
  a = 0;
  flag_logic(a);
  mem_write8(0x8497, a);
  mem_write8(0x8481, a);
  a = mem_read8(0x9C87);
  flag_cmp(a, 0x01);
  a = 0x69;
  if (flag_nz()) goto lab_p29_L_615E;
  a = 0;
  flag_logic(a);
  lab_p29_L_615E: ;
  mem_write8(0x9C87, a);
  cpu_pop_af();
  return;
  lab_p29_L_6163: ;
  a = (uint8_t)(a | (1u << 1));
  lab_p29_L_6165: ;
  p00_L_11D8();
  cpu_push_af();
  a = mem_read8(0x82A3);
  mem_write8(0x8497, a);
  cpu_pop_af();
  goto lab_p29_L_60FE;
}

/* flash page 29 cpu 0x60EF (offset 0x20EF) */
void p29_L_60EF(void) {
  /* nop */
  set_de(0x3AF5);
  a = (uint8_t)(a + a);
  /* sbc a,h */
  flag_cmp(a, 0x69);
  if (flag_nz()) p29_L_7BA4();
  p29_L_75F5();
  cpu_pop_af();
  lab_p29_L_60FE: ;
  cpu_push_af();
  p29_L_6388();
  cpu_pop_hl();
  a = h;
  if (flag_c()) goto lab_p29_L_6140;
  cpu_push_af();
  a = mem_read8(0x9C87);
  flag_cmp(a, 0x69);
  a = mem_read8(0x82A3);
  if (flag_nz()) p29_L_7BAF();
  cpu_pop_af();
  p29_L_6172();
  if (flag_c()) goto lab_p29_L_612E;
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p29_L_60FE;
  cpu_pop_bc();
  b = (uint8_t)(b + 1);
  cpu_push_bc();
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p29_L_60FE;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p29_L_6163;
  p29_L_6177();
  if (flag_c()) goto lab_p29_L_6165;
  goto lab_p29_L_60FE;
  lab_p29_L_612E: ;
  cpu_pop_bc();
  c = (uint8_t)(c + 1);
  cpu_push_bc();
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_z()) goto lab_p29_L_60FE;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p29_L_6163;
  p29_L_6177();
  if (flag_c()) goto lab_p29_L_60FE;
  goto lab_p29_L_6165;
  lab_p29_L_6140: ;
  p00_L_113F();
  a = (uint8_t)(a & ~(1u << 0));
  a = (uint8_t)(a - 0x02);
  cpu_pop_bc();
  cpu_push_af();
  a = mem_read8(0x8497);
  d = a;
  a = 0;
  flag_logic(a);
  mem_write8(0x8497, a);
  mem_write8(0x8481, a);
  a = mem_read8(0x9C87);
  flag_cmp(a, 0x01);
  a = 0x69;
  if (flag_nz()) goto lab_p29_L_615E;
  a = 0;
  flag_logic(a);
  lab_p29_L_615E: ;
  mem_write8(0x9C87, a);
  cpu_pop_af();
  return;
  lab_p29_L_6163: ;
  a = (uint8_t)(a | (1u << 1));
  lab_p29_L_6165: ;
  p00_L_11D8();
  cpu_push_af();
  a = mem_read8(0x82A3);
  mem_write8(0x8497, a);
  cpu_pop_af();
  goto lab_p29_L_60FE;
}

/* flash page 29 cpu 0x6172 (offset 0x2172) */
void p29_L_6172(void) {
  set_de(0x8480);
  goto lab_p29_L_617A;
  lab_p29_L_617A: ;
  cpu_push_af();
  set_hl(0x848B);
  b = 0x08;
  p00_L_3E3D();
  cpu_pop_hl();
  a = h;
  return;
}

/* flash page 29 cpu 0x6177 (offset 0x2177) */
void p29_L_6177(void) {
  set_de(0x8496);
  cpu_push_af();
  set_hl(0x848B);
  b = 0x08;
  p00_L_3E3D();
  cpu_pop_hl();
  a = h;
  return;
}

/* flash page 29 cpu 0x6186 (offset 0x2186) */
void p29_L_6186(void) {
  p29_L_75F5();
  lab_p29_L_6189: ;
  p29_L_638B();
  if (flag_c()) return;
  p29_L_6172();
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_z()) goto lab_p29_L_6189;
  p29_L_61A4();
  return;
}

/* flash page 29 cpu 0x6196 (offset 0x2196) */
void p29_L_6196(void) {
  p29_L_75F5();
  lab_p29_L_6199: ;
  p29_L_6388();
  if (flag_c()) return;
  p29_L_6172();
  flag_set_z((c & (1u << 3)) == 0);
  if (flag_z()) goto lab_p29_L_6199;
  p29_L_61A4();
  return;
}

/* flash page 29 cpu 0x61A4 (offset 0x21A4) */
void p29_L_61A4(void) {
  a = mem_read8(0x82A3);
  a = a | a;
  flag_logic(a);
  cpu_push_bc();
  set_de(0x8070);
  set_hl(0x4000);
  cpu_push_af();
  os_bcall(0x8075);
  cpu_pop_af();
  set_hl((uint16_t)(hl() + 1));
  cpu_push_af();
  os_bcall(0x805A);
  cpu_pop_af();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x61BC (offset 0x21BC) */
void p29_L_61BC(void) {
  p00_L_2D2D();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  cpu_push_af();
  p00_L_3CFF();
  cpu_pop_af();
  cpu_push_af();
  set_hl(0x4000);
  set_de(0x8040);
  os_bcall(0x8075);
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x805A);
  cpu_pop_af();
  cpu_push_af();
  p29_L_5CFF();
  set_hl(0x83A5);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  mem_write8(hl(), 0x00);
  a = 0x24;
  a = (uint8_t)(a - c);
  l = a;
  h = 0x05;
  mem_write16(0x86D7, hl());
  set_hl(0x83A5);
  p00_L_3D4D();
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p29_L_6201;
  a = 0x50;
  p00_L_3C45();
  if (flag_z()) goto lab_p29_L_620C;
  lab_p29_L_6201: ;
  set_hl(0x636F);
  set_de(0x82A5);
  set_bc(0x0019);
  while (bc() != 0) { cpu_ldi(); }
  lab_p29_L_620C: ;
  set_hl(0x82A5);
  p29_L_62B3();
  set_hl(0x2750);
  p29_L_62B3();
  cpu_pop_af();
  cpu_push_af();
  p29_L_54A0();
  if (flag_nz()) goto lab_p29_L_6270;
  cpu_pop_af();
  cpu_push_af();
  p29_L_52F0();
  if (flag_z()) goto lab_p29_L_6237;
  set_hl(0x270B);
  a = 0x51;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p29_L_62B3();
  goto lab_p29_L_6246;
  lab_p29_L_6237: ;
  set_hl(0x26F8);
  a = 0x52;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p29_L_62B3();
  lab_p29_L_6246: ;
  cpu_pop_af();
  cpu_push_af();
  p29_L_54A0();
  p29_L_59B3();
  cpu_push_de();
  cpu_push_hl();
  cpu_push_bc();
  cpu_pop_hl();
  p29_L_598E();
  a = mem_read8(0x6385);
  p00_L_3D47();
  cpu_pop_hl();
  p29_L_598E();
  a = mem_read8(0x6385);
  p00_L_3D47();
  cpu_pop_hl();
  p29_L_598E();
  cpu_pop_af();
  cpu_push_af();
  p29_L_52F0();
  if (flag_z()) goto lab_p29_L_629B;
  lab_p29_L_6270: ;
  cpu_pop_af();
  cpu_push_af();
  p29_L_543D();
  if (flag_nz()) goto lab_p29_L_629B;
  set_hl(0x2719);
  a = 0x53;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p29_L_62B3();
  a = mem_read8(0x8478);
  set_hl(0x8478);
  p29_L_650D();
  a = mem_read8(0x8478);
  p00_L_3D47();
  a = mem_read8(0x8479);
  p00_L_3D47();
  lab_p29_L_629B: ;
  cpu_pop_af();
  set_hl(0x273D);
  a = 0x54;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p29_L_62B3();
  /* ei */
  p00_L_3F21();
  p00_L_3837();
  return;
}

/* flash page 29 cpu 0x61CD (offset 0x21CD) */
void p29_L_61CD(void) {
  b = b;
  a = (uint8_t)(a + b);
  os_bcall(0x8075);
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x805A);
  cpu_pop_af();
  cpu_push_af();
  p29_L_5CFF();
  set_hl(0x83A5);
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  mem_write8(hl(), 0x00);
  a = 0x24;
  a = (uint8_t)(a - c);
  l = a;
  h = 0x05;
  mem_write16(0x86D7, hl());
  set_hl(0x83A5);
  p00_L_3D4D();
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p29_L_6201;
  a = 0x50;
  p00_L_3C45();
  if (flag_z()) goto lab_p29_L_620C;
  lab_p29_L_6201: ;
  set_hl(0x636F);
  set_de(0x82A5);
  set_bc(0x0019);
  while (bc() != 0) { cpu_ldi(); }
  lab_p29_L_620C: ;
  set_hl(0x82A5);
  p29_L_62B3();
  set_hl(0x2750);
  p29_L_62B3();
  cpu_pop_af();
  cpu_push_af();
  p29_L_54A0();
  if (flag_nz()) goto lab_p29_L_6270;
  cpu_pop_af();
  cpu_push_af();
  p29_L_52F0();
  if (flag_z()) goto lab_p29_L_6237;
  set_hl(0x270B);
  a = 0x51;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p29_L_62B3();
  goto lab_p29_L_6246;
  lab_p29_L_6237: ;
  set_hl(0x26F8);
  a = 0x52;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p29_L_62B3();
  lab_p29_L_6246: ;
  cpu_pop_af();
  cpu_push_af();
  p29_L_54A0();
  p29_L_59B3();
  cpu_push_de();
  cpu_push_hl();
  cpu_push_bc();
  cpu_pop_hl();
  p29_L_598E();
  a = mem_read8(0x6385);
  p00_L_3D47();
  cpu_pop_hl();
  p29_L_598E();
  a = mem_read8(0x6385);
  p00_L_3D47();
  cpu_pop_hl();
  p29_L_598E();
  cpu_pop_af();
  cpu_push_af();
  p29_L_52F0();
  if (flag_z()) goto lab_p29_L_629B;
  lab_p29_L_6270: ;
  cpu_pop_af();
  cpu_push_af();
  p29_L_543D();
  if (flag_nz()) goto lab_p29_L_629B;
  set_hl(0x2719);
  a = 0x53;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p29_L_62B3();
  a = mem_read8(0x8478);
  set_hl(0x8478);
  p29_L_650D();
  a = mem_read8(0x8478);
  p00_L_3D47();
  a = mem_read8(0x8479);
  p00_L_3D47();
  lab_p29_L_629B: ;
  cpu_pop_af();
  set_hl(0x273D);
  a = 0x54;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p29_L_62B3();
  /* ei */
  p00_L_3F21();
  p00_L_3837();
  return;
}

/* flash page 29 cpu 0x62B3 (offset 0x22B3) */
void p29_L_62B3(void) {
  cpu_push_hl();
  p00_L_0033();
  mem_write16(0x86D7, hl());
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_3D4D();
  return;
}

/* flash page 29 cpu 0x62C1 (offset 0x22C1) */
void p29_L_62C1(void) {
  p00_L_2E65();
  set_hl(0x84BF);
  set_de(0x8479);
  p00_L_1185();
  a = 0;
  flag_logic(a);
  p29_L_6196();
  if (flag_c()) goto lab_p29_L_6345;
  cpu_push_hl();
  cpu_push_af();
  p00_L_1960();
  p00_L_3F09();
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
  cpu_pop_af();
  cpu_push_af();
  p29_L_5E31();
  p29_L_53E5();
  if (flag_nz()) goto lab_p29_L_631D;
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x80A8);
  if (flag_z()) goto lab_p29_L_6305;
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8096);
  if (flag_z()) goto lab_p29_L_6348;
  lab_p29_L_6305: ;
  cpu_pop_af();
  cpu_push_af();
  set_hl(0x4000);
  p29_L_5E59();
  p29_L_52D9();
  if (flag_c()) goto lab_p29_L_6314;
  if (flag_z()) goto lab_p29_L_6348;
  lab_p29_L_6314: ;
  cpu_pop_af();
  cpu_push_af();
  p29_L_5E78();
  if (flag_c()) goto lab_p29_L_6348;
  if (flag_nz()) goto lab_p29_L_6348;
  lab_p29_L_631D: ;
  cpu_pop_af();
  cpu_pop_hl();
  cpu_push_af();
  p29_L_5E31();
  p00_L_0AFB();
  if (flag_z()) goto lab_p29_L_6344;
  os_bcall(0x80A8);
  if (flag_nz()) goto lab_p29_L_6332;
  cpu_pop_af();
  cpu_push_af();
  p29_L_576D();
  lab_p29_L_6332: ;
  cpu_pop_af();
  p29_L_403F();
  p00_L_2E65();
  p00_L_3E8B();
  set_hl(0x0000);
  mem_write16(0x844B, hl());
  goto lab_p29_L_6345;
  lab_p29_L_6344: ;
  cpu_pop_af();
  lab_p29_L_6345: ;
  p00_L_2539();
  return;
  lab_p29_L_6348: ;
  cpu_pop_af();
  mem_write8(0x843E, a);
  p29_L_6FC0();
  if (flag_nz()) { p00_L_2555(); return; }
  p00_L_24A9();
  if (flag_z()) p29_L_6FF9();
  a = mem_read8(0x843E);
  p29_L_5C2D();
  if (flag_z()) goto lab_p29_L_6366;
  a = mem_read8(0x843E);
  p29_L_61BC();
  lab_p29_L_6366: ;
  p29_L_5FDB();
  a = mem_read8(0x843E);
  cpu_pop_hl();
  /* ei */
  return;
}

/* flash page 29 cpu 0x6388 (offset 0x2388) */
void p29_L_6388(void) {
  /* scf */
  goto lab_p29_L_638D;
  lab_p29_L_638D: ;
  cpu_push_af();
  lab_p29_L_638E: ;
  set_de(0x82A3);
  a = mem_read8(de());
  a = (uint8_t)(a - 1);
  mem_write8(de(), a);
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p29_L_639B;
  cpu_pop_af();
  /* scf */
  return;
  lab_p29_L_639B: ;
  a = mem_read8(0x9C87);
  flag_cmp(a, 0x69);
  if (flag_nz()) goto lab_p29_L_63C8;
  a = mem_read8(0x82A3);
  p29_L_7BB5();
  if (flag_z()) goto lab_p29_L_638E;
  a = mem_read8(0x82A3);
  set_hl(0x4000);
  set_de(0x8040);
  os_bcall(0x8075);
  if (flag_z()) goto lab_p29_L_63BF;
  a = 0x01;
  mem_write8(0x9C87, a);
  goto lab_p29_L_638E;
  lab_p29_L_63BF: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(0x82A3);
  os_bcall(0x805A);
  goto lab_p29_L_6407;
  lab_p29_L_63C8: ;
  a = mem_read8(de());
  set_hl(0x4000);
  p00_L_3E31();
  if (flag_nz()) goto lab_p29_L_638E;
  set_de(0x8040);
  a = a | a;
  flag_logic(a);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_638E;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(0x82A3);
  cpu_push_af();
  os_bcall(0x805A);
  cpu_pop_af();
  os_bcall(0x8051);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_638E;
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p29_L_638E;
  a = mem_read8(0x82A3);
  cpu_push_hl();
  cpu_push_bc();
  p29_L_5E31();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x82A3);
  if (flag_nc()) goto lab_p29_L_6402;
  p29_L_53B3();
  goto lab_p29_L_6405;
  lab_p29_L_6402: ;
  p29_L_53E5();
  lab_p29_L_6405: ;
  if (flag_nz()) goto lab_p29_L_638E;
  lab_p29_L_6407: ;
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_bc();
  p00_L_129A();
  cpu_pop_bc();
  cpu_pop_hl();
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_6419;
  a = c;
  e = 0x09;
  a = (uint8_t)(a - e);
  if (flag_c()) goto lab_p29_L_641C;
  lab_p29_L_6419: ;
  set_bc(0x0008);
  lab_p29_L_641C: ;
  set_de(0x8484);
  a = mem_read8(0x82A3);
  os_bcall(0x8054);
  /* scf */
  /* ccf */
  return;
}

/* flash page 29 cpu 0x638B (offset 0x238B) */
void p29_L_638B(void) {
  /* scf */
  /* ccf */
  cpu_push_af();
  lab_p29_L_638E: ;
  set_de(0x82A3);
  a = mem_read8(de());
  a = (uint8_t)(a - 1);
  mem_write8(de(), a);
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p29_L_639B;
  cpu_pop_af();
  /* scf */
  return;
  lab_p29_L_639B: ;
  a = mem_read8(0x9C87);
  flag_cmp(a, 0x69);
  if (flag_nz()) goto lab_p29_L_63C8;
  a = mem_read8(0x82A3);
  p29_L_7BB5();
  if (flag_z()) goto lab_p29_L_638E;
  a = mem_read8(0x82A3);
  set_hl(0x4000);
  set_de(0x8040);
  os_bcall(0x8075);
  if (flag_z()) goto lab_p29_L_63BF;
  a = 0x01;
  mem_write8(0x9C87, a);
  goto lab_p29_L_638E;
  lab_p29_L_63BF: ;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(0x82A3);
  os_bcall(0x805A);
  goto lab_p29_L_6407;
  lab_p29_L_63C8: ;
  a = mem_read8(de());
  set_hl(0x4000);
  p00_L_3E31();
  if (flag_nz()) goto lab_p29_L_638E;
  set_de(0x8040);
  a = a | a;
  flag_logic(a);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_638E;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(0x82A3);
  cpu_push_af();
  os_bcall(0x805A);
  cpu_pop_af();
  os_bcall(0x8051);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_638E;
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p29_L_638E;
  a = mem_read8(0x82A3);
  cpu_push_hl();
  cpu_push_bc();
  p29_L_5E31();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_af();
  a = mem_read8(0x82A3);
  if (flag_nc()) goto lab_p29_L_6402;
  p29_L_53B3();
  goto lab_p29_L_6405;
  lab_p29_L_6402: ;
  p29_L_53E5();
  lab_p29_L_6405: ;
  if (flag_nz()) goto lab_p29_L_638E;
  lab_p29_L_6407: ;
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_bc();
  p00_L_129A();
  cpu_pop_bc();
  cpu_pop_hl();
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_6419;
  a = c;
  e = 0x09;
  a = (uint8_t)(a - e);
  if (flag_c()) goto lab_p29_L_641C;
  lab_p29_L_6419: ;
  set_bc(0x0008);
  lab_p29_L_641C: ;
  set_de(0x8484);
  a = mem_read8(0x82A3);
  os_bcall(0x8054);
  /* scf */
  /* ccf */
  return;
}

/* flash page 29 cpu 0x6428 (offset 0x2428) */
void p29_L_6428(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  p29_L_6186();
  if (flag_c()) goto lab_p29_L_6468;
  mem_write8(0x8433, a);
  p29_L_7CB2();
  if (flag_z()) goto lab_p29_L_6462;
  p29_L_7124();
  if (flag_z()) goto lab_p29_L_644E;
  p00_L_10DD();
  a = 0x14;
  mem_write8(0x8499, a);
  p00_rst18();
  p29_L_5FDB();
  p00_L_2C67();
  goto lab_p29_L_646B;
  lab_p29_L_644E: ;
  set_de(0x0005);
  a = 0x02;
  mem_write8(0x867E, a);
  p00_L_2C4F();
  p00_L_2C6D();
  a = mem_read8(0x8432);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_6468;
  lab_p29_L_6462: ;
  a = mem_read8(0x8433);
  p29_L_403F();
  lab_p29_L_6468: ;
  p29_L_5FDB();
  lab_p29_L_646B: ;
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x646F (offset 0x246F) */
void p29_L_646F(void) {
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_af();
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
  set_hl(0x4000);
  p29_L_4566();
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p29_L_64AE;
  set_hl(0x6000);
  p29_L_4566();
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p29_L_64AE;
  flag_cmp(a, 0x8F);
  if (flag_z()) goto lab_p29_L_64A6;
  set_hl(0x4000);
  p29_L_4566();
  flag_cmp(a, 0x8F);
  if (flag_z()) goto lab_p29_L_64A6;
  lab_p29_L_64A6: ;
  b = 0x00;
  cpu_ex_de_hl();
  p29_L_456D();
  goto lab_p29_L_64CE;
  lab_p29_L_64AE: ;
  a = h;
  a = a ^ 0x20;
  flag_logic(a);
  h = a;
  p29_L_4566();
  flag_cmp(a, 0x8F);
  if (flag_z()) goto lab_p29_L_64C0;
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p29_L_64E1;
  goto lab_p29_L_64CE;
  lab_p29_L_64C0: ;
  cpu_push_hl();
  a = h;
  a = a ^ 0x20;
  flag_logic(a);
  h = a;
  p29_L_457C();
  cpu_pop_de();
  b = 0x00;
  p29_L_456D();
  lab_p29_L_64CE: ;
  cpu_pop_af();
  flag_cmp(a, 0x0F);
  if (flag_nz()) goto lab_p29_L_64D8;
  p00_L_2B8F();
  goto lab_p29_L_64DB;
  lab_p29_L_64D8: ;
  p00_L_2B89();
  lab_p29_L_64DB: ;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  p29_L_5FDB();
  return;
  lab_p29_L_64E1: ;
  set_hl(0x4001);
  set_de(0x6001);
  lab_p29_L_64E7: ;
  p29_L_4566();
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p29_L_64F2;
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p29_L_64F6;
  lab_p29_L_64F2: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  goto lab_p29_L_64E7;
  lab_p29_L_64F6: ;
  a = h;
  a = a ^ 0x20;
  flag_logic(a);
  a = a & 0xF0;
  flag_logic(a);
  h = a;
  a = 0;
  flag_logic(a);
  l = a;
  p29_L_457C();
  goto lab_p29_L_64CE;
}

/* flash page 29 cpu 0x6503 (offset 0x2503) */
void p29_L_6503(void) {
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_650A;
  p29_L_651E();
  lab_p29_L_650A: ;
  a = 0;
  flag_logic(a);
  mem_write8(hl(), a);
  return;
}

/* flash page 29 cpu 0x650D (offset 0x250D) */
void p29_L_650D(void) {
  p00_L_32E5();
  p29_L_6523();
  if (flag_z()) goto lab_p29_L_6519;
  a = (uint8_t)(a + 0x30);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  lab_p29_L_6519: ;
  a = b;
  p29_L_6523();
  if (flag_z()) return;
  p29_L_651E();
  return;
}

/* flash page 29 cpu 0x651E (offset 0x251E) */
void p29_L_651E(void) {
  a = (uint8_t)(a + 0x30);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  return;
}

/* flash page 29 cpu 0x6523 (offset 0x2523) */
void p29_L_6523(void) {
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_6529;
  d = 0x01;
  return;
  lab_p29_L_6529: ;
  e = a;
  a = d;
  a = a | a;
  flag_logic(a);
  a = e;
  return;
}

/* flash page 29 cpu 0x652E (offset 0x252E) */
void p29_L_652E(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  set_hl(mem_read16(0x83A1));
  p29_L_57C5();
  a = a | a;
  flag_logic(a);
  /* adc hl,de */
  p29_L_57C5();
  mem_write16(0x83A1, hl());
  if (flag_nc()) goto lab_p29_L_654C;
  set_hl(mem_read16(0x839F));
  h = (uint8_t)(h + 1);
  if (flag_nz()) goto lab_p29_L_6549;
  l = (uint8_t)(l + 1);
  lab_p29_L_6549: ;
  mem_write16(0x839F, hl());
  lab_p29_L_654C: ;
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x6550 (offset 0x2550) */
void p29_L_6550(void) {
  cpu_push_de();
  set_de(0x0001);
  p29_L_6559();
  cpu_pop_de();
  return;
}

/* flash page 29 cpu 0x6559 (offset 0x2559) */
void p29_L_6559(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_de();
  cpu_ex_de_hl();
  set_de(0x4000);
  os_bcall(0x804B);
  a = mem_read8(0x986B);
  a = (uint8_t)(a + e);
  mem_write8(0x986B, a);
  a = e;
  set_de(0x4000);
  os_bcall(0x8045);
  cpu_push_hl();
  cpu_pop_bc();
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  set_hl(mem_read16(0x986C));
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_z()) goto lab_p29_L_6591;
  a = mem_read8(0x986B);
  a = (uint8_t)(a + 1);
  mem_write8(0x986B, a);
  set_bc(0x4000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  lab_p29_L_6591: ;
  mem_write16(0x986C, hl());
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x6598 (offset 0x2598) */
void p29_L_6598(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x986B);
  goto lab_p29_L_65A6;
  lab_p29_L_65A6: ;
  a = 0;
  flag_logic(a);
  b = 0x04;
  lab_p29_L_65A9: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_65A9;
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x65A0 (offset 0x25A0) */
void p29_L_65A0(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x839F);
  a = 0;
  flag_logic(a);
  b = 0x04;
  lab_p29_L_65A9: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_65A9;
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x65B1 (offset 0x25B1) */
void p29_L_65B1(void) {
  cpu_push_af();
  cpu_push_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p29_L_65F2;
  p29_L_65A0();
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
  p29_L_6EDB();
  p29_L_5FDB();
  mem_write8(0x83EB, a);
  cpu_pop_af();
  if (flag_po()) goto lab_p29_L_65E5;
  /* ei */
  lab_p29_L_65E5: ;
  a = mem_read8(0x83EB);
  set_de(0x9C96);
  p29_L_6621();
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) | (1u << 6)));
  lab_p29_L_65F2: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p29_L_6608;
  p29_L_65A0();
  p29_L_662F();
  set_de(0x9C9A);
  p29_L_6621();
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) | (1u << 7)));
  lab_p29_L_6608: ;
  set_hl(0x9C9A);
  p29_L_6626();
  set_de(0x83A2);
  set_hl(0x9C99);
  b = 0x04;
  a = a | a;
  flag_logic(a);
  lab_p29_L_6617: ;
  a = mem_read8(de());
  /* adc a,(hl) */
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() - 1));
  set_de((uint16_t)(de() - 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_6617;
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x6621 (offset 0x2621) */
void p29_L_6621(void) {
  set_hl(0x839F);
  goto lab_p29_L_6629;
  lab_p29_L_6629: ;
  set_bc(0x0004);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 29 cpu 0x6626 (offset 0x2626) */
void p29_L_6626(void) {
  set_de(0x839F);
  set_bc(0x0004);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 29 cpu 0x662F (offset 0x262F) */
void p29_L_662F(void) {
  p29_L_6800();
  b = (uint8_t)(b + 1);
  a = 0x08;
  set_de(0x0000);
  lab_p29_L_6638: ;
  p29_L_7BD4();
  flag_cmp(a, b);
  if (flag_nc()) return;
  set_hl(0x4000);
  cpu_push_af();
  p29_L_6B36();
  flag_cmp(a, 0xFE);
  if (flag_z()) goto lab_p29_L_6664;
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p29_L_665C;
  cpu_pop_af();
  cpu_push_af();
  p29_L_673D();
  p29_L_652E();
  set_de(0x0001);
  p29_L_652E();
  goto lab_p29_L_6664;
  lab_p29_L_665C: ;
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p29_L_6669;
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  goto lab_p29_L_6638;
  lab_p29_L_6664: ;
  cpu_pop_af();
  a = (uint8_t)(a + 0x04);
  goto lab_p29_L_6638;
  lab_p29_L_6669: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  lab_p29_L_666C: ;
  cpu_push_af();
  cpu_push_hl();
  c = 0xF0;
  cpu_push_bc();
  p29_L_6769();
  cpu_push_bc();
  cpu_pop_de();
  cpu_pop_bc();
  if (flag_z()) goto lab_p29_L_6696;
  sp = (uint16_t)(sp + 1);
  sp = (uint16_t)(sp + 1);
  sp = (uint16_t)(sp + 1);
  sp = (uint16_t)(sp + 1);
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  p29_L_6559();
  cpu_pop_de();
  p29_L_652E();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  goto lab_p29_L_666C;
  lab_p29_L_6696: ;
  cpu_pop_hl();
  cpu_pop_af();
  c = 0xFF;
  cpu_push_bc();
  p29_L_6769();
  cpu_pop_bc();
  if (flag_z()) goto lab_p29_L_66A7;
  p29_L_673D();
  p29_L_652E();
  lab_p29_L_66A7: ;
  goto lab_p29_L_6664;
}

/* flash page 29 cpu 0x66A9 (offset 0x26A9) */
void p29_L_66A9(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_hl();
  set_bc(mem_read16(0x9869));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p29_L_66BB;
  a = a | a;
  flag_logic(a);
  /* adc hl,bc */
  mem_write16(0x9869, hl());
  lab_p29_L_66BB: ;
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x66BF (offset 0x26BF) */
void p29_L_66BF(void) {
  cpu_push_bc();
  cpu_push_de();
  a = mem_read8(0x8478);
  cpu_push_af();
  cpu_push_bc();
  set_bc(0x0000);
  mem_write16(0x9869, bc());
  p29_L_66CD();
  return;
}

/* flash page 29 cpu 0x66CD (offset 0x26CD) */
void p29_L_66CD(void) {
  p29_L_6800();
  a = b;
  mem_write8(0x83FF, a);
  cpu_pop_bc();
  a = 0x08;
  lab_p29_L_66D7: ;
  cpu_push_af();
  set_hl(0x4000);
  p29_L_6B36();
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p29_L_66E7;
  lab_p29_L_66E2: ;
  cpu_pop_af();
  a = (uint8_t)(a + 0x03);
  goto lab_p29_L_66F0;
  lab_p29_L_66E7: ;
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p29_L_66FB;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p29_L_6711;
  cpu_pop_af();
  lab_p29_L_66F0: ;
  cpu_push_hl();
  set_hl(0x83FF);
  cpu_cp_hl();
  cpu_pop_hl();
  if (flag_nc()) goto lab_p29_L_672F;
  a = (uint8_t)(a + 1);
  goto lab_p29_L_66D7;
  lab_p29_L_66FB: ;
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  c = 0xFF;
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  p29_L_6550();
  p29_L_6769();
  cpu_pop_bc();
  if (flag_z()) goto lab_p29_L_66E2;
  cpu_pop_de();
  cpu_push_af();
  lab_p29_L_6711: ;
  cpu_pop_af();
  mem_write16(0x82A5, hl());
  cpu_push_bc();
  cpu_push_af();
  a = mem_read8(0x83FF);
  b = a;
  b = (uint8_t)(b + 1);
  cpu_pop_af();
  p29_L_673D();
  cpu_ex_de_hl();
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  p29_L_66A9();
  cpu_sbc_hl_bc();
  set_hl(mem_read16(0x82A5));
  if (flag_nc()) goto lab_p29_L_6733;
  goto lab_p29_L_66F0;
  lab_p29_L_672F: ;
  a = 0xFF;
  a = (uint8_t)(a + 0x10);
  lab_p29_L_6733: ;
  cpu_pop_bc();
  c = a;
  a = b;
  mem_write8(0x8478, a);
  a = c;
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x673D (offset 0x273D) */
void p29_L_673D(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_af();
  cpu_push_hl();
  cpu_pop_de();
  set_hl(0x7FFF);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  lab_p29_L_6748: ;
  cpu_ex_de_hl();
  a = (uint8_t)(a + 1);
  p29_L_67EC();
  if (flag_z()) goto lab_p29_L_6765;
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p29_L_6765;
  set_hl(0x4000);
  cpu_push_af();
  p29_L_6B36();
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p29_L_6764;
  set_hl(0x4000);
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_af();
  goto lab_p29_L_6748;
  lab_p29_L_6764: ;
  cpu_pop_af();
  lab_p29_L_6765: ;
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x6769 (offset 0x2769) */
void p29_L_6769(void) {
  p29_L_6598();
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_af();
  a = a | 0x03;
  flag_logic(a);
  b = 0x15;
  p00_L_24A9();
  if (flag_nz()) goto lab_p29_L_6780;
  b = 0x69;
  lab_p29_L_6780: ;
  flag_cmp(a, b);
  if (flag_c()) goto lab_p29_L_6784;
  a = b;
  lab_p29_L_6784: ;
  mem_write8(0x8390, a);
  cpu_pop_af();
  cpu_pop_hl();
  cpu_pop_bc();
  lab_p29_L_678A: ;
  cpu_push_bc();
  a = mem_read8(0x986B);
  p29_L_6B36();
  flag_cmp(a, c);
  if (flag_z()) goto lab_p29_L_67C8;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p29_L_67C2;
  mem_write16(0x986C, hl());
  p29_L_6550();
  a = mem_read8(0x986B);
  p29_L_6B36();
  e = a;
  p29_L_6550();
  a = mem_read8(0x986B);
  p29_L_6B36();
  d = a;
  set_de((uint16_t)(de() + 1));
  p29_L_6559();
  a = mem_read8(0x8390);
  b = a;
  a = mem_read8(0x986B);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p29_L_67BF;
  if (flag_nz()) goto lab_p29_L_67C2;
  lab_p29_L_67BF: ;
  cpu_pop_bc();
  goto lab_p29_L_678A;
  lab_p29_L_67C2: ;
  a = 0;
  flag_logic(a);
  a = mem_read8(0x986B);
  cpu_pop_bc();
  return;
  lab_p29_L_67C8: ;
  cpu_pop_bc();
  a = mem_read8(0x986B);
  cpu_push_af();
  cpu_push_hl();
  mem_write16(0x986C, hl());
  p29_L_6550();
  a = mem_read8(0x986B);
  p29_L_6B36();
  c = a;
  a = mem_read8(0x986B);
  p29_L_6550();
  a = mem_read8(0x986B);
  p29_L_6B36();
  b = a;
  cpu_pop_hl();
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 29 cpu 0x67EC (offset 0x27EC) */
void p29_L_67EC(void) {
  cpu_push_bc();
  b = a;
  a = a & 0x03;
  flag_logic(a);
  a = b;
  if (flag_z()) goto lab_p29_L_67FE;
  p00_L_24A9();
  if (flag_nz()) goto lab_p29_L_67FC;
  flag_cmp(a, 0x6A);
  goto lab_p29_L_67FE;
  lab_p29_L_67FC: ;
  flag_cmp(a, 0x16);
  lab_p29_L_67FE: ;
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x6800 (offset 0x2800) */
void p29_L_6800(void) {
  cpu_push_af();
  cpu_push_hl();
  cpu_push_de();
  p29_L_75EC();
  set_hl(0x4000);
  lab_p29_L_6809: ;
  cpu_push_af();
  p29_L_6B36();
  flag_cmp(a, 0x80);
  if (flag_z()) goto lab_p29_L_6815;
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p29_L_6827;
  lab_p29_L_6815: ;
  cpu_pop_af();
  cpu_push_af();
  p00_L_3E31();
  if (flag_nz()) goto lab_p29_L_6827;
  p29_L_4A3F();
  a = c;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_6827;
  cpu_pop_af();
  a = (uint8_t)(a - c);
  goto lab_p29_L_6809;
  lab_p29_L_6827: ;
  cpu_pop_af();
  b = a;
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x682D (offset 0x282D) */
void p29_L_682D(void) {
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 7)));
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
  a = mem_read8(0x83EE);
  set_hl(mem_read16(0x83EF));
  p29_L_69E8();
  set_de(mem_read16(0x83F3));
  set_bc(mem_read16(0x83F9));
  p29_L_6F54();
  if (flag_c()) { p00_L_2541(); return; }
  os_bcall(0x8054);
  set_de(mem_read16(0x83EF));
  a = mem_read8(0x83EE);
  b = 0xF0;
  os_bcall(0x8021);
  set_de(mem_read16(0x83F3));
  mem_write16(0x83EF, de());
  a = 0x00;
  mem_write8(0x83EE, a);
  set_hl(mem_read16(0x83F1));
  p00_L_2EDD();
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x687E (offset 0x287E) */
void p29_L_687E(void) {
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 7)));
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
  cpu_ex_de_hl();
  p29_L_692E();
  return;
}

/* flash page 29 cpu 0x6897 (offset 0x2897) */
void p29_L_6897(void) {
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 7)));
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
  a = mem_read8(0x83EE);
  set_hl(mem_read16(0x83EF));
  p29_L_69D4();
  if (flag_nz()) goto lab_p29_L_68D2;
  b = 0xF0;
  a = mem_read8(0x83EE);
  set_de(mem_read16(0x83EF));
  p29_L_6F82();
  if (flag_c()) { p00_L_2541(); return; }
  os_bcall(0x8021);
  set_hl(mem_read16(0x83EF));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x83EF, hl());
  goto lab_p29_L_68D6;
  lab_p29_L_68D2: ;
  set_de(mem_read16(0x83EF));
  lab_p29_L_68D6: ;
  b = 0xFE;
  a = mem_read8(0x83EE);
  mem_write8(0x8404, a);
  mem_write16(0x8402, de());
  p29_L_6F82();
  if (flag_c()) { p00_L_2541(); return; }
  os_bcall(0x8021);
  a = mem_read8(0x83EE);
  set_de(mem_read16(0x8402));
  mem_write8(0x986B, a);
  mem_write16(0x986C, de());
  p29_L_6550();
  a = mem_read8(0x986B);
  set_de(mem_read16(0x986C));
  set_hl(0x83F9);
  set_bc(0x0002);
  p29_L_6F54();
  if (flag_c()) { p00_L_2541(); return; }
  os_bcall(0x8087);
  set_de(0x0002);
  p29_L_6559();
  a = mem_read8(0x8404);
  mem_write8(0x83EE, a);
  set_de(mem_read16(0x986C));
  set_hl(mem_read16(0x83F1));
  p00_L_2EDD();
  a = mem_read8(0x986B);
  mem_write8(0x83EE, a);
  p29_L_692E();
  return;
}

/* flash page 29 cpu 0x692E (offset 0x292E) */
void p29_L_692E(void) {
  set_hl(mem_read16(0x83F1));
  set_bc(mem_read16(0x83F5));
  cpu_push_de();
  set_de(0x8478);
  b = c;
  lab_p29_L_693A: ;
  a = mem_read8(hl());
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() - 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_693A;
  cpu_pop_de();
  a = mem_read8(0x83EE);
  set_bc(mem_read16(0x83F5));
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 7)));
  mem_write16(0x986C, de());
  mem_write8(0x986B, a);
  p29_L_6F54();
  if (flag_c()) { p00_L_2541(); return; }
  os_bcall(0x8087);
  set_de(mem_read16(0x83F5));
  p29_L_6559();
  a = mem_read8(0x986B);
  mem_write8(0x83EE, a);
  set_de(mem_read16(0x986C));
  mem_write16(0x83FB, de());
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 3)) == 0);
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 3)));
  if (flag_nz()) goto lab_p29_L_69D1;
  a = mem_read8(0x83EE);
  set_hl(mem_read16(0x83F3));
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 5)) == 0);
  set_bc(0x0002);
  if (flag_nz()) goto lab_p29_L_698F;
  set_bc(mem_read16(0x83F7));
  lab_p29_L_698F: ;
  mem_write16(0x986C, de());
  mem_write8(0x986B, a);
  p29_L_6F54();
  if (flag_c()) { p00_L_2541(); return; }
  p29_L_7666();
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 5)) == 0);
  set_de(0x0002);
  if (flag_nz()) goto lab_p29_L_69AC;
  set_de(mem_read16(0x83F7));
  lab_p29_L_69AC: ;
  p29_L_6559();
  a = mem_read8(0x986B);
  mem_write8(0x83EE, a);
  set_de(mem_read16(0x986C));
  flag_set_z((mem_read8((uint16_t)(iy + 0x26)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p29_L_69D1;
  set_de(mem_read16(0x8402));
  b = 0xFC;
  a = mem_read8(0x8404);
  p29_L_6F82();
  if (flag_c()) { p00_L_2541(); return; }
  os_bcall(0x8021);
  lab_p29_L_69D1: ;
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x69CD (offset 0x29CD) */
void p29_L_69CD(void) {
  h = (uint8_t)(h - 1);
  os_bcall(0x8021);
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x69D4 (offset 0x29D4) */
void p29_L_69D4(void) {
  cpu_push_hl();
  set_bc(0x4000);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_pop_hl();
  if (flag_z()) goto lab_p29_L_69DF;
  if (flag_nc()) return;
  lab_p29_L_69DF: ;
  b = a;
  a = a & 0x03;
  flag_logic(a);
  a = b;
  return;
}

/* flash page 29 cpu 0x69E4 (offset 0x29E4) */
void p29_L_69E4(void) {
  p29_L_69E8();
  return;
}

/* flash page 29 cpu 0x69E8 (offset 0x29E8) */
void p29_L_69E8(void) {
  p29_L_6A07();
  cpu_push_af();
  cpu_push_hl();
  cpu_push_af();
  p29_L_6B36();
  e = a;
  cpu_pop_af();
  set_hl((uint16_t)(hl() + 1));
  p00_L_23FC();
  if (flag_nc()) goto lab_p29_L_69FA;
  a = (uint8_t)(a + 1);
  lab_p29_L_69FA: ;
  p29_L_6B36();
  d = a;
  cpu_push_de();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x6A03 (offset 0x2A03) */
void p29_L_6A03(void) {
  p29_L_6A07();
  return;
}

/* flash page 29 cpu 0x6A07 (offset 0x2A07) */
void p29_L_6A07(void) {
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_23FC();
  if (flag_nc()) { p29_L_6A10(); return; }
  a = (uint8_t)(a + 1);
  p29_L_6A10();
  return;
}

/* flash page 29 cpu 0x6A10 (offset 0x2A10) */
void p29_L_6A10(void) {
  cpu_push_af();
  p29_L_6B36();
  a = a & 0x1F;
  flag_logic(a);
  a = a | a;
  flag_logic(a);
  p00_L_23F6();
  if (flag_nc()) goto lab_p29_L_6A21;
  d = a;
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  cpu_push_af();
  a = d;
  lab_p29_L_6A21: ;
  set_de(0x0003);
  p00_L_17B3();
  if (flag_z()) goto lab_p29_L_6A3D;
  p00_L_1830();
  if (flag_z()) goto lab_p29_L_6A3D;
  cpu_pop_af();
  mem_write8(0x986B, a);
  p29_L_6B36();
  flag_cmp(a, 0x5D);
  a = mem_read8(0x986B);
  if (flag_nz()) goto lab_p29_L_6A45;
  cpu_push_af();
  lab_p29_L_6A3D: ;
  cpu_pop_af();
  cpu_push_af();
  p29_L_6B36();
  e = a;
  cpu_pop_af();
  e = (uint8_t)(e + 1);
  lab_p29_L_6A45: ;
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  p29_L_6559();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  return;
}

/* flash page 29 cpu 0x6A55 (offset 0x2A55) */
void p29_L_6A55(void) {
  p29_L_6800();
  p29_L_75EC();
  flag_cmp(a, b);
  if (flag_c()) goto lab_p29_L_6A6D;
  if (flag_z()) goto lab_p29_L_6A6D;
  lab_p29_L_6A60: ;
  cpu_push_bc();
  p29_L_4022();
  cpu_pop_bc();
  a = mem_read8(0x82A4);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p29_L_6A6D;
  if (flag_nz()) goto lab_p29_L_6A60;
  lab_p29_L_6A6D: ;
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 2)));
  a = 0x04;
  p00_L_2EB9();
  return;
}

/* flash page 29 cpu 0x6A77 (offset 0x2A77) */
void p29_L_6A77(void) {
  p00_L_3F2D();
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
  a = 0x08;
  os_bcall(0x8084);
  a = 0x08;
  set_de(0x4000);
  b = 0xFE;
  os_bcall(0x8021);
  a = 0x0C;
  lab_p29_L_6A9C: ;
  cpu_push_af();
  p29_L_7BD4();
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8084);
  cpu_pop_af();
  a = (uint8_t)(a + 0x04);
  p29_L_75E1();
  if (flag_c()) goto lab_p29_L_6A9C;
  set_hl(0x82A5);
  b = 0xE8;
  lab_p29_L_6AB2: ;
  a = 0xFF;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_6AB2;
  a = 0xFE;
  set_hl(0x836D);
  mem_write8(hl(), a);
  p00_L_24A9();
  if (flag_z()) goto lab_p29_L_6AC9;
  a = 0x7F;
  set_hl(0x836E);
  mem_write8(hl(), a);
  lab_p29_L_6AC9: ;
  a = 0x00;
  p29_L_40CC();
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x6AD1 (offset 0x2AD1) */
void p29_L_6AD1(void) {
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) & ~(1u << 4)));
  a = 0x08;
  lab_p29_L_6ADF: ;
  cpu_push_af();
  set_hl(0x4000);
  p29_L_6B36();
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p29_L_6AF3;
  lab_p29_L_6AEA: ;
  cpu_pop_af();
  cpu_push_bc();
  c = 0x03;
  a = (uint8_t)(a + c);
  cpu_pop_bc();
  cpu_push_af();
  goto lab_p29_L_6AFB;
  lab_p29_L_6AF3: ;
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p29_L_6B07;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p29_L_6AEA;
  lab_p29_L_6AFB: ;
  cpu_pop_af();
  cpu_push_hl();
  p29_L_6800();
  flag_cmp(a, b);
  cpu_pop_hl();
  if (flag_nc()) goto lab_p29_L_6B35;
  a = (uint8_t)(a + 1);
  goto lab_p29_L_6ADF;
  lab_p29_L_6B07: ;
  cpu_pop_af();
  cpu_push_af();
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  p29_L_6550();
  lab_p29_L_6B12: ;
  c = 0xFC;
  p29_L_6769();
  if (flag_z()) goto lab_p29_L_6AEA;
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  cpu_push_bc();
  p00_L_2FC7();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  set_de((uint16_t)(de() + 1));
  p29_L_6559();
  a = mem_read8(0x986B);
  goto lab_p29_L_6B12;
  lab_p29_L_6B35: ;
  return;
}

/* flash page 29 cpu 0x6B36 (offset 0x2B36) */
void p29_L_6B36(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  set_bc(0x0001);
  set_de(0x9867);
  p29_L_6B49();
  a = mem_read8(0x9867);
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x6B49 (offset 0x2B49) */
void p29_L_6B49(void) {
  p00_L_24A9();
  if (flag_z()) goto lab_p29_L_6B50;
  a = a & 0x1F;
  flag_logic(a);
  lab_p29_L_6B50: ;
  cpu_push16(ix);
  ix = 0x6B5C;
  p29_L_6B87();
  ix = cpu_pop16();
  return;
}

/* flash page 29 cpu 0x6B87 (offset 0x2B87) */
void p29_L_6B87(void) {
  p29_L_6BB0();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  cpu_push16(ix);
  cpu_pop_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  set_de(0x8100);
  cpu_push_de();
  while (bc() != 0) { cpu_ldi(); }
  ix = cpu_pop16();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  p29_L_6BAD();
  cpu_push_af();
  a = mem_read8(0x82A2);
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_z()) goto lab_p29_L_6BAB;
  /* ei */
  lab_p29_L_6BAB: ;
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x6BAD (offset 0x2BAD) */
void p29_L_6BAD(void) {
  os_banked_call(0x8100);
  return;
}

/* flash page 29 cpu 0x6BB0 (offset 0x2BB0) */
void p29_L_6BB0(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_ld_a_i();
  cpu_push_af();
  /* di */
  cpu_pop_bc();
  a = c;
  mem_write8(0x82A2, a);
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x6BBE (offset 0x2BBE) */
void p29_L_6BBE(void) {
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 7)));
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
  a = b;
  b = 0xF0;
  p29_L_6F82();
  if (flag_c()) { p00_L_2541(); return; }
  os_bcall(0x8021);
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x6BE2 (offset 0x2BE2) */
void p29_L_6BE2(void) {
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 7)));
  a = 0x08;
  lab_p29_L_6BE8: ;
  cpu_push_af();
  set_hl(0x4000);
  p29_L_6B36();
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p29_L_6BF9;
  lab_p29_L_6BF3: ;
  cpu_pop_af();
  a = (uint8_t)(a + 0x03);
  cpu_push_af();
  goto lab_p29_L_6C01;
  lab_p29_L_6BF9: ;
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p29_L_6C0E;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p29_L_6BF3;
  lab_p29_L_6C01: ;
  cpu_pop_af();
  cpu_push_hl();
  p29_L_6800();
  flag_cmp(a, b);
  cpu_pop_hl();
  if (flag_nc()) goto lab_p29_L_6CAB;
  a = (uint8_t)(a + 1);
  goto lab_p29_L_6BE8;
  lab_p29_L_6C0E: ;
  cpu_pop_af();
  cpu_push_af();
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  p29_L_6550();
  p29_L_6C19();
  return;
  lab_p29_L_6CAB: ;
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 2)));
  a = 0x03;
  p00_L_2EB9();
  return;
}

/* flash page 29 cpu 0x6C19 (offset 0x2C19) */
void p29_L_6C19(void) {
  goto lab_p29_L_6C19;
  lab_p29_L_6BE8: ;
  cpu_push_af();
  set_hl(0x4000);
  p29_L_6B36();
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p29_L_6BF9;
  lab_p29_L_6BF3: ;
  cpu_pop_af();
  a = (uint8_t)(a + 0x03);
  cpu_push_af();
  goto lab_p29_L_6C01;
  lab_p29_L_6BF9: ;
  flag_cmp(a, 0xF0);
  if (flag_z()) goto lab_p29_L_6C0E;
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p29_L_6BF3;
  lab_p29_L_6C01: ;
  cpu_pop_af();
  cpu_push_hl();
  p29_L_6800();
  flag_cmp(a, b);
  cpu_pop_hl();
  if (flag_nc()) goto lab_p29_L_6CAB;
  a = (uint8_t)(a + 1);
  goto lab_p29_L_6BE8;
  lab_p29_L_6C0E: ;
  cpu_pop_af();
  cpu_push_af();
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  p29_L_6550();
  lab_p29_L_6C19: ;
  c = 0xFC;
  p29_L_6769();
  if (flag_z()) goto lab_p29_L_6BF3;
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  mem_write8(0x8404, a);
  mem_write16(0x8402, hl());
  set_de(0x0003);
  p29_L_6559();
  a = mem_read8(0x986B);
  cpu_push_bc();
  cpu_push_af();
  p29_L_6B36();
  a = a & 0x1F;
  flag_logic(a);
  mem_write8(0x8478, a);
  p00_L_17B3();
  if (flag_z()) goto lab_p29_L_6C49;
  p00_L_1830();
  if (flag_nz()) goto lab_p29_L_6C6A;
  lab_p29_L_6C49: ;
  a = a | a;
  flag_logic(a);
  p00_L_23F6();
  if (flag_nc()) goto lab_p29_L_6C52;
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  cpu_push_af();
  lab_p29_L_6C52: ;
  cpu_pop_af();
  cpu_push_af();
  p29_L_6B36();
  c = a;
  b = 0x00;
  cpu_pop_af();
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  p29_L_6550();
  a = mem_read8(0x986B);
  cpu_push_af();
  goto lab_p29_L_6C76;
  lab_p29_L_6C6A: ;
  a = a | a;
  flag_logic(a);
  p00_L_23F6();
  if (flag_nc()) goto lab_p29_L_6C73;
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  cpu_push_af();
  lab_p29_L_6C73: ;
  set_bc(0x0003);
  lab_p29_L_6C76: ;
  set_de(0x8479);
  cpu_push_hl();
  a = mem_read8(0x8478);
  cpu_push_af();
  p00_L_1295();
  cpu_pop_af();
  mem_write8(0x8478, a);
  cpu_pop_hl();
  cpu_pop_af();
  p29_L_6B49();
  p00_L_19ED();
  p00_L_1F31();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  a = mem_read8(0x8404);
  set_hl(mem_read16(0x8402));
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  p29_L_6559();
  p29_L_6550();
  a = mem_read8(0x986B);
  goto lab_p29_L_6C19;
  lab_p29_L_6CAB: ;
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 2)));
  a = 0x03;
  p00_L_2EB9();
  return;
}

/* flash page 29 cpu 0x6CB5 (offset 0x2CB5) */
void p29_L_6CB5(void) {
  set_hl(0x8697);
  p00_L_24A9();
  if (flag_z()) goto lab_p29_L_6CC4;
  c = a;
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  return;
  lab_p29_L_6CC4: ;
  b = a;
  p00_L_2DB1();
  /* or (hl) */
  mem_write8(hl(), a);
  return;
}

/* flash page 29 cpu 0x6CCB (offset 0x2CCB) */
void p29_L_6CCB(void) {
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  set_de(0x0003);
  p29_L_6559();
  p00_L_1295();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  p29_L_6B36();
  mem_write8(0x8478, a);
  p00_L_23F6();
  if (flag_nc()) goto lab_p29_L_6CF2;
  a = mem_read8(0x986B);
  a = (uint8_t)(a + 1);
  mem_write8(0x986B, a);
  lab_p29_L_6CF2: ;
  mem_write16(0x986C, hl());
  a = mem_read8(0x8478);
  b = 0x03;
  p00_L_17B3();
  if (flag_z()) goto lab_p29_L_6D11;
  p00_L_1830();
  if (flag_z()) goto lab_p29_L_6D11;
  a = mem_read8(0x986B);
  p29_L_6B36();
  flag_cmp(a, 0x5D);
  a = mem_read8(0x986B);
  if (flag_nz()) goto lab_p29_L_6D21;
  lab_p29_L_6D11: ;
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  p29_L_6B36();
  b = a;
  a = mem_read8(0x986B);
  p29_L_6550();
  lab_p29_L_6D21: ;
  set_de(0x8479);
  lab_p29_L_6D24: ;
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  cpu_push_bc();
  p29_L_6B36();
  cpu_pop_bc();
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  p29_L_6550();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_6D24;
  return;
}

/* flash page 29 cpu 0x6D37 (offset 0x2D37) */
void p29_L_6D37(void) {
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_de();
  cpu_push_af();
  mem_write8(0x83EE, a);
  mem_write16(0x83EF, hl());
  a = b;
  mem_write8(0x83F1, a);
  mem_write16(0x83F2, de());
  mem_write8(0x8404, a);
  mem_write16(0x8402, de());
  a = mem_read8(0x83EE);
  set_hl(mem_read16(0x83EF));
  p29_L_6CCB();
  a = mem_read8(0x8478);
  a = a & 0x1F;
  flag_logic(a);
  cpu_push_af();
  a = mem_read8(0x83EE);
  set_hl(mem_read16(0x83EF));
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  p29_L_6550();
  a = mem_read8(0x986B);
  p29_L_6B36();
  c = a;
  p29_L_6550();
  a = mem_read8(0x986B);
  p29_L_6B36();
  b = a;
  p29_L_6550();
  cpu_push_bc();
  a = mem_read8(0x986B);
  mem_write8(0x83EE, a);
  mem_write16(0x83EF, hl());
  a = mem_read8(0x83F1);
  set_de(mem_read16(0x83F2));
  mem_write8(0x986B, a);
  mem_write16(0x986C, de());
  b = 0xFE;
  os_bcall(0x8021);
  p29_L_6550();
  a = mem_read8(0x986B);
  set_de(mem_read16(0x986C));
  cpu_pop_bc();
  cpu_push_bc();
  b = c;
  os_bcall(0x8021);
  p29_L_6550();
  a = mem_read8(0x986B);
  set_de(mem_read16(0x986C));
  cpu_pop_bc();
  cpu_push_bc();
  os_bcall(0x8021);
  p29_L_6550();
  a = mem_read8(0x986B);
  set_de(mem_read16(0x986C));
  mem_write8(0x83F1, a);
  mem_write16(0x83F2, de());
  a = mem_read8(0x83EE);
  set_hl(mem_read16(0x83EF));
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  set_de(0x83FD);
  set_bc(0x0003);
  p29_L_6B49();
  set_de(0x0006);
  p29_L_6559();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  mem_write8(0x83EE, a);
  mem_write16(0x83EF, hl());
  a = mem_read8(0x83F1);
  set_de(mem_read16(0x83F2));
  mem_write8(0x986B, a);
  mem_write16(0x986C, de());
  set_hl(0x83FD);
  set_bc(0x0003);
  os_bcall(0x8087);
  set_de(0x0003);
  p29_L_6559();
  a = mem_read8(0x986B);
  set_de(mem_read16(0x986C));
  set_hl(0x8402);
  set_bc(0x0003);
  os_bcall(0x8087);
  set_de(0x0003);
  p29_L_6559();
  a = mem_read8(0x986B);
  set_de(mem_read16(0x986C));
  mem_write8(0x83F1, a);
  mem_write16(0x83F2, de());
  cpu_pop_hl();
  set_bc(0x0006);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  p29_L_6E40();
  return;
}

/* flash page 29 cpu 0x6DCD (offset 0x2DCD) */
void p29_L_6DCD(void) {
  if (flag_p()) { p00_L_3A83(); return; }
  a = a ^ 0x83;
  flag_logic(a);
  set_hl(mem_read16(0x83EF));
  mem_write8(0x986B, a);
  mem_write16(0x986C, hl());
  set_de(0x83FD);
  set_bc(0x0003);
  p29_L_6B49();
  set_de(0x0006);
  p29_L_6559();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  mem_write8(0x83EE, a);
  mem_write16(0x83EF, hl());
  a = mem_read8(0x83F1);
  set_de(mem_read16(0x83F2));
  mem_write8(0x986B, a);
  mem_write16(0x986C, de());
  set_hl(0x83FD);
  set_bc(0x0003);
  os_bcall(0x8087);
  set_de(0x0003);
  p29_L_6559();
  a = mem_read8(0x986B);
  set_de(mem_read16(0x986C));
  set_hl(0x8402);
  set_bc(0x0003);
  os_bcall(0x8087);
  set_de(0x0003);
  p29_L_6559();
  a = mem_read8(0x986B);
  set_de(mem_read16(0x986C));
  mem_write8(0x83F1, a);
  mem_write16(0x83F2, de());
  cpu_pop_hl();
  set_bc(0x0006);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  p29_L_6E40();
  return;
}

/* flash page 29 cpu 0x6E40 (offset 0x2E40) */
void p29_L_6E40(void) {
  lab_p29_L_6E40: ;
  set_hl(0x0000);
  mem_write16(0x83F4, hl());
  set_de(0x8000);
  lab_p29_L_6E49: ;
  cpu_push_bc();
  a = mem_read8(0x83EE);
  b = a;
  set_hl(mem_read16(0x83EF));
  p00_L_01E3();
  a = c;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_z()) goto lab_p29_L_6E60;
  b = (uint8_t)(b + 1);
  set_hl(0x4000);
  lab_p29_L_6E60: ;
  p29_L_6ECE();
  a = b;
  mem_write8(0x83EE, a);
  mem_write16(0x83EF, hl());
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_6EA7;
  p29_L_6ED5();
  if (flag_z()) goto lab_p29_L_6E77;
  goto lab_p29_L_6E49;
  lab_p29_L_6E77: ;
  cpu_push_bc();
  set_hl(0x8000);
  set_de(mem_read16(0x83F2));
  a = mem_read8(0x83F1);
  mem_write16(0x986C, de());
  mem_write8(0x986B, a);
  set_bc(mem_read16(0x83F4));
  os_bcall(0x8087);
  set_de(mem_read16(0x83F4));
  p29_L_6559();
  a = mem_read8(0x986B);
  set_hl(mem_read16(0x986C));
  mem_write8(0x83F1, a);
  mem_write16(0x83F2, hl());
  cpu_pop_bc();
  goto lab_p29_L_6E40;
  lab_p29_L_6EA7: ;
  set_hl(0x8000);
  set_de(mem_read16(0x83F2));
  a = mem_read8(0x83F1);
  set_bc(mem_read16(0x83F4));
  os_bcall(0x8087);
  a = mem_read8(0x8404);
  set_de(mem_read16(0x8402));
  b = 0xFC;
  os_bcall(0x8021);
  cpu_pop_af();
  mem_write8(0x8478, a);
  cpu_pop_af();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x6ECE (offset 0x2ECE) */
void p29_L_6ECE(void) {
  cpu_push_hl();
  set_hl(0x83F4);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x6ED5 (offset 0x2ED5) */
void p29_L_6ED5(void) {
  a = mem_read8(0x83F4);
  flag_cmp(a, 0xFF);
  return;
}

/* flash page 29 cpu 0x6EDB (offset 0x2EDB) */
void p29_L_6EDB(void) {
  p29_L_75EC();
  lab_p29_L_6EDE: ;
  p29_L_7BD4();
  p29_L_6800();
  flag_cmp(a, b);
  if (flag_c()) goto lab_p29_L_6F53;
  if (flag_z()) goto lab_p29_L_6F53;
  set_hl(0x4000);
  cpu_push_af();
  p29_L_6B36();
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p29_L_6F0A;
  cpu_pop_af();
  cpu_push_af();
  p29_L_4A3F();
  a = c;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_6F52;
  b = c;
  set_de(0x4000);
  lab_p29_L_6F01: ;
  p29_L_652E();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_6F01;
  lab_p29_L_6F06: ;
  cpu_pop_af();
  a = (uint8_t)(a - c);
  goto lab_p29_L_6EDE;
  lab_p29_L_6F0A: ;
  flag_cmp(a, 0x80);
  if (flag_nz()) goto lab_p29_L_6F52;
  cpu_pop_af();
  cpu_push_af();
  p00_L_3E31();
  if (flag_nz()) goto lab_p29_L_6F52;
  cpu_pop_af();
  cpu_push_af();
  p29_L_5E34();
  p29_L_53E5();
  if (flag_z()) goto lab_p29_L_6F43;
  cpu_pop_af();
  cpu_push_af();
  p29_L_4A3F();
  a = c;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_6F52;
  b = c;
  lab_p29_L_6F29: ;
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  set_de(0x4000);
  b = 0x00;
  os_bcall(0x8021);
  set_de(0x4000);
  p29_L_652E();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_z()) goto lab_p29_L_6F4E;
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  cpu_push_af();
  goto lab_p29_L_6F29;
  lab_p29_L_6F43: ;
  cpu_pop_af();
  cpu_push_af();
  p29_L_4A3F();
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_6F52;
  goto lab_p29_L_6F06;
  lab_p29_L_6F4E: ;
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  goto lab_p29_L_6EDE;
  lab_p29_L_6F52: ;
  cpu_pop_af();
  lab_p29_L_6F53: ;
  return;
}

/* flash page 29 cpu 0x6F54 (offset 0x2F54) */
void p29_L_6F54(void) {
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p29_L_6F7D;
  cpu_push_af();
  a = mem_read8(0x8478);
  cpu_push_af();
  p29_L_6800();
  cpu_pop_af();
  mem_write8(0x8478, a);
  cpu_pop_af();
  flag_cmp(a, b);
  if (flag_z()) goto lab_p29_L_6F6E;
  if (flag_nc()) goto lab_p29_L_6F7D;
  lab_p29_L_6F6E: ;
  set_bc(0x4000);
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p29_L_6F7D;
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p29_L_6F7D;
  goto lab_p29_L_6F7E;
  lab_p29_L_6F7D: ;
  /* scf */
  lab_p29_L_6F7E: ;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x6F82 (offset 0x2F82) */
void p29_L_6F82(void) {
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p29_L_6FA7;
  cpu_push_af();
  a = mem_read8(0x8478);
  cpu_push_af();
  p29_L_6800();
  cpu_pop_af();
  mem_write8(0x8478, a);
  cpu_pop_af();
  flag_cmp(a, b);
  if (flag_z()) goto lab_p29_L_6F9C;
  if (flag_nc()) goto lab_p29_L_6FA7;
  lab_p29_L_6F9C: ;
  set_bc(0x4000);
  cpu_ex_de_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_c()) goto lab_p29_L_6FA7;
  goto lab_p29_L_6FA8;
  lab_p29_L_6FA7: ;
  /* scf */
  lab_p29_L_6FA8: ;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x6FAC (offset 0x2FAC) */
void p29_L_6FAC(void) {
  cpu_push_hl();
  cpu_push_bc();
  p29_L_75E1();
  if (flag_nc()) goto lab_p29_L_6FBD;
  p29_L_6800();
  flag_cmp(a, b);
  if (flag_c()) goto lab_p29_L_6FBA;
  a = a | a;
  flag_logic(a);
  lab_p29_L_6FBA: ;
  cpu_pop_bc();
  cpu_pop_hl();
  return;
  lab_p29_L_6FBD: ;
  /* scf */
  goto lab_p29_L_6FBA;
}

/* flash page 29 cpu 0x6FC0 (offset 0x2FC0) */
void p29_L_6FC0(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  set_hl(0x4000);
  set_de(0x80C0);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_6FF4;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(0x843E);
  os_bcall(0x805A);
  a = mem_read8(0x843E);
  p29_L_5CFF();
  p00_L_01C8();
  b = a;
  a = mem_read8(0x83A5);
  flag_cmp(a, b);
  if (flag_z()) goto lab_p29_L_6FE9;
  if (flag_c()) goto lab_p29_L_6FF4;
  goto lab_p29_L_6FF5;
  lab_p29_L_6FE9: ;
  p00_L_01C8();
  a = mem_read8(0x83A6);
  flag_cmp(a, b);
  if (flag_z()) goto lab_p29_L_6FF4;
  if (flag_nc()) goto lab_p29_L_6FF5;
  lab_p29_L_6FF4: ;
  a = 0;
  flag_logic(a);
  lab_p29_L_6FF5: ;
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x6FF9 (offset 0x2FF9) */
void p29_L_6FF9(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p29_L_701F;
  a = mem_read8(0x843E);
  set_hl(0x4000);
  set_de(0x80A0);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_7024;
  set_hl((uint16_t)(hl() + 1));
  a = mem_read8(0x843E);
  os_bcall(0x805A);
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_7024;
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_7024;
  lab_p29_L_701F: ;
  p00_L_0BB1();
  goto lab_p29_L_7027;
  lab_p29_L_7024: ;
  p00_L_0B8D();
  lab_p29_L_7027: ;
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x702B (offset 0x302B) */
void p29_str_2(void) {
  b = h;
  h = l;
  l = h;
  h = l;
  mem_write8(hl(), h);
  l = c;
  l = mem_read8(hl());
  h = a;
  l = 0x2E;
  l = 0x00;
  p29_str_1();
  return;
}

/* flash page 29 cpu 0x7037 (offset 0x3037) */
void p29_str_1(void) {
  c = b;
  h = c;
  halt();
  h = l;
  if (flag_nz()) goto lab_p29_L_7082;
  a = b;
  mem_write8(hl(), b);
  l = c;
  mem_write8(hl(), d);
  h = l;
  h = h;
  l = 0x00;
  p29_L_7045();
  return;
  lab_p29_L_7062: ;
  cpu_push_af();
  os_bcall(0x8051);
  flag_cmp(a, d);
  if (flag_nz()) goto lab_p29_L_709E;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8051);
  a = a & 0xF0;
  flag_logic(a);
  flag_cmp(a, e);
  if (flag_nz()) goto lab_p29_L_7078;
  cpu_pop_af();
  set_hl((uint16_t)(hl() - 1));
  goto lab_p29_L_70A2;
  lab_p29_L_7078: ;
  cpu_pop_af();
  cpu_push_af();
  cpu_push_de();
  os_bcall(0x805A);
  cpu_pop_de();
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x83EE, hl());
  lab_p29_L_7082: ;
  a = (uint8_t)(a + e);
  cpu_pop_af();
  cpu_push_af();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x8051);
  a = a & 0xF0;
  flag_logic(a);
  flag_cmp(a, e);
  if (flag_z()) goto lab_p29_L_7093;
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p29_L_7097;
  lab_p29_L_7093: ;
  cpu_pop_hl();
  cpu_pop_af();
  goto lab_p29_L_7062;
  lab_p29_L_7097: ;
  cpu_pop_hl();
  set_hl(mem_read16(0x83EE));
  a = 0x01;
  a = a | a;
  flag_logic(a);
  lab_p29_L_709E: ;
  cpu_pop_bc();
  ix = cpu_pop16();
  return;
  lab_p29_L_70A2: ;
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  ix = cpu_pop16();
  return;
}

/* flash page 29 cpu 0x7045 (offset 0x3045) */
void p29_L_7045(void) {
  cpu_push_bc();
  cpu_push_af();
  a = mem_read8(0x97A6);
  b = a;
  lab_p29_L_704B: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  /* scf */
  if (flag_z()) goto lab_p29_L_705A;
  p00_L_3F9F();
  a = mem_read8(0x844B);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p29_L_704B;
  lab_p29_L_705A: ;
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x705E (offset 0x305E) */
void p29_L_705E(void) {
  a = 0x7E;
  p29_L_7060();
  return;
}

/* flash page 29 cpu 0x7060 (offset 0x3060) */
void p29_L_7060(void) {
  cpu_push16(ix);
  lab_p29_L_7062: ;
  cpu_push_af();
  os_bcall(0x8051);
  flag_cmp(a, d);
  if (flag_nz()) goto lab_p29_L_709E;
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  cpu_push_af();
  os_bcall(0x8051);
  a = a & 0xF0;
  flag_logic(a);
  flag_cmp(a, e);
  if (flag_nz()) goto lab_p29_L_7078;
  cpu_pop_af();
  set_hl((uint16_t)(hl() - 1));
  goto lab_p29_L_70A2;
  lab_p29_L_7078: ;
  cpu_pop_af();
  cpu_push_af();
  cpu_push_de();
  os_bcall(0x805A);
  cpu_pop_de();
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x83EE, hl());
  cpu_pop_af();
  cpu_push_af();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x8051);
  a = a & 0xF0;
  flag_logic(a);
  flag_cmp(a, e);
  if (flag_z()) goto lab_p29_L_7093;
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p29_L_7097;
  lab_p29_L_7093: ;
  cpu_pop_hl();
  cpu_pop_af();
  goto lab_p29_L_7062;
  lab_p29_L_7097: ;
  cpu_pop_hl();
  set_hl(mem_read16(0x83EE));
  a = 0x01;
  a = a | a;
  flag_logic(a);
  lab_p29_L_709E: ;
  cpu_pop_bc();
  ix = cpu_pop16();
  return;
  lab_p29_L_70A2: ;
  a = 0x00;
  flag_set_z((a & (1u << 7)) == 0);
  ix = cpu_pop16();
  return;
}

/* flash page 29 cpu 0x70A9 (offset 0x30A9) */
void p29_L_70A9(void) {
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
  p00_L_240A();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  b = 0xFC;
  p29_L_6F54();
  if (flag_c()) { p00_L_2541(); return; }
  os_bcall(0x8021);
  p29_L_5FED();
  return;
}

/* flash page 29 cpu 0x70D1 (offset 0x30D1) */
void p29_L_70D1(void) {
  set_de(0x0300);
  os_bcall(0x8027);
  return;
}

/* flash page 29 cpu 0x70D8 (offset 0x30D8) */
void p29_str_3(void) {
  b = e;
  h = l;
  mem_write8(hl(), d);
  mem_write8(hl(), h);
  l = 0x20;
  d = d;
  h = l;
  halt();
  l = c;
  mem_write8(hl(), e);
  l = c;
  l = a;
  l = mem_read8(hl());
  if (flag_nz()) goto lab_p29_L_710B;
  /* nop */
  p29_L_70E9();
  return;
  lab_p29_L_710A: ;
  a = mem_read8(hl());
  lab_p29_L_710B: ;
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_710A;
  set_hl(0x8478);
  p00_L_3D4D();
  a = 0x7E;
  cpu_pop_hl();
  p29_L_4873();
  cpu_push_bc();
  cpu_pop_hl();
  p29_L_598E();
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x70E9 (offset 0x30E9) */
void p29_L_70E9(void) {
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
  p29_L_70D1();
  if (flag_nz()) { p29_L_5FDB(); return; }
  cpu_push_hl();
  set_hl(0x70D8);
  set_de(0x8478);
  set_bc(0x0012);
  lab_p29_L_710A: ;
  a = mem_read8(hl());
  mem_write8(de(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_710A;
  set_hl(0x8478);
  p00_L_3D4D();
  a = 0x7E;
  cpu_pop_hl();
  p29_L_4873();
  cpu_push_bc();
  cpu_pop_hl();
  p29_L_598E();
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x7124 (offset 0x3124) */
void p29_L_7124(void) {
  a = mem_read8(0x8674);
  flag_cmp(a, 0x23);
  return;
}

/* flash page 29 cpu 0x712A (offset 0x312A) */
void p29_L_712A(void) {
  set_bc(mem_read16(0x8685));
  a = (uint8_t)(a - c);
  set_hl(mem_read16(0x8683));
  cpu_push_af();
  a = mem_read8(0x8434);
  a = (uint8_t)(a - c);
  p29_L_5EFC();
  if (flag_c()) { p29_L_7150(); return; }
  cpu_pop_af();
  set_bc(mem_read16(0x867D));
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_af();
  h = 0x09;
  p00_L_2C5B();
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_hl();
  p29_L_7240();
  return;
}

/* flash page 29 cpu 0x7150 (offset 0x3150) */
void p29_L_7150(void) {
  p29_L_5FDB();
  p29_L_7124();
  cpu_push_af();
  if (flag_z()) goto lab_p29_L_715C;
  p00_L_25C8();
  lab_p29_L_715C: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_z()) goto lab_p29_L_7166;
  set_hl(0x2C79);
  p00_L_25A2();
  lab_p29_L_7166: ;
  p00_L_3D2F();
  a = 0x0B;
  p00_L_2C49();
  cpu_pop_af();
  if (flag_z()) goto lab_p29_L_7174;
  p00_L_25C8();
  lab_p29_L_7174: ;
  p00_L_3D05();
  p00_L_2541();
  return;
}

/* flash page 29 cpu 0x717A (offset 0x317A) */
void p29_L_717A(void) {
  set_hl(0x8000);
  set_de(0x81AF);
  goto lab_p29_L_7188;
  lab_p29_L_7188: ;
  set_bc(0x0080);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 29 cpu 0x7182 (offset 0x3182) */
void p29_L_7182(void) {
  set_hl(0x81AF);
  set_de(0x8000);
  set_bc(0x0080);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 29 cpu 0x7240 (offset 0x3240) */
void p29_L_7240(void) {
  cpu_push16(ix);
  cpu_push_af();
  mem_write8(0x82A4, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x8672, a);
  cpu_ex_de_hl();
  mem_write16(0x843B, de());
  cpu_push_bc();
  p00_L_2C61();
  cpu_pop_bc();
  set_hl(0x8670);
  a = mem_read8(0x8675);
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p29_L_733F;
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
  set_hl(mem_read16(0x8676));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nz()) goto lab_p29_L_733F;
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 7)));
  a = 0;
  flag_logic(a);
  mem_write8(0x9C87, a);
  set_bc(mem_read16(0x8676));
  set_de(0x0000);
  mem_write16(0x8678, de());
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_7363;
  set_hl(0x8000);
  mem_write16(0x8439, bc());
  lab_p29_L_729C: ;
  p00_L_171E();
  if (flag_z()) goto lab_p29_L_7345;
  p00_L_2565();
  return;
  lab_p29_L_733F: ;
  p29_L_5FDB();
  p00_L_2565();
  return;
  lab_p29_L_7345: ;
  cpu_push_bc();
  p00_L_3F81();
  mem_write8(hl(), a);
  p29_L_7CA5();
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  b = 0x00;
  set_hl(mem_read16(0x8678));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x8678, hl());
  cpu_ex_de_hl();
  p29_L_7CBB();
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_729C;
  lab_p29_L_7363: ;
  p00_L_3F81();
  cpu_push_af();
  p00_L_3F81();
  b = a;
  cpu_pop_af();
  c = a;
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_738A;
  a = hw_in(PORT_SE_STATUS);
  a = a & 0x01;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_738A;
  a = 0;
  flag_logic(a);
  hw_out(PORT_SE_STATUS, a);
  set_de(0x00FE);
  lab_p29_L_737F: ;
  set_de((uint16_t)(de() - 1));
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_737F;
  a = 0x01;
  hw_out(PORT_SE_STATUS, a);
  goto lab_p29_L_7392;
  lab_p29_L_738A: ;
  set_de(0x0100);
  lab_p29_L_738D: ;
  set_de((uint16_t)(de() - 1));
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_738D;
  lab_p29_L_7392: ;
  set_hl(mem_read16(0x8678));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nz()) goto lab_p29_L_75A5;
  p29_L_739B();
  return;
  lab_p29_L_75A5: ;
  set_hl(mem_read16(0x8439));
  cpu_push_hl();
  h = 0x5A;
  p00_L_2C5B();
  p29_L_7336();
  return;
}

/* flash page 29 cpu 0x72A5 (offset 0x32A5) */
void p29_L_72A5(void) {
  p29_L_733B();
  p29_L_5FDB();
  p29_L_7124();
  cpu_push_af();
  if (flag_z()) goto lab_p29_L_72B4;
  p00_L_25C8();
  lab_p29_L_72B4: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_z()) goto lab_p29_L_72BE;
  set_hl(0x2C79);
  p00_L_25A2();
  lab_p29_L_72BE: ;
  p00_L_3D2F();
  a = 0x01;
  p00_L_2C49();
  cpu_pop_af();
  if (flag_z()) goto lab_p29_L_72CC;
  p00_L_25C8();
  lab_p29_L_72CC: ;
  p00_L_3D05();
  p00_L_24F5();
  return;
}

/* flash page 29 cpu 0x732F (offset 0x332F) */
void p29_L_732F(void) {
  p29_L_733B();
  p00_L_2C49();
  return;
}

/* flash page 29 cpu 0x7336 (offset 0x3336) */
void p29_L_7336(void) {
  h = 0x36;
  p00_L_2C73();
  return;
}

/* flash page 29 cpu 0x733B (offset 0x333B) */
void p29_L_733B(void) {
  p29_L_7CB2();
  if (flag_nz()) return;
  p29_L_5FDB();
  p00_L_2565();
  return;
}

/* flash page 29 cpu 0x739B (offset 0x339B) */
void p29_L_739B(void) {
  goto lab_p29_L_739B;
  lab_p29_L_72D2: ;
  p29_L_733B();
  p29_L_5FDB();
  p29_L_7124();
  cpu_push_af();
  if (flag_z()) goto lab_p29_L_72E1;
  p00_L_25C8();
  lab_p29_L_72E1: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_z()) goto lab_p29_L_72EB;
  set_hl(0x2C79);
  p00_L_25A2();
  lab_p29_L_72EB: ;
  p00_L_3D2F();
  a = 0x07;
  p00_L_2C49();
  cpu_pop_af();
  if (flag_z()) goto lab_p29_L_72F9;
  p00_L_25C8();
  lab_p29_L_72F9: ;
  p00_L_2C55();
  p00_L_3D05();
  p00_L_2539();
  return;
  lab_p29_L_7302: ;
  p29_L_733B();
  p29_L_5FDB();
  p29_L_7124();
  cpu_push_af();
  if (flag_z()) goto lab_p29_L_7311;
  p00_L_25C8();
  lab_p29_L_7311: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_z()) goto lab_p29_L_731B;
  set_hl(0x2C79);
  p00_L_25A2();
  lab_p29_L_731B: ;
  p00_L_3D2F();
  a = 0x09;
  p00_L_2C49();
  cpu_pop_af();
  if (flag_z()) goto lab_p29_L_7329;
  p00_L_25C8();
  lab_p29_L_7329: ;
  p00_L_3D05();
  p00_L_253D();
  return;
  lab_p29_L_739B: ;
  p29_L_5E0A();
  a = mem_read8(0x822F);
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p29_L_74BC;
  set_de(mem_read16(0x843B));
  cpu_push_de();
  os_bcall(0x8063);
  cpu_pop_de();
  mem_write16(0x843B, de());
  if (flag_nz()) goto lab_p29_L_72D2;
  a = 0x01;
  set_de(0x8050);
  p29_L_7060();
  if (flag_nz()) goto lab_p29_L_73C6;
  p29_L_50C5();
  if (flag_nz()) goto lab_p29_L_7302;
  lab_p29_L_73C6: ;
  p29_L_75B8();
  a = mem_read8(0x8432);
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p29_L_75B4;
  /* di */
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p00_L_3CD5();
  a = mem_read8(0x8670);
  cpu_push_af();
  p29_L_717A();
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 2)));
  p00_L_0AFB();
  if (flag_z()) { p00_L_24FD(); return; }
  a = 0x00;
  b = 0x00;
  p00_L_2EB9();
  p29_L_7182();
  cpu_pop_af();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  mem_write8(0x8670, a);
  p29_L_7B72();
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p29_L_72A5(); return; }
  cpu_push_af();
  p29_L_7BEA();
  if (flag_c()) goto lab_p29_L_740C;
  lab_p29_L_7409: ;
  if (flag_nz()) { p29_L_72A5(); return; }
  lab_p29_L_740C: ;
  a = 0;
  flag_logic(a);
  flag_cmp(a, d);
  if (flag_z()) { p00_L_24FD(); return; }
  cpu_push_de();
  p29_L_5242();
  flag_cmp(a, 0x08);
  if (flag_z()) goto lab_p29_L_7430;
  a = (uint8_t)(a + 0x04);
  b = a;
  a = c;
  a = (uint8_t)(a - d);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p29_L_7430;
  a = 0x05;
  p00_L_2EB9();
  p29_L_5242();
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p29_L_7409;
  p29_L_7182();
  lab_p29_L_7430: ;
  a = mem_read8(0x82A3);
  p29_L_6CB5();
  a = 0x01;
  set_hl(0x8000);
  p29_L_5E34();
  p29_L_7CB2();
  if (flag_z()) goto lab_p29_L_7453;
  a = 0x19;
  mem_write8(0x8672, a);
  p00_L_2E23();
  p00_L_2DE7();
  /* di */
  a = 0;
  flag_logic(a);
  mem_write8(0x8672, a);
  lab_p29_L_7453: ;
  cpu_pop_de();
  cpu_pop_af();
  cpu_push_de();
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
  p29_L_519D();
  p29_L_5E90();
  set_hl(0x8000);
  p29_L_5757();
  set_hl(mem_read16(0x83A1));
  p29_L_57C5();
  cpu_push_hl();
  a = 0x01;
  set_hl(0x8000);
  cpu_push_hl();
  set_hl((uint16_t)(hl() + 1));
  os_bcall(0x805A);
  cpu_pop_bc();
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  set_hl(mem_read16(0x8439));
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_sbc_hl_bc();
  p29_L_57C5();
  mem_write16(0x83A1, hl());
  if (flag_c()) goto lab_p29_L_749D;
  if (flag_nz()) goto lab_p29_L_74F0;
  lab_p29_L_749D: ;
  set_hl(mem_read16(0x839F));
  p29_L_57C5();
  set_hl((uint16_t)(hl() - 1));
  p29_L_57C5();
  mem_write16(0x839F, hl());
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_74BA;
  set_hl(mem_read16(0x83A1));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_74BA;
  a = 0x00;
  mem_write8(0x83A4, a);
  lab_p29_L_74BA: ;
  goto lab_p29_L_74F0;
  lab_p29_L_74BC: ;
  cpu_push_de();
  p29_L_7CB2();
  if (flag_nz()) goto lab_p29_L_74F0;
  a = mem_read8(0x82A4);
  p29_L_7CCF();
  p29_L_4566();
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p29_L_74ED;
  p29_L_4565();
  flag_cmp(a, 0xBF);
  if (flag_nz()) goto lab_p29_L_74ED;
  p29_L_4565();
  b = a;
  a = mem_read8(0x82A4);
  flag_cmp(a, b);
  if (flag_z()) goto lab_p29_L_74F0;
  if (flag_nc()) goto lab_p29_L_74ED;
  p29_L_4565();
  b = a;
  a = mem_read8(0x82A4);
  b = (uint8_t)(b + 1);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p29_L_74F0;
  lab_p29_L_74ED: ;
  p29_L_7150();
  return;
  lab_p29_L_74F0: ;
  set_bc(mem_read16(0x8439));
  set_hl(0x8000);
  set_de(mem_read16(0x843B));
  a = mem_read8(0x82A4);
  flag_set_z((d & (1u << 7)) == 0);
  if (flag_nz()) { p29_L_7150(); return; }
  flag_set_z((d & (1u << 6)) == 0);
  if (flag_z()) { p29_L_7150(); return; }
  flag_cmp(a, 0x08);
  if (flag_c()) { p29_L_7150(); return; }
  p29_L_75E1();
  if (flag_nc()) { p29_L_7150(); return; }
  p29_L_756F();
  os_bcall(0x8087);
  p29_L_7CB2();
  if (flag_z()) goto lab_p29_L_752A;
  p29_L_5FDB();
  p00_L_3F1B();
  lab_p29_L_7524: ;
  cpu_pop_de();
  lab_p29_L_7525: ;
  cpu_pop_af();
  ix = cpu_pop16();
  a = 0;
  flag_logic(a);
  return;
  lab_p29_L_752A: ;
  a = mem_read8(0x822F);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_7535;
  p29_L_5FDB();
  goto lab_p29_L_7524;
  lab_p29_L_7535: ;
  p29_L_7CCF();
  cpu_pop_de();
  cpu_push_hl();
  cpu_push_de();
  b = 0x04;
  lab_p29_L_753D: ;
  p29_L_4566();
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p29_L_7549;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_753D;
  goto lab_p29_L_754C;
  lab_p29_L_7549: ;
  p29_L_407A();
  lab_p29_L_754C: ;
  set_hl(0xBFFE);
  mem_write16(0x8479, hl());
  a = mem_read8(0x82A3);
  mem_write8(0x847B, a);
  cpu_pop_de();
  a = (uint8_t)(a - d);
  mem_write8(0x847C, a);
  set_bc(0x0004);
  set_hl(0x8479);
  p29_L_7700();
  cpu_pop_de();
  os_bcall(0x8087);
  p29_L_5FDB();
  goto lab_p29_L_7525;
  lab_p29_L_75B4: ;
  cpu_pop_af();
  ix = cpu_pop16();
  return;
}

/* flash page 29 cpu 0x756F (offset 0x356F) */
void p29_L_756F(void) {
  h = d;
  l = e;
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() + bc()));
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_z()) goto lab_p29_L_75A1;
  set_hl(0x8000);
  set_de(mem_read16(0x843B));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  b = h;
  c = l;
  set_hl(0x8000);
  cpu_push_bc();
  os_bcall(0x8087);
  cpu_pop_bc();
  a = mem_read8(0x82A4);
  a = (uint8_t)(a - 1);
  set_hl(mem_read16(0x8439));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_bc();
  b = h;
  c = l;
  cpu_pop_de();
  set_hl(0x8000);
  set_hl((uint16_t)(hl() + de()));
  set_de(0x4000);
  return;
  lab_p29_L_75A1: ;
  set_hl(0x8000);
  return;
}

/* flash page 29 cpu 0x75B8 (offset 0x35B8) */
void p29_L_75B8(void) {
  goto lab_p29_L_75B8;
  lab_p29_L_75B1: ;
  p29_L_732F();
  return;
  lab_p29_L_75B8: ;
  p00_L_1295();
  a = 0x01;
  a = a | a;
  flag_logic(a);
  set_hl(0x8000);
  set_de(0x8040);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_75B1;
  set_hl((uint16_t)(hl() + 1));
  a = 0x01;
  os_bcall(0x805A);
  set_de(0x8479);
  while (bc() != 0) { cpu_ldi(); }
  a = mem_read8(0x82A4);
  cpu_push_af();
  p29_L_6428();
  cpu_pop_af();
  mem_write8(0x82A4, a);
  return;
}

/* flash page 29 cpu 0x75E1 (offset 0x35E1) */
void p29_L_75E1(void) {
  p00_L_24A9();
  if (flag_nz()) goto lab_p29_L_75E9;
  flag_cmp(a, 0x6A);
  return;
  lab_p29_L_75E9: ;
  flag_cmp(a, 0x16);
  return;
}

/* flash page 29 cpu 0x75EC (offset 0x35EC) */
void p29_L_75EC(void) {
  a = 0x15;
  p00_L_24A9();
  if (flag_nz()) return;
  a = 0x69;
  return;
}

/* flash page 29 cpu 0x75F5 (offset 0x35F5) */
void p29_L_75F5(void) {
  p29_L_75EC();
  a = (uint8_t)(a + 1);
  mem_write8(0x82A3, a);
  return;
}

/* flash page 29 cpu 0x75FD (offset 0x35FD) */
void p29_L_75FD(void) {
  set_de(0x839F);
  a = a & 0x0F;
  flag_logic(a);
  flag_cmp(a, 0x0F);
  if (flag_nz()) goto lab_p29_L_7609;
  b = 0x04;
  return;
  lab_p29_L_7609: ;
  flag_cmp(a, 0x0E);
  if (flag_nz()) goto lab_p29_L_7612;
  b = 0x02;
  a = 0;
  flag_logic(a);
  goto lab_p29_L_761A;
  lab_p29_L_7612: ;
  flag_cmp(a, 0x0D);
  if (flag_nz()) return;
  b = 0x01;
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  lab_p29_L_761A: ;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  return;
}

/* flash page 29 cpu 0x761F (offset 0x361F) */
void p29_L_761F(void) {
  lab_p29_L_761F: ;
  cpu_push_af();
  p29_L_6B36();
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_761F;
  return;
}

/* flash page 29 cpu 0x762A (offset 0x362A) */
void p29_L_762A(void) {
  p29_L_7634();
  set_de(0x0610);
  os_bcall(0x8030);
  return;
}

/* flash page 29 cpu 0x7634 (offset 0x3634) */
void p29_L_7634(void) {
  p29_L_4894();
  set_de(0x0600);
  p29_L_777E();
  p29_L_4574();
  a = 0x7E;
  return;
}

/* flash page 29 cpu 0x7643 (offset 0x3643) */
void p29_L_7643(void) {
  set_bc(0x000D);
  p00_L_24A9();
  if (flag_nz()) return;
  set_bc(0x0061);
  return;
}

/* flash page 29 cpu 0x764E (offset 0x364E) */
void p29_L_764E(void) {
  cpu_push16(ix);
  cpu_pop_hl();
  set_bc(0x000D);
  set_hl((uint16_t)(hl() + bc()));
  return;
}

/* flash page 29 cpu 0x7656 (offset 0x3656) */
void p29_L_7656(void) {
  a = 0x16;
  p00_L_24A9();
  if (flag_nz()) return;
  a = 0x6A;
  return;
}

/* flash page 29 cpu 0x7663 (offset 0x3663) */
void p29_L_7663(void) {
  set_bc(0x0001);
  p29_L_7666();
  return;
}

/* flash page 29 cpu 0x7666 (offset 0x3666) */
void p29_L_7666(void) {
  mem_write8((uint16_t)(iy + 0x25), (uint8_t)(mem_read8((uint16_t)(iy + 0x25)) & ~(1u << 1)));
  p00_L_24A9();
  if (flag_z()) goto lab_p29_L_7671;
  a = a & 0x1F;
  flag_logic(a);
  lab_p29_L_7671: ;
  cpu_push16(ix);
  ix = 0x767D;
  p29_L_6B87();
  ix = cpu_pop16();
  return;
}

/* flash page 29 cpu 0x7700 (offset 0x3700) */
void p29_L_7700(void) {
  a = hw_in(PORT_STATUS);
  a = a & 0x80;
  flag_logic(a);
  a = 0x1E;
  if (flag_z()) return;
  p29_L_7707();
  return;
}

/* flash page 29 cpu 0x7707 (offset 0x3707) */
void p29_L_7707(void) {
  a = 0x7E;
  return;
}

/* flash page 29 cpu 0x770A (offset 0x370A) */
void p29_L_770A(void) {
  cpu_push_af();
  a = (uint8_t)(a + 1);
  mem_write8(0x82A3, a);
  p29_L_638B();
  a = 0x14;
  mem_write8(0x8478, a);
  set_bc(0x0008);
  set_hl(0x8484);
  set_de(0x8479);
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x7724 (offset 0x3724) */
void p29_L_7724(void) {
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
  /* nop */
  p29_L_43F6();
  if (flag_nz()) goto lab_p29_L_777B;
  a = mem_read8(0x8434);
  set_hl(0x4000);
  p29_L_5E59();
  p29_L_52D9();
  if (flag_c()) goto lab_p29_L_774F;
  if (flag_nz()) goto lab_p29_L_7778;
  lab_p29_L_774F: ;
  a = mem_read8(0x8434);
  set_hl(0x4000);
  p29_L_5E34();
  p29_L_51C3();
  a = mem_read8(0x8434);
  set_hl(0x4000);
  p29_L_5E59();
  p29_L_533B();
  p29_L_6800();
  a = b;
  os_bcall(0x80CF);
  a = 0xFF;
  mem_write8(0x8670, a);
  p29_L_5FDB();
  a = 0;
  flag_logic(a);
  return;
  lab_p29_L_7778: ;
  a = 0x09;
  return;
  lab_p29_L_777B: ;
  a = 0x08;
  return;
}

/* flash page 29 cpu 0x777E (offset 0x377E) */
void p29_L_777E(void) {
  p29_L_7700();
  os_bcall(0x805D);
  return;
}

/* flash page 29 cpu 0x780B (offset 0x380B) */
void p29_L_780B(void) {
  return;
}

/* flash page 29 cpu 0x780D (offset 0x380D) */
void p29_L_780D(void) {
  p00_L_24F5();
  return;
}

/* flash page 29 cpu 0x7865 (offset 0x3865) */
void p29_L_7865(void) {
  lab_p29_L_7865: ;
  cpu_push_hl();
  cpu_push_bc();
  a = mem_read8(0x8439);
  set_de(0x8000);
  set_bc(0x0100);
  os_bcall(0x8054);
  cpu_pop_bc();
  set_hl(0x0100);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_nc()) goto lab_p29_L_7882;
  cpu_push_bc();
  set_bc(0x0100);
  goto lab_p29_L_7883;
  lab_p29_L_7882: ;
  cpu_push_bc();
  lab_p29_L_7883: ;
  set_hl(0x8000);
  os_bcall(0x8090);
  cpu_ex_de_hl();
  cpu_pop_hl();
  set_bc(0x0100);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_push_hl();
  cpu_pop_bc();
  cpu_ex_de_hl();
  if (flag_z()) goto lab_p29_L_78A1;
  if (flag_c()) goto lab_p29_L_78A1;
  cpu_pop_hl();
  cpu_push_bc();
  set_de(0x0100);
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_bc();
  goto lab_p29_L_7865;
  lab_p29_L_78A1: ;
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x78A3 (offset 0x38A3) */
void p29_L_78A3(void) {
  cpu_push_af();
  cpu_push_hl();
  cpu_push_bc();
  b = 0x08;
  lab_p29_L_78A8: ;
  c = a;
  a = a ^ e;
  flag_logic(a);
  /* rr d */
  /* rr e */
  a = a & 0x01;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_78BA;
  a = 0x08;
  a = a ^ e;
  flag_logic(a);
  e = a;
  a = 0x84;
  a = a ^ d;
  flag_logic(a);
  d = a;
  lab_p29_L_78BA: ;
  a = c;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_78A8;
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x78C2 (offset 0x38C2) */
void p29_L_78C2(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_af();
  set_de(0xFFFF);
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_78F1;
  lab_p29_L_78CC: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  cpu_push_af();
  cpu_push_hl();
  cpu_push_bc();
  b = 0x08;
  lab_p29_L_78D3: ;
  c = a;
  a = a ^ e;
  flag_logic(a);
  /* rr d */
  /* rr e */
  a = a & 0x01;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_78E5;
  a = 0x08;
  a = a ^ e;
  flag_logic(a);
  e = a;
  a = 0x84;
  a = a ^ d;
  flag_logic(a);
  d = a;
  lab_p29_L_78E5: ;
  a = c;
  cpu_rra();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_78D3;
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_af();
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_78CC;
  lab_p29_L_78F1: ;
  cpu_pop_af();
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x78F5 (offset 0x38F5) */
void p29_L_78F5(void) {
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  set_hl(0x790F);
  p00_L_0059();
  p00_L_3F81();
  l = a;
  p00_L_005C();
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p29_L_790F;
  a = 0;
  flag_logic(a);
  a = l;
  goto lab_p29_L_7911;
  lab_p29_L_790F: ;
  a = a | 0xFF;
  flag_logic(a);
  lab_p29_L_7911: ;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x7915 (offset 0x3915) */
void p29_L_7915(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_af();
  set_de(0x0000);
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_792D;
  lab_p29_L_791F: ;
  p29_L_78F5();
  if (flag_nz()) goto lab_p29_L_792D;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() + 1));
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_791F;
  a = 0;
  flag_logic(a);
  lab_p29_L_792D: ;
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x7932 (offset 0x3932) */
void p29_L_7932(void) {
  cpu_push_bc();
  cpu_push_af();
  p00_L_24A9();
  if (flag_z()) goto lab_p29_L_7945;
  a = link_in(); /* stub */
  a = a & 0x03;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_7949;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p29_L_7949;
  goto lab_p29_L_7949;
  lab_p29_L_7945: ;
  a = hw_in(0x09);
  a = a & 0x58;
  flag_logic(a);
  lab_p29_L_7949: ;
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x794D (offset 0x394D) */
void p29_L_794D(void) {
  cpu_push_af();
  lab_p29_L_794E: ;
  p29_L_7932();
  if (flag_z()) goto lab_p29_L_795A;
  p29_L_78F5();
  if (flag_nz()) goto lab_p29_L_795A;
  goto lab_p29_L_794E;
  lab_p29_L_795A: ;
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x795C (offset 0x395C) */
void p29_L_795C(void) {
  cpu_push16(ix);
  ix = 0x0000;
  cpu_add_ix_sp();
  cpu_push_hl();
  cpu_push_de();
  cpu_push_af();
  cpu_push_af();
  cpu_push_af();
  set_de(0xFFFF);
  p29_L_78F5();
  if (flag_nz()) goto lab_p29_L_79F0;
  p29_L_78F5();
  if (flag_nz()) goto lab_p29_L_79F0;
  p29_L_78A3();
  h = a;
  p29_L_78F5();
  if (flag_nz()) goto lab_p29_L_79F0;
  p29_L_78A3();
  l = a;
  p29_L_7984();
  return;
  lab_p29_L_79F0: ;
  p29_L_794D();
  a = a | 0xFF;
  flag_logic(a);
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_hl();
  ix = cpu_pop16();
  return;
}

/* flash page 29 cpu 0x7984 (offset 0x3984) */
void p29_L_7984(void) {
  /* ld (ix-0x07),ixh */
  /* ld (ix-0x08),ixl */
  p29_L_78F5();
  if (flag_nz()) goto lab_p29_L_79F0;
  p29_L_78A3();
  h = a;
  p29_L_78F5();
  if (flag_nz()) goto lab_p29_L_79F0;
  p29_L_78A3();
  l = a;
  /* ld (ix-0x05),ixh */
  /* ld (ix-0x06),ixl */
  p29_L_78F5();
  if (flag_nz()) goto lab_p29_L_79F0;
  h = a;
  p29_L_78F5();
  if (flag_nz()) goto lab_p29_L_79F0;
  l = a;
  a = a & a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nz()) goto lab_p29_L_79F0;
  /* ld d,(ix-0x05) */
  /* ld e,(ix-0x06) */
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_79F5;
  /* ld ixh,(ix-0x03) */
  /* ld ixl,(ix-0x04) */
  a = a & a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p29_L_79F0;
  /* ld ixh,(ix-0x01) */
  /* ld ixl,(ix-0x02) */
  /* ld b,(ix-0x05) */
  /* ld c,(ix-0x06) */
  p29_L_7915();
  if (flag_nz()) goto lab_p29_L_79F0;
  p29_L_78C2();
  p29_L_78F5();
  if (flag_nz()) goto lab_p29_L_79F0;
  h = a;
  p29_L_78F5();
  if (flag_nz()) goto lab_p29_L_79F0;
  l = a;
  a = a & a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nz()) goto lab_p29_L_79F0;
  a = 0;
  flag_logic(a);
  goto lab_p29_L_79F5;
  lab_p29_L_79F0: ;
  p29_L_794D();
  a = a | 0xFF;
  flag_logic(a);
  lab_p29_L_79F5: ;
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_hl();
  ix = cpu_pop16();
  return;
}

/* flash page 29 cpu 0x7A67 (offset 0x3A67) */
void p29_L_7A67(void) {
  cpu_push_hl();
  cpu_push_de();
  set_hl(0x0000);
  set_de(0x0000);
  p29_L_7AD0();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x7A75 (offset 0x3A75) */
void p29_L_7A75(void) {
  cpu_push_bc();
  b = 0x01;
  p29_L_7A67();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x7A85 (offset 0x3A85) */
void p29_L_7A85(void) {
  cpu_push_bc();
  b = 0x04;
  p29_L_7A67();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x7A8D (offset 0x3A8D) */
void p29_L_7A8D(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 4)) == 0);
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 4)));
  return;
}

/* flash page 29 cpu 0x7A96 (offset 0x3A96) */
void p29_L_7A96(void) {
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_af();
  set_hl(0x7AAF);
  p00_L_0059();
  p00_L_3F87();
  p00_L_005C();
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p29_L_7AAF;
  a = 0;
  flag_logic(a);
  goto lab_p29_L_7AB1;
  lab_p29_L_7AAF: ;
  a = a | 0xFF;
  flag_logic(a);
  lab_p29_L_7AB1: ;
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x7AB7 (offset 0x3AB7) */
void p29_L_7AB7(void) {
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_af();
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_7ACB;
  lab_p29_L_7ABE: ;
  a = mem_read8(hl());
  p29_L_7A96();
  if (flag_nz()) goto lab_p29_L_7ACB;
  set_hl((uint16_t)(hl() + 1));
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p29_L_7ABE;
  a = 0;
  flag_logic(a);
  lab_p29_L_7ACB: ;
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x7AD0 (offset 0x3AD0) */
void p29_L_7AD0(void) {
  cpu_push16(ix);
  ix = 0x0000;
  cpu_add_ix_sp();
  cpu_push_hl();
  cpu_push_de();
  cpu_push_bc();
  cpu_push_af();
  set_de(0xFFFF);
  a = 0x5B;
  p29_L_7A96();
  if (flag_nz()) goto lab_p29_L_7B37;
  a = b;
  p29_L_78A3();
  p29_L_7A96();
  if (flag_nz()) goto lab_p29_L_7B37;
  a = c;
  p29_L_78A3();
  p29_L_7A96();
  if (flag_nz()) goto lab_p29_L_7B37;
  /* ld b,(ix-0x03) */
  /* ld c,(ix-0x04) */
  a = b;
  p29_L_78A3();
  p29_L_7A96();
  if (flag_nz()) goto lab_p29_L_7B37;
  a = c;
  p29_L_78A3();
  p29_L_7A96();
  if (flag_nz()) goto lab_p29_L_7B37;
  a = d;
  p29_L_7A96();
  if (flag_nz()) goto lab_p29_L_7B37;
  a = e;
  p29_L_7A96();
  if (flag_nz()) goto lab_p29_L_7B37;
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_7B34;
  p29_L_78C2();
  p29_L_7AB7();
  if (flag_nz()) goto lab_p29_L_7B37;
  a = d;
  p29_L_7A96();
  if (flag_nz()) goto lab_p29_L_7B37;
  a = e;
  p29_L_7A96();
  if (flag_nz()) goto lab_p29_L_7B37;
  lab_p29_L_7B34: ;
  a = 0;
  flag_logic(a);
  goto lab_p29_L_7B39;
  lab_p29_L_7B37: ;
  a = a | 0xFF;
  flag_logic(a);
  lab_p29_L_7B39: ;
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  cpu_pop_de();
  cpu_pop_hl();
  ix = cpu_pop16();
  return;
}

/* flash page 29 cpu 0x7B41 (offset 0x3B41) */
void p29_L_7B41(void) {
  goto lab_p29_L_7B41;
  lab_p29_L_75B1: ;
  p29_L_732F();
  return;
  lab_p29_L_7B41: ;
  p00_L_1295();
  a = 0x01;
  a = a | a;
  flag_logic(a);
  set_hl(0x8000);
  set_de(0x8040);
  os_bcall(0x8075);
  if (flag_nz()) goto lab_p29_L_75B1;
  set_hl((uint16_t)(hl() + 1));
  a = 0x01;
  os_bcall(0x805A);
  set_de(0x8479);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(mem_read16(0x82A3));
  cpu_push_hl();
  p29_L_6186();
  if (flag_c()) goto lab_p29_L_7B6D;
  mem_write8(0x8433, a);
  p29_L_403F();
  lab_p29_L_7B6D: ;
  cpu_pop_hl();
  mem_write16(0x82A3, hl());
  return;
}

/* flash page 29 cpu 0x7B72 (offset 0x3B72) */
void p29_L_7B72(void) {
  p29_L_75EC();
  lab_p29_L_7B75: ;
  set_hl(0x4000);
  cpu_push_af();
  p29_L_6B36();
  flag_cmp(a, 0x80);
  if (flag_z()) goto lab_p29_L_7B84;
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p29_L_7B9C;
  lab_p29_L_7B84: ;
  cpu_pop_af();
  p00_L_3E31();
  if (flag_nz()) goto lab_p29_L_7B9A;
  p29_L_4A3F();
  b = a;
  a = c;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p29_L_7B98;
  a = b;
  a = (uint8_t)(a - c);
  flag_cmp(a, 0x08);
  if (flag_nc()) goto lab_p29_L_7B75;
  lab_p29_L_7B98: ;
  a = 0;
  flag_logic(a);
  return;
  lab_p29_L_7B9A: ;
  flag_cmp(a, a);
  return;
  lab_p29_L_7B9C: ;
  flag_cmp(a, 0xFF);
  cpu_pop_bc();
  a = b;
  if (flag_nz()) goto lab_p29_L_7B9A;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 29 cpu 0x7BA4 (offset 0x3BA4) */
void p29_L_7BA4(void) {
  a = 0;
  flag_logic(a);
  b = 0x0E;
  set_hl(0x9C88);
  lab_p29_L_7BAA: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_7BAA;
  return;
}

/* flash page 29 cpu 0x7BAF (offset 0x3BAF) */
void p29_L_7BAF(void) {
  p29_L_7BBA();
  /* or (hl) */
  mem_write8(hl(), a);
  return;
}

/* flash page 29 cpu 0x7BB5 (offset 0x3BB5) */
void p29_L_7BB5(void) {
  p29_L_7BBA();
  /* and (hl) */
  return;
}

/* flash page 29 cpu 0x7BBA (offset 0x3BBA) */
void p29_L_7BBA(void) {
  a = (uint8_t)(a - 0x08);
  set_hl(0x9C88);
  c = a;
  b = 0x00;
  /* sra c */
  /* sra c */
  /* sra c */
  set_hl((uint16_t)(hl() + bc()));
  a = a & 0x07;
  flag_logic(a);
  c = a;
  p29_L_7BCC();
  return;
}

/* flash page 29 cpu 0x7BCA (offset 0x3BCA) */
void p29_L_7BCA(void) {
  cpu_rlca();
  c = a;
  p29_L_7BCC();
  return;
}

/* flash page 29 cpu 0x7BCC (offset 0x3BCC) */
void p29_L_7BCC(void) {
  b = c;
  a = 0x80;
  b = (uint8_t)(b + 1);
  lab_p29_L_7BD0: ;
  cpu_rlca();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_7BD0;
  return;
}

/* flash page 29 cpu 0x7BD4 (offset 0x3BD4) */
void p29_L_7BD4(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x12)) & (1u << 0)) == 0);
  if (flag_z()) return;
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  a = 0x01;
  mem_write8(0x8476, a);
  p00_L_01BF();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 29 cpu 0x7BEA (offset 0x3BEA) */
void p29_L_7BEA(void) {
  mem_write8(0x82A4, a);
  mem_write8(0x82A3, a);
  mem_write8(0x8434, a);
  p29_L_5DC7();
  if (flag_c()) return;
  if (flag_z()) return;
  a = e;
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p29_L_72A5(); return; }
  a = 0x06;
  p00_L_2EB9();
  if (flag_z()) { p29_L_72A5(); return; }
  p29_L_7182();
  a = mem_read8(0x8434);
  p29_L_5DC7();
  return;
}

/* flash page 29 cpu 0x7C0F (offset 0x3C0F) */
void p29_L_7C0F(void) {
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
  p29_L_6800();
  a = b;
  os_bcall(0x80CF);
  p29_L_5FDB();
  return;
}

/* flash page 29 cpu 0x7C64 (offset 0x3C64) */
void p29_L_7C64(void) {
  cpu_push_hl();
  set_hl(0x8689);
  flag_set_z((mem_read8(hl()) & (1u << 7)) == 0);
  cpu_pop_hl();
  return;
}

/* flash page 29 cpu 0x7C96 (offset 0x3C96) */
void p29_L_7C96(void) {
  p00_L_24A9();
  if (flag_nz()) goto lab_p29_L_7CA0;
  a = a & 0x7F;
  flag_logic(a);
  flag_cmp(a, 0x6A);
  return;
  lab_p29_L_7CA0: ;
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x16);
  return;
}

/* flash page 29 cpu 0x7CA5 (offset 0x3CA5) */
void p29_L_7CA5(void) {
  a = mem_read8(0x83A4);
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  a = mem_read8(0x83A3);
  a = (uint8_t)(a + 1);
  mem_write8(0x83A3, a);
  return;
}

/* flash page 29 cpu 0x7CB2 (offset 0x3CB2) */
void p29_L_7CB2(void) {
  cpu_push_bc();
  b = a;
  a = mem_read8(0x8672);
  a = (uint8_t)(a + 1);
  a = b;
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x7CBB (offset 0x3CBB) */
void p29_L_7CBB(void) {
  a = mem_read8(0x822F);
  flag_cmp(a, 0x00);
  if (flag_z()) return;
  cpu_push_hl();
  p29_L_578D();
  a = l;
  a = a | h;
  flag_logic(a);
  cpu_pop_hl();
  if (flag_nz()) return;
  a = 0x00;
  mem_write8(0x83A4, a);
  return;
}

/* flash page 29 cpu 0x7CCD (offset 0x3CCD) */
void p29_L_7CCD(void) {
  a = (uint8_t)(a + e);
  return;
}

/* flash page 29 cpu 0x7CCF (offset 0x3CCF) */
void p29_L_7CCF(void) {
  os_bcall(0x8057);
  p29_L_4897();
  set_de(0x1DE2);
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 29 cpu 0x7CDA (offset 0x3CDA) */
void p29_L_7CDA(void) {
  cpu_push_af();
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
  p00_L_2ECB();
  p29_L_7CCF();
  cpu_push_hl();
  b = 0x08;
  lab_p29_L_7CF5: ;
  p29_L_4566();
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p29_L_7D01;
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p29_L_7CF5;
  goto lab_p29_L_7D04;
  lab_p29_L_7D01: ;
  p29_L_407A();
  lab_p29_L_7D04: ;
  set_hl(0x7FFE);
  mem_write16(0x8479, hl());
  a = mem_read8(0x83EE);
  mem_write8(0x847B, a);
  set_hl(mem_read16(0x83EF));
  p29_L_69D4();
  if (flag_nz()) goto lab_p29_L_7D19;
  set_hl((uint16_t)(hl() + 1));
  lab_p29_L_7D19: ;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_de(mem_read16(0x83F5));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x847C, hl());
  mem_write16(0x84DB, hl());
  set_de(mem_read16(0x83F7));
  flag_set_z((d & (1u << 7)) == 0);
  if (flag_z()) goto lab_p29_L_7D33;
  a = (uint8_t)(a + 1);
  a = (uint8_t)(a + 1);
  d = (uint8_t)(d & ~(1u << 7));
  lab_p29_L_7D33: ;
  flag_set_z((d & (1u << 6)) == 0);
  if (flag_z()) goto lab_p29_L_7D3A;
  a = (uint8_t)(a + 1);
  d = (uint8_t)(d & ~(1u << 6));
  lab_p29_L_7D3A: ;
  set_hl((uint16_t)(hl() + de()));
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_z()) goto lab_p29_L_7D44;
  a = (uint8_t)(a + 1);
  h = (uint8_t)(h & ~(1u << 7));
  h = (uint8_t)(h | (1u << 6));
  lab_p29_L_7D44: ;
  mem_write8(0x847E, a);
  mem_write16(0x847F, hl());
  set_bc(0x0008);
  set_hl(0x8479);
  p29_L_7700();
  cpu_pop_de();
  os_bcall(0x8087);
  p29_L_5FDB();
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) | (1u << 3)));
  p29_L_6897();
  cpu_pop_af();
  set_hl(mem_read16(0x83F1));
  mem_write8(hl(), a);
  return;
}

/* flash page 29 cpu 0x7D52 (offset 0x3D52) */
void p29_L_7D52(void) {
  mem_write8(hl(), a);
  cpu_pop_de();
  os_bcall(0x8087);
  p29_L_5FDB();
  mem_write8((uint16_t)(iy + 0x26), (uint8_t)(mem_read8((uint16_t)(iy + 0x26)) | (1u << 3)));
  p29_L_6897();
  cpu_pop_af();
  set_hl(mem_read16(0x83F1));
  mem_write8(hl(), a);
  return;
}

/* flash page 29 cpu 0x7D67 (offset 0x3D67) */
void p29_L_7D67(void) {
  a = mem_read8(0x9834);
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
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
  p29_L_7C96();
  if (flag_nc()) goto lab_p29_L_7E0D;
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p29_L_7E0D;
  p29_L_7CCF();
  p29_L_4566();
  flag_cmp(a, 0xFE);
  if (flag_nz()) goto lab_p29_L_7E0D;
  p29_L_4565();
  flag_cmp(a, 0x7F);
  if (flag_nz()) goto lab_p29_L_7E0D;
  p29_L_4565();
  b = a;
  a = mem_read8(0x83EE);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p29_L_7E0D;
  if (flag_nz()) goto lab_p29_L_7DD3;
  p29_L_455C();
  cpu_push_hl();
  set_hl(mem_read16(0x84DB));
  p00_L_192A();
  cpu_ex_de_hl();
  cpu_pop_hl();
  if (flag_c()) goto lab_p29_L_7E0D;
  goto lab_p29_L_7DD9;
  lab_p29_L_7DD3: ;
  set_de(mem_read16(0x84DB));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  lab_p29_L_7DD9: ;
  a = mem_read8(0x83EE);
  b = 0x00;
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + bc()));
  p00_L_23FC();
  if (flag_nc()) goto lab_p29_L_7DE6;
  a = (uint8_t)(a + 1);
  lab_p29_L_7DE6: ;
  b = a;
  cpu_ex_de_hl();
  p29_L_4565();
  flag_cmp(a, b);
  if (flag_c()) goto lab_p29_L_7E0D;
  if (flag_nz()) goto lab_p29_L_7DFC;
  cpu_push_de();
  p29_L_455C();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  p00_L_192A();
  cpu_ex_de_hl();
  if (flag_nc()) goto lab_p29_L_7E0D;
  lab_p29_L_7DFC: ;
  set_de(mem_read16(0x84DB));
  set_hl(0x983A);
  b = 0x00;
  a = mem_read8(0x83EE);
  os_bcall(0x80C9);
  goto lab_p29_L_7E0E;
  lab_p29_L_7E0D: ;
  /* nop */
  lab_p29_L_7E0E: ;
  p29_L_5FDB();
  mem_write8(0x83EB, a);
  cpu_pop_af();
  if (flag_po()) goto lab_p29_L_7E19;
  /* ei */
  lab_p29_L_7E19: ;
  a = mem_read8(0x83EB);
  mem_write16(0x84DB, de());
  cpu_pop_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p29_L_7E2D;
  a = mem_read8(0x83EE);
  a = (uint8_t)(a + 1);
  mem_write8(0x83EE, a);
  lab_p29_L_7E2D: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  return;
}

/* flash page 29 cpu 0x7E40 (offset 0x3E40) */
void p29_L_7E40(void) {
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
  if (flag_z()) p29_L_7D67();
  return;
}

/* flash page 29 cpu 0x7FCD (offset 0x3FCD) */
void p29_L_7FCD(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  e = l;
}


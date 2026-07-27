/* Recovered from flash page 4 (mechanical ASM->C) */
/* cpu window 0x4000..0x7FFF prefix=p04_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p04_L_4000(void);
void p04_L_4008(void);
void p04_L_4017(void);
void p04_L_401B(void);
void p04_L_4025(void);
void p04_L_4029(void);
void p04_L_40A8(void);
void p04_L_40AD(void);
void p04_L_40D0(void);
void p04_L_40D5(void);
void p04_L_40E3(void);
void p04_L_4100(void);
void p04_L_4155(void);
void p04_L_4157(void);
void p04_L_41F1(void);
void p04_L_41F3(void);
void p04_L_42B3(void);
void p04_L_42EA(void);
void p04_L_4304(void);
void p04_L_4314(void);
void p04_L_431B(void);
void p04_L_4329(void);
void p04_L_4343(void);
void p04_L_434D(void);
void p04_L_4364(void);
void p04_L_438A(void);
void p04_L_438C(void);
void p04_L_4391(void);
void p04_L_43B3(void);
void p04_L_43BF(void);
void p04_L_43C2(void);
void p04_L_43C5(void);
void p04_L_43CD(void);
void p04_L_43E1(void);
void p04_L_4418(void);
void p04_L_441F(void);
void p04_L_442B(void);
void p04_L_4432(void);
void p04_L_444F(void);
void p04_L_4469(void);
void p04_L_4481(void);
void p04_L_449A(void);
void p04_L_44A0(void);
void p04_L_44E4(void);
void p04_L_44EB(void);
void p04_L_44ED(void);
void p04_L_452C(void);
void p04_L_4543(void);
void p04_L_4593(void);
void p04_L_4596(void);
void p04_L_45A5(void);
void p04_L_45BC(void);
void p04_L_45F9(void);
void p04_L_465B(void);
void p04_L_46CB(void);
void p04_L_46DD(void);
void p04_L_46DE(void);
void p04_L_4764(void);
void p04_L_4780(void);
void p04_L_47AB(void);
void p04_L_47BC(void);
void p04_L_4886(void);
void p04_L_4896(void);
void p04_L_489F(void);
void p04_L_48AE(void);
void p04_L_48B5(void);
void p04_L_48BB(void);
void p04_L_48BE(void);
void p04_L_48FE(void);
void p04_L_4A31(void);
void p04_L_4A40(void);
void p04_L_4A43(void);
void p04_L_4BBA(void);
void p04_L_4BED(void);
void p04_L_4D35(void);
void p04_L_4D37(void);
void p04_L_4D42(void);
void p04_L_4D45(void);
void p04_L_4D54(void);
void p04_L_4D5C(void);
void p04_L_4DB0(void);
void p04_L_4EDD(void);
void p04_L_4F3D(void);
void p04_L_4F71(void);
void p04_L_4FB9(void);
void p04_L_4FC8(void);
void p04_L_4FEC(void);
void p04_L_501E(void);
void p04_L_506F(void);
void p04_L_50FE(void);
void p04_L_51A2(void);
void p04_L_51AA(void);
void p04_L_51B5(void);
void p04_L_52C2(void);
void p04_L_52EC(void);
void p04_L_52F1(void);
void p04_L_5336(void);
void p04_L_5340(void);
void p04_L_53B4(void);
void p04_L_5467(void);
void p04_L_5470(void);
void p04_L_5474(void);
void p04_L_54D3(void);
void p04_L_5513(void);
void p04_L_5585(void);
void p04_L_56A0(void);
void p04_L_56B3(void);
void p04_L_56FE(void);
void p04_L_570F(void);
void p04_L_5720(void);
void p04_L_5729(void);
void p04_L_572D(void);
void p04_L_5758(void);
void p04_L_578D(void);
void p04_L_57A5(void);
void p04_L_57CD(void);
void p04_L_57FE(void);
void p04_L_5848(void);
void p04_L_5855(void);
void p04_L_586B(void);
void p04_L_5893(void);
void p04_L_58BE(void);
void p04_L_5A28(void);
void p04_L_5ADC(void);
void p04_L_5AE5(void);
void p04_L_5B86(void);
void p04_L_5BA1(void);
void p04_L_5BB6(void);
void p04_L_5BBB(void);
void p04_L_5BFB(void);
void p04_L_5C0A(void);
void p04_L_5C0F(void);
void p04_L_5C4D(void);
void p04_L_5C5D(void);
void p04_L_5C67(void);
void p04_L_5C6D(void);
void p04_L_5C7A(void);
void p04_L_5CA7(void);
void p04_L_5CB1(void);
void p04_L_5CDE(void);
void p04_L_5CEA(void);
void p04_L_5D12(void);
void p04_L_5D8C(void);
void p04_L_5DAD(void);
void p04_L_5DC6(void);
void p04_L_5DD4(void);
void p04_L_5E23(void);
void p04_L_5E32(void);
void p04_L_5E38(void);
void p04_L_5E5D(void);
void p04_L_5E6E(void);
void p04_L_5E72(void);
void p04_L_5E7C(void);
void p04_L_5E89(void);
void p04_L_5E96(void);
void p04_L_5EA3(void);
void p04_L_5EF2(void);
void p04_L_5F08(void);
void p04_L_5F1C(void);
void p04_L_5F40(void);
void p04_L_5F49(void);
void p04_L_5F65(void);
void p04_L_5F83(void);
void p04_L_5F8D(void);
void p04_L_5F96(void);
void p04_L_5FA7(void);
void p04_L_5FB9(void);
void p04_L_5FBC(void);
void p04_L_5FD1(void);
void p04_L_5FEC(void);
void p04_L_602F(void);
void p04_L_60A7(void);
void p04_L_60D8(void);
void p04_L_60DC(void);
void p04_L_60DF(void);
void p04_L_60F8(void);
void p04_L_612A(void);
void p04_L_6145(void);
void p04_L_614A(void);
void p04_L_6177(void);
void p04_L_6185(void);
void p04_L_61A6(void);
void p04_L_61DB(void);
void p04_L_6206(void);
void p04_L_6255(void);
void p04_L_6262(void);
void p04_L_6267(void);
void p04_L_626B(void);
void p04_L_6282(void);
void p04_L_634E(void);
void p04_L_63D8(void);
void p04_L_63DC(void);
void p04_L_6409(void);
void p04_L_6419(void);
void p04_L_6431(void);
void p04_L_6440(void);
void p04_L_644F(void);
void p04_L_645F(void);
void p04_L_6494(void);
void p04_L_64BD(void);
void p04_L_6580(void);
void p04_L_65AB(void);
void p04_L_65AF(void);
void p04_L_65E6(void);
void p04_L_6600(void);
void p04_L_6611(void);
void p04_L_6619(void);
void p04_ascii_map(void);
void p04_ascii_map_2(void);
void p04_L_666E(void);
void p04_L_6687(void);
void p04_L_66A5(void);
void p04_L_6700(void);
void p04_L_6715(void);
void p04_L_6721(void);
void p04_L_6726(void);
void p04_str_2(void);
void p04_str_5(void);
void p04_str_3(void);
void p04_L_674A(void);
void p04_L_6757(void);
void p04_L_6786(void);
void p04_L_678F(void);
void p04_L_6818(void);
void p04_L_6896(void);
void p04_L_6962(void);
void p04_L_6977(void);
void p04_L_6996(void);
void p04_L_69A6(void);
void p04_L_69AF(void);
void p04_L_69B7(void);
void p04_L_69EF(void);
void p04_L_6A10(void);
void p04_L_6AC3(void);
void p04_L_6B01(void);
void p04_L_6B68(void);
void p04_L_6BF0(void);
void p04_L_6C32(void);
void p04_L_6C3A(void);
void p04_L_6CA2(void);
void p04_L_6D21(void);
void p04_L_6D22(void);
void p04_L_6D3C(void);
void p04_L_6DF3(void);
void p04_L_6E96(void);
void p04_L_6F32(void);
void p04_L_6F5D(void);
void p04_L_6FA4(void);
void p04_L_6FA7(void);
void p04_L_6FAA(void);
void p04_L_6FCD(void);
void p04_L_7018(void);
void p04_L_701F(void);
void p04_L_702A(void);
void p04_L_703C(void);
void p04_L_707E(void);
void p04_L_7087(void);
void p04_L_70A9(void);
void p04_L_70C2(void);
void p04_L_70CF(void);
void p04_L_70D4(void);
void p04_L_70DF(void);
void p04_L_712A(void);
void p04_L_713E(void);
void p04_L_7146(void);
void p04_L_7151(void);
void p04_L_715C(void);
void p04_L_7162(void);
void p04_L_7168(void);
void p04_L_716A(void);
void p04_L_717B(void);
void p04_L_7180(void);
void p04_L_718E(void);
void p04_L_71DD(void);
void p04_L_71EF(void);
void p04_L_720D(void);
void p04_L_7211(void);
void p04_L_721C(void);
void p04_L_7221(void);
void p04_L_722F(void);
void p04_L_7289(void);
void p04_L_7298(void);
void p04_L_72A7(void);
void p04_L_72B6(void);
void p04_L_72C4(void);
void p04_L_72D8(void);
void p04_L_72ED(void);
void p04_L_72F9(void);
void p04_L_7302(void);
void p04_L_7473(void);
void p04_L_7478(void);
void p04_L_74A0(void);
void p04_L_74D7(void);
void p04_L_7514(void);
void p04_L_7521(void);
void p04_L_7536(void);
void p04_L_753A(void);
void p04_L_753F(void);
void p04_L_755A(void);
void p04_L_755F(void);
void p04_L_7564(void);
void p04_L_756C(void);
void p04_L_7571(void);
void p04_L_75A2(void);
void p04_L_75A9(void);
void p04_L_75B3(void);
void p04_L_75C5(void);
void p04_L_75CB(void);
void p04_L_75E1(void);
void p04_L_75EA(void);
void p04_L_75EB(void);
void p04_L_75F8(void);
void p04_L_75FE(void);
void p04_L_7603(void);
void p04_L_7613(void);
void p04_L_761E(void);
void p04_L_762E(void);
void p04_L_7636(void);
void p04_L_7640(void);
void p04_L_764E(void);
void p04_L_7651(void);
void p04_L_7661(void);
void p04_L_767A(void);
void p04_L_7685(void);
void p04_L_76A2(void);
void p04_L_76A4(void);
void p04_L_76AC(void);
void p04_L_76E8(void);
void p04_L_76F1(void);
void p04_L_7713(void);
void p04_L_7721(void);
void p04_L_7730(void);
void p04_L_7737(void);
void p04_L_775A(void);
void p04_L_7767(void);
void p04_L_77A6(void);
void p04_L_77CB(void);
void p04_L_77D9(void);
void p04_L_77FE(void);
void p04_L_7875(void);
void p04_L_787A(void);
void p04_L_787D(void);
void p04_L_7930(void);
void p04_L_793E(void);
void p04_L_794C(void);
void p04_L_795A(void);
void p04_L_7968(void);
void p04_L_797A(void);
void p04_L_797B(void);
void p04_L_797D(void);
void p04_L_7992(void);
void p04_L_7998(void);
void p04_L_79AC(void);
void p04_L_79C5(void);
void p04_L_7A03(void);
void p04_str_6(void);
void p04_str_1(void);
void p04_str_12(void);
void p04_str_4(void);
void p04_str_13(void);
void p04_str_8(void);
void p04_str_15(void);
void p04_L_7A6F(void);
void p04_str_16(void);
void p04_str_10(void);
void p04_str_7(void);
void p04_str_9(void);
void p04_str_11(void);
void p04_str_14(void);
void p04_L_7AB2(void);
void p04_L_7AE1(void);
void p04_L_7B03(void);
void p04_L_7B06(void);
void p04_L_7B09(void);
void p04_L_7B95(void);
void p04_L_7BC8(void);
void p04_L_7BE4(void);
void p04_L_7C00(void);
void p04_L_7C13(void);
void p04_L_7C8C(void);
void p04_L_7CCB(void);
void p04_L_7D14(void);
void p04_L_7D39(void);
void p04_L_7D44(void);
void p04_L_7D6C(void);
void p04_L_7D71(void);
void p04_L_7D7F(void);
void p04_L_7DDF(void);
void p04_L_7E1E(void);
void p04_L_7E35(void);
void p04_L_7F07(void);
void p04_L_7F9B(void);
void p04_L_7FA1(void);
void p04_L_7FA9(void);

/* flash page 4 cpu 0x4000 (offset 0x0000) */
void p04_L_4000(void) {
  h = 0x00;
  a = mem_read8(0x966C);
  p00_L_01AF();
  return;
}

/* flash page 4 cpu 0x4008 (offset 0x0008) */
void p04_L_4008(void) {
  set_bc(mem_read16(0x8D1A));
  e = c;
  b = 0x00;
  cpu_push_af();
  a = mem_read8(0x8DA6);
  d = a;
  cpu_pop_af();
  p04_L_4025();
  return;
}

/* flash page 4 cpu 0x4017 (offset 0x0017) */
void p04_L_4017(void) {
  set_bc(mem_read16(0x8D1A));
  p04_L_401B();
  return;
}

/* flash page 4 cpu 0x401B (offset 0x001B) */
void p04_L_401B(void) {
  cpu_push_af();
  a = mem_read8(0x8DA3);
  e = a;
  cpu_pop_af();
  e = (uint8_t)(e - 1);
  d = b;
  c = 0x01;
  p04_L_4025();
  return;
}

/* flash page 4 cpu 0x4025 (offset 0x0025) */
void p04_L_4025(void) {
  h = 0x01;
  p04_L_4029();
  return;
}

/* flash page 4 cpu 0x4029 (offset 0x0029) */
void p04_L_4029(void) {
  cpu_push_af();
  a = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_3483();
  if (flag_z()) goto lab_p04_L_4038;
  cpu_pop_af();
  return;
  lab_p04_L_4038: ;
  cpu_push_bc();
  mem_write16(0x9315, bc());
  ix = cpu_pop16();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  a = e;
  a = (uint8_t)(a - c);
  if (flag_nc()) goto lab_p04_L_404A;
  /* neg */
  h = (uint8_t)(h | (1u << 4));
  lab_p04_L_404A: ;
  l = a;
  a = d;
  a = (uint8_t)(a - b);
  if (flag_nc()) goto lab_p04_L_4053;
  /* neg */
  h = (uint8_t)(h | (1u << 5));
  lab_p04_L_4053: ;
  e = a;
  b = h;
  a = l;
  flag_cmp(a, e);
  if (flag_c()) goto lab_p04_L_405D;
  b = (uint8_t)(b | (1u << 6));
  l = e;
  e = a;
  lab_p04_L_405D: ;
  a = 0;
  flag_logic(a);
  d = a;
  h = a;
  cpu_push_hl();
  cpu_sbc_hl_de();
  set_hl((uint16_t)(hl() + hl()));
  /* ex (sp),hl */
  set_hl((uint16_t)(hl() + hl()));
  cpu_push_hl();
  cpu_sbc_hl_de();
  cpu_push16(ix);
  e = (uint8_t)(e + 1);
  a = b;
  a = a & 0x0F;
  flag_logic(a);
  d = a;
  a = b;
  cpu_pop_bc();
  ix = 0x0000;
  cpu_add_ix_sp();
  lab_p04_L_4078: ;
  p04_L_4157();
  cpu_push_bc();
  flag_set_z((h & (1u << 7)) == 0);
  if (flag_z()) goto lab_p04_L_4091;
  c = mem_read8(ix);
  b = mem_read8((uint16_t)(ix + 0x01));
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_bc();
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_409C;
  p04_L_4314();
  goto lab_p04_L_40A3;
  lab_p04_L_4091: ;
  c = mem_read8((uint16_t)(ix + 0x02));
  b = mem_read8((uint16_t)(ix + 0x03));
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_bc();
  p04_L_4314();
  lab_p04_L_409C: ;
  c = (uint8_t)(c + 1);
  flag_set_z((a & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_40A3;
  c = (uint8_t)(c - 1);
  c = (uint8_t)(c - 1);
  lab_p04_L_40A3: ;
  e = (uint8_t)(e - 1);
  if (flag_nz()) goto lab_p04_L_4078;
  cpu_pop_hl();
  cpu_pop_hl();
  p04_L_40A8();
  return;
}

/* flash page 4 cpu 0x40A8 (offset 0x00A8) */
void p04_L_40A8(void) {
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 4 cpu 0x40AD (offset 0x00AD) */
void p04_L_40AD(void) {
  set_hl(0x9668);
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_40EB;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p04_L_40BF;
  a = 0x02;
  mem_write8(0x966C, a);
  lab_p04_L_40BF: ;
  l = b;
  p04_L_4000();
  e = a;
  a = mem_read8(0x966C);
  a = (uint8_t)(a - 1);
  flag_cmp(a, e);
  if (flag_nz()) return;
  a = 0x01;
  mem_write8(0x966C, a);
  a = 0;
  flag_logic(a);
  p04_L_40D0();
  return;
  lab_p04_L_40EB: ;
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p04_L_4115;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p04_L_40FA;
  a = 0x02;
  mem_write8(0x966C, a);
  lab_p04_L_40FA: ;
  l = c;
  p04_L_4000();
  set_hl(0x9775);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_410D;
  e = a;
  a = mem_read8(0x966C);
  a = (uint8_t)(a - 1);
  a = (uint8_t)(a - e);
  p04_L_40D0();
  return;
  lab_p04_L_410D: ;
  cpu_push_af();
  a = mem_read8(0x966C);
  e = a;
  cpu_pop_af();
  p04_L_40D0();
  return;
  lab_p04_L_4115: ;
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p04_L_4121;
  a = 0x03;
  mem_write8(0x966C, a);
  lab_p04_L_4121: ;
  l = c;
  p04_L_4000();
  cpu_push_af();
  l = b;
  p04_L_4000();
  cpu_pop_de();
  e = a;
  cpu_pop_af();
  if (flag_z()) goto lab_p04_L_4135;
  a = e;
  a = (uint8_t)(a - d);
  if (flag_nc()) goto lab_p04_L_4143;
  goto lab_p04_L_413E;
  lab_p04_L_4135: ;
  a = e;
  a = mem_read8(0x966C);
  a = (uint8_t)(a - 1);
  a = (uint8_t)(a - e);
  a = (uint8_t)(a - d);
  if (flag_nc()) goto lab_p04_L_4143;
  lab_p04_L_413E: ;
  e = a;
  a = mem_read8(0x966C);
  a = (uint8_t)(a + e);
  lab_p04_L_4143: ;
  set_hl(0x9775);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_z()) { p04_L_40D0(); return; }
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p04_L_40D0(); return; }
  e = a;
  a = mem_read8(0x966C);
  a = (uint8_t)(a - e);
  p04_L_40D0();
  return;
}

/* flash page 4 cpu 0x40D0 (offset 0x00D0) */
void p04_L_40D0(void) {
  set_hl(0x9775);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  p04_L_40D5();
  return;
}

/* flash page 4 cpu 0x40D5 (offset 0x00D5) */
void p04_L_40D5(void) {
  if (flag_z()) goto lab_p04_L_40D9;
  /* neg */
  lab_p04_L_40D9: ;
  a = (uint8_t)(a + c);
  if (flag_z()) return;
  c = a;
  set_hl(0x966D);
  cpu_cp_hl();
  if (flag_nc()) return;
  d = 0x01;
  p04_L_40E3();
  return;
}

/* flash page 4 cpu 0x40E3 (offset 0x00E3) */
void p04_L_40E3(void) {
  p04_L_41F1();
  a = mem_read8(0x966C);
  p04_L_40D0();
  return;
}

/* flash page 4 cpu 0x4100 (offset 0x0100) */
void p04_L_4100(void) {
  a = 0;
  flag_logic(a);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_410D;
  e = a;
  a = mem_read8(0x966C);
  a = (uint8_t)(a - 1);
  a = (uint8_t)(a - e);
  p04_L_40D0();
  return;
  lab_p04_L_410D: ;
  cpu_push_af();
  a = mem_read8(0x966C);
  e = a;
  cpu_pop_af();
  p04_L_40D0();
  return;
}

/* flash page 4 cpu 0x4155 (offset 0x0155) */
void p04_L_4155(void) {
  d = 0x01;
  p04_L_4157();
  return;
}

/* flash page 4 cpu 0x4157 (offset 0x0157) */
void p04_L_4157(void) {
  cpu_push_af();
  a = 0x00;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_3483();
  if (flag_z()) goto lab_p04_L_4166;
  cpu_pop_af();
  return;
  lab_p04_L_4166: ;
  cpu_push_bc();
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 5)) == 0);
  if (flag_z()) { p04_L_41F3(); return; }
  a = mem_read8(0x9775);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p04_L_418A;
  if (flag_c()) { p04_L_41F3(); return; }
  flag_cmp(a, 0x04);
  if (flag_nc()) { p04_L_41F3(); return; }
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 6)));
  cpu_push_hl();
  cpu_push_de();
  p04_L_40AD();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_bc();
  goto lab_p04_L_41F2;
  lab_p04_L_418A: ;
  p04_L_41F1();
  cpu_push_hl();
  cpu_push_bc();
  a = c;
  set_bc(mem_read16(0x9315));
  flag_cmp(a, c);
  if (flag_z()) goto lab_p04_L_41C0;
  if (flag_c()) goto lab_p04_L_41A9;
  b = (uint8_t)(b + 1);
  p04_L_41F1();
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c - 1);
  cpu_pop_af();
  flag_cmp(a, b);
  if (flag_z()) goto lab_p04_L_41D2;
  if (flag_c()) goto lab_p04_L_41D3;
  c = (uint8_t)(c - 1);
  goto lab_p04_L_41D4;
  lab_p04_L_41A9: ;
  b = (uint8_t)(b + 1);
  p04_L_41F1();
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c - 1);
  p04_L_41F1();
  cpu_pop_af();
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p04_L_41D7;
  b = (uint8_t)(b + 1);
  goto lab_p04_L_41D4;
  lab_p04_L_41C0: ;
  cpu_pop_af();
  c = (uint8_t)(c - 1);
  flag_cmp(a, b);
  if (flag_z()) goto lab_p04_L_41D7;
  cpu_push_af();
  p04_L_41F1();
  cpu_pop_af();
  if (flag_c()) goto lab_p04_L_41CF;
  b = (uint8_t)(b + 1);
  goto lab_p04_L_41D4;
  lab_p04_L_41CF: ;
  b = (uint8_t)(b - 1);
  goto lab_p04_L_41D4;
  lab_p04_L_41D2: ;
  b = (uint8_t)(b + 1);
  lab_p04_L_41D3: ;
  c = (uint8_t)(c + 1);
  lab_p04_L_41D4: ;
  p04_L_41F1();
  lab_p04_L_41D7: ;
  cpu_pop_hl();
  cpu_pop_bc();
  mem_write16(0x9315, bc());
  cpu_pop_af();
  return;
  lab_p04_L_41F2: ;
  cpu_push_bc();
  p04_L_41F3();
  return;
}

/* flash page 4 cpu 0x41F1 (offset 0x01F1) */
void p04_L_41F1(void) {
  cpu_push_af();
  cpu_push_bc();
  p04_L_41F3();
  return;
}

/* flash page 4 cpu 0x41F3 (offset 0x01F3) */
void p04_L_41F3(void) {
  goto lab_p04_L_41F3;
  lab_p04_L_40A6: ;
  cpu_pop_hl();
  cpu_pop_hl();
  p04_L_40A8();
  return;
  lab_p04_L_41F3: ;
  a = mem_read8(0x8DA1);
  a = (uint8_t)(a + b);
  b = a;
  a = mem_read8(0x8DA2);
  a = (uint8_t)(a + c);
  c = a;
  cpu_push_de();
  cpu_push_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x2B)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_420A;
  p04_L_4304();
  goto lab_p04_L_420D;
  lab_p04_L_420A: ;
  p04_L_42EA();
  lab_p04_L_420D: ;
  if (flag_c()) { p04_L_40A8(); return; }
  p04_L_42B3();
  b = d;
  c = a;
  cpu_ex_de_hl();
  set_hl(0x9872);
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x3C)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_4224;
  cpu_push_hl();
  goto lab_p04_L_4251;
  lab_p04_L_4224: ;
  set_hl(0x9340);
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x3C)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_4251;
  /* di */
  a = mem_read8(0x8451);
  p00_lcd_cmd_07();
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p00_lcd_cmd_05();
  a = mem_read8(0x844F);
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  p00_L_3C69();
  cpu_pop_hl();
  cpu_push_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_4252;
  lab_p04_L_4251: ;
  a = mem_read8(hl());
  lab_p04_L_4252: ;
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_4258;
  lab_p04_L_4255: ;
  a = a | c;
  flag_logic(a);
  goto lab_p04_L_425F;
  lab_p04_L_4258: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_425D;
  lab_p04_L_425A: ;
  a = a | c;
  flag_logic(a);
  goto lab_p04_L_4260;
  lab_p04_L_425D: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_429A;
  lab_p04_L_425F: ;
  a = a ^ c;
  flag_logic(a);
  lab_p04_L_4260: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x3C)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p04_L_426C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x3C)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_4270;
  lab_p04_L_426C: ;
  cpu_pop_hl();
  /* ei */
  goto lab_p04_L_428E;
  lab_p04_L_4270: ;
  h = a;
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_4280;
  a = mem_read8(0x844F);
  flag_cmp(a, 0x25);
  a = h;
  if (flag_nz()) goto lab_p04_L_4280;
  a = a | 0x01;
  flag_logic(a);
  lab_p04_L_4280: ;
  p00_lcd_busy_wait();
  lcd_write_data(); /* ti_lcd_op_write(a) */
  a = h;
  cpu_pop_hl();
  /* ei */
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_428F;
  lab_p04_L_428E: ;
  mem_write8(hl(), a);
  lab_p04_L_428F: ;
  cpu_pop_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x3C)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_4297;
  mem_write8(hl(), a);
  lab_p04_L_4297: ;
  p04_L_40A8();
  return;
  lab_p04_L_429A: ;
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p04_L_42A7;
  a = mem_read8(hl());
  a = a & c;
  flag_logic(a);
  /* ei */
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_hl();
  cpu_pop_hl();
  return;
  lab_p04_L_42A7: ;
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p04_L_40A6;
  b = a;
  a = mem_read8(hl());
  a = a & c;
  flag_logic(a);
  a = b;
  if (flag_z()) goto lab_p04_L_4255;
  goto lab_p04_L_425A;
}

/* flash page 4 cpu 0x42B3 (offset 0x02B3) */
void p04_L_42B3(void) {
  cpu_push_de();
  set_hl(0x42E2);
  d = 0x00;
  a = b;
  a = a & 0x07;
  flag_logic(a);
  e = a;
  set_hl((uint16_t)(hl() + de()));
  e = mem_read8(hl());
  h = d;
  /* srl b */
  /* srl b */
  /* srl b */
  a = b;
  a = a | 0x20;
  flag_logic(a);
  mem_write8(0x844F, a);
  a = 0x3F;
  a = (uint8_t)(a - c);
  a = a | 0x80;
  flag_logic(a);
  mem_write8(0x8451, a);
  a = a & 0x7F;
  flag_logic(a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  c = a;
  l = a;
  set_hl((uint16_t)(hl() + hl()));
  a = e;
  e = c;
  set_hl((uint16_t)(hl() + de()));
  e = b;
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_de();
  return;
}

/* flash page 4 cpu 0x42EA (offset 0x02EA) */
void p04_L_42EA(void) {
  cpu_push_af();
  cpu_push_hl();
  set_hl(mem_read16(0x8DA3));
  h = (uint8_t)(h - 1);
  a = b;
  flag_cmp(a, h);
  if (flag_nc()) goto lab_p04_L_4300;
  a = c;
  flag_cmp(a, 0x40);
  if (flag_nc()) goto lab_p04_L_4300;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_4300;
  cpu_pop_hl();
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  return;
  lab_p04_L_4300: ;
  cpu_pop_hl();
  cpu_pop_af();
  /* scf */
  return;
}

/* flash page 4 cpu 0x4304 (offset 0x0304) */
void p04_L_4304(void) {
  goto lab_p04_L_4304;
  lab_p04_L_42FC: ;
  cpu_pop_hl();
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  return;
  lab_p04_L_4300: ;
  cpu_pop_hl();
  cpu_pop_af();
  /* scf */
  return;
  lab_p04_L_4304: ;
  cpu_push_af();
  cpu_push_hl();
  set_hl(mem_read16(0x8DA3));
  a = b;
  flag_cmp(a, h);
  if (flag_nc()) goto lab_p04_L_4300;
  a = c;
  flag_cmp(a, 0x40);
  if (flag_nc()) goto lab_p04_L_4300;
  goto lab_p04_L_42FC;
}

/* flash page 4 cpu 0x4314 (offset 0x0314) */
void p04_L_4314(void) {
  b = (uint8_t)(b + 1);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) return;
  b = (uint8_t)(b - 1);
  b = (uint8_t)(b - 1);
  return;
}

/* flash page 4 cpu 0x431B (offset 0x031B) */
void p04_L_431B(void) {
  set_hl(mem_read16(0x9824));
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  p04_L_4329();
  cpu_pop_hl();
  if (flag_nz()) return;
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  p04_L_4329();
  return;
}

/* flash page 4 cpu 0x4329 (offset 0x0329) */
void p04_L_4329(void) {
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_nz()) return;
  cpu_push_hl();
  p00_rst20();
  p00_L_3E37();
  a = mem_read8(0x8479);
  flag_cmp(a, 0xE4);
  if (flag_nc()) goto lab_p04_L_433E;
  cpu_pop_de();
  p00_L_11FD();
  a = 0;
  flag_logic(a);
  return;
  lab_p04_L_433E: ;
  cpu_pop_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  h = (uint8_t)(h + 1);
  return;
}

/* flash page 4 cpu 0x4343 (offset 0x0343) */
void p04_L_4343(void) {
  set_hl(mem_read16(0x9824));
  set_de(0xFFF7);
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  p04_L_434D();
  return;
}

/* flash page 4 cpu 0x434D (offset 0x034D) */
void p04_L_434D(void) {
  cpu_push_de();
  cpu_push_hl();
  cpu_ex_de_hl();
  a = 0;
  flag_logic(a);
  set_de(0x8F50);
  p04_L_4364();
  /* sla a */
  /* sla a */
  set_de(0x8F6B);
  cpu_pop_hl();
  p04_L_4364();
  cpu_pop_de();
  return;
}

/* flash page 4 cpu 0x4364 (offset 0x0364) */
void p04_L_4364(void) {
  cpu_push_hl();
  cpu_push_af();
  cpu_push_de();
  p00_rst20();
  cpu_pop_hl();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1183();
  cpu_push_hl();
  p00_L_107E();
  if (flag_nc()) goto lab_p04_L_437A;
  cpu_pop_hl();
  cpu_pop_af();
  a = a | 0x02;
  flag_logic(a);
  goto lab_p04_L_4388;
  lab_p04_L_437A: ;
  p00_rst08();
  cpu_pop_hl();
  p00_rst20();
  p00_L_107E();
  if (flag_nc()) goto lab_p04_L_4387;
  cpu_pop_af();
  a = a | 0x01;
  flag_logic(a);
  goto lab_p04_L_4388;
  lab_p04_L_4387: ;
  cpu_pop_af();
  lab_p04_L_4388: ;
  cpu_pop_hl();
  return;
}

/* flash page 4 cpu 0x438A (offset 0x038A) */
void p04_L_438A(void) {
  a = 0x01;
  p04_L_438C();
  return;
}

/* flash page 4 cpu 0x438C (offset 0x038C) */
void p04_L_438C(void) {
  cpu_push_af();
  p00_L_222C();
  cpu_pop_af();
  p04_L_4391();
  return;
}

/* flash page 4 cpu 0x4391 (offset 0x0391) */
void p04_L_4391(void) {
  cpu_push_af();
  set_de(0xFFF7);
  p04_L_431B();
  if (flag_nz()) goto lab_p04_L_43AF;
  p04_L_4343();
  a = a & 0x0F;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_43AF;
  p04_L_43B3();
  cpu_pop_de();
  mem_write16(0x9315, bc());
  p04_L_4157();
  p00_L_21A4();
  return;
  lab_p04_L_43AF: ;
  cpu_pop_hl();
  p00_L_21A4();
  return;
}

/* flash page 4 cpu 0x43B3 (offset 0x03B3) */
void p04_L_43B3(void) {
  cpu_push_hl();
  p04_L_442B();
  cpu_pop_de();
  cpu_push_af();
  p04_L_441F();
  cpu_pop_bc();
  c = a;
  return;
}

/* flash page 4 cpu 0x43BF (offset 0x03BF) */
void p04_L_43BF(void) {
  set_hl(0x8499);
  p04_L_43C2();
  return;
}

/* flash page 4 cpu 0x43C2 (offset 0x03C2) */
void p04_L_43C2(void) {
  set_de(0x8478);
  p04_L_43C5();
  return;
}

/* flash page 4 cpu 0x43C5 (offset 0x03C5) */
void p04_L_43C5(void) {
  cpu_push_de();
  cpu_push_bc();
  a = c;
  p04_L_43E1();
  cpu_pop_af();
  cpu_pop_hl();
  p04_L_43CD();
  return;
}

/* flash page 4 cpu 0x43CD (offset 0x03CD) */
void p04_L_43CD(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p04_L_43D5;
  /* neg */
  lab_p04_L_43D5: ;
  set_bc(0x8E6A);
  set_de(0x9152);
  cpu_push_hl();
  l = a;
  a = 0xFF;
  goto lab_p04_L_43EA;
  lab_p04_L_43EA: ;
  h = 0x00;
  cpu_push_bc();
  cpu_push_af();
  cpu_push_de();
  p00_L_3B55();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_0E5C();
  cpu_pop_hl();
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  if (flag_nz()) goto lab_p04_L_4406;
  cpu_push_hl();
  set_hl(0x8E73);
  p00_rst20();
  p00_rst30();
  p00_rst08();
  cpu_pop_hl();
  lab_p04_L_4406: ;
  p00_rst20();
  p00_L_0D1F();
  p00_L_3E37();
  cpu_pop_hl();
  p00_L_0BEC();
  p00_L_15FB();
  cpu_pop_de();
  p00_L_11FD();
  return;
}

/* flash page 4 cpu 0x43E1 (offset 0x03E1) */
void p04_L_43E1(void) {
  set_bc(0x8F6B);
  set_de(0x915B);
  a = (uint8_t)(a - 1);
  cpu_push_hl();
  l = a;
  h = 0x00;
  cpu_push_bc();
  cpu_push_af();
  cpu_push_de();
  p00_L_3B55();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_0E5C();
  cpu_pop_hl();
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  if (flag_nz()) goto lab_p04_L_4406;
  cpu_push_hl();
  set_hl(0x8E73);
  p00_rst20();
  p00_rst30();
  p00_rst08();
  cpu_pop_hl();
  lab_p04_L_4406: ;
  p00_rst20();
  p00_L_0D1F();
  p00_L_3E37();
  cpu_pop_hl();
  p00_L_0BEC();
  p00_L_15FB();
  cpu_pop_de();
  p00_L_11FD();
  return;
}

/* flash page 4 cpu 0x4418 (offset 0x0418) */
void p04_L_4418(void) {
  goto lab_p04_L_4418;
  lab_p04_L_43EC: ;
  cpu_push_bc();
  cpu_push_af();
  cpu_push_de();
  p00_L_3B55();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_0E5C();
  cpu_pop_hl();
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  if (flag_nz()) goto lab_p04_L_4406;
  cpu_push_hl();
  set_hl(0x8E73);
  p00_rst20();
  p00_rst30();
  p00_rst08();
  cpu_pop_hl();
  lab_p04_L_4406: ;
  p00_rst20();
  p00_L_0D1F();
  p00_L_3E37();
  cpu_pop_hl();
  p00_L_0BEC();
  p00_L_15FB();
  cpu_pop_de();
  p00_L_11FD();
  return;
  lab_p04_L_4418: ;
  cpu_push_hl();
  set_hl(mem_read16(0x8E67));
  a = 0;
  flag_logic(a);
  goto lab_p04_L_43EC;
}

/* flash page 4 cpu 0x441F (offset 0x041F) */
void p04_L_441F(void) {
  set_bc(0x8F6B);
  set_hl(0x916D);
  a = a | a;
  flag_logic(a);
  p04_L_4432();
  a = (uint8_t)(a + 1);
  return;
}

/* flash page 4 cpu 0x442B (offset 0x042B) */
void p04_L_442B(void) {
  set_bc(0x8E6A);
  set_hl(0x9164);
  /* scf */
  p04_L_4432();
  return;
}

/* flash page 4 cpu 0x4432 (offset 0x0432) */
void p04_L_4432(void) {
  cpu_push_af();
  cpu_push_hl();
  cpu_push_bc();
  cpu_ex_de_hl();
  p00_rst20();
  cpu_pop_hl();
  p00_L_0C25();
  cpu_pop_hl();
  p00_L_0D19();
  cpu_pop_af();
  if (flag_nc()) goto lab_p04_L_4448;
  set_hl(0x8E73);
  p00_L_0C25();
  lab_p04_L_4448: ;
  p04_L_4469();
  p00_L_3B5B();
  return;
}

/* flash page 4 cpu 0x444F (offset 0x044F) */
void p04_L_444F(void) {
  goto lab_p04_L_444F;
  lab_p04_L_4442: ;
  set_hl(0x8E73);
  p00_L_0C25();
  p04_L_4469();
  p00_L_3B5B();
  return;
  lab_p04_L_444F: ;
  set_hl(0x8E6A);
  p00_L_0C25();
  set_hl(0x9164);
  p00_L_0D19();
  set_hl(0x900D);
  p00_L_0EC1();
  p00_L_0FAF();
  p00_L_0D1F();
  goto lab_p04_L_4442;
}

/* flash page 4 cpu 0x4469 (offset 0x0469) */
void p04_L_4469(void) {
  a = mem_read8(0x8479);
  a = (uint8_t)(a - 0x7F);
  if (flag_c()) goto lab_p04_L_4497;
  if (flag_z()) goto lab_p04_L_4490;
  b = 0x02;
  set_hl(0x847B);
  flag_cmp(a, 0x02);
  a = 0x50;
  if (flag_z()) { p04_L_4481(); return; }
  a = 0x05;
  b = (uint8_t)(b - 1);
  set_hl((uint16_t)(hl() - 1));
  p04_L_4481();
  return;
  lab_p04_L_4485: ;
  set_hl(0x847A);
  mem_write8(hl(), 0x10);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x00);
  p00_L_15F3();
  return;
  lab_p04_L_4490: ;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x50);
  if (flag_nc()) goto lab_p04_L_4485;
  lab_p04_L_4497: ;
  p00_L_128A();
  return;
}

/* flash page 4 cpu 0x4481 (offset 0x0481) */
void p04_L_4481(void) {
  p00_L_1377();
  if (flag_nc()) return;
  set_hl(0x847A);
  mem_write8(hl(), 0x10);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x00);
  p00_L_15F3();
  return;
}

/* flash page 4 cpu 0x449A (offset 0x049A) */
void p04_L_449A(void) {
  a = 0;
  flag_logic(a);
  p04_L_63D8();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 4 cpu 0x44A0 (offset 0x04A0) */
void p04_L_44A0(void) {
  b = a;
  a = 0x00;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_330F();
  cpu_push_bc();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 4)));
  set_hl(0x4516);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 3)));
  cpu_pop_af();
  set_hl(0x4523);
  set_bc(0x0009);
  /* cpir */
  if (flag_z()) { p04_L_44E4(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_44E1;
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p04_L_44E4(); return; }
  flag_cmp(a, 0x06);
  if (flag_c()) goto lab_p04_L_44DE;
  flag_cmp(a, 0x07);
  if (flag_z()) goto lab_p04_L_44DE;
  flag_cmp(a, 0x05);
  if (flag_nz()) { p04_L_44E4(); return; }
  return;
  lab_p04_L_44DE: ;
  p04_L_678F();
  lab_p04_L_44E1: ;
  p04_L_452C();
  p04_L_44E4();
  return;
}

/* flash page 4 cpu 0x44E4 (offset 0x04E4) */
void p04_L_44E4(void) {
  p04_L_6715();
  p04_L_5CEA();
  return;
}

/* flash page 4 cpu 0x44EB (offset 0x04EB) */
void p04_L_44EB(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  cpu_push_hl();
  cpu_push_af();
  a = mem_read8(0x8DA4);
  /* srl a */
  a = (uint8_t)(a - 1);
  h = a;
  cpu_pop_af();
  l = 0x20;
  p00_L_17CE();
  if (flag_z()) goto lab_p04_L_4503;
  l = 0x10;
  lab_p04_L_4503: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p04_L_450B;
  l = 0x1A;
  lab_p04_L_450B: ;
  mem_write16(0x8D18, hl());
  mem_write16(0x8D1C, hl());
  mem_write16(0x8D1A, hl());
  cpu_pop_hl();
  return;
}

/* flash page 4 cpu 0x44ED (offset 0x04ED) */
void p04_L_44ED(void) {
  mem_write8(bc(), a);
  b = mem_read8(hl());
  if (flag_nz()) return;
  cpu_push_hl();
  cpu_push_af();
  a = mem_read8(0x8DA4);
  /* srl a */
  a = (uint8_t)(a - 1);
  h = a;
  cpu_pop_af();
  l = 0x20;
  p00_L_17CE();
  if (flag_z()) goto lab_p04_L_4503;
  l = 0x10;
  lab_p04_L_4503: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p04_L_450B;
  l = 0x1A;
  lab_p04_L_450B: ;
  mem_write16(0x8D18, hl());
  mem_write16(0x8D1C, hl());
  mem_write16(0x8D1A, hl());
  cpu_pop_hl();
  return;
}

/* flash page 4 cpu 0x452C (offset 0x052C) */
void p04_L_452C(void) {
  return;
}

/* flash page 4 cpu 0x4543 (offset 0x0543) */
void p04_L_4543(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_4555;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_4555;
  set_hl(mem_read16(0x85AA));
  a = h;
  flag_cmp(a, l);
  if (flag_nz()) return;
  lab_p04_L_4555: ;
  p04_L_6185();
  p04_L_48BB();
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 0)) == 0);
  if (flag_z()) return;
  p00_L_3D89();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) return;
  a = mem_read8(0x8D1B);
  p04_L_77FE();
  p04_L_48FE();
  return;
}

/* flash page 4 cpu 0x4593 (offset 0x0593) */
void p04_L_4593(void) {
  p00_L_3315();
  p04_L_4596();
  return;
}

/* flash page 4 cpu 0x4596 (offset 0x0596) */
void p04_L_4596(void) {
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 5)));
  set_hl(0x25A1);
  mem_write16(0x8595, hl());
  return;
}

/* flash page 4 cpu 0x45A5 (offset 0x05A5) */
void p04_L_45A5(void) {
  b = a;
  a = 0x06;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_330F();
  if (flag_nz()) return;
  a = b;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_46FA;
  p04_L_45BC();
  return;
  lab_p04_L_46FA: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_4706;
  set_hl(mem_read16(0x8D1C));
  mem_write16(0x8D18, hl());
  lab_p04_L_4706: ;
  flag_cmp(a, 0x7F);
  if (flag_c()) { p04_L_47BC(); return; }
  b = a;
  a = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_330F();
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_474E;
  a = mem_read8(0x8E63);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_474E;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x65);
  if (flag_z()) goto lab_p04_L_474E;
  flag_cmp(a, 0x67);
  if (flag_z()) goto lab_p04_L_474E;
  set_hl(mem_read16(0x980C));
  mem_write16(0x9824, hl());
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 2)));
  cpu_push_bc();
  cpu_push_af();
  p04_L_4F71();
  cpu_pop_af();
  mem_write8(0x8D17, a);
  mem_write8(0x85FD, a);
  p04_L_48FE();
  cpu_pop_af();
  p04_L_45BC();
  return;
  lab_p04_L_474E: ;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x2F);
  a = b;
  if (flag_nz()) { p00_L_05F2(); return; }
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  p00_L_3BBB();
  p04_L_4764();
  p04_L_489F();
  return;
}

/* flash page 4 cpu 0x45BC (offset 0x05BC) */
void p04_L_45BC(void) {
  flag_cmp(a, 0xFE);
  if (flag_z()) { p00_L_3777(); return; }
  flag_cmp(a, 0x0C);
  if (flag_z()) return;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p04_L_45DA;
  flag_cmp(a, 0x09);
  if (flag_nz()) { p00_L_3777(); return; }
  p00_L_1916();
  if (flag_z()) goto lab_p04_L_45DF;
  p00_L_03A0();
  p00_L_378F();
  return;
  lab_p04_L_45DA: ;
  p00_L_1916();
  if (flag_nz()) goto lab_p04_L_45E8;
  lab_p04_L_45DF: ;
  p04_L_4593();
  p04_L_6185();
  p04_L_5720();
  return;
  lab_p04_L_45E8: ;
  p00_L_002B();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 3)));
  p00_L_331B();
  p00_L_1851();
  /* scf */
  p04_L_5AE5();
  p04_L_45F9();
  return;
}

/* flash page 4 cpu 0x45F9 (offset 0x05F9) */
void p04_L_45F9(void) {
  p00_L_37CB();
  p00_L_219B();
  a = 0x4F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_460A;
  a = mem_read8(0x85FD);
  lab_p04_L_460A: ;
  mem_write8(0x8D17, a);
  p04_L_4596();
  a = mem_read8(0x8D17);
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 4)));
  flag_cmp(a, 0x4F);
  if (flag_nz()) goto lab_p04_L_461F;
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) | (1u << 4)));
  lab_p04_L_461F: ;
  flag_cmp(a, 0x52);
  if (flag_c()) { p04_L_465B(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 3)) == 0);
  if (flag_nz()) { p04_L_465B(); return; }
  p00_rst18();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 5)));
  p04_L_465B();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 5)));
  set_hl(mem_read16(0x980C));
  mem_write16(0x9824, hl());
  p00_L_219B();
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x7D);
  if (flag_z()) goto lab_p04_L_464D;
  flag_cmp(a, 0x6F);
  if (flag_c()) goto lab_p04_L_4652;
  flag_cmp(a, 0x74);
  if (flag_nc()) goto lab_p04_L_4652;
  lab_p04_L_464D: ;
  p04_L_5CA7();
  if (flag_nz()) { p04_L_465B(); return; }
  lab_p04_L_4652: ;
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 0)));
  a = 0x05;
  p04_L_45A5();
  p04_L_465B();
  return;
}

/* flash page 4 cpu 0x465B (offset 0x065B) */
void p04_L_465B(void) {
  set_hl(0x0000);
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_468B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_4686;
  p00_rst18();
  p04_L_501E();
  p00_L_10DD();
  p00_L_2196();
  p00_L_0C13();
  set_hl(0x9004);
  p00_L_0EC1();
  p00_L_0FAF();
  p00_L_0D1F();
  p00_L_10EF();
  p00_rst30();
  lab_p04_L_4686: ;
  p04_L_6726();
  goto lab_p04_L_46CC;
  lab_p04_L_468B: ;
  p00_L_0013();
  if (flag_nz()) goto lab_p04_L_46B6;
  set_hl(0x8F86);
  p00_L_0198();
  if (flag_nz()) goto lab_p04_L_469B;
  set_hl(0x8FA1);
  lab_p04_L_469B: ;
  p00_L_11F8();
  cpu_push_hl();
  p00_L_0C2D();
  cpu_pop_hl();
  set_de(0x0009);
  set_hl((uint16_t)(hl() + de()));
  p00_L_0EC1();
  p00_L_0FAF();
  p00_L_3B5B();
  cpu_ex_de_hl();
  mem_write16(0x8E2B, hl());
  goto lab_p04_L_46CC;
  lab_p04_L_46B6: ;
  p00_rst18();
  p04_L_444F();
  l = a;
  h = 0x00;
  mem_write16(0x8E2B, hl());
  p00_L_219B();
  set_de(0x8478);
  p04_L_442B();
  l = a;
  h = 0x00;
  lab_p04_L_46CC: ;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 0)));
  p04_L_506F();
  return;
}

/* flash page 4 cpu 0x46CB (offset 0x06CB) */
void p04_L_46CB(void) {
  /* nop */
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 0)));
  p04_L_506F();
  return;
}

/* flash page 4 cpu 0x46DD (offset 0x06DD) */
void p04_L_46DD(void) {
  b = l;
  p04_L_46DE();
  return;
}

/* flash page 4 cpu 0x46DE (offset 0x06DE) */
void p04_L_46DE(void) {
  p00_L_0013();
  if (flag_nz()) p00_L_16A2();
  p00_L_01A2();
  if (flag_nz()) p00_L_16AA();
  p00_L_0198();
  if (flag_nz()) p00_L_1689();
  p00_L_019D();
  if (flag_nz()) p00_L_1697();
  p00_L_38B5();
  return;
}

/* flash page 4 cpu 0x4764 (offset 0x0764) */
void p04_L_4764(void) {
  set_bc(mem_read16(0x8D18));
  cpu_push_bc();
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p04_L_478B;
  cpu_push_de();
  a = mem_read8(0x8DA3);
  a = (uint8_t)(a - 1);
  a = (uint8_t)(a - c);
  c = b;
  b = a;
  mem_write16(0x86D7, bc());
  cpu_pop_de();
  cpu_push_de();
  cpu_push_bc();
  p04_L_47AB();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 7)));
  cpu_pop_bc();
  cpu_pop_de();
  mem_write16(0x86D7, bc());
  lab_p04_L_478B: ;
  p04_L_47AB();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 7)));
  a = mem_read8(0x86D7);
  cpu_pop_bc();
  b = a;
  if (flag_nc()) goto lab_p04_L_479D;
  flag_cmp(a, 0x5F);
  if (flag_c()) goto lab_p04_L_47A6;
  lab_p04_L_479D: ;
  p00_L_18B7();
  b = 0x2E;
  if (flag_nz()) goto lab_p04_L_47A6;
  b = 0x5E;
  lab_p04_L_47A6: ;
  mem_write16(0x8D18, bc());
  return;
}

/* flash page 4 cpu 0x4780 (offset 0x0780) */
void p04_L_4780(void) {
  b = a;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 7)));
  cpu_pop_bc();
  cpu_pop_de();
  mem_write16(0x86D7, bc());
  p04_L_47AB();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 7)));
  a = mem_read8(0x86D7);
  cpu_pop_bc();
  b = a;
  if (flag_nc()) goto lab_p04_L_479D;
  flag_cmp(a, 0x5F);
  if (flag_c()) goto lab_p04_L_47A6;
  lab_p04_L_479D: ;
  p00_L_18B7();
  b = 0x2E;
  if (flag_nz()) goto lab_p04_L_47A6;
  b = 0x5E;
  lab_p04_L_47A6: ;
  mem_write16(0x8D18, bc());
  return;
}

/* flash page 4 cpu 0x47AB (offset 0x07AB) */
void p04_L_47AB(void) {
  p00_L_3DAD();
  set_hl((uint16_t)(hl() + 1));
  b = a;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 4)));
  p00_L_3D59();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 4)));
  return;
}

/* flash page 4 cpu 0x47BC (offset 0x07BC) */
void p04_L_47BC(void) {
  b = a;
  a = 0x07;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_330F();
  if (flag_nz()) return;
  a = b;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  flag_cmp(a, 0x05);
  if (flag_c()) goto lab_p04_L_47E6;
  flag_cmp(a, 0x0E);
  if (flag_c()) goto lab_p04_L_4A51;
  flag_cmp(a, 0x10);
  if (flag_nc()) goto lab_p04_L_4A51;
  lab_p04_L_47E6: ;
  d = a;
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_330F();
  if (flag_nz()) return;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x4D);
  if (flag_z()) goto lab_p04_L_4811;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_4817;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p04_L_4811;
  flag_cmp(a, 0x4F);
  a = d;
  if (flag_nz()) goto lab_p04_L_51D0;
  flag_cmp(a, 0x03);
  lab_p04_L_480A: ;
  if (flag_z()) goto lab_p04_L_51D0;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p04_L_480A;
  lab_p04_L_4811: ;
  p00_L_3EFD();
  p04_L_5CEA();
  lab_p04_L_4817: ;
  a = mem_read8(0x8D17);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_4822;
  a = 0x07;
  mem_write8(0x8D17, a);
  lab_p04_L_4822: ;
  a = d;
  set_bc(mem_read16(0x8D18));
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p04_L_4830;
  if (flag_nc()) goto lab_p04_L_4836;
  b = (uint8_t)(b + 1);
  goto lab_p04_L_485A;
  lab_p04_L_4830: ;
  b = (uint8_t)(b - 1);
  goto lab_p04_L_485A;
  lab_p04_L_4833: ;
  c = (uint8_t)(c - 1);
  goto lab_p04_L_485A;
  lab_p04_L_4836: ;
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p04_L_4833;
  if (flag_c()) goto lab_p04_L_4859;
  flag_cmp(a, 0x0E);
  a = b;
  if (flag_nz()) goto lab_p04_L_484A;
  a = (uint8_t)(a - 0x05);
  b = a;
  if (flag_nc()) goto lab_p04_L_4860;
  b = 0x00;
  goto lab_p04_L_4860;
  lab_p04_L_484A: ;
  a = (uint8_t)(a + 0x05);
  set_hl(0x8DA5);
  cpu_cp_hl();
  if (flag_c()) goto lab_p04_L_4856;
  b = mem_read8(hl());
  b = (uint8_t)(b - 1);
  goto lab_p04_L_4860;
  lab_p04_L_4856: ;
  b = a;
  goto lab_p04_L_4860;
  lab_p04_L_4859: ;
  c = (uint8_t)(c + 1);
  lab_p04_L_485A: ;
  p04_L_42EA();
  if (flag_c()) { p04_L_48AE(); return; }
  lab_p04_L_4860: ;
  p00_L_17CE();
  if (flag_z()) goto lab_p04_L_486A;
  a = c;
  flag_cmp(a, 0x20);
  if (flag_nc()) { p04_L_48AE(); return; }
  lab_p04_L_486A: ;
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_4874;
  a = c;
  flag_cmp(a, 0x34);
  if (flag_nc()) { p04_L_48AE(); return; }
  lab_p04_L_4874: ;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x2F);
  if (flag_nz()) { p04_L_4896(); return; }
  p04_L_6687();
  if (flag_nc()) { p04_L_48AE(); return; }
  mem_write16(0x8D18, bc());
  p04_L_489F();
  return;
  lab_p04_L_4A51: ;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p04_L_4ED0;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_4DB3;
  p00_L_3EFD();
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x51);
  if (flag_z()) goto lab_p04_L_4D7D;
  flag_cmp(a, 0x7D);
  if (flag_nz()) goto lab_p04_L_4AE2;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_4A76;
  cpu_pop_de();
  p04_L_6715();
  lab_p04_L_4A76: ;
  p04_L_5CA7();
  if (flag_nz()) { p04_L_48BB(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 2)) == 0);
  cpu_push_af();
  set_hl(mem_read16(0x8D18));
  cpu_push_hl();
  p00_L_38F1();
  set_de(0x8D8F);
  p00_L_11FD();
  p04_L_7BE4();
  cpu_pop_hl();
  mem_write16(0x8D18, hl());
  p00_L_1037();
  if (flag_nz()) goto lab_p04_L_4ACC;
  p00_L_15FB();
  p00_L_3339();
  p00_L_0013();
  if (flag_z()) goto lab_p04_L_4ABA;
  set_hl(0x8D8F);
  p00_rst20();
  p00_L_3321();
  p04_L_7636();
  p00_L_1179();
  p04_L_77D9();
  p00_L_16BC();
  goto lab_p04_L_4ABD;
  lab_p04_L_4ABA: ;
  p04_L_787A();
  lab_p04_L_4ABD: ;
  p04_L_5BA1();
  cpu_pop_af();
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 2)));
  a = 0x4D;
  mem_write8(0x8D17, a);
  return;
  lab_p04_L_4ACC: ;
  set_hl(0x7A20);
  p04_L_75C5();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7992();
  p04_L_7A03();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  goto lab_p04_L_4ABD;
  lab_p04_L_4AE2: ;
  flag_cmp(a, 0x6F);
  if (flag_z()) goto lab_p04_L_4AF3;
  flag_cmp(a, 0x73);
  if (flag_z()) goto lab_p04_L_4AF3;
  flag_cmp(a, 0x71);
  if (flag_z()) goto lab_p04_L_4AF3;
  flag_cmp(a, 0x63);
  if (flag_nz()) goto lab_p04_L_4B7B;
  lab_p04_L_4AF3: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_4AFA;
  cpu_pop_hl();
  lab_p04_L_4AFA: ;
  p04_L_5CA7();
  if (flag_z()) goto lab_p04_L_4B09;
  p04_L_6715();
  p04_L_48BB();
  p04_L_5CEA();
  return;
  lab_p04_L_4B09: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 2)) == 0);
  cpu_push_af();
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p00_L_334B();
  a = mem_read8(0x8D17);
  p00_L_0013();
  if (flag_nz()) goto lab_p04_L_4B43;
  p00_L_0198();
  if (flag_nz()) goto lab_p04_L_4B48;
  flag_cmp(a, 0x63);
  if (flag_nz()) goto lab_p04_L_4B5C;
  p00_L_17E0();
  cpu_push_hl();
  p00_rst18();
  cpu_pop_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 0)));
  p00_L_38D3();
  lab_p04_L_4B31: ;
  set_hl(0x7A20);
  lab_p04_L_4B34: ;
  p00_L_1037();
  if (flag_nz()) { p00_L_24C9(); return; }
  p04_L_6419();
  cpu_pop_af();
  p04_L_46DE();
  goto lab_p04_L_4BBD;
  lab_p04_L_4B43: ;
  p00_L_38BB();
  goto lab_p04_L_4B31;
  lab_p04_L_4B48: ;
  flag_cmp(a, 0x6F);
  if (flag_z()) goto lab_p04_L_4B54;
  p00_L_38CD();
  p00_L_0ED0();
  goto lab_p04_L_4B31;
  lab_p04_L_4B54: ;
  p00_L_38C1();
  set_hl(0x6735);
  goto lab_p04_L_4B34;
  lab_p04_L_4B5C: ;
  flag_cmp(a, 0x73);
  if (flag_z()) goto lab_p04_L_4B6B;
  p00_L_17E0();
  p00_L_38C7();
  set_hl(0x6743);
  goto lab_p04_L_4B34;
  lab_p04_L_4B6B: ;
  p00_L_38C7();
  set_hl(0x673C);
  goto lab_p04_L_4B34;
  lab_p04_L_4B73: ;
  p00_L_38F1();
  set_de(0x8D98);
  goto lab_p04_L_4B8C;
  lab_p04_L_4B7B: ;
  flag_cmp(a, 0x7F);
  if (flag_z()) goto lab_p04_L_4B86;
  flag_cmp(a, 0x81);
  if (flag_z()) return;
  flag_cmp(a, 0x53);
  if (flag_nz()) goto lab_p04_L_4BA2;
  lab_p04_L_4B86: ;
  p00_L_38F1();
  set_de(0x8D8F);
  lab_p04_L_4B8C: ;
  p00_L_11FD();
  a = mem_read8(0x8D17);
  a = (uint8_t)(a + 0x02);
  mem_write8(0x8D17, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  p04_L_61A6();
  p04_L_48BB();
  return;
  lab_p04_L_4BA2: ;
  flag_cmp(a, 0x55);
  if (flag_z()) goto lab_p04_L_4B73;
  flag_cmp(a, 0x57);
  if (flag_nz()) goto lab_p04_L_4BC8;
  p04_L_4D54();
  cpu_push_hl();
  p00_L_3351();
  p00_L_3321();
  p04_L_5B86();
  p04_L_7968();
  p04_L_4BBA();
  return;
  lab_p04_L_4BBD: ;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 4)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 2)));
  p04_L_465B();
  return;
  lab_p04_L_4BC8: ;
  flag_cmp(a, 0x5F);
  if (flag_z()) goto lab_p04_L_4B86;
  flag_cmp(a, 0x69);
  if (flag_z()) goto lab_p04_L_4B86;
  flag_cmp(a, 0x6B);
  if (flag_z()) goto lab_p04_L_4B73;
  flag_cmp(a, 0x77);
  if (flag_z()) goto lab_p04_L_4B86;
  flag_cmp(a, 0x79);
  if (flag_z()) goto lab_p04_L_4B73;
  flag_cmp(a, 0x61);
  if (flag_nz()) goto lab_p04_L_4BEE;
  p04_L_4D5C();
  cpu_push_hl();
  p00_L_3357();
  set_hl(0x672C);
  p04_L_6419();
  p04_L_4BED();
  return;
  lab_p04_L_4BEE: ;
  flag_cmp(a, 0x6D);
  if (flag_nz()) goto lab_p04_L_4C3B;
  a = a | a;
  flag_logic(a);
  lab_p04_L_4BF3: ;
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_4BFD;
  cpu_pop_af();
  cpu_pop_de();
  cpu_push_af();
  lab_p04_L_4BFD: ;
  p04_L_6715();
  p04_L_4D54();
  cpu_pop_af();
  cpu_push_hl();
  cpu_push_af();
  p00_L_1171();
  p00_L_2191();
  p00_L_219B();
  p00_rst08();
  p00_L_16A2();
  p00_L_10DD();
  p00_L_1229();
  a = 0x7B;
  mem_write8(0x8479, a);
  p00_L_1486();
  cpu_pop_af();
  cpu_push_af();
  b = 0x00;
  p00_L_397B();
  cpu_pop_af();
  cpu_pop_hl();
  cpu_push_af();
  cpu_push_hl();
  p04_L_5B86();
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) p04_L_794C();
  cpu_pop_af();
  if (flag_nc()) p04_L_793E();
  p04_L_4BBA();
  return;
  lab_p04_L_4C3B: ;
  flag_cmp(a, 0x7B);
  /* scf */
  if (flag_z()) goto lab_p04_L_4BF3;
  flag_cmp(a, 0x65);
  if (flag_nz()) goto lab_p04_L_4C78;
  p04_L_5CA7();
  if (flag_nz()) { p04_L_48BB(); return; }
  a = mem_read8(0x8D1B);
  mem_write8(0x847A, a);
  set_hl(mem_read16(0x980E));
  mem_write16(0x847D, hl());
  set_hl(mem_read16(0x9810));
  mem_write16(0x847B, hl());
  a = 0x67;
  mem_write8(0x8D17, a);
  set_hl(mem_read16(0x8D18));
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_4C6C;
  l = (uint8_t)(l | (1u << 7));
  lab_p04_L_4C6C: ;
  mem_write16(0x847F, hl());
  set_de(0x8D8F);
  p00_L_11FD();
  p04_L_51A2();
  return;
  lab_p04_L_4C78: ;
  flag_cmp(a, 0x67);
  if (flag_nz()) goto lab_p04_L_4CB7;
  p04_L_5CA7();
  if (flag_nz()) { p04_L_48BB(); return; }
  set_hl(0x8D8F);
  p00_rst20();
  set_hl(0x8D1B);
  a = mem_read8(0x847A);
  cpu_cp_hl();
  if (flag_nz()) goto lab_p04_L_4C9B;
  set_hl(mem_read16(0x980E));
  set_de(mem_read16(0x847D));
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p04_L_4CB4;
  lab_p04_L_4C9B: ;
  set_hl(mem_read16(0x8D18));
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_4CA6;
  l = (uint8_t)(l | (1u << 7));
  lab_p04_L_4CA6: ;
  mem_write16(0x8478, hl());
  set_de(0x8D8F);
  p00_L_11FD();
  a = 0x59;
  mem_write8(0x8D17, a);
  lab_p04_L_4CB4: ;
  p04_L_48BB();
  return;
  lab_p04_L_4CB7: ;
  flag_cmp(a, 0x59);
  if (flag_nz()) { p04_L_5CEA(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_4CC3;
  cpu_pop_hl();
  lab_p04_L_4CC3: ;
  l = 0x13;
  p04_L_4D35();
  cpu_push_de();
  set_hl(0x8D8F);
  p00_rst20();
  a = mem_read8(0x847A);
  mem_write8(0x847F, a);
  h = 0x41;
  l = 0x63;
  mem_write16(0x8479, hl());
  cpu_pop_de();
  set_hl(0x8479);
  p00_L_1189();
  a = mem_read8(hl());
  p04_L_4D45();
  cpu_push_de();
  set_hl(mem_read16(0x980E));
  mem_write16(0x847D, hl());
  set_hl(mem_read16(0x9810));
  mem_write16(0x847B, hl());
  h = 0x41;
  l = 0x63;
  mem_write16(0x8479, hl());
  a = 0x71;
  set_hl(0x8478);
  mem_write8(hl(), a);
  cpu_pop_de();
  p00_L_1187();
  p04_L_4D42();
  p00_L_1135();
  p00_rst18();
  p00_rst18();
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  a = 0x05;
  mem_write8(0x8D17, a);
  p04_L_5C6D();
  p00_L_16A2();
  p00_rst18();
  p00_L_335D();
  p00_L_3321();
  p00_L_219B();
  p00_rst10();
  if (flag_c()) goto lab_p04_L_4D29;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  lab_p04_L_4D29: ;
  p00_L_38F1();
  p04_L_5B86();
  p04_L_795A();
  p04_L_4BBA();
  return;
  lab_p04_L_4D7D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_4DA2;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p04_L_4DA2;
  set_hl(0x84AF);
  p00_L_1254();
  set_hl(0x6094);
  p00_L_25A2();
  a = 0;
  flag_logic(a);
  set_hl(0x84AF);
  set_de(0x84AF);
  p00_L_35DF();
  p00_L_25C8();
  lab_p04_L_4DA2: ;
  p04_L_44E4();
  p04_L_44EB();
  p00_L_0087();
  a = 0x5A;
  p04_L_45A5();
  return;
  lab_p04_L_4DB3: ;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x1D);
  if (flag_nz()) goto lab_p04_L_4DC9;
  set_bc(mem_read16(0x8D18));
  set_de(mem_read16(0x8D1A));
  p04_L_4025();
  a = 0x1B;
  goto lab_p04_L_4DD3;
  lab_p04_L_4DC9: ;
  flag_cmp(a, 0x27);
  if (flag_nz()) goto lab_p04_L_4DD6;
  a = 0;
  flag_logic(a);
  p00_L_35EB();
  a = 0x25;
  lab_p04_L_4DD3: ;
  p04_L_56FE();
  return;
  lab_p04_L_4DD6: ;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p04_L_4DE3;
  set_hl(0x6094);
  p00_L_25A2();
  /* scf */
  goto lab_p04_L_4DEE;
  lab_p04_L_4DE3: ;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p04_L_4E0C;
  set_hl(0x6094);
  p00_L_25A2();
  a = a | a;
  flag_logic(a);
  lab_p04_L_4DEE: ;
  set_hl(0x9148);
  set_de(0x913F);
  p00_L_35DF();
  p00_L_25C8();
  a = mem_read8(0x8D17);
  p00_L_0087();
  p04_L_678F();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_4DD3;
  p04_L_5470();
  return;
  lab_p04_L_4E0C: ;
  flag_cmp(a, 0x29);
  if (flag_nz()) goto lab_p04_L_4E15;
  p04_L_4017();
  goto lab_p04_L_4E4D;
  lab_p04_L_4E15: ;
  flag_cmp(a, 0x31);
  if (flag_nz()) goto lab_p04_L_4E1E;
  p04_L_4008();
  goto lab_p04_L_4E4D;
  lab_p04_L_4E1E: ;
  flag_cmp(a, 0x2B);
  if (flag_nz()) goto lab_p04_L_4E2B;
  a = 0x2D;
  mem_write8(0x8D17, a);
  d = 0x01;
  goto lab_p04_L_4E46;
  lab_p04_L_4E2B: ;
  flag_cmp(a, 0x2D);
  if (flag_nz()) goto lab_p04_L_4E36;
  a = 0x2B;
  mem_write8(0x8D17, a);
  goto lab_p04_L_4E4D;
  lab_p04_L_4E36: ;
  d = 0x00;
  flag_cmp(a, 0x21);
  if (flag_z()) goto lab_p04_L_4E46;
  d = (uint8_t)(d + 1);
  flag_cmp(a, 0x1F);
  if (flag_z()) goto lab_p04_L_4E46;
  d = (uint8_t)(d + 1);
  flag_cmp(a, 0x23);
  if (flag_nz()) goto lab_p04_L_4E50;
  lab_p04_L_4E46: ;
  set_bc(mem_read16(0x8D18));
  p04_L_4157();
  lab_p04_L_4E4D: ;
  p04_L_48AE();
  return;
  lab_p04_L_4E50: ;
  flag_cmp(a, 0x15);
  if (flag_nz()) goto lab_p04_L_4E66;
  p04_L_5CEA();
  p00_L_38F1();
  p00_L_1171();
  p00_L_353D();
  p04_L_5EA3();
  p04_L_4DB0();
  return;
  lab_p04_L_4E66: ;
  flag_cmp(a, 0x13);
  if (flag_nz()) goto lab_p04_L_4E6E;
  a = 0x09;
  goto lab_p04_L_4EC4;
  lab_p04_L_4E6E: ;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p04_L_4EB5;
  p04_L_5CEA();
  set_hl(mem_read16(0x8D1A));
  set_de(mem_read16(0x8D18));
  a = h;
  flag_cmp(a, d);
  if (flag_z()) { p00_L_250D(); return; }
  if (flag_c()) goto lab_p04_L_4E85;
  cpu_ex_de_hl();
  lab_p04_L_4E85: ;
  a = l;
  flag_cmp(a, e);
  if (flag_z()) { p00_L_250D(); return; }
  if (flag_c()) goto lab_p04_L_4E8E;
  l = e;
  e = a;
  lab_p04_L_4E8E: ;
  mem_write16(0x8D1A, hl());
  mem_write16(0x8D18, de());
  c = l;
  b = h;
  set_de(0x84A4);
  set_hl(0x84AF);
  p04_L_43C5();
  set_bc(mem_read16(0x8D18));
  p04_L_43BF();
  p04_L_5C5D();
  p04_L_5EF2();
  p00_L_0087();
  a = 0x5F;
  p04_L_45A5();
  return;
  lab_p04_L_4EB5: ;
  flag_cmp(a, 0x25);
  if (flag_nz()) goto lab_p04_L_4EBD;
  a = 0x27;
  goto lab_p04_L_4EC4;
  lab_p04_L_4EBD: ;
  flag_cmp(a, 0x1B);
  if (flag_nz()) { p04_L_5CEA(); return; }
  a = 0x1D;
  lab_p04_L_4EC4: ;
  mem_write8(0x8D17, a);
  set_hl(mem_read16(0x8D18));
  mem_write16(0x8D1A, hl());
  p04_L_48AE();
  return;
  lab_p04_L_4ED0: ;
  flag_cmp(a, 0x63);
  if (flag_nz()) goto lab_p04_L_4EDC;
  p04_L_5C5D();
  p04_L_60F8();
  p04_L_4F3D();
  return;
  lab_p04_L_4EDC: ;
  flag_cmp(a, 0x5B);
  if (flag_nz()) goto lab_p04_L_4EE5;
  p04_L_5FBC();
  p04_L_4F3D();
  return;
  lab_p04_L_4EE5: ;
  flag_cmp(a, 0x65);
  if (flag_nz()) goto lab_p04_L_4EEE;
  p04_L_5F65();
  p04_L_4F3D();
  return;
  lab_p04_L_4EEE: ;
  flag_cmp(a, 0x5E);
  if (flag_nz()) goto lab_p04_L_4EF7;
  p04_L_5F49();
  p04_L_4F3D();
  return;
  lab_p04_L_4EF7: ;
  flag_cmp(a, 0x62);
  if (flag_nz()) goto lab_p04_L_4F00;
  p04_L_602F();
  p04_L_4F3D();
  return;
  lab_p04_L_4F00: ;
  flag_cmp(a, 0x60);
  if (flag_nz()) goto lab_p04_L_4F09;
  p04_L_5F1C();
  p04_L_4F3D();
  return;
  lab_p04_L_4F09: ;
  flag_cmp(a, 0x66);
  if (flag_nz()) goto lab_p04_L_4F12;
  p04_L_5FB9();
  goto lab_p04_L_4F43;
  lab_p04_L_4F12: ;
  flag_cmp(a, 0x68);
  if (flag_nz()) goto lab_p04_L_4F1D;
  a = 0x8F;
  p00_L_35EB();
  p04_L_4F3D();
  return;
  lab_p04_L_4F1D: ;
  flag_cmp(a, 0x44);
  if (flag_z()) goto lab_p04_L_4F43;
  flag_cmp(a, 0x6B);
  if (flag_z()) { p04_L_4F3D(); return; }
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p04_L_4F36;
  p00_L_3EFD();
  a = mem_read8(0x8D17);
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p00_L_05F2(); return; }
  lab_p04_L_4F33: ;
  p04_L_5720();
  return;
  lab_p04_L_4F36: ;
  flag_cmp(a, 0x64);
  if (flag_nz()) goto lab_p04_L_4F52;
  p04_L_60A7();
  p04_L_4F3D();
  return;
  lab_p04_L_4F43: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  cpu_push_af();
  if (flag_nz()) p04_L_678F();
  cpu_pop_af();
  if (flag_z()) p04_L_6185();
  p04_L_5720();
  return;
  lab_p04_L_4F52: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  cpu_push_af();
  if (flag_nz()) p04_L_678F();
  cpu_pop_af();
  cpu_push_af();
  if (flag_z()) p04_L_6185();
  cpu_pop_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_4F33;
  flag_cmp(a, 0x75);
  if (flag_nz()) goto lab_p04_L_502C;
  a = 0;
  flag_logic(a);
  mem_write8(0x85FD, a);
  goto lab_p04_L_4F7B;
  lab_p04_L_4F7B: ;
  p04_L_5ADC();
  set_hl(mem_read16(0x980C));
  mem_write16(0x9824, hl());
  if (flag_z()) { p04_L_5720(); return; }
  p04_L_5720();
  p04_L_4FB9();
  a = mem_read8(0x8D1B);
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) p04_L_77FE();
  p00_L_3CC9();
  p00_L_3759();
  mem_write16(0x9706, hl());
  p00_L_3651();
  p00_L_03A0();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 0)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 5)));
  set_hl(0x4572);
  mem_write16(0x8595, hl());
  return;
  lab_p04_L_502C: ;
  set_hl(0x4FFE);
  set_bc(0x000C);
  /* cpir */
  if (flag_nz()) goto lab_p04_L_56E6;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 4)));
  set_hl(0x500A);
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  mem_write8(0x8D17, a);
  set_hl(0x505E);
  a = mem_read8(0x9151);
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_5054;
  a = (uint8_t)(a + 0x08);
  lab_p04_L_5054: ;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  l = mem_read8(hl());
  h = d;
  p04_L_6715();
  goto lab_p04_L_507D;
  lab_p04_L_507D: ;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 6)));
  mem_write16(0x8E67, hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_5099;
  set_hl(0x0000);
  mem_write16(0x8E65, hl());
  mem_write16(0x8D1A, hl());
  mem_write16(0x9810, hl());
  mem_write16(0x980E, hl());
  lab_p04_L_5099: ;
  p00_L_35A9();
  a = 0;
  flag_logic(a);
  mem_write8(0x8E63, a);
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 0)));
  p04_L_626B();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_50DC;
  /* set 7,(iy) */
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_50D9;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  p00_L_39F3();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_50CA;
  set_hl(0x8FE0);
  p00_rst20();
  p00_L_39D5();
  lab_p04_L_50CA: ;
  p04_L_51B5();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 4)));
  lab_p04_L_50D9: ;
  p04_L_52EC();
  return;
  lab_p04_L_50DC: ;
  p04_L_449A();
  if (flag_nz()) goto lab_p04_L_50E9;
  p00_L_35AF();
  if (flag_z()) goto lab_p04_L_4F43;
  goto lab_p04_L_5139;
  lab_p04_L_50E9: ;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x4F);
  if (flag_z()) goto lab_p04_L_5139;
  p00_L_01A2();
  if (flag_nz()) p04_L_7298();
  p00_L_0198();
  if (flag_nz()) p04_L_7289();
  goto lab_p04_L_5136;
  lab_p04_L_5136: ;
  p04_L_50FE();
  lab_p04_L_5139: ;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_5182;
  p00_L_39F3();
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x4F);
  if (flag_nz()) goto lab_p04_L_5150;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_517F;
  goto lab_p04_L_5173;
  lab_p04_L_5150: ;
  set_hl(0x8D21);
  p00_rst20();
  /* bit 7,(iy) */
  if (flag_nz()) goto lab_p04_L_516D;
  set_hl(0x8FBC);
  p00_rst20();
  p00_L_0C2A();
  p00_L_15CB();
  if (flag_nz()) { p00_L_2509(); return; }
  p04_L_6726();
  p04_L_501E();
  lab_p04_L_516D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_517C;
  lab_p04_L_5173: ;
  set_hl(0x8FE0);
  p00_rst20();
  p00_L_39D5();
  goto lab_p04_L_517F;
  lab_p04_L_517C: ;
  p04_L_6726();
  lab_p04_L_517F: ;
  p04_L_51B5();
  lab_p04_L_5182: ;
  /* set 7,(iy) */
  a = 0x0B;
  mem_write8(0x8D1B, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_519C;
  p00_L_0189();
  if (flag_z()) { p04_L_51A2(); return; }
  p04_L_6185();
  p04_L_5BA1();
  lab_p04_L_519C: ;
  p00_L_0189();
  if (flag_nz()) { p04_L_5470(); return; }
  p04_L_51A2();
  return;
  lab_p04_L_51D0: ;
  b = a;
  a = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3369();
  if (flag_nz()) return;
  cpu_push_bc();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1F)) & (1u << 4)) == 0);
  if (flag_nz()) p04_L_51AA();
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 6)));
  p04_L_50FE();
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 1)));
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p04_L_53B2;
  if (flag_c()) goto lab_p04_L_5483;
  flag_cmp(a, 0x0E);
  if (flag_nc()) goto lab_p04_L_5222;
  d = a;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x81);
  if (flag_nz()) goto lab_p04_L_5216;
  set_hl(mem_read16(0x8E65));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x8E65, hl());
  p00_L_3591();
  return;
  lab_p04_L_5216: ;
  set_hl(0x5016);
  set_bc(0x0008);
  /* cpir */
  if (flag_z()) { p04_L_52F1(); return; }
  a = d;
  lab_p04_L_5222: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p04_L_5548;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  a = mem_read8(0x8E63);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_525D;
  p00_L_35AF();
  if (flag_nz()) goto lab_p04_L_5246;
  p04_L_63D8();
  if (flag_nz()) goto lab_p04_L_5246;
  p00_L_35AF();
  b = a;
  a = mem_read8(0x8E63);
  flag_cmp(a, b);
  if (flag_z()) { p04_L_48BB(); return; }
  lab_p04_L_5246: ;
  a = mem_read8(0x8E63);
  p00_L_35C1();
  lab_p04_L_524C: ;
  p00_L_3EFD();
  a = mem_read8(0x8E63);
  p00_L_35AF();
  if (flag_z()) goto lab_p04_L_5274;
  p00_L_3585();
  p04_L_48B5();
  return;
  lab_p04_L_525D: ;
  set_hl(mem_read16(0x9810));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_5277;
  set_de(mem_read16(0x980E));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p04_L_5277;
  set_de((uint16_t)(de() + 1));
  mem_write16(0x980E, de());
  p04_L_52F1();
  return;
  lab_p04_L_5274: ;
  mem_write8(0x8E63, a);
  lab_p04_L_5277: ;
  a = mem_read8(0x8D1B);
  p04_L_63D8();
  if (flag_nz()) goto lab_p04_L_529B;
  p00_L_35AF();
  if (flag_nz()) goto lab_p04_L_529B;
  p04_L_63D8();
  b = a;
  a = mem_read8(0x8D1B);
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p04_L_529B;
  set_hl(mem_read16(0x9810));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_529B;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 7)));
  p04_L_52F1();
  return;
  lab_p04_L_529B: ;
  set_hl(0x0000);
  mem_write16(0x9810, hl());
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x980E, hl());
  a = mem_read8(0x8D1B);
  flag_cmp(a, 0x0A);
  if (flag_z()) goto lab_p04_L_52B7;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_52B7;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_52B7;
  p04_L_52C2();
  lab_p04_L_52B7: ;
  p04_L_63D8();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_52CD;
  mem_write8(0x8D1B, a);
  goto lab_p04_L_524C;
  lab_p04_L_52CD: ;
  mem_write8(0x8D1B, a);
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_52E5;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_52E5;
  set_hl(0x8FE0);
  p00_rst20();
  p00_L_39D5();
  p04_L_51B5();
  lab_p04_L_52E5: ;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 0)));
  p00_L_3EFD();
  p04_L_52EC();
  return;
  lab_p04_L_53B2: ;
  b = 0x01;
  p04_L_53B4();
  return;
  lab_p04_L_5462: ;
  p00_L_0087();
  p04_L_5470();
  return;
  lab_p04_L_5483: ;
  b = 0x01;
  lab_p04_L_5485: ;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 4)));
  a = mem_read8(0x8E63);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_5493;
  p00_L_3591();
  return;
  lab_p04_L_5493: ;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 1)));
  p00_L_0013();
  if (flag_z()) goto lab_p04_L_54DB;
  p04_L_5474();
  lab_p04_L_549F: ;
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + c);
  mem_write8(0x8E67, a);
  p04_L_75A2();
  if (flag_c()) goto lab_p04_L_54D1;
  cpu_push_bc();
  p04_L_5C7A();
  a = mem_read8(0x8E67);
  if (flag_nz()) goto lab_p04_L_54BB;
  cpu_pop_bc();
  a = (uint8_t)(a - c);
  mem_write8(0x8E67, a);
  p04_L_54D3();
  return;
  lab_p04_L_54BB: ;
  cpu_push_af();
  p00_L_3EFD();
  p04_L_58BE();
  cpu_pop_de();
  cpu_push_af();
  a = d;
  a = (uint8_t)(a - 0x08);
  h = 0x00;
  l = a;
  cpu_pop_af();
  cpu_pop_bc();
  if (flag_nz()) goto lab_p04_L_5462;
  mem_write16(0x8E67, hl());
  lab_p04_L_54D1: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_549F;
  p04_L_54D3();
  return;
  lab_p04_L_54D6: ;
  set_hl((uint16_t)(hl() + de()));
  if (flag_c()) goto lab_p04_L_54F2;
  lab_p04_L_54D9: ;
  p04_L_54D3();
  return;
  lab_p04_L_54DB: ;
  p00_L_019D();
  if (flag_nz()) goto lab_p04_L_5516;
  set_de(0x0001);
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 7)));
  lab_p04_L_54E7: ;
  set_hl(mem_read16(0x8E67));
  a = e;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p04_L_54D6;
  set_hl((uint16_t)(hl() + de()));
  if (flag_c()) goto lab_p04_L_54D9;
  lab_p04_L_54F2: ;
  cpu_push_de();
  cpu_push_bc();
  mem_write16(0x8E67, hl());
  set_bc(0x8FA1);
  p00_L_01A2();
  if (flag_nz()) goto lab_p04_L_5502;
  set_bc(0x8F86);
  lab_p04_L_5502: ;
  p04_L_722F();
  cpu_pop_bc();
  cpu_pop_de();
  if (flag_c()) goto lab_p04_L_553F;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 1)));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_54E7;
  p04_L_5513();
  return;
  lab_p04_L_5516: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_5525;
  set_hl(0x8D21);
  p00_L_186A();
  p04_L_54D3();
  return;
  lab_p04_L_5525: ;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 7)));
  lab_p04_L_5529: ;
  cpu_push_bc();
  p04_L_6F32();
  if (flag_c()) goto lab_p04_L_553E;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 7)));
  p04_L_6726();
  p00_L_3ABF();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_5529;
  p04_L_5513();
  return;
  lab_p04_L_553E: ;
  cpu_pop_bc();
  lab_p04_L_553F: ;
  set_hl(mem_read16(0x8E67));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x8E67, hl());
  p04_L_5513();
  return;
  lab_p04_L_5548: ;
  flag_cmp(a, 0x0E);
  if (flag_c()) goto lab_p04_L_5558;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 0)));
  b = 0x05;
  if (flag_nz()) goto lab_p04_L_5485;
  p04_L_53B4();
  return;
  lab_p04_L_5558: ;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 0)));
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  a = mem_read8(0x8E63);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_559E;
  p00_L_35BB();
  if (flag_nz()) goto lab_p04_L_557F;
  a = 0x0B;
  p04_L_63DC();
  if (flag_nz()) goto lab_p04_L_557F;
  a = 0x04;
  p00_L_35BB();
  b = a;
  a = mem_read8(0x8E63);
  flag_cmp(a, b);
  if (flag_z()) { p04_L_48BB(); return; }
  lab_p04_L_557F: ;
  a = mem_read8(0x8E63);
  p00_L_35C1();
  p04_L_5585();
  return;
  lab_p04_L_559E: ;
  set_hl(mem_read16(0x9810));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_55B5;
  set_de(mem_read16(0x980E));
  set_de((uint16_t)(de() - 1));
  a = e;
  a = a | d;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_55B5;
  mem_write16(0x980E, de());
  p04_L_5513();
  return;
  lab_p04_L_55B5: ;
  a = mem_read8(0x8D1B);
  p04_L_63DC();
  if (flag_nz()) goto lab_p04_L_55DE;
  a = 0x04;
  p00_L_35BB();
  if (flag_nz()) goto lab_p04_L_55DE;
  a = 0x0B;
  p04_L_63DC();
  b = a;
  a = mem_read8(0x8D1B);
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p04_L_55DE;
  set_hl(mem_read16(0x9810));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_55DE;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 7)));
  p04_L_52F1();
  return;
  lab_p04_L_55DE: ;
  a = 0;
  flag_logic(a);
  h = a;
  l = a;
  mem_write16(0x9810, hl());
  mem_write8(0x8E63, a);
  a = mem_read8(0x8D1B);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_55F5;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_55F5;
  p04_L_52C2();
  lab_p04_L_55F5: ;
  p04_L_63DC();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_52CD;
  mem_write8(0x8D1B, a);
  a = 0x04;
  mem_write8(0x8E63, a);
  p04_L_5585();
  return;
  lab_p04_L_56E6: ;
  set_hl(0x56CC);
  set_bc(0x000D);
  /* cpir */
  if (flag_nz()) goto lab_p04_L_571D;
  set_hl(0x56D9);
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  if (flag_z()) p04_L_6185();
  cpu_pop_af();
  p04_L_56FE();
  return;
  lab_p04_L_571D: ;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_5723;
  p04_L_5720();
  return;
  lab_p04_L_5723: ;
  p04_L_48BB();
  return;
}

/* flash page 4 cpu 0x4886 (offset 0x0886) */
void p04_L_4886(void) {
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 7)));
  set_hl(mem_read16(0x8D18));
  mem_write16(0x8D1C, hl());
  goto lab_p04_L_48C2;
  lab_p04_L_48C2: ;
  a = mem_read8(0x8D17);
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  flag_cmp(a, 0x4D);
  if (flag_z()) return;
  flag_cmp(a, 0x2F);
  if (flag_z()) return;
  flag_cmp(a, 0x05);
  if (flag_z()) { p04_L_764E(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_4948;
  a = mem_read8(0x8E63);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_48F4;
  p00_L_358B();
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 4)) == 0);
  if (flag_nz()) { p04_L_48FE(); return; }
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x7F);
  if (flag_nc()) { p04_L_48FE(); return; }
  return;
  lab_p04_L_48F4: ;
  a = mem_read8(0x8D1B);
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) p04_L_77FE();
  p04_L_48FE();
  return;
  lab_p04_L_4948: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  flag_cmp(a, 0x4F);
  if (flag_z()) goto lab_p04_L_4956;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 4)) == 0);
  if (flag_nz()) return;
  lab_p04_L_4956: ;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  p00_L_0198();
  if (flag_z()) goto lab_p04_L_498D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_498D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_4983;
  p04_L_66A5();
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_497A;
  p04_L_7685();
  p04_L_4A40();
  return;
  lab_p04_L_497A: ;
  p04_L_764E();
  p04_L_4A40();
  p04_L_761E();
  return;
  lab_p04_L_4983: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 3)) == 0);
  if (flag_nz()) { p04_L_7685(); return; }
  p04_L_767A();
  return;
  lab_p04_L_498D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_4A06;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_4A06;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p04_L_4A06;
  set_hl(0x4A06);
  p00_L_25A2();
  p00_L_168D();
  p00_rst10();
  if (flag_c()) goto lab_p04_L_49B3;
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) { p00_L_24BD(); return; }
  lab_p04_L_49B3: ;
  p00_L_1689();
  p00_rst10();
  if (flag_c()) goto lab_p04_L_49BE;
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) { p00_L_24BD(); return; }
  lab_p04_L_49BE: ;
  p00_L_353D();
  p00_rst08();
  p00_L_38F1();
  p00_L_3AD1();
  p00_L_15FB();
  p00_L_25C8();
  p00_L_21E0();
  p00_L_332D();
  p00_L_219B();
  p00_L_3333();
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) { p04_L_7685(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_49FD;
  p04_L_66A5();
  p04_L_7685();
  p04_L_4A40();
  p00_L_019D();
  if (flag_nz()) p04_L_7661();
  p00_L_01A2();
  if (flag_z()) return;
  p04_L_762E();
  return;
  lab_p04_L_49FD: ;
  p00_L_01A2();
  if (flag_nz()) goto lab_p04_L_7682;
  p04_L_7685();
  return;
  lab_p04_L_4A06: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) { p04_L_764E(); return; }
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_4A1F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_765C;
  p04_L_4A31();
  p04_L_7661();
  return;
  lab_p04_L_4A1F: ;
  p00_L_01A2();
  if (flag_z()) { p04_L_4A31(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_764B;
  p04_L_4A31();
  p04_L_762E();
  return;
  lab_p04_L_764B: ;
  p04_L_762E();
  p04_L_764E();
  return;
  lab_p04_L_765C: ;
  p04_L_7661();
  p04_L_764E();
  return;
  lab_p04_L_7682: ;
  p04_L_762E();
  p04_L_7685();
  return;
}

/* flash page 4 cpu 0x4896 (offset 0x0896) */
void p04_L_4896(void) {
  mem_write16(0x8D18, bc());
  flag_cmp(a, 0x2D);
  if (flag_z()) p04_L_4155();
  p04_L_489F();
  return;
}

/* flash page 4 cpu 0x489F (offset 0x089F) */
void p04_L_489F(void) {
  set_hl(0x84AF);
  p04_L_43C2();
  p00_L_3321();
  p00_L_1130();
  p00_L_3327();
  p04_L_48AE();
  return;
}

/* flash page 4 cpu 0x48AE (offset 0x08AE) */
void p04_L_48AE(void) {
  p04_L_5C6D();
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 7)));
  p04_L_48B5();
  return;
}

/* flash page 4 cpu 0x48B5 (offset 0x08B5) */
void p04_L_48B5(void) {
  set_hl(mem_read16(0x8D18));
  mem_write16(0x8D1C, hl());
  p04_L_48BB();
  return;
}

/* flash page 4 cpu 0x48BB (offset 0x08BB) */
void p04_L_48BB(void) {
  p04_L_5BA1();
  p04_L_48BE();
  return;
}

/* flash page 4 cpu 0x48BE (offset 0x08BE) */
void p04_L_48BE(void) {
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 3)));
  a = mem_read8(0x8D17);
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  flag_cmp(a, 0x4D);
  if (flag_z()) return;
  flag_cmp(a, 0x2F);
  if (flag_z()) return;
  flag_cmp(a, 0x05);
  if (flag_z()) { p04_L_764E(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_4948;
  a = mem_read8(0x8E63);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_48F4;
  p00_L_358B();
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 4)) == 0);
  if (flag_nz()) { p04_L_48FE(); return; }
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x7F);
  if (flag_nc()) { p04_L_48FE(); return; }
  return;
  lab_p04_L_48F4: ;
  a = mem_read8(0x8D1B);
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) p04_L_77FE();
  p04_L_48FE();
  return;
  lab_p04_L_4948: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  flag_cmp(a, 0x4F);
  if (flag_z()) goto lab_p04_L_4956;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 4)) == 0);
  if (flag_nz()) return;
  lab_p04_L_4956: ;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  p00_L_0198();
  if (flag_z()) goto lab_p04_L_498D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_498D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_4983;
  p04_L_66A5();
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_497A;
  p04_L_7685();
  p04_L_4A40();
  return;
  lab_p04_L_497A: ;
  p04_L_764E();
  p04_L_4A40();
  p04_L_761E();
  return;
  lab_p04_L_4983: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 3)) == 0);
  if (flag_nz()) { p04_L_7685(); return; }
  p04_L_767A();
  return;
  lab_p04_L_498D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_4A06;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_4A06;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p04_L_4A06;
  set_hl(0x4A06);
  p00_L_25A2();
  p00_L_168D();
  p00_rst10();
  if (flag_c()) goto lab_p04_L_49B3;
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) { p00_L_24BD(); return; }
  lab_p04_L_49B3: ;
  p00_L_1689();
  p00_rst10();
  if (flag_c()) goto lab_p04_L_49BE;
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) { p00_L_24BD(); return; }
  lab_p04_L_49BE: ;
  p00_L_353D();
  p00_rst08();
  p00_L_38F1();
  p00_L_3AD1();
  p00_L_15FB();
  p00_L_25C8();
  p00_L_21E0();
  p00_L_332D();
  p00_L_219B();
  p00_L_3333();
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) { p04_L_7685(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_49FD;
  p04_L_66A5();
  p04_L_7685();
  p04_L_4A40();
  p00_L_019D();
  if (flag_nz()) p04_L_7661();
  p00_L_01A2();
  if (flag_z()) return;
  p04_L_762E();
  return;
  lab_p04_L_49FD: ;
  p00_L_01A2();
  if (flag_nz()) goto lab_p04_L_7682;
  p04_L_7685();
  return;
  lab_p04_L_4A06: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) { p04_L_764E(); return; }
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_4A1F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_765C;
  p04_L_4A31();
  p04_L_7661();
  return;
  lab_p04_L_4A1F: ;
  p00_L_01A2();
  if (flag_z()) { p04_L_4A31(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_764B;
  p04_L_4A31();
  p04_L_762E();
  return;
  lab_p04_L_764B: ;
  p04_L_762E();
  p04_L_764E();
  return;
  lab_p04_L_765C: ;
  p04_L_7661();
  p04_L_764E();
  return;
  lab_p04_L_7682: ;
  p04_L_762E();
  p04_L_7685();
  return;
}

/* flash page 4 cpu 0x48FE (offset 0x08FE) */
void p04_L_48FE(void) {
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x5F);
  if (flag_z()) goto lab_p04_L_78D0;
  flag_cmp(a, 0x61);
  if (flag_z()) goto lab_p04_L_78DE;
  flag_cmp(a, 0x53);
  if (flag_z()) goto lab_p04_L_4923;
  flag_cmp(a, 0x65);
  if (flag_z()) goto lab_p04_L_78A6;
  flag_cmp(a, 0x67);
  if (flag_z()) goto lab_p04_L_78B4;
  flag_cmp(a, 0x59);
  if (flag_z()) goto lab_p04_L_4934;
  flag_cmp(a, 0x55);
  if (flag_z()) goto lab_p04_L_493D;
  flag_cmp(a, 0x69);
  lab_p04_L_4923: ;
  if (flag_z()) goto lab_p04_L_7898;
  flag_cmp(a, 0x7F);
  if (flag_z()) goto lab_p04_L_4923;
  flag_cmp(a, 0x81);
  if (flag_z()) goto lab_p04_L_493D;
  flag_cmp(a, 0x6B);
  if (flag_z()) goto lab_p04_L_493D;
  flag_cmp(a, 0x6D);
  lab_p04_L_4934: ;
  if (flag_z()) goto lab_p04_L_78EC;
  flag_cmp(a, 0x77);
  if (flag_z()) goto lab_p04_L_4923;
  flag_cmp(a, 0x79);
  lab_p04_L_493D: ;
  if (flag_z()) goto lab_p04_L_78C2;
  flag_cmp(a, 0x7B);
  if (flag_z()) goto lab_p04_L_4934;
  flag_cmp(a, 0x57);
  if (flag_z()) goto lab_p04_L_4934;
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  flag_cmp(a, 0x4F);
  if (flag_z()) goto lab_p04_L_4956;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 4)) == 0);
  if (flag_nz()) return;
  lab_p04_L_4956: ;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  p00_L_0198();
  if (flag_z()) goto lab_p04_L_498D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_498D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_4983;
  p04_L_66A5();
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_497A;
  p04_L_7685();
  p04_L_4A40();
  return;
  lab_p04_L_497A: ;
  p04_L_764E();
  p04_L_4A40();
  p04_L_761E();
  return;
  lab_p04_L_4983: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 3)) == 0);
  if (flag_nz()) { p04_L_7685(); return; }
  p04_L_767A();
  return;
  lab_p04_L_498D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_4A06;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_4A06;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p04_L_4A06;
  set_hl(0x4A06);
  p00_L_25A2();
  p00_L_168D();
  p00_rst10();
  if (flag_c()) goto lab_p04_L_49B3;
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) { p00_L_24BD(); return; }
  lab_p04_L_49B3: ;
  p00_L_1689();
  p00_rst10();
  if (flag_c()) goto lab_p04_L_49BE;
  flag_set_z((mem_read8(hl()) & (1u << 6)) == 0);
  if (flag_nz()) { p00_L_24BD(); return; }
  lab_p04_L_49BE: ;
  p00_L_353D();
  p00_rst08();
  p00_L_38F1();
  p00_L_3AD1();
  p00_L_15FB();
  p00_L_25C8();
  p00_L_21E0();
  p00_L_332D();
  p00_L_219B();
  p00_L_3333();
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) { p04_L_7685(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_49FD;
  p04_L_66A5();
  p04_L_7685();
  p04_L_4A40();
  p00_L_019D();
  if (flag_nz()) p04_L_7661();
  p00_L_01A2();
  if (flag_z()) return;
  p04_L_762E();
  return;
  lab_p04_L_49FD: ;
  p00_L_01A2();
  if (flag_nz()) goto lab_p04_L_7682;
  p04_L_7685();
  return;
  lab_p04_L_4A06: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) { p04_L_764E(); return; }
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_4A1F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_765C;
  p04_L_4A31();
  p04_L_7661();
  return;
  lab_p04_L_4A1F: ;
  p00_L_01A2();
  if (flag_z()) { p04_L_4A31(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_764B;
  p04_L_4A31();
  p04_L_762E();
  return;
  lab_p04_L_764B: ;
  p04_L_762E();
  p04_L_764E();
  return;
  lab_p04_L_765C: ;
  p04_L_7661();
  p04_L_764E();
  return;
  lab_p04_L_7682: ;
  p04_L_762E();
  p04_L_7685();
  return;
  lab_p04_L_7898: ;
  set_hl(0x7A8D);
  a = 0x5A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p04_L_78F8;
  lab_p04_L_78A6: ;
  set_hl(0x7A44);
  a = 0x5F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p04_L_78F8;
  lab_p04_L_78B4: ;
  set_hl(0x7A51);
  a = 0x5E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p04_L_78F8;
  lab_p04_L_78C2: ;
  set_hl(0x7A99);
  a = 0x59;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p04_L_78F8;
  lab_p04_L_78D0: ;
  set_hl(0x7A73);
  a = 0x5C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p04_L_78F8;
  lab_p04_L_78DE: ;
  set_hl(0x7A80);
  a = 0x5B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p04_L_78F8;
  lab_p04_L_78EC: ;
  set_hl(0x7AA6);
  a = 0x58;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  lab_p04_L_78F8: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_7910;
  cpu_push_hl();
  p04_L_66A5();
  p04_L_764E();
  p00_L_3EFD();
  cpu_pop_hl();
  p04_L_7930();
  p04_L_4A43();
  return;
  lab_p04_L_7910: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_7925;
  p04_L_75F8();
  p00_L_18B7();
  if (flag_nz()) goto lab_p04_L_7933;
  a = (uint8_t)(a - 0x02);
  mem_write8(0x86D8, a);
  goto lab_p04_L_7933;
  lab_p04_L_7925: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_7974;
  p04_L_75C5();
  goto lab_p04_L_7933;
  lab_p04_L_7933: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7992();
  p04_L_7A03();
  return;
  lab_p04_L_7974: ;
  p04_L_7930();
  p04_L_764E();
  return;
}

/* flash page 4 cpu 0x4A31 (offset 0x0A31) */
void p04_L_4A31(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_nz()) p04_L_66A5();
  p04_L_764E();
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) return;
  p04_L_4A40();
  return;
}

/* flash page 4 cpu 0x4A40 (offset 0x0A40) */
void p04_L_4A40(void) {
  p00_L_3EFD();
  p04_L_4A43();
  return;
}

/* flash page 4 cpu 0x4A43 (offset 0x0A43) */
void p04_L_4A43(void) {
  p04_L_5BA1();
  a = mem_read8(0x8D1B);
  p04_L_77FE();
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 3)));
  return;
}

/* flash page 4 cpu 0x4BBA (offset 0x0BBA) */
void p04_L_4BBA(void) {
  p00_L_38F1();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 4)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 2)));
  p04_L_465B();
  return;
}

/* flash page 4 cpu 0x4BED (offset 0x0BED) */
void p04_L_4BED(void) {
  return;
}

/* flash page 4 cpu 0x4D35 (offset 0x0D35) */
void p04_L_4D35(void) {
  h = 0x00;
  p04_L_4D37();
  return;
}

/* flash page 4 cpu 0x4D37 (offset 0x0D37) */
void p04_L_4D37(void) {
  p00_L_1CA2();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  return;
}

/* flash page 4 cpu 0x4D42 (offset 0x0D42) */
void p04_L_4D42(void) {
  a = mem_read8(0x8D1B);
  p04_L_4D45();
  return;
}

/* flash page 4 cpu 0x4D45 (offset 0x0D45) */
void p04_L_4D45(void) {
  cpu_push_de();
  p00_L_3363();
  cpu_pop_de();
  a = 0x5E;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  a = mem_read8(0x847A);
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  return;
}

/* flash page 4 cpu 0x4D54 (offset 0x0D54) */
void p04_L_4D54(void) {
  set_hl(0x8D8F);
  p00_L_21E8();
  goto lab_p04_L_4D5F;
  lab_p04_L_4D5F: ;
  p00_L_21E8();
  cpu_pop_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_4D6D;
  cpu_pop_de();
  p04_L_6715();
  lab_p04_L_4D6D: ;
  cpu_push_hl();
  a = 0x05;
  mem_write8(0x8D17, a);
  p04_L_5C6D();
  p00_L_334B();
  set_hl(mem_read16(0x982A));
  return;
}

/* flash page 4 cpu 0x4D5C (offset 0x0D5C) */
void p04_L_4D5C(void) {
  set_hl(0x8D8F);
  p00_L_21E8();
  cpu_pop_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_4D6D;
  cpu_pop_de();
  p04_L_6715();
  lab_p04_L_4D6D: ;
  cpu_push_hl();
  a = 0x05;
  mem_write8(0x8D17, a);
  p04_L_5C6D();
  p00_L_334B();
  set_hl(mem_read16(0x982A));
  return;
}

/* flash page 4 cpu 0x4DB0 (offset 0x0DB0) */
void p04_L_4DB0(void) {
  p04_L_4F3D();
  return;
}

/* flash page 4 cpu 0x4EDD (offset 0x0EDD) */
void p04_L_4EDD(void) {
  e = e;
  if (flag_nz()) goto lab_p04_L_4EE5;
  p04_L_5FBC();
  p04_L_4F3D();
  return;
  lab_p04_L_4EE5: ;
  flag_cmp(a, 0x65);
  if (flag_nz()) goto lab_p04_L_4EEE;
  p04_L_5F65();
  p04_L_4F3D();
  return;
  lab_p04_L_4EEE: ;
  flag_cmp(a, 0x5E);
  if (flag_nz()) goto lab_p04_L_4EF7;
  p04_L_5F49();
  p04_L_4F3D();
  return;
  lab_p04_L_4EF7: ;
  flag_cmp(a, 0x62);
  if (flag_nz()) goto lab_p04_L_4F00;
  p04_L_602F();
  p04_L_4F3D();
  return;
  lab_p04_L_4F00: ;
  flag_cmp(a, 0x60);
  if (flag_nz()) goto lab_p04_L_4F09;
  p04_L_5F1C();
  p04_L_4F3D();
  return;
  lab_p04_L_4F09: ;
  flag_cmp(a, 0x66);
  if (flag_nz()) goto lab_p04_L_4F12;
  p04_L_5FB9();
  goto lab_p04_L_4F43;
  lab_p04_L_4F12: ;
  flag_cmp(a, 0x68);
  if (flag_nz()) goto lab_p04_L_4F1D;
  a = 0x8F;
  p00_L_35EB();
  p04_L_4F3D();
  return;
  lab_p04_L_4F1D: ;
  flag_cmp(a, 0x44);
  if (flag_z()) goto lab_p04_L_4F43;
  flag_cmp(a, 0x6B);
  if (flag_z()) { p04_L_4F3D(); return; }
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p04_L_4F36;
  p00_L_3EFD();
  a = mem_read8(0x8D17);
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p00_L_05F2(); return; }
  lab_p04_L_4F33: ;
  p04_L_5720();
  return;
  lab_p04_L_4F36: ;
  flag_cmp(a, 0x64);
  if (flag_nz()) goto lab_p04_L_4F52;
  p04_L_60A7();
  p04_L_4F3D();
  return;
  lab_p04_L_4F43: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  cpu_push_af();
  if (flag_nz()) p04_L_678F();
  cpu_pop_af();
  if (flag_z()) p04_L_6185();
  p04_L_5720();
  return;
  lab_p04_L_4F52: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  cpu_push_af();
  if (flag_nz()) p04_L_678F();
  cpu_pop_af();
  cpu_push_af();
  if (flag_z()) p04_L_6185();
  cpu_pop_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_4F33;
  flag_cmp(a, 0x75);
  if (flag_nz()) goto lab_p04_L_502C;
  a = 0;
  flag_logic(a);
  mem_write8(0x85FD, a);
  goto lab_p04_L_4F7B;
  lab_p04_L_4F7B: ;
  p04_L_5ADC();
  set_hl(mem_read16(0x980C));
  mem_write16(0x9824, hl());
  if (flag_z()) { p04_L_5720(); return; }
  p04_L_5720();
  p04_L_4FB9();
  a = mem_read8(0x8D1B);
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) p04_L_77FE();
  p00_L_3CC9();
  p00_L_3759();
  mem_write16(0x9706, hl());
  p00_L_3651();
  p00_L_03A0();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 0)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 5)));
  set_hl(0x4572);
  mem_write16(0x8595, hl());
  return;
  lab_p04_L_502C: ;
  set_hl(0x4FFE);
  set_bc(0x000C);
  /* cpir */
  if (flag_nz()) goto lab_p04_L_56E6;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 4)));
  set_hl(0x500A);
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  mem_write8(0x8D17, a);
  set_hl(0x505E);
  a = mem_read8(0x9151);
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_5054;
  a = (uint8_t)(a + 0x08);
  lab_p04_L_5054: ;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  l = mem_read8(hl());
  h = d;
  p04_L_6715();
  goto lab_p04_L_507D;
  lab_p04_L_507D: ;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 6)));
  mem_write16(0x8E67, hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_5099;
  set_hl(0x0000);
  mem_write16(0x8E65, hl());
  mem_write16(0x8D1A, hl());
  mem_write16(0x9810, hl());
  mem_write16(0x980E, hl());
  lab_p04_L_5099: ;
  p00_L_35A9();
  a = 0;
  flag_logic(a);
  mem_write8(0x8E63, a);
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 0)));
  p04_L_626B();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_50DC;
  /* set 7,(iy) */
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_50D9;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  p00_L_39F3();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_50CA;
  set_hl(0x8FE0);
  p00_rst20();
  p00_L_39D5();
  lab_p04_L_50CA: ;
  p04_L_51B5();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 4)));
  lab_p04_L_50D9: ;
  p04_L_52EC();
  return;
  lab_p04_L_50DC: ;
  p04_L_449A();
  if (flag_nz()) goto lab_p04_L_50E9;
  p00_L_35AF();
  if (flag_z()) goto lab_p04_L_4F43;
  goto lab_p04_L_5139;
  lab_p04_L_50E9: ;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x4F);
  if (flag_z()) goto lab_p04_L_5139;
  p00_L_01A2();
  if (flag_nz()) p04_L_7298();
  p00_L_0198();
  if (flag_nz()) p04_L_7289();
  goto lab_p04_L_5136;
  lab_p04_L_5136: ;
  p04_L_50FE();
  lab_p04_L_5139: ;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_5182;
  p00_L_39F3();
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x4F);
  if (flag_nz()) goto lab_p04_L_5150;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_517F;
  goto lab_p04_L_5173;
  lab_p04_L_5150: ;
  set_hl(0x8D21);
  p00_rst20();
  /* bit 7,(iy) */
  if (flag_nz()) goto lab_p04_L_516D;
  set_hl(0x8FBC);
  p00_rst20();
  p00_L_0C2A();
  p00_L_15CB();
  if (flag_nz()) { p00_L_2509(); return; }
  p04_L_6726();
  p04_L_501E();
  lab_p04_L_516D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_517C;
  lab_p04_L_5173: ;
  set_hl(0x8FE0);
  p00_rst20();
  p00_L_39D5();
  goto lab_p04_L_517F;
  lab_p04_L_517C: ;
  p04_L_6726();
  lab_p04_L_517F: ;
  p04_L_51B5();
  lab_p04_L_5182: ;
  /* set 7,(iy) */
  a = 0x0B;
  mem_write8(0x8D1B, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_519C;
  p00_L_0189();
  if (flag_z()) { p04_L_51A2(); return; }
  p04_L_6185();
  p04_L_5BA1();
  lab_p04_L_519C: ;
  p00_L_0189();
  if (flag_nz()) { p04_L_5470(); return; }
  p04_L_51A2();
  return;
  lab_p04_L_56E6: ;
  set_hl(0x56CC);
  set_bc(0x000D);
  /* cpir */
  if (flag_nz()) goto lab_p04_L_571D;
  set_hl(0x56D9);
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  if (flag_z()) p04_L_6185();
  cpu_pop_af();
  p04_L_56FE();
  return;
  lab_p04_L_571D: ;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_5723;
  p04_L_5720();
  return;
  lab_p04_L_5723: ;
  p04_L_48BB();
  return;
}

/* flash page 4 cpu 0x4F3D (offset 0x0F3D) */
void p04_L_4F3D(void) {
  goto lab_p04_L_4F3D;
  lab_p04_L_4F33: ;
  p04_L_5720();
  return;
  lab_p04_L_4F3D: ;
  p00_L_0087();
  a = 0;
  flag_logic(a);
  goto lab_p04_L_4F52;
  lab_p04_L_4F43: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  cpu_push_af();
  if (flag_nz()) p04_L_678F();
  cpu_pop_af();
  if (flag_z()) p04_L_6185();
  p04_L_5720();
  return;
  lab_p04_L_4F52: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  cpu_push_af();
  if (flag_nz()) p04_L_678F();
  cpu_pop_af();
  cpu_push_af();
  if (flag_z()) p04_L_6185();
  cpu_pop_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_4F33;
  flag_cmp(a, 0x75);
  if (flag_nz()) goto lab_p04_L_502C;
  a = 0;
  flag_logic(a);
  mem_write8(0x85FD, a);
  goto lab_p04_L_4F7B;
  lab_p04_L_4F7B: ;
  p04_L_5ADC();
  set_hl(mem_read16(0x980C));
  mem_write16(0x9824, hl());
  if (flag_z()) { p04_L_5720(); return; }
  p04_L_5720();
  p04_L_4FB9();
  a = mem_read8(0x8D1B);
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) p04_L_77FE();
  p00_L_3CC9();
  p00_L_3759();
  mem_write16(0x9706, hl());
  p00_L_3651();
  p00_L_03A0();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 0)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 5)));
  set_hl(0x4572);
  mem_write16(0x8595, hl());
  return;
  lab_p04_L_502C: ;
  set_hl(0x4FFE);
  set_bc(0x000C);
  /* cpir */
  if (flag_nz()) goto lab_p04_L_56E6;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 4)));
  set_hl(0x500A);
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  mem_write8(0x8D17, a);
  set_hl(0x505E);
  a = mem_read8(0x9151);
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_5054;
  a = (uint8_t)(a + 0x08);
  lab_p04_L_5054: ;
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  l = mem_read8(hl());
  h = d;
  p04_L_6715();
  goto lab_p04_L_507D;
  lab_p04_L_507D: ;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 6)));
  mem_write16(0x8E67, hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_5099;
  set_hl(0x0000);
  mem_write16(0x8E65, hl());
  mem_write16(0x8D1A, hl());
  mem_write16(0x9810, hl());
  mem_write16(0x980E, hl());
  lab_p04_L_5099: ;
  p00_L_35A9();
  a = 0;
  flag_logic(a);
  mem_write8(0x8E63, a);
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 0)));
  p04_L_626B();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_50DC;
  /* set 7,(iy) */
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_50D9;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  p00_L_39F3();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_50CA;
  set_hl(0x8FE0);
  p00_rst20();
  p00_L_39D5();
  lab_p04_L_50CA: ;
  p04_L_51B5();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 4)));
  lab_p04_L_50D9: ;
  p04_L_52EC();
  return;
  lab_p04_L_50DC: ;
  p04_L_449A();
  if (flag_nz()) goto lab_p04_L_50E9;
  p00_L_35AF();
  if (flag_z()) goto lab_p04_L_4F43;
  goto lab_p04_L_5139;
  lab_p04_L_50E9: ;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x4F);
  if (flag_z()) goto lab_p04_L_5139;
  p00_L_01A2();
  if (flag_nz()) p04_L_7298();
  p00_L_0198();
  if (flag_nz()) p04_L_7289();
  goto lab_p04_L_5136;
  lab_p04_L_5136: ;
  p04_L_50FE();
  lab_p04_L_5139: ;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_5182;
  p00_L_39F3();
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x4F);
  if (flag_nz()) goto lab_p04_L_5150;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_517F;
  goto lab_p04_L_5173;
  lab_p04_L_5150: ;
  set_hl(0x8D21);
  p00_rst20();
  /* bit 7,(iy) */
  if (flag_nz()) goto lab_p04_L_516D;
  set_hl(0x8FBC);
  p00_rst20();
  p00_L_0C2A();
  p00_L_15CB();
  if (flag_nz()) { p00_L_2509(); return; }
  p04_L_6726();
  p04_L_501E();
  lab_p04_L_516D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_517C;
  lab_p04_L_5173: ;
  set_hl(0x8FE0);
  p00_rst20();
  p00_L_39D5();
  goto lab_p04_L_517F;
  lab_p04_L_517C: ;
  p04_L_6726();
  lab_p04_L_517F: ;
  p04_L_51B5();
  lab_p04_L_5182: ;
  /* set 7,(iy) */
  a = 0x0B;
  mem_write8(0x8D1B, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_519C;
  p00_L_0189();
  if (flag_z()) { p04_L_51A2(); return; }
  p04_L_6185();
  p04_L_5BA1();
  lab_p04_L_519C: ;
  p00_L_0189();
  if (flag_nz()) { p04_L_5470(); return; }
  p04_L_51A2();
  return;
  lab_p04_L_56E6: ;
  set_hl(0x56CC);
  set_bc(0x000D);
  /* cpir */
  if (flag_nz()) goto lab_p04_L_571D;
  set_hl(0x56D9);
  set_hl((uint16_t)(hl() + bc()));
  a = mem_read8(hl());
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  if (flag_z()) p04_L_6185();
  cpu_pop_af();
  p04_L_56FE();
  return;
  lab_p04_L_571D: ;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_5723;
  p04_L_5720();
  return;
  lab_p04_L_5723: ;
  p04_L_48BB();
  return;
}

/* flash page 4 cpu 0x4F71 (offset 0x0F71) */
void p04_L_4F71(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 3)));
  p04_L_61A6();
  p04_L_5BA1();
  p04_L_5ADC();
  set_hl(mem_read16(0x980C));
  mem_write16(0x9824, hl());
  if (flag_z()) { p04_L_5720(); return; }
  p04_L_5720();
  p04_L_4FB9();
  a = mem_read8(0x8D1B);
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) p04_L_77FE();
  p00_L_3CC9();
  p00_L_3759();
  mem_write16(0x9706, hl());
  p00_L_3651();
  p00_L_03A0();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 0)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 5)));
  set_hl(0x4572);
  mem_write16(0x8595, hl());
  return;
}

/* flash page 4 cpu 0x4FB9 (offset 0x0FB9) */
void p04_L_4FB9(void) {
  p04_L_4FEC();
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  p04_L_4FC8();
  return;
}

/* flash page 4 cpu 0x4FC8 (offset 0x0FC8) */
void p04_L_4FC8(void) {
  goto lab_p04_L_4FCA;
  lab_p04_L_4FCA: ;
  set_hl(0x26C2);
  p00_L_0013();
  if (flag_nz()) goto lab_p04_L_4FE5;
  set_hl(0x26BF);
  p00_L_0198();
  if (flag_nz()) goto lab_p04_L_4FE5;
  set_hl(0x26C5);
  p00_L_01A2();
  if (flag_nz()) goto lab_p04_L_4FE5;
  set_hl(0x26C8);
  lab_p04_L_4FE5: ;
  p00_L_3C87();
  p00_L_3D1D();
  return;
}

/* flash page 4 cpu 0x4FEC (offset 0x0FEC) */
void p04_L_4FEC(void) {
  set_hl(mem_read16(0x97A6));
  l = (uint8_t)(l - 1);
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_4FF8;
  l = 0x03;
  lab_p04_L_4FF8: ;
  h = 0x00;
  mem_write16(0x844B, hl());
  return;
}

/* flash page 4 cpu 0x501E (offset 0x101E) */
void p04_L_501E(void) {
  a = 0x1F;
  p00_L_3633();
  set_hl(0x8FBC);
  p00_L_0BEC();
  p00_L_0C2A();
  return;
}

/* flash page 4 cpu 0x506F (offset 0x106F) */
void p04_L_506F(void) {
  goto lab_p04_L_506F;
  lab_p04_L_4F43: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  cpu_push_af();
  if (flag_nz()) p04_L_678F();
  cpu_pop_af();
  if (flag_z()) p04_L_6185();
  p04_L_5720();
  return;
  lab_p04_L_506F: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p04_L_507D;
  cpu_push_hl();
  p04_L_6185();
  p04_L_5BA1();
  cpu_pop_hl();
  lab_p04_L_507D: ;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 6)));
  mem_write16(0x8E67, hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_5099;
  set_hl(0x0000);
  mem_write16(0x8E65, hl());
  mem_write16(0x8D1A, hl());
  mem_write16(0x9810, hl());
  mem_write16(0x980E, hl());
  lab_p04_L_5099: ;
  p00_L_35A9();
  a = 0;
  flag_logic(a);
  mem_write8(0x8E63, a);
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 0)));
  p04_L_626B();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_50DC;
  /* set 7,(iy) */
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_50D9;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  p00_L_39F3();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_50CA;
  set_hl(0x8FE0);
  p00_rst20();
  p00_L_39D5();
  lab_p04_L_50CA: ;
  p04_L_51B5();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 4)));
  lab_p04_L_50D9: ;
  p04_L_52EC();
  return;
  lab_p04_L_50DC: ;
  p04_L_449A();
  if (flag_nz()) goto lab_p04_L_50E9;
  p00_L_35AF();
  if (flag_z()) goto lab_p04_L_4F43;
  goto lab_p04_L_5139;
  lab_p04_L_50E9: ;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x4F);
  if (flag_z()) goto lab_p04_L_5139;
  p00_L_01A2();
  if (flag_nz()) p04_L_7298();
  p00_L_0198();
  if (flag_nz()) p04_L_7289();
  goto lab_p04_L_5136;
  lab_p04_L_5136: ;
  p04_L_50FE();
  lab_p04_L_5139: ;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_5182;
  p00_L_39F3();
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x4F);
  if (flag_nz()) goto lab_p04_L_5150;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_517F;
  goto lab_p04_L_5173;
  lab_p04_L_5150: ;
  set_hl(0x8D21);
  p00_rst20();
  /* bit 7,(iy) */
  if (flag_nz()) goto lab_p04_L_516D;
  set_hl(0x8FBC);
  p00_rst20();
  p00_L_0C2A();
  p00_L_15CB();
  if (flag_nz()) { p00_L_2509(); return; }
  p04_L_6726();
  p04_L_501E();
  lab_p04_L_516D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_517C;
  lab_p04_L_5173: ;
  set_hl(0x8FE0);
  p00_rst20();
  p00_L_39D5();
  goto lab_p04_L_517F;
  lab_p04_L_517C: ;
  p04_L_6726();
  lab_p04_L_517F: ;
  p04_L_51B5();
  lab_p04_L_5182: ;
  /* set 7,(iy) */
  a = 0x0B;
  mem_write8(0x8D1B, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_519C;
  p00_L_0189();
  if (flag_z()) { p04_L_51A2(); return; }
  p04_L_6185();
  p04_L_5BA1();
  lab_p04_L_519C: ;
  p00_L_0189();
  if (flag_nz()) { p04_L_5470(); return; }
  p04_L_51A2();
  return;
}

/* flash page 4 cpu 0x50FE (offset 0x10FE) */
void p04_L_50FE(void) {
  set_hl(mem_read16(0x8E67));
  /* bit 7,(iy) */
  if (flag_z()) goto lab_p04_L_511C;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_5119;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  set_hl(0x8D21);
  p00_rst20();
  p00_L_39D5();
  return;
  lab_p04_L_5119: ;
  set_hl(mem_read16(0x8E2B));
  lab_p04_L_511C: ;
  p04_L_6700();
  set_bc(0x8F86);
  p00_L_0198();
  if (flag_nz()) goto lab_p04_L_512E;
  set_bc(0x8FA1);
  p00_L_01A2();
  if (flag_z()) return;
  lab_p04_L_512E: ;
  a = mem_read8(0x8E63);
  a = a | a;
  flag_logic(a);
  if (flag_z()) p04_L_722F();
  return;
}

/* flash page 4 cpu 0x51A2 (offset 0x11A2) */
void p04_L_51A2(void) {
  a = 0x04;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 0)));
  goto lab_p04_L_51EF;
  lab_p04_L_51EF: ;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 1)));
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p04_L_53B2;
  if (flag_c()) goto lab_p04_L_5483;
  flag_cmp(a, 0x0E);
  if (flag_nc()) goto lab_p04_L_5222;
  d = a;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x81);
  if (flag_nz()) goto lab_p04_L_5216;
  set_hl(mem_read16(0x8E65));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x8E65, hl());
  p00_L_3591();
  return;
  lab_p04_L_5216: ;
  set_hl(0x5016);
  set_bc(0x0008);
  /* cpir */
  if (flag_z()) { p04_L_52F1(); return; }
  a = d;
  lab_p04_L_5222: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p04_L_5548;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  a = mem_read8(0x8E63);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_525D;
  p00_L_35AF();
  if (flag_nz()) goto lab_p04_L_5246;
  p04_L_63D8();
  if (flag_nz()) goto lab_p04_L_5246;
  p00_L_35AF();
  b = a;
  a = mem_read8(0x8E63);
  flag_cmp(a, b);
  if (flag_z()) { p04_L_48BB(); return; }
  lab_p04_L_5246: ;
  a = mem_read8(0x8E63);
  p00_L_35C1();
  lab_p04_L_524C: ;
  p00_L_3EFD();
  a = mem_read8(0x8E63);
  p00_L_35AF();
  if (flag_z()) goto lab_p04_L_5274;
  p00_L_3585();
  p04_L_48B5();
  return;
  lab_p04_L_525D: ;
  set_hl(mem_read16(0x9810));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_5277;
  set_de(mem_read16(0x980E));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p04_L_5277;
  set_de((uint16_t)(de() + 1));
  mem_write16(0x980E, de());
  p04_L_52F1();
  return;
  lab_p04_L_5274: ;
  mem_write8(0x8E63, a);
  lab_p04_L_5277: ;
  a = mem_read8(0x8D1B);
  p04_L_63D8();
  if (flag_nz()) goto lab_p04_L_529B;
  p00_L_35AF();
  if (flag_nz()) goto lab_p04_L_529B;
  p04_L_63D8();
  b = a;
  a = mem_read8(0x8D1B);
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p04_L_529B;
  set_hl(mem_read16(0x9810));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_529B;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 7)));
  p04_L_52F1();
  return;
  lab_p04_L_529B: ;
  set_hl(0x0000);
  mem_write16(0x9810, hl());
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x980E, hl());
  a = mem_read8(0x8D1B);
  flag_cmp(a, 0x0A);
  if (flag_z()) goto lab_p04_L_52B7;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_52B7;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_52B7;
  p04_L_52C2();
  lab_p04_L_52B7: ;
  p04_L_63D8();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_52CD;
  mem_write8(0x8D1B, a);
  goto lab_p04_L_524C;
  lab_p04_L_52CD: ;
  mem_write8(0x8D1B, a);
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_52E5;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_52E5;
  set_hl(0x8FE0);
  p00_rst20();
  p00_L_39D5();
  p04_L_51B5();
  lab_p04_L_52E5: ;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 0)));
  p00_L_3EFD();
  p04_L_52EC();
  return;
  lab_p04_L_53B2: ;
  b = 0x01;
  p04_L_53B4();
  return;
  lab_p04_L_5462: ;
  p00_L_0087();
  p04_L_5470();
  return;
  lab_p04_L_5483: ;
  b = 0x01;
  lab_p04_L_5485: ;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 4)));
  a = mem_read8(0x8E63);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_5493;
  p00_L_3591();
  return;
  lab_p04_L_5493: ;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 1)));
  p00_L_0013();
  if (flag_z()) goto lab_p04_L_54DB;
  p04_L_5474();
  lab_p04_L_549F: ;
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + c);
  mem_write8(0x8E67, a);
  p04_L_75A2();
  if (flag_c()) goto lab_p04_L_54D1;
  cpu_push_bc();
  p04_L_5C7A();
  a = mem_read8(0x8E67);
  if (flag_nz()) goto lab_p04_L_54BB;
  cpu_pop_bc();
  a = (uint8_t)(a - c);
  mem_write8(0x8E67, a);
  p04_L_54D3();
  return;
  lab_p04_L_54BB: ;
  cpu_push_af();
  p00_L_3EFD();
  p04_L_58BE();
  cpu_pop_de();
  cpu_push_af();
  a = d;
  a = (uint8_t)(a - 0x08);
  h = 0x00;
  l = a;
  cpu_pop_af();
  cpu_pop_bc();
  if (flag_nz()) goto lab_p04_L_5462;
  mem_write16(0x8E67, hl());
  lab_p04_L_54D1: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_549F;
  p04_L_54D3();
  return;
  lab_p04_L_54D6: ;
  set_hl((uint16_t)(hl() + de()));
  if (flag_c()) goto lab_p04_L_54F2;
  lab_p04_L_54D9: ;
  p04_L_54D3();
  return;
  lab_p04_L_54DB: ;
  p00_L_019D();
  if (flag_nz()) goto lab_p04_L_5516;
  set_de(0x0001);
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 7)));
  lab_p04_L_54E7: ;
  set_hl(mem_read16(0x8E67));
  a = e;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p04_L_54D6;
  set_hl((uint16_t)(hl() + de()));
  if (flag_c()) goto lab_p04_L_54D9;
  lab_p04_L_54F2: ;
  cpu_push_de();
  cpu_push_bc();
  mem_write16(0x8E67, hl());
  set_bc(0x8FA1);
  p00_L_01A2();
  if (flag_nz()) goto lab_p04_L_5502;
  set_bc(0x8F86);
  lab_p04_L_5502: ;
  p04_L_722F();
  cpu_pop_bc();
  cpu_pop_de();
  if (flag_c()) goto lab_p04_L_553F;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 1)));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_54E7;
  p04_L_5513();
  return;
  lab_p04_L_5516: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_5525;
  set_hl(0x8D21);
  p00_L_186A();
  p04_L_54D3();
  return;
  lab_p04_L_5525: ;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 7)));
  lab_p04_L_5529: ;
  cpu_push_bc();
  p04_L_6F32();
  if (flag_c()) goto lab_p04_L_553E;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 7)));
  p04_L_6726();
  p00_L_3ABF();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_5529;
  p04_L_5513();
  return;
  lab_p04_L_553E: ;
  cpu_pop_bc();
  lab_p04_L_553F: ;
  set_hl(mem_read16(0x8E67));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x8E67, hl());
  p04_L_5513();
  return;
  lab_p04_L_5548: ;
  flag_cmp(a, 0x0E);
  if (flag_c()) goto lab_p04_L_5558;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 0)));
  b = 0x05;
  if (flag_nz()) goto lab_p04_L_5485;
  p04_L_53B4();
  return;
  lab_p04_L_5558: ;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 0)));
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  a = mem_read8(0x8E63);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_559E;
  p00_L_35BB();
  if (flag_nz()) goto lab_p04_L_557F;
  a = 0x0B;
  p04_L_63DC();
  if (flag_nz()) goto lab_p04_L_557F;
  a = 0x04;
  p00_L_35BB();
  b = a;
  a = mem_read8(0x8E63);
  flag_cmp(a, b);
  if (flag_z()) { p04_L_48BB(); return; }
  lab_p04_L_557F: ;
  a = mem_read8(0x8E63);
  p00_L_35C1();
  p04_L_5585();
  return;
  lab_p04_L_559E: ;
  set_hl(mem_read16(0x9810));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_55B5;
  set_de(mem_read16(0x980E));
  set_de((uint16_t)(de() - 1));
  a = e;
  a = a | d;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_55B5;
  mem_write16(0x980E, de());
  p04_L_5513();
  return;
  lab_p04_L_55B5: ;
  a = mem_read8(0x8D1B);
  p04_L_63DC();
  if (flag_nz()) goto lab_p04_L_55DE;
  a = 0x04;
  p00_L_35BB();
  if (flag_nz()) goto lab_p04_L_55DE;
  a = 0x0B;
  p04_L_63DC();
  b = a;
  a = mem_read8(0x8D1B);
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p04_L_55DE;
  set_hl(mem_read16(0x9810));
  a = l;
  a = a | h;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_55DE;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 7)));
  p04_L_52F1();
  return;
  lab_p04_L_55DE: ;
  a = 0;
  flag_logic(a);
  h = a;
  l = a;
  mem_write16(0x9810, hl());
  mem_write8(0x8E63, a);
  a = mem_read8(0x8D1B);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_55F5;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_55F5;
  p04_L_52C2();
  lab_p04_L_55F5: ;
  p04_L_63DC();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_52CD;
  mem_write8(0x8D1B, a);
  a = 0x04;
  mem_write8(0x8E63, a);
  p04_L_5585();
  return;
}

/* flash page 4 cpu 0x51AA (offset 0x11AA) */
void p04_L_51AA(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_21A7();
  set_hl(0x8D21);
  p00_rst20();
  p04_L_51B5();
  return;
}

/* flash page 4 cpu 0x51B5 (offset 0x11B5) */
void p04_L_51B5(void) {
  p00_rst18();
  p04_L_702A();
  p00_L_219B();
  p00_L_3AB9();
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) | (1u << 5)));
  p00_L_1697();
  p00_rst10();
  mem_write16(0x9196, de());
  return;
}

/* flash page 4 cpu 0x52C2 (offset 0x12C2) */
void p04_L_52C2(void) {
  set_hl(mem_read16(0x980C));
  set_de(0x0012);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  return;
}

/* flash page 4 cpu 0x52EC (offset 0x12EC) */
void p04_L_52EC(void) {
  p00_L_019D();
  if (flag_z()) { p04_L_52F1(); return; }
  p04_L_52F1();
  return;
}

/* flash page 4 cpu 0x52F1 (offset 0x12F1) */
void p04_L_52F1(void) {
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 6)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_5300;
  p00_L_0013();
  if (flag_nz()) goto lab_p04_L_5306;
  lab_p04_L_5300: ;
  set_hl(mem_read16(0x8E67));
  p04_L_6700();
  lab_p04_L_5306: ;
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p00_L_0013();
  if (flag_z()) goto lab_p04_L_5607;
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 7)) == 0);
  if (flag_nz()) { p04_L_5340(); return; }
  p04_L_5C6D();
  set_hl(0x8483);
  a = mem_read8(0x8E67);
  mem_write8(0x8D19, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_5333;
  p04_L_43CD();
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x4F);
  if (flag_nz()) p00_L_3321();
  lab_p04_L_5333: ;
  p00_L_336F();
  p04_L_5336();
  return;
  lab_p04_L_5607: ;
  p00_L_01A2();
  if (flag_z()) goto lab_p04_L_5624;
  p04_L_5C6D();
  p00_L_336F();
  p04_L_5467();
  p04_L_5C0A();
  p00_L_334B();
  p00_L_17E0();
  p00_L_337B();
  p04_L_5336();
  return;
  lab_p04_L_5624: ;
  p00_L_019D();
  if (flag_nz()) goto lab_p04_L_5658;
  p04_L_5C6D();
  p00_L_336F();
  p04_L_5467();
  p00_L_018E();
  if (flag_z()) goto lab_p04_L_564C;
  p00_L_332D();
  set_hl(mem_read16(0x9196));
  p00_L_11F8();
  set_hl(0x56B9);
  p00_L_25A2();
  p00_L_3ACB();
  p00_L_25C8();
  lab_p04_L_564C: ;
  p00_L_21E0();
  p04_L_5C0A();
  p00_L_219B();
  p04_L_5336();
  return;
  lab_p04_L_5658: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 7)) == 0);
  if (flag_nz()) { p04_L_5340(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_nz()) { p04_L_5758(); return; }
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  p04_L_5C6D();
  p04_L_56A0();
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_nz()) goto lab_p04_L_5680;
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  lab_p04_L_5680: ;
  p04_L_5467();
  p04_L_5C0A();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  p04_L_5729();
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_nz()) goto lab_p04_L_569D;
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  lab_p04_L_569D: ;
  p04_L_5336();
  return;
}

/* flash page 4 cpu 0x5336 (offset 0x1336) */
void p04_L_5336(void) {
  p00_rst18();
  p00_L_219B();
  p04_L_5467();
  p04_L_5BB6();
  p04_L_5340();
  return;
}

/* flash page 4 cpu 0x5340 (offset 0x1340) */
void p04_L_5340(void) {
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 6)));
  a = mem_read8((uint16_t)(iy + 0x17));
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  set_hl(mem_read16(0x980E));
  a = l;
  a = a | h;
  flag_logic(a);
  flag_cmp(a, 0x01);
  if (flag_z()) p00_L_3375();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 3)));
  cpu_pop_af();
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_536B;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 2)));
  lab_p04_L_536B: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_539A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p04_L_5389;
  p04_L_6721();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_539A;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 4)));
  a = 0x4F;
  mem_write8(0x8D17, a);
  lab_p04_L_5389: ;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 5)));
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 7)));
  return;
  lab_p04_L_539A: ;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 4)));
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_53AE;
  p00_L_3EFD();
  p04_L_48B5();
  return;
  lab_p04_L_53AE: ;
  p04_L_4886();
  return;
}

/* flash page 4 cpu 0x53B4 (offset 0x13B4) */
void p04_L_53B4(void) {
  a = mem_read8(0x8E63);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_53BE;
  p00_L_3597();
  return;
  lab_p04_L_53BE: ;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 2)));
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_541F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_53F0;
  set_hl(0x8D21);
  p00_rst20();
  set_hl(0x8FBC);
  p00_L_1073();
  if (flag_c()) { p04_L_48BB(); return; }
  p00_L_0C2A();
  p04_L_6726();
  p00_L_21A7();
  set_hl(0x8FE0);
  p00_rst20();
  p00_L_39D5();
  p04_L_51B5();
  p04_L_52F1();
  return;
  lab_p04_L_53F0: ;
  cpu_push_bc();
  p04_L_501E();
  p00_L_1100();
  p00_L_39F3();
  cpu_pop_bc();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 7)));
  lab_p04_L_53FF: ;
  cpu_push_bc();
  p00_L_10F8();
  p00_L_107E();
  cpu_pop_bc();
  if (flag_z()) goto lab_p04_L_5417;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 7)));
  cpu_push_bc();
  set_hl(0x9004);
  p00_L_0C25();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_53FF;
  lab_p04_L_5417: ;
  p04_L_6726();
  p00_L_3AB9();
  goto lab_p04_L_5460;
  lab_p04_L_541F: ;
  p04_L_5474();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 4)));
  p00_L_0013();
  set_de(0xFFFF);
  if (flag_z()) goto lab_p04_L_54E3;
  lab_p04_L_542F: ;
  a = mem_read8(0x8E67);
  a = (uint8_t)(a - c);
  mem_write8(0x8E67, a);
  if (flag_nc()) goto lab_p04_L_545E;
  cpu_push_bc();
  p04_L_5C7A();
  a = mem_read8(0x8E67);
  if (flag_nz()) goto lab_p04_L_5448;
  cpu_pop_bc();
  a = (uint8_t)(a + c);
  mem_write8(0x8E67, a);
  goto lab_p04_L_5460;
  lab_p04_L_5448: ;
  cpu_push_af();
  p00_L_3EFD();
  p04_L_58BE();
  cpu_pop_de();
  cpu_push_af();
  a = d;
  a = (uint8_t)(a + 0x08);
  l = a;
  h = 0x00;
  cpu_pop_af();
  cpu_pop_bc();
  if (flag_nz()) goto lab_p04_L_5462;
  mem_write16(0x8E67, hl());
  lab_p04_L_545E: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_542F;
  lab_p04_L_5460: ;
  p04_L_54D3();
  return;
  lab_p04_L_5462: ;
  p00_L_0087();
  p04_L_5470();
  return;
  lab_p04_L_54D6: ;
  set_hl((uint16_t)(hl() + de()));
  if (flag_c()) goto lab_p04_L_54F2;
  lab_p04_L_54D9: ;
  p04_L_54D3();
  return;
  lab_p04_L_54E3: ;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 7)));
  lab_p04_L_54E7: ;
  set_hl(mem_read16(0x8E67));
  a = e;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p04_L_54D6;
  set_hl((uint16_t)(hl() + de()));
  if (flag_c()) goto lab_p04_L_54D9;
  lab_p04_L_54F2: ;
  cpu_push_de();
  cpu_push_bc();
  mem_write16(0x8E67, hl());
  set_bc(0x8FA1);
  p00_L_01A2();
  if (flag_nz()) goto lab_p04_L_5502;
  set_bc(0x8F86);
  lab_p04_L_5502: ;
  p04_L_722F();
  cpu_pop_bc();
  cpu_pop_de();
  if (flag_c()) goto lab_p04_L_553F;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 1)));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_54E7;
  p04_L_5513();
  return;
  lab_p04_L_553F: ;
  set_hl(mem_read16(0x8E67));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x8E67, hl());
  p04_L_5513();
  return;
}

/* flash page 4 cpu 0x5467 (offset 0x1467) */
void p04_L_5467(void) {
  p00_L_0189();
  if (flag_z()) return;
  cpu_pop_hl();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  p04_L_5470();
  return;
}

/* flash page 4 cpu 0x5470 (offset 0x1470) */
void p04_L_5470(void) {
  p04_L_5CEA();
  return;
}

/* flash page 4 cpu 0x5474 (offset 0x1474) */
void p04_L_5474(void) {
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 6)));
  c = 0x01;
  p00_L_0013();
  if (flag_z()) return;
  a = mem_read8(0x9151);
  c = a;
  return;
}

/* flash page 4 cpu 0x54D3 (offset 0x14D3) */
void p04_L_54D3(void) {
  p04_L_52F1();
  return;
}

/* flash page 4 cpu 0x5513 (offset 0x1513) */
void p04_L_5513(void) {
  p04_L_52F1();
  return;
}

/* flash page 4 cpu 0x5585 (offset 0x1585) */
void p04_L_5585(void) {
  goto lab_p04_L_5585;
  lab_p04_L_52CD: ;
  mem_write8(0x8D1B, a);
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_52E5;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_52E5;
  set_hl(0x8FE0);
  p00_rst20();
  p00_L_39D5();
  p04_L_51B5();
  lab_p04_L_52E5: ;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 0)));
  p00_L_3EFD();
  p04_L_52EC();
  return;
  lab_p04_L_5585: ;
  p00_L_3EFD();
  p00_L_35BB();
  if (flag_z()) goto lab_p04_L_5593;
  p00_L_3585();
  p04_L_48B5();
  return;
  lab_p04_L_5593: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x8E63, a);
  a = 0x0B;
  mem_write8(0x8D1B, a);
  goto lab_p04_L_55F5;
  lab_p04_L_55F5: ;
  p04_L_63DC();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_52CD;
  mem_write8(0x8D1B, a);
  a = 0x04;
  mem_write8(0x8E63, a);
  goto lab_p04_L_5585;
}

/* flash page 4 cpu 0x56A0 (offset 0x16A0) */
void p04_L_56A0(void) {
  p00_L_39F3();
  p04_L_56B3();
  if (flag_z()) return;
  set_hl(0x8E3F);
  flag_set_z((a & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p04_L_56B1;
  set_hl(0x8E2D);
  lab_p04_L_56B1: ;
  p00_rst20();
  return;
}

/* flash page 4 cpu 0x56B3 (offset 0x16B3) */
void p04_L_56B3(void) {
  a = mem_read8((uint16_t)(iy + 0x0F));
  a = a & 0x1C;
  flag_logic(a);
  return;
}

/* flash page 4 cpu 0x56FE (offset 0x16FE) */
void p04_L_56FE(void) {
  set_bc(mem_read16(0x8D18));
  mem_write8(0x8D17, a);
  flag_cmp(a, 0x2F);
  if (flag_nz()) goto lab_p04_L_571A;
  a = b;
  flag_cmp(a, 0x5C);
  if (flag_c()) goto lab_p04_L_5710;
  b = 0x5B;
  lab_p04_L_5710: ;
  a = c;
  flag_cmp(a, 0x06);
  if (flag_nc()) goto lab_p04_L_5717;
  c = 0x06;
  lab_p04_L_5717: ;
  p04_L_4896();
  return;
  lab_p04_L_571A: ;
  p04_L_489F();
  return;
}

/* flash page 4 cpu 0x570F (offset 0x170F) */
void p04_L_570F(void) {
  e = e;
  a = c;
  flag_cmp(a, 0x06);
  if (flag_nc()) goto lab_p04_L_5717;
  c = 0x06;
  lab_p04_L_5717: ;
  p04_L_4896();
  return;
}

/* flash page 4 cpu 0x5720 (offset 0x1720) */
void p04_L_5720(void) {
  p04_L_5CEA();
  p04_L_48BB();
  return;
}

/* flash page 4 cpu 0x5729 (offset 0x1729) */
void p04_L_5729(void) {
  a = mem_read8(0x8D1B);
  c = a;
  p04_L_572D();
  return;
}

/* flash page 4 cpu 0x572D (offset 0x172D) */
void p04_L_572D(void) {
  set_hl(0x8E3F);
  a = mem_read8((uint16_t)(iy + 0x0F));
  b = 0x02;
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_5743;
  a = a & 0x1C;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_5743;
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_5754;
  goto lab_p04_L_574F;
  lab_p04_L_5743: ;
  a = c;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p04_L_5754;
  b = 0x01;
  set_hl(0x8E2D);
  if (flag_c()) goto lab_p04_L_5754;
  lab_p04_L_574F: ;
  b = 0x03;
  set_hl(0x8E51);
  lab_p04_L_5754: ;
  cpu_push_bc();
  p00_rst20();
  cpu_pop_bc();
  return;
}

/* flash page 4 cpu 0x5758 (offset 0x1758) */
void p04_L_5758(void) {
  lab_p04_L_5758: ;
  p04_L_5C6D();
  a = mem_read8((uint16_t)(iy + 0x0F));
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_z()) goto lab_p04_L_57B3;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_5779;
  p00_L_3EFD();
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) | (1u << 1)));
  p00_L_128A();
  p04_L_5BBB();
  p04_L_5729();
  p00_rst18();
  goto lab_p04_L_57DA;
  lab_p04_L_5779: ;
  p04_L_5848();
  a = mem_read8((uint16_t)(iy + 0x17));
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  p00_L_3ABF();
  cpu_pop_af();
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_5790;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 2)));
  lab_p04_L_5790: ;
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) & ~(1u << 5)));
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) & ~(1u << 1)));
  p04_L_5729();
  p00_rst08();
  p00_L_22FC();
  p00_L_1100();
  p00_L_1276();
  p04_L_57A5();
  return;
  lab_p04_L_57B3: ;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_581D;
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) | (1u << 1)));
  p04_L_5729();
  p00_L_10DD();
  p00_rst08();
  p00_L_22F2();
  p00_L_2333();
  p00_L_3EFD();
  p04_L_5855();
  p00_L_22FC();
  p04_L_5BBB();
  p00_L_1867();
  p00_L_22FC();
  lab_p04_L_57DA: ;
  p04_L_5C0F();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  set_hl(0x91D0);
  p00_rst20();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) p00_L_39F3();
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x4F);
  if (flag_nz()) goto lab_p04_L_57FA;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_39F3();
  lab_p04_L_57FA: ;
  set_hl(0x8D21);
  p00_L_1073();
  if (flag_nz()) goto lab_p04_L_5816;
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  set_de(0x8D21);
  set_hl(0x91D0);
  p00_L_1183();
  p04_L_48B5();
  return;
  lab_p04_L_5816: ;
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  goto lab_p04_L_5758;
  lab_p04_L_581D: ;
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) & ~(1u << 1)));
  p04_L_5848();
  a = mem_read8((uint16_t)(iy + 0x17));
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  p00_L_3ABF();
  cpu_pop_af();
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_5838;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 2)));
  lab_p04_L_5838: ;
  p04_L_5729();
  p00_rst08();
  p00_L_22FC();
  p00_L_1100();
  p00_L_10DD();
  p04_L_57A5();
  return;
}

/* flash page 4 cpu 0x578D (offset 0x178D) */
void p04_L_578D(void) {
  /* rl a */
  a = (uint8_t)(a - 0xFD);
  /* rrc a */
  /* xor (hl) */
  mem_write8((uint16_t)(iy + 0x0F), (uint8_t)(mem_read8((uint16_t)(iy + 0x0F)) & ~(1u << 1)));
  p04_L_5729();
  p00_rst08();
  p00_L_22FC();
  p00_L_1100();
  p00_L_1276();
  p04_L_57A5();
  return;
}

/* flash page 4 cpu 0x57A5 (offset 0x17A5) */
void p04_L_57A5(void) {
  p00_L_3EFD();
  p04_L_5855();
  p04_L_5729();
  p04_L_5BBB();
  goto lab_p04_L_57D7;
  lab_p04_L_57D7: ;
  p00_L_22FC();
  p04_L_5C0F();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  set_hl(0x91D0);
  p00_rst20();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) p00_L_39F3();
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x4F);
  if (flag_nz()) goto lab_p04_L_57FA;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_39F3();
  lab_p04_L_57FA: ;
  set_hl(0x8D21);
  p00_L_1073();
  if (flag_nz()) goto lab_p04_L_5816;
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  set_de(0x8D21);
  set_hl(0x91D0);
  p00_L_1183();
  p04_L_48B5();
  return;
  lab_p04_L_5816: ;
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p04_L_5758();
  return;
}

/* flash page 4 cpu 0x57CD (offset 0x17CD) */
void p04_L_57CD(void) {
  e = b;
  p00_L_22FC();
  p04_L_5BBB();
  p00_L_1867();
  p00_L_22FC();
  p04_L_5C0F();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  set_hl(0x91D0);
  p00_rst20();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  if (flag_nz()) p00_L_39F3();
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x4F);
  if (flag_nz()) goto lab_p04_L_57FA;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_39F3();
  lab_p04_L_57FA: ;
  set_hl(0x8D21);
  p00_L_1073();
  if (flag_nz()) goto lab_p04_L_5816;
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  set_de(0x8D21);
  set_hl(0x91D0);
  p00_L_1183();
  p04_L_48B5();
  return;
  lab_p04_L_5816: ;
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p04_L_5758();
  return;
}

/* flash page 4 cpu 0x57FE (offset 0x17FE) */
void p04_L_57FE(void) {
  mem_write8(hl(), e);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_5821;
  d = (uint8_t)(d + 1);
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  set_de(0x8D21);
  set_hl(0x91D0);
  p00_L_1183();
  p04_L_48B5();
  return;
  lab_p04_L_5821: ;
  p04_L_5848();
  a = mem_read8((uint16_t)(iy + 0x17));
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  p00_L_3ABF();
  cpu_pop_af();
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_5838;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 2)));
  lab_p04_L_5838: ;
  p04_L_5729();
  p00_rst08();
  p00_L_22FC();
  p00_L_1100();
  p00_L_10DD();
  p04_L_57A5();
  return;
}

/* flash page 4 cpu 0x5848 (offset 0x1848) */
void p04_L_5848(void) {
  p00_L_1867();
  p00_L_39F3();
  p00_L_0C1B();
  p00_L_39D5();
  return;
}

/* flash page 4 cpu 0x5855 (offset 0x1855) */
void p04_L_5855(void) {
  p00_L_222C();
  set_hl(0x91D0);
  p00_rst20();
  set_hl(0x8FBC);
  p00_L_1073();
  cpu_push_af();
  p00_L_2148();
  cpu_pop_af();
  if (flag_nc()) p00_L_356D();
  return;
}

/* flash page 4 cpu 0x586B (offset 0x186B) */
void p04_L_586B(void) {
  lab_p04_L_586B: ;
  cpu_push_bc();
  cpu_push_de();
  p04_L_42B3();
  cpu_pop_de();
  cpu_push_de();
  set_hl((uint16_t)(hl() + de()));
  set_bc(0x000B);
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_587D;
  c = 0x05;
  lab_p04_L_587D: ;
  e = l;
  d = h;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_588A;
  set_de((uint16_t)(de() + 1));
  /* lddr */
  goto lab_p04_L_588D;
  lab_p04_L_588A: ;
  set_de((uint16_t)(de() - 1));
  while (bc() != 0) { cpu_ldi(); }
  lab_p04_L_588D: ;
  cpu_pop_de();
  cpu_pop_bc();
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p04_L_586B;
  return;
}

/* flash page 4 cpu 0x5893 (offset 0x1893) */
void p04_L_5893(void) {
  b = 0x3F;
  cpu_push_de();
  lab_p04_L_5896: ;
  set_hl((uint16_t)(hl() + de()));
  mem_write8(hl(), 0x00);
  cpu_push_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p04_L_58A5;
  set_hl((uint16_t)(hl() - 1));
  a = 0xF8;
  goto lab_p04_L_58A8;
  lab_p04_L_58A5: ;
  set_hl((uint16_t)(hl() + 1));
  a = 0x3F;
  lab_p04_L_58A8: ;
  /* and (hl) */
  mem_write8(hl(), a);
  cpu_pop_hl();
  set_de(0x000C);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_5896;
  cpu_pop_hl();
  set_de(0x000B);
  set_hl((uint16_t)(hl() + de()));
  set_de((uint16_t)(de() + 1));
  b = 0x3F;
  lab_p04_L_58B8: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 0)));
  set_hl((uint16_t)(hl() + de()));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_58B8;
  return;
}

/* flash page 4 cpu 0x58BE (offset 0x18BE) */
void p04_L_58BE(void) {
  goto lab_p04_L_58BE;
  lab_p04_L_5726: ;
  p00_L_2509();
  return;
  lab_p04_L_58BE: ;
  set_hl(0x5726);
  p00_L_25A2();
  a = 0x02;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3369();
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 0)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 6)));
  set_hl(0x8E73);
  p00_rst20();
  a = 0x08;
  p00_L_3561();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_nz()) p00_L_0E5C();
  p00_rst30();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x8E);
  if (flag_z()) goto lab_p04_L_5726;
  p00_L_0087();
  set_de(0x8E73);
  p00_L_11FD();
  set_hl(0x9152);
  p00_L_0D19();
  p00_L_10DD();
  p00_L_1179();
  a = mem_read8(0x8DA6);
  l = a;
  h = 0x00;
  p00_L_3B55();
  p00_L_0D1F();
  p00_L_10EF();
  p00_L_10DD();
  set_hl(0x8E6A);
  p00_rst20();
  p00_rst30();
  p00_L_3E37();
  p00_L_15FB();
  p00_L_1171();
  p00_L_10EF();
  p00_rst30();
  p00_L_15FB();
  set_hl(0x8F59);
  mem_write16(0x84DD, hl());
  p00_L_3381();
  set_hl(0x84A4);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  set_de(0x8F50);
  p00_L_1183();
  set_hl(0x9152);
  p00_L_11F8();
  set_hl(0x8484);
  p00_L_15F6();
  p00_L_0E5C();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_5959;
  p00_L_0E5C();
  p00_L_113A();
  lab_p04_L_5959: ;
  p00_rst30();
  p00_rst18();
  p04_L_5E32();
  p00_L_2182();
  p00_L_25C8();
  c = 0x3F;
  b = 0x0F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_5974;
  a = mem_read8(0x8DA4);
  a = (uint8_t)(a - 0x09);
  b = a;
  lab_p04_L_5974: ;
  set_de(0x9340);
  cpu_push_bc();
  cpu_push_hl();
  p04_L_586B();
  cpu_pop_hl();
  cpu_pop_bc();
  set_de(0x9872);
  flag_set_z((mem_read8((uint16_t)(iy + 0x3C)) & (1u << 1)) == 0);
  if (flag_nz()) p04_L_586B();
  set_bc(mem_read16(0x8DA3));
  b = (uint8_t)(b - 1);
  c = 0x3F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_5997;
  b = 0x07;
  lab_p04_L_5997: ;
  p04_L_42B3();
  cpu_push_hl();
  set_de(0x9340);
  p04_L_5893();
  cpu_pop_hl();
  set_de(0x9872);
  flag_set_z((mem_read8((uint16_t)(iy + 0x3C)) & (1u << 1)) == 0);
  if (flag_nz()) p04_L_5893();
  p04_L_61A6();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 5)) == 0);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  set_hl(mem_read16(0x8D1A));
  cpu_push_hl();
  set_hl(mem_read16(0x9810));
  cpu_push_hl();
  set_hl(mem_read16(0x980E));
  cpu_push_hl();
  a = mem_read8(0x8E67);
  cpu_push_af();
  p04_L_7302();
  mem_write8((uint16_t)(iy + 0x3C), (uint8_t)(mem_read8((uint16_t)(iy + 0x3C)) & ~(1u << 1)));
  cpu_pop_af();
  cpu_push_af();
  mem_write8(0x8E67, a);
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  set_hl(0x0000);
  mem_write16(0x8D1A, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 1)));
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p04_L_72C4();
  p00_rst18();
  p00_rst18();
  p04_L_7211();
  if (flag_z()) goto lab_p04_L_5AAD;
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_hl();
  mem_write8(0x8E67, a);
  set_hl(0x0000);
  mem_write16(0x9810, hl());
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x980E, hl());
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + 0x08);
  set_hl(0x9151);
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p04_L_5A20;
  a = (uint8_t)(a - 0x10);
  cpu_push_af();
  a = mem_read8(0x8DA4);
  a = (uint8_t)(a - 0x0B);
  d = a;
  cpu_pop_af();
  lab_p04_L_5A1A: ;
  /* sub (hl) */
  flag_cmp(a, d);
  if (flag_nc()) goto lab_p04_L_5A1A;
  goto lab_p04_L_5A25;
  lab_p04_L_5A20: ;
  /* add a,(hl) */
  flag_cmp(a, 0x0A);
  if (flag_c()) goto lab_p04_L_5A20;
  lab_p04_L_5A25: ;
  mem_write8(0x8E68, a);
  p04_L_5A28();
  return;
  lab_p04_L_5AAD: ;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 1)));
  cpu_pop_hl();
  cpu_pop_af();
  mem_write16(0x982A, hl());
  cpu_pop_hl();
  mem_write16(0x980E, hl());
  cpu_pop_hl();
  mem_write16(0x9810, hl());
  cpu_pop_hl();
  mem_write16(0x8D1A, hl());
  cpu_pop_af();
  if (flag_z()) goto lab_p04_L_5AD1;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  lab_p04_L_5AD1: ;
  p00_L_21A4();
  set_hl(mem_read16(0x918C));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  p00_L_0189();
  return;
}

/* flash page 4 cpu 0x5A28 (offset 0x1A28) */
void p04_L_5A28(void) {
  goto lab_p04_L_5A28;
  lab_p04_L_59EB: ;
  p04_L_7211();
  if (flag_z()) goto lab_p04_L_5AAD;
  cpu_pop_hl();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_hl();
  mem_write8(0x8E67, a);
  set_hl(0x0000);
  mem_write16(0x9810, hl());
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x980E, hl());
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + 0x08);
  set_hl(0x9151);
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p04_L_5A20;
  a = (uint8_t)(a - 0x10);
  cpu_push_af();
  a = mem_read8(0x8DA4);
  a = (uint8_t)(a - 0x0B);
  d = a;
  cpu_pop_af();
  lab_p04_L_5A1A: ;
  /* sub (hl) */
  flag_cmp(a, d);
  if (flag_nc()) goto lab_p04_L_5A1A;
  goto lab_p04_L_5A25;
  lab_p04_L_5A20: ;
  /* add a,(hl) */
  flag_cmp(a, 0x0A);
  if (flag_c()) goto lab_p04_L_5A20;
  lab_p04_L_5A25: ;
  mem_write8(0x8E68, a);
  lab_p04_L_5A28: ;
  a = mem_read8(0x8E68);
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 3)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 7)));
  lab_p04_L_5A33: ;
  mem_write8(0x8E67, a);
  set_hl(mem_read16(0x918E));
  p04_L_43CD();
  p00_L_336F();
  p04_L_7151();
  set_de(0x848E);
  p00_L_2318();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1183();
  p00_rst08();
  p00_L_233D();
  set_hl(mem_read16(0x918E));
  p00_rst20();
  p00_L_235C();
  p04_L_6FA4();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 3)) == 0);
  if (flag_z()) p04_L_718E();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p00_L_0189();
  if (flag_nz()) goto lab_p04_L_5AAD;
  p04_L_70C2();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p04_L_5AA0;
  set_hl(0x8DA6);
  a = mem_read8(0x8E67);
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p04_L_5AA0;
  cpu_cp_hl();
  if (flag_nc()) goto lab_p04_L_5AA0;
  set_hl(0x9151);
  /* add a,(hl) */
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_5A9B;
  /* sub (hl) */
  /* sub (hl) */
  if (flag_nc()) goto lab_p04_L_5A9B;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 7)));
  lab_p04_L_5A9B: ;
  mem_write8(0x8E67, a);
  goto lab_p04_L_5A33;
  lab_p04_L_5AA0: ;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 7)));
  p04_L_712A();
  if (flag_nc()) goto lab_p04_L_59EB;
  goto lab_p04_L_5A28;
  lab_p04_L_5AAD: ;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 1)));
  cpu_pop_hl();
  cpu_pop_af();
  mem_write16(0x982A, hl());
  cpu_pop_hl();
  mem_write16(0x980E, hl());
  cpu_pop_hl();
  mem_write16(0x9810, hl());
  cpu_pop_hl();
  mem_write16(0x8D1A, hl());
  cpu_pop_af();
  if (flag_z()) goto lab_p04_L_5AD1;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  lab_p04_L_5AD1: ;
  p00_L_21A4();
  set_hl(mem_read16(0x918C));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  p00_L_0189();
  return;
}

/* flash page 4 cpu 0x5ADC (offset 0x1ADC) */
void p04_L_5ADC(void) {
  p04_L_626B();
  a = 0;
  flag_logic(a);
  p04_L_63D8();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 4 cpu 0x5AE5 (offset 0x1AE5) */
void p04_L_5AE5(void) {
  cpu_push_af();
  p00_L_1653();
  cpu_pop_af();
  if (flag_nc()) goto lab_p04_L_5B51;
  set_hl(0x8F50);
  p00_L_0013();
  if (flag_nz()) goto lab_p04_L_5B22;
  set_hl(0x8F86);
  p00_L_0198();
  if (flag_nz()) goto lab_p04_L_5B22;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_5B1F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_5B12;
  p00_L_187F();
  set_hl(0x8FE0);
  p00_L_11F8();
  goto lab_p04_L_5B1A;
  lab_p04_L_5B12: ;
  p00_rst18();
  p04_L_501E();
  p00_rst08();
  p00_L_219B();
  lab_p04_L_5B1A: ;
  set_hl(0x8FC5);
  goto lab_p04_L_5B25;
  lab_p04_L_5B1F: ;
  set_hl(0x8FA1);
  lab_p04_L_5B22: ;
  p00_L_11F8();
  lab_p04_L_5B25: ;
  cpu_push_hl();
  p00_L_10DD();
  p00_L_107E();
  cpu_pop_hl();
  if (flag_z()) goto lab_p04_L_5B4E;
  cpu_push_af();
  p00_L_1073();
  if (flag_z()) goto lab_p04_L_5B4D;
  if (flag_c()) goto lab_p04_L_5B48;
  cpu_pop_af();
  if (flag_c()) goto lab_p04_L_5B4E;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_5B45;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_5B4E;
  lab_p04_L_5B45: ;
  p00_L_24FD();
  return;
  lab_p04_L_5B48: ;
  cpu_pop_af();
  if (flag_c()) goto lab_p04_L_5B45;
  goto lab_p04_L_5B4E;
  lab_p04_L_5B4D: ;
  cpu_pop_hl();
  lab_p04_L_5B4E: ;
  p00_L_1135();
  lab_p04_L_5B51: ;
  p00_L_0013();
  if (flag_nz()) p00_L_3321();
  p00_L_01A2();
  if (flag_nz()) p00_L_3399();
  p00_L_0198();
  if (flag_nz()) p00_L_3333();
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_5B7F;
  p00_L_14E1();
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_rst18();
  p00_L_1697();
  p00_rst10();
  cpu_push_de();
  p00_L_219B();
  cpu_pop_de();
  mem_write16(0x9196, de());
  p00_L_11FD();
  return;
  lab_p04_L_5B7F: ;
  set_hl(mem_read16(0x84DD));
  mem_write16(0x9196, hl());
  return;
}

/* flash page 4 cpu 0x5B86 (offset 0x1B86) */
void p04_L_5B86(void) {
  p04_L_5C0A();
  mem_write8(0x8E67, a);
  p00_L_38F1();
  p00_L_3339();
  p00_L_336F();
  cpu_pop_bc();
  p04_L_5467();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  cpu_push_bc();
  p04_L_5BB6();
  p04_L_5BA1();
  return;
}

/* flash page 4 cpu 0x5BA1 (offset 0x1BA1) */
void p04_L_5BA1(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p04_L_5BB4;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 6)) == 0);
  if (flag_nz()) p04_L_775A();
  lab_p04_L_5BB4: ;
  cpu_pop_af();
  return;
}

/* flash page 4 cpu 0x5BB6 (offset 0x1BB6) */
void p04_L_5BB6(void) {
  p00_L_018E();
  if (flag_z()) { p04_L_5BFB(); return; }
  p04_L_5BBB();
  return;
}

/* flash page 4 cpu 0x5BBB (offset 0x1BBB) */
void p04_L_5BBB(void) {
  set_hl(0x5BFB);
  p00_L_25A2();
  p00_L_15FB();
  p00_L_25C8();
  p00_L_3327();
  set_hl(0x8478);
  p04_L_4329();
  if (flag_nz()) { p04_L_5BFB(); return; }
  p00_L_1100();
  a = 0;
  flag_logic(a);
  set_de(0x8F6B);
  set_hl(0x8478);
  p04_L_4364();
  p00_L_113F();
  b = a;
  a = 0x01;
  flag_set_z((b & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_5C04;
  a = mem_read8(0x8DA3);
  a = (uint8_t)(a - 1);
  flag_set_z((b & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_5C04;
  set_de(0x8478);
  p04_L_441F();
  lab_p04_L_5BF7: ;
  mem_write8(0x8D18, a);
  return;
  lab_p04_L_5C04: ;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 2)));
  goto lab_p04_L_5BF7;
}

/* flash page 4 cpu 0x5BFB (offset 0x1BFB) */
void p04_L_5BFB(void) {
  goto lab_p04_L_5BFB;
  lab_p04_L_5BF7: ;
  mem_write8(0x8D18, a);
  return;
  lab_p04_L_5BFB: ;
  a = mem_read8(0x8DA3);
  /* srl a */
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 2)));
  goto lab_p04_L_5BF7;
}

/* flash page 4 cpu 0x5C0A (offset 0x1C0A) */
void p04_L_5C0A(void) {
  p00_L_018E();
  if (flag_z()) { p04_L_5C4D(); return; }
  p04_L_5C0F();
  return;
}

/* flash page 4 cpu 0x5C0F (offset 0x1C0F) */
void p04_L_5C0F(void) {
  set_hl(0x5C4D);
  p00_L_25A2();
  p00_L_15FB();
  p00_L_25C8();
  p00_L_3321();
  set_hl(0x8478);
  p04_L_4329();
  if (flag_nz()) { p04_L_5C4D(); return; }
  p00_L_1100();
  a = 0;
  flag_logic(a);
  set_de(0x8F50);
  set_hl(0x8478);
  p04_L_4364();
  p00_L_113F();
  b = a;
  a = 0;
  flag_logic(a);
  flag_set_z((b & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_5C57;
  a = mem_read8(0x8DA6);
  flag_set_z((b & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_5C57;
  set_de(0x8478);
  p04_L_442B();
  lab_p04_L_5C49: ;
  mem_write8(0x8D19, a);
  return;
  lab_p04_L_5C57: ;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 2)));
  goto lab_p04_L_5C49;
}

/* flash page 4 cpu 0x5C4D (offset 0x1C4D) */
void p04_L_5C4D(void) {
  goto lab_p04_L_5C4D;
  lab_p04_L_5C49: ;
  mem_write8(0x8D19, a);
  return;
  lab_p04_L_5C4D: ;
  a = mem_read8(0x8DA4);
  /* srl a */
  a = (uint8_t)(a - 1);
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 2)));
  goto lab_p04_L_5C49;
}

/* flash page 4 cpu 0x5C5D (offset 0x1C5D) */
void p04_L_5C5D(void) {
  set_hl(0x8F50);
  set_de(0x9198);
  mem_write8((uint16_t)(iy + 0x04), (uint8_t)(mem_read8((uint16_t)(iy + 0x04)) | (1u << 7)));
  p04_L_5C67();
  return;
}

/* flash page 4 cpu 0x5C67 (offset 0x1C67) */
void p04_L_5C67(void) {
  set_bc(0x0036);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 4 cpu 0x5C6D (offset 0x1C6D) */
void p04_L_5C6D(void) {
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 7)));
  return;
}

/* flash page 4 cpu 0x5C7A (offset 0x1C7A) */
void p04_L_5C7A(void) {
  a = 0;
  flag_logic(a);
  p00_L_35B5();
  if (flag_z()) goto lab_p04_L_5C86;
  lab_p04_L_5C80: ;
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 1)));
  a = 0;
  flag_logic(a);
  return;
  lab_p04_L_5C86: ;
  p00_L_0013();
  if (flag_z()) goto lab_p04_L_5C91;
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_5C80;
  lab_p04_L_5C91: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_5C80;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x61);
  if (flag_z()) goto lab_p04_L_5C80;
  flag_cmp(a, 0x55);
  if (flag_z()) goto lab_p04_L_5C80;
  flag_cmp(a, 0x57);
  if (flag_z()) goto lab_p04_L_5C80;
  return;
}

/* flash page 4 cpu 0x5CA7 (offset 0x1CA7) */
void p04_L_5CA7(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 6)) == 0);
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 7)) == 0);
  return;
}

/* flash page 4 cpu 0x5CB1 (offset 0x1CB1) */
void p04_L_5CB1(void) {
  p00_L_3315();
  p04_L_4596();
  p00_L_3EFD();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  p04_L_5CDE();
  return;
}

/* flash page 4 cpu 0x5CDE (offset 0x1CDE) */
void p04_L_5CDE(void) {
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 3)));
  p04_L_5CEA();
  return;
}

/* flash page 4 cpu 0x5CEA (offset 0x1CEA) */
void p04_L_5CEA(void) {
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_5D04;
  cpu_push_hl();
  cpu_push_de();
  set_hl(mem_read16(0x980C));
  set_de(mem_read16(0x9824));
  p00_L_192A();
  if (flag_nc()) goto lab_p04_L_5D02;
  mem_write16(0x9824, hl());
  lab_p04_L_5D02: ;
  cpu_pop_de();
  cpu_pop_hl();
  lab_p04_L_5D04: ;
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 0)));
  a = 0;
  flag_logic(a);
  mem_write8(0x8D17, a);
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 2)));
  cpu_pop_af();
  return;
}

/* flash page 4 cpu 0x5D12 (offset 0x1D12) */
void p04_L_5D12(void) {
  cpu_push_af();
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 6)));
  a = 0;
  flag_logic(a);
  mem_write8(0x8F4F, a);
  a = 0x0E;
  mem_write8(0x8478, a);
  set_de(0x8FCE);
  b = 0x06;
  lab_p04_L_5D28: ;
  cpu_push_bc();
  p00_L_11FD();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_5D28;
  set_de(0x9016);
  p00_L_11FD();
  p04_L_5E72();
  p04_L_60F8();
  p04_L_6145();
  p04_L_614A();
  p04_L_612A();
  set_de(0x8E7E);
  set_hl(0x8F50);
  set_bc(0x00CF);
  while (bc() != 0) { cpu_ldi(); }
  p00_L_128A();
  a = 0x40;
  mem_write8(0x847A, a);
  set_de(0x913F);
  p00_L_11FD();
  p00_L_11FD();
  set_hl(0x00D0);
  mem_write16(0x8F4D, hl());
  set_hl(0x00CF);
  mem_write16(0x8E7C, hl());
  set_hl(0x0012);
  mem_write16(0x92B1, hl());
  p04_L_40A8();
  return;
}

/* flash page 4 cpu 0x5D8C (offset 0x1D8C) */
void p04_L_5D8C(void) {
  cpu_push_af();
  cpu_push_de();
  p00_L_11F8();
  p00_rst20();
  p00_L_0C2D();
  p00_L_0D16();
  p00_L_10DD();
  cpu_pop_hl();
  p00_rst20();
  cpu_pop_af();
  if (flag_c()) p00_L_0ECC();
  p00_L_10EF();
  p00_L_0D1F();
  p00_L_10DD();
  p00_L_1108();
  p04_L_5DAD();
  return;
}

/* flash page 4 cpu 0x5DAD (offset 0x1DAD) */
void p04_L_5DAD(void) {
  p00_rst30();
  p00_L_3E37();
  p00_L_15FB();
  p00_L_10EF();
  p00_L_10DD();
  p00_L_113A();
  p00_L_0C2D();
  p00_L_3E37();
  p00_L_15FB();
  return;
}

/* flash page 4 cpu 0x5DC6 (offset 0x1DC6) */
void p04_L_5DC6(void) {
  set_hl(0x8F6B);
  a = mem_read8(0x8DA3);
  a = (uint8_t)(a - 0x02);
  c = a;
  b = 0x00;
  set_de(0x915B);
  p04_L_5DD4();
  return;
}

/* flash page 4 cpu 0x5DD4 (offset 0x1DD4) */
void p04_L_5DD4(void) {
  cpu_push_de();
  cpu_push_bc();
  set_de(0x8483);
  p00_L_1183();
  p00_L_117C();
  p00_L_0C2D();
  p00_L_15CB();
  if (flag_nz()) { p00_L_2509(); return; }
  cpu_pop_hl();
  p00_L_3B55();
  p00_L_0ED0();
  a = mem_read8(0x8479);
  flag_cmp(a, 0xE4);
  if (flag_nc()) { p00_L_2509(); return; }
  p00_L_15FB();
  p00_L_14C7();
  if (flag_z()) { p00_L_2509(); return; }
  cpu_pop_de();
  cpu_push_de();
  p00_L_11FD();
  p00_L_0ECC();
  set_hl(0x847C);
  b = 0x03;
  a = 0x50;
  p04_L_4481();
  set_hl(0x847C);
  b = 0x05;
  p00_L_12AA();
  set_hl(0x0012);
  cpu_pop_de();
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  p00_L_11FD();
  return;
}

/* flash page 4 cpu 0x5E23 (offset 0x1E23) */
void p04_L_5E23(void) {
  set_hl(0x8F50);
  a = mem_read8(0x8DA6);
  c = a;
  b = 0x00;
  set_de(0x9152);
  p04_L_5DD4();
  p04_L_5E32();
  return;
}

/* flash page 4 cpu 0x5E32 (offset 0x1E32) */
void p04_L_5E32(void) {
  set_hl(0x8F50);
  a = mem_read8(0x9153);
  p04_L_5E38();
  return;
}

/* flash page 4 cpu 0x5E38 (offset 0x1E38) */
void p04_L_5E38(void) {
  cpu_push_af();
  p00_rst20();
  p00_L_11F8();
  a = mem_read8(0x847A);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_5E5B;
  a = mem_read8(0x8485);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_5E5B;
  a = mem_read8(0x8479);
  set_hl(0x8484);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p04_L_5E53;
  a = mem_read8(hl());
  lab_p04_L_5E53: ;
  a = (uint8_t)(a - 0x0A);
  cpu_pop_de();
  a = (uint8_t)(a - d);
  if (flag_nc()) { p00_L_2509(); return; }
  return;
  lab_p04_L_5E5B: ;
  cpu_pop_de();
  return;
}

/* flash page 4 cpu 0x5E5D (offset 0x1E5D) */
void p04_L_5E5D(void) {
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 5)));
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 7)));
  return;
}

/* flash page 4 cpu 0x5E6E (offset 0x1E6E) */
void p04_L_5E6E(void) {
  p00_L_0013();
  if (flag_nz()) return;
  p04_L_5E72();
  return;
}

/* flash page 4 cpu 0x5E72 (offset 0x1E72) */
void p04_L_5E72(void) {
  p04_L_5E5D();
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 4)));
  p00_L_0087();
  return;
}

/* flash page 4 cpu 0x5E7C (offset 0x1E7C) */
void p04_L_5E7C(void) {
  goto lab_p04_L_5E7C;
  lab_p04_L_5E79: ;
  p00_L_0087();
  return;
  lab_p04_L_5E7C: ;
  p00_L_019D();
  if (flag_nz()) return;
  p04_L_5E5D();
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 7)));
  goto lab_p04_L_5E79;
}

/* flash page 4 cpu 0x5E89 (offset 0x1E89) */
void p04_L_5E89(void) {
  goto lab_p04_L_5E89;
  lab_p04_L_5E79: ;
  p00_L_0087();
  return;
  lab_p04_L_5E89: ;
  p00_L_0198();
  if (flag_nz()) return;
  p04_L_5E5D();
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 5)));
  goto lab_p04_L_5E79;
}

/* flash page 4 cpu 0x5E96 (offset 0x1E96) */
void p04_L_5E96(void) {
  goto lab_p04_L_5E96;
  lab_p04_L_5E79: ;
  p00_L_0087();
  return;
  lab_p04_L_5E96: ;
  p00_L_01A2();
  if (flag_nz()) return;
  p04_L_5E5D();
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 6)));
  goto lab_p04_L_5E79;
}

/* flash page 4 cpu 0x5EA3 (offset 0x1EA3) */
void p04_L_5EA3(void) {
  p04_L_5C5D();
  p00_L_0FAF();
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  a = mem_read8(0x8DA3);
  a = (uint8_t)(a - 0x02);
  cpu_push_af();
  /* srl a */
  p00_L_3561();
  p00_L_0C2D();
  p00_L_1169();
  cpu_pop_af();
  p00_L_3561();
  p00_rst30();
  p00_L_10DD();
  p00_L_1229();
  p00_L_15F3();
  set_de(0x8F62);
  p00_L_11FD();
  set_de(0x8F7D);
  p00_L_11FD();
  p00_L_113A();
  p00_L_0FAF();
  a = mem_read8(0x8DA6);
  cpu_push_af();
  /* srl a */
  p00_L_3561();
  p00_L_0C2D();
  p00_L_1171();
  cpu_pop_af();
  p00_L_3561();
  p00_rst30();
  p04_L_5EF2();
  return;
}

/* flash page 4 cpu 0x5EF2 (offset 0x1EF2) */
void p04_L_5EF2(void) {
  set_hl(0x8F59);
  mem_write16(0x84DD, hl());
  p00_L_3381();
  p00_L_1135();
  set_hl(0x8F74);
  mem_write16(0x84DD, hl());
  p00_L_3381();
  p00_L_113A();
  a = 0x0A;
  p00_L_3675();
  p00_L_1130();
  set_hl(0x8F6B);
  mem_write16(0x84DD, hl());
  p00_L_3381();
  return;
}

/* flash page 4 cpu 0x5F08 (offset 0x1F08) */
void p04_L_5F08(void) {
  a = mem_read8(0x3E11);
  a = mem_read8(bc());
  p00_L_3675();
  p00_L_1130();
  set_hl(0x8F6B);
  mem_write16(0x84DD, hl());
  p00_L_3381();
  return;
}

/* flash page 4 cpu 0x5F1C (offset 0x1F1C) */
void p04_L_5F1C(void) {
  p04_L_5C5D();
  p00_L_1229();
  set_de(0x8F62);
  p00_L_11FD();
  set_de(0x8F7D);
  p00_L_11FD();
  a = mem_read8(0x8DA6);
  /* srl a */
  p00_L_355B();
  p04_L_60DC();
  a = mem_read8(0x8DA3);
  a = (uint8_t)(a - 0x02);
  /* srl a */
  p04_L_5F40();
  return;
}

/* flash page 4 cpu 0x5F40 (offset 0x1F40) */
void p04_L_5F40(void) {
  p00_L_355B();
  p00_L_15E0();
  p04_L_60D8();
  return;
}

/* flash page 4 cpu 0x5F49 (offset 0x1F49) */
void p04_L_5F49(void) {
  set_hl(0x8F50);
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p04_L_5F55;
  set_hl(0x9198);
  lab_p04_L_5F55: ;
  set_de(0x8478);
  p04_L_5C67();
  p04_L_5C5D();
  set_de(0x8478);
  /* scf */
  cpu_push_af();
  goto lab_p04_L_5F9E;
  lab_p04_L_5F9E: ;
  set_hl(0x8F50);
  b = 0x06;
  cpu_pop_af();
  if (flag_c()) { p04_L_5FA7(); return; }
  cpu_ex_de_hl();
  p04_L_5FA7();
  return;
}

/* flash page 4 cpu 0x5F65 (offset 0x1F65) */
void p04_L_5F65(void) {
  p04_L_5C5D();
  /* scf */
  cpu_push_af();
  p00_L_0198();
  if (flag_z()) goto lab_p04_L_5F86;
  set_hl(0x8F86);
  set_de(0x8EB4);
  goto lab_p04_L_5F91;
  lab_p04_L_5F77: ;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_5F9B;
  set_hl(0x8FBC);
  set_de(0x8EEA);
  b = 0x05;
  goto lab_p04_L_5F93;
  lab_p04_L_5F86: ;
  p00_L_01A2();
  if (flag_z()) goto lab_p04_L_5F77;
  set_hl(0x8FA1);
  set_de(0x8ECF);
  lab_p04_L_5F91: ;
  b = 0x03;
  lab_p04_L_5F93: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p04_L_5F98;
  cpu_ex_de_hl();
  lab_p04_L_5F98: ;
  p04_L_5FA7();
  lab_p04_L_5F9B: ;
  set_de(0x8E7E);
  set_hl(0x8F50);
  b = 0x06;
  cpu_pop_af();
  if (flag_c()) { p04_L_5FA7(); return; }
  cpu_ex_de_hl();
  p04_L_5FA7();
  return;
}

/* flash page 4 cpu 0x5F83 (offset 0x1F83) */
void p04_L_5F83(void) {
  b = (uint8_t)(b - 1);
  goto lab_p04_L_5F93;
  lab_p04_L_5F93: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p04_L_5F98;
  cpu_ex_de_hl();
  lab_p04_L_5F98: ;
  p04_L_5FA7();
  set_de(0x8E7E);
  set_hl(0x8F50);
  b = 0x06;
  cpu_pop_af();
  if (flag_c()) { p04_L_5FA7(); return; }
  cpu_ex_de_hl();
  p04_L_5FA7();
  return;
}

/* flash page 4 cpu 0x5F8D (offset 0x1F8D) */
void p04_L_5F8D(void) {
  /* adc a,a */
  set_de(0x8ECF);
  b = 0x03;
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p04_L_5F98;
  cpu_ex_de_hl();
  lab_p04_L_5F98: ;
  p04_L_5FA7();
  set_de(0x8E7E);
  set_hl(0x8F50);
  b = 0x06;
  cpu_pop_af();
  if (flag_c()) { p04_L_5FA7(); return; }
  cpu_ex_de_hl();
  p04_L_5FA7();
  return;
}

/* flash page 4 cpu 0x5F96 (offset 0x1F96) */
void p04_L_5F96(void) {
  set_bc(0xCDEB);
  a = a & a;
  flag_logic(a);
  e = a;
  set_de(0x8E7E);
  set_hl(0x8F50);
  b = 0x06;
  cpu_pop_af();
  if (flag_c()) { p04_L_5FA7(); return; }
  cpu_ex_de_hl();
  p04_L_5FA7();
  return;
}

/* flash page 4 cpu 0x5FA7 (offset 0x1FA7) */
void p04_L_5FA7(void) {
  lab_p04_L_5FA7: ;
  p00_L_16FA();
  cpu_ex_de_hl();
  cpu_push_bc();
  cpu_push_de();
  p00_L_1183();
  cpu_ex_de_hl();
  /* ex (sp),hl */
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_5FA7;
  return;
}

/* flash page 4 cpu 0x5FB9 (offset 0x1FB9) */
void p04_L_5FB9(void) {
  goto lab_p04_L_5FB9;
  lab_p04_L_5F69: ;
  cpu_push_af();
  p00_L_0198();
  if (flag_z()) goto lab_p04_L_5F86;
  set_hl(0x8F86);
  set_de(0x8EB4);
  goto lab_p04_L_5F91;
  lab_p04_L_5F77: ;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_5F9B;
  set_hl(0x8FBC);
  set_de(0x8EEA);
  b = 0x05;
  goto lab_p04_L_5F93;
  lab_p04_L_5F86: ;
  p00_L_01A2();
  if (flag_z()) goto lab_p04_L_5F77;
  set_hl(0x8FA1);
  set_de(0x8ECF);
  lab_p04_L_5F91: ;
  b = 0x03;
  lab_p04_L_5F93: ;
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p04_L_5F98;
  cpu_ex_de_hl();
  lab_p04_L_5F98: ;
  p04_L_5FA7();
  lab_p04_L_5F9B: ;
  set_de(0x8E7E);
  set_hl(0x8F50);
  b = 0x06;
  cpu_pop_af();
  if (flag_c()) { p04_L_5FA7(); return; }
  cpu_ex_de_hl();
  p04_L_5FA7();
  return;
  lab_p04_L_5FB9: ;
  a = a | a;
  flag_logic(a);
  goto lab_p04_L_5F69;
}

/* flash page 4 cpu 0x5FBC (offset 0x1FBC) */
void p04_L_5FBC(void) {
  set_hl(0x6094);
  p00_L_25A2();
  p04_L_5C5D();
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_5FD5;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_34AD();
  p04_L_5FD1();
  return;
  lab_p04_L_5FD5: ;
  p00_L_009B();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 2)));
  p04_L_678F();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 2)));
  p00_L_2324();
  a = mem_read8(0x8478);
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p04_L_601D;
  p00_L_3E37();
  p00_L_15FB();
  p00_L_2375();
  p00_L_22CF();
  p00_L_3E37();
  p00_L_15FB();
  p00_L_2389();
  p00_L_219B();
  p00_L_3E37();
  p00_L_15FB();
  p00_L_10DD();
  p00_L_219B();
  p00_L_3E37();
  p00_L_15FB();
  p00_L_35E5();
  lab_p04_L_601D: ;
  set_hl(mem_read16(0x980C));
  mem_write16(0x9824, hl());
  p00_L_25C8();
  p00_L_019D();
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) return;
  p04_L_602F();
  return;
}

/* flash page 4 cpu 0x5FD1 (offset 0x1FD1) */
void p04_L_5FD1(void) {
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 2)));
  p00_L_009B();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 2)));
  p04_L_678F();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 2)));
  p00_L_2324();
  a = mem_read8(0x8478);
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p04_L_601D;
  p00_L_3E37();
  p00_L_15FB();
  p00_L_2375();
  p00_L_22CF();
  p00_L_3E37();
  p00_L_15FB();
  p00_L_2389();
  p00_L_219B();
  p00_L_3E37();
  p00_L_15FB();
  p00_L_10DD();
  p00_L_219B();
  p00_L_3E37();
  p00_L_15FB();
  p00_L_35E5();
  lab_p04_L_601D: ;
  set_hl(mem_read16(0x980C));
  mem_write16(0x9824, hl());
  p00_L_25C8();
  p00_L_019D();
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) return;
  p04_L_602F();
  return;
}

/* flash page 4 cpu 0x5FEC (offset 0x1FEC) */
void p04_L_5FEC(void) {
  a = (uint8_t)(a + h);
  a = (uint8_t)(a + 1);
  if (flag_z()) goto lab_p04_L_601D;
  p00_L_3E37();
  p00_L_15FB();
  p00_L_2375();
  p00_L_22CF();
  p00_L_3E37();
  p00_L_15FB();
  p00_L_2389();
  p00_L_219B();
  p00_L_3E37();
  p00_L_15FB();
  p00_L_10DD();
  p00_L_219B();
  p00_L_3E37();
  p00_L_15FB();
  p00_L_35E5();
  lab_p04_L_601D: ;
  set_hl(mem_read16(0x980C));
  mem_write16(0x9824, hl());
  p00_L_25C8();
  p00_L_019D();
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) return;
  p04_L_602F();
  return;
}

/* flash page 4 cpu 0x602F (offset 0x202F) */
void p04_L_602F(void) {
  p00_L_0087();
  p04_L_5E23();
  p04_L_5DC6();
  set_hl(0x6094);
  p00_L_25A2();
  set_hl(0x915B);
  p00_rst20();
  set_hl(0x9152);
  p00_L_1073();
  if (flag_c()) goto lab_p04_L_6057;
  if (flag_z()) goto lab_p04_L_6090;
  set_hl(0x8F50);
  a = mem_read8(0x8DA6);
  /* srl a */
  a = a | a;
  flag_logic(a);
  goto lab_p04_L_6065;
  lab_p04_L_6057: ;
  p00_L_1179();
  set_hl(0x8F6B);
  a = mem_read8(0x8DA3);
  a = (uint8_t)(a - 0x02);
  /* srl a */
  /* scf */
  lab_p04_L_6065: ;
  cpu_push_af();
  cpu_push_hl();
  p00_L_3561();
  p00_L_0D1F();
  p00_L_10DD();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_11F7();
  p00_rst30();
  p00_L_0D16();
  p00_L_1171();
  p00_L_10EF();
  p04_L_5DAD();
  p04_L_5C5D();
  cpu_pop_de();
  p00_L_11FD();
  set_hl(0x8499);
  p00_L_1183();
  cpu_pop_af();
  lab_p04_L_6090: ;
  p00_L_25C8();
  return;
}

/* flash page 4 cpu 0x60A7 (offset 0x20A7) */
void p04_L_60A7(void) {
  p04_L_5C5D();
  a = 0x5A;
  p00_L_355B();
  /* bit 2,(iy) */
  if (flag_z()) p00_L_0D00();
  set_de(0x8F62);
  p00_L_11FD();
  set_hl(0x609E);
  p00_rst20();
  /* bit 2,(iy) */
  if (flag_z()) p00_L_0D00();
  p04_L_60DF();
  p00_L_1229();
  set_de(0x8F7D);
  p00_L_11FD();
  a = 0x40;
  mem_write8(0x847A, a);
  p04_L_60D8();
  return;
}

/* flash page 4 cpu 0x60D8 (offset 0x20D8) */
void p04_L_60D8(void) {
  a = 0x0C;
  goto lab_p04_L_60E1;
  lab_p04_L_60E1: ;
  cpu_push_af();
  p00_L_1171();
  p00_L_0E4C();
  cpu_pop_af();
  cpu_push_af();
  p00_L_3675();
  p00_L_113A();
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  p00_L_3675();
  p00_L_113A();
  return;
}

/* flash page 4 cpu 0x60DC (offset 0x20DC) */
void p04_L_60DC(void) {
  p00_L_15E0();
  p04_L_60DF();
  return;
}

/* flash page 4 cpu 0x60DF (offset 0x20DF) */
void p04_L_60DF(void) {
  a = 0x0A;
  cpu_push_af();
  p00_L_1171();
  p00_L_0E4C();
  cpu_pop_af();
  cpu_push_af();
  p00_L_3675();
  p00_L_113A();
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  p00_L_3675();
  p00_L_113A();
  return;
}

/* flash page 4 cpu 0x60F8 (offset 0x20F8) */
void p04_L_60F8(void) {
  p00_L_1229();
  a = 0x02;
  p00_L_3675();
  a = 0x03;
  p00_L_3675();
  a = 0x36;
  p00_L_0013();
  if (flag_nz()) p00_L_3675();
  p00_L_15F3();
  p04_L_60D8();
  p04_L_60DF();
  p04_L_5E23();
  p04_L_5DC6();
  p00_L_0013();
  if (flag_nz()) return;
  p00_L_0198();
  if (flag_nz()) { p04_L_6145(); return; }
  p00_L_01A2();
  if (flag_nz()) { p04_L_614A(); return; }
  p04_L_612A();
  return;
}

/* flash page 4 cpu 0x612A (offset 0x212A) */
void p04_L_612A(void) {
  p00_L_1229();
  a = 0x1F;
  p00_L_3675();
  a = 0x1B;
  p00_L_3675();
  a = 0x34;
  p00_L_3675();
  p00_L_15F3();
  a = 0x1D;
  p00_L_3675();
  return;
}

/* flash page 4 cpu 0x6145 (offset 0x2145) */
void p04_L_6145(void) {
  set_hl(0x8F86);
  goto lab_p04_L_614D;
  lab_p04_L_614D: ;
  p00_L_128D();
  mem_write16(0x84DD, hl());
  set_de(0x0009);
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  p00_L_128A();
  a = 0x75;
  mem_write8(0x847A, a);
  /* bit 2,(iy) */
  if (flag_z()) p00_L_0D00();
  cpu_pop_de();
  p00_L_11FD();
  a = 0x30;
  p00_L_3561();
  p00_L_0D1F();
  p00_L_3381();
  return;
}

/* flash page 4 cpu 0x614A (offset 0x214A) */
void p04_L_614A(void) {
  set_hl(0x8FA1);
  p00_L_128D();
  mem_write16(0x84DD, hl());
  set_de(0x0009);
  set_hl((uint16_t)(hl() + de()));
  cpu_push_hl();
  p00_L_128A();
  a = 0x75;
  mem_write8(0x847A, a);
  /* bit 2,(iy) */
  if (flag_z()) p00_L_0D00();
  cpu_pop_de();
  p00_L_11FD();
  a = 0x30;
  p00_L_3561();
  p00_L_0D1F();
  p00_L_3381();
  return;
}

/* flash page 4 cpu 0x6177 (offset 0x2177) */
void p04_L_6177(void) {
  set_hl(0x9340);
  cpu_push_hl();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  set_bc(0x02FF);
  mem_write8(hl(), 0x00);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 4 cpu 0x6185 (offset 0x2185) */
void p04_L_6185(void) {
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 2)));
  p00_L_18B7();
  if (flag_z()) { p04_L_61A6(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_34AD();
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 7)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 6)) == 0);
  if (flag_z()) return;
  p04_L_61A6();
  return;
}

/* flash page 4 cpu 0x61A6 (offset 0x21A6) */
void p04_L_61A6(void) {
  set_hl(0x9340);
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 2)));
  b = 0x20;
  p00_L_17CE();
  if (flag_nz()) goto lab_p04_L_61BB;
  a = mem_read8(0x97A6);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  b = a;
  lab_p04_L_61BB: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_61D3;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_61D3;
  a = b;
  a = (uint8_t)(a - 0x07);
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p04_L_61D2;
  a = (uint8_t)(a - 0x07);
  lab_p04_L_61D2: ;
  b = a;
  lab_p04_L_61D3: ;
  p04_L_6206();
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 6)));
  /* ei */
  p04_L_61DB();
  return;
}

/* flash page 4 cpu 0x61DB (offset 0x21DB) */
void p04_L_61DB(void) {
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_61F6;
  cpu_push_de();
  p00_L_339F();
  b = 0x2F;
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 1)));
  p04_L_401B();
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  p00_L_33A5();
  cpu_pop_de();
  return;
  lab_p04_L_61F6: ;
  p00_L_17CE();
  if (flag_z()) return;
  cpu_push_de();
  set_bc(0x0000);
  set_de(0x5E00);
  p04_L_4025();
  cpu_pop_de();
  return;
}

/* flash page 4 cpu 0x6206 (offset 0x2206) */
void p04_L_6206(void) {
  /* di */
  a = 0x07;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  a = 0x7F;
  lab_p04_L_6210: ;
  cpu_push_bc();
  a = (uint8_t)(a + 1);
  mem_write8(0x8451, a);
  p00_lcd_cmd_07();
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  a = 0x20;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  b = 0x0C;
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_622D;
  b = 0x05;
  lab_p04_L_622D: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p00_lcd_busy_wait();
  lcd_write_data(); /* ti_lcd_op_write(a) */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_622D;
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_6247;
  a = mem_read8(hl());
  a = a | 0x01;
  flag_logic(a);
  p00_lcd_busy_wait();
  lcd_write_data(); /* ti_lcd_op_write(a) */
  set_bc(0x0007);
  set_hl((uint16_t)(hl() + bc()));
  lab_p04_L_6247: ;
  cpu_pop_bc();
  a = mem_read8(0x8451);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_6210;
  a = 0x05;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  return;
}

/* flash page 4 cpu 0x6255 (offset 0x2255) */
void p04_L_6255(void) {
  set_hl(0x0000);
  mem_write16(0x848E, hl());
  mem_write16(0x8490, hl());
  a = 0x02;
  goto lab_p04_L_626C;
  lab_p04_L_626C: ;
  mem_write8(0x8485, a);
  set_hl(mem_read16(0x9824));
  mem_write16(0x980C, hl());
  p00_L_1295();
  p00_rst18();
  p00_rst18();
  a = 0x01;
  p00_L_385B();
  set_hl(0xFE66);
  p04_L_6282();
  return;
}

/* flash page 4 cpu 0x6262 (offset 0x2262) */
void p04_L_6262(void) {
  mem_write8(0x8485, a);
  goto lab_p04_L_627A;
  lab_p04_L_627A: ;
  a = 0x01;
  p00_L_385B();
  set_hl(0xFE66);
  p04_L_6282();
  return;
}

/* flash page 4 cpu 0x6267 (offset 0x2267) */
void p04_L_6267(void) {
  a = 0x06;
  goto lab_p04_L_626C;
  lab_p04_L_626C: ;
  mem_write8(0x8485, a);
  set_hl(mem_read16(0x9824));
  mem_write16(0x980C, hl());
  p00_L_1295();
  p00_rst18();
  p00_rst18();
  a = 0x01;
  p00_L_385B();
  set_hl(0xFE66);
  p04_L_6282();
  return;
}

/* flash page 4 cpu 0x626B (offset 0x226B) */
void p04_L_626B(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x8485, a);
  set_hl(mem_read16(0x9824));
  mem_write16(0x980C, hl());
  p00_L_1295();
  p00_rst18();
  p00_rst18();
  a = 0x01;
  p00_L_385B();
  set_hl(0xFE66);
  p04_L_6282();
  return;
}

/* flash page 4 cpu 0x6282 (offset 0x2282) */
void p04_L_6282(void) {
  lab_p04_L_6282: ;
  cpu_ex_de_hl();
  set_hl(mem_read16(0x982E));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) return;
  cpu_ex_de_hl();
  cpu_push_hl();
  a = mem_read8(hl());
  p00_L_1857();
  if (flag_nz()) { p04_L_634E(); return; }
  b = a;
  a = mem_read8(0x8485);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p04_L_62A4;
  flag_set_z((b & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_62A1;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 3)));
  lab_p04_L_62A1: ;
  p04_L_634E();
  return;
  lab_p04_L_62A4: ;
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p04_L_62AB;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_62FF;
  lab_p04_L_62AB: ;
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_62DB;
  a = mem_read8((uint16_t)(iy + 0x0F));
  a = a & 0x1C;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_62DB;
  cpu_push_hl();
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  cpu_pop_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_62CB;
  flag_cmp(a, 0x82);
  goto lab_p04_L_62D7;
  lab_p04_L_62CB: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p04_L_62D5;
  flag_cmp(a, 0x80);
  goto lab_p04_L_62D7;
  lab_p04_L_62D5: ;
  flag_cmp(a, 0x81);
  lab_p04_L_62D7: ;
  if (flag_z()) { p04_L_634E(); return; }
  goto lab_p04_L_62DF;
  lab_p04_L_62DB: ;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_z()) { p04_L_634E(); return; }
  lab_p04_L_62DF: ;
  a = mem_read8(0x8485);
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_62FF;
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p04_L_62FF;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x4A);
  if (flag_z()) goto lab_p04_L_62FF;
  p00_L_185F();
  if (flag_nz()) goto lab_p04_L_62FF;
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x0B);
  if (flag_nz()) { p04_L_634E(); return; }
  lab_p04_L_62FF: ;
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(0x847A);
  a = a & 0xF0;
  flag_logic(a);
  b = a;
  a = mem_read8(hl());
  a = a & 0xF0;
  flag_logic(a);
  flag_cmp(a, b);
  if (flag_nz()) { p04_L_634E(); return; }
  flag_cmp(a, 0x20);
  a = mem_read8(hl());
  if (flag_nz()) goto lab_p04_L_6319;
  /* srl a */
  lab_p04_L_6319: ;
  a = a & 0x0F;
  flag_logic(a);
  a = (uint8_t)(a + 1);
  b = a;
  a = mem_read8(0x8485);
  flag_cmp(a, 0x03);
  if (flag_nc()) goto lab_p04_L_6355;
  lab_p04_L_6324: ;
  a = b;
  p04_L_6409();
  set_hl(mem_read16(0x980C));
  p00_L_25EA();
  /* or (hl) */
  mem_write8(hl(), a);
  a = mem_read8(0x8485);
  flag_cmp(a, 0x02);
  if (flag_nz()) { p04_L_634E(); return; }
  cpu_pop_hl();
  cpu_push_hl();
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  d = mem_read8(hl());
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl(mem_read16(0x848E));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x848E, hl());
  set_hl(0x8490);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p04_L_634E();
  return;
  lab_p04_L_634F: ;
  p00_L_33AB();
  goto lab_p04_L_6282;
  lab_p04_L_6355: ;
  flag_cmp(a, 0x06);
  if (flag_z()) goto lab_p04_L_6324;
  cpu_pop_hl();
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p04_L_63AA;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p04_L_634F;
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
  if (flag_z()) { p04_L_634E(); return; }
  p00_L_01A2();
  if (flag_z()) goto lab_p04_L_6396;
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  a = a ^ 0x01;
  flag_logic(a);
  d = a;
  mem_write16(0x8479, de());
  a = 0;
  flag_logic(a);
  mem_write8(0x847B, a);
  p00_rst10();
  if (flag_c()) goto lab_p04_L_63A2;
  cpu_ex_de_hl();
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  /* or (hl) */
  if (flag_z()) goto lab_p04_L_63A2;
  cpu_ex_de_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  a = 0x01;
  p00_L_385B();
  lab_p04_L_6396: ;
  cpu_pop_hl();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  lab_p04_L_6399: ;
  p00_L_0087();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 1)));
  goto lab_p04_L_634F;
  lab_p04_L_63A2: ;
  a = 0x01;
  p00_L_385B();
  cpu_pop_hl();
  goto lab_p04_L_634F;
  lab_p04_L_63AA: ;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p04_L_63B6;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p04_L_634F;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 5)));
  goto lab_p04_L_6399;
  lab_p04_L_63B6: ;
  cpu_push_hl();
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
  flag_set_z((mem_read8((uint16_t)(iy + 0x1E)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p04_L_63D1;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x82);
  if (flag_z()) goto lab_p04_L_63D4;
  lab_p04_L_63D1: ;
  p00_L_1F58();
  lab_p04_L_63D4: ;
  cpu_pop_hl();
  goto lab_p04_L_6282;
}

/* flash page 4 cpu 0x634E (offset 0x234E) */
void p04_L_634E(void) {
  cpu_pop_hl();
  p00_L_33AB();
  p04_L_6282();
  return;
}

/* flash page 4 cpu 0x63D8 (offset 0x23D8) */
void p04_L_63D8(void) {
  b = 0x01;
  goto lab_p04_L_63DE;
  lab_p04_L_63DE: ;
  cpu_push_bc();
  b = a;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x7F);
  a = b;
  cpu_pop_bc();
  if (flag_nc()) goto lab_p04_L_63EE;
  a = (uint8_t)(a + b);
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p04_L_63F0;
  lab_p04_L_63EE: ;
  a = 0;
  flag_logic(a);
  return;
  lab_p04_L_63F0: ;
  flag_cmp(a, 0x0B);
  if (flag_c()) goto lab_p04_L_63F6;
  a = 0;
  flag_logic(a);
  return;
  lab_p04_L_63F6: ;
  cpu_push_af();
  set_hl(mem_read16(0x980C));
  p00_L_25EA();
  if (flag_nz()) goto lab_p04_L_6402;
  cpu_pop_af();
  goto lab_p04_L_63DE;
  lab_p04_L_6402: ;
  cpu_pop_af();
  cpu_push_af();
  p00_L_385B();
  cpu_pop_af();
  return;
}

/* flash page 4 cpu 0x63DC (offset 0x23DC) */
void p04_L_63DC(void) {
  b = 0xFF;
  lab_p04_L_63DE: ;
  cpu_push_bc();
  b = a;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x7F);
  a = b;
  cpu_pop_bc();
  if (flag_nc()) goto lab_p04_L_63EE;
  a = (uint8_t)(a + b);
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p04_L_63F0;
  lab_p04_L_63EE: ;
  a = 0;
  flag_logic(a);
  return;
  lab_p04_L_63F0: ;
  flag_cmp(a, 0x0B);
  if (flag_c()) goto lab_p04_L_63F6;
  a = 0;
  flag_logic(a);
  return;
  lab_p04_L_63F6: ;
  cpu_push_af();
  set_hl(mem_read16(0x980C));
  p00_L_25EA();
  if (flag_nz()) goto lab_p04_L_6402;
  cpu_pop_af();
  goto lab_p04_L_63DE;
  lab_p04_L_6402: ;
  cpu_pop_af();
  cpu_push_af();
  p00_L_385B();
  cpu_pop_af();
  return;
}

/* flash page 4 cpu 0x6409 (offset 0x2409) */
void p04_L_6409(void) {
  h = a;
  p00_L_12B1();
  b = a;
  a = h;
  a = a & 0x0F;
  flag_logic(a);
  b = (uint8_t)(b + 1);
  goto lab_p04_L_6416;
  lab_p04_L_6414: ;
  a = (uint8_t)(a + 0x0A);
  lab_p04_L_6416: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_6414;
  return;
}

/* flash page 4 cpu 0x6419 (offset 0x2419) */
void p04_L_6419(void) {
  cpu_push_hl();
  p04_L_5CEA();
  p00_L_15FB();
  p00_L_3339();
  p04_L_5BA1();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_bc();
  mem_write16(0x982A, bc());
  cpu_push_de();
  p04_L_787D();
  return;
}

/* flash page 4 cpu 0x6431 (offset 0x2431) */
void p04_L_6431(void) {
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 1)));
  a = mem_read8(0x8D18);
  mem_write8(0x8D1A, a);
  p04_L_4008();
  goto lab_p04_L_648F;
  lab_p04_L_648F: ;
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x6440 (offset 0x2440) */
void p04_L_6440(void) {
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 1)));
  a = mem_read8(0x8D19);
  mem_write8(0x8D1B, a);
  p04_L_4017();
  goto lab_p04_L_648F;
  lab_p04_L_648F: ;
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x644F (offset 0x244F) */
void p04_L_644F(void) {
  set_de(mem_read16(0x8D1A));
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 1)));
  h = 0x01;
  set_bc(mem_read16(0x8D18));
  goto lab_p04_L_648C;
  lab_p04_L_648C: ;
  p04_L_4029();
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x645F (offset 0x245F) */
void p04_L_645F(void) {
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 1)));
  h = 0x01;
  set_de(mem_read16(0x8D18));
  set_bc(mem_read16(0x8D1A));
  a = d;
  l = e;
  e = c;
  flag_cmp(a, b);
  if (flag_z()) goto lab_p04_L_648A;
  p04_L_4029();
  a = l;
  flag_cmp(a, c);
  if (flag_z()) goto lab_p04_L_648F;
  c = l;
  l = e;
  e = c;
  p04_L_4029();
  e = l;
  l = d;
  d = b;
  p04_L_4029();
  b = l;
  d = l;
  goto lab_p04_L_648C;
  lab_p04_L_648A: ;
  b = d;
  c = l;
  lab_p04_L_648C: ;
  p04_L_4029();
  lab_p04_L_648F: ;
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x6494 (offset 0x2494) */
void p04_L_6494(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 2)) == 0);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_64AB;
  a = 0x05;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_330F();
  if (flag_nz()) return;
  goto lab_p04_L_64B5;
  lab_p04_L_64AB: ;
  a = 0x03;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3369();
  if (flag_nz()) return;
  lab_p04_L_64B5: ;
  a = mem_read8(0x8D17);
  d = 0x02;
  p04_L_6580();
  return;
}

/* flash page 4 cpu 0x64BD (offset 0x24BD) */
void p04_L_64BD(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_64CF;
  a = 0x04;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_330F();
  if (flag_nz()) return;
  goto lab_p04_L_64D9;
  lab_p04_L_64CF: ;
  a = 0x04;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3369();
  if (flag_nz()) return;
  lab_p04_L_64D9: ;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x55);
  if (flag_nz()) goto lab_p04_L_64EB;
  lab_p04_L_64E0: ;
  set_de(0x8D8F);
  set_hl(0x665F);
  p04_L_6619();
  goto lab_p04_L_6518;
  lab_p04_L_64EB: ;
  flag_cmp(a, 0x6B);
  if (flag_z()) goto lab_p04_L_64E0;
  flag_cmp(a, 0x79);
  if (flag_z()) goto lab_p04_L_64E0;
  flag_cmp(a, 0x61);
  if (flag_z()) goto lab_p04_L_64E0;
  flag_cmp(a, 0x6D);
  if (flag_z()) goto lab_p04_L_6503;
  flag_cmp(a, 0x7B);
  if (flag_z()) goto lab_p04_L_6503;
  flag_cmp(a, 0x57);
  if (flag_nz()) goto lab_p04_L_650E;
  lab_p04_L_6503: ;
  set_de(0x8D98);
  set_hl(0x6664);
  p04_L_6619();
  goto lab_p04_L_64E0;
  lab_p04_L_650E: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p04_L_6518;
  flag_cmp(a, 0x81);
  if (flag_z()) goto lab_p04_L_64E0;
  lab_p04_L_6518: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x08)) & (1u << 7)) == 0);
  if (flag_z()) p04_L_48BE();
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x67);
  if (flag_z()) goto lab_p04_L_6530;
  flag_cmp(a, 0x59);
  if (flag_nz()) goto lab_p04_L_6536;
  set_de(0xFFF8);
  p04_L_666E();
  lab_p04_L_6530: ;
  set_de(0xFFFF);
  p04_L_666E();
  lab_p04_L_6536: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 2)) == 0);
  if (flag_z()) return;
  a = mem_read8(0x8D17);
  flag_cmp(a, 0x1D);
  if (flag_nz()) goto lab_p04_L_6547;
  p04_L_644F();
  goto lab_p04_L_6568;
  lab_p04_L_6547: ;
  flag_cmp(a, 0x29);
  if (flag_nz()) goto lab_p04_L_6550;
  p04_L_6440();
  goto lab_p04_L_657B;
  lab_p04_L_6550: ;
  flag_cmp(a, 0x31);
  if (flag_nz()) goto lab_p04_L_6559;
  p04_L_6431();
  goto lab_p04_L_657B;
  lab_p04_L_6559: ;
  flag_cmp(a, 0x27);
  if (flag_nz()) goto lab_p04_L_6561;
  a = a & 0xFE;
  flag_logic(a);
  goto lab_p04_L_656A;
  lab_p04_L_6561: ;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p04_L_657B;
  p04_L_645F();
  lab_p04_L_6568: ;
  a = 0x02;
  lab_p04_L_656A: ;
  set_hl(mem_read16(0x8D18));
  cpu_push_hl();
  set_hl(mem_read16(0x8D1A));
  mem_write16(0x8D18, hl());
  p04_L_6580();
  cpu_pop_hl();
  mem_write16(0x8D18, hl());
  lab_p04_L_657B: ;
  a = mem_read8(0x8D17);
  a = a & 0xFE;
  flag_logic(a);
  p04_L_6580();
  return;
}

/* flash page 4 cpu 0x6580 (offset 0x2580) */
void p04_L_6580(void) {
  /* srl a */
  if (flag_c()) goto lab_p04_L_65DD;
  d = 0x01;
  a = (uint8_t)(a - 1);
  if (flag_c()) goto lab_p04_L_65D8;
  flag_cmp(a, 0x04);
  if (flag_c()) goto lab_p04_L_659C;
  flag_cmp(a, 0x25);
  if (flag_z()) goto lab_p04_L_6593;
  flag_cmp(a, 0x26);
  lab_p04_L_6593: ;
  a = 0x01;
  if (flag_z()) goto lab_p04_L_659C;
  a = 0x04;
  if (flag_c()) goto lab_p04_L_659C;
  a = (uint8_t)(a + 1);
  lab_p04_L_659C: ;
  h = a;
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + h);
  set_hl(0x6637);
  c = a;
  b = 0x00;
  set_hl((uint16_t)(hl() + bc()));
  set_bc(mem_read16(0x8D18));
  p04_L_65AB();
  return;
  lab_p04_L_65D8: ;
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  return;
  lab_p04_L_65DD: ;
  flag_cmp(a, 0x28);
  a = 0x06;
  if (flag_c()) goto lab_p04_L_659C;
  a = (uint8_t)(a + 1);
  goto lab_p04_L_659C;
}

/* flash page 4 cpu 0x65AB (offset 0x25AB) */
void p04_L_65AB(void) {
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 1)));
  p04_L_65AF();
  return;
}

/* flash page 4 cpu 0x65AF (offset 0x25AF) */
void p04_L_65AF(void) {
  b = (uint8_t)(b + 1);
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  c = (uint8_t)(c + 1);
  e = 0x05;
  lab_p04_L_65B5: ;
  cpu_push_hl();
  set_hl(0x662E);
  a = mem_read8(0x97A6);
  a = (uint8_t)(a + l);
  l = a;
  if (flag_nc()) goto lab_p04_L_65C1;
  h = (uint8_t)(h + 1);
  lab_p04_L_65C1: ;
  a = mem_read8(hl());
  flag_cmp(a, c);
  cpu_pop_hl();
  if (flag_nc()) goto lab_p04_L_65D8;
  cpu_push_bc();
  a = mem_read8(hl());
  lab_p04_L_65C8: ;
  /* srl a */
  if (flag_c()) p04_L_4157();
  if (flag_z()) goto lab_p04_L_65D2;
  b = (uint8_t)(b - 1);
  goto lab_p04_L_65C8;
  lab_p04_L_65D2: ;
  cpu_pop_bc();
  c = (uint8_t)(c - 1);
  set_hl((uint16_t)(hl() + 1));
  e = (uint8_t)(e - 1);
  if (flag_nz()) goto lab_p04_L_65B5;
  lab_p04_L_65D8: ;
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x65E6 (offset 0x25E6) */
void p04_L_65E6(void) {
  flag_cmp(a, 0x01);
  set_hl(0x664B);
  if (flag_z()) goto lab_p04_L_65F1;
  if (flag_nc()) return;
  set_hl(0x6646);
  lab_p04_L_65F1: ;
  set_bc(mem_read16(0x8D18));
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  d = 0x01;
  p04_L_65AF();
  /* scf */
  return;
}

/* flash page 4 cpu 0x6600 (offset 0x2600) */
void p04_L_6600(void) {
  d = 0x04;
  set_hl(0x6669);
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 1)));
  p04_L_65AF();
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x6611 (offset 0x2611) */
void p04_L_6611(void) {
  goto lab_p04_L_6611;
  lab_p04_L_6602: ;
  set_hl(0x6669);
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 1)));
  p04_L_65AF();
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  return;
  lab_p04_L_6611: ;
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) | (1u << 6)));
  d = 0x01;
  goto lab_p04_L_6602;
}

/* flash page 4 cpu 0x6619 (offset 0x2619) */
void p04_L_6619(void) {
  cpu_push_hl();
  p04_L_442B();
  cpu_push_af();
  a = mem_read8(0x8DA3);
  a = (uint8_t)(a - 0x07);
  a = (uint8_t)(a - 0x03);
  c = a;
  cpu_pop_af();
  b = a;
  cpu_pop_hl();
  d = 0x01;
  p04_L_65AB();
  return;
}

/* flash page 4 cpu 0x664B (offset 0x264B) */
void p04_ascii_map(void) {
  /* nop */
  b = (uint8_t)(b + 1);
  c = 0x04;
  /* nop */
  set_de(0x0A0E);
  c = 0x11;
  /* nop */
  /* nop */
  b = (uint8_t)(b + 1);
  /* nop */
  /* nop */
  set_de(0x0400);
  /* nop */
  set_de(0x1810);
  e = (uint8_t)(e + 1);
  goto lab_p04_L_6674;
  lab_p04_L_6674: ;
  /* adc a,l */
  set_hl((uint16_t)(hl() + de()));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  mem_write16(0x8D18, de());
  a = 0x06;
  p04_L_6580();
  cpu_pop_hl();
  mem_write16(0x8D18, hl());
  return;
}

/* flash page 4 cpu 0x6669 (offset 0x2669) */
void p04_ascii_map_2(void) {
  c = 0x11;
  set_de(0x0E11);
  p04_L_666E();
  return;
}

/* flash page 4 cpu 0x666E (offset 0x266E) */
void p04_L_666E(void) {
  set_hl(mem_read16(0x8D18));
  cpu_push_hl();
  set_hl(0x8D98);
  set_hl((uint16_t)(hl() + de()));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  mem_write16(0x8D18, de());
  a = 0x06;
  p04_L_6580();
  cpu_pop_hl();
  mem_write16(0x8D18, hl());
  return;
}

/* flash page 4 cpu 0x6687 (offset 0x2687) */
void p04_L_6687(void) {
  a = c;
  set_hl(0x8DA3);
  cpu_cp_hl();
  if (flag_nc()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x24)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_6697;
  flag_cmp(a, 0x07);
  goto lab_p04_L_6699;
  lab_p04_L_6697: ;
  flag_cmp(a, 0x06);
  lab_p04_L_6699: ;
  /* ccf */
  if (flag_nc()) return;
  a = b;
  set_hl(0x8DA5);
  cpu_cp_hl();
  if (flag_nc()) return;
  flag_cmp(a, 0x00);
  /* ccf */
  return;
}

/* flash page 4 cpu 0x66A5 (offset 0x26A5) */
void p04_L_66A5(void) {
  a = 0xB8;
  set_hl(0x95EC);
  p00_L_17CE();
  if (flag_z()) goto lab_p04_L_66B4;
  a = 0x97;
  set_hl(0x9460);
  lab_p04_L_66B4: ;
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_66C2;
  a = 0xB1;
  set_hl(0x9598);
  b = 0x0E;
  goto lab_p04_L_66C4;
  lab_p04_L_66C2: ;
  b = 0x07;
  lab_p04_L_66C4: ;
  d = a;
  /* di */
  lab_p04_L_66C6: ;
  e = 0x20;
  d = (uint8_t)(d + 1);
  a = d;
  p00_lcd_cmd_07();
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  a = e;
  p00_lcd_busy_wait();
  lcd_write_cmd(); /* ti_lcd_command(a) */
  lab_p04_L_66D8: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  p00_lcd_busy_wait();
  lcd_write_data(); /* ti_lcd_op_write(a) */
  e = (uint8_t)(e + 1);
  a = e;
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_66EA;
  flag_cmp(a, 0x26);
  goto lab_p04_L_66EC;
  lab_p04_L_66EA: ;
  flag_cmp(a, 0x2C);
  lab_p04_L_66EC: ;
  if (flag_nz()) goto lab_p04_L_66D8;
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_66F9;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  lab_p04_L_66F9: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_66C6;
  p00_lcd_cmd_05();
  /* ei */
  return;
}

/* flash page 4 cpu 0x6700 (offset 0x2700) */
void p04_L_6700(void) {
  mem_write16(0x8E67, hl());
  mem_write16(0x8E2B, hl());
  return;
}

/* flash page 4 cpu 0x6715 (offset 0x2715) */
void p04_L_6715(void) {
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 5)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 4)));
  p04_L_6721();
  return;
}

/* flash page 4 cpu 0x6721 (offset 0x2721) */
void p04_L_6721(void) {
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 2)));
  return;
}

/* flash page 4 cpu 0x6726 (offset 0x2726) */
void p04_L_6726(void) {
  set_de(0x8D21);
  p00_L_11FD();
  return;
}

/* flash page 4 cpu 0x6735 (offset 0x2735) */
void p04_str_2(void) {
  h = h;
  mem_write8(hl(), d);
  a = a ^ 0xFF;
  h = h;
  e = e;
  a = (uint8_t)(a - 1);
  /* nop */
  p04_str_5();
  return;
}

/* flash page 4 cpu 0x673C (offset 0x273C) */
void p04_str_5(void) {
  h = h;
  a = b;
  a = a ^ 0xFF;
  h = h;
  mem_write8(hl(), h);
  a = (uint8_t)(a - 1);
  /* nop */
  p04_str_3();
  return;
}

/* flash page 4 cpu 0x6743 (offset 0x2743) */
void p04_str_3(void) {
  h = h;
  a = c;
  a = a ^ 0xFF;
  h = h;
  mem_write8(hl(), h);
  a = (uint8_t)(a - 1);
  /* nop */
  p04_L_674A();
  return;
}

/* flash page 4 cpu 0x674A (offset 0x274A) */
void p04_L_674A(void) {
  goto lab_p04_L_674A;
  lab_p04_L_5D75: ;
  set_hl(0x8F50);
  p00_rst20();
  p00_L_0BEC();
  p00_L_0D16();
  p00_L_1171();
  set_hl(0x8F6B);
  p00_rst20();
  p00_L_0BEC();
  p00_L_0D16();
  return;
  lab_p04_L_674A: ;
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p04_L_6687(); return; }
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p04_L_5D75;
  flag_cmp(a, 0x65);
  if (flag_z()) { p04_L_5FBC(); return; }
  flag_cmp(a, 0x86);
  if (flag_z()) { p04_L_60F8(); return; }
  flag_cmp(a, 0x87);
  if (flag_z()) { p04_L_60A7(); return; }
  flag_cmp(a, 0x8B);
  if (flag_z()) { p04_L_602F(); return; }
  flag_cmp(a, 0x8C);
  if (flag_z()) { p04_L_5EA3(); return; }
  flag_cmp(a, 0x8D);
  if (flag_z()) { p04_L_5F49(); return; }
  flag_cmp(a, 0x8E);
  if (flag_z()) { p04_L_5F1C(); return; }
  flag_cmp(a, 0x90);
  if (flag_z()) { p04_L_5F65(); return; }
  flag_cmp(a, 0x92);
  if (flag_z()) { p04_L_5FB9(); return; }
  flag_cmp(a, 0x93);
  if (flag_z()) { p04_L_4764(); return; }
  return;
}

/* flash page 4 cpu 0x6757 (offset 0x2757) */
void p04_L_6757(void) {
  e = a;
  flag_cmp(a, 0x86);
  if (flag_z()) { p04_L_60F8(); return; }
  flag_cmp(a, 0x87);
  if (flag_z()) { p04_L_60A7(); return; }
  flag_cmp(a, 0x8B);
  if (flag_z()) { p04_L_602F(); return; }
  flag_cmp(a, 0x8C);
  if (flag_z()) { p04_L_5EA3(); return; }
  flag_cmp(a, 0x8D);
  if (flag_z()) { p04_L_5F49(); return; }
  flag_cmp(a, 0x8E);
  if (flag_z()) { p04_L_5F1C(); return; }
  flag_cmp(a, 0x90);
  if (flag_z()) { p04_L_5F65(); return; }
  flag_cmp(a, 0x92);
  if (flag_z()) { p04_L_5FB9(); return; }
  flag_cmp(a, 0x93);
  if (flag_z()) { p04_L_4764(); return; }
  return;
}

/* flash page 4 cpu 0x6786 (offset 0x2786) */
void p04_L_6786(void) {
  set_hl(0x8479);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_rst10();
  if (flag_nc()) p00_L_1F58();
  return;
}

/* flash page 4 cpu 0x678F (offset 0x278F) */
void p04_L_678F(void) {
  /* ei */
  p00_L_3F2D();
  b = a;
  a = 0x00;
  p04_L_7564();
  a = b;
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 7)));
  cpu_push_af();
  a = 0x40;
  mem_write8(0x966D, a);
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 6)));
  /* res 7,(iy) */
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_67C6;
  set_hl(0x8D1E);
  mem_write8(hl(), 0x00);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x01);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x00);
  lab_p04_L_67C6: ;
  p04_L_44E4();
  p04_L_44EB();
  p00_L_0189();
  if (flag_nz()) goto lab_p04_L_6993;
  a = 0x36;
  p00_L_3633();
  p00_L_3B5B();
  mem_write8(0x9151, a);
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_67E9;
  p00_L_0013();
  if (flag_z()) goto lab_p04_L_67F2;
  goto lab_p04_L_67EF;
  lab_p04_L_67E9: ;
  p00_L_35A9();
  p04_L_5DC6();
  lab_p04_L_67EF: ;
  p04_L_5E23();
  lab_p04_L_67F2: ;
  set_hl(0x8F50);
  set_de(0x8E6A);
  p00_L_1183();
  p00_L_128A();
  set_de(0x8E73);
  p00_L_11FD();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  p04_L_756C();
  if (flag_nz()) goto lab_p04_L_686D;
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 2)));
  cpu_pop_bc();
  a = 0x01;
  p04_L_7564();
  a = b;
  p04_L_6818();
  return;
  lab_p04_L_686D: ;
  set_hl(0x0000);
  mem_write16(0x8D1A, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 1)));
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p04_L_626B();
  p00_L_1295();
  p00_rst18();
  p00_rst18();
  p00_L_185F();
  if (flag_z()) goto lab_p04_L_68B8;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 6)));
  p04_L_756C();
  if (flag_nz()) goto lab_p04_L_68C8;
  p00_L_1295();
  a = 0x26;
  p04_L_6896();
  return;
  lab_p04_L_68B8: ;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 1)));
  a = 0;
  flag_logic(a);
  mem_write8(0x8E63, a);
  a = 0x09;
  p04_L_7564();
  if (flag_nz()) { p04_L_6962(); return; }
  lab_p04_L_68C8: ;
  p00_L_0013();
  if (flag_z()) goto lab_p04_L_6A99;
  p04_L_72D8();
  p00_rst18();
  a = 0xFF;
  mem_write8(0x8478, a);
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_68E8;
  p00_rst18();
  set_hl(0x8F50);
  p00_rst20();
  cpu_push_hl();
  p00_rst18();
  cpu_pop_hl();
  p00_rst20();
  p00_rst18();
  goto lab_p04_L_68F0;
  lab_p04_L_68E8: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_6A00;
  p00_rst18();
  lab_p04_L_68F0: ;
  p04_L_7211();
  if (flag_z()) { p04_L_6962(); return; }
  p04_L_70D4();
  lab_p04_L_68F8: ;
  p04_L_72A7();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_755F();
  if (flag_nz()) p04_L_61A6();
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 6)));
  p04_L_6FA4();
  lab_p04_L_690C: ;
  a = 0x03;
  p04_L_7564();
  p04_L_75A9();
  p04_L_7151();
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6921;
  p04_L_7571();
  goto lab_p04_L_6941;
  lab_p04_L_6921: ;
  p04_L_755A();
  if (flag_z()) goto lab_p04_L_692D;
  p00_L_233D();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  lab_p04_L_692D: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  p04_L_717B();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p04_L_6FCD();
  p04_L_755F();
  if (flag_nz()) p04_L_75B3();
  lab_p04_L_6941: ;
  p04_L_7087();
  p04_L_70C2();
  p04_L_69EF();
  if (flag_nc()) goto lab_p04_L_695B;
  set_hl(mem_read16(0x9196));
  b = a;
  a = 0x06;
  p04_L_7564();
  a = b;
  if (flag_z()) p04_L_43CD();
  goto lab_p04_L_690C;
  lab_p04_L_695B: ;
  p04_L_712A();
  if (flag_nc()) goto lab_p04_L_68F0;
  goto lab_p04_L_68F8;
  lab_p04_L_6993: ;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 1)));
  cpu_pop_af();
  p04_L_44E4();
  p04_L_44EB();
  b = a;
  a = 0x07;
  p04_L_7564();
  a = b;
  return;
  lab_p04_L_6A00: ;
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  a = mem_read8(0x9668);
  mem_write8(0x9667, a);
  p04_L_6A10();
  return;
  lab_p04_L_6A99: ;
  p00_L_01A2();
  if (flag_z()) goto lab_p04_L_6C06;
  set_hl(0x8FA1);
  p04_L_6DF3();
  p04_L_72C4();
  a = 0xFF;
  mem_write8(0x8483, a);
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6AB7;
  p00_L_222C();
  goto lab_p04_L_6ABE;
  lab_p04_L_6AB7: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_6B5E;
  lab_p04_L_6ABE: ;
  p00_rst18();
  p00_rst18();
  p04_L_70CF();
  p04_L_6AC3();
  return;
  lab_p04_L_6B5E: ;
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6B68();
  return;
  lab_p04_L_6C06: ;
  p00_L_019D();
  if (flag_nz()) goto lab_p04_L_6E38;
  set_hl(0x8F86);
  p04_L_6DF3();
  p04_L_72C4();
  p04_L_72ED();
  a = 0xFF;
  mem_write8(0x8483, a);
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6C27;
  p00_L_222C();
  goto lab_p04_L_6C2D;
  lab_p04_L_6C27: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_6C98;
  lab_p04_L_6C2D: ;
  p00_L_222C();
  p04_L_70CF();
  p04_L_7289();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6C3A();
  return;
  lab_p04_L_6C98: ;
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6CA2();
  return;
  lab_p04_L_6D2B: ;
  p00_L_1229();
  p00_L_39D5();
  set_hl(0x8F50);
  p00_rst20();
  p04_L_72B6();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6D3C();
  return;
  lab_p04_L_6E35: ;
  p00_L_2509();
  return;
  lab_p04_L_6E38: ;
  set_hl(0x8FC5);
  p00_rst20();
  set_hl(0x8FE0);
  p00_L_1073();
  if (flag_c()) goto lab_p04_L_6E35;
  p04_L_72C4();
  p00_L_21A4();
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6E58;
  a = 0xFF;
  mem_write8(0x8478, a);
  p00_rst18();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  lab_p04_L_6E58: ;
  p04_L_702A();
  if (flag_z()) goto lab_p04_L_6E82;
  a = 0x03;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_6E73;
  a = (uint8_t)(a + a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p04_L_6E73;
  a = (uint8_t)(a - 1);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_6E7E;
  lab_p04_L_6E73: ;
  set_hl(0x91CE);
  b = a;
  /* and (hl) */
  flag_cmp(a, b);
  if (flag_nz()) { p00_L_24FD(); return; }
  goto lab_p04_L_6E85;
  lab_p04_L_6E7E: ;
  a = mem_read8(0x8483);
  a = a | a;
  flag_logic(a);
  lab_p04_L_6E82: ;
  if (flag_z()) { p04_L_6962(); return; }
  lab_p04_L_6E85: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_6D2B;
  p04_L_501E();
  p00_L_3AB9();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6E96();
  return;
}

/* flash page 4 cpu 0x6818 (offset 0x2818) */
void p04_L_6818(void) {
  if (flag_nz()) return;
  cpu_push_af();
  p00_L_185F();
  if (flag_nz()) goto lab_p04_L_6824;
  p04_L_6185();
  goto lab_p04_L_686D;
  lab_p04_L_6824: ;
  a = 0xFF;
  mem_write8(0x9668, a);
  p04_L_6177();
  p00_L_3CFF();
  p00_L_18B7();
  if (flag_nz()) p00_L_34AD();
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 2)));
  a = 0x02;
  p04_L_7564();
  if (flag_z()) p04_L_7302();
  p04_L_61DB();
  p00_L_0189();
  if (flag_nz()) goto lab_p04_L_6993;
  p00_L_32EB();
  set_hl(0x8F50);
  b = 0x17;
  p04_L_72F9();
  set_hl(0x9055);
  b = 0x07;
  p04_L_72F9();
  set_hl(0x92B3);
  b = 0x02;
  p04_L_72F9();
  set_hl(0x8E7E);
  b = 0x17;
  p04_L_72F9();
  lab_p04_L_686D: ;
  set_hl(0x0000);
  mem_write16(0x8D1A, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 1)));
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p04_L_626B();
  p00_L_1295();
  p00_rst18();
  p00_rst18();
  p00_L_185F();
  if (flag_z()) goto lab_p04_L_68B8;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 6)));
  p04_L_756C();
  if (flag_nz()) goto lab_p04_L_68C8;
  p00_L_1295();
  a = 0x26;
  p04_L_6896();
  return;
  lab_p04_L_68B8: ;
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 1)));
  a = 0;
  flag_logic(a);
  mem_write8(0x8E63, a);
  a = 0x09;
  p04_L_7564();
  if (flag_nz()) { p04_L_6962(); return; }
  lab_p04_L_68C8: ;
  p00_L_0013();
  if (flag_z()) goto lab_p04_L_6A99;
  p04_L_72D8();
  p00_rst18();
  a = 0xFF;
  mem_write8(0x8478, a);
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_68E8;
  p00_rst18();
  set_hl(0x8F50);
  p00_rst20();
  cpu_push_hl();
  p00_rst18();
  cpu_pop_hl();
  p00_rst20();
  p00_rst18();
  goto lab_p04_L_68F0;
  lab_p04_L_68E8: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_6A00;
  p00_rst18();
  lab_p04_L_68F0: ;
  p04_L_7211();
  if (flag_z()) { p04_L_6962(); return; }
  p04_L_70D4();
  lab_p04_L_68F8: ;
  p04_L_72A7();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_755F();
  if (flag_nz()) p04_L_61A6();
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 6)));
  p04_L_6FA4();
  lab_p04_L_690C: ;
  a = 0x03;
  p04_L_7564();
  p04_L_75A9();
  p04_L_7151();
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6921;
  p04_L_7571();
  goto lab_p04_L_6941;
  lab_p04_L_6921: ;
  p04_L_755A();
  if (flag_z()) goto lab_p04_L_692D;
  p00_L_233D();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  lab_p04_L_692D: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  p04_L_717B();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p04_L_6FCD();
  p04_L_755F();
  if (flag_nz()) p04_L_75B3();
  lab_p04_L_6941: ;
  p04_L_7087();
  p04_L_70C2();
  p04_L_69EF();
  if (flag_nc()) goto lab_p04_L_695B;
  set_hl(mem_read16(0x9196));
  b = a;
  a = 0x06;
  p04_L_7564();
  a = b;
  if (flag_z()) p04_L_43CD();
  goto lab_p04_L_690C;
  lab_p04_L_695B: ;
  p04_L_712A();
  if (flag_nc()) goto lab_p04_L_68F0;
  goto lab_p04_L_68F8;
  lab_p04_L_6993: ;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 1)));
  cpu_pop_af();
  p04_L_44E4();
  p04_L_44EB();
  b = a;
  a = 0x07;
  p04_L_7564();
  a = b;
  return;
  lab_p04_L_6A00: ;
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  a = mem_read8(0x9668);
  mem_write8(0x9667, a);
  p04_L_6A10();
  return;
  lab_p04_L_6A99: ;
  p00_L_01A2();
  if (flag_z()) goto lab_p04_L_6C06;
  set_hl(0x8FA1);
  p04_L_6DF3();
  p04_L_72C4();
  a = 0xFF;
  mem_write8(0x8483, a);
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6AB7;
  p00_L_222C();
  goto lab_p04_L_6ABE;
  lab_p04_L_6AB7: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_6B5E;
  lab_p04_L_6ABE: ;
  p00_rst18();
  p00_rst18();
  p04_L_70CF();
  p04_L_6AC3();
  return;
  lab_p04_L_6B5E: ;
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6B68();
  return;
  lab_p04_L_6C06: ;
  p00_L_019D();
  if (flag_nz()) goto lab_p04_L_6E38;
  set_hl(0x8F86);
  p04_L_6DF3();
  p04_L_72C4();
  p04_L_72ED();
  a = 0xFF;
  mem_write8(0x8483, a);
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6C27;
  p00_L_222C();
  goto lab_p04_L_6C2D;
  lab_p04_L_6C27: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_6C98;
  lab_p04_L_6C2D: ;
  p00_L_222C();
  p04_L_70CF();
  p04_L_7289();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6C3A();
  return;
  lab_p04_L_6C98: ;
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6CA2();
  return;
  lab_p04_L_6D2B: ;
  p00_L_1229();
  p00_L_39D5();
  set_hl(0x8F50);
  p00_rst20();
  p04_L_72B6();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6D3C();
  return;
  lab_p04_L_6E35: ;
  p00_L_2509();
  return;
  lab_p04_L_6E38: ;
  set_hl(0x8FC5);
  p00_rst20();
  set_hl(0x8FE0);
  p00_L_1073();
  if (flag_c()) goto lab_p04_L_6E35;
  p04_L_72C4();
  p00_L_21A4();
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6E58;
  a = 0xFF;
  mem_write8(0x8478, a);
  p00_rst18();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  lab_p04_L_6E58: ;
  p04_L_702A();
  if (flag_z()) goto lab_p04_L_6E82;
  a = 0x03;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_6E73;
  a = (uint8_t)(a + a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p04_L_6E73;
  a = (uint8_t)(a - 1);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_6E7E;
  lab_p04_L_6E73: ;
  set_hl(0x91CE);
  b = a;
  /* and (hl) */
  flag_cmp(a, b);
  if (flag_nz()) { p00_L_24FD(); return; }
  goto lab_p04_L_6E85;
  lab_p04_L_6E7E: ;
  a = mem_read8(0x8483);
  a = a | a;
  flag_logic(a);
  lab_p04_L_6E82: ;
  if (flag_z()) { p04_L_6962(); return; }
  lab_p04_L_6E85: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_6D2B;
  p04_L_501E();
  p00_L_3AB9();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6E96();
  return;
}

/* flash page 4 cpu 0x6896 (offset 0x2896) */
void p04_L_6896(void) {
  mem_write8(0x8479, a);
  p04_L_6786();
  p04_L_6786();
  p04_L_6786();
  a = 0;
  flag_logic(a);
  mem_write8(0x8E63, a);
  p00_L_357F();
  p04_L_7087();
  p00_L_357F();
  p04_L_7087();
  p00_L_357F();
  p04_L_7087();
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 1)));
  a = 0;
  flag_logic(a);
  mem_write8(0x8E63, a);
  a = 0x09;
  p04_L_7564();
  if (flag_nz()) { p04_L_6962(); return; }
  p00_L_0013();
  if (flag_z()) goto lab_p04_L_6A99;
  p04_L_72D8();
  p00_rst18();
  a = 0xFF;
  mem_write8(0x8478, a);
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_68E8;
  p00_rst18();
  set_hl(0x8F50);
  p00_rst20();
  cpu_push_hl();
  p00_rst18();
  cpu_pop_hl();
  p00_rst20();
  p00_rst18();
  goto lab_p04_L_68F0;
  lab_p04_L_68E8: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_6A00;
  p00_rst18();
  lab_p04_L_68F0: ;
  p04_L_7211();
  if (flag_z()) { p04_L_6962(); return; }
  p04_L_70D4();
  lab_p04_L_68F8: ;
  p04_L_72A7();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_755F();
  if (flag_nz()) p04_L_61A6();
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 6)));
  p04_L_6FA4();
  lab_p04_L_690C: ;
  a = 0x03;
  p04_L_7564();
  p04_L_75A9();
  p04_L_7151();
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6921;
  p04_L_7571();
  goto lab_p04_L_6941;
  lab_p04_L_6921: ;
  p04_L_755A();
  if (flag_z()) goto lab_p04_L_692D;
  p00_L_233D();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  lab_p04_L_692D: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  p04_L_717B();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p04_L_6FCD();
  p04_L_755F();
  if (flag_nz()) p04_L_75B3();
  lab_p04_L_6941: ;
  p04_L_7087();
  p04_L_70C2();
  p04_L_69EF();
  if (flag_nc()) goto lab_p04_L_695B;
  set_hl(mem_read16(0x9196));
  b = a;
  a = 0x06;
  p04_L_7564();
  a = b;
  if (flag_z()) p04_L_43CD();
  goto lab_p04_L_690C;
  lab_p04_L_695B: ;
  p04_L_712A();
  if (flag_nc()) goto lab_p04_L_68F0;
  goto lab_p04_L_68F8;
  lab_p04_L_6A00: ;
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  a = mem_read8(0x9668);
  mem_write8(0x9667, a);
  p04_L_6A10();
  return;
  lab_p04_L_6A99: ;
  p00_L_01A2();
  if (flag_z()) goto lab_p04_L_6C06;
  set_hl(0x8FA1);
  p04_L_6DF3();
  p04_L_72C4();
  a = 0xFF;
  mem_write8(0x8483, a);
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6AB7;
  p00_L_222C();
  goto lab_p04_L_6ABE;
  lab_p04_L_6AB7: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_6B5E;
  lab_p04_L_6ABE: ;
  p00_rst18();
  p00_rst18();
  p04_L_70CF();
  p04_L_6AC3();
  return;
  lab_p04_L_6B5E: ;
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6B68();
  return;
  lab_p04_L_6C06: ;
  p00_L_019D();
  if (flag_nz()) goto lab_p04_L_6E38;
  set_hl(0x8F86);
  p04_L_6DF3();
  p04_L_72C4();
  p04_L_72ED();
  a = 0xFF;
  mem_write8(0x8483, a);
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6C27;
  p00_L_222C();
  goto lab_p04_L_6C2D;
  lab_p04_L_6C27: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_6C98;
  lab_p04_L_6C2D: ;
  p00_L_222C();
  p04_L_70CF();
  p04_L_7289();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6C3A();
  return;
  lab_p04_L_6C98: ;
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6CA2();
  return;
  lab_p04_L_6D2B: ;
  p00_L_1229();
  p00_L_39D5();
  set_hl(0x8F50);
  p00_rst20();
  p04_L_72B6();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6D3C();
  return;
  lab_p04_L_6E35: ;
  p00_L_2509();
  return;
  lab_p04_L_6E38: ;
  set_hl(0x8FC5);
  p00_rst20();
  set_hl(0x8FE0);
  p00_L_1073();
  if (flag_c()) goto lab_p04_L_6E35;
  p04_L_72C4();
  p00_L_21A4();
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6E58;
  a = 0xFF;
  mem_write8(0x8478, a);
  p00_rst18();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  lab_p04_L_6E58: ;
  p04_L_702A();
  if (flag_z()) goto lab_p04_L_6E82;
  a = 0x03;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_6E73;
  a = (uint8_t)(a + a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p04_L_6E73;
  a = (uint8_t)(a - 1);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_6E7E;
  lab_p04_L_6E73: ;
  set_hl(0x91CE);
  b = a;
  /* and (hl) */
  flag_cmp(a, b);
  if (flag_nz()) { p00_L_24FD(); return; }
  goto lab_p04_L_6E85;
  lab_p04_L_6E7E: ;
  a = mem_read8(0x8483);
  a = a | a;
  flag_logic(a);
  lab_p04_L_6E82: ;
  if (flag_z()) { p04_L_6962(); return; }
  lab_p04_L_6E85: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_6D2B;
  p04_L_501E();
  p00_L_3AB9();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6E96();
  return;
}

/* flash page 4 cpu 0x6962 (offset 0x2962) */
void p04_L_6962(void) {
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) & ~(1u << 0)));
  p04_L_756C();
  if (flag_nz()) goto lab_p04_L_698F;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 6)));
  p04_L_6977();
  return;
  lab_p04_L_698F: ;
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 1)));
  cpu_pop_af();
  p04_L_44E4();
  p04_L_44EB();
  b = a;
  a = 0x07;
  p04_L_7564();
  a = b;
  return;
}

/* flash page 4 cpu 0x6977 (offset 0x2977) */
void p04_L_6977(void) {
  p04_L_755F();
  if (flag_nz()) p04_L_61A6();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  set_hl(mem_read16(0x980C));
  mem_write16(0x9824, hl());
  a = 0x01;
  p04_L_6262();
  p04_L_69AF();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 1)));
  cpu_pop_af();
  p04_L_44E4();
  p04_L_44EB();
  b = a;
  a = 0x07;
  p04_L_7564();
  a = b;
  return;
}

/* flash page 4 cpu 0x6996 (offset 0x2996) */
void p04_L_6996(void) {
  /* adc a,(hl) */
  cpu_pop_af();
  p04_L_44E4();
  p04_L_44EB();
  b = a;
  a = 0x07;
  p04_L_7564();
  a = b;
  return;
}

/* flash page 4 cpu 0x69A6 (offset 0x29A6) */
void p04_L_69A6(void) {
  set_de(0x0009);
  lab_p04_L_69A9: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  set_hl((uint16_t)(hl() + de()));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_69A9;
  return;
}

/* flash page 4 cpu 0x69AF (offset 0x29AF) */
void p04_L_69AF(void) {
  set_hl(0x92B3);
  b = 0x02;
  p04_L_69A6();
  p04_L_69B7();
  return;
}

/* flash page 4 cpu 0x69B7 (offset 0x29B7) */
void p04_L_69B7(void) {
  p00_L_16A2();
  set_hl(0x8F50);
  b = 0x06;
  p04_L_69A6();
  p00_L_0013();
  if (flag_nz()) goto lab_p04_L_69EA;
  p00_L_1689();
  set_hl(0x8F86);
  b = 0x03;
  p00_L_0198();
  if (flag_nz()) goto lab_p04_L_69E7;
  p00_L_16AA();
  set_hl(0x8FA1);
  p00_L_01A2();
  if (flag_nz()) goto lab_p04_L_69E7;
  p00_L_1697();
  set_hl(0x8FBC);
  b = 0x09;
  lab_p04_L_69E7: ;
  p04_L_69A6();
  lab_p04_L_69EA: ;
  p00_rst10();
  if (flag_c()) return;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  return;
}

/* flash page 4 cpu 0x69EF (offset 0x29EF) */
void p04_L_69EF(void) {
  a = mem_read8(0x8E67);
  set_hl(0x8DA6);
  cpu_cp_hl();
  if (flag_nc()) return;
  set_hl(0x9151);
  /* add a,(hl) */
  mem_write8(0x8E67, a);
  /* scf */
  return;
}

/* flash page 4 cpu 0x6A10 (offset 0x2A10) */
void p04_L_6A10(void) {
  goto lab_p04_L_6A10;
  lab_p04_L_6A03: ;
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  a = mem_read8(0x9668);
  mem_write8(0x9667, a);
  lab_p04_L_6A10: ;
  p04_L_70A9();
  if (flag_nz()) goto lab_p04_L_6A53;
  p04_L_69EF();
  if (flag_nc()) goto lab_p04_L_6A31;
  p04_L_713E();
  cpu_ex_de_hl();
  set_hl(mem_read16(0x9196));
  cpu_push_hl();
  p00_L_1183();
  cpu_pop_hl();
  p04_L_43CD();
  p04_L_755F();
  if (flag_nz()) p04_L_75B3();
  goto lab_p04_L_6A10;
  lab_p04_L_6A31: ;
  set_de(mem_read16(0x980C));
  set_hl(0x0012);
  set_hl((uint16_t)(hl() + de()));
  p00_L_35D3();
  set_de(0x0009);
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x9824, hl());
  p04_L_755F();
  if (flag_nz()) p04_L_61A6();
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 6)));
  set_hl(mem_read16(0x980E));
  set_hl((uint16_t)(hl() + 1));
  goto lab_p04_L_6A03;
  lab_p04_L_6A53: ;
  a = mem_read8(0x8D1A);
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p04_L_6A65;
  a = mem_read8(0x9667);
  mem_write8(0x9668, a);
  p04_L_755A();
  if (flag_nz()) p04_L_72A7();
  lab_p04_L_6A65: ;
  p04_L_6FA4();
  p04_L_75A9();
  p04_L_755A();
  if (flag_nz()) p00_L_21E5();
  p04_L_7151();
  p04_L_7162();
  p00_L_11FD();
  p04_L_713E();
  set_de(0x848E);
  p00_L_1183();
  p00_rst08();
  set_hl(mem_read16(0x9196));
  p00_rst20();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  p04_L_718E();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p04_L_7087();
  goto lab_p04_L_6A10;
}

/* flash page 4 cpu 0x6AC3 (offset 0x2AC3) */
void p04_L_6AC3(void) {
  goto lab_p04_L_6AC3;
  lab_p04_L_6AC0: ;
  p04_L_70CF();
  lab_p04_L_6AC3: ;
  p04_L_7298();
  p04_L_756C();
  if (flag_nz()) goto lab_p04_L_6ADF;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_755F();
  if (flag_nz()) p04_L_61A6();
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 6)));
  set_hl(0x977F);
  p04_L_6FA7();
  lab_p04_L_6ADF: ;
  p04_L_75A9();
  p04_L_755A();
  if (flag_nz()) p00_L_235C();
  p04_L_715C();
  p00_L_018E();
  cpu_push_af();
  p00_L_334B();
  p00_L_17E0();
  p00_L_337B();
  p04_L_755A();
  if (flag_z()) goto lab_p04_L_6B04;
  p00_L_233D();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  lab_p04_L_6B04: ;
  p04_L_7151();
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6B1B;
  cpu_pop_af();
  if (flag_z()) goto lab_p04_L_6B4A;
  p04_L_7571();
  set_hl(mem_read16(0x918E));
  p00_rst20();
  p00_L_35D9();
  goto lab_p04_L_6B4A;
  lab_p04_L_6B1B: ;
  p00_L_230B();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1183();
  p00_rst08();
  p00_L_233D();
  set_hl(mem_read16(0x918E));
  p00_rst20();
  cpu_pop_af();
  if (flag_nz()) goto lab_p04_L_6B33;
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  lab_p04_L_6B33: ;
  p00_L_235C();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  p04_L_718E();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p00_L_1229();
  p04_L_755F();
  if (flag_nz()) p04_L_75B3();
  lab_p04_L_6B4A: ;
  p04_L_7087();
  p04_L_70C2();
  p04_L_7221();
  if (flag_nc()) goto lab_p04_L_6ADF;
  p04_L_712A();
  if (flag_nc()) goto lab_p04_L_6AC0;
  goto lab_p04_L_6AC3;
}

/* flash page 4 cpu 0x6B01 (offset 0x2B01) */
void p04_L_6B01(void) {
  goto lab_p04_L_6B01;
  lab_p04_L_6AC0: ;
  p04_L_70CF();
  p04_L_6AC3();
  return;
  lab_p04_L_6ADF: ;
  p04_L_75A9();
  p04_L_755A();
  if (flag_nz()) p00_L_235C();
  p04_L_715C();
  p00_L_018E();
  cpu_push_af();
  p00_L_334B();
  p00_L_17E0();
  p00_L_337B();
  p04_L_755A();
  if (flag_z()) goto lab_p04_L_6B04;
  p00_L_233D();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  lab_p04_L_6B01: ;
  /* rlc e */
  /* xor (hl) */
  lab_p04_L_6B04: ;
  p04_L_7151();
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6B1B;
  cpu_pop_af();
  if (flag_z()) goto lab_p04_L_6B4A;
  p04_L_7571();
  set_hl(mem_read16(0x918E));
  p00_rst20();
  p00_L_35D9();
  goto lab_p04_L_6B4A;
  lab_p04_L_6B1B: ;
  p00_L_230B();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1183();
  p00_rst08();
  p00_L_233D();
  set_hl(mem_read16(0x918E));
  p00_rst20();
  cpu_pop_af();
  if (flag_nz()) goto lab_p04_L_6B33;
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  lab_p04_L_6B33: ;
  p00_L_235C();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  p04_L_718E();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p00_L_1229();
  p04_L_755F();
  if (flag_nz()) p04_L_75B3();
  lab_p04_L_6B4A: ;
  p04_L_7087();
  p04_L_70C2();
  p04_L_7221();
  if (flag_nc()) goto lab_p04_L_6ADF;
  p04_L_712A();
  if (flag_nc()) goto lab_p04_L_6AC0;
  p04_L_6AC3();
  return;
}

/* flash page 4 cpu 0x6B68 (offset 0x2B68) */
void p04_L_6B68(void) {
  goto lab_p04_L_6B68;
  lab_p04_L_6B61: ;
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  lab_p04_L_6B68: ;
  p04_L_70A9();
  if (flag_nz()) goto lab_p04_L_6B90;
  p04_L_7221();
  if (flag_nc()) goto lab_p04_L_6B68;
  set_de(mem_read16(0x980C));
  set_hl(0x0012);
  set_hl((uint16_t)(hl() + de()));
  p00_L_35D3();
  mem_write16(0x9824, hl());
  p04_L_755F();
  if (flag_nz()) p04_L_61A6();
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 6)));
  set_hl(mem_read16(0x980E));
  set_hl((uint16_t)(hl() + 1));
  goto lab_p04_L_6B61;
  lab_p04_L_6B90: ;
  set_hl(0x977F);
  p04_L_6FA7();
  a = mem_read8(0x8D1A);
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p04_L_6BA2;
  p04_L_755A();
  if (flag_nz()) p04_L_7298();
  lab_p04_L_6BA2: ;
  p04_L_75A9();
  p04_L_755A();
  if (flag_nz()) p00_L_21E5();
  p04_L_715C();
  p00_L_018E();
  cpu_push_af();
  p00_L_334B();
  p00_L_17E0();
  p00_L_337B();
  p04_L_755A();
  if (flag_nz()) p00_L_21E5();
  p04_L_7151();
  a = mem_read8(0x8D1A);
  a = (uint8_t)(a - 1);
  a = (uint8_t)(a + a);
  set_de(0x848E);
  p04_L_7168();
  cpu_push_de();
  set_de(0x8499);
  p00_L_1183();
  p00_rst08();
  set_hl(mem_read16(0x918E));
  p00_rst20();
  cpu_pop_de();
  cpu_pop_af();
  if (flag_nz()) goto lab_p04_L_6BE4;
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  lab_p04_L_6BE4: ;
  p00_L_11FD();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_1183();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  p04_L_6BF0();
  return;
}

/* flash page 4 cpu 0x6BF0 (offset 0x2BF0) */
void p04_L_6BF0(void) {
  p04_L_718E();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p00_L_1229();
  p04_L_755F();
  if (flag_nz()) p04_L_75B3();
  p04_L_7087();
  p04_L_6B68();
  return;
}

/* flash page 4 cpu 0x6C32 (offset 0x2C32) */
void p04_L_6C32(void) {
  mem_write8(hl(), b);
  p04_L_7289();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_6C3A();
  return;
}

/* flash page 4 cpu 0x6C3A (offset 0x2C3A) */
void p04_L_6C3A(void) {
  goto lab_p04_L_6C3A;
  lab_p04_L_6C30: ;
  p04_L_70CF();
  lab_p04_L_6C33: ;
  p04_L_7289();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  lab_p04_L_6C3A: ;
  p04_L_755F();
  if (flag_nz()) p04_L_61A6();
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 6)));
  set_hl(0x9785);
  p04_L_6FA7();
  lab_p04_L_6C4A: ;
  p04_L_75A9();
  p04_L_70DF();
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6C63;
  p00_L_10E6();
  p00_L_35D9();
  p00_L_1135();
  p04_L_7571();
  goto lab_p04_L_6C86;
  lab_p04_L_6C63: ;
  p04_L_755A();
  if (flag_z()) goto lab_p04_L_6C72;
  p00_L_235C();
  p00_L_2333();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  lab_p04_L_6C72: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  p04_L_7180();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p00_L_1229();
  p04_L_755F();
  if (flag_nz()) p04_L_75B3();
  lab_p04_L_6C86: ;
  p04_L_7087();
  p04_L_70C2();
  p04_L_721C();
  if (flag_nc()) goto lab_p04_L_6C4A;
  p04_L_712A();
  if (flag_nc()) goto lab_p04_L_6C30;
  goto lab_p04_L_6C33;
}

/* flash page 4 cpu 0x6CA2 (offset 0x2CA2) */
void p04_L_6CA2(void) {
  goto lab_p04_L_6CA2;
  lab_p04_L_6C9B: ;
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  lab_p04_L_6CA2: ;
  p04_L_70A9();
  if (flag_nz()) goto lab_p04_L_6CD5;
  p04_L_721C();
  if (flag_c()) goto lab_p04_L_6CB7;
  p00_L_1229();
  p04_L_755F();
  if (flag_nz()) p04_L_75B3();
  goto lab_p04_L_6CA2;
  lab_p04_L_6CB7: ;
  set_de(mem_read16(0x980C));
  set_hl(0x0012);
  set_hl((uint16_t)(hl() + de()));
  p00_L_35D3();
  mem_write16(0x9824, hl());
  p04_L_755F();
  if (flag_nz()) p04_L_61A6();
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 6)));
  set_hl(mem_read16(0x980E));
  set_hl((uint16_t)(hl() + 1));
  goto lab_p04_L_6C9B;
  lab_p04_L_6CD5: ;
  set_hl(0x9785);
  p04_L_6FA7();
  a = mem_read8(0x8D1A);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p04_L_6CE8;
  p04_L_755A();
  if (flag_nz()) p04_L_7289();
  lab_p04_L_6CE8: ;
  p04_L_75A9();
  p04_L_70DF();
  p04_L_755A();
  if (flag_z()) goto lab_p04_L_6CF6;
  p00_L_222C();
  lab_p04_L_6CF6: ;
  a = mem_read8(0x8D1A);
  a = (uint8_t)(a - 1);
  a = (uint8_t)(a + a);
  set_de(0x848E);
  p04_L_7168();
  cpu_push_de();
  set_de(0x8499);
  p00_L_1183();
  cpu_pop_de();
  p00_L_11FD();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_1183();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  p04_L_718E();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  p04_L_7087();
  goto lab_p04_L_6CA2;
}

/* flash page 4 cpu 0x6D21 (offset 0x2D21) */
void p04_L_6D21(void) {
  l = h;
  p04_L_6D22();
  return;
}

/* flash page 4 cpu 0x6D22 (offset 0x2D22) */
void p04_L_6D22(void) {
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 5)));
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) & ~(1u << 6)));
  return;
}

/* flash page 4 cpu 0x6D3C (offset 0x2D3C) */
void p04_L_6D3C(void) {
  lab_p04_L_6D3C: ;
  p04_L_7087();
  a = 0x01;
  d = 0x00;
  lab_p04_L_6D43: ;
  b = a;
  p04_L_6D22();
  a = mem_read8(0x91CE);
  a = a & b;
  flag_logic(a);
  a = b;
  if (flag_z()) goto lab_p04_L_6DAB;
  d = (uint8_t)(d + 1);
  cpu_push_de();
  cpu_push_af();
  p00_L_38F1();
  p04_L_715C();
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6D61;
  p00_L_35D9();
  goto lab_p04_L_6D67;
  lab_p04_L_6D61: ;
  p04_L_755A();
  if (flag_nz()) p00_L_21E5();
  lab_p04_L_6D67: ;
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p04_L_6D6E;
  a = (uint8_t)(a - 1);
  lab_p04_L_6D6E: ;
  b = a;
  set_hl(0x89F8);
  p00_L_12B9();
  /* sla a */
  /* or (hl) */
  mem_write8(hl(), a);
  a = b;
  p00_L_39DB();
  set_hl(0x6DEC);
  p00_L_25A2();
  p00_L_337B();
  p04_L_6D22();
  p00_L_25C8();
  p04_L_7151();
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6D99;
  p04_L_7571();
  goto lab_p04_L_6D9F;
  lab_p04_L_6D99: ;
  p04_L_755A();
  if (flag_nz()) p00_L_21E5();
  lab_p04_L_6D9F: ;
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  p04_L_756C();
  if (flag_z()) p04_L_6F5D();
  cpu_pop_af();
  cpu_pop_de();
  lab_p04_L_6DAB: ;
  a = (uint8_t)(a + a);
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p04_L_6D43;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + 1);
  set_hl(0x8DA5);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p04_L_6DCA;
  mem_write8(0x8E67, a);
  set_hl(mem_read16(0x9196));
  p04_L_43CD();
  goto lab_p04_L_6D3C;
  lab_p04_L_6DCA: ;
  p04_L_756C();
  if (flag_nz()) goto lab_p04_L_6DE9;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p04_L_6DE9;
  a = 0x0B;
  p00_L_3633();
  p00_L_1100();
  p00_L_10DD();
  a = 0x0A;
  p00_L_3633();
  p00_rst08();
  p00_L_356D();
  lab_p04_L_6DE9: ;
  p04_L_6962();
  return;
}

/* flash page 4 cpu 0x6DF3 (offset 0x2DF3) */
void p04_L_6DF3(void) {
  mem_write16(0x8478, hl());
  set_hl(0x6E35);
  p00_L_25A2();
  set_hl(mem_read16(0x8478));
  cpu_push_hl();
  p00_L_11F8();
  p00_rst20();
  cpu_push_hl();
  p00_L_0C2D();
  cpu_pop_hl();
  p00_L_11F8();
  set_hl(mem_read16(0x8484));
  cpu_push_hl();
  a = mem_read8(0x8478);
  a = a & 0x80;
  flag_logic(a);
  b = a;
  a = mem_read8(0x8483);
  a = a & 0x80;
  flag_logic(a);
  a = a ^ b;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_6E35;
  p00_L_0ED0();
  p00_L_0FAF();
  set_hl(0x7121);
  p00_L_1073();
  if (flag_nc()) goto lab_p04_L_6E35;
  cpu_pop_de();
  cpu_pop_hl();
  p04_L_5E38();
  p00_L_25C8();
  return;
  lab_p04_L_6E35: ;
  p00_L_2509();
  return;
}

/* flash page 4 cpu 0x6E96 (offset 0x2E96) */
void p04_L_6E96(void) {
  lab_p04_L_6E96: ;
  p04_L_7087();
  a = 0x01;
  d = 0x00;
  lab_p04_L_6E9D: ;
  b = a;
  p04_L_56B3();
  if (flag_nz()) goto lab_p04_L_6EAA;
  a = mem_read8(0x91CE);
  a = a & b;
  flag_logic(a);
  a = b;
  if (flag_z()) goto lab_p04_L_6F07;
  lab_p04_L_6EAA: ;
  d = (uint8_t)(d + 1);
  cpu_push_de();
  cpu_push_af();
  p04_L_56A0();
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_nz()) goto lab_p04_L_6EBC;
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  lab_p04_L_6EBC: ;
  p04_L_715C();
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6EC9;
  p00_L_35D9();
  goto lab_p04_L_6ECF;
  lab_p04_L_6EC9: ;
  p04_L_755A();
  if (flag_nz()) p00_L_21E5();
  lab_p04_L_6ECF: ;
  cpu_pop_bc();
  cpu_push_bc();
  c = b;
  p04_L_572D();
  p00_L_1037();
  flag_cmp(a, 0x0E);
  if (flag_nz()) goto lab_p04_L_6EE1;
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 5)));
  lab_p04_L_6EE1: ;
  a = b;
  set_hl(0x978B);
  p04_L_6FAA();
  p04_L_7151();
  p04_L_756C();
  if (flag_z()) goto lab_p04_L_6EF5;
  p04_L_7571();
  goto lab_p04_L_6EFB;
  lab_p04_L_6EF5: ;
  p04_L_755A();
  if (flag_nz()) p00_L_21E5();
  lab_p04_L_6EFB: ;
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  p04_L_756C();
  if (flag_z()) p04_L_6F5D();
  cpu_pop_af();
  cpu_pop_de();
  lab_p04_L_6F07: ;
  b = a;
  p04_L_56B3();
  if (flag_nz()) goto lab_p04_L_6F13;
  a = b;
  a = (uint8_t)(a + a);
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p04_L_6E9D;
  lab_p04_L_6F13: ;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  p04_L_6F32();
  if (flag_c()) { p04_L_6962(); return; }
  set_hl(0x6F2C);
  p00_L_25A2();
  p00_L_3ABF();
  p00_L_25C8();
  goto lab_p04_L_6E96;
}

/* flash page 4 cpu 0x6F32 (offset 0x2F32) */
void p04_L_6F32(void) {
  p00_L_39F3();
  p00_L_0C1B();
  p00_L_10DD();
  p00_L_39F3();
  set_hl(0x9004);
  p00_L_0BEC();
  p00_L_1100();
  p00_rst08();
  set_hl(0x8FC5);
  p00_rst20();
  p00_L_107E();
  if (flag_c()) return;
  p00_L_1867();
  p00_L_1135();
  p00_L_39D5();
  p00_L_113F();
  return;
}

/* flash page 4 cpu 0x6F5D (offset 0x2F5D) */
void p04_L_6F5D(void) {
  cpu_push_af();
  p04_L_56B3();
  a = 0x02;
  if (flag_nz()) goto lab_p04_L_6F76;
  a = b;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p04_L_6F6B;
  a = (uint8_t)(a - 1);
  lab_p04_L_6F6B: ;
  set_hl(mem_read16(0x980C));
  p00_L_25EA();
  cpu_pop_de();
  if (flag_z()) return;
  cpu_push_de();
  a = d;
  a = (uint8_t)(a + a);
  lab_p04_L_6F76: ;
  cpu_pop_de();
  set_de(0x848E);
  p04_L_716A();
  cpu_push_de();
  set_de(0x8499);
  p00_L_1183();
  p00_rst08();
  set_hl(mem_read16(0x918E));
  p00_rst20();
  cpu_pop_de();
  p00_L_11FD();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_1183();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_6F9C;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  lab_p04_L_6F9C: ;
  p04_L_718E();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  return;
}

/* flash page 4 cpu 0x6FA4 (offset 0x2FA4) */
void p04_L_6FA4(void) {
  set_hl(0x9775);
  p04_L_6FA7();
  return;
}

/* flash page 4 cpu 0x6FA7 (offset 0x2FA7) */
void p04_L_6FA7(void) {
  a = mem_read8(0x8D1B);
  p04_L_6FAA();
  return;
}

/* flash page 4 cpu 0x6FAA (offset 0x2FAA) */
void p04_L_6FAA(void) {
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  mem_write8(0x9775, a);
  flag_cmp(a, 0x02);
  if (flag_c()) return;
  flag_cmp(a, 0x04);
  if (flag_nc()) return;
  set_hl(0x9668);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = mem_read8(hl());
  flag_cmp(a, 0x04);
  if (flag_c()) goto lab_p04_L_6FC3;
  mem_write8(hl(), 0x00);
  lab_p04_L_6FC3: ;
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x01);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x01);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x01);
  return;
}

/* flash page 4 cpu 0x6FCD (offset 0x2FCD) */
void p04_L_6FCD(void) {
  a = 0x05;
  p04_L_7564();
  if (flag_nz()) return;
  a = mem_read8(0x9775);
  flag_cmp(a, 0x02);
  if (flag_c()) return;
  flag_cmp(a, 0x04);
  if (flag_nc()) return;
  b = a;
  a = mem_read8(0x9669);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_6FE6;
  a = (uint8_t)(a - 1);
  goto lab_p04_L_6FE8;
  lab_p04_L_6FE6: ;
  a = 0x01;
  lab_p04_L_6FE8: ;
  mem_write8(0x9669, a);
  a = mem_read8(0x9668);
  flag_cmp(a, 0x02);
  if (flag_c()) return;
  if (flag_z()) goto lab_p04_L_7007;
  a = b;
  flag_cmp(a, 0x02);
  a = mem_read8(0x966B);
  if (flag_nz()) goto lab_p04_L_7002;
  p04_L_7018();
  lab_p04_L_6FFE: ;
  mem_write8(0x966B, a);
  return;
  lab_p04_L_7002: ;
  p04_L_701F();
  goto lab_p04_L_6FFE;
  lab_p04_L_7007: ;
  a = b;
  flag_cmp(a, 0x02);
  a = mem_read8(0x966A);
  if (flag_nz()) goto lab_p04_L_7013;
  lab_p04_L_700F: ;
  mem_write8(0x966A, a);
  return;
  lab_p04_L_7013: ;
  p04_L_7018();
  goto lab_p04_L_700F;
}

/* flash page 4 cpu 0x7018 (offset 0x3018) */
void p04_L_7018(void) {
  a = (uint8_t)(a + 1);
  flag_cmp(a, 0x04);
  if (flag_c()) return;
  a = 0x01;
  return;
}

/* flash page 4 cpu 0x701F (offset 0x301F) */
void p04_L_701F(void) {
  flag_cmp(a, 0x02);
  a = 0x01;
  if (flag_z()) return;
  a = 0x03;
  if (flag_c()) return;
  a = 0x02;
  return;
}

/* flash page 4 cpu 0x702A (offset 0x302A) */
void p04_L_702A(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x91CE, a);
  mem_write8(0x8483, a);
  a = (uint8_t)(a + 1);
  p04_L_703C();
  a = 0x02;
  p04_L_703C();
  a = 0x04;
  p04_L_703C();
  return;
}

/* flash page 4 cpu 0x703C (offset 0x303C) */
void p04_L_703C(void) {
  cpu_push_af();
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p04_L_7042;
  a = (uint8_t)(a - 1);
  lab_p04_L_7042: ;
  p04_L_707E();
  cpu_pop_bc();
  cpu_push_af();
  if (flag_z()) goto lab_p04_L_7054;
  cpu_ex_de_hl();
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p04_L_7054;
  set_hl(0x8483);
  a = mem_read8(hl());
  a = a | b;
  flag_logic(a);
  mem_write8(hl(), a);
  lab_p04_L_7054: ;
  set_hl(0x91CE);
  cpu_pop_af();
  a = mem_read8(hl());
  if (flag_z()) goto lab_p04_L_705D;
  a = a | b;
  flag_logic(a);
  mem_write8(hl(), a);
  lab_p04_L_705D: ;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p00_L_019D();
  if (flag_z()) goto lab_p04_L_707C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_707C;
  p00_L_172A();
  if (flag_nz()) goto lab_p04_L_7075;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p04_L_707C;
  lab_p04_L_7075: ;
  a = mem_read8(0x8483);
  mem_write8(hl(), a);
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  lab_p04_L_707C: ;
  cpu_pop_af();
  return;
}

/* flash page 4 cpu 0x707E (offset 0x307E) */
void p04_L_707E(void) {
  p00_L_39DB();
  p00_rst10();
  cpu_ex_de_hl();
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  /* or (hl) */
  return;
}

/* flash page 4 cpu 0x7087 (offset 0x3087) */
void p04_L_7087(void) {
  p00_L_0189();
  if (flag_z()) goto lab_p04_L_7096;
  p04_L_756C();
  if (flag_nz()) { p00_L_2511(); return; }
  lab_p04_L_7092: ;
  cpu_pop_hl();
  p04_L_6977();
  return;
  lab_p04_L_7096: ;
  p04_L_756C();
  if (flag_nz()) return;
  p00_L_038C();
  flag_cmp(a, 0x09);
  if (flag_nz()) return;
  p00_L_32F1();
  p00_L_0189();
  if (flag_nz()) goto lab_p04_L_7092;
  return;
}

/* flash page 4 cpu 0x70A9 (offset 0x30A9) */
void p04_L_70A9(void) {
  set_hl(0x0000);
  mem_write16(0x9810, hl());
  p04_L_720D();
  if (flag_nz()) return;
  a = mem_read8(0x8D1A);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p04_L_70CB;
  a = 0;
  flag_logic(a);
  mem_write8(0x8D1A, a);
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  p04_L_70C2();
  return;
  lab_p04_L_70CB: ;
  cpu_pop_hl();
  p04_L_6962();
  return;
}

/* flash page 4 cpu 0x70C2 (offset 0x30C2) */
void p04_L_70C2(void) {
  ix = cpu_pop16();
  cpu_pop_hl();
  cpu_push_hl();
  mem_write16(0x982A, hl());
  os_jp_ix();
  return;
}

/* flash page 4 cpu 0x70CF (offset 0x30CF) */
void p04_L_70CF(void) {
  goto lab_p04_L_70CF;
  lab_p04_L_70CB: ;
  cpu_pop_hl();
  p04_L_6962();
  return;
  lab_p04_L_70CF: ;
  p04_L_7211();
  if (flag_z()) goto lab_p04_L_70CB;
  p04_L_70D4();
  return;
}

/* flash page 4 cpu 0x70D4 (offset 0x30D4) */
void p04_L_70D4(void) {
  set_hl(0x0000);
  mem_write16(0x9810, hl());
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x980E, hl());
  return;
}

/* flash page 4 cpu 0x70DF (offset 0x30DF) */
void p04_L_70DF(void) {
  p04_L_7146();
  set_hl(mem_read16(0x9196));
  p00_L_11F8();
  p00_L_018E();
  if (flag_z()) goto lab_p04_L_7114;
  set_hl(0x7114);
  p00_L_25A2();
  p00_L_3ACB();
  p00_L_15FB();
  set_de(mem_read16(0x918E));
  p00_L_11FD();
  p00_L_14B0();
  p00_L_15FB();
  set_de(mem_read16(0x9192));
  p00_L_11FD();
  p00_L_14B0();
  p00_L_25C8();
  return;
  lab_p04_L_7114: ;
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  a = 0x20;
  mem_write8(0x8478, a);
  mem_write8(0x8483, a);
  return;
}

/* flash page 4 cpu 0x712A (offset 0x312A) */
void p04_L_712A(void) {
  set_hl(mem_read16(0x9810));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) return;
  set_de(mem_read16(0x980E));
  cpu_sbc_hl_de();
  if (flag_z()) return;
  set_de((uint16_t)(de() + 1));
  mem_write16(0x980E, de());
  /* scf */
  return;
}

/* flash page 4 cpu 0x713E (offset 0x313E) */
void p04_L_713E(void) {
  set_hl(mem_read16(0x980C));
  set_de(0x0024);
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 4 cpu 0x7146 (offset 0x3146) */
void p04_L_7146(void) {
  set_hl(mem_read16(0x9194));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  d = mem_read8(hl());
  goto lab_p04_L_7155;
  lab_p04_L_7155: ;
  p00_L_018E();
  if (flag_nz()) { p00_L_11FD(); return; }
  return;
}

/* flash page 4 cpu 0x7151 (offset 0x3151) */
void p04_L_7151(void) {
  set_de(mem_read16(0x9192));
  p00_L_018E();
  if (flag_nz()) { p00_L_11FD(); return; }
  return;
}

/* flash page 4 cpu 0x715C (offset 0x315C) */
void p04_L_715C(void) {
  goto lab_p04_L_715C;
  lab_p04_L_7155: ;
  p00_L_018E();
  if (flag_nz()) { p00_L_11FD(); return; }
  return;
  lab_p04_L_715C: ;
  set_de(mem_read16(0x918E));
  goto lab_p04_L_7155;
}

/* flash page 4 cpu 0x7162 (offset 0x3162) */
void p04_L_7162(void) {
  a = mem_read8(0x8D1A);
  set_de(0x8499);
  p04_L_7168();
  return;
}

/* flash page 4 cpu 0x7168 (offset 0x3168) */
void p04_L_7168(void) {
  a = (uint8_t)(a + 0x04);
  p04_L_716A();
  return;
}

/* flash page 4 cpu 0x716A (offset 0x316A) */
void p04_L_716A(void) {
  l = a;
  h = 0x00;
  p00_L_1025();
  set_bc(mem_read16(0x980C));
  set_hl((uint16_t)(hl() + bc()));
  cpu_push_hl();
  p00_L_1183();
  cpu_pop_de();
  return;
}

/* flash page 4 cpu 0x717B (offset 0x317B) */
void p04_L_717B(void) {
  p00_rst08();
  set_hl(mem_read16(0x9196));
  p00_rst20();
  p04_L_7180();
  return;
}

/* flash page 4 cpu 0x7180 (offset 0x3180) */
void p04_L_7180(void) {
  p00_L_230B();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1183();
  p00_L_235C();
  p00_L_2333();
  p04_L_718E();
  return;
}

/* flash page 4 cpu 0x718E (offset 0x318E) */
void p04_L_718E(void) {
  p00_L_018E();
  if (flag_z()) return;
  a = 0x04;
  p04_L_7564();
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p04_L_71E4;
  a = mem_read8(0x9775);
  flag_cmp(a, 0x04);
  if (flag_c()) goto lab_p04_L_71EB;
  flag_cmp(a, 0x06);
  if (flag_nc()) { p04_L_438A(); return; }
  p00_L_222C();
  p00_L_221D();
  p00_L_113F();
  p00_L_10EF();
  p04_L_71EF();
  if (flag_z()) p04_L_6600();
  p00_L_22CF();
  p00_L_231F();
  p04_L_71DD();
  p00_L_218C();
  p00_L_2191();
  p00_L_2148();
  a = mem_read8(0x9775);
  flag_cmp(a, 0x05);
  if (flag_z()) return;
  p00_L_222C();
  p00_L_356D();
  p00_L_2148();
  p04_L_71DD();
  return;
  lab_p04_L_71E4: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 0)) == 0);
  if (flag_nz()) { p04_L_438A(); return; }
  lab_p04_L_71EB: ;
  p00_L_356D();
  return;
}

/* flash page 4 cpu 0x71DD (offset 0x31DD) */
void p04_L_71DD(void) {
  p04_L_71EF();
  if (flag_z()) p04_L_6611();
  return;
}

/* flash page 4 cpu 0x71EF (offset 0x31EF) */
void p04_L_71EF(void) {
  p00_L_222C();
  set_de(0xFFF7);
  p04_L_431B();
  if (flag_nz()) goto lab_p04_L_7205;
  p04_L_4343();
  a = a & 0x0F;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_7205;
  p04_L_43B3();
  a = 0;
  flag_logic(a);
  lab_p04_L_7205: ;
  cpu_push_af();
  cpu_push_bc();
  p00_L_21A4();
  cpu_pop_bc();
  cpu_pop_af();
  return;
}

/* flash page 4 cpu 0x720D (offset 0x320D) */
void p04_L_720D(void) {
  set_hl(0x8D1A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p04_L_7211();
  return;
}

/* flash page 4 cpu 0x7211 (offset 0x3211) */
void p04_L_7211(void) {
  a = mem_read8(0x8D1B);
  p04_L_63D8();
  mem_write8(0x8D1B, a);
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 4 cpu 0x721C (offset 0x321C) */
void p04_L_721C(void) {
  set_bc(0x8F86);
  goto lab_p04_L_7224;
  lab_p04_L_7224: ;
  set_hl(mem_read16(0x8E67));
  set_de(0x0001);
  set_hl((uint16_t)(hl() + de()));
  if (flag_c()) return;
  mem_write16(0x8E67, hl());
  p04_L_722F();
  return;
}

/* flash page 4 cpu 0x7221 (offset 0x3221) */
void p04_L_7221(void) {
  set_bc(0x8FA1);
  set_hl(mem_read16(0x8E67));
  set_de(0x0001);
  set_hl((uint16_t)(hl() + de()));
  if (flag_c()) return;
  mem_write16(0x8E67, hl());
  p04_L_722F();
  return;
}

/* flash page 4 cpu 0x722F (offset 0x322F) */
void p04_L_722F(void) {
  set_hl(0x0009);
  set_hl((uint16_t)(hl() + bc()));
  cpu_push_hl();
  set_de(0x0009);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  cpu_push_af();
  cpu_ex_de_hl();
  set_hl(0x8499);
  p04_L_4418();
  p00_L_3E37();
  cpu_pop_af();
  cpu_pop_hl();
  p00_L_11F8();
  cpu_rla();
  if (flag_nc()) goto lab_p04_L_7278;
  p00_L_107E();
  if (flag_nz()) goto lab_p04_L_7268;
  p00_L_1135();
  p00_L_107E();
  lab_p04_L_7257: ;
  if (flag_nc()) goto lab_p04_L_7268;
  p00_L_14CC();
  if (flag_z()) p00_L_1287();
  p00_L_10E6();
  set_hl(0x8499);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  a = 0;
  flag_logic(a);
  lab_p04_L_7268: ;
  if (flag_c()) return;
  p00_L_1135();
  p00_L_15FB();
  set_de(mem_read16(0x9196));
  p00_L_11FD();
  a = a | a;
  flag_logic(a);
  return;
  lab_p04_L_7278: ;
  p00_L_107E();
  if (flag_z()) goto lab_p04_L_7280;
  /* ccf */
  goto lab_p04_L_7268;
  lab_p04_L_7280: ;
  p00_L_1135();
  p00_L_107E();
  /* ccf */
  goto lab_p04_L_7257;
}

/* flash page 4 cpu 0x7289 (offset 0x3289) */
void p04_L_7289(void) {
  set_hl(0x0000);
  mem_write16(0x8E67, hl());
  set_hl(0x8F86);
  p00_rst20();
  p00_L_3333();
  goto lab_p04_L_72BD;
  lab_p04_L_72BD: ;
  set_hl(mem_read16(0x84DD));
  mem_write16(0x9196, hl());
  return;
}

/* flash page 4 cpu 0x7298 (offset 0x3298) */
void p04_L_7298(void) {
  set_hl(0x8FA1);
  p00_rst20();
  set_hl(0x0000);
  mem_write16(0x8E67, hl());
  p00_L_3399();
  goto lab_p04_L_72BD;
  lab_p04_L_72BD: ;
  set_hl(mem_read16(0x84DD));
  mem_write16(0x9196, hl());
  return;
}

/* flash page 4 cpu 0x72A7 (offset 0x32A7) */
void p04_L_72A7(void) {
  p04_L_713E();
  cpu_push_hl();
  set_hl(0x8F50);
  p00_rst20();
  cpu_pop_de();
  p04_L_756C();
  if (flag_z()) p00_L_11FD();
  p04_L_72B6();
  return;
}

/* flash page 4 cpu 0x72B6 (offset 0x32B6) */
void p04_L_72B6(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x8E67, a);
  p00_L_3321();
  set_hl(mem_read16(0x84DD));
  mem_write16(0x9196, hl());
  return;
}

/* flash page 4 cpu 0x72C4 (offset 0x32C4) */
void p04_L_72C4(void) {
  p00_L_128A();
  p00_L_3321();
  set_hl(mem_read16(0x981C));
  mem_write16(0x918C, hl());
  mem_write8(hl(), 0x00);
  set_hl(mem_read16(0x84DD));
  mem_write16(0x918E, hl());
  p04_L_72D8();
  return;
}

/* flash page 4 cpu 0x72D8 (offset 0x32D8) */
void p04_L_72D8(void) {
  p00_L_128A();
  p00_L_3327();
  set_hl(mem_read16(0x981C));
  mem_write16(0x9190, hl());
  mem_write8(hl(), 0x00);
  set_hl(mem_read16(0x84DD));
  mem_write16(0x9192, hl());
  return;
}

/* flash page 4 cpu 0x72ED (offset 0x32ED) */
void p04_L_72ED(void) {
  p00_L_332D();
  set_hl(mem_read16(0x981C));
  mem_write16(0x9194, hl());
  mem_write8(hl(), 0x00);
  return;
}

/* flash page 4 cpu 0x72F9 (offset 0x32F9) */
void p04_L_72F9(void) {
  set_de(0x0009);
  lab_p04_L_72FC: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  set_hl((uint16_t)(hl() + de()));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_72FC;
  return;
}

/* flash page 4 cpu 0x7302 (offset 0x3302) */
void p04_L_7302(void) {
  a = mem_read8(0x8A2C);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x3C)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p04_L_7310;
  mem_write8((uint16_t)(iy + 0x3C), (uint8_t)(mem_read8((uint16_t)(iy + 0x3C)) | (1u << 2)));
  lab_p04_L_7310: ;
  set_de(0x9152);
  set_hl(0x8F62);
  p04_L_753F();
  mem_write8(0x84A4, a);
  set_de(0x915B);
  set_hl(0x8F7D);
  p04_L_753F();
  mem_write8(0x84A5, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p04_L_73DD;
  p00_L_1276();
  set_de(0x8499);
  l = e;
  h = d;
  p04_L_434D();
  l = a;
  cpu_push_hl();
  a = 0xFF;
  p04_L_755A();
  if (flag_z()) goto lab_p04_L_7362;
  a = mem_read8(0x8E69);
  p04_L_75A2();
  if (flag_nc()) goto lab_p04_L_7362;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p04_L_7359;
  a = (uint8_t)(a - 0x08);
  if (flag_nc()) goto lab_p04_L_7377;
  l = (uint8_t)(l | (1u << 3));
  goto lab_p04_L_7362;
  lab_p04_L_7359: ;
  a = (uint8_t)(a + 0x08);
  p04_L_75A2();
  if (flag_c()) goto lab_p04_L_7377;
  l = (uint8_t)(l | (1u << 2));
  lab_p04_L_7362: ;
  mem_write8(0x8E69, a);
  a = 0;
  flag_logic(a);
  flag_set_z((l & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p04_L_7395;
  a = mem_read8(0x8DA6);
  flag_set_z((l & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_7395;
  set_de(0x8499);
  p04_L_442B();
  lab_p04_L_7377: ;
  mem_write8(0x8D1B, a);
  mem_write8(0x8E69, a);
  p04_L_7473();
  if (flag_c()) p04_L_4017();
  b = a;
  a = mem_read8(0x8DA6);
  flag_cmp(a, b);
  a = b;
  if (flag_nz()) goto lab_p04_L_7394;
  a = (uint8_t)(a - 1);
  mem_write8(0x8D1B, a);
  p04_L_74A0();
  goto lab_p04_L_7398;
  lab_p04_L_7394: ;
  a = (uint8_t)(a + 1);
  lab_p04_L_7395: ;
  mem_write8(0x8D1B, a);
  lab_p04_L_7398: ;
  cpu_pop_hl();
  a = 0x01;
  flag_set_z((l & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p04_L_73D1;
  a = mem_read8(0x8DA3);
  a = (uint8_t)(a - 1);
  flag_set_z((l & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_73D1;
  p00_L_1276();
  set_de(0x8499);
  p04_L_441F();
  mem_write8(0x8D1A, a);
  d = a;
  a = mem_read8(0x8DA3);
  a = (uint8_t)(a - 1);
  flag_cmp(a, d);
  a = d;
  if (flag_nz()) goto lab_p04_L_73BF;
  a = (uint8_t)(a - 1);
  goto lab_p04_L_73C0;
  lab_p04_L_73BF: ;
  a = (uint8_t)(a + 1);
  lab_p04_L_73C0: ;
  set_de(mem_read16(0x8D1A));
  cpu_push_af();
  a = mem_read8(0x8DA6);
  c = a;
  b = 0x00;
  cpu_pop_af();
  d = c;
  c = e;
  p04_L_4025();
  lab_p04_L_73D1: ;
  mem_write8(0x8D1A, a);
  a = mem_read8(0x8D1B);
  p04_L_7478();
  if (flag_c()) p04_L_74A0();
  lab_p04_L_73DD: ;
  a = mem_read8(0x84A4);
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  if (flag_nz()) goto lab_p04_L_7400;
  b = a;
  a = mem_read8(0x8DA6);
  c = a;
  p04_L_755A();
  if (flag_z()) goto lab_p04_L_73FA;
  a = (uint8_t)(a - 0x09);
  b = a;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_73FA;
  set_bc(0x0009);
  lab_p04_L_73FA: ;
  cpu_pop_af();
  a = c;
  cpu_push_af();
  a = b;
  goto lab_p04_L_7437;
  lab_p04_L_7400: ;
  set_bc(0x8F50);
  set_de(0x8F59);
  set_hl(0x8F62);
  p04_L_755A();
  if (flag_z()) goto lab_p04_L_741C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p04_L_7419;
  set_bc(0x84AF);
  goto lab_p04_L_741C;
  lab_p04_L_7419: ;
  set_de(0x84AF);
  lab_p04_L_741C: ;
  mem_write16(0x84A7, de());
  p04_L_74D7();
  if (flag_c()) goto lab_p04_L_7467;
  lab_p04_L_7425: ;
  set_de(mem_read16(0x84A7));
  set_hl(0x8F62);
  p04_L_7514();
  if (flag_c()) goto lab_p04_L_746A;
  set_de(0x8478);
  p04_L_442B();
  lab_p04_L_7437: ;
  p00_L_0189();
  if (flag_nz()) goto lab_p04_L_746A;
  mem_write8(0x8D1B, a);
  set_bc(mem_read16(0x8D1A));
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 5)) == 0);
  if (flag_z()) p04_L_4155();
  set_hl(mem_read16(0x8E67));
  cpu_push_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 2)) == 0);
  if (flag_nz()) p04_L_74A0();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x8E67, hl());
  cpu_pop_af();
  cpu_push_af();
  if (flag_nz()) goto lab_p04_L_7425;
  set_bc(mem_read16(0x8D1A));
  b = (uint8_t)(b + 1);
  flag_cmp(a, b);
  a = b;
  if (flag_nc()) goto lab_p04_L_7437;
  lab_p04_L_7467: ;
  cpu_pop_af();
  goto lab_p04_L_746E;
  lab_p04_L_746A: ;
  cpu_pop_af();
  if (flag_nz()) p00_L_21A7();
  lab_p04_L_746E: ;
  cpu_pop_af();
  mem_write8(0x8A2C, a);
  return;
}

/* flash page 4 cpu 0x7473 (offset 0x3473) */
void p04_L_7473(void) {
  p04_L_755A();
  if (flag_nz()) goto lab_p04_L_748A;
  p04_L_7478();
  return;
  lab_p04_L_748A: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_7493;
  flag_cmp(a, 0x0A);
  return;
  lab_p04_L_7493: ;
  cpu_push_hl();
  cpu_push_af();
  a = mem_read8(0x8DA4);
  a = (uint8_t)(a - 0x0B);
  l = a;
  cpu_pop_af();
  flag_cmp(a, l);
  cpu_pop_hl();
  /* ccf */
  return;
}

/* flash page 4 cpu 0x7478 (offset 0x3478) */
void p04_L_7478(void) {
  p04_L_755A();
  if (flag_nz()) goto lab_p04_L_747F;
  lab_p04_L_747D: ;
  /* scf */
  return;
  lab_p04_L_747F: ;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_747D;
  cpu_push_hl();
  set_hl(0x8DA6);
  cpu_cp_hl();
  cpu_pop_hl();
  if (flag_z()) goto lab_p04_L_747D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p04_L_7493;
  flag_cmp(a, 0x0A);
  return;
  lab_p04_L_7493: ;
  cpu_push_hl();
  cpu_push_af();
  a = mem_read8(0x8DA4);
  a = (uint8_t)(a - 0x0B);
  l = a;
  cpu_pop_af();
  flag_cmp(a, l);
  cpu_pop_hl();
  /* ccf */
  return;
}

/* flash page 4 cpu 0x74A0 (offset 0x34A0) */
void p04_L_74A0(void) {
  a = mem_read8(0x84A5);
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p04_L_4017(); return; }
  set_bc(0x8F6B);
  set_de(0x8F74);
  set_hl(0x8F7D);
  p04_L_74D7();
  if (flag_c()) return;
  lab_p04_L_74B4: ;
  set_de(0x8F74);
  set_hl(0x8F7D);
  p04_L_7514();
  if (flag_c()) { p00_L_21A7(); return; }
  set_hl(mem_read16(0x8E67));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x8E67, hl());
  set_de(0x8478);
  p04_L_441F();
  set_bc(mem_read16(0x8D1A));
  c = a;
  p04_L_4155();
  goto lab_p04_L_74B4;
}

/* flash page 4 cpu 0x74D7 (offset 0x34D7) */
void p04_L_74D7(void) {
  cpu_push_de();
  cpu_push_bc();
  p00_L_11F8();
  cpu_pop_hl();
  p00_rst20();
  p00_L_14CC();
  if (flag_z()) goto lab_p04_L_7511;
  p00_L_15D1();
  p00_L_10E6();
  p00_L_0ED0();
  p00_L_3E37();
  p04_L_7536();
  p00_L_10EF();
  p00_L_0D1F();
  p00_L_10DD();
  p00_L_3E37();
  p00_rst08();
  cpu_pop_hl();
  p00_rst20();
  p00_L_107E();
  if (flag_c()) return;
  p00_L_1135();
  p00_rst18();
  set_hl(0x0000);
  mem_write16(0x8E67, hl());
  a = 0;
  flag_logic(a);
  return;
  lab_p04_L_7511: ;
  cpu_pop_af();
  /* scf */
  return;
}

/* flash page 4 cpu 0x7514 (offset 0x3514) */
void p04_L_7514(void) {
  cpu_push_de();
  p00_rst20();
  p00_L_15D6();
  set_hl(mem_read16(0x8E67));
  p00_L_3B55();
  p00_L_0D1F();
  p00_L_22F7();
  p00_rst30();
  p00_L_3E37();
  p00_L_10DD();
  p00_rst08();
  cpu_pop_hl();
  p00_rst20();
  p00_L_107E();
  if (flag_c()) return;
  p00_L_1135();
  return;
}

/* flash page 4 cpu 0x7521 (offset 0x3521) */
void p04_L_7521(void) {
  c = (uint8_t)(c - 1);
  p00_L_22F7();
  p00_rst30();
  p00_L_3E37();
  p00_L_10DD();
  p00_rst08();
  cpu_pop_hl();
  p00_rst20();
  p00_L_107E();
  if (flag_c()) return;
  p00_L_1135();
  return;
}

/* flash page 4 cpu 0x7536 (offset 0x3536) */
void p04_L_7536(void) {
  p00_L_0E4C();
  p00_L_0BF9();
  p00_L_0E4C();
  return;
}

/* flash page 4 cpu 0x753A (offset 0x353A) */
void p04_L_753A(void) {
  sp = hl();
  set_bc((uint16_t)(bc() - 1));
  p00_L_0E4C();
  return;
}

/* flash page 4 cpu 0x753F (offset 0x353F) */
void p04_L_753F(void) {
  cpu_push_de();
  p00_rst20();
  p00_L_15D6();
  p00_L_14C7();
  cpu_pop_hl();
  if (flag_z()) goto lab_p04_L_7557;
  p00_L_11F8();
  p00_L_15D1();
  p00_L_107E();
  if (flag_nc()) goto lab_p04_L_7557;
  a = 0;
  flag_logic(a);
  return;
  lab_p04_L_7557: ;
  a = 0x01;
  return;
}

/* flash page 4 cpu 0x755A (offset 0x355A) */
void p04_L_755A(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 5)) == 0);
  return;
}

/* flash page 4 cpu 0x755F (offset 0x355F) */
void p04_L_755F(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 6)) == 0);
  return;
}

/* flash page 4 cpu 0x7564 (offset 0x3564) */
void p04_L_7564(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 6)) == 0);
  if (flag_nz()) p00_L_32F7();
  return;
}

/* flash page 4 cpu 0x756C (offset 0x356C) */
void p04_L_756C(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x11)) & (1u << 2)) == 0);
  return;
}

/* flash page 4 cpu 0x7571 (offset 0x3571) */
void p04_L_7571(void) {
  p00_L_018E();
  if (flag_z()) return;
  set_hl(mem_read16(0x9824));
  set_de(0xFFE5);
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(hl());
  a = (uint8_t)(a + 1);
  if (flag_nz()) goto lab_p04_L_7586;
  p00_L_2389();
  p00_L_2375();
  return;
  lab_p04_L_7586: ;
  p00_L_1171();
  p00_L_22C7();
  p00_L_107E();
  if (flag_c()) { p00_L_237F(); return; }
  p00_L_1108();
  p00_L_2324();
  p00_L_107E();
  if (flag_nc()) return;
  p00_L_113A();
  p00_L_2375();
  return;
}

/* flash page 4 cpu 0x75A2 (offset 0x35A2) */
void p04_L_75A2(void) {
  cpu_push_hl();
  set_hl(0x8DA5);
  cpu_cp_hl();
  cpu_pop_hl();
  return;
}

/* flash page 4 cpu 0x75A9 (offset 0x35A9) */
void p04_L_75A9(void) {
  set_hl(0xFFFF);
  mem_write16(0x9C24, hl());
  p00_L_336F();
  return;
}

/* flash page 4 cpu 0x75B3 (offset 0x35B3) */
void p04_L_75B3(void) {
  set_hl(mem_read16(0x9C24));
  set_de(0xFFF1);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) return;
  if (flag_z()) return;
  b = l;
  lab_p04_L_75BF: ;
  p00_L_0284();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_75BF;
  return;
}

/* flash page 4 cpu 0x75C5 (offset 0x35C5) */
void p04_L_75C5(void) {
  p00_L_18B7();
  if (flag_nz()) { p04_L_75EA(); return; }
  a = 0;
  flag_logic(a);
  p04_L_75CB();
  return;
}

/* flash page 4 cpu 0x75CB (offset 0x35CB) */
void p04_L_75CB(void) {
  mem_write8(0x86D7, a);
  a = mem_read8(0x97A6);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a - 0x07);
  p00_L_17CE();
  if (flag_z()) goto lab_p04_L_75DD;
  a = (uint8_t)(a - 0x21);
  lab_p04_L_75DD: ;
  mem_write8(0x86D8, a);
  return;
}

/* flash page 4 cpu 0x75E1 (offset 0x35E1) */
void p04_L_75E1(void) {
  goto lab_p04_L_75E1;
  lab_p04_L_75CA: ;
  a = 0;
  flag_logic(a);
  p04_L_75CB();
  return;
  lab_p04_L_75E1: ;
  p00_L_18B7();
  if (flag_nz()) goto lab_p04_L_75CA;
  a = 0x30;
  p04_L_75CB();
  return;
}

/* flash page 4 cpu 0x75EA (offset 0x35EA) */
void p04_L_75EA(void) {
  a = 0;
  flag_logic(a);
  p04_L_75EB();
  return;
}

/* flash page 4 cpu 0x75EB (offset 0x35EB) */
void p04_L_75EB(void) {
  goto lab_p04_L_75EB;
  lab_p04_L_75D6: ;
  p00_L_17CE();
  if (flag_z()) goto lab_p04_L_75DD;
  a = (uint8_t)(a - 0x21);
  lab_p04_L_75DD: ;
  mem_write8(0x86D8, a);
  return;
  lab_p04_L_75EB: ;
  mem_write8(0x86D7, a);
  a = mem_read8(0x97A6);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a - 0x0D);
  goto lab_p04_L_75D6;
}

/* flash page 4 cpu 0x75F8 (offset 0x35F8) */
void p04_L_75F8(void) {
  p04_L_75EA();
  p00_L_18B7();
  p04_L_75FE();
  return;
}

/* flash page 4 cpu 0x75FE (offset 0x35FE) */
void p04_L_75FE(void) {
  goto lab_p04_L_75FE;
  lab_p04_L_75DD: ;
  mem_write8(0x86D8, a);
  return;
  lab_p04_L_75FE: ;
  if (flag_z()) return;
  a = (uint8_t)(a - 0x06);
  goto lab_p04_L_75DD;
}

/* flash page 4 cpu 0x7603 (offset 0x3603) */
void p04_L_7603(void) {
  goto lab_p04_L_7603;
  lab_p04_L_75DD: ;
  mem_write8(0x86D8, a);
  return;
  lab_p04_L_7603: ;
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_760F;
  p04_L_75F8();
  a = (uint8_t)(a - 0x06);
  goto lab_p04_L_75DD;
  lab_p04_L_760F: ;
  a = 0x30;
  p04_L_75EB();
  return;
}

/* flash page 4 cpu 0x7613 (offset 0x3613) */
void p04_L_7613(void) {
  p04_L_75C5();
  h = 0x52;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 6)) == 0);
  goto lab_p04_L_768B;
  lab_p04_L_768B: ;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7992();
  a = h;
  p00_L_16AC();
  p00_L_3D47();
  a = 0x3D;
  p00_L_3D47();
  cpu_pop_af();
  if (flag_nz()) goto lab_p04_L_76A7;
  p04_L_76A2();
  return;
  lab_p04_L_76A7: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x761E (offset 0x361E) */
void p04_L_761E(void) {
  p04_L_75F8();
  h = 0x5B;
  a = 0;
  flag_logic(a);
  goto lab_p04_L_768B;
  lab_p04_L_768B: ;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7992();
  a = h;
  p00_L_16AC();
  p00_L_3D47();
  a = 0x3D;
  p00_L_3D47();
  cpu_pop_af();
  if (flag_nz()) goto lab_p04_L_76A7;
  p04_L_76A2();
  return;
  lab_p04_L_76A7: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x762E (offset 0x362E) */
void p04_L_762E(void) {
  p04_L_75F8();
  h = 0x54;
  a = 0;
  flag_logic(a);
  goto lab_p04_L_768B;
  lab_p04_L_768B: ;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7992();
  a = h;
  p00_L_16AC();
  p00_L_3D47();
  a = 0x3D;
  p00_L_3D47();
  cpu_pop_af();
  if (flag_nz()) goto lab_p04_L_76A7;
  p04_L_76A2();
  return;
  lab_p04_L_76A7: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x7636 (offset 0x3636) */
void p04_L_7636(void) {
  p00_L_18B7();
  if (flag_nz()) { p04_L_7640(); return; }
  p04_L_75F8();
  goto lab_p04_L_7643;
  lab_p04_L_7643: ;
  h = 0x58;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 6)) == 0);
  goto lab_p04_L_768B;
  lab_p04_L_768B: ;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7992();
  a = h;
  p00_L_16AC();
  p00_L_3D47();
  a = 0x3D;
  p00_L_3D47();
  cpu_pop_af();
  if (flag_nz()) goto lab_p04_L_76A7;
  p04_L_76A2();
  return;
  lab_p04_L_76A7: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x7640 (offset 0x3640) */
void p04_L_7640(void) {
  p04_L_75C5();
  h = 0x58;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 6)) == 0);
  goto lab_p04_L_768B;
  lab_p04_L_768B: ;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7992();
  a = h;
  p00_L_16AC();
  p00_L_3D47();
  a = 0x3D;
  p00_L_3D47();
  cpu_pop_af();
  if (flag_nz()) goto lab_p04_L_76A7;
  p04_L_76A2();
  return;
  lab_p04_L_76A7: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x764E (offset 0x364E) */
void p04_L_764E(void) {
  p04_L_7640();
  p04_L_7651();
  return;
}

/* flash page 4 cpu 0x7651 (offset 0x3651) */
void p04_L_7651(void) {
  p04_L_75E1();
  h = 0x59;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 7)) == 0);
  goto lab_p04_L_768B;
  lab_p04_L_768B: ;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7992();
  a = h;
  p00_L_16AC();
  p00_L_3D47();
  a = 0x3D;
  p00_L_3D47();
  cpu_pop_af();
  if (flag_nz()) goto lab_p04_L_76A7;
  p04_L_76A2();
  return;
  lab_p04_L_76A7: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x7661 (offset 0x3661) */
void p04_L_7661(void) {
  p04_L_75F8();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7992();
  a = 0x01;
  p00_L_3D47();
  a = 0x3D;
  p00_L_3D47();
  p00_L_1697();
  p04_L_76A2();
  return;
}

/* flash page 4 cpu 0x767A (offset 0x367A) */
void p04_L_767A(void) {
  p04_L_7640();
  p04_L_7651();
  p04_L_761E();
  return;
}

/* flash page 4 cpu 0x7685 (offset 0x3685) */
void p04_L_7685(void) {
  goto lab_p04_L_7685;
  lab_p04_L_7626: ;
  p04_L_75E1();
  h = 0x5B;
  a = 0;
  flag_logic(a);
  goto lab_p04_L_768B;
  lab_p04_L_7685: ;
  p04_L_7613();
  goto lab_p04_L_7626;
  lab_p04_L_768B: ;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7992();
  a = h;
  p00_L_16AC();
  p00_L_3D47();
  a = 0x3D;
  p00_L_3D47();
  cpu_pop_af();
  if (flag_nz()) goto lab_p04_L_76A7;
  p04_L_76A2();
  return;
  lab_p04_L_76A7: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x76A2 (offset 0x36A2) */
void p04_L_76A2(void) {
  p00_rst10();
  cpu_ex_de_hl();
  p04_L_76A4();
  return;
}

/* flash page 4 cpu 0x76A4 (offset 0x36A4) */
void p04_L_76A4(void) {
  p04_L_797A();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x76AC (offset 0x36AC) */
void p04_L_76AC(void) {
  p04_L_75C5();
  p00_L_38F1();
  set_hl(mem_read16(0x8E65));
  a = h;
  a = a | h;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_76CA;
  lab_p04_L_76B9: ;
  p00_L_35A3();
  a = 0x05;
  if (flag_z()) goto lab_p04_L_76D3;
  p00_L_359D();
  a = 0x01;
  if (flag_z()) goto lab_p04_L_76D3;
  p04_L_7640();
  return;
  lab_p04_L_76CA: ;
  a = l;
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p04_L_76B9;
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p04_L_76B9;
  lab_p04_L_76D3: ;
  a = (uint8_t)(a - 1);
  a = (uint8_t)(a + a);
  e = a;
  d = 0x00;
  set_hl(0x7A16);
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  a = 0x5D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p04_L_76E8();
  return;
}

/* flash page 4 cpu 0x76E8 (offset 0x36E8) */
void p04_L_76E8(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7A03();
  a = 0x3D;
  p04_L_76F1();
  return;
}

/* flash page 4 cpu 0x76F1 (offset 0x36F1) */
void p04_L_76F1(void) {
  p00_L_3D47();
  a = mem_read8(0x86D7);
  flag_cmp(a, 0x16);
  a = 0x05;
  if (flag_z()) goto lab_p04_L_76FF;
  a = 0x06;
  lab_p04_L_76FF: ;
  p00_L_18B7();
  if (flag_nz()) goto lab_p04_L_7706;
  a = 0x09;
  lab_p04_L_7706: ;
  p04_L_797D();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x7713 (offset 0x3713) */
void p04_L_7713(void) {
  p04_L_7737();
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_7720;
  p04_L_75E1();
  goto lab_p04_L_772E;
  lab_p04_L_7720: ;
  a = 0x30;
  p04_L_75CB();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 7)));
  a = 0x20;
  p00_L_3D47();
  lab_p04_L_772E: ;
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 7)));
  set_hl(0x8B5A);
  a = 0x70;
  p04_L_7737();
  return;
}

/* flash page 4 cpu 0x7721 (offset 0x3721) */
void p04_L_7721(void) {
  goto lab_p04_L_7721;
  lab_p04_L_76F0: ;
  a = (uint8_t)(a - 1);
  p04_L_76F1();
  return;
  lab_p04_L_7721: ;
  if (flag_nc()) goto lab_p04_L_76F0;
  flag_set_z((l & (1u << 6)) == 0);
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 7)));
  a = 0x20;
  p00_L_3D47();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 7)));
  set_hl(0x8B5A);
  a = 0x70;
  p04_L_7737();
  return;
}

/* flash page 4 cpu 0x7730 (offset 0x3730) */
void p04_L_7730(void) {
  d = (uint8_t)(d + 1);
  cpu_cp_hl();
  set_hl(0x8B5A);
  a = 0x70;
  p04_L_7737();
  return;
}

/* flash page 4 cpu 0x7737 (offset 0x3737) */
void p04_L_7737(void) {
  cpu_push_af();
  p00_rst20();
  d = 0x04;
  p00_L_0FB1();
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p00_L_3D47();
  a = 0x3D;
  p00_L_3D47();
  set_hl(0x8478);
  p04_L_76A4();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 7)));
  return;
}

/* flash page 4 cpu 0x775A (offset 0x375A) */
void p04_L_775A(void) {
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  set_de(0x7800);
  p04_L_7767();
  set_de(0x7901);
  p04_L_7767();
  return;
}

/* flash page 4 cpu 0x7767 (offset 0x3767) */
void p04_L_7767(void) {
  b = 0x01;
  a = mem_read8(0x8DA4);
  a = (uint8_t)(a - 0x06);
  cpu_push_de();
  cpu_push_bc();
  /* rrc e */
  if (flag_nz()) goto lab_p04_L_7796;
  p04_L_75EB();
  a = mem_read8(0x86D8);
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_7781;
  a = (uint8_t)(a - 0x0D);
  lab_p04_L_7781: ;
  a = (uint8_t)(a - 1);
  mem_write8(0x86D8, a);
  lab_p04_L_7785: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7992();
  cpu_pop_bc();
  lab_p04_L_778D: ;
  cpu_pop_af();
  p00_L_3D47();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_778D;
  p04_L_7875();
  return;
  lab_p04_L_7796: ;
  set_hl(0x0500);
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_77A1;
  set_hl(0x0600);
  lab_p04_L_77A1: ;
  mem_write16(0x86D7, hl());
  goto lab_p04_L_7785;
}

/* flash page 4 cpu 0x77A6 (offset 0x37A6) */
void p04_L_77A6(void) {
  mem_write16(0x86D7, hl());
  d = 0x5E;
  a = mem_read8(0x847A);
  e = a;
  p00_L_3DAD();
  b = a;
  set_hl((uint16_t)(hl() + 1));
  mem_write8((uint16_t)(iy + 0x24), (uint8_t)(mem_read8((uint16_t)(iy + 0x24)) & ~(1u << 4)));
  p00_L_3D59();
  set_hl(mem_read16(0x8D18));
  cpu_push_hl();
  p00_rst10();
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  a = 0x3D;
  p00_L_3D47();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 4)));
  p00_L_34E9();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 4)));
  cpu_pop_hl();
  mem_write16(0x8D18, hl());
  return;
}

/* flash page 4 cpu 0x77CB (offset 0x37CB) */
void p04_L_77CB(void) {
  set_de(0xCDE6);
  os_jp_hl();
  return;
}

/* flash page 4 cpu 0x77D9 (offset 0x37D9) */
void p04_L_77D9(void) {
  goto lab_p04_L_77D9;
  lab_p04_L_77C4: ;
  a = 0x3D;
  p00_L_3D47();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 4)));
  p00_L_34E9();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 4)));
  cpu_pop_hl();
  mem_write16(0x8D18, hl());
  return;
  lab_p04_L_77D9: ;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  a = 0x01;
  p04_L_75CB();
  a = 0x79;
  p00_L_3D47();
  set_hl(mem_read16(0x8D18));
  cpu_push_hl();
  p00_rst10();
  cpu_ex_de_hl();
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_bc((uint16_t)(bc() - 1));
  set_bc((uint16_t)(bc() - 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  goto lab_p04_L_77C4;
}

/* flash page 4 cpu 0x77FE (offset 0x37FE) */
void p04_L_77FE(void) {
  b = a;
  a = 0x00;
  flag_set_z((mem_read8((uint16_t)(iy + 0x36)) & (1u << 0)) == 0);
  if (flag_nz()) p00_L_3369();
  if (flag_nz()) return;
  a = b;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_784F;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  a = mem_read8(0x8E63);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_7867;
  cpu_pop_af();
  p00_L_385B();
  p00_L_01A2();
  if (flag_z()) goto lab_p04_L_782C;
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 3)));
  lab_p04_L_782C: ;
  set_hl(0x0000);
  p04_L_77A6();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 3)));
  p00_L_01A2();
  if (flag_z()) { p04_L_7875(); return; }
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x0030);
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_784A;
  set_hl(0x0018);
  lab_p04_L_784A: ;
  p04_L_77A6();
  p04_L_7875();
  return;
  lab_p04_L_784F: ;
  cpu_pop_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x04)) & (1u << 4)) == 0);
  if (flag_nz()) return;
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  set_hl(0x005A);
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_7864;
  l = 0x2A;
  lab_p04_L_7864: ;
  mem_write16(0x86D7, hl());
  lab_p04_L_7867: ;
  p04_L_7992();
  cpu_pop_af();
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p04_L_7870;
  a = 0;
  flag_logic(a);
  lab_p04_L_7870: ;
  a = (uint8_t)(a + 0x30);
  p00_L_3D47();
  p04_L_7875();
  return;
}

/* flash page 4 cpu 0x7875 (offset 0x3875) */
void p04_L_7875(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  return;
}

/* flash page 4 cpu 0x787A (offset 0x387A) */
void p04_L_787A(void) {
  set_hl(0x7A20);
  p04_L_787D();
  return;
}

/* flash page 4 cpu 0x787D (offset 0x387D) */
void p04_L_787D(void) {
  p04_L_75C5();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7992();
  p04_L_7A03();
  p00_L_32C1();
  p00_L_18B7();
  if (flag_nz()) p04_L_75E1();
  p04_L_797B();
  p04_L_7875();
  return;
}

/* flash page 4 cpu 0x7930 (offset 0x3930) */
void p04_L_7930(void) {
  p04_L_75F8();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7992();
  p04_L_7A03();
  return;
}

/* flash page 4 cpu 0x793E (offset 0x393E) */
void p04_L_793E(void) {
  set_hl(0x7A27);
  a = 0x62;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p04_L_7974;
  lab_p04_L_7974: ;
  p04_L_7930();
  p04_L_764E();
  return;
}

/* flash page 4 cpu 0x794C (offset 0x394C) */
void p04_L_794C(void) {
  set_hl(0x7A2F);
  a = 0x61;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p04_L_7974;
  lab_p04_L_7974: ;
  p04_L_7930();
  p04_L_764E();
  return;
}

/* flash page 4 cpu 0x795A (offset 0x395A) */
void p04_L_795A(void) {
  set_hl(0x7A37);
  a = 0x60;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p04_L_7974;
  lab_p04_L_7974: ;
  p04_L_7930();
  p04_L_764E();
  return;
}

/* flash page 4 cpu 0x7968 (offset 0x3968) */
void p04_L_7968(void) {
  set_hl(0x7AAD);
  a = 0x57;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p04_L_7930();
  p04_L_764E();
  return;
}

/* flash page 4 cpu 0x797A (offset 0x397A) */
void p04_L_797A(void) {
  p00_rst20();
  p04_L_797B();
  return;
}

/* flash page 4 cpu 0x797B (offset 0x397B) */
void p04_L_797B(void) {
  a = 0x09;
  p04_L_797D();
  return;
}

/* flash page 4 cpu 0x797D (offset 0x397D) */
void p04_L_797D(void) {
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  cpu_push_af();
  p00_L_39CF();
  cpu_pop_af();
  p00_L_3639();
  set_hl(0x848E);
  p04_L_7A03();
  p04_L_7992();
  p04_L_7992();
  return;
}

/* flash page 4 cpu 0x7992 (offset 0x3992) */
void p04_L_7992(void) {
  a = 0x20;
  p00_L_3D47();
  return;
}

/* flash page 4 cpu 0x7998 (offset 0x3998) */
void p04_L_7998(void) {
  c = a;
  b = 0x08;
  a = 0;
  flag_logic(a);
  lab_p04_L_799C: ;
  /* sla c */
  cpu_rla();
  flag_cmp(a, 0x0A);
  if (flag_c()) goto lab_p04_L_79A6;
  a = (uint8_t)(a - 0x0A);
  c = (uint8_t)(c + 1);
  lab_p04_L_79A6: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p04_L_799C;
  b = a;
  a = c;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 4 cpu 0x79AC (offset 0x39AC) */
void p04_L_79AC(void) {
  p04_L_75C5();
  p00_L_2315();
  set_hl(0x26D2);
  a = 0x63;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p04_L_7A03();
  p04_L_79C5();
  return;
}

/* flash page 4 cpu 0x79C5 (offset 0x39C5) */
void p04_L_79C5(void) {
  a = 0x3C;
  p04_L_76F1();
  p00_L_16A6();
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_79D7;
  p04_L_75E1();
  goto lab_p04_L_79DC;
  lab_p04_L_79D7: ;
  a = 0x3A;
  p04_L_75CB();
  lab_p04_L_79DC: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  a = 0x6E;
  p00_L_3D47();
  a = 0x3D;
  p00_L_3D47();
  p04_L_76A2();
  p00_L_2324();
  p04_L_75F8();
  set_hl(0x26D7);
  a = 0x64;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p04_L_76E8();
  return;
}

/* flash page 4 cpu 0x7A03 (offset 0x3A03) */
void p04_L_7A03(void) {
  cpu_push_af();
  cpu_push_de();
  cpu_push16(ix);
  lab_p04_L_7A07: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_7A11;
  p00_L_3D47();
  if (flag_nc()) goto lab_p04_L_7A07;
  lab_p04_L_7A11: ;
  ix = cpu_pop16();
  cpu_pop_de();
  cpu_pop_af();
  return;
}

/* flash page 4 cpu 0x7A16 (offset 0x3A16) */
void p04_str_6(void) {
  h = l;
  a = d;
  e = a;
  a = d;
  l = a;
  a = d;
  h = d;
  a = d;
  l = d;
  a = d;
  p04_str_1();
  return;
}

/* flash page 4 cpu 0x7A20 (offset 0x3A20) */
void p04_str_1(void) {
  h = h;
  a = c;
  a = a ^ 0xFF;
  h = h;
  a = b;
  a = (uint8_t)(a - 1);
  /* nop */
  p04_str_12();
  return;
}

/* flash page 4 cpu 0x7A27 (offset 0x3A27) */
void p04_str_12(void) {
  c = l;
  l = c;
  l = mem_read8(hl());
  l = c;
  l = l;
  mem_write8(hl(), l);
  l = l;
  /* nop */
  p04_str_4();
  return;
}

/* flash page 4 cpu 0x7A2F (offset 0x3A2F) */
void p04_str_4(void) {
  c = l;
  h = c;
  a = b;
  l = c;
  l = l;
  mem_write8(hl(), l);
  l = l;
  /* nop */
  p04_str_13();
  return;
}

/* flash page 4 cpu 0x7A37 (offset 0x3A37) */
void p04_str_13(void) {
  c = c;
  l = mem_read8(hl());
  mem_write8(hl(), h);
  h = l;
  mem_write8(hl(), d);
  mem_write8(hl(), e);
  h = l;
  h = e;
  mem_write8(hl(), h);
  l = c;
  l = a;
  l = mem_read8(hl());
  /* nop */
  p04_str_8();
  return;
}

/* flash page 4 cpu 0x7A44 (offset 0x3A44) */
void p04_str_8(void) {
  b = mem_read8(hl());
  l = c;
  mem_write8(hl(), d);
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  if (flag_nz()) goto lab_p04_L_7AAE;
  mem_write8(hl(), l);
  mem_write8(hl(), d);
  halt();
  h = l;
  /* ccf */
  /* nop */
  p04_str_15();
  return;
  lab_p04_L_7AAE: ;
  h = l;
  mem_write8(hl(), d);
  l = a;
  /* nop */
  p04_L_7AB2();
  return;
}

/* flash page 4 cpu 0x7A51 (offset 0x3A51) */
void p04_str_15(void) {
  d = e;
  h = l;
  h = e;
  l = a;
  l = mem_read8(hl());
  h = h;
  if (flag_nz()) goto lab_p04_L_7ABC;
  mem_write8(hl(), l);
  mem_write8(hl(), d);
  halt();
  h = l;
  /* ccf */
  /* nop */
  d = c;
  sp = 0x5100;
  sp = (uint16_t)(sp + 1);
  /* nop */
  l = l;
  l = c;
  l = mem_read8(hl());
  e = b;
  /* nop */
  l = l;
  h = c;
  a = b;
  e = b;
  /* nop */
  p04_L_7A6F();
  return;
  lab_p04_L_7ABC: ;
  h = a;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p04_L_7ADA;
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_7AD4;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_7ADA;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p04_L_7ADA;
  lab_p04_L_7AD4: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_7ADD;
  lab_p04_L_7ADA: ;
  p04_L_6185();
  lab_p04_L_7ADD: ;
  p04_L_5BA1();
  return;
}

/* flash page 4 cpu 0x7A6F (offset 0x3A6F) */
void p04_L_7A6F(void) {
  c = l;
  h = l;
  h = h;
  /* nop */
  p04_str_16();
  return;
}

/* flash page 4 cpu 0x7A73 (offset 0x3A73) */
void p04_str_16(void) {
  c = h;
  l = a;
  mem_write8(hl(), a);
  h = l;
  mem_write8(hl(), d);
  if (flag_nz()) goto lab_p04_L_7AC6;
  l = c;
  l = l;
  l = c;
  mem_write8(hl(), h);
  /* ccf */
  /* nop */
  p04_str_10();
  return;
  lab_p04_L_7AC6: ;
  if (flag_z()) goto lab_p04_L_7AD4;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_7ADA;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p04_L_7ADA;
  lab_p04_L_7AD4: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_7ADD;
  lab_p04_L_7ADA: ;
  p04_L_6185();
  lab_p04_L_7ADD: ;
  p04_L_5BA1();
  return;
}

/* flash page 4 cpu 0x7A80 (offset 0x3A80) */
void p04_str_10(void) {
  d = l;
  mem_write8(hl(), b);
  mem_write8(hl(), b);
  h = l;
  mem_write8(hl(), d);
  if (flag_nz()) goto lab_p04_L_7AD3;
  l = c;
  l = l;
  l = c;
  mem_write8(hl(), h);
  /* ccf */
  /* nop */
  p04_str_7();
  return;
  lab_p04_L_7AD3: ;
  b = 0xFD;
  /* rlc d */
  d = mem_read8(hl());
  if (flag_nz()) goto lab_p04_L_7ADD;
  p04_L_6185();
  lab_p04_L_7ADD: ;
  p04_L_5BA1();
  return;
}

/* flash page 4 cpu 0x7A8D (offset 0x3A8D) */
void p04_str_7(void) {
  c = h;
  h = l;
  h = mem_read8(hl());
  mem_write8(hl(), h);
  if (flag_nz()) goto lab_p04_L_7AD5;
  l = a;
  mem_write8(hl(), l);
  l = mem_read8(hl());
  h = h;
  /* ccf */
  /* nop */
  p04_str_9();
  return;
  lab_p04_L_7AD5: ;
  /* rlc d */
  d = mem_read8(hl());
  if (flag_nz()) goto lab_p04_L_7ADD;
  p04_L_6185();
  lab_p04_L_7ADD: ;
  p04_L_5BA1();
  return;
}

/* flash page 4 cpu 0x7A99 (offset 0x3A99) */
void p04_str_9(void) {
  d = d;
  l = c;
  h = a;
  l = b;
  mem_write8(hl(), h);
  if (flag_nz()) goto lab_p04_L_7AE2;
  l = a;
  mem_write8(hl(), l);
  l = mem_read8(hl());
  h = h;
  /* ccf */
  /* nop */
  p04_str_11();
  return;
  lab_p04_L_7AE2: ;
  h = (uint8_t)(h + 1);
  /* nop */
  p00_L_21C3();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_ex_de_hl();
  return;
}

/* flash page 4 cpu 0x7AA6 (offset 0x3AA6) */
void p04_str_11(void) {
  b = a;
  mem_write8(hl(), l);
  h = l;
  mem_write8(hl(), e);
  mem_write8(hl(), e);
  /* ccf */
  /* nop */
  p04_str_14();
  return;
}

/* flash page 4 cpu 0x7AAD (offset 0x3AAD) */
void p04_str_14(void) {
  e = d;
  h = l;
  mem_write8(hl(), d);
  l = a;
  /* nop */
  p04_L_7AB2();
  return;
}

/* flash page 4 cpu 0x7AB2 (offset 0x3AB2) */
void p04_L_7AB2(void) {
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  if (flag_nz()) p04_L_678F();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p04_L_7ADA;
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_7AD4;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p04_L_7ADA;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p04_L_7ADA;
  lab_p04_L_7AD4: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p04_L_7ADD;
  lab_p04_L_7ADA: ;
  p04_L_6185();
  lab_p04_L_7ADD: ;
  p04_L_5BA1();
  return;
}

/* flash page 4 cpu 0x7AE1 (offset 0x3AE1) */
void p04_L_7AE1(void) {
  set_hl(0x0024);
  p00_L_21C3();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_ex_de_hl();
  return;
}

/* flash page 4 cpu 0x7B03 (offset 0x3B03) */
void p04_L_7B03(void) {
  p04_L_7AE1();
  p04_L_7B06();
  return;
}

/* flash page 4 cpu 0x7B06 (offset 0x3B06) */
void p04_L_7B06(void) {
  p00_L_11FD();
  p04_L_7B09();
  return;
}

/* flash page 4 cpu 0x7B09 (offset 0x3B09) */
void p04_L_7B09(void) {
  set_hl(0x8F74);
  p00_L_1183();
  p00_L_11FD();
  set_hl(0x8F6B);
  p00_L_1183();
  p04_L_7AB2();
  p00_L_0189();
  if (flag_nz()) goto lab_p04_L_7B24;
  p00_L_3573();
  return;
  lab_p04_L_7B24: ;
  set_de(0x0024);
  p00_L_21B6();
  return;
}

/* flash page 4 cpu 0x7B95 (offset 0x3B95) */
void p04_L_7B95(void) {
  a = 0x03;
  cpu_push_af();
  goto lab_p04_L_7B9E;
  lab_p04_L_7B9E: ;
  a = mem_read8(0x8DA5);
  p04_L_7BC8();
  b = a;
  cpu_push_bc();
  a = mem_read8(0x8DA3);
  a = (uint8_t)(a - 1);
  p04_L_7BC8();
  cpu_pop_bc();
  c = a;
  a = 0x3F;
  a = (uint8_t)(a - c);
  if (flag_z()) goto lab_p04_L_7BE1;
  p00_L_17CE();
  if (flag_z()) goto lab_p04_L_7BBB;
  a = (uint8_t)(a - 0x20);
  lab_p04_L_7BBB: ;
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_7BC2;
  a = (uint8_t)(a - 0x0C);
  lab_p04_L_7BC2: ;
  c = a;
  cpu_pop_de();
  p04_L_4157();
  return;
  lab_p04_L_7BE1: ;
  p00_L_24C9();
  return;
}

/* flash page 4 cpu 0x7BC8 (offset 0x3BC8) */
void p04_L_7BC8(void) {
  cpu_push_af();
  p00_L_219B();
  p00_L_187F();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x83);
  if (flag_nc()) goto lab_p04_L_7BE1;
  p00_L_3B5B();
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_7BE1;
  a = e;
  cpu_pop_de();
  flag_cmp(a, d);
  if (flag_c()) return;
  lab_p04_L_7BE1: ;
  p00_L_24C9();
  return;
}

/* flash page 4 cpu 0x7BE4 (offset 0x3BE4) */
void p04_L_7BE4(void) {
  goto lab_p04_L_7BE4;
  lab_p04_L_7BE1: ;
  p00_L_24C9();
  return;
  lab_p04_L_7BE4: ;
  p00_L_334B();
  p00_L_0013();
  if (flag_z()) goto lab_p04_L_7C93;
  p00_rst18();
  p00_L_353D();
  p00_rst08();
  p00_L_22FC();
  p00_L_2333();
  p00_L_38BB();
  p00_L_1037();
  if (flag_nz()) goto lab_p04_L_7BE1;
  p04_L_7C00();
  return;
  lab_p04_L_7C93: ;
  p00_L_01A2();
  if (flag_z()) goto lab_p04_L_7CCE;
  p00_L_38C7();
  p00_rst18();
  p00_L_334B();
  p00_L_17E0();
  p00_L_38C7();
  p00_L_2196();
  p00_L_14CC();
  if (flag_z()) goto lab_p04_L_7CBD;
  p00_L_0ED0();
  p00_L_1169();
  p00_L_353D();
  p00_rst18();
  p00_L_1130();
  p04_L_7C00();
  return;
  lab_p04_L_7CBD: ;
  p00_L_1887();
  p00_L_38F1();
  p04_L_7B03();
  a = 0xFF;
  mem_write8(0x8478, a);
  p04_L_7CCB();
  return;
  lab_p04_L_7CCE: ;
  p00_L_019D();
  if (flag_nz()) { p00_L_24D9(); return; }
  p00_L_38CD();
  p00_L_14CC();
  if (flag_z()) goto lab_p04_L_7CBD;
  p00_L_0ED0();
  p00_rst18();
  p00_L_1689();
  p00_L_38B5();
  p00_L_39FF();
  p00_L_1171();
  p00_L_117F();
  p00_L_168D();
  p00_L_38B5();
  p00_rst08();
  p00_L_113A();
  p00_L_0D1F();
  p00_L_1171();
  p00_L_1130();
  p00_L_0D1F();
  p00_L_22F7();
  p00_L_0D1F();
  p00_L_1108();
  p00_L_0C13();
  p04_L_7C13();
  return;
}

/* flash page 4 cpu 0x7C00 (offset 0x3C00) */
void p04_L_7C00(void) {
  p00_rst08();
  p00_L_38F1();
  p00_L_0D1F();
  p00_L_22F2();
  p00_L_2333();
  p00_L_10F8();
  p00_L_0C13();
  p04_L_7C13();
  return;
}

/* flash page 4 cpu 0x7C13 (offset 0x3C13) */
void p04_L_7C13(void) {
  p00_rst18();
  p00_L_39CF();
  a = 0x15;
  p00_L_32A3();
  cpu_push_bc();
  p00_L_2315();
  p00_L_39CF();
  a = 0x15;
  p00_L_32A3();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + bc()));
  set_bc(0x0004);
  set_hl((uint16_t)(hl() + bc()));
  p04_L_4D37();
  mem_write16(0x9196, de());
  p00_L_21D6();
  p00_L_2324();
  p00_L_39CF();
  a = 0x15;
  p00_L_32A3();
  set_de(mem_read16(0x9196));
  p04_L_7F9B();
  a = 0x58;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  a = 0x70;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  p00_L_2315();
  p00_L_39CF();
  a = 0x15;
  p00_L_32A3();
  cpu_pop_de();
  p04_L_7F9B();
  p00_L_2196();
  p00_L_21A7();
  p00_L_219B();
  p04_L_44E4();
  p00_L_222C();
  p04_L_7D39();
  p00_L_219B();
  a = mem_read8(0x859A);
  flag_cmp(a, 0x44);
  if (flag_nz()) goto lab_p04_L_7C86;
  p00_L_0013();
  if (flag_z()) goto lab_p04_L_7C86;
  p00_rst08();
  goto lab_p04_L_7C89;
  lab_p04_L_7C86: ;
  p00_L_16BC();
  lab_p04_L_7C89: ;
  p00_L_219B();
  p04_L_7C8C();
  return;
}

/* flash page 4 cpu 0x7C8C (offset 0x3C8C) */
void p04_L_7C8C(void) {
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) & ~(1u << 0)));
  p04_L_44E4();
  return;
}

/* flash page 4 cpu 0x7CCB (offset 0x3CCB) */
void p04_L_7CCB(void) {
  p04_L_7C8C();
  return;
}

/* flash page 4 cpu 0x7D14 (offset 0x3D14) */
void p04_L_7D14(void) {
  p04_L_7AB2();
  p04_L_7FA1();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 3)));
  p04_L_72D8();
  a = 0;
  flag_logic(a);
  mem_write8(0x8E67, a);
  set_hl(0x8F50);
  p00_rst20();
  p00_rst18();
  p00_rst18();
  p00_L_3321();
  set_hl(mem_read16(0x84DD));
  mem_write16(0x9196, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  return;
}

/* flash page 4 cpu 0x7D39 (offset 0x3D39) */
void p04_L_7D39(void) {
  p04_L_7D14();
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  lab_p04_L_7D40: ;
  p00_L_2324();
  p00_L_337B();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p04_L_7D53;
  p00_L_233D();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  lab_p04_L_7D53: ;
  p04_L_7151();
  p04_L_717B();
  p04_L_7D6C();
  p04_L_70C2();
  p04_L_7F07();
  if (flag_nc()) { p04_L_7D71(); return; }
  set_hl(mem_read16(0x9196));
  p04_L_43CD();
  goto lab_p04_L_7D40;
}

/* flash page 4 cpu 0x7D44 (offset 0x3D44) */
void p04_L_7D44(void) {
  goto lab_p04_L_7D44;
  lab_p04_L_7D40: ;
  p00_L_2324();
  p00_L_337B();
  lab_p04_L_7D44: ;
  a = e;
  sp = (uint16_t)(sp + 1);
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p04_L_7D53;
  p00_L_233D();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  lab_p04_L_7D53: ;
  p04_L_7151();
  p04_L_717B();
  p04_L_7D6C();
  p04_L_70C2();
  p04_L_7F07();
  if (flag_nc()) { p04_L_7D71(); return; }
  set_hl(mem_read16(0x9196));
  p04_L_43CD();
  goto lab_p04_L_7D40;
}

/* flash page 4 cpu 0x7D6C (offset 0x3D6C) */
void p04_L_7D6C(void) {
  p00_L_0189();
  if (flag_z()) return;
  cpu_pop_hl();
  p04_L_7D71();
  return;
}

/* flash page 4 cpu 0x7D71 (offset 0x3D71) */
void p04_L_7D71(void) {
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 3)));
  p00_L_21A4();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  p04_L_44E4();
  return;
}

/* flash page 4 cpu 0x7D7F (offset 0x3D7F) */
void p04_L_7D7F(void) {
  p00_L_219B();
  p00_L_14D1();
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_163B();
  flag_cmp(a, 0x81);
  if (flag_nc()) { p00_L_24C9(); return; }
  a = mem_read8(0x847A);
  p00_L_12B1();
  return;
}

/* flash page 4 cpu 0x7DDF (offset 0x3DDF) */
void p04_L_7DDF(void) {
  lab_p04_L_7DDF: ;
  set_de(0x8478);
  set_hl(mem_read16(0x9824));
  p00_L_2277();
  p00_L_337B();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 5)) == 0);
  if (flag_nz()) p00_L_235C();
  set_de(0x848E);
  p00_L_2327();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1183();
  p00_rst08();
  p00_L_235C();
  set_hl(mem_read16(0x9196));
  p00_rst20();
  p04_L_718E();
  p00_L_2267();
  p00_L_337B();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 5)) == 0);
  if (flag_nz()) p00_L_233D();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  p04_L_7151();
  set_de(0x848E);
  p00_L_2327();
  set_de(0x8499);
  p00_L_22FF();
  p00_rst08();
  p00_L_233D();
  set_hl(mem_read16(0x9196));
  p00_rst20();
  p00_L_2375();
  p04_L_718E();
  p00_L_0189();
  if (flag_nz()) goto lab_p04_L_7EFE;
  p04_L_70C2();
  p00_L_22F7();
  p00_L_2315();
  p00_L_107E();
  if (flag_nc()) goto lab_p04_L_7EF0;
  p00_L_22F7();
  p00_L_2315();
  a = mem_read8(0x8478);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p04_L_7EF0;
  a = mem_read8(0x8483);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p04_L_7EF0;
  set_hl(mem_read16(0x9196));
  set_de(0x848E);
  p00_L_1183();
  set_hl(0x848E);
  p04_L_4329();
  set_hl(mem_read16(0x9824));
  set_de(0xFFD3);
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  set_hl(0x848E);
  a = 0;
  flag_logic(a);
  p04_L_4364();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_7EF0;
  p00_L_22FC();
  p00_L_3E37();
  p00_L_21DB();
  p00_rst18();
  set_de(0x8F6B);
  set_hl(0x8478);
  a = 0;
  flag_logic(a);
  p04_L_4364();
  p00_L_219B();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p04_L_7EA2;
  p00_L_21A7();
  goto lab_p04_L_7EF0;
  lab_p04_L_7EA2: ;
  a = a | a;
  flag_logic(a);
  a = 0x40;
  if (flag_nz()) goto lab_p04_L_7EAD;
  set_de(0x8478);
  p04_L_441F();
  lab_p04_L_7EAD: ;
  mem_write8(0x966D, a);
  p00_L_2324();
  p00_L_3E37();
  set_de(0x8F6B);
  set_hl(0x8478);
  a = 0;
  flag_logic(a);
  p04_L_4364();
  cpu_push_af();
  p00_L_219B();
  p00_L_2310();
  set_hl(0x8F6B);
  cpu_pop_af();
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_7EF0;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_nz()) p00_L_11F8();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  cpu_pop_hl();
  cpu_pop_af();
  mem_write8(0x966C, a);
  cpu_push_af();
  cpu_push_hl();
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) | (1u << 7)));
  a = 0x03;
  p04_L_438C();
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  lab_p04_L_7EF0: ;
  p04_L_7F07();
  if (flag_nc()) goto lab_p04_L_7EFE;
  set_hl(mem_read16(0x9196));
  p04_L_43CD();
  goto lab_p04_L_7DDF;
  lab_p04_L_7EFE: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_hl();
  p00_L_21A7();
  p04_L_7D71();
  return;
}

/* flash page 4 cpu 0x7E1E (offset 0x3E1E) */
void p04_L_7E1E(void) {
  a = (uint8_t)(a + h);
  p00_L_2327();
  set_de(0x8499);
  p00_L_22FF();
  p00_rst08();
  p00_L_233D();
  set_hl(mem_read16(0x9196));
  p00_rst20();
  p00_L_2375();
  p04_L_718E();
  p00_L_0189();
  if (flag_nz()) goto lab_p04_L_7EFE;
  p04_L_70C2();
  p00_L_22F7();
  p00_L_2315();
  p00_L_107E();
  if (flag_nc()) goto lab_p04_L_7EF0;
  p00_L_22F7();
  p00_L_2315();
  a = mem_read8(0x8478);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p04_L_7EF0;
  a = mem_read8(0x8483);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p04_L_7EF0;
  set_hl(mem_read16(0x9196));
  set_de(0x848E);
  p00_L_1183();
  set_hl(0x848E);
  p04_L_4329();
  set_hl(mem_read16(0x9824));
  set_de(0xFFD3);
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  set_hl(0x848E);
  a = 0;
  flag_logic(a);
  p04_L_4364();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_7EF0;
  p00_L_22FC();
  p00_L_3E37();
  p00_L_21DB();
  p00_rst18();
  set_de(0x8F6B);
  set_hl(0x8478);
  a = 0;
  flag_logic(a);
  p04_L_4364();
  p00_L_219B();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p04_L_7EA2;
  p00_L_21A7();
  goto lab_p04_L_7EF0;
  lab_p04_L_7EA2: ;
  a = a | a;
  flag_logic(a);
  a = 0x40;
  if (flag_nz()) goto lab_p04_L_7EAD;
  set_de(0x8478);
  p04_L_441F();
  lab_p04_L_7EAD: ;
  mem_write8(0x966D, a);
  p00_L_2324();
  p00_L_3E37();
  set_de(0x8F6B);
  set_hl(0x8478);
  a = 0;
  flag_logic(a);
  p04_L_4364();
  cpu_push_af();
  p00_L_219B();
  p00_L_2310();
  set_hl(0x8F6B);
  cpu_pop_af();
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_7EF0;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_nz()) p00_L_11F8();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  cpu_pop_hl();
  cpu_pop_af();
  mem_write8(0x966C, a);
  cpu_push_af();
  cpu_push_hl();
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) | (1u << 7)));
  a = 0x03;
  p04_L_438C();
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  lab_p04_L_7EF0: ;
  p04_L_7F07();
  if (flag_nc()) goto lab_p04_L_7EFE;
  set_hl(mem_read16(0x9196));
  p04_L_43CD();
  p04_L_7DDF();
  return;
  lab_p04_L_7EFE: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_hl();
  p00_L_21A7();
  p04_L_7D71();
  return;
}

/* flash page 4 cpu 0x7E35 (offset 0x3E35) */
void p04_L_7E35(void) {
  mem_write8(hl(), c);
  p00_L_0189();
  if (flag_nz()) goto lab_p04_L_7EFE;
  p04_L_70C2();
  p00_L_22F7();
  p00_L_2315();
  p00_L_107E();
  if (flag_nc()) goto lab_p04_L_7EF0;
  p00_L_22F7();
  p00_L_2315();
  a = mem_read8(0x8478);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p04_L_7EF0;
  a = mem_read8(0x8483);
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p04_L_7EF0;
  set_hl(mem_read16(0x9196));
  set_de(0x848E);
  p00_L_1183();
  set_hl(0x848E);
  p04_L_4329();
  set_hl(mem_read16(0x9824));
  set_de(0xFFD3);
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  set_hl(0x848E);
  a = 0;
  flag_logic(a);
  p04_L_4364();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p04_L_7EF0;
  p00_L_22FC();
  p00_L_3E37();
  p00_L_21DB();
  p00_rst18();
  set_de(0x8F6B);
  set_hl(0x8478);
  a = 0;
  flag_logic(a);
  p04_L_4364();
  p00_L_219B();
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_z()) goto lab_p04_L_7EA2;
  p00_L_21A7();
  goto lab_p04_L_7EF0;
  lab_p04_L_7EA2: ;
  a = a | a;
  flag_logic(a);
  a = 0x40;
  if (flag_nz()) goto lab_p04_L_7EAD;
  set_de(0x8478);
  p04_L_441F();
  lab_p04_L_7EAD: ;
  mem_write8(0x966D, a);
  p00_L_2324();
  p00_L_3E37();
  set_de(0x8F6B);
  set_hl(0x8478);
  a = 0;
  flag_logic(a);
  p04_L_4364();
  cpu_push_af();
  p00_L_219B();
  p00_L_2310();
  set_hl(0x8F6B);
  cpu_pop_af();
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p04_L_7EF0;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_nz()) p00_L_11F8();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 5)));
  cpu_pop_hl();
  cpu_pop_af();
  mem_write8(0x966C, a);
  cpu_push_af();
  cpu_push_hl();
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) | (1u << 7)));
  a = 0x03;
  p04_L_438C();
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) & ~(1u << 7)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 5)));
  lab_p04_L_7EF0: ;
  p04_L_7F07();
  if (flag_nc()) goto lab_p04_L_7EFE;
  set_hl(mem_read16(0x9196));
  p04_L_43CD();
  p04_L_7DDF();
  return;
  lab_p04_L_7EFE: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_hl();
  p00_L_21A7();
  p04_L_7D71();
  return;
}

/* flash page 4 cpu 0x7F07 (offset 0x3F07) */
void p04_L_7F07(void) {
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + 1);
  p04_L_75A2();
  if (flag_nc()) return;
  mem_write8(0x8E67, a);
  return;
}

/* flash page 4 cpu 0x7F9B (offset 0x3F9B) */
void p04_L_7F9B(void) {
  set_hl(0x848E);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 4 cpu 0x7FA1 (offset 0x3FA1) */
void p04_L_7FA1(void) {
  p00_L_0189();
  if (flag_z()) return;
  cpu_pop_hl();
  p04_L_44E4();
  return;
}

/* flash page 4 cpu 0x7FA9 (offset 0x3FA9) */
void p04_L_7FA9(void) {
  goto lab_p04_L_7FA9;
  lab_p04_L_7AEC: ;
  p04_L_7AE1();
  set_hl(0x8F50);
  p00_L_1183();
  p00_L_11FD();
  set_hl(0x8F59);
  p00_L_1183();
  p00_L_11FD();
  goto lab_p04_L_7B18;
  lab_p04_L_7B18: ;
  p04_L_7AB2();
  p00_L_0189();
  if (flag_nz()) goto lab_p04_L_7B24;
  p00_L_3573();
  return;
  lab_p04_L_7B24: ;
  set_de(0x0024);
  p00_L_21B6();
  return;
  lab_p04_L_7B2A: ;
  p04_L_7AB2();
  p00_L_0189();
  if (flag_nz()) goto lab_p04_L_7B24;
  p00_L_3567();
  return;
  lab_p04_L_7B36: ;
  a = b;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p04_L_7B48;
  flag_cmp(a, 0x03);
  if (flag_nz()) { p00_L_24E5(); return; }
  a = e;
  flag_cmp(a, 0x07);
  if (flag_z()) { p00_L_24E5(); return; }
  goto lab_p04_L_7B50;
  lab_p04_L_7B48: ;
  cpu_push_de();
  p00_L_2222();
  p00_L_1229();
  cpu_pop_de();
  lab_p04_L_7B50: ;
  a = 0xFB;
  a = (uint8_t)(a + e);
  cpu_push_af();
  p00_L_2222();
  b = 0x03;
  p00_L_3981();
  p00_L_219B();
  cpu_pop_af();
  cpu_push_af();
  p00_rst18();
  p04_L_7AB2();
  p00_L_219B();
  cpu_pop_af();
  set_hl(0x847A);
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_z()) { p04_L_4391(); return; }
  cpu_push_af();
  a = mem_read8(hl());
  cpu_push_af();
  p00_L_3579();
  if (flag_z()) goto lab_p04_L_7B7C;
  cpu_pop_af();
  cpu_pop_af();
  return;
  lab_p04_L_7B7C: ;
  cpu_pop_bc();
  cpu_pop_af();
  set_hl(0x664B);
  flag_set_z((b & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p04_L_7B88;
  set_hl(0x6646);
  lab_p04_L_7B88: ;
  set_bc(mem_read16(0x8D18));
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) & ~(1u << 1)));
  d = a;
  p04_L_65AF();
  return;
  lab_p04_L_7B9A: ;
  cpu_push_bc();
  p04_L_7AB2();
  a = mem_read8(0x8DA5);
  p04_L_7BC8();
  b = a;
  cpu_push_bc();
  a = mem_read8(0x8DA3);
  a = (uint8_t)(a - 1);
  p04_L_7BC8();
  cpu_pop_bc();
  c = a;
  a = 0x3F;
  a = (uint8_t)(a - c);
  if (flag_z()) goto lab_p04_L_7BE1;
  p00_L_17CE();
  if (flag_z()) goto lab_p04_L_7BBB;
  a = (uint8_t)(a - 0x20);
  lab_p04_L_7BBB: ;
  p00_L_18B7();
  if (flag_z()) goto lab_p04_L_7BC2;
  a = (uint8_t)(a - 0x0C);
  lab_p04_L_7BC2: ;
  c = a;
  cpu_pop_de();
  p04_L_4157();
  return;
  lab_p04_L_7BE1: ;
  p00_L_24C9();
  return;
  lab_p04_L_7BF1: ;
  p00_rst08();
  p00_L_22FC();
  p00_L_2333();
  p00_L_38BB();
  p00_L_1037();
  if (flag_nz()) goto lab_p04_L_7BE1;
  p04_L_7C00();
  return;
  lab_p04_L_7D8D: ;
  if (flag_nc()) { p00_L_24C9(); return; }
  a = mem_read8(0x847A);
  p00_L_12B1();
  return;
  lab_p04_L_7D96: ;
  p04_L_7D7F();
  flag_cmp(a, 0x09);
  if (flag_nc()) goto lab_p04_L_7D8D;
  mem_write8(0x9D8E, a);
  p04_L_7D7F();
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p04_L_7D8D;
  a = (uint8_t)(a - 1);
  cpu_push_af();
  p04_L_7AB2();
  cpu_pop_af();
  mem_write8(0x9668, a);
  a = 0x02;
  mem_write8(0x9775, a);
  p04_L_7FA1();
  a = mem_read8(0x9D8E);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 3)));
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p04_L_72D8();
  a = 0;
  flag_logic(a);
  mem_write8(0x8E67, a);
  set_hl(0x8F50);
  p00_rst20();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  p00_L_3321();
  set_hl(mem_read16(0x84DD));
  mem_write16(0x9196, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  p04_L_7DDF();
  return;
  lab_p04_L_7F13: ;
  p00_L_0013();
  if (flag_z()) { p00_L_24D9(); return; }
  p04_L_5DC6();
  set_hl(0x8F6B);
  a = mem_read8(0x915C);
  p04_L_5E38();
  p04_L_7AB2();
  p04_L_7FA1();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 3)));
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  p04_L_72D8();
  a = 0;
  flag_logic(a);
  mem_write8(0x8E67, a);
  set_hl(0x8F6B);
  p00_rst20();
  p00_rst08();
  p00_L_222C();
  p00_L_3321();
  set_hl(mem_read16(0x84DD));
  mem_write16(0x9196, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 5)));
  lab_p04_L_7F4F: ;
  p00_L_2324();
  p00_L_337B();
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p04_L_7F62;
  p00_L_235C();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  lab_p04_L_7F62: ;
  p04_L_7151();
  set_de(0x848E);
  p00_L_2318();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_1183();
  p00_L_235C();
  set_hl(mem_read16(0x9196));
  p00_L_11F8();
  p00_L_2333();
  p04_L_718E();
  p04_L_7D6C();
  p04_L_70C2();
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + 1);
  set_hl(0x8DA3);
  cpu_cp_hl();
  if (flag_nc()) { p04_L_7D71(); return; }
  mem_write8(0x8E67, a);
  set_hl(mem_read16(0x9196));
  p04_L_43E1();
  goto lab_p04_L_7F4F;
  lab_p04_L_7FA9: ;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p04_L_7B18;
  flag_cmp(a, 0x9C);
  if (flag_z()) goto lab_p04_L_7B2A;
  flag_cmp(a, 0x9D);
  if (flag_z()) { p04_L_7B03(); return; }
  flag_cmp(a, 0x9E);
  if (flag_z()) goto lab_p04_L_7B36;
  flag_cmp(a, 0xA1);
  if (flag_z()) goto lab_p04_L_7B9A;
  flag_cmp(a, 0xA4);
  if (flag_z()) goto lab_p04_L_7D96;
  flag_cmp(a, 0xA6);
  if (flag_z()) goto lab_p04_L_7AEC;
  flag_cmp(a, 0xA7);
  if (flag_z()) goto lab_p04_L_7BF1;
  flag_cmp(a, 0xA8);
  if (flag_z()) goto lab_p04_L_7F13;
  flag_cmp(a, 0xA9);
  if (flag_z()) { p04_L_7D39(); return; }
  return;
}


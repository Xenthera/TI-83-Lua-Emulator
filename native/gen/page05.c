/* Recovered from flash page 5 (mechanical ASM->C) */
/* cpu window 0x4000..0x7FFF prefix=p05_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p05_L_4000(void);
void p05_L_4003(void);
void p05_L_4028(void);
void p05_L_4043(void);
void p05_L_4060(void);
void p05_L_406D(void);
void p05_L_407A(void);
void p05_L_40A3(void);
void p05_L_40AD(void);
void p05_L_40C6(void);
void p05_L_40CD(void);
void p05_L_40D5(void);
void p05_L_40E3(void);
void p05_L_40EA(void);
void p05_L_40F7(void);
void p05_L_4100(void);
void p05_L_413B(void);
void p05_L_4164(void);
void p05_L_4260(void);
void p05_L_42C3(void);
void p05_L_42D4(void);
void p05_L_42DD(void);
void p05_L_42E8(void);
void p05_L_42EE(void);
void p05_L_42F9(void);
void p05_L_4327(void);
void p05_L_432F(void);
void p05_L_435D(void);
void p05_L_43D3(void);
void p05_L_441E(void);
void p05_L_4423(void);
void p05_L_442D(void);
void p05_L_4435(void);
void p05_L_443F(void);
void p05_L_4454(void);
void p05_L_4472(void);
void p05_L_4477(void);
void p05_L_448C(void);
void p05_L_44B3(void);
void p05_L_4524(void);
void p05_L_4549(void);
void p05_L_4562(void);
void p05_L_4567(void);
void p05_L_456A(void);
void p05_L_45CD(void);
void p05_L_45F7(void);
void p05_L_460B(void);
void p05_L_4626(void);
void p05_L_462B(void);
void p05_L_4652(void);
void p05_L_4692(void);
void p05_L_46B6(void);
void p05_L_46C1(void);
void p05_L_46C7(void);
void p05_L_46CD(void);
void p05_L_46DD(void);
void p05_L_46F6(void);
void p05_L_4702(void);
void p05_L_4721(void);
void p05_L_472F(void);
void p05_L_4758(void);
void p05_L_475E(void);
void p05_L_4760(void);
void p05_L_477B(void);
void p05_L_4783(void);
void p05_L_478B(void);
void p05_L_4797(void);
void p05_L_47A3(void);
void p05_L_47B8(void);
void p05_L_47C2(void);
void p05_L_47CD(void);
void p05_L_47EA(void);
void p05_L_47F6(void);
void p05_L_47FA(void);
void p05_L_47FF(void);
void p05_L_4802(void);
void p05_L_4861(void);
void p05_L_487A(void);
void p05_L_4882(void);
void p05_L_488C(void);
void p05_L_48B6(void);
void p05_L_48C0(void);
void p05_L_48F2(void);
void p05_L_4932(void);
void p05_L_4938(void);
void p05_L_493E(void);
void p05_L_4941(void);
void p05_L_4AC1(void);
void p05_L_4AE3(void);
void p05_L_4B17(void);
void p05_L_4B30(void);
void p05_L_4B32(void);
void p05_L_4B46(void);
void p05_L_4B4A(void);
void p05_L_4C04(void);
void p05_L_4C32(void);
void p05_L_4C98(void);
void p05_L_4CB9(void);
void p05_L_4D56(void);
void p05_L_4D70(void);
void p05_L_4DAB(void);
void p05_L_4DDF(void);
void p05_L_4E03(void);
void p05_L_4E2D(void);
void p05_L_4E35(void);
void p05_L_4E97(void);
void p05_L_4EB7(void);
void p05_L_4EBC(void);
void p05_L_4F79(void);
void p05_L_4F98(void);
void p05_L_4FF5(void);
void p05_L_4FF8(void);
void p05_L_5008(void);
void p05_L_500F(void);
void p05_L_50EB(void);
void p05_L_50F5(void);
void p05_L_50FF(void);
void p05_L_5116(void);
void p05_L_5169(void);
void p05_L_516D(void);
void p05_L_5199(void);
void p05_L_519C(void);
void p05_L_51A7(void);
void p05_L_51B1(void);
void p05_L_51C7(void);
void p05_L_51D9(void);
void p05_L_520D(void);
void p05_L_5221(void);
void p05_L_5224(void);
void p05_L_522F(void);
void p05_L_526B(void);
void p05_L_5285(void);
void p05_L_5357(void);
void p05_L_5385(void);
void p05_L_538B(void);
void p05_L_5397(void);
void p05_L_53C0(void);
void p05_L_53C9(void);
void p05_L_53CE(void);
void p05_L_5403(void);
void p05_L_5409(void);
void p05_L_5427(void);
void p05_L_5430(void);
void p05_L_543C(void);
void p05_L_543E(void);
void p05_L_5446(void);
void p05_L_544D(void);
void p05_L_5463(void);
void p05_L_5468(void);
void p05_L_5470(void);
void p05_L_5488(void);
void p05_L_548F(void);
void p05_L_549F(void);
void p05_L_54A7(void);
void p05_L_54BB(void);
void p05_L_54CA(void);
void p05_L_550D(void);
void p05_L_551B(void);
void p05_L_552C(void);
void p05_L_5530(void);
void p05_L_5533(void);
void p05_L_554E(void);
void p05_L_5553(void);
void p05_L_5581(void);
void p05_L_558A(void);
void p05_L_55AC(void);
void p05_L_55B6(void);
void p05_L_55C2(void);
void p05_L_55CD(void);
void p05_L_5636(void);
void p05_L_563F(void);
void p05_L_5649(void);
void p05_L_565F(void);
void p05_L_5663(void);
void p05_L_5665(void);
void p05_L_5687(void);
void p05_L_5691(void);
void p05_L_56A9(void);
void p05_L_56EA(void);
void p05_L_575A(void);
void p05_L_578B(void);
void p05_L_5797(void);
void p05_L_57A8(void);
void p05_L_57B8(void);
void p05_L_57D8(void);
void p05_L_57FC(void);
void p05_L_584C(void);
void p05_L_5868(void);
void p05_L_5874(void);
void p05_L_588E(void);
void p05_L_58A7(void);
void p05_L_58C6(void);
void p05_L_58DC(void);
void p05_L_58DF(void);
void p05_L_58EE(void);
void p05_L_5954(void);
void p05_L_59A3(void);
void p05_L_59B0(void);
void p05_L_5A11(void);
void p05_L_5A32(void);
void p05_L_5A68(void);
void p05_L_5A71(void);
void p05_L_5A76(void);
void p05_L_5ADB(void);
void p05_L_5AEE(void);
void p05_L_5AFB(void);
void p05_L_5B14(void);
void p05_L_5B17(void);
void p05_L_5B1D(void);
void p05_L_5B20(void);
void p05_L_5B5C(void);
void p05_L_5B62(void);
void p05_L_5B6F(void);
void p05_L_5B77(void);
void p05_L_5BA7(void);
void p05_L_5BB1(void);
void p05_L_5BCD(void);
void p05_L_5BE9(void);
void p05_L_5C38(void);
void p05_L_5C44(void);
void p05_L_5C4F(void);
void p05_L_5C80(void);
void p05_L_5CD6(void);
void p05_L_5CE2(void);
void p05_L_5CE9(void);
void p05_L_5CEA(void);
void p05_L_5CEC(void);
void p05_L_5CED(void);
void p05_L_5CF2(void);
void p05_L_5CFB(void);
void p05_L_5CFF(void);
void p05_L_5D42(void);
void p05_L_5D63(void);
void p05_L_5D6D(void);
void p05_L_5D75(void);
void p05_L_5D81(void);
void p05_L_5D9C(void);
void p05_L_5DB7(void);
void p05_L_5E10(void);
void p05_L_5E6F(void);
void p05_L_5E77(void);
void p05_L_5E84(void);
void p05_L_5E90(void);
void p05_L_5E9F(void);
void p05_L_5EA4(void);
void p05_L_5EA9(void);
void p05_L_5ECD(void);
void p05_L_5EDA(void);
void p05_L_5EE1(void);
void p05_L_5EE6(void);
void p05_L_5EFA(void);
void p05_L_5F01(void);
void p05_L_5F25(void);
void p05_L_5F31(void);
void p05_L_5F7E(void);
void p05_L_5FEC(void);
void p05_L_6020(void);
void p05_L_602F(void);
void p05_L_603D(void);
void p05_L_604B(void);
void p05_L_6056(void);
void p05_L_605E(void);
void p05_L_6067(void);
void p05_L_6077(void);
void p05_L_607D(void);
void p05_L_608D(void);
void p05_L_609D(void);
void p05_L_60A0(void);
void p05_L_60CD(void);
void p05_L_6120(void);
void p05_L_6185(void);
void p05_L_61AD(void);
void p05_L_61D3(void);
void p05_L_61E2(void);
void p05_L_61E9(void);
void p05_L_6201(void);
void p05_L_620C(void);
void p05_L_621C(void);
void p05_L_622C(void);
void p05_L_6236(void);
void p05_L_6240(void);
void p05_L_6248(void);
void p05_L_6250(void);
void p05_L_6254(void);
void p05_L_62DB(void);
void p05_L_62FE(void);
void p05_L_6312(void);
void p05_L_635B(void);
void p05_L_6370(void);
void p05_L_637C(void);
void p05_L_64AD(void);
void p05_L_64B1(void);
void p05_L_6512(void);
void p05_L_6516(void);
void p05_L_6519(void);
void p05_L_652D(void);
void p05_L_6569(void);
void p05_L_6574(void);
void p05_L_6590(void);
void p05_L_659C(void);
void p05_L_65A8(void);
void p05_L_6635(void);
void p05_L_664E(void);
void p05_L_665C(void);
void p05_L_6663(void);
void p05_L_6671(void);
void p05_L_668B(void);
void p05_L_6696(void);
void p05_L_66BB(void);
void p05_L_66EA(void);
void p05_L_66F6(void);
void p05_L_6707(void);
void p05_L_6710(void);
void p05_L_6752(void);
void p05_L_675A(void);
void p05_L_676B(void);
void p05_L_6773(void);
void p05_L_67B1(void);
void p05_L_67B4(void);
void p05_L_67C4(void);
void p05_L_67C8(void);
void p05_L_67EE(void);
void p05_L_67F0(void);
void p05_L_6814(void);
void p05_L_6825(void);
void p05_L_6830(void);
void p05_L_6834(void);
void p05_L_6876(void);
void p05_L_6880(void);
void p05_L_688C(void);
void p05_L_6891(void);
void p05_L_6896(void);
void p05_L_689C(void);
void p05_L_68AB(void);
void p05_L_68B8(void);
void p05_L_68F5(void);
void p05_L_6938(void);
void p05_L_6B36(void);
void p05_L_6B56(void);
void p05_L_6B60(void);
void p05_L_6B86(void);
void p05_L_6BB3(void);
void p05_L_6BB9(void);
void p05_L_6BD3(void);
void p05_L_6BDB(void);
void p05_L_6C02(void);
void p05_L_6C47(void);
void p05_L_6D19(void);
void p05_L_6D21(void);
void p05_L_6D9C(void);
void p05_L_6DB5(void);
void p05_L_6DDE(void);
void p05_L_6DEC(void);
void p05_L_6DFB(void);
void p05_L_6E04(void);
void p05_L_6E05(void);
void p05_L_6E0B(void);
void p05_L_6E45(void);
void p05_L_6EA6(void);
void p05_L_6ECD(void);
void p05_L_6F87(void);
void p05_L_6FAE(void);
void p05_L_6FB2(void);
void p05_L_6FB7(void);
void p05_L_6FBC(void);
void p05_L_6FCD(void);
void p05_L_6FD8(void);
void p05_L_7019(void);
void p05_L_7036(void);
void p05_L_7051(void);
void p05_L_70AC(void);
void p05_L_70B5(void);
void p05_L_70E1(void);
void p05_L_70F5(void);
void p05_L_7101(void);
void p05_L_7104(void);
void p05_L_7113(void);
void p05_L_71F3(void);
void p05_L_71FA(void);
void p05_L_7218(void);
void p05_L_722B(void);
void p05_L_722F(void);
void p05_L_7298(void);
void p05_L_72B7(void);
void p05_L_72CD(void);
void p05_L_72F9(void);
void p05_L_7331(void);
void p05_L_735E(void);
void p05_L_740F(void);
void p05_L_7429(void);
void p05_L_745C(void);
void p05_L_7466(void);
void p05_L_748E(void);
void p05_L_74B8(void);
void p05_L_7550(void);
void p05_L_755C(void);
void p05_L_7565(void);
void p05_L_756B(void);
void p05_L_7583(void);
void p05_L_75A2(void);
void p05_L_75AF(void);
void p05_L_76A6(void);
void p05_L_76A9(void);
void p05_L_76B5(void);
void p05_L_76BC(void);
void p05_L_76BF(void);
void p05_L_76C7(void);
void p05_L_77CB(void);
void p05_L_77CD(void);
void p05_font(void);
void p05_str_8(void);
void p05_str_4(void);
void p05_str_9(void);
void p05_str_2(void);
void p05_str_5(void);
void p05_str_6(void);
void p05_str_3(void);
void p05_str_7(void);
void p05_str_1(void);
void p05_L_7986(void);
void p05_L_79A0(void);
void p05_L_79CF(void);
void p05_L_7A24(void);
void p05_L_7A32(void);
void p05_L_7A50(void);
void p05_L_7A60(void);
void p05_L_7D41(void);
void p05_L_7DCD(void);

/* flash page 5 cpu 0x4000 (offset 0x0000) */
void p05_L_4000(void) {
  p05_L_4702();
  p05_L_4003();
  return;
}

/* flash page 5 cpu 0x4003 (offset 0x0003) */
void p05_L_4003(void) {
  a = mem_read8(0x8446);
  cpu_push_af();
  set_hl(0x406D);
  p00_L_07C1();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  cpu_pop_af();
  p05_L_4060();
  p05_L_407A();
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  p00_L_3D17();
  p05_L_462B();
  p05_L_4692();
  p05_L_4567();
  p05_L_4028();
  return;
}

/* flash page 5 cpu 0x4028 (offset 0x0028) */
void p05_L_4028(void) {
  a = 0x0A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p05_L_4035;
  a = 0x49;
  p00_L_3C45();
  lab_p05_L_4035: ;
  mem_write8(0x844C, a);
  a = 0x00;
  mem_write8(0x844B, a);
  p05_L_4454();
  p05_L_4477();
  p05_L_4043();
  return;
}

/* flash page 5 cpu 0x4043 (offset 0x0043) */
void p05_L_4043(void) {
  set_hl(0x848E);
  lab_p05_L_4046: ;
  a = mem_read8(hl());
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_4058;
  cpu_push_hl();
  p00_L_36C3();
  cpu_pop_hl();
  if (flag_nz()) goto lab_p05_L_4046;
  p00_L_24F5();
  return;
  lab_p05_L_4058: ;
  p00_L_3645();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 5)));
  return;
}

/* flash page 5 cpu 0x4060 (offset 0x0060) */
void p05_L_4060(void) {
  mem_write8(0x847A, a);
  a = 0x5C;
  mem_write8(0x8479, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x847B, a);
  return;
}

/* flash page 5 cpu 0x406D (offset 0x006D) */
void p05_L_406D(void) {
  d = e;
  b = c;
  os_jp_hl();
  return;
}

/* flash page 5 cpu 0x407A (offset 0x007A) */
void p05_L_407A(void) {
  p00_L_2413();
  if (flag_nc()) goto lab_p05_L_408D;
  set_hl(0x0101);
  p00_L_1C81();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_101A();
  p00_L_1135();
  lab_p05_L_408D: ;
  p00_L_1847();
  p00_L_21E5();
  p00_L_03A0();
  p00_L_0740();
  p05_L_40A3();
  p00_L_188D();
  mem_write16(0x9702, hl());
  return;
}

/* flash page 5 cpu 0x40A3 (offset 0x00A3) */
void p05_L_40A3(void) {
  set_hl(0x0101);
  mem_write16(0x96FC, hl());
  mem_write16(0x970A, hl());
  return;
}

/* flash page 5 cpu 0x40AD (offset 0x00AD) */
void p05_L_40AD(void) {
  a = 0x0D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p05_L_40BA;
  a = 0x4A;
  p00_L_3C45();
  lab_p05_L_40BA: ;
  mem_write8(0x844C, a);
  p05_L_4454();
  p05_L_4472();
  p05_L_4043();
  return;
}

/* flash page 5 cpu 0x40C6 (offset 0x00C6) */
void p05_L_40C6(void) {
  p00_L_3D7D();
  p05_L_456A();
  p00_L_166E();
  p00_L_36FF();
  p00_L_3255();
  p05_L_40D5();
  return;
}

/* flash page 5 cpu 0x40CD (offset 0x00CD) */
void p05_L_40CD(void) {
  l = mem_read8(hl());
  d = 0xCD;
  p00_rst38_isr();
  mem_write8(hl(), 0xCD);
  d = l;
  mem_write8(0xF42A, a);
  /* sub (hl) */
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96FA, hl());
  mem_write16(0x96F8, hl());
  p00_L_3645();
  p05_L_40E3();
  return;
}

/* flash page 5 cpu 0x40D5 (offset 0x00D5) */
void p05_L_40D5(void) {
  set_hl(mem_read16(0x96F4));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96FA, hl());
  mem_write16(0x96F8, hl());
  p00_L_3645();
  p05_L_40E3();
  return;
}

/* flash page 5 cpu 0x40E3 (offset 0x00E3) */
void p05_L_40E3(void) {
  p00_L_37A7();
  return;
}

/* flash page 5 cpu 0x40EA (offset 0x00EA) */
void p05_L_40EA(void) {
  set_hl(0x0615);
  p00_L_25A2();
  p05_L_40F7();
  p00_L_25C8();
  return;
}

/* flash page 5 cpu 0x40F7 (offset 0x00F7) */
void p05_L_40F7(void) {
  p05_L_448C();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 5)));
  set_hl(mem_read16(0x858D));
  set_bc(0x4260);
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_z()) goto lab_p05_L_411F;
  a = mem_read8(0x9703);
  flag_cmp(a, e);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  a = mem_read8(0x9702);
  d = e;
  e = a;
  p05_L_413B();
  a = h;
  mem_write8(0x9703, a);
  return;
  lab_p05_L_411F: ;
  a = mem_read8(0x9702);
  flag_cmp(a, e);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  a = mem_read8(0x9703);
  d = a;
  p05_L_413B();
  a = l;
  mem_write8(0x9702, a);
  set_hl(0x0101);
  mem_write16(0x970A, hl());
  a = a | h;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x4100 (offset 0x0100) */
void p05_L_4100(void) {
  a = (uint8_t)(a + l);
  set_bc(0x4260);
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_bc();
  if (flag_z()) goto lab_p05_L_411F;
  a = mem_read8(0x9703);
  flag_cmp(a, e);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  a = mem_read8(0x9702);
  d = e;
  e = a;
  p05_L_413B();
  a = h;
  mem_write8(0x9703, a);
  return;
  lab_p05_L_411F: ;
  a = mem_read8(0x9702);
  flag_cmp(a, e);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  a = mem_read8(0x9703);
  d = a;
  p05_L_413B();
  a = l;
  mem_write8(0x9702, a);
  set_hl(0x0101);
  mem_write16(0x970A, hl());
  a = a | h;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x413B (offset 0x013B) */
void p05_L_413B(void) {
  cpu_push_de();
  p00_L_22FC();
  p00_rst10();
  p00_L_1847();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_3AE3();
  p00_L_22FC();
  p00_rst10();
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) p00_L_0087();
  cpu_pop_hl();
  return;
}

/* flash page 5 cpu 0x4164 (offset 0x0164) */
void p05_L_4164(void) {
  goto lab_p05_L_4164;
  lab_p05_L_4018: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  p00_L_3D17();
  p05_L_462B();
  p05_L_4692();
  p05_L_4567();
  p05_L_4028();
  return;
  lab_p05_L_4164: ;
  p00_L_1916();
  if (flag_z()) return;
  p05_L_40EA();
  a = mem_read8(0x8444);
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p05_L_4188;
  set_hl(0x406D);
  p00_L_07CC();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p05_L_4018;
  p05_L_462B();
  p05_L_4692();
  p05_L_4028();
  return;
  lab_p05_L_4188: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p05_L_4196;
  p05_L_462B();
  p05_L_4692();
  goto lab_p05_L_4199;
  lab_p05_L_4196: ;
  p05_L_46C7();
  lab_p05_L_4199: ;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  a = 0;
  flag_logic(a);
  mem_write8(0x844B, a);
  set_hl(0x4260);
  mem_write16(0x858D, hl());
  set_hl(0x40C6);
  mem_write16(0x8595, hl());
  set_hl(0x4702);
  mem_write16(0x8591, hl());
  p05_L_40AD();
  p00_L_3CC9();
  return;
}

/* flash page 5 cpu 0x4260 (offset 0x0260) */
void p05_L_4260(void) {
  goto lab_p05_L_4260;
  lab_p05_L_4160: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p05_L_41C5;
  p05_L_4164();
  return;
  lab_p05_L_41C5: ;
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p05_L_41CE;
  p00_L_3783();
  goto lab_p05_L_4240;
  lab_p05_L_41CE: ;
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p05_L_41D7;
  p00_L_378F();
  goto lab_p05_L_4240;
  lab_p05_L_41D7: ;
  flag_cmp(a, 0x8A);
  if (flag_z()) return;
  flag_cmp(a, 0x0C);
  if (flag_z()) return;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p05_L_41E5;
  p00_L_369F();
  return;
  lab_p05_L_41E5: ;
  flag_cmp(a, 0x0D);
  if (flag_z()) return;
  flag_cmp(a, 0x0E);
  if (flag_z()) goto lab_p05_L_41F0;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p05_L_41F7;
  lab_p05_L_41F0: ;
  p00_L_325B();
  p00_L_37A1();
  return;
  lab_p05_L_41F7: ;
  flag_cmp(a, 0x0F);
  if (flag_z()) goto lab_p05_L_41FF;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p05_L_4229;
  lab_p05_L_41FF: ;
  set_hl(mem_read16(0x96F6));
  set_de(mem_read16(0x96FA));
  set_de((uint16_t)(de() - 1));
  p00_L_192A();
  if (flag_nz()) goto lab_p05_L_4214;
  a = 0x05;
  mem_write8(0x8444, a);
  p05_L_4164();
  return;
  lab_p05_L_4214: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  set_hl(mem_read16(0x96F8));
  set_de(mem_read16(0x96FA));
  p00_L_192A();
  if (flag_z()) return;
  a = mem_read8(hl());
  e = a;
  d = 0x00;
  goto lab_p05_L_4233;
  lab_p05_L_4229: ;
  flag_cmp(a, 0x5A);
  if (flag_c()) return;
  p00_L_3BBB();
  a = d;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  a = e;
  lab_p05_L_4233: ;
  flag_cmp(a, 0x3A);
  if (flag_nc()) return;
  flag_cmp(a, 0x30);
  if (flag_c()) return;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  p00_L_379B();
  lab_p05_L_4240: ;
  p05_L_42D4();
  if (flag_nz()) return;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  a = 0x0C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p05_L_4255;
  a = 0x4B;
  p00_L_3C45();
  lab_p05_L_4255: ;
  mem_write8(0x844C, a);
  p05_L_46B6();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
  lab_p05_L_4260: ;
  flag_cmp(a, 0x27);
  if (flag_z()) { p05_L_4000(); return; }
  flag_cmp(a, 0x0E);
  if (flag_z()) goto lab_p05_L_426D;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p05_L_4278;
  lab_p05_L_426D: ;
  p00_L_191A();
  if (flag_nz()) goto lab_p05_L_41F0;
  a = 0x03;
  mem_write8(0x8444, a);
  lab_p05_L_4278: ;
  flag_cmp(a, 0x0F);
  if (flag_z()) goto lab_p05_L_4280;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p05_L_4294;
  lab_p05_L_4280: ;
  set_hl(mem_read16(0x96F6));
  set_de(mem_read16(0x96FA));
  set_de((uint16_t)(de() - 1));
  p00_L_192A();
  if (flag_nz()) goto lab_p05_L_4294;
  a = 0x05;
  mem_write8(0x8444, a);
  goto lab_p05_L_429D;
  lab_p05_L_4294: ;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p05_L_429D;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p05_L_4160;
  lab_p05_L_429D: ;
  p00_L_1916();
  if (flag_z()) return;
  set_hl(0x0615);
  p00_L_25A2();
  p05_L_40F7();
  if (flag_nz()) goto lab_p05_L_42B7;
  p00_L_25C8();
  p05_L_462B();
  p05_L_4692();
  goto lab_p05_L_42BD;
  lab_p05_L_42B7: ;
  p00_L_25C8();
  p05_L_46CD();
  lab_p05_L_42BD: ;
  p05_L_42E8();
  p05_L_443F();
  p05_L_42C3();
  return;
}

/* flash page 5 cpu 0x42C3 (offset 0x02C3) */
void p05_L_42C3(void) {
  set_hl(0x4337);
  mem_write16(0x858D, hl());
  set_hl(0x589B);
  mem_write16(0x8591, hl());
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  return;
}

/* flash page 5 cpu 0x42D4 (offset 0x02D4) */
void p05_L_42D4(void) {
  set_de(0x4153);
  set_hl(mem_read16(0x858D));
  p00_L_192A();
  return;
}

/* flash page 5 cpu 0x42DD (offset 0x02DD) */
void p05_L_42DD(void) {
  p05_L_42D4();
  if (flag_z()) return;
  set_de(0x4260);
  p00_L_192A();
  if (flag_z()) return;
  p05_L_42E8();
  return;
}

/* flash page 5 cpu 0x42E8 (offset 0x02E8) */
void p05_L_42E8(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  p05_L_42EE();
  return;
}

/* flash page 5 cpu 0x42EE (offset 0x02EE) */
void p05_L_42EE(void) {
  p05_L_42F9();
  p05_L_4721();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  return;
}

/* flash page 5 cpu 0x42F9 (offset 0x02F9) */
void p05_L_42F9(void) {
  a = mem_read8(0x970B);
  a = (uint8_t)(a - 1);
  /* sla a */
  b = a;
  /* sla a */
  a = (uint8_t)(a + b);
  a = (uint8_t)(a + 0x0A);
  p00_L_17CE();
  if (flag_z()) goto lab_p05_L_430C;
  a = (uint8_t)(a + 0x20);
  lab_p05_L_430C: ;
  mem_write8(0x86D8, a);
  a = mem_read8(0x970A);
  a = (uint8_t)(a - 1);
  /* sla a */
  b = a;
  /* sla a */
  /* sla a */
  /* sla a */
  /* sla a */
  a = (uint8_t)(a - b);
  a = (uint8_t)(a + 0x05);
  mem_write8(0x86D7, a);
  p05_L_6BB3();
  return;
}

/* flash page 5 cpu 0x4327 (offset 0x0327) */
void p05_L_4327(void) {
  a = mem_read8(0x9703);
  set_hl(0x96FD);
  cpu_cp_hl();
  return;
}

/* flash page 5 cpu 0x432F (offset 0x032F) */
void p05_L_432F(void) {
  a = mem_read8(0x96FD);
  set_hl(0x9703);
  cpu_cp_hl();
  return;
}

/* flash page 5 cpu 0x435D (offset 0x035D) */
void p05_L_435D(void) {
  goto lab_p05_L_435D;
  lab_p05_L_4199: ;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  a = 0;
  flag_logic(a);
  mem_write8(0x844B, a);
  set_hl(0x4260);
  mem_write16(0x858D, hl());
  set_hl(0x40C6);
  mem_write16(0x8595, hl());
  set_hl(0x4702);
  mem_write16(0x8591, hl());
  p05_L_40AD();
  p00_L_3CC9();
  return;
  lab_p05_L_41BA: ;
  p00_L_3D17();
  p05_L_4567();
  p00_L_03A0();
  goto lab_p05_L_4199;
  lab_p05_L_435D: ;
  a = mem_read8(0x96FD);
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p05_L_41BA;
  p05_L_4423();
  set_hl(0x96FD);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  goto lab_p05_L_43C7;
  lab_p05_L_43C7: ;
  set_hl(0x970B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p05_L_43D3(); return; }
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_4562();
  p05_L_43D3();
  return;
}

/* flash page 5 cpu 0x43D3 (offset 0x03D3) */
void p05_L_43D3(void) {
  p05_L_42E8();
  p05_L_443F();
  return;
}

/* flash page 5 cpu 0x441E (offset 0x041E) */
void p05_L_441E(void) {
  set_hl(0x970A);
  goto lab_p05_L_4426;
  lab_p05_L_4426: ;
  a = mem_read8(hl());
  flag_cmp(a, 0x02);
  if (flag_nc()) p05_L_42EE();
  return;
}

/* flash page 5 cpu 0x4423 (offset 0x0423) */
void p05_L_4423(void) {
  set_hl(0x970B);
  a = mem_read8(hl());
  flag_cmp(a, 0x02);
  if (flag_nc()) p05_L_42EE();
  return;
}

/* flash page 5 cpu 0x442D (offset 0x042D) */
void p05_L_442D(void) {
  set_hl(0x970B);
  a = mem_read8(hl());
  flag_cmp(a, 0x07);
  goto lab_p05_L_443B;
  lab_p05_L_443B: ;
  if (flag_c()) p05_L_42EE();
  return;
}

/* flash page 5 cpu 0x4435 (offset 0x0435) */
void p05_L_4435(void) {
  set_hl(0x970A);
  a = mem_read8(hl());
  flag_cmp(a, 0x03);
  if (flag_c()) p05_L_42EE();
  return;
}

/* flash page 5 cpu 0x443F (offset 0x043F) */
void p05_L_443F(void) {
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  set_hl(0x0007);
  mem_write16(0x844B, hl());
  p05_L_460B();
  p05_L_478B();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 5 cpu 0x4454 (offset 0x0454) */
void p05_L_4454(void) {
  a = mem_read8(0x844C);
  mem_write8(0x97A7, a);
  p00_L_3759();
  mem_write16(0x9706, hl());
  p00_L_166E();
  p00_L_3261();
  set_hl(mem_read16(0x96F4));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96FA, hl());
  mem_write16(0x96F8, hl());
  return;
}

/* flash page 5 cpu 0x4472 (offset 0x0472) */
void p05_L_4472(void) {
  a = mem_read8(0x9702);
  goto lab_p05_L_447A;
  lab_p05_L_447A: ;
  l = a;
  h = 0x00;
  p00_L_3B55();
  p00_L_1179();
  a = 0x03;
  p00_L_3639();
  set_hl(0x848E);
  return;
}

/* flash page 5 cpu 0x4477 (offset 0x0477) */
void p05_L_4477(void) {
  a = mem_read8(0x9703);
  l = a;
  h = 0x00;
  p00_L_3B55();
  p00_L_1179();
  a = 0x03;
  p00_L_3639();
  set_hl(0x848E);
  return;
}

/* flash page 5 cpu 0x448C (offset 0x048C) */
void p05_L_448C(void) {
  p00_L_3255();
  set_hl(mem_read16(0x84D7));
  mem_write16(0x96FA, hl());
  mem_write16(0x96F8, hl());
  p05_L_58C6();
  p00_L_1847();
  p00_L_14D1();
  if (flag_nz()) { p00_L_24ED(); return; }
  p00_L_3B5B();
  a = 0;
  flag_logic(a);
  flag_cmp(a, d);
  if (flag_nz()) { p00_L_24ED(); return; }
  a = 0x63;
  flag_cmp(a, e);
  if (flag_c()) { p00_L_24ED(); return; }
  return;
}

/* flash page 5 cpu 0x44B3 (offset 0x04B3) */
void p05_L_44B3(void) {
  goto lab_p05_L_44B3;
  lab_p05_L_42BA: ;
  p05_L_46CD();
  p05_L_42E8();
  p05_L_443F();
  p05_L_42C3();
  return;
  lab_p05_L_4376: ;
  p05_L_442D();
  set_hl(0x96FD);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x970B);
  a = mem_read8(hl());
  flag_cmp(a, 0x07);
  goto lab_p05_L_43A3;
  lab_p05_L_4385: ;
  p05_L_42C3();
  goto lab_p05_L_4396;
  lab_p05_L_4396: ;
  p05_L_4435();
  set_hl(0x96FC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x970A);
  a = mem_read8(hl());
  flag_cmp(a, 0x03);
  lab_p05_L_43A3: ;
  if (flag_nc()) goto lab_p05_L_43A8;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p05_L_43AB;
  lab_p05_L_43A8: ;
  p05_L_4562();
  lab_p05_L_43AB: ;
  p05_L_43D3();
  return;
  lab_p05_L_44B3: ;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p05_L_4500;
  p00_L_1916();
  if (flag_nz()) goto lab_p05_L_44CC;
  p05_L_5687();
  p05_L_477B();
  if (flag_c()) goto lab_p05_L_44CF;
  p05_L_432F();
  if (flag_nc()) p05_L_478B();
  goto lab_p05_L_44CF;
  lab_p05_L_44CC: ;
  p05_L_4549();
  lab_p05_L_44CF: ;
  p05_L_477B();
  if (flag_c()) goto lab_p05_L_4385;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x42);
  if (flag_nz()) { p05_L_4524(); return; }
  p05_L_432F();
  if (flag_nc()) goto lab_p05_L_42BA;
  p05_L_42C3();
  a = 0x01;
  mem_write8(0x96FC, a);
  mem_write8(0x970A, a);
  set_hl(0x96FD);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x970B);
  a = mem_read8(hl());
  flag_cmp(a, 0x07);
  if (flag_nc()) goto lab_p05_L_44FA;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p05_L_44FA: ;
  p05_L_4562();
  p05_L_43D3();
  return;
  lab_p05_L_4500: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p05_L_4528;
  p00_L_1916();
  if (flag_nz()) goto lab_p05_L_4514;
  p05_L_5687();
  p05_L_432F();
  if (flag_nc()) p05_L_478B();
  goto lab_p05_L_4517;
  lab_p05_L_4514: ;
  p05_L_4549();
  lab_p05_L_4517: ;
  p05_L_42C3();
  p05_L_432F();
  if (flag_c()) goto lab_p05_L_4376;
  p05_L_42E8();
  return;
  lab_p05_L_4528: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p05_L_4535;
  p05_L_4549();
  p05_L_42C3();
  p05_L_435D();
  return;
  lab_p05_L_4535: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p05_L_453E;
  flag_cmp(a, 0x8A);
  if (flag_z()) return;
  lab_p05_L_453E: ;
  flag_cmp(a, 0x27);
  if (flag_nz()) { p00_L_3777(); return; }
  p05_L_57B8();
  p05_L_4003();
  return;
}

/* flash page 5 cpu 0x4524 (offset 0x0524) */
void p05_L_4524(void) {
  p05_L_47A3();
  return;
}

/* flash page 5 cpu 0x4549 (offset 0x0549) */
void p05_L_4549(void) {
  p00_L_1916();
  if (flag_nz()) goto lab_p05_L_4552;
  p05_L_5687();
  return;
  lab_p05_L_4552: ;
  set_hl(0x0615);
  p00_L_25A2();
  p05_L_47C2();
  p05_L_478B();
  p00_L_25C8();
  return;
}

/* flash page 5 cpu 0x4562 (offset 0x0562) */
void p05_L_4562(void) {
  p00_L_3D17();
  p05_L_456A();
  return;
}

/* flash page 5 cpu 0x4567 (offset 0x0567) */
void p05_L_4567(void) {
  p05_L_40A3();
  p05_L_456A();
  return;
}

/* flash page 5 cpu 0x456A (offset 0x056A) */
void p05_L_456A(void) {
  set_hl(mem_read16(0x970A));
  cpu_push_hl();
  set_hl(mem_read16(0x96FC));
  cpu_push_hl();
  h = (uint8_t)(h + 1);
  l = (uint8_t)(l + 1);
  set_de(mem_read16(0x970A));
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_de();
  mem_write16(0x96FC, hl());
  a = l;
  cpu_push_af();
  p05_L_46DD();
  lab_p05_L_4583: ;
  mem_write8(0x970B, a);
  a = 0x01;
  mem_write8(0x970A, a);
  cpu_pop_af();
  cpu_push_af();
  mem_write8(0x96FC, a);
  p05_L_42F9();
  a = 0;
  flag_logic(a);
  mem_write8(0x86D7, a);
  a = mem_read8(0x96FC);
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p05_L_45A2;
  a = 0xC1;
  goto lab_p05_L_45A4;
  lab_p05_L_45A2: ;
  a = 0x5F;
  lab_p05_L_45A4: ;
  p00_L_3D47();
  p05_L_42F9();
  p05_L_4758();
  p05_L_45F7();
  p05_L_45F7();
  a = 0x5C;
  mem_write8(0x86D7, a);
  p05_L_477B();
  if (flag_c()) goto lab_p05_L_45C1;
  a = 0x5D;
  goto lab_p05_L_45C3;
  lab_p05_L_45C1: ;
  a = 0xCE;
  lab_p05_L_45C3: ;
  p00_L_3D47();
  a = mem_read8(0x970B);
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p05_L_45D5;
  p05_L_45CD();
  return;
  lab_p05_L_45D5: ;
  a = mem_read8(0x96FD);
  set_hl(0x9703);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p05_L_45ED;
  a = (uint8_t)(a + 1);
  mem_write8(0x96FD, a);
  a = mem_read8(0x970B);
  a = (uint8_t)(a + 1);
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p05_L_4583;
  p05_L_47F6();
  lab_p05_L_45ED: ;
  cpu_pop_af();
  cpu_pop_hl();
  mem_write16(0x96FC, hl());
  cpu_pop_hl();
  mem_write16(0x970A, hl());
  return;
}

/* flash page 5 cpu 0x45CD (offset 0x05CD) */
void p05_L_45CD(void) {
  goto lab_p05_L_45CD;
  lab_p05_L_4583: ;
  mem_write8(0x970B, a);
  a = 0x01;
  mem_write8(0x970A, a);
  cpu_pop_af();
  cpu_push_af();
  mem_write8(0x96FC, a);
  p05_L_42F9();
  a = 0;
  flag_logic(a);
  mem_write8(0x86D7, a);
  a = mem_read8(0x96FC);
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p05_L_45A2;
  a = 0xC1;
  goto lab_p05_L_45A4;
  lab_p05_L_45A2: ;
  a = 0x5F;
  lab_p05_L_45A4: ;
  p00_L_3D47();
  p05_L_42F9();
  p05_L_4758();
  p05_L_45F7();
  p05_L_45F7();
  a = 0x5C;
  mem_write8(0x86D7, a);
  p05_L_477B();
  if (flag_c()) goto lab_p05_L_45C1;
  a = 0x5D;
  goto lab_p05_L_45C3;
  lab_p05_L_45C1: ;
  a = 0xCE;
  lab_p05_L_45C3: ;
  p00_L_3D47();
  a = mem_read8(0x970B);
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p05_L_45D5;
  lab_p05_L_45CD: ;
  a = mem_read8(0x96FD);
  flag_cmp(a, 0x02);
  if (flag_nc()) p05_L_47EA();
  lab_p05_L_45D5: ;
  a = mem_read8(0x96FD);
  set_hl(0x9703);
  cpu_cp_hl();
  if (flag_nc()) goto lab_p05_L_45ED;
  a = (uint8_t)(a + 1);
  mem_write8(0x96FD, a);
  a = mem_read8(0x970B);
  a = (uint8_t)(a + 1);
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p05_L_4583;
  p05_L_47F6();
  lab_p05_L_45ED: ;
  cpu_pop_af();
  cpu_pop_hl();
  mem_write16(0x96FC, hl());
  cpu_pop_hl();
  mem_write16(0x970A, hl());
  return;
}

/* flash page 5 cpu 0x45F7 (offset 0x05F7) */
void p05_L_45F7(void) {
  p05_L_4783();
  if (flag_z()) return;
  if (flag_c()) return;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = mem_read8(0x970A);
  a = (uint8_t)(a + 1);
  mem_write8(0x970A, a);
  p05_L_42F9();
  p05_L_4758();
  return;
}

/* flash page 5 cpu 0x460B (offset 0x060B) */
void p05_L_460B(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x844C, a);
  a = mem_read8(0x96FD);
  p05_L_4626();
  a = 0x2C;
  p00_L_3F9F();
  a = mem_read8(0x96FC);
  p05_L_4626();
  a = 0x3D;
  p00_L_3F9F();
  return;
}

/* flash page 5 cpu 0x4626 (offset 0x0626) */
void p05_L_4626(void) {
  b = 0x80;
  p05_L_554E();
  return;
}

/* flash page 5 cpu 0x462B (offset 0x062B) */
void p05_L_462B(void) {
  set_hl(0x2625);
  a = 0x32;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  a = 0;
  flag_logic(a);
  mem_write8(0x844B, a);
  mem_write8(0x844C, a);
  p00_L_3C87();
  p00_L_22FC();
  a = mem_read8(0x847A);
  a = (uint8_t)(a + 0x41);
  p00_L_3F9F();
  a = 0x5D;
  p00_L_3F9F();
  return;
}

/* flash page 5 cpu 0x4652 (offset 0x0652) */
void p05_L_4652(void) {
  cpu_push_af();
  a = 0x20;
  p00_L_3F9F();
  cpu_pop_af();
  p05_L_4060();
  p00_rst10();
  if (flag_nc()) goto lab_p05_L_4663;
  p00_L_3D1D();
  return;
  lab_p05_L_4663: ;
  p00_L_1F55();
  if (flag_z()) goto lab_p05_L_4674;
  set_hl(mem_read16(0x9702));
  cpu_push_hl();
  cpu_ex_de_hl();
  p00_L_3267();
  h = b;
  l = c;
  goto lab_p05_L_467C;
  lab_p05_L_4674: ;
  set_hl(mem_read16(0x9702));
  cpu_push_hl();
  cpu_ex_de_hl();
  p00_L_0033();
  lab_p05_L_467C: ;
  mem_write16(0x9702, hl());
  a = 0x06;
  mem_write8(0x844C, a);
  a = mem_read8(0x9703);
  p05_L_46C1();
  p05_L_46B6();
  cpu_pop_hl();
  mem_write16(0x9702, hl());
  return;
}

/* flash page 5 cpu 0x4692 (offset 0x0692) */
void p05_L_4692(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p05_L_469F;
  a = 0x4C;
  p00_L_3C45();
  p05_L_46B6();
  return;
  lab_p05_L_469F: ;
  a = 0x0A;
  mem_write8(0x844C, a);
  a = mem_read8(0x9703);
  p05_L_46C1();
  a = mem_read8(0x844C);
  flag_cmp(a, 0x0B);
  if (flag_nz()) { p05_L_46B6(); return; }
  a = 0x20;
  p00_L_3F9F();
  p05_L_46B6();
  return;
}

/* flash page 5 cpu 0x46B6 (offset 0x06B6) */
void p05_L_46B6(void) {
  a = 0x09;
  p00_L_3F9F();
  p00_L_3D1D();
  a = mem_read8(0x9702);
  p05_L_46C1();
  return;
}

/* flash page 5 cpu 0x46C1 (offset 0x06C1) */
void p05_L_46C1(void) {
  b = 0x30;
  p05_L_554E();
  return;
}

/* flash page 5 cpu 0x46C7 (offset 0x06C7) */
void p05_L_46C7(void) {
  set_hl(0x0101);
  mem_write16(0x970A, hl());
  p05_L_46CD();
  return;
}

/* flash page 5 cpu 0x46CD (offset 0x06CD) */
void p05_L_46CD(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x97A5, a);
  p00_L_3D17();
  p05_L_462B();
  p05_L_4692();
  p05_L_456A();
  p05_L_46DD();
  return;
}

/* flash page 5 cpu 0x46DD (offset 0x06DD) */
void p05_L_46DD(void) {
  a = 0x01;
  mem_write8(0x97A5, a);
  return;
}

/* flash page 5 cpu 0x46F6 (offset 0x06F6) */
void p05_L_46F6(void) {
  set_hl(0x8578);
  set_de(0x978F);
  set_bc(0x0010);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 5 cpu 0x4702 (offset 0x0702) */
void p05_L_4702(void) {
  set_hl(0x471C);
  p00_L_25A2();
  p00_L_1916();
  if (flag_nz()) p05_L_40F7();
  p05_L_5687();
  p00_L_25C8();
  p05_L_58A7();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 3)));
  return;
}

/* flash page 5 cpu 0x4721 (offset 0x0721) */
void p05_L_4721(void) {
  p05_L_4797();
  p05_L_475E();
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 1)));
  p05_L_67C8();
  return;
}

/* flash page 5 cpu 0x472F (offset 0x072F) */
void p05_L_472F(void) {
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  p05_L_475E();
  a = mem_read8(0x8478);
  a = (uint8_t)(a - 0x0C);
  if (flag_nz()) { p05_L_67C8(); return; }
  a = c;
  flag_cmp(a, 0x07);
  if (flag_c()) { p05_L_67C8(); return; }
  a = 0;
  flag_logic(a);
  mem_write8(0x97B6, a);
  p00_L_3D4D();
  a = 0xCE;
  p00_L_3D47();
  p05_L_6B86();
  return;
}

/* flash page 5 cpu 0x4758 (offset 0x0758) */
void p05_L_4758(void) {
  p05_L_4797();
  p05_L_67F0();
  return;
}

/* flash page 5 cpu 0x475E (offset 0x075E) */
void p05_L_475E(void) {
  a = 0x06;
  p05_L_4760();
  return;
}

/* flash page 5 cpu 0x4760 (offset 0x0760) */
void p05_L_4760(void) {
  set_hl(0x8478);
  b = a;
  a = mem_read8(0x8478);
  p00_L_1032();
  a = b;
  if (flag_z()) goto lab_p05_L_4774;
  p00_L_326D();
  set_hl(0x848E);
  return;
  lab_p05_L_4774: ;
  p00_L_3273();
  set_hl(0x97B1);
  return;
}

/* flash page 5 cpu 0x477B (offset 0x077B) */
void p05_L_477B(void) {
  a = mem_read8(0x96FC);
  set_hl(0x9702);
  cpu_cp_hl();
  return;
}

/* flash page 5 cpu 0x4783 (offset 0x0783) */
void p05_L_4783(void) {
  a = mem_read8(0x9702);
  set_hl(0x96FC);
  cpu_cp_hl();
  return;
}

/* flash page 5 cpu 0x478B (offset 0x078B) */
void p05_L_478B(void) {
  p05_L_563F();
  p05_L_4797();
  p05_L_5663();
  p05_L_55C2();
  return;
}

/* flash page 5 cpu 0x4797 (offset 0x0797) */
void p05_L_4797(void) {
  p00_L_22FC();
  p00_rst10();
  set_bc(mem_read16(0x96FC));
  p00_L_3B7F();
  return;
}

/* flash page 5 cpu 0x47A3 (offset 0x07A3) */
void p05_L_47A3(void) {
  p00_L_374D();
  p05_L_47B8();
  if (flag_z()) goto lab_p05_L_47AD;
  if (flag_c()) goto lab_p05_L_47B4;
  lab_p05_L_47AD: ;
  p05_L_4797();
  p00_L_3735();
  return;
  lab_p05_L_47B4: ;
  p00_L_3741();
  return;
}

/* flash page 5 cpu 0x47B8 (offset 0x07B8) */
void p05_L_47B8(void) {
  p05_L_4327();
  if (flag_nz()) return;
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(0x9702);
  cpu_cp_hl();
  return;
}

/* flash page 5 cpu 0x47C2 (offset 0x07C2) */
void p05_L_47C2(void) {
  p05_L_58C6();
  p00_L_1847();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p05_L_47DF;
  p05_L_58DC();
  set_hl(mem_read16(0x96FC));
  d = 0x00;
  e = h;
  b = d;
  c = l;
  p00_L_3285();
  p00_L_36DB();
  lab_p05_L_47DF: ;
  p05_L_47B8();
  if (flag_nc()) return;
  set_hl(mem_read16(0x96FC));
  mem_write16(0x9702, hl());
  return;
}

/* flash page 5 cpu 0x47CD (offset 0x07CD) */
void p05_L_47CD(void) {
  set_de(0xDCCD);
  e = b;
  set_hl(mem_read16(0x96FC));
  d = 0x00;
  e = h;
  b = d;
  c = l;
  p00_L_3285();
  p00_L_36DB();
  p05_L_47B8();
  if (flag_nc()) return;
  set_hl(mem_read16(0x96FC));
  mem_write16(0x9702, hl());
  return;
}

/* flash page 5 cpu 0x47EA (offset 0x07EA) */
void p05_L_47EA(void) {
  c = 0x1E;
  a = 0x5C;
  mem_write8(0x86D7, a);
  a = c;
  p00_L_3D47();
  return;
}

/* flash page 5 cpu 0x47F6 (offset 0x07F6) */
void p05_L_47F6(void) {
  goto lab_p05_L_47F6;
  lab_p05_L_47EC: ;
  a = 0x5C;
  mem_write8(0x86D7, a);
  a = c;
  p00_L_3D47();
  return;
  lab_p05_L_47F6: ;
  c = 0x1F;
  goto lab_p05_L_47EC;
}

/* flash page 5 cpu 0x47FA (offset 0x07FA) */
void p05_L_47FA(void) {
  p05_L_5868();
  p05_L_4802();
  return;
}

/* flash page 5 cpu 0x47FF (offset 0x07FF) */
void p05_L_47FF(void) {
  p05_L_5874();
  p05_L_4802();
  return;
}

/* flash page 5 cpu 0x4802 (offset 0x0802) */
void p05_L_4802(void) {
  p05_L_5AEE();
  set_hl(0x490C);
  p00_L_07C1();
  p00_L_176F();
  p05_L_4882();
  a = (uint8_t)(a - 1);
  mem_write8(0x97A5, a);
  a = mem_read8(0x970F);
  set_hl(0x9710);
  /* add a,(hl) */
  a = (uint8_t)(a + 1);
  mem_write8(0x96FC, a);
  set_hl(0x0001);
  mem_write16(0x96FE, hl());
  a = mem_read8(0x9710);
  a = (uint8_t)(a + 1);
  l = a;
  h = 0x01;
  mem_write16(0x970A, hl());
  p05_L_4861();
  a = mem_read8(0x89FA);
  mem_write8(0x89FB, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x9301, a);
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 4)));
  p05_L_488C();
  p05_L_56EA();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p05_L_4877;
  a = 0x03;
  p05_L_4DDF();
  a = 0x05;
  p05_L_4DDF();
  a = 0x05;
  set_hl(mem_read16(0x858D));
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 4)));
  os_jp_hl();
  return;
  lab_p05_L_4877: ;
  p05_L_5B62();
  return;
}

/* flash page 5 cpu 0x4861 (offset 0x0861) */
void p05_L_4861(void) {
  a = mem_read8(0x970E);
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p05_L_4872;
  a = mem_read8(0x9770);
  flag_cmp(a, 0x71);
  a = mem_read8(0x970E);
  if (flag_nz()) goto lab_p05_L_4873;
  lab_p05_L_4872: ;
  a = (uint8_t)(a - 1);
  lab_p05_L_4873: ;
  mem_write8(0x9702, a);
  return;
}

/* flash page 5 cpu 0x487A (offset 0x087A) */
void p05_L_487A(void) {
  goto lab_p05_L_487A;
  lab_p05_L_4877: ;
  p05_L_5B62();
  return;
  lab_p05_L_487A: ;
  set_hl(0x490C);
  p00_L_07CC();
  goto lab_p05_L_4877;
}

/* flash page 5 cpu 0x4882 (offset 0x0882) */
void p05_L_4882(void) {
  a = 0x01;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) return;
  a = (uint8_t)(a + 0x04);
  return;
}

/* flash page 5 cpu 0x488C (offset 0x088C) */
void p05_L_488C(void) {
  p00_L_3D17();
  p05_L_51D9();
  p05_L_4882();
  mem_write8(0x97A5, a);
  p05_L_5285();
  p05_L_54A7();
  p05_L_5221();
  if (flag_nz()) goto lab_p05_L_48B3;
  set_hl(0x0000);
  mem_write16(0x96FD, hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x970B, a);
  set_hl(0x4BF6);
  mem_write16(0x858D, hl());
  lab_p05_L_48B3: ;
  p05_L_5169();
  p05_L_48B6();
  return;
}

/* flash page 5 cpu 0x48B6 (offset 0x08B6) */
void p05_L_48B6(void) {
  p05_L_550D();
  p05_L_55B6();
  p05_L_48C0();
  return;
}

/* flash page 5 cpu 0x48C0 (offset 0x08C0) */
void p05_L_48C0(void) {
  a = mem_read8(0x96FC);
  flag_cmp(a, 0x0A);
  if (flag_nc()) goto lab_p05_L_48D3;
  b = 0x06;
  a = 0x57;
  p05_L_48F2();
  a = mem_read8(0x96FC);
  goto lab_p05_L_48ED;
  lab_p05_L_48D3: ;
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p05_L_48DB;
  a = 0x82;
  goto lab_p05_L_48DD;
  lab_p05_L_48DB: ;
  a = 0x81;
  lab_p05_L_48DD: ;
  b = a;
  a = 0x57;
  p05_L_48F2();
  a = mem_read8(0x96FC);
  a = (uint8_t)(a - 0x0A);
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p05_L_48ED;
  a = 0;
  flag_logic(a);
  lab_p05_L_48ED: ;
  a = (uint8_t)(a + 0x80);
  b = a;
  a = 0x5B;
  p05_L_48F2();
  return;
}

/* flash page 5 cpu 0x48F2 (offset 0x08F2) */
void p05_L_48F2(void) {
  mem_write8(0x86D7, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x86D8, a);
  p05_L_558A();
  return;
}

/* flash page 5 cpu 0x4932 (offset 0x0932) */
void p05_L_4932(void) {
  a = mem_read8(0x859A);
  flag_cmp(a, 0x55);
  return;
}

/* flash page 5 cpu 0x4938 (offset 0x0938) */
void p05_L_4938(void) {
  flag_cmp(a, 0x06);
  if (flag_z()) { p05_L_4941(); return; }
  flag_cmp(a, 0x05);
  p05_L_493E();
  return;
}

/* flash page 5 cpu 0x493E (offset 0x093E) */
void p05_L_493E(void) {
  if (flag_nz()) { p05_L_4B46(); return; }
  p05_L_4941();
  return;
}

/* flash page 5 cpu 0x4941 (offset 0x0941) */
void p05_L_4941(void) {
  p00_L_03A0();
  p00_L_3255();
  p05_L_5ADB();
  set_hl(mem_read16(0x96F6));
  set_de(mem_read16(0x96F8));
  p00_L_192A();
  if (flag_z()) goto lab_p05_L_495F;
  a = 0x00;
  lab_p05_L_4958: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  p00_L_192A();
  if (flag_nz()) goto lab_p05_L_4958;
  lab_p05_L_495F: ;
  set_hl(0x84C8);
  set_de(0x84CC);
  a = mem_read8(0x859A);
  flag_cmp(a, 0x56);
  if (flag_nz()) goto lab_p05_L_4978;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p05_L_4983;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p05_L_4983;
  lab_p05_L_4978: ;
  a = mem_read8(hl());
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p05_L_49E7;
  set_hl((uint16_t)(hl() + 1));
  p00_L_192A();
  if (flag_nz()) goto lab_p05_L_4978;
  lab_p05_L_4983: ;
  set_hl(0x84C7);
  set_de(0x8479);
  p00_L_1185();
  set_hl(mem_read16(0x96F6));
  set_de(0x84C7);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nz()) goto lab_p05_L_49A7;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x56);
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 6)) == 0);
  if (flag_z()) return;
  p00_L_1295();
  goto lab_p05_L_4A0B;
  lab_p05_L_49A7: ;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x56);
  if (flag_nz()) goto lab_p05_L_49BB;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p05_L_4A0F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1C)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p05_L_4A2F;
  lab_p05_L_49BB: ;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x31);
  if (flag_nz()) goto lab_p05_L_49CD;
  flag_set_z((mem_read8((uint16_t)(iy + 0x18)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p05_L_49E7;
  a = l;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p05_L_49EF;
  lab_p05_L_49CD: ;
  flag_cmp(a, 0x41);
  if (flag_c()) goto lab_p05_L_49E7;
  flag_cmp(a, 0x5C);
  if (flag_c()) goto lab_p05_L_49EF;
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p05_L_49E7;
  a = l;
  flag_cmp(a, 0x03);
  if (flag_nc()) goto lab_p05_L_49E7;
  a = mem_read8(0x847A);
  mem_write8(0x8479, a);
  l = (uint8_t)(l - 1);
  goto lab_p05_L_49EF;
  lab_p05_L_49E7: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 4)) == 0);
  if (flag_z()) { p00_L_24D5(); return; }
  return;
  lab_p05_L_49EF: ;
  a = 0x05;
  a = (uint8_t)(a - l);
  if (flag_z()) goto lab_p05_L_49FE;
  set_hl(0x847E);
  e = a;
  d = 0x00;
  cpu_sbc_hl_de();
  mem_write8(hl(), 0x00);
  lab_p05_L_49FE: ;
  b = 0x00;
  c = 0x05;
  p05_L_4932();
  if (flag_z()) goto lab_p05_L_4A48;
  flag_cmp(a, 0x56);
  if (flag_nz()) goto lab_p05_L_4A4C;
  lab_p05_L_4A0B: ;
  p00_L_3465();
  return;
  lab_p05_L_4A0F: ;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5C);
  if (flag_nz()) goto lab_p05_L_49E7;
  a = mem_read8(0x847A);
  flag_cmp(a, 0x0A);
  if (flag_nc()) goto lab_p05_L_49E7;
  set_hl(mem_read16(0x96F6));
  set_de(0x84C9);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nz()) goto lab_p05_L_49E7;
  a = 0x02;
  mem_write8(0x8478, a);
  goto lab_p05_L_4A0B;
  lab_p05_L_4A2F: ;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5E);
  if (flag_nz()) goto lab_p05_L_49E7;
  set_hl(mem_read16(0x96F6));
  set_de(0x84C9);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nz()) goto lab_p05_L_49E7;
  a = 0x03;
  mem_write8(0x8478, a);
  goto lab_p05_L_4A0B;
  lab_p05_L_4A48: ;
  p05_L_735E();
  return;
  lab_p05_L_4A4C: ;
  cpu_push_bc();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p05_L_4A62;
  set_de(0x847F);
  set_hl(0x847E);
  set_bc(0x0006);
  /* lddr */
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x5D);
  lab_p05_L_4A62: ;
  p00_L_241E();
  cpu_pop_bc();
  a = mem_read8(0x96FC);
  a = (uint8_t)(a - 1);
  p05_L_5199();
  cpu_ex_de_hl();
  set_hl(0x847A);
  while (bc() != 0) { cpu_ldi(); }
  p05_L_5463();
  if (flag_nz()) goto lab_p05_L_4A8C;
  mem_write8(0x9702, a);
  flag_cmp(a, 0x14);
  if (flag_z()) goto lab_p05_L_4A8C;
  a = mem_read8(0x96FC);
  p05_L_5199();
  mem_write8(hl(), 0x71);
  set_hl(0x970E);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p05_L_4A8C: ;
  b = 0x00;
  lab_p05_L_4A8E: ;
  b = (uint8_t)(b + 1);
  lab_p05_L_4A8F: ;
  a = mem_read8(0x96FC);
  flag_cmp(a, b);
  if (flag_z()) goto lab_p05_L_4A8E;
  cpu_push_bc();
  a = b;
  p05_L_5199();
  set_hl((uint16_t)(hl() - 1));
  set_de(0x847E);
  b = 0x05;
  p00_L_3E3D();
  cpu_push_bc();
  cpu_pop_de();
  cpu_pop_bc();
  a = 0x05;
  flag_cmp(a, e);
  if (flag_z()) goto lab_p05_L_4ABC;
  b = (uint8_t)(b + 1);
  a = mem_read8(0x970E);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p05_L_4A8F;
  p00_rst10();
  set_hl(0x0000);
  if (flag_c()) p00_L_1C46();
  p05_L_4B30();
  return;
  lab_p05_L_4ABC: ;
  p05_L_4AE3();
  p05_L_4B30();
  return;
}

/* flash page 5 cpu 0x4AC1 (offset 0x0AC1) */
void p05_L_4AC1(void) {
  p05_L_4861();
  b = 0x01;
  lab_p05_L_4AC6: ;
  cpu_push_bc();
  a = b;
  p05_L_5199();
  set_hl((uint16_t)(hl() - 1));
  set_de(0x847E);
  b = 0x05;
  p00_L_3E3D();
  cpu_push_bc();
  cpu_pop_de();
  cpu_pop_bc();
  a = 0x05;
  flag_cmp(a, e);
  if (flag_z()) { p05_L_4AE3(); return; }
  b = (uint8_t)(b + 1);
  a = mem_read8(0x970E);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p05_L_4AC6;
  p05_L_4AE3();
  return;
}

/* flash page 5 cpu 0x4AE3 (offset 0x0AE3) */
void p05_L_4AE3(void) {
  set_hl(0x96FC);
  a = b;
  cpu_cp_hl();
  if (flag_nc()) goto lab_p05_L_4B07;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  a = mem_read8(0x9710);
  a = a | 0x00;
  flag_logic(a);
  if (flag_nz()) goto lab_p05_L_4AFF;
  a = mem_read8(0x970F);
  a = a | 0x00;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_4B07;
  set_hl(0x970F);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  goto lab_p05_L_4B07;
  lab_p05_L_4AFF: ;
  set_hl(0x970A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  set_hl(0x9710);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  lab_p05_L_4B07: ;
  set_hl(mem_read16(0x96FC));
  cpu_push_hl();
  a = b;
  mem_write8(0x96FC, a);
  p05_L_4D70();
  cpu_pop_hl();
  mem_write16(0x96FC, hl());
  return;
}

/* flash page 5 cpu 0x4B17 (offset 0x0B17) */
void p05_L_4B17(void) {
  p05_L_5463();
  if (flag_z()) { p05_L_4B30(); return; }
  mem_write8(0x9702, a);
  flag_cmp(a, 0x14);
  if (flag_z()) { p05_L_4B30(); return; }
  a = mem_read8(0x96FC);
  a = (uint8_t)(a - 1);
  p05_L_5199();
  mem_write8(hl(), 0x71);
  set_hl(0x970E);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_4B30();
  return;
}

/* flash page 5 cpu 0x4B30 (offset 0x0B30) */
void p05_L_4B30(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p00_L_03A0();
  set_hl(0x4BF6);
  mem_write16(0x858D, hl());
  set_hl(0x5893);
  mem_write16(0x8591, hl());
  p05_L_4FF8();
  return;
}

/* flash page 5 cpu 0x4B32 (offset 0x0B32) */
void p05_L_4B32(void) {
  c = (uint8_t)(c + 1);
  a = a & 0xCD;
  flag_logic(a);
  a = a & b;
  flag_logic(a);
  set_bc((uint16_t)(bc() + 1));
  set_hl(0x4BF6);
  mem_write16(0x858D, hl());
  set_hl(0x5893);
  mem_write16(0x8591, hl());
  p05_L_4FF8();
  return;
}

/* flash page 5 cpu 0x4B46 (offset 0x0B46) */
void p05_L_4B46(void) {
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p05_L_4B8F;
  p05_L_4B4A();
  return;
  lab_p05_L_4B8F: ;
  flag_cmp(a, 0x08);
  if (flag_z()) { p05_L_4941(); return; }
  flag_cmp(a, 0x04);
  if (flag_z()) { p05_L_4941(); return; }
  flag_cmp(a, 0x07);
  if (flag_z()) goto lab_p05_L_4BA1;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p05_L_4BB6;
  lab_p05_L_4BA1: ;
  p05_L_4932();
  if (flag_z()) goto lab_p05_L_4BAA;
  flag_cmp(a, 0x56);
  if (flag_nz()) goto lab_p05_L_4BB5;
  lab_p05_L_4BAA: ;
  a = mem_read8(0x92C5);
  a = (uint8_t)(a | (1u << 2));
  mem_write8(0x92C5, a);
  p05_L_4941();
  return;
  lab_p05_L_4BB5: ;
  a = b;
  lab_p05_L_4BB6: ;
  flag_cmp(a, 0x27);
  if (flag_z()) goto lab_p05_L_4D38;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p05_L_4BE3;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p05_L_4BDF;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p05_L_4BDF;
  flag_cmp(a, 0x0A);
  if (flag_c()) goto lab_p05_L_4BD1;
  flag_cmp(a, 0x10);
  if (flag_c()) goto lab_p05_L_4BDF;
  lab_p05_L_4BD1: ;
  flag_cmp(a, 0x56);
  if (flag_z()) goto lab_p05_L_4BE3;
  p00_L_1916();
  if (flag_z()) goto lab_p05_L_4BDF;
  cpu_push_af();
  p05_L_4B4A();
  cpu_pop_af();
  lab_p05_L_4BDF: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 6)));
  lab_p05_L_4BE3: ;
  p00_L_31B9();
  return;
  lab_p05_L_4D38: ;
  p05_L_47FA();
  p05_L_5221();
  if (flag_nz()) return;
  p05_L_4D56();
  return;
}

/* flash page 5 cpu 0x4B4A (offset 0x0B4A) */
void p05_L_4B4A(void) {
  goto lab_p05_L_4B4A;
  lab_p05_L_4B37: ;
  set_hl(0x4BF6);
  mem_write16(0x858D, hl());
  set_hl(0x5893);
  mem_write16(0x8591, hl());
  p05_L_4FF8();
  return;
  lab_p05_L_4B4A: ;
  p00_L_31B3();
  set_hl(mem_read16(0x96FA));
  set_de(mem_read16(0x96F8));
  p00_L_192A();
  if (flag_z()) goto lab_p05_L_4B6A;
  p00_L_3D1D();
  p00_L_36B7();
  set_hl(0x84C7);
  p00_L_12A2();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  return;
  lab_p05_L_4B6A: ;
  p05_L_4932();
  if (flag_z()) return;
  flag_cmp(a, 0x56);
  if (flag_z()) return;
  p05_L_5463();
  if (flag_z()) p05_L_4D56();
  if (flag_z()) goto lab_p05_L_4B37;
  set_hl(0x4BF6);
  mem_write16(0x858D, hl());
  set_hl(0x5893);
  mem_write16(0x8591, hl());
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  p00_L_03A0();
  p05_L_4CB9();
  return;
}

/* flash page 5 cpu 0x4C04 (offset 0x0C04) */
void p05_L_4C04(void) {
  p05_L_54BB();
  p00_L_3D1D();
  p05_L_551B();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  set_hl(0x4938);
  mem_write16(0x858D, hl());
  set_hl(0x5868);
  mem_write16(0x8591, hl());
  set_hl(0x4BE6);
  mem_write16(0x8595, hl());
  p00_L_3417();
  set_hl(0x84CC);
  mem_write16(0x96FA, hl());
  mem_write16(0x96F8, hl());
  return;
}

/* flash page 5 cpu 0x4C32 (offset 0x0C32) */
void p05_L_4C32(void) {
  if (flag_z()) goto lab_p05_L_4C38;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p05_L_4C62;
  lab_p05_L_4C38: ;
  p00_L_31BF();
  a = mem_read8(0x96FC);
  flag_cmp(a, 0x14);
  if (flag_z()) goto lab_p05_L_4C47;
  p05_L_5221();
  if (flag_nz()) goto lab_p05_L_4C52;
  lab_p05_L_4C47: ;
  a = 0x01;
  mem_write8(0x96FC, a);
  mem_write8(0x970A, a);
  p05_L_4FF5();
  return;
  lab_p05_L_4C52: ;
  a = mem_read8(0x96FC);
  set_hl(0x9702);
  cpu_cp_hl();
  if (flag_nz()) goto lab_p05_L_4F76;
  p00_L_03B8();
  p05_L_4F79();
  return;
  lab_p05_L_4C62: ;
  flag_cmp(a, 0x0E);
  if (flag_z()) goto lab_p05_L_4C6A;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p05_L_4C8B;
  lab_p05_L_4C6A: ;
  p00_L_31BF();
  a = mem_read8(0x96FC);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p05_L_4FCC;
  a = mem_read8(0x9702);
  a = (uint8_t)(a - 0x03);
  if (flag_c()) { p05_L_48C0(); return; }
  if (flag_c()) return;
  a = (uint8_t)(a + 0x03);
  mem_write8(0x96FC, a);
  a = 0x03;
  mem_write8(0x970A, a);
  p05_L_4FF5();
  return;
  lab_p05_L_4C8B: ;
  flag_cmp(a, 0x08);
  if (flag_z()) { p05_L_4C98(); return; }
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p05_L_4CA9;
  lab_p05_L_4C93: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  p05_L_4C98();
  return;
  lab_p05_L_4CA9: ;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p05_L_4C93;
  flag_cmp(a, 0x07);
  if (flag_z()) return;
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p05_L_4CC5;
  p05_L_5221();
  if (flag_z()) return;
  p05_L_4CB9();
  return;
  lab_p05_L_4CC5: ;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p05_L_4D29;
  cpu_push_af();
  p05_L_5221();
  if (flag_z()) goto lab_p05_L_4D30;
  cpu_pop_af();
  p05_L_5468();
  if (flag_z()) return;
  a = mem_read8(0x970E);
  flag_cmp(a, 0x14);
  if (flag_z()) goto lab_p05_L_4CDC;
  a = (uint8_t)(a + 1);
  lab_p05_L_4CDC: ;
  set_hl(0x96FC);
  /* sub (hl) */
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_4CFB;
  set_hl(0x0000);
  p05_L_519C();
  a = l;
  b = 0x00;
  c = a;
  a = mem_read8(0x970E);
  flag_cmp(a, 0x14);
  if (flag_z()) goto lab_p05_L_4CF5;
  a = (uint8_t)(a + 1);
  lab_p05_L_4CF5: ;
  p05_L_5199();
  set_hl((uint16_t)(hl() - 1));
  goto lab_p05_L_4CFF;
  lab_p05_L_4CFB: ;
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  lab_p05_L_4CFF: ;
  cpu_push_hl();
  cpu_ex_de_hl();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  /* lddr */
  a = mem_read8(0x970E);
  flag_cmp(a, 0x14);
  if (flag_nz()) goto lab_p05_L_4D23;
  a = mem_read8(0x96FC);
  a = (uint8_t)(a - 1);
  p05_L_5199();
  mem_write8(hl(), 0x71);
  set_hl(0x9702);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_4B30();
  p05_L_4C04();
  return;
  lab_p05_L_4D23: ;
  p05_L_4B17();
  p05_L_4C04();
  return;
  lab_p05_L_4D29: ;
  cpu_push_af();
  p05_L_5221();
  if (flag_nz()) goto lab_p05_L_50C2;
  lab_p05_L_4D30: ;
  cpu_pop_af();
  flag_cmp(a, 0x09);
  if (flag_z()) return;
  flag_cmp(a, 0x27);
  if (flag_nz()) goto lab_p05_L_4D41;
  p05_L_47FA();
  p05_L_5221();
  if (flag_nz()) return;
  p05_L_4D56();
  return;
  lab_p05_L_4D41: ;
  cpu_push_af();
  p05_L_4C04();
  cpu_pop_af();
  flag_cmp(a, 0x43);
  if (flag_nz()) goto lab_p05_L_4D5E;
  set_hl(0x4BF6);
  mem_write16(0x858D, hl());
  set_hl(0x5893);
  mem_write16(0x8591, hl());
  p05_L_4D56();
  return;
  lab_p05_L_4D5E: ;
  flag_cmp(a, 0x9A);
  if (flag_c()) p00_L_03A0();
  flag_cmp(a, 0xB4);
  if (flag_c()) { p05_L_4B46(); return; }
  flag_cmp(a, 0xCC);
  if (flag_nz()) p00_L_03A0();
  p05_L_4B46();
  return;
  lab_p05_L_4F76: ;
  p00_L_31BF();
  p05_L_4F79();
  return;
  lab_p05_L_4FCC: ;
  a = mem_read8(0x96FC);
  flag_cmp(a, 0x02);
  if (flag_c()) return;
  p00_L_31BF();
  p05_L_50EB();
  set_hl(0x96FC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p05_L_4F98();
  set_hl(0x970A);
  cpu_push_af();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p05_L_500F();
  set_hl(0x970A);
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_4FF3;
  cpu_pop_af();
  if (flag_nc()) { p05_L_5008(); return; }
  p05_L_4FF5();
  return;
  lab_p05_L_4FF3: ;
  cpu_pop_af();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_4FF5();
  return;
  lab_p05_L_50C2: ;
  p05_L_552C();
  p00_L_241E();
  p00_L_1EF4();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_50D5;
  cpu_pop_af();
  flag_cmp(a, 0x27);
  if (flag_nz()) return;
  p05_L_47FF();
  return;
  lab_p05_L_50D5: ;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  a = 0x07;
  mem_write8(0x844B, a);
  p05_L_55AC();
  if (flag_z()) goto lab_p05_L_591E;
  p05_L_4E03();
  cpu_pop_af();
  p05_L_5116();
  return;
  lab_p05_L_591E: ;
  p05_L_58EE();
  cpu_pop_af();
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p05_L_592A;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p05_L_593D;
  lab_p05_L_592A: ;
  p05_L_5954();
  p05_L_487A();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 5)) == 0);
  if (flag_nz()) p05_L_488C();
  p05_L_56EA();
  p05_L_4EBC();
  return;
  lab_p05_L_593D: ;
  flag_cmp(a, 0x03);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p05_L_5949;
  flag_cmp(a, 0x8A);
  if (flag_z()) return;
  lab_p05_L_5949: ;
  flag_cmp(a, 0x27);
  if (flag_nz()) { p00_L_3777(); return; }
  p05_L_584C();
  p05_L_4802();
  return;
}

/* flash page 5 cpu 0x4C98 (offset 0x0C98) */
void p05_L_4C98(void) {
  b = a;
  p05_L_5221();
  if (flag_z()) { p05_L_4C04(); return; }
  a = b;
  set_hl(0x4DDF);
  mem_write16(0x858D, hl());
  p05_L_4DDF();
  return;
}

/* flash page 5 cpu 0x4CB9 (offset 0x0CB9) */
void p05_L_4CB9(void) {
  p05_L_4D70();
  p05_L_5221();
  if (flag_z()) p05_L_4D56();
  p05_L_4FF8();
  return;
}

/* flash page 5 cpu 0x4D56 (offset 0x0D56) */
void p05_L_4D56(void) {
  p00_L_03B8();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  return;
}

/* flash page 5 cpu 0x4D70 (offset 0x0D70) */
void p05_L_4D70(void) {
  a = mem_read8(0x970E);
  set_hl(0x96FC);
  /* sub (hl) */
  if (flag_c()) return;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_4DA0;
  set_hl(0x0000);
  p05_L_519C();
  a = l;
  b = 0x00;
  c = a;
  a = mem_read8(0x96FC);
  a = (uint8_t)(a - 1);
  p05_L_5199();
  cpu_ex_de_hl();
  a = mem_read8(0x96FC);
  p05_L_5199();
  while (bc() != 0) { cpu_ldi(); }
  a = mem_read8(0x9702);
  flag_cmp(a, 0x14);
  if (flag_z()) goto lab_p05_L_4DA0;
  set_hl(0x970E);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  lab_p05_L_4DA0: ;
  set_hl(0x9702);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  a = mem_read8(hl());
  p05_L_5199();
  mem_write8(hl(), 0x71);
  return;
}

/* flash page 5 cpu 0x4DAB (offset 0x0DAB) */
void p05_L_4DAB(void) {
  set_hl(0x5922);
  mem_write16(0x858D, hl());
  set_hl(0x584C);
  mem_write16(0x8591, hl());
  set_hl(0x37FB);
  mem_write16(0x8595, hl());
  cpu_push_af();
  p00_L_374D();
  cpu_pop_af();
  h = a;
  l = 0x3F;
  p00_L_1671();
  p00_rst10();
  a = 0x04;
  p00_L_31C5();
  p00_L_373B();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 4)) == 0);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 4)));
  return;
}

/* flash page 5 cpu 0x4DDF (offset 0x0DDF) */
void p05_L_4DDF(void) {
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p05_L_4E28;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  a = 0x07;
  mem_write8(0x844B, a);
  p05_L_55AC();
  if (flag_nz()) { p05_L_4E03(); return; }
  p05_L_552C();
  p00_L_241E();
  if (flag_c()) { p05_L_58EE(); return; }
  p00_L_1EF4();
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p05_L_58EE(); return; }
  p05_L_4DAB();
  return;
  lab_p05_L_4E28: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p05_L_4EAE;
  p05_L_4E2D();
  return;
  lab_p05_L_4EAE: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p05_L_4F11;
  p05_L_5470();
  if (flag_c()) goto lab_p05_L_4ED7;
  p05_L_4EB7();
  return;
  lab_p05_L_4ED4: ;
  p05_L_5008();
  return;
  lab_p05_L_4ED7: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  set_hl(mem_read16(0x96FE));
  set_de(0xFFF8);
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_4EEB;
  set_de(0xFFFD);
  lab_p05_L_4EEB: ;
  set_hl((uint16_t)(hl() + de()));
  if (flag_c()) goto lab_p05_L_4EFE;
  p05_L_516D();
  set_hl(0x0001);
  mem_write16(0x96FE, hl());
  a = 0x01;
  mem_write8(0x970B, a);
  goto lab_p05_L_4ED4;
  lab_p05_L_4EFE: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  set_hl(0x0001);
  mem_write16(0x96FE, hl());
  a = 0x01;
  mem_write8(0x970B, a);
  p05_L_4FF5();
  return;
  lab_p05_L_4F11: ;
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p05_L_4F39;
  p05_L_516D();
  b = 0x06;
  lab_p05_L_4F1A: ;
  set_hl(mem_read16(0x96FE));
  set_de(0x0001);
  p00_L_192A();
  if (flag_z()) goto lab_p05_L_4F36;
  set_hl(mem_read16(0x96FE));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x96FE, hl());
  cpu_push_bc();
  p05_L_55AC();
  if (flag_nz()) p05_L_4E97();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_4F1A;
  lab_p05_L_4F36: ;
  p05_L_5008();
  return;
  lab_p05_L_4F39: ;
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p05_L_4F6A;
  p05_L_516D();
  b = 0x06;
  lab_p05_L_4F42: ;
  p05_L_5470();
  if (flag_c()) { p05_L_5008(); return; }
  p05_L_5B14();
  if (flag_z()) { p05_L_5008(); return; }
  set_hl(mem_read16(0x96FE));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96FE, hl());
  p05_L_6896();
  if (flag_nc()) goto lab_p05_L_4F5D;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p05_L_4F65;
  lab_p05_L_4F5D: ;
  cpu_push_bc();
  p00_L_31D1();
  p05_L_53CE();
  cpu_pop_bc();
  lab_p05_L_4F65: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_4F42;
  p05_L_5008();
  return;
  lab_p05_L_4F6A: ;
  flag_cmp(a, 0x0F);
  if (flag_z()) goto lab_p05_L_4F72;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p05_L_4FC4;
  lab_p05_L_4F72: ;
  p05_L_549F();
  if (flag_nc()) return;
  p00_L_31BF();
  p05_L_4F79();
  return;
  lab_p05_L_4FC4: ;
  flag_cmp(a, 0x0E);
  if (flag_z()) goto lab_p05_L_4FCC;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p05_L_5021;
  lab_p05_L_4FCC: ;
  a = mem_read8(0x96FC);
  flag_cmp(a, 0x02);
  if (flag_c()) return;
  p00_L_31BF();
  p05_L_50EB();
  set_hl(0x96FC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p05_L_4F98();
  set_hl(0x970A);
  cpu_push_af();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p05_L_500F();
  set_hl(0x970A);
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_4FF3;
  cpu_pop_af();
  if (flag_nc()) { p05_L_5008(); return; }
  p05_L_4FF5();
  return;
  lab_p05_L_4FF3: ;
  cpu_pop_af();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_4FF5();
  return;
  lab_p05_L_5021: ;
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p05_L_5059;
  p05_L_5A32();
  if (flag_nz()) return;
  p05_L_55AC();
  if (flag_z()) return;
  p05_L_5470();
  if (flag_c()) goto lab_p05_L_55A4;
  p05_L_552C();
  p00_L_241E();
  if (flag_c()) goto lab_p05_L_5056;
  p00_L_16FA();
  p00_L_17E9();
  p00_rst10();
  cpu_push_hl();
  p05_L_5636();
  cpu_pop_hl();
  if (flag_z()) goto lab_p05_L_5056;
  set_bc(mem_read16(0x96FE));
  set_hl(0x0001);
  a = mem_read8(0x8478);
  p00_L_31D7();
  lab_p05_L_5056: ;
  p05_L_4FF5();
  return;
  lab_p05_L_5059: ;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p05_L_50AB;
  p05_L_5A32();
  if (flag_nz()) return;
  p05_L_55AC();
  if (flag_z()) return;
  set_hl(mem_read16(0x9704));
  p05_L_5B17();
  if (flag_nc()) return;
  set_hl(0x0615);
  p00_L_25A2();
  p05_L_552C();
  p00_L_241E();
  if (flag_nc()) goto lab_p05_L_5088;
  set_hl(0x0001);
  p00_L_1C46();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p00_L_101A();
  goto lab_p05_L_5097;
  lab_p05_L_5088: ;
  p00_L_16FA();
  set_bc(mem_read16(0x96FE));
  set_bc((uint16_t)(bc() - 1));
  set_hl(0x0001);
  a = a | a;
  flag_logic(a);
  p00_L_31DD();
  lab_p05_L_5097: ;
  p05_L_552C();
  p00_L_241E();
  if (flag_c()) goto lab_p05_L_50A5;
  p00_L_16FA();
  p00_L_17E9();
  lab_p05_L_50A5: ;
  p00_L_25C8();
  p05_L_4FF5();
  return;
  lab_p05_L_50AB: ;
  flag_cmp(a, 0x0C);
  if (flag_z()) return;
  flag_cmp(a, 0x8A);
  if (flag_z()) return;
  flag_cmp(a, 0x27);
  if (flag_z()) { p05_L_47FF(); return; }
  flag_cmp(a, 0x09);
  if (flag_z()) goto lab_p05_L_50C1;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p05_L_50C1;
  flag_cmp(a, 0x5A);
  if (flag_c()) return;
  lab_p05_L_50C1: ;
  cpu_push_af();
  p05_L_552C();
  p00_L_241E();
  p00_L_1EF4();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_50D5;
  cpu_pop_af();
  flag_cmp(a, 0x27);
  if (flag_nz()) return;
  p05_L_47FF();
  return;
  lab_p05_L_50D5: ;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  a = 0x07;
  mem_write8(0x844B, a);
  p05_L_55AC();
  if (flag_z()) goto lab_p05_L_591E;
  p05_L_4E03();
  cpu_pop_af();
  p05_L_5116();
  return;
  lab_p05_L_55A4: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  p00_L_378F();
  return;
  lab_p05_L_591E: ;
  p05_L_58EE();
  cpu_pop_af();
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p05_L_592A;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p05_L_593D;
  lab_p05_L_592A: ;
  p05_L_5954();
  p05_L_487A();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 5)) == 0);
  if (flag_nz()) p05_L_488C();
  p05_L_56EA();
  p05_L_4EBC();
  return;
  lab_p05_L_593D: ;
  flag_cmp(a, 0x03);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p05_L_5949;
  flag_cmp(a, 0x8A);
  if (flag_z()) return;
  lab_p05_L_5949: ;
  flag_cmp(a, 0x27);
  if (flag_nz()) { p00_L_3777(); return; }
  p05_L_584C();
  p05_L_4802();
  return;
}

/* flash page 5 cpu 0x4E03 (offset 0x0E03) */
void p05_L_4E03(void) {
  set_hl(0x5116);
  mem_write16(0x858D, hl());
  set_hl(0x5874);
  mem_write16(0x8591, hl());
  set_hl(0x37FB);
  mem_write16(0x8595, hl());
  p00_L_374D();
  p05_L_5470();
  if (flag_c()) goto lab_p05_L_4E24;
  p05_L_5649();
  p00_L_3735();
  return;
  lab_p05_L_4E24: ;
  p00_L_3741();
  return;
}

/* flash page 5 cpu 0x4E2D (offset 0x0E2D) */
void p05_L_4E2D(void) {
  p05_L_55AC();
  if (flag_z()) goto lab_p05_L_4E54;
  p05_L_516D();
  p05_L_4E35();
  return;
  lab_p05_L_4E51: ;
  p05_L_5008();
  return;
  lab_p05_L_4E54: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  set_hl(mem_read16(0x9704));
  set_de(0xFFF9);
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_4E68;
  set_de(0xFFFE);
  lab_p05_L_4E68: ;
  set_hl((uint16_t)(hl() + de()));
  if (flag_c()) goto lab_p05_L_4E7B;
  p05_L_516D();
  set_hl(mem_read16(0x9704));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96FE, hl());
  a = l;
  mem_write8(0x970B, a);
  goto lab_p05_L_4E51;
  lab_p05_L_4E7B: ;
  set_hl(mem_read16(0x9704));
  p05_L_5B17();
  if (flag_nc()) goto lab_p05_L_4E84;
  set_hl((uint16_t)(hl() + 1));
  lab_p05_L_4E84: ;
  mem_write16(0x96FE, hl());
  a = 0x07;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_4E91;
  a = 0x02;
  lab_p05_L_4E91: ;
  mem_write8(0x970B, a);
  p05_L_4FF5();
  return;
}

/* flash page 5 cpu 0x4E35 (offset 0x0E35) */
void p05_L_4E35(void) {
  set_hl(mem_read16(0x96FE));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x96FE, hl());
  p05_L_55AC();
  if (flag_nz()) goto lab_p05_L_4E4E;
  set_hl(0x970B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  set_hl(0x4BF6);
  mem_write16(0x858D, hl());
  p05_L_5008();
  return;
  lab_p05_L_4E4E: ;
  p05_L_4E97();
  p05_L_5008();
  return;
}

/* flash page 5 cpu 0x4E97 (offset 0x0E97) */
void p05_L_4E97(void) {
  set_hl(0x970B);
  a = 0;
  flag_logic(a);
  cpu_push_af();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_4EA5;
  cpu_pop_af();
  if (flag_nc()) return;
  goto lab_p05_L_4EA6;
  lab_p05_L_4EA5: ;
  cpu_pop_af();
  lab_p05_L_4EA6: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_L_31CB();
  p05_L_53CE();
  return;
}

/* flash page 5 cpu 0x4EB7 (offset 0x0EB7) */
void p05_L_4EB7(void) {
  p05_L_5B14();
  if (flag_nc()) goto lab_p05_L_4EFE;
  p05_L_4EBC();
  return;
  lab_p05_L_4EFE: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 0)) == 0);
  if (flag_nz()) return;
  set_hl(0x0001);
  mem_write16(0x96FE, hl());
  a = 0x01;
  mem_write8(0x970B, a);
  p05_L_4FF5();
  return;
}

/* flash page 5 cpu 0x4EBC (offset 0x0EBC) */
void p05_L_4EBC(void) {
  p05_L_516D();
  set_hl(mem_read16(0x96FE));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96FE, hl());
  p05_L_6896();
  if (flag_nc()) goto lab_p05_L_4ECE;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p05_L_4ED4;
  lab_p05_L_4ECE: ;
  p00_L_31D1();
  p05_L_53CE();
  lab_p05_L_4ED4: ;
  p05_L_5008();
  return;
}

/* flash page 5 cpu 0x4F79 (offset 0x0F79) */
void p05_L_4F79(void) {
  p05_L_50F5();
  set_hl(0x96FC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_4F98();
  cpu_push_af();
  set_hl(0x970A);
  a = mem_read8(hl());
  flag_cmp(a, 0x03);
  if (flag_c()) goto lab_p05_L_4F8F;
  cpu_pop_af();
  p05_L_4FF5();
  return;
  lab_p05_L_4F8F: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_500F();
  cpu_pop_af();
  if (flag_c()) { p05_L_4FF5(); return; }
  p05_L_5008();
  return;
}

/* flash page 5 cpu 0x4F98 (offset 0x0F98) */
void p05_L_4F98(void) {
  p05_L_54A7();
  p05_L_5488();
  if (flag_nc()) return;
  set_hl(mem_read16(0x9704));
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  set_hl(mem_read16(0x96FE));
  a = mem_read8(0x970B);
  e = a;
  d = 0x00;
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_ex_de_hl();
  cpu_pop_hl();
  mem_write16(0x96FE, hl());
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  a = l;
  if (flag_c()) goto lab_p05_L_4FBD;
  if (flag_nz()) goto lab_p05_L_4FC0;
  lab_p05_L_4FBD: ;
  a = 0x01;
  /* scf */
  lab_p05_L_4FC0: ;
  mem_write8(0x970B, a);
  return;
}

/* flash page 5 cpu 0x4FF5 (offset 0x0FF5) */
void p05_L_4FF5(void) {
  p05_L_500F();
  p05_L_4FF8();
  return;
}

/* flash page 5 cpu 0x4FF8 (offset 0x0FF8) */
void p05_L_4FF8(void) {
  goto lab_p05_L_4FF8;
  lab_p05_L_484D: ;
  a = 0x03;
  p05_L_4DDF();
  a = 0x05;
  p05_L_4DDF();
  a = 0x05;
  set_hl(mem_read16(0x858D));
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 4)));
  os_jp_hl();
  return;
  lab_p05_L_4FF8: ;
  p05_L_5AEE();
  p05_L_488C();
  p05_L_56EA();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p05_L_484D;
  p05_L_5008();
  return;
}

/* flash page 5 cpu 0x5008 (offset 0x1008) */
void p05_L_5008(void) {
  p05_L_5169();
  p05_L_48B6();
  return;
}

/* flash page 5 cpu 0x500F (offset 0x100F) */
void p05_L_500F(void) {
  a = mem_read8(0x970A);
  a = (uint8_t)(a - 1);
  mem_write8(0x9710, a);
  a = mem_read8(0x96FC);
  set_hl(0x970A);
  /* sub (hl) */
  mem_write8(0x970F, a);
  return;
}

/* flash page 5 cpu 0x50EB (offset 0x10EB) */
void p05_L_50EB(void) {
  set_hl(0x970A);
  a = mem_read8(hl());
  flag_cmp(a, 0x02);
  if (flag_nc()) p05_L_516D();
  return;
}

/* flash page 5 cpu 0x50F5 (offset 0x10F5) */
void p05_L_50F5(void) {
  set_hl(0x970A);
  a = mem_read8(hl());
  flag_cmp(a, 0x03);
  if (flag_c()) p05_L_516D();
  return;
}

/* flash page 5 cpu 0x50FF (offset 0x10FF) */
void p05_L_50FF(void) {
  p05_L_552C();
  p00_L_241E();
  cpu_push_af();
  p05_L_5691();
  p05_L_552C();
  p00_rst10();
  cpu_pop_af();
  set_hl(0x8478);
  cpu_cp_hl();
  if (flag_nz()) p05_L_488C();
  return;
}

/* flash page 5 cpu 0x5116 (offset 0x1116) */
void p05_L_5116(void) {
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p05_L_511E;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p05_L_5141;
  lab_p05_L_511E: ;
  p00_L_1916();
  if (flag_nz()) goto lab_p05_L_512E;
  p05_L_5687();
  p05_L_5B14();
  if (flag_z()) p05_L_55B6();
  goto lab_p05_L_5131;
  lab_p05_L_512E: ;
  p05_L_50FF();
  lab_p05_L_5131: ;
  p05_L_487A();
  p05_L_5B14();
  if (flag_z()) { p05_L_5169(); return; }
  p05_L_5470();
  if (flag_c()) return;
  p05_L_4EB7();
  return;
  lab_p05_L_5141: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p05_L_5158;
  p00_L_1916();
  if (flag_nz()) goto lab_p05_L_514F;
  p05_L_5687();
  goto lab_p05_L_5152;
  lab_p05_L_514F: ;
  p05_L_50FF();
  lab_p05_L_5152: ;
  p05_L_487A();
  p05_L_4E2D();
  return;
  lab_p05_L_5158: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p05_L_5161;
  flag_cmp(a, 0x8A);
  if (flag_z()) return;
  lab_p05_L_5161: ;
  flag_cmp(a, 0x27);
  if (flag_nz()) { p00_L_3777(); return; }
  p05_L_47FF();
  return;
}

/* flash page 5 cpu 0x5169 (offset 0x1169) */
void p05_L_5169(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  p05_L_516D();
  return;
}

/* flash page 5 cpu 0x516D (offset 0x116D) */
void p05_L_516D(void) {
  p05_L_5470();
  if (flag_c()) goto lab_p05_L_5185;
  set_de(0x0000);
  set_hl(mem_read16(0x96FE));
  p00_L_192A();
  if (flag_z()) goto lab_p05_L_518A;
  p05_L_5427();
  lab_p05_L_5180: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  return;
  lab_p05_L_5185: ;
  p05_L_53C0();
  goto lab_p05_L_5180;
  lab_p05_L_518A: ;
  p05_L_51C7();
  a = mem_read8(0x9710);
  b = a;
  p00_L_31E3();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  return;
}

/* flash page 5 cpu 0x5199 (offset 0x1199) */
void p05_L_5199(void) {
  set_hl(0x9711);
  p05_L_519C();
  return;
}

/* flash page 5 cpu 0x519C (offset 0x119C) */
void p05_L_519C(void) {
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

/* flash page 5 cpu 0x51A7 (offset 0x11A7) */
void p05_L_51A7(void) {
  a = mem_read8(0x844B);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  mem_write8(0x86D8, a);
  return;
}

/* flash page 5 cpu 0x51B1 (offset 0x11B1) */
void p05_L_51B1(void) {
  a = 0x06;
  p00_L_3D47();
  a = mem_read8(0x86D7);
  a = (uint8_t)(a - 0x04);
  set_hl(0x844C);
  mem_write8(hl(), 0x01);
  lab_p05_L_51C0: ;
  a = (uint8_t)(a - 0x06);
  if (flag_z()) return;
  if (flag_c()) return;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  goto lab_p05_L_51C0;
}

/* flash page 5 cpu 0x51C7 (offset 0x11C7) */
void p05_L_51C7(void) {
  a = 0x01;
  h = a;
  a = 0;
  flag_logic(a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_51D3;
  a = 0x04;
  lab_p05_L_51D3: ;
  l = a;
  mem_write16(0x844B, hl());
  p05_L_51A7();
  return;
}

/* flash page 5 cpu 0x51D9 (offset 0x11D9) */
void p05_L_51D9(void) {
  set_hl(0x84C7);
  set_de(0x8483);
  p00_L_118B();
  set_hl(0x0000);
  a = 0;
  flag_logic(a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_51EE;
  a = 0x04;
  lab_p05_L_51EE: ;
  l = a;
  mem_write16(0x844B, hl());
  p00_L_3D1D();
  p05_L_51C7();
  b = 0x00;
  lab_p05_L_51FA: ;
  p00_L_31E3();
  b = (uint8_t)(b + 1);
  a = b;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p05_L_51FA;
  set_de(0x84C7);
  set_hl(0x8483);
  p00_L_118B();
  return;
}

/* flash page 5 cpu 0x520D (offset 0x120D) */
void p05_L_520D(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p05_L_5217;
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 0)));
  lab_p05_L_5217: ;
  a = 0x4C;
  p00_L_3D47();
  a = b;
  p00_L_3D47();
  return;
}

/* flash page 5 cpu 0x5221 (offset 0x1221) */
void p05_L_5221(void) {
  a = mem_read8(0x9710);
  p05_L_5224();
  return;
}

/* flash page 5 cpu 0x5224 (offset 0x1224) */
void p05_L_5224(void) {
  set_hl(0x970F);
  /* add a,(hl) */
  p05_L_5199();
  a = mem_read8(hl());
  flag_cmp(a, 0x71);
  return;
}

/* flash page 5 cpu 0x522F (offset 0x122F) */
void p05_L_522F(void) {
  p05_L_5A32();
  if (flag_z()) return;
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  set_hl(0x5250);
  p00_L_25A2();
  p05_L_552C();
  p00_rst10();
  p00_L_31E9();
  p00_L_31EF();
  p00_L_25C8();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x526B (offset 0x126B) */
void p05_L_526B(void) {
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 4)));
  set_hl(mem_read16(0x96FC));
  mem_write16(0x92FD, hl());
  set_hl(mem_read16(0x970A));
  a = l;
  mem_write8(0x9710, a);
  l = (uint8_t)(l + 1);
  h = 0x01;
  mem_write16(0x92FF, hl());
  p05_L_5A68();
  return;
}

/* flash page 5 cpu 0x5285 (offset 0x1285) */
void p05_L_5285(void) {
  p05_L_5A76();
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 4)));
  set_hl(mem_read16(0x9702));
  cpu_push_hl();
  set_hl(mem_read16(0x9704));
  cpu_push_hl();
  set_de(mem_read16(0x970A));
  cpu_push_de();
  set_hl(mem_read16(0x96FC));
  cpu_push_hl();
  set_hl(mem_read16(0x96FE));
  cpu_push_hl();
  set_hl((uint16_t)(hl() + 1));
  set_de(mem_read16(0x970B));
  d = 0x00;
  cpu_sbc_hl_de();
  mem_write16(0x96FE, hl());
  cpu_push_hl();
  a = mem_read8(0x96FC);
  a = (uint8_t)(a + 1);
  set_hl(0x970A);
  /* sub (hl) */
  cpu_push_af();
  mem_write8(0x96FC, a);
  a = 0;
  flag_logic(a);
  mem_write8(0x970A, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p05_L_52DD;
  a = mem_read8(0x9301);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p05_L_52D0;
  p05_L_526B();
  goto lab_p05_L_52DD;
  lab_p05_L_52D0: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x27)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p05_L_52DD;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 5)));
  p05_L_522F();
  lab_p05_L_52DD: ;
  a = 0;
  flag_logic(a);
  p05_L_5224();
  cpu_push_af();
  if (flag_nz()) p05_L_538B();
  cpu_pop_af();
  if (flag_nz()) goto lab_p05_L_52ED;
  a = 0x01;
  mem_write8(0x970A, a);
  lab_p05_L_52ED: ;
  cpu_pop_af();
  cpu_pop_hl();
  cpu_push_hl();
  mem_write16(0x96FE, hl());
  a = (uint8_t)(a + 1);
  mem_write8(0x96FC, a);
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p05_L_5317;
  a = mem_read8(0x9301);
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p05_L_530A;
  p05_L_526B();
  goto lab_p05_L_5317;
  lab_p05_L_530A: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x27)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p05_L_5317;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 6)));
  p05_L_522F();
  lab_p05_L_5317: ;
  a = 0x01;
  p05_L_5224();
  cpu_push_af();
  if (flag_nz()) p05_L_5385();
  cpu_pop_af();
  if (flag_nz()) goto lab_p05_L_5327;
  set_hl(0x970A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p05_L_5327: ;
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  mem_write8(0x96FC, a);
  cpu_pop_hl();
  mem_write16(0x96FE, hl());
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p05_L_534F;
  a = mem_read8(0x9301);
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p05_L_5342;
  p05_L_526B();
  goto lab_p05_L_534F;
  lab_p05_L_5342: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x27)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p05_L_534F;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 7)));
  p05_L_522F();
  lab_p05_L_534F: ;
  a = 0x02;
  p05_L_5224();
  if (flag_nz()) p05_L_5385();
  p05_L_5357();
  return;
}

/* flash page 5 cpu 0x5357 (offset 0x1357) */
void p05_L_5357(void) {
  cpu_pop_hl();
  mem_write16(0x96FE, hl());
  cpu_pop_hl();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p05_L_5375;
  set_de(mem_read16(0x92FD));
  p00_L_192A();
  if (flag_z()) goto lab_p05_L_5375;
  cpu_ex_de_hl();
  mem_write16(0x96FC, hl());
  cpu_pop_hl();
  set_hl(mem_read16(0x92FF));
  goto lab_p05_L_5379;
  lab_p05_L_5375: ;
  mem_write16(0x96FC, hl());
  cpu_pop_hl();
  lab_p05_L_5379: ;
  mem_write16(0x970A, hl());
  cpu_pop_hl();
  mem_write16(0x9704, hl());
  cpu_pop_hl();
  mem_write16(0x9702, hl());
  return;
}

/* flash page 5 cpu 0x5385 (offset 0x1385) */
void p05_L_5385(void) {
  a = mem_read8(0x970A);
  a = (uint8_t)(a + 1);
  goto lab_p05_L_538D;
  lab_p05_L_538D: ;
  mem_write8(0x970A, a);
  a = 0x01;
  mem_write8(0x970B, a);
  p05_L_54A7();
  lab_p05_L_5398: ;
  p05_L_5470();
  if (flag_nc()) goto lab_p05_L_53AA;
  set_hl(mem_read16(0x9704));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x9704, hl());
  p05_L_5470();
  if (flag_z()) { p05_L_53C0(); return; }
  return;
  lab_p05_L_53AA: ;
  p05_L_5430();
  set_hl(0x970B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_6896();
  if (flag_z()) goto lab_p05_L_53B7;
  if (flag_nc()) return;
  lab_p05_L_53B7: ;
  set_hl(mem_read16(0x96FE));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96FE, hl());
  goto lab_p05_L_5398;
}

/* flash page 5 cpu 0x538B (offset 0x138B) */
void p05_L_538B(void) {
  a = 0x01;
  mem_write8(0x970A, a);
  a = 0x01;
  mem_write8(0x970B, a);
  p05_L_54A7();
  lab_p05_L_5398: ;
  p05_L_5470();
  if (flag_nc()) goto lab_p05_L_53AA;
  set_hl(mem_read16(0x9704));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x9704, hl());
  p05_L_5470();
  if (flag_z()) { p05_L_53C0(); return; }
  return;
  lab_p05_L_53AA: ;
  p05_L_5430();
  set_hl(0x970B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_6896();
  if (flag_z()) goto lab_p05_L_53B7;
  if (flag_nc()) return;
  lab_p05_L_53B7: ;
  set_hl(mem_read16(0x96FE));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96FE, hl());
  goto lab_p05_L_5398;
}

/* flash page 5 cpu 0x5397 (offset 0x1397) */
void p05_L_5397(void) {
  d = h;
  lab_p05_L_5398: ;
  p05_L_5470();
  if (flag_nc()) goto lab_p05_L_53AA;
  set_hl(mem_read16(0x9704));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x9704, hl());
  p05_L_5470();
  if (flag_z()) { p05_L_53C0(); return; }
  return;
  lab_p05_L_53AA: ;
  p05_L_5430();
  set_hl(0x970B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_6896();
  if (flag_z()) goto lab_p05_L_53B7;
  if (flag_nc()) return;
  lab_p05_L_53B7: ;
  set_hl(mem_read16(0x96FE));
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x96FE, hl());
  goto lab_p05_L_5398;
}

/* flash page 5 cpu 0x53C0 (offset 0x13C0) */
void p05_L_53C0(void) {
  p05_L_42F9();
  set_hl(0x2638);
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  p00_L_3D4D();
  return;
}

/* flash page 5 cpu 0x53C9 (offset 0x13C9) */
void p05_L_53C9(void) {
  /* adc a,(hl) */
  p00_L_3D4D();
  return;
}

/* flash page 5 cpu 0x53CE (offset 0x13CE) */
void p05_L_53CE(void) {
  set_hl(mem_read16(0x9702));
  cpu_push_hl();
  set_hl(mem_read16(0x9704));
  cpu_push_hl();
  set_de(mem_read16(0x970A));
  cpu_push_de();
  set_hl(mem_read16(0x96FC));
  cpu_push_hl();
  set_hl(mem_read16(0x96FE));
  cpu_push_hl();
  a = mem_read8(0x96FC);
  a = (uint8_t)(a + 1);
  a = (uint8_t)(a - e);
  cpu_push_af();
  mem_write8(0x96FC, a);
  p05_L_5409();
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  mem_write8(0x96FC, a);
  cpu_push_af();
  p05_L_5403();
  cpu_pop_af();
  a = (uint8_t)(a + 1);
  mem_write8(0x96FC, a);
  p05_L_5403();
  p05_L_5357();
  return;
}

/* flash page 5 cpu 0x5403 (offset 0x1403) */
void p05_L_5403(void) {
  a = mem_read8(0x970A);
  a = (uint8_t)(a + 1);
  goto lab_p05_L_540B;
  lab_p05_L_540B: ;
  mem_write8(0x970A, a);
  p05_L_54A7();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_de(mem_read16(0x96FE));
  p00_L_192A();
  if (flag_c()) return;
  if (flag_z()) goto lab_p05_L_5421;
  p05_L_516D();
  return;
  lab_p05_L_5421: ;
  p05_L_42F9();
  p05_L_6B86();
  return;
}

/* flash page 5 cpu 0x5409 (offset 0x1409) */
void p05_L_5409(void) {
  a = 0x01;
  mem_write8(0x970A, a);
  p05_L_54A7();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  set_de(mem_read16(0x96FE));
  p00_L_192A();
  if (flag_c()) return;
  if (flag_z()) goto lab_p05_L_5421;
  p05_L_516D();
  return;
  lab_p05_L_5421: ;
  p05_L_42F9();
  p05_L_6B86();
  return;
}

/* flash page 5 cpu 0x5427 (offset 0x1427) */
void p05_L_5427(void) {
  p05_L_42F9();
  p05_L_5649();
  p05_L_472F();
  return;
}

/* flash page 5 cpu 0x5430 (offset 0x1430) */
void p05_L_5430(void) {
  p05_L_42F9();
  p05_L_5649();
  p05_L_67F0();
  p05_L_6B86();
  return;
}

/* flash page 5 cpu 0x543C (offset 0x143C) */
void p05_L_543C(void) {
  b = 0x00;
  p05_L_543E();
  return;
}

/* flash page 5 cpu 0x543E (offset 0x143E) */
void p05_L_543E(void) {
  c = a;
  e = a;
  d = 0x5E;
  p00_L_3411();
  return;
}

/* flash page 5 cpu 0x5446 (offset 0x1446) */
void p05_L_5446(void) {
  p00_L_17CE();
  if (flag_z()) return;
  a = (uint8_t)(a - 0x20);
  return;
}

/* flash page 5 cpu 0x544D (offset 0x144D) */
void p05_L_544D(void) {
  c = 0x09;
  b = a;
  d = a;
  a = 0x3F;
  p05_L_5446();
  e = a;
  p00_L_3411();
  return;
}

/* flash page 5 cpu 0x5463 (offset 0x1463) */
void p05_L_5463(void) {
  goto lab_p05_L_5463;
  lab_p05_L_545E: ;
  set_hl(0x96FC);
  cpu_cp_hl();
  return;
  lab_p05_L_5463: ;
  a = mem_read8(0x970E);
  goto lab_p05_L_545E;
}

/* flash page 5 cpu 0x5468 (offset 0x1468) */
void p05_L_5468(void) {
  a = mem_read8(0x9702);
  set_hl(0x970E);
  cpu_cp_hl();
  return;
}

/* flash page 5 cpu 0x5470 (offset 0x1470) */
void p05_L_5470(void) {
  cpu_push_de();
  set_hl(mem_read16(0x9704));
  set_de(mem_read16(0x96FE));
  p00_L_192A();
  set_hl(mem_read16(0x96FC));
  cpu_pop_de();
  return;
}

/* flash page 5 cpu 0x5488 (offset 0x1488) */
void p05_L_5488(void) {
  goto lab_p05_L_5488;
  lab_p05_L_5474: ;
  set_de(mem_read16(0x96FE));
  p00_L_192A();
  set_hl(mem_read16(0x96FC));
  cpu_pop_de();
  return;
  lab_p05_L_5488: ;
  cpu_push_de();
  set_hl(mem_read16(0x9704));
  set_hl((uint16_t)(hl() + 1));
  goto lab_p05_L_5474;
}

/* flash page 5 cpu 0x548F (offset 0x148F) */
void p05_L_548F(void) {
  cpu_push_de();
  set_hl(mem_read16(0x96FE));
  set_de(mem_read16(0x9704));
  p00_L_192A();
  set_hl(mem_read16(0x9704));
  cpu_pop_de();
  return;
}

/* flash page 5 cpu 0x549F (offset 0x149F) */
void p05_L_549F(void) {
  a = mem_read8(0x96FC);
  set_hl(0x9702);
  cpu_cp_hl();
  return;
}

/* flash page 5 cpu 0x54A7 (offset 0x14A7) */
void p05_L_54A7(void) {
  p05_L_552C();
  p00_L_241E();
  set_hl(0x0000);
  if (flag_c()) goto lab_p05_L_54B7;
  h = d;
  l = e;
  p00_L_0033();
  lab_p05_L_54B7: ;
  mem_write16(0x9704, hl());
  return;
}

/* flash page 5 cpu 0x54BB (offset 0x14BB) */
void p05_L_54BB(void) {
  set_hl(0x0007);
  mem_write16(0x844B, hl());
  p05_L_51A7();
  a = 0x01;
  mem_write8(0x86D7, a);
  return;
}

/* flash page 5 cpu 0x54CA (offset 0x14CA) */
void p05_L_54CA(void) {
  p05_L_54BB();
  p05_L_5221();
  if (flag_z()) { p05_L_551B(); return; }
  flag_cmp(a, 0x06);
  if (flag_nc()) goto lab_p05_L_54E0;
  a = (uint8_t)(a + 0x81);
  cpu_push_bc();
  b = a;
  p05_L_520D();
  cpu_pop_bc();
  goto lab_p05_L_54F3;
  lab_p05_L_54E0: ;
  set_de(0x84C7);
  cpu_push_bc();
  set_bc(0x0005);
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_bc();
  set_de((uint16_t)(de() + 1));
  a = 0;
  flag_logic(a);
  mem_write8(de(), a);
  set_hl(0x84C7);
  p00_L_3D4D();
  lab_p05_L_54F3: ;
  p05_L_55AC();
  if (flag_z()) goto lab_p05_L_5508;
  a = 0x28;
  p00_L_3D47();
  set_hl(mem_read16(0x96FE));
  p05_L_5553();
  a = 0x29;
  p00_L_3D47();
  lab_p05_L_5508: ;
  p05_L_51B1();
  goto lab_p05_L_5548;
  lab_p05_L_5548: ;
  a = 0x3D;
  p00_L_3F9F();
  return;
}

/* flash page 5 cpu 0x550D (offset 0x150D) */
void p05_L_550D(void) {
  p05_L_54BB();
  p00_L_3D1D();
  p05_L_54CA();
  p00_L_3D1D();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x551B (offset 0x151B) */
void p05_L_551B(void) {
  goto lab_p05_L_551B;
  lab_p05_L_5519: ;
  a = a | a;
  flag_logic(a);
  return;
  lab_p05_L_551B: ;
  set_hl(0x262D);
  a = 0x10;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3C87();
  goto lab_p05_L_5519;
}

/* flash page 5 cpu 0x552C (offset 0x152C) */
void p05_L_552C(void) {
  a = mem_read8(0x96FC);
  a = (uint8_t)(a - 1);
  p05_L_5530();
  return;
}

/* flash page 5 cpu 0x5530 (offset 0x1530) */
void p05_L_5530(void) {
  p05_L_5199();
  p05_L_5533();
  return;
}

/* flash page 5 cpu 0x5533 (offset 0x1533) */
void p05_L_5533(void) {
  cpu_ex_de_hl();
  a = 0x5D;
  mem_write8(0x8479, a);
  set_hl(0x847A);
  cpu_ex_de_hl();
  b = 0x00;
  c = 0x05;
  while (bc() != 0) { cpu_ldi(); }
  a = 0;
  flag_logic(a);
  mem_write8(0x847F, a);
  return;
}

/* flash page 5 cpu 0x554E (offset 0x154E) */
void p05_L_554E(void) {
  l = a;
  h = 0x00;
  goto lab_p05_L_5555;
  lab_p05_L_5555: ;
  set_de(0x03E8);
  p00_L_192A();
  if (flag_c()) goto lab_p05_L_556F;
  p05_L_5581();
  set_de(0x0064);
  lab_p05_L_5563: ;
  p05_L_5581();
  set_de(0x000A);
  lab_p05_L_5569: ;
  p05_L_5581();
  lab_p05_L_556C: ;
  a = l;
  p05_L_558A();
  return;
  lab_p05_L_556F: ;
  set_de(0x0064);
  p00_L_192A();
  if (flag_nc()) goto lab_p05_L_5563;
  set_de(0x000A);
  p00_L_192A();
  if (flag_nc()) goto lab_p05_L_5569;
  goto lab_p05_L_556C;
}

/* flash page 5 cpu 0x5553 (offset 0x1553) */
void p05_L_5553(void) {
  b = 0x80;
  set_de(0x03E8);
  p00_L_192A();
  if (flag_c()) goto lab_p05_L_556F;
  p05_L_5581();
  set_de(0x0064);
  lab_p05_L_5563: ;
  p05_L_5581();
  set_de(0x000A);
  lab_p05_L_5569: ;
  p05_L_5581();
  lab_p05_L_556C: ;
  a = l;
  p05_L_558A();
  return;
  lab_p05_L_556F: ;
  set_de(0x0064);
  p00_L_192A();
  if (flag_nc()) goto lab_p05_L_5563;
  set_de(0x000A);
  p00_L_192A();
  if (flag_nc()) goto lab_p05_L_5569;
  goto lab_p05_L_556C;
}

/* flash page 5 cpu 0x5581 (offset 0x1581) */
void p05_L_5581(void) {
  a = 0;
  flag_logic(a);
  goto lab_p05_L_5585;
  lab_p05_L_5584: ;
  a = (uint8_t)(a + 1);
  lab_p05_L_5585: ;
  cpu_sbc_hl_de();
  if (flag_nc()) goto lab_p05_L_5584;
  set_hl((uint16_t)(hl() + de()));
  p05_L_558A();
  return;
}

/* flash page 5 cpu 0x558A (offset 0x158A) */
void p05_L_558A(void) {
  goto lab_p05_L_558A;
  lab_p05_L_554A: ;
  p00_L_3F9F();
  return;
  lab_p05_L_558A: ;
  a = (uint8_t)(a + b);
  e = a;
  p00_L_31FB();
  a = e;
  if (flag_z()) goto lab_p05_L_554A;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x43);
  a = e;
  if (flag_z()) goto lab_p05_L_55A0;
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p05_L_554A;
  lab_p05_L_55A0: ;
  p00_L_3D47();
  return;
}

/* flash page 5 cpu 0x55AC (offset 0x15AC) */
void p05_L_55AC(void) {
  a = mem_read8(0x96FF);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  a = mem_read8(0x96FE);
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x55B6 (offset 0x15B6) */
void p05_L_55B6(void) {
  p05_L_563F();
  p05_L_55AC();
  if (flag_z()) goto lab_p05_L_55CA;
  p05_L_565F();
  if (flag_c()) return;
  p05_L_55C2();
  return;
  lab_p05_L_55CA: ;
  p05_L_552C();
  p05_L_55CD();
  return;
}

/* flash page 5 cpu 0x55C2 (offset 0x15C2) */
void p05_L_55C2(void) {
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 1)));
  p00_L_3CB7();
  return;
}

/* flash page 5 cpu 0x55CD (offset 0x15CD) */
void p05_L_55CD(void) {
  p00_L_241E();
  if (flag_c()) return;
  p00_L_1EF4();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_55FB;
  h = a;
  l = 0x3F;
  p00_L_1671();
  p00_rst10();
  if (flag_c()) return;
  cpu_push_de();
  a = 0x22;
  p00_L_3F9F();
  cpu_pop_de();
  cpu_push_de();
  cpu_pop_hl();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + de()));
  cpu_pop_de();
  p00_L_3201();
  if (flag_nc()) return;
  a = 0x22;
  p00_L_3F9F();
  return;
  lab_p05_L_55FB: ;
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 1)));
  p05_L_5636();
  if (flag_z()) return;
  a = 0x7B;
  p00_L_3CAB();
  goto lab_p05_L_5611;
  lab_p05_L_560A: ;
  a = 0x2C;
  p00_L_3CAB();
  if (flag_c()) goto lab_p05_L_5635;
  lab_p05_L_5611: ;
  cpu_push_bc();
  p00_rst20();
  a = mem_read8(0x8478);
  p00_L_1032();
  if (flag_nz()) goto lab_p05_L_561E;
  p00_L_11F8();
  lab_p05_L_561E: ;
  cpu_push_hl();
  a = 0x14;
  p05_L_4760();
  p00_L_3CB1();
  cpu_pop_hl();
  cpu_pop_bc();
  if (flag_c()) goto lab_p05_L_5635;
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | b;
  flag_logic(a);
  if (flag_nz()) goto lab_p05_L_560A;
  a = 0x7D;
  p00_L_3CAB();
  lab_p05_L_5635: ;
  return;
}

/* flash page 5 cpu 0x5636 (offset 0x1636) */
void p05_L_5636(void) {
  h = d;
  l = e;
  c = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  b = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = b;
  a = a | c;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x563F (offset 0x163F) */
void p05_L_563F(void) {
  p00_L_37AD();
  p00_L_37A7();
  p00_L_3CC9();
  return;
}

/* flash page 5 cpu 0x5649 (offset 0x1649) */
void p05_L_5649(void) {
  p05_L_54A7();
  p05_L_5470();
  if (flag_c()) return;
  p05_L_552C();
  p00_L_241E();
  if (flag_c()) return;
  set_hl(mem_read16(0x96FE));
  p00_L_3AF5();
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x565F (offset 0x165F) */
void p05_L_565F(void) {
  p05_L_5649();
  if (flag_c()) return;
  p05_L_5663();
  return;
}

/* flash page 5 cpu 0x5663 (offset 0x1663) */
void p05_L_5663(void) {
  a = 0x14;
  p05_L_5665();
  return;
}

/* flash page 5 cpu 0x5665 (offset 0x1665) */
void p05_L_5665(void) {
  set_hl(0x8478);
  set_de(0x97F2);
  p00_L_1183();
  set_hl(0x8478);
  b = a;
  p00_L_1037();
  a = b;
  if (flag_nz()) goto lab_p05_L_567F;
  p00_L_3639();
  set_hl(0x848E);
  return;
  lab_p05_L_567F: ;
  p00_L_3273();
  set_hl(0x97B1);
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x5687 (offset 0x1687) */
void p05_L_5687(void) {
  p00_L_03A0();
  p00_L_36CF();
  p00_L_37CB();
  return;
}

/* flash page 5 cpu 0x5691 (offset 0x1691) */
void p05_L_5691(void) {
  p00_L_1916();
  if (flag_nz()) goto lab_p05_L_5699;
  sp = (uint16_t)(sp + 1);
  sp = (uint16_t)(sp + 1);
  return;
  lab_p05_L_5699: ;
  set_hl(0x0615);
  p00_L_25A2();
  p05_L_56A9();
  p05_L_55B6();
  p00_L_25C8();
  return;
}

/* flash page 5 cpu 0x56A9 (offset 0x16A9) */
void p05_L_56A9(void) {
  p05_L_575A();
  p05_L_58C6();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 5)) == 0);
  if (flag_z()) return;
  p00_L_2222();
  p05_L_552C();
  p00_L_1100();
  p00_L_2176();
  set_hl(0x001E);
  p00_L_23BD();
  p05_L_58DF();
  if (flag_nc()) p00_L_16F4();
  p05_L_578B();
  p05_L_552C();
  p00_L_241E();
  if (flag_c()) return;
  p00_L_17E9();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 3)) == 0);
  if (flag_z()) return;
  p05_L_5AEE();
  p05_L_56EA();
  p05_L_51D9();
  p05_L_5285();
  return;
}

/* flash page 5 cpu 0x56EA (offset 0x16EA) */
void p05_L_56EA(void) {
  set_hl(mem_read16(0x970A));
  cpu_push_hl();
  a = mem_read8(0x96FC);
  cpu_push_af();
  a = mem_read8(0x970F);
  a = (uint8_t)(a + 1);
  mem_write8(0x96FC, a);
  set_hl(0x0001);
  mem_write16(0x970A, hl());
  a = mem_read8(0x9301);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p05_L_5710;
  flag_set_z((mem_read8((uint16_t)(iy + 0x27)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p05_L_5715;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 5)));
  lab_p05_L_5710: ;
  p05_L_5A11();
  if (flag_c()) goto lab_p05_L_5715;
  lab_p05_L_5715: ;
  set_hl(0x96FC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x970A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = mem_read8(0x9301);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p05_L_572E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x27)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p05_L_5733;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 6)));
  lab_p05_L_572E: ;
  p05_L_5A11();
  if (flag_c()) goto lab_p05_L_5733;
  lab_p05_L_5733: ;
  set_hl(0x96FC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  set_hl(0x970A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = mem_read8(0x9301);
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p05_L_574C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x27)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p05_L_5751;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 7)));
  lab_p05_L_574C: ;
  p05_L_5A11();
  if (flag_c()) goto lab_p05_L_5751;
  lab_p05_L_5751: ;
  cpu_pop_af();
  mem_write8(0x96FC, a);
  cpu_pop_hl();
  mem_write16(0x970A, hl());
  return;
}

/* flash page 5 cpu 0x575A (offset 0x175A) */
void p05_L_575A(void) {
  a = mem_read8(0x96FC);
  cpu_push_af();
  a = mem_read8(0x970F);
  a = (uint8_t)(a + 1);
  mem_write8(0x96FC, a);
  p05_L_5A32();
  if (flag_nz()) goto lab_p05_L_5782;
  set_hl(0x96FC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_5A32();
  if (flag_nz()) goto lab_p05_L_5782;
  set_hl(0x96FC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_5A32();
  if (flag_nz()) goto lab_p05_L_5782;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 3)));
  goto lab_p05_L_5786;
  lab_p05_L_5782: ;
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 3)));
  lab_p05_L_5786: ;
  cpu_pop_af();
  mem_write8(0x96FC, a);
  return;
}

/* flash page 5 cpu 0x578B (offset 0x178B) */
void p05_L_578B(void) {
  set_bc(mem_read16(0x96FE));
  p00_L_3207();
  p00_L_36DB();
  p05_L_548F();
  if (flag_z()) return;
  if (flag_c()) return;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x9704, hl());
  return;
}

/* flash page 5 cpu 0x5797 (offset 0x1797) */
void p05_L_5797(void) {
  d = h;
  if (flag_z()) return;
  if (flag_c()) return;
  set_hl((uint16_t)(hl() + 1));
  mem_write16(0x9704, hl());
  return;
}

/* flash page 5 cpu 0x57A8 (offset 0x17A8) */
void p05_L_57A8(void) {
  p05_L_65A8();
  if (flag_z()) return;
  a = mem_read8(0x8479);
  h = a;
  a = mem_read8(0x847A);
  l = a;
  mem_write16(0x92AC, hl());
  return;
}

/* flash page 5 cpu 0x57B8 (offset 0x17B8) */
void p05_L_57B8(void) {
  set_hl(0x5847);
  p00_L_25A2();
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p05_L_58A1;
  p00_L_1916();
  if (flag_z()) goto lab_p05_L_58A1;
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p05_L_58A1;
  p05_L_47C2();
  p05_L_588E();
  return;
  lab_p05_L_58A1: ;
  p05_L_5687();
  p00_L_25C8();
  p05_L_58A7();
  return;
}

/* flash page 5 cpu 0x57D8 (offset 0x17D8) */
void p05_L_57D8(void) {
  p05_L_621C();
  set_hl(0x5839);
  p00_L_25A2();
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p05_L_5833;
  p00_L_1916();
  if (flag_z()) goto lab_p05_L_5833;
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p05_L_5833;
  p05_L_6B56();
  p05_L_5CF2();
  goto lab_p05_L_582B;
  lab_p05_L_582B: ;
  p00_L_37CB();
  p05_L_57A8();
  goto lab_p05_L_58A4;
  lab_p05_L_5833: ;
  p05_L_5687();
  p00_L_25C8();
  p00_L_37CB();
  set_hl(0x58A7);
  p00_L_25A2();
  p05_L_57A8();
  goto lab_p05_L_58A4;
  lab_p05_L_58A4: ;
  p00_L_25C8();
  p05_L_58A7();
  return;
}

/* flash page 5 cpu 0x57FC (offset 0x17FC) */
void p05_L_57FC(void) {
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 7)));
  p05_L_621C();
  set_hl(0x5839);
  p00_L_25A2();
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p05_L_5833;
  set_hl(mem_read16(0x9706));
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p05_L_5823;
  a = mem_read8(hl());
  a = a & 0xE0;
  flag_logic(a);
  cpu_ex_de_hl();
  set_hl(0x84D2);
  /* or (hl) */
  cpu_ex_de_hl();
  mem_write8(hl(), a);
  lab_p05_L_5823: ;
  p00_L_1916();
  if (flag_z()) goto lab_p05_L_5833;
  p05_L_6D9C();
  p00_L_37CB();
  p05_L_57A8();
  goto lab_p05_L_58A4;
  lab_p05_L_5833: ;
  p05_L_5687();
  p00_L_25C8();
  p00_L_37CB();
  set_hl(0x58A7);
  p00_L_25A2();
  p05_L_57A8();
  goto lab_p05_L_58A4;
  lab_p05_L_58A4: ;
  p00_L_25C8();
  p05_L_58A7();
  return;
}

/* flash page 5 cpu 0x584C (offset 0x184C) */
void p05_L_584C(void) {
  set_hl(0x5847);
  p00_L_25A2();
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p05_L_58A1;
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p05_L_58A1;
  p00_L_1916();
  if (flag_z()) goto lab_p05_L_58A1;
  p05_L_59B0();
  p05_L_588E();
  return;
  lab_p05_L_58A1: ;
  p05_L_5687();
  p00_L_25C8();
  p05_L_58A7();
  return;
}

/* flash page 5 cpu 0x5868 (offset 0x1868) */
void p05_L_5868(void) {
  p05_L_5463();
  if (flag_nz()) p05_L_4D70();
  set_hl(0x5874);
  mem_write16(0x8591, hl());
  p05_L_5874();
  return;
}

/* flash page 5 cpu 0x5874 (offset 0x1874) */
void p05_L_5874(void) {
  set_hl(0x5847);
  p00_L_25A2();
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p05_L_58A1;
  p00_L_1916();
  if (flag_z()) goto lab_p05_L_58A1;
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p05_L_58A1;
  p05_L_56A9();
  p05_L_588E();
  return;
  lab_p05_L_58A1: ;
  p05_L_5687();
  p00_L_25C8();
  p05_L_58A7();
  return;
}

/* flash page 5 cpu 0x588E (offset 0x188E) */
void p05_L_588E(void) {
  p00_L_37CB();
  goto lab_p05_L_58A4;
  lab_p05_L_58A4: ;
  p00_L_25C8();
  p05_L_58A7();
  return;
}

/* flash page 5 cpu 0x58A7 (offset 0x18A7) */
void p05_L_58A7(void) {
  p00_L_0740();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  p00_L_3E91();
  p00_L_36DB();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 3)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 3)) == 0);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 4)) == 0);
  if (flag_z()) return;
  p00_L_3E8B();
  return;
}

/* flash page 5 cpu 0x58C6 (offset 0x18C6) */
void p05_L_58C6(void) {
  p00_L_37C5();
  p00_L_166E();
  p00_L_002B();
  p00_L_36D5();
  p00_L_1717();
  p00_L_1032();
  if (flag_z()) return;
  p00_L_1653();
  return;
}

/* flash page 5 cpu 0x58DC (offset 0x18DC) */
void p05_L_58DC(void) {
  p00_L_22F2();
  p05_L_58DF();
  return;
}

/* flash page 5 cpu 0x58DF (offset 0x18DF) */
void p05_L_58DF(void) {
  p00_L_1037();
  cpu_push_af();
  p00_L_2222();
  p00_L_113F();
  cpu_pop_af();
  p00_L_241E();
  return;
}

/* flash page 5 cpu 0x58EE (offset 0x18EE) */
void p05_L_58EE(void) {
  set_hl(0x5922);
  mem_write16(0x858D, hl());
  set_hl(0x584C);
  mem_write16(0x8591, hl());
  set_hl(0x37FB);
  mem_write16(0x8595, hl());
  p00_L_374D();
  p05_L_552C();
  p00_L_241E();
  if (flag_c()) goto lab_p05_L_591A;
  cpu_push_hl();
  p05_L_5636();
  cpu_pop_hl();
  a = mem_read8(hl());
  if (flag_z()) goto lab_p05_L_591A;
  p00_L_31C5();
  p00_L_373B();
  return;
  lab_p05_L_591A: ;
  p00_L_3741();
  return;
}

/* flash page 5 cpu 0x5954 (offset 0x1954) */
void p05_L_5954(void) {
  p00_L_1916();
  if (flag_nz()) { p05_L_59A3(); return; }
  p05_L_5A32();
  if (flag_z()) goto lab_p05_L_5982;
  set_hl(mem_read16(0x96F6));
  mem_write16(0x86D9, hl());
  a = mem_read8(0x89FA);
  mem_write8(0x89FB, a);
  a = 0x2A;
  p00_L_3213();
  if (flag_c()) return;
  a = 0x2A;
  p00_L_3213();
  if (flag_c()) return;
  set_hl(mem_read16(0x86D9));
  mem_write16(0x96F6, hl());
  p05_L_59A3();
  p05_L_56EA();
  return;
  lab_p05_L_5982: ;
  p05_L_5687();
  p05_L_552C();
  p00_L_17E9();
  p00_L_241E();
  if (flag_c()) return;
  p00_L_1F58();
  set_hl(0x0000);
  p00_L_1C46();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 5)) == 0);
  if (flag_nz()) p05_L_5AEE();
  p05_L_56EA();
  return;
}

/* flash page 5 cpu 0x59A3 (offset 0x19A3) */
void p05_L_59A3(void) {
  set_hl(0x0615);
  p00_L_25A2();
  p05_L_59B0();
  p00_L_25C8();
  return;
}

/* flash page 5 cpu 0x59B0 (offset 0x19B0) */
void p05_L_59B0(void) {
  p00_L_37C5();
  p00_L_166E();
  p00_L_002B();
  p00_L_36D5();
  p00_L_1717();
  p00_L_1037();
  flag_cmp(a, 0x04);
  if (flag_z()) goto lab_p05_L_59CF;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p05_L_59CF;
  flag_cmp(a, 0x01);
  if (flag_nz()) { p00_L_24DD(); return; }
  lab_p05_L_59CF: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p05_L_59D9;
  p00_L_36DB();
  return;
  lab_p05_L_59D9: ;
  p05_L_5AEE();
  p00_L_2222();
  p05_L_552C();
  p00_rst10();
  if (flag_nc()) p00_L_16F4();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 3)));
  p00_L_38DF();
  p00_L_36DB();
  p05_L_552C();
  p00_rst10();
  if (flag_c()) return;
  p00_L_17E9();
  a = mem_read8(0x970A);
  a = (uint8_t)(a - 0x02);
  if (flag_nc()) goto lab_p05_L_5A05;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 5)));
  p05_L_5A11();
  return;
  lab_p05_L_5A05: ;
  if (flag_nz()) goto lab_p05_L_5A0D;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 6)));
  p05_L_5A11();
  return;
  lab_p05_L_5A0D: ;
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 7)));
  p05_L_5A11();
  return;
}

/* flash page 5 cpu 0x5A11 (offset 0x1A11) */
void p05_L_5A11(void) {
  p05_L_5A32();
  if (flag_z()) return;
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  set_hl(0x5A3F);
  p00_L_25A2();
  p05_L_552C();
  p00_rst10();
  p00_L_31E9();
  p00_L_31EF();
  p00_L_25C8();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x5A32 (offset 0x1A32) */
void p05_L_5A32(void) {
  p05_L_552C();
  p00_rst10();
  if (flag_c()) goto lab_p05_L_5A3D;
  p00_L_1EF4();
  a = a | a;
  flag_logic(a);
  return;
  lab_p05_L_5A3D: ;
  a = 0;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x5A68 (offset 0x1A68) */
void p05_L_5A68(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  p00_L_002B();
  /* scf */
  return;
}

/* flash page 5 cpu 0x5A71 (offset 0x1A71) */
void p05_L_5A71(void) {
  p00_L_18B7();
  if (flag_nz()) goto lab_p05_L_5AB4;
  p05_L_5A76();
  return;
  lab_p05_L_5AA2: ;
  p05_L_544D();
  cpu_pop_hl();
  mem_write16(0x8DA1, hl());
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x02), a);
  p00_L_18B7();
  if (flag_nz()) p00_L_33A5();
  return;
  lab_p05_L_5AB4: ;
  p00_L_339F();
  a = mem_read8((uint16_t)(iy + 0x02));
  cpu_push_af();
  set_hl(mem_read16(0x8DA1));
  cpu_push_hl();
  set_hl(0x0000);
  mem_write16(0x8DA1, hl());
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 1)));
  a = 0x09;
  b = 0x30;
  p05_L_543E();
  a = 0x37;
  b = 0x30;
  p05_L_543E();
  a = 0x47;
  goto lab_p05_L_5AA2;
}

/* flash page 5 cpu 0x5A76 (offset 0x1A76) */
void p05_L_5A76(void) {
  p00_L_18B7();
  if (flag_nz()) p00_L_339F();
  a = mem_read8((uint16_t)(iy + 0x02));
  cpu_push_af();
  set_hl(mem_read16(0x8DA1));
  cpu_push_hl();
  set_hl(0x0000);
  mem_write16(0x8DA1, hl());
  mem_write8((uint16_t)(iy + 0x02), (uint8_t)(mem_read8((uint16_t)(iy + 0x02)) | (1u << 1)));
  a = 0x09;
  p05_L_543C();
  a = 0x37;
  p05_L_5446();
  p05_L_543C();
  a = 0x1F;
  p05_L_544D();
  a = 0x3D;
  p05_L_544D();
  cpu_pop_hl();
  mem_write16(0x8DA1, hl());
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x02), a);
  p00_L_18B7();
  if (flag_nz()) p00_L_33A5();
  return;
}

/* flash page 5 cpu 0x5ADB (offset 0x1ADB) */
void p05_L_5ADB(void) {
  p00_L_3D35();
  lab_p05_L_5ADE: ;
  a = mem_read8(hl());
  flag_cmp(a, 0x20);
  if (flag_z()) return;
  a = mem_read8(0x844C);
  a = (uint8_t)(a + 1);
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  mem_write8(0x844C, a);
  set_hl((uint16_t)(hl() + 1));
  goto lab_p05_L_5ADE;
}

/* flash page 5 cpu 0x5AEE (offset 0x1AEE) */
void p05_L_5AEE(void) {
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 5)));
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 7)));
  return;
}

/* flash page 5 cpu 0x5AFB (offset 0x1AFB) */
void p05_L_5AFB(void) {
  cpu_push_bc();
  cpu_push_af();
  a = mem_read8(0x97A6);
  b = a;
  lab_p05_L_5B01: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  /* scf */
  if (flag_z()) goto lab_p05_L_5B10;
  p00_L_3F9F();
  a = mem_read8(0x844B);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p05_L_5B01;
  lab_p05_L_5B10: ;
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  return;
}

/* flash page 5 cpu 0x5B14 (offset 0x1B14) */
void p05_L_5B14(void) {
  set_hl(mem_read16(0x96FE));
  p05_L_5B17();
  return;
}

/* flash page 5 cpu 0x5B17 (offset 0x1B17) */
void p05_L_5B17(void) {
  set_de(0x03E7);
  p00_L_192A();
  return;
}

/* flash page 5 cpu 0x5B1D (offset 0x1B1D) */
void p05_L_5B1D(void) {
  p05_L_57D8();
  p05_L_5B20();
  return;
}

/* flash page 5 cpu 0x5B20 (offset 0x1B20) */
void p05_L_5B20(void) {
  p05_L_6FCD();
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 7)));
  set_hl(0x684F);
  p00_L_07C1();
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_5B3E;
  p00_L_3D11();
  p05_L_5BA7();
  if (flag_z()) goto lab_p05_L_5B41;
  lab_p05_L_5B3E: ;
  p00_L_3E8B();
  lab_p05_L_5B41: ;
  p00_L_176F();
  p05_L_620C();
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_5B59;
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 3)));
  p00_L_3525();
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 3)));
  p05_L_5B62();
  return;
  lab_p05_L_5B59: ;
  p05_L_6DEC();
  p05_L_5B5C();
  return;
}

/* flash page 5 cpu 0x5B5C (offset 0x1B5C) */
void p05_L_5B5C(void) {
  p05_L_5C38();
  p05_L_61AD();
  p05_L_5B62();
  return;
}

/* flash page 5 cpu 0x5B62 (offset 0x1B62) */
void p05_L_5B62(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 4)));
  return;
}

/* flash page 5 cpu 0x5B6F (offset 0x1B6F) */
void p05_L_5B6F(void) {
  set_hl(0x684F);
  p00_L_07CC();
  p05_L_5B62();
  return;
}

/* flash page 5 cpu 0x5B77 (offset 0x1B77) */
void p05_L_5B77(void) {
  p05_L_6FCD();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) | (1u << 6)));
  p00_L_3153();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  p05_L_6DEC();
  p05_L_5C38();
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_5BA3;
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  p00_L_3E8B();
  p00_L_3525();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  return;
  lab_p05_L_5BA3: ;
  p05_L_61AD();
  return;
}

/* flash page 5 cpu 0x5BA7 (offset 0x1BA7) */
void p05_L_5BA7(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 6)) == 0);
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 7)) == 0);
  return;
}

/* flash page 5 cpu 0x5BB1 (offset 0x1BB1) */
void p05_L_5BB1(void) {
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  p05_L_5BA7();
  if (flag_z()) goto lab_p05_L_5BC3;
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p05_L_5BC3;
  p00_L_3E8B();
  lab_p05_L_5BC3: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 0)) == 0);
  if (flag_nz()) { p05_L_5BE9(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 2)) == 0);
  p05_L_5BCD();
  return;
}

/* flash page 5 cpu 0x5BCD (offset 0x1BCD) */
void p05_L_5BCD(void) {
  if (flag_nz()) { p05_L_5BE9(); return; }
  p05_L_6FCD();
  p05_L_6DEC();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  b = 0x08;
  l = b;
  h = 0x08;
  lab_p05_L_5BDE: ;
  l = (uint8_t)(l - 1);
  mem_write16(0x844B, hl());
  p00_L_3D1D();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5BDE;
  goto lab_p05_L_5BED;
  lab_p05_L_5BED: ;
  a = mem_read8(0x97A7);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 2)));
  set_hl(0x5C21);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  p05_L_5C38();
  p05_L_61AD();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 2)));
  cpu_pop_af();
  mem_write8(0x97A7, a);
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 7)));
  return;
}

/* flash page 5 cpu 0x5BE9 (offset 0x1BE9) */
void p05_L_5BE9(void) {
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  a = mem_read8(0x97A7);
  cpu_push_af();
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) | (1u << 2)));
  set_hl(0x5C21);
  p00_L_25A2();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  p05_L_5C38();
  p05_L_61AD();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x1F), (uint8_t)(mem_read8((uint16_t)(iy + 0x1F)) & ~(1u << 2)));
  cpu_pop_af();
  mem_write8(0x97A7, a);
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) & ~(1u << 7)));
  return;
}

/* flash page 5 cpu 0x5C38 (offset 0x1C38) */
void p05_L_5C38(void) {
  a = 0;
  flag_logic(a);
  p00_L_17CE();
  if (flag_z()) goto lab_p05_L_5C40;
  a = (uint8_t)(a + 0x04);
  lab_p05_L_5C40: ;
  mem_write8(0x97A5, a);
  return;
}

/* flash page 5 cpu 0x5C44 (offset 0x1C44) */
void p05_L_5C44(void) {
  set_hl(0x929F);
  a = 0;
  flag_logic(a);
  b = 0x0D;
  lab_p05_L_5C4A: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5C4A;
  return;
}

/* flash page 5 cpu 0x5C4F (offset 0x1C4F) */
void p05_L_5C4F(void) {
  p05_L_6876();
  if (flag_z()) { p05_L_5C80(); return; }
  set_hl(0x91E2);
  c = 0x07;
  set_de(0x0009);
  a = mem_read8(0x91E0);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_5C70;
  flag_cmp(a, 0x07);
  if (flag_nc()) goto lab_p05_L_5CCC;
  b = a;
  a = 0x02;
  lab_p05_L_5C69: ;
  /* sla a */
  set_hl((uint16_t)(hl() + de()));
  c = (uint8_t)(c - 1);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5C69;
  a = (uint8_t)(a - 1);
  lab_p05_L_5C70: ;
  mem_write8(0x929F, a);
  a = c;
  /* sla a */
  /* sla a */
  /* sla a */
  a = (uint8_t)(a + c);
  b = a;
  p05_L_5CEC();
  return;
  lab_p05_L_5CCC: ;
  a = 0xFF;
  mem_write8(0x929F, a);
  return;
}

/* flash page 5 cpu 0x5C80 (offset 0x1C80) */
void p05_L_5C80(void) {
  set_hl(0x8622);
  p00_rst20();
  p00_L_10DD();
  set_hl(0x91E2);
  b = 0x07;
  cpu_push_bc();
  cpu_push_hl();
  cpu_push_hl();
  goto lab_p05_L_5C9D;
  lab_p05_L_5C91: ;
  cpu_push_bc();
  cpu_push_de();
  cpu_push_hl();
  p00_L_1135();
  p00_L_0C1B();
  p00_L_10DD();
  lab_p05_L_5C9D: ;
  set_hl(0x5CD2);
  p00_L_25A2();
  p00_L_15FB();
  set_hl(0x92BC);
  p00_L_11F8();
  p00_L_0D1F();
  p05_L_6FB2();
  if (flag_nz()) p00_L_3E37();
  set_hl(0x862B);
  p00_L_11F8();
  p00_rst30();
  p00_L_15FB();
  p00_L_25C8();
  cpu_pop_de();
  cpu_pop_de();
  cpu_push_de();
  p00_L_11FD();
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5C91;
  a = 0xFF;
  mem_write8(0x929F, a);
  return;
}

/* flash page 5 cpu 0x5CD6 (offset 0x1CD6) */
void p05_L_5CD6(void) {
  a = 0xFF;
  mem_write8(0x8478, a);
  return;
}

/* flash page 5 cpu 0x5CE2 (offset 0x1CE2) */
void p05_L_5CE2(void) {
  set_hl(0x9221);
  b = 0x7E;
  p05_L_5CEC();
  return;
}

/* flash page 5 cpu 0x5CE9 (offset 0x1CE9) */
void p05_L_5CE9(void) {
  set_hl((uint16_t)(hl() + de()));
  p05_L_5CEA();
  return;
}

/* flash page 5 cpu 0x5CEA (offset 0x1CEA) */
void p05_L_5CEA(void) {
  b = 0x09;
  p05_L_5CEC();
  return;
}

/* flash page 5 cpu 0x5CEC (offset 0x1CEC) */
void p05_L_5CEC(void) {
  a = 0;
  flag_logic(a);
  p05_L_5CED();
  return;
}

/* flash page 5 cpu 0x5CED (offset 0x1CED) */
void p05_L_5CED(void) {
  lab_p05_L_5CED: ;
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5CED;
  return;
}

/* flash page 5 cpu 0x5CF2 (offset 0x1CF2) */
void p05_L_5CF2(void) {
  p05_L_6880();
  if (flag_nz()) return;
  a = mem_read8(0x91DC);
  goto lab_p05_L_5D01;
  lab_p05_L_5D01: ;
  p05_L_6880();
  if (flag_nz()) return;
  set_hl(mem_read16(0x91DD));
  cpu_push_hl();
  set_hl(mem_read16(0x91DB));
  cpu_push_hl();
  mem_write8(0x91DC, a);
  p05_L_652D();
  if (flag_z()) goto lab_p05_L_5D3F;
  mem_write8(0x91DB, a);
  a = 0x01;
  p05_L_609D();
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_5D32;
  p05_L_6FAE();
  if (flag_z()) goto lab_p05_L_5D3F;
  p05_L_652D();
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  a = (uint8_t)(a + 1);
  goto lab_p05_L_5D37;
  lab_p05_L_5D32: ;
  p05_L_668B();
  if (flag_z()) goto lab_p05_L_5D3F;
  lab_p05_L_5D37: ;
  mem_write8(0x91DB, a);
  a = 0x02;
  p05_L_609D();
  lab_p05_L_5D3F: ;
  p05_L_6707();
  return;
}

/* flash page 5 cpu 0x5CFB (offset 0x1CFB) */
void p05_L_5CFB(void) {
  a = 0x01;
  goto lab_p05_L_5D01;
  lab_p05_L_5D01: ;
  p05_L_6880();
  if (flag_nz()) return;
  set_hl(mem_read16(0x91DD));
  cpu_push_hl();
  set_hl(mem_read16(0x91DB));
  cpu_push_hl();
  mem_write8(0x91DC, a);
  p05_L_652D();
  if (flag_z()) goto lab_p05_L_5D3F;
  mem_write8(0x91DB, a);
  a = 0x01;
  p05_L_609D();
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_5D32;
  p05_L_6FAE();
  if (flag_z()) goto lab_p05_L_5D3F;
  p05_L_652D();
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  a = (uint8_t)(a + 1);
  goto lab_p05_L_5D37;
  lab_p05_L_5D32: ;
  p05_L_668B();
  if (flag_z()) goto lab_p05_L_5D3F;
  lab_p05_L_5D37: ;
  mem_write8(0x91DB, a);
  a = 0x02;
  p05_L_609D();
  lab_p05_L_5D3F: ;
  p05_L_6707();
  return;
}

/* flash page 5 cpu 0x5CFF (offset 0x1CFF) */
void p05_L_5CFF(void) {
  a = 0x07;
  p05_L_6880();
  if (flag_nz()) return;
  set_hl(mem_read16(0x91DD));
  cpu_push_hl();
  set_hl(mem_read16(0x91DB));
  cpu_push_hl();
  mem_write8(0x91DC, a);
  p05_L_652D();
  if (flag_z()) goto lab_p05_L_5D3F;
  mem_write8(0x91DB, a);
  a = 0x01;
  p05_L_609D();
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_5D32;
  p05_L_6FAE();
  if (flag_z()) goto lab_p05_L_5D3F;
  p05_L_652D();
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  a = (uint8_t)(a + 1);
  goto lab_p05_L_5D37;
  lab_p05_L_5D32: ;
  p05_L_668B();
  if (flag_z()) goto lab_p05_L_5D3F;
  lab_p05_L_5D37: ;
  mem_write8(0x91DB, a);
  a = 0x02;
  p05_L_609D();
  lab_p05_L_5D3F: ;
  p05_L_6707();
  return;
}

/* flash page 5 cpu 0x5D42 (offset 0x1D42) */
void p05_L_5D42(void) {
  p05_L_5CE2();
  set_hl(0x92A0);
  b = 0x0C;
  p05_L_5CEC();
  p05_L_6880();
  if (flag_nz()) return;
  set_hl(0x92A0);
  b = 0x0C;
  a = mem_read8(0x929F);
  p05_L_5CED();
  p05_L_5EFA();
  p05_L_5F01();
  return;
}

/* flash page 5 cpu 0x5D63 (offset 0x1D63) */
void p05_L_5D63(void) {
  p00_L_33BD();
  p05_L_5EDA();
  mem_write8(0x91DA, a);
  return;
}

/* flash page 5 cpu 0x5D6D (offset 0x1D6D) */
void p05_L_5D6D(void) {
  set_hl(0x9221);
  set_de(0x9260);
  goto lab_p05_L_5D7B;
  lab_p05_L_5D7B: ;
  set_bc(0x003F);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 5 cpu 0x5D75 (offset 0x1D75) */
void p05_L_5D75(void) {
  set_de(0x9221);
  set_hl(0x9260);
  set_bc(0x003F);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 5 cpu 0x5D81 (offset 0x1D81) */
void p05_L_5D81(void) {
  set_de(0x929E);
  set_hl(0x9295);
  set_bc(0x00B4);
  /* lddr */
  set_hl(0x929F);
  b = 0x0D;
  lab_p05_L_5D91: ;
  a = mem_read8(hl());
  /* sla a */
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5D91;
  p05_L_5EA9();
  return;
}

/* flash page 5 cpu 0x5D9C (offset 0x1D9C) */
void p05_L_5D9C(void) {
  set_de(0x91E2);
  set_hl(0x91EB);
  set_bc(0x00B4);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(0x929F);
  b = 0x0D;
  lab_p05_L_5DAC: ;
  a = mem_read8(hl());
  /* srl a */
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5DAC;
  p05_L_5EA4();
  return;
}

/* flash page 5 cpu 0x5DB7 (offset 0x1DB7) */
void p05_L_5DB7(void) {
  a = mem_read8(0x91DC);
  flag_cmp(a, 0x07);
  if (flag_z()) goto lab_p05_L_5DDD;
  set_de(0x929E);
  set_hl(0x9295);
  p05_L_5E77();
  cpu_push_bc();
  /* lddr */
  set_de(0x925F);
  set_hl(0x9256);
  cpu_pop_bc();
  cpu_push_bc();
  /* lddr */
  set_de(0x9220);
  set_hl(0x9217);
  cpu_pop_bc();
  /* lddr */
  lab_p05_L_5DDD: ;
  set_hl(0x929F);
  b = 0x0D;
  lab_p05_L_5DE2: ;
  cpu_push_bc();
  a = mem_read8(0x91DC);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_5DF4;
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p05_L_5DF4;
  b = a;
  a = 0;
  flag_logic(a);
  lab_p05_L_5DEE: ;
  /* sla a */
  a = (uint8_t)(a + 0x01);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5DEE;
  lab_p05_L_5DF4: ;
  b = a;
  a = mem_read8(hl());
  a = a & b;
  flag_logic(a);
  c = a;
  a = b;
  a = a ^ 0xFF;
  flag_logic(a);
  /* and (hl) */
  /* sla a */
  a = a | c;
  flag_logic(a);
  mem_write8(hl(), a);
  cpu_pop_bc();
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5DE2;
  p05_L_605E();
  /* or (hl) */
  mem_write8(hl(), a);
  p05_L_5E90();
  p05_L_5E9F();
  return;
}

/* flash page 5 cpu 0x5E10 (offset 0x1E10) */
void p05_L_5E10(void) {
  a = mem_read8(0x91DC);
  flag_cmp(a, 0x01);
  if (flag_z()) { p05_L_5D9C(); return; }
  flag_cmp(a, 0x07);
  if (flag_nc()) goto lab_p05_L_5E43;
  p05_L_5E77();
  cpu_push_bc();
  set_de(0x9221);
  set_hl(0x9218);
  p05_L_5E6F();
  while (bc() != 0) { cpu_ldi(); }
  set_de(0x9260);
  set_hl(0x9257);
  cpu_pop_bc();
  p05_L_5E6F();
  cpu_push_bc();
  while (bc() != 0) { cpu_ldi(); }
  set_de(0x929F);
  set_hl(0x9296);
  cpu_pop_bc();
  p05_L_5E6F();
  while (bc() != 0) { cpu_ldi(); }
  lab_p05_L_5E43: ;
  p05_L_5EA4();
  set_hl(0x929F);
  b = 0x0D;
  lab_p05_L_5E4B: ;
  cpu_push_bc();
  a = mem_read8(0x91DC);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_5E5D;
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p05_L_5E5D;
  b = a;
  a = 0;
  flag_logic(a);
  lab_p05_L_5E57: ;
  /* sla a */
  a = (uint8_t)(a + 0x01);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5E57;
  lab_p05_L_5E5D: ;
  b = a;
  a = a ^ 0xFF;
  flag_logic(a);
  c = a;
  a = mem_read8(hl());
  a = a & b;
  flag_logic(a);
  b = a;
  a = mem_read8(hl());
  /* srl a */
  a = a & c;
  flag_logic(a);
  a = a | b;
  flag_logic(a);
  mem_write8(hl(), a);
  cpu_pop_bc();
  set_hl((uint16_t)(hl() + 1));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5E4B;
  return;
}

/* flash page 5 cpu 0x5E6F (offset 0x1E6F) */
void p05_L_5E6F(void) {
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_bc();
  cpu_ex_de_hl();
  a = 0;
  flag_logic(a);
  cpu_sbc_hl_bc();
  return;
}

/* flash page 5 cpu 0x5E77 (offset 0x1E77) */
void p05_L_5E77(void) {
  b = a;
  a = 0x07;
  a = (uint8_t)(a - b);
  b = a;
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + b);
  c = a;
  b = 0x00;
  return;
}

/* flash page 5 cpu 0x5E84 (offset 0x1E84) */
void p05_L_5E84(void) {
  a = mem_read8(0x91DC);
  a = (uint8_t)(a - 1);
  l = a;
  h = 0x00;
  p00_L_1025();
  cpu_ex_de_hl();
  return;
}

/* flash page 5 cpu 0x5E90 (offset 0x1E90) */
void p05_L_5E90(void) {
  p00_L_128A();
  set_de(0x91E2);
  p05_L_5E84();
  set_hl((uint16_t)(hl() + de()));
  cpu_ex_de_hl();
  p00_L_11FD();
  return;
}

/* flash page 5 cpu 0x5E9F (offset 0x1E9F) */
void p05_L_5E9F(void) {
  p05_L_5E84();
  goto lab_p05_L_5EB2;
  lab_p05_L_5EB2: ;
  set_hl(0x9221);
  p05_L_5CE9();
  set_hl(0x9260);
  p05_L_5CE9();
  p05_L_6891();
  if (flag_z()) return;
  b = a;
  a = 0x01;
  goto lab_p05_L_5EC9;
  lab_p05_L_5EC7: ;
  /* sla a */
  lab_p05_L_5EC9: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5EC7;
  a = a ^ 0xFF;
  flag_logic(a);
  p05_L_5ECD();
  return;
}

/* flash page 5 cpu 0x5EA4 (offset 0x1EA4) */
void p05_L_5EA4(void) {
  set_de(0x0036);
  goto lab_p05_L_5EAC;
  lab_p05_L_5EAC: ;
  set_hl(0x91E2);
  p05_L_5CE9();
  set_hl(0x9221);
  p05_L_5CE9();
  set_hl(0x9260);
  p05_L_5CE9();
  p05_L_6891();
  if (flag_z()) return;
  b = a;
  a = 0x01;
  goto lab_p05_L_5EC9;
  lab_p05_L_5EC7: ;
  /* sla a */
  lab_p05_L_5EC9: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5EC7;
  a = a ^ 0xFF;
  flag_logic(a);
  p05_L_5ECD();
  return;
}

/* flash page 5 cpu 0x5EA9 (offset 0x1EA9) */
void p05_L_5EA9(void) {
  set_de(0x0000);
  set_hl(0x91E2);
  p05_L_5CE9();
  set_hl(0x9221);
  p05_L_5CE9();
  set_hl(0x9260);
  p05_L_5CE9();
  p05_L_6891();
  if (flag_z()) return;
  b = a;
  a = 0x01;
  goto lab_p05_L_5EC9;
  lab_p05_L_5EC7: ;
  /* sla a */
  lab_p05_L_5EC9: ;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5EC7;
  a = a ^ 0xFF;
  flag_logic(a);
  p05_L_5ECD();
  return;
}

/* flash page 5 cpu 0x5ECD (offset 0x1ECD) */
void p05_L_5ECD(void) {
  c = a;
  set_hl(0x92A0);
  b = 0x0C;
  lab_p05_L_5ED3: ;
  /* and (hl) */
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  a = c;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_5ED3;
  return;
}

/* flash page 5 cpu 0x5EDA (offset 0x1EDA) */
void p05_L_5EDA(void) {
  set_hl(mem_read16(0x980C));
  mem_write16(0x9824, hl());
  return;
}

/* flash page 5 cpu 0x5EE1 (offset 0x1EE1) */
void p05_L_5EE1(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 6)) == 0);
  return;
}

/* flash page 5 cpu 0x5EE6 (offset 0x1EE6) */
void p05_L_5EE6(void) {
  p05_L_652D();
  if (flag_z()) return;
  cpu_push_af();
  a = 0x01;
  mem_write8(0x91DD, a);
  cpu_pop_af();
  p05_L_5F25();
  a = 0x02;
  mem_write8(0x91DD, a);
  return;
}

/* flash page 5 cpu 0x5EFA (offset 0x1EFA) */
void p05_L_5EFA(void) {
  a = 0x01;
  mem_write8(0x91DD, a);
  goto lab_p05_L_5F2E;
  lab_p05_L_5F2E: ;
  mem_write8(0x91DB, a);
  p05_L_5F31();
  return;
}

/* flash page 5 cpu 0x5F01 (offset 0x1F01) */
void p05_L_5F01(void) {
  p05_L_6FAE();
  if (flag_nz()) goto lab_p05_L_5F0A;
  p00_L_18B7();
  if (flag_nz()) return;
  lab_p05_L_5F0A: ;
  a = 0x02;
  mem_write8(0x91DD, a);
  p05_L_65A8();
  if (flag_z()) return;
  p05_L_5EE1();
  if (flag_z()) goto lab_p05_L_5F20;
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  a = (uint8_t)(a + 1);
  p05_L_5F25();
  return;
  lab_p05_L_5F20: ;
  p00_L_3513();
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  p05_L_5F25();
  return;
}

/* flash page 5 cpu 0x5F25 (offset 0x1F25) */
void p05_L_5F25(void) {
  set_hl(mem_read16(0x91DB));
  cpu_push_hl();
  mem_write8(0x91DB, a);
  goto lab_p05_L_5F3B;
  lab_p05_L_5F3B: ;
  a = 0;
  flag_logic(a);
  mem_write8(0x91DC, a);
  b = 0x07;
  set_hl(0x91E2);
  lab_p05_L_5F44: ;
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x91DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_L_21E5();
  p00_L_1120();
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p05_L_6834();
  if (flag_c()) goto lab_p05_L_5FCB;
  if (flag_z()) goto lab_p05_L_5FCB;
  p05_L_604B();
  if (flag_nz()) goto lab_p05_L_5FCB;
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  set_hl(0x5FDC);
  p00_L_25A2();
  p05_L_603D();
  p00_L_21E0();
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p05_L_5F87;
  p00_L_187F();
  p00_L_1100();
  set_hl(0x8FE0);
  p05_L_5F7E();
  return;
  lab_p05_L_5F87: ;
  p00_L_25C8();
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 1)));
  a = 0;
  flag_logic(a);
  mem_write8(0x9305, a);
  set_hl(0x5FE0);
  p00_L_25A2();
  p00_L_31E9();
  set_hl(0x0000);
  mem_write16(0x9665, hl());
  p00_L_38F7();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 1)));
  set_hl(0x5FDC);
  p00_L_25A2();
  p05_L_6185();
  p05_L_602F();
  a = 0;
  flag_logic(a);
  mem_write8(0x9305, a);
  p00_L_25C8();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  p05_L_6020();
  lab_p05_L_5FCB: ;
  p00_L_219B();
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p05_L_5F44;
  cpu_pop_hl();
  mem_write16(0x91DB, hl());
  p00_L_32FD();
  return;
}

/* flash page 5 cpu 0x5F31 (offset 0x1F31) */
void p05_L_5F31(void) {
  set_hl(mem_read16(0x91DB));
  cpu_push_hl();
  p05_L_65A8();
  if (flag_z()) goto lab_p05_L_5FD4;
  a = 0;
  flag_logic(a);
  mem_write8(0x91DC, a);
  b = 0x07;
  set_hl(0x91E2);
  lab_p05_L_5F44: ;
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x91DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_L_21E5();
  p00_L_1120();
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p05_L_6834();
  if (flag_c()) goto lab_p05_L_5FCB;
  if (flag_z()) goto lab_p05_L_5FCB;
  p05_L_604B();
  if (flag_nz()) goto lab_p05_L_5FCB;
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  set_hl(0x5FDC);
  p00_L_25A2();
  p05_L_603D();
  p00_L_21E0();
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p05_L_5F87;
  p00_L_187F();
  p00_L_1100();
  set_hl(0x8FE0);
  p05_L_5F7E();
  return;
  lab_p05_L_5F87: ;
  p00_L_25C8();
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 1)));
  a = 0;
  flag_logic(a);
  mem_write8(0x9305, a);
  set_hl(0x5FE0);
  p00_L_25A2();
  p00_L_31E9();
  set_hl(0x0000);
  mem_write16(0x9665, hl());
  p00_L_38F7();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 1)));
  set_hl(0x5FDC);
  p00_L_25A2();
  p05_L_6185();
  p05_L_602F();
  a = 0;
  flag_logic(a);
  mem_write8(0x9305, a);
  p00_L_25C8();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  p05_L_6020();
  lab_p05_L_5FCB: ;
  p00_L_219B();
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p05_L_5F44;
  lab_p05_L_5FD4: ;
  cpu_pop_hl();
  mem_write16(0x91DB, hl());
  p00_L_32FD();
  return;
}

/* flash page 5 cpu 0x5F7E (offset 0x1F7E) */
void p05_L_5F7E(void) {
  goto lab_p05_L_5F7E;
  lab_p05_L_5F44: ;
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x91DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_L_21E5();
  p00_L_1120();
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p05_L_6834();
  if (flag_c()) goto lab_p05_L_5FCB;
  if (flag_z()) goto lab_p05_L_5FCB;
  p05_L_604B();
  if (flag_nz()) goto lab_p05_L_5FCB;
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  set_hl(0x5FDC);
  p00_L_25A2();
  p05_L_603D();
  p00_L_21E0();
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p05_L_5F87;
  p00_L_187F();
  p00_L_1100();
  set_hl(0x8FE0);
  lab_p05_L_5F7E: ;
  p00_L_1073();
  p00_L_113F();
  if (flag_c()) { p00_L_24C9(); return; }
  lab_p05_L_5F87: ;
  p00_L_25C8();
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 1)));
  a = 0;
  flag_logic(a);
  mem_write8(0x9305, a);
  set_hl(0x5FE0);
  p00_L_25A2();
  p00_L_31E9();
  set_hl(0x0000);
  mem_write16(0x9665, hl());
  p00_L_38F7();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 1)));
  set_hl(0x5FDC);
  p00_L_25A2();
  p05_L_6185();
  p05_L_602F();
  a = 0;
  flag_logic(a);
  mem_write8(0x9305, a);
  p00_L_25C8();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  p05_L_6020();
  lab_p05_L_5FCB: ;
  p00_L_219B();
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p05_L_5F44;
  cpu_pop_hl();
  mem_write16(0x91DB, hl());
  p00_L_32FD();
  return;
}

/* flash page 5 cpu 0x5FEC (offset 0x1FEC) */
void p05_L_5FEC(void) {
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 1)));
  p05_L_602F();
  mem_write8(0x86DD, a);
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_z()) goto lab_p05_L_6004;
  flag_cmp(a, 0x87);
  if (flag_z()) goto lab_p05_L_6019;
  flag_cmp(a, 0x86);
  if (flag_c()) goto lab_p05_L_6019;
  goto lab_p05_L_600C;
  lab_p05_L_6004: ;
  flag_cmp(a, 0x07);
  if (flag_z()) goto lab_p05_L_6019;
  flag_cmp(a, 0x06);
  if (flag_c()) goto lab_p05_L_6019;
  lab_p05_L_600C: ;
  p05_L_6FD8();
  flag_set_z((mem_read8((uint16_t)(iy + 0x08)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3159();
  p00_L_2565();
  return;
  lab_p05_L_6019: ;
  p05_L_5CD6();
  a = 0;
  flag_logic(a);
  mem_write8(0x9305, a);
  p05_L_6020();
  return;
}

/* flash page 5 cpu 0x6020 (offset 0x2020) */
void p05_L_6020(void) {
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 6)));
  p05_L_6077();
  p05_L_607D();
  cpu_ex_de_hl();
  p00_L_11FD();
  return;
}

/* flash page 5 cpu 0x602F (offset 0x202F) */
void p05_L_602F(void) {
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 0)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 7)) == 0);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 0)));
  return;
}

/* flash page 5 cpu 0x603D (offset 0x203D) */
void p05_L_603D(void) {
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 7)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 0)) == 0);
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) | (1u << 7)));
  return;
}

/* flash page 5 cpu 0x604B (offset 0x204B) */
void p05_L_604B(void) {
  p05_L_6880();
  if (flag_z()) return;
  p05_L_6067();
  b = a;
  /* and (hl) */
  a = a ^ b;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x6056 (offset 0x2056) */
void p05_L_6056(void) {
  p05_L_6067();
  a = a ^ 0xFF;
  flag_logic(a);
  /* and (hl) */
  mem_write8(hl(), a);
  return;
}

/* flash page 5 cpu 0x605E (offset 0x205E) */
void p05_L_605E(void) {
  a = mem_read8(0x91DC);
  set_hl(0x929F);
  b = a;
  goto lab_p05_L_6071;
  lab_p05_L_6071: ;
  a = 0x80;
  lab_p05_L_6073: ;
  cpu_rlca();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_6073;
  return;
}

/* flash page 5 cpu 0x6067 (offset 0x2067) */
void p05_L_6067(void) {
  set_hl(mem_read16(0x91DB));
  b = h;
  h = 0x00;
  set_de(0x929F);
  set_hl((uint16_t)(hl() + de()));
  a = 0x80;
  lab_p05_L_6073: ;
  cpu_rlca();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_6073;
  return;
}

/* flash page 5 cpu 0x6077 (offset 0x2077) */
void p05_L_6077(void) {
  p05_L_6067();
  /* or (hl) */
  mem_write8(hl(), a);
  return;
}

/* flash page 5 cpu 0x607D (offset 0x207D) */
void p05_L_607D(void) {
  a = mem_read8(0x91DD);
  a = a | a;
  flag_logic(a);
  if (flag_z()) { p05_L_608D(); return; }
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p05_L_6088;
  a = 0x07;
  lab_p05_L_6088: ;
  set_de(0x9221);
  goto lab_p05_L_6090;
  lab_p05_L_6090: ;
  set_hl(0x91DC);
  /* add a,(hl) */
  a = (uint8_t)(a - 1);
  l = a;
  h = 0x00;
  p00_L_1025();
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 5 cpu 0x608D (offset 0x208D) */
void p05_L_608D(void) {
  set_de(0x91E2);
  set_hl(0x91DC);
  /* add a,(hl) */
  a = (uint8_t)(a - 1);
  l = a;
  h = 0x00;
  p00_L_1025();
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 5 cpu 0x609D (offset 0x209D) */
void p05_L_609D(void) {
  mem_write8(0x91DD, a);
  p05_L_60A0();
  return;
}

/* flash page 5 cpu 0x60A0 (offset 0x20A0) */
void p05_L_60A0(void) {
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  set_hl(0x6175);
  p00_L_25A2();
  p05_L_603D();
  p00_L_21E5();
  a = 0;
  flag_logic(a);
  p05_L_608D();
  p00_rst20();
  p05_L_6834();
  if (flag_c()) goto lab_p05_L_616A;
  if (flag_z()) goto lab_p05_L_616A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p05_L_60D6;
  p00_L_187F();
  p00_L_1100();
  set_hl(0x8FE0);
  p05_L_60CD();
  return;
  lab_p05_L_60D6: ;
  p00_L_25C8();
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 1)));
  a = 0;
  flag_logic(a);
  mem_write8(0x9305, a);
  set_hl(0x6179);
  p00_L_25A2();
  p05_L_6FB2();
  if (flag_z()) goto lab_p05_L_6139;
  p00_L_0013();
  if (flag_z()) goto lab_p05_L_60FE;
  a = mem_read8(0x9151);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p05_L_6139;
  lab_p05_L_60FE: ;
  p00_L_01A2();
  if (flag_z()) goto lab_p05_L_6116;
  a = mem_read8(0x91DD);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p05_L_6122;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 6)) == 0);
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_38F1();
  goto lab_p05_L_6145;
  lab_p05_L_6116: ;
  p05_L_6DB5();
  if (flag_nz()) goto lab_p05_L_6139;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 6)) == 0);
  if (flag_nz()) { p00_L_24C9(); return; }
  lab_p05_L_6122: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 7)) == 0);
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_353D();
  p00_L_0198();
  if (flag_z()) goto lab_p05_L_6145;
  p00_L_168D();
  p00_L_38B5();
  goto lab_p05_L_6145;
  lab_p05_L_6139: ;
  p00_L_31E9();
  set_hl(0x0000);
  mem_write16(0x9665, hl());
  p00_L_38F7();
  lab_p05_L_6145: ;
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 1)));
  set_hl(0x6175);
  p00_L_25A2();
  p05_L_6185();
  p05_L_602F();
  a = 0;
  flag_logic(a);
  mem_write8(0x9305, a);
  p00_L_25C8();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  p05_L_6020();
  p00_L_32FD();
  return;
  lab_p05_L_616A: ;
  p00_L_219B();
  p00_L_25C8();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  return;
}

/* flash page 5 cpu 0x60CD (offset 0x20CD) */
void p05_L_60CD(void) {
  p00_L_1073();
  p00_L_113F();
  if (flag_c()) { p00_L_24C9(); return; }
  p00_L_25C8();
  set_hl(0x0001);
  mem_write16(0x980E, hl());
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) | (1u << 1)));
  a = 0;
  flag_logic(a);
  mem_write8(0x9305, a);
  set_hl(0x6179);
  p00_L_25A2();
  p05_L_6FB2();
  if (flag_z()) goto lab_p05_L_6139;
  p00_L_0013();
  if (flag_z()) goto lab_p05_L_60FE;
  a = mem_read8(0x9151);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p05_L_6139;
  lab_p05_L_60FE: ;
  p00_L_01A2();
  if (flag_z()) goto lab_p05_L_6116;
  a = mem_read8(0x91DD);
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p05_L_6122;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 6)) == 0);
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_38F1();
  goto lab_p05_L_6145;
  lab_p05_L_6116: ;
  p05_L_6DB5();
  if (flag_nz()) goto lab_p05_L_6139;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 6)) == 0);
  if (flag_nz()) { p00_L_24C9(); return; }
  lab_p05_L_6122: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 7)) == 0);
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_353D();
  p00_L_0198();
  if (flag_z()) goto lab_p05_L_6145;
  p00_L_168D();
  p00_L_38B5();
  goto lab_p05_L_6145;
  lab_p05_L_6139: ;
  p00_L_31E9();
  set_hl(0x0000);
  mem_write16(0x9665, hl());
  p00_L_38F7();
  lab_p05_L_6145: ;
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 1)));
  set_hl(0x6175);
  p00_L_25A2();
  p05_L_6185();
  p05_L_602F();
  a = 0;
  flag_logic(a);
  mem_write8(0x9305, a);
  p00_L_25C8();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  p05_L_6020();
  p00_L_32FD();
  return;
}

/* flash page 5 cpu 0x6120 (offset 0x2120) */
void p05_L_6120(void) {
  return;
}

/* flash page 5 cpu 0x6185 (offset 0x2185) */
void p05_L_6185(void) {
  p00_L_1037();
  if (flag_z()) return;
  flag_cmp(a, 0x0C);
  if (flag_z()) { p00_L_24D1(); return; }
  flag_cmp(a, 0x0D);
  if (flag_z()) { p00_L_24D1(); return; }
  flag_cmp(a, 0x0E);
  if (flag_z()) { p00_L_24C9(); return; }
  flag_cmp(a, 0x01);
  if (flag_nz()) { p00_L_24DD(); return; }
  p00_L_241E();
  if (flag_c()) { p00_L_24DD(); return; }
  set_hl(0x0001);
  p00_L_3AF5();
  p00_L_36DB();
  return;
}

/* flash page 5 cpu 0x61AD (offset 0x21AD) */
void p05_L_61AD(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 6)) == 0);
  if (flag_z()) { p05_L_61D3(); return; }
  p05_L_6236();
  p05_L_622C();
  p05_L_5C4F();
  p05_L_5D63();
  p05_L_5D42();
  p05_L_622C();
  p05_L_6FAE();
  if (flag_z()) goto lab_p05_L_61CF;
  a = 0x01;
  mem_write8(0x91DD, a);
  lab_p05_L_61CF: ;
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 6)));
  p05_L_61D3();
  return;
}

/* flash page 5 cpu 0x61D3 (offset 0x21D3) */
void p05_L_61D3(void) {
  p05_L_62FE();
  p05_L_61E9();
  p05_L_64B1();
  p05_L_5A71();
  p05_L_66F6();
  p05_L_61E2();
  return;
}

/* flash page 5 cpu 0x61E2 (offset 0x21E2) */
void p05_L_61E2(void) {
  p05_L_6370();
  p05_L_6250();
  return;
}

/* flash page 5 cpu 0x61E9 (offset 0x21E9) */
void p05_L_61E9(void) {
  p00_L_18B7();
  if (flag_nz()) goto lab_p05_L_61F2;
  p00_L_3D17();
  return;
  lab_p05_L_61F2: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  set_hl(0x0800);
  mem_write16(0x844B, hl());
  p00_L_3D1D();
  return;
}

/* flash page 5 cpu 0x6201 (offset 0x2201) */
void p05_L_6201(void) {
  p05_L_64B1();
  p05_L_676B();
  p05_L_6773();
  p05_L_61E2();
  return;
}

/* flash page 5 cpu 0x620C (offset 0x220C) */
void p05_L_620C(void) {
  set_hl(0x92B3);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  set_hl(0x92BC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  set_hl(0x91D9);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 6)));
  return;
}

/* flash page 5 cpu 0x621C (offset 0x221C) */
void p05_L_621C(void) {
  set_hl(0x92B3);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  set_hl(0x92BC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  set_hl(0x91D9);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 6)));
  return;
}

/* flash page 5 cpu 0x622C (offset 0x222C) */
void p05_L_622C(void) {
  set_hl(0x0100);
  mem_write16(0x91DB, hl());
  mem_write16(0x91DD, hl());
  return;
}

/* flash page 5 cpu 0x6236 (offset 0x2236) */
void p05_L_6236(void) {
  p05_L_6876();
  if (flag_nz()) return;
  a = 0x07;
  mem_write8(0x91E0, a);
  return;
}

/* flash page 5 cpu 0x6240 (offset 0x2240) */
void p05_L_6240(void) {
  a = mem_read8(0x91E0);
  set_hl(0x91DC);
  cpu_cp_hl();
  return;
}

/* flash page 5 cpu 0x6248 (offset 0x2248) */
void p05_L_6248(void) {
  a = mem_read8(0x91DC);
  set_hl(0x91E0);
  cpu_cp_hl();
  return;
}

/* flash page 5 cpu 0x6250 (offset 0x2250) */
void p05_L_6250(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  p05_L_6254();
  return;
}

/* flash page 5 cpu 0x6254 (offset 0x2254) */
void p05_L_6254(void) {
  cpu_push_bc();
  cpu_push_hl();
  p05_L_6891();
  if (flag_z()) goto lab_p05_L_6285;
  p05_L_6FB2();
  if (flag_nz()) goto lab_p05_L_626D;
  p05_L_6312();
  p05_L_67B1();
  lab_p05_L_6266: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 3)));
  cpu_pop_hl();
  cpu_pop_bc();
  return;
  lab_p05_L_626D: ;
  p05_L_6312();
  p05_L_67B1();
  set_hl(0x91DD);
  a = mem_read8(hl());
  cpu_push_af();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_6312();
  p05_L_67B1();
  cpu_pop_af();
  mem_write8(0x91DD, a);
  goto lab_p05_L_6266;
  lab_p05_L_6285: ;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x4A);
  if (flag_z()) goto lab_p05_L_62A6;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p05_L_62A6;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p05_L_62DB();
  set_de(mem_read16(0x92AC));
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p05_L_62BC;
  p05_L_664E();
  goto lab_p05_L_62BC;
  lab_p05_L_62A6: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p05_L_62C5;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p05_L_62DB();
  set_hl(mem_read16(0x9706));
  p00_L_2407();
  d = mem_read8(hl());
  set_hl((uint16_t)(hl() - 1));
  e = mem_read8(hl());
  lab_p05_L_62BC: ;
  p05_L_6663();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  goto lab_p05_L_6266;
  lab_p05_L_62C5: ;
  p05_L_62DB();
  p05_L_65A8();
  if (flag_z()) goto lab_p05_L_6266;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p05_L_62D6;
  p05_L_664E();
  lab_p05_L_62D6: ;
  p05_L_665C();
  goto lab_p05_L_6266;
}

/* flash page 5 cpu 0x62DB (offset 0x22DB) */
void p05_L_62DB(void) {
  a = mem_read8(0x97A5);
  l = a;
  h = 0x0D;
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_62EF;
  p00_L_019D();
  if (flag_z()) goto lab_p05_L_62FA;
  h = 0x0C;
  goto lab_p05_L_62FA;
  lab_p05_L_62EF: ;
  h = 0x06;
  a = mem_read8(0x91DD);
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p05_L_62FA;
  h = 0x0C;
  lab_p05_L_62FA: ;
  mem_write16(0x844B, hl());
  return;
}

/* flash page 5 cpu 0x62FE (offset 0x22FE) */
void p05_L_62FE(void) {
  a = mem_read8(0x91DC);
  flag_cmp(a, 0x08);
  if (flag_nc()) goto lab_p05_L_630C;
  p00_L_17CE();
  if (flag_z()) return;
  flag_cmp(a, 0x03);
  if (flag_c()) return;
  lab_p05_L_630C: ;
  a = 0x01;
  mem_write8(0x91DC, a);
  return;
}

/* flash page 5 cpu 0x6312 (offset 0x2312) */
void p05_L_6312(void) {
  a = mem_read8(0x91DC);
  a = (uint8_t)(a - 1);
  /* sla a */
  b = a;
  /* sla a */
  a = (uint8_t)(a + b);
  a = (uint8_t)(a + 0x0A);
  p00_L_17CE();
  if (flag_z()) goto lab_p05_L_6325;
  a = (uint8_t)(a + 0x20);
  lab_p05_L_6325: ;
  mem_write8(0x86D8, a);
  a = mem_read8(0x91DD);
  p00_L_18B7();
  if (flag_nz()) goto lab_p05_L_6344;
  /* sla a */
  b = a;
  /* sla a */
  /* sla a */
  /* sla a */
  /* sla a */
  a = (uint8_t)(a - b);
  a = (uint8_t)(a + 0x05);
  mem_write8(0x86D7, a);
  p05_L_6BB3();
  return;
  lab_p05_L_6344: ;
  b = 0x31;
  p05_L_6FAE();
  if (flag_z()) goto lab_p05_L_634F;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_6354;
  a = (uint8_t)(a - 1);
  lab_p05_L_634F: ;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_6354;
  b = 0x49;
  lab_p05_L_6354: ;
  a = b;
  mem_write8(0x86D7, a);
  p05_L_6BB3();
  return;
}

/* flash page 5 cpu 0x635B (offset 0x235B) */
void p05_L_635B(void) {
  set_hl(0x0007);
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_636C;
  set_hl(0x3830);
  mem_write16(0x86D7, hl());
  set_hl(0x0807);
  lab_p05_L_636C: ;
  mem_write16(0x844B, hl());
  return;
}

/* flash page 5 cpu 0x6370 (offset 0x2370) */
void p05_L_6370(void) {
  p00_L_18B7();
  if (flag_z()) { p05_L_637C(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x1D)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p05_L_6408;
  p05_L_637C();
  return;
  lab_p05_L_6408: ;
  p05_L_6FB2();
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 2)));
  p05_L_635B();
  p00_L_3D1D();
  p05_L_6891();
  if (flag_z()) goto lab_p05_L_6FF1;
  a = mem_read8(0x91DB);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p05_L_647B;
  a = mem_read8((uint16_t)(iy + 0x02));
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p05_L_646F;
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p05_L_6473;
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p05_L_6477;
  a = 0x58;
  lab_p05_L_6433: ;
  p05_L_64AD();
  a = 0x3D;
  p05_L_64AD();
  p00_L_3CC9();
  p05_L_6830();
  if (flag_c()) goto lab_p05_L_6461;
  if (flag_nz()) goto lab_p05_L_6449;
  lab_p05_L_6445: ;
  p05_L_6BD3();
  return;
  lab_p05_L_6449: ;
  a = 0x09;
  p00_L_019D();
  if (flag_nz()) goto lab_p05_L_6451;
  a = (uint8_t)(a + 1);
  lab_p05_L_6451: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p05_L_649E;
  p05_L_6876();
  if (flag_z()) goto lab_p05_L_649E;
  p05_L_5663();
  lab_p05_L_645F: ;
  goto lab_p05_L_64A1;
  lab_p05_L_6461: ;
  set_hl(0x261F);
  a = 0x48;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p05_L_645F;
  lab_p05_L_646F: ;
  a = 0x01;
  goto lab_p05_L_6433;
  lab_p05_L_6473: ;
  a = 0x54;
  goto lab_p05_L_6433;
  lab_p05_L_6477: ;
  a = 0x5B;
  goto lab_p05_L_6433;
  lab_p05_L_647B: ;
  p05_L_652D();
  p05_L_6671();
  a = 0x3D;
  p05_L_64AD();
  p00_L_3CC9();
  p05_L_6830();
  if (flag_c()) goto lab_p05_L_6461;
  if (flag_z()) goto lab_p05_L_6445;
  a = 0x07;
  p00_L_019D();
  if (flag_nz()) goto lab_p05_L_649E;
  a = (uint8_t)(a + 1);
  p05_L_5EE1();
  if (flag_nz()) goto lab_p05_L_649E;
  a = (uint8_t)(a + 1);
  lab_p05_L_649E: ;
  p05_L_5665();
  lab_p05_L_64A1: ;
  p05_L_67C4();
  return;
  lab_p05_L_6FF1: ;
  p05_L_652D();
  if (flag_z()) return;
  p05_L_6671();
  p00_rst10();
  a = 0x3D;
  p00_L_3D47();
  p00_L_3183();
  cpu_ex_de_hl();
  lab_p05_L_7002: ;
  cpu_push_de();
  p00_L_315F();
  if (flag_z()) goto lab_p05_L_7017;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p00_L_3DAD();
  b = a;
  set_hl((uint16_t)(hl() + 1));
  p00_L_3D5F();
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_nc()) return;
  goto lab_p05_L_7002;
  lab_p05_L_7017: ;
  cpu_pop_de();
  return;
}

/* flash page 5 cpu 0x637C (offset 0x237C) */
void p05_L_637C(void) {
  p05_L_635B();
  p05_L_6891();
  if (flag_z()) goto lab_p05_L_6FDD;
  a = mem_read8(0x91DB);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p05_L_63DF;
  a = mem_read8((uint16_t)(iy + 0x02));
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p05_L_63D3;
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p05_L_63D7;
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p05_L_63DB;
  a = 0x58;
  lab_p05_L_639C: ;
  p00_L_3F9F();
  a = 0x3D;
  p00_L_3F9F();
  p00_L_3CC9();
  p05_L_6830();
  if (flag_c()) goto lab_p05_L_63C5;
  if (flag_nz()) goto lab_p05_L_63B2;
  lab_p05_L_63AE: ;
  p00_L_3D1D();
  return;
  lab_p05_L_63B2: ;
  a = 0x0E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x15)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p05_L_6402;
  p05_L_6876();
  if (flag_z()) goto lab_p05_L_6402;
  p05_L_5663();
  lab_p05_L_63C2: ;
  p05_L_55C2();
  return;
  lab_p05_L_63C5: ;
  set_hl(0x261F);
  a = 0x48;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p05_L_63C2;
  lab_p05_L_63D3: ;
  a = 0x01;
  goto lab_p05_L_639C;
  lab_p05_L_63D7: ;
  a = 0x54;
  goto lab_p05_L_639C;
  lab_p05_L_63DB: ;
  a = 0x5B;
  goto lab_p05_L_639C;
  lab_p05_L_63DF: ;
  p05_L_65A8();
  p05_L_665C();
  a = 0x3D;
  p00_L_3F9F();
  p00_L_3CC9();
  p05_L_6830();
  if (flag_c()) goto lab_p05_L_63C5;
  if (flag_z()) goto lab_p05_L_63AE;
  a = 0x0B;
  p00_L_019D();
  if (flag_nz()) goto lab_p05_L_6402;
  a = (uint8_t)(a + 1);
  p05_L_5EE1();
  if (flag_nz()) goto lab_p05_L_6402;
  a = (uint8_t)(a + 1);
  lab_p05_L_6402: ;
  p05_L_5665();
  p05_L_55C2();
  return;
  lab_p05_L_6FDD: ;
  p05_L_65A8();
  if (flag_z()) return;
  a = mem_read8(0x847A);
  p00_L_317D();
  p00_L_3CC9();
  p00_L_3183();
  p05_L_6BDB();
  return;
}

/* flash page 5 cpu 0x64AD (offset 0x24AD) */
void p05_L_64AD(void) {
  p00_L_3D47();
  return;
}

/* flash page 5 cpu 0x64B1 (offset 0x24B1) */
void p05_L_64B1(void) {
  a = mem_read8(0x97A5);
  l = a;
  h = 0x02;
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_64BE;
  h = 0x09;
  lab_p05_L_64BE: ;
  mem_write16(0x844B, hl());
  a = mem_read8((uint16_t)(iy + 0x02));
  flag_set_z((a & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p05_L_64EB;
  flag_set_z((a & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p05_L_64EF;
  flag_set_z((a & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p05_L_650E;
  a = 0x58;
  lab_p05_L_64D2: ;
  p05_L_6516();
  p05_L_652D();
  if (flag_z()) return;
  p05_L_6635();
  p00_L_18B7();
  if (flag_nz()) return;
  p00_L_3513();
  if (flag_z()) return;
  lab_p05_L_64E4: ;
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 0)));
  p05_L_665C();
  return;
  lab_p05_L_64EB: ;
  a = 0x01;
  goto lab_p05_L_64D2;
  lab_p05_L_64EF: ;
  a = 0x54;
  p05_L_6FAE();
  if (flag_z()) p05_L_6516();
  p05_L_652D();
  if (flag_z()) return;
  p05_L_6635();
  p05_L_6FAE();
  if (flag_nz()) goto lab_p05_L_6507;
  p00_L_18B7();
  if (flag_nz()) return;
  lab_p05_L_6507: ;
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  goto lab_p05_L_64E4;
  lab_p05_L_650E: ;
  a = 0x5B;
  goto lab_p05_L_64D2;
}

/* flash page 5 cpu 0x6512 (offset 0x2512) */
void p05_L_6512(void) {
  a = 0x0C;
  goto lab_p05_L_6529;
  lab_p05_L_6529: ;
  mem_write8(0x844C, a);
  return;
}

/* flash page 5 cpu 0x6516 (offset 0x2516) */
void p05_L_6516(void) {
  p00_L_3F9F();
  p05_L_6519();
  return;
}

/* flash page 5 cpu 0x6519 (offset 0x2519) */
void p05_L_6519(void) {
  a = 0x06;
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_6529;
  a = 0x0D;
  p00_L_019D();
  if (flag_z()) goto lab_p05_L_6529;
  a = 0x0C;
  lab_p05_L_6529: ;
  mem_write8(0x844C, a);
  return;
}

/* flash page 5 cpu 0x652D (offset 0x252D) */
void p05_L_652D(void) {
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_654B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 2)) == 0);
  if (flag_z()) goto lab_p05_L_654B;
  p00_L_128A();
  a = 0x03;
  mem_write8(0x8478, a);
  set_hl(mem_read16(0x92AF));
  mem_write16(0x8479, hl());
  a = mem_read8(0x92AE);
  a = a | a;
  flag_logic(a);
  return;
  lab_p05_L_654B: ;
  a = mem_read8(0x91DD);
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p05_L_655C;
  p00_L_18B7();
  if (flag_z()) { p05_L_6569(); return; }
  a = 0x01;
  mem_write8(0x91DD, a);
  lab_p05_L_655C: ;
  p05_L_65A8();
  set_hl(mem_read16(0x8479));
  mem_write16(0x92AF, hl());
  mem_write8(0x92AE, a);
  return;
}

/* flash page 5 cpu 0x6569 (offset 0x2569) */
void p05_L_6569(void) {
  p00_L_33F3();
  a = mem_read8(0x91DB);
  p05_L_5EE1();
  if (flag_nz()) goto lab_p05_L_657C;
  p05_L_6574();
  return;
  lab_p05_L_657C: ;
  /* srl a */
  if (flag_c()) goto lab_p05_L_6588;
  a = (uint8_t)(a - 1);
  p05_L_6696();
  /* sla a */
  a = (uint8_t)(a - 1);
  return;
  lab_p05_L_6588: ;
  a = (uint8_t)(a + 1);
  p05_L_6574();
  if (flag_z()) return;
  /* sla a */
  return;
}

/* flash page 5 cpu 0x6574 (offset 0x2574) */
void p05_L_6574(void) {
  p00_L_33F9();
  p05_L_5EDA();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x6590 (offset 0x2590) */
void p05_L_6590(void) {
  p05_L_5EE1();
  if (flag_z()) return;
  set_hl(0x91DB);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_z()) return;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  return;
}

/* flash page 5 cpu 0x659C (offset 0x259C) */
void p05_L_659C(void) {
  p05_L_5EE1();
  if (flag_z()) return;
  set_hl(0x91DB);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_nz()) return;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  return;
}

/* flash page 5 cpu 0x65A8 (offset 0x25A8) */
void p05_L_65A8(void) {
  p05_L_6FB2();
  if (flag_z()) goto lab_p05_L_65C0;
  p00_L_334B();
  p05_L_6DB5();
  if (flag_z()) goto lab_p05_L_65BB;
  a = mem_read8(0x91CE);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_65BF;
  lab_p05_L_65BB: ;
  a = mem_read8(0x8D1B);
  a = a | a;
  flag_logic(a);
  lab_p05_L_65BF: ;
  return;
  lab_p05_L_65C0: ;
  p00_L_33F3();
  p05_L_688C();
  if (flag_z()) goto lab_p05_L_65C9;
  a = (uint8_t)(a - 1);
  lab_p05_L_65C9: ;
  p05_L_5EE1();
  if (flag_z()) goto lab_p05_L_65EB;
  /* srl a */
  p00_L_3513();
  p05_L_5EDA();
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  p05_L_688C();
  if (flag_nz()) goto lab_p05_L_65DF;
  a = (uint8_t)(a + 1);
  return;
  lab_p05_L_65DF: ;
  a = (uint8_t)(a - 1);
  a = a & 0x01;
  flag_logic(a);
  set_hl(0x847A);
  /* or (hl) */
  mem_write8(hl(), a);
  p05_L_688C();
  return;
  lab_p05_L_65EB: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p05_L_662D;
  cpu_push_af();
  p00_L_38E5();
  set_hl(mem_read16(0x980C));
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p05_L_65FE;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 1)));
  lab_p05_L_65FE: ;
  flag_set_z((a & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p05_L_6604;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 2)));
  lab_p05_L_6604: ;
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p05_L_660A;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 3)));
  lab_p05_L_660A: ;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_662C;
  a = 0x03;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p05_L_6623;
  a = (uint8_t)(a + a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p05_L_6623;
  a = (uint8_t)(a - 1);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p05_L_662C;
  lab_p05_L_6623: ;
  set_hl(0x91CE);
  b = a;
  /* and (hl) */
  flag_cmp(a, b);
  if (flag_nz()) { p00_L_24FD(); return; }
  lab_p05_L_662C: ;
  cpu_pop_af();
  lab_p05_L_662D: ;
  p00_L_3513();
  p05_L_5EDA();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x6635 (offset 0x2635) */
void p05_L_6635(void) {
  cpu_push_af();
  p05_L_664E();
  p05_L_665C();
  p05_L_6FAE();
  if (flag_z()) goto lab_p05_L_6646;
  p05_L_6519();
  goto lab_p05_L_664C;
  lab_p05_L_6646: ;
  p00_L_18B7();
  if (flag_z()) p05_L_6512();
  lab_p05_L_664C: ;
  cpu_pop_af();
  return;
}

/* flash page 5 cpu 0x664E (offset 0x264E) */
void p05_L_664E(void) {
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_6657;
  p00_L_019D();
  if (flag_nz()) return;
  lab_p05_L_6657: ;
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 0)));
  return;
}

/* flash page 5 cpu 0x665C (offset 0x265C) */
void p05_L_665C(void) {
  set_de(mem_read16(0x8479));
  a = e;
  e = d;
  d = a;
  p05_L_6663();
  return;
}

/* flash page 5 cpu 0x6663 (offset 0x2663) */
void p05_L_6663(void) {
  p00_L_3459();
  p00_L_019D();
  if (flag_z()) return;
  set_hl(0x2690);
  p00_L_3C87();
  return;
}

/* flash page 5 cpu 0x6671 (offset 0x2671) */
void p05_L_6671(void) {
  set_de(mem_read16(0x8479));
  a = e;
  e = d;
  d = a;
  p00_L_3DAD();
  b = a;
  set_hl((uint16_t)(hl() + 1));
  p00_L_3D53();
  p00_L_019D();
  if (flag_z()) return;
  set_hl(0x2690);
  p00_L_3D4D();
  return;
}

/* flash page 5 cpu 0x668B (offset 0x268B) */
void p05_L_668B(void) {
  p00_L_33F3();
  a = mem_read8(0x91DB);
  p05_L_5EE1();
  if (flag_nz()) goto lab_p05_L_669E;
  p05_L_6696();
  return;
  lab_p05_L_669E: ;
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p05_L_66AC;
  /* srl a */
  p05_L_6696();
  if (flag_z()) return;
  /* sla a */
  a = (uint8_t)(a - 1);
  return;
  lab_p05_L_66AC: ;
  a = (uint8_t)(a - 1);
  /* srl a */
  p05_L_6696();
  if (flag_z()) return;
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 0)));
  /* sla a */
  return;
}

/* flash page 5 cpu 0x6696 (offset 0x2696) */
void p05_L_6696(void) {
  p00_L_3513();
  p05_L_5EDA();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x66BB (offset 0x26BB) */
void p05_L_66BB(void) {
  set_hl(mem_read16(0x91DD));
  cpu_push_hl();
  p05_L_6FAE();
  if (flag_nz()) goto lab_p05_L_66CB;
  set_de(0x91E2);
  a = 0;
  flag_logic(a);
  p05_L_66EA();
  lab_p05_L_66CB: ;
  set_de(0x9221);
  a = 0x01;
  p05_L_66EA();
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_66DD;
  p05_L_6FAE();
  if (flag_z()) goto lab_p05_L_66E5;
  lab_p05_L_66DD: ;
  set_de(0x9260);
  a = 0x02;
  p05_L_66EA();
  lab_p05_L_66E5: ;
  cpu_pop_hl();
  mem_write16(0x91DD, hl());
  return;
}

/* flash page 5 cpu 0x66EA (offset 0x26EA) */
void p05_L_66EA(void) {
  mem_write8(0x91DD, a);
  p05_L_5E84();
  set_hl((uint16_t)(hl() + de()));
  p00_rst20();
  p05_L_6254();
  return;
}

/* flash page 5 cpu 0x66F6 (offset 0x26F6) */
void p05_L_66F6(void) {
  set_hl(mem_read16(0x91DD));
  cpu_push_hl();
  set_hl(mem_read16(0x91DB));
  cpu_push_hl();
  p05_L_6710();
  p05_L_6752();
  p05_L_675A();
  p05_L_6707();
  return;
}

/* flash page 5 cpu 0x6707 (offset 0x2707) */
void p05_L_6707(void) {
  cpu_pop_hl();
  mem_write16(0x91DB, hl());
  cpu_pop_hl();
  mem_write16(0x91DD, hl());
  return;
}

/* flash page 5 cpu 0x6710 (offset 0x2710) */
void p05_L_6710(void) {
  p05_L_6FAE();
  if (flag_nz()) return;
  set_hl(0x91E2);
  set_de(0x0000);
  p00_L_18B7();
  if (flag_nz()) goto lab_p05_L_6782;
  b = 0x07;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_6729;
  b = 0x02;
  lab_p05_L_6729: ;
  /* ld ix,(0x91DC) */
  cpu_push16(ix);
  mem_write16(0x91DC, de());
  lab_p05_L_6733: ;
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x91DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_6312();
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p05_L_6834();
  if (flag_c()) goto lab_p05_L_6746;
  if (flag_z()) goto lab_p05_L_6749;
  lab_p05_L_6746: ;
  p05_L_67EE();
  lab_p05_L_6749: ;
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_6733;
  cpu_pop_hl();
  mem_write16(0x91DC, hl());
  return;
  lab_p05_L_6782: ;
  b = 0x07;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_678C;
  b = 0x02;
  lab_p05_L_678C: ;
  /* ld ix,(0x91DC) */
  cpu_push16(ix);
  mem_write16(0x91DC, de());
  lab_p05_L_6796: ;
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x91DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_6312();
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p05_L_6834();
  p05_L_67B4();
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_6796;
  cpu_pop_hl();
  mem_write16(0x91DC, hl());
  return;
}

/* flash page 5 cpu 0x6752 (offset 0x2752) */
void p05_L_6752(void) {
  goto lab_p05_L_6752;
  lab_p05_L_671A: ;
  p00_L_18B7();
  if (flag_nz()) goto lab_p05_L_6782;
  b = 0x07;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_6729;
  b = 0x02;
  lab_p05_L_6729: ;
  /* ld ix,(0x91DC) */
  cpu_push16(ix);
  mem_write16(0x91DC, de());
  lab_p05_L_6733: ;
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x91DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_6312();
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p05_L_6834();
  if (flag_c()) goto lab_p05_L_6746;
  if (flag_z()) goto lab_p05_L_6749;
  lab_p05_L_6746: ;
  p05_L_67EE();
  lab_p05_L_6749: ;
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_6733;
  cpu_pop_hl();
  mem_write16(0x91DC, hl());
  return;
  lab_p05_L_6752: ;
  set_hl(0x9221);
  set_de(0x0100);
  goto lab_p05_L_671A;
  lab_p05_L_6782: ;
  b = 0x07;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_678C;
  b = 0x02;
  lab_p05_L_678C: ;
  /* ld ix,(0x91DC) */
  cpu_push16(ix);
  mem_write16(0x91DC, de());
  lab_p05_L_6796: ;
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x91DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_6312();
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p05_L_6834();
  p05_L_67B4();
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_6796;
  cpu_pop_hl();
  mem_write16(0x91DC, hl());
  return;
}

/* flash page 5 cpu 0x675A (offset 0x275A) */
void p05_L_675A(void) {
  goto lab_p05_L_675A;
  lab_p05_L_671A: ;
  p00_L_18B7();
  if (flag_nz()) goto lab_p05_L_6782;
  b = 0x07;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_6729;
  b = 0x02;
  lab_p05_L_6729: ;
  /* ld ix,(0x91DC) */
  cpu_push16(ix);
  mem_write16(0x91DC, de());
  lab_p05_L_6733: ;
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x91DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_6312();
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p05_L_6834();
  if (flag_c()) goto lab_p05_L_6746;
  if (flag_z()) goto lab_p05_L_6749;
  lab_p05_L_6746: ;
  p05_L_67EE();
  lab_p05_L_6749: ;
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_6733;
  cpu_pop_hl();
  mem_write16(0x91DC, hl());
  return;
  lab_p05_L_675A: ;
  set_hl(0x9260);
  set_de(0x0200);
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_671A;
  p05_L_6FAE();
  if (flag_nz()) goto lab_p05_L_671A;
  return;
  lab_p05_L_6782: ;
  b = 0x07;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_678C;
  b = 0x02;
  lab_p05_L_678C: ;
  /* ld ix,(0x91DC) */
  cpu_push16(ix);
  mem_write16(0x91DC, de());
  lab_p05_L_6796: ;
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x91DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_6312();
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p05_L_6834();
  p05_L_67B4();
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_6796;
  cpu_pop_hl();
  mem_write16(0x91DC, hl());
  return;
}

/* flash page 5 cpu 0x676B (offset 0x276B) */
void p05_L_676B(void) {
  set_hl(0x9221);
  set_de(0x0100);
  goto lab_p05_L_6782;
  lab_p05_L_6782: ;
  b = 0x07;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_678C;
  b = 0x02;
  lab_p05_L_678C: ;
  /* ld ix,(0x91DC) */
  cpu_push16(ix);
  mem_write16(0x91DC, de());
  lab_p05_L_6796: ;
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x91DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_6312();
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p05_L_6834();
  p05_L_67B4();
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_6796;
  cpu_pop_hl();
  mem_write16(0x91DC, hl());
  return;
}

/* flash page 5 cpu 0x6773 (offset 0x2773) */
void p05_L_6773(void) {
  set_hl(0x9260);
  set_de(0x0200);
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_6782;
  p05_L_6FAE();
  if (flag_z()) return;
  lab_p05_L_6782: ;
  b = 0x07;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_678C;
  b = 0x02;
  lab_p05_L_678C: ;
  /* ld ix,(0x91DC) */
  cpu_push16(ix);
  mem_write16(0x91DC, de());
  lab_p05_L_6796: ;
  cpu_push_bc();
  cpu_push_hl();
  set_hl(0x91DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_6312();
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p05_L_6834();
  p05_L_67B4();
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_6796;
  cpu_pop_hl();
  mem_write16(0x91DC, hl());
  return;
}

/* flash page 5 cpu 0x67B1 (offset 0x27B1) */
void p05_L_67B1(void) {
  p05_L_6830();
  p05_L_67B4();
  return;
}

/* flash page 5 cpu 0x67B4 (offset 0x27B4) */
void p05_L_67B4(void) {
  if (flag_c()) goto lab_p05_L_67E9;
  if (flag_nz()) goto lab_p05_L_67C1;
  a = 0;
  flag_logic(a);
  mem_write8(0x848E, a);
  set_hl(0x848E);
  p05_L_67C4();
  return;
  lab_p05_L_67C1: ;
  p05_L_6825();
  p05_L_67C4();
  return;
  lab_p05_L_67E9: ;
  set_hl(0x261F);
  p05_L_67C4();
  return;
}

/* flash page 5 cpu 0x67C4 (offset 0x27C4) */
void p05_L_67C4(void) {
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 1)));
  p05_L_67C8();
  return;
}

/* flash page 5 cpu 0x67C8 (offset 0x27C8) */
void p05_L_67C8(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  set_de(mem_read16(0x844B));
  cpu_push_de();
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_67E1;
  lab_p05_L_67D5: ;
  a = mem_read8(hl());
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_67E1;
  p00_L_3D47();
  set_hl((uint16_t)(hl() + 1));
  if (flag_nc()) goto lab_p05_L_67D5;
  goto lab_p05_L_67E4;
  lab_p05_L_67E1: ;
  p05_L_6B86();
  lab_p05_L_67E4: ;
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 5 cpu 0x67EE (offset 0x27EE) */
void p05_L_67EE(void) {
  if (flag_c()) goto lab_p05_L_6820;
  p05_L_67F0();
  return;
  lab_p05_L_6820: ;
  set_hl(0x261F);
  p05_L_6814();
  return;
}

/* flash page 5 cpu 0x67F0 (offset 0x27F0) */
void p05_L_67F0(void) {
  p05_L_6825();
  a = mem_read8(0x8478);
  a = (uint8_t)(a - 0x0C);
  if (flag_nz()) { p05_L_6814(); return; }
  b = 0x07;
  p05_L_6BB9();
  if (flag_z()) goto lab_p05_L_6803;
  b = 0x06;
  lab_p05_L_6803: ;
  a = c;
  flag_cmp(a, b);
  if (flag_c()) { p05_L_6814(); return; }
  a = 0;
  flag_logic(a);
  mem_write8(0x97B6, a);
  p05_L_6814();
  a = 0xCE;
  p00_L_3D47();
  return;
}

/* flash page 5 cpu 0x6814 (offset 0x2814) */
void p05_L_6814(void) {
  mem_write8((uint16_t)(iy + 0x0E), (uint8_t)(mem_read8((uint16_t)(iy + 0x0E)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  p00_L_3D4D();
  return;
}

/* flash page 5 cpu 0x6825 (offset 0x2825) */
void p05_L_6825(void) {
  p05_L_6BB9();
  if (flag_z()) { p05_L_475E(); return; }
  a = 0x05;
  p05_L_4760();
  return;
}

/* flash page 5 cpu 0x6830 (offset 0x2830) */
void p05_L_6830(void) {
  p05_L_607D();
  p00_rst20();
  p05_L_6834();
  return;
}

/* flash page 5 cpu 0x6834 (offset 0x2834) */
void p05_L_6834(void) {
  a = mem_read8(0x8478);
  flag_cmp(a, 0xFF);
  if (flag_z()) goto lab_p05_L_684D;
  a = 0;
  flag_logic(a);
  set_hl(0x8478);
  set_bc(0x0009);
  lab_p05_L_6842: ;
  /* cpi */
  if (flag_nz()) goto lab_p05_L_684A;
  flag_cmp(a, c);
  if (flag_nz()) goto lab_p05_L_6842;
  return;
  lab_p05_L_684A: ;
  /* scf */
  /* ccf */
  return;
  lab_p05_L_684D: ;
  /* scf */
  return;
}

/* flash page 5 cpu 0x6876 (offset 0x2876) */
void p05_L_6876(void) {
  p05_L_6FB2();
  if (flag_nz()) goto lab_p05_L_688A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 4)) == 0);
  return;
  lab_p05_L_688A: ;
  flag_cmp(a, a);
  return;
}

/* flash page 5 cpu 0x6880 (offset 0x2880) */
void p05_L_6880(void) {
  p05_L_6FB2();
  if (flag_nz()) goto lab_p05_L_688A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 5)) == 0);
  return;
  lab_p05_L_688A: ;
  flag_cmp(a, a);
  return;
}

/* flash page 5 cpu 0x688C (offset 0x288C) */
void p05_L_688C(void) {
  a = mem_read8(0x91DB);
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x6891 (offset 0x2891) */
void p05_L_6891(void) {
  a = mem_read8(0x91DC);
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x6896 (offset 0x2896) */
void p05_L_6896(void) {
  set_hl(0x970B);
  a = mem_read8(hl());
  goto lab_p05_L_689F;
  lab_p05_L_689F: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_68A8;
  flag_cmp(a, 0x02);
  return;
  lab_p05_L_68A8: ;
  flag_cmp(a, 0x07);
  return;
}

/* flash page 5 cpu 0x689C (offset 0x289C) */
void p05_L_689C(void) {
  a = mem_read8(0x91DC);
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 0)) == 0);
  if (flag_z()) goto lab_p05_L_68A8;
  flag_cmp(a, 0x02);
  return;
  lab_p05_L_68A8: ;
  flag_cmp(a, 0x07);
  return;
}

/* flash page 5 cpu 0x68AB (offset 0x28AB) */
void p05_L_68AB(void) {
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p05_L_68F1;
  p05_L_688C();
  if (flag_nz()) goto lab_p05_L_68DD;
  p05_L_6876();
  if (flag_z()) return;
  p05_L_68B8();
  return;
  lab_p05_L_68DD: ;
  p05_L_6891();
  if (flag_z()) { p05_L_6C02(); return; }
  p05_L_6880();
  if (flag_z()) return;
  p05_L_65A8();
  if (flag_nz()) p05_L_60A0();
  p05_L_61E2();
  return;
  lab_p05_L_68F1: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p05_L_6934;
  p05_L_68F5();
  return;
  lab_p05_L_6934: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p05_L_6973;
  p05_L_6938();
  return;
  lab_p05_L_6973: ;
  set_hl(0x91DC);
  flag_cmp(a, 0x0F);
  if (flag_z()) goto lab_p05_L_697E;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p05_L_69D9;
  lab_p05_L_697E: ;
  p05_L_668B();
  if (flag_z()) return;
  b = a;
  a = mem_read8(0x91DD);
  flag_cmp(a, 0x02);
  if (flag_nc()) goto lab_p05_L_69A1;
  p00_L_18B7();
  if (flag_z()) goto lab_p05_L_6993;
  flag_cmp(a, 0x01);
  if (flag_nc()) goto lab_p05_L_69A1;
  lab_p05_L_6993: ;
  p05_L_6254();
  a = b;
  mem_write8(0x91DB, a);
  set_hl(0x91DD);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_61E2();
  return;
  lab_p05_L_69A1: ;
  a = b;
  mem_write8(0x91DB, a);
  p05_L_5EE1();
  if (flag_z()) goto lab_p05_L_69C0;
  p05_L_5CE2();
  a = 0x01;
  mem_write8(0x91DD, a);
  p05_L_5F31();
  p05_L_5F01();
  a = 0x01;
  mem_write8(0x91DD, a);
  p05_L_6201();
  return;
  lab_p05_L_69C0: ;
  set_hl(0x9221);
  p00_L_18B7();
  if (flag_nz()) goto lab_p05_L_69CE;
  p05_L_5D75();
  set_hl(0x9260);
  lab_p05_L_69CE: ;
  b = 0x3F;
  p05_L_5CEC();
  p05_L_5F31();
  p05_L_6201();
  return;
  lab_p05_L_69D9: ;
  flag_cmp(a, 0x0E);
  if (flag_z()) goto lab_p05_L_69E1;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p05_L_6A42;
  lab_p05_L_69E1: ;
  p05_L_688C();
  if (flag_z()) return;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p05_L_69ED;
  p05_L_6891();
  if (flag_z()) return;
  lab_p05_L_69ED: ;
  p05_L_6569();
  b = a;
  if (flag_nz()) goto lab_p05_L_69F9;
  p05_L_6891();
  if (flag_z()) return;
  goto lab_p05_L_6A00;
  lab_p05_L_69F9: ;
  a = mem_read8(0x91DD);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p05_L_6A0E;
  lab_p05_L_6A00: ;
  p05_L_6254();
  a = b;
  mem_write8(0x91DB, a);
  set_hl(0x91DD);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p05_L_61E2();
  return;
  lab_p05_L_6A0E: ;
  a = b;
  mem_write8(0x91DB, a);
  p05_L_5EE1();
  if (flag_z()) goto lab_p05_L_6A3A;
  p00_L_18B7();
  if (flag_nz()) goto lab_p05_L_6A3A;
  p05_L_5CE2();
  a = 0x01;
  mem_write8(0x91DD, a);
  set_hl(0x91DB);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p05_L_5F31();
  p05_L_5F01();
  set_hl(0x91DB);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = 0x02;
  mem_write8(0x91DD, a);
  p05_L_6201();
  return;
  lab_p05_L_6A3A: ;
  p05_L_5D6D();
  set_hl(0x9221);
  goto lab_p05_L_69CE;
  lab_p05_L_6A42: ;
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p05_L_6A5C;
  p05_L_6876();
  if (flag_z()) return;
  p05_L_6891();
  if (flag_z()) return;
  p05_L_6240();
  if (flag_c()) return;
  p05_L_5E10();
  set_hl(0x91E0);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p05_L_61D3();
  return;
  lab_p05_L_6A5C: ;
  flag_cmp(a, 0x0B);
  if (flag_nz()) goto lab_p05_L_6A7B;
  p05_L_6876();
  if (flag_z()) return;
  p05_L_6891();
  if (flag_z()) return;
  p05_L_5DB7();
  set_hl(0x91E0);
  a = 0x06;
  cpu_cp_hl();
  if (flag_c()) goto lab_p05_L_6A75;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p05_L_6A75: ;
  p05_L_5CF2();
  p05_L_61D3();
  return;
  lab_p05_L_6A7B: ;
  flag_cmp(a, 0x0C);
  if (flag_z()) return;
  flag_cmp(a, 0x8A);
  if (flag_z()) return;
  flag_cmp(a, 0x27);
  if (flag_z()) { p05_L_5B1D(); return; }
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p05_L_6AA9;
  cpu_push_af();
  p05_L_688C();
  if (flag_z()) goto lab_p05_L_6ABE;
  p05_L_6891();
  if (flag_z()) goto lab_p05_L_6C30;
  p05_L_6880();
  if (flag_z()) goto lab_p05_L_6ABC;
  p05_L_6056();
  p05_L_607D();
  p05_L_5CEA();
  p05_L_61E2();
  goto lab_p05_L_6ABC;
  lab_p05_L_6AA9: ;
  flag_cmp(a, 0x0D);
  if (flag_z()) goto lab_p05_L_6AB0;
  flag_cmp(a, 0x5A);
  if (flag_c()) return;
  lab_p05_L_6AB0: ;
  cpu_push_af();
  p05_L_688C();
  if (flag_z()) goto lab_p05_L_6ABE;
  p05_L_6891();
  if (flag_z()) goto lab_p05_L_6C30;
  lab_p05_L_6ABC: ;
  cpu_pop_af();
  return;
  lab_p05_L_6ABE: ;
  p05_L_6876();
  if (flag_z()) goto lab_p05_L_6ABC;
  p05_L_68B8();
  cpu_pop_af();
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p05_L_6ACF;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p05_L_6AF8;
  lab_p05_L_6ACF: ;
  p00_L_1916();
  if (flag_nz()) goto lab_p05_L_6AD9;
  p05_L_5687();
  goto lab_p05_L_6ADF;
  lab_p05_L_6AD9: ;
  p05_L_6B36();
  p05_L_5CF2();
  lab_p05_L_6ADF: ;
  p05_L_5B6F();
  p05_L_66BB();
  p05_L_689C();
  if (flag_nc()) goto lab_p05_L_6AF2;
  p05_L_6240();
  if (flag_c()) p05_L_6250();
  goto lab_p05_L_6AF5;
  lab_p05_L_6AF2: ;
  p05_L_61E2();
  lab_p05_L_6AF5: ;
  p05_L_6938();
  return;
  lab_p05_L_6AF8: ;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p05_L_6B25;
  p00_L_1916();
  if (flag_nz()) goto lab_p05_L_6B0E;
  p05_L_5687();
  a = mem_read8(0x91DC);
  flag_cmp(a, 0x02);
  if (flag_c()) p05_L_6370();
  goto lab_p05_L_6B14;
  lab_p05_L_6B0E: ;
  p05_L_6B36();
  p05_L_5CF2();
  lab_p05_L_6B14: ;
  p05_L_5B6F();
  p05_L_66BB();
  a = mem_read8(0x91DC);
  flag_cmp(a, 0x02);
  if (flag_c()) p05_L_6250();
  p05_L_68F5();
  return;
  lab_p05_L_6B25: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p05_L_6B2E;
  flag_cmp(a, 0x8A);
  if (flag_z()) return;
  lab_p05_L_6B2E: ;
  flag_cmp(a, 0x27);
  if (flag_nz()) { p00_L_3777(); return; }
  p05_L_5B1D();
  return;
  lab_p05_L_6C30: ;
  p05_L_6C02();
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 7)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x13)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p05_L_6DC0;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p05_L_6D15;
  p05_L_6D19();
  return;
  lab_p05_L_6D15: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p05_L_6D24;
  p05_L_6D19();
  return;
  lab_p05_L_6D24: ;
  flag_cmp(a, 0x03);
  if (flag_z()) return;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p05_L_6D43;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 4)));
  p00_L_3BD3();
  if (flag_nz()) { p00_L_377D(); return; }
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 6)));
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) | (1u << 0)));
  set_hl(0x844C);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  return;
  lab_p05_L_6D43: ;
  flag_cmp(a, 0x0C);
  if (flag_nz()) goto lab_p05_L_6D5D;
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
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) | (1u << 7)));
  p00_L_316B();
  return;
  lab_p05_L_6D5D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0E)) & (1u << 7)) == 0);
  if (flag_nz()) goto lab_p05_L_6D66;
  flag_cmp(a, 0x8A);
  if (flag_z()) return;
  lab_p05_L_6D66: ;
  flag_cmp(a, 0x27);
  if (flag_nz()) goto lab_p05_L_6D70;
  p05_L_57FC();
  p05_L_5B20();
  return;
  lab_p05_L_6D70: ;
  p00_L_375F();
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p05_L_6D7D;
  c = 0x00;
  lab_p05_L_6D79: ;
  p00_L_3171();
  return;
  lab_p05_L_6D7D: ;
  flag_cmp(a, 0x0D);
  if (flag_nz()) goto lab_p05_L_6D89;
  lab_p05_L_6D82: ;
  p00_L_009B();
  c = 0x01;
  goto lab_p05_L_6D79;
  lab_p05_L_6D89: ;
  flag_cmp(a, 0x0A);
  if (flag_nz()) goto lab_p05_L_6D94;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 5)) == 0);
  if (flag_z()) return;
  goto lab_p05_L_6D82;
  lab_p05_L_6D94: ;
  flag_cmp(a, 0x5A);
  if (flag_c()) return;
  flag_cmp(a, 0x3E);
  if (flag_z()) return;
  goto lab_p05_L_6D82;
  lab_p05_L_6DC0: ;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p05_L_6DD6;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 5)));
  set_hl(mem_read16(0x9706));
  c = 0x01;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p05_L_6DD2;
  c = (uint8_t)(c - 1);
  lab_p05_L_6DD2: ;
  p00_L_3171();
  return;
  lab_p05_L_6DD6: ;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p05_L_6DE3;
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 0)));
  p05_L_6DDE();
  return;
  lab_p05_L_6DE3: ;
  flag_cmp(a, 0x04);
  if (flag_nz()) return;
  p05_L_6DDE();
  p05_L_6D19();
  return;
}

/* flash page 5 cpu 0x68B8 (offset 0x28B8) */
void p05_L_68B8(void) {
  p00_L_18B7();
  if (flag_nz()) p05_L_637C();
  set_hl(0x685C);
  p00_L_07CC();
  p05_L_635B();
  p00_L_374D();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  p05_L_6830();
  if (flag_c()) goto lab_p05_L_68D9;
  if (flag_z()) goto lab_p05_L_68D9;
  p00_L_3735();
  return;
  lab_p05_L_68D9: ;
  p00_L_3741();
  return;
}

/* flash page 5 cpu 0x68F5 (offset 0x28F5) */
void p05_L_68F5(void) {
  set_hl(0x91DC);
  a = mem_read8(hl());
  flag_cmp(a, 0x01);
  if (flag_c()) return;
  if (flag_nz()) goto lab_p05_L_6903;
  p05_L_688C();
  if (flag_z()) goto lab_p05_L_690D;
  lab_p05_L_6903: ;
  p05_L_6254();
  set_hl(0x91DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  p05_L_61E2();
  return;
  lab_p05_L_690D: ;
  p05_L_6876();
  if (flag_nz()) return;
  p05_L_6E04();
  if (flag_c()) return;
  p05_L_6254();
  p00_L_31CB();
  p05_L_5D81();
  set_hl(0x92B3);
  p00_rst20();
  set_de(0x91E2);
  p00_L_11FD();
  p05_L_66BB();
  p05_L_5CFB();
  p05_L_66BB();
  p05_L_61E2();
  return;
}

/* flash page 5 cpu 0x6938 (offset 0x2938) */
void p05_L_6938(void) {
  set_hl(0x91DC);
  p05_L_6876();
  if (flag_z()) goto lab_p05_L_6952;
  p05_L_6240();
  if (flag_c()) return;
  p05_L_689C();
  if (flag_nc()) return;
  lab_p05_L_6948: ;
  p05_L_6254();
  set_hl(0x91DC);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p05_L_61E2();
  return;
  lab_p05_L_6952: ;
  p05_L_689C();
  if (flag_c()) goto lab_p05_L_6948;
  p05_L_6DFB();
  if (flag_c()) return;
  p05_L_6254();
  p00_L_31D1();
  p05_L_5D9C();
  p05_L_5C80();
  p05_L_66BB();
  p05_L_5CFF();
  p05_L_66BB();
  p05_L_61E2();
  return;
}

/* flash page 5 cpu 0x6B36 (offset 0x2B36) */
void p05_L_6B36(void) {
  p00_L_1916();
  if (flag_nz()) goto lab_p05_L_6B3E;
  sp = (uint16_t)(sp + 1);
  sp = (uint16_t)(sp + 1);
  return;
  lab_p05_L_6B3E: ;
  set_hl(0x0615);
  p00_L_25A2();
  p05_L_6B60();
  p05_L_6248();
  if (flag_c()) goto lab_p05_L_6B4F;
  if (flag_z()) goto lab_p05_L_6B4F;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p05_L_6B4F: ;
  p05_L_6370();
  p00_L_25C8();
  return;
}

/* flash page 5 cpu 0x6B56 (offset 0x2B56) */
void p05_L_6B56(void) {
  p05_L_6B60();
  p05_L_6248();
  if (flag_c()) return;
  if (flag_z()) return;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  return;
}

/* flash page 5 cpu 0x6B60 (offset 0x2B60) */
void p05_L_6B60(void) {
  p00_L_002B();
  p05_L_58C6();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 5)) == 0);
  if (flag_z()) return;
  p00_L_1653();
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_187F();
  p05_L_6077();
  p05_L_607D();
  cpu_ex_de_hl();
  p00_L_11FD();
  p00_L_37CB();
  p05_L_5E9F();
  return;
}

/* flash page 5 cpu 0x6B86 (offset 0x2B86) */
void p05_L_6B86(void) {
  p05_L_6BB9();
  if (flag_nz()) goto lab_p05_L_6BC6;
  a = mem_read8(0x86D7);
  a = (uint8_t)(a - 0x1E);
  if (flag_c()) goto lab_p05_L_6B9B;
  if (flag_z()) return;
  a = (uint8_t)(a - 0x1E);
  if (flag_c()) goto lab_p05_L_6B9B;
  if (flag_z()) return;
  a = (uint8_t)(a - 0x1E);
  if (flag_nc()) return;
  lab_p05_L_6B9B: ;
  /* neg */
  b = a;
  b = (uint8_t)(b - 1);
  if (flag_z()) { p05_L_6BB3(); return; }
  lab_p05_L_6BA1: ;
  a = b;
  a = (uint8_t)(a - 0x04);
  if (flag_c()) goto lab_p05_L_6BAC;
  b = a;
  b = (uint8_t)(b + 1);
  a = 0x06;
  goto lab_p05_L_6BAE;
  lab_p05_L_6BAC: ;
  a = 0x20;
  lab_p05_L_6BAE: ;
  p00_L_3D47();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_6BA1;
  p05_L_6BB3();
  return;
  lab_p05_L_6BC6: ;
  a = mem_read8(0x86D7);
  a = (uint8_t)(a - 0x46);
  if (flag_c()) goto lab_p05_L_6B9B;
  if (flag_z()) return;
  a = (uint8_t)(a - 0x19);
  if (flag_c()) goto lab_p05_L_6B9B;
  if (flag_nc()) return;
  p05_L_6BD3();
  return;
}

/* flash page 5 cpu 0x6BB3 (offset 0x2BB3) */
void p05_L_6BB3(void) {
  a = 0x20;
  p00_L_3D47();
  return;
}

/* flash page 5 cpu 0x6BB9 (offset 0x2BB9) */
void p05_L_6BB9(void) {
  p00_L_18B7();
  if (flag_z()) return;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x43);
  if (flag_z()) return;
  flag_cmp(a, 0x42);
  return;
}

/* flash page 5 cpu 0x6BD3 (offset 0x2BD3) */
void p05_L_6BD3(void) {
  goto lab_p05_L_6BD3;
  lab_p05_L_6B9B: ;
  /* neg */
  b = a;
  b = (uint8_t)(b - 1);
  if (flag_z()) { p05_L_6BB3(); return; }
  lab_p05_L_6BA1: ;
  a = b;
  a = (uint8_t)(a - 0x04);
  if (flag_c()) goto lab_p05_L_6BAC;
  b = a;
  b = (uint8_t)(b + 1);
  a = 0x06;
  goto lab_p05_L_6BAE;
  lab_p05_L_6BAC: ;
  a = 0x20;
  lab_p05_L_6BAE: ;
  p00_L_3D47();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_6BA1;
  p05_L_6BB3();
  return;
  lab_p05_L_6BD3: ;
  a = mem_read8(0x86D7);
  a = (uint8_t)(a - 0x5F);
  if (flag_c()) goto lab_p05_L_6B9B;
  return;
}

/* flash page 5 cpu 0x6BDB (offset 0x2BDB) */
void p05_L_6BDB(void) {
  cpu_ex_de_hl();
  lab_p05_L_6BDC: ;
  cpu_push_de();
  p00_L_315F();
  if (flag_z()) goto lab_p05_L_6BEF;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p00_L_3DB9();
  p00_L_3C99();
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_c()) return;
  goto lab_p05_L_6BDC;
  lab_p05_L_6BEF: ;
  cpu_pop_de();
  a = mem_read8(0x844B);
  flag_cmp(a, 0x08);
  if (flag_c()) goto lab_p05_L_6BFE;
  set_hl(0x0F07);
  mem_write16(0x844B, hl());
  return;
  lab_p05_L_6BFE: ;
  p00_L_3D1D();
  return;
}

/* flash page 5 cpu 0x6C02 (offset 0x2C02) */
void p05_L_6C02(void) {
  p00_L_18B7();
  if (flag_nz()) p05_L_637C();
  set_hl(0x6869);
  p00_L_07CC();
  p05_L_635B();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 4)));
  p05_L_65A8();
  a = mem_read8(0x847A);
  mem_write8(0x9813, a);
  p00_L_3165();
  p00_L_37AD();
  p00_L_37A7();
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) & ~(1u << 0)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 5)));
  return;
}

/* flash page 5 cpu 0x6C47 (offset 0x2C47) */
void p05_L_6C47(void) {
  p05_L_6D9C();
  set_hl(mem_read16(0x9706));
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p05_L_6CEC;
  p05_L_6DB5();
  if (flag_nz()) goto lab_p05_L_6CEC;
  p05_L_6590();
  p05_L_668B();
  if (flag_z()) goto lab_p05_L_6CAD;
  mem_write8(0x91DB, a);
  lab_p05_L_6C63: ;
  a = mem_read8(0x91DD);
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p05_L_6C75;
  p05_L_5CE2();
  p05_L_6590();
  p05_L_5EE6();
  goto lab_p05_L_6CA0;
  lab_p05_L_6C75: ;
  p05_L_5CE2();
  p05_L_659C();
  a = mem_read8(0x91DB);
  cpu_push_af();
  p05_L_5F31();
  p05_L_5F01();
  cpu_pop_af();
  mem_write8(0x91DB, a);
  a = 0x01;
  mem_write8(0x91DD, a);
  lab_p05_L_6C8E: ;
  p05_L_5B6F();
  p05_L_62FE();
  p05_L_61E9();
  p05_L_64B1();
  p05_L_5A71();
  p05_L_66F6();
  return;
  lab_p05_L_6CA0: ;
  set_hl(0x9260);
  b = 0x3F;
  p05_L_5CEC();
  p05_L_5F31();
  goto lab_p05_L_6D0C;
  lab_p05_L_6CAD: ;
  p05_L_659C();
  p05_L_6569();
  mem_write8(0x91DB, a);
  if (flag_nz()) goto lab_p05_L_6CC1;
  p05_L_5B6F();
  p05_L_6FD8();
  p05_L_5B5C();
  return;
  lab_p05_L_6CC1: ;
  p05_L_5EE1();
  if (flag_nz()) goto lab_p05_L_6C63;
  a = mem_read8(0x91DD);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p05_L_6CDF;
  set_hl(0x9260);
  b = 0x3F;
  p05_L_5CEC();
  a = 0x01;
  mem_write8(0x91DD, a);
  p05_L_5F31();
  goto lab_p05_L_6CEA;
  lab_p05_L_6CDF: ;
  set_hl(0x9221);
  b = 0x3F;
  p05_L_5CEC();
  p05_L_5F31();
  lab_p05_L_6CEA: ;
  goto lab_p05_L_6C8E;
  lab_p05_L_6CEC: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p05_L_6D12;
  a = mem_read8(0x91DD);
  flag_cmp(a, 0x02);
  if (flag_c()) goto lab_p05_L_6D01;
  p05_L_5F31();
  p05_L_5EE6();
  goto lab_p05_L_6D0C;
  lab_p05_L_6D01: ;
  p05_L_5F31();
  p05_L_5F01();
  a = 0x01;
  mem_write8(0x91DD, a);
  lab_p05_L_6D0C: ;
  p05_L_5B6F();
  p05_L_6201();
  return;
  lab_p05_L_6D12: ;
  p05_L_5B6F();
  return;
}

/* flash page 5 cpu 0x6D19 (offset 0x2D19) */
void p05_L_6D19(void) {
  p05_L_6C47();
  a = mem_read8(0x91DB);
  a = a | a;
  flag_logic(a);
  if (flag_z()) return;
  p05_L_6D21();
  return;
}

/* flash page 5 cpu 0x6D21 (offset 0x2D21) */
void p05_L_6D21(void) {
  p05_L_6938();
  return;
}

/* flash page 5 cpu 0x6D9C (offset 0x2D9C) */
void p05_L_6D9C(void) {
  set_hl(mem_read16(0x9706));
  p05_L_6DB5();
  if (flag_nz()) goto lab_p05_L_6DA8;
  flag_set_z((mem_read8(hl()) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p05_L_6DAE;
  lab_p05_L_6DA8: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p05_L_6DB1;
  lab_p05_L_6DAE: ;
  p05_L_6FD8();
  lab_p05_L_6DB1: ;
  p00_L_3177();
  return;
}

/* flash page 5 cpu 0x6DB5 (offset 0x2DB5) */
void p05_L_6DB5(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x02)) & (1u << 7)) == 0);
  if (flag_z()) return;
  a = mem_read8((uint16_t)(iy + 0x0F));
  a = a & 0x1C;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x6DDE (offset 0x2DDE) */
void p05_L_6DDE(void) {
  set_hl(0x844C);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  return;
}

/* flash page 5 cpu 0x6DEC (offset 0x2DEC) */
void p05_L_6DEC(void) {
  set_de(0x8622);
  p00_L_101A();
  set_hl(0x92B3);
  set_de(0x862B);
  p00_L_1183();
  return;
}

/* flash page 5 cpu 0x6DFB (offset 0x2DFB) */
void p05_L_6DFB(void) {
  set_hl(0x8622);
  p00_rst20();
  p00_L_0C1B();
  p05_L_6E0B();
  return;
}

/* flash page 5 cpu 0x6E04 (offset 0x2E04) */
void p05_L_6E04(void) {
  set_hl(0x8622);
  p00_rst20();
  p00_L_0C2A();
  p05_L_6E0B();
  return;
}

/* flash page 5 cpu 0x6E05 (offset 0x2E05) */
void p05_L_6E05(void) {
  mem_write16(0xE786, hl());
  p00_L_0C2A();
  p05_L_6E0B();
  return;
}

/* flash page 5 cpu 0x6E0B (offset 0x2E0B) */
void p05_L_6E0B(void) {
  set_hl(0x6E43);
  p00_L_25A2();
  p00_L_15FB();
  p00_L_1171();
  set_hl(0x92BC);
  p00_L_11F8();
  p00_L_0D1F();
  p05_L_6FB2();
  if (flag_nz()) p00_L_3E37();
  set_hl(0x862B);
  p00_L_11F8();
  p00_rst30();
  p00_L_15FB();
  a = 0x1A;
  p00_L_3675();
  set_hl(0x84A4);
  set_de(0x8622);
  p00_L_1183();
  p00_L_25C8();
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 5 cpu 0x6E45 (offset 0x2E45) */
void p05_L_6E45(void) {
  p00_L_18B7();
  if (flag_z()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 7)) == 0);
  if (flag_nz()) return;
  a = mem_read8(0x8E63);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x08)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p05_L_6E5D;
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 1)));
  lab_p05_L_6E5D: ;
  p05_L_620C();
  flag_set_z((mem_read8((uint16_t)(iy + 0x27)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p05_L_6EB1;
  flag_set_z((mem_read8((uint16_t)(iy + 0x27)) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p05_L_6EAC;
  p05_L_6FB2();
  if (flag_z()) goto lab_p05_L_6EB1;
  flag_set_z((mem_read8((uint16_t)(iy + 0x1F)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p05_L_6E9F;
  b = 0x01;
  p00_L_0013();
  if (flag_z()) goto lab_p05_L_6E89;
  a = mem_read8(0x9151);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_6E89;
  flag_cmp(a, 0x09);
  if (flag_nc()) goto lab_p05_L_6E89;
  b = a;
  lab_p05_L_6E89: ;
  cpu_push_bc();
  flag_set_z((mem_read8((uint16_t)(iy + 0x27)) & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p05_L_6E99;
  flag_set_z((mem_read8((uint16_t)(iy + 0x27)) & (1u << 1)) == 0);
  if (flag_nz()) p05_L_6938();
  goto lab_p05_L_6E9C;
  lab_p05_L_6E99: ;
  p05_L_68F5();
  lab_p05_L_6E9C: ;
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_6E89;
  lab_p05_L_6E9F: ;
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  p05_L_621C();
  return;
  lab_p05_L_6EAC: ;
  p05_L_6FB2();
  if (flag_nz()) goto lab_p05_L_6EF0;
  lab_p05_L_6EB1: ;
  p05_L_6FB7();
  p00_L_0013();
  if (flag_nz()) goto lab_p05_L_6EE1;
  p00_L_019D();
  if (flag_nz()) goto lab_p05_L_6ED9;
  p00_L_0198();
  if (flag_nz()) goto lab_p05_L_6ECE;
  set_hl(0x8FB3);
  p05_L_6EA6();
  set_hl(0x8FA1);
  goto lab_p05_L_6EEA;
  lab_p05_L_6ECE: ;
  set_hl(0x8F98);
  p05_L_6EA6();
  set_hl(0x8F86);
  goto lab_p05_L_6EEA;
  lab_p05_L_6ED9: ;
  set_hl(0x9004);
  p05_L_6EA6();
  goto lab_p05_L_6EF0;
  lab_p05_L_6EE1: ;
  set_hl(0x9152);
  p05_L_6EA6();
  set_hl(0x8E6A);
  lab_p05_L_6EEA: ;
  set_de(0x862B);
  p00_L_1183();
  lab_p05_L_6EF0: ;
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p05_L_635B();
  p00_L_3D1D();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  p05_L_5EDA();
  p00_L_019D();
  if (flag_z()) goto lab_p05_L_6F45;
  set_hl(0x0075);
  p00_L_21C3();
  set_bc(0x0036);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_ex_de_hl();
  set_hl(0x901F);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(0x91D0);
  p00_L_1183();
  set_bc(0x0036);
  set_hl(0x8E2D);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(mem_read16(0x84E9));
  cpu_push_hl();
  p00_L_39F3();
  p00_L_21E5();
  /* bit 7,(iy) */
  if (flag_z()) goto lab_p05_L_6F3A;
  set_hl(0x8D21);
  p00_rst20();
  lab_p05_L_6F3A: ;
  set_de(0x862B);
  p00_L_11FD();
  p00_L_128A();
  goto lab_p05_L_6F48;
  lab_p05_L_6F45: ;
  p05_L_6F87();
  lab_p05_L_6F48: ;
  p05_L_6E0B();
  p05_L_621C();
  p05_L_6FD8();
  p05_L_5BE9();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  p00_L_019D();
  if (flag_z()) goto lab_p05_L_6F83;
  p00_L_219B();
  p00_L_39D5();
  set_de(0x0075);
  set_bc(0x0036);
  p00_L_21B6();
  set_de(0x901F);
  while (bc() != 0) { cpu_ldi(); }
  set_de(0x91D0);
  p00_L_1183();
  set_bc(0x0036);
  set_de(0x8E2D);
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_hl();
  mem_write16(0x84E9, hl());
  lab_p05_L_6F83: ;
  p00_L_33F3();
  return;
}

/* flash page 5 cpu 0x6EA6 (offset 0x2EA6) */
void p05_L_6EA6(void) {
  set_de(0x92BC);
  p00_L_1183();
  return;
}

/* flash page 5 cpu 0x6ECD (offset 0x2ECD) */
void p05_L_6ECD(void) {
  e = (uint8_t)(e + 1);
  set_hl(0x8F98);
  p05_L_6EA6();
  set_hl(0x8F86);
  goto lab_p05_L_6EEA;
  lab_p05_L_6EEA: ;
  set_de(0x862B);
  p00_L_1183();
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p05_L_635B();
  p00_L_3D1D();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  p05_L_5EDA();
  p00_L_019D();
  if (flag_z()) goto lab_p05_L_6F45;
  set_hl(0x0075);
  p00_L_21C3();
  set_bc(0x0036);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_ex_de_hl();
  set_hl(0x901F);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(0x91D0);
  p00_L_1183();
  set_bc(0x0036);
  set_hl(0x8E2D);
  while (bc() != 0) { cpu_ldi(); }
  set_hl(mem_read16(0x84E9));
  cpu_push_hl();
  p00_L_39F3();
  p00_L_21E5();
  /* bit 7,(iy) */
  if (flag_z()) goto lab_p05_L_6F3A;
  set_hl(0x8D21);
  p00_rst20();
  lab_p05_L_6F3A: ;
  set_de(0x862B);
  p00_L_11FD();
  p00_L_128A();
  goto lab_p05_L_6F48;
  lab_p05_L_6F45: ;
  p05_L_6F87();
  lab_p05_L_6F48: ;
  p05_L_6E0B();
  p05_L_621C();
  p05_L_6FD8();
  p05_L_5BE9();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 1)));
  p00_L_019D();
  if (flag_z()) goto lab_p05_L_6F83;
  p00_L_219B();
  p00_L_39D5();
  set_de(0x0075);
  set_bc(0x0036);
  p00_L_21B6();
  set_de(0x901F);
  while (bc() != 0) { cpu_ldi(); }
  set_de(0x91D0);
  p00_L_1183();
  set_bc(0x0036);
  set_de(0x8E2D);
  while (bc() != 0) { cpu_ldi(); }
  cpu_pop_hl();
  mem_write16(0x84E9, hl());
  lab_p05_L_6F83: ;
  p00_L_33F3();
  return;
}

/* flash page 5 cpu 0x6F87 (offset 0x2F87) */
void p05_L_6F87(void) {
  a = mem_read8(0x8E67);
  /* bit 7,(iy) */
  if (flag_z()) goto lab_p05_L_6F93;
  a = mem_read8(0x8E2B);
  lab_p05_L_6F93: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p05_L_6F9B;
  /* neg */
  lab_p05_L_6F9B: ;
  l = a;
  h = 0x00;
  p00_L_3B55();
  flag_set_z((mem_read8((uint16_t)(iy + 0x17)) & (1u << 7)) == 0);
  if (flag_nz()) p00_L_0E5C();
  set_hl(0x8E73);
  p00_rst20();
  p00_rst30();
  return;
}

/* flash page 5 cpu 0x6FAE (offset 0x2FAE) */
void p05_L_6FAE(void) {
  p05_L_5EE1();
  if (flag_z()) return;
  p05_L_6FB2();
  return;
}

/* flash page 5 cpu 0x6FB2 (offset 0x2FB2) */
void p05_L_6FB2(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x27)) & (1u << 4)) == 0);
  return;
}

/* flash page 5 cpu 0x6FB7 (offset 0x2FB7) */
void p05_L_6FB7(void) {
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) | (1u << 4)));
  return;
}

/* flash page 5 cpu 0x6FBC (offset 0x2FBC) */
void p05_L_6FBC(void) {
  mem_write8((uint16_t)(iy + 0x27), (uint8_t)(mem_read8((uint16_t)(iy + 0x27)) & ~(1u << 4)));
  return;
}

/* flash page 5 cpu 0x6FCD (offset 0x2FCD) */
void p05_L_6FCD(void) {
  p05_L_6FB2();
  if (flag_z()) return;
  p05_L_6FBC();
  mem_write8((uint16_t)(iy + 0x1D), (uint8_t)(mem_read8((uint16_t)(iy + 0x1D)) | (1u << 7)));
  p05_L_6FD8();
  return;
}

/* flash page 5 cpu 0x6FD8 (offset 0x2FD8) */
void p05_L_6FD8(void) {
  mem_write8((uint16_t)(iy + 0x13), (uint8_t)(mem_read8((uint16_t)(iy + 0x13)) | (1u << 6)));
  return;
}

/* flash page 5 cpu 0x7019 (offset 0x3019) */
void p05_L_7019(void) {
  set_hl(0x7239);
  p00_L_07CC();
  set_hl(0x7897);
  p00_L_17CE();
  if (flag_z()) goto lab_p05_L_702A;
  set_hl(0x78B5);
  lab_p05_L_702A: ;
  a = 0x03;
  p05_L_71F3();
  a = 0;
  flag_logic(a);
  mem_write8(0x97A2, a);
  p05_L_72F9();
  return;
}

/* flash page 5 cpu 0x7036 (offset 0x3036) */
void p05_L_7036(void) {
  a = mem_read8(0x8446);
  mem_write8(0x92FC, a);
  set_hl(0x7239);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 3)));
  p05_L_7113();
  a = 0x03;
  mem_write8(0x97A2, a);
  p05_L_72F9();
  p05_L_7051();
  return;
}

/* flash page 5 cpu 0x7051 (offset 0x3051) */
void p05_L_7051(void) {
  p05_L_70E1();
  p05_L_71FA();
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p05_L_7069;
  set_hl(0x0A04);
  a = 0x2C;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p05_L_7075;
  lab_p05_L_7069: ;
  set_hl(0x0604);
  a = 0x2D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  lab_p05_L_7075: ;
  mem_write16(0x844B, hl());
  a = 0x00;
  p05_L_70AC();
  set_hl(0x0605);
  mem_write16(0x844B, hl());
  p05_L_71FA();
  flag_cmp(a, 0x05);
  if (flag_z()) return;
  p05_L_71FA();
  if (flag_nc()) goto lab_p05_L_709B;
  a = 0x2E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  a = 0x01;
  p05_L_70AC();
  return;
  lab_p05_L_709B: ;
  set_hl(0x0505);
  a = 0x2F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  mem_write16(0x844B, hl());
  a = 0x02;
  p05_L_70AC();
  return;
}

/* flash page 5 cpu 0x70AC (offset 0x30AC) */
void p05_L_70AC(void) {
  set_hl(0x92C9);
  p05_L_519C();
  p05_L_7104();
  p05_L_70B5();
  return;
}

/* flash page 5 cpu 0x70B5 (offset 0x30B5) */
void p05_L_70B5(void) {
  a = mem_read8(hl());
  flag_cmp(a, 0x06);
  if (flag_c()) goto lab_p05_L_70D3;
  flag_cmp(a, 0x40);
  if (flag_z()) goto lab_p05_L_70C2;
  p00_L_311D();
  return;
  lab_p05_L_70C2: ;
  set_hl(0x26E9);
  a = 0x3D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p00_L_3C87();
  goto lab_p05_L_70DD;
  lab_p05_L_70D3: ;
  a = (uint8_t)(a + 1);
  /* sla a */
  e = a;
  p05_L_755C();
  p05_L_5AFB();
  lab_p05_L_70DD: ;
  p00_L_3D1D();
  return;
}

/* flash page 5 cpu 0x70E1 (offset 0x30E1) */
void p05_L_70E1(void) {
  a = mem_read8(0x97A1);
  b = a;
  /* ld ix,(0x979F) */
  lab_p05_L_70E9: ;
  a = a | a;
  flag_logic(a);
  p05_L_74B8();
  set_de(0x000A);
  /* add ix,de */
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_70E9;
  return;
}

/* flash page 5 cpu 0x70F5 (offset 0x30F5) */
void p05_L_70F5(void) {
  set_hl(mem_read16(0x844B));
  cpu_push_hl();
  p05_L_70E1();
  cpu_pop_hl();
  mem_write16(0x844B, hl());
  return;
}

/* flash page 5 cpu 0x7101 (offset 0x3101) */
void p05_L_7101(void) {
  set_hl(0x92C9);
  p05_L_7104();
  return;
}

/* flash page 5 cpu 0x7104 (offset 0x3104) */
void p05_L_7104(void) {
  set_de(0x0011);
  a = mem_read8(0x92FC);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_7111;
  b = a;
  lab_p05_L_710E: ;
  set_hl((uint16_t)(hl() + de()));
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_710E;
  lab_p05_L_7111: ;
  set_hl((uint16_t)(hl() + 1));
  return;
}

/* flash page 5 cpu 0x7113 (offset 0x3113) */
void p05_L_7113(void) {
  a = 0x00;
  mem_write8(0x97A5, a);
  p00_L_3D2F();
  p00_L_3D0B();
  set_hl(0x0002);
  mem_write16(0x844B, hl());
  set_hl(0x795E);
  a = 0x21;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p05_L_5AFB();
  p05_L_76BF();
  a = 0x01;
  mem_write8(0x92C6, a);
  p05_L_76BF();
  p05_L_71FA();
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p05_L_717D;
  set_hl(0x92C6);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  set_hl(0x7919);
  a = 0x22;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p05_L_76BC();
  set_hl(0x7924);
  a = 0x23;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p05_L_76BC();
  set_hl(0x7951);
  a = 0x24;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p05_L_76BC();
  set_hl(0x76DF);
  a = 0x10;
  p05_L_71F3();
  return;
  lab_p05_L_717D: ;
  set_hl(0x7912);
  a = 0x25;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p05_L_76BC();
  p05_L_71FA();
  if (flag_nc()) goto lab_p05_L_71B6;
  set_hl(0x792F);
  a = 0x26;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p05_L_76BC();
  set_hl(0x7951);
  a = 0x24;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p05_L_76BC();
  set_hl(0x777F);
  a = 0x0E;
  p05_L_71F3();
  return;
  lab_p05_L_71B6: ;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p05_L_71DF;
  set_hl(0x7939);
  a = 0x27;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p05_L_76BC();
  set_hl(0x7951);
  a = 0x24;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p05_L_76BC();
  set_hl(0x780B);
  a = 0x0E;
  p05_L_71F3();
  return;
  lab_p05_L_71DF: ;
  set_hl(0x7939);
  a = 0x27;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p05_L_76BC();
  set_hl(0x780B);
  a = 0x0B;
  p05_L_71F3();
  return;
}

/* flash page 5 cpu 0x71F3 (offset 0x31F3) */
void p05_L_71F3(void) {
  mem_write16(0x979F, hl());
  mem_write8(0x97A1, a);
  return;
}

/* flash page 5 cpu 0x71FA (offset 0x31FA) */
void p05_L_71FA(void) {
  p05_L_7101();
  set_hl((uint16_t)(hl() - 1));
  a = mem_read8(hl());
  a = a & 0x0F;
  flag_logic(a);
  flag_cmp(a, 0x02);
  return;
}

/* flash page 5 cpu 0x7218 (offset 0x3218) */
void p05_L_7218(void) {
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), d);
  p00_L_25A2();
  p05_L_4941();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x01), (uint8_t)(mem_read8((uint16_t)(iy + 0x01)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 6)));
  p05_L_722B();
  return;
}

/* flash page 5 cpu 0x722B (offset 0x322B) */
void p05_L_722B(void) {
  p00_L_0740();
  return;
}

/* flash page 5 cpu 0x722F (offset 0x322F) */
void p05_L_722F(void) {
  set_hl(mem_read16(0x858D));
  set_de(0x7246);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  return;
}

/* flash page 5 cpu 0x7298 (offset 0x3298) */
void p05_L_7298(void) {
  p05_L_7583();
  if (flag_nc()) goto lab_p05_L_72A9;
  a = 0x0F;
  /* and (hl) */
  mem_write8(hl(), a);
  a = mem_read8((uint16_t)(ix + 0x09));
  p00_L_12B9();
  goto lab_p05_L_72B0;
  lab_p05_L_72A9: ;
  a = 0xF0;
  /* and (hl) */
  mem_write8(hl(), a);
  a = mem_read8((uint16_t)(ix + 0x09));
  lab_p05_L_72B0: ;
  /* or (hl) */
  mem_write8(hl(), a);
  flag_set_z((mem_read8((uint16_t)(ix + 0x06)) & (1u << 7)) == 0);
  if (flag_z()) return;
  p05_L_72B7();
  return;
}

/* flash page 5 cpu 0x72B7 (offset 0x32B7) */
void p05_L_72B7(void) {
  mem_write8((uint16_t)(iy + 0x17), (uint8_t)(mem_read8((uint16_t)(iy + 0x17)) | (1u << 1)));
  p00_L_009B();
  return;
}

/* flash page 5 cpu 0x72CD (offset 0x32CD) */
void p05_L_72CD(void) {
  set_hl((uint16_t)(hl() + de()));
  a = mem_read8(ix);
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p05_L_72DF;
  p00_L_019D();
  if (flag_z()) { p00_L_3663(); return; }
  p00_L_3129();
  return;
  lab_p05_L_72DF: ;
  mem_write8(0x97A2, a);
  flag_cmp(a, 0xFE);
  if (flag_nz()) { p05_L_72F9(); return; }
  a = e;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p05_L_72EF;
  a = 0x00;
  goto lab_p05_L_72F2;
  lab_p05_L_72EF: ;
  a = mem_read8(0x92C6);
  lab_p05_L_72F2: ;
  mem_write8(0x92C5, a);
  a = (uint8_t)(a & ~(1u << 2));
  goto lab_p05_L_731D;
  lab_p05_L_731D: ;
  set_hl(0x7312);
  mem_write16(0x858D, hl());
  set_hl(0x720F);
  mem_write16(0x8591, hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x97A7, a);
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 6)));
  p05_L_7331();
  return;
}

/* flash page 5 cpu 0x72F9 (offset 0x32F9) */
void p05_L_72F9(void) {
  a = mem_read8(0x97A2);
  l = a;
  h = 0x00;
  e = l;
  d = h;
  set_hl((uint16_t)(hl() + hl()));
  set_hl((uint16_t)(hl() + hl()));
  set_hl((uint16_t)(hl() + hl()));
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  set_de(mem_read16(0x979F));
  set_hl((uint16_t)(hl() + de()));
  mem_write16(0x97A3, hl());
  cpu_push_hl();
  ix = cpu_pop16();
  return;
}

/* flash page 5 cpu 0x7331 (offset 0x3331) */
void p05_L_7331(void) {
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) & ~(1u << 6)));
  p00_L_3417();
  set_hl(0x84CC);
  mem_write16(0x96F8, hl());
  mem_write16(0x96FA, hl());
  p05_L_7429();
  p05_L_7466();
  p05_L_748E();
  p00_L_3423();
  p05_L_7429();
  p05_L_740F();
  set_hl(mem_read16(0x96F6));
  set_hl((uint16_t)(hl() + bc()));
  mem_write16(0x96F6, hl());
  p00_L_3645();
  return;
}

/* flash page 5 cpu 0x735E (offset 0x335E) */
void p05_L_735E(void) {
  p05_L_7466();
  set_de(0x84C7);
  b = 0x00;
  c = 0x04;
  lab_p05_L_7368: ;
  a = mem_read8(de());
  flag_cmp(a, 0x5D);
  if (flag_z()) goto lab_p05_L_7376;
  cpu_cp_hl();
  if (flag_nz()) p05_L_72B7();
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p05_L_737A;
  set_hl((uint16_t)(hl() + 1));
  lab_p05_L_7376: ;
  set_de((uint16_t)(de() + 1));
  c = (uint8_t)(c - 1);
  if (flag_nc()) goto lab_p05_L_7368;
  lab_p05_L_737A: ;
  a = mem_read8(0x84C7);
  flag_cmp(a, 0x31);
  if (flag_z()) goto lab_p05_L_7394;
  set_hl(0x84C7);
  a = mem_read8(hl());
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p05_L_738A;
  set_hl((uint16_t)(hl() + 1));
  lab_p05_L_738A: ;
  p05_L_5533();
  p00_rst10();
  set_hl(0x0000);
  if (flag_c()) p00_L_1C46();
  lab_p05_L_7394: ;
  b = 0x00;
  c = 0x05;
  p05_L_7466();
  set_de(0x84C7);
  cpu_ex_de_hl();
  a = mem_read8(hl());
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p05_L_73A6;
  set_hl((uint16_t)(hl() + 1));
  c = (uint8_t)(c - 1);
  lab_p05_L_73A6: ;
  while (bc() != 0) { cpu_ldi(); }
  p05_L_7429();
  p05_L_7466();
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 4)) == 0);
  if (flag_nz()) return;
  p05_L_70B5();
  p05_L_745C();
  if (flag_nz()) goto lab_p05_L_73DD;
  a = mem_read8(0x92C6);
  flag_cmp(a, 0x01);
  a = mem_read8(0x92C5);
  if (flag_nz()) goto lab_p05_L_73D4;
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p05_L_73D4;
  p05_L_71FA();
  if (flag_c()) goto lab_p05_L_73FA;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p05_L_73E6;
  goto lab_p05_L_73FA;
  lab_p05_L_73D4: ;
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_z()) goto lab_p05_L_73FA;
  set_hl(0x92C5);
  goto lab_p05_L_73ED;
  lab_p05_L_73DD: ;
  set_hl(0x92C5);
  a = mem_read8(hl());
  flag_set_z((a & (1u << 2)) == 0);
  if (flag_nz()) goto lab_p05_L_73ED;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p05_L_73E6: ;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 6)));
  p05_L_7331();
  return;
  lab_p05_L_73ED: ;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 2)));
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_p()) { p05_L_7331(); return; }
  a = 0x05;
  mem_write8(0x97A2, a);
  goto lab_p05_L_73FF;
  lab_p05_L_73FA: ;
  a = 0x0B;
  mem_write8(0x97A2, a);
  lab_p05_L_73FF: ;
  set_hl(0x7239);
  p00_L_07CC();
  mem_write8((uint16_t)(iy + 0x0D), (uint8_t)(mem_read8((uint16_t)(iy + 0x0D)) | (1u << 6)));
  p00_L_03A0();
  p05_L_72F9();
  return;
}

/* flash page 5 cpu 0x740F (offset 0x340F) */
void p05_L_740F(void) {
  set_hl(0x84C7);
  b = 0x05;
  lab_p05_L_7414: ;
  a = mem_read8(hl());
  flag_cmp(a, 0x5D);
  if (flag_nz()) goto lab_p05_L_741B;
  b = (uint8_t)(b - 1);
  set_hl((uint16_t)(hl() + 1));
  lab_p05_L_741B: ;
  set_hl((uint16_t)(hl() + 1));
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p05_L_7422;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_7414;
  lab_p05_L_7422: ;
  a = 0x05;
  a = (uint8_t)(a - b);
  c = a;
  b = 0x00;
  return;
}

/* flash page 5 cpu 0x7429 (offset 0x3429) */
void p05_L_7429(void) {
  a = 0x30;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p05_L_7436;
  p00_L_3C45();
  if (flag_z()) goto lab_p05_L_7458;
  lab_p05_L_7436: ;
  a = mem_read8(0x92C5);
  a = (uint8_t)(a & ~(1u << 2));
  a = (uint8_t)(a + 0x04);
  mem_write8(0x844B, a);
  p05_L_745C();
  if (flag_nz()) goto lab_p05_L_7456;
  flag_cmp(a, 0x00);
  if (flag_nz()) goto lab_p05_L_744D;
  a = 0x0A;
  goto lab_p05_L_7458;
  lab_p05_L_744D: ;
  p05_L_71FA();
  if (flag_c()) goto lab_p05_L_7456;
  a = 0x05;
  goto lab_p05_L_7458;
  lab_p05_L_7456: ;
  a = 0x06;
  lab_p05_L_7458: ;
  mem_write8(0x844C, a);
  return;
}

/* flash page 5 cpu 0x745C (offset 0x345C) */
void p05_L_745C(void) {
  set_hl(0x92C6);
  a = mem_read8(0x92C5);
  a = (uint8_t)(a & ~(1u << 2));
  cpu_cp_hl();
  return;
}

/* flash page 5 cpu 0x7466 (offset 0x3466) */
void p05_L_7466(void) {
  p05_L_745C();
  if (flag_nz()) goto lab_p05_L_747C;
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p05_L_747C;
  p05_L_71FA();
  if (flag_c()) goto lab_p05_L_747C;
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) | (1u << 1)));
  a = 0x02;
  goto lab_p05_L_7485;
  lab_p05_L_747C: ;
  mem_write8((uint16_t)(iy + 0x18), (uint8_t)(mem_read8((uint16_t)(iy + 0x18)) & ~(1u << 1)));
  a = mem_read8(0x92C5);
  a = (uint8_t)(a & ~(1u << 2));
  lab_p05_L_7485: ;
  set_hl(0x92C9);
  p05_L_519C();
  p05_L_7104();
  return;
}

/* flash page 5 cpu 0x748E (offset 0x348E) */
void p05_L_748E(void) {
  set_de(0x84C7);
  a = mem_read8(hl());
  flag_cmp(a, 0x31);
  if (flag_nz()) goto lab_p05_L_749B;
  cpu_ex_de_hl();
  mem_write8(hl(), 0x31);
  goto lab_p05_L_74A9;
  lab_p05_L_749B: ;
  flag_cmp(a, 0x06);
  if (flag_nc()) goto lab_p05_L_74A6;
  cpu_ex_de_hl();
  mem_write8(hl(), 0x5D);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  goto lab_p05_L_74A9;
  lab_p05_L_74A6: ;
  p00_L_118B();
  lab_p05_L_74A9: ;
  set_hl(0x84C7);
  return;
}

/* flash page 5 cpu 0x74B8 (offset 0x34B8) */
void p05_L_74B8(void) {
  cpu_push_bc();
  a = mem_read8(0x89F5);
  cpu_push_af();
  e = mem_read8((uint16_t)(ix + 0x07));
  flag_set_z((mem_read8((uint16_t)(ix + 0x06)) & (1u << 6)) == 0);
  if (flag_nz()) goto lab_p05_L_7510;
  /* ld ixl,(ix+0x04) */
  /* ld ixh,(ix+0x05) */
  mem_write16(0x844B, hl());
  if (flag_nc()) goto lab_p05_L_74F1;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p05_L_74DE;
  a = 0x28;
  p00_L_3C45();
  if (flag_z()) goto lab_p05_L_74E1;
  lab_p05_L_74DE: ;
  a = mem_read8((uint16_t)(ix + 0x06));
  lab_p05_L_74E1: ;
  a = a & 0x0F;
  flag_logic(a);
  b = a;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  a = 0x20;
  lab_p05_L_74EA: ;
  p00_L_3F9F();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_74EA;
  goto lab_p05_L_750A;
  lab_p05_L_74F1: ;
  p05_L_7550();
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p05_L_74FE;
  mem_write8((uint16_t)(iy + 0x08), (uint8_t)(mem_read8((uint16_t)(iy + 0x08)) | (1u << 0)));
  lab_p05_L_74FE: ;
  a = 0x2A;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p05_L_5AFB();
  lab_p05_L_750A: ;
  cpu_pop_af();
  mem_write8(0x89F5, a);
  cpu_pop_bc();
  return;
  lab_p05_L_7510: ;
  /* ld ixh,(ix+0x04) */
  /* ld ixl,(ix+0x05) */
  mem_write16(0x86D7, hl());
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  if (flag_nc()) goto lab_p05_L_753F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p05_L_752C;
  a = 0x29;
  p00_L_3C45();
  if (flag_z()) goto lab_p05_L_7531;
  lab_p05_L_752C: ;
  a = mem_read8((uint16_t)(ix + 0x06));
  a = a & 0x1F;
  flag_logic(a);
  lab_p05_L_7531: ;
  b = a;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  lab_p05_L_7536: ;
  a = 0x20;
  p00_L_3D47();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_7536;
  goto lab_p05_L_750A;
  lab_p05_L_753F: ;
  p05_L_7550();
  a = 0x2B;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p05_L_76C7();
  goto lab_p05_L_750A;
}

/* flash page 5 cpu 0x7550 (offset 0x3550) */
void p05_L_7550(void) {
  p05_L_756B();
  if (flag_nz()) goto lab_p05_L_7559;
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 3)));
  lab_p05_L_7559: ;
  e = mem_read8((uint16_t)(ix + 0x07));
  p05_L_755C();
  return;
}

/* flash page 5 cpu 0x755C (offset 0x355C) */
void p05_L_755C(void) {
  d = 0x00;
  set_hl(0x78D3);
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  return;
}

/* flash page 5 cpu 0x7565 (offset 0x3565) */
void p05_L_7565(void) {
  p05_L_755C();
  p05_L_5AFB();
  return;
}

/* flash page 5 cpu 0x756B (offset 0x356B) */
void p05_L_756B(void) {
  p05_L_7583();
  cpu_push_af();
  a = mem_read8(0x859A);
  flag_cmp(a, 0x49);
  if (flag_z()) goto lab_p05_L_757C;
  cpu_pop_af();
  if (flag_c()) p00_L_12B1();
  goto lab_p05_L_757D;
  lab_p05_L_757C: ;
  cpu_pop_af();
  lab_p05_L_757D: ;
  a = a & 0x0F;
  flag_logic(a);
  /* cp (ix+0x09) */
  return;
}

/* flash page 5 cpu 0x7583 (offset 0x3583) */
void p05_L_7583(void) {
  a = mem_read8((uint16_t)(ix + 0x08));
  e = a;
  /* srl e */
  cpu_push_af();
  d = 0x00;
  set_hl(0x92C8);
  set_hl((uint16_t)(hl() + de()));
  flag_cmp(a, 0x68);
  if (flag_z()) goto lab_p05_L_759F;
  a = mem_read8(0x859A);
  flag_cmp(a, 0x49);
  if (flag_z()) goto lab_p05_L_759F;
  p05_L_7104();
  set_hl((uint16_t)(hl() - 1));
  lab_p05_L_759F: ;
  cpu_pop_af();
  a = mem_read8(hl());
  return;
}

/* flash page 5 cpu 0x75A2 (offset 0x35A2) */
void p05_L_75A2(void) {
  set_hl(0x92C9);
  p05_L_519C();
  p05_L_7104();
  p00_L_312F();
  return;
}

/* flash page 5 cpu 0x75AF (offset 0x35AF) */
void p05_L_75AF(void) {
  a = mem_read8(0x92FC);
  cpu_push_af();
  a = d;
  mem_write8(0x92FC, a);
  p05_L_71FA();
  cpu_push_hl();
  ix = cpu_pop16();
  set_hl(0x795B);
  a = 0x1D;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  a = mem_read8((uint16_t)(ix + 0x10));
  a = a & 0x0F;
  flag_logic(a);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p05_L_75DE;
  set_hl(0x7957);
  a = 0x1E;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  lab_p05_L_75DE: ;
  a = mem_read8(0x97A6);
  cpu_push_af();
  a = 0x07;
  mem_write8(0x97A6, a);
  p05_L_5AFB();
  cpu_pop_af();
  mem_write8(0x97A6, a);
  p00_L_3CD5();
  p00_L_3D1D();
  a = mem_read8(0x844B);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  a = (uint8_t)(a + a);
  mem_write8(0x86D8, a);
  a = 0x0C;
  mem_write8(0x86D7, a);
  a = mem_read8(ix);
  a = a & 0x0F;
  flag_logic(a);
  set_hl(0x78EB);
  p05_L_76B5();
  p05_L_76A6();
  a = 0x1A;
  mem_write8(0x86D7, a);
  a = 0x00;
  p05_L_75A2();
  a = 0x31;
  mem_write8(0x86D7, a);
  p05_L_71FA();
  if (flag_c()) goto lab_p05_L_764B;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p05_L_7652;
  a = mem_read8((uint16_t)(ix + 0x10));
  p00_L_12B1();
  set_hl(0x7901);
  p05_L_76B5();
  p00_L_0033();
  p05_L_76C7();
  set_hl(0x790D);
  a = 0x1F;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  p05_L_76C7();
  goto lab_p05_L_765C;
  lab_p05_L_764B: ;
  a = 0x01;
  p05_L_75A2();
  goto lab_p05_L_765C;
  lab_p05_L_7652: ;
  a = 0x31;
  mem_write8(0x86D7, a);
  a = 0x02;
  p05_L_75A2();
  lab_p05_L_765C: ;
  a = 0x48;
  mem_write8(0x86D7, a);
  p05_L_71FA();
  if (flag_c()) goto lab_p05_L_7677;
  flag_cmp(a, 0x02);
  if (flag_z()) goto lab_p05_L_7677;
  flag_cmp(a, 0x05);
  if (flag_nz()) goto lab_p05_L_7689;
  a = 0x20;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  lab_p05_L_7677: ;
  a = mem_read8(ix);
  p00_L_12B1();
  set_hl(0x78F7);
  p05_L_76B5();
  p00_L_0033();
  p05_L_76C7();
  lab_p05_L_7689: ;
  cpu_pop_af();
  mem_write8(0x92FC, a);
  return;
}

/* flash page 5 cpu 0x76A6 (offset 0x36A6) */
void p05_L_76A6(void) {
  p00_L_0033();
  p05_L_76A9();
  return;
}

/* flash page 5 cpu 0x76A9 (offset 0x36A9) */
void p05_L_76A9(void) {
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  p05_L_76C7();
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) & ~(1u << 1)));
  return;
}

/* flash page 5 cpu 0x76B5 (offset 0x36B5) */
void p05_L_76B5(void) {
  /* sla a */
  e = a;
  d = 0x00;
  set_hl((uint16_t)(hl() + de()));
  return;
}

/* flash page 5 cpu 0x76BC (offset 0x36BC) */
void p05_L_76BC(void) {
  p05_L_5AFB();
  p05_L_76BF();
  return;
}

/* flash page 5 cpu 0x76BF (offset 0x36BF) */
void p05_L_76BF(void) {
  set_hl(0x844B);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  a = 0;
  flag_logic(a);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), a);
  return;
}

/* flash page 5 cpu 0x76C7 (offset 0x36C7) */
void p05_L_76C7(void) {
  cpu_push_af();
  cpu_push_de();
  cpu_push16(ix);
  lab_p05_L_76CB: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p05_L_76D5;
  p00_L_3D47();
  if (flag_nc()) goto lab_p05_L_76CB;
  lab_p05_L_76D5: ;
  ix = cpu_pop16();
  cpu_pop_de();
  cpu_pop_af();
  return;
}

/* flash page 5 cpu 0x77CB (offset 0x37CB) */
void p05_L_77CB(void) {
  /* rr (hl) */
  p05_L_77CD();
  return;
}

/* flash page 5 cpu 0x77CD (offset 0x37CD) */
void p05_L_77CD(void) {
  goto lab_p05_L_77CD;
  lab_p05_L_6616: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p05_L_6623;
  a = (uint8_t)(a - 1);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p05_L_662C;
  lab_p05_L_6623: ;
  set_hl(0x91CE);
  b = a;
  /* and (hl) */
  flag_cmp(a, b);
  if (flag_nz()) { p00_L_24FD(); return; }
  lab_p05_L_662C: ;
  cpu_pop_af();
  p00_L_3513();
  p05_L_5EDA();
  a = a | a;
  flag_logic(a);
  return;
  lab_p05_L_77CD: ;
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  set_hl((uint16_t)(hl() + bc()));
  cpu_rlca();
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x18);
  cpu_rra();
  /* rr h */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  a = mem_read8(bc());
  cpu_ex_af();
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x18);
  a = a ^ 0xFF;
  /* sla b */
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_hl((uint16_t)(hl() + bc()));
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x18);
  /* ccf */
  /* sla d */
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  set_bc((uint16_t)(bc() - 1));
  flag_cmp(a, 0x0B);
  b = 0x06;
  a = (uint8_t)(a + c);
  h = (uint8_t)(h + 1);
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  c = (uint8_t)(c - 1);
  set_bc((uint16_t)(bc() - 1));
  flag_cmp(a, 0x0C);
  b = 0x08;
  a = (uint8_t)(a + c);
  h = 0x03;
  set_bc(0x0C0D);
  flag_cmp(a, 0x0D);
  b = 0x0A;
  a = (uint8_t)(a + c);
  if (flag_z()) goto lab_p05_L_780D;
  mem_write8(bc(), a);
  set_bc(0x0000);
  lab_p05_L_780D: ;
  /* nop */
  set_bc((uint16_t)(bc() + 1));
  set_bc(0x5200);
  mem_write8(de(), a);
  l = b;
  /* nop */
  mem_write8(bc(), a);
  /* nop */
  set_bc(0x0103);
  set_hl((uint16_t)(hl() + de()));
  d = d;
  d = (uint8_t)(d + 1);
  l = b;
  set_bc(0x0102);
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  set_bc(0x5232);
  d = 0x68;
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  b = (uint8_t)(b - 1);
  set_bc(0x8200);
  c = 0x22;
  set_bc(0x0304);
  /* nop */
  b = (uint8_t)(b - 1);
  set_bc(0x8303);
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p05_L_785E;
  /* nop */
  b = 0x05;
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x10);
  cpu_rra();
  /* rr b */
  mem_write8(bc(), a);
  /* nop */
  cpu_rlca();
  b = (uint8_t)(b - 1);
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x10);
  a = a ^ 0xFF;
  /* rr d */
  mem_write8(bc(), a);
  set_bc(0x0608);
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x10);
  /* ccf */
  /* rr (hl) */
  mem_write8(bc(), a);
  set_bc((uint16_t)(bc() + 1));
  set_hl((uint16_t)(hl() + bc()));
  cpu_rlca();
  set_bc((uint16_t)(bc() + 1));
  lab_p05_L_785E: ;
  flag_cmp(a, 0x18);
  cpu_rra();
  /* rr h */
  mem_write8(bc(), a);
  mem_write8(bc(), a);
  a = mem_read8(bc());
  cpu_ex_af();
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x18);
  a = a ^ 0xFF;
  /* sla b */
  mem_write8(bc(), a);
  b = (uint8_t)(b + 1);
  a = mem_read8(bc());
  set_hl((uint16_t)(hl() + bc()));
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x18);
  /* ccf */
  /* sla d */
  mem_write8(bc(), a);
  b = (uint8_t)(b - 1);
  c = (uint8_t)(c + 1);
  set_bc((uint16_t)(bc() - 1));
  flag_cmp(a, 0x0B);
  b = 0x06;
  a = (uint8_t)(a + c);
  h = (uint8_t)(h + 1);
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  c = (uint8_t)(c - 1);
  set_bc((uint16_t)(bc() - 1));
  flag_cmp(a, 0x0C);
  b = 0x08;
  a = (uint8_t)(a + c);
  h = 0x03;
  set_bc(0x0C0D);
  flag_cmp(a, 0x0D);
  b = 0x0A;
  a = (uint8_t)(a + c);
  if (flag_z()) goto lab_p05_L_7899;
  mem_write8(bc(), a);
  set_bc(0x0000);
  lab_p05_L_7899: ;
  /* nop */
  p00_rst38_isr();
  /* nop */
  b = 0xD2;
  mem_write8(de(), a);
  mem_write16(0x0201, hl());
  /* nop */
  set_bc(0x00FF);
  e = 0xD2;
  d = (uint8_t)(d + 1);
  b = h;
  set_bc(0x0102);
  mem_write8(bc(), a);
  p00_rst38_isr();
  /* nop */
  mem_write8(hl(), 0xD2);
  d = 0x66;
  set_bc(0x0001);
  /* nop */
  p00_rst38_isr();
  if (flag_nz()) goto lab_p05_L_78C1;
  if (flag_nc()) { p00_L_2212(); return; }
  set_bc(0x0002);
  lab_p05_L_78C1: ;
  set_bc(0x20FF);
  e = 0xD2;
  d = (uint8_t)(d + 1);
  b = h;
  set_bc(0x0102);
  mem_write8(bc(), a);
  p00_rst38_isr();
  if (flag_nz()) goto lab_p05_L_7905;
  if (flag_nc()) goto lab_p05_L_6616;
  set_bc(0x7936);
  /* ccf */
  a = c;
  b = d;
  a = c;
  b = l;
  a = c;
  c = b;
  a = c;
  c = e;
  a = c;
  c = mem_read8(hl());
  a = c;
  e = e;
  a = c;
  d = a;
  a = c;
  a = mem_read8(hl());
  h = 0x84;
  h = 0x8A;
  h = 0x6A;
  a = c;
  l = l;
  a = c;
  halt();
  a = c;
  mem_write8(hl(), e);
  a = c;
  mem_write8(hl(), b);
  a = c;
  a = c;
  a = c;
  h = h;
  a = c;
  h = mem_read8(hl());
  a = c;
  l = b;
  a = c;
  b = (uint8_t)(b - 1);
  a = c;
  cpu_rlca();
  a = c;
  set_hl((uint16_t)(hl() + bc()));
  a = c;
  set_bc((uint16_t)(bc() - 1));
  a = c;
  lab_p05_L_7905: ;
  e = b;
  /* nop */
  e = c;
  /* nop */
  a = b;
  /* nop */
  a = c;
  /* nop */
  p05_str_8();
  return;
}

/* flash page 5 cpu 0x78B5 (offset 0x38B5) */
void p05_font(void) {
  goto lab_p05_font;
  lab_p05_L_6616: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p05_L_6623;
  a = (uint8_t)(a - 1);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0F)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p05_L_662C;
  lab_p05_L_6623: ;
  set_hl(0x91CE);
  b = a;
  /* and (hl) */
  flag_cmp(a, b);
  if (flag_nz()) { p00_L_24FD(); return; }
  lab_p05_L_662C: ;
  cpu_pop_af();
  p00_L_3513();
  p05_L_5EDA();
  a = a | a;
  flag_logic(a);
  return;
  lab_p05_font: ;
  set_bc(0x0000);
  p00_rst38_isr();
  if (flag_nz()) goto lab_p05_L_78C1;
  if (flag_nc()) { p00_L_2212(); return; }
  set_bc(0x0002);
  lab_p05_L_78C1: ;
  set_bc(0x20FF);
  e = 0xD2;
  d = (uint8_t)(d + 1);
  b = h;
  set_bc(0x0102);
  mem_write8(bc(), a);
  p00_rst38_isr();
  if (flag_nz()) goto lab_p05_L_7905;
  if (flag_nc()) goto lab_p05_L_6616;
  set_bc(0x7936);
  /* ccf */
  a = c;
  b = d;
  a = c;
  b = l;
  a = c;
  c = b;
  a = c;
  c = e;
  a = c;
  c = mem_read8(hl());
  a = c;
  e = e;
  a = c;
  d = a;
  a = c;
  a = mem_read8(hl());
  h = 0x84;
  h = 0x8A;
  h = 0x6A;
  a = c;
  l = l;
  a = c;
  halt();
  a = c;
  mem_write8(hl(), e);
  a = c;
  mem_write8(hl(), b);
  a = c;
  a = c;
  a = c;
  h = h;
  a = c;
  h = mem_read8(hl());
  a = c;
  l = b;
  a = c;
  b = (uint8_t)(b - 1);
  a = c;
  cpu_rlca();
  a = c;
  set_hl((uint16_t)(hl() + bc()));
  a = c;
  set_bc((uint16_t)(bc() - 1));
  a = c;
  lab_p05_L_7905: ;
  e = b;
  /* nop */
  e = c;
  /* nop */
  a = b;
  /* nop */
  a = c;
  /* nop */
  p05_str_8();
  return;
}

/* flash page 5 cpu 0x790D (offset 0x390D) */
void p05_str_8(void) {
  b = c;
  a = b;
  l = c;
  mem_write8(hl(), e);
  /* nop */
  p05_str_4();
  return;
}

/* flash page 5 cpu 0x7912 (offset 0x3912) */
void p05_str_4(void) {
  e = b;
  l = h;
  l = c;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  a = mem_read8(0x4400);
  h = c;
  mem_write8(hl(), h);
  h = c;
  if (flag_nz()) goto lab_p05_L_796B;
  l = c;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  a = mem_read8(0x4400);
  h = c;
  mem_write8(hl(), h);
  h = c;
  if (flag_nz()) goto lab_p05_L_796B;
  a = b;
  l = c;
  mem_write8(hl(), e);
  a = mem_read8(0x5900);
  l = h;
  l = c;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  a = mem_read8(0x2000);
  sp = 0x4600;
  mem_write8(hl(), d);
  h = l;
  mem_write8(hl(), c);
  a = mem_read8(0x4C00);
  a = (uint8_t)(a + c);
  /* nop */
  c = h;
  a = (uint8_t)(a + d);
  /* nop */
  c = h;
  a = (uint8_t)(a + e);
  /* nop */
  c = h;
  a = (uint8_t)(a + h);
  /* nop */
  c = h;
  a = (uint8_t)(a + l);
  /* nop */
  c = h;
  /* add a,(hl) */
  /* nop */
  p05_str_3();
  return;
  lab_p05_L_796B: ;
  /* jp po,0xE300 - other page/RAM */
  /* call 0xE500 - RAM/other */
  a = a & 0x00;
  flag_logic(a);
  p00_rst20();
  if (flag_pe()) return;
  /* nop */
  os_jp_hl();
  return;
}

/* flash page 5 cpu 0x7919 (offset 0x3919) */
void p05_str_9(void) {
  b = h;
  h = c;
  mem_write8(hl(), h);
  h = c;
  if (flag_nz()) goto lab_p05_L_796B;
  l = c;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  a = mem_read8(0x4400);
  h = c;
  mem_write8(hl(), h);
  h = c;
  if (flag_nz()) goto lab_p05_L_796B;
  a = b;
  l = c;
  mem_write8(hl(), e);
  a = mem_read8(0x5900);
  l = h;
  l = c;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  a = mem_read8(0x2000);
  sp = 0x4600;
  mem_write8(hl(), d);
  h = l;
  mem_write8(hl(), c);
  a = mem_read8(0x4C00);
  a = (uint8_t)(a + c);
  /* nop */
  c = h;
  a = (uint8_t)(a + d);
  /* nop */
  c = h;
  a = (uint8_t)(a + e);
  /* nop */
  c = h;
  a = (uint8_t)(a + h);
  /* nop */
  c = h;
  a = (uint8_t)(a + l);
  /* nop */
  c = h;
  /* add a,(hl) */
  /* nop */
  p05_str_3();
  return;
  lab_p05_L_796B: ;
  /* jp po,0xE300 - other page/RAM */
  /* call 0xE500 - RAM/other */
  a = a & 0x00;
  flag_logic(a);
  p00_rst20();
  if (flag_pe()) return;
  /* nop */
  os_jp_hl();
  return;
}

/* flash page 5 cpu 0x7924 (offset 0x3924) */
void p05_str_2(void) {
  b = h;
  h = c;
  mem_write8(hl(), h);
  h = c;
  if (flag_nz()) goto lab_p05_L_796B;
  a = b;
  l = c;
  mem_write8(hl(), e);
  a = mem_read8(0x5900);
  l = h;
  l = c;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  a = mem_read8(0x2000);
  sp = 0x4600;
  mem_write8(hl(), d);
  h = l;
  mem_write8(hl(), c);
  a = mem_read8(0x4C00);
  a = (uint8_t)(a + c);
  /* nop */
  c = h;
  a = (uint8_t)(a + d);
  /* nop */
  c = h;
  a = (uint8_t)(a + e);
  /* nop */
  c = h;
  a = (uint8_t)(a + h);
  /* nop */
  c = h;
  a = (uint8_t)(a + l);
  /* nop */
  c = h;
  /* add a,(hl) */
  /* nop */
  p05_str_3();
  return;
  lab_p05_L_796B: ;
  /* jp po,0xE300 - other page/RAM */
  /* call 0xE500 - RAM/other */
  a = a & 0x00;
  flag_logic(a);
  p00_rst20();
  if (flag_pe()) return;
  /* nop */
  os_jp_hl();
  return;
}

/* flash page 5 cpu 0x792F (offset 0x392F) */
void p05_str_5(void) {
  e = c;
  l = h;
  l = c;
  mem_write8(hl(), e);
  mem_write8(hl(), h);
  a = mem_read8(0x2000);
  sp = 0x4600;
  mem_write8(hl(), d);
  h = l;
  mem_write8(hl(), c);
  a = mem_read8(0x4C00);
  a = (uint8_t)(a + c);
  /* nop */
  c = h;
  a = (uint8_t)(a + d);
  /* nop */
  c = h;
  a = (uint8_t)(a + e);
  /* nop */
  c = h;
  a = (uint8_t)(a + h);
  /* nop */
  c = h;
  a = (uint8_t)(a + l);
  /* nop */
  c = h;
  /* add a,(hl) */
  /* nop */
  p05_str_3();
  return;
}

/* flash page 5 cpu 0x7939 (offset 0x3939) */
void p05_str_6(void) {
  b = mem_read8(hl());
  mem_write8(hl(), d);
  h = l;
  mem_write8(hl(), c);
  a = mem_read8(0x4C00);
  a = (uint8_t)(a + c);
  /* nop */
  c = h;
  a = (uint8_t)(a + d);
  /* nop */
  c = h;
  a = (uint8_t)(a + e);
  /* nop */
  c = h;
  a = (uint8_t)(a + h);
  /* nop */
  c = h;
  a = (uint8_t)(a + l);
  /* nop */
  c = h;
  /* add a,(hl) */
  /* nop */
  p05_str_3();
  return;
}

/* flash page 5 cpu 0x7951 (offset 0x3951) */
void p05_str_3(void) {
  c = l;
  h = c;
  mem_write8(hl(), d);
  l = e;
  a = mem_read8(0x4F00);
  h = mem_read8(hl());
  h = mem_read8(hl());
  /* nop */
  c = a;
  l = mem_read8(hl());
  /* nop */
  p05_str_1();
  return;
}

/* flash page 5 cpu 0x7957 (offset 0x3957) */
void p05_str_7(void) {
  c = a;
  h = mem_read8(hl());
  h = mem_read8(hl());
  /* nop */
  c = a;
  l = mem_read8(hl());
  /* nop */
  p05_str_1();
  return;
}

/* flash page 5 cpu 0x795E (offset 0x395E) */
void p05_str_1(void) {
  d = h;
  a = c;
  mem_write8(hl(), b);
  h = l;
  a = mem_read8(0x0A00);
  /* nop */
  set_bc((uint16_t)(bc() - 1));
  /* nop */
  c = (uint8_t)(c + 1);
  /* nop */
  cpu_pop_hl();
  /* jp po,0xE300 - other page/RAM */
  /* call 0xE500 - RAM/other */
  a = a & 0x00;
  flag_logic(a);
  p00_rst20();
  if (flag_pe()) return;
  /* nop */
  os_jp_hl();
  return;
}

/* flash page 5 cpu 0x7986 (offset 0x3986) */
void p05_L_7986(void) {
  set_hl(0x844A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  if (flag_nz()) return;
  cpu_push_af();
  a = hw_in(PORT_INTMASK);
  cpu_push_af();
  a = 0x08;
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  hw_out(PORT_INTMASK, a);
  cpu_pop_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 3)) == 0);
  if (flag_z()) { p05_L_7A60(); return; }
  p05_L_79CF();
  return;
}

/* flash page 5 cpu 0x79A0 (offset 0x39A0) */
void p05_L_79A0(void) {
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 2)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 5)) == 0);
  if (flag_z()) { p05_L_79CF(); return; }
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x01)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p05_L_79CA;
  mem_write8((uint16_t)(iy + 0x15), (uint8_t)(mem_read8((uint16_t)(iy + 0x15)) & ~(1u << 1)));
  mem_write8((uint16_t)(iy + 0x12), (uint8_t)(mem_read8((uint16_t)(iy + 0x12)) & ~(1u << 1)));
  a = 0x03;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 3)) == 0);
  if (flag_nz()) p00_L_330F();
  if (flag_nz()) goto lab_p05_L_79CA;
  p00_L_3E55();
  p00_L_33C3();
  lab_p05_L_79CA: ;
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 3)));
  p05_L_79CF();
  return;
}

/* flash page 5 cpu 0x79CF (offset 0x39CF) */
void p05_L_79CF(void) {
  cpu_push_af();
  a = 0x32;
  mem_write8(0x844A, a);
  cpu_pop_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 3)) == 0);
  if (flag_z()) return;
  cpu_push_af();
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p05_L_79E7;
  p00_L_3F27();
  goto lab_p05_L_7A1E;
  lab_p05_L_79E7: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p05_L_79F7;
  cpu_push16(ix);
  a = a | a;
  flag_logic(a);
  p05_L_7A24();
  ix = cpu_pop16();
  goto lab_p05_L_7A1E;
  lab_p05_L_79F7: ;
  a = mem_read8(0x844E);
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p05_L_7A08;
  b = a;
  a = 0x24;
  p00_L_30FF();
  if (flag_z()) goto lab_p05_L_7A1E;
  lab_p05_L_7A08: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p05_L_7A1B;
  set_hl(mem_read16(0x86D7));
  cpu_push_hl();
  p00_L_3D47();
  cpu_pop_hl();
  mem_write16(0x86D7, hl());
  goto lab_p05_L_7A1E;
  lab_p05_L_7A1B: ;
  p00_L_3C6F();
  lab_p05_L_7A1E: ;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) & ~(1u << 3)));
  cpu_pop_af();
  return;
}

/* flash page 5 cpu 0x7A24 (offset 0x3A24) */
void p05_L_7A24(void) {
  cpu_push_af();
  /* ld ix,(0x97A3) */
  a = mem_read8(0x859A);
  flag_cmp(a, 0x55);
  if (flag_z()) goto lab_p05_L_7A41;
  flag_cmp(a, 0x49);
  p05_L_7A32();
  return;
  lab_p05_L_7A41: ;
  cpu_pop_af();
  p05_L_74B8();
  return;
}

/* flash page 5 cpu 0x7A32 (offset 0x3A32) */
void p05_L_7A32(void) {
  if (flag_z()) goto lab_p05_L_7A41;
  flag_cmp(a, 0x56);
  if (flag_z()) goto lab_p05_L_7A46;
  flag_cmp(a, 0x58);
  if (flag_z()) goto lab_p05_L_7A4B;
  cpu_pop_af();
  p00_L_3105();
  return;
  lab_p05_L_7A41: ;
  cpu_pop_af();
  p05_L_74B8();
  return;
  lab_p05_L_7A46: ;
  cpu_pop_af();
  p00_L_3471();
  return;
  lab_p05_L_7A4B: ;
  cpu_pop_af();
  p00_L_310B();
  return;
}

/* flash page 5 cpu 0x7A50 (offset 0x3A50) */
void p05_L_7A50(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 4)) == 0);
  if (flag_nz()) return;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 5)) == 0);
  if (flag_nz()) p00_L_33FF();
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 2)));
  p05_L_7A60();
  return;
}

/* flash page 5 cpu 0x7A60 (offset 0x3A60) */
void p05_L_7A60(void) {
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 2)) == 0);
  if (flag_z()) return;
  cpu_push_af();
  cpu_push_de();
  cpu_push_hl();
  a = 0x32;
  mem_write8(0x844A, a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p05_L_7A78;
  p00_L_3F27();
  goto lab_p05_L_7AC1;
  lab_p05_L_7A78: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0D)) & (1u << 6)) == 0);
  if (flag_z()) goto lab_p05_L_7A8C;
  cpu_push16(ix);
  /* ld ix,(0x97A3) */
  /* scf */
  p05_L_7A24();
  ix = cpu_pop16();
  goto lab_p05_L_7AC1;
  lab_p05_L_7A8C: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x0C)) & (1u << 3)) == 0);
  if (flag_nz()) goto lab_p05_L_7ACA;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p05_L_7AA0;
  a = 0x22;
  p00_L_30FF();
  if (flag_z()) goto lab_p05_L_7B21;
  lab_p05_L_7AA0: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p05_L_7AC3;
  lab_p05_L_7AA6: ;
  set_hl(0x81A0);
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p05_L_7AB2;
  set_hl(0x81A8);
  lab_p05_L_7AB2: ;
  set_de(mem_read16(0x86D7));
  cpu_push_de();
  a = 0x06;
  p00_L_3D3B();
  cpu_pop_de();
  mem_write16(0x86D7, de());
  lab_p05_L_7AC1: ;
  goto lab_p05_L_7B21;
  lab_p05_L_7AC3: ;
  p00_L_3D35();
  a = mem_read8(hl());
  mem_write8(0x844E, a);
  lab_p05_L_7ACA: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x34)) & (1u << 7)) == 0);
  if (flag_z()) goto lab_p05_L_7AD7;
  a = 0x23;
  p00_L_30FF();
  if (flag_z()) goto lab_p05_L_7B21;
  lab_p05_L_7AD7: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x2A)) & (1u << 1)) == 0);
  if (flag_nz()) goto lab_p05_L_7AA6;
  p00_L_3111();
  if (flag_nz()) goto lab_p05_L_7AF6;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p05_L_7AF2;
  p00_L_1923();
  if (flag_z()) goto lab_p05_L_7AF2;
  a = mem_read8(de());
  flag_cmp(a, 0x3F);
  if (flag_nz()) goto lab_p05_L_7AF6;
  lab_p05_L_7AF2: ;
  a = 0xF1;
  goto lab_p05_L_7B15;
  lab_p05_L_7AF6: ;
  a = 0xE0;
  flag_set_z((mem_read8((uint16_t)(iy + 0x05)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p05_L_7B00;
  a = (uint8_t)(a + 0x04);
  lab_p05_L_7B00: ;
  /* ld iyh,(iy+0x12) */
  flag_set_z((h & (1u << 3)) == 0);
  if (flag_z()) goto lab_p05_L_7B0A;
  a = (uint8_t)(a + 1);
  goto lab_p05_L_7B15;
  lab_p05_L_7B0A: ;
  flag_set_z((h & (1u << 4)) == 0);
  if (flag_z()) goto lab_p05_L_7B15;
  a = (uint8_t)(a + 0x02);
  flag_set_z((h & (1u << 5)) == 0);
  if (flag_z()) goto lab_p05_L_7B15;
  a = (uint8_t)(a + 1);
  lab_p05_L_7B15: ;
  b = a;
  a = mem_read8(0x844B);
  a = a | a;
  flag_logic(a);
  a = b;
  if (flag_nz()) goto lab_p05_L_7B1E;
  /* nop */
  lab_p05_L_7B1E: ;
  p00_L_3C6F();
  lab_p05_L_7B21: ;
  mem_write8((uint16_t)(iy + 0x0C), (uint8_t)(mem_read8((uint16_t)(iy + 0x0C)) | (1u << 3)));
  cpu_pop_hl();
  cpu_pop_de();
  cpu_pop_af();
  return;
}

/* flash page 5 cpu 0x7D41 (offset 0x3D41) */
void p05_L_7D41(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p05_L_7DCD();
  return;
}

/* flash page 5 cpu 0x7DCD (offset 0x3DCD) */
void p05_L_7DCD(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
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


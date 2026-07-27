/* Recovered from flash page 26 (mechanical ASM->C) */
/* cpu window 0x4000..0x7FFF prefix=p26_ */
#include "ti_cpu.h"
#include "ti_hw_api.h"
#include "ti_mem.h"
#include "ti_os_gen.h"

void p26_L_4000(void);
void p26_L_40D5(void);
void p26_L_40E3(void);
void p26_L_4100(void);
void p26_L_42BD(void);
void p26_L_42C0(void);
void p26_L_42CC(void);
void p26_L_42DB(void);
void p26_L_4413(void);
void p26_L_4414(void);
void p26_L_443B(void);
void p26_L_447A(void);
void p26_L_452C(void);
void p26_L_4532(void);
void p26_L_45CE(void);
void p26_L_462D(void);
void p26_L_463A(void);
void p26_L_467B(void);
void p26_L_46BF(void);
void p26_L_46C0(void);
void p26_L_4736(void);
void p26_L_4739(void);
void p26_L_4751(void);
void p26_L_4766(void);
void p26_L_47CF(void);
void p26_L_47D2(void);
void p26_L_4827(void);
void p26_L_4849(void);
void p26_L_4936(void);
void p26_L_4972(void);
void p26_L_4999(void);
void p26_L_4A10(void);
void p26_L_4A13(void);
void p26_L_4A14(void);
void p26_L_4A87(void);
void p26_L_4A8E(void);
void p26_L_4A90(void);
void p26_L_4ADE(void);
void p26_L_4AF9(void);
void p26_L_4B26(void);
void p26_L_4BC0(void);
void p26_L_4BDD(void);
void p26_L_4C7F(void);
void p26_L_4C9D(void);
void p26_L_4CA3(void);
void p26_L_4D4D(void);
void p26_L_4D53(void);
void p26_L_4D9B(void);
void p26_L_4DA4(void);
void p26_L_4E52(void);
void p26_L_4E73(void);
void p26_L_4EA9(void);
void p26_L_4EC8(void);
void p26_L_4EE7(void);
void p26_L_4F82(void);
void p26_L_4F88(void);
void p26_L_5017(void);
void p26_L_5029(void);
void p26_L_50A8(void);
void p26_L_50AB(void);
void p26_L_50AE(void);
void p26_L_50AF(void);
void p26_L_50B8(void);
void p26_L_50C4(void);
void p26_L_50C7(void);
void p26_L_50CD(void);
void p26_L_50EE(void);
void p26_L_5186(void);
void p26_L_5195(void);
void p26_L_524C(void);
void p26_L_5251(void);
void p26_L_526A(void);
void p26_L_5270(void);
void p26_L_5283(void);
void p26_L_5286(void);
void p26_L_52A5(void);
void p26_L_52C0(void);
void p26_L_52F9(void);
void p26_L_5301(void);
void p26_L_5326(void);
void p26_L_5342(void);
void p26_L_5346(void);
void p26_L_5355(void);
void p26_L_535B(void);
void p26_L_5377(void);
void p26_L_537D(void);
void p26_L_5390(void);
void p26_L_5396(void);
void p26_L_539C(void);
void p26_L_5438(void);
void p26_L_5439(void);
void p26_L_543F(void);
void p26_L_5446(void);
void p26_L_5450(void);
void p26_L_5495(void);
void p26_L_54B0(void);
void p26_L_54B4(void);
void p26_L_54BA(void);
void p26_L_54DE(void);
void p26_L_54F7(void);
void p26_L_5503(void);
void p26_L_557F(void);
void p26_L_559D(void);
void p26_L_55A0(void);
void p26_L_55DE(void);
void p26_L_55F8(void);
void p26_L_5605(void);
void p26_L_5620(void);
void p26_L_5671(void);
void p26_L_5682(void);
void p26_L_56A9(void);
void p26_L_56E6(void);
void p26_L_56E7(void);
void p26_L_56ED(void);
void p26_L_570B(void);
void p26_L_570E(void);
void p26_L_5725(void);
void p26_L_5748(void);
void p26_L_5759(void);
void p26_L_5760(void);
void p26_L_5782(void);
void p26_L_5788(void);
void p26_L_578E(void);
void p26_L_5798(void);
void p26_L_57B0(void);
void p26_L_57E3(void);
void p26_L_589C(void);
void p26_L_58F2(void);
void p26_L_59DC(void);
void p26_L_59E0(void);
void p26_L_59ED(void);
void p26_L_5A18(void);
void p26_L_5A71(void);
void p26_L_5A79(void);
void p26_L_5AB4(void);
void p26_L_5C10(void);
void p26_L_5C14(void);
void p26_L_5C75(void);
void p26_L_5C92(void);
void p26_L_5CD7(void);
void p26_L_5CF2(void);
void p26_L_5D01(void);
void p26_L_5D47(void);
void p26_L_5D4E(void);
void p26_L_5E0E(void);
void p26_L_5E26(void);
void p26_L_5E46(void);
void p26_L_5E7B(void);
void p26_L_5ED6(void);
void p26_L_5EE5(void);
void p26_L_5F7B(void);
void p26_L_60BA(void);
void p26_L_625C(void);
void p26_L_626D(void);
void p26_L_6279(void);
void p26_L_6289(void);
void p26_L_62A7(void);
void p26_L_62BA(void);
void p26_L_62D0(void);
void p26_L_62DA(void);
void p26_L_62E0(void);
void p26_L_6305(void);
void p26_L_6373(void);
void p26_L_637E(void);
void p26_L_6445(void);
void p26_L_64AD(void);
void p26_L_64B8(void);
void p26_L_66FC(void);
void p26_L_6703(void);
void p26_L_68C6(void);
void p26_L_68CB(void);
void p26_L_68DA(void);
void p26_L_6E90(void);
void p26_L_6E93(void);
void p26_L_6E96(void);
void p26_L_6EA4(void);
void p26_L_6EA9(void);
void p26_L_6EB5(void);
void p26_L_6EB9(void);
void p26_L_6EBC(void);
void p26_L_6ECF(void);
void p26_L_6ED4(void);
void p26_L_6EE3(void);
void p26_L_6EF2(void);
void p26_L_6F41(void);
void p26_L_7186(void);
void p26_L_718C(void);
void p26_L_71A3(void);
void p26_L_71D0(void);
void p26_L_71E9(void);
void p26_L_71F4(void);
void p26_L_723D(void);
void p26_L_72E2(void);
void p26_L_7363(void);
void p26_L_73B0(void);
void p26_L_740A(void);
void p26_L_740D(void);
void p26_L_741E(void);
void p26_L_742B(void);
void p26_L_742D(void);
void p26_L_7439(void);
void p26_L_743B(void);
void p26_L_7440(void);
void p26_L_7446(void);
void p26_L_751D(void);
void p26_L_7548(void);
void p26_L_76CD(void);
void p26_L_7749(void);
void p26_L_7758(void);
void p26_L_778C(void);
void p26_L_7799(void);
void p26_L_7834(void);
void p26_L_7843(void);
void p26_L_7853(void);
void p26_L_7866(void);
void p26_L_786E(void);
void p26_L_78F9(void);
void p26_L_7A3E(void);
void p26_L_7A48(void);
void p26_L_7A59(void);
void p26_L_7A65(void);
void p26_L_7A70(void);
void p26_L_7A8C(void);
void p26_L_7AA2(void);
void p26_L_7AAE(void);
void p26_L_7ADA(void);
void p26_L_7B45(void);
void p26_L_7B9B(void);
void p26_L_7BA0(void);
void p26_L_7BB4(void);
void p26_str_1(void);
void p26_str_2(void);
void p26_L_7E16(void);
void p26_L_7E3E(void);
void p26_L_7E41(void);

/* flash page 26 cpu 0x4000 (offset 0x0000) */
void p26_L_4000(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p26_L_40D5();
  return;
}

/* flash page 26 cpu 0x40D5 (offset 0x00D5) */
void p26_L_40D5(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p26_L_40E3();
  return;
}

/* flash page 26 cpu 0x40E3 (offset 0x00E3) */
void p26_L_40E3(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p26_L_4100();
  return;
}

/* flash page 26 cpu 0x4100 (offset 0x0100) */
void p26_L_4100(void) {
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  lab_p26_L_4194: ;
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  lab_p26_L_41B9: ;
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  lab_p26_L_41E0: ;
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  p00_rst38_isr();
  /* nop */
  a = (uint8_t)(a + b);
  h = a;
  b = h;
  a = (uint8_t)(a - l);
  cpu_rlca();
  lab_p26_L_4206: ;
  h = (uint8_t)(h + 1);
  e = c;
  h = (uint8_t)(h - 1);
  /* nop */
  a = (uint8_t)(a + c);
  d = b;
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p26_L_4194;
  a = (uint8_t)(a - e);
  mem_write8(hl(), l);
  set_hl((uint16_t)(hl() + hl()));
  mem_write8(hl(), c);
  /* nop */
  a = (uint8_t)(a + d);
  b = e;
  a = (uint8_t)(a - e);
  if (flag_nc()) goto lab_p26_L_425C;
  b = b;
  h = b;
  set_bc((uint16_t)(bc() + 1));
  /* nop */
  a = (uint8_t)(a + e);
  if (flag_nz()) goto lab_p26_L_4227;
  d = d;
  mem_write8(hl(), h);
  set_bc(0x7330);
  /* nop */
  a = (uint8_t)(a + e);
  a = (uint8_t)(a + a);
  lab_p26_L_4227: ;
  h = d;
  mem_write8(hl(), c);
  mem_write8(bc(), a);
  a = 0;
  flag_logic(a);
  a = (uint8_t)(a + l);
  set_hl(0x8400);
  if (flag_nz()) goto lab_p26_L_41B9;
  l = b;
  h = c;
  a = b;
  a = (uint8_t)(a - d);
  mem_write8(hl(), b);
  /* nop */
  a = (uint8_t)(a + h);
  b = d;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  mem_write8(hl(), 0x89);
  d = b;
  a = 0;
  flag_logic(a);
  b = h;
  /* nop */
  a = (uint8_t)(a + c);
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_af();
  d = (uint8_t)(d - 1);
  d = c;
  d = d;
  b = l;
  a = (uint8_t)(a + b);
  a = (uint8_t)(a + b);
  a = (uint8_t)(a + d);
  goto lab_p26_L_41E0;
  lab_p26_L_425C: ;
  d = (uint8_t)(d - 1);
  if (flag_z()) goto lab_p26_L_42BF;
  mem_write8(hl(), d);
  mem_write8(hl(), e);
  mem_write8(hl(), a);
  a = (uint8_t)(a - l);
  a = (uint8_t)(a + b);
  a = (uint8_t)(a + e);
  /* sbc a,c */
  b = b;
  if (flag_nc()) goto lab_p26_L_42DD;
  d = (uint8_t)(d - 1);
  cpu_ex_af();
  if (flag_z()) goto lab_p26_L_426D;
  lab_p26_L_426D: ;
  a = (uint8_t)(a + e);
  set_hl((uint16_t)(hl() + hl()));
  a = (uint8_t)(a + b);
  if (flag_c()) goto lab_p26_L_42C5;
  if (flag_nc()) goto lab_p26_L_4206;
  d = a;
  /* nop */
  a = (uint8_t)(a + h);
  b = d;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  mem_write8(hl(), 0x89);
  d = b;
  a = 0;
  flag_logic(a);
  b = h;
  a = (uint8_t)(a + b);
  a = h;
  a = (uint8_t)(a + e);
  /* daa */
  mem_write8(hl(), c);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  a = (uint8_t)(a - c);
  a = (uint8_t)(a + d);
  /* adc a,c */
  /* nop */
  a = h;
  mem_write8(hl(), 0x55);
  h = a;
  mem_write8(hl(), h);
  d = a;
  set_hl((uint16_t)(hl() + bc()));
  a = (uint8_t)(a + c);
  a = (uint8_t)(a + b);
  a = h;
  h = (uint8_t)(h - 1);
  a = (uint8_t)(a + l);
  cpu_ex_af();
  h = d;
  set_bc(0x5180);
  /* nop */
  a = h;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  b = mem_read8(hl());
  a = b;
  d = 0x02;
  b = b;
  l = b;
  a = (uint8_t)(a + b);
  a = l;
  mem_write8(de(), a);
  b = 0x37;
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) - 1));
  h = b;
  a = (uint8_t)(a + h);
  h = (uint8_t)(h + 1);
  /* nop */
  a = mem_read8(hl());
  mem_write8(hl(), 0x19);
  mem_write8(de(), a);
  b = 0x82;
  d = d;
  mem_write8(hl(), c);
  /* nop */
  a = a;
  set_hl((uint16_t)(hl() + sp));
  a = (uint8_t)(a - b);
  /* adc a,c */
  a = (uint8_t)(a - e);
  b = c;
  a = c;
  b = 0xCD;
  /* call 0xCD42 - RAM/other */
  lab_p26_L_42BF: ;
  b = d;
  p26_L_42C0();
  return;
  /* call 0xCD42 - RAM/other */
  /* call 0xCD42 - RAM/other */
  lab_p26_L_42C5: ;
  b = d;
  p26_L_42CC();
  /* call 0xCD42 - RAM/other */
  p26_L_42CC();
  p26_L_42CC();
  return;
  /* call 0xE542 - RAM/other */
  p00_L_1128();
  p00_L_0D1F();
  cpu_pop_hl();
  p00_L_11F8();
  cpu_push_hl();
  p00_rst30();
  cpu_pop_hl();
  return;
  lab_p26_L_42DD: ;
  goto lab_p26_L_431D;
  lab_p26_L_431C: ;
  p00_L_22FC();
  lab_p26_L_431D: ;
  /* call 0xCD22 - RAM/other */
  p00_L_1221();
  set_hl(0xCD12);
  p00_L_107E();
  a = mem_read8(hl());
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p26_L_435E;
  if (flag_c()) goto lab_p26_L_433A;
  set_de((uint16_t)(de() + 1));
  if (flag_z()) goto lab_p26_L_433A;
  p00_L_0C2A();
  p00_L_233D();
  p00_L_10EF();
  p00_L_0D1F();
  p00_L_10DD();
  goto lab_p26_L_431C;
  lab_p26_L_433A: ;
  p00_L_219B();
  p00_L_21D6();
  p00_L_1246();
  p00_L_0C2D();
  p00_L_1169();
  set_hl(0x4200);
  p00_rst20();
  p26_L_42BD();
  p00_rst18();
  set_hl(0x423F);
  p00_rst20();
  cpu_push_hl();
  p00_L_1128();
  p00_L_0C2D();
  cpu_pop_hl();
  p26_L_42BD();
  lab_p26_L_435E: ;
  flag_cmp(a, l);
  b = d;
  p00_L_2196();
  p00_rst18();
  p00_L_2315();
  p00_L_0D1F();
  p00_L_2196();
  p00_L_0ED0();
  p00_L_38A3();
  p00_L_21A7();
  return;
}

/* flash page 26 cpu 0x42BD (offset 0x02BD) */
void p26_L_42BD(void) {
  p26_L_42CC();
  p26_L_42C0();
  return;
}

/* flash page 26 cpu 0x42C0 (offset 0x02C0) */
void p26_L_42C0(void) {
  p26_L_42CC();
  p26_L_42CC();
  p26_L_42CC();
  p26_L_42CC();
  p26_L_42CC();
  return;
}

/* flash page 26 cpu 0x42CC (offset 0x02CC) */
void p26_L_42CC(void) {
  cpu_push_hl();
  p00_L_1128();
  p00_L_0D1F();
  cpu_pop_hl();
  p00_L_11F8();
  cpu_push_hl();
  p00_rst30();
  cpu_pop_hl();
  return;
}

/* flash page 26 cpu 0x42DB (offset 0x02DB) */
void p26_L_42DB(void) {
  p00_L_1884();
  a = 0x86;
  set_hl(0x8483);
  p00_L_0FE3();
  p00_L_107E();
  if (flag_c()) goto lab_p26_L_42EE;
  if (flag_nz()) { p00_L_24C9(); return; }
  lab_p26_L_42EE: ;
  p00_rst18();
  p00_L_120C();
  p00_L_107E();
  if (flag_nc()) goto lab_p26_L_4376;
  p00_L_1202();
  lab_p26_L_42FB: ;
  p00_L_22F7();
  p00_L_1241();
  p00_L_107E();
  if (flag_c()) goto lab_p26_L_431C;
  if (flag_z()) goto lab_p26_L_431C;
  p00_L_1135();
  p00_L_0ED0();
  p00_L_10DD();
  p00_L_22FC();
  p00_L_0C1B();
  p00_L_233D();
  goto lab_p26_L_42FB;
  lab_p26_L_431C: ;
  p00_L_22FC();
  p00_L_1221();
  p00_L_107E();
  if (flag_c()) goto lab_p26_L_433A;
  if (flag_z()) goto lab_p26_L_433A;
  p00_L_0C2A();
  p00_L_233D();
  p00_L_10EF();
  p00_L_0D1F();
  p00_L_10DD();
  goto lab_p26_L_431C;
  lab_p26_L_433A: ;
  p00_L_219B();
  p00_L_21D6();
  p00_L_1246();
  p00_L_0C2D();
  p00_L_1169();
  set_hl(0x4200);
  p00_rst20();
  p26_L_42BD();
  p00_rst18();
  set_hl(0x423F);
  p00_rst20();
  cpu_push_hl();
  p00_L_1128();
  p00_L_0C2D();
  cpu_pop_hl();
  p26_L_42BD();
  p00_L_2196();
  p00_rst18();
  p00_L_2315();
  p00_L_0D1F();
  p00_L_2196();
  p00_L_0ED0();
  p00_L_38A3();
  p00_L_21A7();
  return;
  lab_p26_L_4376: ;
  p00_L_0ECC();
  p00_L_0D1E();
  p00_L_1169();
  set_hl(0x427E);
  p00_rst20();
  p26_L_42C0();
  p00_rst18();
  p00_L_2315();
  p00_L_38A3();
  p00_rst18();
  p00_L_2324();
  set_hl(0x0FC3);
  p00_L_0C25();
  p00_L_2196();
  p00_L_0D1F();
  p00_rst18();
  a = 0x03;
  p00_L_152C();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_2196();
  p00_L_0C13();
  set_hl(0x42B4);
  p00_L_0C20();
  p00_L_10DD();
  p00_L_219B();
  p00_L_2196();
  p00_L_0ED0();
  p00_L_10EF();
  p00_rst30();
  return;
}

/* flash page 26 cpu 0x4413 (offset 0x0413) */
void p26_L_4413(void) {
  p00_rst08();
  p26_L_4414();
  return;
}

/* flash page 26 cpu 0x4414 (offset 0x0414) */
void p26_L_4414(void) {
  p00_L_1135();
  p00_L_0ED0();
  return;
}

/* flash page 26 cpu 0x443B (offset 0x043B) */
void p26_L_443B(void) {
  a = mem_read8(0x8479);
  flag_cmp(a, 0xC0);
  if (flag_nc()) { p00_L_128A(); return; }
  p00_L_0D1E();
  p00_L_0D16();
  p00_L_0E4C();
  p00_L_3933();
  set_hl(0x4455);
  p00_L_0EC1();
  return;
}

/* flash page 26 cpu 0x447A (offset 0x047A) */
void p26_L_447A(void) {
  p00_L_1251();
  p00_L_0C13();
  return;
}

/* flash page 26 cpu 0x452C (offset 0x052C) */
void p26_L_452C(void) {
  p00_L_21A4();
  p00_L_21A4();
  return;
}

/* flash page 26 cpu 0x4532 (offset 0x0532) */
void p26_L_4532(void) {
  p26_L_463A();
  p00_L_1171();
  p00_rst08();
  p00_L_219B();
  p00_L_1169();
  p00_L_14CC();
  if (flag_nz()) p00_L_0ED0();
  p00_rst18();
  p00_L_113A();
  p00_L_2315();
  p00_rst18();
  p00_L_3B5B();
  cpu_ex_de_hl();
  set_hl((uint16_t)(hl() + 1));
  set_de(0x03E8);
  p00_L_192A();
  if (flag_nc()) { p00_L_24ED(); return; }
  cpu_push_hl();
  p00_L_1C40();
  mem_write16(0x84D7, de());
  p00_L_1135();
  p00_L_233D();
  p00_L_1130();
  p00_L_1251();
  p00_L_107E();
  if (flag_nz()) goto lab_p26_L_4587;
  set_hl(0x0001);
  p26_L_45CE();
  p00_L_1229();
  cpu_pop_hl();
  p00_L_3B13();
  lab_p26_L_4581: ;
  p00_L_22FC();
  p26_L_4C7F();
  return;
  lab_p26_L_4587: ;
  p00_L_14C7();
  if (flag_nz()) goto lab_p26_L_459E;
  p00_L_1229();
  set_hl(0x0001);
  p00_L_3B13();
  set_hl(0x0002);
  p26_L_45CE();
  cpu_pop_hl();
  goto lab_p26_L_4581;
  lab_p26_L_459E: ;
  p00_L_113A();
  p00_L_38A3();
  p00_L_231F();
  p00_L_0D1F();
  p00_rst18();
  p00_L_2324();
  p00_L_38A3();
  p00_L_2375();
  p00_L_22CF();
  p00_L_0C1B();
  p00_L_2389();
  p00_L_128A();
  p00_rst18();
  set_hl(0x0000);
  cpu_pop_de();
  p26_L_467B();
  p00_L_2324();
  p26_L_5377();
  return;
}

/* flash page 26 cpu 0x45CE (offset 0x05CE) */
void p26_L_45CE(void) {
  mem_write16(0x8483, hl());
  p00_L_128A();
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_push_bc();
  cpu_push_hl();
  set_bc((uint16_t)(bc() - 1));
  cpu_push_bc();
  set_de(mem_read16(0x84D7));
  set_hl(mem_read16(0x8483));
  p00_L_3AE9();
  cpu_ex_de_hl();
  lab_p26_L_45E5: ;
  p00_L_11FD();
  cpu_pop_bc();
  set_bc((uint16_t)(bc() - 1));
  a = c;
  a = a | c;
  flag_logic(a);
  if (flag_z()) return;
  cpu_push_bc();
  goto lab_p26_L_45E5;
}

/* flash page 26 cpu 0x462D (offset 0x062D) */
void p26_L_462D(void) {
  p00_rst08();
  p00_L_2315();
  p26_L_4A87();
  p00_L_219B();
  /* scf */
  goto lab_p26_L_4642;
  lab_p26_L_4642: ;
  cpu_push_af();
  p26_L_46BF();
  p00_L_1100();
  p00_L_2315();
  p00_L_187F();
  cpu_pop_af();
  if (flag_c()) goto lab_p26_L_465A;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x83);
  if (flag_nc()) { p00_L_24C9(); return; }
  lab_p26_L_465A: ;
  p00_L_113F();
  return;
}

/* flash page 26 cpu 0x463A (offset 0x063A) */
void p26_L_463A(void) {
  p26_L_4A87();
  p00_rst18();
  p00_L_1179();
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  p26_L_46BF();
  p00_L_1100();
  p00_L_2315();
  p00_L_187F();
  cpu_pop_af();
  if (flag_c()) goto lab_p26_L_465A;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x83);
  if (flag_nc()) { p00_L_24C9(); return; }
  lab_p26_L_465A: ;
  p00_L_113F();
  return;
}

/* flash page 26 cpu 0x467B (offset 0x067B) */
void p26_L_467B(void) {
  lab_p26_L_467B: ;
  set_hl((uint16_t)(hl() + 1));
  set_de((uint16_t)(de() - 1));
  a = d;
  a = a | e;
  flag_logic(a);
  if (flag_z()) goto lab_p26_L_46B6;
  cpu_push_de();
  cpu_push_hl();
  p00_L_2315();
  p00_L_392D();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_3B13();
  p00_L_22FC();
  p00_L_0C1B();
  p00_L_233D();
  p00_rst08();
  p00_L_22D9();
  p00_L_0C2D();
  p00_L_22F7();
  p00_L_0ED0();
  p00_L_38A3();
  p00_L_22C7();
  p00_rst30();
  p00_L_2310();
  p00_rst30();
  p00_L_235C();
  cpu_pop_hl();
  cpu_pop_de();
  goto lab_p26_L_467B;
  lab_p26_L_46B6: ;
  cpu_push_hl();
  p00_L_392D();
  cpu_pop_hl();
  p00_L_3B13();
  return;
}

/* flash page 26 cpu 0x46BF (offset 0x06BF) */
void p26_L_46BF(void) {
  p00_rst18();
  p26_L_46C0();
  return;
}

/* flash page 26 cpu 0x46C0 (offset 0x06C0) */
void p26_L_46C0(void) {
  p00_L_1873();
  p00_L_1159();
  p26_L_447A();
  p00_L_1873();
  return;
}

/* flash page 26 cpu 0x4736 (offset 0x0736) */
void p26_L_4736(void) {
  p26_L_4A87();
  p26_L_4739();
  return;
}

/* flash page 26 cpu 0x4739 (offset 0x0739) */
void p26_L_4739(void) {
  p00_rst18();
  p00_rst18();
  p00_L_22CF();
  return;
}

/* flash page 26 cpu 0x4751 (offset 0x0751) */
void p26_L_4751(void) {
  p00_L_2196();
  p00_L_0C13();
  p00_L_21A4();
  p00_L_21A7();
  return;
}

/* flash page 26 cpu 0x4766 (offset 0x0766) */
void p26_L_4766(void) {
  p00_rst18();
  p00_L_1179();
  p00_L_1884();
  p00_rst18();
  p00_L_0D16();
  p00_rst18();
  p00_rst30();
  p00_rst18();
  p26_L_42DB();
  p00_rst18();
  p00_L_2324();
  p26_L_42DB();
  p00_L_2196();
  p00_L_0C13();
  set_hl(0x475D);
  p00_L_0C25();
  p00_rst18();
  p00_L_22CF();
  p00_L_38A3();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_2196();
  p00_rst30();
  p00_rst18();
  p00_L_22D9();
  p00_L_0D1E();
  p00_L_22C7();
  p00_rst30();
  p00_L_38A3();
  p00_L_2310();
  p00_L_0D1F();
  p00_L_2196();
  p00_L_0C13();
  p00_L_392D();
  p26_L_452C();
  return;
}

/* flash page 26 cpu 0x47CF (offset 0x07CF) */
void p26_L_47CF(void) {
  p00_L_2310();
  p26_L_47D2();
  return;
}

/* flash page 26 cpu 0x47D2 (offset 0x07D2) */
void p26_L_47D2(void) {
  p00_rst18();
  p00_L_127B();
  a = mem_read8(0x8479);
  flag_cmp(a, 0xB2);
  if (flag_nc()) goto lab_p26_L_4800;
  p00_L_10E6();
  p00_L_1179();
  p00_L_0D16();
  p00_rst18();
  p00_L_21E0();
  p00_L_2324();
  p00_L_0D1E();
  p00_L_10EF();
  p00_rst30();
  p26_L_4413();
  p26_L_4BDD();
  p00_L_0D16();
  p00_L_1100();
  lab_p26_L_4800: ;
  p00_L_219B();
  p00_L_15CB();
  cpu_push_af();
  p00_L_113F();
  cpu_pop_af();
  if (flag_nz()) p26_L_447A();
  return;
}

/* flash page 26 cpu 0x4827 (offset 0x0827) */
void p26_L_4827(void) {
  p00_L_15CB();
  if (flag_nz()) { p00_L_1229(); return; }
  a = mem_read8(0x8479);
  flag_cmp(a, 0xE3);
  if (flag_nc()) { p00_L_128A(); return; }
  flag_set_z((b & (1u << 0)) == 0);
  if (flag_z()) goto lab_p26_L_4AEE;
  p00_L_0D16();
  p00_L_10DD();
  p00_L_2315();
  p00_L_0D16();
  p00_L_10EF();
  p26_L_4849();
  return;
  lab_p26_L_4AEE: ;
  p00_rst18();
  p00_L_22CF();
  p00_rst18();
  p00_L_22CF();
  p26_L_4BC0();
  return;
}

/* flash page 26 cpu 0x4849 (offset 0x0849) */
void p26_L_4849(void) {
  p00_L_1884();
  p00_L_14CC();
  if (flag_z()) { p00_L_1229(); return; }
  p00_rst18();
  p00_L_21E0();
  p00_L_107E();
  if (flag_c()) goto lab_p26_L_48A3;
  if (flag_z()) goto lab_p26_L_48A3;
  p00_L_10DD();
  p00_L_0ECC();
  p00_L_1171();
  p00_L_1169();
  lab_p26_L_4869: ;
  a = 0x88;
  p00_L_0FE0();
  p00_L_1108();
  p00_L_0D1F();
  p00_rst08();
  p00_L_1130();
  p00_L_107E();
  if (flag_nc()) goto lab_p26_L_489D;
  set_hl(0x8499);
  p00_L_186A();
  p00_rst08();
  p00_L_22FC();
  p00_L_0ED0();
  p00_L_1108();
  p00_L_0D1F();
  p00_L_1171();
  p00_rst08();
  p00_L_1128();
  p00_rst30();
  p00_L_1169();
  goto lab_p26_L_4869;
  lab_p26_L_489D: ;
  p26_L_4936();
  p26_L_447A();
  return;
  lab_p26_L_48A3: ;
  p00_L_0FDE();
  p00_L_1171();
  p00_L_22FC();
  p00_L_0C1B();
  p00_L_2310();
  p00_L_0C2D();
  p00_rst18();
  p00_L_0ECC();
  p00_rst18();
  p00_L_1169();
  p00_L_128A();
  lab_p26_L_48C0: ;
  p00_L_0C1B();
  p00_rst18();
  p00_L_22B3();
  p00_L_0C13();
  p00_L_22F7();
  p00_L_0D1F();
  p00_L_10DD();
  p00_L_2310();
  p00_L_0D1F();
  p00_L_1100();
  p00_L_2324();
  p00_L_1246();
  p00_rst30();
  p00_L_2375();
  p00_L_10F8();
  p26_L_4A13();
  p00_L_0ECC();
  p00_L_235C();
  p00_L_1108();
  p26_L_4414();
  p00_L_231F();
  p26_L_4A13();
  p00_L_1171();
  p00_L_2310();
  p00_L_0D1F();
  p00_rst08();
  p00_L_1130();
  p00_L_0D1F();
  p00_L_1169();
  p00_L_1179();
  p00_L_0C2A();
  a = mem_read8(0x847A);
  cpu_push_af();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x78);
  cpu_push_af();
  p00_L_219B();
  cpu_pop_af();
  cpu_pop_bc();
  if (flag_c()) goto lab_p26_L_4933;
  a = b;
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p26_L_4933;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x82);
  if (flag_nz()) goto lab_p26_L_48C0;
  lab_p26_L_4933: ;
  p00_L_21A4();
  p26_L_4936();
  return;
}

/* flash page 26 cpu 0x4936 (offset 0x0936) */
void p26_L_4936(void) {
  p00_L_21CC();
  p00_L_2315();
  p00_L_38A3();
  p00_L_231F();
  p00_L_0D1F();
  p00_rst18();
  p00_L_1179();
  p26_L_42DB();
  p00_L_2196();
  p00_L_0C13();
  p00_L_10DD();
  p00_L_2310();
  a = 0x03;
  p00_L_152C();
  p00_L_0D1F();
  p00_L_10EF();
  p00_L_0C13();
  p00_L_392D();
  p00_L_2196();
  p00_L_0D1F();
  p00_L_21A4();
  return;
}

/* flash page 26 cpu 0x4972 (offset 0x0972) */
void p26_L_4972(void) {
  p00_L_10EF();
  p00_L_0D1F();
  return;
}

/* flash page 26 cpu 0x4999 (offset 0x0999) */
void p26_L_4999(void) {
  p00_rst18();
  p00_L_1179();
  p26_L_4A87();
  p00_L_0D16();
  p00_L_1884();
  p00_rst18();
  p00_L_2315();
  p00_L_15CB();
  if (flag_nz()) goto lab_p26_L_49CA;
  p00_L_14C7();
  if (flag_nz()) goto lab_p26_L_49D0;
  p00_L_219B();
  p00_L_21A7();
  p00_L_1251();
  p00_L_107E();
  if (flag_c()) { p00_L_24C9(); return; }
  if (flag_nz()) goto lab_p26_L_49CD;
  set_hl(0x0FC3);
  p00_rst20();
  return;
  lab_p26_L_49CA: ;
  p00_L_21A4();
  lab_p26_L_49CD: ;
  p00_L_128A();
  return;
  lab_p26_L_49D0: ;
  p00_L_0D16();
  p00_L_38A3();
  p00_L_1100();
  p00_L_22FC();
  p00_L_0C2A();
  p00_L_10F8();
  p00_L_0D1F();
  p00_rst18();
  p00_L_2315();
  p26_L_42DB();
  p00_L_2196();
  p00_L_0C13();
  p00_rst18();
  a = 0x03;
  p00_L_152C();
  p00_L_0D16();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_2196();
  p00_L_0C13();
  p00_L_392D();
  p00_L_0D16();
  p00_L_21A4();
  return;
}

/* flash page 26 cpu 0x4A10 (offset 0x0A10) */
void p26_L_4A10(void) {
  p00_L_1251();
  p26_L_4A13();
  return;
}

/* flash page 26 cpu 0x4A13 (offset 0x0A13) */
void p26_L_4A13(void) {
  p00_rst30();
  p26_L_4A14();
  return;
}

/* flash page 26 cpu 0x4A14 (offset 0x0A14) */
void p26_L_4A14(void) {
  a = mem_read8(0x8479);
  flag_cmp(a, 0x1D);
  if (flag_nc()) return;
  a = 0x1D;
  p00_L_0FE0();
  return;
}

/* flash page 26 cpu 0x4A87 (offset 0x0A87) */
void p26_L_4A87(void) {
  p00_L_14D5();
  if (flag_z()) return;
  p00_L_24C9();
  return;
}

/* flash page 26 cpu 0x4A8E (offset 0x0A8E) */
void p26_L_4A8E(void) {
  a = 0x01;
  p26_L_4A90();
  return;
}

/* flash page 26 cpu 0x4A90 (offset 0x0A90) */
void p26_L_4A90(void) {
  goto lab_p26_L_4A90;
  lab_p26_L_4A8B: ;
  p00_L_24C9();
  return;
  lab_p26_L_4A90: ;
  cpu_push_af();
  p00_L_1130();
  d = 0x01;
  p00_L_0FB1();
  lab_p26_L_4A99: ;
  p00_L_163B();
  if (flag_nc()) goto lab_p26_L_4AA7;
  cpu_pop_af();
  a = mem_read8(0x847A);
  flag_cmp(a, 0x50);
  if (flag_z()) return;
  goto lab_p26_L_4A8B;
  lab_p26_L_4AA7: ;
  p00_L_0C2A();
  p00_L_14C7();
  cpu_pop_bc();
  if (flag_z()) return;
  a = b;
  p00_L_1169();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_4AC0;
  p00_rst08();
  p00_L_22FC();
  p00_L_0ED0();
  goto lab_p26_L_4AD6;
  lab_p26_L_4AC0: ;
  p00_L_1135();
  p00_L_0C2A();
  p00_L_10DD();
  p00_rst08();
  p00_L_1130();
  p00_L_0ED0();
  p00_L_22F7();
  p00_L_0D1F();
  lab_p26_L_4AD6: ;
  p00_L_233D();
  p00_L_1130();
  goto lab_p26_L_4A99;
}

/* flash page 26 cpu 0x4ADE (offset 0x0ADE) */
void p26_L_4ADE(void) {
  goto lab_p26_L_4ADE;
  lab_p26_L_483A: ;
  p00_L_0D16();
  p00_L_10DD();
  p00_L_2315();
  p00_L_0D16();
  p00_L_10EF();
  p26_L_4849();
  return;
  lab_p26_L_4ADE: ;
  cpu_push_bc();
  p00_L_1287();
  p00_L_107E();
  cpu_pop_bc();
  if (flag_c()) { p00_L_1229(); return; }
  flag_set_z((b & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p26_L_483A;
  p00_rst18();
  p00_L_22CF();
  p00_rst18();
  p00_L_22CF();
  p26_L_4BC0();
  return;
}

/* flash page 26 cpu 0x4AF9 (offset 0x0AF9) */
void p26_L_4AF9(void) {
  p26_L_4A87();
  p00_rst18();
  p00_L_0D16();
  p00_rst18();
  p00_L_2324();
  p26_L_4A87();
  p00_L_1246();
  p00_L_107E();
  cpu_push_af();
  p00_L_0D16();
  p00_rst18();
  cpu_pop_af();
  return;
}

/* flash page 26 cpu 0x4B26 (offset 0x0B26) */
void p26_L_4B26(void) {
  p00_rst18();
  set_hl(0x8BBD);
  p00_rst20();
  p00_rst18();
  set_hl(0x8BD8);
  p00_rst20();
  p26_L_4AF9();
  cpu_push_af();
  p00_L_22B3();
  p00_L_128A();
  p00_L_107E();
  if (flag_nc()) goto lab_p26_L_4BAB;
  cpu_pop_af();
  p00_L_22CF();
  p00_L_0D1F();
  p00_L_231F();
  p00_L_0ED0();
  p00_rst18();
  p00_L_0C1B();
  p00_L_38A3();
  p00_L_1100();
  p00_L_2315();
  p00_L_231F();
  p00_rst30();
  p00_rst08();
  p00_L_113F();
  p00_L_0D1F();
  p00_rst18();
  p00_L_1179();
  p26_L_42DB();
  p00_rst18();
  p00_L_22CF();
  p26_L_42DB();
  p00_L_2196();
  p00_L_0C13();
  p00_rst18();
  p00_L_22D9();
  p26_L_42DB();
  p00_L_2196();
  p00_L_0C13();
  p00_L_2196();
  p00_L_0C2D();
  p00_rst18();
  p00_L_2315();
  p00_L_38A3();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_2196();
  p00_rst30();
  p00_L_392D();
  p00_L_2262();
  p00_L_0ED0();
  set_de(0x0036);
  p00_L_21B6();
  return;
  lab_p26_L_4BAB: ;
  if (flag_nz()) goto lab_p26_L_4BB4;
  cpu_pop_af();
  if (flag_z()) goto lab_p26_L_4BBB;
  if (flag_c()) { p00_L_24C9(); return; }
  cpu_push_af();
  lab_p26_L_4BB4: ;
  cpu_pop_af();
  p00_L_128A();
  lab_p26_L_4BB8: ;
  p26_L_5377();
  return;
  lab_p26_L_4BBB: ;
  p00_L_1229();
  goto lab_p26_L_4BB8;
}

/* flash page 26 cpu 0x4BC0 (offset 0x0BC0) */
void p26_L_4BC0(void) {
  p26_L_4AF9();
  p00_L_22D9();
  p00_L_22C7();
  p00_L_0D1F();
  p00_L_231F();
  p00_rst30();
  p00_rst08();
  p00_L_2324();
  p00_L_0ED0();
  p26_L_4BDD();
  p26_L_4C7F();
  return;
}

/* flash page 26 cpu 0x4BDD (offset 0x0BDD) */
void p26_L_4BDD(void) {
  p26_L_46BF();
  p00_L_163B();
  cpu_push_af();
  p00_L_2315();
  p00_L_1884();
  p00_L_2324();
  p00_L_1884();
  p00_L_22FC();
  cpu_pop_af();
  if (flag_nc()) { p26_L_4C7F(); return; }
  p00_L_38A3();
  p00_L_231F();
  p00_L_0D1F();
  p00_rst18();
  p00_L_2315();
  p26_L_447A();
  p00_L_38A3();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_2196();
  p00_rst30();
  p00_rst18();
  p00_L_22CF();
  p00_L_231F();
  p00_rst30();
  p26_L_42DB();
  p00_rst18();
  p00_L_22D9();
  p26_L_42DB();
  p00_L_2196();
  p00_L_0C13();
  p00_rst18();
  p00_L_22CF();
  p26_L_42DB();
  p00_L_2196();
  p00_L_0C13();
  p00_L_2196();
  p00_rst30();
  p00_L_392D();
  p00_rst18();
  p26_L_4C9D();
  p00_rst30();
  p00_L_1246();
  p00_rst30();
  p00_L_1100();
  p00_L_22CF();
  p00_L_0C1B();
  p26_L_5450();
  p00_L_2310();
  p00_L_107E();
  cpu_push_af();
  p26_L_4C9D();
  cpu_pop_af();
  if (flag_nc()) goto lab_p26_L_4C85;
  p00_L_21E0();
  p00_rst18();
  p00_L_22CF();
  p26_L_447A();
  p00_rst18();
  p26_L_4CA3();
  p00_L_231F();
  p00_L_0ED0();
  p00_L_2196();
  p00_L_0D1F();
  p26_L_447A();
  p26_L_4C7F();
  return;
  lab_p26_L_4C85: ;
  p00_L_222C();
  p00_L_22CF();
  p00_rst18();
  p26_L_4CA3();
  p00_L_22C7();
  p00_L_0ED0();
  p00_L_2196();
  p00_L_0D1F();
  p26_L_4C7F();
  return;
}

/* flash page 26 cpu 0x4C7F (offset 0x0C7F) */
void p26_L_4C7F(void) {
  set_bc(0x001B);
  p00_L_21AA();
  return;
}

/* flash page 26 cpu 0x4C9D (offset 0x0C9D) */
void p26_L_4C9D(void) {
  p00_L_22CF();
  p00_L_231F();
  return;
}

/* flash page 26 cpu 0x4CA3 (offset 0x0CA3) */
void p26_L_4CA3(void) {
  p00_L_1229();
  p00_rst18();
  p00_L_22CF();
  p00_L_0C1B();
  p00_L_10DD();
  p00_L_22CF();
  p00_L_231F();
  p00_rst30();
  p00_L_2310();
  p00_L_0D1F();
  p26_L_5788();
  p26_L_447A();
  p26_L_4A14();
  p00_L_0ECC();
  p00_rst18();
  p00_rst18();
  p00_L_128A();
  lab_p26_L_4CCE: ;
  p00_L_0C1B();
  p00_rst18();
  p00_L_2262();
  p00_L_0C13();
  p00_L_22F7();
  p26_L_4DA4();
  p00_L_2277();
  p00_L_0C2A();
  p26_L_4D53();
  p00_L_231F();
  p00_L_0D1F();
  p26_L_4D9B();
  p00_L_2277();
  p00_L_22F7();
  p00_rst30();
  p00_L_10DD();
  p00_L_2277();
  p00_L_2262();
  p00_rst30();
  p00_L_22F7();
  p00_rst30();
  p00_L_10EF();
  p00_L_0E4C();
  p26_L_4DA4();
  p00_L_2277();
  p00_L_0C1B();
  p26_L_4D53();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_1169();
  p26_L_4D9B();
  p00_L_1130();
  p00_L_0C2A();
  p00_L_1169();
  p00_L_219B();
  a = mem_read8(0x84B0);
  flag_cmp(a, 0x79);
  a = mem_read8(0x84B1);
  if (flag_c()) goto lab_p26_L_4D4A;
  if (flag_nz()) goto lab_p26_L_4D3F;
  flag_cmp(a, 0x30);
  if (flag_c()) goto lab_p26_L_4D4A;
  lab_p26_L_4D3F: ;
  flag_cmp(a, 0x00);
  if (flag_z()) goto lab_p26_L_4D4A;
  a = mem_read8(0x8479);
  flag_cmp(a, 0x82);
  if (flag_nz()) goto lab_p26_L_4CCE;
  lab_p26_L_4D4A: ;
  p00_L_22FC();
  p26_L_4D4D();
  return;
}

/* flash page 26 cpu 0x4D4D (offset 0x0D4D) */
void p26_L_4D4D(void) {
  set_bc(0x0036);
  p00_L_21AA();
  return;
}

/* flash page 26 cpu 0x4D53 (offset 0x0D53) */
void p26_L_4D53(void) {
  p00_L_10DD();
  p00_L_22FC();
  p00_L_0C18();
  p00_L_1100();
  p00_L_10EF();
  p00_rst30();
  p00_L_1171();
  p00_L_2277();
  p00_L_10F8();
  p00_rst30();
  p00_L_1108();
  p00_L_0D1F();
  p00_rst08();
  p00_L_1130();
  p00_L_0ED0();
  p00_L_1169();
  p00_L_231F();
  p00_L_0D1F();
  p26_L_4A10();
  p00_L_0ECC();
  p00_L_2375();
  p00_L_1130();
  p00_L_22C7();
  p00_L_0ED0();
  p26_L_4A10();
  p00_L_2389();
  return;
}

/* flash page 26 cpu 0x4D9B (offset 0x0D9B) */
void p26_L_4D9B(void) {
  p00_L_2310();
  p00_L_0D1F();
  p00_L_235C();
  return;
}

/* flash page 26 cpu 0x4DA4 (offset 0x0DA4) */
void p26_L_4DA4(void) {
  p00_L_0D1F();
  p00_L_22B3();
  p00_L_0D1F();
  p00_L_1169();
  return;
}

/* flash page 26 cpu 0x4E52 (offset 0x0E52) */
void p26_L_4E52(void) {
  flag_cmp(a, b);
  if (flag_c()) return;
  cpu_push_bc();
  cpu_push_af();
  p00_L_1037();
  if (flag_nz()) goto lab_p26_L_4E6F;
  cpu_pop_af();
  cpu_push_af();
  a = (uint8_t)(a - 1);
  set_hl(0x4E6F);
  p00_L_25A2();
  b = a;
  p00_L_3981();
  p00_L_25C8();
  cpu_pop_af();
  cpu_pop_bc();
  a = a | a;
  flag_logic(a);
  return;
  lab_p26_L_4E6F: ;
  cpu_pop_af();
  cpu_pop_bc();
  /* scf */
  return;
}

/* flash page 26 cpu 0x4E73 (offset 0x0E73) */
void p26_L_4E73(void) {
  cpu_push_hl();
  p26_L_4E52();
  cpu_pop_hl();
  if (flag_c()) return;
  cpu_push_hl();
  cpu_push_bc();
  a = (uint8_t)(a - b);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p26_L_4E8D;
  if (flag_c()) goto lab_p26_L_4E89;
  flag_cmp(a, 0x03);
  if (flag_nc()) { p00_L_24E5(); return; }
  goto lab_p26_L_4E91;
  lab_p26_L_4E89: ;
  p00_rst18();
  p00_L_128A();
  lab_p26_L_4E8D: ;
  p00_rst18();
  p00_L_128A();
  lab_p26_L_4E91: ;
  p00_rst18();
  cpu_pop_bc();
  cpu_pop_hl();
  set_de(0x0012);
  p26_L_4EC8();
  p00_L_2315();
  p26_L_55A0();
  p00_L_219B();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 7)));
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 26 cpu 0x4EA9 (offset 0x0EA9) */
void p26_L_4EA9(void) {
  cpu_push_hl();
  p26_L_4E52();
  cpu_pop_hl();
  if (flag_c()) return;
  cpu_push_hl();
  cpu_push_bc();
  a = (uint8_t)(a - b);
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p26_L_4EBC;
  if (flag_nc()) { p00_L_24E5(); return; }
  p26_L_5CF2();
  lab_p26_L_4EBC: ;
  p26_L_5251();
  cpu_pop_bc();
  cpu_pop_hl();
  set_de(0x0009);
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 7)));
  p26_L_4EC8();
  return;
}

/* flash page 26 cpu 0x4EC8 (offset 0x0EC8) */
void p26_L_4EC8(void) {
  cpu_push_hl();
  set_hl(mem_read16(0x9824));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_pop_de();
  lab_p26_L_4ED0: ;
  a = mem_read8(de());
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  p00_L_23CF();
  cpu_push_hl();
  cpu_push_bc();
  p00_rst20();
  p00_L_1897();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_pop_de();
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p26_L_4ED0;
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 26 cpu 0x4EE7 (offset 0x0EE7) */
void p26_L_4EE7(void) {
  cpu_push_bc();
  b = 0x06;
  p26_L_4E52();
  cpu_pop_bc();
  if (flag_c()) return;
  cpu_push_bc();
  cpu_push_af();
  cpu_pop_af();
  flag_cmp(a, 0x07);
  if (flag_c()) goto lab_p26_L_4F06;
  if (flag_z()) goto lab_p26_L_4F0E;
  flag_cmp(a, 0x09);
  if (flag_c()) goto lab_p26_L_4F18;
  lab_p26_L_4EFC: ;
  if (flag_nz()) { p00_L_24E5(); return; }
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_4EFC;
  goto lab_p26_L_4F1C;
  lab_p26_L_4F06: ;
  p26_L_5CF2();
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  if (flag_z()) goto lab_p26_L_4F11;
  lab_p26_L_4F0E: ;
  p00_rst18();
  goto lab_p26_L_4F15;
  lab_p26_L_4F11: ;
  p00_L_128A();
  p00_rst18();
  lab_p26_L_4F15: ;
  p00_L_128A();
  lab_p26_L_4F18: ;
  p00_rst18();
  p00_L_128A();
  lab_p26_L_4F1C: ;
  p00_rst18();
  set_de(0x001B);
  c = 0x06;
  set_hl(0x4F6F);
  p26_L_4EC8();
  p26_L_6289();
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 7)));
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p26_L_4F52;
  p00_L_21A7();
  p00_L_2315();
  p26_L_5251();
  p00_L_21A7();
  p00_L_235C();
  p00_L_219B();
  p00_L_14C7();
  p26_L_5301();
  p00_L_21A4();
  cpu_pop_af();
  p26_L_524C();
  return;
  lab_p26_L_4F52: ;
  cpu_pop_af();
  p00_L_219B();
  p00_L_14C7();
  cpu_push_af();
  p00_L_2315();
  p26_L_55A0();
  p00_L_219B();
  p00_L_14C7();
  p26_L_5A79();
  p00_L_21A4();
  p26_L_57E3();
  return;
}

/* flash page 26 cpu 0x4F82 (offset 0x0F82) */
void p26_L_4F82(void) {
  p00_L_3A05();
  p26_L_50AE();
  p26_L_4F88();
  return;
}

/* flash page 26 cpu 0x4F88 (offset 0x0F88) */
void p26_L_4F88(void) {
  p00_L_0C18();
  p26_L_447A();
  p00_L_1169();
  p00_L_15D6();
  p00_L_14C7();
  if (flag_z()) return;
  p00_L_163B();
  if (flag_c()) goto lab_p26_L_4FA2;
  p00_L_0FDE();
  goto lab_p26_L_4FDC;
  lab_p26_L_4FA2: ;
  p00_rst08();
  p00_L_128A();
  set_hl(0x707F);
  mem_write16(0x8479, hl());
  p00_L_107E();
  if (flag_c()) goto lab_p26_L_4FE7;
  p00_L_1130();
  p00_L_0D1E();
  set_hl(0x4DB0);
  a = 0x03;
  p26_L_5017();
  a = 0x03;
  p26_L_5029();
  p00_L_1128();
  p00_L_0D1F();
  p00_L_1108();
  p00_L_0ED0();
  p00_L_21A7();
  return;
  lab_p26_L_4FD3: ;
  p00_L_1108();
  p00_L_0ED0();
  p00_L_21A7();
  lab_p26_L_4FDC: ;
  a = mem_read8(0x84AF);
  set_hl(0x8478);
  /* xor (hl) */
  mem_write8(0x8478, a);
  return;
  lab_p26_L_4FE7: ;
  a = 0x98;
  mem_write8(0x847A, a);
  p00_L_107E();
  cpu_push_af();
  p00_L_1179();
  p26_L_447A();
  p00_L_0D16();
  p00_L_3921();
  p00_L_0E4C();
  p00_L_3A05();
  cpu_pop_af();
  set_hl(0x4E1C);
  if (flag_c()) goto lab_p26_L_500B;
  set_hl(0x4DE6);
  lab_p26_L_500B: ;
  a = 0x02;
  p26_L_5017();
  a = 0x04;
  p26_L_5029();
  goto lab_p26_L_4FD3;
}

/* flash page 26 cpu 0x5017 (offset 0x1017) */
void p26_L_5017(void) {
  cpu_push_hl();
  p00_rst18();
  cpu_pop_hl();
  p26_L_5029();
  cpu_push_hl();
  p00_L_0D1F();
  p00_L_0C1B();
  p00_L_1171();
  cpu_pop_hl();
  return;
}

/* flash page 26 cpu 0x5029 (offset 0x1029) */
void p26_L_5029(void) {
  cpu_push_af();
  cpu_push_hl();
  p00_L_1287();
  lab_p26_L_502E: ;
  cpu_pop_hl();
  p00_rst20();
  cpu_push_hl();
  p00_rst30();
  p00_L_22F7();
  cpu_pop_hl();
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  if (flag_z()) return;
  cpu_push_af();
  cpu_push_hl();
  p00_L_0D1F();
  p00_rst08();
  goto lab_p26_L_502E;
}

/* flash page 26 cpu 0x50A8 (offset 0x10A8) */
void p26_L_50A8(void) {
  p26_L_50B8();
  p26_L_50AB();
  return;
}

/* flash page 26 cpu 0x50AB (offset 0x10AB) */
void p26_L_50AB(void) {
  p00_L_0ED0();
  p26_L_50AE();
  return;
}

/* flash page 26 cpu 0x50AE (offset 0x10AE) */
void p26_L_50AE(void) {
  p00_rst18();
  p26_L_50AF();
  return;
}

/* flash page 26 cpu 0x50AF (offset 0x10AF) */
void p26_L_50AF(void) {
  p00_L_2315();
  p26_L_447A();
  p00_L_0D16();
  return;
}

/* flash page 26 cpu 0x50B8 (offset 0x10B8) */
void p26_L_50B8(void) {
  set_hl(0x8A5E);
  a = mem_read8(hl());
  a = a & 0x1F;
  flag_logic(a);
  flag_cmp(a, 0x0E);
  if (flag_z()) { p00_L_2515(); return; }
  return;
}

/* flash page 26 cpu 0x50C4 (offset 0x10C4) */
void p26_L_50C4(void) {
  set_hl(0x8A43);
  p26_L_50C7();
  return;
}

/* flash page 26 cpu 0x50C7 (offset 0x10C7) */
void p26_L_50C7(void) {
  set_de(0x84A4);
  p00_L_1183();
  p26_L_50CD();
  return;
}

/* flash page 26 cpu 0x50CD (offset 0x10CD) */
void p26_L_50CD(void) {
  p00_L_2196();
  p00_L_0D1F();
  p00_L_10DD();
  p00_L_1108();
  p00_rst30();
  a = 0x33;
  p00_L_1897();
  p00_L_113A();
  p00_L_10EF();
  p00_L_0C2D();
  a = 0x32;
  p00_L_1897();
  return;
}

/* flash page 26 cpu 0x50EE (offset 0x10EE) */
void p26_L_50EE(void) {
  p00_L_222C();
  p26_L_4F88();
  b = 0x08;
  lab_p26_L_50F6: ;
  cpu_push_bc();
  p00_rst18();
  p00_L_2310();
  p26_L_4766();
  p00_rst18();
  p00_L_2315();
  p00_L_231F();
  p26_L_47D2();
  p00_L_22C7();
  p00_L_0C2D();
  p00_L_2196();
  p00_L_0ED0();
  p00_L_2196();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x78);
  if (flag_c()) goto lab_p26_L_5124;
  p00_rst30();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p26_L_50F6;
  goto lab_p26_L_5128;
  lab_p26_L_5124: ;
  cpu_pop_bc();
  p00_L_1179();
  lab_p26_L_5128: ;
  p00_L_21A4();
  return;
}

/* flash page 26 cpu 0x5186 (offset 0x1186) */
void p26_L_5186(void) {
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 6)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 7)));
  mem_write8(0x8A36, a);
  return;
}

/* flash page 26 cpu 0x5195 (offset 0x1195) */
void p26_L_5195(void) {
  goto lab_p26_L_5195;
  lab_p26_L_5192: ;
  p00_L_24E5();
  return;
  lab_p26_L_5195: ;
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p26_L_5192;
  flag_cmp(a, 0x01);
  if (flag_c()) goto lab_p26_L_5192;
  if (flag_z()) goto lab_p26_L_51BC;
  flag_cmp(a, 0x03);
  if (flag_c()) goto lab_p26_L_51C2;
  if (flag_nz()) goto lab_p26_L_51B2;
  p00_L_1037();
  if (flag_nz()) goto lab_p26_L_51C8;
  a = 0xFF;
  mem_write8(0x8483, a);
  p00_L_21E0();
  return;
  lab_p26_L_51B2: ;
  p00_L_22F7();
  p00_L_18A8();
  if (flag_z()) { p00_L_24DD(); return; }
  return;
  lab_p26_L_51BC: ;
  p00_rst18();
  a = 0x00;
  p00_L_1682();
  lab_p26_L_51C2: ;
  p00_rst18();
  a = 0xFF;
  mem_write8(0x8478, a);
  lab_p26_L_51C8: ;
  p26_L_5CF2();
  return;
}

/* flash page 26 cpu 0x524C (offset 0x124C) */
void p26_L_524C(void) {
  a = 0x15;
  p26_L_5186();
  return;
}

/* flash page 26 cpu 0x5251 (offset 0x1251) */
void p26_L_5251(void) {
  p00_L_1653();
  p00_L_1873();
  a = mem_read8(0x8479);
  flag_cmp(a, 0x82);
  if (flag_nc()) { p00_L_24C9(); return; }
  flag_cmp(a, 0x80);
  if (flag_c()) goto lab_p26_L_5268;
  a = (uint8_t)(a - 0x02);
  mem_write8(0x8479, a);
  lab_p26_L_5268: ;
  p00_rst18();
  return;
}

/* flash page 26 cpu 0x526A (offset 0x126A) */
void p26_L_526A(void) {
  p26_L_5439();
  p26_L_50B8();
  p26_L_5270();
  return;
}

/* flash page 26 cpu 0x5270 (offset 0x1270) */
void p26_L_5270(void) {
  p00_rst08();
  p00_L_22CF();
  p00_L_1884();
  p26_L_50AB();
  p26_L_4F88();
  p26_L_50C4();
  p26_L_452C();
  return;
}

/* flash page 26 cpu 0x5283 (offset 0x1283) */
void p26_L_5283(void) {
  p26_L_5439();
  p26_L_5286();
  return;
}

/* flash page 26 cpu 0x5286 (offset 0x1286) */
void p26_L_5286(void) {
  p00_rst08();
  set_hl(0x8A5E);
  p00_rst20();
  p26_L_50A8();
  p00_L_10DD();
  set_hl(0x8A3A);
  p00_rst20();
  p00_L_0C2A();
  p00_rst08();
  p00_L_1135();
  p26_L_50EE();
  p26_L_50C4();
  p26_L_4C7F();
  return;
}

/* flash page 26 cpu 0x52A5 (offset 0x12A5) */
void p26_L_52A5(void) {
  goto lab_p26_L_52A5;
  lab_p26_L_52A2: ;
  p26_L_4C7F();
  return;
  lab_p26_L_52A5: ;
  b = 0x28;
  a = 0x02;
  p26_L_5671();
  p26_L_55F8();
  p00_L_2310();
  p00_L_0ED0();
  p26_L_4F82();
  set_hl(0x8B90);
  p26_L_50C7();
  goto lab_p26_L_52A2;
}

/* flash page 26 cpu 0x52C0 (offset 0x12C0) */
void p26_L_52C0(void) {
  p26_L_5605();
  p26_L_55F8();
  p00_L_22C7();
  p00_L_0ED0();
  p00_L_10DD();
  set_hl(0x8BA2);
  p00_rst20();
  p26_L_55F8();
  p00_L_2310();
  p00_L_0ED0();
  p00_L_10EF();
  p00_rst30();
  p26_L_4F82();
  p00_L_1171();
  set_hl(0x8B99);
  p00_rst20();
  set_hl(0x8BA2);
  p00_L_0C25();
  p00_L_1486();
  p26_L_50CD();
  p26_L_5377();
  return;
}

/* flash page 26 cpu 0x52F9 (offset 0x12F9) */
void p26_L_52F9(void) {
  p00_L_14C7();
  cpu_push_af();
  p26_L_5725();
  cpu_pop_af();
  p26_L_5301();
  return;
}

/* flash page 26 cpu 0x5301 (offset 0x1301) */
void p26_L_5301(void) {
  if (flag_nz()) goto lab_p26_L_5335;
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 7)));
  set_hl(0x8BB4);
  p00_rst20();
  set_hl(0x8BCF);
  p00_L_11F8();
  p26_L_5760();
  p00_L_21D6();
  p26_L_59ED();
  lab_p26_L_531A: ;
  p00_L_10DD();
  p26_L_50AF();
  p00_L_10EF();
  p26_L_50EE();
  p26_L_5326();
  return;
  lab_p26_L_5335: ;
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 7)));
  p26_L_5A18();
  p00_rst18();
  p00_L_113A();
  goto lab_p26_L_531A;
}

/* flash page 26 cpu 0x5326 (offset 0x1326) */
void p26_L_5326(void) {
  p00_L_1171();
  p26_L_578E();
  p00_L_1486();
  p26_L_50CD();
  p26_L_5377();
  return;
}

/* flash page 26 cpu 0x5342 (offset 0x1342) */
void p26_L_5342(void) {
  /* scf */
  p26_L_56E7();
  p26_L_5346();
  return;
}

/* flash page 26 cpu 0x5346 (offset 0x1346) */
void p26_L_5346(void) {
  p00_L_21E0();
  p26_L_50AF();
  p26_L_4F88();
  p26_L_5326();
  p00_L_21A7();
  return;
}

/* flash page 26 cpu 0x5355 (offset 0x1355) */
void p26_L_5355(void) {
  p26_L_5438();
  p26_L_50B8();
  p26_L_535B();
  return;
}

/* flash page 26 cpu 0x535B (offset 0x135B) */
void p26_L_535B(void) {
  p00_rst08();
  p00_L_22CF();
  p00_L_1884();
  p00_L_0ED0();
  p00_L_22B3();
  set_de(0x8D8F);
  set_hl(0x8483);
  p00_L_1183();
  p26_L_5446();
  p26_L_537D();
  p26_L_5377();
  return;
}

/* flash page 26 cpu 0x5377 (offset 0x1377) */
void p26_L_5377(void) {
  set_bc(0x002D);
  p00_L_21AA();
  return;
}

/* flash page 26 cpu 0x537D (offset 0x137D) */
void p26_L_537D(void) {
  a = 0x23;
  p00_L_1897();
  p00_L_22F7();
  p00_L_14CC();
  cpu_push_af();
  if (flag_z()) p00_L_15D6();
  p26_L_5503();
  cpu_pop_af();
  p26_L_5390();
  return;
}

/* flash page 26 cpu 0x5390 (offset 0x1390) */
void p26_L_5390(void) {
  if (flag_z()) p00_L_0C18();
  p00_L_22F7();
  p26_L_5396();
  return;
}

/* flash page 26 cpu 0x5396 (offset 0x1396) */
void p26_L_5396(void) {
  p00_L_15C6();
  if (flag_nz()) p26_L_447A();
  p26_L_539C();
  return;
}

/* flash page 26 cpu 0x539C (offset 0x139C) */
void p26_L_539C(void) {
  a = 0x22;
  p00_L_1897();
  return;
}

/* flash page 26 cpu 0x5438 (offset 0x1438) */
void p26_L_5438(void) {
  p00_rst18();
  p26_L_5439();
  return;
}

/* flash page 26 cpu 0x5439 (offset 0x1439) */
void p26_L_5439(void) {
  p00_L_2324();
  p26_L_570B();
  p26_L_543F();
  return;
}

/* flash page 26 cpu 0x543F (offset 0x143F) */
void p26_L_543F(void) {
  p26_L_6EA4();
  p00_L_3A05();
  return;
}

/* flash page 26 cpu 0x5446 (offset 0x1446) */
void p26_L_5446(void) {
  p00_L_1100();
  set_hl(0x8A43);
  p00_rst20();
  p00_L_0C2D();
  p26_L_5450();
  return;
}

/* flash page 26 cpu 0x5450 (offset 0x1450) */
void p26_L_5450(void) {
  p00_L_10F8();
  p00_L_0ED0();
  return;
}

/* flash page 26 cpu 0x5495 (offset 0x1495) */
void p26_L_5495(void) {
  cpu_push_af();
  p26_L_5186();
  cpu_pop_af();
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 7)));
  p00_rst18();
  a = 0x24;
  p26_L_5D4E();
  p00_L_21A7();
  p00_L_333F();
  set_hl(0x8B6C);
  a = 0x74;
  p26_L_54B0();
  return;
}

/* flash page 26 cpu 0x54B0 (offset 0x14B0) */
void p26_L_54B0(void) {
  p00_L_32D9();
  return;
}

/* flash page 26 cpu 0x54B4 (offset 0x14B4) */
void p26_L_54B4(void) {
  p26_L_5438();
  p26_L_50B8();
  p26_L_54BA();
  return;
}

/* flash page 26 cpu 0x54BA (offset 0x14BA) */
void p26_L_54BA(void) {
  p00_rst08();
  set_hl(0x8A5E);
  p00_rst20();
  p00_L_0ED0();
  p00_L_22C7();
  set_de(0x8D8F);
  set_hl(0x8483);
  p00_L_1183();
  p26_L_5446();
  a = 0x24;
  p00_L_1897();
  p00_rst18();
  p26_L_6EA4();
  p00_L_0C2A();
  p00_rst08();
  p26_L_54DE();
  return;
}

/* flash page 26 cpu 0x54DE (offset 0x14DE) */
void p26_L_54DE(void) {
  p00_L_2315();
  p00_L_14C7();
  cpu_push_af();
  p00_L_219B();
  cpu_pop_af();
  cpu_push_af();
  if (flag_z()) p00_L_15D6();
  p26_L_47D2();
  cpu_pop_af();
  p26_L_5390();
  p26_L_452C();
  return;
}

/* flash page 26 cpu 0x54F7 (offset 0x14F7) */
void p26_L_54F7(void) {
  p00_L_231F();
  p00_L_0C2D();
  p00_L_2310();
  p00_L_0ED0();
  p26_L_5503();
  return;
}

/* flash page 26 cpu 0x5503 (offset 0x1503) */
void p26_L_5503(void) {
  p00_rst18();
  p00_L_15D6();
  p00_rst08();
  set_hl(0x5549);
  p00_rst20();
  cpu_push_hl();
  p00_L_0D1F();
  p00_L_0C1B();
  p00_L_0ECC();
  p00_rst18();
  cpu_pop_hl();
  p00_rst20();
  b = 0x05;
  cpu_push_bc();
  lab_p26_L_551C: ;
  cpu_push_hl();
  p00_L_22F7();
  p00_L_0D1F();
  cpu_pop_hl();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p26_L_5540;
  p00_L_233D();
  p00_L_2315();
  p26_L_443B();
  p00_L_2196();
  p00_L_0D1F();
  p00_L_2196();
  p00_L_15C6();
  if (flag_nz()) p26_L_447A();
  return;
  lab_p26_L_5540: ;
  cpu_push_bc();
  p00_L_11F8();
  cpu_push_hl();
  p00_rst30();
  cpu_pop_hl();
  goto lab_p26_L_551C;
}

/* flash page 26 cpu 0x557F (offset 0x157F) */
void p26_L_557F(void) {
  flag_cmp(a, 0x03);
  if (flag_c()) { p00_L_24E5(); return; }
  if (flag_z()) goto lab_p26_L_558F;
  flag_cmp(a, 0x05);
  if (flag_z()) goto lab_p26_L_5597;
  if (flag_nc()) { p00_L_24E5(); return; }
  goto lab_p26_L_5593;
  lab_p26_L_558F: ;
  p00_rst18();
  p00_L_128A();
  lab_p26_L_5593: ;
  p00_rst18();
  p00_L_128A();
  lab_p26_L_5597: ;
  p00_L_1653();
  p00_L_14C7();
  return;
}

/* flash page 26 cpu 0x559D (offset 0x159D) */
void p26_L_559D(void) {
  p00_L_22FC();
  p26_L_55A0();
  return;
}

/* flash page 26 cpu 0x55A0 (offset 0x15A0) */
void p26_L_55A0(void) {
  b = 0x00;
  p00_L_14C7();
  if (flag_z()) goto lab_p26_L_55AE;
  b = (uint8_t)(b + 1);
  p00_L_15CB();
  if (flag_z()) goto lab_p26_L_55AE;
  b = (uint8_t)(b + 1);
  lab_p26_L_55AE: ;
  a = b;
  mem_write8(0x8A37, a);
  return;
}

/* flash page 26 cpu 0x55DE (offset 0x15DE) */
void p26_L_55DE(void) {
  cpu_push_af();
  p26_L_5186();
  cpu_pop_af();
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 7)));
  a = 0x23;
  p26_L_5D4E();
  p00_L_333F();
  set_hl(0x8B63);
  a = 0x7A;
  p26_L_54B0();
  return;
}

/* flash page 26 cpu 0x55F8 (offset 0x15F8) */
void p26_L_55F8(void) {
  p00_L_1100();
  p26_L_447A();
  p00_L_10F8();
  p00_L_0D1F();
  return;
}

/* flash page 26 cpu 0x5605 (offset 0x1605) */
void p26_L_5605(void) {
  b = 0x2A;
  a = 0x30;
  p26_L_5671();
  p00_L_22CF();
  a = 0x2D;
  p00_L_1897();
  p26_L_4A87();
  p00_rst08();
  p00_L_22D9();
  a = 0x29;
  p26_L_5682();
  return;
}

/* flash page 26 cpu 0x5620 (offset 0x1620) */
void p26_L_5620(void) {
  p26_L_5605();
  p00_L_2315();
  p00_L_22C7();
  p00_rst30();
  p00_L_10DD();
  p00_L_2324();
  p00_L_22B3();
  p00_rst30();
  p26_L_5788();
  a = 0x28;
  p00_L_1897();
  p26_L_55F8();
  p00_L_10DD();
  p00_L_2315();
  p00_L_0ECC();
  p00_L_1171();
  p00_L_22CF();
  p00_L_0ECC();
  p00_L_1108();
  p00_rst30();
  p26_L_4972();
  p00_L_3A05();
  p00_L_10DD();
  set_hl(0x8B99);
  p00_rst20();
  set_hl(0x8BA2);
  p00_L_0C25();
  p26_L_5788();
  p26_L_537D();
  p26_L_5377();
  return;
}

/* flash page 26 cpu 0x5671 (offset 0x1671) */
void p26_L_5671(void) {
  cpu_push_bc();
  cpu_push_af();
  p00_L_2315();
  cpu_pop_af();
  p00_L_1897();
  p26_L_4A87();
  p00_rst08();
  p00_L_2324();
  cpu_pop_af();
  p26_L_5682();
  return;
}

/* flash page 26 cpu 0x5682 (offset 0x1682) */
void p26_L_5682(void) {
  cpu_push_af();
  p00_L_187F();
  p00_L_107E();
  if (flag_c()) goto lab_p26_L_568E;
  if (flag_nz()) { p00_L_24C9(); return; }
  lab_p26_L_568E: ;
  p00_L_0ED0();
  cpu_pop_af();
  p00_L_1897();
  return;
}

/* flash page 26 cpu 0x56A9 (offset 0x16A9) */
void p26_L_56A9(void) {
  p00_L_22CF();
  p00_L_1873();
  p00_L_163B();
  if (flag_nc()) { p00_L_24C9(); return; }
  b = 0x28;
  a = 0x02;
  p26_L_5671();
  p00_L_22C7();
  set_de(0x8D8F);
  set_hl(0x8483);
  p00_L_1183();
  p00_L_0C2D();
  p00_L_10DD();
  p00_L_22CF();
  p26_L_55F8();
  p00_L_2310();
  p00_L_0ED0();
  p00_L_3A05();
  p26_L_4413();
  p26_L_537D();
  p26_L_452C();
  return;
}

/* flash page 26 cpu 0x56E6 (offset 0x16E6) */
void p26_L_56E6(void) {
  a = 0;
  flag_logic(a);
  p26_L_56E7();
  return;
}

/* flash page 26 cpu 0x56E7 (offset 0x16E7) */
void p26_L_56E7(void) {
  cpu_push_af();
  p00_rst18();
  p26_L_5725();
  cpu_pop_af();
  p26_L_56ED();
  return;
}

/* flash page 26 cpu 0x56ED (offset 0x16ED) */
void p26_L_56ED(void) {
  cpu_push_af();
  p00_L_2267();
  p00_L_1884();
  p00_L_2277();
  p00_L_1884();
  p00_L_2262();
  p26_L_5760();
  cpu_pop_af();
  if (flag_c()) return;
  p26_L_537D();
  p00_L_21A7();
  p26_L_4D4D();
  return;
}

/* flash page 26 cpu 0x570B (offset 0x170B) */
void p26_L_570B(void) {
  p00_L_2310();
  p26_L_570E();
  return;
}

/* flash page 26 cpu 0x570E (offset 0x170E) */
void p26_L_570E(void) {
  a = mem_read8(0x8483);
  flag_cmp(a, 0xFF);
  a = 0x01;
  if (flag_z()) goto lab_p26_L_571D;
  p00_rst18();
  p00_L_1179();
  a = 0x02;
  lab_p26_L_571D: ;
  p26_L_637E();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 5)));
  return;
}

/* flash page 26 cpu 0x5725 (offset 0x1725) */
void p26_L_5725(void) {
  p00_L_22CF();
  p26_L_570B();
  set_de(0x8BC6);
  p26_L_5748();
  set_hl(0x8D2A);
  set_de(0x8D39);
  set_bc(0x000F);
  while (bc() != 0) { cpu_ldi(); }
  p00_L_22D9();
  p00_L_231F();
  p26_L_570E();
  set_de(0x8BAB);
  p26_L_5748();
  return;
}

/* flash page 26 cpu 0x5748 (offset 0x1748) */
void p26_L_5748(void) {
  a = 0x0E;
  set_hl(0x8A43);
  p26_L_5759();
  set_hl(0x8A5E);
  p26_L_5759();
  set_hl(0x8A3A);
  p26_L_5759();
  return;
}

/* flash page 26 cpu 0x5759 (offset 0x1759) */
void p26_L_5759(void) {
  cpu_push_hl();
  p00_L_1183();
  cpu_pop_hl();
  mem_write8(hl(), a);
  return;
}

/* flash page 26 cpu 0x5760 (offset 0x1760) */
void p26_L_5760(void) {
  p00_L_10E6();
  p00_L_0D1E();
  set_hl(0x8BBD);
  p00_L_0EC1();
  p00_L_14A2();
  p00_L_0D1E();
  set_hl(0x8BD8);
  p00_L_0EC1();
  p00_L_10EF();
  p00_rst30();
  p00_L_1171();
  p00_L_3A05();
  p26_L_5782();
  return;
}

/* flash page 26 cpu 0x5782 (offset 0x1782) */
void p26_L_5782(void) {
  p00_L_10DD();
  p26_L_578E();
  p26_L_5788();
  return;
}

/* flash page 26 cpu 0x5788 (offset 0x1788) */
void p26_L_5788(void) {
  p00_L_10EF();
  p00_L_0ED0();
  return;
}

/* flash page 26 cpu 0x578E (offset 0x178E) */
void p26_L_578E(void) {
  set_hl(0x8BAB);
  p00_rst20();
  set_hl(0x8BC6);
  p00_L_0C25();
  return;
}

/* flash page 26 cpu 0x5798 (offset 0x1798) */
void p26_L_5798(void) {
  cpu_push_de();
  p00_rst20();
  p00_L_0D1E();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_0EC1();
  p00_L_0D1E();
  p00_L_10DD();
  cpu_pop_hl();
  p00_rst20();
  p00_L_0C2A();
  p26_L_4413();
  return;
}

/* flash page 26 cpu 0x57B0 (offset 0x17B0) */
void p26_L_57B0(void) {
  cpu_push_de();
  p00_rst20();
  p00_L_0D1E();
  p00_rst18();
  cpu_pop_hl();
  p00_rst20();
  p00_L_0C2A();
  p00_L_2196();
  p00_L_0D1F();
  p00_L_1128();
  p00_L_1169();
  return;
}

/* flash page 26 cpu 0x57E3 (offset 0x17E3) */
void p26_L_57E3(void) {
  set_hl(0x8B87);
  p00_rst20();
  cpu_pop_af();
  a = 0x0E;
  p26_L_5495();
  return;
}

/* flash page 26 cpu 0x589C (offset 0x189C) */
void p26_L_589C(void) {
  a = 0x0D;
  p00_L_3675();
  p00_L_15E0();
  p00_L_0E4C();
  a = 0x0C;
  p00_L_3675();
  return;
}

/* flash page 26 cpu 0x58F2 (offset 0x18F2) */
void p26_L_58F2(void) {
  c = a;
  a = b;
  cpu_push_af();
  a = c;
  flag_cmp(a, 0x01);
  if (flag_z()) { p00_L_24E5(); return; }
  if (flag_c()) goto lab_p26_L_59BC;
  flag_cmp(a, 0x03);
  if (flag_c()) goto lab_p26_L_59C7;
  if (flag_nz()) goto lab_p26_L_5919;
  p00_L_1037();
  if (flag_nz()) goto lab_p26_L_59CD;
  a = 0xFF;
  mem_write8(0x8483, a);
  p00_L_21E0();
  p00_L_21E0();
  p26_L_59DC();
  return;
  lab_p26_L_5919: ;
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p26_L_594C;
  a = 0xFF;
  mem_write8(0x848E, a);
  p00_L_22F7();
  p00_L_18A8();
  if (flag_nz()) goto lab_p26_L_5940;
  p00_L_232E();
  p00_L_21DB();
  p00_L_21E0();
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p26_L_593D;
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) { p00_L_24DD(); return; }
  lab_p26_L_593D: ;
  p26_L_59E0();
  return;
  lab_p26_L_5940: ;
  p00_L_1037();
  if (flag_nz()) goto lab_p26_L_59D3;
  p00_L_21DB();
  p26_L_59DC();
  return;
  lab_p26_L_594C: ;
  if (flag_nz()) goto lab_p26_L_5987;
  a = 0xFF;
  mem_write8(0x848E, a);
  p00_L_2310();
  p00_L_18A8();
  if (flag_nz()) goto lab_p26_L_5977;
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p00_L_24DD(); return; }
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) { p00_L_24DD(); return; }
  p00_L_234D();
  p00_L_21E0();
  p00_L_2310();
  p00_L_234D();
  p00_L_21E0();
  goto lab_p26_L_59E8;
  lab_p26_L_5977: ;
  p00_L_22F7();
  p00_L_18A8();
  if (flag_nz()) { p26_L_59DC(); return; }
  p00_L_232E();
  p00_L_21E0();
  p26_L_59E0();
  return;
  lab_p26_L_5987: ;
  flag_cmp(a, 0x06);
  if (flag_nz()) goto lab_p26_L_59AF;
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) { p26_L_59E0(); return; }
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) { p26_L_59E0(); return; }
  p00_L_2310();
  p00_L_18A8();
  if (flag_nz()) { p26_L_59E0(); return; }
  a = 0xFF;
  mem_write8(0x848E, a);
  p00_L_234D();
  p00_L_22F2();
  p00_L_2333();
  p00_L_21DB();
  goto lab_p26_L_59E8;
  lab_p26_L_59AF: ;
  flag_cmp(a, 0x07);
  if (flag_nz()) goto lab_p26_L_59B7;
  cpu_pop_af();
  cpu_push_af();
  if (flag_c()) goto lab_p26_L_59E8;
  lab_p26_L_59B7: ;
  if (flag_nc()) { p00_L_24E5(); return; }
  p26_L_59E0();
  return;
  lab_p26_L_59BC: ;
  p00_rst18();
  a = 0x00;
  p00_L_1682();
  p00_rst18();
  set_hl(0x847A);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  lab_p26_L_59C7: ;
  p00_rst18();
  a = 0xFF;
  mem_write8(0x8478, a);
  lab_p26_L_59CD: ;
  p00_rst18();
  a = 0xFF;
  mem_write8(0x8478, a);
  lab_p26_L_59D3: ;
  p26_L_5CF2();
  cpu_pop_af();
  cpu_push_af();
  a = a | a;
  flag_logic(a);
  if (flag_z()) p00_L_128A();
  p26_L_59DC();
  return;
  lab_p26_L_59E8: ;
  p00_L_1653();
  cpu_pop_af();
  return;
}

/* flash page 26 cpu 0x59DC (offset 0x19DC) */
void p26_L_59DC(void) {
  p00_rst18();
  p00_L_128A();
  p26_L_59E0();
  return;
}

/* flash page 26 cpu 0x59E0 (offset 0x19E0) */
void p26_L_59E0(void) {
  cpu_pop_af();
  cpu_push_af();
  if (flag_nc()) goto lab_p26_L_59E8;
  p00_rst18();
  p00_L_128A();
  lab_p26_L_59E8: ;
  p00_L_1653();
  cpu_pop_af();
  return;
}

/* flash page 26 cpu 0x59ED (offset 0x19ED) */
void p26_L_59ED(void) {
  set_hl(0x8BB4);
  set_de(0x8BBD);
  p26_L_5798();
  p00_L_1169();
  set_hl(0x8BCF);
  set_de(0x8BD8);
  p26_L_5798();
  p00_L_1128();
  p00_rst30();
  p00_L_10DD();
  p00_L_113A();
  p00_L_0D1E();
  p26_L_5788();
  a = 0x27;
  p00_L_1897();
  return;
}

/* flash page 26 cpu 0x5A18 (offset 0x1A18) */
void p26_L_5A18(void) {
  set_hl(0x8BBD);
  p00_rst20();
  set_hl(0x8BD8);
  p00_L_0C20();
  p00_L_1246();
  p00_L_0C2D();
  a = 0x27;
  p00_L_1897();
  p00_L_1171();
  set_hl(0x8BB4);
  set_de(0x8BBD);
  p26_L_57B0();
  set_hl(0x8BCF);
  set_de(0x8BD8);
  p26_L_57B0();
  p00_rst30();
  p00_L_1108();
  p00_L_0ED0();
  p00_L_3A05();
  a = 0x31;
  p00_L_1897();
  p00_rst18();
  set_hl(0x8BBD);
  p00_rst20();
  p00_L_0ECC();
  p00_L_1169();
  set_hl(0x8BD8);
  p00_rst20();
  p00_L_0ECC();
  p00_L_1128();
  p00_rst30();
  p00_L_3A05();
  p00_L_2196();
  p00_L_0D1F();
  return;
}

/* flash page 26 cpu 0x5A71 (offset 0x1A71) */
void p26_L_5A71(void) {
  p00_L_14C7();
  cpu_push_af();
  p26_L_5725();
  cpu_pop_af();
  p26_L_5A79();
  return;
}

/* flash page 26 cpu 0x5A79 (offset 0x1A79) */
void p26_L_5A79(void) {
  if (flag_nz()) goto lab_p26_L_5AA0;
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) | (1u << 7)));
  set_hl(0x8BB4);
  p00_rst20();
  set_hl(0x8BCF);
  p00_L_11F8();
  p26_L_5760();
  a = 0x24;
  p00_L_1897();
  p26_L_59ED();
  p00_rst08();
  set_hl(0x8B6C);
  p00_rst20();
  lab_p26_L_5A99: ;
  p00_rst18();
  p26_L_54DE();
  p00_L_21A7();
  return;
  lab_p26_L_5AA0: ;
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 7)));
  p26_L_5A18();
  p26_L_5782();
  a = 0x24;
  p00_L_1897();
  p00_L_1108();
  goto lab_p26_L_5A99;
}

/* flash page 26 cpu 0x5AB4 (offset 0x1AB4) */
void p26_L_5AB4(void) {
  lab_p26_L_5AB4: ;
  p26_L_4AF9();
  p00_L_22B3();
  p00_L_0FDE();
  p00_L_14CC();
  if (flag_z()) goto lab_p26_L_5AD0;
  p00_L_1229();
  p00_L_107E();
  if (flag_c()) { p00_L_24C9(); return; }
  if (flag_nz()) goto lab_p26_L_5AD3;
  p00_L_128A();
  lab_p26_L_5AD0: ;
  p26_L_5377();
  return;
  lab_p26_L_5AD3: ;
  set_hl(0x0FC3);
  p00_rst20();
  p00_L_107E();
  if (flag_nc()) goto lab_p26_L_5AF7;
  p00_L_21A4();
  p00_L_2324();
  p26_L_447A();
  p00_L_2196();
  p00_L_235C();
  p00_L_22FC();
  p00_L_2333();
  p26_L_5AB4();
  p00_L_0ECC();
  return;
  lab_p26_L_5AF7: ;
  p00_L_2315();
  p26_L_42DB();
  p00_rst18();
  p00_L_2315();
  p26_L_42DB();
  p00_L_2196();
  p00_rst30();
  p00_rst18();
  p00_L_2315();
  p00_L_231F();
  p00_rst30();
  p26_L_42DB();
  p00_L_2196();
  p00_L_0C13();
  p00_rst18();
  p00_L_2267();
  p00_L_38A3();
  p00_L_22F7();
  p00_rst30();
  p00_rst18();
  p00_L_2277();
  p26_L_447A();
  p00_L_38A3();
  p00_L_2310();
  p00_rst30();
  p00_L_235C();
  p00_L_2324();
  p00_L_22C7();
  p00_rst30();
  p00_L_1246();
  p00_rst30();
  p00_L_1100();
  p00_L_22CF();
  p00_L_0C1B();
  p00_L_10F8();
  p00_L_0ED0();
  p00_L_23A4();
  p00_L_1229();
  a = 0x10;
  lab_p26_L_5B57: ;
  cpu_push_af();
  p00_L_23B3();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_22C7();
  p00_rst30();
  p00_rst08();
  p00_L_22CF();
  p00_L_0ED0();
  p00_rst18();
  p00_L_38A3();
  p00_L_22B3();
  p00_L_0D1F();
  p00_rst18();
  p00_L_2315();
  p26_L_447A();
  p00_L_38A3();
  p00_L_22B3();
  p00_L_0D1F();
  p00_L_2196();
  p00_rst30();
  p00_L_1100();
  p00_L_2272();
  p00_L_22FC();
  p00_L_107E();
  if (flag_nc()) goto lab_p26_L_5BC4;
  p00_L_10F8();
  p00_L_2315();
  p00_L_0C2D();
  p00_L_392D();
  p00_L_2196();
  p00_rst18();
  p00_L_22D9();
  p00_rst18();
  p00_L_22D9();
  p00_rst18();
  p00_L_21E0();
  p26_L_4CA3();
  p00_L_22B3();
  p00_L_0ED0();
  p00_L_2196();
  p00_L_0C2D();
  goto lab_p26_L_5BF2;
  lab_p26_L_5BC4: ;
  p00_L_10F8();
  p00_L_2324();
  p00_L_0C2D();
  p00_L_392D();
  p00_L_2196();
  p00_rst18();
  p00_L_22CF();
  p00_rst18();
  p00_L_2267();
  p00_rst18();
  p00_L_1229();
  p00_L_0C2D();
  p00_rst18();
  p26_L_4CA3();
  p00_L_22C7();
  p00_L_0ED0();
  p00_L_2196();
  p00_L_0C13();
  lab_p26_L_5BF2: ;
  a = mem_read8(0x8479);
  cpu_push_af();
  p00_L_22B3();
  p00_L_0D1F();
  p00_rst30();
  cpu_pop_af();
  flag_cmp(a, 0x7C);
  if (flag_c()) goto lab_p26_L_5C09;
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p26_L_5B57;
  goto lab_p26_L_5C0A;
  lab_p26_L_5C09: ;
  cpu_pop_af();
  lab_p26_L_5C0A: ;
  p00_L_21A4();
  p26_L_5377();
  return;
}

/* flash page 26 cpu 0x5C10 (offset 0x1C10) */
void p26_L_5C10(void) {
  p00_rst18();
  p26_L_5725();
  p26_L_5C14();
  return;
}

/* flash page 26 cpu 0x5C14 (offset 0x1C14) */
void p26_L_5C14(void) {
  p00_L_219B();
  p26_L_55A0();
  p00_L_1287();
  p00_L_107E();
  cpu_push_af();
  set_hl(0x8BB4);
  p00_rst20();
  set_hl(0x8BCF);
  p00_L_0EC1();
  p00_L_0D1E();
  a = 0x26;
  p00_L_1897();
  cpu_pop_af();
  if (flag_z()) goto lab_p26_L_5C42;
  p26_L_5C75();
  p26_L_4BC0();
  p26_L_452C();
  p26_L_539C();
  return;
  lab_p26_L_5C42: ;
  p26_L_5C75();
  p26_L_4BC0();
  set_hl(0x0FC3);
  p00_L_11F8();
  p00_L_107E();
  if (flag_c()) goto lab_p26_L_5C5B;
  if (flag_z()) goto lab_p26_L_5C5B;
  p26_L_447A();
  p00_rst18();
  goto lab_p26_L_5C5F;
  lab_p26_L_5C5B: ;
  p00_rst18();
  p26_L_447A();
  lab_p26_L_5C5F: ;
  a = 0;
  flag_logic(a);
  p26_L_5C75();
  p26_L_5AB4();
  p00_L_10DD();
  p00_L_219B();
  p00_L_0C18();
  p26_L_539C();
  p26_L_452C();
  return;
}

/* flash page 26 cpu 0x5C75 (offset 0x1C75) */
void p26_L_5C75(void) {
  cpu_push_af();
  if (flag_c()) p00_L_0ECC();
  p00_rst18();
  set_hl(0x8BD8);
  p00_rst20();
  p00_L_0C2A();
  p00_L_1100();
  set_hl(0x8BBD);
  p00_rst20();
  p00_L_0C2A();
  cpu_pop_af();
  if (flag_nc()) p00_L_149D();
  p00_L_21DB();
  return;
}

/* flash page 26 cpu 0x5C92 (offset 0x1C92) */
void p26_L_5C92(void) {
  cpu_push_af();
  p00_rst18();
  cpu_pop_af();
  flag_cmp(a, 0x02);
  if (flag_c()) { p00_L_24E5(); return; }
  if (flag_z()) goto lab_p26_L_5CC4;
  flag_cmp(a, 0x04);
  if (flag_nz()) goto lab_p26_L_5CAF;
  p00_L_1037();
  if (flag_nz()) goto lab_p26_L_5CD0;
  a = 0xFF;
  mem_write8(0x8483, a);
  p00_L_2333();
  goto lab_p26_L_5CD3;
  lab_p26_L_5CAF: ;
  if (flag_c()) goto lab_p26_L_5CCA;
  p00_L_2310();
  p00_L_18A8();
  if (flag_nz()) goto lab_p26_L_5CD4;
  p00_L_2333();
  a = 0xFF;
  mem_write8(0x8483, a);
  p00_L_2357();
  return;
  lab_p26_L_5CC4: ;
  a = 0x00;
  p00_L_1682();
  p00_rst18();
  lab_p26_L_5CCA: ;
  a = 0xFF;
  mem_write8(0x8478, a);
  p00_rst18();
  lab_p26_L_5CD0: ;
  p00_L_128A();
  lab_p26_L_5CD3: ;
  p00_rst18();
  lab_p26_L_5CD4: ;
  p00_L_128A();
  return;
}

/* flash page 26 cpu 0x5CD7 (offset 0x1CD7) */
void p26_L_5CD7(void) {
  p00_L_1653();
  p00_L_14C7();
  cpu_push_af();
  p00_L_2176();
  p00_L_1653();
  p26_L_55A0();
  p00_L_231F();
  p00_L_18A8();
  if (flag_nz()) { p00_L_24DD(); return; }
  cpu_pop_af();
  return;
}

/* flash page 26 cpu 0x5CF2 (offset 0x1CF2) */
void p26_L_5CF2(void) {
  p00_rst18();
  set_hl(0x5CF8);
  p00_rst20();
  return;
}

/* flash page 26 cpu 0x5D01 (offset 0x1D01) */
void p26_L_5D01(void) {
  mem_write8((uint16_t)(iy + 0x11), (uint8_t)(mem_read8((uint16_t)(iy + 0x11)) & ~(1u << 7)));
  cpu_push_af();
  a = e;
  a = (uint8_t)(a - 0x22);
  e = a;
  d = 0x00;
  set_hl(0x5D29);
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  cpu_push_hl();
  p00_L_2222();
  p00_L_3E5B();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) | (1u << 2)));
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 5)));
  p00_L_2176();
  cpu_pop_hl();
  cpu_pop_af();
  os_jp_hl();
  return;
}

/* flash page 26 cpu 0x5D47 (offset 0x1D47) */
void p26_L_5D47(void) {
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  cpu_push_af();
  goto lab_p26_L_5D86;
  lab_p26_L_5D86: ;
  p00_L_0087();
  cpu_pop_af();
  cpu_push_af();
  p00_L_18A3();
  p00_rst18();
  p00_L_32A9();
  lab_p26_L_5D92: ;
  p00_L_0189();
  if (flag_nz()) { p00_L_2511(); return; }
  p00_L_38F1();
  cpu_pop_af();
  cpu_push_af();
  set_hl(0x5DFC);
  p00_L_25A2();
  p26_L_5E0E();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 5)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p26_L_5DBF;
  p00_L_233D();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  lab_p26_L_5DBF: ;
  p00_L_3387();
  p00_L_3303();
  p00_L_38F1();
  p00_L_231F();
  cpu_pop_bc();
  cpu_push_bc();
  p00_L_018E();
  if (flag_nz()) p26_L_5E26();
  p00_L_3393();
  a = mem_read8(0x8DA5);
  b = a;
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + 1);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p26_L_5DEC;
  mem_write8(0x8E67, a);
  set_hl(mem_read16(0x9196));
  p00_L_340B();
  goto lab_p26_L_5D92;
  lab_p26_L_5DEC: ;
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 3)));
  p26_L_4C7F();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  p00_L_34C5();
  return;
}

/* flash page 26 cpu 0x5D4E (offset 0x1D4E) */
void p26_L_5D4E(void) {
  set_hl(mem_read16(0x982A));
  cpu_push_hl();
  cpu_push_af();
  p00_L_3549();
  p00_L_1235();
  a = 0x32;
  mem_write8(0x847A, a);
  p00_L_33E1();
  p00_L_1229();
  a = 0x02;
  p00_L_3675();
  p00_L_15EB();
  a = 0x03;
  p00_L_3675();
  p00_L_0E4C();
  a = 0x0C;
  p00_L_3675();
  p00_L_15D6();
  a = 0x45;
  mem_write8(0x847A, a);
  a = 0x0D;
  p00_L_3675();
  p00_L_0087();
  cpu_pop_af();
  cpu_push_af();
  p00_L_18A3();
  p00_rst18();
  p00_L_32A9();
  lab_p26_L_5D92: ;
  p00_L_0189();
  if (flag_nz()) { p00_L_2511(); return; }
  p00_L_38F1();
  cpu_pop_af();
  cpu_push_af();
  set_hl(0x5DFC);
  p00_L_25A2();
  p26_L_5E0E();
  p00_L_25C8();
  mem_write8((uint16_t)(iy + 0x07), (uint8_t)(mem_read8((uint16_t)(iy + 0x07)) | (1u << 0)));
  set_hl(0x8478);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) & ~(1u << 5)));
  flag_set_z((mem_read8((uint16_t)(iy + 0x03)) & (1u << 5)) == 0);
  if (flag_z()) goto lab_p26_L_5DBF;
  p00_L_233D();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 5)));
  lab_p26_L_5DBF: ;
  p00_L_3387();
  p00_L_3303();
  p00_L_38F1();
  p00_L_231F();
  cpu_pop_bc();
  cpu_push_bc();
  p00_L_018E();
  if (flag_nz()) p26_L_5E26();
  p00_L_3393();
  a = mem_read8(0x8DA5);
  b = a;
  a = mem_read8(0x8E67);
  a = (uint8_t)(a + 1);
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p26_L_5DEC;
  mem_write8(0x8E67, a);
  set_hl(mem_read16(0x9196));
  p00_L_340B();
  goto lab_p26_L_5D92;
  lab_p26_L_5DEC: ;
  cpu_pop_af();
  mem_write8((uint16_t)(iy + 0x03), (uint8_t)(mem_read8((uint16_t)(iy + 0x03)) & ~(1u << 3)));
  p26_L_4C7F();
  cpu_pop_hl();
  mem_write16(0x982A, hl());
  p00_L_34C5();
  return;
}

/* flash page 26 cpu 0x5E0E (offset 0x1E0E) */
void p26_L_5E0E(void) {
  goto lab_p26_L_5E0E;
  lab_p26_L_4B14: ;
  p00_rst18();
  set_hl(0x8BBD);
  p00_rst20();
  p00_L_0C2A();
  p00_rst18();
  set_hl(0x8BD8);
  p00_rst20();
  p00_L_0C2A();
  goto lab_p26_L_4B30;
  lab_p26_L_4B30: ;
  p26_L_4AF9();
  cpu_push_af();
  p00_L_22B3();
  p00_L_128A();
  p00_L_107E();
  if (flag_nc()) goto lab_p26_L_4BAB;
  cpu_pop_af();
  p00_L_22CF();
  p00_L_0D1F();
  p00_L_231F();
  p00_L_0ED0();
  p00_rst18();
  p00_L_0C1B();
  p00_L_38A3();
  p00_L_1100();
  p00_L_2315();
  p00_L_231F();
  p00_rst30();
  p00_rst08();
  p00_L_113F();
  p00_L_0D1F();
  p00_rst18();
  p00_L_1179();
  p26_L_42DB();
  p00_rst18();
  p00_L_22CF();
  p26_L_42DB();
  p00_L_2196();
  p00_L_0C13();
  p00_rst18();
  p00_L_22D9();
  p26_L_42DB();
  p00_L_2196();
  p00_L_0C13();
  p00_L_2196();
  p00_L_0C2D();
  p00_rst18();
  p00_L_2315();
  p00_L_38A3();
  p00_L_231F();
  p00_L_0D1F();
  p00_L_2196();
  p00_rst30();
  p00_L_392D();
  p00_L_2262();
  p00_L_0ED0();
  set_de(0x0036);
  p00_L_21B6();
  return;
  lab_p26_L_4BAB: ;
  if (flag_nz()) goto lab_p26_L_4BB4;
  cpu_pop_af();
  if (flag_z()) goto lab_p26_L_4BBB;
  if (flag_c()) { p00_L_24C9(); return; }
  cpu_push_af();
  lab_p26_L_4BB4: ;
  cpu_pop_af();
  p00_L_128A();
  lab_p26_L_4BB8: ;
  p26_L_5377();
  return;
  lab_p26_L_4BBB: ;
  p00_L_1229();
  goto lab_p26_L_4BB8;
  lab_p26_L_5E0E: ;
  flag_cmp(a, 0x24);
  if (flag_c()) { p26_L_443B(); return; }
  if (flag_nz()) goto lab_p26_L_5E1B;
  p00_L_22C7();
  p26_L_4766();
  return;
  lab_p26_L_5E1B: ;
  flag_cmp(a, 0x26);
  if (flag_z()) goto lab_p26_L_4B14;
  p00_L_22C7();
  p26_L_4999();
  return;
}

/* flash page 26 cpu 0x5E26 (offset 0x1E26) */
void p26_L_5E26(void) {
  a = mem_read8(0x8A37);
  flag_cmp(a, 0x01);
  if (flag_nc()) goto lab_p26_L_5E62;
  a = b;
  flag_cmp(a, 0x26);
  if (flag_nz()) goto lab_p26_L_5E4E;
  set_hl(0x8D8F);
  p00_rst20();
  p00_L_107E();
  if (flag_c()) p00_L_14B0();
  p00_L_21E0();
  p00_rst08();
  p00_L_38F1();
  p26_L_5E7B();
  p26_L_5E46();
  return;
  lab_p26_L_5E4E: ;
  p00_L_15D1();
  p26_L_5E7B();
  p00_L_38F1();
  p00_L_231F();
  p00_L_15D1();
  p00_L_0E5C();
  goto lab_p26_L_5E64;
  lab_p26_L_5E62: ;
  if (flag_z()) { p26_L_5E7B(); return; }
  lab_p26_L_5E64: ;
  p00_L_107E();
  if (flag_z()) goto lab_p26_L_5E6A;
  if (flag_nc()) return;
  lab_p26_L_5E6A: ;
  p00_L_1276();
  p00_L_353D();
  p00_rst08();
  p00_L_38F1();
  p00_L_1100();
  p00_L_356D();
  return;
}

/* flash page 26 cpu 0x5E46 (offset 0x1E46) */
void p26_L_5E46(void) {
  p00_L_2196();
  p00_L_38F1();
  goto lab_p26_L_5E64;
  lab_p26_L_5E64: ;
  p00_L_107E();
  if (flag_z()) goto lab_p26_L_5E6A;
  if (flag_nc()) return;
  lab_p26_L_5E6A: ;
  p00_L_1276();
  p00_L_353D();
  p00_rst08();
  p00_L_38F1();
  p00_L_1100();
  p00_L_356D();
  return;
}

/* flash page 26 cpu 0x5E7B (offset 0x1E7B) */
void p26_L_5E7B(void) {
  goto lab_p26_L_5E7B;
  lab_p26_L_5E6A: ;
  p00_L_1276();
  p00_L_353D();
  p00_rst08();
  p00_L_38F1();
  p00_L_1100();
  p00_L_356D();
  return;
  lab_p26_L_5E7B: ;
  p00_L_107E();
  if (flag_nc()) goto lab_p26_L_5E6A;
  return;
}

/* flash page 26 cpu 0x5ED6 (offset 0x1ED6) */
void p26_L_5ED6(void) {
  p00_L_39F9();
  p00_L_2310();
  p00_L_107E();
  if (flag_c()) { p00_L_1229(); return; }
  p00_L_128A();
  return;
}

/* flash page 26 cpu 0x5EE5 (offset 0x1EE5) */
void p26_L_5EE5(void) {
  e = a;
  d = 0x00;
  set_hl(0x5EF0);
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  os_jp_hl();
  return;
}

/* flash page 26 cpu 0x5F7B (offset 0x1F7B) */
void p26_L_5F7B(void) {
  p00_rst18();
  p00_L_2315();
  p00_L_38DF();
  p00_L_2315();
  p00_rst18();
  p00_L_2315();
  a = 0x71;
  p00_L_3993();
  p00_rst18();
  p00_L_188D();
  mem_write16(0x84D3, de());
  cpu_push_hl();
  mem_write16(0x84AF, hl());
  mem_write16(0x84B7, hl());
  a = 0x0A;
  p00_L_3B9D();
  cpu_pop_hl();
  mem_write16(0x84AF, hl());
  mem_write16(0x84B3, hl());
  p00_L_2315();
  p00_rst10();
  mem_write16(0x84D5, de());
  /* scf */
  p00_L_3B97();
  cpu_pop_hl();
  cpu_push_hl();
  a = h;
  p00_L_355B();
  p00_L_0C2A();
  p00_rst18();
  cpu_pop_hl();
  cpu_push_hl();
  a = l;
  p00_L_355B();
  p00_L_0C2A();
  p00_L_2196();
  p00_L_0D1F();
  a = 0x27;
  p00_L_1897();
  p00_L_1884();
  p00_L_0D16();
  p00_rst18();
  cpu_pop_hl();
  a = 0x03;
  p26_L_60BA();
  p00_rst18();
  p00_L_188D();
  mem_write16(0x84D3, de());
  a = 0x02;
  p26_L_60BA();
  p00_rst10();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  set_bc(0x0101);
  p00_L_3B6D();
  a = 0x25;
  p00_L_1897();
  p00_L_0D16();
  p00_rst08();
  p00_L_219B();
  p00_rst10();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  p00_L_2315();
  p00_rst10();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  p00_L_219B();
  p26_L_4849();
  a = 0x22;
  p00_L_1897();
  p26_L_4C7F();
  cpu_pop_af();
  a = 0x11;
  cpu_push_af();
  p26_L_5186();
  cpu_pop_af();
  if (flag_z()) return;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 7)));
  p00_L_3549();
  set_hl(0x8B87);
  p00_rst20();
  p00_rst18();
  p00_L_1251();
  a = 0x15;
  mem_write8(0x8485, a);
  p00_L_0D1F();
  a = 0x85;
  mem_write8(0x8485, a);
  p00_rst30();
  a = 0x0B;
  p00_L_3675();
  a = 0x0C;
  p00_L_3675();
  p00_L_1229();
  a = 0x02;
  p00_L_3675();
  p00_L_15E0();
  a = 0x03;
  p00_L_3675();
  p00_L_128A();
  a = 0x0A;
  p00_L_3675();
  p00_L_22FC();
  p00_L_1246();
  p00_L_107E();
  if (flag_z()) goto lab_p26_L_60A6;
  if (flag_nc()) goto lab_p26_L_60AC;
  a = 0x50;
  mem_write8(0x847A, a);
  a = 0x0B;
  p00_L_3675();
  p00_L_1229();
  a = 0x17;
  mem_write8(0x847A, a);
  lab_p26_L_6080: ;
  p26_L_589C();
  a = 0x01;
  mem_write8(0x8A37, a);
  a = 0x25;
  flag_cmp(a, a);
  p26_L_5D47();
  p00_L_333F();
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) | (1u << 7)));
  mem_write8((uint16_t)(iy + 0x05), (uint8_t)(mem_read8((uint16_t)(iy + 0x05)) | (1u << 1)));
  a = 0xD9;
  p00_L_3D47();
  a = 0x12;
  set_hl(0x8B75);
  p26_L_54B0();
  return;
  lab_p26_L_60A6: ;
  set_hl(0x0FC3);
  p00_rst20();
  goto lab_p26_L_6080;
  lab_p26_L_60AC: ;
  p00_L_1246();
  p00_L_0C2D();
  p00_L_22F7();
  p26_L_4999();
  goto lab_p26_L_6080;
}

/* flash page 26 cpu 0x60BA (offset 0x20BA) */
void p26_L_60BA(void) {
  cpu_push_af();
  flag_set_z((a & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p26_L_60C2;
  a = l;
  l = h;
  h = a;
  lab_p26_L_60C2: ;
  cpu_push_hl();
  h = 0x01;
  p00_L_1C7B();
  mem_write16(0x84D7, de());
  cpu_pop_bc();
  cpu_pop_af();
  mem_write8(0x84A4, a);
  cpu_push_bc();
  lab_p26_L_60D2: ;
  cpu_push_bc();
  p00_L_1287();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  b = h;
  lab_p26_L_60DA: ;
  cpu_push_bc();
  set_hl(0x84A4);
  flag_set_z((mem_read8(hl()) & (1u << 0)) == 0);
  if (flag_nz()) goto lab_p26_L_60E5;
  a = b;
  b = c;
  c = a;
  lab_p26_L_60E5: ;
  cpu_push_hl();
  p00_L_3B79();
  cpu_pop_hl();
  flag_set_z((mem_read8(hl()) & (1u << 1)) == 0);
  if (flag_z()) p00_L_187F();
  p00_rst30();
  p00_rst08();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p26_L_60DA;
  cpu_push_bc();
  b = (uint8_t)(b + 1);
  p00_L_3B8B();
  cpu_pop_bc();
  c = (uint8_t)(c - 1);
  if (flag_nz()) goto lab_p26_L_60D2;
  cpu_pop_hl();
  p00_L_1135();
  return;
}

/* flash page 26 cpu 0x625C (offset 0x225C) */
void p26_L_625C(void) {
  p00_rst18();
  set_hl(0x8A3A);
  p00_rst20();
  p00_L_187F();
  goto lab_p26_L_6267;
  lab_p26_L_6267: ;
  p00_L_1884();
  p00_L_219B();
  return;
}

/* flash page 26 cpu 0x626D (offset 0x226D) */
void p26_L_626D(void) {
  goto lab_p26_L_626D;
  lab_p26_L_6266: ;
  p00_rst20();
  p00_L_1884();
  p00_L_219B();
  return;
  lab_p26_L_626D: ;
  p00_rst18();
  set_hl(0x8A3A);
  p26_L_62A7();
  set_hl(0x8A5E);
  goto lab_p26_L_6266;
}

/* flash page 26 cpu 0x6279 (offset 0x2279) */
void p26_L_6279(void) {
  goto lab_p26_L_6279;
  lab_p26_L_6260: ;
  p00_rst20();
  p00_L_187F();
  goto lab_p26_L_6267;
  lab_p26_L_6267: ;
  p00_L_1884();
  p00_L_219B();
  return;
  lab_p26_L_6279: ;
  p00_rst18();
  set_hl(0x8BBD);
  p00_rst20();
  p00_L_187F();
  p00_L_1884();
  set_hl(0x8BD8);
  goto lab_p26_L_6260;
}

/* flash page 26 cpu 0x6289 (offset 0x2289) */
void p26_L_6289(void) {
  p00_rst18();
  set_hl(0x8BBD);
  p26_L_62A7();
  set_hl(0x8BD8);
  p26_L_62A7();
  set_hl(0x8BB4);
  p00_rst20();
  p00_L_1884();
  set_hl(0x8BCF);
  p00_rst20();
  p00_L_1884();
  p00_L_219B();
  return;
}

/* flash page 26 cpu 0x62A7 (offset 0x22A7) */
void p26_L_62A7(void) {
  p00_L_11F8();
  p00_L_1229();
  p00_L_107E();
  if (flag_nc()) { p00_L_24C9(); return; }
  p00_L_1179();
  p00_L_187F();
  return;
}

/* flash page 26 cpu 0x62BA (offset 0x22BA) */
void p26_L_62BA(void) {
  p00_L_1295();
  a = 0x26;
  mem_write8(0x8479, a);
  p00_rst10();
  if (flag_nc()) p00_L_1F58();
  return;
}

/* flash page 26 cpu 0x62D0 (offset 0x22D0) */
void p26_L_62D0(void) {
  p00_L_2429();
  mem_write16(0x84DB, de());
  set_de(0x8D34);
  p26_L_62DA();
  return;
}

/* flash page 26 cpu 0x62DA (offset 0x22DA) */
void p26_L_62DA(void) {
  set_hl(0x847A);
  p00_L_118B();
  return;
}

/* flash page 26 cpu 0x62E0 (offset 0x22E0) */
void p26_L_62E0(void) {
  a = 0;
  flag_logic(a);
  mem_write8(0x84DC, a);
  a = (uint8_t)(a - 1);
  mem_write8(0x8D34, a);
  return;
}

/* flash page 26 cpu 0x6305 (offset 0x2305) */
void p26_L_6305(void) {
  goto lab_p26_L_6305;
  lab_p26_L_62E9: ;
  p26_L_71E9();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x1C);
  if (flag_nz()) goto lab_p26_L_62FD;
  p00_L_2196();
  p00_L_218C();
  p00_L_21E0();
  goto lab_p26_L_6312;
  lab_p26_L_62FD: ;
  p00_L_1725();
  if (flag_nz()) goto lab_p26_L_641D;
  goto lab_p26_L_630D;
  lab_p26_L_6305: ;
  p26_L_71E9();
  p00_L_1725();
  if (flag_z()) goto lab_p26_L_6312;
  lab_p26_L_630D: ;
  p26_L_62D0();
  goto lab_p26_L_6318;
  lab_p26_L_6312: ;
  p26_L_62E0();
  p00_L_21E5();
  lab_p26_L_6318: ;
  p00_L_219B();
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p26_L_63D1;
  p00_L_1641();
  lab_p26_L_6326: ;
  if (flag_z()) { p00_L_24D5(); return; }
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p26_L_6326;
  if (flag_z()) { p00_L_24DD(); return; }
  p00_L_1725();
  if (flag_nz()) goto lab_p26_L_642D;
  set_de(0x8D2F);
  p26_L_62DA();
  p00_L_2191();
  a = mem_read8(0x848E);
  a = a & 0x0F;
  flag_logic(a);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p26_L_63D1;
  a = mem_read8(0x848F);
  flag_cmp(a, 0x24);
  if (flag_z()) goto lab_p26_L_6326;
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p26_L_6326;
  set_de(0x8D2A);
  set_hl(0x8490);
  p00_L_118B();
  p00_L_21CC();
  p00_L_399F();
  if (flag_nz()) { p00_L_24E9(); return; }
  p00_L_2182();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_21D1();
  p26_L_6445();
  return;
  lab_p26_L_63D1: ;
  if (flag_nz()) { p00_L_24DD(); return; }
  p26_L_55A0();
  p00_L_2176();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p26_L_63FF;
  cpu_pop_af();
  flag_cmp(a, 0x1C);
  if (flag_nz()) goto lab_p26_L_63D1;
  cpu_push_af();
  cpu_push_bc();
  p00_L_1037();
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_10DD();
  p00_L_2176();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p26_L_63D1;
  lab_p26_L_63FF: ;
  p00_L_1641();
  if (flag_z()) goto lab_p26_L_6326;
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p26_L_6326;
  a = b;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p26_L_6420;
  cpu_pop_af();
  cpu_push_af();
  a = b;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p26_L_62E9;
  if (flag_nc()) { p00_L_24E5(); return; }
  goto lab_p26_L_6305;
  lab_p26_L_641D: ;
  p00_L_24E5();
  return;
  lab_p26_L_6420: ;
  p26_L_71E9();
  cpu_pop_af();
  cpu_push_af();
  p00_L_1725();
  if (flag_z()) goto lab_p26_L_641D;
  p26_L_62E0();
  lab_p26_L_642D: ;
  p00_L_1725();
  if (flag_z()) p00_L_21CC();
  set_hl(0x847A);
  set_de(0x8D2A);
  p00_L_118B();
  p00_L_39A5();
  p00_L_1725();
  if (flag_z()) p00_L_2182();
  p26_L_6445();
  return;
}

/* flash page 26 cpu 0x6373 (offset 0x2373) */
void p26_L_6373(void) {
  goto lab_p26_L_6373;
  lab_p26_L_62E9: ;
  p26_L_71E9();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x1C);
  if (flag_nz()) goto lab_p26_L_62FD;
  p00_L_2196();
  p00_L_218C();
  p00_L_21E0();
  goto lab_p26_L_6312;
  lab_p26_L_62FD: ;
  p00_L_1725();
  if (flag_nz()) goto lab_p26_L_641D;
  goto lab_p26_L_630D;
  lab_p26_L_630D: ;
  p26_L_62D0();
  goto lab_p26_L_6318;
  lab_p26_L_6312: ;
  p26_L_62E0();
  p00_L_21E5();
  lab_p26_L_6318: ;
  p00_L_219B();
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p26_L_63D1;
  p00_L_1641();
  lab_p26_L_6326: ;
  if (flag_z()) { p00_L_24D5(); return; }
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p26_L_6326;
  if (flag_z()) { p00_L_24DD(); return; }
  p00_L_1725();
  if (flag_nz()) goto lab_p26_L_642D;
  set_de(0x8D2F);
  p26_L_62DA();
  p00_L_2191();
  a = mem_read8(0x848E);
  a = a & 0x0F;
  flag_logic(a);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p26_L_63D1;
  a = mem_read8(0x848F);
  flag_cmp(a, 0x24);
  if (flag_z()) goto lab_p26_L_6326;
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p26_L_6326;
  set_de(0x8D2A);
  set_hl(0x8490);
  p00_L_118B();
  p00_L_21CC();
  p00_L_399F();
  if (flag_nz()) { p00_L_24E9(); return; }
  p00_L_2182();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_21D1();
  p26_L_6445();
  return;
  lab_p26_L_6373: ;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) & ~(1u << 5)));
  set_hl(0x8A37);
  mem_write8(hl(), 0x00);
  goto lab_p26_L_6384;
  lab_p26_L_6384: ;
  /* res 1,(iy) */
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 1)));
  cpu_push_bc();
  set_hl(0x9817);
  mem_write8(hl(), 0x00);
  cpu_push_af();
  set_hl(0x8499);
  p00_L_1224();
  a = 0xFF;
  mem_write8(0x84AF, a);
  cpu_pop_af();
  b = a;
  p00_L_1037();
  p00_L_1725();
  if (flag_nz()) goto lab_p26_L_63BC;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p26_L_63BC;
  cpu_push_bc();
  p00_L_1171();
  p00_L_2176();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  p00_L_1037();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) | (1u << 1)));
  lab_p26_L_63BC: ;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p26_L_63FF;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_63D1;
  cpu_push_bc();
  p00_L_1169();
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  flag_cmp(a, 0x1C);
  if (flag_z()) goto lab_p26_L_63D7;
  flag_cmp(a, 0x19);
  lab_p26_L_63D1: ;
  if (flag_nz()) { p00_L_24DD(); return; }
  p26_L_55A0();
  lab_p26_L_63D7: ;
  p00_L_2176();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p26_L_63FF;
  cpu_pop_af();
  flag_cmp(a, 0x1C);
  if (flag_nz()) goto lab_p26_L_63D1;
  cpu_push_af();
  cpu_push_bc();
  p00_L_1037();
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_10DD();
  p00_L_2176();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p26_L_63D1;
  lab_p26_L_63FF: ;
  p00_L_1641();
  if (flag_z()) goto lab_p26_L_6326;
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p26_L_6326;
  a = b;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p26_L_6420;
  cpu_pop_af();
  cpu_push_af();
  a = b;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p26_L_62E9;
  if (flag_nc()) { p00_L_24E5(); return; }
  p26_L_6305();
  return;
  lab_p26_L_641D: ;
  p00_L_24E5();
  return;
  lab_p26_L_6420: ;
  p26_L_71E9();
  cpu_pop_af();
  cpu_push_af();
  p00_L_1725();
  if (flag_z()) goto lab_p26_L_641D;
  p26_L_62E0();
  lab_p26_L_642D: ;
  p00_L_1725();
  if (flag_z()) p00_L_21CC();
  set_hl(0x847A);
  set_de(0x8D2A);
  p00_L_118B();
  p00_L_39A5();
  p00_L_1725();
  if (flag_z()) p00_L_2182();
  p26_L_6445();
  return;
}

/* flash page 26 cpu 0x637E (offset 0x237E) */
void p26_L_637E(void) {
  goto lab_p26_L_637E;
  lab_p26_L_62E9: ;
  p26_L_71E9();
  cpu_pop_af();
  cpu_push_af();
  flag_cmp(a, 0x1C);
  if (flag_nz()) goto lab_p26_L_62FD;
  p00_L_2196();
  p00_L_218C();
  p00_L_21E0();
  goto lab_p26_L_6312;
  lab_p26_L_62FD: ;
  p00_L_1725();
  if (flag_nz()) goto lab_p26_L_641D;
  goto lab_p26_L_630D;
  lab_p26_L_630D: ;
  p26_L_62D0();
  goto lab_p26_L_6318;
  lab_p26_L_6312: ;
  p26_L_62E0();
  p00_L_21E5();
  lab_p26_L_6318: ;
  p00_L_219B();
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p26_L_63D1;
  p00_L_1641();
  lab_p26_L_6326: ;
  if (flag_z()) { p00_L_24D5(); return; }
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p26_L_6326;
  if (flag_z()) { p00_L_24DD(); return; }
  p00_L_1725();
  if (flag_nz()) goto lab_p26_L_642D;
  set_de(0x8D2F);
  p26_L_62DA();
  p00_L_2191();
  a = mem_read8(0x848E);
  a = a & 0x0F;
  flag_logic(a);
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p26_L_63D1;
  a = mem_read8(0x848F);
  flag_cmp(a, 0x24);
  if (flag_z()) goto lab_p26_L_6326;
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p26_L_6326;
  set_de(0x8D2A);
  set_hl(0x8490);
  p00_L_118B();
  p00_L_21CC();
  p00_L_399F();
  if (flag_nz()) { p00_L_24E9(); return; }
  p00_L_2182();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_21D1();
  p26_L_6445();
  return;
  lab_p26_L_637E: ;
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 5)));
  b = 0x00;
  /* res 1,(iy) */
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) & ~(1u << 1)));
  cpu_push_bc();
  set_hl(0x9817);
  mem_write8(hl(), 0x00);
  cpu_push_af();
  set_hl(0x8499);
  p00_L_1224();
  a = 0xFF;
  mem_write8(0x84AF, a);
  cpu_pop_af();
  b = a;
  p00_L_1037();
  p00_L_1725();
  if (flag_nz()) goto lab_p26_L_63BC;
  flag_cmp(a, 0x03);
  if (flag_nz()) goto lab_p26_L_63BC;
  cpu_push_bc();
  p00_L_1171();
  p00_L_2176();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  p00_L_1037();
  mem_write8((uint16_t)(iy + 0x1A), (uint8_t)(mem_read8((uint16_t)(iy + 0x1A)) | (1u << 1)));
  lab_p26_L_63BC: ;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p26_L_63FF;
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_63D1;
  cpu_push_bc();
  p00_L_1169();
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  cpu_push_bc();
  flag_cmp(a, 0x1C);
  if (flag_z()) goto lab_p26_L_63D7;
  flag_cmp(a, 0x19);
  lab_p26_L_63D1: ;
  if (flag_nz()) { p00_L_24DD(); return; }
  p26_L_55A0();
  lab_p26_L_63D7: ;
  p00_L_2176();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p26_L_63FF;
  cpu_pop_af();
  flag_cmp(a, 0x1C);
  if (flag_nz()) goto lab_p26_L_63D1;
  cpu_push_af();
  cpu_push_bc();
  p00_L_1037();
  if (flag_nz()) { p00_L_24C9(); return; }
  p00_L_10DD();
  p00_L_2176();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  p00_L_1037();
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p26_L_63D1;
  lab_p26_L_63FF: ;
  p00_L_1641();
  if (flag_z()) goto lab_p26_L_6326;
  flag_cmp(a, 0x72);
  if (flag_z()) goto lab_p26_L_6326;
  a = b;
  flag_cmp(a, 0x01);
  if (flag_z()) goto lab_p26_L_6420;
  cpu_pop_af();
  cpu_push_af();
  a = b;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p26_L_62E9;
  if (flag_nc()) { p00_L_24E5(); return; }
  p26_L_6305();
  return;
  lab_p26_L_641D: ;
  p00_L_24E5();
  return;
  lab_p26_L_6420: ;
  p26_L_71E9();
  cpu_pop_af();
  cpu_push_af();
  p00_L_1725();
  if (flag_z()) goto lab_p26_L_641D;
  p26_L_62E0();
  lab_p26_L_642D: ;
  p00_L_1725();
  if (flag_z()) p00_L_21CC();
  set_hl(0x847A);
  set_de(0x8D2A);
  p00_L_118B();
  p00_L_39A5();
  p00_L_1725();
  if (flag_z()) p00_L_2182();
  p26_L_6445();
  return;
}

/* flash page 26 cpu 0x6445 (offset 0x2445) */
void p26_L_6445(void) {
  cpu_pop_af();
  mem_write8(0x8A36, a);
  set_hl(0x62C7);
  p00_L_25A2();
  p26_L_64B8();
  p00_L_25C8();
  p26_L_62BA();
  a = mem_read8(0x8A36);
  flag_cmp(a, 0x04);
  if (flag_nc()) goto lab_p26_L_6479;
  lab_p26_L_645F: ;
  a = 0x16;
  set_hl(0x8AEE);
  p00_rst20();
  p00_rst08();
  set_hl(0x8AF7);
  p00_rst20();
  a = 0x16;
  p00_L_1897();
  p00_L_1179();
  a = 0x17;
  p00_L_1897();
  goto lab_p26_L_647D;
  lab_p26_L_6479: ;
  flag_cmp(a, 0x19);
  if (flag_z()) goto lab_p26_L_645F;
  lab_p26_L_647D: ;
  p26_L_723D();
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 7)));
  p26_L_6703();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p26_L_649A;
  p00_L_1691();
  p00_rst18();
  p00_L_2315();
  p00_L_38DF();
  p00_L_21A7();
  lab_p26_L_649A: ;
  a = mem_read8(0x8A36);
  flag_cmp(a, 0x19);
  if (flag_nz()) return;
  /* bit 1,(iy) */
  if (flag_nz()) { p00_L_2515(); return; }
  a = 0x22;
  p26_L_5EE5();
  return;
}

/* flash page 26 cpu 0x64AD (offset 0x24AD) */
void p26_L_64AD(void) {
  p00_rst08();
  set_hl(mem_read16(0x84AF));
  p26_L_6EBC();
  p00_L_0D1F();
  return;
}

/* flash page 26 cpu 0x64B8 (offset 0x24B8) */
void p26_L_64B8(void) {
  p26_L_6ECF();
  if (flag_z()) goto lab_p26_L_64D0;
  set_hl(mem_read16(0x84DB));
  p00_L_0033();
  cpu_ex_de_hl();
  set_hl(mem_read16(0x84D3));
  p00_L_0033();
  p00_L_192A();
  if (flag_nz()) { p00_L_24E9(); return; }
  lab_p26_L_64D0: ;
  set_hl(mem_read16(0x84D3));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  a = mem_read8(0x8A36);
  flag_cmp(a, 0x08);
  if (flag_nz()) goto lab_p26_L_64EE;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 4)));
  p26_L_7548();
  p26_L_751D();
  p26_L_78F9();
  return;
  lab_p26_L_64EE: ;
  flag_cmp(a, 0x1C);
  if (flag_z()) goto lab_p26_L_6501;
  flag_cmp(a, 0x19);
  if (flag_z()) goto lab_p26_L_6501;
  if (flag_nc()) goto lab_p26_L_6F52;
  flag_cmp(a, 0x09);
  if (flag_z()) goto lab_p26_L_6501;
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p26_L_6503;
  lab_p26_L_6501: ;
  a = 0x04;
  lab_p26_L_6503: ;
  a = (uint8_t)(a - 0x02);
  cpu_push_af();
  a = mem_read8(0x8A36);
  flag_cmp(a, 0x1C);
  if (flag_z()) goto lab_p26_L_68F9;
  cpu_pop_af();
  set_hl(mem_read16(0x84D5));
  mem_write16(0x84D7, hl());
  set_hl(mem_read16(0x84DB));
  mem_write16(0x84D5, hl());
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) & ~(1u << 5)));
  p00_L_1725();
  if (flag_nz()) goto lab_p26_L_7450;
  cpu_push_af();
  cpu_push_de();
  mem_write16(0x84AF, de());
  a = 0;
  flag_logic(a);
  a = mem_read8(0x8A36);
  p00_L_3999();
  set_hl(mem_read16(0x84D7));
  mem_write16(0x84D5, hl());
  p00_rst18();
  p00_L_21E0();
  p00_L_21D6();
  p00_rst18();
  set_de(0x8A3A);
  set_hl(0x8483);
  p00_L_1183();
  set_hl(0x8499);
  p00_L_1183();
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_L_1183();
  set_de(0x8A94);
  p00_L_11FD();
  set_hl(0x84AF);
  p00_L_1183();
  p00_L_1295();
  cpu_pop_hl();
  mem_write16(0x84B3, hl());
  p00_rst18();
  cpu_pop_af();
  cpu_push_af();
  h = a;
  l = a;
  l = (uint8_t)(l + 1);
  p00_L_1C7B();
  mem_write16(0x84D9, de());
  p00_L_21D6();
  p00_L_128A();
  p00_rst18();
  p00_rst18();
  mem_write16(0x9302, de());
  p00_rst18();
  p00_L_29E3();
  a = 0;
  flag_logic(a);
  lab_p26_L_6585: ;
  mem_write8(0x84B1, a);
  lab_p26_L_6588: ;
  mem_write8(0x84B2, a);
  p00_L_128A();
  p00_L_29A1();
  p00_L_29AA();
  set_hl(0x0001);
  lab_p26_L_6597: ;
  mem_write16(0x84AF, hl());
  p00_L_3AEF();
  b = 0x02;
  p26_L_6EA9();
  p00_L_28EC();
  p00_L_0C2D();
  set_hl(mem_read16(0x84B1));
  a = l;
  a = a | a;
  flag_logic(a);
  cpu_push_af();
  a = (uint8_t)(a + h);
  l = a;
  h = 0x00;
  cpu_push_af();
  p00_L_3B55();
  cpu_pop_af();
  if (flag_z()) p00_L_1229();
  p00_L_29C1();
  p00_L_3915();
  p00_L_187A();
  p00_L_28DB();
  p26_L_64AD();
  p00_L_10DD();
  p00_L_2893();
  p00_rst30();
  p00_L_29AA();
  cpu_pop_af();
  if (flag_nz()) goto lab_p26_L_6632;
  set_hl(mem_read16(0x84AF));
  p00_L_3B0D();
  p00_L_21D6();
  b = 0x01;
  p26_L_6EA9();
  p00_L_28E0();
  p00_L_0C2D();
  a = mem_read8(0x84B2);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_6625;
  p00_rst18();
  p00_L_0D1E();
  p26_L_64AD();
  p00_L_2917();
  p00_rst30();
  p00_L_29E3();
  set_hl(mem_read16(0x84AF));
  p00_L_3B0D();
  b = 0x01;
  p26_L_6EA9();
  p00_rst18();
  p00_L_3AEF();
  b = 0x02;
  p26_L_6EA9();
  p00_L_2196();
  p00_L_0D1F();
  p26_L_64AD();
  p00_L_231F();
  p00_rst30();
  p00_L_2375();
  p00_L_219B();
  lab_p26_L_6625: ;
  p00_L_2196();
  p00_L_0D1F();
  p00_L_28FD();
  p00_rst30();
  p00_L_29A1();
  lab_p26_L_6632: ;
  set_hl(mem_read16(0x84AF));
  set_de(mem_read16(0x84B3));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  cpu_push_af();
  set_hl((uint16_t)(hl() + de()));
  set_hl((uint16_t)(hl() + 1));
  cpu_pop_af();
  if (flag_c()) goto lab_p26_L_6597;
  p00_L_289D();
  set_bc(mem_read16(0x84B1));
  b = (uint8_t)(b + 1);
  c = (uint8_t)(c + 1);
  cpu_push_bc();
  set_de(mem_read16(0x84D9));
  p00_L_3B91();
  cpu_pop_bc();
  cpu_push_bc();
  a = c;
  c = b;
  b = a;
  set_de(mem_read16(0x84D9));
  p00_L_3B91();
  p00_L_2902();
  cpu_pop_bc();
  a = mem_read8(0x84B1);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_6673;
  set_de(mem_read16(0x84D9));
  a = mem_read8(de());
  c = a;
  p00_L_3B91();
  lab_p26_L_6673: ;
  a = mem_read8(0x84B2);
  cpu_pop_bc();
  cpu_push_bc();
  a = (uint8_t)(a + 1);
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p26_L_6588;
  a = mem_read8(0x84B1);
  cpu_pop_bc();
  cpu_push_bc();
  a = (uint8_t)(a + 1);
  flag_cmp(a, b);
  if (flag_nz()) goto lab_p26_L_6585;
  p00_L_219B();
  a = 0x11;
  p00_L_1897();
  p00_L_21A4();
  set_bc(0x0202);
  set_de(mem_read16(0x84D9));
  p00_L_3B7F();
  p00_rst18();
  mem_write16(0x9302, de());
  p00_L_1171();
  set_de(0x8A67);
  p26_L_68C6();
  set_de(0x8AB8);
  p26_L_68C6();
  /* bit 1,(iy) */
  if (flag_nz()) goto lab_p26_L_66D7;
  p00_L_2267();
  p00_L_163B();
  if (flag_c()) goto lab_p26_L_66D7;
  p00_L_0C2A();
  p00_L_10DD();
  p00_rst08();
  p00_L_113A();
  set_de(0x8A5E);
  p26_L_68CB();
  p00_L_10EF();
  set_de(0x8AAF);
  p26_L_68CB();
  lab_p26_L_66D7: ;
  p00_L_22D9();
  set_de(0x8A55);
  p26_L_68DA();
  p00_L_2277();
  p00_L_1171();
  p00_L_22CF();
  set_de(0x8AA6);
  p26_L_68DA();
  a = mem_read8(0x8A36);
  flag_cmp(a, 0x09);
  if (flag_nz()) goto lab_p26_L_6708;
  p26_L_6F41();
  p26_L_6EE3();
  p26_L_66FC();
  return;
  lab_p26_L_6708: ;
  set_hl(mem_read16(0x84D9));
  mem_write16(0x84D3, hl());
  p00_L_0033();
  cpu_push_hl();
  cpu_push_hl();
  mem_write16(0x84AF, hl());
  cpu_pop_bc();
  lab_p26_L_6717: ;
  cpu_push_bc();
  set_de(mem_read16(0x84D9));
  p00_L_3B7F();
  p00_rst18();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  a = b;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p26_L_6717;
  cpu_pop_bc();
  cpu_push_bc();
  a = b;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p26_L_6765;
  cpu_push_bc();
  set_bc(0x0202);
  set_de(mem_read16(0x84D9));
  p00_L_3B7F();
  p00_L_1887();
  p00_rst08();
  cpu_pop_bc();
  lab_p26_L_673E: ;
  cpu_push_bc();
  set_de(mem_read16(0x84D9));
  p00_L_3B7F();
  p00_L_0ED0();
  cpu_pop_bc();
  cpu_push_bc();
  set_de(mem_read16(0x84D9));
  p00_L_3B91();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  a = b;
  flag_cmp(a, 0x01);
  if (flag_nz()) goto lab_p26_L_673E;
  p00_L_128A();
  set_de(mem_read16(0x84D9));
  p00_L_3B91();
  goto lab_p26_L_6772;
  lab_p26_L_6765: ;
  a = 0;
  flag_logic(a);
  p00_L_3BA3();
  cpu_pop_bc();
  cpu_push_bc();
  c = (uint8_t)(c - 1);
  p00_L_3B79();
  p00_L_1887();
  lab_p26_L_6772: ;
  p00_L_2910();
  p00_L_28FD();
  p00_L_0D1F();
  p00_L_14C7();
  if (flag_z()) goto lab_p26_L_6796;
  cpu_pop_bc();
  cpu_push_bc();
  a = b;
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p26_L_6796;
  p00_L_3A05();
  p00_rst08();
  p00_L_22FC();
  p00_L_0ED0();
  a = 0x12;
  p00_L_1897();
  lab_p26_L_6796: ;
  p00_L_128A();
  cpu_pop_bc();
  cpu_push_bc();
  h = b;
  l = c;
  b = 0x02;
  lab_p26_L_679F: ;
  cpu_push_hl();
  cpu_push_bc();
  p00_L_10DD();
  p00_L_2196();
  cpu_pop_bc();
  cpu_push_bc();
  p00_L_3B79();
  p00_L_0D1F();
  p00_L_10EF();
  p00_rst30();
  cpu_pop_bc();
  cpu_pop_hl();
  b = (uint8_t)(b + 1);
  a = h;
  flag_cmp(a, b);
  if (flag_nc()) goto lab_p26_L_679F;
  p00_L_290B();
  p00_L_14CC();
  if (flag_z()) goto lab_p26_L_67D3;
  p00_L_0ED0();
  lab_p26_L_67D3: ;
  cpu_pop_bc();
  cpu_push_bc();
  lab_p26_L_68F9: ;
  cpu_pop_af();
  cpu_push_de();
  set_hl(0x0003);
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_nc()) { p00_L_24ED(); return; }
  p00_L_1135();
  p00_L_1884();
  p00_L_187F();
  p00_L_1251();
  set_hl(0x8484);
  mem_write8(hl(), 0x81);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x17);
  p00_L_107E();
  if (flag_nc()) { p00_L_24C9(); return; }
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_21D1();
  p00_L_21D6();
  p00_L_21CC();
  set_hl(mem_read16(0x84D3));
  mem_write16(0x84D7, hl());
  set_hl(mem_read16(0x84D5));
  mem_write16(0x84D3, hl());
  a = 0;
  flag_logic(a);
  mem_write8(0x84D6, a);
  cpu_pop_de();
  cpu_push_de();
  mem_write16(0x84AF, de());
  a = 0;
  flag_logic(a);
  /* scf */
  p00_L_3999();
  p00_L_2196();
  p00_rst18();
  a = mem_read8(0x8483);
  flag_cmp(a, 0xFF);
  if (flag_nz()) goto lab_p26_L_6B8B;
  p00_L_1276();
  set_hl(0x0001);
  p00_L_3E6D();
  cpu_push_hl();
  p00_L_22F7();
  p00_L_0C2D();
  p00_L_1171();
  p00_L_0D1E();
  cpu_pop_hl();
  set_de(0x8483);
  p00_L_1183();
  p00_rst18();
  p00_L_2315();
  p00_L_0C13();
  p00_L_1169();
  p00_L_0D1E();
  p00_L_22F7();
  p00_rst30();
  p00_L_233D();
  p00_L_16B5();
  p00_L_128A();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  set_hl(0x0002);
  lab_p26_L_6994: ;
  p00_L_0189();
  if (flag_nz()) { p00_L_2511(); return; }
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p00_L_3E6D();
  p00_L_2893();
  p00_L_0C2D();
  p00_L_1118();
  p00_L_1144();
  p00_L_1169();
  p00_L_2262();
  p00_rst30();
  p00_L_23A4();
  p00_L_1135();
  p00_L_2281();
  p00_rst30();
  p00_L_239A();
  p00_L_113A();
  p00_L_2272();
  p00_rst30();
  p00_L_2393();
  p00_L_1135();
  p00_L_0D1E();
  p00_L_22B3();
  p00_rst30();
  p00_L_23B3();
  p00_L_113A();
  p00_L_10EF();
  p00_L_0D1F();
  p00_L_22C7();
  p00_rst30();
  p00_L_2389();
  p00_L_1135();
  p00_L_1128();
  p00_L_0D1F();
  p00_L_231F();
  p00_rst30();
  p00_L_2375();
  p00_L_113A();
  p00_L_0D1E();
  p00_L_2310();
  p00_rst30();
  p00_L_235C();
  p00_L_113A();
  p00_L_1128();
  p00_L_0D1F();
  p00_L_22F7();
  p00_rst30();
  p00_L_233D();
  p00_L_1130();
  p00_L_0D1E();
  p00_L_28FD();
  p00_rst30();
  p00_L_29A1();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_de();
  p00_L_192A();
  if (flag_nz()) goto lab_p26_L_6994;
  set_hl(0x0304);
  mem_write16(0x84AF, hl());
  p00_L_1C7B();
  mem_write16(0x84D9, de());
  cpu_pop_hl();
  cpu_push_hl();
  set_hl((uint16_t)(hl() - 1));
  set_hl((uint16_t)(hl() - 1));
  cpu_push_de();
  p00_L_3B55();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_hl(0x8483);
  p00_L_1183();
  set_hl(mem_read16(0x9302));
  set_bc(0x001B);
  while (bc() != 0) { cpu_ldi(); }
  cpu_push_hl();
  set_hl(mem_read16(0x9302));
  p00_L_1183();
  cpu_pop_hl();
  set_bc(0x001B);
  while (bc() != 0) { cpu_ldi(); }
  cpu_push_hl();
  cpu_push_de();
  p00_L_2277();
  cpu_pop_de();
  p00_L_11FD();
  cpu_push_de();
  p00_L_22CF();
  cpu_pop_de();
  p00_L_11FD();
  cpu_pop_hl();
  p00_L_35D3();
  set_hl(mem_read16(0x9302));
  mem_write16(0x9824, hl());
  p00_L_21D6();
  set_hl(mem_read16(0x84D3));
  mem_write16(0x84DB, hl());
  set_hl(mem_read16(0x84D9));
  mem_write16(0x84D3, hl());
  a = 0;
  flag_logic(a);
  p00_L_3BA3();
  p00_L_128A();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  set_bc(0x0304);
  p00_L_3B79();
  set_hl(0x0FCC);
  p00_L_0D19();
  p00_L_10DD();
  set_bc(0x0204);
  p00_L_3B79();
  p00_L_0ECC();
  p00_rst08();
  p00_L_1229();
  p00_L_0C2D();
  p00_L_10EF();
  p00_L_0D1F();
  p00_rst18();
  p00_L_14C7();
  if (flag_z()) goto lab_p26_L_6AC2;
  p00_L_163B();
  if (flag_nc()) { p00_L_24C5(); return; }
  lab_p26_L_6AC2: ;
  set_bc(0x0303);
  p00_L_3B79();
  p00_L_14C7();
  if (flag_z()) { p00_L_24C5(); return; }
  p00_L_2267();
  p00_rst10();
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) | (1u << 7)));
  p00_L_2277();
  a = mem_read8(0x8479);
  a = (uint8_t)(a - 0x0A);
  mem_write8(0x8479, a);
  if (flag_c()) p00_L_128A();
  p00_L_2393();
  set_hl(mem_read16(0x84D7));
  set_hl((uint16_t)(hl() + 1));
  set_hl((uint16_t)(hl() + 1));
  p00_rst20();
  mem_write16(0x8499, hl());
  p00_L_1171();
  p00_L_1169();
  set_hl(0x0001);
  lab_p26_L_6B8B: ;
  p00_L_1179();
  p00_L_1884();
  p00_rst18();
  p00_L_1276();
  set_hl(0x0000);
  lab_p26_L_6B98: ;
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p00_L_3E6D();
  p00_L_2310();
  p00_L_0C2D();
  p00_L_0D1E();
  p00_L_10EF();
  p00_rst30();
  p00_L_10DD();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_de();
  p00_L_192A();
  if (flag_nz()) goto lab_p26_L_6B98;
  a = mem_read8(0x8479);
  a = (uint8_t)(a - 0x0A);
  mem_write8(0x8479, a);
  if (flag_c()) p00_L_128A();
  p00_L_2196();
  p00_rst18();
  p00_L_128A();
  p00_rst18();
  p00_rst18();
  p00_rst18();
  p00_L_22D9();
  p00_rst18();
  p00_rst18();
  set_hl(0x8000);
  mem_write16(0x8478, hl());
  set_de(0x847A);
  set_hl(0x1583);
  p00_L_1187();
  p00_L_0ED0();
  p00_L_233D();
  set_hl(mem_read16(0x84D7));
  mem_write16(0x84D5, hl());
  mem_write8((uint16_t)(iy + 0x1E), (uint8_t)(mem_read8((uint16_t)(iy + 0x1E)) | (1u << 6)));
  set_hl(0x0405);
  p00_L_1C7B();
  mem_write16(0x84D9, de());
  p00_L_1135();
  p00_L_23B3();
  p00_L_16B5();
  p00_L_128A();
  b = 0x11;
  lab_p26_L_6C06: ;
  cpu_push_bc();
  p00_rst18();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p26_L_6C06;
  p00_L_0189();
  if (flag_nz()) { p00_L_2511(); return; }
  p00_L_128A();
  b = 0x11;
  set_de(mem_read16(0x9302));
  lab_p26_L_6C1A: ;
  cpu_push_bc();
  p00_L_11FD();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p26_L_6C1A;
  set_hl(0x0000);
  lab_p26_L_6C24: ;
  p00_L_0189();
  if (flag_nz()) { p00_L_2511(); return; }
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p00_L_3B0D();
  p00_rst18();
  p00_L_28FD();
  p00_L_0D1F();
  p00_L_38A9();
  p00_L_23AE();
  p00_L_2389();
  p00_L_28C3();
  p00_L_0D1F();
  p00_L_10DD();
  p00_L_22D9();
  p00_L_28B0();
  p00_L_0D1F();
  p00_L_10EF();
  p00_L_0C2D();
  p00_L_2196();
  p00_L_0D1F();
  p00_L_235C();
  p00_L_28CB();
  p00_L_22C7();
  p00_L_0D1F();
  p00_L_10DD();
  p00_L_28B0();
  p00_L_2324();
  p00_L_0D1F();
  p00_L_10EF();
  p00_rst30();
  p00_L_2893();
  p00_rst30();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_3B01();
  p00_L_0C2D();
  p00_L_233D();
  set_hl(mem_read16(0x9302));
  cpu_push_hl();
  p00_L_22CF();
  p26_L_6E90();
  p00_L_2324();
  p26_L_6E90();
  p00_L_22CF();
  p26_L_6E96();
  p00_L_2315();
  p26_L_6E90();
  p00_L_22FC();
  p26_L_6E90();
  p00_L_2324();
  p00_L_0D1E();
  p26_L_6E96();
  p00_L_2324();
  p26_L_6E96();
  p00_L_2324();
  p00_L_2310();
  p26_L_6E93();
  p00_L_2324();
  p00_L_22F7();
  p26_L_6E93();
  p00_L_2315();
  p26_L_6E96();
  p00_L_22FC();
  p26_L_6E96();
  p00_L_2315();
  p00_L_0D1E();
  p26_L_6E96();
  p00_L_2315();
  p00_L_22F7();
  p26_L_6E93();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_de();
  p00_L_192A();
  if (flag_nz()) goto lab_p26_L_6C24;
  set_de(mem_read16(0x84D9));
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  set_hl(mem_read16(0x9302));
  set_bc(0x002D);
  while (bc() != 0) { cpu_ldi(); }
  cpu_push_hl();
  cpu_push_de();
  set_hl(mem_read16(0x9302));
  p00_rst20();
  cpu_pop_de();
  p00_L_1183();
  mem_write16(0x848E, hl());
  cpu_pop_hl();
  set_bc(0x0024);
  while (bc() != 0) { cpu_ldi(); }
  cpu_push_hl();
  set_hl(mem_read16(0x848E));
  p00_L_1183();
  mem_write16(0x848E, hl());
  cpu_push_de();
  p00_L_229F();
  cpu_pop_de();
  p00_L_11FD();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  p00_L_3B55();
  cpu_pop_de();
  set_hl(0x8483);
  p00_L_1183();
  cpu_pop_hl();
  lab_p26_L_6F52: ;
  set_hl(mem_read16(0x84D3));
  p00_L_0033();
  set_de(0x0003);
  cpu_push_hl();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_c()) { p00_L_2515(); return; }
  p26_L_6ED4();
  a = 0x01;
  set_hl(0x0001);
  cpu_pop_bc();
  cpu_push_bc();
  p00_L_3B2B();
  cpu_push_hl();
  p00_L_3E6D();
  p00_rst18();
  a = 0;
  flag_logic(a);
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_push_hl();
  set_hl(0x0001);
  p00_L_3B2B();
  cpu_push_hl();
  p00_L_3E6D();
  p00_L_22F7();
  p00_L_0ED0();
  p00_rst18();
  p26_L_6ED4();
  p00_L_1229();
  a = 0x19;
  mem_write8(0x847A, a);
  p00_L_0ECC();
  p00_rst18();
  p00_L_2315();
  p00_L_0D1F();
  p00_L_0C2A();
  p00_L_3945();
  p00_rst18();
  set_hl(0x71E0);
  p00_rst20();
  p00_L_22F7();
  p00_L_0C2D();
  p00_L_1100();
  cpu_pop_hl();
  p00_L_3E6D();
  p00_L_1169();
  p00_rst08();
  cpu_pop_hl();
  p00_L_3E6D();
  p00_L_0C2D();
  p00_rst08();
  p00_L_113F();
  p00_L_0ED0();
  p00_rst18();
  p00_L_1128();
  p00_L_0D1F();
  p00_L_2310();
  p00_L_0C13();
  p00_L_235C();
  set_hl(0x0304);
  p00_L_1C7B();
  p00_L_21D6();
  set_hl(0x0005);
  p00_L_21C0();
  mem_write16(0x9302, hl());
  b = 0x40;
  lab_p26_L_6FEC: ;
  p00_L_0189();
  if (flag_nz()) { p00_L_2511(); return; }
  cpu_push_bc();
  p00_L_28F1();
  p00_rst10();
  mem_write16(0x84D7, de());
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  b = 0x0C;
  p00_L_128A();
  lab_p26_L_7002: ;
  cpu_push_bc();
  p00_L_11FD();
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (b != 0) goto lab_p26_L_7002;
  set_hl(mem_read16(0x84D3));
  p00_L_0033();
  lab_p26_L_700F: ;
  p00_L_0189();
  if (flag_nz()) { p00_L_2511(); return; }
  cpu_push_hl();
  p00_L_3E6D();
  p00_L_290B();
  p00_L_0D1F();
  p00_L_2917();
  p00_rst30();
  p00_L_23B3();
  p00_L_393F();
  p00_L_0ECC();
  p00_L_2389();
  p00_L_0D1E();
  p00_L_2923();
  p00_L_0D1F();
  p00_L_2375();
  p00_rst08();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_3E6D();
  p00_L_0D1F();
  p00_L_235C();
  p00_L_22D9();
  p00_L_3939();
  p00_L_22C7();
  p00_L_0D1F();
  p00_L_0C1B();
  p00_L_233D();
  p00_L_2923();
  p00_L_0D1F();
  p00_L_10DD();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_3B0D();
  p00_L_2940();
  p00_L_0ED0();
  p00_L_10EF();
  p00_L_0C13();
  p00_L_23B3();
  cpu_pop_hl();
  cpu_push_hl();
  p26_L_6EBC();
  p00_rst18();
  p00_L_28B0();
  set_de(mem_read16(0x84D7));
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  p26_L_71A3();
  cpu_push_de();
  p00_L_2893();
  cpu_pop_de();
  p26_L_71A3();
  cpu_push_de();
  p00_L_28FD();
  cpu_pop_de();
  p26_L_71A3();
  p00_L_21A7();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_700F;
  set_hl(mem_read16(0x84D3));
  mem_write16(0x84D9, hl());
  set_hl(mem_read16(0x84D7));
  mem_write16(0x84D3, hl());
  set_bc(0x0104);
  p00_L_3B79();
  p00_L_29C8();
  set_bc(0x0204);
  p00_L_3B79();
  p00_L_29AA();
  set_bc(0x0304);
  mem_write16(0x84AF, bc());
  p00_L_3B79();
  p00_L_29A1();
  p00_L_0189();
  if (flag_nz()) { p00_L_2511(); return; }
  a = 0;
  flag_logic(a);
  p00_L_3BA9();
  set_bc(0x0303);
  p00_L_3B79();
  p00_L_1887();
  set_hl(0x0104);
  mem_write16(0x84AF, hl());
  p00_L_128A();
  p00_L_28B0();
  p26_L_718C();
  p00_L_2893();
  p26_L_718C();
  p00_L_28FD();
  p26_L_718C();
  a = mem_read8(0x8479);
  cpu_push_af();
  p00_L_3A05();
  a = 0x10;
  p00_L_3561();
  p00_L_0D1F();
  p00_L_0C1B();
  p00_L_0ECC();
  p00_rst18();
  set_hl(0x0104);
  mem_write16(0x84AF, hl());
  p00_L_291C();
  p26_L_7186();
  p00_L_29E3();
  p00_L_2910();
  p26_L_7186();
  p00_L_29DF();
  p00_L_2928();
  p26_L_7186();
  p00_L_2A0F();
  p00_L_21A7();
  cpu_pop_af();
  flag_cmp(a, 0x74);
  if (flag_c()) goto lab_p26_L_7148;
  set_hl(mem_read16(0x84D9));
  mem_write16(0x84D3, hl());
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_nz()) goto lab_p26_L_6FEC;
  p00_L_2521();
  return;
  lab_p26_L_7148: ;
  cpu_pop_af();
  p00_L_2940();
  p00_L_0D1F();
  p00_L_0C18();
  a = 0x18;
  p00_L_1897();
  p00_L_2910();
  p00_L_0C18();
  a = 0x17;
  p00_L_1897();
  p00_L_291C();
  p00_L_0C18();
  p00_L_0E4C();
  p00_L_3933();
  a = 0x16;
  p00_L_1897();
  lab_p26_L_7450: ;
  /* res 1,(iy) */
  cpu_push_de();
  a = 0;
  flag_logic(a);
  /* scf */
  p00_L_3999();
  p00_L_222C();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p26_L_7475;
  set_hl(0x8483);
  set_de(0x8A3A);
  p00_L_1183();
  p00_L_11FD();
  set_hl(0x84A4);
  p00_L_1183();
  lab_p26_L_7475: ;
  p00_L_128A();
  cpu_pop_hl();
  lab_p26_L_7479: ;
  mem_write16(0x84AF, hl());
  p00_L_1171();
  p00_L_3AFB();
  p00_L_2315();
  p00_L_0C13();
  p00_L_0D1E();
  p26_L_64AD();
  p00_L_1108();
  p00_rst30();
  set_hl(mem_read16(0x84AF));
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_7479;
  p00_L_1171();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p26_L_74B1;
  set_hl(0x8A3A);
  p00_L_0EC1();
  p00_L_3A05();
  a = 0x07;
  p00_L_1897();
  lab_p26_L_74B1: ;
  /* bit 1,(iy) */
  if (flag_nz()) goto lab_p26_L_74DD;
  p00_L_22FC();
  p00_L_1251();
  p00_L_107E();
  if (flag_z()) goto lab_p26_L_74DD;
  if (flag_c()) goto lab_p26_L_74DD;
  p00_L_0C2D();
  p00_rst08();
  p00_L_113A();
  p00_L_0ED0();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 5)) == 0);
  if (flag_nz()) { p00_L_21A4(); return; }
  p00_L_3A05();
  a = 0x06;
  p00_L_1897();
  lab_p26_L_74DD: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 5)) == 0);
  if (flag_nz()) { p00_L_24C9(); return; }
  set_hl(0x8A43);
  p00_rst20();
  p00_L_0D1E();
  set_hl(0x8A3A);
  p00_L_0D19();
  p00_L_1108();
  p00_rst30();
  a = 0x05;
  p00_L_1897();
  p00_L_21A4();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 6)));
  p26_L_7548();
  p00_L_1295();
  a = 0x26;
  mem_write8(0x8479, a);
  p00_rst10();
  if (flag_nc()) p00_L_1F58();
  p26_L_751D();
  return;
}

/* flash page 26 cpu 0x66FC (offset 0x26FC) */
void p26_L_66FC(void) {
  set_bc(0x003F);
  p00_L_21AA();
  cpu_pop_af();
  p26_L_6703();
  return;
}

/* flash page 26 cpu 0x6703 (offset 0x2703) */
void p26_L_6703(void) {
  mem_write8((uint16_t)(iy + 0x09), (uint8_t)(mem_read8((uint16_t)(iy + 0x09)) | (1u << 6)));
  return;
}

/* flash page 26 cpu 0x68C6 (offset 0x28C6) */
void p26_L_68C6(void) {
  cpu_push_de();
  p00_L_2262();
  cpu_pop_de();
  p26_L_68CB();
  return;
}

/* flash page 26 cpu 0x68CB (offset 0x28CB) */
void p26_L_68CB(void) {
  cpu_push_de();
  p00_L_0ED0();
  p00_L_3A05();
  cpu_pop_de();
  p00_L_11FD();
  p00_L_2277();
  return;
}

/* flash page 26 cpu 0x68DA (offset 0x28DA) */
void p26_L_68DA(void) {
  cpu_push_de();
  p00_L_0D1E();
  cpu_pop_de();
  cpu_push_de();
  p00_L_2262();
  p00_L_0D1F();
  p00_L_1108();
  p00_rst30();
  p00_L_15FB();
  cpu_pop_de();
  p00_L_11FD();
  return;
}

/* flash page 26 cpu 0x6E90 (offset 0x2E90) */
void p26_L_6E90(void) {
  p00_L_22C7();
  p26_L_6E93();
  return;
}

/* flash page 26 cpu 0x6E93 (offset 0x2E93) */
void p26_L_6E93(void) {
  p00_L_0D1F();
  p26_L_6E96();
  return;
}

/* flash page 26 cpu 0x6E96 (offset 0x2E96) */
void p26_L_6E96(void) {
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_bc();
  cpu_push_hl();
  p00_L_0C20();
  cpu_pop_de();
  p00_L_11FD();
  cpu_pop_hl();
  cpu_push_de();
  os_jp_hl();
  return;
}

/* flash page 26 cpu 0x6EA4 (offset 0x2EA4) */
void p26_L_6EA4(void) {
  set_hl(0x8A3A);
  p00_rst20();
  return;
}

/* flash page 26 cpu 0x6EA9 (offset 0x2EA9) */
void p26_L_6EA9(void) {
  a = mem_read8(0x8A36);
  flag_cmp(a, 0x04);
  if (flag_nc()) return;
  a = a & b;
  flag_logic(a);
  if (flag_z()) return;
  p00_L_3921();
  return;
}

/* flash page 26 cpu 0x6EB5 (offset 0x2EB5) */
void p26_L_6EB5(void) {
  set_bc(mem_read16(0x84AF));
  p26_L_6EB9();
  return;
}

/* flash page 26 cpu 0x6EB9 (offset 0x2EB9) */
void p26_L_6EB9(void) {
  p00_L_3E67();
  p26_L_6EBC();
  return;
}

/* flash page 26 cpu 0x6EBC (offset 0x2EBC) */
void p26_L_6EBC(void) {
  cpu_push_hl();
  p00_L_1229();
  p26_L_6ECF();
  cpu_pop_hl();
  if (flag_z()) return;
  set_de(mem_read16(0x84DB));
  p00_L_3AF5();
  p00_L_1873();
  return;
}

/* flash page 26 cpu 0x6ECF (offset 0x2ECF) */
void p26_L_6ECF(void) {
  a = mem_read8(0x84DC);
  a = a | a;
  flag_logic(a);
  return;
}

/* flash page 26 cpu 0x6ED4 (offset 0x2ED4) */
void p26_L_6ED4(void) {
  set_hl(mem_read16(0x84D3));
  set_de(mem_read16(0x84D5));
  mem_write16(0x84D3, de());
  mem_write16(0x84D5, hl());
  return;
}

/* flash page 26 cpu 0x6EE3 (offset 0x2EE3) */
void p26_L_6EE3(void) {
  p26_L_6ED4();
  p26_L_6EF2();
  a = 0x0A;
  p00_L_1897();
  a = 0x0B;
  goto lab_p26_L_6F4B;
  lab_p26_L_6F4B: ;
  p00_L_113A();
  p00_L_1897();
  return;
}

/* flash page 26 cpu 0x6EF2 (offset 0x2EF2) */
void p26_L_6EF2(void) {
  set_hl(mem_read16(0x84D3));
  e = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  d = mem_read8(hl());
  mem_write16(0x84AF, de());
  /* scf */
  cpu_push_af();
  lab_p26_L_6EFE: ;
  set_hl(mem_read16(0x84AF));
  p26_L_6EBC();
  p00_L_14C7();
  if (flag_z()) goto lab_p26_L_6F32;
  p00_L_3AEF();
  cpu_pop_af();
  if (flag_nc()) goto lab_p26_L_6F19;
  a = 0;
  flag_logic(a);
  cpu_push_af();
  p00_L_10DD();
  p00_L_1171();
  goto lab_p26_L_6F32;
  lab_p26_L_6F19: ;
  cpu_push_af();
  p00_L_1100();
  p00_L_10EF();
  p00_L_107E();
  if (flag_c()) p00_L_10D4();
  p00_L_10F8();
  p00_L_113A();
  p00_L_107E();
  if (flag_c()) p00_L_1151();
  lab_p26_L_6F32: ;
  set_hl(mem_read16(0x84AF));
  set_hl((uint16_t)(hl() - 1));
  mem_write16(0x84AF, hl());
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_6EFE;
  cpu_pop_af();
  p00_L_1135();
  return;
}

/* flash page 26 cpu 0x6F41 (offset 0x2F41) */
void p26_L_6F41(void) {
  p26_L_6EF2();
  a = 0x08;
  p00_L_1897();
  a = 0x09;
  p00_L_113A();
  p00_L_1897();
  return;
}

/* flash page 26 cpu 0x7186 (offset 0x3186) */
void p26_L_7186(void) {
  p00_L_22F7();
  a = 0;
  flag_logic(a);
  goto lab_p26_L_718E;
  lab_p26_L_718E: ;
  cpu_push_af();
  p00_rst18();
  p00_L_3B73();
  set_hl(0x84B0);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_L_0D1F();
  p00_L_2196();
  cpu_pop_af();
  if (flag_z()) { p00_L_0C13(); return; }
  p00_rst30();
  return;
}

/* flash page 26 cpu 0x718C (offset 0x318C) */
void p26_L_718C(void) {
  a = a | 0x01;
  flag_logic(a);
  cpu_push_af();
  p00_rst18();
  p00_L_3B73();
  set_hl(0x84B0);
  mem_write8(hl(), (uint8_t)(mem_read8(hl()) + 1));
  p00_L_0D1F();
  p00_L_2196();
  cpu_pop_af();
  if (flag_z()) { p00_L_0C13(); return; }
  p00_rst30();
  return;
}

/* flash page 26 cpu 0x71A3 (offset 0x31A3) */
void p26_L_71A3(void) {
  cpu_push_de();
  p00_L_22FC();
  p00_L_0D1F();
  p00_rst18();
  p00_L_28B0();
  cpu_pop_de();
  p26_L_71D0();
  cpu_push_de();
  p00_L_2893();
  cpu_pop_de();
  p26_L_71D0();
  cpu_push_de();
  p00_L_28FD();
  cpu_pop_de();
  p26_L_71D0();
  cpu_push_de();
  p00_L_28E0();
  cpu_pop_de();
  p26_L_71D0();
  cpu_push_de();
  p00_L_21A7();
  cpu_pop_de();
  return;
}

/* flash page 26 cpu 0x71D0 (offset 0x31D0) */
void p26_L_71D0(void) {
  cpu_push_de();
  p00_L_22FC();
  p00_L_0D1F();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_0C20();
  cpu_pop_de();
  p00_L_11FD();
  return;
}

/* flash page 26 cpu 0x71E9 (offset 0x31E9) */
void p26_L_71E9(void) {
  p00_rst18();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 2)) == 0);
  if (flag_z()) p00_L_3E5B();
  p00_L_219B();
  return;
}

/* flash page 26 cpu 0x71F4 (offset 0x31F4) */
void p26_L_71F4(void) {
  set_hl((uint16_t)(hl() + bc()));
  cpu_push_hl();
  p00_L_1691();
  cpu_pop_hl();
  p00_L_1CA8();
  set_de((uint16_t)(de() + 1));
  set_de((uint16_t)(de() + 1));
  return;
}

/* flash page 26 cpu 0x723D (offset 0x323D) */
void p26_L_723D(void) {
  goto lab_p26_L_723D;
  lab_p26_L_7200: ;
  a = 0x03;
  p26_L_73B0();
  set_bc(0xFFFD);
  p26_L_71F4();
  a = 0x18;
  p26_L_743B();
  a = 0x83;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  a = 0x10;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  a = 0x31;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  a = 0x70;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  p26_L_7439();
  a = 0xBF;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  a = 0xB0;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  a = 0x17;
  p26_L_743B();
  p26_L_741E();
  a = 0x11;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  a = 0x11;
  mem_write8(de(), a);
  p26_L_72E2();
  return;
  lab_p26_L_723D: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x09)) & (1u << 5)) == 0);
  if (flag_nz()) return;
  a = mem_read8(0x8A36);
  flag_cmp(a, 0x09);
  if (flag_z()) return;
  set_hl(0x73AA);
  p00_L_25A2();
  flag_cmp(a, 0x08);
  if (flag_z()) goto lab_p26_L_7262;
  flag_cmp(a, 0x1C);
  if (flag_z()) goto lab_p26_L_73CF;
  flag_cmp(a, 0x19);
  if (flag_z()) goto lab_p26_L_7262;
  if (flag_nc()) goto lab_p26_L_7200;
  flag_cmp(a, 0x05);
  if (flag_nc()) goto lab_p26_L_736C;
  lab_p26_L_7262: ;
  p26_L_742B();
  cpu_push_bc();
  a = 0x17;
  p26_L_742D();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + bc()));
  set_bc(0x0002);
  a = mem_read8(0x8A36);
  a = a | a;
  flag_logic(a);
  if (flag_z()) goto lab_p26_L_7284;
  flag_cmp(a, 0x03);
  if (flag_z()) goto lab_p26_L_7284;
  flag_cmp(a, 0x04);
  if (flag_nc()) goto lab_p26_L_7284;
  set_bc((uint16_t)(bc() + 1));
  flag_cmp(a, 0x02);
  if (flag_nz()) goto lab_p26_L_7284;
  set_bc((uint16_t)(bc() + 1));
  lab_p26_L_7284: ;
  p26_L_71F4();
  p26_L_7439();
  cpu_push_de();
  a = 0x17;
  p26_L_742D();
  cpu_pop_de();
  a = mem_read8(0x8A36);
  flag_cmp(a, 0x19);
  if (flag_z()) goto lab_p26_L_72AC;
  flag_cmp(a, 0x03);
  cpu_push_af();
  if (flag_c()) goto lab_p26_L_72AC;
  p26_L_741E();
  cpu_pop_af();
  if (flag_nz()) goto lab_p26_L_72AC;
  a = 0xF0;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  p26_L_7440();
  p26_L_72E2();
  return;
  lab_p26_L_72AC: ;
  flag_cmp(a, 0x01);
  a = 0x70;
  if (flag_nz()) goto lab_p26_L_72B4;
  a = 0x82;
  lab_p26_L_72B4: ;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  p26_L_7440();
  a = mem_read8(0x8A36);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_72C4;
  lab_p26_L_72BF: ;
  p26_L_741E();
  p26_L_72E2();
  return;
  lab_p26_L_72C4: ;
  flag_cmp(a, 0x19);
  if (flag_z()) goto lab_p26_L_72BF;
  flag_cmp(a, 0x04);
  if (flag_nc()) { p26_L_72E2(); return; }
  a = (uint8_t)(a - 1);
  a = 0xBE;
  if (flag_nz()) goto lab_p26_L_72D3;
  a = 0xF0;
  lab_p26_L_72D3: ;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  p26_L_741E();
  a = mem_read8(0x8A36);
  flag_cmp(a, 0x02);
  if (flag_nz()) { p26_L_72E2(); return; }
  a = 0x11;
  mem_write8(de(), a);
  p26_L_72E2();
  return;
  lab_p26_L_736C: ;
  a = (uint8_t)(a - 0x02);
  p26_L_73B0();
  set_bc(0xFFFA);
  p26_L_71F4();
  a = mem_read8(0x8A36);
  a = (uint8_t)(a - 0x02);
  cpu_push_af();
  set_hl(0x73CE);
  lab_p26_L_7380: ;
  cpu_push_de();
  a = mem_read8(hl());
  cpu_push_hl();
  p26_L_742D();
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_hl();
  p26_L_7440();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  cpu_pop_bc();
  b = (uint8_t)(b - 1);
  if (flag_z()) { p26_L_72E2(); return; }
  p26_L_741E();
  cpu_ex_de_hl();
  a = b;
  a = (uint8_t)(a - 1);
  if (flag_z()) goto lab_p26_L_73A3;
  mem_write8(hl(), 0xF0);
  set_hl((uint16_t)(hl() + 1));
  a = b;
  a = (uint8_t)(a + 0x30);
  mem_write8(hl(), a);
  set_hl((uint16_t)(hl() + 1));
  lab_p26_L_73A3: ;
  mem_write8(hl(), 0x70);
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  cpu_push_bc();
  goto lab_p26_L_7380;
  lab_p26_L_73CF: ;
  a = 0x04;
  p26_L_73B0();
  set_bc(0xFFF6);
  p26_L_71F4();
  p26_L_7439();
  cpu_ex_de_hl();
  mem_write8(hl(), 0x82);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0xC2);
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  a = 0x17;
  p26_L_743B();
  p26_L_741E();
  a = 0x70;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  a = 0x18;
  p26_L_743B();
  cpu_ex_de_hl();
  mem_write8(hl(), 0x11);
  set_hl((uint16_t)(hl() + 1));
  mem_write8(hl(), 0x70);
  set_hl((uint16_t)(hl() + 1));
  cpu_ex_de_hl();
  a = 0x19;
  p26_L_743B();
  p26_L_72E2();
  return;
}

/* flash page 26 cpu 0x72E2 (offset 0x32E2) */
void p26_L_72E2(void) {
  p26_L_740A();
  cpu_ex_de_hl();
  p00_L_0033();
  cpu_push_hl();
  p26_L_7363();
  cpu_pop_hl();
  mem_write16(0x84AF, hl());
  p00_L_1C46();
  set_hl(0x735D);
  p00_L_25A2();
  p00_L_16A2();
  p00_rst10();
  cpu_push_af();
  p00_L_128A();
  cpu_pop_af();
  if (flag_c()) p00_L_3321();
  p00_L_38F1();
  p00_L_2222();
  set_hl(mem_read16(0x84AF));
  cpu_push_hl();
  set_hl(0x0001);
  lab_p26_L_7313: ;
  cpu_push_hl();
  p26_L_740A();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_3AF5();
  p00_L_3321();
  p00_L_1691();
  p00_L_36D5();
  p00_rst08();
  set_hl(0x8D2F);
  p26_L_740D();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_3AF5();
  p00_L_0C2D();
  p00_rst08();
  set_hl(0x7423);
  p00_rst20();
  p00_rst10();
  cpu_push_de();
  p00_L_1179();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_3B19();
  cpu_pop_hl();
  cpu_pop_de();
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  if (flag_z()) goto lab_p26_L_7350;
  set_hl((uint16_t)(hl() + de()));
  cpu_push_de();
  set_hl((uint16_t)(hl() + 1));
  goto lab_p26_L_7313;
  lab_p26_L_7350: ;
  p00_L_2176();
  p00_L_3321();
  p00_L_25C8();
  p00_L_25C8();
  return;
}

/* flash page 26 cpu 0x7363 (offset 0x3363) */
void p26_L_7363(void) {
  set_hl(0x7423);
  p00_rst20();
  p00_rst10();
  if (flag_nc()) p00_L_1F58();
  return;
}

/* flash page 26 cpu 0x73B0 (offset 0x33B0) */
void p26_L_73B0(void) {
  set_hl(0x0000);
  set_de(0x73CE);
  lab_p26_L_73B6: ;
  cpu_push_af();
  cpu_push_de();
  cpu_push_hl();
  a = mem_read8(de());
  p26_L_742D();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() + bc()));
  set_bc(0x0004);
  set_hl((uint16_t)(hl() + bc()));
  cpu_pop_de();
  set_de((uint16_t)(de() - 1));
  cpu_pop_af();
  a = (uint8_t)(a - 1);
  if (flag_nz()) goto lab_p26_L_73B6;
  return;
}

/* flash page 26 cpu 0x740A (offset 0x340A) */
void p26_L_740A(void) {
  set_hl(0x8D2A);
  p26_L_740D();
  return;
}

/* flash page 26 cpu 0x740D (offset 0x340D) */
void p26_L_740D(void) {
  set_de(0x8479);
  a = 0x5D;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  p00_L_118B();
  cpu_ex_de_hl();
  mem_write8(hl(), 0x00);
  p00_L_2429();
  return;
}

/* flash page 26 cpu 0x741E (offset 0x341E) */
void p26_L_741E(void) {
  a = 0x58;
  mem_write8(de(), a);
  set_de((uint16_t)(de() + 1));
  return;
}

/* flash page 26 cpu 0x742B (offset 0x342B) */
void p26_L_742B(void) {
  a = 0x16;
  p26_L_742D();
  return;
}

/* flash page 26 cpu 0x742D (offset 0x342D) */
void p26_L_742D(void) {
  p00_L_18A3();
  p00_L_39CF();
  a = 0x15;
  p00_L_32A3();
  return;
}

/* flash page 26 cpu 0x7439 (offset 0x3439) */
void p26_L_7439(void) {
  a = 0x16;
  p26_L_743B();
  return;
}

/* flash page 26 cpu 0x743B (offset 0x343B) */
void p26_L_743B(void) {
  cpu_push_de();
  p26_L_742D();
  cpu_pop_de();
  p26_L_7440();
  return;
}

/* flash page 26 cpu 0x7440 (offset 0x3440) */
void p26_L_7440(void) {
  set_hl(0x848E);
  while (bc() != 0) { cpu_ldi(); }
  return;
}

/* flash page 26 cpu 0x7446 (offset 0x3446) */
void p26_L_7446(void) {
  mem_write8((uint16_t)(iy + 0x19), (uint8_t)(mem_read8((uint16_t)(iy + 0x19)) | (1u << 5)));
  set_hl(mem_read16(0x84D5));
  mem_write16(0x84DB, hl());
  /* res 1,(iy) */
  cpu_push_de();
  a = 0;
  flag_logic(a);
  /* scf */
  p00_L_3999();
  p00_L_222C();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p26_L_7475;
  set_hl(0x8483);
  set_de(0x8A3A);
  p00_L_1183();
  p00_L_11FD();
  set_hl(0x84A4);
  p00_L_1183();
  lab_p26_L_7475: ;
  p00_L_128A();
  cpu_pop_hl();
  lab_p26_L_7479: ;
  mem_write16(0x84AF, hl());
  p00_L_1171();
  p00_L_3AFB();
  p00_L_2315();
  p00_L_0C13();
  p00_L_0D1E();
  p26_L_64AD();
  p00_L_1108();
  p00_rst30();
  set_hl(mem_read16(0x84AF));
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_7479;
  p00_L_1171();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 5)) == 0);
  if (flag_nz()) goto lab_p26_L_74B1;
  set_hl(0x8A3A);
  p00_L_0EC1();
  p00_L_3A05();
  a = 0x07;
  p00_L_1897();
  lab_p26_L_74B1: ;
  /* bit 1,(iy) */
  if (flag_nz()) goto lab_p26_L_74DD;
  p00_L_22FC();
  p00_L_1251();
  p00_L_107E();
  if (flag_z()) goto lab_p26_L_74DD;
  if (flag_c()) goto lab_p26_L_74DD;
  p00_L_0C2D();
  p00_rst08();
  p00_L_113A();
  p00_L_0ED0();
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 5)) == 0);
  if (flag_nz()) { p00_L_21A4(); return; }
  p00_L_3A05();
  a = 0x06;
  p00_L_1897();
  lab_p26_L_74DD: ;
  flag_set_z((mem_read8((uint16_t)(iy + 0x19)) & (1u << 5)) == 0);
  if (flag_nz()) { p00_L_24C9(); return; }
  set_hl(0x8A43);
  p00_rst20();
  p00_L_0D1E();
  set_hl(0x8A3A);
  p00_L_0D19();
  p00_L_1108();
  p00_rst30();
  a = 0x05;
  p00_L_1897();
  p00_L_21A4();
  flag_set_z((mem_read8((uint16_t)(iy + 0x1A)) & (1u << 2)) == 0);
  if (flag_nz()) return;
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 3)));
  mem_write8((uint16_t)(iy + 0x16), (uint8_t)(mem_read8((uint16_t)(iy + 0x16)) & ~(1u << 4)));
  mem_write8((uint16_t)(iy + 0x14), (uint8_t)(mem_read8((uint16_t)(iy + 0x14)) & ~(1u << 6)));
  p26_L_7548();
  p00_L_1295();
  a = 0x26;
  mem_write8(0x8479, a);
  p00_rst10();
  if (flag_nc()) p00_L_1F58();
  p26_L_751D();
  return;
}

/* flash page 26 cpu 0x751D (offset 0x351D) */
void p26_L_751D(void) {
  p00_L_219B();
  a = 0x15;
  p00_L_1897();
  p00_L_219B();
  a = 0x14;
  p00_L_1897();
  p00_L_219B();
  a = 0x13;
  p00_L_1897();
  p00_L_219B();
  a = 0x09;
  p00_L_1897();
  p00_L_219B();
  a = 0x08;
  p00_L_1897();
  p00_L_21A7();
  return;
}

/* flash page 26 cpu 0x7548 (offset 0x3548) */
void p26_L_7548(void) {
  p26_L_786E();
  cpu_push_hl();
  set_de(0x0001);
  p00_L_35CD();
  p00_rst18();
  set_bc(0x0001);
  p00_L_18BC();
  p00_rst18();
  cpu_pop_bc();
  cpu_push_bc();
  p00_L_18BC();
  p00_rst18();
  cpu_pop_hl();
  cpu_push_hl();
  set_de(0x0001);
  p26_L_7799();
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 4)) == 0);
  if (flag_z()) goto lab_p26_L_7575;
  cpu_pop_af();
  p00_L_21A4();
  p00_L_21AA();
  return;
  lab_p26_L_7575: ;
  cpu_pop_bc();
  cpu_push_bc();
  mem_write16(0x84B3, bc());
  cpu_push_de();
  cpu_push_hl();
  p00_rst18();
  p00_L_222C();
  p00_L_221D();
  p00_L_21D1();
  p00_L_2277();
  /* bit 1,(iy) */
  if (flag_nz()) goto lab_p26_L_7651;
  p26_L_6EB5();
  p00_rst18();
  p00_L_22CF();
  p00_L_0D16();
  p00_rst18();
  p00_L_16B5();
  set_hl(0x785D);
  p00_L_25A2();
  set_hl(mem_read16(0x84B3));
  cpu_push_hl();
  set_hl(mem_read16(0x84B1));
  cpu_push_hl();
  set_hl(mem_read16(0x84AF));
  cpu_push_hl();
  p00_L_0BF9();
  p00_rst08();
  p00_L_22CF();
  p00_L_107E();
  if (flag_nc()) goto lab_p26_L_75D6;
  p00_L_0C13();
  p26_L_7749();
  cpu_pop_hl();
  cpu_push_hl();
  set_de(0x0001);
  p26_L_7799();
  p00_L_2393();
  p00_L_2315();
  p26_L_7749();
  goto lab_p26_L_75EC;
  lab_p26_L_75D6: ;
  p00_L_14C7();
  cpu_push_af();
  p00_L_292F();
  cpu_pop_af();
  if (flag_z()) goto lab_p26_L_75E9;
  set_hl(mem_read16(0x84B1));
  set_de(0x0001);
  p26_L_7799();
  lab_p26_L_75E9: ;
  p00_L_2393();
  lab_p26_L_75EC: ;
  p00_L_22FC();
  p00_L_34B3();
  p00_L_231F();
  p00_L_107E();
  if (flag_nc()) goto lab_p26_L_7630;
  p00_L_0C13();
  p00_L_1100();
  p00_L_2310();
  p00_L_1229();
  p00_L_107E();
  if (flag_nc()) goto lab_p26_L_7628;
  p00_L_113F();
  p26_L_7749();
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  p26_L_7799();
  p00_L_23A4();
  p00_L_2315();
  p26_L_7749();
  p00_L_2267();
  goto lab_p26_L_764C;
  lab_p26_L_7628: ;
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  goto lab_p26_L_7646;
  lab_p26_L_7630: ;
  p00_L_22D9();
  p00_L_107E();
  cpu_push_af();
  p00_L_2928();
  cpu_pop_af();
  if (flag_c()) goto lab_p26_L_7649;
  if (flag_z()) goto lab_p26_L_7649;
  cpu_pop_de();
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_de();
  set_de((uint16_t)(de() + 1));
  lab_p26_L_7646: ;
  p26_L_7799();
  lab_p26_L_7649: ;
  p00_L_23A4();
  lab_p26_L_764C: ;
  p00_L_25C8();
  goto lab_p26_L_76B5;
  lab_p26_L_7651: ;
  cpu_pop_af();
  cpu_pop_af();
  set_hl(0x0000);
  mem_write16(0x84B7, hl());
  mem_write16(0x84AF, hl());
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  p00_L_1271();
  lab_p26_L_7661: ;
  p00_L_2324();
  set_hl(0x0FD5);
  p00_L_0D19();
  p00_rst08();
  p00_L_113A();
  p00_L_107E();
  if (flag_nc()) goto lab_p26_L_76A4;
  p00_L_1108();
  p26_L_7758();
  a = mem_read8(0x84B7);
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_7661;
  p00_L_2324();
  set_hl(0x0FCC);
  p00_L_0D19();
  p00_L_1108();
  p00_L_107E();
  cpu_push_af();
  p26_L_7866();
  cpu_pop_af();
  if (flag_c()) goto lab_p26_L_769A;
  if (flag_nz()) goto lab_p26_L_7661;
  p26_L_778C();
  lab_p26_L_769A: ;
  p00_L_23B3();
  a = 0x01;
  mem_write8(0x84B7, a);
  goto lab_p26_L_7661;
  lab_p26_L_76A4: ;
  cpu_pop_hl();
  cpu_push_af();
  p26_L_7866();
  cpu_pop_af();
  if (flag_z()) p26_L_778C();
  p00_L_2389();
  set_de(0x001B);
  goto lab_p26_L_76BA;
  lab_p26_L_76B5: ;
  cpu_pop_af();
  cpu_pop_af();
  set_de(0x002D);
  lab_p26_L_76BA: ;
  p00_L_21B6();
  p00_rst08();
  cpu_pop_bc();
  set_hl(0x0001);
  mem_write16(0x8478, hl());
  mem_write16(0x847A, bc());
  mem_write16(0x847C, bc());
  p26_L_76CD();
  return;
}

/* flash page 26 cpu 0x76CD (offset 0x36CD) */
void p26_L_76CD(void) {
  cpu_push_bc();
  p00_L_23A4();
  cpu_pop_bc();
  flag_set_z((mem_read8((uint16_t)(iy + 0x14)) & (1u << 6)) == 0);
  if (flag_z()) return;
  cpu_push_bc();
  p00_L_2315();
  p00_L_0C13();
  p00_L_1251();
  a = 0x15;
  mem_write8(0x8485, a);
  p00_L_0D1F();
  p00_rst18();
  p00_L_231F();
  p00_L_0C13();
  p00_L_2196();
  p00_L_23B3();
  p00_L_22FC();
  p00_rst30();
  p00_rst08();
  cpu_pop_bc();
  cpu_push_bc();
  lab_p26_L_76FD: ;
  cpu_push_bc();
  p00_L_18BC();
  p00_L_107E();
  cpu_pop_bc();
  if (flag_c()) goto lab_p26_L_7714;
  if (flag_z()) goto lab_p26_L_7714;
  set_bc((uint16_t)(bc() - 1));
  a = b;
  a = a | c;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_76FD;
  set_bc((uint16_t)(bc() + 1));
  cpu_push_bc();
  p00_L_1179();
  cpu_pop_bc();
  lab_p26_L_7714: ;
  mem_write16(0x84B1, bc());
  p00_L_2389();
  p00_L_22B3();
  set_bc(0x0001);
  lab_p26_L_7721: ;
  cpu_push_bc();
  p00_L_18BC();
  p00_L_107E();
  cpu_pop_bc();
  mem_write16(0x84AF, bc());
  cpu_pop_hl();
  if (flag_nc()) goto lab_p26_L_773D;
  a = a | a;
  flag_logic(a);
  cpu_push_hl();
  cpu_sbc_hl_bc();
  if (flag_z()) goto lab_p26_L_7739;
  set_bc((uint16_t)(bc() + 1));
  goto lab_p26_L_7721;
  lab_p26_L_7739: ;
  p00_L_1179();
  cpu_pop_hl();
  lab_p26_L_773D: ;
  mem_write16(0x84B3, hl());
  p00_L_23B3();
  p00_L_1130();
  p00_L_23A4();
  return;
}

/* flash page 26 cpu 0x7749 (offset 0x3749) */
void p26_L_7749(void) {
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_push_bc();
  cpu_push_hl();
  p00_L_3E67();
  set_de(mem_read16(0x84DB));
  p00_L_3B19();
  return;
}

/* flash page 26 cpu 0x7758 (offset 0x3758) */
void p26_L_7758(void) {
  cpu_pop_hl();
  mem_write16(0x84B5, hl());
  cpu_pop_hl();
  cpu_push_hl();
  p26_L_7853();
  p26_L_7866();
  p00_L_10DD();
  lab_p26_L_7767: ;
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_de();
  cpu_push_hl();
  p00_L_192A();
  if (flag_c()) goto lab_p26_L_7774;
  lab_p26_L_7770: ;
  set_hl(mem_read16(0x84B5));
  os_jp_hl();
  return;
  lab_p26_L_7774: ;
  cpu_pop_bc();
  set_bc((uint16_t)(bc() + 1));
  cpu_push_bc();
  p00_L_18BC();
  p00_L_10EF();
  p00_L_107E();
  if (flag_nz()) goto lab_p26_L_7770;
  p00_L_1108();
  cpu_pop_hl();
  cpu_push_hl();
  p26_L_7853();
  goto lab_p26_L_7767;
}

/* flash page 26 cpu 0x778C (offset 0x378C) */
void p26_L_778C(void) {
  p00_rst08();
  set_bc(mem_read16(0x84AF));
  set_bc((uint16_t)(bc() + 1));
  p00_L_18BC();
  p00_rst30();
  p00_L_0D16();
  return;
}

/* flash page 26 cpu 0x7799 (offset 0x3799) */
void p26_L_7799(void) {
  cpu_push_de();
  cpu_push_hl();
  cpu_push_de();
  set_de((uint16_t)(de() - 1));
  mem_write16(0x84AF, de());
  p00_L_1287();
  p00_L_21E0();
  lab_p26_L_77A7: ;
  cpu_pop_bc();
  cpu_push_bc();
  p26_L_6EB9();
  p00_rst30();
  p00_rst08();
  cpu_pop_de();
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_192A();
  set_de((uint16_t)(de() + 1));
  cpu_push_de();
  if (flag_nz()) goto lab_p26_L_77A7;
  cpu_pop_de();
  p00_rst18();
  p00_L_1271();
  /* bit 1,(iy) */
  if (flag_nz()) goto lab_p26_L_7809;
  lab_p26_L_77C3: ;
  p26_L_7834();
  if (flag_c()) goto lab_p26_L_77D1;
  if (flag_z()) p26_L_7843();
  set_hl((uint16_t)(hl() + 1));
  p26_L_7853();
  goto lab_p26_L_77C3;
  lab_p26_L_77D1: ;
  p00_L_22FC();
  p00_L_0C1B();
  p00_L_0D16();
  p00_L_0BF9();
  p00_L_2310();
  p00_L_107E();
  if (flag_nz()) goto lab_p26_L_77E6;
  /* scf */
  lab_p26_L_77E6: ;
  cpu_push_af();
  p26_L_7866();
  cpu_pop_af();
  if (flag_nc()) goto lab_p26_L_77F9;
  p00_rst08();
  set_bc(mem_read16(0x84B1));
  p00_L_18BC();
  p00_rst30();
  p00_L_0D16();
  lab_p26_L_77F9: ;
  p00_L_2191();
  p00_L_218C();
  cpu_pop_af();
  cpu_pop_af();
  set_hl(mem_read16(0x84AF));
  set_de(mem_read16(0x84B1));
  return;
  lab_p26_L_7809: ;
  set_hl(mem_read16(0x84AF));
  set_hl((uint16_t)(hl() + 1));
  cpu_push_hl();
  lab_p26_L_780E: ;
  p26_L_7834();
  if (flag_c()) goto lab_p26_L_781A;
  if (flag_z()) goto lab_p26_L_781A;
  p26_L_7758();
  goto lab_p26_L_780E;
  lab_p26_L_781A: ;
  cpu_pop_hl();
  p00_L_113A();
  p00_L_0C18();
  p00_rst08();
  p00_L_22FC();
  p00_L_107E();
  cpu_push_af();
  p26_L_7866();
  cpu_pop_af();
  if (flag_c()) goto lab_p26_L_77F9;
  p26_L_778C();
  goto lab_p26_L_77F9;
}

/* flash page 26 cpu 0x7834 (offset 0x3834) */
void p26_L_7834(void) {
  p00_L_113A();
  p00_L_0C18();
  p00_rst08();
  p00_L_22FC();
  p00_L_107E();
  if (flag_c()) return;
  if (flag_z()) return;
  p26_L_7843();
  return;
}

/* flash page 26 cpu 0x7843 (offset 0x3843) */
void p26_L_7843(void) {
  p00_L_1108();
  p00_L_2357();
  set_hl(mem_read16(0x84AF));
  mem_write16(0x84B1, hl());
  a = 0;
  flag_logic(a);
  a = a | 0x01;
  flag_logic(a);
  return;
}

/* flash page 26 cpu 0x7853 (offset 0x3853) */
void p26_L_7853(void) {
  mem_write16(0x84AF, hl());
  p26_L_6EB5();
  p00_rst30();
  p00_L_1171();
  return;
}

/* flash page 26 cpu 0x7866 (offset 0x3866) */
void p26_L_7866(void) {
  set_bc(mem_read16(0x84AF));
  p00_L_18BC();
  return;
}

/* flash page 26 cpu 0x786E (offset 0x386E) */
void p26_L_786E(void) {
  /* res 1,(iy) */
  a = 0;
  flag_logic(a);
  set_bc(0x0000);
  lab_p26_L_7876: ;
  cpu_push_af();
  cpu_push_bc();
  p00_L_127B();
  set_hl(mem_read16(0x84D3));
  p00_L_0033();
  lab_p26_L_7881: ;
  cpu_push_hl();
  p26_L_6EBC();
  p00_L_14C7();
  if (flag_z()) goto lab_p26_L_78AA;
  p00_L_14E1();
  if (flag_z()) goto lab_p26_L_7893;
  /* set 1,(iy) */
  lab_p26_L_7893: ;
  cpu_pop_hl();
  cpu_pop_bc();
  cpu_pop_af();
  cpu_push_af();
  if (flag_nz()) goto lab_p26_L_789D;
  set_bc((uint16_t)(bc() + 1));
  cpu_push_bc();
  goto lab_p26_L_78AB;
  lab_p26_L_789D: ;
  set_bc((uint16_t)(bc() - 1));
  cpu_push_bc();
  cpu_push_hl();
  p00_L_35C7();
  p00_L_10F8();
  p00_rst30();
  p00_L_1100();
  lab_p26_L_78AA: ;
  cpu_pop_hl();
  lab_p26_L_78AB: ;
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_7881;
  cpu_pop_bc();
  cpu_pop_af();
  if (flag_nz()) goto lab_p26_L_78E2;
  cpu_push_bc();
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 4)) == 0);
  if (flag_nz()) goto lab_p26_L_78EC;
  p00_L_1295();
  a = 0;
  flag_logic(a);
  flag_set_z((mem_read8((uint16_t)(iy + 0x16)) & (1u << 3)) == 0);
  if (flag_z()) goto lab_p26_L_78C8;
  a = mem_read8(0x8E63);
  lab_p26_L_78C8: ;
  a = (uint8_t)(a + 0x26);
  mem_write8(0x8479, a);
  p00_rst10();
  if (flag_nc()) p00_L_1F58();
  cpu_pop_hl();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + hl()));
  p00_L_1C8F();
  lab_p26_L_78D7: ;
  mem_write16(0x84D9, de());
  cpu_pop_bc();
  cpu_push_bc();
  set_bc((uint16_t)(bc() + 1));
  a = a | 0x01;
  flag_logic(a);
  goto lab_p26_L_7876;
  lab_p26_L_78E2: ;
  p00_L_113F();
  cpu_pop_hl();
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) { p00_L_2515(); return; }
  return;
  lab_p26_L_78EC: ;
  cpu_pop_hl();
  cpu_push_hl();
  set_hl((uint16_t)(hl() + hl()));
  p00_L_1C89();
  cpu_push_de();
  p00_L_21D6();
  cpu_pop_de();
  goto lab_p26_L_78D7;
}

/* flash page 26 cpu 0x78F9 (offset 0x38F9) */
void p26_L_78F9(void) {
  p26_L_786E();
  set_de(0x0003);
  p00_L_192A();
  if (flag_c()) { p00_L_2515(); return; }
  cpu_push_hl();
  p00_rst18();
  cpu_pop_hl();
  cpu_push_hl();
  set_de(0x0001);
  p00_L_35CD();
  p00_L_1271();
  cpu_pop_de();
  cpu_push_de();
  set_hl(0x0001);
  p26_L_7A70();
  cpu_push_hl();
  set_hl(0x0000);
  mem_write16(0x84B1, hl());
  p00_L_128A();
  p00_rst18();
  lab_p26_L_7925: ;
  p00_L_113A();
  p00_L_1221();
  p00_L_0D1F();
  p00_L_2310();
  p00_L_107E();
  if (flag_nc()) goto lab_p26_L_794B;
  p00_L_113A();
  p00_L_233D();
  set_hl(mem_read16(0x84AF));
  mem_write16(0x84B1, hl());
  cpu_pop_hl();
  cpu_pop_de();
  cpu_push_de();
  p26_L_7A70();
  cpu_push_hl();
  goto lab_p26_L_7925;
  lab_p26_L_794B: ;
  cpu_pop_hl();
  p26_L_7AAE();
  mem_write16(0x84B3, hl());
  p00_L_1271();
  cpu_pop_hl();
  cpu_push_hl();
  mem_write16(0x84AF, hl());
  p26_L_7A8C();
  cpu_push_hl();
  set_hl(0x0000);
  mem_write16(0x84B1, hl());
  p00_L_128A();
  p00_L_233D();
  lab_p26_L_796A: ;
  p00_L_113A();
  p00_L_1221();
  p00_L_0D1F();
  p00_L_2310();
  p00_L_107E();
  if (flag_nc()) goto lab_p26_L_798E;
  p00_L_113A();
  p00_L_233D();
  set_hl(mem_read16(0x84AF));
  mem_write16(0x84B1, hl());
  cpu_pop_hl();
  p26_L_7A8C();
  cpu_push_hl();
  goto lab_p26_L_796A;
  lab_p26_L_798E: ;
  cpu_pop_hl();
  p26_L_7AAE();
  mem_write16(0x84B5, hl());
  set_de(mem_read16(0x84B3));
  a = a | a;
  flag_logic(a);
  cpu_sbc_hl_de();
  lab_p26_L_799C: ;
  if (flag_c()) { p00_L_2515(); return; }
  set_de(0x0002);
  cpu_sbc_hl_de();
  if (flag_c()) goto lab_p26_L_799C;
  p00_L_21CC();
  a = 0x1B;
  p26_L_7A48();
  a = 0x1C;
  p26_L_7A59();
  a = 0x1D;
  p26_L_7A65();
  p26_L_6ED4();
  set_hl(mem_read16(0x84B3));
  set_de(0x0001);
  p00_L_35CD();
  p00_L_22E8();
  a = 0x1E;
  p26_L_7A48();
  set_de(mem_read16(0x84B3));
  set_de((uint16_t)(de() + 1));
  set_hl(mem_read16(0x84B5));
  set_hl((uint16_t)(hl() - 1));
  p00_L_35CD();
  p00_L_22E8();
  a = 0x1F;
  p26_L_7A59();
  set_de(mem_read16(0x84B5));
  cpu_pop_hl();
  cpu_push_hl();
  p00_L_35CD();
  p00_L_22E8();
  a = 0x20;
  p26_L_7A65();
  set_hl(0x8B36);
  p00_L_0C25();
  p00_L_1100();
  set_hl(0x8B2D);
  p00_rst20();
  set_hl(0x8B1B);
  p00_L_0C25();
  p00_rst08();
  p00_L_113F();
  p00_L_0ED0();
  a = 0x16;
  p00_L_1897();
  set_hl(0x8B1B);
  p26_L_7A3E();
  set_hl(0x8AEE);
  p00_L_0D19();
  p00_rst18();
  set_hl(0x8B36);
  p26_L_7A3E();
  p00_L_2196();
  p00_L_0C2D();
  p00_L_1221();
  p00_L_0ED0();
  a = 0x17;
  p00_L_1897();
  p26_L_6ED4();
  cpu_pop_hl();
  p00_L_21A7();
  p00_L_21A4();
  return;
}

/* flash page 26 cpu 0x7A3E (offset 0x3A3E) */
void p26_L_7A3E(void) {
  p00_rst20();
  p00_L_11F8();
  cpu_push_hl();
  p00_rst30();
  cpu_pop_hl();
  p00_L_0C20();
  return;
}

/* flash page 26 cpu 0x7A48 (offset 0x3A48) */
void p26_L_7A48(void) {
  cpu_push_af();
  set_hl(mem_read16(0x84B3));
  set_de(0x0001);
  p26_L_7799();
  cpu_pop_af();
  p00_L_1897();
  p00_L_22E8();
  return;
}

/* flash page 26 cpu 0x7A59 (offset 0x3A59) */
void p26_L_7A59(void) {
  goto lab_p26_L_7A59;
  lab_p26_L_7A4F: ;
  p26_L_7799();
  cpu_pop_af();
  p00_L_1897();
  p00_L_22E8();
  return;
  lab_p26_L_7A59: ;
  cpu_push_af();
  set_de(mem_read16(0x84B3));
  set_de((uint16_t)(de() + 1));
  set_hl(mem_read16(0x84B5));
  set_hl((uint16_t)(hl() - 1));
  goto lab_p26_L_7A4F;
}

/* flash page 26 cpu 0x7A65 (offset 0x3A65) */
void p26_L_7A65(void) {
  goto lab_p26_L_7A65;
  lab_p26_L_7A4F: ;
  p26_L_7799();
  cpu_pop_af();
  p00_L_1897();
  p00_L_22E8();
  return;
  lab_p26_L_7A65: ;
  set_de(mem_read16(0x84B5));
  cpu_pop_bc();
  cpu_pop_hl();
  cpu_push_hl();
  cpu_push_bc();
  cpu_push_af();
  goto lab_p26_L_7A4F;
}

/* flash page 26 cpu 0x7A70 (offset 0x3A70) */
void p26_L_7A70(void) {
  lab_p26_L_7A70: ;
  cpu_push_de();
  cpu_push_hl();
  p00_L_1108();
  cpu_pop_hl();
  cpu_push_hl();
  p26_L_7853();
  cpu_pop_de();
  set_de((uint16_t)(de() + 1));
  cpu_pop_hl();
  p00_L_192A();
  cpu_ex_de_hl();
  if (flag_c()) return;
  cpu_push_de();
  cpu_push_hl();
  p26_L_7AA2();
  cpu_pop_hl();
  cpu_pop_de();
  if (flag_z()) goto lab_p26_L_7A70;
  return;
}

/* flash page 26 cpu 0x7A8C (offset 0x3A8C) */
void p26_L_7A8C(void) {
  lab_p26_L_7A8C: ;
  cpu_push_hl();
  p00_L_1108();
  cpu_pop_hl();
  cpu_push_hl();
  p26_L_7853();
  cpu_pop_hl();
  set_hl((uint16_t)(hl() - 1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) return;
  cpu_push_hl();
  p26_L_7AA2();
  cpu_pop_hl();
  if (flag_z()) goto lab_p26_L_7A8C;
  return;
}

/* flash page 26 cpu 0x7AA2 (offset 0x3AA2) */
void p26_L_7AA2(void) {
  cpu_push_hl();
  p26_L_7866();
  p00_rst08();
  cpu_pop_bc();
  p00_L_18BC();
  p00_L_107E();
  return;
}

/* flash page 26 cpu 0x7AAE (offset 0x3AAE) */
void p26_L_7AAE(void) {
  set_hl(mem_read16(0x84B1));
  a = h;
  a = a | l;
  flag_logic(a);
  if (flag_z()) goto lab_p26_L_7AD6;
  p00_L_113A();
  p00_L_22F7();
  p00_rst30();
  p00_L_1221();
  p00_L_0D1F();
  p00_rst18();
  p00_L_2324();
  p00_L_0C18();
  p00_rst08();
  p00_L_219B();
  p00_L_107E();
  if (flag_c()) goto lab_p26_L_7AD6;
  set_hl(mem_read16(0x84B1));
  if (flag_nz()) return;
  lab_p26_L_7AD6: ;
  set_hl(mem_read16(0x84AF));
  return;
}

/* flash page 26 cpu 0x7ADA (offset 0x3ADA) */
void p26_L_7ADA(void) {
  cpu_push_bc();
  set_hl(0x7E47);
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_z()) goto lab_p26_L_7AED;
  b = a;
  a = 0x47;
  p00_L_3C45();
  if (flag_z()) goto lab_p26_L_7AF0;
  a = b;
  lab_p26_L_7AED: ;
  p26_L_7E41();
  lab_p26_L_7AF0: ;
  p26_L_7B9B();
  p00_L_3D1D();
  cpu_pop_af();
  a = a | a;
  flag_logic(a);
  if (flag_nz()) goto lab_p26_L_7B5F;
  a = mem_read8(0x8A36);
  flag_cmp(a, 0x0B);
  if (flag_c()) goto lab_p26_L_7B9A;
  set_hl(0x7DEC);
  flag_cmp(a, 0x0D);
  if (flag_c()) goto lab_p26_L_7B28;
  set_hl(0x7DF2);
  flag_cmp(a, 0x0F);
  if (flag_c()) goto lab_p26_L_7B23;
  set_hl(0x7DF8);
  if (flag_z()) goto lab_p26_L_7B2F;
  set_hl(0x7DFE);
  flag_cmp(a, 0x10);
  if (flag_z()) goto lab_p26_L_7B23;
  set_hl(0x7E04);
  flag_cmp(a, 0x12);
  if (flag_nz()) goto lab_p26_L_7B4F;
  lab_p26_L_7B23: ;
  p26_L_7E3E();
  goto lab_p26_L_7B65;
  lab_p26_L_7B28: ;
  p26_L_7B45();
  a = 0x0D;
  goto lab_p26_L_7B34;
  lab_p26_L_7B2F: ;
  p26_L_7B45();
  a = 0x06;
  lab_p26_L_7B34: ;
  cpu_push_af();
  set_hl(0x8D8F);
  p00_rst20();
  cpu_pop_af();
  p00_L_326D();
  set_hl(0x848E);
  p00_L_3C87();
  goto lab_p26_L_7B9A;
  lab_p26_L_7B4F: ;
  flag_cmp(a, 0x13);
  if (flag_c()) goto lab_p26_L_7B9A;
  flag_cmp(a, 0x1B);
  if (flag_z()) goto lab_p26_L_7B9A;
  p00_L_3045();
  set_hl(0x97B1);
  goto lab_p26_L_7B65;
  lab_p26_L_7B5F: ;
  set_hl(0x7E47);
  p26_L_7E41();
  lab_p26_L_7B65: ;
  a = 0x02;
  set_de(0x0101);
  p26_L_7BA0();
  p00_L_3D1D();
  a = mem_read8(0x8A36);
  flag_cmp(a, 0x19);
  if (flag_nz()) goto lab_p26_L_7B9A;
  p00_L_17CE();
  if (flag_z()) goto lab_p26_L_7B89;
  set_hl(0x7E10);
  p26_L_7E3E();
  a = 0x02;
  set_de(0x0701);
  goto lab_p26_L_7B94;
  lab_p26_L_7B89: ;
  set_hl(0x7E0A);
  p26_L_7E3E();
  a = 0x03;
  set_de(0x0102);
  lab_p26_L_7B94: ;
  p26_L_7BA0();
  p00_L_3D1D();
  lab_p26_L_7B9A: ;
  return;
}

/* flash page 26 cpu 0x7B45 (offset 0x3B45) */
void p26_L_7B45(void) {
  p26_L_7E3E();
  a = 0x02;
  set_de(0x0101);
  p26_L_7BA0();
  return;
}

/* flash page 26 cpu 0x7B9B (offset 0x3B9B) */
void p26_L_7B9B(void) {
  a = 0x01;
  set_de(0x0000);
  p26_L_7BA0();
  return;
}

/* flash page 26 cpu 0x7BA0 (offset 0x3BA0) */
void p26_L_7BA0(void) {
  p00_L_17CE();
  if (flag_z()) goto lab_p26_L_7BA9;
  a = (uint8_t)(a + 0x03);
  e = a;
  a = (uint8_t)(a + 1);
  lab_p26_L_7BA9: ;
  mem_write8(0x97A5, a);
  mem_write16(0x844B, de());
  p26_L_7BB4();
  return;
}

/* flash page 26 cpu 0x7BB4 (offset 0x3BB4) */
void p26_L_7BB4(void) {
  cpu_push_bc();
  cpu_push_af();
  a = mem_read8(0x97A6);
  b = a;
  lab_p26_L_7BBA: ;
  a = mem_read8(hl());
  set_hl((uint16_t)(hl() + 1));
  a = a | a;
  flag_logic(a);
  /* scf */
  if (flag_z()) goto lab_p26_L_7BC9;
  p00_L_3F9F();
  a = mem_read8(0x844B);
  flag_cmp(a, b);
  if (flag_c()) goto lab_p26_L_7BBA;
  lab_p26_L_7BC9: ;
  cpu_pop_bc();
  a = b;
  cpu_pop_bc();
  return;
}

/* flash page 26 cpu 0x7DAD (offset 0x3DAD) */
void p26_str_1(void) {
  b = mem_read8(hl());
  h = c;
  h = e;
  mem_write8(hl(), h);
  l = a;
  mem_write8(hl(), d);
  /* nop */
  d = e;
  l = c;
  l = mem_read8(hl());
  d = d;
  h = l;
  h = a;
  /* nop */
  a = c;
  a = (uint8_t)(a - 1);
  h = c;
  set_hl(mem_read16(0x6973));
  l = mem_read8(hl());
  if (flag_z()) goto lab_p26_L_7E26;
  a = b;
  set_hl((uint16_t)(hl() - 1));
  h = e;
  set_hl((uint16_t)(hl() + hl()));
  set_hl((uint16_t)(hl() - 1));
  h = h;
  /* nop */
  p26_str_2();
  return;
  lab_p26_L_7E26: ;
  set_hl(0x7DCB);
  a = 0x46;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  a = 0x01;
  mem_write8(0x844C, a);
  p26_L_7BB4();
  p00_L_3D1D();
  return;
}

/* flash page 26 cpu 0x7DCB (offset 0x3DCB) */
void p26_str_2(void) {
  b = l;
  mem_write8(hl(), d);
  mem_write8(hl(), d);
  l = a;
  mem_write8(hl(), d);
  /* nop */
  a = mem_read8(0x3EBC);
  if (flag_nc()) goto lab_p26_L_7DFC;
  cpu_push_bc();
  a = 0x30;
  /* nop */
  a = mem_read8(0x3CBC);
  if (flag_nc()) goto lab_p26_L_7E05;
  cpu_push_bc();
  a = (uint8_t)(a + 1);
  if (flag_nc()) goto lab_p26_L_7DE3;
  lab_p26_L_7DE3: ;
  a = mem_read8(0x18BC);
  if (flag_nc()) goto lab_p26_L_7E0E;
  cpu_push_bc();
  goto lab_p26_L_7E1B;
  lab_p26_L_7DFC: ;
  l = (uint8_t)(l - 1);
  a = l;
  sp = (uint16_t)(sp + 1);
  a = l;
  set_hl((uint16_t)(hl() + sp));
  a = l;
  /* ccf */
  a = l;
  b = l;
  lab_p26_L_7E05: ;
  a = l;
  c = e;
  a = l;
  d = c;
  a = l;
  /* adc a,e */
  a = l;
  mem_write8(hl(), e);
  a = l;
  lab_p26_L_7E0E: ;
  a = a;
  a = l;
  /* ex (sp),hl */
  a = l;
  cpu_pop_de();
  a = l;
  if (flag_c()) { p00_L_217D(); return; }
  a = a ^ l;
  flag_logic(a);
  a = l;
  if (flag_nz()) goto lab_p26_L_7E26;
  lab_p26_L_7E1B: ;
  a = 0x45;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p26_L_7E32;
  lab_p26_L_7E26: ;
  set_hl(0x7DCB);
  a = 0x46;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  lab_p26_L_7E32: ;
  a = 0x01;
  mem_write8(0x844C, a);
  p26_L_7BB4();
  p00_L_3D1D();
  return;
}

/* flash page 26 cpu 0x7E16 (offset 0x3E16) */
void p26_L_7E16(void) {
  set_hl(0x7DAD);
  if (flag_nz()) goto lab_p26_L_7E26;
  a = 0x45;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  goto lab_p26_L_7E32;
  lab_p26_L_7E26: ;
  set_hl(0x7DCB);
  a = 0x46;
  flag_set_z((mem_read8((uint16_t)(iy + 0x35)) & (1u << 1)) == 0);
  if (flag_nz()) p00_L_3C45();
  lab_p26_L_7E32: ;
  a = 0x01;
  mem_write8(0x844C, a);
  p26_L_7BB4();
  p00_L_3D1D();
  return;
}

/* flash page 26 cpu 0x7E3E (offset 0x3E3E) */
void p26_L_7E3E(void) {
  a = mem_read8(0x8A37);
  p26_L_7E41();
  return;
}

/* flash page 26 cpu 0x7E41 (offset 0x3E41) */
void p26_L_7E41(void) {
  a = (uint8_t)(a + a);
  d = 0x00;
  e = a;
  set_hl((uint16_t)(hl() + de()));
  p00_L_0033();
  return;
}


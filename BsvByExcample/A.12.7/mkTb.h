/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Sat Jan 13 20:48:58 CET 2024
 * 
 */

/* Generation options: */
#ifndef __mkTb_h__
#define __mkTb_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkTb module */
class MOD_mkTb : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_Reg<tUInt32> INST_arr1_0;
  MOD_Reg<tUInt32> INST_arr1_1;
  MOD_Reg<tUInt32> INST_arr1_2;
  MOD_Reg<tUInt32> INST_arr1_3;
  MOD_Reg<tUInt32> INST_arr1_4;
  MOD_Reg<tUInt32> INST_arr1_5;
  MOD_Reg<tUInt32> INST_arr1_6;
  MOD_Reg<tUInt32> INST_arr1_7;
  MOD_Reg<tUInt8> INST_inx;
  MOD_Reg<tUInt32> INST_step;
 
 /* Constructor */
 public:
  MOD_mkTb(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
 
 /* Publicly accessible definitions */
 public:
  tUInt32 DEF_b__h570;
 
 /* Local definitions */
 private:
  tUInt32 DEF_arr1_0___d6;
  tUInt32 DEF_b__h2457;
  tUInt32 DEF_b__h2382;
  tUInt32 DEF_b__h2289;
  tUInt32 DEF_b__h2196;
  tUInt32 DEF_b__h2103;
  tUInt32 DEF_b__h2010;
  tUInt32 DEF_b__h1917;
  tUInt32 DEF_step_PLUS_1___d3;
 
 /* Rules */
 public:
  void RL_init();
  void RL_step1();
  void RL_step2();
  void RL_step3();
  void RL_step4();
  void RL_step5();
  void RL_step6();
  void RL_step7();
  void RL_step8();
  void RL_watcher();
 
 /* Methods */
 public:
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTb &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTb &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTb &backing);
};

#endif /* ifndef __mkTb_h__ */

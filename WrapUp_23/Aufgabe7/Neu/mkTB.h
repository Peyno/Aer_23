/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Fri Feb 23 23:16:51 CET 2024
 * 
 */

/* Generation options: */
#ifndef __mkTB_h__
#define __mkTB_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkTB module */
class MOD_mkTB : public Module {
 
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
  MOD_Wire<tUInt8> INST_abort;
  MOD_Fifo<tUInt64> INST_dut_adder_in;
  MOD_Fifo<tUInt32> INST_dut_adder_out;
  MOD_Fifo<tUWide> INST_dut_incoming;
  MOD_Fifo<tUInt64> INST_dut_mul_in;
  MOD_Fifo<tUInt32> INST_dut_mul_out;
  MOD_Reg<tUInt32> INST_dut_rega;
  MOD_Reg<tUInt32> INST_dut_regb;
  MOD_Reg<tUInt32> INST_dut_regc;
  MOD_Reg<tUInt32> INST_dut_regd;
  MOD_Reg<tUInt32> INST_dut_resultadd1;
  MOD_Reg<tUInt32> INST_dut_resultadd2;
  MOD_Reg<tUInt32> INST_dut_resultmul;
  MOD_Fifo<tUInt32> INST_dut_sqrt_in;
  MOD_Fifo<tUInt32> INST_dut_sqrt_out;
  MOD_Reg<tUInt32> INST_dut_state;
  MOD_Reg<tUInt8> INST_running;
  MOD_Reg<tUInt8> INST_start_reg;
  MOD_Reg<tUInt8> INST_start_reg_1;
  MOD_Wire<tUInt8> INST_start_reg_2;
  MOD_Wire<tUInt8> INST_start_wire;
  MOD_Reg<tUInt8> INST_state_can_overlap;
  MOD_Reg<tUInt8> INST_state_fired;
  MOD_Wire<tUInt8> INST_state_fired_1;
  MOD_ConfigReg<tUInt8> INST_state_mkFSMstate;
  MOD_Wire<tUInt8> INST_state_overlap_pw;
  MOD_Wire<tUInt8> INST_state_set_pw;
 
 /* Constructor */
 public:
  MOD_mkTB(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUInt8 DEF_WILL_FIRE_RL_action_l154c9;
  tUInt8 DEF_WILL_FIRE_RL_action_l153c1;
  tUInt8 DEF_WILL_FIRE_RL_action_l152c12;
  tUInt32 DEF_b__h1158;
 
 /* Local definitions */
 private:
  tUWide DEF_dut_incoming_first____d25;
  tUInt32 DEF_dut_adder_out_first____d40;
  tUInt32 DEF_dut_state_2_PLUS_1___d30;
 
 /* Rules */
 public:
  void RL_dut_adder_r1();
  void RL_dut_mul_r1();
  void RL_dut_sqrt_r1();
  void RL_dut_pull();
  void RL_dut_requestadd1();
  void RL_dut_responseadd1();
  void RL_dut_requestadd2();
  void RL_dut_responseadd2();
  void RL_dut_requestmul();
  void RL_dut_responsemul();
  void RL_dut_sqrtrequest();
  void RL_start_reg__dreg_update();
  void RL_state_handle_abort();
  void RL_state_fired__dreg_update();
  void RL_state_every();
  void RL_restart();
  void RL_action_l152c12();
  void RL_action_l153c1();
  void RL_action_l154c9();
  void RL_idle_l150c17();
  void RL_fsm_start();
  void RL_auto_start();
  void RL_auto_finish();
  void __me_check_16();
  void __me_check_17();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTB &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTB &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTB &backing);
};

#endif /* ifndef __mkTB_h__ */
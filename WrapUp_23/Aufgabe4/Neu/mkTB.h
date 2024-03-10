/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Fri Feb 23 21:25:30 CET 2024
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
  MOD_Reg<tUInt32> INST_dut_index;
  MOD_Reg<tUWide> INST_dut_stack;
  MOD_Reg<tUInt32> INST_i;
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
  tUInt8 DEF_WILL_FIRE_RL_action_f_update_l42c9;
  tUInt8 DEF_WILL_FIRE_RL_action_l44c13;
  tUInt8 DEF_WILL_FIRE_RL_action_l43c16;
  tUInt8 DEF_WILL_FIRE_RL_action_f_init_l42c9;
  tUInt32 DEF_x__h14401;
  tUInt32 DEF_b__h5484;
 
 /* Local definitions */
 private:
  tUWide DEF_dut_stack__h14687;
  tUInt32 DEF_v__h14332;
  tUInt32 DEF_v__h14327;
  tUInt32 DEF_v__h14322;
  tUInt32 DEF_v__h14317;
  tUInt32 DEF_v__h14312;
  tUWide DEF_IF_dut_index_9_EQ_4_5_THEN_i_6_ELSE_dut_stack__ETC___d72;
  tUWide DEF_IF_dut_index_9_EQ_4_5_THEN_i_6_ELSE_dut_stack__ETC___d65;
 
 /* Rules */
 public:
  void RL_start_reg__dreg_update();
  void RL_state_handle_abort();
  void RL_state_fired__dreg_update();
  void RL_state_every();
  void RL_restart();
  void RL_action_f_init_l42c9();
  void RL_action_l43c16();
  void RL_action_l44c13();
  void RL_action_f_update_l42c9();
  void RL_idle_l42c9();
  void RL_idle_l42c9_1();
  void RL_fsm_start();
  void RL_auto_start();
  void RL_auto_finish();
  void __me_check_5();
  void __me_check_6();
  void __me_check_7();
 
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
/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Sat Feb 24 17:31:03 CET 2024
 * 
 */

/* Generation options: */
#ifndef __mkAmpelTest_h__
#define __mkAmpelTest_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkAmpelTest module */
class MOD_mkAmpelTest : public Module {
 
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
  MOD_Wire<tUInt8> INST_ampel_fsm_abort;
  MOD_Reg<tUInt8> INST_ampel_fsm_start_reg;
  MOD_Reg<tUInt8> INST_ampel_fsm_start_reg_1;
  MOD_Wire<tUInt8> INST_ampel_fsm_start_reg_2;
  MOD_Wire<tUInt8> INST_ampel_fsm_start_wire;
  MOD_Reg<tUInt8> INST_ampel_fsm_state_can_overlap;
  MOD_Reg<tUInt8> INST_ampel_fsm_state_fired;
  MOD_Wire<tUInt8> INST_ampel_fsm_state_fired_1;
  MOD_ConfigReg<tUInt8> INST_ampel_fsm_state_mkFSMstate;
  MOD_Wire<tUInt8> INST_ampel_fsm_state_overlap_pw;
  MOD_Wire<tUInt8> INST_ampel_fsm_state_set_pw;
  MOD_Reg<tUInt8> INST_ampel_idle_counter;
  MOD_CReg<tUInt8> INST_ampel_pedestrian_request;
  MOD_CReg<tUInt8> INST_ampel_pedestrian_state;
  MOD_CReg<tUInt8> INST_ampel_state;
  MOD_Reg<tUInt32> INST_counter;
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
  MOD_mkAmpelTest(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUInt8 DEF_WILL_FIRE_RL_action_l129c26;
  tUInt8 DEF_WILL_FIRE_RL_action_l127c18;
  tUInt8 DEF_WILL_FIRE_RL_ampel_fsm_action_l79c32;
  tUInt8 DEF_WILL_FIRE_RL_ampel_fsm_action_l75c9;
  tUInt8 DEF_WILL_FIRE_RL_ampel_fsm_action_l70c9;
  tUInt8 DEF_WILL_FIRE_RL_ampel_fsm_action_l64c9;
  tUInt8 DEF_WILL_FIRE_RL_ampel_fsm_action_l35c33;
  tUInt8 DEF_WILL_FIRE_RL_ampel_fsm_action_l30c9;
  tUInt8 DEF_WILL_FIRE_RL_ampel_fsm_action_l26c9;
  tUInt8 DEF_b__h8525;
 
 /* Local definitions */
 private:
  tUInt64 DEF_v__h33538;
 
 /* Rules */
 public:
  void RL_ampel_fsm_start_reg__dreg_update();
  void RL_ampel_fsm_state_handle_abort();
  void RL_ampel_fsm_state_fired__dreg_update();
  void RL_ampel_fsm_state_every();
  void RL_ampel_fsm_restart();
  void RL_ampel_fsm_action_l26c9();
  void RL_ampel_fsm_action_l30c9();
  void RL_ampel_fsm_action_l35c33();
  void RL_ampel_fsm_action_l64c9();
  void RL_ampel_fsm_action_l70c9();
  void RL_ampel_fsm_action_l75c9();
  void RL_ampel_fsm_action_l79c32();
  void RL_ampel_fsm_idle_l24c14();
  void RL_ampel_fsm_idle_l24c14_1();
  void RL_ampel_fsm_fsm_start();
  void RL_ampel_start();
  void RL_start_reg__dreg_update();
  void RL_state_handle_abort();
  void RL_state_fired__dreg_update();
  void RL_state_every();
  void RL_restart();
  void RL_action_l127c18();
  void RL_action_l129c26();
  void RL_fsm_start();
  void RL_auto_start();
  void RL_auto_finish();
  void __me_check_5();
  void __me_check_6();
  void __me_check_7();
  void __me_check_8();
  void __me_check_9();
  void __me_check_10();
  void __me_check_21();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkAmpelTest &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkAmpelTest &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkAmpelTest &backing);
};

#endif /* ifndef __mkAmpelTest_h__ */
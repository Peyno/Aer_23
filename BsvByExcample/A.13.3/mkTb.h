/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Sat Jan 13 21:38:33 CET 2024
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
  MOD_Reg<tUInt8> INST_complete;
  MOD_Wire<tUInt8> INST_testFSM_abort;
  MOD_Reg<tUInt8> INST_testFSM_start_reg;
  MOD_Reg<tUInt8> INST_testFSM_start_reg_1;
  MOD_Wire<tUInt8> INST_testFSM_start_reg_2;
  MOD_Wire<tUInt8> INST_testFSM_start_wire;
  MOD_Reg<tUInt8> INST_testFSM_state_can_overlap;
  MOD_Reg<tUInt8> INST_testFSM_state_fired;
  MOD_Wire<tUInt8> INST_testFSM_state_fired_1;
  MOD_ConfigReg<tUInt8> INST_testFSM_state_mkFSMstate;
  MOD_Wire<tUInt8> INST_testFSM_state_overlap_pw;
  MOD_Wire<tUInt8> INST_testFSM_state_set_pw;
 
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
  tUInt8 DEF_WILL_FIRE_RL_testFSM_action_l14c9;
  tUInt8 DEF_WILL_FIRE_RL_testFSM_action_l13c9;
  tUInt8 DEF_WILL_FIRE_RL_testFSM_action_l12c9;
  tUInt8 DEF_WILL_FIRE_RL_testFSM_action_l11c9;
 
 /* Local definitions */
 private:
  tUInt64 DEF_v__h9820;
  tUInt64 DEF_v__h9356;
  tUInt64 DEF_v__h9145;
  tUInt64 DEF_v__h8942;
 
 /* Rules */
 public:
  void RL_testFSM_start_reg__dreg_update();
  void RL_testFSM_state_handle_abort();
  void RL_testFSM_state_fired__dreg_update();
  void RL_testFSM_state_every();
  void RL_testFSM_restart();
  void RL_testFSM_action_l11c9();
  void RL_testFSM_action_l12c9();
  void RL_testFSM_action_l13c9();
  void RL_testFSM_action_l14c9();
  void RL_testFSM_idle_l10c5();
  void RL_testFSM_fsm_start();
  void RL_startit();
  void RL_alwaysrun();
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTb &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTb &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTb &backing);
};

#endif /* ifndef __mkTb_h__ */

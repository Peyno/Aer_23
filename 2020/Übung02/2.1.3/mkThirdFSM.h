/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Tue Jan 16 17:56:16 CET 2024
 * 
 */

/* Generation options: */
#ifndef __mkThirdFSM_h__
#define __mkThirdFSM_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkThirdFSM module */
class MOD_mkThirdFSM : public Module {
 
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
  MOD_Reg<tUInt32> INST_counter;
  MOD_Reg<tUInt32> INST_i;
  MOD_Wire<tUInt8> INST_myFSM_abort;
  MOD_Reg<tUInt8> INST_myFSM_start_reg;
  MOD_Reg<tUInt8> INST_myFSM_start_reg_1;
  MOD_Wire<tUInt8> INST_myFSM_start_reg_2;
  MOD_Wire<tUInt8> INST_myFSM_start_wire;
  MOD_Reg<tUInt8> INST_myFSM_state_can_overlap;
  MOD_Reg<tUInt8> INST_myFSM_state_fired;
  MOD_Wire<tUInt8> INST_myFSM_state_fired_1;
  MOD_ConfigReg<tUInt8> INST_myFSM_state_mkFSMstate;
  MOD_Wire<tUInt8> INST_myFSM_state_overlap_pw;
  MOD_Wire<tUInt8> INST_myFSM_state_set_pw;
  MOD_Wire<tUInt8> INST_pw;
 
 /* Constructor */
 public:
  MOD_mkThirdFSM(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUInt8 DEF_WILL_FIRE_RL_myFSM_action_l23c13;
  tUInt8 DEF_WILL_FIRE_RL_myFSM_action_f_update_l20c13;
  tUInt8 DEF_WILL_FIRE_RL_myFSM_action_l21c17;
  tUInt8 DEF_WILL_FIRE_RL_myFSM_action_f_init_l20c13;
  tUInt32 DEF_b__h5556;
  tUInt32 DEF_b__h138;
 
 /* Local definitions */
 private:
  tUInt64 DEF_v__h13588;
 
 /* Rules */
 public:
  void RL_count();
  void RL_restCount();
  void RL_myFSM_start_reg__dreg_update();
  void RL_myFSM_state_handle_abort();
  void RL_myFSM_state_fired__dreg_update();
  void RL_myFSM_state_every();
  void RL_myFSM_restart();
  void RL_myFSM_action_f_init_l20c13();
  void RL_myFSM_action_l21c17();
  void RL_myFSM_action_f_update_l20c13();
  void RL_myFSM_action_l23c13();
  void RL_myFSM_idle_l19c9();
  void RL_myFSM_fsm_start();
  void RL_startFSM();
  void __me_check_7();
  void __me_check_8();
  void __me_check_9();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkThirdFSM &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkThirdFSM &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkThirdFSM &backing);
};

#endif /* ifndef __mkThirdFSM_h__ */

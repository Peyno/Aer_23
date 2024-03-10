/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Sat Feb 10 16:52:04 CET 2024
 * 
 */

/* Generation options: */
#ifndef __mkMacTb_h__
#define __mkMacTb_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkMacTb module */
class MOD_mkMacTb : public Module {
 
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
  MOD_Reg<tUInt32> INST_dut1_a;
  MOD_Fifo<tUInt32> INST_dut1_inA;
  MOD_Fifo<tUInt32> INST_dut1_inB;
  MOD_Reg<tUInt32> INST_resultdut1;
  MOD_Reg<tUInt32> INST_resultdut2;
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
  MOD_mkMacTb(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUInt8 DEF_WILL_FIRE_RL_action_l63c17;
  tUInt8 DEF_WILL_FIRE_RL_action_l62c28;
  tUInt8 DEF_WILL_FIRE_RL_action_l61c21;
  tUInt8 DEF_WILL_FIRE_RL_action_l60c21;
 
 /* Local definitions */
 private:
  tUInt32 DEF_b__h316;
 
 /* Rules */
 public:
  void RL_dut1_calc();
  void RL_start_reg__dreg_update();
  void RL_state_handle_abort();
  void RL_state_fired__dreg_update();
  void RL_state_every();
  void RL_restart();
  void RL_action_l60c21();
  void RL_action_l61c21();
  void RL_action_l62c28();
  void RL_action_l63c17();
  void RL_idle_l58c12();
  void RL_fsm_start();
  void RL_auto_start();
  void RL_auto_finish();
  void __me_check_6();
  void __me_check_7();
  void __me_check_8();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkMacTb &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkMacTb &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkMacTb &backing);
};

#endif /* ifndef __mkMacTb_h__ */

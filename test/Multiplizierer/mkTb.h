/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Sat Feb 10 16:32:40 CET 2024
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
  MOD_Reg<tUInt32> INST_dut_reg_rslt;
  MOD_Reg<tUInt32> INST_dut_reg_x;
  MOD_Reg<tUInt32> INST_dut_reg_y;
  MOD_Reg<tUInt8> INST_dut_set_x;
  MOD_Reg<tUInt8> INST_dut_set_y;
 
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
  tUInt32 DEF_dut_reg_y__h289;
 
 /* Local definitions */
 private:
  tUInt32 DEF_dut_reg_rslt___d9;
 
 /* Rules */
 public:
  void RL_dut_calc();
  void RL_calc_real();
  void RL_result_real();
 
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
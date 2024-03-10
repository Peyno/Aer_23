/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Fri Feb  9 18:22:47 CET 2024
 * 
 */

/* Generation options: */
#ifndef __mkTb2_h__
#define __mkTb2_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkTb2 module */
class MOD_mkTb2 : public Module {
 
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
  MOD_Reg<tUInt32> INST_c;
 
 /* Constructor */
 public:
  MOD_mkTb2(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
 
 /* Local definitions */
 private:
 
 /* Rules */
 public:
  void RL_r1();
  void RL_r1_1();
  void RL_r1_2();
  void RL_r1_3();
  void RL_r1_4();
  void RL_r1_5();
  void RL_r1_6();
  void RL_r1_7();
  void RL_r1_8();
  void RL_r1_9();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTb2 &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTb2 &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTb2 &backing);
};

#endif /* ifndef __mkTb2_h__ */
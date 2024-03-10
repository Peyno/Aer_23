/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Thu Feb 15 17:02:18 CET 2024
 * 
 */

/* Generation options: */
#ifndef __mkToPutTestTb_h__
#define __mkToPutTestTb_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkToPutTestTb module */
class MOD_mkToPutTestTb : public Module {
 
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
  MOD_Reg<tUInt8> INST_bol;
  MOD_Reg<tUInt32> INST_end_result;
  MOD_Fifo<tUInt32> INST_server_fifo_in;
  MOD_Fifo<tUInt32> INST_server_fifo_out;
 
 /* Constructor */
 public:
  MOD_mkToPutTestTb(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  void RL_server_do_sth();
  void RL_calc();
  void RL_r2();
  void RL_r3();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkToPutTestTb &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkToPutTestTb &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkToPutTestTb &backing);
};

#endif /* ifndef __mkToPutTestTb_h__ */
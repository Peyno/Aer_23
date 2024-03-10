/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Wed Feb 14 18:26:12 CET 2024
 * 
 */

/* Generation options: */
#ifndef __mkTB1_h__
#define __mkTB1_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkTB1 module */
class MOD_mkTB1 : public Module {
 
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
  MOD_Reg<tUInt32> INST_cntr;
  MOD_Reg<tUInt8> INST_dut_cntr;
  MOD_Fifo<tUInt8> INST_dut_queue;
 
 /* Constructor */
 public:
  MOD_mkTB1(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUInt8 DEF__read__h153;
 
 /* Rules */
 public:
  void RL_dut_switch();
  void RL_dut_r1();
  void RL_r();
  void RL_r1();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTB1 &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTB1 &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTB1 &backing);
};

#endif /* ifndef __mkTB1_h__ */

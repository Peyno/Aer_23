/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Mon Feb 12 13:23:00 CET 2024
 * 
 */

/* Generation options: */
#ifndef __mkAufgabe5TB_h__
#define __mkAufgabe5TB_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkAufgabe5TB module */
class MOD_mkAufgabe5TB : public Module {
 
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
  MOD_Reg<tUInt32> INST_cinter;
  MOD_Reg<tUInt32> INST_count;
  MOD_Reg<tUInt32> INST_dut_ctr;
  MOD_Fifo<tUInt8> INST_dut_fifo;
  MOD_Reg<tUInt8> INST_dut_fifoout;
  MOD_Reg<tUInt8> INST_dut_pinvalue;
  MOD_Reg<tUInt8> INST_dut_state;
  MOD_Reg<tUInt32> INST_dut_ticks;
  MOD_Reg<tUInt32> INST_state;
 
 /* Constructor */
 public:
  MOD_mkAufgabe5TB(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUInt32 DEF_b__h308;
  tUInt32 DEF_b__h1047;
  tUInt32 DEF_b__h1012;
 
 /* Local definitions */
 private:
  tUInt64 DEF_v__h1137;
 
 /* Rules */
 public:
  void RL_dut_ticrule();
  void RL_dut_idle();
  void RL_dut_start();
  void RL_dut_transfer();
  void RL_dut_ende();
  void RL_counter();
  void RL_stop();
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkAufgabe5TB &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkAufgabe5TB &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkAufgabe5TB &backing);
};

#endif /* ifndef __mkAufgabe5TB_h__ */

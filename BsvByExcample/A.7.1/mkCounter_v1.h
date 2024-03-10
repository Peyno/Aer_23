/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Wed Jan 10 11:12:53 CET 2024
 * 
 */

/* Generation options: */
#ifndef __mkCounter_v1_h__
#define __mkCounter_v1_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkCounter_v1 module */
class MOD_mkCounter_v1 : public Module {
 
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
  MOD_Reg<tUInt32> INST_value1;
 
 /* Constructor */
 public:
  MOD_mkCounter_v1(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUInt32 DEF_b__h61;
 
 /* Rules */
 public:
 
 /* Methods */
 public:
  tUInt32 METH_read();
  tUInt8 METH_RDY_read();
  void METH_increment(tUInt32 ARG_increment_di);
  tUInt8 METH_RDY_increment();
  void METH_decrement(tUInt32 ARG_decrement_dd);
  tUInt8 METH_RDY_decrement();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkCounter_v1 &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkCounter_v1 &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkCounter_v1 &backing);
};

#endif /* ifndef __mkCounter_v1_h__ */

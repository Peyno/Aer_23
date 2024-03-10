/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Tue Jan  9 16:05:01 CET 2024
 * 
 */

/* Generation options: */
#ifndef __mkGadget_h__
#define __mkGadget_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkGadget module */
class MOD_mkGadget : public Module {
 
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
  MOD_Reg<tUInt32> INST_bubble_cycles;
  MOD_Fifo<tUInt32> INST_infifo;
  MOD_Reg<tUInt32> INST_max_bubble_cycles;
  MOD_Fifo<tUInt32> INST_outfifo;
 
 /* Constructor */
 public:
  MOD_mkGadget(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUInt32 DEF_b__h358;
 
 /* Rules */
 public:
  void RL_enqueue_item();
  void RL_inc_bubble_cyclus();
  void RL_enqueue_bubble();
 
 /* Methods */
 public:
  void METH_request_put(tUInt32 ARG_request_put);
  tUInt8 METH_RDY_request_put();
  tUInt32 METH_response_get();
  tUInt8 METH_RDY_response_get();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkGadget &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkGadget &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkGadget &backing);
};

#endif /* ifndef __mkGadget_h__ */
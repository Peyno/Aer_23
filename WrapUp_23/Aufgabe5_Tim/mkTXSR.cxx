/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Tue Feb 13 17:46:46 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTXSR.h"


/* Constructor */
MOD_mkTXSR::MOD_mkTXSR(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_fTX(simHdl, "fTX", this, 8u, 2u, (tUInt8)1u, 0u),
    INST_pwTick(simHdl, "pwTick", this, 0u),
    INST_rBitIndex(simHdl, "rBitIndex", this, 4u, (tUInt8)10u, (tUInt8)0u),
    INST_rCounter(simHdl, "rCounter", this, 32u, 0u, (tUInt8)0u),
    INST_rOut(simHdl, "rOut", this, 10u, 0u, (tUInt8)0u),
    INST_rOutputPin(simHdl, "rOutputPin", this, 1u, (tUInt8)1u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 8u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTXSR::init_symbols_0()
{
  init_symbol(&symbols[0u], "fTX", SYM_MODULE, &INST_fTX);
  init_symbol(&symbols[1u], "pwTick", SYM_MODULE, &INST_pwTick);
  init_symbol(&symbols[2u], "RL_send_bit", SYM_RULE);
  init_symbol(&symbols[3u], "RL_tick_gen", SYM_RULE);
  init_symbol(&symbols[4u], "rBitIndex", SYM_MODULE, &INST_rBitIndex);
  init_symbol(&symbols[5u], "rCounter", SYM_MODULE, &INST_rCounter);
  init_symbol(&symbols[6u], "rOut", SYM_MODULE, &INST_rOut);
  init_symbol(&symbols[7u], "rOutputPin", SYM_MODULE, &INST_rOutputPin);
}


/* Rule actions */

void MOD_mkTXSR::RL_tick_gen()
{
  tUInt8 DEF_NOT_rCounter_PLUS_1_ULT_16___d5;
  tUInt32 DEF_rCounter_PLUS_1___d2;
  tUInt8 DEF_rCounter_PLUS_1_ULT_16___d3;
  tUInt32 DEF_IF_rCounter_PLUS_1_ULT_16_THEN_rCounter_PLUS_1_ETC___d4;
  tUInt32 DEF_b__h332;
  DEF_b__h332 = INST_rCounter.METH_read();
  DEF_rCounter_PLUS_1___d2 = DEF_b__h332 + 1u;
  DEF_rCounter_PLUS_1_ULT_16___d3 = DEF_rCounter_PLUS_1___d2 < 16u;
  DEF_IF_rCounter_PLUS_1_ULT_16_THEN_rCounter_PLUS_1_ETC___d4 = DEF_rCounter_PLUS_1_ULT_16___d3 ? DEF_rCounter_PLUS_1___d2 : 0u;
  DEF_NOT_rCounter_PLUS_1_ULT_16___d5 = !DEF_rCounter_PLUS_1_ULT_16___d3;
  INST_rCounter.METH_write(DEF_IF_rCounter_PLUS_1_ULT_16_THEN_rCounter_PLUS_1_ETC___d4);
  if (DEF_NOT_rCounter_PLUS_1_ULT_16___d5)
    INST_pwTick.METH_wset();
}

void MOD_mkTXSR::RL_send_bit()
{
  tUInt32 DEF__0b1_CONCAT_IF_rBitIndex_EQ_10_0_THEN_fTX_first_ETC___d16;
  tUInt8 DEF_NOT_rBitIndex_EQ_10_0___d19;
  tUInt8 DEF_IF_rBitIndex_EQ_10_0_THEN_0_ELSE_rBitIndex_PLU_ETC___d18;
  tUInt8 DEF_rBitIndex_EQ_10___d10;
  tUInt8 DEF_x__h549;
  tUInt32 DEF_rOut_BITS_9_TO_1___h491;
  tUInt8 DEF_b__h389;
  tUInt8 DEF_pkt__h394;
  tUInt32 DEF_rOut__h588;
  DEF_rOut__h588 = INST_rOut.METH_read();
  DEF_pkt__h394 = INST_fTX.METH_first();
  DEF_b__h389 = INST_rBitIndex.METH_read();
  DEF_rOut_BITS_9_TO_1___h491 = (tUInt32)(DEF_rOut__h588 >> 1u);
  DEF_x__h549 = (tUInt8)((tUInt8)1u & DEF_rOut__h588);
  DEF_rBitIndex_EQ_10___d10 = DEF_b__h389 == (tUInt8)10u;
  DEF_IF_rBitIndex_EQ_10_0_THEN_0_ELSE_rBitIndex_PLU_ETC___d18 = DEF_rBitIndex_EQ_10___d10 ? (tUInt8)0u : (tUInt8)15u & (DEF_b__h389 + (tUInt8)1u);
  DEF_NOT_rBitIndex_EQ_10_0___d19 = !DEF_rBitIndex_EQ_10___d10;
  DEF__0b1_CONCAT_IF_rBitIndex_EQ_10_0_THEN_fTX_first_ETC___d16 = 1023u & ((((tUInt32)((tUInt8)1u)) << 9u) | (DEF_rBitIndex_EQ_10___d10 ? 511u & ((((tUInt32)(DEF_pkt__h394)) << 1u) | (tUInt32)((tUInt8)0u)) : DEF_rOut_BITS_9_TO_1___h491));
  INST_rOut.METH_write(DEF__0b1_CONCAT_IF_rBitIndex_EQ_10_0_THEN_fTX_first_ETC___d16);
  INST_rBitIndex.METH_write(DEF_IF_rBitIndex_EQ_10_0_THEN_0_ELSE_rBitIndex_PLU_ETC___d18);
  if (DEF_rBitIndex_EQ_10___d10)
    INST_fTX.METH_deq();
  if (DEF_NOT_rBitIndex_EQ_10_0___d19)
    INST_rOutputPin.METH_write(DEF_x__h549);
}


/* Methods */

tUInt8 MOD_mkTXSR::METH_pin()
{
  tUInt8 PORT_pin;
  PORT_pin = INST_rOutputPin.METH_read();
  return PORT_pin;
}

tUInt8 MOD_mkTXSR::METH_RDY_pin()
{
  tUInt8 DEF_CAN_FIRE_pin;
  tUInt8 PORT_RDY_pin;
  DEF_CAN_FIRE_pin = (tUInt8)1u;
  PORT_RDY_pin = DEF_CAN_FIRE_pin;
  return PORT_RDY_pin;
}

void MOD_mkTXSR::METH_data_put(tUInt8 ARG_data_put)
{
  INST_fTX.METH_enq(ARG_data_put);
}

tUInt8 MOD_mkTXSR::METH_RDY_data_put()
{
  tUInt8 DEF_CAN_FIRE_data_put;
  tUInt8 PORT_RDY_data_put;
  DEF_CAN_FIRE_data_put = INST_fTX.METH_i_notFull();
  PORT_RDY_data_put = DEF_CAN_FIRE_data_put;
  return PORT_RDY_data_put;
}


/* Reset routines */

void MOD_mkTXSR::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_rOutputPin.reset_RST(ARG_rst_in);
  INST_rOut.reset_RST(ARG_rst_in);
  INST_rCounter.reset_RST(ARG_rst_in);
  INST_rBitIndex.reset_RST(ARG_rst_in);
  INST_fTX.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTXSR::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTXSR::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_fTX.dump_state(indent + 2u);
  INST_pwTick.dump_state(indent + 2u);
  INST_rBitIndex.dump_state(indent + 2u);
  INST_rCounter.dump_state(indent + 2u);
  INST_rOut.dump_state(indent + 2u);
  INST_rOutputPin.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTXSR::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 7u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  num = INST_fTX.dump_VCD_defs(num);
  num = INST_pwTick.dump_VCD_defs(num);
  num = INST_rBitIndex.dump_VCD_defs(num);
  num = INST_rCounter.dump_VCD_defs(num);
  num = INST_rOut.dump_VCD_defs(num);
  num = INST_rOutputPin.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTXSR::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTXSR &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTXSR::vcd_defs(tVCDDumpType dt, MOD_mkTXSR &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
    }
}

void MOD_mkTXSR::vcd_prims(tVCDDumpType dt, MOD_mkTXSR &backing)
{
  INST_fTX.dump_VCD(dt, backing.INST_fTX);
  INST_pwTick.dump_VCD(dt, backing.INST_pwTick);
  INST_rBitIndex.dump_VCD(dt, backing.INST_rBitIndex);
  INST_rCounter.dump_VCD(dt, backing.INST_rCounter);
  INST_rOut.dump_VCD(dt, backing.INST_rOut);
  INST_rOutputPin.dump_VCD(dt, backing.INST_rOutputPin);
}

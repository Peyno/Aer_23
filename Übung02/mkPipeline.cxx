/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Tue Nov 21 15:45:36 CET 2023
 * 
 */
#include "bluesim_primitives.h"
#include "mkPipeline.h"


/* Constructor */
MOD_mkPipeline::MOD_mkPipeline(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_fifo_in(simHdl, "fifo_in", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_fifo_out(simHdl, "fifo_out", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_params_0(simHdl, "params_0", this, 32u),
    INST_params_1(simHdl, "params_1", this, 32u),
    INST_params_2(simHdl, "params_2", this, 32u),
    INST_regs_0(simHdl, "regs_0", this, 33u, 2863311530llu, (tUInt8)0u),
    INST_regs_1(simHdl, "regs_1", this, 33u, 2863311530llu, (tUInt8)0u),
    INST_regs_2(simHdl, "regs_2", this, 33u, 2863311530llu, (tUInt8)0u),
    INST_regs_3(simHdl, "regs_3", this, 33u, 2863311530llu, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  PORT_EN_setParam = false;
  PORT_EN_calc_result = false;
  PORT_EN_calc_put = false;
  PORT_setParam_addr = 0u;
  PORT_setParam_val = 0u;
  PORT_calc_put_x = 0u;
  symbol_count = 19u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkPipeline::init_symbols_0()
{
  init_symbol(&symbols[0u], "calc_put_x", SYM_PORT, &PORT_calc_put_x, 32u);
  init_symbol(&symbols[1u], "EN_calc_put", SYM_PORT, &PORT_EN_calc_put, 1u);
  init_symbol(&symbols[2u], "EN_calc_result", SYM_PORT, &PORT_EN_calc_result, 1u);
  init_symbol(&symbols[3u], "EN_setParam", SYM_PORT, &PORT_EN_setParam, 1u);
  init_symbol(&symbols[4u], "fifo_in", SYM_MODULE, &INST_fifo_in);
  init_symbol(&symbols[5u], "fifo_out", SYM_MODULE, &INST_fifo_out);
  init_symbol(&symbols[6u], "params_0", SYM_MODULE, &INST_params_0);
  init_symbol(&symbols[7u], "params_1", SYM_MODULE, &INST_params_1);
  init_symbol(&symbols[8u], "params_2", SYM_MODULE, &INST_params_2);
  init_symbol(&symbols[9u], "RL_alltogether", SYM_RULE);
  init_symbol(&symbols[10u], "regs_0", SYM_MODULE, &INST_regs_0);
  init_symbol(&symbols[11u], "regs_1", SYM_MODULE, &INST_regs_1);
  init_symbol(&symbols[12u], "regs_2", SYM_MODULE, &INST_regs_2);
  init_symbol(&symbols[13u], "regs_3", SYM_MODULE, &INST_regs_3);
  init_symbol(&symbols[14u], "setParam_addr", SYM_PORT, &PORT_setParam_addr, 2u);
  init_symbol(&symbols[15u], "setParam_val", SYM_PORT, &PORT_setParam_val, 32u);
  init_symbol(&symbols[16u], "WILL_FIRE_calc_put", SYM_DEF, &DEF_WILL_FIRE_calc_put, 1u);
  init_symbol(&symbols[17u], "WILL_FIRE_calc_result", SYM_DEF, &DEF_WILL_FIRE_calc_result, 1u);
  init_symbol(&symbols[18u], "WILL_FIRE_setParam", SYM_DEF, &DEF_WILL_FIRE_setParam, 1u);
}


/* Rule actions */

void MOD_mkPipeline::RL_alltogether()
{
  tUInt32 DEF_regs_3_5_BITS_31_TO_0_7_PLUS_128___d38;
  tUInt64 DEF_regs_0_BIT_32_0_CONCAT_regs_0_BITS_31_TO_0_1_M_ETC___d15;
  tUInt64 DEF_fifo_in_notEmpty_CONCAT_fifo_in_first_PLUS_par_ETC___d8;
  tUInt64 DEF_regs_1_6_BIT_32_7_CONCAT_regs_1_6_BITS_31_TO_0_ETC___d22;
  tUInt64 DEF_regs_2_3_BIT_32_4_CONCAT_IF_regs_2_3_BIT_31_5__ETC___d34;
  tUInt32 DEF_IF_IF_regs_2_3_BIT_32_4_THEN_regs_2_3_BITS_31__ETC___d31;
  tUInt32 DEF_IF_regs_2_3_BIT_32_4_THEN_regs_2_3_BITS_31_TO__ETC___d27;
  tUInt8 DEF_regs_3_5_BIT_32___d36;
  tUInt32 DEF_b__h1305;
  tUInt32 DEF_b__h1519;
  tUInt32 DEF_b__h1742;
  tUInt32 DEF_b__h1961;
  tUInt8 DEF_fifo_in_notEmpty____d4;
  tUInt32 DEF_b__h1106;
  tUInt32 DEF_b__h1323;
  tUInt32 DEF_b__h1537;
  tUInt64 DEF_regs_0___d9;
  tUInt64 DEF_regs_1___d16;
  tUInt64 DEF_regs_2___d23;
  tUInt64 DEF_regs_3___d35;
  DEF_regs_3___d35 = INST_regs_3.METH_read();
  DEF_regs_2___d23 = INST_regs_2.METH_read();
  DEF_regs_1___d16 = INST_regs_1.METH_read();
  DEF_regs_0___d9 = INST_regs_0.METH_read();
  DEF_b__h1537 = INST_params_2.METH_read();
  DEF_b__h1106 = INST_params_0.METH_read();
  DEF_b__h1323 = INST_params_1.METH_read();
  DEF_fifo_in_notEmpty____d4 = INST_fifo_in.METH_notEmpty();
  DEF_b__h1961 = (tUInt32)(DEF_regs_3___d35);
  DEF_b__h1742 = (tUInt32)(DEF_regs_2___d23);
  DEF_b__h1519 = (tUInt32)(DEF_regs_1___d16);
  DEF_regs_3_5_BIT_32___d36 = (tUInt8)(DEF_regs_3___d35 >> 32u);
  DEF_b__h1305 = (tUInt32)(DEF_regs_0___d9);
  DEF_IF_regs_2_3_BIT_32_4_THEN_regs_2_3_BITS_31_TO__ETC___d27 = DEF_b__h1742;
  DEF_IF_IF_regs_2_3_BIT_32_4_THEN_regs_2_3_BITS_31__ETC___d31 = primShiftR32(32u,
									      32u,
									      (tUInt32)((tUInt8)(DEF_IF_regs_2_3_BIT_32_4_THEN_regs_2_3_BITS_31_TO__ETC___d27 >> 31u) ? -DEF_IF_regs_2_3_BIT_32_4_THEN_regs_2_3_BITS_31_TO__ETC___d27 : DEF_IF_regs_2_3_BIT_32_4_THEN_regs_2_3_BITS_31_TO__ETC___d27),
									      32u,
									      2u);
  DEF_regs_2_3_BIT_32_4_CONCAT_IF_regs_2_3_BIT_31_5__ETC___d34 = 8589934591llu & ((((tUInt64)((tUInt8)(DEF_regs_2___d23 >> 32u))) << 32u) | (tUInt64)((tUInt8)((tUInt8)1u & (DEF_regs_2___d23 >> 31u)) ? -DEF_IF_IF_regs_2_3_BIT_32_4_THEN_regs_2_3_BITS_31__ETC___d31 : DEF_IF_IF_regs_2_3_BIT_32_4_THEN_regs_2_3_BITS_31__ETC___d31));
  DEF_regs_1_6_BIT_32_7_CONCAT_regs_1_6_BITS_31_TO_0_ETC___d22 = 8589934591llu & ((((tUInt64)((tUInt8)(DEF_regs_1___d16 >> 32u))) << 32u) | (tUInt64)((tUInt32)(((tUInt64)(DEF_b__h1519)) * ((tUInt64)(DEF_b__h1537)))));
  DEF_fifo_in_notEmpty_CONCAT_fifo_in_first_PLUS_par_ETC___d8 = 8589934591llu & ((((tUInt64)(DEF_fifo_in_notEmpty____d4)) << 32u) | (tUInt64)(INST_fifo_in.METH_first() + DEF_b__h1106));
  DEF_regs_3_5_BITS_31_TO_0_7_PLUS_128___d38 = DEF_b__h1961 + 128u;
  DEF_regs_0_BIT_32_0_CONCAT_regs_0_BITS_31_TO_0_1_M_ETC___d15 = 8589934591llu & ((((tUInt64)((tUInt8)(DEF_regs_0___d9 >> 32u))) << 32u) | (tUInt64)((tUInt32)(((tUInt64)(DEF_b__h1305)) * ((tUInt64)(DEF_b__h1323)))));
  INST_regs_0.METH_write(DEF_fifo_in_notEmpty_CONCAT_fifo_in_first_PLUS_par_ETC___d8);
  if (DEF_fifo_in_notEmpty____d4)
    INST_fifo_in.METH_deq();
  INST_regs_1.METH_write(DEF_regs_0_BIT_32_0_CONCAT_regs_0_BITS_31_TO_0_1_M_ETC___d15);
  INST_regs_2.METH_write(DEF_regs_1_6_BIT_32_7_CONCAT_regs_1_6_BITS_31_TO_0_ETC___d22);
  INST_regs_3.METH_write(DEF_regs_2_3_BIT_32_4_CONCAT_IF_regs_2_3_BIT_31_5__ETC___d34);
  if (DEF_regs_3_5_BIT_32___d36)
    INST_fifo_out.METH_enq(DEF_regs_3_5_BITS_31_TO_0_7_PLUS_128___d38);
}


/* Methods */

void MOD_mkPipeline::METH_calc_put(tUInt32 ARG_calc_put_x)
{
  PORT_EN_calc_put = (tUInt8)1u;
  DEF_WILL_FIRE_calc_put = (tUInt8)1u;
  PORT_calc_put_x = ARG_calc_put_x;
  INST_fifo_in.METH_enq(ARG_calc_put_x);
}

tUInt8 MOD_mkPipeline::METH_RDY_calc_put()
{
  tUInt8 PORT_RDY_calc_put;
  tUInt8 DEF_CAN_FIRE_calc_put;
  DEF_CAN_FIRE_calc_put = INST_fifo_in.METH_i_notFull();
  PORT_RDY_calc_put = DEF_CAN_FIRE_calc_put;
  return PORT_RDY_calc_put;
}

tUInt32 MOD_mkPipeline::METH_calc_result()
{
  tUInt32 DEF_calc_result__avValue1;
  tUInt32 PORT_calc_result;
  PORT_EN_calc_result = (tUInt8)1u;
  DEF_WILL_FIRE_calc_result = (tUInt8)1u;
  DEF_calc_result__avValue1 = INST_fifo_out.METH_first();
  PORT_calc_result = DEF_calc_result__avValue1;
  INST_fifo_out.METH_deq();
  return PORT_calc_result;
}

tUInt8 MOD_mkPipeline::METH_RDY_calc_result()
{
  tUInt8 PORT_RDY_calc_result;
  tUInt8 DEF_CAN_FIRE_calc_result;
  DEF_CAN_FIRE_calc_result = INST_fifo_out.METH_i_notEmpty();
  PORT_RDY_calc_result = DEF_CAN_FIRE_calc_result;
  return PORT_RDY_calc_result;
}

void MOD_mkPipeline::METH_setParam(tUInt8 ARG_setParam_addr, tUInt32 ARG_setParam_val)
{
  tUInt8 DEF_setParam_addr_EQ_0___d39;
  tUInt8 DEF_setParam_addr_EQ_1___d40;
  tUInt8 DEF_setParam_addr_EQ_2___d41;
  PORT_EN_setParam = (tUInt8)1u;
  DEF_WILL_FIRE_setParam = (tUInt8)1u;
  PORT_setParam_addr = ARG_setParam_addr;
  PORT_setParam_val = ARG_setParam_val;
  DEF_setParam_addr_EQ_2___d41 = ARG_setParam_addr == (tUInt8)2u;
  DEF_setParam_addr_EQ_1___d40 = ARG_setParam_addr == (tUInt8)1u;
  DEF_setParam_addr_EQ_0___d39 = ARG_setParam_addr == (tUInt8)0u;
  if (DEF_setParam_addr_EQ_0___d39)
    INST_params_0.METH_write(ARG_setParam_val);
  if (DEF_setParam_addr_EQ_1___d40)
    INST_params_1.METH_write(ARG_setParam_val);
  if (DEF_setParam_addr_EQ_2___d41)
    INST_params_2.METH_write(ARG_setParam_val);
}

tUInt8 MOD_mkPipeline::METH_RDY_setParam()
{
  tUInt8 PORT_RDY_setParam;
  tUInt8 DEF_CAN_FIRE_setParam;
  DEF_CAN_FIRE_setParam = (tUInt8)1u;
  PORT_RDY_setParam = DEF_CAN_FIRE_setParam;
  return PORT_RDY_setParam;
}


/* Reset routines */

void MOD_mkPipeline::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_regs_3.reset_RST(ARG_rst_in);
  INST_regs_2.reset_RST(ARG_rst_in);
  INST_regs_1.reset_RST(ARG_rst_in);
  INST_regs_0.reset_RST(ARG_rst_in);
  INST_fifo_out.reset_RST(ARG_rst_in);
  INST_fifo_in.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkPipeline::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkPipeline::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_fifo_in.dump_state(indent + 2u);
  INST_fifo_out.dump_state(indent + 2u);
  INST_params_0.dump_state(indent + 2u);
  INST_params_1.dump_state(indent + 2u);
  INST_params_2.dump_state(indent + 2u);
  INST_regs_0.dump_state(indent + 2u);
  INST_regs_1.dump_state(indent + 2u);
  INST_regs_2.dump_state(indent + 2u);
  INST_regs_3.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkPipeline::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 19u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_calc_put", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_calc_result", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_setParam", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "EN_calc_put", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "EN_calc_result", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "EN_setParam", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "calc_put_x", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "setParam_addr", 2u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "setParam_val", 32u);
  num = INST_fifo_in.dump_VCD_defs(num);
  num = INST_fifo_out.dump_VCD_defs(num);
  num = INST_params_0.dump_VCD_defs(num);
  num = INST_params_1.dump_VCD_defs(num);
  num = INST_params_2.dump_VCD_defs(num);
  num = INST_regs_0.dump_VCD_defs(num);
  num = INST_regs_1.dump_VCD_defs(num);
  num = INST_regs_2.dump_VCD_defs(num);
  num = INST_regs_3.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkPipeline::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkPipeline &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkPipeline::vcd_defs(tVCDDumpType dt, MOD_mkPipeline &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 2u);
    vcd_write_x(sim_hdl, num++, 32u);
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
      if ((backing.DEF_WILL_FIRE_calc_put) != DEF_WILL_FIRE_calc_put)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_calc_put, 1u);
	backing.DEF_WILL_FIRE_calc_put = DEF_WILL_FIRE_calc_put;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_calc_result) != DEF_WILL_FIRE_calc_result)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_calc_result, 1u);
	backing.DEF_WILL_FIRE_calc_result = DEF_WILL_FIRE_calc_result;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_setParam) != DEF_WILL_FIRE_setParam)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_setParam, 1u);
	backing.DEF_WILL_FIRE_setParam = DEF_WILL_FIRE_setParam;
      }
      ++num;
      if ((backing.PORT_EN_calc_put) != PORT_EN_calc_put)
      {
	vcd_write_val(sim_hdl, num, PORT_EN_calc_put, 1u);
	backing.PORT_EN_calc_put = PORT_EN_calc_put;
      }
      ++num;
      if ((backing.PORT_EN_calc_result) != PORT_EN_calc_result)
      {
	vcd_write_val(sim_hdl, num, PORT_EN_calc_result, 1u);
	backing.PORT_EN_calc_result = PORT_EN_calc_result;
      }
      ++num;
      if ((backing.PORT_EN_setParam) != PORT_EN_setParam)
      {
	vcd_write_val(sim_hdl, num, PORT_EN_setParam, 1u);
	backing.PORT_EN_setParam = PORT_EN_setParam;
      }
      ++num;
      if ((backing.PORT_calc_put_x) != PORT_calc_put_x)
      {
	vcd_write_val(sim_hdl, num, PORT_calc_put_x, 32u);
	backing.PORT_calc_put_x = PORT_calc_put_x;
      }
      ++num;
      if ((backing.PORT_setParam_addr) != PORT_setParam_addr)
      {
	vcd_write_val(sim_hdl, num, PORT_setParam_addr, 2u);
	backing.PORT_setParam_addr = PORT_setParam_addr;
      }
      ++num;
      if ((backing.PORT_setParam_val) != PORT_setParam_val)
      {
	vcd_write_val(sim_hdl, num, PORT_setParam_val, 32u);
	backing.PORT_setParam_val = PORT_setParam_val;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_calc_put, 1u);
      backing.DEF_WILL_FIRE_calc_put = DEF_WILL_FIRE_calc_put;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_calc_result, 1u);
      backing.DEF_WILL_FIRE_calc_result = DEF_WILL_FIRE_calc_result;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_setParam, 1u);
      backing.DEF_WILL_FIRE_setParam = DEF_WILL_FIRE_setParam;
      vcd_write_val(sim_hdl, num++, PORT_EN_calc_put, 1u);
      backing.PORT_EN_calc_put = PORT_EN_calc_put;
      vcd_write_val(sim_hdl, num++, PORT_EN_calc_result, 1u);
      backing.PORT_EN_calc_result = PORT_EN_calc_result;
      vcd_write_val(sim_hdl, num++, PORT_EN_setParam, 1u);
      backing.PORT_EN_setParam = PORT_EN_setParam;
      vcd_write_val(sim_hdl, num++, PORT_calc_put_x, 32u);
      backing.PORT_calc_put_x = PORT_calc_put_x;
      vcd_write_val(sim_hdl, num++, PORT_setParam_addr, 2u);
      backing.PORT_setParam_addr = PORT_setParam_addr;
      vcd_write_val(sim_hdl, num++, PORT_setParam_val, 32u);
      backing.PORT_setParam_val = PORT_setParam_val;
    }
}

void MOD_mkPipeline::vcd_prims(tVCDDumpType dt, MOD_mkPipeline &backing)
{
  INST_fifo_in.dump_VCD(dt, backing.INST_fifo_in);
  INST_fifo_out.dump_VCD(dt, backing.INST_fifo_out);
  INST_params_0.dump_VCD(dt, backing.INST_params_0);
  INST_params_1.dump_VCD(dt, backing.INST_params_1);
  INST_params_2.dump_VCD(dt, backing.INST_params_2);
  INST_regs_0.dump_VCD(dt, backing.INST_regs_0);
  INST_regs_1.dump_VCD(dt, backing.INST_regs_1);
  INST_regs_2.dump_VCD(dt, backing.INST_regs_2);
  INST_regs_3.dump_VCD(dt, backing.INST_regs_3);
}

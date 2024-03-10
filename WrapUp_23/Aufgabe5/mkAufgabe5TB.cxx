/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Mon Feb 12 13:23:00 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkAufgabe5TB.h"


/* String declarations */
static std::string const __str_literal_1("%b", 2u);


/* Constructor */
MOD_mkAufgabe5TB::MOD_mkAufgabe5TB(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_cinter(simHdl, "cinter", this, 32u, 0u, (tUInt8)0u),
    INST_count(simHdl, "count", this, 32u, 0u, (tUInt8)0u),
    INST_dut_ctr(simHdl, "dut_ctr", this, 32u, 0u, (tUInt8)0u),
    INST_dut_fifo(simHdl, "dut_fifo", this, 8u, 2u, (tUInt8)1u, 0u),
    INST_dut_fifoout(simHdl, "dut_fifoout", this, 8u),
    INST_dut_pinvalue(simHdl, "dut_pinvalue", this, 1u),
    INST_dut_state(simHdl, "dut_state", this, 2u, (tUInt8)0u, (tUInt8)0u),
    INST_dut_ticks(simHdl, "dut_ticks", this, 32u, 16u, (tUInt8)0u),
    INST_state(simHdl, "state", this, 32u, 0u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u),
    DEF_v__h1137(12297829382473034410llu)
{
  symbol_count = 20u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkAufgabe5TB::init_symbols_0()
{
  init_symbol(&symbols[0u], "b__h1012", SYM_DEF, &DEF_b__h1012, 32u);
  init_symbol(&symbols[1u], "b__h1047", SYM_DEF, &DEF_b__h1047, 32u);
  init_symbol(&symbols[2u], "b__h308", SYM_DEF, &DEF_b__h308, 32u);
  init_symbol(&symbols[3u], "cinter", SYM_MODULE, &INST_cinter);
  init_symbol(&symbols[4u], "count", SYM_MODULE, &INST_count);
  init_symbol(&symbols[5u], "dut_ctr", SYM_MODULE, &INST_dut_ctr);
  init_symbol(&symbols[6u], "dut_fifo", SYM_MODULE, &INST_dut_fifo);
  init_symbol(&symbols[7u], "dut_fifoout", SYM_MODULE, &INST_dut_fifoout);
  init_symbol(&symbols[8u], "dut_pinvalue", SYM_MODULE, &INST_dut_pinvalue);
  init_symbol(&symbols[9u], "dut_state", SYM_MODULE, &INST_dut_state);
  init_symbol(&symbols[10u], "dut_ticks", SYM_MODULE, &INST_dut_ticks);
  init_symbol(&symbols[11u], "RL_counter", SYM_RULE);
  init_symbol(&symbols[12u], "RL_dut_ende", SYM_RULE);
  init_symbol(&symbols[13u], "RL_dut_idle", SYM_RULE);
  init_symbol(&symbols[14u], "RL_dut_start", SYM_RULE);
  init_symbol(&symbols[15u], "RL_dut_ticrule", SYM_RULE);
  init_symbol(&symbols[16u], "RL_dut_transfer", SYM_RULE);
  init_symbol(&symbols[17u], "RL_r1", SYM_RULE);
  init_symbol(&symbols[18u], "RL_stop", SYM_RULE);
  init_symbol(&symbols[19u], "state", SYM_MODULE, &INST_state);
}


/* Rule actions */

void MOD_mkAufgabe5TB::RL_dut_ticrule()
{
  tUInt32 DEF_dut_ticks_MINUS_1___d4;
  DEF_b__h308 = INST_dut_ticks.METH_read();
  DEF_dut_ticks_MINUS_1___d4 = DEF_b__h308 - 1u;
  INST_dut_ticks.METH_write(DEF_dut_ticks_MINUS_1___d4);
}

void MOD_mkAufgabe5TB::RL_dut_idle()
{
  tUInt8 DEF_dut_fifo_notEmpty____d8;
  DEF_dut_fifo_notEmpty____d8 = INST_dut_fifo.METH_notEmpty();
  INST_dut_ticks.METH_write(16u);
  INST_dut_pinvalue.METH_write((tUInt8)1u);
  if (DEF_dut_fifo_notEmpty____d8)
    INST_dut_state.METH_write((tUInt8)1u);
}

void MOD_mkAufgabe5TB::RL_dut_start()
{
  INST_dut_ticks.METH_write(16u);
  INST_dut_pinvalue.METH_write((tUInt8)0u);
  INST_dut_state.METH_write((tUInt8)2u);
}

void MOD_mkAufgabe5TB::RL_dut_transfer()
{
  tUInt32 DEF_dut_ctr_5_PLUS_1___d16;
  tUInt8 DEF_dut_ctr_5_SLT_9___d18;
  tUInt8 DEF_NOT_dut_ctr_5_SLT_9_8___d22;
  tUInt8 DEF_x__h663;
  tUInt8 DEF_dut_ctr_5_BITS_2_TO_0___d20;
  tUInt8 DEF_x__h602;
  tUInt8 DEF_bs__h678;
  tUInt32 DEF_x__h708;
  DEF_x__h708 = INST_dut_ctr.METH_read();
  DEF_bs__h678 = INST_dut_fifoout.METH_read();
  DEF_x__h602 = INST_dut_fifo.METH_first();
  DEF_dut_ctr_5_BITS_2_TO_0___d20 = (tUInt8)((tUInt8)7u & DEF_x__h708);
  DEF_x__h663 = primExtract8(1u,
			     8u,
			     (tUInt8)(DEF_bs__h678),
			     3u,
			     (tUInt8)(DEF_dut_ctr_5_BITS_2_TO_0___d20),
			     3u,
			     (tUInt8)(DEF_dut_ctr_5_BITS_2_TO_0___d20));
  DEF_dut_ctr_5_SLT_9___d18 = primSLT8(1u, 32u, (tUInt32)(DEF_x__h708), 32u, 9u);
  DEF_NOT_dut_ctr_5_SLT_9_8___d22 = !DEF_dut_ctr_5_SLT_9___d18;
  DEF_dut_ctr_5_PLUS_1___d16 = DEF_x__h708 + 1u;
  INST_dut_ticks.METH_write(16u);
  INST_dut_ctr.METH_write(DEF_dut_ctr_5_PLUS_1___d16);
  INST_dut_fifo.METH_deq();
  INST_dut_fifoout.METH_write(DEF_x__h602);
  if (DEF_NOT_dut_ctr_5_SLT_9_8___d22)
    INST_dut_state.METH_write((tUInt8)3u);
  if (DEF_dut_ctr_5_SLT_9___d18)
    INST_dut_pinvalue.METH_write(DEF_x__h663);
}

void MOD_mkAufgabe5TB::RL_dut_ende()
{
  INST_dut_fifo.METH_deq();
  INST_dut_ctr.METH_write(0u);
  INST_dut_ticks.METH_write(16u);
  INST_dut_pinvalue.METH_write((tUInt8)1u);
  INST_dut_state.METH_write((tUInt8)0u);
}

void MOD_mkAufgabe5TB::RL_counter()
{
  tUInt32 DEF_count_7_PLUS_1___d28;
  tUInt32 DEF_cinter_9_PLUS_1___d30;
  tUInt8 DEF_count_7_EQ_100___d31;
  DEF_b__h1047 = INST_cinter.METH_read();
  DEF_b__h1012 = INST_count.METH_read();
  DEF_count_7_EQ_100___d31 = DEF_b__h1012 == 100u;
  DEF_cinter_9_PLUS_1___d30 = DEF_b__h1047 + 1u;
  DEF_count_7_PLUS_1___d28 = DEF_b__h1012 + 1u;
  INST_count.METH_write(DEF_count_7_PLUS_1___d28);
  INST_cinter.METH_write(DEF_cinter_9_PLUS_1___d30);
  if (DEF_count_7_EQ_100___d31)
    INST_dut_fifo.METH_enq((tUInt8)85u);
}

void MOD_mkAufgabe5TB::RL_stop()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_finish(sim_hdl, "32", 0u);
}

void MOD_mkAufgabe5TB::RL_r1()
{
  tUInt8 DEF_x__h1133;
  DEF_x__h1133 = INST_dut_pinvalue.METH_read();
  INST_cinter.METH_write(0u);
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h1137 = dollar_time(sim_hdl);
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s,1,64", &__str_literal_1, DEF_x__h1133, DEF_v__h1137);
}


/* Methods */


/* Reset routines */

void MOD_mkAufgabe5TB::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_state.reset_RST(ARG_rst_in);
  INST_dut_ticks.reset_RST(ARG_rst_in);
  INST_dut_state.reset_RST(ARG_rst_in);
  INST_dut_fifo.reset_RST(ARG_rst_in);
  INST_dut_ctr.reset_RST(ARG_rst_in);
  INST_count.reset_RST(ARG_rst_in);
  INST_cinter.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkAufgabe5TB::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkAufgabe5TB::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_cinter.dump_state(indent + 2u);
  INST_count.dump_state(indent + 2u);
  INST_dut_ctr.dump_state(indent + 2u);
  INST_dut_fifo.dump_state(indent + 2u);
  INST_dut_fifoout.dump_state(indent + 2u);
  INST_dut_pinvalue.dump_state(indent + 2u);
  INST_dut_state.dump_state(indent + 2u);
  INST_dut_ticks.dump_state(indent + 2u);
  INST_state.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkAufgabe5TB::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 14u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "b__h1012", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "b__h1047", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "b__h308", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h1137", 64u);
  num = INST_cinter.dump_VCD_defs(num);
  num = INST_count.dump_VCD_defs(num);
  num = INST_dut_ctr.dump_VCD_defs(num);
  num = INST_dut_fifo.dump_VCD_defs(num);
  num = INST_dut_fifoout.dump_VCD_defs(num);
  num = INST_dut_pinvalue.dump_VCD_defs(num);
  num = INST_dut_state.dump_VCD_defs(num);
  num = INST_dut_ticks.dump_VCD_defs(num);
  num = INST_state.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkAufgabe5TB::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkAufgabe5TB &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkAufgabe5TB::vcd_defs(tVCDDumpType dt, MOD_mkAufgabe5TB &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 64u);
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
      if ((backing.DEF_b__h1012) != DEF_b__h1012)
      {
	vcd_write_val(sim_hdl, num, DEF_b__h1012, 32u);
	backing.DEF_b__h1012 = DEF_b__h1012;
      }
      ++num;
      if ((backing.DEF_b__h1047) != DEF_b__h1047)
      {
	vcd_write_val(sim_hdl, num, DEF_b__h1047, 32u);
	backing.DEF_b__h1047 = DEF_b__h1047;
      }
      ++num;
      if ((backing.DEF_b__h308) != DEF_b__h308)
      {
	vcd_write_val(sim_hdl, num, DEF_b__h308, 32u);
	backing.DEF_b__h308 = DEF_b__h308;
      }
      ++num;
      if ((backing.DEF_v__h1137) != DEF_v__h1137)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h1137, 64u);
	backing.DEF_v__h1137 = DEF_v__h1137;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_b__h1012, 32u);
      backing.DEF_b__h1012 = DEF_b__h1012;
      vcd_write_val(sim_hdl, num++, DEF_b__h1047, 32u);
      backing.DEF_b__h1047 = DEF_b__h1047;
      vcd_write_val(sim_hdl, num++, DEF_b__h308, 32u);
      backing.DEF_b__h308 = DEF_b__h308;
      vcd_write_val(sim_hdl, num++, DEF_v__h1137, 64u);
      backing.DEF_v__h1137 = DEF_v__h1137;
    }
}

void MOD_mkAufgabe5TB::vcd_prims(tVCDDumpType dt, MOD_mkAufgabe5TB &backing)
{
  INST_cinter.dump_VCD(dt, backing.INST_cinter);
  INST_count.dump_VCD(dt, backing.INST_count);
  INST_dut_ctr.dump_VCD(dt, backing.INST_dut_ctr);
  INST_dut_fifo.dump_VCD(dt, backing.INST_dut_fifo);
  INST_dut_fifoout.dump_VCD(dt, backing.INST_dut_fifoout);
  INST_dut_pinvalue.dump_VCD(dt, backing.INST_dut_pinvalue);
  INST_dut_state.dump_VCD(dt, backing.INST_dut_state);
  INST_dut_ticks.dump_VCD(dt, backing.INST_dut_ticks);
  INST_state.dump_VCD(dt, backing.INST_state);
}

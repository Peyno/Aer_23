/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Wed Feb 14 18:26:12 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTB1.h"


/* String declarations */
static std::string const __str_literal_1("%d", 2u);


/* Constructor */
MOD_mkTB1::MOD_mkTB1(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_cntr(simHdl, "cntr", this, 32u, 0u, (tUInt8)0u),
    INST_dut_cntr(simHdl, "dut_cntr", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_dut_queue(simHdl, "dut_queue", this, 1u, 2u, (tUInt8)1u, 0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 7u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTB1::init_symbols_0()
{
  init_symbol(&symbols[0u], "cntr", SYM_MODULE, &INST_cntr);
  init_symbol(&symbols[1u], "dut_cntr", SYM_MODULE, &INST_dut_cntr);
  init_symbol(&symbols[2u], "dut_queue", SYM_MODULE, &INST_dut_queue);
  init_symbol(&symbols[3u], "RL_dut_r1", SYM_RULE);
  init_symbol(&symbols[4u], "RL_dut_switch", SYM_RULE);
  init_symbol(&symbols[5u], "RL_r", SYM_RULE);
  init_symbol(&symbols[6u], "RL_r1", SYM_RULE);
}


/* Rule actions */

void MOD_mkTB1::RL_dut_switch()
{
  tUInt8 DEF_NOT_dut_cntr___d3;
  DEF__read__h153 = INST_dut_cntr.METH_read();
  DEF_NOT_dut_cntr___d3 = !DEF__read__h153;
  INST_dut_queue.METH_enq(DEF_NOT_dut_cntr___d3);
}

void MOD_mkTB1::RL_dut_r1()
{
  tUInt8 DEF_x__h198;
  DEF__read__h153 = INST_dut_cntr.METH_read();
  DEF_x__h198 = (tUInt8)1u & (DEF__read__h153 + (tUInt8)1u);
  INST_dut_cntr.METH_write(DEF_x__h198);
}

void MOD_mkTB1::RL_r()
{
  tUInt8 DEF_dut_queue_first____d6;
  DEF_dut_queue_first____d6 = INST_dut_queue.METH_first();
  INST_dut_queue.METH_deq();
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s,1", &__str_literal_1, DEF_dut_queue_first____d6);
}

void MOD_mkTB1::RL_r1()
{
  tUInt32 DEF_cntr_PLUS_1___d8;
  tUInt8 DEF_cntr_EQ_10___d9;
  tUInt32 DEF_b__h337;
  DEF_b__h337 = INST_cntr.METH_read();
  DEF_cntr_EQ_10___d9 = DEF_b__h337 == 10u;
  DEF_cntr_PLUS_1___d8 = DEF_b__h337 + 1u;
  INST_cntr.METH_write(DEF_cntr_PLUS_1___d8);
  if (!(PORT_RST_N == (tUInt8)0u))
    if (DEF_cntr_EQ_10___d9)
      dollar_finish(sim_hdl, "32", 0u);
}


/* Methods */


/* Reset routines */

void MOD_mkTB1::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_dut_queue.reset_RST(ARG_rst_in);
  INST_dut_cntr.reset_RST(ARG_rst_in);
  INST_cntr.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTB1::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTB1::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_cntr.dump_state(indent + 2u);
  INST_dut_cntr.dump_state(indent + 2u);
  INST_dut_queue.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTB1::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 5u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "_read__h153", 1u);
  num = INST_cntr.dump_VCD_defs(num);
  num = INST_dut_cntr.dump_VCD_defs(num);
  num = INST_dut_queue.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTB1::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTB1 &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTB1::vcd_defs(tVCDDumpType dt, MOD_mkTB1 &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
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
      if ((backing.DEF__read__h153) != DEF__read__h153)
      {
	vcd_write_val(sim_hdl, num, DEF__read__h153, 1u);
	backing.DEF__read__h153 = DEF__read__h153;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF__read__h153, 1u);
      backing.DEF__read__h153 = DEF__read__h153;
    }
}

void MOD_mkTB1::vcd_prims(tVCDDumpType dt, MOD_mkTB1 &backing)
{
  INST_cntr.dump_VCD(dt, backing.INST_cntr);
  INST_dut_cntr.dump_VCD(dt, backing.INST_dut_cntr);
  INST_dut_queue.dump_VCD(dt, backing.INST_dut_queue);
}

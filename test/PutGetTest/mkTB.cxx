/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Thu Feb 15 17:23:07 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTB.h"


/* String declarations */
static std::string const __str_literal_2("Wert = %d", 9u);
static std::string const __str_literal_1("\303\266alsdj", 7u);


/* Constructor */
MOD_mkTB::MOD_mkTB(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_server_fifo_in(simHdl, "server_fifo_in", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_server_fifo_out(simHdl, "server_fifo_out", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_w(simHdl, "w", this, 32u, 0u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 7u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTB::init_symbols_0()
{
  init_symbol(&symbols[0u], "RL_r1", SYM_RULE);
  init_symbol(&symbols[1u], "RL_r2", SYM_RULE);
  init_symbol(&symbols[2u], "RL_r3", SYM_RULE);
  init_symbol(&symbols[3u], "RL_server_do_sth", SYM_RULE);
  init_symbol(&symbols[4u], "server_fifo_in", SYM_MODULE, &INST_server_fifo_in);
  init_symbol(&symbols[5u], "server_fifo_out", SYM_MODULE, &INST_server_fifo_out);
  init_symbol(&symbols[6u], "w", SYM_MODULE, &INST_w);
}


/* Rule actions */

void MOD_mkTB::RL_server_do_sth()
{
  tUInt32 DEF_server_fifo_in_first____d4;
  DEF_server_fifo_in_first____d4 = INST_server_fifo_in.METH_first();
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s", &__str_literal_1);
  INST_server_fifo_in.METH_deq();
  INST_server_fifo_out.METH_enq(DEF_server_fifo_in_first____d4);
}

void MOD_mkTB::RL_r1()
{
  INST_server_fifo_in.METH_enq(10u);
}

void MOD_mkTB::RL_r2()
{
  tUInt32 DEF_server_fifo_out_first____d7;
  DEF_server_fifo_out_first____d7 = INST_server_fifo_out.METH_first();
  INST_server_fifo_out.METH_deq();
  INST_w.METH_port0__write(DEF_server_fifo_out_first____d7);
}

void MOD_mkTB::RL_r3()
{
  tUInt32 DEF_b__h577;
  tUInt32 DEF_signed_w_port1__read___d9;
  DEF_b__h577 = INST_w.METH_port1__read();
  DEF_signed_w_port1__read___d9 = DEF_b__h577;
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s,-32", &__str_literal_2, DEF_signed_w_port1__read___d9);
}


/* Methods */


/* Reset routines */

void MOD_mkTB::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_w.reset_RST(ARG_rst_in);
  INST_server_fifo_out.reset_RST(ARG_rst_in);
  INST_server_fifo_in.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTB::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTB::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_server_fifo_in.dump_state(indent + 2u);
  INST_server_fifo_out.dump_state(indent + 2u);
  INST_w.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTB::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 4u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  num = INST_server_fifo_in.dump_VCD_defs(num);
  num = INST_server_fifo_out.dump_VCD_defs(num);
  num = INST_w.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTB::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTB &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTB::vcd_defs(tVCDDumpType dt, MOD_mkTB &backing)
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

void MOD_mkTB::vcd_prims(tVCDDumpType dt, MOD_mkTB &backing)
{
  INST_server_fifo_in.dump_VCD(dt, backing.INST_server_fifo_in);
  INST_server_fifo_out.dump_VCD(dt, backing.INST_server_fifo_out);
  INST_w.dump_VCD(dt, backing.INST_w);
}

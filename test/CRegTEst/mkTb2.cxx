/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Wed Feb  7 13:13:32 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTb2.h"


/* String declarations */
static std::string const __str_literal_1("Ergebnis: %d", 12u);


/* Constructor */
MOD_mkTb2::MOD_mkTb2(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_a(simHdl, "a", this, 32u, 5u, (tUInt8)0u),
    INST_uut_counter_value(simHdl, "uut_counter_value", this, 32u, 0u, (tUInt8)0u),
    INST_uut_in(simHdl, "uut_in", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_uut_out(simHdl, "uut_out", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_uut_t(simHdl, "uut_t", this, 32u, 0u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 9u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTb2::init_symbols_0()
{
  init_symbol(&symbols[0u], "a", SYM_MODULE, &INST_a);
  init_symbol(&symbols[1u], "RL_r1", SYM_RULE);
  init_symbol(&symbols[2u], "RL_r2", SYM_RULE);
  init_symbol(&symbols[3u], "RL_uut_r1", SYM_RULE);
  init_symbol(&symbols[4u], "RL_uut_r2", SYM_RULE);
  init_symbol(&symbols[5u], "uut_counter_value", SYM_MODULE, &INST_uut_counter_value);
  init_symbol(&symbols[6u], "uut_in", SYM_MODULE, &INST_uut_in);
  init_symbol(&symbols[7u], "uut_out", SYM_MODULE, &INST_uut_out);
  init_symbol(&symbols[8u], "uut_t", SYM_MODULE, &INST_uut_t);
}


/* Rule actions */

void MOD_mkTb2::RL_uut_r1()
{
  tUInt32 DEF_uut_counter_value_port1__read_PLUS_5___d3;
  tUInt32 DEF_b__h545;
  DEF_b__h545 = INST_uut_counter_value.METH_port1__read();
  DEF_uut_counter_value_port1__read_PLUS_5___d3 = DEF_b__h545 + 5u;
  INST_uut_in.METH_deq();
  INST_uut_counter_value.METH_port1__write(DEF_uut_counter_value_port1__read_PLUS_5___d3);
}

void MOD_mkTb2::RL_uut_r2()
{
  tUInt32 DEF_b__h597;
  tUInt32 DEF_b__h607;
  DEF_b__h607 = INST_uut_t.METH_read();
  DEF_b__h597 = INST_uut_counter_value.METH_port3__read();
  INST_uut_t.METH_write(DEF_b__h597);
  INST_uut_out.METH_enq(DEF_b__h607);
}

void MOD_mkTb2::RL_r1()
{
  tUInt32 DEF_b__h672;
  DEF_b__h672 = INST_a.METH_read();
  INST_uut_in.METH_enq(DEF_b__h672);
}

void MOD_mkTb2::RL_r2()
{
  tUInt32 DEF_signed_uut_out_first__0___d11;
  DEF_signed_uut_out_first__0___d11 = INST_uut_out.METH_first();
  INST_uut_out.METH_deq();
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_uut_out_first__0___d11);
}


/* Methods */


/* Reset routines */

void MOD_mkTb2::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_uut_t.reset_RST(ARG_rst_in);
  INST_uut_out.reset_RST(ARG_rst_in);
  INST_uut_in.reset_RST(ARG_rst_in);
  INST_uut_counter_value.reset_RST(ARG_rst_in);
  INST_a.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTb2::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTb2::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_a.dump_state(indent + 2u);
  INST_uut_counter_value.dump_state(indent + 2u);
  INST_uut_in.dump_state(indent + 2u);
  INST_uut_out.dump_state(indent + 2u);
  INST_uut_t.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTb2::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 6u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  num = INST_a.dump_VCD_defs(num);
  num = INST_uut_counter_value.dump_VCD_defs(num);
  num = INST_uut_in.dump_VCD_defs(num);
  num = INST_uut_out.dump_VCD_defs(num);
  num = INST_uut_t.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTb2::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTb2 &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTb2::vcd_defs(tVCDDumpType dt, MOD_mkTb2 &backing)
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

void MOD_mkTb2::vcd_prims(tVCDDumpType dt, MOD_mkTb2 &backing)
{
  INST_a.dump_VCD(dt, backing.INST_a);
  INST_uut_counter_value.dump_VCD(dt, backing.INST_uut_counter_value);
  INST_uut_in.dump_VCD(dt, backing.INST_uut_in);
  INST_uut_out.dump_VCD(dt, backing.INST_uut_out);
  INST_uut_t.dump_VCD(dt, backing.INST_uut_t);
}
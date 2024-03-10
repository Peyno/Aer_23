/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Fri Feb  9 18:22:47 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTb2.h"


/* String declarations */
static std::string const __str_literal_1("%d", 2u);


/* Constructor */
MOD_mkTb2::MOD_mkTb2(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_c(simHdl, "c", this, 32u, 0u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 11u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTb2::init_symbols_0()
{
  init_symbol(&symbols[0u], "c", SYM_MODULE, &INST_c);
  init_symbol(&symbols[1u], "RL_r1", SYM_RULE);
  init_symbol(&symbols[2u], "RL_r1_1", SYM_RULE);
  init_symbol(&symbols[3u], "RL_r1_2", SYM_RULE);
  init_symbol(&symbols[4u], "RL_r1_3", SYM_RULE);
  init_symbol(&symbols[5u], "RL_r1_4", SYM_RULE);
  init_symbol(&symbols[6u], "RL_r1_5", SYM_RULE);
  init_symbol(&symbols[7u], "RL_r1_6", SYM_RULE);
  init_symbol(&symbols[8u], "RL_r1_7", SYM_RULE);
  init_symbol(&symbols[9u], "RL_r1_8", SYM_RULE);
  init_symbol(&symbols[10u], "RL_r1_9", SYM_RULE);
}


/* Rule actions */

void MOD_mkTb2::RL_r1()
{
  tUInt32 DEF_signed_0___d1;
  DEF_signed_0___d1 = 0u;
  dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_0___d1);
}

void MOD_mkTb2::RL_r1_1()
{
  tUInt32 DEF_signed_1___d2;
  DEF_signed_1___d2 = 1u;
  dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_1___d2);
}

void MOD_mkTb2::RL_r1_2()
{
  tUInt32 DEF_signed_2___d3;
  DEF_signed_2___d3 = 2u;
  dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_2___d3);
}

void MOD_mkTb2::RL_r1_3()
{
  tUInt32 DEF_signed_3___d4;
  DEF_signed_3___d4 = 3u;
  dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_3___d4);
}

void MOD_mkTb2::RL_r1_4()
{
  tUInt32 DEF_signed_4___d5;
  DEF_signed_4___d5 = 4u;
  dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_4___d5);
}

void MOD_mkTb2::RL_r1_5()
{
  tUInt32 DEF_signed_5___d6;
  DEF_signed_5___d6 = 5u;
  dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_5___d6);
}

void MOD_mkTb2::RL_r1_6()
{
  tUInt32 DEF_signed_6___d7;
  DEF_signed_6___d7 = 6u;
  dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_6___d7);
}

void MOD_mkTb2::RL_r1_7()
{
  tUInt32 DEF_signed_7___d8;
  DEF_signed_7___d8 = 7u;
  dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_7___d8);
}

void MOD_mkTb2::RL_r1_8()
{
  tUInt32 DEF_signed_8___d9;
  DEF_signed_8___d9 = 8u;
  dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_8___d9);
}

void MOD_mkTb2::RL_r1_9()
{
  tUInt32 DEF_signed_9___d10;
  DEF_signed_9___d10 = 9u;
  dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_9___d10);
}


/* Methods */


/* Reset routines */

void MOD_mkTb2::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_c.reset_RST(ARG_rst_in);
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
  INST_c.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTb2::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 2u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  num = INST_c.dump_VCD_defs(num);
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
  INST_c.dump_VCD(dt, backing.INST_c);
}
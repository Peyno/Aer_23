/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Thu Jan 11 15:44:42 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTb.h"


/* String declarations */
static std::string const __str_literal_4("2*10+1       =", 14u);
static std::string const __str_literal_1("=== step 0 ===", 14u);
static std::string const __str_literal_5("=== step 1 ===", 14u);
static std::string const __str_literal_6("All done", 8u);
static std::string const __str_literal_3("increment 20 = ", 15u);
static std::string const __str_literal_2("square    10 = ", 15u);


/* Constructor */
MOD_mkTb::MOD_mkTb(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_step(simHdl, "step", this, 32u, 0u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 4u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTb::init_symbols_0()
{
  init_symbol(&symbols[0u], "b__h74", SYM_DEF, &DEF_b__h74, 32u);
  init_symbol(&symbols[1u], "RL_intit", SYM_RULE);
  init_symbol(&symbols[2u], "RL_step1", SYM_RULE);
  init_symbol(&symbols[3u], "step", SYM_MODULE, &INST_step);
}


/* Rule actions */

void MOD_mkTb::RL_intit()
{
  tUInt32 DEF_step_PLUS_1___d6;
  tUInt32 DEF_signed_21___d4;
  tUInt32 DEF_signed_100___d3;
  tUInt32 DEF_signed_101___d5;
  DEF_signed_101___d5 = 101u;
  DEF_signed_100___d3 = 100u;
  DEF_signed_21___d4 = 21u;
  DEF_b__h74 = INST_step.METH_read();
  DEF_step_PLUS_1___d6 = DEF_b__h74 + 1u;
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    dollar_display(sim_hdl, this, "s", &__str_literal_1);
    dollar_display(sim_hdl, this, "s,-32", &__str_literal_2, DEF_signed_100___d3);
    dollar_display(sim_hdl, this, "s,-32", &__str_literal_3, DEF_signed_21___d4);
    dollar_display(sim_hdl, this, "s,-32", &__str_literal_4, DEF_signed_101___d5);
  }
  INST_step.METH_write(DEF_step_PLUS_1___d6);
}

void MOD_mkTb::RL_step1()
{
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    dollar_display(sim_hdl, this, "s", &__str_literal_5);
    dollar_display(sim_hdl, this, "s", &__str_literal_6);
    dollar_finish(sim_hdl, "32", 0u);
  }
}


/* Methods */


/* Reset routines */

void MOD_mkTb::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_step.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTb::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTb::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_step.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTb::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 3u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "b__h74", 32u);
  num = INST_step.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTb::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTb &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTb::vcd_defs(tVCDDumpType dt, MOD_mkTb &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
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
      if ((backing.DEF_b__h74) != DEF_b__h74)
      {
	vcd_write_val(sim_hdl, num, DEF_b__h74, 32u);
	backing.DEF_b__h74 = DEF_b__h74;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_b__h74, 32u);
      backing.DEF_b__h74 = DEF_b__h74;
    }
}

void MOD_mkTb::vcd_prims(tVCDDumpType dt, MOD_mkTb &backing)
{
  INST_step.dump_VCD(dt, backing.INST_step);
}

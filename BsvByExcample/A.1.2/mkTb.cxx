/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Sat Dec 23 17:01:16 CET 2023
 * 
 */
#include "bluesim_primitives.h"
#include "mkTb.h"


/* String declarations */
static std::string const __str_literal_1("Hello World! The answer is %0d", 30u);


/* Constructor */
MOD_mkTb::MOD_mkTb(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_ifc(simHdl, "ifc", this),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 2u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTb::init_symbols_0()
{
  init_symbol(&symbols[0u], "ifc", SYM_MODULE, &INST_ifc);
  init_symbol(&symbols[1u], "RL_theUltimateAnswer", SYM_RULE);
}


/* Rule actions */

void MOD_mkTb::RL_theUltimateAnswer()
{
  tUInt32 DEF_b__h119;
  tUInt32 DEF_signed_ifc_the_answer_10_15_17___d2;
  DEF_b__h119 = INST_ifc.METH_the_answer(10u, 15u, 17u);
  DEF_signed_ifc_the_answer_10_15_17___d2 = DEF_b__h119;
  dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_ifc_the_answer_10_15_17___d2);
  dollar_finish(sim_hdl, "32", 0u);
}


/* Methods */


/* Reset routines */

void MOD_mkTb::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_ifc.reset_RST_N(ARG_rst_in);
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
}


/* VCD dumping routines */

unsigned int MOD_mkTb::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 1u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  if (levels != 1u)
  {
    unsigned int l = levels == 0u ? 0u : levels - 1u;
    num = INST_ifc.dump_VCD_defs(l);
  }
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTb::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTb &backing)
{
  vcd_defs(dt, backing);
  if (levels != 1u)
    vcd_submodules(dt, levels - 1u, backing);
}

void MOD_mkTb::vcd_defs(tVCDDumpType dt, MOD_mkTb &backing)
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

void MOD_mkTb::vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkTb &backing)
{
  INST_ifc.dump_VCD(dt, levels, backing.INST_ifc);
}

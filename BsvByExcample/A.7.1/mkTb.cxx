/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Wed Jan 10 11:12:53 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTb.h"


/* String declarations */
static std::string const __str_literal_1("In state %0d, counter values are %0d, %0d", 41u);


/* Constructor */
MOD_mkTb::MOD_mkTb(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_c1(simHdl, "c1", this),
    INST_c2(simHdl, "c2", this),
    INST_state(simHdl, "state", this, 32u, 0u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 10u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTb::init_symbols_0()
{
  init_symbol(&symbols[0u], "b__h182", SYM_DEF, &DEF_b__h182, 32u);
  init_symbol(&symbols[1u], "c1", SYM_MODULE, &INST_c1);
  init_symbol(&symbols[2u], "c2", SYM_MODULE, &INST_c2);
  init_symbol(&symbols[3u], "RL_decr1", SYM_RULE);
  init_symbol(&symbols[4u], "RL_decr2", SYM_RULE);
  init_symbol(&symbols[5u], "RL_incr1", SYM_RULE);
  init_symbol(&symbols[6u], "RL_incr2", SYM_RULE);
  init_symbol(&symbols[7u], "RL_show", SYM_RULE);
  init_symbol(&symbols[8u], "RL_step_state", SYM_RULE);
  init_symbol(&symbols[9u], "state", SYM_MODULE, &INST_state);
}


/* Rule actions */

void MOD_mkTb::RL_step_state()
{
  tUInt32 DEF_state_PLUS_1___d4;
  tUInt8 DEF_NOT_state_SLE_9___d3;
  DEF_b__h182 = INST_state.METH_read();
  DEF_NOT_state_SLE_9___d3 = !primSLE8(1u, 32u, (tUInt32)(DEF_b__h182), 32u, 9u);
  DEF_state_PLUS_1___d4 = DEF_b__h182 + 1u;
  if (!(PORT_RST_N == (tUInt8)0u))
    if (DEF_NOT_state_SLE_9___d3)
      dollar_finish(sim_hdl, "32", 0u);
  INST_state.METH_write(DEF_state_PLUS_1___d4);
}

void MOD_mkTb::RL_show()
{
  tUInt32 DEF_b__h253;
  tUInt32 DEF_signed_c1_read___d7;
  tUInt32 DEF_signed_state___d5;
  tUInt32 DEF_b__h259;
  tUInt32 DEF_signed_c2_read___d9;
  DEF_b__h259 = INST_c2.METH_read();
  DEF_signed_c2_read___d9 = DEF_b__h259;
  DEF_b__h182 = INST_state.METH_read();
  DEF_signed_state___d5 = DEF_b__h182;
  DEF_b__h253 = INST_c1.METH_read();
  DEF_signed_c1_read___d7 = DEF_b__h253;
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl,
		   this,
		   "s,-32,-32,-32",
		   &__str_literal_1,
		   DEF_signed_state___d5,
		   DEF_signed_c1_read___d7,
		   DEF_signed_c2_read___d9);
}

void MOD_mkTb::RL_incr1()
{
  INST_c1.METH_increment(5u);
}

void MOD_mkTb::RL_decr1()
{
  INST_c1.METH_decrement(2u);
}

void MOD_mkTb::RL_incr2()
{
  INST_c2.METH_increment(5u);
}

void MOD_mkTb::RL_decr2()
{
  INST_c2.METH_decrement(2u);
}


/* Methods */


/* Reset routines */

void MOD_mkTb::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_state.reset_RST(ARG_rst_in);
  INST_c2.reset_RST_N(ARG_rst_in);
  INST_c1.reset_RST_N(ARG_rst_in);
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
  INST_c1.dump_state(indent + 2u);
  INST_c2.dump_state(indent + 2u);
  INST_state.dump_state(indent + 2u);
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
  vcd_write_def(sim_hdl, num++, "b__h182", 32u);
  num = INST_state.dump_VCD_defs(num);
  if (levels != 1u)
  {
    unsigned int l = levels == 0u ? 0u : levels - 1u;
    num = INST_c1.dump_VCD_defs(l);
    num = INST_c2.dump_VCD_defs(l);
  }
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTb::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTb &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
  if (levels != 1u)
    vcd_submodules(dt, levels - 1u, backing);
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
      if ((backing.DEF_b__h182) != DEF_b__h182)
      {
	vcd_write_val(sim_hdl, num, DEF_b__h182, 32u);
	backing.DEF_b__h182 = DEF_b__h182;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_b__h182, 32u);
      backing.DEF_b__h182 = DEF_b__h182;
    }
}

void MOD_mkTb::vcd_prims(tVCDDumpType dt, MOD_mkTb &backing)
{
  INST_state.dump_VCD(dt, backing.INST_state);
}

void MOD_mkTb::vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkTb &backing)
{
  INST_c1.dump_VCD(dt, levels, backing.INST_c1);
  INST_c2.dump_VCD(dt, levels, backing.INST_c2);
}

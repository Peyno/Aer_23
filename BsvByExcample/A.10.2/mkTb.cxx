/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Thu Jan 11 14:51:06 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTb.h"


/* String declarations */
static std::string const __str_literal_1("%0d: rule r, r0 = %0d, r1 = %0d", 31u);


/* Constructor */
MOD_mkTb::MOD_mkTb(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_cycle(simHdl, "cycle", this, 32u, 0u, (tUInt8)0u),
    INST_r0(simHdl, "r0", this, 32u, 33u, (tUInt8)0u),
    INST_r1(simHdl, "r1", this, 32u, 33u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 4u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTb::init_symbols_0()
{
  init_symbol(&symbols[0u], "cycle", SYM_MODULE, &INST_cycle);
  init_symbol(&symbols[1u], "RL_r", SYM_RULE);
  init_symbol(&symbols[2u], "r0", SYM_MODULE, &INST_r0);
  init_symbol(&symbols[3u], "r1", SYM_MODULE, &INST_r1);
}


/* Rule actions */

void MOD_mkTb::RL_r()
{
  tUInt32 DEF_cycle_PLUS_1___d16;
  tUInt8 DEF_NOT_cycle_SLE_7_4___d15;
  tUInt32 DEF_IF_cycle_BIT_0_THEN_r1_PLUS_1_1_ELSE_r1_PLUS_5_2___d13;
  tUInt32 DEF_IF_cycle_BIT_0_THEN_r0_PLUS_1_ELSE_r0_PLUS_5___d10;
  tUInt8 DEF_cycle_BIT_0___h341;
  tUInt32 DEF_b__h195;
  tUInt32 DEF_signed_r0___d4;
  tUInt32 DEF_cycle__h338;
  tUInt32 DEF_signed_cycle___d2;
  tUInt32 DEF_b__h198;
  tUInt32 DEF_signed_r1___d6;
  DEF_b__h198 = INST_r1.METH_read();
  DEF_signed_r1___d6 = DEF_b__h198;
  DEF_cycle__h338 = INST_cycle.METH_read();
  DEF_signed_cycle___d2 = DEF_cycle__h338;
  DEF_b__h195 = INST_r0.METH_read();
  DEF_signed_r0___d4 = DEF_b__h195;
  DEF_cycle_BIT_0___h341 = (tUInt8)((tUInt8)1u & DEF_cycle__h338);
  DEF_IF_cycle_BIT_0_THEN_r0_PLUS_1_ELSE_r0_PLUS_5___d10 = DEF_cycle_BIT_0___h341 ? DEF_b__h195 + 1u : DEF_b__h195 + 5u;
  DEF_IF_cycle_BIT_0_THEN_r1_PLUS_1_1_ELSE_r1_PLUS_5_2___d13 = DEF_cycle_BIT_0___h341 ? DEF_b__h198 + 1u : DEF_b__h198 + 5u;
  DEF_NOT_cycle_SLE_7_4___d15 = !primSLE8(1u, 32u, (tUInt32)(DEF_cycle__h338), 32u, 7u);
  DEF_cycle_PLUS_1___d16 = DEF_cycle__h338 + 1u;
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl,
		   this,
		   "s,-32,-32,-32",
		   &__str_literal_1,
		   DEF_signed_cycle___d2,
		   DEF_signed_r0___d4,
		   DEF_signed_r1___d6);
  INST_r0.METH_write(DEF_IF_cycle_BIT_0_THEN_r0_PLUS_1_ELSE_r0_PLUS_5___d10);
  INST_r1.METH_write(DEF_IF_cycle_BIT_0_THEN_r1_PLUS_1_1_ELSE_r1_PLUS_5_2___d13);
  if (!(PORT_RST_N == (tUInt8)0u))
    if (DEF_NOT_cycle_SLE_7_4___d15)
      dollar_finish(sim_hdl, "32", 0u);
  INST_cycle.METH_write(DEF_cycle_PLUS_1___d16);
}


/* Methods */


/* Reset routines */

void MOD_mkTb::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_r1.reset_RST(ARG_rst_in);
  INST_r0.reset_RST(ARG_rst_in);
  INST_cycle.reset_RST(ARG_rst_in);
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
  INST_cycle.dump_state(indent + 2u);
  INST_r0.dump_state(indent + 2u);
  INST_r1.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTb::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 4u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  num = INST_cycle.dump_VCD_defs(num);
  num = INST_r0.dump_VCD_defs(num);
  num = INST_r1.dump_VCD_defs(num);
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

void MOD_mkTb::vcd_prims(tVCDDumpType dt, MOD_mkTb &backing)
{
  INST_cycle.dump_VCD(dt, backing.INST_cycle);
  INST_r0.dump_VCD(dt, backing.INST_r0);
  INST_r1.dump_VCD(dt, backing.INST_r1);
}

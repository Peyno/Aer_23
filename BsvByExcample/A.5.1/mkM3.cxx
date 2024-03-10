/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Tue Dec 26 20:47:09 CET 2023
 * 
 */
#include "bluesim_primitives.h"
#include "mkM3.h"


/* String declarations */
static std::string const __str_literal_1("x = %0d, m1b/x = %0d, m2/x = %0d, m2/m1a/x = %0d", 48u);


/* Constructor */
MOD_mkM3::MOD_mkM3(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_m1b(simHdl, "m1b", this, 20u),
    INST_m2(simHdl, "m2", this, 30u),
    INST_x(simHdl, "x", this, 32u, 10u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 4u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkM3::init_symbols_0()
{
  init_symbol(&symbols[0u], "m1b", SYM_MODULE, &INST_m1b);
  init_symbol(&symbols[1u], "m2", SYM_MODULE, &INST_m2);
  init_symbol(&symbols[2u], "RL_justonce", SYM_RULE);
  init_symbol(&symbols[3u], "x", SYM_MODULE, &INST_x);
}


/* Rule actions */

void MOD_mkM3::RL_justonce()
{
  tUInt32 DEF_b__h191;
  tUInt32 DEF_signed_m1b_read_local_x___d4;
  tUInt32 DEF_b__h185;
  tUInt32 DEF_signed_x___d2;
  tUInt32 DEF_b__h197;
  tUInt32 DEF_signed_m2_read_local_x___d6;
  tUInt32 DEF_b__h203;
  tUInt32 DEF_signed_m2_read_sub_x___d8;
  DEF_b__h203 = INST_m2.METH_read_sub_x();
  DEF_signed_m2_read_sub_x___d8 = DEF_b__h203;
  DEF_b__h197 = INST_m2.METH_read_local_x();
  DEF_signed_m2_read_local_x___d6 = DEF_b__h197;
  DEF_b__h185 = INST_x.METH_read();
  DEF_signed_x___d2 = DEF_b__h185;
  DEF_b__h191 = INST_m1b.METH_read_local_x();
  DEF_signed_m1b_read_local_x___d4 = DEF_b__h191;
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    dollar_display(sim_hdl,
		   this,
		   "s,-32,-32,-32,-32",
		   &__str_literal_1,
		   DEF_signed_x___d2,
		   DEF_signed_m1b_read_local_x___d4,
		   DEF_signed_m2_read_local_x___d6,
		   DEF_signed_m2_read_sub_x___d8);
    dollar_finish(sim_hdl, "32", 0u);
  }
}


/* Methods */


/* Reset routines */

void MOD_mkM3::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_x.reset_RST(ARG_rst_in);
  INST_m2.reset_RST_N(ARG_rst_in);
  INST_m1b.reset_RST_N(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkM3::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkM3::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_m1b.dump_state(indent + 2u);
  INST_m2.dump_state(indent + 2u);
  INST_x.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkM3::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 2u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  num = INST_x.dump_VCD_defs(num);
  if (levels != 1u)
  {
    unsigned int l = levels == 0u ? 0u : levels - 1u;
    num = INST_m1b.dump_VCD_defs(l);
    num = INST_m2.dump_VCD_defs(l);
  }
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkM3::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkM3 &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
  if (levels != 1u)
    vcd_submodules(dt, levels - 1u, backing);
}

void MOD_mkM3::vcd_defs(tVCDDumpType dt, MOD_mkM3 &backing)
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

void MOD_mkM3::vcd_prims(tVCDDumpType dt, MOD_mkM3 &backing)
{
  INST_x.dump_VCD(dt, backing.INST_x);
}

void MOD_mkM3::vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkM3 &backing)
{
  INST_m1b.dump_VCD(dt, levels, backing.INST_m1b);
  INST_m2.dump_VCD(dt, levels, backing.INST_m2);
}
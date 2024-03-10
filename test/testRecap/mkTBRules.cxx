/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Sun Feb 18 12:50:56 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTBRules.h"


/* String declarations */
static std::string const __str_literal_1("Ergebnis ist : %d", 17u);


/* Constructor */
MOD_mkTBRules::MOD_mkTBRules(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_dut_in(simHdl, "dut_in", this, 8u, 2u, (tUInt8)1u, 0u),
    INST_dut_out(simHdl, "dut_out", this, 8u, 2u, (tUInt8)1u, 0u),
    INST_dut_thresh(simHdl, "dut_thresh", this, 8u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 7u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTBRules::init_symbols_0()
{
  init_symbol(&symbols[0u], "dut_in", SYM_MODULE, &INST_dut_in);
  init_symbol(&symbols[1u], "dut_out", SYM_MODULE, &INST_dut_out);
  init_symbol(&symbols[2u], "dut_thresh", SYM_MODULE, &INST_dut_thresh);
  init_symbol(&symbols[3u], "RL_ausgabe", SYM_RULE);
  init_symbol(&symbols[4u], "RL_dut_dosth", SYM_RULE);
  init_symbol(&symbols[5u], "RL_put", SYM_RULE);
  init_symbol(&symbols[6u], "RL_set", SYM_RULE);
}


/* Rule actions */

void MOD_mkTBRules::RL_dut_dosth()
{
  tUInt8 DEF_IF_dut_in_first_ULE_dut_thresh_THEN_0_ELSE_255___d7;
  tUInt8 DEF_b__h291;
  DEF_b__h291 = INST_dut_thresh.METH_read();
  DEF_IF_dut_in_first_ULE_dut_thresh_THEN_0_ELSE_255___d7 = INST_dut_in.METH_first() <= DEF_b__h291 ? (tUInt8)0u : (tUInt8)255u;
  INST_dut_in.METH_deq();
  INST_dut_out.METH_enq(DEF_IF_dut_in_first_ULE_dut_thresh_THEN_0_ELSE_255___d7);
}

void MOD_mkTBRules::RL_set()
{
  INST_dut_thresh.METH_write((tUInt8)5u);
}

void MOD_mkTBRules::RL_put()
{
  INST_dut_in.METH_enq((tUInt8)3u);
}

void MOD_mkTBRules::RL_ausgabe()
{
  tUInt8 DEF_unsigned_dut_out_first__0___d11;
  DEF_unsigned_dut_out_first__0___d11 = INST_dut_out.METH_first();
  INST_dut_out.METH_deq();
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    dollar_display(sim_hdl, this, "s,8", &__str_literal_1, DEF_unsigned_dut_out_first__0___d11);
    dollar_finish(sim_hdl, "32", 0u);
  }
}


/* Methods */


/* Reset routines */

void MOD_mkTBRules::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_dut_out.reset_RST(ARG_rst_in);
  INST_dut_in.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTBRules::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTBRules::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_dut_in.dump_state(indent + 2u);
  INST_dut_out.dump_state(indent + 2u);
  INST_dut_thresh.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTBRules::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 4u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  num = INST_dut_in.dump_VCD_defs(num);
  num = INST_dut_out.dump_VCD_defs(num);
  num = INST_dut_thresh.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTBRules::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTBRules &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTBRules::vcd_defs(tVCDDumpType dt, MOD_mkTBRules &backing)
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

void MOD_mkTBRules::vcd_prims(tVCDDumpType dt, MOD_mkTBRules &backing)
{
  INST_dut_in.dump_VCD(dt, backing.INST_dut_in);
  INST_dut_out.dump_VCD(dt, backing.INST_dut_out);
  INST_dut_thresh.dump_VCD(dt, backing.INST_dut_thresh);
}

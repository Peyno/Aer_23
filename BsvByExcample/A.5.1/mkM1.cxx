/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Tue Dec 26 20:47:09 CET 2023
 * 
 */
#include "bluesim_primitives.h"
#include "mkM1.h"


/* Constructor */
MOD_mkM1::MOD_mkM1(tSimStateHdl simHdl, char const *name, Module *parent, tUInt32 ARG_init_val)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    PARAM_init_val(ARG_init_val),
    INST_x(simHdl, "x", this, 32u, ARG_init_val, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 2u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkM1::init_symbols_0()
{
  init_symbol(&symbols[0u], "init_val", SYM_PARAM, (void *)(&PARAM_init_val), 32u);
  init_symbol(&symbols[1u], "x", SYM_MODULE, &INST_x);
}


/* Rule actions */


/* Methods */

tUInt32 MOD_mkM1::METH_read_local_x()
{
  tUInt32 PORT_read_local_x;
  PORT_read_local_x = INST_x.METH_read();
  return PORT_read_local_x;
}

tUInt8 MOD_mkM1::METH_RDY_read_local_x()
{
  tUInt8 DEF_CAN_FIRE_read_local_x;
  tUInt8 PORT_RDY_read_local_x;
  DEF_CAN_FIRE_read_local_x = (tUInt8)1u;
  PORT_RDY_read_local_x = DEF_CAN_FIRE_read_local_x;
  return PORT_RDY_read_local_x;
}


/* Reset routines */

void MOD_mkM1::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_x.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkM1::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkM1::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_x.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkM1::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 2u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  num = INST_x.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkM1::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkM1 &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkM1::vcd_defs(tVCDDumpType dt, MOD_mkM1 &backing)
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

void MOD_mkM1::vcd_prims(tVCDDumpType dt, MOD_mkM1 &backing)
{
  INST_x.dump_VCD(dt, backing.INST_x);
}

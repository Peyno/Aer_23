/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Wed Jan 10 14:51:02 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTb.h"


/* String declarations */
static std::string const __str_literal_1("=== step 0 ===", 14u);
static std::string const __str_literal_4("=== step 1 ===", 14u);
static std::string const __str_literal_7("=== step 2 ===", 14u);
static std::string const __str_literal_10("All done", 8u);
static std::string const __str_literal_2("r1.a = ", 7u);
static std::string const __str_literal_3("r1.b = ", 7u);
static std::string const __str_literal_5("r2.ra = ", 8u);
static std::string const __str_literal_6("r2.rb = ", 8u);
static std::string const __str_literal_8("r3.ra = ", 8u);
static std::string const __str_literal_9("r3.rb = ", 8u);


/* Constructor */
MOD_mkTb::MOD_mkTb(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_fifo(simHdl, "fifo", this, 33u, 2u, (tUInt8)1u, 0u),
    INST_r1(simHdl, "r1", this, 33u, 0llu, (tUInt8)0u),
    INST_r2_ra(simHdl, "r2_ra", this, 32u, 2u, (tUInt8)0u),
    INST_r2_rb(simHdl, "r2_rb", this, 1u, (tUInt8)1u, (tUInt8)0u),
    INST_reg3A(simHdl, "reg3A", this, 32u, 3u, (tUInt8)0u),
    INST_reg3B(simHdl, "reg3B", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_step(simHdl, "step", this, 32u, 0u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 11u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTb::init_symbols_0()
{
  init_symbol(&symbols[0u], "b__h343", SYM_DEF, &DEF_b__h343, 32u);
  init_symbol(&symbols[1u], "fifo", SYM_MODULE, &INST_fifo);
  init_symbol(&symbols[2u], "RL_init", SYM_RULE);
  init_symbol(&symbols[3u], "RL_step1", SYM_RULE);
  init_symbol(&symbols[4u], "RL_step2", SYM_RULE);
  init_symbol(&symbols[5u], "r1", SYM_MODULE, &INST_r1);
  init_symbol(&symbols[6u], "r2_ra", SYM_MODULE, &INST_r2_ra);
  init_symbol(&symbols[7u], "r2_rb", SYM_MODULE, &INST_r2_rb);
  init_symbol(&symbols[8u], "reg3A", SYM_MODULE, &INST_reg3A);
  init_symbol(&symbols[9u], "reg3B", SYM_MODULE, &INST_reg3B);
  init_symbol(&symbols[10u], "step", SYM_MODULE, &INST_step);
}


/* Rule actions */

void MOD_mkTb::RL_init()
{
  tUInt8 DEF_r1_BIT_0___d6;
  tUInt64 DEF_r1___d3;
  tUInt32 DEF_signed_r1_BITS_32_TO_1___d5;
  DEF_r1___d3 = INST_r1.METH_read();
  DEF_signed_r1_BITS_32_TO_1___d5 = (tUInt32)(DEF_r1___d3 >> 1u);
  DEF_b__h343 = INST_step.METH_read();
  DEF_r1_BIT_0___d6 = (tUInt8)((tUInt8)1u & DEF_r1___d3);
  DEF_step_PLUS_1___d7 = DEF_b__h343 + 1u;
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    dollar_display(sim_hdl, this, "s", &__str_literal_1);
    dollar_display(sim_hdl, this, "s,-32", &__str_literal_2, DEF_signed_r1_BITS_32_TO_1___d5);
    dollar_display(sim_hdl, this, "s,1", &__str_literal_3, DEF_r1_BIT_0___d6);
  }
  INST_r1.METH_write(40llu);
  INST_step.METH_write(DEF_step_PLUS_1___d7);
}

void MOD_mkTb::RL_step1()
{
  tUInt8 DEF_r2_rb__h617;
  tUInt32 DEF_b__h583;
  tUInt32 DEF_signed_r2_ra___d10;
  DEF_b__h583 = INST_r2_ra.METH_read();
  DEF_signed_r2_ra___d10 = DEF_b__h583;
  DEF_b__h343 = INST_step.METH_read();
  DEF_r2_rb__h617 = INST_r2_rb.METH_read();
  DEF_step_PLUS_1___d7 = DEF_b__h343 + 1u;
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    dollar_display(sim_hdl, this, "s", &__str_literal_4);
    dollar_display(sim_hdl, this, "s,-32", &__str_literal_5, DEF_signed_r2_ra___d10);
    dollar_display(sim_hdl, this, "s,1", &__str_literal_6, DEF_r2_rb__h617);
  }
  INST_r2_ra.METH_write(31u);
  INST_r2_rb.METH_write((tUInt8)0u);
  INST_step.METH_write(DEF_step_PLUS_1___d7);
}

void MOD_mkTb::RL_step2()
{
  tUInt8 DEF_reg3B__h797;
  tUInt32 DEF_b__h763;
  tUInt32 DEF_signed_reg3A_3___d14;
  DEF_b__h763 = INST_reg3A.METH_read();
  DEF_signed_reg3A_3___d14 = DEF_b__h763;
  DEF_reg3B__h797 = INST_reg3B.METH_read();
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    dollar_display(sim_hdl, this, "s", &__str_literal_7);
    dollar_display(sim_hdl, this, "s,-32", &__str_literal_8, DEF_signed_reg3A_3___d14);
    dollar_display(sim_hdl, this, "s,1", &__str_literal_9, DEF_reg3B__h797);
    dollar_display(sim_hdl, this, "s", &__str_literal_10);
    dollar_finish(sim_hdl, "32", 0u);
  }
}


/* Methods */


/* Reset routines */

void MOD_mkTb::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_step.reset_RST(ARG_rst_in);
  INST_reg3B.reset_RST(ARG_rst_in);
  INST_reg3A.reset_RST(ARG_rst_in);
  INST_r2_rb.reset_RST(ARG_rst_in);
  INST_r2_ra.reset_RST(ARG_rst_in);
  INST_r1.reset_RST(ARG_rst_in);
  INST_fifo.reset_RST(ARG_rst_in);
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
  INST_fifo.dump_state(indent + 2u);
  INST_r1.dump_state(indent + 2u);
  INST_r2_ra.dump_state(indent + 2u);
  INST_r2_rb.dump_state(indent + 2u);
  INST_reg3A.dump_state(indent + 2u);
  INST_reg3B.dump_state(indent + 2u);
  INST_step.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTb::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 10u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "b__h343", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "step_PLUS_1___d7", 32u);
  num = INST_fifo.dump_VCD_defs(num);
  num = INST_r1.dump_VCD_defs(num);
  num = INST_r2_ra.dump_VCD_defs(num);
  num = INST_r2_rb.dump_VCD_defs(num);
  num = INST_reg3A.dump_VCD_defs(num);
  num = INST_reg3B.dump_VCD_defs(num);
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
      if ((backing.DEF_b__h343) != DEF_b__h343)
      {
	vcd_write_val(sim_hdl, num, DEF_b__h343, 32u);
	backing.DEF_b__h343 = DEF_b__h343;
      }
      ++num;
      if ((backing.DEF_step_PLUS_1___d7) != DEF_step_PLUS_1___d7)
      {
	vcd_write_val(sim_hdl, num, DEF_step_PLUS_1___d7, 32u);
	backing.DEF_step_PLUS_1___d7 = DEF_step_PLUS_1___d7;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_b__h343, 32u);
      backing.DEF_b__h343 = DEF_b__h343;
      vcd_write_val(sim_hdl, num++, DEF_step_PLUS_1___d7, 32u);
      backing.DEF_step_PLUS_1___d7 = DEF_step_PLUS_1___d7;
    }
}

void MOD_mkTb::vcd_prims(tVCDDumpType dt, MOD_mkTb &backing)
{
  INST_fifo.dump_VCD(dt, backing.INST_fifo);
  INST_r1.dump_VCD(dt, backing.INST_r1);
  INST_r2_ra.dump_VCD(dt, backing.INST_r2_ra);
  INST_r2_rb.dump_VCD(dt, backing.INST_r2_rb);
  INST_reg3A.dump_VCD(dt, backing.INST_reg3A);
  INST_reg3B.dump_VCD(dt, backing.INST_reg3B);
  INST_step.dump_VCD(dt, backing.INST_step);
}
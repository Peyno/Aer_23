/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Wed Jan 17 17:54:55 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "testCalculations.h"


/* String declarations */
static std::string const __str_literal_2("(%0d) Put: %d", 13u);
static std::string const __str_literal_1("(%0d) Result: %d", 16u);


/* Constructor */
MOD_testCalculations::MOD_testCalculations(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_cntr(simHdl, "cntr", this, 32u, 0u, (tUInt8)0u),
    INST_uut_a(simHdl, "uut_a", this, 32u, 42u, (tUInt8)0u),
    INST_uut_addA_a(simHdl, "uut_addA_a", this, 32u, (tUInt8)0u),
    INST_uut_addA_p(simHdl, "uut_addA_p", this, 32u, 0u, (tUInt8)0u),
    INST_uut_addA_r(simHdl, "uut_addA_r", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_uut_b(simHdl, "uut_b", this, 32u, 2u, (tUInt8)0u),
    INST_uut_c(simHdl, "uut_c", this, 32u, 4u, (tUInt8)0u),
    INST_uut_calcUnits_3_a(simHdl, "uut_calcUnits_3_a", this, 32u, (tUInt8)0u),
    INST_uut_calcUnits_3_r(simHdl, "uut_calcUnits_3_r", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_uut_calcUnits_4_a(simHdl, "uut_calcUnits_4_a", this, 32u, (tUInt8)0u),
    INST_uut_calcUnits_4_r(simHdl, "uut_calcUnits_4_r", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_uut_inFIFO(simHdl, "uut_inFIFO", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_uut_initialised(simHdl, "uut_initialised", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_uut_outFIFO(simHdl, "uut_outFIFO", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_uut_timesB_a(simHdl, "uut_timesB_a", this, 32u, (tUInt8)0u),
    INST_uut_timesB_p(simHdl, "uut_timesB_p", this, 32u, 0u, (tUInt8)0u),
    INST_uut_timesB_r(simHdl, "uut_timesB_r", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_uut_timesC_a(simHdl, "uut_timesC_a", this, 32u, (tUInt8)0u),
    INST_uut_timesC_p(simHdl, "uut_timesC_p", this, 32u, 0u, (tUInt8)0u),
    INST_uut_timesC_r(simHdl, "uut_timesC_r", this, 32u, 2u, (tUInt8)1u, 0u),
    PORT_RST_N((tUInt8)1u),
    DEF_v__h2494(12297829382473034410llu),
    DEF_v__h2423(12297829382473034410llu)
{
  symbol_count = 37u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_testCalculations::init_symbols_0()
{
  init_symbol(&symbols[0u], "b__h2528", SYM_DEF, &DEF_b__h2528, 32u);
  init_symbol(&symbols[1u], "cntr", SYM_MODULE, &INST_cntr);
  init_symbol(&symbols[2u], "RL_countUp", SYM_RULE);
  init_symbol(&symbols[3u], "RL_endIt", SYM_RULE);
  init_symbol(&symbols[4u], "RL_printResult", SYM_RULE);
  init_symbol(&symbols[5u], "RL_putData", SYM_RULE);
  init_symbol(&symbols[6u], "RL_uut_addA_doCalc", SYM_RULE);
  init_symbol(&symbols[7u], "RL_uut_calc", SYM_RULE);
  init_symbol(&symbols[8u], "RL_uut_calc_1", SYM_RULE);
  init_symbol(&symbols[9u], "RL_uut_calc_2", SYM_RULE);
  init_symbol(&symbols[10u], "RL_uut_calc_3", SYM_RULE);
  init_symbol(&symbols[11u], "RL_uut_calcUnits_3_calc", SYM_RULE);
  init_symbol(&symbols[12u], "RL_uut_calcUnits_4_calc", SYM_RULE);
  init_symbol(&symbols[13u], "RL_uut_initialise", SYM_RULE);
  init_symbol(&symbols[14u], "RL_uut_outputResult", SYM_RULE);
  init_symbol(&symbols[15u], "RL_uut_setupCalc", SYM_RULE);
  init_symbol(&symbols[16u], "RL_uut_timesB_doCalc", SYM_RULE);
  init_symbol(&symbols[17u], "RL_uut_timesC_doCalc", SYM_RULE);
  init_symbol(&symbols[18u], "uut_a", SYM_MODULE, &INST_uut_a);
  init_symbol(&symbols[19u], "uut_addA_a", SYM_MODULE, &INST_uut_addA_a);
  init_symbol(&symbols[20u], "uut_addA_p", SYM_MODULE, &INST_uut_addA_p);
  init_symbol(&symbols[21u], "uut_addA_r", SYM_MODULE, &INST_uut_addA_r);
  init_symbol(&symbols[22u], "uut_b", SYM_MODULE, &INST_uut_b);
  init_symbol(&symbols[23u], "uut_c", SYM_MODULE, &INST_uut_c);
  init_symbol(&symbols[24u], "uut_calcUnits_3_a", SYM_MODULE, &INST_uut_calcUnits_3_a);
  init_symbol(&symbols[25u], "uut_calcUnits_3_r", SYM_MODULE, &INST_uut_calcUnits_3_r);
  init_symbol(&symbols[26u], "uut_calcUnits_4_a", SYM_MODULE, &INST_uut_calcUnits_4_a);
  init_symbol(&symbols[27u], "uut_calcUnits_4_r", SYM_MODULE, &INST_uut_calcUnits_4_r);
  init_symbol(&symbols[28u], "uut_inFIFO", SYM_MODULE, &INST_uut_inFIFO);
  init_symbol(&symbols[29u], "uut_initialised", SYM_MODULE, &INST_uut_initialised);
  init_symbol(&symbols[30u], "uut_outFIFO", SYM_MODULE, &INST_uut_outFIFO);
  init_symbol(&symbols[31u], "uut_timesB_a", SYM_MODULE, &INST_uut_timesB_a);
  init_symbol(&symbols[32u], "uut_timesB_p", SYM_MODULE, &INST_uut_timesB_p);
  init_symbol(&symbols[33u], "uut_timesB_r", SYM_MODULE, &INST_uut_timesB_r);
  init_symbol(&symbols[34u], "uut_timesC_a", SYM_MODULE, &INST_uut_timesC_a);
  init_symbol(&symbols[35u], "uut_timesC_p", SYM_MODULE, &INST_uut_timesC_p);
  init_symbol(&symbols[36u], "uut_timesC_r", SYM_MODULE, &INST_uut_timesC_r);
}


/* Rule actions */

void MOD_testCalculations::RL_uut_addA_doCalc()
{
  tUInt32 DEF_uut_addA_a_wget_PLUS_uut_addA_p___d6;
  tUInt32 DEF_b__h392;
  DEF_b__h392 = INST_uut_addA_p.METH_read();
  DEF_uut_addA_a_wget_PLUS_uut_addA_p___d6 = INST_uut_addA_a.METH_wget() + DEF_b__h392;
  INST_uut_addA_r.METH_enq(DEF_uut_addA_a_wget_PLUS_uut_addA_p___d6);
}

void MOD_testCalculations::RL_uut_timesB_doCalc()
{
  tUInt32 DEF_uut_timesB_a_wget__0_MUL_uut_timesB_p_1_2_BITS_ETC___d13;
  tUInt32 DEF_b__h638;
  DEF_b__h638 = INST_uut_timesB_p.METH_read();
  DEF_uut_timesB_a_wget__0_MUL_uut_timesB_p_1_2_BITS_ETC___d13 = (tUInt32)(((tUInt64)(INST_uut_timesB_a.METH_wget())) * ((tUInt64)(DEF_b__h638)));
  INST_uut_timesB_r.METH_enq(DEF_uut_timesB_a_wget__0_MUL_uut_timesB_p_1_2_BITS_ETC___d13);
}

void MOD_testCalculations::RL_uut_timesC_doCalc()
{
  tUInt32 DEF_uut_timesC_a_wget__7_MUL_uut_timesC_p_8_9_BITS_ETC___d20;
  tUInt32 DEF_b__h885;
  DEF_b__h885 = INST_uut_timesC_p.METH_read();
  DEF_uut_timesC_a_wget__7_MUL_uut_timesC_p_8_9_BITS_ETC___d20 = (tUInt32)(((tUInt64)(INST_uut_timesC_a.METH_wget())) * ((tUInt64)(DEF_b__h885)));
  INST_uut_timesC_r.METH_enq(DEF_uut_timesC_a_wget__7_MUL_uut_timesC_p_8_9_BITS_ETC___d20);
}

void MOD_testCalculations::RL_uut_calcUnits_3_calc()
{
  tUInt32 DEF_IF_uut_calcUnits_3_a_wget__4_BIT_31_5_THEN_NEG_ETC___d28;
  tUInt32 DEF_IF_uut_calcUnits_3_a_wget__4_BIT_31_5_THEN_NEG_ETC___d30;
  tUInt8 DEF_uut_calcUnits_3_a_wget__4_BIT_31___d25;
  tUInt32 DEF_x__h1158;
  DEF_x__h1158 = INST_uut_calcUnits_3_a.METH_wget();
  DEF_uut_calcUnits_3_a_wget__4_BIT_31___d25 = (tUInt8)(DEF_x__h1158 >> 31u);
  DEF_IF_uut_calcUnits_3_a_wget__4_BIT_31_5_THEN_NEG_ETC___d28 = primShiftR32(32u,
									      32u,
									      (tUInt32)(DEF_uut_calcUnits_3_a_wget__4_BIT_31___d25 ? -DEF_x__h1158 : DEF_x__h1158),
									      32u,
									      2u);
  DEF_IF_uut_calcUnits_3_a_wget__4_BIT_31_5_THEN_NEG_ETC___d30 = DEF_uut_calcUnits_3_a_wget__4_BIT_31___d25 ? -DEF_IF_uut_calcUnits_3_a_wget__4_BIT_31_5_THEN_NEG_ETC___d28 : DEF_IF_uut_calcUnits_3_a_wget__4_BIT_31_5_THEN_NEG_ETC___d28;
  INST_uut_calcUnits_3_r.METH_enq(DEF_IF_uut_calcUnits_3_a_wget__4_BIT_31_5_THEN_NEG_ETC___d30);
}

void MOD_testCalculations::RL_uut_calcUnits_4_calc()
{
  tUInt32 DEF_uut_calcUnits_4_a_wget__4_PLUS_128___d35;
  DEF_uut_calcUnits_4_a_wget__4_PLUS_128___d35 = INST_uut_calcUnits_4_a.METH_wget() + 128u;
  INST_uut_calcUnits_4_r.METH_enq(DEF_uut_calcUnits_4_a_wget__4_PLUS_128___d35);
}

void MOD_testCalculations::RL_uut_initialise()
{
  tUInt32 DEF_b__h1474;
  tUInt32 DEF_b__h1505;
  tUInt32 DEF_b__h1514;
  DEF_b__h1514 = INST_uut_c.METH_read();
  DEF_b__h1505 = INST_uut_b.METH_read();
  DEF_b__h1474 = INST_uut_a.METH_read();
  INST_uut_addA_p.METH_write(DEF_b__h1474);
  INST_uut_timesB_p.METH_write(DEF_b__h1505);
  INST_uut_timesC_p.METH_write(DEF_b__h1514);
}

void MOD_testCalculations::RL_uut_calc()
{
  tUInt32 DEF_uut_addA_r_first____d42;
  DEF_uut_addA_r_first____d42 = INST_uut_addA_r.METH_first();
  INST_uut_addA_r.METH_deq();
  INST_uut_timesB_a.METH_wset(DEF_uut_addA_r_first____d42);
}

void MOD_testCalculations::RL_uut_calc_1()
{
  tUInt32 DEF_uut_timesB_r_first____d44;
  DEF_uut_timesB_r_first____d44 = INST_uut_timesB_r.METH_first();
  INST_uut_timesB_r.METH_deq();
  INST_uut_timesC_a.METH_wset(DEF_uut_timesB_r_first____d44);
}

void MOD_testCalculations::RL_uut_calc_2()
{
  tUInt32 DEF_uut_timesC_r_first____d46;
  DEF_uut_timesC_r_first____d46 = INST_uut_timesC_r.METH_first();
  INST_uut_timesC_r.METH_deq();
  INST_uut_calcUnits_3_a.METH_wset(DEF_uut_timesC_r_first____d46);
}

void MOD_testCalculations::RL_uut_calc_3()
{
  tUInt32 DEF_uut_calcUnits_3_r_first____d48;
  DEF_uut_calcUnits_3_r_first____d48 = INST_uut_calcUnits_3_r.METH_first();
  INST_uut_calcUnits_3_r.METH_deq();
  INST_uut_calcUnits_4_a.METH_wset(DEF_uut_calcUnits_3_r_first____d48);
}

void MOD_testCalculations::RL_uut_setupCalc()
{
  tUInt32 DEF_uut_inFIFO_first____d50;
  DEF_uut_inFIFO_first____d50 = INST_uut_inFIFO.METH_first();
  INST_uut_addA_a.METH_wset(DEF_uut_inFIFO_first____d50);
  INST_uut_inFIFO.METH_deq();
}

void MOD_testCalculations::RL_uut_outputResult()
{
  tUInt32 DEF_uut_calcUnits_4_r_first____d54;
  DEF_uut_calcUnits_4_r_first____d54 = INST_uut_calcUnits_4_r.METH_first();
  INST_uut_calcUnits_4_r.METH_deq();
  INST_uut_outFIFO.METH_enq(DEF_uut_calcUnits_4_r_first____d54);
}

void MOD_testCalculations::RL_printResult()
{
  tUInt32 DEF_signed_uut_outFIFO_first__7___d58;
  DEF_signed_uut_outFIFO_first__7___d58 = INST_uut_outFIFO.METH_first();
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h2423 = dollar_time(sim_hdl);
  INST_uut_outFIFO.METH_deq();
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl,
		   this,
		   "s,64,-32",
		   &__str_literal_1,
		   DEF_v__h2423,
		   DEF_signed_uut_outFIFO_first__7___d58);
}

void MOD_testCalculations::RL_putData()
{
  tUInt32 DEF_signed_cntr_1___d62;
  DEF_b__h2528 = INST_cntr.METH_read();
  DEF_signed_cntr_1___d62 = DEF_b__h2528;
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h2494 = dollar_time(sim_hdl);
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s,64,-32", &__str_literal_2, DEF_v__h2494, DEF_signed_cntr_1___d62);
  INST_uut_inFIFO.METH_enq(DEF_b__h2528);
}

void MOD_testCalculations::RL_countUp()
{
  tUInt32 DEF_cntr_1_PLUS_1___d63;
  DEF_b__h2528 = INST_cntr.METH_read();
  DEF_cntr_1_PLUS_1___d63 = DEF_b__h2528 + 1u;
  INST_cntr.METH_write(DEF_cntr_1_PLUS_1___d63);
}

void MOD_testCalculations::RL_endIt()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_finish(sim_hdl, "32", 1u);
}


/* Methods */


/* Reset routines */

void MOD_testCalculations::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_uut_timesC_r.reset_RST(ARG_rst_in);
  INST_uut_timesC_p.reset_RST(ARG_rst_in);
  INST_uut_timesB_r.reset_RST(ARG_rst_in);
  INST_uut_timesB_p.reset_RST(ARG_rst_in);
  INST_uut_outFIFO.reset_RST(ARG_rst_in);
  INST_uut_initialised.reset_RST(ARG_rst_in);
  INST_uut_inFIFO.reset_RST(ARG_rst_in);
  INST_uut_calcUnits_4_r.reset_RST(ARG_rst_in);
  INST_uut_calcUnits_3_r.reset_RST(ARG_rst_in);
  INST_uut_c.reset_RST(ARG_rst_in);
  INST_uut_b.reset_RST(ARG_rst_in);
  INST_uut_addA_r.reset_RST(ARG_rst_in);
  INST_uut_addA_p.reset_RST(ARG_rst_in);
  INST_uut_a.reset_RST(ARG_rst_in);
  INST_cntr.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_testCalculations::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_testCalculations::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_cntr.dump_state(indent + 2u);
  INST_uut_a.dump_state(indent + 2u);
  INST_uut_addA_a.dump_state(indent + 2u);
  INST_uut_addA_p.dump_state(indent + 2u);
  INST_uut_addA_r.dump_state(indent + 2u);
  INST_uut_b.dump_state(indent + 2u);
  INST_uut_c.dump_state(indent + 2u);
  INST_uut_calcUnits_3_a.dump_state(indent + 2u);
  INST_uut_calcUnits_3_r.dump_state(indent + 2u);
  INST_uut_calcUnits_4_a.dump_state(indent + 2u);
  INST_uut_calcUnits_4_r.dump_state(indent + 2u);
  INST_uut_inFIFO.dump_state(indent + 2u);
  INST_uut_initialised.dump_state(indent + 2u);
  INST_uut_outFIFO.dump_state(indent + 2u);
  INST_uut_timesB_a.dump_state(indent + 2u);
  INST_uut_timesB_p.dump_state(indent + 2u);
  INST_uut_timesB_r.dump_state(indent + 2u);
  INST_uut_timesC_a.dump_state(indent + 2u);
  INST_uut_timesC_p.dump_state(indent + 2u);
  INST_uut_timesC_r.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_testCalculations::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 24u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "b__h2528", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h2423", 64u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h2494", 64u);
  num = INST_cntr.dump_VCD_defs(num);
  num = INST_uut_a.dump_VCD_defs(num);
  num = INST_uut_addA_a.dump_VCD_defs(num);
  num = INST_uut_addA_p.dump_VCD_defs(num);
  num = INST_uut_addA_r.dump_VCD_defs(num);
  num = INST_uut_b.dump_VCD_defs(num);
  num = INST_uut_c.dump_VCD_defs(num);
  num = INST_uut_calcUnits_3_a.dump_VCD_defs(num);
  num = INST_uut_calcUnits_3_r.dump_VCD_defs(num);
  num = INST_uut_calcUnits_4_a.dump_VCD_defs(num);
  num = INST_uut_calcUnits_4_r.dump_VCD_defs(num);
  num = INST_uut_inFIFO.dump_VCD_defs(num);
  num = INST_uut_initialised.dump_VCD_defs(num);
  num = INST_uut_outFIFO.dump_VCD_defs(num);
  num = INST_uut_timesB_a.dump_VCD_defs(num);
  num = INST_uut_timesB_p.dump_VCD_defs(num);
  num = INST_uut_timesB_r.dump_VCD_defs(num);
  num = INST_uut_timesC_a.dump_VCD_defs(num);
  num = INST_uut_timesC_p.dump_VCD_defs(num);
  num = INST_uut_timesC_r.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_testCalculations::dump_VCD(tVCDDumpType dt,
				    unsigned int levels,
				    MOD_testCalculations &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_testCalculations::vcd_defs(tVCDDumpType dt, MOD_testCalculations &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 64u);
    vcd_write_x(sim_hdl, num++, 64u);
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
      if ((backing.DEF_b__h2528) != DEF_b__h2528)
      {
	vcd_write_val(sim_hdl, num, DEF_b__h2528, 32u);
	backing.DEF_b__h2528 = DEF_b__h2528;
      }
      ++num;
      if ((backing.DEF_v__h2423) != DEF_v__h2423)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h2423, 64u);
	backing.DEF_v__h2423 = DEF_v__h2423;
      }
      ++num;
      if ((backing.DEF_v__h2494) != DEF_v__h2494)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h2494, 64u);
	backing.DEF_v__h2494 = DEF_v__h2494;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_b__h2528, 32u);
      backing.DEF_b__h2528 = DEF_b__h2528;
      vcd_write_val(sim_hdl, num++, DEF_v__h2423, 64u);
      backing.DEF_v__h2423 = DEF_v__h2423;
      vcd_write_val(sim_hdl, num++, DEF_v__h2494, 64u);
      backing.DEF_v__h2494 = DEF_v__h2494;
    }
}

void MOD_testCalculations::vcd_prims(tVCDDumpType dt, MOD_testCalculations &backing)
{
  INST_cntr.dump_VCD(dt, backing.INST_cntr);
  INST_uut_a.dump_VCD(dt, backing.INST_uut_a);
  INST_uut_addA_a.dump_VCD(dt, backing.INST_uut_addA_a);
  INST_uut_addA_p.dump_VCD(dt, backing.INST_uut_addA_p);
  INST_uut_addA_r.dump_VCD(dt, backing.INST_uut_addA_r);
  INST_uut_b.dump_VCD(dt, backing.INST_uut_b);
  INST_uut_c.dump_VCD(dt, backing.INST_uut_c);
  INST_uut_calcUnits_3_a.dump_VCD(dt, backing.INST_uut_calcUnits_3_a);
  INST_uut_calcUnits_3_r.dump_VCD(dt, backing.INST_uut_calcUnits_3_r);
  INST_uut_calcUnits_4_a.dump_VCD(dt, backing.INST_uut_calcUnits_4_a);
  INST_uut_calcUnits_4_r.dump_VCD(dt, backing.INST_uut_calcUnits_4_r);
  INST_uut_inFIFO.dump_VCD(dt, backing.INST_uut_inFIFO);
  INST_uut_initialised.dump_VCD(dt, backing.INST_uut_initialised);
  INST_uut_outFIFO.dump_VCD(dt, backing.INST_uut_outFIFO);
  INST_uut_timesB_a.dump_VCD(dt, backing.INST_uut_timesB_a);
  INST_uut_timesB_p.dump_VCD(dt, backing.INST_uut_timesB_p);
  INST_uut_timesB_r.dump_VCD(dt, backing.INST_uut_timesB_r);
  INST_uut_timesC_a.dump_VCD(dt, backing.INST_uut_timesC_a);
  INST_uut_timesC_p.dump_VCD(dt, backing.INST_uut_timesC_p);
  INST_uut_timesC_r.dump_VCD(dt, backing.INST_uut_timesC_r);
}

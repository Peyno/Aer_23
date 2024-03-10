/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Tue Feb 20 16:08:35 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTB.h"


/* String declarations */
static std::string const __str_literal_7("Ergebnis der Pipeline: %d", 25u);
static std::string const __str_literal_8("Error: \"Tb.bsv\", line 139, column 12: (R0001)\n  Mutually exclusive rules (from the ME sets [RL_action_l139c12] and\n  [RL_action_l140c12, RL_action_l142c9] ) fired in the same clock cycle.\n",
					 188u);
static std::string const __str_literal_9("Error: \"Tb.bsv\", line 140, column 12: (R0001)\n  Mutually exclusive rules (from the ME sets [RL_action_l140c12] and\n  [RL_action_l142c9] ) fired in the same clock cycle.\n",
					 169u);
static std::string const __str_literal_1("Rule r1", 7u);
static std::string const __str_literal_2("Rule r2", 7u);
static std::string const __str_literal_3("Rule r3", 7u);
static std::string const __str_literal_4("Rule r4", 7u);
static std::string const __str_literal_6("Wert wurde aus fifo3 deq", 24u);
static std::string const __str_literal_5("Wert wurde in fifo1 enq", 23u);


/* Constructor */
MOD_mkTB::MOD_mkTB(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_abort(simHdl, "abort", this, 1u, (tUInt8)0u),
    INST_dut_fifo1(simHdl, "dut_fifo1", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_dut_fifo2(simHdl, "dut_fifo2", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_dut_fifo3(simHdl, "dut_fifo3", this, 32u, 2u, (tUInt8)1u, 0u),
    INST_dut_stage(simHdl, "dut_stage", this, 8u, (tUInt8)0u, (tUInt8)0u),
    INST_dut_stage0_wert(simHdl, "dut_stage0_wert", this, 32u, 0u, (tUInt8)0u),
    INST_dut_stage0put(simHdl, "dut_stage0put", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_dut_stage1_wert(simHdl, "dut_stage1_wert", this, 32u, 0u, (tUInt8)0u),
    INST_dut_stage1put(simHdl, "dut_stage1put", this, 1u, (tUInt8)1u, (tUInt8)0u),
    INST_dut_x(simHdl, "dut_x", this, 32u, 0u, (tUInt8)0u),
    INST_running(simHdl, "running", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_start_reg(simHdl, "start_reg", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_start_reg_1(simHdl, "start_reg_1", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_start_reg_2(simHdl, "start_reg_2", this, 1u, (tUInt8)0u),
    INST_start_wire(simHdl, "start_wire", this, 1u, (tUInt8)0u),
    INST_state_can_overlap(simHdl, "state_can_overlap", this, 1u, (tUInt8)1u, (tUInt8)0u),
    INST_state_fired(simHdl, "state_fired", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_state_fired_1(simHdl, "state_fired_1", this, 1u, (tUInt8)0u),
    INST_state_mkFSMstate(simHdl, "state_mkFSMstate", this, 3u, (tUInt8)0u, (tUInt8)0u),
    INST_state_overlap_pw(simHdl, "state_overlap_pw", this, 0u),
    INST_state_set_pw(simHdl, "state_set_pw", this, 0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 43u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTB::init_symbols_0()
{
  init_symbol(&symbols[0u], "__me_check_10", SYM_RULE);
  init_symbol(&symbols[1u], "__me_check_9", SYM_RULE);
  init_symbol(&symbols[2u], "abort", SYM_MODULE, &INST_abort);
  init_symbol(&symbols[3u], "dut_fifo1", SYM_MODULE, &INST_dut_fifo1);
  init_symbol(&symbols[4u], "dut_fifo2", SYM_MODULE, &INST_dut_fifo2);
  init_symbol(&symbols[5u], "dut_fifo3", SYM_MODULE, &INST_dut_fifo3);
  init_symbol(&symbols[6u], "dut_stage", SYM_MODULE, &INST_dut_stage);
  init_symbol(&symbols[7u], "dut_stage0_wert", SYM_MODULE, &INST_dut_stage0_wert);
  init_symbol(&symbols[8u], "dut_stage0put", SYM_MODULE, &INST_dut_stage0put);
  init_symbol(&symbols[9u], "dut_stage1_wert", SYM_MODULE, &INST_dut_stage1_wert);
  init_symbol(&symbols[10u], "dut_stage1put", SYM_MODULE, &INST_dut_stage1put);
  init_symbol(&symbols[11u], "dut_x", SYM_MODULE, &INST_dut_x);
  init_symbol(&symbols[12u], "RL_action_l139c12", SYM_RULE);
  init_symbol(&symbols[13u], "RL_action_l140c12", SYM_RULE);
  init_symbol(&symbols[14u], "RL_action_l142c9", SYM_RULE);
  init_symbol(&symbols[15u], "RL_auto_finish", SYM_RULE);
  init_symbol(&symbols[16u], "RL_auto_start", SYM_RULE);
  init_symbol(&symbols[17u], "RL_dut_r1", SYM_RULE);
  init_symbol(&symbols[18u], "RL_dut_r2", SYM_RULE);
  init_symbol(&symbols[19u], "RL_dut_r3", SYM_RULE);
  init_symbol(&symbols[20u], "RL_dut_r4", SYM_RULE);
  init_symbol(&symbols[21u], "RL_fsm_start", SYM_RULE);
  init_symbol(&symbols[22u], "RL_idle_l138c14", SYM_RULE);
  init_symbol(&symbols[23u], "RL_restart", SYM_RULE);
  init_symbol(&symbols[24u], "RL_start_reg__dreg_update", SYM_RULE);
  init_symbol(&symbols[25u], "RL_state_every", SYM_RULE);
  init_symbol(&symbols[26u], "RL_state_fired__dreg_update", SYM_RULE);
  init_symbol(&symbols[27u], "RL_state_handle_abort", SYM_RULE);
  init_symbol(&symbols[28u], "running", SYM_MODULE, &INST_running);
  init_symbol(&symbols[29u], "start_reg", SYM_MODULE, &INST_start_reg);
  init_symbol(&symbols[30u], "start_reg_1", SYM_MODULE, &INST_start_reg_1);
  init_symbol(&symbols[31u], "start_reg_2", SYM_MODULE, &INST_start_reg_2);
  init_symbol(&symbols[32u], "start_wire", SYM_MODULE, &INST_start_wire);
  init_symbol(&symbols[33u], "state_can_overlap", SYM_MODULE, &INST_state_can_overlap);
  init_symbol(&symbols[34u], "state_fired", SYM_MODULE, &INST_state_fired);
  init_symbol(&symbols[35u], "state_fired_1", SYM_MODULE, &INST_state_fired_1);
  init_symbol(&symbols[36u], "state_mkFSMstate", SYM_MODULE, &INST_state_mkFSMstate);
  init_symbol(&symbols[37u], "state_overlap_pw", SYM_MODULE, &INST_state_overlap_pw);
  init_symbol(&symbols[38u], "state_set_pw", SYM_MODULE, &INST_state_set_pw);
  init_symbol(&symbols[39u],
	      "WILL_FIRE_RL_action_l139c12",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_action_l139c12,
	      1u);
  init_symbol(&symbols[40u],
	      "WILL_FIRE_RL_action_l140c12",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_action_l140c12,
	      1u);
  init_symbol(&symbols[41u],
	      "WILL_FIRE_RL_action_l142c9",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_action_l142c9,
	      1u);
  init_symbol(&symbols[42u], "x__h863", SYM_DEF, &DEF_x__h863, 8u);
}


/* Rule actions */

void MOD_mkTB::RL_dut_r1()
{
  tUInt32 DEF_dut_fifo1_first____d5;
  DEF_dut_fifo1_first____d5 = INST_dut_fifo1.METH_first();
  DEF_x__h863 = INST_dut_stage.METH_read();
  DEF_x__h855 = (tUInt8)255u & (DEF_x__h863 + (tUInt8)1u);
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s", &__str_literal_1);
  INST_dut_fifo1.METH_deq();
  INST_dut_stage0_wert.METH_write(DEF_dut_fifo1_first____d5);
  INST_dut_stage.METH_write(DEF_x__h855);
}

void MOD_mkTB::RL_dut_r2()
{
  tUInt32 DEF_dut_stage0_wert_0_PLUS_5___d11;
  tUInt32 DEF_b__h747;
  DEF_b__h747 = INST_dut_stage0_wert.METH_read();
  DEF_x__h863 = INST_dut_stage.METH_read();
  DEF_dut_stage0_wert_0_PLUS_5___d11 = DEF_b__h747 + 5u;
  DEF_x__h855 = (tUInt8)255u & (DEF_x__h863 + (tUInt8)1u);
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s", &__str_literal_2);
  INST_dut_fifo2.METH_enq(DEF_dut_stage0_wert_0_PLUS_5___d11);
  INST_dut_stage.METH_write(DEF_x__h855);
}

void MOD_mkTB::RL_dut_r3()
{
  tUInt32 DEF_dut_fifo2_first____d15;
  DEF_dut_fifo2_first____d15 = INST_dut_fifo2.METH_first();
  DEF_x__h863 = INST_dut_stage.METH_read();
  DEF_x__h855 = (tUInt8)255u & (DEF_x__h863 + (tUInt8)1u);
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s", &__str_literal_3);
  INST_dut_fifo2.METH_deq();
  INST_dut_stage1_wert.METH_write(DEF_dut_fifo2_first____d15);
  INST_dut_stage.METH_write(DEF_x__h855);
}

void MOD_mkTB::RL_dut_r4()
{
  tUInt32 DEF_dut_stage1_wert_9_MUL_dut_stage1_wert_9_0_BITS_ETC___d21;
  tUInt32 DEF_b__h930;
  DEF_b__h930 = INST_dut_stage1_wert.METH_read();
  DEF_dut_stage1_wert_9_MUL_dut_stage1_wert_9_0_BITS_ETC___d21 = (tUInt32)(((tUInt64)(DEF_b__h930)) * ((tUInt64)(DEF_b__h930)));
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s", &__str_literal_4);
  INST_dut_fifo3.METH_enq(DEF_dut_stage1_wert_9_MUL_dut_stage1_wert_9_0_BITS_ETC___d21);
  INST_dut_stage.METH_write((tUInt8)0u);
}

void MOD_mkTB::RL_start_reg__dreg_update()
{
  tUInt8 DEF_start_reg_2_whas__2_AND_start_reg_2_wget__3___d24;
  DEF_start_reg_2_whas__2_AND_start_reg_2_wget__3___d24 = INST_start_reg_2.METH_whas() && INST_start_reg_2.METH_wget();
  INST_start_reg_1.METH_write(DEF_start_reg_2_whas__2_AND_start_reg_2_wget__3___d24);
}

void MOD_mkTB::RL_state_handle_abort()
{
  INST_state_mkFSMstate.METH_write((tUInt8)0u);
}

void MOD_mkTB::RL_state_fired__dreg_update()
{
  tUInt8 DEF_state_fired_1_whas__4_AND_state_fired_1_wget__5___d36;
  DEF_state_fired_1_whas__4_AND_state_fired_1_wget__5___d36 = INST_state_fired_1.METH_whas() && INST_state_fired_1.METH_wget();
  INST_state_fired.METH_write(DEF_state_fired_1_whas__4_AND_state_fired_1_wget__5___d36);
}

void MOD_mkTB::RL_state_every()
{
  tUInt8 DEF_state_set_pw_whas__7_OR_NOT_state_overlap_pw_w_ETC___d42;
  tUInt8 DEF_state_can_overlap__h2416;
  DEF_state_can_overlap__h2416 = INST_state_can_overlap.METH_read();
  DEF_state_set_pw_whas__7_OR_NOT_state_overlap_pw_w_ETC___d42 = INST_state_set_pw.METH_whas() || (!INST_state_overlap_pw.METH_whas() && DEF_state_can_overlap__h2416);
  INST_state_can_overlap.METH_write(DEF_state_set_pw_whas__7_OR_NOT_state_overlap_pw_w_ETC___d42);
}

void MOD_mkTB::RL_restart()
{
  INST_start_wire.METH_wset((tUInt8)1u);
  INST_start_reg_2.METH_wset((tUInt8)1u);
}

void MOD_mkTB::RL_action_l139c12()
{
  INST_state_mkFSMstate.METH_write((tUInt8)1u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
  INST_dut_x.METH_write(2u);
}

void MOD_mkTB::RL_action_l140c12()
{
  INST_state_mkFSMstate.METH_write((tUInt8)2u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s", &__str_literal_5);
  INST_dut_fifo1.METH_enq(2u);
}

void MOD_mkTB::RL_action_l142c9()
{
  tUInt32 DEF_signed_dut_fifo3_first__6___d67;
  DEF_signed_dut_fifo3_first__6___d67 = INST_dut_fifo3.METH_first();
  INST_state_mkFSMstate.METH_write((tUInt8)3u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s", &__str_literal_6);
  INST_dut_fifo3.METH_deq();
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s,-32", &__str_literal_7, DEF_signed_dut_fifo3_first__6___d67);
}

void MOD_mkTB::RL_idle_l138c14()
{
  INST_state_mkFSMstate.METH_write((tUInt8)0u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
}

void MOD_mkTB::RL_fsm_start()
{
  INST_start_wire.METH_wset((tUInt8)1u);
  INST_start_reg_2.METH_wset((tUInt8)1u);
  INST_start_reg.METH_write((tUInt8)0u);
}

void MOD_mkTB::RL_auto_start()
{
  INST_start_reg.METH_write((tUInt8)1u);
  INST_running.METH_write((tUInt8)1u);
}

void MOD_mkTB::RL_auto_finish()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_finish(sim_hdl, "32", 0u);
}

void MOD_mkTB::__me_check_9()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    if (DEF_WILL_FIRE_RL_action_l139c12 && (DEF_WILL_FIRE_RL_action_l140c12 || DEF_WILL_FIRE_RL_action_l142c9))
      dollar_error(sim_hdl, this, "s", &__str_literal_8);
}

void MOD_mkTB::__me_check_10()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    if (DEF_WILL_FIRE_RL_action_l140c12 && DEF_WILL_FIRE_RL_action_l142c9)
      dollar_error(sim_hdl, this, "s", &__str_literal_9);
}


/* Methods */


/* Reset routines */

void MOD_mkTB::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_state_mkFSMstate.reset_RST(ARG_rst_in);
  INST_state_fired.reset_RST(ARG_rst_in);
  INST_state_can_overlap.reset_RST(ARG_rst_in);
  INST_start_reg_1.reset_RST(ARG_rst_in);
  INST_start_reg.reset_RST(ARG_rst_in);
  INST_running.reset_RST(ARG_rst_in);
  INST_dut_x.reset_RST(ARG_rst_in);
  INST_dut_stage1put.reset_RST(ARG_rst_in);
  INST_dut_stage1_wert.reset_RST(ARG_rst_in);
  INST_dut_stage0put.reset_RST(ARG_rst_in);
  INST_dut_stage0_wert.reset_RST(ARG_rst_in);
  INST_dut_stage.reset_RST(ARG_rst_in);
  INST_dut_fifo3.reset_RST(ARG_rst_in);
  INST_dut_fifo2.reset_RST(ARG_rst_in);
  INST_dut_fifo1.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTB::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTB::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_abort.dump_state(indent + 2u);
  INST_dut_fifo1.dump_state(indent + 2u);
  INST_dut_fifo2.dump_state(indent + 2u);
  INST_dut_fifo3.dump_state(indent + 2u);
  INST_dut_stage.dump_state(indent + 2u);
  INST_dut_stage0_wert.dump_state(indent + 2u);
  INST_dut_stage0put.dump_state(indent + 2u);
  INST_dut_stage1_wert.dump_state(indent + 2u);
  INST_dut_stage1put.dump_state(indent + 2u);
  INST_dut_x.dump_state(indent + 2u);
  INST_running.dump_state(indent + 2u);
  INST_start_reg.dump_state(indent + 2u);
  INST_start_reg_1.dump_state(indent + 2u);
  INST_start_reg_2.dump_state(indent + 2u);
  INST_start_wire.dump_state(indent + 2u);
  INST_state_can_overlap.dump_state(indent + 2u);
  INST_state_fired.dump_state(indent + 2u);
  INST_state_fired_1.dump_state(indent + 2u);
  INST_state_mkFSMstate.dump_state(indent + 2u);
  INST_state_overlap_pw.dump_state(indent + 2u);
  INST_state_set_pw.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTB::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 27u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_action_l139c12", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_action_l140c12", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_action_l142c9", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x__h855", 8u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x__h863", 8u);
  num = INST_abort.dump_VCD_defs(num);
  num = INST_dut_fifo1.dump_VCD_defs(num);
  num = INST_dut_fifo2.dump_VCD_defs(num);
  num = INST_dut_fifo3.dump_VCD_defs(num);
  num = INST_dut_stage.dump_VCD_defs(num);
  num = INST_dut_stage0_wert.dump_VCD_defs(num);
  num = INST_dut_stage0put.dump_VCD_defs(num);
  num = INST_dut_stage1_wert.dump_VCD_defs(num);
  num = INST_dut_stage1put.dump_VCD_defs(num);
  num = INST_dut_x.dump_VCD_defs(num);
  num = INST_running.dump_VCD_defs(num);
  num = INST_start_reg.dump_VCD_defs(num);
  num = INST_start_reg_1.dump_VCD_defs(num);
  num = INST_start_reg_2.dump_VCD_defs(num);
  num = INST_start_wire.dump_VCD_defs(num);
  num = INST_state_can_overlap.dump_VCD_defs(num);
  num = INST_state_fired.dump_VCD_defs(num);
  num = INST_state_fired_1.dump_VCD_defs(num);
  num = INST_state_mkFSMstate.dump_VCD_defs(num);
  num = INST_state_overlap_pw.dump_VCD_defs(num);
  num = INST_state_set_pw.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTB::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTB &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTB::vcd_defs(tVCDDumpType dt, MOD_mkTB &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 8u);
    vcd_write_x(sim_hdl, num++, 8u);
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
      if ((backing.DEF_WILL_FIRE_RL_action_l139c12) != DEF_WILL_FIRE_RL_action_l139c12)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_action_l139c12, 1u);
	backing.DEF_WILL_FIRE_RL_action_l139c12 = DEF_WILL_FIRE_RL_action_l139c12;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_action_l140c12) != DEF_WILL_FIRE_RL_action_l140c12)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_action_l140c12, 1u);
	backing.DEF_WILL_FIRE_RL_action_l140c12 = DEF_WILL_FIRE_RL_action_l140c12;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_action_l142c9) != DEF_WILL_FIRE_RL_action_l142c9)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_action_l142c9, 1u);
	backing.DEF_WILL_FIRE_RL_action_l142c9 = DEF_WILL_FIRE_RL_action_l142c9;
      }
      ++num;
      if ((backing.DEF_x__h855) != DEF_x__h855)
      {
	vcd_write_val(sim_hdl, num, DEF_x__h855, 8u);
	backing.DEF_x__h855 = DEF_x__h855;
      }
      ++num;
      if ((backing.DEF_x__h863) != DEF_x__h863)
      {
	vcd_write_val(sim_hdl, num, DEF_x__h863, 8u);
	backing.DEF_x__h863 = DEF_x__h863;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_action_l139c12, 1u);
      backing.DEF_WILL_FIRE_RL_action_l139c12 = DEF_WILL_FIRE_RL_action_l139c12;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_action_l140c12, 1u);
      backing.DEF_WILL_FIRE_RL_action_l140c12 = DEF_WILL_FIRE_RL_action_l140c12;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_action_l142c9, 1u);
      backing.DEF_WILL_FIRE_RL_action_l142c9 = DEF_WILL_FIRE_RL_action_l142c9;
      vcd_write_val(sim_hdl, num++, DEF_x__h855, 8u);
      backing.DEF_x__h855 = DEF_x__h855;
      vcd_write_val(sim_hdl, num++, DEF_x__h863, 8u);
      backing.DEF_x__h863 = DEF_x__h863;
    }
}

void MOD_mkTB::vcd_prims(tVCDDumpType dt, MOD_mkTB &backing)
{
  INST_abort.dump_VCD(dt, backing.INST_abort);
  INST_dut_fifo1.dump_VCD(dt, backing.INST_dut_fifo1);
  INST_dut_fifo2.dump_VCD(dt, backing.INST_dut_fifo2);
  INST_dut_fifo3.dump_VCD(dt, backing.INST_dut_fifo3);
  INST_dut_stage.dump_VCD(dt, backing.INST_dut_stage);
  INST_dut_stage0_wert.dump_VCD(dt, backing.INST_dut_stage0_wert);
  INST_dut_stage0put.dump_VCD(dt, backing.INST_dut_stage0put);
  INST_dut_stage1_wert.dump_VCD(dt, backing.INST_dut_stage1_wert);
  INST_dut_stage1put.dump_VCD(dt, backing.INST_dut_stage1put);
  INST_dut_x.dump_VCD(dt, backing.INST_dut_x);
  INST_running.dump_VCD(dt, backing.INST_running);
  INST_start_reg.dump_VCD(dt, backing.INST_start_reg);
  INST_start_reg_1.dump_VCD(dt, backing.INST_start_reg_1);
  INST_start_reg_2.dump_VCD(dt, backing.INST_start_reg_2);
  INST_start_wire.dump_VCD(dt, backing.INST_start_wire);
  INST_state_can_overlap.dump_VCD(dt, backing.INST_state_can_overlap);
  INST_state_fired.dump_VCD(dt, backing.INST_state_fired);
  INST_state_fired_1.dump_VCD(dt, backing.INST_state_fired_1);
  INST_state_mkFSMstate.dump_VCD(dt, backing.INST_state_mkFSMstate);
  INST_state_overlap_pw.dump_VCD(dt, backing.INST_state_overlap_pw);
  INST_state_set_pw.dump_VCD(dt, backing.INST_state_set_pw);
}
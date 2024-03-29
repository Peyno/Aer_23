/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Sat Feb 10 16:52:04 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkMacTb.h"


/* String declarations */
static std::string const __str_literal_1("Ergebnis dut1 : %d", 18u);
static std::string const __str_literal_2("Error: \"Aufgabe5.bsv\", line 60, column 21: (R0001)\n  Mutually exclusive rules (from the ME sets [RL_action_l60c21] and\n  [RL_action_l61c21, RL_action_l62c28, RL_action_l63c17] ) fired in the same\n  clock cycle.\n",
					 211u);
static std::string const __str_literal_3("Error: \"Aufgabe5.bsv\", line 61, column 21: (R0001)\n  Mutually exclusive rules (from the ME sets [RL_action_l61c21] and\n  [RL_action_l62c28, RL_action_l63c17] ) fired in the same clock cycle.\n",
					 191u);
static std::string const __str_literal_4("Error: \"Aufgabe5.bsv\", line 62, column 28: (R0001)\n  Mutually exclusive rules (from the ME sets [RL_action_l62c28] and\n  [RL_action_l63c17] ) fired in the same clock cycle.\n",
					 173u);


/* Constructor */
MOD_mkMacTb::MOD_mkMacTb(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_abort(simHdl, "abort", this, 1u, (tUInt8)0u),
    INST_dut1_a(simHdl, "dut1_a", this, 32u, 0u, (tUInt8)0u),
    INST_dut1_inA(simHdl, "dut1_inA", this, 16u, 2u, (tUInt8)1u, 0u),
    INST_dut1_inB(simHdl, "dut1_inB", this, 16u, 2u, (tUInt8)1u, 0u),
    INST_resultdut1(simHdl, "resultdut1", this, 32u, 0u, (tUInt8)0u),
    INST_resultdut2(simHdl, "resultdut2", this, 32u, 0u, (tUInt8)0u),
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
  symbol_count = 38u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkMacTb::init_symbols_0()
{
  init_symbol(&symbols[0u], "__me_check_6", SYM_RULE);
  init_symbol(&symbols[1u], "__me_check_7", SYM_RULE);
  init_symbol(&symbols[2u], "__me_check_8", SYM_RULE);
  init_symbol(&symbols[3u], "abort", SYM_MODULE, &INST_abort);
  init_symbol(&symbols[4u], "dut1_a", SYM_MODULE, &INST_dut1_a);
  init_symbol(&symbols[5u], "dut1_inA", SYM_MODULE, &INST_dut1_inA);
  init_symbol(&symbols[6u], "dut1_inB", SYM_MODULE, &INST_dut1_inB);
  init_symbol(&symbols[7u], "RL_action_l60c21", SYM_RULE);
  init_symbol(&symbols[8u], "RL_action_l61c21", SYM_RULE);
  init_symbol(&symbols[9u], "RL_action_l62c28", SYM_RULE);
  init_symbol(&symbols[10u], "RL_action_l63c17", SYM_RULE);
  init_symbol(&symbols[11u], "RL_auto_finish", SYM_RULE);
  init_symbol(&symbols[12u], "RL_auto_start", SYM_RULE);
  init_symbol(&symbols[13u], "RL_dut1_calc", SYM_RULE);
  init_symbol(&symbols[14u], "RL_fsm_start", SYM_RULE);
  init_symbol(&symbols[15u], "RL_idle_l58c12", SYM_RULE);
  init_symbol(&symbols[16u], "RL_restart", SYM_RULE);
  init_symbol(&symbols[17u], "RL_start_reg__dreg_update", SYM_RULE);
  init_symbol(&symbols[18u], "RL_state_every", SYM_RULE);
  init_symbol(&symbols[19u], "RL_state_fired__dreg_update", SYM_RULE);
  init_symbol(&symbols[20u], "RL_state_handle_abort", SYM_RULE);
  init_symbol(&symbols[21u], "resultdut1", SYM_MODULE, &INST_resultdut1);
  init_symbol(&symbols[22u], "resultdut2", SYM_MODULE, &INST_resultdut2);
  init_symbol(&symbols[23u], "running", SYM_MODULE, &INST_running);
  init_symbol(&symbols[24u], "start_reg", SYM_MODULE, &INST_start_reg);
  init_symbol(&symbols[25u], "start_reg_1", SYM_MODULE, &INST_start_reg_1);
  init_symbol(&symbols[26u], "start_reg_2", SYM_MODULE, &INST_start_reg_2);
  init_symbol(&symbols[27u], "start_wire", SYM_MODULE, &INST_start_wire);
  init_symbol(&symbols[28u], "state_can_overlap", SYM_MODULE, &INST_state_can_overlap);
  init_symbol(&symbols[29u], "state_fired", SYM_MODULE, &INST_state_fired);
  init_symbol(&symbols[30u], "state_fired_1", SYM_MODULE, &INST_state_fired_1);
  init_symbol(&symbols[31u], "state_mkFSMstate", SYM_MODULE, &INST_state_mkFSMstate);
  init_symbol(&symbols[32u], "state_overlap_pw", SYM_MODULE, &INST_state_overlap_pw);
  init_symbol(&symbols[33u], "state_set_pw", SYM_MODULE, &INST_state_set_pw);
  init_symbol(&symbols[34u],
	      "WILL_FIRE_RL_action_l60c21",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_action_l60c21,
	      1u);
  init_symbol(&symbols[35u],
	      "WILL_FIRE_RL_action_l61c21",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_action_l61c21,
	      1u);
  init_symbol(&symbols[36u],
	      "WILL_FIRE_RL_action_l62c28",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_action_l62c28,
	      1u);
  init_symbol(&symbols[37u],
	      "WILL_FIRE_RL_action_l63c17",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_action_l63c17,
	      1u);
}


/* Rule actions */

void MOD_mkMacTb::RL_dut1_calc()
{
  tUInt32 DEF_dut1_a_PLUS_SEXT_dut1_inA_first_MUL_SEXT_dut1__ETC___d11;
  DEF_b__h316 = INST_dut1_a.METH_read();
  DEF_dut1_a_PLUS_SEXT_dut1_inA_first_MUL_SEXT_dut1__ETC___d11 = DEF_b__h316 + ((tUInt32)(((tUInt64)(primSignExt32(32u,
														   16u,
														   (tUInt32)(INST_dut1_inA.METH_first())))) * ((tUInt64)(primSignExt32(32u,
																						       16u,
																						       (tUInt32)(INST_dut1_inB.METH_first()))))));
  INST_dut1_a.METH_write(DEF_dut1_a_PLUS_SEXT_dut1_inA_first_MUL_SEXT_dut1__ETC___d11);
  INST_dut1_inA.METH_deq();
  INST_dut1_inB.METH_deq();
}

void MOD_mkMacTb::RL_start_reg__dreg_update()
{
  tUInt8 DEF_start_reg_2_whas__2_AND_start_reg_2_wget__3___d14;
  DEF_start_reg_2_whas__2_AND_start_reg_2_wget__3___d14 = INST_start_reg_2.METH_whas() && INST_start_reg_2.METH_wget();
  INST_start_reg_1.METH_write(DEF_start_reg_2_whas__2_AND_start_reg_2_wget__3___d14);
}

void MOD_mkMacTb::RL_state_handle_abort()
{
  INST_state_mkFSMstate.METH_write((tUInt8)0u);
}

void MOD_mkMacTb::RL_state_fired__dreg_update()
{
  tUInt8 DEF_state_fired_1_whas__4_AND_state_fired_1_wget__5___d26;
  DEF_state_fired_1_whas__4_AND_state_fired_1_wget__5___d26 = INST_state_fired_1.METH_whas() && INST_state_fired_1.METH_wget();
  INST_state_fired.METH_write(DEF_state_fired_1_whas__4_AND_state_fired_1_wget__5___d26);
}

void MOD_mkMacTb::RL_state_every()
{
  tUInt8 DEF_state_set_pw_whas__7_OR_NOT_state_overlap_pw_w_ETC___d32;
  tUInt8 DEF_state_can_overlap__h2011;
  DEF_state_can_overlap__h2011 = INST_state_can_overlap.METH_read();
  DEF_state_set_pw_whas__7_OR_NOT_state_overlap_pw_w_ETC___d32 = INST_state_set_pw.METH_whas() || (!INST_state_overlap_pw.METH_whas() && DEF_state_can_overlap__h2011);
  INST_state_can_overlap.METH_write(DEF_state_set_pw_whas__7_OR_NOT_state_overlap_pw_w_ETC___d32);
}

void MOD_mkMacTb::RL_restart()
{
  INST_start_wire.METH_wset((tUInt8)1u);
  INST_start_reg_2.METH_wset((tUInt8)1u);
}

void MOD_mkMacTb::RL_action_l60c21()
{
  INST_state_mkFSMstate.METH_write((tUInt8)1u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
  INST_dut1_inA.METH_enq(2u);
}

void MOD_mkMacTb::RL_action_l61c21()
{
  INST_state_mkFSMstate.METH_write((tUInt8)2u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
  INST_dut1_inB.METH_enq(3u);
}

void MOD_mkMacTb::RL_action_l62c28()
{
  DEF_b__h316 = INST_dut1_a.METH_read();
  INST_state_mkFSMstate.METH_write((tUInt8)3u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
  INST_resultdut1.METH_write(DEF_b__h316);
}

void MOD_mkMacTb::RL_action_l63c17()
{
  tUInt32 DEF_b__h10334;
  tUInt32 DEF_signed_resultdut1_8___d59;
  DEF_b__h10334 = INST_resultdut1.METH_read();
  DEF_signed_resultdut1_8___d59 = DEF_b__h10334;
  INST_state_mkFSMstate.METH_write((tUInt8)4u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_resultdut1_8___d59);
}

void MOD_mkMacTb::RL_idle_l58c12()
{
  INST_state_mkFSMstate.METH_write((tUInt8)0u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
}

void MOD_mkMacTb::RL_fsm_start()
{
  INST_start_wire.METH_wset((tUInt8)1u);
  INST_start_reg_2.METH_wset((tUInt8)1u);
  INST_start_reg.METH_write((tUInt8)0u);
}

void MOD_mkMacTb::RL_auto_start()
{
  INST_start_reg.METH_write((tUInt8)1u);
  INST_running.METH_write((tUInt8)1u);
}

void MOD_mkMacTb::RL_auto_finish()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_finish(sim_hdl, "32", 0u);
}

void MOD_mkMacTb::__me_check_6()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    if (DEF_WILL_FIRE_RL_action_l60c21 && ((DEF_WILL_FIRE_RL_action_l61c21 || DEF_WILL_FIRE_RL_action_l62c28) || DEF_WILL_FIRE_RL_action_l63c17))
      dollar_error(sim_hdl, this, "s", &__str_literal_2);
}

void MOD_mkMacTb::__me_check_7()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    if (DEF_WILL_FIRE_RL_action_l61c21 && (DEF_WILL_FIRE_RL_action_l62c28 || DEF_WILL_FIRE_RL_action_l63c17))
      dollar_error(sim_hdl, this, "s", &__str_literal_3);
}

void MOD_mkMacTb::__me_check_8()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    if (DEF_WILL_FIRE_RL_action_l62c28 && DEF_WILL_FIRE_RL_action_l63c17)
      dollar_error(sim_hdl, this, "s", &__str_literal_4);
}


/* Methods */


/* Reset routines */

void MOD_mkMacTb::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_state_mkFSMstate.reset_RST(ARG_rst_in);
  INST_state_fired.reset_RST(ARG_rst_in);
  INST_state_can_overlap.reset_RST(ARG_rst_in);
  INST_start_reg_1.reset_RST(ARG_rst_in);
  INST_start_reg.reset_RST(ARG_rst_in);
  INST_running.reset_RST(ARG_rst_in);
  INST_resultdut2.reset_RST(ARG_rst_in);
  INST_resultdut1.reset_RST(ARG_rst_in);
  INST_dut1_inB.reset_RST(ARG_rst_in);
  INST_dut1_inA.reset_RST(ARG_rst_in);
  INST_dut1_a.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkMacTb::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkMacTb::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_abort.dump_state(indent + 2u);
  INST_dut1_a.dump_state(indent + 2u);
  INST_dut1_inA.dump_state(indent + 2u);
  INST_dut1_inB.dump_state(indent + 2u);
  INST_resultdut1.dump_state(indent + 2u);
  INST_resultdut2.dump_state(indent + 2u);
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

unsigned int MOD_mkMacTb::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 23u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_action_l60c21", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_action_l61c21", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_action_l62c28", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_action_l63c17", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "b__h316", 32u);
  num = INST_abort.dump_VCD_defs(num);
  num = INST_dut1_a.dump_VCD_defs(num);
  num = INST_dut1_inA.dump_VCD_defs(num);
  num = INST_dut1_inB.dump_VCD_defs(num);
  num = INST_resultdut1.dump_VCD_defs(num);
  num = INST_resultdut2.dump_VCD_defs(num);
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

void MOD_mkMacTb::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkMacTb &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkMacTb::vcd_defs(tVCDDumpType dt, MOD_mkMacTb &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
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
      if ((backing.DEF_WILL_FIRE_RL_action_l60c21) != DEF_WILL_FIRE_RL_action_l60c21)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_action_l60c21, 1u);
	backing.DEF_WILL_FIRE_RL_action_l60c21 = DEF_WILL_FIRE_RL_action_l60c21;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_action_l61c21) != DEF_WILL_FIRE_RL_action_l61c21)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_action_l61c21, 1u);
	backing.DEF_WILL_FIRE_RL_action_l61c21 = DEF_WILL_FIRE_RL_action_l61c21;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_action_l62c28) != DEF_WILL_FIRE_RL_action_l62c28)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_action_l62c28, 1u);
	backing.DEF_WILL_FIRE_RL_action_l62c28 = DEF_WILL_FIRE_RL_action_l62c28;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_action_l63c17) != DEF_WILL_FIRE_RL_action_l63c17)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_action_l63c17, 1u);
	backing.DEF_WILL_FIRE_RL_action_l63c17 = DEF_WILL_FIRE_RL_action_l63c17;
      }
      ++num;
      if ((backing.DEF_b__h316) != DEF_b__h316)
      {
	vcd_write_val(sim_hdl, num, DEF_b__h316, 32u);
	backing.DEF_b__h316 = DEF_b__h316;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_action_l60c21, 1u);
      backing.DEF_WILL_FIRE_RL_action_l60c21 = DEF_WILL_FIRE_RL_action_l60c21;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_action_l61c21, 1u);
      backing.DEF_WILL_FIRE_RL_action_l61c21 = DEF_WILL_FIRE_RL_action_l61c21;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_action_l62c28, 1u);
      backing.DEF_WILL_FIRE_RL_action_l62c28 = DEF_WILL_FIRE_RL_action_l62c28;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_action_l63c17, 1u);
      backing.DEF_WILL_FIRE_RL_action_l63c17 = DEF_WILL_FIRE_RL_action_l63c17;
      vcd_write_val(sim_hdl, num++, DEF_b__h316, 32u);
      backing.DEF_b__h316 = DEF_b__h316;
    }
}

void MOD_mkMacTb::vcd_prims(tVCDDumpType dt, MOD_mkMacTb &backing)
{
  INST_abort.dump_VCD(dt, backing.INST_abort);
  INST_dut1_a.dump_VCD(dt, backing.INST_dut1_a);
  INST_dut1_inA.dump_VCD(dt, backing.INST_dut1_inA);
  INST_dut1_inB.dump_VCD(dt, backing.INST_dut1_inB);
  INST_resultdut1.dump_VCD(dt, backing.INST_resultdut1);
  INST_resultdut2.dump_VCD(dt, backing.INST_resultdut2);
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

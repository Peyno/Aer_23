/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Mon Jan 15 21:29:58 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTb.h"


/* String declarations */
static std::string const __str_literal_2("Error: \"StmtFSM.bs\", line 41, column 0: (R0001)\n  Mutually exclusive rules (from the ME sets [RL_action_d_init_np] and\n  [RL_action_np, RL_action_l9c17] ) fired in the same clock cycle.\n",
					 186u);
static std::string const __str_literal_3("Error: \"StmtFSM.bs\", line 41, column 0: (R0001)\n  Mutually exclusive rules (from the ME sets [RL_action_np] and\n  [RL_action_l9c17] ) fired in the same clock cycle.\n",
					 165u);
static std::string const __str_literal_1("Hello World", 11u);


/* Constructor */
MOD_mkTb::MOD_mkTb(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_abort(simHdl, "abort", this, 1u, (tUInt8)0u),
    INST_jj_delay_count(simHdl, "jj_delay_count", this, 10u, 0u, (tUInt8)0u),
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
    PORT_RST_N((tUInt8)1u),
    DEF_v__h13049(12297829382473034410llu)
{
  symbol_count = 30u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTb::init_symbols_0()
{
  init_symbol(&symbols[0u], "__me_check_5", SYM_RULE);
  init_symbol(&symbols[1u], "__me_check_6", SYM_RULE);
  init_symbol(&symbols[2u], "abort", SYM_MODULE, &INST_abort);
  init_symbol(&symbols[3u], "jj_delay_count", SYM_MODULE, &INST_jj_delay_count);
  init_symbol(&symbols[4u], "RL_action_d_init_np", SYM_RULE);
  init_symbol(&symbols[5u], "RL_action_l9c17", SYM_RULE);
  init_symbol(&symbols[6u], "RL_action_np", SYM_RULE);
  init_symbol(&symbols[7u], "RL_auto_finish", SYM_RULE);
  init_symbol(&symbols[8u], "RL_auto_start", SYM_RULE);
  init_symbol(&symbols[9u], "RL_fsm_start", SYM_RULE);
  init_symbol(&symbols[10u], "RL_idle_l6c9", SYM_RULE);
  init_symbol(&symbols[11u], "RL_restart", SYM_RULE);
  init_symbol(&symbols[12u], "RL_start_reg__dreg_update", SYM_RULE);
  init_symbol(&symbols[13u], "RL_state_every", SYM_RULE);
  init_symbol(&symbols[14u], "RL_state_fired__dreg_update", SYM_RULE);
  init_symbol(&symbols[15u], "RL_state_handle_abort", SYM_RULE);
  init_symbol(&symbols[16u], "running", SYM_MODULE, &INST_running);
  init_symbol(&symbols[17u], "start_reg", SYM_MODULE, &INST_start_reg);
  init_symbol(&symbols[18u], "start_reg_1", SYM_MODULE, &INST_start_reg_1);
  init_symbol(&symbols[19u], "start_reg_2", SYM_MODULE, &INST_start_reg_2);
  init_symbol(&symbols[20u], "start_wire", SYM_MODULE, &INST_start_wire);
  init_symbol(&symbols[21u], "state_can_overlap", SYM_MODULE, &INST_state_can_overlap);
  init_symbol(&symbols[22u], "state_fired", SYM_MODULE, &INST_state_fired);
  init_symbol(&symbols[23u], "state_fired_1", SYM_MODULE, &INST_state_fired_1);
  init_symbol(&symbols[24u], "state_mkFSMstate", SYM_MODULE, &INST_state_mkFSMstate);
  init_symbol(&symbols[25u], "state_overlap_pw", SYM_MODULE, &INST_state_overlap_pw);
  init_symbol(&symbols[26u], "state_set_pw", SYM_MODULE, &INST_state_set_pw);
  init_symbol(&symbols[27u],
	      "WILL_FIRE_RL_action_d_init_np",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_action_d_init_np,
	      1u);
  init_symbol(&symbols[28u],
	      "WILL_FIRE_RL_action_l9c17",
	      SYM_DEF,
	      &DEF_WILL_FIRE_RL_action_l9c17,
	      1u);
  init_symbol(&symbols[29u], "WILL_FIRE_RL_action_np", SYM_DEF, &DEF_WILL_FIRE_RL_action_np, 1u);
}


/* Rule actions */

void MOD_mkTb::RL_start_reg__dreg_update()
{
  tUInt8 DEF_start_reg_2_whas_AND_start_reg_2_wget___d3;
  DEF_start_reg_2_whas_AND_start_reg_2_wget___d3 = INST_start_reg_2.METH_whas() && INST_start_reg_2.METH_wget();
  INST_start_reg_1.METH_write(DEF_start_reg_2_whas_AND_start_reg_2_wget___d3);
}

void MOD_mkTb::RL_state_handle_abort()
{
  INST_state_mkFSMstate.METH_write((tUInt8)0u);
}

void MOD_mkTb::RL_state_fired__dreg_update()
{
  tUInt8 DEF_state_fired_1_whas__3_AND_state_fired_1_wget__4___d15;
  DEF_state_fired_1_whas__3_AND_state_fired_1_wget__4___d15 = INST_state_fired_1.METH_whas() && INST_state_fired_1.METH_wget();
  INST_state_fired.METH_write(DEF_state_fired_1_whas__3_AND_state_fired_1_wget__4___d15);
}

void MOD_mkTb::RL_state_every()
{
  tUInt8 DEF_state_set_pw_whas__6_OR_NOT_state_overlap_pw_w_ETC___d21;
  tUInt8 DEF_state_can_overlap__h2129;
  DEF_state_can_overlap__h2129 = INST_state_can_overlap.METH_read();
  DEF_state_set_pw_whas__6_OR_NOT_state_overlap_pw_w_ETC___d21 = INST_state_set_pw.METH_whas() || (!INST_state_overlap_pw.METH_whas() && DEF_state_can_overlap__h2129);
  INST_state_can_overlap.METH_write(DEF_state_set_pw_whas__6_OR_NOT_state_overlap_pw_w_ETC___d21);
}

void MOD_mkTb::RL_restart()
{
  INST_start_wire.METH_wset((tUInt8)1u);
  INST_start_reg_2.METH_wset((tUInt8)1u);
}

void MOD_mkTb::RL_action_d_init_np()
{
  INST_state_mkFSMstate.METH_write((tUInt8)1u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
  INST_jj_delay_count.METH_write(0u);
}

void MOD_mkTb::RL_action_np()
{
  tUInt32 DEF_x__h12759;
  DEF_jj_delay_count_read____d37 = INST_jj_delay_count.METH_read();
  DEF_x__h12759 = 1023u & (DEF_jj_delay_count_read____d37 + 1u);
  INST_state_mkFSMstate.METH_write((tUInt8)2u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
  INST_jj_delay_count.METH_write(DEF_x__h12759);
}

void MOD_mkTb::RL_action_l9c17()
{
  INST_state_mkFSMstate.METH_write((tUInt8)3u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h13049 = dollar_time(sim_hdl);
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s,64", &__str_literal_1, DEF_v__h13049);
}

void MOD_mkTb::RL_idle_l6c9()
{
  INST_state_mkFSMstate.METH_write((tUInt8)0u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
}

void MOD_mkTb::RL_fsm_start()
{
  INST_start_wire.METH_wset((tUInt8)1u);
  INST_start_reg_2.METH_wset((tUInt8)1u);
  INST_start_reg.METH_write((tUInt8)0u);
}

void MOD_mkTb::RL_auto_start()
{
  INST_start_reg.METH_write((tUInt8)1u);
  INST_running.METH_write((tUInt8)1u);
}

void MOD_mkTb::RL_auto_finish()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_finish(sim_hdl, "32", 0u);
}

void MOD_mkTb::__me_check_5()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    if (DEF_WILL_FIRE_RL_action_d_init_np && (DEF_WILL_FIRE_RL_action_np || DEF_WILL_FIRE_RL_action_l9c17))
      dollar_error(sim_hdl, this, "s", &__str_literal_2);
}

void MOD_mkTb::__me_check_6()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    if (DEF_WILL_FIRE_RL_action_np && DEF_WILL_FIRE_RL_action_l9c17)
      dollar_error(sim_hdl, this, "s", &__str_literal_3);
}


/* Methods */


/* Reset routines */

void MOD_mkTb::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_state_mkFSMstate.reset_RST(ARG_rst_in);
  INST_state_fired.reset_RST(ARG_rst_in);
  INST_state_can_overlap.reset_RST(ARG_rst_in);
  INST_start_reg_1.reset_RST(ARG_rst_in);
  INST_start_reg.reset_RST(ARG_rst_in);
  INST_running.reset_RST(ARG_rst_in);
  INST_jj_delay_count.reset_RST(ARG_rst_in);
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
  INST_abort.dump_state(indent + 2u);
  INST_jj_delay_count.dump_state(indent + 2u);
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

unsigned int MOD_mkTb::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 19u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_action_d_init_np", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_action_l9c17", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_RL_action_np", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "jj_delay_count_read____d37", 10u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h13049", 64u);
  num = INST_abort.dump_VCD_defs(num);
  num = INST_jj_delay_count.dump_VCD_defs(num);
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
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 10u);
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
      if ((backing.DEF_WILL_FIRE_RL_action_d_init_np) != DEF_WILL_FIRE_RL_action_d_init_np)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_action_d_init_np, 1u);
	backing.DEF_WILL_FIRE_RL_action_d_init_np = DEF_WILL_FIRE_RL_action_d_init_np;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_action_l9c17) != DEF_WILL_FIRE_RL_action_l9c17)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_action_l9c17, 1u);
	backing.DEF_WILL_FIRE_RL_action_l9c17 = DEF_WILL_FIRE_RL_action_l9c17;
      }
      ++num;
      if ((backing.DEF_WILL_FIRE_RL_action_np) != DEF_WILL_FIRE_RL_action_np)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_RL_action_np, 1u);
	backing.DEF_WILL_FIRE_RL_action_np = DEF_WILL_FIRE_RL_action_np;
      }
      ++num;
      if ((backing.DEF_jj_delay_count_read____d37) != DEF_jj_delay_count_read____d37)
      {
	vcd_write_val(sim_hdl, num, DEF_jj_delay_count_read____d37, 10u);
	backing.DEF_jj_delay_count_read____d37 = DEF_jj_delay_count_read____d37;
      }
      ++num;
      if ((backing.DEF_v__h13049) != DEF_v__h13049)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h13049, 64u);
	backing.DEF_v__h13049 = DEF_v__h13049;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_action_d_init_np, 1u);
      backing.DEF_WILL_FIRE_RL_action_d_init_np = DEF_WILL_FIRE_RL_action_d_init_np;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_action_l9c17, 1u);
      backing.DEF_WILL_FIRE_RL_action_l9c17 = DEF_WILL_FIRE_RL_action_l9c17;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_RL_action_np, 1u);
      backing.DEF_WILL_FIRE_RL_action_np = DEF_WILL_FIRE_RL_action_np;
      vcd_write_val(sim_hdl, num++, DEF_jj_delay_count_read____d37, 10u);
      backing.DEF_jj_delay_count_read____d37 = DEF_jj_delay_count_read____d37;
      vcd_write_val(sim_hdl, num++, DEF_v__h13049, 64u);
      backing.DEF_v__h13049 = DEF_v__h13049;
    }
}

void MOD_mkTb::vcd_prims(tVCDDumpType dt, MOD_mkTb &backing)
{
  INST_abort.dump_VCD(dt, backing.INST_abort);
  INST_jj_delay_count.dump_VCD(dt, backing.INST_jj_delay_count);
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

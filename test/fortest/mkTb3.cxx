/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Fri Feb  9 18:27:49 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkTb3.h"


/* String declarations */
static std::string const __str_literal_1("%d", 2u);


/* Constructor */
MOD_mkTb3::MOD_mkTb3(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_abort(simHdl, "abort", this, 1u, (tUInt8)0u),
    INST_c(simHdl, "c", this, 32u, 0u, (tUInt8)0u),
    INST_running(simHdl, "running", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_start_reg(simHdl, "start_reg", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_start_reg_1(simHdl, "start_reg_1", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_start_reg_2(simHdl, "start_reg_2", this, 1u, (tUInt8)0u),
    INST_start_wire(simHdl, "start_wire", this, 1u, (tUInt8)0u),
    INST_state_can_overlap(simHdl, "state_can_overlap", this, 1u, (tUInt8)1u, (tUInt8)0u),
    INST_state_fired(simHdl, "state_fired", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_state_fired_1(simHdl, "state_fired_1", this, 1u, (tUInt8)0u),
    INST_state_mkFSMstate(simHdl, "state_mkFSMstate", this, 2u, (tUInt8)0u, (tUInt8)0u),
    INST_state_overlap_pw(simHdl, "state_overlap_pw", this, 0u),
    INST_state_set_pw(simHdl, "state_set_pw", this, 0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 25u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTb3::init_symbols_0()
{
  init_symbol(&symbols[0u], "abort", SYM_MODULE, &INST_abort);
  init_symbol(&symbols[1u], "b__h4234", SYM_DEF, &DEF_b__h4234, 32u);
  init_symbol(&symbols[2u], "c", SYM_MODULE, &INST_c);
  init_symbol(&symbols[3u], "RL_action_l48c22", SYM_RULE);
  init_symbol(&symbols[4u], "RL_auto_finish", SYM_RULE);
  init_symbol(&symbols[5u], "RL_auto_start", SYM_RULE);
  init_symbol(&symbols[6u], "RL_fsm_start", SYM_RULE);
  init_symbol(&symbols[7u], "RL_idle_l48c9", SYM_RULE);
  init_symbol(&symbols[8u], "RL_idle_l48c9_1", SYM_RULE);
  init_symbol(&symbols[9u], "RL_restart", SYM_RULE);
  init_symbol(&symbols[10u], "RL_start_reg__dreg_update", SYM_RULE);
  init_symbol(&symbols[11u], "RL_state_every", SYM_RULE);
  init_symbol(&symbols[12u], "RL_state_fired__dreg_update", SYM_RULE);
  init_symbol(&symbols[13u], "RL_state_handle_abort", SYM_RULE);
  init_symbol(&symbols[14u], "running", SYM_MODULE, &INST_running);
  init_symbol(&symbols[15u], "start_reg", SYM_MODULE, &INST_start_reg);
  init_symbol(&symbols[16u], "start_reg_1", SYM_MODULE, &INST_start_reg_1);
  init_symbol(&symbols[17u], "start_reg_2", SYM_MODULE, &INST_start_reg_2);
  init_symbol(&symbols[18u], "start_wire", SYM_MODULE, &INST_start_wire);
  init_symbol(&symbols[19u], "state_can_overlap", SYM_MODULE, &INST_state_can_overlap);
  init_symbol(&symbols[20u], "state_fired", SYM_MODULE, &INST_state_fired);
  init_symbol(&symbols[21u], "state_fired_1", SYM_MODULE, &INST_state_fired_1);
  init_symbol(&symbols[22u], "state_mkFSMstate", SYM_MODULE, &INST_state_mkFSMstate);
  init_symbol(&symbols[23u], "state_overlap_pw", SYM_MODULE, &INST_state_overlap_pw);
  init_symbol(&symbols[24u], "state_set_pw", SYM_MODULE, &INST_state_set_pw);
}


/* Rule actions */

void MOD_mkTb3::RL_start_reg__dreg_update()
{
  tUInt8 DEF_start_reg_2_whas_AND_start_reg_2_wget___d3;
  DEF_start_reg_2_whas_AND_start_reg_2_wget___d3 = INST_start_reg_2.METH_whas() && INST_start_reg_2.METH_wget();
  INST_start_reg_1.METH_write(DEF_start_reg_2_whas_AND_start_reg_2_wget___d3);
}

void MOD_mkTb3::RL_state_handle_abort()
{
  INST_state_mkFSMstate.METH_write((tUInt8)0u);
}

void MOD_mkTb3::RL_state_fired__dreg_update()
{
  tUInt8 DEF_state_fired_1_whas__3_AND_state_fired_1_wget__4___d15;
  DEF_state_fired_1_whas__3_AND_state_fired_1_wget__4___d15 = INST_state_fired_1.METH_whas() && INST_state_fired_1.METH_wget();
  INST_state_fired.METH_write(DEF_state_fired_1_whas__3_AND_state_fired_1_wget__4___d15);
}

void MOD_mkTb3::RL_state_every()
{
  tUInt8 DEF_state_set_pw_whas__6_OR_NOT_state_overlap_pw_w_ETC___d21;
  tUInt8 DEF_state_can_overlap__h1604;
  DEF_state_can_overlap__h1604 = INST_state_can_overlap.METH_read();
  DEF_state_set_pw_whas__6_OR_NOT_state_overlap_pw_w_ETC___d21 = INST_state_set_pw.METH_whas() || (!INST_state_overlap_pw.METH_whas() && DEF_state_can_overlap__h1604);
  INST_state_can_overlap.METH_write(DEF_state_set_pw_whas__6_OR_NOT_state_overlap_pw_w_ETC___d21);
}

void MOD_mkTb3::RL_restart()
{
  INST_start_wire.METH_wset((tUInt8)1u);
  INST_start_reg_2.METH_wset((tUInt8)1u);
}

void MOD_mkTb3::RL_action_l48c22()
{
  tUInt32 DEF_c_2_PLUS_1___d45;
  tUInt32 DEF_signed_c_2___d44;
  DEF_b__h4234 = INST_c.METH_read();
  DEF_signed_c_2___d44 = DEF_b__h4234;
  DEF_c_2_PLUS_1___d45 = DEF_b__h4234 + 1u;
  INST_state_mkFSMstate.METH_write((tUInt8)1u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_c_2___d44);
  INST_c.METH_write(DEF_c_2_PLUS_1___d45);
}

void MOD_mkTb3::RL_idle_l48c9()
{
  INST_state_mkFSMstate.METH_write((tUInt8)0u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
}

void MOD_mkTb3::RL_idle_l48c9_1()
{
  INST_state_mkFSMstate.METH_write((tUInt8)0u);
  INST_state_fired_1.METH_wset((tUInt8)1u);
  INST_state_set_pw.METH_wset();
}

void MOD_mkTb3::RL_fsm_start()
{
  INST_start_wire.METH_wset((tUInt8)1u);
  INST_start_reg_2.METH_wset((tUInt8)1u);
  INST_start_reg.METH_write((tUInt8)0u);
}

void MOD_mkTb3::RL_auto_start()
{
  INST_start_reg.METH_write((tUInt8)1u);
  INST_running.METH_write((tUInt8)1u);
}

void MOD_mkTb3::RL_auto_finish()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_finish(sim_hdl, "32", 0u);
}


/* Methods */


/* Reset routines */

void MOD_mkTb3::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_state_mkFSMstate.reset_RST(ARG_rst_in);
  INST_state_fired.reset_RST(ARG_rst_in);
  INST_state_can_overlap.reset_RST(ARG_rst_in);
  INST_start_reg_1.reset_RST(ARG_rst_in);
  INST_start_reg.reset_RST(ARG_rst_in);
  INST_running.reset_RST(ARG_rst_in);
  INST_c.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTb3::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTb3::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_abort.dump_state(indent + 2u);
  INST_c.dump_state(indent + 2u);
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

unsigned int MOD_mkTb3::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 15u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "b__h4234", 32u);
  num = INST_abort.dump_VCD_defs(num);
  num = INST_c.dump_VCD_defs(num);
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

void MOD_mkTb3::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTb3 &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTb3::vcd_defs(tVCDDumpType dt, MOD_mkTb3 &backing)
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
      if ((backing.DEF_b__h4234) != DEF_b__h4234)
      {
	vcd_write_val(sim_hdl, num, DEF_b__h4234, 32u);
	backing.DEF_b__h4234 = DEF_b__h4234;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_b__h4234, 32u);
      backing.DEF_b__h4234 = DEF_b__h4234;
    }
}

void MOD_mkTb3::vcd_prims(tVCDDumpType dt, MOD_mkTb3 &backing)
{
  INST_abort.dump_VCD(dt, backing.INST_abort);
  INST_c.dump_VCD(dt, backing.INST_c);
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

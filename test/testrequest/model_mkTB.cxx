/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Wed Feb 14 19:38:36 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkTB.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkTB::MODEL_mkTB()
{
  mkTB_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkTB()
{
  MODEL_mkTB *model = new MODEL_mkTB();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkTB &INST_top = *((MOD_mkTB *)(instance_ptr));
	 tUInt8 DEF_INST_top_DEF_abort_whas_AND_abort_wget__0_1_OR_state_mkFSMs_ETC___d50;
	 tUInt8 DEF_INST_top_DEF_abort_whas_AND_abort_wget__0_1_OR_state_mkFSMs_ETC___d54;
	 tUInt8 DEF_INST_top_DEF_abort_whas_AND_abort_wget__0___d11;
	 tUInt8 DEF_INST_top_DEF_NOT_start_wire_whas__2_3_OR_NOT_start_wire_wge_ETC___d16;
	 tUInt8 DEF_INST_top_DEF_NOT_abort_whas_1_OR_NOT_abort_wget__0_2___d33;
	 tUInt8 DEF_INST_top_DEF_abort_whas_AND_abort_wget__0_1_OR_state_mkFSMs_ETC___d41;
	 tUInt8 DEF_INST_top_DEF_state_mkFSMstate_read__7_EQ_2___d40;
	 tUInt8 DEF_INST_top_DEF_abort_wget____d10;
	 tUInt8 DEF_INST_top_DEF_abort_whas____d9;
	 tUInt8 DEF_INST_top_DEF_start_reg__h7417;
	 tUInt8 DEF_INST_top_DEF_running__h7503;
	 tUInt8 DEF_INST_top_DEF_start_wire_wget____d14;
	 tUInt8 DEF_INST_top_DEF_start_wire_whas____d12;
	 tUInt8 DEF_INST_top_DEF_start_reg_1__h6638;
	 tUInt8 DEF_INST_top_DEF_state_fired__h6640;
	 tUInt8 DEF_INST_top_DEF_state_mkFSMstate_read____d37;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_dut_r1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_dut_r1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_start_reg__dreg_update;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_start_reg__dreg_update;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_state_handle_abort;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_state_handle_abort;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_state_fired__dreg_update;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_state_fired__dreg_update;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_state_every;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_state_every;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_restart;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_restart;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_l27c12;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_l29c1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_idle_l26c14;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_idle_l26c14;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_fsm_start;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_fsm_start;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_auto_start;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_auto_start;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_auto_finish;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_auto_finish;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE___me_check_6;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE___me_check_6;
	 DEF_INST_top_DEF_state_mkFSMstate_read____d37 = INST_top.INST_state_mkFSMstate.METH_read();
	 DEF_INST_top_DEF_abort_whas____d9 = INST_top.INST_abort.METH_whas();
	 DEF_INST_top_DEF_abort_wget____d10 = INST_top.INST_abort.METH_wget();
	 DEF_INST_top_DEF_NOT_abort_whas_1_OR_NOT_abort_wget__0_2___d33 = !DEF_INST_top_DEF_abort_whas____d9 || !DEF_INST_top_DEF_abort_wget____d10;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_l29c1 = DEF_INST_top_DEF_NOT_abort_whas_1_OR_NOT_abort_wget__0_2___d33 && DEF_INST_top_DEF_state_mkFSMstate_read____d37 == (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_action_l29c1 = DEF_INST_top_DEF_CAN_FIRE_RL_action_l29c1;
	 DEF_INST_top_DEF_state_fired__h6640 = INST_top.INST_state_fired.METH_read();
	 DEF_INST_top_DEF_start_reg_1__h6638 = INST_top.INST_start_reg_1.METH_read();
	 DEF_INST_top_DEF_running__h7503 = INST_top.INST_running.METH_read();
	 DEF_INST_top_DEF_start_reg__h7417 = INST_top.INST_start_reg.METH_read();
	 DEF_INST_top_DEF_state_mkFSMstate_read__7_EQ_2___d40 = DEF_INST_top_DEF_state_mkFSMstate_read____d37 == (tUInt8)2u;
	 DEF_INST_top_DEF_abort_whas_AND_abort_wget__0___d11 = DEF_INST_top_DEF_abort_whas____d9 && DEF_INST_top_DEF_abort_wget____d10;
	 DEF_INST_top_DEF_abort_whas_AND_abort_wget__0_1_OR_state_mkFSMs_ETC___d41 = (DEF_INST_top_DEF_abort_whas_AND_abort_wget__0___d11 || DEF_INST_top_DEF_state_mkFSMstate_read____d37 == (tUInt8)0u) || DEF_INST_top_DEF_state_mkFSMstate_read__7_EQ_2___d40;
	 DEF_INST_top_DEF_abort_whas_AND_abort_wget__0_1_OR_state_mkFSMs_ETC___d50 = DEF_INST_top_DEF_abort_whas_AND_abort_wget__0_1_OR_state_mkFSMs_ETC___d41 && (!DEF_INST_top_DEF_start_reg_1__h6638 || DEF_INST_top_DEF_state_fired__h6640);
	 DEF_INST_top_DEF_abort_whas_AND_abort_wget__0_1_OR_state_mkFSMs_ETC___d54 = DEF_INST_top_DEF_abort_whas_AND_abort_wget__0_1_OR_state_mkFSMs_ETC___d50 && !DEF_INST_top_DEF_start_reg__h7417;
	 DEF_INST_top_DEF_CAN_FIRE_RL_auto_finish = DEF_INST_top_DEF_running__h7503 && DEF_INST_top_DEF_abort_whas_AND_abort_wget__0_1_OR_state_mkFSMs_ETC___d54;
	 DEF_INST_top_DEF_WILL_FIRE_RL_auto_finish = DEF_INST_top_DEF_CAN_FIRE_RL_auto_finish;
	 DEF_INST_top_DEF_CAN_FIRE_RL_auto_start = DEF_INST_top_DEF_abort_whas_AND_abort_wget__0_1_OR_state_mkFSMs_ETC___d54 && !DEF_INST_top_DEF_running__h7503;
	 DEF_INST_top_DEF_WILL_FIRE_RL_auto_start = DEF_INST_top_DEF_CAN_FIRE_RL_auto_start;
	 DEF_INST_top_DEF_CAN_FIRE_RL_dut_r1 = INST_top.INST_dut_in.METH_i_notEmpty() && INST_top.INST_dut_out.METH_i_notFull();
	 DEF_INST_top_DEF_WILL_FIRE_RL_dut_r1 = DEF_INST_top_DEF_CAN_FIRE_RL_dut_r1;
	 DEF_INST_top_DEF_CAN_FIRE_RL_fsm_start = DEF_INST_top_DEF_abort_whas_AND_abort_wget__0_1_OR_state_mkFSMs_ETC___d50 && DEF_INST_top_DEF_start_reg__h7417;
	 DEF_INST_top_DEF_WILL_FIRE_RL_fsm_start = DEF_INST_top_DEF_CAN_FIRE_RL_fsm_start;
	 DEF_INST_top_DEF_CAN_FIRE_RL_restart = (DEF_INST_top_DEF_start_reg_1__h6638 && !DEF_INST_top_DEF_state_fired__h6640) && DEF_INST_top_DEF_NOT_abort_whas_1_OR_NOT_abort_wget__0_2___d33;
	 DEF_INST_top_DEF_WILL_FIRE_RL_restart = DEF_INST_top_DEF_CAN_FIRE_RL_restart;
	 DEF_INST_top_DEF_CAN_FIRE_RL_start_reg__dreg_update = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_start_reg__dreg_update = DEF_INST_top_DEF_CAN_FIRE_RL_start_reg__dreg_update;
	 DEF_INST_top_DEF_CAN_FIRE_RL_state_fired__dreg_update = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_state_fired__dreg_update = DEF_INST_top_DEF_CAN_FIRE_RL_state_fired__dreg_update;
	 DEF_INST_top_DEF_CAN_FIRE_RL_state_every = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_state_every = DEF_INST_top_DEF_CAN_FIRE_RL_state_every;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_6 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_6 = DEF_INST_top_DEF_CAN_FIRE___me_check_6;
	 if (INST_top.DEF_WILL_FIRE_RL_action_l29c1)
	   INST_top.RL_action_l29c1();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_auto_finish)
	   INST_top.RL_auto_finish();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_auto_start)
	   INST_top.RL_auto_start();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_dut_r1)
	   INST_top.RL_dut_r1();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_fsm_start)
	   INST_top.RL_fsm_start();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_restart)
	   INST_top.RL_restart();
	 DEF_INST_top_DEF_start_wire_whas____d12 = INST_top.INST_start_wire.METH_whas();
	 DEF_INST_top_DEF_start_wire_wget____d14 = INST_top.INST_start_wire.METH_wget();
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_l27c12 = (INST_top.INST_dut_in.METH_i_notFull() && ((DEF_INST_top_DEF_start_wire_whas____d12 && DEF_INST_top_DEF_start_wire_wget____d14) && DEF_INST_top_DEF_abort_whas_AND_abort_wget__0_1_OR_state_mkFSMs_ETC___d41)) && !DEF_INST_top_DEF_CAN_FIRE_RL_action_l29c1;
	 INST_top.DEF_WILL_FIRE_RL_action_l27c12 = DEF_INST_top_DEF_CAN_FIRE_RL_action_l27c12;
	 DEF_INST_top_DEF_NOT_start_wire_whas__2_3_OR_NOT_start_wire_wge_ETC___d16 = !DEF_INST_top_DEF_start_wire_whas____d12 || !DEF_INST_top_DEF_start_wire_wget____d14;
	 DEF_INST_top_DEF_CAN_FIRE_RL_idle_l26c14 = (DEF_INST_top_DEF_NOT_start_wire_whas__2_3_OR_NOT_start_wire_wge_ETC___d16 && (DEF_INST_top_DEF_NOT_abort_whas_1_OR_NOT_abort_wget__0_2___d33 && DEF_INST_top_DEF_state_mkFSMstate_read__7_EQ_2___d40)) && !DEF_INST_top_DEF_CAN_FIRE_RL_action_l29c1;
	 DEF_INST_top_DEF_WILL_FIRE_RL_idle_l26c14 = DEF_INST_top_DEF_CAN_FIRE_RL_idle_l26c14;
	 DEF_INST_top_DEF_CAN_FIRE_RL_state_handle_abort = (DEF_INST_top_DEF_abort_whas_AND_abort_wget__0___d11 && DEF_INST_top_DEF_NOT_start_wire_whas__2_3_OR_NOT_start_wire_wge_ETC___d16) && !(DEF_INST_top_DEF_CAN_FIRE_RL_action_l29c1 || DEF_INST_top_DEF_CAN_FIRE_RL_restart);
	 DEF_INST_top_DEF_WILL_FIRE_RL_state_handle_abort = DEF_INST_top_DEF_CAN_FIRE_RL_state_handle_abort;
	 if (INST_top.DEF_WILL_FIRE_RL_action_l27c12)
	   INST_top.RL_action_l27c12();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_start_reg__dreg_update)
	   INST_top.RL_start_reg__dreg_update();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_state_handle_abort)
	   INST_top.RL_state_handle_abort();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_6)
	   INST_top.__me_check_6();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_idle_l26c14)
	   INST_top.RL_idle_l26c14();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_state_every)
	   INST_top.RL_state_every();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_state_fired__dreg_update)
	   INST_top.RL_state_fired__dreg_update();
	 INST_top.INST_state_fired_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_state_overlap_pw.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_state_set_pw.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_abort.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_start_reg_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_start_wire.clk((tUInt8)1u, (tUInt8)1u);
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_dut_in.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_dut_out.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_start_reg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_start_reg_1.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_state_mkFSMstate.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_state_fired.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_state_can_overlap.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_running.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkTB::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkTB_instance = new MOD_mkTB(sim_hdl, "top", NULL);
  bk_get_or_define_clock(sim_hdl, "CLK");
  if (master)
  {
    bk_alter_clock(sim_hdl, bk_get_clock_by_name(sim_hdl, "CLK"), CLK_LOW, false, 0llu, 5llu, 5llu);
    bk_use_default_reset(sim_hdl);
  }
  bk_set_clock_event_fn(sim_hdl,
			bk_get_clock_by_name(sim_hdl, "CLK"),
			schedule_posedge_CLK,
			NULL,
			(tEdgeDirection)(POSEDGE));
  (mkTB_instance->INST_dut_in.set_clk_0)("CLK");
  (mkTB_instance->INST_dut_out.set_clk_0)("CLK");
  (mkTB_instance->INST_start_wire.set_clk_0)("CLK");
  (mkTB_instance->INST_start_reg_2.set_clk_0)("CLK");
  (mkTB_instance->INST_abort.set_clk_0)("CLK");
  (mkTB_instance->INST_state_set_pw.set_clk_0)("CLK");
  (mkTB_instance->INST_state_overlap_pw.set_clk_0)("CLK");
  (mkTB_instance->INST_state_fired_1.set_clk_0)("CLK");
  (mkTB_instance->set_clk_0)("CLK");
}
void MODEL_mkTB::destroy_model()
{
  delete mkTB_instance;
  mkTB_instance = NULL;
}
void MODEL_mkTB::reset_model(bool asserted)
{
  (mkTB_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkTB::get_instance()
{
  return mkTB_instance;
}

/* Fill in version numbers */
void MODEL_mkTB::get_version(char const **name, char const **build)
{
  *name = "2023.07";
  *build = "0eb551dc";
}

/* Get the model creation time */
time_t MODEL_mkTB::get_creation_time()
{
  
  /* Wed Feb 14 18:38:36 UTC 2024 */
  return 1707935916llu;
}

/* State dumping function */
void MODEL_mkTB::dump_state()
{
  (mkTB_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkTB & mkTB_backing(tSimStateHdl simHdl)
{
  static MOD_mkTB *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkTB(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkTB::dump_VCD_defs()
{
  (mkTB_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkTB::dump_VCD(tVCDDumpType dt)
{
  (mkTB_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkTB_backing(sim_hdl));
}

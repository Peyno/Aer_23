/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Fri Feb 23 21:25:30 CET 2024
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
	 tUInt8 DEF_INST_top_DEF_i_6_SLT_6___d37;
	 tUInt8 DEF_INST_top_DEF_NOT_i_6_SLT_6_7___d38;
	 tUInt8 DEF_INST_top_DEF_NOT_i_6_SLT_6_7_8_AND_start_wire_whas_AND_star_ETC___d39;
	 tUInt8 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d45;
	 tUInt8 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d41;
	 tUInt8 DEF_INST_top_DEF_NOT_i_6_SLT_6_7_8_AND_NOT_start_wire_whas_OR_N_ETC___d86;
	 tUInt8 DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d95;
	 tUInt8 DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d99;
	 tUInt8 DEF_INST_top_DEF_abort_whas_AND_abort_wget___d6;
	 tUInt8 DEF_INST_top_DEF_NOT_start_wire_whas_OR_NOT_start_wire_wget_0___d11;
	 tUInt8 DEF_INST_top_DEF_start_wire_whas_AND_start_wire_wget___d30;
	 tUInt8 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28;
	 tUInt8 DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d34;
	 tUInt8 DEF_INST_top_DEF_state_mkFSMstate_read__2_EQ_1___d40;
	 tUInt8 DEF_INST_top_DEF_state_mkFSMstate_read__2_EQ_4___d44;
	 tUInt8 DEF_INST_top_DEF_abort_wget____d5;
	 tUInt8 DEF_INST_top_DEF_abort_whas____d4;
	 tUInt8 DEF_INST_top_DEF_start_reg__h15519;
	 tUInt8 DEF_INST_top_DEF_running__h15605;
	 tUInt8 DEF_INST_top_DEF_start_wire_wget____d9;
	 tUInt8 DEF_INST_top_DEF_start_wire_whas____d7;
	 tUInt8 DEF_INST_top_DEF_start_reg_1__h13130;
	 tUInt8 DEF_INST_top_DEF_state_fired__h13132;
	 tUInt8 DEF_INST_top_DEF_state_mkFSMstate_read____d32;
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
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_f_init_l42c9;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_l43c16;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_l44c13;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l42c9;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_idle_l42c9;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_idle_l42c9;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_idle_l42c9_1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_idle_l42c9_1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_fsm_start;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_fsm_start;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_auto_start;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_auto_start;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_auto_finish;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_auto_finish;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE___me_check_5;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE___me_check_5;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE___me_check_6;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE___me_check_6;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE___me_check_7;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE___me_check_7;
	 DEF_INST_top_DEF_state_mkFSMstate_read____d32 = INST_top.INST_state_mkFSMstate.METH_read();
	 DEF_INST_top_DEF_abort_whas____d4 = INST_top.INST_abort.METH_whas();
	 DEF_INST_top_DEF_abort_wget____d5 = INST_top.INST_abort.METH_wget();
	 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 = !DEF_INST_top_DEF_abort_whas____d4 || !DEF_INST_top_DEF_abort_wget____d5;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l42c9 = DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read____d32 == (tUInt8)3u;
	 INST_top.DEF_WILL_FIRE_RL_action_f_update_l42c9 = DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l42c9;
	 INST_top.DEF_x__h14401 = INST_top.INST_dut_index.METH_read();
	 INST_top.DEF_b__h5484 = INST_top.INST_i.METH_read();
	 DEF_INST_top_DEF_state_mkFSMstate_read__2_EQ_4___d44 = DEF_INST_top_DEF_state_mkFSMstate_read____d32 == (tUInt8)4u;
	 DEF_INST_top_DEF_state_mkFSMstate_read__2_EQ_1___d40 = DEF_INST_top_DEF_state_mkFSMstate_read____d32 == (tUInt8)1u;
	 DEF_INST_top_DEF_i_6_SLT_6___d37 = primSLT8(1u, 32u, (tUInt32)(INST_top.DEF_b__h5484), 32u, 6u);
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_l43c16 = primSLT8(1u,
							       32u,
							       (tUInt32)(INST_top.DEF_x__h14401),
							       32u,
							       5u) && (DEF_INST_top_DEF_i_6_SLT_6___d37 && (DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && (DEF_INST_top_DEF_state_mkFSMstate_read__2_EQ_1___d40 || DEF_INST_top_DEF_state_mkFSMstate_read__2_EQ_4___d44)));
	 INST_top.DEF_WILL_FIRE_RL_action_l43c16 = DEF_INST_top_DEF_CAN_FIRE_RL_action_l43c16;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_l44c13 = !primSLE8(1u,
								32u,
								(tUInt32)(INST_top.DEF_x__h14401),
								32u,
								0u) && (DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read____d32 == (tUInt8)2u);
	 INST_top.DEF_WILL_FIRE_RL_action_l44c13 = DEF_INST_top_DEF_CAN_FIRE_RL_action_l44c13;
	 DEF_INST_top_DEF_state_fired__h13132 = INST_top.INST_state_fired.METH_read();
	 DEF_INST_top_DEF_start_reg_1__h13130 = INST_top.INST_start_reg_1.METH_read();
	 DEF_INST_top_DEF_start_reg__h15519 = INST_top.INST_start_reg.METH_read();
	 DEF_INST_top_DEF_running__h15605 = INST_top.INST_running.METH_read();
	 DEF_INST_top_DEF_abort_whas_AND_abort_wget___d6 = DEF_INST_top_DEF_abort_whas____d4 && DEF_INST_top_DEF_abort_wget____d5;
	 DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d34 = DEF_INST_top_DEF_abort_whas_AND_abort_wget___d6 || DEF_INST_top_DEF_state_mkFSMstate_read____d32 == (tUInt8)0u;
	 DEF_INST_top_DEF_NOT_i_6_SLT_6_7___d38 = !DEF_INST_top_DEF_i_6_SLT_6___d37;
	 DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d95 = ((DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d34 || (DEF_INST_top_DEF_NOT_i_6_SLT_6_7___d38 && DEF_INST_top_DEF_state_mkFSMstate_read__2_EQ_1___d40)) || (DEF_INST_top_DEF_NOT_i_6_SLT_6_7___d38 && DEF_INST_top_DEF_state_mkFSMstate_read__2_EQ_4___d44)) && (!DEF_INST_top_DEF_start_reg_1__h13130 || DEF_INST_top_DEF_state_fired__h13132);
	 DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d99 = DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d95 && !DEF_INST_top_DEF_start_reg__h15519;
	 DEF_INST_top_DEF_CAN_FIRE_RL_auto_finish = DEF_INST_top_DEF_running__h15605 && DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d99;
	 DEF_INST_top_DEF_WILL_FIRE_RL_auto_finish = DEF_INST_top_DEF_CAN_FIRE_RL_auto_finish;
	 DEF_INST_top_DEF_CAN_FIRE_RL_auto_start = DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d99 && !DEF_INST_top_DEF_running__h15605;
	 DEF_INST_top_DEF_WILL_FIRE_RL_auto_start = DEF_INST_top_DEF_CAN_FIRE_RL_auto_start;
	 DEF_INST_top_DEF_CAN_FIRE_RL_fsm_start = DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d95 && DEF_INST_top_DEF_start_reg__h15519;
	 DEF_INST_top_DEF_WILL_FIRE_RL_fsm_start = DEF_INST_top_DEF_CAN_FIRE_RL_fsm_start;
	 DEF_INST_top_DEF_CAN_FIRE_RL_restart = (DEF_INST_top_DEF_start_reg_1__h13130 && !DEF_INST_top_DEF_state_fired__h13132) && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28;
	 DEF_INST_top_DEF_WILL_FIRE_RL_restart = DEF_INST_top_DEF_CAN_FIRE_RL_restart;
	 DEF_INST_top_DEF_CAN_FIRE_RL_start_reg__dreg_update = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_start_reg__dreg_update = DEF_INST_top_DEF_CAN_FIRE_RL_start_reg__dreg_update;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_5 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_5 = DEF_INST_top_DEF_CAN_FIRE___me_check_5;
	 DEF_INST_top_DEF_CAN_FIRE_RL_state_every = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_state_every = DEF_INST_top_DEF_CAN_FIRE_RL_state_every;
	 DEF_INST_top_DEF_CAN_FIRE_RL_state_fired__dreg_update = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_state_fired__dreg_update = DEF_INST_top_DEF_CAN_FIRE_RL_state_fired__dreg_update;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_6 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_6 = DEF_INST_top_DEF_CAN_FIRE___me_check_6;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_7 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_7 = DEF_INST_top_DEF_CAN_FIRE___me_check_7;
	 if (INST_top.DEF_WILL_FIRE_RL_action_f_update_l42c9)
	   INST_top.RL_action_f_update_l42c9();
	 if (INST_top.DEF_WILL_FIRE_RL_action_l43c16)
	   INST_top.RL_action_l43c16();
	 if (INST_top.DEF_WILL_FIRE_RL_action_l44c13)
	   INST_top.RL_action_l44c13();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_auto_finish)
	   INST_top.RL_auto_finish();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_auto_start)
	   INST_top.RL_auto_start();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_restart)
	   INST_top.RL_restart();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_6)
	   INST_top.__me_check_6();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_7)
	   INST_top.__me_check_7();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_fsm_start)
	   INST_top.RL_fsm_start();
	 DEF_INST_top_DEF_start_wire_whas____d7 = INST_top.INST_start_wire.METH_whas();
	 DEF_INST_top_DEF_start_wire_wget____d9 = INST_top.INST_start_wire.METH_wget();
	 DEF_INST_top_DEF_start_wire_whas_AND_start_wire_wget___d30 = DEF_INST_top_DEF_start_wire_whas____d7 && DEF_INST_top_DEF_start_wire_wget____d9;
	 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d41 = DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read__2_EQ_1___d40;
	 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d45 = DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read__2_EQ_4___d44;
	 DEF_INST_top_DEF_NOT_i_6_SLT_6_7_8_AND_start_wire_whas_AND_star_ETC___d39 = DEF_INST_top_DEF_NOT_i_6_SLT_6_7___d38 && DEF_INST_top_DEF_start_wire_whas_AND_start_wire_wget___d30;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_f_init_l42c9 = ((DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 || DEF_INST_top_DEF_start_wire_whas_AND_start_wire_wget___d30) && (((DEF_INST_top_DEF_start_wire_whas_AND_start_wire_wget___d30 && DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d34) || (DEF_INST_top_DEF_NOT_i_6_SLT_6_7_8_AND_start_wire_whas_AND_star_ETC___d39 && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d41)) || (DEF_INST_top_DEF_NOT_i_6_SLT_6_7_8_AND_start_wire_whas_AND_star_ETC___d39 && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d45))) && !((DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l42c9 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l44c13) || DEF_INST_top_DEF_CAN_FIRE_RL_action_l43c16);
	 INST_top.DEF_WILL_FIRE_RL_action_f_init_l42c9 = DEF_INST_top_DEF_CAN_FIRE_RL_action_f_init_l42c9;
	 DEF_INST_top_DEF_NOT_start_wire_whas_OR_NOT_start_wire_wget_0___d11 = !DEF_INST_top_DEF_start_wire_whas____d7 || !DEF_INST_top_DEF_start_wire_wget____d9;
	 DEF_INST_top_DEF_NOT_i_6_SLT_6_7_8_AND_NOT_start_wire_whas_OR_N_ETC___d86 = DEF_INST_top_DEF_NOT_i_6_SLT_6_7___d38 && DEF_INST_top_DEF_NOT_start_wire_whas_OR_NOT_start_wire_wget_0___d11;
	 DEF_INST_top_DEF_CAN_FIRE_RL_idle_l42c9 = (DEF_INST_top_DEF_NOT_i_6_SLT_6_7_8_AND_NOT_start_wire_whas_OR_N_ETC___d86 && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d41) && !((DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l42c9 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l44c13) || DEF_INST_top_DEF_CAN_FIRE_RL_action_l43c16);
	 DEF_INST_top_DEF_WILL_FIRE_RL_idle_l42c9 = DEF_INST_top_DEF_CAN_FIRE_RL_idle_l42c9;
	 DEF_INST_top_DEF_CAN_FIRE_RL_idle_l42c9_1 = (DEF_INST_top_DEF_NOT_i_6_SLT_6_7_8_AND_NOT_start_wire_whas_OR_N_ETC___d86 && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d45) && !((DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l42c9 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l44c13) || DEF_INST_top_DEF_CAN_FIRE_RL_action_l43c16);
	 DEF_INST_top_DEF_WILL_FIRE_RL_idle_l42c9_1 = DEF_INST_top_DEF_CAN_FIRE_RL_idle_l42c9_1;
	 DEF_INST_top_DEF_CAN_FIRE_RL_state_handle_abort = (DEF_INST_top_DEF_abort_whas_AND_abort_wget___d6 && DEF_INST_top_DEF_NOT_start_wire_whas_OR_NOT_start_wire_wget_0___d11) && !((DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l42c9 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l44c13) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_l43c16 || DEF_INST_top_DEF_CAN_FIRE_RL_restart));
	 DEF_INST_top_DEF_WILL_FIRE_RL_state_handle_abort = DEF_INST_top_DEF_CAN_FIRE_RL_state_handle_abort;
	 if (INST_top.DEF_WILL_FIRE_RL_action_f_init_l42c9)
	   INST_top.RL_action_f_init_l42c9();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_idle_l42c9)
	   INST_top.RL_idle_l42c9();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_idle_l42c9_1)
	   INST_top.RL_idle_l42c9_1();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_state_every)
	   INST_top.RL_state_every();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_state_fired__dreg_update)
	   INST_top.RL_state_fired__dreg_update();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_state_handle_abort)
	   INST_top.RL_state_handle_abort();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_5)
	   INST_top.__me_check_5();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_start_reg__dreg_update)
	   INST_top.RL_start_reg__dreg_update();
	 INST_top.INST_state_fired_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_state_overlap_pw.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_state_set_pw.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_abort.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_start_reg_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_start_wire.clk((tUInt8)1u, (tUInt8)1u);
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_dut_index.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_i.rst_tick__clk__1((tUInt8)1u);
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
  
  /* Fri Feb 23 20:25:30 UTC 2024 */
  return 1708719930llu;
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

/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Tue Feb 13 17:46:46 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkTB2.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkTB2::MODEL_mkTB2()
{
  mkTB2_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkTB2()
{
  MODEL_mkTB2 *model = new MODEL_mkTB2();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkTB2 &INST_top = *((MOD_mkTB2 *)(instance_ptr));
	 tUInt8 DEF_INST_top_INST_dut_DEF_CAN_FIRE_RL_tick_gen;
	 tUInt8 DEF_INST_top_INST_dut_DEF_WILL_FIRE_RL_tick_gen;
	 tUInt8 DEF_INST_top_INST_dut_DEF_CAN_FIRE_RL_send_bit;
	 tUInt8 DEF_INST_top_INST_dut_DEF_WILL_FIRE_RL_send_bit;
	 tUInt8 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d54;
	 tUInt8 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d64;
	 tUInt8 DEF_INST_top_DEF_NOT_jj_repeat_count_read__0_BIT_0_1___d52;
	 tUInt8 DEF_INST_top_DEF_counter_0_SLT_8___d71;
	 tUInt8 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d90;
	 tUInt8 DEF_INST_top_DEF_NOT_jj_1_repeat_count_read__2_BIT_0_3___d74;
	 tUInt8 DEF_INST_top_DEF_counter_0_SLT_8_1_AND_jj_1_repeat_count_read___ETC___d81;
	 tUInt8 DEF_INST_top_DEF_NOT_counter_0_SLT_8_1___d107;
	 tUInt8 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d121;
	 tUInt8 DEF_INST_top_DEF_NOT_jj_2_repeat_count_read__08_BIT_0_09___d110;
	 tUInt8 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d79;
	 tUInt8 DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d152;
	 tUInt8 DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d156;
	 tUInt8 DEF_INST_top_DEF_abort_whas_AND_abort_wget___d6;
	 tUInt8 DEF_INST_top_DEF_NOT_start_wire_whas_OR_NOT_start_wire_wget_0___d11;
	 tUInt8 DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d35;
	 tUInt8 DEF_INST_top_DEF_start_wire_whas_AND_start_wire_wget___d30;
	 tUInt8 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28;
	 tUInt8 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_OR_star_ETC___d56;
	 tUInt8 DEF_INST_top_DEF_NOT_jj_repeat_count_read__0_BIT_0_1_2_AND_NOT__ETC___d65;
	 tUInt8 DEF_INST_top_DEF_jj_repeat_count_read__0_BIT_0_1_AND_NOT_abort__ETC___d60;
	 tUInt8 DEF_INST_top_DEF_counter_0_SLT_8_1_AND_jj_1_repeat_count_read___ETC___d86;
	 tUInt8 DEF_INST_top_DEF_NOT_jj_1_repeat_count_read__2_BIT_0_3_4_AND_NO_ETC___d91;
	 tUInt8 DEF_INST_top_DEF_counter_0_SLT_8_1_AND_jj_1_repeat_count_read___ETC___d95;
	 tUInt8 DEF_INST_top_DEF_NOT_counter_0_SLT_8_1_07_AND_jj_2_repeat_count_ETC___d114;
	 tUInt8 DEF_INST_top_DEF_NOT_jj_2_repeat_count_read__08_BIT_0_09_10_AND_ETC___d122;
	 tUInt8 DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_9___d76;
	 tUInt8 DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_14___d77;
	 tUInt8 DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_15___d115;
	 tUInt8 DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_19___d34;
	 tUInt8 DEF_INST_top_DEF_jj_repeat_count_read__0_BIT_0___d51;
	 tUInt8 DEF_INST_top_DEF_jj_1_repeat_count_read__2_BIT_0___d73;
	 tUInt8 DEF_INST_top_DEF_jj_2_repeat_count_read__08_BIT_0___d109;
	 tUInt8 DEF_INST_top_DEF_abort_wget____d5;
	 tUInt8 DEF_INST_top_DEF_abort_whas____d4;
	 tUInt8 DEF_INST_top_DEF_start_reg__h78458;
	 tUInt8 DEF_INST_top_DEF_running__h78544;
	 tUInt8 DEF_INST_top_DEF_start_wire_wget____d9;
	 tUInt8 DEF_INST_top_DEF_start_wire_whas____d7;
	 tUInt8 DEF_INST_top_DEF_start_reg_1__h70589;
	 tUInt8 DEF_INST_top_DEF_state_fired__h70591;
	 tUInt8 DEF_INST_top_DEF_state_mkFSMstate_read____d31;
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
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_l60c13;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_l61c13;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_l68c16;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_l69c13;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l75c13;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_l75c25;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_f_init_l82c13;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l83c17;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_l83c29;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l82c13;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l94c13;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_l94c25;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_l102c13;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l75c13;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_action_ovlp_r_update_l75c13;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l83c17;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_action_ovlp_r_update_l83c17;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l94c13;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_action_ovlp_r_update_l94c13;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_idle_l59c18;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_idle_l59c18;
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
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE___me_check_8;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE___me_check_8;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE___me_check_9;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE___me_check_9;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE___me_check_10;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE___me_check_10;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE___me_check_11;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE___me_check_11;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE___me_check_12;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE___me_check_12;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE___me_check_13;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE___me_check_13;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE___me_check_14;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE___me_check_14;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE___me_check_15;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE___me_check_15;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE___me_check_16;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE___me_check_16;
	 INST_top.DEF_jj_repeat_count_read____d50 = INST_top.INST_jj_repeat_count.METH_read();
	 DEF_INST_top_DEF_state_mkFSMstate_read____d31 = INST_top.INST_state_mkFSMstate.METH_read();
	 DEF_INST_top_DEF_abort_whas____d4 = INST_top.INST_abort.METH_whas();
	 DEF_INST_top_DEF_abort_wget____d5 = INST_top.INST_abort.METH_wget();
	 DEF_INST_top_DEF_jj_repeat_count_read__0_BIT_0___d51 = (tUInt8)((tUInt8)1u & (INST_top.DEF_jj_repeat_count_read____d50));
	 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 = !DEF_INST_top_DEF_abort_whas____d4 || !DEF_INST_top_DEF_abort_wget____d5;
	 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d64 = DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)7u;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_f_init_l82c13 = DEF_INST_top_DEF_jj_repeat_count_read__0_BIT_0___d51 && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d64;
	 INST_top.DEF_WILL_FIRE_RL_action_f_init_l82c13 = DEF_INST_top_DEF_CAN_FIRE_RL_action_f_init_l82c13;
	 INST_top.DEF_jj_1_repeat_count_read____d72 = INST_top.INST_jj_1_repeat_count.METH_read();
	 DEF_INST_top_DEF_jj_1_repeat_count_read__2_BIT_0___d73 = (tUInt8)((tUInt8)1u & (INST_top.DEF_jj_1_repeat_count_read____d72));
	 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d90 = DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)12u;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l82c13 = DEF_INST_top_DEF_jj_1_repeat_count_read__2_BIT_0___d73 && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d90;
	 INST_top.DEF_WILL_FIRE_RL_action_f_update_l82c13 = DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l82c13;
	 INST_top.DEF_jj_2_repeat_count_read____d108 = INST_top.INST_jj_2_repeat_count.METH_read();
	 DEF_INST_top_DEF_jj_2_repeat_count_read__08_BIT_0___d109 = (tUInt8)((tUInt8)1u & (INST_top.DEF_jj_2_repeat_count_read____d108));
	 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d121 = DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)17u;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_l102c13 = DEF_INST_top_DEF_jj_2_repeat_count_read__08_BIT_0___d109 && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d121;
	 INST_top.DEF_WILL_FIRE_RL_action_l102c13 = DEF_INST_top_DEF_CAN_FIRE_RL_action_l102c13;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_l61c13 = DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_action_l61c13 = DEF_INST_top_DEF_CAN_FIRE_RL_action_l61c13;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_l68c16 = INST_top.INST_dut.METH_RDY_data_put() && (DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)2u);
	 INST_top.DEF_WILL_FIRE_RL_action_l68c16 = DEF_INST_top_DEF_CAN_FIRE_RL_action_l68c16;
	 INST_top.DEF_dut_pin____d39 = INST_top.INST_dut.METH_pin();
	 INST_top.DEF_NOT_dut_pin__9___d40 = !(INST_top.DEF_dut_pin____d39);
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_l69c13 = INST_top.DEF_NOT_dut_pin__9___d40 && (DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)3u);
	 INST_top.DEF_WILL_FIRE_RL_action_l69c13 = DEF_INST_top_DEF_CAN_FIRE_RL_action_l69c13;
	 INST_top.DEF_state_can_overlap__h6285 = INST_top.INST_state_can_overlap.METH_read();
	 DEF_INST_top_DEF_NOT_jj_repeat_count_read__0_BIT_0_1___d52 = !DEF_INST_top_DEF_jj_repeat_count_read__0_BIT_0___d51;
	 DEF_INST_top_DEF_NOT_jj_repeat_count_read__0_BIT_0_1_2_AND_NOT__ETC___d65 = DEF_INST_top_DEF_NOT_jj_repeat_count_read__0_BIT_0_1___d52 && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d64;
	 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d54 = DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)4u;
	 DEF_INST_top_DEF_jj_repeat_count_read__0_BIT_0_1_AND_NOT_abort__ETC___d60 = (DEF_INST_top_DEF_jj_repeat_count_read__0_BIT_0___d51 && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d54) || (DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)5u);
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l75c13 = INST_top.DEF_state_can_overlap__h6285 && (DEF_INST_top_DEF_jj_repeat_count_read__0_BIT_0_1_AND_NOT_abort__ETC___d60 || DEF_INST_top_DEF_NOT_jj_repeat_count_read__0_BIT_0_1_2_AND_NOT__ETC___d65);
	 DEF_INST_top_DEF_WILL_FIRE_RL_action_ovlp_r_update_l75c13 = DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l75c13;
	 INST_top.DEF_x__h74895 = INST_top.INST_counter.METH_read();
	 DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_14___d77 = DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)14u;
	 DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_9___d76 = DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)9u;
	 DEF_INST_top_DEF_NOT_jj_1_repeat_count_read__2_BIT_0_3___d74 = !DEF_INST_top_DEF_jj_1_repeat_count_read__2_BIT_0___d73;
	 DEF_INST_top_DEF_NOT_jj_1_repeat_count_read__2_BIT_0_3_4_AND_NO_ETC___d91 = DEF_INST_top_DEF_NOT_jj_1_repeat_count_read__2_BIT_0_3___d74 && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d90;
	 DEF_INST_top_DEF_counter_0_SLT_8___d71 = primSLT8(1u,
							   32u,
							   (tUInt32)(INST_top.DEF_x__h74895),
							   32u,
							   8u);
	 DEF_INST_top_DEF_counter_0_SLT_8_1_AND_jj_1_repeat_count_read___ETC___d81 = DEF_INST_top_DEF_counter_0_SLT_8___d71 && DEF_INST_top_DEF_jj_1_repeat_count_read__2_BIT_0___d73;
	 DEF_INST_top_DEF_counter_0_SLT_8_1_AND_jj_1_repeat_count_read___ETC___d95 = DEF_INST_top_DEF_counter_0_SLT_8_1_AND_jj_1_repeat_count_read___ETC___d81 && (DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_14___d77);
	 DEF_INST_top_DEF_counter_0_SLT_8_1_AND_jj_1_repeat_count_read___ETC___d86 = (DEF_INST_top_DEF_counter_0_SLT_8_1_AND_jj_1_repeat_count_read___ETC___d81 && (DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_9___d76)) || (DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)10u);
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l83c17 = INST_top.DEF_state_can_overlap__h6285 && (DEF_INST_top_DEF_counter_0_SLT_8_1_AND_jj_1_repeat_count_read___ETC___d86 || (DEF_INST_top_DEF_NOT_jj_1_repeat_count_read__2_BIT_0_3_4_AND_NO_ETC___d91 || DEF_INST_top_DEF_counter_0_SLT_8_1_AND_jj_1_repeat_count_read___ETC___d95));
	 DEF_INST_top_DEF_WILL_FIRE_RL_action_ovlp_r_update_l83c17 = DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l83c17;
	 DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_15___d115 = DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)15u;
	 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d79 = DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && (DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_9___d76 || DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_14___d77);
	 DEF_INST_top_DEF_NOT_jj_2_repeat_count_read__08_BIT_0_09___d110 = !DEF_INST_top_DEF_jj_2_repeat_count_read__08_BIT_0___d109;
	 DEF_INST_top_DEF_NOT_jj_2_repeat_count_read__08_BIT_0_09_10_AND_ETC___d122 = DEF_INST_top_DEF_NOT_jj_2_repeat_count_read__08_BIT_0_09___d110 && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d121;
	 DEF_INST_top_DEF_NOT_counter_0_SLT_8_1___d107 = !DEF_INST_top_DEF_counter_0_SLT_8___d71;
	 DEF_INST_top_DEF_NOT_counter_0_SLT_8_1_07_AND_jj_2_repeat_count_ETC___d114 = (DEF_INST_top_DEF_NOT_counter_0_SLT_8_1___d107 && DEF_INST_top_DEF_jj_2_repeat_count_read__08_BIT_0___d109) && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d79;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l94c13 = INST_top.DEF_state_can_overlap__h6285 && (DEF_INST_top_DEF_NOT_counter_0_SLT_8_1_07_AND_jj_2_repeat_count_ETC___d114 || ((DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_15___d115) || DEF_INST_top_DEF_NOT_jj_2_repeat_count_read__08_BIT_0_09_10_AND_ETC___d122));
	 DEF_INST_top_DEF_WILL_FIRE_RL_action_ovlp_r_update_l94c13 = DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l94c13;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l94c13 = (DEF_INST_top_DEF_NOT_counter_0_SLT_8_1___d107 && DEF_INST_top_DEF_NOT_jj_2_repeat_count_read__08_BIT_0_09___d110) && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d79;
	 INST_top.DEF_WILL_FIRE_RL_action_r_init_l94c13 = DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l94c13;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l75c13 = DEF_INST_top_DEF_NOT_jj_repeat_count_read__0_BIT_0_1___d52 && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d54;
	 INST_top.DEF_WILL_FIRE_RL_action_r_init_l75c13 = DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l75c13;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l83c17 = (DEF_INST_top_DEF_counter_0_SLT_8___d71 && DEF_INST_top_DEF_NOT_jj_1_repeat_count_read__2_BIT_0_3___d74) && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_AND_sta_ETC___d79;
	 INST_top.DEF_WILL_FIRE_RL_action_r_init_l83c17 = DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l83c17;
	 DEF_INST_top_DEF_state_fired__h70591 = INST_top.INST_state_fired.METH_read();
	 DEF_INST_top_DEF_start_reg_1__h70589 = INST_top.INST_start_reg_1.METH_read();
	 DEF_INST_top_DEF_running__h78544 = INST_top.INST_running.METH_read();
	 DEF_INST_top_DEF_start_reg__h78458 = INST_top.INST_start_reg.METH_read();
	 DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_19___d34 = DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)19u;
	 DEF_INST_top_DEF_abort_whas_AND_abort_wget___d6 = DEF_INST_top_DEF_abort_whas____d4 && DEF_INST_top_DEF_abort_wget____d5;
	 DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d35 = (DEF_INST_top_DEF_abort_whas_AND_abort_wget___d6 || DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)0u) || DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_19___d34;
	 DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d152 = DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d35 && (!DEF_INST_top_DEF_start_reg_1__h70589 || DEF_INST_top_DEF_state_fired__h70591);
	 DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d156 = DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d152 && !DEF_INST_top_DEF_start_reg__h78458;
	 DEF_INST_top_DEF_CAN_FIRE_RL_auto_finish = DEF_INST_top_DEF_running__h78544 && DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d156;
	 DEF_INST_top_DEF_WILL_FIRE_RL_auto_finish = DEF_INST_top_DEF_CAN_FIRE_RL_auto_finish;
	 DEF_INST_top_DEF_CAN_FIRE_RL_auto_start = DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d156 && !DEF_INST_top_DEF_running__h78544;
	 DEF_INST_top_DEF_WILL_FIRE_RL_auto_start = DEF_INST_top_DEF_CAN_FIRE_RL_auto_start;
	 DEF_INST_top_DEF_CAN_FIRE_RL_fsm_start = DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d152 && DEF_INST_top_DEF_start_reg__h78458;
	 DEF_INST_top_DEF_WILL_FIRE_RL_fsm_start = DEF_INST_top_DEF_CAN_FIRE_RL_fsm_start;
	 DEF_INST_top_DEF_CAN_FIRE_RL_restart = (DEF_INST_top_DEF_start_reg_1__h70589 && !DEF_INST_top_DEF_state_fired__h70591) && DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28;
	 DEF_INST_top_DEF_WILL_FIRE_RL_restart = DEF_INST_top_DEF_CAN_FIRE_RL_restart;
	 DEF_INST_top_DEF_CAN_FIRE_RL_start_reg__dreg_update = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_start_reg__dreg_update = DEF_INST_top_DEF_CAN_FIRE_RL_start_reg__dreg_update;
	 DEF_INST_top_DEF_CAN_FIRE_RL_state_every = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_state_every = DEF_INST_top_DEF_CAN_FIRE_RL_state_every;
	 DEF_INST_top_DEF_CAN_FIRE_RL_state_fired__dreg_update = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_state_fired__dreg_update = DEF_INST_top_DEF_CAN_FIRE_RL_state_fired__dreg_update;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_10 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_10 = DEF_INST_top_DEF_CAN_FIRE___me_check_10;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_11 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_11 = DEF_INST_top_DEF_CAN_FIRE___me_check_11;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_12 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_12 = DEF_INST_top_DEF_CAN_FIRE___me_check_12;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_13 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_13 = DEF_INST_top_DEF_CAN_FIRE___me_check_13;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_14 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_14 = DEF_INST_top_DEF_CAN_FIRE___me_check_14;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_15 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_15 = DEF_INST_top_DEF_CAN_FIRE___me_check_15;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_16 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_16 = DEF_INST_top_DEF_CAN_FIRE___me_check_16;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_5 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_5 = DEF_INST_top_DEF_CAN_FIRE___me_check_5;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_6 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_6 = DEF_INST_top_DEF_CAN_FIRE___me_check_6;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_7 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_7 = DEF_INST_top_DEF_CAN_FIRE___me_check_7;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_8 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_8 = DEF_INST_top_DEF_CAN_FIRE___me_check_8;
	 DEF_INST_top_DEF_CAN_FIRE___me_check_9 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE___me_check_9 = DEF_INST_top_DEF_CAN_FIRE___me_check_9;
	 DEF_INST_top_INST_dut_DEF_CAN_FIRE_RL_tick_gen = (tUInt8)1u;
	 DEF_INST_top_INST_dut_DEF_WILL_FIRE_RL_tick_gen = DEF_INST_top_INST_dut_DEF_CAN_FIRE_RL_tick_gen;
	 if (INST_top.DEF_WILL_FIRE_RL_action_f_init_l82c13)
	   INST_top.RL_action_f_init_l82c13();
	 if (INST_top.DEF_WILL_FIRE_RL_action_f_update_l82c13)
	   INST_top.RL_action_f_update_l82c13();
	 if (INST_top.DEF_WILL_FIRE_RL_action_l102c13)
	   INST_top.RL_action_l102c13();
	 if (INST_top.DEF_WILL_FIRE_RL_action_l61c13)
	   INST_top.RL_action_l61c13();
	 if (INST_top.DEF_WILL_FIRE_RL_action_l68c16)
	   INST_top.RL_action_l68c16();
	 if (INST_top.DEF_WILL_FIRE_RL_action_l69c13)
	   INST_top.RL_action_l69c13();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_action_ovlp_r_update_l75c13)
	   INST_top.RL_action_ovlp_r_update_l75c13();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_action_ovlp_r_update_l83c17)
	   INST_top.RL_action_ovlp_r_update_l83c17();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_action_ovlp_r_update_l94c13)
	   INST_top.RL_action_ovlp_r_update_l94c13();
	 if (INST_top.DEF_WILL_FIRE_RL_action_r_init_l75c13)
	   INST_top.RL_action_r_init_l75c13();
	 if (INST_top.DEF_WILL_FIRE_RL_action_r_init_l83c17)
	   INST_top.RL_action_r_init_l83c17();
	 if (INST_top.DEF_WILL_FIRE_RL_action_r_init_l94c13)
	   INST_top.RL_action_r_init_l94c13();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_fsm_start)
	   INST_top.RL_fsm_start();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_auto_start)
	   INST_top.RL_auto_start();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_restart)
	   INST_top.RL_restart();
	 DEF_INST_top_DEF_start_wire_whas____d7 = INST_top.INST_start_wire.METH_whas();
	 DEF_INST_top_DEF_start_wire_wget____d9 = INST_top.INST_start_wire.METH_wget();
	 DEF_INST_top_DEF_start_wire_whas_AND_start_wire_wget___d30 = DEF_INST_top_DEF_start_wire_whas____d7 && DEF_INST_top_DEF_start_wire_wget____d9;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_l60c13 = (DEF_INST_top_DEF_start_wire_whas_AND_start_wire_wget___d30 && DEF_INST_top_DEF_abort_whas_AND_abort_wget_OR_state_mkFSMstate__ETC___d35) && !((((DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l94c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l83c17) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l75c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l102c13)) || ((DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l94c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l82c13) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l83c17 || DEF_INST_top_DEF_CAN_FIRE_RL_action_f_init_l82c13))) || ((DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l75c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l69c13) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_l68c16 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l61c13)));
	 INST_top.DEF_WILL_FIRE_RL_action_l60c13 = DEF_INST_top_DEF_CAN_FIRE_RL_action_l60c13;
	 DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_OR_star_ETC___d56 = DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 || DEF_INST_top_DEF_start_wire_whas_AND_start_wire_wget___d30;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_l75c25 = (DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_OR_star_ETC___d56 && (DEF_INST_top_DEF_jj_repeat_count_read__0_BIT_0_1_AND_NOT_abort__ETC___d60 || ((DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)6u) || DEF_INST_top_DEF_NOT_jj_repeat_count_read__0_BIT_0_1_2_AND_NOT__ETC___d65))) && !((((DEF_INST_top_DEF_CAN_FIRE_RL_auto_start || DEF_INST_top_DEF_CAN_FIRE_RL_fsm_start) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l94c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l83c17)) || ((DEF_INST_top_DEF_CAN_FIRE_RL_action_l102c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l94c13) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l82c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l83c17))) || (((DEF_INST_top_DEF_CAN_FIRE_RL_action_f_init_l82c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l75c13) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_l69c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l68c16)) || DEF_INST_top_DEF_CAN_FIRE_RL_action_l61c13));
	 INST_top.DEF_WILL_FIRE_RL_action_l75c25 = DEF_INST_top_DEF_CAN_FIRE_RL_action_l75c25;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_l83c29 = (DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_OR_star_ETC___d56 && ((DEF_INST_top_DEF_counter_0_SLT_8_1_AND_jj_1_repeat_count_read___ETC___d86 || ((DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)11u) || DEF_INST_top_DEF_NOT_jj_1_repeat_count_read__2_BIT_0_3_4_AND_NO_ETC___d91)) || DEF_INST_top_DEF_counter_0_SLT_8_1_AND_jj_1_repeat_count_read___ETC___d95)) && !((((DEF_INST_top_DEF_CAN_FIRE_RL_auto_start || DEF_INST_top_DEF_CAN_FIRE_RL_fsm_start) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l94c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l75c13)) || ((DEF_INST_top_DEF_CAN_FIRE_RL_action_l102c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l94c13) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l82c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l83c17))) || (((DEF_INST_top_DEF_CAN_FIRE_RL_action_f_init_l82c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l75c13) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_l69c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l68c16)) || DEF_INST_top_DEF_CAN_FIRE_RL_action_l61c13));
	 INST_top.DEF_WILL_FIRE_RL_action_l83c29 = DEF_INST_top_DEF_CAN_FIRE_RL_action_l83c29;
	 DEF_INST_top_DEF_CAN_FIRE_RL_action_l94c25 = (DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7_8_OR_star_ETC___d56 && ((DEF_INST_top_DEF_NOT_counter_0_SLT_8_1_07_AND_jj_2_repeat_count_ETC___d114 || (DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && (DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_15___d115 || DEF_INST_top_DEF_state_mkFSMstate_read____d31 == (tUInt8)16u))) || DEF_INST_top_DEF_NOT_jj_2_repeat_count_read__08_BIT_0_09_10_AND_ETC___d122)) && !((((DEF_INST_top_DEF_CAN_FIRE_RL_auto_start || DEF_INST_top_DEF_CAN_FIRE_RL_fsm_start) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l83c17 || DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l75c13)) || ((DEF_INST_top_DEF_CAN_FIRE_RL_action_l102c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l94c13) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l82c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l83c17))) || (((DEF_INST_top_DEF_CAN_FIRE_RL_action_f_init_l82c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l75c13) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_l69c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l68c16)) || DEF_INST_top_DEF_CAN_FIRE_RL_action_l61c13));
	 INST_top.DEF_WILL_FIRE_RL_action_l94c25 = DEF_INST_top_DEF_CAN_FIRE_RL_action_l94c25;
	 DEF_INST_top_DEF_NOT_start_wire_whas_OR_NOT_start_wire_wget_0___d11 = !DEF_INST_top_DEF_start_wire_whas____d7 || !DEF_INST_top_DEF_start_wire_wget____d9;
	 DEF_INST_top_DEF_CAN_FIRE_RL_idle_l59c18 = (DEF_INST_top_DEF_NOT_start_wire_whas_OR_NOT_start_wire_wget_0___d11 && (DEF_INST_top_DEF_NOT_abort_whas_6_OR_NOT_abort_wget_7___d28 && DEF_INST_top_DEF_state_mkFSMstate_read__1_EQ_19___d34)) && !((((DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l94c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l83c17) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l75c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l102c13)) || ((DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l94c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l82c13) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l83c17 || DEF_INST_top_DEF_CAN_FIRE_RL_action_f_init_l82c13))) || ((DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l75c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l69c13) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_l68c16 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l61c13)));
	 DEF_INST_top_DEF_WILL_FIRE_RL_idle_l59c18 = DEF_INST_top_DEF_CAN_FIRE_RL_idle_l59c18;
	 DEF_INST_top_DEF_CAN_FIRE_RL_state_handle_abort = (DEF_INST_top_DEF_abort_whas_AND_abort_wget___d6 && DEF_INST_top_DEF_NOT_start_wire_whas_OR_NOT_start_wire_wget_0___d11) && !((((DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l94c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l83c17) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_ovlp_r_update_l75c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l102c13)) || ((DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l94c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_f_update_l82c13) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l83c17 || DEF_INST_top_DEF_CAN_FIRE_RL_action_f_init_l82c13))) || (((DEF_INST_top_DEF_CAN_FIRE_RL_action_r_init_l75c13 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l69c13) || (DEF_INST_top_DEF_CAN_FIRE_RL_action_l68c16 || DEF_INST_top_DEF_CAN_FIRE_RL_action_l61c13)) || DEF_INST_top_DEF_CAN_FIRE_RL_restart));
	 DEF_INST_top_DEF_WILL_FIRE_RL_state_handle_abort = DEF_INST_top_DEF_CAN_FIRE_RL_state_handle_abort;
	 if (INST_top.DEF_WILL_FIRE_RL_action_l60c13)
	   INST_top.RL_action_l60c13();
	 if (INST_top.DEF_WILL_FIRE_RL_action_l75c25)
	   INST_top.RL_action_l75c25();
	 if (INST_top.DEF_WILL_FIRE_RL_action_l83c29)
	   INST_top.RL_action_l83c29();
	 if (INST_top.DEF_WILL_FIRE_RL_action_l94c25)
	   INST_top.RL_action_l94c25();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_auto_finish)
	   INST_top.RL_auto_finish();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_start_reg__dreg_update)
	   INST_top.RL_start_reg__dreg_update();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_state_handle_abort)
	   INST_top.RL_state_handle_abort();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_5)
	   INST_top.__me_check_5();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_6)
	   INST_top.__me_check_6();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_7)
	   INST_top.__me_check_7();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_8)
	   INST_top.__me_check_8();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_9)
	   INST_top.__me_check_9();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_10)
	   INST_top.__me_check_10();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_11)
	   INST_top.__me_check_11();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_12)
	   INST_top.__me_check_12();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_13)
	   INST_top.__me_check_13();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_14)
	   INST_top.__me_check_14();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_16)
	   INST_top.__me_check_16();
	 if (DEF_INST_top_DEF_WILL_FIRE___me_check_15)
	   INST_top.__me_check_15();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_idle_l59c18)
	   INST_top.RL_idle_l59c18();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_state_every)
	   INST_top.RL_state_every();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_state_fired__dreg_update)
	   INST_top.RL_state_fired__dreg_update();
	 if (DEF_INST_top_INST_dut_DEF_WILL_FIRE_RL_tick_gen)
	   INST_top.INST_dut.RL_tick_gen();
	 DEF_INST_top_INST_dut_DEF_CAN_FIRE_RL_send_bit = INST_top.INST_dut.INST_fTX.METH_i_notEmpty() && INST_top.INST_dut.INST_pwTick.METH_whas();
	 DEF_INST_top_INST_dut_DEF_WILL_FIRE_RL_send_bit = DEF_INST_top_INST_dut_DEF_CAN_FIRE_RL_send_bit;
	 if (DEF_INST_top_INST_dut_DEF_WILL_FIRE_RL_send_bit)
	   INST_top.INST_dut.RL_send_bit();
	 INST_top.INST_state_fired_1.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_state_overlap_pw.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_state_set_pw.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_abort.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_start_reg_2.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_start_wire.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_dut.INST_pwTick.clk((tUInt8)1u, (tUInt8)1u);
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_dut.INST_fTX.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_dut.INST_rOutputPin.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_dut.INST_rCounter.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_dut.INST_rOut.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_dut.INST_rBitIndex.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_counter.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_mistakes.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_start_reg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_start_reg_1.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_jj_repeat_count.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_jj_1_repeat_count.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_jj_2_repeat_count.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_state_mkFSMstate.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_state_fired.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_state_can_overlap.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_running.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkTB2::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkTB2_instance = new MOD_mkTB2(sim_hdl, "top", NULL);
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
  (mkTB2_instance->INST_dut.INST_fTX.set_clk_0)("CLK");
  (mkTB2_instance->INST_dut.INST_pwTick.set_clk_0)("CLK");
  (mkTB2_instance->INST_dut.set_clk_0)("CLK");
  (mkTB2_instance->INST_start_wire.set_clk_0)("CLK");
  (mkTB2_instance->INST_start_reg_2.set_clk_0)("CLK");
  (mkTB2_instance->INST_abort.set_clk_0)("CLK");
  (mkTB2_instance->INST_state_set_pw.set_clk_0)("CLK");
  (mkTB2_instance->INST_state_overlap_pw.set_clk_0)("CLK");
  (mkTB2_instance->INST_state_fired_1.set_clk_0)("CLK");
  (mkTB2_instance->set_clk_0)("CLK");
}
void MODEL_mkTB2::destroy_model()
{
  delete mkTB2_instance;
  mkTB2_instance = NULL;
}
void MODEL_mkTB2::reset_model(bool asserted)
{
  (mkTB2_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkTB2::get_instance()
{
  return mkTB2_instance;
}

/* Fill in version numbers */
void MODEL_mkTB2::get_version(char const **name, char const **build)
{
  *name = "2023.07";
  *build = "0eb551dc";
}

/* Get the model creation time */
time_t MODEL_mkTB2::get_creation_time()
{
  
  /* Tue Feb 13 16:46:46 UTC 2024 */
  return 1707842806llu;
}

/* State dumping function */
void MODEL_mkTB2::dump_state()
{
  (mkTB2_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkTB2 & mkTB2_backing(tSimStateHdl simHdl)
{
  static MOD_mkTB2 *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkTB2(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkTB2::dump_VCD_defs()
{
  (mkTB2_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkTB2::dump_VCD(tVCDDumpType dt)
{
  (mkTB2_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkTB2_backing(sim_hdl));
}
/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Thu Feb 15 17:02:18 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkToPutTestTb.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkToPutTestTb::MODEL_mkToPutTestTb()
{
  mkToPutTestTb_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkToPutTestTb()
{
  MODEL_mkToPutTestTb *model = new MODEL_mkToPutTestTb();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkToPutTestTb &INST_top = *((MOD_mkToPutTestTb *)(instance_ptr));
	 tUInt8 DEF_INST_top_DEF_bol___d6;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_server_do_sth;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_server_do_sth;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_calc;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_calc;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_r2;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_r2;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_r3;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_r3;
	 DEF_INST_top_DEF_bol___d6 = INST_top.INST_bol.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_calc = INST_top.INST_server_fifo_in.METH_i_notFull() && !DEF_INST_top_DEF_bol___d6;
	 DEF_INST_top_DEF_WILL_FIRE_RL_calc = DEF_INST_top_DEF_CAN_FIRE_RL_calc;
	 DEF_INST_top_DEF_CAN_FIRE_RL_r2 = INST_top.INST_server_fifo_out.METH_i_notEmpty();
	 DEF_INST_top_DEF_WILL_FIRE_RL_r2 = DEF_INST_top_DEF_CAN_FIRE_RL_r2;
	 DEF_INST_top_DEF_CAN_FIRE_RL_r3 = DEF_INST_top_DEF_bol___d6;
	 DEF_INST_top_DEF_WILL_FIRE_RL_r3 = DEF_INST_top_DEF_CAN_FIRE_RL_r3;
	 DEF_INST_top_DEF_CAN_FIRE_RL_server_do_sth = INST_top.INST_server_fifo_in.METH_i_notEmpty() && INST_top.INST_server_fifo_out.METH_i_notFull();
	 DEF_INST_top_DEF_WILL_FIRE_RL_server_do_sth = DEF_INST_top_DEF_CAN_FIRE_RL_server_do_sth;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_calc)
	   INST_top.RL_calc();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_r3)
	   INST_top.RL_r3();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_r2)
	   INST_top.RL_r2();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_server_do_sth)
	   INST_top.RL_server_do_sth();
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_server_fifo_in.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_server_fifo_out.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_bol.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkToPutTestTb::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkToPutTestTb_instance = new MOD_mkToPutTestTb(sim_hdl, "top", NULL);
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
  (mkToPutTestTb_instance->INST_server_fifo_in.set_clk_0)("CLK");
  (mkToPutTestTb_instance->INST_server_fifo_out.set_clk_0)("CLK");
  (mkToPutTestTb_instance->set_clk_0)("CLK");
}
void MODEL_mkToPutTestTb::destroy_model()
{
  delete mkToPutTestTb_instance;
  mkToPutTestTb_instance = NULL;
}
void MODEL_mkToPutTestTb::reset_model(bool asserted)
{
  (mkToPutTestTb_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkToPutTestTb::get_instance()
{
  return mkToPutTestTb_instance;
}

/* Fill in version numbers */
void MODEL_mkToPutTestTb::get_version(char const **name, char const **build)
{
  *name = "2023.07";
  *build = "0eb551dc";
}

/* Get the model creation time */
time_t MODEL_mkToPutTestTb::get_creation_time()
{
  
  /* Thu Feb 15 16:02:18 UTC 2024 */
  return 1708012938llu;
}

/* State dumping function */
void MODEL_mkToPutTestTb::dump_state()
{
  (mkToPutTestTb_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkToPutTestTb & mkToPutTestTb_backing(tSimStateHdl simHdl)
{
  static MOD_mkToPutTestTb *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkToPutTestTb(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkToPutTestTb::dump_VCD_defs()
{
  (mkToPutTestTb_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkToPutTestTb::dump_VCD(tVCDDumpType dt)
{
  (mkToPutTestTb_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkToPutTestTb_backing(sim_hdl));
}
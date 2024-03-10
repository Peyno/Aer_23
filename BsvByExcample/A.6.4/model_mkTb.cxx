/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Tue Jan  9 16:23:00 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkTb.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkTb::MODEL_mkTb()
{
  mkTb_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkTb()
{
  MODEL_mkTb *model = new MODEL_mkTb();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkTb &INST_top = *((MOD_mkTb *)(instance_ptr));
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_rx;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_rx;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_ry0;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_ry1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_ry0;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_ry1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_ry2;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_ry2;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_done;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_done;
	 INST_top.DEF_b__h189 = INST_top.INST_cycle.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_done = !primSLT8(1u, 32u, (tUInt32)(INST_top.DEF_b__h189), 32u, 10u);
	 DEF_INST_top_DEF_WILL_FIRE_RL_done = DEF_INST_top_DEF_CAN_FIRE_RL_done;
	 DEF_INST_top_DEF_CAN_FIRE_RL_rx = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_rx = DEF_INST_top_DEF_CAN_FIRE_RL_rx;
	 INST_top.DEF_x__h459 = INST_top.INST_x.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_ry0 = (tUInt8)((tUInt8)1u & (INST_top.DEF_x__h459));
	 DEF_INST_top_DEF_WILL_FIRE_RL_ry0 = DEF_INST_top_DEF_CAN_FIRE_RL_ry0;
	 DEF_INST_top_DEF_CAN_FIRE_RL_ry1 = (tUInt8)((tUInt8)1u & ((INST_top.DEF_x__h459) >> 1u));
	 DEF_INST_top_DEF_WILL_FIRE_RL_ry1 = DEF_INST_top_DEF_CAN_FIRE_RL_ry1 && !DEF_INST_top_DEF_WILL_FIRE_RL_ry0;
	 INST_top.DEF_x_BIT_2___h278 = (tUInt8)((INST_top.DEF_x__h459) >> 2u);
	 DEF_INST_top_DEF_CAN_FIRE_RL_ry2 = INST_top.DEF_x_BIT_2___h278;
	 DEF_INST_top_DEF_WILL_FIRE_RL_ry2 = (DEF_INST_top_DEF_CAN_FIRE_RL_ry2 && !DEF_INST_top_DEF_WILL_FIRE_RL_ry1) && !DEF_INST_top_DEF_WILL_FIRE_RL_ry0;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_ry0)
	   INST_top.RL_ry0();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_ry1)
	   INST_top.RL_ry1();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_ry2)
	   INST_top.RL_ry2();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_done)
	   INST_top.RL_done();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_rx)
	   INST_top.RL_rx();
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_x.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_cycle.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_y.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkTb::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkTb_instance = new MOD_mkTb(sim_hdl, "top", NULL);
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
  (mkTb_instance->set_clk_0)("CLK");
}
void MODEL_mkTb::destroy_model()
{
  delete mkTb_instance;
  mkTb_instance = NULL;
}
void MODEL_mkTb::reset_model(bool asserted)
{
  (mkTb_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkTb::get_instance()
{
  return mkTb_instance;
}

/* Fill in version numbers */
void MODEL_mkTb::get_version(char const **name, char const **build)
{
  *name = "2023.07";
  *build = "0eb551dc";
}

/* Get the model creation time */
time_t MODEL_mkTb::get_creation_time()
{
  
  /* Tue Jan  9 15:23:00 UTC 2024 */
  return 1704813780llu;
}

/* State dumping function */
void MODEL_mkTb::dump_state()
{
  (mkTb_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkTb & mkTb_backing(tSimStateHdl simHdl)
{
  static MOD_mkTb *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkTb(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkTb::dump_VCD_defs()
{
  (mkTb_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkTb::dump_VCD(tVCDDumpType dt)
{
  (mkTb_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkTb_backing(sim_hdl));
}

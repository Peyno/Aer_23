/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Tue Jan  9 17:36:38 CET 2024
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
	 tUInt8 DEF_INST_top_INST_foo_DEF_CAN_FIRE_RL_count_cycles;
	 tUInt8 DEF_INST_top_INST_foo_DEF_WILL_FIRE_RL_count_cycles;
	 tUInt8 DEF_INST_top_INST_foo_DEF_CAN_FIRE_RL_incx;
	 tUInt8 DEF_INST_top_INST_foo_DEF_WILL_FIRE_RL_incx;
	 tUInt8 DEF_INST_top_INST_foo_DEF_CAN_FIRE_RL_incy;
	 tUInt8 DEF_INST_top_INST_foo_DEF_WILL_FIRE_RL_incy;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_rAVX;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_rAVX;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_rAY;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_rAY;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_rVY;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_rVY;
	 INST_top.INST_foo.PORT_EN_avx = (tUInt8)0u;
	 INST_top.INST_foo.DEF_WILL_FIRE_avx = (tUInt8)0u;
	 INST_top.INST_foo.METH_RDY_avx();
	 DEF_INST_top_DEF_CAN_FIRE_RL_rAVX = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_rAVX = DEF_INST_top_DEF_CAN_FIRE_RL_rAVX;
	 INST_top.INST_foo.METH_RDY_ay();
	 DEF_INST_top_DEF_CAN_FIRE_RL_rAY = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_rAY = DEF_INST_top_DEF_CAN_FIRE_RL_rAY;
	 DEF_INST_top_DEF_CAN_FIRE_RL_rVY = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_rVY = DEF_INST_top_DEF_CAN_FIRE_RL_rVY;
	 DEF_INST_top_INST_foo_DEF_CAN_FIRE_RL_count_cycles = (tUInt8)1u;
	 DEF_INST_top_INST_foo_DEF_WILL_FIRE_RL_count_cycles = DEF_INST_top_INST_foo_DEF_CAN_FIRE_RL_count_cycles;
	 DEF_INST_top_INST_foo_DEF_CAN_FIRE_RL_incy = (tUInt8)1u;
	 DEF_INST_top_INST_foo_DEF_WILL_FIRE_RL_incy = DEF_INST_top_INST_foo_DEF_CAN_FIRE_RL_incy;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_rAVX)
	   INST_top.RL_rAVX();
	 INST_top.INST_foo.DEF_WILL_FIRE_avx = INST_top.INST_foo.PORT_EN_avx;
	 DEF_INST_top_INST_foo_DEF_CAN_FIRE_RL_incx = (tUInt8)1u;
	 DEF_INST_top_INST_foo_DEF_WILL_FIRE_RL_incx = DEF_INST_top_INST_foo_DEF_CAN_FIRE_RL_incx && !(INST_top.INST_foo.DEF_WILL_FIRE_avx);
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_rVY)
	   INST_top.RL_rVY();
	 if (DEF_INST_top_INST_foo_DEF_WILL_FIRE_RL_incx)
	   INST_top.INST_foo.RL_incx();
	 if (DEF_INST_top_INST_foo_DEF_WILL_FIRE_RL_incy)
	   INST_top.INST_foo.RL_incy();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_rAY)
	   INST_top.RL_rAY();
	 if (DEF_INST_top_INST_foo_DEF_WILL_FIRE_RL_count_cycles)
	   INST_top.INST_foo.RL_count_cycles();
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_foo.INST_x.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_foo.INST_y.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_foo.INST_cycle.rst_tick__clk__1((tUInt8)1u);
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
  (mkTb_instance->INST_foo.set_clk_0)("CLK");
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
  
  /* Tue Jan  9 16:36:38 UTC 2024 */
  return 1704818198llu;
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

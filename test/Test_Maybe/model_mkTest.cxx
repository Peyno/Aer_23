/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Wed Jan 24 18:45:15 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkTest.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkTest::MODEL_mkTest()
{
  mkTest_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkTest()
{
  MODEL_mkTest *model = new MODEL_mkTest();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkTest &INST_top = *((MOD_mkTest *)(instance_ptr));
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_r1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_r1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_foo;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_foo;
	 DEF_INST_top_DEF_CAN_FIRE_RL_r1 = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_r1 = DEF_INST_top_DEF_CAN_FIRE_RL_r1;
	 DEF_INST_top_DEF_CAN_FIRE_RL_foo = !((tUInt8)(INST_top.INST_b.METH_read() >> 32u));
	 DEF_INST_top_DEF_WILL_FIRE_RL_foo = DEF_INST_top_DEF_CAN_FIRE_RL_foo && !DEF_INST_top_DEF_WILL_FIRE_RL_r1;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_foo)
	   INST_top.RL_foo();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_r1)
	   INST_top.RL_r1();
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_bool.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkTest::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkTest_instance = new MOD_mkTest(sim_hdl, "top", NULL);
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
  (mkTest_instance->set_clk_0)("CLK");
}
void MODEL_mkTest::destroy_model()
{
  delete mkTest_instance;
  mkTest_instance = NULL;
}
void MODEL_mkTest::reset_model(bool asserted)
{
  (mkTest_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkTest::get_instance()
{
  return mkTest_instance;
}

/* Fill in version numbers */
void MODEL_mkTest::get_version(char const **name, char const **build)
{
  *name = "2023.07";
  *build = "0eb551dc";
}

/* Get the model creation time */
time_t MODEL_mkTest::get_creation_time()
{
  
  /* Wed Jan 24 17:45:15 UTC 2024 */
  return 1706118315llu;
}

/* State dumping function */
void MODEL_mkTest::dump_state()
{
  (mkTest_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkTest & mkTest_backing(tSimStateHdl simHdl)
{
  static MOD_mkTest *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkTest(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkTest::dump_VCD_defs()
{
  (mkTest_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkTest::dump_VCD(tVCDDumpType dt)
{
  (mkTest_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkTest_backing(sim_hdl));
}
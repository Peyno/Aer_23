/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Mon Jan 15 17:30:16 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkHelloTestbench.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkHelloTestbench::MODEL_mkHelloTestbench()
{
  mkHelloTestbench_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkHelloTestbench()
{
  MODEL_mkHelloTestbench *model = new MODEL_mkHelloTestbench();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkHelloTestbench &INST_top = *((MOD_mkHelloTestbench *)(instance_ptr));
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_dut_count;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_dut_count;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_dut_hellodisplay;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_dut_hellodisplay;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_checkLedStatus;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_checkLedStatus;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_counterIncr;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_counterIncr;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_endSimulation;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_endSimulation;
	 DEF_INST_top_DEF_CAN_FIRE_RL_checkLedStatus = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_checkLedStatus = DEF_INST_top_DEF_CAN_FIRE_RL_checkLedStatus;
	 DEF_INST_top_DEF_CAN_FIRE_RL_counterIncr = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_counterIncr = DEF_INST_top_DEF_CAN_FIRE_RL_counterIncr;
	 DEF_INST_top_DEF_CAN_FIRE_RL_dut_count = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_dut_count = DEF_INST_top_DEF_CAN_FIRE_RL_dut_count;
	 INST_top.DEF_b__h118 = INST_top.INST_dut_counter.METH_read();
	 INST_top.DEF_dut_counter_EQ_0x1FFFFFF___d2 = (INST_top.DEF_b__h118) == 33554431u;
	 DEF_INST_top_DEF_CAN_FIRE_RL_dut_hellodisplay = INST_top.DEF_dut_counter_EQ_0x1FFFFFF___d2;
	 DEF_INST_top_DEF_WILL_FIRE_RL_dut_hellodisplay = DEF_INST_top_DEF_CAN_FIRE_RL_dut_hellodisplay;
	 INST_top.DEF_b__h383 = INST_top.INST_counter.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_endSimulation = (INST_top.DEF_b__h383) == 200000000u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_endSimulation = DEF_INST_top_DEF_CAN_FIRE_RL_endSimulation;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_checkLedStatus)
	   INST_top.RL_checkLedStatus();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_endSimulation)
	   INST_top.RL_endSimulation();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_counterIncr)
	   INST_top.RL_counterIncr();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_dut_hellodisplay)
	   INST_top.RL_dut_hellodisplay();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_dut_count)
	   INST_top.RL_dut_count();
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_dut_counter.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_dut_ledStatus.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_counter.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_ledLastCycle.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkHelloTestbench::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkHelloTestbench_instance = new MOD_mkHelloTestbench(sim_hdl, "top", NULL);
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
  (mkHelloTestbench_instance->set_clk_0)("CLK");
}
void MODEL_mkHelloTestbench::destroy_model()
{
  delete mkHelloTestbench_instance;
  mkHelloTestbench_instance = NULL;
}
void MODEL_mkHelloTestbench::reset_model(bool asserted)
{
  (mkHelloTestbench_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkHelloTestbench::get_instance()
{
  return mkHelloTestbench_instance;
}

/* Fill in version numbers */
void MODEL_mkHelloTestbench::get_version(char const **name, char const **build)
{
  *name = "2023.07";
  *build = "0eb551dc";
}

/* Get the model creation time */
time_t MODEL_mkHelloTestbench::get_creation_time()
{
  
  /* Mon Jan 15 16:30:16 UTC 2024 */
  return 1705336216llu;
}

/* State dumping function */
void MODEL_mkHelloTestbench::dump_state()
{
  (mkHelloTestbench_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkHelloTestbench & mkHelloTestbench_backing(tSimStateHdl simHdl)
{
  static MOD_mkHelloTestbench *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkHelloTestbench(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkHelloTestbench::dump_VCD_defs()
{
  (mkHelloTestbench_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkHelloTestbench::dump_VCD(tVCDDumpType dt)
{
  (mkHelloTestbench_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkHelloTestbench_backing(sim_hdl));
}

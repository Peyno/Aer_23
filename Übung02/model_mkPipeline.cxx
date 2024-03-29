/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Tue Nov 21 15:45:36 CET 2023
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkPipeline.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkPipeline::MODEL_mkPipeline()
{
  mkPipeline_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkPipeline()
{
  MODEL_mkPipeline *model = new MODEL_mkPipeline();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkPipeline &INST_top = *((MOD_mkPipeline *)(instance_ptr));
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_alltogether;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_alltogether;
	 DEF_INST_top_DEF_CAN_FIRE_RL_alltogether = INST_top.INST_fifo_in.METH_i_notEmpty() && INST_top.INST_fifo_out.METH_i_notFull();
	 DEF_INST_top_DEF_WILL_FIRE_RL_alltogether = DEF_INST_top_DEF_CAN_FIRE_RL_alltogether;
	 INST_top.DEF_WILL_FIRE_calc_put = INST_top.PORT_EN_calc_put;
	 INST_top.METH_RDY_calc_put();
	 INST_top.DEF_WILL_FIRE_calc_result = INST_top.PORT_EN_calc_result;
	 INST_top.METH_RDY_calc_result();
	 INST_top.DEF_WILL_FIRE_setParam = INST_top.PORT_EN_setParam;
	 INST_top.METH_RDY_setParam();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_alltogether)
	   INST_top.RL_alltogether();
	 if (INST_top.DEF_WILL_FIRE_calc_put)
	   INST_top.METH_calc_put(INST_top.PORT_calc_put_x);
	 if (INST_top.DEF_WILL_FIRE_calc_result)
	   INST_top.METH_calc_result();
	 if (INST_top.DEF_WILL_FIRE_setParam)
	   INST_top.METH_setParam(INST_top.PORT_setParam_addr, INST_top.PORT_setParam_val);
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_fifo_in.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_fifo_out.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_regs_0.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_regs_1.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_regs_2.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_regs_3.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkPipeline::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkPipeline_instance = new MOD_mkPipeline(sim_hdl, "top", NULL);
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
  (mkPipeline_instance->INST_fifo_in.set_clk_0)("CLK");
  (mkPipeline_instance->INST_fifo_out.set_clk_0)("CLK");
  (mkPipeline_instance->set_clk_0)("CLK");
}
void MODEL_mkPipeline::destroy_model()
{
  delete mkPipeline_instance;
  mkPipeline_instance = NULL;
}
void MODEL_mkPipeline::reset_model(bool asserted)
{
  (mkPipeline_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkPipeline::get_instance()
{
  return mkPipeline_instance;
}

/* Fill in version numbers */
void MODEL_mkPipeline::get_version(char const **name, char const **build)
{
  *name = "2023.07";
  *build = "0eb551dc";
}

/* Get the model creation time */
time_t MODEL_mkPipeline::get_creation_time()
{
  
  /* Tue Nov 21 14:45:36 UTC 2023 */
  return 1700577936llu;
}

/* State dumping function */
void MODEL_mkPipeline::dump_state()
{
  (mkPipeline_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkPipeline & mkPipeline_backing(tSimStateHdl simHdl)
{
  static MOD_mkPipeline *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkPipeline(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkPipeline::dump_VCD_defs()
{
  (mkPipeline_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkPipeline::dump_VCD(tVCDDumpType dt)
{
  (mkPipeline_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkPipeline_backing(sim_hdl));
}

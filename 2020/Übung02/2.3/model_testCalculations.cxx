/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Wed Jan 17 17:54:55 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "model_testCalculations.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_testCalculations::MODEL_testCalculations()
{
  testCalculations_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_testCalculations()
{
  MODEL_testCalculations *model = new MODEL_testCalculations();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_testCalculations &INST_top = *((MOD_testCalculations *)(instance_ptr));
	 tUInt8 DEF_INST_top_DEF_uut_initialised__h1440;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_uut_addA_doCalc;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_uut_addA_doCalc;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_uut_timesB_doCalc;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_uut_timesB_doCalc;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_uut_timesC_doCalc;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_uut_timesC_doCalc;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_uut_calcUnits_3_calc;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_uut_calcUnits_3_calc;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_uut_calcUnits_4_calc;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_uut_calcUnits_4_calc;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_uut_initialise;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_uut_initialise;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_uut_calc;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_uut_calc;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_uut_calc_1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_uut_calc_1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_uut_calc_2;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_uut_calc_2;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_uut_calc_3;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_uut_calc_3;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_uut_setupCalc;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_uut_setupCalc;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_uut_outputResult;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_uut_outputResult;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_printResult;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_printResult;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_putData;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_putData;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_countUp;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_countUp;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_endIt;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_endIt;
	 DEF_INST_top_DEF_CAN_FIRE_RL_countUp = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_countUp = DEF_INST_top_DEF_CAN_FIRE_RL_countUp;
	 INST_top.DEF_b__h2528 = INST_top.INST_cntr.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_endIt = (INST_top.DEF_b__h2528) == 40u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_endIt = DEF_INST_top_DEF_CAN_FIRE_RL_endIt;
	 DEF_INST_top_DEF_CAN_FIRE_RL_printResult = INST_top.INST_uut_outFIFO.METH_i_notEmpty();
	 DEF_INST_top_DEF_WILL_FIRE_RL_printResult = DEF_INST_top_DEF_CAN_FIRE_RL_printResult;
	 DEF_INST_top_DEF_CAN_FIRE_RL_putData = INST_top.INST_uut_inFIFO.METH_i_notFull();
	 DEF_INST_top_DEF_WILL_FIRE_RL_putData = DEF_INST_top_DEF_CAN_FIRE_RL_putData;
	 DEF_INST_top_DEF_CAN_FIRE_RL_uut_calc = INST_top.INST_uut_addA_r.METH_i_notEmpty();
	 DEF_INST_top_DEF_WILL_FIRE_RL_uut_calc = DEF_INST_top_DEF_CAN_FIRE_RL_uut_calc;
	 DEF_INST_top_DEF_CAN_FIRE_RL_uut_calc_1 = INST_top.INST_uut_timesB_r.METH_i_notEmpty();
	 DEF_INST_top_DEF_WILL_FIRE_RL_uut_calc_1 = DEF_INST_top_DEF_CAN_FIRE_RL_uut_calc_1;
	 DEF_INST_top_DEF_CAN_FIRE_RL_uut_calc_2 = INST_top.INST_uut_timesC_r.METH_i_notEmpty();
	 DEF_INST_top_DEF_WILL_FIRE_RL_uut_calc_2 = DEF_INST_top_DEF_CAN_FIRE_RL_uut_calc_2;
	 DEF_INST_top_DEF_CAN_FIRE_RL_uut_outputResult = INST_top.INST_uut_calcUnits_4_r.METH_i_notEmpty() && INST_top.INST_uut_outFIFO.METH_i_notFull();
	 DEF_INST_top_DEF_WILL_FIRE_RL_uut_outputResult = DEF_INST_top_DEF_CAN_FIRE_RL_uut_outputResult;
	 DEF_INST_top_DEF_CAN_FIRE_RL_uut_calc_3 = INST_top.INST_uut_calcUnits_3_r.METH_i_notEmpty();
	 DEF_INST_top_DEF_WILL_FIRE_RL_uut_calc_3 = DEF_INST_top_DEF_CAN_FIRE_RL_uut_calc_3;
	 DEF_INST_top_DEF_uut_initialised__h1440 = INST_top.INST_uut_initialised.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_uut_initialise = !DEF_INST_top_DEF_uut_initialised__h1440;
	 DEF_INST_top_DEF_WILL_FIRE_RL_uut_initialise = DEF_INST_top_DEF_CAN_FIRE_RL_uut_initialise;
	 DEF_INST_top_DEF_CAN_FIRE_RL_uut_setupCalc = INST_top.INST_uut_inFIFO.METH_i_notEmpty();
	 DEF_INST_top_DEF_WILL_FIRE_RL_uut_setupCalc = DEF_INST_top_DEF_CAN_FIRE_RL_uut_setupCalc;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_printResult)
	   INST_top.RL_printResult();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_putData)
	   INST_top.RL_putData();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_endIt)
	   INST_top.RL_endIt();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_countUp)
	   INST_top.RL_countUp();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_uut_calc)
	   INST_top.RL_uut_calc();
	 DEF_INST_top_DEF_CAN_FIRE_RL_uut_timesB_doCalc = INST_top.INST_uut_timesB_r.METH_i_notFull() && INST_top.INST_uut_timesB_a.METH_whas();
	 DEF_INST_top_DEF_WILL_FIRE_RL_uut_timesB_doCalc = DEF_INST_top_DEF_CAN_FIRE_RL_uut_timesB_doCalc;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_uut_calc_1)
	   INST_top.RL_uut_calc_1();
	 DEF_INST_top_DEF_CAN_FIRE_RL_uut_timesC_doCalc = INST_top.INST_uut_timesC_r.METH_i_notFull() && INST_top.INST_uut_timesC_a.METH_whas();
	 DEF_INST_top_DEF_WILL_FIRE_RL_uut_timesC_doCalc = DEF_INST_top_DEF_CAN_FIRE_RL_uut_timesC_doCalc;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_uut_calc_2)
	   INST_top.RL_uut_calc_2();
	 DEF_INST_top_DEF_CAN_FIRE_RL_uut_calcUnits_3_calc = INST_top.INST_uut_calcUnits_3_r.METH_i_notFull() && INST_top.INST_uut_calcUnits_3_a.METH_whas();
	 DEF_INST_top_DEF_WILL_FIRE_RL_uut_calcUnits_3_calc = DEF_INST_top_DEF_CAN_FIRE_RL_uut_calcUnits_3_calc;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_uut_calcUnits_3_calc)
	   INST_top.RL_uut_calcUnits_3_calc();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_uut_calc_3)
	   INST_top.RL_uut_calc_3();
	 DEF_INST_top_DEF_CAN_FIRE_RL_uut_calcUnits_4_calc = INST_top.INST_uut_calcUnits_4_r.METH_i_notFull() && INST_top.INST_uut_calcUnits_4_a.METH_whas();
	 DEF_INST_top_DEF_WILL_FIRE_RL_uut_calcUnits_4_calc = DEF_INST_top_DEF_CAN_FIRE_RL_uut_calcUnits_4_calc;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_uut_calcUnits_4_calc)
	   INST_top.RL_uut_calcUnits_4_calc();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_uut_outputResult)
	   INST_top.RL_uut_outputResult();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_uut_timesB_doCalc)
	   INST_top.RL_uut_timesB_doCalc();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_uut_setupCalc)
	   INST_top.RL_uut_setupCalc();
	 DEF_INST_top_DEF_CAN_FIRE_RL_uut_addA_doCalc = INST_top.INST_uut_addA_r.METH_i_notFull() && INST_top.INST_uut_addA_a.METH_whas();
	 DEF_INST_top_DEF_WILL_FIRE_RL_uut_addA_doCalc = DEF_INST_top_DEF_CAN_FIRE_RL_uut_addA_doCalc;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_uut_addA_doCalc)
	   INST_top.RL_uut_addA_doCalc();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_uut_timesC_doCalc)
	   INST_top.RL_uut_timesC_doCalc();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_uut_initialise)
	   INST_top.RL_uut_initialise();
	 INST_top.INST_uut_calcUnits_4_a.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_uut_calcUnits_3_a.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_uut_timesC_a.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_uut_timesB_a.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_uut_addA_a.clk((tUInt8)1u, (tUInt8)1u);
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_uut_a.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_uut_b.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_uut_c.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_uut_addA_p.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_uut_addA_r.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_uut_timesB_p.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_uut_timesB_r.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_uut_timesC_p.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_uut_timesC_r.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_uut_calcUnits_3_r.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_uut_calcUnits_4_r.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_uut_initialised.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_uut_inFIFO.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_uut_outFIFO.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_cntr.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_testCalculations::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  testCalculations_instance = new MOD_testCalculations(sim_hdl, "top", NULL);
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
  (testCalculations_instance->INST_uut_addA_a.set_clk_0)("CLK");
  (testCalculations_instance->INST_uut_addA_r.set_clk_0)("CLK");
  (testCalculations_instance->INST_uut_timesB_a.set_clk_0)("CLK");
  (testCalculations_instance->INST_uut_timesB_r.set_clk_0)("CLK");
  (testCalculations_instance->INST_uut_timesC_a.set_clk_0)("CLK");
  (testCalculations_instance->INST_uut_timesC_r.set_clk_0)("CLK");
  (testCalculations_instance->INST_uut_calcUnits_3_a.set_clk_0)("CLK");
  (testCalculations_instance->INST_uut_calcUnits_3_r.set_clk_0)("CLK");
  (testCalculations_instance->INST_uut_calcUnits_4_a.set_clk_0)("CLK");
  (testCalculations_instance->INST_uut_calcUnits_4_r.set_clk_0)("CLK");
  (testCalculations_instance->INST_uut_inFIFO.set_clk_0)("CLK");
  (testCalculations_instance->INST_uut_outFIFO.set_clk_0)("CLK");
  (testCalculations_instance->set_clk_0)("CLK");
}
void MODEL_testCalculations::destroy_model()
{
  delete testCalculations_instance;
  testCalculations_instance = NULL;
}
void MODEL_testCalculations::reset_model(bool asserted)
{
  (testCalculations_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_testCalculations::get_instance()
{
  return testCalculations_instance;
}

/* Fill in version numbers */
void MODEL_testCalculations::get_version(char const **name, char const **build)
{
  *name = "2023.07";
  *build = "0eb551dc";
}

/* Get the model creation time */
time_t MODEL_testCalculations::get_creation_time()
{
  
  /* Wed Jan 17 16:54:55 UTC 2024 */
  return 1705510495llu;
}

/* State dumping function */
void MODEL_testCalculations::dump_state()
{
  (testCalculations_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_testCalculations & testCalculations_backing(tSimStateHdl simHdl)
{
  static MOD_testCalculations *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_testCalculations(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_testCalculations::dump_VCD_defs()
{
  (testCalculations_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_testCalculations::dump_VCD(tVCDDumpType dt)
{
  (testCalculations_instance->dump_VCD)(dt, vcd_depth(sim_hdl), testCalculations_backing(sim_hdl));
}

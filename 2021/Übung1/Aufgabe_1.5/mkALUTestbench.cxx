/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Sat Feb 17 15:44:58 CET 2024
 * 
 */
#include "bluesim_primitives.h"
#include "mkALUTestbench.h"


/* String declarations */
static std::string const __str_literal_1("Result: %d", 10u);


/* Constructor */
MOD_mkALUTestbench::MOD_mkALUTestbench(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_testState(simHdl, "testState", this, 8u, (tUInt8)0u, (tUInt8)0u),
    INST_uut_newOperands(simHdl, "uut_newOperands", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_uut_opA(simHdl, "uut_opA", this, 32u, 0u, (tUInt8)0u),
    INST_uut_opB(simHdl, "uut_opB", this, 32u, 0u, (tUInt8)0u),
    INST_uut_operation(simHdl, "uut_operation", this, 3u, (tUInt8)0u, (tUInt8)0u),
    INST_uut_pow_opA(simHdl, "uut_pow_opA", this, 32u, 0u, (tUInt8)0u),
    INST_uut_pow_opB(simHdl, "uut_pow_opB", this, 32u, 0u, (tUInt8)0u),
    INST_uut_pow_result(simHdl, "uut_pow_result", this, 32u, 1u, (tUInt8)0u),
    INST_uut_pow_resultValid(simHdl, "uut_pow_resultValid", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_uut_result(simHdl, "uut_result", this, 32u, 0u, (tUInt8)0u),
    INST_uut_resultValid(simHdl, "uut_resultValid", this, 1u, (tUInt8)0u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 25u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkALUTestbench::init_symbols_0()
{
  init_symbol(&symbols[0u], "b__h405", SYM_DEF, &DEF_b__h405, 32u);
  init_symbol(&symbols[1u], "RL_checkAdd", SYM_RULE);
  init_symbol(&symbols[2u], "RL_checkAnd", SYM_RULE);
  init_symbol(&symbols[3u], "RL_checkDiv", SYM_RULE);
  init_symbol(&symbols[4u], "RL_checkMul", SYM_RULE);
  init_symbol(&symbols[5u], "RL_checkOr", SYM_RULE);
  init_symbol(&symbols[6u], "RL_checkPow", SYM_RULE);
  init_symbol(&symbols[7u], "RL_checkSub", SYM_RULE);
  init_symbol(&symbols[8u], "RL_endSim", SYM_RULE);
  init_symbol(&symbols[9u], "RL_printResults", SYM_RULE);
  init_symbol(&symbols[10u], "RL_uut_calculate", SYM_RULE);
  init_symbol(&symbols[11u], "RL_uut_pow_calc", SYM_RULE);
  init_symbol(&symbols[12u], "RL_uut_pow_calcDone", SYM_RULE);
  init_symbol(&symbols[13u], "testState", SYM_MODULE, &INST_testState);
  init_symbol(&symbols[14u], "testState__h2370", SYM_DEF, &DEF_testState__h2370, 8u);
  init_symbol(&symbols[15u], "uut_newOperands", SYM_MODULE, &INST_uut_newOperands);
  init_symbol(&symbols[16u], "uut_opA", SYM_MODULE, &INST_uut_opA);
  init_symbol(&symbols[17u], "uut_opB", SYM_MODULE, &INST_uut_opB);
  init_symbol(&symbols[18u], "uut_operation", SYM_MODULE, &INST_uut_operation);
  init_symbol(&symbols[19u], "uut_pow_opA", SYM_MODULE, &INST_uut_pow_opA);
  init_symbol(&symbols[20u], "uut_pow_opB", SYM_MODULE, &INST_uut_pow_opB);
  init_symbol(&symbols[21u], "uut_pow_result", SYM_MODULE, &INST_uut_pow_result);
  init_symbol(&symbols[22u], "uut_pow_resultValid", SYM_MODULE, &INST_uut_pow_resultValid);
  init_symbol(&symbols[23u], "uut_result", SYM_MODULE, &INST_uut_result);
  init_symbol(&symbols[24u], "uut_resultValid", SYM_MODULE, &INST_uut_resultValid);
}


/* Rule actions */

void MOD_mkALUTestbench::RL_uut_pow_calc()
{
  tUInt32 DEF_uut_pow_opB_MINUS_1___d4;
  tUInt32 DEF_uut_pow_result_MUL_uut_pow_opA_BITS_31_TO_0___d8;
  tUInt32 DEF_b__h472;
  DEF_b__h471 = INST_uut_pow_result.METH_read();
  DEF_b__h405 = INST_uut_pow_opB.METH_read();
  DEF_b__h472 = INST_uut_pow_opA.METH_read();
  DEF_uut_pow_result_MUL_uut_pow_opA_BITS_31_TO_0___d8 = (tUInt32)(((tUInt64)(DEF_b__h471)) * ((tUInt64)(DEF_b__h472)));
  DEF_uut_pow_opB_MINUS_1___d4 = DEF_b__h405 - 1u;
  INST_uut_pow_opB.METH_write(DEF_uut_pow_opB_MINUS_1___d4);
  INST_uut_pow_result.METH_write(DEF_uut_pow_result_MUL_uut_pow_opA_BITS_31_TO_0___d8);
}

void MOD_mkALUTestbench::RL_uut_pow_calcDone()
{
  INST_uut_pow_resultValid.METH_write((tUInt8)1u);
}

void MOD_mkALUTestbench::RL_uut_calculate()
{
  tUInt32 DEF_x__h689;
  tUInt32 DEF_x__h669;
  tUInt32 DEF_IF_uut_opA_0_BIT_31_5_THEN_NEG_uut_opA_0_2_ELS_ETC___d36;
  tUInt32 DEF_IF_uut_operation_8_EQ_0_9_THEN_uut_opA_0_MUL_u_ETC___d54;
  tUInt8 DEF_uut_opA_BIT_31___h682;
  tUInt8 DEF_uut_opB_BIT_31___h702;
  tUInt8 DEF_x__h646;
  tUInt32 DEF_x__h686;
  tUInt32 DEF_x__h706;
  DEF_b__h471 = INST_uut_pow_result.METH_read();
  DEF_x__h706 = INST_uut_opB.METH_read();
  DEF_x__h686 = INST_uut_opA.METH_read();
  DEF_x__h646 = INST_uut_operation.METH_read();
  DEF_uut_opB_BIT_31___h702 = (tUInt8)(DEF_x__h706 >> 31u);
  DEF_uut_opA_BIT_31___h682 = (tUInt8)(DEF_x__h686 >> 31u);
  DEF_x__h669 = DEF_uut_opA_BIT_31___h682 ? -DEF_x__h686 : DEF_x__h686;
  DEF_x__h689 = DEF_uut_opB_BIT_31___h702 ? -DEF_x__h706 : DEF_x__h706;
  DEF_IF_uut_opA_0_BIT_31_5_THEN_NEG_uut_opA_0_2_ELS_ETC___d36 = DEF_x__h669 / DEF_x__h689;
  switch (DEF_x__h646) {
  case (tUInt8)0u:
    DEF_IF_uut_operation_8_EQ_0_9_THEN_uut_opA_0_MUL_u_ETC___d54 = (tUInt32)(((tUInt64)(DEF_x__h686)) * ((tUInt64)(DEF_x__h706)));
    break;
  case (tUInt8)1u:
    DEF_IF_uut_operation_8_EQ_0_9_THEN_uut_opA_0_MUL_u_ETC___d54 = (DEF_uut_opA_BIT_31___h682 && !DEF_uut_opB_BIT_31___h702) || (!DEF_uut_opA_BIT_31___h682 && DEF_uut_opB_BIT_31___h702) ? -DEF_IF_uut_opA_0_BIT_31_5_THEN_NEG_uut_opA_0_2_ELS_ETC___d36 : DEF_IF_uut_opA_0_BIT_31_5_THEN_NEG_uut_opA_0_2_ELS_ETC___d36;
    break;
  case (tUInt8)2u:
    DEF_IF_uut_operation_8_EQ_0_9_THEN_uut_opA_0_MUL_u_ETC___d54 = DEF_x__h686 + DEF_x__h706;
    break;
  case (tUInt8)3u:
    DEF_IF_uut_operation_8_EQ_0_9_THEN_uut_opA_0_MUL_u_ETC___d54 = DEF_x__h686 - DEF_x__h706;
    break;
  case (tUInt8)4u:
    DEF_IF_uut_operation_8_EQ_0_9_THEN_uut_opA_0_MUL_u_ETC___d54 = DEF_x__h686 & DEF_x__h706;
    break;
  case (tUInt8)5u:
    DEF_IF_uut_operation_8_EQ_0_9_THEN_uut_opA_0_MUL_u_ETC___d54 = DEF_x__h686 | DEF_x__h706;
    break;
  case (tUInt8)6u:
    DEF_IF_uut_operation_8_EQ_0_9_THEN_uut_opA_0_MUL_u_ETC___d54 = DEF_b__h471;
    break;
  default:
    DEF_IF_uut_operation_8_EQ_0_9_THEN_uut_opA_0_MUL_u_ETC___d54 = 0u;
  }
  INST_uut_result.METH_write(DEF_IF_uut_operation_8_EQ_0_9_THEN_uut_opA_0_MUL_u_ETC___d54);
  INST_uut_newOperands.METH_write((tUInt8)0u);
  INST_uut_resultValid.METH_write((tUInt8)1u);
}

void MOD_mkALUTestbench::RL_checkMul()
{
  DEF_testState__h2370 = INST_testState.METH_read();
  DEF_testState_6_PLUS_1___d59 = (tUInt8)255u & (DEF_testState__h2370 + (tUInt8)1u);
  INST_uut_opA.METH_write(4u);
  INST_uut_opB.METH_write(5u);
  INST_uut_operation.METH_write((tUInt8)0u);
  INST_uut_newOperands.METH_write((tUInt8)1u);
  INST_uut_resultValid.METH_write((tUInt8)0u);
  INST_testState.METH_write(DEF_testState_6_PLUS_1___d59);
}

void MOD_mkALUTestbench::RL_checkDiv()
{
  DEF_testState__h2370 = INST_testState.METH_read();
  DEF_testState_6_PLUS_1___d59 = (tUInt8)255u & (DEF_testState__h2370 + (tUInt8)1u);
  INST_uut_opA.METH_write(12u);
  INST_uut_opB.METH_write(4u);
  INST_uut_operation.METH_write((tUInt8)1u);
  INST_uut_newOperands.METH_write((tUInt8)1u);
  INST_uut_resultValid.METH_write((tUInt8)0u);
  INST_testState.METH_write(DEF_testState_6_PLUS_1___d59);
}

void MOD_mkALUTestbench::RL_checkAdd()
{
  DEF_testState__h2370 = INST_testState.METH_read();
  DEF_testState_6_PLUS_1___d59 = (tUInt8)255u & (DEF_testState__h2370 + (tUInt8)1u);
  INST_uut_opA.METH_write(12u);
  INST_uut_opB.METH_write(4u);
  INST_uut_operation.METH_write((tUInt8)2u);
  INST_uut_newOperands.METH_write((tUInt8)1u);
  INST_uut_resultValid.METH_write((tUInt8)0u);
  INST_testState.METH_write(DEF_testState_6_PLUS_1___d59);
}

void MOD_mkALUTestbench::RL_checkSub()
{
  DEF_testState__h2370 = INST_testState.METH_read();
  DEF_testState_6_PLUS_1___d59 = (tUInt8)255u & (DEF_testState__h2370 + (tUInt8)1u);
  INST_uut_opA.METH_write(12u);
  INST_uut_opB.METH_write(4u);
  INST_uut_operation.METH_write((tUInt8)3u);
  INST_uut_newOperands.METH_write((tUInt8)1u);
  INST_uut_resultValid.METH_write((tUInt8)0u);
  INST_testState.METH_write(DEF_testState_6_PLUS_1___d59);
}

void MOD_mkALUTestbench::RL_checkAnd()
{
  DEF_testState__h2370 = INST_testState.METH_read();
  DEF_testState_6_PLUS_1___d59 = (tUInt8)255u & (DEF_testState__h2370 + (tUInt8)1u);
  INST_uut_opA.METH_write(10u);
  INST_uut_opB.METH_write(10u);
  INST_uut_operation.METH_write((tUInt8)4u);
  INST_uut_newOperands.METH_write((tUInt8)1u);
  INST_uut_resultValid.METH_write((tUInt8)0u);
  INST_testState.METH_write(DEF_testState_6_PLUS_1___d59);
}

void MOD_mkALUTestbench::RL_checkOr()
{
  DEF_testState__h2370 = INST_testState.METH_read();
  DEF_testState_6_PLUS_1___d59 = (tUInt8)255u & (DEF_testState__h2370 + (tUInt8)1u);
  INST_uut_opA.METH_write(10u);
  INST_uut_opB.METH_write(11u);
  INST_uut_operation.METH_write((tUInt8)5u);
  INST_uut_newOperands.METH_write((tUInt8)1u);
  INST_uut_resultValid.METH_write((tUInt8)0u);
  INST_testState.METH_write(DEF_testState_6_PLUS_1___d59);
}

void MOD_mkALUTestbench::RL_checkPow()
{
  DEF_testState__h2370 = INST_testState.METH_read();
  DEF_testState_6_PLUS_1___d59 = (tUInt8)255u & (DEF_testState__h2370 + (tUInt8)1u);
  INST_uut_opA.METH_write(2u);
  INST_uut_opB.METH_write(12u);
  INST_uut_newOperands.METH_write((tUInt8)1u);
  INST_uut_operation.METH_write((tUInt8)6u);
  INST_uut_resultValid.METH_write((tUInt8)0u);
  INST_uut_pow_result.METH_write(1u);
  INST_uut_pow_opA.METH_write(2u);
  INST_uut_pow_opB.METH_write(12u);
  INST_testState.METH_write(DEF_testState_6_PLUS_1___d59);
  INST_uut_pow_resultValid.METH_write((tUInt8)0u);
}

void MOD_mkALUTestbench::RL_printResults()
{
  tUInt32 DEF_signed_uut_result_4___d75;
  DEF_signed_uut_result_4___d75 = INST_uut_result.METH_read();
  DEF_testState__h2370 = INST_testState.METH_read();
  DEF_testState_6_PLUS_1___d59 = (tUInt8)255u & (DEF_testState__h2370 + (tUInt8)1u);
  INST_uut_resultValid.METH_write((tUInt8)0u);
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_display(sim_hdl, this, "s,-32", &__str_literal_1, DEF_signed_uut_result_4___d75);
  INST_testState.METH_write(DEF_testState_6_PLUS_1___d59);
}

void MOD_mkALUTestbench::RL_endSim()
{
  if (!(PORT_RST_N == (tUInt8)0u))
    dollar_finish(sim_hdl, "32", 1u);
}


/* Methods */


/* Reset routines */

void MOD_mkALUTestbench::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_uut_resultValid.reset_RST(ARG_rst_in);
  INST_uut_result.reset_RST(ARG_rst_in);
  INST_uut_pow_resultValid.reset_RST(ARG_rst_in);
  INST_uut_pow_result.reset_RST(ARG_rst_in);
  INST_uut_pow_opB.reset_RST(ARG_rst_in);
  INST_uut_pow_opA.reset_RST(ARG_rst_in);
  INST_uut_operation.reset_RST(ARG_rst_in);
  INST_uut_opB.reset_RST(ARG_rst_in);
  INST_uut_opA.reset_RST(ARG_rst_in);
  INST_uut_newOperands.reset_RST(ARG_rst_in);
  INST_testState.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkALUTestbench::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkALUTestbench::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_testState.dump_state(indent + 2u);
  INST_uut_newOperands.dump_state(indent + 2u);
  INST_uut_opA.dump_state(indent + 2u);
  INST_uut_opB.dump_state(indent + 2u);
  INST_uut_operation.dump_state(indent + 2u);
  INST_uut_pow_opA.dump_state(indent + 2u);
  INST_uut_pow_opB.dump_state(indent + 2u);
  INST_uut_pow_result.dump_state(indent + 2u);
  INST_uut_pow_resultValid.dump_state(indent + 2u);
  INST_uut_result.dump_state(indent + 2u);
  INST_uut_resultValid.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkALUTestbench::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 16u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "b__h405", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "b__h471", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "testState_6_PLUS_1___d59", 8u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "testState__h2370", 8u);
  num = INST_testState.dump_VCD_defs(num);
  num = INST_uut_newOperands.dump_VCD_defs(num);
  num = INST_uut_opA.dump_VCD_defs(num);
  num = INST_uut_opB.dump_VCD_defs(num);
  num = INST_uut_operation.dump_VCD_defs(num);
  num = INST_uut_pow_opA.dump_VCD_defs(num);
  num = INST_uut_pow_opB.dump_VCD_defs(num);
  num = INST_uut_pow_result.dump_VCD_defs(num);
  num = INST_uut_pow_resultValid.dump_VCD_defs(num);
  num = INST_uut_result.dump_VCD_defs(num);
  num = INST_uut_resultValid.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkALUTestbench::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkALUTestbench &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkALUTestbench::vcd_defs(tVCDDumpType dt, MOD_mkALUTestbench &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 8u);
    vcd_write_x(sim_hdl, num++, 8u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
      if ((backing.DEF_b__h405) != DEF_b__h405)
      {
	vcd_write_val(sim_hdl, num, DEF_b__h405, 32u);
	backing.DEF_b__h405 = DEF_b__h405;
      }
      ++num;
      if ((backing.DEF_b__h471) != DEF_b__h471)
      {
	vcd_write_val(sim_hdl, num, DEF_b__h471, 32u);
	backing.DEF_b__h471 = DEF_b__h471;
      }
      ++num;
      if ((backing.DEF_testState_6_PLUS_1___d59) != DEF_testState_6_PLUS_1___d59)
      {
	vcd_write_val(sim_hdl, num, DEF_testState_6_PLUS_1___d59, 8u);
	backing.DEF_testState_6_PLUS_1___d59 = DEF_testState_6_PLUS_1___d59;
      }
      ++num;
      if ((backing.DEF_testState__h2370) != DEF_testState__h2370)
      {
	vcd_write_val(sim_hdl, num, DEF_testState__h2370, 8u);
	backing.DEF_testState__h2370 = DEF_testState__h2370;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_b__h405, 32u);
      backing.DEF_b__h405 = DEF_b__h405;
      vcd_write_val(sim_hdl, num++, DEF_b__h471, 32u);
      backing.DEF_b__h471 = DEF_b__h471;
      vcd_write_val(sim_hdl, num++, DEF_testState_6_PLUS_1___d59, 8u);
      backing.DEF_testState_6_PLUS_1___d59 = DEF_testState_6_PLUS_1___d59;
      vcd_write_val(sim_hdl, num++, DEF_testState__h2370, 8u);
      backing.DEF_testState__h2370 = DEF_testState__h2370;
    }
}

void MOD_mkALUTestbench::vcd_prims(tVCDDumpType dt, MOD_mkALUTestbench &backing)
{
  INST_testState.dump_VCD(dt, backing.INST_testState);
  INST_uut_newOperands.dump_VCD(dt, backing.INST_uut_newOperands);
  INST_uut_opA.dump_VCD(dt, backing.INST_uut_opA);
  INST_uut_opB.dump_VCD(dt, backing.INST_uut_opB);
  INST_uut_operation.dump_VCD(dt, backing.INST_uut_operation);
  INST_uut_pow_opA.dump_VCD(dt, backing.INST_uut_pow_opA);
  INST_uut_pow_opB.dump_VCD(dt, backing.INST_uut_pow_opB);
  INST_uut_pow_result.dump_VCD(dt, backing.INST_uut_pow_result);
  INST_uut_pow_resultValid.dump_VCD(dt, backing.INST_uut_pow_resultValid);
  INST_uut_result.dump_VCD(dt, backing.INST_uut_result);
  INST_uut_resultValid.dump_VCD(dt, backing.INST_uut_resultValid);
}

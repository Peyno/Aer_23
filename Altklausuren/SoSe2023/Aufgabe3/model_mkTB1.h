/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Tue Feb 20 15:55:26 CET 2024
 * 
 */

/* Generation options: */
#ifndef __model_mkTB1_h__
#define __model_mkTB1_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"

#include "bs_model.h"
#include "mkTB1.h"

/* Class declaration for a model of mkTB1 */
class MODEL_mkTB1 : public Model {
 
 /* Top-level module instance */
 private:
  MOD_mkTB1 *mkTB1_instance;
 
 /* Handle to the simulation kernel */
 private:
  tSimStateHdl sim_hdl;
 
 /* Constructor */
 public:
  MODEL_mkTB1();
 
 /* Functions required by the kernel */
 public:
  void create_model(tSimStateHdl simHdl, bool master);
  void destroy_model();
  void reset_model(bool asserted);
  void get_version(char const **name, char const **build);
  time_t get_creation_time();
  void * get_instance();
  void dump_state();
  void dump_VCD_defs();
  void dump_VCD(tVCDDumpType dt);
};

/* Function for creating a new model */
extern "C" {
  void * new_MODEL_mkTB1();
}

#endif /* ifndef __model_mkTB1_h__ */

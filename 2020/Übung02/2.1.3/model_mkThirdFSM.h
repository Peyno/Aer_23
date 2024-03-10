/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Tue Jan 16 17:56:16 CET 2024
 * 
 */

/* Generation options: */
#ifndef __model_mkThirdFSM_h__
#define __model_mkThirdFSM_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"

#include "bs_model.h"
#include "mkThirdFSM.h"

/* Class declaration for a model of mkThirdFSM */
class MODEL_mkThirdFSM : public Model {
 
 /* Top-level module instance */
 private:
  MOD_mkThirdFSM *mkThirdFSM_instance;
 
 /* Handle to the simulation kernel */
 private:
  tSimStateHdl sim_hdl;
 
 /* Constructor */
 public:
  MODEL_mkThirdFSM();
 
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
  void * new_MODEL_mkThirdFSM();
}

#endif /* ifndef __model_mkThirdFSM_h__ */

/*
 * Generated by Bluespec Compiler, version 2023.07 (build 0eb551dc)
 * 
 * On Mon Feb 12 13:23:00 CET 2024
 * 
 */

/* Generation options: */
#ifndef __model_mkAufgabe5TB_h__
#define __model_mkAufgabe5TB_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"

#include "bs_model.h"
#include "mkAufgabe5TB.h"

/* Class declaration for a model of mkAufgabe5TB */
class MODEL_mkAufgabe5TB : public Model {
 
 /* Top-level module instance */
 private:
  MOD_mkAufgabe5TB *mkAufgabe5TB_instance;
 
 /* Handle to the simulation kernel */
 private:
  tSimStateHdl sim_hdl;
 
 /* Constructor */
 public:
  MODEL_mkAufgabe5TB();
 
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
  void * new_MODEL_mkAufgabe5TB();
}

#endif /* ifndef __model_mkAufgabe5TB_h__ */

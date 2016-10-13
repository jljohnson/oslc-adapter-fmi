/* Main Simulation File */
/* Simulation code for IntegerNetwork1 generated by the OpenModelica Compiler 1.9.2+dev (r24999). */

#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "simulation/simulation_info_xml.h"
#include "simulation/simulation_runtime.h"
#include "util/omc_error.h"
#include "simulation/solver/model_help.h"
#include "simulation/solver/delay.h"
#include "simulation/solver/linearSystem.h"
#include "simulation/solver/nonlinearSystem.h"
#include "simulation/solver/mixedSystem.h"

#include <assert.h>
#include <string.h>

#include "IntegerNetwork1_functions.h"
#include "IntegerNetwork1_model.h"
#include "IntegerNetwork1_literals.h"




#if defined(HPCOM) && !defined(_OPENMP)
  #error "HPCOM requires OpenMP or the results are wrong"
#endif
#if defined(_OPENMP)
  #include <omp.h>
#else
  /* dummy omp defines */
  #define omp_get_max_threads() 1
#endif

#define threadData data->threadData


#define prefixedName_performSimulation IntegerNetwork1_performSimulation
#include <simulation/solver/perform_simulation.c>

#define prefixedName_performQSSSimulation IntegerNetwork1_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c>

/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif
int measure_time_flag = 0;

int IntegerNetwork1_input_function(DATA *data)
{
  TRACE_PUSH

  $PintegerStep = data->simulationInfo.inputVars[0];
  
  TRACE_POP
  return 0;
}

int IntegerNetwork1_input_function_init(DATA *data)
{
  TRACE_PUSH

  $P$ATTRIBUTE$PintegerStep.start = data->simulationInfo.inputVars[0];
  
  TRACE_POP
  return 0;
}


int IntegerNetwork1_output_function(DATA *data)
{
  TRACE_PUSH

  data->simulationInfo.outputVars[0] = $Py;
  data->simulationInfo.outputVars[1] = $Py1;
  data->simulationInfo.outputVars[2] = $Py2;
  data->simulationInfo.outputVars[3] = $Py3;
  data->simulationInfo.outputVars[4] = $Py4;
  data->simulationInfo.outputVars[5] = $Py5;
  
  TRACE_POP
  return 0;
}


/*
 equation index: 29
 type: SIMPLE_ASSIGN
 $whenCondition4 = sample(2, booleanPulse2.startTime, booleanPulse2.period)
 */
void IntegerNetwork1_eqFunction_29(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  $P$whenCondition4 = $P$sample2;
  TRACE_POP
}
/*
 equation index: 30
 type: SIMPLE_ASSIGN
 $whenCondition3 = false
 */
void IntegerNetwork1_eqFunction_30(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  $P$whenCondition3 = 0;
  TRACE_POP
}
/*
 equation index: 31
 type: SIMPLE_ASSIGN
 $whenCondition1 = sample(1, booleanPulse1.startTime, booleanPulse1.period)
 */
void IntegerNetwork1_eqFunction_31(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  $P$whenCondition1 = $P$sample1;
  TRACE_POP
}
/*
 equation index: 32
 type: WHEN
 
 when {$whenCondition4} then
   booleanPulse2._pulsStart = time;
 end when;
 */
void IntegerNetwork1_eqFunction_32(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  if(initial())
  {
    $PbooleanPulse2$PpulsStart = $P$PRE$PbooleanPulse2$PpulsStart;
  }
  else if(0 || ($P$whenCondition4 && !$P$PRE$P$whenCondition4 /* edge */))
  {
    $PbooleanPulse2$PpulsStart = time;
  }
  else
  {
    $PbooleanPulse2$PpulsStart = $P$PRE$PbooleanPulse2$PpulsStart;
  }
  TRACE_POP
}
/*
 equation index: 33
 type: SIMPLE_ASSIGN
 multiSwitch1._u[2] = time >= booleanPulse2.pulsStart and time < booleanPulse2.pulsStart + 1.6
 */
void IntegerNetwork1_eqFunction_33(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  modelica_boolean tmp30;
  modelica_boolean tmp31;
  RELATIONHYSTERESIS(tmp30, time, $PbooleanPulse2$PpulsStart, 4, GreaterEq);
  RELATIONHYSTERESIS(tmp31, time, ($PbooleanPulse2$PpulsStart + 1.6), 5, Less);
  $PmultiSwitch1$Pu$lB2$rB = (tmp30 && tmp31);
  TRACE_POP
}
/*
 equation index: 34
 type: WHEN
 
 when {$whenCondition1} then
   booleanPulse1._pulsStart = time;
 end when;
 */
void IntegerNetwork1_eqFunction_34(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  if(initial())
  {
    $PbooleanPulse1$PpulsStart = $P$PRE$PbooleanPulse1$PpulsStart;
  }
  else if(0 || ($P$whenCondition1 && !$P$PRE$P$whenCondition1 /* edge */))
  {
    $PbooleanPulse1$PpulsStart = time;
  }
  else
  {
    $PbooleanPulse1$PpulsStart = $P$PRE$PbooleanPulse1$PpulsStart;
  }
  TRACE_POP
}
/*
 equation index: 35
 type: SIMPLE_ASSIGN
 multiSwitch1._u[1] = time >= booleanPulse1.pulsStart and time < booleanPulse1.pulsStart + 0.5
 */
void IntegerNetwork1_eqFunction_35(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  modelica_boolean tmp32;
  modelica_boolean tmp33;
  RELATIONHYSTERESIS(tmp32, time, $PbooleanPulse1$PpulsStart, 2, GreaterEq);
  RELATIONHYSTERESIS(tmp33, time, ($PbooleanPulse1$PpulsStart + 0.5), 3, Less);
  $PmultiSwitch1$Pu$lB1$rB = (tmp32 && tmp33);
  TRACE_POP
}
/*
 equation index: 36
 type: SIMPLE_ASSIGN
 multiSwitch1._firstActiveIndex = Modelica.Math.BooleanVectors.firstTrueIndex({multiSwitch1.u[1], multiSwitch1.u[2]})
 */
void IntegerNetwork1_eqFunction_36(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  boolean_array tmp34;
  array_alloc_scalar_boolean_array(&tmp34, 2, (modelica_boolean)$PmultiSwitch1$Pu$lB1$rB, (modelica_boolean)$PmultiSwitch1$Pu$lB2$rB);
  $PmultiSwitch1$PfirstActiveIndex = omc_Modelica_Math_BooleanVectors_firstTrueIndex(threadData, tmp34);
  TRACE_POP
}
/*
 equation index: 37
 type: SIMPLE_ASSIGN
 multiSwitch1._y = if multiSwitch1.firstActiveIndex > 0 then multiSwitch1.expr[multiSwitch1.firstActiveIndex] else if multiSwitch1.use_pre_as_default then pre(multiSwitch1.y) else multiSwitch1.y_default
 */
void IntegerNetwork1_eqFunction_37(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  modelica_boolean tmp35;
  tmp35 = Greater((modelica_integer)$PmultiSwitch1$PfirstActiveIndex,(modelica_integer) 0);
  $PmultiSwitch1$Py = (tmp35?(modelica_integer)$PmultiSwitch1$Pexpr_index((modelica_integer)$PmultiSwitch1$PfirstActiveIndex):($PmultiSwitch1$Puse_pre_as_default?$P$PRE$PmultiSwitch1$Py:(modelica_integer)$PmultiSwitch1$Py_default));
  TRACE_POP
}
/*
 equation index: 38
 type: SIMPLE_ASSIGN
 y = multiSwitch1.y
 */
void IntegerNetwork1_eqFunction_38(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  $Py = (modelica_integer)$PmultiSwitch1$Py;
  TRACE_POP
}
/*
 equation index: 39
 type: SIMPLE_ASSIGN
 $whenCondition2 = multiSwitch1.u[1]
 */
void IntegerNetwork1_eqFunction_39(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  $P$whenCondition2 = $PmultiSwitch1$Pu$lB1$rB;
  TRACE_POP
}
/*
 equation index: 40
 type: WHEN
 
 when {$whenCondition3, $whenCondition2} then
   triggeredAdd._y = pre(triggeredAdd.y) + integerConstant.k;
 end when;
 */
void IntegerNetwork1_eqFunction_40(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  if(initial())
  {
    $PtriggeredAdd$Py = $P$PRE$PtriggeredAdd$Py;
  }
  else if(0 || ($P$whenCondition3 && !$P$PRE$P$whenCondition3 /* edge */) || ($P$whenCondition2 && !$P$PRE$P$whenCondition2 /* edge */))
  {
    $PtriggeredAdd$Py = ($P$PRE$PtriggeredAdd$Py + (modelica_integer)$PintegerConstant$Pk);
  }
  else
  {
    $PtriggeredAdd$Py = $P$PRE$PtriggeredAdd$Py;
  }
  TRACE_POP
}
/*
 equation index: 41
 type: SIMPLE_ASSIGN
 y4 = triggeredAdd.y
 */
void IntegerNetwork1_eqFunction_41(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
  $Py4 = (modelica_integer)$PtriggeredAdd$Py;
  TRACE_POP
}
/*
 equation index: 42
 type: SIMPLE_ASSIGN
 y5 = sine.offset + (if time < sine.startTime then 0.0 else sine.amplitude * sin(6.283185307179586 * sine.freqHz * (time - sine.startTime) + sine.phase))
 */
void IntegerNetwork1_eqFunction_42(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  modelica_boolean tmp36;
  RELATIONHYSTERESIS(tmp36, time, $Psine$PstartTime, 0, Less);
  $Py5 = ($Psine$Poffset + (tmp36?0.0:($Psine$Pamplitude * sin(((6.283185307179586 * ($Psine$PfreqHz * (time - $Psine$PstartTime))) + $Psine$Pphase)))));
  TRACE_POP
}
/*
 equation index: 43
 type: SIMPLE_ASSIGN
 y2 = if y5 > 0.0 then integer(floor(0.5 + y5, 1), 0) else integer(ceil(y5 + -0.5, 3), 2)
 */
void IntegerNetwork1_eqFunction_43(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
  modelica_boolean tmp37;
  RELATIONHYSTERESIS(tmp37, $Py5, 0.0, 1, Greater);
  $Py2 = (tmp37?(_event_integer(((modelica_real)_event_floor((0.5 + $Py5), (modelica_integer) 1, data)), (modelica_integer) 0, data)):(_event_integer(((modelica_real)_event_ceil(($Py5 + -0.5), (modelica_integer) 3, data)), (modelica_integer) 2, data)));
  TRACE_POP
}
/*
 equation index: 44
 type: SIMPLE_ASSIGN
 y3 = sum.k[1] * y2 + sum.k[2] * integerStep + sum.k[3] * integerConstant.k
 */
void IntegerNetwork1_eqFunction_44(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
  $Py3 = (((modelica_integer)$Psum$Pk$lB1$rB * (modelica_integer)$Py2) + (((modelica_integer)$Psum$Pk$lB2$rB * (modelica_integer)$PintegerStep) + ((modelica_integer)$Psum$Pk$lB3$rB * (modelica_integer)$PintegerConstant$Pk)));
  TRACE_POP
}
/*
 equation index: 45
 type: SIMPLE_ASSIGN
 y1 = y3 * integerStep
 */
void IntegerNetwork1_eqFunction_45(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
  $Py1 = ((modelica_integer)$Py3 * (modelica_integer)$PintegerStep);
  TRACE_POP
}


int IntegerNetwork1_functionDAE(DATA *data)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo.needToIterate = 0;
  data->simulationInfo.discreteCall = 1;
  IntegerNetwork1_eqFunction_29(data);

  IntegerNetwork1_eqFunction_30(data);

  IntegerNetwork1_eqFunction_31(data);

  IntegerNetwork1_eqFunction_32(data);

  IntegerNetwork1_eqFunction_33(data);

  IntegerNetwork1_eqFunction_34(data);

  IntegerNetwork1_eqFunction_35(data);

  IntegerNetwork1_eqFunction_36(data);

  IntegerNetwork1_eqFunction_37(data);

  IntegerNetwork1_eqFunction_38(data);

  IntegerNetwork1_eqFunction_39(data);

  IntegerNetwork1_eqFunction_40(data);

  IntegerNetwork1_eqFunction_41(data);

  IntegerNetwork1_eqFunction_42(data);

  IntegerNetwork1_eqFunction_43(data);

  IntegerNetwork1_eqFunction_44(data);

  IntegerNetwork1_eqFunction_45(data);
  
  
  
  
  TRACE_POP
  return 0;
}


int IntegerNetwork1_functionODE(DATA *data)
{
  TRACE_PUSH

  
  data->simulationInfo.callStatistics.functionODE++;
  
  data->simulationInfo.discreteCall = 0;
  /* no ODE systems */

  
  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data);

#include "IntegerNetwork1_12jac.h"
#include "IntegerNetwork1_13opt.h"
extern void IntegerNetwork1_callExternalObjectConstructors(DATA *data);
extern void IntegerNetwork1_callExternalObjectDestructors(DATA *_data);
extern void IntegerNetwork1_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA *data);
extern void IntegerNetwork1_initialLinearSystem(int nLinearSystems, LINEAR_SYSTEM_DATA *data);
extern void IntegerNetwork1_initialMixedSystem(int nMixedSystems, MIXED_SYSTEM_DATA *data);
extern void IntegerNetwork1_initializeStateSets(int nStateSets, STATE_SET_DATA* statesetData, DATA *data);
extern int IntegerNetwork1_functionAlgebraics(DATA *data);
extern int IntegerNetwork1_function_storeDelayed(DATA *data);
extern int IntegerNetwork1_updateBoundVariableAttributes(DATA *data);
extern int IntegerNetwork1_functionInitialEquations(DATA *data);
extern int IntegerNetwork1_functionRemovedInitialEquations(DATA *data);
extern int IntegerNetwork1_updateBoundParameters(DATA *data);
extern int IntegerNetwork1_checkForAsserts(DATA *data);
extern int IntegerNetwork1_function_ZeroCrossingsEquations(DATA *data);
extern int IntegerNetwork1_function_ZeroCrossings(DATA *data, double* gout);
extern int IntegerNetwork1_function_updateRelations(DATA *data, int evalZeroCross);
extern int IntegerNetwork1_checkForDiscreteChanges(DATA *data);
extern const char* IntegerNetwork1_zeroCrossingDescription(int i, int **out_EquationIndexes);
extern const char* IntegerNetwork1_relationDescription(int i);
extern void IntegerNetwork1_function_initSample(DATA *data);
extern int IntegerNetwork1_initialAnalyticJacobianG(void* data);
extern int IntegerNetwork1_initialAnalyticJacobianA(void* data);
extern int IntegerNetwork1_initialAnalyticJacobianB(void* data);
extern int IntegerNetwork1_initialAnalyticJacobianC(void* data);
extern int IntegerNetwork1_initialAnalyticJacobianD(void* data);
extern int IntegerNetwork1_functionJacG_column(void* data);
extern int IntegerNetwork1_functionJacA_column(void* data);
extern int IntegerNetwork1_functionJacB_column(void* data);
extern int IntegerNetwork1_functionJacC_column(void* data);
extern int IntegerNetwork1_functionJacD_column(void* data);
extern const char* IntegerNetwork1_linear_model_frame(void);
extern int IntegerNetwork1_mayer(DATA* data, modelica_real** res, short *);
extern int IntegerNetwork1_lagrange(DATA* data, modelica_real** res, short *, short *);
extern int IntegerNetwork1_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
extern int IntegerNetwork1_setInputData(DATA *data);
extern int IntegerNetwork1_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);

struct OpenModelicaGeneratedFunctionCallbacks IntegerNetwork1_callback = {
   (int (*)(DATA *, void *)) IntegerNetwork1_performSimulation,
   (int (*)(DATA *, void *)) IntegerNetwork1_performQSSSimulation,
   IntegerNetwork1_callExternalObjectConstructors,
   IntegerNetwork1_callExternalObjectDestructors,
   IntegerNetwork1_initialNonLinearSystem,
   IntegerNetwork1_initialLinearSystem,
   IntegerNetwork1_initialMixedSystem,
   IntegerNetwork1_initializeStateSets,
   IntegerNetwork1_functionODE,
   IntegerNetwork1_functionAlgebraics,
   IntegerNetwork1_functionDAE,
   IntegerNetwork1_input_function,
   IntegerNetwork1_input_function_init,
   IntegerNetwork1_output_function,
   IntegerNetwork1_function_storeDelayed,
   IntegerNetwork1_updateBoundVariableAttributes,
   1 /* useSymbolicInitialization */,
   0 /* useHomotopy */,
   IntegerNetwork1_functionInitialEquations,
   IntegerNetwork1_functionRemovedInitialEquations,
   IntegerNetwork1_updateBoundParameters,
   IntegerNetwork1_checkForAsserts,
   IntegerNetwork1_function_ZeroCrossingsEquations,
   IntegerNetwork1_function_ZeroCrossings,
   IntegerNetwork1_function_updateRelations,
   IntegerNetwork1_checkForDiscreteChanges,
   IntegerNetwork1_zeroCrossingDescription,
   IntegerNetwork1_relationDescription,
   IntegerNetwork1_function_initSample,
   IntegerNetwork1_INDEX_JAC_A,
   IntegerNetwork1_INDEX_JAC_B,
   IntegerNetwork1_INDEX_JAC_C,
   IntegerNetwork1_INDEX_JAC_D,
   IntegerNetwork1_initialAnalyticJacobianA,
   IntegerNetwork1_initialAnalyticJacobianB,
   IntegerNetwork1_initialAnalyticJacobianC,
   IntegerNetwork1_initialAnalyticJacobianD,
   IntegerNetwork1_functionJacA_column,
   IntegerNetwork1_functionJacB_column,
   IntegerNetwork1_functionJacC_column,
   IntegerNetwork1_functionJacD_column,
   IntegerNetwork1_linear_model_frame,
   IntegerNetwork1_mayer,
   IntegerNetwork1_lagrange,
   IntegerNetwork1_pickUpBoundsForInputsInOptimization,
   IntegerNetwork1_setInputData,
   IntegerNetwork1_getTimeGrid

};

void IntegerNetwork1_setupDataStruc(DATA *data)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  data->callback = &IntegerNetwork1_callback;
  data->modelData.modelName = "IntegerNetwork1";
  data->modelData.modelFilePrefix = "IntegerNetwork1";
  data->modelData.resultFileName = NULL;
  data->modelData.modelDir = "c:/OpenModelicaExternal/tools/FMI/Test_FMUs/FMI_1.0/ModelExchange/win32/OpenModelica/1.9.2/IntegerNetwork1";
  data->modelData.modelGUID = "{8c4e810f-3df3-4a00-8276-176fa3c9f9e0}";
  #ifdef OPENMODELICA_XML_FROM_FILE_AT_RUNTIME
  data->modelData.initXMLData = NULL;
  data->modelData.modelDataXml.infoXMLData = NULL;
  #else
  data->modelData.initXMLData =
  #include "IntegerNetwork1_init.c"
  ;
  data->modelData.modelDataXml.infoXMLData =
  #include "IntegerNetwork1_info.c"
  ;
  #endif
  
  data->modelData.nStates = 0;
  data->modelData.nVariablesReal = 2*0+1+2+0 + 0;
  data->modelData.nDiscreteReal = 2;
  data->modelData.nVariablesInteger = 15;
  data->modelData.nVariablesBoolean = 7;
  data->modelData.nVariablesString = 0;
  data->modelData.nParametersReal = 13;
  data->modelData.nParametersInteger = 9;
  data->modelData.nParametersBoolean = 7;
  data->modelData.nParametersString = 0;
  data->modelData.nInputVars = 1;
  data->modelData.nOutputVars = 6;
  
  data->modelData.nAliasReal = 2;
  data->modelData.nAliasInteger = 18;
  data->modelData.nAliasBoolean = 3;
  data->modelData.nAliasString = 0;
  
  data->modelData.nZeroCrossings = 8;
  data->modelData.nSamples = 2;
  data->modelData.nRelations = 6;
  data->modelData.nMathEvents = 4;
  data->modelData.nExtObjs = 0;
  setupModelInfoFunctions(1);
  data->modelData.modelDataXml.fileName = "IntegerNetwork1_info.json";
  data->modelData.modelDataXml.modelInfoXmlLength = 0;
  data->modelData.modelDataXml.nFunctions = 1;
  data->modelData.modelDataXml.nProfileBlocks = 0;
  data->modelData.modelDataXml.nEquations = 53;
  data->modelData.nMixedSystems = 0;
  data->modelData.nLinearSystems = 0;
  data->modelData.nNonLinearSystems = 0;
  data->modelData.nStateSets = 0;
  data->modelData.nJacobians = 4;
  data->modelData.nOptimizeConstraints = 0;
  data->modelData.nOptimizeFinalConstraints = 0;
  
  data->modelData.nDelayExpressions = 0;
  
}

#ifdef __cplusplus
}
#endif

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
int main(int argc, char**argv)
{
  int res;
  DATA simulation_data;
  MMC_INIT();omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    IntegerNetwork1_setupDataStruc(&simulation_data);
    simulation_data.threadData = threadData;
    res = _main_SimulationRuntime(argc, argv, &simulation_data);
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
  EXIT(res);
  return res;
}

/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
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

#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void IntegerNetwork1_function_initSample(DATA *data)
{
  long i=0;
  /* $P$sample1 */
  data->modelData.samplesInfo[i].index = 1;
  data->modelData.samplesInfo[i].start = $PbooleanPulse1$PstartTime;
  data->modelData.samplesInfo[i].interval = $PbooleanPulse1$Pperiod;
  assertStreamPrint(threadData,data->modelData.samplesInfo[i].interval > 0.0, "sample-interval <= 0.0");
  i++;
  /* $P$sample2 */
  data->modelData.samplesInfo[i].index = 2;
  data->modelData.samplesInfo[i].start = $PbooleanPulse2$PstartTime;
  data->modelData.samplesInfo[i].interval = $PbooleanPulse2$Pperiod;
  assertStreamPrint(threadData,data->modelData.samplesInfo[i].interval > 0.0, "sample-interval <= 0.0");
  i++;
}

const char *IntegerNetwork1_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"time < sine.startTime",
  "y5 > 0.0",
  "integer(floor(0.5 + y5), 0)",
  "floor(0.5 + y5, 1)",
  "integer(ceil(y5 + -0.5), 2)",
  "ceil(y5 + -0.5, 3)",
  "time >= booleanPulse1.pulsStart and time < booleanPulse1.pulsStart + 0.5",
  "time >= booleanPulse2.pulsStart and time < booleanPulse2.pulsStart + 1.6"};
  static const int occurEqs0[] = {1,42};
  static const int occurEqs1[] = {1,43};
  static const int occurEqs2[] = {1,43};
  static const int occurEqs3[] = {1,43};
  static const int occurEqs4[] = {1,43};
  static const int occurEqs5[] = {1,43};
  static const int occurEqs6[] = {1,35};
  static const int occurEqs7[] = {1,33};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2,occurEqs3,occurEqs4,occurEqs5,occurEqs6,occurEqs7};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void IntegerNetwork1_eqFunction_29(DATA* data);
extern void IntegerNetwork1_eqFunction_31(DATA* data);
extern void IntegerNetwork1_eqFunction_42(DATA* data);

int IntegerNetwork1_function_ZeroCrossingsEquations(DATA *data)
{
  TRACE_PUSH
  
  data->simulationInfo.callStatistics.functionZeroCrossingsEquations++;
  
  data->simulationInfo.discreteCall = 0;
  IntegerNetwork1_eqFunction_29(data);

  IntegerNetwork1_eqFunction_31(data);

  IntegerNetwork1_eqFunction_42(data);
  
  TRACE_POP
  return 0;
}

int IntegerNetwork1_function_ZeroCrossings(DATA *data, double *gout)
{
  TRACE_PUSH
  modelica_boolean tmp1026;
  modelica_boolean tmp1027;
  modelica_boolean tmp1028;
  modelica_boolean tmp1029;
  modelica_boolean tmp1030;
  modelica_boolean tmp1031;
  
  data->simulationInfo.callStatistics.functionZeroCrossings++;
  
  tmp1026 = LessZC(time, $Psine$PstartTime, data->simulationInfo.storedRelations[0]);
  gout[0] = (tmp1026) ? 1 : -1;
  tmp1027 = GreaterZC($Py5, 0.0, data->simulationInfo.storedRelations[1]);
  gout[1] = (tmp1027) ? 1 : -1;
  gout[2] = (floor(floor((0.5 + $Py5))) != floor(data->simulationInfo.mathEventsValuePre[(modelica_integer) 0])) ? 1 : -1;
  gout[3] = (floor((0.5 + $Py5)) != floor(data->simulationInfo.mathEventsValuePre[(modelica_integer) 1])) ? 1 : -1;
  gout[4] = (floor(ceil(($Py5 + -0.5))) != floor(data->simulationInfo.mathEventsValuePre[(modelica_integer) 2])) ? 1 : -1;
  gout[5] = (ceil(($Py5 + -0.5)) != ceil(data->simulationInfo.mathEventsValuePre[(modelica_integer) 3])) ? 1 : -1;
  tmp1028 = GreaterEqZC(time, $PbooleanPulse1$PpulsStart, data->simulationInfo.storedRelations[2]);
  tmp1029 = LessZC(time, ($PbooleanPulse1$PpulsStart + 0.5), data->simulationInfo.storedRelations[3]);
  gout[6] = ((tmp1028 && tmp1029)) ? 1 : -1;
  tmp1030 = GreaterEqZC(time, $PbooleanPulse2$PpulsStart, data->simulationInfo.storedRelations[4]);
  tmp1031 = LessZC(time, ($PbooleanPulse2$PpulsStart + 1.6), data->simulationInfo.storedRelations[5]);
  gout[7] = ((tmp1030 && tmp1031)) ? 1 : -1;
  
  TRACE_POP
  return 0;
}

const char *IntegerNetwork1_relationDescription(int i)
{
  const char *res[] = {"time < sine.startTime",
  "y5 > 0.0",
  "time >= booleanPulse1.pulsStart",
  "time < booleanPulse1.pulsStart + 0.5",
  "time >= booleanPulse2.pulsStart",
  "time < booleanPulse2.pulsStart + 1.6"};
  return res[i];
}

int IntegerNetwork1_function_updateRelations(DATA *data, int evalforZeroCross)
{
  TRACE_PUSH
  modelica_boolean tmp1032;
  modelica_boolean tmp1033;
  modelica_boolean tmp1034;
  modelica_boolean tmp1035;
  modelica_boolean tmp1036;
  modelica_boolean tmp1037;
  
  
  if(evalforZeroCross)
  {
    tmp1032 = LessZC(time, $Psine$PstartTime, data->simulationInfo.storedRelations[0]);
    data->simulationInfo.relations[0] = tmp1032;
    tmp1033 = GreaterZC($Py5, 0.0, data->simulationInfo.storedRelations[1]);
    data->simulationInfo.relations[1] = tmp1033;
    tmp1034 = GreaterEqZC(time, $PbooleanPulse1$PpulsStart, data->simulationInfo.storedRelations[2]);
    data->simulationInfo.relations[2] = tmp1034;
    tmp1035 = LessZC(time, ($PbooleanPulse1$PpulsStart + 0.5), data->simulationInfo.storedRelations[3]);
    data->simulationInfo.relations[3] = tmp1035;
    tmp1036 = GreaterEqZC(time, $PbooleanPulse2$PpulsStart, data->simulationInfo.storedRelations[4]);
    data->simulationInfo.relations[4] = tmp1036;
    tmp1037 = LessZC(time, ($PbooleanPulse2$PpulsStart + 1.6), data->simulationInfo.storedRelations[5]);
    data->simulationInfo.relations[5] = tmp1037;
  }
  else
  {
    data->simulationInfo.relations[0] = (time < $Psine$PstartTime);
    data->simulationInfo.relations[1] = ($Py5 > 0.0);
    data->simulationInfo.relations[2] = (time >= $PbooleanPulse1$PpulsStart);
    data->simulationInfo.relations[3] = (time < ($PbooleanPulse1$PpulsStart + 0.5));
    data->simulationInfo.relations[4] = (time >= $PbooleanPulse2$PpulsStart);
    data->simulationInfo.relations[5] = (time < ($PbooleanPulse2$PpulsStart + 1.6));
  }
  
  TRACE_POP
  return 0;
}

int IntegerNetwork1_checkForDiscreteChanges(DATA *data)
{
  TRACE_PUSH
  int needToIterate = 0;

  infoStreamPrint(LOG_EVENTS_V, 1, "check for discrete changes at time=%.12g", data->localData[0]->timeValue);
  if($P$whenCondition4 != $P$PRE$P$whenCondition4)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: $whenCondition4 from %d to %d", $P$PRE$P$whenCondition4, $P$whenCondition4);
    needToIterate = 1;
  }
  if($P$whenCondition3 != $P$PRE$P$whenCondition3)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: $whenCondition3 from %d to %d", $P$PRE$P$whenCondition3, $P$whenCondition3);
    needToIterate = 1;
  }
  if($P$whenCondition2 != $P$PRE$P$whenCondition2)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: $whenCondition2 from %d to %d", $P$PRE$P$whenCondition2, $P$whenCondition2);
    needToIterate = 1;
  }
  if($P$whenCondition1 != $P$PRE$P$whenCondition1)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: $whenCondition1 from %d to %d", $P$PRE$P$whenCondition1, $P$whenCondition1);
    needToIterate = 1;
  }
  if($PtriggeredAdd$Py != $P$PRE$PtriggeredAdd$Py)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: triggeredAdd._y from %ld to %ld", $P$PRE$PtriggeredAdd$Py, $PtriggeredAdd$Py);
    needToIterate = 1;
  }
  if($PbooleanPulse1$PpulsStart != $P$PRE$PbooleanPulse1$PpulsStart)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: booleanPulse1._pulsStart from %g to %g", $P$PRE$PbooleanPulse1$PpulsStart, $PbooleanPulse1$PpulsStart);
    needToIterate = 1;
  }
  if($PmultiSwitch1$Py != $P$PRE$PmultiSwitch1$Py)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: multiSwitch1._y from %ld to %ld", $P$PRE$PmultiSwitch1$Py, $PmultiSwitch1$Py);
    needToIterate = 1;
  }
  if($PmultiSwitch1$PfirstActiveIndex != $P$PRE$PmultiSwitch1$PfirstActiveIndex)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: multiSwitch1._firstActiveIndex from %ld to %ld", $P$PRE$PmultiSwitch1$PfirstActiveIndex, $PmultiSwitch1$PfirstActiveIndex);
    needToIterate = 1;
  }
  if($PmultiSwitch1$Pu$lB1$rB != $P$PRE$PmultiSwitch1$Pu$lB1$rB)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: multiSwitch1._u[1] from %d to %d", $P$PRE$PmultiSwitch1$Pu$lB1$rB, $PmultiSwitch1$Pu$lB1$rB);
    needToIterate = 1;
  }
  if($PmultiSwitch1$Pu$lB2$rB != $P$PRE$PmultiSwitch1$Pu$lB2$rB)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: multiSwitch1._u[2] from %d to %d", $P$PRE$PmultiSwitch1$Pu$lB2$rB, $PmultiSwitch1$Pu$lB2$rB);
    needToIterate = 1;
  }
  if($PbooleanPulse2$PpulsStart != $P$PRE$PbooleanPulse2$PpulsStart)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: booleanPulse2._pulsStart from %g to %g", $P$PRE$PbooleanPulse2$PpulsStart, $PbooleanPulse2$PpulsStart);
    needToIterate = 1;
  }
  if($Py != $P$PRE$Py)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: y from %ld to %ld", $P$PRE$Py, $Py);
    needToIterate = 1;
  }
  if($Py1 != $P$PRE$Py1)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: y1 from %ld to %ld", $P$PRE$Py1, $Py1);
    needToIterate = 1;
  }
  if($Py2 != $P$PRE$Py2)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: y2 from %ld to %ld", $P$PRE$Py2, $Py2);
    needToIterate = 1;
  }
  if($Py3 != $P$PRE$Py3)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: y3 from %ld to %ld", $P$PRE$Py3, $Py3);
    needToIterate = 1;
  }
  if($Py4 != $P$PRE$Py4)
  {
    infoStreamPrint(LOG_EVENTS_V, 0, "discrete var changed: y4 from %ld to %ld", $P$PRE$Py4, $Py4);
    needToIterate = 1;
  }
  if (ACTIVE_STREAM(LOG_EVENTS_V)) messageClose(LOG_EVENTS_V);
  
  TRACE_POP
  return needToIterate;
}

#if defined(__cplusplus)
}
#endif

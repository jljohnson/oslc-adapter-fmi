/* Main Simulation File */
/* Simulation code for BooleanNetwork1 generated by the OpenModelica Compiler 1.9.2+dev (r24999). */

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

#include "BooleanNetwork1_functions.h"
#include "BooleanNetwork1_model.h"
#include "BooleanNetwork1_literals.h"




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


#define prefixedName_performSimulation BooleanNetwork1_performSimulation
#include <simulation/solver/perform_simulation.c>

#define prefixedName_performQSSSimulation BooleanNetwork1_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c>

/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif
int measure_time_flag = 0;

int BooleanNetwork1_input_function(DATA *data)
{
  TRACE_PUSH

  $PbooleanStep = data->simulationInfo.inputVars[0];
  
  TRACE_POP
  return 0;
}

int BooleanNetwork1_input_function_init(DATA *data)
{
  TRACE_PUSH

  $P$ATTRIBUTE$PbooleanStep.start = data->simulationInfo.inputVars[0];
  
  TRACE_POP
  return 0;
}


int BooleanNetwork1_output_function(DATA *data)
{
  TRACE_PUSH

  data->simulationInfo.outputVars[0] = $PQ;
  data->simulationInfo.outputVars[1] = $PQI;
  data->simulationInfo.outputVars[2] = $Py;
  data->simulationInfo.outputVars[3] = $Py1;
  data->simulationInfo.outputVars[4] = $Py2;
  data->simulationInfo.outputVars[5] = $Py3;
  data->simulationInfo.outputVars[6] = $Py4;
  
  TRACE_POP
  return 0;
}


/*
 equation index: 60
 type: SIMPLE_ASSIGN
 QI = pre(rSFlipFlop.pre.u)
 */
void BooleanNetwork1_eqFunction_60(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,60};
  $PQI = $P$PRE$PrSFlipFlop$Ppre$Pu;
  TRACE_POP
}
/*
 equation index: 61
 type: SIMPLE_ASSIGN
 rSFlipFlop._S = sample(3, sampleTriggerSet.startTime, sampleTriggerSet.period)
 */
void BooleanNetwork1_eqFunction_61(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
  $PrSFlipFlop$PS = $P$sample3;
  TRACE_POP
}
/*
 equation index: 62
 type: SIMPLE_ASSIGN
 rSFlipFlop._R = sample(4, sampleTriggerReset.startTime, sampleTriggerReset.period)
 */
void BooleanNetwork1_eqFunction_62(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
  $PrSFlipFlop$PR = $P$sample4;
  TRACE_POP
}
/*
 equation index: 63
 type: SIMPLE_ASSIGN
 Q = not (QI or rSFlipFlop.R)
 */
void BooleanNetwork1_eqFunction_63(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,63};
  $PQ = (!($PQI || $PrSFlipFlop$PR));
  TRACE_POP
}
/*
 equation index: 64
 type: SIMPLE_ASSIGN
 rSFlipFlop._pre._u = not (rSFlipFlop.S or Q)
 */
void BooleanNetwork1_eqFunction_64(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,64};
  $PrSFlipFlop$Ppre$Pu = (!($PrSFlipFlop$PS || $PQ));
  TRACE_POP
}
/*
 equation index: 65
 type: ALGORITHM
 
   booleanTable.y := pre(booleanTable.y);
   booleanTable.nextTime := pre(booleanTable.nextTime);
   booleanTable.index := pre(booleanTable.index);
   $whenCondition1 := pre($whenCondition1);
   $whenCondition1 := time >= pre(booleanTable.nextTime);
   when $whenCondition1 then
     if booleanTable.index < 7 then
       booleanTable.index := 1 + booleanTable.index;
       booleanTable.nextTime := booleanTable.table[booleanTable.index];
       booleanTable.y := not booleanTable.y;
     elseif booleanTable.index == 7 then
       booleanTable.index := 1 + booleanTable.index;
       booleanTable.y := not booleanTable.y;
     end if;
   end when;
 */
void BooleanNetwork1_eqFunction_65(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  modelica_boolean tmp50;
  modelica_boolean tmp51;
  $PbooleanTable$Py = $P$PRE$PbooleanTable$Py;

  $PbooleanTable$PnextTime = $P$PRE$PbooleanTable$PnextTime;

  $PbooleanTable$Pindex = $P$PRE$PbooleanTable$Pindex;

  $P$whenCondition1 = $P$PRE$P$whenCondition1;

  RELATIONHYSTERESIS(tmp50, time, $P$PRE$PbooleanTable$PnextTime, 0, GreaterEq);
  $P$whenCondition1 = tmp50;

  if(data->simulationInfo.discreteCall == 1)
  {
    if(initial())
    {
      ; /* nothing to do */
    }
    else if(0 || ($P$whenCondition1 && !$P$PRE$P$whenCondition1 /* edge */))
    {
      tmp51 = Less((modelica_integer)$PbooleanTable$Pindex,(modelica_integer) 7);
      if(tmp51)
      {
        $PbooleanTable$Pindex = ((modelica_integer) 1 + (modelica_integer)$PbooleanTable$Pindex);

        $PbooleanTable$PnextTime = $PbooleanTable$Ptable_index((modelica_integer)$PbooleanTable$Pindex);

        $PbooleanTable$Py = (!$PbooleanTable$Py);
      }
      else
      {
        if(((modelica_integer)$PbooleanTable$Pindex == (modelica_integer) 7))
        {
          $PbooleanTable$Pindex = ((modelica_integer) 1 + (modelica_integer)$PbooleanTable$Pindex);

          $PbooleanTable$Py = (!$PbooleanTable$Py);
        }
      }
    }
  }
  TRACE_POP
}
/*
 equation index: 66
 type: SIMPLE_ASSIGN
 onDelay._u = booleanTable.y
 */
void BooleanNetwork1_eqFunction_66(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,66};
  $PonDelay$Pu = $PbooleanTable$Py;
  TRACE_POP
}
/*
 equation index: 67
 type: ALGORITHM
 
   onDelay.t_next := pre(onDelay.t_next);
   onDelay.delaySignal := pre(onDelay.delaySignal);
   $whenCondition3 := pre($whenCondition3);
   $whenCondition2 := pre($whenCondition2);
   $whenCondition2 := onDelay.u;
   $whenCondition3 := not onDelay.u;
   when initial() then
     onDelay.delaySignal := onDelay.u;
     onDelay.t_next := -1.0 + time;
   elsewhen $whenCondition2 then
     onDelay.delaySignal := true;
     onDelay.t_next := time + onDelay.delayTime;
   elsewhen $whenCondition3 then
     onDelay.delaySignal := false;
     onDelay.t_next := time + -1.0;
   end when;
 */
void BooleanNetwork1_eqFunction_67(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,67};
  $PonDelay$Pt_next = $P$PRE$PonDelay$Pt_next;

  $PonDelay$PdelaySignal = $P$PRE$PonDelay$PdelaySignal;

  $P$whenCondition3 = $P$PRE$P$whenCondition3;

  $P$whenCondition2 = $P$PRE$P$whenCondition2;

  $P$whenCondition2 = $PonDelay$Pu;

  $P$whenCondition3 = (!$PonDelay$Pu);

  if(data->simulationInfo.discreteCall == 1)
  {
    if(initial())
    {
      $PonDelay$PdelaySignal = $PonDelay$Pu;

      $PonDelay$Pt_next = (-1.0 + time);
    }
    else if(0)
    {
      $PonDelay$PdelaySignal = $PonDelay$Pu;

      $PonDelay$Pt_next = (-1.0 + time);
    }
    else if(0 || ($P$whenCondition2 && !$P$PRE$P$whenCondition2 /* edge */))
    {
      $PonDelay$PdelaySignal = 1;

      $PonDelay$Pt_next = (time + $PonDelay$PdelayTime);
    }
    else if(0 || ($P$whenCondition3 && !$P$PRE$P$whenCondition3 /* edge */))
    {
      $PonDelay$PdelaySignal = 0;

      $PonDelay$Pt_next = (time + -1.0);
    }
  }
  TRACE_POP
}
/*
 equation index: 68
 type: SIMPLE_ASSIGN
 y4 = if onDelay.delaySignal then time >= onDelay.t_next else false
 */
void BooleanNetwork1_eqFunction_68(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,68};
  modelica_boolean tmp53;
  modelica_boolean tmp54;
  modelica_boolean tmp55;
  tmp54 = (modelica_boolean)$PonDelay$PdelaySignal;
  if(tmp54)
  {
    RELATIONHYSTERESIS(tmp53, time, $PonDelay$Pt_next, 1, GreaterEq);
    tmp55 = tmp53;
  }
  else
  {
    tmp55 = 0;
  }
  $Py4 = tmp55;
  TRACE_POP
}
/*
 equation index: 69
 type: SIMPLE_ASSIGN
 $whenCondition7 = false
 */
void BooleanNetwork1_eqFunction_69(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,69};
  $P$whenCondition7 = 0;
  TRACE_POP
}
/*
 equation index: 70
 type: SIMPLE_ASSIGN
 $whenCondition5 = sample(2, booleanPulse2.startTime, booleanPulse2.period)
 */
void BooleanNetwork1_eqFunction_70(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,70};
  $P$whenCondition5 = $P$sample2;
  TRACE_POP
}
/*
 equation index: 71
 type: SIMPLE_ASSIGN
 $whenCondition4 = sample(1, booleanPulse1.startTime, booleanPulse1.period)
 */
void BooleanNetwork1_eqFunction_71(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,71};
  $P$whenCondition4 = $P$sample1;
  TRACE_POP
}
/*
 equation index: 72
 type: WHEN
 
 when {$whenCondition5} then
   booleanPulse2._pulsStart = time;
 end when;
 */
void BooleanNetwork1_eqFunction_72(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,72};
  if(initial())
  {
    $PbooleanPulse2$PpulsStart = $P$PRE$PbooleanPulse2$PpulsStart;
  }
  else if(0 || ($P$whenCondition5 && !$P$PRE$P$whenCondition5 /* edge */))
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
 equation index: 73
 type: SIMPLE_ASSIGN
 rising._u = time >= booleanPulse2.pulsStart and time < booleanPulse2.pulsStart + 0.8
 */
void BooleanNetwork1_eqFunction_73(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,73};
  modelica_boolean tmp56;
  modelica_boolean tmp57;
  RELATIONHYSTERESIS(tmp56, time, $PbooleanPulse2$PpulsStart, 4, GreaterEq);
  RELATIONHYSTERESIS(tmp57, time, ($PbooleanPulse2$PpulsStart + 0.8), 5, Less);
  $Prising$Pu = (tmp56 && tmp57);
  TRACE_POP
}
/*
 equation index: 74
 type: SIMPLE_ASSIGN
 falling._not_u = not rising.u
 */
void BooleanNetwork1_eqFunction_74(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,74};
  $Pfalling$Pnot_u = (!$Prising$Pu);
  TRACE_POP
}
/*
 equation index: 75
 type: SIMPLE_ASSIGN
 changing._u = not falling.not_u
 */
void BooleanNetwork1_eqFunction_75(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,75};
  $Pchanging$Pu = (!$Pfalling$Pnot_u);
  TRACE_POP
}
/*
 equation index: 76
 type: SIMPLE_ASSIGN
 changing._y = changing.u <> pre(changing.u)
 */
void BooleanNetwork1_eqFunction_76(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,76};
  $Pchanging$Py = ((!$Pchanging$Pu && $P$PRE$Pchanging$Pu) || ($Pchanging$Pu && !$P$PRE$Pchanging$Pu));
  TRACE_POP
}
/*
 equation index: 77
 type: SIMPLE_ASSIGN
 $whenCondition6 = changing.y
 */
void BooleanNetwork1_eqFunction_77(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,77};
  $P$whenCondition6 = $Pchanging$Py;
  TRACE_POP
}
/*
 equation index: 78
 type: WHEN
 
 when {$whenCondition7, $whenCondition6} then
   triggeredAdd._y = pre(triggeredAdd.y) + integerConstant.k;
 end when;
 */
void BooleanNetwork1_eqFunction_78(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,78};
  if(initial())
  {
    $PtriggeredAdd$Py = $P$PRE$PtriggeredAdd$Py;
  }
  else if(0 || ($P$whenCondition7 && !$P$PRE$P$whenCondition7 /* edge */) || ($P$whenCondition6 && !$P$PRE$P$whenCondition6 /* edge */))
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
 equation index: 79
 type: SIMPLE_ASSIGN
 y1 = triggeredAdd.y
 */
void BooleanNetwork1_eqFunction_79(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,79};
  $Py1 = (modelica_integer)$PtriggeredAdd$Py;
  TRACE_POP
}
/*
 equation index: 80
 type: SIMPLE_ASSIGN
 y2 = not falling.not_u
 */
void BooleanNetwork1_eqFunction_80(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,80};
  $Py2 = (!$Pfalling$Pnot_u);
  TRACE_POP
}
/*
 equation index: 81
 type: SIMPLE_ASSIGN
 set1._u[2] = falling.not_u and not pre(falling.not_u)
 */
void BooleanNetwork1_eqFunction_81(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,81};
  $Pset1$Pu$lB2$rB = ($Pfalling$Pnot_u && (!$P$PRE$Pfalling$Pnot_u));
  TRACE_POP
}
/*
 equation index: 82
 type: SIMPLE_ASSIGN
 set1._u[1] = rising.u and not pre(rising.u)
 */
void BooleanNetwork1_eqFunction_82(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,82};
  $Pset1$Pu$lB1$rB = ($Prising$Pu && (!$P$PRE$Prising$Pu));
  TRACE_POP
}
/*
 equation index: 83
 type: SIMPLE_ASSIGN
 set1._firstActiveIndex = Modelica.Math.BooleanVectors.firstTrueIndex({set1.u[1], set1.u[2]})
 */
void BooleanNetwork1_eqFunction_83(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,83};
  boolean_array tmp59;
  array_alloc_scalar_boolean_array(&tmp59, 2, (modelica_boolean)$Pset1$Pu$lB1$rB, (modelica_boolean)$Pset1$Pu$lB2$rB);
  $Pset1$PfirstActiveIndex = omc_Modelica_Math_BooleanVectors_firstTrueIndex(threadData, tmp59);
  TRACE_POP
}
/*
 equation index: 84
 type: SIMPLE_ASSIGN
 set1._y = if set1.firstActiveIndex == 0 then if set1.use_pre_as_default then pre(set1.y) else set1.y_default else set1.expr[set1.firstActiveIndex]
 */
void BooleanNetwork1_eqFunction_84(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,84};
  $Pset1$Py = (((modelica_integer)$Pset1$PfirstActiveIndex == (modelica_integer) 0)?($Pset1$Puse_pre_as_default?$P$PRE$Pset1$Py:$Pset1$Py_default):$Pset1$Pexpr_index((modelica_integer)$Pset1$PfirstActiveIndex));
  TRACE_POP
}
/*
 equation index: 85
 type: SIMPLE_ASSIGN
 y3 = set1.y
 */
void BooleanNetwork1_eqFunction_85(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,85};
  $Py3 = $Pset1$Py;
  TRACE_POP
}
/*
 equation index: 86
 type: WHEN
 
 when {$whenCondition4} then
   booleanPulse1._pulsStart = time;
 end when;
 */
void BooleanNetwork1_eqFunction_86(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,86};
  if(initial())
  {
    $PbooleanPulse1$PpulsStart = $P$PRE$PbooleanPulse1$PpulsStart;
  }
  else if(0 || ($P$whenCondition4 && !$P$PRE$P$whenCondition4 /* edge */))
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
 equation index: 87
 type: SIMPLE_ASSIGN
 and1._u[1] = time >= booleanPulse1.pulsStart and time < booleanPulse1.pulsStart + 0.2
 */
void BooleanNetwork1_eqFunction_87(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,87};
  modelica_boolean tmp61;
  modelica_boolean tmp62;
  RELATIONHYSTERESIS(tmp61, time, $PbooleanPulse1$PpulsStart, 2, GreaterEq);
  RELATIONHYSTERESIS(tmp62, time, ($PbooleanPulse1$PpulsStart + 0.2), 3, Less);
  $Pand1$Pu$lB1$rB = (tmp61 && tmp62);
  TRACE_POP
}
/*
 equation index: 88
 type: SIMPLE_ASSIGN
 y = Modelica.Math.BooleanVectors.allTrue({and1.u[1], booleanStep, rising.u})
 */
void BooleanNetwork1_eqFunction_88(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,88};
  boolean_array tmp63;
  array_alloc_scalar_boolean_array(&tmp63, 3, (modelica_boolean)$Pand1$Pu$lB1$rB, (modelica_boolean)$PbooleanStep, (modelica_boolean)$Prising$Pu);
  $Py = omc_Modelica_Math_BooleanVectors_allTrue(threadData, tmp63);
  TRACE_POP
}
/*
 equation index: 89
 type: SIMPLE_ASSIGN
 xor1._u[1] = Modelica.Math.BooleanVectors.anyTrue({y, rising.u})
 */
void BooleanNetwork1_eqFunction_89(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,89};
  boolean_array tmp64;
  array_alloc_scalar_boolean_array(&tmp64, 2, (modelica_boolean)$Py, (modelica_boolean)$Prising$Pu);
  $Pxor1$Pu$lB1$rB = omc_Modelica_Math_BooleanVectors_anyTrue(threadData, tmp64);
  TRACE_POP
}
/*
 equation index: 90
 type: SIMPLE_ASSIGN
 nand1._u[1] = Modelica.Math.BooleanVectors.oneTrue({xor1.u[1], rising.u})
 */
void BooleanNetwork1_eqFunction_90(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
  boolean_array tmp65;
  array_alloc_scalar_boolean_array(&tmp65, 2, (modelica_boolean)$Pxor1$Pu$lB1$rB, (modelica_boolean)$Prising$Pu);
  $Pnand1$Pu$lB1$rB = omc_Modelica_Math_BooleanVectors_oneTrue(threadData, tmp65);
  TRACE_POP
}
/*
 equation index: 91
 type: SIMPLE_ASSIGN
 or2._u[1] = not Modelica.Math.BooleanVectors.allTrue({nand1.u[1], rising.u})
 */
void BooleanNetwork1_eqFunction_91(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,91};
  boolean_array tmp66;
  array_alloc_scalar_boolean_array(&tmp66, 2, (modelica_boolean)$Pnand1$Pu$lB1$rB, (modelica_boolean)$Prising$Pu);
  $Por2$Pu$lB1$rB = (!omc_Modelica_Math_BooleanVectors_allTrue(threadData, tmp66));
  TRACE_POP
}
/*
 equation index: 92
 type: SIMPLE_ASSIGN
 nor1._y = Modelica.Math.BooleanVectors.anyTrue({or2.u[1], rising.u})
 */
void BooleanNetwork1_eqFunction_92(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,92};
  boolean_array tmp67;
  array_alloc_scalar_boolean_array(&tmp67, 2, (modelica_boolean)$Por2$Pu$lB1$rB, (modelica_boolean)$Prising$Pu);
  $Pnor1$Py = omc_Modelica_Math_BooleanVectors_anyTrue(threadData, tmp67);
  TRACE_POP
}


int BooleanNetwork1_functionDAE(DATA *data)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo.needToIterate = 0;
  data->simulationInfo.discreteCall = 1;
  BooleanNetwork1_eqFunction_60(data);

  BooleanNetwork1_eqFunction_61(data);

  BooleanNetwork1_eqFunction_62(data);

  BooleanNetwork1_eqFunction_63(data);

  BooleanNetwork1_eqFunction_64(data);

  BooleanNetwork1_eqFunction_65(data);

  BooleanNetwork1_eqFunction_66(data);

  BooleanNetwork1_eqFunction_67(data);

  BooleanNetwork1_eqFunction_68(data);

  BooleanNetwork1_eqFunction_69(data);

  BooleanNetwork1_eqFunction_70(data);

  BooleanNetwork1_eqFunction_71(data);

  BooleanNetwork1_eqFunction_72(data);

  BooleanNetwork1_eqFunction_73(data);

  BooleanNetwork1_eqFunction_74(data);

  BooleanNetwork1_eqFunction_75(data);

  BooleanNetwork1_eqFunction_76(data);

  BooleanNetwork1_eqFunction_77(data);

  BooleanNetwork1_eqFunction_78(data);

  BooleanNetwork1_eqFunction_79(data);

  BooleanNetwork1_eqFunction_80(data);

  BooleanNetwork1_eqFunction_81(data);

  BooleanNetwork1_eqFunction_82(data);

  BooleanNetwork1_eqFunction_83(data);

  BooleanNetwork1_eqFunction_84(data);

  BooleanNetwork1_eqFunction_85(data);

  BooleanNetwork1_eqFunction_86(data);

  BooleanNetwork1_eqFunction_87(data);

  BooleanNetwork1_eqFunction_88(data);

  BooleanNetwork1_eqFunction_89(data);

  BooleanNetwork1_eqFunction_90(data);

  BooleanNetwork1_eqFunction_91(data);

  BooleanNetwork1_eqFunction_92(data);
  
  
  
  
  TRACE_POP
  return 0;
}


int BooleanNetwork1_functionODE(DATA *data)
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

#include "BooleanNetwork1_12jac.h"
#include "BooleanNetwork1_13opt.h"
extern void BooleanNetwork1_callExternalObjectConstructors(DATA *data);
extern void BooleanNetwork1_callExternalObjectDestructors(DATA *_data);
extern void BooleanNetwork1_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA *data);
extern void BooleanNetwork1_initialLinearSystem(int nLinearSystems, LINEAR_SYSTEM_DATA *data);
extern void BooleanNetwork1_initialMixedSystem(int nMixedSystems, MIXED_SYSTEM_DATA *data);
extern void BooleanNetwork1_initializeStateSets(int nStateSets, STATE_SET_DATA* statesetData, DATA *data);
extern int BooleanNetwork1_functionAlgebraics(DATA *data);
extern int BooleanNetwork1_function_storeDelayed(DATA *data);
extern int BooleanNetwork1_updateBoundVariableAttributes(DATA *data);
extern int BooleanNetwork1_functionInitialEquations(DATA *data);
extern int BooleanNetwork1_functionRemovedInitialEquations(DATA *data);
extern int BooleanNetwork1_updateBoundParameters(DATA *data);
extern int BooleanNetwork1_checkForAsserts(DATA *data);
extern int BooleanNetwork1_function_ZeroCrossingsEquations(DATA *data);
extern int BooleanNetwork1_function_ZeroCrossings(DATA *data, double* gout);
extern int BooleanNetwork1_function_updateRelations(DATA *data, int evalZeroCross);
extern int BooleanNetwork1_checkForDiscreteChanges(DATA *data);
extern const char* BooleanNetwork1_zeroCrossingDescription(int i, int **out_EquationIndexes);
extern const char* BooleanNetwork1_relationDescription(int i);
extern void BooleanNetwork1_function_initSample(DATA *data);
extern int BooleanNetwork1_initialAnalyticJacobianG(void* data);
extern int BooleanNetwork1_initialAnalyticJacobianA(void* data);
extern int BooleanNetwork1_initialAnalyticJacobianB(void* data);
extern int BooleanNetwork1_initialAnalyticJacobianC(void* data);
extern int BooleanNetwork1_initialAnalyticJacobianD(void* data);
extern int BooleanNetwork1_functionJacG_column(void* data);
extern int BooleanNetwork1_functionJacA_column(void* data);
extern int BooleanNetwork1_functionJacB_column(void* data);
extern int BooleanNetwork1_functionJacC_column(void* data);
extern int BooleanNetwork1_functionJacD_column(void* data);
extern const char* BooleanNetwork1_linear_model_frame(void);
extern int BooleanNetwork1_mayer(DATA* data, modelica_real** res, short *);
extern int BooleanNetwork1_lagrange(DATA* data, modelica_real** res, short *, short *);
extern int BooleanNetwork1_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
extern int BooleanNetwork1_setInputData(DATA *data);
extern int BooleanNetwork1_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);

struct OpenModelicaGeneratedFunctionCallbacks BooleanNetwork1_callback = {
   (int (*)(DATA *, void *)) BooleanNetwork1_performSimulation,
   (int (*)(DATA *, void *)) BooleanNetwork1_performQSSSimulation,
   BooleanNetwork1_callExternalObjectConstructors,
   BooleanNetwork1_callExternalObjectDestructors,
   BooleanNetwork1_initialNonLinearSystem,
   BooleanNetwork1_initialLinearSystem,
   BooleanNetwork1_initialMixedSystem,
   BooleanNetwork1_initializeStateSets,
   BooleanNetwork1_functionODE,
   BooleanNetwork1_functionAlgebraics,
   BooleanNetwork1_functionDAE,
   BooleanNetwork1_input_function,
   BooleanNetwork1_input_function_init,
   BooleanNetwork1_output_function,
   BooleanNetwork1_function_storeDelayed,
   BooleanNetwork1_updateBoundVariableAttributes,
   1 /* useSymbolicInitialization */,
   0 /* useHomotopy */,
   BooleanNetwork1_functionInitialEquations,
   BooleanNetwork1_functionRemovedInitialEquations,
   BooleanNetwork1_updateBoundParameters,
   BooleanNetwork1_checkForAsserts,
   BooleanNetwork1_function_ZeroCrossingsEquations,
   BooleanNetwork1_function_ZeroCrossings,
   BooleanNetwork1_function_updateRelations,
   BooleanNetwork1_checkForDiscreteChanges,
   BooleanNetwork1_zeroCrossingDescription,
   BooleanNetwork1_relationDescription,
   BooleanNetwork1_function_initSample,
   BooleanNetwork1_INDEX_JAC_A,
   BooleanNetwork1_INDEX_JAC_B,
   BooleanNetwork1_INDEX_JAC_C,
   BooleanNetwork1_INDEX_JAC_D,
   BooleanNetwork1_initialAnalyticJacobianA,
   BooleanNetwork1_initialAnalyticJacobianB,
   BooleanNetwork1_initialAnalyticJacobianC,
   BooleanNetwork1_initialAnalyticJacobianD,
   BooleanNetwork1_functionJacA_column,
   BooleanNetwork1_functionJacB_column,
   BooleanNetwork1_functionJacC_column,
   BooleanNetwork1_functionJacD_column,
   BooleanNetwork1_linear_model_frame,
   BooleanNetwork1_mayer,
   BooleanNetwork1_lagrange,
   BooleanNetwork1_pickUpBoundsForInputsInOptimization,
   BooleanNetwork1_setInputData,
   BooleanNetwork1_getTimeGrid

};

void BooleanNetwork1_setupDataStruc(DATA *data)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  data->callback = &BooleanNetwork1_callback;
  data->modelData.modelName = "BooleanNetwork1";
  data->modelData.modelFilePrefix = "BooleanNetwork1";
  data->modelData.resultFileName = NULL;
  data->modelData.modelDir = "c:/OpenModelicaExternal/tools/FMI/Test_FMUs/FMI_1.0/ModelExchange/win32/OpenModelica/1.9.2/BooleanNetwork1";
  data->modelData.modelGUID = "{8c4e810f-3df3-4a00-8276-176fa3c9f9e0}";
  #ifdef OPENMODELICA_XML_FROM_FILE_AT_RUNTIME
  data->modelData.initXMLData = NULL;
  data->modelData.modelDataXml.infoXMLData = NULL;
  #else
  data->modelData.initXMLData =
  #include "BooleanNetwork1_init.c"
  ;
  data->modelData.modelDataXml.infoXMLData =
  #include "BooleanNetwork1_info.c"
  ;
  #endif
  
  data->modelData.nStates = 0;
  data->modelData.nVariablesReal = 2*0+0+4+0 + 0;
  data->modelData.nDiscreteReal = 4;
  data->modelData.nVariablesInteger = 6;
  data->modelData.nVariablesBoolean = 41;
  data->modelData.nVariablesString = 0;
  data->modelData.nParametersReal = 20;
  data->modelData.nParametersInteger = 9;
  data->modelData.nParametersBoolean = 17;
  data->modelData.nParametersString = 0;
  data->modelData.nInputVars = 1;
  data->modelData.nOutputVars = 7;
  
  data->modelData.nAliasReal = 0;
  data->modelData.nAliasInteger = 4;
  data->modelData.nAliasBoolean = 43;
  data->modelData.nAliasString = 0;
  
  data->modelData.nZeroCrossings = 4;
  data->modelData.nSamples = 4;
  data->modelData.nRelations = 6;
  data->modelData.nMathEvents = 0;
  data->modelData.nExtObjs = 0;
  setupModelInfoFunctions(1);
  data->modelData.modelDataXml.fileName = "BooleanNetwork1_info.json";
  data->modelData.modelDataXml.modelInfoXmlLength = 0;
  data->modelData.modelDataXml.nFunctions = 6;
  data->modelData.modelDataXml.nProfileBlocks = 0;
  data->modelData.modelDataXml.nEquations = 106;
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
  
    BooleanNetwork1_setupDataStruc(&simulation_data);
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

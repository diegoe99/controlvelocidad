/*
 * ControlVelocidad.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ControlVelocidad".
 *
 * Model version              : 1.11
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sun May  7 00:06:31 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ControlVelocidad_h_
#define RTW_HEADER_ControlVelocidad_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ControlVelocidad_COMMON_INCLUDES_
#define ControlVelocidad_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ControlVelocidad_COMMON_INCLUDES_ */

#include "ControlVelocidad_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#define ControlVelocidad_M_TYPE        RT_MODEL_ControlVelocidad_T

/* Block signals (default storage) */
typedef struct {
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Inductancia;                  /* '<S1>/Inductancia' */
  real_T Inercia;                      /* '<S1>/Inercia' */
  real_T Inductancia_l;                /* '<S3>/Inductancia' */
  real_T Inercia_o;                    /* '<S3>/Inercia' */
} B_ControlVelocidad_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator1_CSTATE_c;         /* '<S3>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE_m;         /* '<Root>/Integrator1' */
  real_T Integrator_CSTATE_a;          /* '<S1>/Integrator' */
  real_T Integrator_CSTATE_a3;         /* '<S3>/Integrator' */
} X_ControlVelocidad_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator1_CSTATE_c;         /* '<S3>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE_m;         /* '<Root>/Integrator1' */
  real_T Integrator_CSTATE_a;          /* '<S1>/Integrator' */
  real_T Integrator_CSTATE_a3;         /* '<S3>/Integrator' */
} XDot_ControlVelocidad_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
  boolean_T Integrator1_CSTATE_c;      /* '<S3>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator1_CSTATE_m;      /* '<Root>/Integrator1' */
  boolean_T Integrator_CSTATE_a;       /* '<S1>/Integrator' */
  boolean_T Integrator_CSTATE_a3;      /* '<S3>/Integrator' */
} XDis_ControlVelocidad_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Velocidadizq;                 /* '<Root>/Velocidad izq' */
  real_T Velocidadderecha;             /* '<Root>/Velocidad derecha' */
} ExtY_ControlVelocidad_T;

/* Real-time Model Data Structure */
struct tag_RTM_ControlVelocidad_T {
  const char_T *errorStatus;
  RTWSolverInfo *solverInfo;
  B_ControlVelocidad_T *blockIO;
  X_ControlVelocidad_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  ExtY_ControlVelocidad_T *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[6];
  real_T odeF[3][6];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Model entry point functions */
extern RT_MODEL_ControlVelocidad_T *ControlVelocidad(void);
extern void ControlVelocidad_initialize(RT_MODEL_ControlVelocidad_T *const
  ControlVelocidad_M);
extern void ControlVelocidad_step(RT_MODEL_ControlVelocidad_T *const
  ControlVelocidad_M);
extern void ControlVelocidad_terminate(RT_MODEL_ControlVelocidad_T
  * ControlVelocidad_M);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<S4>/Clock' : Unused code path elimination
 * Block '<S4>/Clock1' : Unused code path elimination
 * Block '<S4>/Clock2' : Unused code path elimination
 * Block '<S4>/Clock3' : Unused code path elimination
 * Block '<S4>/Clock4' : Unused code path elimination
 * Block '<S4>/Clock5' : Unused code path elimination
 * Block '<S4>/Constant' : Unused code path elimination
 * Block '<S4>/Constant1' : Unused code path elimination
 * Block '<S4>/Constant2' : Unused code path elimination
 * Block '<S4>/Constant6' : Unused code path elimination
 * Block '<S4>/Gain' : Unused code path elimination
 * Block '<S4>/Gain1' : Unused code path elimination
 * Block '<S4>/Gain2' : Unused code path elimination
 * Block '<S4>/Gain3' : Unused code path elimination
 * Block '<S4>/Product' : Unused code path elimination
 * Block '<S4>/Product1' : Unused code path elimination
 * Block '<S4>/Sum' : Unused code path elimination
 * Block '<S4>/Sum1' : Unused code path elimination
 * Block '<S4>/Sum2' : Unused code path elimination
 * Block '<S4>/Switch' : Unused code path elimination
 * Block '<S4>/Switch1' : Unused code path elimination
 * Block '<S4>/Switch5' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ControlVelocidad'
 * '<S1>'   : 'ControlVelocidad/Subsystem'
 * '<S2>'   : 'ControlVelocidad/Subsystem1'
 * '<S3>'   : 'ControlVelocidad/Subsystem3'
 * '<S4>'   : 'ControlVelocidad/Trapezoidal'
 */
#endif                                 /* RTW_HEADER_ControlVelocidad_h_ */

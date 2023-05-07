/*
 * ControlVelocidad.c
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

#include "ControlVelocidad.h"
#include "ControlVelocidad_private.h"

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si ,
  RT_MODEL_ControlVelocidad_T *const ControlVelocidad_M)
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ControlVelocidad_derivatives(ControlVelocidad_M);

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ControlVelocidad_step(ControlVelocidad_M);
  ControlVelocidad_derivatives(ControlVelocidad_M);

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ControlVelocidad_step(ControlVelocidad_M);
  ControlVelocidad_derivatives(ControlVelocidad_M);

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void ControlVelocidad_step(RT_MODEL_ControlVelocidad_T *const ControlVelocidad_M)
{
  B_ControlVelocidad_T *ControlVelocidad_B = ControlVelocidad_M->blockIO;
  X_ControlVelocidad_T *ControlVelocidad_X = ControlVelocidad_M->contStates;
  ExtY_ControlVelocidad_T *ControlVelocidad_Y = (ExtY_ControlVelocidad_T *)
    ControlVelocidad_M->outputs;
  real_T rtb_Integrator;
  if (rtmIsMajorTimeStep(ControlVelocidad_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(ControlVelocidad_M->solverInfo,
                          ((ControlVelocidad_M->Timing.clockTick0+1)*
      ControlVelocidad_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ControlVelocidad_M)) {
    ControlVelocidad_M->Timing.t[0] = rtsiGetT(ControlVelocidad_M->solverInfo);
  }

  /* Outport: '<Root>/Velocidad izq' incorporates:
   *  Integrator: '<S1>/Integrator1'
   */
  ControlVelocidad_Y->Velocidadizq = ControlVelocidad_X->Integrator1_CSTATE;

  /* Outport: '<Root>/Velocidad derecha' incorporates:
   *  Integrator: '<S3>/Integrator1'
   */
  ControlVelocidad_Y->Velocidadderecha =
    ControlVelocidad_X->Integrator1_CSTATE_c;

  /* Clock: '<S4>/Clock9' incorporates:
   *  Clock: '<S4>/Clock7'
   *  Clock: '<S4>/Clock8'
   */
  rtb_Integrator = ControlVelocidad_M->Timing.t[0];

  /* Switch: '<S4>/Switch3' incorporates:
   *  Clock: '<S4>/Clock9'
   *  Constant: '<S4>/Constant4'
   *  Gain: '<S4>/Gain5'
   *  Sum: '<S4>/Sum3'
   *  Switch: '<S4>/Switch2'
   */
  if (rtb_Integrator > 20.0) {
    rtb_Integrator = 1.5 - 0.05 * rtb_Integrator;
  } else if (rtb_Integrator > 10.0) {
    /* Switch: '<S4>/Switch2' incorporates:
     *  Constant: '<S4>/Constant3'
     */
    rtb_Integrator = 0.5;
  } else {
    /* Switch: '<S4>/Switch2' incorporates:
     *  Clock: '<S4>/Clock6'
     *  Gain: '<S4>/Gain4'
     */
    rtb_Integrator = 0.05 * ControlVelocidad_M->Timing.t[0];
  }

  /* End of Switch: '<S4>/Switch3' */

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S4>/Constant5'
   *  Product: '<S2>/Divide1'
   *  Product: '<S2>/Product'
   *  Sum: '<S2>/Subtract'
   *  Switch: '<S2>/Switch1'
   *  Switch: '<S4>/Switch4'
   */
  rtb_Integrator = fmax((fmax(rtb_Integrator, 0.0) * 2.0 - 0.025) / 0.24, 0.0);

  /* Sum: '<Root>/Sum' incorporates:
   *  Integrator: '<S1>/Integrator1'
   *  Switch: '<S2>/Switch'
   */
  ControlVelocidad_B->Sum = rtb_Integrator -
    ControlVelocidad_X->Integrator1_CSTATE;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Integrator: '<S3>/Integrator1'
   */
  ControlVelocidad_B->Sum2 = rtb_Integrator -
    ControlVelocidad_X->Integrator1_CSTATE_c;

  /* Gain: '<S1>/Inductancia' incorporates:
   *  Gain: '<Root>/Ki'
   *  Gain: '<Root>/Kp'
   *  Gain: '<S1>/Ke'
   *  Gain: '<S1>/Resistencia'
   *  Integrator: '<Root>/Integrator'
   *  Integrator: '<S1>/Integrator'
   *  Integrator: '<S1>/Integrator1'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<S1>/Sum'
   */
  ControlVelocidad_B->Inductancia = (((5.0 *
    ControlVelocidad_X->Integrator_CSTATE + 400.0 * ControlVelocidad_B->Sum) -
    8.0 * ControlVelocidad_X->Integrator_CSTATE_a) - 0.17 *
    ControlVelocidad_X->Integrator1_CSTATE) * 5.0;

  /* Gain: '<S1>/Inercia' incorporates:
   *  Gain: '<S1>/Kt'
   *  Gain: '<S1>/amortiguación'
   *  Integrator: '<S1>/Integrator'
   *  Integrator: '<S1>/Integrator1'
   *  Sum: '<S1>/Sum1'
   */
  ControlVelocidad_B->Inercia = (0.17 * ControlVelocidad_X->Integrator_CSTATE_a
    - 0.000115 * ControlVelocidad_X->Integrator1_CSTATE) * 0.17;

  /* Gain: '<S3>/Inductancia' incorporates:
   *  Gain: '<Root>/Ki1'
   *  Gain: '<Root>/Kp1'
   *  Gain: '<S3>/Ke'
   *  Gain: '<S3>/Resistencia'
   *  Integrator: '<Root>/Integrator1'
   *  Integrator: '<S3>/Integrator'
   *  Integrator: '<S3>/Integrator1'
   *  Sum: '<Root>/Sum3'
   *  Sum: '<S3>/Sum'
   */
  ControlVelocidad_B->Inductancia_l = (((5.0 *
    ControlVelocidad_X->Integrator1_CSTATE_m + 400.0 * ControlVelocidad_B->Sum2)
    - 8.0 * ControlVelocidad_X->Integrator_CSTATE_a3) - 0.17 *
    ControlVelocidad_X->Integrator1_CSTATE_c) * 5.0;

  /* Gain: '<S3>/Inercia' incorporates:
   *  Gain: '<S3>/Kt'
   *  Gain: '<S3>/amortiguación'
   *  Integrator: '<S3>/Integrator'
   *  Integrator: '<S3>/Integrator1'
   *  Sum: '<S3>/Sum1'
   */
  ControlVelocidad_B->Inercia_o = (0.17 *
    ControlVelocidad_X->Integrator_CSTATE_a3 - 0.000115 *
    ControlVelocidad_X->Integrator1_CSTATE_c) * 0.17;
  if (rtmIsMajorTimeStep(ControlVelocidad_M)) {
    rt_ertODEUpdateContinuousStates(ControlVelocidad_M->solverInfo,
      ControlVelocidad_M);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++ControlVelocidad_M->Timing.clockTick0;
    ControlVelocidad_M->Timing.t[0] = rtsiGetSolverStopTime
      (ControlVelocidad_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      ControlVelocidad_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ControlVelocidad_derivatives(RT_MODEL_ControlVelocidad_T *const
  ControlVelocidad_M)
{
  B_ControlVelocidad_T *ControlVelocidad_B = ControlVelocidad_M->blockIO;
  XDot_ControlVelocidad_T *_rtXdot;
  _rtXdot = ((XDot_ControlVelocidad_T *) ControlVelocidad_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = ControlVelocidad_B->Inercia;

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_c = ControlVelocidad_B->Inercia_o;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = ControlVelocidad_B->Sum;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_m = ControlVelocidad_B->Sum2;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE_a = ControlVelocidad_B->Inductancia;

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE_a3 = ControlVelocidad_B->Inductancia_l;
}

/* Model initialize function */
void ControlVelocidad_initialize(RT_MODEL_ControlVelocidad_T *const
  ControlVelocidad_M)
{
  X_ControlVelocidad_T *ControlVelocidad_X = ControlVelocidad_M->contStates;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  ControlVelocidad_X->Integrator1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S3>/Integrator1' */
  ControlVelocidad_X->Integrator1_CSTATE_c = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  ControlVelocidad_X->Integrator_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  ControlVelocidad_X->Integrator1_CSTATE_m = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  ControlVelocidad_X->Integrator_CSTATE_a = 0.0;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  ControlVelocidad_X->Integrator_CSTATE_a3 = 0.0;
}

/* Model terminate function */
void ControlVelocidad_terminate(RT_MODEL_ControlVelocidad_T * ControlVelocidad_M)
{
  rt_FREE(ControlVelocidad_M->solverInfo);

  /* model code */
  rt_FREE(ControlVelocidad_M->blockIO);
  rt_FREE(ControlVelocidad_M->contStates);
  rt_FREE(ControlVelocidad_M->outputs);
  rt_FREE(ControlVelocidad_M);
}

/* Model data allocation function */
RT_MODEL_ControlVelocidad_T *ControlVelocidad(void)
{
  RT_MODEL_ControlVelocidad_T *ControlVelocidad_M;
  ControlVelocidad_M = (RT_MODEL_ControlVelocidad_T *) malloc(sizeof
    (RT_MODEL_ControlVelocidad_T));
  if (ControlVelocidad_M == (NULL)) {
    return (NULL);
  }

  (void) memset((char *)ControlVelocidad_M, 0,
                sizeof(RT_MODEL_ControlVelocidad_T));

  {
    /* Setup solver object */
    RTWSolverInfo *rt_SolverInfo = (RTWSolverInfo *) malloc(sizeof(RTWSolverInfo));
    rt_VALIDATE_MEMORY(ControlVelocidad_M,rt_SolverInfo);
    ControlVelocidad_M->solverInfo = (rt_SolverInfo);
    rtsiSetSimTimeStepPtr(ControlVelocidad_M->solverInfo,
                          &ControlVelocidad_M->Timing.simTimeStep);
    rtsiSetTPtr(ControlVelocidad_M->solverInfo, &rtmGetTPtr(ControlVelocidad_M));
    rtsiSetStepSizePtr(ControlVelocidad_M->solverInfo,
                       &ControlVelocidad_M->Timing.stepSize0);
    rtsiSetdXPtr(ControlVelocidad_M->solverInfo, &ControlVelocidad_M->derivs);
    rtsiSetContStatesPtr(ControlVelocidad_M->solverInfo, (real_T **)
                         &ControlVelocidad_M->contStates);
    rtsiSetNumContStatesPtr(ControlVelocidad_M->solverInfo,
      &ControlVelocidad_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(ControlVelocidad_M->solverInfo,
      &ControlVelocidad_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(ControlVelocidad_M->solverInfo,
      &ControlVelocidad_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(ControlVelocidad_M->solverInfo,
      &ControlVelocidad_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(ControlVelocidad_M->solverInfo, (&rtmGetErrorStatus
      (ControlVelocidad_M)));
    rtsiSetRTModelPtr(ControlVelocidad_M->solverInfo, ControlVelocidad_M);
  }

  rtsiSetSolverName(ControlVelocidad_M->solverInfo,"ode3");

  /* block I/O */
  {
    B_ControlVelocidad_T *b = (B_ControlVelocidad_T *) malloc(sizeof
      (B_ControlVelocidad_T));
    rt_VALIDATE_MEMORY(ControlVelocidad_M,b);
    ControlVelocidad_M->blockIO = (b);
  }

  /* states (continuous) */
  {
    X_ControlVelocidad_T *x = (X_ControlVelocidad_T *) malloc(sizeof
      (X_ControlVelocidad_T));
    rt_VALIDATE_MEMORY(ControlVelocidad_M,x);
    ControlVelocidad_M->contStates = (x);
  }

  /* external outputs */
  {
    ExtY_ControlVelocidad_T *ControlVelocidad_Y = (ExtY_ControlVelocidad_T *)
      malloc(sizeof(ExtY_ControlVelocidad_T));
    rt_VALIDATE_MEMORY(ControlVelocidad_M,ControlVelocidad_Y);
    ControlVelocidad_M->outputs = (ControlVelocidad_Y);
  }

  {
    B_ControlVelocidad_T *ControlVelocidad_B = ControlVelocidad_M->blockIO;
    X_ControlVelocidad_T *ControlVelocidad_X = ControlVelocidad_M->contStates;
    ExtY_ControlVelocidad_T *ControlVelocidad_Y = (ExtY_ControlVelocidad_T *)
      ControlVelocidad_M->outputs;
    rtsiSetSimTimeStep(ControlVelocidad_M->solverInfo, MAJOR_TIME_STEP);
    ControlVelocidad_M->intgData.y = ControlVelocidad_M->odeY;
    ControlVelocidad_M->intgData.f[0] = ControlVelocidad_M->odeF[0];
    ControlVelocidad_M->intgData.f[1] = ControlVelocidad_M->odeF[1];
    ControlVelocidad_M->intgData.f[2] = ControlVelocidad_M->odeF[2];
    ControlVelocidad_M->contStates = ((X_ControlVelocidad_T *)
      ControlVelocidad_X);
    rtsiSetSolverData(ControlVelocidad_M->solverInfo, (void *)
                      &ControlVelocidad_M->intgData);
    rtmSetTPtr(ControlVelocidad_M, &ControlVelocidad_M->Timing.tArray[0]);
    ControlVelocidad_M->Timing.stepSize0 = 0.001;

    /* block I/O */
    (void) memset(((void *) ControlVelocidad_B), 0,
                  sizeof(B_ControlVelocidad_T));

    /* states (continuous) */
    {
      (void) memset((void *)ControlVelocidad_X, 0,
                    sizeof(X_ControlVelocidad_T));
    }

    /* external outputs */
    (void)memset(ControlVelocidad_Y, 0, sizeof(ExtY_ControlVelocidad_T));
  }

  return ControlVelocidad_M;
}

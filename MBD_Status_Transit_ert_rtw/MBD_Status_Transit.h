/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MBD_Status_Transit.h
 *
 * Code generated for Simulink model 'MBD_Status_Transit'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Dec  9 20:34:26 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MBD_Status_Transit_h_
#define RTW_HEADER_MBD_Status_Transit_h_
#ifndef MBD_Status_Transit_COMMON_INCLUDES_
#define MBD_Status_Transit_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#endif                                 /* MBD_Status_Transit_COMMON_INCLUDES_ */

#include "MBD_Status_Transit_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  uint32_T Gain;                       /* '<Root>/Gain' */
  uint32_T Gain2;                      /* '<Root>/Gain2' */
  uint32_T Gain1;                      /* '<Root>/Gain1' */
  uint32_T Gain3;                      /* '<Root>/Gain3' */
} B_MBD_Status_Transit_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S3>/Analog to Digital Converter' */
} DW_MBD_Status_Transit_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint32_T Out1;                       /* '<Root>/Out1' */
  uint32_T Out2;                       /* '<Root>/Out2' */
  uint32_T Out3;                       /* '<Root>/Out3' */
  uint32_T Out4;                       /* '<Root>/Out4' */
} ExtY_MBD_Status_Transit_T;

/* Parameters (default storage) */
struct P_MBD_Status_Transit_T_ {
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint16_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  uint16_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  uint16_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<Root>/Gain3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_MBD_Status_Transit_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_MBD_Status_Transit_T MBD_Status_Transit_P;

/* Block signals (default storage) */
extern B_MBD_Status_Transit_T MBD_Status_Transit_B;

/* Block states (default storage) */
extern DW_MBD_Status_Transit_T MBD_Status_Transit_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_MBD_Status_Transit_T MBD_Status_Transit_Y;

/* Model entry point functions */
extern void MBD_Status_Transit_initialize(void);
extern void MBD_Status_Transit_step(void);
extern void MBD_Status_Transit_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MBD_Status_Transit_T *const MBD_Status_Transit_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'MBD_Status_Transit'
 * '<S1>'   : 'MBD_Status_Transit/Analog to Digital Converter'
 * '<S2>'   : 'MBD_Status_Transit/Analog to Digital Converter/ECSoC'
 * '<S3>'   : 'MBD_Status_Transit/Analog to Digital Converter/ECSoC/ECSimCodegen'
 */
#endif                                 /* RTW_HEADER_MBD_Status_Transit_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

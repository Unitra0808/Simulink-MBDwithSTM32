/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MBD_Status_Transit_types.h
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

#ifndef RTW_HEADER_MBD_Status_Transit_types_h_
#define RTW_HEADER_MBD_Status_Transit_types_h_
#include "rtwtypes.h"
#include "stm_adc_ll.h"

/* Custom Type definition for MATLABSystem: '<S3>/Analog to Digital Converter' */
#include "stm_adc_ll.h"
#include "stm_adc_ll.h"
#ifndef struct_tag_X9xwsB6CJnV6Kmy8hSqtIG
#define struct_tag_X9xwsB6CJnV6Kmy8hSqtIG

struct tag_X9xwsB6CJnV6Kmy8hSqtIG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  ADC_Type_T* ADCHandle;
  uint16_T ADCInternalBuffer[8];
};

#endif                                 /* struct_tag_X9xwsB6CJnV6Kmy8hSqtIG */

#ifndef typedef_stm32cube_blocks_AnalogInput__T
#define typedef_stm32cube_blocks_AnalogInput__T

typedef struct tag_X9xwsB6CJnV6Kmy8hSqtIG stm32cube_blocks_AnalogInput__T;

#endif                             /* typedef_stm32cube_blocks_AnalogInput__T */

/* Parameters (default storage) */
typedef struct P_MBD_Status_Transit_T_ P_MBD_Status_Transit_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_MBD_Status_Transit_T RT_MODEL_MBD_Status_Transit_T;

#endif                              /* RTW_HEADER_MBD_Status_Transit_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MBD_Status_Transit.c
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

#include "MBD_Status_Transit.h"
#include "MBD_Status_Transit_types.h"
#include "rtwtypes.h"
#include "stm_adc_ll.h"
#include "MBD_Status_Transit_private.h"

/* Block signals (default storage) */
B_MBD_Status_Transit_T MBD_Status_Transit_B;

/* Block states (default storage) */
DW_MBD_Status_Transit_T MBD_Status_Transit_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_MBD_Status_Transit_T MBD_Status_Transit_Y;

/* Real-time model */
static RT_MODEL_MBD_Status_Transit_T MBD_Status_Transit_M_;
RT_MODEL_MBD_Status_Transit_T *const MBD_Status_Transit_M =
  &MBD_Status_Transit_M_;

/* Forward declaration for local functions */
static void MBD_Status_Tra_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void MBD_Status_Tra_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  uint16_T module;
  uint16_T triggerType;
  uint32_T noConv;
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  adcStructLoc.dmastream = LL_DMA_STREAM_0;
  adcStructLoc.dmaPeripheralPtr = DMA2;
  adcStructLoc.InternalBufferPtr = (void*)(&obj->ADCInternalBuffer[0]);
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.InternalBufferSize = 4U;
  module = ADC_DMA_INTERRUPT_MODE;
  triggerType = ADC_TRIGGER_AND_READ;
  noConv = LL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS;
  adcStructLoc.RegularNoOfConversion = 4U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, module, 1, triggerType, noConv);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
}

/* Model step function */
void MBD_Status_Transit_step(void)
{
  uint16_T data[4];
  uint16_T triggerType;

  /* MATLABSystem: '<S3>/Analog to Digital Converter' */
  triggerType = ADC_TRIGGER_AND_READ;
  regularReadADCDMA(MBD_Status_Transit_DW.obj.ADCHandle, triggerType, &data[0]);

  /* Gain: '<Root>/Gain' incorporates:
   *  MATLABSystem: '<S3>/Analog to Digital Converter'
   */
  MBD_Status_Transit_B.Gain = (uint32_T)MBD_Status_Transit_P.Gain_Gain * data[0];

  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<Root>/Gain'
   */
  MBD_Status_Transit_Y.Out1 = MBD_Status_Transit_B.Gain;

  /* Gain: '<Root>/Gain2' incorporates:
   *  MATLABSystem: '<S3>/Analog to Digital Converter'
   */
  MBD_Status_Transit_B.Gain2 = (uint32_T)MBD_Status_Transit_P.Gain2_Gain * data
    [1];

  /* Outport: '<Root>/Out2' incorporates:
   *  Gain: '<Root>/Gain2'
   */
  MBD_Status_Transit_Y.Out2 = MBD_Status_Transit_B.Gain2;

  /* Gain: '<Root>/Gain1' incorporates:
   *  MATLABSystem: '<S3>/Analog to Digital Converter'
   */
  MBD_Status_Transit_B.Gain1 = (uint32_T)MBD_Status_Transit_P.Gain1_Gain * data
    [2];

  /* Outport: '<Root>/Out3' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  MBD_Status_Transit_Y.Out3 = MBD_Status_Transit_B.Gain1;

  /* Gain: '<Root>/Gain3' incorporates:
   *  MATLABSystem: '<S3>/Analog to Digital Converter'
   */
  MBD_Status_Transit_B.Gain3 = (uint32_T)MBD_Status_Transit_P.Gain3_Gain * data
    [3];

  /* Outport: '<Root>/Out4' incorporates:
   *  Gain: '<Root>/Gain3'
   */
  MBD_Status_Transit_Y.Out4 = MBD_Status_Transit_B.Gain3;

  {                                    /* Sample time: [0.0001s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  MBD_Status_Transit_M->Timing.taskTime0 =
    ((time_T)(++MBD_Status_Transit_M->Timing.clockTick0)) *
    MBD_Status_Transit_M->Timing.stepSize0;
}

/* Model initialize function */
void MBD_Status_Transit_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(MBD_Status_Transit_M, -1);
  MBD_Status_Transit_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  MBD_Status_Transit_M->Sizes.checksums[0] = (2936424884U);
  MBD_Status_Transit_M->Sizes.checksums[1] = (1531385032U);
  MBD_Status_Transit_M->Sizes.checksums[2] = (2046238870U);
  MBD_Status_Transit_M->Sizes.checksums[3] = (725181320U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    MBD_Status_Transit_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(MBD_Status_Transit_M->extModeInfo,
      &MBD_Status_Transit_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(MBD_Status_Transit_M->extModeInfo,
                        MBD_Status_Transit_M->Sizes.checksums);
    rteiSetTPtr(MBD_Status_Transit_M->extModeInfo, rtmGetTPtr
                (MBD_Status_Transit_M));
  }

  /* Start for MATLABSystem: '<S3>/Analog to Digital Converter' */
  MBD_Status_Transit_DW.obj.isInitialized = 0;
  MBD_Status_Transit_DW.obj.matlabCodegenIsDeleted = false;
  MBD_Status_Tra_SystemCore_setup(&MBD_Status_Transit_DW.obj);
}

/* Model terminate function */
void MBD_Status_Transit_terminate(void)
{
  uint16_T mode;

  /* Terminate for MATLABSystem: '<S3>/Analog to Digital Converter' */
  if (!MBD_Status_Transit_DW.obj.matlabCodegenIsDeleted) {
    MBD_Status_Transit_DW.obj.matlabCodegenIsDeleted = true;
    if ((MBD_Status_Transit_DW.obj.isInitialized == 1) &&
        MBD_Status_Transit_DW.obj.isSetupComplete) {
      mode = ADC_DMA_INTERRUPT_MODE;
      ADC_Handle_Deinit(MBD_Status_Transit_DW.obj.ADCHandle, mode, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog to Digital Converter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

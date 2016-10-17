/* Include files */

#include "blascompat32.h"
#include "penduloInvNoLineal_sfun.h"
#include "c5_penduloInvNoLineal.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "penduloInvNoLineal_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[9] = { "nargin", "nargout",
  "ActualAngle", "criticalAngle", "swingUp", "LQRcontroller", "globalState", "y",
  "globalStateOut" };

/* Function Declarations */
static void initialize_c5_penduloInvNoLineal
  (SFc5_penduloInvNoLinealInstanceStruct *chartInstance);
static void initialize_params_c5_penduloInvNoLineal
  (SFc5_penduloInvNoLinealInstanceStruct *chartInstance);
static void enable_c5_penduloInvNoLineal(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance);
static void disable_c5_penduloInvNoLineal(SFc5_penduloInvNoLinealInstanceStruct *
  chartInstance);
static void c5_update_debugger_state_c5_penduloInvNoLineal
  (SFc5_penduloInvNoLinealInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_penduloInvNoLineal
  (SFc5_penduloInvNoLinealInstanceStruct *chartInstance);
static void set_sim_state_c5_penduloInvNoLineal
  (SFc5_penduloInvNoLinealInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_penduloInvNoLineal(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance);
static void sf_c5_penduloInvNoLineal(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance);
static void initSimStructsc5_penduloInvNoLineal
  (SFc5_penduloInvNoLinealInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance, const mxArray *c5_globalStateOut, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_c_emlrt_marshallIn(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_d_emlrt_marshallIn(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_penduloInvNoLineal, const
  char_T *c5_identifier);
static uint8_T c5_e_emlrt_marshallIn(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_penduloInvNoLineal
  (SFc5_penduloInvNoLinealInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_penduloInvNoLineal = 0U;
}

static void initialize_params_c5_penduloInvNoLineal
  (SFc5_penduloInvNoLinealInstanceStruct *chartInstance)
{
}

static void enable_c5_penduloInvNoLineal(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_penduloInvNoLineal(SFc5_penduloInvNoLinealInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_penduloInvNoLineal
  (SFc5_penduloInvNoLinealInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_penduloInvNoLineal
  (SFc5_penduloInvNoLinealInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  uint8_T c5_c_hoistedGlobal;
  uint8_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  real_T *c5_globalStateOut;
  real_T *c5_e_y;
  c5_globalStateOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_e_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(3), FALSE);
  c5_hoistedGlobal = *c5_globalStateOut;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_e_y;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_hoistedGlobal = chartInstance->c5_is_active_c5_penduloInvNoLineal;
  c5_c_u = c5_c_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_penduloInvNoLineal
  (SFc5_penduloInvNoLinealInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_globalStateOut;
  real_T *c5_y;
  c5_globalStateOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  *c5_globalStateOut = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 0)), "globalStateOut");
  *c5_y = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
    "y");
  chartInstance->c5_is_active_c5_penduloInvNoLineal = c5_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 2)),
     "is_active_c5_penduloInvNoLineal");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_penduloInvNoLineal(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_penduloInvNoLineal(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance)
{
}

static void sf_c5_penduloInvNoLineal(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_d_hoistedGlobal;
  real_T c5_e_hoistedGlobal;
  real_T c5_ActualAngle;
  real_T c5_criticalAngle;
  real_T c5_swingUp;
  real_T c5_LQRcontroller;
  real_T c5_globalState;
  uint32_T c5_debug_family_var_map[9];
  real_T c5_nargin = 5.0;
  real_T c5_nargout = 2.0;
  real_T c5_y;
  real_T c5_globalStateOut;
  real_T *c5_b_y;
  real_T *c5_b_ActualAngle;
  real_T *c5_b_criticalAngle;
  real_T *c5_b_swingUp;
  real_T *c5_b_LQRcontroller;
  real_T *c5_b_globalState;
  real_T *c5_b_globalStateOut;
  boolean_T guard1 = FALSE;
  c5_b_globalStateOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_b_globalState = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c5_b_LQRcontroller = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_b_swingUp = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_criticalAngle = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_ActualAngle = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_b_y, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_b_ActualAngle, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_b_criticalAngle, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_b_swingUp, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_b_LQRcontroller, 4U);
  _SFD_DATA_RANGE_CHECK(*c5_b_globalState, 5U);
  _SFD_DATA_RANGE_CHECK(*c5_b_globalStateOut, 6U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_ActualAngle;
  c5_b_hoistedGlobal = *c5_b_criticalAngle;
  c5_c_hoistedGlobal = *c5_b_swingUp;
  c5_d_hoistedGlobal = *c5_b_LQRcontroller;
  c5_e_hoistedGlobal = *c5_b_globalState;
  c5_ActualAngle = c5_hoistedGlobal;
  c5_criticalAngle = c5_b_hoistedGlobal;
  c5_swingUp = c5_c_hoistedGlobal;
  c5_LQRcontroller = c5_d_hoistedGlobal;
  c5_globalState = c5_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_ActualAngle, 2U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_criticalAngle, 3U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_swingUp, 4U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_LQRcontroller, 5U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_globalState, 6U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_y, 7U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_globalStateOut, 8U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c5_ActualAngle < c5_criticalAngle)) {
    if (CV_EML_COND(0, 1, 1, c5_globalState == 0.0)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 0, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
      c5_y = c5_swingUp;
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
      c5_globalStateOut = 0.0;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
    c5_y = c5_LQRcontroller;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
    c5_globalStateOut = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -9);
  sf_debug_symbol_scope_pop();
  *c5_b_y = c5_y;
  *c5_b_globalStateOut = c5_globalStateOut;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  sf_debug_check_for_state_inconsistency(_penduloInvNoLinealMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc5_penduloInvNoLineal
  (SFc5_penduloInvNoLinealInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_penduloInvNoLinealInstanceStruct *chartInstance;
  chartInstance = (SFc5_penduloInvNoLinealInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance, const mxArray *c5_globalStateOut, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_globalStateOut),
    &c5_thisId);
  sf_mex_destroy(&c5_globalStateOut);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_globalStateOut;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_penduloInvNoLinealInstanceStruct *chartInstance;
  chartInstance = (SFc5_penduloInvNoLinealInstanceStruct *)chartInstanceVoid;
  c5_globalStateOut = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_globalStateOut),
    &c5_thisId);
  sf_mex_destroy(&c5_globalStateOut);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_penduloInvNoLineal_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_penduloInvNoLinealInstanceStruct *chartInstance;
  chartInstance = (SFc5_penduloInvNoLinealInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_c_emlrt_marshallIn(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i0, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_penduloInvNoLinealInstanceStruct *chartInstance;
  chartInstance = (SFc5_penduloInvNoLinealInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_d_emlrt_marshallIn(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_penduloInvNoLineal, const
  char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_penduloInvNoLineal), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_penduloInvNoLineal);
  return c5_y;
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_penduloInvNoLinealInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_penduloInvNoLineal_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2205343613U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1742108714U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3926584042U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(308142955U);
}

mxArray *sf_c5_penduloInvNoLineal_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("lB7y7RvN9miSUbdOF4yS6B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c5_penduloInvNoLineal(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[14],T\"globalStateOut\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c5_penduloInvNoLineal\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_penduloInvNoLineal_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_penduloInvNoLinealInstanceStruct *chartInstance;
    chartInstance = (SFc5_penduloInvNoLinealInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_penduloInvNoLinealMachineNumber_,
           5,
           1,
           1,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_penduloInvNoLinealMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_penduloInvNoLinealMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_penduloInvNoLinealMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"y");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ActualAngle");
          _SFD_SET_DATA_PROPS(2,1,1,0,"criticalAngle");
          _SFD_SET_DATA_PROPS(3,1,1,0,"swingUp");
          _SFD_SET_DATA_PROPS(4,1,1,0,"LQRcontroller");
          _SFD_SET_DATA_PROPS(5,1,1,0,"globalState");
          _SFD_SET_DATA_PROPS(6,2,0,1,"globalStateOut");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,378);
        _SFD_CV_INIT_EML_IF(0,1,0,170,222,264,373);

        {
          static int condStart[] = { 174, 205 };

          static int condEnd[] = { 201, 221 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,174,221,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);

        {
          real_T *c5_y;
          real_T *c5_ActualAngle;
          real_T *c5_criticalAngle;
          real_T *c5_swingUp;
          real_T *c5_LQRcontroller;
          real_T *c5_globalState;
          real_T *c5_globalStateOut;
          c5_globalStateOut = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            2);
          c5_globalState = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c5_LQRcontroller = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c5_swingUp = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_criticalAngle = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_ActualAngle = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c5_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_y);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_ActualAngle);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_criticalAngle);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_swingUp);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_LQRcontroller);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_globalState);
          _SFD_SET_DATA_VALUE_PTR(6U, c5_globalStateOut);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_penduloInvNoLinealMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "OfdUtsTaaFeom2Aa9aQREE";
}

static void sf_opaque_initialize_c5_penduloInvNoLineal(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_penduloInvNoLinealInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_penduloInvNoLineal((SFc5_penduloInvNoLinealInstanceStruct*)
    chartInstanceVar);
  initialize_c5_penduloInvNoLineal((SFc5_penduloInvNoLinealInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_penduloInvNoLineal(void *chartInstanceVar)
{
  enable_c5_penduloInvNoLineal((SFc5_penduloInvNoLinealInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_penduloInvNoLineal(void *chartInstanceVar)
{
  disable_c5_penduloInvNoLineal((SFc5_penduloInvNoLinealInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_penduloInvNoLineal(void *chartInstanceVar)
{
  sf_c5_penduloInvNoLineal((SFc5_penduloInvNoLinealInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_penduloInvNoLineal(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_penduloInvNoLineal
    ((SFc5_penduloInvNoLinealInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_penduloInvNoLineal();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c5_penduloInvNoLineal(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_penduloInvNoLineal();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_penduloInvNoLineal((SFc5_penduloInvNoLinealInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_penduloInvNoLineal(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_penduloInvNoLineal(S);
}

static void sf_opaque_set_sim_state_c5_penduloInvNoLineal(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_penduloInvNoLineal(S, st);
}

static void sf_opaque_terminate_c5_penduloInvNoLineal(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_penduloInvNoLinealInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_penduloInvNoLineal((SFc5_penduloInvNoLinealInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_penduloInvNoLineal_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_penduloInvNoLineal((SFc5_penduloInvNoLinealInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_penduloInvNoLineal(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_penduloInvNoLineal
      ((SFc5_penduloInvNoLinealInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_penduloInvNoLineal(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_penduloInvNoLineal_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,2);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(520697875U));
  ssSetChecksum1(S,(2196924568U));
  ssSetChecksum2(S,(180004400U));
  ssSetChecksum3(S,(1596914614U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_penduloInvNoLineal(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_penduloInvNoLineal(SimStruct *S)
{
  SFc5_penduloInvNoLinealInstanceStruct *chartInstance;
  chartInstance = (SFc5_penduloInvNoLinealInstanceStruct *)malloc(sizeof
    (SFc5_penduloInvNoLinealInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_penduloInvNoLinealInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_penduloInvNoLineal;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_penduloInvNoLineal;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_penduloInvNoLineal;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_penduloInvNoLineal;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_penduloInvNoLineal;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_penduloInvNoLineal;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_penduloInvNoLineal;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_penduloInvNoLineal;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_penduloInvNoLineal;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_penduloInvNoLineal;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_penduloInvNoLineal;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c5_penduloInvNoLineal_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_penduloInvNoLineal(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_penduloInvNoLineal(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_penduloInvNoLineal(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_penduloInvNoLineal_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

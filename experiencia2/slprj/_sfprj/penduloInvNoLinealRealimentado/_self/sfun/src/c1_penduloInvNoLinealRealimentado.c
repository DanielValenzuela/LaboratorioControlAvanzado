/* Include files */

#include "blascompat32.h"
#include "penduloInvNoLinealRealimentado_sfun.h"
#include "c1_penduloInvNoLinealRealimentado.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "penduloInvNoLinealRealimentado_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[12] = { "scaleFactor", "fromLow",
  "fromHigh", "toLow", "toHigh", "new_range", "old_range", "new_value", "nargin",
  "nargout", "value", "y" };

/* Function Declarations */
static void initialize_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void initialize_params_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void enable_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void disable_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void set_sim_state_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c1_st);
static void finalize_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void sf_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void initSimStructsc1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c1_y, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_penduloInvNoLinealRealimentado, const char_T
   *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_penduloInvNoLinealRealimentado = 0U;
}

static void initialize_params_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
}

static void enable_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T *c1_d_y;
  c1_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  c1_hoistedGlobal = *c1_d_y;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal =
    chartInstance->c1_is_active_c1_penduloInvNoLinealRealimentado;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_y;
  c1_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "y");
  chartInstance->c1_is_active_c1_penduloInvNoLinealRealimentado =
    c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "is_active_c1_penduloInvNoLinealRealimentado");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_penduloInvNoLinealRealimentado(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
}

static void sf_c1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_value;
  uint32_T c1_debug_family_var_map[12];
  real_T c1_scaleFactor;
  real_T c1_fromLow;
  real_T c1_fromHigh;
  real_T c1_toLow;
  real_T c1_toHigh;
  real_T c1_new_range;
  real_T c1_old_range;
  real_T c1_new_value;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  real_T c1_y;
  real_T c1_b;
  real_T c1_b_y;
  real_T *c1_b_value;
  real_T *c1_c_y;
  c1_c_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_value = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_b_value, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_c_y, 1U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_value;
  c1_value = c1_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 12U, 12U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_scaleFactor, 0U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_fromLow, 1U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_fromHigh, 2U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_toLow, 3U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_toHigh, 4U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_new_range, 5U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_old_range, 6U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_new_value, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_value, 10U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_y, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  c1_scaleFactor = 0.017453292519943295;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  if (CV_EML_IF(0, 1, 0, c1_value > 3.1415926535897931)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
    c1_fromLow = 3.1590459461097367;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
    c1_fromHigh = 6.2831853071795862;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
    c1_toLow = -3.12413936106985;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
    c1_toHigh = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
    c1_new_range = 3.12413936106985;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
    c1_old_range = 3.1241393610698496;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
    c1_b = c1_value - c1_fromLow;
    c1_b_y = 1.0000000000000002 * c1_b;
    c1_new_value = c1_b_y + c1_toLow;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
    c1_y = c1_new_value;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
    c1_y = c1_value;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -15);
  sf_debug_symbol_scope_pop();
  *c1_c_y = c1_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_penduloInvNoLinealRealimentadoMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc1_penduloInvNoLinealRealimentado
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance;
  chartInstance = (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c1_y, const char_T *c1_identifier)
{
  real_T c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId);
  sf_mex_destroy(&c1_y);
  return c1_b_y;
}

static real_T c1_b_emlrt_marshallIn
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y;
  SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance;
  chartInstance = (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *)
    chartInstanceVoid;
  c1_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId);
  sf_mex_destroy(&c1_y);
  *(real_T *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray
  *sf_c1_penduloInvNoLinealRealimentado_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[4];
  c1_ResolvedFunctionInfo (*c1_b_info)[4];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i0;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[4])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mrdivide";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[0].fileTimeLo = 1325138538U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 1319747966U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[1].name = "rdivide";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[1].fileTimeLo = 1286836844U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[2].name = "eml_div";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c1_b_info)[2].fileTimeLo = 1313369410U;
  (*c1_b_info)[2].fileTimeHi = 0U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context = "";
  (*c1_b_info)[3].name = "mtimes";
  (*c1_b_info)[3].dominantType = "double";
  (*c1_b_info)[3].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[3].fileTimeLo = 1289534092U;
  (*c1_b_info)[3].fileTimeHi = 0U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    c1_r0 = &c1_info[c1_i0];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i0);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance;
  chartInstance = (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i1, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance;
  chartInstance = (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_penduloInvNoLinealRealimentado, const char_T
   *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_penduloInvNoLinealRealimentado), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_penduloInvNoLinealRealimentado);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info
  (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_penduloInvNoLinealRealimentado_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2225280468U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3150734823U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2629958684U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2234576739U);
}

mxArray *sf_c1_penduloInvNoLinealRealimentado_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("oU90mQ3XUCEeyPNKoyxTKG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_penduloInvNoLinealRealimentado
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c1_penduloInvNoLinealRealimentado\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_penduloInvNoLinealRealimentado_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance;
    chartInstance = (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_penduloInvNoLinealRealimentadoMachineNumber_,
           1,
           1,
           1,
           2,
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
          init_script_number_translation
            (_penduloInvNoLinealRealimentadoMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_penduloInvNoLinealRealimentadoMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_penduloInvNoLinealRealimentadoMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"value");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,476);
        _SFD_CV_INIT_EML_IF(0,1,0,61,87,432,463);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_value;
          real_T *c1_y;
          c1_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_value = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_value);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_penduloInvNoLinealRealimentadoMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "ka6N2Ig00dVp2MQipnAXJ";
}

static void sf_opaque_initialize_c1_penduloInvNoLinealRealimentado(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_penduloInvNoLinealRealimentadoInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_penduloInvNoLinealRealimentado
    ((SFc1_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
  initialize_c1_penduloInvNoLinealRealimentado
    ((SFc1_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_penduloInvNoLinealRealimentado(void
  *chartInstanceVar)
{
  enable_c1_penduloInvNoLinealRealimentado
    ((SFc1_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_penduloInvNoLinealRealimentado(void
  *chartInstanceVar)
{
  disable_c1_penduloInvNoLinealRealimentado
    ((SFc1_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_penduloInvNoLinealRealimentado(void
  *chartInstanceVar)
{
  sf_c1_penduloInvNoLinealRealimentado
    ((SFc1_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c1_penduloInvNoLinealRealimentado(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_penduloInvNoLinealRealimentado
    ((SFc1_penduloInvNoLinealRealimentadoInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_penduloInvNoLinealRealimentado();/* state var info */
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

extern void sf_internal_set_sim_state_c1_penduloInvNoLinealRealimentado
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_penduloInvNoLinealRealimentado();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_penduloInvNoLinealRealimentado
    ((SFc1_penduloInvNoLinealRealimentadoInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_penduloInvNoLinealRealimentado
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_penduloInvNoLinealRealimentado(S);
}

static void sf_opaque_set_sim_state_c1_penduloInvNoLinealRealimentado(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_penduloInvNoLinealRealimentado(S, st);
}

static void sf_opaque_terminate_c1_penduloInvNoLinealRealimentado(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_penduloInvNoLinealRealimentadoInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_penduloInvNoLinealRealimentado
      ((SFc1_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_penduloInvNoLinealRealimentado_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_penduloInvNoLinealRealimentado
    ((SFc1_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_penduloInvNoLinealRealimentado(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_penduloInvNoLinealRealimentado
      ((SFc1_penduloInvNoLinealRealimentadoInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_penduloInvNoLinealRealimentado(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_penduloInvNoLinealRealimentado_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(780929523U));
  ssSetChecksum1(S,(712635776U));
  ssSetChecksum2(S,(2270358834U));
  ssSetChecksum3(S,(407811466U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_penduloInvNoLinealRealimentado(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_penduloInvNoLinealRealimentado(SimStruct *S)
{
  SFc1_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance;
  chartInstance = (SFc1_penduloInvNoLinealRealimentadoInstanceStruct *)malloc
    (sizeof(SFc1_penduloInvNoLinealRealimentadoInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_penduloInvNoLinealRealimentadoInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_penduloInvNoLinealRealimentado;
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

void c1_penduloInvNoLinealRealimentado_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_penduloInvNoLinealRealimentado(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_penduloInvNoLinealRealimentado(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_penduloInvNoLinealRealimentado(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_penduloInvNoLinealRealimentado_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

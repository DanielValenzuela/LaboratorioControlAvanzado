/* Include files */

#include "blascompat32.h"
#include "IV_actividad2_sfun.h"
#include "c3_IV_actividad2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "IV_actividad2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[5] = { "nargin", "nargout", "f", "hc",
  "dhc_dt" };

/* Function Declarations */
static void initialize_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct
  *chartInstance);
static void initialize_params_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct *
  chartInstance);
static void enable_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct
  *chartInstance);
static void disable_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_IV_actividad2
  (SFc3_IV_actividad2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_IV_actividad2
  (SFc3_IV_actividad2InstanceStruct *chartInstance);
static void set_sim_state_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct
  *chartInstance);
static void sf_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct *chartInstance);
static void initSimStructsc3_IV_actividad2(SFc3_IV_actividad2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_IV_actividad2InstanceStruct
  *chartInstance, const mxArray *c3_dhc_dt, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_IV_actividad2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_eml_error(SFc3_IV_actividad2InstanceStruct *chartInstance);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_IV_actividad2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_d_emlrt_marshallIn(SFc3_IV_actividad2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_IV_actividad2, const char_T
  *c3_identifier);
static uint8_T c3_e_emlrt_marshallIn(SFc3_IV_actividad2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_IV_actividad2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_IV_actividad2 = 0U;
}

static void initialize_params_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct *
  chartInstance)
{
}

static void enable_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_IV_actividad2
  (SFc3_IV_actividad2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_IV_actividad2
  (SFc3_IV_actividad2InstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T *c3_dhc_dt;
  c3_dhc_dt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  c3_hoistedGlobal = *c3_dhc_dt;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_active_c3_IV_actividad2;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_dhc_dt;
  c3_dhc_dt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_dhc_dt = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    0)), "dhc_dt");
  chartInstance->c3_is_active_c3_IV_actividad2 = c3_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
     "is_active_c3_IV_actividad2");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_IV_actividad2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct
  *chartInstance)
{
}

static void sf_c3_IV_actividad2(SFc3_IV_actividad2InstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_f;
  real_T c3_hc;
  uint32_T c3_debug_family_var_map[5];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  real_T c3_dhc_dt;
  real_T c3_b;
  real_T c3_y;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_b_b;
  real_T c3_b_y;
  real_T c3_a;
  real_T c3_ak;
  real_T c3_c_y;
  real_T c3_c_b;
  real_T c3_d_y;
  real_T c3_d_b;
  real_T c3_e_y;
  real_T c3_A;
  real_T c3_B;
  real_T c3_c_x;
  real_T c3_f_y;
  real_T c3_d_x;
  real_T c3_g_y;
  real_T *c3_b_hc;
  real_T *c3_b_f;
  real_T *c3_b_dhc_dt;
  c3_b_hc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_dhc_dt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_b_f, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_b_dhc_dt, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_b_hc, 2U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_f;
  c3_b_hoistedGlobal = *c3_b_hc;
  c3_f = c3_hoistedGlobal;
  c3_hc = c3_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_f, 2U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_hc, 3U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_dhc_dt, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_b = c3_f;
  c3_y = 5.43 * c3_b;
  c3_x = c3_hc;
  c3_b_x = c3_x;
  if (c3_b_x < 0.0) {
    c3_eml_error(chartInstance);
  }

  c3_b_x = muDoubleScalarSqrt(c3_b_x);
  c3_b_b = c3_b_x;
  c3_b_y = 20.21 * c3_b_b;
  c3_a = c3_hc;
  c3_ak = c3_a;
  c3_c_y = muDoubleScalarPower(c3_ak, 2.0);
  c3_c_b = c3_c_y;
  c3_d_y = 0.63 * c3_c_b;
  c3_d_b = c3_hc;
  c3_e_y = 11.4 * c3_d_b;
  c3_A = (c3_y - 78.43) - c3_b_y;
  c3_B = (c3_d_y + c3_e_y) + 17.1;
  c3_c_x = c3_A;
  c3_f_y = c3_B;
  c3_d_x = c3_c_x;
  c3_g_y = c3_f_y;
  c3_dhc_dt = c3_d_x / c3_g_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  *c3_b_dhc_dt = c3_dhc_dt;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  sf_debug_check_for_state_inconsistency(_IV_actividad2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_IV_actividad2(SFc3_IV_actividad2InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_IV_actividad2InstanceStruct *chartInstance;
  chartInstance = (SFc3_IV_actividad2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_IV_actividad2InstanceStruct
  *chartInstance, const mxArray *c3_dhc_dt, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_dhc_dt), &c3_thisId);
  sf_mex_destroy(&c3_dhc_dt);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_IV_actividad2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_dhc_dt;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_IV_actividad2InstanceStruct *chartInstance;
  chartInstance = (SFc3_IV_actividad2InstanceStruct *)chartInstanceVoid;
  c3_dhc_dt = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_dhc_dt), &c3_thisId);
  sf_mex_destroy(&c3_dhc_dt);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_IV_actividad2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[11];
  c3_ResolvedFunctionInfo (*c3_b_info)[11];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i0;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_b_info = (c3_ResolvedFunctionInfo (*)[11])c3_info;
  (*c3_b_info)[0].context = "";
  (*c3_b_info)[0].name = "mtimes";
  (*c3_b_info)[0].dominantType = "double";
  (*c3_b_info)[0].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[0].fileTimeLo = 1289534092U;
  (*c3_b_info)[0].fileTimeHi = 0U;
  (*c3_b_info)[0].mFileTimeLo = 0U;
  (*c3_b_info)[0].mFileTimeHi = 0U;
  (*c3_b_info)[1].context = "";
  (*c3_b_info)[1].name = "sqrt";
  (*c3_b_info)[1].dominantType = "double";
  (*c3_b_info)[1].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c3_b_info)[1].fileTimeLo = 1286836752U;
  (*c3_b_info)[1].fileTimeHi = 0U;
  (*c3_b_info)[1].mFileTimeLo = 0U;
  (*c3_b_info)[1].mFileTimeHi = 0U;
  (*c3_b_info)[2].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c3_b_info)[2].name = "eml_error";
  (*c3_b_info)[2].dominantType = "char";
  (*c3_b_info)[2].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c3_b_info)[2].fileTimeLo = 1305339600U;
  (*c3_b_info)[2].fileTimeHi = 0U;
  (*c3_b_info)[2].mFileTimeLo = 0U;
  (*c3_b_info)[2].mFileTimeHi = 0U;
  (*c3_b_info)[3].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c3_b_info)[3].name = "eml_scalar_sqrt";
  (*c3_b_info)[3].dominantType = "double";
  (*c3_b_info)[3].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  (*c3_b_info)[3].fileTimeLo = 1286836738U;
  (*c3_b_info)[3].fileTimeHi = 0U;
  (*c3_b_info)[3].mFileTimeLo = 0U;
  (*c3_b_info)[3].mFileTimeHi = 0U;
  (*c3_b_info)[4].context = "";
  (*c3_b_info)[4].name = "power";
  (*c3_b_info)[4].dominantType = "double";
  (*c3_b_info)[4].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c3_b_info)[4].fileTimeLo = 1307672840U;
  (*c3_b_info)[4].fileTimeHi = 0U;
  (*c3_b_info)[4].mFileTimeLo = 0U;
  (*c3_b_info)[4].mFileTimeHi = 0U;
  (*c3_b_info)[5].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c3_b_info)[5].name = "eml_scalar_eg";
  (*c3_b_info)[5].dominantType = "double";
  (*c3_b_info)[5].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c3_b_info)[5].fileTimeLo = 1286836796U;
  (*c3_b_info)[5].fileTimeHi = 0U;
  (*c3_b_info)[5].mFileTimeLo = 0U;
  (*c3_b_info)[5].mFileTimeHi = 0U;
  (*c3_b_info)[6].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c3_b_info)[6].name = "eml_scalexp_alloc";
  (*c3_b_info)[6].dominantType = "double";
  (*c3_b_info)[6].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c3_b_info)[6].fileTimeLo = 1286836796U;
  (*c3_b_info)[6].fileTimeHi = 0U;
  (*c3_b_info)[6].mFileTimeLo = 0U;
  (*c3_b_info)[6].mFileTimeHi = 0U;
  (*c3_b_info)[7].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c3_b_info)[7].name = "eml_scalar_floor";
  (*c3_b_info)[7].dominantType = "double";
  (*c3_b_info)[7].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c3_b_info)[7].fileTimeLo = 1286836726U;
  (*c3_b_info)[7].fileTimeHi = 0U;
  (*c3_b_info)[7].mFileTimeLo = 0U;
  (*c3_b_info)[7].mFileTimeHi = 0U;
  (*c3_b_info)[8].context = "";
  (*c3_b_info)[8].name = "mrdivide";
  (*c3_b_info)[8].dominantType = "double";
  (*c3_b_info)[8].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c3_b_info)[8].fileTimeLo = 1325138538U;
  (*c3_b_info)[8].fileTimeHi = 0U;
  (*c3_b_info)[8].mFileTimeLo = 1319747966U;
  (*c3_b_info)[8].mFileTimeHi = 0U;
  (*c3_b_info)[9].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c3_b_info)[9].name = "rdivide";
  (*c3_b_info)[9].dominantType = "double";
  (*c3_b_info)[9].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c3_b_info)[9].fileTimeLo = 1286836844U;
  (*c3_b_info)[9].fileTimeHi = 0U;
  (*c3_b_info)[9].mFileTimeLo = 0U;
  (*c3_b_info)[9].mFileTimeHi = 0U;
  (*c3_b_info)[10].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c3_b_info)[10].name = "eml_div";
  (*c3_b_info)[10].dominantType = "double";
  (*c3_b_info)[10].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c3_b_info)[10].fileTimeLo = 1313369410U;
  (*c3_b_info)[10].fileTimeHi = 0U;
  (*c3_b_info)[10].mFileTimeLo = 0U;
  (*c3_b_info)[10].mFileTimeHi = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 11), FALSE);
  for (c3_i0 = 0; c3_i0 < 11; c3_i0++) {
    c3_r0 = &c3_info[c3_i0];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i0);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_eml_error(SFc3_IV_actividad2InstanceStruct *chartInstance)
{
  int32_T c3_i1;
  static char_T c3_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  for (c3_i1 = 0; c3_i1 < 30; c3_i1++) {
    c3_u[c3_i1] = c3_varargin_1[c3_i1];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c3_y));
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_IV_actividad2InstanceStruct *chartInstance;
  chartInstance = (SFc3_IV_actividad2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_IV_actividad2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i2;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i2, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_IV_actividad2InstanceStruct *chartInstance;
  chartInstance = (SFc3_IV_actividad2InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_IV_actividad2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_IV_actividad2, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_IV_actividad2), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_IV_actividad2);
  return c3_y;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_IV_actividad2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_IV_actividad2InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_IV_actividad2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(686338377U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1997760719U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(379903781U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4102038396U);
}

mxArray *sf_c3_IV_actividad2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("pd3K2Rez4KBD4oz7zYuNhE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

static const mxArray *sf_get_sim_state_info_c3_IV_actividad2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"dhc_dt\",},{M[8],M[0],T\"is_active_c3_IV_actividad2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_IV_actividad2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_IV_actividad2InstanceStruct *chartInstance;
    chartInstance = (SFc3_IV_actividad2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_IV_actividad2MachineNumber_,
           3,
           1,
           1,
           3,
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
          init_script_number_translation(_IV_actividad2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_IV_actividad2MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_IV_actividad2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"f");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dhc_dt");
          _SFD_SET_DATA_PROPS(2,1,1,0,"hc");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,126);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c3_f;
          real_T *c3_dhc_dt;
          real_T *c3_hc;
          c3_hc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_dhc_dt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_f);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_dhc_dt);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_hc);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_IV_actividad2MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "SqSs4kPwtnYVJIG1LYNyGB";
}

static void sf_opaque_initialize_c3_IV_actividad2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_IV_actividad2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_IV_actividad2((SFc3_IV_actividad2InstanceStruct*)
    chartInstanceVar);
  initialize_c3_IV_actividad2((SFc3_IV_actividad2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_IV_actividad2(void *chartInstanceVar)
{
  enable_c3_IV_actividad2((SFc3_IV_actividad2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_IV_actividad2(void *chartInstanceVar)
{
  disable_c3_IV_actividad2((SFc3_IV_actividad2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_IV_actividad2(void *chartInstanceVar)
{
  sf_c3_IV_actividad2((SFc3_IV_actividad2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_IV_actividad2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_IV_actividad2
    ((SFc3_IV_actividad2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_IV_actividad2();/* state var info */
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

extern void sf_internal_set_sim_state_c3_IV_actividad2(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_IV_actividad2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_IV_actividad2((SFc3_IV_actividad2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_IV_actividad2(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_IV_actividad2(S);
}

static void sf_opaque_set_sim_state_c3_IV_actividad2(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_IV_actividad2(S, st);
}

static void sf_opaque_terminate_c3_IV_actividad2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_IV_actividad2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_IV_actividad2((SFc3_IV_actividad2InstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_IV_actividad2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_IV_actividad2((SFc3_IV_actividad2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_IV_actividad2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_IV_actividad2((SFc3_IV_actividad2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_IV_actividad2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_IV_actividad2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2653594351U));
  ssSetChecksum1(S,(1483376856U));
  ssSetChecksum2(S,(2455662043U));
  ssSetChecksum3(S,(1074729485U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_IV_actividad2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_IV_actividad2(SimStruct *S)
{
  SFc3_IV_actividad2InstanceStruct *chartInstance;
  chartInstance = (SFc3_IV_actividad2InstanceStruct *)malloc(sizeof
    (SFc3_IV_actividad2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_IV_actividad2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_IV_actividad2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_IV_actividad2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_IV_actividad2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_IV_actividad2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_IV_actividad2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_IV_actividad2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_IV_actividad2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_IV_actividad2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_IV_actividad2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_IV_actividad2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_IV_actividad2;
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

void c3_IV_actividad2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_IV_actividad2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_IV_actividad2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_IV_actividad2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_IV_actividad2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

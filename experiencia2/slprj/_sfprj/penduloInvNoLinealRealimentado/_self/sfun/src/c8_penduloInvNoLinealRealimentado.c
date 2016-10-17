/* Include files */

#include "blascompat32.h"
#include "penduloInvNoLinealRealimentado_sfun.h"
#include "c8_penduloInvNoLinealRealimentado.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "penduloInvNoLinealRealimentado_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c8_debug_family_names[4] = { "nargin", "nargout", "u", "y" };

/* Function Declarations */
static void initialize_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void initialize_params_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void enable_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void disable_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void set_sim_state_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c8_st);
static void finalize_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void sf_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void initSimStructsc8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static real_T c8_emlrt_marshallIn
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c8_y, const char_T *c8_identifier);
static real_T c8_b_emlrt_marshallIn
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[14]);
static void c8_eml_scalar_eg(SFc8_penduloInvNoLinealRealimentadoInstanceStruct
  *chartInstance);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_c_emlrt_marshallIn
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_d_emlrt_marshallIn
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c8_b_is_active_c8_penduloInvNoLinealRealimentado, const char_T
   *c8_identifier);
static uint8_T c8_e_emlrt_marshallIn
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_penduloInvNoLinealRealimentado = 0U;
}

static void initialize_params_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
}

static void enable_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  real_T c8_hoistedGlobal;
  real_T c8_u;
  const mxArray *c8_b_y = NULL;
  uint8_T c8_b_hoistedGlobal;
  uint8_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T *c8_d_y;
  c8_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(2), FALSE);
  c8_hoistedGlobal = *c8_d_y;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal =
    chartInstance->c8_is_active_c8_penduloInvNoLinealRealimentado;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c8_st)
{
  const mxArray *c8_u;
  real_T *c8_y;
  c8_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  *c8_y = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)),
    "y");
  chartInstance->c8_is_active_c8_penduloInvNoLinealRealimentado =
    c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
    "is_active_c8_penduloInvNoLinealRealimentado");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_penduloInvNoLinealRealimentado(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
}

static void sf_c8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
  real_T c8_hoistedGlobal;
  real_T c8_u;
  uint32_T c8_debug_family_var_map[4];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real_T c8_y;
  real_T c8_x;
  real_T c8_xk;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_d_x;
  real_T c8_e_x;
  real_T c8_f_x;
  real_T c8_b_y;
  real_T c8_g_x;
  real_T c8_c_y;
  real_T c8_b;
  real_T c8_d_y;
  real_T c8_h_x;
  real_T c8_i_x;
  real_T *c8_b_u;
  real_T *c8_e_y;
  c8_e_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c8_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c8_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c8_e_y, 1U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c8_sfEvent);
  c8_hoistedGlobal = *c8_b_u;
  c8_u = c8_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c8_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 0U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 1U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c8_u, 2U, c8_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c8_y, 3U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_x = c8_u;
  c8_eml_scalar_eg(chartInstance);
  c8_xk = c8_x;
  c8_b_x = c8_xk;
  c8_c_x = c8_b_x;
  c8_eml_scalar_eg(chartInstance);
  c8_y = c8_c_x / 6.2831853071795862;
  c8_d_x = c8_y;
  c8_e_x = c8_d_x;
  c8_e_x = muDoubleScalarRound(c8_e_x);
  c8_f_x = c8_y - c8_e_x;
  c8_b_y = muDoubleScalarAbs(c8_f_x);
  c8_g_x = c8_y;
  c8_c_y = muDoubleScalarAbs(c8_g_x);
  c8_b = c8_c_y;
  c8_d_y = 2.2204460492503131E-16 * c8_b;
  if (c8_b_y <= c8_d_y) {
    c8_y = 0.0;
  } else {
    c8_h_x = c8_y;
    c8_i_x = c8_h_x;
    c8_i_x = muDoubleScalarFloor(c8_i_x);
    c8_y = (c8_y - c8_i_x) * 6.2831853071795862;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  *c8_e_y = c8_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c8_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_penduloInvNoLinealRealimentadoMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc8_penduloInvNoLinealRealimentado
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance;
  chartInstance = (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_emlrt_marshallIn
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c8_y, const char_T *c8_identifier)
{
  real_T c8_b_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_y), &c8_thisId);
  sf_mex_destroy(&c8_y);
  return c8_b_y;
}

static real_T c8_b_emlrt_marshallIn
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_y;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_b_y;
  SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance;
  chartInstance = (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *)
    chartInstanceVoid;
  c8_y = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_y), &c8_thisId);
  sf_mex_destroy(&c8_y);
  *(real_T *)c8_outData = c8_b_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray
  *sf_c8_penduloInvNoLinealRealimentado_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[14];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i0;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c8_i0 = 0; c8_i0 < 14; c8_i0++) {
    c8_r0 = &c8_info[c8_i0];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i0);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[14])
{
  c8_info[0].context = "";
  c8_info[0].name = "mtimes";
  c8_info[0].dominantType = "double";
  c8_info[0].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[0].fileTimeLo = 1289534092U;
  c8_info[0].fileTimeHi = 0U;
  c8_info[0].mFileTimeLo = 0U;
  c8_info[0].mFileTimeHi = 0U;
  c8_info[1].context = "";
  c8_info[1].name = "mod";
  c8_info[1].dominantType = "double";
  c8_info[1].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c8_info[1].fileTimeLo = 1286836744U;
  c8_info[1].fileTimeHi = 0U;
  c8_info[1].mFileTimeLo = 0U;
  c8_info[1].mFileTimeHi = 0U;
  c8_info[2].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c8_info[2].name = "eml_scalar_eg";
  c8_info[2].dominantType = "double";
  c8_info[2].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[2].fileTimeLo = 1286836796U;
  c8_info[2].fileTimeHi = 0U;
  c8_info[2].mFileTimeLo = 0U;
  c8_info[2].mFileTimeHi = 0U;
  c8_info[3].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c8_info[3].name = "eml_scalexp_alloc";
  c8_info[3].dominantType = "double";
  c8_info[3].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[3].fileTimeLo = 1286836796U;
  c8_info[3].fileTimeHi = 0U;
  c8_info[3].mFileTimeLo = 0U;
  c8_info[3].mFileTimeHi = 0U;
  c8_info[4].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c8_info[4].name = "eml_scalar_mod";
  c8_info[4].dominantType = "double";
  c8_info[4].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c8_info[4].fileTimeLo = 1307672838U;
  c8_info[4].fileTimeHi = 0U;
  c8_info[4].mFileTimeLo = 0U;
  c8_info[4].mFileTimeHi = 0U;
  c8_info[5].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c8_info[5].name = "eml_scalar_eg";
  c8_info[5].dominantType = "double";
  c8_info[5].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[5].fileTimeLo = 1286836796U;
  c8_info[5].fileTimeHi = 0U;
  c8_info[5].mFileTimeLo = 0U;
  c8_info[5].mFileTimeHi = 0U;
  c8_info[6].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c8_info[6].name = "eml_scalar_floor";
  c8_info[6].dominantType = "double";
  c8_info[6].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c8_info[6].fileTimeLo = 1286836726U;
  c8_info[6].fileTimeHi = 0U;
  c8_info[6].mFileTimeLo = 0U;
  c8_info[6].mFileTimeHi = 0U;
  c8_info[7].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c8_info[7].name = "eml_scalar_round";
  c8_info[7].dominantType = "double";
  c8_info[7].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c8_info[7].fileTimeLo = 1307672838U;
  c8_info[7].fileTimeHi = 0U;
  c8_info[7].mFileTimeLo = 0U;
  c8_info[7].mFileTimeHi = 0U;
  c8_info[8].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c8_info[8].name = "eml_scalar_abs";
  c8_info[8].dominantType = "double";
  c8_info[8].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[8].fileTimeLo = 1286836712U;
  c8_info[8].fileTimeHi = 0U;
  c8_info[8].mFileTimeLo = 0U;
  c8_info[8].mFileTimeHi = 0U;
  c8_info[9].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c8_info[9].name = "eps";
  c8_info[9].dominantType = "char";
  c8_info[9].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[9].fileTimeLo = 1307672840U;
  c8_info[9].fileTimeHi = 0U;
  c8_info[9].mFileTimeLo = 0U;
  c8_info[9].mFileTimeHi = 0U;
  c8_info[10].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[10].name = "eml_is_float_class";
  c8_info[10].dominantType = "char";
  c8_info[10].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c8_info[10].fileTimeLo = 1286836782U;
  c8_info[10].fileTimeHi = 0U;
  c8_info[10].mFileTimeLo = 0U;
  c8_info[10].mFileTimeHi = 0U;
  c8_info[11].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[11].name = "eml_eps";
  c8_info[11].dominantType = "char";
  c8_info[11].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c8_info[11].fileTimeLo = 1307672840U;
  c8_info[11].fileTimeHi = 0U;
  c8_info[11].mFileTimeLo = 0U;
  c8_info[11].mFileTimeHi = 0U;
  c8_info[12].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c8_info[12].name = "eml_float_model";
  c8_info[12].dominantType = "char";
  c8_info[12].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c8_info[12].fileTimeLo = 1307672842U;
  c8_info[12].fileTimeHi = 0U;
  c8_info[12].mFileTimeLo = 0U;
  c8_info[12].mFileTimeHi = 0U;
  c8_info[13].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c8_info[13].name = "mtimes";
  c8_info[13].dominantType = "double";
  c8_info[13].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[13].fileTimeLo = 1289534092U;
  c8_info[13].fileTimeHi = 0U;
  c8_info[13].mFileTimeLo = 0U;
  c8_info[13].mFileTimeHi = 0U;
}

static void c8_eml_scalar_eg(SFc8_penduloInvNoLinealRealimentadoInstanceStruct
  *chartInstance)
{
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance;
  chartInstance = (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static int32_T c8_c_emlrt_marshallIn
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i1;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i1, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i1;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance;
  chartInstance = (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *)
    chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_d_emlrt_marshallIn
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c8_b_is_active_c8_penduloInvNoLinealRealimentado, const char_T
   *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_penduloInvNoLinealRealimentado), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_penduloInvNoLinealRealimentado);
  return c8_y;
}

static uint8_T c8_e_emlrt_marshallIn
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance, const
   mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info
  (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_penduloInvNoLinealRealimentado_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3383985625U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1722358053U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(141825159U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1787565699U);
}

mxArray *sf_c8_penduloInvNoLinealRealimentado_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("8h5qeC16BbqADpp5fotfWF");
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

static const mxArray *sf_get_sim_state_info_c8_penduloInvNoLinealRealimentado
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c8_penduloInvNoLinealRealimentado\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_penduloInvNoLinealRealimentado_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance;
    chartInstance = (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_penduloInvNoLinealRealimentadoMachineNumber_,
           8,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,55);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);

        {
          real_T *c8_u;
          real_T *c8_y;
          c8_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c8_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_y);
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
  return "5SI7ol3GkO8pKfUKud2WGH";
}

static void sf_opaque_initialize_c8_penduloInvNoLinealRealimentado(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_penduloInvNoLinealRealimentadoInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_penduloInvNoLinealRealimentado
    ((SFc8_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
  initialize_c8_penduloInvNoLinealRealimentado
    ((SFc8_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_penduloInvNoLinealRealimentado(void
  *chartInstanceVar)
{
  enable_c8_penduloInvNoLinealRealimentado
    ((SFc8_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_penduloInvNoLinealRealimentado(void
  *chartInstanceVar)
{
  disable_c8_penduloInvNoLinealRealimentado
    ((SFc8_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_penduloInvNoLinealRealimentado(void
  *chartInstanceVar)
{
  sf_c8_penduloInvNoLinealRealimentado
    ((SFc8_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c8_penduloInvNoLinealRealimentado(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_penduloInvNoLinealRealimentado
    ((SFc8_penduloInvNoLinealRealimentadoInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_penduloInvNoLinealRealimentado();/* state var info */
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

extern void sf_internal_set_sim_state_c8_penduloInvNoLinealRealimentado
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_penduloInvNoLinealRealimentado();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_penduloInvNoLinealRealimentado
    ((SFc8_penduloInvNoLinealRealimentadoInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_penduloInvNoLinealRealimentado
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c8_penduloInvNoLinealRealimentado(S);
}

static void sf_opaque_set_sim_state_c8_penduloInvNoLinealRealimentado(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c8_penduloInvNoLinealRealimentado(S, st);
}

static void sf_opaque_terminate_c8_penduloInvNoLinealRealimentado(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_penduloInvNoLinealRealimentadoInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_penduloInvNoLinealRealimentado
      ((SFc8_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_penduloInvNoLinealRealimentado_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_penduloInvNoLinealRealimentado
    ((SFc8_penduloInvNoLinealRealimentadoInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_penduloInvNoLinealRealimentado(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_penduloInvNoLinealRealimentado
      ((SFc8_penduloInvNoLinealRealimentadoInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_penduloInvNoLinealRealimentado(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_penduloInvNoLinealRealimentado_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(34406424U));
  ssSetChecksum1(S,(1292417676U));
  ssSetChecksum2(S,(1301575784U));
  ssSetChecksum3(S,(2156464291U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_penduloInvNoLinealRealimentado(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_penduloInvNoLinealRealimentado(SimStruct *S)
{
  SFc8_penduloInvNoLinealRealimentadoInstanceStruct *chartInstance;
  chartInstance = (SFc8_penduloInvNoLinealRealimentadoInstanceStruct *)malloc
    (sizeof(SFc8_penduloInvNoLinealRealimentadoInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc8_penduloInvNoLinealRealimentadoInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_penduloInvNoLinealRealimentado;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_penduloInvNoLinealRealimentado;
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

void c8_penduloInvNoLinealRealimentado_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_penduloInvNoLinealRealimentado(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_penduloInvNoLinealRealimentado(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_penduloInvNoLinealRealimentado(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_penduloInvNoLinealRealimentado_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

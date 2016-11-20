/* Include files */

#include "blascompat32.h"
#include "modeloNoLinealEcuaciones_sfun.h"
#include "c2_modeloNoLinealEcuaciones.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "modeloNoLinealEcuaciones_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[19] = { "g", "M", "m", "l", "b", "I",
  "numerador", "denominador", "nargin", "nargout", "u", "x1", "x2", "x3", "x4",
  "phi1", "phi2", "phi3", "phi4" };

/* Function Declarations */
static void initialize_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance);
static void initialize_params_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance);
static void enable_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance);
static void disable_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance);
static void set_sim_state_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance);
static void sf_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance);
static void c2_chartstep_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance);
static void initSimStructsc2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_modeloNoLinealEcuacionesInstanceStruct
  *chartInstance, const mxArray *c2_phi4, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_modeloNoLinealEcuacionesInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[15]);
static real_T c2_power(SFc2_modeloNoLinealEcuacionesInstanceStruct
  *chartInstance, real_T c2_a);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_modeloNoLinealEcuacionesInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_modeloNoLinealEcuacionesInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_modeloNoLinealEcuaciones,
  const char_T *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_modeloNoLinealEcuacionesInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_modeloNoLinealEcuacionesInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_modeloNoLinealEcuaciones = 0U;
}

static void initialize_params_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance)
{
}

static void enable_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T *c2_phi1;
  real_T *c2_phi2;
  real_T *c2_phi3;
  real_T *c2_phi4;
  c2_phi4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_phi3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_phi2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_phi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(5), FALSE);
  c2_hoistedGlobal = *c2_phi1;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_phi2;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_phi3;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *c2_phi4;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_is_active_c2_modeloNoLinealEcuaciones;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_phi1;
  real_T *c2_phi2;
  real_T *c2_phi3;
  real_T *c2_phi4;
  c2_phi4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_phi3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_phi2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_phi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_phi1 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    0)), "phi1");
  *c2_phi2 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    1)), "phi2");
  *c2_phi3 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    2)), "phi3");
  *c2_phi4 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    3)), "phi4");
  chartInstance->c2_is_active_c2_modeloNoLinealEcuaciones =
    c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
    "is_active_c2_modeloNoLinealEcuaciones");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_modeloNoLinealEcuaciones(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance)
{
}

static void sf_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance)
{
  real_T *c2_u;
  real_T *c2_x1;
  real_T *c2_x2;
  real_T *c2_x3;
  real_T *c2_x4;
  real_T *c2_phi1;
  real_T *c2_phi2;
  real_T *c2_phi3;
  real_T *c2_phi4;
  c2_phi4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_phi3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_phi2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_phi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_x4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_x3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_x2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_x1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_x1, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_x2, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_x3, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_x4, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_phi1, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_phi2, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_phi3, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_phi4, 8U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_modeloNoLinealEcuaciones(chartInstance);
  sf_debug_check_for_state_inconsistency(_modeloNoLinealEcuacionesMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_u;
  real_T c2_x1;
  real_T c2_x2;
  real_T c2_x3;
  real_T c2_x4;
  uint32_T c2_debug_family_var_map[19];
  real_T c2_g;
  real_T c2_M;
  real_T c2_m;
  real_T c2_l;
  real_T c2_b;
  real_T c2_I;
  real_T c2_numerador;
  real_T c2_denominador;
  real_T c2_nargin = 5.0;
  real_T c2_nargout = 4.0;
  real_T c2_phi1;
  real_T c2_phi2;
  real_T c2_phi3;
  real_T c2_phi4;
  real_T c2_b_b;
  real_T c2_y;
  real_T c2_c_b;
  real_T c2_b_y;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_d_b;
  real_T c2_c_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_d_y;
  real_T c2_j_x;
  real_T c2_e_y;
  real_T c2_z;
  real_T c2_e_b;
  real_T c2_f_y;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_f_b;
  real_T c2_g_y;
  real_T c2_m_x;
  real_T c2_h_y;
  real_T c2_n_x;
  real_T c2_i_y;
  real_T c2_b_z;
  real_T c2_a;
  real_T c2_j_y;
  real_T c2_b_a;
  real_T c2_k_y;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T *c2_b_phi4;
  real_T *c2_b_phi3;
  real_T *c2_b_phi2;
  real_T *c2_b_phi1;
  real_T *c2_b_x4;
  real_T *c2_b_x3;
  real_T *c2_b_x2;
  real_T *c2_b_x1;
  real_T *c2_b_u;
  c2_b_phi4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_phi3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_phi2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_phi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_x4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_x3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_x2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_x1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_u;
  c2_b_hoistedGlobal = *c2_b_x1;
  c2_c_hoistedGlobal = *c2_b_x2;
  c2_d_hoistedGlobal = *c2_b_x3;
  c2_e_hoistedGlobal = *c2_b_x4;
  c2_u = c2_hoistedGlobal;
  c2_x1 = c2_b_hoistedGlobal;
  c2_x2 = c2_c_hoistedGlobal;
  c2_x3 = c2_d_hoistedGlobal;
  c2_x4 = c2_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 19U, 19U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_g, 0U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_M, 1U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_m, 2U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_l, 3U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_b, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_I, 5U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_numerador, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_denominador, 7U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_u, 10U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_x1, 11U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_x2, 12U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_x3, 13U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_x4, 14U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_phi1, 15U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_phi2, 16U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_phi3, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_phi4, 18U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_g = 9.81;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_M = 0.768;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_m = 0.104;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_l = 0.3213;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_b = 0.05;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_I = 0.0138;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_phi1 = c2_x3;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_phi2 = c2_x4;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_b_b = c2_u;
  c2_y = 1.88 * c2_b_b;
  c2_c_b = c2_power(chartInstance, c2_x4);
  c2_b_y = 0.0334152 * c2_c_b;
  c2_x = c2_x2;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarSin(c2_b_x);
  c2_c_x = c2_x2;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarTan(c2_d_x);
  c2_d_b = c2_d_x;
  c2_c_y = 8.55432 * c2_d_b;
  c2_numerador = (((c2_y - 4.7) + c2_b_y * c2_b_x) - (c2_b + 0.548) * c2_x3) +
    c2_c_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_e_x = c2_x2;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarCos(c2_f_x);
  c2_g_x = c2_x2;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarCos(c2_h_x);
  c2_denominador = 0.021395656878719995 - 0.0011165755910399998 * (c2_f_x *
    c2_h_x);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_i_x = c2_numerador;
  c2_d_y = c2_denominador;
  c2_j_x = c2_i_x;
  c2_e_y = c2_d_y;
  c2_z = c2_j_x / c2_e_y;
  c2_e_b = c2_z;
  c2_f_y = 0.024536303759999996 * c2_e_b;
  c2_k_x = c2_x2;
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarTan(c2_l_x);
  c2_f_b = c2_l_x;
  c2_g_y = 9.81 * c2_f_b;
  c2_phi3 = c2_f_y - c2_g_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_m_x = c2_numerador;
  c2_h_y = c2_denominador;
  c2_n_x = c2_m_x;
  c2_i_y = c2_h_y;
  c2_b_z = c2_n_x / c2_i_y;
  c2_a = -c2_b_z;
  c2_j_y = c2_a * 0.104;
  c2_b_a = c2_j_y;
  c2_k_y = c2_b_a * 0.3213;
  c2_o_x = c2_x2;
  c2_p_x = c2_o_x;
  c2_p_x = muDoubleScalarCos(c2_p_x);
  c2_phi4 = c2_k_y * c2_p_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -19);
  sf_debug_symbol_scope_pop();
  *c2_b_phi1 = c2_phi1;
  *c2_b_phi2 = c2_phi2;
  *c2_b_phi3 = c2_phi3;
  *c2_b_phi4 = c2_phi4;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_modeloNoLinealEcuaciones
  (SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance;
  chartInstance = (SFc2_modeloNoLinealEcuacionesInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_modeloNoLinealEcuacionesInstanceStruct
  *chartInstance, const mxArray *c2_phi4, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_phi4), &c2_thisId);
  sf_mex_destroy(&c2_phi4);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_modeloNoLinealEcuacionesInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_phi4;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance;
  chartInstance = (SFc2_modeloNoLinealEcuacionesInstanceStruct *)
    chartInstanceVoid;
  c2_phi4 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_phi4), &c2_thisId);
  sf_mex_destroy(&c2_phi4);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_modeloNoLinealEcuaciones_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[15];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 15), FALSE);
  for (c2_i0 = 0; c2_i0 < 15; c2_i0++) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[15])
{
  c2_info[0].context = "";
  c2_info[0].name = "mtimes";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[0].fileTimeLo = 1289534092U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "power";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[1].fileTimeLo = 1307672840U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[2].name = "eml_scalar_eg";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[2].fileTimeLo = 1286836796U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[3].name = "eml_scalexp_alloc";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[3].fileTimeLo = 1286836796U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[4].name = "eml_scalar_floor";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[4].fileTimeLo = 1286836726U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "";
  c2_info[5].name = "sin";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[5].fileTimeLo = 1286836750U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[6].name = "eml_scalar_sin";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[6].fileTimeLo = 1286836736U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "";
  c2_info[7].name = "tan";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/tan.m";
  c2_info[7].fileTimeLo = 1286836752U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/tan.m";
  c2_info[8].name = "eml_scalar_tan";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_tan.m";
  c2_info[8].fileTimeLo = 1286836738U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "";
  c2_info[9].name = "mpower";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[9].fileTimeLo = 1286836842U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[10].name = "power";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[10].fileTimeLo = 1307672840U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "";
  c2_info[11].name = "cos";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[11].fileTimeLo = 1286836706U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[12].name = "eml_scalar_cos";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[12].fileTimeLo = 1286836722U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "";
  c2_info[13].name = "rdivide";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[13].fileTimeLo = 1286836844U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[14].name = "eml_div";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[14].fileTimeLo = 1313369410U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
}

static real_T c2_power(SFc2_modeloNoLinealEcuacionesInstanceStruct
  *chartInstance, real_T c2_a)
{
  real_T c2_ak;
  c2_ak = c2_a;
  return muDoubleScalarPower(c2_ak, 2.0);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance;
  chartInstance = (SFc2_modeloNoLinealEcuacionesInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_modeloNoLinealEcuacionesInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i1, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance;
  chartInstance = (SFc2_modeloNoLinealEcuacionesInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_modeloNoLinealEcuacionesInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_modeloNoLinealEcuaciones,
  const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_modeloNoLinealEcuaciones), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_modeloNoLinealEcuaciones);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_modeloNoLinealEcuacionesInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_modeloNoLinealEcuacionesInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_modeloNoLinealEcuaciones_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2399710672U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1188586421U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3490257206U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3381332073U);
}

mxArray *sf_c2_modeloNoLinealEcuaciones_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("yR0HH55FTrmcfkJ8Qd6JkE");
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

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_modeloNoLinealEcuaciones(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[10],T\"phi1\",},{M[1],M[11],T\"phi2\",},{M[1],M[12],T\"phi3\",},{M[1],M[13],T\"phi4\",},{M[8],M[0],T\"is_active_c2_modeloNoLinealEcuaciones\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_modeloNoLinealEcuaciones_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance;
    chartInstance = (SFc2_modeloNoLinealEcuacionesInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_modeloNoLinealEcuacionesMachineNumber_,
           2,
           1,
           1,
           9,
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
          init_script_number_translation(_modeloNoLinealEcuacionesMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_modeloNoLinealEcuacionesMachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds
            (_modeloNoLinealEcuacionesMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,1,1,0,"x1");
          _SFD_SET_DATA_PROPS(2,1,1,0,"x2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"x3");
          _SFD_SET_DATA_PROPS(4,1,1,0,"x4");
          _SFD_SET_DATA_PROPS(5,2,0,1,"phi1");
          _SFD_SET_DATA_PROPS(6,2,0,1,"phi2");
          _SFD_SET_DATA_PROPS(7,2,0,1,"phi3");
          _SFD_SET_DATA_PROPS(8,2,0,1,"phi4");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,626);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_u;
          real_T *c2_x1;
          real_T *c2_x2;
          real_T *c2_x3;
          real_T *c2_x4;
          real_T *c2_phi1;
          real_T *c2_phi2;
          real_T *c2_phi3;
          real_T *c2_phi4;
          c2_phi4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c2_phi3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_phi2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_phi1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_x4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_x3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_x2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_x1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_x1);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_x2);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_x3);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_x4);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_phi1);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_phi2);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_phi3);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_phi4);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_modeloNoLinealEcuacionesMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "qqPsB1vY2QUvjjvOCmMOQE";
}

static void sf_opaque_initialize_c2_modeloNoLinealEcuaciones(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_modeloNoLinealEcuacionesInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_modeloNoLinealEcuaciones
    ((SFc2_modeloNoLinealEcuacionesInstanceStruct*) chartInstanceVar);
  initialize_c2_modeloNoLinealEcuaciones
    ((SFc2_modeloNoLinealEcuacionesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_modeloNoLinealEcuaciones(void *chartInstanceVar)
{
  enable_c2_modeloNoLinealEcuaciones
    ((SFc2_modeloNoLinealEcuacionesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_modeloNoLinealEcuaciones(void *chartInstanceVar)
{
  disable_c2_modeloNoLinealEcuaciones
    ((SFc2_modeloNoLinealEcuacionesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_modeloNoLinealEcuaciones(void *chartInstanceVar)
{
  sf_c2_modeloNoLinealEcuaciones((SFc2_modeloNoLinealEcuacionesInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_modeloNoLinealEcuaciones
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_modeloNoLinealEcuaciones
    ((SFc2_modeloNoLinealEcuacionesInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_modeloNoLinealEcuaciones();/* state var info */
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

extern void sf_internal_set_sim_state_c2_modeloNoLinealEcuaciones(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_modeloNoLinealEcuaciones();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_modeloNoLinealEcuaciones
    ((SFc2_modeloNoLinealEcuacionesInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_modeloNoLinealEcuaciones
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_modeloNoLinealEcuaciones(S);
}

static void sf_opaque_set_sim_state_c2_modeloNoLinealEcuaciones(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_modeloNoLinealEcuaciones(S, st);
}

static void sf_opaque_terminate_c2_modeloNoLinealEcuaciones(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_modeloNoLinealEcuacionesInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_modeloNoLinealEcuaciones
      ((SFc2_modeloNoLinealEcuacionesInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_modeloNoLinealEcuaciones_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_modeloNoLinealEcuaciones
    ((SFc2_modeloNoLinealEcuacionesInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_modeloNoLinealEcuaciones(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_modeloNoLinealEcuaciones
      ((SFc2_modeloNoLinealEcuacionesInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_modeloNoLinealEcuaciones(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_modeloNoLinealEcuaciones_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1469496522U));
  ssSetChecksum1(S,(3602139795U));
  ssSetChecksum2(S,(4181606338U));
  ssSetChecksum3(S,(1972065088U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_modeloNoLinealEcuaciones(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_modeloNoLinealEcuaciones(SimStruct *S)
{
  SFc2_modeloNoLinealEcuacionesInstanceStruct *chartInstance;
  chartInstance = (SFc2_modeloNoLinealEcuacionesInstanceStruct *)malloc(sizeof
    (SFc2_modeloNoLinealEcuacionesInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_modeloNoLinealEcuacionesInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_modeloNoLinealEcuaciones;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_modeloNoLinealEcuaciones;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_modeloNoLinealEcuaciones;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_modeloNoLinealEcuaciones;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_modeloNoLinealEcuaciones;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_modeloNoLinealEcuaciones;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_modeloNoLinealEcuaciones;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_modeloNoLinealEcuaciones;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_modeloNoLinealEcuaciones;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_modeloNoLinealEcuaciones;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_modeloNoLinealEcuaciones;
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

void c2_modeloNoLinealEcuaciones_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_modeloNoLinealEcuaciones(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_modeloNoLinealEcuaciones(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_modeloNoLinealEcuaciones(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_modeloNoLinealEcuaciones_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

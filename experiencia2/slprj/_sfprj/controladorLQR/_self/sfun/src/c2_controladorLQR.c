/* Include files */

#include "blascompat32.h"
#include "controladorLQR_sfun.h"
#include "c2_controladorLQR.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controladorLQR_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[9] = { "Ts", "f", "A", "dt", "t", "u",
  "nargin", "nargout", "y" };

/* Function Declarations */
static void initialize_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance);
static void initialize_params_c2_controladorLQR
  (SFc2_controladorLQRInstanceStruct *chartInstance);
static void enable_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance);
static void disable_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_controladorLQR
  (SFc2_controladorLQRInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_controladorLQR
  (SFc2_controladorLQRInstanceStruct *chartInstance);
static void set_sim_state_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance);
static void sf_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance);
static void c2_chartstep_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance);
static void initSimStructsc2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_controladorLQRInstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_identifier, real_T c2_b_y[301]);
static void c2_b_emlrt_marshallIn(SFc2_controladorLQRInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[301]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_controladorLQRInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[40]);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_controladorLQRInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_controladorLQRInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_controladorLQR, const char_T *
  c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_controladorLQRInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_controladorLQRInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_controladorLQR = 0U;
}

static void initialize_params_c2_controladorLQR
  (SFc2_controladorLQRInstanceStruct *chartInstance)
{
}

static void enable_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_controladorLQR
  (SFc2_controladorLQRInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_controladorLQR
  (SFc2_controladorLQRInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[301];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_d_y)[301];
  c2_d_y = (real_T (*)[301])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 301; c2_i0++) {
    c2_u[c2_i0] = (*c2_d_y)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 301),
                FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_controladorLQR;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[301];
  int32_T c2_i1;
  real_T (*c2_y)[301];
  c2_y = (real_T (*)[301])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "y",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 301; c2_i1++) {
    (*c2_y)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_controladorLQR = c2_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_controladorLQR");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_controladorLQR(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance)
{
}

static void sf_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance)
{
  int32_T c2_i2;
  real_T (*c2_y)[301];
  c2_y = (real_T (*)[301])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 301; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_y)[c2_i2], 0U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_controladorLQR(chartInstance);
  sf_debug_check_for_state_inconsistency(_controladorLQRMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_Ts;
  real_T c2_f;
  real_T c2_A;
  real_T c2_dt;
  real_T c2_t[301];
  real_T c2_u[301];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  real_T c2_y[301];
  int32_T c2_i3;
  static real_T c2_dv1[301] = { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07,
    0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18, 0.19, 0.2,
    0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31, 0.32, 0.33,
    0.34, 0.35000000000000003, 0.36, 0.37, 0.38, 0.39, 0.4, 0.41000000000000003,
    0.42, 0.43, 0.44, 0.45, 0.46, 0.47000000000000003, 0.48, 0.49, 0.5, 0.51,
    0.52, 0.53, 0.54, 0.55, 0.56, 0.57000000000000006, 0.58, 0.59, 0.6, 0.61,
    0.62, 0.63, 0.64, 0.65, 0.66, 0.67, 0.68, 0.69000000000000006,
    0.70000000000000007, 0.71, 0.72, 0.73, 0.74, 0.75, 0.76, 0.77, 0.78, 0.79,
    0.8, 0.81, 0.82000000000000006, 0.83000000000000007, 0.84, 0.85, 0.86, 0.87,
    0.88, 0.89, 0.9, 0.91, 0.92, 0.93, 0.94000000000000006, 0.95000000000000007,
    0.96, 0.97, 0.98, 0.99, 1.0, 1.01, 1.02, 1.03, 1.04, 1.05, 1.06, 1.07, 1.08,
    1.09, 1.1, 1.11, 1.12, 1.1300000000000001, 1.1400000000000001,
    1.1500000000000001, 1.16, 1.17, 1.18, 1.19, 1.2, 1.21, 1.22, 1.23, 1.24,
    1.25, 1.26, 1.27, 1.28, 1.29, 1.3, 1.31, 1.32, 1.33, 1.34, 1.35, 1.36, 1.37,
    1.3800000000000001, 1.3900000000000001, 1.4000000000000001, 1.41, 1.42, 1.43,
    1.44, 1.45, 1.46, 1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.56,
    1.57, 1.58, 1.59, 1.5999999999999999, 1.6099999999999999, 1.6199999999999999,
    1.63, 1.64, 1.65, 1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75,
    1.76, 1.77, 1.78, 1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.8499999999999999,
    1.8599999999999999, 1.8699999999999999, 1.88, 1.89, 1.9, 1.91, 1.92, 1.93,
    1.94, 1.95, 1.96, 1.97, 1.98, 1.99, 2.0, 2.01, 2.02, 2.0300000000000002,
    2.04, 2.05, 2.06, 2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14, 2.15, 2.16,
    2.17, 2.1799999999999997, 2.19, 2.2, 2.21, 2.2199999999999998, 2.23, 2.24,
    2.25, 2.26, 2.27, 2.2800000000000002, 2.29, 2.3, 2.31, 2.32, 2.33, 2.34,
    2.35, 2.36, 2.37, 2.38, 2.39, 2.4, 2.41, 2.42, 2.4299999999999997, 2.44,
    2.45, 2.46, 2.4699999999999998, 2.48, 2.49, 2.5, 2.51, 2.52, 2.53, 2.54,
    2.55, 2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63, 2.64, 2.65, 2.66, 2.67,
    2.68, 2.69, 2.7, 2.71, 2.7199999999999998, 2.73, 2.74, 2.75, 2.76, 2.77,
    2.78, 2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87, 2.88, 2.89, 2.9,
    2.91, 2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0 };

  int32_T c2_i4;
  static real_T c2_dv2[301] = { 0.0, 1.1755705045849463, 1.9021130325903071,
    1.9021130325903073, 1.1755705045849465, 2.4492935982947064E-16,
    -1.1755705045849461, -1.9021130325903071, -1.9021130325903073,
    -1.1755705045849467, -4.8985871965894128E-16, 1.1755705045849458,
    1.9021130325903071, 1.9021130325903073, 1.1755705045849467,
    7.3478807948841188E-16, -1.1755705045849456, -1.9021130325903068,
    -1.9021130325903075, -1.1755705045849469, -9.7971743931788257E-16,
    1.1755705045849454, 1.9021130325903068, 1.9021130325903075,
    1.1755705045849472, 1.2246467991473533E-15, -1.1755705045849452,
    -1.9021130325903068, -1.9021130325903075, -1.1755705045849474,
    -1.4695761589768238E-15, 1.1755705045849449, 1.9021130325903066,
    1.9021130325903077, 1.1755705045849476, -5.3909218387947074E-15,
    -1.1755705045849449, -1.9021130325903066, -1.9021130325903077,
    -1.1755705045849478, -1.9594348786357651E-15, 1.1755705045849503,
    1.9021130325903064, 1.9021130325903077, 1.1755705045849481,
    2.2043642384652358E-15, -1.1755705045849445, -1.9021130325903086,
    -1.902113032590308, -1.1755705045849483, -2.4492935982947065E-15,
    1.17557050458495, 1.9021130325903064, 1.9021130325903057, 1.1755705045849485,
    -4.4112043994768247E-15, -1.1755705045849441, -1.9021130325903084,
    -1.902113032590308, -1.1755705045849543, -2.9391523179536475E-15,
    1.1755705045849381, 1.9021130325903062, 1.902113032590306,
    1.1755705045849487, -3.9213456798178833E-15, -1.1755705045849436,
    -1.9021130325903084, -1.9021130325903082, -1.1755705045849432,
    1.0781843677589415E-14, 1.1755705045849376, 1.902113032590306,
    1.9021130325903104, 1.1755705045849492, 1.0779367755043061E-14,
    -1.1755705045849432, -1.9021130325903082, -1.9021130325903084,
    -1.1755705045849436, -3.91886975727153E-15, 1.1755705045849487,
    1.9021130325903104, 1.9021130325903062, 1.1755705045849496,
    1.1269226474702003E-14, -1.1755705045849429, -1.9021130325903037,
    -1.9021130325903084, -1.1755705045849441, -4.4087284769304716E-15,
    1.1755705045849485, 1.9021130325903057, 1.9021130325903064,
    1.1755705045849385, -2.45176952084106E-15, -1.1755705045849425,
    -1.9021130325903035, -1.9021130325903086, -1.175570504584956,
    -4.898587196589413E-15, 1.1755705045849481, 1.90211303259031,
    1.9021130325903108, 1.1755705045849503, -1.9619108011821185E-15,
    -1.1755705045849536, -1.9021130325903122, -1.9021130325903088,
    -1.1755705045849449, 8.82240879895365E-15, 1.1755705045849592,
    1.9021130325903055, 1.9021130325903066, 1.1755705045849392,
    -1.5682906796725182E-14, -1.1755705045849416, -1.9021130325902988,
    -1.9021130325903133, -1.1755705045849567, -5.878304635907295E-15,
    1.1755705045849472, 1.9021130325903008, 1.9021130325903113,
    1.1755705045849512, -9.82193361864236E-16, -1.1755705045849527,
    -1.9021130325903031, -1.9021130325903091, -1.1755705045849456,
    7.8426913596357665E-15, 1.1755705045849354, 1.9021130325903051,
    1.9021130325903071, 1.17557050458494, -1.4703189357407298E-14,
    -1.1755705045849409, -1.9021130325903073, -1.9021130325903048,
    -1.1755705045849345, 2.156368735517883E-14, 1.1755705045849234,
    1.9021130325903006, 1.9021130325903115, 1.175570504584952,
    -2.4759225463534308E-18, -1.175570504584929, -1.9021130325903026,
    -1.9021130325903093, -1.1755705045849465, -2.1558735510086122E-14,
    1.1755705045849345, 1.9021130325903048, 1.9021130325903073,
    1.1755705045849409, 1.4698237512314591E-14, -1.17557050458494,
    -1.9021130325903071, -1.9021130325903051, -1.1755705045849354,
    -3.625944894494707E-14, 1.1755705045849227, 1.9021130325903004,
    1.9021130325903117, 1.1755705045849527, 2.9398950947175538E-14,
    -1.1755705045849281, -1.9021130325903024, -1.9021130325903097,
    -1.1755705045849472, -2.2538452949404006E-14, 1.1755705045849338,
    1.9021130325903046, 1.9021130325903075, 1.1755705045849647,
    1.5677954951632475E-14, -1.1755705045849392, -1.9021130325903066,
    -1.9021130325903055, -1.1755705045849592, -8.8174569538609433E-15,
    1.1755705045849449, 1.9021130325903088, 1.9021130325903033,
    1.1755705045849536, 3.0378668386493419E-14, -1.1755705045849274,
    -1.9021130325903022, -1.90211303259031, -1.1755705045849709,
    -2.3518170388721888E-14, 1.175570504584933, 1.9021130325903042,
    1.9021130325903166, 1.1755705045849654, 1.6657672390950356E-14,
    -1.1755705045849385, -1.9021130325903064, -1.9021130325903146,
    -1.1755705045849598, -9.7971743931788261E-15, 1.175570504584921,
    1.9021130325903084, 1.9021130325903037, 1.1755705045849314,
    3.13583858258113E-14, -1.1755705045849265, -1.9021130325903017,
    -1.9021130325903104, -1.1755705045849487, 3.9238216023642371E-15,
    1.1755705045849092, 1.9021130325903126, 1.9021130325903171,
    1.1755705045849203, 1.763738983026824E-14, -1.1755705045849376,
    -1.902113032590306, -1.9021130325903237, -1.1755705045849376,
    1.76448175979073E-14, 1.1755705045849203, 1.9021130325902993,
    1.9021130325903126, 1.1755705045849552, 3.9163938347251765E-15,
    -1.1755705045849028, -1.9021130325903104, -1.9021130325903017,
    -1.1755705045849725, -2.5477605267357653E-14, 1.1755705045849314,
    1.9021130325903037, 1.9021130325903084, 1.17557050458499,
    -9.8046021608178859E-15, -1.1755705045849139, -1.9021130325903146,
    -1.9021130325903151, -1.1755705045849614, -1.175660927181459E-14,
    1.1755705045849425, 1.902113032590308, 1.9021130325903217,
    1.1755705045849789, -2.3525598156360949E-14, -1.175570504584925,
    -1.9021130325903013, -1.9021130325903108, -1.1755705045849503,
    1.9643867237284719E-15, 1.1755705045849076, 1.9021130325903122,
    1.9021130325903175, 1.1755705045849678, 1.9596824708904003E-14,
    -1.1755705045849361, -1.9021130325903055, -1.9021130325903066,
    -1.1755705045849854, 1.5685382719271533E-14, 1.1755705045849187,
    1.9021130325902988, 1.9021130325903133, 1.1755705045849567,
    5.875828713360942E-15, -1.1755705045849472, -1.9021130325902922,
    -1.9021130325903024, -1.1755705045849743, 2.9406378714814596E-14,
    1.1755705045849298, 1.9021130325902855, 1.9021130325903091,
    1.1755705045849456, -7.84516728218212E-15, -1.1755705045849123,
    -1.9021130325902964, -1.9021130325903157, -1.1755705045849631,
    -1.3716044150450356E-14, 1.1755705045849409, 1.9021130325902897,
    1.9021130325903048, 1.1755705045849805, -2.1566163277725183E-14,
    -1.1755705045849234, -1.9021130325903006, -1.9021130325903115,
    -1.175570504584952, 4.9518450927068616E-18, 1.175570504584952,
    1.902113032590294, 1.9021130325903006, 1.1755705045849694,
    -3.5287159273268247E-14, -1.1755705045849345, -1.9021130325903048,
    -1.9021130325903073, -1.1755705045849409, -4.3117471020172244E-14 };

  int32_T c2_i5;
  int32_T c2_i6;
  real_T (*c2_b_y)[301];
  c2_b_y = (real_T (*)[301])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_Ts, 0U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_f, 1U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_A, 2U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_dt, 3U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_t, 4U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_u, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_y, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_Ts = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_f = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_A = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_dt = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  for (c2_i3 = 0; c2_i3 < 301; c2_i3++) {
    c2_t[c2_i3] = c2_dv1[c2_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i4 = 0; c2_i4 < 301; c2_i4++) {
    c2_u[c2_i4] = c2_dv2[c2_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  for (c2_i5 = 0; c2_i5 < 301; c2_i5++) {
    c2_y[c2_i5] = c2_u[c2_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -12);
  sf_debug_symbol_scope_pop();
  for (c2_i6 = 0; c2_i6 < 301; c2_i6++) {
    (*c2_b_y)[c2_i6] = c2_y[c2_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_controladorLQR(SFc2_controladorLQRInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i7;
  real_T c2_b_inData[301];
  int32_T c2_i8;
  real_T c2_u[301];
  const mxArray *c2_y = NULL;
  SFc2_controladorLQRInstanceStruct *chartInstance;
  chartInstance = (SFc2_controladorLQRInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i7 = 0; c2_i7 < 301; c2_i7++) {
    c2_b_inData[c2_i7] = (*(real_T (*)[301])c2_inData)[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 301; c2_i8++) {
    c2_u[c2_i8] = c2_b_inData[c2_i8];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 301), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_controladorLQRInstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_identifier, real_T c2_b_y[301])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
}

static void c2_b_emlrt_marshallIn(SFc2_controladorLQRInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[301])
{
  real_T c2_dv3[301];
  int32_T c2_i9;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 2, 1,
                301);
  for (c2_i9 = 0; c2_i9 < 301; c2_i9++) {
    c2_y[c2_i9] = c2_dv3[c2_i9];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[301];
  int32_T c2_i10;
  SFc2_controladorLQRInstanceStruct *chartInstance;
  chartInstance = (SFc2_controladorLQRInstanceStruct *)chartInstanceVoid;
  c2_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
  for (c2_i10 = 0; c2_i10 < 301; c2_i10++) {
    (*(real_T (*)[301])c2_outData)[c2_i10] = c2_b_y[c2_i10];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_controladorLQRInstanceStruct *chartInstance;
  chartInstance = (SFc2_controladorLQRInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_controladorLQRInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_controladorLQRInstanceStruct *chartInstance;
  chartInstance = (SFc2_controladorLQRInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_controladorLQR_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[40];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i11;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 40), FALSE);
  for (c2_i11 = 0; c2_i11 < 40; c2_i11++) {
    c2_r0 = &c2_info[c2_i11];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i11);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i11);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i11);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i11);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i11);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i11);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i11);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i11);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[40])
{
  c2_info[0].context = "";
  c2_info[0].name = "mrdivide";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[0].fileTimeLo = 1325138538U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 1319747966U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[1].name = "rdivide";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[1].fileTimeLo = 1286836844U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[2].name = "eml_div";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[2].fileTimeLo = 1313369410U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "mtimes";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[3].fileTimeLo = 1289534092U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "";
  c2_info[4].name = "colon";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[4].fileTimeLo = 1311276918U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c2_info[5].name = "isfinite";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[5].fileTimeLo = 1286836758U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[6].name = "isinf";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[6].fileTimeLo = 1286836760U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[7].name = "isnan";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[7].fileTimeLo = 1286836760U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c2_info[8].name = "floor";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[8].fileTimeLo = 1286836742U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[9].name = "eml_scalar_floor";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[9].fileTimeLo = 1286836726U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c2_info[10].name = "realmax";
  c2_info[10].dominantType = "char";
  c2_info[10].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[10].fileTimeLo = 1307672842U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[11].name = "eml_realmax";
  c2_info[11].dominantType = "char";
  c2_info[11].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c2_info[11].fileTimeLo = 1307672844U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c2_info[12].name = "eml_float_model";
  c2_info[12].dominantType = "char";
  c2_info[12].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[12].fileTimeLo = 1307672842U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c2_info[13].name = "mtimes";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[13].fileTimeLo = 1289534092U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c2_info[14].name = "isnan";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[14].fileTimeLo = 1286836760U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c2_info[15].name = "isinf";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[15].fileTimeLo = 1286836760U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c2_info[16].name = "floor";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[16].fileTimeLo = 1286836742U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c2_info[17].name = "mtimes";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[17].fileTimeLo = 1289534092U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c2_info[18].name = "abs";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[18].fileTimeLo = 1286836694U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[19].name = "eml_scalar_abs";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[19].fileTimeLo = 1286836712U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c2_info[20].name = "eps";
  c2_info[20].dominantType = "char";
  c2_info[20].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[20].fileTimeLo = 1307672840U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[21].name = "eml_is_float_class";
  c2_info[21].dominantType = "char";
  c2_info[21].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[21].fileTimeLo = 1286836782U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[22].name = "eml_eps";
  c2_info[22].dominantType = "char";
  c2_info[22].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c2_info[22].fileTimeLo = 1307672840U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c2_info[23].name = "eml_float_model";
  c2_info[23].dominantType = "char";
  c2_info[23].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[23].fileTimeLo = 1307672842U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!maxabs";
  c2_info[24].name = "abs";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[24].fileTimeLo = 1286836694U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c2_info[25].name = "eml_index_class";
  c2_info[25].dominantType = "";
  c2_info[25].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[25].fileTimeLo = 1286836778U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c2_info[26].name = "intmax";
  c2_info[26].dominantType = "char";
  c2_info[26].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[26].fileTimeLo = 1311276916U;
  c2_info[26].fileTimeHi = 0U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c2_info[27].name = "eml_index_minus";
  c2_info[27].dominantType = "int32";
  c2_info[27].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[27].fileTimeLo = 1286836778U;
  c2_info[27].fileTimeHi = 0U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[28].name = "eml_index_class";
  c2_info[28].dominantType = "";
  c2_info[28].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[28].fileTimeLo = 1286836778U;
  c2_info[28].fileTimeHi = 0U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c2_info[29].name = "eml_index_rdivide";
  c2_info[29].dominantType = "int32";
  c2_info[29].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c2_info[29].fileTimeLo = 1286836780U;
  c2_info[29].fileTimeHi = 0U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c2_info[30].name = "eml_index_class";
  c2_info[30].dominantType = "";
  c2_info[30].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[30].fileTimeLo = 1286836778U;
  c2_info[30].fileTimeHi = 0U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
  c2_info[31].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c2_info[31].name = "eml_int_forloop_overflow_check";
  c2_info[31].dominantType = "";
  c2_info[31].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[31].fileTimeLo = 1311276916U;
  c2_info[31].fileTimeHi = 0U;
  c2_info[31].mFileTimeLo = 0U;
  c2_info[31].mFileTimeHi = 0U;
  c2_info[32].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c2_info[32].name = "intmax";
  c2_info[32].dominantType = "char";
  c2_info[32].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[32].fileTimeLo = 1311276916U;
  c2_info[32].fileTimeHi = 0U;
  c2_info[32].mFileTimeLo = 0U;
  c2_info[32].mFileTimeHi = 0U;
  c2_info[33].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c2_info[33].name = "mtimes";
  c2_info[33].dominantType = "double";
  c2_info[33].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[33].fileTimeLo = 1289534092U;
  c2_info[33].fileTimeHi = 0U;
  c2_info[33].mFileTimeLo = 0U;
  c2_info[33].mFileTimeHi = 0U;
  c2_info[34].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c2_info[34].name = "eml_index_times";
  c2_info[34].dominantType = "int32";
  c2_info[34].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[34].fileTimeLo = 1286836780U;
  c2_info[34].fileTimeHi = 0U;
  c2_info[34].mFileTimeLo = 0U;
  c2_info[34].mFileTimeHi = 0U;
  c2_info[35].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[35].name = "eml_index_class";
  c2_info[35].dominantType = "";
  c2_info[35].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[35].fileTimeLo = 1286836778U;
  c2_info[35].fileTimeHi = 0U;
  c2_info[35].mFileTimeLo = 0U;
  c2_info[35].mFileTimeHi = 0U;
  c2_info[36].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c2_info[36].name = "eml_index_plus";
  c2_info[36].dominantType = "int32";
  c2_info[36].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[36].fileTimeLo = 1286836778U;
  c2_info[36].fileTimeHi = 0U;
  c2_info[36].mFileTimeLo = 0U;
  c2_info[36].mFileTimeHi = 0U;
  c2_info[37].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[37].name = "eml_index_class";
  c2_info[37].dominantType = "";
  c2_info[37].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[37].fileTimeLo = 1286836778U;
  c2_info[37].fileTimeHi = 0U;
  c2_info[37].mFileTimeLo = 0U;
  c2_info[37].mFileTimeHi = 0U;
  c2_info[38].context = "";
  c2_info[38].name = "sin";
  c2_info[38].dominantType = "double";
  c2_info[38].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[38].fileTimeLo = 1286836750U;
  c2_info[38].fileTimeHi = 0U;
  c2_info[38].mFileTimeLo = 0U;
  c2_info[38].mFileTimeHi = 0U;
  c2_info[39].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[39].name = "eml_scalar_sin";
  c2_info[39].dominantType = "double";
  c2_info[39].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[39].fileTimeLo = 1286836736U;
  c2_info[39].fileTimeHi = 0U;
  c2_info[39].mFileTimeLo = 0U;
  c2_info[39].mFileTimeHi = 0U;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_controladorLQRInstanceStruct *chartInstance;
  chartInstance = (SFc2_controladorLQRInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_controladorLQRInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i12;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i12, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i12;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_controladorLQRInstanceStruct *chartInstance;
  chartInstance = (SFc2_controladorLQRInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_controladorLQRInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_controladorLQR, const char_T *
  c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_controladorLQR), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_controladorLQR);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_controladorLQRInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_controladorLQRInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_controladorLQR_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3687231892U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3740270155U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(302599710U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(765485077U);
}

mxArray *sf_c2_controladorLQR_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BYTBCc1DAiDK27aa4t2DI");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
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
      pr[1] = (double)(301);
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

static const mxArray *sf_get_sim_state_info_c2_controladorLQR(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_controladorLQR\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_controladorLQR_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_controladorLQRInstanceStruct *chartInstance;
    chartInstance = (SFc2_controladorLQRInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controladorLQRMachineNumber_,
           2,
           1,
           1,
           1,
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
          init_script_number_translation(_controladorLQRMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_controladorLQRMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_controladorLQRMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"y");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,448);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 301;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T (*c2_y)[301];
          c2_y = (real_T (*)[301])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_controladorLQRMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "0UneYXtEkgcK6C4mjUxSLD";
}

static void sf_opaque_initialize_c2_controladorLQR(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_controladorLQRInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_controladorLQR((SFc2_controladorLQRInstanceStruct*)
    chartInstanceVar);
  initialize_c2_controladorLQR((SFc2_controladorLQRInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_controladorLQR(void *chartInstanceVar)
{
  enable_c2_controladorLQR((SFc2_controladorLQRInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_controladorLQR(void *chartInstanceVar)
{
  disable_c2_controladorLQR((SFc2_controladorLQRInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_controladorLQR(void *chartInstanceVar)
{
  sf_c2_controladorLQR((SFc2_controladorLQRInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_controladorLQR(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_controladorLQR
    ((SFc2_controladorLQRInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_controladorLQR();/* state var info */
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

extern void sf_internal_set_sim_state_c2_controladorLQR(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_controladorLQR();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_controladorLQR((SFc2_controladorLQRInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_controladorLQR(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_controladorLQR(S);
}

static void sf_opaque_set_sim_state_c2_controladorLQR(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_controladorLQR(S, st);
}

static void sf_opaque_terminate_c2_controladorLQR(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_controladorLQRInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_controladorLQR((SFc2_controladorLQRInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controladorLQR_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_controladorLQR((SFc2_controladorLQRInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_controladorLQR(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_controladorLQR((SFc2_controladorLQRInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_controladorLQR(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controladorLQR_optimization_info();
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
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3415847494U));
  ssSetChecksum1(S,(1720677714U));
  ssSetChecksum2(S,(478302534U));
  ssSetChecksum3(S,(3038015011U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_controladorLQR(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_controladorLQR(SimStruct *S)
{
  SFc2_controladorLQRInstanceStruct *chartInstance;
  chartInstance = (SFc2_controladorLQRInstanceStruct *)malloc(sizeof
    (SFc2_controladorLQRInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_controladorLQRInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_controladorLQR;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_controladorLQR;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_controladorLQR;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_controladorLQR;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_controladorLQR;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_controladorLQR;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_controladorLQR;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_controladorLQR;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_controladorLQR;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_controladorLQR;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_controladorLQR;
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

void c2_controladorLQR_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_controladorLQR(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_controladorLQR(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_controladorLQR(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_controladorLQR_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

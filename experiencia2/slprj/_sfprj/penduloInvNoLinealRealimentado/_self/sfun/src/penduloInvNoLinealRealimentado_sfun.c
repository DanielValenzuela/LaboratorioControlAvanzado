/* Include files */

#include "penduloInvNoLinealRealimentado_sfun.h"
#include "c1_penduloInvNoLinealRealimentado.h"
#include "c2_penduloInvNoLinealRealimentado.h"
#include "c7_penduloInvNoLinealRealimentado.h"
#include "c8_penduloInvNoLinealRealimentado.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _penduloInvNoLinealRealimentadoMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void penduloInvNoLinealRealimentado_initializer(void)
{
}

void penduloInvNoLinealRealimentado_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_penduloInvNoLinealRealimentado_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_penduloInvNoLinealRealimentado_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_penduloInvNoLinealRealimentado_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_penduloInvNoLinealRealimentado_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_penduloInvNoLinealRealimentado_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_penduloInvNoLinealRealimentado_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(510521380U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2318545587U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4228371781U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2517872390U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2278222659U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2709073043U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1154730678U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4134161800U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_penduloInvNoLinealRealimentado_get_check_sum(mxArray
            *plhs[]);
          sf_c1_penduloInvNoLinealRealimentado_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_penduloInvNoLinealRealimentado_get_check_sum(mxArray
            *plhs[]);
          sf_c2_penduloInvNoLinealRealimentado_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_penduloInvNoLinealRealimentado_get_check_sum(mxArray
            *plhs[]);
          sf_c7_penduloInvNoLinealRealimentado_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_penduloInvNoLinealRealimentado_get_check_sum(mxArray
            *plhs[]);
          sf_c8_penduloInvNoLinealRealimentado_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1764838350U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3410240878U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(118138738U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(243351119U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2183187639U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1042781503U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4161480131U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(365400598U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_penduloInvNoLinealRealimentado_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "oU90mQ3XUCEeyPNKoyxTKG") == 0) {
          extern mxArray
            *sf_c1_penduloInvNoLinealRealimentado_get_autoinheritance_info(void);
          plhs[0] =
            sf_c1_penduloInvNoLinealRealimentado_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "2C3tH39nCuZ81IY36Ik1fB") == 0) {
          extern mxArray
            *sf_c2_penduloInvNoLinealRealimentado_get_autoinheritance_info(void);
          plhs[0] =
            sf_c2_penduloInvNoLinealRealimentado_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "h1RsjrsSzMxqKojBADZBnB") == 0) {
          extern mxArray
            *sf_c7_penduloInvNoLinealRealimentado_get_autoinheritance_info(void);
          plhs[0] =
            sf_c7_penduloInvNoLinealRealimentado_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "8h5qeC16BbqADpp5fotfWF") == 0) {
          extern mxArray
            *sf_c8_penduloInvNoLinealRealimentado_get_autoinheritance_info(void);
          plhs[0] =
            sf_c8_penduloInvNoLinealRealimentado_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_penduloInvNoLinealRealimentado_get_eml_resolved_functions_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_penduloInvNoLinealRealimentado_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_penduloInvNoLinealRealimentado_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_penduloInvNoLinealRealimentado_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_penduloInvNoLinealRealimentado_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_penduloInvNoLinealRealimentado_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_penduloInvNoLinealRealimentado_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_penduloInvNoLinealRealimentado_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_penduloInvNoLinealRealimentado_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void penduloInvNoLinealRealimentado_debug_initialize(void)
{
  _penduloInvNoLinealRealimentadoMachineNumber_ = sf_debug_initialize_machine(
    "penduloInvNoLinealRealimentado","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_penduloInvNoLinealRealimentadoMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_penduloInvNoLinealRealimentadoMachineNumber_,0);
}

void penduloInvNoLinealRealimentado_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_penduloInvNoLinealRealimentado_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "penduloInvNoLinealRealimentado", "penduloInvNoLinealRealimentado");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_penduloInvNoLinealRealimentado_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

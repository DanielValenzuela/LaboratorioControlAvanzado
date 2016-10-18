/* Include files */

#include "modeloNoLinealEcuaciones_sfun.h"
#include "c2_modeloNoLinealEcuaciones.h"
#include "c7_modeloNoLinealEcuaciones.h"
#include "c8_modeloNoLinealEcuaciones.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _modeloNoLinealEcuacionesMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void modeloNoLinealEcuaciones_initializer(void)
{
}

void modeloNoLinealEcuaciones_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_modeloNoLinealEcuaciones_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==2) {
    c2_modeloNoLinealEcuaciones_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_modeloNoLinealEcuaciones_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_modeloNoLinealEcuaciones_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_modeloNoLinealEcuaciones_process_check_sum_call( int nlhs,
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3523034065U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(351759139U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1195586914U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2636996236U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(641072223U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3445143315U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(30361238U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3045745398U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_modeloNoLinealEcuaciones_get_check_sum(mxArray *
            plhs[]);
          sf_c2_modeloNoLinealEcuaciones_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_modeloNoLinealEcuaciones_get_check_sum(mxArray *
            plhs[]);
          sf_c7_modeloNoLinealEcuaciones_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_modeloNoLinealEcuaciones_get_check_sum(mxArray *
            plhs[]);
          sf_c8_modeloNoLinealEcuaciones_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2206407207U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3736015465U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3746289195U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1960630136U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_modeloNoLinealEcuaciones_autoinheritance_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 2:
      {
        if (strcmp(aiChksum, "yR0HH55FTrmcfkJ8Qd6JkE") == 0) {
          extern mxArray
            *sf_c2_modeloNoLinealEcuaciones_get_autoinheritance_info(void);
          plhs[0] = sf_c2_modeloNoLinealEcuaciones_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "FPgh5smhZndaTf5XfRw2DC") == 0) {
          extern mxArray
            *sf_c7_modeloNoLinealEcuaciones_get_autoinheritance_info(void);
          plhs[0] = sf_c7_modeloNoLinealEcuaciones_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "OQuJoV9pmlZXeIKUCIc9j") == 0) {
          extern mxArray
            *sf_c8_modeloNoLinealEcuaciones_get_autoinheritance_info(void);
          plhs[0] = sf_c8_modeloNoLinealEcuaciones_get_autoinheritance_info();
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

unsigned int sf_modeloNoLinealEcuaciones_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 2:
      {
        extern const mxArray
          *sf_c2_modeloNoLinealEcuaciones_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_modeloNoLinealEcuaciones_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_modeloNoLinealEcuaciones_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_modeloNoLinealEcuaciones_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_modeloNoLinealEcuaciones_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_modeloNoLinealEcuaciones_get_eml_resolved_functions_info();
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

void modeloNoLinealEcuaciones_debug_initialize(void)
{
  _modeloNoLinealEcuacionesMachineNumber_ = sf_debug_initialize_machine(
    "modeloNoLinealEcuaciones","sfun",0,3,0,0,0);
  sf_debug_set_machine_event_thresholds(_modeloNoLinealEcuacionesMachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(_modeloNoLinealEcuacionesMachineNumber_,0);
}

void modeloNoLinealEcuaciones_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_modeloNoLinealEcuaciones_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "modeloNoLinealEcuaciones", "modeloNoLinealEcuaciones");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_modeloNoLinealEcuaciones_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

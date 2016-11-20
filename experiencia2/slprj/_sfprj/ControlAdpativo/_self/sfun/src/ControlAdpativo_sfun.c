/* Include files */

#include "ControlAdpativo_sfun.h"
#include "c1_ControlAdpativo.h"
#include "c2_ControlAdpativo.h"
#include "c3_ControlAdpativo.h"
#include "c4_ControlAdpativo.h"
#include "c6_ControlAdpativo.h"
#include "c7_ControlAdpativo.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _ControlAdpativoMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void ControlAdpativo_initializer(void)
{
}

void ControlAdpativo_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_ControlAdpativo_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_ControlAdpativo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_ControlAdpativo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_ControlAdpativo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_ControlAdpativo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_ControlAdpativo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_ControlAdpativo_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_ControlAdpativo_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4229601223U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1789990530U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1454088693U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(126219059U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3354988651U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1716312387U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2589522188U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2796172240U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_ControlAdpativo_get_check_sum(mxArray *plhs[]);
          sf_c1_ControlAdpativo_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_ControlAdpativo_get_check_sum(mxArray *plhs[]);
          sf_c2_ControlAdpativo_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_ControlAdpativo_get_check_sum(mxArray *plhs[]);
          sf_c3_ControlAdpativo_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_ControlAdpativo_get_check_sum(mxArray *plhs[]);
          sf_c4_ControlAdpativo_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_ControlAdpativo_get_check_sum(mxArray *plhs[]);
          sf_c6_ControlAdpativo_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_ControlAdpativo_get_check_sum(mxArray *plhs[]);
          sf_c7_ControlAdpativo_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(47230085U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3714866465U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2059584356U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(498108144U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_ControlAdpativo_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "0d7utIryrnXgDpwRkTiAwH") == 0) {
          extern mxArray *sf_c1_ControlAdpativo_get_autoinheritance_info(void);
          plhs[0] = sf_c1_ControlAdpativo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "0d7utIryrnXgDpwRkTiAwH") == 0) {
          extern mxArray *sf_c2_ControlAdpativo_get_autoinheritance_info(void);
          plhs[0] = sf_c2_ControlAdpativo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "0d7utIryrnXgDpwRkTiAwH") == 0) {
          extern mxArray *sf_c3_ControlAdpativo_get_autoinheritance_info(void);
          plhs[0] = sf_c3_ControlAdpativo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "jItRcBaSZfpyvFC1h8aWbB") == 0) {
          extern mxArray *sf_c4_ControlAdpativo_get_autoinheritance_info(void);
          plhs[0] = sf_c4_ControlAdpativo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "0d7utIryrnXgDpwRkTiAwH") == 0) {
          extern mxArray *sf_c6_ControlAdpativo_get_autoinheritance_info(void);
          plhs[0] = sf_c6_ControlAdpativo_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "0d7utIryrnXgDpwRkTiAwH") == 0) {
          extern mxArray *sf_c7_ControlAdpativo_get_autoinheritance_info(void);
          plhs[0] = sf_c7_ControlAdpativo_get_autoinheritance_info();
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

unsigned int sf_ControlAdpativo_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
          *sf_c1_ControlAdpativo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_ControlAdpativo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_ControlAdpativo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_ControlAdpativo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_ControlAdpativo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_ControlAdpativo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_ControlAdpativo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_ControlAdpativo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_ControlAdpativo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_ControlAdpativo_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_ControlAdpativo_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_ControlAdpativo_get_eml_resolved_functions_info();
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

void ControlAdpativo_debug_initialize(void)
{
  _ControlAdpativoMachineNumber_ = sf_debug_initialize_machine("ControlAdpativo",
    "sfun",0,6,0,0,0);
  sf_debug_set_machine_event_thresholds(_ControlAdpativoMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_ControlAdpativoMachineNumber_,0);
}

void ControlAdpativo_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_ControlAdpativo_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("ControlAdpativo",
      "ControlAdpativo");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_ControlAdpativo_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

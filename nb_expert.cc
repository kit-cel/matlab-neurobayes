#include "mex.h"
#include <iostream>
#include <string>
#include <fstream>
#include "NeuroBayesExpert.hh"

void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
    double *nb_input,*nb_output;
    size_t mrows,ncols;
    
    /* The input must be a noncomplex vector and a string.*/
    mrows = mxGetM(prhs[0]);
    ncols = mxGetN(prhs[0]);
    
    if(mrows!=1)
    {
        std::cout << "MROWS: " << mrows << std::endl;
        std::cout << "NCOLS: " << ncols << std::endl;
        mexErrMsgIdAndTxt("MATLAB:nb_expert:invalidNumInputs","Input has more than one row.");
    }
    
    std::string file_expertise = mxArrayToString(prhs[1]); // get filepath to expertise
    
    /* Check for existent expertise on filepath. */
    std::ifstream file(file_expertise.c_str());
    if(not(file.good()))
    {
        std::cout << "FILEPATH NOT VALID: " << file_expertise << std::endl;
        mexErrMsgIdAndTxt("MATLAB:nb_expert:notFoundInPath","Filepath is not existent.");
    }
    
    /* Create matrix for the return argument (scalar). */
    plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
  
    /* Assign pointers to each input and output. */
    nb_input = mxGetPr(prhs[0]);
    nb_output = mxGetPr(plhs[0]);
    
    /* Call the neurobayes expert. */
    Expert* nb_expert = new Expert(file_expertise.c_str());
    nb_output[0] = nb_expert->nb_expert(nb_input);
    delete nb_expert;
}

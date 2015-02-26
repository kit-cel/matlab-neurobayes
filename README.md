MATLAB wrapper for NeuroBayes
========

This wrapper for MATLAB via MEX-File Creation API [0] of the NeuroBayes [1] artifical neural network makes it possible to use the NeuroBayes Expert within MATLAB. The training of the network is not included in this wrapper.

**Install guide**  
First insert your individual pathes to header files and shared libraries in the file `mexit.m`. Then execute this file via MATLAB. This will generate the output files `nb_expert.o` and `nb_expert.mex64`. Now you can use the NeuroBayes expert within MATLAB via the call `nb_expert(input_vector,filepath_expertise)`. Check out the file `testit.m` for test-cases and examples.

**Dependencies**  
NeuroBayes Expert

**Contact**  
Stefan Wunsch  
stefan.wunsch[at]student.kit.edu

**References**  
[0] http://de.mathworks.com/help/matlab/call-mex-files-1.html
[1] http://neurobayes.phi-t.de/

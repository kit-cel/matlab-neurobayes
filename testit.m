% test case: given expertise
disp('// Test nb_expert function on functionality (any output is valid)')
a = rand(1,21);
filepath = 'example_expertise';
nb_output = nb_expert(a,filepath)

% test case: error-handling (no expertise)
disp('// Test error-handling for not existent expertise')
filepath = 'notexistent_expertise';
nb_output = nb_expert(a,filepath)

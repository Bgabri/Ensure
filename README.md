# Ensure


## USAGE
A compile/run time assertion checker with unique exit errors.

WARNING: A counter is used to give the assertions unique exit errors
starting from 0 with a maximum of 255. The counter is reset between 
files, so it is recommended to offset the counter using the
INCREMENT_COUNT(_100, _10, _1) macro at the top of the file. 


Simply invoke ensure(expression) 

INCREMENT_COUNT(0, 4, 2); // offset the counter by 42 
ensure(1 + 1 == 2) // holds true, does not exit with 42 
ensure(1 + 1 == 3) // holds false, exits with 43 


To check the corrsponding exit error of an ensure use the following 
compiler flags.

At compile time: 
    -D which_compile_error

At run time:
    -D which_run_error

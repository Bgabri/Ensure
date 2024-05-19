# ${\color{Dandelion}ensure.c}$
A compile/run time assertion checker with unique exit error codes.

## usage
A counter is used to give the assertions unique exit errors
starting from `0` with a maximum of `255`. The counter is reset between 
files, so it is recommended to offset the counter using the
`INCREMENT_COUNT(_100, _10, _1)` macro at the top of the file. 


Simply invoke ensure(expression) 
```c
INCREMENT_COUNT(0, 4, 2); // offset the counter by 42 
ensure(1 + 1 == 2) // holds true, does not exit with 42 
ensure(1 + 1 == 3) // holds false, exits with 43 
```

To check the corrsponding exit error of an ensure use the following 
compiler flags.

At compile time: 
```c
    -D which_compile_error
```
At run time:
```c
    -D which_run_error
```
### ![sample](https://github.com/Bgabri/Ensure/blob/main/sample/sample.c)
```C
#include <stdio.h>
#include <stdlib.h>

#include "ensure.h"


// Add offset
INCREMENT_COUNT(0, 4, 2);


int sumOfNums(int *nums, int start, int end) {
    if (start == end) return 0;
    return nums[start] + sumOfNums(nums, start+1, end);
}

void func() {
    int sum = 45; // 0+1+2+...+8+9
    
    int nums[8] = {1, 2, 3, 4, 6, 7, 8, 9};

    for (int i = 0; i < 8; i++) {
        ensure(45 - sum == sumOfNums(nums, 0, i)); // exit code 42
        sum -= nums[i];
    }

    ensure(sum == 5); // exit code 43
}

int main(int argc, char *argv[]) {

    ensure(1+1 == 2); // exit code 44

    func();

    ensure(!!!45); // exit code 45

    return 0;
}
```
### output
#### compile time
<img src="https://github.com/Bgabri/Ensure/blob/main/sample/out_compile.png" width="700px">

#### run time
<img src="https://github.com/Bgabri/Ensure/blob/main/sample/out_run.png" width="700px">

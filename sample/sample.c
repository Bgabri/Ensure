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

    ensuref(!!!45, "!!!45 does not hold\n"); // exit code 45

    return 0;
}
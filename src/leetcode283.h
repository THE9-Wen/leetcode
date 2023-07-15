//
// Created by Wenhao on 2023/7/15.
//

#ifndef LEETCODE_LEETCODE283_H
#define LEETCODE_LEETCODE283_H

#endif //LEETCODE_LEETCODE283_H

void moveZeroes(int* nums, int numsSize){
    int fast = 0;
    int slow = 0;
    while (fast < numsSize) {
        if (fast < numsSize && nums[fast] == 0) {
            fast++;
        } else {
            nums[slow++] = nums[fast++];
        }
    }
    while (slow < numsSize) {
        nums[slow++] = 0;
    }
}

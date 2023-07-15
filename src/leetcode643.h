//
// Created by Wenhao on 2023/7/15.
//

#ifndef LEETCODE_LEETCODE643_H
#define LEETCODE_LEETCODE643_H

#endif //LEETCODE_LEETCODE643_H

double findMaxAverage(int* nums, int numsSize, int k){
    int fast = 0;
    int slow = 0;
    int sum = 0;
    while (fast < k) {
        sum += nums[fast++];
    }
    int max = sum;
    while (fast < numsSize) {
        sum = sum - nums[slow] + nums[fast];
        max = max < sum ? sum : max;
        slow++;
        fast++;
    }
    return (max + 0.0) / k;
}

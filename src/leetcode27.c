//
// Created by Wenhao on 2023/7/14.
//

int removeElement(int* nums, int numsSize, int val){
    int fast = 0;
    int slow = 0;
    while (fast < numsSize) {
        if (nums[fast] != val && fast < numsSize) {
            nums[slow++] = nums[fast++];
        } else {
            fast++;
        }
    }
    return slow;
}
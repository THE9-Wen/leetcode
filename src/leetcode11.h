//
// Created by Wenhao on 2023/7/15.
//

#ifndef LEETCODE_LEETCODE11_H
#define LEETCODE_LEETCODE11_H

#endif //LEETCODE_LEETCODE11_H

int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int maxSize = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            int area = height[left] * (right - left);
            maxSize = maxSize < area ? area : maxSize;
            left++;
        } else {
            int area = height[right] * (right - left);
            maxSize = maxSize < area ? area : maxSize;
            right--;
        }
    }
    return maxSize;
}

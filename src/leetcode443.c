#include <string.h>
#include <stdlib.h>
#include <printf.h>

//
// Created by Wenhao on 2023/7/15.
//
int getDigits(int number) {
    int digit = 0;
    while (number > 0) {
        number /= 10;
        digit++;
    }
    return digit;
}

/**
 * 思路不清晰版
 * @param chars
 * @param charsSize
 * @return
 */
int compress(char* chars, int charsSize){
    int fast = 0;
    int slow = 0;
    while (fast < charsSize - 1) {
        int i = 1;
        while (fast < charsSize - 1 && chars[fast] == chars[fast + 1]) {
            i++;
            fast++;
        }
        chars[slow] = chars[fast];
        if (i > 1) {int digit = getDigits(i);
            for (int j = 0;i > 0;i /= 10,j++) {
                chars[slow + digit - j] = i % 10 + '0';
            }
            slow += digit;
        }
        slow++;
        fast++;
    }
    if (fast < charsSize) {
        chars[slow++] = chars[fast];
    }
    return slow;
}

void reverse(char * str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
}

/**
 * 思路清晰版 还是交换比较简单
 * @param chars
 * @param charsSize
 * @return
 */
int compress_v2(char* chars, int charsSize){
    int fast = 0;
    int slow = 0;
    // slow指针指向压缩后写入的位置 fast指针指向压缩前读取的位置
    while (fast < charsSize) {
        chars[slow] = chars[fast];
        int count = 0;
        while (fast < charsSize && chars[fast] == chars[slow]) {
            count++;
            fast++;
        }
        slow++;
        if (count > 1) {
            int digit = 0;
            while (count > 0) {
                chars[slow + digit++] = count % 10 + '0';
                count /= 10;
            }
            reverse(chars, slow, slow + digit - 1);
            slow += digit;
        }
    }
    return slow;
}

int main() {
    char chars = {'a', 'a'};
    compress(&chars, 2);
    printf("%s", &chars);
    return 0;
}
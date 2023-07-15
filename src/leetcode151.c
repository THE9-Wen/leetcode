//
// Created by Wenhao on 2023/7/13.
//

#include <stdlib.h>
#include <printf.h>
#include <string.h>

/**
 * 翻转字符串
 * 开始和结束指向一个实际存在的字符而不是哨兵
 *
 * @param s
 * @param start
 * @param end
 */
void reverse(char * s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

char * reverseWords(char * s){
    int length = strlen(s);
    int slow = 0;
    int fast = 0;
    // 删除字符串前的空格
    while (s[fast] == ' ') {
        fast++;
    }
    // 删除字符串中间的空格 从第0个和第1个开始判断
    while (fast < length - 1) {
        if (s[fast] == ' ' && s[fast + 1] == ' ') {
            fast++;
        } else {
            s[slow++] = s[fast++];
        }
    }
    // 拷贝最后一个字符
    if (s[fast] != ' ') {
        s[slow++] = s[fast++];
    }
    s[slow] = '\0';

    // 翻转整个字符串
    reverse(s, 0, slow - 1);

    // 翻转每一个单词
    for (int i = 0; i < slow; i++) {
        int j = i;
        while (s[j] != ' ' && j < slow) {
            j++;
        }
        reverse(s, i, j - 1);
        i = j;
    }
    return s;
}

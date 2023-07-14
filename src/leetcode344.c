//
// Created by Wenhao on 2023/7/14.
//

void reverseString(char* s, int sSize){
    int left = 0;
    int right = sSize - 1;
    char temp;
    while (left < right) {
        temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
}

int main() {
    return 0;
}

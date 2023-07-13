//
// Created by Wenhao on 2023/7/13.
//

#include <string.h>
#include <printf.h>
#include <stdbool.h>

char vowel[] = "aeiouAEIOU";

bool isVowel(char c) {
  for (int i = 0;vowel[i]; i++) {
      if (vowel[i] == c) {
          return true;
      }
  }
  return false;
}

char * reverseVowels(char * s){
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        while (!isVowel(s[left]) && left < right) {
            left++;
        }
        while (!isVowel(s[right]) && left < right) {
            right--;
        }
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    return s;
}

int main() {
    char * result = reverseVowels("hello");
    printf("%s\n", result);
    return 0;
}

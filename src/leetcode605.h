#include <stdbool.h>
#include <stdlib.h>

//
// Created by Wenhao on 2023/7/13.
//
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int max = 0;
    int i = 0;
    if (flowerbedSize == 0) {
        return 0 >= n;
    }
    if (flowerbedSize == 1) {
        return (1 - flowerbed[0]) >= n;
    }
    if (flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
        max++;
        flowerbed[i] = 1;
    }
    for (i = 1;i < flowerbedSize - 1;i++) {
        if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
            max++;
            flowerbed[i] = 1;
        }
    }
    if (flowerbed[i] == 0 && flowerbed[i - 1] == 0) {
        max++;
        flowerbed[i] = 1;
    }
    return max >= n;
}

bool canPlaceFlowers_v2(int* flowerbed, int flowerbedSize, int n){
    int *copy = malloc((flowerbedSize + 2) * sizeof (int));
    copy[0] = 0;
    copy[flowerbedSize + 1] = 0;
    for (int i = 0;i < flowerbedSize;i++) {
        copy[i + 1] = flowerbed[i];
    }
    int max = 0;
    for (int i = 1;i < flowerbedSize + 1;i++) {
        if (!copy[i - 1] && !copy[i] && !copy[i + 1]) {
            max++;
            copy[i] = 1;
        }
        if (max >= n) {
            return true;
        }
    }
    return false;
}

bool canPlaceFlowers_v3(int* flowerbed, int flowerbedSize, int n){
    int preFlower = -2;
    int max = 0;
    int i;
    for (i = 0;i < flowerbedSize;i++) {
        if (flowerbed[i]) {
            max += (i - preFlower) / 2 - 1;
            preFlower = i;
        }
    }
    if (i != preFlower) {
        max += (i - preFlower - 1) / 2;
    }
    return max >= n;
}
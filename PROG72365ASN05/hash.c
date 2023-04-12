#include "hash.h"
#include <stdio.h>

int h1(int k, int M) {
    return k % M;
}

int h2(int k, int R) {
    return R - (k % R);
}

void hashInit(int* hashTable, int* input, int M, int R) {
    int i, j, index, key;
    for (i = 0; i < M; i++) {
        hashTable[i] = -1; // Initialize hash table to -1
    }
    for (j = 0; j < M; j++) {
        key = input[j];
        i = 0;
        do {
            index = (h1(key, M) + i * h2(key, R)) % M;
            if (hashTable[index] == -1) {
                hashTable[index] = key;
                break;
            }
            i++;
        } while (i < M);
    }
}

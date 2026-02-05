#include <stdio.h>

void mergeLogs(int log1[], int size1, int log2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    // Compare elements from both logs and merge in sorted order
    while (i < size1 && j < size2) {
        if (log1[i] <= log2[j]) {
            result[k++] = log1[i++];
        } else {
            result[k++] = log2[j++];
        }
    }

    // Append remaining elements from log1, if any
    while (i < size1) {
        result[k++] = log1[i++];
    }

    // Append remaining elements from log2, if any
    while (j < size2) {
        result[k++] = log2[j++];
    }
}

int main() {
    int logA[] = {10, 20, 30, 40}; // Sorted server 1 logs
    int logB[] = {15, 25, 35};      // Sorted server 2 logs
    int sizeA = sizeof(logA) / sizeof(logA[0]);
    int sizeB = sizeof(logB) / sizeof(logB[0]);
    int mergedLog[sizeA + sizeB];

    mergeLogs(logA, sizeA, logB, sizeB, mergedLog);

    // Output: 10 15 20 25 30 35 40
    for (int i = 0; i < sizeA + sizeB; i++) {
        printf("%d ", mergedLog[i]);
    }
    return 0;
}


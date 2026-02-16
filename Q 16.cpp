#include <stdio.h>

int main() {
    int arr[] = {1, 2, 2, 3, 1, 4, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Array to store the frequency of elements, initialized to -1
    int freq[n];

    for (int i = 0; i < n; i++) {
        freq[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int count = 1;
        if (freq[i] != 0) { // Only process if not marked as a duplicate
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0; // Mark the duplicate element as visited/counted
                }
            }
            freq[i] = count; // Store the frequency of the current distinct element
        }
    }

    printf("The frequency of each distinct element is:\n");
    for (int i = 0; i < n; i++) {
        if (freq[i] != 0) {
            printf("%d occurs %d times\n", arr[i], freq[i]);
        }
    }

    return 0;
}


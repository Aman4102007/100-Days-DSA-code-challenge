#include <stdio.h>

// Define a maximum array size to prevent buffer overflow issues
#define MAX_SIZE 100

/**
 * Inserts an element x at a 1-based position pos in an array of n integers.
 * 
 * @param arr The integer array.
 * @param n A pointer to the current size of the array.
 * @param x The element to insert.
 * @param pos The 1-based position for insertion (1 to n+1).
 * @return 0 on success, -1 on failure (invalid position or array full).
 */
int insert_element(int arr[], int *n, int x, int pos) {
    // Validate the position. It must be between 1 (start) and n+1 (end)
    if (pos < 1 || pos > *n + 1) {
        printf("Error: Invalid position for insertion.\n");
        return -1;
    }

    // Check if the array is full
    if (*n >= MAX_SIZE) {
        printf("Error: Array is full, cannot insert more elements.\n");
        return -1;
    }

    // Convert 1-based position to 0-based index
    int index = pos - 1;

    // Shift existing elements to the right to make space
    // Start from the last element (index n-1) and move to the target index
    for (int i = *n - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the new element at the now-vacant target index
    arr[index] = x;

    // Increment the size of the array
    (*n)++;

    return 0;
}

int main() {
    int arr[MAX_SIZE] = {10, 20, 30, 40, 50};
    int n = 5; // Current number of elements
    int x = 25; // Element to insert
    int pos = 3; // Position for insertion (1-based, so between 20 and 30)

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (insert_element(arr, &n, x, pos) == 0) {
        printf("After inserting %d at position %d:\n", x, pos);
        printf("Modified array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}



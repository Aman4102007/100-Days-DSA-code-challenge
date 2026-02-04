#include <stdio.h>

int main() {
    int array[100], position, i, n;

    printf("Enter number of elements in array: ");
    // Ensure the user inputs a valid number of elements
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid input for number of elements.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the 1-based position to delete the element from (1 to %d): ", n);
    // Ensure the user inputs a valid position
    if (scanf("%d", &position) != 1 || position < 1 || position > n) {
        printf("Invalid position entered.\n");
        return 1;
    }

    // Deleting the element by shifting subsequent elements
    // The loop starts from the 0-based index of the position to be deleted
    for (i = position - 1; i < n - 1; i++) {
        array[i] = array[i+1];
    }

    // Decrement the number of elements in the array
    n--;

    // Printing the new array
    printf("Resultant array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}


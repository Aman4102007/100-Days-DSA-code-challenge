#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to delete the first occurrence of a key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node *curr = head, *prev = NULL;

    // Case 1: Key is found in the head node
    if (curr != NULL && curr->data == key) {
        head = curr->next; // Change head
        free(curr); // Free the old head node memory
        return head;
    }

    // Case 2: Search for the key to be deleted, keep track of the previous node
    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If the key was not present in the list
    if (curr == NULL) {
        return head;
    }

    // Unlink the node from the linked list
    if (prev != NULL) {
        prev->next = curr->next;
    }

    free(curr); // Free the memory of the found node
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to handle input and execution
int main() {
    struct Node* head = NULL;
    int n, data, key;

    // Read input size n
    if (scanf("%d", &n) != 1) return 1;

    // Read n integers and build the list
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &data) != 1) return 1;
        head = insertEnd(head, data);
    }

    // Read the key to delete
    if (scanf("%d", &key) != 1) return 1;

    // Delete the first occurrence of the key
    head = deleteKey(head, key);

    // Print the modified list
    printList(head);

    // Free all remaining allocated memory to prevent memory leaks (good practice)
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


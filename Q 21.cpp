#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct node {
    int data;
    struct node *next;
};

// Function to create and traverse (print) the linked list
void createAndDisplayList(int n) {
    struct node *head = NULL, *newNode, *temp;
    int data, i;

    for (i = 0; i < n; i++) {
        scanf("%d", &data); // Read data
        newNode = (struct node *)malloc(sizeof(struct node)); // Allocate node
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Traverse and print
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        createAndDisplayList(n);
    }
    return 0;
}


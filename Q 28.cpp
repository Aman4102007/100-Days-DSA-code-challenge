#include <iostream>
#include <vector>

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node dynamically
Node* createNode(int data) {
    Node* newNode = new Node(); // Dynamically allocate memory
    if (!newNode) {
        std::cout << "Memory allocation failed" << std::endl;
        return nullptr;
    }
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to create the circular linked list from a vector of integers
Node* createCircularLinkedList(const std::vector<int>& elements) {
    if (elements.empty()) {
        return nullptr;
    }

    Node* head = createNode(elements[0]);
    Node* current = head;

    for (size_t i = 1; i < elements.size(); ++i) {
        current->next = createNode(elements[i]);
        current = current->next;
    }

    // Make the list circular
    current->next = head;

    return head;
}

// Function to traverse and print the circular linked list
void printCircularLinkedList(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    
    // Traverse until we return to the head node
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);

    std::cout << std::endl;
}

// Main function to handle input and execution
int main() {
    int n;
    // Read the number of elements
    if (!(std::cin >> n)) return 0;

    std::vector<int> elements(n);
    // Read the n elements
    for (int i = 0; i < n; ++i) {
        std::cin >> elements[i];
    }

    // Create the circular linked list
    Node* head = createCircularLinkedList(elements);

    // Print the list
    printCircularLinkedList(head);

    // Note: In a real application, you would also need a function
    // to deallocate the dynamically allocated memory to prevent memory leaks.

    return 0;
}


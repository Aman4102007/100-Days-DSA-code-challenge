#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Node structure for the polynomial
struct Node {
    int coeff;
    int exp;
    Node* next;

    // Constructor for convenience
    Node(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};

// Function to insert a term into the polynomial while maintaining sorted order (descending exponent)
Node* insertTerm(Node* head, int coeff, int exp) {
    if (coeff == 0) return head;
    Node* newNode = new Node(coeff, exp); // Dynamically allocate new node
    
    // If the list is empty or the new node has a higher exponent than the head
    if (head == nullptr || exp > head->exp) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    // Traverse the list to find the correct position to insert
    while (current->next != nullptr && current->next->exp >= exp) {
        // If an existing term has the same exponent, add coefficients
        if (current->next->exp == exp) {
            current->next->coeff += coeff;
            // If the coefficient becomes zero, remove the node
            if (current->next->coeff == 0) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            delete newNode; // New node not needed
            return head;
        }
        current = current->next;
    }

    // Insert the new node at the correct position
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to print the polynomial in standard form
void printPolynomial(Node* head) {
    if (head == nullptr) {
        cout << "0" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        // Handle the coefficient and exponent formatting
        if (current->coeff != 0) {
            // Print coefficient if it's not 1 or -1 (unless it's a constant)
            if (current->coeff != 1 && current->coeff != -1 || current->exp == 0) {
                cout << current->coeff;
            } else if (current->coeff == -1) {
                cout << "-";
            }

            // Print 'x' if exponent is > 0
            if (current->exp > 0) {
                cout << "x";
            }

            // Print exponent if it's > 1
            if (current->exp > 1) {
                cout << "^" << current->exp;
            }

            // Add " + " if there are more terms with positive coefficients
            if (current->next != nullptr && current->next->coeff > 0) {
                cout << " + ";
            } else if (current->next != nullptr && current->next->coeff < 0) {
                cout << " "; // Space before a negative coefficient (which includes its sign)
            }
        }
        current = current->next;
    }
    cout << endl;
}

// Function to deallocate the memory of the linked list
void deleteList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp; // Deallocate memory for each node
    }
}

int main() {
    Node* poly = nullptr;
    int n;
    cout << "Input:" << endl;
    if (!(cin >> n)) return 1;

    for (int i = 0; i < n; ++i) {
        int coeff, exp;
        cin >> coeff >> exp;
        poly = insertTerm(poly, coeff, exp);
    }

    cout << "Output:" << endl;
    printPolynomial(poly);

    // Clean up memory
    deleteList(poly);

    return 0;
}


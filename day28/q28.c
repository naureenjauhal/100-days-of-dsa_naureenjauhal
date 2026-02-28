#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Create first node
    head = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d", &head->data);
    head->next = head;   // Circular link to itself
    temp = head;

    // Create remaining nodes
    for (int i = 1; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);

        newNode->next = head;  // Point new node to head
        temp->next = newNode;  // Previous node points to new node

        temp = newNode;        // Move temp forward
    }

    // Traverse and print
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}
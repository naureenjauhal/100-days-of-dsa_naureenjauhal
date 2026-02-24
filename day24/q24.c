#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key;
    struct Node *head = NULL, *temp = NULL, *newNode;

    // Input number of nodes
    scanf("%d", &n);

    // Create linked list
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Input key
    scanf("%d", &key);

    struct Node *current = head, *previous = NULL;

    // If head contains key
    if(current != NULL && current->data == key) {
        head = current->next;
        free(current);
    } else {
        while(current != NULL && current->data != key) {
            previous = current;
            current = current->next;
        }

        if(current != NULL) {
            previous->next = current->next;
            free(current);
        }
    }

    // Print updated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
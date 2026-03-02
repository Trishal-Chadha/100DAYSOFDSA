#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    if(n <= 0) {
        return 0;
    }

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory dynamically
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

        if(head == NULL) {
            head = newNode;
            newNode->next = head;   // Circular link
            temp = head;
        }
        else {
            temp->next = newNode;
            newNode->next = head;   // Maintain circular nature
            temp = newNode;
        }
    }

    // Traversal
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue for level order construction
struct Node* queue[1000];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == 999) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct Node* current = dequeue();

        // Left child
        if (arr[i] != -1) {
            current->left = newNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    return root;
}

// Mirror the tree
void mirror(struct Node* root) {
    if (root == NULL) return;

    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    mirror(root);

    inorder(root);

    return 0;
}
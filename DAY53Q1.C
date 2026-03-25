#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue structure
struct QueueNode {
    struct Node* node;
    int hd;
};

struct Queue {
    int front, rear, size;
    struct QueueNode* arr;
};

struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->size = n;
    q->arr = (struct QueueNode*)malloc(n * sizeof(struct QueueNode));
    return q;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    if (q->rear == q->size - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
}

struct QueueNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));

    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root, int n) {
    if (!root) return;

    int hd[n], val[n], count = 0;

    struct Queue* q = createQueue(n);
    enqueue(q, root, 0);

    int minHD = 0, maxHD = 0;

    while (!isEmpty(q)) {
        struct QueueNode temp = dequeue(q);
        struct Node* node = temp.node;
        int h = temp.hd;

        hd[count] = h;
        val[count] = node->data;
        count++;

        if (h < minHD) minHD = h;
        if (h > maxHD) maxHD = h;

        if (node->left)
            enqueue(q, node->left, h - 1);

        if (node->right)
            enqueue(q, node->right, h + 1);
    }

    // Print vertical order
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < count; j++) {
            if (hd[j] == i) {
                printf("%d ", val[j]);
            }
        }
        printf("\n");
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root, n);

    return 0;
}
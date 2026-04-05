#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    int* arr;
    int front, rear;
};

// Create queue
struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (int*)malloc(n * sizeof(int));
    q->front = 0;
    q->rear = -1;
    return q;
}

// Check if empty
int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

// Enqueue
void enqueue(struct Queue* q, int x) {
    q->arr[++q->rear] = x;
}

// Dequeue
int dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// BFS function
void bfs(int s, struct Node** adj, int n) {
    int* visited = (int*)calloc(n, sizeof(int));

    struct Queue* q = createQueue(n);

    visited[s] = 1;
    enqueue(q, s);

    while (!isEmpty(q)) {
        int node = dequeue(q);
        printf("%d ", node);

        struct Node* temp = adj[node];
        while (temp) {
            int neighbor = temp->data;

            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(q, neighbor);
            }
            temp = temp->next;
        }
    }

    free(visited);
}
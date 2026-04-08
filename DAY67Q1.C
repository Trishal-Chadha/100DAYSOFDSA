#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack
int stack[MAX], top = -1;

// Graph
int adj[MAX][MAX];
int visited[MAX];

// Push to stack
void push(int node) {
    stack[++top] = node;
}

// DFS function
void dfs(int node, int n) {
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[node][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }

    // Push after visiting all neighbors
    push(node);
}

// Topological sort function
void topoSort(int n) {
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, n);
        }
    }

    // Print stack (reverse order)
    printf("Topological Order: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize graph
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topoSort(n);

    return 0;
}
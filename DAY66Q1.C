#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function to detect cycle
bool dfs(int node, int n, int **adj, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {
            // If not visited
            if (!visited[i]) {
                if (dfs(i, n, adj, visited, recStack))
                    return true;
            }
            // If already in recursion stack → cycle
            else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Allocate adjacency matrix
    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adj[i] = (int *)calloc(n, sizeof(int));
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed edge
    }

    bool *visited = (bool *)calloc(n, sizeof(bool));
    bool *recStack = (bool *)calloc(n, sizeof(bool));

    // Check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n, adj, visited, recStack)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    // Free memory
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);
    free(recStack);

    return 0;
}

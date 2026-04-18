#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];

void dfs(int v, int n) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m, u, v;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    dfs(1, n);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}
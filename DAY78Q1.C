#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int visited[], int n) {
    int min = INT_MAX, min_index;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int prim(int n, int graph[MAX][MAX]) {
    int key[MAX], visited[MAX];
    
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;  // start from node 1
    int total_weight = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key, visited, n);
        visited[u] = 1;
        total_weight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return total_weight;
}

int main() {
    int n = 4, m = 5;
    int graph[MAX][MAX] = {0};

    // edges: u v w
    graph[1][2] = graph[2][1] = 3;
    graph[1][3] = graph[3][1] = 5;
    graph[2][3] = graph[3][2] = 1;
    graph[2][4] = graph[4][2] = 4;
    graph[3][4] = graph[4][3] = 2;

    printf("Total MST Weight = %d\n", prim(n, graph));

    return 0;
}
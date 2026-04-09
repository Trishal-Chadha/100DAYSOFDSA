#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);
    
    // Step 1: Calculate indegree
    for(int i = 0; i < V; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    // Step 2: Push nodes with indegree 0
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Process queue
    vector<int> topo;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // Step 4: Check cycle
    if(topo.size() != V) {
        cout << "Cycle detected! Topological sort not possible.\n";
        return {};
    }

    return topo;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Example graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topologicalSort(V, adj);

    cout << "Topological Order: ";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}

// Purpose: Euler Tour - flatten tree for range queries
// Time: O(V + E)
vector<int> tin, tout;
int timer = 0;

void eulerTour(int u, int parent = -1) {
    tin[u] = timer++;
    for (int v : adj[u]) {
        if (v != parent) {
            eulerTour(v, u);
        }
    }
    tout[u] = timer++;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

// Purpose: Topological Sort using Kahn's algorithm (BFS)
// Time: O(V + E)
vector<int> topologicalSort(int n, vector<vector<int>> &adj) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    return result;
}

// Purpose: Topological Sort using DFS
// Time: O(V + E)
vector<int> topoResult;
vector<bool> topoVis;

void topoDFS(int v) {
    topoVis[v] = true;
    for (int u : adj[v]) {
        if (!topoVis[u]) {
            topoDFS(u);
        }
    }
    topoResult.push_back(v);
}


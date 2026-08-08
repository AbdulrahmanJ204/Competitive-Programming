// Purpose: Depth First Search - traverse graph depth-wise
// Time: O(V + E)
void dfs(int node) {
    visited[node] = true;
    for (int child : adj[node]) {
        if (!visited[child]) {
            dfs(child);
        }
    }
}

// Purpose: DFS with timestamps - useful for detecting cycles and tree queries
// Time: O(V + E)
vector<int> color, time_in, time_out;
int dfs_timer = 0;

void dfsWithTime(int v) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            dfsWithTime(u);
        }
    }
    color[v] = 2;
    time_out[v] = dfs_timer++;
}

// Purpose: Breadth First Search - find shortest path in unweighted graph
// Time: O(V + E)
void bfs(int start) {
    queue<int> q;
    vector<int> d(adj.size(), -1), p(adj.size(), -1);

    q.push(start);
    visited[start] = true;
    d[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int child : adj[node]) {
            if (!visited[child]) {
                visited[child] = true;
                d[child] = d[node] + 1;
                p[child] = node;
                q.push(child);
            }
        }
    }
}

// Purpose: 0-1 BFS - shortest path in graph with edge weights 0 or 1
// Time: O(V + E)
void bfs01(int start, vector<vector<pair<int, int>>> &graph) {
    int n = graph.size();
    vector<int> dist(n, INF);
    deque<int> q;

    dist[start] = 0;
    q.push_front(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 1) {
                    q.push_back(v);
                } else {
                    q.push_front(v);
                }
            }
        }
    }
}

// Purpose: Find diameter of a tree (longest path)
// Time: O(V + E)
int maxDist = 0, farthest = -1;
vector<vector<pair<int, int>>> tree;

void treeDFS(int u, int parent, int dist) {
    if (dist > maxDist) {
        maxDist = dist;
        farthest = u;
    }
    for (auto [v, w] : tree[u]) {
        if (v != parent) {
            treeDFS(v, u, dist + w);
        }
    }
}

int treeDiameter(int n) {
    maxDist = 0;
    treeDFS(0, -1, 0);
    int u = farthest;
    maxDist = 0;
    treeDFS(u, -1, 0);
    return maxDist;
}


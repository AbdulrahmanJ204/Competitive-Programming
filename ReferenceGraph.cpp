// ============================================================================
//                              GRAPH THEORY
// ============================================================================

// Purpose: Disjoint Set Union (Union-Find) - manage disjoint sets efficiently
// Time: O(α(n)) per operation where α is inverse Ackermann function
struct DSU {
    int cnt;
    vector<int> parent, size;

    DSU(int n) : cnt(n), size(n + 1, 1), parent(n + 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            cnt--;
            if (size[x] < size[y])
                swap(x, y);
            size[x] += size[y];
            parent[y] = x;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int getSize(int x) {
        return size[find(x)];
    }
};
struct DSU {
    int cnt;
    vector<int> p, sz;

    DSU(int n) : cnt(n), sz(n + 1, 1), p(n + 1) {
        for (int i = 0; i <= n; i++)
            p[i] = i;
    }

    int find(int a) {
        return (p[a] == a ? a : find(p[a]));
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            cnt--;
            if (sz[a] > sz[b])
                swap(a, b);
            sz[b] += sz[a];
            sz[a] = 0;
            p[a] = p[b];
        }
    }
};

// Basic Graph Traversal
vector<vector<int>> adj;
vector<bool> visited;

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

// Purpose: Lowest Common Ancestor with Binary Lifting
// Time: O(n log n) preprocessing, O(log n) query

// TO calculate lca of two nodes given the root is R
// calculate LCA for each pair , make XOR for them , you got the LCA
const int LOG = 20;
vector<vector<int>> up;
vector<int> depth;

void lcaDFS(int u, int parent = 0) {
    up[0][u] = parent;
    for (int i = 1; i < LOG; i++) {
        up[i][u] = up[i - 1][up[i - 1][u]];
    }
    for (int v : adj[u]) {
        if (v != parent) {
            depth[v] = depth[u] + 1;
            lcaDFS(v, u);
        }
    }
}

void buildLCA(int n, int root = 1) {
    up.assign(LOG, vector<int>(n + 1));
    depth.assign(n + 1, 0);
    lcaDFS(root);
}

int kthAncestor(int u, int k) {
    if (depth[u] < k)
        return -1;
    for (int i = LOG - 1; i >= 0; i--) {
        if (k & (1 << i)) {
            u = up[i][u];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    u = kthAncestor(u, depth[u] - depth[v]);
    if (u == v)
        return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

int distanceBetween(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
// ============================================================================
//                    LCA USING EULER TOUR + SPARSE TABLE
// ============================================================================

// Purpose: Lowest Common Ancestor using Euler Tour and Sparse Table for RMQ
// Time: O(n) preprocessing, O(1) LCA query
// Space: O(n log n)
// Advantages: Faster queries than binary lifting, good for heavy query workloads

struct LCA_EulerSparse {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> euler_tour, depth, first_occurrence;
    SparseTable<pair<int, int>> st;

    LCA_EulerSparse(int n_) : n(n_), timer(0) {
        adj.resize(n + 1);
        first_occurrence.assign(n + 1, -1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int parent, int d) {
        first_occurrence[u] = euler_tour.size();
        euler_tour.push_back(u);
        depth.push_back(d);

        for (int v : adj[u]) {
            if (v != parent) {
                dfs(v, u, d + 1);
                euler_tour.push_back(u);
                depth.push_back(d);
            }
        }
    }

    void build(int root = 1) {
        euler_tour.clear();
        depth.clear();

        dfs(root, -1, 0);

        // Create array of (depth, node) pairs for RMQ
        vector<pair<int, int>> depth_node_pairs;
        for (int i = 0; i < euler_tour.size(); i++) {
            depth_node_pairs.push_back({depth[i], euler_tour[i]});
        }

        // Build sparse table for RMQ (minimum depth)
        auto minOp = [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first ? a : b;
        };
        st = SparseTable<pair<int, int>>(depth_node_pairs, minOp);
    }

    int lca(int u, int v) {
        int l = first_occurrence[u];
        int r = first_occurrence[v];
        if (l > r)
            swap(l, r);

        return st.query(l, r).second;
    }

    int distance(int u, int v) {
        int lca_node = lca(u, v);
        return depth[first_occurrence[u]] + depth[first_occurrence[v]] -
               2 * depth[first_occurrence[lca_node]];
    }

    bool isAncestor(int u, int v) {
        return lca(u, v) == u;
    }
};

/* USAGE EXAMPLE:
LCA_EulerSparse lca(n);
for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    lca.addEdge(u, v);
}
lca.build(1); // Build with root = 1

int ancestor = lca.lca(u, v);
int dist = lca.distance(u, v);
bool isAnc = lca.isAncestor(u, v);
*/

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

// Purpose: Dijkstra's Algorithm - shortest path in weighted graph
// Time: O((V + E) log V)
vector<ll> dijkstra(int start, int n, vector<vector<pair<int, ll>>> &graph) {
    vector<ll> dist(n, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Purpose: Floyd-Warshall Algorithm - all pairs shortest path
// Time: O(V³)
void floydWarshall(vector<vector<ll>> &dist, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

// Purpose: Kruskal's Minimum Spanning Tree
// Time: O(E log E)
struct Edge {
    int u, v;
    ll w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

pair<ll, vector<Edge>> kruskalMST(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);

    ll totalWeight = 0;
    vector<Edge> mstEdges;

    for (Edge e : edges) {
        if (!dsu.same(e.u, e.v)) {
            dsu.unite(e.u, e.v);
            totalWeight += e.w;
            mstEdges.push_back(e);
        }
    }

    return {totalWeight, mstEdges};
}

// Purpose: Count paths passing through each node in a tree
// Time: O(V)
vector<ll> countPathsThroughNode(int n, vector<vector<int>> &tree) {
    vector<ll> subtreeSize(n + 1, 0);
    vector<ll> pathsThrough(n + 1, 0);
    vector<bool> vis(n + 1, false);

    function<ll(int)> dfs = [&](int u) -> ll {
        vis[u] = true;
        subtreeSize[u] = 1;

        ll totalPairs = 0;
        ll currentSum = 0;

        for (int v : tree[u]) {
            if (!vis[v]) {
                ll childSize = dfs(v);
                totalPairs += currentSum * childSize;
                currentSum += childSize;
                subtreeSize[u] += childSize;
            }
        }

        pathsThrough[u] = totalPairs + (n - subtreeSize[u]) * currentSum;
        return subtreeSize[u];
    };

    dfs(1);
    return pathsThrough;
}
// Purpose: Heavy-Light Decomposition - tree path queries in O(log² n)
// Time: O(n log n) preprocessing, O(log² n) path query/update
struct HLD {
    int n, root, cur_pos;
    vector<vector<pair<int, int>>> adj;
    vector<int> parent, depth, heavy, head, pos;
    vector<ll> base;
    LazySegmentTree<ll> seg;

    HLD() {}
    HLD(const vector<vector<pair<int, int>>> &adj_, int root_ = 0) {
        build(adj_, root_);
    }

    void build(const vector<vector<pair<int, int>>> &adj_, int root_ = 0) {
        adj = adj_;
        n = adj.size();
        root = root_;
        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        base.assign(n + 1, 0);
        cur_pos = 1;

        dfs(root);
        decompose(root, root);

        for (int u = 0; u < n; u++) {
            for (auto [v, w] : adj[u]) {
                if (parent[v] == u) {
                    base[pos[v]] = w;
                }
            }
        }

        seg.init(n);
        seg.build(base);
    }

    int dfs(int v) {
        int size = 1, max_child_size = 0;
        for (auto [c, w] : adj[v]) {
            if (c != parent[v]) {
                parent[c] = v;
                depth[c] = depth[v] + 1;
                int child_size = dfs(c);
                size += child_size;
                if (child_size > max_child_size) {
                    max_child_size = child_size;
                    heavy[v] = c;
                }
            }
        }
        return size;
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = cur_pos++;
        if (heavy[v] != -1)
            decompose(heavy[v], h);
        for (auto [c, w] : adj[v]) {
            if (c != parent[v] && c != heavy[v]) {
                decompose(c, c);
            }
        }
    }

    void updatePath(int u, int v, ll val) {
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);
            seg.update(pos[head[u]], pos[u], val);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        if (u != v)
            seg.update(pos[u] + 1, pos[v], val);
    }

    ll queryPath(int u, int v) {
        ll result = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);
            result += seg.query(pos[head[u]], pos[u]);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        if (u != v)
            result += seg.query(pos[u] + 1, pos[v]);
        return result;
    }
};
// ============================================================================
//                    HEAVY-LIGHT DECOMPOSITION ON NODES
// ============================================================================

// Purpose: HLD on nodes - efficient tree path queries and updates on node values
// Time: O(n log n) preprocessing, O(log² n) path query/update
// Space: O(n)
// Uses: Range queries on tree paths, subtree queries, LCA queries

struct HLD_Nodes {
    int n, root, cur_pos;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, subtree_size;
    vector<ll> node_values;
    LazySegmentTree<ll> seg;

    HLD_Nodes() {}
    HLD_Nodes(int n_, int root_ = 1) : n(n_), root(root_), cur_pos(1) {
        adj.resize(n + 1);
        parent.assign(n + 1, -1);
        depth.assign(n + 1, 0);
        heavy.assign(n + 1, -1);
        head.assign(n + 1, 0);
        pos.assign(n + 1, 0);
        subtree_size.assign(n + 1, 0);
        node_values.assign(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void setNodeValue(int u, ll val) {
        node_values[u] = val;
    }

    void build() {
        dfs_size(root);
        dfs_decompose(root, root);

        // Build segment tree with node values
        vector<ll> seg_array(n + 1, 0);
        for (int u = 1; u <= n; u++) {
            seg_array[pos[u]] = node_values[u];
        }

        seg.init(n);
        seg.build(seg_array);
    }

private:
    int dfs_size(int u) {
        subtree_size[u] = 1;
        int max_child_size = 0;

        for (int v : adj[u]) {
            if (v != parent[u]) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                int child_size = dfs_size(v);
                subtree_size[u] += child_size;

                if (child_size > max_child_size) {
                    max_child_size = child_size;
                    heavy[u] = v;
                }
            }
        }
        return subtree_size[u];
    }

    void dfs_decompose(int u, int h) {
        head[u] = h;
        pos[u] = cur_pos++;

        // Process heavy child first
        if (heavy[u] != -1) {
            dfs_decompose(heavy[u], h);
        }

        // Process light children
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs_decompose(v, v);
            }
        }
    }

public:
    // Update node value
    void updateNode(int u, ll val) {
        seg.set(pos[u], val);
        node_values[u] = val;
    }

    // Add value to node
    void addToNode(int u, ll val) {
        seg.update(pos[u], pos[u], val);
        node_values[u] += val;
    }

    // Update all nodes on path from u to v
    void updatePath(int u, int v, ll val) {
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);
            seg.update(pos[head[u]], pos[u], val);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);
        seg.update(pos[u], pos[v], val);
    }

    // Query sum of all nodes on path from u to v
    ll queryPath(int u, int v) {
        ll result = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);
            result += seg.query(pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);
        result += seg.query(pos[u], pos[v]);
        return result;
    }

    // Update all nodes in subtree of u
    void updateSubtree(int u, ll val) {
        seg.update(pos[u], pos[u] + subtree_size[u] - 1, val);
    }

    // Query sum of all nodes in subtree of u
    ll querySubtree(int u) {
        return seg.query(pos[u], pos[u] + subtree_size[u] - 1);
    }

    // Get node value
    ll getNodeValue(int u) {
        return seg.query(pos[u], pos[u]);
    }

    // LCA using HLD
    int lca(int u, int v) {
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);
            u = parent[head[u]];
        }
        return depth[u] < depth[v] ? u : v;
    }

    // Distance between two nodes
    int distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    // Check if u is ancestor of v
    bool isAncestor(int u, int v) {
        return pos[u] <= pos[v] && pos[v] < pos[u] + subtree_size[u];
    }

    // Kth ancestor of node u (k steps up)
    int kthAncestor(int u, int k) {
        if (depth[u] < k)
            return -1;

        int target_depth = depth[u] - k;
        while (depth[head[u]] > target_depth) {
            u = parent[head[u]];
        }

        // Now u and target are in the same heavy path
        while (depth[u] > target_depth) {
            u = parent[u];
        }
        return u;
    }

    // Find node at distance k from u towards v
    int nodeAtDistance(int u, int v, int k) {
        int lca_node = lca(u, v);
        int dist_u_lca = depth[u] - depth[lca_node];
        int dist_lca_v = depth[v] - depth[lca_node];

        if (k <= dist_u_lca) {
            return kthAncestor(u, k);
        } else if (k <= dist_u_lca + dist_lca_v) {
            return kthAncestor(v, dist_u_lca + dist_lca_v - k);
        } else {
            return -1; // Distance k exceeds path length
        }
    }

    // Get all nodes on path from u to v
    vector<int> getPathNodes(int u, int v) {
        vector<int> path_u_to_lca, path_lca_to_v;
        int lca_node = lca(u, v);

        // Collect nodes from u to lca
        int curr = u;
        while (curr != lca_node) {
            path_u_to_lca.push_back(curr);
            curr = parent[curr];
        }
        path_u_to_lca.push_back(lca_node);

        // Collect nodes from v to lca
        curr = v;
        while (curr != lca_node) {
            path_lca_to_v.push_back(curr);
            curr = parent[curr];
        }

        // Combine paths
        vector<int> full_path = path_u_to_lca;
        reverse(path_lca_to_v.begin(), path_lca_to_v.end());
        full_path.insert(full_path.end(), path_lca_to_v.begin(), path_lca_to_v.end());

        return full_path;
    }
};

/* USAGE EXAMPLE:
HLD_Nodes hld(n, 1); // n nodes, root = 1

// Add edges
for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    hld.addEdge(u, v);
}

// Set initial node values
for (int i = 1; i <= n; i++) {
    int val; cin >> val;
    hld.setNodeValue(i, val);
}

hld.build();

// Operations
hld.updateNode(u, val);           // Set node u to val
hld.addToNode(u, val);           // Add val to node u
hld.updatePath(u, v, val);       // Add val to all nodes on path u-v
hld.updateSubtree(u, val);       // Add val to all nodes in subtree of u

ll path_sum = hld.queryPath(u, v);     // Sum of nodes on path u-v
ll subtree_sum = hld.querySubtree(u);  // Sum of nodes in subtree of u
ll node_val = hld.getNodeValue(u);     // Get value of node u

int lca_node = hld.lca(u, v);          // LCA of u and v
int dist = hld.distance(u, v);         // Distance between u and v
bool is_anc = hld.isAncestor(u, v);    // Check if u is ancestor of v

int kth_anc = hld.kthAncestor(u, k);   // kth ancestor of u
int mid_node = hld.nodeAtDistance(u, v, k); // Node at distance k from u towards v
vector<int> path = hld.getPathNodes(u, v);  // All nodes on path u-v
*/

// Key Differences from Edge HLD:
// 1. Node values instead of edge weights
// 2. Path queries include both endpoints
// 3. Subtree queries include the root of subtree
// 4. More direct node-based operations
// 5. Can handle node updates efficiently

// Applications:
// 1. Sum/Max/Min queries on tree paths (node values)
// 2. Subtree sum/max/min queries
// 3. Node value updates on paths or subtrees
// 4. Tree DP optimization
// 5. Complex tree queries with node attributes

//                              TREE HASHING
// Purpose: Tree Hashing - assign unique hash values to trees for isomorphism
// Time: O(n) per tree hashing
// Uses: Tree isomorphism, finding identical subtrees, tree pattern matching
// Can detect if two trees have the same structure

const ll HASH_BASE = 1000000007;
const ll HASH_MOD = 1000000009;

struct TreeHash {
    int n;
    vector<vector<int>> adj;
    vector<ll> subtree_hash;
    vector<int> subtree_size;

    TreeHash(int n_) : n(n_) {
        adj.resize(n + 1);
        subtree_hash.assign(n + 1, 0);
        subtree_size.assign(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll dfs(int u, int parent) {
        subtree_size[u] = 1;
        vector<ll> child_hashes;

        for (int v : adj[u]) {
            if (v != parent) {
                ll child_hash = dfs(v, u);
                child_hashes.push_back(child_hash);
                subtree_size[u] += subtree_size[v];
            }
        }

        // Sort child hashes to make hash independent of child order
        sort(child_hashes.begin(), child_hashes.end());

        ll hash_val = 1;
        for (ll child_hash : child_hashes) {
            hash_val = (hash_val * HASH_BASE + child_hash) % HASH_MOD;
        }

        // Include subtree size in hash to distinguish trees with same structure but different sizes
        hash_val = (hash_val * HASH_BASE + subtree_size[u]) % HASH_MOD;

        return subtree_hash[u] = hash_val;
    }

    ll getTreeHash(int root = 1) {
        return dfs(root, -1);
    }

    // Get hash of subtree rooted at node u
    ll getSubtreeHash(int u) {
        return subtree_hash[u];
    }

    // Find all nodes with identical subtree structure
    map<ll, vector<int>> groupBySubtreeHash(int root = 1) {
        dfs(root, -1);
        map<ll, vector<int>> groups;

        for (int i = 1; i <= n; i++) {
            groups[subtree_hash[i]].push_back(i);
        }

        return groups;
    }
};

// Advanced Tree Hashing with Node Values
struct TreeHashWithValues {
    int n;
    vector<vector<int>> adj;
    vector<ll> node_values;
    vector<ll> subtree_hash;

    TreeHashWithValues(int n_) : n(n_) {
        adj.resize(n + 1);
        node_values.assign(n + 1, 0);
        subtree_hash.assign(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void setNodeValue(int u, ll val) {
        node_values[u] = val;
    }

    ll dfs(int u, int parent) {
        vector<ll> child_hashes;

        for (int v : adj[u]) {
            if (v != parent) {
                child_hashes.push_back(dfs(v, u));
            }
        }

        sort(child_hashes.begin(), child_hashes.end());

        ll hash_val = node_values[u];
        for (ll child_hash : child_hashes) {
            hash_val = (hash_val * HASH_BASE + child_hash) % HASH_MOD;
        }

        return subtree_hash[u] = hash_val;
    }

    ll getTreeHash(int root = 1) {
        return dfs(root, -1);
    }
};

// Tree Isomorphism Checker
struct TreeIsomorphism {
    static bool areIsomorphic(TreeHash &tree1, TreeHash &tree2, int root1 = 1, int root2 = 1) {
        if (tree1.n != tree2.n)
            return false;

        ll hash1 = tree1.getTreeHash(root1);
        ll hash2 = tree2.getTreeHash(root2);

        return hash1 == hash2;
    }

    // Find all possible roots that make two trees isomorphic
    static vector<pair<int, int>> findIsomorphicRoots(TreeHash &tree1, TreeHash &tree2) {
        vector<pair<int, int>> isomorphic_pairs;

        for (int root1 = 1; root1 <= tree1.n; root1++) {
            ll hash1 = tree1.getTreeHash(root1);

            for (int root2 = 1; root2 <= tree2.n; root2++) {
                ll hash2 = tree2.getTreeHash(root2);

                if (hash1 == hash2) {
                    isomorphic_pairs.push_back({root1, root2});
                }
            }
        }

        return isomorphic_pairs;
    }
};

// Rooted Tree Canonical Hash (independent of root choice for some applications)
struct CanonicalTreeHash {
    int n;
    vector<vector<int>> adj;
    vector<ll> canonical_hash;

    CanonicalTreeHash(int n_) : n(n_) {
        adj.resize(n + 1);
        canonical_hash.assign(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll dfs(int u, int parent) {
        vector<ll> child_hashes;

        for (int v : adj[u]) {
            if (v != parent) {
                child_hashes.push_back(dfs(v, u));
            }
        }

        sort(child_hashes.begin(), child_hashes.end());

        ll hash_val = 1;
        for (ll child_hash : child_hashes) {
            hash_val = (hash_val * HASH_BASE + child_hash) % HASH_MOD;
        }

        return canonical_hash[u] = hash_val;
    }

    // Get the canonical hash by trying all possible roots and taking the lexicographically smallest
    ll getCanonicalHash() {
        ll min_hash = LLONG_MAX;

        for (int root = 1; root <= n; root++) {
            ll hash_val = dfs(root, -1);
            min_hash = min(min_hash, hash_val);
        }

        return min_hash;
    }
};

/* USAGE EXAMPLES:

// Basic tree hashing
TreeHash th(n);
for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    th.addEdge(u, v);
}
ll tree_hash = th.getTreeHash(1);

// Find identical subtrees
auto groups = th.groupBySubtreeHash(1);
for (auto& [hash, nodes] : groups) {
    if (nodes.size() > 1) {
        cout << "Nodes with identical subtrees: ";
        for (int node : nodes) cout << node << " ";
        cout << endl;
    }
}

// Tree isomorphism
TreeHash th1(n1), th2(n2);
// ... add edges ...
bool isomorphic = TreeIsomorphism::areIsomorphic(th1, th2);

// Tree hashing with node values
TreeHashWithValues thv(n);
for (int i = 1; i <= n; i++) {
    int val; cin >> val;
    thv.setNodeValue(i, val);
}
// ... add edges ...
ll hash_with_values = thv.getTreeHash(1);

// Canonical tree hash (root-independent for unrooted trees)
CanonicalTreeHash cth(n);
// ... add edges ...
ll canonical_hash = cth.getCanonicalHash();
*/

// Applications:
// 1. Tree Isomorphism: Check if two trees have the same structure
// 2. Subtree Matching: Find all occurrences of a pattern tree in a larger tree
// 3. Tree Deduplication: Remove duplicate trees from a collection
// 4. Tree Clustering: Group trees by structural similarity
// 5. Tree Caching: Use hash as key to cache results for identical tree structures

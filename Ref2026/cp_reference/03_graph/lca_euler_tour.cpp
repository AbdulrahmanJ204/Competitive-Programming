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


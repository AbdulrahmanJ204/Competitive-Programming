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


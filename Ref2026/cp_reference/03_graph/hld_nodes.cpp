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

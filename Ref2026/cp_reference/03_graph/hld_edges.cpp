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


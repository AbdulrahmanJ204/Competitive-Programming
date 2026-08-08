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


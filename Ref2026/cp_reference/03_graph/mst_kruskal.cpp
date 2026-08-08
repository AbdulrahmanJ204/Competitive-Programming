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


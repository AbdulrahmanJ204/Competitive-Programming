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

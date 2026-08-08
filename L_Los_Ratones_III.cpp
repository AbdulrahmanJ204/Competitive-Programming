#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a *b / gcd(a, b)
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES"
#define cno cout << "NO"
#define oo LLONG_MAX
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int mod = 1e9 + 7;
ll sum(ll x, ll y) { return (x % mod + y % mod) % mod; }
ll mul(ll x, ll y) { return (x % mod * y % mod) % mod; }

#define lft 2 * x, lx, (lx + rx) / 2
#define rt 2 * x + 1, (lx + rx) / 2 + 1, rx

template <typename T>
struct SEG {
    vector<T> tree, lazy;
    T neutral = 0;
    T lazy_neutral = 1;
    int size, n;

    SEG(int n_ = 0) { init(n_); }

    void init(int n_) {
        n = n_;
        size = 1;
        while (size <= n)
            size *= 2;
        tree.assign(2 * size, neutral);
        lazy.assign(2 * size, lazy_neutral);
    }

    T merge(T a, T b) { return a + b; }

    T build(vector<ll> &a, int x = 1, int lx = 1, int rx = -1) {
        if (rx == -1) rx = n;
        if (lx == rx)
            return tree[x] = a[lx];
        return tree[x] = merge(build(a, lft), build(a, rt));
    }

    void push(int x, int lx, int rx) {
        if (lazy[x] == lazy_neutral || lx == rx) return;
        tree[2 * x] = mul(tree[2 * x], lazy[x]);
        tree[2 * x + 1] = mul(tree[2 * x + 1], lazy[x]);
        lazy[2 * x] = mul(lazy[2 * x], lazy[x]);
        lazy[2 * x + 1] = mul(lazy[2 * x + 1], lazy[x]);
        lazy[x] = lazy_neutral;
    }

    T upd(int l, int r, ll val, int x = 1, int lx = 1, int rx = -1) {
        if (rx == -1) rx = n;
        if (r < lx || rx < l) return tree[x];
        if (l <= lx && rx <= r) {
            tree[x] = mul(tree[x], val);
            lazy[x] = mul(lazy[x], val);
            return tree[x];
        }
        push(x, lx, rx);
        return tree[x] = merge(upd(l, r, val, lft), upd(l, r, val, rt));
    }

    T query(int l, int r, int x = 1, int lx = 1, int rx = -1) {
        if (rx == -1) rx = n;
        if (r < lx || rx < l) return neutral;
        if (l <= lx && rx <= r) return tree[x];
        push(x, lx, rx);
        return merge(query(l, r, lft), query(l, r, rt));
    }
};

// HLD struct
struct HLD {
    int n, root, cur_pos;
    vector<vector<pair<int,int>>> adj;
    vector<int> parent, depth, heavy, head, pos;
    vector<ll> base; 
    SEG<int> seg;   // segment tree is now owned by HLD

    HLD() {}
    HLD(const vector<vector<pair<int,int>>> &adj_, int root_ = 0) {
        build(adj_, root_);
    }

    void build(const vector<vector<pair<int,int>>> &adj_, int root_ = 0) {
        adj = adj_;
        n = (int)adj.size();
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

        for (int u = 0; u < n; ++u) {
            for (auto [v, c] : adj[u]) {
                if (parent[v] == u)
                    base[pos[v]] = c;
            }
        }
        seg.init(n);
        seg.build(base);
    }

    int dfs(int v) {
        int size = 1, max_c_size = 0;
        for (auto [c, w] : adj[v]) {
            if (c != parent[v]) {
                parent[c] = v;
                depth[c] = depth[v] + 1;
                int c_size = dfs(c);
                size += c_size;
                if (c_size > max_c_size) {
                    max_c_size = c_size;
                    heavy[v] = c;
                }
            }
        }
        return size;
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = cur_pos++;
        if (heavy[v] != -1) decompose(heavy[v], h);
        for (auto [c, w] : adj[v]) {
            if (c != parent[v] && c != heavy[v])
                decompose(c, c);
        }
    }

    void updatePath(int u, int v, ll val) {
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            seg.upd(pos[head[u]], pos[u], val);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        if (u != v) seg.upd(pos[u] + 1, pos[v], val);
    }

    ll queryPath(int u, int v) {
        ll res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            res = sum(res, seg.query(pos[head[u]], pos[u]));
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        if (u != v) res = sum(res, seg.query(pos[u] + 1, pos[v]));
        return res % mod;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    int root = 0;
    for (int x = 0; x < n; x++)
        if (adj[x].size() == 1) { root = x; break; }

    HLD hld(adj, root);

    while (q--) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        hld.updatePath(u, v, x);
        cout << hld.queryPath(u, v) << endl;
    }
}

int32_t main() {
    InTheNameOfAllah
    solve();
    cendl;
    return 0;
}

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

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
#define cin(v)                        \
    for (ll i = 0; i < v.size(); i++) \
        cin >> v[i];
#define cin1(v, n)             \
    for (ll i = 0; i < n; i++) \
        cin >> v[i];
#define cin2(v, n, m)               \
    for (ll i = 0; i < n; i++)      \
        for (int j = 0; j < m; j++) \
            cin >> v[i][j];
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define cout1(v, n)            \
    for (ll i = 0; i < n; i++) \
        cout << v[i] << ' ';   \
    cendl;
#define cout2(v, n, m)                \
    for (ll i = 0; i < n; i++, cendl) \
        for (int j = 0; j < m; j++)   \
            cout << v[i][j] << ' ';
#define assign1(v, n, value)   \
    for (ll i = 0; i < n; i++) \
        v[i] = value;
#define assign2(v, n, m, value)     \
    for (ll i = 0; i < n; i++)      \
        for (int j = 0; j < m; j++) \
            v[i][j] = value;
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define oo LLONG_MAX
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(L, R) uniform_int_distribution<int>(L, R)(rng);

template <class T>
using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void build(int node, vector<vector<int>> &adj, vector<int> &tree) {
    tree.push_back(node);
    for (int child : adj[node]) {
        build(child, adj, tree);
    }
}
void solve() {
    int q;
    cin >> q;
    vector<pair<int, int>> v;
    map<int, int> mp;
    vector<vector<int>> adj(2e5 + 1);
    int id = 2;
    for (int i = 0; i < q; i++) {
        int op, x;
        cin >> op >> x;
        v.push_back({op, x});
        if (op == 1) {
            adj[x].push_back(id);
            id++;
        }
    }
    vector<int> tree;
    build(1, adj, tree);

    o_set<int> se;
    for (int i = 0; i < tree.size(); i++)
        mp[tree[i]] = i;

    se.insert(0);
    id = 2;
    for (int i = 0; i < q; i++) {
        int op = v[i].first, x = v[i].second;
        if (op == 1)
            se.insert(mp[id]), id++;
        else if (op == 2)
            se.erase(mp[x]);
        else
            cout << se.order_of_key(mp[x]) + 1 << endl;
    }

    return;
}

int32_t main() {
    InTheNameOfAllah;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin>>t;
    while (t--) {

        solve();
        cendl;
    }
    return 0;
}
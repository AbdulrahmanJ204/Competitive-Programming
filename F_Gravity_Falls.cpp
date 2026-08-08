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
struct Node {
    map<int, Node> mp;
    int lv;
    void add(vector<int> &v, int idx = 0) {
        if (idx == v.size())
            return;
        mp[v[idx]].add(v, idx + 1);
    }
    void pr() {
        for (auto &x : mp) {
            cout << " { "<< x.first;
            x.second.pr();
            cout<<" } ";
        }
    }
    // build a map
    // save the level
    // build second map starting from that level;
    // how to build the map?
    // for the smallest element
    //
};
void solve() {
    ll n;
    cin >> n;
    int sz[n];
    vector<vector<int>> v(n);

    Node root;
    for (int i = 0; i < n; i++) {

        cin >> sz[i];
        v[i].resize(sz[i]);
        for (int j = 0; j < sz[i]; j++) {
            cin >> v[i][j];
        }
        v[i].push_back(-1);
        root.add(v[i]);
    }
    root.pr();
    
    // int mx = *max_element(sz , sz+k);
    // vector<int> mn(mx,1e9);

    // for (int i = 0; i < k; i++)
    // {
    //   for (int j = 0; j < v[i].size(); j++)
    //   {
    //     mn[j] = min(v[i][j],mn[j] );
    //   }
    // }
    // int j =0;
    // for (int i = 0; i < k; i++)
    // {
    // }

    // build for smallest start
    // take from begin always
    // when reach -1 , save the level of -1
    // now bulid for smallest on that level
    // repeat
    // i can sort based on first element starting from
    // sort based on what????
    // need map for this structure
    /*
    0 -> 1-> 1 -> -1
               -> 9
          -> 2 -> 2 -> 1-> -1
                    -> 1-> 3
          -> 3 -> 3 -> 2-> 1
      -> 2
      -> 3

    */

    return;
}

int32_t main() {
    InTheNameOfAllah
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
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
#define cyes cout << "Yes"
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
struct DSU {
    int cnt;
    vector<int> p, sz;

    DSU(int n) : cnt(n), sz(n + 1, 1), p(n + 1) {
        for (int i = 0; i <= n; i++)
            p[i] = i;
    }

    int find(int a) {
        return p[a] = (p[a] == a ? a : find(p[a]));
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
    void print() {
        for (int i = 0; i < p.size(); i++) {
            cout << p[i] << " ";
        }
        cendl;
    }
};
vector<int> prevGreater2(int arr[], int n) {
    // Create a stack and push index of first element
    // to it
    stack<pair<int, int>> s;
    s.push({arr[0], 1});

    vector<int> v;
    // Previous greater for first element is always -1.
    v.push_back(0);

    // Traverse remaining elements
    for (int i = 1; i < n; i++) {
        while (s.empty() == false && s.top().first > arr[i])
            s.pop();
        s.empty() ? v.push_back(0) : v.push_back(s.top().second);
        s.push({arr[i], i + 1});
    }
    return v;
}
void solve() {
    ll n;
    cin >> n;
    int a[n+1];
    int pre[n+1] , suf[n+2];
    pre[0] = 1e9;
    for (int i = 1; i <= n; i++)
    {
      cin>>a[i];
      pre[i] = min(a[i] , pre[i-1]);
    }
    suf[n+1] = -1e9;
    
    for (int i = n; i > 0; i--)
    {
      suf[i] = max(a[i] , suf[i+1]);
    }
    for (int i = 2; i <= n; i++)
    {
      if(pre[i-1]> suf[i]){
        cout<<"No";
        return;
      }
    }
    cyes;
    return;

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
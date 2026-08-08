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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(L, R) uniform_int_distribution<int>(L, R)(rng);

void solve() {
    int a, b;
    cin >> a >> b;
    
    if (__builtin_clz(a) > __builtin_clz(b)) {
        cout << -1;
        return;
    } else if (a == b) {
        cout << 0;
        return;
    }
   
    vector<int> ans;
    for (int i = 0; i < 31; i++) {
        int x = 1ll<<i;
        if(x>a) continue;
        if (x&a) continue;
        a^=x;
        ans.push_back(x);
    }
    for (int i = 0; i < 31; i++)
    {
        int x = 1ll <<i;
        if(x>a) continue;
        if(x&b) continue;
        a^=x;
        ans.push_back(x);
    }
    cout<<ans.size()<<endl;
    for(auto x : ans) cout<<x<<' ';
    

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
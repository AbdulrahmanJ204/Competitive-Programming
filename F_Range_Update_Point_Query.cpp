#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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

void solve() {
    ll n, q;
    cin >> n >> q;
    int z = n + 1;
    ll a[z];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    set<int> ind;
    for (int i = 1; i <= n; i++) {
        ind.insert(i);
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            int i = *ind.lower_bound(l);
            while (l <= i && i <= r && ind.size()) {
                int sum = 0;
                int num = a[i];
                while (num) {
                    sum += num % 10;
                    num /= 10;
                }
                a[i] = sum;
                if (a[i] < 10)
                    ind.erase(i);
                if (!ind.size())
                    break;
                auto next = ind.lower_bound(i + 1);
                // if (next == ind.end())
                //     break;
                i = *next;
            }
        } else {
            int x;
            cin >> x;
            cout << a[x] << endl;
        }
    }

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
        // cendl;
    }
    return 0;
}
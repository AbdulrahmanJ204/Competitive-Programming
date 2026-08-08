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
    ll n;
    cin >> n;
    int m;
    cin >> m;
    int st[n + 1], end[n + 1], pre[n + 1];
    assign1(st, n + 1, 0);
    assign1(pre, n + 1, 0);
    assign1(end, n + 1, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        st[l]++;
        end[r]++;
        pre[l]++;
        if (r < n + 1)
            pre[r + 1]--;
    }
    for (int i = 1; i < n + 1; i++) {
        pre[i] += pre[i - 1];
    }
    // cout1(pre ,n+1)
    vector<int> ans(n, -1);
    int idx = max_element(pre, pre + n + 1) - pre;
    bool found = 0;
    // cout<<idx<<endl;
    if (pre[idx] == m) {
        ans[idx - 1] = 0;
        int x = 1;
        for (int i = 1; i <= n; i++) {
            if (i == idx)
                continue;
            ans[i - 1] = x++;
        }

    } else {
        for (int i = 1; i < n; i++) {
            if (!end[i]) {
                ans[i - 1] = 0;
                ans[i] = 1;
                found = 1;
                break;
            }
            if (!st[i + 1]) {
                ans[i - 1] = 1;
                ans[i] = 0;
                found = 1;
                break;
            }
        }
        if (!found) {
            int x[] = {0, 2, 1};
            for (int i = 0; i < 3; i++) {
                ans[i] = x[i];
            }
        }
    }
    int x = *max_element(all(ans)) + 1;
    for (int i = 0; i < n; i++) {
        if(~ans[i]) continue;
        ans[i] = x++;
    }

    for (auto x : ans)
        cout << x << " ";
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
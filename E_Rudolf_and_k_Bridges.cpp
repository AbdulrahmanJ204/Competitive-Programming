#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
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
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

void solve() {
    int n, m, d, k;
    cin >> n >> m >> k >> d;
    ll a[n][m];
    cin2(a,n,m);
    ll dp[n][m];
    multiset<ll> ms;
    for (int row = 0; row < n; row++) {
        ms.clear();
        dp[row][0] = 1;
        ms.insert(1);
        for (int col = 1; col <= d; col++) {
            dp[row][col] = (*ms.begin()) + a[row][col] + 1;
            ms.insert(dp[row][col]);
        }
        for (int col = d + 1; col < m; col++) {
            dp[row][col] = (*ms.begin()) + a[row][col] + 1;
            ms.erase(ms.find(dp[row][col - d - 1]));
            ms.insert(dp[row][col]);
        }
    }
    
    ll col = m - 1;
    ll sum = 0;
    for (int i = 0; i < k; i++) {
        sum += dp[i][col];
        
    }
    
    ll ans = sum, l = 0, r = k;

    while (r < n) {
        sum -= dp[l][col];
        l++;
        sum += dp[r][col];
        r++;
        ans = min(ans, sum);
    }
    
    cout << ans;
    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
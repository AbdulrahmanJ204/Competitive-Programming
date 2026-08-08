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
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define cin(v)                        \
    for (ll i = 0; i < v.size(); i++) \
        cin >> v[i];
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
const int MX = 1e5 + 10;
ll x[MX], h[MX];
ll n;
ll dp[MX][3];
ll fun(int i, int last) {
    if (i == n + 1)
        return 0;
    if (~dp[i][last])
        return dp[i][last];
    ll c1 = 0, c2 = 0, c3 = 0;
    // 0 is stand , 1 to left , 2 to right
    c1 = fun(i + 1, 0);
    if (x[i] + h[i] < x[i + 1])
        c3 = 1 + fun(i + 1, 2);

    if (last != 2) {
        if (x[i] - h[i] > x[i - 1])
            c2 = 1 + fun(i + 1, 1);
    } else {
        if (x[i] - h[i] > x[i - 1] + h[i - 1])
            c2 = 1 + fun(i + 1, 1);
    }

    return dp[i][last] = max({c1, c2, c3});
}
void solve() {
    cin >> n;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = 0;

    x[0] = -1e10;
    h[0] = -1e10;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> h[i];
    }
    x[n + 1] = 1e18;
    dp[n + 1][0] = dp[n + 1][1] = dp[n + 1][2] = 0;
    for (int i = n; i >= 1; i--) {
        ll c1= dp[i+1][0];
        ll c3=0,c2=0;
        if (x[i] + h[i] < x[i + 1])
        c3 = 1 + dp[i+1][2];
         if (x[i] - h[i] > x[i - 1])
            c2 = 1 + dp[i+1][1];
        dp[i][0]=max({c1,c2,c3});
        dp[i][1]=max({c1,c2,c3});
        c2=0;
        if(x[i] - h[i] > x[i - 1] + h[i - 1])
            c2 = 1 + dp[i+1][1];
        dp[i][2]=max({c1,c2,c3});
    
    }
    ll ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, dp[1][i]);
    }
    // cout << fun(1, 1);
    // for(int j=0;j<3;j++)
    // {
    // for(int i=0;i<=n;i++)
    //      cout<<dp[i][j]<<"  ";
    //      cout<<endl;
    //      }

    cout << ans;

    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
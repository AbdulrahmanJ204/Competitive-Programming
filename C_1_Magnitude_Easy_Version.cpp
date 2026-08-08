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
const ll M = 2e5 + 10;
ll a[M];
ll n;
ll dp[M][2];
// ll fun(int i, bool x) {
//     if (i == 0)
//         return x?abs(a[i]): a[i];
//     if(dp[i][x]!=-1e18) return dp[i][x];    
//     ll c1= min(fun(i-1, 0)+a[i], fun(i-1,1) + a[i])    ;
//     ll c2= max(abs(fun(i-1, 0)+a[i]),abs (fun(i-1,1) + a[i]))    ;
//     dp[i][x]= x? c2 : c1;
//     return dp[i][x];
// }

void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        }
    dp[0][0]=a[0];
    dp[0][1]=abs(a[0]);
    for (int i = 1; i < n; i++)
    {
        dp[i][0]=min(dp[i-1][0]+a[i], dp[i-1][1]+a[i]);
        dp[i][1]=min(dp[i-1][0]+a[i], dp[i-1][1]+a[i]);
    }
    
   
   
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
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
const int N = 1e5 + 10;
ll n;
ll a[N][2];
ll dp[N][2];
ll fun(int i, int last) {
if(i==n) return 0;
if(dp[i][last]!=-1) return dp[i][last];
int index=(last+1)%2;
ll c1=a[i][index] + fun(i+1,index);
ll c2=fun(i+1,last);
return dp[i][last]= max(c1,c2);

}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 2; j++)
        dp[i][j]=-1;
      
      
    for (int i = 0; i < n; i++)
        cin >> a[i][0];

    for (int i = 0; i < n; i++)
        cin >> a[i][1];
    cout<<max(fun(0,0),fun(0,1));
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
#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
const int N=1e5+1000;
ll dp[N][3];
ll x[100110],h[100110];
ll mx;
ll solve(ll i,ll last_state) {
    if (i > mx)
        return 0;
    if (dp[i][last_state] != -1) return dp[i][last_state];
    ll c1,c2=-1e9;ll c3=-1e9;
        c1 = solve(i + 1, 0);
        if (last_state == 2) {
            if (x[i] - h[i] > x[i - 1] + h[i - 1])
                c2 = 1+solve(i+1,1);
        } else if (x[i] - h[i] > x[i - 1])
            c2 = 1 + solve(i + 1, 1);
        if (x[i] + h[i] < x[i + 1])
           c3 = 1 + solve(i + 1, 2);
    return dp[i][last_state]=max({c1,c2,c3});
}

int main() {
    InTheNameOfAllah
    for (ll i = 0; i < N; ++i)
        for (ll j = 0; j < 3; ++j)
                dp[i][j]=-1;
    ll n;
    cin>>n;
    mx=n;
    x[0]=-1e9-10;
    h[0]=-1e9-10;
    for (int i = 1; i <= n; ++i) {
        cin>>x[i]>>h[i];
    }
    x[n+1]=1e18;
    ll ans=0;
    solve(1,0);
//    for (int i = 0; i <= n; ++i) {
//        cout<<"tree : "<<i<<endl;
//        for (int j = 0; j < 3; ++j) {
//            for (int k = 0; k < 3; ++k) {
//                cout<<dp[i][k][j]<<' ';
//            }
//            cendl;
//        }
//       cendl;cendl;
//    }
    for (int i = 0; i < 3; ++i)
            ans=max(ans,dp[1][i]);


    cout<<ans<<endl;
    return 0;
}
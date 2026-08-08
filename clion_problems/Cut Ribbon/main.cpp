#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
ll dp[4010];
ll n,a,b,c,k=0;
ll solve(ll len)
{  // cout<<len<<' '<<i<<endl;
    if(len<0)
        return -1e9;
    if(len==0)
        return 0;

    if(dp[len]!=-1)
        return dp[len];
    ll a1=solve(len-a);
    ll b1=solve(len-b);
    ll c1=solve( len-c);
    dp[len]=max({a1,b1,c1})+1;
    return dp[len];

}
int main() {
    InTheNameOfAllah
    cin>>n>>a>>b>>c;
    for (ll i = 0; i < 4010; ++i) {
        dp[i]=-1;
    }
    dp[0]=0;
    cout<<solve(n)<<endl;
//    for (ll k = 0; k <= n; ++k) {
//        cout<<k<<' ';
//    }cendl;
//    for (ll j = 0; j <= n; ++j) {
//        cout<<dp[j]<<' ';
//    }
    return 0;
}
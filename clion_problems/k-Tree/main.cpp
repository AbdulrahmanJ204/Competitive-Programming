#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int n,k,d;
const int N=10000;
ll dp[N][2];

ll mod=1e9+7;
ll solve(ll sum,int dd)
{   //cout<<sum<<endl;


    if(sum>n)
        return 0;

    if (sum == n&&dd)
        return 1;
     if(dp[sum][dd]!=-1)
         return dp[sum][dd];
     ll ans=0;

    for (int j = 1; j <= k; ++j) {
        if(j>=d) dd=1;
        dp[sum+j][dd]=solve(sum+j,dd)%mod;
        ans+= dp[sum+j][dd];
        ans%=mod;
        //cout<<ans<<endl;
    }
    return ans;

}
int main() {
    InTheNameOfAllah
    cin >> n >> k >> d;
    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < 2; ++i) {
            dp[j][i] = -1;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= k; ++i) {
        int x = 0;
        if (i >= d)
            x = 1;
        ans += (solve(i, x) % mod);
        ans %= mod;
    }
    cout << ans;
    return 0;
}
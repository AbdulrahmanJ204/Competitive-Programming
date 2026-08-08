#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
const int N=2e5+100;
ll dp[N];
ll mx;
ll a[N];
ll solve(int i)
{
    if(i>=mx)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    ll c1;
    c1=solve(i+a[i])+a[i];
    return dp[i]=c1;

}
int main() {
    InTheNameOfAllah
    test {
    int n;
    cin>>n;mx=n;
        for (int i = 0; i < N; ++i) {
            dp[i]=-1;
        }

        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        ll ans=-1e9;
        for (int i = 0; i < n; ++i) {
            ans=max(solve(i),ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
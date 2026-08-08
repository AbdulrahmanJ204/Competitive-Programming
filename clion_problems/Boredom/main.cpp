#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
const int N= 1e5 + 2;
ll dp[N], a[N];
ll mx=0;
ll solve(ll i)
{  //cout<<i<<endl;
    if(i>mx)
    return 0;
    if(dp[i]!=-1)
        return dp[i];

   ll c1=a[i]+solve(i+2);
   ll c2=a[i+1]+solve(i+3);
 // cout<<c1<<' '<<c2<<' '<<endl;
   return dp[i]=max(c1,c2);
}
int main() {
    InTheNameOfAllah
    int n;
    cin>>n;
    for (int i = 0; i <N ; ++i) {
        a[i]=0;
        dp[i]=-1;
    }
    ll s[n];
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
        mx=max(s[i],mx) ;
        a[s[i]]++;
    }
    a[0]=0;
    for (int i = 0; i <N ; ++i) {
        a[i]*=i;
    }
 //   for (int j = 0; j <= mx+1; ++j) {
 //   cout<<a[j]<<' ';
//    }cendl;
//cendl;
    cout<<solve(1)<<endl;
 //   cendl;
 //   for (int i = 0; i <=mx ; ++i) {
  //      cout<<dp[i]<<" ";
  //  }cendl;
    return 0;
}
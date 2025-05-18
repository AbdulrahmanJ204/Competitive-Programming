#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"
#define cno cout<<"NO"
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define cin1(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define cin2(v,n,m) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) cin>>v[i][j];
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
ll n , k;
const int z=1e5+10;
ll a[z];
ll dp[z];
ll fun(int i = 0){
  if(i==n-1) return 0;
  if(~dp[i]) return dp[i];
  ll c1=1e18,c2=1e18;
  for (int j = 1; j <= k; j++)
  {

  if(i+j>=n) break;
  c1=abs(a[i]-a[i+j])+ fun(i+j);
  c2=min(c1,c2);  
  }
  
  
  return dp[i]= min(c1,c2);
}

void solve()
{
    cin>>n>>k;
    cin1(a,n);
    // assign1(dp,n,-1);
    dp[n-1]=0;
    for (int i = n - 2; i >= 0; i--)
    {
      for (int j = 1; i+j < n; j++)
      {
        dp[i]=min(abs(a[i]-a[j])+dp[i+j],dp[i]);
      }
      
    }
    cout<<dp[0];
    // cout<<fun();
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
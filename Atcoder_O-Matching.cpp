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
ll n;
const int q=22;
const int z=1<<q;
int graph[q][q];
ll mod=1e9+7;
ll dp[q][z];
ll fun(int man, int mask){
  if(mask==(1<<n)-1) return 1;
  if(~dp[man][mask]) return dp[man][mask];
  ll ans=0;
  for (int i = 0; i < n; i++)
  {
    if(graph[man][i]&&!((1<<i)&mask)){
      ans+=fun(man+1,(1<<i)|mask)%mod;
      ans%=mod;
    }
  }
  return dp[man][mask]= ans;
}
void solve()
{
    cin>>n;
    cin2(graph,n,n);
    assign2(dp,n,1<<n,-1);
    ll ans=fun(0,0);
    
    cout<<ans;
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
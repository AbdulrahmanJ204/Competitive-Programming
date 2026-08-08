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
ll n,m,k;
const int Q=18;
const int Z= (1<<Q);
ll a[Q];
ll dp[Q][Z];
ll mp[Q][Q];
// int getNumberOfOnes(int number){
//   int ans=0;
//   for (int i = 0; i < 19; i++)
//     if((1 << i) & number) ans++;

//   return ans;
// }

ll fun(int dish, int mask){
  if(__builtin_popcount(mask)==m)
   return a[dish];
  if(~dp[dish][mask]) return dp[dish][mask];
  
  
  ll mx=0;
  for (int i = 0; i < n; i++)
    if(!(mask&(1<<i))){
      ll x=mp[dish][i]+a[dish];
      mx=max(mx,x+fun(i,mask|(1<<i)));
      }
  
  return dp[dish][mask]= mx;
}
void solve()
{
    cin>>n>>m>>k;
    cin1(a,n);
    assign2(mp,n,n,0);
    for (int i = 0; i < k; i++)
     {
      ll x,y,c;
      cin>>x>>y>>c;
      mp[x-1][y-1]=c;
     }
     ll ans=0;
      assign2(dp,n,(1<<n),-1);
    for (int i = 0; i < n; i++)
    {
      ans=max(ans,fun(i,(1<<i)));
      
    }
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
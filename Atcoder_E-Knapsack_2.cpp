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
const int z=110,y=100010;
ll a[z][2];
ll n,w;
ll totalValue=0;
ll dp[z][y];
ll fun(int i, int curValue){
if(i==n)
return (!curValue ? 0 : 1e18);
if(~dp[i][curValue])return dp[i][curValue];
ll c= fun(i+1,curValue);
if(curValue>=a[i][1])
c= min(c,a[i][0]+fun(i+1,curValue-a[i][1]));
return dp[i][curValue]=c;
}
void solve()
{
    cin>>n>>w;
    cin2(a,n,2);
    totalValue=0;
    
    for (int i = 0; i < n; i++)
      totalValue+=a[i][1];
    assign2(dp,n,totalValue+1,-1);
    ll ans=0;
    while(totalValue>=0){
      if(fun(0,totalValue)<=w){
        ans=totalValue;
        break;
      }  
      totalValue--;
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
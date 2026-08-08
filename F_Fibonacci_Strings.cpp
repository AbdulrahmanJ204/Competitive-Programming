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
const int z=0;
ll maxX=1000 , maxK=1e18;
void solve()
{
    
    vector<ll> dp(maxX);
    string s[3];
    ll x, k;
    cin>>dp[1]>>dp[2];
    cin>>s[0]>>s[1];
    cin>>x>>k;
    s[2]=s[1]+s[0];
    for (int i = 3; i < 1001; i++)
      dp[i]=min(dp[i-1]+dp[i-2],maxK);
    if(x==1){
      cout<<s[x-1][k-1];
      return;
    }
    while(k>dp[3]){
      ll l=2 , r=x;
      while(r-l>1){
        ll mid=(l+r)/2;
        if(k>dp[mid]){
          l=mid;
        }else r=mid;
      }
    k-=dp[l];
    }
    cout<<s[2][k-1];
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
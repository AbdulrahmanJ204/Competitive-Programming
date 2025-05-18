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
const int z=1e3+10;
ll n,m,mod=1e9+7;
string s[z];
ll dp[z][z];
bool isValid(int i, int j){
  if(i>=n||i<0||j>=m||j<0) return false;
  return s[i][j]=='.';
}

ll fun(int i = 0, int j = 0){
  if(!isValid(i,j)) return dp[i][j] = 0;
  if(i==n-1&&j==m-1) return dp[i][j]= 1;
  if(~dp[i][j]) return dp[i][j];
  ll c1= fun(i+1,j)%mod+fun(i,j+1)%mod;
  c1%=mod;
  return dp[i][j]=c1;
}
void solve()
{
    cin>>n>>m;
    cin1(s,n);
    assign2(dp,n,m,-1);
    cout<<fun()%mod;
    

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
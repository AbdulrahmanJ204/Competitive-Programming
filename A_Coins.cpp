#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
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
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
const int z =151 , y = 30100;
ll n,m,k,w;
ll a[z], b[z];
// ll dp[z][z][y];
ll mod  = 1e9 + 7;
ll fun(int i , int j , int sum){
  if(i==n || j==m) return sum<=k;
  
  ll c1= fun(i+1, j , sum+a[i]);
  ll c2= fun(i+1 ,j , sum);
  ll c3 = fun(i+1 , j+1 , sum);
  ll c4 = fun(i+1 , j+1 , sum+a[i]-b[j]);
  ll c5 = fun(i , j+1 , sum-b[j]);
  ll c6 = fun(i , j+1 , sum);
  return c1 + c2 + c3 + c4 + c5 + c6 ;
}


void solve()
{
    cin>>n>>m>>k>>w;
    cin1(a,n);
    cin1(b,m);
    k+=15000;
    for (int i = 0; i < n; i++)
      a[i]+=15000 , b[i]+=15000;
    cout<<fun(0,0,0);
    

  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
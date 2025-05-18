#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
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
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    cin1(a,n);
    ll gc=a[0];
    for (int i = 1; i < n; i++) gc=__gcd(gc,a[i]);
    if(n==1){
      cout<<(k<=a[0] ? k-1: k);
      return;
    }
    ll mxkInArr = (n-1)*(gc-1);
    if(mxkInArr<k){
     cout<<gc*(n-1)+(k-mxkInArr);
     return;
    }  
    ll temp=k/(gc-1), mod=k%(gc-1);
    if(!mod) mod=gc-1, temp--;
    ll ans=temp*gc + mod;
    cout<<ans;
  return;
}

int32_t main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
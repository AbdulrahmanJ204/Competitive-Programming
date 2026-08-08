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

void solve()
{
    ll n;
    cin>>n;
    ll a[n][2];
    map<pair<ll,ll> , ll  > mx;
    
    ll zeros=0, ones=0;
    for (int i = 0; i < n; i++)
    {
      int x,y;
      cin>>x>>y;
      if(y) ones++;
      else zeros++;
      mx[make_pair(x,y)]++;
    }
    ll ans=0;
    for(auto &pt : mx){
    ll x=pt.first.first,y=pt.first.second;
    ll nextY=(y+1)%2;
    if(mx.count(make_pair(x,nextY)) )
    ans+=zeros+ones-2; 

    } 
    ans/=2;
    for(auto &pt : mx){
    ll x=pt.first.first,y=pt.first.second;
    ll nextY=(y+1)%2;
    if(mx.count(make_pair(x+1,nextY))&&mx.count(make_pair(x-1,nextY))) ans++;
    }
    cout<<ans;
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
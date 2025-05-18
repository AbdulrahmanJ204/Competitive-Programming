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
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n,m;
    cin>>n>>m;
    int x,y ,k;
    cin>>x>>y>>k;
    int a[k] , b[k];
    int ans=0;
    for (int i = 0; i < k; i++)
    {
      cin>>a[i]>>b[i];
      int can = 0, canX = 0, canY = 0;
      if(!a[i] && !b[i]);
      else if (!a[i]) { 
          canY = (b[i] > 0 ? (m - y) : y - 1) / b[i];
          can = abs(canY);
      } else if (!b[i]) {
          canX = (a[i] > 0 ? (n - x) : x - 1) / a[i];
          can = abs(canX);
      } else {
          canX = (a[i] > 0 ? (n - x) : x - 1) / a[i],
          canY = (b[i] > 0 ? (m - y) : y - 1) / b[i];
          can = min(abs(canX), abs(canY));
      }
      x+= can * a[i];
      y+= can * b[i];
      ans+= can;
    }
    cout<<ans;
    

  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
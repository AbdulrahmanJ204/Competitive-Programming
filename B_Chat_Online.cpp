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
const int MX = 100;
int a[MX] , b[MX] , c [MX]  , d[MX] ;
ll n ,m , l , r;
bool checkFor(int t){
  for (int i = 0; i < n; i++)
  {
    int l1 = a[i] , r1 = b[i];
    for (int j = 0; j < m; j++)
    {
      int l2 = c[j]+t , r2 = d[j]+t;
      if((l2 > r1 || r2 < l1)) continue;
      return true;
    }
    
  }
  return false;
}
void solve()
{
    cin>>n>>m>>l>>r;
    for (int i = 0; i < n; i++)
    {
      cin>>a[i]>>b[i];
    }
    
    for (int i = 0; i < m; i++)
    {
      cin>>c[i]>>d[i];
    }
    int ans=0;
    for (int t = l; t < r+1; t++)
    {
      if(checkFor(t)) ans++;

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
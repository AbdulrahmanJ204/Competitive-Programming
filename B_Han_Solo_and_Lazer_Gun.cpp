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

void fun(ll &a, ll &b) {
 
  if (a * b < 0) {
      a = -abs(a);
      b = abs(b);
  } else if (a * b > 0) {
      a = abs(a);
      b = abs(b);
  } else {
    if(b) b=1e6;
    if(a) a=1e6;
  }
  ll gc = __gcd(abs(a), abs(b));
  if (gc)
      a /= gc, b /= gc;
}
void solve()
{
    ll n, x0 , y0;
    cin>>n>>x0>>y0;
    set<pair<ll,ll>> st;
    for (int i = 0; i < n; i++)
    {
      ll x ,y;
      cin>>x>>y;
      // x+=1e4 , y+=1e4;
      x -= x0 , y-=y0;
      fun(x , y);
      st.insert({x,y});
    }
    cout<<st.size();
    
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
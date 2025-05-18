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
#define rep(i , from , to) for(int i = from ; i < to ;i++)
#define repR(i , from , to) for(int i = from ; i >= to ;i--)
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    cin1(a,n);
    ll mx=*max_element(a,a+n);
    multiset<ll> st;
    rep(i , 0 , n){
      st.insert(a[i]);
    }
    ll gc=mx-a[0];
    ll ans=0;
    rep(i,0,n)
    {
      gc=__gcd(mx-a[i], gc);
    }
    rep(i,0,n)
    {
      if(mx!=a[i])
      ans+=(mx-a[i])/gc;
    }
    ll extra=n;
    ll temp=mx;
    int cnt=0;
    while(cnt<n){
      temp-=gc;
      cnt++;
      if(!st.count(temp)){
        extra=min(extra,cnt);
        break;
      }
    }
    cout<<ans+extra;
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
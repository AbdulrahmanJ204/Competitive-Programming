#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define i128 __int128_t
#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define gcd(a ,b) __gcd(a,b)
#define lcm(a,b) a/gcd(a,b)*b
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(L,R) uniform_int_distribution<int>(L, R)(rng);

template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    cin1(a,n);
    ll mx= *max_element(all(a));
    
    
    vector<int> mp(mx+1 , 0);
    for (int i = 0; i < n; i++)
    {
      mp[a[i]]++;
    }
    vector<int> d1(mx+1,1e9), d2(mx+1,1e9);
    
    for (ll k = 1; k <= mx; ++k)
    for (ll j = k; j <= mx; j += k)
    {
      if(mp[j]){
        if(j<d1[k]) {
        d2[k] = d1[k] ;
        d1[k]=j;
        }
        else if(j<d2[k]) d2[k] = j;
        if(mp[j]>1){
              if(j<d1[k]) {
        d2[k] = d1[k] ;
        d1[k]=j;
        }
        else if(j<d2[k]) d2[k] = j;
        }
      }  
    }  
    // cout1(d1,mx+1);
    // cout1(d2,mx+1);
    ll mnLCM = LONG_LONG_MAX, f = -1;
    for (int k = 1; k <= mx; ++k){
      if(d1[k] == 1e9||d2[k] == 1e9)continue;  
        ll lc = lcm(d1[k] ,d2[k]);
        if(lc < mnLCM){
          mnLCM = lc;
          f = k;
        }
      
    }
    // cout<<mnLCM<<" "<<f<<" "<<endl;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      if(a[i]==d1[f]){
        ans.push_back(i+1);
        a[i] = -1;
        break;
      }
    }
    for (int i = 0; i < n; i++)
    {
      if(a[i]==d2[f]){
        ans.push_back(i+1);
        break;
      }
    }
    sort(all(ans));
    tryAndCry(ans);

  return;
}

int32_t main() {
    InTheNameOfAllah;
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
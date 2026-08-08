#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define gcd(a ,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
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
int mod = 998244353;


ll mul(ll x, ll y) { return (x % mod * y % mod) % mod; }
void solve()
{
    ll n;
    cin>>n;
    int a[n];
    cin1(a,n);
    map<int,int> mp;
    map<int,int> v;

    for (int i = 0; i < n; i++)
    {
      int sq= sqrtl(a[i]) , cb = cbrtl(a[i]);
      if(cb*cb*cb == a[i]){
        mp[cb]+=3;
      }
      else if(sq * sq == a[i]){
          int sqq = sqrtl(sq);
          if(sqq*sqq==sq){
            mp[sqq]+=4;
          }
          else mp[sq]+=2;
      }
      else{
        v[a[i]]++;
        
      }
    }
    for (auto y : v){
      int x = y.first;
      for (int i = 0; i < n; i++)
      { 
        int gc = gcd(x , a[i]);
        if( gc> 1 && a[i]!=x){
          int rm = x / gc;
          mp[gc]+=v[x];
          mp[rm]+=v[x];
          v[x] = 0;
          break;
        }    
      }
    }
    
    
    int ans =1;
    for(auto y : v){
     if(!y.second) continue;
    //  if(y.second > 1)
    // cout<<y.first<<" "<<y.second<<endl;
        y.second++, y.second *= y.second;
     ans = mul(ans , y.second );
   }
    
    
    for(auto x : mp) ans = mul(ans , x.second + 1);
    cout<<ans;

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
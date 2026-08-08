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
vector<int> v;
void sieve(ll n) {
    vector<bool> flg(n + 1, true);
    flg[0] = flg[1] = 0;
    for (ll p = 2; p <= n; p++)
        if (flg[p]) {
            v.push_back(p);
            for (ll i = p * p; i <= n; i += p)
                flg[i] = 0;
        }
}
void solve()
{
    ll n;
    cin>>n;
    vector<int> a(n);
    cin1(a,n);
    sort(all(a));
    vector<int> b(a);
    unq(b);
    if(b.size()<a.size()){
      if(a.back() != 1)
      cyes;
      else cno;
      return;
    }
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        int ai = a[i];
        for(int p : primes){
          if(ai%p) continue;
          if(p * p > ai) break;
          if(mp[p]){
            cyes;
            return;
          }
          
        }
    }
    
    
    
   

  return;
}

int32_t main() {
    InTheNameOfAllah;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieveFactorization();
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
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

int mod = 1e9 + 7;
ll sum(ll x, ll y) { return (x % mod + y % mod) % mod; }

ll sub(ll x, ll y) { return (x % mod - y % mod + mod) % mod; }

ll mul(i128 x, i128 y) { 
    // __int128_t
    return (x % mod * y % mod) % mod; }
long long fastPower(ll base, ll exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = mul(result, base) % mod;
        }
        base = mul(base, base) % mod;
        exponent /= 2;
    }
    return result % mod;
}

int inv_mod(int a) {
    return fastPower(a, mod - 2);
}

ll sumRange(ll l, ll r) {
    int len = r - l + 1;
    int sm = l + r;

    if (len % 2 == 0)
        len /= 2;
    else
        sm /= 2;
    return mul(len, sm);
}
void solve()
{
    ll n;
    cin>>n;
    
    
    
    int res = n;
    int cur =0 , pre = 0;

    int i;
    for (i = 2; i * i <= n; i++) {
        cur = n / i, pre = n / (i - 1);
        cur = sum(cur, mul((i - 1), sumRange(cur, pre)));
        res = sum(res, cur);
    }
    if(n/i== i-1){
      res= sum(mul( n/i , i), res);
    }
   
    cout<<res;
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
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
vector<vector<int>> factors;
void sieveFactorization(int N) {
    factors.resize(N + 1,vector<int>());
    for (int i = 2; i <= N; ++i) {
        if (factors[i].empty()) { // If i is prime
            for (int j = i; j <= N; j += i) {
                factors[j].push_back(i);
            }
        }
    }
    // O N*logN

}
void getFactors(int n , map<int,map<int,int>> &mp){
  int orig = n;
  for(int f : factors[orig]){
    while(n%f == 0)
    mp[orig][f]++, n/=f;
    
  }
} 
int mod = 1e9 + 7;
ll mul(ll x, ll y) { return (x % mod * y % mod) % mod; }

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
void solve()
{
    ll n;
    cin>>n;
    sieveFactorization(n+1);
    int a[n];
    cin1(a,n);
    vector<bool> taken(n);
    set<int> st;
    for (int i = 0; i < n; i++)
      a[i]--;
    for (int i = 0; i < n; i++)
    {
      int idx = i;
      int cnt =0;
      while(!taken[idx]){
        taken[idx] = true;
        idx= a[idx];
        cnt++;
      } 
      if(cnt) st.insert(cnt);
    }
    if(st.size()==1){
      cout<<*st.begin();
      return;
    }
    map<int,map<int,int>> mp;
    for(int x : st) getFactors(x , mp);
    map<int,int> mxP;
    for (int i = 0; i < n; i++)
    {
      for(auto x : mp[a[i]]) mxP[x.first] = max(mxP[x.first] , x.second);
    }
    
    int ans =1;
    for(auto& x : mxP) {
      
       ans =mul(ans, fastPower(x.first, x.second));
       
      
    }
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
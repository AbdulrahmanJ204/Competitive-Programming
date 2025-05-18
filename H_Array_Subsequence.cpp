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
  #define oo  LLONG_MAX;
  #define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

  ll sum(ll x, ll y, ll mod) { return (x % mod + y % mod) % mod; }

  ll sub(ll x, ll y, ll mod) { return (x % mod - y % mod + mod) % mod; }

  ll mul(ll x, ll y, ll mod) { return (x % mod * y % mod) % mod; }

  long long fastPower(ll base, ll exponent, ll mod) {
      long long result = 1;
      while (exponent > 0) {
          if (exponent % 2 == 1) {
              result = mul(result, base, mod) % mod;
          }
          base = mul(base, base, mod) % mod;
          exponent /= 2;
      }
      return result % mod;
  }

  int inv_mod(int a, ll mod) {
      return fastPower(a, mod - 2, mod);
  }

  ll div(ll a, ll b , int mod) {
    // int mod = MOD;
    return a * inv_mod(b, mod) % mod; }
  ll pow(ll x, ll n, ll mod) {
      x %= mod;
      ll res = 1;
      while (n) {
          if (n % 2) {
              res = res * x % mod;
          }
          n /= 2;
          x = x * x % mod;
      }
      return res;
  }

  ll inverse_mod(ll x, ll mod) {
      x %= mod;
      return pow(x, mod - 2, mod);
  }
  const int MOD = 1e9 + 7;
  const int N = 5e5;
  ll fact[N], inv[N];
  void pre() {
      fact[0] = 1;
      inv[0] = inverse_mod(fact[0], MOD);
      for (ll i = 1; i < N; i++) {
          fact[i] = fact[i - 1] * i % MOD;
          inv[i] = inverse_mod(fact[i], MOD);
      }
  }

  ll nCr(ll n, ll r) {
      if (n < r)
          return 0;
      return fact[n] * inv[n - r] % MOD * inv[r] % MOD;
  }



  const int z = 5e5+10;
  int a[z];

  void solve()
  {

    int n, k;
    cin>>n>>k;
    cin1(a,n);
    map<int,int> mp;  
    sort(a, a+n);
    int mx[n] , mn [n];
    int mod = 1e9+7;
    for (int i = 0; i < n; i++)
    {
      mn[i]=mul(nCr(n-i-1 , k-1),a[i], mod);
      mx[i]=mul(nCr(i , k-1) ,a[i], mod);
    }
    
    // cout1(mn, n);
    // cout1(mx, n);
  ll ans=0;
  for (int i = 0; i < n; i++)
  {
    ans =sum(ans, sub(mx[i],mn[i], mod) , mod);
  }

  cout << div(ans, nCr(n,k) , mod);


    return;
  }

  int32_t main() {
      InTheNameOfAllah
      //freopen("input.txt", "r", stdin);
      //freopen("output.txt", "w", stdout);
      pre();
      ll t=1;
      cin>>t;
      while(t--){
        solve();
        cendl;
      }
      return 0;
  }
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
vector<long long> primeFactors(long long n) {
    vector<long long> factorization;
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
int gcd(vector<int> &numbers) {
    return accumulate(numbers.begin(), numbers.end(), 0,
                      [](int x, int y) { return __gcd(x, y); });
}
void solve()
{
    ll n;
    cin>>n;
    set<int> st;
    ll ans= 1;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin>>x;
      st.insert(x);
      
    }
    // tryAndCry(st);
    vector<int> vv;
    for(auto x : st) vv.push_back(x);
    int gc= gcd(vv);
    if(gc>1) {
      cout<<gc;
      return;
    }
    set<int> factors;
    for(ll x : st){
      if(x%2==0){
        factors.insert(2);
        continue;
      }
      vector<int> v= primeFactors(x);
      for(ll y : v){ factors.insert(y); break;}
    }
    
    for(ll x : factors) ans*=x;
    tryAndCry(factors);
    // for(ll x : st)
    // {
    //   cout<<__gcd(x , ans)<<endl;
    // }
    cout<<ans;
  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
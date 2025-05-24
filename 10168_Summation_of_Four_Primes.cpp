#include <bits/stdc++.h>
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
const ll maxn = 10000002;

vector<int> primeNumbers(maxn, 0);
void sieve(ll n = maxn) {
  vector<int> primes(maxn, 1);
    primes[0] = primes[1] = 0;
    primeNumbers[0] =0 ,  primeNumbers[1] = 1;
    for (ll p = 2; p <= n; p++)
    if (primes[p]) {
      primeNumbers[p] = p;
      for (ll i = p * p; i <= n; i += p)
      primes[i] = 0;
    }
    int prePrime = 3;
    for (ll p = 4; p <= n; p++)
    if(primeNumbers[p]) prePrime =primeNumbers[p];
    else primeNumbers[p] = prePrime;
        
}

void solve()
{
    ll n;
    while(cin>>n)
    {
      if(n<8){
        cout<<"Impossible.";
      }else{
        for (int i = 3 ; i >= 0; i--)
        {
          int lastPrime = primeNumbers[n - (i*2)];
          cout<<lastPrime<<' ';
          n-=lastPrime;
        }
        
      }
      cendl;
    }
  return;
  
}


int32_t main() {
    InTheNameOfAllah
    sieve();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
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
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

const int mod = 1e9 + 7 , N = 2e5+10;
ll factorial[N];
ll fp(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll cur = fp(x, y / 2);
    return (((cur * cur) % mod) * (y % 2 ? x : 1)) % mod;
}

ll ModInv(ll x)
{
    return fp(x , mod - 2);
}

void PreCalc()
{
    factorial[0] =  1;
    for(ll i = 1; i<=N ;i++ )
        factorial[i] = (i * factorial[i-1]) % mod;
}

ll C(int n,int r)
{
    if(n<r) return 0;
    ll d = factorial[n-r] * factorial[r];
    d%=mod;
    return (factorial[n] * ModInv(d)) % mod;
}


void solve()
{
  ll k,n;
  cin>>k>>n;
  int a[n]; 
  cin1(a,n);  
  ll cnt=0;  
  for (int i = 0; i < n; i++)
    cnt+=a[i];
    
  cout<<C(cnt,k);
  
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    PreCalc();
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
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
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

int MOD  = 1e9+7;
const int Z = 1e5;
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


void solve()
{
    string s;
    cin>>s;
    int ans = 0;
    string x = s;
    int n = s.size();
    ll denum  , n1 = 0 ;

    int k = 0;
    reverse(all(x));
    
    for (int i = 0; i < n; i++)
    {
      if(s[i]=='?') k++;
      if(s[i]!=x[i] ){
          if (x[i] != '?' && s[i] != '?') {
              cout << 0;
              return;
          }
      }
      else if(x[i]=='?' && s[i]=='?'){
          n1++;
      }
    }
    n1 = (n1 +1)/2;
    int num = pow(26 , n1 , MOD) ;
    denum = pow( 26 , k , MOD);
    
    ans = (num%MOD) * inverse_mod(denum , MOD);
    ans%=MOD; 
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
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

const ll  MOD = 998244353 , N = 6e5+1;
ll pow(ll x,ll n,ll mod){
    x%=mod;
    ll res=1;
    while(n){
        if(n%2){
            res=res*x%mod;
        }
        n/=2;
        x=x*x%mod;
    }
    return res;
}

ll inverse_mod(ll x,ll mod){
    x%=mod;
    return pow(x,mod-2,mod);
}

ll fact[N], inv[N];
void pre(){
    fact[0] = 1;
    inv[0] = inverse_mod(fact[0], MOD);
    for(ll i = 1 ; i < N ; i ++){
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = inverse_mod(fact[i], MOD);
    }   
}

ll nCr(ll n,ll r){
    if(n < r) return 0;
    if(!r) return 0;
    return fact[n]%MOD * inv[n - r] % MOD * inv[r] % MOD;
}



void solve()
{
    ll n,k;
    cin>>n>>k;
    ll l[n],r[n];
    map<ll,ll> mp;
    for (int i = 0; i < n; i++)
    {
      cin>>l[i]>>r[i];
      mp[l[i]];
      mp[r[i]];
    }
    ll cnt=1;
    for(auto &x : mp) x.second=cnt++;
    ll pre[cnt+1],new1[cnt+1];
    assign1(pre,cnt+1,0);    
    assign1(new1,cnt+1,0);    
    for (ll i = 0; i < n; i++)
    pre[mp[l[i]]]++,
    pre[mp[r[i]]+1]--,
    new1[mp[l[i]]]++;
    
    // for (int i = 0; i < n; i++)
    // pre[l[i]]++,pre[r[i]+1]--,new1[l[i]]++;
    
    for (int i = 1; i < cnt+1; i++)
      pre[i]+=pre[i-1];

    // for (int i = 0; i < cnt+1; i++)
    // {
    //   cout<<k<<' ';
    // }cendl;
      
    // cout1(pre,cnt+1);
    // cout1(new1,cnt+1);
    ll ans=0;
    for (int i = 1; i < cnt; i++)
    {
      // if(pre[i]<=k){
        // cout<<"pre[i] = "<<pre[i]<<"  nCr1 = "<<nCr(k,pre[i])<<endl;
        // cout<<"pre[i] - new[i] = "<<pre[i]- new1[i]<<"  nCr2 = "<<nCr(k,pre[i]-new1[i])<<endl;
        ans+=nCr(pre[i],k)%MOD-nCr(pre[i]-new1[i],k)%MOD;
        ans = (ans % MOD + MOD) % MOD;
      // }
    }
    cout<<ans;
  return;
}

int main() {
    InTheNameOfAllah
    pre();
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
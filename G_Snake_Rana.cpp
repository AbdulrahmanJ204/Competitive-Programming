#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
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
#define rep(i , from , to) for(int i = from ; i < to ;i++)
#define repR(i , from , to) for(int i = from ; i >= to ;i--)
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n ,m ,k;
    cin>>n>>m>>k;
    ll x[k] , y[k];
    for (int i = 0; i < k; i++)
      cin>>x[i]>>y[i];
    
    ll ans= n*(n+1)*m*(m+1)/4;
    ll temp=0;
    for (int mask = 1; mask < (1<<k); mask++)
    {
      ll cur=0 , cnt=0;
      ll mnX = n+1 , mnY = m+1 , mxX = 0 , mxY = 0;
      for (int bit = 0; bit < k; bit++)
      {
        if(!(mask&(1<<bit))) continue;
        cnt++;
        mnX= min(mnX , x[bit]);
        mnY= min(mnY , y[bit]);
        mxX= max(mxX , x[bit]);
        mxY= max(mxY , y[bit]);
      }
      cur= mnX * mnY * (n+1 -mxX) * (m+1 - mxY);
      ll sign= cnt%2 ? 1 : -1 ;
      temp+=sign* cur;
    }
    
    cout<<ans-temp;
    
    
    
  return;
}

int32_t main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
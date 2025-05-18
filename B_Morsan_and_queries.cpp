#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define int ll
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

int a[1002];
void solve()
{
    ll n,q;
    cin>>n>>q;
    a[0]=0;
    for (int i = 1; i <= n; i++)
      cin>>a[i];
    int mxa= *max_element(a+1 , a+n+1);
    int pre[mxa+1][n+1];
    assign2(pre,mxa+1,n+1,0);
    for (int i = 1; i < n+1; i++)
      pre[a[i]][i]++;
    
    for (int ai = 1; ai <= mxa; ai++)
    for (int i = 1; i < n+1; i++)
    pre[ai][i]+=pre[ai][i-1];  
    
    while(q--){
      int l , r , k;
      cin>>l>>r>>k;
      ll ans=0;
      for (int ai = 1; ai <= mxa; ai++)
      { 
        
        int first = pre[ai][l-1] ,
        last = pre[ai][r];
        int cnt= 0;
        cnt= last-first;
        int mod= ai%k;
        if(mod)
        ans+=cnt * min(k-mod , mod);
      }
      cout<<ans<<' ';
    }

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
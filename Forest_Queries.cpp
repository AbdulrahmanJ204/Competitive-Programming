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

void solve()
{
    ll n,q;
    cin>>n>>q;
    int pre[n+1][n+1];
    for (int i = 0; i <= n; i++)
    {
      pre[i][0]=pre[0][i]=0;
    }
    string s[n+1];
    for (int i = 1; i <= n; i++)
    {
      cin>>s[i];
      s[i] = '.'+s[i];
    }
    
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1] + (s[i][j]=='*');
   
    while(q--){
      int x1 ,y1 , x2 , y2;
      cin>>y1>>x1>>y2>>x2;
      
      int ans =pre[y1-1][x1-1] + pre[y2][x2] - pre[y1-1][x2] - pre[y2][x1-1];
      cout<<ans<<endl;
    }

  return;
}

int32_t main() {
    InTheNameOfAllah
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
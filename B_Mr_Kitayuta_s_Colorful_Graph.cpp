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
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int u , v , color; 
int vis[110];
map<int , vector<vector<int>>> mp;
bool dfs(int node){
  if(node==v) return 1;
  bool t = 0;
  vis[node] = true;
  for(auto x : mp[color][node]) 
  if(!vis[x]) t|=dfs(x);
  return t;
}
void solve()
{
    int n,m;
    cin>>n>>m;

    for (int i = 0; i < m; i++)
    mp[i+1].resize(n+1);
    for (int i = 0; i < m; i++)
    {
      int u , v, c;
      cin>>u>>v>>c;
      mp[c][u].push_back(v); 
      mp[c][v].push_back(u); 
    }

    int q;
    cin>>q;
    while(q--){
      cin>>u>>v;
      int ans=0;
      for(auto x : mp) 
      {
        assign1(vis , n+1 , 0);
        color = x.first , ans+=dfs(u);
      }
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
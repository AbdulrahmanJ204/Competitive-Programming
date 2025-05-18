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

const int z = 2e5+10; 
set<pair<int,int>> adj[z];
int mx = 0 , first = -1 , last = -1;
bool vis[z];
void dfs(int i , int cnt){
  vis[i]  =true;
  for(auto child : adj[i]) 
  if(!vis[child.first])
  dfs(child.first , cnt+child.second);
  
  if(cnt > mx) first = i , mx = cnt;
}
void solve()
{
    ll n;
    cin>>n;
    int sum=0;
    for (int i = 0; i < n-1; i++)
    {
      int u , v,c;
      cin>>u>>v>>c;
      sum+=c;
      adj[u].insert({v,c});
      adj[v].insert({u,c});
    }
    
    
    ll ans=sum*2;
    assign1(vis , n+ 1,false);
    for (int i = 1; i < n+1; i++)
      if(adj[i].size()) {
        dfs(i , 0);
        break;
      }
    mx = 0;
    assign1(vis , n+ 1,false);
    dfs(first , 0);
    
    ans-=mx;
    
    cout<<ans;
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
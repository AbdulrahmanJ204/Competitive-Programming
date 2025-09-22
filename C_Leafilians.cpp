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

void dfs(int node , int parent , vector<vector<int>> &adj , vector<int>& dist){
  dist[node] = dist[parent]+1;
  for(auto child : adj[node]){
    if(child==parent) continue;
    dfs(child , node ,adj , dist);
  }
}
void solve()
{
    ll n;
    cin>>n;
    if(n==1){
      cout<<"Go8";
      return;
    }
    vector<vector<int>> adj(n+1);
    vector<int> dist(n+1);
    for (int i = 0; i < n-1; i++)
    {
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
      if(adj[i].size()==1) {
        dfs(i , 0 , adj , dist);
        break;
      }
    }
    int mx =0 , node=-1;
    for (int i = 0; i < n+1; i++)
    {
      if(dist[i] > mx){
        mx = dist[i];
        node = i;
      }
    }
    dist.assign(n+1 , -1);
    dfs(node , 0 , adj ,dist);
    int dia = *max_element(all(dist));
    int ans = dia%3;
    cout<<(ans==2 ? "Neodoomer" : "Go8");
    

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
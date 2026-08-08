#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define i128 __int128_t
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(L,R) uniform_int_distribution<int>(L, R)(rng);

template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int lst = 0, mx =0;
void dfs(int node, int cnt , vector<int> &vis, vector<vector<int>>&adj, vector<int>&par) {
    vis[node] = cnt++;
    
    for (int ch : adj[node]) {
        if (vis[ch] == -1){
        par[ch] = node;
        dfs(ch, cnt,vis,adj,par);}
    }
    if (cnt > mx)
        lst = node, mx = cnt;
}
void solve()
{
    ll n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++)
    {
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> dst1(n+1,-1);
    vector<int> dst2(n+1,-1);
    vector<int> par(n+1,-1);
   

    vector<pair<int,int>> mids;
    for (int i = 1; i <= n; i++) {

        if (dst1[i] == -1) {
            lst = 0, mx = 0;
            dfs(i, 0, dst1, adj, par);
            int ed = lst;
            
            lst = 0, mx = 0 ;
            dfs(ed, 0, dst2, adj, par);
            int node = lst;
            while(node !=-1){
                if (dst2[node] == mx / 2 ) {
                  mids.push_back({mx , node});
                  break;
                }
                node = par[node];
             
            }
        }
    }
    if(mids.size()==1){
      cout<<mids[0].first-1;
      return;
    }
    
    sort(rall(mids));
   int mx =0;
   int f = (mids[0].first)/2+ (mids[1].first)/2 +1;
   int s = mids.size()>2 ? (mids[1].first)/2+ (mids[2].first)/2 +2: 0;
  
   mx =max({f , s , mids[0].first-1});
   cout<<mx<<endl;
    for (int i = 1; i < mids.size(); i++)
    cout<<mids[0].second<<" "<<mids[i].second<<endl; 
    
   
    

  return;
}

int32_t main() {
    InTheNameOfAllah;
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
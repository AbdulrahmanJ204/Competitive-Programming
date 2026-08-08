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
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<setw(20)<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    int n, m, q;
    cin>>n>>m>>q;
    vector<pair<pair<int,int> , int> > edges ;
    for (int i = 0; i < m; i++)
    {
      int u , v,  c;
      cin>>u>>v>>c;
      edges.push_back({{u,v},c});
    }
    
    bool en[m];
    assign1(en,m , true);

    vector<pair<pair<int,int> , int> > qu;
    while(q--){
      int op ;
      cin>>op;
      int x, y;
      if(op==1){
        cin>>x;
        qu.push_back({{op , x-1}, 0});
        en[x-1]=false;
      }
      else{
        cin>>x>>y;
        qu.push_back({{op,x},y});
      }
    }
    int INF = 2e18;
    int adj[n+1][n+1], dist[n+1][n+1];
    assign2(adj , n+1 , n+1 , 0);
    assign2(dist , n+1 , n+1 , INF);
    for (int i = 0; i < m; i++)
    {
      if(en[i]){
        int u , v, c;
        u=edges[i].first.first,
        v= edges[i].first.second,
        c= edges[i].second;
        adj[u][v]=c;
        adj[v][u]=c;
        dist[u][v] = min(dist[u][v] , c);   
        dist[v][u] = min(dist[v][u] , c);   
      }
    }
    for (int i = 0; i < n+1; i++)
    {
      dist[i][i]=0;
    }
    
    for (int k = 1; k < n+1; k++) {
        for (int i = 1; i < n+1; i++) {   
            for (int j = 1; j < n+1; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    // cout2(dist , n +1 , n+1 );

    vector<int> ans;
    reverse(all(qu));
    for (int l = 0; l < qu.size(); l++)
    {
      pair<pair<int,int> , int> cur = qu[l];
      int op = cur.first.first , x= cur.first.second , y = cur.second;
      if(op==1){
         en[x]= true;
          int u = edges[x].first.first , v = edges[x].first.second,
          c= edges[x].second;
          dist[u][v]=dist[v][u] = min(dist[u][v] , c);
         for (int i = 1; i < n+1; i++) {   
            for (int j = 1; j < n+1; j++) {
                if(dist[i][u]!=INF && dist[v][j] !=INF)
                dist[i][j]= min(dist[i][j] , dist[u][i] + dist[u][v] + dist[v][j]); 
                if(dist[i][v]!=INF && dist[u][j] !=INF)
                dist[i][j]= min(dist[i][j] , dist[u][j] + dist[u][v] + dist[v][i]); 
            }
        }
    //     cendl;
    // cout2(dist , n +1 , n+1 );
      }
      else{
        if(dist[x][y]==INF) ans.push_back(-1);
        else
        ans.push_back(dist[x][y]);
      }
    }
    reverse(all(ans));
    for (int i = 0; i < ans.size(); i++)
    {
      cout<<ans[i]<<endl;
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
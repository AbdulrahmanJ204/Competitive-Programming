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

void solve()
{
    ll n,m,x;
    cin>>n>>m>>x;
    int g[n+1];
    for (int i = 1; i < n+1; i++)
      cin>>g[i];
    vector<pair<int,int>> graph[n+1];
    for (int i = 0; i < m; i++)
    {
      int u , v , w;
      cin>>u>>v>>w;
      graph[u].push_back({v , w});
      graph[v].push_back({u , w});
    }
    
    
    
    queue<pair<pair<int,int> , pair<int,int>> > pq;
    // time , gas , node , flying
    int max_g=x+1; 
    int dist[n+1][max_g][2];
    for (int i = 0; i <= n; i++)
      for (int j = 0; j < max_g; j++) 
        for (int k = 0; k < 2; k++)   
          dist[i][j][k]=1e18;
     
    
    pq.push({{0 , 0},{1,0}});
    while(!pq.empty()){
      pair<pair<int,int> , pair<int,int>> tp = pq.front();
      pq.pop();
      int curTime= -tp.first.first,
      curGas=tp.first.second,
      curNode=tp.second.first,
      flying= tp.second.second;
      if(dist[curNode][curGas][flying]<= curTime) continue;
      dist[curNode][curGas][flying]= curTime;
        
      for(auto child : graph[curNode]){
        int curChild = child.first , validTime = child.second;
          int newTime = curTime; 
        if(flying){
          newTime++;
          pq.push({{-newTime , curGas},{curChild , 0}});
        }
        else{
          int newGas = min(curGas+g[curNode] , x);
          newTime+=2;
          if(newTime<=validTime) 
          pq.push({{-newTime , newGas},{curChild , 0}});
          
          if(newGas){  
          pq.push({{-newTime , newGas-1},{curChild , 0}});
          pq.push({{-newTime+1 , newGas-1},{curChild , 1}});
          }
        }
      }
    }
    ll ans= 1e18;
    
      for (int j = 0; j < max_g; j++)
      ans=min(ans,dist[n][j][0]);
      
    
      
    if(ans==1e18) ans= -1;
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
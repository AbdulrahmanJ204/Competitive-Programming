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
    ll n,t;
    cin>>n>>t;
    vector<pair<int,int>> graph[n];
    for (int time = 1; time < t+1; time++)
    {
      int m;
      cin>>m;
      while(m--){
        int u,v;
        cin>>u>>v;
        graph[u].push_back({time,v});
        graph[v].push_back({time,u});
      }
    }
    int k;
    cin>>k;
    int a[k];
    cin1(a,k);
    priority_queue<array<int, 3>> pq;
    // Dist ,  curTime, curNode
    pq.push({0,0,1});
    int dist[n+1];
    assign1(dist,n+1,1e18);
    // dist[1]=0;
    while(pq.size()){
      auto [curDist , curTime, curNode] = pq.top();
      pq.pop();
      if(curDist<=dist[curNode]) continue;
      dist[curNode] =curDist;
      for(auto child : graph[curNode]){
        int time = child.first , curChild = child.second;
        if(curTime+1<k)
        pq.push({curDist+1 ,curTime+1 , curChild});
        
      } 
      pq.push({curDist+1 ,curTime+1 , curNode});
    }
    cout<<dist[n];
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
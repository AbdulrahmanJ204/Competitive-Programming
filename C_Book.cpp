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
const int z=2e5+10;
ll vis[z];
ll n; 
bool cycle=false;
vector<int> graph[z];
bool isCyclic() {
  
    // stores in-degree of each vertex
    vector<int> inDegree(n, 0); 
  
    // queue to store vertices with 0 in-degree
    queue<int> q; 
  
    int visited = 0; // count of visited vertices

    // Calculate in-degree of each vertex
    for (int u = 0; u < n; u++) {
        for (auto v :graph[u]) {
            inDegree[v]++;
        }
    }

    // Enqueue vertices with 0 in-degree
    for (int u = 0; u < n; u++) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }

    // BFS traversal
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited++;
        for (auto v :graph[u]) {
            inDegree[v]--;
          
            // If in-degree becomes 0, enqueue it
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return visited != n; 
}
void solve()
{
    cin>>n;
    ll deg[n];
    cycle=false;
    for (int i = 0; i < n; i++)
    graph[i].clear();
    assign1(deg,n,0);
    assign1(vis,n,1e18);
    int cant= 1;
    for (int child = 0; child < n; child++)
    {
      int k , node;
      cin>>k;
      if(cant==1) cant&=k;
      deg[child]=k;
      while(k--){
        cin>>node;
        node--;
        if(node==child) cant=2;
        graph[node].push_back(child);
      }
      if(k>=0)
      sort(all(graph[node]));
    }
    if(cant){
      cout<<-1;
      return;
    }
    if(isCyclic()) 
    {
      cout<<-1;
      return;
    }
  
    set<int> cur  ;
    ll ans=1;
    for (int i = 0; i < n; i++) if(!deg[i] && graph[i].size()) cur.insert(i);

    while(cur.size()){
      vector<int> nxt;
      
      while(cur.size())
      {
        int node= *cur.begin();
        cur.erase(cur.begin());
        for(int child : graph[node]){
          if(deg[child]){
            deg[child]--;
            if(!deg[child]) 
           if(child>node) cur.insert(child);
           else   nxt.push_back(child);
          }
        }
      }
      for (int &x : nxt) cur.insert(x) ;
      if(nxt.size())
      ans++;
      
    }
    cout<<ans;
    
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
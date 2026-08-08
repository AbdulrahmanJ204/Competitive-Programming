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
    ll n,m;
    cin>>n>>m;
    int s ,t;
    cin>>s>>t;
    vector<pair<int,pair<int,int>>> adj[n+1];
    for (int i = 0; i < m; i++)
    {
      int u, v , b , d;
      cin>>u>>v>>b>>d;
      v--,u--;
      adj[u].push_back({v , {b ,d}});
      adj[v].push_back({u , {b ,d}});
    }
    s-- , t--;
    
    // beauty , dist , node;
    priority_queue<pair< int ,pair<int,int> >> pq; 
    
    pair<int,int> vec[n+1];
    for (int i = 0; i < n+1; i++)
    {
     vec[i] =  {0 , 1e18};
    }
    // pq.push({{0,0},s});
    for(auto v : adj[s]){
      int vBeauty = v.second.first , vDist = v.second.second, child= v.first;
      pq.push({vBeauty , {-vDist,child}});
    }
     
    while(!pq.empty()){
      pair<int,pair<int,int>> tp = pq.top();
      pq.pop();
      int curBeauty = tp.first ,
          curDist = -tp.second.first,
          u = tp.second.second;
          
      if(vec[u].first > curBeauty) continue;
      if(vec[u].first == curBeauty){
        vec[u].second = min(curDist , vec[u].second);
        continue;
      }    
      vec[u]= {curBeauty , curDist};
      for(auto v : adj[u]){
        int vBeauty = v.second.first , vDist = v.second.second, child= v.first;
        int newBeauty =   min(curBeauty , vBeauty);
        pq.push({newBeauty , {-vDist - curDist,child}});
      }     
    }
    cout<<vec[t].first<<" "<<vec[t].second;
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
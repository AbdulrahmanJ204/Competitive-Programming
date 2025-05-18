#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
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
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> graph[n];
    for (int from , to , w, i = 0; i < m; i++)
    {
      cin>>from>>to>>w;
      from--,to--;
      graph[from].emplace_back(to,w);
      graph[to].emplace_back(from,w);
    }
     
    priority_queue<pair<pair<int,int>, ll>> pq; 
    ll dist[n];
    bool isTrain[n];
    assign1(dist,n,LLONG_MAX);
    assign1(isTrain,n,false);
    
    for (int s,y,i = 0; i < k; i++)
    {
      cin>>s>>y;
      s--;
      pq.push({{-y,-1},s});
    }
    
    
    pq.push({{0,0},0});

    while(!pq.empty()){
      pair<pair<int,int>,int> curPair=pq.top();
      pq.pop();
      int curDist=-curPair.first.first;
      int curNode=curPair.second;
      int T = -curPair.first.second;
      if(dist[curNode]<=curDist) continue;
      isTrain[curNode] = T;
      dist[curNode]=curDist;
      for(auto &child : graph[curNode]){
        ll newDist=curDist+child.second;
        ll curChild = child.first;
        if(newDist<dist[curChild]) pq.push({{-newDist,0},curChild});
      }
    }
    for (int i = 0; i < n; i++) k-=isTrain[i];
    
    
    cout<<k;
  return;
}

int32_t main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
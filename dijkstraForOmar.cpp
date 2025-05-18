#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"
#define cno cout<<"NO"
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    int n;
    vector<pair<int,int>> graph[n]; // node , weight
    vector<int> dist(n,1e9);
    priority_queue<pair<int,int>> q;
    int src=0;
    dist[src]=0;
    q.push({0,0});
    while(!q.empty())
    {
      pair<int,int> x=q.top(); // pair of {dist , node}
      q.pop();
      int nodeSrcDist=-x.first;
      int node= x.second;
      if(nodeSrcDist<dist[node]){
      for(auto child: graph[node])
      { 
        int childNode=child.first;
        int childEdge=child.second;
        if(dist[node]+childEdge<dist[childNode]){
          dist[childNode]=dist[node]+childEdge;
          q.push({-dist[childNode],childNode});
        }
      }
      }
    }
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
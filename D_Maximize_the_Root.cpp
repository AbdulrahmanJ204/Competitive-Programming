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
#define cin1(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define cin2(v,n,m) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) cin>>v[i][j];
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
ll n;
const int q=2e5+10;
ll a[q];
vector<vector<ll>> graph;
ll fun(int node){
  if(!graph[node].size()) return a[node];
  ll mn=1e18;
  for(auto x: graph[node])
  mn=min(mn,fun(x));

  return min((a[node]+mn)/2,mn);
}
void solve()
{
    cin>>n;
    cin1(a,n);
    graph.clear();
    graph.assign(n,vector<ll>(0));
    for (int i = 1; i < n; i++)
    {
      int x;
      cin>>x;
      graph[x-1].push_back(i);
    }
    ll mn=1e18;
    for(auto x: graph[0]){
      mn=min(mn,fun(x));
    }
    cout<<a[0]+mn;
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
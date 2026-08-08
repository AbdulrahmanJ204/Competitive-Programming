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
bool can = true;
void dfs(vector<set<int>> &tree , int node , int parent){
  int cnt = 0;
  for(int child : tree[node])
  cnt+=(tree[child].size() == 3);
  if(cnt==3) can = false;
  for(int child : tree[node])
  if(child!=parent) dfs(tree , child , node);
}
void compress(vector<set<int>> &tree){
  
  for (int i = 0; i < tree.size(); i++)
    if(tree[i].size()==2)
    {
      int left = *tree[i].begin() , right =*tree[i].rbegin();
      tree[i].clear();
      tree[left].erase(i);
      tree[right].erase(i);
      tree[left].insert(right);
      tree[right].insert(left);
    }
}
void solve()
{
    ll n;
    cin>>n;
    can = true;
    vector<set<int>> tree(n+1);
    for (int i = 0; i < n-1; i++)
    {
      int u,v;
      cin>>u>>v;
      tree[u].insert(v);
      tree[v].insert(u);
    }
    int three = 0;
    for (int i = 1; i < n+1; i++)
    {
      
      if(tree[i].size()>3) {
        cno;
        return;
      }
    }
    
    compress(tree);
    for (int i = 0; i < n+1; i++)
    {
      if(tree[i].size()==1){
         dfs(tree , i , 0);
        break;
        }}
    
    if(can) cyes;
    else cno;
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
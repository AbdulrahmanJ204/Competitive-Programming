#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

// Header files, namespaces,
// macros as defined above
using namespace __gnu_pbds;
// less to set and less_equal to multiset
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>


const int z = 2e5 + 10;
int p[z];
ordered_set graph[z];

ll find(int a){
  return p[a]=(p[a]== a ? a : find(p[a])); 
}

void merge(int a, int b){
  
  a= find(a);
  b= find(b);
  if(a==b) return ;
  if(graph[a].size() > graph[b].size()) swap(a,b); 
  for(auto &x : graph[a]) graph[b].insert(x);
  graph[a].clear();

  p[a] = b;
}

void solve()
{
    ll n;
    cin>>n;
    for (int i = 0; i < n+1; i++)
    {
      graph[i].insert(i);
      p[i] = i;
    }
    
      ll q;
      cin>>q;
      while(q--){
        int op , u , v  , k;
        cin>>op;
        if(op==1){
          cin>>u>>v;
          merge(u,v);
        }
        else{
          cin>>u>>k;
          int parent= find(u);
          if(graph[parent].size()<k) cout<<-1;
          else cout<<*graph[parent].find_by_order(graph[parent].size()-k);
          cendl;
        }
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
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
bool visited[z];
ll subTreeNodes[z];
vector<int> graph[z];

ll sum(ll x, ll y, ll mod) {return (x % mod + y % mod) % mod;}

ll sub(ll x, ll y, ll mod) {return (x % mod - y % mod + mod) % mod;}

ll mul(ll x, ll y, ll mod) {return (x % mod * y % mod) % mod;}

long long fastPower(ll base, ll exponent,ll mod) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = mul(result, base, mod) % mod;
        }
        base = mul(base, base, mod) % mod;
        exponent /= 2;
    }
    return result % mod;
}

ll dfs(int node ){

  visited[node]=true;
  ll nodes= 0;
  for(auto child : graph[node]){
    if(!visited[child])
    nodes+= dfs(child) +1;
  }

  return subTreeNodes[node] =nodes;
}
void solve()
{
    ll n;
    cin>>n;
    ll p[n];
    cin1(p,n);
  
    assign1(visited, n+1 , false);
    for (int i = 0; i <= n; i++)
    graph[i].clear();
    
    int src= 0;
    for (int i = 0; i < n; i++)
    {
      if(!p[i]) src=i+1;
      graph[p[i]] .push_back(i+1);
    }
    
    
    dfs(src);
    
    ll ans[n+1];
    ll mod= 1e9+7;
    for (int i = 1; i < n+1; i++)
    {
      
      ll groups= fastPower(2,subTreeNodes[i],mod) -1;
      // 2 ^ (number of nodes in subtree) -1 ; (remove one for empty group). , using sum of (0Cn + 1Cn + ..... + nCn = 2^n).
      for(auto child : graph[i]){
        // invalid group is a group which consist of nodes from child subtree only, without the chlid himself.
        ll invalidGroups = fastPower(2,subTreeNodes[child],mod) -1; 
        groups= sub(groups ,invalidGroups,mod);
      }
      ans[i]=groups;
      
    }
    for (int i = 1; i < n+1; i++)
    cout<<ans[i]<<' ';
    
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
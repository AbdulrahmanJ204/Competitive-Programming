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
const int z= 1010;

// int find(int a){
//   return p[a]= (p[a]== a ? a : find(p[a]));
// }
// void merge(int a , int b){
//   a= find(a);
//   b= find(b);
//   if(a==b) return;
//   if(sz[a]> sz[b]) swap(a,b);
//   sz[b]+=sz[a];
//   sz[a]=0;
//   p[a]=b;
// }

class DSU {
 
private:
    vector<int> p, size;
    bool pathCompress;
public:
    DSU(int n, bool pathCompress = true) {
        p.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for(int i = 1; i<=n; i++) {
            p[i] = i;
            size[i] = 1;
        }
        this->pathCompress = pathCompress;
    }
 
    int find(int x) {
        if(x == p[x]) return x;
        int y = find(p[x]);
        if(this->pathCompress) p[x] = y;
        return y;
    }
 
    void merge(int a, int b) {
 
        a = find(a);
        b = find(b);
        if(a == b) return;
 
        if(size[a] < size[b]) swap(a, b);
 
        p[b] = a;
        size[a] += size[b];
        size[b]=0;
    }
 
    int Size(int u) {
        return size[find(u)];
    }
};
 
void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    DSU dsu(n);
    int p[n+1],sz[n+1];
    assign1(sz , n+1 , 1);
    set<int> st;
    for (int i = 1; i < n+1; i++)
      p[i]= i;
    p[0]=0;
    for (int i = 0; i < k; i++)
    {
      int x;
      cin>>x;
      st.insert(x);
    }
    
    if(!m){
      n-=k-1;
      cout<<n*(n-1) / 2;
      return;
    }

    for (int i = 0; i < m; i++)
    {
      int u , v;
      cin>>u>>v;
      dsu.merge(u,v);
    }

    sz[0]=0;
    set<int> st2;
    for(auto x : st) st2.insert(dsu.find(x));
    
    ll nGov=0, mxGov=0;
    
    for (int i = 1; i < n+1; i++)
    sz[i]= dsu.Size(i) , p[i]= dsu.find(i);
    
    // cout1(sz, n+1);
    // cout1(p, n+1);
    for (int i = 1; i < n+1; i++)
      if(st2.count(i)) mxGov=max(mxGov , sz[i]);
    map<int,int> vis;
    ll ans=-m;
    for (int i = 1; i < n+1; i++)
    {
      if(vis[p[i]]) continue;
      vis[p[i]]++;
      if(!st2.count(p[i])) ans+=mxGov*sz[i] , mxGov+=sz[i];
      ans+=sz[i]*(sz[i]-1)/2;
    }
    
    
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
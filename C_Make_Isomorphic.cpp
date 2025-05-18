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
#define rep(i , from , to) for(int i = from ; i < to ;i++)
#define repR(i , from , to) for(int i = from ; i >= to ;i--)
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n;
    cin>>n;
    ll m1 ,m2;
    cin>>m1;
    set<pair<int,int>> edg2;
    vector<int> graph[n];
    for (int i = 0; i < m1; i++)
    {
      int from , to ;cin>>from>>to;
      from--,to--;
      graph[from].push_back(to);
      graph[to].push_back(from);
    }
    cin>>m2;
    for (int i = 0; i < m2; i++)
    {
      int from , to ;cin>>from>>to;
      from--,to--;
      edg2.insert({from,to});
      edg2.insert({to,from});
    }
    ll a[n][n];
    assign2(a,n,n,-1);
    for (int i = 0; i < n; i++)
    {
      for (int j = i+1; j < n; j++)
      {
        cin>>a[i][j];
        a[j][i]=a[i][j];
      }
      
    }
    map<int,int> mp;
    ll degH[n];
    for (int i = 0; i < n; i++)
    degH[i]=graph[i].size();
    
    
    ll reCost=0;
    for(auto x: edg2){
      reCost+=a[x.first][x.second];
    } 
    reCost/=2;
    ll ans=1e18;
    vector<int> v;
    for (int i = 0; i < n; i++)
      v.push_back(i);
    
    
    do{

    ll curCost=reCost; 
    ll deg[n];
    assign1(deg,n,0);
    set<pair<int,int>> curSet;

    for (int i = 0; i < n; i++)
    {
      int from = v[i];
      int curDeg=0;
      while(deg[i]!=degH[i]){
        int to= 0;
      for (int j = 0; j < n; j++)
      {
        int cur=v[j];
        if(from==cur) continue;
        if(curSet.count({from,cur})) continue;
        if(degH[i]==deg[i]) continue;
        if(degH[j]==deg[j]) continue;
        // cout<<"from : "<<from<<" - > "<< to <<endl;
        if(deg[j]>deg[to]) to=j;
      }

        deg[i]++;
        deg[to]++;
        to=v[to];
        curSet.insert({from,to});
        curSet.insert({to,from});
        if(edg2.count({from,to})) curCost-=a[from][to];
        else curCost+=a[from][to];
      }
      
    }
    // cout1(deg,n);
    bool ok=true;
    for (int i = 0; i < n; i++)
    {
      if(deg[i]!=degH[i]) ok=false;
    }
      if(ok)
      ans=min(ans,curCost);
    }while(next_permutation(all(v)));
    cout<<ans;
  return;
}

int32_t main() {
    // InTheNameOfAllah
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
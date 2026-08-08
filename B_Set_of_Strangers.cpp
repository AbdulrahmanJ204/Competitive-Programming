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
int a[710][710];
bool vis[710][710];
ll n,m;
int dx[] = {-1 , 1 , 0 , 0 };
int dy[] = { 0 , 0 , 1 , -1};
bool valid(int i , int j){
  return i>=0 && i<n && j>=0 && j<m && !vis[i][j];
}
void dfs(int x , int y , int& cnt){
    cnt++;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i], newY = y + dy[i];
        if (valid(newX, newY)){
            if (a[newX][newY] == a[x][y] )
                dfs(newX, newY, cnt);
        }
    }
}
void solve()
{
  cin>>n>>m;
  cin2(a,n,m);
  assign2(vis , n  ,m , 0);
  int ans = 0;
  map<int,int> mp;
  bool twos = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int cnt = 0;
      if(!vis[i][j])
      dfs(i , j , cnt);
      if(cnt>1) mp[a[i][j]] = 2 , twos=true;
      else mp[a[i][j]] = max(1ll , mp[a[i][j]]);
    }
  }
  for(auto x : mp) ans+=x.second;
  ans -= twos ? 2 : 1;
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
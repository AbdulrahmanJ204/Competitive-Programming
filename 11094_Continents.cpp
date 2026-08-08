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

int x ,y ,n ,m , cur;
string s[30];
bool vis[30][30];
int dx[]= {1 , -1 , 0 ,  0} , 
    dy[]= {0 ,  0 , 1 , -1};
    char z;
bool isValid(int i , int j){
  return i<n && i>=0 && !vis[i][j] && s[i][j]==z;
}
void dfs(int i , int j){
  if(!isValid(i , j)) return;
  vis[i][j]= 1;
  cur++;
  for (int k = 0; k <4 ; k++)
  {
    int nx = i+dx[k] , ny = j+dy[k];
    ny=(ny+m)%m;
    dfs(nx , ny);
  }
}
void solve()
{
  
  while(cin>>n>>m){
    cin1(s,n);
    assign2(vis , 30 , 30 , 0);
    cin>>x>>y; 
    z= s[x][y]; 
    dfs(x , y);
    int ans= 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cur=0;
        dfs(i,j);
        ans=max(ans , cur);
      }
      
    }
    cout<<ans<<endl;
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
      // cendl;
    }
    return 0;
}
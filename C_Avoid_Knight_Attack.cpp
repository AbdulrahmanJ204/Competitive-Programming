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

ll n, m;
set<pair<int,int>> st;
bool valid(int i , int j){
  if(i> n || j > n || i<=0 || j<=0) return false;
  return st.count({i , j}) == 0;
}
void solve()
{
    cin>>n>>m;
    ll ans = n*n - m;
    int a[m], b[m];
    for (int i = 0; i < m; i++)
    {
      cin>>a[i]>>b[i];
      st.insert({a[i] ,b[i]});
    }
    int dx []= {2 , 1 , -1 , -2 , -2 , -1 , 1 , 2};
    int dy []= {1 , 2 , 2 , 1 , -1 , -2 , -2 , -1};
    set<pair<int,int>> removed;
    for (int i = 0; i < m; i++)
    {
      
      for (int j = 0; j < 8; j++)
      {
        
      int newX = a[i]+ dx[j]  , newY = b[i]+ dy[j] ;
      if(valid(newX , newY)&& !removed.count({newX , newY})) {
        removed.insert({newX , newY});
        ans--;
      }
      }
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
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define gcd(a ,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
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
ll n;
map<int,vector<int>> mpr , mpc;
int check(int idx , vector<vector<int>>& a){
      int l = 1e10 , r = 0 , u = 1e10 , d = 0 ; 
      for (int i = 0; i < n; i++)
      {
        if(idx==i) continue;
        l = min(l , a[i][0]);
        r = max(r , a[i][0]);
        u = min(u , a[i][1]);
        d = max(d , a[i][1]);
      }
      int space = (r-l+1)*(d - u +1);
      if(space == n-1){
        int x = 1e10 , y = 1e10;
        if(l>1 || r < 1e9) x= abs(l-r)+1;
        if(u>1 || d < 1e9) y= abs(u-d)+1;
        space+= min(x ,y);
      }
      // cout<<l<<" "<<r<<" "<<u<<" "<<d<<endl;
      // cout<<space<<' '<<idx<<endl;
      return space;
}
void solve()
{
    
    cin>>n;
    mpr.clear();
    mpc.clear();
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        int x;
        cin>>x;
        a[i].push_back(x);
      }
    }
    
    int l = 1e10 , r = 0 , u = 1e10 , d = 0; 
    for (int i = 0; i < n; i++)
    {
      l = min(l , a[i][0]);
      r = max(r , a[i][0]);
      
      u = min(u , a[i][1]);
      d = max(d , a[i][1]);
      mpr[a[i][0]].push_back(i);
      mpc[a[i][1]].push_back(i);
    }
    bool tl , tu , td , tr;
    tl = tu = td = tr = true;
    
    if(mpr[l].size() > 1) tl = false;
    if(mpr[r].size() > 1) tr = false;
    if(mpc[u].size() > 1) tu = false;
    if(mpc[d].size() > 1) td = false;
    int ans = (r-l+1) * (d-u+1);
    if (tl)
        ans = min(ans, check(mpr[l][0],a));

    if (tr)
        ans = min(ans, check(mpr[r][0],a));

    if (tu)
        ans = min(ans, check(mpc[u][0],a));

    if (td)
        ans = min(ans, check(mpc[d][0],a));

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
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
const int z= 2e5+10;
ll a[z];
ll b[z];
map<int, vector<int> > mp;
map<int,int> dp;
int fun(int size){
if(!mp.count(size)) return size;
if(dp.count(size)) return dp[size];
int mx = size;
for(auto x : mp[size]){
 if(x-1)
 mx= max(mx ,  fun(size + x -1));
}
return dp[size] =  mx;
}

void solve()
{
    ll n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
      cin>>a[i];
      b[i] = i + a[i]-1;
      if(b[i]>=n)
      mp[b[i]].push_back(i);
    }
  
    
    int ans = fun(n);
    cout<<ans;
    mp.clear();
    dp.clear();
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
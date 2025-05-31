#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
ll n, m;
const int z = 3e5;
int b[z];
vector<pair<int,int>> adj[z];
bool check(int maxCan){
      vector<int> a(n , 0);
      for (int i = 0; i < n; i++)
      {
        if(i && !a[i]) continue;
        a[i] +=b[i];
        a[i] = min(a[i] , maxCan);
        for(auto& x : adj[i]){
          int c = x.first , w = x.second;
          if(w<=a[i]){
            a[c] = max(a[c] , a[i]);
          }
        }
      }
      return a[n-1];      
    };
void solve()
{
    cin>>n>>m;
    
    
    cin1(b,n);
    for (int i = 0; i < m; i++)
    adj[i].clear();
    for (int i = 0; i < m; i++)
    {
      int s , t , w;
      cin>>s>>t>>w;
      s-- , t--;
      adj[s].push_back({t,w});
    }
   
   
    if(!check(1e9+20)){
      cout<<-1;
      return;
    }
    int l = 0  , r  = 1e9+20 , ans = 1e9+20;
    while(l<=r){
      int mid = (l+r)/2;
      if(check(mid)) 
      ans = min(ans , mid) , r = mid-1;
      else l = mid+1;
    }
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
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define i128 __int128_t
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(L,R) uniform_int_distribution<int>(L, R)(rng);

template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    int n , w , h;
    cin>>n>>w>>h;
    vector<tuple<int,int,int>> v;
    for (int i = 0; i < n; i++)
    {
      int x, y;
      cin>>x>>y;
      if(x > w  &&  y > h)
      v.push_back({x,y,i});
    }
    if(v.size()==0){
      cout<<0;
      return;
    }
    sort(all(v), [&](tuple<int,int,int> f , tuple<int,int,int> s){
      auto [x,y,i]  = f;
      auto [x2,y2,i2]  = s;
      int mn1 = min({x,y});
      int mn2 = min(x2,y2);
      if(mn1!=mn2) return mn1 < mn2;
      int mx = max(x,y);
      int mx2 = max(x2,y2);
      return mx < mx2;  
      
    });
    n = v.size();
    vector<int> ws , hs;
    
    for(auto [x,y,i] : v) {
      ws.push_back(x);
      hs.push_back(y);
    }
    
    
    
    vector<int> dp(n, 1);
  
    vector<int> seq(n);

    for (int i = 0; i < n; i++) {
      
        seq[i] = i; 
      
        for (int prev = 0; prev < i; prev++) {
          
            if (ws[prev] < ws[i] && hs[prev] < hs[i] && 
                1 + dp[prev] > dp[i]) {
              
                dp[i] = 1 + dp[prev];
                seq[i] = prev;
            }
        }
    }
    int ans = -1;
    int ansInd = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            ansInd = i;
        }
    }
    vector<int> res;
    res.push_back(get<2>(v[ansInd]));
    while (seq[ansInd] != ansInd) {
        ansInd = seq[ansInd];
        res.push_back(get<2>(v[ansInd]));
    }
    reverse(res.begin(), res.end());

    cout<<res.size()<<endl;
    for(auto id : res) cout<<id+1<<" ";
  return;
}

int32_t main() {
    InTheNameOfAllah;
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
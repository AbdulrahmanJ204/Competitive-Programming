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
    ll n;
    cin>>n;
    int a[n];
    cin1(a,n);

    vector<int> ans(n+1,0);
    vector<map<int,int>> v(n);
    // for 1 , take gcd alone, and gcd with every previous gcd? maybe    
    v[0][a[0]]= 1;
    for (int i = 1; i < n; i++)
    {
        int ai = a[i];
        // for every subarray ends at i-1
        // i need to loop over them and append my self to them
        // and calculate the new GCD
        v[i][ai] = 1;
        for(auto pr : v[i-1]){
            int gc = pr.first , ln = pr.second;
            gc = gcd(gc , ai);
            ln++;
            v[i][gc] = max(ln, v[i][gc]);
        }
    }
    
    int i = 0;
    for(auto x : v){
        
        i++;
        for(auto p : x) {
        ans[p.second] = max(ans[p.second] , p.first);
        }
    }
    for (int i = ans.size() - 2; i >= 0; i--)
    {
      ans[i] = max(ans[i] , ans[i+1]);
    }
    for (int i = 0; i < n; i++)
    {
      cout<<ans[i+1]<<' ';
    }
    
    

  return;
}

int32_t main() {
    InTheNameOfAllah;
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
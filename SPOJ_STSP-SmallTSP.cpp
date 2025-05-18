#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
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
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
const int MX = 20, Q = 1 << MX;
int graph[MX][MX];
int dp[MX][Q];
ll n;
int parent;
ll fun(int node, int mask) {
    if (mask == ((1 << n) - 1)){
        if(graph[node][parent]) return graph[node][parent];
        return 1e18;
    }
    if(~dp[node][mask]) return dp[node][mask];
    ll mn = 1e18;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !((mask) & (1 << i))) {
            mn = min(mn, graph[node][i] + fun(i, mask + (int)(1 << i)));
        }
    }
    return dp[node][mask]= mn;
}
void solve() {
    cin >> n;
    cin2(graph, n, n);
    assign2(dp, n, 1 << n, -1);
    ll ans = 1e18;
    
    for (int i = 0; i < n; i++) {
        parent=i;
        assign2(dp, n, 1 << n, -1);
        ans = min(ans, fun(i, 1 << i));
    }
    cout << ans;
    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
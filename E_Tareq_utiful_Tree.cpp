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

const int maxN = 2e5 + 50;
ll n;
vector<int> adj[maxN];
pair<int, int> splitEdge;
int dfs(int node, int parent) {

    int children = 1;

    for (auto child : adj[node]) {
        if (child == parent)continue;
        children += dfs(child, node);
    }

    if (children  * 2 == n && splitEdge.first == -1 && splitEdge.second == -1)
          splitEdge.first = node, splitEdge.second = parent;
    return children;
}

void countColors(int node, int parent, int mp[], int c[]) {
    mp[c[node]]++;
    for (auto child : adj[node]) {
        if (child == parent)
            continue;
        countColors(child, node, mp, c);
    }
}

void solve() {
    cin >> n;
    int c[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> c[i + 1];
    }
    splitEdge.first = -1;
    splitEdge.second = -1;
    int mp1[n + 50], mp2[n + 50];
    for (int i = 0; i < n + 50; i++) {
        mp1[i] = 0;
        mp2[i] = 0;
    }
for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    map<int, int> cnt;

    for (int i = 1; i <= n; i++) {
        cnt[c[i]]++;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (cnt[c[i]] & 1) {
            cout << -1;
            return;
        }
        // find_bridges();
    for (int i = 1; i <= n; i++)
        if (adj[i].size() == 1) {
            dfs(i, -1);
            break;
        }
        if(splitEdge.first==-1){
          cout<<-1;return;
        }
    countColors(splitEdge.first, splitEdge.second, mp1, c);
    countColors(splitEdge.second, splitEdge.first, mp2, c);
    int ans = 0;
    for (auto x : cnt) {
        int color = x.first;
        ans += abs(mp1[color] - mp2[color]) / 2;
    }
    cout << ans / 2;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    return;
}

int32_t main() {
    InTheNameOfAllah
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
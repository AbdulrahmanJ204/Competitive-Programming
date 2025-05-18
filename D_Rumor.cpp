#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
const int N = 1e5 + 10;
vector<ll> graph[N];
bool visited[N];
ll a[N];
ll dfs(int node) {
    visited[node] = true;
    ll ans = a[node];
    for (ll child : graph[node]) {
        if (!visited[child])
            ans = min(ans, dfs(child));
    }
    return ans;
}
void solve() {
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        visited[i] = false;
    }
    while (m--) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)

        if (!visited[i])
            ans += dfs(i);

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
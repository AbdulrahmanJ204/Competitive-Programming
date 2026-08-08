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
bool visited[N];
int a[N];
ll n, m;
vector<int> graph[N];
ll dfs(int node, int cnt, int parent) {
    if (cnt > m)
        return 0;
    visited[node] = true;
    ll ans = 0;
    for (auto child : graph[node]) {
        if (!visited[child] && child != parent) {
            if (a[child])
                ans += dfs(child, cnt + 1, node);
            else
                ans += dfs(child, 0, node);
        }
    }
    if (graph[node].size() == 1&&parent!=-1 && cnt <= m)
        return 1;
    return ans;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        visited[i] = false;
    }

    n--;
    while (n--) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    cout << dfs(1, a[1], -1);
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
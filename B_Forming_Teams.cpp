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
int color[101], ans = 0;
vector<vector<int>> adj(101);
bool dfs(int node, int col) {
    color[node] = col;
    for (auto x : adj[node]) {
        if (color[x] == -1) {
            if (!dfs(x, !col))
                return false;
        } else if (color[x] == col)
            return false;
    }
    return true;
}

bool dfs(int node, int par, int &cnt) {
    if (color[node])
        return false;
    color[node] = 1;
    for (auto x : adj[node]) {
        if (x != par)
            if (!dfs(x, node, ++cnt))
                return false;
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    ans = 0;
    for (int i = 0; i < n + 1; i++)
        color[i] = 0;
    // for (int i = 0; i < n + 1; i++)
    //     color[i] = -1;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[to].push_back(from);
        adj[from].push_back(to);
    }
    for (int i = 1; i < n + 1; i++)
        if (!color[i]) {
            int cnt=0;
            if(!dfs(i, -1, cnt))
            ans+=cnt%2;
        } 
    
    // for (int i = 1; i < n + 1; i++)
    //     if (color[i] == -1)
    //         dfs(i,0) ? ans: ans++;

    ans += (n - ans) % 2;
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
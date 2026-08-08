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
const int N = 2e5 + 5;
vector<int> graph[N];
ll visited[N];
ll dfs(int node, int parent) {

    for (auto child : graph[node]) {
        if (!visited[child]&&child !=parent)
            dfs(child , node);
            if(child!=parent)
        visited[node] += visited[child];
    }
    if (!visited[node])
        visited[node]++;
    return visited[node];
}

void solve() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        graph[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;
        
        graph[from].push_back(to);
        graph[to] . push_back(from);
    }
    dfs(1,-1);
    // for (int i = 1; i <= n; i++)
        // cout << visited[i] << ' ';
    // cendl;
    ll q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
         cout<<visited[a]*visited[b];
        cendl;
    }
    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
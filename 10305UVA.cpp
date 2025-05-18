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
int n, m;
vector<vector<int>> adj(101);
vector<int> topsort;
bool visited[101];
void dfs(int node) {

    visited[node] = true;

    for (auto child : adj[node])
        if (!visited[child])
            dfs(child);

    topsort.push_back(node);

}
int main() {
    InTheNameOfAllah

        while (cin >> n >> m && n != 0) {

        adj.clear();
        topsort.clear();

        for (int i = 1; i < n + 1; i++)
            visited[i] = false;

        for (int i = 0; i < m; i++) {
            int from, to;
            cin >> from >> to;
            adj[from].push_back(to);
        }

        for (int i = 1; i < n + 1; i++)
            if (!visited[i])
                dfs(i);

        reverse(topsort.begin(), topsort.end());

        for (auto x : topsort)
            cout << x << ' ';

        cendl;
    }
    return 0;
}

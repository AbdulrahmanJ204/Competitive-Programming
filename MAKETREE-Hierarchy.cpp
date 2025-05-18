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
const int N = 100010;
int n, k;
vector<vector<int>> adj(N);
int visited[N];
vector<int> topsort;
void dfs(int node) {
    visited[node] = 1;
    for (auto x : adj[node])
        if (!visited[x])
            dfs(x);
    topsort.push_back(node);
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i < n + 1; i++) 
        visited[i] = 0;
    

    for (int i = 1; i <= k; i++) {
        int w;
        cin >> w;
        while (w--) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    for (int i = 1; i < n + 1; i++) 
        if (!visited[i])
            dfs(i);
    
    bool x = true;
    reverse(topsort.begin(),topsort.end());
    visited[topsort[0]] = 0;
    for (int i = 1; i < topsort.size(); i++)
        visited[topsort[i]] = topsort[i - 1];

    for (int i = 0; i < topsort.size(); i++)
        cout<< visited[i+1] << endl;

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
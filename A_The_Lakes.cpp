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

ll n, m;
bool visited[1001][1001];
int a[1001][1001];
bool valid(int i, int j) {
    if (i >= n || i < 0 || j >= m || j < 0)
        return false;
    return !visited[i][j] && a[i][j] != 0;
}
ll dfs(int i, int j) {
    if (!valid(i, j))
        return 0;
    visited[i][j] = true;
    ll ans = a[i][j];
    ans += dfs(i, j + 1);
    ans += dfs(i + 1, j);
    ans += dfs(i, j - 1);
    ans += dfs(i - 1, j);
    return ans;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            visited[i][j] = false;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j])
                ans = max(ans, dfs(i, j));

    cout << ans;

    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define cin(v)                        \
    for (ll i = 0; i < v.size(); i++) \
        cin >> v[i];
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
vector<vector<int>> visited;
vector<string> s;
// map<int, int> c;
vector<int> c;
ll n, m;
bool valid(int i, int j) {
    if (i >= n || i < 0 || j >= m || j < 0)
        return false;
    return s[i][j] == '#' && !visited[i][j];
}
int color = 1;
void dfs(int i, int j) {
    if (!valid(i, j))
        return;

    visited[i][j] = color;
    c[color]++;
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}

void solve() {
    cin >> n >> m;
    s.clear();
    visited.clear();
    c.clear();
    s.resize(n);
    visited.resize(n, vector<int>(m));
    c.resize(n*m+1, 0);
    color=1;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = 0;

    ll ans = 0;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (valid(i, j)){ 
                dfs(i, j);
                color++;
                }

    for (int i = 0; i < n; i++) {
        ll temp = 0;
        set<int> colors;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') temp++;
            
            colors.insert(visited[i][j]);
            if (i + 1 < n)  colors.insert(visited[i + 1][j]);
            if (i - 1 >= 0) colors.insert(visited[i - 1][j]);
        }

        for (auto x : colors) 
            temp += c[x];

        ans = max(ans, temp);
    }
    
    for (int j = 0; j < m; j++) {
        ll temp = 0;
        set<int> colors;
        for (int i = 0; i < n; i++) {
            if (s[i][j] == '.') temp++;
                
            colors.insert(visited[i][j]);
            
            if (j + 1 < m)  colors.insert(visited[i][j + 1]);
            if (j - 1 >= 0) colors.insert(visited[i][j - 1]);
        }
        for (auto x : colors) 
            temp += c[x];
        ans = max(ans, temp);
    }

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
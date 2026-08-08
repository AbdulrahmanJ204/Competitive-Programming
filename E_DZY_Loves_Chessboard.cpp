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
const int N = 111;
string s[N];
char c[2] = {'B', 'W'};
bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return s[i][j] == '.';
}

void dfs(int i, int j, int index) {
    if (!valid(i, j))
        return;
    s[i][j] = c[index];
    index = (index + 1) % 2;
    dfs(i - 1, j, index);
    dfs(i, j - 1, index);
    dfs(i + 1, j, index);
    dfs(i, j + 1, index);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '.')
                dfs(i, j, 0);
    for (int i = 0; i < n; i++)
        cout << s[i] << endl;

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
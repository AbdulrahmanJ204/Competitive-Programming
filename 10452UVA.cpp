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
string s[9];
vector<string> v;
string w = "IEHOVA#";
bool valid(int i, int j) {
    return i < n && i >= 0 && j >= 0 && j < m;
}
void dfs(int i, int j, int cnt, string x) {
    if (!valid(i, j) || w[cnt] != s[i][j])
        return;
    v.push_back(x);

    dfs(i - 1, j, cnt + 1, "forth");
    dfs(i, j + 1, cnt + 1, "right");
    dfs(i, j - 1, cnt + 1, "left");
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        v.clear();
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int x;
        for (int i = 0; i < m; i++)
            if (s[n - 1][i] == '@')
                x = i;

        dfs(n - 2, x, 0, "forth");
        dfs(n - 1, x + 1, 0, "right");
        dfs(n - 1, x - 1, 0, "left");
        for (int i = 0; i < v.size() - 1; i++) {
            cout << v[i] << ' ';
        }
        cout << v[v.size() - 1];
        cendl;
    }
    return 0;
}
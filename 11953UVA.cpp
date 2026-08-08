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
ll n;
string s[110];
bool visited[110][110];
bool valid(int i, int j) {
    return i < n && i >= 0 && j >= 0 && j < n;
}

void dfs(int i, int j) {
    if (!valid(i, j)||visited[i][j] || s[i][j] == '.')
        return;
    visited[i][j] = true;
    dfs(i, j + 1);
    dfs(i, j - 1);
    dfs(i + 1, j);
    dfs(i - 1, j);
    return;
}
int main() {
    // InTheNameOfAllah
        ll t = 1;
    cin >> t;
    for (int T = 1; T < t + 1; T++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                visited[i][j] = false;
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j] && s[i][j] == 'x') {
                    ans++;
                    dfs(i, j);
                }
    
        cout<<"Case "<<T<<": "<<ans<<endl;
    }

    return 0;
}
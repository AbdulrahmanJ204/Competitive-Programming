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
const int N = 22;
ll n, m;
bool visited[N][N];
int h[N] , v[N];
void reset() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
}

bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return !visited[i][j];
}
void dfs(int i, int j) {
    if (!valid(i, j))
        return;
    visited[i][j] = true;
     dfs(i+v[j],j);
    dfs(i,j+h[i]);
}
bool check() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j])
                return false;
    return true;
}
void solve() {
    cin >> n >> m;
    string ho, ve;
    cin >> ho >> ve;
    for (int i = 0; i < n; i++)
        if (ho[i] == '>')
            h[i] = 1;
        else
            h[i] = -1;
    for (int i = 0; i < m; i++)
        if (ve[i] == '^')
            v[i] = -1;
        else
            v[i] = 1;
            
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            reset();
            dfs(i,j);
            if(!check()) {
              cout<<"NO";
              return;
            }
        }
        cout<<"YES";
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
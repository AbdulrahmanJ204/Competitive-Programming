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

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n][m], b[n][m];
    int rows[n], columns[m];
    for (int i = 0; i < n; i++) {
        rows[i] = i;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            columns[j] = j;
        }
    }
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            mp[b[i][j]] = {i, j};
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[a[i][j]].first != i)
                rows[i] = mp[a[i][j]].first;
            if (mp[a[i][j]].second != j)
                columns[j] = mp[a[i][j]].second;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[a[i][j]].first != rows[i]||mp[a[i][j]].second != columns[j] ){
              cout<<"NO";
              return;
            }
        }
    }
    
    // tryAndCry(rows);
    // tryAndCry(columns);
    //  for (auto i : rows){
    // for (auto j : columns)
    //     cout<<a[i][j]<<' ';
    //     cendl;}
    //  for (auto i : rows){
    // for (auto j : columns)
    //     cout<<b[i][j]<<' ';
    //     cendl;}
    cout<<"YES";
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
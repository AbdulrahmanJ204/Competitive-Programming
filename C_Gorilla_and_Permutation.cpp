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
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];

    for (int i = 0; i < n-k+1; i++) {
        a[i] = n - i;
        
    }
    int cnt = m+1;
    for (int i = n-k+1; i < n - m; i++) {
        a[i] = cnt;
        // cout << cnt << ' ';
        cnt++;
    }

    cnt = 1;
    for (int i = n - m; i < n; i++) {
        a[i] = cnt;
        cnt++;
    }

    for (auto x : a)
        cout << x << ' ';

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
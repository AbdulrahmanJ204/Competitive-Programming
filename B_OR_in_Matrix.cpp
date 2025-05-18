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

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n][m], b[n][m];
    int x[n], y[m];
    for (int i = 0; i < n; i++) {
        x[i] = 0;
        for (int j = 0; j < m; j++) {
            a[i][j] = 1;
            y[j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            if (!b[i][j]) {
                for (int k = 0; k < n; k++)
                    a[k][j] = 0;
                for (int k = 0; k < m; k++)
                    a[i][k] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                x[i] = 1;
                y[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] && !x[i] && !y[j]) {
                cout << "NO";
                return;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cendl;
    }

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
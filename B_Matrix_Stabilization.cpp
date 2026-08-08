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
const int MX = 200;
int a[MX][MX];
int n, m;
bool good(int i, int j) {
    bool x = true;
    int cnt = 0;
    int neg=0;
    if (i - 1 >= 0)
       {neg++; (a[i][j] > a[i - 1][j]) ? cnt++ : cnt;
    }if (i + 1 < n)
    {neg++;    (a[i][j] > a[i + 1][j]) ? cnt++ : cnt;
    }if (j - 1 >= 0)
    {neg++;    (a[i][j] > a[i][j - 1]) ? cnt++ : cnt;
    }if (j + 1 < m)
    {neg++;    (a[i][j] > a[i][j + 1]) ? cnt++ : cnt;
    }// cout<<cnt<<endl;
    return cnt == neg;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int x = 4;
    // while (x--) {
       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (good(i, j)) {
                    int mx = 0;
                    if (i - 1 >= 0)
                        mx = max(mx, a[i - 1][j]);
                    if (i + 1 < n)
                        mx = max(mx, a[i + 1][j]);
                    if (j - 1 >= 0)
                        mx = max(mx, a[i][j - 1]);
                    if (j + 1 < m)
                        mx = max(mx, a[i][j + 1]);
                    a[i][j] = mx;
                    
                }
            }
            
        }
    // }

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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
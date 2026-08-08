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
    int n, k;
    cin >> n >> k;
    int N = 2 * n + 1;
    int a[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 1; i < N; i += 2) {
        if (a[i] - 1 > a[i - 1] && a[i] - 1 > a[i + 1] && k > 0) {
            a[i]--;
            k--;
        }
    }
    for (int x : a)
        cout << x << ' ';
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
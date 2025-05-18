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
    ll n;
    cin >> n;
    int t;
    cin >> t;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int cnt = 0, value = 0;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (cnt >= t)
            break;
        if (t - cnt >= a[i])
            if (b[i] >= value) {
                index = i;
                value = b[i];
            }

        cnt++;
    }
    if (index != -1)
        index++;
    cout << index;

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
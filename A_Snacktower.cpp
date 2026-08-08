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
    int a[n];
    int suf[n + 1];
    for (int i = 0; i < n + 1; i++)
        suf[i] = 0;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--)
        suf[i] = max(suf[i + 1], a[i]);
    int mx=suf[0];
    for (int i = 0; i < n; i++) {
        if (a[i] == suf[i]) {
            q.push(a[i]);
            while (!q.empty()) {
                if (q.top() != mx)
                    break;
                cout << mx-- << ' ';
                q.pop();
            }
            cendl;
        }
        else {
            q.push(a[i]);
            cendl;
        }
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
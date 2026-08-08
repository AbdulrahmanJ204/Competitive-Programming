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

    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int k = k1 + k2;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    priority_queue<ll> q;
    for (int i = 0; i < n; i++) {
        q.push(abs(a[i] - b[i]));
    }

    while (q.top() != 0 && k > 0) {
        ll temp = q.top();
        temp--;
        k--;
        q.pop();
        q.push(temp);
    }
    if (k > 0)
        cout << k % 2;
    else {
        ll ans = 0;
        while (!q.empty()) {
            ans += q.top() * q.top();
            q.pop();
        }
        cout << ans;
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
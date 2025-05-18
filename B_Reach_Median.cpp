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
    ll s;
    cin >> s;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int mid = n / 2;
    ll ans = 0;
    if (a[mid] < s) {
        for (int i = mid; i < n; i++)
            if (a[i] < s)
                ans += s - a[i];
    } else if (a[mid] > s) {
        for (int i = mid; i >= 0; i--) {
            if (a[i] > s)
                ans += a[i] - s;
        }
    }
    cout<<ans;
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
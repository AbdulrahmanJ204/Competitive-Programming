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
    ll a[n];
    ll sum = 0;
    int b[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        b[a[i] % 3]++;
    }
    ll ans = 3 - sum % 3;
    if(sum%3==0) cout<<0;
    else if(b[sum%3]>0) cout<<1;
    else cout<<ans;

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
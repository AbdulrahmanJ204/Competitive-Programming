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
    vector<int> a(n + 1);
    int sum = 0;
    int pre[n + 1];
    pre[0] = a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(), a.rend()-1);
    // cout<<sum<<endl;\
    // cout<<a[0]<<endl;
    for (int i = 1; i < n + 1; i++)
        pre[i] = a[i] + pre[i - 1];
    for (int i = 1; i < n + 1; i++) {
      // cout<<sum-pre[i]<<' '<<pre[i]<<endl;
        if (sum - pre[i] < pre[i]) {
            cout << i;
            return;
        }
    }
    cout << n;
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
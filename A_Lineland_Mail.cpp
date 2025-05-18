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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << a[1] - a[0] << ' ' << a[n - 1] - a[0] << endl;
    for (int i = 1; i < n - 1; i++)
        cout << min(a[i] - a[i - 1], a[i + 1] - a[i]) <<" "<< max(a[n-1] - a[i], a[i] - a[0])<<endl;;

    cout << a[n - 1] - a[n - 2] << ' ' << a[n - 1] - a[0] << endl;

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
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
    ll a[n], x[n];
    for (int i = 1; i < n; i++) {
        cin >> x[i];
        a[i] = 0;
    }

    a[0] = x[1] + 1;
    a[1] = x[1];
    for (int i = 2; i < n; i++) {
        if (x[i] >= a[i - 1])
                a[i - 1] += 1000*a[i - 2];
       
            a[i] = x[i] + a[i - 1];
    }
    if(!a[n-1]) a[n-1]=x[n-1];
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

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
//5 4 6 11 12 14 
// 4 2 5 1 2

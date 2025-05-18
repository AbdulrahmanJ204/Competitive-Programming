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
    ll x[n], y[n];
    ll mny = 2e18,
       mxy = 0,
       mnx = 2e18,
       mxx = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        x[i] += 1e9+1;
        y[i] += 1e9+1;
        mnx=min(mnx,x[i]);
        mxx=max(mxx,x[i]);
        mny=min(mny,y[i]);
        mxy=max(mxy,y[i]);
    }
    ll ans=max((mxx-mnx),(mxy-mny));
    cout<<ans*ans;
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
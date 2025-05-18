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
    int ans=0;
    int mn=1e9+234,mx=0;
    for (int i = 0; i < n; i++)
    {
      cin>>a[i];
      mn=min(a[i],mn);
      mx=max(a[i],mx);
    }
    for (int i = 0; i < n; i++)
    {
      if(a[i]>mn&&a[i]<mx) ans++;
    }
    
    cout << ans;
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
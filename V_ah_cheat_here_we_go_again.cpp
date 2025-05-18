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
    map<int, int> m;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
        mx = max(mx, a[i]);
    }

    int ans = 0;
    vector<pair<int, int>> v(mx + 1);
    for (int i = 0; i <= mx; i++) {
        v[i] = {0, 0};
    }

    for (auto x : m) {

        v[x.first] = {x.first, x.second};
    }
    for (int i = 0; i < mx; i++) {
        ans+=v[i].second%2;
        v[i+1].second+=v[i].second/2;
    }
    while(v[mx].second>0){
        ans+=v[mx].second%2;
        v[mx].second/=2;
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
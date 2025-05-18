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
ll n, k;
bool good(string s) {
    int size = s.size();
    bool a[k + 1];
    for (int i = 0; i < k + 1; i++)
        a[i] = false;

    for (int i = 0; i < size; i++)
        a[s[i] - '0'] = true;

    for (int i = 0; i < k + 1; i++)
        if (!a[i])
            return false;

    return true;
}
void solve() {
    cin >> n >> k;
    string a[n];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (good(a[i]))
            ans++;
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
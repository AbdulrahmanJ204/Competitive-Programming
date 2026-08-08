#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, heavy = "heavy", metal = "metal";
    cin >> s;
    ll n = s.size(), h1[n + 1], m[n + 1];
    for (ll j = 0; j < n + 1; ++j) {
        m[j] = 0;
        h1[j] = 0;
    }
    for (ll i = 0; i < n - 5; ++i) {
        string a = s.substr(i, 5);
        if (a == heavy)
            h1[i] = 1;
    }
    for (ll i = n - 1; i >= 4; --i) {
        string a = s.substr(i - 4, 5);
        if (a == metal)
            m[i - 4] = m[i - 3] + 1;
        else
            m[i - 4] = m[i - 3];
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (h1[i])
            ans += m[i];
    }
    cout << ans << endl;
    return 0;

}
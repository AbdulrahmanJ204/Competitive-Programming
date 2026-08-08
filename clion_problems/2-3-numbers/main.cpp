#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<ll> s;
    ll x = 2, y = 3;
    for (int j = 0; j <= 30; ++j) {
        ll two = pow(x, j);
        s.insert(two);
        for (int i = 0; i <= 19; ++i) {
            ll three = pow(y, i);
            s.insert(three);
            if (two * three <= 10e9) 
                s.insert(two * three);
        }
    }

    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (*it > 10e9) break;
        if (*it >= l && *it <= r)
            ans++;
    }
    cout << ans << endl;


    return 0;
}


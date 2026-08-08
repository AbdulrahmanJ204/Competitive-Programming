#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll ans = 0;
        ll n = stoll(s);
        if (n < 2050) {
            cout << -1 << endl;
            continue;
        }
        ll p = 2050 * pow(10, s.size() - 4);
        if (n < p)
            p /= 10;
        while (n >= p && p >= 2050) {
            ans += n / p;

            n %= p;

            while (n < p) { p /= (10); }
        }

        if (n == 0)
            cout << ans << endl;
        else
            cout << -1 << endl;

    }


    return 0;
}

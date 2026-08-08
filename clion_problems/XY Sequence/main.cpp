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
        ll n, b, x, y;
        cin >> n >> b >> x >> y;
        ll a[n + 1];
        a[0] = 0;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {

            if (a[i - 1] + x <= b) {
                a[i] = a[i - 1] + x;
                ans += a[i];
            } else {
                a[i] = a[i - 1] - y;
                ans += a[i];
            }

        }

        cout << ans << endl;
    }
    return 0;

}
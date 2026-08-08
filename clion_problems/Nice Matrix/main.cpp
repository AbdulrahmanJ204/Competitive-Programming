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
        int n, m;
        cin >> n >> m;
        ll a[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        vector<ll> v;
        ll ans = 0;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                v.push_back(a[i][j]);
                v.push_back(a[n - i - 1][j]);
                v.push_back(a[i][m - j - 1]);
                v.push_back(a[n - i - 1][m - j - 1]);
                sort(v.begin(), v.end());
                ans += v[1] - v[0] + v[3] - v[2] + 2 * (v[2] - v[1]);
                v.clear();
            }
        }
        if (n % 2 == 1) {
            for (int j = 0; j < m / 2; ++j) {
                v.push_back(a[n / 2][j]);
                v.push_back(a[n / 2][m - j - 1]);
                sort(v.begin(), v.end());
                ans += v[1] - v[0];
                v.clear();
            }
        }
        if (m % 2 == 1)
            for (int i = 0; i < n / 2; ++i) {
                v.push_back(a[i][m / 2]);
                v.push_back(a[n - i - 1][m / 2]);
                sort(v.begin(), v.end());
                ans += v[1] - v[0];
                v.clear();
            }
        cout << ans << endl;

    }


    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
        int n;
        cin >> n;
        ll a[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n - 1; ++j)
                cin >> a[i][j];

        map<ll, pair<ll, bool>> m;
        ll mx = 0;
        ll second = 0;
        for (int j = 0; j < n - 1; ++j) {
            ll x;
            for (int i = 0; i < n; ++i) {
                if (!m[a[i][j]].second)
                    m[a[i][j]].first++;
                if (m[a[i][j]].first > mx && !m[a[i][j]].second) {
                    x = a[i][j];
                    mx = max(m[a[i][j]].first, mx);
                }
            }
            cout << x << ' ';
            m[x].first = 0;
            m[x].second = 1;
            mx = 0;
            for (int i = 0; i < n; ++i) {
                if (!m[a[i][j]].second)
                    if (m[a[i][j]].first > mx) {
                        second = a[i][j];
                        mx = max(m[a[i][j]].first, mx);
                    }
            }
            if (!m[second].second)
                cout << second << ' ';
            m[second].first = 0;
            m[second].second = 1;
            mx = 0;
        }
        cout << endl;
    }
    return 0;
}

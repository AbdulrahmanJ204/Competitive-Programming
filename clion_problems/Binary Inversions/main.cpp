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
        ll n;
        cin >> n;
        int a[n];
        ll suf[n + 1], suf1[n + 1], suf2[n + 1];
        ll firstp0, lastp1;
        ll cnt = 0, c1 = 0;
        bool done = false;
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
            suf[i] = 0;
            suf1[i] = 0;
            suf2[i] = 0;
            if (a[i] == 1) {
                lastp1 = i;
                c1++;
            }
        }
        ll ans2 = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                if (cnt == 0) {
                    firstp0 = i;
                    cnt++;
                } else
                    cnt++;
            }
        }
        if (c1 == n) {
            cout << c1 - 1 << endl;
            continue;
        }
        if (cnt == n) {
            cout << cnt - 1 << endl;
            continue;
        }
        for (ll j = n - 2; j >= 0; --j) {
            if (j + 1 == firstp0 && cnt > 1) {
                suf[j] = suf[j + 1];
                continue;
            }
            if (a[j + 1] == 0)
                suf[j] = suf[j + 1] + 1;
            else
                suf[j] = suf[j + 1];
        }
        for (ll j = n - 2; j >= 0; --j) {
            if (j + 1 == lastp1 && c1 > 1) {
                suf1[j] = suf1[j + 1] + 1;
                continue;
            }
            if (a[j + 1] == 0)
                suf1[j] = suf1[j + 1] + 1;
            else
                suf1[j] = suf1[j + 1];
        }

        ll ans = 0, ans1 = 0;
        for (ll i = 0; i < n; ++i) {
            if (a[i] == 1 || i == firstp0)
                ans += suf[i];
        }
        for (ll i = 0; i < n; ++i) {
            if (a[i] == 1 && i != lastp1)
                ans1 += suf1[i];
        }
        for (ll j = n - 2; j >= 0; --j) {
            if (a[j + 1] == 0)
                suf2[j] = suf2[j + 1] + 1;
            else
                suf2[j] = suf2[j + 1];
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1)
                ans2 += suf2[i];
        }
        cout << max(ans2, max(ans, ans1)) << endl;

    }


    return 0;

}
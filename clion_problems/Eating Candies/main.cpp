#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
        ll n;
        cin >> n;
        ll a[n], pre[n + 1], suf[n + 1], l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            pre[i] = 0;
            suf[i] = 0;
        }
        suf[n] = 0;
        pre[n] = 0;
        pre[0] = a[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + a[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1] + a[i];
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll x = pre[i];
            l = i + 1;
            r = n;
            while (l <= r) {
                ll mid = (l + r) / 2;
                if (suf[mid] == x) {
                    ans = max(ans, n - (mid - i) + 1);
                    break;
                }
                else if (suf[mid] > x)
                    l = mid + 1;
                else if (suf[mid] < x)
                    r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

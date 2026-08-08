#include <bits/stdc++.h>
using namespace std;
#define test  ll t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
        ll n, q;
        cin >> n >> q;
        vector<int> a(n);
        ll pre[n + 1];

        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
            pre[i] = 0;
        }
        sort(a.rbegin(), a.rend());
        pre[0] = 0;
        for (ll i = 1; i <= n; ++i) {
            pre[i] = a[i - 1] + pre[i - 1];
        }
        while (q--) {
            ll x;
            cin >> x;
            ll l = 1, r = n, mid, ans;
            bool exist = false;
            if (l == r)
                if (pre[r] >= x) {
                    ans = l;
                    exist = true;
                }
            while (l < r) {
                mid = (l + r) / 2;

                if (pre[mid] >= x) {
                    r = mid;
                    ans = mid;
                    exist = true;
                } else
                    l = mid + 1;
                if (l == r)
                    if (pre[r] >= x) {
                        ans = l;
                        exist = true;
                    }
            }
            if (exist)
                cout << ans << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}

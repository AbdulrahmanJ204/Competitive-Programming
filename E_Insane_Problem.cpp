#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES"
#define cno cout << "NO"
#define cin(v)                        \
    for (ll i = 0; i < v.size(); i++) \
        cin >> v[i];
#define cin1(v, n)             \
    for (ll i = 0; i < n; i++) \
        cin >> v[i];
#define cin2(v, n, m)               \
    for (ll i = 0; i < n; i++)      \
        for (int j = 0; j < m; j++) \
            cin >> v[i][j];
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define cout1(v, n)            \
    for (ll i = 0; i < n; i++) \
        cout << v[i] << ' ';   \
    cendl;
#define cout2(v, n, m)                \
    for (ll i = 0; i < n; i++, cendl) \
        for (int j = 0; j < m; j++)   \
            cout << v[i][j] << ' ';
#define assign1(v, n, value)   \
    for (ll i = 0; i < n; i++) \
        v[i] = value;
#define assign2(v, n, m, value)     \
    for (ll i = 0; i < n; i++)      \
        for (int j = 0; j < m; j++) \
            v[i][j] = value;
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define oo LLONG_MAX
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
long long fastPower(ll base, ll exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}
void solve() {
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    int lastK = 1;
    int ok = k;
    while (k * ok < l1)
        k *= ok;
    ll ans = 0;
        k*=ok;
    // cout << "K = " << k << endl;
    while (k <= r1) {
        // left * k^x (min and max x) find dif and mul with r - l
        int mn = 29;
        int l = 0, r = 30;
        while (l <= r) {
            int po = (l + r) / 2;
            int rightSideValue = l1 * fastPower(ok, po);
            if (rightSideValue < l2) {
                l = po + 1;
            } else if (rightSideValue > r2) {
                r = po - 1;
            } else {
                mn = min(po, mn);
                r = po - 1;
            }
        }
        l = 0, r = 30;
        int mx = 0;
        while (l <= r) {
            int po = (l + r) / 2;
            int rightSideValue = l1 * fastPower(ok, po);
            if (rightSideValue < l2) {
                l = po + 1;
            } else if (rightSideValue > r2) {
                r = po - 1;
            } else {
                mx = max(po, mx);
                l = po + 1;
            }
        }
        if(l1 > k){
          k = r1;
        }
        cout<<"Mx = "<<mx <<" Mn = "<<mn<<endl;
        cout << "left = " << l1 << " right = " << k << endl;
        ans += (k - l1 ) * (mx - mn +1);
        l1 = k;
        k *= ok;
    }
    cout << ans;
    return;
}

int32_t main() {
    InTheNameOfAllah
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
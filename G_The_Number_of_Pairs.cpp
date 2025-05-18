#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define cin(v)                        \
    for (ll i = 0; i < v.size(); i++) \
        cin >> v[i];
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
const ll M = 2e7 + 10;
ll sieve[M];

ll fastPower2(ll x) {
    return (ll)1 << x;
}
ll getWhatever(ll x) {

    return sieve[x];
}
void solve() {
    ll c, d, x;
    cin >> c >> d >> x;
    vector<ll> v;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            v.push_back(i);
            if (i != x / i)
                v.push_back(x / i);
        }
    }
    ll ans = 0;
    for (ll i = 0; i < v.size(); i++) {

        if ((x / v[i] + d) % c == 0) {
            ans += fastPower2(getWhatever((x / v[i] + d) / c));
        }
    }
    cout << ans;
    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    for (ll i = 0; i < M; i++) {
        sieve[i] = 0;
    }
    for (ll i = 2; i < M; i++) {
        if (!sieve[i]) {
            for (ll j = i; j < M; j += i) {
                sieve[j]++;
            }
        }
    }

    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
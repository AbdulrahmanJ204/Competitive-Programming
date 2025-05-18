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
const int N = 1e5 + 10;
ll n;
bool a[N];

vector<ll> divisor(ll x) {
    vector<ll> v;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            v.push_back(i);
            if (i != x / i)
                v.push_back(x / i);
        }
    }
    return v;
}
bool check(ll x) {
    ll step = n / x;
    for (int i = 0; i < step; i++) {
        int j = i, cnt = 0, can = 1;
        for (; j < n, cnt < x; j += step, cnt++)
            if (!a[j])
                can = 0;

        if (x == cnt && j >= n && can)
            return true;
    }
    return false;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> v = divisor(n);
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= 3)
            if (check(v[i])) {
                cyes;
                return;
            }
    }
    cno;
    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
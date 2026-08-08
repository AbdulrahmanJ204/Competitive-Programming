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

void solve() {
    ll n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> a1, a2, a3, g1, g2, g3;
    int index = -1;
    int last = 0;
    for (int i = 0; i < n - 1; i++) {
        int x = __gcd(a[i], a[i + 1]);
        if (x >= last) {
            a1.push_back(a[i]);
            a2.push_back(a[i]);
            a3.push_back(a[i]);
            last = x;
        } else {
            index = i;
            a2.pop_back();
            a2.push_back(a[i]);
            a3.push_back(a[i]);
            break;
        }
    }

    if (index == -1) {
        cout << "YES";
        return;
    }
    for (int i = index + 1; i < n; i++) {
        a1.push_back(a[i]);
        a2.push_back(a[i]);
        if (i != index + 1)
            a3.push_back(a[i]);
    }
    for (int i = 0; i < n - 2; i++) {
        g1.push_back(__gcd(a1[i], a1[i + 1]));
        g2.push_back(__gcd(a2[i], a2[i + 1]));
        g3.push_back(__gcd(a3[i], a3[i + 1]));
    }

    is_sorted(g1.begin(), g1.end()) ||
    is_sorted(g3.begin(), g3.end()) ||
    is_sorted(g2.begin(), g2.end())
        ? cout << "YES"
        : cout << "NO";

    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
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
    string s, x;
    cin >> s >> x;
    vector<int> a(210, 0), c(210, 0), b(210, 0);
    for (int i = 0; i < s.size(); i++)
        a[i] = s[i] - '0';

    for (int i = 0; i < x.size(); i++)
        b[i] = x[i] - '0';
    for (int i = 0; i < 201; i++) {
        c[i] += a[i] + b[i];
        c[i + 1] = c[i] / 10;
        c[i] %= 10;
    }
    int start = 0;
    while (c[start] == 0)
        start++;
    int end = 209;
    while (c[end] == 0)
        end--;
    for (int i = start; i <= end; i++) {
        cout << c[i];
    }

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
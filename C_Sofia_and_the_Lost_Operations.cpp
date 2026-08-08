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
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
      s.insert(b[i]);
    }
    int z;
    cin >> z;
    int d[z];
    map<int, int> m;
    for (int i = 0; i < z; i++) {
        cin >> d[i];
    }
    int shouldRemove = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            m[b[i]]++;
            shouldRemove++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < z; i++) {
        if (m[d[i]]) {
            shouldRemove--;
            m[d[i]]--;
            cnt = 0;
        } else 
            cnt++;
    }
    if(s.find(d[z-1])!=s.end()) cnt=0;
    cnt > 0 || shouldRemove > 0 ? cout << "NO" : cout << "YES";

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
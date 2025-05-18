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
    int n, m;
    cin >> n >> m;
    set<int> s;
    int a[n + 1];
    set<int> ::iterator it= s.begin();
    for (int i = 1; i <= n; i++) {
        s.insert(it,i);
        it++;
        a[i] = -1;
    }

    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        auto it1 = s.lower_bound(l);
        auto it2 = s.upper_bound(r);
        set<int>::iterator itr;

        for (itr = it1; itr != it2; itr++) {
            int i = *itr;
            if (i != x && a[i] == -1) {
                a[i] = x;
            }
        }

        s.erase(it1, it2);
        s.insert(it2,x);
    }
    for (int i = 1; i < n + 1; i++) {
        if (a[i] == -1)
            a[i] = 0;
        cout << a[i] << ' ';
    }

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
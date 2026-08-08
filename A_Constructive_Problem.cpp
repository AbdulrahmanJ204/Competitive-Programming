#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

void solve() {
    ll n;
    cin >> n;
    int a[n];
    int mx = 0, mn = 1e9 + 9;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
        mn = min(a[i], mn);
        m[a[i]]++;
    }
    if (n == 1) {
        a[0] == 0 ? cout << "NO" : cout << "YES";
        return;
    }
    if (mn > 0)
        cout << "YES";
    else {
        int mex;
        for (int i = 0; i <= mx + 1; i++)
            if (!m[i]) {
                mex = i;
                break;
            }
        int find = mex;
        int hide = mex + 1;
        if (!m[hide]) {
            bool can = false;
            for (auto x : m)
                if (x.first > mex + 1 || x.second > 1)
                    can = true;
            can ? cout << "YES" : cout << "NO";

        } else {
            int first = -1, last = -1;
            for (int i = 0; i < n; i++)
                if (a[i] == hide && first == -1) {
                    first = i;
                    last = i;
                } else if (a[i] == hide)
                    last = i;

            for (int i = first; i < last + 1; i++) {
                m[a[i]]--;
                m[find]++;
            }
            for (int i = 0; i < hide; i++)
                if (!m[i]) {
                    cout << "NO";
                    return;
                }
            cout << "YES";
        }
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
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
    string s;
    cin >> s;
    int n = s.size();
    stack<char> stL, stR;
    vector<int> v;
    int lastHash = -1;
    for (int i = 0; i < n; i++)
        if (s[i] == '#')
            lastHash = i;

    int lastOpen = 0;
    int lastClosed = 0;
    for (int i = lastHash + 1; i < n; i++)
        if (s[i] == '(')
            lastOpen = i;
        else
            lastClosed = i;

    if (lastClosed < lastOpen) {
        cout << -1;
        return;
    }
    for (int i = lastHash + 1; i < n; i++) {
        if (s[i] == '(')
            stL.push(s[i]);
        else {
            if (stL.empty())
                stR.push(s[i]);
            else
                stL.pop();
        }
    }

    if (stL.size() > stR.size() && stL.size() > 0) {
        cout << -1;
        return;
    }
    while (!stL.empty()) {
        stL.pop();
        stR.pop();
    }

    for (int i = 0; i < lastHash; i++) {
        if (s[i] == '(')
            stL.push(s[i]);
        else if (stL.empty()) {
            cout << -1;
            return;
        } else if (s[i] == '#') {
            v.push_back(1);
            stL.pop();
        } else
            stL.pop();
    }
    ll x = stR.size() - stL.size();
    if (x >= 0) {
        cout << -1;
        return;
    }

    v.push_back(abs(x));

    for (int x : v)
        cout << x << endl;

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
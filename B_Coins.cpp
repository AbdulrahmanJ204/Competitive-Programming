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
    int cnt[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        if (s[1] == '>') swap(s[2], s[0]);
        cnt[s[0] - 'A']++;
    }
    bool can = false;
    for (int i = 0; i < 3; i++)
        if (cnt[i] == 0)
            can = true;

    if (!can) {
        cout << "Impossible";
        return;
    }

    string ans = "DDD";

    for (int i = 0; i < 3; i++) {
        ans[cnt[i]] = 'A' + i;
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
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
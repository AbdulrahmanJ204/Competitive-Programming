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
    string s;
    cin >> s;

    vector<char> v;
    int cnt[26];
    for (int i = 0; i < 26; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!cnt[s[i] - 'a']) {
            v.push_back(s[i]);
            cnt[s[i] - 'a']++;
        }
    }
    map<char, char> m;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() / 2 + v.size() % 2; i++) {
        m[v[i]] = v[v.size() - i - 1];
        m[v[v.size() - i - 1]] = v[i];
    }
    
    for (int i = 0; i < n; i++) {
        s[i] = m[s[i]];
    }
    cout << s;
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
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
    int index;
    string s;
    cin >> s;
    cin >> index;
    index--;
    char mx='0';
    for (int i = 0; i < s.size(); i++)
    {
      if(s[i]>=mx)  mx=s[i];
    }
    
    char pre = '?';
    if (index > 0)
        pre = s[index - 1];
    char suf = '?';
    if (index < s.size() - 1)
        suf = s[index + 1];
    if (suf != '?')
        s[index + 1] = mx + 1;
    if (pre != '?')
        s[index - 1] = mx + 1;
    sort(s.begin(), s.end());
    // cout<<s<<endl;
    string ans = "";
    int i = 0;
    while (i < index - 1) {
        ans += s[i];
        i++;
    }
    if (pre != '?')
        ans += pre;

    ans += s[i];
    i++;
    if (suf != '?')
        ans += suf;
    while (i < s.size() - 2) {
        ans += s[i];
        i++;
    }
    cout << ans;
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
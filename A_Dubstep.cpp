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
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
            s[i] = s[i + 1] = s[i + 2] = '?';
        }
    }
    // cout << s << endl;
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        string temp = "";
        if (s[i] != '?') {
            while (s[i] != '?'&&i<n) {
                temp += s[i++];
            }
            if(temp!="")
            ans.push_back(temp);
        }
    }
    for(auto x: ans)cout<<x<<' ';
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
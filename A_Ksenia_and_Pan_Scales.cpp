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
    string s, s1 = "", s2 = "", x;
    cin >> s;
    cin >> x;
    int i;
    for (i = 0; i < s.size(); i++)
        if (s[i] != '|') s1 += s[i];
        else break;
    i++;
    for (; i < s.size(); i++)
        s2 += s[i];

    int size = x.size();

    for (i = 0; i < size; i++)
        if (s1.size() > s2.size())
            s2 += x[i];
        else
            s1 += x[i];
            
    if (s1.size() == s2.size())
        cout << s1 << '|' << s2;
    else
        cout << "Impossible";
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
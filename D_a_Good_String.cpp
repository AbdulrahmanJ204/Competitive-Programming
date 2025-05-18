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
ll n;
string s;

ll fun(int index, int len, char c) {
    if (len == 0 || index >= n)
        return 0;
    if (len == 1)
        return (s[index] == c) ? 0 : 1;
    ll cnt1 = 0, cnt2 = 0;
    for (int i = index; i < index + len / 2; i++)
        if (s[i] != c)
            cnt1++;
    for (int i = index + len / 2; i < index + len; i++)
        if (s[i] != c)
            cnt2++;
    ll c1 = cnt2 + fun(index, len / 2, c + 1),
       c2 = cnt1 + fun(index + len / 2, len / 2, c + 1);
    return min(c1, c2);
}
void solve() {
    cin >> n >> s;
    if (n == 1) {
      if(s=="a") cout<<0;else cout<<1;
      return;
    } else if (n == 2) {
        if (s == "ab" || s == "ba")
            cout << 0 ;
        else if (s[0] == 'b' || s[1] == 'b')
            cout << 1 ;
        else if (s[0] == 'a' || s[1] == 'a')
            cout << 1 ;
        else
            cout << 2 ;
        return ;
    }
    cout << fun(0, n, 'a');

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
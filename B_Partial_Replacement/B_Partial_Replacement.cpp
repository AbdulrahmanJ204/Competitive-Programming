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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = 0;
    int ans = 1;
    int first,last;
    int i=0;
    while(s[i]=='.') i++;
    first=i;
    i=n-1;
    while(s[i]=='.') i--;
    last=i;


    for (int i = first; i < last; i += k) {
        if (s[i] == '*')
            ans++;
        else {
            while (s[i] == '.')
                i--;
            ans++;
        }
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
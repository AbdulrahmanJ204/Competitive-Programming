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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll ans = 0;
    string x = "";
    for (int i = 0; i < n; i++) {
        char c = (abs('z' - s[i]) > abs('a' - s[i])) ? 'z' : 'a';
        int dif = abs(c - s[i]);
        if (ans + dif == k) {
            ans += dif;
            x += c;
            i++;
            while (i < n) {
                x += s[i];
                i++;
            }
            break;
        } else if (ans + dif > k) {
            if (c == 'a') {
                while (ans + s[i] - c > k) {
                    c++;
                }
                ans += abs(s[i] - c);
                x += c;
                i++;
                while (i < n) {
                    x += s[i];
                    i++;
                }
            } else {
                while (ans + abs(c - s[i]) > k) {
                    c--;
                }
                ans += abs(s[i] - c);
                x += c;
                i++;
                while (i < n) {
                    x += s[i];
                    i++;
                }
                break;
            }
        } else {
            ans += dif;
            x += c;
        }
    }
    if (ans >= k)
        cout << x;
    else
        cout << -1;

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
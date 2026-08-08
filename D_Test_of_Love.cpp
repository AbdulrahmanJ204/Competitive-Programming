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
int n, m, water;
string s;

bool fun(int index) {

    if (index > n)
        return water>=0;

    if (s[index] == 'C')
        return false;

    if (s[index] == 'W') {
        int i = index;
        while (i <= n) {
            if (s[i] == 'C')
                return false;
            if (s[i] == 'L')
                return fun(i);
            if (s[i] == 'W')
                water--;
            i++;
        }
        return water>=0;
    }

    if (s[index] == 'L') {
        int lastLog = -1;
        for (int i = index + 1; i < min(index + m + 1, n + 1); i++)
            if (s[i] == 'L')
                lastLog = i;
        if (lastLog != -1)
            return fun(lastLog);
        return fun(index + m);
    }
}
void solve() {
    cin >> n >> m >> water;
    cin >> s;
    s = "L" + s;
    fun(0) ? cout << "YES" : cout << "NO";
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
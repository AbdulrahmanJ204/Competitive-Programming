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
int lastDay(int m, int y) {
    if (m == 2)
        y % 4 == 0 && y % 100 != 0 ? return 29 : return 28;

    if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    return 31;
}
int main() {
    InTheNameOfAllah
        ll t = 1;
    while (cin >> t && t != 0) {
        ll d, m, y, c, pd, pm, py, pc;
        cin >> pd >> pm >> py >> pc;
        ll n = t - 1;
        ll ans = 0, sum = 0;
        while (n--) {
            cin >> d >> m >> y >> c;
            if (py == y) {
                if (m == pm && d == pd + 1) {
                    ans++;
                    sum += c - pc;
                } else if (m == pm + 1 && lastDay(pm, py) == pd && d == 1) {
                    ans++;
                    sum += c - pc;
                }

            } else if (py + 1 == y && pm == 12 && m == 1 && pd == 31 && d == 1) {
                ans++;
                sum += c - pc;
            }

            pd = d;
            pm = m;
            py = y;
            pc = c;
        }
        cout << ans << ' ' << sum << endl;
    }
    return 0;
}
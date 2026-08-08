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
ll lcm(ll a, ll b) {
    ll ans = a * b / __gcd(a, b);
    return ans;
}

void solve() {
    ll n, m, a, d;
    cin >> n >> m >> a >> d;
    ll v[5];
    v[0] = a;
    for (ll i = 1; i < 5; i++)
        v[i] = a + i * d;

    ll cnt = 0, cnt2 = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    for (int x = 0; x < 2; x++) {
                        ll d = 1, elements = 0;
                        if (i)
                            d = lcm(v[0], d), elements++;
                        if (j)
                            d = lcm(v[1], d), elements++;
                        if (k)
                            d = lcm(v[2], d), elements++;
                        if (l)
                            d = lcm(v[3], d), elements++;
                        if (x)
                            d = lcm(v[4], d), elements++;
                        if (!elements)
                            continue;
                        int sign = elements % 2 == 1 ? 1 : -1;
                        // cout<<endl<<d<<' '<<sign<<' '<<cnt<<endl;
                        cnt += sign * m / d;
                    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    for (int x = 0; x < 2; x++) {
                        ll d = 1, elements = 0;
                        if (i)
                            d = lcm(v[0], d), elements++;
                        if (j)
                            d = lcm(v[1], d), elements++;
                        if (k)
                            d = lcm(v[2], d), elements++;
                        if (l)
                            d = lcm(v[3], d), elements++;
                        if (x)
                            d = lcm(v[4], d), elements++;
                        if (!elements)
                            continue;
                        int sign = elements % 2 == 1 ? 1 : -1;
                        cnt2 += sign * (n - 1) / d;
                    }
    // cout << m - cnt << ' ' << n - cnt2 << endl;
    cout << m - cnt - n + cnt2 + 1;

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
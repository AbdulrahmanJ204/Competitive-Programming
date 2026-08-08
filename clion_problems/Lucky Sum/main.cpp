#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll l, r;
    cin >> l >> r;
    queue<ll> q;
    ll ans = 0;
    q.push(4);
    q.push(7);
    while (l <= r) {

        ll x = q.front();
        if (x > r) {
            ans += x * (r - l + 1);
            break;
        }
        if (l <= x && !q.empty()) {
            ans = ans + x * (x - l + 1);

            l = x + 1;
            q.push(x * 10 + 4);
            q.push(x * 10 + 7);
            q.pop();
        } else if (!q.empty()) {

            q.push(x * 10 + 4);
            q.push(x * 10 + 7);
            q.pop();

        }

    }

    cout << ans << endl;
    return 0;

}
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
ll n, k;
bool check(ll mid) {
    /*
      1      |
             | |   2
      3  | | |
             | | | |   4
   5 | | | | | 6 7 8
     1 2 3 4 5
        sum1: number of all outputs for k
        sum1= 1 (the middle line) + sum from 1 to k-1(x)

        sum2: number of outputs without some small splits (taking split with more outputs is better)
        e.g: taking 2 splits : 4 and 5 , sum1 = 11 (1+ 4(4+1)/2); sum2= 3 ( 1 + 2) , sum from 1 to (2 :  5 - 2 - 1)
                                                                                                         k -mid- 1 (y)
        ans= sum1-sum2 , which is real outputs : 11-3 = 8


     */
    ll x = k - 1, y = k - mid - 1;
    ll sum1 = 1 + x * (1 + x) / 2, sum2 = y * (y + 1) / 2;
    ll ans = sum1 - sum2;
    return ans >= n;
}
void solve() {
    cin >> n >> k;
    ll l = 0, r = k, ans = 1e10;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = min(ans, mid);
        } else
            l = mid + 1;
    }
    cout << (ans == 1e10 ? -1 : ans);
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
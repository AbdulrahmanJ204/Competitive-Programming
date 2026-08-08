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
bool check(ll k) {
    ll temp = n;
    ll ans = 0;
    while(temp>0){
      temp-=k;
      ans+=k;
      temp-=temp/10;
    }
    ans+=temp;
    return ans*2 >= n;
}
void solve() {
    cin >> n;
    if (n == 1||n==2) {
        cout << 1;
        return;
    }
    ll l = 1, r = n, ans = 1e18;
    while (l <= r) {
        ll k = (l + r) / 2;
        bool x = check(k);
        if (x) {
            ans = min(ans, k);
            r = k - 1;
        } else
            l = k + 1;
    }
    cout << ans;
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
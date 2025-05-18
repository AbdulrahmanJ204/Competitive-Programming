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
int a[300010];
int check(ll len) {
    ll temp = k;
    for (int i = 0; i < len; i++) {
        if (a[i] == 0)
            temp--;
    }
    ll l = 0, r = len;
    while (r < n) {
        if (temp >= 0)
            return l;
        if (a[l] == 0)
            temp++;
        l++;
        if (a[r] == 0)
            temp--;
        r++;
    }
    if (temp >= 0)
            return l;
    return -1;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll l = 0, r = n, ans = 0,index=-1;
    while (l <= r) {
        ll len = (l + r) / 2;
        int i = check(len);
        if (i != -1) {
            if (ans <= len) {
                ans = max(ans, len);
                index = i;
            }
            l = len + 1;
        } else {
            r = len - 1;
        }
    }
    cout<<ans<<endl;
    for (int i = index; i < index+ans; i++)
    {
      a[i]=1;
    }
    for (int i = 0; i < n; i++)
    {
      cout<<a[i]<<' ';
    }
    
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
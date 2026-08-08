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
    ll n;
    cin >> n;
    string s, x;
    cin >> s >> x;
    sort(x.begin(), x.end());
    sort(s.begin(), s.end());
    string t1 = s, t2 = x;
    int mx = 0, mn = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i] < x[j]) {
                mx++;
                x[j] = '0';
                break;
            }
        }
    }
    x = t2;
    //  cout<<s<<endl<<x<<endl;
    if (s != x) {
        int j = 0;
        for (int i = 0; i < n - mn; i++) {
            while (s[i] > x[j] && j < n) {
                mn++;
                j++;
            }
            j++;
        }
    }
    cout << mn << endl
         << mx;

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
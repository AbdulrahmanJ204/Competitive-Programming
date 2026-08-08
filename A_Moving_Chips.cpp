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
    vector<int> v;
    bool first = false;
    int lastIndex = -1, firstIndex = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            if (!first) {
                first = true;
                firstIndex = i;
            }
            lastIndex = i;
        }
        v.push_back(x);
    }
    int ans=0;
    for (int i =firstIndex; i < lastIndex; i++)
    {
        if(v[i]==0) ans++;       
    }
    cout<<ans;
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
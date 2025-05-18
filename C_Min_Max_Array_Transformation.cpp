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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)  cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
   
   
    int cnt = 0;
    vector<int> mns,mxs;
  
    for (int i = n - 1; i >= 0; i--) {
        int indexOfMn = lower_bound(b.begin(), b.end() - cnt, a[i]) - b.begin();
        int mx=b[n-cnt-1];
        int mn=b[indexOfMn];
        if(indexOfMn>=i) cnt=n-i;
        mns.push_back(mn-a[i]);
        mxs.push_back(mx-a[i]);
    }   
        reverse(mns.begin(),mns.end());
        reverse(mxs.begin(),mxs.end());
        for(auto x: mns) cout<<x<<' ';
        cendl;
        for(auto x: mxs) cout<<x<<' ';

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
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
    ll n, k;
    cin >> n >> k;
    int a[n],
        cnt = 0,
        firstNegative = -1,
        lenOfPositive = 0,
        lenOfNegative = 0,
        lastIndexOfPositive = -1;
    vector<int> v, negatives;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            cnt++;
            lenOfNegative++;
            if (lenOfPositive > 0 && firstNegative != -1) {
                v.push_back(lenOfPositive);
                lenOfPositive = 0;
            }
            if (firstNegative == -1)
                firstNegative = i;
        } else {
            if (lenOfNegative > 0) {
                negatives.push_back(lenOfNegative);
                lenOfNegative=0;
            }
            lastIndexOfPositive = i;
            lenOfPositive++;
        }
    }

        // for(auto x: negatives) cout<<x<<' ';cendl;
        if(lenOfNegative>0) negatives.push_back(lenOfNegative);
    if (lenOfPositive > 0)
        v.push_back(lenOfPositive);

    if (cnt > k) {
        cout << -1;
        return;
    }
    if (firstNegative == -1) {
        cout << 0;
        return;
    }
    int additional = k - cnt,
        size = v.size(),
        ans = negatives.size() * 2;

    if (v.size() == 0) {
        cout << 1;
        return;
    }
    if (lastIndexOfPositive < n - 1) {
        sort(v.begin(), v.end());
        for (int i = 0; i < size && additional > 0; i++) {
            if (v[i] <= additional) {
                additional -= v[i];
                ans -= 2;
            }
        }
            ans--;
    } else {
        sort(v.begin(), v.end() - 1);
        for (int i = 0; i < size - 1 && additional > 0; i++) {
            if (v[i] <= additional) {
                additional -= v[i];
                ans -= 2;
            }
        }
        if (v[size - 1] <= additional)
            ans--;
    }

    cout << ans;
    // cout<<max(ans,1);
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
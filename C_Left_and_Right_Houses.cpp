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
    string s;
    cin >> s;
    string temp = s;
    auto t = unique(temp.begin(), temp.end()) - temp.begin();
    temp.resize(t);
    if (temp.size() == 1) {
        if (temp[0] == '0')
            cout << n;
        else
            cout << 0;
        return;
    }
    s = "?" + s + "?";
    double pre[n + 2], suf[n + 2];
    for (int i = 0; i < n + 2; i++) {
        pre[i] = 0;
        suf[i] = 0;
    }
    for (int i = 1; i <= n; i++)
        if (s[i] == '0')
            pre[i] = pre[i - 1] + 1;
        else
            pre[i] = pre[i - 1];

    for (int i = n; i >= 1; i--)
        if (s[i] == '1')
            suf[i] = suf[i + 1] + 1;
        else
            suf[i] = suf[i + 1];
    vector<int> v;

    for (int i = 0; i < n + 1; i++) {
        double x = i;
        double x2 = n - i;
        if (x  <=2* pre[i] && x2  <=2* suf[i+1])
            v.push_back(i);
    }
    if(!v.size()) {
        cout<<0;
        return;
    }
    double mid = double(n) / 2;
    double low = 1e9, high = -1e9;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= mid)
            low = v[i];
        else {
            high = v[i];
            break;
        }
    }
    
    if (abs(mid - low) <= abs(mid - high))
        cout <<low;
    else
        cout << high;
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
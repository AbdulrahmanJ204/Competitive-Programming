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
ll fastPower(ll base, ll exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}

void solve() {
    ll n;
    string s1, s2;
    cin >> n;
    cin >> s1 >> s2;
    string s = "";
    vector<string> sufs;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        s+=s1[i];
        sufs.push_back(s);
    }
    string x="";
    for (int i = n - 1; i >= 0; i--)
    {   x=s2[i]+x;
        m[sufs[i]+x]++;
    }
    for(auto x: m) {
        cout<<x.first<<endl<<x.second;
        break;
    }
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
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        ll pre[n], suf[n];
        set<char> a;
        for (int i = 0; i < s.size(); ++i) {
            a.insert(s[i]);
            pre[i] = a.size();
        }
        a.clear();
        for (int i = s.size() - 1; i >= 0; --i) {
            a.insert(s[i]);
            suf[i] = a.size();
        }
        ll ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, pre[i] + suf[i + 1]);
        }
        cout << ans << endl;
    }


    return 0;

}
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
    int n, k;
    string s[n];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<int> p;
    for (int i = 0; i < k; i++)
        p.push_back(i);

    int ans = 1e9 + 10;
    do {
        int mn = 1e9, mx = 0;
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = 0; j < k; j++) {
                temp += s[i][p[j]];
            }
            mn = min(mn, stoi(temp));
            mx = max(stoi(temp), mx);
        }
        ans = min((mx - mn), ans);
    } while (next_permutation(p.begin(), p.end()));
   
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
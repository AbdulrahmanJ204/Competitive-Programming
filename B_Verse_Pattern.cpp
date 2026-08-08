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
bool vowel(char c) {
    return ((c == 'a') ||( c == 'u') || (c == 'i') || (c == 'o') || (c == 'e') || (c == 'y'));
}
void solve() {
    ll n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    string a[n];
    getline(cin, a[0]);
    for (int i = 0; i < n; i++) {
        getline(cin, a[i]);
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        // cout<<i<<' '<<a[i]<<endl;
        string s = a[i];
        for (int j = 0; j < s.size(); j++) {
            if (vowel(s[j]))
                cnt++;
        }
      // cout<<cnt<<' '<<i<<endl;
        if (cnt != p[i]) {
          // cout<<a[i]<<' '<<p[i]<<endl;
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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
#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int main() {
    InTheNameOfAllah
    test {

        string a, b;
        cin >> a >> b;
        int cnt[26];
        for (int i = 0; i < 26; ++i) {
            cnt[i] = 0;
        }
        string br = b;
        reverse(br.begin(), br.end());
        if (a == b) {
            cout << 0 << endl;
            continue;
        } else if (a == br) {
            cout << 1 << endl;
            continue;
        }
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            cnt[b[i] - 'a']++;
            cnt[a[i] - 'a']++;
        }
        bool exist = true;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2 != 0)
                exist = false;
        }
        if (a[n / 2] != b[n / 2])
            exist = false;
        for (int i = 0; i < n / 2; ++i) {
            if (a[i] != b[i] && a[i] != b[n - i - 1])
                exist = false;
        }
        if (!exist) {
            cout << -1 << endl;
            continue;
        }
        string s = "";
        for (int j = 0; j < n / 2; ++j) {
            if (a[j] == b[j]) { if (a[j] != a[n - j - 1]) s += '1'; }
            else s += '0';
        }
        ll ans = 0;
        bool one = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0' && !one) {
                ans++;
                one = true;
            } else if (s[i] == '1' && one) {
                ans++;
                one = false;
            }

        }

        cout << ans << endl;
    }
    return 0;
}
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

int main() {
    InTheNameOfAllah
        string a,
        b;
    while (cin >> a) {
        cin >> b;
        if (a == "0" || b == "0") {
            cout << 0 << endl;
            continue;
        }
        if (a.size() < b.size())
            swap(a, b);
        vector<int> ans(600);
        for (int i = 0; i < 600; i++) {
            ans[i] = 0;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < b.size(); i++) {
            int digit = b[i] - '0';
            for (int j = 0; j < a.size(); j++) {
                int mul = digit * (a[j] - '0');
                ans[j + i] += mul;
            }
        }
        for (int i = 0; i < 599; i++) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }

        reverse(ans.begin(), ans.end());
        int i = 0;
        while (ans[i] == 0)
            i++;
        if (i == 600)
            cout << '0';
        while (i < 600) {
            cout << ans[i];
            i++;
        }
        cout << endl;
    }

    return 0;
}
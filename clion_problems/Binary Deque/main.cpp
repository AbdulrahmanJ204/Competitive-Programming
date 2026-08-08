#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

int n,s;
int pre[1000000];
int check (int len) {
    bool small = false;
    for (int i = 0; i <= n - len; ++i) {
        if (pre[len + i] - pre[i] == s)
            return 0;
        else if (pre[len + i] - pre[i] < s)
            small = true;
    }
    if (small) return -1;
    return 1;
}
int main() {
    InTheNameOfAllah
    test {
        int sum = 0;
        cin >> n >> s;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum < s) {
            cout << -1 << endl;
            continue;
        } else if (sum == s) {
            cout << 0 << endl;
            continue;
        }

        pre[0] = 0;
        for (int i = 1; i < n + 1; ++i)
            pre[i] = pre[i - 1] + a[i - 1];

        ll l = 0, r = n, ans = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;
            int x = check(mid);
            if (x == 0) {
                ans = max(ans, mid);
                l = mid + 1;
            } else if (x == 1) {
                r = mid - 1;
            } else
                l = mid + 1;

        }
        cout << n - ans << endl;
    }
    return 0;
}
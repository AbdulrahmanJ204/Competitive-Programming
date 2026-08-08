    #include <bits/stdc++.h>
    using namespace std;
    #define test  ll t;cin>>t;while(t--)
    #define ll long long
    #define endl '\n'
    #define cendl cout<<endl
    #define cyes cout<<"YES"<<endl
    #define cno cout<<"NO"<<endl
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n, q;
        cin >> n >> q;
        int a[n + 1];
        int pre[101][n + 1];

        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        for (int i = 0; i < 101; ++i)
            for (int j = 0; j < n + 1; ++j)
                pre[i][j] = 0;


        for (int i = 1; i < 101; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[j] == i)
                    pre[i][j] = pre[i][j - 1] + 1;
                else
                    pre[i][j] = pre[i][j - 1];

            }
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for (int i = 1; i < 101; ++i) {
                if (pre[i][r] - pre[i][l - 1] > 0)
                    ans++;
            }
            cout << ans << endl;
        }
        return 0;
    }
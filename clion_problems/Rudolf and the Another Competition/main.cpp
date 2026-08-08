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
        ll n, m, h;
        cin >> n >> m >> h;
        ll t[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> t[i][j];
            }
            sort(t[i], t[i] + m);
        }
        ll penalty1 = 0, solved_problems1 = 0, time1 = 0;
        ll ans = 1;
        for (int j = 0; j < m; ++j) {
            if (time1 + t[0][j] <= h) {
                time1 += t[0][j];
                penalty1 += time1;
                solved_problems1++;
            } else break;
        }

        for (int i = 1; i < n; ++i) {
            ll penalty = 0, solved_problems = 0, time = 0;
            for (int j = 0; j < m; ++j) {
                if (time + t[i][j] <= h) {
                    time += t[i][j];
                    penalty += time;
                    solved_problems++;
                } else break;
            }
            if (solved_problems > solved_problems1)
                ans++;
            if ((solved_problems == solved_problems1)
                && (penalty < penalty1))
                ans++;
        }
        cout << ans << endl;

    }

    return 0;
}
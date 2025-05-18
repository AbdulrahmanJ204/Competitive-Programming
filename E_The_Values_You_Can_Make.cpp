#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define cin(v)                        \
    for (ll i = 0; i < v.size(); i++) \
        cin >> v[i];
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
const int MX = 501;
int n, k;
// bool dp[MX][MX][MX];
bool dp[MX][MX];
vector<int> x(MX);
set<int> values;
// void fun(int i, int sum, int subSum) {
   
//     if (sum == k)  {values.insert(subSum);
//     return;
//     }
//     if (i == n) return;
//     if (dp[i][sum][subSum])
//         return;
//     fun(i + 1, sum, subSum);
//     if(sum+x[i]<=k){
//     fun(i + 1, sum + x[i], subSum + x[i]);
//     fun(i + 1, sum + x[i], subSum);
//     }
//     dp[i][sum][subSum] = 1;
// }

void solve() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    // for (int i = 1; i <= n; i++) {
    //     cin >> x[i];
    // }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <=k; j++) {
    //         for (int l = 0; l <= k; l++) {
    //             dp[i][j][l] = false;
    //         }
    //     }
    // }

    dp[0][0]=1;
    for (int i = 0; i < n; i++)
    {   
        int coin=x[i];
        for (int sum = k; sum >= 0; sum--)
            if(dp[sum][sum])
                if(sum+coin<=k)
                for (int subSum = 0; subSum <= k; subSum++)
                {
                    dp[sum+coin][subSum]|=dp[sum][subSum];
                    dp[sum+coin][subSum+coin]|=dp[sum][subSum];
                } 
    }
    
    for (int subSum = 0; subSum <= k; subSum++)
        if(dp[k][subSum]) values.insert(subSum);
    
    

    // for (int i = 0; i <= n; i++)
    //     dp[i][0][0] = 1;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < k + 1; j++) {
    //         for (int l = 0; l < k + 1; l++) {
    //             dp[i][j][l] = dp[i - 1] [j] [l];
    //             if (j - x[i] >= 0) {
    //                 dp[i][j][l] |= dp[i - 1][ j - x[i]][l];
    //             if(l-x[i]>=0)dp[i][j][l] |= dp[i - 1][j - x[i]][l - x[i]];
    //             }
    //         }
    //     }
    // }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j < k + 1; j++)
    //     if(dp[i][k][j]) values.insert(j);
    // }

    // fun(0, 0, 0);
    cout << values.size() << endl;
    for (auto x : values)
        cout << x << ' ';

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
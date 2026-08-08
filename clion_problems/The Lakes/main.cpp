#include <bits/stdc++.h>
using namespace std;
#define test  ll t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int n, m;
bool visited[1002][1002];int a[1002][1002];
ll dfs(int i,int j)
{   if(i<n&&i>=0&&j>=0&&j<m) {
        if (visited[i][j])
            return 0;

        if (!visited[i][j]) {
            visited[i][j] = true;
            return a[i][j] + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j - 1) + dfs(i, j + 1);
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
        cin >> n >> m;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                if (a[i][j] == 0)
                    visited[i][j] = true;
                else
                    visited[i][j] = false;
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!visited[i][j])
                    ans = max(ans, dfs(i, j));
        cout << ans << endl;
    }
    return 0;
}
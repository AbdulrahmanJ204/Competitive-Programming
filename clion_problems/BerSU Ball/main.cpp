#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(b.begin(), b.end());

    cin >> m;
    vector<int> g;
    for (int j = 0; j < m; ++j) {
        int x;
        cin >> x;
        g.push_back(x);
    }
    sort(g.begin(), g.end());
    ll ans = 0;
    if (m < n) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < b.size(); ++j) {
                if (b[j] == g[i]) {
                    b.erase(j + b.begin());
                    ans++;
                    break;
                } else if (g[i] - 1 == b[j]) {
                    b.erase(j + b.begin());
                    ans++;
                    break;
                } else if (g[i] + 1 == b[j]) {
                    b.erase(j + b.begin());
                    ans++;
                    break;
                }
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < g.size(); ++j) {

                if (b[i] == g[j]) {
                    g.erase(j + g.begin());
                    ans++;
                    break;
                } else if (b[i] - 1 == g[j]) {
                    g.erase(j + g.begin());
                    ans++;
                    break;
                } else if (b[i] + 1 == g[j]) {
                    g.erase(j + g.begin());
                    ans++;
                    break;
                }

            }
        }
    }
    cout << ans << endl;

    return 0;

}
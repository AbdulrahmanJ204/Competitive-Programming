#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

const int maxN = 1e7;
int n;

bool vis[maxN];
int a[maxN];

void run_case() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> v;

    for (int i = 0; i <= n; i++)
        vis[i] = 0;
    int score = 0;

    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        int s1 = 0, s2 = 0;
        vector<int> cycle;
        int idx = i;
        while (!vis[idx]) {
            vis[idx] = true;
            cycle.push_back(idx);
            idx = a[idx];
        }

        for (int j = 0; j < cycle.size(); j++)
            if (j & 1)
                s1 -= cycle[j];
            else
                s1 += cycle[j];

        if (cycle.size() & 1) {
            int s = s1;
            for (int j = 0; j < cycle.size() - 1; j++) {
                int x = cycle[j];
                s = 2ll * x - s;
                s1 = max(s1, s);
            }
            v.push_back(s1);
        }
        else
            score += llabs(s1);
    }

    sort(v.rbegin(), v.rend());

    for (int i = 0; i < v.size(); i++)
        score += v[i] * (i & 1 ? -1 : 1);
    cout << score << "\n";
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run_case();
    }
    return 0;
}
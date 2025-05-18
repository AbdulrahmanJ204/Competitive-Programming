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

void solve() {

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph[n + 1];
    int s[n + 1];

    while (m--) {
        int from, to, w;
        cin >> from >> to >> w;
        graph[from].push_back({to, w});
        graph[to].push_back({from, w});
    }
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    priority_queue<pair<pair<ll, ll>, ll>> q;

    ll cost[n + 1][1010];

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < 1010; j++)
            cost[i][j] = 1e18;

    ll ans = 1e18;
    q.push({make_pair(0, -s[1]), 1});
    while (!q.empty()) {
        auto tp = q.top().first;
        ll curCost = -tp.first;
        ll curBike = -tp.second;
        ll node = q.top().second;
        q.pop();
        // if (node == n)
        //     ans = min(ans, curCost);
        if (curCost > cost[node][curBike])
            continue;
        for (auto v : graph[node]) {
            ll child = v.first;
            ll w = v.second * curBike;
            if (curCost + w < cost[child][curBike]) {
                cost[child][curBike] = curCost + w;
                q.push({make_pair(-cost[child][curBike], -curBike), child});
                if (curBike != s[child])
                    q.push({make_pair(-cost[child][curBike], -s[child]), child});
            }
        }
    }
    for(int i=1 ; i<=n ;i++)ans=min(ans,cost[n][s[i]]);
    cout << ans;
    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
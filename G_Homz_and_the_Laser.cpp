#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a *b / gcd(a, b)
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES"
#define cno cout << "NO"
#define cin(v)                        \
    for (ll i = 0; i < v.size(); i++) \
        cin >> v[i];
#define cin1(v, n)             \
    for (ll i = 0; i < n; i++) \
        cin >> v[i];
#define cin2(v, n, m)               \
    for (ll i = 0; i < n; i++)      \
        for (int j = 0; j < m; j++) \
            cin >> v[i][j];
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define cout1(v, n)            \
    for (ll i = 0; i < n; i++) \
        cout << v[i] << ' ';   \
    cendl;
#define cout2(v, n, m)                \
    for (ll i = 0; i < n; i++, cendl) \
        for (int j = 0; j < m; j++)   \
            cout << v[i][j] << ' ';
#define assign1(v, n, value)   \
    for (ll i = 0; i < n; i++) \
        v[i] = value;
#define assign2(v, n, m, value)     \
    for (ll i = 0; i < n; i++)      \
        for (int j = 0; j < m; j++) \
            v[i][j] = value;
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define oo LLONG_MAX
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int rs, cs, re, ce;
    char dcs, dce;
    cin >> rs >> cs >> dcs >> re >> ce >> dce;
    map<char, int> mp;
    int down = 0, up = 1, left = 2, right = 3;

    mp['D'] = down;
    mp['U'] = up;
    mp['L'] = left;
    mp['R'] = right;
    int ds = mp[dcs], de = mp[dce];
    string s[n + 2];
    for (int i = 0; i <= m + 1; i++)
        s[0] += ".", s[n + 1] += ".";
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = "." + s[i] + ".";
    }
    n += 2;
    m += 2;
    int dist[n][m][4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                dist[i][j][k] = 1e9;
            }
        }
    }
    auto valid = [&](int i, int j) -> bool {
        return i > -1 && i < n && j > -1 && j < m;
    };
    priority_queue<array<int, 4>> pq;
    // if (ds == up)
    //     rs++;
    // if (ds == down)
    //     rs--;
    // if (ds == right)
    //     cs--;
    // if (ds == left)
    //     cs++;
    dist[rs][cs][ds] = 0;
    pq.push({0, ds, rs, cs});
    while (pq.size()) {
        auto [cnt, dir, i, j] = pq.top();
        pq.pop();
        cnt = -cnt;
        if (dist[i][j][dir] < cnt)
            continue;
        dist[i][j][dir] = cnt;
        if (s[i][j] == '.') {
            int newI = i, newJ = j;
            if (dir == down)
                newI++;
            if (dir == up)
                newI--;
            if (dir == left)
                newJ--;
            if (dir == right)
                newJ++;

            if (!valid(newI, newJ))
                continue;
            if (cnt < dist[newI][newJ][dir]) {
                pq.push({-cnt, dir, newI, newJ});
            }
        }

        // D U L R
        // 0 1 2 3
        if (s[i][j] == '/') {
            int newI = i, newJ = j, newDir = dir;
            if (dir == down) {
                newJ--; // go left
                if (valid(newI, newJ)) {
                    newDir = left;
                    if (cnt < dist[newI][newJ][newDir]) {
                        pq.push({-cnt, newDir, newI, newJ});
                    }
                    newJ++;
                }
                newJ++; // flip and go right
                if (valid(newI, newJ)) {
                    newDir = right;
                    if (cnt + 1 < dist[newI][newJ][newDir]) {
                        pq.push({-cnt - 1, newDir, newI, newJ});
                    }
                }
            }
            if (dir == up) {
                newJ++; // go right
                if (valid(newI, newJ)) {
                    newDir = right;
                    if (cnt < dist[newI][newJ][newDir]) {
                        pq.push({-cnt, newDir, newI, newJ});
                    }
                    newJ--;
                }
                newJ--; // flip and go left
                if (valid(newI, newJ)) {
                    newDir = left;
                    if (cnt + 1 < dist[newI][newJ][newDir]) {

                        pq.push({-cnt - 1, newDir, newI, newJ});
                    }
                }
            }

            // D U L R
            // 0 1 2 3
            if (dir == left) {
                newI++; // go down
                if (valid(newI, newJ)) {
                    newDir = down;
                    if (cnt < dist[newI][newJ][newDir]) {

                        pq.push({-cnt, newDir, newI, newJ});
                    }
                    newI--;
                }
                newI--; // flip and go up
                if (valid(newI, newJ)) {
                    newDir = up;
                    if (cnt + 1 < dist[newI][newJ][newDir]) {

                        pq.push({-cnt - 1, newDir, newI, newJ});
                    }
                }
            }
            if (dir == right) {
                newI--; // go up
                if (valid(newI, newJ)) {
                    newDir = up;
                    if (cnt < dist[newI][newJ][newDir]) {

                        pq.push({-cnt, newDir, newI, newJ});
                    }
                    newI++;
                }
                newI++; // flip and go down
                if (valid(newI, newJ)) {
                    newDir = down;
                    if (cnt + 1 < dist[newI][newJ][newDir]) {

                        pq.push({-cnt - 1, newDir, newI, newJ});
                    }
                }
            }
        }
        if (s[i][j] == '\\') {
            int newI = i, newJ = j, newDir = dir;
            if (dir == up) {
                newJ--; // go left
                if (valid(newI, newJ)) {
                    newDir = left;
                    if (cnt < dist[newI][newJ][newDir]) {

                        pq.push({-cnt, newDir, newI, newJ});
                    }
                    newJ++;
                }
                newJ++; // flip and go right
                if (valid(newI, newJ)) {
                    newDir = right;
                    if (cnt + 1 < dist[newI][newJ][newDir]) {

                        pq.push({-cnt - 1, newDir, newI, newJ});
                    }
                }
            }
            if (dir == down) {
                newJ++; // go right
                if (valid(newI, newJ)) {
                    newDir = right;
                    if (cnt < dist[newI][newJ][newDir]) {

                        pq.push({-cnt, newDir, newI, newJ});
                    }
                    newJ--;
                }
                newJ--; // flip and go left
                if (valid(newI, newJ)) {
                    newDir = left;
                    if (cnt + 1 < dist[newI][newJ][newDir]) {

                        pq.push({-cnt - 1, newDir, newI, newJ});
                    }
                }
            }

            // D U L R
            // 0 1 2 3
            if (dir == right) {
                newI++; // go down
                if (valid(newI, newJ)) {
                    newDir = down;
                    if (cnt < dist[newI][newJ][newDir]) {

                        pq.push({-cnt, newDir, newI, newJ});
                    }
                    newI--;
                }
                newI--; // flip and go up
                if (valid(newI, newJ)) {
                    newDir = up;
                    if (cnt + 1 < dist[newI][newJ][newDir]) {

                        pq.push({-cnt - 1, newDir, newI, newJ});
                    }
                }
            }
            if (dir == left) {
                newI--; // go up
                if (valid(newI, newJ)) {
                    newDir = up;
                    if (cnt < dist[newI][newJ][newDir]) {

                        pq.push({-cnt, newDir, newI, newJ});
                    }
                    newI++;
                }
                newI++; // flip and go down
                if (valid(newI, newJ)) {
                    newDir = down;
                    if (cnt + 1 < dist[newI][newJ][newDir]) {

                        pq.push({-cnt - 1, newDir, newI, newJ});
                    }
                }
            }
        }
    }
    // D U L R
    // 0 1 2 3
    if (de == down)
        re++;
    if (de == up)
        re--;
    if (de == left)
        ce--;
    if (de == right)
        ce++;
    int ans = dist[re][ce][de];
    if (ans >k)
        ans = -1;
    cout << ans;
    return;
}

int32_t main() {
    InTheNameOfAllah
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
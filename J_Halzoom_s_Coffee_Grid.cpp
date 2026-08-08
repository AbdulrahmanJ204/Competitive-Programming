#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int short
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
    n++, m++;

    int a[n][m];
    int pre[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i][j] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    set<array<int, 4>> good;
    pair<bool, int> b[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            b[i][j] = {false, 0};
        }
    }

    for (int i1 = 1; i1 < n; i1++) {
        for (int j1 = 1; j1 < m; j1++) {
            for (int i2 = i1; i2 < n; i2++) {
                for (int j2 = j1; j2 < m; j2++) {
                    int sum = pre[i2][j2] - pre[i1 - 1][j2] - pre[i2][j1 - 1] + pre[i1 - 1][j1 - 1];
                    if (sum == k) {
                        for (int i = i1; i <= i2; i++) {
                            for (int j = j1; j <= j2; j++) {
                                if (b[i][j].first) {
                                    j = b[i][j].second ;
                                } else
                                    b[i][j] = {true, j2};
                            }
                        }
                    }
                }
            }
        }
    }

    //   for(auto &x : good){
    //     // cout<<x.first.first<<" "
    //     // <<x.first.second<<" p2 : "
    //     // <<x.second.first<<" "<<x.second.second<<endl;
    //     // cout1(x ,4);
    //   for(int i = x[0] ; i<= x[2] ; i++)
    //   for(int j = x[1] ; j<=x[3]; j++)
    //   {
    //     if(b[i][j].first){
    //       j = b[i][j].second;
    //     }
    //     else
    //     b[i][j] ={true , x[3]};
    //   }

    // }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (b[i][j].first)
                cout << a[i][j] << " ";
            else
                cout << 0 << ' ';
        }
        cendl;
    }

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
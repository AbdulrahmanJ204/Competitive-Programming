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

map<int, map<int, int>> mp;
vector<int> factors;
map<int, int> primesCnt;
void sieveFactorization(int N) {
    factors.resize(N + 1, 1);
    for (int i = 2; i <= N; ++i) {
        if (factors[i] == 1) { // If i is prime
            for (int j = i; j <= N; j += i) {
                factors[j] = i;
            }
        }
    }
}
void getFactorization(int x) {
    if (mp.count(x))
        return;
    int y = x;
    while (x != 1) {
        mp[y][factors[x]]++;
        x = x / factors[x];
    }
}
void solve(){
    int n; cin >> n;
    vector<int> a(n);
    cin1(a,n);
    set<int> st(all(a));
    for (int x: st) getFactorization(x);

    map<int,int> maxExp;
    for (int x: st){
        for (auto [p,e]: mp[x])
            maxExp[p] = max(maxExp[p], e);
    }

    vector<int> primes;
    for (auto [p,e]: maxExp) primes.push_back(p);
    int k = primes.size();
    if (k==0){ cout << 1; return; }

    int FULL = (1<<k)-1;

    vector<int> masks;
    for (int x: st){
        int mask = 0;
        for (int i=0;i<k;i++){
            int p=primes[i];
            if (mp[x][p]==maxExp[p]) mask |= (1<<i);
        }
        masks.push_back(mask);
    }

    const int INF = 1e9;
    vector<int> dp(1<<k, INF);
    dp[0]=0;
    for (int m:masks){
        for (int mask=FULL; mask>=0; --mask){
            dp[mask|m] = min(dp[mask|m], dp[mask]+1);
            if(mask==0) break;
        }
    }
    cout << dp[FULL];
}

int32_t main() {
    InTheNameOfAllah
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        sieveFactorization(1e6+10);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
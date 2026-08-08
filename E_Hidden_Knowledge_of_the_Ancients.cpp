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
    ll n;
    int k, L, R;
    cin >> n >> k >> L >> R;
    int a[n];
    cin1(a, n);
    int ans = 0;
    map<int, int> mp;
    int dist = 0;
    int left =0;
    // L <= right - left + 1 <= R
    // L - right -1 <= -left <= R - right - 1
    // right + 1 - L <= left <= right +1 -R
    // st <= left <= ed
    for (int right = 0; right < n; right++) {
        mp[a[right]]++;
        if (mp[a[right]] == 1)
            dist++;
        while (dist > k) {
            mp[a[left]]--;
            if (mp[a[left]] == 0) {
                dist--;
            }
            left++;
        }
        
        int st = max(left, right - R + 1); 
        int ed = right - L + 1;            
        if (ed >= st)
            ans += ed - st + 1;
    }
    dist = 0;
    left =0;
    mp.clear();
    for (int right = 0; right < n; right++) {
        mp[a[right]]++;
        if (mp[a[right]] == 1)
            dist++;
        while (dist > k-1) {
            mp[a[left]]--;
            if (mp[a[left]] == 0) {
                dist--;
            }
            left++;
        }
       
        int st = max(left, right - R + 1); 
        int ed = right - L + 1;            
        if (ed >= st)
            ans -= ed - st + 1;
    }
    cout << ans;
    return;
}

int32_t main() {
    InTheNameOfAllah
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
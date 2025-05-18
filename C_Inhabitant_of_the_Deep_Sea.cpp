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
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

void solve() {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    cin1(a, n);
    int i = 0, j = n - 1;
    bool first = true;
    ll ans = 0;
    while (k > 0 && i < j) {
        ll mn = min({a[i], a[j]});
        if(k<mn) break;
        if(k<2*mn){
          ans+=(a[i]<=(k+1)/2);
          break;
        }
        a[i]-=mn;
        a[j]-=mn;
        k-=2*mn;
        if(!a[i]) ans++,i++;
        if(!a[j]) ans++,j--;
        

    }
    if (i == j)
        ans += (a[i] <= k && k > 0);
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
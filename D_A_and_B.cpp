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
    cin >> n;
    string s;
    cin >> s;
    int a[n + 1], b[n + 1];
    a[0] = b[0] = 0;
    int mnA = -1, mxA = -1, mnB = -1, mxB = -1;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (s[i - 1] == 'a');
        b[i] = b[i - 1] + (s[i - 1] == 'b');
        if (s[i - 1] == 'a') {
            mxA = i;
            if (mnA == -1)
                mnA = i;
        } else {
            mxB = i;
            if (mnB == -1)
                mnB = i;
        }
    }
    if (mnA == -1 || mnB == -1) {
        cout << 0;
        return;
    }
    if(mxA < mnB || mxB < mnA){
      cout<<0;
      return;
    }
    // cout1(a, n + 1);
    // cout1(b, n + 1);
    int ansA = 0 , ansB = 0;
    for (int i = mnA; i < mxA; i++)
    {

      if(s[i-1]=='b'){
        int bL = b[i-1]- b[mnA] , bR = b[mxA] - b[i];
        int left = i - mnA , right = mxA - i;
        ansA += min( left-bL , right - bR);
      }
    }
    for (int i = mnB; i < mxB; i++)
    { 
      if(s[i-1]=='a'){
        int aL = a[i-1]- a[mnB] , aR = a[mxB] - a[i];  
        int left = i - mnB , right = mxB - i;
        ansB += min( left-aL , right - aR);
      }
    }
    int ans = min(ansA , ansB);
    cout<<ans;
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
#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

const int N = 60;
int a[N];
ll n;
int dif(int a, int b) {
    return abs(a - b);
}
int getInstability(int x, int y) {
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (i == x || i == y)
            continue;
        else if (i == x - 1 || i == y - 1) {
            ans += dif(a[i], a[i + 2]);
            i += 2;
        } else {
            ans += dif(a[i], a[i + 1]);
            i++;
        }
    }
    return ans;
}
void solve() {

    cin >> n;
    
    n *= 2;
    
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    int ans = 1e9;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = min(ans, getInstability(i, j));

    cout << ans;

    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
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

void solve() {
    double d, h, v, e;

    cin >> d >> h >> v >> e;
    double area = d * d / 4 * acos(-1);
    double size = area * h;
    double ratio=area*e-v;
    if(ratio>=0) cout<<"NO";
    else {
        cout<<"YES\n";
        double ans=abs(size/ratio);
        cout<<fixed<<setprecision(12)<<ans;
    }
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
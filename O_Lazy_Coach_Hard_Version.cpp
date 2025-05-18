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
    int n, q;
    cin >> n >> q;

    int a[n + 1];
    int nextIndex[n + 1];
    map<int, vector<int>> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]].push_back(i);
    }

    nextIndex[n] = n + 1;
    a[0] = nextIndex[0] = 0;
    
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] != a[i + 1]) {
            nextIndex[i] = i + 1;
        } else
            nextIndex[i] = nextIndex[i + 1];
    }
    // tryAndCry(a);
    // tryAndCry(nextIndex);
    // for (auto x : m) {
    //     cout << x.first << " : ";
    //     tryAndCry(x.second)
    //         cendl;
    // }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if(l==r|| nextIndex[l]>=r){
            cyes;
            continue;
        }
        int i1=lower_bound(m[a[l]].begin(),m[a[l]].end(),l)-m[a[l]].begin();
        int i2=upper_bound(m[a[l]].begin(),m[a[l]].end(),r)-m[a[l]].begin()-1;
        int len1=i2-i1+1;

        int index=nextIndex[l];
        // if(index==n+1) index=n;

        i1=lower_bound(m[a[index]].begin(),m[a[index]].end(),l)-m[a[index]].begin();
        i2=upper_bound(m[a[index]].begin(),m[a[index]].end(),r)-m[a[index]].begin()-1;

        int len2=i2-i1+1;

        len1+len2==(r-l+1)? cout<<"YES\n": cout<<"NO\n";

        
    }

    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        // cendl;
    }
    return 0;
}
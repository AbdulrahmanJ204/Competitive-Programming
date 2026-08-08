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
    int n;
    cin >> n;
    int a[n];
    vector<pair<int, int>> b; // sorted with indices
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b.push_back(make_pair(a[i], i));
    }
    sort(b.begin(), b.begin() + n);
    vector<int> v;
    for (int i = n - 1; i >= 0; i--) {
        int j = i - 1;
        v.clear();
        v.push_back(b[i].second);
        while (j >= 0 && (int)(b[i].first ^ b[j].first) < 4) {
            v.push_back(b[j].second);
            j--;
        }
        sort(v.begin(),v.end());
        for(int k=0; k<v.size();k++){
            a[v[k]]=b[j+k+1].first;
        }
        i=j+1;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
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
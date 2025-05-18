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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    // int ind[m];
    priority_queue<int> ind;
    for (int i = 0; i < m; i++) {
        // cin>>ind[i];
        int x;
        cin >> x;
        x--;
        ind.push(-x);
    }
    string c;
    cin >> c;
    priority_queue<int> chars;
    set<int> st;
    for (auto x : c)
        chars.push(-(int)x);
    while (!ind.empty() && !chars.empty()) {
        int index = -ind.top();
        ind.pop();
        if (st.find(index)!=st.end())
            continue;
        st.insert(index);
        char x = -chars.top();
        chars.pop();
        // if(x<s[index]){
        s[index] = x;
        // }
    }
    cout << s;
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
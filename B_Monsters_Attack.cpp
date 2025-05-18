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

    ll n, k;
    cin >> n >> k;
    ll a[n], x[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back(make_pair(x[i], a[i]));
    }
    sort(v.begin(), v.end());
    stack<pair<int, int>> neg, pos, temp;
    for (int i = 0; i < n; i++) {
        if (v[i].first > 0)
            temp.push(v[i]);
        else
            neg.push(v[i]);
    }
    while (!temp.empty()) {
        pos.push(temp.top());
        temp.pop();
    }
    ll p = 0;
    while (p <= n) {
        int z = k;
        while (z > 0&&(!pos.empty()||!neg.empty())) {
            if (!pos.empty() && !neg.empty()) {
                if(pos.top().first==p||abs(neg.top().first)==p)
                {
                    cout<<"NO";
                    return;
                }
                if (pos.top().first <= abs(neg.top().first)) {
                    ll mn = min(pos.top().second, z);
                    z -= mn;
                    pos.top().second -= mn;
                    if (!pos.top().second)
                        pos.pop();
                }
                else {
                    ll mn = min(abs(neg.top().second),z);
                    z -= mn;
                    neg.top().second -= mn;
                    if (!neg.top().second)
                        neg.pop();
                }
            } else if (!pos.empty()) {
                if(pos.top().first==p)
                {
                    cout<<"NO";
                    return;
                }
                ll mn = min(pos.top().second, z);
                    z -= mn;
                    pos.top().second -= mn;
                    if (!pos.top().second)
                        pos.pop();
            } else if (!neg.empty()) {
                if(abs(neg.top().first)==p)
                {
                    cout<<"NO";
                    return;
                }
                 ll mn = min(abs(neg.top().second), z);
                    z -= mn;
                    neg.top().second -= mn;
                    if (!neg.top().second)
                        neg.pop();
            }
        }
        p++;
    }
    cout << "YES";
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
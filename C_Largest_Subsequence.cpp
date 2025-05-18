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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    bool sorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            sorted = false;
        }
    }
    if (sorted) {
        cout << 0;
        return;
    }
    vector<int> v[26];
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a'].push_back(i);
    }

    vector<int> indices;
    int last = 0;
    ll mxSize = 0;
    for (int i = 26 - 1; i >= 0; i--) {
        int index = lower_bound(v[i].begin(), v[i].end(), last) - v[i].begin();
        if (index < v[i].size())
            for (int j = index; j < v[i].size(); j++) {
                if (indices.empty())
                    mxSize = v[i].size();
                indices.push_back(v[i][j]);
                last = v[i][j];
            }
    }

    int size = indices.size();
    for (int i = 0; i < size / 2; i++) {
        int a = indices[i], b = indices[size - i - 1];
        swap(s[a],s[b]);
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            cout << -1;
            return;
        }
    }
    cout << indices.size() - mxSize;

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
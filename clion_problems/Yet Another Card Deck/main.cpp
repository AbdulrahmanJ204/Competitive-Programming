#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, q1;
    cin >> n >> q1;
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        q.push_back(x);
    }
    while (q1--) {
        int x;
        cin >> x;
        for (auto i = q.begin(); i != q.end(); ++i) {
            if (*i == x) {
                cout << (i - q.begin() + 1) << ' ';
                q.erase(i);
                q.push_front(x);
                break;
            }
        }
    }
    return 0;
}

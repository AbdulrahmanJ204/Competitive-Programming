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

const int N = 21;
ll a[N], b[N];
vector<int> v;
ll n;
int mx = 0, mn = 0, po = 0, ne = 0;
void pos() {

    while (a[mx] + a[mn] < 0) {
        a[mx] *= 2;
        v.push_back(mx + 1);
        v.push_back(mx + 1);
    }
    for (int i = 1; i < n; i++) {
        if (a[i] < 0) {
            a[i] += a[mx];
            v.push_back(i + 1);
            v.push_back(mx + 1);
        }
    }
    for (int i = 1; i < n; i++) {
        if(a[i]<a[i-1]){
            a[i] += a[i - 1];
            v.push_back(i + 1);
            v.push_back(i);
        }
    }
}

void neg() {

    while (a[mx] + a[mn] > 0) {
        a[mn] *= 2;
        v.push_back(mn + 1);
        v.push_back(mn + 1);
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > 0) {
            a[i] += a[mn];
            v.push_back(i + 1);
            v.push_back(mn + 1);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            a[i] += a[i + 1];
            v.push_back(i + 1);
            v.push_back(i + 2);
        }
    }
}
void reset() {
    if (v.size())
        v.clear();
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}
void solve() {
    cin >> n;
    po = ne = mn = mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        if (a[i] > 0)
            po++;
        if (a[i] < 0)
            ne++;
    }
    if (v.size())
        v.clear();
    if (is_sorted(a, a + n) || n == 1) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] >= a[mx])
            mx = i;
        if (a[mn] >= a[i])
            mn = i;
    }

    if (!ne) {
        for (int i = 1; i < n; i++) {
            a[i] += a[i - 1];
            v.push_back(i + 1);
            v.push_back(i);
        }
    } else if (!po) {
        for (int i = n - 2; i >= 0; i--) {
            a[i] += a[i + 1];
            v.push_back(i + 1);
            v.push_back(i + 2);
        }
    } else {
        pos();
        if (!is_sorted(a, a + n) || v.size() > 62) {
            reset();
            neg();
        }
    }
    // cout<<"\nARR: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a[i]<<' ';
    // }cendl;

    cout << v.size() / 2 << endl;
    for (int i = 0; i < v.size(); i += 2) {
        cout << v[i] << ' ' << v[i + 1] << endl;
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
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

void solve() {
    cin >> n;
    int p = 0, e = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        if (a[i] > 0)
            p++;
        if (a[i] < 0)
            e++;
    }
    v.clear();

    if (is_sorted(a, a + n)||n==1) {
        cout << 0 << endl;
        return;
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
        if (a[i] >= a[mx])
            mx = i;

    if (p) {
        while (a[mx] <= 20) {
            a[mx] += a[mx];
            v.push_back(mx + 1);
            v.push_back(mx + 1);
        }
        a[1]+=a[mx]*2;
        v.push_back(2);
        v.push_back(mx+1);
        v.push_back(2);
        v.push_back(mx+1);
        for (int i = 2; i < n; i++) {
                
            while (a[i] < a[i - 1]) {
                a[i] += a[i-1];
                v.push_back(i + 1);
                v.push_back(i );
            }
            if(a[i]>a[mx]) mx=i;
        }
        // for (int i = 1; i < n; i++) {
        //     a[mx] += a[mx];
        //     v.push_back(mx + 1);
        //     v.push_back(mx + 1);
        //     a[i] += a[mx];
        //     v.push_back(i + 1);
        //     v.push_back(mx + 1);
        //     if (a[i] > a[mx])
        //         mx = i;
        // }
    } else {
        for (int i = n - 2; i >= 0; i--) {
            a[i] += a[i + 1];
            v.push_back(i + 1);
            v.push_back(i + 2);
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
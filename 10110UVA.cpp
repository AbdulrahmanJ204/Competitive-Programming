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

int main() {
    InTheNameOfAllah
    while (true) {
        ll n;
        cin >> n;
        if (n == 0)
            break;
        ll x = sqrt(n);
        if (x * x == n)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
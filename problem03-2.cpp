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
int readInt() {
    int n;
    cin >> n;
    return n;
}
bool isPerfect(int n) {
  int sum = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0)
            sum += i;
    return sum == n;
}

void solve() {
    int n = readInt();
    isPerfect(n) ? cout << n << " is perfect" : cout << n << " is not perfect";
    cendl;
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
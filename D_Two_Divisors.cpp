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
const int lastNinSieve = 1e7 + 2;
int primes[lastNinSieve];

void sieve() {
    for (int i = 0; i < lastNinSieve; i++)
        primes[i] = 0;
    for (ll p = 2; p < lastNinSieve; p++)
        if (!primes[p])
            for (ll i = p; i < lastNinSieve; i += p)
                primes[i] = p;
}
int getWhatever(int x) {
    ll ans = 1;
    int temp = primes[x];
    while (x % temp == 0) {
        ans *= temp;
        x /= temp;
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sieve();
    vector<int> v1, v2;
    for (int i = 0; i < n; i++) {

        int first = getWhatever(a[i]);
        int second = a[i] / first;

        if (__gcd(first + second, a[i]) != 1 || first == 1 || second == 1)
            first = second = -1;

        v1.push_back(first);
        v2.push_back(second);
    }
    tryAndCry(v1);
    tryAndCry(v2);

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
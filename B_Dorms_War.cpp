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
ll sum(ll x, ll y, ll mod);
ll fastPower(ll base, ll exponent);
vector<ll> factorization(ll x);
bool isPrime(ll x);
vector<ll> divisor(ll x);
int sum_1_to_n(int n);
int sum_in_range(int lower, int upper);
const ll lastNinSieve = 0;
vector<bool> primes(lastNinSieve + 1, true);
void sieve();
ll mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    bool special[26];
    for (int i = 0; i < 26; i++) {
        special[i] = false;
    }
    char c;
    for (int i = 0; i < k; i++) {
        cin >> c;
        special[c - 'a'] = true;
    }
    bool exist = false;
    int first = -1;
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (special[s[i] - 'a']) {
            exist = true;
            last = i;
            if (first == -1)
                first = i;
        }
    }
    if (!exist) {
        cout << 0;
        return;
    }
    if (first == last) {
        cout << first;
        return;
    }
    int ans = 0;
    int mx = 0;
    int temp = 0;
    for (int i = first; i < last; i++) {
        if (s[i + 1] == s[i] && special[s[i + 1] - 'a']) {
        } else if (!special[s[i + 1] - 'a']) {
            temp++;
        } else {
            temp = 0;
        }
        mx = max(temp, mx);
    }
    if (first <= mx)
        ans++;
    mx = max(first, mx);
    ans += mx;

    cout << ans;

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
ll sum(ll x, ll y, ll mod) {
    return (x % mod + y % mod) % mod;
}
ll sub(ll x, ll y, ll mod) {
    return (x % mod - y % mod + mod) % mod;
}
ll mul(ll x, ll y, ll mod) {
    return (x % mod * y % mod) % mod;
}
ll fastPower(ll base, ll exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = mul(result, base, mod) % mod;
        }
        base = mul(base, base, mod) % mod;
        exponent /= 2;
    }
    return result % mod;
}
vector<ll> factorization(ll x) {
    vector<ll> v;
    for (ll i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            x /= i;
            v.push_back(i);
        }
    }
    if (x > 1)
        v.push_back(x);
    return v;
}
bool isPrime(ll x) {
    if (x == 1)
        return false;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
vector<ll> divisor(ll x) {
    vector<ll> v;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            v.push_back(i);
            if (i != x / i)
                v.push_back(x / i);
        }
    }
    return v;
}

int sum_1_to_n(int n) {
    return (n * (n + 1) / 2);
}
int sum_in_range(int lower, int upper) {
    return (upper - lower + 1) * (lower + upper) / 2;
}
void sieve() {
    primes[0] = primes[1] = 0;
    for (ll p = 2; p <= lastNinSieve; p++) {
        if (primes[p])
            for (ll i = p * p; i <= lastNinSieve; i += p)
                primes[i] = 0;
    }
}
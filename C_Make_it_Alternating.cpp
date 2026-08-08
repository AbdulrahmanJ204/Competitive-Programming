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
ll mul(ll x, ll y, ll mod);
void sieve();
ll mod = 998244353;
ll dp[200001];
/* ll factorial(ll n){
    if(n==1||n==0) return 1;
    if(n<dp.size()) return dp[n];
    return mul(n,factorial(n-1),mod);
} */
void solve() {
    string s;
    cin >> s;
    string temp = s;
    int x = unique(s.begin(), s.end()) - s.begin();
    s.resize(x);
    ll ans = temp.size() - s.size();
    s = temp;
    cout << ans << ' ';
    ll pre=ans;
    ans = 1;
    int n = s.size();
    // cout << s << endl;
    ll blocks=0;
    for (int i = 0; i < n; i++) {
        ll cnt = 0;
        if (s[i] == '1') {
            while (s[i] == '1') {
                cnt++;
                i++;
            }
        } else {
            while (s[i] == '0') {
                cnt++;
                i++;
            }
        }
        i--;
        // cout << cnt << endl;
        if(cnt>=2)
        blocks++;
        // ans = mul(ans, dp[cnt], mod);
    }
    // if (blocks>1)
        // ans= mul(ans,pre,mod);
    for (int i = 0; i < n; i++) {
        ll cnt = 0;
        if (s[i] == '1') {
            while (s[i] == '1') {
                cnt++;
                i++;
            }
        } else {
            while (s[i] == '0') {
                cnt++;
                i++;
            }
        }
        i--;
        // cout << cnt << endl;
        
        ans=mul(ans,cnt,mod);
    }
        ans = mul(ans, dp[pre], mod);

    cout << ans;
    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    dp[0] = 1;
    dp[1] = 1;
    for (ll i = 2; i < 200001; i++) {
        dp[i] = mul(dp[i - 1], i, mod);
    }
    /*  for (int i = 0; i < 200001; i++)
    {
        cout<<dp[i]<<' ';
    } */
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
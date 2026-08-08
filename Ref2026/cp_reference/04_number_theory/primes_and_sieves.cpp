// Purpose: Extended Euclidean Algorithm - finds x,y such that ax + by = gcd(a,b)
// Time: O(log(min(a,b)))
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

// Purpose: Solve Linear Diophantine Equation ax + by = c
// Time: O(log(min(a,b)))
pair<ll, ll> solveLinearDiophantine(ll a, ll b, ll c) {
    ll g = abs(gcd(a, b));
    if (c % g != 0) {
        return make_pair(LLONG_MIN, LLONG_MIN);
    }
    ll x, y;
    extgcd(a, b, x, y);
    x *= (c / g);
    y *= (c / g);
    return make_pair(x, y);
}

// Purpose: Sieve of Eratosthenes - find all primes up to MAXN
// Time: O(n log log n)
vector<bool> is_prime(MAXN, true);
vector<ll> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j < MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

// Purpose: Segmented Sieve for large ranges - count primes up to n
// Time: O(n log log sqrt(n))
ll count_primes(ll n) {
    const ll S = 10000;

    vector<ll> primes;
    ll nsqrt = sqrt(n);
    vector<bool> is_prime(nsqrt + 2, true);
    for (ll i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    ll result = 0;
    vector<bool> block(S);
    for (ll k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        ll start = k * S;
        for (ll p : primes) {
            ll start_idx = (start + p - 1) / p;
            ll j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (ll i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}

// Purpose: Prime factorization of a number
// Time: O(sqrt(n))
vector<ll> primeFactors(ll n) {
    vector<ll> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (ll d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

// Purpose: Sieve for factorization - precompute smallest prime factor for each number
// Time: O(n log log n) preprocessing
vector<vector<ll>> sieveFactorization(ll N) {
    vector<vector<ll>> factors(N + 1);
    for (ll i = 2; i <= N; ++i) {
        if (factors[i].empty()) {
            for (ll j = i; j <= N; j += i) {
                factors[j].push_back(i);
            }
        }
    }
    return factors;
}

// Purpose: Find all divisors of a number
// Time: O(sqrt(n))
vector<ll> getDivisors(ll n) {
    vector<ll> divisors;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }
    return divisors;
}

// Purpose: Sieve to find all divisors for numbers 1 to N
// Time: O(n log n)
vector<vector<ll>> divisorSieve(ll N) {
    vector<vector<ll>> divisors(N + 1);
    for (ll i = 1; i <= N; ++i) {
        for (ll j = i; j <= N; j += i) {
            divisors[j].push_back(i);
        }
    }
    return divisors;
}

// Purpose: Miller-Rabin Primality Test - probabilistic primality test
// Time: O(k log³ n) where k is number of iterations
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(u64 n, int iter = 5) {
    if (n < 4)
        return n == 2 || n == 3;
    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

// Purpose: Euler's Totient Function - count numbers ≤ n that are coprime to n
// Time: O(sqrt(n))
ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// DIVISIBILITY RULES & PROPERTIES:

// Sum of divisors formula: σ(n) where n = p1^a1 * p2^a2 * ... * pk^ak
// σ(n) = (p1^(a1+1) - 1)/(p1-1) * (p2^(a2+1) - 1)/(p2-1) * ... * (pk^(ak+1) - 1)/(pk-1)

ll sumOfDivisors(ll n) {
    ll result = 1;
    for (ll i = 2; i * i <= n; i++) {
        ll count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) {
            result *= (fastPower(i, count + 1) - 1) / (i - 1);
        }
    }
    if (n > 1) {
        result *= (n + 1);
    }
    return result;
}

// Number of divisors: τ(n) where n = p1^a1 * p2^a2 * ... * pk^ak
// τ(n) = (a1+1) * (a2+1) * ... * (ak+1)

ll countDivisors(ll n) {
    ll result = 1;
    for (ll i = 2; i * i <= n; i++) {
        ll count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) {
            result *= (count + 1);
        }
    }
    if (n > 1) {
        result *= 2;
    }
    return result;
}

// Pick's Theorem: Area = Interior + Boundary/2 - 1
ll picksInterior(ll area, ll boundary) {
    return area - boundary / 2 + 1;
}


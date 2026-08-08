// Purpose: Count digits in a number
// Time: O(log n)
int countDigits(ll n) {
    return n > 0 ? (int)log10(n) + 1 : 1;
}

// Purpose: Sum of arithmetic sequence from l to r
// Time: O(1)
ll sumRange(ll l, ll r) {
    return (r - l + 1) * (l + r) / 2;
}

// Purpose: Sum of squares 1² + 2² + ... + n²
// Time: O(1)
ll sumSquares(ll n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

// Purpose: Sum of even numbers from 1 to n
// Time: O(1)
ll evenSum1ToN(ll n) {
    if (n % 2 == 1)
        n--;
    return (n * (n + 2)) / 4;
}

// Purpose: Sum of odd numbers from 1 to n
// Time: O(1)
ll oddSum1ToN(ll n) {
    if (n % 2 == 0)
        n--;
    return ((n + 1) * (n + 1)) / 4;
}

ll evenSumInRange(ll left, ll right) {
    if (left % 2 == 1)
        left++;
    if (right % 2 == 1)
        right--;
    if (left > right)
        return 0;
    return (right / 2) * (right / 2 + 1) - ((left - 1) / 2) * (((left - 1) / 2) + 1);
}

ll oddSumInRange(ll left, ll right) {
    if (left % 2 == 0)
        left++;
    if (right % 2 == 0)
        right--;
    if (left > right)
        return 0;
    return ((right + 1) / 2) * ((right + 1) / 2) - ((left - 1) / 2) * ((left - 1) / 2);
}

// Purpose: Count how many times n is divisible by d
// Time: O(log n)
ll countDivisions(ll n, ll d) {
    ll count = 0;
    while (n > 1 && n % d == 0) {
        n /= d;
        count++;
    }
    return count;
}

// COUNTING THEOREMS:

// Stirling numbers of the second kind S(n,k): number of ways to partition n objects into k non-empty subsets
vector<vector<ll>> stirlingSecond(int n, int k) {
    vector<vector<ll>> S(n + 1, vector<ll>(k + 1, 0));
    S[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            S[i][j] = (j * S[i - 1][j] + S[i - 1][j - 1]) % MOD;
        }
    }
    return S;
}

// Bell numbers: B(n) = sum of S(n,k) for k=0 to n
vector<ll> bellNumbers(int n) {
    vector<ll> bell(n + 1, 0);
    bell[0] = 1;

    for (int i = 1; i <= n; i++) {
        bell[i] = 0;
        for (int k = 0; k < i; k++) {
            bell[i] = (bell[i] + nCr(i - 1, k) * bell[k]) % MOD;
        }
    }
    return bell;
}

// Derangement numbers: number of permutations with no fixed points
ll derangement(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    ll d0 = 1, d1 = 0;
    for (int i = 2; i <= n; i++) {
        ll d2 = ((ll)(i - 1) * (d0 + d1)) % MOD;
        d0 = d1;
        d1 = d2;
    }
    return d1;
}

// ADVANCED DIVISIBILITY:

// Count numbers ≤ n that are divisible by at least one number in the set
ll inclusionExclusionDivisible(ll n, vector<ll> &divisors) {
    ll result = 0;
    int k = divisors.size();

    for (int mask = 1; mask < (1 << k); mask++) {
        ll lcm_val = 1;
        int bits = 0;

        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                lcm_val = lcm(lcm_val, divisors[i]);
                bits++;
                if (lcm_val > n)
                    break;
            }
        }

        if (lcm_val <= n) {
            ll count = n / lcm_val;
            if (bits % 2 == 1)
                result += count;
            else
                result -= count;
        }
    }

    return result;
}

// SEQUENCES & RECURRENCES:

// MULTIPLICATIVE FUNCTIONS:

// Möbius function: μ(n)
// μ(n) = 1 if n is square-free with even number of prime factors
// μ(n) = -1 if n is square-free with odd number of prime factors
// μ(n) = 0 if n is not square-free

vector<int> mobius;

void computeMobius(int n) {
    mobius.assign(n + 1, 1);
    vector<bool> isPrime(n + 1, true);

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i; j <= n; j += i) {
                isPrime[j] = false;
                mobius[j] *= -1;
            }
            // Mark multiples of i²
            for (ll j = (ll)i * i; j <= n; j += (ll)i * i) {
                mobius[j] = 0;
            }
        }
    }
}

// Euler's totient function using mobius
ll phiUsingMobius(ll n) {
    ll result = 0;
    for (ll i = 1; i <= n; i++) {
        if (mobius[i] != 0) {
            result += mobius[i] * (n / i);
        }
    }
    return result;
}

// Count pairs (i,j) where 1 ≤ i ≤ n, 1 ≤ j ≤ m, gcd(i,j) = 1
ll countCoprimePairs(ll n, ll m) {
    ll result = 0;
    for (ll i = 1; i <= min(n, m); i++) {
        result += mobius[i] * (n / i) * (m / i);
    }
    return result;
}

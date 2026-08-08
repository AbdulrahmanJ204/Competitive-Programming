// ============================================================================
//                          COMBINATORICS & FACTORIALS
// ============================================================================

// Purpose: Precompute factorials and their modular inverses
// Time: O(MAXN) preprocessing, O(1) query

ll fact[MAXN], inv[MAXN];

void precomputeFactorials() {
    fact[0] = 1;
    inv[0] = inv_mod(fact[0]);
    for (ll i = 1; i < MAXN; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = inv_mod(fact[i]);
    }
}

ll nCr(ll n, ll r) {
    if (n < r || r < 0)
        return 0;
    return mul(fact[n], mul(inv[n - r], inv[r]));
}

ll nPr(ll n, ll r) {
    if (n < r || r < 0)
        return 0;
    return mul(fact[n], inv[n - r]);
}

// ============================================================================
//                              NUMBER THEORY
// ============================================================================

// Time: O(log(min(a,b)))
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// Time: O(log(min(a,b)))
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


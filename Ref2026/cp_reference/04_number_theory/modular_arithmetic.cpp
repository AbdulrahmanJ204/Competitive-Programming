//                            MODULAR ARITHMETIC
// ============================================================================

ll sum(ll x, ll y) { return (x % MOD + y % MOD) % MOD; }
ll sub(ll x, ll y) { return (x % MOD - y % MOD + MOD) % MOD; }
ll mul(ll x, ll y) { return (x % MOD * y % MOD) % MOD; }

// Time: O(log exponent)
ll fastPower(ll base, ll exponent, ll mod = MOD) {
    ll result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = mul(result, base);
        }
        base = mul(base, base);
        exponent /= 2;
    }
    return result;
}
// Time: O(log MOD)
ll inv_mod(ll a, ll mod = MOD) {
    return fastPower(a, mod - 2, mod);
}
ll div_mod(ll a, ll b) { return mul(a, inv_mod(b)); }


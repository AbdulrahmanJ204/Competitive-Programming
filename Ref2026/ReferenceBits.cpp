// ============================================================================
//                          BITWISE OPERATIONS & FACTS
// ============================================================================

// BITWISE OPERATIONS REFERENCE:
// & (AND): 1 & 1 = 1, otherwise 0
// | (OR): 0 | 0 = 0, otherwise 1
// ^ (XOR): same bits = 0, different bits = 1
// ~ (NOT): flips all bits
// << (LEFT SHIFT): x << k = x * 2^k
// >> (RIGHT SHIFT): x >> k = x / 2^k

// Purpose: Basic bit manipulation operations
// Time: O(1)

// Check if kth bit is set (0-indexed from right)
bool isBitSet(ll n, int k) {
    return (n & (1LL << k)) != 0;
}

// Set kth bit
ll setBit(ll n, int k) {
    return n | (1LL << k);
}

// Clear kth bit
ll clearBit(ll n, int k) {
    return n & ~(1LL << k);
}

// Toggle kth bit
ll toggleBit(ll n, int k) {
    return n ^ (1LL << k);
}

// Count number of set bits (popcount)
int countSetBits(ll n) {
    return __builtin_popcountll(n);
}

// Find rightmost set bit position (1-indexed)
int rightmostSetBit(ll n) {
    return __builtin_ctzll(n) + 1; // ctz = count trailing zeros
}

// Find leftmost set bit position (1-indexed from right)
int leftmostSetBit(ll n) {
    return 64 - __builtin_clzll(n); // clz = count leading zeros
}

// USEFUL BIT FACTS:

// XOR Properties:
// a ^ a = 0
// a ^ 0 = a
// XOR is commutative and associative
// If a ^ b = c, then a ^ c = b and b ^ c = a

// Power of 2 check
bool isPowerOfTwo(ll n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Get rightmost set bit as a power of 2
ll rightmostBit(ll n) {
    return n & (-n); // or n & (~n + 1)
}

// Turn off rightmost set bit
ll turnOffRightmostBit(ll n) {
    return n & (n - 1);
}

// Get all bits after rightmost set bit (including it)
ll getAllBitsAfterRightmost(ll n) {
    return n ^ (n - 1);
}

// Turn on rightmost unset bit
ll turnOnRightmostUnsetBit(ll n) {
    return n | (n + 1);
}

// Turn off rightmost contiguous set bits
ll turnOffRightmostContiguous(ll n) {
    return n & (n + 1);
}

// Swap two numbers without extra space
void swapXOR(ll &a, ll &b) {
    if (a != b) { // Check needed to avoid a = 0
        a ^= b;
        b ^= a;
        a ^= b;
    }
}

// Multiply by power of 2
ll multiplyByPowerOf2(ll n, int k) {
    return n << k; // n * (2^k)
}

// Divide by power of 2
ll divideByPowerOf2(ll n, int k) {
    return n >> k; // n / (2^k)
}

// Modulo with power of 2
ll modWithPowerOf2(ll n, ll pow2) {
    return n & (pow2 - 1); // n % pow2, works only if pow2 is power of 2
}

// Find XOR from 1 to n
ll xorFromOneToN(ll n) {
    ll mod = n % 4;
    if (mod == 0)
        return n;
    if (mod == 1)
        return 1;
    if (mod == 2)
        return n + 1;
    return 0;
}

// Find XOR of range [l, r]
ll xorRange(ll l, ll r) {
    return xorFromOneToN(r) ^ xorFromOneToN(l - 1);
}

// Gray Code: sequence where adjacent numbers differ by exactly one bit
vector<int> generateGrayCode(int n) {
    vector<int> result;
    for (int i = 0; i < (1 << n); i++) {
        result.push_back(i ^ (i >> 1));
    }
    return result;
}

// Convert Gray code to binary
int grayToBinary(int gray) {
    int binary = 0;
    while (gray) {
        binary ^= gray;
        gray >>= 1;
    }
    return binary;
}

// Bit reversal
ll reverseBits(ll n, int totalBits = 32) {
    ll result = 0;
    for (int i = 0; i < totalBits; i++) {
        if (n & (1LL << i)) {
            result |= (1LL << (totalBits - 1 - i));
        }
    }
    return result;
}

// Next lexicographically greater number with same number of set bits
ll nextWithSameSetBits(ll n) {
    ll rightmost = n & (-n);                         // rightmost set bit
    ll nextHigher = n + rightmost;                   // add it to n
    ll rightOnesPattern = n ^ nextHigher;            // get the bits that changed
    rightOnesPattern = rightOnesPattern / rightmost; // right shift by 2
    rightOnesPattern >>= 2;
    return nextHigher | rightOnesPattern;
}

// Maximum XOR of two numbers in array
int maxXORPair(vector<int> &arr) {
    int maxXor = 0;
    int mask = 0;

    for (int i = 30; i >= 0; i--) {
        mask |= (1 << i);
        set<int> prefixes;

        for (int num : arr) {
            prefixes.insert(num & mask);
        }

        int temp = maxXor | (1 << i);
        for (int prefix : prefixes) {
            if (prefixes.count(temp ^ prefix)) {
                maxXor = temp;
                break;
            }
        }
    }
    return maxXor;
}

// ============================================================================
//                            DP SOS (Sum Over Subsets)
// ============================================================================

// Purpose: Sum Over Subsets DP - efficiently compute sum of f(Y) for all Y ⊆ X
// Time: O(n * 2^n) where n is number of bits
// Space: O(2^n)

// BASIC SOS DP:
// For each mask X, compute sum of f(Y) for all Y that are submasks of X
vector<ll> SOS_DP(vector<ll> &f) {
    int n = __builtin_ctz((int)f.size()); // f.size() should be 2^n
    vector<ll> dp = f;

    for (int bit = 0; bit < n; bit++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << bit)) {
                dp[mask] += dp[mask ^ (1 << bit)];
            }
        }
    }
    return dp;
}

// REVERSE SOS (Sum Over Supersets):
// For each mask X, compute sum of f(Y) for all Y such that X ⊆ Y
vector<ll> reverseSOS_DP(vector<ll> &f) {
    int n = __builtin_ctz((int)f.size());
    vector<ll> dp = f;

    for (int bit = 0; bit < n; bit++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (!(mask & (1 << bit))) {
                dp[mask] += dp[mask ^ (1 << bit)];
            }
        }
    }
    return dp;
}

// WALKING OVER SUBMASKS:
// Purpose: Iterate through all submasks of a given mask
// Time: O(3^n) total for all masks, O(2^popcount(mask)) for single mask

void iterateSubmasks(int mask) {
    // Method 1: Standard submask iteration
    for (int submask = mask;; submask = (submask - 1) & mask) {
        // Process submask
        if (submask == 0)
            break;
    }

    // Method 2: Including empty set
    int submask = mask;
    do {
        // Process submask
        submask = (submask - 1) & mask;
    } while (submask != mask);
}

// Generate all submasks of a given mask
vector<int> getAllSubmasks(int mask) {
    vector<int> submasks;
    for (int submask = mask;; submask = (submask - 1) & mask) {
        submasks.push_back(submask);
        if (submask == 0)
            break;
    }
    return submasks;
}

// WALKING OVER SUPERMASKS:
// Purpose: Iterate through all supermasks of a given mask in range [0, limit]
// Time: O(3^n) total for all masks

void iterateSupermasks(int mask, int limit) {
    // Method 1: Generate all supermasks up to limit
    for (int supermask = mask; supermask <= limit; supermask = (supermask + 1) | mask) {
        // Process supermask
        if (supermask == limit)
            break;
    }
}

// Generate all supermasks of a given mask within limit
vector<int> getAllSupermasks(int mask, int limit) {
    vector<int> supermasks;
    for (int supermask = mask; supermask <= limit; supermask = (supermask + 1) | mask) {
        supermasks.push_back(supermask);
        if (supermask == limit)
            break;
    }
    return supermasks;
}

// PRACTICAL APPLICATIONS:

// 1. Maximum XOR subset problem
ll maxXORSubset(vector<int> &arr) {
    int n = arr.size();
    vector<ll> dp(1 << n, 0);

    // Initialize: dp[mask] = XOR of elements corresponding to set bits in mask
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                dp[mask] ^= arr[i];
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

// 2. Count number of subsets with given XOR
int countSubsetsWithXOR(vector<int> &arr, int targetXOR) {
    int n = arr.size();
    vector<vector<int>> dp(1 << n, vector<int>(1024, 0)); // Assuming XOR values < 1024
    dp[0][0] = 1;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int xorVal = 0; xorVal < 1024; xorVal++) {
            if (dp[mask][xorVal] > 0) {
                for (int i = 0; i < n; i++) {
                    if (!(mask & (1 << i))) {
                        int newMask = mask | (1 << i);
                        int newXOR = xorVal ^ arr[i];
                        dp[newMask][newXOR] += dp[mask][xorVal];
                    }
                }
            }
        }
    }

    int result = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        result += dp[mask][targetXOR];
    }
    return result;
}

// 3. Minimum elements to remove to make XOR equal to target
int minRemovals(vector<int> &arr, int target) {
    int n = arr.size();
    vector<int> dp(1 << 20, INT_MAX); // Assuming values < 2^20
    dp[0] = 0;

    for (int x : arr) {
        for (int mask = (1 << 20) - 1; mask >= 0; mask--) {
            if (dp[mask] != INT_MAX) {
                dp[mask ^ x] = min(dp[mask ^ x], dp[mask] + 1);
            }
        }
    }

    return dp[target] == INT_MAX ? -1 : n - dp[target];
}

// 4. SOS DP for counting divisors in array
vector<ll> countDivisorsDP(vector<int> &arr, int maxVal) {
    vector<ll> cnt(maxVal + 1, 0);

    // Count frequency of each number
    for (int x : arr) {
        cnt[x]++;
    }

    // SOS DP on divisor lattice
    for (int i = 1; i <= maxVal; i++) {
        for (int j = 2 * i; j <= maxVal; j += i) {
            cnt[i] += cnt[j];
        }
    }

    return cnt;
}

// 5. Advanced: SOS DP with updates
struct DynamicSOS {
    int n;
    vector<ll> dp, original;

    DynamicSOS(int n_) : n(n_), dp(1 << n, 0), original(1 << n, 0) {}

    void update(int mask, ll val) {
        ll diff = val - original[mask];
        original[mask] = val;

        // Update all supermasks of this mask
        for (int supermask = mask; supermask < (1 << n); supermask = (supermask + 1) | mask) {
            dp[supermask] += diff;
            if (supermask == (1 << n) - 1)
                break;
        }
    }

    ll query(int mask) {
        return dp[mask];
    }

    void rebuild() {
        dp = SOS_DP(original);
    }
};

// TEMPLATE FOR COMMON SOS PROBLEMS:
/*
Problem Pattern: For each mask, find sum/max/min of f(submask) for all submasks
Solution:
1. Initialize dp[mask] = f(mask) for all masks
2. For each bit position i from 0 to n-1:
   For each mask from 0 to 2^n-1:
     if mask has ith bit set:
       dp[mask] = combine(dp[mask], dp[mask without ith bit])

For supermasks, reverse the condition:
     if mask doesn't have ith bit set:
       dp[mask] = combine(dp[mask], dp[mask with ith bit])
*/

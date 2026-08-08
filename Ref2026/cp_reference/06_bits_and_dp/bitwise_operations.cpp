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


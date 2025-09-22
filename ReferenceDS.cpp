
// ============================================================================
//                              BASIC MACROS
// ============================================================================

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define oo LLONG_MAX
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a *b / gcd(a, b)

// Fast IO
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

// File IO
void setIO(string name = "") {
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// Unique function - removes consecutive duplicates
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));

// ============================================================================
//                           DATA STRUCTURES
// ============================================================================

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// Purpose: Ordered Set - maintains elements in sorted order with rank queries
// Time: O(log n) for insert, erase, find_by_order, order_of_key
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename R>
using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// For multiset behavior (allows duplicates)
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/* USAGE EXAMPLES:
ordered_set<int> s;
s.insert(1); s.insert(3); s.insert(2);
cout << *s.find_by_order(1) << endl; // 2 (1st indexed element, 0-indexed)
cout << s.order_of_key(2) << endl;   // 1 (number of elements < 2)
s.erase(s.find_by_order(0));         // Remove smallest element

ordered_map<int, string> mp;
mp.insert({1, "one"}); mp.insert({3, "three"});
cout << mp.find_by_order(0)->second << endl; // "one"


*/

// Purpose: Custom Hash for unordered containers to avoid collision attacks
// Time: O(1) expected
struct custom_hash {
    static uint64_t splitmix64(uint64_t z) {
        z += 0x9e3779b97f4a7c15;
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
        z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
        return z ^ (z >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename T>
using hash_set = unordered_set<T, custom_hash>;
template <typename T, typename U>
using hash_map = unordered_map<T, U, custom_hash>;

/* USAGE EXAMPLES:
hash_set<int> s;
s.insert(1); s.insert(2);

hash_map<int, string> mp;
mp[1] = "one"; mp[2] = "two";

unordered_set<int, custom_hash> safe_set;
unordered_map<int, int, custom_hash> safe_map;
ORDERED SET USAGE:
================
ordered_set<int> s;
s.insert(1); s.insert(3); s.insert(2);
cout << *s.find_by_order(1) << endl;   // 2 (1st indexed element, 0-based)
cout << s.order_of_key(2) << endl;     // 1 (number of elements < 2)
s.erase(s.find_by_order(0));           // Remove smallest element
// To remove specific element: s.erase(s.find(x));

ordered_multiset<int> ms;              // Allows duplicates
ms.insert(1); ms.insert(1); ms.insert(2);
cout << ms.order_of_key(2) << endl;    // 2 (elements < 2)

ordered_map<int, string> mp;
mp.insert({1, "one"}); mp.insert({3, "three"});
cout << mp.find_by_order(0)->second << endl; // "one"

UNORDERED MAP/SET WITH CUSTOM HASH:
==================================
// Safer than default hash (avoids collision attacks)
unordered_set<int, custom_hash> safe_set;
unordered_map<int, int, custom_hash> safe_map;

// Or use the typedef versions:
hash_set<int> hs;
hash_map<int, string> hm;

// Example usage:
safe_set.insert(42);
safe_map[1] = 100;
if (safe_set.count(42)) cout << "Found\n";

*/

// Purpose: Sparse Table - answer range minimum/maximum queries in O(1)
// Time: O(n log n) preprocessing, O(1) query
template <typename T>
struct SparseTable {
    vector<vector<T>> st;
    function<T(T, T)> op;

    SparseTable(vector<T> &arr, function<T(T, T)> operation) : op(operation) {
        int n = arr.size();
        int k = 32 - __builtin_clz(n);
        st.assign(n, vector<T>(k));

        for (int i = 0; i < n; i++)
            st[i][0] = arr[i];

        for (int j = 1; j < k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) {
        int len = r - l + 1;
        int k = 31 - __builtin_clz(len);
        return op(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

/* USAGE EXAMPLE:
vector<int> arr = {1, 3, 2, 7, 9, 11};
auto minOp = [](int a, int b) { return min(a, b); };
SparseTable<int> st(arr, minOp);
cout << st.query(1, 4) << endl; // minimum in range [1, 4]
*/
#define lft 2 * x, lx, (lx + rx) / 2
#define rt 2 * x + 1, (lx + rx) / 2 + 1, rx
int seg_size;
template <typename T>
struct SEG {
    vector<T> tree;
    T neutral = 1e9 + 1;

    int size;
    SEG(int n) {
        size = 1;
        seg_size = n;
        while (size <= n)
            size *= 2;
        tree.assign(size * 2, neutral);
    }

    T merge(T a, T b) {
        return min(a, b);
    }
    T build(vector<int> &a, int x = 1, int lx = 1, int rx = seg_size) {
        if (lx == rx)
            return tree[x] = a[lx];
        return tree[x] = merge(build(a, lft), build(a, rt));
    }

    T set(int i, int v, int x = 1, int lx = 1, int rx = seg_size) {
        if (lx == rx) {
            return tree[x] = v;
        }
        int mid = (lx + rx) / 2;
        if (i <= mid)
            set(i, v, lft);
        else
            set(i, v, rt);
        return tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    T query(int l, int r, int x = 1, int lx = 1, int rx = seg_size) {
        if (lx > r || rx < l)
            return neutral;
        if (l <= lx && rx <= r)
            return tree[x];
        return merge(query(l, r, lft), query(l, r, rt));
    }
};
// Purpose: Segment Tree with Lazy Propagation - range updates and queries
// Time: O(n) build, O(log n) query/update
#define lft 2 * x, lx, (lx + rx) / 2
#define rt 2 * x + 1, (lx + rx) / 2 + 1, rx

template <typename T>
struct LazySegmentTree {
    vector<T> tree, lazy;
    T neutral = 0;
    T lazy_neutral = 0;
    int size, n;

    LazySegmentTree(int n_ = 0) { init(n_); }

    void init(int n_) {
        n = n_;
        size = 1;
        while (size <= n)
            size *= 2;
        tree.assign(2 * size, neutral);
        lazy.assign(2 * size, lazy_neutral);
    }

    T merge(T a, T b) { return a + b; }

    void build(vector<T> &arr, int x = 1, int lx = 1, int rx = -1) {
        if (rx == -1)
            rx = n;
        if (lx == rx) {
            tree[x] = arr[lx];
            return;
        }
        build(arr, lft);
        build(arr, rt);
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    void push(int x, int lx, int rx) {
        if (lazy[x] == lazy_neutral || lx == rx)
            return;

        tree[2 * x] += lazy[x] * ((lx + rx) / 2 - lx + 1);
        tree[2 * x + 1] += lazy[x] * (rx - (lx + rx) / 2);
        lazy[2 * x] += lazy[x];
        lazy[2 * x + 1] += lazy[x];
        lazy[x] = lazy_neutral;
    }

    void update(int l, int r, T val, int x = 1, int lx = 1, int rx = -1) {
        if (rx == -1)
            rx = n;
        if (r < lx || rx < l)
            return;

        if (l <= lx && rx <= r) {
            tree[x] += val * (rx - lx + 1);
            lazy[x] += val;
            return;
        }

        push(x, lx, rx);
        update(l, r, val, lft);
        update(l, r, val, rt);
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    T query(int l, int r, int x = 1, int lx = 1, int rx = -1) {
        if (rx == -1)
            rx = n;
        if (r < lx || rx < l)
            return neutral;
        if (l <= lx && rx <= r)
            return tree[x];

        push(x, lx, rx);
        return merge(query(l, r, lft), query(l, r, rt));
    }

    void set(int i, T val, int x = 1, int lx = 1, int rx = -1) {
        if (rx == -1)
            rx = n;
        if (lx == rx) {
            tree[x] = val;
            return;
        }
        push(x, lx, rx);
        int mid = (lx + rx) / 2;
        if (i <= mid) {
            set(i, val, lft);
        } else {
            set(i, val, rt);
        }
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }
};

/* USAGE EXAMPLE:
LazySegmentTree<ll> seg(n);
seg.build(arr);
seg.update(l, r, val); // Add val to range [l, r]
cout << seg.query(l, r) << endl; // Sum of range [l, r]
*/

// Purpose: Fenwick Tree (Binary Indexed Tree) - prefix sums with updates
// Time: O(log n) update/query, O(n log n) build
template <typename T>
struct FenwickTree {
    vector<T> tree;
    int n;

    FenwickTree(int n_) : n(n_), tree(n_ + 1, 0) {}

    void update(int idx, T val) {
        for (int i = idx; i <= n; i += i & -i) {
            tree[i] += val;
        }
    }

    T query(int idx) {
        T sum = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

    T rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

/* USAGE EXAMPLE:
FenwickTree<ll> ft(n);
ft.update(i, val); // Add val to position i
cout << ft.rangeQuery(l, r) << endl; // Sum of range [l, r]
*/

// Purpose: Trie - efficient string storage and prefix queries
// Time: O(|s|) insert/search, O(1) space per character
struct TrieNode {
    TrieNode *children[26];
    bool isEnd;
    int count;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEnd = false;
        count = 0;
    }
};

struct Trie {
    TrieNode *root;

    Trie() { root = new TrieNode(); }

    void insert(string &word) {
        TrieNode *curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
            curr->count++;
        }
        curr->isEnd = true;
    }

    bool search(string &word) {
        TrieNode *curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx])
                return false;
            curr = curr->children[idx];
        }
        return curr->isEnd;
    }

    int countPrefix(string &prefix) {
        TrieNode *curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!curr->children[idx])
                return 0;
            curr = curr->children[idx];
        }
        return curr->count;
    }
};

// P and M should be prime numbers and P < M, to achive better results
// Better use two hashes with P1,M1 and P2,M2 or 3 hashes to minimize tbe hash collision probability
// DO NOT USE UNORDERED MAP/SET WHEN USING HASH
template <int32_t P, int32_t M>
struct Hash {
    // common P and M values:
    // P: 1331 9973
    // M: 1e9+7  1e9+9

    // Make sure to have p & m as const, it will significantly improve the preformace
    const int p = P;
    const int m = M;
    // s[0]*p^(n-1) + s[1]*p^(n-2) + ... s[n-1]*p^(0)

    vector<ll> pow, h;

    // Preprocess a string in O(n)
    Hash(string s, int n) : pow(n), h(n) { // string s with size n
        pow[0] = 1;
        for (int i = 1; i < n; i++)
            pow[i] = pow[i - 1] * p % m;
        h[0] = s[0] + 1;
        for (int i = 1; i < n; i++)
            h[i] = (h[i - 1] * p + s[i] + 1) % m;
    }

    Hash() {}

    void Build(string s, int n) { // string s with size n
        pow.resize(n);
        h.resize(n);
        pow[0] = 1;
        for (int i = 1; i < n; i++)
            pow[i] = pow[i - 1] * p % m;
        h[0] = s[0] + 1;
        for (int i = 1; i < n; i++)
            h[i] = (h[i - 1] * p + s[i] + 1) % m;
    }

    // get hash value of a substring in O(1)
    // for hash H H(i,j) returns the hash of substring(i,j)
    inline ll operator()(int i, int j) {
        ll ret = h[j] - (i ? h[i - 1] * pow[j - i + 1] : 0);
        return (ret % m + m) % m;
    }
    // construct the hash h for string s like this: Hash<P,(int)M> h(s,s.size());
    // or like this Hash<P,(int)M> h(); then call h.Build(s,s.size());
};

// Purpose: Ternary Search - find maximum/minimum of unimodal function
// Time: O(log₃(range/precision))
double ternary_search(double l, double r, function<double(double)> f) {
    for (int i = 0; i < 100; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(m1) > f(m2)) { // Change for min/max
            l = m1;
        } else {
            r = m2;
        }
    }
    return f(l);
}

// Purpose: Longest Common Subsequence - find LCS and reconstruct it
// Time: O(nm), Space: O(nm)
string LCS(string &a, string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string result = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            result = a[i - 1] + result;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return result;
}

// Purpose: Longest Increasing Subsequence - find length of LIS
// Time: O(n log n)
int LIS(vector<int> &nums) {
    vector<int> lis;
    for (int x : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) {
            lis.push_back(x);
        } else {
            *it = x;
        }
    }
    return lis.size();
}

// Purpose: KMP String Matching - find all occurrences of pattern in text
// Time: O(n + m) where n = |text|, m = |pattern|
vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0, i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(string text, string pattern) {
    vector<int> result;
    vector<int> lps = computeLPS(pattern);
    int n = text.length(), m = pattern.length();
    int i = 0, j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}

// Purpose: Z Algorithm - find all occurrences and compute Z array
// Time: O(n)
vector<int> zAlgorithm(string s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

// Purpose: Manacher's Algorithm - find all palindromic substrings
// Time: O(n)
vector<int> manacher(string s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }

    int n = t.length();
    vector<int> p(n, 0);
    int center = 0, right = 0;

    for (int i = 0; i < n; i++) {
        if (i < right) {
            p[i] = min(right - i, p[2 * center - i]);
        }

        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 &&
               t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    return p;
}

// ============================================================================
//                              UTILITIES
// ============================================================================

// Purpose: Next Greater Element for each position
// Time: O(n)
vector<int> nextGreater(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(arr[i]);
    }
    return result;
}

// Purpose: Previous Greater Element for each position
// Time: O(n)
vector<int> prevGreater(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(arr[i]);
    }
    return result;
}

// Purpose: Generate all subsets recursively
// Time: O(2ⁿ)
void generateSubsets(vector<int> &arr, int index, vector<int> &current, vector<vector<int>> &result) {
    if (index == arr.size()) {
        result.push_back(current);
        return;
    }
    // Include current element
    current.push_back(arr[index]);
    generateSubsets(arr, index + 1, current, result);
    current.pop_back();

    // Exclude current element
    generateSubsets(arr, index + 1, current, result);
}

// Purpose: Generate subsets using bitmask
// Time: O(n * 2ⁿ)
void generateSubsetsBitmask(vector<int> &arr) {
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset.push_back(arr[i]);
            }
        }
        // Process subset
    }
}

// Purpose: Generate combinations of size m from n elements
// Time: O(C(n,m))
vector<int> combination;
int cnt_combinations = 0;

void getCombinations(int n, int m, int i = 0, int last_val = 0) {
    if (i == m) {
        cnt_combinations++;
        // Process combination
        return;
    }
    for (int j = last_val + 1; j <= n; j++) {
        combination.push_back(j);
        getCombinations(n, m, i + 1, j);
        combination.pop_back();
    }
}

// Purpose: Inclusion-Exclusion Principle implementation
// Time: O(2ᵏ)
void inclusionExclusion(int k) {
    ll ans = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        ll cur = 0, cnt = 0;
        for (int bit = 0; bit < k; bit++) {
            if (!(mask & (1 << bit)))
                continue;
            cnt++;
            // Process bit
        }
        // Calculate cur based on the bits set
        ll sign = cnt % 2 ? 1 : -1;
        ans += sign * cur;
    }
}

// Purpose: Mo's Algorithm for offline range queries
// Time: O((n + q) * sqrt(n))
struct Query {
    int l, r, idx;
};

bool moComparator(Query a, Query b) {
    int block_size = sqrt(MAXN);
    if (a.l / block_size != b.l / block_size) {
        return a.l / block_size < b.l / block_size;
    }
    return (a.l / block_size & 1) ? (a.r < b.r) : (a.r > b.r);
}

void moAlgorithm(vector<int> &arr, vector<Query> &queries) {
    sort(queries.begin(), queries.end(), moComparator);

    int currentL = 0, currentR = -1;
    // Current answer state

    for (Query q : queries) {
        while (currentR < q.r) {
            currentR++;
            // Add arr[currentR] to current answer
        }
        while (currentR > q.r) {
            // Remove arr[currentR] from current answer
            currentR--;
        }
        while (currentL < q.l) {
            // Remove arr[currentL] from current answer
            currentL++;
        }
        while (currentL > q.l) {
            currentL--;
            // Add arr[currentL] to current answer
        }

        // Store answer for queries[q.idx]
    }
}

struct MoPairs {
    int n, block_size;
    long long K;
    vector<int> arr;
    vector<Query> queries;
    unordered_map<int, long long> freq; // added to calculate the answers ,dependes on the problem
    long long currentAnswer = 0;
    int currL = 0, currR = -1;

    MoPairs(const vector<int> &a, const vector<Query> &qs, long long target)
        : n((int)a.size()), arr(a), queries(qs), K(target) {
        block_size = max(1, (int)sqrt(n));
    }

    static bool cmp(const Query &a, const Query &b, int block_size) {
        int ab = a.l / block_size, bb = b.l / block_size;
        if (ab != bb)
            return ab < bb;
        return (ab & 1) ? (a.r < b.r) : (a.r > b.r);
    }

    void add(int pos) {
        // here modify the answer depending on problem
        int x = arr[pos];
        currentAnswer += freq[K - x];
        freq[x]++;
    }
    void remove_(int pos) {
        // here modify the answer depending on problem
        int x = arr[pos];
        freq[x]--;
        currentAnswer -= freq[K - x];
    }

    vector<long long> run() {
        sort(queries.begin(), queries.end(),
             [&](const Query &a, const Query &b) {
                 return cmp(a, b, block_size);
             });
        vector<long long> answers(queries.size());
        for (auto &q : queries) {
            while (currL > q.l) {
                --currL;
                add(currL);
            }
            while (currR < q.r) {
                ++currR;
                add(currR);
            }
            while (currL < q.l) {
                remove_(currL);
                ++currL;
            }
            while (currR > q.r) {
                remove_(currR);
                --currR;
            }
            answers[q.idx] = currentAnswer;
        }
        return answers;
    }
};

/*
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<Query> qs(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        --l; --r;
        qs[i] = {l, r, i};
    }

    MoPairs solver(a, qs, K);
    vector<long long> ans = solver.run();

    for (auto x : ans) cout << x << "\n";
 */

// Purpose: Coordinate Compression - map large values to small indices
// Time: O(n log n)
vector<ll> compress(vector<ll> &a) {
    vector<ll> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (ll &x : a) {
        x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    }
    return vals;
}

// ============================================================================
//                                  MISC
// ============================================================================

/*

Contest Tips:
============
- Always check for integer overflow (use long long)
- Be careful with 0-indexed vs 1-indexed problems
- Test with edge cases: n=1, n=2, empty arrays, negative numbers
- Read the problem statement twice
- Check if the problem needs fast I/O
- Use custom hash for unordered containers in contests
- When TLE, consider: better algorithm, optimizations, or data structures
- For geometry problems, watch out for precision errors
- In DP problems, carefully define states and transitions
- For graph problems, check if it's directed/undirected, weighted/unweighted

Time Complexity Cheat Sheet:
==========================
- Sorting: O(n log n)
- Binary Search: O(log n)
- DFS/BFS: O(V + E)
- Dijkstra: O((V + E) log V)
- Bellman-Ford: O(VE)
- Floyd-Warshall: O(V³)
- Segment Tree: O(log n) query/update
- Fenwick Tree: O(log n) query/update
- DSU: O(α(n)) ≈ O(1) per operation
- Sparse Table: O(n log n) build, O(1) RMQ
- Matrix Exponentiation: O(k³ log n) where k is matrix size

Common Mistakes to Avoid:
========================
- Integer overflow (use long long)
- Array bounds (check indices)
- Uninitialized variables
- Wrong loop bounds (< vs <=)
- Modular arithmetic errors
- Not handling edge cases
- Using wrong data types
- Forgetting to clear global arrays between test cases
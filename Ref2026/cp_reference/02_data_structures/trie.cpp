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


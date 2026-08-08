// Purpose: Tree Hashing - assign unique hash values to trees for isomorphism
// Time: O(n) per tree hashing
// Uses: Tree isomorphism, finding identical subtrees, tree pattern matching
// Can detect if two trees have the same structure

const ll HASH_BASE = 1000000007;
const ll HASH_MOD = 1000000009;

struct TreeHash {
    int n;
    vector<vector<int>> adj;
    vector<ll> subtree_hash;
    vector<int> subtree_size;

    TreeHash(int n_) : n(n_) {
        adj.resize(n + 1);
        subtree_hash.assign(n + 1, 0);
        subtree_size.assign(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll dfs(int u, int parent) {
        subtree_size[u] = 1;
        vector<ll> child_hashes;

        for (int v : adj[u]) {
            if (v != parent) {
                ll child_hash = dfs(v, u);
                child_hashes.push_back(child_hash);
                subtree_size[u] += subtree_size[v];
            }
        }

        // Sort child hashes to make hash independent of child order
        sort(child_hashes.begin(), child_hashes.end());

        ll hash_val = 1;
        for (ll child_hash : child_hashes) {
            hash_val = (hash_val * HASH_BASE + child_hash) % HASH_MOD;
        }

        // Include subtree size in hash to distinguish trees with same structure but different sizes
        hash_val = (hash_val * HASH_BASE + subtree_size[u]) % HASH_MOD;

        return subtree_hash[u] = hash_val;
    }

    ll getTreeHash(int root = 1) {
        return dfs(root, -1);
    }

    // Get hash of subtree rooted at node u
    ll getSubtreeHash(int u) {
        return subtree_hash[u];
    }

    // Find all nodes with identical subtree structure
    map<ll, vector<int>> groupBySubtreeHash(int root = 1) {
        dfs(root, -1);
        map<ll, vector<int>> groups;

        for (int i = 1; i <= n; i++) {
            groups[subtree_hash[i]].push_back(i);
        }

        return groups;
    }
};

// Advanced Tree Hashing with Node Values
struct TreeHashWithValues {
    int n;
    vector<vector<int>> adj;
    vector<ll> node_values;
    vector<ll> subtree_hash;

    TreeHashWithValues(int n_) : n(n_) {
        adj.resize(n + 1);
        node_values.assign(n + 1, 0);
        subtree_hash.assign(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void setNodeValue(int u, ll val) {
        node_values[u] = val;
    }

    ll dfs(int u, int parent) {
        vector<ll> child_hashes;

        for (int v : adj[u]) {
            if (v != parent) {
                child_hashes.push_back(dfs(v, u));
            }
        }

        sort(child_hashes.begin(), child_hashes.end());

        ll hash_val = node_values[u];
        for (ll child_hash : child_hashes) {
            hash_val = (hash_val * HASH_BASE + child_hash) % HASH_MOD;
        }

        return subtree_hash[u] = hash_val;
    }

    ll getTreeHash(int root = 1) {
        return dfs(root, -1);
    }
};

// Tree Isomorphism Checker
struct TreeIsomorphism {
    static bool areIsomorphic(TreeHash &tree1, TreeHash &tree2, int root1 = 1, int root2 = 1) {
        if (tree1.n != tree2.n)
            return false;

        ll hash1 = tree1.getTreeHash(root1);
        ll hash2 = tree2.getTreeHash(root2);

        return hash1 == hash2;
    }

    // Find all possible roots that make two trees isomorphic
    static vector<pair<int, int>> findIsomorphicRoots(TreeHash &tree1, TreeHash &tree2) {
        vector<pair<int, int>> isomorphic_pairs;

        for (int root1 = 1; root1 <= tree1.n; root1++) {
            ll hash1 = tree1.getTreeHash(root1);

            for (int root2 = 1; root2 <= tree2.n; root2++) {
                ll hash2 = tree2.getTreeHash(root2);

                if (hash1 == hash2) {
                    isomorphic_pairs.push_back({root1, root2});
                }
            }
        }

        return isomorphic_pairs;
    }
};

// Rooted Tree Canonical Hash (independent of root choice for some applications)
struct CanonicalTreeHash {
    int n;
    vector<vector<int>> adj;
    vector<ll> canonical_hash;

    CanonicalTreeHash(int n_) : n(n_) {
        adj.resize(n + 1);
        canonical_hash.assign(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll dfs(int u, int parent) {
        vector<ll> child_hashes;

        for (int v : adj[u]) {
            if (v != parent) {
                child_hashes.push_back(dfs(v, u));
            }
        }

        sort(child_hashes.begin(), child_hashes.end());

        ll hash_val = 1;
        for (ll child_hash : child_hashes) {
            hash_val = (hash_val * HASH_BASE + child_hash) % HASH_MOD;
        }

        return canonical_hash[u] = hash_val;
    }

    // Get the canonical hash by trying all possible roots and taking the lexicographically smallest
    ll getCanonicalHash() {
        ll min_hash = LLONG_MAX;

        for (int root = 1; root <= n; root++) {
            ll hash_val = dfs(root, -1);
            min_hash = min(min_hash, hash_val);
        }

        return min_hash;
    }
};

/* USAGE EXAMPLES:

// Basic tree hashing
TreeHash th(n);
for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    th.addEdge(u, v);
}
ll tree_hash = th.getTreeHash(1);

// Find identical subtrees
auto groups = th.groupBySubtreeHash(1);
for (auto& [hash, nodes] : groups) {
    if (nodes.size() > 1) {
        cout << "Nodes with identical subtrees: ";
        for (int node : nodes) cout << node << " ";
        cout << endl;
    }
}

// Tree isomorphism
TreeHash th1(n1), th2(n2);
// ... add edges ...
bool isomorphic = TreeIsomorphism::areIsomorphic(th1, th2);

// Tree hashing with node values
TreeHashWithValues thv(n);
for (int i = 1; i <= n; i++) {
    int val; cin >> val;
    thv.setNodeValue(i, val);
}
// ... add edges ...
ll hash_with_values = thv.getTreeHash(1);

// Canonical tree hash (root-independent for unrooted trees)
CanonicalTreeHash cth(n);
// ... add edges ...
ll canonical_hash = cth.getCanonicalHash();
*/

// Applications:
// 1. Tree Isomorphism: Check if two trees have the same structure
// 2. Subtree Matching: Find all occurrences of a pattern tree in a larger tree
// 3. Tree Deduplication: Remove duplicate trees from a collection
// 4. Tree Clustering: Group trees by structural similarity
// 5. Tree Caching: Use hash as key to cache results for identical tree structures

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

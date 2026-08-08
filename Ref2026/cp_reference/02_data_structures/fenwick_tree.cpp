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


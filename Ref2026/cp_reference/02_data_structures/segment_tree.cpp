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

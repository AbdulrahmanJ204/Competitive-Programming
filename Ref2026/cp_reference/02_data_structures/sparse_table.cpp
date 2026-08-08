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

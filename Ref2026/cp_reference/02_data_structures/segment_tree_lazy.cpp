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


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define lft 2 * x, lx, (lx + rx) / 2
#define rit 2 * x + 1, (lx + rx) / 2 + 1, rx

int seg_size;

struct SEG {
    vector<vector<int>> tree;
    int size = 1;
    vector<int> neutral;
    SEG(int n) {
        seg_size = n;
        while (size <= n)
            size *= 2;
        tree.assign(2 * size, neutral);
    }
    vector<int> merge(vector<int> &a, vector<int> &b) {

        int i = 0, j = 0;
        vector<int> v;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                v.push_back(a[i]);
                i++;
            } else {
                v.push_back(b[j]);
                j++;
            }
        }
        while(i<a.size()){
            v.push_back(a[i]); i++;
        }
        while(j<b.size()) {
            v.push_back(b[j]);
            j++;
        }

        return v;
    }
    void build(vector<int> &a, int x = 1, int lx = 1, int rx = seg_size) {
        if (lx == rx) {
            tree[x].push_back(a[lx]);
            return;
        }
        build(a, lft);
        build(a, rit);
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }
    int ans(vector<int> &v , int x , int y){
        int st = lower_bound(v.begin() , v.end() , x) - v.begin();
        int ed = upper_bound(v.begin() , v.end() , y) - v.begin()-1;
        
        return  ed -st + 1 ;
    }
    int query(int l, int r, int d , int u, int x = 1, int lx = 1, int rx = seg_size) {
        if (l > rx || r < lx)
            return 0;
        if (l <= lx && rx <= r)
            return ans(tree[x] , d , u);
        return (query(l, r ,d ,u, lft)+ query(l, r, d ,u, rit));
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    SEG seg(n);
    seg.build(a);

    while (q--) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
     
        cout << seg.query(l , r, x, y) << "\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

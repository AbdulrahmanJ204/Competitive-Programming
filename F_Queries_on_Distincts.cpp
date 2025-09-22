#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define gcd(a ,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"
#define cno cout<<"NO"
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define cin1(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define cin2(v,n,m) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) cin>>v[i][j];
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

#define lft 2 * x, lx, (lx + rx) / 2
#define rt 2 * x + 1, (lx + rx) / 2 + 1, rx
int seg_size;
template <typename T> struct SEG {
    vector<T> tree;
    T neutral = 1e9;

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
    void build(vector<int> &a, int x = 1, int lx = 1, int rx = seg_size) {
        if (lx == rx) {
            tree[x] = a[lx];
            return;
        }
        build(a, lft), build(a, rt);
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    T query(int l, int r, int x = 1, int lx = 1, int rx = seg_size) {
        if (lx > r || rx < l)
            return neutral;
        if (l <= lx && rx <= r)
            return tree[x];
        return merge(query(l, r, lft), query(l, r, rt));
    }
};


void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    n++;
    vector<vector<int>> pre(26, vector<int>(n , 0));

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < n; j++)
            pre[i][j] = (j == 0 ? 0 : pre[i][j - 1] + (s[j-1] - 'a' == i));

    auto check = [&](int startIdx, int len, int need) -> bool {
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            int r = min(n - 1, startIdx + len - 1);
            cnt += (pre[i][r] - pre[i][startIdx - 1] >0);
        }
        return cnt >= need;
    };

    vector<vector<int>> minLen(26, vector<int>(n , 1));
    for (int i = 1; i < n; i++)
        for (int j = 0; j < 26; j++) {
            int l = -1, r = n, ans = 1e9;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (check(i, mid, j + 1))
                    r = mid - 1, ans = min(ans, mid);
                else
                    l = mid + 1;
            }
            minLen[j][i] = ans;
        }

    vector<SEG<int>> seg(26, SEG<int>(n));
    for (int i = 0; i < 26; i++)
        seg[i].build(minLen[i]);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int cnt = 0;
        for (int i = 0; i < 26; i++)
            cnt += (pre[i][r] - pre[i][l - 1] > 0);
        
        int lx = l, rx = r , rq = l;
        while (lx <= rx) {
            int mid = (lx+rx)/2;
            if(minLen[cnt-1][mid] + mid -1<=r) rq =max(rq , mid) , lx = mid+1;
            else rx = mid-1;
        }
        int ans = seg[cnt - 1].query(l, rq);
        cout << ans << endl;
    }

    return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    // cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define i128 __int128_t
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(L,R) uniform_int_distribution<int>(L, R)(rng);

template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Manacher {
public: 
    vector<int> p;    
    string ms;        

    Manacher(string &s) {
        ms = "@"; 
        for (char c : s) {
            ms += "#" + string(1, c);
        }
        ms += "#$"; 
        runManacher();
    }

    void runManacher() {
        int n = ms.size();
        p.assign(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n - 1; ++i) {
            int mirror = l + r - i;
            if (i < r)
                p[i] = min(r - i, p[mirror]);
            while (ms[i + 1 + p[i]] == ms[i - 1 - p[i]]){
                ++p[i];
            }
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    int getLongest(int cen, int odd) {
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
    }
};  

template<typename T, T (*op)(T, T)>
struct SparseTable {
    vector<vector<T>> ST;
    int n;
    SparseTable(const vector<T>& a) {
        n = a.size();
        if(n == 0) return;
        int maxLog = 32 - __builtin_clz(n);
        ST.resize(n, vector<T>(maxLog));
        for (int i = 0; i < n; i++) ST[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 0; i + (1 << j) - 1 < n; i++)
                ST[i][j] = op(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
    }

    T query(int l, int r) {
        if (l > r) return 0;
        int len = r - l + 1;
        int k = (31 ^ __builtin_clz(len));
        return op(ST[l][k], ST[r - (1 << k) + 1][k]);
    }
};

int op(int a, int b){
    return max(a, b);
}

int OddSum_in_range(int left, int right) {
    if (left > right) return 0;
    if (left % 2 == 0) left++;
    if (right % 2 == 0) right--;
    if (left > right) return 0;
    int n_right = (right + 1) / 2;
    int n_left = (left - 1) / 2;
    return (n_right * n_right) - (n_left * n_left);
}

int EvenSum_in_range(int left, int right) {
    if (left > right) return 0;
    if (left % 2 == 1) left++;
    if (right % 2 == 1) right--;
    if (left > right) return 0;
    int n_right = right / 2;
    int n_left = (left - 2) / 2;
    return (n_right * (n_right + 1)) - (n_left * (n_left + 1));
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s= '.' + s;
    n = s.size();
    int q;
    cin >> q;
    
    Manacher man(s);
      
    vector<int> odd(n,0), even(n,0);
    for (int i = 1; i < n; i++) {
        odd[i] = man.getLongest(i, 1);  
        even[i] = man.getLongest(i, 0);
    }
    
    SparseTable<int, op> ev(even), od(odd); 
    vector<int> odd_lengths, ev_length;
    
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        
        int len = r - l + 1;

        int lo = 1, hi = len;
        if (hi % 2 == 0) hi--;
        int mx_odd = 1;
        
        while (lo <= hi) {
            int mid = (lo+hi)/ 2;
            if (mid % 2 == 0) mid++; 
            if(mid>hi) mid-=2;
            int margin = mid / 2;
            int q_left = l + margin ;
            int q_right = r - margin;

            if (od.query(q_left, q_right) >= mid) {
                mx_odd = mid;
                lo = mid + 2;
            } else {
                hi = mid - 2;
            }
        }

        
        lo = 2, hi = len;
        if (hi % 2) hi--;
        int mx_even = 0;
        
        while (lo <= hi) {
            int mid = (hi + lo) / 2;
            if (mid % 2) mid++;
            if(mid>hi) mid-=2;
            int margin = mid / 2;
            // 0 1 2 3 
            // len = 4 , margin = 2, 
            int q_left = l + margin -1 ;
            int q_right = r - margin ;
            
            if (ev.query(q_left, q_right) >= mid) {
                mx_even = mid;
                lo = mid + 2;
            } else {
                hi = mid - 2;
            }
        }
        int ans = 0;
        if (mx_odd < k) ans += OddSum_in_range(mx_odd + 1, k);
        if (mx_even < k) ans += EvenSum_in_range(mx_even + 1, k);
        cout << ans << endl;
    }
    return;
}

int32_t main() {
    InTheNameOfAllah;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

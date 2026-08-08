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

int comp(int x, vector<int> &ve) {
    return lower_bound(ve.begin(), ve.end(), x) - ve.begin() +1;
}
#define lft 2 * x, lx, (lx + rx) / 2
#define rt 2 * x + 1, (lx + rx) / 2 + 1, rx
int seg_size;
template <typename T>
struct SEG {
    vector<T> tree;
    T neutral = 0 ;

    int size;
    SEG(int n) {
        size = 1;
        seg_size = n;
        while (size <= n)
            size *= 2;
        tree.assign(size * 2, neutral);
    }

    T merge(T a, T b) {
        return max(a, b);
    }
    

    T set(int i, int v, int x = 1, int lx = 1, int rx = seg_size) {
        if (lx == rx) {
            return tree[x] = max(tree[x],v);
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
void solve()
{
  ll n;
  cin >> n;
  vector<int> cmp;
  vector<array<int,3>> v;
  for (int i = 0; i < n; i++) {
    int a, b, h;
    cin >> a >> b >> h;
    v.push_back({a, b, h});
    cmp.push_back(a);
    cmp.push_back(b);
  }
  sort(all(cmp));
  unq(cmp);

  for (int i = 0; i < n; i++) {
      auto [a, b, h] = v[i];
      v[i] = {comp(a,cmp), comp(b,cmp), h};
  }

  sort(all(v), [&](array<int,3> f, array<int,3> s) {
    auto [af, bf, hf] = f;
    auto [as, bs, hs] = s;
    return (bf != bs) ? bs < bf : as < af;
  });
  vector<int> dp(n);
  SEG<int> seg(comp(cmp.back() , cmp));
  for(int i = 0 ; i < n ; i ++)
  {
    auto [a,b,h] = v[i];
    
    dp[i] = h + seg.query(1 , b-1);
    seg.set(a , dp[i]);
  }
  
  int ans = *max_element(all(dp));
  cout<<ans;
  
  return;
}

int32_t main() {
    InTheNameOfAllah;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
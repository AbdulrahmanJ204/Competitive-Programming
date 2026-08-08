#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

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
#define tryAndCry(v) for(auto x : v){cerr<<x<<" ";}cerr<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(L,R) uniform_int_distribution<int>(L, R)(rng);

template <class T>
using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    ll n;
    cin >> n;
    int a[n];
    vector<int> v;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
        mp[a[i]].push_back(i);
    }
    if (n == 1) {
        cout << 0;
        return;
    }
    sort(rall(v));
    unq(v);
    v.push_back(0);
    
    int width = 0, moved = 0;
    int sz = v.size();
    for (int i = 0; i < sz - 1; i++) {
        int h = v[i], nxt = v[i + 1];
        int df = h - nxt;
        
        width += mp[h].size();
        
        
        int single_row_dist = 0;
        for (int idx : mp[h])
            single_row_dist += n - idx-1;
        int rows_until_end_dist = single_row_dist *h;
        int single_row_remove = width * (width - 1) / 2;
        int rows_remove = single_row_remove*df;
    
        
        moved += rows_until_end_dist - rows_remove;
    
    }
    o_set<int> st;
    int mx = 0;
    for (int i = 0; i < sz - 1; i++) {
        int h = v[i];
        for (int idx : mp[h])
            st.insert(idx);
        int idx = mp[h].back();
        int ord = st.order_of_key(idx);
        mx = max(mx, ord);
    }
    cout << moved + mx;
    
    return;
}
int32_t main() {
    InTheNameOfAllah;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
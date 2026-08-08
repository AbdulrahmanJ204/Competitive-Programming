#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
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
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);



void solve()
{
    ll n, q;
    cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    string s;
    cin >> s;
    int pre[n + 2], suf[n + 2];
    pre[0] = 0, suf[n + 1] = 1e9;
    for (int i = 1; i <= n; i++) {
        pre[i] = max(a[i], pre[i - 1]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = min(suf[i + 1], a[i]);
    }
    s = "#" + s;
    set<int> st;
    for (int i = 1; i < n; i++) {
        if (s[i] == 'L' && s[i + 1] == 'R') {
            if (pre[i] > i || suf[i + 1] < i + 1)
                st.insert(i);
        }
    }

    while (q--) {
        int x;
        cin >> x;
        if (s[x] == 'R') {

            // RRR -> RLR
            // LRR -> LLR
            // RRL -> RLL
            // LRL -> LLL
            if (s[x + 1] == 'R' && s[x - 1] == 'R') {
                if (pre[x] > x || suf[x + 1] < x + 1)
                    st.insert(x);
            } else if (s[x - 1] == 'L') {
                if (st.count(x - 1))
                    st.erase(x - 1);
                if (s[x + 1] == 'R') {
                    if (pre[x] > x || suf[x + 1] < x + 1)
                        st.insert(x);
                }
            }
            s[x] = 'L';
        } else {
            // LLL -> LRL
            // RLL -> RRL
            // LLR -> LRR
            // RLR -> RRR
            if (s[x + 1] == 'L' && s[x - 1] == 'L') {
                int i = x - 1;
                if (pre[i] > i || suf[i + 1] < i + 1)
                    st.insert(i);
            } else if (s[x + 1] == 'R') {
                if (st.count(x))
                    st.erase(x);
                if (s[x - 1] == 'L') {
                    int i = x - 1;
                    if (pre[i] > i || suf[i + 1] < i + 1)
                        st.insert(i);
                }
            }

            s[x] = 'R';
        }

        st.size() ? cno : cyes;
        cendl;
    }
  return;
}

int32_t main() {
    // InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      
    }
    return 0;
}
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
    ll l , n, k;
    cin>>l>>n>>k;
    int t;
    cin>>t;
    ll a[t+1];
    for (int i = 1; i < t+1; i++)
    cin>>a[i];
    ll ans=-1;
    set<int> st;
    st.insert(0);
    st.insert(l+1);
    int ranges = l/ (k+1) ;
    ranges+= (l - ranges*(k+1) >= k ? 1 : 0);
    for (int i = 1; i < t + 1; i++) {
        int x;
        x = a[i];
        if (st.count(x)) {
            continue;
        }
        auto it = st.upper_bound(x);
        int after = *it;
        it--;
        int before = *it;

        int pre = (after - before - 1) / (k+1)  ;
        pre+= (after - before -1 - pre*(k+1)  >=k ? 1 : 0);

        int right = (after - x - 1) / (k+1) , left = (x - before - 1) / (k+1) ;
        right+= (after - x - 1 - right *(k+1) >=k ? 1 : 0 );
        left+= ( x- before  - 1 - left *(k+1) >=k ? 1 : 0 );
        ranges += left + right - pre;

        st.insert(x);
        if (ranges < n)
        if (~ans)
            ans=min(ans , i );
            else ans = i;
    }
    cout<<ans;
  return;
}

int32_t main() {
    InTheNameOfAllah
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
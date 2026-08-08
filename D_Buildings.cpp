#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 

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
// Header files, namespaces, 
// macros as defined above 
using namespace __gnu_pbds; 
  //less to set and less_equal to multiset
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
vector<int> prevGreater(int arr[], int n)
{
    // Create a stack and push index of first element 
    // to it
    stack<pair<int,int>> s;
    s.push({arr[0] , 1});

    vector<int> v; 
    // Previous greater for first element is always -1.
    v.push_back(0);
 
    // Traverse remaining elements
    for (int i = 1; i < n; i++) {
        while (s.empty() == false && s.top().first < arr[i])
            s.pop();
        s.empty() ? v.push_back(0) : v.push_back(s.top().second);
        s.push({arr[i],i+1});
    }
    return v;

}
void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    cin1(a,n);
    ll ans[n];
    ll pre[n+1];
    assign1(pre,n+1,0);
    vector<int> pg=prevGreater(a,n);
    // cout1(pg,n);
    for (int i = 0; i < n; i++)
    {
      pre[pg[i]-1]--;
      pre[i]++;
    }
    // cout1(pre,n+1);
    for (int i = n - 1; i >= 0; i--)
    {
      pre[i]+=pre[i+1];
    }
    for (int i = 1; i < n+1; i++)
    {
      cout<<pre[i]<<' ';
    } 
        
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
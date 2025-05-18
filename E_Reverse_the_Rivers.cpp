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
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n,k ,q;
    cin>>n>>k>>q;
    vector<int> v[k];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < k; j++)
      {
        int x;
        cin>>x;
        v[j].push_back(x);
      }
    
    for (int i = 0; i < k; i++)
      for (int j = 1; j < n; j++)
        v[i][j]|=v[i][j-1];
      
      
    // cout2(v , k , n);
    while(q--){
      int m;
      cin>>m;
      int lower = 1 , upper = n;
      int ans = 0;
      while(m--){
        int r , c;
        char op;
        cin>>r>>op>>c;
        r--;
        if(op=='<'){
          int temp = lower_bound(all(v[r]) , c)- v[r].begin() -1;
          upper = min(temp+1 , upper);
        }
        else{
          int temp = upper_bound(all(v[r]) , c)- v[r].begin();
          lower = max(temp+1 , lower);
        }
      }
      cout<<(lower>upper ? -1 : lower)<<endl;
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
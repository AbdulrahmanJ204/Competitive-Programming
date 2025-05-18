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
    ll n;
    cin>>n;
    ll a[n];
    cin1(a,n);
    int f1 =-1 , l1 ,f2 = -1 , l2;
    for (int i = 0; i < n; i++)
    {
      if(a[i]>0) {
        if(f1==-1) f1 = i;
        l1 = i;
      }
      if(a[i]<0){
        if(f2 ==-1) f2 = i;
        l2 = i;
      }
    }
    if(f1==-1){
      cout<<l2 - f2 +1;
      return;
    }
    if(f2==-1){
      cout<<l1-f1 + 1;
      return;
    }
    

    int ans = 1e18;
    while(l1 < n && f2 >=0){
      int cur = max({l1 , f1 , l2 , f2}) - min({l1 , l2 , f1 , f2}) +1;
      ans = min(cur , ans);
      l1++; f1 ++;
      l2-- , f2--;
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
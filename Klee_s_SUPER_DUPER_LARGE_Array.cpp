#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
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
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
const int z=0;
ll sum_in_range(ll lower, ll upper) {
    return (upper - lower + 1) * (lower + upper) / 2;
}
void solve()
{
    ll n,k;
    cin>>n>>k;
    ll ans=LONG_LONG_MAX;
    ll l=1, r=n;
    while(r-l>3){
      
      ll m1= l + (r-l)/ 3;
      ll m2= r- (r-l)/3;
      ll left=abs(sum_in_range(k , k+ m1-1) - sum_in_range(k+m1 , k+n-1)) ;
      ll right=abs(sum_in_range(k , k+ m2-1) - sum_in_range(k+m2 , k+n-1)) ;
      
      if(left< right) {
        ans=min(ans,left);
        r=m2;
      }
      else {
        ans=min(ans, right);
        l=m1;
      }
    }
    for (ll m1 = l; m1 < r+1; m1++)
    {
      
      ll left=abs(sum_in_range(k , k+ m1-1) - sum_in_range(k+m1 , k+n-1)) ;
      ans=min(ans,left);
    }
    
    cout<<ans;
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
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
ll n,m;
const int z=1e5+10;
ll a[z], b[z];
vector<int> ind[z+1];
bool check(ll mid){
  vector<pair<ll,ll>> days;
  
  for (int i = 1; i < m+1; i++)
  {
    auto it=lower_bound(all(ind[i]),mid)-ind[i].begin()-1;
    if(it<0) return false;
    // if(b[i]>ind[i][it]) return false;
    days.push_back({ind[i][it],b[i-1]});
  }
  sort(all(days));
  // cout<<"\nMID =  "<<mid<<endl;
  // for(auto x: days) cout<<x.first<<' '<<x.second<<endl;
  int cnt=0, j=0;
  for (int i = 0; i <= mid; i++)
  {
    if(days[j].first==i){
      cnt-=days[j].second;
      j++;
    }
    else cnt++;
    if(cnt<0) return false;
  }
  
  return cnt<=mid;
}
void solve()
{
    cin>>n>>m;
    cin1(a,n);
    cin1(b,m);
    for (int i = 0; i < n; i++)
      ind[a[i]].push_back(i);
    check(n);
    ll l=0, r=n+1, ans=LLONG_MAX;
    while(l<=r){
      ll mid=(l+r)/2;
      if(check(mid)){
        ans=min(ans,mid);
        r=mid-1;
      }
      else l=mid+1;
    }
    if(ans==LLONG_MAX) ans=-1;
    cout<<ans;



  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
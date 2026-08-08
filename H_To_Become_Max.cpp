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
ll n,k;
const int z=1010;
ll a[z];
bool check(ll mid){
  ll temp=k, cnt;
  bool can=false;
  // cendl;cendl;
  for (int i = 0; i < n-1; i++) 
  {
    // cout<<i<<' ';
      temp=k;
      cnt=mid;
      for (int j = i; j < n-1; j++)
      {
        if(a[j]<cnt){
          temp-= cnt-a[j];
          if(a[j+1]<cnt) cnt--;
        }
        else can|= temp>=0&&cnt>=0;
      }
      if(cnt<=a[n-1]) can|= temp>=0&&cnt>=0;
  }
  
  return can;
}
void solve()
{
    cin>>n>>k;
    cin1(a,n);
    ll l=0;
    for (int i = 0; i < n; i++)
     l=max(l,a[i]);
    
    ll r=l+k+1,ans=l;
    while(l<=r){
      ll mid=(l+r)/2;
      if(check(mid)){
        ans=max(ans,mid);
        l=mid+1;
      }
      else r=mid-1;
    }
    // cendl;
    
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
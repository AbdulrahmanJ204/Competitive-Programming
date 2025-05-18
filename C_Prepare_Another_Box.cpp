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
const int z=2e5+10;
ll a[z] ,b[z];
ll n;
bool check(int mid){
  int i = 0 , j= 0;
  
  while(i<n){
    if(i!=mid)
    {
      if(a[i] > b[j]) return 0;
      j++;
    }
    i++;
  } 
  return 1;
}
void solve()
{
    cin>>n;
    cin1(a,n);
    cin1(b,n-1);
    sort(a, a+n);
    sort(b , b+n-1);
    // cout1(a,n);
    // cout1(b,n-1);

    int l = 0 , r = n-1 , ans=1e9+10;

    while(l<=r) 
    {
      int mid = (l+r)/2;
      if(check(mid)){
        ans=min(ans, mid);
        r=mid-1;
      }
      else l=mid+1;
    }
    if(ans==1e9+10) cout<<-1;
    else cout<<a[ans];
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
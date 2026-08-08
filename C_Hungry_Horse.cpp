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
ll n,d;
const int z=1e5+10;
pair<ll,ll> a[z];

void solve()
{
    cin>>n>>d;
    for (int i = 0; i < n; i++)
      cin>>a[i].first;
    for (int i = 0; i < n; i++)
      cin>>a[i].second;
      sort(a,a+n);
      int lastCan=-1;
      for (int i = n - 1; i >= 0; i--)
        if(a[i].first+a[i].second<=d){
          lastCan = i;
          break;
        }
      vector<pair<ll,pair<ll,ll>>> v;
      for (int i = 0; i < n; i++)
      {
        v[i].first= a[i].first+a[i].second;
        v[i].second=a[i];
      }
      sort(all(v));
      int steps= 0 , dishes = 0  , ans=0;
      for (int i = 0; i < n; i++)
      {
        int 
        if()
      }
      
    
      
      
      // cout<<ans;
    

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
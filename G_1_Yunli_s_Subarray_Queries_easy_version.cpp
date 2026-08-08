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

void solve()
{
    ll n, k,q;
    cin>>n>>k>>q;
    ll a[n];
    cin1(a,n);
    ll ans[n];
    map<ll,ll> mp;
    for (int i = 0; i < n; i++)
      a[i]-=i;
    
    for (int i = 0; i < k; i++)
      mp[a[i]]++;
    multiset<ll> ms;
    for(auto &x : mp)
    ms.insert(x.second);
    ans[0]=*ms.rbegin();
    ll l=1 , r=k;
    while(r<n){
      ms.erase(ms.find(mp[a[l-1]]));
      mp[a[l-1]]--;
      if(mp[a[l-1]])
      ms.insert(mp[a[l-1]]);
      if(mp[a[r]])
      ms.erase(ms.find(mp[a[r]]));
      mp[a[r]]++;
      ms.insert(mp[a[r]]);
      ans[l]=*ms.rbegin();
      l++;
      r++;
    }
  
    while(q--){
      cin>>l>>r;
      cout<<k-ans[l-1]<<endl;
    }
    

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      // cendl;
    }
    return 0;
}
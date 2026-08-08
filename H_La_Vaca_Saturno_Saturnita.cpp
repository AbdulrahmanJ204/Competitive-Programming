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
#define lft 2*x , lx , (lx+rx)/2
#define rit 2*x + 1 , (lx+rx)/2+1 , rx
vector<int> divisors[100001];
void divisorSieve(int N) {
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            divisors[j].push_back(i);
        }
    }

}
void solve()
{
  ll n,q;
  cin>>n>>q;
  int a[n+1];
  vector<int> mp[100001];
    for (int i = 1; i <= n; i++){
      cin>>a[i];
      mp[a[i]].push_back(i);
    }
    
    while(q--){
      int k , l , r;
      cin>>k>>l>>r;
      int ans = 0;
      vector<pair<int,int>> v;
      for (int i = 0; i < divisors[k].size(); i++)
      {
        int div = divisors[k][i];
        int first = lower_bound( all(mp[div]) , l ) - mp[div].begin();
        if(first != mp[div].size()){
          int index = mp[div][first];
          v.push_back({index , div});
        }
        else{
          v.push_back({r+1 , div});
        }
      }
      sort(all(v));
      int start = l;
      for(auto x : v)
      {
        if(x.first > r) break;
        ans+=k* (x.first - start);
        while(k%x.second==0) k/=x.second;
        start = x.first;
      } 
      
      ans+= k * (r - start+1);
      cout<<ans<<endl;
    }
    
    
    
    return;
  }
  
  int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    divisorSieve(1e5);
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      // cendl;
    }
    return 0;
}
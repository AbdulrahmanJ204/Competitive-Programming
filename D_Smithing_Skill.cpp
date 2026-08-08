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
const int N=1e6+20;
ll dp[N];
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<int,int>> v;
    vector<int> a(n),b(n);
    cin1(a,n);
    cin1(b,n);
    ll c[m];
    cin1(c,m);
    int ind[n];
    iota(ind,ind+n,0);
    sort(ind,ind+n , [&a](int &i , int &j){
      return a[i]<a[j];
    });
    for (int i = 0; i < n; i++)
    {
      int idx= ind[i];
      if(v.empty()|| a[idx]-b[idx] < v.back().second )
      v.push_back({a[idx],a[idx]-b[idx]});
    }
    
    
    ll weapon = 0;
    for (int metal = 1; metal <N ; metal++)
    { 
      while(weapon<v.size() && v[weapon].first<=metal) weapon++;
      if(weapon) dp[metal] = dp[metal-v[weapon-1].second]+2;
    }
    // cout1(dp,N);
    int i = 0;
    ll score=0;
    for (int i = 0; i < m; i++)
    {
      if(c[i]>v.back().first){
        ll cur=(c[i]-v.back().first)/ (v.back().second) +1 ;
        score+=cur*2 ;
        c[i] -= cur* v.back().second;
      }
      score+=dp[c[i]];
    }
    
    cout<<score;
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
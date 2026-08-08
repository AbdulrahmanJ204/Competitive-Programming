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
int fun ( int l , int r ){
  return (r-l) * (r-l+1)/2;
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
      int x, y;
      cin>>x>>y;

      v.push_back({x,y});
    }
    int ans = m;
    sort(all(v));
    for (int i = 0; i < n; i++)
      ans-=(v[i].first==v[i].second);
    for (int i = 0; i < n; i++)
    cout<<setw(2)<<v[i].first<<" "; cendl;
    for (int i = 0; i < n; i++)
    cout<<setw(2)<<v[i].second<<" "; cendl;
    int start = 1;
    int end = v[0].second;
    ans+=fun(start , end-1);
        // cout<<"1ans = "<<ans<<" fun = "<<fun(start , end-1)<<endl;
        // cout<<"1start = "<<start<<" end = "<<end<<endl;
        
    for (int i = 0; i < n; i++)
    {


      if(v[i].second < end){
        cout<<"1 ans = "<<ans<<" fun = "<<fun(start , end-1)<<endl;
        cout<<"1 start = "<<start<<" end = "<<end<<endl;
        
        ans+=fun(start , end-1);
        start = end;
        if(i+1<n) end = v[i+1].second;
      }
      else if(v[i].first >= end){
        cout<<"2 ans = "<<ans<<" fun = "<<fun(start , end-1)<<endl;
        cout<<"2 start = "<<start<<" end = "<<end<<endl;
        
        ans+=fun(start ,end-1);
        start = end;
        end=v[i].second;
      }
    }
        cout<<"E ans = "<<ans<<" fun = "<<fun(start , end-1)<<endl;
        cout<<"E start = "<<start<<" end = "<<end<<endl;
    if(end!=m) ans+=fun(start , end);
    
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
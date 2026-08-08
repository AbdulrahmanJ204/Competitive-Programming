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

void solve()
{
    ll n;
    cin>>n;
    ll m; cin>>m;
    ll a[m] , b[m];
    vector<pair<int,int>> v;
    for (int i = 0; i < m; i++)
    {
      cin>>a[i]>>b[i];
      v.push_back({a[i],b[i]});
    }
    sort(rall(v) ,[&] (pair<int,int> a, pair<int,int> b){
return a.first+a.second > b.first+b.second; });
    if(n==1){
      cout<<*max_element(a ,a+n);
      return;
    }
    if(n==2){
      cout<<max(v[0].first+v[0].second , v[0].first + v[1].first);
      return; 
    }
    for (int i = 0; i < m; i++)
    {
      cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    
    int mxB=*max_element(b , b+m);
    ll x= n;
    ll score = 0;
    ll mxa=0;
    ll extra=0;
    for (int i = 0; i < m; i++)
    { 
      // cout<<score<<endl;
      if(v[i].first > mxB)
       score+=v[i].first , x-- , extra= max(extra , v[i].second * x);
      }
      score+=extra;
    // score+=mxB*x;
    // cout<<"Mx = "<<mxB<<endl;
    cout<<score;


  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
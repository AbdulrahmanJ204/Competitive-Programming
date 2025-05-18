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

void solve()
{
    ll n , t1 , t2 , k;
    cin>>n>>t1>>t2>>k;
    int a[n][2];
    cin2(a , n , 2);
    vector<pair<double , int>> ans;
    for (int i = 0; i < n; i++)
    {
      double speed;
      double mn = min(a[i][0] , a[i][1]),mx = max(a[i][0] , a[i][1]);
      double s1= (mn * t1) - (mn*t1/100 * k) + mx *t2,
      s2 = (mx * t1) - (mx*t1/100 * k) + mn *t2;
      speed = max(s1 , s2);
      ans.push_back(make_pair(speed , i+1));
      
    }
    sort(all(ans) , [&](pair<double , int> a , pair<double , int> b){
      if(a.first !=b.first) return a.first>b.first;
      return a.second < b.second;
    });
    for(auto& x : ans){
      cout<<x.second<<" "<<fixed<<setprecision(2)<<x.first<<endl;
    }

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
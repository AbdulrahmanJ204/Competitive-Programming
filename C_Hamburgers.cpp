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
    string s;
    cin>>s;
    int cnt[]= {0,0,0};
    bool c[3]={0 , 0 ,0};
    for (int i = 0; i < s.size(); i++)
    {
      if(s[i]=='B') cnt[0]++ , c[0] = 1;
      if(s[i]=='S') cnt[1]++ , c[1] = 1;
      if(s[i]=='C') cnt[2]++ , c[2] = 1;
    }

    int a[3], p[3], ri;
    cin1(a,3);
    cin1(p,3);
    cin >> ri;
    int ans = 0 , l = 1 , r = 1e14 ;
    auto check= [&](int mid){
      int rem[3] ={0,0,0}
      , can[3]={0,0,0} 
      , req[3]={0,0,0},
       need[3]={0,0,0};
       int price=0;
      for (int i = 0; i < 3; i++)
      {
        if(!c[i]) continue;
        rem[i] = a[i]%cnt[i];
        can[i] = a[i]/cnt[i];
        req[i] = max(0ll , mid-can[i]);
        need[i] = req[i] * cnt[i] - rem[i];
        need[i] *= p[i];
        price+=need[i];
      }

      
      return price <= ri;
    };
    while(l<=r) {
      int mid = (l+r)/2;
      if(check(mid)){
        l = mid+1;
        ans= max(ans , mid);
      }
      else r = mid-1;
    }
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
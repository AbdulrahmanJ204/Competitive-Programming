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
ll dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
}

void solve()
{
    ll x , y , x2, y2 , x1 , y1;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    ll ans = min({dist(x1 , y1 , x ,y) , dist(x2 , y1 , x ,y) , dist(x2 , y2 , x ,y) , dist(x1 , y2 , x ,y) });
    
    if(x1 <= x && x <= x2){
      
     ans = min(dist(x , y , x , y1) , ans);
     ans = min(dist(x , y , x , y2) , ans);
      
    }
    if(y1 <= y && y <= y2){
    ans = min(dist(x , y , x1 , y) , ans);
     ans = min(dist(x , y , x2 , y) , ans);
      
    }
    cout<<fixed<<setprecision(3);
    cout<<sqrtl(ans);

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
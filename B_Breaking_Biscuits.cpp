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
#define PI 3.14159265

double calculateHeight(int n, double s) {
    // Calculate the apothem
    double apothem = s / (2 * tan(M_PI / n));
    // Height is twice the apothem
    double height = 2 * apothem;
    return height;
}


void solve()
{
    ll n;
    cin>>n;
    double x[n],y[n];
    for (int i = 0; i < n; i++)
    {
      cin>>x[i]>>y[i];
    }
    cout<<fixed<<setprecision(10);
    double width=0;
    if(n%2){
      cout<<calculateHeight(n ,sqrt( abs(x[1]-x[0])*abs(x[1]-x[0])+ abs(y[1]-y[0])*abs(y[1]-y[0])));
    }
    else{
      double ans= 1e18;
      for (int i = 0; i < n/2; i++)
      {
        cerr<<sqrt( abs(x[i]-x[i+n/2-1])*abs(x[i]-x[i+n/2-1]) + abs(y[i]-y[i+n/2-1])*abs(y[i]-y[i+n/2-1]))<<endl;
       ans=min(ans,sqrt( abs(x[i]-x[i+n/2-1])*abs(x[i]-x[i+n/2-1]) + abs(y[i]-y[i+n/2-1])*abs(y[i]-y[i+n/2-1])));
      }
      cout<<ans;
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
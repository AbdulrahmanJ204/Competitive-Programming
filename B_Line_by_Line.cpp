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



int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t=1;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
      ll n;
    cin>>n;
    long double p;
    cin>>p;
    long double p1=1;
    // cout<<fixed<<setprecision(6);
    // for (int i = 0; i < n-1; i++)
    //   p1*=p/100;
      // p1*=10;
      // cout<<p1<<endl;
    long double ans=pow(p/100 , (double) (n-1) / (n));
    // p1*=p/100;
    cout<<"Case #"<<i+1<<": ";
    cout<<fixed<<setprecision(6)<<ans*100 - p;
    cendl;
    }
    
    return 0;
}
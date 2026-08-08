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
    ll a, b;
    cin>>a>>b;
    int c[n];
    cin1(c,n);
    sort(c , c + n);
    int mx = c[n-1];
    int temp = max(a,b);
    a= min(a,b);
    b=temp;
    ll ans= 0;
    // if(a!=b) {cout<<" XXXXXXXXXXXXXXXX";
    // return;}
    for (int i = 0; i < n; i++)
    {
      // add A only
      int x1 = (mx-c[i] )% a , x2 = a-x1;
      int res1 = x1 > x2 ? mx + x2 : mx- x1; 
      c[i] = res1; 
    }
    for (int i = 0; i < n; i++)
    {
      // add A only
     
      int x1 = (mx-c[i] )% b , x2 = b-x1;
      int res2 = x1 > x2 ? mx + x2 : mx- x1;
      c[i] = res2; 
     }
    sort(c , c + n);
    int curDif = c[n-1] - c[0];
    int gc = __gcd(a,b);

    // cout1(c , n); 
    // cout<<a<<" "<<b<<endl;
    // cout<<curDif<<endl;
    // cout<<"gc = "<<gc<<endl;
    cout<<endl<<curDif%gc<<" "<<gc - curDif%gc<<endl;;
    
    if(gc!=a && gc!=b && a!=b)
    curDif = min({ curDif , curDif%gc , gc - curDif%gc});
    cout<<curDif;
    
    

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
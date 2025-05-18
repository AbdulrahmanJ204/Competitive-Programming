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
const int z=2e5+10;
ll a[z], b[z];
ll n;

void solve()
{
    cin>>n;
    cin1(a,n);
    cin1(b,n);
    
    ll s1= 0 , s2= 0;
    ll pp = 0 , nn= 0;
    for (int i = 0; i < n; i++)
    {
      if(a[i]>0 && b[i]<=0) s1++;
      if(a[i]<=0 && b[i]> 0) s2++;
      if(a[i]>0 && b[i]>0 ) pp++;
      if(a[i]<0 && b[i]<0) nn++;
    }
    while(nn+pp){
      if(pp){
        s1 < s2 ? s1++ : s2++;
        pp--;
      }
      if(nn){
        s1 < s2 ? s2-- : s1--;
        nn--;
      }
    }
    
    cout<<min(s1,s2);
    

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
#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
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
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n;
    cin>>n;
    ll c[n+1],a[n+1],b[n+1];
    cin1(c,n);
    cin1(a,n);
    cin1(b,n);
    a[n]=b[n]=c[n]=0;
    ll cycle=abs(a[1]-b[1]) ,ans=0;
    for (int i = 1; i < n-1; i++)
    {
      ans= max(cycle+c[i]+1,ans);
      ll dif=min(a[i+1],b[i+1])-1 + c[i]-max(a[i+1],b[i+1]);
      cycle= max(abs(a[i+1]-b[i+1]),cycle+dif+2);
      
      if(a[i+1]==b[i+1]) {
        ans= max(cycle,ans);
        cycle=0;
      }
    }
    cycle+=1+c[n-1];
    ans=max(cycle,ans);
    cout<<ans;
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
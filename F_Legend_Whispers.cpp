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
    int n;
    cin>>n;
    ll a[n],b[n];
    cin1(a,n);
    sort(a,a+n);
    // reverse(a,a+n);
    cin1(b,n);
    sort(b,b+n);
    reverse(b,b+n);
    ll l=1,r=1e6,ans=-1;
    while (l<=r)
    {
      ll mid=(l+r)/2;
      bool deleted[n]={};
      for (int i = 0; i < n; i++)
      {
        ll x=b[i]*mid;
        for (int j = 0; j < n; j++)
        {
          if(deleted[j]) continue; 
          if(a[j]>=x && a[j]%b[i]==0)
          {
            deleted[j]=1;
            break;
          }
        }
      }
      bool flag=1;
      for (int i = 0; i < n; i++)
      {
        if(!deleted[i])
        {
          flag=0;
          break;
        }
      }
      if(flag)
      l=mid+1,ans=max(mid,ans);
      else r=mid-1;
      
    }
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
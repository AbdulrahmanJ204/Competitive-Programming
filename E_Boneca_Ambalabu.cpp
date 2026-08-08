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
    ll n;
    cin>>n;
    int a[n];
    cin1(a,n);
    int cnt[31];
    assign1(cnt , 31 , 0);
    int mxz = 0;
    for (int i = 0; i < n; i++)
    {
      int x = a[i];
      int z= 0;
      while(x>0){
        cnt[z] += x%2;
        z++;
        x/=2;
      }
      mxz = max(mxz , z);
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
      int cur[mxz];
      assign1(cur , mxz , 0);
      int x = a[i];
      int z= 0;
      while(x>0){
        cur[z] = x%2;
        z++;
        x/=2;
      }
      int tmp = 0;
      for (int j = 0; j < mxz; j++)
      {
        if(cur[j]){
          int zeros = n-cnt[j];
          tmp += (1ll<<j) * zeros;
        }
        else tmp+= (1ll<<j) * cnt[j];
      }
      mx = max(mx , tmp);
      
    }
    cout<<mx;
    

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
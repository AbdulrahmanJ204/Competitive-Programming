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
    int n,m,k;
    cin>>n>>m>>k;
    m++;
    int a[n+1] , l[m] , r[m] , d[m],pre[m+1];
    int p[n+2];
    p[0]=p[n+1]=0;
    for (int i = 1; i <= n; i++)
    {
      cin>>a[i];
      p[i]=0;
    }
    
    pre[0]=0;
    for (int i = 1; i < m; i++)
    {
      cin>>l[i]>>r[i]>>d[i];
      pre[i] = 0; 
    }
    
    for (int i = 0; i < k; i++)
    {
      int x ,y;
      cin>>x>>y;
      pre[x]++;
      pre[y+1]--;
    }
    for (int i = 1; i < m; i++)
    {
      pre[i]+=pre[i-1];
      p[l[i]] += d[i] * pre[i];
      p[r[i]+1] -= d[i]*pre[i];
    }
    for (int i = 1; i < n+1; i++)
    p[i]+=p[i-1];
    for (int i = 0; i < n; i++)
    {
      cout<<a[i+1]+ p[i+1]<<" ";
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
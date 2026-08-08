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
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<setw(8)<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n,k;
    cin>>n>>k;
    double dp[k+1][n+1];
    double ans=0;
    assign2(dp,k+1,n+1 , 0);
    
    dp[0][0]=1.0;
    
    for (int i = 0; i < k ; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        if(j==n){
          
        dp[i+1][j]   += 0.5 * dp[i][j];
        dp[i+1][j-1] += 0.5 * dp[i][j];
        }
        else{

        dp[i+1][j+1] += 0.5 * dp[i][j];
        dp[i+1][j]   += 0.5 * dp[i][j];
          
        }

      }
      
    }
    


    // cout2(dp,k+1,n+1);

    for (int i = 0; i < n+1; i++)
    { 
      
      ans+=dp[k][i] * (double)i;
    }
    
    cout<<fixed<<setprecision(6)<<ans;


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
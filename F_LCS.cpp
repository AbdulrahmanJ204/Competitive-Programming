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
string a,b;
ll dp[3010][3010];

// ll fun(int i1 = 0 , int i2 = 0)
// {
//   if(i1==a.size()|| i2==b.size()){
//     return 0;
//   }
//   if(~dp[i1][i2]) return dp[i1][i2];
//   ll s1=0,s2=0,s3=0;
//   if(a[i1]==b[i2])
//     s1=1+fun(i1+1,i2+1);  
//   s2=fun(i1+1,i2);
//   s3=fun(i1, i2+1);
  
  
//   return dp[i1][i2]=max({s1,s2,s3});
// }
void solve()
{
    cin>>a>>b;
    int n=a.size(),m=b.size();
    assign2(dp,n+1,m+1,0);
    for (int i =1; i <=n; ++i) {
        for (int j = 1; j <=m; ++j) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else    
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // for (int i = n-1; i >= 0; --i) {
    //     for (int j = m-1; j >= 0; --j) {
    //         if (a[i] == b[j])
    //             dp[i][j] = dp[i + 1][j + 1] + 1;
    //         else    
    //         dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            
    //     }
    // }
    // cout<<dp[1][1];
    
    
    // cout<<"    ";
    // for (int i = 0; i < m; i++)
    // {
    //   cout<<b[i]<<' ';
    // }cendl;
    // int cnt=0;
    // for (int i = 0; i <= n; i++){
    //   if(i)
    //   cout<<a[i-1]<<' ';
    //   else cout<<"  ";
    // for (int j = 0; j <= m; j++){
    //   cout<<dp[i][j]<<' ';
    // }cendl;
    // }


    string path="";
    int i=n,j=m;
    while(i+j>0){
      // cout<<"I = "<<i<<"  J = "<<j<<"  dp[i][j] = "<<dp[i][j]<<endl;
      if(i>0 && dp[i][j] == dp[i-1][j]){
        i--;
      }
      else if(j>0 && dp[i][j]==dp[i][j-1]){
        j--;
      }
      else {
        i--,j--;
         if(a[i]==b[j])
         path+=a[i];
      }
    }
    
    
    reverse(all(path));
    // cout2(dp,n+1,m+1);
    
    cout<<path;
    // cout<<fun();

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
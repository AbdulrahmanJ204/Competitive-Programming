#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n; string s;
int dp[3500][3500];
ll mod=1e9+7;
ll fun(int i, int cnt){

if(i==n) return cnt==0;
if(cnt<0) return 0;
if(dp[i][cnt]!=-1) return dp[i][cnt];
ll sum=0;
if(s[i]=='(') sum= fun(i+1,cnt+1)%mod;
if(s[i]==')') sum=fun(i+1,cnt-1)%mod;
if(s[i]=='?') sum= (fun(i+1,cnt+1)%mod+fun(i+1,cnt-1)%mod)%mod;
return dp[i][cnt]=sum;

}
int main() {
  cin>>n>>s;
  for(int i=0; i<=n; i++){
    for(int j=0; j<=n ; j++)
        dp[i][j]=-1;
  }
  cout<<fun(0,0);
    return 0;
}

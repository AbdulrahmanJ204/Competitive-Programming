#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
const int N=101;
int dp[N][4];
int a[110];
int mx;
int solve(int i,int last)
{
    if(i>mx)
        return dp[i][last]=0;
    if(dp[i][last]!=-1)
        return dp[i][last];
    if(a[i]==0)
        return dp[i][last]=solve(i+1,a[i]);
    if(a[i]==3) {
        if (last == 1) {
            int c1 = solve(i + 1, 2) + 1;
            int c2 = solve(i + 1, 0);
            return dp[i][last] = max(c1,c2);
        } else if (last == 2)
        {
            int c1 = solve(i + 1, 1) + 1;
            int c2 = solve(i + 1, 0);
            return dp[i][last] = max(c1,c2);
        }
        else if(last==0)
        {
            int c1=solve(i+1,1)+1;
            int c2=solve(i+1,2)+1;
            int c3=solve(i+1,0);
            return dp[i][last]=max({c1, c2, c3});
        }
    }
    if(a[i]==last)
    {
        int c=solve(i+1,0);
        return dp[i][last]=c;
    }
    else
    {
        int c1=solve(i+1,a[i])+1;
        int c2=solve(i+1,0);
        return dp[i][last] = max(c1, c2);
    }

}

int main() {
    InTheNameOfAllah
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < 4; ++i) {
            dp[j][i]=-1;
        }

    }
    int n;
    cin>>n;
    mx=n;
    int cnt=0;
    a[0]=0;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        if(a[i]==0) cnt++;
    }
   solve(1,0);
    int ans=0;
    for (int i = 0; i < 4; ++i) {
        ans=max(dp[1][i],ans);
    }
    cout<<n-ans<<endl;
//    for (int k = 0; k < N; ++k) {
//        cout<<dp[k]<<' ';
//    }
    return 0;
}
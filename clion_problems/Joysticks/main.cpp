#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
const int N=300;
ll dp[N][N];
ll solve(int a1,int a2)
{   if(a1==1&&a2==1)
    return 0;
    if(a1<=0||a2<=0)
        return 0;
    if(dp[a1][a2]!=-1) return dp[a1][a2];
    ll c1=1+solve(a1-2,a2+1);
    ll c2=1+solve(a1+1,a2-2);
    return dp[a1][a2]=max(c1,c2);
}
int main() {
    InTheNameOfAllah
    int a1,a2;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j]=-1;
        }
    }
    cin>>a1>>a2;
    cout<<solve(a1,a2);
    return 0;
}
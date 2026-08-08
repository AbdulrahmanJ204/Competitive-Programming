#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int n1,n2,k1,k2;
int mod=1e8;
const int N=200,mN=20;
ll dp[N][N][mN][mN];
ll solve(int i1,int i2,int f,int h)
{
    if(f>k1||h>k2)
        return 0;
    if(n1==i1&&n2==i2)
        return 1;
    if(dp[i1][i2][f][h]!=-1)
        return dp[i1][i2][f][h];
    ll c1=0,c2=0;
    if(i1<n1)
    c1=solve(i1+1,i2,f+1,0 );
    if(i2<n2)
    c2=solve(i1,i2+1,0,h+1);
  //  cout<<c1<<' '<<c2<<endl;
    return dp[i1][i2][f][h]= (c1%mod+c2%mod)%mod;



}
int main() {
    InTheNameOfAllah
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < mN; ++k) {
                for (int l = 0; l < mN; ++l) {
                    dp[i][j][k][l]=-1;
                }
            }
        }
    }
    cin>>n1>>n2>>k1>>k2;
    cout<<solve(0,0,0,0)%mod;
    return 0;
}
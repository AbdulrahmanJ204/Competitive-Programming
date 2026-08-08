#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
const int N=1e5+100;
int n;
int a[N],b[N];
ll dp[N][3];
ll solve(int i,int last)
{
    if(i>n)
        return 0;
    if(dp[i][last]!=-1)
        return dp[i][last];
    ll c1=-1e9,c2=-1e9,c3;
    if(last!=1)
    c1=a[i]+solve(i+1,1);
    if(last!=2)
    c2=b[i]+solve(i+1,2);
    c3=solve(i+1,last);
    return dp[i][last]=max({c1,c2,c3});
}

int main() {
    InTheNameOfAllah
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp[i][j] = -1;
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> b[j];
    }
    cout << solve(0, 0);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
string s;
const int N=1e5+100;
ll dp[N];
ll mod=1e9+7;
ll solve(ll i)
{
    if(i>=s.size()-1)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    ll c1,c2=0;
    c1=solve(i%mod+1)%mod;
    if((s[i]=='u'&&s[i+1]=='u')||(s[i]=='n'&&s[i+1]=='n'))
    c2=(1+solve(i%mod+2)%mod)%mod;
     dp[i]=(c1%mod+c2%mod)%mod;

    return dp[i];
}
int main() {
    InTheNameOfAllah
    for (int i = 0; i < N; ++i) {
        dp[i]=-1;
    }
    cin>>s;
    bool exist=true;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='m'||s[i]=='w') {
            exist = false;
            break;
        }
    }

    if(!exist)
        cout<<0;
    else
    cout<<(solve(0)%mod+1)%mod<<endl;


    return 0;
}
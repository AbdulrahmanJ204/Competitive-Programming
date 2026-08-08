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
const int N=1e6+100;int n;
ll dp[N],dp2[N];
//ll solve(int i)
//{
//    if(i>=n-1) return 0;
//    if(s[i]=='o') {
//        dp[i]=-3;
//        return 0;
//    }
//    if(dp[i]!=-1) return dp[i];
//    ll c1=0,c2=0;
//    if(s[i]=='v'&&s[i+1]=='v')
//        c1=1+solve(i+2);
//    c2=solve(i+1);
//    dp[i]=c1+c2;
//    return dp[i];
//}
int main() {
    InTheNameOfAllah
    /*for (int i = 0; i < N; ++i) {
        dp[i]=-1;
    }*/
    cin>>s;
    n=s.size();
    vector<ll> v;
        int c=0;
        int f=1e9;
    for (int i = 0; i < n; ++i) {
        if(s[i]=='o')
        {
            int x=0;
            while (s[i]=='o') {
                x--;
                i++;
            }
            i--;
            v.push_back(x);
        }
       else {

            while (s[i] == 'v') {
                c++;
                i++;
            }
            c--;
            v.push_back(c);
            i--;
        }
    }
    for (int j = 0; j < v.size(); ++j) {
//        cout<<v[j]<<' ';
        if(v[j]>0)
        f=min(f,j);
    }

    ll ans=0;
//    cendl;
//    cout<<f<<endl;
    for (int i = f; i < v.size(); ++i) {
        if(v[i]<0) {
            ans += ((c - v[i - 1]) * v[i-1] * abs(v[i]));
//            cout << c << ' ' << v[i - 1] << ' ' << v[i]<<' ' << ans << endl;
        }
    }
    cout<<ans<<endl;
  /*  ll pre[n+1],suf[n+1];
    ll v=0;


    for (int i = 0; i < n; ++i) {
        if(s[i]=='v')
            dp[i]=v++;
        else {
            v=0;
            dp[i]=-3;
        }
        pre[i]=0;
        suf[i]=0;
        if(s[i]=='o') {
            pre[i] = -10;
            suf[i]=-10;
        }
    }
    ll mx=0;
    for (int i = 0; i < n; ++i) {
        pre[i]=dp[i];
    }
    for (int i = 0; i < n; ++i) {
        if(dp[i]<0) continue;

        pre[i]+=mx;
        mx=pre[i];
    }
    v=0;
    for (int i = n-1; i >=0;--i) {
        if(s[i]=='v')
            dp2[i]=v++;
        else {
            v=0;
            dp2[i]=-3;
        }
    }
    mx=0;
    for (int i = n-1; i >=0;--i) {
        mx=max(mx,dp2[i]);
        suf[i]+=mx;
        mx=max(mx,suf[i]);
    }

    //    for (int j = 0; j < n; ++j) {
//        solve(j);
//    }
//    for (int i = 0; i < n; ++i) {
//        cout<<dp[i]<<' ';
//    }cendl;
//    for (int i = 0; i < n; ++i) {
//        cout<<dp2[i]<<' ';
//    }cendl;
//    for (int i = 0; i < n; ++i) {
//        cout<<pre[i]<<' ';
//    }cendl;
//    for (int i = 0; i < n; ++i) {
//        cout<<suf[i]<<' ';
//    }cendl;
*/
    return 0;
}
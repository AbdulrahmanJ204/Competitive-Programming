#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
        int n;
        cin>>n;
        ll a[n+1];
        ll mn=1e18;
        map<ll,ll> m;
        a[0]=0;
        for (int i = 1; i <= n; ++i) {
            cin>>a[i];
            m[a[i]]++;
        }
        sort(a,a+n);
        ll ans=0;
        ll pre=0,suf=0;
        ll nu=n;
       for(auto x:m)
       {
           ans=max(ans,x.first*nu);
           nu-=x.second;

       }
        cout<<ans<<endl;

    }
    return 0;
}
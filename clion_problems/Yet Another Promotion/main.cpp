#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

int main() {
    InTheNameOfAllah
    test {
        ll a,b,n,m;
        cin>>a>>b>>n>>m;
        ll ans=0;
        if(n>m)
        {
            ll x=n/(m+1);
            if(m*a<= (m+1)*b)
                ans+=m*a*x;
            else ans+=(m+1)*b*x;
            n%=(m+1);
        }
        ans+=min(n*a,n*b);

        cout<<ans<<endl;
    }
    return 0;
}
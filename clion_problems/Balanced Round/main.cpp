#include <bits/stdc++.h>
using namespace std;
#define test  ll  t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);


int main() {
    InTheNameOfAllah
    test {
        ll n,k;
        cin>>n>>k;
        vector<ll>v;
        for (ll  i = 0; i < n; ++i) {
            ll x;
            cin>>x;
            v.push_back(x);

        }

        ll tans=0,ans=0;
        sort(v.begin(),v.end());
        int last=0;
        for (ll  i = 1; i < n; ++i) {
            if(v[i]>v[i-1]+k) {
                ans=max(ans,i-last);
                last=i;
            }

        }
        ans=max(ans,n-last);
        cout<<n-ans<<endl;
    }
    return 0;
}
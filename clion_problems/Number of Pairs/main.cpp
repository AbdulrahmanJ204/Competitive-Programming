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
        ll n,l,r;
        cin>>n>>l>>r;
        vector<ll> v;

        for (int i = 0; i < n; ++i) {
            ll x;
            cin>>x;

                v.push_back(x);

        }
        sort(v.begin(),v.end());
        ll ans=0;
        ll first=0,last=0;

        for (int i = 0; i < n-1; ++i) {
            ll x1=l-v[i];
            ll x2=r-v[i];
            first=lower_bound(v.begin()+i+1,v.end(),x1)-v.begin();
            last =upper_bound(v.begin()+i+1,v.end(),x2)-v.begin()-1;

         //   cout<<first<<' '<<last<<endl;

            if(last<first) continue;
            if(v[i]+v[first]>=l&&v[i]+v[last]<=r)
            ans+=abs(last-first)+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
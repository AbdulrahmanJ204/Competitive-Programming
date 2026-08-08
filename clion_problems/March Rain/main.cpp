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
    int n,k;
    cin>>n>>k;
    ll x[n];
        for (int i = 0; i < n; ++i) {
            cin>>x[i];
        }
        vector<pair<ll,ll>> v;
        for (int j = 1; j < n; ++j) {
            v.push_back(make_pair(x[j]-x[j-1],j-1));
        }
        sort(v.rbegin(),v.rend());
        ll ans=0;
        vector<ll> a;
        for (ll i = 0; i < k-1; ++i) {
            a.push_back(v[i].second);
        }
        sort(a.begin(),a.end());
        ll cnt=0;
        for (int i = 0; i < n; ) {
            ans=max(ans,x[i]-x[a[cnt]]);
        i+=a[cnt++]+1;
        }

        cout<<ans<<endl;
    }
    return 0;
}
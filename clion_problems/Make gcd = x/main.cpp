#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int n,m;
        cin>>n>>m;
        ll a[n+1];
        ll gc=0;
    for (int i = 1; i <= n; ++i)
        cin>>a[i];
    while(m--)
    {   gc=0;
        int l,r,x;
        int ans=0;
        cin>>l>>r>>x;
        vector<ll> v;
        for (int j = l; j <=r ; ++j)
            v.push_back(a[j]);
        sort(v.begin(),v.end());
        for (int i = 0; i < v.size(); ++i) {
        gc=__gcd(gc,v[i]);
        }
        if(gc==x) {
            cout << 0 << endl;
            continue;
        }
        if(gc%x==0) {
            cout << 1 << endl;
            continue;
        }
        for (int i = 0; i < v.size(); ++i) {
            if(v[i]%x!=0)
                ans++;
        }
        cout<<ans<<endl;
        v.clear();
    }
    return 0;
}


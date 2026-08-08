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
    ll n;
    ll d;
    cin >> n >> d;
    vector<ll> v;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    ll ans = 0;
    for (ll i = 0; i < n - 2; ++i) {
        ll lastindex = upper_bound(v.begin(), v.end(), v[i] + d) - v.begin() - 1;
        if (lastindex - i < 2)
            continue;
        lastindex = lastindex - i - 1;
        ll p = lastindex * (lastindex + 1) / 2;
        ans += p;
    }
    cout << ans << endl;
    return 0;
}

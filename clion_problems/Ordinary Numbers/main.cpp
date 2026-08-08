#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin >> n;

        ll ans = 0;
        for (int i = 1; i < 10; ++i) {
            ll x = i;
            while(x <= n)
            {   ans++;
                x=x*10+i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

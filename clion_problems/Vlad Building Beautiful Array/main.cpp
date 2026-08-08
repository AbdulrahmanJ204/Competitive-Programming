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
        cin >> n;
        ll a[n];
        ll mneven = 1e10, mnodd = 1e10;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] % 2 == 0)
                mneven = min(a[i], mneven);
            else
                mnodd = min(mnodd, a[i]);
        }
        if (mnodd == 1e10 || mneven == 1e10)
            cyes;
        else if (mnodd > mneven)
            cno;
        else if (mneven - mnodd > 0)
            cyes;
        else
            cno;
    }
    return 0;
}
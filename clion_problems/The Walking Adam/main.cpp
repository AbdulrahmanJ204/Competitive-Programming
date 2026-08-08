#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll a[n];
    ll x,y;
    cin>>x>>y;
    ll a1=0,b=0,c=0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        if(a[i]<=x)
            a1++;
        else if(a[i]<=y)
            b++;
        else
            c++;
    }
    cout<<a1<<' '<<b<<' '<<c;
    return 0;
}

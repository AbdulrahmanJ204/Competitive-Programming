#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double n; ll k;
    cin>>n>>k;
    ll ans,a=ceil(n/2);
    if(k<=a)
        ans=k*2-1;
    else
        ans=(k-a)*2;
    cout << ans<<' ';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n;
    cin>>n;
    ll a[n];
    ll sum=0;
    ll min_odd=1000000000;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        if(a[i]%2==0)
        sum+=a[i];
        else
        {
            sum+=a[i];
            min_odd=min(min_odd,a[i]);
        }

    }if(sum%2==0)
        cout<<sum<<'\n';
    else
        cout<<sum-min_odd<<'\n';
    return 0;
}

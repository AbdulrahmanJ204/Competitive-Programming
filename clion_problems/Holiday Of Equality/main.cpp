#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
   int n;
   cin>>n;
   vector<ll> v;
    for (int i = 0; i < n; ++i) {
    int x;
    cin>>x;
    v.push_back(x);

    }
    ll ans=0;
    sort(v.begin(),v.end());
    for (int j = 0; j < n - 1; ++j) {
        if(v[j]<v[n-1])
            ans+=(v[n-1]-v[j]);
    }
    cout<<ans<<endl;
    return 0;
}

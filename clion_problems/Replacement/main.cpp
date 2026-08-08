#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<ll>v ;

    for (int i = 0; i < n; ++i) {
        ll x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    if(v[n-1]!=1)
        v[n-1]=1;
    else
        v[n-1]=2;

    sort(v.begin(),v.end());


    for (int i = 0; i < n; ++i) {
        cout<<v[i]<<' ';
    }

    return 0;
}

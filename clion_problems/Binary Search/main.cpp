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
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
            cin>>a[i];
    }
    for (int j = 0; j < k; ++j) {
        ll x;
        cin>>x;
        lower_bound(a.begin(),a.end(),x);
        if(*lower_bound(a.begin(),a.end(),x)==x)
            cyes;
        else
            cno;
    }
    return 0;
}
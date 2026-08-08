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
    int n ,k;
    cin>>n>>k;
    vector<ll> v;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin>>x;
        v.push_back(x);
    }
    while(k--)
    {
        ll x;
        cin>>x;
        int ptr=lower_bound(v.begin(),v.end(),x)-v.begin();
        cout<<ptr+1<<endl;


    }
    return 0;
}
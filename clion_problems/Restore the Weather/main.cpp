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
    ll n,k;
    cin>>n>>k;
    vector<ll> d,a(n),b(n);
    bool taken[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            taken[i]=0;
            d.push_back(a[i]);
        }
        for (int i = 0; i < n; ++i) {
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        map<ll,queue<ll>> m;
        for (int i = 0; i < n; ++i) {
            m[a[i]].push(b[i]);
        }
        for (int i = 0; i < n; ++i) {
            cout<<m[d[i]].front()<<' ';
            m[d[i]].pop();
        }
        cendl;










    }
    return 0;
}